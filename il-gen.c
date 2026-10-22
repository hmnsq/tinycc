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
enum {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

const 정수 reg_classes[NB_REGS] = {
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
typedef struct GFuncContext {
    정수 func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#define IL_OP_PREFIX 0xFE

enum ILOPCodes {
#define OP(name, str, n) IL_OP_ ## name = n,
#include "il-opcodes.h"
#undef OP
};

char *il_opcodes_str[] = {
#define OP(name, str, n) [n] = str,
#include "il-opcodes.h"
#undef OP
};

/******************************************************/

/* arguments variable numbers start from there */
#define ARG_BASE 0x70000000

static FILE *il_outfile;

static void out_byte(정수 c)
{
    *(char *)ind++ = c;
}

static void out_le32(정수 c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

static void init_outfile(void)
{
    만약 (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

static void out_op1(정수 op)
{
    만약 (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
static void out_op(정수 op)
{
    out_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

static void out_opb(정수 op, 정수 c)
{
    out_op1(op);
    out_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

static void out_opi(정수 op, 정수 c)
{
    out_op1(op);
    out_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
static void il_type_to_str(char *buf, 정수 buf_size, 
                           정수 t, const char *varstr)
{
    정수 bt;
    Sym *s, *sa;
    char buf1[256];
    const char *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    만약 (t & VT_UNSIGNED)
        pstrcat(buf, buf_size, "unsigned ");
    switch(bt) {
    case VT_VOID:
        tstr = "void";
        goto add_tstr;
    case VT_BOOL:
        tstr = "bool";
        goto add_tstr;
    case VT_BYTE:
        tstr = "int8";
        goto add_tstr;
    case VT_SHORT:
        tstr = "int16";
        goto add_tstr;
    case VT_ENUM:
    case VT_INT:
    case VT_LONG:
        tstr = "int32";
        goto add_tstr;
    case VT_LLONG:
        tstr = "int64";
        goto add_tstr;
    case VT_FLOAT:
        tstr = "float32";
        goto add_tstr;
    case VT_DOUBLE:
    case VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        break;
    case VT_STRUCT:
        tcc_error("structures not handled yet");
        break;
    case VT_FUNC:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_size, s->t, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        동안 (sa != NULL) {
            il_type_to_str(buf1, sizeof(buf1), sa->t, NULL);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            만약 (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        goto no_var;
    case VT_PTR:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, sizeof(buf1), "*");
        만약 (varstr)
            pstrcat(buf1, sizeof(buf1), varstr);
        il_type_to_str(buf, buf_size, s->t, buf1);
        goto no_var;
    }
    만약 (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
void greloc_patch1(Reloc *p, 정수 val)
{
}

/* output a symbol and patch all calls to it */
void gsym_addr(t, a)
{
}

/* output jump and return symbol */
static 정수 out_opj(정수 op, 정수 c)
{
    out_op1(op);
    out_le32(0);
    만약 (c == 0) {
        c = ind - (정수)cur_text_section->data;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    반환 c;
}

void gsym(정수 t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
void load(정수 r, SValue *sv)
{
    정수 v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    만약 (sv->r & VT_LVAL) {
        만약 (v == VT_LOCAL) {
            만약 (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                만약 (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } 아니면 만약 (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } 아니면 {
                    out_opi(IL_OP_LDARG, fc);
                }
            } 아니면 {
                만약 (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } 아니면 만약 (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } 아니면 {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } 아니면 만약 (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } 아니면 {
            만약 ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } 아니면 만약 ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } 아니면 만약 ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } 아니면 만약 ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            아니면 만약 ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            아니면 만약 ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            아니면 만약 ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            아니면
                out_op(IL_OP_LDIND_I4);
        } 
    } 아니면 {
        만약 (v == VT_CONST) {
            /* XXX: handle globals */
            만약 (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } 아니면 {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } 아니면 만약 (v == VT_LOCAL) {
            만약 (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                만약 (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } 아니면 {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } 아니면 {
                만약 (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } 아니면 {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } 아니면 {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
void store(정수 r, SValue *sv)
{
    정수 v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    만약 (v == VT_LOCAL) {
        만약 (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            만약 (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } 아니면 {
                out_opi(IL_OP_STARG, fc);
            }
        } 아니면 {
            만약 (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } 아니면 만약 (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } 아니면 {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } 아니면 만약 (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } 아니면 {
        만약 ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        아니면 만약 ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        아니면 만약 ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        아니면 만약 ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        아니면 만약 ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        아니면
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
void gfunc_start(GFuncContext *c, 정수 func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
void gfunc_param(GFuncContext *c)
{
    만약 ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } 아니면 {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
void gfunc_call(GFuncContext *c)
{
    char buf[1024];

    만약 ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, sizeof(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } 아니면 {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, sizeof(buf), vtop->t, NULL);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
void gfunc_prolog(정수 t)
{
    정수 addr, u, func_call;
    Sym *sym;
    char buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, sizeof(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    만약 (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    만약 ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    동안 ((sym = sym->next) != NULL) {
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
정수 gjmp(정수 t)
{
    반환 out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
void gjmp_addr(정수 a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
정수 gtst(정수 inv, 정수 t)
{
    정수 v, *p, c;

    v = vtop->r & VT_VALMASK;
    만약 (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        switch(c) {
        case TOK_EQ:
            c = IL_OP_BEQ;
            break;
        case TOK_NE:
            c = IL_OP_BNE_UN;
            break;
        case TOK_LT:
            c = IL_OP_BLT;
            break;
        case TOK_LE:
            c = IL_OP_BLE;
            break;
        case TOK_GT:
            c = IL_OP_BGT;
            break;
        case TOK_GE:
            c = IL_OP_BGE;
            break;
        case TOK_ULT:
            c = IL_OP_BLT_UN;
            break;
        case TOK_ULE:
            c = IL_OP_BLE_UN;
            break;
        case TOK_UGT:
            c = IL_OP_BGT_UN;
            break;
        case TOK_UGE:
            c = IL_OP_BGE_UN;
            break;
        }
        t = out_opj(c, t);
    } 아니면 만약 (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        만약 ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            동안 (*p != 0)
                p = (정수 *)*p;
            *p = t;
            t = vtop->c.i;
        } 아니면 {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    반환 t;
}

/* generate an integer binary operation */
void gen_opi(정수 op)
{
    gv2(RC_ST1, RC_ST0);
    switch(op) {
    case '+':
        out_op(IL_OP_ADD);
        goto std_op;
    case '-':
        out_op(IL_OP_SUB);
        goto std_op;
    case '&':
        out_op(IL_OP_AND);
        goto std_op;
    case '^':
        out_op(IL_OP_XOR);
        goto std_op;
    case '|':
        out_op(IL_OP_OR);
        goto std_op;
    case '*':
        out_op(IL_OP_MUL);
        goto std_op;
    case TOK_SHL:
        out_op(IL_OP_SHL);
        goto std_op;
    case TOK_SHR:
        out_op(IL_OP_SHR_UN);
        goto std_op;
    case TOK_SAR:
        out_op(IL_OP_SHR);
        goto std_op;
    case '/':
    case TOK_PDIV:
        out_op(IL_OP_DIV);
        goto std_op;
    case TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        goto std_op;
    case '%':
        out_op(IL_OP_REM);
        goto std_op;
    case TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        break;
    case TOK_EQ:
    case TOK_NE:
    case TOK_LT:
    case TOK_LE:
    case TOK_GT:
    case TOK_GE:
    case TOK_ULT:
    case TOK_ULE:
    case TOK_UGT:
    case TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        break;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
void gen_opf(정수 op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
void gen_cvt_itof(정수 t)
{
    gv(RC_ST0);
    만약 (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    아니면
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
void gen_cvt_ftoi(정수 t)
{
    gv(RC_ST0);
    switch(t) {
    case VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        break;
    case VT_LLONG:
        out_op(IL_OP_CONV_I8);
        break;
    case VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        break;
    default:
        out_op(IL_OP_CONV_I4);
        break;
    }
}

/* convert from one floating point type to another */
void gen_cvt_ftof(정수 t)
{
    gv(RC_ST0);
    만약 (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } 아니면 {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

