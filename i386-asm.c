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
#அந்தர்பாவ "tcc.h"

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
#இல்லையெனில்
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#endif

#define OPC_GROUP_SHIFT 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
எண்ணிக்கை {
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
    OPT_REG8_கீழ், /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
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
# define OP_REG8_கீழ் (1 << OPT_REG8_கீழ்)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#இல்லையெனில்
# define OP_REG64 0
# define OP_REG8_கீழ் 0
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
#இல்லையெனில்
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#endif

வகைவரை கட்டமைப்பு ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

வகைவரை கட்டமைப்பு Operand {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t shift;
    கோவை_மதிப்பு e;
} Operand;

நிலையான மாறிலி uint8_t reg_to_size[9] = {
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

நிலையான மாறிலி uint8_t test_bits[NB_TEST_OPCODES] = {
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

நிலையான மாறிலி uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

நிலையான மாறிலி ASMInstr asm_instrs[] = {
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
#இல்லையெனில்
# include "i386-asm.h"
#endif
    /* last operation */
    { 0, },
};

நிலையான மாறிலி uint16_t op0_codes[] = {
#define ALT(x)
#define DEF_ASM_OP0(x, opcode) opcode,
#define DEF_ASM_OP0L(name, opcode, group, instr_type)
#define DEF_ASM_OP1(name, opcode, group, instr_type, op0)
#define DEF_ASM_OP2(name, opcode, group, instr_type, op0, op1)
#define DEF_ASM_OP3(name, opcode, group, instr_type, op0, op1, op2)
#ifdef TCC_TARGET_X86_64
# include "x86_64-asm.h"
#இல்லையெனில்
# include "i386-asm.h"
#endif
};

நிலையான உள்வரி முழு get_reg_shift(TCCState *s1)
{
    முழு shift, v;
    v = asm_int_கோவை(s1);
    தேர்வு(v) {
    நிலை 1:
        shift = 0;
        நிறுத்து;
    நிலை 2:
        shift = 1;
        நிறுத்து;
    நிலை 4:
        shift = 2;
        நிறுத்து;
    நிலை 8:
        shift = 3;
        நிறுத்து;
    இயல்பு:
        expect("1, 2, 4 or 8 constant");
        shift = 0;
        நிறுத்து;
    }
    திரும்பு shift;
}

#ifdef TCC_TARGET_X86_64
நிலையான முழு asm_parse_numeric_reg(முழு t, unsigned முழு *type)
{
    முழு reg = -1;
    எனில் (t >= TOK_IDENT && t < tok_ident) {
	மாறிலி எழுத்து *s = table_ident[t - TOK_IDENT]->str;
	எழுத்து c;
	*type = OP_REG64;
	எனில் (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	எனில் (*s++ != 'r')
	  திரும்பு -1;
	/* Don't allow leading '0'.  */
	எனில் ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	இல்லையெனில்
	  திரும்பு -1;
	எனில் ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	எனில் (reg > 15)
	  திரும்பு -1;
	எனில் ((c = *s) == 0)
	  ;
	இல்லையெனில் எனில் (*type != OP_REG64)
	  திரும்பு -1;
	இல்லையெனில் எனில் (c == 'b' && !s[1])
	  *type = OP_REG8;
	இல்லையெனில் எனில் (c == 'w' && !s[1])
	  *type = OP_REG16;
	இல்லையெனில் எனில் (c == 'd' && !s[1])
	  *type = OP_REG32;
	இல்லையெனில்
	  திரும்பு -1;
    }
    திரும்பு reg;
}
#endif

நிலையான முழு asm_parse_reg(unsigned முழு *type)
{
    முழு reg = 0;
    *type = 0;
    எனில் (tok != '%')
        செல் error_32;
    next();
    எனில் (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#ifdef TCC_TARGET_X86_64
    } இல்லையெனில் எனில் (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } இல்லையெனில் எனில் (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } இல்லையெனில் எனில் ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#endif
    } இல்லையெனில் {
    error_32:
        expect("register");
    }
    next();
    திரும்பு reg;
}

நிலையான வெறுமை parse_operand(TCCState *s1, Operand *op)
{
    கோவை_மதிப்பு e;
    முழு reg, indir;
    மாறிலி எழுத்து *p;

    indir = 0;
    எனில் (tok == '*') {
        next();
        indir = OP_INDIR;
    }

    எனில் (tok == '%') {
        next();
        எனில் (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            எனில் ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            இல்லையெனில் எனில் (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            இல்லையெனில் எனில் (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } இல்லையெனில் எனில் (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } இல்லையெனில் எனில் (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } இல்லையெனில் எனில் (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            next();
            எனில் (tok == '(') {
                next();
                எனில் (tok != TOK_PPNUM)
                    செல் reg_error;
                p = tokc.str.data;
                reg = p[0] - '0';
                எனில் ((unsigned)reg >= 8 || p[1] != '\0')
                    செல் reg_error;
                op->reg = reg;
                next();
                skip(')');
            }
            எனில் (op->reg == 0)
                op->type |= OP_ST0;
            செல் no_skip;
#ifdef TCC_TARGET_X86_64
	} இல்லையெனில் எனில் (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_கீழ்;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } இல்லையெனில் எனில் ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#endif
        } இல்லையெனில் {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        next();
    no_skip: ;
    } இல்லையெனில் எனில் (tok == '$') {
        /* constant value */
        next();
        asm_கோவை(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        எனில் (!op->e.sym) {
            எனில் (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            எனில் (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            எனில் (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#ifdef TCC_TARGET_X86_64
            எனில் (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#endif
        }
    } இல்லையெனில் {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->shift = 0;
        எனில் (tok != '(') {
            asm_கோவை(s1, &e);
            op->e = e;
        } இல்லையெனில் {
            next();
            எனில் (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = வெற்று;
            } இல்லையெனில் {
                /* bracketed offset expression */
                asm_கோவை(s1, &e);
                எனில் (tok != ')')
                    expect(")");
                next();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        எனில் (tok == '(') {
	    unsigned முழு type = 0;
            next();
            எனில் (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            எனில் (tok == ',') {
                next();
                எனில் (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                எனில் (tok == ',') {
                    next();
                    op->shift = get_reg_shift(s1);
                }
            }
	    எனில் (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        எனில் (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC வெறுமை gen_expr32(கோவை_மதிப்பு *pe)
{
    எனில் (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    இல்லையெனில்
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
நிலையான வெறுமை gen_disp32(கோவை_மதிப்பு *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    எனில் (esym && esym->st_shndx == cur_text_section->sh_இலக்கம்) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_மதிப்பு - ind - 4);
    } இல்லையெனில் {
        எனில் (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = வெற்று;
        }
#ifdef TCC_TARGET_X86_64
        greloca(cur_text_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#இல்லையெனில்
        gen_addrpc32(VT_SYM, sym, pe->v);
#endif

    }
}

/* generate the modrm operand */
நிலையான உள்வரி முழு asm_modrm(முழு reg, Operand *op)
{
    முழு mod, reg1, reg2, sib_reg1;

    எனில் (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } இல்லையெனில் எனில் (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#ifdef TCC_TARGET_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#இல்லையெனில்
	g(0x05 + (reg << 3));
#endif
	gen_expr32(&op->e);
#ifdef TCC_TARGET_X86_64
    } இல்லையெனில் எனில் (op->reg == -2) {
        கோவை_மதிப்பு *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        திரும்பு ind;
#endif
    } இல்லையெனில் {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        எனில் (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } இல்லையெனில் எனில் (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } இல்லையெனில் எனில் (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } இல்லையெனில் {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        எனில் (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        எனில் (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            எனில் (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->shift << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        எனில் (mod == 0x40) {
            g(op->e.v);
        } இல்லையெனில் எனில் (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    திரும்பு 0;
}

#ifdef TCC_TARGET_X86_64
#define REX_W 0x48
#define REX_R 0x44
#define REX_X 0x42
#define REX_B 0x41

நிலையான வெறுமை asm_rex(முழு width64, Operand *ops, முழு nb_ops, முழு *op_type,
		    முழு regi, முழு rmi)
{
  unsigned எழுத்து rex = width64 ? 0x48 : 0;
  முழு saw_உயர்வு_8bit = 0;
  முழு i;
  எனில் (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      க்கு(i = 0; i < nb_ops; i++) {
	  எனில் (op_type[i] & (OP_REG | OP_ST)) {
	      எனில் (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } இல்லையெனில் எனில் (ops[i].type & OP_REG8_கீழ்)
		  rex |= 0x40;
	      இல்லையெனில் எனில் (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_உயர்வு_8bit = ops[i].reg;
	      நிறுத்து;
	  }
      }
  } இல்லையெனில் {
      எனில் (regi != -1) {
	  எனில் (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } இல்லையெனில் எனில் (ops[regi].type & OP_REG8_கீழ்)
	      rex |= 0x40;
	  இல்லையெனில் எனில் (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_உயர்வு_8bit = ops[regi].reg;
      }
      எனில் (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  எனில் (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } இல்லையெனில் எனில் (ops[rmi].type & OP_REG8_கீழ்)
	      rex |= 0x40;
	  இல்லையெனில் எனில் (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_உயர்வு_8bit = ops[rmi].reg;
      }
      எனில் (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  எனில் (rex) {
      எனில் (saw_உயர்வு_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_உயர்வு_8bit-4]);
      g(rex);
  }
}
#endif


நிலையான வெறுமை maybe_print_stats (வெறுமை)
{
    நிலையான முழு already;

    எனில் (0 && !already)
    /* print stats about opcodes */
    {
        மாறிலி கட்டமைப்பு ASMInstr *pa;
        முழு freq[4];
        முழு op_vals[500];
        முழு nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, அளவு(freq));
        க்கு(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                க்கு(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    எனில் (pa->instr_type == op_vals[j])
                        செல் found;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            found: ;
            //}
        }
        க்கு(i=0;i<nb_op_vals;i++) {
            முழு v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                printf("%3d: %08x\n", i, v);
        }
        printf("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (முழு)அளவு(asm_instrs),
	       (முழு)அளவு(asm_instrs) / (முழு)அளவு(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC வெறுமை asm_opcode(TCCState *s1, முழு opcode)
{
    மாறிலி ASMInstr *pa;
    முழு i, modrm_index, modreg_index, reg, v, op1, seg_prefix, pc, p;
    முழு nb_ops, s;
    Operand ops[MAX_OPERANDS], *எடு;
    முழு op_type[3]; /* decoded op type */
    முழு alltypes;   /* OR of all operand types */
    முழு autosize;
    முழு p66;
#ifdef TCC_TARGET_X86_64
    முழு rex64;
#endif

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    எனில் (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    எடு = ops;
    nb_ops = 0;
    seg_prefix = 0;
    alltypes = 0;
    க்கு(;;) {
        எனில் (tok == ';' || tok == TOK_LINEFEED)
            நிறுத்து;
        எனில் (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_operand(s1, எடு);
        எனில் (tok == ':') {
           எனில் (!(எடு->type & OP_SEG) || seg_prefix)
               tcc_error("incorrect prefix");
           seg_prefix = segment_prefixes[எடு->reg];
           next();
           parse_operand(s1, எடு);
           எனில் (!(எடு->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        எடு++;
        nb_ops++;
        எனில் (tok != ',')
            நிறுத்து;
        next();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    க்கு(pa = asm_instrs; pa->sym != 0; pa++) {
	முழு it = pa->instr_type & OPCT_MASK;
        s = 0;
        எனில் (it == OPC_FARITH) {
            v = opcode - pa->sym;
            எனில் (!((unsigned)v < 8 * 6 && (v % 6) == 0))
                தொடர்;
        } இல்லையெனில் எனில் (it == OPC_ARITH) {
            எனில் (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                தொடர்;
            s = (opcode - pa->sym) % NBWLX;
	    எனில் ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		எனில் (((opcode - pa->sym + 1) % NBWLX) == 0)
		    தொடர்;
	        s++;
	      }
        } இல்லையெனில் எனில் (it == OPC_SHIFT) {
            எனில் (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                தொடர்;
            s = (opcode - pa->sym) % NBWLX;
        } இல்லையெனில் எனில் (it == OPC_TEST) {
            எனில் (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                தொடர்;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    எனில் (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } இல்லையெனில் எனில் (pa->instr_type & OPC_B) {
#ifdef TCC_TARGET_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    எனில் ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        தொடர்;
#endif
            எனில் (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                தொடர்;
            s = opcode - pa->sym;
        } இல்லையெனில் எனில் (pa->instr_type & OPC_WLX) {
            எனில் (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                தொடர்;
            s = opcode - pa->sym + 1;
        } இல்லையெனில் {
            எனில் (pa->sym != opcode)
                தொடர்;
        }
        எனில் (pa->nb_ops != nb_ops)
            தொடர்;
#ifdef TCC_TARGET_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	எனில் (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    தொடர்;
#endif
        /* now decode and check each operand */
	alltypes = 0;
        க்கு(i = 0; i < nb_ops; i++) {
            முழு op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            தேர்வு(op2) {
            நிலை OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                நிறுத்து;
            நிலை OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                நிறுத்து;
            நிலை OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                நிறுத்து;
            நிலை OPT_IMW:
                v = OP_IM16 | OP_IM32;
                நிறுத்து;
	    நிலை OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		நிறுத்து;
	    நிலை OPT_DISP:
	    நிலை OPT_DISP8:
		v = OP_ADDR;
		நிறுத்து;
            இயல்பு:
                v = 1 << op2;
                நிறுத்து;
            }
            எனில் (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            எனில் ((ops[i].type & v) == 0)
                செல் next;
	    alltypes |= ops[i].type;
        }
        (வெறுமை)alltypes; /* maybe unused */
        /* all is matching ! */
        நிறுத்து;
    next: ;
    }
    எனில் (pa->sym == 0) {
        எனில் (opcode >= TOK_ASM_first && opcode <= TOK_ASM_last) {
            முழு b;
            b = op0_codes[opcode - TOK_ASM_first];
            எனில் (b & 0xff00)
                g(b >> 8);
            g(b);
            திரும்பு;
        } இல்லையெனில் எனில் (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, வெற்று));
        } இல்லையெனில் {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = table_ident[opcode - TOK_IDENT];
	    எனில் (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		செல் again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#ifdef TCC_TARGET_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    எனில் ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#endif
    எனில் (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        க்கு(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            எனில் ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_to_size[ops[i].type & OP_REG];
        }
        எனில் (s == autosize) {
            எனில் ((opcode == TOK_ASM_தள்ளு || opcode == TOK_ASM_எடு) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    இல்லையெனில் எனில் ((opcode == TOK_ASM_தள்ளு || opcode == TOK_ASM_எடு) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            இல்லையெனில்
                tcc_error("cannot infer opcode suffix");
        }
    }

#ifdef TCC_TARGET_X86_64
    rex64 = 0;
    எனில் (pa->instr_type & OPC_48)
        rex64 = 1;
    இல்லையெனில் எனில் (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	முழு default64 = 0;
	க்கு(i = 0; i < nb_ops; i++) {
	    எனில் (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		நிறுத்து;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        எனில் (((opcode != TOK_ASM_தள்ளு && opcode != TOK_ASM_எடு
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#endif

    /* now generates the operation */
    எனில் (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    எனில் (seg_prefix)
        g(seg_prefix);
#ifdef TCC_TARGET_X86_64
    /* Generate addr32 prefix if needed */
    க்கு(i = 0; i < nb_ops; i++) {
        எனில் (ops[i].type & OP_EA32) {
	    g(0x67);
	    நிறுத்து;
        }
    }
#endif
    /* generate data16 prefix if needed */
    p66 = 0;
    எனில் (s == 1)
        p66 = 1;
    இல்லையெனில் {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        க்கு (i = 0; i < nb_ops; i++)
            எனில் ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    எனில் (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    தேர்வு (p) {
        நிலை 0: நிறுத்து;  /* no prefix */
        நிலை 0x48: நிறுத்து; /* REX, handled elsewhere */
        நிலை 0x66:
        நிலை 0x67:
        நிலை 0xf2:
        நிலை 0xf3: v = v & 0xff; g(p); நிறுத்து;
        நிலை 0xd4: நிலை 0xd5: நிறுத்து; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        நிலை 0xd8: நிலை 0xd9: நிலை 0xda: நிலை 0xdb: /* x87, no normal prefix */
        நிலை 0xdc: நிலை 0xdd: நிலை 0xde: நிலை 0xdf: நிறுத்து;
        இயல்பு: tcc_error("bad prefix 0x%2x in opcode table", p); நிறுத்து;
    }
    எனில் (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    எனில் ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } இல்லையெனில் எனில் (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } இல்லையெனில் எனில் ((v == 0x06 || v == 0x07)) {
        எனில் (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } இல்லையெனில் {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } இல்லையெனில் எனில் (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } இல்லையெனில் எனில் ((pa->instr_type & (OPCT_MASK | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_index = -1;
    modreg_index = -1;
    எனில் (pa->instr_type & OPC_MODRM) {
	எனில் (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#ifdef TCC_TARGET_X86_64
	    எனில் (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    இல்லையெனில் எனில் (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#இல்லையெனில்
	    எனில் (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#endif
	    இல்லையெனில்
	      tcc_error("bad MODR/M opcode without operands");
	    செல் modrm_found;
	}
        /* first look for an ea operand */
        க்கு(i = 0;i < nb_ops; i++) {
            எனில் (op_type[i] & OP_EA)
                செல் modrm_found;
        }
        /* then if not found, a register or indirection (shift instructions) */
        க்கு(i = 0;i < nb_ops; i++) {
            எனில் (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                செல் modrm_found;
        }
#ifdef ASM_DEBUG
        tcc_error("bad op table");
#endif
    modrm_found:
        modrm_index = i;
        /* if a register is used in another operand then it is
           used instead of group */
        க்கு(i = 0;i < nb_ops; i++) {
            முழு t = op_type[i];
            எனில் (i != modrm_index &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_index = i;
                நிறுத்து;
            }
        }
    }
#ifdef TCC_TARGET_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_index, modrm_index);
#endif

    எனில் (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        எனில் (v == 0xb0 && s >= 1)
            v += 7;
        க்கு(i = 0; i < nb_ops; i++) {
            எனில் (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                நிறுத்து;
            }
        }
    }
    எனில் (pa->instr_type & OPC_B)
        v += s >= 1;
    எனில் (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        முழு jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        எனில் (!esym || esym->st_shndx != cur_text_section->sh_இலக்கம்)
            செல் no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_மதிப்பு - ind - 2 - (v >= 0xff);
        எனில் (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } இல்லையெனில் {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    எனில் (v == 0xeb) /* jmp */
	        v = 0xe9;
	    இல்லையெனில் எனில் (v == 0x70) /* jcc */
	        v += 0x0f10;
	    இல்லையெனில்
	        tcc_error("invalid displacement");
        }
    }
    எனில் (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_bits[opcode - pa->sym];
    இல்லையெனில் எனில் (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    எனில் (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    எனில் (op1)
        g(op1);
    g(v);

    எனில் (OPCT_IS(pa->instr_type, OPC_SHIFT)) {
        reg = (opcode - pa->sym) / NBWLX;
        எனில் (reg == 6)
            reg = 7;
    } இல்லையெனில் எனில் (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } இல்லையெனில் எனில் (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } இல்லையெனில் {
        reg = (pa->instr_type >> OPC_GROUP_SHIFT) & 7;
    }

    pc = 0;
    எனில் (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	எனில் (modreg_index >= 0)
	    reg = ops[modreg_index].reg;
        pc = asm_modrm(reg, &ops[modrm_index]);
    }

    /* emit constants */
#ifndef TCC_TARGET_X86_64
    எனில் (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        எனில் (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        திரும்பு;
    }
#endif
    க்கு(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        எனில் (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            எனில் ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                எனில் (s == 0)
                    v = OP_IM8;
                இல்லையெனில் எனில் (s == 1)
                    v = OP_IM16;
                இல்லையெனில் எனில் (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                இல்லையெனில்
                    v = OP_IM64;
            }

            எனில் ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            எனில் (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } இல்லையெனில் எனில் (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#ifdef TCC_TARGET_X86_64
            } இல்லையெனில் எனில் (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#endif
	    } இல்லையெனில் எனில் (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } இல்லையெனில் {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    எனில் (pc)
        add32le(cur_text_section->data + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
நிலையான உள்வரி முழு constraint_priority(மாறிலி எழுத்து *str)
{
    முழு priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    க்கு(;;) {
        c = *str;
        எனில் (c == '\0')
            நிறுத்து;
        str++;
        தேர்வு(c) {
        நிலை 'A':
            pr = 0;
            நிறுத்து;
        நிலை 'a':
        நிலை 'b':
        நிலை 'c':
        நிலை 'd':
        நிலை 'S':
        நிலை 'D':
            pr = 1;
            நிறுத்து;
        நிலை 'q':
            pr = 2;
            நிறுத்து;
        நிலை 'r':
	நிலை 'R':
	நிலை 'p':
            pr = 3;
            நிறுத்து;
        நிலை 'N':
        நிலை 'M':
        நிலை 'I':
	நிலை 'e':
        நிலை 'i':
        நிலை 'm':
        நிலை 'g':
            pr = 4;
            நிறுத்து;
        இயல்பு:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        எனில் (pr > priority)
            priority = pr;
    }
    திரும்பு priority;
}

நிலையான மாறிலி எழுத்து *skip_constraint_modifiers(மாறிலி எழுத்து *p)
{
    போது (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    திரும்பு p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC முழு asm_parse_regvar (முழு t)
{
    மாறிலி எழுத்து *s;
    Operand op;
    எனில் (t < TOK_IDENT || (t & SYM_FIELD))
        திரும்பு -1;
    s = table_ident[t - TOK_IDENT]->str;
    எனில் (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_operand(tcc_state, &op);
    /* Accept only integer regs for now. */
    எனில் (op.type & OP_REG)
        திரும்பு op.reg;
    இல்லையெனில்
        திரும்பு -1;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC வெறுமை asm_compute_constraints(ASMOperand *operands,
                                    முழு nb_operands, முழு nb_outputs,
                                    மாறிலி uint8_t *clobber_regs,
                                    முழு *pout_reg)
{
    ASMOperand *op;
    முழு sorted_op[MAX_ASM_OPERANDS];
    முழு i, j, k, p1, p2, tmp, reg, c, reg_mask;
    மாறிலி எழுத்து *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    க்கு(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->உள்ளீடு_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    க்கு(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        எனில் (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, வெற்று);
            எனில் ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_index = k;
            எனில் (operands[k].உள்ளீடு_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].உள்ளீடு_index = i;
            op->priority = 5;
	} இல்லையெனில் எனில் ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->priority = 1;
	    op->reg = reg;
        } இல்லையெனில் {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    க்கு(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    க்கு(i=0;i<nb_operands - 1;i++) {
        க்கு(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            எனில் (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    க்கு(i = 0;i < NB_ASM_REGS; i++) {
        எனில் (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        இல்லையெனில்
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_IN_MASK | REG_OUT_MASK;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    க்கு(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        எனில் (op->ref_index >= 0)
            தொடர்;
        /* select if register is used for output, input or both */
        எனில் (op->உள்ளீடு_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } இல்லையெனில் எனில் (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } இல்லையெனில் {
            reg_mask = REG_IN_MASK;
        }
	எனில் (op->reg >= 0) {
	    எனில் (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_next:
        c = *str++;
        தேர்வு(c) {
        நிலை '=':
            செல் try_next;
        நிலை '+':
            op->is_rw = 1;
            /* FALL THRU */
        நிலை '&':
            எனில் (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            செல் try_next;
        நிலை 'A':
            /* allocate both eax and edx */
            எனில் (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                செல் try_next;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_mask;
            regs_allocated[TREG_XDX] |= reg_mask;
            நிறுத்து;
        நிலை 'a':
            reg = TREG_XAX;
            செல் alloc_reg;
        நிலை 'b':
            reg = 3;
            செல் alloc_reg;
        நிலை 'c':
            reg = TREG_XCX;
            செல் alloc_reg;
        நிலை 'd':
            reg = TREG_XDX;
            செல் alloc_reg;
        நிலை 'S':
            reg = 6;
            செல் alloc_reg;
        நிலை 'D':
            reg = 7;
        alloc_reg:
            எனில் (op->reg >= 0 && reg != op->reg)
                செல் try_next;
            எனில் (is_reg_allocated(reg))
                செல் try_next;
            செல் reg_found;
        நிலை 'q':
            /* eax, ebx, ecx or edx */
            எனில் (op->reg >= 0) {
                எனில் ((reg = op->reg) < 4)
                    செல் reg_found;
            } இல்லையெனில் க்கு(reg = 0; reg < 4; reg++) {
                எனில் (!is_reg_allocated(reg))
                    செல் reg_found;
            }
            செல் try_next;
        நிலை 'r':
	நிலை 'R':
	நிலை 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            எனில் ((reg = op->reg) >= 0)
                செல் reg_found;
            இல்லையெனில் க்கு(reg = 0; reg < NB_ASM_REGS; reg++) {
                எனில் (!is_reg_allocated(reg))
                    செல் reg_found;
            }
            செல் try_next;
        reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            நிறுத்து;
	நிலை 'e':
        நிலை 'i':
            எனில் (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                செல் try_next;
            நிறுத்து;
        நிலை 'I':
        நிலை 'N':
        நிலை 'M':
            எனில் (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                செல் try_next;
            நிறுத்து;
        நிலை 'm':
        நிலை 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            எனில் (j < nb_outputs || c == 'm') {
                எனில் ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    க்கு(reg = 0; reg < NB_ASM_REGS; reg++) {
                        எனில் (!(regs_allocated[reg] & REG_IN_MASK))
                            செல் reg_found1;
                    }
                    செல் try_next;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            நிறுத்து;
        இயல்பு:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            நிறுத்து;
        }
        /* if a reference is present for that operand, we assign it too */
        எனில் (op->உள்ளீடு_index >= 0) {
            operands[op->உள்ளீடு_index].reg = op->reg;
            operands[op->உள்ளீடு_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    க்கு(i=0;i<nb_operands;i++) {
        op = &operands[i];
        எனில் (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_memory) {
            க்கு(reg = 0; reg < NB_ASM_REGS; reg++) {
                எனில் (!(regs_allocated[reg] & REG_OUT_MASK))
                    செல் reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            நிறுத்து;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    க்கு(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, வெற்று) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    எனில் (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC வெறுமை subst_asm_operand(CString *add_str,
                              SValue *sv, முழு modifier)
{
    முழு r, reg, size, val;

    r = sv->r;
    எனில் ((r & VT_VALMASK) == VT_CONST) {
        எனில் (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(add_str, '$');
        எனில் (r & VT_SYM) {
	    மாறிலி எழுத்து *name = get_tok_str(sv->sym->v, வெற்று);
	    எனில் (sv->sym->v >= SYM_FIRST_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            எனில் (tcc_state->leading_underscore)
              cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            எனில் ((uint32_t)sv->c.i == 0)
                செல் no_offset;
	    cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        எனில் (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
    no_offset:;
#ifdef TCC_TARGET_X86_64
        எனில் (r & VT_LVAL)
            cstr_cat(add_str, "(%rip)", -1);
#endif
    } இல்லையெனில் எனில் ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d(%%%s)", (முழு)sv->c.i, get_tok_str(TOK_ASM_xax + 5, வெற்று));
    } இல்லையெனில் எனில் (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        எனில் (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, வெற்று));
    } இல்லையெனில் {
        /* register case */
        reg = r & VT_VALMASK;
        எனில் (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        எனில் ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        இல்லையெனில் எனில் ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
#ifdef TCC_TARGET_X86_64
        இல்லையெனில் எனில் ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
#endif
        இல்லையெனில்
            size = 4;
        எனில் (size == 1 && reg >= 4)
            size = 4;

        எனில் (modifier == 'b') {
            எனில் (reg >= 4)
                tcc_error("cannot use byte register");
            size = 1;
        } இல்லையெனில் எனில் (modifier == 'h') {
            எனில் (reg >= 4)
                tcc_error("cannot use byte register");
            size = -1;
        } இல்லையெனில் எனில் (modifier == 'w') {
            size = 2;
        } இல்லையெனில் எனில் (modifier == 'k') {
            size = 4;
#ifdef TCC_TARGET_X86_64
        } இல்லையெனில் எனில் (modifier == 'q') {
            size = 8;
#endif
        }

        எனில் (reg >= 8) {
            cstr_printf(add_str, "%%r%d%c", reg, (size == 1) ? 'b' : ((size == 2) ? 'w' : ((size == 4) ? 'd' : ' ')));
            திரும்பு;
        }
        தேர்வு(size) {
        நிலை -1:
            reg = TOK_ASM_ah + reg;
            நிறுத்து;
        நிலை 1:
            reg = TOK_ASM_al + reg;
            நிறுத்து;
        நிலை 2:
            reg = TOK_ASM_ax + reg;
            நிறுத்து;
        இயல்பு:
            reg = TOK_ASM_eax + reg;
            நிறுத்து;
#ifdef TCC_TARGET_X86_64
        நிலை 8:
            reg = TOK_ASM_rax + reg;
            நிறுத்து;
#endif
        }
        cstr_printf(add_str, "%%%s", get_tok_str(reg, வெற்று));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC வெறுமை asm_gen_code(ASMOperand *operands, முழு nb_operands,
                         முழு nb_outputs, முழு is_output,
                         uint8_t *clobber_regs,
                         முழு out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    முழு i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    நிலையான மாறிலி uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#இல்லையெனில்
    நிலையான மாறிலி uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#endif
#இல்லையெனில்
    நிலையான மாறிலி uint8_t reg_saved[] = { 3, 6, 7 };
#endif

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, அளவு(regs_allocated));
    க்கு(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        எனில் (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    எனில் (!is_output) {
        /* generate reg save code */
        க்கு(i = 0; i < அளவு(reg_saved)/அளவு(reg_saved[0]); i++) {
            reg = reg_saved[i];
            எனில் (regs_allocated[reg]) {
		எனில் (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        க்கு(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            எனில் (op->reg >= 0) {
                எனில் ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } இல்லையெனில் எனில் (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    load(op->reg, op->vt);
                    எனில் (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        load(TREG_XDX, &sv);
                    }
                }
            }
        }
    } இல்லையெனில் {
        /* generate save code */
        க்கு(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            எனில் (op->reg >= 0) {
                எனில் ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    எனில் (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        load(out_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } இல்லையெனில் {
                    store(op->reg, op->vt);
                    எனில் (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        க்கு(i = அளவு(reg_saved)/அளவு(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            எனில் (regs_allocated[reg]) {
		எனில் (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC வெறுமை asm_clobber(uint8_t *clobber_regs, மாறிலி எழுத்து *str)
{
    முழு reg;
#ifdef TCC_TARGET_X86_64
    unsigned முழு type;
#endif

    எனில் (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        திரும்பு;
    reg = tok_alloc_const(str);
    எனில் (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } இல்லையெனில் எனில் (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#ifdef TCC_TARGET_X86_64
    } இல்லையெனில் எனில் (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } இல்லையெனில் எனில் ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#endif
    } இல்லையெனில் {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
