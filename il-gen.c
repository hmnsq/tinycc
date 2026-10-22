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
ગણના {
    REG_ST0 = 0,
    REG_ST1,
    REG_ST2,
};

અચલ પૂર્ણાંક reg_classes[NB_REGS] = {
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
પ્રકારવ્યાખ્યા સંરચના GFuncContext {
    પૂર્ણાંક func_call; /* func call type (FUNC_STDCALL or FUNC_CDECL) */
} GFuncContext;

/******************************************************/
/* opcode definitions */

#define IL_OP_PREFIX 0xFE

ગણના ILOPCodes {
#define OP(name, str, n) IL_OP_ ## name = n,
#અન્તર્ભાવ "il-opcodes.h"
#undef OP
};

અક્ષર *il_opcodes_str[] = {
#define OP(name, str, n) [n] = str,
#અન્તર્ભાવ "il-opcodes.h"
#undef OP
};

/******************************************************/

/* arguments variable numbers start from there */
#define ARG_BASE 0x70000000

સ્થિર FILE *il_outfile;

સ્થિર શૂન્ય out_byte(પૂર્ણાંક c)
{
    *(અક્ષર *)ind++ = c;
}

સ્થિર શૂન્ય out_le32(પૂર્ણાંક c)
{
    out_byte(c);
    out_byte(c >> 8);
    out_byte(c >> 16);
    out_byte(c >> 24);
}

સ્થિર શૂન્ય init_outfile(શૂન્ય)
{
    જો (!il_outfile) {
        il_outfile = stdout;
        fprintf(il_outfile, 
                ".assembly extern mscorlib\n"
                "{\n"
                ".ver 1:0:2411:0\n"
                "}\n\n");
    }
}

સ્થિર શૂન્ય out_op1(પૂર્ણાંક op)
{
    જો (op & 0x100)
        out_byte(IL_OP_PREFIX);
    out_byte(op & 0xff);
}

/* output an opcode with prefix */
સ્થિર શૂન્ય out_op(પૂર્ણાંક op)
{
    out_op1(op);
    fprintf(il_outfile, " %s\n", il_opcodes_str[op]);
}

સ્થિર શૂન્ય out_opb(પૂર્ણાંક op, પૂર્ણાંક c)
{
    out_op1(op);
    out_byte(c);
    fprintf(il_outfile, " %s %d\n", il_opcodes_str[op], c);
}

સ્થિર શૂન્ય out_opi(પૂર્ણાંક op, પૂર્ણાંક c)
{
    out_op1(op);
    out_le32(c);
    fprintf(il_outfile, " %s 0x%x\n", il_opcodes_str[op], c);
}

/* XXX: not complete */
સ્થિર શૂન્ય il_type_to_str(અક્ષર *buf, પૂર્ણાંક buf_size, 
                           પૂર્ણાંક t, અચલ અક્ષર *varstr)
{
    પૂર્ણાંક bt;
    Sym *s, *sa;
    અક્ષર buf1[256];
    અચલ અક્ષર *tstr;

    t = t & VT_TYPE;
    bt = t & VT_BTYPE;
    buf[0] = '\0';
    જો (t & VT_UNSIGNED)
        pstrcat(buf, buf_size, "unsigned ");
    પસંદગી(bt) {
    સ્થિતિ VT_VOID:
        tstr = "void";
        જાઓ add_tstr;
    સ્થિતિ VT_BOOL:
        tstr = "bool";
        જાઓ add_tstr;
    સ્થિતિ VT_BYTE:
        tstr = "int8";
        જાઓ add_tstr;
    સ્થિતિ VT_SHORT:
        tstr = "int16";
        જાઓ add_tstr;
    સ્થિતિ VT_ENUM:
    સ્થિતિ VT_INT:
    સ્થિતિ VT_LONG:
        tstr = "int32";
        જાઓ add_tstr;
    સ્થિતિ VT_LLONG:
        tstr = "int64";
        જાઓ add_tstr;
    સ્થિતિ VT_FLOAT:
        tstr = "float32";
        જાઓ add_tstr;
    સ્થિતિ VT_DOUBLE:
    સ્થિતિ VT_LDOUBLE:
        tstr = "float64";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        તોડો;
    સ્થિતિ VT_STRUCT:
        tcc_error("structures not handled yet");
        તોડો;
    સ્થિતિ VT_FUNC:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        il_type_to_str(buf, buf_size, s->t, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        જ્યારે (sa != ખાલી) {
            il_type_to_str(buf1, કદ(buf1), sa->t, ખાલી);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            જો (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        જાઓ no_var;
    સ્થિતિ VT_PTR:
        s = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
        pstrcpy(buf1, કદ(buf1), "*");
        જો (varstr)
            pstrcat(buf1, કદ(buf1), varstr);
        il_type_to_str(buf, buf_size, s->t, buf1);
        જાઓ no_var;
    }
    જો (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}


/* patch relocation entry with value 'val' */
શૂન્ય greloc_patch1(Reloc *p, પૂર્ણાંક val)
{
}

/* output a symbol and patch all calls to it */
શૂન્ય gsym_addr(t, a)
{
}

/* output jump and return symbol */
સ્થિર પૂર્ણાંક out_opj(પૂર્ણાંક op, પૂર્ણાંક c)
{
    out_op1(op);
    out_le32(0);
    જો (c == 0) {
        c = ind - (પૂર્ણાંક)cur_text_section->data;
    }
    fprintf(il_outfile, " %s L%d\n", il_opcodes_str[op], c);
    પાછા c;
}

શૂન્ય gsym(પૂર્ણાંક t)
{
    fprintf(il_outfile, "L%d:\n", t);
}

/* load 'r' from value 'sv' */
શૂન્ય load(પૂર્ણાંક r, SValue *sv)
{
    પૂર્ણાંક v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;

    જો (sv->r & VT_LVAL) {
        જો (v == VT_LOCAL) {
            જો (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                જો (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDARG_0 + fc);
                } નહીંતર જો (fc <= 0xff) {
                    out_opb(IL_OP_LDARG_S, fc);
                } નહીંતર {
                    out_opi(IL_OP_LDARG, fc);
                }
            } નહીંતર {
                જો (fc >= 0 && fc <= 4) {
                    out_op(IL_OP_LDLOC_0 + fc);
                } નહીંતર જો (fc <= 0xff) {
                    out_opb(IL_OP_LDLOC_S, fc);
                } નહીંતર {
                    out_opi(IL_OP_LDLOC, fc);
                }
            }
        } નહીંતર જો (v == VT_CONST) {
                /* XXX: handle globals */
                out_opi(IL_OP_LDSFLD, 0);
        } નહીંતર {
            જો ((ft & VT_BTYPE) == VT_FLOAT) {
                out_op(IL_OP_LDIND_R4);
            } નહીંતર જો ((ft & VT_BTYPE) == VT_DOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } નહીંતર જો ((ft & VT_BTYPE) == VT_LDOUBLE) {
                out_op(IL_OP_LDIND_R8);
            } નહીંતર જો ((ft & VT_TYPE) == VT_BYTE)
                out_op(IL_OP_LDIND_I1);
            નહીંતર જો ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U1);
            નહીંતર જો ((ft & VT_TYPE) == VT_SHORT)
                out_op(IL_OP_LDIND_I2);
            નહીંતર જો ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED))
                out_op(IL_OP_LDIND_U2);
            નહીંતર
                out_op(IL_OP_LDIND_I4);
        } 
    } નહીંતર {
        જો (v == VT_CONST) {
            /* XXX: handle globals */
            જો (fc >= -1 && fc <= 8) {
                out_op(IL_OP_LDC_I4_M1 + fc + 1); 
            } નહીંતર {
                out_opi(IL_OP_LDC_I4, fc);
            }
        } નહીંતર જો (v == VT_LOCAL) {
            જો (fc >= ARG_BASE) {
                fc -= ARG_BASE;
                જો (fc <= 0xff) {
                    out_opb(IL_OP_LDARGA_S, fc);
                } નહીંતર {
                    out_opi(IL_OP_LDARGA, fc);
                }
            } નહીંતર {
                જો (fc <= 0xff) {
                    out_opb(IL_OP_LDLOCA_S, fc);
                } નહીંતર {
                    out_opi(IL_OP_LDLOCA, fc);
                }
            }
        } નહીંતર {
            /* XXX: do it */
        }
    }
}

/* store register 'r' in lvalue 'v' */
શૂન્ય store(પૂર્ણાંક r, SValue *sv)
{
    પૂર્ણાંક v, fc, ft;

    v = sv->r & VT_VALMASK;
    fc = sv->c.i;
    ft = sv->t;
    જો (v == VT_LOCAL) {
        જો (fc >= ARG_BASE) {
            fc -= ARG_BASE;
            /* XXX: check IL arg store semantics */
            જો (fc <= 0xff) {
                out_opb(IL_OP_STARG_S, fc);
            } નહીંતર {
                out_opi(IL_OP_STARG, fc);
            }
        } નહીંતર {
            જો (fc >= 0 && fc <= 4) {
                out_op(IL_OP_STLOC_0 + fc);
            } નહીંતર જો (fc <= 0xff) {
                out_opb(IL_OP_STLOC_S, fc);
            } નહીંતર {
                out_opi(IL_OP_STLOC, fc);
            }
        }
    } નહીંતર જો (v == VT_CONST) {
        /* XXX: handle globals */
        out_opi(IL_OP_STSFLD, 0);
    } નહીંતર {
        જો ((ft & VT_BTYPE) == VT_FLOAT)
            out_op(IL_OP_STIND_R4);
        નહીંતર જો ((ft & VT_BTYPE) == VT_DOUBLE)
            out_op(IL_OP_STIND_R8);
        નહીંતર જો ((ft & VT_BTYPE) == VT_LDOUBLE)
            out_op(IL_OP_STIND_R8);
        નહીંતર જો ((ft & VT_BTYPE) == VT_BYTE)
            out_op(IL_OP_STIND_I1);
        નહીંતર જો ((ft & VT_BTYPE) == VT_SHORT)
            out_op(IL_OP_STIND_I2);
        નહીંતર
            out_op(IL_OP_STIND_I4);
    }
}

/* start function call and return function call context */
શૂન્ય gfunc_start(GFuncContext *c, પૂર્ણાંક func_call)
{
    c->func_call = func_call;
}

/* push function parameter which is in (vtop->t, vtop->c). Stack entry
   is then popped. */
શૂન્ય gfunc_param(GFuncContext *c)
{
    જો ((vtop->t & VT_BTYPE) == VT_STRUCT) {
        tcc_error("structures passed as value not handled yet");
    } નહીંતર {
        /* simply push on stack */
        gv(RC_ST0);
    }
    vtop--;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
શૂન્ય gfunc_call(GFuncContext *c)
{
    અક્ષર buf[1024];

    જો ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        /* XXX: more info needed from tcc */
        il_type_to_str(buf, કદ(buf), vtop->t, "xxx");
        fprintf(il_outfile, " call %s\n", buf);
    } નહીંતર {
        /* indirect call */
        gv(RC_INT);
        il_type_to_str(buf, કદ(buf), vtop->t, ખાલી);
        fprintf(il_outfile, " calli %s\n", buf);
    }
    vtop--;
}

/* generate function prolog of type 't' */
શૂન્ય gfunc_prolog(પૂર્ણાંક t)
{
    પૂર્ણાંક addr, u, func_call;
    Sym *sym;
    અક્ષર buf[1024];

    init_outfile();

    /* XXX: pass function name to gfunc_prolog */
    il_type_to_str(buf, કદ(buf), t, funcname);
    fprintf(il_outfile, ".method static %s il managed\n", buf);
    fprintf(il_outfile, "{\n");
    /* XXX: cannot do better now */
    fprintf(il_outfile, " .maxstack %d\n", NB_REGS);
    fprintf(il_outfile, " .locals (int32, int32, int32, int32, int32, int32, int32, int32)\n");
    
    જો (!strcmp(funcname, "main"))
        fprintf(il_outfile, " .entrypoint\n");
        
    sym = sym_find((unsigned)t >> VT_STRUCT_SHIFT);
    func_call = sym->r;

    addr = ARG_BASE;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    func_vt = sym->t;
    func_var = (sym->c == FUNC_ELLIPSIS);
    જો ((func_vt & VT_BTYPE) == VT_STRUCT) {
        func_vc = addr;
        addr++;
    }
    /* define parameters */
    જ્યારે ((sym = sym->next) != ખાલી) {
        u = sym->t;
        sym_ધકેલો(sym->v & ~SYM_FIELD, u,
                 VT_LOCAL | lvalue_type(sym->type.t), addr);
        addr++;
    }
}

/* generate function epilog */
શૂન્ય gfunc_epilog(શૂન્ય)
{
    out_op(IL_OP_RET);
    fprintf(il_outfile, "}\n\n");
}

/* generate a jump to a label */
પૂર્ણાંક gjmp(પૂર્ણાંક t)
{
    પાછા out_opj(IL_OP_BR, t);
}

/* generate a jump to a fixed address */
શૂન્ય gjmp_addr(પૂર્ણાંક a)
{
    /* XXX: handle syms */
    out_opi(IL_OP_BR, a);
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
પૂર્ણાંક gtst(પૂર્ણાંક inv, પૂર્ણાંક t)
{
    પૂર્ણાંક v, *p, c;

    v = vtop->r & VT_VALMASK;
    જો (v == VT_CMP) {
        c = vtop->c.i ^ inv;
        પસંદગી(c) {
        સ્થિતિ TOK_EQ:
            c = IL_OP_BEQ;
            તોડો;
        સ્થિતિ TOK_NE:
            c = IL_OP_BNE_UN;
            તોડો;
        સ્થિતિ TOK_LT:
            c = IL_OP_BLT;
            તોડો;
        સ્થિતિ TOK_LE:
            c = IL_OP_BLE;
            તોડો;
        સ્થિતિ TOK_GT:
            c = IL_OP_BGT;
            તોડો;
        સ્થિતિ TOK_GE:
            c = IL_OP_BGE;
            તોડો;
        સ્થિતિ TOK_ULT:
            c = IL_OP_BLT_UN;
            તોડો;
        સ્થિતિ TOK_ULE:
            c = IL_OP_BLE_UN;
            તોડો;
        સ્થિતિ TOK_UGT:
            c = IL_OP_BGT_UN;
            તોડો;
        સ્થિતિ TOK_UGE:
            c = IL_OP_BGE_UN;
            તોડો;
        }
        t = out_opj(c, t);
    } નહીંતર જો (v == VT_JMP || v == VT_JMPI) {
        /* && or || optimization */
        જો ((v & 1) == inv) {
            /* insert vtop->c jump list in t */
            p = &vtop->c.i;
            જ્યારે (*p != 0)
                p = (પૂર્ણાંક *)*p;
            *p = t;
            t = vtop->c.i;
        } નહીંતર {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    પાછા t;
}

/* generate an integer binary operation */
શૂન્ય gen_opi(પૂર્ણાંક op)
{
    gv2(RC_ST1, RC_ST0);
    પસંદગી(op) {
    સ્થિતિ '+':
        out_op(IL_OP_ADD);
        જાઓ std_op;
    સ્થિતિ '-':
        out_op(IL_OP_SUB);
        જાઓ std_op;
    સ્થિતિ '&':
        out_op(IL_OP_AND);
        જાઓ std_op;
    સ્થિતિ '^':
        out_op(IL_OP_XOR);
        જાઓ std_op;
    સ્થિતિ '|':
        out_op(IL_OP_OR);
        જાઓ std_op;
    સ્થિતિ '*':
        out_op(IL_OP_MUL);
        જાઓ std_op;
    સ્થિતિ TOK_SHL:
        out_op(IL_OP_SHL);
        જાઓ std_op;
    સ્થિતિ TOK_SHR:
        out_op(IL_OP_SHR_UN);
        જાઓ std_op;
    સ્થિતિ TOK_SAR:
        out_op(IL_OP_SHR);
        જાઓ std_op;
    સ્થિતિ '/':
    સ્થિતિ TOK_PDIV:
        out_op(IL_OP_DIV);
        જાઓ std_op;
    સ્થિતિ TOK_UDIV:
        out_op(IL_OP_DIV_UN);
        જાઓ std_op;
    સ્થિતિ '%':
        out_op(IL_OP_REM);
        જાઓ std_op;
    સ્થિતિ TOK_UMOD:
        out_op(IL_OP_REM_UN);
    std_op:
        vtop--;
        vtop[0].r = REG_ST0;
        તોડો;
    સ્થિતિ TOK_EQ:
    સ્થિતિ TOK_NE:
    સ્થિતિ TOK_LT:
    સ્થિતિ TOK_LE:
    સ્થિતિ TOK_GT:
    સ્થિતિ TOK_GE:
    સ્થિતિ TOK_ULT:
    સ્થિતિ TOK_ULE:
    સ્થિતિ TOK_UGT:
    સ્થિતિ TOK_UGE:
        vtop--;
        vtop[0].r = VT_CMP;
        vtop[0].c.i = op;
        તોડો;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
શૂન્ય gen_opf(પૂર્ણાંક op)
{
    /* same as integer */
    gen_opi(op);
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
શૂન્ય gen_cvt_itof(પૂર્ણાંક t)
{
    gv(RC_ST0);
    જો (t == VT_FLOAT)
        out_op(IL_OP_CONV_R4);
    નહીંતર
        out_op(IL_OP_CONV_R8);
}

/* convert fp to int 't' type */
/* XXX: handle long long case */
શૂન્ય gen_cvt_ftoi(પૂર્ણાંક t)
{
    gv(RC_ST0);
    પસંદગી(t) {
    સ્થિતિ VT_INT | VT_UNSIGNED:
        out_op(IL_OP_CONV_U4);
        તોડો;
    સ્થિતિ VT_LLONG:
        out_op(IL_OP_CONV_I8);
        તોડો;
    સ્થિતિ VT_LLONG | VT_UNSIGNED:
        out_op(IL_OP_CONV_U8);
        તોડો;
    મૂળભૂત:
        out_op(IL_OP_CONV_I4);
        તોડો;
    }
}

/* convert from one floating point type to another */
શૂન્ય gen_cvt_ftof(પૂર્ણાંક t)
{
    gv(RC_ST0);
    જો (t == VT_FLOAT) {
        out_op(IL_OP_CONV_R4);
    } નહીંતર {
        out_op(IL_OP_CONV_R8);
    }
}

/* end of CIL code generator */
/*************************************************************/

