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

ST_FUNC void g(puur_naa_nka c);
ST_FUNC void gen_le16(puur_naa_nka c);
ST_FUNC void gen_le32(puur_naa_nka c);

/*************************************************************/
#ᮜᮤᮚ
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
    puur_naa_nka reg_tok;
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
ST_FUNC void g(puur_naa_nka c)
{
    puur_naa_nka ind1;
    ᮚᮦᮔ᮪ (nocode_wanted)
        ᮝᮜᮤ;
    ind1 = ind + 1;
    ᮚᮦᮔ᮪ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC void gen_le16(puur_naa_nka c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC void gen_le32(puur_naa_nka c)
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
    ᮚᮦᮔ᮪ (nocode_wanted)
        ᮝᮜᮤ;
    ᮚᮦᮔ᮪ (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
static puur_naa_nka arm64_parse_asm_reg(puur_naa_nka t)
{
    /* X registers (64-bit) */
    ᮚᮦᮔ᮪ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ᮝᮜᮤ t - TOK_ASM_x0;
    /* W registers (32-bit) */
    ᮚᮦᮔ᮪ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ᮝᮜᮤ t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    ᮚᮦᮔ᮪ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ᮝᮜᮤ (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    ᮚᮦᮔ᮪ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ᮝᮜᮤ (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    ᮚᮦᮔ᮪ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ᮝᮜᮤ (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    ᮚᮦᮔ᮪ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ᮝᮜᮤ (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    ᮚᮦᮔ᮪ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ᮝᮜᮤ (t - TOK_ASM_b0) + 32;
    /* Special registers */
    ᮚᮦᮔ᮪ (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        ᮝᮜᮤ 31;  /* SP/ZR encoded as 31 */
    ᮝᮜᮤ -1;
}

/* Get register type from token */
static uint8_t get_reg_type(puur_naa_nka t)
{
    ᮚᮦᮔ᮪ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ᮝᮜᮤ REG_X;
    ᮚᮦᮔ᮪ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ᮝᮜᮤ REG_W;
    ᮚᮦᮔ᮪ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ᮝᮜᮤ REG_V;
    ᮚᮦᮔ᮪ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ᮝᮜᮤ REG_D;
    ᮚᮦᮔ᮪ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ᮝᮜᮤ REG_S;
    ᮚᮦᮔ᮪ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ᮝᮜᮤ REG_H;
    ᮚᮦᮔ᮪ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ᮝᮜᮤ REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    ᮚᮦᮔ᮪ (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        ᮝᮜᮤ REG_X;
    ᮚᮦᮔ᮪ (t == TOK_ASM_wzr)
        ᮝᮜᮤ REG_W;
    ᮝᮜᮤ REG_X;
}

/* Parse condition code */
static puur_naa_nka parse_condition(puur_naa_nka t)
{
    switch (t) {
        pak_sa TOK_ASM_eq: ᮝᮜᮤ 0;
        pak_sa TOK_ASM_ne: ᮝᮜᮤ 1;
        pak_sa TOK_ASM_cs:
        pak_sa TOK_ASM_hs: ᮝᮜᮤ 2;
        pak_sa TOK_ASM_cc:
        pak_sa TOK_ASM_lo: ᮝᮜᮤ 3;
        pak_sa TOK_ASM_mi: ᮝᮜᮤ 4;
        pak_sa TOK_ASM_pl: ᮝᮜᮤ 5;
        pak_sa TOK_ASM_vs: ᮝᮜᮤ 6;
        pak_sa TOK_ASM_vc: ᮝᮜᮤ 7;
        pak_sa TOK_ASM_hi: ᮝᮜᮤ 8;
        pak_sa TOK_ASM_ls: ᮝᮜᮤ 9;
        pak_sa TOK_ASM_ge: ᮝᮜᮤ 10;
        pak_sa TOK_ASM_lt: ᮝᮜᮤ 11;
        pak_sa TOK_ASM_gt: ᮝᮜᮤ 12;
        pak_sa TOK_ASM_le: ᮝᮜᮤ 13;
        pak_sa TOK_ASM_al: ᮝᮜᮤ 14;
        default: ᮝᮜᮤ -1;
    }
}

static puur_naa_nka parse_barrier_option_name(puur_naa_nka t)
{
    const var_na *name;

    ᮚᮦᮔ᮪ (t < TOK_IDENT)
        ᮝᮜᮤ -1;
    name = get_tok_str(t, NULL);
    ᮚᮦᮔ᮪ (!strcmp(name, "oshld")) ᮝᮜᮤ 0x1;
    ᮚᮦᮔ᮪ (!strcmp(name, "oshst")) ᮝᮜᮤ 0x2;
    ᮚᮦᮔ᮪ (!strcmp(name, "osh"))   ᮝᮜᮤ 0x3;
    ᮚᮦᮔ᮪ (!strcmp(name, "nshld")) ᮝᮜᮤ 0x5;
    ᮚᮦᮔ᮪ (!strcmp(name, "nshst")) ᮝᮜᮤ 0x6;
    ᮚᮦᮔ᮪ (!strcmp(name, "nsh"))   ᮝᮜᮤ 0x7;
    ᮚᮦᮔ᮪ (!strcmp(name, "ishld")) ᮝᮜᮤ 0x9;
    ᮚᮦᮔ᮪ (!strcmp(name, "ishst")) ᮝᮜᮤ 0xA;
    ᮚᮦᮔ᮪ (!strcmp(name, "ish"))   ᮝᮜᮤ 0xB;
    ᮚᮦᮔ᮪ (!strcmp(name, "ld"))    ᮝᮜᮤ 0xD;
    ᮚᮦᮔ᮪ (!strcmp(name, "st"))    ᮝᮜᮤ 0xE;
    ᮚᮦᮔ᮪ (!strcmp(name, "sy"))    ᮝᮜᮤ 0xF;
    ᮝᮜᮤ -1;
}

static puur_naa_nka arm64_parse_regvar(puur_naa_nka t)
{
    ᮚᮦᮔ᮪ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ᮝᮜᮤ t - TOK_ASM_x0;
    ᮚᮦᮔ᮪ (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        ᮝᮜᮤ ARM64_FREG_BASE + (t - TOK_ASM_v0);
    ᮚᮦᮔ᮪ (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        ᮝᮜᮤ ARM64_FREG_BASE + (t - TOK_ASM_d0);
    ᮚᮦᮔ᮪ (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        ᮝᮜᮤ ARM64_FREG_BASE + (t - TOK_ASM_s0);
    ᮚᮦᮔ᮪ (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        ᮝᮜᮤ ARM64_FREG_BASE + (t - TOK_ASM_h0);
    ᮚᮦᮔ᮪ (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        ᮝᮜᮤ ARM64_FREG_BASE + (t - TOK_ASM_b0);
    ᮝᮜᮤ -1;
}

/* Parse a single operand */
static void parse_operand(TCCState *s1, Operand *op)
{
    puur_naa_nka reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    ᮚᮦᮔ᮪ (tok == '[') {
        parse_addr_operand(s1, op);
        ᮝᮜᮤ;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    ᮚᮦᮔ᮪ (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        ᮝᮜᮤ;
    }

    /* Condition code */
    reg = parse_condition(tok);
    ᮚᮦᮔ᮪ (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        ᮝᮜᮤ;
    }

    /* Immediate or address expression */
    ᮚᮦᮔ᮪ (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_expr(s1, &op->e);
        op->type = OP_IM;
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } ᮜᮤᮚ {
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

    ᮚᮦᮔ᮪ (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_expr(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
static void parse_addr_operand(TCCState *s1, Operand *op)
{
    puur_naa_nka reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = NULL;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    ᮚᮦᮔ᮪ (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        ᮝᮜᮤ;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    ᮚᮦᮔ᮪ (tok == ',') {
        next();
        ᮚᮦᮔ᮪ (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_expr(s1, &op->e);
    }
    skip(']');
    ᮚᮦᮔ᮪ (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        ᮚᮦᮔ᮪ (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_expr(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
static void gen_mov_with_base(puur_naa_nka rd, uint16_t imm, puur_naa_nka shift,
                              puur_naa_nka is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    ᮚᮦᮔ᮪ (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

static void gen_movz(puur_naa_nka rd, uint16_t imm, puur_naa_nka shift, puur_naa_nka is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
static void gen_movn(puur_naa_nka rd, uint16_t imm, puur_naa_nka shift, puur_naa_nka is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
static void gen_movk(puur_naa_nka rd, uint16_t imm, puur_naa_nka shift, puur_naa_nka is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
static void gen_add_imm(puur_naa_nka rd, puur_naa_nka rn, uint32_t imm, puur_naa_nka is_64bit, puur_naa_nka setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    ᮚᮦᮔ᮪ (is_64bit) instr |= ARM64_SF(1);
    ᮚᮦᮔ᮪ (setflags) instr |= ARM64_S(1);

    ᮚᮦᮔ᮪ (imm <= 0xFFF) {
        imm12 = imm;
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } ᮜᮤᮚ {
        tcc_error("add immediate out of range");
        ᮝᮜᮤ;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
static void gen_sub_imm(puur_naa_nka rd, puur_naa_nka rn, uint32_t imm, puur_naa_nka is_64bit, puur_naa_nka setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    ᮚᮦᮔ᮪ (is_64bit) instr |= ARM64_SF(1);
    ᮚᮦᮔ᮪ (setflags) instr |= ARM64_S(1);

    ᮚᮦᮔ᮪ (imm <= 0xFFF) {
        imm12 = imm;
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } ᮜᮤᮚ {
        tcc_error("sub immediate out of range");
        ᮝᮜᮤ;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
static void gen_dp_reg(uint32_t opcode, puur_naa_nka rd, puur_naa_nka rn, puur_naa_nka rm, puur_naa_nka is_64bit)
{
    uint32_t instr = opcode;
    ᮚᮦᮔ᮪ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
static void gen_ldst_imm(uint32_t base_opcode, puur_naa_nka rt, puur_naa_nka rn,
                         int32_t offset, puur_naa_nka size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    ᮚᮦᮔ᮪ (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        ᮚᮦᮔ᮪ (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            ᮝᮜᮤ;
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

    ᮚᮦᮔ᮪ (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        ᮝᮜᮤ;
    }

    ᮚᮦᮔ᮪ (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
static void gen_ldst_pair(uint32_t base_opcode, puur_naa_nka rt, puur_naa_nka rt2, puur_naa_nka rn,
                          int32_t offset, puur_naa_nka size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    ᮚᮦᮔ᮪ (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    ᮚᮦᮔ᮪ (imm7 < -64 || imm7 > 63)
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
static void gen_br(puur_naa_nka rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
static void gen_blr(puur_naa_nka rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
static void gen_ret(puur_naa_nka rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
static void gen_b_cond(puur_naa_nka cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
static void gen_cbz_or_cbnz(puur_naa_nka rt, int32_t offset, puur_naa_nka is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    ᮚᮦᮔ᮪ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

static void gen_cbz(puur_naa_nka rt, int32_t offset, puur_naa_nka is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
static void gen_cbnz(puur_naa_nka rt, int32_t offset, puur_naa_nka is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
static void gen_mov_reg(puur_naa_nka rd, puur_naa_nka rm, puur_naa_nka is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    ᮚᮦᮔ᮪ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

static puur_naa_nka arm64_asm_encode_bimm64(uint64_t x)
{
    puur_naa_nka neg, rep, pos, len;

    neg = x & 1;
    ᮚᮦᮔ᮪ (neg)
        x = ~x;
    ᮚᮦᮔ᮪ (!x)
        ᮝᮜᮤ -1;

    ᮚᮦᮔ᮪ (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    ᮜᮤᮚ ᮚᮦᮔ᮪ (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    ᮜᮤᮚ ᮚᮦᮔ᮪ (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    ᮜᮤᮚ ᮚᮦᮔ᮪ (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    ᮜᮤᮚ ᮚᮦᮔ᮪ (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    ᮜᮤᮚ
        rep = 64;

    pos = 0;
    ᮚᮦᮔ᮪ (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    ᮚᮦᮔ᮪ (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    ᮚᮦᮔ᮪ (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    ᮚᮦᮔ᮪ (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    ᮚᮦᮔ᮪ (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    ᮚᮦᮔ᮪ (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    ᮚᮦᮔ᮪ (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    ᮚᮦᮔ᮪ (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    ᮚᮦᮔ᮪ (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    ᮚᮦᮔ᮪ (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    ᮚᮦᮔ᮪ (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    ᮚᮦᮔ᮪ (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    ᮚᮦᮔ᮪ (x)
        ᮝᮜᮤ -1;
    ᮚᮦᮔ᮪ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    ᮝᮜᮤ ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

static void gen_logical_imm(uint32_t opcode, puur_naa_nka rd, puur_naa_nka rn,
                            uint64_t imm, puur_naa_nka is_64bit)
{
    uint32_t instr;
    uint64_t val;
    puur_naa_nka enc;

    ᮚᮦᮔ᮪ (is_64bit)
        val = imm;
    ᮜᮤᮚ {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    ᮚᮦᮔ᮪ (enc < 0) {
        tcc_error("logical immediate out of range");
        ᮝᮜᮤ;
    }

    instr = opcode;
    ᮚᮦᮔ᮪ (is_64bit)
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
static anta_hstha puur_naa_nka constraint_priority(const var_na *str)
{
    puur_naa_nka priority, c, pr;

    priority = 0;
    for (;;) {
        c = *str++;
        ᮚᮦᮔ᮪ (c == '\0')
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
            ᮚᮦᮔ᮪ (str[0] == 'm' && str[1] == 'p') {
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
        ᮚᮦᮔ᮪ (pr > priority)
            priority = pr;
    }
    ᮝᮜᮤ priority;
}

static const var_na *skip_constraint_modifiers(const var_na *p)
{
    ᮞᮨᮓᮨᮜ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ᮝᮜᮤ p;
}

static puur_naa_nka is_valid_add_imm(int64_t val)
{
    ᮝᮜᮤ val >= 0 && val <= 4095;
}

static puur_naa_nka is_valid_logical_imm(int64_t val, puur_naa_nka bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    ᮚᮦᮔ᮪ (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    ᮝᮜᮤ arm64_asm_encode_bimm64(uval) >= 0;
}

static puur_naa_nka is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    ᮚᮦᮔ᮪ (uval <= 0xFFFF)
        ᮝᮜᮤ 1;
    ᮚᮦᮔ᮪ (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        ᮝᮜᮤ 1;
    ᮚᮦᮔ᮪ (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        ᮝᮜᮤ 1;
    ᮚᮦᮔ᮪ ((uval & 0xFFFFFFFF00000000ULL) == 0)
        ᮝᮜᮤ 1;

    ᮝᮜᮤ 0;
}

static puur_naa_nka is_valid_movw_shift(puur_naa_nka shift, puur_naa_nka is_64bit)
{
    ᮚᮦᮔ᮪ (shift < 0 || (shift & 15))
        ᮝᮜᮤ 0;
    ᮚᮦᮔ᮪ (shift > (is_64bit ? 48 : 16))
        ᮝᮜᮤ 0;
    ᮝᮜᮤ 1;
}

static puur_naa_nka arm64_memory_is_base_only(const SValue *sv)
{
    puur_naa_nka r;

    r = sv->r;
    ᮚᮦᮔ᮪ ((r & VT_VALMASK) == VT_CONST)
        ᮝᮜᮤ 0;
    ᮚᮦᮔ᮪ ((r & VT_VALMASK) == VT_LOCAL)
        ᮝᮜᮤ 0;
    ᮚᮦᮔ᮪ ((r & VT_VALMASK) == VT_LLOCAL)
        ᮝᮜᮤ 1;
    ᮚᮦᮔ᮪ (r & VT_LVAL)
        ᮝᮜᮤ (r & VT_VALMASK) < VT_CONST;
    ᮝᮜᮤ 0;
}

static puur_naa_nka arm64_memory_is_pair_suitable(const SValue *sv)
{
    int64_t offset;

    ᮚᮦᮔ᮪ (arm64_memory_is_base_only(sv))
        ᮝᮜᮤ 1;
    ᮚᮦᮔ᮪ ((sv->r & VT_VALMASK) != VT_LOCAL)
        ᮝᮜᮤ 0;

    offset = (int64_t)sv->c.i;
    ᮝᮜᮤ (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

static puur_naa_nka arm64_int_reg_is_allocatable(puur_naa_nka reg)
{
#ifdef TCC_TARGET_PE
    ᮝᮜᮤ reg >= TREG_X0 && reg <= TREG_X17;
#ᮜᮤᮚ
    ᮝᮜᮤ reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

static puur_naa_nka arm64_memory_needs_address_reg(const SValue *sv)
{
    puur_naa_nka r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    ᮚᮦᮔ᮪ (!(r & VT_LVAL))
        ᮝᮜᮤ 0;
    switch (r & VT_VALMASK) {
    pak_sa VT_LOCAL:
    pak_sa VT_LLOCAL:
    pak_sa VT_CONST:
        ᮝᮜᮤ 1;
    }
    ᮝᮜᮤ 0;
}

static puur_naa_nka arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    puur_naa_nka reg;

    ᮚᮦᮔ᮪ (!arm64_memory_needs_address_reg(op->vt))
        ᮝᮜᮤ 1;

    for (reg = 0; reg < 31; reg++) {
        ᮚᮦᮔ᮪ (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            ᮝᮜᮤ 1;
        }
    }
    ᮝᮜᮤ 0;
}

static void arm64_load_memory_operand_base(puur_naa_nka reg, SValue *sv)
{
    SValue base;
    puur_naa_nka rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    ᮚᮦᮔ᮪ (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } ᮜᮤᮚ {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

static puur_naa_nka operand_is_sp(const Operand *op)
{
    ᮝᮜᮤ op->reg_tok == TOK_ASM_sp;
}

static puur_naa_nka parse_sysreg_name(puur_naa_nka t)
{
    const var_na *name;

    ᮚᮦᮔ᮪ (t < TOK_IDENT)
        ᮝᮜᮤ -1;
    name = get_tok_str(t, NULL);
    ᮚᮦᮔ᮪ (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        ᮝᮜᮤ 0;
    ᮚᮦᮔ᮪ (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        ᮝᮜᮤ 1;
    ᮝᮜᮤ -1;
}

static void gen_mrs(puur_naa_nka rt, puur_naa_nka sysreg)
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
            ᮝᮜᮤ;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

static void gen_msr(puur_naa_nka rt, puur_naa_nka sysreg)
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
            ᮝᮜᮤ;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
static void gen_nop(void)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
static void gen_shift(puur_naa_nka rd, puur_naa_nka rn, puur_naa_nka rm_or_imm, puur_naa_nka shift_type, puur_naa_nka is_imm, puur_naa_nka is_64bit)
{
    uint32_t instr;
    puur_naa_nka width = is_64bit ? 64 : 32;

    ᮚᮦᮔ᮪ (is_imm) {
        /* Shift by immediate */
        switch (shift_type) {
            pak_sa 0: /* LSL - UBFM alias */
                ᮚᮦᮔ᮪ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ᮝᮜᮤ;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                bha_nga;
            pak_sa 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                ᮚᮦᮔ᮪ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ᮝᮜᮤ;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                bha_nga;
            pak_sa 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                ᮚᮦᮔ᮪ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ᮝᮜᮤ;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                bha_nga;
            pak_sa 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                ᮚᮦᮔ᮪ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ᮝᮜᮤ;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                ᮝᮜᮤ;
            default:
                tcc_error("unknown shift type");
                ᮝᮜᮤ;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } ᮜᮤᮚ {
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
                ᮝᮜᮤ;
        }
        ᮚᮦᮔ᮪ (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
static void asm_shift(TCCState *s1, puur_naa_nka token)
{
    Operand op1, op2, op3;
    puur_naa_nka rd, rn, shift_amount;
    puur_naa_nka shift_type;
    puur_naa_nka is_64bit = 1;

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
            ᮝᮜᮤ;
    }

    parse_operand(s1, &op1);
    ᮚᮦᮔ᮪ (tok == ',') next();
    parse_operand(s1, &op2);

    ᮚᮦᮔ᮪ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ᮝᮜᮤ;
    }
    ᮚᮦᮔ᮪ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ᮝᮜᮤ;
    }

    rd = op1.reg;
    rn = op2.reg;

    ᮚᮦᮔ᮪ (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ᮚᮦᮔ᮪ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ᮝᮜᮤ;
        }
        ᮚᮦᮔ᮪ (op3.type & OP_REG) {
            ᮚᮦᮔ᮪ (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ᮝᮜᮤ;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } ᮜᮤᮚ ᮚᮦᮔ᮪ (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } ᮜᮤᮚ {
            tcc_error("shift requires immediate or register operand");
        }
    } ᮜᮤᮚ {
        tcc_error("shift requires immediate or register operand");
        ᮝᮜᮤ;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
static void gen_barrier(puur_naa_nka barrier_type, puur_naa_nka option)
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
            ᮝᮜᮤ;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
static void asm_barrier(TCCState *s1, puur_naa_nka token)
{
    puur_naa_nka barrier_type, option;
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
            ᮝᮜᮤ;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    ᮚᮦᮔ᮪ (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        ᮚᮦᮔ᮪ (option >= 0) {
            next();
        } ᮜᮤᮚ {
            parse_operand(s1, &op);
            ᮚᮦᮔ᮪ (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                ᮝᮜᮤ;
            }
            ᮚᮦᮔ᮪ (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                ᮝᮜᮤ;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
static void gen_mov_imm(puur_naa_nka rd, uint64_t imm, puur_naa_nka is_64bit)
{
    uint16_t hw;
    puur_naa_nka i, first = 1;

    for (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        ᮚᮦᮔ᮪ (hw != 0 || i == 0) {
            ᮚᮦᮔ᮪ (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } ᮜᮤᮚ {
                gen_movk(rd, hw, i, is_64bit);
            }
        } ᮜᮤᮚ ᮚᮦᮔ᮪ (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
static void asm_mov(TCCState *s1)
{
    Operand op1, op2;
    puur_naa_nka rd, rn;
    puur_naa_nka is_64bit;

    parse_operand(s1, &op1);
    ᮚᮦᮔ᮪ (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    ᮚᮦᮔ᮪ (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        ᮚᮦᮔ᮪ (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            ᮝᮜᮤ;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        ᮚᮦᮔ᮪ (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        ᮜᮤᮚ
            gen_mov_reg(rd, rn, is_64bit);
    } ᮜᮤᮚ {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
static void asm_data_proc(TCCState *s1, puur_naa_nka token)
{
    Operand op1, op2, op3;
    puur_naa_nka rd, rn, rm;
    puur_naa_nka is_64bit = 1;
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
            ᮝᮜᮤ;
    }

    parse_operand(s1, &op1);
    ᮚᮦᮔ᮪ (tok == ',') next();
    parse_operand(s1, &op2);

    ᮚᮦᮔ᮪ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ᮝᮜᮤ;
    }
    ᮚᮦᮔ᮪ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ᮝᮜᮤ;
    }

    rd = op1.reg;
    rn = op2.reg;

    ᮚᮦᮔ᮪ (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ᮚᮦᮔ᮪ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ᮝᮜᮤ;
        }
        ᮚᮦᮔ᮪ (op3.type & OP_IM) {
            ᮚᮦᮔ᮪ (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            ᮜᮤᮚ ᮚᮦᮔ᮪ (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            ᮜᮤᮚ ᮚᮦᮔ᮪ (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            ᮜᮤᮚ ᮚᮦᮔ᮪ (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            ᮜᮤᮚ ᮚᮦᮔ᮪ (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            ᮜᮤᮚ ᮚᮦᮔ᮪ (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            ᮜᮤᮚ
                tcc_error("immediate operand not valid for this instruction");
        } ᮜᮤᮚ {
            ᮚᮦᮔ᮪ (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                ᮝᮜᮤ;
            }
            rm = op3.reg;
            ᮚᮦᮔ᮪ (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ᮝᮜᮤ;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } ᮜᮤᮚ {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
static void asm_ldst(TCCState *s1, puur_naa_nka token)
{
    Operand op1, op2;
    puur_naa_nka rt, rn;
    int32_t offset = 0;
    puur_naa_nka size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    ᮚᮦᮔ᮪ (tok == ',') next();
    parse_operand(s1, &op2);

    ᮚᮦᮔ᮪ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ᮝᮜᮤ;
    }
    ᮚᮦᮔ᮪ (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        ᮝᮜᮤ;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    switch (token) {
        pak_sa TOK_ASM_ldr:
            ᮚᮦᮔ᮪ (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } ᮜᮤᮚ ᮚᮦᮔ᮪ (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } ᮜᮤᮚ ᮚᮦᮔ᮪ (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } ᮜᮤᮚ {
                tcc_error("ldr requires a w, x, or d register");
                ᮝᮜᮤ;
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
            ᮚᮦᮔ᮪ (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } ᮜᮤᮚ ᮚᮦᮔ᮪ (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } ᮜᮤᮚ ᮚᮦᮔ᮪ (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } ᮜᮤᮚ {
                tcc_error("str requires a w, x, or d register");
                ᮝᮜᮤ;
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
            ᮝᮜᮤ;
    }

    ᮚᮦᮔ᮪ (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

static void asm_ldst_pair(TCCState *s1, puur_naa_nka token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    puur_naa_nka size_log2 = 3;

    parse_operand(s1, &op1);
    ᮚᮦᮔ᮪ (tok == ',')
        next();
    parse_operand(s1, &op2);
    ᮚᮦᮔ᮪ (tok == ',')
        next();
    parse_operand(s1, &op3);

    ᮚᮦᮔ᮪ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ᮝᮜᮤ;
    }
    ᮚᮦᮔ᮪ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ᮝᮜᮤ;
    }
    ᮚᮦᮔ᮪ (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    ᮚᮦᮔ᮪ ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        ᮚᮦᮔ᮪ (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } ᮜᮤᮚ {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } ᮜᮤᮚ ᮚᮦᮔ᮪ ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        ᮚᮦᮔ᮪ (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } ᮜᮤᮚ {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } ᮜᮤᮚ {
        tcc_error("stp/ldp requires matching x or d registers");
        ᮝᮜᮤ;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

static void asm_sysreg(TCCState *s1, puur_naa_nka token)
{
    Operand op;
    puur_naa_nka sysreg;

    ᮚᮦᮔ᮪ (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        ᮚᮦᮔ᮪ (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        ᮚᮦᮔ᮪ (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        ᮝᮜᮤ;
    }

    sysreg = parse_sysreg_name(tok);
    ᮚᮦᮔ᮪ (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    ᮚᮦᮔ᮪ (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
static puur_naa_nka get_branch_condition(puur_naa_nka branch_token)
{
    puur_naa_nka cond_token;

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
        default: ᮝᮜᮤ -1;
    }

    ᮝᮜᮤ parse_condition(cond_token);
}

/* Handle branch instructions */
static void asm_branch(TCCState *s1, puur_naa_nka token)
{
    Operand op;
    puur_naa_nka cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    ᮚᮦᮔ᮪ (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        ᮝᮜᮤ;
    }

    ᮚᮦᮔ᮪ (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    ᮜᮤᮚ
        parse_expr_operand(s1, &op);

    ᮚᮦᮔ᮪ (op.type & OP_IM) {
        sym = op.e.sym;
        ᮚᮦᮔ᮪ (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            ᮚᮦᮔ᮪ (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } ᮜᮤᮚ {
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
        } ᮜᮤᮚ {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            ᮚᮦᮔ᮪ (cond >= 0) {
                gen_b_cond(cond, offset);
            } ᮜᮤᮚ {
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
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (op.type & OP_REG) {
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
static void asm_cb(TCCState *s1, puur_naa_nka token)
{
    Operand op1, op2;
    puur_naa_nka rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    ᮚᮦᮔ᮪ (tok == ',') next();
    parse_expr_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    ᮚᮦᮔ᮪ (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        ᮚᮦᮔ᮪ (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } ᮜᮤᮚ {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } ᮜᮤᮚ {
        offset = (int32_t)op2.e.v - ind;
        ᮚᮦᮔ᮪ (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        ᮜᮤᮚ
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
static void asm_move_wide(TCCState *s1, puur_naa_nka token)
{
    Operand op1, op2;
    puur_naa_nka rd, is_64bit = 1;
    uint16_t imm;
    puur_naa_nka shift = 0;

    parse_operand(s1, &op1);
    ᮚᮦᮔ᮪ (tok == ',') next();
    parse_operand(s1, &op2);

    ᮚᮦᮔ᮪ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ᮝᮜᮤ;
    }
    ᮚᮦᮔ᮪ (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        ᮝᮜᮤ;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    ᮚᮦᮔ᮪ ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        ᮝᮜᮤ;
    }
    imm = op2.e.v;

    ᮚᮦᮔ᮪ (tok == ',') {
        next();
        ᮚᮦᮔ᮪ (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            ᮝᮜᮤ;
        }
            next();
            ᮚᮦᮔ᮪ (tok == '#') next();
            asm_expr(s1, &op2.e);
        ᮚᮦᮔ᮪ (op2.e.sym || !is_valid_movw_shift((puur_naa_nka)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            ᮝᮜᮤ;
        }
            shift = (puur_naa_nka)op2.e.v / 16;
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
ST_FUNC void asm_opcode(TCCState *s1, puur_naa_nka opcode)
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
ST_FUNC void subst_asm_operand(CString *add_str, SValue *sv, puur_naa_nka modifier)
{
    puur_naa_nka r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    ᮚᮦᮔ᮪ ((r & VT_VALMASK) == VT_CONST) {
        ᮚᮦᮔ᮪ ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            ᮝᮜᮤ;
        }
        ᮚᮦᮔ᮪ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        ᮚᮦᮔ᮪ (r & VT_SYM) {
            const var_na *name = get_tok_str(sv->sym->v, NULL);
            ᮚᮦᮔ᮪ (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            ᮚᮦᮔ᮪ (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            ᮚᮦᮔ᮪ ((uint32_t) sv->c.i == 0)
                goto no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        ᮚᮦᮔ᮪ (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } ᮜᮤᮚ ᮚᮦᮔ᮪ (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } ᮜᮤᮚ {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } ᮜᮤᮚ ᮚᮦᮔ᮪ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (puur_naa_nka) sv->c.i);
    } ᮜᮤᮚ ᮚᮦᮔ᮪ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ᮚᮦᮔ᮪ (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } ᮜᮤᮚ {
        /* register case */
        reg = r & VT_VALMASK;
        ᮚᮦᮔ᮪ (reg >= VT_CONST)
            tcc_internal_error("");

        ᮚᮦᮔ᮪ (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            ᮚᮦᮔ᮪ (modifier == 0)
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
                ᮝᮜᮤ;
            default:
                tcc_error("invalid operand modifier for SIMD/FP register");
                ᮝᮜᮤ;
            }
        }

        /* choose register operand size */
        ᮚᮦᮔ᮪ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        ᮜᮤᮚ ᮚᮦᮔ᮪ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        ᮜᮤᮚ ᮚᮦᮔ᮪ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        ᮜᮤᮚ
            size = 4;

        ᮚᮦᮔ᮪ (modifier == 'x') {
            size = 8;
        } ᮜᮤᮚ ᮚᮦᮔ᮪ (modifier == 'w' || modifier == 'k') {
            size = 4;
        } ᮜᮤᮚ ᮚᮦᮔ᮪ (modifier == 'b') {
            size = 1;
        } ᮜᮤᮚ ᮚᮦᮔ᮪ (modifier == 'h') {
            size = 2;
        } ᮜᮤᮚ ᮚᮦᮔ᮪ (modifier == 'q') {
            size = 8;
        }

        ᮚᮦᮔ᮪ (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } ᮜᮤᮚ {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC void asm_gen_code(ASMOperand *operands, puur_naa_nka nb_operands,
                          puur_naa_nka nb_outputs, puur_naa_nka is_output,
                          uint8_t *clobber_regs,
                          puur_naa_nka out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    puur_naa_nka i, reg, saved_count, stack_size, stack_off;
    puur_naa_nka saved_regs[12];
    static const uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, parimaa_na(regs_allocated));
    for (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ᮚᮦᮔ᮪ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_count = 0;
    for (i = 0; i < parimaa_na(reg_saved) / parimaa_na(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ᮚᮦᮔ᮪ (regs_allocated[reg])
            saved_regs[saved_count++] = reg;
    }
    stack_size = ((saved_count + 1) / 2) * 16;

    ᮚᮦᮔ᮪ (!is_output) {
        ᮚᮦᮔ᮪ (saved_count > 0) {
            gen_sub_imm(31, 31, stack_size, 1, 0);

            for (i = stack_off = 0; i < saved_count; ) {
                ᮚᮦᮔ᮪ (i + 1 < saved_count) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, stack_off, 3);
                    stack_off += 16;
                    i += 2;
                } ᮜᮤᮚ {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 stack_off, 3);
                    i++;
                }
            }
        }

        for (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ᮚᮦᮔ᮪ (op->reg >= 0) {
                ᮚᮦᮔ᮪ (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } ᮜᮤᮚ ᮚᮦᮔ᮪ (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } ᮜᮤᮚ {
        for (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            ᮚᮦᮔ᮪ (op->reg >= 0) {
                ᮚᮦᮔ᮪ (op->is_memory)
                    continue;
                ᮚᮦᮔ᮪ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ᮚᮦᮔ᮪ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } ᮜᮤᮚ {
                    store(op->reg, op->vt);
                }
            }
        }

        ᮚᮦᮔ᮪ (saved_count > 0) {
            for (i = stack_off = 0; i < saved_count; ) {
                ᮚᮦᮔ᮪ (i + 1 < saved_count) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, stack_off, 3);
                    stack_off += 16;
                    i += 2;
                } ᮜᮤᮚ {
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
                                    puur_naa_nka nb_operands, puur_naa_nka nb_outputs,
                                    const uint8_t *clobber_regs,
                                    puur_naa_nka *pout_reg)
{
    ASMOperand *op;
    puur_naa_nka sorted_op[MAX_ASM_OPERANDS];
    puur_naa_nka i, j, k, p1, p2, tmp, reg, c, reg_mask;
    const var_na *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    for (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->input_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    for (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ᮚᮦᮔ᮪ (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, NULL);
            ᮚᮦᮔ᮪ ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            ᮚᮦᮔ᮪ (operands[k].input_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].input_index = i;
            op->priority = 5;
        } ᮜᮤᮚ ᮚᮦᮔ᮪ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } ᮜᮤᮚ {
            op->priority = constraint_priority(str);
        }
    }

    for (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    for (i = 0; i < nb_operands - 1; i++) {
        for (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            ᮚᮦᮔ᮪ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    for (i = 0; i < NB_ASM_REGS; i++) {
        ᮚᮦᮔ᮪ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        ᮜᮤᮚ
            regs_allocated[i] = 0;
    }

    for (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        ᮚᮦᮔ᮪ (op->ref_index >= 0)
            continue;
        ᮚᮦᮔ᮪ (op->input_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } ᮜᮤᮚ ᮚᮦᮔ᮪ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } ᮜᮤᮚ {
            reg_mask = REG_IN_MASK;
        }
        ᮚᮦᮔ᮪ (op->reg >= 0) {
            ᮚᮦᮔ᮪ (is_reg_allocated(op->reg))
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
            ᮚᮦᮔ᮪ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            goto try_next;
        pak_sa 'r':
            for (reg = 0; reg < 31; reg++) {
                ᮚᮦᮔ᮪ (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        pak_sa 'w':
        pak_sa 'f':
            for (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                ᮚᮦᮔ᮪ (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        pak_sa 'x':
        pak_sa 'y':
            for (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                ᮚᮦᮔ᮪ (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        pak_sa 'm':
        pak_sa 'g':
            ᮚᮦᮔ᮪ (j < nb_outputs || c == 'm') {
                ᮚᮦᮔ᮪ (!arm64_prepare_memory_operand(op, regs_allocated))
                    goto try_next;
            }
            bha_nga;
        pak_sa 'Q':
            ᮚᮦᮔ᮪ (!arm64_memory_is_base_only(op->vt))
                goto try_next;
            ᮚᮦᮔ᮪ (!arm64_prepare_memory_operand(op, regs_allocated))
                goto try_next;
            bha_nga;
        pak_sa 'S':
            ᮚᮦᮔ᮪ ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                goto try_next;
            bha_nga;
        pak_sa 'U':
            ᮚᮦᮔ᮪ (str[0] != 'm' || str[1] != 'p')
                goto try_next;
            str += 2;
            ᮚᮦᮔ᮪ (!arm64_memory_is_pair_suitable(op->vt))
                goto try_next;
            ᮚᮦᮔ᮪ (!arm64_prepare_memory_operand(op, regs_allocated))
                goto try_next;
            bha_nga;
        pak_sa 'i':
            ᮚᮦᮔ᮪ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                goto try_next;
            bha_nga;
        pak_sa 'I':
            ᮚᮦᮔ᮪ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ᮚᮦᮔ᮪ (!is_valid_add_imm(op->vt->c.i))
                goto try_next;
            bha_nga;
        pak_sa 'J':
            ᮚᮦᮔ᮪ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ᮚᮦᮔ᮪ (!is_valid_add_imm(-op->vt->c.i))
                goto try_next;
            bha_nga;
        pak_sa 'K':
            ᮚᮦᮔ᮪ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ᮚᮦᮔ᮪ (!is_valid_logical_imm(op->vt->c.i, 32))
                goto try_next;
            bha_nga;
        pak_sa 'L':
            ᮚᮦᮔ᮪ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ᮚᮦᮔ᮪ (!is_valid_logical_imm(op->vt->c.i, 64))
                goto try_next;
            bha_nga;
        pak_sa 'M':
        pak_sa 'N':
            ᮚᮦᮔ᮪ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ᮚᮦᮔ᮪ (!is_valid_movw_imm(op->vt->c.i))
                goto try_next;
            bha_nga;
        pak_sa 'Z':
            ᮚᮦᮔ᮪ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            ᮚᮦᮔ᮪ (op->vt->c.i != 0)
                goto try_next;
            bha_nga;
        pak_sa 'n':
            ᮚᮦᮔ᮪ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                goto try_next;
            bha_nga;
        default:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            bha_nga;
        }
        ᮚᮦᮔ᮪ (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
        continue;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        ᮚᮦᮔ᮪ (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    for (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ᮚᮦᮔ᮪ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            for (reg = 0; reg < 31; reg++) {
                ᮚᮦᮔ᮪ (!(regs_allocated[reg] & REG_OUT_MASK))
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
    puur_naa_nka reg;

    ᮚᮦᮔ᮪ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ᮝᮜᮤ;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    ᮚᮦᮔ᮪ (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC puur_naa_nka asm_parse_regvar(puur_naa_nka t)
{
    ᮝᮜᮤ arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
