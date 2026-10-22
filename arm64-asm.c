/*************************************************************/
/*
 *  ARM64 (AArch64) assembler for TCC
 *
 *  Based on ARM64 Architecture Reference Manual
 *  Supports AArch64 assembler parsing and extended inline asm
 *  with operands, constraints, and clobbers.
 */

#अगर_घोषित TARGET_DEFS_ONLY

#घोषणा CONFIG_TCC_ASM
/* 32 general purpose + 32 SIMD/FP registers */
#घोषणा NB_ASM_REGS 64

ST_FUNC व्योम g(पूर्णांक c);
ST_FUNC व्योम gen_le16(पूर्णांक c);
ST_FUNC व्योम gen_le32(पूर्णांक c);

/*************************************************************/
#अन्यथा
/*************************************************************/

#घोषणा USING_GLOBALS
#समावेश "tcc.h"

/* Register type flags */
#घोषणा REG_X     0x01  /* 64-bit general purpose */
#घोषणा REG_W     0x02  /* 32-bit general purpose */
#घोषणा REG_V     0x04  /* 128-bit SIMD */
#घोषणा REG_D     0x08  /* 64-bit FP */
#घोषणा REG_S     0x10  /* 32-bit FP */
#घोषणा REG_H     0x20  /* 16-bit FP */
#घोषणा REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
क्रमागत {
    OPT_REG,
    OPT_IM,
    OPT_ADDR,
    OPT_COND,
};

#घोषणा OP_REG     (1 << OPT_REG)
#घोषणा OP_IM      (1 << OPT_IM)
#घोषणा OP_ADDR    (1 << OPT_ADDR)
#घोषणा OP_COND    (1 << OPT_COND)

/* Register allocation masks */
#घोषणा REG_OUT_MASK 0x01
#घोषणा REG_IN_MASK  0x02

#घोषणा is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

/* ARM64 register constants */
#घोषणा TREG_X0  0
#घोषणा TREG_X1  1
#घोषणा TREG_X2  2
#घोषणा TREG_X3  3
#घोषणा TREG_X4  4
#घोषणा TREG_X5  5
#घोषणा TREG_X6  6
#घोषणा TREG_X7  7
#घोषणा TREG_X8  8
#घोषणा TREG_X9  9
#घोषणा TREG_X10 10
#घोषणा TREG_X11 11
#घोषणा TREG_X12 12
#घोषणा TREG_X13 13
#घोषणा TREG_X14 14
#घोषणा TREG_X15 15
#घोषणा TREG_X16 16
#घोषणा TREG_X17 17
#घोषणा TREG_X18 18
#घोषणा TREG_X19 19
#घोषणा TREG_X20 20
#घोषणा TREG_X21 21
#घोषणा TREG_X22 22
#घोषणा TREG_X23 23
#घोषणा TREG_X24 24
#घोषणा TREG_X25 25
#घोषणा TREG_X26 26
#घोषणा TREG_X27 27
#घोषणा TREG_X28 28
#घोषणा TREG_X29 29
#घोषणा TREG_X30 30
#घोषणा TREG_SP  31

#घोषणा ARM64_FREG_BASE 20
#घोषणा ARM64_FREG_LAST (ARM64_FREG_BASE + 7)

प्रकार काष्ठा Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    पूर्णांक reg_tok;
    व्यंजक_मूल्य e;
} Operand;

क्रमागत {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
अटल व्योम parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC व्योम g(पूर्णांक c)
{
    पूर्णांक ind1;
    अगर (nocode_wanted)
        वापस;
    ind1 = ind + 1;
    अगर (ind1 > cur_text_section->तथ्य_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->तथ्य[ind] = c;
    ind = ind1;
}

ST_FUNC व्योम gen_le16(पूर्णांक c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC व्योम gen_le32(पूर्णांक c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC व्योम gen_expr32(व्यंजक_मूल्य *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
अटल व्योम emit_instr32(uint32_t val)
{
    अगर (nocode_wanted)
        वापस;
    अगर (ind + 4 > cur_text_section->तथ्य_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->तथ्य + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
अटल पूर्णांक arm64_parse_asm_reg(पूर्णांक t)
{
    /* X registers (64-bit) */
    अगर (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        वापस t - TOK_ASM_x0;
    /* W registers (32-bit) */
    अगर (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        वापस t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    अगर (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        वापस (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    अगर (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        वापस (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    अगर (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        वापस (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    अगर (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        वापस (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    अगर (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        वापस (t - TOK_ASM_b0) + 32;
    /* Special registers */
    अगर (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        वापस 31;  /* SP/ZR encoded as 31 */
    वापस -1;
}

/* Get register type from token */
अटल uint8_t get_reg_type(पूर्णांक t)
{
    अगर (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        वापस REG_X;
    अगर (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        वापस REG_W;
    अगर (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        वापस REG_V;
    अगर (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        वापस REG_D;
    अगर (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        वापस REG_S;
    अगर (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        वापस REG_H;
    अगर (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        वापस REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    अगर (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        वापस REG_X;
    अगर (t == TOK_ASM_wzr)
        वापस REG_W;
    वापस REG_X;
}

/* Parse condition code */
अटल पूर्णांक parse_condition(पूर्णांक t)
{
    चयन (t) {
        हाल TOK_ASM_eq: वापस 0;
        हाल TOK_ASM_ne: वापस 1;
        हाल TOK_ASM_cs:
        हाल TOK_ASM_hs: वापस 2;
        हाल TOK_ASM_cc:
        हाल TOK_ASM_lo: वापस 3;
        हाल TOK_ASM_mi: वापस 4;
        हाल TOK_ASM_pl: वापस 5;
        हाल TOK_ASM_vs: वापस 6;
        हाल TOK_ASM_vc: वापस 7;
        हाल TOK_ASM_hi: वापस 8;
        हाल TOK_ASM_ls: वापस 9;
        हाल TOK_ASM_ge: वापस 10;
        हाल TOK_ASM_lt: वापस 11;
        हाल TOK_ASM_gt: वापस 12;
        हाल TOK_ASM_le: वापस 13;
        हाल TOK_ASM_al: वापस 14;
        शेष: वापस -1;
    }
}

अटल पूर्णांक parse_barrier_option_name(पूर्णांक t)
{
    स्थिर अक्षर *name;

    अगर (t < TOK_IDENT)
        वापस -1;
    name = get_tok_str(t, शून्य);
    अगर (!म_भेद(name, "oshld")) वापस 0x1;
    अगर (!म_भेद(name, "oshst")) वापस 0x2;
    अगर (!म_भेद(name, "osh"))   वापस 0x3;
    अगर (!म_भेद(name, "nshld")) वापस 0x5;
    अगर (!म_भेद(name, "nshst")) वापस 0x6;
    अगर (!म_भेद(name, "nsh"))   वापस 0x7;
    अगर (!म_भेद(name, "ishld")) वापस 0x9;
    अगर (!म_भेद(name, "ishst")) वापस 0xA;
    अगर (!म_भेद(name, "ish"))   वापस 0xB;
    अगर (!म_भेद(name, "ld"))    वापस 0xD;
    अगर (!म_भेद(name, "st"))    वापस 0xE;
    अगर (!म_भेद(name, "sy"))    वापस 0xF;
    वापस -1;
}

अटल पूर्णांक arm64_parse_regvar(पूर्णांक t)
{
    अगर (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        वापस t - TOK_ASM_x0;
    अगर (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        वापस ARM64_FREG_BASE + (t - TOK_ASM_v0);
    अगर (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        वापस ARM64_FREG_BASE + (t - TOK_ASM_d0);
    अगर (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        वापस ARM64_FREG_BASE + (t - TOK_ASM_s0);
    अगर (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        वापस ARM64_FREG_BASE + (t - TOK_ASM_h0);
    अगर (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        वापस ARM64_FREG_BASE + (t - TOK_ASM_b0);
    वापस -1;
}

/* Parse a single operand */
अटल व्योम parse_operand(TCCState *s1, Operand *op)
{
    पूर्णांक reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    अगर (tok == '[') {
        parse_addr_operand(s1, op);
        वापस;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    अगर (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        अग्र();
        वापस;
    }

    /* Condition code */
    reg = parse_condition(tok);
    अगर (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        अग्र();
        वापस;
    }

    /* Immediate or address expression */
    अगर (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        अग्र();
        asm_व्यंजक(s1, &op->e);
        op->type = OP_IM;
    } अन्यथा अगर (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } अन्यथा {
        asm_व्यंजक(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
अटल व्योम parse_व्यंजक_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    अगर (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        अग्र();
    asm_व्यंजक(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
अटल व्योम parse_addr_operand(TCCState *s1, Operand *op)
{
    पूर्णांक reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = शून्य;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    अगर (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        वापस;
    }
    op->reg = reg;
    op->reg_tok = tok;
    अग्र();
    /* Check for offset */
    अगर (tok == ',') {
        अग्र();
        अगर (tok == '#' || tok == '@' || tok == '$')
            अग्र();
        asm_व्यंजक(s1, &op->e);
    }
    skip(']');
    अगर (tok == '!') {
        op->addr_mode = ADDR_PRE;
        अग्र();
    } अन्यथा अगर (tok == ',') {
        op->addr_mode = ADDR_POST;
        अग्र();
        अगर (tok == '#' || tok == '@' || tok == '$')
            अग्र();
        asm_व्यंजक(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
अटल व्योम gen_mov_with_base(पूर्णांक rd, uint16_t imm, पूर्णांक shift,
                              पूर्णांक is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    अगर (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

अटल व्योम gen_movz(पूर्णांक rd, uint16_t imm, पूर्णांक shift, पूर्णांक is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
अटल व्योम gen_movn(पूर्णांक rd, uint16_t imm, पूर्णांक shift, पूर्णांक is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
अटल व्योम gen_movk(पूर्णांक rd, uint16_t imm, पूर्णांक shift, पूर्णांक is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
अटल व्योम gen_add_imm(पूर्णांक rd, पूर्णांक rn, uint32_t imm, पूर्णांक is_64bit, पूर्णांक setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    अगर (is_64bit) instr |= ARM64_SF(1);
    अगर (setflags) instr |= ARM64_S(1);

    अगर (imm <= 0xFFF) {
        imm12 = imm;
    } अन्यथा अगर (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } अन्यथा {
        tcc_error("add immediate out of range");
        वापस;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
अटल व्योम gen_sub_imm(पूर्णांक rd, पूर्णांक rn, uint32_t imm, पूर्णांक is_64bit, पूर्णांक setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    अगर (is_64bit) instr |= ARM64_SF(1);
    अगर (setflags) instr |= ARM64_S(1);

    अगर (imm <= 0xFFF) {
        imm12 = imm;
    } अन्यथा अगर (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } अन्यथा {
        tcc_error("sub immediate out of range");
        वापस;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
अटल व्योम gen_dp_reg(uint32_t opcode, पूर्णांक rd, पूर्णांक rn, पूर्णांक rm, पूर्णांक is_64bit)
{
    uint32_t instr = opcode;
    अगर (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
अटल व्योम gen_ldst_imm(uint32_t base_opcode, पूर्णांक rt, पूर्णांक rn,
                         int32_t offset, पूर्णांक आकार_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    अगर (offset >= 0 && !(offset & ((1 << आकार_log2) - 1))) {
    imm12 = offset >> आकार_log2;
        अगर (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            वापस;
        }
    }

    चयन (base_opcode) {
    हाल ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; अवरोध;
    हाल ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; अवरोध;
    हाल ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; अवरोध;
    हाल ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; अवरोध;
    हाल ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; अवरोध;
    हाल ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; अवरोध;
    हाल ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; अवरोध;
    हाल ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; अवरोध;
    हाल ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; अवरोध;
    हाल ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; अवरोध;
    }

    अगर (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        वापस;
    }

    अगर (offset & ((1 << आकार_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
अटल व्योम gen_ldst_pair(uint32_t base_opcode, पूर्णांक rt, पूर्णांक rt2, पूर्णांक rn,
                          int32_t offset, पूर्णांक आकार_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    अगर (offset & ((1 << आकार_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> आकार_log2;
    अगर (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
अटल व्योम gen_b_or_bl(int32_t offset, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    instr |= ARM64_OFFSET26(offset);
    emit_instr32(instr);
}

अटल व्योम gen_b(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_B);
}

/* Generate BL (branch with link) */
अटल व्योम gen_bl(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_BL);
}

/* Generate BR (branch to register) */
अटल व्योम gen_br(पूर्णांक rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
अटल व्योम gen_blr(पूर्णांक rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
अटल व्योम gen_ret(पूर्णांक rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
अटल व्योम gen_b_cond(पूर्णांक cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
अटल व्योम gen_cbz_or_cbnz(पूर्णांक rt, int32_t offset, पूर्णांक is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    अगर (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

अटल व्योम gen_cbz(पूर्णांक rt, int32_t offset, पूर्णांक is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
अटल व्योम gen_cbnz(पूर्णांक rt, int32_t offset, पूर्णांक is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
अटल व्योम gen_mov_reg(पूर्णांक rd, पूर्णांक rm, पूर्णांक is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    अगर (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

अटल पूर्णांक arm64_asm_encode_bimm64(uint64_t x)
{
    पूर्णांक neg, rep, pos, len;

    neg = x & 1;
    अगर (neg)
        x = ~x;
    अगर (!x)
        वापस -1;

    अगर (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    अन्यथा अगर (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    अन्यथा अगर (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    अन्यथा अगर (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    अन्यथा अगर (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    अन्यथा
        rep = 64;

    pos = 0;
    अगर (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    अगर (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    अगर (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    अगर (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    अगर (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    अगर (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    अगर (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    अगर (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    अगर (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    अगर (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    अगर (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    अगर (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    अगर (x)
        वापस -1;
    अगर (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    वापस ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

अटल व्योम gen_logical_imm(uint32_t opcode, पूर्णांक rd, पूर्णांक rn,
                            uint64_t imm, पूर्णांक is_64bit)
{
    uint32_t instr;
    uint64_t val;
    पूर्णांक enc;

    अगर (is_64bit)
        val = imm;
    अन्यथा {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    अगर (enc < 0) {
        tcc_error("logical immediate out of range");
        वापस;
    }

    instr = opcode;
    अगर (is_64bit)
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
अटल अंतरभूत पूर्णांक constraint_priority(स्थिर अक्षर *str)
{
    पूर्णांक priority, c, pr;

    priority = 0;
    क्रम (;;) {
        c = *str++;
        अगर (c == '\0')
            अवरोध;
        चयन (c) {
        हाल '=':
        हाल '+':
        हाल '&':
            जारी;
        हाल 'r':
            pr = 1;
            अवरोध;
        हाल 'w':
        हाल 'f':
        हाल 'x':
        हाल 'y':
            pr = 3;
            अवरोध;
        हाल 'm':
        हाल 'Q':
            pr = 4;
            अवरोध;
        हाल 'i':
        हाल 'S':
            pr = 5;
            अवरोध;
        हाल 'U':
            अगर (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                अवरोध;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            अवरोध;
        हाल 'I':
        हाल 'J':
        हाल 'K':
        हाल 'L':
        हाल 'M':
        हाल 'N':
        हाल 'Z':
            pr = 6;
            अवरोध;
        हाल 'n':
            pr = 7;
            अवरोध;
        हाल 'g':
            pr = 8;
            अवरोध;
        शेष:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            अवरोध;
        }
        अगर (pr > priority)
            priority = pr;
    }
    वापस priority;
}

अटल स्थिर अक्षर *skip_constraint_modifiers(स्थिर अक्षर *p)
{
    जबतक (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    वापस p;
}

अटल पूर्णांक is_valid_add_imm(int64_t val)
{
    वापस val >= 0 && val <= 4095;
}

अटल पूर्णांक is_valid_logical_imm(int64_t val, पूर्णांक bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    अगर (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    वापस arm64_asm_encode_bimm64(uval) >= 0;
}

अटल पूर्णांक is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    अगर (uval <= 0xFFFF)
        वापस 1;
    अगर (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        वापस 1;
    अगर (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        वापस 1;
    अगर ((uval & 0xFFFFFFFF00000000ULL) == 0)
        वापस 1;

    वापस 0;
}

अटल पूर्णांक is_valid_movw_shift(पूर्णांक shift, पूर्णांक is_64bit)
{
    अगर (shift < 0 || (shift & 15))
        वापस 0;
    अगर (shift > (is_64bit ? 48 : 16))
        वापस 0;
    वापस 1;
}

अटल पूर्णांक arm64_memory_is_base_only(स्थिर SValue *sv)
{
    पूर्णांक r;

    r = sv->r;
    अगर ((r & VT_VALMASK) == VT_CONST)
        वापस 0;
    अगर ((r & VT_VALMASK) == VT_LOCAL)
        वापस 0;
    अगर ((r & VT_VALMASK) == VT_LLOCAL)
        वापस 1;
    अगर (r & VT_LVAL)
        वापस (r & VT_VALMASK) < VT_CONST;
    वापस 0;
}

अटल पूर्णांक arm64_memory_is_pair_suitable(स्थिर SValue *sv)
{
    int64_t offset;

    अगर (arm64_memory_is_base_only(sv))
        वापस 1;
    अगर ((sv->r & VT_VALMASK) != VT_LOCAL)
        वापस 0;

    offset = (int64_t)sv->c.i;
    वापस (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

अटल पूर्णांक arm64_int_reg_is_allocatable(पूर्णांक reg)
{
#अगर_घोषित TCC_TARGET_PE
    वापस reg >= TREG_X0 && reg <= TREG_X17;
#अन्यथा
    वापस reg >= TREG_X0 && reg <= TREG_X30;
#पूर्ण_अगर
}

अटल पूर्णांक arm64_memory_needs_address_reg(स्थिर SValue *sv)
{
    पूर्णांक r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    अगर (!(r & VT_LVAL))
        वापस 0;
    चयन (r & VT_VALMASK) {
    हाल VT_LOCAL:
    हाल VT_LLOCAL:
    हाल VT_CONST:
        वापस 1;
    }
    वापस 0;
}

अटल पूर्णांक arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    पूर्णांक reg;

    अगर (!arm64_memory_needs_address_reg(op->vt))
        वापस 1;

    क्रम (reg = 0; reg < 31; reg++) {
        अगर (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            वापस 1;
        }
    }
    वापस 0;
}

अटल व्योम arm64_load_memory_operand_base(पूर्णांक reg, SValue *sv)
{
    SValue base;
    पूर्णांक rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    अगर (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } अन्यथा अगर (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } अन्यथा {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

अटल पूर्णांक operand_is_sp(स्थिर Operand *op)
{
    वापस op->reg_tok == TOK_ASM_sp;
}

अटल पूर्णांक parse_sysreg_name(पूर्णांक t)
{
    स्थिर अक्षर *name;

    अगर (t < TOK_IDENT)
        वापस -1;
    name = get_tok_str(t, शून्य);
    अगर (!म_भेद(name, "FPCR") || !म_भेद(name, "fpcr"))
        वापस 0;
    अगर (!म_भेद(name, "FPSR") || !म_भेद(name, "fpsr"))
        वापस 1;
    वापस -1;
}

अटल व्योम gen_mrs(पूर्णांक rt, पूर्णांक sysreg)
{
    uint32_t instr;

    चयन (sysreg) {
        हाल 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            अवरोध;
        हाल 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            अवरोध;
        शेष:
            tcc_error("unsupported system register");
            वापस;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

अटल व्योम gen_msr(पूर्णांक rt, पूर्णांक sysreg)
{
    uint32_t instr;

    चयन (sysreg) {
        हाल 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            अवरोध;
        हाल 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            अवरोध;
        शेष:
            tcc_error("unsupported system register");
            वापस;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
अटल व्योम gen_nop(व्योम)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
अटल व्योम gen_shift(पूर्णांक rd, पूर्णांक rn, पूर्णांक rm_or_imm, पूर्णांक shift_type, पूर्णांक is_imm, पूर्णांक is_64bit)
{
    uint32_t instr;
    पूर्णांक width = is_64bit ? 64 : 32;

    अगर (is_imm) {
        /* Shift by immediate */
        चयन (shift_type) {
            हाल 0: /* LSL - UBFM alias */
                अगर (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    वापस;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                अवरोध;
            हाल 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                अगर (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    वापस;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                अवरोध;
            हाल 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                अगर (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    वापस;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                अवरोध;
            हाल 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                अगर (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    वापस;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                वापस;
            शेष:
                tcc_error("unknown shift type");
                वापस;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } अन्यथा {
        /* Shift by register */
        चयन (shift_type) {
            हाल 0: /* LSL */
                instr = ARM64_LSL_REG;
                अवरोध;
            हाल 1: /* LSR */
                instr = ARM64_LSR_REG;
                अवरोध;
            हाल 2: /* ASR */
                instr = ARM64_ASR_REG;
                अवरोध;
            हाल 3: /* ROR */
                instr = ARM64_ROR_REG;
                अवरोध;
            शेष:
                tcc_error("unknown shift type");
                वापस;
        }
        अगर (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
अटल व्योम asm_shift(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2, op3;
    पूर्णांक rd, rn, shift_amount;
    पूर्णांक shift_type;
    पूर्णांक is_64bit = 1;

    चयन (token) {
        हाल TOK_ASM_lsl:
            shift_type = 0;
            अवरोध;
        हाल TOK_ASM_lsr:
            shift_type = 1;
            अवरोध;
        हाल TOK_ASM_asr:
            shift_type = 2;
            अवरोध;
        हाल TOK_ASM_ror:
            shift_type = 3;
            अवरोध;
        शेष:
            tcc_error("unknown shift instruction");
            वापस;
    }

    parse_operand(s1, &op1);
    अगर (tok == ',') अग्र();
    parse_operand(s1, &op2);

    अगर (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        वापस;
    }
    अगर (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        वापस;
    }

    rd = op1.reg;
    rn = op2.reg;

    अगर (tok == ',') {
        अग्र();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        अगर (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            वापस;
        }
        अगर (op3.type & OP_REG) {
            अगर (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                वापस;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } अन्यथा अगर (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } अन्यथा {
            tcc_error("shift requires immediate or register operand");
        }
    } अन्यथा {
        tcc_error("shift requires immediate or register operand");
        वापस;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
अटल व्योम gen_barrier(पूर्णांक barrier_type, पूर्णांक option)
{
    uint32_t instr;

    चयन (barrier_type) {
        हाल 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            अवरोध;
        हाल 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            अवरोध;
        हाल 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            अवरोध;
        शेष:
            tcc_error("unknown barrier type");
            वापस;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
अटल व्योम asm_barrier(TCCState *s1, पूर्णांक token)
{
    पूर्णांक barrier_type, option;
    Operand op;

    चयन (token) {
        हाल TOK_ASM_isb:
            barrier_type = 0;
            अवरोध;
        हाल TOK_ASM_dsb:
            barrier_type = 1;
            अवरोध;
        हाल TOK_ASM_dmb:
            barrier_type = 2;
            अवरोध;
        शेष:
            tcc_error("unknown barrier instruction");
            वापस;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    अगर (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        अगर (option >= 0) {
            अग्र();
        } अन्यथा {
            parse_operand(s1, &op);
            अगर (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                वापस;
            }
            अगर (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                वापस;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
अटल व्योम gen_mov_imm(पूर्णांक rd, uint64_t imm, पूर्णांक is_64bit)
{
    uint16_t hw;
    पूर्णांक i, first = 1;

    क्रम (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        अगर (hw != 0 || i == 0) {
            अगर (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } अन्यथा {
                gen_movk(rd, hw, i, is_64bit);
            }
        } अन्यथा अगर (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
अटल व्योम asm_mov(TCCState *s1)
{
    Operand op1, op2;
    पूर्णांक rd, rn;
    पूर्णांक is_64bit;

    parse_operand(s1, &op1);
    अगर (tok == ',') अग्र();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    अगर (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        अगर (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            वापस;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } अन्यथा अगर (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        अगर (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        अन्यथा
            gen_mov_reg(rd, rn, is_64bit);
    } अन्यथा {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
अटल व्योम asm_तथ्य_proc(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2, op3;
    पूर्णांक rd, rn, rm;
    पूर्णांक is_64bit = 1;
    uint32_t opcode;

    चयन (token) {
        हाल TOK_ASM_add:
        हाल TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            अवरोध;
        हाल TOK_ASM_sub:
        हाल TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            अवरोध;
        हाल TOK_ASM_and:
        हाल TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            अवरोध;
        हाल TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            अवरोध;
        हाल TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            अवरोध;
        हाल TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            अवरोध;
        शेष:
            tcc_error("unsupported data processing instruction");
            वापस;
    }

    parse_operand(s1, &op1);
    अगर (tok == ',') अग्र();
    parse_operand(s1, &op2);

    अगर (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        वापस;
    }
    अगर (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        वापस;
    }

    rd = op1.reg;
    rn = op2.reg;

    अगर (tok == ',') {
        अग्र();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        अगर (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            वापस;
        }
        अगर (op3.type & OP_IM) {
            अगर (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            अन्यथा अगर (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            अन्यथा अगर (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            अन्यथा अगर (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            अन्यथा अगर (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            अन्यथा अगर (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            अन्यथा
                tcc_error("immediate operand not valid for this instruction");
        } अन्यथा {
            अगर (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                वापस;
            }
            rm = op3.reg;
            अगर (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                वापस;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } अन्यथा अगर (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } अन्यथा {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
अटल व्योम asm_ldst(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2;
    पूर्णांक rt, rn;
    int32_t offset = 0;
    पूर्णांक आकार_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    अगर (tok == ',') अग्र();
    parse_operand(s1, &op2);

    अगर (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        वापस;
    }
    अगर (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        वापस;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    चयन (token) {
        हाल TOK_ASM_ldr:
            अगर (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                आकार_log2 = 3;
            } अन्यथा अगर (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                आकार_log2 = 2;
            } अन्यथा अगर (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                आकार_log2 = 3;
            } अन्यथा {
                tcc_error("ldr requires a w, x, or d register");
                वापस;
            }
            अवरोध;
        हाल TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            आकार_log2 = 0;
            अवरोध;
        हाल TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            आकार_log2 = 1;
            अवरोध;
        हाल TOK_ASM_str:
            अगर (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                आकार_log2 = 3;
            } अन्यथा अगर (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                आकार_log2 = 2;
            } अन्यथा अगर (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                आकार_log2 = 3;
            } अन्यथा {
                tcc_error("str requires a w, x, or d register");
                वापस;
            }
            अवरोध;
        हाल TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            आकार_log2 = 0;
            अवरोध;
        हाल TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            आकार_log2 = 1;
            अवरोध;
        शेष:
            tcc_error("unsupported load/store instruction");
            वापस;
    }

    अगर (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, आकार_log2);
}

अटल व्योम asm_ldst_pair(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    पूर्णांक आकार_log2 = 3;

    parse_operand(s1, &op1);
    अगर (tok == ',')
        अग्र();
    parse_operand(s1, &op2);
    अगर (tok == ',')
        अग्र();
    parse_operand(s1, &op3);

    अगर (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        वापस;
    }
    अगर (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        वापस;
    }
    अगर (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    अगर ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        अगर (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } अन्यथा {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } अन्यथा अगर ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        अगर (token == TOK_ASM_stp) {
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
        वापस;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, आकार_log2);
}

अटल व्योम asm_sysreg(TCCState *s1, पूर्णांक token)
{
    Operand op;
    पूर्णांक sysreg;

    अगर (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        अगर (tok == ',')
            अग्र();
        sysreg = parse_sysreg_name(tok);
        अगर (sysreg < 0)
            tcc_error("unsupported system register");
        अग्र();
        gen_mrs(op.reg, sysreg);
        वापस;
    }

    sysreg = parse_sysreg_name(tok);
    अगर (sysreg < 0)
        tcc_error("unsupported system register");
    अग्र();
    अगर (tok == ',')
        अग्र();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
अटल पूर्णांक get_branch_condition(पूर्णांक branch_token)
{
    पूर्णांक cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    चयन (branch_token) {
        हाल TOK_ASM_beq: cond_token = TOK_ASM_eq; अवरोध;
        हाल TOK_ASM_bne: cond_token = TOK_ASM_ne; अवरोध;
        हाल TOK_ASM_bcs:
        हाल TOK_ASM_bhs: cond_token = TOK_ASM_cs; अवरोध;
        हाल TOK_ASM_bcc:
        हाल TOK_ASM_blo: cond_token = TOK_ASM_cc; अवरोध;
        हाल TOK_ASM_bmi: cond_token = TOK_ASM_mi; अवरोध;
        हाल TOK_ASM_bpl: cond_token = TOK_ASM_pl; अवरोध;
        हाल TOK_ASM_bvs: cond_token = TOK_ASM_vs; अवरोध;
        हाल TOK_ASM_bvc: cond_token = TOK_ASM_vc; अवरोध;
        हाल TOK_ASM_bhi: cond_token = TOK_ASM_hi; अवरोध;
        हाल TOK_ASM_bls: cond_token = TOK_ASM_ls; अवरोध;
        हाल TOK_ASM_bge: cond_token = TOK_ASM_ge; अवरोध;
        हाल TOK_ASM_blt: cond_token = TOK_ASM_lt; अवरोध;
        हाल TOK_ASM_bgt: cond_token = TOK_ASM_gt; अवरोध;
        हाल TOK_ASM_ble: cond_token = TOK_ASM_le; अवरोध;
        शेष: वापस -1;
    }

    वापस parse_condition(cond_token);
}

/* Handle branch instructions */
अटल व्योम asm_branch(TCCState *s1, पूर्णांक token)
{
    Operand op;
    पूर्णांक cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    अगर (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        वापस;
    }

    अगर (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    अन्यथा
        parse_व्यंजक_operand(s1, &op);

    अगर (op.type & OP_IM) {
        sym = op.e.sym;
        अगर (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            अगर (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } अन्यथा {
                चयन (token) {
                    हाल TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        अवरोध;
                    हाल TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        अवरोध;
                    शेष:
                        tcc_error("unsupported branch");
                }
            }
        } अन्यथा {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            अगर (cond >= 0) {
                gen_b_cond(cond, offset);
            } अन्यथा {
                चयन (token) {
                    हाल TOK_ASM_b:
                        gen_b(offset);
                        अवरोध;
                    हाल TOK_ASM_bl:
                        gen_bl(offset);
                        अवरोध;
                    शेष:
                        tcc_error("unsupported branch");
                }
            }
        }
    } अन्यथा अगर (op.type & OP_REG) {
        चयन (token) {
            हाल TOK_ASM_br:
                gen_br(op.reg);
                अवरोध;
            हाल TOK_ASM_blr:
                gen_blr(op.reg);
                अवरोध;
            हाल TOK_ASM_ret:
                gen_ret(op.reg);
                अवरोध;
            शेष:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
अटल व्योम asm_cb(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2;
    पूर्णांक rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    अगर (tok == ',') अग्र();
    parse_व्यंजक_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    अगर (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        अगर (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } अन्यथा {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } अन्यथा {
        offset = (int32_t)op2.e.v - ind;
        अगर (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        अन्यथा
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
अटल व्योम asm_move_wide(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2;
    पूर्णांक rd, is_64bit = 1;
    uint16_t imm;
    पूर्णांक shift = 0;

    parse_operand(s1, &op1);
    अगर (tok == ',') अग्र();
    parse_operand(s1, &op2);

    अगर (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        वापस;
    }
    अगर (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        वापस;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    अगर ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        वापस;
    }
    imm = op2.e.v;

    अगर (tok == ',') {
        अग्र();
        अगर (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            वापस;
        }
            अग्र();
            अगर (tok == '#') अग्र();
            asm_व्यंजक(s1, &op2.e);
        अगर (op2.e.sym || !is_valid_movw_shift((पूर्णांक)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            वापस;
        }
            shift = (पूर्णांक)op2.e.v / 16;
        }

    चयन (token) {
        हाल TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            अवरोध;
        हाल TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            अवरोध;
        हाल TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            अवरोध;
        शेष:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC व्योम asm_opcode(TCCState *s1, पूर्णांक opcode)
{
    चयन (opcode) {
        हाल TOK_ASM_add:
        हाल TOK_ASM_adds:
        हाल TOK_ASM_sub:
        हाल TOK_ASM_subs:
        हाल TOK_ASM_and:
        हाल TOK_ASM_ands:
        हाल TOK_ASM_orr:
        हाल TOK_ASM_eor:
        हाल TOK_ASM_mul:
            asm_तथ्य_proc(s1, opcode);
            अवरोध;

        हाल TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            अवरोध;

        हाल TOK_ASM_lsl:
        हाल TOK_ASM_lsr:
        हाल TOK_ASM_asr:
        हाल TOK_ASM_ror:
            asm_shift(s1, opcode);
            अवरोध;

        हाल TOK_ASM_ldr:
        हाल TOK_ASM_ldrb:
        हाल TOK_ASM_ldrh:
        हाल TOK_ASM_str:
        हाल TOK_ASM_strb:
        हाल TOK_ASM_strh:
            asm_ldst(s1, opcode);
            अवरोध;

        हाल TOK_ASM_ldp:
        हाल TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            अवरोध;

        हाल TOK_ASM_b:
        हाल TOK_ASM_bl:
        हाल TOK_ASM_br:
        हाल TOK_ASM_blr:
        हाल TOK_ASM_ret:
        हाल TOK_ASM_beq:
        हाल TOK_ASM_bne:
        हाल TOK_ASM_bcs:
        हाल TOK_ASM_bhs:
        हाल TOK_ASM_bcc:
        हाल TOK_ASM_blo:
        हाल TOK_ASM_bmi:
        हाल TOK_ASM_bpl:
        हाल TOK_ASM_bvs:
        हाल TOK_ASM_bvc:
        हाल TOK_ASM_bhi:
        हाल TOK_ASM_bls:
        हाल TOK_ASM_bge:
        हाल TOK_ASM_blt:
        हाल TOK_ASM_bgt:
        हाल TOK_ASM_ble:
            asm_branch(s1, opcode);
            अवरोध;

        हाल TOK_ASM_cbz:
        हाल TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            अवरोध;

        हाल TOK_ASM_movz:
        हाल TOK_ASM_movn:
        हाल TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            अवरोध;

        हाल TOK_ASM_mrs:
        हाल TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            अवरोध;

        हाल TOK_ASM_isb:
        हाल TOK_ASM_dsb:
        हाल TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            अवरोध;

        हाल TOK_ASM_nop:
            gen_nop();
            अवरोध;

        शेष:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, शून्य));
            अवरोध;
    }
}

/* Substitute assembler operand */
ST_FUNC व्योम subst_asm_operand(CString *add_str, SValue *sv, पूर्णांक modifier)
{
    पूर्णांक r, reg, आकार, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    अगर ((r & VT_VALMASK) == VT_CONST) {
        अगर ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            वापस;
        }
        अगर (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        अगर (r & VT_SYM) {
            स्थिर अक्षर *name = get_tok_str(sv->sym->v, शून्य);
            अगर (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, म_माप(name))->tok, sv->sym);
            अगर (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            अगर ((uint32_t) sv->c.i == 0)
                जाओ no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        अगर (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (दीर्घ दीर्घ)val);
        } अन्यथा अगर (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (अचिन्हित दीर्घ दीर्घ)uval);
        } अन्यथा {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (दीर्घ दीर्घ)val);
        }
      no_offset:;
    } अन्यथा अगर ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (पूर्णांक) sv->c.i);
    } अन्यथा अगर (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        अगर (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } अन्यथा {
        /* register case */
        reg = r & VT_VALMASK;
        अगर (reg >= VT_CONST)
            tcc_internal_error("");

        अगर (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            आकार = type_आकार(&sv->type, &align);

            अगर (modifier == 0)
                modifier = आकार <= 4 ? 's'
                         : आकार == 8 ? 'd'
                         : 'q';

            चयन (modifier) {
            हाल 'b':
            हाल 'h':
            हाल 's':
            हाल 'd':
            हाल 'q':
            हाल 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                वापस;
            शेष:
                tcc_error("invalid operand modifier for SIMD/FP register");
                वापस;
            }
        }

        /* choose register operand size */
        अगर ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            आकार = 1;
        अन्यथा अगर ((sv->type.t & VT_BTYPE) == VT_SHORT)
            आकार = 2;
        अन्यथा अगर ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            आकार = 8;
        अन्यथा
            आकार = 4;

        अगर (modifier == 'x') {
            आकार = 8;
        } अन्यथा अगर (modifier == 'w' || modifier == 'k') {
            आकार = 4;
        } अन्यथा अगर (modifier == 'b') {
            आकार = 1;
        } अन्यथा अगर (modifier == 'h') {
            आकार = 2;
        } अन्यथा अगर (modifier == 'q') {
            आकार = 8;
        }

        अगर (आकार <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } अन्यथा {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC व्योम asm_gen_code(ASMOperand *operands, पूर्णांक nb_operands,
                          पूर्णांक nb_outputs, पूर्णांक is_output,
                          uint8_t *clobber_regs,
                          पूर्णांक out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    पूर्णांक i, reg, saved_गिनती, ढेर_आकार, ढेर_off;
    पूर्णांक saved_regs[12];
    अटल स्थिर uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    स_नकल(regs_allocated, clobber_regs, माप(regs_allocated));
    क्रम (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        अगर (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_गिनती = 0;
    क्रम (i = 0; i < माप(reg_saved) / माप(reg_saved[0]); i++) {
        reg = reg_saved[i];
        अगर (regs_allocated[reg])
            saved_regs[saved_गिनती++] = reg;
    }
    ढेर_आकार = ((saved_गिनती + 1) / 2) * 16;

    अगर (!is_output) {
        अगर (saved_गिनती > 0) {
            gen_sub_imm(31, 31, ढेर_आकार, 1, 0);

            क्रम (i = ढेर_off = 0; i < saved_गिनती; ) {
                अगर (i + 1 < saved_गिनती) {
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

        क्रम (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            अगर (op->reg >= 0) {
                अगर (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } अन्यथा अगर (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } अन्यथा {
        क्रम (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            अगर (op->reg >= 0) {
                अगर (op->is_memory)
                    जारी;
                अगर ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    अगर (!op->is_memory) {
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

        अगर (saved_गिनती > 0) {
            क्रम (i = ढेर_off = 0; i < saved_गिनती; ) {
                अगर (i + 1 < saved_गिनती) {
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
            gen_add_imm(31, 31, ढेर_आकार, 1, 0);
        }
    }
}

ST_FUNC व्योम asm_compute_constraints(ASMOperand *operands,
                                    पूर्णांक nb_operands, पूर्णांक nb_outputs,
                                    स्थिर uint8_t *clobber_regs,
                                    पूर्णांक *pout_reg)
{
    ASMOperand *op;
    पूर्णांक sorted_op[MAX_ASM_OPERANDS];
    पूर्णांक i, j, k, p1, p2, tmp, reg, c, reg_mask;
    स्थिर अक्षर *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    क्रम (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->निवेश_सूचकांक = -1;
        op->ref_सूचकांक = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    क्रम (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        अगर (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, शून्य);
            अगर ((अचिन्हित)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_सूचकांक = k;
            अगर (operands[k].निवेश_सूचकांक >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].निवेश_सूचकांक = i;
            op->priority = 5;
        } अन्यथा अगर ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } अन्यथा {
            op->priority = constraint_priority(str);
        }
    }

    क्रम (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    क्रम (i = 0; i < nb_operands - 1; i++) {
        क्रम (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            अगर (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    क्रम (i = 0; i < NB_ASM_REGS; i++) {
        अगर (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        अन्यथा
            regs_allocated[i] = 0;
    }

    क्रम (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        अगर (op->ref_सूचकांक >= 0)
            जारी;
        अगर (op->निवेश_सूचकांक >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अन्यथा अगर (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अन्यथा {
            reg_mask = REG_IN_MASK;
        }
        अगर (op->reg >= 0) {
            अगर (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            जाओ reg_found;
        }
    try_अग्र:
        c = *str++;
        चयन (c) {
        हाल '=':
            जाओ try_अग्र;
        हाल '+':
            op->is_rw = 1;
        हाल '&':
            अगर (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            जाओ try_अग्र;
        हाल 'r':
            क्रम (reg = 0; reg < 31; reg++) {
                अगर (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    जाओ reg_found;
            }
            जाओ try_अग्र;
        हाल 'w':
        हाल 'f':
            क्रम (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                अगर (!is_reg_allocated(reg))
                    जाओ reg_found;
            }
            जाओ try_अग्र;
        हाल 'x':
        हाल 'y':
            क्रम (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                अगर (!is_reg_allocated(reg))
                    जाओ reg_found;
            }
            जाओ try_अग्र;
        हाल 'm':
        हाल 'g':
            अगर (j < nb_outputs || c == 'm') {
                अगर (!arm64_prepare_memory_operand(op, regs_allocated))
                    जाओ try_अग्र;
            }
            अवरोध;
        हाल 'Q':
            अगर (!arm64_memory_is_base_only(op->vt))
                जाओ try_अग्र;
            अगर (!arm64_prepare_memory_operand(op, regs_allocated))
                जाओ try_अग्र;
            अवरोध;
        हाल 'S':
            अगर ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                जाओ try_अग्र;
            अवरोध;
        हाल 'U':
            अगर (str[0] != 'm' || str[1] != 'p')
                जाओ try_अग्र;
            str += 2;
            अगर (!arm64_memory_is_pair_suitable(op->vt))
                जाओ try_अग्र;
            अगर (!arm64_prepare_memory_operand(op, regs_allocated))
                जाओ try_अग्र;
            अवरोध;
        हाल 'i':
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                जाओ try_अग्र;
            अवरोध;
        हाल 'I':
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जाओ try_अग्र;
            अगर (!is_valid_add_imm(op->vt->c.i))
                जाओ try_अग्र;
            अवरोध;
        हाल 'J':
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जाओ try_अग्र;
            अगर (!is_valid_add_imm(-op->vt->c.i))
                जाओ try_अग्र;
            अवरोध;
        हाल 'K':
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जाओ try_अग्र;
            अगर (!is_valid_logical_imm(op->vt->c.i, 32))
                जाओ try_अग्र;
            अवरोध;
        हाल 'L':
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जाओ try_अग्र;
            अगर (!is_valid_logical_imm(op->vt->c.i, 64))
                जाओ try_अग्र;
            अवरोध;
        हाल 'M':
        हाल 'N':
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जाओ try_अग्र;
            अगर (!is_valid_movw_imm(op->vt->c.i))
                जाओ try_अग्र;
            अवरोध;
        हाल 'Z':
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जाओ try_अग्र;
            अगर (op->vt->c.i != 0)
                जाओ try_अग्र;
            अवरोध;
        हाल 'n':
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                जाओ try_अग्र;
            अवरोध;
        शेष:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            अवरोध;
        }
        अगर (op->निवेश_सूचकांक >= 0) {
            operands[op->निवेश_सूचकांक].reg = op->reg;
            operands[op->निवेश_सूचकांक].is_llong = op->is_llong;
        }
        जारी;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        अगर (op->निवेश_सूचकांक >= 0) {
            operands[op->निवेश_सूचकांक].reg = op->reg;
            operands[op->निवेश_सूचकांक].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    क्रम (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        अगर (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            क्रम (reg = 0; reg < 31; reg++) {
                अगर (!(regs_allocated[reg] & REG_OUT_MASK))
                    जाओ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            अवरोध;
        }
    }
}

/* Handle clobber list */
ST_FUNC व्योम asm_clobber(uint8_t *clobber_regs, स्थिर अक्षर *str)
{
    पूर्णांक reg;

    अगर (!म_भेद(str, "memory") ||
        !म_भेद(str, "cc") ||
        !म_भेद(str, "flags"))
        वापस;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    अगर (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC पूर्णांक asm_parse_regvar(पूर्णांक t)
{
    वापस arm64_parse_regvar(t);
}

/*************************************************************/
#पूर्ण_अगर /* ndef TARGET_DEFS_ONLY */
