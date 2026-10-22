/*************************************************************/
/*
 *  ARM64 (AArch64) assembler for TCC
 *
 *  Based on ARM64 Architecture Reference Manual
 *  Supports AArch64 assembler parsing and extended inline asm
 *  with operands, constraints, and clobbers.
 */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

#ವ್ಯಾಖ್ಯಾನಿಸು CONFIG_TCC_ASM
/* 32 general purpose + 32 SIMD/FP registers */
#ವ್ಯಾಖ್ಯಾನಿಸು NB_ASM_REGS 64

ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಂಕ c);

/*************************************************************/
#ಇಲ್ಲದಿದ್ದರೆ
/*************************************************************/

#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

/* Register type flags */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_X     0x01  /* 64-bit general purpose */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_W     0x02  /* 32-bit general purpose */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_V     0x04  /* 128-bit SIMD */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_D     0x08  /* 64-bit FP */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_S     0x10  /* 32-bit FP */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_H     0x20  /* 16-bit FP */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
ಎಣಿಕೆ {
    OPT_REG,
    OPT_IM,
    OPT_ADDR,
    OPT_COND,
};

#ವ್ಯಾಖ್ಯಾನಿಸು OP_REG     (1 << OPT_REG)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_IM      (1 << OPT_IM)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_ADDR    (1 << OPT_ADDR)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_COND    (1 << OPT_COND)

/* Register allocation masks */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಹೊರಹೋಗು_ಮುಖವಾಡ 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಒಳ_ಮುಖವಾಡ  0x02

#ವ್ಯಾಖ್ಯಾನಿಸು is_reg_allocated(reg) (regs_allocated[reg] & reg_ಮುಖವಾಡ)

/* ARM64 register constants */
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X0  0
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X1  1
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X2  2
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X3  3
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X4  4
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X5  5
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X6  6
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X7  7
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X8  8
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X9  9
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X10 10
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X11 11
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X12 12
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X13 13
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X14 14
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X15 15
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X16 16
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X17 17
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X18 18
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X19 19
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X20 20
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X21 21
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X22 22
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X23 23
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X24 24
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X25 25
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X26 26
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X27 27
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X28 28
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X29 29
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_X30 30
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_SP  31

#ವ್ಯಾಖ್ಯಾನಿಸು ARM64_FREG_ತಳ 20
#ವ್ಯಾಖ್ಯಾನಿಸು ARM64_FREG_ಕೊನೆಯ (ARM64_FREG_ತಳ + 7)

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಕಾರ್ಯಾಂಶ {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t ಸರಿಸು;
    uint8_t addr_ಬಹುಲಕ;
    ಪೂರ್ಣಾಂಕ reg_tok;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
} ಕಾರ್ಯಾಂಶ;

ಎಣಿಕೆ {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
ಸ್ಥಿರ ಶೂನ್ಯ parse_addr_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op);

/* XXX: make it faster ? */
ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಂಕ c)
{
    ಪೂರ್ಣಾಂಕ ind1;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    ind1 = ind + 1;
    ಆದರೆ (ind1 > cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_allocated)
        section_realloc(cur_ಪಠ್ಯ_section, ind1);
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind] = c;
    ind = ind1;
}

ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಂಕ c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಂಕ c)
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
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (ind + 4 > cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_allocated)
        section_realloc(cur_ಪಠ್ಯ_section, ind + 4);
    write32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_parse_asm_reg(ಪೂರ್ಣಾಂಕ t)
{
    /* X registers (64-bit) */
    ಆದರೆ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ಹಿಂತಿರುಗಿ t - TOK_ASM_x0;
    /* W registers (32-bit) */
    ಆದರೆ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ಹಿಂತಿರುಗಿ t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    ಆದರೆ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ಹಿಂತಿರುಗಿ (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    ಆದರೆ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ಹಿಂತಿರುಗಿ (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    ಆದರೆ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ಹಿಂತಿರುಗಿ (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    ಆದರೆ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ಹಿಂತಿರುಗಿ (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    ಆದರೆ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ಹಿಂತಿರುಗಿ (t - TOK_ASM_b0) + 32;
    /* Special registers */
    ಆದರೆ (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        ಹಿಂತಿರುಗಿ 31;  /* SP/ZR encoded as 31 */
    ಹಿಂತಿರುಗಿ -1;
}

/* Get register type from token */
ಸ್ಥಿರ uint8_t get_reg_type(ಪೂರ್ಣಾಂಕ t)
{
    ಆದರೆ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ಹಿಂತಿರುಗಿ REG_X;
    ಆದರೆ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ಹಿಂತಿರುಗಿ REG_W;
    ಆದರೆ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ಹಿಂತಿರುಗಿ REG_V;
    ಆದರೆ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ಹಿಂತಿರುಗಿ REG_D;
    ಆದರೆ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ಹಿಂತಿರುಗಿ REG_S;
    ಆದರೆ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ಹಿಂತಿರುಗಿ REG_H;
    ಆದರೆ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ಹಿಂತಿರುಗಿ REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    ಆದರೆ (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        ಹಿಂತಿರುಗಿ REG_X;
    ಆದರೆ (t == TOK_ASM_wzr)
        ಹಿಂತಿರುಗಿ REG_W;
    ಹಿಂತಿರುಗಿ REG_X;
}

/* Parse condition code */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ parse_condition(ಪೂರ್ಣಾಂಕ t)
{
    ಆಯ್ಕೆ (t) {
        ಸ್ಥಿತಿ TOK_ASM_eq: ಹಿಂತಿರುಗಿ 0;
        ಸ್ಥಿತಿ TOK_ASM_ne: ಹಿಂತಿರುಗಿ 1;
        ಸ್ಥಿತಿ TOK_ASM_cs:
        ಸ್ಥಿತಿ TOK_ASM_hs: ಹಿಂತಿರುಗಿ 2;
        ಸ್ಥಿತಿ TOK_ASM_cc:
        ಸ್ಥಿತಿ TOK_ASM_lo: ಹಿಂತಿರುಗಿ 3;
        ಸ್ಥಿತಿ TOK_ASM_mi: ಹಿಂತಿರುಗಿ 4;
        ಸ್ಥಿತಿ TOK_ASM_pl: ಹಿಂತಿರುಗಿ 5;
        ಸ್ಥಿತಿ TOK_ASM_vs: ಹಿಂತಿರುಗಿ 6;
        ಸ್ಥಿತಿ TOK_ASM_vc: ಹಿಂತಿರುಗಿ 7;
        ಸ್ಥಿತಿ TOK_ASM_hi: ಹಿಂತಿರುಗಿ 8;
        ಸ್ಥಿತಿ TOK_ASM_ls: ಹಿಂತಿರುಗಿ 9;
        ಸ್ಥಿತಿ TOK_ASM_ge: ಹಿಂತಿರುಗಿ 10;
        ಸ್ಥಿತಿ TOK_ASM_lt: ಹಿಂತಿರುಗಿ 11;
        ಸ್ಥಿತಿ TOK_ASM_gt: ಹಿಂತಿರುಗಿ 12;
        ಸ್ಥಿತಿ TOK_ASM_le: ಹಿಂತಿರುಗಿ 13;
        ಸ್ಥಿತಿ TOK_ASM_al: ಹಿಂತಿರುಗಿ 14;
        ಪೂರ್ವನಿಯೋಜಿತ: ಹಿಂತಿರುಗಿ -1;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ parse_barrier_option_name(ಪೂರ್ಣಾಂಕ t)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;

    ಆದರೆ (t < TOK_IDENT)
        ಹಿಂತಿರುಗಿ -1;
    name = get_tok_str(t, ಖಾಲಿ);
    ಆದರೆ (!strcmp(name, "oshld")) ಹಿಂತಿರುಗಿ 0x1;
    ಆದರೆ (!strcmp(name, "oshst")) ಹಿಂತಿರುಗಿ 0x2;
    ಆದರೆ (!strcmp(name, "osh"))   ಹಿಂತಿರುಗಿ 0x3;
    ಆದರೆ (!strcmp(name, "nshld")) ಹಿಂತಿರುಗಿ 0x5;
    ಆದರೆ (!strcmp(name, "nshst")) ಹಿಂತಿರುಗಿ 0x6;
    ಆದರೆ (!strcmp(name, "nsh"))   ಹಿಂತಿರುಗಿ 0x7;
    ಆದರೆ (!strcmp(name, "ishld")) ಹಿಂತಿರುಗಿ 0x9;
    ಆದರೆ (!strcmp(name, "ishst")) ಹಿಂತಿರುಗಿ 0xA;
    ಆದರೆ (!strcmp(name, "ish"))   ಹಿಂತಿರುಗಿ 0xB;
    ಆದರೆ (!strcmp(name, "ld"))    ಹಿಂತಿರುಗಿ 0xD;
    ಆದರೆ (!strcmp(name, "st"))    ಹಿಂತಿರುಗಿ 0xE;
    ಆದರೆ (!strcmp(name, "sy"))    ಹಿಂತಿರುಗಿ 0xF;
    ಹಿಂತಿರುಗಿ -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_parse_regvar(ಪೂರ್ಣಾಂಕ t)
{
    ಆದರೆ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ಹಿಂತಿರುಗಿ t - TOK_ASM_x0;
    ಆದರೆ (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        ಹಿಂತಿರುಗಿ ARM64_FREG_ತಳ + (t - TOK_ASM_v0);
    ಆದರೆ (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        ಹಿಂತಿರುಗಿ ARM64_FREG_ತಳ + (t - TOK_ASM_d0);
    ಆದರೆ (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        ಹಿಂತಿರುಗಿ ARM64_FREG_ತಳ + (t - TOK_ASM_s0);
    ಆದರೆ (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        ಹಿಂತಿರುಗಿ ARM64_FREG_ತಳ + (t - TOK_ASM_h0);
    ಆದರೆ (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        ಹಿಂತಿರುಗಿ ARM64_FREG_ತಳ + (t - TOK_ASM_b0);
    ಹಿಂತಿರುಗಿ -1;
}

/* Parse a single operand */
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op)
{
    ಪೂರ್ಣಾಂಕ reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->ಸರಿಸು = 0;
    op->addr_ಬಹುಲಕ = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    ಆದರೆ (tok == '[') {
        parse_addr_ಕಾರ್ಯಾಂಶ(s1, op);
        ಹಿಂತಿರುಗಿ;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    ಆದರೆ (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        ಮುಂದಿನ();
        ಹಿಂತಿರುಗಿ;
    }

    /* Condition code */
    reg = parse_condition(tok);
    ಆದರೆ (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        ಮುಂದಿನ();
        ಹಿಂತಿರುಗಿ;
    }

    /* Immediate or address expression */
    ಆದರೆ (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op->e);
        op->type = OP_IM;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } ಇಲ್ಲದಿದ್ದರೆ {
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಅಭಿವ್ಯಕ್ತಿ_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->ಸರಿಸು = 0;
    op->addr_ಬಹುಲಕ = ADDR_OFF;
    op->reg_tok = 0;

    ಆದರೆ (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        ಮುಂದಿನ();
    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
ಸ್ಥಿರ ಶೂನ್ಯ parse_addr_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op)
{
    ಪೂರ್ಣಾಂಕ reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = ಖಾಲಿ;
    op->addr_ಬಹುಲಕ = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    ಆದರೆ (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        ಹಿಂತಿರುಗಿ;
    }
    op->reg = reg;
    op->reg_tok = tok;
    ಮುಂದಿನ();
    /* Check for offset */
    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ();
        ಆದರೆ (tok == '#' || tok == '@' || tok == '$')
            ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op->e);
    }
    skip(']');
    ಆದರೆ (tok == '!') {
        op->addr_ಬಹುಲಕ = ADDR_PRE;
        ಮುಂದಿನ();
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == ',') {
        op->addr_ಬಹುಲಕ = ADDR_POST;
        ಮುಂದಿನ();
        ಆದರೆ (tok == '#' || tok == '@' || tok == '$')
            ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
ಸ್ಥಿರ ಶೂನ್ಯ gen_mov_with_ತಳ(ಪೂರ್ಣಾಂಕ rd, uint16_t imm, ಪೂರ್ಣಾಂಕ ಸರಿಸು,
                              ಪೂರ್ಣಾಂಕ is_64bit, uint32_t ತಳ_opcode)
{
    uint32_t instr = ತಳ_opcode;
    ಆದರೆ (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, ಸರಿಸು);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_movz(ಪೂರ್ಣಾಂಕ rd, uint16_t imm, ಪೂರ್ಣಾಂಕ ಸರಿಸು, ಪೂರ್ಣಾಂಕ is_64bit)
{
    gen_mov_with_ತಳ(rd, imm, ಸರಿಸು, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
ಸ್ಥಿರ ಶೂನ್ಯ gen_movn(ಪೂರ್ಣಾಂಕ rd, uint16_t imm, ಪೂರ್ಣಾಂಕ ಸರಿಸು, ಪೂರ್ಣಾಂಕ is_64bit)
{
    gen_mov_with_ತಳ(rd, imm, ಸರಿಸು, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
ಸ್ಥಿರ ಶೂನ್ಯ gen_movk(ಪೂರ್ಣಾಂಕ rd, uint16_t imm, ಪೂರ್ಣಾಂಕ ಸರಿಸು, ಪೂರ್ಣಾಂಕ is_64bit)
{
    gen_mov_with_ತಳ(rd, imm, ಸರಿಸು, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_ಕೂಡಿಸು_imm(ಪೂರ್ಣಾಂಕ rd, ಪೂರ್ಣಾಂಕ rn, uint32_t imm, ಪೂರ್ಣಾಂಕ is_64bit, ಪೂರ್ಣಾಂಕ setflags)
{
    uint32_t instr = ARM64_ಕೂಡಿಸು_IMM;
    uint32_t imm12;

    ಆದರೆ (is_64bit) instr |= ARM64_SF(1);
    ಆದರೆ (setflags) instr |= ARM64_S(1);

    ಆದರೆ (imm <= 0xFFF) {
        imm12 = imm;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_error("add immediate out of range");
        ಹಿಂತಿರುಗಿ;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_sub_imm(ಪೂರ್ಣಾಂಕ rd, ಪೂರ್ಣಾಂಕ rn, uint32_t imm, ಪೂರ್ಣಾಂಕ is_64bit, ಪೂರ್ಣಾಂಕ setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    ಆದರೆ (is_64bit) instr |= ARM64_SF(1);
    ಆದರೆ (setflags) instr |= ARM64_S(1);

    ಆದರೆ (imm <= 0xFFF) {
        imm12 = imm;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_error("sub immediate out of range");
        ಹಿಂತಿರುಗಿ;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
ಸ್ಥಿರ ಶೂನ್ಯ gen_dp_reg(uint32_t opcode, ಪೂರ್ಣಾಂಕ rd, ಪೂರ್ಣಾಂಕ rn, ಪೂರ್ಣಾಂಕ rm, ಪೂರ್ಣಾಂಕ is_64bit)
{
    uint32_t instr = opcode;
    ಆದರೆ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_ldst_imm(uint32_t ತಳ_opcode, ಪೂರ್ಣಾಂಕ rt, ಪೂರ್ಣಾಂಕ rn,
                         int32_t ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_log2)
{
    uint32_t instr = ತಳ_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    ಆದರೆ (ಸ್ಥಾನಾಂತರ >= 0 && !(ಸ್ಥಾನಾಂತರ & ((1 << ಗಾತ್ರ_log2) - 1))) {
    imm12 = ಸ್ಥಾನಾಂತರ >> ಗಾತ್ರ_log2;
        ಆದರೆ (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            ಹಿಂತಿರುಗಿ;
        }
    }

    ಆಯ್ಕೆ (ತಳ_opcode) {
    ಸ್ಥಿತಿ ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; ನಿಲ್ಲಿಸು;
    }

    ಆದರೆ (unscaled_opcode && ಸ್ಥಾನಾಂತರ >= -256 && ಸ್ಥಾನಾಂತರ <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)ಸ್ಥಾನಾಂತರ & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (ಸ್ಥಾನಾಂತರ & ((1 << ಗಾತ್ರ_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_ldst_pair(uint32_t ತಳ_opcode, ಪೂರ್ಣಾಂಕ rt, ಪೂರ್ಣಾಂಕ rt2, ಪೂರ್ಣಾಂಕ rn,
                          int32_t ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_log2)
{
    int32_t imm7;
    uint32_t instr = ತಳ_opcode;

    ಆದರೆ (ಸ್ಥಾನಾಂತರ & ((1 << ಗಾತ್ರ_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = ಸ್ಥಾನಾಂತರ >> ಗಾತ್ರ_log2;
    ಆದರೆ (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
ಸ್ಥಿರ ಶೂನ್ಯ gen_b_or_bl(int32_t ಸ್ಥಾನಾಂತರ, uint32_t ತಳ_opcode)
{
    uint32_t instr = ತಳ_opcode;
    instr |= ARM64_OFFSET26(ಸ್ಥಾನಾಂತರ);
    emit_instr32(instr);
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_b(int32_t ಸ್ಥಾನಾಂತರ)
{
    gen_b_or_bl(ಸ್ಥಾನಾಂತರ, ARM64_B);
}

/* Generate BL (branch with link) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_bl(int32_t ಸ್ಥಾನಾಂತರ)
{
    gen_b_or_bl(ಸ್ಥಾನಾಂತರ, ARM64_BL);
}

/* Generate BR (branch to register) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_br(ಪೂರ್ಣಾಂಕ rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_blr(ಪೂರ್ಣಾಂಕ rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
ಸ್ಥಿರ ಶೂನ್ಯ gen_ret(ಪೂರ್ಣಾಂಕ rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
ಸ್ಥಿರ ಶೂನ್ಯ gen_b_cond(ಪೂರ್ಣಾಂಕ cond, int32_t ಸ್ಥಾನಾಂತರ)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(ಸ್ಥಾನಾಂತರ);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
ಸ್ಥಿರ ಶೂನ್ಯ gen_cbz_or_cbnz(ಪೂರ್ಣಾಂಕ rt, int32_t ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ is_64bit, uint32_t ತಳ_opcode)
{
    uint32_t instr = ತಳ_opcode;
    ಆದರೆ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(ಸ್ಥಾನಾಂತರ);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_cbz(ಪೂರ್ಣಾಂಕ rt, int32_t ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ is_64bit)
{
    gen_cbz_or_cbnz(rt, ಸ್ಥಾನಾಂತರ, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
ಸ್ಥಿರ ಶೂನ್ಯ gen_cbnz(ಪೂರ್ಣಾಂಕ rt, int32_t ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ is_64bit)
{
    gen_cbz_or_cbnz(rt, ಸ್ಥಾನಾಂತರ, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
ಸ್ಥಿರ ಶೂನ್ಯ gen_mov_reg(ಪೂರ್ಣಾಂಕ rd, ಪೂರ್ಣಾಂಕ rm, ಪೂರ್ಣಾಂಕ is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    ಆದರೆ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_asm_encode_bimm64(uint64_t x)
{
    ಪೂರ್ಣಾಂಕ neg, rep, pos, len;

    neg = x & 1;
    ಆದರೆ (neg)
        x = ~x;
    ಆದರೆ (!x)
        ಹಿಂತಿರುಗಿ -1;

    ಆದರೆ (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    ಇಲ್ಲದಿದ್ದರೆ
        rep = 64;

    pos = 0;
    ಆದರೆ (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    ಆದರೆ (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    ಆದರೆ (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    ಆದರೆ (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    ಆದರೆ (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    ಆದರೆ (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    ಆದರೆ (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    ಆದರೆ (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    ಆದರೆ (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    ಆದರೆ (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    ಆದರೆ (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    ಆದರೆ (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    ಆದರೆ (x)
        ಹಿಂತಿರುಗಿ -1;
    ಆದರೆ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    ಹಿಂತಿರುಗಿ ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_logical_imm(uint32_t opcode, ಪೂರ್ಣಾಂಕ rd, ಪೂರ್ಣಾಂಕ rn,
                            uint64_t imm, ಪೂರ್ಣಾಂಕ is_64bit)
{
    uint32_t instr;
    uint64_t val;
    ಪೂರ್ಣಾಂಕ enc;

    ಆದರೆ (is_64bit)
        val = imm;
    ಇಲ್ಲದಿದ್ದರೆ {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    ಆದರೆ (enc < 0) {
        tcc_error("logical immediate out of range");
        ಹಿಂತಿರುಗಿ;
    }

    instr = opcode;
    ಆದರೆ (is_64bit)
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
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ constraint_ಆದ್ಯತೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಪೂರ್ಣಾಂಕ ಆದ್ಯತೆ, c, pr;

    ಆದ್ಯತೆ = 0;
    ಗಾಗಿ (;;) {
        c = *str++;
        ಆದರೆ (c == '\0')
            ನಿಲ್ಲಿಸು;
        ಆಯ್ಕೆ (c) {
        ಸ್ಥಿತಿ '=':
        ಸ್ಥಿತಿ '+':
        ಸ್ಥಿತಿ '&':
            ಮುಂದುವರಿ;
        ಸ್ಥಿತಿ 'r':
            pr = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'w':
        ಸ್ಥಿತಿ 'f':
        ಸ್ಥಿತಿ 'x':
        ಸ್ಥಿತಿ 'y':
            pr = 3;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'm':
        ಸ್ಥಿತಿ 'Q':
            pr = 4;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'i':
        ಸ್ಥಿತಿ 'S':
            pr = 5;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'U':
            ಆದರೆ (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                ನಿಲ್ಲಿಸು;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'I':
        ಸ್ಥಿತಿ 'J':
        ಸ್ಥಿತಿ 'K':
        ಸ್ಥಿತಿ 'L':
        ಸ್ಥಿತಿ 'M':
        ಸ್ಥಿತಿ 'N':
        ಸ್ಥಿತಿ 'Z':
            pr = 6;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'n':
            pr = 7;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'g':
            pr = 8;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            ನಿಲ್ಲಿಸು;
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

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_valid_ಕೂಡಿಸು_imm(int64_t val)
{
    ಹಿಂತಿರುಗಿ val >= 0 && val <= 4095;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_valid_logical_imm(int64_t val, ಪೂರ್ಣಾಂಕ ಬಿಟ್ಟುಗಳು)
{
    uint64_t uval;

    uval = (uint64_t)val;
    ಆದರೆ (ಬಿಟ್ಟುಗಳು == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    ಹಿಂತಿರುಗಿ arm64_asm_encode_bimm64(uval) >= 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    ಆದರೆ (uval <= 0xFFFF)
        ಹಿಂತಿರುಗಿ 1;
    ಆದರೆ (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        ಹಿಂತಿರುಗಿ 1;
    ಆದರೆ (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        ಹಿಂತಿರುಗಿ 1;
    ಆದರೆ ((uval & 0xFFFFFFFF00000000ULL) == 0)
        ಹಿಂತಿರುಗಿ 1;

    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_valid_movw_ಸರಿಸು(ಪೂರ್ಣಾಂಕ ಸರಿಸು, ಪೂರ್ಣಾಂಕ is_64bit)
{
    ಆದರೆ (ಸರಿಸು < 0 || (ಸರಿಸು & 15))
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (ಸರಿಸು > (is_64bit ? 48 : 16))
        ಹಿಂತಿರುಗಿ 0;
    ಹಿಂತಿರುಗಿ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_ಸ್ಮರಣೆ_is_ತಳ_only(ಸ್ಥಿರಾಂಕ SValue *sv)
{
    ಪೂರ್ಣಾಂಕ r;

    r = sv->r;
    ಆದರೆ ((r & VT_VALMASK) == VT_CONST)
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ ((r & VT_VALMASK) == VT_LOCAL)
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ ((r & VT_VALMASK) == VT_LLOCAL)
        ಹಿಂತಿರುಗಿ 1;
    ಆದರೆ (r & VT_LVAL)
        ಹಿಂತಿರುಗಿ (r & VT_VALMASK) < VT_CONST;
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_ಸ್ಮರಣೆ_is_pair_suitable(ಸ್ಥಿರಾಂಕ SValue *sv)
{
    int64_t ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (arm64_ಸ್ಮರಣೆ_is_ತಳ_only(sv))
        ಹಿಂತಿರುಗಿ 1;
    ಆದರೆ ((sv->r & VT_VALMASK) != VT_LOCAL)
        ಹಿಂತಿರುಗಿ 0;

    ಸ್ಥಾನಾಂತರ = (int64_t)sv->c.i;
    ಹಿಂತಿರುಗಿ (ಸ್ಥಾನಾಂತರ & 7) == 0 && ಸ್ಥಾನಾಂತರ >= -512 && ಸ್ಥಾನಾಂತರ <= 504;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_int_reg_is_allocatable(ಪೂರ್ಣಾಂಕ reg)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಹಿಂತಿರುಗಿ reg >= TREG_X0 && reg <= TREG_X17;
#ಇಲ್ಲದಿದ್ದರೆ
    ಹಿಂತಿರುಗಿ reg >= TREG_X0 && reg <= TREG_X30;
#ಆದರೆ_ಅಂತ್ಯ
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_ಸ್ಮರಣೆ_needs_ವಿಳಾಸ_reg(ಸ್ಥಿರಾಂಕ SValue *sv)
{
    ಪೂರ್ಣಾಂಕ r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    ಆದರೆ (!(r & VT_LVAL))
        ಹಿಂತಿರುಗಿ 0;
    ಆಯ್ಕೆ (r & VT_VALMASK) {
    ಸ್ಥಿತಿ VT_LOCAL:
    ಸ್ಥಿತಿ VT_LLOCAL:
    ಸ್ಥಿತಿ VT_CONST:
        ಹಿಂತಿರುಗಿ 1;
    }
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_prepare_ಸ್ಮರಣೆ_ಕಾರ್ಯಾಂಶ(ASMOperand *op, uint8_t *regs_allocated)
{
    ಪೂರ್ಣಾಂಕ reg;

    ಆದರೆ (!arm64_ಸ್ಮರಣೆ_needs_ವಿಳಾಸ_reg(op->vt))
        ಹಿಂತಿರುಗಿ 1;

    ಗಾಗಿ (reg = 0; reg < 31; reg++) {
        ಆದರೆ (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_ಒಳ_ಮುಖವಾಡ)) {
            regs_allocated[reg] |= REG_ಒಳ_ಮುಖವಾಡ;
            op->reg = reg;
            op->is_ಸ್ಮರಣೆ = 1;
            ಹಿಂತಿರುಗಿ 1;
        }
    }
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_ತುಂಬು_ಸ್ಮರಣೆ_ಕಾರ್ಯಾಂಶ_ತಳ(ಪೂರ್ಣಾಂಕ reg, SValue *sv)
{
    SValue ತಳ;
    ಪೂರ್ಣಾಂಕ rval;

    ತಳ = *sv;
    ತಳ.type.t = VT_PTR;
    rval = ತಳ.r & VT_VALMASK;
    ಆದರೆ (rval == VT_LLOCAL) {
        ತಳ.r = (ತಳ.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (rval == VT_CONST || rval == VT_LOCAL) {
        ತಳ.r &= ~VT_LVAL;
    } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_ಆಂತರಿಕ_error("unsupported ARM64 memory operand base");
    }
    ತುಂಬು(reg, &ತಳ);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಕಾರ್ಯಾಂಶ_is_sp(ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *op)
{
    ಹಿಂತಿರುಗಿ op->reg_tok == TOK_ASM_sp;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ parse_sysreg_name(ಪೂರ್ಣಾಂಕ t)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;

    ಆದರೆ (t < TOK_IDENT)
        ಹಿಂತಿರುಗಿ -1;
    name = get_tok_str(t, ಖಾಲಿ);
    ಆದರೆ (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        ಹಿಂತಿರುಗಿ 1;
    ಹಿಂತಿರುಗಿ -1;
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_mrs(ಪೂರ್ಣಾಂಕ rt, ಪೂರ್ಣಾಂಕ sysreg)
{
    uint32_t instr;

    ಆಯ್ಕೆ (sysreg) {
        ಸ್ಥಿತಿ 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unsupported system register");
            ಹಿಂತಿರುಗಿ;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_msr(ಪೂರ್ಣಾಂಕ rt, ಪೂರ್ಣಾಂಕ sysreg)
{
    uint32_t instr;

    ಆಯ್ಕೆ (sysreg) {
        ಸ್ಥಿತಿ 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unsupported system register");
            ಹಿಂತಿರುಗಿ;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
ಸ್ಥಿರ ಶೂನ್ಯ gen_nop(ಶೂನ್ಯ)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_ಸರಿಸು(ಪೂರ್ಣಾಂಕ rd, ಪೂರ್ಣಾಂಕ rn, ಪೂರ್ಣಾಂಕ rm_or_imm, ಪೂರ್ಣಾಂಕ ಸರಿಸು_type, ಪೂರ್ಣಾಂಕ is_imm, ಪೂರ್ಣಾಂಕ is_64bit)
{
    uint32_t instr;
    ಪೂರ್ಣಾಂಕ ಅಗಲ = is_64bit ? 64 : 32;

    ಆದರೆ (is_imm) {
        /* Shift by immediate */
        ಆಯ್ಕೆ (ಸರಿಸು_type) {
            ಸ್ಥಿತಿ 0: /* LSL - UBFM alias */
                ಆದರೆ (rm_or_imm < 0 || rm_or_imm >= ಅಗಲ) {
                    tcc_error("shift immediate out of range");
                    ಹಿಂತಿರುಗಿ;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((ಅಗಲ - rm_or_imm) & (ಅಗಲ - 1));
                instr |= ARM64_IMM_S(ಅಗಲ - rm_or_imm - 1);
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                ಆದರೆ (rm_or_imm < 0 || rm_or_imm >= ಅಗಲ) {
                    tcc_error("shift immediate out of range");
                    ಹಿಂತಿರುಗಿ;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(ಅಗಲ - 1);
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                ಆದರೆ (rm_or_imm < 0 || rm_or_imm >= ಅಗಲ) {
                    tcc_error("shift immediate out of range");
                    ಹಿಂತಿರುಗಿ;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(ಅಗಲ - 1);
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                ಆದರೆ (rm_or_imm < 0 || rm_or_imm >= ಅಗಲ) {
                    tcc_error("shift immediate out of range");
                    ಹಿಂತಿರುಗಿ;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                ಹಿಂತಿರುಗಿ;
            ಪೂರ್ವನಿಯೋಜಿತ:
                tcc_error("unknown shift type");
                ಹಿಂತಿರುಗಿ;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* Shift by register */
        ಆಯ್ಕೆ (ಸರಿಸು_type) {
            ಸ್ಥಿತಿ 0: /* LSL */
                instr = ARM64_LSL_REG;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 1: /* LSR */
                instr = ARM64_LSR_REG;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 2: /* ASR */
                instr = ARM64_ASR_REG;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 3: /* ROR */
                instr = ARM64_ROR_REG;
                ನಿಲ್ಲಿಸು;
            ಪೂರ್ವನಿಯೋಜಿತ:
                tcc_error("unknown shift type");
                ಹಿಂತಿರುಗಿ;
        }
        ಆದರೆ (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
ಸ್ಥಿರ ಶೂನ್ಯ asm_ಸರಿಸು(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ op1, op2, op3;
    ಪೂರ್ಣಾಂಕ rd, rn, ಸರಿಸು_amount;
    ಪೂರ್ಣಾಂಕ ಸರಿಸು_type;
    ಪೂರ್ಣಾಂಕ is_64bit = 1;

    ಆಯ್ಕೆ (token) {
        ಸ್ಥಿತಿ TOK_ASM_lsl:
            ಸರಿಸು_type = 0;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_lsr:
            ಸರಿಸು_type = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_asr:
            ಸರಿಸು_type = 2;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_ror:
            ಸರಿಸು_type = 3;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unknown shift instruction");
            ಹಿಂತಿರುಗಿ;
    }

    parse_ಕಾರ್ಯಾಂಶ(s1, &op1);
    ಆದರೆ (tok == ',') ಮುಂದಿನ();
    parse_ಕಾರ್ಯಾಂಶ(s1, &op2);

    ಆದರೆ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ಹಿಂತಿರುಗಿ;
    }
    ಆದರೆ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ಹಿಂತಿರುಗಿ;
    }

    rd = op1.reg;
    rn = op2.reg;

    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ();
        parse_ಕಾರ್ಯಾಂಶ(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ಆದರೆ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ಹಿಂತಿರುಗಿ;
        }
        ಆದರೆ (op3.type & OP_REG) {
            ಆದರೆ (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ಹಿಂತಿರುಗಿ;
            }
            gen_ಸರಿಸು(rd, rn, op3.reg, ಸರಿಸು_type, 0, is_64bit);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op3.type & OP_IM) {
            ಸರಿಸು_amount = op3.e.v;
            gen_ಸರಿಸು(rd, rn, ಸರಿಸು_amount, ಸರಿಸು_type, 1, is_64bit);
        } ಇಲ್ಲದಿದ್ದರೆ {
            tcc_error("shift requires immediate or register operand");
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_error("shift requires immediate or register operand");
        ಹಿಂತಿರುಗಿ;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
ಸ್ಥಿರ ಶೂನ್ಯ gen_barrier(ಪೂರ್ಣಾಂಕ barrier_type, ಪೂರ್ಣಾಂಕ option)
{
    uint32_t instr;

    ಆಯ್ಕೆ (barrier_type) {
        ಸ್ಥಿತಿ 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unknown barrier type");
            ಹಿಂತಿರುಗಿ;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
ಸ್ಥಿರ ಶೂನ್ಯ asm_barrier(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಪೂರ್ಣಾಂಕ barrier_type, option;
    ಕಾರ್ಯಾಂಶ op;

    ಆಯ್ಕೆ (token) {
        ಸ್ಥಿತಿ TOK_ASM_isb:
            barrier_type = 0;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_dsb:
            barrier_type = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_dmb:
            barrier_type = 2;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unknown barrier instruction");
            ಹಿಂತಿರುಗಿ;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    ಆದರೆ (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        ಆದರೆ (option >= 0) {
            ಮುಂದಿನ();
        } ಇಲ್ಲದಿದ್ದರೆ {
            parse_ಕಾರ್ಯಾಂಶ(s1, &op);
            ಆದರೆ (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                ಹಿಂತಿರುಗಿ;
            }
            ಆದರೆ (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                ಹಿಂತಿರುಗಿ;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
ಸ್ಥಿರ ಶೂನ್ಯ gen_mov_imm(ಪೂರ್ಣಾಂಕ rd, uint64_t imm, ಪೂರ್ಣಾಂಕ is_64bit)
{
    uint16_t hw;
    ಪೂರ್ಣಾಂಕ i, ಮೊದಲ = 1;

    ಗಾಗಿ (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        ಆದರೆ (hw != 0 || i == 0) {
            ಆದರೆ (ಮೊದಲ) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                ಮೊದಲ = 0;
            } ಇಲ್ಲದಿದ್ದರೆ {
                gen_movk(rd, hw, i, is_64bit);
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!ಮೊದಲ) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
ಸ್ಥಿರ ಶೂನ್ಯ asm_mov(TCCState *s1)
{
    ಕಾರ್ಯಾಂಶ op1, op2;
    ಪೂರ್ಣಾಂಕ rd, rn;
    ಪೂರ್ಣಾಂಕ is_64bit;

    parse_ಕಾರ್ಯಾಂಶ(s1, &op1);
    ಆದರೆ (tok == ',') ಮುಂದಿನ();
    parse_ಕಾರ್ಯಾಂಶ(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    ಆದರೆ (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        ಆದರೆ (ಕಾರ್ಯಾಂಶ_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            ಹಿಂತಿರುಗಿ;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        ಆದರೆ (ಕಾರ್ಯಾಂಶ_is_sp(&op1) || ಕಾರ್ಯಾಂಶ_is_sp(&op2))
            gen_ಕೂಡಿಸು_imm(rd, rn, 0, 1, 0);
        ಇಲ್ಲದಿದ್ದರೆ
            gen_mov_reg(rd, rn, is_64bit);
    } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
ಸ್ಥಿರ ಶೂನ್ಯ asm_ದತ್ತಾಂಶ_proc(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ op1, op2, op3;
    ಪೂರ್ಣಾಂಕ rd, rn, rm;
    ಪೂರ್ಣಾಂಕ is_64bit = 1;
    uint32_t opcode;

    ಆಯ್ಕೆ (token) {
        ಸ್ಥಿತಿ TOK_ASM_ಕೂಡಿಸು:
        ಸ್ಥಿತಿ TOK_ASM_adds:
            opcode = token == TOK_ASM_ಕೂಡಿಸು ? ARM64_ಕೂಡಿಸು_REG : ARM64_ADDS_REG;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_sub:
        ಸ್ಥಿತಿ TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_and:
        ಸ್ಥಿತಿ TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unsupported data processing instruction");
            ಹಿಂತಿರುಗಿ;
    }

    parse_ಕಾರ್ಯಾಂಶ(s1, &op1);
    ಆದರೆ (tok == ',') ಮುಂದಿನ();
    parse_ಕಾರ್ಯಾಂಶ(s1, &op2);

    ಆದರೆ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ಹಿಂತಿರುಗಿ;
    }
    ಆದರೆ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ಹಿಂತಿರುಗಿ;
    }

    rd = op1.reg;
    rn = op2.reg;

    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ();
        parse_ಕಾರ್ಯಾಂಶ(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ಆದರೆ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ಹಿಂತಿರುಗಿ;
        }
        ಆದರೆ (op3.type & OP_IM) {
            ಆದರೆ (token == TOK_ASM_ಕೂಡಿಸು || token == TOK_ASM_adds)
                gen_ಕೂಡಿಸು_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_ತಳ, rd, rn, op3.e.v, is_64bit);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            ಇಲ್ಲದಿದ್ದರೆ
                tcc_error("immediate operand not valid for this instruction");
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                ಹಿಂತಿರುಗಿ;
            }
            rm = op3.reg;
            ಆದರೆ (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ಹಿಂತಿರುಗಿ;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
ಸ್ಥಿರ ಶೂನ್ಯ asm_ldst(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ op1, op2;
    ಪೂರ್ಣಾಂಕ rt, rn;
    int32_t ಸ್ಥಾನಾಂತರ = 0;
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_log2 = 3;
    uint32_t ತಳ_opcode;

    parse_ಕಾರ್ಯಾಂಶ(s1, &op1);
    ಆದರೆ (tok == ',') ಮುಂದಿನ();
    parse_ಕಾರ್ಯಾಂಶ(s1, &op2);

    ಆದರೆ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ಹಿಂತಿರುಗಿ;
    }
    ಆದರೆ (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        ಹಿಂತಿರುಗಿ;
    }

    rt = op1.reg;
    rn = op2.reg;
    ಸ್ಥಾನಾಂತರ = op2.e.v;

    ಆಯ್ಕೆ (token) {
        ಸ್ಥಿತಿ TOK_ASM_ldr:
            ಆದರೆ (op1.reg_type & REG_X) {
                ತಳ_opcode = ARM64_LDR_X;
                ಗಾತ್ರ_log2 = 3;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op1.reg_type & REG_W) {
                ತಳ_opcode = ARM64_LDR_W;
                ಗಾತ್ರ_log2 = 2;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op1.reg_type & REG_D) {
                ತಳ_opcode = ARM64_LDR_D;
                ಗಾತ್ರ_log2 = 3;
            } ಇಲ್ಲದಿದ್ದರೆ {
                tcc_error("ldr requires a w, x, or d register");
                ಹಿಂತಿರುಗಿ;
            }
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_ldrb:
            ತಳ_opcode = ARM64_LDR_B;
            ಗಾತ್ರ_log2 = 0;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_ldrh:
            ತಳ_opcode = ARM64_LDR_H;
            ಗಾತ್ರ_log2 = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_str:
            ಆದರೆ (op1.reg_type & REG_X) {
                ತಳ_opcode = ARM64_STR_X;
                ಗಾತ್ರ_log2 = 3;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op1.reg_type & REG_W) {
                ತಳ_opcode = ARM64_STR_W;
                ಗಾತ್ರ_log2 = 2;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op1.reg_type & REG_D) {
                ತಳ_opcode = ARM64_STR_D;
                ಗಾತ್ರ_log2 = 3;
            } ಇಲ್ಲದಿದ್ದರೆ {
                tcc_error("str requires a w, x, or d register");
                ಹಿಂತಿರುಗಿ;
            }
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_strb:
            ತಳ_opcode = ARM64_STR_B;
            ಗಾತ್ರ_log2 = 0;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_strh:
            ತಳ_opcode = ARM64_STR_H;
            ಗಾತ್ರ_log2 = 1;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unsupported load/store instruction");
            ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (op2.addr_ಬಹುಲಕ != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(ತಳ_opcode, rt, rn, ಸ್ಥಾನಾಂತರ, ಗಾತ್ರ_log2);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ldst_pair(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ op1, op2, op3;
    uint32_t ತಳ_opcode;
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_log2 = 3;

    parse_ಕಾರ್ಯಾಂಶ(s1, &op1);
    ಆದರೆ (tok == ',')
        ಮುಂದಿನ();
    parse_ಕಾರ್ಯಾಂಶ(s1, &op2);
    ಆದರೆ (tok == ',')
        ಮುಂದಿನ();
    parse_ಕಾರ್ಯಾಂಶ(s1, &op3);

    ಆದರೆ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ಹಿಂತಿರುಗಿ;
    }
    ಆದರೆ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ಹಿಂತಿರುಗಿ;
    }
    ಆದರೆ (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    ಆದರೆ ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        ಆದರೆ (token == TOK_ASM_stp) {
            ತಳ_opcode = op3.addr_ಬಹುಲಕ == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_ಬಹುಲಕ == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ತಳ_opcode = op3.addr_ಬಹುಲಕ == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_ಬಹುಲಕ == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        ಆದರೆ (token == TOK_ASM_stp) {
            ತಳ_opcode = op3.addr_ಬಹುಲಕ == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_ಬಹುಲಕ == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ತಳ_opcode = op3.addr_ಬಹುಲಕ == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_ಬಹುಲಕ == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_error("stp/ldp requires matching x or d registers");
        ಹಿಂತಿರುಗಿ;
    }

    gen_ldst_pair(ತಳ_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, ಗಾತ್ರ_log2);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_sysreg(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ op;
    ಪೂರ್ಣಾಂಕ sysreg;

    ಆದರೆ (token == TOK_ASM_mrs) {
        parse_ಕಾರ್ಯಾಂಶ(s1, &op);
        ಆದರೆ (tok == ',')
            ಮುಂದಿನ();
        sysreg = parse_sysreg_name(tok);
        ಆದರೆ (sysreg < 0)
            tcc_error("unsupported system register");
        ಮುಂದಿನ();
        gen_mrs(op.reg, sysreg);
        ಹಿಂತಿರುಗಿ;
    }

    sysreg = parse_sysreg_name(tok);
    ಆದರೆ (sysreg < 0)
        tcc_error("unsupported system register");
    ಮುಂದಿನ();
    ಆದರೆ (tok == ',')
        ಮುಂದಿನ();
    parse_ಕಾರ್ಯಾಂಶ(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ get_branch_condition(ಪೂರ್ಣಾಂಕ branch_token)
{
    ಪೂರ್ಣಾಂಕ cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    ಆಯ್ಕೆ (branch_token) {
        ಸ್ಥಿತಿ TOK_ASM_beq: cond_token = TOK_ASM_eq; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bne: cond_token = TOK_ASM_ne; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bcs:
        ಸ್ಥಿತಿ TOK_ASM_bhs: cond_token = TOK_ASM_cs; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bcc:
        ಸ್ಥಿತಿ TOK_ASM_blo: cond_token = TOK_ASM_cc; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bmi: cond_token = TOK_ASM_mi; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bpl: cond_token = TOK_ASM_pl; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bvs: cond_token = TOK_ASM_vs; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bvc: cond_token = TOK_ASM_vc; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bhi: cond_token = TOK_ASM_hi; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bls: cond_token = TOK_ASM_ls; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bge: cond_token = TOK_ASM_ge; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_blt: cond_token = TOK_ASM_lt; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_bgt: cond_token = TOK_ASM_gt; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_ble: cond_token = TOK_ASM_le; ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ: ಹಿಂತಿರುಗಿ -1;
    }

    ಹಿಂತಿರುಗಿ parse_condition(cond_token);
}

/* Handle branch instructions */
ಸ್ಥಿರ ಶೂನ್ಯ asm_branch(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ op;
    ಪೂರ್ಣಾಂಕ cond;
    Sym *sym;
    int32_t ಸ್ಥಾನಾಂತರ;

    /* ret can be used without operand */
    ಆದರೆ (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_ಕಾರ್ಯಾಂಶ(s1, &op);
    ಇಲ್ಲದಿದ್ದರೆ
        parse_ಅಭಿವ್ಯಕ್ತಿ_ಕಾರ್ಯಾಂಶ(s1, &op);

    ಆದರೆ (op.type & OP_IM) {
        sym = op.e.sym;
        ಆದರೆ (sym) {
            /* Symbolic address - emit relocation */
            ಸ್ಥಾನಾಂತರ = 0;

            cond = get_branch_condition(token);
            ಆದರೆ (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_ಪಠ್ಯ_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆಯ್ಕೆ (token) {
                    ಸ್ಥಿತಿ TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_ಪಠ್ಯ_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        ನಿಲ್ಲಿಸು;
                    ಸ್ಥಿತಿ TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_ಪಠ್ಯ_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        ನಿಲ್ಲಿಸು;
                    ಪೂರ್ವನಿಯೋಜಿತ:
                        tcc_error("unsupported branch");
                }
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಸ್ಥಾನಾಂತರ = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            ಆದರೆ (cond >= 0) {
                gen_b_cond(cond, ಸ್ಥಾನಾಂತರ);
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆಯ್ಕೆ (token) {
                    ಸ್ಥಿತಿ TOK_ASM_b:
                        gen_b(ಸ್ಥಾನಾಂತರ);
                        ನಿಲ್ಲಿಸು;
                    ಸ್ಥಿತಿ TOK_ASM_bl:
                        gen_bl(ಸ್ಥಾನಾಂತರ);
                        ನಿಲ್ಲಿಸು;
                    ಪೂರ್ವನಿಯೋಜಿತ:
                        tcc_error("unsupported branch");
                }
            }
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op.type & OP_REG) {
        ಆಯ್ಕೆ (token) {
            ಸ್ಥಿತಿ TOK_ASM_br:
                gen_br(op.reg);
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_ASM_blr:
                gen_blr(op.reg);
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_ASM_ret:
                gen_ret(op.reg);
                ನಿಲ್ಲಿಸು;
            ಪೂರ್ವನಿಯೋಜಿತ:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
ಸ್ಥಿರ ಶೂನ್ಯ asm_cb(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ op1, op2;
    ಪೂರ್ಣಾಂಕ rt, is_64bit;
    int32_t ಸ್ಥಾನಾಂತರ;
    Sym *sym;

    parse_ಕಾರ್ಯಾಂಶ(s1, &op1);
    ಆದರೆ (tok == ',') ಮುಂದಿನ();
    parse_ಅಭಿವ್ಯಕ್ತಿ_ಕಾರ್ಯಾಂಶ(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    ಆದರೆ (sym) {
        /* Symbolic address - emit relocation */
        ಸ್ಥಾನಾಂತರ = 0;
        ಆದರೆ (token == TOK_ASM_cbz) {
            gen_cbz(rt, ಸ್ಥಾನಾಂತರ, is_64bit);
            greloca(cur_ಪಠ್ಯ_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } ಇಲ್ಲದಿದ್ದರೆ {
            gen_cbnz(rt, ಸ್ಥಾನಾಂತರ, is_64bit);
            greloca(cur_ಪಠ್ಯ_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಸ್ಥಾನಾಂತರ = (int32_t)op2.e.v - ind;
        ಆದರೆ (token == TOK_ASM_cbz)
            gen_cbz(rt, ಸ್ಥಾನಾಂತರ, is_64bit);
        ಇಲ್ಲದಿದ್ದರೆ
            gen_cbnz(rt, ಸ್ಥಾನಾಂತರ, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
ಸ್ಥಿರ ಶೂನ್ಯ asm_move_wide(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ op1, op2;
    ಪೂರ್ಣಾಂಕ rd, is_64bit = 1;
    uint16_t imm;
    ಪೂರ್ಣಾಂಕ ಸರಿಸು = 0;

    parse_ಕಾರ್ಯಾಂಶ(s1, &op1);
    ಆದರೆ (tok == ',') ಮುಂದಿನ();
    parse_ಕಾರ್ಯಾಂಶ(s1, &op2);

    ಆದರೆ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ಹಿಂತಿರುಗಿ;
    }
    ಆದರೆ (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        ಹಿಂತಿರುಗಿ;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    ಆದರೆ ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        ಹಿಂತಿರುಗಿ;
    }
    imm = op2.e.v;

    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ();
        ಆದರೆ (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            ಹಿಂತಿರುಗಿ;
        }
            ಮುಂದಿನ();
            ಆದರೆ (tok == '#') ಮುಂದಿನ();
            asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &op2.e);
        ಆದರೆ (op2.e.sym || !is_valid_movw_ಸರಿಸು((ಪೂರ್ಣಾಂಕ)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            ಹಿಂತಿರುಗಿ;
        }
            ಸರಿಸು = (ಪೂರ್ಣಾಂಕ)op2.e.v / 16;
        }

    ಆಯ್ಕೆ (token) {
        ಸ್ಥಿತಿ TOK_ASM_movz:
            gen_movz(rd, imm, ಸರಿಸು, is_64bit);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_movn:
            gen_movn(rd, imm, ಸರಿಸು, is_64bit);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_movk:
            gen_movk(rd, imm, ಸರಿಸು, is_64bit);
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ opcode)
{
    ಆಯ್ಕೆ (opcode) {
        ಸ್ಥಿತಿ TOK_ASM_ಕೂಡಿಸು:
        ಸ್ಥಿತಿ TOK_ASM_adds:
        ಸ್ಥಿತಿ TOK_ASM_sub:
        ಸ್ಥಿತಿ TOK_ASM_subs:
        ಸ್ಥಿತಿ TOK_ASM_and:
        ಸ್ಥಿತಿ TOK_ASM_ands:
        ಸ್ಥಿತಿ TOK_ASM_orr:
        ಸ್ಥಿತಿ TOK_ASM_eor:
        ಸ್ಥಿತಿ TOK_ASM_mul:
            asm_ದತ್ತಾಂಶ_proc(s1, opcode);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_lsl:
        ಸ್ಥಿತಿ TOK_ASM_lsr:
        ಸ್ಥಿತಿ TOK_ASM_asr:
        ಸ್ಥಿತಿ TOK_ASM_ror:
            asm_ಸರಿಸು(s1, opcode);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_ldr:
        ಸ್ಥಿತಿ TOK_ASM_ldrb:
        ಸ್ಥಿತಿ TOK_ASM_ldrh:
        ಸ್ಥಿತಿ TOK_ASM_str:
        ಸ್ಥಿತಿ TOK_ASM_strb:
        ಸ್ಥಿತಿ TOK_ASM_strh:
            asm_ldst(s1, opcode);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_ldp:
        ಸ್ಥಿತಿ TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_b:
        ಸ್ಥಿತಿ TOK_ASM_bl:
        ಸ್ಥಿತಿ TOK_ASM_br:
        ಸ್ಥಿತಿ TOK_ASM_blr:
        ಸ್ಥಿತಿ TOK_ASM_ret:
        ಸ್ಥಿತಿ TOK_ASM_beq:
        ಸ್ಥಿತಿ TOK_ASM_bne:
        ಸ್ಥಿತಿ TOK_ASM_bcs:
        ಸ್ಥಿತಿ TOK_ASM_bhs:
        ಸ್ಥಿತಿ TOK_ASM_bcc:
        ಸ್ಥಿತಿ TOK_ASM_blo:
        ಸ್ಥಿತಿ TOK_ASM_bmi:
        ಸ್ಥಿತಿ TOK_ASM_bpl:
        ಸ್ಥಿತಿ TOK_ASM_bvs:
        ಸ್ಥಿತಿ TOK_ASM_bvc:
        ಸ್ಥಿತಿ TOK_ASM_bhi:
        ಸ್ಥಿತಿ TOK_ASM_bls:
        ಸ್ಥಿತಿ TOK_ASM_bge:
        ಸ್ಥಿತಿ TOK_ASM_blt:
        ಸ್ಥಿತಿ TOK_ASM_bgt:
        ಸ್ಥಿತಿ TOK_ASM_ble:
            asm_branch(s1, opcode);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_cbz:
        ಸ್ಥಿತಿ TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_movz:
        ಸ್ಥಿತಿ TOK_ASM_movn:
        ಸ್ಥಿತಿ TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_mrs:
        ಸ್ಥಿತಿ TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_isb:
        ಸ್ಥಿತಿ TOK_ASM_dsb:
        ಸ್ಥಿತಿ TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_nop:
            gen_nop();
            ನಿಲ್ಲಿಸು;

        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, ಖಾಲಿ));
            ನಿಲ್ಲಿಸು;
    }
}

/* Substitute assembler operand */
ST_FUNC ಶೂನ್ಯ subst_asm_ಕಾರ್ಯಾಂಶ(CString *ಕೂಡಿಸು_str, SValue *sv, ಪೂರ್ಣಾಂಕ modifier)
{
    ಪೂರ್ಣಾಂಕ r, reg, ಗಾತ್ರ_2, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    ಆದರೆ ((r & VT_VALMASK) == VT_CONST) {
        ಆದರೆ ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(ಕೂಡಿಸು_str, modifier == 'w' ? "wzr" : "xzr", -1);
            ಹಿಂತಿರುಗಿ;
        }
        ಆದರೆ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(ಕೂಡಿಸು_str, '#');
        ಆದರೆ (r & VT_SYM) {
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = get_tok_str(sv->sym->v, ಖಾಲಿ);
            ಆದರೆ (sv->sym->v >= SYM_ಮೊದಲ_ANOM)
                get_asm_sym(tok_alloc(name, ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name))->tok, sv->sym);
            ಆದರೆ (tcc_state->leading_underscore)
                cstr_ccat(ಕೂಡಿಸು_str, '_');
            cstr_cat(ಕೂಡಿಸು_str, name, -1);
            ಆದರೆ ((uint32_t) sv->c.i == 0)
                ಹೋಗು no_ಸ್ಥಾನಾಂತರ;
            cstr_ccat(ಕೂಡಿಸು_str, '+');
        }
        uval = sv->c.i;
        ಆದರೆ (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(ಕೂಡಿಸು_str, "%lld", (ದೀರ್ಘ ದೀರ್ಘ)val);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (uval > 0x7fffffffffffffffULL) {
            cstr_printf(ಕೂಡಿಸು_str, "0x%llx", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)uval);
        } ಇಲ್ಲದಿದ್ದರೆ {
            val = (int64_t)uval;
            cstr_printf(ಕೂಡಿಸು_str, "%lld", (ದೀರ್ಘ ದೀರ್ಘ)val);
        }
      no_ಸ್ಥಾನಾಂತರ:;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(ಕೂಡಿಸು_str, "[x29,#%d]", (ಪೂರ್ಣಾಂಕ) sv->c.i);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ಆದರೆ (reg >= VT_CONST)
            tcc_ಆಂತರಿಕ_error("");
        cstr_printf(ಕೂಡಿಸು_str, "[x%d]", reg);
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* register case */
        reg = r & VT_VALMASK;
        ಆದರೆ (reg >= VT_CONST)
            tcc_ಆಂತರಿಕ_error("");

        ಆದರೆ (ARM64_FREG_ತಳ <= reg && reg <= ARM64_FREG_ಕೊನೆಯ) {
            fp_reg = reg - ARM64_FREG_ತಳ;
            ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&sv->type, &align);

            ಆದರೆ (modifier == 0)
                modifier = ಗಾತ್ರ_2 <= 4 ? 's'
                         : ಗಾತ್ರ_2 == 8 ? 'd'
                         : 'q';

            ಆಯ್ಕೆ (modifier) {
            ಸ್ಥಿತಿ 'b':
            ಸ್ಥಿತಿ 'h':
            ಸ್ಥಿತಿ 's':
            ಸ್ಥಿತಿ 'd':
            ಸ್ಥಿತಿ 'q':
            ಸ್ಥಿತಿ 'Z':
                cstr_printf(ಕೂಡಿಸು_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                ಹಿಂತಿರುಗಿ;
            ಪೂರ್ವನಿಯೋಜಿತ:
                tcc_error("invalid operand modifier for SIMD/FP register");
                ಹಿಂತಿರುಗಿ;
            }
        }

        /* choose register operand size */
        ಆದರೆ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            ಗಾತ್ರ_2 = 1;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            ಗಾತ್ರ_2 = 2;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            ಗಾತ್ರ_2 = 8;
        ಇಲ್ಲದಿದ್ದರೆ
            ಗಾತ್ರ_2 = 4;

        ಆದರೆ (modifier == 'x') {
            ಗಾತ್ರ_2 = 8;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (modifier == 'w' || modifier == 'k') {
            ಗಾತ್ರ_2 = 4;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (modifier == 'b') {
            ಗಾತ್ರ_2 = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (modifier == 'h') {
            ಗಾತ್ರ_2 = 2;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (modifier == 'q') {
            ಗಾತ್ರ_2 = 8;
        }

        ಆದರೆ (ಗಾತ್ರ_2 <= 4) {
            cstr_printf(ಕೂಡಿಸು_str, "w%d", reg);
        } ಇಲ್ಲದಿದ್ದರೆ {
            cstr_printf(ಕೂಡಿಸು_str, "x%d", reg);
        }
    }
}

ST_FUNC ಶೂನ್ಯ asm_gen_ಸಂಕೇತ(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands,
                          ಪೂರ್ಣಾಂಕ nb_outputs, ಪೂರ್ಣಾಂಕ is_output,
                          uint8_t *clobber_regs,
                          ಪೂರ್ಣಾಂಕ ಹೊರಹೋಗು_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ಪೂರ್ಣಾಂಕ i, reg, saved_ಎಣಿಕೆ, ರಾಶಿ_ಗಾತ್ರ, ರಾಶಿ_off;
    ಪೂರ್ಣಾಂಕ saved_regs[12];
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    ಸ್ಮರಣೆ_ನಕಲು(regs_allocated, clobber_regs, ಗಾತ್ರ(regs_allocated));
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ಆದರೆ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_ಎಣಿಕೆ = 0;
    ಗಾಗಿ (i = 0; i < ಗಾತ್ರ(reg_saved) / ಗಾತ್ರ(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ಆದರೆ (regs_allocated[reg])
            saved_regs[saved_ಎಣಿಕೆ++] = reg;
    }
    ರಾಶಿ_ಗಾತ್ರ = ((saved_ಎಣಿಕೆ + 1) / 2) * 16;

    ಆದರೆ (!is_output) {
        ಆದರೆ (saved_ಎಣಿಕೆ > 0) {
            gen_sub_imm(31, 31, ರಾಶಿ_ಗಾತ್ರ, 1, 0);

            ಗಾಗಿ (i = ರಾಶಿ_off = 0; i < saved_ಎಣಿಕೆ; ) {
                ಆದರೆ (i + 1 < saved_ಎಣಿಕೆ) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ರಾಶಿ_off, 3);
                    ರಾಶಿ_off += 16;
                    i += 2;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 ರಾಶಿ_off, 3);
                    i++;
                }
            }
        }

        ಗಾಗಿ (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ಆದರೆ (op->reg >= 0) {
                ಆದರೆ (op->is_ಸ್ಮರಣೆ) {
                    arm64_ತುಂಬು_ಸ್ಮರಣೆ_ಕಾರ್ಯಾಂಶ_ತಳ(op->reg, op->vt);
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (i >= nb_outputs || op->is_rw) {
                    ತುಂಬು(op->reg, op->vt);
                }
            }
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಗಾಗಿ (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            ಆದರೆ (op->reg >= 0) {
                ಆದರೆ (op->is_ಸ್ಮರಣೆ)
                    ಮುಂದುವರಿ;
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
                }
            }
        }

        ಆದರೆ (saved_ಎಣಿಕೆ > 0) {
            ಗಾಗಿ (i = ರಾಶಿ_off = 0; i < saved_ಎಣಿಕೆ; ) {
                ಆದರೆ (i + 1 < saved_ಎಣಿಕೆ) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ರಾಶಿ_off, 3);
                    ರಾಶಿ_off += 16;
                    i += 2;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 ರಾಶಿ_off, 3);
                    i++;
                }
            }
            gen_ಕೂಡಿಸು_imm(31, 31, ರಾಶಿ_ಗಾತ್ರ, 1, 0);
        }
    }
}

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

    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ = -1;
        op->ref_ಸೂಚ್ಯಂಕ = -1;
        op->reg = -1;
        op->is_ಸ್ಮರಣೆ = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ಆದರೆ (isnum(*str) || *str == '[') {
            k = ಕಂಡುಹಿಡಿ_constraint(operands, nb_operands, str, ಖಾಲಿ);
            ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
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

    ಗಾಗಿ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ಗಾಗಿ (i = 0; i < nb_operands - 1; i++) {
        ಗಾಗಿ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].ಆದ್ಯತೆ;
            p2 = operands[sorted_op[j]].ಆದ್ಯತೆ;
            ಆದರೆ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ಗಾಗಿ (i = 0; i < NB_ASM_REGS; i++) {
        ಆದರೆ (clobber_regs[i])
            regs_allocated[i] = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
        ಇಲ್ಲದಿದ್ದರೆ
            regs_allocated[i] = 0;
    }

    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        ಆದರೆ (op->ref_ಸೂಚ್ಯಂಕ >= 0)
            ಮುಂದುವರಿ;
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
            ಹೋಗು reg_ಸಿಕ್ಕಿತು;
        }
    try_ಮುಂದಿನ:
        c = *str++;
        ಆಯ್ಕೆ (c) {
        ಸ್ಥಿತಿ '=':
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ '+':
            op->is_rw = 1;
        ಸ್ಥಿತಿ '&':
            ಆದರೆ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_ಮುಖವಾಡ = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ 'r':
            ಗಾಗಿ (reg = 0; reg < 31; reg++) {
                ಆದರೆ (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            }
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ 'w':
        ಸ್ಥಿತಿ 'f':
            ಗಾಗಿ (reg = ARM64_FREG_ತಳ; reg <= ARM64_FREG_ಕೊನೆಯ; reg++) {
                ಆದರೆ (!is_reg_allocated(reg))
                    ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            }
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ 'x':
        ಸ್ಥಿತಿ 'y':
            ಗಾಗಿ (reg = ARM64_FREG_ತಳ; reg <= ARM64_FREG_ಕೊನೆಯ; reg++) {
                ಆದರೆ (!is_reg_allocated(reg))
                    ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            }
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ 'm':
        ಸ್ಥಿತಿ 'g':
            ಆದರೆ (j < nb_outputs || c == 'm') {
                ಆದರೆ (!arm64_prepare_ಸ್ಮರಣೆ_ಕಾರ್ಯಾಂಶ(op, regs_allocated))
                    ಹೋಗು try_ಮುಂದಿನ;
            }
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'Q':
            ಆದರೆ (!arm64_ಸ್ಮರಣೆ_is_ತಳ_only(op->vt))
                ಹೋಗು try_ಮುಂದಿನ;
            ಆದರೆ (!arm64_prepare_ಸ್ಮರಣೆ_ಕಾರ್ಯಾಂಶ(op, regs_allocated))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'S':
            ಆದರೆ ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'U':
            ಆದರೆ (str[0] != 'm' || str[1] != 'p')
                ಹೋಗು try_ಮುಂದಿನ;
            str += 2;
            ಆದರೆ (!arm64_ಸ್ಮರಣೆ_is_pair_suitable(op->vt))
                ಹೋಗು try_ಮುಂದಿನ;
            ಆದರೆ (!arm64_prepare_ಸ್ಮರಣೆ_ಕಾರ್ಯಾಂಶ(op, regs_allocated))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'i':
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'I':
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ಆದರೆ (!is_valid_ಕೂಡಿಸು_imm(op->vt->c.i))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'J':
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ಆದರೆ (!is_valid_ಕೂಡಿಸು_imm(-op->vt->c.i))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'K':
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ಆದರೆ (!is_valid_logical_imm(op->vt->c.i, 32))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'L':
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ಆದರೆ (!is_valid_logical_imm(op->vt->c.i, 64))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'M':
        ಸ್ಥಿತಿ 'N':
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ಆದರೆ (!is_valid_movw_imm(op->vt->c.i))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'Z':
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ಆದರೆ (op->vt->c.i != 0)
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'n':
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            ನಿಲ್ಲಿಸು;
        }
        ಆದರೆ (op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ >= 0) {
            operands[op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ].reg = op->reg;
            operands[op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ].is_llong = op->is_llong;
        }
        ಮುಂದುವರಿ;
    reg_ಸಿಕ್ಕಿತು:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_ಮುಖವಾಡ;
        ಆದರೆ (op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ >= 0) {
            operands[op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ].reg = op->reg;
            operands[op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ಆದರೆ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_ಸ್ಮರಣೆ) {
            ಗಾಗಿ (reg = 0; reg < 31; reg++) {
                ಆದರೆ (!(regs_allocated[reg] & REG_ಹೊರಹೋಗು_ಮುಖವಾಡ))
                    ಹೋಗು reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            ನಿಲ್ಲಿಸು;
        }
    }
}

/* Handle clobber list */
ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಪೂರ್ಣಾಂಕ reg;

    ಆದರೆ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ಹಿಂತಿರುಗಿ;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    ಆದರೆ (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC ಪೂರ್ಣಾಂಕ asm_parse_regvar(ಪೂರ್ಣಾಂಕ t)
{
    ಹಿಂತಿರುಗಿ arm64_parse_regvar(t);
}

/*************************************************************/
#ಆದರೆ_ಅಂತ್ಯ /* ndef TARGET_DEFS_ONLY */
