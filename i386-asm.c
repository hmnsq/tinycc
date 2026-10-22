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

#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"

#నిర్వచించు MAX_OPERANDS 3

#నిర్వచించు TOK_ASM_మొదటి TOK_ASM_clc
#నిర్వచించు TOK_ASM_చివరి TOK_ASM_emms
#నిర్వచించు TOK_ASM_alllast TOK_ASM_subps

#నిర్వచించు OPC_B          0x01  /* only used with OPC_WL */
#నిర్వచించు OPC_WL         0x02  /* accepts w, l or no suffix */
#నిర్వచించు OPC_BWL        (OPC_B | OPC_WL) /* accepts b, w, l or no suffix */
#నిర్వచించు OPC_REG        0x04 /* register is added to opcode */
#నిర్వచించు OPC_MODRM      0x08 /* modrm encoding */

#నిర్వచించు OPCT_ముసుగు      0x70
#నిర్వచించు OPC_FWAIT      0x10 /* add fwait opcode */
#నిర్వచించు OPC_జరుపు      0x20 /* shift opcodes */
#నిర్వచించు OPC_ARITH      0x30 /* arithmetic opcodes */
#నిర్వచించు OPC_FARITH     0x40 /* FPU arithmetic opcodes */
#నిర్వచించు OPC_TEST       0x50 /* test opcodes */
#నిర్వచించు OPC_0F01       0x60 /* 0x0f01XX (group 7, XX is 2nd opcode,
                               no operands and unstructured mod/rm) */
#నిర్వచించు OPCT_IS(v,i) (((v) & OPCT_ముసుగు) == (i))

#నిర్వచించు OPC_0F        0x100 /* Is secondary map (0x0f prefix) */
#నిర్వచించు OPC_48        0x200 /* Always has REX prefix */
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
# define OPC_WLQ     0x1000  /* accepts w, l, q or no suffix */
# define OPC_BWLQ    (OPC_B | OPC_WLQ) /* accepts b, w, l, q or no suffix */
# define OPC_WLX     OPC_WLQ
# define OPC_BWLX    OPC_BWLQ
#లేకపోతే
# define OPC_WLX     OPC_WL
# define OPC_BWLX    OPC_BWL
#అయితే_ముగింపు

#నిర్వచించు OPC_సమూహం_జరుపు 13

/* in order to compress the operand type, we use specific operands and
   we or only with EA  */
గణన {
    OPT_REG8=0, /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG16,  /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_REG32,  /* warning: value is hardcoded from TOK_ASM_xxx */
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    OPT_REG64,  /* warning: value is hardcoded from TOK_ASM_xxx */
#అయితే_ముగింపు
    OPT_MMX,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SSE,    /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_CR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_TR,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_DB,     /* warning: value is hardcoded from TOK_ASM_xxx */
    OPT_SEG,
    OPT_ST,
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    OPT_REG8_దిగువ, /* %spl,%bpl,%sil,%dil, encoded like ah,ch,dh,bh, but
		     with REX prefix, not used in insn templates */
#అయితే_ముగింపు
    OPT_IM8,
    OPT_IM8S,
    OPT_IM16,
    OPT_IM32,
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    OPT_IM64,
#అయితే_ముగింపు
    OPT_EAX,    /* %al, %ax, %eax or %rax register */
    OPT_ST0,    /* %st(0) register */
    OPT_CL,     /* %cl register */
    OPT_DX,     /* %dx register */
    OPT_ADDR,   /* OP_EA with only offset */
    OPT_INDIR,  /* *(expr) */
    /* composite types */
    OPT_సంయుక్త_మొదటి,
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

#నిర్వచించు OP_REG8   (1 << OPT_REG8)
#నిర్వచించు OP_REG16  (1 << OPT_REG16)
#నిర్వచించు OP_REG32  (1 << OPT_REG32)
#నిర్వచించు OP_MMX    (1 << OPT_MMX)
#నిర్వచించు OP_SSE    (1 << OPT_SSE)
#నిర్వచించు OP_CR     (1 << OPT_CR)
#నిర్వచించు OP_TR     (1 << OPT_TR)
#నిర్వచించు OP_DB     (1 << OPT_DB)
#నిర్వచించు OP_SEG    (1 << OPT_SEG)
#నిర్వచించు OP_ST     (1 << OPT_ST)
#నిర్వచించు OP_IM8    (1 << OPT_IM8)
#నిర్వచించు OP_IM8S   (1 << OPT_IM8S)
#నిర్వచించు OP_IM16   (1 << OPT_IM16)
#నిర్వచించు OP_IM32   (1 << OPT_IM32)
#నిర్వచించు OP_EAX    (1 << OPT_EAX)
#నిర్వచించు OP_ST0    (1 << OPT_ST0)
#నిర్వచించు OP_CL     (1 << OPT_CL)
#నిర్వచించు OP_DX     (1 << OPT_DX)
#నిర్వచించు OP_ADDR   (1 << OPT_ADDR)
#నిర్వచించు OP_INDIR  (1 << OPT_INDIR)
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
# define OP_REG64 (1 << OPT_REG64)
# define OP_REG8_దిగువ (1 << OPT_REG8_దిగువ)
# define OP_IM64  (1 << OPT_IM64)
# define OP_EA32  (OP_EA << 1)
#లేకపోతే
# define OP_REG64 0
# define OP_REG8_దిగువ 0
# define OP_IM64  0
# define OP_EA32  0
#అయితే_ముగింపు

#నిర్వచించు OP_EA     0x40000000u
#నిర్వచించు OP_REG    (OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64)

#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
# define TREG_XAX   TREG_RAX
# define TREG_XCX   TREG_RCX
# define TREG_XDX   TREG_RDX
# define TOK_ASM_xax TOK_ASM_rax
#లేకపోతే
# define TREG_XAX   TREG_EAX
# define TREG_XCX   TREG_ECX
# define TREG_XDX   TREG_EDX
# define TOK_ASM_xax TOK_ASM_eax
#అయితే_ముగింపు

రకనిర్వచనం నిర్మాణం ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[MAX_OPERANDS]; /* see OP_xxx */
} ASMInstr;

రకనిర్వచనం నిర్మాణం నిర్వాహ్యం {
    uint32_t type;
    int8_t  reg; /* register, -1 if none */
    int8_t  reg2; /* second register, -1 if none */
    uint8_t జరుపు;
    సమాసం_విలువ e;
} నిర్వాహ్యం;

స్థిర స్థిరరాశి uint8_t reg_గమ్యం_కొలత[9] = {
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

#నిర్వచించు NB_TEST_OPCODES 30

స్థిర స్థిరరాశి uint8_t test_బిట్లు[NB_TEST_OPCODES] = {
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

స్థిర స్థిరరాశి uint8_t segment_prefixes[] = {
 0x26, /* es */
 0x2e, /* cs */
 0x36, /* ss */
 0x3e, /* ds */
 0x64, /* fs */
 0x65  /* gs */
};

స్థిర స్థిరరాశి ASMInstr asm_instrs[] = {
#నిర్వచించు ALT(x) x
/* This removes a 0x0f in the second byte */
#నిర్వచించు O(o) ((uint64_t) ((((o) & 0xff00) == 0x0f00) ? ((((o) >> 8) & ~0xff) | ((o) & 0xff)) : (o)))
/* This constructs instr_type from opcode, type and group.  */
#నిర్వచించు T(o,i,g) ((i) | ((g) << OPC_సమూహం_జరుపు) | ((((o) & 0xff00) == 0x0f00) ? OPC_0F : 0))
#నిర్వచించు DEF_ASM_OP0(name, opcode)
#నిర్వచించు DEF_ASM_OP0L(name, opcode, సమూహం, instr_type) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, సమూహం), 0, { 0 } },
#నిర్వచించు DEF_ASM_OP1(name, opcode, సమూహం, instr_type, op0) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, సమూహం), 1, { op0 }},
#నిర్వచించు DEF_ASM_OP2(name, opcode, సమూహం, instr_type, op0, op1) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, సమూహం), 2, { op0, op1 }},
#నిర్వచించు DEF_ASM_OP3(name, opcode, సమూహం, instr_type, op0, op1, op2) { TOK_ASM_ ## name, O(opcode), T(opcode, instr_type, సమూహం), 3, { op0, op1, op2 }},
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
# include "x86_64-asm.h"
#లేకపోతే
# include "i386-asm.h"
#అయితే_ముగింపు
    /* last operation */
    { 0, },
};

స్థిర స్థిరరాశి uint16_t op0_codes[] = {
#నిర్వచించు ALT(x)
#నిర్వచించు DEF_ASM_OP0(x, opcode) opcode,
#నిర్వచించు DEF_ASM_OP0L(name, opcode, సమూహం, instr_type)
#నిర్వచించు DEF_ASM_OP1(name, opcode, సమూహం, instr_type, op0)
#నిర్వచించు DEF_ASM_OP2(name, opcode, సమూహం, instr_type, op0, op1)
#నిర్వచించు DEF_ASM_OP3(name, opcode, సమూహం, instr_type, op0, op1, op2)
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
# include "x86_64-asm.h"
#లేకపోతే
# include "i386-asm.h"
#అయితే_ముగింపు
};

స్థిర అంతఃవరుస పూర్ణాంకం get_reg_జరుపు(TCCState *s1)
{
    పూర్ణాంకం జరుపు, v;
    v = asm_int_సమాసం(s1);
    ఎంపిక(v) {
    స్థితి 1:
        జరుపు = 0;
        ఆపు;
    స్థితి 2:
        జరుపు = 1;
        ఆపు;
    స్థితి 4:
        జరుపు = 2;
        ఆపు;
    స్థితి 8:
        జరుపు = 3;
        ఆపు;
    అప్రమేయ:
        expect("1, 2, 4 or 8 constant");
        జరుపు = 0;
        ఆపు;
    }
    తిరిగి జరుపు;
}

#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
స్థిర పూర్ణాంకం asm_parse_numeric_reg(పూర్ణాంకం t, గుర్తులేని పూర్ణాంకం *type)
{
    పూర్ణాంకం reg = -1;
    ఒకవేళ (t >= TOK_IDENT && t < tok_ident) {
	స్థిరరాశి అక్షరం *s = పట్టిక_ident[t - TOK_IDENT]->str;
	అక్షరం c;
	*type = OP_REG64;
	ఒకవేళ (*s == 'c') {
	    s++;
	    *type = OP_CR;
	}
	ఒకవేళ (*s++ != 'r')
	  తిరిగి -1;
	/* Don't allow leading '0'.  */
	ఒకవేళ ((c = *s++) >= '1' && c <= '9')
	  reg = c - '0';
	లేకపోతే
	  తిరిగి -1;
	ఒకవేళ ((c = *s) >= '0' && c <= '5')
	  s++, reg = reg * 10 + c - '0';
	ఒకవేళ (reg > 15)
	  తిరిగి -1;
	ఒకవేళ ((c = *s) == 0)
	  ;
	లేకపోతే ఒకవేళ (*type != OP_REG64)
	  తిరిగి -1;
	లేకపోతే ఒకవేళ (c == 'b' && !s[1])
	  *type = OP_REG8;
	లేకపోతే ఒకవేళ (c == 'w' && !s[1])
	  *type = OP_REG16;
	లేకపోతే ఒకవేళ (c == 'd' && !s[1])
	  *type = OP_REG32;
	లేకపోతే
	  తిరిగి -1;
    }
    తిరిగి reg;
}
#అయితే_ముగింపు

స్థిర పూర్ణాంకం asm_parse_reg(గుర్తులేని పూర్ణాంకం *type)
{
    పూర్ణాంకం reg = 0;
    *type = 0;
    ఒకవేళ (tok != '%')
        వెళ్ళు error_32;
    తదుపరి();
    ఒకవేళ (tok >= TOK_ASM_eax && tok <= TOK_ASM_edi) {
        reg = tok - TOK_ASM_eax;
	*type = OP_REG32;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    } లేకపోతే ఒకవేళ (tok >= TOK_ASM_rax && tok <= TOK_ASM_rdi) {
        reg = tok - TOK_ASM_rax;
	*type = OP_REG64;
    } లేకపోతే ఒకవేళ (tok == TOK_ASM_rip) {
        reg = -2; /* Probably should use different escape code. */
	*type = OP_REG64;
    } లేకపోతే ఒకవేళ ((reg = asm_parse_numeric_reg(tok, type)) >= 0
	       && (*type == OP_REG32 || *type == OP_REG64)) {
	;
#అయితే_ముగింపు
    } లేకపోతే {
    error_32:
        expect("register");
    }
    తదుపరి();
    తిరిగి reg;
}

స్థిర శూన్య parse_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op)
{
    సమాసం_విలువ e;
    పూర్ణాంకం reg, indir;
    స్థిరరాశి అక్షరం *p;

    indir = 0;
    ఒకవేళ (tok == '*') {
        తదుపరి();
        indir = OP_INDIR;
    }

    ఒకవేళ (tok == '%') {
        తదుపరి();
        ఒకవేళ (tok >= TOK_ASM_al && tok <= TOK_ASM_db7) {
            reg = tok - TOK_ASM_al;
            op->type = 1 << (reg >> 3); /* WARNING: do not change constant order */
            op->reg = reg & 7;
            ఒకవేళ ((op->type & OP_REG) && op->reg == TREG_XAX)
                op->type |= OP_EAX;
            లేకపోతే ఒకవేళ (op->type == OP_REG8 && op->reg == TREG_XCX)
                op->type |= OP_CL;
            లేకపోతే ఒకవేళ (op->type == OP_REG16 && op->reg == TREG_XDX)
                op->type |= OP_DX;
        } లేకపోతే ఒకవేళ (tok >= TOK_ASM_dr0 && tok <= TOK_ASM_dr7) {
            op->type = OP_DB;
            op->reg = tok - TOK_ASM_dr0;
        } లేకపోతే ఒకవేళ (tok >= TOK_ASM_es && tok <= TOK_ASM_gs) {
            op->type = OP_SEG;
            op->reg = tok - TOK_ASM_es;
        } లేకపోతే ఒకవేళ (tok == TOK_ASM_st) {
            op->type = OP_ST;
            op->reg = 0;
            తదుపరి();
            ఒకవేళ (tok == '(') {
                తదుపరి();
                ఒకవేళ (tok != TOK_PPNUM)
                    వెళ్ళు reg_error;
                p = tokc.str.దత్తాంశం;
                reg = p[0] - '0';
                ఒకవేళ ((గుర్తులేని)reg >= 8 || p[1] != '\0')
                    వెళ్ళు reg_error;
                op->reg = reg;
                తదుపరి();
                skip(')');
            }
            ఒకవేళ (op->reg == 0)
                op->type |= OP_ST0;
            వెళ్ళు no_skip;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
	} లేకపోతే ఒకవేళ (tok >= TOK_ASM_spl && tok <= TOK_ASM_dil) {
	    op->type = OP_REG8 | OP_REG8_దిగువ;
	    op->reg = 4 + tok - TOK_ASM_spl;
        } లేకపోతే ఒకవేళ ((op->reg = asm_parse_numeric_reg(tok, &op->type)) >= 0) {
	    ;
#అయితే_ముగింపు
        } లేకపోతే {
        reg_error:
            tcc_error("unknown register %%%s", get_tok_str(tok, &tokc));
        }
        తదుపరి();
    no_skip: ;
    } లేకపోతే ఒకవేళ (tok == '$') {
        /* constant value */
        తదుపరి();
        asm_సమాసం(s1, &e);
        op->type = OP_IM32;
        op->e = e;
        ఒకవేళ (!op->e.sym) {
            ఒకవేళ (op->e.v == (uint8_t)op->e.v)
                op->type |= OP_IM8;
            ఒకవేళ (op->e.v == (int8_t)op->e.v)
                op->type |= OP_IM8S;
            ఒకవేళ (op->e.v == (uint16_t)op->e.v)
                op->type |= OP_IM16;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
            ఒకవేళ (op->e.v != (int32_t)op->e.v && op->e.v != (uint32_t)op->e.v)
                op->type = OP_IM64;
#అయితే_ముగింపు
        }
    } లేకపోతే {
        /* address(reg,reg2,shift) with all variants */
        op->type = OP_EA;
        op->reg = -1;
        op->reg2 = -1;
        op->జరుపు = 0;
        ఒకవేళ (tok != '(') {
            asm_సమాసం(s1, &e);
            op->e = e;
        } లేకపోతే {
            తదుపరి();
            ఒకవేళ (tok == '%') {
                unget_tok('(');
                op->e.v = 0;
                op->e.sym = ఖాళీ;
            } లేకపోతే {
                /* bracketed offset expression */
                asm_సమాసం(s1, &e);
                ఒకవేళ (tok != ')')
                    expect(")");
                తదుపరి();
                op->e.v = e.v;
                op->e.sym = e.sym;
            }
	    op->e.pcrel = 0;
        }
        ఒకవేళ (tok == '(') {
	    గుర్తులేని పూర్ణాంకం type = 0;
            తదుపరి();
            ఒకవేళ (tok != ',') {
                op->reg = asm_parse_reg(&type);
            }
            ఒకవేళ (tok == ',') {
                తదుపరి();
                ఒకవేళ (tok != ',') {
                    op->reg2 = asm_parse_reg(&type);
                }
                ఒకవేళ (tok == ',') {
                    తదుపరి();
                    op->జరుపు = get_reg_జరుపు(s1);
                }
            }
	    ఒకవేళ (type & OP_REG32)
	        op->type |= OP_EA32;
            skip(')');
        }
        ఒకవేళ (op->reg == -1 && op->reg2 == -1)
            op->type |= OP_ADDR;
    }
    op->type |= indir;
}

/* XXX: unify with C code output ? */
ST_FUNC శూన్య gen_expr32(సమాసం_విలువ *pe)
{
    ఒకవేళ (pe->pcrel)
        /* If PC-relative, always set VT_SYM, even without symbol,
	   so as to force a relocation to be emitted.  */
	gen_addrpc32(VT_SYM, pe->sym, pe->v + (ind + 4));
    లేకపోతే
	gen_addr32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}

/* XXX: unify with C code output ? */
స్థిర శూన్య gen_disp32(సమాసం_విలువ *pe)
{
    Sym *sym = pe->sym;
    ElfSym *esym = elfsym(sym);
    ఒకవేళ (esym && esym->st_shndx == cur_పాఠ్యం_section->sh_అంకె) {
        /* same section: we can output an absolute value. Note
           that the TCC compiler behaves differently here because
           it always outputs a relocation to ease (future) code
           elimination in the linker */
        gen_le32(pe->v + esym->st_విలువ - ind - 4);
    } లేకపోతే {
        ఒకవేళ (sym && sym->type.t == VT_VOID) {
            sym->type.t = VT_FUNC;
            sym->type.ref = ఖాళీ;
        }
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
        greloca(cur_పాఠ్యం_section, sym, ind, R_X86_64_PLT32, pe->v - 4);
        gen_le32(0);
#లేకపోతే
        gen_addrpc32(VT_SYM, sym, pe->v);
#అయితే_ముగింపు

    }
}

/* generate the modrm operand */
స్థిర అంతఃవరుస పూర్ణాంకం asm_modrm(పూర్ణాంకం reg, నిర్వాహ్యం *op)
{
    పూర్ణాంకం mod, reg1, reg2, sib_reg1;

    ఒకవేళ (op->type & (OP_REG | OP_MMX | OP_SSE)) {
        g(0xc0 + (reg << 3) + op->reg);
    } లేకపోతే ఒకవేళ (op->reg == -1 && op->reg2 == -1) {
        /* displacement only */
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
	g(0x04 + (reg << 3));
	g(0x25);
#లేకపోతే
	g(0x05 + (reg << 3));
#అయితే_ముగింపు
	gen_expr32(&op->e);
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    } లేకపోతే ఒకవేళ (op->reg == -2) {
        సమాసం_విలువ *pe = &op->e;
        g(0x05 + (reg << 3));
        gen_addrpc32(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
        తిరిగి ind;
#అయితే_ముగింపు
    } లేకపోతే {
        sib_reg1 = op->reg;
        /* fist compute displacement encoding */
        ఒకవేళ (sib_reg1 == -1) {
            sib_reg1 = 5;
            mod = 0x00;
        } లేకపోతే ఒకవేళ (op->e.v == 0 && !op->e.sym && op->reg != 5) {
            mod = 0x00;
        } లేకపోతే ఒకవేళ (op->e.v == (int8_t)op->e.v && !op->e.sym) {
            mod = 0x40;
        } లేకపోతే {
            mod = 0x80;
        }
        /* compute if sib byte needed */
        reg1 = op->reg;
        ఒకవేళ (op->reg2 != -1)
            reg1 = 4;
        g(mod + (reg << 3) + reg1);
        ఒకవేళ (reg1 == 4) {
            /* add sib byte */
            reg2 = op->reg2;
            ఒకవేళ (reg2 == -1)
                reg2 = 4; /* indicate no index */
            g((op->జరుపు << 6) + (reg2 << 3) + sib_reg1);
        }
        /* add offset */
        ఒకవేళ (mod == 0x40) {
            g(op->e.v);
        } లేకపోతే ఒకవేళ (mod == 0x80 || op->reg == -1) {
	    gen_expr32(&op->e);
        }
    }
    తిరిగి 0;
}

#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
#నిర్వచించు REX_W 0x48
#నిర్వచించు REX_R 0x44
#నిర్వచించు REX_X 0x42
#నిర్వచించు REX_B 0x41

స్థిర శూన్య asm_rex(పూర్ణాంకం width64, నిర్వాహ్యం *ops, పూర్ణాంకం nb_ops, పూర్ణాంకం *op_type,
		    పూర్ణాంకం regi, పూర్ణాంకం rmi)
{
  గుర్తులేని అక్షరం rex = width64 ? 0x48 : 0;
  పూర్ణాంకం saw_ఎగువ_8bit = 0;
  పూర్ణాంకం i;
  ఒకవేళ (rmi == -1) {
      /* No mod/rm byte, but we might have a register op nevertheless
         (we will add it to the opcode later).  */
      కొరకు(i = 0; i < nb_ops; i++) {
	  ఒకవేళ (op_type[i] & (OP_REG | OP_ST)) {
	      ఒకవేళ (ops[i].reg >= 8) {
		  rex |= REX_B;
		  ops[i].reg -= 8;
	      } లేకపోతే ఒకవేళ (ops[i].type & OP_REG8_దిగువ)
		  rex |= 0x40;
	      లేకపోతే ఒకవేళ (ops[i].type & OP_REG8 && ops[i].reg >= 4)
		  /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
		  saw_ఎగువ_8bit = ops[i].reg;
	      ఆపు;
	  }
      }
  } లేకపోతే {
      ఒకవేళ (regi != -1) {
	  ఒకవేళ (ops[regi].reg >= 8) {
	      rex |= REX_R;
	      ops[regi].reg -= 8;
	  } లేకపోతే ఒకవేళ (ops[regi].type & OP_REG8_దిగువ)
	      rex |= 0x40;
	  లేకపోతే ఒకవేళ (ops[regi].type & OP_REG8 && ops[regi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_ఎగువ_8bit = ops[regi].reg;
      }
      ఒకవేళ (ops[rmi].type & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_EA)) {
	  ఒకవేళ (ops[rmi].reg >= 8) {
	      rex |= REX_B;
	      ops[rmi].reg -= 8;
	  } లేకపోతే ఒకవేళ (ops[rmi].type & OP_REG8_దిగువ)
	      rex |= 0x40;
	  లేకపోతే ఒకవేళ (ops[rmi].type & OP_REG8 && ops[rmi].reg >= 4)
	      /* An 8 bit reg >= 4 without REG8 is ah/ch/dh/bh */
	      saw_ఎగువ_8bit = ops[rmi].reg;
      }
      ఒకవేళ (ops[rmi].type & OP_EA && ops[rmi].reg2 >= 8) {
	  rex |= REX_X;
	  ops[rmi].reg2 -= 8;
      }
  }
  ఒకవేళ (rex) {
      ఒకవేళ (saw_ఎగువ_8bit)
	  tcc_error("can't encode register %%%ch when REX prefix is required",
		    "acdb"[saw_ఎగువ_8bit-4]);
      g(rex);
  }
}
#అయితే_ముగింపు


స్థిర శూన్య maybe_print_stats (శూన్య)
{
    స్థిర పూర్ణాంకం already;

    ఒకవేళ (0 && !already)
    /* print stats about opcodes */
    {
        స్థిరరాశి నిర్మాణం ASMInstr *pa;
        పూర్ణాంకం freq[4];
        పూర్ణాంకం op_vals[500];
        పూర్ణాంకం nb_op_vals, i, j;

	already = 1;
        nb_op_vals = 0;
        memset(freq, 0, పరిమాణం(freq));
        కొరకు(pa = asm_instrs; pa->sym != 0; pa++) {
            freq[pa->nb_ops]++;
            //for(i=0;i<pa->nb_ops;i++) {
                కొరకు(j=0;j<nb_op_vals;j++) {
                    //if (pa->op_type[i] == op_vals[j])
                    ఒకవేళ (pa->instr_type == op_vals[j])
                        వెళ్ళు దొరికింది;
                }
                //op_vals[nb_op_vals++] = pa->op_type[i];
                op_vals[nb_op_vals++] = pa->instr_type;
            దొరికింది: ;
            //}
        }
        కొరకు(i=0;i<nb_op_vals;i++) {
            పూర్ణాంకం v = op_vals[i];
            //if ((v & (v - 1)) != 0)
                రాయి("%3d: %08x\n", i, v);
        }
        రాయి("size=%d nb=%d f0=%d f1=%d f2=%d f3=%d\n",
               (పూర్ణాంకం)పరిమాణం(asm_instrs),
	       (పూర్ణాంకం)పరిమాణం(asm_instrs) / (పూర్ణాంకం)పరిమాణం(ASMInstr),
               freq[0], freq[1], freq[2], freq[3]);
    }
}

ST_FUNC శూన్య asm_opcode(TCCState *s1, పూర్ణాంకం opcode)
{
    స్థిరరాశి ASMInstr *pa;
    పూర్ణాంకం i, modrm_సూచీ, modreg_సూచీ, reg, v, op1, seg_ఉపసర్గ, pc, p;
    పూర్ణాంకం nb_ops, s;
    నిర్వాహ్యం ops[MAX_OPERANDS], *తీయి;
    పూర్ణాంకం op_type[3]; /* decoded op type */
    పూర్ణాంకం alltypes;   /* OR of all operand types */
    పూర్ణాంకం autosize;
    పూర్ణాంకం p66;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    పూర్ణాంకం rex64;
#అయితే_ముగింపు

    maybe_print_stats();
    /* force synthetic ';' after prefix instruction, so we can handle */
    /* one-line things like "rep stosb" instead of only "rep\nstosb" */
    ఒకవేళ (opcode >= TOK_ASM_wait && opcode <= TOK_ASM_repnz)
        unget_tok(';');

    /* get operands */
    తీయి = ops;
    nb_ops = 0;
    seg_ఉపసర్గ = 0;
    alltypes = 0;
    కొరకు(;;) {
        ఒకవేళ (tok == ';' || tok == TOK_LINEFEED)
            ఆపు;
        ఒకవేళ (nb_ops >= MAX_OPERANDS) {
            tcc_error("incorrect number of operands");
        }
        parse_నిర్వాహ్యం(s1, తీయి);
        ఒకవేళ (tok == ':') {
           ఒకవేళ (!(తీయి->type & OP_SEG) || seg_ఉపసర్గ)
               tcc_error("incorrect prefix");
           seg_ఉపసర్గ = segment_prefixes[తీయి->reg];
           తదుపరి();
           parse_నిర్వాహ్యం(s1, తీయి);
           ఒకవేళ (!(తీయి->type & OP_EA)) {
               tcc_error("segment prefix must be followed by memory reference");
           }
        }
        తీయి++;
        nb_ops++;
        ఒకవేళ (tok != ',')
            ఆపు;
        తదుపరి();
    }

    s = 0; /* avoid warning */

again:
    /* optimize matching by using a lookup table (no hashing is needed
       !) */
    కొరకు(pa = asm_instrs; pa->sym != 0; pa++) {
	పూర్ణాంకం it = pa->instr_type & OPCT_ముసుగు;
        s = 0;
        ఒకవేళ (it == OPC_FARITH) {
            v = opcode - pa->sym;
            ఒకవేళ (!((గుర్తులేని)v < 8 * 6 && (v % 6) == 0))
                కొనసాగు;
        } లేకపోతే ఒకవేళ (it == OPC_ARITH) {
            ఒకవేళ (!(opcode >= pa->sym && opcode < pa->sym + 8*NBWLX))
                కొనసాగు;
            s = (opcode - pa->sym) % NBWLX;
	    ఒకవేళ ((pa->instr_type & OPC_BWLX) == OPC_WLX)
	      {
		/* We need to reject the xxxb opcodes that we accepted above.
		   Note that pa->sym for WLX opcodes is the 'w' token,
		   to get the 'b' token subtract one.  */
		ఒకవేళ (((opcode - pa->sym + 1) % NBWLX) == 0)
		    కొనసాగు;
	        s++;
	      }
        } లేకపోతే ఒకవేళ (it == OPC_జరుపు) {
            ఒకవేళ (!(opcode >= pa->sym && opcode < pa->sym + 7*NBWLX))
                కొనసాగు;
            s = (opcode - pa->sym) % NBWLX;
        } లేకపోతే ఒకవేళ (it == OPC_TEST) {
            ఒకవేళ (!(opcode >= pa->sym && opcode < pa->sym + NB_TEST_OPCODES))
                కొనసాగు;
	    /* cmovxx is a test opcode but accepts multiple sizes.
	       The suffixes aren't encoded in the table, instead we
	       simply force size autodetection always and deal with suffixed
	       variants below when we don't find e.g. "cmovzl".  */
	    ఒకవేళ (pa->instr_type & OPC_WLX)
	        s = NBWLX - 1;
        } లేకపోతే ఒకవేళ (pa->instr_type & OPC_B) {
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
	    /* Some instructions don't have the full size but only
	       bwl form.  insb e.g. */
	    ఒకవేళ ((pa->instr_type & OPC_WLQ) != OPC_WLQ
		&& !(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
	        కొనసాగు;
#అయితే_ముగింపు
            ఒకవేళ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX))
                కొనసాగు;
            s = opcode - pa->sym;
        } లేకపోతే ఒకవేళ (pa->instr_type & OPC_WLX) {
            ఒకవేళ (!(opcode >= pa->sym && opcode < pa->sym + NBWLX-1))
                కొనసాగు;
            s = opcode - pa->sym + 1;
        } లేకపోతే {
            ఒకవేళ (pa->sym != opcode)
                కొనసాగు;
        }
        ఒకవేళ (pa->nb_ops != nb_ops)
            కొనసాగు;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
	/* Special case for moves.  Selecting the IM64->REG64 form
	   should only be done if we really have an >32bit imm64, and that
	   is hardcoded.  Ignore it here.  */
	ఒకవేళ (pa->opcode == 0xb0 && ops[0].type != OP_IM64
	    && (ops[1].type & OP_REG) == OP_REG64
	    && !(pa->instr_type & OPC_0F))
	    కొనసాగు;
#అయితే_ముగింపు
        /* now decode and check each operand */
	alltypes = 0;
        కొరకు(i = 0; i < nb_ops; i++) {
            పూర్ణాంకం op1, op2;
            op1 = pa->op_type[i];
            op2 = op1 & 0x1f;
            ఎంపిక(op2) {
            స్థితి OPT_IM:
                v = OP_IM8 | OP_IM16 | OP_IM32;
                ఆపు;
            స్థితి OPT_REG:
                v = OP_REG8 | OP_REG16 | OP_REG32 | OP_REG64;
                ఆపు;
            స్థితి OPT_REGW:
                v = OP_REG16 | OP_REG32 | OP_REG64;
                ఆపు;
            స్థితి OPT_IMW:
                v = OP_IM16 | OP_IM32;
                ఆపు;
	    స్థితి OPT_MMXSSE:
		v = OP_MMX | OP_SSE;
		ఆపు;
	    స్థితి OPT_DISP:
	    స్థితి OPT_DISP8:
		v = OP_ADDR;
		ఆపు;
            అప్రమేయ:
                v = 1 << op2;
                ఆపు;
            }
            ఒకవేళ (op1 & OPT_EA)
                v |= OP_EA;
	    op_type[i] = v;
            ఒకవేళ ((ops[i].type & v) == 0)
                వెళ్ళు తదుపరి;
	    alltypes |= ops[i].type;
        }
        (శూన్య)alltypes; /* maybe unused */
        /* all is matching ! */
        ఆపు;
    తదుపరి: ;
    }
    ఒకవేళ (pa->sym == 0) {
        ఒకవేళ (opcode >= TOK_ASM_మొదటి && opcode <= TOK_ASM_చివరి) {
            పూర్ణాంకం b;
            b = op0_codes[opcode - TOK_ASM_మొదటి];
            ఒకవేళ (b & 0xff00)
                g(b >> 8);
            g(b);
            తిరిగి;
        } లేకపోతే ఒకవేళ (opcode <= TOK_ASM_alllast) {
            tcc_error("bad operand with opcode '%s'",
                  get_tok_str(opcode, ఖాళీ));
        } లేకపోతే {
	    /* Special case for cmovcc, we accept size suffixes but ignore
	       them, but we don't want them to blow up our tables.  */
	    TokenSym *ts = పట్టిక_ident[opcode - TOK_IDENT];
	    ఒకవేళ (ts->len >= 6
		&& strchr("wlq", ts->str[ts->len-1])
		&& !memcmp(ts->str, "cmov", 4)) {
		opcode = tok_alloc(ts->str, ts->len-1)->tok;
		వెళ్ళు again;
	    }
            tcc_error("unknown opcode '%s'", ts->str);
        }
    }
    /* if the size is unknown, then evaluate it (OPC_B or OPC_WL case) */
    autosize = NBWLX-1;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    /* XXX the autosize should rather be zero, to not have to adjust this
       all the time.  */
    ఒకవేళ ((pa->instr_type & OPC_BWLQ) == OPC_B)
        autosize = NBWLX-2;
#అయితే_ముగింపు
    ఒకవేళ (s == autosize) {
	/* Check for register operands providing hints about the size.
	   Start from the end, i.e. destination operands.  This matters
	   only for opcodes accepting different sized registers, lar and lsl
	   are such opcodes.  */
        కొరకు(i = nb_ops - 1; s == autosize && i >= 0; i--) {
            ఒకవేళ ((ops[i].type & OP_REG) && !(op_type[i] & (OP_CL | OP_DX)))
                s = reg_గమ్యం_కొలత[ops[i].type & OP_REG];
        }
        ఒకవేళ (s == autosize) {
            ఒకవేళ ((opcode == TOK_ASM_నెట్టు || opcode == TOK_ASM_తీయి) &&
                (ops[0].type & (OP_SEG | OP_IM8S | OP_IM32)))
                s = 2;
	    లేకపోతే ఒకవేళ ((opcode == TOK_ASM_నెట్టు || opcode == TOK_ASM_తీయి) &&
		     (ops[0].type & OP_EA))
	        s = NBWLX - 2;
            లేకపోతే
                tcc_error("cannot infer opcode suffix");
        }
    }

#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    rex64 = 0;
    ఒకవేళ (pa->instr_type & OPC_48)
        rex64 = 1;
    లేకపోతే ఒకవేళ (s == 3 || (alltypes & OP_REG64)) {
        /* generate REX prefix */
	పూర్ణాంకం default64 = 0;
	కొరకు(i = 0; i < nb_ops; i++) {
	    ఒకవేళ (op_type[i] == OP_REG64 && pa->opcode != 0xb8) {
		/* If only 64bit regs are accepted in one operand
		   this is a default64 instruction without need for
		   REX prefixes, except for movabs(0xb8).  */
		default64 = 1;
		ఆపు;
	    }
	}
	/* XXX find better encoding for the default64 instructions.  */
        ఒకవేళ (((opcode != TOK_ASM_నెట్టు && opcode != TOK_ASM_తీయి
	      && opcode != TOK_ASM_pushw && opcode != TOK_ASM_pushl
	      && opcode != TOK_ASM_pushq && opcode != TOK_ASM_popw
	      && opcode != TOK_ASM_popl && opcode != TOK_ASM_popq
	      && opcode != TOK_ASM_call && opcode != TOK_ASM_jmp))
	    && !default64)
            rex64 = 1;
    }
#అయితే_ముగింపు

    /* now generates the operation */
    ఒకవేళ (OPCT_IS(pa->instr_type, OPC_FWAIT))
        g(0x9b);
    ఒకవేళ (seg_ఉపసర్గ)
        g(seg_ఉపసర్గ);
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    /* Generate addr32 prefix if needed */
    కొరకు(i = 0; i < nb_ops; i++) {
        ఒకవేళ (ops[i].type & OP_EA32) {
	    g(0x67);
	    ఆపు;
        }
    }
#అయితే_ముగింపు
    /* generate data16 prefix if needed */
    p66 = 0;
    ఒకవేళ (s == 1)
        p66 = 1;
    లేకపోతే {
	/* accepting mmx+sse in all operands --> needs 0x66 to
	   switch to sse mode.  Accepting only sse in an operand --> is
	   already SSE insn and needs 0x66/f2/f3 handling.  */
        కొరకు (i = 0; i < nb_ops; i++)
            ఒకవేళ ((op_type[i] & (OP_MMX | OP_SSE)) == (OP_MMX | OP_SSE)
	        && ops[i].type & OP_SSE)
	        p66 = 1;
    }
    ఒకవేళ (p66)
        g(0x66);

    v = pa->opcode;
    p = v >> 8;  /* possibly prefix byte(s) */
    ఎంపిక (p) {
        స్థితి 0: ఆపు;  /* no prefix */
        స్థితి 0x48: ఆపు; /* REX, handled elsewhere */
        స్థితి 0x66:
        స్థితి 0x67:
        స్థితి 0xf2:
        స్థితి 0xf3: v = v & 0xff; g(p); ఆపు;
        స్థితి 0xd4: స్థితి 0xd5: ఆపు; /* aam and aad, not prefix, but hardcoded immediate argument "10" */
        స్థితి 0xd8: స్థితి 0xd9: స్థితి 0xda: స్థితి 0xdb: /* x87, no normal prefix */
        స్థితి 0xdc: స్థితి 0xdd: స్థితి 0xde: స్థితి 0xdf: ఆపు;
        అప్రమేయ: tcc_error("bad prefix 0x%2x in opcode table", p); ఆపు;
    }
    ఒకవేళ (pa->instr_type & OPC_0F)
        v = ((v & ~0xff) << 8) | 0x0f00 | (v & 0xff);
    ఒకవేళ ((v == 0x69 || v == 0x6b) && nb_ops == 2) {
        /* kludge for imul $im, %reg */
        nb_ops = 3;
        ops[2] = ops[1];
        op_type[2] = op_type[1];
    } లేకపోతే ఒకవేళ (v == 0xcd && ops[0].e.v == 3 && !ops[0].e.sym) {
        v--; /* int $3 case */
        nb_ops = 0;
    } లేకపోతే ఒకవేళ ((v == 0x06 || v == 0x07)) {
        ఒకవేళ (ops[0].reg >= 4) {
            /* push/pop %fs or %gs */
            v = 0x0fa0 + (v - 0x06) + ((ops[0].reg - 4) << 3);
        } లేకపోతే {
            v += ops[0].reg << 3;
        }
        nb_ops = 0;
    } లేకపోతే ఒకవేళ (v <= 0x05) {
        /* arith case */
        v += ((opcode - TOK_ASM_addb) / NBWLX) << 3;
    } లేకపోతే ఒకవేళ ((pa->instr_type & (OPCT_ముసుగు | OPC_MODRM)) == OPC_FARITH) {
        /* fpu arith case */
        v += ((opcode - pa->sym) / 6) << 3;
    }

    /* search which operand will be used for modrm */
    modrm_సూచీ = -1;
    modreg_సూచీ = -1;
    ఒకవేళ (pa->instr_type & OPC_MODRM) {
	ఒకవేళ (!nb_ops) {
	    /* A modrm opcode without operands is a special case (e.g. mfence).
	       It has a group and acts as if there's an register operand 0 */
	    i = 0;
	    ops[i].type = OP_REG;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
	    ఒకవేళ (pa->sym == TOK_ASM_endbr64)
	      ops[i].reg = 2; // dx
	    లేకపోతే ఒకవేళ (pa->sym >= TOK_ASM_lfence && pa->sym <= TOK_ASM_sfence)
  	      ops[i].reg = 0; // ax
#లేకపోతే
	    ఒకవేళ (pa->sym == TOK_ASM_endbr32)
	      ops[i].reg = 3; // bx
#అయితే_ముగింపు
	    లేకపోతే
	      tcc_error("bad MODR/M opcode without operands");
	    వెళ్ళు modrm_దొరికింది;
	}
        /* first look for an ea operand */
        కొరకు(i = 0;i < nb_ops; i++) {
            ఒకవేళ (op_type[i] & OP_EA)
                వెళ్ళు modrm_దొరికింది;
        }
        /* then if not found, a register or indirection (shift instructions) */
        కొరకు(i = 0;i < nb_ops; i++) {
            ఒకవేళ (op_type[i] & (OP_REG | OP_MMX | OP_SSE | OP_INDIR))
                వెళ్ళు modrm_దొరికింది;
        }
#నిర్వచితమైతే ASM_DEBUG
        tcc_error("bad op table");
#అయితే_ముగింపు
    modrm_దొరికింది:
        modrm_సూచీ = i;
        /* if a register is used in another operand then it is
           used instead of group */
        కొరకు(i = 0;i < nb_ops; i++) {
            పూర్ణాంకం t = op_type[i];
            ఒకవేళ (i != modrm_సూచీ &&
                (t & (OP_REG | OP_MMX | OP_SSE | OP_CR | OP_TR | OP_DB | OP_SEG))) {
                modreg_సూచీ = i;
                ఆపు;
            }
        }
    }
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    asm_rex (rex64, ops, nb_ops, op_type, modreg_సూచీ, modrm_సూచీ);
#అయితే_ముగింపు

    ఒకవేళ (pa->instr_type & OPC_REG) {
        /* mov $im, %reg case */
        ఒకవేళ (v == 0xb0 && s >= 1)
            v += 7;
        కొరకు(i = 0; i < nb_ops; i++) {
            ఒకవేళ (op_type[i] & (OP_REG | OP_ST)) {
                v += ops[i].reg;
                ఆపు;
            }
        }
    }
    ఒకవేళ (pa->instr_type & OPC_B)
        v += s >= 1;
    ఒకవేళ (nb_ops == 1 && pa->op_type[0] == OPT_DISP8) {
	ElfSym *esym;
        పూర్ణాంకం jmp_disp;

        /* see if we can really generate the jump with a byte offset */
	esym = elfsym(ops[0].e.sym);
        ఒకవేళ (!esym || esym->st_shndx != cur_పాఠ్యం_section->sh_అంకె)
            వెళ్ళు no_short_jump;
        jmp_disp = ops[0].e.v + esym->st_విలువ - ind - 2 - (v >= 0xff);
        ఒకవేళ (jmp_disp == (int8_t)jmp_disp) {
            /* OK to generate jump */
	    ops[0].e.sym = 0;
            ops[0].e.v = jmp_disp;
	    op_type[0] = OP_IM8S;
        } లేకపోతే {
        no_short_jump:
	    /* long jump will be allowed. need to modify the
	       opcode slightly */
	    ఒకవేళ (v == 0xeb) /* jmp */
	        v = 0xe9;
	    లేకపోతే ఒకవేళ (v == 0x70) /* jcc */
	        v += 0x0f10;
	    లేకపోతే
	        tcc_error("invalid displacement");
        }
    }
    ఒకవేళ (OPCT_IS(pa->instr_type, OPC_TEST))
        v += test_బిట్లు[opcode - pa->sym];
    లేకపోతే ఒకవేళ (OPCT_IS(pa->instr_type, OPC_0F01))
        v |= 0x0f0100;
    op1 = v >> 16;
    ఒకవేళ (op1)
        g(op1);
    op1 = (v >> 8) & 0xff;
    ఒకవేళ (op1)
        g(op1);
    g(v);

    ఒకవేళ (OPCT_IS(pa->instr_type, OPC_జరుపు)) {
        reg = (opcode - pa->sym) / NBWLX;
        ఒకవేళ (reg == 6)
            reg = 7;
    } లేకపోతే ఒకవేళ (OPCT_IS(pa->instr_type, OPC_ARITH)) {
        reg = (opcode - pa->sym) / NBWLX;
    } లేకపోతే ఒకవేళ (OPCT_IS(pa->instr_type, OPC_FARITH)) {
        reg = (opcode - pa->sym) / 6;
    } లేకపోతే {
        reg = (pa->instr_type >> OPC_సమూహం_జరుపు) & 7;
    }

    pc = 0;
    ఒకవేళ (pa->instr_type & OPC_MODRM) {
        /* if a register is used in another operand then it is
           used instead of group */
	ఒకవేళ (modreg_సూచీ >= 0)
	    reg = ops[modreg_సూచీ].reg;
        pc = asm_modrm(reg, &ops[modrm_సూచీ]);
    }

    /* emit constants */
#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_X86_64
    ఒకవేళ (!(pa->instr_type & OPC_0F)
	&& (pa->opcode == 0x9a || pa->opcode == 0xea)) {
        /* ljmp or lcall kludge */
	gen_expr32(&ops[1].e);
        ఒకవేళ (ops[0].e.sym)
            tcc_error("cannot relocate");
        gen_le16(ops[0].e.v);
        తిరిగి;
    }
#అయితే_ముగింపు
    కొరకు(i = 0;i < nb_ops; i++) {
        v = op_type[i];
        ఒకవేళ (v & (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64 | OP_IM8S | OP_ADDR)) {
            /* if multiple sizes are given it means we must look
               at the op size */
            ఒకవేళ ((v | OP_IM8 | OP_IM64) == (OP_IM8 | OP_IM16 | OP_IM32 | OP_IM64)) {
                ఒకవేళ (s == 0)
                    v = OP_IM8;
                లేకపోతే ఒకవేళ (s == 1)
                    v = OP_IM16;
                లేకపోతే ఒకవేళ (s == 2 || (v & OP_IM64) == 0)
                    v = OP_IM32;
                లేకపోతే
                    v = OP_IM64;
            }

            ఒకవేళ ((v & (OP_IM8 | OP_IM8S | OP_IM16)) && ops[i].e.sym)
                tcc_error("cannot relocate");

            ఒకవేళ (v & (OP_IM8 | OP_IM8S)) {
                g(ops[i].e.v);
            } లేకపోతే ఒకవేళ (v & OP_IM16) {
                gen_le16(ops[i].e.v);
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
            } లేకపోతే ఒకవేళ (v & OP_IM64) {
                gen_expr64(&ops[i].e);
#అయితే_ముగింపు
	    } లేకపోతే ఒకవేళ (pa->op_type[i] == OPT_DISP || pa->op_type[i] == OPT_DISP8) {
                gen_disp32(&ops[i].e);
            } లేకపోతే {
                gen_expr32(&ops[i].e);
            }
        }
    }

    /* after immediate operands, adjust pc-relative address */
    ఒకవేళ (pc)
        add32le(cur_పాఠ్యం_section->దత్తాంశం + pc - 4, pc - ind);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
స్థిర అంతఃవరుస పూర్ణాంకం constraint_ప్రాధాన్యత(స్థిరరాశి అక్షరం *str)
{
    పూర్ణాంకం ప్రాధాన్యత, c, pr;

    /* we take the lowest priority */
    ప్రాధాన్యత = 0;
    కొరకు(;;) {
        c = *str;
        ఒకవేళ (c == '\0')
            ఆపు;
        str++;
        ఎంపిక(c) {
        స్థితి 'A':
            pr = 0;
            ఆపు;
        స్థితి 'a':
        స్థితి 'b':
        స్థితి 'c':
        స్థితి 'd':
        స్థితి 'S':
        స్థితి 'D':
            pr = 1;
            ఆపు;
        స్థితి 'q':
            pr = 2;
            ఆపు;
        స్థితి 'r':
	స్థితి 'R':
	స్థితి 'p':
            pr = 3;
            ఆపు;
        స్థితి 'N':
        స్థితి 'M':
        స్థితి 'I':
	స్థితి 'e':
        స్థితి 'i':
        స్థితి 'm':
        స్థితి 'g':
            pr = 4;
            ఆపు;
        అప్రమేయ:
            tcc_error("unknown constraint '%c'", c);
            pr = 0;
        }
        ఒకవేళ (pr > ప్రాధాన్యత)
            ప్రాధాన్యత = pr;
    }
    తిరిగి ప్రాధాన్యత;
}

స్థిర స్థిరరాశి అక్షరం *skip_constraint_modifiers(స్థిరరాశి అక్షరం *p)
{
    అయితే (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    తిరిగి p;
}

/* If t (a token) is of the form "%reg" or "reg" return the register number and
   type, otherwise return -1. With GCC the % is optional, too. */
ST_FUNC పూర్ణాంకం asm_parse_regvar (పూర్ణాంకం t)
{
    స్థిరరాశి అక్షరం *s;
    నిర్వాహ్యం op;
    ఒకవేళ (t < TOK_IDENT || (t & SYM_క్షేత్రం))
        తిరిగి -1;
    s = పట్టిక_ident[t - TOK_IDENT]->str;
    ఒకవేళ (s[0] == '%')
        ++s;
    t = tok_alloc_const(s);
    unget_tok(t);
    /* Internally the % prefix is required. */
    unget_tok('%');
    parse_నిర్వాహ్యం(tcc_state, &op);
    /* Accept only integer regs for now. */
    ఒకవేళ (op.type & OP_REG)
        తిరిగి op.reg;
    లేకపోతే
        తిరిగి -1;
}

#నిర్వచించు REG_బహిర్గతం_ముసుగు 0x01
#నిర్వచించు REG_లోపల_ముసుగు  0x02

#నిర్వచించు is_reg_allocated(reg) (regs_allocated[reg] & reg_ముసుగు)

ST_FUNC శూన్య asm_compute_constraints(ASMOperand *operands,
                                    పూర్ణాంకం nb_operands, పూర్ణాంకం nb_outputs,
                                    స్థిరరాశి uint8_t *clobber_regs,
                                    పూర్ణాంకం *pout_reg)
{
    ASMOperand *op;
    పూర్ణాంకం sorted_op[MAX_ASM_OPERANDS];
    పూర్ణాంకం i, j, k, p1, p2, tmp, reg, c, reg_ముసుగు;
    స్థిరరాశి అక్షరం *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    కొరకు(i=0;i<nb_operands;i++) {
        op = &operands[i];
        op->ఆదానం_సూచీ = -1;
        op->ref_సూచీ = -1;
        op->reg = -1;
        op->is_జ్ఞాపకం = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    కొరకు(i=0;i<nb_operands;i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ఒకవేళ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = కనుగొను_constraint(operands, nb_operands, str, ఖాళీ);
            ఒకవేళ ((గుర్తులేని)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                      i, str);
            op->ref_సూచీ = k;
            ఒకవేళ (operands[k].ఆదానం_సూచీ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ఆదానం_సూచీ = i;
            op->ప్రాధాన్యత = 5;
	} లేకపోతే ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LOCAL
		   && op->vt->sym
		   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
	    op->ప్రాధాన్యత = 1;
	    op->reg = reg;
        } లేకపోతే {
            op->ప్రాధాన్యత = constraint_ప్రాధాన్యత(str);
        }
    }

    /* sort operands according to their priority */
    కొరకు(i=0;i<nb_operands;i++)
        sorted_op[i] = i;
    కొరకు(i=0;i<nb_operands - 1;i++) {
        కొరకు(j=i+1;j<nb_operands;j++) {
            p1 = operands[sorted_op[i]].ప్రాధాన్యత;
            p2 = operands[sorted_op[j]].ప్రాధాన్యత;
            ఒకవేళ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    కొరకు(i = 0;i < NB_ASM_REGS; i++) {
        ఒకవేళ (clobber_regs[i])
            regs_allocated[i] = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
        లేకపోతే
            regs_allocated[i] = 0;
    }
    /* esp cannot be used */
    regs_allocated[4] = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
    /* ebp cannot be used yet */
    regs_allocated[5] = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;

    /* allocate registers and generate corresponding asm moves */
    కొరకు(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ఒకవేళ (op->ref_సూచీ >= 0)
            కొనసాగు;
        /* select if register is used for output, input or both */
        ఒకవేళ (op->ఆదానం_సూచీ >= 0) {
            reg_ముసుగు = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
        } లేకపోతే ఒకవేళ (j < nb_outputs) {
            reg_ముసుగు = REG_బహిర్గతం_ముసుగు;
        } లేకపోతే {
            reg_ముసుగు = REG_లోపల_ముసుగు;
        }
	ఒకవేళ (op->reg >= 0) {
	    ఒకవేళ (is_reg_allocated(op->reg))
	        tcc_error("asm regvar requests register that's taken already");
	    reg = op->reg;
	}
    try_తదుపరి:
        c = *str++;
        ఎంపిక(c) {
        స్థితి '=':
            వెళ్ళు try_తదుపరి;
        స్థితి '+':
            op->is_rw = 1;
            /* FALL THRU */
        స్థితి '&':
            ఒకవేళ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_ముసుగు = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
            వెళ్ళు try_తదుపరి;
        స్థితి 'A':
            /* allocate both eax and edx */
            ఒకవేళ (is_reg_allocated(TREG_XAX) ||
                is_reg_allocated(TREG_XDX))
                వెళ్ళు try_తదుపరి;
            op->is_llong = 1;
            op->reg = TREG_XAX;
            regs_allocated[TREG_XAX] |= reg_ముసుగు;
            regs_allocated[TREG_XDX] |= reg_ముసుగు;
            ఆపు;
        స్థితి 'a':
            reg = TREG_XAX;
            వెళ్ళు alloc_reg;
        స్థితి 'b':
            reg = 3;
            వెళ్ళు alloc_reg;
        స్థితి 'c':
            reg = TREG_XCX;
            వెళ్ళు alloc_reg;
        స్థితి 'd':
            reg = TREG_XDX;
            వెళ్ళు alloc_reg;
        స్థితి 'S':
            reg = 6;
            వెళ్ళు alloc_reg;
        స్థితి 'D':
            reg = 7;
        alloc_reg:
            ఒకవేళ (op->reg >= 0 && reg != op->reg)
                వెళ్ళు try_తదుపరి;
            ఒకవేళ (is_reg_allocated(reg))
                వెళ్ళు try_తదుపరి;
            వెళ్ళు reg_దొరికింది;
        స్థితి 'q':
            /* eax, ebx, ecx or edx */
            ఒకవేళ (op->reg >= 0) {
                ఒకవేళ ((reg = op->reg) < 4)
                    వెళ్ళు reg_దొరికింది;
            } లేకపోతే కొరకు(reg = 0; reg < 4; reg++) {
                ఒకవేళ (!is_reg_allocated(reg))
                    వెళ్ళు reg_దొరికింది;
            }
            వెళ్ళు try_తదుపరి;
        స్థితి 'r':
	స్థితి 'R':
	స్థితి 'p': /* A general address, for x86(64) any register is acceptable*/
            /* any general register */
            ఒకవేళ ((reg = op->reg) >= 0)
                వెళ్ళు reg_దొరికింది;
            లేకపోతే కొరకు(reg = 0; reg < NB_ASM_REGS; reg++) {
                ఒకవేళ (!is_reg_allocated(reg))
                    వెళ్ళు reg_దొరికింది;
            }
            వెళ్ళు try_తదుపరి;
        reg_దొరికింది:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_ముసుగు;
            ఆపు;
	స్థితి 'e':
        స్థితి 'i':
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'I':
        స్థితి 'N':
        స్థితి 'M':
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'm':
        స్థితి 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ఒకవేళ (j < nb_outputs || c == 'm') {
                ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    కొరకు(reg = 0; reg < NB_ASM_REGS; reg++) {
                        ఒకవేళ (!(regs_allocated[reg] & REG_లోపల_ముసుగు))
                            వెళ్ళు reg_found1;
                    }
                    వెళ్ళు try_తదుపరి;
                reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_లోపల_ముసుగు;
                    op->reg = reg;
                    op->is_జ్ఞాపకం = 1;
                }
            }
            ఆపు;
        అప్రమేయ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                  j, op->constraint);
            ఆపు;
        }
        /* if a reference is present for that operand, we assign it too */
        ఒకవేళ (op->ఆదానం_సూచీ >= 0) {
            operands[op->ఆదానం_సూచీ].reg = op->reg;
            operands[op->ఆదానం_సూచీ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    కొరకు(i=0;i<nb_operands;i++) {
        op = &operands[i];
        ఒకవేళ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL  &&
            !op->is_జ్ఞాపకం) {
            కొరకు(reg = 0; reg < NB_ASM_REGS; reg++) {
                ఒకవేళ (!(regs_allocated[reg] & REG_బహిర్గతం_ముసుగు))
                    వెళ్ళు reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            ఆపు;
        }
    }

    /* print sorted constraints */
#నిర్వచితమైతే ASM_DEBUG
    కొరకు(i=0;i<nb_operands;i++) {
        j = sorted_op[i];
        op = &operands[j];
        రాయి("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ఖాళీ) : "",
               op->constraint,
               op->vt->r,
               op->reg);
    }
    ఒకవేళ (*pout_reg >= 0)
        రాయి("out_reg=%d\n", *pout_reg);
#అయితే_ముగింపు
}

ST_FUNC శూన్య subst_asm_నిర్వాహ్యం(CString *కూడు_str,
                              SValue *sv, పూర్ణాంకం modifier)
{
    పూర్ణాంకం r, reg, కొలత, val;

    r = sv->r;
    ఒకవేళ ((r & VT_VALMASK) == VT_CONST) {
        ఒకవేళ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
	    modifier != 'P')
            cstr_ccat(కూడు_str, '$');
        ఒకవేళ (r & VT_SYM) {
	    స్థిరరాశి అక్షరం *name = get_tok_str(sv->sym->v, ఖాళీ);
	    ఒకవేళ (sv->sym->v >= SYM_మొదటి_ANOM) {
		/* In case of anonymous symbols ("L.42", used
		   for static data labels) we can't find them
		   in the C symbol table when later looking up
		   this name.  So enter them now into the asm label
		   list when we still know the symbol.  */
		get_asm_sym(tok_alloc_const(name), sv->sym);
	    }
            ఒకవేళ (tcc_state->leading_underscore)
              cstr_ccat(కూడు_str, '_');
            cstr_cat(కూడు_str, name, -1);
            ఒకవేళ ((uint32_t)sv->c.i == 0)
                వెళ్ళు no_స్థానభ్రంశం;
	    cstr_ccat(కూడు_str, '+');
        }
        val = sv->c.i;
        ఒకవేళ (modifier == 'n')
            val = -val;
        cstr_printf(కూడు_str, "%d", val);
    no_స్థానభ్రంశం:;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
        ఒకవేళ (r & VT_LVAL)
            cstr_cat(కూడు_str, "(%rip)", -1);
#అయితే_ముగింపు
    } లేకపోతే ఒకవేళ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(కూడు_str, "%d(%%%s)", (పూర్ణాంకం)sv->c.i, get_tok_str(TOK_ASM_xax + 5, ఖాళీ));
    } లేకపోతే ఒకవేళ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ఒకవేళ (reg >= VT_CONST)
            tcc_అంతర్గత_error("");
        cstr_printf(కూడు_str, "(%%%s)", get_tok_str(TOK_ASM_xax + reg, ఖాళీ));
    } లేకపోతే {
        /* register case */
        reg = r & VT_VALMASK;
        ఒకవేళ (reg >= VT_CONST)
            tcc_అంతర్గత_error("");

        /* choose register operand size */
        ఒకవేళ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
	    (sv->type.t & VT_BTYPE) == VT_BOOL)
            కొలత = 1;
        లేకపోతే ఒకవేళ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            కొలత = 2;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
        లేకపోతే ఒకవేళ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
		 (sv->type.t & VT_BTYPE) == VT_PTR)
            కొలత = 8;
#అయితే_ముగింపు
        లేకపోతే
            కొలత = 4;
        ఒకవేళ (కొలత == 1 && reg >= 4)
            కొలత = 4;

        ఒకవేళ (modifier == 'b') {
            ఒకవేళ (reg >= 4)
                tcc_error("cannot use byte register");
            కొలత = 1;
        } లేకపోతే ఒకవేళ (modifier == 'h') {
            ఒకవేళ (reg >= 4)
                tcc_error("cannot use byte register");
            కొలత = -1;
        } లేకపోతే ఒకవేళ (modifier == 'w') {
            కొలత = 2;
        } లేకపోతే ఒకవేళ (modifier == 'k') {
            కొలత = 4;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
        } లేకపోతే ఒకవేళ (modifier == 'q') {
            కొలత = 8;
#అయితే_ముగింపు
        }

        ఒకవేళ (reg >= 8) {
            cstr_printf(కూడు_str, "%%r%d%c", reg, (కొలత == 1) ? 'b' : ((కొలత == 2) ? 'w' : ((కొలత == 4) ? 'd' : ' ')));
            తిరిగి;
        }
        ఎంపిక(కొలత) {
        స్థితి -1:
            reg = TOK_ASM_ah + reg;
            ఆపు;
        స్థితి 1:
            reg = TOK_ASM_al + reg;
            ఆపు;
        స్థితి 2:
            reg = TOK_ASM_ax + reg;
            ఆపు;
        అప్రమేయ:
            reg = TOK_ASM_eax + reg;
            ఆపు;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
        స్థితి 8:
            reg = TOK_ASM_rax + reg;
            ఆపు;
#అయితే_ముగింపు
        }
        cstr_printf(కూడు_str, "%%%s", get_tok_str(reg, ఖాళీ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC శూన్య asm_gen_సంకేతం(ASMOperand *operands, పూర్ణాంకం nb_operands,
                         పూర్ణాంకం nb_outputs, పూర్ణాంకం is_output,
                         uint8_t *clobber_regs,
                         పూర్ణాంకం బహిర్గతం_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    పూర్ణాంకం i, reg;

    /* Strictly speaking %Xbp and %Xsp should be included in the
       call-preserved registers, but currently it doesn't matter.  */
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    స్థిర స్థిరరాశి uint8_t reg_saved[] = { 3, 6, 7, 12, 13, 14, 15 };
#లేకపోతే
    స్థిర స్థిరరాశి uint8_t reg_saved[] = { 3, 12, 13, 14, 15 };
#అయితే_ముగింపు
#లేకపోతే
    స్థిర స్థిరరాశి uint8_t reg_saved[] = { 3, 6, 7 };
#అయితే_ముగింపు

    /* mark all used registers */
    జ్ఞాపకం_నకలు(regs_allocated, clobber_regs, పరిమాణం(regs_allocated));
    కొరకు(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        ఒకవేళ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    ఒకవేళ (!is_output) {
        /* generate reg save code */
        కొరకు(i = 0; i < పరిమాణం(reg_saved)/పరిమాణం(reg_saved[0]); i++) {
            reg = reg_saved[i];
            ఒకవేళ (regs_allocated[reg]) {
		ఒకవేళ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x50 + reg);
            }
        }

        /* generate load code */
        కొరకు(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ఒకవేళ (op->reg >= 0) {
                ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_జ్ఞాపకం) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    ఎక్కించు(op->reg, &sv);
                } లేకపోతే ఒకవేళ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    ఎక్కించు(op->reg, op->vt);
                    ఒకవేళ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        ఎక్కించు(TREG_XDX, &sv);
                    }
                }
            }
        }
    } లేకపోతే {
        /* generate save code */
        కొరకు(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ఒకవేళ (op->reg >= 0) {
                ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ఒకవేళ (!op->is_జ్ఞాపకం) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
			sv.type.t = VT_PTR;
                        ఎక్కించు(బహిర్గతం_reg, &sv);

			sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | బహిర్గతం_reg;
                        store(op->reg, &sv);
                    }
                } లేకపోతే {
                    store(op->reg, op->vt);
                    ఒకవేళ (op->is_llong) {
                        SValue sv;
                        sv = *op->vt;
                        sv.c.i += 4;
                        store(TREG_XDX, &sv);
                    }
                }
            }
        }
        /* generate reg restore code */
        కొరకు(i = పరిమాణం(reg_saved)/పరిమాణం(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            ఒకవేళ (regs_allocated[reg]) {
		ఒకవేళ (reg >= 8)
		  g(0x41), reg-=8;
                g(0x58 + reg);
            }
        }
    }
}

ST_FUNC శూన్య asm_clobber(uint8_t *clobber_regs, స్థిరరాశి అక్షరం *str)
{
    పూర్ణాంకం reg;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    గుర్తులేని పూర్ణాంకం type;
#అయితే_ముగింపు

    ఒకవేళ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
	!strcmp(str, "flags"))
        తిరిగి;
    reg = tok_alloc_const(str);
    ఒకవేళ (reg >= TOK_ASM_eax && reg <= TOK_ASM_edi) {
        reg -= TOK_ASM_eax;
    } లేకపోతే ఒకవేళ (reg >= TOK_ASM_ax && reg <= TOK_ASM_di) {
        reg -= TOK_ASM_ax;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    } లేకపోతే ఒకవేళ (reg >= TOK_ASM_rax && reg <= TOK_ASM_rdi) {
        reg -= TOK_ASM_rax;
    } లేకపోతే ఒకవేళ ((reg = asm_parse_numeric_reg(reg, &type)) >= 0) {
	;
#అయితే_ముగింపు
    } లేకపోతే {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}
