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

#घोषणा USING_GLOBALS
#समावेश "tcc.h"

#घोषणा MAX_OPERANDS 3

#घोषणा TOK_ASM_first TOK_ASM_clc
#घोषणा TOK_ASM_last TOK_ASM_emms
#घोषणा TOK_ASM_alllast TOK_ASM_subps

#घोषणा OPC_B          0x01  /* only used with OPC_WL */
#घोषणा OPC_WL         0x02  /* accepts w, l or no suffix */
#घोषणा OPC_BWL        (OPC_B | OPC_WL) /* accepts b, w, l or no suffix */
#घोषणा OPC_REG        0x04 /* register is added to opcode */
#घोषणा OPC_MODRM      0x08 /* modrm encoding */

#घोषणा OPCT_MASK      0x70
#घोषणा OPC_FWAIT      0x10 /* add fwait opcode */
#घोषणा OPC_SHIFT      0x20 /* shift opcodes */
#घोषणा OPC_ARITH      0x30 /* arithmetic opcodes */
#घोषणा OPC_FARITH     0x40 /* FPU arithmetic opcodes */
#घोषणा OPC_TEST       0x50 /* test opcodes */
#घोषणा OPC_0F01       0x60 /* 0x0f01XX (group 7, XX is 2nd opcode,
                               no operands and unstructured mod/rm) */
#घोषणा OPCT_IS(v,i) (((v) & OPCT_MASK) == (i))

#घोषणा OPC_0F        0x100 /* Is secondary map (0x0f prefix) */
#घोषणा OPC_48        0x200 /* Always has REX prefix */
#अगर_घोषित TCC_TARGET_X86_64
# define OPC_WLQ     0x1000  /* accepts w, l, q or no suffix */
# define OPC_BWLQ    (OPC_B | OPC_WLQ) /* accepts b, w, l, q or no suffix */
# define OPC_WLX     OPC_WLQ
# define OPC_BWLX    OPC_BWLQ
#अन्यथा
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#पूर्ण_अगर

#घोषणा OPC_GROUP_SHIFT 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
क्रमागत {
    OPT_REG8=0, /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG16,  /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG32,  /* warning: value is hardcoded from TOK_ASM_xxx */
#अगर_घोषित TCC_TARGET_X86_64
    OPT_REG64,  /* warning: value is hardcoded from TOK_ASM_xxx */
#पूर्ण_अगर
    OPT_MMX,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SSE,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_CR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_TR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_DB,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SEG,
    OPT_ST,
#अगर_घोषित TCC_TARGET_X86_64
    OPT_REG8_निचला, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
		     with REX prefix, not used in insn templates */
#पूर्ण_अगर
    OPT_IM8,
    OPT_IM8S,
    OPT_IM16,
    OPT_IM32,
#अगर_घोषित TCC_TARGET_X86_64
    OPT_IM64,
#पूर्ण_अगर
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

#घोषणा OP_REG8   (1 << OPT_REG8)
#घोषणा OP_REG16  (1 << OPT_REG16)
#घोषणा OP_REG32  (1 << OPT_REG32)
#घोषणा OP_MMX    (1 << OPT_MMX)
#घोषणा OP_SSE    (1 << OPT_SSE)
#घोषणा OP_CR     (1 << OPT_CR)
#घोषणा OP_TR     (1 << OPT_TR)
#घोषणा OP_DB     (1 << OPT_DB)
#घोषणा OP_SEG    (1 << OPT_SEG)
#घोषणा OP_ST     (1 << OPT_ST)
#घोषणा OP_IM8    (1 << OPT_IM8)
#घोषणा OP_IM8S   (1 << OPT_IM8S)
#घोषणा OP_IM16   (1 << OPT_IM16)
#घोषणा OP_IM32   (1 << OPT_IM32)
#घोषणा OP_EAX    (1 << OPT_EAX)
#घोषणा OP_ST0    (1 << OPT_ST0)
#घोषणा OP_CL     (1 << OPT_CL)
#घोषणा OP_DX     (1 << OPT_DX)
#घोषणा OP_ADDR   (1 << OPT_ADDR)
#घोषणा OP_INDIR  (1 << OPT_INDIR)
#अगर_घोषित TCC_TARGET_X86_64
# define OP_REG64 (1 << OPT_REG64)
# define OP_REG8_निचला (1 << OPT_REG8_निचला)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#अन्यथा
# define OP_REG64 0
# define OP_REG8_निचला 0
# define OP_IM64  0
# define OP_EA32  0
#पूर्ण_अगर

#घोषणा OP_EA     0x40000000u
#घोषणा OP_REG    (OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64)

#अगर_घोषित TCC_TARGET_X86_64
# define TREG_XAX   TREG_RAX
# define TREG_XCX   TREG_RCX
# define TREG_XDX   TREG_RDX
# define TOK_ASM_xax TOK_ASM_rax
#अन्यथा
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#पूर्ण_अगर

प्रकार काष्ठा ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

प्रकार काष्ठा Operand {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t shift;
    व्यंजक_मूल्य e;
} Operand;

अटल स्थिर uint8_t reg_to_आकार[9] = {
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

#घोषणा NB_TEST_OPCODES 30

अटल स्थिर uint8_t test_bits[NB_TEST_OPCODES] = {
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

अटल स्थिर uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

अटल स्थिर ASMInstr asm_instrs[] = {
#घोषणा ALT(x) x
/* This removes a 0x0f in the second byte */
#घोषणा O(o) ((uint64_t) ((((o) & 0xff00) == 0x0f00) ? ((((o) >> 8) & ~0xff) | ((o) & 0xff)) : (o)))
/* This constructs instr_type from opcode, type and group.  */
#घोषणा T(o,i,g) ((i) | ((g) << OPC_GROUP_SHIFT) | ((((o) & 0xff00) == 0x0f00) ? OPC_0F : 0))
#घोषणा DEF_ASM_OP0(name, opcode)
#घोषणा DEF_ASM_OP0L(name, opcode, group, instr_type) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, group), 0, { 0 } },
#घोषणा DEF_ASM_OP1(name, opcode, group, instr_type, op0) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, group), 1, { op0 }},
#घोषणा DEF_ASM_OP2(name, opcode, group, instr_type, op0, op1) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, group), 2, { op0, op1 }},
#घोषणा DEF_ASM_OP3(name, opcode, group, instr_type, op0, op1, op2) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, group), 3, { op0, op1, op2 }},
#अगर_घोषित TCC_TARGET_X86_64
# include "x86_64-asm.h"
#अन्यथा
# include "i386-asm.h"
#पूर्ण_अगर
    /* last operation */
    { 0, },
};

अटल स्थिर uint16_t op0_codes[] = {
#घोषणा ALT(x)
#घोषणा DEF_ASM_OP0(x, opcode) opcode,
#घोषणा DEF_ASM_OP0L(name, opcode, group, instr_type)
#घोषणा DEF_ASM_OP1(name, opcode, group, instr_type, op0)
#घोषणा DEF_ASM_OP2(name, opcode, group, instr_type, op0, op1)
#घोषणा DEF_ASM_OP3(name, opcode, group, instr_type, op0, op1, op2)
#अगर_घोषित TCC_TARGET_X86_64
# include "x86_64-asm.h"
#अन्यथा
# include "i386-asm.h"
#पूर्ण_अगर
};

अटल अंतरभूत पूर्णांक get_reg_shift(TCCState *s1)
{
    पूर्णांक shift, v;
    v = asm_int_व्यंजक(s1);
    चयन(v) {
    हाल 1:
        shift = 0;
        अवरोध;
    हाल 2:
        shift = 1;
        अवरोध;
    हाल 4:
        shift = 2;
        अवरोध;
    हाल 8:
        shift = 3;
        अवरोध;
    शेष:
        expect("1, 2, 4 or 8 constant");
        shift = 0;
        अवरोध;
    }
    वापस shift;
}

#अगर_घोषित TCC_TARGET_X86_64
अटल पूर्णांक asm_parse_numeric_reg(पूर्णांक t, अचिन्हित पूर्णांक *type)
{
    पूर्णांक reg = -1;
    अगर (t >= TOK_IDENT && t < tok_ident) {
	स्थिर अक्षर *s = table_ident[t - TOK_IDENT]->str;
	अक्षर c;
	*type = OP_REG64;
	अगर (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	अगर (*s++ != 'r')
	  वापस -1;
	/* Don't allow leading '0'.  */
	अगर ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	अन्यथा
	  वापस -1;
	अगर ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	अगर (reg > 15)
	  वापस -1;
	अगर ((c = *s) == 0)
	  ;
	अन्यथा अगर (*type != OP_REG64)
	  वापस -1;
	अन्यथा अगर (c == 'b' && !s[1])
	  *type = OP_REG8;
	अन्यथा अगर (c == 'w' && !s[1])
	  *type = OP_REG16;
	अन्यथा अगर (c == 'd' && !s[1])
	  *type = OP_REG32;
	अन्यथा
	  वापस -1;
    }
    वापस reg;
}
#पूर्ण_अगर

अटल पूर्णांक asm_parse_reg(अचिन्हित पूर्णांक *type)
{
    पूर्णांक reg = 0;
    *type = 0;
    अगर (tok != '%')
        जाओ error_32;
    अग्र();
    अगर (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#अगर_घोषित TCC_TARGET_X86_64
    } अन्यथा अगर (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } अन्यथा अगर (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } अन्यथा अगर ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#पूर्ण_अगर
    } अन्यथा {
    error_32:
        expect("register");
    }
    अग्र();
    वापस reg;
}

अटल व्योम parse_operand(TCCState *s1, Operand *op)
{
    व्यंजक_मूल्य e;
    पूर्णांक reg, indir;
    स्थिर अक्षर *p;

    indir = 0;
    अगर (tok == '*') {
        अग्र();
        indir = OP_INDIR;
    }

    अगर (tok == '%') {
        अग्र();
        अगर (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            अगर ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            अन्यथा अगर (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            अन्यथा अगर (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } अन्यथा अगर (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } अन्यथा अगर (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } अन्यथा अगर (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            अग्र();
            अगर (tok == '(') {
                अग्र();
                अगर (tok != TOK_PPNUM)
                    जाओ reg_error;
                p = tokc.str.तथ्य;
                reg = p[0] - '0';
                अगर ((अचिन्हित)reg >= 8 || p[1] != '\0')
                    जाओ reg_error;
                op->reg = reg;
                अग्र();
                skip(')');
            }
            अगर (op->reg == 0)
                op->type |= OP_ST0;
            जाओ no_skip;
#अगर_घोषित TCC_TARGET_X86_64
	} अन्यथा अगर (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_निचला;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } अन्यथा अगर ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#पूर्ण_अगर
        } अन्यथा {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        अग्र();
    no_skip: ;
    } अन्यथा अगर (tok == '$') {
        /* constant value */
        अग्र();
        asm_व्यंजक(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        अगर (!op->e.sym) {
            अगर (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            अगर (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            अगर (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#अगर_घोषित TCC_TARGET_X86_64
            अगर (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#पूर्ण_अगर
        }
    } अन्यथा {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->shift = 0;
        अगर (tok != '(') {
            asm_व्यंजक(s1, &e);
            op->e = e;
        } अन्यथा {
            अग्र();
            अगर (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = शून्य;
            } अन्यथा {
                /* bracketed offset expression */
                asm_व्यंजक(s1, &e);
                अगर (tok != ')')
                    expect(")");
                अग्र();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        अगर (tok == '(') {
	    अचिन्हित पूर्णांक type = 0;
            अग्र();
            अगर (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            अगर (tok == ',') {
                अग्र();
                अगर (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                अगर (tok == ',') {
                    अग्र();
                    op->shift = get_reg_shift(s1);
                }
            }
	    अगर (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        अगर (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC व्योम gen_expr32(व्यंजक_मूल्य *pe)
{
    अगर (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    अन्यथा
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
अटल व्योम gen_disp32(व्यंजक_मूल्य *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    अगर (esym && esym->st_shndx == cur_text_section->sh_अंक) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_मूल्य - ind - 4);
    } अन्यथा {
        अगर (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = शून्य;
        }
#अगर_घोषित TCC_TARGET_X86_64
        greloca(cur_text_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#अन्यथा
        gen_addrpc32(VT_SYM, sym, pe->v);
#पूर्ण_अगर

    }
}

/* generate the modrm operand */
अटल अंतरभूत पूर्णांक asm_modrm(पूर्णांक reg, Operand *op)
{
    पूर्णांक mod, reg1, reg2, sib_reg1;

    अगर (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } अन्यथा अगर (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#अगर_घोषित TCC_TARGET_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#अन्यथा
	g(0x05 + (reg << 3));
#पूर्ण_अगर
	gen_expr32(&op->e);
#अगर_घोषित TCC_TARGET_X86_64
    } अन्यथा अगर (op->reg == -2) {
        व्यंजक_मूल्य *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        वापस ind;
#पूर्ण_अगर
    } अन्यथा {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        अगर (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } अन्यथा अगर (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } अन्यथा अगर (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } अन्यथा {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        अगर (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        अगर (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            अगर (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->shift << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        अगर (mod == 0x40) {
            g(op->e.v);
        } अन्यथा अगर (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    वापस 0;
}

#अगर_घोषित TCC_TARGET_X86_64
#घोषणा REX_W 0x48
#घोषणा REX_R 0x44
#घोषणा REX_X 0x42
#घोषणा REX_B 0x41

अटल व्योम asm_rex(पूर्णांक width64, Operand *ops, पूर्णांक nb_ops, पूर्णांक *op_type,
		    पूर्णांक regi, पूर्णांक rmi)
{
  अचिन्हित अक्षर rex = width64 ? 0x48 : 0;
  पूर्णांक saw_ऊपरी_8bit = 0;
  पूर्णांक i;
  अगर (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      क्रम(i = 0; i < nb_ops; i++) {
	  अगर (op_type[i] & (OP_REG | OP_ST)) {
	      अगर (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } अन्यथा अगर (ops[i].type & OP_REG8_निचला)
		  rex |= 0x40;
	      अन्यथा अगर (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_ऊपरी_8bit = ops[i].reg;
	      अवरोध;
	  }
      }
  } अन्यथा {
      अगर (regi != -1) {
	  अगर (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } अन्यथा अगर (ops[regi].type & OP_REG8_निचला)
	      rex |= 0x40;
	  अन्यथा अगर (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_ऊपरी_8bit = ops[regi].reg;
      }
      अगर (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  अगर (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } अन्यथा अगर (ops[rmi].type & OP_REG8_निचला)
	      rex |= 0x40;
	  अन्यथा अगर (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_ऊपरी_8bit = ops[rmi].reg;
      }
      अगर (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  अगर (rex) {
      अगर (saw_ऊपरी_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_ऊपरी_8bit-4]);
      g(rex);
  }
}
#पूर्ण_अगर


अटल व्योम maybe_print_stats (व्योम)
{
    अटल पूर्णांक already;

    अगर (0 && !already)
    /* print stats about opcodes */
    {
        स्थिर काष्ठा ASMInstr *pa;
        पूर्णांक freq[4];
        पूर्णांक op_vals[500];
        पूर्णांक nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        स_रखो(freq, 0, माप(freq));
        क्रम(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                क्रम(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    अगर (pa->instr_type == op_vals[j])
                        जाओ found;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            found: ;
            //}
        }
        क्रम(i=0;i<nb_op_vals;i++) {
            पूर्णांक v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                म_लिखो("%3d: %08x\n", i, v);
        }
        म_लिखो("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (पूर्णांक)माप(asm_instrs),
	       (पूर्णांक)माप(asm_instrs) / (पूर्णांक)माप(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC व्योम asm_opcode(TCCState *s1, पूर्णांक opcode)
{
    स्थिर ASMInstr *pa;
    पूर्णांक i, modrm_सूचकांक, modreg_सूचकांक, reg, v, op1, seg_prefix, pc, p;
    पूर्णांक nb_ops, s;
    Operand ops[MAX_OPERANDS], *निकालो;
    पूर्णांक op_type[3]; /* decoded op type */
    पूर्णांक alltypes;   /* OR of all operand types */
    पूर्णांक autosize;
    पूर्णांक p66;
#अगर_घोषित TCC_TARGET_X86_64
    पूर्णांक rex64;
#पूर्ण_अगर

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    अगर (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    निकालो = ops;
    nb_ops = 0;
    seg_prefix = 0;
    alltypes = 0;
    क्रम(;;) {
        अगर (tok == ';' || tok == TOK_LINEFEED)
            अवरोध;
        अगर (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_operand(s1, निकालो);
        अगर (tok == ':') {
           अगर (!(निकालो->type & OP_SEG) || seg_prefix)
               tcc_error("incorrect prefix");
           seg_prefix = segment_prefixes[निकालो->reg];
           अग्र();
           parse_operand(s1, निकालो);
           अगर (!(निकालो->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        निकालो++;
        nb_ops++;
        अगर (tok != ',')
            अवरोध;
        अग्र();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    क्रम(pa = asm_instrs; pa->sym != 0; pa++) {
	पूर्णांक it = pa->instr_type & OPCT_MASK;
        s = 0;
        अगर (it == OPC_FARITH) {
            v = opcode - pa->sym;
            अगर (!((अचिन्हित)v < 8 * 6 && (v % 6) == 0))
                जारी;
        } अन्यथा अगर (it == OPC_ARITH) {
            अगर (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                जारी;
            s = (opcode - pa->sym) % NBWLX;
	    अगर ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		अगर (((opcode - pa->sym + 1) % NBWLX) == 0)
		    जारी;
	        s++;
	      }
        } अन्यथा अगर (it == OPC_SHIFT) {
            अगर (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                जारी;
            s = (opcode - pa->sym) % NBWLX;
        } अन्यथा अगर (it == OPC_TEST) {
            अगर (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                जारी;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    अगर (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } अन्यथा अगर (pa->instr_type & OPC_B) {
#अगर_घोषित TCC_TARGET_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    अगर ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        जारी;
#पूर्ण_अगर
            अगर (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                जारी;
            s = opcode - pa->sym;
        } अन्यथा अगर (pa->instr_type & OPC_WLX) {
            अगर (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                जारी;
            s = opcode - pa->sym + 1;
        } अन्यथा {
            अगर (pa->sym != opcode)
                जारी;
        }
        अगर (pa->nb_ops != nb_ops)
            जारी;
#अगर_घोषित TCC_TARGET_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	अगर (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    जारी;
#पूर्ण_अगर
        /* now decode and check each operand */
	alltypes = 0;
        क्रम(i = 0; i < nb_ops; i++) {
            पूर्णांक op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            चयन(op2) {
            हाल OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                अवरोध;
            हाल OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                अवरोध;
            हाल OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                अवरोध;
            हाल OPT_IMW:
                v = OP_IM16 | OP_IM32;
                अवरोध;
	    हाल OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		अवरोध;
	    हाल OPT_DISP:
	    हाल OPT_DISP8:
		v = OP_ADDR;
		अवरोध;
            शेष:
                v = 1 << op2;
                अवरोध;
            }
            अगर (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            अगर ((ops[i].type & v) == 0)
                जाओ अग्र;
	    alltypes |= ops[i].type;
        }
        (व्योम)alltypes; /* maybe unused */
        /* all is matching ! */
        अवरोध;
    अग्र: ;
    }
    अगर (pa->sym == 0) {
        अगर (opcode >= TOK_ASM_first && opcode <= TOK_ASM_last) {
            पूर्णांक b;
            b = op0_codes[opcode - TOK_ASM_first];
            अगर (b & 0xff00)
                g(b >> 8);
            g(b);
            वापस;
        } अन्यथा अगर (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, शून्य));
        } अन्यथा {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = table_ident[opcode - TOK_IDENT];
	    अगर (ts->len >= 6
		&& म_अक्षर("wlq", ts->str[ts->len-1])
		&& !स_भेद(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		जाओ again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#अगर_घोषित TCC_TARGET_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    अगर ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#पूर्ण_अगर
    अगर (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        क्रम(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            अगर ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_to_आकार[ops[i].type & OP_REG];
        }
        अगर (s == autosize) {
            अगर ((opcode == TOK_ASM_धकेलो || opcode == TOK_ASM_निकालो) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    अन्यथा अगर ((opcode == TOK_ASM_धकेलो || opcode == TOK_ASM_निकालो) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            अन्यथा
                tcc_error("cannot infer opcode suffix");
        }
    }

#अगर_घोषित TCC_TARGET_X86_64
    rex64 = 0;
    अगर (pa->instr_type & OPC_48)
        rex64 = 1;
    अन्यथा अगर (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	पूर्णांक default64 = 0;
	क्रम(i = 0; i < nb_ops; i++) {
	    अगर (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		अवरोध;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        अगर (((opcode != TOK_ASM_धकेलो && opcode != TOK_ASM_निकालो
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#पूर्ण_अगर

    /* now generates the operation */
    अगर (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    अगर (seg_prefix)
        g(seg_prefix);
#अगर_घोषित TCC_TARGET_X86_64
    /* Generate addr32 prefix if needed */
    क्रम(i = 0; i < nb_ops; i++) {
        अगर (ops[i].type & OP_EA32) {
	    g(0x67);
	    अवरोध;
        }
    }
#पूर्ण_अगर
    /* generate data16 prefix if needed */
    p66 = 0;
    अगर (s == 1)
        p66 = 1;
    अन्यथा {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        क्रम (i = 0; i < nb_ops; i++)
            अगर ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    अगर (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    चयन (p) {
        हाल 0: अवरोध;  /* no prefix */
        हाल 0x48: अवरोध; /* REX, handled elsewhere */
        हाल 0x66:
        हाल 0x67:
        हाल 0xf2:
        हाल 0xf3: v = v & 0xff; g(p); अवरोध;
        हाल 0xd4: हाल 0xd5: अवरोध; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        हाल 0xd8: हाल 0xd9: हाल 0xda: हाल 0xdb: /* x87, no normal prefix */
        हाल 0xdc: हाल 0xdd: हाल 0xde: हाल 0xdf: अवरोध;
        शेष: tcc_error("bad prefix 0x%2x in opcode table", p); अवरोध;
    }
    अगर (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    अगर ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } अन्यथा अगर (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } अन्यथा अगर ((v == 0x06 || v == 0x07)) {
        अगर (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } अन्यथा {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } अन्यथा अगर (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } अन्यथा अगर ((pa->instr_type & (OPCT_MASK | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_सूचकांक = -1;
    modreg_सूचकांक = -1;
    अगर (pa->instr_type & OPC_MODRM) {
	अगर (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#अगर_घोषित TCC_TARGET_X86_64
	    अगर (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    अन्यथा अगर (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#अन्यथा
	    अगर (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#पूर्ण_अगर
	    अन्यथा
	      tcc_error("bad MODR/M opcode without operands");
	    जाओ modrm_found;
	}
        /* first look for an ea operand */
        क्रम(i = 0;i < nb_ops; i++) {
            अगर (op_type[i] & OP_EA)
                जाओ modrm_found;
        }
        /* then if not found, a register or indirection (shift instructions) */
        क्रम(i = 0;i < nb_ops; i++) {
            अगर (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                जाओ modrm_found;
        }
#अगर_घोषित ASM_DEBUG
        tcc_error("bad op table");
#पूर्ण_अगर
    modrm_found:
        modrm_सूचकांक = i;
        /* if a register is used in another operand then it is
           used instead of group */
        क्रम(i = 0;i < nb_ops; i++) {
            पूर्णांक t = op_type[i];
            अगर (i != modrm_सूचकांक &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_सूचकांक = i;
                अवरोध;
            }
        }
    }
#अगर_घोषित TCC_TARGET_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_सूचकांक, modrm_सूचकांक);
#पूर्ण_अगर

    अगर (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        अगर (v == 0xb0 && s >= 1)
            v += 7;
        क्रम(i = 0; i < nb_ops; i++) {
            अगर (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                अवरोध;
            }
        }
    }
    अगर (pa->instr_type & OPC_B)
        v += s >= 1;
    अगर (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        पूर्णांक jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        अगर (!esym || esym->st_shndx != cur_text_section->sh_अंक)
            जाओ no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_मूल्य - ind - 2 - (v >= 0xff);
        अगर (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } अन्यथा {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    अगर (v == 0xeb) /* jmp */
	        v = 0xe9;
	    अन्यथा अगर (v == 0x70) /* jcc */
	        v += 0x0f10;
	    अन्यथा
	        tcc_error("invalid displacement");
        }
    }
    अगर (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_bits[opcode - pa->sym];
    अन्यथा अगर (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    अगर (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    अगर (op1)
        g(op1);
    g(v);

    अगर (OPCT_IS(pa->instr_type, OPC_SHIFT)) {
        reg = (opcode - pa->sym) / NBWLX;
        अगर (reg == 6)
            reg = 7;
    } अन्यथा अगर (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } अन्यथा अगर (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } अन्यथा {
        reg = (pa->instr_type >> OPC_GROUP_SHIFT) & 7;
    }

    pc = 0;
    अगर (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	अगर (modreg_सूचकांक >= 0)
	    reg = ops[modreg_सूचकांक].reg;
        pc = asm_modrm(reg, &ops[modrm_सूचकांक]);
    }

    /* emit constants */
#अगर_अघोषित TCC_TARGET_X86_64
    अगर (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        अगर (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        वापस;
    }
#पूर्ण_अगर
    क्रम(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        अगर (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            अगर ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                अगर (s == 0)
                    v = OP_IM8;
                अन्यथा अगर (s == 1)
                    v = OP_IM16;
                अन्यथा अगर (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                अन्यथा
                    v = OP_IM64;
            }

            अगर ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            अगर (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } अन्यथा अगर (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#अगर_घोषित TCC_TARGET_X86_64
            } अन्यथा अगर (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#पूर्ण_अगर
	    } अन्यथा अगर (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } अन्यथा {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    अगर (pc)
        add32le(cur_text_section->तथ्य + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
अटल अंतरभूत पूर्णांक constraint_priority(स्थिर अक्षर *str)
{
    पूर्णांक priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    क्रम(;;) {
        c = *str;
        अगर (c == '\0')
            अवरोध;
        str++;
        चयन(c) {
        हाल 'A':
            pr = 0;
            अवरोध;
        हाल 'a':
        हाल 'b':
        हाल 'c':
        हाल 'd':
        हाल 'S':
        हाल 'D':
            pr = 1;
            अवरोध;
        हाल 'q':
            pr = 2;
            अवरोध;
        हाल 'r':
	हाल 'R':
	हाल 'p':
            pr = 3;
            अवरोध;
        हाल 'N':
        हाल 'M':
        हाल 'I':
	हाल 'e':
        हाल 'i':
        हाल 'm':
        हाल 'g':
            pr = 4;
            अवरोध;
        शेष:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        अगर (pr > priority)
            priority = pr;
    }
    वापस priority;
}

अटल स्थिर अक्षर *skip_constraint_modifiers(स्थिर अक्षर *p)
{
    जबतक (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    वापस p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC पूर्णांक asm_parse_regvar (पूर्णांक t)
{
    स्थिर अक्षर *s;
    Operand op;
    अगर (t < TOK_IDENT || (t & SYM_FIELD))
        वापस -1;
    s = table_ident[t - TOK_IDENT]->str;
    अगर (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_operand(tcc_state, &op);
    /* Accept only integer regs for now. */
    अगर (op.type & OP_REG)
        वापस op.reg;
    अन्यथा
        वापस -1;
}

#घोषणा REG_OUT_MASK 0x01
#घोषणा REG_IN_MASK  0x02

#घोषणा is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC व्योम asm_compute_constraints(ASMOperand *operands,
                                    पूर्णांक nb_operands, पूर्णांक nb_outputs,
                                    स्थिर uint8_t *clobber_regs,
                                    पूर्णांक *pout_reg)
{
    ASMOperand *op;
    पूर्णांक sorted_op[MAX_ASM_OPERANDS];
    पूर्णांक i, j, k, p1, p2, tmp, reg, c, reg_mask;
    स्थिर अक्षर *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    क्रम(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->निवेश_सूचकांक = -1;
        op->ref_सूचकांक = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    क्रम(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        अगर (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, शून्य);
            अगर ((अचिन्हित)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_सूचकांक = k;
            अगर (operands[k].निवेश_सूचकांक >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].निवेश_सूचकांक = i;
            op->priority = 5;
	} अन्यथा अगर ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->priority = 1;
	    op->reg = reg;
        } अन्यथा {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    क्रम(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    क्रम(i=0;i<nb_operands - 1;i++) {
        क्रम(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            अगर (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    क्रम(i = 0;i < NB_ASM_REGS; i++) {
        अगर (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        अन्यथा
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_IN_MASK | REG_OUT_MASK;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    क्रम(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        अगर (op->ref_सूचकांक >= 0)
            जारी;
        /* select if register is used for output, input or both */
        अगर (op->निवेश_सूचकांक >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अन्यथा अगर (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अन्यथा {
            reg_mask = REG_IN_MASK;
        }
	अगर (op->reg >= 0) {
	    अगर (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_अग्र:
        c = *str++;
        चयन(c) {
        हाल '=':
            जाओ try_अग्र;
        हाल '+':
            op->is_rw = 1;
            /* FALL THRU */
        हाल '&':
            अगर (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            जाओ try_अग्र;
        हाल 'A':
            /* allocate both eax and edx */
            अगर (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                जाओ try_अग्र;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_mask;
            regs_allocated[TREG_XDX] |= reg_mask;
            अवरोध;
        हाल 'a':
            reg = TREG_XAX;
            जाओ alloc_reg;
        हाल 'b':
            reg = 3;
            जाओ alloc_reg;
        हाल 'c':
            reg = TREG_XCX;
            जाओ alloc_reg;
        हाल 'd':
            reg = TREG_XDX;
            जाओ alloc_reg;
        हाल 'S':
            reg = 6;
            जाओ alloc_reg;
        हाल 'D':
            reg = 7;
        alloc_reg:
            अगर (op->reg >= 0 && reg != op->reg)
                जाओ try_अग्र;
            अगर (is_reg_allocated(reg))
                जाओ try_अग्र;
            जाओ reg_found;
        हाल 'q':
            /* eax, ebx, ecx or edx */
            अगर (op->reg >= 0) {
                अगर ((reg = op->reg) < 4)
                    जाओ reg_found;
            } अन्यथा क्रम(reg = 0; reg < 4; reg++) {
                अगर (!is_reg_allocated(reg))
                    जाओ reg_found;
            }
            जाओ try_अग्र;
        हाल 'r':
	हाल 'R':
	हाल 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            अगर ((reg = op->reg) >= 0)
                जाओ reg_found;
            अन्यथा क्रम(reg = 0; reg < NB_ASM_REGS; reg++) {
                अगर (!is_reg_allocated(reg))
                    जाओ reg_found;
            }
            जाओ try_अग्र;
        reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            अवरोध;
	हाल 'e':
        हाल 'i':
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                जाओ try_अग्र;
            अवरोध;
        हाल 'I':
        हाल 'N':
        हाल 'M':
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जाओ try_अग्र;
            अवरोध;
        हाल 'm':
        हाल 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            अगर (j < nb_outputs || c == 'm') {
                अगर ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    क्रम(reg = 0; reg < NB_ASM_REGS; reg++) {
                        अगर (!(regs_allocated[reg] & REG_IN_MASK))
                            जाओ reg_found1;
                    }
                    जाओ try_अग्र;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            अवरोध;
        शेष:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            अवरोध;
        }
        /* if a reference is present for that operand, we assign it too */
        अगर (op->निवेश_सूचकांक >= 0) {
            operands[op->निवेश_सूचकांक].reg = op->reg;
            operands[op->निवेश_सूचकांक].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    क्रम(i=0;i<nb_operands;i++) {
        op = &operands[i];
        अगर (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_memory) {
            क्रम(reg = 0; reg < NB_ASM_REGS; reg++) {
                अगर (!(regs_allocated[reg] & REG_OUT_MASK))
                    जाओ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            अवरोध;
        }
    }

    /* print sorted constraints */
#अगर_घोषित ASM_DEBUG
    क्रम(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        म_लिखो("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, शून्य) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    अगर (*pout_reg >= 0)
        म_लिखो("out_reg=%d\n", *pout_reg);
#पूर्ण_अगर
}

ST_FUNC व्योम subst_asm_operand(CString *add_str,
                              SValue *sv, पूर्णांक modifier)
{
    पूर्णांक r, reg, आकार, val;

    r = sv->r;
    अगर ((r & VT_VALMASK) == VT_CONST) {
        अगर (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(add_str, '$');
        अगर (r & VT_SYM) {
	    स्थिर अक्षर *name = get_tok_str(sv->sym->v, शून्य);
	    अगर (sv->sym->v >= SYM_FIRST_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            अगर (tcc_state->leading_underscore)
              cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            अगर ((uint32_t)sv->c.i == 0)
                जाओ no_offset;
	    cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        अगर (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
    no_offset:;
#अगर_घोषित TCC_TARGET_X86_64
        अगर (r & VT_LVAL)
            cstr_cat(add_str, "(%rip)", -1);
#पूर्ण_अगर
    } अन्यथा अगर ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d(%%%s)", (पूर्णांक)sv->c.i, get_tok_str(TOK_ASM_xax + 5, शून्य));
    } अन्यथा अगर (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        अगर (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, शून्य));
    } अन्यथा {
        /* register case */
        reg = r & VT_VALMASK;
        अगर (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        अगर ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            आकार = 1;
        अन्यथा अगर ((sv->type.t & VT_BTYPE) == VT_SHORT)
            आकार = 2;
#अगर_घोषित TCC_TARGET_X86_64
        अन्यथा अगर ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            आकार = 8;
#पूर्ण_अगर
        अन्यथा
            आकार = 4;
        अगर (आकार == 1 && reg >= 4)
            आकार = 4;

        अगर (modifier == 'b') {
            अगर (reg >= 4)
                tcc_error("cannot use byte register");
            आकार = 1;
        } अन्यथा अगर (modifier == 'h') {
            अगर (reg >= 4)
                tcc_error("cannot use byte register");
            आकार = -1;
        } अन्यथा अगर (modifier == 'w') {
            आकार = 2;
        } अन्यथा अगर (modifier == 'k') {
            आकार = 4;
#अगर_घोषित TCC_TARGET_X86_64
        } अन्यथा अगर (modifier == 'q') {
            आकार = 8;
#पूर्ण_अगर
        }

        अगर (reg >= 8) {
            cstr_printf(add_str, "%%r%d%c", reg, (आकार == 1) ? 'b' : ((आकार == 2) ? 'w' : ((आकार == 4) ? 'd' : ' ')));
            वापस;
        }
        चयन(आकार) {
        हाल -1:
            reg = TOK_ASM_ah + reg;
            अवरोध;
        हाल 1:
            reg = TOK_ASM_al + reg;
            अवरोध;
        हाल 2:
            reg = TOK_ASM_ax + reg;
            अवरोध;
        शेष:
            reg = TOK_ASM_eax + reg;
            अवरोध;
#अगर_घोषित TCC_TARGET_X86_64
        हाल 8:
            reg = TOK_ASM_rax + reg;
            अवरोध;
#पूर्ण_अगर
        }
        cstr_printf(add_str, "%%%s", get_tok_str(reg, शून्य));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC व्योम asm_gen_code(ASMOperand *operands, पूर्णांक nb_operands,
                         पूर्णांक nb_outputs, पूर्णांक is_output,
                         uint8_t *clobber_regs,
                         पूर्णांक out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    पूर्णांक i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#अगर_घोषित TCC_TARGET_X86_64
#अगर_घोषित TCC_TARGET_PE
    अटल स्थिर uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#अन्यथा
    अटल स्थिर uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#पूर्ण_अगर
#अन्यथा
    अटल स्थिर uint8_t reg_saved[] = { 3, 6, 7 };
#पूर्ण_अगर

    /* mark all used registers */
    स_नकल(regs_allocated, clobber_regs, माप(regs_allocated));
    क्रम(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        अगर (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    अगर (!is_output) {
        /* generate reg save code */
        क्रम(i = 0; i < माप(reg_saved)/माप(reg_saved[0]); i++) {
            reg = reg_saved[i];
            अगर (regs_allocated[reg]) {
		अगर (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        क्रम(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            अगर (op->reg >= 0) {
                अगर ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } अन्यथा अगर (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    load(op->reg, op->vt);
                    अगर (op->is_llong) {
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
        क्रम(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            अगर (op->reg >= 0) {
                अगर ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    अगर (!op->is_memory) {
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
                    अगर (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        क्रम(i = माप(reg_saved)/माप(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            अगर (regs_allocated[reg]) {
		अगर (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC व्योम asm_clobber(uint8_t *clobber_regs, स्थिर अक्षर *str)
{
    पूर्णांक reg;
#अगर_घोषित TCC_TARGET_X86_64
    अचिन्हित पूर्णांक type;
#पूर्ण_अगर

    अगर (!म_भेद(str, "memory") ||
        !म_भेद(str, "cc") ||
	!म_भेद(str, "flags"))
        वापस;
    reg = tok_alloc_const(str);
    अगर (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } अन्यथा अगर (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#अगर_घोषित TCC_TARGET_X86_64
    } अन्यथा अगर (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } अन्यथा अगर ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#पूर्ण_अगर
    } अन्यथा {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
