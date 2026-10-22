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

#تېروتنه this کوډ has بټ-rotted since 2003

/* number of available registers */
#تعریف_کړه NB_REGS             3

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#تعریف_کړه RC_ST      0x0001  /* any stack entry */
#تعریف_کړه RC_ST0     0x0002  /* top of stack */
#تعریف_کړه RC_ST1     0x0004  /* top - 1 */

#تعریف_کړه RC_INT     RC_ST
#تعریف_کړه RC_FLOAT   RC_ST
#تعریف_کړه RC_IRET    RC_ST0 /* function return: integer register */
#تعریف_کړه RC_LRET    RC_ST0 /* function return: second integer register */
#تعریف_کړه RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
تعداد {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

ثابت صحيح reg_classes[NB_REGS] = {
    /* ST0 */ RC_ST | RC_ST0,
    /* ST1 */ RC_ST | RC_ST1,
    /* ST2 */ RC_ST,
};

/* return registers for function */
#تعریف_کړه REG_IRET REG_ST0 /* single word int return register */
#تعریف_کړه REG_LRET REG_ST0 /* second word return register (for long long) */
#تعریف_کړه REG_FRET REG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
/* #define INVERT_FUNC_PARAMS */

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#تعریف_کړه PTR_اندازه 4

/* long double size and alignment, in bytes */
#تعریف_کړه LDOUBLE_اندازه  8
#تعریف_کړه LDOUBLE_ALIGN 8

/* function call context */
تعريفنوع بنية GFuncContext {
    صحيح func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#تعریف_کړه IL_OP_مختاړی 0xFE

تعداد ILOPCodes {
#تعریف_کړه OP(name, str, n) IL_OP_ ## name = n,
#ضمن "il-opcodes.h"
#تعریف_لغوه OP
};

حرف *il_opcodes_str[] = {
#تعریف_کړه OP(name, str, n) [n] = str,
#ضمن "il-opcodes.h"
#تعریف_لغوه OP
};

/******************************************************/

/* arguments variable numbers start from there */
#تعریف_کړه ARG_بنسټ 0x70000000

ساكن FILE *il_outfile;

ساكن فراغ بهر_byte(صحيح c)
{
    *(حرف *)ind++ = c;
}

ساكن فراغ بهر_le32(صحيح c)
{
    بهر_byte(c);
    بهر_byte(c >> 8);
    بهر_byte(c >> 16);
    بهر_byte(c >> 24);
}

ساكن فراغ init_outfile(فراغ)
{
    إذا (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

ساكن فراغ بهر_op1(صحيح op)
{
    إذا (op & 0x100)
        بهر_byte(IL_OP_مختاړی);
    بهر_byte(op & 0xff);
}

/* output an opcode with prefix */
ساكن فراغ بهر_op(صحيح op)
{
    بهر_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

ساكن فراغ بهر_opb(صحيح op, صحيح c)
{
    بهر_op1(op);
    بهر_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

ساكن فراغ بهر_opi(صحيح op, صحيح c)
{
    بهر_op1(op);
    بهر_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
ساكن فراغ il_type_منزل_str(حرف *buf, صحيح buf_اندازه, 
                           صحيح t, ثابت حرف *varstr)
{
    صحيح bt;
    Sym *s, *sa;
    حرف buf1[256];
    ثابت حرف *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    إذا (t & VT_UNSIGNED)
        pstrcat(buf, buf_اندازه, "unsigned ");
    بدل(bt) {
    حالة VT_VOID:
        tstr = "void";
        اذهب جمع_کړه_tstr;
    حالة VT_BOOL:
        tstr = "bool";
        اذهب جمع_کړه_tstr;
    حالة VT_BYTE:
        tstr = "int8";
        اذهب جمع_کړه_tstr;
    حالة VT_SHORT:
        tstr = "int16";
        اذهب جمع_کړه_tstr;
    حالة VT_ENUM:
    حالة VT_INT:
    حالة VT_LONG:
        tstr = "int32";
        اذهب جمع_کړه_tstr;
    حالة VT_LLONG:
        tstr = "int64";
        اذهب جمع_کړه_tstr;
    حالة VT_FLOAT:
        tstr = "float32";
        اذهب جمع_کړه_tstr;
    حالة VT_DOUBLE:
    حالة VT_LDOUBLE:
        tstr = "float64";
    جمع_کړه_tstr:
        pstrcat(buf, buf_اندازه, tstr);
        اكسر;
    حالة VT_STRUCT:
        tcc_error("structures not handled yet");
        اكسر;
    حالة VT_FUNC:
        s = sym_پیدا_کړه((بینښه)t >> VT_STRUCT_ښويدنه);
        il_type_منزل_str(buf, buf_اندازه, s->t, varstr);
        pstrcat(buf, buf_اندازه, "(");
        sa = s->بل;
        طالما (sa != عدم) {
            il_type_منزل_str(buf1, حجم(buf1), sa->t, عدم);
            pstrcat(buf, buf_اندازه, buf1);
            sa = sa->بل;
            إذا (sa)
                pstrcat(buf, buf_اندازه, ", ");
        }
        pstrcat(buf, buf_اندازه, ")");
        اذهب no_var;
    حالة VT_PTR:
        s = sym_پیدا_کړه((بینښه)t >> VT_STRUCT_ښويدنه);
        pstrcpy(buf1, حجم(buf1), "*");
        إذا (varstr)
            pstrcat(buf1, حجم(buf1), varstr);
        il_type_منزل_str(buf, buf_اندازه, s->t, buf1);
        اذهب no_var;
    }
    إذا (varstr) {
        pstrcat(buf, buf_اندازه, " ");
        pstrcat(buf, buf_اندازه, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
فراغ greloc_patch1(Reloc *p, صحيح val)
{
}

/* output a symbol and patch all calls to it */
فراغ gsym_addr(t, a)
{
}

/* output jump and return symbol */
ساكن صحيح بهر_opj(صحيح op, صحيح c)
{
    بهر_op1(op);
    بهر_le32(0);
    إذا (c == 0) {
        c = ind - (صحيح)cur_متن_section->معلومات;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    أرجع c;
}

فراغ gsym(صحيح t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
فراغ بارول(صحيح r, SValue *sv)
{
    صحيح v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    إذا (sv->r & VT_LVAL) {
        إذا (v == VT_LOCAL) {
            إذا (fc >= ARG_بنسټ) {
                fc -= ARG_بنسټ;
                إذا (fc >= 0 && fc <= 4) {
                    بهر_op(IL_OP_LDARG_0 + fc);
                } وإلا إذا (fc <= 0xff) {
                    بهر_opb(IL_OP_LDARG_S, fc);
                } وإلا {
                    بهر_opi(IL_OP_LDARG, fc);
                }
            } وإلا {
                إذا (fc >= 0 && fc <= 4) {
                    بهر_op(IL_OP_LDLOC_0 + fc);
                } وإلا إذا (fc <= 0xff) {
                    بهر_opb(IL_OP_LDLOC_S, fc);
                } وإلا {
                    بهر_opi(IL_OP_LDLOC, fc);
                }
            }
        } وإلا إذا (v == VT_CONST) {
                /* XXX: handle globals */
                بهر_opi(IL_OP_LDSFLD, 0);
        } وإلا {
            إذا ((ft & VT_BTYPE) == VT_FLOAT) {
                بهر_op(IL_OP_LDIND_R4);
            } وإلا إذا ((ft & VT_BTYPE) == VT_DOUBLE) {
                بهر_op(IL_OP_LDIND_R8);
            } وإلا إذا ((ft & VT_BTYPE) == VT_LDOUBLE) {
                بهر_op(IL_OP_LDIND_R8);
            } وإلا إذا ((ft & VT_TYPE) == VT_BYTE)
                بهر_op(IL_OP_LDIND_I1);
            وإلا إذا ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                بهر_op(IL_OP_LDIND_U1);
            وإلا إذا ((ft & VT_TYPE) == VT_SHORT)
                بهر_op(IL_OP_LDIND_I2);
            وإلا إذا ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                بهر_op(IL_OP_LDIND_U2);
            وإلا
                بهر_op(IL_OP_LDIND_I4);
        } 
    } وإلا {
        إذا (v == VT_CONST) {
            /* XXX: handle globals */
            إذا (fc >= -1 && fc <= 8) {
                بهر_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } وإلا {
                بهر_opi(IL_OP_LDC_I4, fc);
            }
        } وإلا إذا (v == VT_LOCAL) {
            إذا (fc >= ARG_بنسټ) {
                fc -= ARG_بنسټ;
                إذا (fc <= 0xff) {
                    بهر_opb(IL_OP_LDARGA_S, fc);
                } وإلا {
                    بهر_opi(IL_OP_LDARGA, fc);
                }
            } وإلا {
                إذا (fc <= 0xff) {
                    بهر_opb(IL_OP_LDLOCA_S, fc);
                } وإلا {
                    بهر_opi(IL_OP_LDLOCA, fc);
                }
            }
        } وإلا {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
فراغ store(صحيح r, SValue *sv)
{
    صحيح v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    إذا (v == VT_LOCAL) {
        إذا (fc >= ARG_بنسټ) {
            fc -= ARG_بنسټ;
            /* XXX: check IL arg store semantics */
            إذا (fc <= 0xff) {
                بهر_opb(IL_OP_STARG_S, fc);
            } وإلا {
                بهر_opi(IL_OP_STARG, fc);
            }
        } وإلا {
            إذا (fc >= 0 && fc <= 4) {
                بهر_op(IL_OP_STLOC_0 + fc);
            } وإلا إذا (fc <= 0xff) {
                بهر_opb(IL_OP_STLOC_S, fc);
            } وإلا {
                بهر_opi(IL_OP_STLOC, fc);
            }
        }
    } وإلا إذا (v == VT_CONST) {
        /* XXX: handle globals */
        بهر_opi(IL_OP_STSFLD, 0);
    } وإلا {
        إذا ((ft & VT_BTYPE) == VT_FLOAT)
            بهر_op(IL_OP_STIND_R4);
        وإلا إذا ((ft & VT_BTYPE) == VT_DOUBLE)
            بهر_op(IL_OP_STIND_R8);
        وإلا إذا ((ft & VT_BTYPE) == VT_LDOUBLE)
            بهر_op(IL_OP_STIND_R8);
        وإلا إذا ((ft & VT_BTYPE) == VT_BYTE)
            بهر_op(IL_OP_STIND_I1);
        وإلا إذا ((ft & VT_BTYPE) == VT_SHORT)
            بهر_op(IL_OP_STIND_I2);
        وإلا
            بهر_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
فراغ gfunc_پیل(GFuncContext *c, صحيح func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
فراغ gfunc_param(GFuncContext *c)
{
    إذا ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } وإلا {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
فراغ gfunc_call(GFuncContext *c)
{
    حرف buf[1024];

    إذا ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_منزل_str(buf, حجم(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } وإلا {
        /* indirect call */
        gv(RC_INT);
        il_type_منزل_str(buf, حجم(buf), vtop->t, عدم);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
فراغ gfunc_prolog(صحيح t)
{
    صحيح addr, u, func_call;
    Sym *sym;
    حرف buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_منزل_str(buf, حجم(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    إذا (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_پیدا_کړه((بینښه)t >> VT_STRUCT_ښويدنه);
    func_call = sym->r;

    addr = ARG_بنسټ;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    إذا ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    طالما ((sym = sym->بل) != عدم) {
        u = sym->t;
        sym_ټېل(sym->v & ~SYM_ډګر, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
فراغ gfunc_epilog(فراغ)
{
    بهر_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
صحيح gjmp(صحيح t)
{
    أرجع بهر_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
فراغ gjmp_addr(صحيح a)
{
    /* XXX: handle syms */
    بهر_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
صحيح gtst(صحيح inv, صحيح t)
{
    صحيح v, *p, c;

    v = vtop->r & VT_VALMASK;
    إذا (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        بدل(c) {
        حالة TOK_EQ:
            c = IL_OP_BEQ;
            اكسر;
        حالة TOK_NE:
            c = IL_OP_BNE_UN;
            اكسر;
        حالة TOK_LT:
            c = IL_OP_BLT;
            اكسر;
        حالة TOK_LE:
            c = IL_OP_BLE;
            اكسر;
        حالة TOK_GT:
            c = IL_OP_BGT;
            اكسر;
        حالة TOK_GE:
            c = IL_OP_BGE;
            اكسر;
        حالة TOK_ULT:
            c = IL_OP_BLT_UN;
            اكسر;
        حالة TOK_ULE:
            c = IL_OP_BLE_UN;
            اكسر;
        حالة TOK_UGT:
            c = IL_OP_BGT_UN;
            اكسر;
        حالة TOK_UGE:
            c = IL_OP_BGE_UN;
            اكسر;
        }
        t = بهر_opj(c, t);
    } وإلا إذا (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        إذا ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            طالما (*p != 0)
                p = (صحيح *)*p;
            *p = t;
            t = vtop->c.i;
        } وإلا {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    أرجع t;
}

/* generate an integer binary operation */
فراغ gen_opi(صحيح op)
{
    gv2(RC_ST1, RC_ST0);
    بدل(op) {
    حالة '+':
        بهر_op(IL_OP_جمع_کړه);
        اذهب std_op;
    حالة '-':
        بهر_op(IL_OP_SUB);
        اذهب std_op;
    حالة '&':
        بهر_op(IL_OP_AND);
        اذهب std_op;
    حالة '^':
        بهر_op(IL_OP_XOR);
        اذهب std_op;
    حالة '|':
        بهر_op(IL_OP_OR);
        اذهب std_op;
    حالة '*':
        بهر_op(IL_OP_MUL);
        اذهب std_op;
    حالة TOK_SHL:
        بهر_op(IL_OP_SHL);
        اذهب std_op;
    حالة TOK_SHR:
        بهر_op(IL_OP_SHR_UN);
        اذهب std_op;
    حالة TOK_SAR:
        بهر_op(IL_OP_SHR);
        اذهب std_op;
    حالة '/':
    حالة TOK_PDIV:
        بهر_op(IL_OP_DIV);
        اذهب std_op;
    حالة TOK_UDIV:
        بهر_op(IL_OP_DIV_UN);
        اذهب std_op;
    حالة '%':
        بهر_op(IL_OP_REM);
        اذهب std_op;
    حالة TOK_UMOD:
        بهر_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        اكسر;
    حالة TOK_EQ:
    حالة TOK_NE:
    حالة TOK_LT:
    حالة TOK_LE:
    حالة TOK_GT:
    حالة TOK_GE:
    حالة TOK_ULT:
    حالة TOK_ULE:
    حالة TOK_UGT:
    حالة TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        اكسر;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
فراغ gen_opf(صحيح op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
فراغ gen_cvt_itof(صحيح t)
{
    gv(RC_ST0);
    إذا (t == VT_FLOAT)
        بهر_op(IL_OP_CONV_R4);
    وإلا
        بهر_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
فراغ gen_cvt_ftoi(صحيح t)
{
    gv(RC_ST0);
    بدل(t) {
    حالة VT_INT | VT_UNSIGNED:
        بهر_op(IL_OP_CONV_U4);
        اكسر;
    حالة VT_LLONG:
        بهر_op(IL_OP_CONV_I8);
        اكسر;
    حالة VT_LLONG | VT_UNSIGNED:
        بهر_op(IL_OP_CONV_U8);
        اكسر;
    افتراضي:
        بهر_op(IL_OP_CONV_I4);
        اكسر;
    }
}

/* convert from one floating point type to another */
فراغ gen_cvt_ftof(صحيح t)
{
    gv(RC_ST0);
    إذا (t == VT_FLOAT) {
        بهر_op(IL_OP_CONV_R4);
    } وإلا {
        بهر_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

