﻿#region License
/* 
 * Copyright (C) 1999-2016 John Källén.
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

using Reko.Core;
using Reko.Core.CLanguage;
using Reko.Core.Code;
using Reko.Core.Expressions;
using Reko.Core.Serialization;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace Reko.Analysis
{
    /// <summary>
    /// Builds ProcedureSignatures from user-supplied signatures.
    /// </summary>
    public class UserSignatureBuilder
    {
        private Program program;

        public UserSignatureBuilder(Program program)
        {
            this.program = program;
        }

        /// <summary>
        /// For each procedure, either use a user-supplied signature, 
        /// or the predefined one.
        /// </summary>
        public void BuildSignatures()
        {
            foreach (var de in program.Procedures)
            {
                var proc = de.Value;
                Procedure_v1 userProc;
                if (program.User.Procedures.TryGetValue(de.Key, out userProc))
                {
                    var sProc = DeserializeSignature(userProc, proc);
                    if (sProc != null)
                    {
                        var ser = program.CreateProcedureSerializer();
                        var sig = ser.Deserialize(sProc.Signature, proc.Frame);
                        if (sig != null)
                        {
                            proc.Name = sProc.Name;
                            ApplySignatureToProcedure(de.Key, sig, proc);
                            continue;
                        }
                    }
                }

                if (proc.Signature.ParametersValid)
                {
                    ApplySignatureToProcedure(de.Key, proc.Signature, proc);
                }
            }
        }

        public ProcedureBase_v1 DeserializeSignature(Procedure_v1 userProc, Procedure proc)
        {
            if (!string.IsNullOrEmpty(userProc.CSignature))
            {
                return ParseFunctionDeclaration(userProc.CSignature, proc.Frame);
            }
            return null;
        }

        public void ApplySignatureToProcedure(Address addr, ProcedureSignature sig, Procedure proc)
        {
            proc.Signature = sig;

            int i = 0;
            var stmts = proc.EntryBlock.Succ[0].Statements;
            var linAddr = addr.ToLinear();
            var m = new ExpressionEmitter();
            foreach (var param in sig.Parameters)
            {
                var starg = param.Storage as StackArgumentStorage;
                if (starg != null)
                {
                    proc.Frame.EnsureStackArgument(
                        starg.StackOffset + sig.ReturnAddressOnStack,
                        param.DataType,
                        param.Name);
                    var fp = proc.Frame.FramePointer;
                    stmts.Insert(i, linAddr, new Store(
                        m.Load(param.DataType, m.IAdd(fp, sig.ReturnAddressOnStack + starg.StackOffset)),
                        param));
                }
                else
                {
                    var paramId = proc.Frame.EnsureIdentifier(param.Storage);
                    paramId.DataType = param.DataType;

                    // Need to take an extra step with parameters being passed
                    // in a register. It's perfectly possible for a user to 
                    // create a variable which they want to call 'r2' but which
                    // the calling convention of the machine wants to call 'r1'.
                    // To avoid this, we create a temporary identifier for 
                    // the formal parameter, and inject an copy statement in the
                    // entry block that moves the parameter value into the 
                    // register.
                    stmts.Insert(i, linAddr, NewMethod(param, paramId));
                }
                ++i;
            }
        }

        private static Assignment NewMethod(Identifier param, Identifier dst)
        {
            return new Assignment(dst, param);
        }

        public ProcedureBase_v1 ParseFunctionDeclaration(string fnDecl, Frame frame)
        {
            try {
                var lexer = new CLexer(new StringReader(fnDecl + ";"));
                var symbols = program.CreateSymbolTable();
                var oldProcs = symbols.Procedures.Count;
                var cstate = new ParserState(symbols.NamedTypes.Keys);
                var cParser = new CParser(cstate, lexer);
                var decl = cParser.Parse_ExternalDecl();
                if (decl == null)
                    return null;

                //$HACK: Relying on a side effect here to
                // get both the procedure name and the signature. Ew.
                symbols.AddDeclaration(decl);
                if (symbols.Procedures.Count == oldProcs)
                    return null;
                return symbols.Procedures.Last();
            }
            catch (Exception ex)
            {
                //$TODO: if user has supplied a signature that can't parse,
                // we must notify them in the diagnostics window with a 
                // WARNING.
                Debug.Print("{0}\r\n{1}", ex.Message, ex.StackTrace);
                return null;
            }
        }

        //$BUG failed on "int var[6]"
        public GlobalDataItem_v2 ParseGlobalDeclaration(string txtGlobal)
        {
            try
            {
                var tokens = txtGlobal.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                if (tokens.Length <= 1)
                    return null;
                var name = tokens[tokens.Length - 1];
                if (!IsValidCIdentifier(name))
                    return null;
                var lexer = new CLexer(new StringReader("typedef " + txtGlobal + ";"));
                var symbols = program.CreateSymbolTable();
                var oldNamedTypes = symbols.NamedTypes.Count;
                var cstate = new ParserState(symbols.NamedTypes.Keys);
                var cParser = new CParser(cstate, lexer);
                var decl = cParser.Parse_ExternalDecl();
                if (decl == null)
                    return null;

                //$HACK: Relying on a side effect here to
                // get both the global type. Ew.
                symbols.AddDeclaration(decl);
                if (symbols.NamedTypes.Count == oldNamedTypes)
                    return null;
                var type = symbols.NamedTypes[name];
                var global = new GlobalDataItem_v2()
                {
                    Name = name,
                    DataType = type,
                };
                return global;
            }
            catch (Exception ex)
            {
                //$TODO: if user has supplied a global variable that can't parse,
                // we must notify them in the diagnostics window with a 
                // WARNING.
                Debug.Print("{0}\r\n{1}", ex.Message, ex.StackTrace);
                return null;
            }
        }

        //$REFACTOR: this is language and platform dependent.
        public static bool IsValidCIdentifier(string id)
        {
            return Regex.IsMatch(id, "^[_a-zA-Z][_a-zA-Z0-9]*$");
        }
    }
}
