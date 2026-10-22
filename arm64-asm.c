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

ST_FUNC void g(ціле c);
ST_FUNC void gen_le16(ціле c);
ST_FUNC void gen_le32(ціле c);

/*************************************************************/
#інакше
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
enum {
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

typedef struct Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    ціле reg_tok;
    ExprValue e;
} Operand;

enum {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
static void parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC void g(ціле c)
{
    ціле ind1;
    якщо (nocode_wanted)
        повернути;
    ind1 = ind + 1;
    якщо (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC void gen_le16(ціле c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC void gen_le32(ціле c)
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
    якщо (nocode_wanted)
        повернути;
    якщо (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
static ціле arm64_parse_asm_reg(ціле t)
{
    /* X registers (64-bit) */
    якщо (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        повернути t - TOK_ASM_x0;
    /* W registers (32-bit) */
    якщо (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        повернути t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    якщо (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        повернути (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    якщо (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        повернути (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    якщо (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        повернути (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    якщо (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        повернути (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    якщо (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        повернути (t - TOK_ASM_b0) + 32;
    /* Special registers */
    якщо (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        повернути 31;  /* SP/ZR encoded as 31 */
    повернути -1;
}

/* Get register type from token */
static uint8_t get_reg_type(ціле t)
{
    якщо (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        повернути REG_X;
    якщо (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        повернути REG_W;
    якщо (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        повернути REG_V;
    якщо (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        повернути REG_D;
    якщо (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        повернути REG_S;
    якщо (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        повернути REG_H;
    якщо (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        повернути REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    якщо (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        повернути REG_X;
    якщо (t == TOK_ASM_wzr)
        повернути REG_W;
    повернути REG_X;
}

/* Parse condition code */
static ціле parse_condition(ціле t)
{
    switch (t) {
        case TOK_ASM_eq: повернути 0;
        case TOK_ASM_ne: повернути 1;
        case TOK_ASM_cs:
        case TOK_ASM_hs: повернути 2;
        case TOK_ASM_cc:
        case TOK_ASM_lo: повернути 3;
        case TOK_ASM_mi: повернути 4;
        case TOK_ASM_pl: повернути 5;
        case TOK_ASM_vs: повернути 6;
        case TOK_ASM_vc: повернути 7;
        case TOK_ASM_hi: повернути 8;
        case TOK_ASM_ls: повернути 9;
        case TOK_ASM_ge: повернути 10;
        case TOK_ASM_lt: повернути 11;
        case TOK_ASM_gt: повернути 12;
        case TOK_ASM_le: повернути 13;
        case TOK_ASM_al: повернути 14;
        default: повернути -1;
    }
}

static ціле parse_barrier_option_name(ціле t)
{
    const char *name;

    якщо (t < TOK_IDENT)
        повернути -1;
    name = get_tok_str(t, NULL);
    якщо (!strcmp(name, "oshld")) повернути 0x1;
    якщо (!strcmp(name, "oshst")) повернути 0x2;
    якщо (!strcmp(name, "osh"))   повернути 0x3;
    якщо (!strcmp(name, "nshld")) повернути 0x5;
    якщо (!strcmp(name, "nshst")) повернути 0x6;
    якщо (!strcmp(name, "nsh"))   повернути 0x7;
    якщо (!strcmp(name, "ishld")) повернути 0x9;
    якщо (!strcmp(name, "ishst")) повернути 0xA;
    якщо (!strcmp(name, "ish"))   повернути 0xB;
    якщо (!strcmp(name, "ld"))    повернути 0xD;
    якщо (!strcmp(name, "st"))    повернути 0xE;
    якщо (!strcmp(name, "sy"))    повернути 0xF;
    повернути -1;
}

static ціле arm64_parse_regvar(ціле t)
{
    якщо (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        повернути t - TOK_ASM_x0;
    якщо (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        повернути ARM64_FREG_BASE + (t - TOK_ASM_v0);
    якщо (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        повернути ARM64_FREG_BASE + (t - TOK_ASM_d0);
    якщо (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        повернути ARM64_FREG_BASE + (t - TOK_ASM_s0);
    якщо (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        повернути ARM64_FREG_BASE + (t - TOK_ASM_h0);
    якщо (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        повернути ARM64_FREG_BASE + (t - TOK_ASM_b0);
    повернути -1;
}

/* Parse a single operand */
static void parse_operand(TCCState *s1, Operand *op)
{
    ціле reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    якщо (tok == '[') {
        parse_addr_operand(s1, op);
        повернути;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    якщо (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        повернути;
    }

    /* Condition code */
    reg = parse_condition(tok);
    якщо (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        повернути;
    }

    /* Immediate or address expression */
    якщо (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_expr(s1, &op->e);
        op->type = OP_IM;
    } інакше якщо (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } інакше {
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

    якщо (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_expr(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
static void parse_addr_operand(TCCState *s1, Operand *op)
{
    ціле reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = NULL;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    якщо (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        повернути;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    якщо (tok == ',') {
        next();
        якщо (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_expr(s1, &op->e);
    }
    skip(']');
    якщо (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } інакше якщо (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        якщо (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_expr(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
static void gen_mov_with_base(ціле rd, uint16_t imm, ціле shift,
                              ціле is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    якщо (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

static void gen_movz(ціле rd, uint16_t imm, ціле shift, ціле is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
static void gen_movn(ціле rd, uint16_t imm, ціле shift, ціле is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
static void gen_movk(ціле rd, uint16_t imm, ціле shift, ціле is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
static void gen_add_imm(ціле rd, ціле rn, uint32_t imm, ціле is_64bit, ціле setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    якщо (is_64bit) instr |= ARM64_SF(1);
    якщо (setflags) instr |= ARM64_S(1);

    якщо (imm <= 0xFFF) {
        imm12 = imm;
    } інакше якщо (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } інакше {
        tcc_error("add immediate out of range");
        повернути;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
static void gen_sub_imm(ціле rd, ціле rn, uint32_t imm, ціле is_64bit, ціле setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    якщо (is_64bit) instr |= ARM64_SF(1);
    якщо (setflags) instr |= ARM64_S(1);

    якщо (imm <= 0xFFF) {
        imm12 = imm;
    } інакше якщо (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } інакше {
        tcc_error("sub immediate out of range");
        повернути;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
static void gen_dp_reg(uint32_t opcode, ціле rd, ціле rn, ціле rm, ціле is_64bit)
{
    uint32_t instr = opcode;
    якщо (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
static void gen_ldst_imm(uint32_t base_opcode, ціле rt, ціле rn,
                         int32_t offset, ціле size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    якщо (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        якщо (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            повернути;
        }
    }

    switch (base_opcode) {
    case ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; break;
    case ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; break;
    case ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; break;
    case ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; break;
    case ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; break;
    case ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; break;
    case ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; break;
    case ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; break;
    case ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; break;
    case ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; break;
    }

    якщо (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        повернути;
    }

    якщо (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
static void gen_ldst_pair(uint32_t base_opcode, ціле rt, ціле rt2, ціле rn,
                          int32_t offset, ціле size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    якщо (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    якщо (imm7 < -64 || imm7 > 63)
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
static void gen_br(ціле rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
static void gen_blr(ціле rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
static void gen_ret(ціле rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
static void gen_b_cond(ціле cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
static void gen_cbz_or_cbnz(ціле rt, int32_t offset, ціле is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    якщо (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

static void gen_cbz(ціле rt, int32_t offset, ціле is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
static void gen_cbnz(ціле rt, int32_t offset, ціле is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
static void gen_mov_reg(ціле rd, ціле rm, ціле is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    якщо (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

static ціле arm64_asm_encode_bimm64(uint64_t x)
{
    ціле neg, rep, pos, len;

    neg = x & 1;
    якщо (neg)
        x = ~x;
    якщо (!x)
        повернути -1;

    якщо (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    інакше якщо (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    інакше якщо (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    інакше якщо (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    інакше якщо (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    інакше
        rep = 64;

    pos = 0;
    якщо (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    якщо (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    якщо (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    якщо (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    якщо (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    якщо (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    якщо (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    якщо (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    якщо (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    якщо (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    якщо (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    якщо (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    якщо (x)
        повернути -1;
    якщо (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    повернути ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

static void gen_logical_imm(uint32_t opcode, ціле rd, ціле rn,
                            uint64_t imm, ціле is_64bit)
{
    uint32_t instr;
    uint64_t val;
    ціле enc;

    якщо (is_64bit)
        val = imm;
    інакше {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    якщо (enc < 0) {
        tcc_error("logical immediate out of range");
        повернути;
    }

    instr = opcode;
    якщо (is_64bit)
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
static inline ціле constraint_priority(const char *str)
{
    ціле priority, c, pr;

    priority = 0;
    для (;;) {
        c = *str++;
        якщо (c == '\0')
            break;
        switch (c) {
        case '=':
        case '+':
        case '&':
            continue;
        case 'r':
            pr = 1;
            break;
        case 'w':
        case 'f':
        case 'x':
        case 'y':
            pr = 3;
            break;
        case 'm':
        case 'Q':
            pr = 4;
            break;
        case 'i':
        case 'S':
            pr = 5;
            break;
        case 'U':
            якщо (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                break;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            break;
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'Z':
            pr = 6;
            break;
        case 'n':
            pr = 7;
            break;
        case 'g':
            pr = 8;
            break;
        default:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            break;
        }
        якщо (pr > priority)
            priority = pr;
    }
    повернути priority;
}

static const char *skip_constraint_modifiers(const char *p)
{
    поки (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    повернути p;
}

static ціле is_valid_add_imm(int64_t val)
{
    повернути val >= 0 && val <= 4095;
}

static ціле is_valid_logical_imm(int64_t val, ціле bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    якщо (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    повернути arm64_asm_encode_bimm64(uval) >= 0;
}

static ціле is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    якщо (uval <= 0xFFFF)
        повернути 1;
    якщо (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        повернути 1;
    якщо (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        повернути 1;
    якщо ((uval & 0xFFFFFFFF00000000ULL) == 0)
        повернути 1;

    повернути 0;
}

static ціле is_valid_movw_shift(ціле shift, ціле is_64bit)
{
    якщо (shift < 0 || (shift & 15))
        повернути 0;
    якщо (shift > (is_64bit ? 48 : 16))
        повернути 0;
    повернути 1;
}

static ціле arm64_memory_is_base_only(const SValue *sv)
{
    ціле r;

    r = sv->r;
    якщо ((r & VT_VALMASK) == VT_CONST)
        повернути 0;
    якщо ((r & VT_VALMASK) == VT_LOCAL)
        повернути 0;
    якщо ((r & VT_VALMASK) == VT_LLOCAL)
        повернути 1;
    якщо (r & VT_LVAL)
        повернути (r & VT_VALMASK) < VT_CONST;
    повернути 0;
}

static ціле arm64_memory_is_pair_suitable(const SValue *sv)
{
    int64_t offset;

    якщо (arm64_memory_is_base_only(sv))
        повернути 1;
    якщо ((sv->r & VT_VALMASK) != VT_LOCAL)
        повернути 0;

    offset = (int64_t)sv->c.i;
    повернути (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

static ціле arm64_int_reg_is_allocatable(ціле reg)
{
#ifdef TCC_TARGET_PE
    повернути reg >= TREG_X0 && reg <= TREG_X17;
#інакше
    повернути reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

static ціле arm64_memory_needs_address_reg(const SValue *sv)
{
    ціле r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    якщо (!(r & VT_LVAL))
        повернути 0;
    switch (r & VT_VALMASK) {
    case VT_LOCAL:
    case VT_LLOCAL:
    case VT_CONST:
        повернути 1;
    }
    повернути 0;
}

static ціле arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    ціле reg;

    якщо (!arm64_memory_needs_address_reg(op->vt))
        повернути 1;

    для (reg = 0; reg < 31; reg++) {
        якщо (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            повернути 1;
        }
    }
    повернути 0;
}

static void arm64_load_memory_operand_base(ціле reg, SValue *sv)
{
    SValue base;
    ціле rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    якщо (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } інакше якщо (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } інакше {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

static ціле operand_is_sp(const Operand *op)
{
    повернути op->reg_tok == TOK_ASM_sp;
}

static ціле parse_sysreg_name(ціле t)
{
    const char *name;

    якщо (t < TOK_IDENT)
        повернути -1;
    name = get_tok_str(t, NULL);
    якщо (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        повернути 0;
    якщо (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        повернути 1;
    повернути -1;
}

static void gen_mrs(ціле rt, ціле sysreg)
{
    uint32_t instr;

    switch (sysreg) {
        case 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            break;
        case 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            break;
        default:
            tcc_error("unsupported system register");
            повернути;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

static void gen_msr(ціле rt, ціле sysreg)
{
    uint32_t instr;

    switch (sysreg) {
        case 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            break;
        case 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            break;
        default:
            tcc_error("unsupported system register");
            повернути;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
static void gen_nop(void)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
static void gen_shift(ціле rd, ціле rn, ціле rm_or_imm, ціле shift_type, ціле is_imm, ціле is_64bit)
{
    uint32_t instr;
    ціле width = is_64bit ? 64 : 32;

    якщо (is_imm) {
        /* Shift by immediate */
        switch (shift_type) {
            case 0: /* LSL - UBFM alias */
                якщо (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    повернути;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                break;
            case 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                якщо (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    повернути;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                break;
            case 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                якщо (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    повернути;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                break;
            case 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                якщо (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    повернути;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                повернути;
            default:
                tcc_error("unknown shift type");
                повернути;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } інакше {
        /* Shift by register */
        switch (shift_type) {
            case 0: /* LSL */
                instr = ARM64_LSL_REG;
                break;
            case 1: /* LSR */
                instr = ARM64_LSR_REG;
                break;
            case 2: /* ASR */
                instr = ARM64_ASR_REG;
                break;
            case 3: /* ROR */
                instr = ARM64_ROR_REG;
                break;
            default:
                tcc_error("unknown shift type");
                повернути;
        }
        якщо (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
static void asm_shift(TCCState *s1, ціле token)
{
    Operand op1, op2, op3;
    ціле rd, rn, shift_amount;
    ціле shift_type;
    ціле is_64bit = 1;

    switch (token) {
        case TOK_ASM_lsl:
            shift_type = 0;
            break;
        case TOK_ASM_lsr:
            shift_type = 1;
            break;
        case TOK_ASM_asr:
            shift_type = 2;
            break;
        case TOK_ASM_ror:
            shift_type = 3;
            break;
        default:
            tcc_error("unknown shift instruction");
            повернути;
    }

    parse_operand(s1, &op1);
    якщо (tok == ',') next();
    parse_operand(s1, &op2);

    якщо (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        повернути;
    }
    якщо (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        повернути;
    }

    rd = op1.reg;
    rn = op2.reg;

    якщо (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        якщо (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            повернути;
        }
        якщо (op3.type & OP_REG) {
            якщо (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                повернути;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } інакше якщо (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } інакше {
            tcc_error("shift requires immediate or register operand");
        }
    } інакше {
        tcc_error("shift requires immediate or register operand");
        повернути;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
static void gen_barrier(ціле barrier_type, ціле option)
{
    uint32_t instr;

    switch (barrier_type) {
        case 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            break;
        case 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            break;
        case 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            break;
        default:
            tcc_error("unknown barrier type");
            повернути;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
static void asm_barrier(TCCState *s1, ціле token)
{
    ціле barrier_type, option;
    Operand op;

    switch (token) {
        case TOK_ASM_isb:
            barrier_type = 0;
            break;
        case TOK_ASM_dsb:
            barrier_type = 1;
            break;
        case TOK_ASM_dmb:
            barrier_type = 2;
            break;
        default:
            tcc_error("unknown barrier instruction");
            повернути;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    якщо (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        якщо (option >= 0) {
            next();
        } інакше {
            parse_operand(s1, &op);
            якщо (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                повернути;
            }
            якщо (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                повернути;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
static void gen_mov_imm(ціле rd, uint64_t imm, ціле is_64bit)
{
    uint16_t hw;
    ціле i, first = 1;

    для (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        якщо (hw != 0 || i == 0) {
            якщо (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } інакше {
                gen_movk(rd, hw, i, is_64bit);
            }
        } інакше якщо (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
static void asm_mov(TCCState *s1)
{
    Operand op1, op2;
    ціле rd, rn;
    ціле is_64bit;

    parse_operand(s1, &op1);
    якщо (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    якщо (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        якщо (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            повернути;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } інакше якщо (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        якщо (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        інакше
            gen_mov_reg(rd, rn, is_64bit);
    } інакше {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
static void asm_data_proc(TCCState *s1, ціле token)
{
    Operand op1, op2, op3;
    ціле rd, rn, rm;
    ціле is_64bit = 1;
    uint32_t opcode;

    switch (token) {
        case TOK_ASM_add:
        case TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            break;
        case TOK_ASM_sub:
        case TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            break;
        case TOK_ASM_and:
        case TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            break;
        case TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            break;
        case TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            break;
        case TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            break;
        default:
            tcc_error("unsupported data processing instruction");
            повернути;
    }

    parse_operand(s1, &op1);
    якщо (tok == ',') next();
    parse_operand(s1, &op2);

    якщо (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        повернути;
    }
    якщо (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        повернути;
    }

    rd = op1.reg;
    rn = op2.reg;

    якщо (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        якщо (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            повернути;
        }
        якщо (op3.type & OP_IM) {
            якщо (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            інакше якщо (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            інакше якщо (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            інакше якщо (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            інакше якщо (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            інакше якщо (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            інакше
                tcc_error("immediate operand not valid for this instruction");
        } інакше {
            якщо (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                повернути;
            }
            rm = op3.reg;
            якщо (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                повернути;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } інакше якщо (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } інакше {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
static void asm_ldst(TCCState *s1, ціле token)
{
    Operand op1, op2;
    ціле rt, rn;
    int32_t offset = 0;
    ціле size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    якщо (tok == ',') next();
    parse_operand(s1, &op2);

    якщо (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        повернути;
    }
    якщо (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        повернути;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    switch (token) {
        case TOK_ASM_ldr:
            якщо (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } інакше якщо (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } інакше якщо (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } інакше {
                tcc_error("ldr requires a w, x, or d register");
                повернути;
            }
            break;
        case TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            break;
        case TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            break;
        case TOK_ASM_str:
            якщо (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } інакше якщо (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } інакше якщо (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } інакше {
                tcc_error("str requires a w, x, or d register");
                повернути;
            }
            break;
        case TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            break;
        case TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            break;
        default:
            tcc_error("unsupported load/store instruction");
            повернути;
    }

    якщо (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

static void asm_ldst_pair(TCCState *s1, ціле token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    ціле size_log2 = 3;

    parse_operand(s1, &op1);
    якщо (tok == ',')
        next();
    parse_operand(s1, &op2);
    якщо (tok == ',')
        next();
    parse_operand(s1, &op3);

    якщо (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        повернути;
    }
    якщо (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        повернути;
    }
    якщо (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    якщо ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        якщо (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } інакше {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } інакше якщо ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        якщо (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } інакше {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } інакше {
        tcc_error("stp/ldp requires matching x or d registers");
        повернути;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

static void asm_sysreg(TCCState *s1, ціле token)
{
    Operand op;
    ціле sysreg;

    якщо (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        якщо (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        якщо (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        повернути;
    }

    sysreg = parse_sysreg_name(tok);
    якщо (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    якщо (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
static ціле get_branch_condition(ціле branch_token)
{
    ціле cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    switch (branch_token) {
        case TOK_ASM_beq: cond_token = TOK_ASM_eq; break;
        case TOK_ASM_bne: cond_token = TOK_ASM_ne; break;
        case TOK_ASM_bcs:
        case TOK_ASM_bhs: cond_token = TOK_ASM_cs; break;
        case TOK_ASM_bcc:
        case TOK_ASM_blo: cond_token = TOK_ASM_cc; break;
        case TOK_ASM_bmi: cond_token = TOK_ASM_mi; break;
        case TOK_ASM_bpl: cond_token = TOK_ASM_pl; break;
        case TOK_ASM_bvs: cond_token = TOK_ASM_vs; break;
        case TOK_ASM_bvc: cond_token = TOK_ASM_vc; break;
        case TOK_ASM_bhi: cond_token = TOK_ASM_hi; break;
        case TOK_ASM_bls: cond_token = TOK_ASM_ls; break;
        case TOK_ASM_bge: cond_token = TOK_ASM_ge; break;
        case TOK_ASM_blt: cond_token = TOK_ASM_lt; break;
        case TOK_ASM_bgt: cond_token = TOK_ASM_gt; break;
        case TOK_ASM_ble: cond_token = TOK_ASM_le; break;
        default: повернути -1;
    }

    повернути parse_condition(cond_token);
}

/* Handle branch instructions */
static void asm_branch(TCCState *s1, ціле token)
{
    Operand op;
    ціле cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    якщо (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        повернути;
    }

    якщо (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    інакше
        parse_expr_operand(s1, &op);

    якщо (op.type & OP_IM) {
        sym = op.e.sym;
        якщо (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            якщо (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } інакше {
                switch (token) {
                    case TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        break;
                    case TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        break;
                    default:
                        tcc_error("unsupported branch");
                }
            }
        } інакше {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            якщо (cond >= 0) {
                gen_b_cond(cond, offset);
            } інакше {
                switch (token) {
                    case TOK_ASM_b:
                        gen_b(offset);
                        break;
                    case TOK_ASM_bl:
                        gen_bl(offset);
                        break;
                    default:
                        tcc_error("unsupported branch");
                }
            }
        }
    } інакше якщо (op.type & OP_REG) {
        switch (token) {
            case TOK_ASM_br:
                gen_br(op.reg);
                break;
            case TOK_ASM_blr:
                gen_blr(op.reg);
                break;
            case TOK_ASM_ret:
                gen_ret(op.reg);
                break;
            default:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
static void asm_cb(TCCState *s1, ціле token)
{
    Operand op1, op2;
    ціле rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    якщо (tok == ',') next();
    parse_expr_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    якщо (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        якщо (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } інакше {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } інакше {
        offset = (int32_t)op2.e.v - ind;
        якщо (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        інакше
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
static void asm_move_wide(TCCState *s1, ціле token)
{
    Operand op1, op2;
    ціле rd, is_64bit = 1;
    uint16_t imm;
    ціле shift = 0;

    parse_operand(s1, &op1);
    якщо (tok == ',') next();
    parse_operand(s1, &op2);

    якщо (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        повернути;
    }
    якщо (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        повернути;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    якщо ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        повернути;
    }
    imm = op2.e.v;

    якщо (tok == ',') {
        next();
        якщо (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            повернути;
        }
            next();
            якщо (tok == '#') next();
            asm_expr(s1, &op2.e);
        якщо (op2.e.sym || !is_valid_movw_shift((ціле)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            повернути;
        }
            shift = (ціле)op2.e.v / 16;
        }

    switch (token) {
        case TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            break;
        case TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            break;
        case TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            break;
        default:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC void asm_opcode(TCCState *s1, ціле opcode)
{
    switch (opcode) {
        case TOK_ASM_add:
        case TOK_ASM_adds:
        case TOK_ASM_sub:
        case TOK_ASM_subs:
        case TOK_ASM_and:
        case TOK_ASM_ands:
        case TOK_ASM_orr:
        case TOK_ASM_eor:
        case TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            break;

        case TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            break;

        case TOK_ASM_lsl:
        case TOK_ASM_lsr:
        case TOK_ASM_asr:
        case TOK_ASM_ror:
            asm_shift(s1, opcode);
            break;

        case TOK_ASM_ldr:
        case TOK_ASM_ldrb:
        case TOK_ASM_ldrh:
        case TOK_ASM_str:
        case TOK_ASM_strb:
        case TOK_ASM_strh:
            asm_ldst(s1, opcode);
            break;

        case TOK_ASM_ldp:
        case TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            break;

        case TOK_ASM_b:
        case TOK_ASM_bl:
        case TOK_ASM_br:
        case TOK_ASM_blr:
        case TOK_ASM_ret:
        case TOK_ASM_beq:
        case TOK_ASM_bne:
        case TOK_ASM_bcs:
        case TOK_ASM_bhs:
        case TOK_ASM_bcc:
        case TOK_ASM_blo:
        case TOK_ASM_bmi:
        case TOK_ASM_bpl:
        case TOK_ASM_bvs:
        case TOK_ASM_bvc:
        case TOK_ASM_bhi:
        case TOK_ASM_bls:
        case TOK_ASM_bge:
        case TOK_ASM_blt:
        case TOK_ASM_bgt:
        case TOK_ASM_ble:
            asm_branch(s1, opcode);
            break;

        case TOK_ASM_cbz:
        case TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            break;

        case TOK_ASM_movz:
        case TOK_ASM_movn:
        case TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            break;

        case TOK_ASM_mrs:
        case TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            break;

        case TOK_ASM_isb:
        case TOK_ASM_dsb:
        case TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            break;

        case TOK_ASM_nop:
            gen_nop();
            break;

        default:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, NULL));
            break;
    }
}

/* Substitute assembler operand */
ST_FUNC void subst_asm_operand(CString *add_str, SValue *sv, ціле modifier)
{
    ціле r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    якщо ((r & VT_VALMASK) == VT_CONST) {
        якщо ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            повернути;
        }
        якщо (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        якщо (r & VT_SYM) {
            const char *name = get_tok_str(sv->sym->v, NULL);
            якщо (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            якщо (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            якщо ((uint32_t) sv->c.i == 0)
                goto no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        якщо (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } інакше якщо (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } інакше {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } інакше якщо ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (ціле) sv->c.i);
    } інакше якщо (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        якщо (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } інакше {
        /* register case */
        reg = r & VT_VALMASK;
        якщо (reg >= VT_CONST)
            tcc_internal_error("");

        якщо (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            якщо (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            switch (modifier) {
            case 'b':
            case 'h':
            case 's':
            case 'd':
            case 'q':
            case 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                повернути;
            default:
                tcc_error("invalid operand modifier for SIMD/FP register");
                повернути;
            }
        }

        /* choose register operand size */
        якщо ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        інакше якщо ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        інакше якщо ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        інакше
            size = 4;

        якщо (modifier == 'x') {
            size = 8;
        } інакше якщо (modifier == 'w' || modifier == 'k') {
            size = 4;
        } інакше якщо (modifier == 'b') {
            size = 1;
        } інакше якщо (modifier == 'h') {
            size = 2;
        } інакше якщо (modifier == 'q') {
            size = 8;
        }

        якщо (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } інакше {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC void asm_gen_code(ASMOperand *operands, ціле nb_operands,
                          ціле nb_outputs, ціле is_output,
                          uint8_t *clobber_regs,
                          ціле out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ціле i, reg, saved_count, stack_size, stack_off;
    ціле saved_regs[12];
    static const uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, sizeof(regs_allocated));
    для (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        якщо (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_count = 0;
    для (i = 0; i < sizeof(reg_saved) / sizeof(reg_saved[0]); i++) {
        reg = reg_saved[i];
        якщо (regs_allocated[reg])
            saved_regs[saved_count++] = reg;
    }
    stack_size = ((saved_count + 1) / 2) * 16;

    якщо (!is_output) {
        якщо (saved_count > 0) {
            gen_sub_imm(31, 31, stack_size, 1, 0);

            для (i = stack_off = 0; i < saved_count; ) {
                якщо (i + 1 < saved_count) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, stack_off, 3);
                    stack_off += 16;
                    i += 2;
                } інакше {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 stack_off, 3);
                    i++;
                }
            }
        }

        для (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            якщо (op->reg >= 0) {
                якщо (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } інакше якщо (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } інакше {
        для (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            якщо (op->reg >= 0) {
                якщо (op->is_memory)
                    continue;
                якщо ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    якщо (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } інакше {
                    store(op->reg, op->vt);
                }
            }
        }

        якщо (saved_count > 0) {
            для (i = stack_off = 0; i < saved_count; ) {
                якщо (i + 1 < saved_count) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, stack_off, 3);
                    stack_off += 16;
                    i += 2;
                } інакше {
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
                                    ціле nb_operands, ціле nb_outputs,
                                    const uint8_t *clobber_regs,
                                    ціле *pout_reg)
{
    ASMOperand *op;
    ціле sorted_op[MAX_ASM_OPERANDS];
    ціле i, j, k, p1, p2, tmp, reg, c, reg_mask;
    const char *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    для (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->input_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    для (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        якщо (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, NULL);
            якщо ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            якщо (operands[k].input_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].input_index = i;
            op->priority = 5;
        } інакше якщо ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } інакше {
            op->priority = constraint_priority(str);
        }
    }

    для (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    для (i = 0; i < nb_operands - 1; i++) {
        для (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            якщо (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    для (i = 0; i < NB_ASM_REGS; i++) {
        якщо (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        інакше
            regs_allocated[i] = 0;
    }

    для (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        якщо (op->ref_index >= 0)
            continue;
        якщо (op->input_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } інакше якщо (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } інакше {
            reg_mask = REG_IN_MASK;
        }
        якщо (op->reg >= 0) {
            якщо (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            goto reg_found;
        }
    try_next:
        c = *str++;
        switch (c) {
        case '=':
            goto try_next;
        case '+':
            op->is_rw = 1;
        case '&':
            якщо (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            goto try_next;
        case 'r':
            для (reg = 0; reg < 31; reg++) {
                якщо (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        case 'w':
        case 'f':
            для (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                якщо (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        case 'x':
        case 'y':
            для (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                якщо (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        case 'm':
        case 'g':
            якщо (j < nb_outputs || c == 'm') {
                якщо (!arm64_prepare_memory_operand(op, regs_allocated))
                    goto try_next;
            }
            break;
        case 'Q':
            якщо (!arm64_memory_is_base_only(op->vt))
                goto try_next;
            якщо (!arm64_prepare_memory_operand(op, regs_allocated))
                goto try_next;
            break;
        case 'S':
            якщо ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                goto try_next;
            break;
        case 'U':
            якщо (str[0] != 'm' || str[1] != 'p')
                goto try_next;
            str += 2;
            якщо (!arm64_memory_is_pair_suitable(op->vt))
                goto try_next;
            якщо (!arm64_prepare_memory_operand(op, regs_allocated))
                goto try_next;
            break;
        case 'i':
            якщо (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                goto try_next;
            break;
        case 'I':
            якщо (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            якщо (!is_valid_add_imm(op->vt->c.i))
                goto try_next;
            break;
        case 'J':
            якщо (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            якщо (!is_valid_add_imm(-op->vt->c.i))
                goto try_next;
            break;
        case 'K':
            якщо (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            якщо (!is_valid_logical_imm(op->vt->c.i, 32))
                goto try_next;
            break;
        case 'L':
            якщо (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            якщо (!is_valid_logical_imm(op->vt->c.i, 64))
                goto try_next;
            break;
        case 'M':
        case 'N':
            якщо (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            якщо (!is_valid_movw_imm(op->vt->c.i))
                goto try_next;
            break;
        case 'Z':
            якщо (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                goto try_next;
            якщо (op->vt->c.i != 0)
                goto try_next;
            break;
        case 'n':
            якщо (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                goto try_next;
            break;
        default:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            break;
        }
        якщо (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
        continue;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        якщо (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    для (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        якщо (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            для (reg = 0; reg < 31; reg++) {
                якщо (!(regs_allocated[reg] & REG_OUT_MASK))
                    goto reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            break;
        }
    }
}

/* Handle clobber list */
ST_FUNC void asm_clobber(uint8_t *clobber_regs, const char *str)
{
    ціле reg;

    якщо (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        повернути;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    якщо (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC ціле asm_parse_regvar(ціле t)
{
    повернути arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
