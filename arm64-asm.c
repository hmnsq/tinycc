/*************************************************************/
/*
 *  ARM64 (AArch64) assembler for TCC
 *
 *  Based on ARM64 Architecture Reference Manual
 *  Supports AArch64 assembler parsing and extended inline asm
 *  with operands, constraints, and clobbers.
 */

#اگر_تعریف_شدہ ہدف_DEFS_ONLY

#تعریف_کرو CONFIG_TCC_ASM
/* 32 general purpose + 32 SIMD/FP registers */
#تعریف_کرو NB_ASM_REGS 64

ST_FUNC خالی g(صحیح c);
ST_FUNC خالی gen_le16(صحیح c);
ST_FUNC خالی gen_le32(صحیح c);

/*************************************************************/
#ورنہ
/*************************************************************/

#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"

/* Register type flags */
#تعریف_کرو REG_X     0x01  /* 64-bit general purpose */
#تعریف_کرو REG_W     0x02  /* 32-bit general purpose */
#تعریف_کرو REG_V     0x04  /* 128-bit SIMD */
#تعریف_کرو REG_D     0x08  /* 64-bit FP */
#تعریف_کرو REG_S     0x10  /* 32-bit FP */
#تعریف_کرو REG_H     0x20  /* 16-bit FP */
#تعریف_کرو REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
شمار {
    OPT_REG,
    OPT_IM,
    OPT_ADDR,
    OPT_COND,
};

#تعریف_کرو OP_REG     (1 << OPT_REG)
#تعریف_کرو OP_IM      (1 << OPT_IM)
#تعریف_کرو OP_ADDR    (1 << OPT_ADDR)
#تعریف_کرو OP_COND    (1 << OPT_COND)

/* Register allocation masks */
#تعریف_کرو REG_برآمد_نقاب 0x01
#تعریف_کرو REG_اندر_نقاب  0x02

#تعریف_کرو is_reg_allocated(reg) (regs_allocated[reg] & reg_نقاب)

/* ARM64 register constants */
#تعریف_کرو TREG_X0  0
#تعریف_کرو TREG_X1  1
#تعریف_کرو TREG_X2  2
#تعریف_کرو TREG_X3  3
#تعریف_کرو TREG_X4  4
#تعریف_کرو TREG_X5  5
#تعریف_کرو TREG_X6  6
#تعریف_کرو TREG_X7  7
#تعریف_کرو TREG_X8  8
#تعریف_کرو TREG_X9  9
#تعریف_کرو TREG_X10 10
#تعریف_کرو TREG_X11 11
#تعریف_کرو TREG_X12 12
#تعریف_کرو TREG_X13 13
#تعریف_کرو TREG_X14 14
#تعریف_کرو TREG_X15 15
#تعریف_کرو TREG_X16 16
#تعریف_کرو TREG_X17 17
#تعریف_کرو TREG_X18 18
#تعریف_کرو TREG_X19 19
#تعریف_کرو TREG_X20 20
#تعریف_کرو TREG_X21 21
#تعریف_کرو TREG_X22 22
#تعریف_کرو TREG_X23 23
#تعریف_کرو TREG_X24 24
#تعریف_کرو TREG_X25 25
#تعریف_کرو TREG_X26 26
#تعریف_کرو TREG_X27 27
#تعریف_کرو TREG_X28 28
#تعریف_کرو TREG_X29 29
#تعریف_کرو TREG_X30 30
#تعریف_کرو TREG_SP  31

#تعریف_کرو ARM64_FREG_بنیاد 20
#تعریف_کرو ARM64_FREG_آخری (ARM64_FREG_بنیاد + 7)

قسمتعریف ساخت عملیہ {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t سرکاؤ;
    uint8_t addr_منوال;
    صحیح reg_tok;
    اظہاریہ_قدر e;
} عملیہ;

شمار {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
ساکن خالی parse_addr_عملیہ(TCCState *s1, عملیہ *op);

/* XXX: make it faster ? */
ST_FUNC خالی g(صحیح c)
{
    صحیح ind1;
    اگر (nocode_wanted)
        واپس;
    ind1 = ind + 1;
    اگر (ind1 > cur_متن_section->ڈیٹا_allocated)
        section_realloc(cur_متن_section, ind1);
    cur_متن_section->ڈیٹا[ind] = c;
    ind = ind1;
}

ST_FUNC خالی gen_le16(صحیح c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC خالی gen_le32(صحیح c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC خالی gen_expr32(اظہاریہ_قدر *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
ساکن خالی emit_instr32(uint32_t val)
{
    اگر (nocode_wanted)
        واپس;
    اگر (ind + 4 > cur_متن_section->ڈیٹا_allocated)
        section_realloc(cur_متن_section, ind + 4);
    write32le(cur_متن_section->ڈیٹا + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
ساکن صحیح arm64_parse_asm_reg(صحیح t)
{
    /* X registers (64-bit) */
    اگر (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        واپس t - TOK_ASM_x0;
    /* W registers (32-bit) */
    اگر (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        واپس t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    اگر (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        واپس (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    اگر (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        واپس (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    اگر (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        واپس (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    اگر (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        واپس (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    اگر (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        واپس (t - TOK_ASM_b0) + 32;
    /* Special registers */
    اگر (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        واپس 31;  /* SP/ZR encoded as 31 */
    واپس -1;
}

/* Get register type from token */
ساکن uint8_t get_reg_type(صحیح t)
{
    اگر (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        واپس REG_X;
    اگر (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        واپس REG_W;
    اگر (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        واپس REG_V;
    اگر (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        واپس REG_D;
    اگر (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        واپس REG_S;
    اگر (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        واپس REG_H;
    اگر (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        واپس REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    اگر (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        واپس REG_X;
    اگر (t == TOK_ASM_wzr)
        واپس REG_W;
    واپس REG_X;
}

/* Parse condition code */
ساکن صحیح parse_condition(صحیح t)
{
    انتخاب (t) {
        حالت TOK_ASM_eq: واپس 0;
        حالت TOK_ASM_ne: واپس 1;
        حالت TOK_ASM_cs:
        حالت TOK_ASM_hs: واپس 2;
        حالت TOK_ASM_cc:
        حالت TOK_ASM_lo: واپس 3;
        حالت TOK_ASM_mi: واپس 4;
        حالت TOK_ASM_pl: واپس 5;
        حالت TOK_ASM_vs: واپس 6;
        حالت TOK_ASM_vc: واپس 7;
        حالت TOK_ASM_hi: واپس 8;
        حالت TOK_ASM_ls: واپس 9;
        حالت TOK_ASM_ge: واپس 10;
        حالت TOK_ASM_lt: واپس 11;
        حالت TOK_ASM_gt: واپس 12;
        حالت TOK_ASM_le: واپس 13;
        حالت TOK_ASM_al: واپس 14;
        طےشدہ: واپس -1;
    }
}

ساکن صحیح parse_barrier_option_name(صحیح t)
{
    ثابت حرف *name;

    اگر (t < TOK_IDENT)
        واپس -1;
    name = get_tok_str(t, تہی);
    اگر (!strcmp(name, "oshld")) واپس 0x1;
    اگر (!strcmp(name, "oshst")) واپس 0x2;
    اگر (!strcmp(name, "osh"))   واپس 0x3;
    اگر (!strcmp(name, "nshld")) واپس 0x5;
    اگر (!strcmp(name, "nshst")) واپس 0x6;
    اگر (!strcmp(name, "nsh"))   واپس 0x7;
    اگر (!strcmp(name, "ishld")) واپس 0x9;
    اگر (!strcmp(name, "ishst")) واپس 0xA;
    اگر (!strcmp(name, "ish"))   واپس 0xB;
    اگر (!strcmp(name, "ld"))    واپس 0xD;
    اگر (!strcmp(name, "st"))    واپس 0xE;
    اگر (!strcmp(name, "sy"))    واپس 0xF;
    واپس -1;
}

ساکن صحیح arm64_parse_regvar(صحیح t)
{
    اگر (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        واپس t - TOK_ASM_x0;
    اگر (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        واپس ARM64_FREG_بنیاد + (t - TOK_ASM_v0);
    اگر (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        واپس ARM64_FREG_بنیاد + (t - TOK_ASM_d0);
    اگر (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        واپس ARM64_FREG_بنیاد + (t - TOK_ASM_s0);
    اگر (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        واپس ARM64_FREG_بنیاد + (t - TOK_ASM_h0);
    اگر (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        واپس ARM64_FREG_بنیاد + (t - TOK_ASM_b0);
    واپس -1;
}

/* Parse a single operand */
ساکن خالی parse_عملیہ(TCCState *s1, عملیہ *op)
{
    صحیح reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->سرکاؤ = 0;
    op->addr_منوال = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    اگر (tok == '[') {
        parse_addr_عملیہ(s1, op);
        واپس;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    اگر (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        اگلا();
        واپس;
    }

    /* Condition code */
    reg = parse_condition(tok);
    اگر (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        اگلا();
        واپس;
    }

    /* Immediate or address expression */
    اگر (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        اگلا();
        asm_اظہاریہ(s1, &op->e);
        op->type = OP_IM;
    } ورنہ اگر (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } ورنہ {
        asm_اظہاریہ(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
ساکن خالی parse_اظہاریہ_عملیہ(TCCState *s1, عملیہ *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->سرکاؤ = 0;
    op->addr_منوال = ADDR_OFF;
    op->reg_tok = 0;

    اگر (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        اگلا();
    asm_اظہاریہ(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
ساکن خالی parse_addr_عملیہ(TCCState *s1, عملیہ *op)
{
    صحیح reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = تہی;
    op->addr_منوال = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    اگر (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        واپس;
    }
    op->reg = reg;
    op->reg_tok = tok;
    اگلا();
    /* Check for offset */
    اگر (tok == ',') {
        اگلا();
        اگر (tok == '#' || tok == '@' || tok == '$')
            اگلا();
        asm_اظہاریہ(s1, &op->e);
    }
    skip(']');
    اگر (tok == '!') {
        op->addr_منوال = ADDR_PRE;
        اگلا();
    } ورنہ اگر (tok == ',') {
        op->addr_منوال = ADDR_POST;
        اگلا();
        اگر (tok == '#' || tok == '@' || tok == '$')
            اگلا();
        asm_اظہاریہ(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
ساکن خالی gen_mov_with_بنیاد(صحیح rd, uint16_t imm, صحیح سرکاؤ,
                              صحیح is_64bit, uint32_t بنیاد_opcode)
{
    uint32_t instr = بنیاد_opcode;
    اگر (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, سرکاؤ);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ساکن خالی gen_movz(صحیح rd, uint16_t imm, صحیح سرکاؤ, صحیح is_64bit)
{
    gen_mov_with_بنیاد(rd, imm, سرکاؤ, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
ساکن خالی gen_movn(صحیح rd, uint16_t imm, صحیح سرکاؤ, صحیح is_64bit)
{
    gen_mov_with_بنیاد(rd, imm, سرکاؤ, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
ساکن خالی gen_movk(صحیح rd, uint16_t imm, صحیح سرکاؤ, صحیح is_64bit)
{
    gen_mov_with_بنیاد(rd, imm, سرکاؤ, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
ساکن خالی gen_جوڑو_imm(صحیح rd, صحیح rn, uint32_t imm, صحیح is_64bit, صحیح setflags)
{
    uint32_t instr = ARM64_جوڑو_IMM;
    uint32_t imm12;

    اگر (is_64bit) instr |= ARM64_SF(1);
    اگر (setflags) instr |= ARM64_S(1);

    اگر (imm <= 0xFFF) {
        imm12 = imm;
    } ورنہ اگر (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } ورنہ {
        tcc_error("add immediate out of range");
        واپس;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
ساکن خالی gen_sub_imm(صحیح rd, صحیح rn, uint32_t imm, صحیح is_64bit, صحیح setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    اگر (is_64bit) instr |= ARM64_SF(1);
    اگر (setflags) instr |= ARM64_S(1);

    اگر (imm <= 0xFFF) {
        imm12 = imm;
    } ورنہ اگر (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } ورنہ {
        tcc_error("sub immediate out of range");
        واپس;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
ساکن خالی gen_dp_reg(uint32_t opcode, صحیح rd, صحیح rn, صحیح rm, صحیح is_64bit)
{
    uint32_t instr = opcode;
    اگر (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
ساکن خالی gen_ldst_imm(uint32_t بنیاد_opcode, صحیح rt, صحیح rn,
                         int32_t انحراف, صحیح سائز_log2)
{
    uint32_t instr = بنیاد_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    اگر (انحراف >= 0 && !(انحراف & ((1 << سائز_log2) - 1))) {
    imm12 = انحراف >> سائز_log2;
        اگر (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            واپس;
        }
    }

    انتخاب (بنیاد_opcode) {
    حالت ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; توڑو;
    حالت ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; توڑو;
    حالت ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; توڑو;
    حالت ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; توڑو;
    حالت ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; توڑو;
    حالت ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; توڑو;
    حالت ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; توڑو;
    حالت ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; توڑو;
    حالت ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; توڑو;
    حالت ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; توڑو;
    }

    اگر (unscaled_opcode && انحراف >= -256 && انحراف <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)انحراف & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        واپس;
    }

    اگر (انحراف & ((1 << سائز_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
ساکن خالی gen_ldst_pair(uint32_t بنیاد_opcode, صحیح rt, صحیح rt2, صحیح rn,
                          int32_t انحراف, صحیح سائز_log2)
{
    int32_t imm7;
    uint32_t instr = بنیاد_opcode;

    اگر (انحراف & ((1 << سائز_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = انحراف >> سائز_log2;
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
ساکن خالی gen_b_or_bl(int32_t انحراف, uint32_t بنیاد_opcode)
{
    uint32_t instr = بنیاد_opcode;
    instr |= ARM64_OFFSET26(انحراف);
    emit_instr32(instr);
}

ساکن خالی gen_b(int32_t انحراف)
{
    gen_b_or_bl(انحراف, ARM64_B);
}

/* Generate BL (branch with link) */
ساکن خالی gen_bl(int32_t انحراف)
{
    gen_b_or_bl(انحراف, ARM64_BL);
}

/* Generate BR (branch to register) */
ساکن خالی gen_br(صحیح rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
ساکن خالی gen_blr(صحیح rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
ساکن خالی gen_ret(صحیح rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
ساکن خالی gen_b_cond(صحیح cond, int32_t انحراف)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(انحراف);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
ساکن خالی gen_cbz_or_cbnz(صحیح rt, int32_t انحراف, صحیح is_64bit, uint32_t بنیاد_opcode)
{
    uint32_t instr = بنیاد_opcode;
    اگر (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(انحراف);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

ساکن خالی gen_cbz(صحیح rt, int32_t انحراف, صحیح is_64bit)
{
    gen_cbz_or_cbnz(rt, انحراف, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
ساکن خالی gen_cbnz(صحیح rt, int32_t انحراف, صحیح is_64bit)
{
    gen_cbz_or_cbnz(rt, انحراف, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
ساکن خالی gen_mov_reg(صحیح rd, صحیح rm, صحیح is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    اگر (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

ساکن صحیح arm64_asm_encode_bimm64(uint64_t x)
{
    صحیح neg, rep, pos, len;

    neg = x & 1;
    اگر (neg)
        x = ~x;
    اگر (!x)
        واپس -1;

    اگر (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    ورنہ اگر (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    ورنہ اگر (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    ورنہ اگر (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    ورنہ اگر (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    ورنہ
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
        واپس -1;
    اگر (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    واپس ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ساکن خالی gen_logical_imm(uint32_t opcode, صحیح rd, صحیح rn,
                            uint64_t imm, صحیح is_64bit)
{
    uint32_t instr;
    uint64_t val;
    صحیح enc;

    اگر (is_64bit)
        val = imm;
    ورنہ {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    اگر (enc < 0) {
        tcc_error("logical immediate out of range");
        واپس;
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
ساکن اندرونی صحیح constraint_ترجیح(ثابت حرف *str)
{
    صحیح ترجیح, c, pr;

    ترجیح = 0;
    برائے (;;) {
        c = *str++;
        اگر (c == '\0')
            توڑو;
        انتخاب (c) {
        حالت '=':
        حالت '+':
        حالت '&':
            جاری;
        حالت 'r':
            pr = 1;
            توڑو;
        حالت 'w':
        حالت 'f':
        حالت 'x':
        حالت 'y':
            pr = 3;
            توڑو;
        حالت 'm':
        حالت 'Q':
            pr = 4;
            توڑو;
        حالت 'i':
        حالت 'S':
            pr = 5;
            توڑو;
        حالت 'U':
            اگر (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                توڑو;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            توڑو;
        حالت 'I':
        حالت 'J':
        حالت 'K':
        حالت 'L':
        حالت 'M':
        حالت 'N':
        حالت 'Z':
            pr = 6;
            توڑو;
        حالت 'n':
            pr = 7;
            توڑو;
        حالت 'g':
            pr = 8;
            توڑو;
        طےشدہ:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            توڑو;
        }
        اگر (pr > ترجیح)
            ترجیح = pr;
    }
    واپس ترجیح;
}

ساکن ثابت حرف *skip_constraint_modifiers(ثابت حرف *p)
{
    جب (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    واپس p;
}

ساکن صحیح is_valid_جوڑو_imm(int64_t val)
{
    واپس val >= 0 && val <= 4095;
}

ساکن صحیح is_valid_logical_imm(int64_t val, صحیح بٹ)
{
    uint64_t uval;

    uval = (uint64_t)val;
    اگر (بٹ == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    واپس arm64_asm_encode_bimm64(uval) >= 0;
}

ساکن صحیح is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    اگر (uval <= 0xFFFF)
        واپس 1;
    اگر (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        واپس 1;
    اگر (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        واپس 1;
    اگر ((uval & 0xFFFFFFFF00000000ULL) == 0)
        واپس 1;

    واپس 0;
}

ساکن صحیح is_valid_movw_سرکاؤ(صحیح سرکاؤ, صحیح is_64bit)
{
    اگر (سرکاؤ < 0 || (سرکاؤ & 15))
        واپس 0;
    اگر (سرکاؤ > (is_64bit ? 48 : 16))
        واپس 0;
    واپس 1;
}

ساکن صحیح arm64_حافظہ_is_بنیاد_only(ثابت SValue *sv)
{
    صحیح r;

    r = sv->r;
    اگر ((r & VT_VALMASK) == VT_CONST)
        واپس 0;
    اگر ((r & VT_VALMASK) == VT_LOCAL)
        واپس 0;
    اگر ((r & VT_VALMASK) == VT_LLOCAL)
        واپس 1;
    اگر (r & VT_LVAL)
        واپس (r & VT_VALMASK) < VT_CONST;
    واپس 0;
}

ساکن صحیح arm64_حافظہ_is_pair_suitable(ثابت SValue *sv)
{
    int64_t انحراف;

    اگر (arm64_حافظہ_is_بنیاد_only(sv))
        واپس 1;
    اگر ((sv->r & VT_VALMASK) != VT_LOCAL)
        واپس 0;

    انحراف = (int64_t)sv->c.i;
    واپس (انحراف & 7) == 0 && انحراف >= -512 && انحراف <= 504;
}

ساکن صحیح arm64_int_reg_is_allocatable(صحیح reg)
{
#اگر_تعریف_شدہ TCC_ہدف_PE
    واپس reg >= TREG_X0 && reg <= TREG_X17;
#ورنہ
    واپس reg >= TREG_X0 && reg <= TREG_X30;
#اگر_ختم
}

ساکن صحیح arm64_حافظہ_needs_پتہ_reg(ثابت SValue *sv)
{
    صحیح r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    اگر (!(r & VT_LVAL))
        واپس 0;
    انتخاب (r & VT_VALMASK) {
    حالت VT_LOCAL:
    حالت VT_LLOCAL:
    حالت VT_CONST:
        واپس 1;
    }
    واپس 0;
}

ساکن صحیح arm64_prepare_حافظہ_عملیہ(ASMOperand *op, uint8_t *regs_allocated)
{
    صحیح reg;

    اگر (!arm64_حافظہ_needs_پتہ_reg(op->vt))
        واپس 1;

    برائے (reg = 0; reg < 31; reg++) {
        اگر (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_اندر_نقاب)) {
            regs_allocated[reg] |= REG_اندر_نقاب;
            op->reg = reg;
            op->is_حافظہ = 1;
            واپس 1;
        }
    }
    واپس 0;
}

ساکن خالی arm64_بھرو_حافظہ_عملیہ_بنیاد(صحیح reg, SValue *sv)
{
    SValue بنیاد;
    صحیح rval;

    بنیاد = *sv;
    بنیاد.type.t = VT_PTR;
    rval = بنیاد.r & VT_VALMASK;
    اگر (rval == VT_LLOCAL) {
        بنیاد.r = (بنیاد.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } ورنہ اگر (rval == VT_CONST || rval == VT_LOCAL) {
        بنیاد.r &= ~VT_LVAL;
    } ورنہ {
        tcc_اندرونی_error("unsupported ARM64 memory operand base");
    }
    بھرو(reg, &بنیاد);
}

ساکن صحیح عملیہ_is_sp(ثابت عملیہ *op)
{
    واپس op->reg_tok == TOK_ASM_sp;
}

ساکن صحیح parse_sysreg_name(صحیح t)
{
    ثابت حرف *name;

    اگر (t < TOK_IDENT)
        واپس -1;
    name = get_tok_str(t, تہی);
    اگر (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        واپس 0;
    اگر (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        واپس 1;
    واپس -1;
}

ساکن خالی gen_mrs(صحیح rt, صحیح sysreg)
{
    uint32_t instr;

    انتخاب (sysreg) {
        حالت 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            توڑو;
        حالت 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            توڑو;
        طےشدہ:
            tcc_error("unsupported system register");
            واپس;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

ساکن خالی gen_msr(صحیح rt, صحیح sysreg)
{
    uint32_t instr;

    انتخاب (sysreg) {
        حالت 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            توڑو;
        حالت 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            توڑو;
        طےشدہ:
            tcc_error("unsupported system register");
            واپس;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
ساکن خالی gen_nop(خالی)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
ساکن خالی gen_سرکاؤ(صحیح rd, صحیح rn, صحیح rm_or_imm, صحیح سرکاؤ_type, صحیح is_imm, صحیح is_64bit)
{
    uint32_t instr;
    صحیح چوڑائی = is_64bit ? 64 : 32;

    اگر (is_imm) {
        /* Shift by immediate */
        انتخاب (سرکاؤ_type) {
            حالت 0: /* LSL - UBFM alias */
                اگر (rm_or_imm < 0 || rm_or_imm >= چوڑائی) {
                    tcc_error("shift immediate out of range");
                    واپس;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((چوڑائی - rm_or_imm) & (چوڑائی - 1));
                instr |= ARM64_IMM_S(چوڑائی - rm_or_imm - 1);
                توڑو;
            حالت 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                اگر (rm_or_imm < 0 || rm_or_imm >= چوڑائی) {
                    tcc_error("shift immediate out of range");
                    واپس;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(چوڑائی - 1);
                توڑو;
            حالت 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                اگر (rm_or_imm < 0 || rm_or_imm >= چوڑائی) {
                    tcc_error("shift immediate out of range");
                    واپس;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(چوڑائی - 1);
                توڑو;
            حالت 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                اگر (rm_or_imm < 0 || rm_or_imm >= چوڑائی) {
                    tcc_error("shift immediate out of range");
                    واپس;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                واپس;
            طےشدہ:
                tcc_error("unknown shift type");
                واپس;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } ورنہ {
        /* Shift by register */
        انتخاب (سرکاؤ_type) {
            حالت 0: /* LSL */
                instr = ARM64_LSL_REG;
                توڑو;
            حالت 1: /* LSR */
                instr = ARM64_LSR_REG;
                توڑو;
            حالت 2: /* ASR */
                instr = ARM64_ASR_REG;
                توڑو;
            حالت 3: /* ROR */
                instr = ARM64_ROR_REG;
                توڑو;
            طےشدہ:
                tcc_error("unknown shift type");
                واپس;
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
ساکن خالی asm_سرکاؤ(TCCState *s1, صحیح token)
{
    عملیہ op1, op2, op3;
    صحیح rd, rn, سرکاؤ_amount;
    صحیح سرکاؤ_type;
    صحیح is_64bit = 1;

    انتخاب (token) {
        حالت TOK_ASM_lsl:
            سرکاؤ_type = 0;
            توڑو;
        حالت TOK_ASM_lsr:
            سرکاؤ_type = 1;
            توڑو;
        حالت TOK_ASM_asr:
            سرکاؤ_type = 2;
            توڑو;
        حالت TOK_ASM_ror:
            سرکاؤ_type = 3;
            توڑو;
        طےشدہ:
            tcc_error("unknown shift instruction");
            واپس;
    }

    parse_عملیہ(s1, &op1);
    اگر (tok == ',') اگلا();
    parse_عملیہ(s1, &op2);

    اگر (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        واپس;
    }
    اگر (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        واپس;
    }

    rd = op1.reg;
    rn = op2.reg;

    اگر (tok == ',') {
        اگلا();
        parse_عملیہ(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        اگر (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            واپس;
        }
        اگر (op3.type & OP_REG) {
            اگر (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                واپس;
            }
            gen_سرکاؤ(rd, rn, op3.reg, سرکاؤ_type, 0, is_64bit);
        } ورنہ اگر (op3.type & OP_IM) {
            سرکاؤ_amount = op3.e.v;
            gen_سرکاؤ(rd, rn, سرکاؤ_amount, سرکاؤ_type, 1, is_64bit);
        } ورنہ {
            tcc_error("shift requires immediate or register operand");
        }
    } ورنہ {
        tcc_error("shift requires immediate or register operand");
        واپس;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
ساکن خالی gen_barrier(صحیح barrier_type, صحیح option)
{
    uint32_t instr;

    انتخاب (barrier_type) {
        حالت 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            توڑو;
        حالت 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            توڑو;
        حالت 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            توڑو;
        طےشدہ:
            tcc_error("unknown barrier type");
            واپس;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
ساکن خالی asm_barrier(TCCState *s1, صحیح token)
{
    صحیح barrier_type, option;
    عملیہ op;

    انتخاب (token) {
        حالت TOK_ASM_isb:
            barrier_type = 0;
            توڑو;
        حالت TOK_ASM_dsb:
            barrier_type = 1;
            توڑو;
        حالت TOK_ASM_dmb:
            barrier_type = 2;
            توڑو;
        طےشدہ:
            tcc_error("unknown barrier instruction");
            واپس;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    اگر (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        اگر (option >= 0) {
            اگلا();
        } ورنہ {
            parse_عملیہ(s1, &op);
            اگر (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                واپس;
            }
            اگر (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                واپس;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
ساکن خالی gen_mov_imm(صحیح rd, uint64_t imm, صحیح is_64bit)
{
    uint16_t hw;
    صحیح i, پہلا = 1;

    برائے (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        اگر (hw != 0 || i == 0) {
            اگر (پہلا) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                پہلا = 0;
            } ورنہ {
                gen_movk(rd, hw, i, is_64bit);
            }
        } ورنہ اگر (!پہلا) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
ساکن خالی asm_mov(TCCState *s1)
{
    عملیہ op1, op2;
    صحیح rd, rn;
    صحیح is_64bit;

    parse_عملیہ(s1, &op1);
    اگر (tok == ',') اگلا();
    parse_عملیہ(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    اگر (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        اگر (عملیہ_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            واپس;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } ورنہ اگر (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        اگر (عملیہ_is_sp(&op1) || عملیہ_is_sp(&op2))
            gen_جوڑو_imm(rd, rn, 0, 1, 0);
        ورنہ
            gen_mov_reg(rd, rn, is_64bit);
    } ورنہ {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
ساکن خالی asm_ڈیٹا_proc(TCCState *s1, صحیح token)
{
    عملیہ op1, op2, op3;
    صحیح rd, rn, rm;
    صحیح is_64bit = 1;
    uint32_t opcode;

    انتخاب (token) {
        حالت TOK_ASM_جوڑو:
        حالت TOK_ASM_adds:
            opcode = token == TOK_ASM_جوڑو ? ARM64_جوڑو_REG : ARM64_ADDS_REG;
            توڑو;
        حالت TOK_ASM_sub:
        حالت TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            توڑو;
        حالت TOK_ASM_and:
        حالت TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            توڑو;
        حالت TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            توڑو;
        حالت TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            توڑو;
        حالت TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            توڑو;
        طےشدہ:
            tcc_error("unsupported data processing instruction");
            واپس;
    }

    parse_عملیہ(s1, &op1);
    اگر (tok == ',') اگلا();
    parse_عملیہ(s1, &op2);

    اگر (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        واپس;
    }
    اگر (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        واپس;
    }

    rd = op1.reg;
    rn = op2.reg;

    اگر (tok == ',') {
        اگلا();
        parse_عملیہ(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        اگر (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            واپس;
        }
        اگر (op3.type & OP_IM) {
            اگر (token == TOK_ASM_جوڑو || token == TOK_ASM_adds)
                gen_جوڑو_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            ورنہ اگر (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            ورنہ اگر (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            ورنہ اگر (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            ورنہ اگر (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_بنیاد, rd, rn, op3.e.v, is_64bit);
            ورنہ اگر (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            ورنہ
                tcc_error("immediate operand not valid for this instruction");
        } ورنہ {
            اگر (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                واپس;
            }
            rm = op3.reg;
            اگر (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                واپس;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } ورنہ اگر (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } ورنہ {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
ساکن خالی asm_ldst(TCCState *s1, صحیح token)
{
    عملیہ op1, op2;
    صحیح rt, rn;
    int32_t انحراف = 0;
    صحیح سائز_log2 = 3;
    uint32_t بنیاد_opcode;

    parse_عملیہ(s1, &op1);
    اگر (tok == ',') اگلا();
    parse_عملیہ(s1, &op2);

    اگر (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        واپس;
    }
    اگر (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        واپس;
    }

    rt = op1.reg;
    rn = op2.reg;
    انحراف = op2.e.v;

    انتخاب (token) {
        حالت TOK_ASM_ldr:
            اگر (op1.reg_type & REG_X) {
                بنیاد_opcode = ARM64_LDR_X;
                سائز_log2 = 3;
            } ورنہ اگر (op1.reg_type & REG_W) {
                بنیاد_opcode = ARM64_LDR_W;
                سائز_log2 = 2;
            } ورنہ اگر (op1.reg_type & REG_D) {
                بنیاد_opcode = ARM64_LDR_D;
                سائز_log2 = 3;
            } ورنہ {
                tcc_error("ldr requires a w, x, or d register");
                واپس;
            }
            توڑو;
        حالت TOK_ASM_ldrb:
            بنیاد_opcode = ARM64_LDR_B;
            سائز_log2 = 0;
            توڑو;
        حالت TOK_ASM_ldrh:
            بنیاد_opcode = ARM64_LDR_H;
            سائز_log2 = 1;
            توڑو;
        حالت TOK_ASM_str:
            اگر (op1.reg_type & REG_X) {
                بنیاد_opcode = ARM64_STR_X;
                سائز_log2 = 3;
            } ورنہ اگر (op1.reg_type & REG_W) {
                بنیاد_opcode = ARM64_STR_W;
                سائز_log2 = 2;
            } ورنہ اگر (op1.reg_type & REG_D) {
                بنیاد_opcode = ARM64_STR_D;
                سائز_log2 = 3;
            } ورنہ {
                tcc_error("str requires a w, x, or d register");
                واپس;
            }
            توڑو;
        حالت TOK_ASM_strb:
            بنیاد_opcode = ARM64_STR_B;
            سائز_log2 = 0;
            توڑو;
        حالت TOK_ASM_strh:
            بنیاد_opcode = ARM64_STR_H;
            سائز_log2 = 1;
            توڑو;
        طےشدہ:
            tcc_error("unsupported load/store instruction");
            واپس;
    }

    اگر (op2.addr_منوال != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(بنیاد_opcode, rt, rn, انحراف, سائز_log2);
}

ساکن خالی asm_ldst_pair(TCCState *s1, صحیح token)
{
    عملیہ op1, op2, op3;
    uint32_t بنیاد_opcode;
    صحیح سائز_log2 = 3;

    parse_عملیہ(s1, &op1);
    اگر (tok == ',')
        اگلا();
    parse_عملیہ(s1, &op2);
    اگر (tok == ',')
        اگلا();
    parse_عملیہ(s1, &op3);

    اگر (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        واپس;
    }
    اگر (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        واپس;
    }
    اگر (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    اگر ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        اگر (token == TOK_ASM_stp) {
            بنیاد_opcode = op3.addr_منوال == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_منوال == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } ورنہ {
            بنیاد_opcode = op3.addr_منوال == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_منوال == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } ورنہ اگر ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        اگر (token == TOK_ASM_stp) {
            بنیاد_opcode = op3.addr_منوال == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_منوال == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } ورنہ {
            بنیاد_opcode = op3.addr_منوال == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_منوال == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } ورنہ {
        tcc_error("stp/ldp requires matching x or d registers");
        واپس;
    }

    gen_ldst_pair(بنیاد_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, سائز_log2);
}

ساکن خالی asm_sysreg(TCCState *s1, صحیح token)
{
    عملیہ op;
    صحیح sysreg;

    اگر (token == TOK_ASM_mrs) {
        parse_عملیہ(s1, &op);
        اگر (tok == ',')
            اگلا();
        sysreg = parse_sysreg_name(tok);
        اگر (sysreg < 0)
            tcc_error("unsupported system register");
        اگلا();
        gen_mrs(op.reg, sysreg);
        واپس;
    }

    sysreg = parse_sysreg_name(tok);
    اگر (sysreg < 0)
        tcc_error("unsupported system register");
    اگلا();
    اگر (tok == ',')
        اگلا();
    parse_عملیہ(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
ساکن صحیح get_branch_condition(صحیح branch_token)
{
    صحیح cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    انتخاب (branch_token) {
        حالت TOK_ASM_beq: cond_token = TOK_ASM_eq; توڑو;
        حالت TOK_ASM_bne: cond_token = TOK_ASM_ne; توڑو;
        حالت TOK_ASM_bcs:
        حالت TOK_ASM_bhs: cond_token = TOK_ASM_cs; توڑو;
        حالت TOK_ASM_bcc:
        حالت TOK_ASM_blo: cond_token = TOK_ASM_cc; توڑو;
        حالت TOK_ASM_bmi: cond_token = TOK_ASM_mi; توڑو;
        حالت TOK_ASM_bpl: cond_token = TOK_ASM_pl; توڑو;
        حالت TOK_ASM_bvs: cond_token = TOK_ASM_vs; توڑو;
        حالت TOK_ASM_bvc: cond_token = TOK_ASM_vc; توڑو;
        حالت TOK_ASM_bhi: cond_token = TOK_ASM_hi; توڑو;
        حالت TOK_ASM_bls: cond_token = TOK_ASM_ls; توڑو;
        حالت TOK_ASM_bge: cond_token = TOK_ASM_ge; توڑو;
        حالت TOK_ASM_blt: cond_token = TOK_ASM_lt; توڑو;
        حالت TOK_ASM_bgt: cond_token = TOK_ASM_gt; توڑو;
        حالت TOK_ASM_ble: cond_token = TOK_ASM_le; توڑو;
        طےشدہ: واپس -1;
    }

    واپس parse_condition(cond_token);
}

/* Handle branch instructions */
ساکن خالی asm_branch(TCCState *s1, صحیح token)
{
    عملیہ op;
    صحیح cond;
    Sym *sym;
    int32_t انحراف;

    /* ret can be used without operand */
    اگر (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        واپس;
    }

    اگر (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_عملیہ(s1, &op);
    ورنہ
        parse_اظہاریہ_عملیہ(s1, &op);

    اگر (op.type & OP_IM) {
        sym = op.e.sym;
        اگر (sym) {
            /* Symbolic address - emit relocation */
            انحراف = 0;

            cond = get_branch_condition(token);
            اگر (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_متن_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } ورنہ {
                انتخاب (token) {
                    حالت TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_متن_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        توڑو;
                    حالت TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_متن_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        توڑو;
                    طےشدہ:
                        tcc_error("unsupported branch");
                }
            }
        } ورنہ {
            انحراف = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            اگر (cond >= 0) {
                gen_b_cond(cond, انحراف);
            } ورنہ {
                انتخاب (token) {
                    حالت TOK_ASM_b:
                        gen_b(انحراف);
                        توڑو;
                    حالت TOK_ASM_bl:
                        gen_bl(انحراف);
                        توڑو;
                    طےشدہ:
                        tcc_error("unsupported branch");
                }
            }
        }
    } ورنہ اگر (op.type & OP_REG) {
        انتخاب (token) {
            حالت TOK_ASM_br:
                gen_br(op.reg);
                توڑو;
            حالت TOK_ASM_blr:
                gen_blr(op.reg);
                توڑو;
            حالت TOK_ASM_ret:
                gen_ret(op.reg);
                توڑو;
            طےشدہ:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
ساکن خالی asm_cb(TCCState *s1, صحیح token)
{
    عملیہ op1, op2;
    صحیح rt, is_64bit;
    int32_t انحراف;
    Sym *sym;

    parse_عملیہ(s1, &op1);
    اگر (tok == ',') اگلا();
    parse_اظہاریہ_عملیہ(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    اگر (sym) {
        /* Symbolic address - emit relocation */
        انحراف = 0;
        اگر (token == TOK_ASM_cbz) {
            gen_cbz(rt, انحراف, is_64bit);
            greloca(cur_متن_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } ورنہ {
            gen_cbnz(rt, انحراف, is_64bit);
            greloca(cur_متن_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } ورنہ {
        انحراف = (int32_t)op2.e.v - ind;
        اگر (token == TOK_ASM_cbz)
            gen_cbz(rt, انحراف, is_64bit);
        ورنہ
            gen_cbnz(rt, انحراف, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
ساکن خالی asm_move_wide(TCCState *s1, صحیح token)
{
    عملیہ op1, op2;
    صحیح rd, is_64bit = 1;
    uint16_t imm;
    صحیح سرکاؤ = 0;

    parse_عملیہ(s1, &op1);
    اگر (tok == ',') اگلا();
    parse_عملیہ(s1, &op2);

    اگر (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        واپس;
    }
    اگر (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        واپس;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    اگر ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        واپس;
    }
    imm = op2.e.v;

    اگر (tok == ',') {
        اگلا();
        اگر (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            واپس;
        }
            اگلا();
            اگر (tok == '#') اگلا();
            asm_اظہاریہ(s1, &op2.e);
        اگر (op2.e.sym || !is_valid_movw_سرکاؤ((صحیح)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            واپس;
        }
            سرکاؤ = (صحیح)op2.e.v / 16;
        }

    انتخاب (token) {
        حالت TOK_ASM_movz:
            gen_movz(rd, imm, سرکاؤ, is_64bit);
            توڑو;
        حالت TOK_ASM_movn:
            gen_movn(rd, imm, سرکاؤ, is_64bit);
            توڑو;
        حالت TOK_ASM_movk:
            gen_movk(rd, imm, سرکاؤ, is_64bit);
            توڑو;
        طےشدہ:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC خالی asm_opcode(TCCState *s1, صحیح opcode)
{
    انتخاب (opcode) {
        حالت TOK_ASM_جوڑو:
        حالت TOK_ASM_adds:
        حالت TOK_ASM_sub:
        حالت TOK_ASM_subs:
        حالت TOK_ASM_and:
        حالت TOK_ASM_ands:
        حالت TOK_ASM_orr:
        حالت TOK_ASM_eor:
        حالت TOK_ASM_mul:
            asm_ڈیٹا_proc(s1, opcode);
            توڑو;

        حالت TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            توڑو;

        حالت TOK_ASM_lsl:
        حالت TOK_ASM_lsr:
        حالت TOK_ASM_asr:
        حالت TOK_ASM_ror:
            asm_سرکاؤ(s1, opcode);
            توڑو;

        حالت TOK_ASM_ldr:
        حالت TOK_ASM_ldrb:
        حالت TOK_ASM_ldrh:
        حالت TOK_ASM_str:
        حالت TOK_ASM_strb:
        حالت TOK_ASM_strh:
            asm_ldst(s1, opcode);
            توڑو;

        حالت TOK_ASM_ldp:
        حالت TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            توڑو;

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
            توڑو;

        حالت TOK_ASM_cbz:
        حالت TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            توڑو;

        حالت TOK_ASM_movz:
        حالت TOK_ASM_movn:
        حالت TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            توڑو;

        حالت TOK_ASM_mrs:
        حالت TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            توڑو;

        حالت TOK_ASM_isb:
        حالت TOK_ASM_dsb:
        حالت TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            توڑو;

        حالت TOK_ASM_nop:
            gen_nop();
            توڑو;

        طےشدہ:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, تہی));
            توڑو;
    }
}

/* Substitute assembler operand */
ST_FUNC خالی subst_asm_عملیہ(CString *جوڑو_str, SValue *sv, صحیح modifier)
{
    صحیح r, reg, سائز, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    اگر ((r & VT_VALMASK) == VT_CONST) {
        اگر ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(جوڑو_str, modifier == 'w' ? "wzr" : "xzr", -1);
            واپس;
        }
        اگر (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(جوڑو_str, '#');
        اگر (r & VT_SYM) {
            ثابت حرف *name = get_tok_str(sv->sym->v, تہی);
            اگر (sv->sym->v >= SYM_پہلا_ANOM)
                get_asm_sym(tok_alloc(name, لڑی_لمبائی(name))->tok, sv->sym);
            اگر (tcc_state->leading_underscore)
                cstr_ccat(جوڑو_str, '_');
            cstr_cat(جوڑو_str, name, -1);
            اگر ((uint32_t) sv->c.i == 0)
                جاؤ no_انحراف;
            cstr_ccat(جوڑو_str, '+');
        }
        uval = sv->c.i;
        اگر (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(جوڑو_str, "%lld", (طویل طویل)val);
        } ورنہ اگر (uval > 0x7fffffffffffffffULL) {
            cstr_printf(جوڑو_str, "0x%llx", (غیرعلامتی طویل طویل)uval);
        } ورنہ {
            val = (int64_t)uval;
            cstr_printf(جوڑو_str, "%lld", (طویل طویل)val);
        }
      no_انحراف:;
    } ورنہ اگر ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(جوڑو_str, "[x29,#%d]", (صحیح) sv->c.i);
    } ورنہ اگر (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_اندرونی_error("");
        cstr_printf(جوڑو_str, "[x%d]", reg);
    } ورنہ {
        /* register case */
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_اندرونی_error("");

        اگر (ARM64_FREG_بنیاد <= reg && reg <= ARM64_FREG_آخری) {
            fp_reg = reg - ARM64_FREG_بنیاد;
            سائز = type_سائز(&sv->type, &align);

            اگر (modifier == 0)
                modifier = سائز <= 4 ? 's'
                         : سائز == 8 ? 'd'
                         : 'q';

            انتخاب (modifier) {
            حالت 'b':
            حالت 'h':
            حالت 's':
            حالت 'd':
            حالت 'q':
            حالت 'Z':
                cstr_printf(جوڑو_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                واپس;
            طےشدہ:
                tcc_error("invalid operand modifier for SIMD/FP register");
                واپس;
            }
        }

        /* choose register operand size */
        اگر ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            سائز = 1;
        ورنہ اگر ((sv->type.t & VT_BTYPE) == VT_SHORT)
            سائز = 2;
        ورنہ اگر ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            سائز = 8;
        ورنہ
            سائز = 4;

        اگر (modifier == 'x') {
            سائز = 8;
        } ورنہ اگر (modifier == 'w' || modifier == 'k') {
            سائز = 4;
        } ورنہ اگر (modifier == 'b') {
            سائز = 1;
        } ورنہ اگر (modifier == 'h') {
            سائز = 2;
        } ورنہ اگر (modifier == 'q') {
            سائز = 8;
        }

        اگر (سائز <= 4) {
            cstr_printf(جوڑو_str, "w%d", reg);
        } ورنہ {
            cstr_printf(جوڑو_str, "x%d", reg);
        }
    }
}

ST_FUNC خالی asm_gen_رمز(ASMOperand *operands, صحیح nb_operands,
                          صحیح nb_outputs, صحیح is_output,
                          uint8_t *clobber_regs,
                          صحیح برآمد_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    صحیح i, reg, saved_گنتی, ڈھیر_سائز, ڈھیر_off;
    صحیح saved_regs[12];
    ساکن ثابت uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    حافظہ_نقل(regs_allocated, clobber_regs, حجم(regs_allocated));
    برائے (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        اگر (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_گنتی = 0;
    برائے (i = 0; i < حجم(reg_saved) / حجم(reg_saved[0]); i++) {
        reg = reg_saved[i];
        اگر (regs_allocated[reg])
            saved_regs[saved_گنتی++] = reg;
    }
    ڈھیر_سائز = ((saved_گنتی + 1) / 2) * 16;

    اگر (!is_output) {
        اگر (saved_گنتی > 0) {
            gen_sub_imm(31, 31, ڈھیر_سائز, 1, 0);

            برائے (i = ڈھیر_off = 0; i < saved_گنتی; ) {
                اگر (i + 1 < saved_گنتی) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ڈھیر_off, 3);
                    ڈھیر_off += 16;
                    i += 2;
                } ورنہ {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 ڈھیر_off, 3);
                    i++;
                }
            }
        }

        برائے (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر (op->is_حافظہ) {
                    arm64_بھرو_حافظہ_عملیہ_بنیاد(op->reg, op->vt);
                } ورنہ اگر (i >= nb_outputs || op->is_rw) {
                    بھرو(op->reg, op->vt);
                }
            }
        }
    } ورنہ {
        برائے (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر (op->is_حافظہ)
                    جاری;
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    اگر (!op->is_حافظہ) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        بھرو(برآمد_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | برآمد_reg;
                        store(op->reg, &sv);
                    }
                } ورنہ {
                    store(op->reg, op->vt);
                }
            }
        }

        اگر (saved_گنتی > 0) {
            برائے (i = ڈھیر_off = 0; i < saved_گنتی; ) {
                اگر (i + 1 < saved_گنتی) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ڈھیر_off, 3);
                    ڈھیر_off += 16;
                    i += 2;
                } ورنہ {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 ڈھیر_off, 3);
                    i++;
                }
            }
            gen_جوڑو_imm(31, 31, ڈھیر_سائز, 1, 0);
        }
    }
}

ST_FUNC خالی asm_compute_constraints(ASMOperand *operands,
                                    صحیح nb_operands, صحیح nb_outputs,
                                    ثابت uint8_t *clobber_regs,
                                    صحیح *pout_reg)
{
    ASMOperand *op;
    صحیح sorted_op[MAX_ASM_OPERANDS];
    صحیح i, j, k, p1, p2, tmp, reg, c, reg_نقاب;
    ثابت حرف *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    برائے (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->داخلہ_اشاریہ = -1;
        op->ref_اشاریہ = -1;
        op->reg = -1;
        op->is_حافظہ = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    برائے (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        اگر (isnum(*str) || *str == '[') {
            k = ڈھونڈو_constraint(operands, nb_operands, str, تہی);
            اگر ((غیرعلامتی)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_اشاریہ = k;
            اگر (operands[k].داخلہ_اشاریہ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].داخلہ_اشاریہ = i;
            op->ترجیح = 5;
        } ورنہ اگر ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->ترجیح = 1;
            op->reg = reg;
        } ورنہ {
            op->ترجیح = constraint_ترجیح(str);
        }
    }

    برائے (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    برائے (i = 0; i < nb_operands - 1; i++) {
        برائے (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].ترجیح;
            p2 = operands[sorted_op[j]].ترجیح;
            اگر (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    برائے (i = 0; i < NB_ASM_REGS; i++) {
        اگر (clobber_regs[i])
            regs_allocated[i] = REG_اندر_نقاب | REG_برآمد_نقاب;
        ورنہ
            regs_allocated[i] = 0;
    }

    برائے (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        اگر (op->ref_اشاریہ >= 0)
            جاری;
        اگر (op->داخلہ_اشاریہ >= 0) {
            reg_نقاب = REG_اندر_نقاب | REG_برآمد_نقاب;
        } ورنہ اگر (j < nb_outputs) {
            reg_نقاب = REG_برآمد_نقاب;
        } ورنہ {
            reg_نقاب = REG_اندر_نقاب;
        }
        اگر (op->reg >= 0) {
            اگر (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            جاؤ reg_ملا;
        }
    try_اگلا:
        c = *str++;
        انتخاب (c) {
        حالت '=':
            جاؤ try_اگلا;
        حالت '+':
            op->is_rw = 1;
        حالت '&':
            اگر (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_نقاب = REG_اندر_نقاب | REG_برآمد_نقاب;
            جاؤ try_اگلا;
        حالت 'r':
            برائے (reg = 0; reg < 31; reg++) {
                اگر (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    جاؤ reg_ملا;
            }
            جاؤ try_اگلا;
        حالت 'w':
        حالت 'f':
            برائے (reg = ARM64_FREG_بنیاد; reg <= ARM64_FREG_آخری; reg++) {
                اگر (!is_reg_allocated(reg))
                    جاؤ reg_ملا;
            }
            جاؤ try_اگلا;
        حالت 'x':
        حالت 'y':
            برائے (reg = ARM64_FREG_بنیاد; reg <= ARM64_FREG_آخری; reg++) {
                اگر (!is_reg_allocated(reg))
                    جاؤ reg_ملا;
            }
            جاؤ try_اگلا;
        حالت 'm':
        حالت 'g':
            اگر (j < nb_outputs || c == 'm') {
                اگر (!arm64_prepare_حافظہ_عملیہ(op, regs_allocated))
                    جاؤ try_اگلا;
            }
            توڑو;
        حالت 'Q':
            اگر (!arm64_حافظہ_is_بنیاد_only(op->vt))
                جاؤ try_اگلا;
            اگر (!arm64_prepare_حافظہ_عملیہ(op, regs_allocated))
                جاؤ try_اگلا;
            توڑو;
        حالت 'S':
            اگر ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                جاؤ try_اگلا;
            توڑو;
        حالت 'U':
            اگر (str[0] != 'm' || str[1] != 'p')
                جاؤ try_اگلا;
            str += 2;
            اگر (!arm64_حافظہ_is_pair_suitable(op->vt))
                جاؤ try_اگلا;
            اگر (!arm64_prepare_حافظہ_عملیہ(op, regs_allocated))
                جاؤ try_اگلا;
            توڑو;
        حالت 'i':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                جاؤ try_اگلا;
            توڑو;
        حالت 'I':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                جاؤ try_اگلا;
            اگر (!is_valid_جوڑو_imm(op->vt->c.i))
                جاؤ try_اگلا;
            توڑو;
        حالت 'J':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                جاؤ try_اگلا;
            اگر (!is_valid_جوڑو_imm(-op->vt->c.i))
                جاؤ try_اگلا;
            توڑو;
        حالت 'K':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                جاؤ try_اگلا;
            اگر (!is_valid_logical_imm(op->vt->c.i, 32))
                جاؤ try_اگلا;
            توڑو;
        حالت 'L':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                جاؤ try_اگلا;
            اگر (!is_valid_logical_imm(op->vt->c.i, 64))
                جاؤ try_اگلا;
            توڑو;
        حالت 'M':
        حالت 'N':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                جاؤ try_اگلا;
            اگر (!is_valid_movw_imm(op->vt->c.i))
                جاؤ try_اگلا;
            توڑو;
        حالت 'Z':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                جاؤ try_اگلا;
            اگر (op->vt->c.i != 0)
                جاؤ try_اگلا;
            توڑو;
        حالت 'n':
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                جاؤ try_اگلا;
            توڑو;
        طےشدہ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            توڑو;
        }
        اگر (op->داخلہ_اشاریہ >= 0) {
            operands[op->داخلہ_اشاریہ].reg = op->reg;
            operands[op->داخلہ_اشاریہ].is_llong = op->is_llong;
        }
        جاری;
    reg_ملا:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_نقاب;
        اگر (op->داخلہ_اشاریہ >= 0) {
            operands[op->داخلہ_اشاریہ].reg = op->reg;
            operands[op->داخلہ_اشاریہ].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    برائے (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        اگر (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_حافظہ) {
            برائے (reg = 0; reg < 31; reg++) {
                اگر (!(regs_allocated[reg] & REG_برآمد_نقاب))
                    جاؤ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            توڑو;
        }
    }
}

/* Handle clobber list */
ST_FUNC خالی asm_clobber(uint8_t *clobber_regs, ثابت حرف *str)
{
    صحیح reg;

    اگر (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        واپس;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    اگر (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC صحیح asm_parse_regvar(صحیح t)
{
    واپس arm64_parse_regvar(t);
}

/*************************************************************/
#اگر_ختم /* ndef TARGET_DEFS_ONLY */
