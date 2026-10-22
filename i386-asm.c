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
#അന്തര്ഭാവ "tcc.h"

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
#അല്ലെങ്കിൽ
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#endif

#define OPC_GROUP_SHIFT 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
എണ്ണൽ {
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
    OPT_REG8_താഴെയുള്ള, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
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
# define OP_REG8_താഴെയുള്ള (1 << OPT_REG8_താഴെയുള്ള)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#അല്ലെങ്കിൽ
# define OP_REG64 0
# define OP_REG8_താഴെയുള്ള 0
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
#അല്ലെങ്കിൽ
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#endif

തരനിർവചനം ഘടന ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

തരനിർവചനം ഘടന Operand {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t shift;
    വ്യഞ്ജകം_മൂല്യം e;
} Operand;

സ്ഥിതം സ്ഥിരം uint8_t reg_to_size[9] = {
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

സ്ഥിതം സ്ഥിരം uint8_t test_bits[NB_TEST_OPCODES] = {
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

സ്ഥിതം സ്ഥിരം uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

സ്ഥിതം സ്ഥിരം ASMInstr asm_instrs[] = {
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
#അല്ലെങ്കിൽ
# include "i386-asm.h"
#endif
    /* last operation */
    { 0, },
};

സ്ഥിതം സ്ഥിരം uint16_t op0_codes[] = {
#define ALT(x)
#define DEF_ASM_OP0(x, opcode) opcode,
#define DEF_ASM_OP0L(name, opcode, group, instr_type)
#define DEF_ASM_OP1(name, opcode, group, instr_type, op0)
#define DEF_ASM_OP2(name, opcode, group, instr_type, op0, op1)
#define DEF_ASM_OP3(name, opcode, group, instr_type, op0, op1, op2)
#ifdef TCC_TARGET_X86_64
# include "x86_64-asm.h"
#അല്ലെങ്കിൽ
# include "i386-asm.h"
#endif
};

സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ get_reg_shift(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ shift, v;
    v = asm_int_വ്യഞ്ജകം(s1);
    തിരഞ്ഞെടുപ്പ്(v) {
    അവസ്ഥ 1:
        shift = 0;
        നിർത്തുക;
    അവസ്ഥ 2:
        shift = 1;
        നിർത്തുക;
    അവസ്ഥ 4:
        shift = 2;
        നിർത്തുക;
    അവസ്ഥ 8:
        shift = 3;
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        expect("1, 2, 4 or 8 constant");
        shift = 0;
        നിർത്തുക;
    }
    തിരികെ shift;
}

#ifdef TCC_TARGET_X86_64
സ്ഥിതം പൂർണ്ണസംഖ്യ asm_parse_numeric_reg(പൂർണ്ണസംഖ്യ t, unsigned പൂർണ്ണസംഖ്യ *type)
{
    പൂർണ്ണസംഖ്യ reg = -1;
    എങ്കിൽ (t >= TOK_IDENT && t < tok_ident) {
	സ്ഥിരം അക്ഷരം *s = table_ident[t - TOK_IDENT]->str;
	അക്ഷരം c;
	*type = OP_REG64;
	എങ്കിൽ (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	എങ്കിൽ (*s++ != 'r')
	  തിരികെ -1;
	/* Don't allow leading '0'.  */
	എങ്കിൽ ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	അല്ലെങ്കിൽ
	  തിരികെ -1;
	എങ്കിൽ ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	എങ്കിൽ (reg > 15)
	  തിരികെ -1;
	എങ്കിൽ ((c = *s) == 0)
	  ;
	അല്ലെങ്കിൽ എങ്കിൽ (*type != OP_REG64)
	  തിരികെ -1;
	അല്ലെങ്കിൽ എങ്കിൽ (c == 'b' && !s[1])
	  *type = OP_REG8;
	അല്ലെങ്കിൽ എങ്കിൽ (c == 'w' && !s[1])
	  *type = OP_REG16;
	അല്ലെങ്കിൽ എങ്കിൽ (c == 'd' && !s[1])
	  *type = OP_REG32;
	അല്ലെങ്കിൽ
	  തിരികെ -1;
    }
    തിരികെ reg;
}
#endif

സ്ഥിതം പൂർണ്ണസംഖ്യ asm_parse_reg(unsigned പൂർണ്ണസംഖ്യ *type)
{
    പൂർണ്ണസംഖ്യ reg = 0;
    *type = 0;
    എങ്കിൽ (tok != '%')
        പോകുക error_32;
    next();
    എങ്കിൽ (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#ifdef TCC_TARGET_X86_64
    } അല്ലെങ്കിൽ എങ്കിൽ (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } അല്ലെങ്കിൽ എങ്കിൽ ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#endif
    } അല്ലെങ്കിൽ {
    error_32:
        expect("register");
    }
    next();
    തിരികെ reg;
}

സ്ഥിതം ശൂന്യം parse_operand(TCCState *s1, Operand *op)
{
    വ്യഞ്ജകം_മൂല്യം e;
    പൂർണ്ണസംഖ്യ reg, indir;
    സ്ഥിരം അക്ഷരം *p;

    indir = 0;
    എങ്കിൽ (tok == '*') {
        next();
        indir = OP_INDIR;
    }

    എങ്കിൽ (tok == '%') {
        next();
        എങ്കിൽ (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            എങ്കിൽ ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            അല്ലെങ്കിൽ എങ്കിൽ (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            അല്ലെങ്കിൽ എങ്കിൽ (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } അല്ലെങ്കിൽ എങ്കിൽ (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } അല്ലെങ്കിൽ എങ്കിൽ (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            next();
            എങ്കിൽ (tok == '(') {
                next();
                എങ്കിൽ (tok != TOK_PPNUM)
                    പോകുക reg_error;
                p = tokc.str.data;
                reg = p[0] - '0';
                എങ്കിൽ ((unsigned)reg >= 8 || p[1] != '\0')
                    പോകുക reg_error;
                op->reg = reg;
                next();
                skip(')');
            }
            എങ്കിൽ (op->reg == 0)
                op->type |= OP_ST0;
            പോകുക no_skip;
#ifdef TCC_TARGET_X86_64
	} അല്ലെങ്കിൽ എങ്കിൽ (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_താഴെയുള്ള;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } അല്ലെങ്കിൽ എങ്കിൽ ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#endif
        } അല്ലെങ്കിൽ {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        next();
    no_skip: ;
    } അല്ലെങ്കിൽ എങ്കിൽ (tok == '$') {
        /* constant value */
        next();
        asm_വ്യഞ്ജകം(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        എങ്കിൽ (!op->e.sym) {
            എങ്കിൽ (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            എങ്കിൽ (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            എങ്കിൽ (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#ifdef TCC_TARGET_X86_64
            എങ്കിൽ (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#endif
        }
    } അല്ലെങ്കിൽ {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->shift = 0;
        എങ്കിൽ (tok != '(') {
            asm_വ്യഞ്ജകം(s1, &e);
            op->e = e;
        } അല്ലെങ്കിൽ {
            next();
            എങ്കിൽ (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = ശൂന്യ;
            } അല്ലെങ്കിൽ {
                /* bracketed offset expression */
                asm_വ്യഞ്ജകം(s1, &e);
                എങ്കിൽ (tok != ')')
                    expect(")");
                next();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        എങ്കിൽ (tok == '(') {
	    unsigned പൂർണ്ണസംഖ്യ type = 0;
            next();
            എങ്കിൽ (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            എങ്കിൽ (tok == ',') {
                next();
                എങ്കിൽ (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                എങ്കിൽ (tok == ',') {
                    next();
                    op->shift = get_reg_shift(s1);
                }
            }
	    എങ്കിൽ (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        എങ്കിൽ (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC ശൂന്യം gen_expr32(വ്യഞ്ജകം_മൂല്യം *pe)
{
    എങ്കിൽ (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    അല്ലെങ്കിൽ
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
സ്ഥിതം ശൂന്യം gen_disp32(വ്യഞ്ജകം_മൂല്യം *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    എങ്കിൽ (esym && esym->st_shndx == cur_text_section->sh_അക്കം) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_മൂല്യം - ind - 4);
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = ശൂന്യ;
        }
#ifdef TCC_TARGET_X86_64
        greloca(cur_text_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#അല്ലെങ്കിൽ
        gen_addrpc32(VT_SYM, sym, pe->v);
#endif

    }
}

/* generate the modrm operand */
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ asm_modrm(പൂർണ്ണസംഖ്യ reg, Operand *op)
{
    പൂർണ്ണസംഖ്യ mod, reg1, reg2, sib_reg1;

    എങ്കിൽ (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } അല്ലെങ്കിൽ എങ്കിൽ (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#ifdef TCC_TARGET_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#അല്ലെങ്കിൽ
	g(0x05 + (reg << 3));
#endif
	gen_expr32(&op->e);
#ifdef TCC_TARGET_X86_64
    } അല്ലെങ്കിൽ എങ്കിൽ (op->reg == -2) {
        വ്യഞ്ജകം_മൂല്യം *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        തിരികെ ind;
#endif
    } അല്ലെങ്കിൽ {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        എങ്കിൽ (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } അല്ലെങ്കിൽ എങ്കിൽ (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } അല്ലെങ്കിൽ എങ്കിൽ (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } അല്ലെങ്കിൽ {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        എങ്കിൽ (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        എങ്കിൽ (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            എങ്കിൽ (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->shift << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        എങ്കിൽ (mod == 0x40) {
            g(op->e.v);
        } അല്ലെങ്കിൽ എങ്കിൽ (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    തിരികെ 0;
}

#ifdef TCC_TARGET_X86_64
#define REX_W 0x48
#define REX_R 0x44
#define REX_X 0x42
#define REX_B 0x41

സ്ഥിതം ശൂന്യം asm_rex(പൂർണ്ണസംഖ്യ width64, Operand *ops, പൂർണ്ണസംഖ്യ nb_ops, പൂർണ്ണസംഖ്യ *op_type,
		    പൂർണ്ണസംഖ്യ regi, പൂർണ്ണസംഖ്യ rmi)
{
  unsigned അക്ഷരം rex = width64 ? 0x48 : 0;
  പൂർണ്ണസംഖ്യ saw_മുകളിലെ_8bit = 0;
  പൂർണ്ണസംഖ്യ i;
  എങ്കിൽ (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      വേണ്ടി(i = 0; i < nb_ops; i++) {
	  എങ്കിൽ (op_type[i] & (OP_REG | OP_ST)) {
	      എങ്കിൽ (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } അല്ലെങ്കിൽ എങ്കിൽ (ops[i].type & OP_REG8_താഴെയുള്ള)
		  rex |= 0x40;
	      അല്ലെങ്കിൽ എങ്കിൽ (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_മുകളിലെ_8bit = ops[i].reg;
	      നിർത്തുക;
	  }
      }
  } അല്ലെങ്കിൽ {
      എങ്കിൽ (regi != -1) {
	  എങ്കിൽ (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } അല്ലെങ്കിൽ എങ്കിൽ (ops[regi].type & OP_REG8_താഴെയുള്ള)
	      rex |= 0x40;
	  അല്ലെങ്കിൽ എങ്കിൽ (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_മുകളിലെ_8bit = ops[regi].reg;
      }
      എങ്കിൽ (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  എങ്കിൽ (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } അല്ലെങ്കിൽ എങ്കിൽ (ops[rmi].type & OP_REG8_താഴെയുള്ള)
	      rex |= 0x40;
	  അല്ലെങ്കിൽ എങ്കിൽ (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_മുകളിലെ_8bit = ops[rmi].reg;
      }
      എങ്കിൽ (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  എങ്കിൽ (rex) {
      എങ്കിൽ (saw_മുകളിലെ_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_മുകളിലെ_8bit-4]);
      g(rex);
  }
}
#endif


സ്ഥിതം ശൂന്യം maybe_print_stats (ശൂന്യം)
{
    സ്ഥിതം പൂർണ്ണസംഖ്യ already;

    എങ്കിൽ (0 && !already)
    /* print stats about opcodes */
    {
        സ്ഥിരം ഘടന ASMInstr *pa;
        പൂർണ്ണസംഖ്യ freq[4];
        പൂർണ്ണസംഖ്യ op_vals[500];
        പൂർണ്ണസംഖ്യ nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, വലുപ്പം(freq));
        വേണ്ടി(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                വേണ്ടി(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    എങ്കിൽ (pa->instr_type == op_vals[j])
                        പോകുക found;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            found: ;
            //}
        }
        വേണ്ടി(i=0;i<nb_op_vals;i++) {
            പൂർണ്ണസംഖ്യ v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                printf("%3d: %08x\n", i, v);
        }
        printf("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (പൂർണ്ണസംഖ്യ)വലുപ്പം(asm_instrs),
	       (പൂർണ്ണസംഖ്യ)വലുപ്പം(asm_instrs) / (പൂർണ്ണസംഖ്യ)വലുപ്പം(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC ശൂന്യം asm_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ opcode)
{
    സ്ഥിരം ASMInstr *pa;
    പൂർണ്ണസംഖ്യ i, modrm_index, modreg_index, reg, v, op1, seg_prefix, pc, p;
    പൂർണ്ണസംഖ്യ nb_ops, s;
    Operand ops[MAX_OPERANDS], *എടുക്കുക;
    പൂർണ്ണസംഖ്യ op_type[3]; /* decoded op type */
    പൂർണ്ണസംഖ്യ alltypes;   /* OR of all operand types */
    പൂർണ്ണസംഖ്യ autosize;
    പൂർണ്ണസംഖ്യ p66;
#ifdef TCC_TARGET_X86_64
    പൂർണ്ണസംഖ്യ rex64;
#endif

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    എങ്കിൽ (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    എടുക്കുക = ops;
    nb_ops = 0;
    seg_prefix = 0;
    alltypes = 0;
    വേണ്ടി(;;) {
        എങ്കിൽ (tok == ';' || tok == TOK_LINEFEED)
            നിർത്തുക;
        എങ്കിൽ (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_operand(s1, എടുക്കുക);
        എങ്കിൽ (tok == ':') {
           എങ്കിൽ (!(എടുക്കുക->type & OP_SEG) || seg_prefix)
               tcc_error("incorrect prefix");
           seg_prefix = segment_prefixes[എടുക്കുക->reg];
           next();
           parse_operand(s1, എടുക്കുക);
           എങ്കിൽ (!(എടുക്കുക->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        എടുക്കുക++;
        nb_ops++;
        എങ്കിൽ (tok != ',')
            നിർത്തുക;
        next();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    വേണ്ടി(pa = asm_instrs; pa->sym != 0; pa++) {
	പൂർണ്ണസംഖ്യ it = pa->instr_type & OPCT_MASK;
        s = 0;
        എങ്കിൽ (it == OPC_FARITH) {
            v = opcode - pa->sym;
            എങ്കിൽ (!((unsigned)v < 8 * 6 && (v % 6) == 0))
                തുടരുക;
        } അല്ലെങ്കിൽ എങ്കിൽ (it == OPC_ARITH) {
            എങ്കിൽ (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                തുടരുക;
            s = (opcode - pa->sym) % NBWLX;
	    എങ്കിൽ ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		എങ്കിൽ (((opcode - pa->sym + 1) % NBWLX) == 0)
		    തുടരുക;
	        s++;
	      }
        } അല്ലെങ്കിൽ എങ്കിൽ (it == OPC_SHIFT) {
            എങ്കിൽ (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                തുടരുക;
            s = (opcode - pa->sym) % NBWLX;
        } അല്ലെങ്കിൽ എങ്കിൽ (it == OPC_TEST) {
            എങ്കിൽ (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                തുടരുക;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    എങ്കിൽ (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (pa->instr_type & OPC_B) {
#ifdef TCC_TARGET_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    എങ്കിൽ ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        തുടരുക;
#endif
            എങ്കിൽ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                തുടരുക;
            s = opcode - pa->sym;
        } അല്ലെങ്കിൽ എങ്കിൽ (pa->instr_type & OPC_WLX) {
            എങ്കിൽ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                തുടരുക;
            s = opcode - pa->sym + 1;
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (pa->sym != opcode)
                തുടരുക;
        }
        എങ്കിൽ (pa->nb_ops != nb_ops)
            തുടരുക;
#ifdef TCC_TARGET_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	എങ്കിൽ (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    തുടരുക;
#endif
        /* now decode and check each operand */
	alltypes = 0;
        വേണ്ടി(i = 0; i < nb_ops; i++) {
            പൂർണ്ണസംഖ്യ op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            തിരഞ്ഞെടുപ്പ്(op2) {
            അവസ്ഥ OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                നിർത്തുക;
            അവസ്ഥ OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                നിർത്തുക;
            അവസ്ഥ OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                നിർത്തുക;
            അവസ്ഥ OPT_IMW:
                v = OP_IM16 | OP_IM32;
                നിർത്തുക;
	    അവസ്ഥ OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		നിർത്തുക;
	    അവസ്ഥ OPT_DISP:
	    അവസ്ഥ OPT_DISP8:
		v = OP_ADDR;
		നിർത്തുക;
            സ്ഥിരസ്ഥിതി:
                v = 1 << op2;
                നിർത്തുക;
            }
            എങ്കിൽ (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            എങ്കിൽ ((ops[i].type & v) == 0)
                പോകുക next;
	    alltypes |= ops[i].type;
        }
        (ശൂന്യം)alltypes; /* maybe unused */
        /* all is matching ! */
        നിർത്തുക;
    next: ;
    }
    എങ്കിൽ (pa->sym == 0) {
        എങ്കിൽ (opcode >= TOK_ASM_first && opcode <= TOK_ASM_last) {
            പൂർണ്ണസംഖ്യ b;
            b = op0_codes[opcode - TOK_ASM_first];
            എങ്കിൽ (b & 0xff00)
                g(b >> 8);
            g(b);
            തിരികെ;
        } അല്ലെങ്കിൽ എങ്കിൽ (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, ശൂന്യ));
        } അല്ലെങ്കിൽ {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = table_ident[opcode - TOK_IDENT];
	    എങ്കിൽ (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		പോകുക again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#ifdef TCC_TARGET_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    എങ്കിൽ ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#endif
    എങ്കിൽ (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        വേണ്ടി(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            എങ്കിൽ ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_to_size[ops[i].type & OP_REG];
        }
        എങ്കിൽ (s == autosize) {
            എങ്കിൽ ((opcode == TOK_ASM_തള്ളുക || opcode == TOK_ASM_എടുക്കുക) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    അല്ലെങ്കിൽ എങ്കിൽ ((opcode == TOK_ASM_തള്ളുക || opcode == TOK_ASM_എടുക്കുക) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            അല്ലെങ്കിൽ
                tcc_error("cannot infer opcode suffix");
        }
    }

#ifdef TCC_TARGET_X86_64
    rex64 = 0;
    എങ്കിൽ (pa->instr_type & OPC_48)
        rex64 = 1;
    അല്ലെങ്കിൽ എങ്കിൽ (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	പൂർണ്ണസംഖ്യ default64 = 0;
	വേണ്ടി(i = 0; i < nb_ops; i++) {
	    എങ്കിൽ (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		നിർത്തുക;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        എങ്കിൽ (((opcode != TOK_ASM_തള്ളുക && opcode != TOK_ASM_എടുക്കുക
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#endif

    /* now generates the operation */
    എങ്കിൽ (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    എങ്കിൽ (seg_prefix)
        g(seg_prefix);
#ifdef TCC_TARGET_X86_64
    /* Generate addr32 prefix if needed */
    വേണ്ടി(i = 0; i < nb_ops; i++) {
        എങ്കിൽ (ops[i].type & OP_EA32) {
	    g(0x67);
	    നിർത്തുക;
        }
    }
#endif
    /* generate data16 prefix if needed */
    p66 = 0;
    എങ്കിൽ (s == 1)
        p66 = 1;
    അല്ലെങ്കിൽ {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        വേണ്ടി (i = 0; i < nb_ops; i++)
            എങ്കിൽ ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    എങ്കിൽ (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    തിരഞ്ഞെടുപ്പ് (p) {
        അവസ്ഥ 0: നിർത്തുക;  /* no prefix */
        അവസ്ഥ 0x48: നിർത്തുക; /* REX, handled elsewhere */
        അവസ്ഥ 0x66:
        അവസ്ഥ 0x67:
        അവസ്ഥ 0xf2:
        അവസ്ഥ 0xf3: v = v & 0xff; g(p); നിർത്തുക;
        അവസ്ഥ 0xd4: അവസ്ഥ 0xd5: നിർത്തുക; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        അവസ്ഥ 0xd8: അവസ്ഥ 0xd9: അവസ്ഥ 0xda: അവസ്ഥ 0xdb: /* x87, no normal prefix */
        അവസ്ഥ 0xdc: അവസ്ഥ 0xdd: അവസ്ഥ 0xde: അവസ്ഥ 0xdf: നിർത്തുക;
        സ്ഥിരസ്ഥിതി: tcc_error("bad prefix 0x%2x in opcode table", p); നിർത്തുക;
    }
    എങ്കിൽ (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    എങ്കിൽ ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } അല്ലെങ്കിൽ എങ്കിൽ (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } അല്ലെങ്കിൽ എങ്കിൽ ((v == 0x06 || v == 0x07)) {
        എങ്കിൽ (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } അല്ലെങ്കിൽ {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } അല്ലെങ്കിൽ എങ്കിൽ (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } അല്ലെങ്കിൽ എങ്കിൽ ((pa->instr_type & (OPCT_MASK | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_index = -1;
    modreg_index = -1;
    എങ്കിൽ (pa->instr_type & OPC_MODRM) {
	എങ്കിൽ (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#ifdef TCC_TARGET_X86_64
	    എങ്കിൽ (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    അല്ലെങ്കിൽ എങ്കിൽ (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#അല്ലെങ്കിൽ
	    എങ്കിൽ (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#endif
	    അല്ലെങ്കിൽ
	      tcc_error("bad MODR/M opcode without operands");
	    പോകുക modrm_found;
	}
        /* first look for an ea operand */
        വേണ്ടി(i = 0;i < nb_ops; i++) {
            എങ്കിൽ (op_type[i] & OP_EA)
                പോകുക modrm_found;
        }
        /* then if not found, a register or indirection (shift instructions) */
        വേണ്ടി(i = 0;i < nb_ops; i++) {
            എങ്കിൽ (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                പോകുക modrm_found;
        }
#ifdef ASM_DEBUG
        tcc_error("bad op table");
#endif
    modrm_found:
        modrm_index = i;
        /* if a register is used in another operand then it is
           used instead of group */
        വേണ്ടി(i = 0;i < nb_ops; i++) {
            പൂർണ്ണസംഖ്യ t = op_type[i];
            എങ്കിൽ (i != modrm_index &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_index = i;
                നിർത്തുക;
            }
        }
    }
#ifdef TCC_TARGET_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_index, modrm_index);
#endif

    എങ്കിൽ (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        എങ്കിൽ (v == 0xb0 && s >= 1)
            v += 7;
        വേണ്ടി(i = 0; i < nb_ops; i++) {
            എങ്കിൽ (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                നിർത്തുക;
            }
        }
    }
    എങ്കിൽ (pa->instr_type & OPC_B)
        v += s >= 1;
    എങ്കിൽ (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        പൂർണ്ണസംഖ്യ jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        എങ്കിൽ (!esym || esym->st_shndx != cur_text_section->sh_അക്കം)
            പോകുക no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_മൂല്യം - ind - 2 - (v >= 0xff);
        എങ്കിൽ (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } അല്ലെങ്കിൽ {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    എങ്കിൽ (v == 0xeb) /* jmp */
	        v = 0xe9;
	    അല്ലെങ്കിൽ എങ്കിൽ (v == 0x70) /* jcc */
	        v += 0x0f10;
	    അല്ലെങ്കിൽ
	        tcc_error("invalid displacement");
        }
    }
    എങ്കിൽ (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_bits[opcode - pa->sym];
    അല്ലെങ്കിൽ എങ്കിൽ (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    എങ്കിൽ (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    എങ്കിൽ (op1)
        g(op1);
    g(v);

    എങ്കിൽ (OPCT_IS(pa->instr_type, OPC_SHIFT)) {
        reg = (opcode - pa->sym) / NBWLX;
        എങ്കിൽ (reg == 6)
            reg = 7;
    } അല്ലെങ്കിൽ എങ്കിൽ (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } അല്ലെങ്കിൽ എങ്കിൽ (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } അല്ലെങ്കിൽ {
        reg = (pa->instr_type >> OPC_GROUP_SHIFT) & 7;
    }

    pc = 0;
    എങ്കിൽ (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	എങ്കിൽ (modreg_index >= 0)
	    reg = ops[modreg_index].reg;
        pc = asm_modrm(reg, &ops[modrm_index]);
    }

    /* emit constants */
#ifndef TCC_TARGET_X86_64
    എങ്കിൽ (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        എങ്കിൽ (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        തിരികെ;
    }
#endif
    വേണ്ടി(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        എങ്കിൽ (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            എങ്കിൽ ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                എങ്കിൽ (s == 0)
                    v = OP_IM8;
                അല്ലെങ്കിൽ എങ്കിൽ (s == 1)
                    v = OP_IM16;
                അല്ലെങ്കിൽ എങ്കിൽ (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                അല്ലെങ്കിൽ
                    v = OP_IM64;
            }

            എങ്കിൽ ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            എങ്കിൽ (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } അല്ലെങ്കിൽ എങ്കിൽ (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#ifdef TCC_TARGET_X86_64
            } അല്ലെങ്കിൽ എങ്കിൽ (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#endif
	    } അല്ലെങ്കിൽ എങ്കിൽ (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } അല്ലെങ്കിൽ {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    എങ്കിൽ (pc)
        add32le(cur_text_section->data + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ constraint_priority(സ്ഥിരം അക്ഷരം *str)
{
    പൂർണ്ണസംഖ്യ priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    വേണ്ടി(;;) {
        c = *str;
        എങ്കിൽ (c == '\0')
            നിർത്തുക;
        str++;
        തിരഞ്ഞെടുപ്പ്(c) {
        അവസ്ഥ 'A':
            pr = 0;
            നിർത്തുക;
        അവസ്ഥ 'a':
        അവസ്ഥ 'b':
        അവസ്ഥ 'c':
        അവസ്ഥ 'd':
        അവസ്ഥ 'S':
        അവസ്ഥ 'D':
            pr = 1;
            നിർത്തുക;
        അവസ്ഥ 'q':
            pr = 2;
            നിർത്തുക;
        അവസ്ഥ 'r':
	അവസ്ഥ 'R':
	അവസ്ഥ 'p':
            pr = 3;
            നിർത്തുക;
        അവസ്ഥ 'N':
        അവസ്ഥ 'M':
        അവസ്ഥ 'I':
	അവസ്ഥ 'e':
        അവസ്ഥ 'i':
        അവസ്ഥ 'm':
        അവസ്ഥ 'g':
            pr = 4;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        എങ്കിൽ (pr > priority)
            priority = pr;
    }
    തിരികെ priority;
}

സ്ഥിതം സ്ഥിരം അക്ഷരം *skip_constraint_modifiers(സ്ഥിരം അക്ഷരം *p)
{
    ആകുമ്പോൾ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    തിരികെ p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC പൂർണ്ണസംഖ്യ asm_parse_regvar (പൂർണ്ണസംഖ്യ t)
{
    സ്ഥിരം അക്ഷരം *s;
    Operand op;
    എങ്കിൽ (t < TOK_IDENT || (t & SYM_FIELD))
        തിരികെ -1;
    s = table_ident[t - TOK_IDENT]->str;
    എങ്കിൽ (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_operand(tcc_state, &op);
    /* Accept only integer regs for now. */
    എങ്കിൽ (op.type & OP_REG)
        തിരികെ op.reg;
    അല്ലെങ്കിൽ
        തിരികെ -1;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC ശൂന്യം asm_compute_constraints(ASMOperand *operands,
                                    പൂർണ്ണസംഖ്യ nb_operands, പൂർണ്ണസംഖ്യ nb_outputs,
                                    സ്ഥിരം uint8_t *clobber_regs,
                                    പൂർണ്ണസംഖ്യ *pout_reg)
{
    ASMOperand *op;
    പൂർണ്ണസംഖ്യ sorted_op[MAX_ASM_OPERANDS];
    പൂർണ്ണസംഖ്യ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    സ്ഥിരം അക്ഷരം *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    വേണ്ടി(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->നിവേശം_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    വേണ്ടി(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        എങ്കിൽ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, ശൂന്യ);
            എങ്കിൽ ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_index = k;
            എങ്കിൽ (operands[k].നിവേശം_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].നിവേശം_index = i;
            op->priority = 5;
	} അല്ലെങ്കിൽ എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->priority = 1;
	    op->reg = reg;
        } അല്ലെങ്കിൽ {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    വേണ്ടി(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    വേണ്ടി(i=0;i<nb_operands - 1;i++) {
        വേണ്ടി(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            എങ്കിൽ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    വേണ്ടി(i = 0;i < NB_ASM_REGS; i++) {
        എങ്കിൽ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        അല്ലെങ്കിൽ
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_IN_MASK | REG_OUT_MASK;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    വേണ്ടി(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        എങ്കിൽ (op->ref_index >= 0)
            തുടരുക;
        /* select if register is used for output, input or both */
        എങ്കിൽ (op->നിവേശം_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } അല്ലെങ്കിൽ എങ്കിൽ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } അല്ലെങ്കിൽ {
            reg_mask = REG_IN_MASK;
        }
	എങ്കിൽ (op->reg >= 0) {
	    എങ്കിൽ (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_next:
        c = *str++;
        തിരഞ്ഞെടുപ്പ്(c) {
        അവസ്ഥ '=':
            പോകുക try_next;
        അവസ്ഥ '+':
            op->is_rw = 1;
            /* FALL THRU */
        അവസ്ഥ '&':
            എങ്കിൽ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            പോകുക try_next;
        അവസ്ഥ 'A':
            /* allocate both eax and edx */
            എങ്കിൽ (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                പോകുക try_next;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_mask;
            regs_allocated[TREG_XDX] |= reg_mask;
            നിർത്തുക;
        അവസ്ഥ 'a':
            reg = TREG_XAX;
            പോകുക alloc_reg;
        അവസ്ഥ 'b':
            reg = 3;
            പോകുക alloc_reg;
        അവസ്ഥ 'c':
            reg = TREG_XCX;
            പോകുക alloc_reg;
        അവസ്ഥ 'd':
            reg = TREG_XDX;
            പോകുക alloc_reg;
        അവസ്ഥ 'S':
            reg = 6;
            പോകുക alloc_reg;
        അവസ്ഥ 'D':
            reg = 7;
        alloc_reg:
            എങ്കിൽ (op->reg >= 0 && reg != op->reg)
                പോകുക try_next;
            എങ്കിൽ (is_reg_allocated(reg))
                പോകുക try_next;
            പോകുക reg_found;
        അവസ്ഥ 'q':
            /* eax, ebx, ecx or edx */
            എങ്കിൽ (op->reg >= 0) {
                എങ്കിൽ ((reg = op->reg) < 4)
                    പോകുക reg_found;
            } അല്ലെങ്കിൽ വേണ്ടി(reg = 0; reg < 4; reg++) {
                എങ്കിൽ (!is_reg_allocated(reg))
                    പോകുക reg_found;
            }
            പോകുക try_next;
        അവസ്ഥ 'r':
	അവസ്ഥ 'R':
	അവസ്ഥ 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            എങ്കിൽ ((reg = op->reg) >= 0)
                പോകുക reg_found;
            അല്ലെങ്കിൽ വേണ്ടി(reg = 0; reg < NB_ASM_REGS; reg++) {
                എങ്കിൽ (!is_reg_allocated(reg))
                    പോകുക reg_found;
            }
            പോകുക try_next;
        reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            നിർത്തുക;
	അവസ്ഥ 'e':
        അവസ്ഥ 'i':
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'I':
        അവസ്ഥ 'N':
        അവസ്ഥ 'M':
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'm':
        അവസ്ഥ 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            എങ്കിൽ (j < nb_outputs || c == 'm') {
                എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    വേണ്ടി(reg = 0; reg < NB_ASM_REGS; reg++) {
                        എങ്കിൽ (!(regs_allocated[reg] & REG_IN_MASK))
                            പോകുക reg_found1;
                    }
                    പോകുക try_next;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            നിർത്തുക;
        }
        /* if a reference is present for that operand, we assign it too */
        എങ്കിൽ (op->നിവേശം_index >= 0) {
            operands[op->നിവേശം_index].reg = op->reg;
            operands[op->നിവേശം_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    വേണ്ടി(i=0;i<nb_operands;i++) {
        op = &operands[i];
        എങ്കിൽ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_memory) {
            വേണ്ടി(reg = 0; reg < NB_ASM_REGS; reg++) {
                എങ്കിൽ (!(regs_allocated[reg] & REG_OUT_MASK))
                    പോകുക reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            നിർത്തുക;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    വേണ്ടി(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ശൂന്യ) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    എങ്കിൽ (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC ശൂന്യം subst_asm_operand(CString *add_str,
                              SValue *sv, പൂർണ്ണസംഖ്യ modifier)
{
    പൂർണ്ണസംഖ്യ r, reg, size, val;

    r = sv->r;
    എങ്കിൽ ((r & VT_VALMASK) == VT_CONST) {
        എങ്കിൽ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(add_str, '$');
        എങ്കിൽ (r & VT_SYM) {
	    സ്ഥിരം അക്ഷരം *name = get_tok_str(sv->sym->v, ശൂന്യ);
	    എങ്കിൽ (sv->sym->v >= SYM_FIRST_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            എങ്കിൽ (tcc_state->leading_underscore)
              cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            എങ്കിൽ ((uint32_t)sv->c.i == 0)
                പോകുക no_offset;
	    cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        എങ്കിൽ (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
    no_offset:;
#ifdef TCC_TARGET_X86_64
        എങ്കിൽ (r & VT_LVAL)
            cstr_cat(add_str, "(%rip)", -1);
#endif
    } അല്ലെങ്കിൽ എങ്കിൽ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d(%%%s)", (പൂർണ്ണസംഖ്യ)sv->c.i, get_tok_str(TOK_ASM_xax + 5, ശൂന്യ));
    } അല്ലെങ്കിൽ എങ്കിൽ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        എങ്കിൽ (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, ശൂന്യ));
    } അല്ലെങ്കിൽ {
        /* register case */
        reg = r & VT_VALMASK;
        എങ്കിൽ (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        എങ്കിൽ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        അല്ലെങ്കിൽ എങ്കിൽ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
#ifdef TCC_TARGET_X86_64
        അല്ലെങ്കിൽ എങ്കിൽ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
#endif
        അല്ലെങ്കിൽ
            size = 4;
        എങ്കിൽ (size == 1 && reg >= 4)
            size = 4;

        എങ്കിൽ (modifier == 'b') {
            എങ്കിൽ (reg >= 4)
                tcc_error("cannot use byte register");
            size = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (modifier == 'h') {
            എങ്കിൽ (reg >= 4)
                tcc_error("cannot use byte register");
            size = -1;
        } അല്ലെങ്കിൽ എങ്കിൽ (modifier == 'w') {
            size = 2;
        } അല്ലെങ്കിൽ എങ്കിൽ (modifier == 'k') {
            size = 4;
#ifdef TCC_TARGET_X86_64
        } അല്ലെങ്കിൽ എങ്കിൽ (modifier == 'q') {
            size = 8;
#endif
        }

        എങ്കിൽ (reg >= 8) {
            cstr_printf(add_str, "%%r%d%c", reg, (size == 1) ? 'b' : ((size == 2) ? 'w' : ((size == 4) ? 'd' : ' ')));
            തിരികെ;
        }
        തിരഞ്ഞെടുപ്പ്(size) {
        അവസ്ഥ -1:
            reg = TOK_ASM_ah + reg;
            നിർത്തുക;
        അവസ്ഥ 1:
            reg = TOK_ASM_al + reg;
            നിർത്തുക;
        അവസ്ഥ 2:
            reg = TOK_ASM_ax + reg;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            reg = TOK_ASM_eax + reg;
            നിർത്തുക;
#ifdef TCC_TARGET_X86_64
        അവസ്ഥ 8:
            reg = TOK_ASM_rax + reg;
            നിർത്തുക;
#endif
        }
        cstr_printf(add_str, "%%%s", get_tok_str(reg, ശൂന്യ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ശൂന്യം asm_gen_code(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands,
                         പൂർണ്ണസംഖ്യ nb_outputs, പൂർണ്ണസംഖ്യ is_output,
                         uint8_t *clobber_regs,
                         പൂർണ്ണസംഖ്യ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    പൂർണ്ണസംഖ്യ i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    സ്ഥിതം സ്ഥിരം uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#അല്ലെങ്കിൽ
    സ്ഥിതം സ്ഥിരം uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#endif
#അല്ലെങ്കിൽ
    സ്ഥിതം സ്ഥിരം uint8_t reg_saved[] = { 3, 6, 7 };
#endif

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, വലുപ്പം(regs_allocated));
    വേണ്ടി(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        എങ്കിൽ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    എങ്കിൽ (!is_output) {
        /* generate reg save code */
        വേണ്ടി(i = 0; i < വലുപ്പം(reg_saved)/വലുപ്പം(reg_saved[0]); i++) {
            reg = reg_saved[i];
            എങ്കിൽ (regs_allocated[reg]) {
		എങ്കിൽ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        വേണ്ടി(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            എങ്കിൽ (op->reg >= 0) {
                എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } അല്ലെങ്കിൽ എങ്കിൽ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    load(op->reg, op->vt);
                    എങ്കിൽ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        load(TREG_XDX, &sv);
                    }
                }
            }
        }
    } അല്ലെങ്കിൽ {
        /* generate save code */
        വേണ്ടി(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            എങ്കിൽ (op->reg >= 0) {
                എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    എങ്കിൽ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        load(out_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } അല്ലെങ്കിൽ {
                    store(op->reg, op->vt);
                    എങ്കിൽ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        വേണ്ടി(i = വലുപ്പം(reg_saved)/വലുപ്പം(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            എങ്കിൽ (regs_allocated[reg]) {
		എങ്കിൽ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC ശൂന്യം asm_clobber(uint8_t *clobber_regs, സ്ഥിരം അക്ഷരം *str)
{
    പൂർണ്ണസംഖ്യ reg;
#ifdef TCC_TARGET_X86_64
    unsigned പൂർണ്ണസംഖ്യ type;
#endif

    എങ്കിൽ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        തിരികെ;
    reg = tok_alloc_const(str);
    എങ്കിൽ (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } അല്ലെങ്കിൽ എങ്കിൽ (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#ifdef TCC_TARGET_X86_64
    } അല്ലെങ്കിൽ എങ്കിൽ (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } അല്ലെങ്കിൽ എങ്കിൽ ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#endif
    } അല്ലെങ്കിൽ {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
