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

#దోషం this సంకేతం_2 has బిట్టు-rotted since 2003

/* number of available registers */
#నిర్వచించు NB_REGS             3

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#నిర్వచించు RC_ST      0x0001  /* any stack entry */
#నిర్వచించు RC_ST0     0x0002  /* top of stack */
#నిర్వచించు RC_ST1     0x0004  /* top - 1 */

#నిర్వచించు RC_INT     RC_ST
#నిర్వచించు RC_FLOAT   RC_ST
#నిర్వచించు RC_IRET    RC_ST0 /* function return: integer register */
#నిర్వచించు RC_LRET    RC_ST0 /* function return: second integer register */
#నిర్వచించు RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
గణన {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

స్థిరరాశి పూర్ణాంకం reg_classes[NB_REGS] = {
    /* ST0 */ RC_ST | RC_ST0,
    /* ST1 */ RC_ST | RC_ST1,
    /* ST2 */ RC_ST,
};

/* return registers for function */
#నిర్వచించు REG_IRET REG_ST0 /* single word int return register */
#నిర్వచించు REG_LRET REG_ST0 /* second word return register (for long long) */
#నిర్వచించు REG_FRET REG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
/* #define INVERT_FUNC_PARAMS */

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#నిర్వచించు PTR_కొలత 4

/* long double size and alignment, in bytes */
#నిర్వచించు LDOUBLE_కొలత  8
#నిర్వచించు LDOUBLE_ALIGN 8

/* function call context */
రకనిర్వచనం నిర్మాణం GFuncContext {
    పూర్ణాంకం func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#నిర్వచించు IL_OP_ఉపసర్గ 0xFE

గణన ILOPCodes {
#నిర్వచించు OP(name, str, n) IL_OP_ ## name = n,
#అన్తర్భావ "il-opcodes.h"
#నిర్వచనం_రద్దు OP
};

అక్షరం *il_opcodes_str[] = {
#నిర్వచించు OP(name, str, n) [n] = str,
#అన్తర్భావ "il-opcodes.h"
#నిర్వచనం_రద్దు OP
};

/******************************************************/

/* arguments variable numbers start from there */
#నిర్వచించు ARG_పునాది 0x70000000

స్థిర FILE *il_outfile;

స్థిర శూన్య బహిర్గతం_byte(పూర్ణాంకం c)
{
    *(అక్షరం *)ind++ = c;
}

స్థిర శూన్య బహిర్గతం_le32(పూర్ణాంకం c)
{
    బహిర్గతం_byte(c);
    బహిర్గతం_byte(c >> 8);
    బహిర్గతం_byte(c >> 16);
    బహిర్గతం_byte(c >> 24);
}

స్థిర శూన్య init_outfile(శూన్య)
{
    ఒకవేళ (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

స్థిర శూన్య బహిర్గతం_op1(పూర్ణాంకం op)
{
    ఒకవేళ (op & 0x100)
        బహిర్గతం_byte(IL_OP_ఉపసర్గ);
    బహిర్గతం_byte(op & 0xff);
}

/* output an opcode with prefix */
స్థిర శూన్య బహిర్గతం_op(పూర్ణాంకం op)
{
    బహిర్గతం_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

స్థిర శూన్య బహిర్గతం_opb(పూర్ణాంకం op, పూర్ణాంకం c)
{
    బహిర్గతం_op1(op);
    బహిర్గతం_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

స్థిర శూన్య బహిర్గతం_opi(పూర్ణాంకం op, పూర్ణాంకం c)
{
    బహిర్గతం_op1(op);
    బహిర్గతం_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
స్థిర శూన్య il_type_గమ్యం_str(అక్షరం *buf, పూర్ణాంకం buf_కొలత, 
                           పూర్ణాంకం t, స్థిరరాశి అక్షరం *varstr)
{
    పూర్ణాంకం bt;
    Sym *s, *sa;
    అక్షరం buf1[256];
    స్థిరరాశి అక్షరం *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    ఒకవేళ (t & VT_UNSIGNED)
        pstrcat(buf, buf_కొలత, "unsigned ");
    ఎంపిక(bt) {
    స్థితి VT_VOID:
        tstr = "void";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_BOOL:
        tstr = "bool";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_BYTE:
        tstr = "int8";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_SHORT:
        tstr = "int16";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_ENUM:
    స్థితి VT_INT:
    స్థితి VT_LONG:
        tstr = "int32";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_LLONG:
        tstr = "int64";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_FLOAT:
        tstr = "float32";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_DOUBLE:
    స్థితి VT_LDOUBLE:
        tstr = "float64";
    కూడు_tstr:
        pstrcat(buf, buf_కొలత, tstr);
        ఆపు;
    స్థితి VT_STRUCT:
        tcc_error("structures not handled yet");
        ఆపు;
    స్థితి VT_FUNC:
        s = sym_కనుగొను((గుర్తులేని)t >> VT_STRUCT_జరుపు);
        il_type_గమ్యం_str(buf, buf_కొలత, s->t, varstr);
        pstrcat(buf, buf_కొలత, "(");
        sa = s->తదుపరి;
        అయితే (sa != ఖాళీ) {
            il_type_గమ్యం_str(buf1, పరిమాణం(buf1), sa->t, ఖాళీ);
            pstrcat(buf, buf_కొలత, buf1);
            sa = sa->తదుపరి;
            ఒకవేళ (sa)
                pstrcat(buf, buf_కొలత, ", ");
        }
        pstrcat(buf, buf_కొలత, ")");
        వెళ్ళు no_var;
    స్థితి VT_PTR:
        s = sym_కనుగొను((గుర్తులేని)t >> VT_STRUCT_జరుపు);
        pstrcpy(buf1, పరిమాణం(buf1), "*");
        ఒకవేళ (varstr)
            pstrcat(buf1, పరిమాణం(buf1), varstr);
        il_type_గమ్యం_str(buf, buf_కొలత, s->t, buf1);
        వెళ్ళు no_var;
    }
    ఒకవేళ (varstr) {
        pstrcat(buf, buf_కొలత, " ");
        pstrcat(buf, buf_కొలత, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
శూన్య greloc_patch1(Reloc *p, పూర్ణాంకం val)
{
}

/* output a symbol and patch all calls to it */
శూన్య gsym_addr(t, a)
{
}

/* output jump and return symbol */
స్థిర పూర్ణాంకం బహిర్గతం_opj(పూర్ణాంకం op, పూర్ణాంకం c)
{
    బహిర్గతం_op1(op);
    బహిర్గతం_le32(0);
    ఒకవేళ (c == 0) {
        c = ind - (పూర్ణాంకం)cur_పాఠ్యం_section->దత్తాంశం;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    తిరిగి c;
}

శూన్య gsym(పూర్ణాంకం t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
శూన్య ఎక్కించు(పూర్ణాంకం r, SValue *sv)
{
    పూర్ణాంకం v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    ఒకవేళ (sv->r & VT_LVAL) {
        ఒకవేళ (v == VT_LOCAL) {
            ఒకవేళ (fc >= ARG_పునాది) {
                fc -= ARG_పునాది;
                ఒకవేళ (fc >= 0 && fc <= 4) {
                    బహిర్గతం_op(IL_OP_LDARG_0 + fc);
                } లేకపోతే ఒకవేళ (fc <= 0xff) {
                    బహిర్గతం_opb(IL_OP_LDARG_S, fc);
                } లేకపోతే {
                    బహిర్గతం_opi(IL_OP_LDARG, fc);
                }
            } లేకపోతే {
                ఒకవేళ (fc >= 0 && fc <= 4) {
                    బహిర్గతం_op(IL_OP_LDLOC_0 + fc);
                } లేకపోతే ఒకవేళ (fc <= 0xff) {
                    బహిర్గతం_opb(IL_OP_LDLOC_S, fc);
                } లేకపోతే {
                    బహిర్గతం_opi(IL_OP_LDLOC, fc);
                }
            }
        } లేకపోతే ఒకవేళ (v == VT_CONST) {
                /* XXX: handle globals */
                బహిర్గతం_opi(IL_OP_LDSFLD, 0);
        } లేకపోతే {
            ఒకవేళ ((ft & VT_BTYPE) == VT_FLOAT) {
                బహిర్గతం_op(IL_OP_LDIND_R4);
            } లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_DOUBLE) {
                బహిర్గతం_op(IL_OP_LDIND_R8);
            } లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_LDOUBLE) {
                బహిర్గతం_op(IL_OP_LDIND_R8);
            } లేకపోతే ఒకవేళ ((ft & VT_TYPE) == VT_BYTE)
                బహిర్గతం_op(IL_OP_LDIND_I1);
            లేకపోతే ఒకవేళ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                బహిర్గతం_op(IL_OP_LDIND_U1);
            లేకపోతే ఒకవేళ ((ft & VT_TYPE) == VT_SHORT)
                బహిర్గతం_op(IL_OP_LDIND_I2);
            లేకపోతే ఒకవేళ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                బహిర్గతం_op(IL_OP_LDIND_U2);
            లేకపోతే
                బహిర్గతం_op(IL_OP_LDIND_I4);
        } 
    } లేకపోతే {
        ఒకవేళ (v == VT_CONST) {
            /* XXX: handle globals */
            ఒకవేళ (fc >= -1 && fc <= 8) {
                బహిర్గతం_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } లేకపోతే {
                బహిర్గతం_opi(IL_OP_LDC_I4, fc);
            }
        } లేకపోతే ఒకవేళ (v == VT_LOCAL) {
            ఒకవేళ (fc >= ARG_పునాది) {
                fc -= ARG_పునాది;
                ఒకవేళ (fc <= 0xff) {
                    బహిర్గతం_opb(IL_OP_LDARGA_S, fc);
                } లేకపోతే {
                    బహిర్గతం_opi(IL_OP_LDARGA, fc);
                }
            } లేకపోతే {
                ఒకవేళ (fc <= 0xff) {
                    బహిర్గతం_opb(IL_OP_LDLOCA_S, fc);
                } లేకపోతే {
                    బహిర్గతం_opi(IL_OP_LDLOCA, fc);
                }
            }
        } లేకపోతే {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
శూన్య store(పూర్ణాంకం r, SValue *sv)
{
    పూర్ణాంకం v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    ఒకవేళ (v == VT_LOCAL) {
        ఒకవేళ (fc >= ARG_పునాది) {
            fc -= ARG_పునాది;
            /* XXX: check IL arg store semantics */
            ఒకవేళ (fc <= 0xff) {
                బహిర్గతం_opb(IL_OP_STARG_S, fc);
            } లేకపోతే {
                బహిర్గతం_opi(IL_OP_STARG, fc);
            }
        } లేకపోతే {
            ఒకవేళ (fc >= 0 && fc <= 4) {
                బహిర్గతం_op(IL_OP_STLOC_0 + fc);
            } లేకపోతే ఒకవేళ (fc <= 0xff) {
                బహిర్గతం_opb(IL_OP_STLOC_S, fc);
            } లేకపోతే {
                బహిర్గతం_opi(IL_OP_STLOC, fc);
            }
        }
    } లేకపోతే ఒకవేళ (v == VT_CONST) {
        /* XXX: handle globals */
        బహిర్గతం_opi(IL_OP_STSFLD, 0);
    } లేకపోతే {
        ఒకవేళ ((ft & VT_BTYPE) == VT_FLOAT)
            బహిర్గతం_op(IL_OP_STIND_R4);
        లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_DOUBLE)
            బహిర్గతం_op(IL_OP_STIND_R8);
        లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_LDOUBLE)
            బహిర్గతం_op(IL_OP_STIND_R8);
        లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_BYTE)
            బహిర్గతం_op(IL_OP_STIND_I1);
        లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_SHORT)
            బహిర్గతం_op(IL_OP_STIND_I2);
        లేకపోతే
            బహిర్గతం_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
శూన్య gfunc_ప్రారంభం(GFuncContext *c, పూర్ణాంకం func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
శూన్య gfunc_param(GFuncContext *c)
{
    ఒకవేళ ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } లేకపోతే {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
శూన్య gfunc_call(GFuncContext *c)
{
    అక్షరం buf[1024];

    ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_గమ్యం_str(buf, పరిమాణం(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } లేకపోతే {
        /* indirect call */
        gv(RC_INT);
        il_type_గమ్యం_str(buf, పరిమాణం(buf), vtop->t, ఖాళీ);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
శూన్య gfunc_prolog(పూర్ణాంకం t)
{
    పూర్ణాంకం addr, u, func_call;
    Sym *sym;
    అక్షరం buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_గమ్యం_str(buf, పరిమాణం(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    ఒకవేళ (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_కనుగొను((గుర్తులేని)t >> VT_STRUCT_జరుపు);
    func_call = sym->r;

    addr = ARG_పునాది;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    ఒకవేళ ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    అయితే ((sym = sym->తదుపరి) != ఖాళీ) {
        u = sym->t;
        sym_నెట్టు(sym->v & ~SYM_క్షేత్రం, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
శూన్య gfunc_epilog(శూన్య)
{
    బహిర్గతం_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
పూర్ణాంకం gjmp(పూర్ణాంకం t)
{
    తిరిగి బహిర్గతం_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
శూన్య gjmp_addr(పూర్ణాంకం a)
{
    /* XXX: handle syms */
    బహిర్గతం_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
పూర్ణాంకం gtst(పూర్ణాంకం inv, పూర్ణాంకం t)
{
    పూర్ణాంకం v, *p, c;

    v = vtop->r & VT_VALMASK;
    ఒకవేళ (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        ఎంపిక(c) {
        స్థితి TOK_EQ:
            c = IL_OP_BEQ;
            ఆపు;
        స్థితి TOK_NE:
            c = IL_OP_BNE_UN;
            ఆపు;
        స్థితి TOK_LT:
            c = IL_OP_BLT;
            ఆపు;
        స్థితి TOK_LE:
            c = IL_OP_BLE;
            ఆపు;
        స్థితి TOK_GT:
            c = IL_OP_BGT;
            ఆపు;
        స్థితి TOK_GE:
            c = IL_OP_BGE;
            ఆపు;
        స్థితి TOK_ULT:
            c = IL_OP_BLT_UN;
            ఆపు;
        స్థితి TOK_ULE:
            c = IL_OP_BLE_UN;
            ఆపు;
        స్థితి TOK_UGT:
            c = IL_OP_BGT_UN;
            ఆపు;
        స్థితి TOK_UGE:
            c = IL_OP_BGE_UN;
            ఆపు;
        }
        t = బహిర్గతం_opj(c, t);
    } లేకపోతే ఒకవేళ (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        ఒకవేళ ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            అయితే (*p != 0)
                p = (పూర్ణాంకం *)*p;
            *p = t;
            t = vtop->c.i;
        } లేకపోతే {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    తిరిగి t;
}

/* generate an integer binary operation */
శూన్య gen_opi(పూర్ణాంకం op)
{
    gv2(RC_ST1, RC_ST0);
    ఎంపిక(op) {
    స్థితి '+':
        బహిర్గతం_op(IL_OP_కూడు);
        వెళ్ళు std_op;
    స్థితి '-':
        బహిర్గతం_op(IL_OP_SUB);
        వెళ్ళు std_op;
    స్థితి '&':
        బహిర్గతం_op(IL_OP_AND);
        వెళ్ళు std_op;
    స్థితి '^':
        బహిర్గతం_op(IL_OP_XOR);
        వెళ్ళు std_op;
    స్థితి '|':
        బహిర్గతం_op(IL_OP_OR);
        వెళ్ళు std_op;
    స్థితి '*':
        బహిర్గతం_op(IL_OP_MUL);
        వెళ్ళు std_op;
    స్థితి TOK_SHL:
        బహిర్గతం_op(IL_OP_SHL);
        వెళ్ళు std_op;
    స్థితి TOK_SHR:
        బహిర్గతం_op(IL_OP_SHR_UN);
        వెళ్ళు std_op;
    స్థితి TOK_SAR:
        బహిర్గతం_op(IL_OP_SHR);
        వెళ్ళు std_op;
    స్థితి '/':
    స్థితి TOK_PDIV:
        బహిర్గతం_op(IL_OP_DIV);
        వెళ్ళు std_op;
    స్థితి TOK_UDIV:
        బహిర్గతం_op(IL_OP_DIV_UN);
        వెళ్ళు std_op;
    స్థితి '%':
        బహిర్గతం_op(IL_OP_REM);
        వెళ్ళు std_op;
    స్థితి TOK_UMOD:
        బహిర్గతం_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        ఆపు;
    స్థితి TOK_EQ:
    స్థితి TOK_NE:
    స్థితి TOK_LT:
    స్థితి TOK_LE:
    స్థితి TOK_GT:
    స్థితి TOK_GE:
    స్థితి TOK_ULT:
    స్థితి TOK_ULE:
    స్థితి TOK_UGT:
    స్థితి TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        ఆపు;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
శూన్య gen_opf(పూర్ణాంకం op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
శూన్య gen_cvt_itof(పూర్ణాంకం t)
{
    gv(RC_ST0);
    ఒకవేళ (t == VT_FLOAT)
        బహిర్గతం_op(IL_OP_CONV_R4);
    లేకపోతే
        బహిర్గతం_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
శూన్య gen_cvt_ftoi(పూర్ణాంకం t)
{
    gv(RC_ST0);
    ఎంపిక(t) {
    స్థితి VT_INT | VT_UNSIGNED:
        బహిర్గతం_op(IL_OP_CONV_U4);
        ఆపు;
    స్థితి VT_LLONG:
        బహిర్గతం_op(IL_OP_CONV_I8);
        ఆపు;
    స్థితి VT_LLONG | VT_UNSIGNED:
        బహిర్గతం_op(IL_OP_CONV_U8);
        ఆపు;
    అప్రమేయ:
        బహిర్గతం_op(IL_OP_CONV_I4);
        ఆపు;
    }
}

/* convert from one floating point type to another */
శూన్య gen_cvt_ftof(పూర్ణాంకం t)
{
    gv(RC_ST0);
    ఒకవేళ (t == VT_FLOAT) {
        బహిర్గతం_op(IL_OP_CONV_R4);
    } లేకపోతే {
        బహిర్గతం_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

