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
ga_nanaa {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

const puur_naa_nka reg_classes[NB_REGS] = {
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
typedef sa_nracanaa GFuncContext {
    puur_naa_nka func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#define IL_OP_PREFIX 0xFE

ga_nanaa ILOPCodes {
#define OP(name, str, n) IL_OP_ ## name = n,
#include "il-opcodes.h"
#undef OP
};

var_na *il_opcodes_str[] = {
#define OP(name, str, n) [n] = str,
#include "il-opcodes.h"
#undef OP
};

/******************************************************/

/* arguments variable numbers start from there */
#define ARG_BASE 0x70000000

static FILE *il_outfile;

static void out_byte(puur_naa_nka c)
{
    *(var_na *)ind++ = c;
}

static void out_le32(puur_naa_nka c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

static void init_outfile(void)
{
    ᮚᮦᮔ᮪ (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

static void out_op1(puur_naa_nka op)
{
    ᮚᮦᮔ᮪ (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
static void out_op(puur_naa_nka op)
{
    out_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

static void out_opb(puur_naa_nka op, puur_naa_nka c)
{
    out_op1(op);
    out_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

static void out_opi(puur_naa_nka op, puur_naa_nka c)
{
    out_op1(op);
    out_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
static void il_type_to_str(var_na *buf, puur_naa_nka buf_size, 
                           puur_naa_nka t, const var_na *varstr)
{
    puur_naa_nka bt;
    Sym *s, *sa;
    var_na buf1[256];
    const var_na *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    ᮚᮦᮔ᮪ (t & VT_UNSIGNED)
        pstrcat(buf, buf_size, "unsigned ");
    switch(bt) {
    pak_sa VT_VOID:
        tstr = "void";
        goto add_tstr;
    pak_sa VT_BOOL:
        tstr = "bool";
        goto add_tstr;
    pak_sa VT_BYTE:
        tstr = "int8";
        goto add_tstr;
    pak_sa VT_SHORT:
        tstr = "int16";
        goto add_tstr;
    pak_sa VT_ENUM:
    pak_sa VT_INT:
    pak_sa VT_LONG:
        tstr = "int32";
        goto add_tstr;
    pak_sa VT_LLONG:
        tstr = "int64";
        goto add_tstr;
    pak_sa VT_FLOAT:
        tstr = "float32";
        goto add_tstr;
    pak_sa VT_DOUBLE:
    pak_sa VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        bha_nga;
    pak_sa VT_STRUCT:
        tcc_error("structures not handled yet");
        bha_nga;
    pak_sa VT_FUNC:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_size, s->t, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        ᮞᮨᮓᮨᮜ (sa != NULL) {
            il_type_to_str(buf1, parimaa_na(buf1), sa->t, NULL);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            ᮚᮦᮔ᮪ (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        goto no_var;
    pak_sa VT_PTR:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, parimaa_na(buf1), "*");
        ᮚᮦᮔ᮪ (varstr)
            pstrcat(buf1, parimaa_na(buf1), varstr);
        il_type_to_str(buf, buf_size, s->t, buf1);
        goto no_var;
    }
    ᮚᮦᮔ᮪ (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
void greloc_patch1(Reloc *p, puur_naa_nka val)
{
}

/* output a symbol and patch all calls to it */
void gsym_addr(t, a)
{
}

/* output jump and return symbol */
static puur_naa_nka out_opj(puur_naa_nka op, puur_naa_nka c)
{
    out_op1(op);
    out_le32(0);
    ᮚᮦᮔ᮪ (c == 0) {
        c = ind - (puur_naa_nka)cur_text_section->data;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    ᮝᮜᮤ c;
}

void gsym(puur_naa_nka t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
void load(puur_naa_nka r, SValue *sv)
{
    puur_naa_nka v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    ᮚᮦᮔ᮪ (sv->r & VT_LVAL) {
        ᮚᮦᮔ᮪ (v == VT_LOCAL) {
            ᮚᮦᮔ᮪ (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                ᮚᮦᮔ᮪ (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } ᮜᮤᮚ ᮚᮦᮔ᮪ (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } ᮜᮤᮚ {
                    out_opi(IL_OP_LDARG, fc);
                }
            } ᮜᮤᮚ {
                ᮚᮦᮔ᮪ (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } ᮜᮤᮚ ᮚᮦᮔ᮪ (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } ᮜᮤᮚ {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } ᮜᮤᮚ ᮚᮦᮔ᮪ (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } ᮜᮤᮚ {
            ᮚᮦᮔ᮪ ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } ᮜᮤᮚ ᮚᮦᮔ᮪ ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } ᮜᮤᮚ ᮚᮦᮔ᮪ ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } ᮜᮤᮚ ᮚᮦᮔ᮪ ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            ᮜᮤᮚ ᮚᮦᮔ᮪ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            ᮜᮤᮚ ᮚᮦᮔ᮪ ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            ᮜᮤᮚ ᮚᮦᮔ᮪ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            ᮜᮤᮚ
                out_op(IL_OP_LDIND_I4);
        } 
    } ᮜᮤᮚ {
        ᮚᮦᮔ᮪ (v == VT_CONST) {
            /* XXX: handle globals */
            ᮚᮦᮔ᮪ (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } ᮜᮤᮚ {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } ᮜᮤᮚ ᮚᮦᮔ᮪ (v == VT_LOCAL) {
            ᮚᮦᮔ᮪ (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                ᮚᮦᮔ᮪ (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } ᮜᮤᮚ {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } ᮜᮤᮚ {
                ᮚᮦᮔ᮪ (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } ᮜᮤᮚ {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } ᮜᮤᮚ {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
void store(puur_naa_nka r, SValue *sv)
{
    puur_naa_nka v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    ᮚᮦᮔ᮪ (v == VT_LOCAL) {
        ᮚᮦᮔ᮪ (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            ᮚᮦᮔ᮪ (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } ᮜᮤᮚ {
                out_opi(IL_OP_STARG, fc);
            }
        } ᮜᮤᮚ {
            ᮚᮦᮔ᮪ (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } ᮜᮤᮚ ᮚᮦᮔ᮪ (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } ᮜᮤᮚ {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } ᮜᮤᮚ {
        ᮚᮦᮔ᮪ ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        ᮜᮤᮚ ᮚᮦᮔ᮪ ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        ᮜᮤᮚ ᮚᮦᮔ᮪ ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        ᮜᮤᮚ ᮚᮦᮔ᮪ ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        ᮜᮤᮚ ᮚᮦᮔ᮪ ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        ᮜᮤᮚ
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
void gfunc_start(GFuncContext *c, puur_naa_nka func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
void gfunc_param(GFuncContext *c)
{
    ᮚᮦᮔ᮪ ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } ᮜᮤᮚ {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
void gfunc_call(GFuncContext *c)
{
    var_na buf[1024];

    ᮚᮦᮔ᮪ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, parimaa_na(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } ᮜᮤᮚ {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, parimaa_na(buf), vtop->t, NULL);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
void gfunc_prolog(puur_naa_nka t)
{
    puur_naa_nka addr, u, func_call;
    Sym *sym;
    var_na buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, parimaa_na(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    ᮚᮦᮔ᮪ (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    ᮚᮦᮔ᮪ ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    ᮞᮨᮓᮨᮜ ((sym = sym->next) != NULL) {
        u = sym->t;
        sym_push(sym->v & ~SYM_FIELD, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
void gfunc_epilog(void)
{
    out_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
puur_naa_nka gjmp(puur_naa_nka t)
{
    ᮝᮜᮤ out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
void gjmp_addr(puur_naa_nka a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
puur_naa_nka gtst(puur_naa_nka inv, puur_naa_nka t)
{
    puur_naa_nka v, *p, c;

    v = vtop->r & VT_VALMASK;
    ᮚᮦᮔ᮪ (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        switch(c) {
        pak_sa TOK_EQ:
            c = IL_OP_BEQ;
            bha_nga;
        pak_sa TOK_NE:
            c = IL_OP_BNE_UN;
            bha_nga;
        pak_sa TOK_LT:
            c = IL_OP_BLT;
            bha_nga;
        pak_sa TOK_LE:
            c = IL_OP_BLE;
            bha_nga;
        pak_sa TOK_GT:
            c = IL_OP_BGT;
            bha_nga;
        pak_sa TOK_GE:
            c = IL_OP_BGE;
            bha_nga;
        pak_sa TOK_ULT:
            c = IL_OP_BLT_UN;
            bha_nga;
        pak_sa TOK_ULE:
            c = IL_OP_BLE_UN;
            bha_nga;
        pak_sa TOK_UGT:
            c = IL_OP_BGT_UN;
            bha_nga;
        pak_sa TOK_UGE:
            c = IL_OP_BGE_UN;
            bha_nga;
        }
        t = out_opj(c, t);
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        ᮚᮦᮔ᮪ ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            ᮞᮨᮓᮨᮜ (*p != 0)
                p = (puur_naa_nka *)*p;
            *p = t;
            t = vtop->c.i;
        } ᮜᮤᮚ {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    ᮝᮜᮤ t;
}

/* generate an integer binary operation */
void gen_opi(puur_naa_nka op)
{
    gv2(RC_ST1, RC_ST0);
    switch(op) {
    pak_sa '+':
        out_op(IL_OP_ADD);
        goto std_op;
    pak_sa '-':
        out_op(IL_OP_SUB);
        goto std_op;
    pak_sa '&':
        out_op(IL_OP_AND);
        goto std_op;
    pak_sa '^':
        out_op(IL_OP_XOR);
        goto std_op;
    pak_sa '|':
        out_op(IL_OP_OR);
        goto std_op;
    pak_sa '*':
        out_op(IL_OP_MUL);
        goto std_op;
    pak_sa TOK_SHL:
        out_op(IL_OP_SHL);
        goto std_op;
    pak_sa TOK_SHR:
        out_op(IL_OP_SHR_UN);
        goto std_op;
    pak_sa TOK_SAR:
        out_op(IL_OP_SHR);
        goto std_op;
    pak_sa '/':
    pak_sa TOK_PDIV:
        out_op(IL_OP_DIV);
        goto std_op;
    pak_sa TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        goto std_op;
    pak_sa '%':
        out_op(IL_OP_REM);
        goto std_op;
    pak_sa TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        bha_nga;
    pak_sa TOK_EQ:
    pak_sa TOK_NE:
    pak_sa TOK_LT:
    pak_sa TOK_LE:
    pak_sa TOK_GT:
    pak_sa TOK_GE:
    pak_sa TOK_ULT:
    pak_sa TOK_ULE:
    pak_sa TOK_UGT:
    pak_sa TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        bha_nga;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
void gen_opf(puur_naa_nka op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
void gen_cvt_itof(puur_naa_nka t)
{
    gv(RC_ST0);
    ᮚᮦᮔ᮪ (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    ᮜᮤᮚ
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
void gen_cvt_ftoi(puur_naa_nka t)
{
    gv(RC_ST0);
    switch(t) {
    pak_sa VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        bha_nga;
    pak_sa VT_LLONG:
        out_op(IL_OP_CONV_I8);
        bha_nga;
    pak_sa VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        bha_nga;
    default:
        out_op(IL_OP_CONV_I4);
        bha_nga;
    }
}

/* convert from one floating point type to another */
void gen_cvt_ftof(puur_naa_nka t)
{
    gv(RC_ST0);
    ᮚᮦᮔ᮪ (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } ᮜᮤᮚ {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

