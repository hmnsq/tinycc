/*************************************************************/
/*
 *  ARM64 (AArch64) assembler for TCC
 *
 *  Based on ARM64 Architecture Reference Manual
 *  Supports AArch64 assembler parsing and extended inline asm
 *  with operands, constraints, and clobbers.
 */

#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

#నిర్వచించు CONFIG_TCC_ASM
/* 32 general purpose + 32 SIMD/FP registers */
#నిర్వచించు NB_ASM_REGS 64

ST_FUNC శూన్య g(పూర్ణాంకం c);
ST_FUNC శూన్య gen_le16(పూర్ణాంకం c);
ST_FUNC శూన్య gen_le32(పూర్ణాంకం c);

/*************************************************************/
#లేకపోతే
/*************************************************************/

#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"

/* Register type flags */
#నిర్వచించు REG_X     0x01  /* 64-bit general purpose */
#నిర్వచించు REG_W     0x02  /* 32-bit general purpose */
#నిర్వచించు REG_V     0x04  /* 128-bit SIMD */
#నిర్వచించు REG_D     0x08  /* 64-bit FP */
#నిర్వచించు REG_S     0x10  /* 32-bit FP */
#నిర్వచించు REG_H     0x20  /* 16-bit FP */
#నిర్వచించు REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
గణన {
    OPT_REG,
    OPT_IM,
    OPT_ADDR,
    OPT_COND,
};

#నిర్వచించు OP_REG     (1 << OPT_REG)
#నిర్వచించు OP_IM      (1 << OPT_IM)
#నిర్వచించు OP_ADDR    (1 << OPT_ADDR)
#నిర్వచించు OP_COND    (1 << OPT_COND)

/* Register allocation masks */
#నిర్వచించు REG_బహిర్గతం_ముసుగు 0x01
#నిర్వచించు REG_లోపల_ముసుగు  0x02

#నిర్వచించు is_reg_allocated(reg) (regs_allocated[reg] & reg_ముసుగు)

/* ARM64 register constants */
#నిర్వచించు TREG_X0  0
#నిర్వచించు TREG_X1  1
#నిర్వచించు TREG_X2  2
#నిర్వచించు TREG_X3  3
#నిర్వచించు TREG_X4  4
#నిర్వచించు TREG_X5  5
#నిర్వచించు TREG_X6  6
#నిర్వచించు TREG_X7  7
#నిర్వచించు TREG_X8  8
#నిర్వచించు TREG_X9  9
#నిర్వచించు TREG_X10 10
#నిర్వచించు TREG_X11 11
#నిర్వచించు TREG_X12 12
#నిర్వచించు TREG_X13 13
#నిర్వచించు TREG_X14 14
#నిర్వచించు TREG_X15 15
#నిర్వచించు TREG_X16 16
#నిర్వచించు TREG_X17 17
#నిర్వచించు TREG_X18 18
#నిర్వచించు TREG_X19 19
#నిర్వచించు TREG_X20 20
#నిర్వచించు TREG_X21 21
#నిర్వచించు TREG_X22 22
#నిర్వచించు TREG_X23 23
#నిర్వచించు TREG_X24 24
#నిర్వచించు TREG_X25 25
#నిర్వచించు TREG_X26 26
#నిర్వచించు TREG_X27 27
#నిర్వచించు TREG_X28 28
#నిర్వచించు TREG_X29 29
#నిర్వచించు TREG_X30 30
#నిర్వచించు TREG_SP  31

#నిర్వచించు ARM64_FREG_పునాది 20
#నిర్వచించు ARM64_FREG_చివరి (ARM64_FREG_పునాది + 7)

రకనిర్వచనం నిర్మాణం నిర్వాహ్యం {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t జరుపు;
    uint8_t addr_బహుళకం;
    పూర్ణాంకం reg_tok;
    సమాసం_విలువ e;
} నిర్వాహ్యం;

గణన {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
స్థిర శూన్య parse_addr_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op);

/* XXX: make it faster ? */
ST_FUNC శూన్య g(పూర్ణాంకం c)
{
    పూర్ణాంకం ind1;
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    ind1 = ind + 1;
    ఒకవేళ (ind1 > cur_పాఠ్యం_section->దత్తాంశం_allocated)
        section_realloc(cur_పాఠ్యం_section, ind1);
    cur_పాఠ్యం_section->దత్తాంశం[ind] = c;
    ind = ind1;
}

ST_FUNC శూన్య gen_le16(పూర్ణాంకం c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC శూన్య gen_le32(పూర్ణాంకం c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC శూన్య gen_expr32(సమాసం_విలువ *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
స్థిర శూన్య emit_instr32(uint32_t val)
{
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    ఒకవేళ (ind + 4 > cur_పాఠ్యం_section->దత్తాంశం_allocated)
        section_realloc(cur_పాఠ్యం_section, ind + 4);
    write32le(cur_పాఠ్యం_section->దత్తాంశం + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
స్థిర పూర్ణాంకం arm64_parse_asm_reg(పూర్ణాంకం t)
{
    /* X registers (64-bit) */
    ఒకవేళ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        తిరిగి t - TOK_ASM_x0;
    /* W registers (32-bit) */
    ఒకవేళ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        తిరిగి t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    ఒకవేళ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        తిరిగి (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    ఒకవేళ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        తిరిగి (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    ఒకవేళ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        తిరిగి (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    ఒకవేళ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        తిరిగి (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    ఒకవేళ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        తిరిగి (t - TOK_ASM_b0) + 32;
    /* Special registers */
    ఒకవేళ (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        తిరిగి 31;  /* SP/ZR encoded as 31 */
    తిరిగి -1;
}

/* Get register type from token */
స్థిర uint8_t get_reg_type(పూర్ణాంకం t)
{
    ఒకవేళ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        తిరిగి REG_X;
    ఒకవేళ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        తిరిగి REG_W;
    ఒకవేళ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        తిరిగి REG_V;
    ఒకవేళ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        తిరిగి REG_D;
    ఒకవేళ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        తిరిగి REG_S;
    ఒకవేళ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        తిరిగి REG_H;
    ఒకవేళ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        తిరిగి REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    ఒకవేళ (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        తిరిగి REG_X;
    ఒకవేళ (t == TOK_ASM_wzr)
        తిరిగి REG_W;
    తిరిగి REG_X;
}

/* Parse condition code */
స్థిర పూర్ణాంకం parse_condition(పూర్ణాంకం t)
{
    ఎంపిక (t) {
        స్థితి TOK_ASM_eq: తిరిగి 0;
        స్థితి TOK_ASM_ne: తిరిగి 1;
        స్థితి TOK_ASM_cs:
        స్థితి TOK_ASM_hs: తిరిగి 2;
        స్థితి TOK_ASM_cc:
        స్థితి TOK_ASM_lo: తిరిగి 3;
        స్థితి TOK_ASM_mi: తిరిగి 4;
        స్థితి TOK_ASM_pl: తిరిగి 5;
        స్థితి TOK_ASM_vs: తిరిగి 6;
        స్థితి TOK_ASM_vc: తిరిగి 7;
        స్థితి TOK_ASM_hi: తిరిగి 8;
        స్థితి TOK_ASM_ls: తిరిగి 9;
        స్థితి TOK_ASM_ge: తిరిగి 10;
        స్థితి TOK_ASM_lt: తిరిగి 11;
        స్థితి TOK_ASM_gt: తిరిగి 12;
        స్థితి TOK_ASM_le: తిరిగి 13;
        స్థితి TOK_ASM_al: తిరిగి 14;
        అప్రమేయ: తిరిగి -1;
    }
}

స్థిర పూర్ణాంకం parse_barrier_option_name(పూర్ణాంకం t)
{
    స్థిరరాశి అక్షరం *name;

    ఒకవేళ (t < TOK_IDENT)
        తిరిగి -1;
    name = get_tok_str(t, ఖాళీ);
    ఒకవేళ (!strcmp(name, "oshld")) తిరిగి 0x1;
    ఒకవేళ (!strcmp(name, "oshst")) తిరిగి 0x2;
    ఒకవేళ (!strcmp(name, "osh"))   తిరిగి 0x3;
    ఒకవేళ (!strcmp(name, "nshld")) తిరిగి 0x5;
    ఒకవేళ (!strcmp(name, "nshst")) తిరిగి 0x6;
    ఒకవేళ (!strcmp(name, "nsh"))   తిరిగి 0x7;
    ఒకవేళ (!strcmp(name, "ishld")) తిరిగి 0x9;
    ఒకవేళ (!strcmp(name, "ishst")) తిరిగి 0xA;
    ఒకవేళ (!strcmp(name, "ish"))   తిరిగి 0xB;
    ఒకవేళ (!strcmp(name, "ld"))    తిరిగి 0xD;
    ఒకవేళ (!strcmp(name, "st"))    తిరిగి 0xE;
    ఒకవేళ (!strcmp(name, "sy"))    తిరిగి 0xF;
    తిరిగి -1;
}

స్థిర పూర్ణాంకం arm64_parse_regvar(పూర్ణాంకం t)
{
    ఒకవేళ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        తిరిగి t - TOK_ASM_x0;
    ఒకవేళ (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        తిరిగి ARM64_FREG_పునాది + (t - TOK_ASM_v0);
    ఒకవేళ (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        తిరిగి ARM64_FREG_పునాది + (t - TOK_ASM_d0);
    ఒకవేళ (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        తిరిగి ARM64_FREG_పునాది + (t - TOK_ASM_s0);
    ఒకవేళ (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        తిరిగి ARM64_FREG_పునాది + (t - TOK_ASM_h0);
    ఒకవేళ (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        తిరిగి ARM64_FREG_పునాది + (t - TOK_ASM_b0);
    తిరిగి -1;
}

/* Parse a single operand */
స్థిర శూన్య parse_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op)
{
    పూర్ణాంకం reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->జరుపు = 0;
    op->addr_బహుళకం = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    ఒకవేళ (tok == '[') {
        parse_addr_నిర్వాహ్యం(s1, op);
        తిరిగి;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    ఒకవేళ (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        తదుపరి();
        తిరిగి;
    }

    /* Condition code */
    reg = parse_condition(tok);
    ఒకవేళ (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        తదుపరి();
        తిరిగి;
    }

    /* Immediate or address expression */
    ఒకవేళ (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        తదుపరి();
        asm_సమాసం(s1, &op->e);
        op->type = OP_IM;
    } లేకపోతే ఒకవేళ (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } లేకపోతే {
        asm_సమాసం(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
స్థిర శూన్య parse_సమాసం_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->జరుపు = 0;
    op->addr_బహుళకం = ADDR_OFF;
    op->reg_tok = 0;

    ఒకవేళ (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        తదుపరి();
    asm_సమాసం(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
స్థిర శూన్య parse_addr_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op)
{
    పూర్ణాంకం reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = ఖాళీ;
    op->addr_బహుళకం = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    ఒకవేళ (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        తిరిగి;
    }
    op->reg = reg;
    op->reg_tok = tok;
    తదుపరి();
    /* Check for offset */
    ఒకవేళ (tok == ',') {
        తదుపరి();
        ఒకవేళ (tok == '#' || tok == '@' || tok == '$')
            తదుపరి();
        asm_సమాసం(s1, &op->e);
    }
    skip(']');
    ఒకవేళ (tok == '!') {
        op->addr_బహుళకం = ADDR_PRE;
        తదుపరి();
    } లేకపోతే ఒకవేళ (tok == ',') {
        op->addr_బహుళకం = ADDR_POST;
        తదుపరి();
        ఒకవేళ (tok == '#' || tok == '@' || tok == '$')
            తదుపరి();
        asm_సమాసం(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
స్థిర శూన్య gen_mov_with_పునాది(పూర్ణాంకం rd, uint16_t imm, పూర్ణాంకం జరుపు,
                              పూర్ణాంకం is_64bit, uint32_t పునాది_opcode)
{
    uint32_t instr = పునాది_opcode;
    ఒకవేళ (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, జరుపు);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

స్థిర శూన్య gen_movz(పూర్ణాంకం rd, uint16_t imm, పూర్ణాంకం జరుపు, పూర్ణాంకం is_64bit)
{
    gen_mov_with_పునాది(rd, imm, జరుపు, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
స్థిర శూన్య gen_movn(పూర్ణాంకం rd, uint16_t imm, పూర్ణాంకం జరుపు, పూర్ణాంకం is_64bit)
{
    gen_mov_with_పునాది(rd, imm, జరుపు, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
స్థిర శూన్య gen_movk(పూర్ణాంకం rd, uint16_t imm, పూర్ణాంకం జరుపు, పూర్ణాంకం is_64bit)
{
    gen_mov_with_పునాది(rd, imm, జరుపు, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
స్థిర శూన్య gen_కూడు_imm(పూర్ణాంకం rd, పూర్ణాంకం rn, uint32_t imm, పూర్ణాంకం is_64bit, పూర్ణాంకం setflags)
{
    uint32_t instr = ARM64_కూడు_IMM;
    uint32_t imm12;

    ఒకవేళ (is_64bit) instr |= ARM64_SF(1);
    ఒకవేళ (setflags) instr |= ARM64_S(1);

    ఒకవేళ (imm <= 0xFFF) {
        imm12 = imm;
    } లేకపోతే ఒకవేళ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } లేకపోతే {
        tcc_error("add immediate out of range");
        తిరిగి;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
స్థిర శూన్య gen_sub_imm(పూర్ణాంకం rd, పూర్ణాంకం rn, uint32_t imm, పూర్ణాంకం is_64bit, పూర్ణాంకం setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    ఒకవేళ (is_64bit) instr |= ARM64_SF(1);
    ఒకవేళ (setflags) instr |= ARM64_S(1);

    ఒకవేళ (imm <= 0xFFF) {
        imm12 = imm;
    } లేకపోతే ఒకవేళ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } లేకపోతే {
        tcc_error("sub immediate out of range");
        తిరిగి;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
స్థిర శూన్య gen_dp_reg(uint32_t opcode, పూర్ణాంకం rd, పూర్ణాంకం rn, పూర్ణాంకం rm, పూర్ణాంకం is_64bit)
{
    uint32_t instr = opcode;
    ఒకవేళ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
స్థిర శూన్య gen_ldst_imm(uint32_t పునాది_opcode, పూర్ణాంకం rt, పూర్ణాంకం rn,
                         int32_t స్థానభ్రంశం, పూర్ణాంకం కొలత_log2)
{
    uint32_t instr = పునాది_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    ఒకవేళ (స్థానభ్రంశం >= 0 && !(స్థానభ్రంశం & ((1 << కొలత_log2) - 1))) {
    imm12 = స్థానభ్రంశం >> కొలత_log2;
        ఒకవేళ (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            తిరిగి;
        }
    }

    ఎంపిక (పునాది_opcode) {
    స్థితి ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; ఆపు;
    స్థితి ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; ఆపు;
    స్థితి ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; ఆపు;
    స్థితి ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; ఆపు;
    స్థితి ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; ఆపు;
    స్థితి ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; ఆపు;
    స్థితి ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; ఆపు;
    స్థితి ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; ఆపు;
    స్థితి ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; ఆపు;
    స్థితి ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; ఆపు;
    }

    ఒకవేళ (unscaled_opcode && స్థానభ్రంశం >= -256 && స్థానభ్రంశం <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)స్థానభ్రంశం & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        తిరిగి;
    }

    ఒకవేళ (స్థానభ్రంశం & ((1 << కొలత_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
స్థిర శూన్య gen_ldst_pair(uint32_t పునాది_opcode, పూర్ణాంకం rt, పూర్ణాంకం rt2, పూర్ణాంకం rn,
                          int32_t స్థానభ్రంశం, పూర్ణాంకం కొలత_log2)
{
    int32_t imm7;
    uint32_t instr = పునాది_opcode;

    ఒకవేళ (స్థానభ్రంశం & ((1 << కొలత_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = స్థానభ్రంశం >> కొలత_log2;
    ఒకవేళ (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
స్థిర శూన్య gen_b_or_bl(int32_t స్థానభ్రంశం, uint32_t పునాది_opcode)
{
    uint32_t instr = పునాది_opcode;
    instr |= ARM64_OFFSET26(స్థానభ్రంశం);
    emit_instr32(instr);
}

స్థిర శూన్య gen_b(int32_t స్థానభ్రంశం)
{
    gen_b_or_bl(స్థానభ్రంశం, ARM64_B);
}

/* Generate BL (branch with link) */
స్థిర శూన్య gen_bl(int32_t స్థానభ్రంశం)
{
    gen_b_or_bl(స్థానభ్రంశం, ARM64_BL);
}

/* Generate BR (branch to register) */
స్థిర శూన్య gen_br(పూర్ణాంకం rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
స్థిర శూన్య gen_blr(పూర్ణాంకం rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
స్థిర శూన్య gen_ret(పూర్ణాంకం rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
స్థిర శూన్య gen_b_cond(పూర్ణాంకం cond, int32_t స్థానభ్రంశం)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(స్థానభ్రంశం);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
స్థిర శూన్య gen_cbz_or_cbnz(పూర్ణాంకం rt, int32_t స్థానభ్రంశం, పూర్ణాంకం is_64bit, uint32_t పునాది_opcode)
{
    uint32_t instr = పునాది_opcode;
    ఒకవేళ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(స్థానభ్రంశం);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

స్థిర శూన్య gen_cbz(పూర్ణాంకం rt, int32_t స్థానభ్రంశం, పూర్ణాంకం is_64bit)
{
    gen_cbz_or_cbnz(rt, స్థానభ్రంశం, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
స్థిర శూన్య gen_cbnz(పూర్ణాంకం rt, int32_t స్థానభ్రంశం, పూర్ణాంకం is_64bit)
{
    gen_cbz_or_cbnz(rt, స్థానభ్రంశం, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
స్థిర శూన్య gen_mov_reg(పూర్ణాంకం rd, పూర్ణాంకం rm, పూర్ణాంకం is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    ఒకవేళ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

స్థిర పూర్ణాంకం arm64_asm_encode_bimm64(uint64_t x)
{
    పూర్ణాంకం neg, rep, pos, len;

    neg = x & 1;
    ఒకవేళ (neg)
        x = ~x;
    ఒకవేళ (!x)
        తిరిగి -1;

    ఒకవేళ (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    లేకపోతే ఒకవేళ (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    లేకపోతే ఒకవేళ (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    లేకపోతే ఒకవేళ (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    లేకపోతే ఒకవేళ (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    లేకపోతే
        rep = 64;

    pos = 0;
    ఒకవేళ (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    ఒకవేళ (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    ఒకవేళ (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    ఒకవేళ (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    ఒకవేళ (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    ఒకవేళ (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    ఒకవేళ (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    ఒకవేళ (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    ఒకవేళ (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    ఒకవేళ (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    ఒకవేళ (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    ఒకవేళ (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    ఒకవేళ (x)
        తిరిగి -1;
    ఒకవేళ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    తిరిగి ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

స్థిర శూన్య gen_logical_imm(uint32_t opcode, పూర్ణాంకం rd, పూర్ణాంకం rn,
                            uint64_t imm, పూర్ణాంకం is_64bit)
{
    uint32_t instr;
    uint64_t val;
    పూర్ణాంకం enc;

    ఒకవేళ (is_64bit)
        val = imm;
    లేకపోతే {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    ఒకవేళ (enc < 0) {
        tcc_error("logical immediate out of range");
        తిరిగి;
    }

    instr = opcode;
    ఒకవేళ (is_64bit)
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
స్థిర అంతఃవరుస పూర్ణాంకం constraint_ప్రాధాన్యత(స్థిరరాశి అక్షరం *str)
{
    పూర్ణాంకం ప్రాధాన్యత, c, pr;

    ప్రాధాన్యత = 0;
    కొరకు (;;) {
        c = *str++;
        ఒకవేళ (c == '\0')
            ఆపు;
        ఎంపిక (c) {
        స్థితి '=':
        స్థితి '+':
        స్థితి '&':
            కొనసాగు;
        స్థితి 'r':
            pr = 1;
            ఆపు;
        స్థితి 'w':
        స్థితి 'f':
        స్థితి 'x':
        స్థితి 'y':
            pr = 3;
            ఆపు;
        స్థితి 'm':
        స్థితి 'Q':
            pr = 4;
            ఆపు;
        స్థితి 'i':
        స్థితి 'S':
            pr = 5;
            ఆపు;
        స్థితి 'U':
            ఒకవేళ (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                ఆపు;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            ఆపు;
        స్థితి 'I':
        స్థితి 'J':
        స్థితి 'K':
        స్థితి 'L':
        స్థితి 'M':
        స్థితి 'N':
        స్థితి 'Z':
            pr = 6;
            ఆపు;
        స్థితి 'n':
            pr = 7;
            ఆపు;
        స్థితి 'g':
            pr = 8;
            ఆపు;
        అప్రమేయ:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            ఆపు;
        }
        ఒకవేళ (pr > ప్రాధాన్యత)
            ప్రాధాన్యత = pr;
    }
    తిరిగి ప్రాధాన్యత;
}

స్థిర స్థిరరాశి అక్షరం *skip_constraint_modifiers(స్థిరరాశి అక్షరం *p)
{
    అయితే (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    తిరిగి p;
}

స్థిర పూర్ణాంకం is_valid_కూడు_imm(int64_t val)
{
    తిరిగి val >= 0 && val <= 4095;
}

స్థిర పూర్ణాంకం is_valid_logical_imm(int64_t val, పూర్ణాంకం బిట్లు)
{
    uint64_t uval;

    uval = (uint64_t)val;
    ఒకవేళ (బిట్లు == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    తిరిగి arm64_asm_encode_bimm64(uval) >= 0;
}

స్థిర పూర్ణాంకం is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    ఒకవేళ (uval <= 0xFFFF)
        తిరిగి 1;
    ఒకవేళ (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        తిరిగి 1;
    ఒకవేళ (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        తిరిగి 1;
    ఒకవేళ ((uval & 0xFFFFFFFF00000000ULL) == 0)
        తిరిగి 1;

    తిరిగి 0;
}

స్థిర పూర్ణాంకం is_valid_movw_జరుపు(పూర్ణాంకం జరుపు, పూర్ణాంకం is_64bit)
{
    ఒకవేళ (జరుపు < 0 || (జరుపు & 15))
        తిరిగి 0;
    ఒకవేళ (జరుపు > (is_64bit ? 48 : 16))
        తిరిగి 0;
    తిరిగి 1;
}

స్థిర పూర్ణాంకం arm64_జ్ఞాపకం_is_పునాది_only(స్థిరరాశి SValue *sv)
{
    పూర్ణాంకం r;

    r = sv->r;
    ఒకవేళ ((r & VT_VALMASK) == VT_CONST)
        తిరిగి 0;
    ఒకవేళ ((r & VT_VALMASK) == VT_LOCAL)
        తిరిగి 0;
    ఒకవేళ ((r & VT_VALMASK) == VT_LLOCAL)
        తిరిగి 1;
    ఒకవేళ (r & VT_LVAL)
        తిరిగి (r & VT_VALMASK) < VT_CONST;
    తిరిగి 0;
}

స్థిర పూర్ణాంకం arm64_జ్ఞాపకం_is_pair_suitable(స్థిరరాశి SValue *sv)
{
    int64_t స్థానభ్రంశం;

    ఒకవేళ (arm64_జ్ఞాపకం_is_పునాది_only(sv))
        తిరిగి 1;
    ఒకవేళ ((sv->r & VT_VALMASK) != VT_LOCAL)
        తిరిగి 0;

    స్థానభ్రంశం = (int64_t)sv->c.i;
    తిరిగి (స్థానభ్రంశం & 7) == 0 && స్థానభ్రంశం >= -512 && స్థానభ్రంశం <= 504;
}

స్థిర పూర్ణాంకం arm64_int_reg_is_allocatable(పూర్ణాంకం reg)
{
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    తిరిగి reg >= TREG_X0 && reg <= TREG_X17;
#లేకపోతే
    తిరిగి reg >= TREG_X0 && reg <= TREG_X30;
#అయితే_ముగింపు
}

స్థిర పూర్ణాంకం arm64_జ్ఞాపకం_needs_చిరునామా_reg(స్థిరరాశి SValue *sv)
{
    పూర్ణాంకం r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    ఒకవేళ (!(r & VT_LVAL))
        తిరిగి 0;
    ఎంపిక (r & VT_VALMASK) {
    స్థితి VT_LOCAL:
    స్థితి VT_LLOCAL:
    స్థితి VT_CONST:
        తిరిగి 1;
    }
    తిరిగి 0;
}

స్థిర పూర్ణాంకం arm64_prepare_జ్ఞాపకం_నిర్వాహ్యం(ASMOperand *op, uint8_t *regs_allocated)
{
    పూర్ణాంకం reg;

    ఒకవేళ (!arm64_జ్ఞాపకం_needs_చిరునామా_reg(op->vt))
        తిరిగి 1;

    కొరకు (reg = 0; reg < 31; reg++) {
        ఒకవేళ (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_లోపల_ముసుగు)) {
            regs_allocated[reg] |= REG_లోపల_ముసుగు;
            op->reg = reg;
            op->is_జ్ఞాపకం = 1;
            తిరిగి 1;
        }
    }
    తిరిగి 0;
}

స్థిర శూన్య arm64_ఎక్కించు_జ్ఞాపకం_నిర్వాహ్యం_పునాది(పూర్ణాంకం reg, SValue *sv)
{
    SValue పునాది;
    పూర్ణాంకం rval;

    పునాది = *sv;
    పునాది.type.t = VT_PTR;
    rval = పునాది.r & VT_VALMASK;
    ఒకవేళ (rval == VT_LLOCAL) {
        పునాది.r = (పునాది.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } లేకపోతే ఒకవేళ (rval == VT_CONST || rval == VT_LOCAL) {
        పునాది.r &= ~VT_LVAL;
    } లేకపోతే {
        tcc_అంతర్గత_error("unsupported ARM64 memory operand base");
    }
    ఎక్కించు(reg, &పునాది);
}

స్థిర పూర్ణాంకం నిర్వాహ్యం_is_sp(స్థిరరాశి నిర్వాహ్యం *op)
{
    తిరిగి op->reg_tok == TOK_ASM_sp;
}

స్థిర పూర్ణాంకం parse_sysreg_name(పూర్ణాంకం t)
{
    స్థిరరాశి అక్షరం *name;

    ఒకవేళ (t < TOK_IDENT)
        తిరిగి -1;
    name = get_tok_str(t, ఖాళీ);
    ఒకవేళ (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        తిరిగి 0;
    ఒకవేళ (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        తిరిగి 1;
    తిరిగి -1;
}

స్థిర శూన్య gen_mrs(పూర్ణాంకం rt, పూర్ణాంకం sysreg)
{
    uint32_t instr;

    ఎంపిక (sysreg) {
        స్థితి 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            ఆపు;
        స్థితి 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            ఆపు;
        అప్రమేయ:
            tcc_error("unsupported system register");
            తిరిగి;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

స్థిర శూన్య gen_msr(పూర్ణాంకం rt, పూర్ణాంకం sysreg)
{
    uint32_t instr;

    ఎంపిక (sysreg) {
        స్థితి 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            ఆపు;
        స్థితి 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            ఆపు;
        అప్రమేయ:
            tcc_error("unsupported system register");
            తిరిగి;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
స్థిర శూన్య gen_nop(శూన్య)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
స్థిర శూన్య gen_జరుపు(పూర్ణాంకం rd, పూర్ణాంకం rn, పూర్ణాంకం rm_or_imm, పూర్ణాంకం జరుపు_type, పూర్ణాంకం is_imm, పూర్ణాంకం is_64bit)
{
    uint32_t instr;
    పూర్ణాంకం వెడల్పు = is_64bit ? 64 : 32;

    ఒకవేళ (is_imm) {
        /* Shift by immediate */
        ఎంపిక (జరుపు_type) {
            స్థితి 0: /* LSL - UBFM alias */
                ఒకవేళ (rm_or_imm < 0 || rm_or_imm >= వెడల్పు) {
                    tcc_error("shift immediate out of range");
                    తిరిగి;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((వెడల్పు - rm_or_imm) & (వెడల్పు - 1));
                instr |= ARM64_IMM_S(వెడల్పు - rm_or_imm - 1);
                ఆపు;
            స్థితి 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                ఒకవేళ (rm_or_imm < 0 || rm_or_imm >= వెడల్పు) {
                    tcc_error("shift immediate out of range");
                    తిరిగి;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(వెడల్పు - 1);
                ఆపు;
            స్థితి 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                ఒకవేళ (rm_or_imm < 0 || rm_or_imm >= వెడల్పు) {
                    tcc_error("shift immediate out of range");
                    తిరిగి;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(వెడల్పు - 1);
                ఆపు;
            స్థితి 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                ఒకవేళ (rm_or_imm < 0 || rm_or_imm >= వెడల్పు) {
                    tcc_error("shift immediate out of range");
                    తిరిగి;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                తిరిగి;
            అప్రమేయ:
                tcc_error("unknown shift type");
                తిరిగి;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } లేకపోతే {
        /* Shift by register */
        ఎంపిక (జరుపు_type) {
            స్థితి 0: /* LSL */
                instr = ARM64_LSL_REG;
                ఆపు;
            స్థితి 1: /* LSR */
                instr = ARM64_LSR_REG;
                ఆపు;
            స్థితి 2: /* ASR */
                instr = ARM64_ASR_REG;
                ఆపు;
            స్థితి 3: /* ROR */
                instr = ARM64_ROR_REG;
                ఆపు;
            అప్రమేయ:
                tcc_error("unknown shift type");
                తిరిగి;
        }
        ఒకవేళ (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
స్థిర శూన్య asm_జరుపు(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం op1, op2, op3;
    పూర్ణాంకం rd, rn, జరుపు_amount;
    పూర్ణాంకం జరుపు_type;
    పూర్ణాంకం is_64bit = 1;

    ఎంపిక (token) {
        స్థితి TOK_ASM_lsl:
            జరుపు_type = 0;
            ఆపు;
        స్థితి TOK_ASM_lsr:
            జరుపు_type = 1;
            ఆపు;
        స్థితి TOK_ASM_asr:
            జరుపు_type = 2;
            ఆపు;
        స్థితి TOK_ASM_ror:
            జరుపు_type = 3;
            ఆపు;
        అప్రమేయ:
            tcc_error("unknown shift instruction");
            తిరిగి;
    }

    parse_నిర్వాహ్యం(s1, &op1);
    ఒకవేళ (tok == ',') తదుపరి();
    parse_నిర్వాహ్యం(s1, &op2);

    ఒకవేళ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        తిరిగి;
    }
    ఒకవేళ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        తిరిగి;
    }

    rd = op1.reg;
    rn = op2.reg;

    ఒకవేళ (tok == ',') {
        తదుపరి();
        parse_నిర్వాహ్యం(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ఒకవేళ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            తిరిగి;
        }
        ఒకవేళ (op3.type & OP_REG) {
            ఒకవేళ (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                తిరిగి;
            }
            gen_జరుపు(rd, rn, op3.reg, జరుపు_type, 0, is_64bit);
        } లేకపోతే ఒకవేళ (op3.type & OP_IM) {
            జరుపు_amount = op3.e.v;
            gen_జరుపు(rd, rn, జరుపు_amount, జరుపు_type, 1, is_64bit);
        } లేకపోతే {
            tcc_error("shift requires immediate or register operand");
        }
    } లేకపోతే {
        tcc_error("shift requires immediate or register operand");
        తిరిగి;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
స్థిర శూన్య gen_barrier(పూర్ణాంకం barrier_type, పూర్ణాంకం option)
{
    uint32_t instr;

    ఎంపిక (barrier_type) {
        స్థితి 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            ఆపు;
        స్థితి 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            ఆపు;
        స్థితి 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            ఆపు;
        అప్రమేయ:
            tcc_error("unknown barrier type");
            తిరిగి;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
స్థిర శూన్య asm_barrier(TCCState *s1, పూర్ణాంకం token)
{
    పూర్ణాంకం barrier_type, option;
    నిర్వాహ్యం op;

    ఎంపిక (token) {
        స్థితి TOK_ASM_isb:
            barrier_type = 0;
            ఆపు;
        స్థితి TOK_ASM_dsb:
            barrier_type = 1;
            ఆపు;
        స్థితి TOK_ASM_dmb:
            barrier_type = 2;
            ఆపు;
        అప్రమేయ:
            tcc_error("unknown barrier instruction");
            తిరిగి;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    ఒకవేళ (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        ఒకవేళ (option >= 0) {
            తదుపరి();
        } లేకపోతే {
            parse_నిర్వాహ్యం(s1, &op);
            ఒకవేళ (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                తిరిగి;
            }
            ఒకవేళ (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                తిరిగి;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
స్థిర శూన్య gen_mov_imm(పూర్ణాంకం rd, uint64_t imm, పూర్ణాంకం is_64bit)
{
    uint16_t hw;
    పూర్ణాంకం i, మొదటి = 1;

    కొరకు (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        ఒకవేళ (hw != 0 || i == 0) {
            ఒకవేళ (మొదటి) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                మొదటి = 0;
            } లేకపోతే {
                gen_movk(rd, hw, i, is_64bit);
            }
        } లేకపోతే ఒకవేళ (!మొదటి) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
స్థిర శూన్య asm_mov(TCCState *s1)
{
    నిర్వాహ్యం op1, op2;
    పూర్ణాంకం rd, rn;
    పూర్ణాంకం is_64bit;

    parse_నిర్వాహ్యం(s1, &op1);
    ఒకవేళ (tok == ',') తదుపరి();
    parse_నిర్వాహ్యం(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    ఒకవేళ (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        ఒకవేళ (నిర్వాహ్యం_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            తిరిగి;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } లేకపోతే ఒకవేళ (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        ఒకవేళ (నిర్వాహ్యం_is_sp(&op1) || నిర్వాహ్యం_is_sp(&op2))
            gen_కూడు_imm(rd, rn, 0, 1, 0);
        లేకపోతే
            gen_mov_reg(rd, rn, is_64bit);
    } లేకపోతే {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
స్థిర శూన్య asm_దత్తాంశం_proc(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం op1, op2, op3;
    పూర్ణాంకం rd, rn, rm;
    పూర్ణాంకం is_64bit = 1;
    uint32_t opcode;

    ఎంపిక (token) {
        స్థితి TOK_ASM_కూడు:
        స్థితి TOK_ASM_adds:
            opcode = token == TOK_ASM_కూడు ? ARM64_కూడు_REG : ARM64_ADDS_REG;
            ఆపు;
        స్థితి TOK_ASM_sub:
        స్థితి TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            ఆపు;
        స్థితి TOK_ASM_and:
        స్థితి TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            ఆపు;
        స్థితి TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            ఆపు;
        స్థితి TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            ఆపు;
        స్థితి TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            ఆపు;
        అప్రమేయ:
            tcc_error("unsupported data processing instruction");
            తిరిగి;
    }

    parse_నిర్వాహ్యం(s1, &op1);
    ఒకవేళ (tok == ',') తదుపరి();
    parse_నిర్వాహ్యం(s1, &op2);

    ఒకవేళ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        తిరిగి;
    }
    ఒకవేళ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        తిరిగి;
    }

    rd = op1.reg;
    rn = op2.reg;

    ఒకవేళ (tok == ',') {
        తదుపరి();
        parse_నిర్వాహ్యం(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        ఒకవేళ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            తిరిగి;
        }
        ఒకవేళ (op3.type & OP_IM) {
            ఒకవేళ (token == TOK_ASM_కూడు || token == TOK_ASM_adds)
                gen_కూడు_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            లేకపోతే ఒకవేళ (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            లేకపోతే ఒకవేళ (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            లేకపోతే ఒకవేళ (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            లేకపోతే ఒకవేళ (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_పునాది, rd, rn, op3.e.v, is_64bit);
            లేకపోతే ఒకవేళ (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            లేకపోతే
                tcc_error("immediate operand not valid for this instruction");
        } లేకపోతే {
            ఒకవేళ (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                తిరిగి;
            }
            rm = op3.reg;
            ఒకవేళ (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                తిరిగి;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } లేకపోతే ఒకవేళ (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } లేకపోతే {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
స్థిర శూన్య asm_ldst(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం op1, op2;
    పూర్ణాంకం rt, rn;
    int32_t స్థానభ్రంశం = 0;
    పూర్ణాంకం కొలత_log2 = 3;
    uint32_t పునాది_opcode;

    parse_నిర్వాహ్యం(s1, &op1);
    ఒకవేళ (tok == ',') తదుపరి();
    parse_నిర్వాహ్యం(s1, &op2);

    ఒకవేళ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        తిరిగి;
    }
    ఒకవేళ (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        తిరిగి;
    }

    rt = op1.reg;
    rn = op2.reg;
    స్థానభ్రంశం = op2.e.v;

    ఎంపిక (token) {
        స్థితి TOK_ASM_ldr:
            ఒకవేళ (op1.reg_type & REG_X) {
                పునాది_opcode = ARM64_LDR_X;
                కొలత_log2 = 3;
            } లేకపోతే ఒకవేళ (op1.reg_type & REG_W) {
                పునాది_opcode = ARM64_LDR_W;
                కొలత_log2 = 2;
            } లేకపోతే ఒకవేళ (op1.reg_type & REG_D) {
                పునాది_opcode = ARM64_LDR_D;
                కొలత_log2 = 3;
            } లేకపోతే {
                tcc_error("ldr requires a w, x, or d register");
                తిరిగి;
            }
            ఆపు;
        స్థితి TOK_ASM_ldrb:
            పునాది_opcode = ARM64_LDR_B;
            కొలత_log2 = 0;
            ఆపు;
        స్థితి TOK_ASM_ldrh:
            పునాది_opcode = ARM64_LDR_H;
            కొలత_log2 = 1;
            ఆపు;
        స్థితి TOK_ASM_str:
            ఒకవేళ (op1.reg_type & REG_X) {
                పునాది_opcode = ARM64_STR_X;
                కొలత_log2 = 3;
            } లేకపోతే ఒకవేళ (op1.reg_type & REG_W) {
                పునాది_opcode = ARM64_STR_W;
                కొలత_log2 = 2;
            } లేకపోతే ఒకవేళ (op1.reg_type & REG_D) {
                పునాది_opcode = ARM64_STR_D;
                కొలత_log2 = 3;
            } లేకపోతే {
                tcc_error("str requires a w, x, or d register");
                తిరిగి;
            }
            ఆపు;
        స్థితి TOK_ASM_strb:
            పునాది_opcode = ARM64_STR_B;
            కొలత_log2 = 0;
            ఆపు;
        స్థితి TOK_ASM_strh:
            పునాది_opcode = ARM64_STR_H;
            కొలత_log2 = 1;
            ఆపు;
        అప్రమేయ:
            tcc_error("unsupported load/store instruction");
            తిరిగి;
    }

    ఒకవేళ (op2.addr_బహుళకం != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(పునాది_opcode, rt, rn, స్థానభ్రంశం, కొలత_log2);
}

స్థిర శూన్య asm_ldst_pair(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం op1, op2, op3;
    uint32_t పునాది_opcode;
    పూర్ణాంకం కొలత_log2 = 3;

    parse_నిర్వాహ్యం(s1, &op1);
    ఒకవేళ (tok == ',')
        తదుపరి();
    parse_నిర్వాహ్యం(s1, &op2);
    ఒకవేళ (tok == ',')
        తదుపరి();
    parse_నిర్వాహ్యం(s1, &op3);

    ఒకవేళ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        తిరిగి;
    }
    ఒకవేళ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        తిరిగి;
    }
    ఒకవేళ (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    ఒకవేళ ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        ఒకవేళ (token == TOK_ASM_stp) {
            పునాది_opcode = op3.addr_బహుళకం == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_బహుళకం == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } లేకపోతే {
            పునాది_opcode = op3.addr_బహుళకం == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_బహుళకం == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } లేకపోతే ఒకవేళ ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        ఒకవేళ (token == TOK_ASM_stp) {
            పునాది_opcode = op3.addr_బహుళకం == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_బహుళకం == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } లేకపోతే {
            పునాది_opcode = op3.addr_బహుళకం == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_బహుళకం == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } లేకపోతే {
        tcc_error("stp/ldp requires matching x or d registers");
        తిరిగి;
    }

    gen_ldst_pair(పునాది_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, కొలత_log2);
}

స్థిర శూన్య asm_sysreg(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం op;
    పూర్ణాంకం sysreg;

    ఒకవేళ (token == TOK_ASM_mrs) {
        parse_నిర్వాహ్యం(s1, &op);
        ఒకవేళ (tok == ',')
            తదుపరి();
        sysreg = parse_sysreg_name(tok);
        ఒకవేళ (sysreg < 0)
            tcc_error("unsupported system register");
        తదుపరి();
        gen_mrs(op.reg, sysreg);
        తిరిగి;
    }

    sysreg = parse_sysreg_name(tok);
    ఒకవేళ (sysreg < 0)
        tcc_error("unsupported system register");
    తదుపరి();
    ఒకవేళ (tok == ',')
        తదుపరి();
    parse_నిర్వాహ్యం(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
స్థిర పూర్ణాంకం get_branch_condition(పూర్ణాంకం branch_token)
{
    పూర్ణాంకం cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    ఎంపిక (branch_token) {
        స్థితి TOK_ASM_beq: cond_token = TOK_ASM_eq; ఆపు;
        స్థితి TOK_ASM_bne: cond_token = TOK_ASM_ne; ఆపు;
        స్థితి TOK_ASM_bcs:
        స్థితి TOK_ASM_bhs: cond_token = TOK_ASM_cs; ఆపు;
        స్థితి TOK_ASM_bcc:
        స్థితి TOK_ASM_blo: cond_token = TOK_ASM_cc; ఆపు;
        స్థితి TOK_ASM_bmi: cond_token = TOK_ASM_mi; ఆపు;
        స్థితి TOK_ASM_bpl: cond_token = TOK_ASM_pl; ఆపు;
        స్థితి TOK_ASM_bvs: cond_token = TOK_ASM_vs; ఆపు;
        స్థితి TOK_ASM_bvc: cond_token = TOK_ASM_vc; ఆపు;
        స్థితి TOK_ASM_bhi: cond_token = TOK_ASM_hi; ఆపు;
        స్థితి TOK_ASM_bls: cond_token = TOK_ASM_ls; ఆపు;
        స్థితి TOK_ASM_bge: cond_token = TOK_ASM_ge; ఆపు;
        స్థితి TOK_ASM_blt: cond_token = TOK_ASM_lt; ఆపు;
        స్థితి TOK_ASM_bgt: cond_token = TOK_ASM_gt; ఆపు;
        స్థితి TOK_ASM_ble: cond_token = TOK_ASM_le; ఆపు;
        అప్రమేయ: తిరిగి -1;
    }

    తిరిగి parse_condition(cond_token);
}

/* Handle branch instructions */
స్థిర శూన్య asm_branch(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం op;
    పూర్ణాంకం cond;
    Sym *sym;
    int32_t స్థానభ్రంశం;

    /* ret can be used without operand */
    ఒకవేళ (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        తిరిగి;
    }

    ఒకవేళ (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_నిర్వాహ్యం(s1, &op);
    లేకపోతే
        parse_సమాసం_నిర్వాహ్యం(s1, &op);

    ఒకవేళ (op.type & OP_IM) {
        sym = op.e.sym;
        ఒకవేళ (sym) {
            /* Symbolic address - emit relocation */
            స్థానభ్రంశం = 0;

            cond = get_branch_condition(token);
            ఒకవేళ (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_పాఠ్యం_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } లేకపోతే {
                ఎంపిక (token) {
                    స్థితి TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_పాఠ్యం_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        ఆపు;
                    స్థితి TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_పాఠ్యం_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        ఆపు;
                    అప్రమేయ:
                        tcc_error("unsupported branch");
                }
            }
        } లేకపోతే {
            స్థానభ్రంశం = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            ఒకవేళ (cond >= 0) {
                gen_b_cond(cond, స్థానభ్రంశం);
            } లేకపోతే {
                ఎంపిక (token) {
                    స్థితి TOK_ASM_b:
                        gen_b(స్థానభ్రంశం);
                        ఆపు;
                    స్థితి TOK_ASM_bl:
                        gen_bl(స్థానభ్రంశం);
                        ఆపు;
                    అప్రమేయ:
                        tcc_error("unsupported branch");
                }
            }
        }
    } లేకపోతే ఒకవేళ (op.type & OP_REG) {
        ఎంపిక (token) {
            స్థితి TOK_ASM_br:
                gen_br(op.reg);
                ఆపు;
            స్థితి TOK_ASM_blr:
                gen_blr(op.reg);
                ఆపు;
            స్థితి TOK_ASM_ret:
                gen_ret(op.reg);
                ఆపు;
            అప్రమేయ:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
స్థిర శూన్య asm_cb(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం op1, op2;
    పూర్ణాంకం rt, is_64bit;
    int32_t స్థానభ్రంశం;
    Sym *sym;

    parse_నిర్వాహ్యం(s1, &op1);
    ఒకవేళ (tok == ',') తదుపరి();
    parse_సమాసం_నిర్వాహ్యం(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    ఒకవేళ (sym) {
        /* Symbolic address - emit relocation */
        స్థానభ్రంశం = 0;
        ఒకవేళ (token == TOK_ASM_cbz) {
            gen_cbz(rt, స్థానభ్రంశం, is_64bit);
            greloca(cur_పాఠ్యం_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } లేకపోతే {
            gen_cbnz(rt, స్థానభ్రంశం, is_64bit);
            greloca(cur_పాఠ్యం_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } లేకపోతే {
        స్థానభ్రంశం = (int32_t)op2.e.v - ind;
        ఒకవేళ (token == TOK_ASM_cbz)
            gen_cbz(rt, స్థానభ్రంశం, is_64bit);
        లేకపోతే
            gen_cbnz(rt, స్థానభ్రంశం, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
స్థిర శూన్య asm_move_wide(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం op1, op2;
    పూర్ణాంకం rd, is_64bit = 1;
    uint16_t imm;
    పూర్ణాంకం జరుపు = 0;

    parse_నిర్వాహ్యం(s1, &op1);
    ఒకవేళ (tok == ',') తదుపరి();
    parse_నిర్వాహ్యం(s1, &op2);

    ఒకవేళ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        తిరిగి;
    }
    ఒకవేళ (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        తిరిగి;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    ఒకవేళ ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        తిరిగి;
    }
    imm = op2.e.v;

    ఒకవేళ (tok == ',') {
        తదుపరి();
        ఒకవేళ (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            తిరిగి;
        }
            తదుపరి();
            ఒకవేళ (tok == '#') తదుపరి();
            asm_సమాసం(s1, &op2.e);
        ఒకవేళ (op2.e.sym || !is_valid_movw_జరుపు((పూర్ణాంకం)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            తిరిగి;
        }
            జరుపు = (పూర్ణాంకం)op2.e.v / 16;
        }

    ఎంపిక (token) {
        స్థితి TOK_ASM_movz:
            gen_movz(rd, imm, జరుపు, is_64bit);
            ఆపు;
        స్థితి TOK_ASM_movn:
            gen_movn(rd, imm, జరుపు, is_64bit);
            ఆపు;
        స్థితి TOK_ASM_movk:
            gen_movk(rd, imm, జరుపు, is_64bit);
            ఆపు;
        అప్రమేయ:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC శూన్య asm_opcode(TCCState *s1, పూర్ణాంకం opcode)
{
    ఎంపిక (opcode) {
        స్థితి TOK_ASM_కూడు:
        స్థితి TOK_ASM_adds:
        స్థితి TOK_ASM_sub:
        స్థితి TOK_ASM_subs:
        స్థితి TOK_ASM_and:
        స్థితి TOK_ASM_ands:
        స్థితి TOK_ASM_orr:
        స్థితి TOK_ASM_eor:
        స్థితి TOK_ASM_mul:
            asm_దత్తాంశం_proc(s1, opcode);
            ఆపు;

        స్థితి TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            ఆపు;

        స్థితి TOK_ASM_lsl:
        స్థితి TOK_ASM_lsr:
        స్థితి TOK_ASM_asr:
        స్థితి TOK_ASM_ror:
            asm_జరుపు(s1, opcode);
            ఆపు;

        స్థితి TOK_ASM_ldr:
        స్థితి TOK_ASM_ldrb:
        స్థితి TOK_ASM_ldrh:
        స్థితి TOK_ASM_str:
        స్థితి TOK_ASM_strb:
        స్థితి TOK_ASM_strh:
            asm_ldst(s1, opcode);
            ఆపు;

        స్థితి TOK_ASM_ldp:
        స్థితి TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            ఆపు;

        స్థితి TOK_ASM_b:
        స్థితి TOK_ASM_bl:
        స్థితి TOK_ASM_br:
        స్థితి TOK_ASM_blr:
        స్థితి TOK_ASM_ret:
        స్థితి TOK_ASM_beq:
        స్థితి TOK_ASM_bne:
        స్థితి TOK_ASM_bcs:
        స్థితి TOK_ASM_bhs:
        స్థితి TOK_ASM_bcc:
        స్థితి TOK_ASM_blo:
        స్థితి TOK_ASM_bmi:
        స్థితి TOK_ASM_bpl:
        స్థితి TOK_ASM_bvs:
        స్థితి TOK_ASM_bvc:
        స్థితి TOK_ASM_bhi:
        స్థితి TOK_ASM_bls:
        స్థితి TOK_ASM_bge:
        స్థితి TOK_ASM_blt:
        స్థితి TOK_ASM_bgt:
        స్థితి TOK_ASM_ble:
            asm_branch(s1, opcode);
            ఆపు;

        స్థితి TOK_ASM_cbz:
        స్థితి TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            ఆపు;

        స్థితి TOK_ASM_movz:
        స్థితి TOK_ASM_movn:
        స్థితి TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            ఆపు;

        స్థితి TOK_ASM_mrs:
        స్థితి TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            ఆపు;

        స్థితి TOK_ASM_isb:
        స్థితి TOK_ASM_dsb:
        స్థితి TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            ఆపు;

        స్థితి TOK_ASM_nop:
            gen_nop();
            ఆపు;

        అప్రమేయ:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, ఖాళీ));
            ఆపు;
    }
}

/* Substitute assembler operand */
ST_FUNC శూన్య subst_asm_నిర్వాహ్యం(CString *కూడు_str, SValue *sv, పూర్ణాంకం modifier)
{
    పూర్ణాంకం r, reg, కొలత, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    ఒకవేళ ((r & VT_VALMASK) == VT_CONST) {
        ఒకవేళ ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(కూడు_str, modifier == 'w' ? "wzr" : "xzr", -1);
            తిరిగి;
        }
        ఒకవేళ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(కూడు_str, '#');
        ఒకవేళ (r & VT_SYM) {
            స్థిరరాశి అక్షరం *name = get_tok_str(sv->sym->v, ఖాళీ);
            ఒకవేళ (sv->sym->v >= SYM_మొదటి_ANOM)
                get_asm_sym(tok_alloc(name, అక్షరశ్రేణి_పొడవు(name))->tok, sv->sym);
            ఒకవేళ (tcc_state->leading_underscore)
                cstr_ccat(కూడు_str, '_');
            cstr_cat(కూడు_str, name, -1);
            ఒకవేళ ((uint32_t) sv->c.i == 0)
                వెళ్ళు no_స్థానభ్రంశం;
            cstr_ccat(కూడు_str, '+');
        }
        uval = sv->c.i;
        ఒకవేళ (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(కూడు_str, "%lld", (దీర్ఘ దీర్ఘ)val);
        } లేకపోతే ఒకవేళ (uval > 0x7fffffffffffffffULL) {
            cstr_printf(కూడు_str, "0x%llx", (గుర్తులేని దీర్ఘ దీర్ఘ)uval);
        } లేకపోతే {
            val = (int64_t)uval;
            cstr_printf(కూడు_str, "%lld", (దీర్ఘ దీర్ఘ)val);
        }
      no_స్థానభ్రంశం:;
    } లేకపోతే ఒకవేళ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(కూడు_str, "[x29,#%d]", (పూర్ణాంకం) sv->c.i);
    } లేకపోతే ఒకవేళ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ఒకవేళ (reg >= VT_CONST)
            tcc_అంతర్గత_error("");
        cstr_printf(కూడు_str, "[x%d]", reg);
    } లేకపోతే {
        /* register case */
        reg = r & VT_VALMASK;
        ఒకవేళ (reg >= VT_CONST)
            tcc_అంతర్గత_error("");

        ఒకవేళ (ARM64_FREG_పునాది <= reg && reg <= ARM64_FREG_చివరి) {
            fp_reg = reg - ARM64_FREG_పునాది;
            కొలత = type_కొలత(&sv->type, &align);

            ఒకవేళ (modifier == 0)
                modifier = కొలత <= 4 ? 's'
                         : కొలత == 8 ? 'd'
                         : 'q';

            ఎంపిక (modifier) {
            స్థితి 'b':
            స్థితి 'h':
            స్థితి 's':
            స్థితి 'd':
            స్థితి 'q':
            స్థితి 'Z':
                cstr_printf(కూడు_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                తిరిగి;
            అప్రమేయ:
                tcc_error("invalid operand modifier for SIMD/FP register");
                తిరిగి;
            }
        }

        /* choose register operand size */
        ఒకవేళ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            కొలత = 1;
        లేకపోతే ఒకవేళ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            కొలత = 2;
        లేకపోతే ఒకవేళ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            కొలత = 8;
        లేకపోతే
            కొలత = 4;

        ఒకవేళ (modifier == 'x') {
            కొలత = 8;
        } లేకపోతే ఒకవేళ (modifier == 'w' || modifier == 'k') {
            కొలత = 4;
        } లేకపోతే ఒకవేళ (modifier == 'b') {
            కొలత = 1;
        } లేకపోతే ఒకవేళ (modifier == 'h') {
            కొలత = 2;
        } లేకపోతే ఒకవేళ (modifier == 'q') {
            కొలత = 8;
        }

        ఒకవేళ (కొలత <= 4) {
            cstr_printf(కూడు_str, "w%d", reg);
        } లేకపోతే {
            cstr_printf(కూడు_str, "x%d", reg);
        }
    }
}

ST_FUNC శూన్య asm_gen_సంకేతం(ASMOperand *operands, పూర్ణాంకం nb_operands,
                          పూర్ణాంకం nb_outputs, పూర్ణాంకం is_output,
                          uint8_t *clobber_regs,
                          పూర్ణాంకం బహిర్గతం_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    పూర్ణాంకం i, reg, saved_లెక్క, దొంతర_కొలత, దొంతర_off;
    పూర్ణాంకం saved_regs[12];
    స్థిర స్థిరరాశి uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    జ్ఞాపకం_నకలు(regs_allocated, clobber_regs, పరిమాణం(regs_allocated));
    కొరకు (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ఒకవేళ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_లెక్క = 0;
    కొరకు (i = 0; i < పరిమాణం(reg_saved) / పరిమాణం(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ఒకవేళ (regs_allocated[reg])
            saved_regs[saved_లెక్క++] = reg;
    }
    దొంతర_కొలత = ((saved_లెక్క + 1) / 2) * 16;

    ఒకవేళ (!is_output) {
        ఒకవేళ (saved_లెక్క > 0) {
            gen_sub_imm(31, 31, దొంతర_కొలత, 1, 0);

            కొరకు (i = దొంతర_off = 0; i < saved_లెక్క; ) {
                ఒకవేళ (i + 1 < saved_లెక్క) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, దొంతర_off, 3);
                    దొంతర_off += 16;
                    i += 2;
                } లేకపోతే {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 దొంతర_off, 3);
                    i++;
                }
            }
        }

        కొరకు (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ఒకవేళ (op->reg >= 0) {
                ఒకవేళ (op->is_జ్ఞాపకం) {
                    arm64_ఎక్కించు_జ్ఞాపకం_నిర్వాహ్యం_పునాది(op->reg, op->vt);
                } లేకపోతే ఒకవేళ (i >= nb_outputs || op->is_rw) {
                    ఎక్కించు(op->reg, op->vt);
                }
            }
        }
    } లేకపోతే {
        కొరకు (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            ఒకవేళ (op->reg >= 0) {
                ఒకవేళ (op->is_జ్ఞాపకం)
                    కొనసాగు;
                ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ఒకవేళ (!op->is_జ్ఞాపకం) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        ఎక్కించు(బహిర్గతం_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | బహిర్గతం_reg;
                        store(op->reg, &sv);
                    }
                } లేకపోతే {
                    store(op->reg, op->vt);
                }
            }
        }

        ఒకవేళ (saved_లెక్క > 0) {
            కొరకు (i = దొంతర_off = 0; i < saved_లెక్క; ) {
                ఒకవేళ (i + 1 < saved_లెక్క) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, దొంతర_off, 3);
                    దొంతర_off += 16;
                    i += 2;
                } లేకపోతే {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 దొంతర_off, 3);
                    i++;
                }
            }
            gen_కూడు_imm(31, 31, దొంతర_కొలత, 1, 0);
        }
    }
}

ST_FUNC శూన్య asm_compute_constraints(ASMOperand *operands,
                                    పూర్ణాంకం nb_operands, పూర్ణాంకం nb_outputs,
                                    స్థిరరాశి uint8_t *clobber_regs,
                                    పూర్ణాంకం *pout_reg)
{
    ASMOperand *op;
    పూర్ణాంకం sorted_op[MAX_ASM_OPERANDS];
    పూర్ణాంకం i, j, k, p1, p2, tmp, reg, c, reg_ముసుగు;
    స్థిరరాశి అక్షరం *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    కొరకు (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ఆదానం_సూచీ = -1;
        op->ref_సూచీ = -1;
        op->reg = -1;
        op->is_జ్ఞాపకం = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    కొరకు (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ఒకవేళ (isnum(*str) || *str == '[') {
            k = కనుగొను_constraint(operands, nb_operands, str, ఖాళీ);
            ఒకవేళ ((గుర్తులేని)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_సూచీ = k;
            ఒకవేళ (operands[k].ఆదానం_సూచీ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ఆదానం_సూచీ = i;
            op->ప్రాధాన్యత = 5;
        } లేకపోతే ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->ప్రాధాన్యత = 1;
            op->reg = reg;
        } లేకపోతే {
            op->ప్రాధాన్యత = constraint_ప్రాధాన్యత(str);
        }
    }

    కొరకు (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    కొరకు (i = 0; i < nb_operands - 1; i++) {
        కొరకు (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].ప్రాధాన్యత;
            p2 = operands[sorted_op[j]].ప్రాధాన్యత;
            ఒకవేళ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    కొరకు (i = 0; i < NB_ASM_REGS; i++) {
        ఒకవేళ (clobber_regs[i])
            regs_allocated[i] = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
        లేకపోతే
            regs_allocated[i] = 0;
    }

    కొరకు (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        ఒకవేళ (op->ref_సూచీ >= 0)
            కొనసాగు;
        ఒకవేళ (op->ఆదానం_సూచీ >= 0) {
            reg_ముసుగు = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
        } లేకపోతే ఒకవేళ (j < nb_outputs) {
            reg_ముసుగు = REG_బహిర్గతం_ముసుగు;
        } లేకపోతే {
            reg_ముసుగు = REG_లోపల_ముసుగు;
        }
        ఒకవేళ (op->reg >= 0) {
            ఒకవేళ (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            వెళ్ళు reg_దొరికింది;
        }
    try_తదుపరి:
        c = *str++;
        ఎంపిక (c) {
        స్థితి '=':
            వెళ్ళు try_తదుపరి;
        స్థితి '+':
            op->is_rw = 1;
        స్థితి '&':
            ఒకవేళ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_ముసుగు = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
            వెళ్ళు try_తదుపరి;
        స్థితి 'r':
            కొరకు (reg = 0; reg < 31; reg++) {
                ఒకవేళ (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    వెళ్ళు reg_దొరికింది;
            }
            వెళ్ళు try_తదుపరి;
        స్థితి 'w':
        స్థితి 'f':
            కొరకు (reg = ARM64_FREG_పునాది; reg <= ARM64_FREG_చివరి; reg++) {
                ఒకవేళ (!is_reg_allocated(reg))
                    వెళ్ళు reg_దొరికింది;
            }
            వెళ్ళు try_తదుపరి;
        స్థితి 'x':
        స్థితి 'y':
            కొరకు (reg = ARM64_FREG_పునాది; reg <= ARM64_FREG_చివరి; reg++) {
                ఒకవేళ (!is_reg_allocated(reg))
                    వెళ్ళు reg_దొరికింది;
            }
            వెళ్ళు try_తదుపరి;
        స్థితి 'm':
        స్థితి 'g':
            ఒకవేళ (j < nb_outputs || c == 'm') {
                ఒకవేళ (!arm64_prepare_జ్ఞాపకం_నిర్వాహ్యం(op, regs_allocated))
                    వెళ్ళు try_తదుపరి;
            }
            ఆపు;
        స్థితి 'Q':
            ఒకవేళ (!arm64_జ్ఞాపకం_is_పునాది_only(op->vt))
                వెళ్ళు try_తదుపరి;
            ఒకవేళ (!arm64_prepare_జ్ఞాపకం_నిర్వాహ్యం(op, regs_allocated))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'S':
            ఒకవేళ ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'U':
            ఒకవేళ (str[0] != 'm' || str[1] != 'p')
                వెళ్ళు try_తదుపరి;
            str += 2;
            ఒకవేళ (!arm64_జ్ఞాపకం_is_pair_suitable(op->vt))
                వెళ్ళు try_తదుపరి;
            ఒకవేళ (!arm64_prepare_జ్ఞాపకం_నిర్వాహ్యం(op, regs_allocated))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'i':
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'I':
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఒకవేళ (!is_valid_కూడు_imm(op->vt->c.i))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'J':
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఒకవేళ (!is_valid_కూడు_imm(-op->vt->c.i))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'K':
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఒకవేళ (!is_valid_logical_imm(op->vt->c.i, 32))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'L':
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఒకవేళ (!is_valid_logical_imm(op->vt->c.i, 64))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'M':
        స్థితి 'N':
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఒకవేళ (!is_valid_movw_imm(op->vt->c.i))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'Z':
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఒకవేళ (op->vt->c.i != 0)
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'n':
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        అప్రమేయ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            ఆపు;
        }
        ఒకవేళ (op->ఆదానం_సూచీ >= 0) {
            operands[op->ఆదానం_సూచీ].reg = op->reg;
            operands[op->ఆదానం_సూచీ].is_llong = op->is_llong;
        }
        కొనసాగు;
    reg_దొరికింది:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_ముసుగు;
        ఒకవేళ (op->ఆదానం_సూచీ >= 0) {
            operands[op->ఆదానం_సూచీ].reg = op->reg;
            operands[op->ఆదానం_సూచీ].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    కొరకు (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ఒకవేళ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_జ్ఞాపకం) {
            కొరకు (reg = 0; reg < 31; reg++) {
                ఒకవేళ (!(regs_allocated[reg] & REG_బహిర్గతం_ముసుగు))
                    వెళ్ళు reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            ఆపు;
        }
    }
}

/* Handle clobber list */
ST_FUNC శూన్య asm_clobber(uint8_t *clobber_regs, స్థిరరాశి అక్షరం *str)
{
    పూర్ణాంకం reg;

    ఒకవేళ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        తిరిగి;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    ఒకవేళ (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC పూర్ణాంకం asm_parse_regvar(పూర్ణాంకం t)
{
    తిరిగి arm64_parse_regvar(t);
}

/*************************************************************/
#అయితే_ముగింపు /* ndef TARGET_DEFS_ONLY */
