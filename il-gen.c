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
गणना {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

ध्रुव पूर्णाङ्क reg_classes[NB_REGS] = {
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
प्रकारनिर्देश संरचना GFuncContext {
    पूर्णाङ्क func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#define IL_OP_PREFIX 0xFE

गणना ILOPCodes {
#define OP(name, str, n) IL_OP_ ## name = n,
#अन्तर्भाव "il-opcodes.h"
#undef OP
};

वर्ण *il_opcodes_str[] = {
#define OP(name, str, n) [n] = str,
#अन्तर्भाव "il-opcodes.h"
#undef OP
};

/******************************************************/

/* arguments variable numbers start from there */
#define ARG_BASE 0x70000000

स्थिर FILE *il_outfile;

स्थिर शून्य out_byte(पूर्णाङ्क c)
{
    *(वर्ण *)ind++ = c;
}

स्थिर शून्य out_le32(पूर्णाङ्क c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

स्थिर शून्य init_outfile(शून्य)
{
    सचे (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

स्थिर शून्य out_op1(पूर्णाङ्क op)
{
    सचे (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
स्थिर शून्य out_op(पूर्णाङ्क op)
{
    out_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

स्थिर शून्य out_opb(पूर्णाङ्क op, पूर्णाङ्क c)
{
    out_op1(op);
    out_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

स्थिर शून्य out_opi(पूर्णाङ्क op, पूर्णाङ्क c)
{
    out_op1(op);
    out_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
स्थिर शून्य il_type_to_str(वर्ण *buf, पूर्णाङ्क buf_size, 
                           पूर्णाङ्क t, ध्रुव वर्ण *varstr)
{
    पूर्णाङ्क bt;
    Sym *s, *sa;
    वर्ण buf1[256];
    ध्रुव वर्ण *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    सचे (t & VT_UNSIGNED)
        pstrcat(buf, buf_size, "unsigned ");
    विकल्प(bt) {
    पक्ष VT_VOID:
        tstr = "void";
        गच्छ add_tstr;
    पक्ष VT_BOOL:
        tstr = "bool";
        गच्छ add_tstr;
    पक्ष VT_BYTE:
        tstr = "int8";
        गच्छ add_tstr;
    पक्ष VT_SHORT:
        tstr = "int16";
        गच्छ add_tstr;
    पक्ष VT_ENUM:
    पक्ष VT_INT:
    पक्ष VT_LONG:
        tstr = "int32";
        गच्छ add_tstr;
    पक्ष VT_LLONG:
        tstr = "int64";
        गच्छ add_tstr;
    पक्ष VT_FLOAT:
        tstr = "float32";
        गच्छ add_tstr;
    पक्ष VT_DOUBLE:
    पक्ष VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        भङ्ग;
    पक्ष VT_STRUCT:
        tcc_error("structures not handled yet");
        भङ्ग;
    पक्ष VT_FUNC:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_size, s->t, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        याव (sa != रिक्त) {
            il_type_to_str(buf1, परिमाण(buf1), sa->t, रिक्त);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            सचे (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        गच्छ no_var;
    पक्ष VT_PTR:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, परिमाण(buf1), "*");
        सचे (varstr)
            pstrcat(buf1, परिमाण(buf1), varstr);
        il_type_to_str(buf, buf_size, s->t, buf1);
        गच्छ no_var;
    }
    सचे (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
शून्य greloc_patch1(Reloc *p, पूर्णाङ्क val)
{
}

/* output a symbol and patch all calls to it */
शून्य gsym_addr(t, a)
{
}

/* output jump and return symbol */
स्थिर पूर्णाङ्क out_opj(पूर्णाङ्क op, पूर्णाङ्क c)
{
    out_op1(op);
    out_le32(0);
    सचे (c == 0) {
        c = ind - (पूर्णाङ्क)cur_text_section->data;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    पटिनिवत्त c;
}

शून्य gsym(पूर्णाङ्क t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
शून्य load(पूर्णाङ्क r, SValue *sv)
{
    पूर्णाङ्क v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    सचे (sv->r & VT_LVAL) {
        सचे (v == VT_LOCAL) {
            सचे (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                सचे (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } अञ्ञथा सचे (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } अञ्ञथा {
                    out_opi(IL_OP_LDARG, fc);
                }
            } अञ्ञथा {
                सचे (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } अञ्ञथा सचे (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } अञ्ञथा {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } अञ्ञथा सचे (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } अञ्ञथा {
            सचे ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } अञ्ञथा सचे ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } अञ्ञथा सचे ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } अञ्ञथा सचे ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            अञ्ञथा सचे ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            अञ्ञथा सचे ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            अञ्ञथा सचे ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            अञ्ञथा
                out_op(IL_OP_LDIND_I4);
        } 
    } अञ्ञथा {
        सचे (v == VT_CONST) {
            /* XXX: handle globals */
            सचे (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } अञ्ञथा {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } अञ्ञथा सचे (v == VT_LOCAL) {
            सचे (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                सचे (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } अञ्ञथा {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } अञ्ञथा {
                सचे (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } अञ्ञथा {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } अञ्ञथा {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
शून्य store(पूर्णाङ्क r, SValue *sv)
{
    पूर्णाङ्क v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    सचे (v == VT_LOCAL) {
        सचे (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            सचे (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } अञ्ञथा {
                out_opi(IL_OP_STARG, fc);
            }
        } अञ्ञथा {
            सचे (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } अञ्ञथा सचे (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } अञ्ञथा {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } अञ्ञथा सचे (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } अञ्ञथा {
        सचे ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        अञ्ञथा सचे ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        अञ्ञथा सचे ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        अञ्ञथा सचे ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        अञ्ञथा सचे ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        अञ्ञथा
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
शून्य gfunc_start(GFuncContext *c, पूर्णाङ्क func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
शून्य gfunc_param(GFuncContext *c)
{
    सचे ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } अञ्ञथा {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
शून्य gfunc_call(GFuncContext *c)
{
    वर्ण buf[1024];

    सचे ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, परिमाण(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } अञ्ञथा {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, परिमाण(buf), vtop->t, रिक्त);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
शून्य gfunc_prolog(पूर्णाङ्क t)
{
    पूर्णाङ्क addr, u, func_call;
    Sym *sym;
    वर्ण buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, परिमाण(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    सचे (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    सचे ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    याव ((sym = sym->next) != रिक्त) {
        u = sym->t;
        sym_प्रक्षिप(sym->v & ~SYM_FIELD, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
शून्य gfunc_epilog(शून्य)
{
    out_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
पूर्णाङ्क gjmp(पूर्णाङ्क t)
{
    पटिनिवत्त out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
शून्य gjmp_addr(पूर्णाङ्क a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
पूर्णाङ्क gtst(पूर्णाङ्क inv, पूर्णाङ्क t)
{
    पूर्णाङ्क v, *p, c;

    v = vtop->r & VT_VALMASK;
    सचे (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        विकल्प(c) {
        पक्ष TOK_EQ:
            c = IL_OP_BEQ;
            भङ्ग;
        पक्ष TOK_NE:
            c = IL_OP_BNE_UN;
            भङ्ग;
        पक्ष TOK_LT:
            c = IL_OP_BLT;
            भङ्ग;
        पक्ष TOK_LE:
            c = IL_OP_BLE;
            भङ्ग;
        पक्ष TOK_GT:
            c = IL_OP_BGT;
            भङ्ग;
        पक्ष TOK_GE:
            c = IL_OP_BGE;
            भङ्ग;
        पक्ष TOK_ULT:
            c = IL_OP_BLT_UN;
            भङ्ग;
        पक्ष TOK_ULE:
            c = IL_OP_BLE_UN;
            भङ्ग;
        पक्ष TOK_UGT:
            c = IL_OP_BGT_UN;
            भङ्ग;
        पक्ष TOK_UGE:
            c = IL_OP_BGE_UN;
            भङ्ग;
        }
        t = out_opj(c, t);
    } अञ्ञथा सचे (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        सचे ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            याव (*p != 0)
                p = (पूर्णाङ्क *)*p;
            *p = t;
            t = vtop->c.i;
        } अञ्ञथा {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    पटिनिवत्त t;
}

/* generate an integer binary operation */
शून्य gen_opi(पूर्णाङ्क op)
{
    gv2(RC_ST1, RC_ST0);
    विकल्प(op) {
    पक्ष '+':
        out_op(IL_OP_ADD);
        गच्छ std_op;
    पक्ष '-':
        out_op(IL_OP_SUB);
        गच्छ std_op;
    पक्ष '&':
        out_op(IL_OP_AND);
        गच्छ std_op;
    पक्ष '^':
        out_op(IL_OP_XOR);
        गच्छ std_op;
    पक्ष '|':
        out_op(IL_OP_OR);
        गच्छ std_op;
    पक्ष '*':
        out_op(IL_OP_MUL);
        गच्छ std_op;
    पक्ष TOK_SHL:
        out_op(IL_OP_SHL);
        गच्छ std_op;
    पक्ष TOK_SHR:
        out_op(IL_OP_SHR_UN);
        गच्छ std_op;
    पक्ष TOK_SAR:
        out_op(IL_OP_SHR);
        गच्छ std_op;
    पक्ष '/':
    पक्ष TOK_PDIV:
        out_op(IL_OP_DIV);
        गच्छ std_op;
    पक्ष TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        गच्छ std_op;
    पक्ष '%':
        out_op(IL_OP_REM);
        गच्छ std_op;
    पक्ष TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        भङ्ग;
    पक्ष TOK_EQ:
    पक्ष TOK_NE:
    पक्ष TOK_LT:
    पक्ष TOK_LE:
    पक्ष TOK_GT:
    पक्ष TOK_GE:
    पक्ष TOK_ULT:
    पक्ष TOK_ULE:
    पक्ष TOK_UGT:
    पक्ष TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        भङ्ग;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
शून्य gen_opf(पूर्णाङ्क op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
शून्य gen_cvt_itof(पूर्णाङ्क t)
{
    gv(RC_ST0);
    सचे (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    अञ्ञथा
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
शून्य gen_cvt_ftoi(पूर्णाङ्क t)
{
    gv(RC_ST0);
    विकल्प(t) {
    पक्ष VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        भङ्ग;
    पक्ष VT_LLONG:
        out_op(IL_OP_CONV_I8);
        भङ्ग;
    पक्ष VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        भङ्ग;
    स्वभाव:
        out_op(IL_OP_CONV_I4);
        भङ्ग;
    }
}

/* convert from one floating point type to another */
शून्य gen_cvt_ftof(पूर्णाङ्क t)
{
    gv(RC_ST0);
    सचे (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } अञ्ञथा {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

