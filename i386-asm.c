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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_OPERANDS 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ASM_ਪਹਿਲਾ TOK_ASM_clc
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ASM_ਆਖਰੀ TOK_ASM_emms
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ASM_alllast TOK_ASM_subps

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_B          0x01  /* only used with OPC_WL */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_WL         0x02  /* accepts w, l or no suffix */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_BWL        (OPC_B | OPC_WL) /* accepts b, w, l or no suffix */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_REG        0x04 /* register is added to opcode */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_MODRM      0x08 /* modrm encoding */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPCT_ਨਕਾਬ      0x70
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_FWAIT      0x10 /* add fwait opcode */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_ਖਿਸਕਾਓ      0x20 /* shift opcodes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_ARITH      0x30 /* arithmetic opcodes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_FARITH     0x40 /* FPU arithmetic opcodes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_TEST       0x50 /* test opcodes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_0F01       0x60 /* 0x0f01XX (group 7, XX is 2nd opcode,
                               no operands and unstructured mod/rm) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPCT_IS(v,i) (((v) & OPCT_ਨਕਾਬ) == (i))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_0F        0x100 /* Is secondary map (0x0f prefix) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_48        0x200 /* Always has REX prefix */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
# define OPC_WLQ     0x1000  /* accepts w, l, q or no suffix */
# define OPC_BWLQ    (OPC_B | OPC_WLQ) /* accepts b, w, l, q or no suffix */
# define OPC_WLX     OPC_WLQ
# define OPC_BWLX    OPC_BWLQ
#ਨਹੀਂਤਾਂ
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPC_ਸਮੂਹ_ਖਿਸਕਾਓ 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
ਗਿਣਤੀ {
    OPT_REG8=0, /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG16,  /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG32,  /* warning: value is hardcoded from TOK_ASM_xxx */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    OPT_REG64,  /* warning: value is hardcoded from TOK_ASM_xxx */
#ਜੇ_ਅੰਤ
    OPT_MMX,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SSE,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_CR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_TR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_DB,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SEG,
    OPT_ST,
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    OPT_REG8_ਨੀਵਾਂ, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
		     with REX prefix, not used in insn templates */
#ਜੇ_ਅੰਤ
    OPT_IM8,
    OPT_IM8S,
    OPT_IM16,
    OPT_IM32,
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    OPT_IM64,
#ਜੇ_ਅੰਤ
    OPT_EAX,    /* %al, %ax, %eax or %rax register */
    OPT_ST0,    /* %st(0) register */
    OPT_CL,     /* %cl register */
    OPT_DX,     /* %dx register */
    OPT_ADDR,   /* OP_EA with only offset */
    OPT_INDIR,  /* *(expr) */
    /* composite types */
    OPT_ਸੰਯੁਕਤ_ਪਹਿਲਾ,
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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_REG8   (1 << OPT_REG8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_REG16  (1 << OPT_REG16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_REG32  (1 << OPT_REG32)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_MMX    (1 << OPT_MMX)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_SSE    (1 << OPT_SSE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_CR     (1 << OPT_CR)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_TR     (1 << OPT_TR)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_DB     (1 << OPT_DB)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_SEG    (1 << OPT_SEG)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_ST     (1 << OPT_ST)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_IM8    (1 << OPT_IM8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_IM8S   (1 << OPT_IM8S)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_IM16   (1 << OPT_IM16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_IM32   (1 << OPT_IM32)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_EAX    (1 << OPT_EAX)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_ST0    (1 << OPT_ST0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_CL     (1 << OPT_CL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_DX     (1 << OPT_DX)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_ADDR   (1 << OPT_ADDR)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_INDIR  (1 << OPT_INDIR)
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
# define OP_REG64 (1 << OPT_REG64)
# define OP_REG8_ਨੀਵਾਂ (1 << OPT_REG8_ਨੀਵਾਂ)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#ਨਹੀਂਤਾਂ
# define OP_REG64 0
# define OP_REG8_ਨੀਵਾਂ 0
# define OP_IM64  0
# define OP_EA32  0
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_EA     0x40000000u
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_REG    (OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
# define TREG_XAX   TREG_RAX
# define TREG_XCX   TREG_RCX
# define TREG_XDX   TREG_RDX
# define TOK_ASM_xax TOK_ASM_rax
#ਨਹੀਂਤਾਂ
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਸੰਕਾਰਜ {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t ਖਿਸਕਾਓ;
    ਵਿਅੰਜਕ_ਮੁੱਲ e;
} ਸੰਕਾਰਜ;

ਸਥਿਰ ਅਚਲ uint8_t reg_ਮੰਜ਼ਿਲ_ਮਾਪ[9] = {
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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_TEST_OPCODES 30

ਸਥਿਰ ਅਚਲ uint8_t test_ਬਿੱਟ[NB_TEST_OPCODES] = {
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

ਸਥਿਰ ਅਚਲ uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

ਸਥਿਰ ਅਚਲ ASMInstr asm_instrs[] = {
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALT(x) x
/* This removes a 0x0f in the second byte */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ O(o) ((uint64_t) ((((o) & 0xff00) == 0x0f00) ? ((((o) >> 8) & ~0xff) | ((o) & 0xff)) : (o)))
/* This constructs instr_type from opcode, type and group.  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ T(o,i,g) ((i) | ((g) << OPC_ਸਮੂਹ_ਖਿਸਕਾਓ) | ((((o) & 0xff00) == 0x0f00) ? OPC_0F : 0))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF_ASM_OP0(name, opcode)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF_ASM_OP0L(name, opcode, ਸਮੂਹ, instr_type) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, ਸਮੂਹ), 0, { 0 } },
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF_ASM_OP1(name, opcode, ਸਮੂਹ, instr_type, op0) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, ਸਮੂਹ), 1, { op0 }},
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF_ASM_OP2(name, opcode, ਸਮੂਹ, instr_type, op0, op1) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, ਸਮੂਹ), 2, { op0, op1 }},
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF_ASM_OP3(name, opcode, ਸਮੂਹ, instr_type, op0, op1, op2) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, ਸਮੂਹ), 3, { op0, op1, op2 }},
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
# include "x86_64-asm.h"
#ਨਹੀਂਤਾਂ
# include "i386-asm.h"
#ਜੇ_ਅੰਤ
    /* last operation */
    { 0, },
};

ਸਥਿਰ ਅਚਲ uint16_t op0_codes[] = {
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALT(x)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF_ASM_OP0(x, opcode) opcode,
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF_ASM_OP0L(name, opcode, ਸਮੂਹ, instr_type)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF_ASM_OP1(name, opcode, ਸਮੂਹ, instr_type, op0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF_ASM_OP2(name, opcode, ਸਮੂਹ, instr_type, op0, op1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF_ASM_OP3(name, opcode, ਸਮੂਹ, instr_type, op0, op1, op2)
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
# include "x86_64-asm.h"
#ਨਹੀਂਤਾਂ
# include "i386-asm.h"
#ਜੇ_ਅੰਤ
};

ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ get_reg_ਖਿਸਕਾਓ(TCCState *s1)
{
    ਪੂਰਨ ਖਿਸਕਾਓ, v;
    v = asm_int_ਵਿਅੰਜਕ(s1);
    ਚੋਣ(v) {
    ਹਾਲਤ 1:
        ਖਿਸਕਾਓ = 0;
        ਰੋਕੋ;
    ਹਾਲਤ 2:
        ਖਿਸਕਾਓ = 1;
        ਰੋਕੋ;
    ਹਾਲਤ 4:
        ਖਿਸਕਾਓ = 2;
        ਰੋਕੋ;
    ਹਾਲਤ 8:
        ਖਿਸਕਾਓ = 3;
        ਰੋਕੋ;
    ਮੂਲ:
        expect("1, 2, 4 or 8 constant");
        ਖਿਸਕਾਓ = 0;
        ਰੋਕੋ;
    }
    ਵਾਪਸ ਖਿਸਕਾਓ;
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
ਸਥਿਰ ਪੂਰਨ asm_parse_numeric_reg(ਪੂਰਨ t, ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *type)
{
    ਪੂਰਨ reg = -1;
    ਜੇ (t >= TOK_IDENT && t < tok_ident) {
	ਅਚਲ ਅੱਖਰ *s = ਸਾਰਣੀ_ident[t - TOK_IDENT]->str;
	ਅੱਖਰ c;
	*type = OP_REG64;
	ਜੇ (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	ਜੇ (*s++ != 'r')
	  ਵਾਪਸ -1;
	/* Don't allow leading '0'.  */
	ਜੇ ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	ਨਹੀਂਤਾਂ
	  ਵਾਪਸ -1;
	ਜੇ ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	ਜੇ (reg > 15)
	  ਵਾਪਸ -1;
	ਜੇ ((c = *s) == 0)
	  ;
	ਨਹੀਂਤਾਂ ਜੇ (*type != OP_REG64)
	  ਵਾਪਸ -1;
	ਨਹੀਂਤਾਂ ਜੇ (c == 'b' && !s[1])
	  *type = OP_REG8;
	ਨਹੀਂਤਾਂ ਜੇ (c == 'w' && !s[1])
	  *type = OP_REG16;
	ਨਹੀਂਤਾਂ ਜੇ (c == 'd' && !s[1])
	  *type = OP_REG32;
	ਨਹੀਂਤਾਂ
	  ਵਾਪਸ -1;
    }
    ਵਾਪਸ reg;
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ asm_parse_reg(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *type)
{
    ਪੂਰਨ reg = 0;
    *type = 0;
    ਜੇ (tok != '%')
        ਜਾਓ error_32;
    ਅਗਲਾ();
    ਜੇ (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    } ਨਹੀਂਤਾਂ ਜੇ (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } ਨਹੀਂਤਾਂ ਜੇ ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#ਜੇ_ਅੰਤ
    } ਨਹੀਂਤਾਂ {
    error_32:
        expect("register");
    }
    ਅਗਲਾ();
    ਵਾਪਸ reg;
}

ਸਥਿਰ ਖਾਲੀ parse_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op)
{
    ਵਿਅੰਜਕ_ਮੁੱਲ e;
    ਪੂਰਨ reg, indir;
    ਅਚਲ ਅੱਖਰ *p;

    indir = 0;
    ਜੇ (tok == '*') {
        ਅਗਲਾ();
        indir = OP_INDIR;
    }

    ਜੇ (tok == '%') {
        ਅਗਲਾ();
        ਜੇ (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            ਜੇ ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            ਨਹੀਂਤਾਂ ਜੇ (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            ਨਹੀਂਤਾਂ ਜੇ (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } ਨਹੀਂਤਾਂ ਜੇ (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } ਨਹੀਂਤਾਂ ਜੇ (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            ਅਗਲਾ();
            ਜੇ (tok == '(') {
                ਅਗਲਾ();
                ਜੇ (tok != TOK_PPNUM)
                    ਜਾਓ reg_error;
                p = tokc.str.ਅੰਕੜੇ;
                reg = p[0] - '0';
                ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)reg >= 8 || p[1] != '\0')
                    ਜਾਓ reg_error;
                op->reg = reg;
                ਅਗਲਾ();
                skip(')');
            }
            ਜੇ (op->reg == 0)
                op->type |= OP_ST0;
            ਜਾਓ no_skip;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
	} ਨਹੀਂਤਾਂ ਜੇ (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_ਨੀਵਾਂ;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } ਨਹੀਂਤਾਂ ਜੇ ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        ਅਗਲਾ();
    no_skip: ;
    } ਨਹੀਂਤਾਂ ਜੇ (tok == '$') {
        /* constant value */
        ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        ਜੇ (!op->e.sym) {
            ਜੇ (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            ਜੇ (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            ਜੇ (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
            ਜੇ (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#ਜੇ_ਅੰਤ
        }
    } ਨਹੀਂਤਾਂ {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->ਖਿਸਕਾਓ = 0;
        ਜੇ (tok != '(') {
            asm_ਵਿਅੰਜਕ(s1, &e);
            op->e = e;
        } ਨਹੀਂਤਾਂ {
            ਅਗਲਾ();
            ਜੇ (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = ਨਿਰਾ;
            } ਨਹੀਂਤਾਂ {
                /* bracketed offset expression */
                asm_ਵਿਅੰਜਕ(s1, &e);
                ਜੇ (tok != ')')
                    expect(")");
                ਅਗਲਾ();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        ਜੇ (tok == '(') {
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ type = 0;
            ਅਗਲਾ();
            ਜੇ (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            ਜੇ (tok == ',') {
                ਅਗਲਾ();
                ਜੇ (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                ਜੇ (tok == ',') {
                    ਅਗਲਾ();
                    op->ਖਿਸਕਾਓ = get_reg_ਖਿਸਕਾਓ(s1);
                }
            }
	    ਜੇ (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        ਜੇ (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC ਖਾਲੀ gen_expr32(ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    ਜੇ (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    ਨਹੀਂਤਾਂ
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
ਸਥਿਰ ਖਾਲੀ gen_disp32(ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    ਜੇ (esym && esym->st_shndx == cur_ਪਾਠ_section->sh_ਅੰਕ) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_ਮੁੱਲ - ind - 4);
    } ਨਹੀਂਤਾਂ {
        ਜੇ (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = ਨਿਰਾ;
        }
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
        greloca(cur_ਪਾਠ_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#ਨਹੀਂਤਾਂ
        gen_addrpc32(VT_SYM, sym, pe->v);
#ਜੇ_ਅੰਤ

    }
}

/* generate the modrm operand */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ asm_modrm(ਪੂਰਨ reg, ਸੰਕਾਰਜ *op)
{
    ਪੂਰਨ mod, reg1, reg2, sib_reg1;

    ਜੇ (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } ਨਹੀਂਤਾਂ ਜੇ (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#ਨਹੀਂਤਾਂ
	g(0x05 + (reg << 3));
#ਜੇ_ਅੰਤ
	gen_expr32(&op->e);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    } ਨਹੀਂਤਾਂ ਜੇ (op->reg == -2) {
        ਵਿਅੰਜਕ_ਮੁੱਲ *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        ਵਾਪਸ ind;
#ਜੇ_ਅੰਤ
    } ਨਹੀਂਤਾਂ {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        ਜੇ (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } ਨਹੀਂਤਾਂ ਜੇ (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } ਨਹੀਂਤਾਂ ਜੇ (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } ਨਹੀਂਤਾਂ {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        ਜੇ (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        ਜੇ (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            ਜੇ (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->ਖਿਸਕਾਓ << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        ਜੇ (mod == 0x40) {
            g(op->e.v);
        } ਨਹੀਂਤਾਂ ਜੇ (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    ਵਾਪਸ 0;
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REX_W 0x48
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REX_R 0x44
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REX_X 0x42
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REX_B 0x41

ਸਥਿਰ ਖਾਲੀ asm_rex(ਪੂਰਨ width64, ਸੰਕਾਰਜ *ops, ਪੂਰਨ nb_ops, ਪੂਰਨ *op_type,
		    ਪੂਰਨ regi, ਪੂਰਨ rmi)
{
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ rex = width64 ? 0x48 : 0;
  ਪੂਰਨ saw_ਉੱਚਾ_8bit = 0;
  ਪੂਰਨ i;
  ਜੇ (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      ਲਈ(i = 0; i < nb_ops; i++) {
	  ਜੇ (op_type[i] & (OP_REG | OP_ST)) {
	      ਜੇ (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } ਨਹੀਂਤਾਂ ਜੇ (ops[i].type & OP_REG8_ਨੀਵਾਂ)
		  rex |= 0x40;
	      ਨਹੀਂਤਾਂ ਜੇ (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_ਉੱਚਾ_8bit = ops[i].reg;
	      ਰੋਕੋ;
	  }
      }
  } ਨਹੀਂਤਾਂ {
      ਜੇ (regi != -1) {
	  ਜੇ (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } ਨਹੀਂਤਾਂ ਜੇ (ops[regi].type & OP_REG8_ਨੀਵਾਂ)
	      rex |= 0x40;
	  ਨਹੀਂਤਾਂ ਜੇ (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_ਉੱਚਾ_8bit = ops[regi].reg;
      }
      ਜੇ (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  ਜੇ (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } ਨਹੀਂਤਾਂ ਜੇ (ops[rmi].type & OP_REG8_ਨੀਵਾਂ)
	      rex |= 0x40;
	  ਨਹੀਂਤਾਂ ਜੇ (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_ਉੱਚਾ_8bit = ops[rmi].reg;
      }
      ਜੇ (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  ਜੇ (rex) {
      ਜੇ (saw_ਉੱਚਾ_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_ਉੱਚਾ_8bit-4]);
      g(rex);
  }
}
#ਜੇ_ਅੰਤ


ਸਥਿਰ ਖਾਲੀ maybe_print_stats (ਖਾਲੀ)
{
    ਸਥਿਰ ਪੂਰਨ already;

    ਜੇ (0 && !already)
    /* print stats about opcodes */
    {
        ਅਚਲ ਬਣਤਰ ASMInstr *pa;
        ਪੂਰਨ freq[4];
        ਪੂਰਨ op_vals[500];
        ਪੂਰਨ nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, ਆਕਾਰ(freq));
        ਲਈ(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                ਲਈ(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    ਜੇ (pa->instr_type == op_vals[j])
                        ਜਾਓ ਮਿਲਿਆ;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            ਮਿਲਿਆ: ;
            //}
        }
        ਲਈ(i=0;i<nb_op_vals;i++) {
            ਪੂਰਨ v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                ਲਿਖੋ("%3d: %08x\n", i, v);
        }
        ਲਿਖੋ("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (ਪੂਰਨ)ਆਕਾਰ(asm_instrs),
	       (ਪੂਰਨ)ਆਕਾਰ(asm_instrs) / (ਪੂਰਨ)ਆਕਾਰ(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC ਖਾਲੀ asm_opcode(TCCState *s1, ਪੂਰਨ opcode)
{
    ਅਚਲ ASMInstr *pa;
    ਪੂਰਨ i, modrm_ਸੂਚਕਾਂਕ, modreg_ਸੂਚਕਾਂਕ, reg, v, op1, seg_ਅਗੇਤਰ, pc, p;
    ਪੂਰਨ nb_ops, s;
    ਸੰਕਾਰਜ ops[MAX_OPERANDS], *ਕੱਢੋ;
    ਪੂਰਨ op_type[3]; /* decoded op type */
    ਪੂਰਨ alltypes;   /* OR of all operand types */
    ਪੂਰਨ autosize;
    ਪੂਰਨ p66;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    ਪੂਰਨ rex64;
#ਜੇ_ਅੰਤ

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    ਜੇ (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    ਕੱਢੋ = ops;
    nb_ops = 0;
    seg_ਅਗੇਤਰ = 0;
    alltypes = 0;
    ਲਈ(;;) {
        ਜੇ (tok == ';' || tok == TOK_LINEFEED)
            ਰੋਕੋ;
        ਜੇ (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_ਸੰਕਾਰਜ(s1, ਕੱਢੋ);
        ਜੇ (tok == ':') {
           ਜੇ (!(ਕੱਢੋ->type & OP_SEG) || seg_ਅਗੇਤਰ)
               tcc_error("incorrect prefix");
           seg_ਅਗੇਤਰ = segment_prefixes[ਕੱਢੋ->reg];
           ਅਗਲਾ();
           parse_ਸੰਕਾਰਜ(s1, ਕੱਢੋ);
           ਜੇ (!(ਕੱਢੋ->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        ਕੱਢੋ++;
        nb_ops++;
        ਜੇ (tok != ',')
            ਰੋਕੋ;
        ਅਗਲਾ();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    ਲਈ(pa = asm_instrs; pa->sym != 0; pa++) {
	ਪੂਰਨ it = pa->instr_type & OPCT_ਨਕਾਬ;
        s = 0;
        ਜੇ (it == OPC_FARITH) {
            v = opcode - pa->sym;
            ਜੇ (!((ਬਿਨਾਨਿਸ਼ਾਨੀ)v < 8 * 6 && (v % 6) == 0))
                ਜਾਰੀ;
        } ਨਹੀਂਤਾਂ ਜੇ (it == OPC_ARITH) {
            ਜੇ (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                ਜਾਰੀ;
            s = (opcode - pa->sym) % NBWLX;
	    ਜੇ ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		ਜੇ (((opcode - pa->sym + 1) % NBWLX) == 0)
		    ਜਾਰੀ;
	        s++;
	      }
        } ਨਹੀਂਤਾਂ ਜੇ (it == OPC_ਖਿਸਕਾਓ) {
            ਜੇ (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                ਜਾਰੀ;
            s = (opcode - pa->sym) % NBWLX;
        } ਨਹੀਂਤਾਂ ਜੇ (it == OPC_TEST) {
            ਜੇ (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                ਜਾਰੀ;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    ਜੇ (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } ਨਹੀਂਤਾਂ ਜੇ (pa->instr_type & OPC_B) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    ਜੇ ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        ਜਾਰੀ;
#ਜੇ_ਅੰਤ
            ਜੇ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                ਜਾਰੀ;
            s = opcode - pa->sym;
        } ਨਹੀਂਤਾਂ ਜੇ (pa->instr_type & OPC_WLX) {
            ਜੇ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                ਜਾਰੀ;
            s = opcode - pa->sym + 1;
        } ਨਹੀਂਤਾਂ {
            ਜੇ (pa->sym != opcode)
                ਜਾਰੀ;
        }
        ਜੇ (pa->nb_ops != nb_ops)
            ਜਾਰੀ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	ਜੇ (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    ਜਾਰੀ;
#ਜੇ_ਅੰਤ
        /* now decode and check each operand */
	alltypes = 0;
        ਲਈ(i = 0; i < nb_ops; i++) {
            ਪੂਰਨ op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            ਚੋਣ(op2) {
            ਹਾਲਤ OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                ਰੋਕੋ;
            ਹਾਲਤ OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                ਰੋਕੋ;
            ਹਾਲਤ OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                ਰੋਕੋ;
            ਹਾਲਤ OPT_IMW:
                v = OP_IM16 | OP_IM32;
                ਰੋਕੋ;
	    ਹਾਲਤ OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		ਰੋਕੋ;
	    ਹਾਲਤ OPT_DISP:
	    ਹਾਲਤ OPT_DISP8:
		v = OP_ADDR;
		ਰੋਕੋ;
            ਮੂਲ:
                v = 1 << op2;
                ਰੋਕੋ;
            }
            ਜੇ (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            ਜੇ ((ops[i].type & v) == 0)
                ਜਾਓ ਅਗਲਾ;
	    alltypes |= ops[i].type;
        }
        (ਖਾਲੀ)alltypes; /* maybe unused */
        /* all is matching ! */
        ਰੋਕੋ;
    ਅਗਲਾ: ;
    }
    ਜੇ (pa->sym == 0) {
        ਜੇ (opcode >= TOK_ASM_ਪਹਿਲਾ && opcode <= TOK_ASM_ਆਖਰੀ) {
            ਪੂਰਨ b;
            b = op0_codes[opcode - TOK_ASM_ਪਹਿਲਾ];
            ਜੇ (b & 0xff00)
                g(b >> 8);
            g(b);
            ਵਾਪਸ;
        } ਨਹੀਂਤਾਂ ਜੇ (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, ਨਿਰਾ));
        } ਨਹੀਂਤਾਂ {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = ਸਾਰਣੀ_ident[opcode - TOK_IDENT];
	    ਜੇ (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		ਜਾਓ again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    ਜੇ ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#ਜੇ_ਅੰਤ
    ਜੇ (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        ਲਈ(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            ਜੇ ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_ਮੰਜ਼ਿਲ_ਮਾਪ[ops[i].type & OP_REG];
        }
        ਜੇ (s == autosize) {
            ਜੇ ((opcode == TOK_ASM_ਧੱਕੋ || opcode == TOK_ASM_ਕੱਢੋ) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    ਨਹੀਂਤਾਂ ਜੇ ((opcode == TOK_ASM_ਧੱਕੋ || opcode == TOK_ASM_ਕੱਢੋ) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            ਨਹੀਂਤਾਂ
                tcc_error("cannot infer opcode suffix");
        }
    }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    rex64 = 0;
    ਜੇ (pa->instr_type & OPC_48)
        rex64 = 1;
    ਨਹੀਂਤਾਂ ਜੇ (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	ਪੂਰਨ default64 = 0;
	ਲਈ(i = 0; i < nb_ops; i++) {
	    ਜੇ (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		ਰੋਕੋ;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        ਜੇ (((opcode != TOK_ASM_ਧੱਕੋ && opcode != TOK_ASM_ਕੱਢੋ
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#ਜੇ_ਅੰਤ

    /* now generates the operation */
    ਜੇ (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    ਜੇ (seg_ਅਗੇਤਰ)
        g(seg_ਅਗੇਤਰ);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    /* Generate addr32 prefix if needed */
    ਲਈ(i = 0; i < nb_ops; i++) {
        ਜੇ (ops[i].type & OP_EA32) {
	    g(0x67);
	    ਰੋਕੋ;
        }
    }
#ਜੇ_ਅੰਤ
    /* generate data16 prefix if needed */
    p66 = 0;
    ਜੇ (s == 1)
        p66 = 1;
    ਨਹੀਂਤਾਂ {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        ਲਈ (i = 0; i < nb_ops; i++)
            ਜੇ ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    ਜੇ (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    ਚੋਣ (p) {
        ਹਾਲਤ 0: ਰੋਕੋ;  /* no prefix */
        ਹਾਲਤ 0x48: ਰੋਕੋ; /* REX, handled elsewhere */
        ਹਾਲਤ 0x66:
        ਹਾਲਤ 0x67:
        ਹਾਲਤ 0xf2:
        ਹਾਲਤ 0xf3: v = v & 0xff; g(p); ਰੋਕੋ;
        ਹਾਲਤ 0xd4: ਹਾਲਤ 0xd5: ਰੋਕੋ; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        ਹਾਲਤ 0xd8: ਹਾਲਤ 0xd9: ਹਾਲਤ 0xda: ਹਾਲਤ 0xdb: /* x87, no normal prefix */
        ਹਾਲਤ 0xdc: ਹਾਲਤ 0xdd: ਹਾਲਤ 0xde: ਹਾਲਤ 0xdf: ਰੋਕੋ;
        ਮੂਲ: tcc_error("bad prefix 0x%2x in opcode table", p); ਰੋਕੋ;
    }
    ਜੇ (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    ਜੇ ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } ਨਹੀਂਤਾਂ ਜੇ (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } ਨਹੀਂਤਾਂ ਜੇ ((v == 0x06 || v == 0x07)) {
        ਜੇ (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } ਨਹੀਂਤਾਂ {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } ਨਹੀਂਤਾਂ ਜੇ (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } ਨਹੀਂਤਾਂ ਜੇ ((pa->instr_type & (OPCT_ਨਕਾਬ | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_ਸੂਚਕਾਂਕ = -1;
    modreg_ਸੂਚਕਾਂਕ = -1;
    ਜੇ (pa->instr_type & OPC_MODRM) {
	ਜੇ (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
	    ਜੇ (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    ਨਹੀਂਤਾਂ ਜੇ (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#ਨਹੀਂਤਾਂ
	    ਜੇ (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#ਜੇ_ਅੰਤ
	    ਨਹੀਂਤਾਂ
	      tcc_error("bad MODR/M opcode without operands");
	    ਜਾਓ modrm_ਮਿਲਿਆ;
	}
        /* first look for an ea operand */
        ਲਈ(i = 0;i < nb_ops; i++) {
            ਜੇ (op_type[i] & OP_EA)
                ਜਾਓ modrm_ਮਿਲਿਆ;
        }
        /* then if not found, a register or indirection (shift instructions) */
        ਲਈ(i = 0;i < nb_ops; i++) {
            ਜੇ (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                ਜਾਓ modrm_ਮਿਲਿਆ;
        }
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ASM_DEBUG
        tcc_error("bad op table");
#ਜੇ_ਅੰਤ
    modrm_ਮਿਲਿਆ:
        modrm_ਸੂਚਕਾਂਕ = i;
        /* if a register is used in another operand then it is
           used instead of group */
        ਲਈ(i = 0;i < nb_ops; i++) {
            ਪੂਰਨ t = op_type[i];
            ਜੇ (i != modrm_ਸੂਚਕਾਂਕ &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_ਸੂਚਕਾਂਕ = i;
                ਰੋਕੋ;
            }
        }
    }
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_ਸੂਚਕਾਂਕ, modrm_ਸੂਚਕਾਂਕ);
#ਜੇ_ਅੰਤ

    ਜੇ (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        ਜੇ (v == 0xb0 && s >= 1)
            v += 7;
        ਲਈ(i = 0; i < nb_ops; i++) {
            ਜੇ (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                ਰੋਕੋ;
            }
        }
    }
    ਜੇ (pa->instr_type & OPC_B)
        v += s >= 1;
    ਜੇ (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        ਪੂਰਨ jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        ਜੇ (!esym || esym->st_shndx != cur_ਪਾਠ_section->sh_ਅੰਕ)
            ਜਾਓ no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_ਮੁੱਲ - ind - 2 - (v >= 0xff);
        ਜੇ (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } ਨਹੀਂਤਾਂ {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    ਜੇ (v == 0xeb) /* jmp */
	        v = 0xe9;
	    ਨਹੀਂਤਾਂ ਜੇ (v == 0x70) /* jcc */
	        v += 0x0f10;
	    ਨਹੀਂਤਾਂ
	        tcc_error("invalid displacement");
        }
    }
    ਜੇ (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_ਬਿੱਟ[opcode - pa->sym];
    ਨਹੀਂਤਾਂ ਜੇ (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    ਜੇ (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    ਜੇ (op1)
        g(op1);
    g(v);

    ਜੇ (OPCT_IS(pa->instr_type, OPC_ਖਿਸਕਾਓ)) {
        reg = (opcode - pa->sym) / NBWLX;
        ਜੇ (reg == 6)
            reg = 7;
    } ਨਹੀਂਤਾਂ ਜੇ (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } ਨਹੀਂਤਾਂ ਜੇ (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } ਨਹੀਂਤਾਂ {
        reg = (pa->instr_type >> OPC_ਸਮੂਹ_ਖਿਸਕਾਓ) & 7;
    }

    pc = 0;
    ਜੇ (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	ਜੇ (modreg_ਸੂਚਕਾਂਕ >= 0)
	    reg = ops[modreg_ਸੂਚਕਾਂਕ].reg;
        pc = asm_modrm(reg, &ops[modrm_ਸੂਚਕਾਂਕ]);
    }

    /* emit constants */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    ਜੇ (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        ਜੇ (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        ਵਾਪਸ;
    }
#ਜੇ_ਅੰਤ
    ਲਈ(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        ਜੇ (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            ਜੇ ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                ਜੇ (s == 0)
                    v = OP_IM8;
                ਨਹੀਂਤਾਂ ਜੇ (s == 1)
                    v = OP_IM16;
                ਨਹੀਂਤਾਂ ਜੇ (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                ਨਹੀਂਤਾਂ
                    v = OP_IM64;
            }

            ਜੇ ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            ਜੇ (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } ਨਹੀਂਤਾਂ ਜੇ (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
            } ਨਹੀਂਤਾਂ ਜੇ (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#ਜੇ_ਅੰਤ
	    } ਨਹੀਂਤਾਂ ਜੇ (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } ਨਹੀਂਤਾਂ {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    ਜੇ (pc)
        add32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ constraint_ਤਰਜੀਹ(ਅਚਲ ਅੱਖਰ *str)
{
    ਪੂਰਨ ਤਰਜੀਹ, c, pr;

    /* we take the lowest priority */
    ਤਰਜੀਹ = 0;
    ਲਈ(;;) {
        c = *str;
        ਜੇ (c == '\0')
            ਰੋਕੋ;
        str++;
        ਚੋਣ(c) {
        ਹਾਲਤ 'A':
            pr = 0;
            ਰੋਕੋ;
        ਹਾਲਤ 'a':
        ਹਾਲਤ 'b':
        ਹਾਲਤ 'c':
        ਹਾਲਤ 'd':
        ਹਾਲਤ 'S':
        ਹਾਲਤ 'D':
            pr = 1;
            ਰੋਕੋ;
        ਹਾਲਤ 'q':
            pr = 2;
            ਰੋਕੋ;
        ਹਾਲਤ 'r':
	ਹਾਲਤ 'R':
	ਹਾਲਤ 'p':
            pr = 3;
            ਰੋਕੋ;
        ਹਾਲਤ 'N':
        ਹਾਲਤ 'M':
        ਹਾਲਤ 'I':
	ਹਾਲਤ 'e':
        ਹਾਲਤ 'i':
        ਹਾਲਤ 'm':
        ਹਾਲਤ 'g':
            pr = 4;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        ਜੇ (pr > ਤਰਜੀਹ)
            ਤਰਜੀਹ = pr;
    }
    ਵਾਪਸ ਤਰਜੀਹ;
}

ਸਥਿਰ ਅਚਲ ਅੱਖਰ *skip_constraint_modifiers(ਅਚਲ ਅੱਖਰ *p)
{
    ਜਦੋਂ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ਵਾਪਸ p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC ਪੂਰਨ asm_parse_regvar (ਪੂਰਨ t)
{
    ਅਚਲ ਅੱਖਰ *s;
    ਸੰਕਾਰਜ op;
    ਜੇ (t < TOK_IDENT || (t & SYM_ਖੇਤਰ))
        ਵਾਪਸ -1;
    s = ਸਾਰਣੀ_ident[t - TOK_IDENT]->str;
    ਜੇ (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_ਸੰਕਾਰਜ(tcc_state, &op);
    /* Accept only integer regs for now. */
    ਜੇ (op.type & OP_REG)
        ਵਾਪਸ op.reg;
    ਨਹੀਂਤਾਂ
        ਵਾਪਸ -1;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਬਾਹਰਲਾ_ਨਕਾਬ 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਵਿੱਚ_ਨਕਾਬ  0x02

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ is_reg_allocated(reg) (regs_allocated[reg] & reg_ਨਕਾਬ)

ST_FUNC ਖਾਲੀ asm_compute_constraints(ASMOperand *operands,
                                    ਪੂਰਨ nb_operands, ਪੂਰਨ nb_outputs,
                                    ਅਚਲ uint8_t *clobber_regs,
                                    ਪੂਰਨ *pout_reg)
{
    ASMOperand *op;
    ਪੂਰਨ sorted_op[MAX_ASM_OPERANDS];
    ਪੂਰਨ i, j, k, p1, p2, tmp, reg, c, reg_ਨਕਾਬ;
    ਅਚਲ ਅੱਖਰ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ਲਈ(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ = -1;
        op->ref_ਸੂਚਕਾਂਕ = -1;
        op->reg = -1;
        op->is_ਸਮ੍ਰਿਤੀ = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ਲਈ(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ਜੇ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = ਲੱਭੋ_constraint(operands, nb_operands, str, ਨਿਰਾ);
            ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_ਸੂਚਕਾਂਕ = k;
            ਜੇ (operands[k].ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ = i;
            op->ਤਰਜੀਹ = 5;
	} ਨਹੀਂਤਾਂ ਜੇ ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->ਤਰਜੀਹ = 1;
	    op->reg = reg;
        } ਨਹੀਂਤਾਂ {
            op->ਤਰਜੀਹ = constraint_ਤਰਜੀਹ(str);
        }
    }

    /* sort operands according to their priority */
    ਲਈ(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    ਲਈ(i=0;i<nb_operands - 1;i++) {
        ਲਈ(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].ਤਰਜੀਹ;
            p2 = operands[sorted_op[j]].ਤਰਜੀਹ;
            ਜੇ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ਲਈ(i = 0;i < NB_ASM_REGS; i++) {
        ਜੇ (clobber_regs[i])
            regs_allocated[i] = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
        ਨਹੀਂਤਾਂ
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;

    /* allocate registers and generate corresponding asm moves */
    ਲਈ(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ਜੇ (op->ref_ਸੂਚਕਾਂਕ >= 0)
            ਜਾਰੀ;
        /* select if register is used for output, input or both */
        ਜੇ (op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0) {
            reg_ਨਕਾਬ = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
        } ਨਹੀਂਤਾਂ ਜੇ (j < nb_outputs) {
            reg_ਨਕਾਬ = REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
        } ਨਹੀਂਤਾਂ {
            reg_ਨਕਾਬ = REG_ਵਿੱਚ_ਨਕਾਬ;
        }
	ਜੇ (op->reg >= 0) {
	    ਜੇ (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_ਅਗਲਾ:
        c = *str++;
        ਚੋਣ(c) {
        ਹਾਲਤ '=':
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ '+':
            op->is_rw = 1;
            /* FALL THRU */
        ਹਾਲਤ '&':
            ਜੇ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_ਨਕਾਬ = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ 'A':
            /* allocate both eax and edx */
            ਜੇ (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                ਜਾਓ try_ਅਗਲਾ;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_ਨਕਾਬ;
            regs_allocated[TREG_XDX] |= reg_ਨਕਾਬ;
            ਰੋਕੋ;
        ਹਾਲਤ 'a':
            reg = TREG_XAX;
            ਜਾਓ alloc_reg;
        ਹਾਲਤ 'b':
            reg = 3;
            ਜਾਓ alloc_reg;
        ਹਾਲਤ 'c':
            reg = TREG_XCX;
            ਜਾਓ alloc_reg;
        ਹਾਲਤ 'd':
            reg = TREG_XDX;
            ਜਾਓ alloc_reg;
        ਹਾਲਤ 'S':
            reg = 6;
            ਜਾਓ alloc_reg;
        ਹਾਲਤ 'D':
            reg = 7;
        alloc_reg:
            ਜੇ (op->reg >= 0 && reg != op->reg)
                ਜਾਓ try_ਅਗਲਾ;
            ਜੇ (is_reg_allocated(reg))
                ਜਾਓ try_ਅਗਲਾ;
            ਜਾਓ reg_ਮਿਲਿਆ;
        ਹਾਲਤ 'q':
            /* eax, ebx, ecx or edx */
            ਜੇ (op->reg >= 0) {
                ਜੇ ((reg = op->reg) < 4)
                    ਜਾਓ reg_ਮਿਲਿਆ;
            } ਨਹੀਂਤਾਂ ਲਈ(reg = 0; reg < 4; reg++) {
                ਜੇ (!is_reg_allocated(reg))
                    ਜਾਓ reg_ਮਿਲਿਆ;
            }
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ 'r':
	ਹਾਲਤ 'R':
	ਹਾਲਤ 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            ਜੇ ((reg = op->reg) >= 0)
                ਜਾਓ reg_ਮਿਲਿਆ;
            ਨਹੀਂਤਾਂ ਲਈ(reg = 0; reg < NB_ASM_REGS; reg++) {
                ਜੇ (!is_reg_allocated(reg))
                    ਜਾਓ reg_ਮਿਲਿਆ;
            }
            ਜਾਓ try_ਅਗਲਾ;
        reg_ਮਿਲਿਆ:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_ਨਕਾਬ;
            ਰੋਕੋ;
	ਹਾਲਤ 'e':
        ਹਾਲਤ 'i':
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'I':
        ਹਾਲਤ 'N':
        ਹਾਲਤ 'M':
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'm':
        ਹਾਲਤ 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ਜੇ (j < nb_outputs || c == 'm') {
                ਜੇ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    ਲਈ(reg = 0; reg < NB_ASM_REGS; reg++) {
                        ਜੇ (!(regs_allocated[reg] & REG_ਵਿੱਚ_ਨਕਾਬ))
                            ਜਾਓ reg_found1;
                    }
                    ਜਾਓ try_ਅਗਲਾ;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_ਵਿੱਚ_ਨਕਾਬ;
                    op->reg = reg;
                    op->is_ਸਮ੍ਰਿਤੀ = 1;
                }
            }
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            ਰੋਕੋ;
        }
        /* if a reference is present for that operand, we assign it too */
        ਜੇ (op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0) {
            operands[op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ].reg = op->reg;
            operands[op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ਲਈ(i=0;i<nb_operands;i++) {
        op = &operands[i];
        ਜੇ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_ਸਮ੍ਰਿਤੀ) {
            ਲਈ(reg = 0; reg < NB_ASM_REGS; reg++) {
                ਜੇ (!(regs_allocated[reg] & REG_ਬਾਹਰਲਾ_ਨਕਾਬ))
                    ਜਾਓ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            ਰੋਕੋ;
        }
    }

    /* print sorted constraints */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ASM_DEBUG
    ਲਈ(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        ਲਿਖੋ("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ਨਿਰਾ) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    ਜੇ (*pout_reg >= 0)
        ਲਿਖੋ("out_reg=%d\n", *pout_reg);
#ਜੇ_ਅੰਤ
}

ST_FUNC ਖਾਲੀ subst_asm_ਸੰਕਾਰਜ(CString *ਜੋੜੋ_str,
                              SValue *sv, ਪੂਰਨ modifier)
{
    ਪੂਰਨ r, reg, ਮਾਪ, val;

    r = sv->r;
    ਜੇ ((r & VT_VALMASK) == VT_CONST) {
        ਜੇ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(ਜੋੜੋ_str, '$');
        ਜੇ (r & VT_SYM) {
	    ਅਚਲ ਅੱਖਰ *name = get_tok_str(sv->sym->v, ਨਿਰਾ);
	    ਜੇ (sv->sym->v >= SYM_ਪਹਿਲਾ_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            ਜੇ (tcc_state->leading_underscore)
              cstr_ccat(ਜੋੜੋ_str, '_');
            cstr_cat(ਜੋੜੋ_str, name, -1);
            ਜੇ ((uint32_t)sv->c.i == 0)
                ਜਾਓ no_ਵਿੱਥ;
	    cstr_ccat(ਜੋੜੋ_str, '+');
        }
        val = sv->c.i;
        ਜੇ (modifier == 'n')
            val = -val;
        cstr_printf(ਜੋੜੋ_str, "%d", val);
    no_ਵਿੱਥ:;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
        ਜੇ (r & VT_LVAL)
            cstr_cat(ਜੋੜੋ_str, "(%rip)", -1);
#ਜੇ_ਅੰਤ
    } ਨਹੀਂਤਾਂ ਜੇ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(ਜੋੜੋ_str, "%d(%%%s)", (ਪੂਰਨ)sv->c.i, get_tok_str(TOK_ASM_xax + 5, ਨਿਰਾ));
    } ਨਹੀਂਤਾਂ ਜੇ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ਜੇ (reg >= VT_CONST)
            tcc_ਅੰਦਰੂਨੀ_error("");
        cstr_printf(ਜੋੜੋ_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, ਨਿਰਾ));
    } ਨਹੀਂਤਾਂ {
        /* register case */
        reg = r & VT_VALMASK;
        ਜੇ (reg >= VT_CONST)
            tcc_ਅੰਦਰੂਨੀ_error("");

        /* choose register operand size */
        ਜੇ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            ਮਾਪ = 1;
        ਨਹੀਂਤਾਂ ਜੇ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            ਮਾਪ = 2;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
        ਨਹੀਂਤਾਂ ਜੇ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            ਮਾਪ = 8;
#ਜੇ_ਅੰਤ
        ਨਹੀਂਤਾਂ
            ਮਾਪ = 4;
        ਜੇ (ਮਾਪ == 1 && reg >= 4)
            ਮਾਪ = 4;

        ਜੇ (modifier == 'b') {
            ਜੇ (reg >= 4)
                tcc_error("cannot use byte register");
            ਮਾਪ = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (modifier == 'h') {
            ਜੇ (reg >= 4)
                tcc_error("cannot use byte register");
            ਮਾਪ = -1;
        } ਨਹੀਂਤਾਂ ਜੇ (modifier == 'w') {
            ਮਾਪ = 2;
        } ਨਹੀਂਤਾਂ ਜੇ (modifier == 'k') {
            ਮਾਪ = 4;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
        } ਨਹੀਂਤਾਂ ਜੇ (modifier == 'q') {
            ਮਾਪ = 8;
#ਜੇ_ਅੰਤ
        }

        ਜੇ (reg >= 8) {
            cstr_printf(ਜੋੜੋ_str, "%%r%d%c", reg, (ਮਾਪ == 1) ? 'b' : ((ਮਾਪ == 2) ? 'w' : ((ਮਾਪ == 4) ? 'd' : ' ')));
            ਵਾਪਸ;
        }
        ਚੋਣ(ਮਾਪ) {
        ਹਾਲਤ -1:
            reg = TOK_ASM_ah + reg;
            ਰੋਕੋ;
        ਹਾਲਤ 1:
            reg = TOK_ASM_al + reg;
            ਰੋਕੋ;
        ਹਾਲਤ 2:
            reg = TOK_ASM_ax + reg;
            ਰੋਕੋ;
        ਮੂਲ:
            reg = TOK_ASM_eax + reg;
            ਰੋਕੋ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
        ਹਾਲਤ 8:
            reg = TOK_ASM_rax + reg;
            ਰੋਕੋ;
#ਜੇ_ਅੰਤ
        }
        cstr_printf(ਜੋੜੋ_str, "%%%s", get_tok_str(reg, ਨਿਰਾ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ਖਾਲੀ asm_gen_ਕੋਡ(ASMOperand *operands, ਪੂਰਨ nb_operands,
                         ਪੂਰਨ nb_outputs, ਪੂਰਨ is_output,
                         uint8_t *clobber_regs,
                         ਪੂਰਨ ਬਾਹਰਲਾ_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ਪੂਰਨ i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਸਥਿਰ ਅਚਲ uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#ਨਹੀਂਤਾਂ
    ਸਥਿਰ ਅਚਲ uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
    ਸਥਿਰ ਅਚਲ uint8_t reg_saved[] = { 3, 6, 7 };
#ਜੇ_ਅੰਤ

    /* mark all used registers */
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(regs_allocated, clobber_regs, ਆਕਾਰ(regs_allocated));
    ਲਈ(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        ਜੇ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    ਜੇ (!is_output) {
        /* generate reg save code */
        ਲਈ(i = 0; i < ਆਕਾਰ(reg_saved)/ਆਕਾਰ(reg_saved[0]); i++) {
            reg = reg_saved[i];
            ਜੇ (regs_allocated[reg]) {
		ਜੇ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        ਲਈ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ਜੇ (op->reg >= 0) {
                ਜੇ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_ਸਮ੍ਰਿਤੀ) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    ਲੱਦੋ(op->reg, &sv);
                } ਨਹੀਂਤਾਂ ਜੇ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    ਲੱਦੋ(op->reg, op->vt);
                    ਜੇ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        ਲੱਦੋ(TREG_XDX, &sv);
                    }
                }
            }
        }
    } ਨਹੀਂਤਾਂ {
        /* generate save code */
        ਲਈ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ਜੇ (op->reg >= 0) {
                ਜੇ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ਜੇ (!op->is_ਸਮ੍ਰਿਤੀ) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        ਲੱਦੋ(ਬਾਹਰਲਾ_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | ਬਾਹਰਲਾ_reg;
                        store(op->reg, &sv);
                    }
                } ਨਹੀਂਤਾਂ {
                    store(op->reg, op->vt);
                    ਜੇ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        ਲਈ(i = ਆਕਾਰ(reg_saved)/ਆਕਾਰ(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            ਜੇ (regs_allocated[reg]) {
		ਜੇ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC ਖਾਲੀ asm_clobber(uint8_t *clobber_regs, ਅਚਲ ਅੱਖਰ *str)
{
    ਪੂਰਨ reg;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ type;
#ਜੇ_ਅੰਤ

    ਜੇ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        ਵਾਪਸ;
    reg = tok_alloc_const(str);
    ਜੇ (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } ਨਹੀਂਤਾਂ ਜੇ (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    } ਨਹੀਂਤਾਂ ਜੇ (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } ਨਹੀਂਤਾਂ ਜੇ ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#ਜੇ_ਅੰਤ
    } ਨਹੀਂਤਾਂ {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
