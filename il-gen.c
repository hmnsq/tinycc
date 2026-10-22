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
ಗಣನಾ {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ reg_classes[NB_REGS] = {
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
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ GFuncContext {
    ಪೂರ್ಣಾಙ್ಕ func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#define IL_OP_PREFIX 0xFE

ಗಣನಾ ILOPCodes {
#define OP(name, str, n) IL_OP_ ## name = n,
#ಅನ್ತರ್ಭಾವ "il-opcodes.h"
#undef OP
};

ವರ್ಣ *il_opcodes_str[] = {
#define OP(name, str, n) [n] = str,
#ಅನ್ತರ್ಭಾವ "il-opcodes.h"
#undef OP
};

/******************************************************/

/* arguments variable numbers start from there */
#define ARG_BASE 0x70000000

ಸ್ಥಿರ FILE *il_outfile;

ಸ್ಥಿರ ಶೂನ್ಯ out_byte(ಪೂರ್ಣಾಙ್ಕ c)
{
    *(ವರ್ಣ *)ind++ = c;
}

ಸ್ಥಿರ ಶೂನ್ಯ out_le32(ಪೂರ್ಣಾಙ್ಕ c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

ಸ್ಥಿರ ಶೂನ್ಯ init_outfile(ಶೂನ್ಯ)
{
    ಯದಿ (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ out_op1(ಪೂರ್ಣಾಙ್ಕ op)
{
    ಯದಿ (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
ಸ್ಥಿರ ಶೂನ್ಯ out_op(ಪೂರ್ಣಾಙ್ಕ op)
{
    out_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

ಸ್ಥಿರ ಶೂನ್ಯ out_opb(ಪೂರ್ಣಾಙ್ಕ op, ಪೂರ್ಣಾಙ್ಕ c)
{
    out_op1(op);
    out_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

ಸ್ಥಿರ ಶೂನ್ಯ out_opi(ಪೂರ್ಣಾಙ್ಕ op, ಪೂರ್ಣಾಙ್ಕ c)
{
    out_op1(op);
    out_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
ಸ್ಥಿರ ಶೂನ್ಯ il_type_to_str(ವರ್ಣ *buf, ಪೂರ್ಣಾಙ್ಕ buf_size, 
                           ಪೂರ್ಣಾಙ್ಕ t, ಧ್ರುವ ವರ್ಣ *varstr)
{
    ಪೂರ್ಣಾಙ್ಕ bt;
    Sym *s, *sa;
    ವರ್ಣ buf1[256];
    ಧ್ರುವ ವರ್ಣ *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    ಯದಿ (t & VT_UNSIGNED)
        pstrcat(buf, buf_size, "unsigned ");
    ವಿಕಲ್ಪ(bt) {
    ಪಕ್ಷ VT_VOID:
        tstr = "void";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_BOOL:
        tstr = "bool";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_BYTE:
        tstr = "int8";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_SHORT:
        tstr = "int16";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_ENUM:
    ಪಕ್ಷ VT_INT:
    ಪಕ್ಷ VT_LONG:
        tstr = "int32";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_LLONG:
        tstr = "int64";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_FLOAT:
        tstr = "float32";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_DOUBLE:
    ಪಕ್ಷ VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        ಭಙ್ಗ;
    ಪಕ್ಷ VT_STRUCT:
        tcc_error("structures not handled yet");
        ಭಙ್ಗ;
    ಪಕ್ಷ VT_FUNC:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_size, s->t, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        ಯಾವತ್ (sa != ರಿಕ್ತ) {
            il_type_to_str(buf1, ಪರಿಮಾಣ(buf1), sa->t, ರಿಕ್ತ);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            ಯದಿ (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        ಗಚ್ಛ no_var;
    ಪಕ್ಷ VT_PTR:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, ಪರಿಮಾಣ(buf1), "*");
        ಯದಿ (varstr)
            pstrcat(buf1, ಪರಿಮಾಣ(buf1), varstr);
        il_type_to_str(buf, buf_size, s->t, buf1);
        ಗಚ್ಛ no_var;
    }
    ಯದಿ (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
ಶೂನ್ಯ greloc_patch1(Reloc *p, ಪೂರ್ಣಾಙ್ಕ val)
{
}

/* output a symbol and patch all calls to it */
ಶೂನ್ಯ gsym_addr(t, a)
{
}

/* output jump and return symbol */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ out_opj(ಪೂರ್ಣಾಙ್ಕ op, ಪೂರ್ಣಾಙ್ಕ c)
{
    out_op1(op);
    out_le32(0);
    ಯದಿ (c == 0) {
        c = ind - (ಪೂರ್ಣಾಙ್ಕ)cur_text_section->data;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    ಪ್ರತ್ಯಾಗಮ c;
}

ಶೂನ್ಯ gsym(ಪೂರ್ಣಾಙ್ಕ t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
ಶೂನ್ಯ load(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    ಯದಿ (sv->r & VT_LVAL) {
        ಯದಿ (v == VT_LOCAL) {
            ಯದಿ (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                ಯದಿ (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } ಅನ್ಯಥಾ ಯದಿ (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } ಅನ್ಯಥಾ {
                    out_opi(IL_OP_LDARG, fc);
                }
            } ಅನ್ಯಥಾ {
                ಯದಿ (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } ಅನ್ಯಥಾ ಯದಿ (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } ಅನ್ಯಥಾ {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } ಅನ್ಯಥಾ ಯದಿ (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } ಅನ್ಯಥಾ {
            ಯದಿ ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } ಅನ್ಯಥಾ ಯದಿ ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } ಅನ್ಯಥಾ ಯದಿ ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } ಅನ್ಯಥಾ ಯದಿ ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            ಅನ್ಯಥಾ ಯದಿ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            ಅನ್ಯಥಾ ಯದಿ ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            ಅನ್ಯಥಾ ಯದಿ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            ಅನ್ಯಥಾ
                out_op(IL_OP_LDIND_I4);
        } 
    } ಅನ್ಯಥಾ {
        ಯದಿ (v == VT_CONST) {
            /* XXX: handle globals */
            ಯದಿ (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } ಅನ್ಯಥಾ {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } ಅನ್ಯಥಾ ಯದಿ (v == VT_LOCAL) {
            ಯದಿ (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                ಯದಿ (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } ಅನ್ಯಥಾ {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } ಅನ್ಯಥಾ {
                ಯದಿ (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } ಅನ್ಯಥಾ {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } ಅನ್ಯಥಾ {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ಶೂನ್ಯ store(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    ಯದಿ (v == VT_LOCAL) {
        ಯದಿ (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            ಯದಿ (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } ಅನ್ಯಥಾ {
                out_opi(IL_OP_STARG, fc);
            }
        } ಅನ್ಯಥಾ {
            ಯದಿ (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } ಅನ್ಯಥಾ ಯದಿ (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } ಅನ್ಯಥಾ {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } ಅನ್ಯಥಾ ಯದಿ (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } ಅನ್ಯಥಾ {
        ಯದಿ ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        ಅನ್ಯಥಾ ಯದಿ ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        ಅನ್ಯಥಾ ಯದಿ ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        ಅನ್ಯಥಾ ಯದಿ ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        ಅನ್ಯಥಾ ಯದಿ ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        ಅನ್ಯಥಾ
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
ಶೂನ್ಯ gfunc_start(GFuncContext *c, ಪೂರ್ಣಾಙ್ಕ func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
ಶೂನ್ಯ gfunc_param(GFuncContext *c)
{
    ಯದಿ ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } ಅನ್ಯಥಾ {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
ಶೂನ್ಯ gfunc_call(GFuncContext *c)
{
    ವರ್ಣ buf[1024];

    ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, ಪರಿಮಾಣ(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } ಅನ್ಯಥಾ {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, ಪರಿಮಾಣ(buf), vtop->t, ರಿಕ್ತ);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
ಶೂನ್ಯ gfunc_prolog(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ addr, u, func_call;
    Sym *sym;
    ವರ್ಣ buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, ಪರಿಮಾಣ(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    ಯದಿ (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    ಯದಿ ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    ಯಾವತ್ ((sym = sym->next) != ರಿಕ್ತ) {
        u = sym->t;
        sym_ತಳ್ಳು(sym->v & ~SYM_FIELD, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
    out_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
ಪೂರ್ಣಾಙ್ಕ gjmp(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪ್ರತ್ಯಾಗಮ out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಙ್ಕ a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
ಪೂರ್ಣಾಙ್ಕ gtst(ಪೂರ್ಣಾಙ್ಕ inv, ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ v, *p, c;

    v = vtop->r & VT_VALMASK;
    ಯದಿ (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        ವಿಕಲ್ಪ(c) {
        ಪಕ್ಷ TOK_EQ:
            c = IL_OP_BEQ;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_NE:
            c = IL_OP_BNE_UN;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_LT:
            c = IL_OP_BLT;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_LE:
            c = IL_OP_BLE;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_GT:
            c = IL_OP_BGT;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_GE:
            c = IL_OP_BGE;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ULT:
            c = IL_OP_BLT_UN;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ULE:
            c = IL_OP_BLE_UN;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_UGT:
            c = IL_OP_BGT_UN;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_UGE:
            c = IL_OP_BGE_UN;
            ಭಙ್ಗ;
        }
        t = out_opj(c, t);
    } ಅನ್ಯಥಾ ಯದಿ (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        ಯದಿ ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            ಯಾವತ್ (*p != 0)
                p = (ಪೂರ್ಣಾಙ್ಕ *)*p;
            *p = t;
            t = vtop->c.i;
        } ಅನ್ಯಥಾ {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    ಪ್ರತ್ಯಾಗಮ t;
}

/* generate an integer binary operation */
ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಙ್ಕ op)
{
    gv2(RC_ST1, RC_ST0);
    ವಿಕಲ್ಪ(op) {
    ಪಕ್ಷ '+':
        out_op(IL_OP_ADD);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ '-':
        out_op(IL_OP_SUB);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ '&':
        out_op(IL_OP_AND);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ '^':
        out_op(IL_OP_XOR);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ '|':
        out_op(IL_OP_OR);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ '*':
        out_op(IL_OP_MUL);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ TOK_SHL:
        out_op(IL_OP_SHL);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ TOK_SHR:
        out_op(IL_OP_SHR_UN);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ TOK_SAR:
        out_op(IL_OP_SHR);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ '/':
    ಪಕ್ಷ TOK_PDIV:
        out_op(IL_OP_DIV);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ '%':
        out_op(IL_OP_REM);
        ಗಚ್ಛ std_op;
    ಪಕ್ಷ TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_EQ:
    ಪಕ್ಷ TOK_NE:
    ಪಕ್ಷ TOK_LT:
    ಪಕ್ಷ TOK_LE:
    ಪಕ್ಷ TOK_GT:
    ಪಕ್ಷ TOK_GE:
    ಪಕ್ಷ TOK_ULT:
    ಪಕ್ಷ TOK_ULE:
    ಪಕ್ಷ TOK_UGT:
    ಪಕ್ಷ TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        ಭಙ್ಗ;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಙ್ಕ op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಙ್ಕ t)
{
    gv(RC_ST0);
    ಯದಿ (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    ಅನ್ಯಥಾ
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಙ್ಕ t)
{
    gv(RC_ST0);
    ವಿಕಲ್ಪ(t) {
    ಪಕ್ಷ VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        ಭಙ್ಗ;
    ಪಕ್ಷ VT_LLONG:
        out_op(IL_OP_CONV_I8);
        ಭಙ್ಗ;
    ಪಕ್ಷ VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        out_op(IL_OP_CONV_I4);
        ಭಙ್ಗ;
    }
}

/* convert from one floating point type to another */
ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಙ್ಕ t)
{
    gv(RC_ST0);
    ಯದಿ (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } ಅನ್ಯಥಾ {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

