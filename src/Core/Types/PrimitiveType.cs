#region License
/* 
 * Copyright (C) 1999-2018 John K�ll�n.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Text;

namespace Reko.Core.Types
{
    /// <summary>
    /// A Domain specifies the possible interpretation of a chunk of bytes.
    /// </summary>
    /// <remarks>
    /// A 32-bit load from memory could mean that the variable could be 
    /// treated as an signed int, unsigned int, floating point number, a 
    /// pointer to something. As the decompiler records how the value is used,
    /// some of these alternatives will be discarded. For instance, if the
    /// 32-bit word is used in a memory access, it is certain that it is a
    /// pointer to (something), and it can't be a float.
    /// </remarks>
	[Flags]
	public enum Domain
	{
		None = 0,
		Boolean = 1,                // f
		Character = 2,              // c
		SignedInt = 4,              // i 
		UnsignedInt = 8,            // u
        Integer = SignedInt|UnsignedInt,
        Bcd = 16,                   // b - Binary coded decimal; a decimal digit stored in each nybble of a byte.
        Real = 32,                  // r
		Pointer = 64,               // p
        Offset = 128,               // n - "near pointer" (x86)
		Selector = 256,             // S
        SegPointer = 512,           // P - Segmented pointer (x86-style)

        Any = Boolean|Character|SignedInt|UnsignedInt|Bcd|Real|Pointer|Offset|Selector|SegPointer
	}

	/// <summary>
	/// Represents a primitive machine data type, with no internal structure.
	/// </summary>
	/// <remarks>
	/// Examples of primitives are integers of different signedness and sizes,
    /// as well as real types and booleans. Pointers to types are not 
    /// considered primitives, as they are type constructors. Primitives are
    /// implemented as immutable flyweights since there are so many of them.
	/// </remarks>
	public class PrimitiveType : DataType
	{
		private int bitSize;
        private int byteSize;
		
		private PrimitiveType(Domain dom, int bitSize, string name)
		{
			this.Domain = dom;
			this.bitSize = bitSize;
            this.byteSize = (bitSize + (BitsPerByte-1)) / BitsPerByte;
			this.Name = name;
		}

        public override void Accept(IDataTypeVisitor v)
        {
            v.VisitPrimitive(this);
        }

        public override T Accept<T>(IDataTypeVisitor<T> v)
        {
            return v.VisitPrimitive(this);
        }

        public override DataType Clone(IDictionary<DataType, DataType> clonedTypes)
		{
			return this;
		}

		public int Compare(PrimitiveType a)
		{
			PrimitiveType p = (PrimitiveType) a;
			int d = (int) Domain - (int) p.Domain;
			if (d != 0)
				return d;
			return bitSize - p.bitSize;
		}

		public static PrimitiveType Create(Domain dom, int byteSize)
		{
			return Create(dom, byteSize, null);
		}

        public static PrimitiveType CreateBitSlice(int bitlength)
        {
            var p = new PrimitiveType(Domain.Integer, bitlength, null);
            PrimitiveType shared;
            if (!cache.TryGetValue(p, out shared))
            {
                shared = p;
                shared.Name = GenerateName(Domain.Integer, p.BitSize);
                cache.Add(shared, shared);
                lookupByName.Add(shared.Name, shared);
            }
            return shared;
        }

        private static PrimitiveType Create(Domain dom, int byteSize, string name)
		{
            if (mpBitWidthToAllowableDomain.TryGetValue(byteSize, out var domainMask))
            {
                dom &= domainMask;
            }
			PrimitiveType p = new PrimitiveType(dom, byteSize*8, null);
            if (!cache.TryGetValue(p, out var shared))
            {
                shared = p;
                shared.Name = name != null ? name : GenerateName(dom, p.BitSize);
                cache.Add(shared, shared);
                lookupByName.Add(shared.Name, shared);
            }
			return shared;
		}

        //$TODO: Make PrimitiveType.CreateWord accept a bit count rather than a byte count
        public static PrimitiveType CreateWord(int byteSize)
        {
            string name;
            if (byteSize == 1)
            {
                name = "byte";
            }
            else
            { 
                name = $"word{byteSize * 8}";
            }
            if (!mpBitWidthToAllowableDomain.TryGetValue(byteSize, out var dom))
            {
                dom = Domain.UnsignedInt | Domain.Integer | Domain.Pointer;
            }
			return Create(dom, (short) byteSize, name);
		}

        //$TODO: Remove when PrimitiveType.CreateWord will accept a bit count.
        public static PrimitiveType CreateWordFromBits(uint bitSize)
        {
            if (bitSize == 0)
                throw new ArgumentOutOfRangeException(nameof(bitSize), $"Value = {bitSize}");
            if (bitSize == 1)
                return Bool;
            if (bitSize <= 8)
                return Byte;
            if (bitSize <= 16)
                return Word16;
            if (bitSize <= 32)
                return Word32;
            if (bitSize <= 64)
                return Word64;
            if (bitSize <= 128)
                return Word128;
            if (bitSize <= 256)
                return Word256;
            throw new ArgumentOutOfRangeException(nameof(bitSize), $"Value = {bitSize}");
        }

        public Domain Domain { get; private set; }

		public override bool Equals(object obj)
		{
			PrimitiveType p = obj as PrimitiveType;
			if (p == null)
				return false;
			return p.Domain == Domain && p.bitSize == bitSize;
		}
	
        /// <summary>
        /// Generates a string based on domain and bitsize
        /// </summary>
        /// <remarks>
        /// Note that these are not C data types, but Reko internal types.
        /// The Reko output formatters are responsible for translation to
        /// C (or whatever output language has been chosen by the user).
        /// </remarks>
        /// <param name="dom"></param>
        /// <param name="bitSize"></param>
        /// <returns></returns>
		public static string GenerateName(Domain dom, int bitSize)
		{
			StringBuilder sb;
			switch (dom)
			{
			case Domain.Boolean:
				return "bool";
			case Domain.Character:
                if (bitSize == 8)
				    return "char";
                if (bitSize == 16)
                    return "wchar_t";
                return "char" + bitSize;
			case Domain.SignedInt:
				return "int" + bitSize;
			case Domain.UnsignedInt:
				return "uint" + bitSize;
			case Domain.Pointer:
				return "ptr" + bitSize;
            case Domain.Offset:
                return "mp" + bitSize;
            case Domain.SegPointer:
                return "segptr" + bitSize;
			case Domain.Real:
				return "real" + bitSize;
			case Domain.Selector:
				return "selector";
			default:
				sb = new StringBuilder();
				if ((dom & Domain.Boolean) != 0)
					sb.Append('b');
				if ((dom & Domain.Character) != 0)
					sb.Append('c');
				if ((dom & Domain.UnsignedInt) != 0)
					sb.Append('u');
                if ((dom & Domain.SignedInt) != 0)
                    sb.Append('i');
                if ((dom & Domain.SegPointer) != 0)
                    sb.Append('s');
                if ((dom & Domain.Pointer) != 0)
                    sb.Append('p');
                if ((dom & Domain.Offset) != 0)
                    sb.Append('o');
                if ((dom & Domain.Selector) != 0)
					sb.Append('s');
				if ((dom & Domain.Real) != 0)
					sb.Append('r');
				sb.Append(bitSize);
				return sb.ToString();
			}
		}

        public static bool TryParse(string primitiveTypeName, out PrimitiveType type)
        {
            return lookupByName.TryGetValue(primitiveTypeName, out type);
        }

		public override int GetHashCode()
		{
			return bitSize * 256 ^ Domain.GetHashCode();
		}

        /// <summary>
        /// True if the type can only be some kind of integral numeric type
        /// </summary>
		public bool IsIntegral
		{
			get { return (Domain & Domain.Integer) != 0 && (Domain & ~Domain.Integer) == 0; }
		}

        /// <summary>
        /// Creates a new primitive type, whose domain is the original domain ANDed 
        /// with the supplied domain mask. If the resulting domain is empty, use the 
        /// supplied domain.
        /// </summary>
        /// <param name="dom"></param>
        /// <returns></returns>
		public PrimitiveType MaskDomain(Domain domainMask)
		{
            var dom = this.Domain & domainMask;
            if (dom == 0)
                dom = domainMask;
            return Create(dom, Size);
		}

		public override string Prefix
		{
			get
			{
				switch (Domain)
				{
				case Domain.None:
					return "v";
				case Domain.Boolean:
					return "f";
				case Domain.Real:
					return "r";
				case Domain.Pointer:
                case Domain.SegPointer:
					return "ptr";
				case Domain.Selector:
					return "pseg";
				default:
					switch (byteSize)
					{
					case 1: return "b";
					case 2: return "w";
					case 4: return "dw";
                    case 8: return "qw";
                    case 16: return "ow";
                    case 32: return "hw";
					default: throw new ArgumentOutOfRangeException();
					}
				}
			}
		}

        public override int BitSize
        {
            get { return this.bitSize; }
        }

        /// <summary>
        /// Size of this primitive type in bytes.
        /// </summary>
        public override int Size
		{
			get { return byteSize; }
			set { throw new InvalidOperationException("Size of a primitive type cannot be changed."); }
		}

		private static Dictionary<PrimitiveType,PrimitiveType> cache;
        private static Dictionary<string, PrimitiveType> lookupByName;
        private static Dictionary<int, Domain> mpBitWidthToAllowableDomain;

        static PrimitiveType()
        {
            cache = new Dictionary<PrimitiveType, PrimitiveType>();
            lookupByName = new Dictionary<string, PrimitiveType>();
            mpBitWidthToAllowableDomain = new Dictionary<int, Domain>
            {
                { 0, Domain.Any },
                { 1, Domain.Boolean|Domain.Character|Domain.Integer },
                { 2, Domain.Character | Domain.Integer | Domain.Pointer | Domain.Offset | Domain.Selector | Domain.Real },
                { 4, Domain.Integer | Domain.Pointer | Domain.Real | Domain.SegPointer },
                { 8, Domain.Integer | Domain.Pointer | Domain.Real },
                { 10, Domain.Integer | Domain.Real | Domain.Bcd },
                { 12, Domain.Integer | Domain.Real },
                { 16, Domain.Integer | Domain.Real },
                { 32, Domain.Integer | Domain.Real },
            };

            Byte = CreateWord(1);
            Bool = Create(Domain.Boolean, 1);
            Char = Create(Domain.Character, 1);
            SByte = Create(Domain.SignedInt, 1);
            UInt8 = Create(Domain.UnsignedInt, 1);

            Word16 = CreateWord(2);
            Int16 = Create(Domain.SignedInt, 2);
            UInt16 = Create(Domain.UnsignedInt, 2);
            Ptr16 = Create(Domain.Pointer, 2);
            SegmentSelector = Create(Domain.Selector, 2);
            WChar = Create(Domain.Character, 2);
            Offset16 = Create(Domain.Offset, 2);

            Word32 = CreateWord(4);
            Int32 = Create(Domain.SignedInt, 4);
            UInt32 = Create(Domain.UnsignedInt, 4);
            Ptr32 = Create(Domain.Pointer, 4);
            SegPtr32 = Create(Domain.SegPointer, 4);
            Real32 = Create(Domain.Real, 4);

            Word64 = CreateWord(8);
            Int64 = Create(Domain.SignedInt, 8);
            UInt64 = Create(Domain.UnsignedInt, 8);
            Ptr64 = Create(Domain.Pointer, 8);
            Real64 = Create(Domain.Real, 8);

            Word80 = CreateWord(10);
            Real80 = Create(Domain.Real, 10);
            Bcd80 = Create(Domain.Bcd, 10);

            Real96 = Create(Domain.Real, 12);

            Word128 = CreateWord(16);
            Int128 = Create(Domain.SignedInt, 16);
            UInt128 = Create(Domain.UnsignedInt, 16);
            Real128 = Create(Domain.Real, 16);

            Word256 = CreateWord(32);
        }

		public static PrimitiveType Bool { get; private set; }

		public static PrimitiveType Byte { get; private set; }
        // 8-bit character
        public static PrimitiveType Char { get; private set; }
		public static PrimitiveType SByte { get; private set; }
		public static PrimitiveType UInt8 { get; private set; }

		public static PrimitiveType Word16 { get; private set; }
		public static PrimitiveType Int16 { get; private set; }
		public static PrimitiveType UInt16 { get; private set; }
        public static PrimitiveType Ptr16 { get; private set; }
        public static PrimitiveType Offset16 { get; private set; }

		public static PrimitiveType SegmentSelector  {get; private set; }

		public static PrimitiveType Word32 { get; private set; }
		public static PrimitiveType Int32 { get; private set; }
		public static PrimitiveType UInt32 { get; private set; }
		public static PrimitiveType Ptr32 { get; private set; }
		public static PrimitiveType Real32 { get; private set; }
        public static PrimitiveType SegPtr32 { get; private set; }

		public static PrimitiveType Word64 { get; private set; }
		public static PrimitiveType Int64 { get; private set; }
		public static PrimitiveType UInt64 { get; private set; }
		public static PrimitiveType Ptr64 { get; private set; }
        public static PrimitiveType Real64 { get; private set; }

        public static PrimitiveType Word80 { get; private set; }
		public static PrimitiveType Real80 { get; private set; }
        public static PrimitiveType Bcd80 { get; private set; }

        public static PrimitiveType Real96 { get; private set; }

        public static PrimitiveType Word128 { get; private set; }
        public static PrimitiveType Int128 { get; private set; }
        public static PrimitiveType UInt128 { get; private set; }
        public static PrimitiveType Real128 { get; private set; }

        public static PrimitiveType Word256 { get; private set; }

        public static PrimitiveType WChar { get; private set; }
    }
}