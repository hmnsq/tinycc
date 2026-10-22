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

#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

#ವ್ಯಾಖ್ಯಾನಿಸು MAX_OPERANDS 3

#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ASM_ಮೊದಲ TOK_ASM_clc
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ASM_ಕೊನೆಯ TOK_ASM_emms
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ASM_alllast TOK_ASM_subps

#ವ್ಯಾಖ್ಯಾನಿಸು OPC_B          0x01  /* only used with OPC_WL */
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_WL         0x02  /* accepts w, l or no suffix */
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_BWL        (OPC_B | OPC_WL) /* accepts b, w, l or no suffix */
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_REG        0x04 /* register is added to opcode */
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_MODRM      0x08 /* modrm encoding */

#ವ್ಯಾಖ್ಯಾನಿಸು OPCT_ಮುಖವಾಡ      0x70
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_FWAIT      0x10 /* add fwait opcode */
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_ಸರಿಸು      0x20 /* shift opcodes */
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_ARITH      0x30 /* arithmetic opcodes */
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_FARITH     0x40 /* FPU arithmetic opcodes */
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_TEST       0x50 /* test opcodes */
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_0F01       0x60 /* 0x0f01XX (group 7, XX is 2nd opcode,
                               no operands and unstructured mod/rm) */
#ವ್ಯಾಖ್ಯಾನಿಸು OPCT_IS(v,i) (((v) & OPCT_ಮುಖವಾಡ) == (i))

#ವ್ಯಾಖ್ಯಾನಿಸು OPC_0F        0x100 /* Is secondary map (0x0f prefix) */
#ವ್ಯಾಖ್ಯಾನಿಸು OPC_48        0x200 /* Always has REX prefix */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
# define OPC_WLQ     0x1000  /* accepts w, l, q or no suffix */
# define OPC_BWLQ    (OPC_B | OPC_WLQ) /* accepts b, w, l, q or no suffix */
# define OPC_WLX     OPC_WLQ
# define OPC_BWLX    OPC_BWLQ
#ಇಲ್ಲದಿದ್ದರೆ
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು OPC_ಗುಂಪು_ಸರಿಸು 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
ಎಣಿಕೆ {
    OPT_REG8=0, /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG16,  /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG32,  /* warning: value is hardcoded from TOK_ASM_xxx */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    OPT_REG64,  /* warning: value is hardcoded from TOK_ASM_xxx */
#ಆದರೆ_ಅಂತ್ಯ
    OPT_MMX,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SSE,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_CR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_TR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_DB,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SEG,
    OPT_ST,
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    OPT_REG8_ಕೆಳಗಿನ, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
		     with REX prefix, not used in insn templates */
#ಆದರೆ_ಅಂತ್ಯ
    OPT_IM8,
    OPT_IM8S,
    OPT_IM16,
    OPT_IM32,
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    OPT_IM64,
#ಆದರೆ_ಅಂತ್ಯ
    OPT_EAX,    /* %al, %ax, %eax or %rax register */
    OPT_ST0,    /* %st(0) register */
    OPT_CL,     /* %cl register */
    OPT_DX,     /* %dx register */
    OPT_ADDR,   /* OP_EA with only offset */
    OPT_INDIR,  /* *(expr) */
    /* composite types */
    OPT_ಸಂಯುಕ್ತ_ಮೊದಲ,
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

#ವ್ಯಾಖ್ಯಾನಿಸು OP_REG8   (1 << OPT_REG8)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_REG16  (1 << OPT_REG16)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_REG32  (1 << OPT_REG32)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_MMX    (1 << OPT_MMX)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_SSE    (1 << OPT_SSE)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_CR     (1 << OPT_CR)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_TR     (1 << OPT_TR)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_DB     (1 << OPT_DB)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_SEG    (1 << OPT_SEG)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_ST     (1 << OPT_ST)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_IM8    (1 << OPT_IM8)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_IM8S   (1 << OPT_IM8S)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_IM16   (1 << OPT_IM16)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_IM32   (1 << OPT_IM32)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_EAX    (1 << OPT_EAX)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_ST0    (1 << OPT_ST0)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_CL     (1 << OPT_CL)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_DX     (1 << OPT_DX)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_ADDR   (1 << OPT_ADDR)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_INDIR  (1 << OPT_INDIR)
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
# define OP_REG64 (1 << OPT_REG64)
# define OP_REG8_ಕೆಳಗಿನ (1 << OPT_REG8_ಕೆಳಗಿನ)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#ಇಲ್ಲದಿದ್ದರೆ
# define OP_REG64 0
# define OP_REG8_ಕೆಳಗಿನ 0
# define OP_IM64  0
# define OP_EA32  0
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು OP_EA     0x40000000u
#ವ್ಯಾಖ್ಯಾನಿಸು OP_REG    (OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
# define TREG_XAX   TREG_RAX
# define TREG_XCX   TREG_RCX
# define TREG_XDX   TREG_RDX
# define TOK_ASM_xax TOK_ASM_rax
#ಇಲ್ಲದಿದ್ದರೆ
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಕಾರ್ಯಾಂಶ {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t ಸರಿಸು;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
} ಕಾರ್ಯಾಂಶ;

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t reg_ಗಮ್ಯ_ಗಾತ್ರ[9] = {
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

#ವ್ಯಾಖ್ಯಾನಿಸು NB_TEST_OPCODES 30

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t test_ಬಿಟ್ಟುಗಳು[NB_TEST_OPCODES] = {
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

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ASMInstr asm_instrs[] = {
#ವ್ಯಾಖ್ಯಾನಿಸು ALT(x) x
/* This removes a 0x0f in the second byte */
#ವ್ಯಾಖ್ಯಾನಿಸು O(o) ((uint64_t) ((((o) & 0xff00) == 0x0f00) ? ((((o) >> 8) & ~0xff) | ((o) & 0xff)) : (o)))
/* This constructs instr_type from opcode, type and group.  */
#ವ್ಯಾಖ್ಯಾನಿಸು T(o,i,g) ((i) | ((g) << OPC_ಗುಂಪು_ಸರಿಸು) | ((((o) & 0xff00) == 0x0f00) ? OPC_0F : 0))
#ವ್ಯಾಖ್ಯಾನಿಸು DEF_ASM_OP0(name, opcode)
#ವ್ಯಾಖ್ಯಾನಿಸು DEF_ASM_OP0L(name, opcode, ಗುಂಪು, instr_type) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, ಗುಂಪು), 0, { 0 } },
#ವ್ಯಾಖ್ಯಾನಿಸು DEF_ASM_OP1(name, opcode, ಗುಂಪು, instr_type, op0) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, ಗುಂಪು), 1, { op0 }},
#ವ್ಯಾಖ್ಯಾನಿಸು DEF_ASM_OP2(name, opcode, ಗುಂಪು, instr_type, op0, op1) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, ಗುಂಪು), 2, { op0, op1 }},
#ವ್ಯಾಖ್ಯಾನಿಸು DEF_ASM_OP3(name, opcode, ಗುಂಪು, instr_type, op0, op1, op2) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, ಗುಂಪು), 3, { op0, op1, op2 }},
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
# include "x86_64-asm.h"
#ಇಲ್ಲದಿದ್ದರೆ
# include "i386-asm.h"
#ಆದರೆ_ಅಂತ್ಯ
    /* last operation */
    { 0, },
};

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint16_t op0_codes[] = {
#ವ್ಯಾಖ್ಯಾನಿಸು ALT(x)
#ವ್ಯಾಖ್ಯಾನಿಸು DEF_ASM_OP0(x, opcode) opcode,
#ವ್ಯಾಖ್ಯಾನಿಸು DEF_ASM_OP0L(name, opcode, ಗುಂಪು, instr_type)
#ವ್ಯಾಖ್ಯಾನಿಸು DEF_ASM_OP1(name, opcode, ಗುಂಪು, instr_type, op0)
#ವ್ಯಾಖ್ಯಾನಿಸು DEF_ASM_OP2(name, opcode, ಗುಂಪು, instr_type, op0, op1)
#ವ್ಯಾಖ್ಯಾನಿಸು DEF_ASM_OP3(name, opcode, ಗುಂಪು, instr_type, op0, op1, op2)
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
# include "x86_64-asm.h"
#ಇಲ್ಲದಿದ್ದರೆ
# include "i386-asm.h"
#ಆದರೆ_ಅಂತ್ಯ
};

ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ get_reg_ಸರಿಸು(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ ಸರಿಸು, v;
    v = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
    ಆಯ್ಕೆ(v) {
    ಸ್ಥಿತಿ 1:
        ಸರಿಸು = 0;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 2:
        ಸರಿಸು = 1;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 4:
        ಸರಿಸು = 2;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 8:
        ಸರಿಸು = 3;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("1, 2, 4 or 8 constant");
        ಸರಿಸು = 0;
        ನಿಲ್ಲಿಸು;
    }
    ಹಿಂತಿರುಗಿ ಸರಿಸು;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asm_parse_numeric_reg(ಪೂರ್ಣಾಂಕ t, ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *type)
{
    ಪೂರ್ಣಾಂಕ reg = -1;
    ಆದರೆ (t >= TOK_IDENT && t < tok_ident) {
	ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s = ಕೋಷ್ಟಕ_ident[t - TOK_IDENT]->str;
	ಅಕ್ಷರ c;
	*type = OP_REG64;
	ಆದರೆ (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	ಆದರೆ (*s++ != 'r')
	  ಹಿಂತಿರುಗಿ -1;
	/* Don't allow leading '0'.  */
	ಆದರೆ ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	ಇಲ್ಲದಿದ್ದರೆ
	  ಹಿಂತಿರುಗಿ -1;
	ಆದರೆ ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	ಆದರೆ (reg > 15)
	  ಹಿಂತಿರುಗಿ -1;
	ಆದರೆ ((c = *s) == 0)
	  ;
	ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*type != OP_REG64)
	  ಹಿಂತಿರುಗಿ -1;
	ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == 'b' && !s[1])
	  *type = OP_REG8;
	ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == 'w' && !s[1])
	  *type = OP_REG16;
	ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == 'd' && !s[1])
	  *type = OP_REG32;
	ಇಲ್ಲದಿದ್ದರೆ
	  ಹಿಂತಿರುಗಿ -1;
    }
    ಹಿಂತಿರುಗಿ reg;
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asm_parse_reg(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *type)
{
    ಪೂರ್ಣಾಂಕ reg = 0;
    *type = 0;
    ಆದರೆ (tok != '%')
        ಹೋಗು error_32;
    ಮುಂದಿನ();
    ಆದರೆ (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#ಆದರೆ_ಅಂತ್ಯ
    } ಇಲ್ಲದಿದ್ದರೆ {
    error_32:
        expect("register");
    }
    ಮುಂದಿನ();
    ಹಿಂತಿರುಗಿ reg;
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op)
{
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    ಪೂರ್ಣಾಂಕ reg, indir;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;

    indir = 0;
    ಆದರೆ (tok == '*') {
        ಮುಂದಿನ();
        indir = OP_INDIR;
    }

    ಆದರೆ (tok == '%') {
        ಮುಂದಿನ();
        ಆದರೆ (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            ಆದರೆ ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            ಮುಂದಿನ();
            ಆದರೆ (tok == '(') {
                ಮುಂದಿನ();
                ಆದರೆ (tok != TOK_PPNUM)
                    ಹೋಗು reg_error;
                p = tokc.str.ದತ್ತಾಂಶ;
                reg = p[0] - '0';
                ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ)reg >= 8 || p[1] != '\0')
                    ಹೋಗು reg_error;
                op->reg = reg;
                ಮುಂದಿನ();
                skip(')');
            }
            ಆದರೆ (op->reg == 0)
                op->type |= OP_ST0;
            ಹೋಗು no_skip;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
	} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_ಕೆಳಗಿನ;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        ಮುಂದಿನ();
    no_skip: ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == '$') {
        /* constant value */
        ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        ಆದರೆ (!op->e.sym) {
            ಆದರೆ (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            ಆದರೆ (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            ಆದರೆ (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
            ಆದರೆ (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#ಆದರೆ_ಅಂತ್ಯ
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->ಸರಿಸು = 0;
        ಆದರೆ (tok != '(') {
            asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
            op->e = e;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಮುಂದಿನ();
            ಆದರೆ (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = ಖಾಲಿ;
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* bracketed offset expression */
                asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
                ಆದರೆ (tok != ')')
                    expect(")");
                ಮುಂದಿನ();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        ಆದರೆ (tok == '(') {
	    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ type = 0;
            ಮುಂದಿನ();
            ಆದರೆ (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            ಆದರೆ (tok == ',') {
                ಮುಂದಿನ();
                ಆದರೆ (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                ಆದರೆ (tok == ',') {
                    ಮುಂದಿನ();
                    op->ಸರಿಸು = get_reg_ಸರಿಸು(s1);
                }
            }
	    ಆದರೆ (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        ಆದರೆ (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    ಆದರೆ (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    ಇಲ್ಲದಿದ್ದರೆ
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
ಸ್ಥಿರ ಶೂನ್ಯ gen_disp32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    ಆದರೆ (esym && esym->st_shndx == cur_ಪಠ್ಯ_section->sh_ಅಂಕೆ) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_ಮೌಲ್ಯ - ind - 4);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = ಖಾಲಿ;
        }
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
        greloca(cur_ಪಠ್ಯ_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#ಇಲ್ಲದಿದ್ದರೆ
        gen_addrpc32(VT_SYM, sym, pe->v);
#ಆದರೆ_ಅಂತ್ಯ

    }
}

/* generate the modrm operand */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ asm_modrm(ಪೂರ್ಣಾಂಕ reg, ಕಾರ್ಯಾಂಶ *op)
{
    ಪೂರ್ಣಾಂಕ mod, reg1, reg2, sib_reg1;

    ಆದರೆ (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#ಇಲ್ಲದಿದ್ದರೆ
	g(0x05 + (reg << 3));
#ಆದರೆ_ಅಂತ್ಯ
	gen_expr32(&op->e);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op->reg == -2) {
        ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        ಹಿಂತಿರುಗಿ ind;
#ಆದರೆ_ಅಂತ್ಯ
    } ಇಲ್ಲದಿದ್ದರೆ {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        ಆದರೆ (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } ಇಲ್ಲದಿದ್ದರೆ {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        ಆದರೆ (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        ಆದರೆ (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            ಆದರೆ (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->ಸರಿಸು << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        ಆದರೆ (mod == 0x40) {
            g(op->e.v);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    ಹಿಂತಿರುಗಿ 0;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
#ವ್ಯಾಖ್ಯಾನಿಸು REX_W 0x48
#ವ್ಯಾಖ್ಯಾನಿಸು REX_R 0x44
#ವ್ಯಾಖ್ಯಾನಿಸು REX_X 0x42
#ವ್ಯಾಖ್ಯಾನಿಸು REX_B 0x41

ಸ್ಥಿರ ಶೂನ್ಯ asm_rex(ಪೂರ್ಣಾಂಕ width64, ಕಾರ್ಯಾಂಶ *ops, ಪೂರ್ಣಾಂಕ nb_ops, ಪೂರ್ಣಾಂಕ *op_type,
		    ಪೂರ್ಣಾಂಕ regi, ಪೂರ್ಣಾಂಕ rmi)
{
  ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ rex = width64 ? 0x48 : 0;
  ಪೂರ್ಣಾಂಕ saw_ಮೇಲಿನ_8bit = 0;
  ಪೂರ್ಣಾಂಕ i;
  ಆದರೆ (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      ಗಾಗಿ(i = 0; i < nb_ops; i++) {
	  ಆದರೆ (op_type[i] & (OP_REG | OP_ST)) {
	      ಆದರೆ (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[i].type & OP_REG8_ಕೆಳಗಿನ)
		  rex |= 0x40;
	      ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_ಮೇಲಿನ_8bit = ops[i].reg;
	      ನಿಲ್ಲಿಸು;
	  }
      }
  } ಇಲ್ಲದಿದ್ದರೆ {
      ಆದರೆ (regi != -1) {
	  ಆದರೆ (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[regi].type & OP_REG8_ಕೆಳಗಿನ)
	      rex |= 0x40;
	  ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_ಮೇಲಿನ_8bit = ops[regi].reg;
      }
      ಆದರೆ (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  ಆದರೆ (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[rmi].type & OP_REG8_ಕೆಳಗಿನ)
	      rex |= 0x40;
	  ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_ಮೇಲಿನ_8bit = ops[rmi].reg;
      }
      ಆದರೆ (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  ಆದರೆ (rex) {
      ಆದರೆ (saw_ಮೇಲಿನ_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_ಮೇಲಿನ_8bit-4]);
      g(rex);
  }
}
#ಆದರೆ_ಅಂತ್ಯ


ಸ್ಥಿರ ಶೂನ್ಯ maybe_print_stats (ಶೂನ್ಯ)
{
    ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ already;

    ಆದರೆ (0 && !already)
    /* print stats about opcodes */
    {
        ಸ್ಥಿರಾಂಕ ರಚನೆ ASMInstr *pa;
        ಪೂರ್ಣಾಂಕ freq[4];
        ಪೂರ್ಣಾಂಕ op_vals[500];
        ಪೂರ್ಣಾಂಕ nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, ಗಾತ್ರ(freq));
        ಗಾಗಿ(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                ಗಾಗಿ(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    ಆದರೆ (pa->instr_type == op_vals[j])
                        ಹೋಗು ಸಿಕ್ಕಿತು;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            ಸಿಕ್ಕಿತು: ;
            //}
        }
        ಗಾಗಿ(i=0;i<nb_op_vals;i++) {
            ಪೂರ್ಣಾಂಕ v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                ಬರೆ("%3d: %08x\n", i, v);
        }
        ಬರೆ("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (ಪೂರ್ಣಾಂಕ)ಗಾತ್ರ(asm_instrs),
	       (ಪೂರ್ಣಾಂಕ)ಗಾತ್ರ(asm_instrs) / (ಪೂರ್ಣಾಂಕ)ಗಾತ್ರ(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ opcode)
{
    ಸ್ಥಿರಾಂಕ ASMInstr *pa;
    ಪೂರ್ಣಾಂಕ i, modrm_ಸೂಚ್ಯಂಕ, modreg_ಸೂಚ್ಯಂಕ, reg, v, op1, seg_ಪೂರ್ವಪ್ರತ್ಯಯ, pc, p;
    ಪೂರ್ಣಾಂಕ nb_ops, s;
    ಕಾರ್ಯಾಂಶ ops[MAX_OPERANDS], *ತೆಗೆ;
    ಪೂರ್ಣಾಂಕ op_type[3]; /* decoded op type */
    ಪೂರ್ಣಾಂಕ alltypes;   /* OR of all operand types */
    ಪೂರ್ಣಾಂಕ autosize;
    ಪೂರ್ಣಾಂಕ p66;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    ಪೂರ್ಣಾಂಕ rex64;
#ಆದರೆ_ಅಂತ್ಯ

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    ಆದರೆ (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    ತೆಗೆ = ops;
    nb_ops = 0;
    seg_ಪೂರ್ವಪ್ರತ್ಯಯ = 0;
    alltypes = 0;
    ಗಾಗಿ(;;) {
        ಆದರೆ (tok == ';' || tok == TOK_LINEFEED)
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_ಕಾರ್ಯಾಂಶ(s1, ತೆಗೆ);
        ಆದರೆ (tok == ':') {
           ಆದರೆ (!(ತೆಗೆ->type & OP_SEG) || seg_ಪೂರ್ವಪ್ರತ್ಯಯ)
               tcc_error("incorrect prefix");
           seg_ಪೂರ್ವಪ್ರತ್ಯಯ = segment_prefixes[ತೆಗೆ->reg];
           ಮುಂದಿನ();
           parse_ಕಾರ್ಯಾಂಶ(s1, ತೆಗೆ);
           ಆದರೆ (!(ತೆಗೆ->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        ತೆಗೆ++;
        nb_ops++;
        ಆದರೆ (tok != ',')
            ನಿಲ್ಲಿಸು;
        ಮುಂದಿನ();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    ಗಾಗಿ(pa = asm_instrs; pa->sym != 0; pa++) {
	ಪೂರ್ಣಾಂಕ it = pa->instr_type & OPCT_ಮುಖವಾಡ;
        s = 0;
        ಆದರೆ (it == OPC_FARITH) {
            v = opcode - pa->sym;
            ಆದರೆ (!((ಚಿಹ್ನೆರಹಿತ)v < 8 * 6 && (v % 6) == 0))
                ಮುಂದುವರಿ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (it == OPC_ARITH) {
            ಆದರೆ (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                ಮುಂದುವರಿ;
            s = (opcode - pa->sym) % NBWLX;
	    ಆದರೆ ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		ಆದರೆ (((opcode - pa->sym + 1) % NBWLX) == 0)
		    ಮುಂದುವರಿ;
	        s++;
	      }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (it == OPC_ಸರಿಸು) {
            ಆದರೆ (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                ಮುಂದುವರಿ;
            s = (opcode - pa->sym) % NBWLX;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (it == OPC_TEST) {
            ಆದರೆ (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                ಮುಂದುವರಿ;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    ಆದರೆ (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (pa->instr_type & OPC_B) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    ಆದರೆ ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        ಮುಂದುವರಿ;
#ಆದರೆ_ಅಂತ್ಯ
            ಆದರೆ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                ಮುಂದುವರಿ;
            s = opcode - pa->sym;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (pa->instr_type & OPC_WLX) {
            ಆದರೆ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                ಮುಂದುವರಿ;
            s = opcode - pa->sym + 1;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (pa->sym != opcode)
                ಮುಂದುವರಿ;
        }
        ಆದರೆ (pa->nb_ops != nb_ops)
            ಮುಂದುವರಿ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	ಆದರೆ (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    ಮುಂದುವರಿ;
#ಆದರೆ_ಅಂತ್ಯ
        /* now decode and check each operand */
	alltypes = 0;
        ಗಾಗಿ(i = 0; i < nb_ops; i++) {
            ಪೂರ್ಣಾಂಕ op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            ಆಯ್ಕೆ(op2) {
            ಸ್ಥಿತಿ OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ OPT_IMW:
                v = OP_IM16 | OP_IM32;
                ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ OPT_DISP:
	    ಸ್ಥಿತಿ OPT_DISP8:
		v = OP_ADDR;
		ನಿಲ್ಲಿಸು;
            ಪೂರ್ವನಿಯೋಜಿತ:
                v = 1 << op2;
                ನಿಲ್ಲಿಸು;
            }
            ಆದರೆ (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            ಆದರೆ ((ops[i].type & v) == 0)
                ಹೋಗು ಮುಂದಿನ;
	    alltypes |= ops[i].type;
        }
        (ಶೂನ್ಯ)alltypes; /* maybe unused */
        /* all is matching ! */
        ನಿಲ್ಲಿಸು;
    ಮುಂದಿನ: ;
    }
    ಆದರೆ (pa->sym == 0) {
        ಆದರೆ (opcode >= TOK_ASM_ಮೊದಲ && opcode <= TOK_ASM_ಕೊನೆಯ) {
            ಪೂರ್ಣಾಂಕ b;
            b = op0_codes[opcode - TOK_ASM_ಮೊದಲ];
            ಆದರೆ (b & 0xff00)
                g(b >> 8);
            g(b);
            ಹಿಂತಿರುಗಿ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, ಖಾಲಿ));
        } ಇಲ್ಲದಿದ್ದರೆ {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = ಕೋಷ್ಟಕ_ident[opcode - TOK_IDENT];
	    ಆದರೆ (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		ಹೋಗು again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    ಆದರೆ ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        ಗಾಗಿ(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            ಆದರೆ ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_ಗಮ್ಯ_ಗಾತ್ರ[ops[i].type & OP_REG];
        }
        ಆದರೆ (s == autosize) {
            ಆದರೆ ((opcode == TOK_ASM_ತಳ್ಳು || opcode == TOK_ASM_ತೆಗೆ) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((opcode == TOK_ASM_ತಳ್ಳು || opcode == TOK_ASM_ತೆಗೆ) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            ಇಲ್ಲದಿದ್ದರೆ
                tcc_error("cannot infer opcode suffix");
        }
    }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    rex64 = 0;
    ಆದರೆ (pa->instr_type & OPC_48)
        rex64 = 1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	ಪೂರ್ಣಾಂಕ default64 = 0;
	ಗಾಗಿ(i = 0; i < nb_ops; i++) {
	    ಆದರೆ (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		ನಿಲ್ಲಿಸು;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        ಆದರೆ (((opcode != TOK_ASM_ತಳ್ಳು && opcode != TOK_ASM_ತೆಗೆ
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#ಆದರೆ_ಅಂತ್ಯ

    /* now generates the operation */
    ಆದರೆ (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    ಆದರೆ (seg_ಪೂರ್ವಪ್ರತ್ಯಯ)
        g(seg_ಪೂರ್ವಪ್ರತ್ಯಯ);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    /* Generate addr32 prefix if needed */
    ಗಾಗಿ(i = 0; i < nb_ops; i++) {
        ಆದರೆ (ops[i].type & OP_EA32) {
	    g(0x67);
	    ನಿಲ್ಲಿಸು;
        }
    }
#ಆದರೆ_ಅಂತ್ಯ
    /* generate data16 prefix if needed */
    p66 = 0;
    ಆದರೆ (s == 1)
        p66 = 1;
    ಇಲ್ಲದಿದ್ದರೆ {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        ಗಾಗಿ (i = 0; i < nb_ops; i++)
            ಆದರೆ ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    ಆದರೆ (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    ಆಯ್ಕೆ (p) {
        ಸ್ಥಿತಿ 0: ನಿಲ್ಲಿಸು;  /* no prefix */
        ಸ್ಥಿತಿ 0x48: ನಿಲ್ಲಿಸು; /* REX, handled elsewhere */
        ಸ್ಥಿತಿ 0x66:
        ಸ್ಥಿತಿ 0x67:
        ಸ್ಥಿತಿ 0xf2:
        ಸ್ಥಿತಿ 0xf3: v = v & 0xff; g(p); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 0xd4: ಸ್ಥಿತಿ 0xd5: ನಿಲ್ಲಿಸು; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        ಸ್ಥಿತಿ 0xd8: ಸ್ಥಿತಿ 0xd9: ಸ್ಥಿತಿ 0xda: ಸ್ಥಿತಿ 0xdb: /* x87, no normal prefix */
        ಸ್ಥಿತಿ 0xdc: ಸ್ಥಿತಿ 0xdd: ಸ್ಥಿತಿ 0xde: ಸ್ಥಿತಿ 0xdf: ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ: tcc_error("bad prefix 0x%2x in opcode table", p); ನಿಲ್ಲಿಸು;
    }
    ಆದರೆ (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    ಆದರೆ ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((v == 0x06 || v == 0x07)) {
        ಆದರೆ (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } ಇಲ್ಲದಿದ್ದರೆ {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((pa->instr_type & (OPCT_ಮುಖವಾಡ | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_ಸೂಚ್ಯಂಕ = -1;
    modreg_ಸೂಚ್ಯಂಕ = -1;
    ಆದರೆ (pa->instr_type & OPC_MODRM) {
	ಆದರೆ (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
	    ಆದರೆ (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#ಇಲ್ಲದಿದ್ದರೆ
	    ಆದರೆ (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#ಆದರೆ_ಅಂತ್ಯ
	    ಇಲ್ಲದಿದ್ದರೆ
	      tcc_error("bad MODR/M opcode without operands");
	    ಹೋಗು modrm_ಸಿಕ್ಕಿತು;
	}
        /* first look for an ea operand */
        ಗಾಗಿ(i = 0;i < nb_ops; i++) {
            ಆದರೆ (op_type[i] & OP_EA)
                ಹೋಗು modrm_ಸಿಕ್ಕಿತು;
        }
        /* then if not found, a register or indirection (shift instructions) */
        ಗಾಗಿ(i = 0;i < nb_ops; i++) {
            ಆದರೆ (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                ಹೋಗು modrm_ಸಿಕ್ಕಿತು;
        }
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ASM_DEBUG
        tcc_error("bad op table");
#ಆದರೆ_ಅಂತ್ಯ
    modrm_ಸಿಕ್ಕಿತು:
        modrm_ಸೂಚ್ಯಂಕ = i;
        /* if a register is used in another operand then it is
           used instead of group */
        ಗಾಗಿ(i = 0;i < nb_ops; i++) {
            ಪೂರ್ಣಾಂಕ t = op_type[i];
            ಆದರೆ (i != modrm_ಸೂಚ್ಯಂಕ &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_ಸೂಚ್ಯಂಕ = i;
                ನಿಲ್ಲಿಸು;
            }
        }
    }
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_ಸೂಚ್ಯಂಕ, modrm_ಸೂಚ್ಯಂಕ);
#ಆದರೆ_ಅಂತ್ಯ

    ಆದರೆ (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        ಆದರೆ (v == 0xb0 && s >= 1)
            v += 7;
        ಗಾಗಿ(i = 0; i < nb_ops; i++) {
            ಆದರೆ (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                ನಿಲ್ಲಿಸು;
            }
        }
    }
    ಆದರೆ (pa->instr_type & OPC_B)
        v += s >= 1;
    ಆದರೆ (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        ಪೂರ್ಣಾಂಕ jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        ಆದರೆ (!esym || esym->st_shndx != cur_ಪಠ್ಯ_section->sh_ಅಂಕೆ)
            ಹೋಗು no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_ಮೌಲ್ಯ - ind - 2 - (v >= 0xff);
        ಆದರೆ (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } ಇಲ್ಲದಿದ್ದರೆ {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    ಆದರೆ (v == 0xeb) /* jmp */
	        v = 0xe9;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == 0x70) /* jcc */
	        v += 0x0f10;
	    ಇಲ್ಲದಿದ್ದರೆ
	        tcc_error("invalid displacement");
        }
    }
    ಆದರೆ (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_ಬಿಟ್ಟುಗಳು[opcode - pa->sym];
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    ಆದರೆ (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    ಆದರೆ (op1)
        g(op1);
    g(v);

    ಆದರೆ (OPCT_IS(pa->instr_type, OPC_ಸರಿಸು)) {
        reg = (opcode - pa->sym) / NBWLX;
        ಆದರೆ (reg == 6)
            reg = 7;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } ಇಲ್ಲದಿದ್ದರೆ {
        reg = (pa->instr_type >> OPC_ಗುಂಪು_ಸರಿಸು) & 7;
    }

    pc = 0;
    ಆದರೆ (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	ಆದರೆ (modreg_ಸೂಚ್ಯಂಕ >= 0)
	    reg = ops[modreg_ಸೂಚ್ಯಂಕ].reg;
        pc = asm_modrm(reg, &ops[modrm_ಸೂಚ್ಯಂಕ]);
    }

    /* emit constants */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_X86_64
    ಆದರೆ (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        ಆದರೆ (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        ಹಿಂತಿರುಗಿ;
    }
#ಆದರೆ_ಅಂತ್ಯ
    ಗಾಗಿ(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        ಆದರೆ (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            ಆದರೆ ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                ಆದರೆ (s == 0)
                    v = OP_IM8;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == 1)
                    v = OP_IM16;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                ಇಲ್ಲದಿದ್ದರೆ
                    v = OP_IM64;
            }

            ಆದರೆ ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            ಆದರೆ (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#ಆದರೆ_ಅಂತ್ಯ
	    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } ಇಲ್ಲದಿದ್ದರೆ {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    ಆದರೆ (pc)
        add32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ constraint_ಆದ್ಯತೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಪೂರ್ಣಾಂಕ ಆದ್ಯತೆ, c, pr;

    /* we take the lowest priority */
    ಆದ್ಯತೆ = 0;
    ಗಾಗಿ(;;) {
        c = *str;
        ಆದರೆ (c == '\0')
            ನಿಲ್ಲಿಸು;
        str++;
        ಆಯ್ಕೆ(c) {
        ಸ್ಥಿತಿ 'A':
            pr = 0;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'a':
        ಸ್ಥಿತಿ 'b':
        ಸ್ಥಿತಿ 'c':
        ಸ್ಥಿತಿ 'd':
        ಸ್ಥಿತಿ 'S':
        ಸ್ಥಿತಿ 'D':
            pr = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'q':
            pr = 2;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'r':
	ಸ್ಥಿತಿ 'R':
	ಸ್ಥಿತಿ 'p':
            pr = 3;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'N':
        ಸ್ಥಿತಿ 'M':
        ಸ್ಥಿತಿ 'I':
	ಸ್ಥಿತಿ 'e':
        ಸ್ಥಿತಿ 'i':
        ಸ್ಥಿತಿ 'm':
        ಸ್ಥಿತಿ 'g':
            pr = 4;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        ಆದರೆ (pr > ಆದ್ಯತೆ)
            ಆದ್ಯತೆ = pr;
    }
    ಹಿಂತಿರುಗಿ ಆದ್ಯತೆ;
}

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *skip_constraint_modifiers(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p)
{
    ಆಗ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ಹಿಂತಿರುಗಿ p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC ಪೂರ್ಣಾಂಕ asm_parse_regvar (ಪೂರ್ಣಾಂಕ t)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s;
    ಕಾರ್ಯಾಂಶ op;
    ಆದರೆ (t < TOK_IDENT || (t & SYM_ಕ್ಷೇತ್ರ))
        ಹಿಂತಿರುಗಿ -1;
    s = ಕೋಷ್ಟಕ_ident[t - TOK_IDENT]->str;
    ಆದರೆ (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_ಕಾರ್ಯಾಂಶ(tcc_state, &op);
    /* Accept only integer regs for now. */
    ಆದರೆ (op.type & OP_REG)
        ಹಿಂತಿರುಗಿ op.reg;
    ಇಲ್ಲದಿದ್ದರೆ
        ಹಿಂತಿರುಗಿ -1;
}

#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಹೊರಹೋಗು_ಮುಖವಾಡ 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಒಳ_ಮುಖವಾಡ  0x02

#ವ್ಯಾಖ್ಯಾನಿಸು is_reg_allocated(reg) (regs_allocated[reg] & reg_ಮುಖವಾಡ)

ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands,
                                    ಪೂರ್ಣಾಂಕ nb_operands, ಪೂರ್ಣಾಂಕ nb_outputs,
                                    ಸ್ಥಿರಾಂಕ uint8_t *clobber_regs,
                                    ಪೂರ್ಣಾಂಕ *pout_reg)
{
    ASMOperand *op;
    ಪೂರ್ಣಾಂಕ sorted_op[MAX_ASM_OPERANDS];
    ಪೂರ್ಣಾಂಕ i, j, k, p1, p2, tmp, reg, c, reg_ಮುಖವಾಡ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ಗಾಗಿ(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ = -1;
        op->ref_ಸೂಚ್ಯಂಕ = -1;
        op->reg = -1;
        op->is_ಸ್ಮರಣೆ = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ಗಾಗಿ(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ಆದರೆ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = ಕಂಡುಹಿಡಿ_constraint(operands, nb_operands, str, ಖಾಲಿ);
            ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_ಸೂಚ್ಯಂಕ = k;
            ಆದರೆ (operands[k].ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ = i;
            op->ಆದ್ಯತೆ = 5;
	} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->ಆದ್ಯತೆ = 1;
	    op->reg = reg;
        } ಇಲ್ಲದಿದ್ದರೆ {
            op->ಆದ್ಯತೆ = constraint_ಆದ್ಯತೆ(str);
        }
    }

    /* sort operands according to their priority */
    ಗಾಗಿ(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    ಗಾಗಿ(i=0;i<nb_operands - 1;i++) {
        ಗಾಗಿ(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].ಆದ್ಯತೆ;
            p2 = operands[sorted_op[j]].ಆದ್ಯತೆ;
            ಆದರೆ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ಗಾಗಿ(i = 0;i < NB_ASM_REGS; i++) {
        ಆದರೆ (clobber_regs[i])
            regs_allocated[i] = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
        ಇಲ್ಲದಿದ್ದರೆ
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;

    /* allocate registers and generate corresponding asm moves */
    ಗಾಗಿ(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ಆದರೆ (op->ref_ಸೂಚ್ಯಂಕ >= 0)
            ಮುಂದುವರಿ;
        /* select if register is used for output, input or both */
        ಆದರೆ (op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ >= 0) {
            reg_ಮುಖವಾಡ = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (j < nb_outputs) {
            reg_ಮುಖವಾಡ = REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            reg_ಮುಖವಾಡ = REG_ಒಳ_ಮುಖವಾಡ;
        }
	ಆದರೆ (op->reg >= 0) {
	    ಆದರೆ (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_ಮುಂದಿನ:
        c = *str++;
        ಆಯ್ಕೆ(c) {
        ಸ್ಥಿತಿ '=':
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ '+':
            op->is_rw = 1;
            /* FALL THRU */
        ಸ್ಥಿತಿ '&':
            ಆದರೆ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_ಮುಖವಾಡ = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ 'A':
            /* allocate both eax and edx */
            ಆದರೆ (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                ಹೋಗು try_ಮುಂದಿನ;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_ಮುಖವಾಡ;
            regs_allocated[TREG_XDX] |= reg_ಮುಖವಾಡ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'a':
            reg = TREG_XAX;
            ಹೋಗು alloc_reg;
        ಸ್ಥಿತಿ 'b':
            reg = 3;
            ಹೋಗು alloc_reg;
        ಸ್ಥಿತಿ 'c':
            reg = TREG_XCX;
            ಹೋಗು alloc_reg;
        ಸ್ಥಿತಿ 'd':
            reg = TREG_XDX;
            ಹೋಗು alloc_reg;
        ಸ್ಥಿತಿ 'S':
            reg = 6;
            ಹೋಗು alloc_reg;
        ಸ್ಥಿತಿ 'D':
            reg = 7;
        alloc_reg:
            ಆದರೆ (op->reg >= 0 && reg != op->reg)
                ಹೋಗು try_ಮುಂದಿನ;
            ಆದರೆ (is_reg_allocated(reg))
                ಹೋಗು try_ಮುಂದಿನ;
            ಹೋಗು reg_ಸಿಕ್ಕಿತು;
        ಸ್ಥಿತಿ 'q':
            /* eax, ebx, ecx or edx */
            ಆದರೆ (op->reg >= 0) {
                ಆದರೆ ((reg = op->reg) < 4)
                    ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            } ಇಲ್ಲದಿದ್ದರೆ ಗಾಗಿ(reg = 0; reg < 4; reg++) {
                ಆದರೆ (!is_reg_allocated(reg))
                    ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            }
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ 'r':
	ಸ್ಥಿತಿ 'R':
	ಸ್ಥಿತಿ 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            ಆದರೆ ((reg = op->reg) >= 0)
                ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            ಇಲ್ಲದಿದ್ದರೆ ಗಾಗಿ(reg = 0; reg < NB_ASM_REGS; reg++) {
                ಆದರೆ (!is_reg_allocated(reg))
                    ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            }
            ಹೋಗು try_ಮುಂದಿನ;
        reg_ಸಿಕ್ಕಿತು:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_ಮುಖವಾಡ;
            ನಿಲ್ಲಿಸು;
	ಸ್ಥಿತಿ 'e':
        ಸ್ಥಿತಿ 'i':
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'I':
        ಸ್ಥಿತಿ 'N':
        ಸ್ಥಿತಿ 'M':
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'm':
        ಸ್ಥಿತಿ 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ಆದರೆ (j < nb_outputs || c == 'm') {
                ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    ಗಾಗಿ(reg = 0; reg < NB_ASM_REGS; reg++) {
                        ಆದರೆ (!(regs_allocated[reg] & REG_ಒಳ_ಮುಖವಾಡ))
                            ಹೋಗು reg_found1;
                    }
                    ಹೋಗು try_ಮುಂದಿನ;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_ಒಳ_ಮುಖವಾಡ;
                    op->reg = reg;
                    op->is_ಸ್ಮರಣೆ = 1;
                }
            }
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            ನಿಲ್ಲಿಸು;
        }
        /* if a reference is present for that operand, we assign it too */
        ಆದರೆ (op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ >= 0) {
            operands[op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ].reg = op->reg;
            operands[op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ಗಾಗಿ(i=0;i<nb_operands;i++) {
        op = &operands[i];
        ಆದರೆ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_ಸ್ಮರಣೆ) {
            ಗಾಗಿ(reg = 0; reg < NB_ASM_REGS; reg++) {
                ಆದರೆ (!(regs_allocated[reg] & REG_ಹೊರಹೋಗು_ಮುಖವಾಡ))
                    ಹೋಗು reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            ನಿಲ್ಲಿಸು;
        }
    }

    /* print sorted constraints */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ASM_DEBUG
    ಗಾಗಿ(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        ಬರೆ("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ಖಾಲಿ) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    ಆದರೆ (*pout_reg >= 0)
        ಬರೆ("out_reg=%d\n", *pout_reg);
#ಆದರೆ_ಅಂತ್ಯ
}

ST_FUNC ಶೂನ್ಯ subst_asm_ಕಾರ್ಯಾಂಶ(CString *ಕೂಡಿಸು_str,
                              SValue *sv, ಪೂರ್ಣಾಂಕ modifier)
{
    ಪೂರ್ಣಾಂಕ r, reg, ಗಾತ್ರ_2, val;

    r = sv->r;
    ಆದರೆ ((r & VT_VALMASK) == VT_CONST) {
        ಆದರೆ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(ಕೂಡಿಸು_str, '$');
        ಆದರೆ (r & VT_SYM) {
	    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = get_tok_str(sv->sym->v, ಖಾಲಿ);
	    ಆದರೆ (sv->sym->v >= SYM_ಮೊದಲ_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            ಆದರೆ (tcc_state->leading_underscore)
              cstr_ccat(ಕೂಡಿಸು_str, '_');
            cstr_cat(ಕೂಡಿಸು_str, name, -1);
            ಆದರೆ ((uint32_t)sv->c.i == 0)
                ಹೋಗು no_ಸ್ಥಾನಾಂತರ;
	    cstr_ccat(ಕೂಡಿಸು_str, '+');
        }
        val = sv->c.i;
        ಆದರೆ (modifier == 'n')
            val = -val;
        cstr_printf(ಕೂಡಿಸು_str, "%d", val);
    no_ಸ್ಥಾನಾಂತರ:;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
        ಆದರೆ (r & VT_LVAL)
            cstr_cat(ಕೂಡಿಸು_str, "(%rip)", -1);
#ಆದರೆ_ಅಂತ್ಯ
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(ಕೂಡಿಸು_str, "%d(%%%s)", (ಪೂರ್ಣಾಂಕ)sv->c.i, get_tok_str(TOK_ASM_xax + 5, ಖಾಲಿ));
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ಆದರೆ (reg >= VT_CONST)
            tcc_ಆಂತರಿಕ_error("");
        cstr_printf(ಕೂಡಿಸು_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, ಖಾಲಿ));
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* register case */
        reg = r & VT_VALMASK;
        ಆದರೆ (reg >= VT_CONST)
            tcc_ಆಂತರಿಕ_error("");

        /* choose register operand size */
        ಆದರೆ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            ಗಾತ್ರ_2 = 1;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            ಗಾತ್ರ_2 = 2;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            ಗಾತ್ರ_2 = 8;
#ಆದರೆ_ಅಂತ್ಯ
        ಇಲ್ಲದಿದ್ದರೆ
            ಗಾತ್ರ_2 = 4;
        ಆದರೆ (ಗಾತ್ರ_2 == 1 && reg >= 4)
            ಗಾತ್ರ_2 = 4;

        ಆದರೆ (modifier == 'b') {
            ಆದರೆ (reg >= 4)
                tcc_error("cannot use byte register");
            ಗಾತ್ರ_2 = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (modifier == 'h') {
            ಆದರೆ (reg >= 4)
                tcc_error("cannot use byte register");
            ಗಾತ್ರ_2 = -1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (modifier == 'w') {
            ಗಾತ್ರ_2 = 2;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (modifier == 'k') {
            ಗಾತ್ರ_2 = 4;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (modifier == 'q') {
            ಗಾತ್ರ_2 = 8;
#ಆದರೆ_ಅಂತ್ಯ
        }

        ಆದರೆ (reg >= 8) {
            cstr_printf(ಕೂಡಿಸು_str, "%%r%d%c", reg, (ಗಾತ್ರ_2 == 1) ? 'b' : ((ಗಾತ್ರ_2 == 2) ? 'w' : ((ಗಾತ್ರ_2 == 4) ? 'd' : ' ')));
            ಹಿಂತಿರುಗಿ;
        }
        ಆಯ್ಕೆ(ಗಾತ್ರ_2) {
        ಸ್ಥಿತಿ -1:
            reg = TOK_ASM_ah + reg;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 1:
            reg = TOK_ASM_al + reg;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 2:
            reg = TOK_ASM_ax + reg;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            reg = TOK_ASM_eax + reg;
            ನಿಲ್ಲಿಸು;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
        ಸ್ಥಿತಿ 8:
            reg = TOK_ASM_rax + reg;
            ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
        }
        cstr_printf(ಕೂಡಿಸು_str, "%%%s", get_tok_str(reg, ಖಾಲಿ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ಶೂನ್ಯ asm_gen_ಸಂಕೇತ(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands,
                         ಪೂರ್ಣಾಂಕ nb_outputs, ಪೂರ್ಣಾಂಕ is_output,
                         uint8_t *clobber_regs,
                         ಪೂರ್ಣಾಂಕ ಹೊರಹೋಗು_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ಪೂರ್ಣಾಂಕ i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#ಇಲ್ಲದಿದ್ದರೆ
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t reg_saved[] = { 3, 6, 7 };
#ಆದರೆ_ಅಂತ್ಯ

    /* mark all used registers */
    ಸ್ಮರಣೆ_ನಕಲು(regs_allocated, clobber_regs, ಗಾತ್ರ(regs_allocated));
    ಗಾಗಿ(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        ಆದರೆ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    ಆದರೆ (!is_output) {
        /* generate reg save code */
        ಗಾಗಿ(i = 0; i < ಗಾತ್ರ(reg_saved)/ಗಾತ್ರ(reg_saved[0]); i++) {
            reg = reg_saved[i];
            ಆದರೆ (regs_allocated[reg]) {
		ಆದರೆ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        ಗಾಗಿ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ಆದರೆ (op->reg >= 0) {
                ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_ಸ್ಮರಣೆ) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    ತುಂಬು(op->reg, &sv);
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    ತುಂಬು(op->reg, op->vt);
                    ಆದರೆ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        ತುಂಬು(TREG_XDX, &sv);
                    }
                }
            }
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* generate save code */
        ಗಾಗಿ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ಆದರೆ (op->reg >= 0) {
                ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ಆದರೆ (!op->is_ಸ್ಮರಣೆ) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        ತುಂಬು(ಹೊರಹೋಗು_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | ಹೊರಹೋಗು_reg;
                        store(op->reg, &sv);
                    }
                } ಇಲ್ಲದಿದ್ದರೆ {
                    store(op->reg, op->vt);
                    ಆದರೆ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        ಗಾಗಿ(i = ಗಾತ್ರ(reg_saved)/ಗಾತ್ರ(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            ಆದರೆ (regs_allocated[reg]) {
		ಆದರೆ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಪೂರ್ಣಾಂಕ reg;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ type;
#ಆದರೆ_ಅಂತ್ಯ

    ಆದರೆ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        ಹಿಂತಿರುಗಿ;
    reg = tok_alloc_const(str);
    ಆದರೆ (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#ಆದರೆ_ಅಂತ್ಯ
    } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
