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

#error this code has bit-rotted since 2003

/* number of available registers */
#define NB_REGS             3

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#define RC_ST      0x0001  /* any stack entry */
#define RC_ST0     0x0002  /* top of stack */
#define RC_ST1     0x0004  /* top - 1 */

#define RC_INT     RC_ST
#define RC_FLOAT   RC_ST
#define RC_IRET    RC_ST0 /* function return: integer register */
#define RC_LRET    RC_ST0 /* function return: second integer register */
#define RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
গণনা {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

ধ্রুবক পূর্ণসংখ্যা reg_classes[NB_REGS] = {
    /* ST0 */ RC_ST | RC_ST0,
    /* ST1 */ RC_ST | RC_ST1,
    /* ST2 */ RC_ST,
};

/* return registers for function */
#define REG_IRET REG_ST0 /* single word int return register */
#define REG_LRET REG_ST0 /* second word return register (for long long) */
#define REG_FRET REG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
/* #define INVERT_FUNC_PARAMS */

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#define PTR_আকার 4

/* long double size and alignment, in bytes */
#define LDOUBLE_আকার  8
#define LDOUBLE_ALIGN 8

/* function call context */
প্রকারলেখ কাঠামো GFuncContext {
    পূর্ণসংখ্যা func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#define IL_OP_PREFIX 0xFE

গণনা ILOPCodes {
#define OP(name, str, n) IL_OP_ ## name = n,
#অন্তর্ভাব "il-opcodes.h"
#undef OP
};

অক্ষর *il_opcodes_str[] = {
#define OP(name, str, n) [n] = str,
#অন্তর্ভাব "il-opcodes.h"
#undef OP
};

/******************************************************/

/* arguments variable numbers start from there */
#define ARG_BASE 0x70000000

স্থির FILE *il_outfile;

স্থির শূন্য out_byte(পূর্ণসংখ্যা c)
{
    *(অক্ষর *)ind++ = c;
}

স্থির শূন্য out_le32(পূর্ণসংখ্যা c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

স্থির শূন্য init_outfile(শূন্য)
{
    যদি (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

স্থির শূন্য out_op1(পূর্ণসংখ্যা op)
{
    যদি (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
স্থির শূন্য out_op(পূর্ণসংখ্যা op)
{
    out_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

স্থির শূন্য out_opb(পূর্ণসংখ্যা op, পূর্ণসংখ্যা c)
{
    out_op1(op);
    out_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

স্থির শূন্য out_opi(পূর্ণসংখ্যা op, পূর্ণসংখ্যা c)
{
    out_op1(op);
    out_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
স্থির শূন্য il_type_to_str(অক্ষর *buf, পূর্ণসংখ্যা buf_আকার, 
                           পূর্ণসংখ্যা t, ধ্রুবক অক্ষর *varstr)
{
    পূর্ণসংখ্যা bt;
    Sym *s, *sa;
    অক্ষর buf1[256];
    ধ্রুবক অক্ষর *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    যদি (t & VT_UNSIGNED)
        pstrcat(buf, buf_আকার, "unsigned ");
    নির্বাচন(bt) {
    ক্ষেত্র VT_VOID:
        tstr = "void";
        যাও add_tstr;
    ক্ষেত্র VT_BOOL:
        tstr = "bool";
        যাও add_tstr;
    ক্ষেত্র VT_BYTE:
        tstr = "int8";
        যাও add_tstr;
    ক্ষেত্র VT_SHORT:
        tstr = "int16";
        যাও add_tstr;
    ক্ষেত্র VT_ENUM:
    ক্ষেত্র VT_INT:
    ক্ষেত্র VT_LONG:
        tstr = "int32";
        যাও add_tstr;
    ক্ষেত্র VT_LLONG:
        tstr = "int64";
        যাও add_tstr;
    ক্ষেত্র VT_FLOAT:
        tstr = "float32";
        যাও add_tstr;
    ক্ষেত্র VT_DOUBLE:
    ক্ষেত্র VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_আকার, tstr);
        বিরতি;
    ক্ষেত্র VT_STRUCT:
        tcc_error("structures not handled yet");
        বিরতি;
    ক্ষেত্র VT_FUNC:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_আকার, s->t, varstr);
        pstrcat(buf, buf_আকার, "(");
        sa = s->পরবর্তী;
        যখন (sa != ফাঁকা) {
            il_type_to_str(buf1, আকার(buf1), sa->t, ফাঁকা);
            pstrcat(buf, buf_আকার, buf1);
            sa = sa->পরবর্তী;
            যদি (sa)
                pstrcat(buf, buf_আকার, ", ");
        }
        pstrcat(buf, buf_আকার, ")");
        যাও no_var;
    ক্ষেত্র VT_PTR:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, আকার(buf1), "*");
        যদি (varstr)
            pstrcat(buf1, আকার(buf1), varstr);
        il_type_to_str(buf, buf_আকার, s->t, buf1);
        যাও no_var;
    }
    যদি (varstr) {
        pstrcat(buf, buf_আকার, " ");
        pstrcat(buf, buf_আকার, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
শূন্য greloc_patch1(Reloc *p, পূর্ণসংখ্যা val)
{
}

/* output a symbol and patch all calls to it */
শূন্য gsym_addr(t, a)
{
}

/* output jump and return symbol */
স্থির পূর্ণসংখ্যা out_opj(পূর্ণসংখ্যা op, পূর্ণসংখ্যা c)
{
    out_op1(op);
    out_le32(0);
    যদি (c == 0) {
        c = ind - (পূর্ণসংখ্যা)cur_text_section->তথ্য;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    ফেরত c;
}

শূন্য gsym(পূর্ণসংখ্যা t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
শূন্য load(পূর্ণসংখ্যা r, SValue *sv)
{
    পূর্ণসংখ্যা v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    যদি (sv->r & VT_LVAL) {
        যদি (v == VT_LOCAL) {
            যদি (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                যদি (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } অন্যথা যদি (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } অন্যথা {
                    out_opi(IL_OP_LDARG, fc);
                }
            } অন্যথা {
                যদি (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } অন্যথা যদি (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } অন্যথা {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } অন্যথা যদি (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } অন্যথা {
            যদি ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } অন্যথা যদি ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } অন্যথা যদি ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } অন্যথা যদি ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            অন্যথা যদি ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            অন্যথা যদি ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            অন্যথা যদি ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            অন্যথা
                out_op(IL_OP_LDIND_I4);
        } 
    } অন্যথা {
        যদি (v == VT_CONST) {
            /* XXX: handle globals */
            যদি (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } অন্যথা {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } অন্যথা যদি (v == VT_LOCAL) {
            যদি (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                যদি (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } অন্যথা {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } অন্যথা {
                যদি (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } অন্যথা {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } অন্যথা {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
শূন্য store(পূর্ণসংখ্যা r, SValue *sv)
{
    পূর্ণসংখ্যা v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    যদি (v == VT_LOCAL) {
        যদি (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            যদি (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } অন্যথা {
                out_opi(IL_OP_STARG, fc);
            }
        } অন্যথা {
            যদি (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } অন্যথা যদি (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } অন্যথা {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } অন্যথা যদি (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } অন্যথা {
        যদি ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        অন্যথা যদি ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        অন্যথা যদি ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        অন্যথা যদি ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        অন্যথা যদি ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        অন্যথা
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
শূন্য gfunc_start(GFuncContext *c, পূর্ণসংখ্যা func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
শূন্য gfunc_param(GFuncContext *c)
{
    যদি ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } অন্যথা {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
শূন্য gfunc_call(GFuncContext *c)
{
    অক্ষর buf[1024];

    যদি ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, আকার(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } অন্যথা {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, আকার(buf), vtop->t, ফাঁকা);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
শূন্য gfunc_prolog(পূর্ণসংখ্যা t)
{
    পূর্ণসংখ্যা addr, u, func_call;
    Sym *sym;
    অক্ষর buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, আকার(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    যদি (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    যদি ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    যখন ((sym = sym->পরবর্তী) != ফাঁকা) {
        u = sym->t;
        sym_ঠেলো(sym->v & ~SYM_FIELD, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
শূন্য gfunc_epilog(শূন্য)
{
    out_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
পূর্ণসংখ্যা gjmp(পূর্ণসংখ্যা t)
{
    ফেরত out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
শূন্য gjmp_addr(পূর্ণসংখ্যা a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
পূর্ণসংখ্যা gtst(পূর্ণসংখ্যা inv, পূর্ণসংখ্যা t)
{
    পূর্ণসংখ্যা v, *p, c;

    v = vtop->r & VT_VALMASK;
    যদি (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        নির্বাচন(c) {
        ক্ষেত্র TOK_EQ:
            c = IL_OP_BEQ;
            বিরতি;
        ক্ষেত্র TOK_NE:
            c = IL_OP_BNE_UN;
            বিরতি;
        ক্ষেত্র TOK_LT:
            c = IL_OP_BLT;
            বিরতি;
        ক্ষেত্র TOK_LE:
            c = IL_OP_BLE;
            বিরতি;
        ক্ষেত্র TOK_GT:
            c = IL_OP_BGT;
            বিরতি;
        ক্ষেত্র TOK_GE:
            c = IL_OP_BGE;
            বিরতি;
        ক্ষেত্র TOK_ULT:
            c = IL_OP_BLT_UN;
            বিরতি;
        ক্ষেত্র TOK_ULE:
            c = IL_OP_BLE_UN;
            বিরতি;
        ক্ষেত্র TOK_UGT:
            c = IL_OP_BGT_UN;
            বিরতি;
        ক্ষেত্র TOK_UGE:
            c = IL_OP_BGE_UN;
            বিরতি;
        }
        t = out_opj(c, t);
    } অন্যথা যদি (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        যদি ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            যখন (*p != 0)
                p = (পূর্ণসংখ্যা *)*p;
            *p = t;
            t = vtop->c.i;
        } অন্যথা {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    ফেরত t;
}

/* generate an integer binary operation */
শূন্য gen_opi(পূর্ণসংখ্যা op)
{
    gv2(RC_ST1, RC_ST0);
    নির্বাচন(op) {
    ক্ষেত্র '+':
        out_op(IL_OP_ADD);
        যাও std_op;
    ক্ষেত্র '-':
        out_op(IL_OP_SUB);
        যাও std_op;
    ক্ষেত্র '&':
        out_op(IL_OP_AND);
        যাও std_op;
    ক্ষেত্র '^':
        out_op(IL_OP_XOR);
        যাও std_op;
    ক্ষেত্র '|':
        out_op(IL_OP_OR);
        যাও std_op;
    ক্ষেত্র '*':
        out_op(IL_OP_MUL);
        যাও std_op;
    ক্ষেত্র TOK_SHL:
        out_op(IL_OP_SHL);
        যাও std_op;
    ক্ষেত্র TOK_SHR:
        out_op(IL_OP_SHR_UN);
        যাও std_op;
    ক্ষেত্র TOK_SAR:
        out_op(IL_OP_SHR);
        যাও std_op;
    ক্ষেত্র '/':
    ক্ষেত্র TOK_PDIV:
        out_op(IL_OP_DIV);
        যাও std_op;
    ক্ষেত্র TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        যাও std_op;
    ক্ষেত্র '%':
        out_op(IL_OP_REM);
        যাও std_op;
    ক্ষেত্র TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        বিরতি;
    ক্ষেত্র TOK_EQ:
    ক্ষেত্র TOK_NE:
    ক্ষেত্র TOK_LT:
    ক্ষেত্র TOK_LE:
    ক্ষেত্র TOK_GT:
    ক্ষেত্র TOK_GE:
    ক্ষেত্র TOK_ULT:
    ক্ষেত্র TOK_ULE:
    ক্ষেত্র TOK_UGT:
    ক্ষেত্র TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        বিরতি;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
শূন্য gen_opf(পূর্ণসংখ্যা op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
শূন্য gen_cvt_itof(পূর্ণসংখ্যা t)
{
    gv(RC_ST0);
    যদি (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    অন্যথা
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
শূন্য gen_cvt_ftoi(পূর্ণসংখ্যা t)
{
    gv(RC_ST0);
    নির্বাচন(t) {
    ক্ষেত্র VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        বিরতি;
    ক্ষেত্র VT_LLONG:
        out_op(IL_OP_CONV_I8);
        বিরতি;
    ক্ষেত্র VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        বিরতি;
    পূর্বনির্ধারিত:
        out_op(IL_OP_CONV_I4);
        বিরতি;
    }
}

/* convert from one floating point type to another */
শূন্য gen_cvt_ftof(পূর্ণসংখ্যা t)
{
    gv(RC_ST0);
    যদি (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } অন্যথা {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

