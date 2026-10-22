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
شمارش {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

ثابت صحیح reg_classes[NB_REGS] = {
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
تعریفنوع ساختار GFuncContext {
    صحیح func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#define IL_OP_PREFIX 0xFE

شمارش ILOPCodes {
#define OP(name, str, n) IL_OP_ ## name = n,
#شامل "il-opcodes.h"
#undef OP
};

نویسه *il_opcodes_str[] = {
#define OP(name, str, n) [n] = str,
#شامل "il-opcodes.h"
#undef OP
};

/******************************************************/

/* arguments variable numbers start from there */
#define ARG_BASE 0x70000000

ایستا FILE *il_outfile;

ایستا تهی out_byte(صحیح c)
{
    *(نویسه *)ind++ = c;
}

ایستا تهی out_le32(صحیح c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

ایستا تهی init_outfile(تهی)
{
    اگر (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

ایستا تهی out_op1(صحیح op)
{
    اگر (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
ایستا تهی out_op(صحیح op)
{
    out_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

ایستا تهی out_opb(صحیح op, صحیح c)
{
    out_op1(op);
    out_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

ایستا تهی out_opi(صحیح op, صحیح c)
{
    out_op1(op);
    out_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
ایستا تهی il_type_to_str(نویسه *buf, صحیح buf_size, 
                           صحیح t, ثابت نویسه *varstr)
{
    صحیح bt;
    Sym *s, *sa;
    نویسه buf1[256];
    ثابت نویسه *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    اگر (t & VT_UNSIGNED)
        pstrcat(buf, buf_size, "unsigned ");
    انتخاب(bt) {
    حالت VT_VOID:
        tstr = "void";
        برو add_tstr;
    حالت VT_BOOL:
        tstr = "bool";
        برو add_tstr;
    حالت VT_BYTE:
        tstr = "int8";
        برو add_tstr;
    حالت VT_SHORT:
        tstr = "int16";
        برو add_tstr;
    حالت VT_ENUM:
    حالت VT_INT:
    حالت VT_LONG:
        tstr = "int32";
        برو add_tstr;
    حالت VT_LLONG:
        tstr = "int64";
        برو add_tstr;
    حالت VT_FLOAT:
        tstr = "float32";
        برو add_tstr;
    حالت VT_DOUBLE:
    حالت VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        بشکن;
    حالت VT_STRUCT:
        tcc_error("structures not handled yet");
        بشکن;
    حالت VT_FUNC:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_size, s->t, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        وقتی (sa != پوچ) {
            il_type_to_str(buf1, اندازه(buf1), sa->t, پوچ);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            اگر (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        برو no_var;
    حالت VT_PTR:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, اندازه(buf1), "*");
        اگر (varstr)
            pstrcat(buf1, اندازه(buf1), varstr);
        il_type_to_str(buf, buf_size, s->t, buf1);
        برو no_var;
    }
    اگر (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
تهی greloc_patch1(Reloc *p, صحیح val)
{
}

/* output a symbol and patch all calls to it */
تهی gsym_addr(t, a)
{
}

/* output jump and return symbol */
ایستا صحیح out_opj(صحیح op, صحیح c)
{
    out_op1(op);
    out_le32(0);
    اگر (c == 0) {
        c = ind - (صحیح)cur_text_section->data;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    بازگشت c;
}

تهی gsym(صحیح t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
تهی load(صحیح r, SValue *sv)
{
    صحیح v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    اگر (sv->r & VT_LVAL) {
        اگر (v == VT_LOCAL) {
            اگر (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                اگر (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } وگرنه اگر (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } وگرنه {
                    out_opi(IL_OP_LDARG, fc);
                }
            } وگرنه {
                اگر (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } وگرنه اگر (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } وگرنه {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } وگرنه اگر (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } وگرنه {
            اگر ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } وگرنه اگر ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } وگرنه اگر ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } وگرنه اگر ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            وگرنه اگر ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            وگرنه اگر ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            وگرنه اگر ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            وگرنه
                out_op(IL_OP_LDIND_I4);
        } 
    } وگرنه {
        اگر (v == VT_CONST) {
            /* XXX: handle globals */
            اگر (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } وگرنه {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } وگرنه اگر (v == VT_LOCAL) {
            اگر (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                اگر (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } وگرنه {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } وگرنه {
                اگر (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } وگرنه {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } وگرنه {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
تهی store(صحیح r, SValue *sv)
{
    صحیح v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    اگر (v == VT_LOCAL) {
        اگر (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            اگر (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } وگرنه {
                out_opi(IL_OP_STARG, fc);
            }
        } وگرنه {
            اگر (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } وگرنه اگر (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } وگرنه {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } وگرنه اگر (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } وگرنه {
        اگر ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        وگرنه اگر ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        وگرنه اگر ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        وگرنه اگر ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        وگرنه اگر ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        وگرنه
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
تهی gfunc_start(GFuncContext *c, صحیح func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
تهی gfunc_param(GFuncContext *c)
{
    اگر ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } وگرنه {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
تهی gfunc_call(GFuncContext *c)
{
    نویسه buf[1024];

    اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, اندازه(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } وگرنه {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, اندازه(buf), vtop->t, پوچ);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
تهی gfunc_prolog(صحیح t)
{
    صحیح addr, u, func_call;
    Sym *sym;
    نویسه buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, اندازه(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    اگر (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    اگر ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    وقتی ((sym = sym->next) != پوچ) {
        u = sym->t;
        sym_افزودن(sym->v & ~SYM_FIELD, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
تهی gfunc_epilog(تهی)
{
    out_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
صحیح gjmp(صحیح t)
{
    بازگشت out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
تهی gjmp_addr(صحیح a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
صحیح gtst(صحیح inv, صحیح t)
{
    صحیح v, *p, c;

    v = vtop->r & VT_VALMASK;
    اگر (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        انتخاب(c) {
        حالت TOK_EQ:
            c = IL_OP_BEQ;
            بشکن;
        حالت TOK_NE:
            c = IL_OP_BNE_UN;
            بشکن;
        حالت TOK_LT:
            c = IL_OP_BLT;
            بشکن;
        حالت TOK_LE:
            c = IL_OP_BLE;
            بشکن;
        حالت TOK_GT:
            c = IL_OP_BGT;
            بشکن;
        حالت TOK_GE:
            c = IL_OP_BGE;
            بشکن;
        حالت TOK_ULT:
            c = IL_OP_BLT_UN;
            بشکن;
        حالت TOK_ULE:
            c = IL_OP_BLE_UN;
            بشکن;
        حالت TOK_UGT:
            c = IL_OP_BGT_UN;
            بشکن;
        حالت TOK_UGE:
            c = IL_OP_BGE_UN;
            بشکن;
        }
        t = out_opj(c, t);
    } وگرنه اگر (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        اگر ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            وقتی (*p != 0)
                p = (صحیح *)*p;
            *p = t;
            t = vtop->c.i;
        } وگرنه {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    بازگشت t;
}

/* generate an integer binary operation */
تهی gen_opi(صحیح op)
{
    gv2(RC_ST1, RC_ST0);
    انتخاب(op) {
    حالت '+':
        out_op(IL_OP_ADD);
        برو std_op;
    حالت '-':
        out_op(IL_OP_SUB);
        برو std_op;
    حالت '&':
        out_op(IL_OP_AND);
        برو std_op;
    حالت '^':
        out_op(IL_OP_XOR);
        برو std_op;
    حالت '|':
        out_op(IL_OP_OR);
        برو std_op;
    حالت '*':
        out_op(IL_OP_MUL);
        برو std_op;
    حالت TOK_SHL:
        out_op(IL_OP_SHL);
        برو std_op;
    حالت TOK_SHR:
        out_op(IL_OP_SHR_UN);
        برو std_op;
    حالت TOK_SAR:
        out_op(IL_OP_SHR);
        برو std_op;
    حالت '/':
    حالت TOK_PDIV:
        out_op(IL_OP_DIV);
        برو std_op;
    حالت TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        برو std_op;
    حالت '%':
        out_op(IL_OP_REM);
        برو std_op;
    حالت TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        بشکن;
    حالت TOK_EQ:
    حالت TOK_NE:
    حالت TOK_LT:
    حالت TOK_LE:
    حالت TOK_GT:
    حالت TOK_GE:
    حالت TOK_ULT:
    حالت TOK_ULE:
    حالت TOK_UGT:
    حالت TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        بشکن;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
تهی gen_opf(صحیح op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
تهی gen_cvt_itof(صحیح t)
{
    gv(RC_ST0);
    اگر (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    وگرنه
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
تهی gen_cvt_ftoi(صحیح t)
{
    gv(RC_ST0);
    انتخاب(t) {
    حالت VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        بشکن;
    حالت VT_LLONG:
        out_op(IL_OP_CONV_I8);
        بشکن;
    حالت VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        بشکن;
    پیشفرض:
        out_op(IL_OP_CONV_I4);
        بشکن;
    }
}

/* convert from one floating point type to another */
تهی gen_cvt_ftof(صحیح t)
{
    gv(RC_ST0);
    اگر (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } وگرنه {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

