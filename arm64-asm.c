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

ST_FUNC void g(ចំនួនគត់ c);
ST_FUNC void gen_le16(ចំនួនគត់ c);
ST_FUNC void gen_le32(ចំនួនគត់ c);

/*************************************************************/
#បើមិនដូច្នេះ
/*************************************************************/

#define USING_GLOBALS
#include "tcc.h"

/* Register type flags */
#define REG_X     0x01  /* 64-bit general purpose */
#define REG_W     0x02  /* 32-bit general purpose */
#define REG_V     0x04  /* 128-bit SIMD */
#define REG_D     0x08  /* 64-bit FP */
#define REG_S     0x10  /* 32-bit FP */
#define REG_H     0x20  /* 16-bit FP */
#define REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
ga_nanaa {
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

typedef sa_nracanaa Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    ចំនួនគត់ reg_tok;
    ExprValue e;
} Operand;

ga_nanaa {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
static void parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC void g(ចំនួនគត់ c)
{
    ចំនួនគត់ ind1;
    ប្រសិនបើ (nocode_wanted)
        ត្រឡប់;
    ind1 = ind + 1;
    ប្រសិនបើ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC void gen_le16(ចំនួនគត់ c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC void gen_le32(ចំនួនគត់ c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC void gen_expr32(ExprValue *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
static void emit_instr32(uint32_t val)
{
    ប្រសិនបើ (nocode_wanted)
        ត្រឡប់;
    ប្រសិនបើ (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
static ចំនួនគត់ arm64_parse_asm_reg(ចំនួនគត់ t)
{
    /* X registers (64-bit) */
    ប្រសិនបើ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ត្រឡប់ t - TOK_ASM_x0;
    /* W registers (32-bit) */
    ប្រសិនបើ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ត្រឡប់ t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    ប្រសិនបើ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ត្រឡប់ (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    ប្រសិនបើ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ត្រឡប់ (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    ប្រសិនបើ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ត្រឡប់ (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    ប្រសិនបើ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ត្រឡប់ (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    ប្រសិនបើ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ត្រឡប់ (t - TOK_ASM_b0) + 32;
    /* Special registers */
    ប្រសិនបើ (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        ត្រឡប់ 31;  /* SP/ZR encoded as 31 */
    ត្រឡប់ -1;
}

/* Get register type from token */
static uint8_t get_reg_type(ចំនួនគត់ t)
{
    ប្រសិនបើ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ត្រឡប់ REG_X;
    ប្រសិនបើ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ត្រឡប់ REG_W;
    ប្រសិនបើ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ត្រឡប់ REG_V;
    ប្រសិនបើ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ត្រឡប់ REG_D;
    ប្រសិនបើ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ត្រឡប់ REG_S;
    ប្រសិនបើ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ត្រឡប់ REG_H;
    ប្រសិនបើ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ត្រឡប់ REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    ប្រសិនបើ (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        ត្រឡប់ REG_X;
    ប្រសិនបើ (t == TOK_ASM_wzr)
        ត្រឡប់ REG_W;
    ត្រឡប់ REG_X;
}

/* Parse condition code */
static ចំនួនគត់ parse_condition(ចំនួនគត់ t)
{
    switch (t) {
        pak_sa TOK_ASM_eq: ត្រឡប់ 0;
        pak_sa TOK_ASM_ne: ត្រឡប់ 1;
        pak_sa TOK_ASM_cs:
        pak_sa TOK_ASM_hs: ត្រឡប់ 2;
        pak_sa TOK_ASM_cc:
        pak_sa TOK_ASM_lo: ត្រឡប់ 3;
        pak_sa TOK_ASM_mi: ត្រឡប់ 4;
        pak_sa TOK_ASM_pl: ត្រឡប់ 5;
        pak_sa TOK_ASM_vs: ត្រឡប់ 6;
        pak_sa TOK_ASM_vc: ត្រឡប់ 7;
        pak_sa TOK_ASM_hi: ត្រឡប់ 8;
        pak_sa TOK_ASM_ls: ត្រឡប់ 9;
        pak_sa TOK_ASM_ge: ត្រឡប់ 10;
        pak_sa TOK_ASM_lt: ត្រឡប់ 11;
        pak_sa TOK_ASM_gt: ត្រឡប់ 12;
        pak_sa TOK_ASM_le: ត្រឡប់ 13;
        pak_sa TOK_ASM_al: ត្រឡប់ 14;
        default: ត្រឡប់ -1;
    }
}

static ចំនួនគត់ parse_barrier_option_name(ចំនួនគត់ t)
{
    const var_na *name;

    ប្រសិនបើ (t < TOK_IDENT)
        ត្រឡប់ -1;
    name = get_tok_str(t, NULL);
    ប្រសិនបើ (!strcmp(name, "oshld")) ត្រឡប់ 0x1;
    ប្រសិនបើ (!strcmp(name, "oshst")) ត្រឡប់ 0x2;
    ប្រសិនបើ (!strcmp(name, "osh"))   ត្រឡប់ 0x3;
    ប្រសិនបើ (!strcmp(name, "nshld")) ត្រឡប់ 0x5;
    ប្រសិនបើ (!strcmp(name, "nshst")) ត្រឡប់ 0x6;
    ប្រសិនបើ (!strcmp(name, "nsh"))   ត្រឡប់ 0x7;
    ប្រសិនបើ (!strcmp(name, "ishld")) ត្រឡប់ 0x9;
    ប្រសិនបើ (!strcmp(name, "ishst")) ត្រឡប់ 0xA;
    ប្រសិនបើ (!strcmp(name, "ish"))   ត្រឡប់ 0xB;
    ប្រសិនបើ (!strcmp(name, "ld"))    ត្រឡប់ 0xD;
    ប្រសិនបើ (!strcmp(name, "st"))    ត្រឡប់ 0xE;
    ប្រសិនបើ (!strcmp(name, "sy"))    ត្រឡប់ 0xF;
    ត្រឡប់ -1;
}

static ចំនួនគត់ arm64_parse_regvar(ចំនួនគត់ t)
{
    ប្រសិនបើ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ត្រឡប់ t - TOK_ASM_x0;
    ប្រសិនបើ (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        ត្រឡប់ ARM64_FREG_BASE + (t - TOK_ASM_v0);
    ប្រសិនបើ (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        ត្រឡប់ ARM64_FREG_BASE + (t - TOK_ASM_d0);
    ប្រសិនបើ (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        ត្រឡប់ ARM64_FREG_BASE + (t - TOK_ASM_s0);
    ប្រសិនបើ (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        ត្រឡប់ ARM64_FREG_BASE + (t - TOK_ASM_h0);
    ប្រសិនបើ (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        ត្រឡប់ ARM64_FREG_BASE + (t - TOK_ASM_b0);
    ត្រឡប់ -1;
}

/* Parse a single operand */
static void parse_operand(TCCState *s1, Operand *op)
{
    ចំនួនគត់ reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    ប្រសិនបើ (tok == '[') {
        parse_addr_operand(s1, op);
        ត្រឡប់;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    ប្រសិនបើ (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        ត្រឡប់;
    }

    /* Condition code */
    reg = parse_condition(tok);
    ប្រសិនបើ (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        ត្រឡប់;
    }

    /* Immediate or address expression */
    ប្រសិនបើ (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_expr(s1, &op->e);
        op->type = OP_IM;
    } បើមិនដូច្នេះ ប្រសិនបើ (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } បើមិនដូច្នេះ {
        asm_expr(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
static void parse_expr_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    ប្រសិនបើ (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_expr(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
static void parse_addr_operand(TCCState *s1, Operand *op)
{
    ចំនួនគត់ reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = NULL;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    ប្រសិនបើ (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        ត្រឡប់;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    ប្រសិនបើ (tok == ',') {
        next();
        ប្រសិនបើ (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_expr(s1, &op->e);
    }
    skip(']');
    ប្រសិនបើ (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } បើមិនដូច្នេះ ប្រសិនបើ (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        ប្រសិនបើ (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_expr(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
static void gen_mov_with_base(ចំនួនគត់ rd, uint16_t imm, ចំនួនគត់ shift,
                              ចំនួនគត់ is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    ប្រសិនបើ (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

static void gen_movz(ចំនួនគត់ rd, uint16_t imm, ចំនួនគត់ shift, ចំនួនគត់ is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
static void gen_movn(ចំនួនគត់ rd, uint16_t imm, ចំនួនគត់ shift, ចំនួនគត់ is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
static void gen_movk(ចំនួនគត់ rd, uint16_t imm, ចំនួនគត់ shift, ចំនួនគត់ is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
static void gen_add_imm(ចំនួនគត់ rd, ចំនួនគត់ rn, uint32_t imm, ចំនួនគត់ is_64bit, ចំនួនគត់ setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    ប្រសិនបើ (is_64bit) instr |= ARM64_SF(1);
    ប្រសិនបើ (setflags) instr |= ARM64_S(1);

    ប្រសិនបើ (imm <= 0xFFF) {
        imm12 = imm;
    } បើមិនដូច្នេះ ប្រសិនបើ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } បើមិនដូច្នេះ {
        tcc_error("add immediate out of range");
        ត្រឡប់;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
static void gen_sub_imm(ចំនួនគត់ rd, ចំនួនគត់ rn, uint32_t imm, ចំនួនគត់ is_64bit, ចំនួនគត់ setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    ប្រសិនបើ (is_64bit) instr |= ARM64_SF(1);
    ប្រសិនបើ (setflags) instr |= ARM64_S(1);

    ប្រសិនបើ (imm <= 0xFFF) {
        imm12 = imm;
    } បើមិនដូច្នេះ ប្រសិនបើ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } បើមិនដូច្នេះ {
        tcc_error("sub immediate out of range");
        ត្រឡប់;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
static void gen_dp_reg(uint32_t opcode, ចំនួនគត់ rd, ចំនួនគត់ rn, ចំនួនគត់ rm, ចំនួនគត់ is_64bit)
{
    uint32_t instr = opcode;
    ប្រសិនបើ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
static void gen_ldst_imm(uint32_t base_opcode, ចំនួនគត់ rt, ចំនួនគត់ rn,
                         int32_t offset, ចំនួនគត់ size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    ប្រសិនបើ (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        ប្រសិនបើ (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            ត្រឡប់;
        }
    }

    switch (base_opcode) {
    pak_sa ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; bha_nga;
    pak_sa ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; bha_nga;
    pak_sa ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; bha_nga;
    pak_sa ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; bha_nga;
    pak_sa ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; bha_nga;
    pak_sa ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; bha_nga;
    pak_sa ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; bha_nga;
    pak_sa ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; bha_nga;
    pak_sa ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; bha_nga;
    pak_sa ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; bha_nga;
    }

    ប្រសិនបើ (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        ត្រឡប់;
    }

    ប្រសិនបើ (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
static void gen_ldst_pair(uint32_t base_opcode, ចំនួនគត់ rt, ចំនួនគត់ rt2, ចំនួនគត់ rn,
                          int32_t offset, ចំនួនគត់ size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    ប្រសិនបើ (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    ប្រសិនបើ (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
static void gen_b_or_bl(int32_t offset, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    instr |= ARM64_OFFSET26(offset);
    emit_instr32(instr);
}

static void gen_b(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_B);
}

/* Generate BL (branch with link) */
static void gen_bl(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_BL);
}

/* Generate BR (branch to register) */
static void gen_br(ចំនួនគត់ rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
static void gen_blr(ចំនួនគត់ rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
static void gen_ret(ចំនួនគត់ rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
static void gen_b_cond(ចំនួនគត់ cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
static void gen_cbz_or_cbnz(ចំនួនគត់ rt, int32_t offset, ចំនួនគត់ is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    ប្រសិនបើ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

static void gen_cbz(ចំនួនគត់ rt, int32_t offset, ចំនួនគត់ is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
static void gen_cbnz(ចំនួនគត់ rt, int32_t offset, ចំនួនគត់ is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
static void gen_mov_reg(ចំនួនគត់ rd, ចំនួនគត់ rm, ចំនួនគត់ is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    ប្រសិនបើ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

static ចំនួនគត់ arm64_asm_encode_bimm64(uint64_t x)
{
    ចំនួនគត់ neg, rep, pos, len;

    neg = x & 1;
    ប្រសិនបើ (neg)
        x = ~x;
    ប្រសិនបើ (!x)
        ត្រឡប់ -1;

    ប្រសិនបើ (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    បើមិនដូច្នេះ ប្រសិនបើ (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    បើមិនដូច្នេះ ប្រសិនបើ (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    បើមិនដូច្នេះ ប្រសិនបើ (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    បើមិនដូច្នេះ ប្រសិនបើ (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    បើមិនដូច្នេះ
        rep = 64;

    pos = 0;
    ប្រសិនបើ (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    ប្រសិនបើ (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    ប្រសិនបើ (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    ប្រសិនបើ (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    ប្រសិនបើ (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    ប្រសិនបើ (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    ប្រសិនបើ (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    ប្រសិនបើ (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    ប្រសិនបើ (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    ប្រសិនបើ (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    ប្រសិនបើ (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    ប្រសិនបើ (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    ប្រសិនបើ (x)
        ត្រឡប់ -1;
    ប្រសិនបើ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    ត្រឡប់ ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

static void gen_logical_imm(uint32_t opcode, ចំនួនគត់ rd, ចំនួនគត់ rn,
                            uint64_t imm, ចំនួនគត់ is_64bit)
{
    uint32_t instr;
    uint64_t val;
    ចំនួនគត់ enc;

    ប្រសិនបើ (is_64bit)
        val = imm;
    បើមិនដូច្នេះ {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    ប្រសិនបើ (enc < 0) {
        tcc_error("logical immediate out of range");
        ត្រឡប់;
    }

    instr = opcode;
    ប្រសិនបើ (is_64bit)
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
static anta_hstha ចំនួនគត់ constraint_priority(const var_na *str)
{
    ចំនួនគត់ priority, c, pr;

    priority = 0;
    សម្រាប់ (;;) {
        c = *str++;
        ប្រសិនបើ (c == '\0')
            bha_nga;
        switch (c) {
        pak_sa '=':
        pak_sa '+':
        pak_sa '&':
            continue;
        pak_sa 'r':
            pr = 1;
            bha_nga;
        pak_sa 'w':
        pak_sa 'f':
        pak_sa 'x':
        pak_sa 'y':
            pr = 3;
            bha_nga;
        pak_sa 'm':
        pak_sa 'Q':
            pr = 4;
            bha_nga;
        pak_sa 'i':
        pak_sa 'S':
            pr = 5;
            bha_nga;
        pak_sa 'U':
            ប្រសិនបើ (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                bha_nga;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            bha_nga;
        pak_sa 'I':
        pak_sa 'J':
        pak_sa 'K':
        pak_sa 'L':
        pak_sa 'M':
        pak_sa 'N':
        pak_sa 'Z':
            pr = 6;
            bha_nga;
        pak_sa 'n':
            pr = 7;
            bha_nga;
        pak_sa 'g':
            pr = 8;
            bha_nga;
        default:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            bha_nga;
        }
        ប្រសិនបើ (pr > priority)
            priority = pr;
    }
    ត្រឡប់ priority;
}

static const var_na *skip_constraint_modifiers(const var_na *p)
{
    ខណៈពេល (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ត្រឡប់ p;
}

static ចំនួនគត់ is_valid_add_imm(int64_t val)
{
    ត្រឡប់ val >= 0 && val <= 4095;
}

static ចំនួនគត់ is_valid_logical_imm(int64_t val, ចំនួនគត់ bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    ប្រសិនបើ (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    ត្រឡប់ arm64_asm_encode_bimm64(uval) >= 0;
}

static ចំនួនគត់ is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    ប្រសិនបើ (uval <= 0xFFFF)
        ត្រឡប់ 1;
    ប្រសិនបើ (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        ត្រឡប់ 1;
    ប្រសិនបើ (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        ត្រឡប់ 1;
    ប្រសិនបើ ((uval & 0xFFFFFFFF00000000ULL) == 0)
        ត្រឡប់ 1;

    ត្រឡប់ 0;
}

static ចំនួនគត់ is_valid_movw_shift(ចំនួនគត់ shift, ចំនួនគត់ is_64bit)
{
    ប្រសិនបើ (shift < 0 || (shift & 15))
        ត្រឡប់ 0;
    ប្រសិនបើ (shift > (is_64bit ? 48 : 16))
        ត្រឡប់ 0;
    ត្រឡប់ 1;
}

static ចំនួនគត់ arm64_memory_is_base_only(const SValue *sv)
{
    ចំនួនគត់ r;

    r = sv->r;
    ប្រសិនបើ ((r & VT_VALMASK) == VT_CONST)
        ត្រឡប់ 0;
    ប្រសិនបើ ((r & VT_VALMASK) == VT_LOCAL)
        ត្រឡប់ 0;
    ប្រសិនបើ ((r & VT_VALMASK) == VT_LLOCAL)
        ត្រឡប់ 1;
    ប្រសិនបើ (r & VT_LVAL)
        ត្រឡប់ (r & VT_VALMASK) < VT_CONST;
    ត្រឡប់ 0;
}

static ចំនួនគត់ arm64_memory_is_pair_suitable(const SValue *sv)
{
    int64_t offset;

    ប្រសិនបើ (arm64_memory_is_base_only(sv))
        ត្រឡប់ 1;
    ប្រសិនបើ ((sv->r & VT_VALMASK) != VT_LOCAL)
        ត្រឡប់ 0;

    offset = (int64_t)sv->c.i;
    ត្រឡប់ (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

static ចំនួនគត់ arm64_int_reg_is_allocatable(ចំនួនគត់ reg)
{
#ifdef TCC_TARGET_PE
    ត្រឡប់ reg >= TREG_X0 && reg <= TREG_X17;
#បើមិនដូច្នេះ
    ត្រឡប់ reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

static ចំនួនគត់ arm64_memory_needs_address_reg(const SValue *sv)
{
    ចំនួនគត់ r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    ប្រសិនបើ (!(r & VT_LVAL))
        ត្រឡប់ 0;
    switch (r & VT_VALMASK) {
    pak_sa VT_LOCAL:
    pak_sa VT_LLOCAL:
    pak_sa VT_CONST:
        ត្រឡប់ 1;
    }
    ត្រឡប់ 0;
}

static ចំនួនគត់ arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    ចំនួនគត់ reg;

    ប្រសិនបើ (!arm64_memory_needs_address_reg(op->vt))
        ត្រឡប់ 1;

    សម្រាប់ (reg = 0; reg < 31; reg++) {
        ប្រសិនបើ (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            ត្រឡប់ 1;
        }
    }
    ត្រឡប់ 0;
}

static void arm64_load_memory_operand_base(ចំនួនគត់ reg, SValue *sv)
{
    SValue base;
    ចំនួនគត់ rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    ប្រសិនបើ (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } បើមិនដូច្នេះ ប្រសិនបើ (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } បើមិនដូច្នេះ {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

static ចំនួនគត់ operand_is_sp(const Operand *op)
{
    ត្រឡប់ op->reg_tok == TOK_ASM_sp;
}

static ចំនួនគត់ parse_sysreg_name(ចំនួនគត់ t)
{
    const var_na *name;

    ប្រសិនបើ (t < TOK_IDENT)
        ត្រឡប់ -1;
    name = get_tok_str(t, NULL);
    ប្រសិនបើ (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        ត្រឡប់ 0;
    ប្រសិនបើ (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        ត្រឡប់ 1;
    ត្រឡប់ -1;
}

static void gen_mrs(ចំនួនគត់ rt, ចំនួនគត់ sysreg)
{
    uint32_t instr;

    switch (sysreg) {
        pak_sa 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            bha_nga;
        pak_sa 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            bha_nga;
        default:
            tcc_error("unsupported system register");
            ត្រឡប់;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

static void gen_msr(ចំនួនគត់ rt, ចំនួនគត់ sysreg)
{
    uint32_t instr;

    switch (sysreg) {
        pak_sa 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            bha_nga;
        pak_sa 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            bha_nga;
        default:
            tcc_error("unsupported system register");
            ត្រឡប់;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
static void gen_nop(void)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
static void gen_shift(ចំនួនគត់ rd, ចំនួនគត់ rn, ចំនួនគត់ rm_or_imm, ចំនួនគត់ shift_type, ចំនួនគត់ is_imm, ចំនួនគត់ is_64bit)
{
    uint32_t instr;
    ចំនួនគត់ width = is_64bit ? 64 : 32;

    ប្រសិនបើ (is_imm) {
        /* Shift by immediate */
        switch (shift_type) {
            pak_sa 0: /* LSL - UBFM alias */
                ប្រសិនបើ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ត្រឡប់;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                bha_nga;
            pak_sa 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                ប្រសិនបើ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ត្រឡប់;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                bha_nga;
            pak_sa 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                ប្រសិនបើ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ត្រឡប់;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                bha_nga;
            pak_sa 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                ប្រសិនបើ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ត្រឡប់;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                ត្រឡប់;
            default:
                tcc_error("unknown shift type");
                ត្រឡប់;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } បើមិនដូច្នេះ {
        /* Shift by register */
        switch (shift_type) {
            pak_sa 0: /* LSL */
                instr = ARM64_LSL_REG;
                bha_nga;
            pak_sa 1: /* LSR */
                instr = ARM64_LSR_REG;
                bha_nga;
            pak_sa 2: /* ASR */
                instr = ARM64_ASR_REG;
                bha_nga;
            pak_sa 3: /* ROR */
                instr = ARM64_ROR_REG;
                bha_nga;
            default:
                tcc_error("unknown shift type");
                ត្រឡប់;
        }
        ប្រសិនបើ (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
static void asm_shift(TCCState *s1, ចំនួនគត់ token)
{
    Operand op1, op2, op3;
    ចំនួនគត់ rd, rn, shift_amount;
    ចំនួនគត់ shift_type;
    ចំនួនគត់ is_64bit = 1;

    switch (token) {
        pak_sa TOK_ASM_lsl:
            shift_type = 0;
            bha_nga;
        pak_sa TOK_ASM_lsr:
            shift_type = 1;
            bha_nga;
        pak_sa TOK_ASM_asr:
            shift_type = 2;
            bha_nga;
        pak_sa TOK_ASM_ror:
            shift_type = 3;
            bha_nga;
        default:
            tcc_error("unknown shift instruction");
            ត្រឡប់;
    }

    parse_operand(s1, &op1);
    ប្រសិនបើ (tok == ',') next();
    parse_operand(s1, &op2);

    ប្រសិនបើ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ត្រឡប់;
    }
    ប្រសិនបើ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ត្រឡប់;
    }

    rd = op1.reg;
    rn = op2.reg;

    ប្រសិនបើ (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ប្រសិនបើ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ត្រឡប់;
        }
        ប្រសិនបើ (op3.type & OP_REG) {
            ប្រសិនបើ (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ត្រឡប់;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } បើមិនដូច្នេះ ប្រសិនបើ (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } បើមិនដូច្នេះ {
            tcc_error("shift requires immediate or register operand");
        }
    } បើមិនដូច្នេះ {
        tcc_error("shift requires immediate or register operand");
        ត្រឡប់;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
static void gen_barrier(ចំនួនគត់ barrier_type, ចំនួនគត់ option)
{
    uint32_t instr;

    switch (barrier_type) {
        pak_sa 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            bha_nga;
        pak_sa 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            bha_nga;
        pak_sa 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            bha_nga;
        default:
            tcc_error("unknown barrier type");
            ត្រឡប់;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
static void asm_barrier(TCCState *s1, ចំនួនគត់ token)
{
    ចំនួនគត់ barrier_type, option;
    Operand op;

    switch (token) {
        pak_sa TOK_ASM_isb:
            barrier_type = 0;
            bha_nga;
        pak_sa TOK_ASM_dsb:
            barrier_type = 1;
            bha_nga;
        pak_sa TOK_ASM_dmb:
            barrier_type = 2;
            bha_nga;
        default:
            tcc_error("unknown barrier instruction");
            ត្រឡប់;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    ប្រសិនបើ (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        ប្រសិនបើ (option >= 0) {
            next();
        } បើមិនដូច្នេះ {
            parse_operand(s1, &op);
            ប្រសិនបើ (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                ត្រឡប់;
            }
            ប្រសិនបើ (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                ត្រឡប់;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
static void gen_mov_imm(ចំនួនគត់ rd, uint64_t imm, ចំនួនគត់ is_64bit)
{
    uint16_t hw;
    ចំនួនគត់ i, first = 1;

    សម្រាប់ (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        ប្រសិនបើ (hw != 0 || i == 0) {
            ប្រសិនបើ (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } បើមិនដូច្នេះ {
                gen_movk(rd, hw, i, is_64bit);
            }
        } បើមិនដូច្នេះ ប្រសិនបើ (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
static void asm_mov(TCCState *s1)
{
    Operand op1, op2;
    ចំនួនគត់ rd, rn;
    ចំនួនគត់ is_64bit;

    parse_operand(s1, &op1);
    ប្រសិនបើ (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    ប្រសិនបើ (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        ប្រសិនបើ (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            ត្រឡប់;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } បើមិនដូច្នេះ ប្រសិនបើ (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        ប្រសិនបើ (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        បើមិនដូច្នេះ
            gen_mov_reg(rd, rn, is_64bit);
    } បើមិនដូច្នេះ {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
static void asm_data_proc(TCCState *s1, ចំនួនគត់ token)
{
    Operand op1, op2, op3;
    ចំនួនគត់ rd, rn, rm;
    ចំនួនគត់ is_64bit = 1;
    uint32_t opcode;

    switch (token) {
        pak_sa TOK_ASM_add:
        pak_sa TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            bha_nga;
        pak_sa TOK_ASM_sub:
        pak_sa TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            bha_nga;
        pak_sa TOK_ASM_and:
        pak_sa TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            bha_nga;
        pak_sa TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            bha_nga;
        pak_sa TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            bha_nga;
        pak_sa TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            bha_nga;
        default:
            tcc_error("unsupported data processing instruction");
            ត្រឡប់;
    }

    parse_operand(s1, &op1);
    ប្រសិនបើ (tok == ',') next();
    parse_operand(s1, &op2);

    ប្រសិនបើ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ត្រឡប់;
    }
    ប្រសិនបើ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ត្រឡប់;
    }

    rd = op1.reg;
    rn = op2.reg;

    ប្រសិនបើ (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ប្រសិនបើ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ត្រឡប់;
        }
        ប្រសិនបើ (op3.type & OP_IM) {
            ប្រសិនបើ (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            បើមិនដូច្នេះ ប្រសិនបើ (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            បើមិនដូច្នេះ ប្រសិនបើ (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            បើមិនដូច្នេះ ប្រសិនបើ (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            បើមិនដូច្នេះ ប្រសិនបើ (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            បើមិនដូច្នេះ ប្រសិនបើ (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            បើមិនដូច្នេះ
                tcc_error("immediate operand not valid for this instruction");
        } បើមិនដូច្នេះ {
            ប្រសិនបើ (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                ត្រឡប់;
            }
            rm = op3.reg;
            ប្រសិនបើ (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ត្រឡប់;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } បើមិនដូច្នេះ ប្រសិនបើ (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } បើមិនដូច្នេះ {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
static void asm_ldst(TCCState *s1, ចំនួនគត់ token)
{
    Operand op1, op2;
    ចំនួនគត់ rt, rn;
    int32_t offset = 0;
    ចំនួនគត់ size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    ប្រសិនបើ (tok == ',') next();
    parse_operand(s1, &op2);

    ប្រសិនបើ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ត្រឡប់;
    }
    ប្រសិនបើ (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        ត្រឡប់;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    switch (token) {
        pak_sa TOK_ASM_ldr:
            ប្រសិនបើ (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } បើមិនដូច្នេះ ប្រសិនបើ (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } បើមិនដូច្នេះ ប្រសិនបើ (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } បើមិនដូច្នេះ {
                tcc_error("ldr requires a w, x, or d register");
                ត្រឡប់;
            }
            bha_nga;
        pak_sa TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            bha_nga;
        pak_sa TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            bha_nga;
        pak_sa TOK_ASM_str:
            ប្រសិនបើ (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } បើមិនដូច្នេះ ប្រសិនបើ (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } បើមិនដូច្នេះ ប្រសិនបើ (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } បើមិនដូច្នេះ {
                tcc_error("str requires a w, x, or d register");
                ត្រឡប់;
            }
            bha_nga;
        pak_sa TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            bha_nga;
        pak_sa TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            bha_nga;
        default:
            tcc_error("unsupported load/store instruction");
            ត្រឡប់;
    }

    ប្រសិនបើ (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

static void asm_ldst_pair(TCCState *s1, ចំនួនគត់ token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    ចំនួនគត់ size_log2 = 3;

    parse_operand(s1, &op1);
    ប្រសិនបើ (tok == ',')
        next();
    parse_operand(s1, &op2);
    ប្រសិនបើ (tok == ',')
        next();
    parse_operand(s1, &op3);

    ប្រសិនបើ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ត្រឡប់;
    }
    ប្រសិនបើ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ត្រឡប់;
    }
    ប្រសិនបើ (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    ប្រសិនបើ ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        ប្រសិនបើ (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } បើមិនដូច្នេះ {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } បើមិនដូច្នេះ ប្រសិនបើ ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        ប្រសិនបើ (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } បើមិនដូច្នេះ {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } បើមិនដូច្នេះ {
        tcc_error("stp/ldp requires matching x or d registers");
        ត្រឡប់;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

static void asm_sysreg(TCCState *s1, ចំនួនគត់ token)
{
    Operand op;
    ចំនួនគត់ sysreg;

    ប្រសិនបើ (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        ប្រសិនបើ (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        ប្រសិនបើ (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        ត្រឡប់;
    }

    sysreg = parse_sysreg_name(tok);
    ប្រសិនបើ (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    ប្រសិនបើ (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
static ចំនួនគត់ get_branch_condition(ចំនួនគត់ branch_token)
{
    ចំនួនគត់ cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    switch (branch_token) {
        pak_sa TOK_ASM_beq: cond_token = TOK_ASM_eq; bha_nga;
        pak_sa TOK_ASM_bne: cond_token = TOK_ASM_ne; bha_nga;
        pak_sa TOK_ASM_bcs:
        pak_sa TOK_ASM_bhs: cond_token = TOK_ASM_cs; bha_nga;
        pak_sa TOK_ASM_bcc:
        pak_sa TOK_ASM_blo: cond_token = TOK_ASM_cc; bha_nga;
        pak_sa TOK_ASM_bmi: cond_token = TOK_ASM_mi; bha_nga;
        pak_sa TOK_ASM_bpl: cond_token = TOK_ASM_pl; bha_nga;
        pak_sa TOK_ASM_bvs: cond_token = TOK_ASM_vs; bha_nga;
        pak_sa TOK_ASM_bvc: cond_token = TOK_ASM_vc; bha_nga;
        pak_sa TOK_ASM_bhi: cond_token = TOK_ASM_hi; bha_nga;
        pak_sa TOK_ASM_bls: cond_token = TOK_ASM_ls; bha_nga;
        pak_sa TOK_ASM_bge: cond_token = TOK_ASM_ge; bha_nga;
        pak_sa TOK_ASM_blt: cond_token = TOK_ASM_lt; bha_nga;
        pak_sa TOK_ASM_bgt: cond_token = TOK_ASM_gt; bha_nga;
        pak_sa TOK_ASM_ble: cond_token = TOK_ASM_le; bha_nga;
        default: ត្រឡប់ -1;
    }

    ត្រឡប់ parse_condition(cond_token);
}

/* Handle branch instructions */
static void asm_branch(TCCState *s1, ចំនួនគត់ token)
{
    Operand op;
    ចំនួនគត់ cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    ប្រសិនបើ (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        ត្រឡប់;
    }

    ប្រសិនបើ (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    បើមិនដូច្នេះ
        parse_expr_operand(s1, &op);

    ប្រសិនបើ (op.type & OP_IM) {
        sym = op.e.sym;
        ប្រសិនបើ (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            ប្រសិនបើ (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } បើមិនដូច្នេះ {
                switch (token) {
                    pak_sa TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        bha_nga;
                    pak_sa TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        bha_nga;
                    default:
                        tcc_error("unsupported branch");
                }
            }
        } បើមិនដូច្នេះ {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            ប្រសិនបើ (cond >= 0) {
                gen_b_cond(cond, offset);
            } បើមិនដូច្នេះ {
                switch (token) {
                    pak_sa TOK_ASM_b:
                        gen_b(offset);
                        bha_nga;
                    pak_sa TOK_ASM_bl:
                        gen_bl(offset);
                        bha_nga;
                    default:
                        tcc_error("unsupported branch");
                }
            }
        }
    } បើមិនដូច្នេះ ប្រសិនបើ (op.type & OP_REG) {
        switch (token) {
            pak_sa TOK_ASM_br:
                gen_br(op.reg);
                bha_nga;
            pak_sa TOK_ASM_blr:
                gen_blr(op.reg);
                bha_nga;
            pak_sa TOK_ASM_ret:
                gen_ret(op.reg);
                bha_nga;
            default:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
static void asm_cb(TCCState *s1, ចំនួនគត់ token)
{
    Operand op1, op2;
    ចំនួនគត់ rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    ប្រសិនបើ (tok == ',') next();
    parse_expr_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    ប្រសិនបើ (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        ប្រសិនបើ (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } បើមិនដូច្នេះ {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } បើមិនដូច្នេះ {
        offset = (int32_t)op2.e.v - ind;
        ប្រសិនបើ (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        បើមិនដូច្នេះ
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
static void asm_move_wide(TCCState *s1, ចំនួនគត់ token)
{
    Operand op1, op2;
    ចំនួនគត់ rd, is_64bit = 1;
    uint16_t imm;
    ចំនួនគត់ shift = 0;

    parse_operand(s1, &op1);
    ប្រសិនបើ (tok == ',') next();
    parse_operand(s1, &op2);

    ប្រសិនបើ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ត្រឡប់;
    }
    ប្រសិនបើ (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        ត្រឡប់;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    ប្រសិនបើ ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        ត្រឡប់;
    }
    imm = op2.e.v;

    ប្រសិនបើ (tok == ',') {
        next();
        ប្រសិនបើ (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            ត្រឡប់;
        }
            next();
            ប្រសិនបើ (tok == '#') next();
            asm_expr(s1, &op2.e);
        ប្រសិនបើ (op2.e.sym || !is_valid_movw_shift((ចំនួនគត់)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            ត្រឡប់;
        }
            shift = (ចំនួនគត់)op2.e.v / 16;
        }

    switch (token) {
        pak_sa TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            bha_nga;
        pak_sa TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            bha_nga;
        pak_sa TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            bha_nga;
        default:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC void asm_opcode(TCCState *s1, ចំនួនគត់ opcode)
{
    switch (opcode) {
        pak_sa TOK_ASM_add:
        pak_sa TOK_ASM_adds:
        pak_sa TOK_ASM_sub:
        pak_sa TOK_ASM_subs:
        pak_sa TOK_ASM_and:
        pak_sa TOK_ASM_ands:
        pak_sa TOK_ASM_orr:
        pak_sa TOK_ASM_eor:
        pak_sa TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            bha_nga;

        pak_sa TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            bha_nga;

        pak_sa TOK_ASM_lsl:
        pak_sa TOK_ASM_lsr:
        pak_sa TOK_ASM_asr:
        pak_sa TOK_ASM_ror:
            asm_shift(s1, opcode);
            bha_nga;

        pak_sa TOK_ASM_ldr:
        pak_sa TOK_ASM_ldrb:
        pak_sa TOK_ASM_ldrh:
        pak_sa TOK_ASM_str:
        pak_sa TOK_ASM_strb:
        pak_sa TOK_ASM_strh:
            asm_ldst(s1, opcode);
            bha_nga;

        pak_sa TOK_ASM_ldp:
        pak_sa TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            bha_nga;

        pak_sa TOK_ASM_b:
        pak_sa TOK_ASM_bl:
        pak_sa TOK_ASM_br:
        pak_sa TOK_ASM_blr:
        pak_sa TOK_ASM_ret:
        pak_sa TOK_ASM_beq:
        pak_sa TOK_ASM_bne:
        pak_sa TOK_ASM_bcs:
        pak_sa TOK_ASM_bhs:
        pak_sa TOK_ASM_bcc:
        pak_sa TOK_ASM_blo:
        pak_sa TOK_ASM_bmi:
        pak_sa TOK_ASM_bpl:
        pak_sa TOK_ASM_bvs:
        pak_sa TOK_ASM_bvc:
        pak_sa TOK_ASM_bhi:
        pak_sa TOK_ASM_bls:
        pak_sa TOK_ASM_bge:
        pak_sa TOK_ASM_blt:
        pak_sa TOK_ASM_bgt:
        pak_sa TOK_ASM_ble:
            asm_branch(s1, opcode);
            bha_nga;

        pak_sa TOK_ASM_cbz:
        pak_sa TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            bha_nga;

        pak_sa TOK_ASM_movz:
        pak_sa TOK_ASM_movn:
        pak_sa TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            bha_nga;

        pak_sa TOK_ASM_mrs:
        pak_sa TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            bha_nga;

        pak_sa TOK_ASM_isb:
        pak_sa TOK_ASM_dsb:
        pak_sa TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            bha_nga;

        pak_sa TOK_ASM_nop:
            gen_nop();
            bha_nga;

        default:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, NULL));
            bha_nga;
    }
}

/* Substitute assembler operand */
ST_FUNC void subst_asm_operand(CString *add_str, SValue *sv, ចំនួនគត់ modifier)
{
    ចំនួនគត់ r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    ប្រសិនបើ ((r & VT_VALMASK) == VT_CONST) {
        ប្រសិនបើ ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            ត្រឡប់;
        }
        ប្រសិនបើ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        ប្រសិនបើ (r & VT_SYM) {
            const var_na *name = get_tok_str(sv->sym->v, NULL);
            ប្រសិនបើ (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            ប្រសិនបើ (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            ប្រសិនបើ ((uint32_t) sv->c.i == 0)
                goto no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        ប្រសិនបើ (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } បើមិនដូច្នេះ ប្រសិនបើ (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } បើមិនដូច្នេះ {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } បើមិនដូច្នេះ ប្រសិនបើ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (ចំនួនគត់) sv->c.i);
    } បើមិនដូច្នេះ ប្រសិនបើ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ប្រសិនបើ (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } បើមិនដូច្នេះ {
        /* register case */
        reg = r & VT_VALMASK;
        ប្រសិនបើ (reg >= VT_CONST)
            tcc_internal_error("");

        ប្រសិនបើ (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            ប្រសិនបើ (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            switch (modifier) {
            pak_sa 'b':
            pak_sa 'h':
            pak_sa 's':
            pak_sa 'd':
            pak_sa 'q':
            pak_sa 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                ត្រឡប់;
            default:
                tcc_error("invalid operand modifier for SIMD/FP register");
                ត្រឡប់;
            }
        }

        /* choose register operand size */
        ប្រសិនបើ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        បើមិនដូច្នេះ ប្រសិនបើ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        បើមិនដូច្នេះ ប្រសិនបើ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        បើមិនដូច្នេះ
            size = 4;

        ប្រសិនបើ (modifier == 'x') {
            size = 8;
        } បើមិនដូច្នេះ ប្រសិនបើ (modifier == 'w' || modifier == 'k') {
            size = 4;
        } បើមិនដូច្នេះ ប្រសិនបើ (modifier == 'b') {
            size = 1;
        } បើមិនដូច្នេះ ប្រសិនបើ (modifier == 'h') {
            size = 2;
        } បើមិនដូច្នេះ ប្រសិនបើ (modifier == 'q') {
            size = 8;
        }

        ប្រសិនបើ (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } បើមិនដូច្នេះ {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC void asm_gen_code(ASMOperand *operands, ចំនួនគត់ nb_operands,
                          ចំនួនគត់ nb_outputs, ចំនួនគត់ is_output,
                          uint8_t *clobber_regs,
                          ចំនួនគត់ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ចំនួនគត់ i, reg, saved_count, stack_size, stack_off;
    ចំនួនគត់ saved_regs[12];
    static const uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, parimaa_na(regs_allocated));
    សម្រាប់ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ប្រសិនបើ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_count = 0;
    សម្រាប់ (i = 0; i < parimaa_na(reg_saved) / parimaa_na(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ប្រសិនបើ (regs_allocated[reg])
            saved_regs[saved_count++] = reg;
    }
    stack_size = ((saved_count + 1) / 2) * 16;

    ប្រសិនបើ (!is_output) {
        ប្រសិនបើ (saved_count > 0) {
            gen_sub_imm(31, 31, stack_size, 1, 0);

            សម្រាប់ (i = stack_off = 0; i < saved_count; ) {
                ប្រសិនបើ (i + 1 < saved_count) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, stack_off, 3);
                    stack_off += 16;
                    i += 2;
                } បើមិនដូច្នេះ {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 stack_off, 3);
                    i++;
                }
            }
        }

        សម្រាប់ (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ប្រសិនបើ (op->reg >= 0) {
                ប្រសិនបើ (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } បើមិនដូច្នេះ ប្រសិនបើ (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } បើមិនដូច្នេះ {
        សម្រាប់ (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            ប្រសិនបើ (op->reg >= 0) {
                ប្រសិនបើ (op->is_memory)
                    continue;
                ប្រសិនបើ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ប្រសិនបើ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } បើមិនដូច្នេះ {
                    store(op->reg, op->vt);
                }
            }
        }

        ប្រសិនបើ (saved_count > 0) {
            សម្រាប់ (i = stack_off = 0; i < saved_count; ) {
                ប្រសិនបើ (i + 1 < saved_count) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, stack_off, 3);
                    stack_off += 16;
                    i += 2;
                } បើមិនដូច្នេះ {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 stack_off, 3);
                    i++;
                }
            }
            gen_add_imm(31, 31, stack_size, 1, 0);
        }
    }
}

ST_FUNC void asm_compute_constraints(ASMOperand *operands,
                                    ចំនួនគត់ nb_operands, ចំនួនគត់ nb_outputs,
                                    const uint8_t *clobber_regs,
                                    ចំនួនគត់ *pout_reg)
{
    ASMOperand *op;
    ចំនួនគត់ sorted_op[MAX_ASM_OPERANDS];
    ចំនួនគត់ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    const var_na *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    សម្រាប់ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->input_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    សម្រាប់ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ប្រសិនបើ (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, NULL);
            ប្រសិនបើ ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            ប្រសិនបើ (operands[k].input_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].input_index = i;
            op->priority = 5;
        } បើមិនដូច្នេះ ប្រសិនបើ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } បើមិនដូច្នេះ {
            op->priority = constraint_priority(str);
        }
    }

    សម្រាប់ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    សម្រាប់ (i = 0; i < nb_operands - 1; i++) {
        សម្រាប់ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            ប្រសិនបើ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    សម្រាប់ (i = 0; i < NB_ASM_REGS; i++) {
        ប្រសិនបើ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        បើមិនដូច្នេះ
            regs_allocated[i] = 0;
    }

    សម្រាប់ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        ប្រសិនបើ (op->ref_index >= 0)
            continue;
        ប្រសិនបើ (op->input_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } បើមិនដូច្នេះ ប្រសិនបើ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } បើមិនដូច្នេះ {
            reg_mask = REG_IN_MASK;
        }
        ប្រសិនបើ (op->reg >= 0) {
            ប្រសិនបើ (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            goto reg_found;
        }
    try_next:
        c = *str++;
        switch (c) {
        pak_sa '=':
            goto try_next;
        pak_sa '+':
            op->is_rw = 1;
        pak_sa '&':
            ប្រសិនបើ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            goto try_next;
        pak_sa 'r':
            សម្រាប់ (reg = 0; reg < 31; reg++) {
                ប្រសិនបើ (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        pak_sa 'w':
        pak_sa 'f':
            សម្រាប់ (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                ប្រសិនបើ (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        pak_sa 'x':
        pak_sa 'y':
            សម្រាប់ (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                ប្រសិនបើ (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        pak_sa 'm':
        pak_sa 'g':
            ប្រសិនបើ (j < nb_outputs || c == 'm') {
                ប្រសិនបើ (!arm64_prepare_memory_operand(op, regs_allocated))
                    goto try_next;
            }
            bha_nga;
        pak_sa 'Q':
            ប្រសិនបើ (!arm64_memory_is_base_only(op->vt))
                goto try_next;
            ប្រសិនបើ (!arm64_prepare_memory_operand(op, regs_allocated))
                goto try_next;
            bha_nga;
        pak_sa 'S':
            ប្រសិនបើ ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                goto try_next;
            bha_nga;
        pak_sa 'U':
            ប្រសិនបើ (str[0] != 'm' || str[1] != 'p')
                goto try_next;
            str += 2;
            ប្រសិនបើ (!arm64_memory_is_pair_suitable(op->vt))
                goto try_next;
            ប្រសិនបើ (!arm64_prepare_memory_operand(op, regs_allocated))
                goto try_next;
            bha_nga;
        pak_sa 'i':
            ប្រសិនបើ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                goto try_next;
            bha_nga;
        pak_sa 'I':
            ប្រសិនបើ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ប្រសិនបើ (!is_valid_add_imm(op->vt->c.i))
                goto try_next;
            bha_nga;
        pak_sa 'J':
            ប្រសិនបើ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ប្រសិនបើ (!is_valid_add_imm(-op->vt->c.i))
                goto try_next;
            bha_nga;
        pak_sa 'K':
            ប្រសិនបើ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ប្រសិនបើ (!is_valid_logical_imm(op->vt->c.i, 32))
                goto try_next;
            bha_nga;
        pak_sa 'L':
            ប្រសិនបើ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ប្រសិនបើ (!is_valid_logical_imm(op->vt->c.i, 64))
                goto try_next;
            bha_nga;
        pak_sa 'M':
        pak_sa 'N':
            ប្រសិនបើ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ប្រសិនបើ (!is_valid_movw_imm(op->vt->c.i))
                goto try_next;
            bha_nga;
        pak_sa 'Z':
            ប្រសិនបើ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ប្រសិនបើ (op->vt->c.i != 0)
                goto try_next;
            bha_nga;
        pak_sa 'n':
            ប្រសិនបើ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                goto try_next;
            bha_nga;
        default:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            bha_nga;
        }
        ប្រសិនបើ (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
        continue;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        ប្រសិនបើ (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    សម្រាប់ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ប្រសិនបើ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            សម្រាប់ (reg = 0; reg < 31; reg++) {
                ប្រសិនបើ (!(regs_allocated[reg] & REG_OUT_MASK))
                    goto reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            bha_nga;
        }
    }
}

/* Handle clobber list */
ST_FUNC void asm_clobber(uint8_t *clobber_regs, const var_na *str)
{
    ចំនួនគត់ reg;

    ប្រសិនបើ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ត្រឡប់;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    ប្រសិនបើ (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC ចំនួនគត់ asm_parse_regvar(ចំនួនគត់ t)
{
    ត្រឡប់ arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
