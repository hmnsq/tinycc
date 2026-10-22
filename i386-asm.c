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
#ಅನ್ತರ್ಭಾವ "tcc.h"

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
#ಅನ್ಯಥಾ
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#endif

#define OPC_GROUP_SHIFT 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
ಗಣನಾ {
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
    OPT_REG8_ಕೆಳಗಿನ, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
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
# define OP_REG8_ಕೆಳಗಿನ (1 << OPT_REG8_ಕೆಳಗಿನ)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#ಅನ್ಯಥಾ
# define OP_REG64 0
# define OP_REG8_ಕೆಳಗಿನ 0
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
#ಅನ್ಯಥಾ
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#endif

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ Operand {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t shift;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
} Operand;

ಸ್ಥಿರ ಧ್ರುವ uint8_t reg_to_size[9] = {
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

ಸ್ಥಿರ ಧ್ರುವ uint8_t test_bits[NB_TEST_OPCODES] = {
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

ಸ್ಥಿರ ಧ್ರುವ uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

ಸ್ಥಿರ ಧ್ರುವ ASMInstr asm_instrs[] = {
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
#ಅನ್ಯಥಾ
# include "i386-asm.h"
#endif
    /* last operation */
    { 0, },
};

ಸ್ಥಿರ ಧ್ರುವ uint16_t op0_codes[] = {
#define ALT(x)
#define DEF_ASM_OP0(x, opcode) opcode,
#define DEF_ASM_OP0L(name, opcode, group, instr_type)
#define DEF_ASM_OP1(name, opcode, group, instr_type, op0)
#define DEF_ASM_OP2(name, opcode, group, instr_type, op0, op1)
#define DEF_ASM_OP3(name, opcode, group, instr_type, op0, op1, op2)
#ifdef TCC_TARGET_X86_64
# include "x86_64-asm.h"
#ಅನ್ಯಥಾ
# include "i386-asm.h"
#endif
};

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ get_reg_shift(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ shift, v;
    v = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
    ವಿಕಲ್ಪ(v) {
    ಪಕ್ಷ 1:
        shift = 0;
        ಭಙ್ಗ;
    ಪಕ್ಷ 2:
        shift = 1;
        ಭಙ್ಗ;
    ಪಕ್ಷ 4:
        shift = 2;
        ಭಙ್ಗ;
    ಪಕ್ಷ 8:
        shift = 3;
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        expect("1, 2, 4 or 8 constant");
        shift = 0;
        ಭಙ್ಗ;
    }
    ಪ್ರತ್ಯಾಗಮ shift;
}

#ifdef TCC_TARGET_X86_64
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asm_parse_numeric_reg(ಪೂರ್ಣಾಙ್ಕ t, unsigned ಪೂರ್ಣಾಙ್ಕ *type)
{
    ಪೂರ್ಣಾಙ್ಕ reg = -1;
    ಯದಿ (t >= TOK_IDENT && t < tok_ident) {
	ಧ್ರುವ ವರ್ಣ *s = table_ident[t - TOK_IDENT]->str;
	ವರ್ಣ c;
	*type = OP_REG64;
	ಯದಿ (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	ಯದಿ (*s++ != 'r')
	  ಪ್ರತ್ಯಾಗಮ -1;
	/* Don't allow leading '0'.  */
	ಯದಿ ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	ಅನ್ಯಥಾ
	  ಪ್ರತ್ಯಾಗಮ -1;
	ಯದಿ ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	ಯದಿ (reg > 15)
	  ಪ್ರತ್ಯಾಗಮ -1;
	ಯದಿ ((c = *s) == 0)
	  ;
	ಅನ್ಯಥಾ ಯದಿ (*type != OP_REG64)
	  ಪ್ರತ್ಯಾಗಮ -1;
	ಅನ್ಯಥಾ ಯದಿ (c == 'b' && !s[1])
	  *type = OP_REG8;
	ಅನ್ಯಥಾ ಯದಿ (c == 'w' && !s[1])
	  *type = OP_REG16;
	ಅನ್ಯಥಾ ಯದಿ (c == 'd' && !s[1])
	  *type = OP_REG32;
	ಅನ್ಯಥಾ
	  ಪ್ರತ್ಯಾಗಮ -1;
    }
    ಪ್ರತ್ಯಾಗಮ reg;
}
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asm_parse_reg(unsigned ಪೂರ್ಣಾಙ್ಕ *type)
{
    ಪೂರ್ಣಾಙ್ಕ reg = 0;
    *type = 0;
    ಯದಿ (tok != '%')
        ಗಚ್ಛ error_32;
    next();
    ಯದಿ (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#ifdef TCC_TARGET_X86_64
    } ಅನ್ಯಥಾ ಯದಿ (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } ಅನ್ಯಥಾ ಯದಿ (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } ಅನ್ಯಥಾ ಯದಿ ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#endif
    } ಅನ್ಯಥಾ {
    error_32:
        expect("register");
    }
    next();
    ಪ್ರತ್ಯಾಗಮ reg;
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_operand(TCCState *s1, Operand *op)
{
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    ಪೂರ್ಣಾಙ್ಕ reg, indir;
    ಧ್ರುವ ವರ್ಣ *p;

    indir = 0;
    ಯದಿ (tok == '*') {
        next();
        indir = OP_INDIR;
    }

    ಯದಿ (tok == '%') {
        next();
        ಯದಿ (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            ಯದಿ ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            ಅನ್ಯಥಾ ಯದಿ (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            ಅನ್ಯಥಾ ಯದಿ (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } ಅನ್ಯಥಾ ಯದಿ (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } ಅನ್ಯಥಾ ಯದಿ (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } ಅನ್ಯಥಾ ಯದಿ (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            next();
            ಯದಿ (tok == '(') {
                next();
                ಯದಿ (tok != TOK_PPNUM)
                    ಗಚ್ಛ reg_error;
                p = tokc.str.data;
                reg = p[0] - '0';
                ಯದಿ ((unsigned)reg >= 8 || p[1] != '\0')
                    ಗಚ್ಛ reg_error;
                op->reg = reg;
                next();
                skip(')');
            }
            ಯದಿ (op->reg == 0)
                op->type |= OP_ST0;
            ಗಚ್ಛ no_skip;
#ifdef TCC_TARGET_X86_64
	} ಅನ್ಯಥಾ ಯದಿ (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_ಕೆಳಗಿನ;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } ಅನ್ಯಥಾ ಯದಿ ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#endif
        } ಅನ್ಯಥಾ {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        next();
    no_skip: ;
    } ಅನ್ಯಥಾ ಯದಿ (tok == '$') {
        /* constant value */
        next();
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        ಯದಿ (!op->e.sym) {
            ಯದಿ (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            ಯದಿ (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            ಯದಿ (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#ifdef TCC_TARGET_X86_64
            ಯದಿ (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#endif
        }
    } ಅನ್ಯಥಾ {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->shift = 0;
        ಯದಿ (tok != '(') {
            asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
            op->e = e;
        } ಅನ್ಯಥಾ {
            next();
            ಯದಿ (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = ರಿಕ್ತ;
            } ಅನ್ಯಥಾ {
                /* bracketed offset expression */
                asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
                ಯದಿ (tok != ')')
                    expect(")");
                next();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        ಯದಿ (tok == '(') {
	    unsigned ಪೂರ್ಣಾಙ್ಕ type = 0;
            next();
            ಯದಿ (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            ಯದಿ (tok == ',') {
                next();
                ಯದಿ (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                ಯದಿ (tok == ',') {
                    next();
                    op->shift = get_reg_shift(s1);
                }
            }
	    ಯದಿ (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        ಯದಿ (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    ಯದಿ (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    ಅನ್ಯಥಾ
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
ಸ್ಥಿರ ಶೂನ್ಯ gen_disp32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    ಯದಿ (esym && esym->st_shndx == cur_text_section->sh_ಅಂಕೆ) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_ಮೌಲ್ಯ - ind - 4);
    } ಅನ್ಯಥಾ {
        ಯದಿ (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = ರಿಕ್ತ;
        }
#ifdef TCC_TARGET_X86_64
        greloca(cur_text_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#ಅನ್ಯಥಾ
        gen_addrpc32(VT_SYM, sym, pe->v);
#endif

    }
}

/* generate the modrm operand */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ asm_modrm(ಪೂರ್ಣಾಙ್ಕ reg, Operand *op)
{
    ಪೂರ್ಣಾಙ್ಕ mod, reg1, reg2, sib_reg1;

    ಯದಿ (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } ಅನ್ಯಥಾ ಯದಿ (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#ifdef TCC_TARGET_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#ಅನ್ಯಥಾ
	g(0x05 + (reg << 3));
#endif
	gen_expr32(&op->e);
#ifdef TCC_TARGET_X86_64
    } ಅನ್ಯಥಾ ಯದಿ (op->reg == -2) {
        ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        ಪ್ರತ್ಯಾಗಮ ind;
#endif
    } ಅನ್ಯಥಾ {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        ಯದಿ (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } ಅನ್ಯಥಾ ಯದಿ (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } ಅನ್ಯಥಾ ಯದಿ (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } ಅನ್ಯಥಾ {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        ಯದಿ (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        ಯದಿ (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            ಯದಿ (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->shift << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        ಯದಿ (mod == 0x40) {
            g(op->e.v);
        } ಅನ್ಯಥಾ ಯದಿ (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ifdef TCC_TARGET_X86_64
#define REX_W 0x48
#define REX_R 0x44
#define REX_X 0x42
#define REX_B 0x41

ಸ್ಥಿರ ಶೂನ್ಯ asm_rex(ಪೂರ್ಣಾಙ್ಕ width64, Operand *ops, ಪೂರ್ಣಾಙ್ಕ nb_ops, ಪೂರ್ಣಾಙ್ಕ *op_type,
		    ಪೂರ್ಣಾಙ್ಕ regi, ಪೂರ್ಣಾಙ್ಕ rmi)
{
  unsigned ವರ್ಣ rex = width64 ? 0x48 : 0;
  ಪೂರ್ಣಾಙ್ಕ saw_ಮೇಲಿನ_8bit = 0;
  ಪೂರ್ಣಾಙ್ಕ i;
  ಯದಿ (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      ಪ್ರತಿ(i = 0; i < nb_ops; i++) {
	  ಯದಿ (op_type[i] & (OP_REG | OP_ST)) {
	      ಯದಿ (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } ಅನ್ಯಥಾ ಯದಿ (ops[i].type & OP_REG8_ಕೆಳಗಿನ)
		  rex |= 0x40;
	      ಅನ್ಯಥಾ ಯದಿ (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_ಮೇಲಿನ_8bit = ops[i].reg;
	      ಭಙ್ಗ;
	  }
      }
  } ಅನ್ಯಥಾ {
      ಯದಿ (regi != -1) {
	  ಯದಿ (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } ಅನ್ಯಥಾ ಯದಿ (ops[regi].type & OP_REG8_ಕೆಳಗಿನ)
	      rex |= 0x40;
	  ಅನ್ಯಥಾ ಯದಿ (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_ಮೇಲಿನ_8bit = ops[regi].reg;
      }
      ಯದಿ (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  ಯದಿ (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } ಅನ್ಯಥಾ ಯದಿ (ops[rmi].type & OP_REG8_ಕೆಳಗಿನ)
	      rex |= 0x40;
	  ಅನ್ಯಥಾ ಯದಿ (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_ಮೇಲಿನ_8bit = ops[rmi].reg;
      }
      ಯದಿ (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  ಯದಿ (rex) {
      ಯದಿ (saw_ಮೇಲಿನ_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_ಮೇಲಿನ_8bit-4]);
      g(rex);
  }
}
#endif


ಸ್ಥಿರ ಶೂನ್ಯ maybe_print_stats (ಶೂನ್ಯ)
{
    ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ already;

    ಯದಿ (0 && !already)
    /* print stats about opcodes */
    {
        ಧ್ರುವ ಸಂರಚನಾ ASMInstr *pa;
        ಪೂರ್ಣಾಙ್ಕ freq[4];
        ಪೂರ್ಣಾಙ್ಕ op_vals[500];
        ಪೂರ್ಣಾಙ್ಕ nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, ಪರಿಮಾಣ(freq));
        ಪ್ರತಿ(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                ಪ್ರತಿ(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    ಯದಿ (pa->instr_type == op_vals[j])
                        ಗಚ್ಛ found;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            found: ;
            //}
        }
        ಪ್ರತಿ(i=0;i<nb_op_vals;i++) {
            ಪೂರ್ಣಾಙ್ಕ v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                printf("%3d: %08x\n", i, v);
        }
        printf("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (ಪೂರ್ಣಾಙ್ಕ)ಪರಿಮಾಣ(asm_instrs),
	       (ಪೂರ್ಣಾಙ್ಕ)ಪರಿಮಾಣ(asm_instrs) / (ಪೂರ್ಣಾಙ್ಕ)ಪರಿಮಾಣ(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ opcode)
{
    ಧ್ರುವ ASMInstr *pa;
    ಪೂರ್ಣಾಙ್ಕ i, modrm_index, modreg_index, reg, v, op1, seg_prefix, pc, p;
    ಪೂರ್ಣಾಙ್ಕ nb_ops, s;
    Operand ops[MAX_OPERANDS], *ತೆಗೆ;
    ಪೂರ್ಣಾಙ್ಕ op_type[3]; /* decoded op type */
    ಪೂರ್ಣಾಙ್ಕ alltypes;   /* OR of all operand types */
    ಪೂರ್ಣಾಙ್ಕ autosize;
    ಪೂರ್ಣಾಙ್ಕ p66;
#ifdef TCC_TARGET_X86_64
    ಪೂರ್ಣಾಙ್ಕ rex64;
#endif

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    ಯದಿ (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    ತೆಗೆ = ops;
    nb_ops = 0;
    seg_prefix = 0;
    alltypes = 0;
    ಪ್ರತಿ(;;) {
        ಯದಿ (tok == ';' || tok == TOK_LINEFEED)
            ಭಙ್ಗ;
        ಯದಿ (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_operand(s1, ತೆಗೆ);
        ಯದಿ (tok == ':') {
           ಯದಿ (!(ತೆಗೆ->type & OP_SEG) || seg_prefix)
               tcc_error("incorrect prefix");
           seg_prefix = segment_prefixes[ತೆಗೆ->reg];
           next();
           parse_operand(s1, ತೆಗೆ);
           ಯದಿ (!(ತೆಗೆ->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        ತೆಗೆ++;
        nb_ops++;
        ಯದಿ (tok != ',')
            ಭಙ್ಗ;
        next();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    ಪ್ರತಿ(pa = asm_instrs; pa->sym != 0; pa++) {
	ಪೂರ್ಣಾಙ್ಕ it = pa->instr_type & OPCT_MASK;
        s = 0;
        ಯದಿ (it == OPC_FARITH) {
            v = opcode - pa->sym;
            ಯದಿ (!((unsigned)v < 8 * 6 && (v % 6) == 0))
                ಅನುವರ್ತ;
        } ಅನ್ಯಥಾ ಯದಿ (it == OPC_ARITH) {
            ಯದಿ (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                ಅನುವರ್ತ;
            s = (opcode - pa->sym) % NBWLX;
	    ಯದಿ ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		ಯದಿ (((opcode - pa->sym + 1) % NBWLX) == 0)
		    ಅನುವರ್ತ;
	        s++;
	      }
        } ಅನ್ಯಥಾ ಯದಿ (it == OPC_SHIFT) {
            ಯದಿ (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                ಅನುವರ್ತ;
            s = (opcode - pa->sym) % NBWLX;
        } ಅನ್ಯಥಾ ಯದಿ (it == OPC_TEST) {
            ಯದಿ (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                ಅನುವರ್ತ;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    ಯದಿ (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } ಅನ್ಯಥಾ ಯದಿ (pa->instr_type & OPC_B) {
#ifdef TCC_TARGET_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    ಯದಿ ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        ಅನುವರ್ತ;
#endif
            ಯದಿ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                ಅನುವರ್ತ;
            s = opcode - pa->sym;
        } ಅನ್ಯಥಾ ಯದಿ (pa->instr_type & OPC_WLX) {
            ಯದಿ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                ಅನುವರ್ತ;
            s = opcode - pa->sym + 1;
        } ಅನ್ಯಥಾ {
            ಯದಿ (pa->sym != opcode)
                ಅನುವರ್ತ;
        }
        ಯದಿ (pa->nb_ops != nb_ops)
            ಅನುವರ್ತ;
#ifdef TCC_TARGET_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	ಯದಿ (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    ಅನುವರ್ತ;
#endif
        /* now decode and check each operand */
	alltypes = 0;
        ಪ್ರತಿ(i = 0; i < nb_ops; i++) {
            ಪೂರ್ಣಾಙ್ಕ op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            ವಿಕಲ್ಪ(op2) {
            ಪಕ್ಷ OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                ಭಙ್ಗ;
            ಪಕ್ಷ OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                ಭಙ್ಗ;
            ಪಕ್ಷ OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                ಭಙ್ಗ;
            ಪಕ್ಷ OPT_IMW:
                v = OP_IM16 | OP_IM32;
                ಭಙ್ಗ;
	    ಪಕ್ಷ OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		ಭಙ್ಗ;
	    ಪಕ್ಷ OPT_DISP:
	    ಪಕ್ಷ OPT_DISP8:
		v = OP_ADDR;
		ಭಙ್ಗ;
            ಸ್ವಭಾವ:
                v = 1 << op2;
                ಭಙ್ಗ;
            }
            ಯದಿ (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            ಯದಿ ((ops[i].type & v) == 0)
                ಗಚ್ಛ next;
	    alltypes |= ops[i].type;
        }
        (ಶೂನ್ಯ)alltypes; /* maybe unused */
        /* all is matching ! */
        ಭಙ್ಗ;
    next: ;
    }
    ಯದಿ (pa->sym == 0) {
        ಯದಿ (opcode >= TOK_ASM_first && opcode <= TOK_ASM_last) {
            ಪೂರ್ಣಾಙ್ಕ b;
            b = op0_codes[opcode - TOK_ASM_first];
            ಯದಿ (b & 0xff00)
                g(b >> 8);
            g(b);
            ಪ್ರತ್ಯಾಗಮ;
        } ಅನ್ಯಥಾ ಯದಿ (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, ರಿಕ್ತ));
        } ಅನ್ಯಥಾ {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = table_ident[opcode - TOK_IDENT];
	    ಯದಿ (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		ಗಚ್ಛ again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#ifdef TCC_TARGET_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    ಯದಿ ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#endif
    ಯದಿ (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        ಪ್ರತಿ(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            ಯದಿ ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_to_size[ops[i].type & OP_REG];
        }
        ಯದಿ (s == autosize) {
            ಯದಿ ((opcode == TOK_ASM_ತಳ್ಳು || opcode == TOK_ASM_ತೆಗೆ) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    ಅನ್ಯಥಾ ಯದಿ ((opcode == TOK_ASM_ತಳ್ಳು || opcode == TOK_ASM_ತೆಗೆ) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            ಅನ್ಯಥಾ
                tcc_error("cannot infer opcode suffix");
        }
    }

#ifdef TCC_TARGET_X86_64
    rex64 = 0;
    ಯದಿ (pa->instr_type & OPC_48)
        rex64 = 1;
    ಅನ್ಯಥಾ ಯದಿ (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	ಪೂರ್ಣಾಙ್ಕ default64 = 0;
	ಪ್ರತಿ(i = 0; i < nb_ops; i++) {
	    ಯದಿ (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		ಭಙ್ಗ;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        ಯದಿ (((opcode != TOK_ASM_ತಳ್ಳು && opcode != TOK_ASM_ತೆಗೆ
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#endif

    /* now generates the operation */
    ಯದಿ (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    ಯದಿ (seg_prefix)
        g(seg_prefix);
#ifdef TCC_TARGET_X86_64
    /* Generate addr32 prefix if needed */
    ಪ್ರತಿ(i = 0; i < nb_ops; i++) {
        ಯದಿ (ops[i].type & OP_EA32) {
	    g(0x67);
	    ಭಙ್ಗ;
        }
    }
#endif
    /* generate data16 prefix if needed */
    p66 = 0;
    ಯದಿ (s == 1)
        p66 = 1;
    ಅನ್ಯಥಾ {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        ಪ್ರತಿ (i = 0; i < nb_ops; i++)
            ಯದಿ ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    ಯದಿ (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    ವಿಕಲ್ಪ (p) {
        ಪಕ್ಷ 0: ಭಙ್ಗ;  /* no prefix */
        ಪಕ್ಷ 0x48: ಭಙ್ಗ; /* REX, handled elsewhere */
        ಪಕ್ಷ 0x66:
        ಪಕ್ಷ 0x67:
        ಪಕ್ಷ 0xf2:
        ಪಕ್ಷ 0xf3: v = v & 0xff; g(p); ಭಙ್ಗ;
        ಪಕ್ಷ 0xd4: ಪಕ್ಷ 0xd5: ಭಙ್ಗ; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        ಪಕ್ಷ 0xd8: ಪಕ್ಷ 0xd9: ಪಕ್ಷ 0xda: ಪಕ್ಷ 0xdb: /* x87, no normal prefix */
        ಪಕ್ಷ 0xdc: ಪಕ್ಷ 0xdd: ಪಕ್ಷ 0xde: ಪಕ್ಷ 0xdf: ಭಙ್ಗ;
        ಸ್ವಭಾವ: tcc_error("bad prefix 0x%2x in opcode table", p); ಭಙ್ಗ;
    }
    ಯದಿ (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    ಯದಿ ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } ಅನ್ಯಥಾ ಯದಿ (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } ಅನ್ಯಥಾ ಯದಿ ((v == 0x06 || v == 0x07)) {
        ಯದಿ (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } ಅನ್ಯಥಾ {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } ಅನ್ಯಥಾ ಯದಿ (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } ಅನ್ಯಥಾ ಯದಿ ((pa->instr_type & (OPCT_MASK | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_index = -1;
    modreg_index = -1;
    ಯದಿ (pa->instr_type & OPC_MODRM) {
	ಯದಿ (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#ifdef TCC_TARGET_X86_64
	    ಯದಿ (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    ಅನ್ಯಥಾ ಯದಿ (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#ಅನ್ಯಥಾ
	    ಯದಿ (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#endif
	    ಅನ್ಯಥಾ
	      tcc_error("bad MODR/M opcode without operands");
	    ಗಚ್ಛ modrm_found;
	}
        /* first look for an ea operand */
        ಪ್ರತಿ(i = 0;i < nb_ops; i++) {
            ಯದಿ (op_type[i] & OP_EA)
                ಗಚ್ಛ modrm_found;
        }
        /* then if not found, a register or indirection (shift instructions) */
        ಪ್ರತಿ(i = 0;i < nb_ops; i++) {
            ಯದಿ (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                ಗಚ್ಛ modrm_found;
        }
#ifdef ASM_DEBUG
        tcc_error("bad op table");
#endif
    modrm_found:
        modrm_index = i;
        /* if a register is used in another operand then it is
           used instead of group */
        ಪ್ರತಿ(i = 0;i < nb_ops; i++) {
            ಪೂರ್ಣಾಙ್ಕ t = op_type[i];
            ಯದಿ (i != modrm_index &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_index = i;
                ಭಙ್ಗ;
            }
        }
    }
#ifdef TCC_TARGET_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_index, modrm_index);
#endif

    ಯದಿ (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        ಯದಿ (v == 0xb0 && s >= 1)
            v += 7;
        ಪ್ರತಿ(i = 0; i < nb_ops; i++) {
            ಯದಿ (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                ಭಙ್ಗ;
            }
        }
    }
    ಯದಿ (pa->instr_type & OPC_B)
        v += s >= 1;
    ಯದಿ (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        ಪೂರ್ಣಾಙ್ಕ jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        ಯದಿ (!esym || esym->st_shndx != cur_text_section->sh_ಅಂಕೆ)
            ಗಚ್ಛ no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_ಮೌಲ್ಯ - ind - 2 - (v >= 0xff);
        ಯದಿ (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } ಅನ್ಯಥಾ {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    ಯದಿ (v == 0xeb) /* jmp */
	        v = 0xe9;
	    ಅನ್ಯಥಾ ಯದಿ (v == 0x70) /* jcc */
	        v += 0x0f10;
	    ಅನ್ಯಥಾ
	        tcc_error("invalid displacement");
        }
    }
    ಯದಿ (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_bits[opcode - pa->sym];
    ಅನ್ಯಥಾ ಯದಿ (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    ಯದಿ (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    ಯದಿ (op1)
        g(op1);
    g(v);

    ಯದಿ (OPCT_IS(pa->instr_type, OPC_SHIFT)) {
        reg = (opcode - pa->sym) / NBWLX;
        ಯದಿ (reg == 6)
            reg = 7;
    } ಅನ್ಯಥಾ ಯದಿ (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } ಅನ್ಯಥಾ ಯದಿ (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } ಅನ್ಯಥಾ {
        reg = (pa->instr_type >> OPC_GROUP_SHIFT) & 7;
    }

    pc = 0;
    ಯದಿ (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	ಯದಿ (modreg_index >= 0)
	    reg = ops[modreg_index].reg;
        pc = asm_modrm(reg, &ops[modrm_index]);
    }

    /* emit constants */
#ifndef TCC_TARGET_X86_64
    ಯದಿ (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        ಯದಿ (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        ಪ್ರತ್ಯಾಗಮ;
    }
#endif
    ಪ್ರತಿ(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        ಯದಿ (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            ಯದಿ ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                ಯದಿ (s == 0)
                    v = OP_IM8;
                ಅನ್ಯಥಾ ಯದಿ (s == 1)
                    v = OP_IM16;
                ಅನ್ಯಥಾ ಯದಿ (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                ಅನ್ಯಥಾ
                    v = OP_IM64;
            }

            ಯದಿ ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            ಯದಿ (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } ಅನ್ಯಥಾ ಯದಿ (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#ifdef TCC_TARGET_X86_64
            } ಅನ್ಯಥಾ ಯದಿ (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#endif
	    } ಅನ್ಯಥಾ ಯದಿ (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } ಅನ್ಯಥಾ {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    ಯದಿ (pc)
        add32le(cur_text_section->data + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ constraint_priority(ಧ್ರುವ ವರ್ಣ *str)
{
    ಪೂರ್ಣಾಙ್ಕ priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    ಪ್ರತಿ(;;) {
        c = *str;
        ಯದಿ (c == '\0')
            ಭಙ್ಗ;
        str++;
        ವಿಕಲ್ಪ(c) {
        ಪಕ್ಷ 'A':
            pr = 0;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'a':
        ಪಕ್ಷ 'b':
        ಪಕ್ಷ 'c':
        ಪಕ್ಷ 'd':
        ಪಕ್ಷ 'S':
        ಪಕ್ಷ 'D':
            pr = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'q':
            pr = 2;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'r':
	ಪಕ್ಷ 'R':
	ಪಕ್ಷ 'p':
            pr = 3;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'N':
        ಪಕ್ಷ 'M':
        ಪಕ್ಷ 'I':
	ಪಕ್ಷ 'e':
        ಪಕ್ಷ 'i':
        ಪಕ್ಷ 'm':
        ಪಕ್ಷ 'g':
            pr = 4;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        ಯದಿ (pr > priority)
            priority = pr;
    }
    ಪ್ರತ್ಯಾಗಮ priority;
}

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ *skip_constraint_modifiers(ಧ್ರುವ ವರ್ಣ *p)
{
    ಯಾವತ್ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ಪ್ರತ್ಯಾಗಮ p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ asm_parse_regvar (ಪೂರ್ಣಾಙ್ಕ t)
{
    ಧ್ರುವ ವರ್ಣ *s;
    Operand op;
    ಯದಿ (t < TOK_IDENT || (t & SYM_FIELD))
        ಪ್ರತ್ಯಾಗಮ -1;
    s = table_ident[t - TOK_IDENT]->str;
    ಯದಿ (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_operand(tcc_state, &op);
    /* Accept only integer regs for now. */
    ಯದಿ (op.type & OP_REG)
        ಪ್ರತ್ಯಾಗಮ op.reg;
    ಅನ್ಯಥಾ
        ಪ್ರತ್ಯಾಗಮ -1;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands,
                                    ಪೂರ್ಣಾಙ್ಕ nb_operands, ಪೂರ್ಣಾಙ್ಕ nb_outputs,
                                    ಧ್ರುವ uint8_t *clobber_regs,
                                    ಪೂರ್ಣಾಙ್ಕ *pout_reg)
{
    ASMOperand *op;
    ಪೂರ್ಣಾಙ್ಕ sorted_op[MAX_ASM_OPERANDS];
    ಪೂರ್ಣಾಙ್ಕ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ಧ್ರುವ ವರ್ಣ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ಪ್ರತಿ(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->ಒಳಹರಿವು_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ಪ್ರತಿ(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ಯದಿ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, ರಿಕ್ತ);
            ಯದಿ ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_index = k;
            ಯದಿ (operands[k].ಒಳಹರಿವು_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ಒಳಹರಿವು_index = i;
            op->priority = 5;
	} ಅನ್ಯಥಾ ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->priority = 1;
	    op->reg = reg;
        } ಅನ್ಯಥಾ {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    ಪ್ರತಿ(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    ಪ್ರತಿ(i=0;i<nb_operands - 1;i++) {
        ಪ್ರತಿ(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            ಯದಿ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ಪ್ರತಿ(i = 0;i < NB_ASM_REGS; i++) {
        ಯದಿ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        ಅನ್ಯಥಾ
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_IN_MASK | REG_OUT_MASK;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    ಪ್ರತಿ(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ಯದಿ (op->ref_index >= 0)
            ಅನುವರ್ತ;
        /* select if register is used for output, input or both */
        ಯದಿ (op->ಒಳಹರಿವು_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } ಅನ್ಯಥಾ ಯದಿ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } ಅನ್ಯಥಾ {
            reg_mask = REG_IN_MASK;
        }
	ಯದಿ (op->reg >= 0) {
	    ಯದಿ (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_next:
        c = *str++;
        ವಿಕಲ್ಪ(c) {
        ಪಕ್ಷ '=':
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ '+':
            op->is_rw = 1;
            /* FALL THRU */
        ಪಕ್ಷ '&':
            ಯದಿ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ 'A':
            /* allocate both eax and edx */
            ಯದಿ (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                ಗಚ್ಛ try_next;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_mask;
            regs_allocated[TREG_XDX] |= reg_mask;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'a':
            reg = TREG_XAX;
            ಗಚ್ಛ alloc_reg;
        ಪಕ್ಷ 'b':
            reg = 3;
            ಗಚ್ಛ alloc_reg;
        ಪಕ್ಷ 'c':
            reg = TREG_XCX;
            ಗಚ್ಛ alloc_reg;
        ಪಕ್ಷ 'd':
            reg = TREG_XDX;
            ಗಚ್ಛ alloc_reg;
        ಪಕ್ಷ 'S':
            reg = 6;
            ಗಚ್ಛ alloc_reg;
        ಪಕ್ಷ 'D':
            reg = 7;
        alloc_reg:
            ಯದಿ (op->reg >= 0 && reg != op->reg)
                ಗಚ್ಛ try_next;
            ಯದಿ (is_reg_allocated(reg))
                ಗಚ್ಛ try_next;
            ಗಚ್ಛ reg_found;
        ಪಕ್ಷ 'q':
            /* eax, ebx, ecx or edx */
            ಯದಿ (op->reg >= 0) {
                ಯದಿ ((reg = op->reg) < 4)
                    ಗಚ್ಛ reg_found;
            } ಅನ್ಯಥಾ ಪ್ರತಿ(reg = 0; reg < 4; reg++) {
                ಯದಿ (!is_reg_allocated(reg))
                    ಗಚ್ಛ reg_found;
            }
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ 'r':
	ಪಕ್ಷ 'R':
	ಪಕ್ಷ 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            ಯದಿ ((reg = op->reg) >= 0)
                ಗಚ್ಛ reg_found;
            ಅನ್ಯಥಾ ಪ್ರತಿ(reg = 0; reg < NB_ASM_REGS; reg++) {
                ಯದಿ (!is_reg_allocated(reg))
                    ಗಚ್ಛ reg_found;
            }
            ಗಚ್ಛ try_next;
        reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            ಭಙ್ಗ;
	ಪಕ್ಷ 'e':
        ಪಕ್ಷ 'i':
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'I':
        ಪಕ್ಷ 'N':
        ಪಕ್ಷ 'M':
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'm':
        ಪಕ್ಷ 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ಯದಿ (j < nb_outputs || c == 'm') {
                ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    ಪ್ರತಿ(reg = 0; reg < NB_ASM_REGS; reg++) {
                        ಯದಿ (!(regs_allocated[reg] & REG_IN_MASK))
                            ಗಚ್ಛ reg_found1;
                    }
                    ಗಚ್ಛ try_next;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            ಭಙ್ಗ;
        }
        /* if a reference is present for that operand, we assign it too */
        ಯದಿ (op->ಒಳಹರಿವು_index >= 0) {
            operands[op->ಒಳಹರಿವು_index].reg = op->reg;
            operands[op->ಒಳಹರಿವು_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ಪ್ರತಿ(i=0;i<nb_operands;i++) {
        op = &operands[i];
        ಯದಿ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_memory) {
            ಪ್ರತಿ(reg = 0; reg < NB_ASM_REGS; reg++) {
                ಯದಿ (!(regs_allocated[reg] & REG_OUT_MASK))
                    ಗಚ್ಛ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            ಭಙ್ಗ;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    ಪ್ರತಿ(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ರಿಕ್ತ) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    ಯದಿ (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC ಶೂನ್ಯ subst_asm_operand(CString *add_str,
                              SValue *sv, ಪೂರ್ಣಾಙ್ಕ modifier)
{
    ಪೂರ್ಣಾಙ್ಕ r, reg, size, val;

    r = sv->r;
    ಯದಿ ((r & VT_VALMASK) == VT_CONST) {
        ಯದಿ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(add_str, '$');
        ಯದಿ (r & VT_SYM) {
	    ಧ್ರುವ ವರ್ಣ *name = get_tok_str(sv->sym->v, ರಿಕ್ತ);
	    ಯದಿ (sv->sym->v >= SYM_FIRST_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            ಯದಿ (tcc_state->leading_underscore)
              cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            ಯದಿ ((uint32_t)sv->c.i == 0)
                ಗಚ್ಛ no_offset;
	    cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        ಯದಿ (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
    no_offset:;
#ifdef TCC_TARGET_X86_64
        ಯದಿ (r & VT_LVAL)
            cstr_cat(add_str, "(%rip)", -1);
#endif
    } ಅನ್ಯಥಾ ಯದಿ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d(%%%s)", (ಪೂರ್ಣಾಙ್ಕ)sv->c.i, get_tok_str(TOK_ASM_xax + 5, ರಿಕ್ತ));
    } ಅನ್ಯಥಾ ಯದಿ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ಯದಿ (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, ರಿಕ್ತ));
    } ಅನ್ಯಥಾ {
        /* register case */
        reg = r & VT_VALMASK;
        ಯದಿ (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        ಯದಿ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        ಅನ್ಯಥಾ ಯದಿ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
#ifdef TCC_TARGET_X86_64
        ಅನ್ಯಥಾ ಯದಿ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
#endif
        ಅನ್ಯಥಾ
            size = 4;
        ಯದಿ (size == 1 && reg >= 4)
            size = 4;

        ಯದಿ (modifier == 'b') {
            ಯದಿ (reg >= 4)
                tcc_error("cannot use byte register");
            size = 1;
        } ಅನ್ಯಥಾ ಯದಿ (modifier == 'h') {
            ಯದಿ (reg >= 4)
                tcc_error("cannot use byte register");
            size = -1;
        } ಅನ್ಯಥಾ ಯದಿ (modifier == 'w') {
            size = 2;
        } ಅನ್ಯಥಾ ಯದಿ (modifier == 'k') {
            size = 4;
#ifdef TCC_TARGET_X86_64
        } ಅನ್ಯಥಾ ಯದಿ (modifier == 'q') {
            size = 8;
#endif
        }

        ಯದಿ (reg >= 8) {
            cstr_printf(add_str, "%%r%d%c", reg, (size == 1) ? 'b' : ((size == 2) ? 'w' : ((size == 4) ? 'd' : ' ')));
            ಪ್ರತ್ಯಾಗಮ;
        }
        ವಿಕಲ್ಪ(size) {
        ಪಕ್ಷ -1:
            reg = TOK_ASM_ah + reg;
            ಭಙ್ಗ;
        ಪಕ್ಷ 1:
            reg = TOK_ASM_al + reg;
            ಭಙ್ಗ;
        ಪಕ್ಷ 2:
            reg = TOK_ASM_ax + reg;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            reg = TOK_ASM_eax + reg;
            ಭಙ್ಗ;
#ifdef TCC_TARGET_X86_64
        ಪಕ್ಷ 8:
            reg = TOK_ASM_rax + reg;
            ಭಙ್ಗ;
#endif
        }
        cstr_printf(add_str, "%%%s", get_tok_str(reg, ರಿಕ್ತ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ಶೂನ್ಯ asm_gen_code(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands,
                         ಪೂರ್ಣಾಙ್ಕ nb_outputs, ಪೂರ್ಣಾಙ್ಕ is_output,
                         uint8_t *clobber_regs,
                         ಪೂರ್ಣಾಙ್ಕ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ಪೂರ್ಣಾಙ್ಕ i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    ಸ್ಥಿರ ಧ್ರುವ uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#ಅನ್ಯಥಾ
    ಸ್ಥಿರ ಧ್ರುವ uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#endif
#ಅನ್ಯಥಾ
    ಸ್ಥಿರ ಧ್ರುವ uint8_t reg_saved[] = { 3, 6, 7 };
#endif

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, ಪರಿಮಾಣ(regs_allocated));
    ಪ್ರತಿ(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        ಯದಿ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    ಯದಿ (!is_output) {
        /* generate reg save code */
        ಪ್ರತಿ(i = 0; i < ಪರಿಮಾಣ(reg_saved)/ಪರಿಮಾಣ(reg_saved[0]); i++) {
            reg = reg_saved[i];
            ಯದಿ (regs_allocated[reg]) {
		ಯದಿ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        ಪ್ರತಿ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ಯದಿ (op->reg >= 0) {
                ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } ಅನ್ಯಥಾ ಯದಿ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    load(op->reg, op->vt);
                    ಯದಿ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        load(TREG_XDX, &sv);
                    }
                }
            }
        }
    } ಅನ್ಯಥಾ {
        /* generate save code */
        ಪ್ರತಿ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ಯದಿ (op->reg >= 0) {
                ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ಯದಿ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        load(out_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } ಅನ್ಯಥಾ {
                    store(op->reg, op->vt);
                    ಯದಿ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        ಪ್ರತಿ(i = ಪರಿಮಾಣ(reg_saved)/ಪರಿಮಾಣ(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            ಯದಿ (regs_allocated[reg]) {
		ಯದಿ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಧ್ರುವ ವರ್ಣ *str)
{
    ಪೂರ್ಣಾಙ್ಕ reg;
#ifdef TCC_TARGET_X86_64
    unsigned ಪೂರ್ಣಾಙ್ಕ type;
#endif

    ಯದಿ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        ಪ್ರತ್ಯಾಗಮ;
    reg = tok_alloc_const(str);
    ಯದಿ (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } ಅನ್ಯಥಾ ಯದಿ (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#ifdef TCC_TARGET_X86_64
    } ಅನ್ಯಥಾ ಯದಿ (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } ಅನ್ಯಥಾ ಯದಿ ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#endif
    } ಅನ್ಯಥಾ {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
