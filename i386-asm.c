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

#تعریف_کن USING_GLOBALS
#ضمن "tcc.h"

#تعریف_کن MAX_OPERANDS 3

#تعریف_کن TOK_ASM_اولی TOK_ASM_clc
#تعریف_کن TOK_ASM_آخرین TOK_ASM_emms
#تعریف_کن TOK_ASM_alllast TOK_ASM_subps

#تعریف_کن OPC_B          0x01  /* only used with OPC_WL */
#تعریف_کن OPC_WL         0x02  /* accepts w, l or no suffix */
#تعریف_کن OPC_BWL        (OPC_B | OPC_WL) /* accepts b, w, l or no suffix */
#تعریف_کن OPC_REG        0x04 /* register is added to opcode */
#تعریف_کن OPC_MODRM      0x08 /* modrm encoding */

#تعریف_کن OPCT_ماسک      0x70
#تعریف_کن OPC_FWAIT      0x10 /* add fwait opcode */
#تعریف_کن OPC_لغزش      0x20 /* shift opcodes */
#تعریف_کن OPC_ARITH      0x30 /* arithmetic opcodes */
#تعریف_کن OPC_FARITH     0x40 /* FPU arithmetic opcodes */
#تعریف_کن OPC_TEST       0x50 /* test opcodes */
#تعریف_کن OPC_0F01       0x60 /* 0x0f01XX (group 7, XX is 2nd opcode,
                               no operands and unstructured mod/rm) */
#تعریف_کن OPCT_IS(v,i) (((v) & OPCT_ماسک) == (i))

#تعریف_کن OPC_0F        0x100 /* Is secondary map (0x0f prefix) */
#تعریف_کن OPC_48        0x200 /* Always has REX prefix */
#اگر_تعریف_شده TCC_هدف_X86_64
# define OPC_WLQ     0x1000  /* accepts w, l, q or no suffix */
# define OPC_BWLQ    (OPC_B | OPC_WLQ) /* accepts b, w, l, q or no suffix */
# define OPC_WLX     OPC_WLQ
# define OPC_BWLX    OPC_BWLQ
#وإلا
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#پایان_اگر

#تعریف_کن OPC_گروه_لغزش 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
تعداد {
    OPT_REG8=0, /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG16,  /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG32,  /* warning: value is hardcoded from TOK_ASM_xxx */
#اگر_تعریف_شده TCC_هدف_X86_64
    OPT_REG64,  /* warning: value is hardcoded from TOK_ASM_xxx */
#پایان_اگر
    OPT_MMX,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SSE,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_CR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_TR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_DB,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SEG,
    OPT_ST,
#اگر_تعریف_شده TCC_هدف_X86_64
    OPT_REG8_کم, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
		     with REX prefix, not used in insn templates */
#پایان_اگر
    OPT_IM8,
    OPT_IM8S,
    OPT_IM16,
    OPT_IM32,
#اگر_تعریف_شده TCC_هدف_X86_64
    OPT_IM64,
#پایان_اگر
    OPT_EAX,    /* %al, %ax, %eax or %rax register */
    OPT_ST0,    /* %st(0) register */
    OPT_CL,     /* %cl register */
    OPT_DX,     /* %dx register */
    OPT_ADDR,   /* OP_EA with only offset */
    OPT_INDIR,  /* *(expr) */
    /* composite types */
    OPT_مرکب_اولی,
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

#تعریف_کن OP_REG8   (1 << OPT_REG8)
#تعریف_کن OP_REG16  (1 << OPT_REG16)
#تعریف_کن OP_REG32  (1 << OPT_REG32)
#تعریف_کن OP_MMX    (1 << OPT_MMX)
#تعریف_کن OP_SSE    (1 << OPT_SSE)
#تعریف_کن OP_CR     (1 << OPT_CR)
#تعریف_کن OP_TR     (1 << OPT_TR)
#تعریف_کن OP_DB     (1 << OPT_DB)
#تعریف_کن OP_SEG    (1 << OPT_SEG)
#تعریف_کن OP_ST     (1 << OPT_ST)
#تعریف_کن OP_IM8    (1 << OPT_IM8)
#تعریف_کن OP_IM8S   (1 << OPT_IM8S)
#تعریف_کن OP_IM16   (1 << OPT_IM16)
#تعریف_کن OP_IM32   (1 << OPT_IM32)
#تعریف_کن OP_EAX    (1 << OPT_EAX)
#تعریف_کن OP_ST0    (1 << OPT_ST0)
#تعریف_کن OP_CL     (1 << OPT_CL)
#تعریف_کن OP_DX     (1 << OPT_DX)
#تعریف_کن OP_ADDR   (1 << OPT_ADDR)
#تعریف_کن OP_INDIR  (1 << OPT_INDIR)
#اگر_تعریف_شده TCC_هدف_X86_64
# define OP_REG64 (1 << OPT_REG64)
# define OP_REG8_کم (1 << OPT_REG8_کم)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#وإلا
# define OP_REG64 0
# define OP_REG8_کم 0
# define OP_IM64  0
# define OP_EA32  0
#پایان_اگر

#تعریف_کن OP_EA     0x40000000u
#تعریف_کن OP_REG    (OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64)

#اگر_تعریف_شده TCC_هدف_X86_64
# define TREG_XAX   TREG_RAX
# define TREG_XCX   TREG_RCX
# define TREG_XDX   TREG_RDX
# define TOK_ASM_xax TOK_ASM_rax
#وإلا
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#پایان_اگر

تعريفنوع بنية ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

تعريفنوع بنية عملوند {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t لغزش;
    عبارت_مقدار e;
} عملوند;

ساكن ثابت uint8_t reg_مقصد_اندازه[9] = {
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

#تعریف_کن NB_TEST_OPCODES 30

ساكن ثابت uint8_t test_بیتها[NB_TEST_OPCODES] = {
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

ساكن ثابت uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

ساكن ثابت ASMInstr asm_instrs[] = {
#تعریف_کن ALT(x) x
/* This removes a 0x0f in the second byte */
#تعریف_کن O(o) ((uint64_t) ((((o) & 0xff00) == 0x0f00) ? ((((o) >> 8) & ~0xff) | ((o) & 0xff)) : (o)))
/* This constructs instr_type from opcode, type and group.  */
#تعریف_کن T(o,i,g) ((i) | ((g) << OPC_گروه_لغزش) | ((((o) & 0xff00) == 0x0f00) ? OPC_0F : 0))
#تعریف_کن DEF_ASM_OP0(name, opcode)
#تعریف_کن DEF_ASM_OP0L(name, opcode, گروه, instr_type) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, گروه), 0, { 0 } },
#تعریف_کن DEF_ASM_OP1(name, opcode, گروه, instr_type, op0) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, گروه), 1, { op0 }},
#تعریف_کن DEF_ASM_OP2(name, opcode, گروه, instr_type, op0, op1) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, گروه), 2, { op0, op1 }},
#تعریف_کن DEF_ASM_OP3(name, opcode, گروه, instr_type, op0, op1, op2) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, گروه), 3, { op0, op1, op2 }},
#اگر_تعریف_شده TCC_هدف_X86_64
# include "x86_64-asm.h"
#وإلا
# include "i386-asm.h"
#پایان_اگر
    /* last operation */
    { 0, },
};

ساكن ثابت uint16_t op0_codes[] = {
#تعریف_کن ALT(x)
#تعریف_کن DEF_ASM_OP0(x, opcode) opcode,
#تعریف_کن DEF_ASM_OP0L(name, opcode, گروه, instr_type)
#تعریف_کن DEF_ASM_OP1(name, opcode, گروه, instr_type, op0)
#تعریف_کن DEF_ASM_OP2(name, opcode, گروه, instr_type, op0, op1)
#تعریف_کن DEF_ASM_OP3(name, opcode, گروه, instr_type, op0, op1, op2)
#اگر_تعریف_شده TCC_هدف_X86_64
# include "x86_64-asm.h"
#وإلا
# include "i386-asm.h"
#پایان_اگر
};

ساكن مضمن صحيح get_reg_لغزش(TCCState *s1)
{
    صحيح لغزش, v;
    v = asm_int_عبارت(s1);
    بدل(v) {
    حالة 1:
        لغزش = 0;
        اكسر;
    حالة 2:
        لغزش = 1;
        اكسر;
    حالة 4:
        لغزش = 2;
        اكسر;
    حالة 8:
        لغزش = 3;
        اكسر;
    افتراضي:
        expect("1, 2, 4 or 8 constant");
        لغزش = 0;
        اكسر;
    }
    أرجع لغزش;
}

#اگر_تعریف_شده TCC_هدف_X86_64
ساكن صحيح asm_parse_numeric_reg(صحيح t, بیعلامت صحيح *type)
{
    صحيح reg = -1;
    إذا (t >= TOK_IDENT && t < tok_ident) {
	ثابت حرف *s = جدول_ident[t - TOK_IDENT]->str;
	حرف c;
	*type = OP_REG64;
	إذا (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	إذا (*s++ != 'r')
	  أرجع -1;
	/* Don't allow leading '0'.  */
	إذا ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	وإلا
	  أرجع -1;
	إذا ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	إذا (reg > 15)
	  أرجع -1;
	إذا ((c = *s) == 0)
	  ;
	وإلا إذا (*type != OP_REG64)
	  أرجع -1;
	وإلا إذا (c == 'b' && !s[1])
	  *type = OP_REG8;
	وإلا إذا (c == 'w' && !s[1])
	  *type = OP_REG16;
	وإلا إذا (c == 'd' && !s[1])
	  *type = OP_REG32;
	وإلا
	  أرجع -1;
    }
    أرجع reg;
}
#پایان_اگر

ساكن صحيح asm_parse_reg(بیعلامت صحيح *type)
{
    صحيح reg = 0;
    *type = 0;
    إذا (tok != '%')
        اذهب error_32;
    بعدی();
    إذا (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#اگر_تعریف_شده TCC_هدف_X86_64
    } وإلا إذا (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } وإلا إذا (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } وإلا إذا ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#پایان_اگر
    } وإلا {
    error_32:
        expect("register");
    }
    بعدی();
    أرجع reg;
}

ساكن فراغ parse_عملوند(TCCState *s1, عملوند *op)
{
    عبارت_مقدار e;
    صحيح reg, indir;
    ثابت حرف *p;

    indir = 0;
    إذا (tok == '*') {
        بعدی();
        indir = OP_INDIR;
    }

    إذا (tok == '%') {
        بعدی();
        إذا (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            إذا ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            وإلا إذا (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            وإلا إذا (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } وإلا إذا (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } وإلا إذا (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } وإلا إذا (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            بعدی();
            إذا (tok == '(') {
                بعدی();
                إذا (tok != TOK_PPNUM)
                    اذهب reg_error;
                p = tokc.str.داده;
                reg = p[0] - '0';
                إذا ((بیعلامت)reg >= 8 || p[1] != '\0')
                    اذهب reg_error;
                op->reg = reg;
                بعدی();
                skip(')');
            }
            إذا (op->reg == 0)
                op->type |= OP_ST0;
            اذهب no_skip;
#اگر_تعریف_شده TCC_هدف_X86_64
	} وإلا إذا (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_کم;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } وإلا إذا ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#پایان_اگر
        } وإلا {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        بعدی();
    no_skip: ;
    } وإلا إذا (tok == '$') {
        /* constant value */
        بعدی();
        asm_عبارت(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        إذا (!op->e.sym) {
            إذا (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            إذا (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            إذا (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#اگر_تعریف_شده TCC_هدف_X86_64
            إذا (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#پایان_اگر
        }
    } وإلا {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->لغزش = 0;
        إذا (tok != '(') {
            asm_عبارت(s1, &e);
            op->e = e;
        } وإلا {
            بعدی();
            إذا (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = عدم;
            } وإلا {
                /* bracketed offset expression */
                asm_عبارت(s1, &e);
                إذا (tok != ')')
                    expect(")");
                بعدی();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        إذا (tok == '(') {
	    بیعلامت صحيح type = 0;
            بعدی();
            إذا (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            إذا (tok == ',') {
                بعدی();
                إذا (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                إذا (tok == ',') {
                    بعدی();
                    op->لغزش = get_reg_لغزش(s1);
                }
            }
	    إذا (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        إذا (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC فراغ gen_expr32(عبارت_مقدار *pe)
{
    إذا (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    وإلا
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
ساكن فراغ gen_disp32(عبارت_مقدار *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    إذا (esym && esym->st_shndx == cur_متن_section->sh_رقم) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_مقدار - ind - 4);
    } وإلا {
        إذا (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = عدم;
        }
#اگر_تعریف_شده TCC_هدف_X86_64
        greloca(cur_متن_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#وإلا
        gen_addrpc32(VT_SYM, sym, pe->v);
#پایان_اگر

    }
}

/* generate the modrm operand */
ساكن مضمن صحيح asm_modrm(صحيح reg, عملوند *op)
{
    صحيح mod, reg1, reg2, sib_reg1;

    إذا (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } وإلا إذا (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#اگر_تعریف_شده TCC_هدف_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#وإلا
	g(0x05 + (reg << 3));
#پایان_اگر
	gen_expr32(&op->e);
#اگر_تعریف_شده TCC_هدف_X86_64
    } وإلا إذا (op->reg == -2) {
        عبارت_مقدار *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        أرجع ind;
#پایان_اگر
    } وإلا {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        إذا (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } وإلا إذا (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } وإلا إذا (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } وإلا {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        إذا (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        إذا (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            إذا (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->لغزش << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        إذا (mod == 0x40) {
            g(op->e.v);
        } وإلا إذا (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    أرجع 0;
}

#اگر_تعریف_شده TCC_هدف_X86_64
#تعریف_کن REX_W 0x48
#تعریف_کن REX_R 0x44
#تعریف_کن REX_X 0x42
#تعریف_کن REX_B 0x41

ساكن فراغ asm_rex(صحيح width64, عملوند *ops, صحيح nb_ops, صحيح *op_type,
		    صحيح regi, صحيح rmi)
{
  بیعلامت حرف rex = width64 ? 0x48 : 0;
  صحيح saw_بالا_8bit = 0;
  صحيح i;
  إذا (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      لكل(i = 0; i < nb_ops; i++) {
	  إذا (op_type[i] & (OP_REG | OP_ST)) {
	      إذا (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } وإلا إذا (ops[i].type & OP_REG8_کم)
		  rex |= 0x40;
	      وإلا إذا (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_بالا_8bit = ops[i].reg;
	      اكسر;
	  }
      }
  } وإلا {
      إذا (regi != -1) {
	  إذا (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } وإلا إذا (ops[regi].type & OP_REG8_کم)
	      rex |= 0x40;
	  وإلا إذا (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_بالا_8bit = ops[regi].reg;
      }
      إذا (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  إذا (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } وإلا إذا (ops[rmi].type & OP_REG8_کم)
	      rex |= 0x40;
	  وإلا إذا (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_بالا_8bit = ops[rmi].reg;
      }
      إذا (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  إذا (rex) {
      إذا (saw_بالا_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_بالا_8bit-4]);
      g(rex);
  }
}
#پایان_اگر


ساكن فراغ maybe_print_stats (فراغ)
{
    ساكن صحيح already;

    إذا (0 && !already)
    /* print stats about opcodes */
    {
        ثابت بنية ASMInstr *pa;
        صحيح freq[4];
        صحيح op_vals[500];
        صحيح nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, حجم(freq));
        لكل(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                لكل(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    إذا (pa->instr_type == op_vals[j])
                        اذهب یافت;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            یافت: ;
            //}
        }
        لكل(i=0;i<nb_op_vals;i++) {
            صحيح v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                چاپ_کن("%3d: %08x\n", i, v);
        }
        چاپ_کن("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (صحيح)حجم(asm_instrs),
	       (صحيح)حجم(asm_instrs) / (صحيح)حجم(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC فراغ asm_opcode(TCCState *s1, صحيح opcode)
{
    ثابت ASMInstr *pa;
    صحيح i, modrm_شاخص, modreg_شاخص, reg, v, op1, seg_پیشوند, pc, p;
    صحيح nb_ops, s;
    عملوند ops[MAX_OPERANDS], *برداشت;
    صحيح op_type[3]; /* decoded op type */
    صحيح alltypes;   /* OR of all operand types */
    صحيح autosize;
    صحيح p66;
#اگر_تعریف_شده TCC_هدف_X86_64
    صحيح rex64;
#پایان_اگر

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    إذا (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    برداشت = ops;
    nb_ops = 0;
    seg_پیشوند = 0;
    alltypes = 0;
    لكل(;;) {
        إذا (tok == ';' || tok == TOK_LINEFEED)
            اكسر;
        إذا (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_عملوند(s1, برداشت);
        إذا (tok == ':') {
           إذا (!(برداشت->type & OP_SEG) || seg_پیشوند)
               tcc_error("incorrect prefix");
           seg_پیشوند = segment_prefixes[برداشت->reg];
           بعدی();
           parse_عملوند(s1, برداشت);
           إذا (!(برداشت->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        برداشت++;
        nb_ops++;
        إذا (tok != ',')
            اكسر;
        بعدی();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    لكل(pa = asm_instrs; pa->sym != 0; pa++) {
	صحيح it = pa->instr_type & OPCT_ماسک;
        s = 0;
        إذا (it == OPC_FARITH) {
            v = opcode - pa->sym;
            إذا (!((بیعلامت)v < 8 * 6 && (v % 6) == 0))
                استمر;
        } وإلا إذا (it == OPC_ARITH) {
            إذا (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                استمر;
            s = (opcode - pa->sym) % NBWLX;
	    إذا ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		إذا (((opcode - pa->sym + 1) % NBWLX) == 0)
		    استمر;
	        s++;
	      }
        } وإلا إذا (it == OPC_لغزش) {
            إذا (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                استمر;
            s = (opcode - pa->sym) % NBWLX;
        } وإلا إذا (it == OPC_TEST) {
            إذا (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                استمر;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    إذا (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } وإلا إذا (pa->instr_type & OPC_B) {
#اگر_تعریف_شده TCC_هدف_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    إذا ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        استمر;
#پایان_اگر
            إذا (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                استمر;
            s = opcode - pa->sym;
        } وإلا إذا (pa->instr_type & OPC_WLX) {
            إذا (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                استمر;
            s = opcode - pa->sym + 1;
        } وإلا {
            إذا (pa->sym != opcode)
                استمر;
        }
        إذا (pa->nb_ops != nb_ops)
            استمر;
#اگر_تعریف_شده TCC_هدف_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	إذا (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    استمر;
#پایان_اگر
        /* now decode and check each operand */
	alltypes = 0;
        لكل(i = 0; i < nb_ops; i++) {
            صحيح op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            بدل(op2) {
            حالة OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                اكسر;
            حالة OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                اكسر;
            حالة OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                اكسر;
            حالة OPT_IMW:
                v = OP_IM16 | OP_IM32;
                اكسر;
	    حالة OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		اكسر;
	    حالة OPT_DISP:
	    حالة OPT_DISP8:
		v = OP_ADDR;
		اكسر;
            افتراضي:
                v = 1 << op2;
                اكسر;
            }
            إذا (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            إذا ((ops[i].type & v) == 0)
                اذهب بعدی;
	    alltypes |= ops[i].type;
        }
        (فراغ)alltypes; /* maybe unused */
        /* all is matching ! */
        اكسر;
    بعدی: ;
    }
    إذا (pa->sym == 0) {
        إذا (opcode >= TOK_ASM_اولی && opcode <= TOK_ASM_آخرین) {
            صحيح b;
            b = op0_codes[opcode - TOK_ASM_اولی];
            إذا (b & 0xff00)
                g(b >> 8);
            g(b);
            أرجع;
        } وإلا إذا (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, عدم));
        } وإلا {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = جدول_ident[opcode - TOK_IDENT];
	    إذا (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		اذهب again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#اگر_تعریف_شده TCC_هدف_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    إذا ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#پایان_اگر
    إذا (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        لكل(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            إذا ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_مقصد_اندازه[ops[i].type & OP_REG];
        }
        إذا (s == autosize) {
            إذا ((opcode == TOK_ASM_افزودن || opcode == TOK_ASM_برداشت) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    وإلا إذا ((opcode == TOK_ASM_افزودن || opcode == TOK_ASM_برداشت) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            وإلا
                tcc_error("cannot infer opcode suffix");
        }
    }

#اگر_تعریف_شده TCC_هدف_X86_64
    rex64 = 0;
    إذا (pa->instr_type & OPC_48)
        rex64 = 1;
    وإلا إذا (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	صحيح default64 = 0;
	لكل(i = 0; i < nb_ops; i++) {
	    إذا (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		اكسر;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        إذا (((opcode != TOK_ASM_افزودن && opcode != TOK_ASM_برداشت
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#پایان_اگر

    /* now generates the operation */
    إذا (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    إذا (seg_پیشوند)
        g(seg_پیشوند);
#اگر_تعریف_شده TCC_هدف_X86_64
    /* Generate addr32 prefix if needed */
    لكل(i = 0; i < nb_ops; i++) {
        إذا (ops[i].type & OP_EA32) {
	    g(0x67);
	    اكسر;
        }
    }
#پایان_اگر
    /* generate data16 prefix if needed */
    p66 = 0;
    إذا (s == 1)
        p66 = 1;
    وإلا {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        لكل (i = 0; i < nb_ops; i++)
            إذا ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    إذا (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    بدل (p) {
        حالة 0: اكسر;  /* no prefix */
        حالة 0x48: اكسر; /* REX, handled elsewhere */
        حالة 0x66:
        حالة 0x67:
        حالة 0xf2:
        حالة 0xf3: v = v & 0xff; g(p); اكسر;
        حالة 0xd4: حالة 0xd5: اكسر; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        حالة 0xd8: حالة 0xd9: حالة 0xda: حالة 0xdb: /* x87, no normal prefix */
        حالة 0xdc: حالة 0xdd: حالة 0xde: حالة 0xdf: اكسر;
        افتراضي: tcc_error("bad prefix 0x%2x in opcode table", p); اكسر;
    }
    إذا (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    إذا ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } وإلا إذا (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } وإلا إذا ((v == 0x06 || v == 0x07)) {
        إذا (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } وإلا {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } وإلا إذا (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } وإلا إذا ((pa->instr_type & (OPCT_ماسک | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_شاخص = -1;
    modreg_شاخص = -1;
    إذا (pa->instr_type & OPC_MODRM) {
	إذا (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#اگر_تعریف_شده TCC_هدف_X86_64
	    إذا (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    وإلا إذا (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#وإلا
	    إذا (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#پایان_اگر
	    وإلا
	      tcc_error("bad MODR/M opcode without operands");
	    اذهب modrm_یافت;
	}
        /* first look for an ea operand */
        لكل(i = 0;i < nb_ops; i++) {
            إذا (op_type[i] & OP_EA)
                اذهب modrm_یافت;
        }
        /* then if not found, a register or indirection (shift instructions) */
        لكل(i = 0;i < nb_ops; i++) {
            إذا (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                اذهب modrm_یافت;
        }
#اگر_تعریف_شده ASM_DEBUG
        tcc_error("bad op table");
#پایان_اگر
    modrm_یافت:
        modrm_شاخص = i;
        /* if a register is used in another operand then it is
           used instead of group */
        لكل(i = 0;i < nb_ops; i++) {
            صحيح t = op_type[i];
            إذا (i != modrm_شاخص &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_شاخص = i;
                اكسر;
            }
        }
    }
#اگر_تعریف_شده TCC_هدف_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_شاخص, modrm_شاخص);
#پایان_اگر

    إذا (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        إذا (v == 0xb0 && s >= 1)
            v += 7;
        لكل(i = 0; i < nb_ops; i++) {
            إذا (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                اكسر;
            }
        }
    }
    إذا (pa->instr_type & OPC_B)
        v += s >= 1;
    إذا (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        صحيح jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        إذا (!esym || esym->st_shndx != cur_متن_section->sh_رقم)
            اذهب no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_مقدار - ind - 2 - (v >= 0xff);
        إذا (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } وإلا {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    إذا (v == 0xeb) /* jmp */
	        v = 0xe9;
	    وإلا إذا (v == 0x70) /* jcc */
	        v += 0x0f10;
	    وإلا
	        tcc_error("invalid displacement");
        }
    }
    إذا (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_بیتها[opcode - pa->sym];
    وإلا إذا (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    إذا (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    إذا (op1)
        g(op1);
    g(v);

    إذا (OPCT_IS(pa->instr_type, OPC_لغزش)) {
        reg = (opcode - pa->sym) / NBWLX;
        إذا (reg == 6)
            reg = 7;
    } وإلا إذا (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } وإلا إذا (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } وإلا {
        reg = (pa->instr_type >> OPC_گروه_لغزش) & 7;
    }

    pc = 0;
    إذا (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	إذا (modreg_شاخص >= 0)
	    reg = ops[modreg_شاخص].reg;
        pc = asm_modrm(reg, &ops[modrm_شاخص]);
    }

    /* emit constants */
#اگر_تعریف_نشده TCC_هدف_X86_64
    إذا (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        إذا (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        أرجع;
    }
#پایان_اگر
    لكل(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        إذا (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            إذا ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                إذا (s == 0)
                    v = OP_IM8;
                وإلا إذا (s == 1)
                    v = OP_IM16;
                وإلا إذا (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                وإلا
                    v = OP_IM64;
            }

            إذا ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            إذا (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } وإلا إذا (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#اگر_تعریف_شده TCC_هدف_X86_64
            } وإلا إذا (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#پایان_اگر
	    } وإلا إذا (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } وإلا {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    إذا (pc)
        add32le(cur_متن_section->داده + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ساكن مضمن صحيح constraint_اولویت(ثابت حرف *str)
{
    صحيح اولویت, c, pr;

    /* we take the lowest priority */
    اولویت = 0;
    لكل(;;) {
        c = *str;
        إذا (c == '\0')
            اكسر;
        str++;
        بدل(c) {
        حالة 'A':
            pr = 0;
            اكسر;
        حالة 'a':
        حالة 'b':
        حالة 'c':
        حالة 'd':
        حالة 'S':
        حالة 'D':
            pr = 1;
            اكسر;
        حالة 'q':
            pr = 2;
            اكسر;
        حالة 'r':
	حالة 'R':
	حالة 'p':
            pr = 3;
            اكسر;
        حالة 'N':
        حالة 'M':
        حالة 'I':
	حالة 'e':
        حالة 'i':
        حالة 'm':
        حالة 'g':
            pr = 4;
            اكسر;
        افتراضي:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        إذا (pr > اولویت)
            اولویت = pr;
    }
    أرجع اولویت;
}

ساكن ثابت حرف *skip_constraint_modifiers(ثابت حرف *p)
{
    طالما (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    أرجع p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC صحيح asm_parse_regvar (صحيح t)
{
    ثابت حرف *s;
    عملوند op;
    إذا (t < TOK_IDENT || (t & SYM_فیلد))
        أرجع -1;
    s = جدول_ident[t - TOK_IDENT]->str;
    إذا (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_عملوند(tcc_state, &op);
    /* Accept only integer regs for now. */
    إذا (op.type & OP_REG)
        أرجع op.reg;
    وإلا
        أرجع -1;
}

#تعریف_کن REG_بیرون_ماسک 0x01
#تعریف_کن REG_درون_ماسک  0x02

#تعریف_کن is_reg_allocated(reg) (regs_allocated[reg] & reg_ماسک)

ST_FUNC فراغ asm_compute_constraints(ASMOperand *operands,
                                    صحيح nb_operands, صحيح nb_outputs,
                                    ثابت uint8_t *clobber_regs,
                                    صحيح *pout_reg)
{
    ASMOperand *op;
    صحيح sorted_op[MAX_ASM_OPERANDS];
    صحيح i, j, k, p1, p2, tmp, reg, c, reg_ماسک;
    ثابت حرف *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    لكل(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->درون_داد_شاخص = -1;
        op->ref_شاخص = -1;
        op->reg = -1;
        op->is_حافظه = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    لكل(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        إذا (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = پیدا_کن_constraint(operands, nb_operands, str, عدم);
            إذا ((بیعلامت)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_شاخص = k;
            إذا (operands[k].درون_داد_شاخص >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].درون_داد_شاخص = i;
            op->اولویت = 5;
	} وإلا إذا ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->اولویت = 1;
	    op->reg = reg;
        } وإلا {
            op->اولویت = constraint_اولویت(str);
        }
    }

    /* sort operands according to their priority */
    لكل(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    لكل(i=0;i<nb_operands - 1;i++) {
        لكل(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].اولویت;
            p2 = operands[sorted_op[j]].اولویت;
            إذا (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    لكل(i = 0;i < NB_ASM_REGS; i++) {
        إذا (clobber_regs[i])
            regs_allocated[i] = REG_درون_ماسک | REG_بیرون_ماسک;
        وإلا
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_درون_ماسک | REG_بیرون_ماسک;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_درون_ماسک | REG_بیرون_ماسک;

    /* allocate registers and generate corresponding asm moves */
    لكل(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        إذا (op->ref_شاخص >= 0)
            استمر;
        /* select if register is used for output, input or both */
        إذا (op->درون_داد_شاخص >= 0) {
            reg_ماسک = REG_درون_ماسک | REG_بیرون_ماسک;
        } وإلا إذا (j < nb_outputs) {
            reg_ماسک = REG_بیرون_ماسک;
        } وإلا {
            reg_ماسک = REG_درون_ماسک;
        }
	إذا (op->reg >= 0) {
	    إذا (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_بعدی:
        c = *str++;
        بدل(c) {
        حالة '=':
            اذهب try_بعدی;
        حالة '+':
            op->is_rw = 1;
            /* FALL THRU */
        حالة '&':
            إذا (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_ماسک = REG_درون_ماسک | REG_بیرون_ماسک;
            اذهب try_بعدی;
        حالة 'A':
            /* allocate both eax and edx */
            إذا (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                اذهب try_بعدی;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_ماسک;
            regs_allocated[TREG_XDX] |= reg_ماسک;
            اكسر;
        حالة 'a':
            reg = TREG_XAX;
            اذهب alloc_reg;
        حالة 'b':
            reg = 3;
            اذهب alloc_reg;
        حالة 'c':
            reg = TREG_XCX;
            اذهب alloc_reg;
        حالة 'd':
            reg = TREG_XDX;
            اذهب alloc_reg;
        حالة 'S':
            reg = 6;
            اذهب alloc_reg;
        حالة 'D':
            reg = 7;
        alloc_reg:
            إذا (op->reg >= 0 && reg != op->reg)
                اذهب try_بعدی;
            إذا (is_reg_allocated(reg))
                اذهب try_بعدی;
            اذهب reg_یافت;
        حالة 'q':
            /* eax, ebx, ecx or edx */
            إذا (op->reg >= 0) {
                إذا ((reg = op->reg) < 4)
                    اذهب reg_یافت;
            } وإلا لكل(reg = 0; reg < 4; reg++) {
                إذا (!is_reg_allocated(reg))
                    اذهب reg_یافت;
            }
            اذهب try_بعدی;
        حالة 'r':
	حالة 'R':
	حالة 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            إذا ((reg = op->reg) >= 0)
                اذهب reg_یافت;
            وإلا لكل(reg = 0; reg < NB_ASM_REGS; reg++) {
                إذا (!is_reg_allocated(reg))
                    اذهب reg_یافت;
            }
            اذهب try_بعدی;
        reg_یافت:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_ماسک;
            اكسر;
	حالة 'e':
        حالة 'i':
            إذا (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                اذهب try_بعدی;
            اكسر;
        حالة 'I':
        حالة 'N':
        حالة 'M':
            إذا (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                اذهب try_بعدی;
            اكسر;
        حالة 'm':
        حالة 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            إذا (j < nb_outputs || c == 'm') {
                إذا ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    لكل(reg = 0; reg < NB_ASM_REGS; reg++) {
                        إذا (!(regs_allocated[reg] & REG_درون_ماسک))
                            اذهب reg_found1;
                    }
                    اذهب try_بعدی;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_درون_ماسک;
                    op->reg = reg;
                    op->is_حافظه = 1;
                }
            }
            اكسر;
        افتراضي:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            اكسر;
        }
        /* if a reference is present for that operand, we assign it too */
        إذا (op->درون_داد_شاخص >= 0) {
            operands[op->درون_داد_شاخص].reg = op->reg;
            operands[op->درون_داد_شاخص].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    لكل(i=0;i<nb_operands;i++) {
        op = &operands[i];
        إذا (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_حافظه) {
            لكل(reg = 0; reg < NB_ASM_REGS; reg++) {
                إذا (!(regs_allocated[reg] & REG_بیرون_ماسک))
                    اذهب reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            اكسر;
        }
    }

    /* print sorted constraints */
#اگر_تعریف_شده ASM_DEBUG
    لكل(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        چاپ_کن("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, عدم) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    إذا (*pout_reg >= 0)
        چاپ_کن("out_reg=%d\n", *pout_reg);
#پایان_اگر
}

ST_FUNC فراغ subst_asm_عملوند(CString *جمع_کن_str,
                              SValue *sv, صحيح modifier)
{
    صحيح r, reg, اندازه, val;

    r = sv->r;
    إذا ((r & VT_VALMASK) == VT_CONST) {
        إذا (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(جمع_کن_str, '$');
        إذا (r & VT_SYM) {
	    ثابت حرف *name = get_tok_str(sv->sym->v, عدم);
	    إذا (sv->sym->v >= SYM_اولی_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            إذا (tcc_state->leading_underscore)
              cstr_ccat(جمع_کن_str, '_');
            cstr_cat(جمع_کن_str, name, -1);
            إذا ((uint32_t)sv->c.i == 0)
                اذهب no_جابه_جایی;
	    cstr_ccat(جمع_کن_str, '+');
        }
        val = sv->c.i;
        إذا (modifier == 'n')
            val = -val;
        cstr_printf(جمع_کن_str, "%d", val);
    no_جابه_جایی:;
#اگر_تعریف_شده TCC_هدف_X86_64
        إذا (r & VT_LVAL)
            cstr_cat(جمع_کن_str, "(%rip)", -1);
#پایان_اگر
    } وإلا إذا ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(جمع_کن_str, "%d(%%%s)", (صحيح)sv->c.i, get_tok_str(TOK_ASM_xax + 5, عدم));
    } وإلا إذا (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        إذا (reg >= VT_CONST)
            tcc_داخلی_error("");
        cstr_printf(جمع_کن_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, عدم));
    } وإلا {
        /* register case */
        reg = r & VT_VALMASK;
        إذا (reg >= VT_CONST)
            tcc_داخلی_error("");

        /* choose register operand size */
        إذا ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            اندازه = 1;
        وإلا إذا ((sv->type.t & VT_BTYPE) == VT_SHORT)
            اندازه = 2;
#اگر_تعریف_شده TCC_هدف_X86_64
        وإلا إذا ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            اندازه = 8;
#پایان_اگر
        وإلا
            اندازه = 4;
        إذا (اندازه == 1 && reg >= 4)
            اندازه = 4;

        إذا (modifier == 'b') {
            إذا (reg >= 4)
                tcc_error("cannot use byte register");
            اندازه = 1;
        } وإلا إذا (modifier == 'h') {
            إذا (reg >= 4)
                tcc_error("cannot use byte register");
            اندازه = -1;
        } وإلا إذا (modifier == 'w') {
            اندازه = 2;
        } وإلا إذا (modifier == 'k') {
            اندازه = 4;
#اگر_تعریف_شده TCC_هدف_X86_64
        } وإلا إذا (modifier == 'q') {
            اندازه = 8;
#پایان_اگر
        }

        إذا (reg >= 8) {
            cstr_printf(جمع_کن_str, "%%r%d%c", reg, (اندازه == 1) ? 'b' : ((اندازه == 2) ? 'w' : ((اندازه == 4) ? 'd' : ' ')));
            أرجع;
        }
        بدل(اندازه) {
        حالة -1:
            reg = TOK_ASM_ah + reg;
            اكسر;
        حالة 1:
            reg = TOK_ASM_al + reg;
            اكسر;
        حالة 2:
            reg = TOK_ASM_ax + reg;
            اكسر;
        افتراضي:
            reg = TOK_ASM_eax + reg;
            اكسر;
#اگر_تعریف_شده TCC_هدف_X86_64
        حالة 8:
            reg = TOK_ASM_rax + reg;
            اكسر;
#پایان_اگر
        }
        cstr_printf(جمع_کن_str, "%%%s", get_tok_str(reg, عدم));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC فراغ asm_gen_کد(ASMOperand *operands, صحيح nb_operands,
                         صحيح nb_outputs, صحيح is_output,
                         uint8_t *clobber_regs,
                         صحيح بیرون_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    صحيح i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#اگر_تعریف_شده TCC_هدف_X86_64
#اگر_تعریف_شده TCC_هدف_PE
    ساكن ثابت uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#وإلا
    ساكن ثابت uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#پایان_اگر
#وإلا
    ساكن ثابت uint8_t reg_saved[] = { 3, 6, 7 };
#پایان_اگر

    /* mark all used registers */
    کپی_حافظه(regs_allocated, clobber_regs, حجم(regs_allocated));
    لكل(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        إذا (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    إذا (!is_output) {
        /* generate reg save code */
        لكل(i = 0; i < حجم(reg_saved)/حجم(reg_saved[0]); i++) {
            reg = reg_saved[i];
            إذا (regs_allocated[reg]) {
		إذا (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        لكل(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            إذا (op->reg >= 0) {
                إذا ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_حافظه) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    بارگیری(op->reg, &sv);
                } وإلا إذا (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    بارگیری(op->reg, op->vt);
                    إذا (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        بارگیری(TREG_XDX, &sv);
                    }
                }
            }
        }
    } وإلا {
        /* generate save code */
        لكل(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            إذا (op->reg >= 0) {
                إذا ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    إذا (!op->is_حافظه) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        بارگیری(بیرون_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | بیرون_reg;
                        store(op->reg, &sv);
                    }
                } وإلا {
                    store(op->reg, op->vt);
                    إذا (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        لكل(i = حجم(reg_saved)/حجم(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            إذا (regs_allocated[reg]) {
		إذا (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC فراغ asm_clobber(uint8_t *clobber_regs, ثابت حرف *str)
{
    صحيح reg;
#اگر_تعریف_شده TCC_هدف_X86_64
    بیعلامت صحيح type;
#پایان_اگر

    إذا (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        أرجع;
    reg = tok_alloc_const(str);
    إذا (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } وإلا إذا (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#اگر_تعریف_شده TCC_هدف_X86_64
    } وإلا إذا (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } وإلا إذا ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#پایان_اگر
    } وإلا {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
