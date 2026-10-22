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
ଗଣନା {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା reg_classes[NB_REGS] = {
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
#define PTR_SIZE 4

/* long double size and alignment, in bytes */
#define LDOUBLE_SIZE  8
#define LDOUBLE_ALIGN 8

/* function call context */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା GFuncContext {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#define IL_OP_PREFIX 0xFE

ଗଣନା ILOPCodes {
#define OP(name, str, n) IL_OP_ ## name = n,
#ଅନ୍ତର୍ଭାଵ "il-opcodes.h"
#undef OP
};

ଅକ୍ଷର *il_opcodes_str[] = {
#define OP(name, str, n) [n] = str,
#ଅନ୍ତର୍ଭାଵ "il-opcodes.h"
#undef OP
};

/******************************************************/

/* arguments variable numbers start from there */
#define ARG_BASE 0x70000000

ସ୍ଥିର FILE *il_outfile;

ସ୍ଥିର ଶୂନ୍ୟ out_byte(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    *(ଅକ୍ଷର *)ind++ = c;
}

ସ୍ଥିର ଶୂନ୍ୟ out_le32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

ସ୍ଥିର ଶୂନ୍ୟ init_outfile(ଶୂନ୍ୟ)
{
    ଯଦି (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ out_op1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    ଯଦି (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
ସ୍ଥିର ଶୂନ୍ୟ out_op(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    out_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

ସ୍ଥିର ଶୂନ୍ୟ out_opb(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    out_op1(op);
    out_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

ସ୍ଥିର ଶୂନ୍ୟ out_opi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    out_op1(op);
    out_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
ସ୍ଥିର ଶୂନ୍ୟ il_type_to_str(ଅକ୍ଷର *buf, ପୂର୍ଣ୍ଣସଂଖ୍ୟା buf_size, 
                           ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ଅଚଳ ଅକ୍ଷର *varstr)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt;
    Sym *s, *sa;
    ଅକ୍ଷର buf1[256];
    ଅଚଳ ଅକ୍ଷର *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    ଯଦି (t & VT_UNSIGNED)
        pstrcat(buf, buf_size, "unsigned ");
    ବାଛ(bt) {
    ସ୍ଥିତି VT_VOID:
        tstr = "void";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_BOOL:
        tstr = "bool";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_BYTE:
        tstr = "int8";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_SHORT:
        tstr = "int16";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_ENUM:
    ସ୍ଥିତି VT_INT:
    ସ୍ଥିତି VT_LONG:
        tstr = "int32";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_LLONG:
        tstr = "int64";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_FLOAT:
        tstr = "float32";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_DOUBLE:
    ସ୍ଥିତି VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି VT_STRUCT:
        tcc_error("structures not handled yet");
        ଭାଙ୍ଗ;
    ସ୍ଥିତି VT_FUNC:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_size, s->t, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        ଯେତେବେଳେ (sa != ଖାଲି) {
            il_type_to_str(buf1, ଆକାର(buf1), sa->t, ଖାଲି);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            ଯଦି (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        ଯାଅ no_var;
    ସ୍ଥିତି VT_PTR:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, ଆକାର(buf1), "*");
        ଯଦି (varstr)
            pstrcat(buf1, ଆକାର(buf1), varstr);
        il_type_to_str(buf, buf_size, s->t, buf1);
        ଯାଅ no_var;
    }
    ଯଦି (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
ଶୂନ୍ୟ greloc_patch1(Reloc *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା val)
{
}

/* output a symbol and patch all calls to it */
ଶୂନ୍ୟ gsym_addr(t, a)
{
}

/* output jump and return symbol */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା out_opj(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    out_op1(op);
    out_le32(0);
    ଯଦି (c == 0) {
        c = ind - (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)cur_text_section->data;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    ଫେରନ୍ତୁ c;
}

ଶୂନ୍ୟ gsym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
ଶୂନ୍ୟ load(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, SValue *sv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    ଯଦି (sv->r & VT_LVAL) {
        ଯଦି (v == VT_LOCAL) {
            ଯଦି (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                ଯଦି (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } ଅନ୍ୟଥା ଯଦି (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } ଅନ୍ୟଥା {
                    out_opi(IL_OP_LDARG, fc);
                }
            } ଅନ୍ୟଥା {
                ଯଦି (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } ଅନ୍ୟଥା ଯଦି (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } ଅନ୍ୟଥା {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } ଅନ୍ୟଥା ଯଦି (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } ଅନ୍ୟଥା {
            ଯଦି ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } ଅନ୍ୟଥା ଯଦି ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } ଅନ୍ୟଥା ଯଦି ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } ଅନ୍ୟଥା ଯଦି ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            ଅନ୍ୟଥା ଯଦି ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            ଅନ୍ୟଥା ଯଦି ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            ଅନ୍ୟଥା ଯଦି ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            ଅନ୍ୟଥା
                out_op(IL_OP_LDIND_I4);
        } 
    } ଅନ୍ୟଥା {
        ଯଦି (v == VT_CONST) {
            /* XXX: handle globals */
            ଯଦି (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } ଅନ୍ୟଥା {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } ଅନ୍ୟଥା ଯଦି (v == VT_LOCAL) {
            ଯଦି (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                ଯଦି (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } ଅନ୍ୟଥା {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } ଅନ୍ୟଥା {
                ଯଦି (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } ଅନ୍ୟଥା {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } ଅନ୍ୟଥା {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ଶୂନ୍ୟ store(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, SValue *sv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    ଯଦି (v == VT_LOCAL) {
        ଯଦି (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            ଯଦି (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } ଅନ୍ୟଥା {
                out_opi(IL_OP_STARG, fc);
            }
        } ଅନ୍ୟଥା {
            ଯଦି (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } ଅନ୍ୟଥା ଯଦି (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } ଅନ୍ୟଥା {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } ଅନ୍ୟଥା ଯଦି (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } ଅନ୍ୟଥା {
        ଯଦି ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        ଅନ୍ୟଥା ଯଦି ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        ଅନ୍ୟଥା ଯଦି ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        ଅନ୍ୟଥା ଯଦି ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        ଅନ୍ୟଥା ଯଦି ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        ଅନ୍ୟଥା
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
ଶୂନ୍ୟ gfunc_start(GFuncContext *c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
ଶୂନ୍ୟ gfunc_param(GFuncContext *c)
{
    ଯଦି ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } ଅନ୍ୟଥା {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
ଶୂନ୍ୟ gfunc_call(GFuncContext *c)
{
    ଅକ୍ଷର buf[1024];

    ଯଦି ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, ଆକାର(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } ଅନ୍ୟଥା {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, ଆକାର(buf), vtop->t, ଖାଲି);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
ଶୂନ୍ୟ gfunc_prolog(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr, u, func_call;
    Sym *sym;
    ଅକ୍ଷର buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, ଆକାର(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    ଯଦି (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    ଯଦି ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    ଯେତେବେଳେ ((sym = sym->next) != ଖାଲି) {
        u = sym->t;
        sym_ଠେଲ(sym->v & ~SYM_FIELD, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
ଶୂନ୍ୟ gfunc_epilog(ଶୂନ୍ୟ)
{
    out_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା gjmp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଫେରନ୍ତୁ out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
ଶୂନ୍ୟ gjmp_addr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା gtst(ପୂର୍ଣ୍ଣସଂଖ୍ୟା inv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, *p, c;

    v = vtop->r & VT_VALMASK;
    ଯଦି (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        ବାଛ(c) {
        ସ୍ଥିତି TOK_EQ:
            c = IL_OP_BEQ;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_NE:
            c = IL_OP_BNE_UN;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_LT:
            c = IL_OP_BLT;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_LE:
            c = IL_OP_BLE;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_GT:
            c = IL_OP_BGT;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_GE:
            c = IL_OP_BGE;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ULT:
            c = IL_OP_BLT_UN;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ULE:
            c = IL_OP_BLE_UN;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_UGT:
            c = IL_OP_BGT_UN;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_UGE:
            c = IL_OP_BGE_UN;
            ଭାଙ୍ଗ;
        }
        t = out_opj(c, t);
    } ଅନ୍ୟଥା ଯଦି (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        ଯଦି ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            ଯେତେବେଳେ (*p != 0)
                p = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)*p;
            *p = t;
            t = vtop->c.i;
        } ଅନ୍ୟଥା {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    ଫେରନ୍ତୁ t;
}

/* generate an integer binary operation */
ଶୂନ୍ୟ gen_opi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    gv2(RC_ST1, RC_ST0);
    ବାଛ(op) {
    ସ୍ଥିତି '+':
        out_op(IL_OP_ADD);
        ଯାଅ std_op;
    ସ୍ଥିତି '-':
        out_op(IL_OP_SUB);
        ଯାଅ std_op;
    ସ୍ଥିତି '&':
        out_op(IL_OP_AND);
        ଯାଅ std_op;
    ସ୍ଥିତି '^':
        out_op(IL_OP_XOR);
        ଯାଅ std_op;
    ସ୍ଥିତି '|':
        out_op(IL_OP_OR);
        ଯାଅ std_op;
    ସ୍ଥିତି '*':
        out_op(IL_OP_MUL);
        ଯାଅ std_op;
    ସ୍ଥିତି TOK_SHL:
        out_op(IL_OP_SHL);
        ଯାଅ std_op;
    ସ୍ଥିତି TOK_SHR:
        out_op(IL_OP_SHR_UN);
        ଯାଅ std_op;
    ସ୍ଥିତି TOK_SAR:
        out_op(IL_OP_SHR);
        ଯାଅ std_op;
    ସ୍ଥିତି '/':
    ସ୍ଥିତି TOK_PDIV:
        out_op(IL_OP_DIV);
        ଯାଅ std_op;
    ସ୍ଥିତି TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        ଯାଅ std_op;
    ସ୍ଥିତି '%':
        out_op(IL_OP_REM);
        ଯାଅ std_op;
    ସ୍ଥିତି TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_EQ:
    ସ୍ଥିତି TOK_NE:
    ସ୍ଥିତି TOK_LT:
    ସ୍ଥିତି TOK_LE:
    ସ୍ଥିତି TOK_GT:
    ସ୍ଥିତି TOK_GE:
    ସ୍ଥିତି TOK_ULT:
    ସ୍ଥିତି TOK_ULE:
    ସ୍ଥିତି TOK_UGT:
    ସ୍ଥିତି TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        ଭାଙ୍ଗ;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
ଶୂନ୍ୟ gen_opf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ଶୂନ୍ୟ gen_cvt_itof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    gv(RC_ST0);
    ଯଦି (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    ଅନ୍ୟଥା
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
ଶୂନ୍ୟ gen_cvt_ftoi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    gv(RC_ST0);
    ବାଛ(t) {
    ସ୍ଥିତି VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି VT_LLONG:
        out_op(IL_OP_CONV_I8);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        out_op(IL_OP_CONV_I4);
        ଭାଙ୍ଗ;
    }
}

/* convert from one floating point type to another */
ଶୂନ୍ୟ gen_cvt_ftof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    gv(RC_ST0);
    ଯଦି (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } ଅନ୍ୟଥା {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

