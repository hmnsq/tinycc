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

#غلطی this رمز has ثنائی_ہندسہ-rotted since 2003

/* number of available registers */
#تعریف_کرو NB_REGS             3

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#تعریف_کرو RC_ST      0x0001  /* any stack entry */
#تعریف_کرو RC_ST0     0x0002  /* top of stack */
#تعریف_کرو RC_ST1     0x0004  /* top - 1 */

#تعریف_کرو RC_INT     RC_ST
#تعریف_کرو RC_FLOAT   RC_ST
#تعریف_کرو RC_IRET    RC_ST0 /* function return: integer register */
#تعریف_کرو RC_LRET    RC_ST0 /* function return: second integer register */
#تعریف_کرو RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
شمار {
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
#تعریف_کرو REG_IRET REG_ST0 /* single word int return register */
#تعریف_کرو REG_LRET REG_ST0 /* second word return register (for long long) */
#تعریف_کرو REG_FRET REG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
/* #define INVERT_FUNC_PARAMS */

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#تعریف_کرو PTR_سائز 4

/* long double size and alignment, in bytes */
#تعریف_کرو LDOUBLE_سائز  8
#تعریف_کرو LDOUBLE_ALIGN 8

/* function call context */
قسمتعریف ساخت GFuncContext {
    صحیح func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#تعریف_کرو IL_OP_سابقہ 0xFE

شمار ILOPCodes {
#تعریف_کرو OP(name, str, n) IL_OP_ ## name = n,
#شامل "il-opcodes.h"
#تعریف_منسوخ OP
};

حرف *il_opcodes_str[] = {
#تعریف_کرو OP(name, str, n) [n] = str,
#شامل "il-opcodes.h"
#تعریف_منسوخ OP
};

/******************************************************/

/* arguments variable numbers start from there */
#تعریف_کرو ARG_بنیاد 0x70000000

ساکن FILE *il_outfile;

ساکن خالی برآمد_byte(صحیح c)
{
    *(حرف *)ind++ = c;
}

ساکن خالی برآمد_le32(صحیح c)
{
    برآمد_byte(c);
    برآمد_byte(c >> 8);
    برآمد_byte(c >> 16);
    برآمد_byte(c >> 24);
}

ساکن خالی init_outfile(خالی)
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

ساکن خالی برآمد_op1(صحیح op)
{
    اگر (op & 0x100)
        برآمد_byte(IL_OP_سابقہ);
    برآمد_byte(op & 0xff);
}

/* output an opcode with prefix */
ساکن خالی برآمد_op(صحیح op)
{
    برآمد_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

ساکن خالی برآمد_opb(صحیح op, صحیح c)
{
    برآمد_op1(op);
    برآمد_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

ساکن خالی برآمد_opi(صحیح op, صحیح c)
{
    برآمد_op1(op);
    برآمد_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
ساکن خالی il_type_مقصد_str(حرف *buf, صحیح buf_سائز, 
                           صحیح t, ثابت حرف *varstr)
{
    صحیح bt;
    Sym *s, *sa;
    حرف buf1[256];
    ثابت حرف *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    اگر (t & VT_UNSIGNED)
        pstrcat(buf, buf_سائز, "unsigned ");
    انتخاب(bt) {
    حالت VT_VOID:
        tstr = "void";
        جاؤ جوڑو_tstr;
    حالت VT_BOOL:
        tstr = "bool";
        جاؤ جوڑو_tstr;
    حالت VT_BYTE:
        tstr = "int8";
        جاؤ جوڑو_tstr;
    حالت VT_SHORT:
        tstr = "int16";
        جاؤ جوڑو_tstr;
    حالت VT_ENUM:
    حالت VT_INT:
    حالت VT_LONG:
        tstr = "int32";
        جاؤ جوڑو_tstr;
    حالت VT_LLONG:
        tstr = "int64";
        جاؤ جوڑو_tstr;
    حالت VT_FLOAT:
        tstr = "float32";
        جاؤ جوڑو_tstr;
    حالت VT_DOUBLE:
    حالت VT_LDOUBLE:
        tstr = "float64";
    جوڑو_tstr:
        pstrcat(buf, buf_سائز, tstr);
        توڑو;
    حالت VT_STRUCT:
        tcc_error("structures not handled yet");
        توڑو;
    حالت VT_FUNC:
        s = sym_ڈھونڈو((غیرعلامتی)t >> VT_STRUCT_سرکاؤ);
        il_type_مقصد_str(buf, buf_سائز, s->t, varstr);
        pstrcat(buf, buf_سائز, "(");
        sa = s->اگلا;
        جب (sa != تہی) {
            il_type_مقصد_str(buf1, حجم(buf1), sa->t, تہی);
            pstrcat(buf, buf_سائز, buf1);
            sa = sa->اگلا;
            اگر (sa)
                pstrcat(buf, buf_سائز, ", ");
        }
        pstrcat(buf, buf_سائز, ")");
        جاؤ no_var;
    حالت VT_PTR:
        s = sym_ڈھونڈو((غیرعلامتی)t >> VT_STRUCT_سرکاؤ);
        pstrcpy(buf1, حجم(buf1), "*");
        اگر (varstr)
            pstrcat(buf1, حجم(buf1), varstr);
        il_type_مقصد_str(buf, buf_سائز, s->t, buf1);
        جاؤ no_var;
    }
    اگر (varstr) {
        pstrcat(buf, buf_سائز, " ");
        pstrcat(buf, buf_سائز, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
خالی greloc_patch1(Reloc *p, صحیح val)
{
}

/* output a symbol and patch all calls to it */
خالی gsym_addr(t, a)
{
}

/* output jump and return symbol */
ساکن صحیح برآمد_opj(صحیح op, صحیح c)
{
    برآمد_op1(op);
    برآمد_le32(0);
    اگر (c == 0) {
        c = ind - (صحیح)cur_متن_section->ڈیٹا;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    واپس c;
}

خالی gsym(صحیح t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
خالی بھرو(صحیح r, SValue *sv)
{
    صحیح v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    اگر (sv->r & VT_LVAL) {
        اگر (v == VT_LOCAL) {
            اگر (fc >= ARG_بنیاد) {
                fc -= ARG_بنیاد;
                اگر (fc >= 0 && fc <= 4) {
                    برآمد_op(IL_OP_LDARG_0 + fc);
                } ورنہ اگر (fc <= 0xff) {
                    برآمد_opb(IL_OP_LDARG_S, fc);
                } ورنہ {
                    برآمد_opi(IL_OP_LDARG, fc);
                }
            } ورنہ {
                اگر (fc >= 0 && fc <= 4) {
                    برآمد_op(IL_OP_LDLOC_0 + fc);
                } ورنہ اگر (fc <= 0xff) {
                    برآمد_opb(IL_OP_LDLOC_S, fc);
                } ورنہ {
                    برآمد_opi(IL_OP_LDLOC, fc);
                }
            }
        } ورنہ اگر (v == VT_CONST) {
                /* XXX: handle globals */
                برآمد_opi(IL_OP_LDSFLD, 0);
        } ورنہ {
            اگر ((ft & VT_BTYPE) == VT_FLOAT) {
                برآمد_op(IL_OP_LDIND_R4);
            } ورنہ اگر ((ft & VT_BTYPE) == VT_DOUBLE) {
                برآمد_op(IL_OP_LDIND_R8);
            } ورنہ اگر ((ft & VT_BTYPE) == VT_LDOUBLE) {
                برآمد_op(IL_OP_LDIND_R8);
            } ورنہ اگر ((ft & VT_TYPE) == VT_BYTE)
                برآمد_op(IL_OP_LDIND_I1);
            ورنہ اگر ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                برآمد_op(IL_OP_LDIND_U1);
            ورنہ اگر ((ft & VT_TYPE) == VT_SHORT)
                برآمد_op(IL_OP_LDIND_I2);
            ورنہ اگر ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                برآمد_op(IL_OP_LDIND_U2);
            ورنہ
                برآمد_op(IL_OP_LDIND_I4);
        } 
    } ورنہ {
        اگر (v == VT_CONST) {
            /* XXX: handle globals */
            اگر (fc >= -1 && fc <= 8) {
                برآمد_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } ورنہ {
                برآمد_opi(IL_OP_LDC_I4, fc);
            }
        } ورنہ اگر (v == VT_LOCAL) {
            اگر (fc >= ARG_بنیاد) {
                fc -= ARG_بنیاد;
                اگر (fc <= 0xff) {
                    برآمد_opb(IL_OP_LDARGA_S, fc);
                } ورنہ {
                    برآمد_opi(IL_OP_LDARGA, fc);
                }
            } ورنہ {
                اگر (fc <= 0xff) {
                    برآمد_opb(IL_OP_LDLOCA_S, fc);
                } ورنہ {
                    برآمد_opi(IL_OP_LDLOCA, fc);
                }
            }
        } ورنہ {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
خالی store(صحیح r, SValue *sv)
{
    صحیح v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    اگر (v == VT_LOCAL) {
        اگر (fc >= ARG_بنیاد) {
            fc -= ARG_بنیاد;
            /* XXX: check IL arg store semantics */
            اگر (fc <= 0xff) {
                برآمد_opb(IL_OP_STARG_S, fc);
            } ورنہ {
                برآمد_opi(IL_OP_STARG, fc);
            }
        } ورنہ {
            اگر (fc >= 0 && fc <= 4) {
                برآمد_op(IL_OP_STLOC_0 + fc);
            } ورنہ اگر (fc <= 0xff) {
                برآمد_opb(IL_OP_STLOC_S, fc);
            } ورنہ {
                برآمد_opi(IL_OP_STLOC, fc);
            }
        }
    } ورنہ اگر (v == VT_CONST) {
        /* XXX: handle globals */
        برآمد_opi(IL_OP_STSFLD, 0);
    } ورنہ {
        اگر ((ft & VT_BTYPE) == VT_FLOAT)
            برآمد_op(IL_OP_STIND_R4);
        ورنہ اگر ((ft & VT_BTYPE) == VT_DOUBLE)
            برآمد_op(IL_OP_STIND_R8);
        ورنہ اگر ((ft & VT_BTYPE) == VT_LDOUBLE)
            برآمد_op(IL_OP_STIND_R8);
        ورنہ اگر ((ft & VT_BTYPE) == VT_BYTE)
            برآمد_op(IL_OP_STIND_I1);
        ورنہ اگر ((ft & VT_BTYPE) == VT_SHORT)
            برآمد_op(IL_OP_STIND_I2);
        ورنہ
            برآمد_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
خالی gfunc_آغاز(GFuncContext *c, صحیح func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
خالی gfunc_param(GFuncContext *c)
{
    اگر ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } ورنہ {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
خالی gfunc_call(GFuncContext *c)
{
    حرف buf[1024];

    اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_مقصد_str(buf, حجم(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } ورنہ {
        /* indirect call */
        gv(RC_INT);
        il_type_مقصد_str(buf, حجم(buf), vtop->t, تہی);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
خالی gfunc_prolog(صحیح t)
{
    صحیح addr, u, func_call;
    Sym *sym;
    حرف buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_مقصد_str(buf, حجم(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    اگر (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_ڈھونڈو((غیرعلامتی)t >> VT_STRUCT_سرکاؤ);
    func_call = sym->r;

    addr = ARG_بنیاد;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    اگر ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    جب ((sym = sym->اگلا) != تہی) {
        u = sym->t;
        sym_ڈالو(sym->v & ~SYM_میدان, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
خالی gfunc_epilog(خالی)
{
    برآمد_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
صحیح gjmp(صحیح t)
{
    واپس برآمد_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
خالی gjmp_addr(صحیح a)
{
    /* XXX: handle syms */
    برآمد_opi(IL_OP_BR, a);
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
            توڑو;
        حالت TOK_NE:
            c = IL_OP_BNE_UN;
            توڑو;
        حالت TOK_LT:
            c = IL_OP_BLT;
            توڑو;
        حالت TOK_LE:
            c = IL_OP_BLE;
            توڑو;
        حالت TOK_GT:
            c = IL_OP_BGT;
            توڑو;
        حالت TOK_GE:
            c = IL_OP_BGE;
            توڑو;
        حالت TOK_ULT:
            c = IL_OP_BLT_UN;
            توڑو;
        حالت TOK_ULE:
            c = IL_OP_BLE_UN;
            توڑو;
        حالت TOK_UGT:
            c = IL_OP_BGT_UN;
            توڑو;
        حالت TOK_UGE:
            c = IL_OP_BGE_UN;
            توڑو;
        }
        t = برآمد_opj(c, t);
    } ورنہ اگر (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        اگر ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            جب (*p != 0)
                p = (صحیح *)*p;
            *p = t;
            t = vtop->c.i;
        } ورنہ {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    واپس t;
}

/* generate an integer binary operation */
خالی gen_opi(صحیح op)
{
    gv2(RC_ST1, RC_ST0);
    انتخاب(op) {
    حالت '+':
        برآمد_op(IL_OP_جوڑو);
        جاؤ std_op;
    حالت '-':
        برآمد_op(IL_OP_SUB);
        جاؤ std_op;
    حالت '&':
        برآمد_op(IL_OP_AND);
        جاؤ std_op;
    حالت '^':
        برآمد_op(IL_OP_XOR);
        جاؤ std_op;
    حالت '|':
        برآمد_op(IL_OP_OR);
        جاؤ std_op;
    حالت '*':
        برآمد_op(IL_OP_MUL);
        جاؤ std_op;
    حالت TOK_SHL:
        برآمد_op(IL_OP_SHL);
        جاؤ std_op;
    حالت TOK_SHR:
        برآمد_op(IL_OP_SHR_UN);
        جاؤ std_op;
    حالت TOK_SAR:
        برآمد_op(IL_OP_SHR);
        جاؤ std_op;
    حالت '/':
    حالت TOK_PDIV:
        برآمد_op(IL_OP_DIV);
        جاؤ std_op;
    حالت TOK_UDIV:
        برآمد_op(IL_OP_DIV_UN);
        جاؤ std_op;
    حالت '%':
        برآمد_op(IL_OP_REM);
        جاؤ std_op;
    حالت TOK_UMOD:
        برآمد_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        توڑو;
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
        توڑو;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
خالی gen_opf(صحیح op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
خالی gen_cvt_itof(صحیح t)
{
    gv(RC_ST0);
    اگر (t == VT_FLOAT)
        برآمد_op(IL_OP_CONV_R4);
    ورنہ
        برآمد_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
خالی gen_cvt_ftoi(صحیح t)
{
    gv(RC_ST0);
    انتخاب(t) {
    حالت VT_INT | VT_UNSIGNED:
        برآمد_op(IL_OP_CONV_U4);
        توڑو;
    حالت VT_LLONG:
        برآمد_op(IL_OP_CONV_I8);
        توڑو;
    حالت VT_LLONG | VT_UNSIGNED:
        برآمد_op(IL_OP_CONV_U8);
        توڑو;
    طےشدہ:
        برآمد_op(IL_OP_CONV_I4);
        توڑو;
    }
}

/* convert from one floating point type to another */
خالی gen_cvt_ftof(صحیح t)
{
    gv(RC_ST0);
    اگر (t == VT_FLOAT) {
        برآمد_op(IL_OP_CONV_R4);
    } ورنہ {
        برآمد_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

