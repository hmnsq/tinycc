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

ST_FUNC வெறுமை g(முழு c);
ST_FUNC வெறுமை gen_le16(முழு c);
ST_FUNC வெறுமை gen_le32(முழு c);

/*************************************************************/
#இல்லையெனில்
/*************************************************************/

#define USING_GLOBALS
#அந்தர்பாவ "tcc.h"

/* Register type flags */
#define REG_X     0x01  /* 64-bit general purpose */
#define REG_W     0x02  /* 32-bit general purpose */
#define REG_V     0x04  /* 128-bit SIMD */
#define REG_D     0x08  /* 64-bit FP */
#define REG_S     0x10  /* 32-bit FP */
#define REG_H     0x20  /* 16-bit FP */
#define REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
எண்ணிக்கை {
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

வகைவரை கட்டமைப்பு Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    முழு reg_tok;
    கோவை_மதிப்பு e;
} Operand;

எண்ணிக்கை {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
நிலையான வெறுமை parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC வெறுமை g(முழு c)
{
    முழு ind1;
    எனில் (nocode_wanted)
        திரும்பு;
    ind1 = ind + 1;
    எனில் (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC வெறுமை gen_le16(முழு c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC வெறுமை gen_le32(முழு c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC வெறுமை gen_expr32(கோவை_மதிப்பு *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
நிலையான வெறுமை emit_instr32(uint32_t val)
{
    எனில் (nocode_wanted)
        திரும்பு;
    எனில் (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
நிலையான முழு arm64_parse_asm_reg(முழு t)
{
    /* X registers (64-bit) */
    எனில் (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        திரும்பு t - TOK_ASM_x0;
    /* W registers (32-bit) */
    எனில் (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        திரும்பு t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    எனில் (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        திரும்பு (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    எனில் (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        திரும்பு (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    எனில் (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        திரும்பு (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    எனில் (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        திரும்பு (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    எனில் (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        திரும்பு (t - TOK_ASM_b0) + 32;
    /* Special registers */
    எனில் (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        திரும்பு 31;  /* SP/ZR encoded as 31 */
    திரும்பு -1;
}

/* Get register type from token */
நிலையான uint8_t get_reg_type(முழு t)
{
    எனில் (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        திரும்பு REG_X;
    எனில் (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        திரும்பு REG_W;
    எனில் (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        திரும்பு REG_V;
    எனில் (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        திரும்பு REG_D;
    எனில் (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        திரும்பு REG_S;
    எனில் (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        திரும்பு REG_H;
    எனில் (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        திரும்பு REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    எனில் (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        திரும்பு REG_X;
    எனில் (t == TOK_ASM_wzr)
        திரும்பு REG_W;
    திரும்பு REG_X;
}

/* Parse condition code */
நிலையான முழு parse_condition(முழு t)
{
    தேர்வு (t) {
        நிலை TOK_ASM_eq: திரும்பு 0;
        நிலை TOK_ASM_ne: திரும்பு 1;
        நிலை TOK_ASM_cs:
        நிலை TOK_ASM_hs: திரும்பு 2;
        நிலை TOK_ASM_cc:
        நிலை TOK_ASM_lo: திரும்பு 3;
        நிலை TOK_ASM_mi: திரும்பு 4;
        நிலை TOK_ASM_pl: திரும்பு 5;
        நிலை TOK_ASM_vs: திரும்பு 6;
        நிலை TOK_ASM_vc: திரும்பு 7;
        நிலை TOK_ASM_hi: திரும்பு 8;
        நிலை TOK_ASM_ls: திரும்பு 9;
        நிலை TOK_ASM_ge: திரும்பு 10;
        நிலை TOK_ASM_lt: திரும்பு 11;
        நிலை TOK_ASM_gt: திரும்பு 12;
        நிலை TOK_ASM_le: திரும்பு 13;
        நிலை TOK_ASM_al: திரும்பு 14;
        இயல்பு: திரும்பு -1;
    }
}

நிலையான முழு parse_barrier_option_name(முழு t)
{
    மாறிலி எழுத்து *name;

    எனில் (t < TOK_IDENT)
        திரும்பு -1;
    name = get_tok_str(t, வெற்று);
    எனில் (!strcmp(name, "oshld")) திரும்பு 0x1;
    எனில் (!strcmp(name, "oshst")) திரும்பு 0x2;
    எனில் (!strcmp(name, "osh"))   திரும்பு 0x3;
    எனில் (!strcmp(name, "nshld")) திரும்பு 0x5;
    எனில் (!strcmp(name, "nshst")) திரும்பு 0x6;
    எனில் (!strcmp(name, "nsh"))   திரும்பு 0x7;
    எனில் (!strcmp(name, "ishld")) திரும்பு 0x9;
    எனில் (!strcmp(name, "ishst")) திரும்பு 0xA;
    எனில் (!strcmp(name, "ish"))   திரும்பு 0xB;
    எனில் (!strcmp(name, "ld"))    திரும்பு 0xD;
    எனில் (!strcmp(name, "st"))    திரும்பு 0xE;
    எனில் (!strcmp(name, "sy"))    திரும்பு 0xF;
    திரும்பு -1;
}

நிலையான முழு arm64_parse_regvar(முழு t)
{
    எனில் (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        திரும்பு t - TOK_ASM_x0;
    எனில் (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        திரும்பு ARM64_FREG_BASE + (t - TOK_ASM_v0);
    எனில் (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        திரும்பு ARM64_FREG_BASE + (t - TOK_ASM_d0);
    எனில் (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        திரும்பு ARM64_FREG_BASE + (t - TOK_ASM_s0);
    எனில் (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        திரும்பு ARM64_FREG_BASE + (t - TOK_ASM_h0);
    எனில் (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        திரும்பு ARM64_FREG_BASE + (t - TOK_ASM_b0);
    திரும்பு -1;
}

/* Parse a single operand */
நிலையான வெறுமை parse_operand(TCCState *s1, Operand *op)
{
    முழு reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    எனில் (tok == '[') {
        parse_addr_operand(s1, op);
        திரும்பு;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    எனில் (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        திரும்பு;
    }

    /* Condition code */
    reg = parse_condition(tok);
    எனில் (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        திரும்பு;
    }

    /* Immediate or address expression */
    எனில் (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_கோவை(s1, &op->e);
        op->type = OP_IM;
    } இல்லையெனில் எனில் (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } இல்லையெனில் {
        asm_கோவை(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
நிலையான வெறுமை parse_கோவை_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    எனில் (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_கோவை(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
நிலையான வெறுமை parse_addr_operand(TCCState *s1, Operand *op)
{
    முழு reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = வெற்று;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    எனில் (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        திரும்பு;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    எனில் (tok == ',') {
        next();
        எனில் (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_கோவை(s1, &op->e);
    }
    skip(']');
    எனில் (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } இல்லையெனில் எனில் (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        எனில் (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_கோவை(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
நிலையான வெறுமை gen_mov_with_base(முழு rd, uint16_t imm, முழு shift,
                              முழு is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    எனில் (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

நிலையான வெறுமை gen_movz(முழு rd, uint16_t imm, முழு shift, முழு is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
நிலையான வெறுமை gen_movn(முழு rd, uint16_t imm, முழு shift, முழு is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
நிலையான வெறுமை gen_movk(முழு rd, uint16_t imm, முழு shift, முழு is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
நிலையான வெறுமை gen_add_imm(முழு rd, முழு rn, uint32_t imm, முழு is_64bit, முழு setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    எனில் (is_64bit) instr |= ARM64_SF(1);
    எனில் (setflags) instr |= ARM64_S(1);

    எனில் (imm <= 0xFFF) {
        imm12 = imm;
    } இல்லையெனில் எனில் (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } இல்லையெனில் {
        tcc_error("add immediate out of range");
        திரும்பு;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
நிலையான வெறுமை gen_sub_imm(முழு rd, முழு rn, uint32_t imm, முழு is_64bit, முழு setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    எனில் (is_64bit) instr |= ARM64_SF(1);
    எனில் (setflags) instr |= ARM64_S(1);

    எனில் (imm <= 0xFFF) {
        imm12 = imm;
    } இல்லையெனில் எனில் (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } இல்லையெனில் {
        tcc_error("sub immediate out of range");
        திரும்பு;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
நிலையான வெறுமை gen_dp_reg(uint32_t opcode, முழு rd, முழு rn, முழு rm, முழு is_64bit)
{
    uint32_t instr = opcode;
    எனில் (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
நிலையான வெறுமை gen_ldst_imm(uint32_t base_opcode, முழு rt, முழு rn,
                         int32_t offset, முழு size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    எனில் (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        எனில் (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            திரும்பு;
        }
    }

    தேர்வு (base_opcode) {
    நிலை ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; நிறுத்து;
    நிலை ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; நிறுத்து;
    நிலை ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; நிறுத்து;
    நிலை ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; நிறுத்து;
    நிலை ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; நிறுத்து;
    நிலை ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; நிறுத்து;
    நிலை ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; நிறுத்து;
    நிலை ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; நிறுத்து;
    நிலை ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; நிறுத்து;
    நிலை ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; நிறுத்து;
    }

    எனில் (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        திரும்பு;
    }

    எனில் (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
நிலையான வெறுமை gen_ldst_pair(uint32_t base_opcode, முழு rt, முழு rt2, முழு rn,
                          int32_t offset, முழு size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    எனில் (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    எனில் (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
நிலையான வெறுமை gen_b_or_bl(int32_t offset, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    instr |= ARM64_OFFSET26(offset);
    emit_instr32(instr);
}

நிலையான வெறுமை gen_b(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_B);
}

/* Generate BL (branch with link) */
நிலையான வெறுமை gen_bl(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_BL);
}

/* Generate BR (branch to register) */
நிலையான வெறுமை gen_br(முழு rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
நிலையான வெறுமை gen_blr(முழு rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
நிலையான வெறுமை gen_ret(முழு rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
நிலையான வெறுமை gen_b_cond(முழு cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
நிலையான வெறுமை gen_cbz_or_cbnz(முழு rt, int32_t offset, முழு is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    எனில் (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

நிலையான வெறுமை gen_cbz(முழு rt, int32_t offset, முழு is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
நிலையான வெறுமை gen_cbnz(முழு rt, int32_t offset, முழு is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
நிலையான வெறுமை gen_mov_reg(முழு rd, முழு rm, முழு is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    எனில் (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

நிலையான முழு arm64_asm_encode_bimm64(uint64_t x)
{
    முழு neg, rep, pos, len;

    neg = x & 1;
    எனில் (neg)
        x = ~x;
    எனில் (!x)
        திரும்பு -1;

    எனில் (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    இல்லையெனில் எனில் (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    இல்லையெனில் எனில் (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    இல்லையெனில் எனில் (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    இல்லையெனில் எனில் (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    இல்லையெனில்
        rep = 64;

    pos = 0;
    எனில் (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    எனில் (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    எனில் (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    எனில் (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    எனில் (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    எனில் (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    எனில் (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    எனில் (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    எனில் (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    எனில் (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    எனில் (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    எனில் (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    எனில் (x)
        திரும்பு -1;
    எனில் (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    திரும்பு ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

நிலையான வெறுமை gen_logical_imm(uint32_t opcode, முழு rd, முழு rn,
                            uint64_t imm, முழு is_64bit)
{
    uint32_t instr;
    uint64_t val;
    முழு enc;

    எனில் (is_64bit)
        val = imm;
    இல்லையெனில் {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    எனில் (enc < 0) {
        tcc_error("logical immediate out of range");
        திரும்பு;
    }

    instr = opcode;
    எனில் (is_64bit)
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
நிலையான உள்வரி முழு constraint_priority(மாறிலி எழுத்து *str)
{
    முழு priority, c, pr;

    priority = 0;
    க்கு (;;) {
        c = *str++;
        எனில் (c == '\0')
            நிறுத்து;
        தேர்வு (c) {
        நிலை '=':
        நிலை '+':
        நிலை '&':
            தொடர்;
        நிலை 'r':
            pr = 1;
            நிறுத்து;
        நிலை 'w':
        நிலை 'f':
        நிலை 'x':
        நிலை 'y':
            pr = 3;
            நிறுத்து;
        நிலை 'm':
        நிலை 'Q':
            pr = 4;
            நிறுத்து;
        நிலை 'i':
        நிலை 'S':
            pr = 5;
            நிறுத்து;
        நிலை 'U':
            எனில் (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                நிறுத்து;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            நிறுத்து;
        நிலை 'I':
        நிலை 'J':
        நிலை 'K':
        நிலை 'L':
        நிலை 'M':
        நிலை 'N':
        நிலை 'Z':
            pr = 6;
            நிறுத்து;
        நிலை 'n':
            pr = 7;
            நிறுத்து;
        நிலை 'g':
            pr = 8;
            நிறுத்து;
        இயல்பு:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            நிறுத்து;
        }
        எனில் (pr > priority)
            priority = pr;
    }
    திரும்பு priority;
}

நிலையான மாறிலி எழுத்து *skip_constraint_modifiers(மாறிலி எழுத்து *p)
{
    போது (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    திரும்பு p;
}

நிலையான முழு is_valid_add_imm(int64_t val)
{
    திரும்பு val >= 0 && val <= 4095;
}

நிலையான முழு is_valid_logical_imm(int64_t val, முழு bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    எனில் (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    திரும்பு arm64_asm_encode_bimm64(uval) >= 0;
}

நிலையான முழு is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    எனில் (uval <= 0xFFFF)
        திரும்பு 1;
    எனில் (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        திரும்பு 1;
    எனில் (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        திரும்பு 1;
    எனில் ((uval & 0xFFFFFFFF00000000ULL) == 0)
        திரும்பு 1;

    திரும்பு 0;
}

நிலையான முழு is_valid_movw_shift(முழு shift, முழு is_64bit)
{
    எனில் (shift < 0 || (shift & 15))
        திரும்பு 0;
    எனில் (shift > (is_64bit ? 48 : 16))
        திரும்பு 0;
    திரும்பு 1;
}

நிலையான முழு arm64_memory_is_base_only(மாறிலி SValue *sv)
{
    முழு r;

    r = sv->r;
    எனில் ((r & VT_VALMASK) == VT_CONST)
        திரும்பு 0;
    எனில் ((r & VT_VALMASK) == VT_LOCAL)
        திரும்பு 0;
    எனில் ((r & VT_VALMASK) == VT_LLOCAL)
        திரும்பு 1;
    எனில் (r & VT_LVAL)
        திரும்பு (r & VT_VALMASK) < VT_CONST;
    திரும்பு 0;
}

நிலையான முழு arm64_memory_is_pair_suitable(மாறிலி SValue *sv)
{
    int64_t offset;

    எனில் (arm64_memory_is_base_only(sv))
        திரும்பு 1;
    எனில் ((sv->r & VT_VALMASK) != VT_LOCAL)
        திரும்பு 0;

    offset = (int64_t)sv->c.i;
    திரும்பு (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

நிலையான முழு arm64_int_reg_is_allocatable(முழு reg)
{
#ifdef TCC_TARGET_PE
    திரும்பு reg >= TREG_X0 && reg <= TREG_X17;
#இல்லையெனில்
    திரும்பு reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

நிலையான முழு arm64_memory_needs_address_reg(மாறிலி SValue *sv)
{
    முழு r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    எனில் (!(r & VT_LVAL))
        திரும்பு 0;
    தேர்வு (r & VT_VALMASK) {
    நிலை VT_LOCAL:
    நிலை VT_LLOCAL:
    நிலை VT_CONST:
        திரும்பு 1;
    }
    திரும்பு 0;
}

நிலையான முழு arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    முழு reg;

    எனில் (!arm64_memory_needs_address_reg(op->vt))
        திரும்பு 1;

    க்கு (reg = 0; reg < 31; reg++) {
        எனில் (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            திரும்பு 1;
        }
    }
    திரும்பு 0;
}

நிலையான வெறுமை arm64_load_memory_operand_base(முழு reg, SValue *sv)
{
    SValue base;
    முழு rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    எனில் (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } இல்லையெனில் எனில் (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } இல்லையெனில் {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

நிலையான முழு operand_is_sp(மாறிலி Operand *op)
{
    திரும்பு op->reg_tok == TOK_ASM_sp;
}

நிலையான முழு parse_sysreg_name(முழு t)
{
    மாறிலி எழுத்து *name;

    எனில் (t < TOK_IDENT)
        திரும்பு -1;
    name = get_tok_str(t, வெற்று);
    எனில் (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        திரும்பு 0;
    எனில் (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        திரும்பு 1;
    திரும்பு -1;
}

நிலையான வெறுமை gen_mrs(முழு rt, முழு sysreg)
{
    uint32_t instr;

    தேர்வு (sysreg) {
        நிலை 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            நிறுத்து;
        நிலை 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            நிறுத்து;
        இயல்பு:
            tcc_error("unsupported system register");
            திரும்பு;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

நிலையான வெறுமை gen_msr(முழு rt, முழு sysreg)
{
    uint32_t instr;

    தேர்வு (sysreg) {
        நிலை 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            நிறுத்து;
        நிலை 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            நிறுத்து;
        இயல்பு:
            tcc_error("unsupported system register");
            திரும்பு;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
நிலையான வெறுமை gen_nop(வெறுமை)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
நிலையான வெறுமை gen_shift(முழு rd, முழு rn, முழு rm_or_imm, முழு shift_type, முழு is_imm, முழு is_64bit)
{
    uint32_t instr;
    முழு width = is_64bit ? 64 : 32;

    எனில் (is_imm) {
        /* Shift by immediate */
        தேர்வு (shift_type) {
            நிலை 0: /* LSL - UBFM alias */
                எனில் (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    திரும்பு;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                நிறுத்து;
            நிலை 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                எனில் (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    திரும்பு;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                நிறுத்து;
            நிலை 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                எனில் (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    திரும்பு;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                நிறுத்து;
            நிலை 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                எனில் (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    திரும்பு;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                திரும்பு;
            இயல்பு:
                tcc_error("unknown shift type");
                திரும்பு;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } இல்லையெனில் {
        /* Shift by register */
        தேர்வு (shift_type) {
            நிலை 0: /* LSL */
                instr = ARM64_LSL_REG;
                நிறுத்து;
            நிலை 1: /* LSR */
                instr = ARM64_LSR_REG;
                நிறுத்து;
            நிலை 2: /* ASR */
                instr = ARM64_ASR_REG;
                நிறுத்து;
            நிலை 3: /* ROR */
                instr = ARM64_ROR_REG;
                நிறுத்து;
            இயல்பு:
                tcc_error("unknown shift type");
                திரும்பு;
        }
        எனில் (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
நிலையான வெறுமை asm_shift(TCCState *s1, முழு token)
{
    Operand op1, op2, op3;
    முழு rd, rn, shift_amount;
    முழு shift_type;
    முழு is_64bit = 1;

    தேர்வு (token) {
        நிலை TOK_ASM_lsl:
            shift_type = 0;
            நிறுத்து;
        நிலை TOK_ASM_lsr:
            shift_type = 1;
            நிறுத்து;
        நிலை TOK_ASM_asr:
            shift_type = 2;
            நிறுத்து;
        நிலை TOK_ASM_ror:
            shift_type = 3;
            நிறுத்து;
        இயல்பு:
            tcc_error("unknown shift instruction");
            திரும்பு;
    }

    parse_operand(s1, &op1);
    எனில் (tok == ',') next();
    parse_operand(s1, &op2);

    எனில் (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        திரும்பு;
    }
    எனில் (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        திரும்பு;
    }

    rd = op1.reg;
    rn = op2.reg;

    எனில் (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        எனில் (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            திரும்பு;
        }
        எனில் (op3.type & OP_REG) {
            எனில் (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                திரும்பு;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } இல்லையெனில் எனில் (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } இல்லையெனில் {
            tcc_error("shift requires immediate or register operand");
        }
    } இல்லையெனில் {
        tcc_error("shift requires immediate or register operand");
        திரும்பு;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
நிலையான வெறுமை gen_barrier(முழு barrier_type, முழு option)
{
    uint32_t instr;

    தேர்வு (barrier_type) {
        நிலை 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            நிறுத்து;
        நிலை 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            நிறுத்து;
        நிலை 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            நிறுத்து;
        இயல்பு:
            tcc_error("unknown barrier type");
            திரும்பு;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
நிலையான வெறுமை asm_barrier(TCCState *s1, முழு token)
{
    முழு barrier_type, option;
    Operand op;

    தேர்வு (token) {
        நிலை TOK_ASM_isb:
            barrier_type = 0;
            நிறுத்து;
        நிலை TOK_ASM_dsb:
            barrier_type = 1;
            நிறுத்து;
        நிலை TOK_ASM_dmb:
            barrier_type = 2;
            நிறுத்து;
        இயல்பு:
            tcc_error("unknown barrier instruction");
            திரும்பு;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    எனில் (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        எனில் (option >= 0) {
            next();
        } இல்லையெனில் {
            parse_operand(s1, &op);
            எனில் (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                திரும்பு;
            }
            எனில் (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                திரும்பு;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
நிலையான வெறுமை gen_mov_imm(முழு rd, uint64_t imm, முழு is_64bit)
{
    uint16_t hw;
    முழு i, first = 1;

    க்கு (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        எனில் (hw != 0 || i == 0) {
            எனில் (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } இல்லையெனில் {
                gen_movk(rd, hw, i, is_64bit);
            }
        } இல்லையெனில் எனில் (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
நிலையான வெறுமை asm_mov(TCCState *s1)
{
    Operand op1, op2;
    முழு rd, rn;
    முழு is_64bit;

    parse_operand(s1, &op1);
    எனில் (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    எனில் (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        எனில் (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            திரும்பு;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } இல்லையெனில் எனில் (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        எனில் (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        இல்லையெனில்
            gen_mov_reg(rd, rn, is_64bit);
    } இல்லையெனில் {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
நிலையான வெறுமை asm_data_proc(TCCState *s1, முழு token)
{
    Operand op1, op2, op3;
    முழு rd, rn, rm;
    முழு is_64bit = 1;
    uint32_t opcode;

    தேர்வு (token) {
        நிலை TOK_ASM_add:
        நிலை TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            நிறுத்து;
        நிலை TOK_ASM_sub:
        நிலை TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            நிறுத்து;
        நிலை TOK_ASM_and:
        நிலை TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            நிறுத்து;
        நிலை TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            நிறுத்து;
        நிலை TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            நிறுத்து;
        நிலை TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            நிறுத்து;
        இயல்பு:
            tcc_error("unsupported data processing instruction");
            திரும்பு;
    }

    parse_operand(s1, &op1);
    எனில் (tok == ',') next();
    parse_operand(s1, &op2);

    எனில் (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        திரும்பு;
    }
    எனில் (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        திரும்பு;
    }

    rd = op1.reg;
    rn = op2.reg;

    எனில் (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        எனில் (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            திரும்பு;
        }
        எனில் (op3.type & OP_IM) {
            எனில் (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            இல்லையெனில் எனில் (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            இல்லையெனில் எனில் (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            இல்லையெனில் எனில் (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            இல்லையெனில் எனில் (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            இல்லையெனில் எனில் (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            இல்லையெனில்
                tcc_error("immediate operand not valid for this instruction");
        } இல்லையெனில் {
            எனில் (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                திரும்பு;
            }
            rm = op3.reg;
            எனில் (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                திரும்பு;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } இல்லையெனில் எனில் (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } இல்லையெனில் {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
நிலையான வெறுமை asm_ldst(TCCState *s1, முழு token)
{
    Operand op1, op2;
    முழு rt, rn;
    int32_t offset = 0;
    முழு size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    எனில் (tok == ',') next();
    parse_operand(s1, &op2);

    எனில் (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        திரும்பு;
    }
    எனில் (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        திரும்பு;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    தேர்வு (token) {
        நிலை TOK_ASM_ldr:
            எனில் (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } இல்லையெனில் எனில் (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } இல்லையெனில் எனில் (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } இல்லையெனில் {
                tcc_error("ldr requires a w, x, or d register");
                திரும்பு;
            }
            நிறுத்து;
        நிலை TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            நிறுத்து;
        நிலை TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            நிறுத்து;
        நிலை TOK_ASM_str:
            எனில் (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } இல்லையெனில் எனில் (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } இல்லையெனில் எனில் (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } இல்லையெனில் {
                tcc_error("str requires a w, x, or d register");
                திரும்பு;
            }
            நிறுத்து;
        நிலை TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            நிறுத்து;
        நிலை TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            நிறுத்து;
        இயல்பு:
            tcc_error("unsupported load/store instruction");
            திரும்பு;
    }

    எனில் (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

நிலையான வெறுமை asm_ldst_pair(TCCState *s1, முழு token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    முழு size_log2 = 3;

    parse_operand(s1, &op1);
    எனில் (tok == ',')
        next();
    parse_operand(s1, &op2);
    எனில் (tok == ',')
        next();
    parse_operand(s1, &op3);

    எனில் (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        திரும்பு;
    }
    எனில் (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        திரும்பு;
    }
    எனில் (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    எனில் ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        எனில் (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } இல்லையெனில் {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } இல்லையெனில் எனில் ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        எனில் (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } இல்லையெனில் {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } இல்லையெனில் {
        tcc_error("stp/ldp requires matching x or d registers");
        திரும்பு;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

நிலையான வெறுமை asm_sysreg(TCCState *s1, முழு token)
{
    Operand op;
    முழு sysreg;

    எனில் (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        எனில் (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        எனில் (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        திரும்பு;
    }

    sysreg = parse_sysreg_name(tok);
    எனில் (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    எனில் (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
நிலையான முழு get_branch_condition(முழு branch_token)
{
    முழு cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    தேர்வு (branch_token) {
        நிலை TOK_ASM_beq: cond_token = TOK_ASM_eq; நிறுத்து;
        நிலை TOK_ASM_bne: cond_token = TOK_ASM_ne; நிறுத்து;
        நிலை TOK_ASM_bcs:
        நிலை TOK_ASM_bhs: cond_token = TOK_ASM_cs; நிறுத்து;
        நிலை TOK_ASM_bcc:
        நிலை TOK_ASM_blo: cond_token = TOK_ASM_cc; நிறுத்து;
        நிலை TOK_ASM_bmi: cond_token = TOK_ASM_mi; நிறுத்து;
        நிலை TOK_ASM_bpl: cond_token = TOK_ASM_pl; நிறுத்து;
        நிலை TOK_ASM_bvs: cond_token = TOK_ASM_vs; நிறுத்து;
        நிலை TOK_ASM_bvc: cond_token = TOK_ASM_vc; நிறுத்து;
        நிலை TOK_ASM_bhi: cond_token = TOK_ASM_hi; நிறுத்து;
        நிலை TOK_ASM_bls: cond_token = TOK_ASM_ls; நிறுத்து;
        நிலை TOK_ASM_bge: cond_token = TOK_ASM_ge; நிறுத்து;
        நிலை TOK_ASM_blt: cond_token = TOK_ASM_lt; நிறுத்து;
        நிலை TOK_ASM_bgt: cond_token = TOK_ASM_gt; நிறுத்து;
        நிலை TOK_ASM_ble: cond_token = TOK_ASM_le; நிறுத்து;
        இயல்பு: திரும்பு -1;
    }

    திரும்பு parse_condition(cond_token);
}

/* Handle branch instructions */
நிலையான வெறுமை asm_branch(TCCState *s1, முழு token)
{
    Operand op;
    முழு cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    எனில் (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        திரும்பு;
    }

    எனில் (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    இல்லையெனில்
        parse_கோவை_operand(s1, &op);

    எனில் (op.type & OP_IM) {
        sym = op.e.sym;
        எனில் (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            எனில் (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } இல்லையெனில் {
                தேர்வு (token) {
                    நிலை TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        நிறுத்து;
                    நிலை TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        நிறுத்து;
                    இயல்பு:
                        tcc_error("unsupported branch");
                }
            }
        } இல்லையெனில் {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            எனில் (cond >= 0) {
                gen_b_cond(cond, offset);
            } இல்லையெனில் {
                தேர்வு (token) {
                    நிலை TOK_ASM_b:
                        gen_b(offset);
                        நிறுத்து;
                    நிலை TOK_ASM_bl:
                        gen_bl(offset);
                        நிறுத்து;
                    இயல்பு:
                        tcc_error("unsupported branch");
                }
            }
        }
    } இல்லையெனில் எனில் (op.type & OP_REG) {
        தேர்வு (token) {
            நிலை TOK_ASM_br:
                gen_br(op.reg);
                நிறுத்து;
            நிலை TOK_ASM_blr:
                gen_blr(op.reg);
                நிறுத்து;
            நிலை TOK_ASM_ret:
                gen_ret(op.reg);
                நிறுத்து;
            இயல்பு:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
நிலையான வெறுமை asm_cb(TCCState *s1, முழு token)
{
    Operand op1, op2;
    முழு rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    எனில் (tok == ',') next();
    parse_கோவை_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    எனில் (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        எனில் (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } இல்லையெனில் {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } இல்லையெனில் {
        offset = (int32_t)op2.e.v - ind;
        எனில் (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        இல்லையெனில்
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
நிலையான வெறுமை asm_move_wide(TCCState *s1, முழு token)
{
    Operand op1, op2;
    முழு rd, is_64bit = 1;
    uint16_t imm;
    முழு shift = 0;

    parse_operand(s1, &op1);
    எனில் (tok == ',') next();
    parse_operand(s1, &op2);

    எனில் (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        திரும்பு;
    }
    எனில் (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        திரும்பு;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    எனில் ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        திரும்பு;
    }
    imm = op2.e.v;

    எனில் (tok == ',') {
        next();
        எனில் (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            திரும்பு;
        }
            next();
            எனில் (tok == '#') next();
            asm_கோவை(s1, &op2.e);
        எனில் (op2.e.sym || !is_valid_movw_shift((முழு)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            திரும்பு;
        }
            shift = (முழு)op2.e.v / 16;
        }

    தேர்வு (token) {
        நிலை TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            நிறுத்து;
        நிலை TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            நிறுத்து;
        நிலை TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            நிறுத்து;
        இயல்பு:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC வெறுமை asm_opcode(TCCState *s1, முழு opcode)
{
    தேர்வு (opcode) {
        நிலை TOK_ASM_add:
        நிலை TOK_ASM_adds:
        நிலை TOK_ASM_sub:
        நிலை TOK_ASM_subs:
        நிலை TOK_ASM_and:
        நிலை TOK_ASM_ands:
        நிலை TOK_ASM_orr:
        நிலை TOK_ASM_eor:
        நிலை TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            நிறுத்து;

        நிலை TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            நிறுத்து;

        நிலை TOK_ASM_lsl:
        நிலை TOK_ASM_lsr:
        நிலை TOK_ASM_asr:
        நிலை TOK_ASM_ror:
            asm_shift(s1, opcode);
            நிறுத்து;

        நிலை TOK_ASM_ldr:
        நிலை TOK_ASM_ldrb:
        நிலை TOK_ASM_ldrh:
        நிலை TOK_ASM_str:
        நிலை TOK_ASM_strb:
        நிலை TOK_ASM_strh:
            asm_ldst(s1, opcode);
            நிறுத்து;

        நிலை TOK_ASM_ldp:
        நிலை TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            நிறுத்து;

        நிலை TOK_ASM_b:
        நிலை TOK_ASM_bl:
        நிலை TOK_ASM_br:
        நிலை TOK_ASM_blr:
        நிலை TOK_ASM_ret:
        நிலை TOK_ASM_beq:
        நிலை TOK_ASM_bne:
        நிலை TOK_ASM_bcs:
        நிலை TOK_ASM_bhs:
        நிலை TOK_ASM_bcc:
        நிலை TOK_ASM_blo:
        நிலை TOK_ASM_bmi:
        நிலை TOK_ASM_bpl:
        நிலை TOK_ASM_bvs:
        நிலை TOK_ASM_bvc:
        நிலை TOK_ASM_bhi:
        நிலை TOK_ASM_bls:
        நிலை TOK_ASM_bge:
        நிலை TOK_ASM_blt:
        நிலை TOK_ASM_bgt:
        நிலை TOK_ASM_ble:
            asm_branch(s1, opcode);
            நிறுத்து;

        நிலை TOK_ASM_cbz:
        நிலை TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            நிறுத்து;

        நிலை TOK_ASM_movz:
        நிலை TOK_ASM_movn:
        நிலை TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            நிறுத்து;

        நிலை TOK_ASM_mrs:
        நிலை TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            நிறுத்து;

        நிலை TOK_ASM_isb:
        நிலை TOK_ASM_dsb:
        நிலை TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            நிறுத்து;

        நிலை TOK_ASM_nop:
            gen_nop();
            நிறுத்து;

        இயல்பு:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, வெற்று));
            நிறுத்து;
    }
}

/* Substitute assembler operand */
ST_FUNC வெறுமை subst_asm_operand(CString *add_str, SValue *sv, முழு modifier)
{
    முழு r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    எனில் ((r & VT_VALMASK) == VT_CONST) {
        எனில் ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            திரும்பு;
        }
        எனில் (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        எனில் (r & VT_SYM) {
            மாறிலி எழுத்து *name = get_tok_str(sv->sym->v, வெற்று);
            எனில் (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            எனில் (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            எனில் ((uint32_t) sv->c.i == 0)
                செல் no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        எனில் (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } இல்லையெனில் எனில் (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } இல்லையெனில் {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } இல்லையெனில் எனில் ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (முழு) sv->c.i);
    } இல்லையெனில் எனில் (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        எனில் (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } இல்லையெனில் {
        /* register case */
        reg = r & VT_VALMASK;
        எனில் (reg >= VT_CONST)
            tcc_internal_error("");

        எனில் (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            எனில் (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            தேர்வு (modifier) {
            நிலை 'b':
            நிலை 'h':
            நிலை 's':
            நிலை 'd':
            நிலை 'q':
            நிலை 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                திரும்பு;
            இயல்பு:
                tcc_error("invalid operand modifier for SIMD/FP register");
                திரும்பு;
            }
        }

        /* choose register operand size */
        எனில் ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        இல்லையெனில் எனில் ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        இல்லையெனில் எனில் ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        இல்லையெனில்
            size = 4;

        எனில் (modifier == 'x') {
            size = 8;
        } இல்லையெனில் எனில் (modifier == 'w' || modifier == 'k') {
            size = 4;
        } இல்லையெனில் எனில் (modifier == 'b') {
            size = 1;
        } இல்லையெனில் எனில் (modifier == 'h') {
            size = 2;
        } இல்லையெனில் எனில் (modifier == 'q') {
            size = 8;
        }

        எனில் (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } இல்லையெனில் {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC வெறுமை asm_gen_code(ASMOperand *operands, முழு nb_operands,
                          முழு nb_outputs, முழு is_output,
                          uint8_t *clobber_regs,
                          முழு out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    முழு i, reg, saved_மொத்தம், அடுக்கு_size, அடுக்கு_off;
    முழு saved_regs[12];
    நிலையான மாறிலி uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, அளவு(regs_allocated));
    க்கு (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        எனில் (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_மொத்தம் = 0;
    க்கு (i = 0; i < அளவு(reg_saved) / அளவு(reg_saved[0]); i++) {
        reg = reg_saved[i];
        எனில் (regs_allocated[reg])
            saved_regs[saved_மொத்தம்++] = reg;
    }
    அடுக்கு_size = ((saved_மொத்தம் + 1) / 2) * 16;

    எனில் (!is_output) {
        எனில் (saved_மொத்தம் > 0) {
            gen_sub_imm(31, 31, அடுக்கு_size, 1, 0);

            க்கு (i = அடுக்கு_off = 0; i < saved_மொத்தம்; ) {
                எனில் (i + 1 < saved_மொத்தம்) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, அடுக்கு_off, 3);
                    அடுக்கு_off += 16;
                    i += 2;
                } இல்லையெனில் {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 அடுக்கு_off, 3);
                    i++;
                }
            }
        }

        க்கு (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            எனில் (op->reg >= 0) {
                எனில் (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } இல்லையெனில் எனில் (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } இல்லையெனில் {
        க்கு (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            எனில் (op->reg >= 0) {
                எனில் (op->is_memory)
                    தொடர்;
                எனில் ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    எனில் (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } இல்லையெனில் {
                    store(op->reg, op->vt);
                }
            }
        }

        எனில் (saved_மொத்தம் > 0) {
            க்கு (i = அடுக்கு_off = 0; i < saved_மொத்தம்; ) {
                எனில் (i + 1 < saved_மொத்தம்) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, அடுக்கு_off, 3);
                    அடுக்கு_off += 16;
                    i += 2;
                } இல்லையெனில் {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 அடுக்கு_off, 3);
                    i++;
                }
            }
            gen_add_imm(31, 31, அடுக்கு_size, 1, 0);
        }
    }
}

ST_FUNC வெறுமை asm_compute_constraints(ASMOperand *operands,
                                    முழு nb_operands, முழு nb_outputs,
                                    மாறிலி uint8_t *clobber_regs,
                                    முழு *pout_reg)
{
    ASMOperand *op;
    முழு sorted_op[MAX_ASM_OPERANDS];
    முழு i, j, k, p1, p2, tmp, reg, c, reg_mask;
    மாறிலி எழுத்து *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    க்கு (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->உள்ளீடு_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    க்கு (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        எனில் (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, வெற்று);
            எனில் ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            எனில் (operands[k].உள்ளீடு_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].உள்ளீடு_index = i;
            op->priority = 5;
        } இல்லையெனில் எனில் ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } இல்லையெனில் {
            op->priority = constraint_priority(str);
        }
    }

    க்கு (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    க்கு (i = 0; i < nb_operands - 1; i++) {
        க்கு (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            எனில் (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    க்கு (i = 0; i < NB_ASM_REGS; i++) {
        எனில் (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        இல்லையெனில்
            regs_allocated[i] = 0;
    }

    க்கு (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        எனில் (op->ref_index >= 0)
            தொடர்;
        எனில் (op->உள்ளீடு_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } இல்லையெனில் எனில் (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } இல்லையெனில் {
            reg_mask = REG_IN_MASK;
        }
        எனில் (op->reg >= 0) {
            எனில் (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            செல் reg_found;
        }
    try_next:
        c = *str++;
        தேர்வு (c) {
        நிலை '=':
            செல் try_next;
        நிலை '+':
            op->is_rw = 1;
        நிலை '&':
            எனில் (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            செல் try_next;
        நிலை 'r':
            க்கு (reg = 0; reg < 31; reg++) {
                எனில் (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    செல் reg_found;
            }
            செல் try_next;
        நிலை 'w':
        நிலை 'f':
            க்கு (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                எனில் (!is_reg_allocated(reg))
                    செல் reg_found;
            }
            செல் try_next;
        நிலை 'x':
        நிலை 'y':
            க்கு (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                எனில் (!is_reg_allocated(reg))
                    செல் reg_found;
            }
            செல் try_next;
        நிலை 'm':
        நிலை 'g':
            எனில் (j < nb_outputs || c == 'm') {
                எனில் (!arm64_prepare_memory_operand(op, regs_allocated))
                    செல் try_next;
            }
            நிறுத்து;
        நிலை 'Q':
            எனில் (!arm64_memory_is_base_only(op->vt))
                செல் try_next;
            எனில் (!arm64_prepare_memory_operand(op, regs_allocated))
                செல் try_next;
            நிறுத்து;
        நிலை 'S':
            எனில் ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                செல் try_next;
            நிறுத்து;
        நிலை 'U':
            எனில் (str[0] != 'm' || str[1] != 'p')
                செல் try_next;
            str += 2;
            எனில் (!arm64_memory_is_pair_suitable(op->vt))
                செல் try_next;
            எனில் (!arm64_prepare_memory_operand(op, regs_allocated))
                செல் try_next;
            நிறுத்து;
        நிலை 'i':
            எனில் (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                செல் try_next;
            நிறுத்து;
        நிலை 'I':
            எனில் (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                செல் try_next;
            எனில் (!is_valid_add_imm(op->vt->c.i))
                செல் try_next;
            நிறுத்து;
        நிலை 'J':
            எனில் (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                செல் try_next;
            எனில் (!is_valid_add_imm(-op->vt->c.i))
                செல் try_next;
            நிறுத்து;
        நிலை 'K':
            எனில் (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                செல் try_next;
            எனில் (!is_valid_logical_imm(op->vt->c.i, 32))
                செல் try_next;
            நிறுத்து;
        நிலை 'L':
            எனில் (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                செல் try_next;
            எனில் (!is_valid_logical_imm(op->vt->c.i, 64))
                செல் try_next;
            நிறுத்து;
        நிலை 'M':
        நிலை 'N':
            எனில் (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                செல் try_next;
            எனில் (!is_valid_movw_imm(op->vt->c.i))
                செல் try_next;
            நிறுத்து;
        நிலை 'Z':
            எனில் (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                செல் try_next;
            எனில் (op->vt->c.i != 0)
                செல் try_next;
            நிறுத்து;
        நிலை 'n':
            எனில் (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                செல் try_next;
            நிறுத்து;
        இயல்பு:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            நிறுத்து;
        }
        எனில் (op->உள்ளீடு_index >= 0) {
            operands[op->உள்ளீடு_index].reg = op->reg;
            operands[op->உள்ளீடு_index].is_llong = op->is_llong;
        }
        தொடர்;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        எனில் (op->உள்ளீடு_index >= 0) {
            operands[op->உள்ளீடு_index].reg = op->reg;
            operands[op->உள்ளீடு_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    க்கு (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        எனில் (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            க்கு (reg = 0; reg < 31; reg++) {
                எனில் (!(regs_allocated[reg] & REG_OUT_MASK))
                    செல் reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            நிறுத்து;
        }
    }
}

/* Handle clobber list */
ST_FUNC வெறுமை asm_clobber(uint8_t *clobber_regs, மாறிலி எழுத்து *str)
{
    முழு reg;

    எனில் (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        திரும்பு;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    எனில் (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC முழு asm_parse_regvar(முழு t)
{
    திரும்பு arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
