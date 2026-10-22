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

ST_FUNC शून्य g(पूर्णांक c);
ST_FUNC शून्य gen_le16(पूर्णांक c);
ST_FUNC शून्य gen_le32(पूर्णांक c);

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

प्रकारव्याख्या संरचना Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    पूर्णांक reg_tok;
    अभिव्यक्ती_मूल्य e;
} Operand;

गणना {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
स्थिर शून्य parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC शून्य g(पूर्णांक c)
{
    पूर्णांक ind1;
    जर (nocode_wanted)
        परत;
    ind1 = ind + 1;
    जर (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC शून्य gen_le16(पूर्णांक c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC शून्य gen_le32(पूर्णांक c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC शून्य gen_expr32(अभिव्यक्ती_मूल्य *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
स्थिर शून्य emit_instr32(uint32_t val)
{
    जर (nocode_wanted)
        परत;
    जर (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
स्थिर पूर्णांक arm64_parse_asm_reg(पूर्णांक t)
{
    /* X registers (64-bit) */
    जर (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        परत t - TOK_ASM_x0;
    /* W registers (32-bit) */
    जर (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        परत t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    जर (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        परत (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    जर (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        परत (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    जर (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        परत (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    जर (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        परत (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    जर (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        परत (t - TOK_ASM_b0) + 32;
    /* Special registers */
    जर (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        परत 31;  /* SP/ZR encoded as 31 */
    परत -1;
}

/* Get register type from token */
स्थिर uint8_t get_reg_type(पूर्णांक t)
{
    जर (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        परत REG_X;
    जर (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        परत REG_W;
    जर (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        परत REG_V;
    जर (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        परत REG_D;
    जर (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        परत REG_S;
    जर (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        परत REG_H;
    जर (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        परत REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    जर (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        परत REG_X;
    जर (t == TOK_ASM_wzr)
        परत REG_W;
    परत REG_X;
}

/* Parse condition code */
स्थिर पूर्णांक parse_condition(पूर्णांक t)
{
    निवड (t) {
        स्थिती TOK_ASM_eq: परत 0;
        स्थिती TOK_ASM_ne: परत 1;
        स्थिती TOK_ASM_cs:
        स्थिती TOK_ASM_hs: परत 2;
        स्थिती TOK_ASM_cc:
        स्थिती TOK_ASM_lo: परत 3;
        स्थिती TOK_ASM_mi: परत 4;
        स्थिती TOK_ASM_pl: परत 5;
        स्थिती TOK_ASM_vs: परत 6;
        स्थिती TOK_ASM_vc: परत 7;
        स्थिती TOK_ASM_hi: परत 8;
        स्थिती TOK_ASM_ls: परत 9;
        स्थिती TOK_ASM_ge: परत 10;
        स्थिती TOK_ASM_lt: परत 11;
        स्थिती TOK_ASM_gt: परत 12;
        स्थिती TOK_ASM_le: परत 13;
        स्थिती TOK_ASM_al: परत 14;
        पूर्वनिर्धारित: परत -1;
    }
}

स्थिर पूर्णांक parse_barrier_option_name(पूर्णांक t)
{
    स्थिरांक अक्षर *name;

    जर (t < TOK_IDENT)
        परत -1;
    name = get_tok_str(t, रिक्त);
    जर (!म_भेद(name, "oshld")) परत 0x1;
    जर (!म_भेद(name, "oshst")) परत 0x2;
    जर (!म_भेद(name, "osh"))   परत 0x3;
    जर (!म_भेद(name, "nshld")) परत 0x5;
    जर (!म_भेद(name, "nshst")) परत 0x6;
    जर (!म_भेद(name, "nsh"))   परत 0x7;
    जर (!म_भेद(name, "ishld")) परत 0x9;
    जर (!म_भेद(name, "ishst")) परत 0xA;
    जर (!म_भेद(name, "ish"))   परत 0xB;
    जर (!म_भेद(name, "ld"))    परत 0xD;
    जर (!म_भेद(name, "st"))    परत 0xE;
    जर (!म_भेद(name, "sy"))    परत 0xF;
    परत -1;
}

स्थिर पूर्णांक arm64_parse_regvar(पूर्णांक t)
{
    जर (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        परत t - TOK_ASM_x0;
    जर (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        परत ARM64_FREG_BASE + (t - TOK_ASM_v0);
    जर (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        परत ARM64_FREG_BASE + (t - TOK_ASM_d0);
    जर (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        परत ARM64_FREG_BASE + (t - TOK_ASM_s0);
    जर (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        परत ARM64_FREG_BASE + (t - TOK_ASM_h0);
    जर (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        परत ARM64_FREG_BASE + (t - TOK_ASM_b0);
    परत -1;
}

/* Parse a single operand */
स्थिर शून्य parse_operand(TCCState *s1, Operand *op)
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
    जर (tok == '[') {
        parse_addr_operand(s1, op);
        परत;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    जर (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        परत;
    }

    /* Condition code */
    reg = parse_condition(tok);
    जर (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        परत;
    }

    /* Immediate or address expression */
    जर (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_अभिव्यक्ती(s1, &op->e);
        op->type = OP_IM;
    } अन्यथा जर (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } अन्यथा {
        asm_अभिव्यक्ती(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
स्थिर शून्य parse_अभिव्यक्ती_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    जर (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_अभिव्यक्ती(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
स्थिर शून्य parse_addr_operand(TCCState *s1, Operand *op)
{
    पूर्णांक reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = रिक्त;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    जर (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        परत;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    जर (tok == ',') {
        next();
        जर (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_अभिव्यक्ती(s1, &op->e);
    }
    skip(']');
    जर (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } अन्यथा जर (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        जर (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_अभिव्यक्ती(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
स्थिर शून्य gen_mov_with_base(पूर्णांक rd, uint16_t imm, पूर्णांक shift,
                              पूर्णांक is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    जर (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

स्थिर शून्य gen_movz(पूर्णांक rd, uint16_t imm, पूर्णांक shift, पूर्णांक is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
स्थिर शून्य gen_movn(पूर्णांक rd, uint16_t imm, पूर्णांक shift, पूर्णांक is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
स्थिर शून्य gen_movk(पूर्णांक rd, uint16_t imm, पूर्णांक shift, पूर्णांक is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
स्थिर शून्य gen_add_imm(पूर्णांक rd, पूर्णांक rn, uint32_t imm, पूर्णांक is_64bit, पूर्णांक setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    जर (is_64bit) instr |= ARM64_SF(1);
    जर (setflags) instr |= ARM64_S(1);

    जर (imm <= 0xFFF) {
        imm12 = imm;
    } अन्यथा जर (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } अन्यथा {
        tcc_error("add immediate out of range");
        परत;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
स्थिर शून्य gen_sub_imm(पूर्णांक rd, पूर्णांक rn, uint32_t imm, पूर्णांक is_64bit, पूर्णांक setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    जर (is_64bit) instr |= ARM64_SF(1);
    जर (setflags) instr |= ARM64_S(1);

    जर (imm <= 0xFFF) {
        imm12 = imm;
    } अन्यथा जर (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } अन्यथा {
        tcc_error("sub immediate out of range");
        परत;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
स्थिर शून्य gen_dp_reg(uint32_t opcode, पूर्णांक rd, पूर्णांक rn, पूर्णांक rm, पूर्णांक is_64bit)
{
    uint32_t instr = opcode;
    जर (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
स्थिर शून्य gen_ldst_imm(uint32_t base_opcode, पूर्णांक rt, पूर्णांक rn,
                         int32_t offset, पूर्णांक size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    जर (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        जर (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            परत;
        }
    }

    निवड (base_opcode) {
    स्थिती ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; थांबा;
    स्थिती ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; थांबा;
    स्थिती ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; थांबा;
    स्थिती ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; थांबा;
    स्थिती ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; थांबा;
    स्थिती ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; थांबा;
    स्थिती ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; थांबा;
    स्थिती ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; थांबा;
    स्थिती ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; थांबा;
    स्थिती ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; थांबा;
    }

    जर (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        परत;
    }

    जर (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
स्थिर शून्य gen_ldst_pair(uint32_t base_opcode, पूर्णांक rt, पूर्णांक rt2, पूर्णांक rn,
                          int32_t offset, पूर्णांक size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    जर (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    जर (imm7 < -64 || imm7 > 63)
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
स्थिर शून्य gen_br(पूर्णांक rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
स्थिर शून्य gen_blr(पूर्णांक rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
स्थिर शून्य gen_ret(पूर्णांक rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
स्थिर शून्य gen_b_cond(पूर्णांक cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
स्थिर शून्य gen_cbz_or_cbnz(पूर्णांक rt, int32_t offset, पूर्णांक is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    जर (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

स्थिर शून्य gen_cbz(पूर्णांक rt, int32_t offset, पूर्णांक is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
स्थिर शून्य gen_cbnz(पूर्णांक rt, int32_t offset, पूर्णांक is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
स्थिर शून्य gen_mov_reg(पूर्णांक rd, पूर्णांक rm, पूर्णांक is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    जर (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

स्थिर पूर्णांक arm64_asm_encode_bimm64(uint64_t x)
{
    पूर्णांक neg, rep, pos, len;

    neg = x & 1;
    जर (neg)
        x = ~x;
    जर (!x)
        परत -1;

    जर (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    अन्यथा जर (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    अन्यथा जर (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    अन्यथा जर (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    अन्यथा जर (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    अन्यथा
        rep = 64;

    pos = 0;
    जर (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    जर (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    जर (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    जर (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    जर (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    जर (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    जर (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    जर (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    जर (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    जर (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    जर (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    जर (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    जर (x)
        परत -1;
    जर (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    परत ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

स्थिर शून्य gen_logical_imm(uint32_t opcode, पूर्णांक rd, पूर्णांक rn,
                            uint64_t imm, पूर्णांक is_64bit)
{
    uint32_t instr;
    uint64_t val;
    पूर्णांक enc;

    जर (is_64bit)
        val = imm;
    अन्यथा {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    जर (enc < 0) {
        tcc_error("logical immediate out of range");
        परत;
    }

    instr = opcode;
    जर (is_64bit)
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
स्थिर ओळीत पूर्णांक constraint_priority(स्थिरांक अक्षर *str)
{
    पूर्णांक priority, c, pr;

    priority = 0;
    साठी (;;) {
        c = *str++;
        जर (c == '\0')
            थांबा;
        निवड (c) {
        स्थिती '=':
        स्थिती '+':
        स्थिती '&':
            सुरूठेवा;
        स्थिती 'r':
            pr = 1;
            थांबा;
        स्थिती 'w':
        स्थिती 'f':
        स्थिती 'x':
        स्थिती 'y':
            pr = 3;
            थांबा;
        स्थिती 'm':
        स्थिती 'Q':
            pr = 4;
            थांबा;
        स्थिती 'i':
        स्थिती 'S':
            pr = 5;
            थांबा;
        स्थिती 'U':
            जर (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                थांबा;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            थांबा;
        स्थिती 'I':
        स्थिती 'J':
        स्थिती 'K':
        स्थिती 'L':
        स्थिती 'M':
        स्थिती 'N':
        स्थिती 'Z':
            pr = 6;
            थांबा;
        स्थिती 'n':
            pr = 7;
            थांबा;
        स्थिती 'g':
            pr = 8;
            थांबा;
        पूर्वनिर्धारित:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            थांबा;
        }
        जर (pr > priority)
            priority = pr;
    }
    परत priority;
}

स्थिर स्थिरांक अक्षर *skip_constraint_modifiers(स्थिरांक अक्षर *p)
{
    पर्यंत (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    परत p;
}

स्थिर पूर्णांक is_valid_add_imm(int64_t val)
{
    परत val >= 0 && val <= 4095;
}

स्थिर पूर्णांक is_valid_logical_imm(int64_t val, पूर्णांक bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    जर (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    परत arm64_asm_encode_bimm64(uval) >= 0;
}

स्थिर पूर्णांक is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    जर (uval <= 0xFFFF)
        परत 1;
    जर (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        परत 1;
    जर (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        परत 1;
    जर ((uval & 0xFFFFFFFF00000000ULL) == 0)
        परत 1;

    परत 0;
}

स्थिर पूर्णांक is_valid_movw_shift(पूर्णांक shift, पूर्णांक is_64bit)
{
    जर (shift < 0 || (shift & 15))
        परत 0;
    जर (shift > (is_64bit ? 48 : 16))
        परत 0;
    परत 1;
}

स्थिर पूर्णांक arm64_memory_is_base_only(स्थिरांक SValue *sv)
{
    पूर्णांक r;

    r = sv->r;
    जर ((r & VT_VALMASK) == VT_CONST)
        परत 0;
    जर ((r & VT_VALMASK) == VT_LOCAL)
        परत 0;
    जर ((r & VT_VALMASK) == VT_LLOCAL)
        परत 1;
    जर (r & VT_LVAL)
        परत (r & VT_VALMASK) < VT_CONST;
    परत 0;
}

स्थिर पूर्णांक arm64_memory_is_pair_suitable(स्थिरांक SValue *sv)
{
    int64_t offset;

    जर (arm64_memory_is_base_only(sv))
        परत 1;
    जर ((sv->r & VT_VALMASK) != VT_LOCAL)
        परत 0;

    offset = (int64_t)sv->c.i;
    परत (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

स्थिर पूर्णांक arm64_int_reg_is_allocatable(पूर्णांक reg)
{
#ifdef TCC_TARGET_PE
    परत reg >= TREG_X0 && reg <= TREG_X17;
#अन्यथा
    परत reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

स्थिर पूर्णांक arm64_memory_needs_address_reg(स्थिरांक SValue *sv)
{
    पूर्णांक r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    जर (!(r & VT_LVAL))
        परत 0;
    निवड (r & VT_VALMASK) {
    स्थिती VT_LOCAL:
    स्थिती VT_LLOCAL:
    स्थिती VT_CONST:
        परत 1;
    }
    परत 0;
}

स्थिर पूर्णांक arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    पूर्णांक reg;

    जर (!arm64_memory_needs_address_reg(op->vt))
        परत 1;

    साठी (reg = 0; reg < 31; reg++) {
        जर (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            परत 1;
        }
    }
    परत 0;
}

स्थिर शून्य arm64_load_memory_operand_base(पूर्णांक reg, SValue *sv)
{
    SValue base;
    पूर्णांक rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    जर (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } अन्यथा जर (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } अन्यथा {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

स्थिर पूर्णांक operand_is_sp(स्थिरांक Operand *op)
{
    परत op->reg_tok == TOK_ASM_sp;
}

स्थिर पूर्णांक parse_sysreg_name(पूर्णांक t)
{
    स्थिरांक अक्षर *name;

    जर (t < TOK_IDENT)
        परत -1;
    name = get_tok_str(t, रिक्त);
    जर (!म_भेद(name, "FPCR") || !म_भेद(name, "fpcr"))
        परत 0;
    जर (!म_भेद(name, "FPSR") || !म_भेद(name, "fpsr"))
        परत 1;
    परत -1;
}

स्थिर शून्य gen_mrs(पूर्णांक rt, पूर्णांक sysreg)
{
    uint32_t instr;

    निवड (sysreg) {
        स्थिती 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            थांबा;
        स्थिती 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("unsupported system register");
            परत;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

स्थिर शून्य gen_msr(पूर्णांक rt, पूर्णांक sysreg)
{
    uint32_t instr;

    निवड (sysreg) {
        स्थिती 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            थांबा;
        स्थिती 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("unsupported system register");
            परत;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
स्थिर शून्य gen_nop(शून्य)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
स्थिर शून्य gen_shift(पूर्णांक rd, पूर्णांक rn, पूर्णांक rm_or_imm, पूर्णांक shift_type, पूर्णांक is_imm, पूर्णांक is_64bit)
{
    uint32_t instr;
    पूर्णांक width = is_64bit ? 64 : 32;

    जर (is_imm) {
        /* Shift by immediate */
        निवड (shift_type) {
            स्थिती 0: /* LSL - UBFM alias */
                जर (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    परत;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                थांबा;
            स्थिती 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                जर (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    परत;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                थांबा;
            स्थिती 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                जर (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    परत;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                थांबा;
            स्थिती 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                जर (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    परत;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                परत;
            पूर्वनिर्धारित:
                tcc_error("unknown shift type");
                परत;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } अन्यथा {
        /* Shift by register */
        निवड (shift_type) {
            स्थिती 0: /* LSL */
                instr = ARM64_LSL_REG;
                थांबा;
            स्थिती 1: /* LSR */
                instr = ARM64_LSR_REG;
                थांबा;
            स्थिती 2: /* ASR */
                instr = ARM64_ASR_REG;
                थांबा;
            स्थिती 3: /* ROR */
                instr = ARM64_ROR_REG;
                थांबा;
            पूर्वनिर्धारित:
                tcc_error("unknown shift type");
                परत;
        }
        जर (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
स्थिर शून्य asm_shift(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2, op3;
    पूर्णांक rd, rn, shift_amount;
    पूर्णांक shift_type;
    पूर्णांक is_64bit = 1;

    निवड (token) {
        स्थिती TOK_ASM_lsl:
            shift_type = 0;
            थांबा;
        स्थिती TOK_ASM_lsr:
            shift_type = 1;
            थांबा;
        स्थिती TOK_ASM_asr:
            shift_type = 2;
            थांबा;
        स्थिती TOK_ASM_ror:
            shift_type = 3;
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("unknown shift instruction");
            परत;
    }

    parse_operand(s1, &op1);
    जर (tok == ',') next();
    parse_operand(s1, &op2);

    जर (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        परत;
    }
    जर (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        परत;
    }

    rd = op1.reg;
    rn = op2.reg;

    जर (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        जर (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            परत;
        }
        जर (op3.type & OP_REG) {
            जर (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                परत;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } अन्यथा जर (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } अन्यथा {
            tcc_error("shift requires immediate or register operand");
        }
    } अन्यथा {
        tcc_error("shift requires immediate or register operand");
        परत;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
स्थिर शून्य gen_barrier(पूर्णांक barrier_type, पूर्णांक option)
{
    uint32_t instr;

    निवड (barrier_type) {
        स्थिती 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            थांबा;
        स्थिती 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            थांबा;
        स्थिती 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("unknown barrier type");
            परत;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
स्थिर शून्य asm_barrier(TCCState *s1, पूर्णांक token)
{
    पूर्णांक barrier_type, option;
    Operand op;

    निवड (token) {
        स्थिती TOK_ASM_isb:
            barrier_type = 0;
            थांबा;
        स्थिती TOK_ASM_dsb:
            barrier_type = 1;
            थांबा;
        स्थिती TOK_ASM_dmb:
            barrier_type = 2;
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("unknown barrier instruction");
            परत;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    जर (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        जर (option >= 0) {
            next();
        } अन्यथा {
            parse_operand(s1, &op);
            जर (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                परत;
            }
            जर (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                परत;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
स्थिर शून्य gen_mov_imm(पूर्णांक rd, uint64_t imm, पूर्णांक is_64bit)
{
    uint16_t hw;
    पूर्णांक i, first = 1;

    साठी (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        जर (hw != 0 || i == 0) {
            जर (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } अन्यथा {
                gen_movk(rd, hw, i, is_64bit);
            }
        } अन्यथा जर (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
स्थिर शून्य asm_mov(TCCState *s1)
{
    Operand op1, op2;
    पूर्णांक rd, rn;
    पूर्णांक is_64bit;

    parse_operand(s1, &op1);
    जर (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    जर (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        जर (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            परत;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } अन्यथा जर (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        जर (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        अन्यथा
            gen_mov_reg(rd, rn, is_64bit);
    } अन्यथा {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
स्थिर शून्य asm_data_proc(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2, op3;
    पूर्णांक rd, rn, rm;
    पूर्णांक is_64bit = 1;
    uint32_t opcode;

    निवड (token) {
        स्थिती TOK_ASM_add:
        स्थिती TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            थांबा;
        स्थिती TOK_ASM_sub:
        स्थिती TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            थांबा;
        स्थिती TOK_ASM_and:
        स्थिती TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            थांबा;
        स्थिती TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            थांबा;
        स्थिती TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            थांबा;
        स्थिती TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("unsupported data processing instruction");
            परत;
    }

    parse_operand(s1, &op1);
    जर (tok == ',') next();
    parse_operand(s1, &op2);

    जर (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        परत;
    }
    जर (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        परत;
    }

    rd = op1.reg;
    rn = op2.reg;

    जर (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        जर (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            परत;
        }
        जर (op3.type & OP_IM) {
            जर (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            अन्यथा जर (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            अन्यथा जर (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            अन्यथा जर (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            अन्यथा जर (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            अन्यथा जर (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            अन्यथा
                tcc_error("immediate operand not valid for this instruction");
        } अन्यथा {
            जर (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                परत;
            }
            rm = op3.reg;
            जर (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                परत;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } अन्यथा जर (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } अन्यथा {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
स्थिर शून्य asm_ldst(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2;
    पूर्णांक rt, rn;
    int32_t offset = 0;
    पूर्णांक size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    जर (tok == ',') next();
    parse_operand(s1, &op2);

    जर (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        परत;
    }
    जर (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        परत;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    निवड (token) {
        स्थिती TOK_ASM_ldr:
            जर (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } अन्यथा जर (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } अन्यथा जर (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } अन्यथा {
                tcc_error("ldr requires a w, x, or d register");
                परत;
            }
            थांबा;
        स्थिती TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            थांबा;
        स्थिती TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            थांबा;
        स्थिती TOK_ASM_str:
            जर (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } अन्यथा जर (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } अन्यथा जर (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } अन्यथा {
                tcc_error("str requires a w, x, or d register");
                परत;
            }
            थांबा;
        स्थिती TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            थांबा;
        स्थिती TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("unsupported load/store instruction");
            परत;
    }

    जर (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

स्थिर शून्य asm_ldst_pair(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    पूर्णांक size_log2 = 3;

    parse_operand(s1, &op1);
    जर (tok == ',')
        next();
    parse_operand(s1, &op2);
    जर (tok == ',')
        next();
    parse_operand(s1, &op3);

    जर (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        परत;
    }
    जर (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        परत;
    }
    जर (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    जर ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        जर (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } अन्यथा {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } अन्यथा जर ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        जर (token == TOK_ASM_stp) {
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
        परत;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

स्थिर शून्य asm_sysreg(TCCState *s1, पूर्णांक token)
{
    Operand op;
    पूर्णांक sysreg;

    जर (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        जर (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        जर (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        परत;
    }

    sysreg = parse_sysreg_name(tok);
    जर (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    जर (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
स्थिर पूर्णांक get_branch_condition(पूर्णांक branch_token)
{
    पूर्णांक cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    निवड (branch_token) {
        स्थिती TOK_ASM_beq: cond_token = TOK_ASM_eq; थांबा;
        स्थिती TOK_ASM_bne: cond_token = TOK_ASM_ne; थांबा;
        स्थिती TOK_ASM_bcs:
        स्थिती TOK_ASM_bhs: cond_token = TOK_ASM_cs; थांबा;
        स्थिती TOK_ASM_bcc:
        स्थिती TOK_ASM_blo: cond_token = TOK_ASM_cc; थांबा;
        स्थिती TOK_ASM_bmi: cond_token = TOK_ASM_mi; थांबा;
        स्थिती TOK_ASM_bpl: cond_token = TOK_ASM_pl; थांबा;
        स्थिती TOK_ASM_bvs: cond_token = TOK_ASM_vs; थांबा;
        स्थिती TOK_ASM_bvc: cond_token = TOK_ASM_vc; थांबा;
        स्थिती TOK_ASM_bhi: cond_token = TOK_ASM_hi; थांबा;
        स्थिती TOK_ASM_bls: cond_token = TOK_ASM_ls; थांबा;
        स्थिती TOK_ASM_bge: cond_token = TOK_ASM_ge; थांबा;
        स्थिती TOK_ASM_blt: cond_token = TOK_ASM_lt; थांबा;
        स्थिती TOK_ASM_bgt: cond_token = TOK_ASM_gt; थांबा;
        स्थिती TOK_ASM_ble: cond_token = TOK_ASM_le; थांबा;
        पूर्वनिर्धारित: परत -1;
    }

    परत parse_condition(cond_token);
}

/* Handle branch instructions */
स्थिर शून्य asm_branch(TCCState *s1, पूर्णांक token)
{
    Operand op;
    पूर्णांक cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    जर (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        परत;
    }

    जर (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    अन्यथा
        parse_अभिव्यक्ती_operand(s1, &op);

    जर (op.type & OP_IM) {
        sym = op.e.sym;
        जर (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            जर (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } अन्यथा {
                निवड (token) {
                    स्थिती TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        थांबा;
                    स्थिती TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        थांबा;
                    पूर्वनिर्धारित:
                        tcc_error("unsupported branch");
                }
            }
        } अन्यथा {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            जर (cond >= 0) {
                gen_b_cond(cond, offset);
            } अन्यथा {
                निवड (token) {
                    स्थिती TOK_ASM_b:
                        gen_b(offset);
                        थांबा;
                    स्थिती TOK_ASM_bl:
                        gen_bl(offset);
                        थांबा;
                    पूर्वनिर्धारित:
                        tcc_error("unsupported branch");
                }
            }
        }
    } अन्यथा जर (op.type & OP_REG) {
        निवड (token) {
            स्थिती TOK_ASM_br:
                gen_br(op.reg);
                थांबा;
            स्थिती TOK_ASM_blr:
                gen_blr(op.reg);
                थांबा;
            स्थिती TOK_ASM_ret:
                gen_ret(op.reg);
                थांबा;
            पूर्वनिर्धारित:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
स्थिर शून्य asm_cb(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2;
    पूर्णांक rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    जर (tok == ',') next();
    parse_अभिव्यक्ती_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    जर (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        जर (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } अन्यथा {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } अन्यथा {
        offset = (int32_t)op2.e.v - ind;
        जर (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        अन्यथा
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
स्थिर शून्य asm_move_wide(TCCState *s1, पूर्णांक token)
{
    Operand op1, op2;
    पूर्णांक rd, is_64bit = 1;
    uint16_t imm;
    पूर्णांक shift = 0;

    parse_operand(s1, &op1);
    जर (tok == ',') next();
    parse_operand(s1, &op2);

    जर (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        परत;
    }
    जर (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        परत;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    जर ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        परत;
    }
    imm = op2.e.v;

    जर (tok == ',') {
        next();
        जर (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            परत;
        }
            next();
            जर (tok == '#') next();
            asm_अभिव्यक्ती(s1, &op2.e);
        जर (op2.e.sym || !is_valid_movw_shift((पूर्णांक)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            परत;
        }
            shift = (पूर्णांक)op2.e.v / 16;
        }

    निवड (token) {
        स्थिती TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            थांबा;
        स्थिती TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            थांबा;
        स्थिती TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC शून्य asm_opcode(TCCState *s1, पूर्णांक opcode)
{
    निवड (opcode) {
        स्थिती TOK_ASM_add:
        स्थिती TOK_ASM_adds:
        स्थिती TOK_ASM_sub:
        स्थिती TOK_ASM_subs:
        स्थिती TOK_ASM_and:
        स्थिती TOK_ASM_ands:
        स्थिती TOK_ASM_orr:
        स्थिती TOK_ASM_eor:
        स्थिती TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            थांबा;

        स्थिती TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            थांबा;

        स्थिती TOK_ASM_lsl:
        स्थिती TOK_ASM_lsr:
        स्थिती TOK_ASM_asr:
        स्थिती TOK_ASM_ror:
            asm_shift(s1, opcode);
            थांबा;

        स्थिती TOK_ASM_ldr:
        स्थिती TOK_ASM_ldrb:
        स्थिती TOK_ASM_ldrh:
        स्थिती TOK_ASM_str:
        स्थिती TOK_ASM_strb:
        स्थिती TOK_ASM_strh:
            asm_ldst(s1, opcode);
            थांबा;

        स्थिती TOK_ASM_ldp:
        स्थिती TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            थांबा;

        स्थिती TOK_ASM_b:
        स्थिती TOK_ASM_bl:
        स्थिती TOK_ASM_br:
        स्थिती TOK_ASM_blr:
        स्थिती TOK_ASM_ret:
        स्थिती TOK_ASM_beq:
        स्थिती TOK_ASM_bne:
        स्थिती TOK_ASM_bcs:
        स्थिती TOK_ASM_bhs:
        स्थिती TOK_ASM_bcc:
        स्थिती TOK_ASM_blo:
        स्थिती TOK_ASM_bmi:
        स्थिती TOK_ASM_bpl:
        स्थिती TOK_ASM_bvs:
        स्थिती TOK_ASM_bvc:
        स्थिती TOK_ASM_bhi:
        स्थिती TOK_ASM_bls:
        स्थिती TOK_ASM_bge:
        स्थिती TOK_ASM_blt:
        स्थिती TOK_ASM_bgt:
        स्थिती TOK_ASM_ble:
            asm_branch(s1, opcode);
            थांबा;

        स्थिती TOK_ASM_cbz:
        स्थिती TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            थांबा;

        स्थिती TOK_ASM_movz:
        स्थिती TOK_ASM_movn:
        स्थिती TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            थांबा;

        स्थिती TOK_ASM_mrs:
        स्थिती TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            थांबा;

        स्थिती TOK_ASM_isb:
        स्थिती TOK_ASM_dsb:
        स्थिती TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            थांबा;

        स्थिती TOK_ASM_nop:
            gen_nop();
            थांबा;

        पूर्वनिर्धारित:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, रिक्त));
            थांबा;
    }
}

/* Substitute assembler operand */
ST_FUNC शून्य subst_asm_operand(CString *add_str, SValue *sv, पूर्णांक modifier)
{
    पूर्णांक r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    जर ((r & VT_VALMASK) == VT_CONST) {
        जर ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            परत;
        }
        जर (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        जर (r & VT_SYM) {
            स्थिरांक अक्षर *name = get_tok_str(sv->sym->v, रिक्त);
            जर (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, म_माप(name))->tok, sv->sym);
            जर (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            जर ((uint32_t) sv->c.i == 0)
                जा no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        जर (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (दीर्घ दीर्घ)val);
        } अन्यथा जर (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (अचिन्हित दीर्घ दीर्घ)uval);
        } अन्यथा {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (दीर्घ दीर्घ)val);
        }
      no_offset:;
    } अन्यथा जर ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (पूर्णांक) sv->c.i);
    } अन्यथा जर (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        जर (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } अन्यथा {
        /* register case */
        reg = r & VT_VALMASK;
        जर (reg >= VT_CONST)
            tcc_internal_error("");

        जर (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            जर (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            निवड (modifier) {
            स्थिती 'b':
            स्थिती 'h':
            स्थिती 's':
            स्थिती 'd':
            स्थिती 'q':
            स्थिती 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                परत;
            पूर्वनिर्धारित:
                tcc_error("invalid operand modifier for SIMD/FP register");
                परत;
            }
        }

        /* choose register operand size */
        जर ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        अन्यथा जर ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        अन्यथा जर ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        अन्यथा
            size = 4;

        जर (modifier == 'x') {
            size = 8;
        } अन्यथा जर (modifier == 'w' || modifier == 'k') {
            size = 4;
        } अन्यथा जर (modifier == 'b') {
            size = 1;
        } अन्यथा जर (modifier == 'h') {
            size = 2;
        } अन्यथा जर (modifier == 'q') {
            size = 8;
        }

        जर (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } अन्यथा {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC शून्य asm_gen_code(ASMOperand *operands, पूर्णांक nb_operands,
                          पूर्णांक nb_outputs, पूर्णांक is_output,
                          uint8_t *clobber_regs,
                          पूर्णांक out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    पूर्णांक i, reg, saved_मोजणी, चळत_size, चळत_off;
    पूर्णांक saved_regs[12];
    स्थिर स्थिरांक uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    स_नकल(regs_allocated, clobber_regs, आकार(regs_allocated));
    साठी (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        जर (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_मोजणी = 0;
    साठी (i = 0; i < आकार(reg_saved) / आकार(reg_saved[0]); i++) {
        reg = reg_saved[i];
        जर (regs_allocated[reg])
            saved_regs[saved_मोजणी++] = reg;
    }
    चळत_size = ((saved_मोजणी + 1) / 2) * 16;

    जर (!is_output) {
        जर (saved_मोजणी > 0) {
            gen_sub_imm(31, 31, चळत_size, 1, 0);

            साठी (i = चळत_off = 0; i < saved_मोजणी; ) {
                जर (i + 1 < saved_मोजणी) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, चळत_off, 3);
                    चळत_off += 16;
                    i += 2;
                } अन्यथा {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 चळत_off, 3);
                    i++;
                }
            }
        }

        साठी (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            जर (op->reg >= 0) {
                जर (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } अन्यथा जर (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } अन्यथा {
        साठी (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            जर (op->reg >= 0) {
                जर (op->is_memory)
                    सुरूठेवा;
                जर ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    जर (!op->is_memory) {
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

        जर (saved_मोजणी > 0) {
            साठी (i = चळत_off = 0; i < saved_मोजणी; ) {
                जर (i + 1 < saved_मोजणी) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, चळत_off, 3);
                    चळत_off += 16;
                    i += 2;
                } अन्यथा {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 चळत_off, 3);
                    i++;
                }
            }
            gen_add_imm(31, 31, चळत_size, 1, 0);
        }
    }
}

ST_FUNC शून्य asm_compute_constraints(ASMOperand *operands,
                                    पूर्णांक nb_operands, पूर्णांक nb_outputs,
                                    स्थिरांक uint8_t *clobber_regs,
                                    पूर्णांक *pout_reg)
{
    ASMOperand *op;
    पूर्णांक sorted_op[MAX_ASM_OPERANDS];
    पूर्णांक i, j, k, p1, p2, tmp, reg, c, reg_mask;
    स्थिरांक अक्षर *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    साठी (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->आदान_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    साठी (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        जर (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, रिक्त);
            जर ((अचिन्हित)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            जर (operands[k].आदान_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].आदान_index = i;
            op->priority = 5;
        } अन्यथा जर ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } अन्यथा {
            op->priority = constraint_priority(str);
        }
    }

    साठी (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    साठी (i = 0; i < nb_operands - 1; i++) {
        साठी (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            जर (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    साठी (i = 0; i < NB_ASM_REGS; i++) {
        जर (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        अन्यथा
            regs_allocated[i] = 0;
    }

    साठी (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        जर (op->ref_index >= 0)
            सुरूठेवा;
        जर (op->आदान_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अन्यथा जर (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अन्यथा {
            reg_mask = REG_IN_MASK;
        }
        जर (op->reg >= 0) {
            जर (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            जा reg_found;
        }
    try_next:
        c = *str++;
        निवड (c) {
        स्थिती '=':
            जा try_next;
        स्थिती '+':
            op->is_rw = 1;
        स्थिती '&':
            जर (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            जा try_next;
        स्थिती 'r':
            साठी (reg = 0; reg < 31; reg++) {
                जर (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    जा reg_found;
            }
            जा try_next;
        स्थिती 'w':
        स्थिती 'f':
            साठी (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                जर (!is_reg_allocated(reg))
                    जा reg_found;
            }
            जा try_next;
        स्थिती 'x':
        स्थिती 'y':
            साठी (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                जर (!is_reg_allocated(reg))
                    जा reg_found;
            }
            जा try_next;
        स्थिती 'm':
        स्थिती 'g':
            जर (j < nb_outputs || c == 'm') {
                जर (!arm64_prepare_memory_operand(op, regs_allocated))
                    जा try_next;
            }
            थांबा;
        स्थिती 'Q':
            जर (!arm64_memory_is_base_only(op->vt))
                जा try_next;
            जर (!arm64_prepare_memory_operand(op, regs_allocated))
                जा try_next;
            थांबा;
        स्थिती 'S':
            जर ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                जा try_next;
            थांबा;
        स्थिती 'U':
            जर (str[0] != 'm' || str[1] != 'p')
                जा try_next;
            str += 2;
            जर (!arm64_memory_is_pair_suitable(op->vt))
                जा try_next;
            जर (!arm64_prepare_memory_operand(op, regs_allocated))
                जा try_next;
            थांबा;
        स्थिती 'i':
            जर (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                जा try_next;
            थांबा;
        स्थिती 'I':
            जर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जा try_next;
            जर (!is_valid_add_imm(op->vt->c.i))
                जा try_next;
            थांबा;
        स्थिती 'J':
            जर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जा try_next;
            जर (!is_valid_add_imm(-op->vt->c.i))
                जा try_next;
            थांबा;
        स्थिती 'K':
            जर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जा try_next;
            जर (!is_valid_logical_imm(op->vt->c.i, 32))
                जा try_next;
            थांबा;
        स्थिती 'L':
            जर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जा try_next;
            जर (!is_valid_logical_imm(op->vt->c.i, 64))
                जा try_next;
            थांबा;
        स्थिती 'M':
        स्थिती 'N':
            जर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जा try_next;
            जर (!is_valid_movw_imm(op->vt->c.i))
                जा try_next;
            थांबा;
        स्थिती 'Z':
            जर (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                जा try_next;
            जर (op->vt->c.i != 0)
                जा try_next;
            थांबा;
        स्थिती 'n':
            जर (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                जा try_next;
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            थांबा;
        }
        जर (op->आदान_index >= 0) {
            operands[op->आदान_index].reg = op->reg;
            operands[op->आदान_index].is_llong = op->is_llong;
        }
        सुरूठेवा;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        जर (op->आदान_index >= 0) {
            operands[op->आदान_index].reg = op->reg;
            operands[op->आदान_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    साठी (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        जर (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            साठी (reg = 0; reg < 31; reg++) {
                जर (!(regs_allocated[reg] & REG_OUT_MASK))
                    जा reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            थांबा;
        }
    }
}

/* Handle clobber list */
ST_FUNC शून्य asm_clobber(uint8_t *clobber_regs, स्थिरांक अक्षर *str)
{
    पूर्णांक reg;

    जर (!म_भेद(str, "memory") ||
        !म_भेद(str, "cc") ||
        !म_भेद(str, "flags"))
        परत;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    जर (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC पूर्णांक asm_parse_regvar(पूर्णांक t)
{
    परत arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
