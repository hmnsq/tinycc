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

ST_FUNC शून्य g(पूर्णाङ्क c);
ST_FUNC शून्य gen_le16(पूर्णाङ्क c);
ST_FUNC शून्य gen_le32(पूर्णाङ्क c);

/*************************************************************/
#अन्यथा
/*************************************************************/

#define USING_GLOBALS
#अन्तर्भाव "tcc.h"

/* Register type flags */
#define REG_X     0x01  /* 64-bit general purpose */
#define REG_W     0x02  /* 32-bit general purpose */
#define REG_V     0x04  /* 128-bit SIMD */
#define REG_D     0x08  /* 64-bit FP */
#define REG_S     0x10  /* 32-bit FP */
#define REG_H     0x20  /* 16-bit FP */
#define REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
गणना {
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

प्रकारनिर्देश संरचना Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    पूर्णाङ्क reg_tok;
    व्यंजक_मूल्य e;
} Operand;

गणना {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
स्थिर शून्य parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC शून्य g(पूर्णाङ्क c)
{
    पूर्णाङ्क ind1;
    यदि (nocode_wanted)
        प्रत्यागम;
    ind1 = ind + 1;
    यदि (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC शून्य gen_le16(पूर्णाङ्क c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC शून्य gen_le32(पूर्णाङ्क c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC शून्य gen_expr32(व्यंजक_मूल्य *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
स्थिर शून्य emit_instr32(uint32_t val)
{
    यदि (nocode_wanted)
        प्रत्यागम;
    यदि (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
स्थिर पूर्णाङ्क arm64_parse_asm_reg(पूर्णाङ्क t)
{
    /* X registers (64-bit) */
    यदि (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        प्रत्यागम t - TOK_ASM_x0;
    /* W registers (32-bit) */
    यदि (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        प्रत्यागम t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    यदि (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        प्रत्यागम (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    यदि (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        प्रत्यागम (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    यदि (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        प्रत्यागम (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    यदि (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        प्रत्यागम (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    यदि (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        प्रत्यागम (t - TOK_ASM_b0) + 32;
    /* Special registers */
    यदि (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        प्रत्यागम 31;  /* SP/ZR encoded as 31 */
    प्रत्यागम -1;
}

/* Get register type from token */
स्थिर uint8_t get_reg_type(पूर्णाङ्क t)
{
    यदि (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        प्रत्यागम REG_X;
    यदि (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        प्रत्यागम REG_W;
    यदि (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        प्रत्यागम REG_V;
    यदि (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        प्रत्यागम REG_D;
    यदि (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        प्रत्यागम REG_S;
    यदि (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        प्रत्यागम REG_H;
    यदि (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        प्रत्यागम REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    यदि (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        प्रत्यागम REG_X;
    यदि (t == TOK_ASM_wzr)
        प्रत्यागम REG_W;
    प्रत्यागम REG_X;
}

/* Parse condition code */
स्थिर पूर्णाङ्क parse_condition(पूर्णाङ्क t)
{
    विकल्प (t) {
        पक्ष TOK_ASM_eq: प्रत्यागम 0;
        पक्ष TOK_ASM_ne: प्रत्यागम 1;
        पक्ष TOK_ASM_cs:
        पक्ष TOK_ASM_hs: प्रत्यागम 2;
        पक्ष TOK_ASM_cc:
        पक्ष TOK_ASM_lo: प्रत्यागम 3;
        पक्ष TOK_ASM_mi: प्रत्यागम 4;
        पक्ष TOK_ASM_pl: प्रत्यागम 5;
        पक्ष TOK_ASM_vs: प्रत्यागम 6;
        पक्ष TOK_ASM_vc: प्रत्यागम 7;
        पक्ष TOK_ASM_hi: प्रत्यागम 8;
        पक्ष TOK_ASM_ls: प्रत्यागम 9;
        पक्ष TOK_ASM_ge: प्रत्यागम 10;
        पक्ष TOK_ASM_lt: प्रत्यागम 11;
        पक्ष TOK_ASM_gt: प्रत्यागम 12;
        पक्ष TOK_ASM_le: प्रत्यागम 13;
        पक्ष TOK_ASM_al: प्रत्यागम 14;
        स्वभाव: प्रत्यागम -1;
    }
}

स्थिर पूर्णाङ्क parse_barrier_option_name(पूर्णाङ्क t)
{
    ध्रुव वर्ण *name;

    यदि (t < TOK_IDENT)
        प्रत्यागम -1;
    name = get_tok_str(t, रिक्त);
    यदि (!strcmp(name, "oshld")) प्रत्यागम 0x1;
    यदि (!strcmp(name, "oshst")) प्रत्यागम 0x2;
    यदि (!strcmp(name, "osh"))   प्रत्यागम 0x3;
    यदि (!strcmp(name, "nshld")) प्रत्यागम 0x5;
    यदि (!strcmp(name, "nshst")) प्रत्यागम 0x6;
    यदि (!strcmp(name, "nsh"))   प्रत्यागम 0x7;
    यदि (!strcmp(name, "ishld")) प्रत्यागम 0x9;
    यदि (!strcmp(name, "ishst")) प्रत्यागम 0xA;
    यदि (!strcmp(name, "ish"))   प्रत्यागम 0xB;
    यदि (!strcmp(name, "ld"))    प्रत्यागम 0xD;
    यदि (!strcmp(name, "st"))    प्रत्यागम 0xE;
    यदि (!strcmp(name, "sy"))    प्रत्यागम 0xF;
    प्रत्यागम -1;
}

स्थिर पूर्णाङ्क arm64_parse_regvar(पूर्णाङ्क t)
{
    यदि (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        प्रत्यागम t - TOK_ASM_x0;
    यदि (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        प्रत्यागम ARM64_FREG_BASE + (t - TOK_ASM_v0);
    यदि (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        प्रत्यागम ARM64_FREG_BASE + (t - TOK_ASM_d0);
    यदि (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        प्रत्यागम ARM64_FREG_BASE + (t - TOK_ASM_s0);
    यदि (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        प्रत्यागम ARM64_FREG_BASE + (t - TOK_ASM_h0);
    यदि (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        प्रत्यागम ARM64_FREG_BASE + (t - TOK_ASM_b0);
    प्रत्यागम -1;
}

/* Parse a single operand */
स्थिर शून्य parse_operand(TCCState *s1, Operand *op)
{
    पूर्णाङ्क reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    यदि (tok == '[') {
        parse_addr_operand(s1, op);
        प्रत्यागम;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    यदि (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        प्रत्यागम;
    }

    /* Condition code */
    reg = parse_condition(tok);
    यदि (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        प्रत्यागम;
    }

    /* Immediate or address expression */
    यदि (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_व्यंजक(s1, &op->e);
        op->type = OP_IM;
    } अन्यथा यदि (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } अन्यथा {
        asm_व्यंजक(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
स्थिर शून्य parse_व्यंजक_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    यदि (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_व्यंजक(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
स्थिर शून्य parse_addr_operand(TCCState *s1, Operand *op)
{
    पूर्णाङ्क reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = रिक्त;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    यदि (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        प्रत्यागम;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    यदि (tok == ',') {
        next();
        यदि (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_व्यंजक(s1, &op->e);
    }
    skip(']');
    यदि (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } अन्यथा यदि (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        यदि (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_व्यंजक(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
स्थिर शून्य gen_mov_with_base(पूर्णाङ्क rd, uint16_t imm, पूर्णाङ्क shift,
                              पूर्णाङ्क is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    यदि (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

स्थिर शून्य gen_movz(पूर्णाङ्क rd, uint16_t imm, पूर्णाङ्क shift, पूर्णाङ्क is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
स्थिर शून्य gen_movn(पूर्णाङ्क rd, uint16_t imm, पूर्णाङ्क shift, पूर्णाङ्क is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
स्थिर शून्य gen_movk(पूर्णाङ्क rd, uint16_t imm, पूर्णाङ्क shift, पूर्णाङ्क is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
स्थिर शून्य gen_add_imm(पूर्णाङ्क rd, पूर्णाङ्क rn, uint32_t imm, पूर्णाङ्क is_64bit, पूर्णाङ्क setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    यदि (is_64bit) instr |= ARM64_SF(1);
    यदि (setflags) instr |= ARM64_S(1);

    यदि (imm <= 0xFFF) {
        imm12 = imm;
    } अन्यथा यदि (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } अन्यथा {
        tcc_error("add immediate out of range");
        प्रत्यागम;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
स्थिर शून्य gen_sub_imm(पूर्णाङ्क rd, पूर्णाङ्क rn, uint32_t imm, पूर्णाङ्क is_64bit, पूर्णाङ्क setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    यदि (is_64bit) instr |= ARM64_SF(1);
    यदि (setflags) instr |= ARM64_S(1);

    यदि (imm <= 0xFFF) {
        imm12 = imm;
    } अन्यथा यदि (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } अन्यथा {
        tcc_error("sub immediate out of range");
        प्रत्यागम;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
स्थिर शून्य gen_dp_reg(uint32_t opcode, पूर्णाङ्क rd, पूर्णाङ्क rn, पूर्णाङ्क rm, पूर्णाङ्क is_64bit)
{
    uint32_t instr = opcode;
    यदि (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
स्थिर शून्य gen_ldst_imm(uint32_t base_opcode, पूर्णाङ्क rt, पूर्णाङ्क rn,
                         int32_t offset, पूर्णाङ्क size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    यदि (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        यदि (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            प्रत्यागम;
        }
    }

    विकल्प (base_opcode) {
    पक्ष ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; भङ्ग;
    पक्ष ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; भङ्ग;
    पक्ष ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; भङ्ग;
    पक्ष ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; भङ्ग;
    पक्ष ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; भङ्ग;
    पक्ष ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; भङ्ग;
    पक्ष ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; भङ्ग;
    पक्ष ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; भङ्ग;
    पक्ष ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; भङ्ग;
    पक्ष ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; भङ्ग;
    }

    यदि (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        प्रत्यागम;
    }

    यदि (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
स्थिर शून्य gen_ldst_pair(uint32_t base_opcode, पूर्णाङ्क rt, पूर्णाङ्क rt2, पूर्णाङ्क rn,
                          int32_t offset, पूर्णाङ्क size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    यदि (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    यदि (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
स्थिर शून्य gen_b_or_bl(int32_t offset, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    instr |= ARM64_OFFSET26(offset);
    emit_instr32(instr);
}

स्थिर शून्य gen_b(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_B);
}

/* Generate BL (branch with link) */
स्थिर शून्य gen_bl(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_BL);
}

/* Generate BR (branch to register) */
स्थिर शून्य gen_br(पूर्णाङ्क rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
स्थिर शून्य gen_blr(पूर्णाङ्क rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
स्थिर शून्य gen_ret(पूर्णाङ्क rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
स्थिर शून्य gen_b_cond(पूर्णाङ्क cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
स्थिर शून्य gen_cbz_or_cbnz(पूर्णाङ्क rt, int32_t offset, पूर्णाङ्क is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    यदि (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

स्थिर शून्य gen_cbz(पूर्णाङ्क rt, int32_t offset, पूर्णाङ्क is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
स्थिर शून्य gen_cbnz(पूर्णाङ्क rt, int32_t offset, पूर्णाङ्क is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
स्थिर शून्य gen_mov_reg(पूर्णाङ्क rd, पूर्णाङ्क rm, पूर्णाङ्क is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    यदि (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

स्थिर पूर्णाङ्क arm64_asm_encode_bimm64(uint64_t x)
{
    पूर्णाङ्क neg, rep, pos, len;

    neg = x & 1;
    यदि (neg)
        x = ~x;
    यदि (!x)
        प्रत्यागम -1;

    यदि (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    अन्यथा यदि (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    अन्यथा यदि (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    अन्यथा यदि (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    अन्यथा यदि (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    अन्यथा
        rep = 64;

    pos = 0;
    यदि (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    यदि (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    यदि (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    यदि (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    यदि (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    यदि (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    यदि (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    यदि (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    यदि (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    यदि (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    यदि (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    यदि (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    यदि (x)
        प्रत्यागम -1;
    यदि (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    प्रत्यागम ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

स्थिर शून्य gen_logical_imm(uint32_t opcode, पूर्णाङ्क rd, पूर्णाङ्क rn,
                            uint64_t imm, पूर्णाङ्क is_64bit)
{
    uint32_t instr;
    uint64_t val;
    पूर्णाङ्क enc;

    यदि (is_64bit)
        val = imm;
    अन्यथा {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    यदि (enc < 0) {
        tcc_error("logical immediate out of range");
        प्रत्यागम;
    }

    instr = opcode;
    यदि (is_64bit)
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
स्थिर अन्तःस्थ पूर्णाङ्क constraint_priority(ध्रुव वर्ण *str)
{
    पूर्णाङ्क priority, c, pr;

    priority = 0;
    प्रति (;;) {
        c = *str++;
        यदि (c == '\0')
            भङ्ग;
        विकल्प (c) {
        पक्ष '=':
        पक्ष '+':
        पक्ष '&':
            अनुवर्त;
        पक्ष 'r':
            pr = 1;
            भङ्ग;
        पक्ष 'w':
        पक्ष 'f':
        पक्ष 'x':
        पक्ष 'y':
            pr = 3;
            भङ्ग;
        पक्ष 'm':
        पक्ष 'Q':
            pr = 4;
            भङ्ग;
        पक्ष 'i':
        पक्ष 'S':
            pr = 5;
            भङ्ग;
        पक्ष 'U':
            यदि (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                भङ्ग;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            भङ्ग;
        पक्ष 'I':
        पक्ष 'J':
        पक्ष 'K':
        पक्ष 'L':
        पक्ष 'M':
        पक्ष 'N':
        पक्ष 'Z':
            pr = 6;
            भङ्ग;
        पक्ष 'n':
            pr = 7;
            भङ्ग;
        पक्ष 'g':
            pr = 8;
            भङ्ग;
        स्वभाव:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            भङ्ग;
        }
        यदि (pr > priority)
            priority = pr;
    }
    प्रत्यागम priority;
}

स्थिर ध्रुव वर्ण *skip_constraint_modifiers(ध्रुव वर्ण *p)
{
    यावत् (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    प्रत्यागम p;
}

स्थिर पूर्णाङ्क is_valid_add_imm(int64_t val)
{
    प्रत्यागम val >= 0 && val <= 4095;
}

स्थिर पूर्णाङ्क is_valid_logical_imm(int64_t val, पूर्णाङ्क bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    यदि (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    प्रत्यागम arm64_asm_encode_bimm64(uval) >= 0;
}

स्थिर पूर्णाङ्क is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    यदि (uval <= 0xFFFF)
        प्रत्यागम 1;
    यदि (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        प्रत्यागम 1;
    यदि (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        प्रत्यागम 1;
    यदि ((uval & 0xFFFFFFFF00000000ULL) == 0)
        प्रत्यागम 1;

    प्रत्यागम 0;
}

स्थिर पूर्णाङ्क is_valid_movw_shift(पूर्णाङ्क shift, पूर्णाङ्क is_64bit)
{
    यदि (shift < 0 || (shift & 15))
        प्रत्यागम 0;
    यदि (shift > (is_64bit ? 48 : 16))
        प्रत्यागम 0;
    प्रत्यागम 1;
}

स्थिर पूर्णाङ्क arm64_memory_is_base_only(ध्रुव SValue *sv)
{
    पूर्णाङ्क r;

    r = sv->r;
    यदि ((r & VT_VALMASK) == VT_CONST)
        प्रत्यागम 0;
    यदि ((r & VT_VALMASK) == VT_LOCAL)
        प्रत्यागम 0;
    यदि ((r & VT_VALMASK) == VT_LLOCAL)
        प्रत्यागम 1;
    यदि (r & VT_LVAL)
        प्रत्यागम (r & VT_VALMASK) < VT_CONST;
    प्रत्यागम 0;
}

स्थिर पूर्णाङ्क arm64_memory_is_pair_suitable(ध्रुव SValue *sv)
{
    int64_t offset;

    यदि (arm64_memory_is_base_only(sv))
        प्रत्यागम 1;
    यदि ((sv->r & VT_VALMASK) != VT_LOCAL)
        प्रत्यागम 0;

    offset = (int64_t)sv->c.i;
    प्रत्यागम (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

स्थिर पूर्णाङ्क arm64_int_reg_is_allocatable(पूर्णाङ्क reg)
{
#ifdef TCC_TARGET_PE
    प्रत्यागम reg >= TREG_X0 && reg <= TREG_X17;
#अन्यथा
    प्रत्यागम reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

स्थिर पूर्णाङ्क arm64_memory_needs_address_reg(ध्रुव SValue *sv)
{
    पूर्णाङ्क r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    यदि (!(r & VT_LVAL))
        प्रत्यागम 0;
    विकल्प (r & VT_VALMASK) {
    पक्ष VT_LOCAL:
    पक्ष VT_LLOCAL:
    पक्ष VT_CONST:
        प्रत्यागम 1;
    }
    प्रत्यागम 0;
}

स्थिर पूर्णाङ्क arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    पूर्णाङ्क reg;

    यदि (!arm64_memory_needs_address_reg(op->vt))
        प्रत्यागम 1;

    प्रति (reg = 0; reg < 31; reg++) {
        यदि (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            प्रत्यागम 1;
        }
    }
    प्रत्यागम 0;
}

स्थिर शून्य arm64_load_memory_operand_base(पूर्णाङ्क reg, SValue *sv)
{
    SValue base;
    पूर्णाङ्क rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    यदि (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } अन्यथा यदि (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } अन्यथा {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

स्थिर पूर्णाङ्क operand_is_sp(ध्रुव Operand *op)
{
    प्रत्यागम op->reg_tok == TOK_ASM_sp;
}

स्थिर पूर्णाङ्क parse_sysreg_name(पूर्णाङ्क t)
{
    ध्रुव वर्ण *name;

    यदि (t < TOK_IDENT)
        प्रत्यागम -1;
    name = get_tok_str(t, रिक्त);
    यदि (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        प्रत्यागम 0;
    यदि (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        प्रत्यागम 1;
    प्रत्यागम -1;
}

स्थिर शून्य gen_mrs(पूर्णाङ्क rt, पूर्णाङ्क sysreg)
{
    uint32_t instr;

    विकल्प (sysreg) {
        पक्ष 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            भङ्ग;
        पक्ष 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            भङ्ग;
        स्वभाव:
            tcc_error("unsupported system register");
            प्रत्यागम;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

स्थिर शून्य gen_msr(पूर्णाङ्क rt, पूर्णाङ्क sysreg)
{
    uint32_t instr;

    विकल्प (sysreg) {
        पक्ष 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            भङ्ग;
        पक्ष 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            भङ्ग;
        स्वभाव:
            tcc_error("unsupported system register");
            प्रत्यागम;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
स्थिर शून्य gen_nop(शून्य)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
स्थिर शून्य gen_shift(पूर्णाङ्क rd, पूर्णाङ्क rn, पूर्णाङ्क rm_or_imm, पूर्णाङ्क shift_type, पूर्णाङ्क is_imm, पूर्णाङ्क is_64bit)
{
    uint32_t instr;
    पूर्णाङ्क width = is_64bit ? 64 : 32;

    यदि (is_imm) {
        /* Shift by immediate */
        विकल्प (shift_type) {
            पक्ष 0: /* LSL - UBFM alias */
                यदि (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    प्रत्यागम;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                भङ्ग;
            पक्ष 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                यदि (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    प्रत्यागम;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                भङ्ग;
            पक्ष 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                यदि (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    प्रत्यागम;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                भङ्ग;
            पक्ष 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                यदि (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    प्रत्यागम;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                प्रत्यागम;
            स्वभाव:
                tcc_error("unknown shift type");
                प्रत्यागम;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } अन्यथा {
        /* Shift by register */
        विकल्प (shift_type) {
            पक्ष 0: /* LSL */
                instr = ARM64_LSL_REG;
                भङ्ग;
            पक्ष 1: /* LSR */
                instr = ARM64_LSR_REG;
                भङ्ग;
            पक्ष 2: /* ASR */
                instr = ARM64_ASR_REG;
                भङ्ग;
            पक्ष 3: /* ROR */
                instr = ARM64_ROR_REG;
                भङ्ग;
            स्वभाव:
                tcc_error("unknown shift type");
                प्रत्यागम;
        }
        यदि (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
स्थिर शून्य asm_shift(TCCState *s1, पूर्णाङ्क token)
{
    Operand op1, op2, op3;
    पूर्णाङ्क rd, rn, shift_amount;
    पूर्णाङ्क shift_type;
    पूर्णाङ्क is_64bit = 1;

    विकल्प (token) {
        पक्ष TOK_ASM_lsl:
            shift_type = 0;
            भङ्ग;
        पक्ष TOK_ASM_lsr:
            shift_type = 1;
            भङ्ग;
        पक्ष TOK_ASM_asr:
            shift_type = 2;
            भङ्ग;
        पक्ष TOK_ASM_ror:
            shift_type = 3;
            भङ्ग;
        स्वभाव:
            tcc_error("unknown shift instruction");
            प्रत्यागम;
    }

    parse_operand(s1, &op1);
    यदि (tok == ',') next();
    parse_operand(s1, &op2);

    यदि (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        प्रत्यागम;
    }
    यदि (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        प्रत्यागम;
    }

    rd = op1.reg;
    rn = op2.reg;

    यदि (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        यदि (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            प्रत्यागम;
        }
        यदि (op3.type & OP_REG) {
            यदि (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                प्रत्यागम;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } अन्यथा यदि (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } अन्यथा {
            tcc_error("shift requires immediate or register operand");
        }
    } अन्यथा {
        tcc_error("shift requires immediate or register operand");
        प्रत्यागम;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
स्थिर शून्य gen_barrier(पूर्णाङ्क barrier_type, पूर्णाङ्क option)
{
    uint32_t instr;

    विकल्प (barrier_type) {
        पक्ष 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            भङ्ग;
        पक्ष 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            भङ्ग;
        पक्ष 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            भङ्ग;
        स्वभाव:
            tcc_error("unknown barrier type");
            प्रत्यागम;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
स्थिर शून्य asm_barrier(TCCState *s1, पूर्णाङ्क token)
{
    पूर्णाङ्क barrier_type, option;
    Operand op;

    विकल्प (token) {
        पक्ष TOK_ASM_isb:
            barrier_type = 0;
            भङ्ग;
        पक्ष TOK_ASM_dsb:
            barrier_type = 1;
            भङ्ग;
        पक्ष TOK_ASM_dmb:
            barrier_type = 2;
            भङ्ग;
        स्वभाव:
            tcc_error("unknown barrier instruction");
            प्रत्यागम;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    यदि (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        यदि (option >= 0) {
            next();
        } अन्यथा {
            parse_operand(s1, &op);
            यदि (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                प्रत्यागम;
            }
            यदि (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                प्रत्यागम;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
स्थिर शून्य gen_mov_imm(पूर्णाङ्क rd, uint64_t imm, पूर्णाङ्क is_64bit)
{
    uint16_t hw;
    पूर्णाङ्क i, first = 1;

    प्रति (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        यदि (hw != 0 || i == 0) {
            यदि (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } अन्यथा {
                gen_movk(rd, hw, i, is_64bit);
            }
        } अन्यथा यदि (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
स्थिर शून्य asm_mov(TCCState *s1)
{
    Operand op1, op2;
    पूर्णाङ्क rd, rn;
    पूर्णाङ्क is_64bit;

    parse_operand(s1, &op1);
    यदि (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    यदि (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        यदि (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            प्रत्यागम;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } अन्यथा यदि (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        यदि (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        अन्यथा
            gen_mov_reg(rd, rn, is_64bit);
    } अन्यथा {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
स्थिर शून्य asm_data_proc(TCCState *s1, पूर्णाङ्क token)
{
    Operand op1, op2, op3;
    पूर्णाङ्क rd, rn, rm;
    पूर्णाङ्क is_64bit = 1;
    uint32_t opcode;

    विकल्प (token) {
        पक्ष TOK_ASM_add:
        पक्ष TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            भङ्ग;
        पक्ष TOK_ASM_sub:
        पक्ष TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            भङ्ग;
        पक्ष TOK_ASM_and:
        पक्ष TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            भङ्ग;
        पक्ष TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            भङ्ग;
        पक्ष TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            भङ्ग;
        पक्ष TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            भङ्ग;
        स्वभाव:
            tcc_error("unsupported data processing instruction");
            प्रत्यागम;
    }

    parse_operand(s1, &op1);
    यदि (tok == ',') next();
    parse_operand(s1, &op2);

    यदि (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        प्रत्यागम;
    }
    यदि (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        प्रत्यागम;
    }

    rd = op1.reg;
    rn = op2.reg;

    यदि (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        यदि (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            प्रत्यागम;
        }
        यदि (op3.type & OP_IM) {
            यदि (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            अन्यथा यदि (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            अन्यथा यदि (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            अन्यथा यदि (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            अन्यथा यदि (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            अन्यथा यदि (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            अन्यथा
                tcc_error("immediate operand not valid for this instruction");
        } अन्यथा {
            यदि (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                प्रत्यागम;
            }
            rm = op3.reg;
            यदि (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                प्रत्यागम;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } अन्यथा यदि (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } अन्यथा {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
स्थिर शून्य asm_ldst(TCCState *s1, पूर्णाङ्क token)
{
    Operand op1, op2;
    पूर्णाङ्क rt, rn;
    int32_t offset = 0;
    पूर्णाङ्क size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    यदि (tok == ',') next();
    parse_operand(s1, &op2);

    यदि (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        प्रत्यागम;
    }
    यदि (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        प्रत्यागम;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    विकल्प (token) {
        पक्ष TOK_ASM_ldr:
            यदि (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } अन्यथा यदि (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } अन्यथा यदि (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } अन्यथा {
                tcc_error("ldr requires a w, x, or d register");
                प्रत्यागम;
            }
            भङ्ग;
        पक्ष TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            भङ्ग;
        पक्ष TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            भङ्ग;
        पक्ष TOK_ASM_str:
            यदि (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } अन्यथा यदि (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } अन्यथा यदि (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } अन्यथा {
                tcc_error("str requires a w, x, or d register");
                प्रत्यागम;
            }
            भङ्ग;
        पक्ष TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            भङ्ग;
        पक्ष TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            भङ्ग;
        स्वभाव:
            tcc_error("unsupported load/store instruction");
            प्रत्यागम;
    }

    यदि (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

स्थिर शून्य asm_ldst_pair(TCCState *s1, पूर्णाङ्क token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    पूर्णाङ्क size_log2 = 3;

    parse_operand(s1, &op1);
    यदि (tok == ',')
        next();
    parse_operand(s1, &op2);
    यदि (tok == ',')
        next();
    parse_operand(s1, &op3);

    यदि (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        प्रत्यागम;
    }
    यदि (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        प्रत्यागम;
    }
    यदि (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    यदि ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        यदि (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } अन्यथा {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } अन्यथा यदि ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        यदि (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } अन्यथा {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } अन्यथा {
        tcc_error("stp/ldp requires matching x or d registers");
        प्रत्यागम;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

स्थिर शून्य asm_sysreg(TCCState *s1, पूर्णाङ्क token)
{
    Operand op;
    पूर्णाङ्क sysreg;

    यदि (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        यदि (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        यदि (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        प्रत्यागम;
    }

    sysreg = parse_sysreg_name(tok);
    यदि (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    यदि (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
स्थिर पूर्णाङ्क get_branch_condition(पूर्णाङ्क branch_token)
{
    पूर्णाङ्क cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    विकल्प (branch_token) {
        पक्ष TOK_ASM_beq: cond_token = TOK_ASM_eq; भङ्ग;
        पक्ष TOK_ASM_bne: cond_token = TOK_ASM_ne; भङ्ग;
        पक्ष TOK_ASM_bcs:
        पक्ष TOK_ASM_bhs: cond_token = TOK_ASM_cs; भङ्ग;
        पक्ष TOK_ASM_bcc:
        पक्ष TOK_ASM_blo: cond_token = TOK_ASM_cc; भङ्ग;
        पक्ष TOK_ASM_bmi: cond_token = TOK_ASM_mi; भङ्ग;
        पक्ष TOK_ASM_bpl: cond_token = TOK_ASM_pl; भङ्ग;
        पक्ष TOK_ASM_bvs: cond_token = TOK_ASM_vs; भङ्ग;
        पक्ष TOK_ASM_bvc: cond_token = TOK_ASM_vc; भङ्ग;
        पक्ष TOK_ASM_bhi: cond_token = TOK_ASM_hi; भङ्ग;
        पक्ष TOK_ASM_bls: cond_token = TOK_ASM_ls; भङ्ग;
        पक्ष TOK_ASM_bge: cond_token = TOK_ASM_ge; भङ्ग;
        पक्ष TOK_ASM_blt: cond_token = TOK_ASM_lt; भङ्ग;
        पक्ष TOK_ASM_bgt: cond_token = TOK_ASM_gt; भङ्ग;
        पक्ष TOK_ASM_ble: cond_token = TOK_ASM_le; भङ्ग;
        स्वभाव: प्रत्यागम -1;
    }

    प्रत्यागम parse_condition(cond_token);
}

/* Handle branch instructions */
स्थिर शून्य asm_branch(TCCState *s1, पूर्णाङ्क token)
{
    Operand op;
    पूर्णाङ्क cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    यदि (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        प्रत्यागम;
    }

    यदि (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    अन्यथा
        parse_व्यंजक_operand(s1, &op);

    यदि (op.type & OP_IM) {
        sym = op.e.sym;
        यदि (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            यदि (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } अन्यथा {
                विकल्प (token) {
                    पक्ष TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        भङ्ग;
                    पक्ष TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        भङ्ग;
                    स्वभाव:
                        tcc_error("unsupported branch");
                }
            }
        } अन्यथा {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            यदि (cond >= 0) {
                gen_b_cond(cond, offset);
            } अन्यथा {
                विकल्प (token) {
                    पक्ष TOK_ASM_b:
                        gen_b(offset);
                        भङ्ग;
                    पक्ष TOK_ASM_bl:
                        gen_bl(offset);
                        भङ्ग;
                    स्वभाव:
                        tcc_error("unsupported branch");
                }
            }
        }
    } अन्यथा यदि (op.type & OP_REG) {
        विकल्प (token) {
            पक्ष TOK_ASM_br:
                gen_br(op.reg);
                भङ्ग;
            पक्ष TOK_ASM_blr:
                gen_blr(op.reg);
                भङ्ग;
            पक्ष TOK_ASM_ret:
                gen_ret(op.reg);
                भङ्ग;
            स्वभाव:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
स्थिर शून्य asm_cb(TCCState *s1, पूर्णाङ्क token)
{
    Operand op1, op2;
    पूर्णाङ्क rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    यदि (tok == ',') next();
    parse_व्यंजक_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    यदि (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        यदि (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } अन्यथा {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } अन्यथा {
        offset = (int32_t)op2.e.v - ind;
        यदि (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        अन्यथा
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
स्थिर शून्य asm_move_wide(TCCState *s1, पूर्णाङ्क token)
{
    Operand op1, op2;
    पूर्णाङ्क rd, is_64bit = 1;
    uint16_t imm;
    पूर्णाङ्क shift = 0;

    parse_operand(s1, &op1);
    यदि (tok == ',') next();
    parse_operand(s1, &op2);

    यदि (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        प्रत्यागम;
    }
    यदि (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        प्रत्यागम;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    यदि ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        प्रत्यागम;
    }
    imm = op2.e.v;

    यदि (tok == ',') {
        next();
        यदि (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            प्रत्यागम;
        }
            next();
            यदि (tok == '#') next();
            asm_व्यंजक(s1, &op2.e);
        यदि (op2.e.sym || !is_valid_movw_shift((पूर्णाङ्क)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            प्रत्यागम;
        }
            shift = (पूर्णाङ्क)op2.e.v / 16;
        }

    विकल्प (token) {
        पक्ष TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            भङ्ग;
        पक्ष TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            भङ्ग;
        पक्ष TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            भङ्ग;
        स्वभाव:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC शून्य asm_opcode(TCCState *s1, पूर्णाङ्क opcode)
{
    विकल्प (opcode) {
        पक्ष TOK_ASM_add:
        पक्ष TOK_ASM_adds:
        पक्ष TOK_ASM_sub:
        पक्ष TOK_ASM_subs:
        पक्ष TOK_ASM_and:
        पक्ष TOK_ASM_ands:
        पक्ष TOK_ASM_orr:
        पक्ष TOK_ASM_eor:
        पक्ष TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            भङ्ग;

        पक्ष TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            भङ्ग;

        पक्ष TOK_ASM_lsl:
        पक्ष TOK_ASM_lsr:
        पक्ष TOK_ASM_asr:
        पक्ष TOK_ASM_ror:
            asm_shift(s1, opcode);
            भङ्ग;

        पक्ष TOK_ASM_ldr:
        पक्ष TOK_ASM_ldrb:
        पक्ष TOK_ASM_ldrh:
        पक्ष TOK_ASM_str:
        पक्ष TOK_ASM_strb:
        पक्ष TOK_ASM_strh:
            asm_ldst(s1, opcode);
            भङ्ग;

        पक्ष TOK_ASM_ldp:
        पक्ष TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            भङ्ग;

        पक्ष TOK_ASM_b:
        पक्ष TOK_ASM_bl:
        पक्ष TOK_ASM_br:
        पक्ष TOK_ASM_blr:
        पक्ष TOK_ASM_ret:
        पक्ष TOK_ASM_beq:
        पक्ष TOK_ASM_bne:
        पक्ष TOK_ASM_bcs:
        पक्ष TOK_ASM_bhs:
        पक्ष TOK_ASM_bcc:
        पक्ष TOK_ASM_blo:
        पक्ष TOK_ASM_bmi:
        पक्ष TOK_ASM_bpl:
        पक्ष TOK_ASM_bvs:
        पक्ष TOK_ASM_bvc:
        पक्ष TOK_ASM_bhi:
        पक्ष TOK_ASM_bls:
        पक्ष TOK_ASM_bge:
        पक्ष TOK_ASM_blt:
        पक्ष TOK_ASM_bgt:
        पक्ष TOK_ASM_ble:
            asm_branch(s1, opcode);
            भङ्ग;

        पक्ष TOK_ASM_cbz:
        पक्ष TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            भङ्ग;

        पक्ष TOK_ASM_movz:
        पक्ष TOK_ASM_movn:
        पक्ष TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            भङ्ग;

        पक्ष TOK_ASM_mrs:
        पक्ष TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            भङ्ग;

        पक्ष TOK_ASM_isb:
        पक्ष TOK_ASM_dsb:
        पक्ष TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            भङ्ग;

        पक्ष TOK_ASM_nop:
            gen_nop();
            भङ्ग;

        स्वभाव:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, रिक्त));
            भङ्ग;
    }
}

/* Substitute assembler operand */
ST_FUNC शून्य subst_asm_operand(CString *add_str, SValue *sv, पूर्णाङ्क modifier)
{
    पूर्णाङ्क r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    यदि ((r & VT_VALMASK) == VT_CONST) {
        यदि ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            प्रत्यागम;
        }
        यदि (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        यदि (r & VT_SYM) {
            ध्रुव वर्ण *name = get_tok_str(sv->sym->v, रिक्त);
            यदि (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            यदि (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            यदि ((uint32_t) sv->c.i == 0)
                गच्छ no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        यदि (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } अन्यथा यदि (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } अन्यथा {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } अन्यथा यदि ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (पूर्णाङ्क) sv->c.i);
    } अन्यथा यदि (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        यदि (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } अन्यथा {
        /* register case */
        reg = r & VT_VALMASK;
        यदि (reg >= VT_CONST)
            tcc_internal_error("");

        यदि (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            यदि (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            विकल्प (modifier) {
            पक्ष 'b':
            पक्ष 'h':
            पक्ष 's':
            पक्ष 'd':
            पक्ष 'q':
            पक्ष 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                प्रत्यागम;
            स्वभाव:
                tcc_error("invalid operand modifier for SIMD/FP register");
                प्रत्यागम;
            }
        }

        /* choose register operand size */
        यदि ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        अन्यथा यदि ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        अन्यथा यदि ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        अन्यथा
            size = 4;

        यदि (modifier == 'x') {
            size = 8;
        } अन्यथा यदि (modifier == 'w' || modifier == 'k') {
            size = 4;
        } अन्यथा यदि (modifier == 'b') {
            size = 1;
        } अन्यथा यदि (modifier == 'h') {
            size = 2;
        } अन्यथा यदि (modifier == 'q') {
            size = 8;
        }

        यदि (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } अन्यथा {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC शून्य asm_gen_code(ASMOperand *operands, पूर्णाङ्क nb_operands,
                          पूर्णाङ्क nb_outputs, पूर्णाङ्क is_output,
                          uint8_t *clobber_regs,
                          पूर्णाङ्क out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    पूर्णाङ्क i, reg, saved_गिनती, ढेर_size, ढेर_off;
    पूर्णाङ्क saved_regs[12];
    स्थिर ध्रुव uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, परिमाण(regs_allocated));
    प्रति (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        यदि (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_गिनती = 0;
    प्रति (i = 0; i < परिमाण(reg_saved) / परिमाण(reg_saved[0]); i++) {
        reg = reg_saved[i];
        यदि (regs_allocated[reg])
            saved_regs[saved_गिनती++] = reg;
    }
    ढेर_size = ((saved_गिनती + 1) / 2) * 16;

    यदि (!is_output) {
        यदि (saved_गिनती > 0) {
            gen_sub_imm(31, 31, ढेर_size, 1, 0);

            प्रति (i = ढेर_off = 0; i < saved_गिनती; ) {
                यदि (i + 1 < saved_गिनती) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ढेर_off, 3);
                    ढेर_off += 16;
                    i += 2;
                } अन्यथा {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 ढेर_off, 3);
                    i++;
                }
            }
        }

        प्रति (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            यदि (op->reg >= 0) {
                यदि (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } अन्यथा यदि (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } अन्यथा {
        प्रति (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            यदि (op->reg >= 0) {
                यदि (op->is_memory)
                    अनुवर्त;
                यदि ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    यदि (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } अन्यथा {
                    store(op->reg, op->vt);
                }
            }
        }

        यदि (saved_गिनती > 0) {
            प्रति (i = ढेर_off = 0; i < saved_गिनती; ) {
                यदि (i + 1 < saved_गिनती) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ढेर_off, 3);
                    ढेर_off += 16;
                    i += 2;
                } अन्यथा {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 ढेर_off, 3);
                    i++;
                }
            }
            gen_add_imm(31, 31, ढेर_size, 1, 0);
        }
    }
}

ST_FUNC शून्य asm_compute_constraints(ASMOperand *operands,
                                    पूर्णाङ्क nb_operands, पूर्णाङ्क nb_outputs,
                                    ध्रुव uint8_t *clobber_regs,
                                    पूर्णाङ्क *pout_reg)
{
    ASMOperand *op;
    पूर्णाङ्क sorted_op[MAX_ASM_OPERANDS];
    पूर्णाङ्क i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ध्रुव वर्ण *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    प्रति (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->निवेश_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    प्रति (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        यदि (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, रिक्त);
            यदि ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            यदि (operands[k].निवेश_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].निवेश_index = i;
            op->priority = 5;
        } अन्यथा यदि ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } अन्यथा {
            op->priority = constraint_priority(str);
        }
    }

    प्रति (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    प्रति (i = 0; i < nb_operands - 1; i++) {
        प्रति (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            यदि (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    प्रति (i = 0; i < NB_ASM_REGS; i++) {
        यदि (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        अन्यथा
            regs_allocated[i] = 0;
    }

    प्रति (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        यदि (op->ref_index >= 0)
            अनुवर्त;
        यदि (op->निवेश_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अन्यथा यदि (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अन्यथा {
            reg_mask = REG_IN_MASK;
        }
        यदि (op->reg >= 0) {
            यदि (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            गच्छ reg_found;
        }
    try_next:
        c = *str++;
        विकल्प (c) {
        पक्ष '=':
            गच्छ try_next;
        पक्ष '+':
            op->is_rw = 1;
        पक्ष '&':
            यदि (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            गच्छ try_next;
        पक्ष 'r':
            प्रति (reg = 0; reg < 31; reg++) {
                यदि (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    गच्छ reg_found;
            }
            गच्छ try_next;
        पक्ष 'w':
        पक्ष 'f':
            प्रति (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                यदि (!is_reg_allocated(reg))
                    गच्छ reg_found;
            }
            गच्छ try_next;
        पक्ष 'x':
        पक्ष 'y':
            प्रति (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                यदि (!is_reg_allocated(reg))
                    गच्छ reg_found;
            }
            गच्छ try_next;
        पक्ष 'm':
        पक्ष 'g':
            यदि (j < nb_outputs || c == 'm') {
                यदि (!arm64_prepare_memory_operand(op, regs_allocated))
                    गच्छ try_next;
            }
            भङ्ग;
        पक्ष 'Q':
            यदि (!arm64_memory_is_base_only(op->vt))
                गच्छ try_next;
            यदि (!arm64_prepare_memory_operand(op, regs_allocated))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'S':
            यदि ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'U':
            यदि (str[0] != 'm' || str[1] != 'p')
                गच्छ try_next;
            str += 2;
            यदि (!arm64_memory_is_pair_suitable(op->vt))
                गच्छ try_next;
            यदि (!arm64_prepare_memory_operand(op, regs_allocated))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'i':
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'I':
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                गच्छ try_next;
            यदि (!is_valid_add_imm(op->vt->c.i))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'J':
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                गच्छ try_next;
            यदि (!is_valid_add_imm(-op->vt->c.i))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'K':
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                गच्छ try_next;
            यदि (!is_valid_logical_imm(op->vt->c.i, 32))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'L':
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                गच्छ try_next;
            यदि (!is_valid_logical_imm(op->vt->c.i, 64))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'M':
        पक्ष 'N':
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                गच्छ try_next;
            यदि (!is_valid_movw_imm(op->vt->c.i))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'Z':
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                गच्छ try_next;
            यदि (op->vt->c.i != 0)
                गच्छ try_next;
            भङ्ग;
        पक्ष 'n':
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                गच्छ try_next;
            भङ्ग;
        स्वभाव:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            भङ्ग;
        }
        यदि (op->निवेश_index >= 0) {
            operands[op->निवेश_index].reg = op->reg;
            operands[op->निवेश_index].is_llong = op->is_llong;
        }
        अनुवर्त;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        यदि (op->निवेश_index >= 0) {
            operands[op->निवेश_index].reg = op->reg;
            operands[op->निवेश_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    प्रति (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        यदि (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            प्रति (reg = 0; reg < 31; reg++) {
                यदि (!(regs_allocated[reg] & REG_OUT_MASK))
                    गच्छ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            भङ्ग;
        }
    }
}

/* Handle clobber list */
ST_FUNC शून्य asm_clobber(uint8_t *clobber_regs, ध्रुव वर्ण *str)
{
    पूर्णाङ्क reg;

    यदि (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        प्रत्यागम;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    यदि (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC पूर्णाङ्क asm_parse_regvar(पूर्णाङ्क t)
{
    प्रत्यागम arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
