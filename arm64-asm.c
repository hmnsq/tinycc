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

ST_FUNC શૂન્ય g(પૂર્ણાંક c);
ST_FUNC શૂન્ય gen_le16(પૂર્ણાંક c);
ST_FUNC શૂન્ય gen_le32(પૂર્ણાંક c);

/*************************************************************/
#નહીંતર
/*************************************************************/

#define USING_GLOBALS
#અન્તર્ભાવ "tcc.h"

/* Register type flags */
#define REG_X     0x01  /* 64-bit general purpose */
#define REG_W     0x02  /* 32-bit general purpose */
#define REG_V     0x04  /* 128-bit SIMD */
#define REG_D     0x08  /* 64-bit FP */
#define REG_S     0x10  /* 32-bit FP */
#define REG_H     0x20  /* 16-bit FP */
#define REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
ગણના {
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

પ્રકારવ્યાખ્યા સંરચના Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    પૂર્ણાંક reg_tok;
    પદાવલિ_કિંમત e;
} Operand;

ગણના {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
સ્થિર શૂન્ય parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC શૂન્ય g(પૂર્ણાંક c)
{
    પૂર્ણાંક ind1;
    જો (nocode_wanted)
        પાછા;
    ind1 = ind + 1;
    જો (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC શૂન્ય gen_le16(પૂર્ણાંક c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC શૂન્ય gen_le32(પૂર્ણાંક c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC શૂન્ય gen_expr32(પદાવલિ_કિંમત *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
સ્થિર શૂન્ય emit_instr32(uint32_t val)
{
    જો (nocode_wanted)
        પાછા;
    જો (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
સ્થિર પૂર્ણાંક arm64_parse_asm_reg(પૂર્ણાંક t)
{
    /* X registers (64-bit) */
    જો (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        પાછા t - TOK_ASM_x0;
    /* W registers (32-bit) */
    જો (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        પાછા t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    જો (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        પાછા (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    જો (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        પાછા (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    જો (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        પાછા (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    જો (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        પાછા (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    જો (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        પાછા (t - TOK_ASM_b0) + 32;
    /* Special registers */
    જો (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        પાછા 31;  /* SP/ZR encoded as 31 */
    પાછા -1;
}

/* Get register type from token */
સ્થિર uint8_t get_reg_type(પૂર્ણાંક t)
{
    જો (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        પાછા REG_X;
    જો (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        પાછા REG_W;
    જો (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        પાછા REG_V;
    જો (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        પાછા REG_D;
    જો (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        પાછા REG_S;
    જો (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        પાછા REG_H;
    જો (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        પાછા REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    જો (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        પાછા REG_X;
    જો (t == TOK_ASM_wzr)
        પાછા REG_W;
    પાછા REG_X;
}

/* Parse condition code */
સ્થિર પૂર્ણાંક parse_condition(પૂર્ણાંક t)
{
    પસંદગી (t) {
        સ્થિતિ TOK_ASM_eq: પાછા 0;
        સ્થિતિ TOK_ASM_ne: પાછા 1;
        સ્થિતિ TOK_ASM_cs:
        સ્થિતિ TOK_ASM_hs: પાછા 2;
        સ્થિતિ TOK_ASM_cc:
        સ્થિતિ TOK_ASM_lo: પાછા 3;
        સ્થિતિ TOK_ASM_mi: પાછા 4;
        સ્થિતિ TOK_ASM_pl: પાછા 5;
        સ્થિતિ TOK_ASM_vs: પાછા 6;
        સ્થિતિ TOK_ASM_vc: પાછા 7;
        સ્થિતિ TOK_ASM_hi: પાછા 8;
        સ્થિતિ TOK_ASM_ls: પાછા 9;
        સ્થિતિ TOK_ASM_ge: પાછા 10;
        સ્થિતિ TOK_ASM_lt: પાછા 11;
        સ્થિતિ TOK_ASM_gt: પાછા 12;
        સ્થિતિ TOK_ASM_le: પાછા 13;
        સ્થિતિ TOK_ASM_al: પાછા 14;
        મૂળભૂત: પાછા -1;
    }
}

સ્થિર પૂર્ણાંક parse_barrier_option_name(પૂર્ણાંક t)
{
    અચલ અક્ષર *name;

    જો (t < TOK_IDENT)
        પાછા -1;
    name = get_tok_str(t, ખાલી);
    જો (!strcmp(name, "oshld")) પાછા 0x1;
    જો (!strcmp(name, "oshst")) પાછા 0x2;
    જો (!strcmp(name, "osh"))   પાછા 0x3;
    જો (!strcmp(name, "nshld")) પાછા 0x5;
    જો (!strcmp(name, "nshst")) પાછા 0x6;
    જો (!strcmp(name, "nsh"))   પાછા 0x7;
    જો (!strcmp(name, "ishld")) પાછા 0x9;
    જો (!strcmp(name, "ishst")) પાછા 0xA;
    જો (!strcmp(name, "ish"))   પાછા 0xB;
    જો (!strcmp(name, "ld"))    પાછા 0xD;
    જો (!strcmp(name, "st"))    પાછા 0xE;
    જો (!strcmp(name, "sy"))    પાછા 0xF;
    પાછા -1;
}

સ્થિર પૂર્ણાંક arm64_parse_regvar(પૂર્ણાંક t)
{
    જો (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        પાછા t - TOK_ASM_x0;
    જો (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        પાછા ARM64_FREG_BASE + (t - TOK_ASM_v0);
    જો (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        પાછા ARM64_FREG_BASE + (t - TOK_ASM_d0);
    જો (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        પાછા ARM64_FREG_BASE + (t - TOK_ASM_s0);
    જો (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        પાછા ARM64_FREG_BASE + (t - TOK_ASM_h0);
    જો (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        પાછા ARM64_FREG_BASE + (t - TOK_ASM_b0);
    પાછા -1;
}

/* Parse a single operand */
સ્થિર શૂન્ય parse_operand(TCCState *s1, Operand *op)
{
    પૂર્ણાંક reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    જો (tok == '[') {
        parse_addr_operand(s1, op);
        પાછા;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    જો (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        પાછા;
    }

    /* Condition code */
    reg = parse_condition(tok);
    જો (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        પાછા;
    }

    /* Immediate or address expression */
    જો (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_પદાવલિ(s1, &op->e);
        op->type = OP_IM;
    } નહીંતર જો (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } નહીંતર {
        asm_પદાવલિ(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
સ્થિર શૂન્ય parse_પદાવલિ_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    જો (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_પદાવલિ(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
સ્થિર શૂન્ય parse_addr_operand(TCCState *s1, Operand *op)
{
    પૂર્ણાંક reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = ખાલી;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    જો (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        પાછા;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    જો (tok == ',') {
        next();
        જો (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_પદાવલિ(s1, &op->e);
    }
    skip(']');
    જો (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } નહીંતર જો (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        જો (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_પદાવલિ(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
સ્થિર શૂન્ય gen_mov_with_base(પૂર્ણાંક rd, uint16_t imm, પૂર્ણાંક shift,
                              પૂર્ણાંક is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    જો (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

સ્થિર શૂન્ય gen_movz(પૂર્ણાંક rd, uint16_t imm, પૂર્ણાંક shift, પૂર્ણાંક is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
સ્થિર શૂન્ય gen_movn(પૂર્ણાંક rd, uint16_t imm, પૂર્ણાંક shift, પૂર્ણાંક is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
સ્થિર શૂન્ય gen_movk(પૂર્ણાંક rd, uint16_t imm, પૂર્ણાંક shift, પૂર્ણાંક is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
સ્થિર શૂન્ય gen_add_imm(પૂર્ણાંક rd, પૂર્ણાંક rn, uint32_t imm, પૂર્ણાંક is_64bit, પૂર્ણાંક setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    જો (is_64bit) instr |= ARM64_SF(1);
    જો (setflags) instr |= ARM64_S(1);

    જો (imm <= 0xFFF) {
        imm12 = imm;
    } નહીંતર જો (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } નહીંતર {
        tcc_error("add immediate out of range");
        પાછા;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
સ્થિર શૂન્ય gen_sub_imm(પૂર્ણાંક rd, પૂર્ણાંક rn, uint32_t imm, પૂર્ણાંક is_64bit, પૂર્ણાંક setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    જો (is_64bit) instr |= ARM64_SF(1);
    જો (setflags) instr |= ARM64_S(1);

    જો (imm <= 0xFFF) {
        imm12 = imm;
    } નહીંતર જો (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } નહીંતર {
        tcc_error("sub immediate out of range");
        પાછા;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
સ્થિર શૂન્ય gen_dp_reg(uint32_t opcode, પૂર્ણાંક rd, પૂર્ણાંક rn, પૂર્ણાંક rm, પૂર્ણાંક is_64bit)
{
    uint32_t instr = opcode;
    જો (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
સ્થિર શૂન્ય gen_ldst_imm(uint32_t base_opcode, પૂર્ણાંક rt, પૂર્ણાંક rn,
                         int32_t offset, પૂર્ણાંક size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    જો (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        જો (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            પાછા;
        }
    }

    પસંદગી (base_opcode) {
    સ્થિતિ ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; તોડો;
    સ્થિતિ ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; તોડો;
    સ્થિતિ ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; તોડો;
    સ્થિતિ ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; તોડો;
    સ્થિતિ ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; તોડો;
    સ્થિતિ ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; તોડો;
    સ્થિતિ ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; તોડો;
    સ્થિતિ ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; તોડો;
    સ્થિતિ ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; તોડો;
    સ્થિતિ ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; તોડો;
    }

    જો (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        પાછા;
    }

    જો (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
સ્થિર શૂન્ય gen_ldst_pair(uint32_t base_opcode, પૂર્ણાંક rt, પૂર્ણાંક rt2, પૂર્ણાંક rn,
                          int32_t offset, પૂર્ણાંક size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    જો (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    જો (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
સ્થિર શૂન્ય gen_b_or_bl(int32_t offset, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    instr |= ARM64_OFFSET26(offset);
    emit_instr32(instr);
}

સ્થિર શૂન્ય gen_b(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_B);
}

/* Generate BL (branch with link) */
સ્થિર શૂન્ય gen_bl(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_BL);
}

/* Generate BR (branch to register) */
સ્થિર શૂન્ય gen_br(પૂર્ણાંક rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
સ્થિર શૂન્ય gen_blr(પૂર્ણાંક rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
સ્થિર શૂન્ય gen_ret(પૂર્ણાંક rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
સ્થિર શૂન્ય gen_b_cond(પૂર્ણાંક cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
સ્થિર શૂન્ય gen_cbz_or_cbnz(પૂર્ણાંક rt, int32_t offset, પૂર્ણાંક is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    જો (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

સ્થિર શૂન્ય gen_cbz(પૂર્ણાંક rt, int32_t offset, પૂર્ણાંક is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
સ્થિર શૂન્ય gen_cbnz(પૂર્ણાંક rt, int32_t offset, પૂર્ણાંક is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
સ્થિર શૂન્ય gen_mov_reg(પૂર્ણાંક rd, પૂર્ણાંક rm, પૂર્ણાંક is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    જો (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

સ્થિર પૂર્ણાંક arm64_asm_encode_bimm64(uint64_t x)
{
    પૂર્ણાંક neg, rep, pos, len;

    neg = x & 1;
    જો (neg)
        x = ~x;
    જો (!x)
        પાછા -1;

    જો (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    નહીંતર જો (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    નહીંતર જો (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    નહીંતર જો (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    નહીંતર જો (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    નહીંતર
        rep = 64;

    pos = 0;
    જો (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    જો (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    જો (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    જો (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    જો (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    જો (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    જો (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    જો (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    જો (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    જો (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    જો (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    જો (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    જો (x)
        પાછા -1;
    જો (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    પાછા ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

સ્થિર શૂન્ય gen_logical_imm(uint32_t opcode, પૂર્ણાંક rd, પૂર્ણાંક rn,
                            uint64_t imm, પૂર્ણાંક is_64bit)
{
    uint32_t instr;
    uint64_t val;
    પૂર્ણાંક enc;

    જો (is_64bit)
        val = imm;
    નહીંતર {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    જો (enc < 0) {
        tcc_error("logical immediate out of range");
        પાછા;
    }

    instr = opcode;
    જો (is_64bit)
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
સ્થિર અંતઃરેખ પૂર્ણાંક constraint_priority(અચલ અક્ષર *str)
{
    પૂર્ણાંક priority, c, pr;

    priority = 0;
    માટે (;;) {
        c = *str++;
        જો (c == '\0')
            તોડો;
        પસંદગી (c) {
        સ્થિતિ '=':
        સ્થિતિ '+':
        સ્થિતિ '&':
            ચાલુ;
        સ્થિતિ 'r':
            pr = 1;
            તોડો;
        સ્થિતિ 'w':
        સ્થિતિ 'f':
        સ્થિતિ 'x':
        સ્થિતિ 'y':
            pr = 3;
            તોડો;
        સ્થિતિ 'm':
        સ્થિતિ 'Q':
            pr = 4;
            તોડો;
        સ્થિતિ 'i':
        સ્થિતિ 'S':
            pr = 5;
            તોડો;
        સ્થિતિ 'U':
            જો (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                તોડો;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            તોડો;
        સ્થિતિ 'I':
        સ્થિતિ 'J':
        સ્થિતિ 'K':
        સ્થિતિ 'L':
        સ્થિતિ 'M':
        સ્થિતિ 'N':
        સ્થિતિ 'Z':
            pr = 6;
            તોડો;
        સ્થિતિ 'n':
            pr = 7;
            તોડો;
        સ્થિતિ 'g':
            pr = 8;
            તોડો;
        મૂળભૂત:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            તોડો;
        }
        જો (pr > priority)
            priority = pr;
    }
    પાછા priority;
}

સ્થિર અચલ અક્ષર *skip_constraint_modifiers(અચલ અક્ષર *p)
{
    જ્યારે (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    પાછા p;
}

સ્થિર પૂર્ણાંક is_valid_add_imm(int64_t val)
{
    પાછા val >= 0 && val <= 4095;
}

સ્થિર પૂર્ણાંક is_valid_logical_imm(int64_t val, પૂર્ણાંક bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    જો (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    પાછા arm64_asm_encode_bimm64(uval) >= 0;
}

સ્થિર પૂર્ણાંક is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    જો (uval <= 0xFFFF)
        પાછા 1;
    જો (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        પાછા 1;
    જો (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        પાછા 1;
    જો ((uval & 0xFFFFFFFF00000000ULL) == 0)
        પાછા 1;

    પાછા 0;
}

સ્થિર પૂર્ણાંક is_valid_movw_shift(પૂર્ણાંક shift, પૂર્ણાંક is_64bit)
{
    જો (shift < 0 || (shift & 15))
        પાછા 0;
    જો (shift > (is_64bit ? 48 : 16))
        પાછા 0;
    પાછા 1;
}

સ્થિર પૂર્ણાંક arm64_memory_is_base_only(અચલ SValue *sv)
{
    પૂર્ણાંક r;

    r = sv->r;
    જો ((r & VT_VALMASK) == VT_CONST)
        પાછા 0;
    જો ((r & VT_VALMASK) == VT_LOCAL)
        પાછા 0;
    જો ((r & VT_VALMASK) == VT_LLOCAL)
        પાછા 1;
    જો (r & VT_LVAL)
        પાછા (r & VT_VALMASK) < VT_CONST;
    પાછા 0;
}

સ્થિર પૂર્ણાંક arm64_memory_is_pair_suitable(અચલ SValue *sv)
{
    int64_t offset;

    જો (arm64_memory_is_base_only(sv))
        પાછા 1;
    જો ((sv->r & VT_VALMASK) != VT_LOCAL)
        પાછા 0;

    offset = (int64_t)sv->c.i;
    પાછા (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

સ્થિર પૂર્ણાંક arm64_int_reg_is_allocatable(પૂર્ણાંક reg)
{
#ifdef TCC_TARGET_PE
    પાછા reg >= TREG_X0 && reg <= TREG_X17;
#નહીંતર
    પાછા reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

સ્થિર પૂર્ણાંક arm64_memory_needs_address_reg(અચલ SValue *sv)
{
    પૂર્ણાંક r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    જો (!(r & VT_LVAL))
        પાછા 0;
    પસંદગી (r & VT_VALMASK) {
    સ્થિતિ VT_LOCAL:
    સ્થિતિ VT_LLOCAL:
    સ્થિતિ VT_CONST:
        પાછા 1;
    }
    પાછા 0;
}

સ્થિર પૂર્ણાંક arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    પૂર્ણાંક reg;

    જો (!arm64_memory_needs_address_reg(op->vt))
        પાછા 1;

    માટે (reg = 0; reg < 31; reg++) {
        જો (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            પાછા 1;
        }
    }
    પાછા 0;
}

સ્થિર શૂન્ય arm64_load_memory_operand_base(પૂર્ણાંક reg, SValue *sv)
{
    SValue base;
    પૂર્ણાંક rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    જો (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } નહીંતર જો (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } નહીંતર {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

સ્થિર પૂર્ણાંક operand_is_sp(અચલ Operand *op)
{
    પાછા op->reg_tok == TOK_ASM_sp;
}

સ્થિર પૂર્ણાંક parse_sysreg_name(પૂર્ણાંક t)
{
    અચલ અક્ષર *name;

    જો (t < TOK_IDENT)
        પાછા -1;
    name = get_tok_str(t, ખાલી);
    જો (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        પાછા 0;
    જો (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        પાછા 1;
    પાછા -1;
}

સ્થિર શૂન્ય gen_mrs(પૂર્ણાંક rt, પૂર્ણાંક sysreg)
{
    uint32_t instr;

    પસંદગી (sysreg) {
        સ્થિતિ 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            તોડો;
        સ્થિતિ 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            તોડો;
        મૂળભૂત:
            tcc_error("unsupported system register");
            પાછા;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

સ્થિર શૂન્ય gen_msr(પૂર્ણાંક rt, પૂર્ણાંક sysreg)
{
    uint32_t instr;

    પસંદગી (sysreg) {
        સ્થિતિ 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            તોડો;
        સ્થિતિ 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            તોડો;
        મૂળભૂત:
            tcc_error("unsupported system register");
            પાછા;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
સ્થિર શૂન્ય gen_nop(શૂન્ય)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
સ્થિર શૂન્ય gen_shift(પૂર્ણાંક rd, પૂર્ણાંક rn, પૂર્ણાંક rm_or_imm, પૂર્ણાંક shift_type, પૂર્ણાંક is_imm, પૂર્ણાંક is_64bit)
{
    uint32_t instr;
    પૂર્ણાંક width = is_64bit ? 64 : 32;

    જો (is_imm) {
        /* Shift by immediate */
        પસંદગી (shift_type) {
            સ્થિતિ 0: /* LSL - UBFM alias */
                જો (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    પાછા;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                તોડો;
            સ્થિતિ 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                જો (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    પાછા;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                તોડો;
            સ્થિતિ 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                જો (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    પાછા;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                તોડો;
            સ્થિતિ 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                જો (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    પાછા;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                પાછા;
            મૂળભૂત:
                tcc_error("unknown shift type");
                પાછા;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } નહીંતર {
        /* Shift by register */
        પસંદગી (shift_type) {
            સ્થિતિ 0: /* LSL */
                instr = ARM64_LSL_REG;
                તોડો;
            સ્થિતિ 1: /* LSR */
                instr = ARM64_LSR_REG;
                તોડો;
            સ્થિતિ 2: /* ASR */
                instr = ARM64_ASR_REG;
                તોડો;
            સ્થિતિ 3: /* ROR */
                instr = ARM64_ROR_REG;
                તોડો;
            મૂળભૂત:
                tcc_error("unknown shift type");
                પાછા;
        }
        જો (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
સ્થિર શૂન્ય asm_shift(TCCState *s1, પૂર્ણાંક token)
{
    Operand op1, op2, op3;
    પૂર્ણાંક rd, rn, shift_amount;
    પૂર્ણાંક shift_type;
    પૂર્ણાંક is_64bit = 1;

    પસંદગી (token) {
        સ્થિતિ TOK_ASM_lsl:
            shift_type = 0;
            તોડો;
        સ્થિતિ TOK_ASM_lsr:
            shift_type = 1;
            તોડો;
        સ્થિતિ TOK_ASM_asr:
            shift_type = 2;
            તોડો;
        સ્થિતિ TOK_ASM_ror:
            shift_type = 3;
            તોડો;
        મૂળભૂત:
            tcc_error("unknown shift instruction");
            પાછા;
    }

    parse_operand(s1, &op1);
    જો (tok == ',') next();
    parse_operand(s1, &op2);

    જો (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        પાછા;
    }
    જો (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        પાછા;
    }

    rd = op1.reg;
    rn = op2.reg;

    જો (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        જો (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            પાછા;
        }
        જો (op3.type & OP_REG) {
            જો (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                પાછા;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } નહીંતર જો (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } નહીંતર {
            tcc_error("shift requires immediate or register operand");
        }
    } નહીંતર {
        tcc_error("shift requires immediate or register operand");
        પાછા;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
સ્થિર શૂન્ય gen_barrier(પૂર્ણાંક barrier_type, પૂર્ણાંક option)
{
    uint32_t instr;

    પસંદગી (barrier_type) {
        સ્થિતિ 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            તોડો;
        સ્થિતિ 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            તોડો;
        સ્થિતિ 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            તોડો;
        મૂળભૂત:
            tcc_error("unknown barrier type");
            પાછા;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
સ્થિર શૂન્ય asm_barrier(TCCState *s1, પૂર્ણાંક token)
{
    પૂર્ણાંક barrier_type, option;
    Operand op;

    પસંદગી (token) {
        સ્થિતિ TOK_ASM_isb:
            barrier_type = 0;
            તોડો;
        સ્થિતિ TOK_ASM_dsb:
            barrier_type = 1;
            તોડો;
        સ્થિતિ TOK_ASM_dmb:
            barrier_type = 2;
            તોડો;
        મૂળભૂત:
            tcc_error("unknown barrier instruction");
            પાછા;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    જો (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        જો (option >= 0) {
            next();
        } નહીંતર {
            parse_operand(s1, &op);
            જો (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                પાછા;
            }
            જો (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                પાછા;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
સ્થિર શૂન્ય gen_mov_imm(પૂર્ણાંક rd, uint64_t imm, પૂર્ણાંક is_64bit)
{
    uint16_t hw;
    પૂર્ણાંક i, first = 1;

    માટે (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        જો (hw != 0 || i == 0) {
            જો (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } નહીંતર {
                gen_movk(rd, hw, i, is_64bit);
            }
        } નહીંતર જો (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
સ્થિર શૂન્ય asm_mov(TCCState *s1)
{
    Operand op1, op2;
    પૂર્ણાંક rd, rn;
    પૂર્ણાંક is_64bit;

    parse_operand(s1, &op1);
    જો (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    જો (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        જો (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            પાછા;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } નહીંતર જો (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        જો (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        નહીંતર
            gen_mov_reg(rd, rn, is_64bit);
    } નહીંતર {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
સ્થિર શૂન્ય asm_data_proc(TCCState *s1, પૂર્ણાંક token)
{
    Operand op1, op2, op3;
    પૂર્ણાંક rd, rn, rm;
    પૂર્ણાંક is_64bit = 1;
    uint32_t opcode;

    પસંદગી (token) {
        સ્થિતિ TOK_ASM_add:
        સ્થિતિ TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            તોડો;
        સ્થિતિ TOK_ASM_sub:
        સ્થિતિ TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            તોડો;
        સ્થિતિ TOK_ASM_and:
        સ્થિતિ TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            તોડો;
        સ્થિતિ TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            તોડો;
        સ્થિતિ TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            તોડો;
        સ્થિતિ TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            તોડો;
        મૂળભૂત:
            tcc_error("unsupported data processing instruction");
            પાછા;
    }

    parse_operand(s1, &op1);
    જો (tok == ',') next();
    parse_operand(s1, &op2);

    જો (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        પાછા;
    }
    જો (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        પાછા;
    }

    rd = op1.reg;
    rn = op2.reg;

    જો (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        જો (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            પાછા;
        }
        જો (op3.type & OP_IM) {
            જો (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            નહીંતર જો (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            નહીંતર જો (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            નહીંતર જો (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            નહીંતર જો (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            નહીંતર જો (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            નહીંતર
                tcc_error("immediate operand not valid for this instruction");
        } નહીંતર {
            જો (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                પાછા;
            }
            rm = op3.reg;
            જો (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                પાછા;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } નહીંતર જો (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } નહીંતર {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
સ્થિર શૂન્ય asm_ldst(TCCState *s1, પૂર્ણાંક token)
{
    Operand op1, op2;
    પૂર્ણાંક rt, rn;
    int32_t offset = 0;
    પૂર્ણાંક size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    જો (tok == ',') next();
    parse_operand(s1, &op2);

    જો (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        પાછા;
    }
    જો (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        પાછા;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    પસંદગી (token) {
        સ્થિતિ TOK_ASM_ldr:
            જો (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } નહીંતર જો (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } નહીંતર જો (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } નહીંતર {
                tcc_error("ldr requires a w, x, or d register");
                પાછા;
            }
            તોડો;
        સ્થિતિ TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            તોડો;
        સ્થિતિ TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            તોડો;
        સ્થિતિ TOK_ASM_str:
            જો (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } નહીંતર જો (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } નહીંતર જો (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } નહીંતર {
                tcc_error("str requires a w, x, or d register");
                પાછા;
            }
            તોડો;
        સ્થિતિ TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            તોડો;
        સ્થિતિ TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            તોડો;
        મૂળભૂત:
            tcc_error("unsupported load/store instruction");
            પાછા;
    }

    જો (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

સ્થિર શૂન્ય asm_ldst_pair(TCCState *s1, પૂર્ણાંક token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    પૂર્ણાંક size_log2 = 3;

    parse_operand(s1, &op1);
    જો (tok == ',')
        next();
    parse_operand(s1, &op2);
    જો (tok == ',')
        next();
    parse_operand(s1, &op3);

    જો (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        પાછા;
    }
    જો (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        પાછા;
    }
    જો (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    જો ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        જો (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } નહીંતર {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } નહીંતર જો ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        જો (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } નહીંતર {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } નહીંતર {
        tcc_error("stp/ldp requires matching x or d registers");
        પાછા;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

સ્થિર શૂન્ય asm_sysreg(TCCState *s1, પૂર્ણાંક token)
{
    Operand op;
    પૂર્ણાંક sysreg;

    જો (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        જો (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        જો (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        પાછા;
    }

    sysreg = parse_sysreg_name(tok);
    જો (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    જો (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
સ્થિર પૂર્ણાંક get_branch_condition(પૂર્ણાંક branch_token)
{
    પૂર્ણાંક cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    પસંદગી (branch_token) {
        સ્થિતિ TOK_ASM_beq: cond_token = TOK_ASM_eq; તોડો;
        સ્થિતિ TOK_ASM_bne: cond_token = TOK_ASM_ne; તોડો;
        સ્થિતિ TOK_ASM_bcs:
        સ્થિતિ TOK_ASM_bhs: cond_token = TOK_ASM_cs; તોડો;
        સ્થિતિ TOK_ASM_bcc:
        સ્થિતિ TOK_ASM_blo: cond_token = TOK_ASM_cc; તોડો;
        સ્થિતિ TOK_ASM_bmi: cond_token = TOK_ASM_mi; તોડો;
        સ્થિતિ TOK_ASM_bpl: cond_token = TOK_ASM_pl; તોડો;
        સ્થિતિ TOK_ASM_bvs: cond_token = TOK_ASM_vs; તોડો;
        સ્થિતિ TOK_ASM_bvc: cond_token = TOK_ASM_vc; તોડો;
        સ્થિતિ TOK_ASM_bhi: cond_token = TOK_ASM_hi; તોડો;
        સ્થિતિ TOK_ASM_bls: cond_token = TOK_ASM_ls; તોડો;
        સ્થિતિ TOK_ASM_bge: cond_token = TOK_ASM_ge; તોડો;
        સ્થિતિ TOK_ASM_blt: cond_token = TOK_ASM_lt; તોડો;
        સ્થિતિ TOK_ASM_bgt: cond_token = TOK_ASM_gt; તોડો;
        સ્થિતિ TOK_ASM_ble: cond_token = TOK_ASM_le; તોડો;
        મૂળભૂત: પાછા -1;
    }

    પાછા parse_condition(cond_token);
}

/* Handle branch instructions */
સ્થિર શૂન્ય asm_branch(TCCState *s1, પૂર્ણાંક token)
{
    Operand op;
    પૂર્ણાંક cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    જો (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        પાછા;
    }

    જો (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    નહીંતર
        parse_પદાવલિ_operand(s1, &op);

    જો (op.type & OP_IM) {
        sym = op.e.sym;
        જો (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            જો (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } નહીંતર {
                પસંદગી (token) {
                    સ્થિતિ TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        તોડો;
                    સ્થિતિ TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        તોડો;
                    મૂળભૂત:
                        tcc_error("unsupported branch");
                }
            }
        } નહીંતર {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            જો (cond >= 0) {
                gen_b_cond(cond, offset);
            } નહીંતર {
                પસંદગી (token) {
                    સ્થિતિ TOK_ASM_b:
                        gen_b(offset);
                        તોડો;
                    સ્થિતિ TOK_ASM_bl:
                        gen_bl(offset);
                        તોડો;
                    મૂળભૂત:
                        tcc_error("unsupported branch");
                }
            }
        }
    } નહીંતર જો (op.type & OP_REG) {
        પસંદગી (token) {
            સ્થિતિ TOK_ASM_br:
                gen_br(op.reg);
                તોડો;
            સ્થિતિ TOK_ASM_blr:
                gen_blr(op.reg);
                તોડો;
            સ્થિતિ TOK_ASM_ret:
                gen_ret(op.reg);
                તોડો;
            મૂળભૂત:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
સ્થિર શૂન્ય asm_cb(TCCState *s1, પૂર્ણાંક token)
{
    Operand op1, op2;
    પૂર્ણાંક rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    જો (tok == ',') next();
    parse_પદાવલિ_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    જો (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        જો (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } નહીંતર {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } નહીંતર {
        offset = (int32_t)op2.e.v - ind;
        જો (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        નહીંતર
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
સ્થિર શૂન્ય asm_move_wide(TCCState *s1, પૂર્ણાંક token)
{
    Operand op1, op2;
    પૂર્ણાંક rd, is_64bit = 1;
    uint16_t imm;
    પૂર્ણાંક shift = 0;

    parse_operand(s1, &op1);
    જો (tok == ',') next();
    parse_operand(s1, &op2);

    જો (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        પાછા;
    }
    જો (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        પાછા;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    જો ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        પાછા;
    }
    imm = op2.e.v;

    જો (tok == ',') {
        next();
        જો (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            પાછા;
        }
            next();
            જો (tok == '#') next();
            asm_પદાવલિ(s1, &op2.e);
        જો (op2.e.sym || !is_valid_movw_shift((પૂર્ણાંક)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            પાછા;
        }
            shift = (પૂર્ણાંક)op2.e.v / 16;
        }

    પસંદગી (token) {
        સ્થિતિ TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            તોડો;
        સ્થિતિ TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            તોડો;
        સ્થિતિ TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            તોડો;
        મૂળભૂત:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC શૂન્ય asm_opcode(TCCState *s1, પૂર્ણાંક opcode)
{
    પસંદગી (opcode) {
        સ્થિતિ TOK_ASM_add:
        સ્થિતિ TOK_ASM_adds:
        સ્થિતિ TOK_ASM_sub:
        સ્થિતિ TOK_ASM_subs:
        સ્થિતિ TOK_ASM_and:
        સ્થિતિ TOK_ASM_ands:
        સ્થિતિ TOK_ASM_orr:
        સ્થિતિ TOK_ASM_eor:
        સ્થિતિ TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            તોડો;

        સ્થિતિ TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            તોડો;

        સ્થિતિ TOK_ASM_lsl:
        સ્થિતિ TOK_ASM_lsr:
        સ્થિતિ TOK_ASM_asr:
        સ્થિતિ TOK_ASM_ror:
            asm_shift(s1, opcode);
            તોડો;

        સ્થિતિ TOK_ASM_ldr:
        સ્થિતિ TOK_ASM_ldrb:
        સ્થિતિ TOK_ASM_ldrh:
        સ્થિતિ TOK_ASM_str:
        સ્થિતિ TOK_ASM_strb:
        સ્થિતિ TOK_ASM_strh:
            asm_ldst(s1, opcode);
            તોડો;

        સ્થિતિ TOK_ASM_ldp:
        સ્થિતિ TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            તોડો;

        સ્થિતિ TOK_ASM_b:
        સ્થિતિ TOK_ASM_bl:
        સ્થિતિ TOK_ASM_br:
        સ્થિતિ TOK_ASM_blr:
        સ્થિતિ TOK_ASM_ret:
        સ્થિતિ TOK_ASM_beq:
        સ્થિતિ TOK_ASM_bne:
        સ્થિતિ TOK_ASM_bcs:
        સ્થિતિ TOK_ASM_bhs:
        સ્થિતિ TOK_ASM_bcc:
        સ્થિતિ TOK_ASM_blo:
        સ્થિતિ TOK_ASM_bmi:
        સ્થિતિ TOK_ASM_bpl:
        સ્થિતિ TOK_ASM_bvs:
        સ્થિતિ TOK_ASM_bvc:
        સ્થિતિ TOK_ASM_bhi:
        સ્થિતિ TOK_ASM_bls:
        સ્થિતિ TOK_ASM_bge:
        સ્થિતિ TOK_ASM_blt:
        સ્થિતિ TOK_ASM_bgt:
        સ્થિતિ TOK_ASM_ble:
            asm_branch(s1, opcode);
            તોડો;

        સ્થિતિ TOK_ASM_cbz:
        સ્થિતિ TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            તોડો;

        સ્થિતિ TOK_ASM_movz:
        સ્થિતિ TOK_ASM_movn:
        સ્થિતિ TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            તોડો;

        સ્થિતિ TOK_ASM_mrs:
        સ્થિતિ TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            તોડો;

        સ્થિતિ TOK_ASM_isb:
        સ્થિતિ TOK_ASM_dsb:
        સ્થિતિ TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            તોડો;

        સ્થિતિ TOK_ASM_nop:
            gen_nop();
            તોડો;

        મૂળભૂત:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, ખાલી));
            તોડો;
    }
}

/* Substitute assembler operand */
ST_FUNC શૂન્ય subst_asm_operand(CString *add_str, SValue *sv, પૂર્ણાંક modifier)
{
    પૂર્ણાંક r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    જો ((r & VT_VALMASK) == VT_CONST) {
        જો ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            પાછા;
        }
        જો (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        જો (r & VT_SYM) {
            અચલ અક્ષર *name = get_tok_str(sv->sym->v, ખાલી);
            જો (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            જો (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            જો ((uint32_t) sv->c.i == 0)
                જાઓ no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        જો (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } નહીંતર જો (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } નહીંતર {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } નહીંતર જો ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (પૂર્ણાંક) sv->c.i);
    } નહીંતર જો (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        જો (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } નહીંતર {
        /* register case */
        reg = r & VT_VALMASK;
        જો (reg >= VT_CONST)
            tcc_internal_error("");

        જો (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            જો (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            પસંદગી (modifier) {
            સ્થિતિ 'b':
            સ્થિતિ 'h':
            સ્થિતિ 's':
            સ્થિતિ 'd':
            સ્થિતિ 'q':
            સ્થિતિ 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                પાછા;
            મૂળભૂત:
                tcc_error("invalid operand modifier for SIMD/FP register");
                પાછા;
            }
        }

        /* choose register operand size */
        જો ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        નહીંતર જો ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        નહીંતર જો ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        નહીંતર
            size = 4;

        જો (modifier == 'x') {
            size = 8;
        } નહીંતર જો (modifier == 'w' || modifier == 'k') {
            size = 4;
        } નહીંતર જો (modifier == 'b') {
            size = 1;
        } નહીંતર જો (modifier == 'h') {
            size = 2;
        } નહીંતર જો (modifier == 'q') {
            size = 8;
        }

        જો (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } નહીંતર {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC શૂન્ય asm_gen_code(ASMOperand *operands, પૂર્ણાંક nb_operands,
                          પૂર્ણાંક nb_outputs, પૂર્ણાંક is_output,
                          uint8_t *clobber_regs,
                          પૂર્ણાંક out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    પૂર્ણાંક i, reg, saved_ગણતરી, ઢગલો_size, ઢગલો_off;
    પૂર્ણાંક saved_regs[12];
    સ્થિર અચલ uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, કદ(regs_allocated));
    માટે (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        જો (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_ગણતરી = 0;
    માટે (i = 0; i < કદ(reg_saved) / કદ(reg_saved[0]); i++) {
        reg = reg_saved[i];
        જો (regs_allocated[reg])
            saved_regs[saved_ગણતરી++] = reg;
    }
    ઢગલો_size = ((saved_ગણતરી + 1) / 2) * 16;

    જો (!is_output) {
        જો (saved_ગણતરી > 0) {
            gen_sub_imm(31, 31, ઢગલો_size, 1, 0);

            માટે (i = ઢગલો_off = 0; i < saved_ગણતરી; ) {
                જો (i + 1 < saved_ગણતરી) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ઢગલો_off, 3);
                    ઢગલો_off += 16;
                    i += 2;
                } નહીંતર {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 ઢગલો_off, 3);
                    i++;
                }
            }
        }

        માટે (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            જો (op->reg >= 0) {
                જો (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } નહીંતર જો (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } નહીંતર {
        માટે (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            જો (op->reg >= 0) {
                જો (op->is_memory)
                    ચાલુ;
                જો ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    જો (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } નહીંતર {
                    store(op->reg, op->vt);
                }
            }
        }

        જો (saved_ગણતરી > 0) {
            માટે (i = ઢગલો_off = 0; i < saved_ગણતરી; ) {
                જો (i + 1 < saved_ગણતરી) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, ઢગલો_off, 3);
                    ઢગલો_off += 16;
                    i += 2;
                } નહીંતર {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 ઢગલો_off, 3);
                    i++;
                }
            }
            gen_add_imm(31, 31, ઢગલો_size, 1, 0);
        }
    }
}

ST_FUNC શૂન્ય asm_compute_constraints(ASMOperand *operands,
                                    પૂર્ણાંક nb_operands, પૂર્ણાંક nb_outputs,
                                    અચલ uint8_t *clobber_regs,
                                    પૂર્ણાંક *pout_reg)
{
    ASMOperand *op;
    પૂર્ણાંક sorted_op[MAX_ASM_OPERANDS];
    પૂર્ણાંક i, j, k, p1, p2, tmp, reg, c, reg_mask;
    અચલ અક્ષર *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    માટે (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->આગત_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    માટે (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        જો (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, ખાલી);
            જો ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            જો (operands[k].આગત_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].આગત_index = i;
            op->priority = 5;
        } નહીંતર જો ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } નહીંતર {
            op->priority = constraint_priority(str);
        }
    }

    માટે (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    માટે (i = 0; i < nb_operands - 1; i++) {
        માટે (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            જો (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    માટે (i = 0; i < NB_ASM_REGS; i++) {
        જો (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        નહીંતર
            regs_allocated[i] = 0;
    }

    માટે (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        જો (op->ref_index >= 0)
            ચાલુ;
        જો (op->આગત_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } નહીંતર જો (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } નહીંતર {
            reg_mask = REG_IN_MASK;
        }
        જો (op->reg >= 0) {
            જો (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            જાઓ reg_found;
        }
    try_next:
        c = *str++;
        પસંદગી (c) {
        સ્થિતિ '=':
            જાઓ try_next;
        સ્થિતિ '+':
            op->is_rw = 1;
        સ્થિતિ '&':
            જો (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            જાઓ try_next;
        સ્થિતિ 'r':
            માટે (reg = 0; reg < 31; reg++) {
                જો (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    જાઓ reg_found;
            }
            જાઓ try_next;
        સ્થિતિ 'w':
        સ્થિતિ 'f':
            માટે (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                જો (!is_reg_allocated(reg))
                    જાઓ reg_found;
            }
            જાઓ try_next;
        સ્થિતિ 'x':
        સ્થિતિ 'y':
            માટે (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                જો (!is_reg_allocated(reg))
                    જાઓ reg_found;
            }
            જાઓ try_next;
        સ્થિતિ 'm':
        સ્થિતિ 'g':
            જો (j < nb_outputs || c == 'm') {
                જો (!arm64_prepare_memory_operand(op, regs_allocated))
                    જાઓ try_next;
            }
            તોડો;
        સ્થિતિ 'Q':
            જો (!arm64_memory_is_base_only(op->vt))
                જાઓ try_next;
            જો (!arm64_prepare_memory_operand(op, regs_allocated))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'S':
            જો ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'U':
            જો (str[0] != 'm' || str[1] != 'p')
                જાઓ try_next;
            str += 2;
            જો (!arm64_memory_is_pair_suitable(op->vt))
                જાઓ try_next;
            જો (!arm64_prepare_memory_operand(op, regs_allocated))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'i':
            જો (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'I':
            જો (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                જાઓ try_next;
            જો (!is_valid_add_imm(op->vt->c.i))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'J':
            જો (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                જાઓ try_next;
            જો (!is_valid_add_imm(-op->vt->c.i))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'K':
            જો (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                જાઓ try_next;
            જો (!is_valid_logical_imm(op->vt->c.i, 32))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'L':
            જો (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                જાઓ try_next;
            જો (!is_valid_logical_imm(op->vt->c.i, 64))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'M':
        સ્થિતિ 'N':
            જો (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                જાઓ try_next;
            જો (!is_valid_movw_imm(op->vt->c.i))
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'Z':
            જો (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                જાઓ try_next;
            જો (op->vt->c.i != 0)
                જાઓ try_next;
            તોડો;
        સ્થિતિ 'n':
            જો (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                જાઓ try_next;
            તોડો;
        મૂળભૂત:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            તોડો;
        }
        જો (op->આગત_index >= 0) {
            operands[op->આગત_index].reg = op->reg;
            operands[op->આગત_index].is_llong = op->is_llong;
        }
        ચાલુ;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        જો (op->આગત_index >= 0) {
            operands[op->આગત_index].reg = op->reg;
            operands[op->આગત_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    માટે (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        જો (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            માટે (reg = 0; reg < 31; reg++) {
                જો (!(regs_allocated[reg] & REG_OUT_MASK))
                    જાઓ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            તોડો;
        }
    }
}

/* Handle clobber list */
ST_FUNC શૂન્ય asm_clobber(uint8_t *clobber_regs, અચલ અક્ષર *str)
{
    પૂર્ણાંક reg;

    જો (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        પાછા;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    જો (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC પૂર્ણાંક asm_parse_regvar(પૂર્ણાંક t)
{
    પાછા arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
