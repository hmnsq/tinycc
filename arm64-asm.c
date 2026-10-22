/*************************************************************/
/*
 *  ARM64 (AArch64) assembler for TCC
 *
 *  Based on ARM64 Architecture Reference Manual
 *  Supports AArch64 assembler parsing and extended inline asm
 *  with operands, constraints, and clobbers.
 */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONFIG_TCC_ASM
/* 32 general purpose + 32 SIMD/FP registers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_ASM_REGS 64

ST_FUNC ਖਾਲੀ g(ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ gen_le16(ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ gen_le32(ਪੂਰਨ c);

/*************************************************************/
#ਨਹੀਂਤਾਂ
/*************************************************************/

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

/* Register type flags */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_X     0x01  /* 64-bit general purpose */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_W     0x02  /* 32-bit general purpose */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_V     0x04  /* 128-bit SIMD */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_D     0x08  /* 64-bit FP */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_S     0x10  /* 32-bit FP */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_H     0x20  /* 16-bit FP */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
ਗਿਣਤੀ {
    OPT_REG,
    OPT_IM,
    OPT_ADDR,
    OPT_COND,
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_REG     (1 << OPT_REG)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_IM      (1 << OPT_IM)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_ADDR    (1 << OPT_ADDR)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_COND    (1 << OPT_COND)

/* Register allocation masks */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਬਾਹਰਲਾ_ਨਕਾਬ 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਵਿੱਚ_ਨਕਾਬ  0x02

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ is_reg_allocated(reg) (regs_allocated[reg] & reg_ਨਕਾਬ)

/* ARM64 register constants */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X0  0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X1  1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X2  2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X3  3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X4  4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X5  5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X6  6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X7  7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X8  8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X9  9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X10 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X11 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X12 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X13 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X14 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X15 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X16 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X17 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X18 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X19 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X20 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X21 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X22 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X23 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X24 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X25 25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X26 26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X27 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X28 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X29 29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_X30 30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_SP  31

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARM64_FREG_ਅਧਾਰ 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARM64_FREG_ਆਖਰੀ (ARM64_FREG_ਅਧਾਰ + 7)

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਸੰਕਾਰਜ {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t ਖਿਸਕਾਓ;
    uint8_t addr_ਬਹੁਲਕ;
    ਪੂਰਨ reg_tok;
    ਵਿਅੰਜਕ_ਮੁੱਲ e;
} ਸੰਕਾਰਜ;

ਗਿਣਤੀ {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
ਸਥਿਰ ਖਾਲੀ parse_addr_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op);

/* XXX: make it faster ? */
ST_FUNC ਖਾਲੀ g(ਪੂਰਨ c)
{
    ਪੂਰਨ ind1;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    ind1 = ind + 1;
    ਜੇ (ind1 > cur_ਪਾਠ_section->ਅੰਕੜੇ_allocated)
        section_realloc(cur_ਪਾਠ_section, ind1);
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind] = c;
    ind = ind1;
}

ST_FUNC ਖਾਲੀ gen_le16(ਪੂਰਨ c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC ਖਾਲੀ gen_le32(ਪੂਰਨ c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC ਖਾਲੀ gen_expr32(ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
ਸਥਿਰ ਖਾਲੀ emit_instr32(uint32_t val)
{
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    ਜੇ (ind + 4 > cur_ਪਾਠ_section->ਅੰਕੜੇ_allocated)
        section_realloc(cur_ਪਾਠ_section, ind + 4);
    write32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
ਸਥਿਰ ਪੂਰਨ arm64_parse_asm_reg(ਪੂਰਨ t)
{
    /* X registers (64-bit) */
    ਜੇ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ਵਾਪਸ t - TOK_ASM_x0;
    /* W registers (32-bit) */
    ਜੇ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ਵਾਪਸ t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    ਜੇ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ਵਾਪਸ (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    ਜੇ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ਵਾਪਸ (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    ਜੇ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ਵਾਪਸ (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    ਜੇ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ਵਾਪਸ (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    ਜੇ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ਵਾਪਸ (t - TOK_ASM_b0) + 32;
    /* Special registers */
    ਜੇ (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        ਵਾਪਸ 31;  /* SP/ZR encoded as 31 */
    ਵਾਪਸ -1;
}

/* Get register type from token */
ਸਥਿਰ uint8_t get_reg_type(ਪੂਰਨ t)
{
    ਜੇ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ਵਾਪਸ REG_X;
    ਜੇ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        ਵਾਪਸ REG_W;
    ਜੇ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        ਵਾਪਸ REG_V;
    ਜੇ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        ਵਾਪਸ REG_D;
    ਜੇ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        ਵਾਪਸ REG_S;
    ਜੇ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        ਵਾਪਸ REG_H;
    ਜੇ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        ਵਾਪਸ REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    ਜੇ (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        ਵਾਪਸ REG_X;
    ਜੇ (t == TOK_ASM_wzr)
        ਵਾਪਸ REG_W;
    ਵਾਪਸ REG_X;
}

/* Parse condition code */
ਸਥਿਰ ਪੂਰਨ parse_condition(ਪੂਰਨ t)
{
    ਚੋਣ (t) {
        ਹਾਲਤ TOK_ASM_eq: ਵਾਪਸ 0;
        ਹਾਲਤ TOK_ASM_ne: ਵਾਪਸ 1;
        ਹਾਲਤ TOK_ASM_cs:
        ਹਾਲਤ TOK_ASM_hs: ਵਾਪਸ 2;
        ਹਾਲਤ TOK_ASM_cc:
        ਹਾਲਤ TOK_ASM_lo: ਵਾਪਸ 3;
        ਹਾਲਤ TOK_ASM_mi: ਵਾਪਸ 4;
        ਹਾਲਤ TOK_ASM_pl: ਵਾਪਸ 5;
        ਹਾਲਤ TOK_ASM_vs: ਵਾਪਸ 6;
        ਹਾਲਤ TOK_ASM_vc: ਵਾਪਸ 7;
        ਹਾਲਤ TOK_ASM_hi: ਵਾਪਸ 8;
        ਹਾਲਤ TOK_ASM_ls: ਵਾਪਸ 9;
        ਹਾਲਤ TOK_ASM_ge: ਵਾਪਸ 10;
        ਹਾਲਤ TOK_ASM_lt: ਵਾਪਸ 11;
        ਹਾਲਤ TOK_ASM_gt: ਵਾਪਸ 12;
        ਹਾਲਤ TOK_ASM_le: ਵਾਪਸ 13;
        ਹਾਲਤ TOK_ASM_al: ਵਾਪਸ 14;
        ਮੂਲ: ਵਾਪਸ -1;
    }
}

ਸਥਿਰ ਪੂਰਨ parse_barrier_option_name(ਪੂਰਨ t)
{
    ਅਚਲ ਅੱਖਰ *name;

    ਜੇ (t < TOK_IDENT)
        ਵਾਪਸ -1;
    name = get_tok_str(t, ਨਿਰਾ);
    ਜੇ (!strcmp(name, "oshld")) ਵਾਪਸ 0x1;
    ਜੇ (!strcmp(name, "oshst")) ਵਾਪਸ 0x2;
    ਜੇ (!strcmp(name, "osh"))   ਵਾਪਸ 0x3;
    ਜੇ (!strcmp(name, "nshld")) ਵਾਪਸ 0x5;
    ਜੇ (!strcmp(name, "nshst")) ਵਾਪਸ 0x6;
    ਜੇ (!strcmp(name, "nsh"))   ਵਾਪਸ 0x7;
    ਜੇ (!strcmp(name, "ishld")) ਵਾਪਸ 0x9;
    ਜੇ (!strcmp(name, "ishst")) ਵਾਪਸ 0xA;
    ਜੇ (!strcmp(name, "ish"))   ਵਾਪਸ 0xB;
    ਜੇ (!strcmp(name, "ld"))    ਵਾਪਸ 0xD;
    ਜੇ (!strcmp(name, "st"))    ਵਾਪਸ 0xE;
    ਜੇ (!strcmp(name, "sy"))    ਵਾਪਸ 0xF;
    ਵਾਪਸ -1;
}

ਸਥਿਰ ਪੂਰਨ arm64_parse_regvar(ਪੂਰਨ t)
{
    ਜੇ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        ਵਾਪਸ t - TOK_ASM_x0;
    ਜੇ (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        ਵਾਪਸ ARM64_FREG_ਅਧਾਰ + (t - TOK_ASM_v0);
    ਜੇ (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        ਵਾਪਸ ARM64_FREG_ਅਧਾਰ + (t - TOK_ASM_d0);
    ਜੇ (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        ਵਾਪਸ ARM64_FREG_ਅਧਾਰ + (t - TOK_ASM_s0);
    ਜੇ (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        ਵਾਪਸ ARM64_FREG_ਅਧਾਰ + (t - TOK_ASM_h0);
    ਜੇ (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        ਵਾਪਸ ARM64_FREG_ਅਧਾਰ + (t - TOK_ASM_b0);
    ਵਾਪਸ -1;
}

/* Parse a single operand */
ਸਥਿਰ ਖਾਲੀ parse_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op)
{
    ਪੂਰਨ reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->ਖਿਸਕਾਓ = 0;
    op->addr_ਬਹੁਲਕ = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    ਜੇ (tok == '[') {
        parse_addr_ਸੰਕਾਰਜ(s1, op);
        ਵਾਪਸ;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    ਜੇ (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        ਅਗਲਾ();
        ਵਾਪਸ;
    }

    /* Condition code */
    reg = parse_condition(tok);
    ਜੇ (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        ਅਗਲਾ();
        ਵਾਪਸ;
    }

    /* Immediate or address expression */
    ਜੇ (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ(s1, &op->e);
        op->type = OP_IM;
    } ਨਹੀਂਤਾਂ ਜੇ (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } ਨਹੀਂਤਾਂ {
        asm_ਵਿਅੰਜਕ(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
ਸਥਿਰ ਖਾਲੀ parse_ਵਿਅੰਜਕ_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->ਖਿਸਕਾਓ = 0;
    op->addr_ਬਹੁਲਕ = ADDR_OFF;
    op->reg_tok = 0;

    ਜੇ (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        ਅਗਲਾ();
    asm_ਵਿਅੰਜਕ(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
ਸਥਿਰ ਖਾਲੀ parse_addr_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op)
{
    ਪੂਰਨ reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = ਨਿਰਾ;
    op->addr_ਬਹੁਲਕ = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    ਜੇ (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        ਵਾਪਸ;
    }
    op->reg = reg;
    op->reg_tok = tok;
    ਅਗਲਾ();
    /* Check for offset */
    ਜੇ (tok == ',') {
        ਅਗਲਾ();
        ਜੇ (tok == '#' || tok == '@' || tok == '$')
            ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ(s1, &op->e);
    }
    skip(']');
    ਜੇ (tok == '!') {
        op->addr_ਬਹੁਲਕ = ADDR_PRE;
        ਅਗਲਾ();
    } ਨਹੀਂਤਾਂ ਜੇ (tok == ',') {
        op->addr_ਬਹੁਲਕ = ADDR_POST;
        ਅਗਲਾ();
        ਜੇ (tok == '#' || tok == '@' || tok == '$')
            ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
ਸਥਿਰ ਖਾਲੀ gen_mov_with_ਅਧਾਰ(ਪੂਰਨ rd, uint16_t imm, ਪੂਰਨ ਖਿਸਕਾਓ,
                              ਪੂਰਨ is_64bit, uint32_t ਅਧਾਰ_opcode)
{
    uint32_t instr = ਅਧਾਰ_opcode;
    ਜੇ (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, ਖਿਸਕਾਓ);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ਸਥਿਰ ਖਾਲੀ gen_movz(ਪੂਰਨ rd, uint16_t imm, ਪੂਰਨ ਖਿਸਕਾਓ, ਪੂਰਨ is_64bit)
{
    gen_mov_with_ਅਧਾਰ(rd, imm, ਖਿਸਕਾਓ, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
ਸਥਿਰ ਖਾਲੀ gen_movn(ਪੂਰਨ rd, uint16_t imm, ਪੂਰਨ ਖਿਸਕਾਓ, ਪੂਰਨ is_64bit)
{
    gen_mov_with_ਅਧਾਰ(rd, imm, ਖਿਸਕਾਓ, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
ਸਥਿਰ ਖਾਲੀ gen_movk(ਪੂਰਨ rd, uint16_t imm, ਪੂਰਨ ਖਿਸਕਾਓ, ਪੂਰਨ is_64bit)
{
    gen_mov_with_ਅਧਾਰ(rd, imm, ਖਿਸਕਾਓ, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
ਸਥਿਰ ਖਾਲੀ gen_ਜੋੜੋ_imm(ਪੂਰਨ rd, ਪੂਰਨ rn, uint32_t imm, ਪੂਰਨ is_64bit, ਪੂਰਨ setflags)
{
    uint32_t instr = ARM64_ਜੋੜੋ_IMM;
    uint32_t imm12;

    ਜੇ (is_64bit) instr |= ARM64_SF(1);
    ਜੇ (setflags) instr |= ARM64_S(1);

    ਜੇ (imm <= 0xFFF) {
        imm12 = imm;
    } ਨਹੀਂਤਾਂ ਜੇ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } ਨਹੀਂਤਾਂ {
        tcc_error("add immediate out of range");
        ਵਾਪਸ;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
ਸਥਿਰ ਖਾਲੀ gen_sub_imm(ਪੂਰਨ rd, ਪੂਰਨ rn, uint32_t imm, ਪੂਰਨ is_64bit, ਪੂਰਨ setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    ਜੇ (is_64bit) instr |= ARM64_SF(1);
    ਜੇ (setflags) instr |= ARM64_S(1);

    ਜੇ (imm <= 0xFFF) {
        imm12 = imm;
    } ਨਹੀਂਤਾਂ ਜੇ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } ਨਹੀਂਤਾਂ {
        tcc_error("sub immediate out of range");
        ਵਾਪਸ;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
ਸਥਿਰ ਖਾਲੀ gen_dp_reg(uint32_t opcode, ਪੂਰਨ rd, ਪੂਰਨ rn, ਪੂਰਨ rm, ਪੂਰਨ is_64bit)
{
    uint32_t instr = opcode;
    ਜੇ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
ਸਥਿਰ ਖਾਲੀ gen_ldst_imm(uint32_t ਅਧਾਰ_opcode, ਪੂਰਨ rt, ਪੂਰਨ rn,
                         int32_t ਵਿੱਥ, ਪੂਰਨ ਮਾਪ_log2)
{
    uint32_t instr = ਅਧਾਰ_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    ਜੇ (ਵਿੱਥ >= 0 && !(ਵਿੱਥ & ((1 << ਮਾਪ_log2) - 1))) {
    imm12 = ਵਿੱਥ >> ਮਾਪ_log2;
        ਜੇ (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            ਵਾਪਸ;
        }
    }

    ਚੋਣ (ਅਧਾਰ_opcode) {
    ਹਾਲਤ ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; ਰੋਕੋ;
    ਹਾਲਤ ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; ਰੋਕੋ;
    ਹਾਲਤ ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; ਰੋਕੋ;
    ਹਾਲਤ ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; ਰੋਕੋ;
    ਹਾਲਤ ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; ਰੋਕੋ;
    ਹਾਲਤ ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; ਰੋਕੋ;
    ਹਾਲਤ ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; ਰੋਕੋ;
    ਹਾਲਤ ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; ਰੋਕੋ;
    ਹਾਲਤ ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; ਰੋਕੋ;
    ਹਾਲਤ ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; ਰੋਕੋ;
    }

    ਜੇ (unscaled_opcode && ਵਿੱਥ >= -256 && ਵਿੱਥ <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)ਵਿੱਥ & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        ਵਾਪਸ;
    }

    ਜੇ (ਵਿੱਥ & ((1 << ਮਾਪ_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
ਸਥਿਰ ਖਾਲੀ gen_ldst_pair(uint32_t ਅਧਾਰ_opcode, ਪੂਰਨ rt, ਪੂਰਨ rt2, ਪੂਰਨ rn,
                          int32_t ਵਿੱਥ, ਪੂਰਨ ਮਾਪ_log2)
{
    int32_t imm7;
    uint32_t instr = ਅਧਾਰ_opcode;

    ਜੇ (ਵਿੱਥ & ((1 << ਮਾਪ_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = ਵਿੱਥ >> ਮਾਪ_log2;
    ਜੇ (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
ਸਥਿਰ ਖਾਲੀ gen_b_or_bl(int32_t ਵਿੱਥ, uint32_t ਅਧਾਰ_opcode)
{
    uint32_t instr = ਅਧਾਰ_opcode;
    instr |= ARM64_OFFSET26(ਵਿੱਥ);
    emit_instr32(instr);
}

ਸਥਿਰ ਖਾਲੀ gen_b(int32_t ਵਿੱਥ)
{
    gen_b_or_bl(ਵਿੱਥ, ARM64_B);
}

/* Generate BL (branch with link) */
ਸਥਿਰ ਖਾਲੀ gen_bl(int32_t ਵਿੱਥ)
{
    gen_b_or_bl(ਵਿੱਥ, ARM64_BL);
}

/* Generate BR (branch to register) */
ਸਥਿਰ ਖਾਲੀ gen_br(ਪੂਰਨ rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
ਸਥਿਰ ਖਾਲੀ gen_blr(ਪੂਰਨ rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
ਸਥਿਰ ਖਾਲੀ gen_ret(ਪੂਰਨ rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
ਸਥਿਰ ਖਾਲੀ gen_b_cond(ਪੂਰਨ cond, int32_t ਵਿੱਥ)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(ਵਿੱਥ);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
ਸਥਿਰ ਖਾਲੀ gen_cbz_or_cbnz(ਪੂਰਨ rt, int32_t ਵਿੱਥ, ਪੂਰਨ is_64bit, uint32_t ਅਧਾਰ_opcode)
{
    uint32_t instr = ਅਧਾਰ_opcode;
    ਜੇ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(ਵਿੱਥ);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

ਸਥਿਰ ਖਾਲੀ gen_cbz(ਪੂਰਨ rt, int32_t ਵਿੱਥ, ਪੂਰਨ is_64bit)
{
    gen_cbz_or_cbnz(rt, ਵਿੱਥ, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
ਸਥਿਰ ਖਾਲੀ gen_cbnz(ਪੂਰਨ rt, int32_t ਵਿੱਥ, ਪੂਰਨ is_64bit)
{
    gen_cbz_or_cbnz(rt, ਵਿੱਥ, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
ਸਥਿਰ ਖਾਲੀ gen_mov_reg(ਪੂਰਨ rd, ਪੂਰਨ rm, ਪੂਰਨ is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    ਜੇ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ਸਥਿਰ ਪੂਰਨ arm64_asm_encode_bimm64(uint64_t x)
{
    ਪੂਰਨ neg, rep, pos, len;

    neg = x & 1;
    ਜੇ (neg)
        x = ~x;
    ਜੇ (!x)
        ਵਾਪਸ -1;

    ਜੇ (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    ਨਹੀਂਤਾਂ ਜੇ (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    ਨਹੀਂਤਾਂ ਜੇ (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    ਨਹੀਂਤਾਂ ਜੇ (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    ਨਹੀਂਤਾਂ ਜੇ (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    ਨਹੀਂਤਾਂ
        rep = 64;

    pos = 0;
    ਜੇ (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    ਜੇ (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    ਜੇ (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    ਜੇ (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    ਜੇ (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    ਜੇ (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    ਜੇ (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    ਜੇ (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    ਜੇ (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    ਜੇ (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    ਜੇ (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    ਜੇ (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    ਜੇ (x)
        ਵਾਪਸ -1;
    ਜੇ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    ਵਾਪਸ ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ਸਥਿਰ ਖਾਲੀ gen_logical_imm(uint32_t opcode, ਪੂਰਨ rd, ਪੂਰਨ rn,
                            uint64_t imm, ਪੂਰਨ is_64bit)
{
    uint32_t instr;
    uint64_t val;
    ਪੂਰਨ enc;

    ਜੇ (is_64bit)
        val = imm;
    ਨਹੀਂਤਾਂ {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    ਜੇ (enc < 0) {
        tcc_error("logical immediate out of range");
        ਵਾਪਸ;
    }

    instr = opcode;
    ਜੇ (is_64bit)
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
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ constraint_ਤਰਜੀਹ(ਅਚਲ ਅੱਖਰ *str)
{
    ਪੂਰਨ ਤਰਜੀਹ, c, pr;

    ਤਰਜੀਹ = 0;
    ਲਈ (;;) {
        c = *str++;
        ਜੇ (c == '\0')
            ਰੋਕੋ;
        ਚੋਣ (c) {
        ਹਾਲਤ '=':
        ਹਾਲਤ '+':
        ਹਾਲਤ '&':
            ਜਾਰੀ;
        ਹਾਲਤ 'r':
            pr = 1;
            ਰੋਕੋ;
        ਹਾਲਤ 'w':
        ਹਾਲਤ 'f':
        ਹਾਲਤ 'x':
        ਹਾਲਤ 'y':
            pr = 3;
            ਰੋਕੋ;
        ਹਾਲਤ 'm':
        ਹਾਲਤ 'Q':
            pr = 4;
            ਰੋਕੋ;
        ਹਾਲਤ 'i':
        ਹਾਲਤ 'S':
            pr = 5;
            ਰੋਕੋ;
        ਹਾਲਤ 'U':
            ਜੇ (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                ਰੋਕੋ;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            ਰੋਕੋ;
        ਹਾਲਤ 'I':
        ਹਾਲਤ 'J':
        ਹਾਲਤ 'K':
        ਹਾਲਤ 'L':
        ਹਾਲਤ 'M':
        ਹਾਲਤ 'N':
        ਹਾਲਤ 'Z':
            pr = 6;
            ਰੋਕੋ;
        ਹਾਲਤ 'n':
            pr = 7;
            ਰੋਕੋ;
        ਹਾਲਤ 'g':
            pr = 8;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            ਰੋਕੋ;
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

ਸਥਿਰ ਪੂਰਨ is_valid_ਜੋੜੋ_imm(int64_t val)
{
    ਵਾਪਸ val >= 0 && val <= 4095;
}

ਸਥਿਰ ਪੂਰਨ is_valid_logical_imm(int64_t val, ਪੂਰਨ ਬਿੱਟ)
{
    uint64_t uval;

    uval = (uint64_t)val;
    ਜੇ (ਬਿੱਟ == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    ਵਾਪਸ arm64_asm_encode_bimm64(uval) >= 0;
}

ਸਥਿਰ ਪੂਰਨ is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    ਜੇ (uval <= 0xFFFF)
        ਵਾਪਸ 1;
    ਜੇ (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        ਵਾਪਸ 1;
    ਜੇ (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        ਵਾਪਸ 1;
    ਜੇ ((uval & 0xFFFFFFFF00000000ULL) == 0)
        ਵਾਪਸ 1;

    ਵਾਪਸ 0;
}

ਸਥਿਰ ਪੂਰਨ is_valid_movw_ਖਿਸਕਾਓ(ਪੂਰਨ ਖਿਸਕਾਓ, ਪੂਰਨ is_64bit)
{
    ਜੇ (ਖਿਸਕਾਓ < 0 || (ਖਿਸਕਾਓ & 15))
        ਵਾਪਸ 0;
    ਜੇ (ਖਿਸਕਾਓ > (is_64bit ? 48 : 16))
        ਵਾਪਸ 0;
    ਵਾਪਸ 1;
}

ਸਥਿਰ ਪੂਰਨ arm64_ਸਮ੍ਰਿਤੀ_is_ਅਧਾਰ_only(ਅਚਲ SValue *sv)
{
    ਪੂਰਨ r;

    r = sv->r;
    ਜੇ ((r & VT_VALMASK) == VT_CONST)
        ਵਾਪਸ 0;
    ਜੇ ((r & VT_VALMASK) == VT_LOCAL)
        ਵਾਪਸ 0;
    ਜੇ ((r & VT_VALMASK) == VT_LLOCAL)
        ਵਾਪਸ 1;
    ਜੇ (r & VT_LVAL)
        ਵਾਪਸ (r & VT_VALMASK) < VT_CONST;
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਪੂਰਨ arm64_ਸਮ੍ਰਿਤੀ_is_pair_suitable(ਅਚਲ SValue *sv)
{
    int64_t ਵਿੱਥ;

    ਜੇ (arm64_ਸਮ੍ਰਿਤੀ_is_ਅਧਾਰ_only(sv))
        ਵਾਪਸ 1;
    ਜੇ ((sv->r & VT_VALMASK) != VT_LOCAL)
        ਵਾਪਸ 0;

    ਵਿੱਥ = (int64_t)sv->c.i;
    ਵਾਪਸ (ਵਿੱਥ & 7) == 0 && ਵਿੱਥ >= -512 && ਵਿੱਥ <= 504;
}

ਸਥਿਰ ਪੂਰਨ arm64_int_reg_is_allocatable(ਪੂਰਨ reg)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਵਾਪਸ reg >= TREG_X0 && reg <= TREG_X17;
#ਨਹੀਂਤਾਂ
    ਵਾਪਸ reg >= TREG_X0 && reg <= TREG_X30;
#ਜੇ_ਅੰਤ
}

ਸਥਿਰ ਪੂਰਨ arm64_ਸਮ੍ਰਿਤੀ_needs_ਪਤਾ_reg(ਅਚਲ SValue *sv)
{
    ਪੂਰਨ r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    ਜੇ (!(r & VT_LVAL))
        ਵਾਪਸ 0;
    ਚੋਣ (r & VT_VALMASK) {
    ਹਾਲਤ VT_LOCAL:
    ਹਾਲਤ VT_LLOCAL:
    ਹਾਲਤ VT_CONST:
        ਵਾਪਸ 1;
    }
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਪੂਰਨ arm64_prepare_ਸਮ੍ਰਿਤੀ_ਸੰਕਾਰਜ(ASMOperand *op, uint8_t *regs_allocated)
{
    ਪੂਰਨ reg;

    ਜੇ (!arm64_ਸਮ੍ਰਿਤੀ_needs_ਪਤਾ_reg(op->vt))
        ਵਾਪਸ 1;

    ਲਈ (reg = 0; reg < 31; reg++) {
        ਜੇ (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_ਵਿੱਚ_ਨਕਾਬ)) {
            regs_allocated[reg] |= REG_ਵਿੱਚ_ਨਕਾਬ;
            op->reg = reg;
            op->is_ਸਮ੍ਰਿਤੀ = 1;
            ਵਾਪਸ 1;
        }
    }
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਖਾਲੀ arm64_ਲੱਦੋ_ਸਮ੍ਰਿਤੀ_ਸੰਕਾਰਜ_ਅਧਾਰ(ਪੂਰਨ reg, SValue *sv)
{
    SValue ਅਧਾਰ;
    ਪੂਰਨ rval;

    ਅਧਾਰ = *sv;
    ਅਧਾਰ.type.t = VT_PTR;
    rval = ਅਧਾਰ.r & VT_VALMASK;
    ਜੇ (rval == VT_LLOCAL) {
        ਅਧਾਰ.r = (ਅਧਾਰ.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } ਨਹੀਂਤਾਂ ਜੇ (rval == VT_CONST || rval == VT_LOCAL) {
        ਅਧਾਰ.r &= ~VT_LVAL;
    } ਨਹੀਂਤਾਂ {
        tcc_ਅੰਦਰੂਨੀ_error("unsupported ARM64 memory operand base");
    }
    ਲੱਦੋ(reg, &ਅਧਾਰ);
}

ਸਥਿਰ ਪੂਰਨ ਸੰਕਾਰਜ_is_sp(ਅਚਲ ਸੰਕਾਰਜ *op)
{
    ਵਾਪਸ op->reg_tok == TOK_ASM_sp;
}

ਸਥਿਰ ਪੂਰਨ parse_sysreg_name(ਪੂਰਨ t)
{
    ਅਚਲ ਅੱਖਰ *name;

    ਜੇ (t < TOK_IDENT)
        ਵਾਪਸ -1;
    name = get_tok_str(t, ਨਿਰਾ);
    ਜੇ (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        ਵਾਪਸ 0;
    ਜੇ (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        ਵਾਪਸ 1;
    ਵਾਪਸ -1;
}

ਸਥਿਰ ਖਾਲੀ gen_mrs(ਪੂਰਨ rt, ਪੂਰਨ sysreg)
{
    uint32_t instr;

    ਚੋਣ (sysreg) {
        ਹਾਲਤ 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            ਰੋਕੋ;
        ਹਾਲਤ 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("unsupported system register");
            ਵਾਪਸ;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

ਸਥਿਰ ਖਾਲੀ gen_msr(ਪੂਰਨ rt, ਪੂਰਨ sysreg)
{
    uint32_t instr;

    ਚੋਣ (sysreg) {
        ਹਾਲਤ 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            ਰੋਕੋ;
        ਹਾਲਤ 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("unsupported system register");
            ਵਾਪਸ;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
ਸਥਿਰ ਖਾਲੀ gen_nop(ਖਾਲੀ)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
ਸਥਿਰ ਖਾਲੀ gen_ਖਿਸਕਾਓ(ਪੂਰਨ rd, ਪੂਰਨ rn, ਪੂਰਨ rm_or_imm, ਪੂਰਨ ਖਿਸਕਾਓ_type, ਪੂਰਨ is_imm, ਪੂਰਨ is_64bit)
{
    uint32_t instr;
    ਪੂਰਨ ਚੌੜਾਈ = is_64bit ? 64 : 32;

    ਜੇ (is_imm) {
        /* Shift by immediate */
        ਚੋਣ (ਖਿਸਕਾਓ_type) {
            ਹਾਲਤ 0: /* LSL - UBFM alias */
                ਜੇ (rm_or_imm < 0 || rm_or_imm >= ਚੌੜਾਈ) {
                    tcc_error("shift immediate out of range");
                    ਵਾਪਸ;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((ਚੌੜਾਈ - rm_or_imm) & (ਚੌੜਾਈ - 1));
                instr |= ARM64_IMM_S(ਚੌੜਾਈ - rm_or_imm - 1);
                ਰੋਕੋ;
            ਹਾਲਤ 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                ਜੇ (rm_or_imm < 0 || rm_or_imm >= ਚੌੜਾਈ) {
                    tcc_error("shift immediate out of range");
                    ਵਾਪਸ;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(ਚੌੜਾਈ - 1);
                ਰੋਕੋ;
            ਹਾਲਤ 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                ਜੇ (rm_or_imm < 0 || rm_or_imm >= ਚੌੜਾਈ) {
                    tcc_error("shift immediate out of range");
                    ਵਾਪਸ;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(ਚੌੜਾਈ - 1);
                ਰੋਕੋ;
            ਹਾਲਤ 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                ਜੇ (rm_or_imm < 0 || rm_or_imm >= ਚੌੜਾਈ) {
                    tcc_error("shift immediate out of range");
                    ਵਾਪਸ;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                ਵਾਪਸ;
            ਮੂਲ:
                tcc_error("unknown shift type");
                ਵਾਪਸ;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } ਨਹੀਂਤਾਂ {
        /* Shift by register */
        ਚੋਣ (ਖਿਸਕਾਓ_type) {
            ਹਾਲਤ 0: /* LSL */
                instr = ARM64_LSL_REG;
                ਰੋਕੋ;
            ਹਾਲਤ 1: /* LSR */
                instr = ARM64_LSR_REG;
                ਰੋਕੋ;
            ਹਾਲਤ 2: /* ASR */
                instr = ARM64_ASR_REG;
                ਰੋਕੋ;
            ਹਾਲਤ 3: /* ROR */
                instr = ARM64_ROR_REG;
                ਰੋਕੋ;
            ਮੂਲ:
                tcc_error("unknown shift type");
                ਵਾਪਸ;
        }
        ਜੇ (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
ਸਥਿਰ ਖਾਲੀ asm_ਖਿਸਕਾਓ(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ op1, op2, op3;
    ਪੂਰਨ rd, rn, ਖਿਸਕਾਓ_amount;
    ਪੂਰਨ ਖਿਸਕਾਓ_type;
    ਪੂਰਨ is_64bit = 1;

    ਚੋਣ (token) {
        ਹਾਲਤ TOK_ASM_lsl:
            ਖਿਸਕਾਓ_type = 0;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_lsr:
            ਖਿਸਕਾਓ_type = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_asr:
            ਖਿਸਕਾਓ_type = 2;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_ror:
            ਖਿਸਕਾਓ_type = 3;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("unknown shift instruction");
            ਵਾਪਸ;
    }

    parse_ਸੰਕਾਰਜ(s1, &op1);
    ਜੇ (tok == ',') ਅਗਲਾ();
    parse_ਸੰਕਾਰਜ(s1, &op2);

    ਜੇ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ਵਾਪਸ;
    }
    ਜੇ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ਵਾਪਸ;
    }

    rd = op1.reg;
    rn = op2.reg;

    ਜੇ (tok == ',') {
        ਅਗਲਾ();
        parse_ਸੰਕਾਰਜ(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ਜੇ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ਵਾਪਸ;
        }
        ਜੇ (op3.type & OP_REG) {
            ਜੇ (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ਵਾਪਸ;
            }
            gen_ਖਿਸਕਾਓ(rd, rn, op3.reg, ਖਿਸਕਾਓ_type, 0, is_64bit);
        } ਨਹੀਂਤਾਂ ਜੇ (op3.type & OP_IM) {
            ਖਿਸਕਾਓ_amount = op3.e.v;
            gen_ਖਿਸਕਾਓ(rd, rn, ਖਿਸਕਾਓ_amount, ਖਿਸਕਾਓ_type, 1, is_64bit);
        } ਨਹੀਂਤਾਂ {
            tcc_error("shift requires immediate or register operand");
        }
    } ਨਹੀਂਤਾਂ {
        tcc_error("shift requires immediate or register operand");
        ਵਾਪਸ;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
ਸਥਿਰ ਖਾਲੀ gen_barrier(ਪੂਰਨ barrier_type, ਪੂਰਨ option)
{
    uint32_t instr;

    ਚੋਣ (barrier_type) {
        ਹਾਲਤ 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            ਰੋਕੋ;
        ਹਾਲਤ 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            ਰੋਕੋ;
        ਹਾਲਤ 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("unknown barrier type");
            ਵਾਪਸ;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
ਸਥਿਰ ਖਾਲੀ asm_barrier(TCCState *s1, ਪੂਰਨ token)
{
    ਪੂਰਨ barrier_type, option;
    ਸੰਕਾਰਜ op;

    ਚੋਣ (token) {
        ਹਾਲਤ TOK_ASM_isb:
            barrier_type = 0;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_dsb:
            barrier_type = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_dmb:
            barrier_type = 2;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("unknown barrier instruction");
            ਵਾਪਸ;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    ਜੇ (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        ਜੇ (option >= 0) {
            ਅਗਲਾ();
        } ਨਹੀਂਤਾਂ {
            parse_ਸੰਕਾਰਜ(s1, &op);
            ਜੇ (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                ਵਾਪਸ;
            }
            ਜੇ (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                ਵਾਪਸ;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
ਸਥਿਰ ਖਾਲੀ gen_mov_imm(ਪੂਰਨ rd, uint64_t imm, ਪੂਰਨ is_64bit)
{
    uint16_t hw;
    ਪੂਰਨ i, ਪਹਿਲਾ = 1;

    ਲਈ (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        ਜੇ (hw != 0 || i == 0) {
            ਜੇ (ਪਹਿਲਾ) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                ਪਹਿਲਾ = 0;
            } ਨਹੀਂਤਾਂ {
                gen_movk(rd, hw, i, is_64bit);
            }
        } ਨਹੀਂਤਾਂ ਜੇ (!ਪਹਿਲਾ) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
ਸਥਿਰ ਖਾਲੀ asm_mov(TCCState *s1)
{
    ਸੰਕਾਰਜ op1, op2;
    ਪੂਰਨ rd, rn;
    ਪੂਰਨ is_64bit;

    parse_ਸੰਕਾਰਜ(s1, &op1);
    ਜੇ (tok == ',') ਅਗਲਾ();
    parse_ਸੰਕਾਰਜ(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    ਜੇ (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        ਜੇ (ਸੰਕਾਰਜ_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            ਵਾਪਸ;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } ਨਹੀਂਤਾਂ ਜੇ (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        ਜੇ (ਸੰਕਾਰਜ_is_sp(&op1) || ਸੰਕਾਰਜ_is_sp(&op2))
            gen_ਜੋੜੋ_imm(rd, rn, 0, 1, 0);
        ਨਹੀਂਤਾਂ
            gen_mov_reg(rd, rn, is_64bit);
    } ਨਹੀਂਤਾਂ {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
ਸਥਿਰ ਖਾਲੀ asm_ਅੰਕੜੇ_proc(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ op1, op2, op3;
    ਪੂਰਨ rd, rn, rm;
    ਪੂਰਨ is_64bit = 1;
    uint32_t opcode;

    ਚੋਣ (token) {
        ਹਾਲਤ TOK_ASM_ਜੋੜੋ:
        ਹਾਲਤ TOK_ASM_adds:
            opcode = token == TOK_ASM_ਜੋੜੋ ? ARM64_ਜੋੜੋ_REG : ARM64_ADDS_REG;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_sub:
        ਹਾਲਤ TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_and:
        ਹਾਲਤ TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("unsupported data processing instruction");
            ਵਾਪਸ;
    }

    parse_ਸੰਕਾਰਜ(s1, &op1);
    ਜੇ (tok == ',') ਅਗਲਾ();
    parse_ਸੰਕਾਰਜ(s1, &op2);

    ਜੇ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ਵਾਪਸ;
    }
    ਜੇ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ਵਾਪਸ;
    }

    rd = op1.reg;
    rn = op2.reg;

    ਜੇ (tok == ',') {
        ਅਗਲਾ();
        parse_ਸੰਕਾਰਜ(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ਜੇ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            ਵਾਪਸ;
        }
        ਜੇ (op3.type & OP_IM) {
            ਜੇ (token == TOK_ASM_ਜੋੜੋ || token == TOK_ASM_adds)
                gen_ਜੋੜੋ_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            ਨਹੀਂਤਾਂ ਜੇ (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            ਨਹੀਂਤਾਂ ਜੇ (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            ਨਹੀਂਤਾਂ ਜੇ (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            ਨਹੀਂਤਾਂ ਜੇ (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_ਅਧਾਰ, rd, rn, op3.e.v, is_64bit);
            ਨਹੀਂਤਾਂ ਜੇ (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            ਨਹੀਂਤਾਂ
                tcc_error("immediate operand not valid for this instruction");
        } ਨਹੀਂਤਾਂ {
            ਜੇ (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                ਵਾਪਸ;
            }
            rm = op3.reg;
            ਜੇ (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                ਵਾਪਸ;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } ਨਹੀਂਤਾਂ ਜੇ (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } ਨਹੀਂਤਾਂ {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
ਸਥਿਰ ਖਾਲੀ asm_ldst(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ op1, op2;
    ਪੂਰਨ rt, rn;
    int32_t ਵਿੱਥ = 0;
    ਪੂਰਨ ਮਾਪ_log2 = 3;
    uint32_t ਅਧਾਰ_opcode;

    parse_ਸੰਕਾਰਜ(s1, &op1);
    ਜੇ (tok == ',') ਅਗਲਾ();
    parse_ਸੰਕਾਰਜ(s1, &op2);

    ਜੇ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ਵਾਪਸ;
    }
    ਜੇ (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        ਵਾਪਸ;
    }

    rt = op1.reg;
    rn = op2.reg;
    ਵਿੱਥ = op2.e.v;

    ਚੋਣ (token) {
        ਹਾਲਤ TOK_ASM_ldr:
            ਜੇ (op1.reg_type & REG_X) {
                ਅਧਾਰ_opcode = ARM64_LDR_X;
                ਮਾਪ_log2 = 3;
            } ਨਹੀਂਤਾਂ ਜੇ (op1.reg_type & REG_W) {
                ਅਧਾਰ_opcode = ARM64_LDR_W;
                ਮਾਪ_log2 = 2;
            } ਨਹੀਂਤਾਂ ਜੇ (op1.reg_type & REG_D) {
                ਅਧਾਰ_opcode = ARM64_LDR_D;
                ਮਾਪ_log2 = 3;
            } ਨਹੀਂਤਾਂ {
                tcc_error("ldr requires a w, x, or d register");
                ਵਾਪਸ;
            }
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_ldrb:
            ਅਧਾਰ_opcode = ARM64_LDR_B;
            ਮਾਪ_log2 = 0;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_ldrh:
            ਅਧਾਰ_opcode = ARM64_LDR_H;
            ਮਾਪ_log2 = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_str:
            ਜੇ (op1.reg_type & REG_X) {
                ਅਧਾਰ_opcode = ARM64_STR_X;
                ਮਾਪ_log2 = 3;
            } ਨਹੀਂਤਾਂ ਜੇ (op1.reg_type & REG_W) {
                ਅਧਾਰ_opcode = ARM64_STR_W;
                ਮਾਪ_log2 = 2;
            } ਨਹੀਂਤਾਂ ਜੇ (op1.reg_type & REG_D) {
                ਅਧਾਰ_opcode = ARM64_STR_D;
                ਮਾਪ_log2 = 3;
            } ਨਹੀਂਤਾਂ {
                tcc_error("str requires a w, x, or d register");
                ਵਾਪਸ;
            }
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_strb:
            ਅਧਾਰ_opcode = ARM64_STR_B;
            ਮਾਪ_log2 = 0;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_strh:
            ਅਧਾਰ_opcode = ARM64_STR_H;
            ਮਾਪ_log2 = 1;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("unsupported load/store instruction");
            ਵਾਪਸ;
    }

    ਜੇ (op2.addr_ਬਹੁਲਕ != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(ਅਧਾਰ_opcode, rt, rn, ਵਿੱਥ, ਮਾਪ_log2);
}

ਸਥਿਰ ਖਾਲੀ asm_ldst_pair(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ op1, op2, op3;
    uint32_t ਅਧਾਰ_opcode;
    ਪੂਰਨ ਮਾਪ_log2 = 3;

    parse_ਸੰਕਾਰਜ(s1, &op1);
    ਜੇ (tok == ',')
        ਅਗਲਾ();
    parse_ਸੰਕਾਰਜ(s1, &op2);
    ਜੇ (tok == ',')
        ਅਗਲਾ();
    parse_ਸੰਕਾਰਜ(s1, &op3);

    ਜੇ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ਵਾਪਸ;
    }
    ਜੇ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        ਵਾਪਸ;
    }
    ਜੇ (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    ਜੇ ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        ਜੇ (token == TOK_ASM_stp) {
            ਅਧਾਰ_opcode = op3.addr_ਬਹੁਲਕ == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_ਬਹੁਲਕ == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } ਨਹੀਂਤਾਂ {
            ਅਧਾਰ_opcode = op3.addr_ਬਹੁਲਕ == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_ਬਹੁਲਕ == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } ਨਹੀਂਤਾਂ ਜੇ ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        ਜੇ (token == TOK_ASM_stp) {
            ਅਧਾਰ_opcode = op3.addr_ਬਹੁਲਕ == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_ਬਹੁਲਕ == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } ਨਹੀਂਤਾਂ {
            ਅਧਾਰ_opcode = op3.addr_ਬਹੁਲਕ == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_ਬਹੁਲਕ == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } ਨਹੀਂਤਾਂ {
        tcc_error("stp/ldp requires matching x or d registers");
        ਵਾਪਸ;
    }

    gen_ldst_pair(ਅਧਾਰ_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, ਮਾਪ_log2);
}

ਸਥਿਰ ਖਾਲੀ asm_sysreg(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ op;
    ਪੂਰਨ sysreg;

    ਜੇ (token == TOK_ASM_mrs) {
        parse_ਸੰਕਾਰਜ(s1, &op);
        ਜੇ (tok == ',')
            ਅਗਲਾ();
        sysreg = parse_sysreg_name(tok);
        ਜੇ (sysreg < 0)
            tcc_error("unsupported system register");
        ਅਗਲਾ();
        gen_mrs(op.reg, sysreg);
        ਵਾਪਸ;
    }

    sysreg = parse_sysreg_name(tok);
    ਜੇ (sysreg < 0)
        tcc_error("unsupported system register");
    ਅਗਲਾ();
    ਜੇ (tok == ',')
        ਅਗਲਾ();
    parse_ਸੰਕਾਰਜ(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
ਸਥਿਰ ਪੂਰਨ get_branch_condition(ਪੂਰਨ branch_token)
{
    ਪੂਰਨ cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    ਚੋਣ (branch_token) {
        ਹਾਲਤ TOK_ASM_beq: cond_token = TOK_ASM_eq; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bne: cond_token = TOK_ASM_ne; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bcs:
        ਹਾਲਤ TOK_ASM_bhs: cond_token = TOK_ASM_cs; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bcc:
        ਹਾਲਤ TOK_ASM_blo: cond_token = TOK_ASM_cc; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bmi: cond_token = TOK_ASM_mi; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bpl: cond_token = TOK_ASM_pl; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bvs: cond_token = TOK_ASM_vs; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bvc: cond_token = TOK_ASM_vc; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bhi: cond_token = TOK_ASM_hi; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bls: cond_token = TOK_ASM_ls; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bge: cond_token = TOK_ASM_ge; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_blt: cond_token = TOK_ASM_lt; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_bgt: cond_token = TOK_ASM_gt; ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_ble: cond_token = TOK_ASM_le; ਰੋਕੋ;
        ਮੂਲ: ਵਾਪਸ -1;
    }

    ਵਾਪਸ parse_condition(cond_token);
}

/* Handle branch instructions */
ਸਥਿਰ ਖਾਲੀ asm_branch(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ op;
    ਪੂਰਨ cond;
    Sym *sym;
    int32_t ਵਿੱਥ;

    /* ret can be used without operand */
    ਜੇ (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        ਵਾਪਸ;
    }

    ਜੇ (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_ਸੰਕਾਰਜ(s1, &op);
    ਨਹੀਂਤਾਂ
        parse_ਵਿਅੰਜਕ_ਸੰਕਾਰਜ(s1, &op);

    ਜੇ (op.type & OP_IM) {
        sym = op.e.sym;
        ਜੇ (sym) {
            /* Symbolic address - emit relocation */
            ਵਿੱਥ = 0;

            cond = get_branch_condition(token);
            ਜੇ (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_ਪਾਠ_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } ਨਹੀਂਤਾਂ {
                ਚੋਣ (token) {
                    ਹਾਲਤ TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_ਪਾਠ_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        ਰੋਕੋ;
                    ਹਾਲਤ TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_ਪਾਠ_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        ਰੋਕੋ;
                    ਮੂਲ:
                        tcc_error("unsupported branch");
                }
            }
        } ਨਹੀਂਤਾਂ {
            ਵਿੱਥ = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            ਜੇ (cond >= 0) {
                gen_b_cond(cond, ਵਿੱਥ);
            } ਨਹੀਂਤਾਂ {
                ਚੋਣ (token) {
                    ਹਾਲਤ TOK_ASM_b:
                        gen_b(ਵਿੱਥ);
                        ਰੋਕੋ;
                    ਹਾਲਤ TOK_ASM_bl:
                        gen_bl(ਵਿੱਥ);
                        ਰੋਕੋ;
                    ਮੂਲ:
                        tcc_error("unsupported branch");
                }
            }
        }
    } ਨਹੀਂਤਾਂ ਜੇ (op.type & OP_REG) {
        ਚੋਣ (token) {
            ਹਾਲਤ TOK_ASM_br:
                gen_br(op.reg);
                ਰੋਕੋ;
            ਹਾਲਤ TOK_ASM_blr:
                gen_blr(op.reg);
                ਰੋਕੋ;
            ਹਾਲਤ TOK_ASM_ret:
                gen_ret(op.reg);
                ਰੋਕੋ;
            ਮੂਲ:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
ਸਥਿਰ ਖਾਲੀ asm_cb(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ op1, op2;
    ਪੂਰਨ rt, is_64bit;
    int32_t ਵਿੱਥ;
    Sym *sym;

    parse_ਸੰਕਾਰਜ(s1, &op1);
    ਜੇ (tok == ',') ਅਗਲਾ();
    parse_ਵਿਅੰਜਕ_ਸੰਕਾਰਜ(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    ਜੇ (sym) {
        /* Symbolic address - emit relocation */
        ਵਿੱਥ = 0;
        ਜੇ (token == TOK_ASM_cbz) {
            gen_cbz(rt, ਵਿੱਥ, is_64bit);
            greloca(cur_ਪਾਠ_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } ਨਹੀਂਤਾਂ {
            gen_cbnz(rt, ਵਿੱਥ, is_64bit);
            greloca(cur_ਪਾਠ_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } ਨਹੀਂਤਾਂ {
        ਵਿੱਥ = (int32_t)op2.e.v - ind;
        ਜੇ (token == TOK_ASM_cbz)
            gen_cbz(rt, ਵਿੱਥ, is_64bit);
        ਨਹੀਂਤਾਂ
            gen_cbnz(rt, ਵਿੱਥ, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
ਸਥਿਰ ਖਾਲੀ asm_move_wide(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ op1, op2;
    ਪੂਰਨ rd, is_64bit = 1;
    uint16_t imm;
    ਪੂਰਨ ਖਿਸਕਾਓ = 0;

    parse_ਸੰਕਾਰਜ(s1, &op1);
    ਜੇ (tok == ',') ਅਗਲਾ();
    parse_ਸੰਕਾਰਜ(s1, &op2);

    ਜੇ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        ਵਾਪਸ;
    }
    ਜੇ (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        ਵਾਪਸ;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    ਜੇ ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        ਵਾਪਸ;
    }
    imm = op2.e.v;

    ਜੇ (tok == ',') {
        ਅਗਲਾ();
        ਜੇ (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            ਵਾਪਸ;
        }
            ਅਗਲਾ();
            ਜੇ (tok == '#') ਅਗਲਾ();
            asm_ਵਿਅੰਜਕ(s1, &op2.e);
        ਜੇ (op2.e.sym || !is_valid_movw_ਖਿਸਕਾਓ((ਪੂਰਨ)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            ਵਾਪਸ;
        }
            ਖਿਸਕਾਓ = (ਪੂਰਨ)op2.e.v / 16;
        }

    ਚੋਣ (token) {
        ਹਾਲਤ TOK_ASM_movz:
            gen_movz(rd, imm, ਖਿਸਕਾਓ, is_64bit);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_movn:
            gen_movn(rd, imm, ਖਿਸਕਾਓ, is_64bit);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_movk:
            gen_movk(rd, imm, ਖਿਸਕਾਓ, is_64bit);
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC ਖਾਲੀ asm_opcode(TCCState *s1, ਪੂਰਨ opcode)
{
    ਚੋਣ (opcode) {
        ਹਾਲਤ TOK_ASM_ਜੋੜੋ:
        ਹਾਲਤ TOK_ASM_adds:
        ਹਾਲਤ TOK_ASM_sub:
        ਹਾਲਤ TOK_ASM_subs:
        ਹਾਲਤ TOK_ASM_and:
        ਹਾਲਤ TOK_ASM_ands:
        ਹਾਲਤ TOK_ASM_orr:
        ਹਾਲਤ TOK_ASM_eor:
        ਹਾਲਤ TOK_ASM_mul:
            asm_ਅੰਕੜੇ_proc(s1, opcode);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_lsl:
        ਹਾਲਤ TOK_ASM_lsr:
        ਹਾਲਤ TOK_ASM_asr:
        ਹਾਲਤ TOK_ASM_ror:
            asm_ਖਿਸਕਾਓ(s1, opcode);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_ldr:
        ਹਾਲਤ TOK_ASM_ldrb:
        ਹਾਲਤ TOK_ASM_ldrh:
        ਹਾਲਤ TOK_ASM_str:
        ਹਾਲਤ TOK_ASM_strb:
        ਹਾਲਤ TOK_ASM_strh:
            asm_ldst(s1, opcode);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_ldp:
        ਹਾਲਤ TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_b:
        ਹਾਲਤ TOK_ASM_bl:
        ਹਾਲਤ TOK_ASM_br:
        ਹਾਲਤ TOK_ASM_blr:
        ਹਾਲਤ TOK_ASM_ret:
        ਹਾਲਤ TOK_ASM_beq:
        ਹਾਲਤ TOK_ASM_bne:
        ਹਾਲਤ TOK_ASM_bcs:
        ਹਾਲਤ TOK_ASM_bhs:
        ਹਾਲਤ TOK_ASM_bcc:
        ਹਾਲਤ TOK_ASM_blo:
        ਹਾਲਤ TOK_ASM_bmi:
        ਹਾਲਤ TOK_ASM_bpl:
        ਹਾਲਤ TOK_ASM_bvs:
        ਹਾਲਤ TOK_ASM_bvc:
        ਹਾਲਤ TOK_ASM_bhi:
        ਹਾਲਤ TOK_ASM_bls:
        ਹਾਲਤ TOK_ASM_bge:
        ਹਾਲਤ TOK_ASM_blt:
        ਹਾਲਤ TOK_ASM_bgt:
        ਹਾਲਤ TOK_ASM_ble:
            asm_branch(s1, opcode);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_cbz:
        ਹਾਲਤ TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_movz:
        ਹਾਲਤ TOK_ASM_movn:
        ਹਾਲਤ TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_mrs:
        ਹਾਲਤ TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_isb:
        ਹਾਲਤ TOK_ASM_dsb:
        ਹਾਲਤ TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_nop:
            gen_nop();
            ਰੋਕੋ;

        ਮੂਲ:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, ਨਿਰਾ));
            ਰੋਕੋ;
    }
}

/* Substitute assembler operand */
ST_FUNC ਖਾਲੀ subst_asm_ਸੰਕਾਰਜ(CString *ਜੋੜੋ_str, SValue *sv, ਪੂਰਨ modifier)
{
    ਪੂਰਨ r, reg, ਮਾਪ, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    ਜੇ ((r & VT_VALMASK) == VT_CONST) {
        ਜੇ ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(ਜੋੜੋ_str, modifier == 'w' ? "wzr" : "xzr", -1);
            ਵਾਪਸ;
        }
        ਜੇ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(ਜੋੜੋ_str, '#');
        ਜੇ (r & VT_SYM) {
            ਅਚਲ ਅੱਖਰ *name = get_tok_str(sv->sym->v, ਨਿਰਾ);
            ਜੇ (sv->sym->v >= SYM_ਪਹਿਲਾ_ANOM)
                get_asm_sym(tok_alloc(name, ਲੜੀ_ਲੰਬਾਈ(name))->tok, sv->sym);
            ਜੇ (tcc_state->leading_underscore)
                cstr_ccat(ਜੋੜੋ_str, '_');
            cstr_cat(ਜੋੜੋ_str, name, -1);
            ਜੇ ((uint32_t) sv->c.i == 0)
                ਜਾਓ no_ਵਿੱਥ;
            cstr_ccat(ਜੋੜੋ_str, '+');
        }
        uval = sv->c.i;
        ਜੇ (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(ਜੋੜੋ_str, "%lld", (ਲੰਮਾ ਲੰਮਾ)val);
        } ਨਹੀਂਤਾਂ ਜੇ (uval > 0x7fffffffffffffffULL) {
            cstr_printf(ਜੋੜੋ_str, "0x%llx", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)uval);
        } ਨਹੀਂਤਾਂ {
            val = (int64_t)uval;
            cstr_printf(ਜੋੜੋ_str, "%lld", (ਲੰਮਾ ਲੰਮਾ)val);
        }
      no_ਵਿੱਥ:;
    } ਨਹੀਂਤਾਂ ਜੇ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(ਜੋੜੋ_str, "[x29,#%d]", (ਪੂਰਨ) sv->c.i);
    } ਨਹੀਂਤਾਂ ਜੇ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ਜੇ (reg >= VT_CONST)
            tcc_ਅੰਦਰੂਨੀ_error("");
        cstr_printf(ਜੋੜੋ_str, "[x%d]", reg);
    } ਨਹੀਂਤਾਂ {
        /* register case */
        reg = r & VT_VALMASK;
        ਜੇ (reg >= VT_CONST)
            tcc_ਅੰਦਰੂਨੀ_error("");

        ਜੇ (ARM64_FREG_ਅਧਾਰ <= reg && reg <= ARM64_FREG_ਆਖਰੀ) {
            fp_reg = reg - ARM64_FREG_ਅਧਾਰ;
            ਮਾਪ = type_ਮਾਪ(&sv->type, &align);

            ਜੇ (modifier == 0)
                modifier = ਮਾਪ <= 4 ? 's'
                         : ਮਾਪ == 8 ? 'd'
                         : 'q';

            ਚੋਣ (modifier) {
            ਹਾਲਤ 'b':
            ਹਾਲਤ 'h':
            ਹਾਲਤ 's':
            ਹਾਲਤ 'd':
            ਹਾਲਤ 'q':
            ਹਾਲਤ 'Z':
                cstr_printf(ਜੋੜੋ_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                ਵਾਪਸ;
            ਮੂਲ:
                tcc_error("invalid operand modifier for SIMD/FP register");
                ਵਾਪਸ;
            }
        }

        /* choose register operand size */
        ਜੇ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            ਮਾਪ = 1;
        ਨਹੀਂਤਾਂ ਜੇ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            ਮਾਪ = 2;
        ਨਹੀਂਤਾਂ ਜੇ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            ਮਾਪ = 8;
        ਨਹੀਂਤਾਂ
            ਮਾਪ = 4;

        ਜੇ (modifier == 'x') {
            ਮਾਪ = 8;
        } ਨਹੀਂਤਾਂ ਜੇ (modifier == 'w' || modifier == 'k') {
            ਮਾਪ = 4;
        } ਨਹੀਂਤਾਂ ਜੇ (modifier == 'b') {
            ਮਾਪ = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (modifier == 'h') {
            ਮਾਪ = 2;
        } ਨਹੀਂਤਾਂ ਜੇ (modifier == 'q') {
            ਮਾਪ = 8;
        }

        ਜੇ (ਮਾਪ <= 4) {
            cstr_printf(ਜੋੜੋ_str, "w%d", reg);
        } ਨਹੀਂਤਾਂ {
            cstr_printf(ਜੋੜੋ_str, "x%d", reg);
        }
    }
}

ST_FUNC ਖਾਲੀ asm_gen_ਕੋਡ(ASMOperand *operands, ਪੂਰਨ nb_operands,
                          ਪੂਰਨ nb_outputs, ਪੂਰਨ is_output,
                          uint8_t *clobber_regs,
                          ਪੂਰਨ ਬਾਹਰਲਾ_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ਪੂਰਨ i, reg, saved_ਗਿਣਤੀ, ਢੇਰ_ਮਾਪ, ਢੇਰ_off;
    ਪੂਰਨ saved_regs[12];
    ਸਥਿਰ ਅਚਲ uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    ਸਮ੍ਰਿਤੀ_ਨਕਲ(regs_allocated, clobber_regs, ਆਕਾਰ(regs_allocated));
    ਲਈ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ਜੇ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_ਗਿਣਤੀ = 0;
    ਲਈ (i = 0; i < ਆਕਾਰ(reg_saved) / ਆਕਾਰ(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ਜੇ (regs_allocated[reg])
            saved_regs[saved_ਗਿਣਤੀ++] = reg;
    }
    ਢੇਰ_ਮਾਪ = ((saved_ਗਿਣਤੀ + 1) / 2) * 16;

    ਜੇ (!is_output) {
        ਜੇ (saved_ਗਿਣਤੀ > 0) {
            gen_sub_imm(31, 31, ਢੇਰ_ਮਾਪ, 1, 0);

            ਲਈ (i = ਢੇਰ_off = 0; i < saved_ਗਿਣਤੀ; ) {
                ਜੇ (i + 1 < saved_ਗਿਣਤੀ) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ਢੇਰ_off, 3);
                    ਢੇਰ_off += 16;
                    i += 2;
                } ਨਹੀਂਤਾਂ {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 ਢੇਰ_off, 3);
                    i++;
                }
            }
        }

        ਲਈ (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ਜੇ (op->reg >= 0) {
                ਜੇ (op->is_ਸਮ੍ਰਿਤੀ) {
                    arm64_ਲੱਦੋ_ਸਮ੍ਰਿਤੀ_ਸੰਕਾਰਜ_ਅਧਾਰ(op->reg, op->vt);
                } ਨਹੀਂਤਾਂ ਜੇ (i >= nb_outputs || op->is_rw) {
                    ਲੱਦੋ(op->reg, op->vt);
                }
            }
        }
    } ਨਹੀਂਤਾਂ {
        ਲਈ (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            ਜੇ (op->reg >= 0) {
                ਜੇ (op->is_ਸਮ੍ਰਿਤੀ)
                    ਜਾਰੀ;
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
                }
            }
        }

        ਜੇ (saved_ਗਿਣਤੀ > 0) {
            ਲਈ (i = ਢੇਰ_off = 0; i < saved_ਗਿਣਤੀ; ) {
                ਜੇ (i + 1 < saved_ਗਿਣਤੀ) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ਢੇਰ_off, 3);
                    ਢੇਰ_off += 16;
                    i += 2;
                } ਨਹੀਂਤਾਂ {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 ਢੇਰ_off, 3);
                    i++;
                }
            }
            gen_ਜੋੜੋ_imm(31, 31, ਢੇਰ_ਮਾਪ, 1, 0);
        }
    }
}

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

    ਲਈ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ = -1;
        op->ref_ਸੂਚਕਾਂਕ = -1;
        op->reg = -1;
        op->is_ਸਮ੍ਰਿਤੀ = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    ਲਈ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ਜੇ (isnum(*str) || *str == '[') {
            k = ਲੱਭੋ_constraint(operands, nb_operands, str, ਨਿਰਾ);
            ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
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

    ਲਈ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ਲਈ (i = 0; i < nb_operands - 1; i++) {
        ਲਈ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].ਤਰਜੀਹ;
            p2 = operands[sorted_op[j]].ਤਰਜੀਹ;
            ਜੇ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ਲਈ (i = 0; i < NB_ASM_REGS; i++) {
        ਜੇ (clobber_regs[i])
            regs_allocated[i] = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
        ਨਹੀਂਤਾਂ
            regs_allocated[i] = 0;
    }

    ਲਈ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        ਜੇ (op->ref_ਸੂਚਕਾਂਕ >= 0)
            ਜਾਰੀ;
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
            ਜਾਓ reg_ਮਿਲਿਆ;
        }
    try_ਅਗਲਾ:
        c = *str++;
        ਚੋਣ (c) {
        ਹਾਲਤ '=':
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ '+':
            op->is_rw = 1;
        ਹਾਲਤ '&':
            ਜੇ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_ਨਕਾਬ = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ 'r':
            ਲਈ (reg = 0; reg < 31; reg++) {
                ਜੇ (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    ਜਾਓ reg_ਮਿਲਿਆ;
            }
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ 'w':
        ਹਾਲਤ 'f':
            ਲਈ (reg = ARM64_FREG_ਅਧਾਰ; reg <= ARM64_FREG_ਆਖਰੀ; reg++) {
                ਜੇ (!is_reg_allocated(reg))
                    ਜਾਓ reg_ਮਿਲਿਆ;
            }
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ 'x':
        ਹਾਲਤ 'y':
            ਲਈ (reg = ARM64_FREG_ਅਧਾਰ; reg <= ARM64_FREG_ਆਖਰੀ; reg++) {
                ਜੇ (!is_reg_allocated(reg))
                    ਜਾਓ reg_ਮਿਲਿਆ;
            }
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ 'm':
        ਹਾਲਤ 'g':
            ਜੇ (j < nb_outputs || c == 'm') {
                ਜੇ (!arm64_prepare_ਸਮ੍ਰਿਤੀ_ਸੰਕਾਰਜ(op, regs_allocated))
                    ਜਾਓ try_ਅਗਲਾ;
            }
            ਰੋਕੋ;
        ਹਾਲਤ 'Q':
            ਜੇ (!arm64_ਸਮ੍ਰਿਤੀ_is_ਅਧਾਰ_only(op->vt))
                ਜਾਓ try_ਅਗਲਾ;
            ਜੇ (!arm64_prepare_ਸਮ੍ਰਿਤੀ_ਸੰਕਾਰਜ(op, regs_allocated))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'S':
            ਜੇ ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'U':
            ਜੇ (str[0] != 'm' || str[1] != 'p')
                ਜਾਓ try_ਅਗਲਾ;
            str += 2;
            ਜੇ (!arm64_ਸਮ੍ਰਿਤੀ_is_pair_suitable(op->vt))
                ਜਾਓ try_ਅਗਲਾ;
            ਜੇ (!arm64_prepare_ਸਮ੍ਰਿਤੀ_ਸੰਕਾਰਜ(op, regs_allocated))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'i':
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'I':
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਜੇ (!is_valid_ਜੋੜੋ_imm(op->vt->c.i))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'J':
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਜੇ (!is_valid_ਜੋੜੋ_imm(-op->vt->c.i))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'K':
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਜੇ (!is_valid_logical_imm(op->vt->c.i, 32))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'L':
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਜੇ (!is_valid_logical_imm(op->vt->c.i, 64))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'M':
        ਹਾਲਤ 'N':
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਜੇ (!is_valid_movw_imm(op->vt->c.i))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'Z':
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਜੇ (op->vt->c.i != 0)
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'n':
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            ਰੋਕੋ;
        }
        ਜੇ (op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0) {
            operands[op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ].reg = op->reg;
            operands[op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ].is_llong = op->is_llong;
        }
        ਜਾਰੀ;
    reg_ਮਿਲਿਆ:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_ਨਕਾਬ;
        ਜੇ (op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0) {
            operands[op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ].reg = op->reg;
            operands[op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    ਲਈ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ਜੇ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_ਸਮ੍ਰਿਤੀ) {
            ਲਈ (reg = 0; reg < 31; reg++) {
                ਜੇ (!(regs_allocated[reg] & REG_ਬਾਹਰਲਾ_ਨਕਾਬ))
                    ਜਾਓ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            ਰੋਕੋ;
        }
    }
}

/* Handle clobber list */
ST_FUNC ਖਾਲੀ asm_clobber(uint8_t *clobber_regs, ਅਚਲ ਅੱਖਰ *str)
{
    ਪੂਰਨ reg;

    ਜੇ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ਵਾਪਸ;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    ਜੇ (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC ਪੂਰਨ asm_parse_regvar(ਪੂਰਨ t)
{
    ਵਾਪਸ arm64_parse_regvar(t);
}

/*************************************************************/
#ਜੇ_ਅੰਤ /* ndef TARGET_DEFS_ONLY */
