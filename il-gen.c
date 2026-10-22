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

#ਗਲਤੀ this ਕੋਡ has ਦੋਆਧਾਰੀ_ਅੰਕ-rotted since 2003

/* number of available registers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_REGS             3

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_ST      0x0001  /* any stack entry */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_ST0     0x0002  /* top of stack */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_ST1     0x0004  /* top - 1 */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_INT     RC_ST
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FLOAT   RC_ST
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_IRET    RC_ST0 /* function return: integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_LRET    RC_ST0 /* function return: second integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
ਗਿਣਤੀ {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

ਅਚਲ ਪੂਰਨ reg_classes[NB_REGS] = {
    /* ST0 */ RC_ST | RC_ST0,
    /* ST1 */ RC_ST | RC_ST1,
    /* ST2 */ RC_ST,
};

/* return registers for function */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IRET REG_ST0 /* single word int return register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_LRET REG_ST0 /* second word return register (for long long) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_FRET REG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
/* #define INVERT_FUNC_PARAMS */

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTR_ਮਾਪ 4

/* long double size and alignment, in bytes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ਮਾਪ  8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ALIGN 8

/* function call context */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ GFuncContext {
    ਪੂਰਨ func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IL_OP_ਅਗੇਤਰ 0xFE

ਗਿਣਤੀ ILOPCodes {
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP(name, str, n) IL_OP_ ## name = n,
#ਅਨ੍ਤਰ੍ਭਾਵ "il-opcodes.h"
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ OP
};

ਅੱਖਰ *il_opcodes_str[] = {
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP(name, str, n) [n] = str,
#ਅਨ੍ਤਰ੍ਭਾਵ "il-opcodes.h"
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ OP
};

/******************************************************/

/* arguments variable numbers start from there */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARG_ਅਧਾਰ 0x70000000

ਸਥਿਰ FILE *il_outfile;

ਸਥਿਰ ਖਾਲੀ ਬਾਹਰਲਾ_byte(ਪੂਰਨ c)
{
    *(ਅੱਖਰ *)ind++ = c;
}

ਸਥਿਰ ਖਾਲੀ ਬਾਹਰਲਾ_le32(ਪੂਰਨ c)
{
    ਬਾਹਰਲਾ_byte(c);
    ਬਾਹਰਲਾ_byte(c >> 8);
    ਬਾਹਰਲਾ_byte(c >> 16);
    ਬਾਹਰਲਾ_byte(c >> 24);
}

ਸਥਿਰ ਖਾਲੀ init_outfile(ਖਾਲੀ)
{
    ਜੇ (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

ਸਥਿਰ ਖਾਲੀ ਬਾਹਰਲਾ_op1(ਪੂਰਨ op)
{
    ਜੇ (op & 0x100)
        ਬਾਹਰਲਾ_byte(IL_OP_ਅਗੇਤਰ);
    ਬਾਹਰਲਾ_byte(op & 0xff);
}

/* output an opcode with prefix */
ਸਥਿਰ ਖਾਲੀ ਬਾਹਰਲਾ_op(ਪੂਰਨ op)
{
    ਬਾਹਰਲਾ_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

ਸਥਿਰ ਖਾਲੀ ਬਾਹਰਲਾ_opb(ਪੂਰਨ op, ਪੂਰਨ c)
{
    ਬਾਹਰਲਾ_op1(op);
    ਬਾਹਰਲਾ_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

ਸਥਿਰ ਖਾਲੀ ਬਾਹਰਲਾ_opi(ਪੂਰਨ op, ਪੂਰਨ c)
{
    ਬਾਹਰਲਾ_op1(op);
    ਬਾਹਰਲਾ_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
ਸਥਿਰ ਖਾਲੀ il_type_ਮੰਜ਼ਿਲ_str(ਅੱਖਰ *buf, ਪੂਰਨ buf_ਮਾਪ, 
                           ਪੂਰਨ t, ਅਚਲ ਅੱਖਰ *varstr)
{
    ਪੂਰਨ bt;
    Sym *s, *sa;
    ਅੱਖਰ buf1[256];
    ਅਚਲ ਅੱਖਰ *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    ਜੇ (t & VT_UNSIGNED)
        pstrcat(buf, buf_ਮਾਪ, "unsigned ");
    ਚੋਣ(bt) {
    ਹਾਲਤ VT_VOID:
        tstr = "void";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_BOOL:
        tstr = "bool";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_BYTE:
        tstr = "int8";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_SHORT:
        tstr = "int16";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_ENUM:
    ਹਾਲਤ VT_INT:
    ਹਾਲਤ VT_LONG:
        tstr = "int32";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_LLONG:
        tstr = "int64";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_FLOAT:
        tstr = "float32";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_DOUBLE:
    ਹਾਲਤ VT_LDOUBLE:
        tstr = "float64";
    ਜੋੜੋ_tstr:
        pstrcat(buf, buf_ਮਾਪ, tstr);
        ਰੋਕੋ;
    ਹਾਲਤ VT_STRUCT:
        tcc_error("structures not handled yet");
        ਰੋਕੋ;
    ਹਾਲਤ VT_FUNC:
        s = sym_ਲੱਭੋ((ਬਿਨਾਨਿਸ਼ਾਨੀ)t >> VT_STRUCT_ਖਿਸਕਾਓ);
        il_type_ਮੰਜ਼ਿਲ_str(buf, buf_ਮਾਪ, s->t, varstr);
        pstrcat(buf, buf_ਮਾਪ, "(");
        sa = s->ਅਗਲਾ;
        ਜਦੋਂ (sa != ਨਿਰਾ) {
            il_type_ਮੰਜ਼ਿਲ_str(buf1, ਆਕਾਰ(buf1), sa->t, ਨਿਰਾ);
            pstrcat(buf, buf_ਮਾਪ, buf1);
            sa = sa->ਅਗਲਾ;
            ਜੇ (sa)
                pstrcat(buf, buf_ਮਾਪ, ", ");
        }
        pstrcat(buf, buf_ਮਾਪ, ")");
        ਜਾਓ no_var;
    ਹਾਲਤ VT_PTR:
        s = sym_ਲੱਭੋ((ਬਿਨਾਨਿਸ਼ਾਨੀ)t >> VT_STRUCT_ਖਿਸਕਾਓ);
        pstrcpy(buf1, ਆਕਾਰ(buf1), "*");
        ਜੇ (varstr)
            pstrcat(buf1, ਆਕਾਰ(buf1), varstr);
        il_type_ਮੰਜ਼ਿਲ_str(buf, buf_ਮਾਪ, s->t, buf1);
        ਜਾਓ no_var;
    }
    ਜੇ (varstr) {
        pstrcat(buf, buf_ਮਾਪ, " ");
        pstrcat(buf, buf_ਮਾਪ, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
ਖਾਲੀ greloc_patch1(Reloc *p, ਪੂਰਨ val)
{
}

/* output a symbol and patch all calls to it */
ਖਾਲੀ gsym_addr(t, a)
{
}

/* output jump and return symbol */
ਸਥਿਰ ਪੂਰਨ ਬਾਹਰਲਾ_opj(ਪੂਰਨ op, ਪੂਰਨ c)
{
    ਬਾਹਰਲਾ_op1(op);
    ਬਾਹਰਲਾ_le32(0);
    ਜੇ (c == 0) {
        c = ind - (ਪੂਰਨ)cur_ਪਾਠ_section->ਅੰਕੜੇ;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    ਵਾਪਸ c;
}

ਖਾਲੀ gsym(ਪੂਰਨ t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
ਖਾਲੀ ਲੱਦੋ(ਪੂਰਨ r, SValue *sv)
{
    ਪੂਰਨ v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    ਜੇ (sv->r & VT_LVAL) {
        ਜੇ (v == VT_LOCAL) {
            ਜੇ (fc >= ARG_ਅਧਾਰ) {
                fc -= ARG_ਅਧਾਰ;
                ਜੇ (fc >= 0 && fc <= 4) {
                    ਬਾਹਰਲਾ_op(IL_OP_LDARG_0 + fc);
                } ਨਹੀਂਤਾਂ ਜੇ (fc <= 0xff) {
                    ਬਾਹਰਲਾ_opb(IL_OP_LDARG_S, fc);
                } ਨਹੀਂਤਾਂ {
                    ਬਾਹਰਲਾ_opi(IL_OP_LDARG, fc);
                }
            } ਨਹੀਂਤਾਂ {
                ਜੇ (fc >= 0 && fc <= 4) {
                    ਬਾਹਰਲਾ_op(IL_OP_LDLOC_0 + fc);
                } ਨਹੀਂਤਾਂ ਜੇ (fc <= 0xff) {
                    ਬਾਹਰਲਾ_opb(IL_OP_LDLOC_S, fc);
                } ਨਹੀਂਤਾਂ {
                    ਬਾਹਰਲਾ_opi(IL_OP_LDLOC, fc);
                }
            }
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_CONST) {
                /* XXX: handle globals */
                ਬਾਹਰਲਾ_opi(IL_OP_LDSFLD, 0);
        } ਨਹੀਂਤਾਂ {
            ਜੇ ((ft & VT_BTYPE) == VT_FLOAT) {
                ਬਾਹਰਲਾ_op(IL_OP_LDIND_R4);
            } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_DOUBLE) {
                ਬਾਹਰਲਾ_op(IL_OP_LDIND_R8);
            } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_LDOUBLE) {
                ਬਾਹਰਲਾ_op(IL_OP_LDIND_R8);
            } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == VT_BYTE)
                ਬਾਹਰਲਾ_op(IL_OP_LDIND_I1);
            ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                ਬਾਹਰਲਾ_op(IL_OP_LDIND_U1);
            ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == VT_SHORT)
                ਬਾਹਰਲਾ_op(IL_OP_LDIND_I2);
            ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                ਬਾਹਰਲਾ_op(IL_OP_LDIND_U2);
            ਨਹੀਂਤਾਂ
                ਬਾਹਰਲਾ_op(IL_OP_LDIND_I4);
        } 
    } ਨਹੀਂਤਾਂ {
        ਜੇ (v == VT_CONST) {
            /* XXX: handle globals */
            ਜੇ (fc >= -1 && fc <= 8) {
                ਬਾਹਰਲਾ_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } ਨਹੀਂਤਾਂ {
                ਬਾਹਰਲਾ_opi(IL_OP_LDC_I4, fc);
            }
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_LOCAL) {
            ਜੇ (fc >= ARG_ਅਧਾਰ) {
                fc -= ARG_ਅਧਾਰ;
                ਜੇ (fc <= 0xff) {
                    ਬਾਹਰਲਾ_opb(IL_OP_LDARGA_S, fc);
                } ਨਹੀਂਤਾਂ {
                    ਬਾਹਰਲਾ_opi(IL_OP_LDARGA, fc);
                }
            } ਨਹੀਂਤਾਂ {
                ਜੇ (fc <= 0xff) {
                    ਬਾਹਰਲਾ_opb(IL_OP_LDLOCA_S, fc);
                } ਨਹੀਂਤਾਂ {
                    ਬਾਹਰਲਾ_opi(IL_OP_LDLOCA, fc);
                }
            }
        } ਨਹੀਂਤਾਂ {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ਖਾਲੀ store(ਪੂਰਨ r, SValue *sv)
{
    ਪੂਰਨ v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    ਜੇ (v == VT_LOCAL) {
        ਜੇ (fc >= ARG_ਅਧਾਰ) {
            fc -= ARG_ਅਧਾਰ;
            /* XXX: check IL arg store semantics */
            ਜੇ (fc <= 0xff) {
                ਬਾਹਰਲਾ_opb(IL_OP_STARG_S, fc);
            } ਨਹੀਂਤਾਂ {
                ਬਾਹਰਲਾ_opi(IL_OP_STARG, fc);
            }
        } ਨਹੀਂਤਾਂ {
            ਜੇ (fc >= 0 && fc <= 4) {
                ਬਾਹਰਲਾ_op(IL_OP_STLOC_0 + fc);
            } ਨਹੀਂਤਾਂ ਜੇ (fc <= 0xff) {
                ਬਾਹਰਲਾ_opb(IL_OP_STLOC_S, fc);
            } ਨਹੀਂਤਾਂ {
                ਬਾਹਰਲਾ_opi(IL_OP_STLOC, fc);
            }
        }
    } ਨਹੀਂਤਾਂ ਜੇ (v == VT_CONST) {
        /* XXX: handle globals */
        ਬਾਹਰਲਾ_opi(IL_OP_STSFLD, 0);
    } ਨਹੀਂਤਾਂ {
        ਜੇ ((ft & VT_BTYPE) == VT_FLOAT)
            ਬਾਹਰਲਾ_op(IL_OP_STIND_R4);
        ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_DOUBLE)
            ਬਾਹਰਲਾ_op(IL_OP_STIND_R8);
        ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_LDOUBLE)
            ਬਾਹਰਲਾ_op(IL_OP_STIND_R8);
        ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_BYTE)
            ਬਾਹਰਲਾ_op(IL_OP_STIND_I1);
        ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_SHORT)
            ਬਾਹਰਲਾ_op(IL_OP_STIND_I2);
        ਨਹੀਂਤਾਂ
            ਬਾਹਰਲਾ_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
ਖਾਲੀ gfunc_ਸ਼ੁਰੂ(GFuncContext *c, ਪੂਰਨ func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
ਖਾਲੀ gfunc_param(GFuncContext *c)
{
    ਜੇ ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } ਨਹੀਂਤਾਂ {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
ਖਾਲੀ gfunc_call(GFuncContext *c)
{
    ਅੱਖਰ buf[1024];

    ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_ਮੰਜ਼ਿਲ_str(buf, ਆਕਾਰ(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } ਨਹੀਂਤਾਂ {
        /* indirect call */
        gv(RC_INT);
        il_type_ਮੰਜ਼ਿਲ_str(buf, ਆਕਾਰ(buf), vtop->t, ਨਿਰਾ);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
ਖਾਲੀ gfunc_prolog(ਪੂਰਨ t)
{
    ਪੂਰਨ addr, u, func_call;
    Sym *sym;
    ਅੱਖਰ buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_ਮੰਜ਼ਿਲ_str(buf, ਆਕਾਰ(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    ਜੇ (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_ਲੱਭੋ((ਬਿਨਾਨਿਸ਼ਾਨੀ)t >> VT_STRUCT_ਖਿਸਕਾਓ);
    func_call = sym->r;

    addr = ARG_ਅਧਾਰ;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    ਜੇ ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    ਜਦੋਂ ((sym = sym->ਅਗਲਾ) != ਨਿਰਾ) {
        u = sym->t;
        sym_ਧੱਕੋ(sym->v & ~SYM_ਖੇਤਰ, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
ਖਾਲੀ gfunc_epilog(ਖਾਲੀ)
{
    ਬਾਹਰਲਾ_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
ਪੂਰਨ gjmp(ਪੂਰਨ t)
{
    ਵਾਪਸ ਬਾਹਰਲਾ_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
ਖਾਲੀ gjmp_addr(ਪੂਰਨ a)
{
    /* XXX: handle syms */
    ਬਾਹਰਲਾ_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
ਪੂਰਨ gtst(ਪੂਰਨ inv, ਪੂਰਨ t)
{
    ਪੂਰਨ v, *p, c;

    v = vtop->r & VT_VALMASK;
    ਜੇ (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        ਚੋਣ(c) {
        ਹਾਲਤ TOK_EQ:
            c = IL_OP_BEQ;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_NE:
            c = IL_OP_BNE_UN;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_LT:
            c = IL_OP_BLT;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_LE:
            c = IL_OP_BLE;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_GT:
            c = IL_OP_BGT;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_GE:
            c = IL_OP_BGE;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ULT:
            c = IL_OP_BLT_UN;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ULE:
            c = IL_OP_BLE_UN;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_UGT:
            c = IL_OP_BGT_UN;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_UGE:
            c = IL_OP_BGE_UN;
            ਰੋਕੋ;
        }
        t = ਬਾਹਰਲਾ_opj(c, t);
    } ਨਹੀਂਤਾਂ ਜੇ (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        ਜੇ ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            ਜਦੋਂ (*p != 0)
                p = (ਪੂਰਨ *)*p;
            *p = t;
            t = vtop->c.i;
        } ਨਹੀਂਤਾਂ {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    ਵਾਪਸ t;
}

/* generate an integer binary operation */
ਖਾਲੀ gen_opi(ਪੂਰਨ op)
{
    gv2(RC_ST1, RC_ST0);
    ਚੋਣ(op) {
    ਹਾਲਤ '+':
        ਬਾਹਰਲਾ_op(IL_OP_ਜੋੜੋ);
        ਜਾਓ std_op;
    ਹਾਲਤ '-':
        ਬਾਹਰਲਾ_op(IL_OP_SUB);
        ਜਾਓ std_op;
    ਹਾਲਤ '&':
        ਬਾਹਰਲਾ_op(IL_OP_AND);
        ਜਾਓ std_op;
    ਹਾਲਤ '^':
        ਬਾਹਰਲਾ_op(IL_OP_XOR);
        ਜਾਓ std_op;
    ਹਾਲਤ '|':
        ਬਾਹਰਲਾ_op(IL_OP_OR);
        ਜਾਓ std_op;
    ਹਾਲਤ '*':
        ਬਾਹਰਲਾ_op(IL_OP_MUL);
        ਜਾਓ std_op;
    ਹਾਲਤ TOK_SHL:
        ਬਾਹਰਲਾ_op(IL_OP_SHL);
        ਜਾਓ std_op;
    ਹਾਲਤ TOK_SHR:
        ਬਾਹਰਲਾ_op(IL_OP_SHR_UN);
        ਜਾਓ std_op;
    ਹਾਲਤ TOK_SAR:
        ਬਾਹਰਲਾ_op(IL_OP_SHR);
        ਜਾਓ std_op;
    ਹਾਲਤ '/':
    ਹਾਲਤ TOK_PDIV:
        ਬਾਹਰਲਾ_op(IL_OP_DIV);
        ਜਾਓ std_op;
    ਹਾਲਤ TOK_UDIV:
        ਬਾਹਰਲਾ_op(IL_OP_DIV_UN);
        ਜਾਓ std_op;
    ਹਾਲਤ '%':
        ਬਾਹਰਲਾ_op(IL_OP_REM);
        ਜਾਓ std_op;
    ਹਾਲਤ TOK_UMOD:
        ਬਾਹਰਲਾ_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_EQ:
    ਹਾਲਤ TOK_NE:
    ਹਾਲਤ TOK_LT:
    ਹਾਲਤ TOK_LE:
    ਹਾਲਤ TOK_GT:
    ਹਾਲਤ TOK_GE:
    ਹਾਲਤ TOK_ULT:
    ਹਾਲਤ TOK_ULE:
    ਹਾਲਤ TOK_UGT:
    ਹਾਲਤ TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        ਰੋਕੋ;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
ਖਾਲੀ gen_opf(ਪੂਰਨ op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ਖਾਲੀ gen_cvt_itof(ਪੂਰਨ t)
{
    gv(RC_ST0);
    ਜੇ (t == VT_FLOAT)
        ਬਾਹਰਲਾ_op(IL_OP_CONV_R4);
    ਨਹੀਂਤਾਂ
        ਬਾਹਰਲਾ_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
ਖਾਲੀ gen_cvt_ftoi(ਪੂਰਨ t)
{
    gv(RC_ST0);
    ਚੋਣ(t) {
    ਹਾਲਤ VT_INT | VT_UNSIGNED:
        ਬਾਹਰਲਾ_op(IL_OP_CONV_U4);
        ਰੋਕੋ;
    ਹਾਲਤ VT_LLONG:
        ਬਾਹਰਲਾ_op(IL_OP_CONV_I8);
        ਰੋਕੋ;
    ਹਾਲਤ VT_LLONG | VT_UNSIGNED:
        ਬਾਹਰਲਾ_op(IL_OP_CONV_U8);
        ਰੋਕੋ;
    ਮੂਲ:
        ਬਾਹਰਲਾ_op(IL_OP_CONV_I4);
        ਰੋਕੋ;
    }
}

/* convert from one floating point type to another */
ਖਾਲੀ gen_cvt_ftof(ਪੂਰਨ t)
{
    gv(RC_ST0);
    ਜੇ (t == VT_FLOAT) {
        ਬਾਹਰਲਾ_op(IL_OP_CONV_R4);
    } ਨਹੀਂਤਾਂ {
        ਬਾਹਰਲਾ_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

