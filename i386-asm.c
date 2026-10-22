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
#अन्तर्भाव "tcc.h"

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
#अन्यथा
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#endif

#define OPC_GROUP_SHIFT 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
गणना {
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
    OPT_REG8_खालचा, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
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
# define OP_REG8_खालचा (1 << OPT_REG8_खालचा)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#अन्यथा
# define OP_REG64 0
# define OP_REG8_खालचा 0
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
#अन्यथा
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#endif

प्रकारनिर्देश संरचना ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

प्रकारनिर्देश संरचना Operand {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t shift;
    अभिव्यक्ती_मूल्य e;
} Operand;

स्थिर ध्रुव uint8_t reg_to_size[9] = {
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

स्थिर ध्रुव uint8_t test_bits[NB_TEST_OPCODES] = {
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

स्थिर ध्रुव uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

स्थिर ध्रुव ASMInstr asm_instrs[] = {
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
#अन्यथा
# include "i386-asm.h"
#endif
    /* last operation */
    { 0, },
};

स्थिर ध्रुव uint16_t op0_codes[] = {
#define ALT(x)
#define DEF_ASM_OP0(x, opcode) opcode,
#define DEF_ASM_OP0L(name, opcode, group, instr_type)
#define DEF_ASM_OP1(name, opcode, group, instr_type, op0)
#define DEF_ASM_OP2(name, opcode, group, instr_type, op0, op1)
#define DEF_ASM_OP3(name, opcode, group, instr_type, op0, op1, op2)
#ifdef TCC_TARGET_X86_64
# include "x86_64-asm.h"
#अन्यथा
# include "i386-asm.h"
#endif
};

स्थिर अन्तःस्थ पूर्णाङ्क get_reg_shift(TCCState *s1)
{
    पूर्णाङ्क shift, v;
    v = asm_int_अभिव्यक्ती(s1);
    विकल्प(v) {
    पक्ष 1:
        shift = 0;
        भङ्ग;
    पक्ष 2:
        shift = 1;
        भङ्ग;
    पक्ष 4:
        shift = 2;
        भङ्ग;
    पक्ष 8:
        shift = 3;
        भङ्ग;
    स्वभाव:
        expect("1, 2, 4 or 8 constant");
        shift = 0;
        भङ्ग;
    }
    प्रत्यागम shift;
}

#ifdef TCC_TARGET_X86_64
स्थिर पूर्णाङ्क asm_parse_numeric_reg(पूर्णाङ्क t, unsigned पूर्णाङ्क *type)
{
    पूर्णाङ्क reg = -1;
    यदि (t >= TOK_IDENT && t < tok_ident) {
	ध्रुव वर्ण *s = table_ident[t - TOK_IDENT]->str;
	वर्ण c;
	*type = OP_REG64;
	यदि (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	यदि (*s++ != 'r')
	  प्रत्यागम -1;
	/* Don't allow leading '0'.  */
	यदि ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	अन्यथा
	  प्रत्यागम -1;
	यदि ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	यदि (reg > 15)
	  प्रत्यागम -1;
	यदि ((c = *s) == 0)
	  ;
	अन्यथा यदि (*type != OP_REG64)
	  प्रत्यागम -1;
	अन्यथा यदि (c == 'b' && !s[1])
	  *type = OP_REG8;
	अन्यथा यदि (c == 'w' && !s[1])
	  *type = OP_REG16;
	अन्यथा यदि (c == 'd' && !s[1])
	  *type = OP_REG32;
	अन्यथा
	  प्रत्यागम -1;
    }
    प्रत्यागम reg;
}
#endif

स्थिर पूर्णाङ्क asm_parse_reg(unsigned पूर्णाङ्क *type)
{
    पूर्णाङ्क reg = 0;
    *type = 0;
    यदि (tok != '%')
        गच्छ error_32;
    next();
    यदि (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#ifdef TCC_TARGET_X86_64
    } अन्यथा यदि (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } अन्यथा यदि (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } अन्यथा यदि ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#endif
    } अन्यथा {
    error_32:
        expect("register");
    }
    next();
    प्रत्यागम reg;
}

स्थिर शून्य parse_operand(TCCState *s1, Operand *op)
{
    अभिव्यक्ती_मूल्य e;
    पूर्णाङ्क reg, indir;
    ध्रुव वर्ण *p;

    indir = 0;
    यदि (tok == '*') {
        next();
        indir = OP_INDIR;
    }

    यदि (tok == '%') {
        next();
        यदि (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            यदि ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            अन्यथा यदि (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            अन्यथा यदि (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } अन्यथा यदि (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } अन्यथा यदि (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } अन्यथा यदि (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            next();
            यदि (tok == '(') {
                next();
                यदि (tok != TOK_PPNUM)
                    गच्छ reg_error;
                p = tokc.str.data;
                reg = p[0] - '0';
                यदि ((unsigned)reg >= 8 || p[1] != '\0')
                    गच्छ reg_error;
                op->reg = reg;
                next();
                skip(')');
            }
            यदि (op->reg == 0)
                op->type |= OP_ST0;
            गच्छ no_skip;
#ifdef TCC_TARGET_X86_64
	} अन्यथा यदि (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_खालचा;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } अन्यथा यदि ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#endif
        } अन्यथा {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        next();
    no_skip: ;
    } अन्यथा यदि (tok == '$') {
        /* constant value */
        next();
        asm_अभिव्यक्ती(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        यदि (!op->e.sym) {
            यदि (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            यदि (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            यदि (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#ifdef TCC_TARGET_X86_64
            यदि (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#endif
        }
    } अन्यथा {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->shift = 0;
        यदि (tok != '(') {
            asm_अभिव्यक्ती(s1, &e);
            op->e = e;
        } अन्यथा {
            next();
            यदि (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = रिक्त;
            } अन्यथा {
                /* bracketed offset expression */
                asm_अभिव्यक्ती(s1, &e);
                यदि (tok != ')')
                    expect(")");
                next();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        यदि (tok == '(') {
	    unsigned पूर्णाङ्क type = 0;
            next();
            यदि (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            यदि (tok == ',') {
                next();
                यदि (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                यदि (tok == ',') {
                    next();
                    op->shift = get_reg_shift(s1);
                }
            }
	    यदि (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        यदि (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC शून्य gen_expr32(अभिव्यक्ती_मूल्य *pe)
{
    यदि (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    अन्यथा
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
स्थिर शून्य gen_disp32(अभिव्यक्ती_मूल्य *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    यदि (esym && esym->st_shndx == cur_text_section->sh_अंक) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_मूल्य - ind - 4);
    } अन्यथा {
        यदि (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = रिक्त;
        }
#ifdef TCC_TARGET_X86_64
        greloca(cur_text_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#अन्यथा
        gen_addrpc32(VT_SYM, sym, pe->v);
#endif

    }
}

/* generate the modrm operand */
स्थिर अन्तःस्थ पूर्णाङ्क asm_modrm(पूर्णाङ्क reg, Operand *op)
{
    पूर्णाङ्क mod, reg1, reg2, sib_reg1;

    यदि (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } अन्यथा यदि (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#ifdef TCC_TARGET_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#अन्यथा
	g(0x05 + (reg << 3));
#endif
	gen_expr32(&op->e);
#ifdef TCC_TARGET_X86_64
    } अन्यथा यदि (op->reg == -2) {
        अभिव्यक्ती_मूल्य *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        प्रत्यागम ind;
#endif
    } अन्यथा {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        यदि (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } अन्यथा यदि (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } अन्यथा यदि (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } अन्यथा {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        यदि (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        यदि (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            यदि (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->shift << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        यदि (mod == 0x40) {
            g(op->e.v);
        } अन्यथा यदि (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    प्रत्यागम 0;
}

#ifdef TCC_TARGET_X86_64
#define REX_W 0x48
#define REX_R 0x44
#define REX_X 0x42
#define REX_B 0x41

स्थिर शून्य asm_rex(पूर्णाङ्क width64, Operand *ops, पूर्णाङ्क nb_ops, पूर्णाङ्क *op_type,
		    पूर्णाङ्क regi, पूर्णाङ्क rmi)
{
  unsigned वर्ण rex = width64 ? 0x48 : 0;
  पूर्णाङ्क saw_वरचा_8bit = 0;
  पूर्णाङ्क i;
  यदि (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      प्रति(i = 0; i < nb_ops; i++) {
	  यदि (op_type[i] & (OP_REG | OP_ST)) {
	      यदि (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } अन्यथा यदि (ops[i].type & OP_REG8_खालचा)
		  rex |= 0x40;
	      अन्यथा यदि (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_वरचा_8bit = ops[i].reg;
	      भङ्ग;
	  }
      }
  } अन्यथा {
      यदि (regi != -1) {
	  यदि (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } अन्यथा यदि (ops[regi].type & OP_REG8_खालचा)
	      rex |= 0x40;
	  अन्यथा यदि (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_वरचा_8bit = ops[regi].reg;
      }
      यदि (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  यदि (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } अन्यथा यदि (ops[rmi].type & OP_REG8_खालचा)
	      rex |= 0x40;
	  अन्यथा यदि (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_वरचा_8bit = ops[rmi].reg;
      }
      यदि (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  यदि (rex) {
      यदि (saw_वरचा_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_वरचा_8bit-4]);
      g(rex);
  }
}
#endif


स्थिर शून्य maybe_print_stats (शून्य)
{
    स्थिर पूर्णाङ्क already;

    यदि (0 && !already)
    /* print stats about opcodes */
    {
        ध्रुव संरचना ASMInstr *pa;
        पूर्णाङ्क freq[4];
        पूर्णाङ्क op_vals[500];
        पूर्णाङ्क nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, परिमाण(freq));
        प्रति(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                प्रति(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    यदि (pa->instr_type == op_vals[j])
                        गच्छ found;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            found: ;
            //}
        }
        प्रति(i=0;i<nb_op_vals;i++) {
            पूर्णाङ्क v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                printf("%3d: %08x\n", i, v);
        }
        printf("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (पूर्णाङ्क)परिमाण(asm_instrs),
	       (पूर्णाङ्क)परिमाण(asm_instrs) / (पूर्णाङ्क)परिमाण(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC शून्य asm_opcode(TCCState *s1, पूर्णाङ्क opcode)
{
    ध्रुव ASMInstr *pa;
    पूर्णाङ्क i, modrm_index, modreg_index, reg, v, op1, seg_prefix, pc, p;
    पूर्णाङ्क nb_ops, s;
    Operand ops[MAX_OPERANDS], *काढा;
    पूर्णाङ्क op_type[3]; /* decoded op type */
    पूर्णाङ्क alltypes;   /* OR of all operand types */
    पूर्णाङ्क autosize;
    पूर्णाङ्क p66;
#ifdef TCC_TARGET_X86_64
    पूर्णाङ्क rex64;
#endif

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    यदि (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    काढा = ops;
    nb_ops = 0;
    seg_prefix = 0;
    alltypes = 0;
    प्रति(;;) {
        यदि (tok == ';' || tok == TOK_LINEFEED)
            भङ्ग;
        यदि (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_operand(s1, काढा);
        यदि (tok == ':') {
           यदि (!(काढा->type & OP_SEG) || seg_prefix)
               tcc_error("incorrect prefix");
           seg_prefix = segment_prefixes[काढा->reg];
           next();
           parse_operand(s1, काढा);
           यदि (!(काढा->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        काढा++;
        nb_ops++;
        यदि (tok != ',')
            भङ्ग;
        next();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    प्रति(pa = asm_instrs; pa->sym != 0; pa++) {
	पूर्णाङ्क it = pa->instr_type & OPCT_MASK;
        s = 0;
        यदि (it == OPC_FARITH) {
            v = opcode - pa->sym;
            यदि (!((unsigned)v < 8 * 6 && (v % 6) == 0))
                अनुवर्त;
        } अन्यथा यदि (it == OPC_ARITH) {
            यदि (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                अनुवर्त;
            s = (opcode - pa->sym) % NBWLX;
	    यदि ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		यदि (((opcode - pa->sym + 1) % NBWLX) == 0)
		    अनुवर्त;
	        s++;
	      }
        } अन्यथा यदि (it == OPC_SHIFT) {
            यदि (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                अनुवर्त;
            s = (opcode - pa->sym) % NBWLX;
        } अन्यथा यदि (it == OPC_TEST) {
            यदि (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                अनुवर्त;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    यदि (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } अन्यथा यदि (pa->instr_type & OPC_B) {
#ifdef TCC_TARGET_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    यदि ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        अनुवर्त;
#endif
            यदि (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                अनुवर्त;
            s = opcode - pa->sym;
        } अन्यथा यदि (pa->instr_type & OPC_WLX) {
            यदि (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                अनुवर्त;
            s = opcode - pa->sym + 1;
        } अन्यथा {
            यदि (pa->sym != opcode)
                अनुवर्त;
        }
        यदि (pa->nb_ops != nb_ops)
            अनुवर्त;
#ifdef TCC_TARGET_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	यदि (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    अनुवर्त;
#endif
        /* now decode and check each operand */
	alltypes = 0;
        प्रति(i = 0; i < nb_ops; i++) {
            पूर्णाङ्क op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            विकल्प(op2) {
            पक्ष OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                भङ्ग;
            पक्ष OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                भङ्ग;
            पक्ष OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                भङ्ग;
            पक्ष OPT_IMW:
                v = OP_IM16 | OP_IM32;
                भङ्ग;
	    पक्ष OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		भङ्ग;
	    पक्ष OPT_DISP:
	    पक्ष OPT_DISP8:
		v = OP_ADDR;
		भङ्ग;
            स्वभाव:
                v = 1 << op2;
                भङ्ग;
            }
            यदि (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            यदि ((ops[i].type & v) == 0)
                गच्छ next;
	    alltypes |= ops[i].type;
        }
        (शून्य)alltypes; /* maybe unused */
        /* all is matching ! */
        भङ्ग;
    next: ;
    }
    यदि (pa->sym == 0) {
        यदि (opcode >= TOK_ASM_first && opcode <= TOK_ASM_last) {
            पूर्णाङ्क b;
            b = op0_codes[opcode - TOK_ASM_first];
            यदि (b & 0xff00)
                g(b >> 8);
            g(b);
            प्रत्यागम;
        } अन्यथा यदि (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, रिक्त));
        } अन्यथा {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = table_ident[opcode - TOK_IDENT];
	    यदि (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		गच्छ again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#ifdef TCC_TARGET_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    यदि ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#endif
    यदि (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        प्रति(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            यदि ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_to_size[ops[i].type & OP_REG];
        }
        यदि (s == autosize) {
            यदि ((opcode == TOK_ASM_ढकला || opcode == TOK_ASM_काढा) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    अन्यथा यदि ((opcode == TOK_ASM_ढकला || opcode == TOK_ASM_काढा) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            अन्यथा
                tcc_error("cannot infer opcode suffix");
        }
    }

#ifdef TCC_TARGET_X86_64
    rex64 = 0;
    यदि (pa->instr_type & OPC_48)
        rex64 = 1;
    अन्यथा यदि (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	पूर्णाङ्क default64 = 0;
	प्रति(i = 0; i < nb_ops; i++) {
	    यदि (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		भङ्ग;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        यदि (((opcode != TOK_ASM_ढकला && opcode != TOK_ASM_काढा
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#endif

    /* now generates the operation */
    यदि (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    यदि (seg_prefix)
        g(seg_prefix);
#ifdef TCC_TARGET_X86_64
    /* Generate addr32 prefix if needed */
    प्रति(i = 0; i < nb_ops; i++) {
        यदि (ops[i].type & OP_EA32) {
	    g(0x67);
	    भङ्ग;
        }
    }
#endif
    /* generate data16 prefix if needed */
    p66 = 0;
    यदि (s == 1)
        p66 = 1;
    अन्यथा {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        प्रति (i = 0; i < nb_ops; i++)
            यदि ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    यदि (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    विकल्प (p) {
        पक्ष 0: भङ्ग;  /* no prefix */
        पक्ष 0x48: भङ्ग; /* REX, handled elsewhere */
        पक्ष 0x66:
        पक्ष 0x67:
        पक्ष 0xf2:
        पक्ष 0xf3: v = v & 0xff; g(p); भङ्ग;
        पक्ष 0xd4: पक्ष 0xd5: भङ्ग; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        पक्ष 0xd8: पक्ष 0xd9: पक्ष 0xda: पक्ष 0xdb: /* x87, no normal prefix */
        पक्ष 0xdc: पक्ष 0xdd: पक्ष 0xde: पक्ष 0xdf: भङ्ग;
        स्वभाव: tcc_error("bad prefix 0x%2x in opcode table", p); भङ्ग;
    }
    यदि (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    यदि ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } अन्यथा यदि (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } अन्यथा यदि ((v == 0x06 || v == 0x07)) {
        यदि (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } अन्यथा {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } अन्यथा यदि (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } अन्यथा यदि ((pa->instr_type & (OPCT_MASK | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_index = -1;
    modreg_index = -1;
    यदि (pa->instr_type & OPC_MODRM) {
	यदि (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#ifdef TCC_TARGET_X86_64
	    यदि (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    अन्यथा यदि (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#अन्यथा
	    यदि (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#endif
	    अन्यथा
	      tcc_error("bad MODR/M opcode without operands");
	    गच्छ modrm_found;
	}
        /* first look for an ea operand */
        प्रति(i = 0;i < nb_ops; i++) {
            यदि (op_type[i] & OP_EA)
                गच्छ modrm_found;
        }
        /* then if not found, a register or indirection (shift instructions) */
        प्रति(i = 0;i < nb_ops; i++) {
            यदि (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                गच्छ modrm_found;
        }
#ifdef ASM_DEBUG
        tcc_error("bad op table");
#endif
    modrm_found:
        modrm_index = i;
        /* if a register is used in another operand then it is
           used instead of group */
        प्रति(i = 0;i < nb_ops; i++) {
            पूर्णाङ्क t = op_type[i];
            यदि (i != modrm_index &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_index = i;
                भङ्ग;
            }
        }
    }
#ifdef TCC_TARGET_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_index, modrm_index);
#endif

    यदि (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        यदि (v == 0xb0 && s >= 1)
            v += 7;
        प्रति(i = 0; i < nb_ops; i++) {
            यदि (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                भङ्ग;
            }
        }
    }
    यदि (pa->instr_type & OPC_B)
        v += s >= 1;
    यदि (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        पूर्णाङ्क jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        यदि (!esym || esym->st_shndx != cur_text_section->sh_अंक)
            गच्छ no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_मूल्य - ind - 2 - (v >= 0xff);
        यदि (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } अन्यथा {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    यदि (v == 0xeb) /* jmp */
	        v = 0xe9;
	    अन्यथा यदि (v == 0x70) /* jcc */
	        v += 0x0f10;
	    अन्यथा
	        tcc_error("invalid displacement");
        }
    }
    यदि (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_bits[opcode - pa->sym];
    अन्यथा यदि (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    यदि (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    यदि (op1)
        g(op1);
    g(v);

    यदि (OPCT_IS(pa->instr_type, OPC_SHIFT)) {
        reg = (opcode - pa->sym) / NBWLX;
        यदि (reg == 6)
            reg = 7;
    } अन्यथा यदि (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } अन्यथा यदि (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } अन्यथा {
        reg = (pa->instr_type >> OPC_GROUP_SHIFT) & 7;
    }

    pc = 0;
    यदि (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	यदि (modreg_index >= 0)
	    reg = ops[modreg_index].reg;
        pc = asm_modrm(reg, &ops[modrm_index]);
    }

    /* emit constants */
#ifndef TCC_TARGET_X86_64
    यदि (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        यदि (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        प्रत्यागम;
    }
#endif
    प्रति(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        यदि (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            यदि ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                यदि (s == 0)
                    v = OP_IM8;
                अन्यथा यदि (s == 1)
                    v = OP_IM16;
                अन्यथा यदि (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                अन्यथा
                    v = OP_IM64;
            }

            यदि ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            यदि (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } अन्यथा यदि (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#ifdef TCC_TARGET_X86_64
            } अन्यथा यदि (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#endif
	    } अन्यथा यदि (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } अन्यथा {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    यदि (pc)
        add32le(cur_text_section->data + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
स्थिर अन्तःस्थ पूर्णाङ्क constraint_priority(ध्रुव वर्ण *str)
{
    पूर्णाङ्क priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    प्रति(;;) {
        c = *str;
        यदि (c == '\0')
            भङ्ग;
        str++;
        विकल्प(c) {
        पक्ष 'A':
            pr = 0;
            भङ्ग;
        पक्ष 'a':
        पक्ष 'b':
        पक्ष 'c':
        पक्ष 'd':
        पक्ष 'S':
        पक्ष 'D':
            pr = 1;
            भङ्ग;
        पक्ष 'q':
            pr = 2;
            भङ्ग;
        पक्ष 'r':
	पक्ष 'R':
	पक्ष 'p':
            pr = 3;
            भङ्ग;
        पक्ष 'N':
        पक्ष 'M':
        पक्ष 'I':
	पक्ष 'e':
        पक्ष 'i':
        पक्ष 'm':
        पक्ष 'g':
            pr = 4;
            भङ्ग;
        स्वभाव:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        यदि (pr > priority)
            priority = pr;
    }
    प्रत्यागम priority;
}

स्थिर ध्रुव वर्ण *skip_constraint_modifiers(ध्रुव वर्ण *p)
{
    यावत् (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    प्रत्यागम p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC पूर्णाङ्क asm_parse_regvar (पूर्णाङ्क t)
{
    ध्रुव वर्ण *s;
    Operand op;
    यदि (t < TOK_IDENT || (t & SYM_FIELD))
        प्रत्यागम -1;
    s = table_ident[t - TOK_IDENT]->str;
    यदि (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_operand(tcc_state, &op);
    /* Accept only integer regs for now. */
    यदि (op.type & OP_REG)
        प्रत्यागम op.reg;
    अन्यथा
        प्रत्यागम -1;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC शून्य asm_compute_constraints(ASMOperand *operands,
                                    पूर्णाङ्क nb_operands, पूर्णाङ्क nb_outputs,
                                    ध्रुव uint8_t *clobber_regs,
                                    पूर्णाङ्क *pout_reg)
{
    ASMOperand *op;
    पूर्णाङ्क sorted_op[MAX_ASM_OPERANDS];
    पूर्णाङ्क i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ध्रुव वर्ण *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    प्रति(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->आदान_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    प्रति(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        यदि (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, रिक्त);
            यदि ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_index = k;
            यदि (operands[k].आदान_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].आदान_index = i;
            op->priority = 5;
	} अन्यथा यदि ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->priority = 1;
	    op->reg = reg;
        } अन्यथा {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    प्रति(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    प्रति(i=0;i<nb_operands - 1;i++) {
        प्रति(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            यदि (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    प्रति(i = 0;i < NB_ASM_REGS; i++) {
        यदि (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        अन्यथा
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_IN_MASK | REG_OUT_MASK;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    प्रति(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        यदि (op->ref_index >= 0)
            अनुवर्त;
        /* select if register is used for output, input or both */
        यदि (op->आदान_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अन्यथा यदि (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अन्यथा {
            reg_mask = REG_IN_MASK;
        }
	यदि (op->reg >= 0) {
	    यदि (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_next:
        c = *str++;
        विकल्प(c) {
        पक्ष '=':
            गच्छ try_next;
        पक्ष '+':
            op->is_rw = 1;
            /* FALL THRU */
        पक्ष '&':
            यदि (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            गच्छ try_next;
        पक्ष 'A':
            /* allocate both eax and edx */
            यदि (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                गच्छ try_next;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_mask;
            regs_allocated[TREG_XDX] |= reg_mask;
            भङ्ग;
        पक्ष 'a':
            reg = TREG_XAX;
            गच्छ alloc_reg;
        पक्ष 'b':
            reg = 3;
            गच्छ alloc_reg;
        पक्ष 'c':
            reg = TREG_XCX;
            गच्छ alloc_reg;
        पक्ष 'd':
            reg = TREG_XDX;
            गच्छ alloc_reg;
        पक्ष 'S':
            reg = 6;
            गच्छ alloc_reg;
        पक्ष 'D':
            reg = 7;
        alloc_reg:
            यदि (op->reg >= 0 && reg != op->reg)
                गच्छ try_next;
            यदि (is_reg_allocated(reg))
                गच्छ try_next;
            गच्छ reg_found;
        पक्ष 'q':
            /* eax, ebx, ecx or edx */
            यदि (op->reg >= 0) {
                यदि ((reg = op->reg) < 4)
                    गच्छ reg_found;
            } अन्यथा प्रति(reg = 0; reg < 4; reg++) {
                यदि (!is_reg_allocated(reg))
                    गच्छ reg_found;
            }
            गच्छ try_next;
        पक्ष 'r':
	पक्ष 'R':
	पक्ष 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            यदि ((reg = op->reg) >= 0)
                गच्छ reg_found;
            अन्यथा प्रति(reg = 0; reg < NB_ASM_REGS; reg++) {
                यदि (!is_reg_allocated(reg))
                    गच्छ reg_found;
            }
            गच्छ try_next;
        reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            भङ्ग;
	पक्ष 'e':
        पक्ष 'i':
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'I':
        पक्ष 'N':
        पक्ष 'M':
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'm':
        पक्ष 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            यदि (j < nb_outputs || c == 'm') {
                यदि ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    प्रति(reg = 0; reg < NB_ASM_REGS; reg++) {
                        यदि (!(regs_allocated[reg] & REG_IN_MASK))
                            गच्छ reg_found1;
                    }
                    गच्छ try_next;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            भङ्ग;
        स्वभाव:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            भङ्ग;
        }
        /* if a reference is present for that operand, we assign it too */
        यदि (op->आदान_index >= 0) {
            operands[op->आदान_index].reg = op->reg;
            operands[op->आदान_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    प्रति(i=0;i<nb_operands;i++) {
        op = &operands[i];
        यदि (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_memory) {
            प्रति(reg = 0; reg < NB_ASM_REGS; reg++) {
                यदि (!(regs_allocated[reg] & REG_OUT_MASK))
                    गच्छ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            भङ्ग;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    प्रति(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, रिक्त) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    यदि (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC शून्य subst_asm_operand(CString *add_str,
                              SValue *sv, पूर्णाङ्क modifier)
{
    पूर्णाङ्क r, reg, size, val;

    r = sv->r;
    यदि ((r & VT_VALMASK) == VT_CONST) {
        यदि (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(add_str, '$');
        यदि (r & VT_SYM) {
	    ध्रुव वर्ण *name = get_tok_str(sv->sym->v, रिक्त);
	    यदि (sv->sym->v >= SYM_FIRST_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            यदि (tcc_state->leading_underscore)
              cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            यदि ((uint32_t)sv->c.i == 0)
                गच्छ no_offset;
	    cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        यदि (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
    no_offset:;
#ifdef TCC_TARGET_X86_64
        यदि (r & VT_LVAL)
            cstr_cat(add_str, "(%rip)", -1);
#endif
    } अन्यथा यदि ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d(%%%s)", (पूर्णाङ्क)sv->c.i, get_tok_str(TOK_ASM_xax + 5, रिक्त));
    } अन्यथा यदि (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        यदि (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, रिक्त));
    } अन्यथा {
        /* register case */
        reg = r & VT_VALMASK;
        यदि (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        यदि ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        अन्यथा यदि ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
#ifdef TCC_TARGET_X86_64
        अन्यथा यदि ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
#endif
        अन्यथा
            size = 4;
        यदि (size == 1 && reg >= 4)
            size = 4;

        यदि (modifier == 'b') {
            यदि (reg >= 4)
                tcc_error("cannot use byte register");
            size = 1;
        } अन्यथा यदि (modifier == 'h') {
            यदि (reg >= 4)
                tcc_error("cannot use byte register");
            size = -1;
        } अन्यथा यदि (modifier == 'w') {
            size = 2;
        } अन्यथा यदि (modifier == 'k') {
            size = 4;
#ifdef TCC_TARGET_X86_64
        } अन्यथा यदि (modifier == 'q') {
            size = 8;
#endif
        }

        यदि (reg >= 8) {
            cstr_printf(add_str, "%%r%d%c", reg, (size == 1) ? 'b' : ((size == 2) ? 'w' : ((size == 4) ? 'd' : ' ')));
            प्रत्यागम;
        }
        विकल्प(size) {
        पक्ष -1:
            reg = TOK_ASM_ah + reg;
            भङ्ग;
        पक्ष 1:
            reg = TOK_ASM_al + reg;
            भङ्ग;
        पक्ष 2:
            reg = TOK_ASM_ax + reg;
            भङ्ग;
        स्वभाव:
            reg = TOK_ASM_eax + reg;
            भङ्ग;
#ifdef TCC_TARGET_X86_64
        पक्ष 8:
            reg = TOK_ASM_rax + reg;
            भङ्ग;
#endif
        }
        cstr_printf(add_str, "%%%s", get_tok_str(reg, रिक्त));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC शून्य asm_gen_code(ASMOperand *operands, पूर्णाङ्क nb_operands,
                         पूर्णाङ्क nb_outputs, पूर्णाङ्क is_output,
                         uint8_t *clobber_regs,
                         पूर्णाङ्क out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    पूर्णाङ्क i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    स्थिर ध्रुव uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#अन्यथा
    स्थिर ध्रुव uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#endif
#अन्यथा
    स्थिर ध्रुव uint8_t reg_saved[] = { 3, 6, 7 };
#endif

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, परिमाण(regs_allocated));
    प्रति(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        यदि (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    यदि (!is_output) {
        /* generate reg save code */
        प्रति(i = 0; i < परिमाण(reg_saved)/परिमाण(reg_saved[0]); i++) {
            reg = reg_saved[i];
            यदि (regs_allocated[reg]) {
		यदि (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        प्रति(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            यदि (op->reg >= 0) {
                यदि ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } अन्यथा यदि (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    load(op->reg, op->vt);
                    यदि (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        load(TREG_XDX, &sv);
                    }
                }
            }
        }
    } अन्यथा {
        /* generate save code */
        प्रति(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            यदि (op->reg >= 0) {
                यदि ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    यदि (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        load(out_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } अन्यथा {
                    store(op->reg, op->vt);
                    यदि (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        प्रति(i = परिमाण(reg_saved)/परिमाण(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            यदि (regs_allocated[reg]) {
		यदि (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC शून्य asm_clobber(uint8_t *clobber_regs, ध्रुव वर्ण *str)
{
    पूर्णाङ्क reg;
#ifdef TCC_TARGET_X86_64
    unsigned पूर्णाङ्क type;
#endif

    यदि (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        प्रत्यागम;
    reg = tok_alloc_const(str);
    यदि (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } अन्यथा यदि (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#ifdef TCC_TARGET_X86_64
    } अन्यथा यदि (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } अन्यथा यदि ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#endif
    } अन्यथा {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
