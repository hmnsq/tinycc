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

ST_FUNC تهی g(صحیح c);
ST_FUNC تهی gen_le16(صحیح c);
ST_FUNC تهی gen_le32(صحیح c);

/*************************************************************/
#وگرنه
/*************************************************************/

#define USING_GLOBALS
#شامل "tcc.h"

/* Register type flags */
#define REG_X     0x01  /* 64-bit general purpose */
#define REG_W     0x02  /* 32-bit general purpose */
#define REG_V     0x04  /* 128-bit SIMD */
#define REG_D     0x08  /* 64-bit FP */
#define REG_S     0x10  /* 32-bit FP */
#define REG_H     0x20  /* 16-bit FP */
#define REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
شمارش {
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

تعریفنوع ساختار Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    صحیح reg_tok;
    عبارت_مقدار e;
} Operand;

شمارش {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
ایستا تهی parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC تهی g(صحیح c)
{
    صحیح ind1;
    اگر (nocode_wanted)
        بازگشت;
    ind1 = ind + 1;
    اگر (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC تهی gen_le16(صحیح c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC تهی gen_le32(صحیح c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC تهی gen_expr32(عبارت_مقدار *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
ایستا تهی emit_instr32(uint32_t val)
{
    اگر (nocode_wanted)
        بازگشت;
    اگر (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
ایستا صحیح arm64_parse_asm_reg(صحیح t)
{
    /* X registers (64-bit) */
    اگر (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        بازگشت t - TOK_ASM_x0;
    /* W registers (32-bit) */
    اگر (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        بازگشت t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    اگر (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        بازگشت (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    اگر (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        بازگشت (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    اگر (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        بازگشت (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    اگر (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        بازگشت (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    اگر (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        بازگشت (t - TOK_ASM_b0) + 32;
    /* Special registers */
    اگر (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        بازگشت 31;  /* SP/ZR encoded as 31 */
    بازگشت -1;
}

/* Get register type from token */
ایستا uint8_t get_reg_type(صحیح t)
{
    اگر (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        بازگشت REG_X;
    اگر (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        بازگشت REG_W;
    اگر (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        بازگشت REG_V;
    اگر (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        بازگشت REG_D;
    اگر (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        بازگشت REG_S;
    اگر (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        بازگشت REG_H;
    اگر (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        بازگشت REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    اگر (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        بازگشت REG_X;
    اگر (t == TOK_ASM_wzr)
        بازگشت REG_W;
    بازگشت REG_X;
}

/* Parse condition code */
ایستا صحیح parse_condition(صحیح t)
{
    انتخاب (t) {
        حالت TOK_ASM_eq: بازگشت 0;
        حالت TOK_ASM_ne: بازگشت 1;
        حالت TOK_ASM_cs:
        حالت TOK_ASM_hs: بازگشت 2;
        حالت TOK_ASM_cc:
        حالت TOK_ASM_lo: بازگشت 3;
        حالت TOK_ASM_mi: بازگشت 4;
        حالت TOK_ASM_pl: بازگشت 5;
        حالت TOK_ASM_vs: بازگشت 6;
        حالت TOK_ASM_vc: بازگشت 7;
        حالت TOK_ASM_hi: بازگشت 8;
        حالت TOK_ASM_ls: بازگشت 9;
        حالت TOK_ASM_ge: بازگشت 10;
        حالت TOK_ASM_lt: بازگشت 11;
        حالت TOK_ASM_gt: بازگشت 12;
        حالت TOK_ASM_le: بازگشت 13;
        حالت TOK_ASM_al: بازگشت 14;
        پیشفرض: بازگشت -1;
    }
}

ایستا صحیح parse_barrier_option_name(صحیح t)
{
    ثابت نویسه *name;

    اگر (t < TOK_IDENT)
        بازگشت -1;
    name = get_tok_str(t, پوچ);
    اگر (!strcmp(name, "oshld")) بازگشت 0x1;
    اگر (!strcmp(name, "oshst")) بازگشت 0x2;
    اگر (!strcmp(name, "osh"))   بازگشت 0x3;
    اگر (!strcmp(name, "nshld")) بازگشت 0x5;
    اگر (!strcmp(name, "nshst")) بازگشت 0x6;
    اگر (!strcmp(name, "nsh"))   بازگشت 0x7;
    اگر (!strcmp(name, "ishld")) بازگشت 0x9;
    اگر (!strcmp(name, "ishst")) بازگشت 0xA;
    اگر (!strcmp(name, "ish"))   بازگشت 0xB;
    اگر (!strcmp(name, "ld"))    بازگشت 0xD;
    اگر (!strcmp(name, "st"))    بازگشت 0xE;
    اگر (!strcmp(name, "sy"))    بازگشت 0xF;
    بازگشت -1;
}

ایستا صحیح arm64_parse_regvar(صحیح t)
{
    اگر (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        بازگشت t - TOK_ASM_x0;
    اگر (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        بازگشت ARM64_FREG_BASE + (t - TOK_ASM_v0);
    اگر (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        بازگشت ARM64_FREG_BASE + (t - TOK_ASM_d0);
    اگر (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        بازگشت ARM64_FREG_BASE + (t - TOK_ASM_s0);
    اگر (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        بازگشت ARM64_FREG_BASE + (t - TOK_ASM_h0);
    اگر (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        بازگشت ARM64_FREG_BASE + (t - TOK_ASM_b0);
    بازگشت -1;
}

/* Parse a single operand */
ایستا تهی parse_operand(TCCState *s1, Operand *op)
{
    صحیح reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    اگر (tok == '[') {
        parse_addr_operand(s1, op);
        بازگشت;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    اگر (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        بازگشت;
    }

    /* Condition code */
    reg = parse_condition(tok);
    اگر (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        بازگشت;
    }

    /* Immediate or address expression */
    اگر (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_عبارت(s1, &op->e);
        op->type = OP_IM;
    } وگرنه اگر (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } وگرنه {
        asm_عبارت(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
ایستا تهی parse_عبارت_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    اگر (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_عبارت(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
ایستا تهی parse_addr_operand(TCCState *s1, Operand *op)
{
    صحیح reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = پوچ;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    اگر (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        بازگشت;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    اگر (tok == ',') {
        next();
        اگر (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_عبارت(s1, &op->e);
    }
    skip(']');
    اگر (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } وگرنه اگر (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        اگر (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_عبارت(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
ایستا تهی gen_mov_with_base(صحیح rd, uint16_t imm, صحیح shift,
                              صحیح is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    اگر (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ایستا تهی gen_movz(صحیح rd, uint16_t imm, صحیح shift, صحیح is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
ایستا تهی gen_movn(صحیح rd, uint16_t imm, صحیح shift, صحیح is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
ایستا تهی gen_movk(صحیح rd, uint16_t imm, صحیح shift, صحیح is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
ایستا تهی gen_add_imm(صحیح rd, صحیح rn, uint32_t imm, صحیح is_64bit, صحیح setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    اگر (is_64bit) instr |= ARM64_SF(1);
    اگر (setflags) instr |= ARM64_S(1);

    اگر (imm <= 0xFFF) {
        imm12 = imm;
    } وگرنه اگر (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } وگرنه {
        tcc_error("add immediate out of range");
        بازگشت;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
ایستا تهی gen_sub_imm(صحیح rd, صحیح rn, uint32_t imm, صحیح is_64bit, صحیح setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    اگر (is_64bit) instr |= ARM64_SF(1);
    اگر (setflags) instr |= ARM64_S(1);

    اگر (imm <= 0xFFF) {
        imm12 = imm;
    } وگرنه اگر (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } وگرنه {
        tcc_error("sub immediate out of range");
        بازگشت;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
ایستا تهی gen_dp_reg(uint32_t opcode, صحیح rd, صحیح rn, صحیح rm, صحیح is_64bit)
{
    uint32_t instr = opcode;
    اگر (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
ایستا تهی gen_ldst_imm(uint32_t base_opcode, صحیح rt, صحیح rn,
                         int32_t offset, صحیح size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    اگر (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        اگر (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            بازگشت;
        }
    }

    انتخاب (base_opcode) {
    حالت ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; بشکن;
    حالت ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; بشکن;
    حالت ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; بشکن;
    حالت ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; بشکن;
    حالت ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; بشکن;
    حالت ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; بشکن;
    حالت ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; بشکن;
    حالت ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; بشکن;
    حالت ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; بشکن;
    حالت ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; بشکن;
    }

    اگر (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        بازگشت;
    }

    اگر (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
ایستا تهی gen_ldst_pair(uint32_t base_opcode, صحیح rt, صحیح rt2, صحیح rn,
                          int32_t offset, صحیح size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    اگر (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    اگر (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
ایستا تهی gen_b_or_bl(int32_t offset, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    instr |= ARM64_OFFSET26(offset);
    emit_instr32(instr);
}

ایستا تهی gen_b(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_B);
}

/* Generate BL (branch with link) */
ایستا تهی gen_bl(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_BL);
}

/* Generate BR (branch to register) */
ایستا تهی gen_br(صحیح rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
ایستا تهی gen_blr(صحیح rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
ایستا تهی gen_ret(صحیح rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
ایستا تهی gen_b_cond(صحیح cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
ایستا تهی gen_cbz_or_cbnz(صحیح rt, int32_t offset, صحیح is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    اگر (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

ایستا تهی gen_cbz(صحیح rt, int32_t offset, صحیح is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
ایستا تهی gen_cbnz(صحیح rt, int32_t offset, صحیح is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
ایستا تهی gen_mov_reg(صحیح rd, صحیح rm, صحیح is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    اگر (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ایستا صحیح arm64_asm_encode_bimm64(uint64_t x)
{
    صحیح neg, rep, pos, len;

    neg = x & 1;
    اگر (neg)
        x = ~x;
    اگر (!x)
        بازگشت -1;

    اگر (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    وگرنه اگر (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    وگرنه اگر (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    وگرنه اگر (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    وگرنه اگر (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    وگرنه
        rep = 64;

    pos = 0;
    اگر (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    اگر (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    اگر (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    اگر (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    اگر (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    اگر (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    اگر (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    اگر (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    اگر (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    اگر (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    اگر (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    اگر (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    اگر (x)
        بازگشت -1;
    اگر (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    بازگشت ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ایستا تهی gen_logical_imm(uint32_t opcode, صحیح rd, صحیح rn,
                            uint64_t imm, صحیح is_64bit)
{
    uint32_t instr;
    uint64_t val;
    صحیح enc;

    اگر (is_64bit)
        val = imm;
    وگرنه {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    اگر (enc < 0) {
        tcc_error("logical immediate out of range");
        بازگشت;
    }

    instr = opcode;
    اگر (is_64bit)
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
ایستا درونخطی صحیح constraint_priority(ثابت نویسه *str)
{
    صحیح priority, c, pr;

    priority = 0;
    برای (;;) {
        c = *str++;
        اگر (c == '\0')
            بشکن;
        انتخاب (c) {
        حالت '=':
        حالت '+':
        حالت '&':
            ادامه;
        حالت 'r':
            pr = 1;
            بشکن;
        حالت 'w':
        حالت 'f':
        حالت 'x':
        حالت 'y':
            pr = 3;
            بشکن;
        حالت 'm':
        حالت 'Q':
            pr = 4;
            بشکن;
        حالت 'i':
        حالت 'S':
            pr = 5;
            بشکن;
        حالت 'U':
            اگر (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                بشکن;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            بشکن;
        حالت 'I':
        حالت 'J':
        حالت 'K':
        حالت 'L':
        حالت 'M':
        حالت 'N':
        حالت 'Z':
            pr = 6;
            بشکن;
        حالت 'n':
            pr = 7;
            بشکن;
        حالت 'g':
            pr = 8;
            بشکن;
        پیشفرض:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            بشکن;
        }
        اگر (pr > priority)
            priority = pr;
    }
    بازگشت priority;
}

ایستا ثابت نویسه *skip_constraint_modifiers(ثابت نویسه *p)
{
    وقتی (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    بازگشت p;
}

ایستا صحیح is_valid_add_imm(int64_t val)
{
    بازگشت val >= 0 && val <= 4095;
}

ایستا صحیح is_valid_logical_imm(int64_t val, صحیح bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    اگر (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    بازگشت arm64_asm_encode_bimm64(uval) >= 0;
}

ایستا صحیح is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    اگر (uval <= 0xFFFF)
        بازگشت 1;
    اگر (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        بازگشت 1;
    اگر (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        بازگشت 1;
    اگر ((uval & 0xFFFFFFFF00000000ULL) == 0)
        بازگشت 1;

    بازگشت 0;
}

ایستا صحیح is_valid_movw_shift(صحیح shift, صحیح is_64bit)
{
    اگر (shift < 0 || (shift & 15))
        بازگشت 0;
    اگر (shift > (is_64bit ? 48 : 16))
        بازگشت 0;
    بازگشت 1;
}

ایستا صحیح arm64_memory_is_base_only(ثابت SValue *sv)
{
    صحیح r;

    r = sv->r;
    اگر ((r & VT_VALMASK) == VT_CONST)
        بازگشت 0;
    اگر ((r & VT_VALMASK) == VT_LOCAL)
        بازگشت 0;
    اگر ((r & VT_VALMASK) == VT_LLOCAL)
        بازگشت 1;
    اگر (r & VT_LVAL)
        بازگشت (r & VT_VALMASK) < VT_CONST;
    بازگشت 0;
}

ایستا صحیح arm64_memory_is_pair_suitable(ثابت SValue *sv)
{
    int64_t offset;

    اگر (arm64_memory_is_base_only(sv))
        بازگشت 1;
    اگر ((sv->r & VT_VALMASK) != VT_LOCAL)
        بازگشت 0;

    offset = (int64_t)sv->c.i;
    بازگشت (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

ایستا صحیح arm64_int_reg_is_allocatable(صحیح reg)
{
#ifdef TCC_TARGET_PE
    بازگشت reg >= TREG_X0 && reg <= TREG_X17;
#وگرنه
    بازگشت reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

ایستا صحیح arm64_memory_needs_address_reg(ثابت SValue *sv)
{
    صحیح r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    اگر (!(r & VT_LVAL))
        بازگشت 0;
    انتخاب (r & VT_VALMASK) {
    حالت VT_LOCAL:
    حالت VT_LLOCAL:
    حالت VT_CONST:
        بازگشت 1;
    }
    بازگشت 0;
}

ایستا صحیح arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    صحیح reg;

    اگر (!arm64_memory_needs_address_reg(op->vt))
        بازگشت 1;

    برای (reg = 0; reg < 31; reg++) {
        اگر (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            بازگشت 1;
        }
    }
    بازگشت 0;
}

ایستا تهی arm64_load_memory_operand_base(صحیح reg, SValue *sv)
{
    SValue base;
    صحیح rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    اگر (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } وگرنه اگر (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } وگرنه {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

ایستا صحیح operand_is_sp(ثابت Operand *op)
{
    بازگشت op->reg_tok == TOK_ASM_sp;
}

ایستا صحیح parse_sysreg_name(صحیح t)
{
    ثابت نویسه *name;

    اگر (t < TOK_IDENT)
        بازگشت -1;
    name = get_tok_str(t, پوچ);
    اگر (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        بازگشت 0;
    اگر (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        بازگشت 1;
    بازگشت -1;
}

ایستا تهی gen_mrs(صحیح rt, صحیح sysreg)
{
    uint32_t instr;

    انتخاب (sysreg) {
        حالت 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            بشکن;
        حالت 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            بشکن;
        پیشفرض:
            tcc_error("unsupported system register");
            بازگشت;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

ایستا تهی gen_msr(صحیح rt, صحیح sysreg)
{
    uint32_t instr;

    انتخاب (sysreg) {
        حالت 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            بشکن;
        حالت 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            بشکن;
        پیشفرض:
            tcc_error("unsupported system register");
            بازگشت;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
ایستا تهی gen_nop(تهی)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
ایستا تهی gen_shift(صحیح rd, صحیح rn, صحیح rm_or_imm, صحیح shift_type, صحیح is_imm, صحیح is_64bit)
{
    uint32_t instr;
    صحیح width = is_64bit ? 64 : 32;

    اگر (is_imm) {
        /* Shift by immediate */
        انتخاب (shift_type) {
            حالت 0: /* LSL - UBFM alias */
                اگر (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    بازگشت;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                بشکن;
            حالت 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                اگر (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    بازگشت;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                بشکن;
            حالت 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                اگر (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    بازگشت;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                بشکن;
            حالت 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                اگر (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    بازگشت;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                بازگشت;
            پیشفرض:
                tcc_error("unknown shift type");
                بازگشت;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } وگرنه {
        /* Shift by register */
        انتخاب (shift_type) {
            حالت 0: /* LSL */
                instr = ARM64_LSL_REG;
                بشکن;
            حالت 1: /* LSR */
                instr = ARM64_LSR_REG;
                بشکن;
            حالت 2: /* ASR */
                instr = ARM64_ASR_REG;
                بشکن;
            حالت 3: /* ROR */
                instr = ARM64_ROR_REG;
                بشکن;
            پیشفرض:
                tcc_error("unknown shift type");
                بازگشت;
        }
        اگر (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
ایستا تهی asm_shift(TCCState *s1, صحیح token)
{
    Operand op1, op2, op3;
    صحیح rd, rn, shift_amount;
    صحیح shift_type;
    صحیح is_64bit = 1;

    انتخاب (token) {
        حالت TOK_ASM_lsl:
            shift_type = 0;
            بشکن;
        حالت TOK_ASM_lsr:
            shift_type = 1;
            بشکن;
        حالت TOK_ASM_asr:
            shift_type = 2;
            بشکن;
        حالت TOK_ASM_ror:
            shift_type = 3;
            بشکن;
        پیشفرض:
            tcc_error("unknown shift instruction");
            بازگشت;
    }

    parse_operand(s1, &op1);
    اگر (tok == ',') next();
    parse_operand(s1, &op2);

    اگر (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        بازگشت;
    }
    اگر (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        بازگشت;
    }

    rd = op1.reg;
    rn = op2.reg;

    اگر (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        اگر (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            بازگشت;
        }
        اگر (op3.type & OP_REG) {
            اگر (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                بازگشت;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } وگرنه اگر (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } وگرنه {
            tcc_error("shift requires immediate or register operand");
        }
    } وگرنه {
        tcc_error("shift requires immediate or register operand");
        بازگشت;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
ایستا تهی gen_barrier(صحیح barrier_type, صحیح option)
{
    uint32_t instr;

    انتخاب (barrier_type) {
        حالت 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            بشکن;
        حالت 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            بشکن;
        حالت 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            بشکن;
        پیشفرض:
            tcc_error("unknown barrier type");
            بازگشت;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
ایستا تهی asm_barrier(TCCState *s1, صحیح token)
{
    صحیح barrier_type, option;
    Operand op;

    انتخاب (token) {
        حالت TOK_ASM_isb:
            barrier_type = 0;
            بشکن;
        حالت TOK_ASM_dsb:
            barrier_type = 1;
            بشکن;
        حالت TOK_ASM_dmb:
            barrier_type = 2;
            بشکن;
        پیشفرض:
            tcc_error("unknown barrier instruction");
            بازگشت;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    اگر (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        اگر (option >= 0) {
            next();
        } وگرنه {
            parse_operand(s1, &op);
            اگر (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                بازگشت;
            }
            اگر (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                بازگشت;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
ایستا تهی gen_mov_imm(صحیح rd, uint64_t imm, صحیح is_64bit)
{
    uint16_t hw;
    صحیح i, first = 1;

    برای (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        اگر (hw != 0 || i == 0) {
            اگر (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } وگرنه {
                gen_movk(rd, hw, i, is_64bit);
            }
        } وگرنه اگر (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
ایستا تهی asm_mov(TCCState *s1)
{
    Operand op1, op2;
    صحیح rd, rn;
    صحیح is_64bit;

    parse_operand(s1, &op1);
    اگر (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    اگر (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        اگر (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            بازگشت;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } وگرنه اگر (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        اگر (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        وگرنه
            gen_mov_reg(rd, rn, is_64bit);
    } وگرنه {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
ایستا تهی asm_data_proc(TCCState *s1, صحیح token)
{
    Operand op1, op2, op3;
    صحیح rd, rn, rm;
    صحیح is_64bit = 1;
    uint32_t opcode;

    انتخاب (token) {
        حالت TOK_ASM_add:
        حالت TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            بشکن;
        حالت TOK_ASM_sub:
        حالت TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            بشکن;
        حالت TOK_ASM_and:
        حالت TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            بشکن;
        حالت TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            بشکن;
        حالت TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            بشکن;
        حالت TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            بشکن;
        پیشفرض:
            tcc_error("unsupported data processing instruction");
            بازگشت;
    }

    parse_operand(s1, &op1);
    اگر (tok == ',') next();
    parse_operand(s1, &op2);

    اگر (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        بازگشت;
    }
    اگر (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        بازگشت;
    }

    rd = op1.reg;
    rn = op2.reg;

    اگر (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        اگر (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            بازگشت;
        }
        اگر (op3.type & OP_IM) {
            اگر (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            وگرنه اگر (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            وگرنه اگر (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            وگرنه اگر (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            وگرنه اگر (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            وگرنه اگر (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            وگرنه
                tcc_error("immediate operand not valid for this instruction");
        } وگرنه {
            اگر (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                بازگشت;
            }
            rm = op3.reg;
            اگر (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                بازگشت;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } وگرنه اگر (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } وگرنه {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
ایستا تهی asm_ldst(TCCState *s1, صحیح token)
{
    Operand op1, op2;
    صحیح rt, rn;
    int32_t offset = 0;
    صحیح size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    اگر (tok == ',') next();
    parse_operand(s1, &op2);

    اگر (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        بازگشت;
    }
    اگر (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        بازگشت;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    انتخاب (token) {
        حالت TOK_ASM_ldr:
            اگر (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } وگرنه اگر (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } وگرنه اگر (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } وگرنه {
                tcc_error("ldr requires a w, x, or d register");
                بازگشت;
            }
            بشکن;
        حالت TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            بشکن;
        حالت TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            بشکن;
        حالت TOK_ASM_str:
            اگر (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } وگرنه اگر (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } وگرنه اگر (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } وگرنه {
                tcc_error("str requires a w, x, or d register");
                بازگشت;
            }
            بشکن;
        حالت TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            بشکن;
        حالت TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            بشکن;
        پیشفرض:
            tcc_error("unsupported load/store instruction");
            بازگشت;
    }

    اگر (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

ایستا تهی asm_ldst_pair(TCCState *s1, صحیح token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    صحیح size_log2 = 3;

    parse_operand(s1, &op1);
    اگر (tok == ',')
        next();
    parse_operand(s1, &op2);
    اگر (tok == ',')
        next();
    parse_operand(s1, &op3);

    اگر (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        بازگشت;
    }
    اگر (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        بازگشت;
    }
    اگر (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    اگر ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        اگر (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } وگرنه {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } وگرنه اگر ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        اگر (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } وگرنه {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } وگرنه {
        tcc_error("stp/ldp requires matching x or d registers");
        بازگشت;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

ایستا تهی asm_sysreg(TCCState *s1, صحیح token)
{
    Operand op;
    صحیح sysreg;

    اگر (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        اگر (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        اگر (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        بازگشت;
    }

    sysreg = parse_sysreg_name(tok);
    اگر (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    اگر (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
ایستا صحیح get_branch_condition(صحیح branch_token)
{
    صحیح cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    انتخاب (branch_token) {
        حالت TOK_ASM_beq: cond_token = TOK_ASM_eq; بشکن;
        حالت TOK_ASM_bne: cond_token = TOK_ASM_ne; بشکن;
        حالت TOK_ASM_bcs:
        حالت TOK_ASM_bhs: cond_token = TOK_ASM_cs; بشکن;
        حالت TOK_ASM_bcc:
        حالت TOK_ASM_blo: cond_token = TOK_ASM_cc; بشکن;
        حالت TOK_ASM_bmi: cond_token = TOK_ASM_mi; بشکن;
        حالت TOK_ASM_bpl: cond_token = TOK_ASM_pl; بشکن;
        حالت TOK_ASM_bvs: cond_token = TOK_ASM_vs; بشکن;
        حالت TOK_ASM_bvc: cond_token = TOK_ASM_vc; بشکن;
        حالت TOK_ASM_bhi: cond_token = TOK_ASM_hi; بشکن;
        حالت TOK_ASM_bls: cond_token = TOK_ASM_ls; بشکن;
        حالت TOK_ASM_bge: cond_token = TOK_ASM_ge; بشکن;
        حالت TOK_ASM_blt: cond_token = TOK_ASM_lt; بشکن;
        حالت TOK_ASM_bgt: cond_token = TOK_ASM_gt; بشکن;
        حالت TOK_ASM_ble: cond_token = TOK_ASM_le; بشکن;
        پیشفرض: بازگشت -1;
    }

    بازگشت parse_condition(cond_token);
}

/* Handle branch instructions */
ایستا تهی asm_branch(TCCState *s1, صحیح token)
{
    Operand op;
    صحیح cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    اگر (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        بازگشت;
    }

    اگر (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    وگرنه
        parse_عبارت_operand(s1, &op);

    اگر (op.type & OP_IM) {
        sym = op.e.sym;
        اگر (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            اگر (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } وگرنه {
                انتخاب (token) {
                    حالت TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        بشکن;
                    حالت TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        بشکن;
                    پیشفرض:
                        tcc_error("unsupported branch");
                }
            }
        } وگرنه {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            اگر (cond >= 0) {
                gen_b_cond(cond, offset);
            } وگرنه {
                انتخاب (token) {
                    حالت TOK_ASM_b:
                        gen_b(offset);
                        بشکن;
                    حالت TOK_ASM_bl:
                        gen_bl(offset);
                        بشکن;
                    پیشفرض:
                        tcc_error("unsupported branch");
                }
            }
        }
    } وگرنه اگر (op.type & OP_REG) {
        انتخاب (token) {
            حالت TOK_ASM_br:
                gen_br(op.reg);
                بشکن;
            حالت TOK_ASM_blr:
                gen_blr(op.reg);
                بشکن;
            حالت TOK_ASM_ret:
                gen_ret(op.reg);
                بشکن;
            پیشفرض:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
ایستا تهی asm_cb(TCCState *s1, صحیح token)
{
    Operand op1, op2;
    صحیح rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    اگر (tok == ',') next();
    parse_عبارت_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    اگر (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        اگر (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } وگرنه {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } وگرنه {
        offset = (int32_t)op2.e.v - ind;
        اگر (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        وگرنه
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
ایستا تهی asm_move_wide(TCCState *s1, صحیح token)
{
    Operand op1, op2;
    صحیح rd, is_64bit = 1;
    uint16_t imm;
    صحیح shift = 0;

    parse_operand(s1, &op1);
    اگر (tok == ',') next();
    parse_operand(s1, &op2);

    اگر (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        بازگشت;
    }
    اگر (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        بازگشت;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    اگر ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        بازگشت;
    }
    imm = op2.e.v;

    اگر (tok == ',') {
        next();
        اگر (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            بازگشت;
        }
            next();
            اگر (tok == '#') next();
            asm_عبارت(s1, &op2.e);
        اگر (op2.e.sym || !is_valid_movw_shift((صحیح)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            بازگشت;
        }
            shift = (صحیح)op2.e.v / 16;
        }

    انتخاب (token) {
        حالت TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            بشکن;
        حالت TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            بشکن;
        حالت TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            بشکن;
        پیشفرض:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC تهی asm_opcode(TCCState *s1, صحیح opcode)
{
    انتخاب (opcode) {
        حالت TOK_ASM_add:
        حالت TOK_ASM_adds:
        حالت TOK_ASM_sub:
        حالت TOK_ASM_subs:
        حالت TOK_ASM_and:
        حالت TOK_ASM_ands:
        حالت TOK_ASM_orr:
        حالت TOK_ASM_eor:
        حالت TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            بشکن;

        حالت TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            بشکن;

        حالت TOK_ASM_lsl:
        حالت TOK_ASM_lsr:
        حالت TOK_ASM_asr:
        حالت TOK_ASM_ror:
            asm_shift(s1, opcode);
            بشکن;

        حالت TOK_ASM_ldr:
        حالت TOK_ASM_ldrb:
        حالت TOK_ASM_ldrh:
        حالت TOK_ASM_str:
        حالت TOK_ASM_strb:
        حالت TOK_ASM_strh:
            asm_ldst(s1, opcode);
            بشکن;

        حالت TOK_ASM_ldp:
        حالت TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            بشکن;

        حالت TOK_ASM_b:
        حالت TOK_ASM_bl:
        حالت TOK_ASM_br:
        حالت TOK_ASM_blr:
        حالت TOK_ASM_ret:
        حالت TOK_ASM_beq:
        حالت TOK_ASM_bne:
        حالت TOK_ASM_bcs:
        حالت TOK_ASM_bhs:
        حالت TOK_ASM_bcc:
        حالت TOK_ASM_blo:
        حالت TOK_ASM_bmi:
        حالت TOK_ASM_bpl:
        حالت TOK_ASM_bvs:
        حالت TOK_ASM_bvc:
        حالت TOK_ASM_bhi:
        حالت TOK_ASM_bls:
        حالت TOK_ASM_bge:
        حالت TOK_ASM_blt:
        حالت TOK_ASM_bgt:
        حالت TOK_ASM_ble:
            asm_branch(s1, opcode);
            بشکن;

        حالت TOK_ASM_cbz:
        حالت TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            بشکن;

        حالت TOK_ASM_movz:
        حالت TOK_ASM_movn:
        حالت TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            بشکن;

        حالت TOK_ASM_mrs:
        حالت TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            بشکن;

        حالت TOK_ASM_isb:
        حالت TOK_ASM_dsb:
        حالت TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            بشکن;

        حالت TOK_ASM_nop:
            gen_nop();
            بشکن;

        پیشفرض:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, پوچ));
            بشکن;
    }
}

/* Substitute assembler operand */
ST_FUNC تهی subst_asm_operand(CString *add_str, SValue *sv, صحیح modifier)
{
    صحیح r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    اگر ((r & VT_VALMASK) == VT_CONST) {
        اگر ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            بازگشت;
        }
        اگر (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        اگر (r & VT_SYM) {
            ثابت نویسه *name = get_tok_str(sv->sym->v, پوچ);
            اگر (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            اگر (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            اگر ((uint32_t) sv->c.i == 0)
                برو no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        اگر (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } وگرنه اگر (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } وگرنه {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } وگرنه اگر ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (صحیح) sv->c.i);
    } وگرنه اگر (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } وگرنه {
        /* register case */
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_internal_error("");

        اگر (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            اگر (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            انتخاب (modifier) {
            حالت 'b':
            حالت 'h':
            حالت 's':
            حالت 'd':
            حالت 'q':
            حالت 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                بازگشت;
            پیشفرض:
                tcc_error("invalid operand modifier for SIMD/FP register");
                بازگشت;
            }
        }

        /* choose register operand size */
        اگر ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        وگرنه اگر ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        وگرنه اگر ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        وگرنه
            size = 4;

        اگر (modifier == 'x') {
            size = 8;
        } وگرنه اگر (modifier == 'w' || modifier == 'k') {
            size = 4;
        } وگرنه اگر (modifier == 'b') {
            size = 1;
        } وگرنه اگر (modifier == 'h') {
            size = 2;
        } وگرنه اگر (modifier == 'q') {
            size = 8;
        }

        اگر (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } وگرنه {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC تهی asm_gen_code(ASMOperand *operands, صحیح nb_operands,
                          صحیح nb_outputs, صحیح is_output,
                          uint8_t *clobber_regs,
                          صحیح out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    صحیح i, reg, saved_شمار, پشته_size, پشته_off;
    صحیح saved_regs[12];
    ایستا ثابت uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, اندازه(regs_allocated));
    برای (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        اگر (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_شمار = 0;
    برای (i = 0; i < اندازه(reg_saved) / اندازه(reg_saved[0]); i++) {
        reg = reg_saved[i];
        اگر (regs_allocated[reg])
            saved_regs[saved_شمار++] = reg;
    }
    پشته_size = ((saved_شمار + 1) / 2) * 16;

    اگر (!is_output) {
        اگر (saved_شمار > 0) {
            gen_sub_imm(31, 31, پشته_size, 1, 0);

            برای (i = پشته_off = 0; i < saved_شمار; ) {
                اگر (i + 1 < saved_شمار) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, پشته_off, 3);
                    پشته_off += 16;
                    i += 2;
                } وگرنه {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 پشته_off, 3);
                    i++;
                }
            }
        }

        برای (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } وگرنه اگر (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } وگرنه {
        برای (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر (op->is_memory)
                    ادامه;
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    اگر (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } وگرنه {
                    store(op->reg, op->vt);
                }
            }
        }

        اگر (saved_شمار > 0) {
            برای (i = پشته_off = 0; i < saved_شمار; ) {
                اگر (i + 1 < saved_شمار) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, پشته_off, 3);
                    پشته_off += 16;
                    i += 2;
                } وگرنه {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 پشته_off, 3);
                    i++;
                }
            }
            gen_add_imm(31, 31, پشته_size, 1, 0);
        }
    }
}

ST_FUNC تهی asm_compute_constraints(ASMOperand *operands,
                                    صحیح nb_operands, صحیح nb_outputs,
                                    ثابت uint8_t *clobber_regs,
                                    صحیح *pout_reg)
{
    ASMOperand *op;
    صحیح sorted_op[MAX_ASM_OPERANDS];
    صحیح i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ثابت نویسه *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    برای (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->درون_داد_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    برای (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        اگر (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, پوچ);
            اگر ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            اگر (operands[k].درون_داد_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].درون_داد_index = i;
            op->priority = 5;
        } وگرنه اگر ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } وگرنه {
            op->priority = constraint_priority(str);
        }
    }

    برای (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    برای (i = 0; i < nb_operands - 1; i++) {
        برای (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            اگر (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    برای (i = 0; i < NB_ASM_REGS; i++) {
        اگر (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        وگرنه
            regs_allocated[i] = 0;
    }

    برای (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        اگر (op->ref_index >= 0)
            ادامه;
        اگر (op->درون_داد_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } وگرنه اگر (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } وگرنه {
            reg_mask = REG_IN_MASK;
        }
        اگر (op->reg >= 0) {
            اگر (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            برو reg_found;
        }
    try_next:
        c = *str++;
        انتخاب (c) {
        حالت '=':
            برو try_next;
        حالت '+':
            op->is_rw = 1;
        حالت '&':
            اگر (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            برو try_next;
        حالت 'r':
            برای (reg = 0; reg < 31; reg++) {
                اگر (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    برو reg_found;
            }
            برو try_next;
        حالت 'w':
        حالت 'f':
            برای (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                اگر (!is_reg_allocated(reg))
                    برو reg_found;
            }
            برو try_next;
        حالت 'x':
        حالت 'y':
            برای (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                اگر (!is_reg_allocated(reg))
                    برو reg_found;
            }
            برو try_next;
        حالت 'm':
        حالت 'g':
            اگر (j < nb_outputs || c == 'm') {
                اگر (!arm64_prepare_memory_operand(op, regs_allocated))
                    برو try_next;
            }
            بشکن;
        حالت 'Q':
            اگر (!arm64_memory_is_base_only(op->vt))
                برو try_next;
            اگر (!arm64_prepare_memory_operand(op, regs_allocated))
                برو try_next;
            بشکن;
        حالت 'S':
            اگر ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                برو try_next;
            بشکن;
        حالت 'U':
            اگر (str[0] != 'm' || str[1] != 'p')
                برو try_next;
            str += 2;
            اگر (!arm64_memory_is_pair_suitable(op->vt))
                برو try_next;
            اگر (!arm64_prepare_memory_operand(op, regs_allocated))
                برو try_next;
            بشکن;
        حالت 'i':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                برو try_next;
            بشکن;
        حالت 'I':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                برو try_next;
            اگر (!is_valid_add_imm(op->vt->c.i))
                برو try_next;
            بشکن;
        حالت 'J':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                برو try_next;
            اگر (!is_valid_add_imm(-op->vt->c.i))
                برو try_next;
            بشکن;
        حالت 'K':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                برو try_next;
            اگر (!is_valid_logical_imm(op->vt->c.i, 32))
                برو try_next;
            بشکن;
        حالت 'L':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                برو try_next;
            اگر (!is_valid_logical_imm(op->vt->c.i, 64))
                برو try_next;
            بشکن;
        حالت 'M':
        حالت 'N':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                برو try_next;
            اگر (!is_valid_movw_imm(op->vt->c.i))
                برو try_next;
            بشکن;
        حالت 'Z':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                برو try_next;
            اگر (op->vt->c.i != 0)
                برو try_next;
            بشکن;
        حالت 'n':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                برو try_next;
            بشکن;
        پیشفرض:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            بشکن;
        }
        اگر (op->درون_داد_index >= 0) {
            operands[op->درون_داد_index].reg = op->reg;
            operands[op->درون_داد_index].is_llong = op->is_llong;
        }
        ادامه;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        اگر (op->درون_داد_index >= 0) {
            operands[op->درون_داد_index].reg = op->reg;
            operands[op->درون_داد_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    برای (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        اگر (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            برای (reg = 0; reg < 31; reg++) {
                اگر (!(regs_allocated[reg] & REG_OUT_MASK))
                    برو reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            بشکن;
        }
    }
}

/* Handle clobber list */
ST_FUNC تهی asm_clobber(uint8_t *clobber_regs, ثابت نویسه *str)
{
    صحیح reg;

    اگر (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        بازگشت;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    اگر (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC صحیح asm_parse_regvar(صحیح t)
{
    بازگشت arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
