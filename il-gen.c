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

#दोषः this संहिता has bit-rotted since 2003

/* number of available registers */
#परिभाषय NB_REGS             3

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#परिभाषय RC_ST      0x0001  /* any stack entry */
#परिभाषय RC_ST0     0x0002  /* top of stack */
#परिभाषय RC_ST1     0x0004  /* top - 1 */

#परिभाषय RC_INT     RC_ST
#परिभाषय RC_FLOAT   RC_ST
#परिभाषय RC_IRET    RC_ST0 /* function return: integer register */
#परिभाषय RC_LRET    RC_ST0 /* function return: second integer register */
#परिभाषय RC_FRET    RC_ST0 /* function return: float register */

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
#परिभाषय REG_IRET REG_ST0 /* single word int return register */
#परिभाषय REG_LRET REG_ST0 /* second word return register (for long long) */
#परिभाषय REG_FRET REG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
/* #define INVERT_FUNC_PARAMS */

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#परिभाषय PTR_आकार 4

/* long double size and alignment, in bytes */
#परिभाषय LDOUBLE_आकार  8
#परिभाषय LDOUBLE_ALIGN 8

/* function call context */
प्रकारनिर्देश संरचना GFuncContext {
    पूर्णाङ्क func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#परिभाषय IL_OP_उपसर्गः 0xFE

गणना ILOPCodes {
#परिभाषय OP(name, str, n) IL_OP_ ## name = n,
#अन्तर्भाव "il-opcodes.h"
#अपरिभाषय OP
};

वर्ण *il_opcodes_str[] = {
#परिभाषय OP(name, str, n) [n] = str,
#अन्तर्भाव "il-opcodes.h"
#अपरिभाषय OP
};

/******************************************************/

/* arguments variable numbers start from there */
#परिभाषय ARG_आधारः 0x70000000

स्थिर FILE *il_outfile;

स्थिर शून्य बहिर्गमनम्_byte(पूर्णाङ्क c)
{
    *(वर्ण *)ind++ = c;
}

स्थिर शून्य बहिर्गमनम्_le32(पूर्णाङ्क c)
{
    बहिर्गमनम्_byte(c);
    बहिर्गमनम्_byte(c >> 8);
    बहिर्गमनम्_byte(c >> 16);
    बहिर्गमनम्_byte(c >> 24);
}

स्थिर शून्य init_outfile(शून्य)
{
    यदि (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

स्थिर शून्य बहिर्गमनम्_op1(पूर्णाङ्क op)
{
    यदि (op & 0x100)
        बहिर्गमनम्_byte(IL_OP_उपसर्गः);
    बहिर्गमनम्_byte(op & 0xff);
}

/* output an opcode with prefix */
स्थिर शून्य बहिर्गमनम्_op(पूर्णाङ्क op)
{
    बहिर्गमनम्_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

स्थिर शून्य बहिर्गमनम्_opb(पूर्णाङ्क op, पूर्णाङ्क c)
{
    बहिर्गमनम्_op1(op);
    बहिर्गमनम्_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

स्थिर शून्य बहिर्गमनम्_opi(पूर्णाङ्क op, पूर्णाङ्क c)
{
    बहिर्गमनम्_op1(op);
    बहिर्गमनम्_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
स्थिर शून्य il_type_गन्तव्यम्_str(वर्ण *buf, पूर्णाङ्क buf_आकार, 
                           पूर्णाङ्क t, ध्रुव वर्ण *varstr)
{
    पूर्णाङ्क bt;
    Sym *s, *sa;
    वर्ण buf1[256];
    ध्रुव वर्ण *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    यदि (t & VT_UNSIGNED)
        pstrcat(buf, buf_आकार, "unsigned ");
    विकल्प(bt) {
    पक्ष VT_VOID:
        tstr = "void";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_BOOL:
        tstr = "bool";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_BYTE:
        tstr = "int8";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_SHORT:
        tstr = "int16";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_ENUM:
    पक्ष VT_INT:
    पक्ष VT_LONG:
        tstr = "int32";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_LLONG:
        tstr = "int64";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_FLOAT:
        tstr = "float32";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_DOUBLE:
    पक्ष VT_LDOUBLE:
        tstr = "float64";
    सङ्कलय_tstr:
        pstrcat(buf, buf_आकार, tstr);
        भङ्ग;
    पक्ष VT_STRUCT:
        tcc_error("structures not handled yet");
        भङ्ग;
    पक्ष VT_FUNC:
        s = sym_find((अचिह्नित)t >> VT_STRUCT_सरणम्);
        il_type_गन्तव्यम्_str(buf, buf_आकार, s->t, varstr);
        pstrcat(buf, buf_आकार, "(");
        sa = s->अग्र;
        यावत् (sa != रिक्त) {
            il_type_गन्तव्यम्_str(buf1, परिमाण(buf1), sa->t, रिक्त);
            pstrcat(buf, buf_आकार, buf1);
            sa = sa->अग्र;
            यदि (sa)
                pstrcat(buf, buf_आकार, ", ");
        }
        pstrcat(buf, buf_आकार, ")");
        गच्छ no_var;
    पक्ष VT_PTR:
        s = sym_find((अचिह्नित)t >> VT_STRUCT_सरणम्);
        pstrcpy(buf1, परिमाण(buf1), "*");
        यदि (varstr)
            pstrcat(buf1, परिमाण(buf1), varstr);
        il_type_गन्तव्यम्_str(buf, buf_आकार, s->t, buf1);
        गच्छ no_var;
    }
    यदि (varstr) {
        pstrcat(buf, buf_आकार, " ");
        pstrcat(buf, buf_आकार, varstr);
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
स्थिर पूर्णाङ्क बहिर्गमनम्_opj(पूर्णाङ्क op, पूर्णाङ्क c)
{
    बहिर्गमनम्_op1(op);
    बहिर्गमनम्_le32(0);
    यदि (c == 0) {
        c = ind - (पूर्णाङ्क)cur_text_section->दत्त;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    प्रत्यागम c;
}

शून्य gsym(पूर्णाङ्क t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
शून्य आरोपय(पूर्णाङ्क r, SValue *sv)
{
    पूर्णाङ्क v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    यदि (sv->r & VT_LVAL) {
        यदि (v == VT_LOCAL) {
            यदि (fc >= ARG_आधारः) {
                fc -= ARG_आधारः;
                यदि (fc >= 0 && fc <= 4) {
                    बहिर्गमनम्_op(IL_OP_LDARG_0 + fc);
                } अन्यथा यदि (fc <= 0xff) {
                    बहिर्गमनम्_opb(IL_OP_LDARG_S, fc);
                } अन्यथा {
                    बहिर्गमनम्_opi(IL_OP_LDARG, fc);
                }
            } अन्यथा {
                यदि (fc >= 0 && fc <= 4) {
                    बहिर्गमनम्_op(IL_OP_LDLOC_0 + fc);
                } अन्यथा यदि (fc <= 0xff) {
                    बहिर्गमनम्_opb(IL_OP_LDLOC_S, fc);
                } अन्यथा {
                    बहिर्गमनम्_opi(IL_OP_LDLOC, fc);
                }
            }
        } अन्यथा यदि (v == VT_CONST) {
                /* XXX: handle globals */
                बहिर्गमनम्_opi(IL_OP_LDSFLD, 0);
        } अन्यथा {
            यदि ((ft & VT_BTYPE) == VT_FLOAT) {
                बहिर्गमनम्_op(IL_OP_LDIND_R4);
            } अन्यथा यदि ((ft & VT_BTYPE) == VT_DOUBLE) {
                बहिर्गमनम्_op(IL_OP_LDIND_R8);
            } अन्यथा यदि ((ft & VT_BTYPE) == VT_LDOUBLE) {
                बहिर्गमनम्_op(IL_OP_LDIND_R8);
            } अन्यथा यदि ((ft & VT_TYPE) == VT_BYTE)
                बहिर्गमनम्_op(IL_OP_LDIND_I1);
            अन्यथा यदि ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                बहिर्गमनम्_op(IL_OP_LDIND_U1);
            अन्यथा यदि ((ft & VT_TYPE) == VT_SHORT)
                बहिर्गमनम्_op(IL_OP_LDIND_I2);
            अन्यथा यदि ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                बहिर्गमनम्_op(IL_OP_LDIND_U2);
            अन्यथा
                बहिर्गमनम्_op(IL_OP_LDIND_I4);
        } 
    } अन्यथा {
        यदि (v == VT_CONST) {
            /* XXX: handle globals */
            यदि (fc >= -1 && fc <= 8) {
                बहिर्गमनम्_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } अन्यथा {
                बहिर्गमनम्_opi(IL_OP_LDC_I4, fc);
            }
        } अन्यथा यदि (v == VT_LOCAL) {
            यदि (fc >= ARG_आधारः) {
                fc -= ARG_आधारः;
                यदि (fc <= 0xff) {
                    बहिर्गमनम्_opb(IL_OP_LDARGA_S, fc);
                } अन्यथा {
                    बहिर्गमनम्_opi(IL_OP_LDARGA, fc);
                }
            } अन्यथा {
                यदि (fc <= 0xff) {
                    बहिर्गमनम्_opb(IL_OP_LDLOCA_S, fc);
                } अन्यथा {
                    बहिर्गमनम्_opi(IL_OP_LDLOCA, fc);
                }
            }
        } अन्यथा {
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
    यदि (v == VT_LOCAL) {
        यदि (fc >= ARG_आधारः) {
            fc -= ARG_आधारः;
            /* XXX: check IL arg store semantics */
            यदि (fc <= 0xff) {
                बहिर्गमनम्_opb(IL_OP_STARG_S, fc);
            } अन्यथा {
                बहिर्गमनम्_opi(IL_OP_STARG, fc);
            }
        } अन्यथा {
            यदि (fc >= 0 && fc <= 4) {
                बहिर्गमनम्_op(IL_OP_STLOC_0 + fc);
            } अन्यथा यदि (fc <= 0xff) {
                बहिर्गमनम्_opb(IL_OP_STLOC_S, fc);
            } अन्यथा {
                बहिर्गमनम्_opi(IL_OP_STLOC, fc);
            }
        }
    } अन्यथा यदि (v == VT_CONST) {
        /* XXX: handle globals */
        बहिर्गमनम्_opi(IL_OP_STSFLD, 0);
    } अन्यथा {
        यदि ((ft & VT_BTYPE) == VT_FLOAT)
            बहिर्गमनम्_op(IL_OP_STIND_R4);
        अन्यथा यदि ((ft & VT_BTYPE) == VT_DOUBLE)
            बहिर्गमनम्_op(IL_OP_STIND_R8);
        अन्यथा यदि ((ft & VT_BTYPE) == VT_LDOUBLE)
            बहिर्गमनम्_op(IL_OP_STIND_R8);
        अन्यथा यदि ((ft & VT_BTYPE) == VT_BYTE)
            बहिर्गमनम्_op(IL_OP_STIND_I1);
        अन्यथा यदि ((ft & VT_BTYPE) == VT_SHORT)
            बहिर्गमनम्_op(IL_OP_STIND_I2);
        अन्यथा
            बहिर्गमनम्_op(IL_OP_STIND_I4);
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
    यदि ((vtop->t & VT_BTYPE) == VT_STRUCT) {
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
    वर्ण buf[1024];

    यदि ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_गन्तव्यम्_str(buf, परिमाण(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } अन्यथा {
        /* indirect call */
        gv(RC_INT);
        il_type_गन्तव्यम्_str(buf, परिमाण(buf), vtop->t, रिक्त);
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
    il_type_गन्तव्यम्_str(buf, परिमाण(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    यदि (!वाक्यं_तुलय(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_find((अचिह्नित)t >> VT_STRUCT_सरणम्);
    func_call = sym->r;

    addr = ARG_आधारः;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    यदि ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    यावत् ((sym = sym->अग्र) != रिक्त) {
        u = sym->t;
        sym_प्रक्षिप(sym->v & ~SYM_क्षेत्रम्, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
शून्य gfunc_epilog(शून्य)
{
    बहिर्गमनम्_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
पूर्णाङ्क gjmp(पूर्णाङ्क t)
{
    प्रत्यागम बहिर्गमनम्_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
शून्य gjmp_addr(पूर्णाङ्क a)
{
    /* XXX: handle syms */
    बहिर्गमनम्_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
पूर्णाङ्क gtst(पूर्णाङ्क inv, पूर्णाङ्क t)
{
    पूर्णाङ्क v, *p, c;

    v = vtop->r & VT_VALMASK;
    यदि (v == VT_CMP) {
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
        t = बहिर्गमनम्_opj(c, t);
    } अन्यथा यदि (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        यदि ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            यावत् (*p != 0)
                p = (पूर्णाङ्क *)*p;
            *p = t;
            t = vtop->c.i;
        } अन्यथा {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    प्रत्यागम t;
}

/* generate an integer binary operation */
शून्य gen_opi(पूर्णाङ्क op)
{
    gv2(RC_ST1, RC_ST0);
    विकल्प(op) {
    पक्ष '+':
        बहिर्गमनम्_op(IL_OP_सङ्कलय);
        गच्छ std_op;
    पक्ष '-':
        बहिर्गमनम्_op(IL_OP_SUB);
        गच्छ std_op;
    पक्ष '&':
        बहिर्गमनम्_op(IL_OP_AND);
        गच्छ std_op;
    पक्ष '^':
        बहिर्गमनम्_op(IL_OP_XOR);
        गच्छ std_op;
    पक्ष '|':
        बहिर्गमनम्_op(IL_OP_OR);
        गच्छ std_op;
    पक्ष '*':
        बहिर्गमनम्_op(IL_OP_MUL);
        गच्छ std_op;
    पक्ष TOK_SHL:
        बहिर्गमनम्_op(IL_OP_SHL);
        गच्छ std_op;
    पक्ष TOK_SHR:
        बहिर्गमनम्_op(IL_OP_SHR_UN);
        गच्छ std_op;
    पक्ष TOK_SAR:
        बहिर्गमनम्_op(IL_OP_SHR);
        गच्छ std_op;
    पक्ष '/':
    पक्ष TOK_PDIV:
        बहिर्गमनम्_op(IL_OP_DIV);
        गच्छ std_op;
    पक्ष TOK_UDIV:
        बहिर्गमनम्_op(IL_OP_DIV_UN);
        गच्छ std_op;
    पक्ष '%':
        बहिर्गमनम्_op(IL_OP_REM);
        गच्छ std_op;
    पक्ष TOK_UMOD:
        बहिर्गमनम्_op(IL_OP_REM_UN);
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
    यदि (t == VT_FLOAT)
        बहिर्गमनम्_op(IL_OP_CONV_R4);
    अन्यथा
        बहिर्गमनम्_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
शून्य gen_cvt_ftoi(पूर्णाङ्क t)
{
    gv(RC_ST0);
    विकल्प(t) {
    पक्ष VT_INT | VT_UNSIGNED:
        बहिर्गमनम्_op(IL_OP_CONV_U4);
        भङ्ग;
    पक्ष VT_LLONG:
        बहिर्गमनम्_op(IL_OP_CONV_I8);
        भङ्ग;
    पक्ष VT_LLONG | VT_UNSIGNED:
        बहिर्गमनम्_op(IL_OP_CONV_U8);
        भङ्ग;
    स्वभाव:
        बहिर्गमनम्_op(IL_OP_CONV_I4);
        भङ्ग;
    }
}

/* convert from one floating point type to another */
शून्य gen_cvt_ftof(पूर्णाङ्क t)
{
    gv(RC_ST0);
    यदि (t == VT_FLOAT) {
        बहिर्गमनम्_op(IL_OP_CONV_R4);
    } अन्यथा {
        बहिर्गमनम्_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

