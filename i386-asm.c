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

#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"

#تعریف_کرو MAX_OPERANDS 3

#تعریف_کرو TOK_ASM_پہلا TOK_ASM_clc
#تعریف_کرو TOK_ASM_آخری TOK_ASM_emms
#تعریف_کرو TOK_ASM_alllast TOK_ASM_subps

#تعریف_کرو OPC_B          0x01  /* only used with OPC_WL */
#تعریف_کرو OPC_WL         0x02  /* accepts w, l or no suffix */
#تعریف_کرو OPC_BWL        (OPC_B | OPC_WL) /* accepts b, w, l or no suffix */
#تعریف_کرو OPC_REG        0x04 /* register is added to opcode */
#تعریف_کرو OPC_MODRM      0x08 /* modrm encoding */

#تعریف_کرو OPCT_نقاب      0x70
#تعریف_کرو OPC_FWAIT      0x10 /* add fwait opcode */
#تعریف_کرو OPC_سرکاؤ      0x20 /* shift opcodes */
#تعریف_کرو OPC_ARITH      0x30 /* arithmetic opcodes */
#تعریف_کرو OPC_FARITH     0x40 /* FPU arithmetic opcodes */
#تعریف_کرو OPC_TEST       0x50 /* test opcodes */
#تعریف_کرو OPC_0F01       0x60 /* 0x0f01XX (group 7, XX is 2nd opcode,
                               no operands and unstructured mod/rm) */
#تعریف_کرو OPCT_IS(v,i) (((v) & OPCT_نقاب) == (i))

#تعریف_کرو OPC_0F        0x100 /* Is secondary map (0x0f prefix) */
#تعریف_کرو OPC_48        0x200 /* Always has REX prefix */
#اگر_تعریف_شدہ TCC_ہدف_X86_64
# define OPC_WLQ     0x1000  /* accepts w, l, q or no suffix */
# define OPC_BWLQ    (OPC_B | OPC_WLQ) /* accepts b, w, l, q or no suffix */
# define OPC_WLX     OPC_WLQ
# define OPC_BWLX    OPC_BWLQ
#ورنہ
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#اگر_ختم

#تعریف_کرو OPC_گروہ_سرکاؤ 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
شمار {
    OPT_REG8=0, /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG16,  /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG32,  /* warning: value is hardcoded from TOK_ASM_xxx */
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    OPT_REG64,  /* warning: value is hardcoded from TOK_ASM_xxx */
#اگر_ختم
    OPT_MMX,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SSE,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_CR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_TR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_DB,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SEG,
    OPT_ST,
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    OPT_REG8_کم, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
		     with REX prefix, not used in insn templates */
#اگر_ختم
    OPT_IM8,
    OPT_IM8S,
    OPT_IM16,
    OPT_IM32,
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    OPT_IM64,
#اگر_ختم
    OPT_EAX,    /* %al, %ax, %eax or %rax register */
    OPT_ST0,    /* %st(0) register */
    OPT_CL,     /* %cl register */
    OPT_DX,     /* %dx register */
    OPT_ADDR,   /* OP_EA with only offset */
    OPT_INDIR,  /* *(expr) */
    /* composite types */
    OPT_مرکب_پہلا,
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

#تعریف_کرو OP_REG8   (1 << OPT_REG8)
#تعریف_کرو OP_REG16  (1 << OPT_REG16)
#تعریف_کرو OP_REG32  (1 << OPT_REG32)
#تعریف_کرو OP_MMX    (1 << OPT_MMX)
#تعریف_کرو OP_SSE    (1 << OPT_SSE)
#تعریف_کرو OP_CR     (1 << OPT_CR)
#تعریف_کرو OP_TR     (1 << OPT_TR)
#تعریف_کرو OP_DB     (1 << OPT_DB)
#تعریف_کرو OP_SEG    (1 << OPT_SEG)
#تعریف_کرو OP_ST     (1 << OPT_ST)
#تعریف_کرو OP_IM8    (1 << OPT_IM8)
#تعریف_کرو OP_IM8S   (1 << OPT_IM8S)
#تعریف_کرو OP_IM16   (1 << OPT_IM16)
#تعریف_کرو OP_IM32   (1 << OPT_IM32)
#تعریف_کرو OP_EAX    (1 << OPT_EAX)
#تعریف_کرو OP_ST0    (1 << OPT_ST0)
#تعریف_کرو OP_CL     (1 << OPT_CL)
#تعریف_کرو OP_DX     (1 << OPT_DX)
#تعریف_کرو OP_ADDR   (1 << OPT_ADDR)
#تعریف_کرو OP_INDIR  (1 << OPT_INDIR)
#اگر_تعریف_شدہ TCC_ہدف_X86_64
# define OP_REG64 (1 << OPT_REG64)
# define OP_REG8_کم (1 << OPT_REG8_کم)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#ورنہ
# define OP_REG64 0
# define OP_REG8_کم 0
# define OP_IM64  0
# define OP_EA32  0
#اگر_ختم

#تعریف_کرو OP_EA     0x40000000u
#تعریف_کرو OP_REG    (OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64)

#اگر_تعریف_شدہ TCC_ہدف_X86_64
# define TREG_XAX   TREG_RAX
# define TREG_XCX   TREG_RCX
# define TREG_XDX   TREG_RDX
# define TOK_ASM_xax TOK_ASM_rax
#ورنہ
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#اگر_ختم

قسمتعریف ساخت ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

قسمتعریف ساخت عملیہ {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t سرکاؤ;
    اظہاریہ_قدر e;
} عملیہ;

ساکن ثابت uint8_t reg_مقصد_سائز[9] = {
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

#تعریف_کرو NB_TEST_OPCODES 30

ساکن ثابت uint8_t test_بٹ[NB_TEST_OPCODES] = {
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

ساکن ثابت uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

ساکن ثابت ASMInstr asm_instrs[] = {
#تعریف_کرو ALT(x) x
/* This removes a 0x0f in the second byte */
#تعریف_کرو O(o) ((uint64_t) ((((o) & 0xff00) == 0x0f00) ? ((((o) >> 8) & ~0xff) | ((o) & 0xff)) : (o)))
/* This constructs instr_type from opcode, type and group.  */
#تعریف_کرو T(o,i,g) ((i) | ((g) << OPC_گروہ_سرکاؤ) | ((((o) & 0xff00) == 0x0f00) ? OPC_0F : 0))
#تعریف_کرو DEF_ASM_OP0(name, opcode)
#تعریف_کرو DEF_ASM_OP0L(name, opcode, گروہ, instr_type) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, گروہ), 0, { 0 } },
#تعریف_کرو DEF_ASM_OP1(name, opcode, گروہ, instr_type, op0) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, گروہ), 1, { op0 }},
#تعریف_کرو DEF_ASM_OP2(name, opcode, گروہ, instr_type, op0, op1) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, گروہ), 2, { op0, op1 }},
#تعریف_کرو DEF_ASM_OP3(name, opcode, گروہ, instr_type, op0, op1, op2) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, گروہ), 3, { op0, op1, op2 }},
#اگر_تعریف_شدہ TCC_ہدف_X86_64
# include "x86_64-asm.h"
#ورنہ
# include "i386-asm.h"
#اگر_ختم
    /* last operation */
    { 0, },
};

ساکن ثابت uint16_t op0_codes[] = {
#تعریف_کرو ALT(x)
#تعریف_کرو DEF_ASM_OP0(x, opcode) opcode,
#تعریف_کرو DEF_ASM_OP0L(name, opcode, گروہ, instr_type)
#تعریف_کرو DEF_ASM_OP1(name, opcode, گروہ, instr_type, op0)
#تعریف_کرو DEF_ASM_OP2(name, opcode, گروہ, instr_type, op0, op1)
#تعریف_کرو DEF_ASM_OP3(name, opcode, گروہ, instr_type, op0, op1, op2)
#اگر_تعریف_شدہ TCC_ہدف_X86_64
# include "x86_64-asm.h"
#ورنہ
# include "i386-asm.h"
#اگر_ختم
};

ساکن اندرونی صحیح get_reg_سرکاؤ(TCCState *s1)
{
    صحیح سرکاؤ, v;
    v = asm_int_اظہاریہ(s1);
    انتخاب(v) {
    حالت 1:
        سرکاؤ = 0;
        توڑو;
    حالت 2:
        سرکاؤ = 1;
        توڑو;
    حالت 4:
        سرکاؤ = 2;
        توڑو;
    حالت 8:
        سرکاؤ = 3;
        توڑو;
    طےشدہ:
        expect("1, 2, 4 or 8 constant");
        سرکاؤ = 0;
        توڑو;
    }
    واپس سرکاؤ;
}

#اگر_تعریف_شدہ TCC_ہدف_X86_64
ساکن صحیح asm_parse_numeric_reg(صحیح t, غیرعلامتی صحیح *type)
{
    صحیح reg = -1;
    اگر (t >= TOK_IDENT && t < tok_ident) {
	ثابت حرف *s = جدول_ident[t - TOK_IDENT]->str;
	حرف c;
	*type = OP_REG64;
	اگر (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	اگر (*s++ != 'r')
	  واپس -1;
	/* Don't allow leading '0'.  */
	اگر ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	ورنہ
	  واپس -1;
	اگر ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	اگر (reg > 15)
	  واپس -1;
	اگر ((c = *s) == 0)
	  ;
	ورنہ اگر (*type != OP_REG64)
	  واپس -1;
	ورنہ اگر (c == 'b' && !s[1])
	  *type = OP_REG8;
	ورنہ اگر (c == 'w' && !s[1])
	  *type = OP_REG16;
	ورنہ اگر (c == 'd' && !s[1])
	  *type = OP_REG32;
	ورنہ
	  واپس -1;
    }
    واپس reg;
}
#اگر_ختم

ساکن صحیح asm_parse_reg(غیرعلامتی صحیح *type)
{
    صحیح reg = 0;
    *type = 0;
    اگر (tok != '%')
        جاؤ error_32;
    اگلا();
    اگر (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    } ورنہ اگر (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } ورنہ اگر (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } ورنہ اگر ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#اگر_ختم
    } ورنہ {
    error_32:
        expect("register");
    }
    اگلا();
    واپس reg;
}

ساکن خالی parse_عملیہ(TCCState *s1, عملیہ *op)
{
    اظہاریہ_قدر e;
    صحیح reg, indir;
    ثابت حرف *p;

    indir = 0;
    اگر (tok == '*') {
        اگلا();
        indir = OP_INDIR;
    }

    اگر (tok == '%') {
        اگلا();
        اگر (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            اگر ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            ورنہ اگر (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            ورنہ اگر (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } ورنہ اگر (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } ورنہ اگر (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } ورنہ اگر (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            اگلا();
            اگر (tok == '(') {
                اگلا();
                اگر (tok != TOK_PPNUM)
                    جاؤ reg_error;
                p = tokc.str.ڈیٹا;
                reg = p[0] - '0';
                اگر ((غیرعلامتی)reg >= 8 || p[1] != '\0')
                    جاؤ reg_error;
                op->reg = reg;
                اگلا();
                skip(')');
            }
            اگر (op->reg == 0)
                op->type |= OP_ST0;
            جاؤ no_skip;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
	} ورنہ اگر (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_کم;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } ورنہ اگر ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#اگر_ختم
        } ورنہ {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        اگلا();
    no_skip: ;
    } ورنہ اگر (tok == '$') {
        /* constant value */
        اگلا();
        asm_اظہاریہ(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        اگر (!op->e.sym) {
            اگر (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            اگر (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            اگر (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
            اگر (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#اگر_ختم
        }
    } ورنہ {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->سرکاؤ = 0;
        اگر (tok != '(') {
            asm_اظہاریہ(s1, &e);
            op->e = e;
        } ورنہ {
            اگلا();
            اگر (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = تہی;
            } ورنہ {
                /* bracketed offset expression */
                asm_اظہاریہ(s1, &e);
                اگر (tok != ')')
                    expect(")");
                اگلا();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        اگر (tok == '(') {
	    غیرعلامتی صحیح type = 0;
            اگلا();
            اگر (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            اگر (tok == ',') {
                اگلا();
                اگر (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                اگر (tok == ',') {
                    اگلا();
                    op->سرکاؤ = get_reg_سرکاؤ(s1);
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
ST_FUNC خالی gen_expr32(اظہاریہ_قدر *pe)
{
    اگر (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    ورنہ
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
ساکن خالی gen_disp32(اظہاریہ_قدر *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    اگر (esym && esym->st_shndx == cur_متن_section->sh_عدد) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_قدر - ind - 4);
    } ورنہ {
        اگر (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = تہی;
        }
#اگر_تعریف_شدہ TCC_ہدف_X86_64
        greloca(cur_متن_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#ورنہ
        gen_addrpc32(VT_SYM, sym, pe->v);
#اگر_ختم

    }
}

/* generate the modrm operand */
ساکن اندرونی صحیح asm_modrm(صحیح reg, عملیہ *op)
{
    صحیح mod, reg1, reg2, sib_reg1;

    اگر (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } ورنہ اگر (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#اگر_تعریف_شدہ TCC_ہدف_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#ورنہ
	g(0x05 + (reg << 3));
#اگر_ختم
	gen_expr32(&op->e);
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    } ورنہ اگر (op->reg == -2) {
        اظہاریہ_قدر *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        واپس ind;
#اگر_ختم
    } ورنہ {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        اگر (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } ورنہ اگر (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } ورنہ اگر (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } ورنہ {
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
            g((op->سرکاؤ << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        اگر (mod == 0x40) {
            g(op->e.v);
        } ورنہ اگر (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    واپس 0;
}

#اگر_تعریف_شدہ TCC_ہدف_X86_64
#تعریف_کرو REX_W 0x48
#تعریف_کرو REX_R 0x44
#تعریف_کرو REX_X 0x42
#تعریف_کرو REX_B 0x41

ساکن خالی asm_rex(صحیح width64, عملیہ *ops, صحیح nb_ops, صحیح *op_type,
		    صحیح regi, صحیح rmi)
{
  غیرعلامتی حرف rex = width64 ? 0x48 : 0;
  صحیح saw_بلند_8bit = 0;
  صحیح i;
  اگر (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      برائے(i = 0; i < nb_ops; i++) {
	  اگر (op_type[i] & (OP_REG | OP_ST)) {
	      اگر (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } ورنہ اگر (ops[i].type & OP_REG8_کم)
		  rex |= 0x40;
	      ورنہ اگر (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_بلند_8bit = ops[i].reg;
	      توڑو;
	  }
      }
  } ورنہ {
      اگر (regi != -1) {
	  اگر (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } ورنہ اگر (ops[regi].type & OP_REG8_کم)
	      rex |= 0x40;
	  ورنہ اگر (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_بلند_8bit = ops[regi].reg;
      }
      اگر (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  اگر (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } ورنہ اگر (ops[rmi].type & OP_REG8_کم)
	      rex |= 0x40;
	  ورنہ اگر (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_بلند_8bit = ops[rmi].reg;
      }
      اگر (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  اگر (rex) {
      اگر (saw_بلند_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_بلند_8bit-4]);
      g(rex);
  }
}
#اگر_ختم


ساکن خالی maybe_print_stats (خالی)
{
    ساکن صحیح already;

    اگر (0 && !already)
    /* print stats about opcodes */
    {
        ثابت ساخت ASMInstr *pa;
        صحیح freq[4];
        صحیح op_vals[500];
        صحیح nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, حجم(freq));
        برائے(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                برائے(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    اگر (pa->instr_type == op_vals[j])
                        جاؤ ملا;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            ملا: ;
            //}
        }
        برائے(i=0;i<nb_op_vals;i++) {
            صحیح v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                لکھو("%3d: %08x\n", i, v);
        }
        لکھو("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (صحیح)حجم(asm_instrs),
	       (صحیح)حجم(asm_instrs) / (صحیح)حجم(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC خالی asm_opcode(TCCState *s1, صحیح opcode)
{
    ثابت ASMInstr *pa;
    صحیح i, modrm_اشاریہ, modreg_اشاریہ, reg, v, op1, seg_سابقہ, pc, p;
    صحیح nb_ops, s;
    عملیہ ops[MAX_OPERANDS], *نکالو;
    صحیح op_type[3]; /* decoded op type */
    صحیح alltypes;   /* OR of all operand types */
    صحیح autosize;
    صحیح p66;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    صحیح rex64;
#اگر_ختم

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    اگر (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    نکالو = ops;
    nb_ops = 0;
    seg_سابقہ = 0;
    alltypes = 0;
    برائے(;;) {
        اگر (tok == ';' || tok == TOK_LINEFEED)
            توڑو;
        اگر (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_عملیہ(s1, نکالو);
        اگر (tok == ':') {
           اگر (!(نکالو->type & OP_SEG) || seg_سابقہ)
               tcc_error("incorrect prefix");
           seg_سابقہ = segment_prefixes[نکالو->reg];
           اگلا();
           parse_عملیہ(s1, نکالو);
           اگر (!(نکالو->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        نکالو++;
        nb_ops++;
        اگر (tok != ',')
            توڑو;
        اگلا();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    برائے(pa = asm_instrs; pa->sym != 0; pa++) {
	صحیح it = pa->instr_type & OPCT_نقاب;
        s = 0;
        اگر (it == OPC_FARITH) {
            v = opcode - pa->sym;
            اگر (!((غیرعلامتی)v < 8 * 6 && (v % 6) == 0))
                جاری;
        } ورنہ اگر (it == OPC_ARITH) {
            اگر (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                جاری;
            s = (opcode - pa->sym) % NBWLX;
	    اگر ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		اگر (((opcode - pa->sym + 1) % NBWLX) == 0)
		    جاری;
	        s++;
	      }
        } ورنہ اگر (it == OPC_سرکاؤ) {
            اگر (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                جاری;
            s = (opcode - pa->sym) % NBWLX;
        } ورنہ اگر (it == OPC_TEST) {
            اگر (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                جاری;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    اگر (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } ورنہ اگر (pa->instr_type & OPC_B) {
#اگر_تعریف_شدہ TCC_ہدف_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    اگر ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        جاری;
#اگر_ختم
            اگر (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                جاری;
            s = opcode - pa->sym;
        } ورنہ اگر (pa->instr_type & OPC_WLX) {
            اگر (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                جاری;
            s = opcode - pa->sym + 1;
        } ورنہ {
            اگر (pa->sym != opcode)
                جاری;
        }
        اگر (pa->nb_ops != nb_ops)
            جاری;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	اگر (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    جاری;
#اگر_ختم
        /* now decode and check each operand */
	alltypes = 0;
        برائے(i = 0; i < nb_ops; i++) {
            صحیح op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            انتخاب(op2) {
            حالت OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                توڑو;
            حالت OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                توڑو;
            حالت OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                توڑو;
            حالت OPT_IMW:
                v = OP_IM16 | OP_IM32;
                توڑو;
	    حالت OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		توڑو;
	    حالت OPT_DISP:
	    حالت OPT_DISP8:
		v = OP_ADDR;
		توڑو;
            طےشدہ:
                v = 1 << op2;
                توڑو;
            }
            اگر (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            اگر ((ops[i].type & v) == 0)
                جاؤ اگلا;
	    alltypes |= ops[i].type;
        }
        (خالی)alltypes; /* maybe unused */
        /* all is matching ! */
        توڑو;
    اگلا: ;
    }
    اگر (pa->sym == 0) {
        اگر (opcode >= TOK_ASM_پہلا && opcode <= TOK_ASM_آخری) {
            صحیح b;
            b = op0_codes[opcode - TOK_ASM_پہلا];
            اگر (b & 0xff00)
                g(b >> 8);
            g(b);
            واپس;
        } ورنہ اگر (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, تہی));
        } ورنہ {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = جدول_ident[opcode - TOK_IDENT];
	    اگر (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		جاؤ again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    اگر ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#اگر_ختم
    اگر (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        برائے(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            اگر ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_مقصد_سائز[ops[i].type & OP_REG];
        }
        اگر (s == autosize) {
            اگر ((opcode == TOK_ASM_ڈالو || opcode == TOK_ASM_نکالو) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    ورنہ اگر ((opcode == TOK_ASM_ڈالو || opcode == TOK_ASM_نکالو) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            ورنہ
                tcc_error("cannot infer opcode suffix");
        }
    }

#اگر_تعریف_شدہ TCC_ہدف_X86_64
    rex64 = 0;
    اگر (pa->instr_type & OPC_48)
        rex64 = 1;
    ورنہ اگر (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	صحیح default64 = 0;
	برائے(i = 0; i < nb_ops; i++) {
	    اگر (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		توڑو;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        اگر (((opcode != TOK_ASM_ڈالو && opcode != TOK_ASM_نکالو
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#اگر_ختم

    /* now generates the operation */
    اگر (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    اگر (seg_سابقہ)
        g(seg_سابقہ);
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    /* Generate addr32 prefix if needed */
    برائے(i = 0; i < nb_ops; i++) {
        اگر (ops[i].type & OP_EA32) {
	    g(0x67);
	    توڑو;
        }
    }
#اگر_ختم
    /* generate data16 prefix if needed */
    p66 = 0;
    اگر (s == 1)
        p66 = 1;
    ورنہ {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        برائے (i = 0; i < nb_ops; i++)
            اگر ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    اگر (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    انتخاب (p) {
        حالت 0: توڑو;  /* no prefix */
        حالت 0x48: توڑو; /* REX, handled elsewhere */
        حالت 0x66:
        حالت 0x67:
        حالت 0xf2:
        حالت 0xf3: v = v & 0xff; g(p); توڑو;
        حالت 0xd4: حالت 0xd5: توڑو; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        حالت 0xd8: حالت 0xd9: حالت 0xda: حالت 0xdb: /* x87, no normal prefix */
        حالت 0xdc: حالت 0xdd: حالت 0xde: حالت 0xdf: توڑو;
        طےشدہ: tcc_error("bad prefix 0x%2x in opcode table", p); توڑو;
    }
    اگر (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    اگر ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } ورنہ اگر (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } ورنہ اگر ((v == 0x06 || v == 0x07)) {
        اگر (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } ورنہ {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } ورنہ اگر (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } ورنہ اگر ((pa->instr_type & (OPCT_نقاب | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_اشاریہ = -1;
    modreg_اشاریہ = -1;
    اگر (pa->instr_type & OPC_MODRM) {
	اگر (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
	    اگر (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    ورنہ اگر (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#ورنہ
	    اگر (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#اگر_ختم
	    ورنہ
	      tcc_error("bad MODR/M opcode without operands");
	    جاؤ modrm_ملا;
	}
        /* first look for an ea operand */
        برائے(i = 0;i < nb_ops; i++) {
            اگر (op_type[i] & OP_EA)
                جاؤ modrm_ملا;
        }
        /* then if not found, a register or indirection (shift instructions) */
        برائے(i = 0;i < nb_ops; i++) {
            اگر (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                جاؤ modrm_ملا;
        }
#اگر_تعریف_شدہ ASM_DEBUG
        tcc_error("bad op table");
#اگر_ختم
    modrm_ملا:
        modrm_اشاریہ = i;
        /* if a register is used in another operand then it is
           used instead of group */
        برائے(i = 0;i < nb_ops; i++) {
            صحیح t = op_type[i];
            اگر (i != modrm_اشاریہ &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_اشاریہ = i;
                توڑو;
            }
        }
    }
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_اشاریہ, modrm_اشاریہ);
#اگر_ختم

    اگر (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        اگر (v == 0xb0 && s >= 1)
            v += 7;
        برائے(i = 0; i < nb_ops; i++) {
            اگر (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                توڑو;
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
        اگر (!esym || esym->st_shndx != cur_متن_section->sh_عدد)
            جاؤ no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_قدر - ind - 2 - (v >= 0xff);
        اگر (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } ورنہ {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    اگر (v == 0xeb) /* jmp */
	        v = 0xe9;
	    ورنہ اگر (v == 0x70) /* jcc */
	        v += 0x0f10;
	    ورنہ
	        tcc_error("invalid displacement");
        }
    }
    اگر (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_بٹ[opcode - pa->sym];
    ورنہ اگر (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    اگر (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    اگر (op1)
        g(op1);
    g(v);

    اگر (OPCT_IS(pa->instr_type, OPC_سرکاؤ)) {
        reg = (opcode - pa->sym) / NBWLX;
        اگر (reg == 6)
            reg = 7;
    } ورنہ اگر (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } ورنہ اگر (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } ورنہ {
        reg = (pa->instr_type >> OPC_گروہ_سرکاؤ) & 7;
    }

    pc = 0;
    اگر (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	اگر (modreg_اشاریہ >= 0)
	    reg = ops[modreg_اشاریہ].reg;
        pc = asm_modrm(reg, &ops[modrm_اشاریہ]);
    }

    /* emit constants */
#اگر_غیر_تعریف_شدہ TCC_ہدف_X86_64
    اگر (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        اگر (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        واپس;
    }
#اگر_ختم
    برائے(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        اگر (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            اگر ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                اگر (s == 0)
                    v = OP_IM8;
                ورنہ اگر (s == 1)
                    v = OP_IM16;
                ورنہ اگر (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                ورنہ
                    v = OP_IM64;
            }

            اگر ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            اگر (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } ورنہ اگر (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#اگر_تعریف_شدہ TCC_ہدف_X86_64
            } ورنہ اگر (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#اگر_ختم
	    } ورنہ اگر (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } ورنہ {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    اگر (pc)
        add32le(cur_متن_section->ڈیٹا + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ساکن اندرونی صحیح constraint_ترجیح(ثابت حرف *str)
{
    صحیح ترجیح, c, pr;

    /* we take the lowest priority */
    ترجیح = 0;
    برائے(;;) {
        c = *str;
        اگر (c == '\0')
            توڑو;
        str++;
        انتخاب(c) {
        حالت 'A':
            pr = 0;
            توڑو;
        حالت 'a':
        حالت 'b':
        حالت 'c':
        حالت 'd':
        حالت 'S':
        حالت 'D':
            pr = 1;
            توڑو;
        حالت 'q':
            pr = 2;
            توڑو;
        حالت 'r':
	حالت 'R':
	حالت 'p':
            pr = 3;
            توڑو;
        حالت 'N':
        حالت 'M':
        حالت 'I':
	حالت 'e':
        حالت 'i':
        حالت 'm':
        حالت 'g':
            pr = 4;
            توڑو;
        طےشدہ:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        اگر (pr > ترجیح)
            ترجیح = pr;
    }
    واپس ترجیح;
}

ساکن ثابت حرف *skip_constraint_modifiers(ثابت حرف *p)
{
    جب (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    واپس p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC صحیح asm_parse_regvar (صحیح t)
{
    ثابت حرف *s;
    عملیہ op;
    اگر (t < TOK_IDENT || (t & SYM_میدان))
        واپس -1;
    s = جدول_ident[t - TOK_IDENT]->str;
    اگر (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_عملیہ(tcc_state, &op);
    /* Accept only integer regs for now. */
    اگر (op.type & OP_REG)
        واپس op.reg;
    ورنہ
        واپس -1;
}

#تعریف_کرو REG_برآمد_نقاب 0x01
#تعریف_کرو REG_اندر_نقاب  0x02

#تعریف_کرو is_reg_allocated(reg) (regs_allocated[reg] & reg_نقاب)

ST_FUNC خالی asm_compute_constraints(ASMOperand *operands,
                                    صحیح nb_operands, صحیح nb_outputs,
                                    ثابت uint8_t *clobber_regs,
                                    صحیح *pout_reg)
{
    ASMOperand *op;
    صحیح sorted_op[MAX_ASM_OPERANDS];
    صحیح i, j, k, p1, p2, tmp, reg, c, reg_نقاب;
    ثابت حرف *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    برائے(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->داخلہ_اشاریہ = -1;
        op->ref_اشاریہ = -1;
        op->reg = -1;
        op->is_حافظہ = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    برائے(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        اگر (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = ڈھونڈو_constraint(operands, nb_operands, str, تہی);
            اگر ((غیرعلامتی)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_اشاریہ = k;
            اگر (operands[k].داخلہ_اشاریہ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].داخلہ_اشاریہ = i;
            op->ترجیح = 5;
	} ورنہ اگر ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->ترجیح = 1;
	    op->reg = reg;
        } ورنہ {
            op->ترجیح = constraint_ترجیح(str);
        }
    }

    /* sort operands according to their priority */
    برائے(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    برائے(i=0;i<nb_operands - 1;i++) {
        برائے(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].ترجیح;
            p2 = operands[sorted_op[j]].ترجیح;
            اگر (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    برائے(i = 0;i < NB_ASM_REGS; i++) {
        اگر (clobber_regs[i])
            regs_allocated[i] = REG_اندر_نقاب | REG_برآمد_نقاب;
        ورنہ
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_اندر_نقاب | REG_برآمد_نقاب;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_اندر_نقاب | REG_برآمد_نقاب;

    /* allocate registers and generate corresponding asm moves */
    برائے(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        اگر (op->ref_اشاریہ >= 0)
            جاری;
        /* select if register is used for output, input or both */
        اگر (op->داخلہ_اشاریہ >= 0) {
            reg_نقاب = REG_اندر_نقاب | REG_برآمد_نقاب;
        } ورنہ اگر (j < nb_outputs) {
            reg_نقاب = REG_برآمد_نقاب;
        } ورنہ {
            reg_نقاب = REG_اندر_نقاب;
        }
	اگر (op->reg >= 0) {
	    اگر (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_اگلا:
        c = *str++;
        انتخاب(c) {
        حالت '=':
            جاؤ try_اگلا;
        حالت '+':
            op->is_rw = 1;
            /* FALL THRU */
        حالت '&':
            اگر (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_نقاب = REG_اندر_نقاب | REG_برآمد_نقاب;
            جاؤ try_اگلا;
        حالت 'A':
            /* allocate both eax and edx */
            اگر (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                جاؤ try_اگلا;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_نقاب;
            regs_allocated[TREG_XDX] |= reg_نقاب;
            توڑو;
        حالت 'a':
            reg = TREG_XAX;
            جاؤ alloc_reg;
        حالت 'b':
            reg = 3;
            جاؤ alloc_reg;
        حالت 'c':
            reg = TREG_XCX;
            جاؤ alloc_reg;
        حالت 'd':
            reg = TREG_XDX;
            جاؤ alloc_reg;
        حالت 'S':
            reg = 6;
            جاؤ alloc_reg;
        حالت 'D':
            reg = 7;
        alloc_reg:
            اگر (op->reg >= 0 && reg != op->reg)
                جاؤ try_اگلا;
            اگر (is_reg_allocated(reg))
                جاؤ try_اگلا;
            جاؤ reg_ملا;
        حالت 'q':
            /* eax, ebx, ecx or edx */
            اگر (op->reg >= 0) {
                اگر ((reg = op->reg) < 4)
                    جاؤ reg_ملا;
            } ورنہ برائے(reg = 0; reg < 4; reg++) {
                اگر (!is_reg_allocated(reg))
                    جاؤ reg_ملا;
            }
            جاؤ try_اگلا;
        حالت 'r':
	حالت 'R':
	حالت 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            اگر ((reg = op->reg) >= 0)
                جاؤ reg_ملا;
            ورنہ برائے(reg = 0; reg < NB_ASM_REGS; reg++) {
                اگر (!is_reg_allocated(reg))
                    جاؤ reg_ملا;
            }
            جاؤ try_اگلا;
        reg_ملا:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_نقاب;
            توڑو;
	حالت 'e':
        حالت 'i':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                جاؤ try_اگلا;
            توڑو;
        حالت 'I':
        حالت 'N':
        حالت 'M':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                جاؤ try_اگلا;
            توڑو;
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
                    برائے(reg = 0; reg < NB_ASM_REGS; reg++) {
                        اگر (!(regs_allocated[reg] & REG_اندر_نقاب))
                            جاؤ reg_found1;
                    }
                    جاؤ try_اگلا;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_اندر_نقاب;
                    op->reg = reg;
                    op->is_حافظہ = 1;
                }
            }
            توڑو;
        طےشدہ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            توڑو;
        }
        /* if a reference is present for that operand, we assign it too */
        اگر (op->داخلہ_اشاریہ >= 0) {
            operands[op->داخلہ_اشاریہ].reg = op->reg;
            operands[op->داخلہ_اشاریہ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    برائے(i=0;i<nb_operands;i++) {
        op = &operands[i];
        اگر (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_حافظہ) {
            برائے(reg = 0; reg < NB_ASM_REGS; reg++) {
                اگر (!(regs_allocated[reg] & REG_برآمد_نقاب))
                    جاؤ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            توڑو;
        }
    }

    /* print sorted constraints */
#اگر_تعریف_شدہ ASM_DEBUG
    برائے(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        لکھو("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, تہی) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    اگر (*pout_reg >= 0)
        لکھو("out_reg=%d\n", *pout_reg);
#اگر_ختم
}

ST_FUNC خالی subst_asm_عملیہ(CString *جوڑو_str,
                              SValue *sv, صحیح modifier)
{
    صحیح r, reg, سائز, val;

    r = sv->r;
    اگر ((r & VT_VALMASK) == VT_CONST) {
        اگر (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(جوڑو_str, '$');
        اگر (r & VT_SYM) {
	    ثابت حرف *name = get_tok_str(sv->sym->v, تہی);
	    اگر (sv->sym->v >= SYM_پہلا_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            اگر (tcc_state->leading_underscore)
              cstr_ccat(جوڑو_str, '_');
            cstr_cat(جوڑو_str, name, -1);
            اگر ((uint32_t)sv->c.i == 0)
                جاؤ no_انحراف;
	    cstr_ccat(جوڑو_str, '+');
        }
        val = sv->c.i;
        اگر (modifier == 'n')
            val = -val;
        cstr_printf(جوڑو_str, "%d", val);
    no_انحراف:;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
        اگر (r & VT_LVAL)
            cstr_cat(جوڑو_str, "(%rip)", -1);
#اگر_ختم
    } ورنہ اگر ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(جوڑو_str, "%d(%%%s)", (صحیح)sv->c.i, get_tok_str(TOK_ASM_xax + 5, تہی));
    } ورنہ اگر (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_اندرونی_error("");
        cstr_printf(جوڑو_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, تہی));
    } ورنہ {
        /* register case */
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_اندرونی_error("");

        /* choose register operand size */
        اگر ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            سائز = 1;
        ورنہ اگر ((sv->type.t & VT_BTYPE) == VT_SHORT)
            سائز = 2;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
        ورنہ اگر ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            سائز = 8;
#اگر_ختم
        ورنہ
            سائز = 4;
        اگر (سائز == 1 && reg >= 4)
            سائز = 4;

        اگر (modifier == 'b') {
            اگر (reg >= 4)
                tcc_error("cannot use byte register");
            سائز = 1;
        } ورنہ اگر (modifier == 'h') {
            اگر (reg >= 4)
                tcc_error("cannot use byte register");
            سائز = -1;
        } ورنہ اگر (modifier == 'w') {
            سائز = 2;
        } ورنہ اگر (modifier == 'k') {
            سائز = 4;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
        } ورنہ اگر (modifier == 'q') {
            سائز = 8;
#اگر_ختم
        }

        اگر (reg >= 8) {
            cstr_printf(جوڑو_str, "%%r%d%c", reg, (سائز == 1) ? 'b' : ((سائز == 2) ? 'w' : ((سائز == 4) ? 'd' : ' ')));
            واپس;
        }
        انتخاب(سائز) {
        حالت -1:
            reg = TOK_ASM_ah + reg;
            توڑو;
        حالت 1:
            reg = TOK_ASM_al + reg;
            توڑو;
        حالت 2:
            reg = TOK_ASM_ax + reg;
            توڑو;
        طےشدہ:
            reg = TOK_ASM_eax + reg;
            توڑو;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
        حالت 8:
            reg = TOK_ASM_rax + reg;
            توڑو;
#اگر_ختم
        }
        cstr_printf(جوڑو_str, "%%%s", get_tok_str(reg, تہی));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC خالی asm_gen_رمز(ASMOperand *operands, صحیح nb_operands,
                         صحیح nb_outputs, صحیح is_output,
                         uint8_t *clobber_regs,
                         صحیح برآمد_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    صحیح i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#اگر_تعریف_شدہ TCC_ہدف_X86_64
#اگر_تعریف_شدہ TCC_ہدف_PE
    ساکن ثابت uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#ورنہ
    ساکن ثابت uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#اگر_ختم
#ورنہ
    ساکن ثابت uint8_t reg_saved[] = { 3, 6, 7 };
#اگر_ختم

    /* mark all used registers */
    حافظہ_نقل(regs_allocated, clobber_regs, حجم(regs_allocated));
    برائے(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        اگر (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    اگر (!is_output) {
        /* generate reg save code */
        برائے(i = 0; i < حجم(reg_saved)/حجم(reg_saved[0]); i++) {
            reg = reg_saved[i];
            اگر (regs_allocated[reg]) {
		اگر (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        برائے(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_حافظہ) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    بھرو(op->reg, &sv);
                } ورنہ اگر (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    بھرو(op->reg, op->vt);
                    اگر (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        بھرو(TREG_XDX, &sv);
                    }
                }
            }
        }
    } ورنہ {
        /* generate save code */
        برائے(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    اگر (!op->is_حافظہ) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        بھرو(برآمد_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | برآمد_reg;
                        store(op->reg, &sv);
                    }
                } ورنہ {
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
        برائے(i = حجم(reg_saved)/حجم(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            اگر (regs_allocated[reg]) {
		اگر (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC خالی asm_clobber(uint8_t *clobber_regs, ثابت حرف *str)
{
    صحیح reg;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    غیرعلامتی صحیح type;
#اگر_ختم

    اگر (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        واپس;
    reg = tok_alloc_const(str);
    اگر (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } ورنہ اگر (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    } ورنہ اگر (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } ورنہ اگر ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#اگر_ختم
    } ورنہ {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
