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

स्थिरांक पूर्णांक reg_classes[NB_REGS] = {
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
प्रकारव्याख्या संरचना GFuncContext {
    पूर्णांक func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#define IL_OP_PREFIX 0xFE

गणना ILOPCodes {
#define OP(name, str, n) IL_OP_ ## name = n,
#अन्तर्भाव "il-opcodes.h"
#undef OP
};

अक्षर *il_opcodes_str[] = {
#define OP(name, str, n) [n] = str,
#अन्तर्भाव "il-opcodes.h"
#undef OP
};

/******************************************************/

/* arguments variable numbers start from there */
#define ARG_BASE 0x70000000

स्थिर खाता *il_outfile;

स्थिर शून्य out_byte(पूर्णांक c)
{
    *(अक्षर *)ind++ = c;
}

स्थिर शून्य out_le32(पूर्णांक c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

स्थिर शून्य init_outfile(शून्य)
{
    जर (!il_outfile) {
        il_outfile = मानक_निकास;
        ख_लिखो(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

स्थिर शून्य out_op1(पूर्णांक op)
{
    जर (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
स्थिर शून्य out_op(पूर्णांक op)
{
    out_op1(op);
    ख_लिखो(il_outfile, " %s\n", il_opcodes_str[op]);
}

स्थिर शून्य out_opb(पूर्णांक op, पूर्णांक c)
{
    out_op1(op);
    out_byte(c);
    ख_लिखो(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

स्थिर शून्य out_opi(पूर्णांक op, पूर्णांक c)
{
    out_op1(op);
    out_le32(c);
    ख_लिखो(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
स्थिर शून्य il_type_to_str(अक्षर *buf, पूर्णांक buf_size, 
                           पूर्णांक t, स्थिरांक अक्षर *varstr)
{
    पूर्णांक bt;
    Sym *s, *sa;
    अक्षर buf1[256];
    स्थिरांक अक्षर *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    जर (t & VT_UNSIGNED)
        pstrcat(buf, buf_size, "unsigned ");
    निवड(bt) {
    स्थिती VT_VOID:
        tstr = "void";
        जा add_tstr;
    स्थिती VT_BOOL:
        tstr = "bool";
        जा add_tstr;
    स्थिती VT_BYTE:
        tstr = "int8";
        जा add_tstr;
    स्थिती VT_SHORT:
        tstr = "int16";
        जा add_tstr;
    स्थिती VT_ENUM:
    स्थिती VT_INT:
    स्थिती VT_LONG:
        tstr = "int32";
        जा add_tstr;
    स्थिती VT_LLONG:
        tstr = "int64";
        जा add_tstr;
    स्थिती VT_FLOAT:
        tstr = "float32";
        जा add_tstr;
    स्थिती VT_DOUBLE:
    स्थिती VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        थांबा;
    स्थिती VT_STRUCT:
        tcc_error("structures not handled yet");
        थांबा;
    स्थिती VT_FUNC:
        s = sym_find((अचिन्हित)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_size, s->t, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        पर्यंत (sa != रिक्त) {
            il_type_to_str(buf1, आकार(buf1), sa->t, रिक्त);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            जर (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        जा no_var;
    स्थिती VT_PTR:
        s = sym_find((अचिन्हित)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, आकार(buf1), "*");
        जर (varstr)
            pstrcat(buf1, आकार(buf1), varstr);
        il_type_to_str(buf, buf_size, s->t, buf1);
        जा no_var;
    }
    जर (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
शून्य greloc_patch1(Reloc *p, पूर्णांक val)
{
}

/* output a symbol and patch all calls to it */
शून्य gsym_addr(t, a)
{
}

/* output jump and return symbol */
स्थिर पूर्णांक out_opj(पूर्णांक op, पूर्णांक c)
{
    out_op1(op);
    out_le32(0);
    जर (c == 0) {
        c = ind - (पूर्णांक)cur_text_section->data;
    }
    ख_लिखो(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    परत c;
}

शून्य gsym(पूर्णांक t)
{
    ख_लिखो(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
शून्य load(पूर्णांक r, SValue *sv)
{
    पूर्णांक v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    जर (sv->r & VT_LVAL) {
        जर (v == VT_LOCAL) {
            जर (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                जर (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } अन्यथा जर (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } अन्यथा {
                    out_opi(IL_OP_LDARG, fc);
                }
            } अन्यथा {
                जर (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } अन्यथा जर (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } अन्यथा {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } अन्यथा जर (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } अन्यथा {
            जर ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } अन्यथा जर ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } अन्यथा जर ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } अन्यथा जर ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            अन्यथा जर ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            अन्यथा जर ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            अन्यथा जर ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            अन्यथा
                out_op(IL_OP_LDIND_I4);
        } 
    } अन्यथा {
        जर (v == VT_CONST) {
            /* XXX: handle globals */
            जर (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } अन्यथा {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } अन्यथा जर (v == VT_LOCAL) {
            जर (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                जर (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } अन्यथा {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } अन्यथा {
                जर (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } अन्यथा {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } अन्यथा {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
शून्य store(पूर्णांक r, SValue *sv)
{
    पूर्णांक v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    जर (v == VT_LOCAL) {
        जर (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            जर (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } अन्यथा {
                out_opi(IL_OP_STARG, fc);
            }
        } अन्यथा {
            जर (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } अन्यथा जर (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } अन्यथा {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } अन्यथा जर (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } अन्यथा {
        जर ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        अन्यथा जर ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        अन्यथा जर ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        अन्यथा जर ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        अन्यथा जर ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        अन्यथा
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
शून्य gfunc_start(GFuncContext *c, पूर्णांक func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
शून्य gfunc_param(GFuncContext *c)
{
    जर ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } अन्यथा {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
शून्य gfunc_call(GFuncContext *c)
{
    अक्षर buf[1024];

    जर ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, आकार(buf), vtop->t, "xxx");
        ख_लिखो(il_outfile, " call %s\n", buf);
    } अन्यथा {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, आकार(buf), vtop->t, रिक्त);
        ख_लिखो(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
शून्य gfunc_prolog(पूर्णांक t)
{
    पूर्णांक addr, u, func_call;
    Sym *sym;
    अक्षर buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, आकार(buf), t, funcname);
    ख_लिखो(il_outfile, ".method static %s il managed\n", buf);
    ख_लिखो(il_outfile, "{\n");
    /* XXX: cannot do better now */
    ख_लिखो(il_outfile, " .maxstack %d\n", NB_REGS);
    ख_लिखो(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    जर (!म_भेद(funcname, "main"))
        ख_लिखो(il_outfile, " .entrypoint\n");
        
    sym = sym_find((अचिन्हित)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    जर ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    पर्यंत ((sym = sym->next) != रिक्त) {
        u = sym->t;
        sym_ढकला(sym->v & ~SYM_FIELD, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
शून्य gfunc_epilog(शून्य)
{
    out_op(IL_OP_RET);
    ख_लिखो(il_outfile, "}\n\n");
}

/* generate a jump to a label */
पूर्णांक gjmp(पूर्णांक t)
{
    परत out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
शून्य gjmp_addr(पूर्णांक a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
पूर्णांक gtst(पूर्णांक inv, पूर्णांक t)
{
    पूर्णांक v, *p, c;

    v = vtop->r & VT_VALMASK;
    जर (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        निवड(c) {
        स्थिती TOK_EQ:
            c = IL_OP_BEQ;
            थांबा;
        स्थिती TOK_NE:
            c = IL_OP_BNE_UN;
            थांबा;
        स्थिती TOK_LT:
            c = IL_OP_BLT;
            थांबा;
        स्थिती TOK_LE:
            c = IL_OP_BLE;
            थांबा;
        स्थिती TOK_GT:
            c = IL_OP_BGT;
            थांबा;
        स्थिती TOK_GE:
            c = IL_OP_BGE;
            थांबा;
        स्थिती TOK_ULT:
            c = IL_OP_BLT_UN;
            थांबा;
        स्थिती TOK_ULE:
            c = IL_OP_BLE_UN;
            थांबा;
        स्थिती TOK_UGT:
            c = IL_OP_BGT_UN;
            थांबा;
        स्थिती TOK_UGE:
            c = IL_OP_BGE_UN;
            थांबा;
        }
        t = out_opj(c, t);
    } अन्यथा जर (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        जर ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            पर्यंत (*p != 0)
                p = (पूर्णांक *)*p;
            *p = t;
            t = vtop->c.i;
        } अन्यथा {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    परत t;
}

/* generate an integer binary operation */
शून्य gen_opi(पूर्णांक op)
{
    gv2(RC_ST1, RC_ST0);
    निवड(op) {
    स्थिती '+':
        out_op(IL_OP_ADD);
        जा std_op;
    स्थिती '-':
        out_op(IL_OP_SUB);
        जा std_op;
    स्थिती '&':
        out_op(IL_OP_AND);
        जा std_op;
    स्थिती '^':
        out_op(IL_OP_XOR);
        जा std_op;
    स्थिती '|':
        out_op(IL_OP_OR);
        जा std_op;
    स्थिती '*':
        out_op(IL_OP_MUL);
        जा std_op;
    स्थिती TOK_SHL:
        out_op(IL_OP_SHL);
        जा std_op;
    स्थिती TOK_SHR:
        out_op(IL_OP_SHR_UN);
        जा std_op;
    स्थिती TOK_SAR:
        out_op(IL_OP_SHR);
        जा std_op;
    स्थिती '/':
    स्थिती TOK_PDIV:
        out_op(IL_OP_DIV);
        जा std_op;
    स्थिती TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        जा std_op;
    स्थिती '%':
        out_op(IL_OP_REM);
        जा std_op;
    स्थिती TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        थांबा;
    स्थिती TOK_EQ:
    स्थिती TOK_NE:
    स्थिती TOK_LT:
    स्थिती TOK_LE:
    स्थिती TOK_GT:
    स्थिती TOK_GE:
    स्थिती TOK_ULT:
    स्थिती TOK_ULE:
    स्थिती TOK_UGT:
    स्थिती TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        थांबा;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
शून्य gen_opf(पूर्णांक op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
शून्य gen_cvt_itof(पूर्णांक t)
{
    gv(RC_ST0);
    जर (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    अन्यथा
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
शून्य gen_cvt_ftoi(पूर्णांक t)
{
    gv(RC_ST0);
    निवड(t) {
    स्थिती VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        थांबा;
    स्थिती VT_LLONG:
        out_op(IL_OP_CONV_I8);
        थांबा;
    स्थिती VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        थांबा;
    पूर्वनिर्धारित:
        out_op(IL_OP_CONV_I4);
        थांबा;
    }
}

/* convert from one floating point type to another */
शून्य gen_cvt_ftof(पूर्णांक t)
{
    gv(RC_ST0);
    जर (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } अन्यथा {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

