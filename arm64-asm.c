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

ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಙ್ಕ c);

/*************************************************************/
#ಅನ್ಯಥಾ
/*************************************************************/

#define USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

/* Register type flags */
#define REG_X     0x01  /* 64-bit general purpose */
#define REG_W     0x02  /* 32-bit general purpose */
#define REG_V     0x04  /* 128-bit SIMD */
#define REG_D     0x08  /* 64-bit FP */
#define REG_S     0x10  /* 32-bit FP */
#define REG_H     0x20  /* 16-bit FP */
#define REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
ಗಣನಾ {
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

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    ಪೂರ್ಣಾಙ್ಕ reg_tok;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
} Operand;

ಗಣನಾ {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
ಸ್ಥಿರ ಶೂನ್ಯ parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಙ್ಕ c)
{
    ಪೂರ್ಣಾಙ್ಕ ind1;
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    ind1 = ind + 1;
    ಯದಿ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಙ್ಕ c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಙ್ಕ c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
ಸ್ಥಿರ ಶೂನ್ಯ emit_instr32(uint32_t val)
{
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_parse_asm_reg(ಪೂರ್ಣಾಙ್ಕ t)
{
    /* X registers (64-bit) */
    ಯದಿ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_x0;
    /* W registers (32-bit) */
    ಯದಿ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    ಯದಿ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ಪ್ರತ್ಯಾಗಮ (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    ಯದಿ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ಪ್ರತ್ಯಾಗಮ (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    ಯದಿ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ಪ್ರತ್ಯಾಗಮ (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    ಯದಿ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ಪ್ರತ್ಯಾಗಮ (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    ಯದಿ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ಪ್ರತ್ಯಾಗಮ (t - TOK_ASM_b0) + 32;
    /* Special registers */
    ಯದಿ (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        ಪ್ರತ್ಯಾಗಮ 31;  /* SP/ZR encoded as 31 */
    ಪ್ರತ್ಯಾಗಮ -1;
}

/* Get register type from token */
ಸ್ಥಿರ uint8_t get_reg_type(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಯದಿ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ಪ್ರತ್ಯಾಗಮ REG_X;
    ಯದಿ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ಪ್ರತ್ಯಾಗಮ REG_W;
    ಯದಿ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ಪ್ರತ್ಯಾಗಮ REG_V;
    ಯದಿ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ಪ್ರತ್ಯಾಗಮ REG_D;
    ಯದಿ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ಪ್ರತ್ಯಾಗಮ REG_S;
    ಯದಿ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ಪ್ರತ್ಯಾಗಮ REG_H;
    ಯದಿ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ಪ್ರತ್ಯಾಗಮ REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    ಯದಿ (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        ಪ್ರತ್ಯಾಗಮ REG_X;
    ಯದಿ (t == TOK_ASM_wzr)
        ಪ್ರತ್ಯಾಗಮ REG_W;
    ಪ್ರತ್ಯಾಗಮ REG_X;
}

/* Parse condition code */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ parse_condition(ಪೂರ್ಣಾಙ್ಕ t)
{
    ವಿಕಲ್ಪ (t) {
        ಪಕ್ಷ TOK_ASM_eq: ಪ್ರತ್ಯಾಗಮ 0;
        ಪಕ್ಷ TOK_ASM_ne: ಪ್ರತ್ಯಾಗಮ 1;
        ಪಕ್ಷ TOK_ASM_cs:
        ಪಕ್ಷ TOK_ASM_hs: ಪ್ರತ್ಯಾಗಮ 2;
        ಪಕ್ಷ TOK_ASM_cc:
        ಪಕ್ಷ TOK_ASM_lo: ಪ್ರತ್ಯಾಗಮ 3;
        ಪಕ್ಷ TOK_ASM_mi: ಪ್ರತ್ಯಾಗಮ 4;
        ಪಕ್ಷ TOK_ASM_pl: ಪ್ರತ್ಯಾಗಮ 5;
        ಪಕ್ಷ TOK_ASM_vs: ಪ್ರತ್ಯಾಗಮ 6;
        ಪಕ್ಷ TOK_ASM_vc: ಪ್ರತ್ಯಾಗಮ 7;
        ಪಕ್ಷ TOK_ASM_hi: ಪ್ರತ್ಯಾಗಮ 8;
        ಪಕ್ಷ TOK_ASM_ls: ಪ್ರತ್ಯಾಗಮ 9;
        ಪಕ್ಷ TOK_ASM_ge: ಪ್ರತ್ಯಾಗಮ 10;
        ಪಕ್ಷ TOK_ASM_lt: ಪ್ರತ್ಯಾಗಮ 11;
        ಪಕ್ಷ TOK_ASM_gt: ಪ್ರತ್ಯಾಗಮ 12;
        ಪಕ್ಷ TOK_ASM_le: ಪ್ರತ್ಯಾಗಮ 13;
        ಪಕ್ಷ TOK_ASM_al: ಪ್ರತ್ಯಾಗಮ 14;
        ಸ್ವಭಾವ: ಪ್ರತ್ಯಾಗಮ -1;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ parse_barrier_option_name(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಧ್ರುವ ವರ್ಣ *name;

    ಯದಿ (t < TOK_IDENT)
        ಪ್ರತ್ಯಾಗಮ -1;
    name = get_tok_str(t, ರಿಕ್ತ);
    ಯದಿ (!strcmp(name, "oshld")) ಪ್ರತ್ಯಾಗಮ 0x1;
    ಯದಿ (!strcmp(name, "oshst")) ಪ್ರತ್ಯಾಗಮ 0x2;
    ಯದಿ (!strcmp(name, "osh"))   ಪ್ರತ್ಯಾಗಮ 0x3;
    ಯದಿ (!strcmp(name, "nshld")) ಪ್ರತ್ಯಾಗಮ 0x5;
    ಯದಿ (!strcmp(name, "nshst")) ಪ್ರತ್ಯಾಗಮ 0x6;
    ಯದಿ (!strcmp(name, "nsh"))   ಪ್ರತ್ಯಾಗಮ 0x7;
    ಯದಿ (!strcmp(name, "ishld")) ಪ್ರತ್ಯಾಗಮ 0x9;
    ಯದಿ (!strcmp(name, "ishst")) ಪ್ರತ್ಯಾಗಮ 0xA;
    ಯದಿ (!strcmp(name, "ish"))   ಪ್ರತ್ಯಾಗಮ 0xB;
    ಯದಿ (!strcmp(name, "ld"))    ಪ್ರತ್ಯಾಗಮ 0xD;
    ಯದಿ (!strcmp(name, "st"))    ಪ್ರತ್ಯಾಗಮ 0xE;
    ಯದಿ (!strcmp(name, "sy"))    ಪ್ರತ್ಯಾಗಮ 0xF;
    ಪ್ರತ್ಯಾಗಮ -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_parse_regvar(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಯದಿ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_x0;
    ಯದಿ (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        ಪ್ರತ್ಯಾಗಮ ARM64_FREG_BASE + (t - TOK_ASM_v0);
    ಯದಿ (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        ಪ್ರತ್ಯಾಗಮ ARM64_FREG_BASE + (t - TOK_ASM_d0);
    ಯದಿ (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        ಪ್ರತ್ಯಾಗಮ ARM64_FREG_BASE + (t - TOK_ASM_s0);
    ಯದಿ (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        ಪ್ರತ್ಯಾಗಮ ARM64_FREG_BASE + (t - TOK_ASM_h0);
    ಯದಿ (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        ಪ್ರತ್ಯಾಗಮ ARM64_FREG_BASE + (t - TOK_ASM_b0);
    ಪ್ರತ್ಯಾಗಮ -1;
}

/* Parse a single operand */
ಸ್ಥಿರ ಶೂನ್ಯ parse_operand(TCCState *s1, Operand *op)
{
    ಪೂರ್ಣಾಙ್ಕ reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    ಯದಿ (tok == '[') {
        parse_addr_operand(s1, op);
        ಪ್ರತ್ಯಾಗಮ;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    ಯದಿ (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        ಪ್ರತ್ಯಾಗಮ;
    }

    /* Condition code */
    reg = parse_condition(tok);
    ಯದಿ (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        ಪ್ರತ್ಯಾಗಮ;
    }

    /* Immediate or address expression */
    ಯದಿ (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op->e);
        op->type = OP_IM;
    } ಅನ್ಯಥಾ ಯದಿ (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } ಅನ್ಯಥಾ {
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಅಭಿವ್ಯಕ್ತಿ_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    ಯದಿ (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
ಸ್ಥಿರ ಶೂನ್ಯ parse_addr_operand(TCCState *s1, Operand *op)
{
    ಪೂರ್ಣಾಙ್ಕ reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = ರಿಕ್ತ;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    ಯದಿ (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        ಪ್ರತ್ಯಾಗಮ;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    ಯದಿ (tok == ',') {
        next();
        ಯದಿ (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op->e);
    }
    skip(']');
    ಯದಿ (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } ಅನ್ಯಥಾ ಯದಿ (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        ಯದಿ (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
ಸ್ಥಿರ ಶೂನ್ಯ gen_mov_with_base(ಪೂರ್ಣಾಙ್ಕ rd, uint16_t imm, ಪೂರ್ಣಾಙ್ಕ shift,
                              ಪೂರ್ಣಾಙ್ಕ is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    ಯದಿ (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_movz(ಪೂರ್ಣಾಙ್ಕ rd, uint16_t imm, ಪೂರ್ಣಾಙ್ಕ shift, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
ಸ್ಥಿರ ಶೂನ್ಯ gen_movn(ಪೂರ್ಣಾಙ್ಕ rd, uint16_t imm, ಪೂರ್ಣಾಙ್ಕ shift, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
ಸ್ಥಿರ ಶೂನ್ಯ gen_movk(ಪೂರ್ಣಾಙ್ಕ rd, uint16_t imm, ಪೂರ್ಣಾಙ್ಕ shift, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_add_imm(ಪೂರ್ಣಾಙ್ಕ rd, ಪೂರ್ಣಾಙ್ಕ rn, uint32_t imm, ಪೂರ್ಣಾಙ್ಕ is_64bit, ಪೂರ್ಣಾಙ್ಕ setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    ಯದಿ (is_64bit) instr |= ARM64_SF(1);
    ಯದಿ (setflags) instr |= ARM64_S(1);

    ಯದಿ (imm <= 0xFFF) {
        imm12 = imm;
    } ಅನ್ಯಥಾ ಯದಿ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } ಅನ್ಯಥಾ {
        tcc_error("add immediate out of range");
        ಪ್ರತ್ಯಾಗಮ;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_sub_imm(ಪೂರ್ಣಾಙ್ಕ rd, ಪೂರ್ಣಾಙ್ಕ rn, uint32_t imm, ಪೂರ್ಣಾಙ್ಕ is_64bit, ಪೂರ್ಣಾಙ್ಕ setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    ಯದಿ (is_64bit) instr |= ARM64_SF(1);
    ಯದಿ (setflags) instr |= ARM64_S(1);

    ಯದಿ (imm <= 0xFFF) {
        imm12 = imm;
    } ಅನ್ಯಥಾ ಯದಿ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } ಅನ್ಯಥಾ {
        tcc_error("sub immediate out of range");
        ಪ್ರತ್ಯಾಗಮ;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
ಸ್ಥಿರ ಶೂನ್ಯ gen_dp_reg(uint32_t opcode, ಪೂರ್ಣಾಙ್ಕ rd, ಪೂರ್ಣಾಙ್ಕ rn, ಪೂರ್ಣಾಙ್ಕ rm, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    uint32_t instr = opcode;
    ಯದಿ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_ldst_imm(uint32_t base_opcode, ಪೂರ್ಣಾಙ್ಕ rt, ಪೂರ್ಣಾಙ್ಕ rn,
                         int32_t offset, ಪೂರ್ಣಾಙ್ಕ size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    ಯದಿ (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        ಯದಿ (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            ಪ್ರತ್ಯಾಗಮ;
        }
    }

    ವಿಕಲ್ಪ (base_opcode) {
    ಪಕ್ಷ ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; ಭಙ್ಗ;
    ಪಕ್ಷ ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; ಭಙ್ಗ;
    ಪಕ್ಷ ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; ಭಙ್ಗ;
    ಪಕ್ಷ ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; ಭಙ್ಗ;
    ಪಕ್ಷ ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; ಭಙ್ಗ;
    ಪಕ್ಷ ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; ಭಙ್ಗ;
    ಪಕ್ಷ ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; ಭಙ್ಗ;
    ಪಕ್ಷ ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; ಭಙ್ಗ;
    ಪಕ್ಷ ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; ಭಙ್ಗ;
    ಪಕ್ಷ ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; ಭಙ್ಗ;
    }

    ಯದಿ (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_ldst_pair(uint32_t base_opcode, ಪೂರ್ಣಾಙ್ಕ rt, ಪೂರ್ಣಾಙ್ಕ rt2, ಪೂರ್ಣಾಙ್ಕ rn,
                          int32_t offset, ಪೂರ್ಣಾಙ್ಕ size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    ಯದಿ (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    ಯದಿ (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
ಸ್ಥಿರ ಶೂನ್ಯ gen_b_or_bl(int32_t offset, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    instr |= ARM64_OFFSET26(offset);
    emit_instr32(instr);
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_b(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_B);
}

/* Generate BL (branch with link) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_bl(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_BL);
}

/* Generate BR (branch to register) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_br(ಪೂರ್ಣಾಙ್ಕ rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_blr(ಪೂರ್ಣಾಙ್ಕ rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
ಸ್ಥಿರ ಶೂನ್ಯ gen_ret(ಪೂರ್ಣಾಙ್ಕ rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
ಸ್ಥಿರ ಶೂನ್ಯ gen_b_cond(ಪೂರ್ಣಾಙ್ಕ cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
ಸ್ಥಿರ ಶೂನ್ಯ gen_cbz_or_cbnz(ಪೂರ್ಣಾಙ್ಕ rt, int32_t offset, ಪೂರ್ಣಾಙ್ಕ is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    ಯದಿ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_cbz(ಪೂರ್ಣಾಙ್ಕ rt, int32_t offset, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
ಸ್ಥಿರ ಶೂನ್ಯ gen_cbnz(ಪೂರ್ಣಾಙ್ಕ rt, int32_t offset, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
ಸ್ಥಿರ ಶೂನ್ಯ gen_mov_reg(ಪೂರ್ಣಾಙ್ಕ rd, ಪೂರ್ಣಾಙ್ಕ rm, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    ಯದಿ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_asm_encode_bimm64(uint64_t x)
{
    ಪೂರ್ಣಾಙ್ಕ neg, rep, pos, len;

    neg = x & 1;
    ಯದಿ (neg)
        x = ~x;
    ಯದಿ (!x)
        ಪ್ರತ್ಯಾಗಮ -1;

    ಯದಿ (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    ಅನ್ಯಥಾ ಯದಿ (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    ಅನ್ಯಥಾ ಯದಿ (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    ಅನ್ಯಥಾ ಯದಿ (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    ಅನ್ಯಥಾ ಯದಿ (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    ಅನ್ಯಥಾ
        rep = 64;

    pos = 0;
    ಯದಿ (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    ಯದಿ (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    ಯದಿ (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    ಯದಿ (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    ಯದಿ (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    ಯದಿ (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    ಯದಿ (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    ಯದಿ (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    ಯದಿ (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    ಯದಿ (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    ಯದಿ (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    ಯದಿ (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    ಯದಿ (x)
        ಪ್ರತ್ಯಾಗಮ -1;
    ಯದಿ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    ಪ್ರತ್ಯಾಗಮ ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_logical_imm(uint32_t opcode, ಪೂರ್ಣಾಙ್ಕ rd, ಪೂರ್ಣಾಙ್ಕ rn,
                            uint64_t imm, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    uint32_t instr;
    uint64_t val;
    ಪೂರ್ಣಾಙ್ಕ enc;

    ಯದಿ (is_64bit)
        val = imm;
    ಅನ್ಯಥಾ {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    ಯದಿ (enc < 0) {
        tcc_error("logical immediate out of range");
        ಪ್ರತ್ಯಾಗಮ;
    }

    instr = opcode;
    ಯದಿ (is_64bit)
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
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ constraint_priority(ಧ್ರುವ ವರ್ಣ *str)
{
    ಪೂರ್ಣಾಙ್ಕ priority, c, pr;

    priority = 0;
    ಪ್ರತಿ (;;) {
        c = *str++;
        ಯದಿ (c == '\0')
            ಭಙ್ಗ;
        ವಿಕಲ್ಪ (c) {
        ಪಕ್ಷ '=':
        ಪಕ್ಷ '+':
        ಪಕ್ಷ '&':
            ಅನುವರ್ತ;
        ಪಕ್ಷ 'r':
            pr = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'w':
        ಪಕ್ಷ 'f':
        ಪಕ್ಷ 'x':
        ಪಕ್ಷ 'y':
            pr = 3;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'm':
        ಪಕ್ಷ 'Q':
            pr = 4;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'i':
        ಪಕ್ಷ 'S':
            pr = 5;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'U':
            ಯದಿ (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                ಭಙ್ಗ;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'I':
        ಪಕ್ಷ 'J':
        ಪಕ್ಷ 'K':
        ಪಕ್ಷ 'L':
        ಪಕ್ಷ 'M':
        ಪಕ್ಷ 'N':
        ಪಕ್ಷ 'Z':
            pr = 6;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'n':
            pr = 7;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'g':
            pr = 8;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            ಭಙ್ಗ;
        }
        ಯದಿ (pr > priority)
            priority = pr;
    }
    ಪ್ರತ್ಯಾಗಮ priority;
}

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ *skip_constraint_modifiers(ಧ್ರುವ ವರ್ಣ *p)
{
    ಯಾವತ್ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ಪ್ರತ್ಯಾಗಮ p;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_valid_add_imm(int64_t val)
{
    ಪ್ರತ್ಯಾಗಮ val >= 0 && val <= 4095;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_valid_logical_imm(int64_t val, ಪೂರ್ಣಾಙ್ಕ bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    ಯದಿ (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    ಪ್ರತ್ಯಾಗಮ arm64_asm_encode_bimm64(uval) >= 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    ಯದಿ (uval <= 0xFFFF)
        ಪ್ರತ್ಯಾಗಮ 1;
    ಯದಿ (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        ಪ್ರತ್ಯಾಗಮ 1;
    ಯದಿ (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        ಪ್ರತ್ಯಾಗಮ 1;
    ಯದಿ ((uval & 0xFFFFFFFF00000000ULL) == 0)
        ಪ್ರತ್ಯಾಗಮ 1;

    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_valid_movw_shift(ಪೂರ್ಣಾಙ್ಕ shift, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    ಯದಿ (shift < 0 || (shift & 15))
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (shift > (is_64bit ? 48 : 16))
        ಪ್ರತ್ಯಾಗಮ 0;
    ಪ್ರತ್ಯಾಗಮ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_memory_is_base_only(ಧ್ರುವ SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ r;

    r = sv->r;
    ಯದಿ ((r & VT_VALMASK) == VT_CONST)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ ((r & VT_VALMASK) == VT_LOCAL)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ ((r & VT_VALMASK) == VT_LLOCAL)
        ಪ್ರತ್ಯಾಗಮ 1;
    ಯದಿ (r & VT_LVAL)
        ಪ್ರತ್ಯಾಗಮ (r & VT_VALMASK) < VT_CONST;
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_memory_is_pair_suitable(ಧ್ರುವ SValue *sv)
{
    int64_t offset;

    ಯದಿ (arm64_memory_is_base_only(sv))
        ಪ್ರತ್ಯಾಗಮ 1;
    ಯದಿ ((sv->r & VT_VALMASK) != VT_LOCAL)
        ಪ್ರತ್ಯಾಗಮ 0;

    offset = (int64_t)sv->c.i;
    ಪ್ರತ್ಯಾಗಮ (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_int_reg_is_allocatable(ಪೂರ್ಣಾಙ್ಕ reg)
{
#ifdef TCC_TARGET_PE
    ಪ್ರತ್ಯಾಗಮ reg >= TREG_X0 && reg <= TREG_X17;
#ಅನ್ಯಥಾ
    ಪ್ರತ್ಯಾಗಮ reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_memory_needs_address_reg(ಧ್ರುವ SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    ಯದಿ (!(r & VT_LVAL))
        ಪ್ರತ್ಯಾಗಮ 0;
    ವಿಕಲ್ಪ (r & VT_VALMASK) {
    ಪಕ್ಷ VT_LOCAL:
    ಪಕ್ಷ VT_LLOCAL:
    ಪಕ್ಷ VT_CONST:
        ಪ್ರತ್ಯಾಗಮ 1;
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    ಪೂರ್ಣಾಙ್ಕ reg;

    ಯದಿ (!arm64_memory_needs_address_reg(op->vt))
        ಪ್ರತ್ಯಾಗಮ 1;

    ಪ್ರತಿ (reg = 0; reg < 31; reg++) {
        ಯದಿ (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            ಪ್ರತ್ಯಾಗಮ 1;
        }
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_load_memory_operand_base(ಪೂರ್ಣಾಙ್ಕ reg, SValue *sv)
{
    SValue base;
    ಪೂರ್ಣಾಙ್ಕ rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    ಯದಿ (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } ಅನ್ಯಥಾ ಯದಿ (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } ಅನ್ಯಥಾ {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ operand_is_sp(ಧ್ರುವ Operand *op)
{
    ಪ್ರತ್ಯಾಗಮ op->reg_tok == TOK_ASM_sp;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ parse_sysreg_name(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಧ್ರುವ ವರ್ಣ *name;

    ಯದಿ (t < TOK_IDENT)
        ಪ್ರತ್ಯಾಗಮ -1;
    name = get_tok_str(t, ರಿಕ್ತ);
    ಯದಿ (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        ಪ್ರತ್ಯಾಗಮ 1;
    ಪ್ರತ್ಯಾಗಮ -1;
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_mrs(ಪೂರ್ಣಾಙ್ಕ rt, ಪೂರ್ಣಾಙ್ಕ sysreg)
{
    uint32_t instr;

    ವಿಕಲ್ಪ (sysreg) {
        ಪಕ್ಷ 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            ಭಙ್ಗ;
        ಪಕ್ಷ 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("unsupported system register");
            ಪ್ರತ್ಯಾಗಮ;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_msr(ಪೂರ್ಣಾಙ್ಕ rt, ಪೂರ್ಣಾಙ್ಕ sysreg)
{
    uint32_t instr;

    ವಿಕಲ್ಪ (sysreg) {
        ಪಕ್ಷ 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            ಭಙ್ಗ;
        ಪಕ್ಷ 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("unsupported system register");
            ಪ್ರತ್ಯಾಗಮ;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
ಸ್ಥಿರ ಶೂನ್ಯ gen_nop(ಶೂನ್ಯ)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_shift(ಪೂರ್ಣಾಙ್ಕ rd, ಪೂರ್ಣಾಙ್ಕ rn, ಪೂರ್ಣಾಙ್ಕ rm_or_imm, ಪೂರ್ಣಾಙ್ಕ shift_type, ಪೂರ್ಣಾಙ್ಕ is_imm, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    uint32_t instr;
    ಪೂರ್ಣಾಙ್ಕ width = is_64bit ? 64 : 32;

    ಯದಿ (is_imm) {
        /* Shift by immediate */
        ವಿಕಲ್ಪ (shift_type) {
            ಪಕ್ಷ 0: /* LSL - UBFM alias */
                ಯದಿ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ಪ್ರತ್ಯಾಗಮ;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                ಭಙ್ಗ;
            ಪಕ್ಷ 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                ಯದಿ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ಪ್ರತ್ಯಾಗಮ;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                ಭಙ್ಗ;
            ಪಕ್ಷ 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                ಯದಿ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ಪ್ರತ್ಯಾಗಮ;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                ಭಙ್ಗ;
            ಪಕ್ಷ 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                ಯದಿ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    ಪ್ರತ್ಯಾಗಮ;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                ಪ್ರತ್ಯಾಗಮ;
            ಸ್ವಭಾವ:
                tcc_error("unknown shift type");
                ಪ್ರತ್ಯಾಗಮ;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } ಅನ್ಯಥಾ {
        /* Shift by register */
        ವಿಕಲ್ಪ (shift_type) {
            ಪಕ್ಷ 0: /* LSL */
                instr = ARM64_LSL_REG;
                ಭಙ್ಗ;
            ಪಕ್ಷ 1: /* LSR */
                instr = ARM64_LSR_REG;
                ಭಙ್ಗ;
            ಪಕ್ಷ 2: /* ASR */
                instr = ARM64_ASR_REG;
                ಭಙ್ಗ;
            ಪಕ್ಷ 3: /* ROR */
                instr = ARM64_ROR_REG;
                ಭಙ್ಗ;
            ಸ್ವಭಾವ:
                tcc_error("unknown shift type");
                ಪ್ರತ್ಯಾಗಮ;
        }
        ಯದಿ (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
ಸ್ಥಿರ ಶೂನ್ಯ asm_shift(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand op1, op2, op3;
    ಪೂರ್ಣಾಙ್ಕ rd, rn, shift_amount;
    ಪೂರ್ಣಾಙ್ಕ shift_type;
    ಪೂರ್ಣಾಙ್ಕ is_64bit = 1;

    ವಿಕಲ್ಪ (token) {
        ಪಕ್ಷ TOK_ASM_lsl:
            shift_type = 0;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_lsr:
            shift_type = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_asr:
            shift_type = 2;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_ror:
            shift_type = 3;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("unknown shift instruction");
            ಪ್ರತ್ಯಾಗಮ;
    }

    parse_operand(s1, &op1);
    ಯದಿ (tok == ',') next();
    parse_operand(s1, &op2);

    ಯದಿ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ಪ್ರತ್ಯಾಗಮ;
    }
    ಯದಿ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ಪ್ರತ್ಯಾಗಮ;
    }

    rd = op1.reg;
    rn = op2.reg;

    ಯದಿ (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ಯದಿ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ಪ್ರತ್ಯಾಗಮ;
        }
        ಯದಿ (op3.type & OP_REG) {
            ಯದಿ (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ಪ್ರತ್ಯಾಗಮ;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } ಅನ್ಯಥಾ ಯದಿ (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } ಅನ್ಯಥಾ {
            tcc_error("shift requires immediate or register operand");
        }
    } ಅನ್ಯಥಾ {
        tcc_error("shift requires immediate or register operand");
        ಪ್ರತ್ಯಾಗಮ;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_barrier(ಪೂರ್ಣಾಙ್ಕ barrier_type, ಪೂರ್ಣಾಙ್ಕ option)
{
    uint32_t instr;

    ವಿಕಲ್ಪ (barrier_type) {
        ಪಕ್ಷ 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            ಭಙ್ಗ;
        ಪಕ್ಷ 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            ಭಙ್ಗ;
        ಪಕ್ಷ 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("unknown barrier type");
            ಪ್ರತ್ಯಾಗಮ;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
ಸ್ಥಿರ ಶೂನ್ಯ asm_barrier(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    ಪೂರ್ಣಾಙ್ಕ barrier_type, option;
    Operand op;

    ವಿಕಲ್ಪ (token) {
        ಪಕ್ಷ TOK_ASM_isb:
            barrier_type = 0;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_dsb:
            barrier_type = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_dmb:
            barrier_type = 2;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("unknown barrier instruction");
            ಪ್ರತ್ಯಾಗಮ;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    ಯದಿ (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        ಯದಿ (option >= 0) {
            next();
        } ಅನ್ಯಥಾ {
            parse_operand(s1, &op);
            ಯದಿ (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                ಪ್ರತ್ಯಾಗಮ;
            }
            ಯದಿ (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                ಪ್ರತ್ಯಾಗಮ;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
ಸ್ಥಿರ ಶೂನ್ಯ gen_mov_imm(ಪೂರ್ಣಾಙ್ಕ rd, uint64_t imm, ಪೂರ್ಣಾಙ್ಕ is_64bit)
{
    uint16_t hw;
    ಪೂರ್ಣಾಙ್ಕ i, first = 1;

    ಪ್ರತಿ (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        ಯದಿ (hw != 0 || i == 0) {
            ಯದಿ (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } ಅನ್ಯಥಾ {
                gen_movk(rd, hw, i, is_64bit);
            }
        } ಅನ್ಯಥಾ ಯದಿ (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
ಸ್ಥಿರ ಶೂನ್ಯ asm_mov(TCCState *s1)
{
    Operand op1, op2;
    ಪೂರ್ಣಾಙ್ಕ rd, rn;
    ಪೂರ್ಣಾಙ್ಕ is_64bit;

    parse_operand(s1, &op1);
    ಯದಿ (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    ಯದಿ (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        ಯದಿ (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            ಪ್ರತ್ಯಾಗಮ;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } ಅನ್ಯಥಾ ಯದಿ (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        ಯದಿ (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        ಅನ್ಯಥಾ
            gen_mov_reg(rd, rn, is_64bit);
    } ಅನ್ಯಥಾ {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
ಸ್ಥಿರ ಶೂನ್ಯ asm_data_proc(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand op1, op2, op3;
    ಪೂರ್ಣಾಙ್ಕ rd, rn, rm;
    ಪೂರ್ಣಾಙ್ಕ is_64bit = 1;
    uint32_t opcode;

    ವಿಕಲ್ಪ (token) {
        ಪಕ್ಷ TOK_ASM_add:
        ಪಕ್ಷ TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_sub:
        ಪಕ್ಷ TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_and:
        ಪಕ್ಷ TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("unsupported data processing instruction");
            ಪ್ರತ್ಯಾಗಮ;
    }

    parse_operand(s1, &op1);
    ಯದಿ (tok == ',') next();
    parse_operand(s1, &op2);

    ಯದಿ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ಪ್ರತ್ಯಾಗಮ;
    }
    ಯದಿ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ಪ್ರತ್ಯಾಗಮ;
    }

    rd = op1.reg;
    rn = op2.reg;

    ಯದಿ (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ಯದಿ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ಪ್ರತ್ಯಾಗಮ;
        }
        ಯದಿ (op3.type & OP_IM) {
            ಯದಿ (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            ಅನ್ಯಥಾ ಯದಿ (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            ಅನ್ಯಥಾ ಯದಿ (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            ಅನ್ಯಥಾ ಯದಿ (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            ಅನ್ಯಥಾ ಯದಿ (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            ಅನ್ಯಥಾ ಯದಿ (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            ಅನ್ಯಥಾ
                tcc_error("immediate operand not valid for this instruction");
        } ಅನ್ಯಥಾ {
            ಯದಿ (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                ಪ್ರತ್ಯಾಗಮ;
            }
            rm = op3.reg;
            ಯದಿ (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ಪ್ರತ್ಯಾಗಮ;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } ಅನ್ಯಥಾ ಯದಿ (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } ಅನ್ಯಥಾ {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
ಸ್ಥಿರ ಶೂನ್ಯ asm_ldst(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand op1, op2;
    ಪೂರ್ಣಾಙ್ಕ rt, rn;
    int32_t offset = 0;
    ಪೂರ್ಣಾಙ್ಕ size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    ಯದಿ (tok == ',') next();
    parse_operand(s1, &op2);

    ಯದಿ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ಪ್ರತ್ಯಾಗಮ;
    }
    ಯದಿ (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        ಪ್ರತ್ಯಾಗಮ;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    ವಿಕಲ್ಪ (token) {
        ಪಕ್ಷ TOK_ASM_ldr:
            ಯದಿ (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } ಅನ್ಯಥಾ ಯದಿ (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } ಅನ್ಯಥಾ ಯದಿ (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } ಅನ್ಯಥಾ {
                tcc_error("ldr requires a w, x, or d register");
                ಪ್ರತ್ಯಾಗಮ;
            }
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_str:
            ಯದಿ (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } ಅನ್ಯಥಾ ಯದಿ (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } ಅನ್ಯಥಾ ಯದಿ (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } ಅನ್ಯಥಾ {
                tcc_error("str requires a w, x, or d register");
                ಪ್ರತ್ಯಾಗಮ;
            }
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("unsupported load/store instruction");
            ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ldst_pair(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    ಪೂರ್ಣಾಙ್ಕ size_log2 = 3;

    parse_operand(s1, &op1);
    ಯದಿ (tok == ',')
        next();
    parse_operand(s1, &op2);
    ಯದಿ (tok == ',')
        next();
    parse_operand(s1, &op3);

    ಯದಿ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ಪ್ರತ್ಯಾಗಮ;
    }
    ಯದಿ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ಪ್ರತ್ಯಾಗಮ;
    }
    ಯದಿ (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    ಯದಿ ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        ಯದಿ (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } ಅನ್ಯಥಾ {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } ಅನ್ಯಥಾ ಯದಿ ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        ಯದಿ (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } ಅನ್ಯಥಾ {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } ಅನ್ಯಥಾ {
        tcc_error("stp/ldp requires matching x or d registers");
        ಪ್ರತ್ಯಾಗಮ;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_sysreg(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand op;
    ಪೂರ್ಣಾಙ್ಕ sysreg;

    ಯದಿ (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        ಯದಿ (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        ಯದಿ (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        ಪ್ರತ್ಯಾಗಮ;
    }

    sysreg = parse_sysreg_name(tok);
    ಯದಿ (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    ಯದಿ (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ get_branch_condition(ಪೂರ್ಣಾಙ್ಕ branch_token)
{
    ಪೂರ್ಣಾಙ್ಕ cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    ವಿಕಲ್ಪ (branch_token) {
        ಪಕ್ಷ TOK_ASM_beq: cond_token = TOK_ASM_eq; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bne: cond_token = TOK_ASM_ne; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bcs:
        ಪಕ್ಷ TOK_ASM_bhs: cond_token = TOK_ASM_cs; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bcc:
        ಪಕ್ಷ TOK_ASM_blo: cond_token = TOK_ASM_cc; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bmi: cond_token = TOK_ASM_mi; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bpl: cond_token = TOK_ASM_pl; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bvs: cond_token = TOK_ASM_vs; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bvc: cond_token = TOK_ASM_vc; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bhi: cond_token = TOK_ASM_hi; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bls: cond_token = TOK_ASM_ls; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bge: cond_token = TOK_ASM_ge; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_blt: cond_token = TOK_ASM_lt; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_bgt: cond_token = TOK_ASM_gt; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_ble: cond_token = TOK_ASM_le; ಭಙ್ಗ;
        ಸ್ವಭಾವ: ಪ್ರತ್ಯಾಗಮ -1;
    }

    ಪ್ರತ್ಯಾಗಮ parse_condition(cond_token);
}

/* Handle branch instructions */
ಸ್ಥಿರ ಶೂನ್ಯ asm_branch(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand op;
    ಪೂರ್ಣಾಙ್ಕ cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    ಯದಿ (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    ಅನ್ಯಥಾ
        parse_ಅಭಿವ್ಯಕ್ತಿ_operand(s1, &op);

    ಯದಿ (op.type & OP_IM) {
        sym = op.e.sym;
        ಯದಿ (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            ಯದಿ (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } ಅನ್ಯಥಾ {
                ವಿಕಲ್ಪ (token) {
                    ಪಕ್ಷ TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        ಭಙ್ಗ;
                    ಪಕ್ಷ TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        ಭಙ್ಗ;
                    ಸ್ವಭಾವ:
                        tcc_error("unsupported branch");
                }
            }
        } ಅನ್ಯಥಾ {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            ಯದಿ (cond >= 0) {
                gen_b_cond(cond, offset);
            } ಅನ್ಯಥಾ {
                ವಿಕಲ್ಪ (token) {
                    ಪಕ್ಷ TOK_ASM_b:
                        gen_b(offset);
                        ಭಙ್ಗ;
                    ಪಕ್ಷ TOK_ASM_bl:
                        gen_bl(offset);
                        ಭಙ್ಗ;
                    ಸ್ವಭಾವ:
                        tcc_error("unsupported branch");
                }
            }
        }
    } ಅನ್ಯಥಾ ಯದಿ (op.type & OP_REG) {
        ವಿಕಲ್ಪ (token) {
            ಪಕ್ಷ TOK_ASM_br:
                gen_br(op.reg);
                ಭಙ್ಗ;
            ಪಕ್ಷ TOK_ASM_blr:
                gen_blr(op.reg);
                ಭಙ್ಗ;
            ಪಕ್ಷ TOK_ASM_ret:
                gen_ret(op.reg);
                ಭಙ್ಗ;
            ಸ್ವಭಾವ:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
ಸ್ಥಿರ ಶೂನ್ಯ asm_cb(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand op1, op2;
    ಪೂರ್ಣಾಙ್ಕ rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    ಯದಿ (tok == ',') next();
    parse_ಅಭಿವ್ಯಕ್ತಿ_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    ಯದಿ (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        ಯದಿ (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } ಅನ್ಯಥಾ {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } ಅನ್ಯಥಾ {
        offset = (int32_t)op2.e.v - ind;
        ಯದಿ (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        ಅನ್ಯಥಾ
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
ಸ್ಥಿರ ಶೂನ್ಯ asm_move_wide(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand op1, op2;
    ಪೂರ್ಣಾಙ್ಕ rd, is_64bit = 1;
    uint16_t imm;
    ಪೂರ್ಣಾಙ್ಕ shift = 0;

    parse_operand(s1, &op1);
    ಯದಿ (tok == ',') next();
    parse_operand(s1, &op2);

    ಯದಿ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ಪ್ರತ್ಯಾಗಮ;
    }
    ಯದಿ (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        ಪ್ರತ್ಯಾಗಮ;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    ಯದಿ ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        ಪ್ರತ್ಯಾಗಮ;
    }
    imm = op2.e.v;

    ಯದಿ (tok == ',') {
        next();
        ಯದಿ (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            ಪ್ರತ್ಯಾಗಮ;
        }
            next();
            ಯದಿ (tok == '#') next();
            asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op2.e);
        ಯದಿ (op2.e.sym || !is_valid_movw_shift((ಪೂರ್ಣಾಙ್ಕ)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            ಪ್ರತ್ಯಾಗಮ;
        }
            shift = (ಪೂರ್ಣಾಙ್ಕ)op2.e.v / 16;
        }

    ವಿಕಲ್ಪ (token) {
        ಪಕ್ಷ TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ opcode)
{
    ವಿಕಲ್ಪ (opcode) {
        ಪಕ್ಷ TOK_ASM_add:
        ಪಕ್ಷ TOK_ASM_adds:
        ಪಕ್ಷ TOK_ASM_sub:
        ಪಕ್ಷ TOK_ASM_subs:
        ಪಕ್ಷ TOK_ASM_and:
        ಪಕ್ಷ TOK_ASM_ands:
        ಪಕ್ಷ TOK_ASM_orr:
        ಪಕ್ಷ TOK_ASM_eor:
        ಪಕ್ಷ TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_lsl:
        ಪಕ್ಷ TOK_ASM_lsr:
        ಪಕ್ಷ TOK_ASM_asr:
        ಪಕ್ಷ TOK_ASM_ror:
            asm_shift(s1, opcode);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_ldr:
        ಪಕ್ಷ TOK_ASM_ldrb:
        ಪಕ್ಷ TOK_ASM_ldrh:
        ಪಕ್ಷ TOK_ASM_str:
        ಪಕ್ಷ TOK_ASM_strb:
        ಪಕ್ಷ TOK_ASM_strh:
            asm_ldst(s1, opcode);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_ldp:
        ಪಕ್ಷ TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_b:
        ಪಕ್ಷ TOK_ASM_bl:
        ಪಕ್ಷ TOK_ASM_br:
        ಪಕ್ಷ TOK_ASM_blr:
        ಪಕ್ಷ TOK_ASM_ret:
        ಪಕ್ಷ TOK_ASM_beq:
        ಪಕ್ಷ TOK_ASM_bne:
        ಪಕ್ಷ TOK_ASM_bcs:
        ಪಕ್ಷ TOK_ASM_bhs:
        ಪಕ್ಷ TOK_ASM_bcc:
        ಪಕ್ಷ TOK_ASM_blo:
        ಪಕ್ಷ TOK_ASM_bmi:
        ಪಕ್ಷ TOK_ASM_bpl:
        ಪಕ್ಷ TOK_ASM_bvs:
        ಪಕ್ಷ TOK_ASM_bvc:
        ಪಕ್ಷ TOK_ASM_bhi:
        ಪಕ್ಷ TOK_ASM_bls:
        ಪಕ್ಷ TOK_ASM_bge:
        ಪಕ್ಷ TOK_ASM_blt:
        ಪಕ್ಷ TOK_ASM_bgt:
        ಪಕ್ಷ TOK_ASM_ble:
            asm_branch(s1, opcode);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_cbz:
        ಪಕ್ಷ TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_movz:
        ಪಕ್ಷ TOK_ASM_movn:
        ಪಕ್ಷ TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_mrs:
        ಪಕ್ಷ TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_isb:
        ಪಕ್ಷ TOK_ASM_dsb:
        ಪಕ್ಷ TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_nop:
            gen_nop();
            ಭಙ್ಗ;

        ಸ್ವಭಾವ:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, ರಿಕ್ತ));
            ಭಙ್ಗ;
    }
}

/* Substitute assembler operand */
ST_FUNC ಶೂನ್ಯ subst_asm_operand(CString *add_str, SValue *sv, ಪೂರ್ಣಾಙ್ಕ modifier)
{
    ಪೂರ್ಣಾಙ್ಕ r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    ಯದಿ ((r & VT_VALMASK) == VT_CONST) {
        ಯದಿ ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            ಪ್ರತ್ಯಾಗಮ;
        }
        ಯದಿ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        ಯದಿ (r & VT_SYM) {
            ಧ್ರುವ ವರ್ಣ *name = get_tok_str(sv->sym->v, ರಿಕ್ತ);
            ಯದಿ (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            ಯದಿ (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            ಯದಿ ((uint32_t) sv->c.i == 0)
                ಗಚ್ಛ no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        ಯದಿ (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } ಅನ್ಯಥಾ ಯದಿ (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } ಅನ್ಯಥಾ {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } ಅನ್ಯಥಾ ಯದಿ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (ಪೂರ್ಣಾಙ್ಕ) sv->c.i);
    } ಅನ್ಯಥಾ ಯದಿ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ಯದಿ (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } ಅನ್ಯಥಾ {
        /* register case */
        reg = r & VT_VALMASK;
        ಯದಿ (reg >= VT_CONST)
            tcc_internal_error("");

        ಯದಿ (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            ಯದಿ (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            ವಿಕಲ್ಪ (modifier) {
            ಪಕ್ಷ 'b':
            ಪಕ್ಷ 'h':
            ಪಕ್ಷ 's':
            ಪಕ್ಷ 'd':
            ಪಕ್ಷ 'q':
            ಪಕ್ಷ 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                ಪ್ರತ್ಯಾಗಮ;
            ಸ್ವಭಾವ:
                tcc_error("invalid operand modifier for SIMD/FP register");
                ಪ್ರತ್ಯಾಗಮ;
            }
        }

        /* choose register operand size */
        ಯದಿ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        ಅನ್ಯಥಾ ಯದಿ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        ಅನ್ಯಥಾ ಯದಿ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        ಅನ್ಯಥಾ
            size = 4;

        ಯದಿ (modifier == 'x') {
            size = 8;
        } ಅನ್ಯಥಾ ಯದಿ (modifier == 'w' || modifier == 'k') {
            size = 4;
        } ಅನ್ಯಥಾ ಯದಿ (modifier == 'b') {
            size = 1;
        } ಅನ್ಯಥಾ ಯದಿ (modifier == 'h') {
            size = 2;
        } ಅನ್ಯಥಾ ಯದಿ (modifier == 'q') {
            size = 8;
        }

        ಯದಿ (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } ಅನ್ಯಥಾ {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC ಶೂನ್ಯ asm_gen_code(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands,
                          ಪೂರ್ಣಾಙ್ಕ nb_outputs, ಪೂರ್ಣಾಙ್ಕ is_output,
                          uint8_t *clobber_regs,
                          ಪೂರ್ಣಾಙ್ಕ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ಪೂರ್ಣಾಙ್ಕ i, reg, saved_ಎಣಿಕೆ, ರಾಶಿ_size, ರಾಶಿ_off;
    ಪೂರ್ಣಾಙ್ಕ saved_regs[12];
    ಸ್ಥಿರ ಧ್ರುವ uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, ಪರಿಮಾಣ(regs_allocated));
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ಯದಿ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_ಎಣಿಕೆ = 0;
    ಪ್ರತಿ (i = 0; i < ಪರಿಮಾಣ(reg_saved) / ಪರಿಮಾಣ(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ಯದಿ (regs_allocated[reg])
            saved_regs[saved_ಎಣಿಕೆ++] = reg;
    }
    ರಾಶಿ_size = ((saved_ಎಣಿಕೆ + 1) / 2) * 16;

    ಯದಿ (!is_output) {
        ಯದಿ (saved_ಎಣಿಕೆ > 0) {
            gen_sub_imm(31, 31, ರಾಶಿ_size, 1, 0);

            ಪ್ರತಿ (i = ರಾಶಿ_off = 0; i < saved_ಎಣಿಕೆ; ) {
                ಯದಿ (i + 1 < saved_ಎಣಿಕೆ) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ರಾಶಿ_off, 3);
                    ರಾಶಿ_off += 16;
                    i += 2;
                } ಅನ್ಯಥಾ {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 ರಾಶಿ_off, 3);
                    i++;
                }
            }
        }

        ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ಯದಿ (op->reg >= 0) {
                ಯದಿ (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } ಅನ್ಯಥಾ ಯದಿ (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } ಅನ್ಯಥಾ {
        ಪ್ರತಿ (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            ಯದಿ (op->reg >= 0) {
                ಯದಿ (op->is_memory)
                    ಅನುವರ್ತ;
                ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ಯದಿ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } ಅನ್ಯಥಾ {
                    store(op->reg, op->vt);
                }
            }
        }

        ಯದಿ (saved_ಎಣಿಕೆ > 0) {
            ಪ್ರತಿ (i = ರಾಶಿ_off = 0; i < saved_ಎಣಿಕೆ; ) {
                ಯದಿ (i + 1 < saved_ಎಣಿಕೆ) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ರಾಶಿ_off, 3);
                    ರಾಶಿ_off += 16;
                    i += 2;
                } ಅನ್ಯಥಾ {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 ರಾಶಿ_off, 3);
                    i++;
                }
            }
            gen_add_imm(31, 31, ರಾಶಿ_size, 1, 0);
        }
    }
}

ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands,
                                    ಪೂರ್ಣಾಙ್ಕ nb_operands, ಪೂರ್ಣಾಙ್ಕ nb_outputs,
                                    ಧ್ರುವ uint8_t *clobber_regs,
                                    ಪೂರ್ಣಾಙ್ಕ *pout_reg)
{
    ASMOperand *op;
    ಪೂರ್ಣಾಙ್ಕ sorted_op[MAX_ASM_OPERANDS];
    ಪೂರ್ಣಾಙ್ಕ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ಧ್ರುವ ವರ್ಣ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ಒಳಹರಿವು_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ಯದಿ (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, ರಿಕ್ತ);
            ಯದಿ ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            ಯದಿ (operands[k].ಒಳಹರಿವು_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ಒಳಹರಿವು_index = i;
            op->priority = 5;
        } ಅನ್ಯಥಾ ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } ಅನ್ಯಥಾ {
            op->priority = constraint_priority(str);
        }
    }

    ಪ್ರತಿ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ಪ್ರತಿ (i = 0; i < nb_operands - 1; i++) {
        ಪ್ರತಿ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            ಯದಿ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ಪ್ರತಿ (i = 0; i < NB_ASM_REGS; i++) {
        ಯದಿ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        ಅನ್ಯಥಾ
            regs_allocated[i] = 0;
    }

    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        ಯದಿ (op->ref_index >= 0)
            ಅನುವರ್ತ;
        ಯದಿ (op->ಒಳಹರಿವು_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } ಅನ್ಯಥಾ ಯದಿ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } ಅನ್ಯಥಾ {
            reg_mask = REG_IN_MASK;
        }
        ಯದಿ (op->reg >= 0) {
            ಯದಿ (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            ಗಚ್ಛ reg_found;
        }
    try_next:
        c = *str++;
        ವಿಕಲ್ಪ (c) {
        ಪಕ್ಷ '=':
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ '+':
            op->is_rw = 1;
        ಪಕ್ಷ '&':
            ಯದಿ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ 'r':
            ಪ್ರತಿ (reg = 0; reg < 31; reg++) {
                ಯದಿ (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    ಗಚ್ಛ reg_found;
            }
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ 'w':
        ಪಕ್ಷ 'f':
            ಪ್ರತಿ (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                ಯದಿ (!is_reg_allocated(reg))
                    ಗಚ್ಛ reg_found;
            }
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ 'x':
        ಪಕ್ಷ 'y':
            ಪ್ರತಿ (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                ಯದಿ (!is_reg_allocated(reg))
                    ಗಚ್ಛ reg_found;
            }
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ 'm':
        ಪಕ್ಷ 'g':
            ಯದಿ (j < nb_outputs || c == 'm') {
                ಯದಿ (!arm64_prepare_memory_operand(op, regs_allocated))
                    ಗಚ್ಛ try_next;
            }
            ಭಙ್ಗ;
        ಪಕ್ಷ 'Q':
            ಯದಿ (!arm64_memory_is_base_only(op->vt))
                ಗಚ್ಛ try_next;
            ಯದಿ (!arm64_prepare_memory_operand(op, regs_allocated))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'S':
            ಯದಿ ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'U':
            ಯದಿ (str[0] != 'm' || str[1] != 'p')
                ಗಚ್ಛ try_next;
            str += 2;
            ಯದಿ (!arm64_memory_is_pair_suitable(op->vt))
                ಗಚ್ಛ try_next;
            ಯದಿ (!arm64_prepare_memory_operand(op, regs_allocated))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'i':
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'I':
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಯದಿ (!is_valid_add_imm(op->vt->c.i))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'J':
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಯದಿ (!is_valid_add_imm(-op->vt->c.i))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'K':
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಯದಿ (!is_valid_logical_imm(op->vt->c.i, 32))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'L':
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಯದಿ (!is_valid_logical_imm(op->vt->c.i, 64))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'M':
        ಪಕ್ಷ 'N':
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಯದಿ (!is_valid_movw_imm(op->vt->c.i))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'Z':
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಯದಿ (op->vt->c.i != 0)
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'n':
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            ಭಙ್ಗ;
        }
        ಯದಿ (op->ಒಳಹರಿವು_index >= 0) {
            operands[op->ಒಳಹರಿವು_index].reg = op->reg;
            operands[op->ಒಳಹರಿವು_index].is_llong = op->is_llong;
        }
        ಅನುವರ್ತ;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        ಯದಿ (op->ಒಳಹರಿವು_index >= 0) {
            operands[op->ಒಳಹರಿವು_index].reg = op->reg;
            operands[op->ಒಳಹರಿವು_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ಯದಿ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            ಪ್ರತಿ (reg = 0; reg < 31; reg++) {
                ಯದಿ (!(regs_allocated[reg] & REG_OUT_MASK))
                    ಗಚ್ಛ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            ಭಙ್ಗ;
        }
    }
}

/* Handle clobber list */
ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಧ್ರುವ ವರ್ಣ *str)
{
    ಪೂರ್ಣಾಙ್ಕ reg;

    ಯದಿ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ಪ್ರತ್ಯಾಗಮ;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    ಯದಿ (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ asm_parse_regvar(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪ್ರತ್ಯಾಗಮ arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
