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

#ದೋಷ this ಸಂಕೇತ_2 has ಬಿಟ್-rotted since 2003

/* number of available registers */
#ವ್ಯಾಖ್ಯಾನಿಸು NB_REGS             3

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_ST      0x0001  /* any stack entry */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_ST0     0x0002  /* top of stack */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_ST1     0x0004  /* top - 1 */

#ವ್ಯಾಖ್ಯಾನಿಸು RC_INT     RC_ST
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FLOAT   RC_ST
#ವ್ಯಾಖ್ಯಾನಿಸು RC_IRET    RC_ST0 /* function return: integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_LRET    RC_ST0 /* function return: second integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
ಎಣಿಕೆ {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ reg_classes[NB_REGS] = {
    /* ST0 */ RC_ST | RC_ST0,
    /* ST1 */ RC_ST | RC_ST1,
    /* ST2 */ RC_ST,
};

/* return registers for function */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_IRET REG_ST0 /* single word int return register */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_LRET REG_ST0 /* second word return register (for long long) */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_FRET REG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
/* #define INVERT_FUNC_PARAMS */

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#ವ್ಯಾಖ್ಯಾನಿಸು PTR_ಗಾತ್ರ 4

/* long double size and alignment, in bytes */
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ಗಾತ್ರ  8
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ALIGN 8

/* function call context */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ GFuncContext {
    ಪೂರ್ಣಾಂಕ func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#ವ್ಯಾಖ್ಯಾನಿಸು IL_OP_ಪೂರ್ವಪ್ರತ್ಯಯ 0xFE

ಎಣಿಕೆ ILOPCodes {
#ವ್ಯಾಖ್ಯಾನಿಸು OP(name, str, n) IL_OP_ ## name = n,
#ಅನ್ತರ್ಭಾವ "il-opcodes.h"
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು OP
};

ಅಕ್ಷರ *il_opcodes_str[] = {
#ವ್ಯಾಖ್ಯಾನಿಸು OP(name, str, n) [n] = str,
#ಅನ್ತರ್ಭಾವ "il-opcodes.h"
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು OP
};

/******************************************************/

/* arguments variable numbers start from there */
#ವ್ಯಾಖ್ಯಾನಿಸು ARG_ತಳ 0x70000000

ಸ್ಥಿರ FILE *il_outfile;

ಸ್ಥಿರ ಶೂನ್ಯ ಹೊರಹೋಗು_byte(ಪೂರ್ಣಾಂಕ c)
{
    *(ಅಕ್ಷರ *)ind++ = c;
}

ಸ್ಥಿರ ಶೂನ್ಯ ಹೊರಹೋಗು_le32(ಪೂರ್ಣಾಂಕ c)
{
    ಹೊರಹೋಗು_byte(c);
    ಹೊರಹೋಗು_byte(c >> 8);
    ಹೊರಹೋಗು_byte(c >> 16);
    ಹೊರಹೋಗು_byte(c >> 24);
}

ಸ್ಥಿರ ಶೂನ್ಯ init_outfile(ಶೂನ್ಯ)
{
    ಆದರೆ (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಹೊರಹೋಗು_op1(ಪೂರ್ಣಾಂಕ op)
{
    ಆದರೆ (op & 0x100)
        ಹೊರಹೋಗು_byte(IL_OP_ಪೂರ್ವಪ್ರತ್ಯಯ);
    ಹೊರಹೋಗು_byte(op & 0xff);
}

/* output an opcode with prefix */
ಸ್ಥಿರ ಶೂನ್ಯ ಹೊರಹೋಗು_op(ಪೂರ್ಣಾಂಕ op)
{
    ಹೊರಹೋಗು_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

ಸ್ಥಿರ ಶೂನ್ಯ ಹೊರಹೋಗು_opb(ಪೂರ್ಣಾಂಕ op, ಪೂರ್ಣಾಂಕ c)
{
    ಹೊರಹೋಗು_op1(op);
    ಹೊರಹೋಗು_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

ಸ್ಥಿರ ಶೂನ್ಯ ಹೊರಹೋಗು_opi(ಪೂರ್ಣಾಂಕ op, ಪೂರ್ಣಾಂಕ c)
{
    ಹೊರಹೋಗು_op1(op);
    ಹೊರಹೋಗು_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
ಸ್ಥಿರ ಶೂನ್ಯ il_type_ಗಮ್ಯ_str(ಅಕ್ಷರ *buf, ಪೂರ್ಣಾಂಕ buf_ಗಾತ್ರ, 
                           ಪೂರ್ಣಾಂಕ t, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *varstr)
{
    ಪೂರ್ಣಾಂಕ bt;
    Sym *s, *sa;
    ಅಕ್ಷರ buf1[256];
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    ಆದರೆ (t & VT_UNSIGNED)
        pstrcat(buf, buf_ಗಾತ್ರ, "unsigned ");
    ಆಯ್ಕೆ(bt) {
    ಸ್ಥಿತಿ VT_VOID:
        tstr = "void";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_BOOL:
        tstr = "bool";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_BYTE:
        tstr = "int8";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_SHORT:
        tstr = "int16";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_ENUM:
    ಸ್ಥಿತಿ VT_INT:
    ಸ್ಥಿತಿ VT_LONG:
        tstr = "int32";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_LLONG:
        tstr = "int64";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_FLOAT:
        tstr = "float32";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_DOUBLE:
    ಸ್ಥಿತಿ VT_LDOUBLE:
        tstr = "float64";
    ಕೂಡಿಸು_tstr:
        pstrcat(buf, buf_ಗಾತ್ರ, tstr);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ VT_STRUCT:
        tcc_error("structures not handled yet");
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ VT_FUNC:
        s = sym_ಕಂಡುಹಿಡಿ((ಚಿಹ್ನೆರಹಿತ)t >> VT_STRUCT_ಸರಿಸು);
        il_type_ಗಮ್ಯ_str(buf, buf_ಗಾತ್ರ, s->t, varstr);
        pstrcat(buf, buf_ಗಾತ್ರ, "(");
        sa = s->ಮುಂದಿನ;
        ಆಗ (sa != ಖಾಲಿ) {
            il_type_ಗಮ್ಯ_str(buf1, ಗಾತ್ರ(buf1), sa->t, ಖಾಲಿ);
            pstrcat(buf, buf_ಗಾತ್ರ, buf1);
            sa = sa->ಮುಂದಿನ;
            ಆದರೆ (sa)
                pstrcat(buf, buf_ಗಾತ್ರ, ", ");
        }
        pstrcat(buf, buf_ಗಾತ್ರ, ")");
        ಹೋಗು no_var;
    ಸ್ಥಿತಿ VT_PTR:
        s = sym_ಕಂಡುಹಿಡಿ((ಚಿಹ್ನೆರಹಿತ)t >> VT_STRUCT_ಸರಿಸು);
        pstrcpy(buf1, ಗಾತ್ರ(buf1), "*");
        ಆದರೆ (varstr)
            pstrcat(buf1, ಗಾತ್ರ(buf1), varstr);
        il_type_ಗಮ್ಯ_str(buf, buf_ಗಾತ್ರ, s->t, buf1);
        ಹೋಗು no_var;
    }
    ಆದರೆ (varstr) {
        pstrcat(buf, buf_ಗಾತ್ರ, " ");
        pstrcat(buf, buf_ಗಾತ್ರ, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
ಶೂನ್ಯ greloc_patch1(Reloc *p, ಪೂರ್ಣಾಂಕ val)
{
}

/* output a symbol and patch all calls to it */
ಶೂನ್ಯ gsym_addr(t, a)
{
}

/* output jump and return symbol */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಹೊರಹೋಗು_opj(ಪೂರ್ಣಾಂಕ op, ಪೂರ್ಣಾಂಕ c)
{
    ಹೊರಹೋಗು_op1(op);
    ಹೊರಹೋಗು_le32(0);
    ಆದರೆ (c == 0) {
        c = ind - (ಪೂರ್ಣಾಂಕ)cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    ಹಿಂತಿರುಗಿ c;
}

ಶೂನ್ಯ gsym(ಪೂರ್ಣಾಂಕ t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
ಶೂನ್ಯ ತುಂಬು(ಪೂರ್ಣಾಂಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಂಕ v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    ಆದರೆ (sv->r & VT_LVAL) {
        ಆದರೆ (v == VT_LOCAL) {
            ಆದರೆ (fc >= ARG_ತಳ) {
                fc -= ARG_ತಳ;
                ಆದರೆ (fc >= 0 && fc <= 4) {
                    ಹೊರಹೋಗು_op(IL_OP_LDARG_0 + fc);
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (fc <= 0xff) {
                    ಹೊರಹೋಗು_opb(IL_OP_LDARG_S, fc);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ಹೊರಹೋಗು_opi(IL_OP_LDARG, fc);
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ (fc >= 0 && fc <= 4) {
                    ಹೊರಹೋಗು_op(IL_OP_LDLOC_0 + fc);
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (fc <= 0xff) {
                    ಹೊರಹೋಗು_opb(IL_OP_LDLOC_S, fc);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ಹೊರಹೋಗು_opi(IL_OP_LDLOC, fc);
                }
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_CONST) {
                /* XXX: handle globals */
                ಹೊರಹೋಗು_opi(IL_OP_LDSFLD, 0);
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ ((ft & VT_BTYPE) == VT_FLOAT) {
                ಹೊರಹೋಗು_op(IL_OP_LDIND_R4);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_DOUBLE) {
                ಹೊರಹೋಗು_op(IL_OP_LDIND_R8);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_LDOUBLE) {
                ಹೊರಹೋಗು_op(IL_OP_LDIND_R8);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == VT_BYTE)
                ಹೊರಹೋಗು_op(IL_OP_LDIND_I1);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                ಹೊರಹೋಗು_op(IL_OP_LDIND_U1);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == VT_SHORT)
                ಹೊರಹೋಗು_op(IL_OP_LDIND_I2);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                ಹೊರಹೋಗು_op(IL_OP_LDIND_U2);
            ಇಲ್ಲದಿದ್ದರೆ
                ಹೊರಹೋಗು_op(IL_OP_LDIND_I4);
        } 
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (v == VT_CONST) {
            /* XXX: handle globals */
            ಆದರೆ (fc >= -1 && fc <= 8) {
                ಹೊರಹೋಗು_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಹೊರಹೋಗು_opi(IL_OP_LDC_I4, fc);
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_LOCAL) {
            ಆದರೆ (fc >= ARG_ತಳ) {
                fc -= ARG_ತಳ;
                ಆದರೆ (fc <= 0xff) {
                    ಹೊರಹೋಗು_opb(IL_OP_LDARGA_S, fc);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ಹೊರಹೋಗು_opi(IL_OP_LDARGA, fc);
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ (fc <= 0xff) {
                    ಹೊರಹೋಗು_opb(IL_OP_LDLOCA_S, fc);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ಹೊರಹೋಗು_opi(IL_OP_LDLOCA, fc);
                }
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ಶೂನ್ಯ store(ಪೂರ್ಣಾಂಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಂಕ v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    ಆದರೆ (v == VT_LOCAL) {
        ಆದರೆ (fc >= ARG_ತಳ) {
            fc -= ARG_ತಳ;
            /* XXX: check IL arg store semantics */
            ಆದರೆ (fc <= 0xff) {
                ಹೊರಹೋಗು_opb(IL_OP_STARG_S, fc);
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಹೊರಹೋಗು_opi(IL_OP_STARG, fc);
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (fc >= 0 && fc <= 4) {
                ಹೊರಹೋಗು_op(IL_OP_STLOC_0 + fc);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (fc <= 0xff) {
                ಹೊರಹೋಗು_opb(IL_OP_STLOC_S, fc);
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಹೊರಹೋಗು_opi(IL_OP_STLOC, fc);
            }
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_CONST) {
        /* XXX: handle globals */
        ಹೊರಹೋಗು_opi(IL_OP_STSFLD, 0);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ ((ft & VT_BTYPE) == VT_FLOAT)
            ಹೊರಹೋಗು_op(IL_OP_STIND_R4);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_DOUBLE)
            ಹೊರಹೋಗು_op(IL_OP_STIND_R8);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_LDOUBLE)
            ಹೊರಹೋಗು_op(IL_OP_STIND_R8);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_BYTE)
            ಹೊರಹೋಗು_op(IL_OP_STIND_I1);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_SHORT)
            ಹೊರಹೋಗು_op(IL_OP_STIND_I2);
        ಇಲ್ಲದಿದ್ದರೆ
            ಹೊರಹೋಗು_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
ಶೂನ್ಯ gfunc_ಆರಂಭ(GFuncContext *c, ಪೂರ್ಣಾಂಕ func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
ಶೂನ್ಯ gfunc_param(GFuncContext *c)
{
    ಆದರೆ ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
ಶೂನ್ಯ gfunc_call(GFuncContext *c)
{
    ಅಕ್ಷರ buf[1024];

    ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_ಗಮ್ಯ_str(buf, ಗಾತ್ರ(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* indirect call */
        gv(RC_INT);
        il_type_ಗಮ್ಯ_str(buf, ಗಾತ್ರ(buf), vtop->t, ಖಾಲಿ);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
ಶೂನ್ಯ gfunc_prolog(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ addr, u, func_call;
    Sym *sym;
    ಅಕ್ಷರ buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_ಗಮ್ಯ_str(buf, ಗಾತ್ರ(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    ಆದರೆ (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_ಕಂಡುಹಿಡಿ((ಚಿಹ್ನೆರಹಿತ)t >> VT_STRUCT_ಸರಿಸು);
    func_call = sym->r;

    addr = ARG_ತಳ;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    ಆದರೆ ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    ಆಗ ((sym = sym->ಮುಂದಿನ) != ಖಾಲಿ) {
        u = sym->t;
        sym_ತಳ್ಳು(sym->v & ~SYM_ಕ್ಷೇತ್ರ, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
    ಹೊರಹೋಗು_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
ಪೂರ್ಣಾಂಕ gjmp(ಪೂರ್ಣಾಂಕ t)
{
    ಹಿಂತಿರುಗಿ ಹೊರಹೋಗು_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಂಕ a)
{
    /* XXX: handle syms */
    ಹೊರಹೋಗು_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
ಪೂರ್ಣಾಂಕ gtst(ಪೂರ್ಣಾಂಕ inv, ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ v, *p, c;

    v = vtop->r & VT_VALMASK;
    ಆದರೆ (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        ಆಯ್ಕೆ(c) {
        ಸ್ಥಿತಿ TOK_EQ:
            c = IL_OP_BEQ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_NE:
            c = IL_OP_BNE_UN;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_LT:
            c = IL_OP_BLT;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_LE:
            c = IL_OP_BLE;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_GT:
            c = IL_OP_BGT;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_GE:
            c = IL_OP_BGE;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ULT:
            c = IL_OP_BLT_UN;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ULE:
            c = IL_OP_BLE_UN;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_UGT:
            c = IL_OP_BGT_UN;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_UGE:
            c = IL_OP_BGE_UN;
            ನಿಲ್ಲಿಸು;
        }
        t = ಹೊರಹೋಗು_opj(c, t);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        ಆದರೆ ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            ಆಗ (*p != 0)
                p = (ಪೂರ್ಣಾಂಕ *)*p;
            *p = t;
            t = vtop->c.i;
        } ಇಲ್ಲದಿದ್ದರೆ {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    ಹಿಂತಿರುಗಿ t;
}

/* generate an integer binary operation */
ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಂಕ op)
{
    gv2(RC_ST1, RC_ST0);
    ಆಯ್ಕೆ(op) {
    ಸ್ಥಿತಿ '+':
        ಹೊರಹೋಗು_op(IL_OP_ಕೂಡಿಸು);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ '-':
        ಹೊರಹೋಗು_op(IL_OP_SUB);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ '&':
        ಹೊರಹೋಗು_op(IL_OP_AND);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ '^':
        ಹೊರಹೋಗು_op(IL_OP_XOR);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ '|':
        ಹೊರಹೋಗು_op(IL_OP_OR);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ '*':
        ಹೊರಹೋಗು_op(IL_OP_MUL);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ TOK_SHL:
        ಹೊರಹೋಗು_op(IL_OP_SHL);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ TOK_SHR:
        ಹೊರಹೋಗು_op(IL_OP_SHR_UN);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ TOK_SAR:
        ಹೊರಹೋಗು_op(IL_OP_SHR);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ '/':
    ಸ್ಥಿತಿ TOK_PDIV:
        ಹೊರಹೋಗು_op(IL_OP_DIV);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ TOK_UDIV:
        ಹೊರಹೋಗು_op(IL_OP_DIV_UN);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ '%':
        ಹೊರಹೋಗು_op(IL_OP_REM);
        ಹೋಗು std_op;
    ಸ್ಥಿತಿ TOK_UMOD:
        ಹೊರಹೋಗು_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_EQ:
    ಸ್ಥಿತಿ TOK_NE:
    ಸ್ಥಿತಿ TOK_LT:
    ಸ್ಥಿತಿ TOK_LE:
    ಸ್ಥಿತಿ TOK_GT:
    ಸ್ಥಿತಿ TOK_GE:
    ಸ್ಥಿತಿ TOK_ULT:
    ಸ್ಥಿತಿ TOK_ULE:
    ಸ್ಥಿತಿ TOK_UGT:
    ಸ್ಥಿತಿ TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        ನಿಲ್ಲಿಸು;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಂಕ op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಂಕ t)
{
    gv(RC_ST0);
    ಆದರೆ (t == VT_FLOAT)
        ಹೊರಹೋಗು_op(IL_OP_CONV_R4);
    ಇಲ್ಲದಿದ್ದರೆ
        ಹೊರಹೋಗು_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಂಕ t)
{
    gv(RC_ST0);
    ಆಯ್ಕೆ(t) {
    ಸ್ಥಿತಿ VT_INT | VT_UNSIGNED:
        ಹೊರಹೋಗು_op(IL_OP_CONV_U4);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ VT_LLONG:
        ಹೊರಹೋಗು_op(IL_OP_CONV_I8);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ VT_LLONG | VT_UNSIGNED:
        ಹೊರಹೋಗು_op(IL_OP_CONV_U8);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಹೊರಹೋಗು_op(IL_OP_CONV_I4);
        ನಿಲ್ಲಿಸು;
    }
}

/* convert from one floating point type to another */
ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಂಕ t)
{
    gv(RC_ST0);
    ಆದರೆ (t == VT_FLOAT) {
        ಹೊರಹೋಗು_op(IL_OP_CONV_R4);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಹೊರಹೋಗು_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

