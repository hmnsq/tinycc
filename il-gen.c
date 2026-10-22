/*
 *  CIL code generator for TCC
 * 
 *  Copyright (c) 2002 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#त्रुटि this code has bit-rotted since 2003

/* number of available registers */
#घोषणा NB_REGS             3

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#घोषणा RC_ST      0x0001  /* any stack entry */
#घोषणा RC_ST0     0x0002  /* top of stack */
#घोषणा RC_ST1     0x0004  /* top - 1 */

#घोषणा RC_INT     RC_ST
#घोषणा RC_FLOAT   RC_ST
#घोषणा RC_IRET    RC_ST0 /* function return: integer register */
#घोषणा RC_LRET    RC_ST0 /* function return: second integer register */
#घोषणा RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
क्रमागत {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

स्थिर पूर्णांक reg_classes[NB_REGS] = {
    /* ST0 */ RC_ST | RC_ST0,
    /* ST1 */ RC_ST | RC_ST1,
    /* ST2 */ RC_ST,
};

/* return registers for function */
#घोषणा REG_IRET REG_ST0 /* single word int return register */
#घोषणा REG_LRET REG_ST0 /* second word return register (for long long) */
#घोषणा REG_FRET REG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
/* #define INVERT_FUNC_PARAMS */

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#घोषणा PTR_आकार 4

/* long double size and alignment, in bytes */
#घोषणा LDOUBLE_आकार  8
#घोषणा LDOUBLE_ALIGN 8

/* function call context */
प्रकार काष्ठा GFuncContext {
    पूर्णांक func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#घोषणा IL_OP_PREFIX 0xFE

क्रमागत ILOPCodes {
#घोषणा OP(name, str, n) IL_OP_ ## name = n,
#समावेश "il-opcodes.h"
#अघोषित OP
};

अक्षर *il_opcodes_str[] = {
#घोषणा OP(name, str, n) [n] = str,
#समावेश "il-opcodes.h"
#अघोषित OP
};

/******************************************************/

/* arguments variable numbers start from there */
#घोषणा ARG_BASE 0x70000000

अटल खाता *il_outfile;

अटल व्योम out_byte(पूर्णांक c)
{
    *(अक्षर *)ind++ = c;
}

अटल व्योम out_le32(पूर्णांक c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

अटल व्योम init_outfile(व्योम)
{
    अगर (!il_outfile) {
        il_outfile = मानक_निकास;
        ख_लिखो(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

अटल व्योम out_op1(पूर्णांक op)
{
    अगर (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
अटल व्योम out_op(पूर्णांक op)
{
    out_op1(op);
    ख_लिखो(il_outfile, " %s\n", il_opcodes_str[op]);
}

अटल व्योम out_opb(पूर्णांक op, पूर्णांक c)
{
    out_op1(op);
    out_byte(c);
    ख_लिखो(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

अटल व्योम out_opi(पूर्णांक op, पूर्णांक c)
{
    out_op1(op);
    out_le32(c);
    ख_लिखो(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
अटल व्योम il_type_to_str(अक्षर *buf, पूर्णांक buf_आकार, 
                           पूर्णांक t, स्थिर अक्षर *varstr)
{
    पूर्णांक bt;
    Sym *s, *sa;
    अक्षर buf1[256];
    स्थिर अक्षर *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    अगर (t & VT_UNSIGNED)
        pstrcat(buf, buf_आकार, "unsigned ");
    चयन(bt) {
    हाल VT_VOID:
        tstr = "void";
        जाओ add_tstr;
    हाल VT_BOOL:
        tstr = "bool";
        जाओ add_tstr;
    हाल VT_BYTE:
        tstr = "int8";
        जाओ add_tstr;
    हाल VT_SHORT:
        tstr = "int16";
        जाओ add_tstr;
    हाल VT_ENUM:
    हाल VT_INT:
    हाल VT_LONG:
        tstr = "int32";
        जाओ add_tstr;
    हाल VT_LLONG:
        tstr = "int64";
        जाओ add_tstr;
    हाल VT_FLOAT:
        tstr = "float32";
        जाओ add_tstr;
    हाल VT_DOUBLE:
    हाल VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_आकार, tstr);
        अवरोध;
    हाल VT_STRUCT:
        tcc_error("structures not handled yet");
        अवरोध;
    हाल VT_FUNC:
        s = sym_find((अचिन्हित)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_आकार, s->t, varstr);
        pstrcat(buf, buf_आकार, "(");
        sa = s->अग्र;
        जबतक (sa != शून्य) {
            il_type_to_str(buf1, माप(buf1), sa->t, शून्य);
            pstrcat(buf, buf_आकार, buf1);
            sa = sa->अग्र;
            अगर (sa)
                pstrcat(buf, buf_आकार, ", ");
        }
        pstrcat(buf, buf_आकार, ")");
        जाओ no_var;
    हाल VT_PTR:
        s = sym_find((अचिन्हित)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, माप(buf1), "*");
        अगर (varstr)
            pstrcat(buf1, माप(buf1), varstr);
        il_type_to_str(buf, buf_आकार, s->t, buf1);
        जाओ no_var;
    }
    अगर (varstr) {
        pstrcat(buf, buf_आकार, " ");
        pstrcat(buf, buf_आकार, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
व्योम greloc_patch1(Reloc *p, पूर्णांक val)
{
}

/* output a symbol and patch all calls to it */
व्योम gsym_addr(t, a)
{
}

/* output jump and return symbol */
अटल पूर्णांक out_opj(पूर्णांक op, पूर्णांक c)
{
    out_op1(op);
    out_le32(0);
    अगर (c == 0) {
        c = ind - (पूर्णांक)cur_text_section->तथ्य;
    }
    ख_लिखो(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    वापस c;
}

व्योम gsym(पूर्णांक t)
{
    ख_लिखो(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
व्योम load(पूर्णांक r, SValue *sv)
{
    पूर्णांक v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    अगर (sv->r & VT_LVAL) {
        अगर (v == VT_LOCAL) {
            अगर (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                अगर (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } अन्यथा अगर (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } अन्यथा {
                    out_opi(IL_OP_LDARG, fc);
                }
            } अन्यथा {
                अगर (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } अन्यथा अगर (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } अन्यथा {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } अन्यथा अगर (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } अन्यथा {
            अगर ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } अन्यथा अगर ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } अन्यथा अगर ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } अन्यथा अगर ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            अन्यथा अगर ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            अन्यथा अगर ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            अन्यथा अगर ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            अन्यथा
                out_op(IL_OP_LDIND_I4);
        } 
    } अन्यथा {
        अगर (v == VT_CONST) {
            /* XXX: handle globals */
            अगर (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } अन्यथा {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } अन्यथा अगर (v == VT_LOCAL) {
            अगर (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                अगर (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } अन्यथा {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } अन्यथा {
                अगर (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } अन्यथा {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } अन्यथा {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
व्योम store(पूर्णांक r, SValue *sv)
{
    पूर्णांक v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    अगर (v == VT_LOCAL) {
        अगर (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            अगर (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } अन्यथा {
                out_opi(IL_OP_STARG, fc);
            }
        } अन्यथा {
            अगर (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } अन्यथा अगर (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } अन्यथा {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } अन्यथा अगर (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } अन्यथा {
        अगर ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        अन्यथा अगर ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        अन्यथा अगर ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        अन्यथा अगर ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        अन्यथा अगर ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        अन्यथा
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
व्योम gfunc_start(GFuncContext *c, पूर्णांक func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
व्योम gfunc_param(GFuncContext *c)
{
    अगर ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } अन्यथा {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
व्योम gfunc_call(GFuncContext *c)
{
    अक्षर buf[1024];

    अगर ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, माप(buf), vtop->t, "xxx");
        ख_लिखो(il_outfile, " call %s\n", buf);
    } अन्यथा {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, माप(buf), vtop->t, शून्य);
        ख_लिखो(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
व्योम gfunc_prolog(पूर्णांक t)
{
    पूर्णांक addr, u, func_call;
    Sym *sym;
    अक्षर buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, माप(buf), t, funcname);
    ख_लिखो(il_outfile, ".method static %s il managed\n", buf);
    ख_लिखो(il_outfile, "{\n");
    /* XXX: cannot do better now */
    ख_लिखो(il_outfile, " .maxstack %d\n", NB_REGS);
    ख_लिखो(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    अगर (!म_भेद(funcname, "main"))
        ख_लिखो(il_outfile, " .entrypoint\n");
        
    sym = sym_find((अचिन्हित)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    अगर ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    जबतक ((sym = sym->अग्र) != शून्य) {
        u = sym->t;
        sym_धकेलो(sym->v & ~SYM_FIELD, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
व्योम gfunc_epilog(व्योम)
{
    out_op(IL_OP_RET);
    ख_लिखो(il_outfile, "}\n\n");
}

/* generate a jump to a label */
पूर्णांक gjmp(पूर्णांक t)
{
    वापस out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
व्योम gjmp_addr(पूर्णांक a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
पूर्णांक gtst(पूर्णांक inv, पूर्णांक t)
{
    पूर्णांक v, *p, c;

    v = vtop->r & VT_VALMASK;
    अगर (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        चयन(c) {
        हाल TOK_EQ:
            c = IL_OP_BEQ;
            अवरोध;
        हाल TOK_NE:
            c = IL_OP_BNE_UN;
            अवरोध;
        हाल TOK_LT:
            c = IL_OP_BLT;
            अवरोध;
        हाल TOK_LE:
            c = IL_OP_BLE;
            अवरोध;
        हाल TOK_GT:
            c = IL_OP_BGT;
            अवरोध;
        हाल TOK_GE:
            c = IL_OP_BGE;
            अवरोध;
        हाल TOK_ULT:
            c = IL_OP_BLT_UN;
            अवरोध;
        हाल TOK_ULE:
            c = IL_OP_BLE_UN;
            अवरोध;
        हाल TOK_UGT:
            c = IL_OP_BGT_UN;
            अवरोध;
        हाल TOK_UGE:
            c = IL_OP_BGE_UN;
            अवरोध;
        }
        t = out_opj(c, t);
    } अन्यथा अगर (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        अगर ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            जबतक (*p != 0)
                p = (पूर्णांक *)*p;
            *p = t;
            t = vtop->c.i;
        } अन्यथा {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    वापस t;
}

/* generate an integer binary operation */
व्योम gen_opi(पूर्णांक op)
{
    gv2(RC_ST1, RC_ST0);
    चयन(op) {
    हाल '+':
        out_op(IL_OP_ADD);
        जाओ std_op;
    हाल '-':
        out_op(IL_OP_SUB);
        जाओ std_op;
    हाल '&':
        out_op(IL_OP_AND);
        जाओ std_op;
    हाल '^':
        out_op(IL_OP_XOR);
        जाओ std_op;
    हाल '|':
        out_op(IL_OP_OR);
        जाओ std_op;
    हाल '*':
        out_op(IL_OP_MUL);
        जाओ std_op;
    हाल TOK_SHL:
        out_op(IL_OP_SHL);
        जाओ std_op;
    हाल TOK_SHR:
        out_op(IL_OP_SHR_UN);
        जाओ std_op;
    हाल TOK_SAR:
        out_op(IL_OP_SHR);
        जाओ std_op;
    हाल '/':
    हाल TOK_PDIV:
        out_op(IL_OP_DIV);
        जाओ std_op;
    हाल TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        जाओ std_op;
    हाल '%':
        out_op(IL_OP_REM);
        जाओ std_op;
    हाल TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        अवरोध;
    हाल TOK_EQ:
    हाल TOK_NE:
    हाल TOK_LT:
    हाल TOK_LE:
    हाल TOK_GT:
    हाल TOK_GE:
    हाल TOK_ULT:
    हाल TOK_ULE:
    हाल TOK_UGT:
    हाल TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        अवरोध;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
व्योम gen_opf(पूर्णांक op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
व्योम gen_cvt_itof(पूर्णांक t)
{
    gv(RC_ST0);
    अगर (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    अन्यथा
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
व्योम gen_cvt_ftoi(पूर्णांक t)
{
    gv(RC_ST0);
    चयन(t) {
    हाल VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        अवरोध;
    हाल VT_LLONG:
        out_op(IL_OP_CONV_I8);
        अवरोध;
    हाल VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        अवरोध;
    शेष:
        out_op(IL_OP_CONV_I4);
        अवरोध;
    }
}

/* convert from one floating point type to another */
व्योम gen_cvt_ftof(पूर्णांक t)
{
    gv(RC_ST0);
    अगर (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } अन्यथा {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

