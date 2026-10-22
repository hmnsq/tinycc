/*************************************************************/
/*
 *  ARM64 (AArch64) assembler for TCC
 *
 *  Based on ARM64 Architecture Reference Manual
 *  Supports AArch64 assembler parsing and extended inline asm
 *  with operands, constraints, and clobbers.
 */

#ifdef TARGET_DEFS_ONLY

#define CONFIG_TCC_ASM
/* 32 general purpose + 32 SIMD/FP registers */
#define NB_ASM_REGS 64

ST_FUNC শূন্য g(পূর্ণাঙ্ক c);
ST_FUNC শূন্য gen_le16(পূর্ণাঙ্ক c);
ST_FUNC শূন্য gen_le32(পূর্ণাঙ্ক c);

/*************************************************************/
#অন্যথা
/*************************************************************/

#define USING_GLOBALS
#অন্তর্ভাৱ "tcc.h"

/* Register type flags */
#define REG_X     0x01  /* 64-bit general purpose */
#define REG_W     0x02  /* 32-bit general purpose */
#define REG_V     0x04  /* 128-bit SIMD */
#define REG_D     0x08  /* 64-bit FP */
#define REG_S     0x10  /* 32-bit FP */
#define REG_H     0x20  /* 16-bit FP */
#define REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
গণনা {
    OPT_REG,
    OPT_IM,
    OPT_ADDR,
    OPT_COND,
};

#define OP_REG     (1 << OPT_REG)
#define OP_IM      (1 << OPT_IM)
#define OP_ADDR    (1 << OPT_ADDR)
#define OP_COND    (1 << OPT_COND)

/* Register allocation masks */
#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

/* ARM64 register constants */
#define TREG_X0  0
#define TREG_X1  1
#define TREG_X2  2
#define TREG_X3  3
#define TREG_X4  4
#define TREG_X5  5
#define TREG_X6  6
#define TREG_X7  7
#define TREG_X8  8
#define TREG_X9  9
#define TREG_X10 10
#define TREG_X11 11
#define TREG_X12 12
#define TREG_X13 13
#define TREG_X14 14
#define TREG_X15 15
#define TREG_X16 16
#define TREG_X17 17
#define TREG_X18 18
#define TREG_X19 19
#define TREG_X20 20
#define TREG_X21 21
#define TREG_X22 22
#define TREG_X23 23
#define TREG_X24 24
#define TREG_X25 25
#define TREG_X26 26
#define TREG_X27 27
#define TREG_X28 28
#define TREG_X29 29
#define TREG_X30 30
#define TREG_SP  31

#define ARM64_FREG_BASE 20
#define ARM64_FREG_LAST (ARM64_FREG_BASE + 7)

প্রকারনির্দেশ সংরচনা Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    পূর্ণাঙ্ক reg_tok;
    ৰাশিমালা_মান e;
} Operand;

গণনা {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
স্থির শূন্য parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC শূন্য g(পূর্ণাঙ্ক c)
{
    পূর্ণাঙ্ক ind1;
    যদি (nocode_wanted)
        ঘূৰাই;
    ind1 = ind + 1;
    যদি (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC শূন্য gen_le16(পূর্ণাঙ্ক c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC শূন্য gen_le32(পূর্ণাঙ্ক c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC শূন্য gen_expr32(ৰাশিমালা_মান *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
স্থির শূন্য emit_instr32(uint32_t val)
{
    যদি (nocode_wanted)
        ঘূৰাই;
    যদি (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
স্থির পূর্ণাঙ্ক arm64_parse_asm_reg(পূর্ণাঙ্ক t)
{
    /* X registers (64-bit) */
    যদি (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ঘূৰাই t - TOK_ASM_x0;
    /* W registers (32-bit) */
    যদি (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ঘূৰাই t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    যদি (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ঘূৰাই (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    যদি (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ঘূৰাই (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    যদি (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ঘূৰাই (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    যদি (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ঘূৰাই (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    যদি (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ঘূৰাই (t - TOK_ASM_b0) + 32;
    /* Special registers */
    যদি (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        ঘূৰাই 31;  /* SP/ZR encoded as 31 */
    ঘূৰাই -1;
}

/* Get register type from token */
স্থির uint8_t get_reg_type(পূর্ণাঙ্ক t)
{
    যদি (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ঘূৰাই REG_X;
    যদি (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ঘূৰাই REG_W;
    যদি (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ঘূৰাই REG_V;
    যদি (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ঘূৰাই REG_D;
    যদি (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ঘূৰাই REG_S;
    যদি (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ঘূৰাই REG_H;
    যদি (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ঘূৰাই REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    যদি (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        ঘূৰাই REG_X;
    যদি (t == TOK_ASM_wzr)
        ঘূৰাই REG_W;
    ঘূৰাই REG_X;
}

/* Parse condition code */
স্থির পূর্ণাঙ্ক parse_condition(পূর্ণাঙ্ক t)
{
    ৱিকল্প (t) {
        পক্ষ TOK_ASM_eq: ঘূৰাই 0;
        পক্ষ TOK_ASM_ne: ঘূৰাই 1;
        পক্ষ TOK_ASM_cs:
        পক্ষ TOK_ASM_hs: ঘূৰাই 2;
        পক্ষ TOK_ASM_cc:
        পক্ষ TOK_ASM_lo: ঘূৰাই 3;
        পক্ষ TOK_ASM_mi: ঘূৰাই 4;
        পক্ষ TOK_ASM_pl: ঘূৰাই 5;
        পক্ষ TOK_ASM_vs: ঘূৰাই 6;
        পক্ষ TOK_ASM_vc: ঘূৰাই 7;
        পক্ষ TOK_ASM_hi: ঘূৰাই 8;
        পক্ষ TOK_ASM_ls: ঘূৰাই 9;
        পক্ষ TOK_ASM_ge: ঘূৰাই 10;
        পক্ষ TOK_ASM_lt: ঘূৰাই 11;
        পক্ষ TOK_ASM_gt: ঘূৰাই 12;
        পক্ষ TOK_ASM_le: ঘূৰাই 13;
        পক্ষ TOK_ASM_al: ঘূৰাই 14;
        স্ৱভাৱ: ঘূৰাই -1;
    }
}

স্থির পূর্ণাঙ্ক parse_barrier_option_name(পূর্ণাঙ্ক t)
{
    ধ্রুৱ ৱর্ণ *name;

    যদি (t < TOK_IDENT)
        ঘূৰাই -1;
    name = get_tok_str(t, রিক্ত);
    যদি (!strcmp(name, "oshld")) ঘূৰাই 0x1;
    যদি (!strcmp(name, "oshst")) ঘূৰাই 0x2;
    যদি (!strcmp(name, "osh"))   ঘূৰাই 0x3;
    যদি (!strcmp(name, "nshld")) ঘূৰাই 0x5;
    যদি (!strcmp(name, "nshst")) ঘূৰাই 0x6;
    যদি (!strcmp(name, "nsh"))   ঘূৰাই 0x7;
    যদি (!strcmp(name, "ishld")) ঘূৰাই 0x9;
    যদি (!strcmp(name, "ishst")) ঘূৰাই 0xA;
    যদি (!strcmp(name, "ish"))   ঘূৰাই 0xB;
    যদি (!strcmp(name, "ld"))    ঘূৰাই 0xD;
    যদি (!strcmp(name, "st"))    ঘূৰাই 0xE;
    যদি (!strcmp(name, "sy"))    ঘূৰাই 0xF;
    ঘূৰাই -1;
}

স্থির পূর্ণাঙ্ক arm64_parse_regvar(পূর্ণাঙ্ক t)
{
    যদি (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ঘূৰাই t - TOK_ASM_x0;
    যদি (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        ঘূৰাই ARM64_FREG_BASE + (t - TOK_ASM_v0);
    যদি (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        ঘূৰাই ARM64_FREG_BASE + (t - TOK_ASM_d0);
    যদি (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        ঘূৰাই ARM64_FREG_BASE + (t - TOK_ASM_s0);
    যদি (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        ঘূৰাই ARM64_FREG_BASE + (t - TOK_ASM_h0);
    যদি (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        ঘূৰাই ARM64_FREG_BASE + (t - TOK_ASM_b0);
    ঘূৰাই -1;
}

/* Parse a single operand */
স্থির শূন্য parse_operand(TCCState *s1, Operand *op)
{
    পূর্ণাঙ্ক reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    যদি (tok == '[') {
        parse_addr_operand(s1, op);
        ঘূৰাই;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    যদি (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        ঘূৰাই;
    }

    /* Condition code */
    reg = parse_condition(tok);
    যদি (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        ঘূৰাই;
    }

    /* Immediate or address expression */
    যদি (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_ৰাশিমালা(s1, &op->e);
        op->type = OP_IM;
    } অন্যথা যদি (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } অন্যথা {
        asm_ৰাশিমালা(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
স্থির শূন্য parse_ৰাশিমালা_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    যদি (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_ৰাশিমালা(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
স্থির শূন্য parse_addr_operand(TCCState *s1, Operand *op)
{
    পূর্ণাঙ্ক reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = রিক্ত;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    যদি (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        ঘূৰাই;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    যদি (tok == ',') {
        next();
        যদি (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_ৰাশিমালা(s1, &op->e);
    }
    skip(']');
    যদি (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } অন্যথা যদি (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        যদি (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_ৰাশিমালা(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
স্থির শূন্য gen_mov_with_base(পূর্ণাঙ্ক rd, uint16_t imm, পূর্ণাঙ্ক shift,
                              পূর্ণাঙ্ক is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    যদি (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

স্থির শূন্য gen_movz(পূর্ণাঙ্ক rd, uint16_t imm, পূর্ণাঙ্ক shift, পূর্ণাঙ্ক is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
স্থির শূন্য gen_movn(পূর্ণাঙ্ক rd, uint16_t imm, পূর্ণাঙ্ক shift, পূর্ণাঙ্ক is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
স্থির শূন্য gen_movk(পূর্ণাঙ্ক rd, uint16_t imm, পূর্ণাঙ্ক shift, পূর্ণাঙ্ক is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
স্থির শূন্য gen_add_imm(পূর্ণাঙ্ক rd, পূর্ণাঙ্ক rn, uint32_t imm, পূর্ণাঙ্ক is_64bit, পূর্ণাঙ্ক setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    যদি (is_64bit) instr |= ARM64_SF(1);
    যদি (setflags) instr |= ARM64_S(1);

    যদি (imm <= 0xFFF) {
        imm12 = imm;
    } অন্যথা যদি (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } অন্যথা {
        tcc_error("add immediate out of range");
        ঘূৰাই;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
স্থির শূন্য gen_sub_imm(পূর্ণাঙ্ক rd, পূর্ণাঙ্ক rn, uint32_t imm, পূর্ণাঙ্ক is_64bit, পূর্ণাঙ্ক setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    যদি (is_64bit) instr |= ARM64_SF(1);
    যদি (setflags) instr |= ARM64_S(1);

    যদি (imm <= 0xFFF) {
        imm12 = imm;
    } অন্যথা যদি (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } অন্যথা {
        tcc_error("sub immediate out of range");
        ঘূৰাই;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
স্থির শূন্য gen_dp_reg(uint32_t opcode, পূর্ণাঙ্ক rd, পূর্ণাঙ্ক rn, পূর্ণাঙ্ক rm, পূর্ণাঙ্ক is_64bit)
{
    uint32_t instr = opcode;
    যদি (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
স্থির শূন্য gen_ldst_imm(uint32_t base_opcode, পূর্ণাঙ্ক rt, পূর্ণাঙ্ক rn,
                         int32_t offset, পূর্ণাঙ্ক size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    যদি (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        যদি (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            ঘূৰাই;
        }
    }

    ৱিকল্প (base_opcode) {
    পক্ষ ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; ভঙ্গ;
    পক্ষ ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; ভঙ্গ;
    পক্ষ ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; ভঙ্গ;
    পক্ষ ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; ভঙ্গ;
    পক্ষ ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; ভঙ্গ;
    পক্ষ ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; ভঙ্গ;
    পক্ষ ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; ভঙ্গ;
    পক্ষ ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; ভঙ্গ;
    পক্ষ ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; ভঙ্গ;
    পক্ষ ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; ভঙ্গ;
    }

    যদি (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        ঘূৰাই;
    }

    যদি (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
স্থির শূন্য gen_ldst_pair(uint32_t base_opcode, পূর্ণাঙ্ক rt, পূর্ণাঙ্ক rt2, পূর্ণাঙ্ক rn,
                          int32_t offset, পূর্ণাঙ্ক size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    যদি (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    যদি (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
স্থির শূন্য gen_b_or_bl(int32_t offset, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    instr |= ARM64_OFFSET26(offset);
    emit_instr32(instr);
}

স্থির শূন্য gen_b(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_B);
}

/* Generate BL (branch with link) */
স্থির শূন্য gen_bl(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_BL);
}

/* Generate BR (branch to register) */
স্থির শূন্য gen_br(পূর্ণাঙ্ক rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
স্থির শূন্য gen_blr(পূর্ণাঙ্ক rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
স্থির শূন্য gen_ret(পূর্ণাঙ্ক rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
স্থির শূন্য gen_b_cond(পূর্ণাঙ্ক cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
স্থির শূন্য gen_cbz_or_cbnz(পূর্ণাঙ্ক rt, int32_t offset, পূর্ণাঙ্ক is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    যদি (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

স্থির শূন্য gen_cbz(পূর্ণাঙ্ক rt, int32_t offset, পূর্ণাঙ্ক is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
স্থির শূন্য gen_cbnz(পূর্ণাঙ্ক rt, int32_t offset, পূর্ণাঙ্ক is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
স্থির শূন্য gen_mov_reg(পূর্ণাঙ্ক rd, পূর্ণাঙ্ক rm, পূর্ণাঙ্ক is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    যদি (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

স্থির পূর্ণাঙ্ক arm64_asm_encode_bimm64(uint64_t x)
{
    পূর্ণাঙ্ক neg, rep, pos, len;

    neg = x & 1;
    যদি (neg)
        x = ~x;
    যদি (!x)
        ঘূৰাই -1;

    যদি (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    অন্যথা যদি (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    অন্যথা যদি (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    অন্যথা যদি (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    অন্যথা যদি (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    অন্যথা
        rep = 64;

    pos = 0;
    যদি (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    যদি (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    যদি (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    যদি (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    যদি (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    যদি (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    যদি (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    যদি (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    যদি (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    যদি (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    যদি (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    যদি (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    যদি (x)
        ঘূৰাই -1;
    যদি (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    ঘূৰাই ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

স্থির শূন্য gen_logical_imm(uint32_t opcode, পূর্ণাঙ্ক rd, পূর্ণাঙ্ক rn,
                            uint64_t imm, পূর্ণাঙ্ক is_64bit)
{
    uint32_t instr;
    uint64_t val;
    পূর্ণাঙ্ক enc;

    যদি (is_64bit)
        val = imm;
    অন্যথা {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    যদি (enc < 0) {
        tcc_error("logical immediate out of range");
        ঘূৰাই;
    }

    instr = opcode;
    যদি (is_64bit)
        instr |= ARM64_SF(1);
    instr |= ARM64_N(enc >> 12);
    instr |= ARM64_IMM_R(enc >> 6);
    instr |= ARM64_IMM_S(enc);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
স্থির অন্তঃস্থ পূর্ণাঙ্ক constraint_priority(ধ্রুৱ ৱর্ণ *str)
{
    পূর্ণাঙ্ক priority, c, pr;

    priority = 0;
    বাবে (;;) {
        c = *str++;
        যদি (c == '\0')
            ভঙ্গ;
        ৱিকল্প (c) {
        পক্ষ '=':
        পক্ষ '+':
        পক্ষ '&':
            অনুৱর্ত;
        পক্ষ 'r':
            pr = 1;
            ভঙ্গ;
        পক্ষ 'w':
        পক্ষ 'f':
        পক্ষ 'x':
        পক্ষ 'y':
            pr = 3;
            ভঙ্গ;
        পক্ষ 'm':
        পক্ষ 'Q':
            pr = 4;
            ভঙ্গ;
        পক্ষ 'i':
        পক্ষ 'S':
            pr = 5;
            ভঙ্গ;
        পক্ষ 'U':
            যদি (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                ভঙ্গ;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            ভঙ্গ;
        পক্ষ 'I':
        পক্ষ 'J':
        পক্ষ 'K':
        পক্ষ 'L':
        পক্ষ 'M':
        পক্ষ 'N':
        পক্ষ 'Z':
            pr = 6;
            ভঙ্গ;
        পক্ষ 'n':
            pr = 7;
            ভঙ্গ;
        পক্ষ 'g':
            pr = 8;
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            ভঙ্গ;
        }
        যদি (pr > priority)
            priority = pr;
    }
    ঘূৰাই priority;
}

স্থির ধ্রুৱ ৱর্ণ *skip_constraint_modifiers(ধ্রুৱ ৱর্ণ *p)
{
    যেতিয়ালৈ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ঘূৰাই p;
}

স্থির পূর্ণাঙ্ক is_valid_add_imm(int64_t val)
{
    ঘূৰাই val >= 0 && val <= 4095;
}

স্থির পূর্ণাঙ্ক is_valid_logical_imm(int64_t val, পূর্ণাঙ্ক bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    যদি (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    ঘূৰাই arm64_asm_encode_bimm64(uval) >= 0;
}

স্থির পূর্ণাঙ্ক is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    যদি (uval <= 0xFFFF)
        ঘূৰাই 1;
    যদি (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        ঘূৰাই 1;
    যদি (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        ঘূৰাই 1;
    যদি ((uval & 0xFFFFFFFF00000000ULL) == 0)
        ঘূৰাই 1;

    ঘূৰাই 0;
}

স্থির পূর্ণাঙ্ক is_valid_movw_shift(পূর্ণাঙ্ক shift, পূর্ণাঙ্ক is_64bit)
{
    যদি (shift < 0 || (shift & 15))
        ঘূৰাই 0;
    যদি (shift > (is_64bit ? 48 : 16))
        ঘূৰাই 0;
    ঘূৰাই 1;
}

স্থির পূর্ণাঙ্ক arm64_memory_is_base_only(ধ্রুৱ SValue *sv)
{
    পূর্ণাঙ্ক r;

    r = sv->r;
    যদি ((r & VT_VALMASK) == VT_CONST)
        ঘূৰাই 0;
    যদি ((r & VT_VALMASK) == VT_LOCAL)
        ঘূৰাই 0;
    যদি ((r & VT_VALMASK) == VT_LLOCAL)
        ঘূৰাই 1;
    যদি (r & VT_LVAL)
        ঘূৰাই (r & VT_VALMASK) < VT_CONST;
    ঘূৰাই 0;
}

স্থির পূর্ণাঙ্ক arm64_memory_is_pair_suitable(ধ্রুৱ SValue *sv)
{
    int64_t offset;

    যদি (arm64_memory_is_base_only(sv))
        ঘূৰাই 1;
    যদি ((sv->r & VT_VALMASK) != VT_LOCAL)
        ঘূৰাই 0;

    offset = (int64_t)sv->c.i;
    ঘূৰাই (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

স্থির পূর্ণাঙ্ক arm64_int_reg_is_allocatable(পূর্ণাঙ্ক reg)
{
#ifdef TCC_TARGET_PE
    ঘূৰাই reg >= TREG_X0 && reg <= TREG_X17;
#অন্যথা
    ঘূৰাই reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

স্থির পূর্ণাঙ্ক arm64_memory_needs_address_reg(ধ্রুৱ SValue *sv)
{
    পূর্ণাঙ্ক r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    যদি (!(r & VT_LVAL))
        ঘূৰাই 0;
    ৱিকল্প (r & VT_VALMASK) {
    পক্ষ VT_LOCAL:
    পক্ষ VT_LLOCAL:
    পক্ষ VT_CONST:
        ঘূৰাই 1;
    }
    ঘূৰাই 0;
}

স্থির পূর্ণাঙ্ক arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    পূর্ণাঙ্ক reg;

    যদি (!arm64_memory_needs_address_reg(op->vt))
        ঘূৰাই 1;

    বাবে (reg = 0; reg < 31; reg++) {
        যদি (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            ঘূৰাই 1;
        }
    }
    ঘূৰাই 0;
}

স্থির শূন্য arm64_load_memory_operand_base(পূর্ণাঙ্ক reg, SValue *sv)
{
    SValue base;
    পূর্ণাঙ্ক rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    যদি (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } অন্যথা যদি (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } অন্যথা {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

স্থির পূর্ণাঙ্ক operand_is_sp(ধ্রুৱ Operand *op)
{
    ঘূৰাই op->reg_tok == TOK_ASM_sp;
}

স্থির পূর্ণাঙ্ক parse_sysreg_name(পূর্ণাঙ্ক t)
{
    ধ্রুৱ ৱর্ণ *name;

    যদি (t < TOK_IDENT)
        ঘূৰাই -1;
    name = get_tok_str(t, রিক্ত);
    যদি (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        ঘূৰাই 0;
    যদি (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        ঘূৰাই 1;
    ঘূৰাই -1;
}

স্থির শূন্য gen_mrs(পূর্ণাঙ্ক rt, পূর্ণাঙ্ক sysreg)
{
    uint32_t instr;

    ৱিকল্প (sysreg) {
        পক্ষ 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            ভঙ্গ;
        পক্ষ 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("unsupported system register");
            ঘূৰাই;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

স্থির শূন্য gen_msr(পূর্ণাঙ্ক rt, পূর্ণাঙ্ক sysreg)
{
    uint32_t instr;

    ৱিকল্প (sysreg) {
        পক্ষ 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            ভঙ্গ;
        পক্ষ 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("unsupported system register");
            ঘূৰাই;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
স্থির শূন্য gen_nop(শূন্য)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
স্থির শূন্য gen_shift(পূর্ণাঙ্ক rd, পূর্ণাঙ্ক rn, পূর্ণাঙ্ক rm_or_imm, পূর্ণাঙ্ক shift_type, পূর্ণাঙ্ক is_imm, পূর্ণাঙ্ক is_64bit)
{
    uint32_t instr;
    পূর্ণাঙ্ক width = is_64bit ? 64 : 32;

    যদি (is_imm) {
        /* Shift by immediate */
        ৱিকল্প (shift_type) {
            পক্ষ 0: /* LSL - UBFM alias */
                যদি (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ঘূৰাই;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                ভঙ্গ;
            পক্ষ 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                যদি (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ঘূৰাই;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                ভঙ্গ;
            পক্ষ 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                যদি (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ঘূৰাই;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                ভঙ্গ;
            পক্ষ 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                যদি (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ঘূৰাই;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                ঘূৰাই;
            স্ৱভাৱ:
                tcc_error("unknown shift type");
                ঘূৰাই;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } অন্যথা {
        /* Shift by register */
        ৱিকল্প (shift_type) {
            পক্ষ 0: /* LSL */
                instr = ARM64_LSL_REG;
                ভঙ্গ;
            পক্ষ 1: /* LSR */
                instr = ARM64_LSR_REG;
                ভঙ্গ;
            পক্ষ 2: /* ASR */
                instr = ARM64_ASR_REG;
                ভঙ্গ;
            পক্ষ 3: /* ROR */
                instr = ARM64_ROR_REG;
                ভঙ্গ;
            স্ৱভাৱ:
                tcc_error("unknown shift type");
                ঘূৰাই;
        }
        যদি (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
স্থির শূন্য asm_shift(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand op1, op2, op3;
    পূর্ণাঙ্ক rd, rn, shift_amount;
    পূর্ণাঙ্ক shift_type;
    পূর্ণাঙ্ক is_64bit = 1;

    ৱিকল্প (token) {
        পক্ষ TOK_ASM_lsl:
            shift_type = 0;
            ভঙ্গ;
        পক্ষ TOK_ASM_lsr:
            shift_type = 1;
            ভঙ্গ;
        পক্ষ TOK_ASM_asr:
            shift_type = 2;
            ভঙ্গ;
        পক্ষ TOK_ASM_ror:
            shift_type = 3;
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("unknown shift instruction");
            ঘূৰাই;
    }

    parse_operand(s1, &op1);
    যদি (tok == ',') next();
    parse_operand(s1, &op2);

    যদি (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ঘূৰাই;
    }
    যদি (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ঘূৰাই;
    }

    rd = op1.reg;
    rn = op2.reg;

    যদি (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        যদি (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ঘূৰাই;
        }
        যদি (op3.type & OP_REG) {
            যদি (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ঘূৰাই;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } অন্যথা যদি (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } অন্যথা {
            tcc_error("shift requires immediate or register operand");
        }
    } অন্যথা {
        tcc_error("shift requires immediate or register operand");
        ঘূৰাই;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
স্থির শূন্য gen_barrier(পূর্ণাঙ্ক barrier_type, পূর্ণাঙ্ক option)
{
    uint32_t instr;

    ৱিকল্প (barrier_type) {
        পক্ষ 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            ভঙ্গ;
        পক্ষ 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            ভঙ্গ;
        পক্ষ 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("unknown barrier type");
            ঘূৰাই;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
স্থির শূন্য asm_barrier(TCCState *s1, পূর্ণাঙ্ক token)
{
    পূর্ণাঙ্ক barrier_type, option;
    Operand op;

    ৱিকল্প (token) {
        পক্ষ TOK_ASM_isb:
            barrier_type = 0;
            ভঙ্গ;
        পক্ষ TOK_ASM_dsb:
            barrier_type = 1;
            ভঙ্গ;
        পক্ষ TOK_ASM_dmb:
            barrier_type = 2;
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("unknown barrier instruction");
            ঘূৰাই;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    যদি (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        যদি (option >= 0) {
            next();
        } অন্যথা {
            parse_operand(s1, &op);
            যদি (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                ঘূৰাই;
            }
            যদি (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                ঘূৰাই;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
স্থির শূন্য gen_mov_imm(পূর্ণাঙ্ক rd, uint64_t imm, পূর্ণাঙ্ক is_64bit)
{
    uint16_t hw;
    পূর্ণাঙ্ক i, first = 1;

    বাবে (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        যদি (hw != 0 || i == 0) {
            যদি (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } অন্যথা {
                gen_movk(rd, hw, i, is_64bit);
            }
        } অন্যথা যদি (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
স্থির শূন্য asm_mov(TCCState *s1)
{
    Operand op1, op2;
    পূর্ণাঙ্ক rd, rn;
    পূর্ণাঙ্ক is_64bit;

    parse_operand(s1, &op1);
    যদি (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    যদি (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        যদি (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            ঘূৰাই;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } অন্যথা যদি (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        যদি (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        অন্যথা
            gen_mov_reg(rd, rn, is_64bit);
    } অন্যথা {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
স্থির শূন্য asm_data_proc(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand op1, op2, op3;
    পূর্ণাঙ্ক rd, rn, rm;
    পূর্ণাঙ্ক is_64bit = 1;
    uint32_t opcode;

    ৱিকল্প (token) {
        পক্ষ TOK_ASM_add:
        পক্ষ TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            ভঙ্গ;
        পক্ষ TOK_ASM_sub:
        পক্ষ TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            ভঙ্গ;
        পক্ষ TOK_ASM_and:
        পক্ষ TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            ভঙ্গ;
        পক্ষ TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            ভঙ্গ;
        পক্ষ TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            ভঙ্গ;
        পক্ষ TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("unsupported data processing instruction");
            ঘূৰাই;
    }

    parse_operand(s1, &op1);
    যদি (tok == ',') next();
    parse_operand(s1, &op2);

    যদি (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ঘূৰাই;
    }
    যদি (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ঘূৰাই;
    }

    rd = op1.reg;
    rn = op2.reg;

    যদি (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        যদি (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ঘূৰাই;
        }
        যদি (op3.type & OP_IM) {
            যদি (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            অন্যথা যদি (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            অন্যথা যদি (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            অন্যথা যদি (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            অন্যথা যদি (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            অন্যথা যদি (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            অন্যথা
                tcc_error("immediate operand not valid for this instruction");
        } অন্যথা {
            যদি (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                ঘূৰাই;
            }
            rm = op3.reg;
            যদি (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ঘূৰাই;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } অন্যথা যদি (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } অন্যথা {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
স্থির শূন্য asm_ldst(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand op1, op2;
    পূর্ণাঙ্ক rt, rn;
    int32_t offset = 0;
    পূর্ণাঙ্ক size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    যদি (tok == ',') next();
    parse_operand(s1, &op2);

    যদি (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ঘূৰাই;
    }
    যদি (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        ঘূৰাই;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    ৱিকল্প (token) {
        পক্ষ TOK_ASM_ldr:
            যদি (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } অন্যথা যদি (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } অন্যথা যদি (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } অন্যথা {
                tcc_error("ldr requires a w, x, or d register");
                ঘূৰাই;
            }
            ভঙ্গ;
        পক্ষ TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            ভঙ্গ;
        পক্ষ TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            ভঙ্গ;
        পক্ষ TOK_ASM_str:
            যদি (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } অন্যথা যদি (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } অন্যথা যদি (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } অন্যথা {
                tcc_error("str requires a w, x, or d register");
                ঘূৰাই;
            }
            ভঙ্গ;
        পক্ষ TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            ভঙ্গ;
        পক্ষ TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("unsupported load/store instruction");
            ঘূৰাই;
    }

    যদি (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

স্থির শূন্য asm_ldst_pair(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    পূর্ণাঙ্ক size_log2 = 3;

    parse_operand(s1, &op1);
    যদি (tok == ',')
        next();
    parse_operand(s1, &op2);
    যদি (tok == ',')
        next();
    parse_operand(s1, &op3);

    যদি (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ঘূৰাই;
    }
    যদি (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ঘূৰাই;
    }
    যদি (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    যদি ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        যদি (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } অন্যথা {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } অন্যথা যদি ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        যদি (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } অন্যথা {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } অন্যথা {
        tcc_error("stp/ldp requires matching x or d registers");
        ঘূৰাই;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

স্থির শূন্য asm_sysreg(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand op;
    পূর্ণাঙ্ক sysreg;

    যদি (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        যদি (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        যদি (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        ঘূৰাই;
    }

    sysreg = parse_sysreg_name(tok);
    যদি (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    যদি (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
স্থির পূর্ণাঙ্ক get_branch_condition(পূর্ণাঙ্ক branch_token)
{
    পূর্ণাঙ্ক cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    ৱিকল্প (branch_token) {
        পক্ষ TOK_ASM_beq: cond_token = TOK_ASM_eq; ভঙ্গ;
        পক্ষ TOK_ASM_bne: cond_token = TOK_ASM_ne; ভঙ্গ;
        পক্ষ TOK_ASM_bcs:
        পক্ষ TOK_ASM_bhs: cond_token = TOK_ASM_cs; ভঙ্গ;
        পক্ষ TOK_ASM_bcc:
        পক্ষ TOK_ASM_blo: cond_token = TOK_ASM_cc; ভঙ্গ;
        পক্ষ TOK_ASM_bmi: cond_token = TOK_ASM_mi; ভঙ্গ;
        পক্ষ TOK_ASM_bpl: cond_token = TOK_ASM_pl; ভঙ্গ;
        পক্ষ TOK_ASM_bvs: cond_token = TOK_ASM_vs; ভঙ্গ;
        পক্ষ TOK_ASM_bvc: cond_token = TOK_ASM_vc; ভঙ্গ;
        পক্ষ TOK_ASM_bhi: cond_token = TOK_ASM_hi; ভঙ্গ;
        পক্ষ TOK_ASM_bls: cond_token = TOK_ASM_ls; ভঙ্গ;
        পক্ষ TOK_ASM_bge: cond_token = TOK_ASM_ge; ভঙ্গ;
        পক্ষ TOK_ASM_blt: cond_token = TOK_ASM_lt; ভঙ্গ;
        পক্ষ TOK_ASM_bgt: cond_token = TOK_ASM_gt; ভঙ্গ;
        পক্ষ TOK_ASM_ble: cond_token = TOK_ASM_le; ভঙ্গ;
        স্ৱভাৱ: ঘূৰাই -1;
    }

    ঘূৰাই parse_condition(cond_token);
}

/* Handle branch instructions */
স্থির শূন্য asm_branch(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand op;
    পূর্ণাঙ্ক cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    যদি (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        ঘূৰাই;
    }

    যদি (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    অন্যথা
        parse_ৰাশিমালা_operand(s1, &op);

    যদি (op.type & OP_IM) {
        sym = op.e.sym;
        যদি (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            যদি (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } অন্যথা {
                ৱিকল্প (token) {
                    পক্ষ TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        ভঙ্গ;
                    পক্ষ TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        ভঙ্গ;
                    স্ৱভাৱ:
                        tcc_error("unsupported branch");
                }
            }
        } অন্যথা {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            যদি (cond >= 0) {
                gen_b_cond(cond, offset);
            } অন্যথা {
                ৱিকল্প (token) {
                    পক্ষ TOK_ASM_b:
                        gen_b(offset);
                        ভঙ্গ;
                    পক্ষ TOK_ASM_bl:
                        gen_bl(offset);
                        ভঙ্গ;
                    স্ৱভাৱ:
                        tcc_error("unsupported branch");
                }
            }
        }
    } অন্যথা যদি (op.type & OP_REG) {
        ৱিকল্প (token) {
            পক্ষ TOK_ASM_br:
                gen_br(op.reg);
                ভঙ্গ;
            পক্ষ TOK_ASM_blr:
                gen_blr(op.reg);
                ভঙ্গ;
            পক্ষ TOK_ASM_ret:
                gen_ret(op.reg);
                ভঙ্গ;
            স্ৱভাৱ:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
স্থির শূন্য asm_cb(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand op1, op2;
    পূর্ণাঙ্ক rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    যদি (tok == ',') next();
    parse_ৰাশিমালা_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    যদি (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        যদি (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } অন্যথা {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } অন্যথা {
        offset = (int32_t)op2.e.v - ind;
        যদি (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        অন্যথা
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
স্থির শূন্য asm_move_wide(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand op1, op2;
    পূর্ণাঙ্ক rd, is_64bit = 1;
    uint16_t imm;
    পূর্ণাঙ্ক shift = 0;

    parse_operand(s1, &op1);
    যদি (tok == ',') next();
    parse_operand(s1, &op2);

    যদি (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ঘূৰাই;
    }
    যদি (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        ঘূৰাই;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    যদি ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        ঘূৰাই;
    }
    imm = op2.e.v;

    যদি (tok == ',') {
        next();
        যদি (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            ঘূৰাই;
        }
            next();
            যদি (tok == '#') next();
            asm_ৰাশিমালা(s1, &op2.e);
        যদি (op2.e.sym || !is_valid_movw_shift((পূর্ণাঙ্ক)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            ঘূৰাই;
        }
            shift = (পূর্ণাঙ্ক)op2.e.v / 16;
        }

    ৱিকল্প (token) {
        পক্ষ TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            ভঙ্গ;
        পক্ষ TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            ভঙ্গ;
        পক্ষ TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC শূন্য asm_opcode(TCCState *s1, পূর্ণাঙ্ক opcode)
{
    ৱিকল্প (opcode) {
        পক্ষ TOK_ASM_add:
        পক্ষ TOK_ASM_adds:
        পক্ষ TOK_ASM_sub:
        পক্ষ TOK_ASM_subs:
        পক্ষ TOK_ASM_and:
        পক্ষ TOK_ASM_ands:
        পক্ষ TOK_ASM_orr:
        পক্ষ TOK_ASM_eor:
        পক্ষ TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            ভঙ্গ;

        পক্ষ TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            ভঙ্গ;

        পক্ষ TOK_ASM_lsl:
        পক্ষ TOK_ASM_lsr:
        পক্ষ TOK_ASM_asr:
        পক্ষ TOK_ASM_ror:
            asm_shift(s1, opcode);
            ভঙ্গ;

        পক্ষ TOK_ASM_ldr:
        পক্ষ TOK_ASM_ldrb:
        পক্ষ TOK_ASM_ldrh:
        পক্ষ TOK_ASM_str:
        পক্ষ TOK_ASM_strb:
        পক্ষ TOK_ASM_strh:
            asm_ldst(s1, opcode);
            ভঙ্গ;

        পক্ষ TOK_ASM_ldp:
        পক্ষ TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            ভঙ্গ;

        পক্ষ TOK_ASM_b:
        পক্ষ TOK_ASM_bl:
        পক্ষ TOK_ASM_br:
        পক্ষ TOK_ASM_blr:
        পক্ষ TOK_ASM_ret:
        পক্ষ TOK_ASM_beq:
        পক্ষ TOK_ASM_bne:
        পক্ষ TOK_ASM_bcs:
        পক্ষ TOK_ASM_bhs:
        পক্ষ TOK_ASM_bcc:
        পক্ষ TOK_ASM_blo:
        পক্ষ TOK_ASM_bmi:
        পক্ষ TOK_ASM_bpl:
        পক্ষ TOK_ASM_bvs:
        পক্ষ TOK_ASM_bvc:
        পক্ষ TOK_ASM_bhi:
        পক্ষ TOK_ASM_bls:
        পক্ষ TOK_ASM_bge:
        পক্ষ TOK_ASM_blt:
        পক্ষ TOK_ASM_bgt:
        পক্ষ TOK_ASM_ble:
            asm_branch(s1, opcode);
            ভঙ্গ;

        পক্ষ TOK_ASM_cbz:
        পক্ষ TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            ভঙ্গ;

        পক্ষ TOK_ASM_movz:
        পক্ষ TOK_ASM_movn:
        পক্ষ TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            ভঙ্গ;

        পক্ষ TOK_ASM_mrs:
        পক্ষ TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            ভঙ্গ;

        পক্ষ TOK_ASM_isb:
        পক্ষ TOK_ASM_dsb:
        পক্ষ TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            ভঙ্গ;

        পক্ষ TOK_ASM_nop:
            gen_nop();
            ভঙ্গ;

        স্ৱভাৱ:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, রিক্ত));
            ভঙ্গ;
    }
}

/* Substitute assembler operand */
ST_FUNC শূন্য subst_asm_operand(CString *add_str, SValue *sv, পূর্ণাঙ্ক modifier)
{
    পূর্ণাঙ্ক r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    যদি ((r & VT_VALMASK) == VT_CONST) {
        যদি ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            ঘূৰাই;
        }
        যদি (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        যদি (r & VT_SYM) {
            ধ্রুৱ ৱর্ণ *name = get_tok_str(sv->sym->v, রিক্ত);
            যদি (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            যদি (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            যদি ((uint32_t) sv->c.i == 0)
                গচ্ছ no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        যদি (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } অন্যথা যদি (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } অন্যথা {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } অন্যথা যদি ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (পূর্ণাঙ্ক) sv->c.i);
    } অন্যথা যদি (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        যদি (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } অন্যথা {
        /* register case */
        reg = r & VT_VALMASK;
        যদি (reg >= VT_CONST)
            tcc_internal_error("");

        যদি (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            যদি (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            ৱিকল্প (modifier) {
            পক্ষ 'b':
            পক্ষ 'h':
            পক্ষ 's':
            পক্ষ 'd':
            পক্ষ 'q':
            পক্ষ 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                ঘূৰাই;
            স্ৱভাৱ:
                tcc_error("invalid operand modifier for SIMD/FP register");
                ঘূৰাই;
            }
        }

        /* choose register operand size */
        যদি ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        অন্যথা যদি ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        অন্যথা যদি ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        অন্যথা
            size = 4;

        যদি (modifier == 'x') {
            size = 8;
        } অন্যথা যদি (modifier == 'w' || modifier == 'k') {
            size = 4;
        } অন্যথা যদি (modifier == 'b') {
            size = 1;
        } অন্যথা যদি (modifier == 'h') {
            size = 2;
        } অন্যথা যদি (modifier == 'q') {
            size = 8;
        }

        যদি (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } অন্যথা {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC শূন্য asm_gen_code(ASMOperand *operands, পূর্ণাঙ্ক nb_operands,
                          পূর্ণাঙ্ক nb_outputs, পূর্ণাঙ্ক is_output,
                          uint8_t *clobber_regs,
                          পূর্ণাঙ্ক out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    পূর্ণাঙ্ক i, reg, saved_গুনতি, স্তূপ_size, স্তূপ_off;
    পূর্ণাঙ্ক saved_regs[12];
    স্থির ধ্রুৱ uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, পরিমাণ(regs_allocated));
    বাবে (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        যদি (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_গুনতি = 0;
    বাবে (i = 0; i < পরিমাণ(reg_saved) / পরিমাণ(reg_saved[0]); i++) {
        reg = reg_saved[i];
        যদি (regs_allocated[reg])
            saved_regs[saved_গুনতি++] = reg;
    }
    স্তূপ_size = ((saved_গুনতি + 1) / 2) * 16;

    যদি (!is_output) {
        যদি (saved_গুনতি > 0) {
            gen_sub_imm(31, 31, স্তূপ_size, 1, 0);

            বাবে (i = স্তূপ_off = 0; i < saved_গুনতি; ) {
                যদি (i + 1 < saved_গুনতি) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, স্তূপ_off, 3);
                    স্তূপ_off += 16;
                    i += 2;
                } অন্যথা {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 স্তূপ_off, 3);
                    i++;
                }
            }
        }

        বাবে (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            যদি (op->reg >= 0) {
                যদি (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } অন্যথা যদি (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } অন্যথা {
        বাবে (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            যদি (op->reg >= 0) {
                যদি (op->is_memory)
                    অনুৱর্ত;
                যদি ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    যদি (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } অন্যথা {
                    store(op->reg, op->vt);
                }
            }
        }

        যদি (saved_গুনতি > 0) {
            বাবে (i = স্তূপ_off = 0; i < saved_গুনতি; ) {
                যদি (i + 1 < saved_গুনতি) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, স্তূপ_off, 3);
                    স্তূপ_off += 16;
                    i += 2;
                } অন্যথা {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 স্তূপ_off, 3);
                    i++;
                }
            }
            gen_add_imm(31, 31, স্তূপ_size, 1, 0);
        }
    }
}

ST_FUNC শূন্য asm_compute_constraints(ASMOperand *operands,
                                    পূর্ণাঙ্ক nb_operands, পূর্ণাঙ্ক nb_outputs,
                                    ধ্রুৱ uint8_t *clobber_regs,
                                    পূর্ণাঙ্ক *pout_reg)
{
    ASMOperand *op;
    পূর্ণাঙ্ক sorted_op[MAX_ASM_OPERANDS];
    পূর্ণাঙ্ক i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ধ্রুৱ ৱর্ণ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    বাবে (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->প্ৰবেশ_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    বাবে (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        যদি (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, রিক্ত);
            যদি ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            যদি (operands[k].প্ৰবেশ_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].প্ৰবেশ_index = i;
            op->priority = 5;
        } অন্যথা যদি ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } অন্যথা {
            op->priority = constraint_priority(str);
        }
    }

    বাবে (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    বাবে (i = 0; i < nb_operands - 1; i++) {
        বাবে (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            যদি (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    বাবে (i = 0; i < NB_ASM_REGS; i++) {
        যদি (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        অন্যথা
            regs_allocated[i] = 0;
    }

    বাবে (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        যদি (op->ref_index >= 0)
            অনুৱর্ত;
        যদি (op->প্ৰবেশ_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } অন্যথা যদি (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } অন্যথা {
            reg_mask = REG_IN_MASK;
        }
        যদি (op->reg >= 0) {
            যদি (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            গচ্ছ reg_found;
        }
    try_next:
        c = *str++;
        ৱিকল্প (c) {
        পক্ষ '=':
            গচ্ছ try_next;
        পক্ষ '+':
            op->is_rw = 1;
        পক্ষ '&':
            যদি (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            গচ্ছ try_next;
        পক্ষ 'r':
            বাবে (reg = 0; reg < 31; reg++) {
                যদি (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    গচ্ছ reg_found;
            }
            গচ্ছ try_next;
        পক্ষ 'w':
        পক্ষ 'f':
            বাবে (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                যদি (!is_reg_allocated(reg))
                    গচ্ছ reg_found;
            }
            গচ্ছ try_next;
        পক্ষ 'x':
        পক্ষ 'y':
            বাবে (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                যদি (!is_reg_allocated(reg))
                    গচ্ছ reg_found;
            }
            গচ্ছ try_next;
        পক্ষ 'm':
        পক্ষ 'g':
            যদি (j < nb_outputs || c == 'm') {
                যদি (!arm64_prepare_memory_operand(op, regs_allocated))
                    গচ্ছ try_next;
            }
            ভঙ্গ;
        পক্ষ 'Q':
            যদি (!arm64_memory_is_base_only(op->vt))
                গচ্ছ try_next;
            যদি (!arm64_prepare_memory_operand(op, regs_allocated))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'S':
            যদি ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'U':
            যদি (str[0] != 'm' || str[1] != 'p')
                গচ্ছ try_next;
            str += 2;
            যদি (!arm64_memory_is_pair_suitable(op->vt))
                গচ্ছ try_next;
            যদি (!arm64_prepare_memory_operand(op, regs_allocated))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'i':
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'I':
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                গচ্ছ try_next;
            যদি (!is_valid_add_imm(op->vt->c.i))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'J':
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                গচ্ছ try_next;
            যদি (!is_valid_add_imm(-op->vt->c.i))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'K':
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                গচ্ছ try_next;
            যদি (!is_valid_logical_imm(op->vt->c.i, 32))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'L':
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                গচ্ছ try_next;
            যদি (!is_valid_logical_imm(op->vt->c.i, 64))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'M':
        পক্ষ 'N':
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                গচ্ছ try_next;
            যদি (!is_valid_movw_imm(op->vt->c.i))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'Z':
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                গচ্ছ try_next;
            যদি (op->vt->c.i != 0)
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'n':
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                গচ্ছ try_next;
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            ভঙ্গ;
        }
        যদি (op->প্ৰবেশ_index >= 0) {
            operands[op->প্ৰবেশ_index].reg = op->reg;
            operands[op->প্ৰবেশ_index].is_llong = op->is_llong;
        }
        অনুৱর্ত;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        যদি (op->প্ৰবেশ_index >= 0) {
            operands[op->প্ৰবেশ_index].reg = op->reg;
            operands[op->প্ৰবেশ_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    বাবে (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        যদি (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            বাবে (reg = 0; reg < 31; reg++) {
                যদি (!(regs_allocated[reg] & REG_OUT_MASK))
                    গচ্ছ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            ভঙ্গ;
        }
    }
}

/* Handle clobber list */
ST_FUNC শূন্য asm_clobber(uint8_t *clobber_regs, ধ্রুৱ ৱর্ণ *str)
{
    পূর্ণাঙ্ক reg;

    যদি (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ঘূৰাই;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    যদি (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC পূর্ণাঙ্ক asm_parse_regvar(পূর্ণাঙ্ক t)
{
    ঘূৰাই arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
