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
#include "tcc.h"

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
#မဟုတ်ပါက
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#endif

#define OPC_GROUP_SHIFT 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
ga_nanaa {
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
    OPT_REG8_LOW, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
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
# define OP_REG8_LOW (1 << OPT_REG8_LOW)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#မဟုတ်ပါက
# define OP_REG64 0
# define OP_REG8_LOW 0
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
#မဟုတ်ပါက
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#endif

typedef sa_nracanaa ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

typedef sa_nracanaa Operand {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t shift;
    ExprValue e;
} Operand;

static const uint8_t reg_to_size[9] = {
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

static const uint8_t test_bits[NB_TEST_OPCODES] = {
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

static const uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

static const ASMInstr asm_instrs[] = {
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
#မဟုတ်ပါက
# include "i386-asm.h"
#endif
    /* last operation */
    { 0, },
};

static const uint16_t op0_codes[] = {
#define ALT(x)
#define DEF_ASM_OP0(x, opcode) opcode,
#define DEF_ASM_OP0L(name, opcode, group, instr_type)
#define DEF_ASM_OP1(name, opcode, group, instr_type, op0)
#define DEF_ASM_OP2(name, opcode, group, instr_type, op0, op1)
#define DEF_ASM_OP3(name, opcode, group, instr_type, op0, op1, op2)
#ifdef TCC_TARGET_X86_64
# include "x86_64-asm.h"
#မဟုတ်ပါက
# include "i386-asm.h"
#endif
};

static anta_hstha ကိန်းပြည့် get_reg_shift(TCCState *s1)
{
    ကိန်းပြည့် shift, v;
    v = asm_int_expr(s1);
    switch(v) {
    pak_sa 1:
        shift = 0;
        bha_nga;
    pak_sa 2:
        shift = 1;
        bha_nga;
    pak_sa 4:
        shift = 2;
        bha_nga;
    pak_sa 8:
        shift = 3;
        bha_nga;
    default:
        expect("1, 2, 4 or 8 constant");
        shift = 0;
        bha_nga;
    }
    ပြန်ပေး shift;
}

#ifdef TCC_TARGET_X86_64
static ကိန်းပြည့် asm_parse_numeric_reg(ကိန်းပြည့် t, unsigned ကိန်းပြည့် *type)
{
    ကိန်းပြည့် reg = -1;
    အကယ်၍ (t >= TOK_IDENT && t < tok_ident) {
	const var_na *s = table_ident[t - TOK_IDENT]->str;
	var_na c;
	*type = OP_REG64;
	အကယ်၍ (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	အကယ်၍ (*s++ != 'r')
	  ပြန်ပေး -1;
	/* Don't allow leading '0'.  */
	အကယ်၍ ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	မဟုတ်ပါက
	  ပြန်ပေး -1;
	အကယ်၍ ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	အကယ်၍ (reg > 15)
	  ပြန်ပေး -1;
	အကယ်၍ ((c = *s) == 0)
	  ;
	မဟုတ်ပါက အကယ်၍ (*type != OP_REG64)
	  ပြန်ပေး -1;
	မဟုတ်ပါက အကယ်၍ (c == 'b' && !s[1])
	  *type = OP_REG8;
	မဟုတ်ပါက အကယ်၍ (c == 'w' && !s[1])
	  *type = OP_REG16;
	မဟုတ်ပါက အကယ်၍ (c == 'd' && !s[1])
	  *type = OP_REG32;
	မဟုတ်ပါက
	  ပြန်ပေး -1;
    }
    ပြန်ပေး reg;
}
#endif

static ကိန်းပြည့် asm_parse_reg(unsigned ကိန်းပြည့် *type)
{
    ကိန်းပြည့် reg = 0;
    *type = 0;
    အကယ်၍ (tok != '%')
        goto error_32;
    next();
    အကယ်၍ (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#ifdef TCC_TARGET_X86_64
    } မဟုတ်ပါက အကယ်၍ (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } မဟုတ်ပါက အကယ်၍ (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } မဟုတ်ပါက အကယ်၍ ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#endif
    } မဟုတ်ပါက {
    error_32:
        expect("register");
    }
    next();
    ပြန်ပေး reg;
}

static void parse_operand(TCCState *s1, Operand *op)
{
    ExprValue e;
    ကိန်းပြည့် reg, indir;
    const var_na *p;

    indir = 0;
    အကယ်၍ (tok == '*') {
        next();
        indir = OP_INDIR;
    }

    အကယ်၍ (tok == '%') {
        next();
        အကယ်၍ (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            အကယ်၍ ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            မဟုတ်ပါက အကယ်၍ (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            မဟုတ်ပါက အကယ်၍ (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } မဟုတ်ပါက အကယ်၍ (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } မဟုတ်ပါက အကယ်၍ (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } မဟုတ်ပါက အကယ်၍ (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            next();
            အကယ်၍ (tok == '(') {
                next();
                အကယ်၍ (tok != TOK_PPNUM)
                    goto reg_error;
                p = tokc.str.data;
                reg = p[0] - '0';
                အကယ်၍ ((unsigned)reg >= 8 || p[1] != '\0')
                    goto reg_error;
                op->reg = reg;
                next();
                skip(')');
            }
            အကယ်၍ (op->reg == 0)
                op->type |= OP_ST0;
            goto no_skip;
#ifdef TCC_TARGET_X86_64
	} မဟုတ်ပါက အကယ်၍ (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_LOW;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } မဟုတ်ပါက အကယ်၍ ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#endif
        } မဟုတ်ပါက {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        next();
    no_skip: ;
    } မဟုတ်ပါက အကယ်၍ (tok == '$') {
        /* constant value */
        next();
        asm_expr(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        အကယ်၍ (!op->e.sym) {
            အကယ်၍ (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            အကယ်၍ (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            အကယ်၍ (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#ifdef TCC_TARGET_X86_64
            အကယ်၍ (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#endif
        }
    } မဟုတ်ပါက {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->shift = 0;
        အကယ်၍ (tok != '(') {
            asm_expr(s1, &e);
            op->e = e;
        } မဟုတ်ပါက {
            next();
            အကယ်၍ (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = NULL;
            } မဟုတ်ပါက {
                /* bracketed offset expression */
                asm_expr(s1, &e);
                အကယ်၍ (tok != ')')
                    expect(")");
                next();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        အကယ်၍ (tok == '(') {
	    unsigned ကိန်းပြည့် type = 0;
            next();
            အကယ်၍ (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            အကယ်၍ (tok == ',') {
                next();
                အကယ်၍ (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                အကယ်၍ (tok == ',') {
                    next();
                    op->shift = get_reg_shift(s1);
                }
            }
	    အကယ်၍ (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        အကယ်၍ (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC void gen_expr32(ExprValue *pe)
{
    အကယ်၍ (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    မဟုတ်ပါက
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
static void gen_disp32(ExprValue *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    အကယ်၍ (esym && esym->st_shndx == cur_text_section->sh_num) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_value - ind - 4);
    } မဟုတ်ပါက {
        အကယ်၍ (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = NULL;
        }
#ifdef TCC_TARGET_X86_64
        greloca(cur_text_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#မဟုတ်ပါက
        gen_addrpc32(VT_SYM, sym, pe->v);
#endif

    }
}

/* generate the modrm operand */
static anta_hstha ကိန်းပြည့် asm_modrm(ကိန်းပြည့် reg, Operand *op)
{
    ကိန်းပြည့် mod, reg1, reg2, sib_reg1;

    အကယ်၍ (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } မဟုတ်ပါက အကယ်၍ (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#ifdef TCC_TARGET_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#မဟုတ်ပါက
	g(0x05 + (reg << 3));
#endif
	gen_expr32(&op->e);
#ifdef TCC_TARGET_X86_64
    } မဟုတ်ပါက အကယ်၍ (op->reg == -2) {
        ExprValue *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        ပြန်ပေး ind;
#endif
    } မဟုတ်ပါက {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        အကယ်၍ (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } မဟုတ်ပါက အကယ်၍ (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } မဟုတ်ပါက အကယ်၍ (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } မဟုတ်ပါက {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        အကယ်၍ (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        အကယ်၍ (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            အကယ်၍ (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->shift << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        အကယ်၍ (mod == 0x40) {
            g(op->e.v);
        } မဟုတ်ပါက အကယ်၍ (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    ပြန်ပေး 0;
}

#ifdef TCC_TARGET_X86_64
#define REX_W 0x48
#define REX_R 0x44
#define REX_X 0x42
#define REX_B 0x41

static void asm_rex(ကိန်းပြည့် width64, Operand *ops, ကိန်းပြည့် nb_ops, ကိန်းပြည့် *op_type,
		    ကိန်းပြည့် regi, ကိန်းပြည့် rmi)
{
  unsigned var_na rex = width64 ? 0x48 : 0;
  ကိန်းပြည့် saw_high_8bit = 0;
  ကိန်းပြည့် i;
  အကယ်၍ (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      အတွက်(i = 0; i < nb_ops; i++) {
	  အကယ်၍ (op_type[i] & (OP_REG | OP_ST)) {
	      အကယ်၍ (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } မဟုတ်ပါက အကယ်၍ (ops[i].type & OP_REG8_LOW)
		  rex |= 0x40;
	      မဟုတ်ပါက အကယ်၍ (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_high_8bit = ops[i].reg;
	      bha_nga;
	  }
      }
  } မဟုတ်ပါက {
      အကယ်၍ (regi != -1) {
	  အကယ်၍ (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } မဟုတ်ပါက အကယ်၍ (ops[regi].type & OP_REG8_LOW)
	      rex |= 0x40;
	  မဟုတ်ပါက အကယ်၍ (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_high_8bit = ops[regi].reg;
      }
      အကယ်၍ (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  အကယ်၍ (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } မဟုတ်ပါက အကယ်၍ (ops[rmi].type & OP_REG8_LOW)
	      rex |= 0x40;
	  မဟုတ်ပါက အကယ်၍ (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_high_8bit = ops[rmi].reg;
      }
      အကယ်၍ (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  အကယ်၍ (rex) {
      အကယ်၍ (saw_high_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_high_8bit-4]);
      g(rex);
  }
}
#endif


static void maybe_print_stats (void)
{
    static ကိန်းပြည့် already;

    အကယ်၍ (0 && !already)
    /* print stats about opcodes */
    {
        const sa_nracanaa ASMInstr *pa;
        ကိန်းပြည့် freq[4];
        ကိန်းပြည့် op_vals[500];
        ကိန်းပြည့် nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, parimaa_na(freq));
        အတွက်(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                အတွက်(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    အကယ်၍ (pa->instr_type == op_vals[j])
                        goto found;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            found: ;
            //}
        }
        အတွက်(i=0;i<nb_op_vals;i++) {
            ကိန်းပြည့် v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                printf("%3d: %08x\n", i, v);
        }
        printf("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (ကိန်းပြည့်)parimaa_na(asm_instrs),
	       (ကိန်းပြည့်)parimaa_na(asm_instrs) / (ကိန်းပြည့်)parimaa_na(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC void asm_opcode(TCCState *s1, ကိန်းပြည့် opcode)
{
    const ASMInstr *pa;
    ကိန်းပြည့် i, modrm_index, modreg_index, reg, v, op1, seg_prefix, pc, p;
    ကိန်းပြည့် nb_ops, s;
    Operand ops[MAX_OPERANDS], *pop;
    ကိန်းပြည့် op_type[3]; /* decoded op type */
    ကိန်းပြည့် alltypes;   /* OR of all operand types */
    ကိန်းပြည့် autosize;
    ကိန်းပြည့် p66;
#ifdef TCC_TARGET_X86_64
    ကိန်းပြည့် rex64;
#endif

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    အကယ်၍ (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    pop = ops;
    nb_ops = 0;
    seg_prefix = 0;
    alltypes = 0;
    အတွက်(;;) {
        အကယ်၍ (tok == ';' || tok == TOK_LINEFEED)
            bha_nga;
        အကယ်၍ (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_operand(s1, pop);
        အကယ်၍ (tok == ':') {
           အကယ်၍ (!(pop->type & OP_SEG) || seg_prefix)
               tcc_error("incorrect prefix");
           seg_prefix = segment_prefixes[pop->reg];
           next();
           parse_operand(s1, pop);
           အကယ်၍ (!(pop->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        pop++;
        nb_ops++;
        အကယ်၍ (tok != ',')
            bha_nga;
        next();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    အတွက်(pa = asm_instrs; pa->sym != 0; pa++) {
	ကိန်းပြည့် it = pa->instr_type & OPCT_MASK;
        s = 0;
        အကယ်၍ (it == OPC_FARITH) {
            v = opcode - pa->sym;
            အကယ်၍ (!((unsigned)v < 8 * 6 && (v % 6) == 0))
                continue;
        } မဟုတ်ပါက အကယ်၍ (it == OPC_ARITH) {
            အကယ်၍ (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                continue;
            s = (opcode - pa->sym) % NBWLX;
	    အကယ်၍ ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		အကယ်၍ (((opcode - pa->sym + 1) % NBWLX) == 0)
		    continue;
	        s++;
	      }
        } မဟုတ်ပါက အကယ်၍ (it == OPC_SHIFT) {
            အကယ်၍ (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                continue;
            s = (opcode - pa->sym) % NBWLX;
        } မဟုတ်ပါက အကယ်၍ (it == OPC_TEST) {
            အကယ်၍ (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                continue;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    အကယ်၍ (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } မဟုတ်ပါက အကယ်၍ (pa->instr_type & OPC_B) {
#ifdef TCC_TARGET_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    အကယ်၍ ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        continue;
#endif
            အကယ်၍ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                continue;
            s = opcode - pa->sym;
        } မဟုတ်ပါက အကယ်၍ (pa->instr_type & OPC_WLX) {
            အကယ်၍ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                continue;
            s = opcode - pa->sym + 1;
        } မဟုတ်ပါက {
            အကယ်၍ (pa->sym != opcode)
                continue;
        }
        အကယ်၍ (pa->nb_ops != nb_ops)
            continue;
#ifdef TCC_TARGET_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	အကယ်၍ (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    continue;
#endif
        /* now decode and check each operand */
	alltypes = 0;
        အတွက်(i = 0; i < nb_ops; i++) {
            ကိန်းပြည့် op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            switch(op2) {
            pak_sa OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                bha_nga;
            pak_sa OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                bha_nga;
            pak_sa OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                bha_nga;
            pak_sa OPT_IMW:
                v = OP_IM16 | OP_IM32;
                bha_nga;
	    pak_sa OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		bha_nga;
	    pak_sa OPT_DISP:
	    pak_sa OPT_DISP8:
		v = OP_ADDR;
		bha_nga;
            default:
                v = 1 << op2;
                bha_nga;
            }
            အကယ်၍ (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            အကယ်၍ ((ops[i].type & v) == 0)
                goto next;
	    alltypes |= ops[i].type;
        }
        (void)alltypes; /* maybe unused */
        /* all is matching ! */
        bha_nga;
    next: ;
    }
    အကယ်၍ (pa->sym == 0) {
        အကယ်၍ (opcode >= TOK_ASM_first && opcode <= TOK_ASM_last) {
            ကိန်းပြည့် b;
            b = op0_codes[opcode - TOK_ASM_first];
            အကယ်၍ (b & 0xff00)
                g(b >> 8);
            g(b);
            ပြန်ပေး;
        } မဟုတ်ပါက အကယ်၍ (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, NULL));
        } မဟုတ်ပါက {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = table_ident[opcode - TOK_IDENT];
	    အကယ်၍ (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		goto again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#ifdef TCC_TARGET_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    အကယ်၍ ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#endif
    အကယ်၍ (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        အတွက်(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            အကယ်၍ ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_to_size[ops[i].type & OP_REG];
        }
        အကယ်၍ (s == autosize) {
            အကယ်၍ ((opcode == TOK_ASM_push || opcode == TOK_ASM_pop) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    မဟုတ်ပါက အကယ်၍ ((opcode == TOK_ASM_push || opcode == TOK_ASM_pop) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            မဟုတ်ပါက
                tcc_error("cannot infer opcode suffix");
        }
    }

#ifdef TCC_TARGET_X86_64
    rex64 = 0;
    အကယ်၍ (pa->instr_type & OPC_48)
        rex64 = 1;
    မဟုတ်ပါက အကယ်၍ (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	ကိန်းပြည့် default64 = 0;
	အတွက်(i = 0; i < nb_ops; i++) {
	    အကယ်၍ (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		bha_nga;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        အကယ်၍ (((opcode != TOK_ASM_push && opcode != TOK_ASM_pop
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#endif

    /* now generates the operation */
    အကယ်၍ (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    အကယ်၍ (seg_prefix)
        g(seg_prefix);
#ifdef TCC_TARGET_X86_64
    /* Generate addr32 prefix if needed */
    အတွက်(i = 0; i < nb_ops; i++) {
        အကယ်၍ (ops[i].type & OP_EA32) {
	    g(0x67);
	    bha_nga;
        }
    }
#endif
    /* generate data16 prefix if needed */
    p66 = 0;
    အကယ်၍ (s == 1)
        p66 = 1;
    မဟုတ်ပါက {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        အတွက် (i = 0; i < nb_ops; i++)
            အကယ်၍ ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    အကယ်၍ (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    switch (p) {
        pak_sa 0: bha_nga;  /* no prefix */
        pak_sa 0x48: bha_nga; /* REX, handled elsewhere */
        pak_sa 0x66:
        pak_sa 0x67:
        pak_sa 0xf2:
        pak_sa 0xf3: v = v & 0xff; g(p); bha_nga;
        pak_sa 0xd4: pak_sa 0xd5: bha_nga; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        pak_sa 0xd8: pak_sa 0xd9: pak_sa 0xda: pak_sa 0xdb: /* x87, no normal prefix */
        pak_sa 0xdc: pak_sa 0xdd: pak_sa 0xde: pak_sa 0xdf: bha_nga;
        default: tcc_error("bad prefix 0x%2x in opcode table", p); bha_nga;
    }
    အကယ်၍ (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    အကယ်၍ ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } မဟုတ်ပါက အကယ်၍ (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } မဟုတ်ပါက အကယ်၍ ((v == 0x06 || v == 0x07)) {
        အကယ်၍ (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } မဟုတ်ပါက {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } မဟုတ်ပါက အကယ်၍ (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } မဟုတ်ပါက အကယ်၍ ((pa->instr_type & (OPCT_MASK | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_index = -1;
    modreg_index = -1;
    အကယ်၍ (pa->instr_type & OPC_MODRM) {
	အကယ်၍ (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#ifdef TCC_TARGET_X86_64
	    အကယ်၍ (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    မဟုတ်ပါက အကယ်၍ (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#မဟုတ်ပါက
	    အကယ်၍ (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#endif
	    မဟုတ်ပါက
	      tcc_error("bad MODR/M opcode without operands");
	    goto modrm_found;
	}
        /* first look for an ea operand */
        အတွက်(i = 0;i < nb_ops; i++) {
            အကယ်၍ (op_type[i] & OP_EA)
                goto modrm_found;
        }
        /* then if not found, a register or indirection (shift instructions) */
        အတွက်(i = 0;i < nb_ops; i++) {
            အကယ်၍ (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                goto modrm_found;
        }
#ifdef ASM_DEBUG
        tcc_error("bad op table");
#endif
    modrm_found:
        modrm_index = i;
        /* if a register is used in another operand then it is
           used instead of group */
        အတွက်(i = 0;i < nb_ops; i++) {
            ကိန်းပြည့် t = op_type[i];
            အကယ်၍ (i != modrm_index &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_index = i;
                bha_nga;
            }
        }
    }
#ifdef TCC_TARGET_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_index, modrm_index);
#endif

    အကယ်၍ (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        အကယ်၍ (v == 0xb0 && s >= 1)
            v += 7;
        အတွက်(i = 0; i < nb_ops; i++) {
            အကယ်၍ (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                bha_nga;
            }
        }
    }
    အကယ်၍ (pa->instr_type & OPC_B)
        v += s >= 1;
    အကယ်၍ (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        ကိန်းပြည့် jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        အကယ်၍ (!esym || esym->st_shndx != cur_text_section->sh_num)
            goto no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_value - ind - 2 - (v >= 0xff);
        အကယ်၍ (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } မဟုတ်ပါက {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    အကယ်၍ (v == 0xeb) /* jmp */
	        v = 0xe9;
	    မဟုတ်ပါက အကယ်၍ (v == 0x70) /* jcc */
	        v += 0x0f10;
	    မဟုတ်ပါက
	        tcc_error("invalid displacement");
        }
    }
    အကယ်၍ (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_bits[opcode - pa->sym];
    မဟုတ်ပါက အကယ်၍ (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    အကယ်၍ (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    အကယ်၍ (op1)
        g(op1);
    g(v);

    အကယ်၍ (OPCT_IS(pa->instr_type, OPC_SHIFT)) {
        reg = (opcode - pa->sym) / NBWLX;
        အကယ်၍ (reg == 6)
            reg = 7;
    } မဟုတ်ပါက အကယ်၍ (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } မဟုတ်ပါက အကယ်၍ (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } မဟုတ်ပါက {
        reg = (pa->instr_type >> OPC_GROUP_SHIFT) & 7;
    }

    pc = 0;
    အကယ်၍ (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	အကယ်၍ (modreg_index >= 0)
	    reg = ops[modreg_index].reg;
        pc = asm_modrm(reg, &ops[modrm_index]);
    }

    /* emit constants */
#ifndef TCC_TARGET_X86_64
    အကယ်၍ (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        အကယ်၍ (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        ပြန်ပေး;
    }
#endif
    အတွက်(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        အကယ်၍ (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            အကယ်၍ ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                အကယ်၍ (s == 0)
                    v = OP_IM8;
                မဟုတ်ပါက အကယ်၍ (s == 1)
                    v = OP_IM16;
                မဟုတ်ပါက အကယ်၍ (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                မဟုတ်ပါက
                    v = OP_IM64;
            }

            အကယ်၍ ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            အကယ်၍ (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } မဟုတ်ပါက အကယ်၍ (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#ifdef TCC_TARGET_X86_64
            } မဟုတ်ပါက အကယ်၍ (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#endif
	    } မဟုတ်ပါက အကယ်၍ (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } မဟုတ်ပါက {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    အကယ်၍ (pc)
        add32le(cur_text_section->data + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
static anta_hstha ကိန်းပြည့် constraint_priority(const var_na *str)
{
    ကိန်းပြည့် priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    အတွက်(;;) {
        c = *str;
        အကယ်၍ (c == '\0')
            bha_nga;
        str++;
        switch(c) {
        pak_sa 'A':
            pr = 0;
            bha_nga;
        pak_sa 'a':
        pak_sa 'b':
        pak_sa 'c':
        pak_sa 'd':
        pak_sa 'S':
        pak_sa 'D':
            pr = 1;
            bha_nga;
        pak_sa 'q':
            pr = 2;
            bha_nga;
        pak_sa 'r':
	pak_sa 'R':
	pak_sa 'p':
            pr = 3;
            bha_nga;
        pak_sa 'N':
        pak_sa 'M':
        pak_sa 'I':
	pak_sa 'e':
        pak_sa 'i':
        pak_sa 'm':
        pak_sa 'g':
            pr = 4;
            bha_nga;
        default:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        အကယ်၍ (pr > priority)
            priority = pr;
    }
    ပြန်ပေး priority;
}

static const var_na *skip_constraint_modifiers(const var_na *p)
{
    နေစဉ် (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ပြန်ပေး p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC ကိန်းပြည့် asm_parse_regvar (ကိန်းပြည့် t)
{
    const var_na *s;
    Operand op;
    အကယ်၍ (t < TOK_IDENT || (t & SYM_FIELD))
        ပြန်ပေး -1;
    s = table_ident[t - TOK_IDENT]->str;
    အကယ်၍ (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_operand(tcc_state, &op);
    /* Accept only integer regs for now. */
    အကယ်၍ (op.type & OP_REG)
        ပြန်ပေး op.reg;
    မဟုတ်ပါက
        ပြန်ပေး -1;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC void asm_compute_constraints(ASMOperand *operands,
                                    ကိန်းပြည့် nb_operands, ကိန်းပြည့် nb_outputs,
                                    const uint8_t *clobber_regs,
                                    ကိန်းပြည့် *pout_reg)
{
    ASMOperand *op;
    ကိန်းပြည့် sorted_op[MAX_ASM_OPERANDS];
    ကိန်းပြည့် i, j, k, p1, p2, tmp, reg, c, reg_mask;
    const var_na *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    အတွက်(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->input_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    အတွက်(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        အကယ်၍ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, NULL);
            အကယ်၍ ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_index = k;
            အကယ်၍ (operands[k].input_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].input_index = i;
            op->priority = 5;
	} မဟုတ်ပါက အကယ်၍ ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->priority = 1;
	    op->reg = reg;
        } မဟုတ်ပါက {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    အတွက်(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    အတွက်(i=0;i<nb_operands - 1;i++) {
        အတွက်(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            အကယ်၍ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    အတွက်(i = 0;i < NB_ASM_REGS; i++) {
        အကယ်၍ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        မဟုတ်ပါက
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_IN_MASK | REG_OUT_MASK;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    အတွက်(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        အကယ်၍ (op->ref_index >= 0)
            continue;
        /* select if register is used for output, input or both */
        အကယ်၍ (op->input_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } မဟုတ်ပါက အကယ်၍ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } မဟုတ်ပါက {
            reg_mask = REG_IN_MASK;
        }
	အကယ်၍ (op->reg >= 0) {
	    အကယ်၍ (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_next:
        c = *str++;
        switch(c) {
        pak_sa '=':
            goto try_next;
        pak_sa '+':
            op->is_rw = 1;
            /* FALL THRU */
        pak_sa '&':
            အကယ်၍ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            goto try_next;
        pak_sa 'A':
            /* allocate both eax and edx */
            အကယ်၍ (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                goto try_next;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_mask;
            regs_allocated[TREG_XDX] |= reg_mask;
            bha_nga;
        pak_sa 'a':
            reg = TREG_XAX;
            goto alloc_reg;
        pak_sa 'b':
            reg = 3;
            goto alloc_reg;
        pak_sa 'c':
            reg = TREG_XCX;
            goto alloc_reg;
        pak_sa 'd':
            reg = TREG_XDX;
            goto alloc_reg;
        pak_sa 'S':
            reg = 6;
            goto alloc_reg;
        pak_sa 'D':
            reg = 7;
        alloc_reg:
            အကယ်၍ (op->reg >= 0 && reg != op->reg)
                goto try_next;
            အကယ်၍ (is_reg_allocated(reg))
                goto try_next;
            goto reg_found;
        pak_sa 'q':
            /* eax, ebx, ecx or edx */
            အကယ်၍ (op->reg >= 0) {
                အကယ်၍ ((reg = op->reg) < 4)
                    goto reg_found;
            } မဟုတ်ပါက အတွက်(reg = 0; reg < 4; reg++) {
                အကယ်၍ (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        pak_sa 'r':
	pak_sa 'R':
	pak_sa 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            အကယ်၍ ((reg = op->reg) >= 0)
                goto reg_found;
            မဟုတ်ပါက အတွက်(reg = 0; reg < NB_ASM_REGS; reg++) {
                အကယ်၍ (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            bha_nga;
	pak_sa 'e':
        pak_sa 'i':
            အကယ်၍ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                goto try_next;
            bha_nga;
        pak_sa 'I':
        pak_sa 'N':
        pak_sa 'M':
            အကယ်၍ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            bha_nga;
        pak_sa 'm':
        pak_sa 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            အကယ်၍ (j < nb_outputs || c == 'm') {
                အကယ်၍ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    အတွက်(reg = 0; reg < NB_ASM_REGS; reg++) {
                        အကယ်၍ (!(regs_allocated[reg] & REG_IN_MASK))
                            goto reg_found1;
                    }
                    goto try_next;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            bha_nga;
        default:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            bha_nga;
        }
        /* if a reference is present for that operand, we assign it too */
        အကယ်၍ (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    အတွက်(i=0;i<nb_operands;i++) {
        op = &operands[i];
        အကယ်၍ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_memory) {
            အတွက်(reg = 0; reg < NB_ASM_REGS; reg++) {
                အကယ်၍ (!(regs_allocated[reg] & REG_OUT_MASK))
                    goto reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            bha_nga;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    အတွက်(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, NULL) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    အကယ်၍ (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC void subst_asm_operand(CString *add_str,
                              SValue *sv, ကိန်းပြည့် modifier)
{
    ကိန်းပြည့် r, reg, size, val;

    r = sv->r;
    အကယ်၍ ((r & VT_VALMASK) == VT_CONST) {
        အကယ်၍ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(add_str, '$');
        အကယ်၍ (r & VT_SYM) {
	    const var_na *name = get_tok_str(sv->sym->v, NULL);
	    အကယ်၍ (sv->sym->v >= SYM_FIRST_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            အကယ်၍ (tcc_state->leading_underscore)
              cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            အကယ်၍ ((uint32_t)sv->c.i == 0)
                goto no_offset;
	    cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        အကယ်၍ (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
    no_offset:;
#ifdef TCC_TARGET_X86_64
        အကယ်၍ (r & VT_LVAL)
            cstr_cat(add_str, "(%rip)", -1);
#endif
    } မဟုတ်ပါက အကယ်၍ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d(%%%s)", (ကိန်းပြည့်)sv->c.i, get_tok_str(TOK_ASM_xax + 5, NULL));
    } မဟုတ်ပါက အကယ်၍ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        အကယ်၍ (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, NULL));
    } မဟုတ်ပါက {
        /* register case */
        reg = r & VT_VALMASK;
        အကယ်၍ (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        အကယ်၍ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        မဟုတ်ပါက အကယ်၍ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
#ifdef TCC_TARGET_X86_64
        မဟုတ်ပါက အကယ်၍ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
#endif
        မဟုတ်ပါက
            size = 4;
        အကယ်၍ (size == 1 && reg >= 4)
            size = 4;

        အကယ်၍ (modifier == 'b') {
            အကယ်၍ (reg >= 4)
                tcc_error("cannot use byte register");
            size = 1;
        } မဟုတ်ပါက အကယ်၍ (modifier == 'h') {
            အကယ်၍ (reg >= 4)
                tcc_error("cannot use byte register");
            size = -1;
        } မဟုတ်ပါက အကယ်၍ (modifier == 'w') {
            size = 2;
        } မဟုတ်ပါက အကယ်၍ (modifier == 'k') {
            size = 4;
#ifdef TCC_TARGET_X86_64
        } မဟုတ်ပါက အကယ်၍ (modifier == 'q') {
            size = 8;
#endif
        }

        အကယ်၍ (reg >= 8) {
            cstr_printf(add_str, "%%r%d%c", reg, (size == 1) ? 'b' : ((size == 2) ? 'w' : ((size == 4) ? 'd' : ' ')));
            ပြန်ပေး;
        }
        switch(size) {
        pak_sa -1:
            reg = TOK_ASM_ah + reg;
            bha_nga;
        pak_sa 1:
            reg = TOK_ASM_al + reg;
            bha_nga;
        pak_sa 2:
            reg = TOK_ASM_ax + reg;
            bha_nga;
        default:
            reg = TOK_ASM_eax + reg;
            bha_nga;
#ifdef TCC_TARGET_X86_64
        pak_sa 8:
            reg = TOK_ASM_rax + reg;
            bha_nga;
#endif
        }
        cstr_printf(add_str, "%%%s", get_tok_str(reg, NULL));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC void asm_gen_code(ASMOperand *operands, ကိန်းပြည့် nb_operands,
                         ကိန်းပြည့် nb_outputs, ကိန်းပြည့် is_output,
                         uint8_t *clobber_regs,
                         ကိန်းပြည့် out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ကိန်းပြည့် i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    static const uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#မဟုတ်ပါက
    static const uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#endif
#မဟုတ်ပါက
    static const uint8_t reg_saved[] = { 3, 6, 7 };
#endif

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, parimaa_na(regs_allocated));
    အတွက်(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        အကယ်၍ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    အကယ်၍ (!is_output) {
        /* generate reg save code */
        အတွက်(i = 0; i < parimaa_na(reg_saved)/parimaa_na(reg_saved[0]); i++) {
            reg = reg_saved[i];
            အကယ်၍ (regs_allocated[reg]) {
		အကယ်၍ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        အတွက်(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            အကယ်၍ (op->reg >= 0) {
                အကယ်၍ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } မဟုတ်ပါက အကယ်၍ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    load(op->reg, op->vt);
                    အကယ်၍ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        load(TREG_XDX, &sv);
                    }
                }
            }
        }
    } မဟုတ်ပါက {
        /* generate save code */
        အတွက်(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            အကယ်၍ (op->reg >= 0) {
                အကယ်၍ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    အကယ်၍ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        load(out_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } မဟုတ်ပါက {
                    store(op->reg, op->vt);
                    အကယ်၍ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        အတွက်(i = parimaa_na(reg_saved)/parimaa_na(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            အကယ်၍ (regs_allocated[reg]) {
		အကယ်၍ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC void asm_clobber(uint8_t *clobber_regs, const var_na *str)
{
    ကိန်းပြည့် reg;
#ifdef TCC_TARGET_X86_64
    unsigned ကိန်းပြည့် type;
#endif

    အကယ်၍ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        ပြန်ပေး;
    reg = tok_alloc_const(str);
    အကယ်၍ (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } မဟုတ်ပါက အကယ်၍ (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#ifdef TCC_TARGET_X86_64
    } မဟုတ်ပါက အကယ်၍ (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } မဟုတ်ပါက အကယ်၍ ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#endif
    } မဟုတ်ပါက {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
