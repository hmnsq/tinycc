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
എണ്ണൽ {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

സ്ഥിരം പൂർണ്ണസംഖ്യ reg_classes[NB_REGS] = {
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
തരനിർവചനം ഘടന GFuncContext {
    പൂർണ്ണസംഖ്യ func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#define IL_OP_PREFIX 0xFE

എണ്ണൽ ILOPCodes {
#define OP(name, str, n) IL_OP_ ## name = n,
#അന്തര്ഭാവ "il-opcodes.h"
#undef OP
};

അക്ഷരം *il_opcodes_str[] = {
#define OP(name, str, n) [n] = str,
#അന്തര്ഭാവ "il-opcodes.h"
#undef OP
};

/******************************************************/

/* arguments variable numbers start from there */
#define ARG_BASE 0x70000000

സ്ഥിതം FILE *il_outfile;

സ്ഥിതം ശൂന്യം out_byte(പൂർണ്ണസംഖ്യ c)
{
    *(അക്ഷരം *)ind++ = c;
}

സ്ഥിതം ശൂന്യം out_le32(പൂർണ്ണസംഖ്യ c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

സ്ഥിതം ശൂന്യം init_outfile(ശൂന്യം)
{
    എങ്കിൽ (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

സ്ഥിതം ശൂന്യം out_op1(പൂർണ്ണസംഖ്യ op)
{
    എങ്കിൽ (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
സ്ഥിതം ശൂന്യം out_op(പൂർണ്ണസംഖ്യ op)
{
    out_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

സ്ഥിതം ശൂന്യം out_opb(പൂർണ്ണസംഖ്യ op, പൂർണ്ണസംഖ്യ c)
{
    out_op1(op);
    out_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

സ്ഥിതം ശൂന്യം out_opi(പൂർണ്ണസംഖ്യ op, പൂർണ്ണസംഖ്യ c)
{
    out_op1(op);
    out_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
സ്ഥിതം ശൂന്യം il_type_to_str(അക്ഷരം *buf, പൂർണ്ണസംഖ്യ buf_size, 
                           പൂർണ്ണസംഖ്യ t, സ്ഥിരം അക്ഷരം *varstr)
{
    പൂർണ്ണസംഖ്യ bt;
    Sym *s, *sa;
    അക്ഷരം buf1[256];
    സ്ഥിരം അക്ഷരം *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    എങ്കിൽ (t & VT_UNSIGNED)
        pstrcat(buf, buf_size, "unsigned ");
    തിരഞ്ഞെടുപ്പ്(bt) {
    അവസ്ഥ VT_VOID:
        tstr = "void";
        പോകുക add_tstr;
    അവസ്ഥ VT_BOOL:
        tstr = "bool";
        പോകുക add_tstr;
    അവസ്ഥ VT_BYTE:
        tstr = "int8";
        പോകുക add_tstr;
    അവസ്ഥ VT_SHORT:
        tstr = "int16";
        പോകുക add_tstr;
    അവസ്ഥ VT_ENUM:
    അവസ്ഥ VT_INT:
    അവസ്ഥ VT_LONG:
        tstr = "int32";
        പോകുക add_tstr;
    അവസ്ഥ VT_LLONG:
        tstr = "int64";
        പോകുക add_tstr;
    അവസ്ഥ VT_FLOAT:
        tstr = "float32";
        പോകുക add_tstr;
    അവസ്ഥ VT_DOUBLE:
    അവസ്ഥ VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        നിർത്തുക;
    അവസ്ഥ VT_STRUCT:
        tcc_error("structures not handled yet");
        നിർത്തുക;
    അവസ്ഥ VT_FUNC:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_size, s->t, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        ആകുമ്പോൾ (sa != ശൂന്യ) {
            il_type_to_str(buf1, വലുപ്പം(buf1), sa->t, ശൂന്യ);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            എങ്കിൽ (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        പോകുക no_var;
    അവസ്ഥ VT_PTR:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, വലുപ്പം(buf1), "*");
        എങ്കിൽ (varstr)
            pstrcat(buf1, വലുപ്പം(buf1), varstr);
        il_type_to_str(buf, buf_size, s->t, buf1);
        പോകുക no_var;
    }
    എങ്കിൽ (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
ശൂന്യം greloc_patch1(Reloc *p, പൂർണ്ണസംഖ്യ val)
{
}

/* output a symbol and patch all calls to it */
ശൂന്യം gsym_addr(t, a)
{
}

/* output jump and return symbol */
സ്ഥിതം പൂർണ്ണസംഖ്യ out_opj(പൂർണ്ണസംഖ്യ op, പൂർണ്ണസംഖ്യ c)
{
    out_op1(op);
    out_le32(0);
    എങ്കിൽ (c == 0) {
        c = ind - (പൂർണ്ണസംഖ്യ)cur_text_section->data;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    തിരികെ c;
}

ശൂന്യം gsym(പൂർണ്ണസംഖ്യ t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
ശൂന്യം load(പൂർണ്ണസംഖ്യ r, SValue *sv)
{
    പൂർണ്ണസംഖ്യ v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    എങ്കിൽ (sv->r & VT_LVAL) {
        എങ്കിൽ (v == VT_LOCAL) {
            എങ്കിൽ (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                എങ്കിൽ (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } അല്ലെങ്കിൽ എങ്കിൽ (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } അല്ലെങ്കിൽ {
                    out_opi(IL_OP_LDARG, fc);
                }
            } അല്ലെങ്കിൽ {
                എങ്കിൽ (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } അല്ലെങ്കിൽ എങ്കിൽ (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } അല്ലെങ്കിൽ {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } അല്ലെങ്കിൽ {
            എങ്കിൽ ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            അല്ലെങ്കിൽ
                out_op(IL_OP_LDIND_I4);
        } 
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (v == VT_CONST) {
            /* XXX: handle globals */
            എങ്കിൽ (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } അല്ലെങ്കിൽ {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (v == VT_LOCAL) {
            എങ്കിൽ (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                എങ്കിൽ (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } അല്ലെങ്കിൽ {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } അല്ലെങ്കിൽ {
                എങ്കിൽ (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } അല്ലെങ്കിൽ {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } അല്ലെങ്കിൽ {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ശൂന്യം store(പൂർണ്ണസംഖ്യ r, SValue *sv)
{
    പൂർണ്ണസംഖ്യ v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    എങ്കിൽ (v == VT_LOCAL) {
        എങ്കിൽ (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            എങ്കിൽ (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } അല്ലെങ്കിൽ {
                out_opi(IL_OP_STARG, fc);
            }
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } അല്ലെങ്കിൽ എങ്കിൽ (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } അല്ലെങ്കിൽ {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } അല്ലെങ്കിൽ എങ്കിൽ (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } അല്ലെങ്കിൽ {
        എങ്കിൽ ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        അല്ലെങ്കിൽ
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
ശൂന്യം gfunc_start(GFuncContext *c, പൂർണ്ണസംഖ്യ func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
ശൂന്യം gfunc_param(GFuncContext *c)
{
    എങ്കിൽ ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } അല്ലെങ്കിൽ {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
ശൂന്യം gfunc_call(GFuncContext *c)
{
    അക്ഷരം buf[1024];

    എങ്കിൽ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, വലുപ്പം(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } അല്ലെങ്കിൽ {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, വലുപ്പം(buf), vtop->t, ശൂന്യ);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
ശൂന്യം gfunc_prolog(പൂർണ്ണസംഖ്യ t)
{
    പൂർണ്ണസംഖ്യ addr, u, func_call;
    Sym *sym;
    അക്ഷരം buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, വലുപ്പം(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    എങ്കിൽ (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    എങ്കിൽ ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    ആകുമ്പോൾ ((sym = sym->next) != ശൂന്യ) {
        u = sym->t;
        sym_തള്ളുക(sym->v & ~SYM_FIELD, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
ശൂന്യം gfunc_epilog(ശൂന്യം)
{
    out_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
പൂർണ്ണസംഖ്യ gjmp(പൂർണ്ണസംഖ്യ t)
{
    തിരികെ out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
ശൂന്യം gjmp_addr(പൂർണ്ണസംഖ്യ a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
പൂർണ്ണസംഖ്യ gtst(പൂർണ്ണസംഖ്യ inv, പൂർണ്ണസംഖ്യ t)
{
    പൂർണ്ണസംഖ്യ v, *p, c;

    v = vtop->r & VT_VALMASK;
    എങ്കിൽ (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        തിരഞ്ഞെടുപ്പ്(c) {
        അവസ്ഥ TOK_EQ:
            c = IL_OP_BEQ;
            നിർത്തുക;
        അവസ്ഥ TOK_NE:
            c = IL_OP_BNE_UN;
            നിർത്തുക;
        അവസ്ഥ TOK_LT:
            c = IL_OP_BLT;
            നിർത്തുക;
        അവസ്ഥ TOK_LE:
            c = IL_OP_BLE;
            നിർത്തുക;
        അവസ്ഥ TOK_GT:
            c = IL_OP_BGT;
            നിർത്തുക;
        അവസ്ഥ TOK_GE:
            c = IL_OP_BGE;
            നിർത്തുക;
        അവസ്ഥ TOK_ULT:
            c = IL_OP_BLT_UN;
            നിർത്തുക;
        അവസ്ഥ TOK_ULE:
            c = IL_OP_BLE_UN;
            നിർത്തുക;
        അവസ്ഥ TOK_UGT:
            c = IL_OP_BGT_UN;
            നിർത്തുക;
        അവസ്ഥ TOK_UGE:
            c = IL_OP_BGE_UN;
            നിർത്തുക;
        }
        t = out_opj(c, t);
    } അല്ലെങ്കിൽ എങ്കിൽ (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        എങ്കിൽ ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            ആകുമ്പോൾ (*p != 0)
                p = (പൂർണ്ണസംഖ്യ *)*p;
            *p = t;
            t = vtop->c.i;
        } അല്ലെങ്കിൽ {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    തിരികെ t;
}

/* generate an integer binary operation */
ശൂന്യം gen_opi(പൂർണ്ണസംഖ്യ op)
{
    gv2(RC_ST1, RC_ST0);
    തിരഞ്ഞെടുപ്പ്(op) {
    അവസ്ഥ '+':
        out_op(IL_OP_ADD);
        പോകുക std_op;
    അവസ്ഥ '-':
        out_op(IL_OP_SUB);
        പോകുക std_op;
    അവസ്ഥ '&':
        out_op(IL_OP_AND);
        പോകുക std_op;
    അവസ്ഥ '^':
        out_op(IL_OP_XOR);
        പോകുക std_op;
    അവസ്ഥ '|':
        out_op(IL_OP_OR);
        പോകുക std_op;
    അവസ്ഥ '*':
        out_op(IL_OP_MUL);
        പോകുക std_op;
    അവസ്ഥ TOK_SHL:
        out_op(IL_OP_SHL);
        പോകുക std_op;
    അവസ്ഥ TOK_SHR:
        out_op(IL_OP_SHR_UN);
        പോകുക std_op;
    അവസ്ഥ TOK_SAR:
        out_op(IL_OP_SHR);
        പോകുക std_op;
    അവസ്ഥ '/':
    അവസ്ഥ TOK_PDIV:
        out_op(IL_OP_DIV);
        പോകുക std_op;
    അവസ്ഥ TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        പോകുക std_op;
    അവസ്ഥ '%':
        out_op(IL_OP_REM);
        പോകുക std_op;
    അവസ്ഥ TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        നിർത്തുക;
    അവസ്ഥ TOK_EQ:
    അവസ്ഥ TOK_NE:
    അവസ്ഥ TOK_LT:
    അവസ്ഥ TOK_LE:
    അവസ്ഥ TOK_GT:
    അവസ്ഥ TOK_GE:
    അവസ്ഥ TOK_ULT:
    അവസ്ഥ TOK_ULE:
    അവസ്ഥ TOK_UGT:
    അവസ്ഥ TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        നിർത്തുക;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
ശൂന്യം gen_opf(പൂർണ്ണസംഖ്യ op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ശൂന്യം gen_cvt_itof(പൂർണ്ണസംഖ്യ t)
{
    gv(RC_ST0);
    എങ്കിൽ (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    അല്ലെങ്കിൽ
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
ശൂന്യം gen_cvt_ftoi(പൂർണ്ണസംഖ്യ t)
{
    gv(RC_ST0);
    തിരഞ്ഞെടുപ്പ്(t) {
    അവസ്ഥ VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        നിർത്തുക;
    അവസ്ഥ VT_LLONG:
        out_op(IL_OP_CONV_I8);
        നിർത്തുക;
    അവസ്ഥ VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        out_op(IL_OP_CONV_I4);
        നിർത്തുക;
    }
}

/* convert from one floating point type to another */
ശൂന്യം gen_cvt_ftof(പൂർണ്ണസംഖ്യ t)
{
    gv(RC_ST0);
    എങ്കിൽ (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } അല്ലെങ്കിൽ {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

