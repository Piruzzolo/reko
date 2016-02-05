#region License
/* 
 * Copyright (C) 1999-2016 John K�ll�n.
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

using Reko.Analysis;
using Reko.Core;
using Reko.Core.Code;
using Reko.Core.Services;
using Reko.Core.Types;
using System;
using System.Diagnostics;
using System.IO;

namespace Reko.Typing
{
	/// <summary>
	/// Gathers type information, infers structure, union, and array types,
	/// then rewrites the program as appropriate to incorporate the inferred types.
	/// Much of the type inference code in this namespace was inspired by the master's thesis
	/// "Entwicklung eines Typanalysesystem f�r einen Decompiler", 2004, by Raimar Falke.
	/// </summary>
	public class TypeAnalyzer
	{
        private DecompilerEventListener eventListener;

		private TypeFactory factory;
		private TypeStore store;
		private ExpressionNormalizer aen;
		private EquivalenceClassBuilder eqb;
#if OLD
        private TraitCollector trco;
		private DataTypeBuilder dtb;
#else
        private TypeCollector tyco;
#endif
        //private DerivedPointerAnalysis dpa;
        private TypeVariableReplacer tvr;
		private TypeTransformer trans;
		private ComplexTypeNamer ctn;
		private TypedExpressionRewriter ter;

		public TypeAnalyzer(DecompilerEventListener eventListener)
		{
			this.eventListener = eventListener;
		}

		/// <summary>
		/// Performs type analysis and rewrites program based on the inferred information.
		/// </summary>
		/// <remarks>
		/// For instance, all MemoryAccesses will be converted to structure field
		/// accesses or array accesses as appropriate.
		/// </remarks>
		/// <param name="program"></param>
		public void RewriteProgram(Program program)
		{
            factory = program.TypeFactory;
            store = program.TypeStore;

            aen = new ExpressionNormalizer(program.Platform.PointerType);
            eqb = new EquivalenceClassBuilder(factory, store);
#if OLD
            dtb = new DataTypeBuilder(factory, store, program.Platform);
            trco = new TraitCollector(factory, store, dtb, program);
#else
            tyco = new TypeCollector(program.TypeFactory, program.TypeStore, program);
#endif
            //dpa = new DerivedPointerAnalysis(factory, store, program.Architecture);
            tvr = new TypeVariableReplacer(store);
            trans = new TypeTransformer(factory, store,program, eventListener);
            ctn = new ComplexTypeNamer();
            ter = new TypedExpressionRewriter(program);

            // RestrictProcedures(program, 0, 1, true); // Re-enable this for debugging
            eventListener.ShowStatus("Gathering primitive datatypes from instructions.");
			aen.Transform(program);
			eqb.Build(program);
#if OLD
            eventListener.ShowStatus("Collecting datatype usage traits.");
			trco.CollectProgramTraits(program);
            eventListener.ShowStatus("Building equivalence classes.");
			dtb.BuildEquivalenceClassDataTypes();
#else
            eventListener.ShowStatus("Collecting data types");
            tyco.CollectTypes();
            store.BuildEquivalenceClassDataTypes(factory);
#endif
            //dpa.FollowConstantPointers(prog);
            tvr.ReplaceTypeVariables();

            eventListener.ShowStatus("Transforming datatypes.");
			var ppr = new PtrPrimitiveReplacer(factory, store, program);
			ppr.ReplaceAll();

			trans.Transform();
			ctn.RenameAllTypes(store);
			store.Dump();
            eventListener.ShowStatus("Rewriting expressions.");
			ter.RewriteProgram(program);
		}

        /// <summary>
        /// $DEBUG: for debugging only, only performs type analysis on the 
        /// <param name="count"/> procedures starting at
        /// procedure start.
        /// </summary>
        [Conditional("DEBUG")]
        private void RestrictProcedures(Program program, int start, int count, bool dumpProcedures)
        {
            count = Math.Min(count, program.Procedures.Values.Count);
            Procedure[] procs = new Procedure[count];
            for (int i = 0; i < count; ++i)
            {
                procs[i] = program.Procedures.Values[i + start];
            }
            program.Procedures.Clear();
            for (uint i = 0; i < procs.Length; ++i)
            {
                program.Procedures[Address.Ptr32(i)] = procs[i];
                if (dumpProcedures)
                {
                    procs[i].Dump(true);
                }
                else
                {
                    Debug.WriteLine(procs[i].Name);
                }
            }
        }

		public void WriteTypes(TextWriter output)
		{
		}
	}
}
