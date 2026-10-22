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

ST_FUNC فراغ g(صحيح c);
ST_FUNC فراغ gen_le16(صحيح c);
ST_FUNC فراغ gen_le32(صحيح c);

/*************************************************************/
#אחרת
/*************************************************************/

#define USING_GLOBALS
#ضمن "tcc.h"

/* Register type flags */
#define REG_X     0x01  /* 64-bit general purpose */
#define REG_W     0x02  /* 32-bit general purpose */
#define REG_V     0x04  /* 128-bit SIMD */
#define REG_D     0x08  /* 64-bit FP */
#define REG_S     0x10  /* 32-bit FP */
#define REG_H     0x20  /* 16-bit FP */
#define REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
تعداد {
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

تعريفنوع بنية Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    صحيح reg_tok;
    ExprValue e;
} Operand;

تعداد {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
ساكن فراغ parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC فراغ g(صحيح c)
{
    صحيح ind1;
    אם (nocode_wanted)
        החזר;
    ind1 = ind + 1;
    אם (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC فراغ gen_le16(صحيح c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC فراغ gen_le32(صحيح c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC فراغ gen_expr32(ExprValue *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
ساكن فراغ emit_instr32(uint32_t val)
{
    אם (nocode_wanted)
        החזר;
    אם (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
ساكن صحيح arm64_parse_asm_reg(صحيح t)
{
    /* X registers (64-bit) */
    אם (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        החזר t - TOK_ASM_x0;
    /* W registers (32-bit) */
    אם (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        החזר t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    אם (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        החזר (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    אם (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        החזר (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    אם (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        החזר (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    אם (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        החזר (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    אם (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        החזר (t - TOK_ASM_b0) + 32;
    /* Special registers */
    אם (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        החזר 31;  /* SP/ZR encoded as 31 */
    החזר -1;
}

/* Get register type from token */
ساكن uint8_t get_reg_type(صحيح t)
{
    אם (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        החזר REG_X;
    אם (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        החזר REG_W;
    אם (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        החזר REG_V;
    אם (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        החזר REG_D;
    אם (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        החזר REG_S;
    אם (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        החזר REG_H;
    אם (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        החזר REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    אם (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        החזר REG_X;
    אם (t == TOK_ASM_wzr)
        החזר REG_W;
    החזר REG_X;
}

/* Parse condition code */
ساكن صحيح parse_condition(صحيح t)
{
    بدل (t) {
        حالة TOK_ASM_eq: החזר 0;
        حالة TOK_ASM_ne: החזר 1;
        حالة TOK_ASM_cs:
        حالة TOK_ASM_hs: החזר 2;
        حالة TOK_ASM_cc:
        حالة TOK_ASM_lo: החזר 3;
        حالة TOK_ASM_mi: החזר 4;
        حالة TOK_ASM_pl: החזר 5;
        حالة TOK_ASM_vs: החזר 6;
        حالة TOK_ASM_vc: החזר 7;
        حالة TOK_ASM_hi: החזר 8;
        حالة TOK_ASM_ls: החזר 9;
        حالة TOK_ASM_ge: החזר 10;
        حالة TOK_ASM_lt: החזר 11;
        حالة TOK_ASM_gt: החזר 12;
        حالة TOK_ASM_le: החזר 13;
        حالة TOK_ASM_al: החזר 14;
        افتراضي: החזר -1;
    }
}

ساكن صحيح parse_barrier_option_name(صحيح t)
{
    ثابت حرف *name;

    אם (t < TOK_IDENT)
        החזר -1;
    name = get_tok_str(t, عدم);
    אם (!strcmp(name, "oshld")) החזר 0x1;
    אם (!strcmp(name, "oshst")) החזר 0x2;
    אם (!strcmp(name, "osh"))   החזר 0x3;
    אם (!strcmp(name, "nshld")) החזר 0x5;
    אם (!strcmp(name, "nshst")) החזר 0x6;
    אם (!strcmp(name, "nsh"))   החזר 0x7;
    אם (!strcmp(name, "ishld")) החזר 0x9;
    אם (!strcmp(name, "ishst")) החזר 0xA;
    אם (!strcmp(name, "ish"))   החזר 0xB;
    אם (!strcmp(name, "ld"))    החזר 0xD;
    אם (!strcmp(name, "st"))    החזר 0xE;
    אם (!strcmp(name, "sy"))    החזר 0xF;
    החזר -1;
}

ساكن صحيح arm64_parse_regvar(صحيح t)
{
    אם (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        החזר t - TOK_ASM_x0;
    אם (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        החזר ARM64_FREG_BASE + (t - TOK_ASM_v0);
    אם (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        החזר ARM64_FREG_BASE + (t - TOK_ASM_d0);
    אם (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        החזר ARM64_FREG_BASE + (t - TOK_ASM_s0);
    אם (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        החזר ARM64_FREG_BASE + (t - TOK_ASM_h0);
    אם (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        החזר ARM64_FREG_BASE + (t - TOK_ASM_b0);
    החזר -1;
}

/* Parse a single operand */
ساكن فراغ parse_operand(TCCState *s1, Operand *op)
{
    صحيح reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    אם (tok == '[') {
        parse_addr_operand(s1, op);
        החזר;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    אם (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        החזר;
    }

    /* Condition code */
    reg = parse_condition(tok);
    אם (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        החזר;
    }

    /* Immediate or address expression */
    אם (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_expr(s1, &op->e);
        op->type = OP_IM;
    } אחרת אם (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } אחרת {
        asm_expr(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
ساكن فراغ parse_expr_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    אם (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_expr(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
ساكن فراغ parse_addr_operand(TCCState *s1, Operand *op)
{
    صحيح reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = عدم;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    אם (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        החזר;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    אם (tok == ',') {
        next();
        אם (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_expr(s1, &op->e);
    }
    skip(']');
    אם (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } אחרת אם (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        אם (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_expr(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
ساكن فراغ gen_mov_with_base(صحيح rd, uint16_t imm, صحيح shift,
                              صحيح is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    אם (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ساكن فراغ gen_movz(صحيح rd, uint16_t imm, صحيح shift, صحيح is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
ساكن فراغ gen_movn(صحيح rd, uint16_t imm, صحيح shift, صحيح is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
ساكن فراغ gen_movk(صحيح rd, uint16_t imm, صحيح shift, صحيح is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
ساكن فراغ gen_add_imm(صحيح rd, صحيح rn, uint32_t imm, صحيح is_64bit, صحيح setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    אם (is_64bit) instr |= ARM64_SF(1);
    אם (setflags) instr |= ARM64_S(1);

    אם (imm <= 0xFFF) {
        imm12 = imm;
    } אחרת אם (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } אחרת {
        tcc_error("add immediate out of range");
        החזר;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
ساكن فراغ gen_sub_imm(صحيح rd, صحيح rn, uint32_t imm, صحيح is_64bit, صحيح setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    אם (is_64bit) instr |= ARM64_SF(1);
    אם (setflags) instr |= ARM64_S(1);

    אם (imm <= 0xFFF) {
        imm12 = imm;
    } אחרת אם (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } אחרת {
        tcc_error("sub immediate out of range");
        החזר;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
ساكن فراغ gen_dp_reg(uint32_t opcode, صحيح rd, صحيح rn, صحيح rm, صحيح is_64bit)
{
    uint32_t instr = opcode;
    אם (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
ساكن فراغ gen_ldst_imm(uint32_t base_opcode, صحيح rt, صحيح rn,
                         int32_t offset, صحيح size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    אם (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        אם (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            החזר;
        }
    }

    بدل (base_opcode) {
    حالة ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; اكسر;
    حالة ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; اكسر;
    حالة ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; اكسر;
    حالة ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; اكسر;
    حالة ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; اكسر;
    حالة ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; اكسر;
    حالة ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; اكسر;
    حالة ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; اكسر;
    حالة ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; اكسر;
    حالة ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; اكسر;
    }

    אם (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        החזר;
    }

    אם (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
ساكن فراغ gen_ldst_pair(uint32_t base_opcode, صحيح rt, صحيح rt2, صحيح rn,
                          int32_t offset, صحيح size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    אם (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    אם (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
ساكن فراغ gen_b_or_bl(int32_t offset, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    instr |= ARM64_OFFSET26(offset);
    emit_instr32(instr);
}

ساكن فراغ gen_b(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_B);
}

/* Generate BL (branch with link) */
ساكن فراغ gen_bl(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_BL);
}

/* Generate BR (branch to register) */
ساكن فراغ gen_br(صحيح rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
ساكن فراغ gen_blr(صحيح rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
ساكن فراغ gen_ret(صحيح rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
ساكن فراغ gen_b_cond(صحيح cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
ساكن فراغ gen_cbz_or_cbnz(صحيح rt, int32_t offset, صحيح is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    אם (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

ساكن فراغ gen_cbz(صحيح rt, int32_t offset, صحيح is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
ساكن فراغ gen_cbnz(صحيح rt, int32_t offset, صحيح is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
ساكن فراغ gen_mov_reg(صحيح rd, صحيح rm, صحيح is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    אם (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ساكن صحيح arm64_asm_encode_bimm64(uint64_t x)
{
    صحيح neg, rep, pos, len;

    neg = x & 1;
    אם (neg)
        x = ~x;
    אם (!x)
        החזר -1;

    אם (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    אחרת אם (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    אחרת אם (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    אחרת אם (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    אחרת אם (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    אחרת
        rep = 64;

    pos = 0;
    אם (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    אם (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    אם (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    אם (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    אם (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    אם (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    אם (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    אם (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    אם (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    אם (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    אם (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    אם (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    אם (x)
        החזר -1;
    אם (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    החזר ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ساكن فراغ gen_logical_imm(uint32_t opcode, صحيح rd, صحيح rn,
                            uint64_t imm, صحيح is_64bit)
{
    uint32_t instr;
    uint64_t val;
    صحيح enc;

    אם (is_64bit)
        val = imm;
    אחרת {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    אם (enc < 0) {
        tcc_error("logical immediate out of range");
        החזר;
    }

    instr = opcode;
    אם (is_64bit)
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
ساكن مضمن صحيح constraint_priority(ثابت حرف *str)
{
    صحيح priority, c, pr;

    priority = 0;
    עבור (;;) {
        c = *str++;
        אם (c == '\0')
            اكسر;
        بدل (c) {
        حالة '=':
        حالة '+':
        حالة '&':
            استمر;
        حالة 'r':
            pr = 1;
            اكسر;
        حالة 'w':
        حالة 'f':
        حالة 'x':
        حالة 'y':
            pr = 3;
            اكسر;
        حالة 'm':
        حالة 'Q':
            pr = 4;
            اكسر;
        حالة 'i':
        حالة 'S':
            pr = 5;
            اكسر;
        حالة 'U':
            אם (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                اكسر;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            اكسر;
        حالة 'I':
        حالة 'J':
        حالة 'K':
        حالة 'L':
        حالة 'M':
        حالة 'N':
        حالة 'Z':
            pr = 6;
            اكسر;
        حالة 'n':
            pr = 7;
            اكسر;
        حالة 'g':
            pr = 8;
            اكسر;
        افتراضي:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            اكسر;
        }
        אם (pr > priority)
            priority = pr;
    }
    החזר priority;
}

ساكن ثابت حرف *skip_constraint_modifiers(ثابت حرف *p)
{
    כלעוד (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    החזר p;
}

ساكن صحيح is_valid_add_imm(int64_t val)
{
    החזר val >= 0 && val <= 4095;
}

ساكن صحيح is_valid_logical_imm(int64_t val, صحيح bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    אם (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    החזר arm64_asm_encode_bimm64(uval) >= 0;
}

ساكن صحيح is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    אם (uval <= 0xFFFF)
        החזר 1;
    אם (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        החזר 1;
    אם (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        החזר 1;
    אם ((uval & 0xFFFFFFFF00000000ULL) == 0)
        החזר 1;

    החזר 0;
}

ساكن صحيح is_valid_movw_shift(صحيح shift, صحيح is_64bit)
{
    אם (shift < 0 || (shift & 15))
        החזר 0;
    אם (shift > (is_64bit ? 48 : 16))
        החזר 0;
    החזר 1;
}

ساكن صحيح arm64_memory_is_base_only(ثابت SValue *sv)
{
    صحيح r;

    r = sv->r;
    אם ((r & VT_VALMASK) == VT_CONST)
        החזר 0;
    אם ((r & VT_VALMASK) == VT_LOCAL)
        החזר 0;
    אם ((r & VT_VALMASK) == VT_LLOCAL)
        החזר 1;
    אם (r & VT_LVAL)
        החזר (r & VT_VALMASK) < VT_CONST;
    החזר 0;
}

ساكن صحيح arm64_memory_is_pair_suitable(ثابت SValue *sv)
{
    int64_t offset;

    אם (arm64_memory_is_base_only(sv))
        החזר 1;
    אם ((sv->r & VT_VALMASK) != VT_LOCAL)
        החזר 0;

    offset = (int64_t)sv->c.i;
    החזר (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

ساكن صحيح arm64_int_reg_is_allocatable(صحيح reg)
{
#ifdef TCC_TARGET_PE
    החזר reg >= TREG_X0 && reg <= TREG_X17;
#אחרת
    החזר reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

ساكن صحيح arm64_memory_needs_address_reg(ثابت SValue *sv)
{
    صحيح r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    אם (!(r & VT_LVAL))
        החזר 0;
    بدل (r & VT_VALMASK) {
    حالة VT_LOCAL:
    حالة VT_LLOCAL:
    حالة VT_CONST:
        החזר 1;
    }
    החזר 0;
}

ساكن صحيح arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    صحيح reg;

    אם (!arm64_memory_needs_address_reg(op->vt))
        החזר 1;

    עבור (reg = 0; reg < 31; reg++) {
        אם (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            החזר 1;
        }
    }
    החזר 0;
}

ساكن فراغ arm64_load_memory_operand_base(صحيح reg, SValue *sv)
{
    SValue base;
    صحيح rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    אם (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } אחרת אם (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } אחרת {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

ساكن صحيح operand_is_sp(ثابت Operand *op)
{
    החזר op->reg_tok == TOK_ASM_sp;
}

ساكن صحيح parse_sysreg_name(صحيح t)
{
    ثابت حرف *name;

    אם (t < TOK_IDENT)
        החזר -1;
    name = get_tok_str(t, عدم);
    אם (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        החזר 0;
    אם (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        החזר 1;
    החזר -1;
}

ساكن فراغ gen_mrs(صحيح rt, صحيح sysreg)
{
    uint32_t instr;

    بدل (sysreg) {
        حالة 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            اكسر;
        حالة 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            اكسر;
        افتراضي:
            tcc_error("unsupported system register");
            החזר;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

ساكن فراغ gen_msr(صحيح rt, صحيح sysreg)
{
    uint32_t instr;

    بدل (sysreg) {
        حالة 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            اكسر;
        حالة 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            اكسر;
        افتراضي:
            tcc_error("unsupported system register");
            החזר;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
ساكن فراغ gen_nop(فراغ)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
ساكن فراغ gen_shift(صحيح rd, صحيح rn, صحيح rm_or_imm, صحيح shift_type, صحيح is_imm, صحيح is_64bit)
{
    uint32_t instr;
    صحيح width = is_64bit ? 64 : 32;

    אם (is_imm) {
        /* Shift by immediate */
        بدل (shift_type) {
            حالة 0: /* LSL - UBFM alias */
                אם (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    החזר;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                اكسر;
            حالة 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                אם (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    החזר;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                اكسر;
            حالة 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                אם (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    החזר;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                اكسر;
            حالة 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                אם (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    החזר;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                החזר;
            افتراضي:
                tcc_error("unknown shift type");
                החזר;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } אחרת {
        /* Shift by register */
        بدل (shift_type) {
            حالة 0: /* LSL */
                instr = ARM64_LSL_REG;
                اكسر;
            حالة 1: /* LSR */
                instr = ARM64_LSR_REG;
                اكسر;
            حالة 2: /* ASR */
                instr = ARM64_ASR_REG;
                اكسر;
            حالة 3: /* ROR */
                instr = ARM64_ROR_REG;
                اكسر;
            افتراضي:
                tcc_error("unknown shift type");
                החזר;
        }
        אם (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
ساكن فراغ asm_shift(TCCState *s1, صحيح token)
{
    Operand op1, op2, op3;
    صحيح rd, rn, shift_amount;
    صحيح shift_type;
    صحيح is_64bit = 1;

    بدل (token) {
        حالة TOK_ASM_lsl:
            shift_type = 0;
            اكسر;
        حالة TOK_ASM_lsr:
            shift_type = 1;
            اكسر;
        حالة TOK_ASM_asr:
            shift_type = 2;
            اكسر;
        حالة TOK_ASM_ror:
            shift_type = 3;
            اكسر;
        افتراضي:
            tcc_error("unknown shift instruction");
            החזר;
    }

    parse_operand(s1, &op1);
    אם (tok == ',') next();
    parse_operand(s1, &op2);

    אם (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        החזר;
    }
    אם (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        החזר;
    }

    rd = op1.reg;
    rn = op2.reg;

    אם (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        אם (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            החזר;
        }
        אם (op3.type & OP_REG) {
            אם (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                החזר;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } אחרת אם (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } אחרת {
            tcc_error("shift requires immediate or register operand");
        }
    } אחרת {
        tcc_error("shift requires immediate or register operand");
        החזר;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
ساكن فراغ gen_barrier(صحيح barrier_type, صحيح option)
{
    uint32_t instr;

    بدل (barrier_type) {
        حالة 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            اكسر;
        حالة 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            اكسر;
        حالة 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            اكسر;
        افتراضي:
            tcc_error("unknown barrier type");
            החזר;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
ساكن فراغ asm_barrier(TCCState *s1, صحيح token)
{
    صحيح barrier_type, option;
    Operand op;

    بدل (token) {
        حالة TOK_ASM_isb:
            barrier_type = 0;
            اكسر;
        حالة TOK_ASM_dsb:
            barrier_type = 1;
            اكسر;
        حالة TOK_ASM_dmb:
            barrier_type = 2;
            اكسر;
        افتراضي:
            tcc_error("unknown barrier instruction");
            החזר;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    אם (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        אם (option >= 0) {
            next();
        } אחרת {
            parse_operand(s1, &op);
            אם (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                החזר;
            }
            אם (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                החזר;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
ساكن فراغ gen_mov_imm(صحيح rd, uint64_t imm, صحيح is_64bit)
{
    uint16_t hw;
    صحيح i, first = 1;

    עבור (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        אם (hw != 0 || i == 0) {
            אם (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } אחרת {
                gen_movk(rd, hw, i, is_64bit);
            }
        } אחרת אם (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
ساكن فراغ asm_mov(TCCState *s1)
{
    Operand op1, op2;
    صحيح rd, rn;
    صحيح is_64bit;

    parse_operand(s1, &op1);
    אם (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    אם (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        אם (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            החזר;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } אחרת אם (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        אם (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        אחרת
            gen_mov_reg(rd, rn, is_64bit);
    } אחרת {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
ساكن فراغ asm_data_proc(TCCState *s1, صحيح token)
{
    Operand op1, op2, op3;
    صحيح rd, rn, rm;
    صحيح is_64bit = 1;
    uint32_t opcode;

    بدل (token) {
        حالة TOK_ASM_add:
        حالة TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            اكسر;
        حالة TOK_ASM_sub:
        حالة TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            اكسر;
        حالة TOK_ASM_and:
        حالة TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            اكسر;
        حالة TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            اكسر;
        حالة TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            اكسر;
        حالة TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            اكسر;
        افتراضي:
            tcc_error("unsupported data processing instruction");
            החזר;
    }

    parse_operand(s1, &op1);
    אם (tok == ',') next();
    parse_operand(s1, &op2);

    אם (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        החזר;
    }
    אם (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        החזר;
    }

    rd = op1.reg;
    rn = op2.reg;

    אם (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        אם (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            החזר;
        }
        אם (op3.type & OP_IM) {
            אם (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            אחרת אם (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            אחרת אם (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            אחרת אם (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            אחרת אם (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            אחרת אם (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            אחרת
                tcc_error("immediate operand not valid for this instruction");
        } אחרת {
            אם (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                החזר;
            }
            rm = op3.reg;
            אם (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                החזר;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } אחרת אם (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } אחרת {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
ساكن فراغ asm_ldst(TCCState *s1, صحيح token)
{
    Operand op1, op2;
    صحيح rt, rn;
    int32_t offset = 0;
    صحيح size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    אם (tok == ',') next();
    parse_operand(s1, &op2);

    אם (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        החזר;
    }
    אם (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        החזר;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    بدل (token) {
        حالة TOK_ASM_ldr:
            אם (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } אחרת אם (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } אחרת אם (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } אחרת {
                tcc_error("ldr requires a w, x, or d register");
                החזר;
            }
            اكسر;
        حالة TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            اكسر;
        حالة TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            اكسر;
        حالة TOK_ASM_str:
            אם (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } אחרת אם (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } אחרת אם (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } אחרת {
                tcc_error("str requires a w, x, or d register");
                החזר;
            }
            اكسر;
        حالة TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            اكسر;
        حالة TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            اكسر;
        افتراضي:
            tcc_error("unsupported load/store instruction");
            החזר;
    }

    אם (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

ساكن فراغ asm_ldst_pair(TCCState *s1, صحيح token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    صحيح size_log2 = 3;

    parse_operand(s1, &op1);
    אם (tok == ',')
        next();
    parse_operand(s1, &op2);
    אם (tok == ',')
        next();
    parse_operand(s1, &op3);

    אם (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        החזר;
    }
    אם (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        החזר;
    }
    אם (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    אם ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        אם (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } אחרת {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } אחרת אם ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        אם (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } אחרת {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } אחרת {
        tcc_error("stp/ldp requires matching x or d registers");
        החזר;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

ساكن فراغ asm_sysreg(TCCState *s1, صحيح token)
{
    Operand op;
    صحيح sysreg;

    אם (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        אם (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        אם (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        החזר;
    }

    sysreg = parse_sysreg_name(tok);
    אם (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    אם (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
ساكن صحيح get_branch_condition(صحيح branch_token)
{
    صحيح cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    بدل (branch_token) {
        حالة TOK_ASM_beq: cond_token = TOK_ASM_eq; اكسر;
        حالة TOK_ASM_bne: cond_token = TOK_ASM_ne; اكسر;
        حالة TOK_ASM_bcs:
        حالة TOK_ASM_bhs: cond_token = TOK_ASM_cs; اكسر;
        حالة TOK_ASM_bcc:
        حالة TOK_ASM_blo: cond_token = TOK_ASM_cc; اكسر;
        حالة TOK_ASM_bmi: cond_token = TOK_ASM_mi; اكسر;
        حالة TOK_ASM_bpl: cond_token = TOK_ASM_pl; اكسر;
        حالة TOK_ASM_bvs: cond_token = TOK_ASM_vs; اكسر;
        حالة TOK_ASM_bvc: cond_token = TOK_ASM_vc; اكسر;
        حالة TOK_ASM_bhi: cond_token = TOK_ASM_hi; اكسر;
        حالة TOK_ASM_bls: cond_token = TOK_ASM_ls; اكسر;
        حالة TOK_ASM_bge: cond_token = TOK_ASM_ge; اكسر;
        حالة TOK_ASM_blt: cond_token = TOK_ASM_lt; اكسر;
        حالة TOK_ASM_bgt: cond_token = TOK_ASM_gt; اكسر;
        حالة TOK_ASM_ble: cond_token = TOK_ASM_le; اكسر;
        افتراضي: החזר -1;
    }

    החזר parse_condition(cond_token);
}

/* Handle branch instructions */
ساكن فراغ asm_branch(TCCState *s1, صحيح token)
{
    Operand op;
    صحيح cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    אם (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        החזר;
    }

    אם (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    אחרת
        parse_expr_operand(s1, &op);

    אם (op.type & OP_IM) {
        sym = op.e.sym;
        אם (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            אם (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } אחרת {
                بدل (token) {
                    حالة TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        اكسر;
                    حالة TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        اكسر;
                    افتراضي:
                        tcc_error("unsupported branch");
                }
            }
        } אחרת {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            אם (cond >= 0) {
                gen_b_cond(cond, offset);
            } אחרת {
                بدل (token) {
                    حالة TOK_ASM_b:
                        gen_b(offset);
                        اكسر;
                    حالة TOK_ASM_bl:
                        gen_bl(offset);
                        اكسر;
                    افتراضي:
                        tcc_error("unsupported branch");
                }
            }
        }
    } אחרת אם (op.type & OP_REG) {
        بدل (token) {
            حالة TOK_ASM_br:
                gen_br(op.reg);
                اكسر;
            حالة TOK_ASM_blr:
                gen_blr(op.reg);
                اكسر;
            حالة TOK_ASM_ret:
                gen_ret(op.reg);
                اكسر;
            افتراضي:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
ساكن فراغ asm_cb(TCCState *s1, صحيح token)
{
    Operand op1, op2;
    صحيح rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    אם (tok == ',') next();
    parse_expr_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    אם (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        אם (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } אחרת {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } אחרת {
        offset = (int32_t)op2.e.v - ind;
        אם (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        אחרת
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
ساكن فراغ asm_move_wide(TCCState *s1, صحيح token)
{
    Operand op1, op2;
    صحيح rd, is_64bit = 1;
    uint16_t imm;
    صحيح shift = 0;

    parse_operand(s1, &op1);
    אם (tok == ',') next();
    parse_operand(s1, &op2);

    אם (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        החזר;
    }
    אם (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        החזר;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    אם ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        החזר;
    }
    imm = op2.e.v;

    אם (tok == ',') {
        next();
        אם (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            החזר;
        }
            next();
            אם (tok == '#') next();
            asm_expr(s1, &op2.e);
        אם (op2.e.sym || !is_valid_movw_shift((صحيح)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            החזר;
        }
            shift = (صحيح)op2.e.v / 16;
        }

    بدل (token) {
        حالة TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            اكسر;
        حالة TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            اكسر;
        حالة TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            اكسر;
        افتراضي:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC فراغ asm_opcode(TCCState *s1, صحيح opcode)
{
    بدل (opcode) {
        حالة TOK_ASM_add:
        حالة TOK_ASM_adds:
        حالة TOK_ASM_sub:
        حالة TOK_ASM_subs:
        حالة TOK_ASM_and:
        حالة TOK_ASM_ands:
        حالة TOK_ASM_orr:
        حالة TOK_ASM_eor:
        حالة TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            اكسر;

        حالة TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            اكسر;

        حالة TOK_ASM_lsl:
        حالة TOK_ASM_lsr:
        حالة TOK_ASM_asr:
        حالة TOK_ASM_ror:
            asm_shift(s1, opcode);
            اكسر;

        حالة TOK_ASM_ldr:
        حالة TOK_ASM_ldrb:
        حالة TOK_ASM_ldrh:
        حالة TOK_ASM_str:
        حالة TOK_ASM_strb:
        حالة TOK_ASM_strh:
            asm_ldst(s1, opcode);
            اكسر;

        حالة TOK_ASM_ldp:
        حالة TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            اكسر;

        حالة TOK_ASM_b:
        حالة TOK_ASM_bl:
        حالة TOK_ASM_br:
        حالة TOK_ASM_blr:
        حالة TOK_ASM_ret:
        حالة TOK_ASM_beq:
        حالة TOK_ASM_bne:
        حالة TOK_ASM_bcs:
        حالة TOK_ASM_bhs:
        حالة TOK_ASM_bcc:
        حالة TOK_ASM_blo:
        حالة TOK_ASM_bmi:
        حالة TOK_ASM_bpl:
        حالة TOK_ASM_bvs:
        حالة TOK_ASM_bvc:
        حالة TOK_ASM_bhi:
        حالة TOK_ASM_bls:
        حالة TOK_ASM_bge:
        حالة TOK_ASM_blt:
        حالة TOK_ASM_bgt:
        حالة TOK_ASM_ble:
            asm_branch(s1, opcode);
            اكسر;

        حالة TOK_ASM_cbz:
        حالة TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            اكسر;

        حالة TOK_ASM_movz:
        حالة TOK_ASM_movn:
        حالة TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            اكسر;

        حالة TOK_ASM_mrs:
        حالة TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            اكسر;

        حالة TOK_ASM_isb:
        حالة TOK_ASM_dsb:
        حالة TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            اكسر;

        حالة TOK_ASM_nop:
            gen_nop();
            اكسر;

        افتراضي:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, عدم));
            اكسر;
    }
}

/* Substitute assembler operand */
ST_FUNC فراغ subst_asm_operand(CString *add_str, SValue *sv, صحيح modifier)
{
    صحيح r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    אם ((r & VT_VALMASK) == VT_CONST) {
        אם ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            החזר;
        }
        אם (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        אם (r & VT_SYM) {
            ثابت حرف *name = get_tok_str(sv->sym->v, عدم);
            אם (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            אם (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            אם ((uint32_t) sv->c.i == 0)
                اذهب no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        אם (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } אחרת אם (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } אחרת {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } אחרת אם ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (صحيح) sv->c.i);
    } אחרת אם (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        אם (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } אחרת {
        /* register case */
        reg = r & VT_VALMASK;
        אם (reg >= VT_CONST)
            tcc_internal_error("");

        אם (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            אם (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            بدل (modifier) {
            حالة 'b':
            حالة 'h':
            حالة 's':
            حالة 'd':
            حالة 'q':
            حالة 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                החזר;
            افتراضي:
                tcc_error("invalid operand modifier for SIMD/FP register");
                החזר;
            }
        }

        /* choose register operand size */
        אם ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        אחרת אם ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        אחרת אם ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        אחרת
            size = 4;

        אם (modifier == 'x') {
            size = 8;
        } אחרת אם (modifier == 'w' || modifier == 'k') {
            size = 4;
        } אחרת אם (modifier == 'b') {
            size = 1;
        } אחרת אם (modifier == 'h') {
            size = 2;
        } אחרת אם (modifier == 'q') {
            size = 8;
        }

        אם (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } אחרת {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC فراغ asm_gen_code(ASMOperand *operands, صحيح nb_operands,
                          صحيح nb_outputs, صحيح is_output,
                          uint8_t *clobber_regs,
                          صحيح out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    صحيح i, reg, saved_count, stack_size, stack_off;
    صحيح saved_regs[12];
    ساكن ثابت uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, حجم(regs_allocated));
    עבור (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        אם (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_count = 0;
    עבור (i = 0; i < حجم(reg_saved) / حجم(reg_saved[0]); i++) {
        reg = reg_saved[i];
        אם (regs_allocated[reg])
            saved_regs[saved_count++] = reg;
    }
    stack_size = ((saved_count + 1) / 2) * 16;

    אם (!is_output) {
        אם (saved_count > 0) {
            gen_sub_imm(31, 31, stack_size, 1, 0);

            עבור (i = stack_off = 0; i < saved_count; ) {
                אם (i + 1 < saved_count) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, stack_off, 3);
                    stack_off += 16;
                    i += 2;
                } אחרת {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 stack_off, 3);
                    i++;
                }
            }
        }

        עבור (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            אם (op->reg >= 0) {
                אם (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } אחרת אם (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } אחרת {
        עבור (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            אם (op->reg >= 0) {
                אם (op->is_memory)
                    استمر;
                אם ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    אם (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } אחרת {
                    store(op->reg, op->vt);
                }
            }
        }

        אם (saved_count > 0) {
            עבור (i = stack_off = 0; i < saved_count; ) {
                אם (i + 1 < saved_count) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, stack_off, 3);
                    stack_off += 16;
                    i += 2;
                } אחרת {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 stack_off, 3);
                    i++;
                }
            }
            gen_add_imm(31, 31, stack_size, 1, 0);
        }
    }
}

ST_FUNC فراغ asm_compute_constraints(ASMOperand *operands,
                                    صحيح nb_operands, صحيح nb_outputs,
                                    ثابت uint8_t *clobber_regs,
                                    صحيح *pout_reg)
{
    ASMOperand *op;
    صحيح sorted_op[MAX_ASM_OPERANDS];
    صحيح i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ثابت حرف *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    עבור (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->input_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    עבור (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        אם (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, عدم);
            אם ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            אם (operands[k].input_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].input_index = i;
            op->priority = 5;
        } אחרת אם ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } אחרת {
            op->priority = constraint_priority(str);
        }
    }

    עבור (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    עבור (i = 0; i < nb_operands - 1; i++) {
        עבור (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            אם (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    עבור (i = 0; i < NB_ASM_REGS; i++) {
        אם (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        אחרת
            regs_allocated[i] = 0;
    }

    עבור (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        אם (op->ref_index >= 0)
            استمر;
        אם (op->input_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } אחרת אם (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } אחרת {
            reg_mask = REG_IN_MASK;
        }
        אם (op->reg >= 0) {
            אם (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            اذهب reg_found;
        }
    try_next:
        c = *str++;
        بدل (c) {
        حالة '=':
            اذهب try_next;
        حالة '+':
            op->is_rw = 1;
        حالة '&':
            אם (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            اذهب try_next;
        حالة 'r':
            עבור (reg = 0; reg < 31; reg++) {
                אם (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    اذهب reg_found;
            }
            اذهب try_next;
        حالة 'w':
        حالة 'f':
            עבור (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                אם (!is_reg_allocated(reg))
                    اذهب reg_found;
            }
            اذهب try_next;
        حالة 'x':
        حالة 'y':
            עבור (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                אם (!is_reg_allocated(reg))
                    اذهب reg_found;
            }
            اذهب try_next;
        حالة 'm':
        حالة 'g':
            אם (j < nb_outputs || c == 'm') {
                אם (!arm64_prepare_memory_operand(op, regs_allocated))
                    اذهب try_next;
            }
            اكسر;
        حالة 'Q':
            אם (!arm64_memory_is_base_only(op->vt))
                اذهب try_next;
            אם (!arm64_prepare_memory_operand(op, regs_allocated))
                اذهب try_next;
            اكسر;
        حالة 'S':
            אם ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                اذهب try_next;
            اكسر;
        حالة 'U':
            אם (str[0] != 'm' || str[1] != 'p')
                اذهب try_next;
            str += 2;
            אם (!arm64_memory_is_pair_suitable(op->vt))
                اذهب try_next;
            אם (!arm64_prepare_memory_operand(op, regs_allocated))
                اذهب try_next;
            اكسر;
        حالة 'i':
            אם (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                اذهب try_next;
            اكسر;
        حالة 'I':
            אם (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                اذهب try_next;
            אם (!is_valid_add_imm(op->vt->c.i))
                اذهب try_next;
            اكسر;
        حالة 'J':
            אם (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                اذهب try_next;
            אם (!is_valid_add_imm(-op->vt->c.i))
                اذهب try_next;
            اكسر;
        حالة 'K':
            אם (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                اذهب try_next;
            אם (!is_valid_logical_imm(op->vt->c.i, 32))
                اذهب try_next;
            اكسر;
        حالة 'L':
            אם (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                اذهب try_next;
            אם (!is_valid_logical_imm(op->vt->c.i, 64))
                اذهب try_next;
            اكسر;
        حالة 'M':
        حالة 'N':
            אם (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                اذهب try_next;
            אם (!is_valid_movw_imm(op->vt->c.i))
                اذهب try_next;
            اكسر;
        حالة 'Z':
            אם (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                اذهب try_next;
            אם (op->vt->c.i != 0)
                اذهب try_next;
            اكسر;
        حالة 'n':
            אם (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                اذهب try_next;
            اكسر;
        افتراضي:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            اكسر;
        }
        אם (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
        استمر;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        אם (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    עבור (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        אם (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            עבור (reg = 0; reg < 31; reg++) {
                אם (!(regs_allocated[reg] & REG_OUT_MASK))
                    اذهب reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            اكسر;
        }
    }
}

/* Handle clobber list */
ST_FUNC فراغ asm_clobber(uint8_t *clobber_regs, ثابت حرف *str)
{
    صحيح reg;

    אם (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        החזר;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    אם (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC صحيح asm_parse_regvar(صحيح t)
{
    החזר arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
