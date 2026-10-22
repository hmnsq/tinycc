/*
 *  i386 specific functions for TCC assembler
 *
 *  Copyright (c) 2001, 2002 Fabrice Bellard
 *  Copyright (c) 2009 Frédéric Feret (x86_64 support)
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

#define USING_GLOBALS
#شامل "tcc.h"

#define MAX_OPERANDS 3

#define TOK_ASM_first TOK_ASM_clc
#define TOK_ASM_last TOK_ASM_emms
#define TOK_ASM_alllast TOK_ASM_subps

#define OPC_B          0x01  /* only used with OPC_WL */
#define OPC_WL         0x02  /* accepts w, l or no suffix */
#define OPC_BWL        (OPC_B | OPC_WL) /* accepts b, w, l or no suffix */
#define OPC_REG        0x04 /* register is added to opcode */
#define OPC_MODRM      0x08 /* modrm encoding */

#define OPCT_MASK      0x70
#define OPC_FWAIT      0x10 /* add fwait opcode */
#define OPC_SHIFT      0x20 /* shift opcodes */
#define OPC_ARITH      0x30 /* arithmetic opcodes */
#define OPC_FARITH     0x40 /* FPU arithmetic opcodes */
#define OPC_TEST       0x50 /* test opcodes */
#define OPC_0F01       0x60 /* 0x0f01XX (group 7, XX is 2nd opcode,
                               no operands and unstructured mod/rm) */
#define OPCT_IS(v,i) (((v) & OPCT_MASK) == (i))

#define OPC_0F        0x100 /* Is secondary map (0x0f prefix) */
#define OPC_48        0x200 /* Always has REX prefix */
#ifdef TCC_TARGET_X86_64
# define OPC_WLQ     0x1000  /* accepts w, l, q or no suffix */
# define OPC_BWLQ    (OPC_B | OPC_WLQ) /* accepts b, w, l, q or no suffix */
# define OPC_WLX     OPC_WLQ
# define OPC_BWLX    OPC_BWLQ
#وگرنه
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#endif

#define OPC_GROUP_SHIFT 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
شمارش {
    OPT_REG8=0, /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG16,  /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG32,  /* warning: value is hardcoded from TOK_ASM_xxx */
#ifdef TCC_TARGET_X86_64
    OPT_REG64,  /* warning: value is hardcoded from TOK_ASM_xxx */
#endif
    OPT_MMX,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SSE,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_CR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_TR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_DB,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SEG,
    OPT_ST,
#ifdef TCC_TARGET_X86_64
    OPT_REG8_کم, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
		     with REX prefix, not used in insn templates */
#endif
    OPT_IM8,
    OPT_IM8S,
    OPT_IM16,
    OPT_IM32,
#ifdef TCC_TARGET_X86_64
    OPT_IM64,
#endif
    OPT_EAX,    /* %al, %ax, %eax or %rax register */
    OPT_ST0,    /* %st(0) register */
    OPT_CL,     /* %cl register */
    OPT_DX,     /* %dx register */
    OPT_ADDR,   /* OP_EA with only offset */
    OPT_INDIR,  /* *(expr) */
    /* composite types */
    OPT_COMPOSITE_FIRST,
    OPT_IM,     /* IM8 | IM16 | IM32 */
    OPT_REG,    /* REG8 | REG16 | REG32 | REG64 */
    OPT_REGW,   /* REG16 | REG32 | REG64 */
    OPT_IMW,    /* IM16 | IM32 */
    OPT_MMXSSE, /* MMX | SSE */
    OPT_DISP,   /* Like OPT_ADDR, but emitted as displacement (for jumps) */
    OPT_DISP8,  /* Like OPT_ADDR, but only 8bit (short jumps) */
    /* can be ored with any OPT_xxx */
    OPT_EA = 0x80
};

#define OP_REG8   (1 << OPT_REG8)
#define OP_REG16  (1 << OPT_REG16)
#define OP_REG32  (1 << OPT_REG32)
#define OP_MMX    (1 << OPT_MMX)
#define OP_SSE    (1 << OPT_SSE)
#define OP_CR     (1 << OPT_CR)
#define OP_TR     (1 << OPT_TR)
#define OP_DB     (1 << OPT_DB)
#define OP_SEG    (1 << OPT_SEG)
#define OP_ST     (1 << OPT_ST)
#define OP_IM8    (1 << OPT_IM8)
#define OP_IM8S   (1 << OPT_IM8S)
#define OP_IM16   (1 << OPT_IM16)
#define OP_IM32   (1 << OPT_IM32)
#define OP_EAX    (1 << OPT_EAX)
#define OP_ST0    (1 << OPT_ST0)
#define OP_CL     (1 << OPT_CL)
#define OP_DX     (1 << OPT_DX)
#define OP_ADDR   (1 << OPT_ADDR)
#define OP_INDIR  (1 << OPT_INDIR)
#ifdef TCC_TARGET_X86_64
# define OP_REG64 (1 << OPT_REG64)
# define OP_REG8_کم (1 << OPT_REG8_کم)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#وگرنه
# define OP_REG64 0
# define OP_REG8_کم 0
# define OP_IM64  0
# define OP_EA32  0
#endif

#define OP_EA     0x40000000u
#define OP_REG    (OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64)

#ifdef TCC_TARGET_X86_64
# define TREG_XAX   TREG_RAX
# define TREG_XCX   TREG_RCX
# define TREG_XDX   TREG_RDX
# define TOK_ASM_xax TOK_ASM_rax
#وگرنه
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#endif

تعریفنوع ساختار ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

تعریفنوع ساختار Operand {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t shift;
    عبارت_مقدار e;
} Operand;

ایستا ثابت uint8_t reg_to_size[9] = {
/*
    [OP_REG8] = 0,
    [OP_REG16] = 1,
    [OP_REG32] = 2,
#ifdef TCC_TARGET_X86_64
    [OP_REG64] = 3,
#endif
*/
    0, 0, 1, 0, 2, 0, 0, 0, 3
};

#define NB_TEST_OPCODES 30

ایستا ثابت uint8_t test_bits[NB_TEST_OPCODES] = {
 0x00, /* o */
 0x01, /* no */
 0x02, /* b */
 0x02, /* c */
 0x02, /* nae */
 0x03, /* nb */
 0x03, /* nc */
 0x03, /* ae */
 0x04, /* e */
 0x04, /* z */
 0x05, /* ne */
 0x05, /* nz */
 0x06, /* be */
 0x06, /* na */
 0x07, /* nbe */
 0x07, /* a */
 0x08, /* s */
 0x09, /* ns */
 0x0a, /* p */
 0x0a, /* pe */
 0x0b, /* np */
 0x0b, /* po */
 0x0c, /* l */
 0x0c, /* nge */
 0x0d, /* nl */
 0x0d, /* ge */
 0x0e, /* le */
 0x0e, /* ng */
 0x0f, /* nle */
 0x0f, /* g */
};

ایستا ثابت uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

ایستا ثابت ASMInstr asm_instrs[] = {
#define ALT(x) x
/* This removes a 0x0f in the second byte */
#define O(o) ((uint64_t) ((((o) & 0xff00) == 0x0f00) ? ((((o) >> 8) & ~0xff) | ((o) & 0xff)) : (o)))
/* This constructs instr_type from opcode, type and group.  */
#define T(o,i,g) ((i) | ((g) << OPC_GROUP_SHIFT) | ((((o) & 0xff00) == 0x0f00) ? OPC_0F : 0))
#define DEF_ASM_OP0(name, opcode)
#define DEF_ASM_OP0L(name, opcode, group, instr_type) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, group), 0, { 0 } },
#define DEF_ASM_OP1(name, opcode, group, instr_type, op0) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, group), 1, { op0 }},
#define DEF_ASM_OP2(name, opcode, group, instr_type, op0, op1) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, group), 2, { op0, op1 }},
#define DEF_ASM_OP3(name, opcode, group, instr_type, op0, op1, op2) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, group), 3, { op0, op1, op2 }},
#ifdef TCC_TARGET_X86_64
# include "x86_64-asm.h"
#وگرنه
# include "i386-asm.h"
#endif
    /* last operation */
    { 0, },
};

ایستا ثابت uint16_t op0_codes[] = {
#define ALT(x)
#define DEF_ASM_OP0(x, opcode) opcode,
#define DEF_ASM_OP0L(name, opcode, group, instr_type)
#define DEF_ASM_OP1(name, opcode, group, instr_type, op0)
#define DEF_ASM_OP2(name, opcode, group, instr_type, op0, op1)
#define DEF_ASM_OP3(name, opcode, group, instr_type, op0, op1, op2)
#ifdef TCC_TARGET_X86_64
# include "x86_64-asm.h"
#وگرنه
# include "i386-asm.h"
#endif
};

ایستا درونخطی صحیح get_reg_shift(TCCState *s1)
{
    صحیح shift, v;
    v = asm_int_عبارت(s1);
    انتخاب(v) {
    حالت 1:
        shift = 0;
        بشکن;
    حالت 2:
        shift = 1;
        بشکن;
    حالت 4:
        shift = 2;
        بشکن;
    حالت 8:
        shift = 3;
        بشکن;
    پیشفرض:
        expect("1, 2, 4 or 8 constant");
        shift = 0;
        بشکن;
    }
    بازگشت shift;
}

#ifdef TCC_TARGET_X86_64
ایستا صحیح asm_parse_numeric_reg(صحیح t, unsigned صحیح *type)
{
    صحیح reg = -1;
    اگر (t >= TOK_IDENT && t < tok_ident) {
	ثابت نویسه *s = table_ident[t - TOK_IDENT]->str;
	نویسه c;
	*type = OP_REG64;
	اگر (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	اگر (*s++ != 'r')
	  بازگشت -1;
	/* Don't allow leading '0'.  */
	اگر ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	وگرنه
	  بازگشت -1;
	اگر ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	اگر (reg > 15)
	  بازگشت -1;
	اگر ((c = *s) == 0)
	  ;
	وگرنه اگر (*type != OP_REG64)
	  بازگشت -1;
	وگرنه اگر (c == 'b' && !s[1])
	  *type = OP_REG8;
	وگرنه اگر (c == 'w' && !s[1])
	  *type = OP_REG16;
	وگرنه اگر (c == 'd' && !s[1])
	  *type = OP_REG32;
	وگرنه
	  بازگشت -1;
    }
    بازگشت reg;
}
#endif

ایستا صحیح asm_parse_reg(unsigned صحیح *type)
{
    صحیح reg = 0;
    *type = 0;
    اگر (tok != '%')
        برو error_32;
    next();
    اگر (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#ifdef TCC_TARGET_X86_64
    } وگرنه اگر (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } وگرنه اگر (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } وگرنه اگر ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#endif
    } وگرنه {
    error_32:
        expect("register");
    }
    next();
    بازگشت reg;
}

ایستا تهی parse_operand(TCCState *s1, Operand *op)
{
    عبارت_مقدار e;
    صحیح reg, indir;
    ثابت نویسه *p;

    indir = 0;
    اگر (tok == '*') {
        next();
        indir = OP_INDIR;
    }

    اگر (tok == '%') {
        next();
        اگر (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            اگر ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            وگرنه اگر (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            وگرنه اگر (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } وگرنه اگر (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } وگرنه اگر (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } وگرنه اگر (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            next();
            اگر (tok == '(') {
                next();
                اگر (tok != TOK_PPNUM)
                    برو reg_error;
                p = tokc.str.data;
                reg = p[0] - '0';
                اگر ((unsigned)reg >= 8 || p[1] != '\0')
                    برو reg_error;
                op->reg = reg;
                next();
                skip(')');
            }
            اگر (op->reg == 0)
                op->type |= OP_ST0;
            برو no_skip;
#ifdef TCC_TARGET_X86_64
	} وگرنه اگر (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_کم;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } وگرنه اگر ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#endif
        } وگرنه {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        next();
    no_skip: ;
    } وگرنه اگر (tok == '$') {
        /* constant value */
        next();
        asm_عبارت(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        اگر (!op->e.sym) {
            اگر (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            اگر (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            اگر (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#ifdef TCC_TARGET_X86_64
            اگر (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#endif
        }
    } وگرنه {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->shift = 0;
        اگر (tok != '(') {
            asm_عبارت(s1, &e);
            op->e = e;
        } وگرنه {
            next();
            اگر (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = پوچ;
            } وگرنه {
                /* bracketed offset expression */
                asm_عبارت(s1, &e);
                اگر (tok != ')')
                    expect(")");
                next();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        اگر (tok == '(') {
	    unsigned صحیح type = 0;
            next();
            اگر (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            اگر (tok == ',') {
                next();
                اگر (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                اگر (tok == ',') {
                    next();
                    op->shift = get_reg_shift(s1);
                }
            }
	    اگر (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        اگر (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC تهی gen_expr32(عبارت_مقدار *pe)
{
    اگر (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    وگرنه
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
ایستا تهی gen_disp32(عبارت_مقدار *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    اگر (esym && esym->st_shndx == cur_text_section->sh_رقم) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_مقدار - ind - 4);
    } وگرنه {
        اگر (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = پوچ;
        }
#ifdef TCC_TARGET_X86_64
        greloca(cur_text_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#وگرنه
        gen_addrpc32(VT_SYM, sym, pe->v);
#endif

    }
}

/* generate the modrm operand */
ایستا درونخطی صحیح asm_modrm(صحیح reg, Operand *op)
{
    صحیح mod, reg1, reg2, sib_reg1;

    اگر (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } وگرنه اگر (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#ifdef TCC_TARGET_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#وگرنه
	g(0x05 + (reg << 3));
#endif
	gen_expr32(&op->e);
#ifdef TCC_TARGET_X86_64
    } وگرنه اگر (op->reg == -2) {
        عبارت_مقدار *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        بازگشت ind;
#endif
    } وگرنه {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        اگر (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } وگرنه اگر (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } وگرنه اگر (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } وگرنه {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        اگر (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        اگر (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            اگر (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->shift << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        اگر (mod == 0x40) {
            g(op->e.v);
        } وگرنه اگر (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    بازگشت 0;
}

#ifdef TCC_TARGET_X86_64
#define REX_W 0x48
#define REX_R 0x44
#define REX_X 0x42
#define REX_B 0x41

ایستا تهی asm_rex(صحیح width64, Operand *ops, صحیح nb_ops, صحیح *op_type,
		    صحیح regi, صحیح rmi)
{
  unsigned نویسه rex = width64 ? 0x48 : 0;
  صحیح saw_بالا_8bit = 0;
  صحیح i;
  اگر (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      برای(i = 0; i < nb_ops; i++) {
	  اگر (op_type[i] & (OP_REG | OP_ST)) {
	      اگر (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } وگرنه اگر (ops[i].type & OP_REG8_کم)
		  rex |= 0x40;
	      وگرنه اگر (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_بالا_8bit = ops[i].reg;
	      بشکن;
	  }
      }
  } وگرنه {
      اگر (regi != -1) {
	  اگر (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } وگرنه اگر (ops[regi].type & OP_REG8_کم)
	      rex |= 0x40;
	  وگرنه اگر (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_بالا_8bit = ops[regi].reg;
      }
      اگر (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  اگر (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } وگرنه اگر (ops[rmi].type & OP_REG8_کم)
	      rex |= 0x40;
	  وگرنه اگر (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_بالا_8bit = ops[rmi].reg;
      }
      اگر (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  اگر (rex) {
      اگر (saw_بالا_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_بالا_8bit-4]);
      g(rex);
  }
}
#endif


ایستا تهی maybe_print_stats (تهی)
{
    ایستا صحیح already;

    اگر (0 && !already)
    /* print stats about opcodes */
    {
        ثابت ساختار ASMInstr *pa;
        صحیح freq[4];
        صحیح op_vals[500];
        صحیح nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, اندازه(freq));
        برای(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                برای(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    اگر (pa->instr_type == op_vals[j])
                        برو found;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            found: ;
            //}
        }
        برای(i=0;i<nb_op_vals;i++) {
            صحیح v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                printf("%3d: %08x\n", i, v);
        }
        printf("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (صحیح)اندازه(asm_instrs),
	       (صحیح)اندازه(asm_instrs) / (صحیح)اندازه(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC تهی asm_opcode(TCCState *s1, صحیح opcode)
{
    ثابت ASMInstr *pa;
    صحیح i, modrm_index, modreg_index, reg, v, op1, seg_prefix, pc, p;
    صحیح nb_ops, s;
    Operand ops[MAX_OPERANDS], *برداشت;
    صحیح op_type[3]; /* decoded op type */
    صحیح alltypes;   /* OR of all operand types */
    صحیح autosize;
    صحیح p66;
#ifdef TCC_TARGET_X86_64
    صحیح rex64;
#endif

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    اگر (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    برداشت = ops;
    nb_ops = 0;
    seg_prefix = 0;
    alltypes = 0;
    برای(;;) {
        اگر (tok == ';' || tok == TOK_LINEFEED)
            بشکن;
        اگر (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_operand(s1, برداشت);
        اگر (tok == ':') {
           اگر (!(برداشت->type & OP_SEG) || seg_prefix)
               tcc_error("incorrect prefix");
           seg_prefix = segment_prefixes[برداشت->reg];
           next();
           parse_operand(s1, برداشت);
           اگر (!(برداشت->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        برداشت++;
        nb_ops++;
        اگر (tok != ',')
            بشکن;
        next();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    برای(pa = asm_instrs; pa->sym != 0; pa++) {
	صحیح it = pa->instr_type & OPCT_MASK;
        s = 0;
        اگر (it == OPC_FARITH) {
            v = opcode - pa->sym;
            اگر (!((unsigned)v < 8 * 6 && (v % 6) == 0))
                ادامه;
        } وگرنه اگر (it == OPC_ARITH) {
            اگر (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                ادامه;
            s = (opcode - pa->sym) % NBWLX;
	    اگر ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		اگر (((opcode - pa->sym + 1) % NBWLX) == 0)
		    ادامه;
	        s++;
	      }
        } وگرنه اگر (it == OPC_SHIFT) {
            اگر (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                ادامه;
            s = (opcode - pa->sym) % NBWLX;
        } وگرنه اگر (it == OPC_TEST) {
            اگر (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                ادامه;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    اگر (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } وگرنه اگر (pa->instr_type & OPC_B) {
#ifdef TCC_TARGET_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    اگر ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        ادامه;
#endif
            اگر (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                ادامه;
            s = opcode - pa->sym;
        } وگرنه اگر (pa->instr_type & OPC_WLX) {
            اگر (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                ادامه;
            s = opcode - pa->sym + 1;
        } وگرنه {
            اگر (pa->sym != opcode)
                ادامه;
        }
        اگر (pa->nb_ops != nb_ops)
            ادامه;
#ifdef TCC_TARGET_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	اگر (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    ادامه;
#endif
        /* now decode and check each operand */
	alltypes = 0;
        برای(i = 0; i < nb_ops; i++) {
            صحیح op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            انتخاب(op2) {
            حالت OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                بشکن;
            حالت OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                بشکن;
            حالت OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                بشکن;
            حالت OPT_IMW:
                v = OP_IM16 | OP_IM32;
                بشکن;
	    حالت OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		بشکن;
	    حالت OPT_DISP:
	    حالت OPT_DISP8:
		v = OP_ADDR;
		بشکن;
            پیشفرض:
                v = 1 << op2;
                بشکن;
            }
            اگر (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            اگر ((ops[i].type & v) == 0)
                برو next;
	    alltypes |= ops[i].type;
        }
        (تهی)alltypes; /* maybe unused */
        /* all is matching ! */
        بشکن;
    next: ;
    }
    اگر (pa->sym == 0) {
        اگر (opcode >= TOK_ASM_first && opcode <= TOK_ASM_last) {
            صحیح b;
            b = op0_codes[opcode - TOK_ASM_first];
            اگر (b & 0xff00)
                g(b >> 8);
            g(b);
            بازگشت;
        } وگرنه اگر (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, پوچ));
        } وگرنه {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = table_ident[opcode - TOK_IDENT];
	    اگر (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		برو again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#ifdef TCC_TARGET_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    اگر ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#endif
    اگر (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        برای(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            اگر ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_to_size[ops[i].type & OP_REG];
        }
        اگر (s == autosize) {
            اگر ((opcode == TOK_ASM_افزودن || opcode == TOK_ASM_برداشت) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    وگرنه اگر ((opcode == TOK_ASM_افزودن || opcode == TOK_ASM_برداشت) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            وگرنه
                tcc_error("cannot infer opcode suffix");
        }
    }

#ifdef TCC_TARGET_X86_64
    rex64 = 0;
    اگر (pa->instr_type & OPC_48)
        rex64 = 1;
    وگرنه اگر (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	صحیح default64 = 0;
	برای(i = 0; i < nb_ops; i++) {
	    اگر (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		بشکن;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        اگر (((opcode != TOK_ASM_افزودن && opcode != TOK_ASM_برداشت
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#endif

    /* now generates the operation */
    اگر (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    اگر (seg_prefix)
        g(seg_prefix);
#ifdef TCC_TARGET_X86_64
    /* Generate addr32 prefix if needed */
    برای(i = 0; i < nb_ops; i++) {
        اگر (ops[i].type & OP_EA32) {
	    g(0x67);
	    بشکن;
        }
    }
#endif
    /* generate data16 prefix if needed */
    p66 = 0;
    اگر (s == 1)
        p66 = 1;
    وگرنه {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        برای (i = 0; i < nb_ops; i++)
            اگر ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    اگر (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    انتخاب (p) {
        حالت 0: بشکن;  /* no prefix */
        حالت 0x48: بشکن; /* REX, handled elsewhere */
        حالت 0x66:
        حالت 0x67:
        حالت 0xf2:
        حالت 0xf3: v = v & 0xff; g(p); بشکن;
        حالت 0xd4: حالت 0xd5: بشکن; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        حالت 0xd8: حالت 0xd9: حالت 0xda: حالت 0xdb: /* x87, no normal prefix */
        حالت 0xdc: حالت 0xdd: حالت 0xde: حالت 0xdf: بشکن;
        پیشفرض: tcc_error("bad prefix 0x%2x in opcode table", p); بشکن;
    }
    اگر (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    اگر ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } وگرنه اگر (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } وگرنه اگر ((v == 0x06 || v == 0x07)) {
        اگر (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } وگرنه {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } وگرنه اگر (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } وگرنه اگر ((pa->instr_type & (OPCT_MASK | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_index = -1;
    modreg_index = -1;
    اگر (pa->instr_type & OPC_MODRM) {
	اگر (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#ifdef TCC_TARGET_X86_64
	    اگر (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    وگرنه اگر (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#وگرنه
	    اگر (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#endif
	    وگرنه
	      tcc_error("bad MODR/M opcode without operands");
	    برو modrm_found;
	}
        /* first look for an ea operand */
        برای(i = 0;i < nb_ops; i++) {
            اگر (op_type[i] & OP_EA)
                برو modrm_found;
        }
        /* then if not found, a register or indirection (shift instructions) */
        برای(i = 0;i < nb_ops; i++) {
            اگر (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                برو modrm_found;
        }
#ifdef ASM_DEBUG
        tcc_error("bad op table");
#endif
    modrm_found:
        modrm_index = i;
        /* if a register is used in another operand then it is
           used instead of group */
        برای(i = 0;i < nb_ops; i++) {
            صحیح t = op_type[i];
            اگر (i != modrm_index &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_index = i;
                بشکن;
            }
        }
    }
#ifdef TCC_TARGET_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_index, modrm_index);
#endif

    اگر (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        اگر (v == 0xb0 && s >= 1)
            v += 7;
        برای(i = 0; i < nb_ops; i++) {
            اگر (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                بشکن;
            }
        }
    }
    اگر (pa->instr_type & OPC_B)
        v += s >= 1;
    اگر (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        صحیح jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        اگر (!esym || esym->st_shndx != cur_text_section->sh_رقم)
            برو no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_مقدار - ind - 2 - (v >= 0xff);
        اگر (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } وگرنه {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    اگر (v == 0xeb) /* jmp */
	        v = 0xe9;
	    وگرنه اگر (v == 0x70) /* jcc */
	        v += 0x0f10;
	    وگرنه
	        tcc_error("invalid displacement");
        }
    }
    اگر (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_bits[opcode - pa->sym];
    وگرنه اگر (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    اگر (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    اگر (op1)
        g(op1);
    g(v);

    اگر (OPCT_IS(pa->instr_type, OPC_SHIFT)) {
        reg = (opcode - pa->sym) / NBWLX;
        اگر (reg == 6)
            reg = 7;
    } وگرنه اگر (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } وگرنه اگر (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } وگرنه {
        reg = (pa->instr_type >> OPC_GROUP_SHIFT) & 7;
    }

    pc = 0;
    اگر (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	اگر (modreg_index >= 0)
	    reg = ops[modreg_index].reg;
        pc = asm_modrm(reg, &ops[modrm_index]);
    }

    /* emit constants */
#ifndef TCC_TARGET_X86_64
    اگر (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        اگر (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        بازگشت;
    }
#endif
    برای(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        اگر (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            اگر ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                اگر (s == 0)
                    v = OP_IM8;
                وگرنه اگر (s == 1)
                    v = OP_IM16;
                وگرنه اگر (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                وگرنه
                    v = OP_IM64;
            }

            اگر ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            اگر (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } وگرنه اگر (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#ifdef TCC_TARGET_X86_64
            } وگرنه اگر (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#endif
	    } وگرنه اگر (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } وگرنه {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    اگر (pc)
        add32le(cur_text_section->data + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ایستا درونخطی صحیح constraint_priority(ثابت نویسه *str)
{
    صحیح priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    برای(;;) {
        c = *str;
        اگر (c == '\0')
            بشکن;
        str++;
        انتخاب(c) {
        حالت 'A':
            pr = 0;
            بشکن;
        حالت 'a':
        حالت 'b':
        حالت 'c':
        حالت 'd':
        حالت 'S':
        حالت 'D':
            pr = 1;
            بشکن;
        حالت 'q':
            pr = 2;
            بشکن;
        حالت 'r':
	حالت 'R':
	حالت 'p':
            pr = 3;
            بشکن;
        حالت 'N':
        حالت 'M':
        حالت 'I':
	حالت 'e':
        حالت 'i':
        حالت 'm':
        حالت 'g':
            pr = 4;
            بشکن;
        پیشفرض:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        اگر (pr > priority)
            priority = pr;
    }
    بازگشت priority;
}

ایستا ثابت نویسه *skip_constraint_modifiers(ثابت نویسه *p)
{
    وقتی (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    بازگشت p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC صحیح asm_parse_regvar (صحیح t)
{
    ثابت نویسه *s;
    Operand op;
    اگر (t < TOK_IDENT || (t & SYM_FIELD))
        بازگشت -1;
    s = table_ident[t - TOK_IDENT]->str;
    اگر (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_operand(tcc_state, &op);
    /* Accept only integer regs for now. */
    اگر (op.type & OP_REG)
        بازگشت op.reg;
    وگرنه
        بازگشت -1;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC تهی asm_compute_constraints(ASMOperand *operands,
                                    صحیح nb_operands, صحیح nb_outputs,
                                    ثابت uint8_t *clobber_regs,
                                    صحیح *pout_reg)
{
    ASMOperand *op;
    صحیح sorted_op[MAX_ASM_OPERANDS];
    صحیح i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ثابت نویسه *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    برای(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->درون_داد_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    برای(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        اگر (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, پوچ);
            اگر ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_index = k;
            اگر (operands[k].درون_داد_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].درون_داد_index = i;
            op->priority = 5;
	} وگرنه اگر ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->priority = 1;
	    op->reg = reg;
        } وگرنه {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    برای(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    برای(i=0;i<nb_operands - 1;i++) {
        برای(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            اگر (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    برای(i = 0;i < NB_ASM_REGS; i++) {
        اگر (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        وگرنه
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_IN_MASK | REG_OUT_MASK;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    برای(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        اگر (op->ref_index >= 0)
            ادامه;
        /* select if register is used for output, input or both */
        اگر (op->درون_داد_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } وگرنه اگر (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } وگرنه {
            reg_mask = REG_IN_MASK;
        }
	اگر (op->reg >= 0) {
	    اگر (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_next:
        c = *str++;
        انتخاب(c) {
        حالت '=':
            برو try_next;
        حالت '+':
            op->is_rw = 1;
            /* FALL THRU */
        حالت '&':
            اگر (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            برو try_next;
        حالت 'A':
            /* allocate both eax and edx */
            اگر (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                برو try_next;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_mask;
            regs_allocated[TREG_XDX] |= reg_mask;
            بشکن;
        حالت 'a':
            reg = TREG_XAX;
            برو alloc_reg;
        حالت 'b':
            reg = 3;
            برو alloc_reg;
        حالت 'c':
            reg = TREG_XCX;
            برو alloc_reg;
        حالت 'd':
            reg = TREG_XDX;
            برو alloc_reg;
        حالت 'S':
            reg = 6;
            برو alloc_reg;
        حالت 'D':
            reg = 7;
        alloc_reg:
            اگر (op->reg >= 0 && reg != op->reg)
                برو try_next;
            اگر (is_reg_allocated(reg))
                برو try_next;
            برو reg_found;
        حالت 'q':
            /* eax, ebx, ecx or edx */
            اگر (op->reg >= 0) {
                اگر ((reg = op->reg) < 4)
                    برو reg_found;
            } وگرنه برای(reg = 0; reg < 4; reg++) {
                اگر (!is_reg_allocated(reg))
                    برو reg_found;
            }
            برو try_next;
        حالت 'r':
	حالت 'R':
	حالت 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            اگر ((reg = op->reg) >= 0)
                برو reg_found;
            وگرنه برای(reg = 0; reg < NB_ASM_REGS; reg++) {
                اگر (!is_reg_allocated(reg))
                    برو reg_found;
            }
            برو try_next;
        reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            بشکن;
	حالت 'e':
        حالت 'i':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                برو try_next;
            بشکن;
        حالت 'I':
        حالت 'N':
        حالت 'M':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                برو try_next;
            بشکن;
        حالت 'm':
        حالت 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            اگر (j < nb_outputs || c == 'm') {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    برای(reg = 0; reg < NB_ASM_REGS; reg++) {
                        اگر (!(regs_allocated[reg] & REG_IN_MASK))
                            برو reg_found1;
                    }
                    برو try_next;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            بشکن;
        پیشفرض:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            بشکن;
        }
        /* if a reference is present for that operand, we assign it too */
        اگر (op->درون_داد_index >= 0) {
            operands[op->درون_داد_index].reg = op->reg;
            operands[op->درون_داد_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    برای(i=0;i<nb_operands;i++) {
        op = &operands[i];
        اگر (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_memory) {
            برای(reg = 0; reg < NB_ASM_REGS; reg++) {
                اگر (!(regs_allocated[reg] & REG_OUT_MASK))
                    برو reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            بشکن;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    برای(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, پوچ) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    اگر (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC تهی subst_asm_operand(CString *add_str,
                              SValue *sv, صحیح modifier)
{
    صحیح r, reg, size, val;

    r = sv->r;
    اگر ((r & VT_VALMASK) == VT_CONST) {
        اگر (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(add_str, '$');
        اگر (r & VT_SYM) {
	    ثابت نویسه *name = get_tok_str(sv->sym->v, پوچ);
	    اگر (sv->sym->v >= SYM_FIRST_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            اگر (tcc_state->leading_underscore)
              cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            اگر ((uint32_t)sv->c.i == 0)
                برو no_offset;
	    cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        اگر (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
    no_offset:;
#ifdef TCC_TARGET_X86_64
        اگر (r & VT_LVAL)
            cstr_cat(add_str, "(%rip)", -1);
#endif
    } وگرنه اگر ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d(%%%s)", (صحیح)sv->c.i, get_tok_str(TOK_ASM_xax + 5, پوچ));
    } وگرنه اگر (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, پوچ));
    } وگرنه {
        /* register case */
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        اگر ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        وگرنه اگر ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
#ifdef TCC_TARGET_X86_64
        وگرنه اگر ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
#endif
        وگرنه
            size = 4;
        اگر (size == 1 && reg >= 4)
            size = 4;

        اگر (modifier == 'b') {
            اگر (reg >= 4)
                tcc_error("cannot use byte register");
            size = 1;
        } وگرنه اگر (modifier == 'h') {
            اگر (reg >= 4)
                tcc_error("cannot use byte register");
            size = -1;
        } وگرنه اگر (modifier == 'w') {
            size = 2;
        } وگرنه اگر (modifier == 'k') {
            size = 4;
#ifdef TCC_TARGET_X86_64
        } وگرنه اگر (modifier == 'q') {
            size = 8;
#endif
        }

        اگر (reg >= 8) {
            cstr_printf(add_str, "%%r%d%c", reg, (size == 1) ? 'b' : ((size == 2) ? 'w' : ((size == 4) ? 'd' : ' ')));
            بازگشت;
        }
        انتخاب(size) {
        حالت -1:
            reg = TOK_ASM_ah + reg;
            بشکن;
        حالت 1:
            reg = TOK_ASM_al + reg;
            بشکن;
        حالت 2:
            reg = TOK_ASM_ax + reg;
            بشکن;
        پیشفرض:
            reg = TOK_ASM_eax + reg;
            بشکن;
#ifdef TCC_TARGET_X86_64
        حالت 8:
            reg = TOK_ASM_rax + reg;
            بشکن;
#endif
        }
        cstr_printf(add_str, "%%%s", get_tok_str(reg, پوچ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC تهی asm_gen_code(ASMOperand *operands, صحیح nb_operands,
                         صحیح nb_outputs, صحیح is_output,
                         uint8_t *clobber_regs,
                         صحیح out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    صحیح i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    ایستا ثابت uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#وگرنه
    ایستا ثابت uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#endif
#وگرنه
    ایستا ثابت uint8_t reg_saved[] = { 3, 6, 7 };
#endif

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, اندازه(regs_allocated));
    برای(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        اگر (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    اگر (!is_output) {
        /* generate reg save code */
        برای(i = 0; i < اندازه(reg_saved)/اندازه(reg_saved[0]); i++) {
            reg = reg_saved[i];
            اگر (regs_allocated[reg]) {
		اگر (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        برای(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } وگرنه اگر (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    load(op->reg, op->vt);
                    اگر (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        load(TREG_XDX, &sv);
                    }
                }
            }
        }
    } وگرنه {
        /* generate save code */
        برای(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    اگر (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        load(out_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } وگرنه {
                    store(op->reg, op->vt);
                    اگر (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        برای(i = اندازه(reg_saved)/اندازه(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            اگر (regs_allocated[reg]) {
		اگر (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC تهی asm_clobber(uint8_t *clobber_regs, ثابت نویسه *str)
{
    صحیح reg;
#ifdef TCC_TARGET_X86_64
    unsigned صحیح type;
#endif

    اگر (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        بازگشت;
    reg = tok_alloc_const(str);
    اگر (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } وگرنه اگر (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#ifdef TCC_TARGET_X86_64
    } وگرنه اگر (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } وگرنه اگر ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#endif
    } وگرنه {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
