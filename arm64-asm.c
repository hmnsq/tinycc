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

ST_FUNC ശൂന്യം g(പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം gen_le16(പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം gen_le32(പൂർണ്ണസംഖ്യ c);

/*************************************************************/
#അല്ലെങ്കിൽ
/*************************************************************/

#define USING_GLOBALS
#അന്തര്ഭാവ "tcc.h"

/* Register type flags */
#define REG_X     0x01  /* 64-bit general purpose */
#define REG_W     0x02  /* 32-bit general purpose */
#define REG_V     0x04  /* 128-bit SIMD */
#define REG_D     0x08  /* 64-bit FP */
#define REG_S     0x10  /* 32-bit FP */
#define REG_H     0x20  /* 16-bit FP */
#define REG_B     0x40  /* 8-bit SIMD */

/* Operand types */
എണ്ണൽ {
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

തരനിർവചനം ഘടന Operand {
    uint32_t type;
    int8_t reg;
    int8_t reg2;
    uint8_t reg_type;
    uint8_t shift;
    uint8_t addr_mode;
    പൂർണ്ണസംഖ്യ reg_tok;
    വ്യഞ്ജകം_മൂല്യം e;
} Operand;

എണ്ണൽ {
    ADDR_OFF,
    ADDR_PRE,
    ADDR_POST,
};

/* Forward declaration */
സ്ഥിതം ശൂന്യം parse_addr_operand(TCCState *s1, Operand *op);

/* XXX: make it faster ? */
ST_FUNC ശൂന്യം g(പൂർണ്ണസംഖ്യ c)
{
    പൂർണ്ണസംഖ്യ ind1;
    എങ്കിൽ (nocode_wanted)
        തിരികെ;
    ind1 = ind + 1;
    എങ്കിൽ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC ശൂന്യം gen_le16(പൂർണ്ണസംഖ്യ c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC ശൂന്യം gen_le32(പൂർണ്ണസംഖ്യ c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC ശൂന്യം gen_expr32(വ്യഞ്ജകം_മൂല്യം *pe)
{
    gen_le32(pe->v);
}

/* Emit 32-bit instruction */
സ്ഥിതം ശൂന്യം emit_instr32(uint32_t val)
{
    എങ്കിൽ (nocode_wanted)
        തിരികെ;
    എങ്കിൽ (ind + 4 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind + 4);
    write32le(cur_text_section->data + ind, val);
    ind += 4;
}

/* Parse ARM64 register token for assembler syntax. */
സ്ഥിതം പൂർണ്ണസംഖ്യ arm64_parse_asm_reg(പൂർണ്ണസംഖ്യ t)
{
    /* X registers (64-bit) */
    എങ്കിൽ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        തിരികെ t - TOK_ASM_x0;
    /* W registers (32-bit) */
    എങ്കിൽ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        തിരികെ t - TOK_ASM_w0;
    /* V registers (128-bit SIMD) */
    എങ്കിൽ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        തിരികെ (t - TOK_ASM_v0) + 32;
    /* D registers (64-bit FP) */
    എങ്കിൽ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        തിരികെ (t - TOK_ASM_d0) + 32;
    /* S registers (32-bit FP) */
    എങ്കിൽ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        തിരികെ (t - TOK_ASM_s0) + 32;
    /* H registers (16-bit FP) */
    എങ്കിൽ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        തിരികെ (t - TOK_ASM_h0) + 32;
    /* B registers (8-bit SIMD) */
    എങ്കിൽ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        തിരികെ (t - TOK_ASM_b0) + 32;
    /* Special registers */
    എങ്കിൽ (t == TOK_ASM_sp || t == TOK_ASM_xzr || t == TOK_ASM_wzr)
        തിരികെ 31;  /* SP/ZR encoded as 31 */
    തിരികെ -1;
}

/* Get register type from token */
സ്ഥിതം uint8_t get_reg_type(പൂർണ്ണസംഖ്യ t)
{
    എങ്കിൽ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        തിരികെ REG_X;
    എങ്കിൽ (t >= TOK_ASM_w0 && t <= TOK_ASM_w30)
        തിരികെ REG_W;
    എങ്കിൽ (t >= TOK_ASM_v0 && t <= TOK_ASM_v31)
        തിരികെ REG_V;
    എങ്കിൽ (t >= TOK_ASM_d0 && t <= TOK_ASM_d31)
        തിരികെ REG_D;
    എങ്കിൽ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
        തിരികെ REG_S;
    എങ്കിൽ (t >= TOK_ASM_h0 && t <= TOK_ASM_h31)
        തിരികെ REG_H;
    എങ്കിൽ (t >= TOK_ASM_b0 && t <= TOK_ASM_b31)
        തിരികെ REG_B;
    /* Special registers - sp is 64-bit, xzr is 64-bit, wzr is 32-bit */
    എങ്കിൽ (t == TOK_ASM_sp || t == TOK_ASM_xzr)
        തിരികെ REG_X;
    എങ്കിൽ (t == TOK_ASM_wzr)
        തിരികെ REG_W;
    തിരികെ REG_X;
}

/* Parse condition code */
സ്ഥിതം പൂർണ്ണസംഖ്യ parse_condition(പൂർണ്ണസംഖ്യ t)
{
    തിരഞ്ഞെടുപ്പ് (t) {
        അവസ്ഥ TOK_ASM_eq: തിരികെ 0;
        അവസ്ഥ TOK_ASM_ne: തിരികെ 1;
        അവസ്ഥ TOK_ASM_cs:
        അവസ്ഥ TOK_ASM_hs: തിരികെ 2;
        അവസ്ഥ TOK_ASM_cc:
        അവസ്ഥ TOK_ASM_lo: തിരികെ 3;
        അവസ്ഥ TOK_ASM_mi: തിരികെ 4;
        അവസ്ഥ TOK_ASM_pl: തിരികെ 5;
        അവസ്ഥ TOK_ASM_vs: തിരികെ 6;
        അവസ്ഥ TOK_ASM_vc: തിരികെ 7;
        അവസ്ഥ TOK_ASM_hi: തിരികെ 8;
        അവസ്ഥ TOK_ASM_ls: തിരികെ 9;
        അവസ്ഥ TOK_ASM_ge: തിരികെ 10;
        അവസ്ഥ TOK_ASM_lt: തിരികെ 11;
        അവസ്ഥ TOK_ASM_gt: തിരികെ 12;
        അവസ്ഥ TOK_ASM_le: തിരികെ 13;
        അവസ്ഥ TOK_ASM_al: തിരികെ 14;
        സ്ഥിരസ്ഥിതി: തിരികെ -1;
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ parse_barrier_option_name(പൂർണ്ണസംഖ്യ t)
{
    സ്ഥിരം അക്ഷരം *name;

    എങ്കിൽ (t < TOK_IDENT)
        തിരികെ -1;
    name = get_tok_str(t, ശൂന്യ);
    എങ്കിൽ (!strcmp(name, "oshld")) തിരികെ 0x1;
    എങ്കിൽ (!strcmp(name, "oshst")) തിരികെ 0x2;
    എങ്കിൽ (!strcmp(name, "osh"))   തിരികെ 0x3;
    എങ്കിൽ (!strcmp(name, "nshld")) തിരികെ 0x5;
    എങ്കിൽ (!strcmp(name, "nshst")) തിരികെ 0x6;
    എങ്കിൽ (!strcmp(name, "nsh"))   തിരികെ 0x7;
    എങ്കിൽ (!strcmp(name, "ishld")) തിരികെ 0x9;
    എങ്കിൽ (!strcmp(name, "ishst")) തിരികെ 0xA;
    എങ്കിൽ (!strcmp(name, "ish"))   തിരികെ 0xB;
    എങ്കിൽ (!strcmp(name, "ld"))    തിരികെ 0xD;
    എങ്കിൽ (!strcmp(name, "st"))    തിരികെ 0xE;
    എങ്കിൽ (!strcmp(name, "sy"))    തിരികെ 0xF;
    തിരികെ -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ arm64_parse_regvar(പൂർണ്ണസംഖ്യ t)
{
    എങ്കിൽ (t >= TOK_ASM_x0 && t <= TOK_ASM_x30)
        തിരികെ t - TOK_ASM_x0;
    എങ്കിൽ (t >= TOK_ASM_v0 && t <= TOK_ASM_v7)
        തിരികെ ARM64_FREG_BASE + (t - TOK_ASM_v0);
    എങ്കിൽ (t >= TOK_ASM_d0 && t <= TOK_ASM_d7)
        തിരികെ ARM64_FREG_BASE + (t - TOK_ASM_d0);
    എങ്കിൽ (t >= TOK_ASM_s0 && t <= TOK_ASM_s7)
        തിരികെ ARM64_FREG_BASE + (t - TOK_ASM_s0);
    എങ്കിൽ (t >= TOK_ASM_h0 && t <= TOK_ASM_h7)
        തിരികെ ARM64_FREG_BASE + (t - TOK_ASM_h0);
    എങ്കിൽ (t >= TOK_ASM_b0 && t <= TOK_ASM_b7)
        തിരികെ ARM64_FREG_BASE + (t - TOK_ASM_b0);
    തിരികെ -1;
}

/* Parse a single operand */
സ്ഥിതം ശൂന്യം parse_operand(TCCState *s1, Operand *op)
{
    പൂർണ്ണസംഖ്യ reg;

    op->type = 0;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    /* Address operand in brackets [xn, ...] */
    എങ്കിൽ (tok == '[') {
        parse_addr_operand(s1, op);
        തിരികെ;
    }

    /* Register */
    reg = arm64_parse_asm_reg(tok);
    എങ്കിൽ (reg >= 0) {
        op->type = OP_REG;
        op->reg = reg;
        op->reg_type = get_reg_type(tok);
        op->reg_tok = tok;
        next();
        തിരികെ;
    }

    /* Condition code */
    reg = parse_condition(tok);
    എങ്കിൽ (reg >= 0) {
        op->type = OP_COND;
        op->reg = reg;
        next();
        തിരികെ;
    }

    /* Immediate or address expression */
    എങ്കിൽ (tok == '#' || tok == ':' || tok == '@' || tok == '$') {
        next();
        asm_വ്യഞ്ജകം(s1, &op->e);
        op->type = OP_IM;
    } അല്ലെങ്കിൽ എങ്കിൽ (tok >= TOK_IDENT) {
        tcc_error("invalid operand '%s'", get_tok_str(tok, &tokc));
        op->type = OP_IM;
    } അല്ലെങ്കിൽ {
        asm_വ്യഞ്ജകം(s1, &op->e);
        op->type = OP_IM;
    }
}

/* Parse a symbolic/immediate expression operand used by branch instructions. */
സ്ഥിതം ശൂന്യം parse_വ്യഞ്ജകം_operand(TCCState *s1, Operand *op)
{
    op->type = OP_IM;
    op->reg = -1;
    op->reg2 = -1;
    op->reg_type = 0;
    op->shift = 0;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    എങ്കിൽ (tok == '#' || tok == ':' || tok == '@' || tok == '$')
        next();
    asm_വ്യഞ്ജകം(s1, &op->e);
}

/* Parse address operand in brackets [xn, ...] */
സ്ഥിതം ശൂന്യം parse_addr_operand(TCCState *s1, Operand *op)
{
    പൂർണ്ണസംഖ്യ reg;

    op->type = OP_ADDR;
    op->reg = -1;
    op->reg2 = -1;
    op->e.v = 0;
    op->e.sym = ശൂന്യ;
    op->addr_mode = ADDR_OFF;
    op->reg_tok = 0;

    skip('[');
    reg = arm64_parse_asm_reg(tok);
    എങ്കിൽ (reg < 0 || reg >= 32) {
        tcc_error("invalid register in address operand");
        തിരികെ;
    }
    op->reg = reg;
    op->reg_tok = tok;
    next();
    /* Check for offset */
    എങ്കിൽ (tok == ',') {
        next();
        എങ്കിൽ (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_വ്യഞ്ജകം(s1, &op->e);
    }
    skip(']');
    എങ്കിൽ (tok == '!') {
        op->addr_mode = ADDR_PRE;
        next();
    } അല്ലെങ്കിൽ എങ്കിൽ (tok == ',') {
        op->addr_mode = ADDR_POST;
        next();
        എങ്കിൽ (tok == '#' || tok == '@' || tok == '$')
            next();
        asm_വ്യഞ്ജകം(s1, &op->e);
    }
}

/* Generate MOVZ/MOVN/MOVK with base opcode */
സ്ഥിതം ശൂന്യം gen_mov_with_base(പൂർണ്ണസംഖ്യ rd, uint16_t imm, പൂർണ്ണസംഖ്യ shift,
                              പൂർണ്ണസംഖ്യ is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    എങ്കിൽ (is_64bit) instr |= ARM64_SF(1);
    /* shift is halfword index (0-3), encode as LSL #0/16/32/48 */
    instr |= ARM64_IMM_HW(imm, shift);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

സ്ഥിതം ശൂന്യം gen_movz(പൂർണ്ണസംഖ്യ rd, uint16_t imm, പൂർണ്ണസംഖ്യ shift, പൂർണ്ണസംഖ്യ is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVZ);
}

/* Generate MOVN instruction */
സ്ഥിതം ശൂന്യം gen_movn(പൂർണ്ണസംഖ്യ rd, uint16_t imm, പൂർണ്ണസംഖ്യ shift, പൂർണ്ണസംഖ്യ is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVN);
}

/* Generate MOVK instruction */
സ്ഥിതം ശൂന്യം gen_movk(പൂർണ്ണസംഖ്യ rd, uint16_t imm, പൂർണ്ണസംഖ്യ shift, പൂർണ്ണസംഖ്യ is_64bit)
{
    gen_mov_with_base(rd, imm, shift, is_64bit, ARM64_MOVK);
}

/* Generate ADD (immediate) */
സ്ഥിതം ശൂന്യം gen_add_imm(പൂർണ്ണസംഖ്യ rd, പൂർണ്ണസംഖ്യ rn, uint32_t imm, പൂർണ്ണസംഖ്യ is_64bit, പൂർണ്ണസംഖ്യ setflags)
{
    uint32_t instr = ARM64_ADD_IMM;
    uint32_t imm12;

    എങ്കിൽ (is_64bit) instr |= ARM64_SF(1);
    എങ്കിൽ (setflags) instr |= ARM64_S(1);

    എങ്കിൽ (imm <= 0xFFF) {
        imm12 = imm;
    } അല്ലെങ്കിൽ എങ്കിൽ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } അല്ലെങ്കിൽ {
        tcc_error("add immediate out of range");
        തിരികെ;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate SUB (immediate) */
സ്ഥിതം ശൂന്യം gen_sub_imm(പൂർണ്ണസംഖ്യ rd, പൂർണ്ണസംഖ്യ rn, uint32_t imm, പൂർണ്ണസംഖ്യ is_64bit, പൂർണ്ണസംഖ്യ setflags)
{
    uint32_t instr = ARM64_SUB_IMM;
    uint32_t imm12;

    എങ്കിൽ (is_64bit) instr |= ARM64_SF(1);
    എങ്കിൽ (setflags) instr |= ARM64_S(1);

    എങ്കിൽ (imm <= 0xFFF) {
        imm12 = imm;
    } അല്ലെങ്കിൽ എങ്കിൽ (!(imm & 0xFFF) && (imm >> 12) <= 0xFFF) {
        instr |= ARM64_SH(1);
        imm12 = imm >> 12;
    } അല്ലെങ്കിൽ {
        tcc_error("sub immediate out of range");
        തിരികെ;
    }

    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate data processing register instruction */
സ്ഥിതം ശൂന്യം gen_dp_reg(uint32_t opcode, പൂർണ്ണസംഖ്യ rd, പൂർണ്ണസംഖ്യ rn, പൂർണ്ണസംഖ്യ rm, പൂർണ്ണസംഖ്യ is_64bit)
{
    uint32_t instr = opcode;
    എങ്കിൽ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

/* Generate LDR/STR (unsigned immediate) */
സ്ഥിതം ശൂന്യം gen_ldst_imm(uint32_t base_opcode, പൂർണ്ണസംഖ്യ rt, പൂർണ്ണസംഖ്യ rn,
                         int32_t offset, പൂർണ്ണസംഖ്യ size_log2)
{
    uint32_t instr = base_opcode;
    uint32_t unscaled_opcode = 0;
    uint32_t imm12;

    എങ്കിൽ (offset >= 0 && !(offset & ((1 << size_log2) - 1))) {
    imm12 = offset >> size_log2;
        എങ്കിൽ (imm12 <= 0xFFF) {
    instr |= ARM64_IMM12(imm12);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
            തിരികെ;
        }
    }

    തിരഞ്ഞെടുപ്പ് (base_opcode) {
    അവസ്ഥ ARM64_LDR_X: unscaled_opcode = ARM64_LDUR_X; നിർത്തുക;
    അവസ്ഥ ARM64_LDR_W: unscaled_opcode = ARM64_LDUR_W; നിർത്തുക;
    അവസ്ഥ ARM64_LDR_B: unscaled_opcode = ARM64_LDUR_B; നിർത്തുക;
    അവസ്ഥ ARM64_LDR_H: unscaled_opcode = ARM64_LDUR_H; നിർത്തുക;
    അവസ്ഥ ARM64_LDR_D: unscaled_opcode = ARM64_LDUR_D_SIMD; നിർത്തുക;
    അവസ്ഥ ARM64_STR_X: unscaled_opcode = ARM64_STUR_X; നിർത്തുക;
    അവസ്ഥ ARM64_STR_W: unscaled_opcode = ARM64_STUR_W; നിർത്തുക;
    അവസ്ഥ ARM64_STR_B: unscaled_opcode = ARM64_STUR_B; നിർത്തുക;
    അവസ്ഥ ARM64_STR_H: unscaled_opcode = ARM64_STUR_H; നിർത്തുക;
    അവസ്ഥ ARM64_STR_D: unscaled_opcode = ARM64_STUR_D_SIMD; നിർത്തുക;
    }

    എങ്കിൽ (unscaled_opcode && offset >= -256 && offset <= 255) {
        instr = unscaled_opcode;
        instr |= ((uint32_t)offset & 0x1FFU) << 12;
        instr |= ARM64_RN(rn);
        instr |= ARM64_RT(rt);
        emit_instr32(instr);
        തിരികെ;
    }

    എങ്കിൽ (offset & ((1 << size_log2) - 1))
        tcc_error("invalid load/store offset");
    tcc_error("load/store offset out of range");
}

/* Generate STP/LDP (signed immediate) */
സ്ഥിതം ശൂന്യം gen_ldst_pair(uint32_t base_opcode, പൂർണ്ണസംഖ്യ rt, പൂർണ്ണസംഖ്യ rt2, പൂർണ്ണസംഖ്യ rn,
                          int32_t offset, പൂർണ്ണസംഖ്യ size_log2)
{
    int32_t imm7;
    uint32_t instr = base_opcode;

    എങ്കിൽ (offset & ((1 << size_log2) - 1))
        tcc_error("invalid pair load/store offset");
    imm7 = offset >> size_log2;
    എങ്കിൽ (imm7 < -64 || imm7 > 63)
        tcc_error("pair load/store offset out of range");

    instr |= ARM64_IMM7(imm7);
    instr |= ARM64_RT2(rt2);
    instr |= ARM64_RN(rn);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

/* Generate B (branch) */
/* Generate B/BL with base opcode */
സ്ഥിതം ശൂന്യം gen_b_or_bl(int32_t offset, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    instr |= ARM64_OFFSET26(offset);
    emit_instr32(instr);
}

സ്ഥിതം ശൂന്യം gen_b(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_B);
}

/* Generate BL (branch with link) */
സ്ഥിതം ശൂന്യം gen_bl(int32_t offset)
{
    gen_b_or_bl(offset, ARM64_BL);
}

/* Generate BR (branch to register) */
സ്ഥിതം ശൂന്യം gen_br(പൂർണ്ണസംഖ്യ rn)
{
    uint32_t instr = ARM64_BR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate BLR (branch with link to register) */
സ്ഥിതം ശൂന്യം gen_blr(പൂർണ്ണസംഖ്യ rn)
{
    uint32_t instr = ARM64_BLR;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate RET */
സ്ഥിതം ശൂന്യം gen_ret(പൂർണ്ണസംഖ്യ rn)
{
    uint32_t instr = ARM64_RET;
    instr |= ARM64_RN(rn);
    emit_instr32(instr);
}

/* Generate conditional branch */
സ്ഥിതം ശൂന്യം gen_b_cond(പൂർണ്ണസംഖ്യ cond, int32_t offset)
{
    uint32_t instr = ARM64_B_COND;
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_COND(cond);
    emit_instr32(instr);
}

/* Generate CBZ */
/* Generate CBZ/CBNZ with base opcode */
സ്ഥിതം ശൂന്യം gen_cbz_or_cbnz(പൂർണ്ണസംഖ്യ rt, int32_t offset, പൂർണ്ണസംഖ്യ is_64bit, uint32_t base_opcode)
{
    uint32_t instr = base_opcode;
    എങ്കിൽ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_OFFSET19(offset);
    instr |= ARM64_RT(rt);
    emit_instr32(instr);
}

സ്ഥിതം ശൂന്യം gen_cbz(പൂർണ്ണസംഖ്യ rt, int32_t offset, പൂർണ്ണസംഖ്യ is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBZ);
}

/* Generate CBNZ */
സ്ഥിതം ശൂന്യം gen_cbnz(പൂർണ്ണസംഖ്യ rt, int32_t offset, പൂർണ്ണസംഖ്യ is_64bit)
{
    gen_cbz_or_cbnz(rt, offset, is_64bit, ARM64_CBNZ);
}

/* Generate MOV (register) - ORR with zero register */
സ്ഥിതം ശൂന്യം gen_mov_reg(പൂർണ്ണസംഖ്യ rd, പൂർണ്ണസംഖ്യ rm, പൂർണ്ണസംഖ്യ is_64bit)
{
    uint32_t instr = ARM64_MOV_REG;
    എങ്കിൽ (is_64bit) instr |= ARM64_SF(1);
    instr |= ARM64_RM(rm);
    instr |= ARM64_RD(rd);
    emit_instr32(instr);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ arm64_asm_encode_bimm64(uint64_t x)
{
    പൂർണ്ണസംഖ്യ neg, rep, pos, len;

    neg = x & 1;
    എങ്കിൽ (neg)
        x = ~x;
    എങ്കിൽ (!x)
        തിരികെ -1;

    എങ്കിൽ (x >> 2 == (x & ((((uint64_t)1) << (64 - 2)) - 1)))
        rep = 2, x &= (((uint64_t)1) << 2) - 1;
    അല്ലെങ്കിൽ എങ്കിൽ (x >> 4 == (x & ((((uint64_t)1) << (64 - 4)) - 1)))
        rep = 4, x &= (((uint64_t)1) << 4) - 1;
    അല്ലെങ്കിൽ എങ്കിൽ (x >> 8 == (x & ((((uint64_t)1) << (64 - 8)) - 1)))
        rep = 8, x &= (((uint64_t)1) << 8) - 1;
    അല്ലെങ്കിൽ എങ്കിൽ (x >> 16 == (x & ((((uint64_t)1) << (64 - 16)) - 1)))
        rep = 16, x &= (((uint64_t)1) << 16) - 1;
    അല്ലെങ്കിൽ എങ്കിൽ (x >> 32 == (x & ((((uint64_t)1) << (64 - 32)) - 1)))
        rep = 32, x &= (((uint64_t)1) << 32) - 1;
    അല്ലെങ്കിൽ
        rep = 64;

    pos = 0;
    എങ്കിൽ (!(x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, pos += 32;
    എങ്കിൽ (!(x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, pos += 16;
    എങ്കിൽ (!(x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, pos += 8;
    എങ്കിൽ (!(x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, pos += 4;
    എങ്കിൽ (!(x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, pos += 2;
    എങ്കിൽ (!(x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, pos += 1;

    len = 0;
    എങ്കിൽ (!(~x & ((((uint64_t)1) << 32) - 1)))
        x >>= 32, len += 32;
    എങ്കിൽ (!(~x & ((((uint64_t)1) << 16) - 1)))
        x >>= 16, len += 16;
    എങ്കിൽ (!(~x & ((((uint64_t)1) << 8) - 1)))
        x >>= 8, len += 8;
    എങ്കിൽ (!(~x & ((((uint64_t)1) << 4) - 1)))
        x >>= 4, len += 4;
    എങ്കിൽ (!(~x & ((((uint64_t)1) << 2) - 1)))
        x >>= 2, len += 2;
    എങ്കിൽ (!(~x & ((((uint64_t)1) << 1) - 1)))
        x >>= 1, len += 1;

    എങ്കിൽ (x)
        തിരികെ -1;
    എങ്കിൽ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    തിരികെ ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

സ്ഥിതം ശൂന്യം gen_logical_imm(uint32_t opcode, പൂർണ്ണസംഖ്യ rd, പൂർണ്ണസംഖ്യ rn,
                            uint64_t imm, പൂർണ്ണസംഖ്യ is_64bit)
{
    uint32_t instr;
    uint64_t val;
    പൂർണ്ണസംഖ്യ enc;

    എങ്കിൽ (is_64bit)
        val = imm;
    അല്ലെങ്കിൽ {
        val = (uint32_t)imm;
        val |= val << 32;
    }

    enc = arm64_asm_encode_bimm64(val);
    എങ്കിൽ (enc < 0) {
        tcc_error("logical immediate out of range");
        തിരികെ;
    }

    instr = opcode;
    എങ്കിൽ (is_64bit)
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
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ constraint_priority(സ്ഥിരം അക്ഷരം *str)
{
    പൂർണ്ണസംഖ്യ priority, c, pr;

    priority = 0;
    വേണ്ടി (;;) {
        c = *str++;
        എങ്കിൽ (c == '\0')
            നിർത്തുക;
        തിരഞ്ഞെടുപ്പ് (c) {
        അവസ്ഥ '=':
        അവസ്ഥ '+':
        അവസ്ഥ '&':
            തുടരുക;
        അവസ്ഥ 'r':
            pr = 1;
            നിർത്തുക;
        അവസ്ഥ 'w':
        അവസ്ഥ 'f':
        അവസ്ഥ 'x':
        അവസ്ഥ 'y':
            pr = 3;
            നിർത്തുക;
        അവസ്ഥ 'm':
        അവസ്ഥ 'Q':
            pr = 4;
            നിർത്തുക;
        അവസ്ഥ 'i':
        അവസ്ഥ 'S':
            pr = 5;
            നിർത്തുക;
        അവസ്ഥ 'U':
            എങ്കിൽ (str[0] == 'm' && str[1] == 'p') {
                str += 2;
                pr = 4;
                നിർത്തുക;
            }
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            നിർത്തുക;
        അവസ്ഥ 'I':
        അവസ്ഥ 'J':
        അവസ്ഥ 'K':
        അവസ്ഥ 'L':
        അവസ്ഥ 'M':
        അവസ്ഥ 'N':
        അവസ്ഥ 'Z':
            pr = 6;
            നിർത്തുക;
        അവസ്ഥ 'n':
            pr = 7;
            നിർത്തുക;
        അവസ്ഥ 'g':
            pr = 8;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_warning("unknown constraint '%c'", c);
            pr = 0;
            നിർത്തുക;
        }
        എങ്കിൽ (pr > priority)
            priority = pr;
    }
    തിരികെ priority;
}

സ്ഥിതം സ്ഥിരം അക്ഷരം *skip_constraint_modifiers(സ്ഥിരം അക്ഷരം *p)
{
    ആകുമ്പോൾ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    തിരികെ p;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ is_valid_add_imm(int64_t val)
{
    തിരികെ val >= 0 && val <= 4095;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ is_valid_logical_imm(int64_t val, പൂർണ്ണസംഖ്യ bits)
{
    uint64_t uval;

    uval = (uint64_t)val;
    എങ്കിൽ (bits == 32) {
        uval = (uint32_t)uval;
        uval |= uval << 32;
    }
    തിരികെ arm64_asm_encode_bimm64(uval) >= 0;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ is_valid_movw_imm(int64_t val)
{
    uint64_t uval = (uint64_t)val;

    എങ്കിൽ (uval <= 0xFFFF)
        തിരികെ 1;
    എങ്കിൽ (uval >= 0xFFFF0000 && (uval & 0xFFFF) == 0)
        തിരികെ 1;
    എങ്കിൽ (uval >= 0xFFFF00000000ULL && (uval & 0xFFFFFFFFULL) == 0)
        തിരികെ 1;
    എങ്കിൽ ((uval & 0xFFFFFFFF00000000ULL) == 0)
        തിരികെ 1;

    തിരികെ 0;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ is_valid_movw_shift(പൂർണ്ണസംഖ്യ shift, പൂർണ്ണസംഖ്യ is_64bit)
{
    എങ്കിൽ (shift < 0 || (shift & 15))
        തിരികെ 0;
    എങ്കിൽ (shift > (is_64bit ? 48 : 16))
        തിരികെ 0;
    തിരികെ 1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ arm64_memory_is_base_only(സ്ഥിരം SValue *sv)
{
    പൂർണ്ണസംഖ്യ r;

    r = sv->r;
    എങ്കിൽ ((r & VT_VALMASK) == VT_CONST)
        തിരികെ 0;
    എങ്കിൽ ((r & VT_VALMASK) == VT_LOCAL)
        തിരികെ 0;
    എങ്കിൽ ((r & VT_VALMASK) == VT_LLOCAL)
        തിരികെ 1;
    എങ്കിൽ (r & VT_LVAL)
        തിരികെ (r & VT_VALMASK) < VT_CONST;
    തിരികെ 0;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ arm64_memory_is_pair_suitable(സ്ഥിരം SValue *sv)
{
    int64_t offset;

    എങ്കിൽ (arm64_memory_is_base_only(sv))
        തിരികെ 1;
    എങ്കിൽ ((sv->r & VT_VALMASK) != VT_LOCAL)
        തിരികെ 0;

    offset = (int64_t)sv->c.i;
    തിരികെ (offset & 7) == 0 && offset >= -512 && offset <= 504;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ arm64_int_reg_is_allocatable(പൂർണ്ണസംഖ്യ reg)
{
#ifdef TCC_TARGET_PE
    തിരികെ reg >= TREG_X0 && reg <= TREG_X17;
#അല്ലെങ്കിൽ
    തിരികെ reg >= TREG_X0 && reg <= TREG_X30;
#endif
}

സ്ഥിതം പൂർണ്ണസംഖ്യ arm64_memory_needs_address_reg(സ്ഥിരം SValue *sv)
{
    പൂർണ്ണസംഖ്യ r;

    r = sv->r & ~(VT_BOUNDED | VT_NONCONST);
    എങ്കിൽ (!(r & VT_LVAL))
        തിരികെ 0;
    തിരഞ്ഞെടുപ്പ് (r & VT_VALMASK) {
    അവസ്ഥ VT_LOCAL:
    അവസ്ഥ VT_LLOCAL:
    അവസ്ഥ VT_CONST:
        തിരികെ 1;
    }
    തിരികെ 0;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ arm64_prepare_memory_operand(ASMOperand *op, uint8_t *regs_allocated)
{
    പൂർണ്ണസംഖ്യ reg;

    എങ്കിൽ (!arm64_memory_needs_address_reg(op->vt))
        തിരികെ 1;

    വേണ്ടി (reg = 0; reg < 31; reg++) {
        എങ്കിൽ (arm64_int_reg_is_allocatable(reg)
            && !(regs_allocated[reg] & REG_IN_MASK)) {
            regs_allocated[reg] |= REG_IN_MASK;
            op->reg = reg;
            op->is_memory = 1;
            തിരികെ 1;
        }
    }
    തിരികെ 0;
}

സ്ഥിതം ശൂന്യം arm64_load_memory_operand_base(പൂർണ്ണസംഖ്യ reg, SValue *sv)
{
    SValue base;
    പൂർണ്ണസംഖ്യ rval;

    base = *sv;
    base.type.t = VT_PTR;
    rval = base.r & VT_VALMASK;
    എങ്കിൽ (rval == VT_LLOCAL) {
        base.r = (base.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
    } അല്ലെങ്കിൽ എങ്കിൽ (rval == VT_CONST || rval == VT_LOCAL) {
        base.r &= ~VT_LVAL;
    } അല്ലെങ്കിൽ {
        tcc_internal_error("unsupported ARM64 memory operand base");
    }
    load(reg, &base);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ operand_is_sp(സ്ഥിരം Operand *op)
{
    തിരികെ op->reg_tok == TOK_ASM_sp;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ parse_sysreg_name(പൂർണ്ണസംഖ്യ t)
{
    സ്ഥിരം അക്ഷരം *name;

    എങ്കിൽ (t < TOK_IDENT)
        തിരികെ -1;
    name = get_tok_str(t, ശൂന്യ);
    എങ്കിൽ (!strcmp(name, "FPCR") || !strcmp(name, "fpcr"))
        തിരികെ 0;
    എങ്കിൽ (!strcmp(name, "FPSR") || !strcmp(name, "fpsr"))
        തിരികെ 1;
    തിരികെ -1;
}

സ്ഥിതം ശൂന്യം gen_mrs(പൂർണ്ണസംഖ്യ rt, പൂർണ്ണസംഖ്യ sysreg)
{
    uint32_t instr;

    തിരഞ്ഞെടുപ്പ് (sysreg) {
        അവസ്ഥ 0: /* FPCR */
            instr = ARM64_MRS_FPCR;
            നിർത്തുക;
        അവസ്ഥ 1: /* FPSR */
            instr = ARM64_MRS_FPSR;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("unsupported system register");
            തിരികെ;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

സ്ഥിതം ശൂന്യം gen_msr(പൂർണ്ണസംഖ്യ rt, പൂർണ്ണസംഖ്യ sysreg)
{
    uint32_t instr;

    തിരഞ്ഞെടുപ്പ് (sysreg) {
        അവസ്ഥ 0: /* FPCR */
            instr = ARM64_MSR_FPCR;
            നിർത്തുക;
        അവസ്ഥ 1: /* FPSR */
            instr = ARM64_MSR_FPSR;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("unsupported system register");
            തിരികെ;
    }
    emit_instr32(instr | ARM64_RD(rt));
}

/* Generate NOP */
സ്ഥിതം ശൂന്യം gen_nop(ശൂന്യം)
{
    emit_instr32(ARM64_NOP);
}

/* Generate shift operations (LSL, LSR, ASR, ROR) */
സ്ഥിതം ശൂന്യം gen_shift(പൂർണ്ണസംഖ്യ rd, പൂർണ്ണസംഖ്യ rn, പൂർണ്ണസംഖ്യ rm_or_imm, പൂർണ്ണസംഖ്യ shift_type, പൂർണ്ണസംഖ്യ is_imm, പൂർണ്ണസംഖ്യ is_64bit)
{
    uint32_t instr;
    പൂർണ്ണസംഖ്യ width = is_64bit ? 64 : 32;

    എങ്കിൽ (is_imm) {
        /* Shift by immediate */
        തിരഞ്ഞെടുപ്പ് (shift_type) {
            അവസ്ഥ 0: /* LSL - UBFM alias */
                എങ്കിൽ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    തിരികെ;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R((width - rm_or_imm) & (width - 1));
                instr |= ARM64_IMM_S(width - rm_or_imm - 1);
                നിർത്തുക;
            അവസ്ഥ 1: /* LSR - UBFM alias: immr = shift, imms = width - 1 */
                എങ്കിൽ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    തിരികെ;
                }
                instr = is_64bit ? ARM64_LSL_IMM : ARM64_LSR_IMM_32;
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                നിർത്തുക;
            അവസ്ഥ 2: /* ASR - SBFM alias: immr = shift, imms = width - 1 */
                എങ്കിൽ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    തിരികെ;
                }
                instr = is_64bit ? ARM64_ASR_IMM : (ARM64_ASR_IMM & ~(1U << 31));
                instr |= ARM64_IMM_R(rm_or_imm);
                instr |= ARM64_IMM_S(width - 1);
                നിർത്തുക;
            അവസ്ഥ 3: /* ROR - EXTR alias: Rm = source, Rn = source, imms = shift */
                എങ്കിൽ (rm_or_imm < 0 || rm_or_imm >= width) {
                    tcc_error("shift immediate out of range");
                    തിരികെ;
                }
                instr = is_64bit ? ARM64_EXTR64 : ARM64_EXTR;
                instr |= ARM64_RM(rn);
                instr |= ARM64_IMM_S(rm_or_imm);
                instr |= ARM64_RN(rn);
                instr |= ARM64_RD(rd);
                emit_instr32(instr);
                തിരികെ;
            സ്ഥിരസ്ഥിതി:
                tcc_error("unknown shift type");
                തിരികെ;
        }
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    } അല്ലെങ്കിൽ {
        /* Shift by register */
        തിരഞ്ഞെടുപ്പ് (shift_type) {
            അവസ്ഥ 0: /* LSL */
                instr = ARM64_LSL_REG;
                നിർത്തുക;
            അവസ്ഥ 1: /* LSR */
                instr = ARM64_LSR_REG;
                നിർത്തുക;
            അവസ്ഥ 2: /* ASR */
                instr = ARM64_ASR_REG;
                നിർത്തുക;
            അവസ്ഥ 3: /* ROR */
                instr = ARM64_ROR_REG;
                നിർത്തുക;
            സ്ഥിരസ്ഥിതി:
                tcc_error("unknown shift type");
                തിരികെ;
        }
        എങ്കിൽ (is_64bit)
            instr |= ARM64_SF(1);
        instr |= ARM64_RM(rm_or_imm);
        instr |= ARM64_RN(rn);
        instr |= ARM64_RD(rd);
    }
    emit_instr32(instr);
}

/* Handle shift instructions */
സ്ഥിതം ശൂന്യം asm_shift(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand op1, op2, op3;
    പൂർണ്ണസംഖ്യ rd, rn, shift_amount;
    പൂർണ്ണസംഖ്യ shift_type;
    പൂർണ്ണസംഖ്യ is_64bit = 1;

    തിരഞ്ഞെടുപ്പ് (token) {
        അവസ്ഥ TOK_ASM_lsl:
            shift_type = 0;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_lsr:
            shift_type = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_asr:
            shift_type = 2;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_ror:
            shift_type = 3;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("unknown shift instruction");
            തിരികെ;
    }

    parse_operand(s1, &op1);
    എങ്കിൽ (tok == ',') next();
    parse_operand(s1, &op2);

    എങ്കിൽ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        തിരികെ;
    }
    എങ്കിൽ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        തിരികെ;
    }

    rd = op1.reg;
    rn = op2.reg;

    എങ്കിൽ (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        എങ്കിൽ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            തിരികെ;
        }
        എങ്കിൽ (op3.type & OP_REG) {
            എങ്കിൽ (is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                തിരികെ;
            }
            gen_shift(rd, rn, op3.reg, shift_type, 0, is_64bit);
        } അല്ലെങ്കിൽ എങ്കിൽ (op3.type & OP_IM) {
            shift_amount = op3.e.v;
            gen_shift(rd, rn, shift_amount, shift_type, 1, is_64bit);
        } അല്ലെങ്കിൽ {
            tcc_error("shift requires immediate or register operand");
        }
    } അല്ലെങ്കിൽ {
        tcc_error("shift requires immediate or register operand");
        തിരികെ;
    }
}

/* Generate barrier instructions (ISB, DSB, DMB) */
സ്ഥിതം ശൂന്യം gen_barrier(പൂർണ്ണസംഖ്യ barrier_type, പൂർണ്ണസംഖ്യ option)
{
    uint32_t instr;

    തിരഞ്ഞെടുപ്പ് (barrier_type) {
        അവസ്ഥ 0: /* ISB - Instruction Synchronization Barrier */
            instr = ARM64_ISB;
            നിർത്തുക;
        അവസ്ഥ 1: /* DSB - Data Synchronization Barrier */
            instr = ARM64_DSB;
            നിർത്തുക;
        അവസ്ഥ 2: /* DMB - Data Memory Barrier */
            instr = ARM64_DMB;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("unknown barrier type");
            തിരികെ;
    }
    instr |= ARM64_ISB_OPTION(option);
    emit_instr32(instr);
}

/* Handle barrier instructions */
സ്ഥിതം ശൂന്യം asm_barrier(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    പൂർണ്ണസംഖ്യ barrier_type, option;
    Operand op;

    തിരഞ്ഞെടുപ്പ് (token) {
        അവസ്ഥ TOK_ASM_isb:
            barrier_type = 0;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_dsb:
            barrier_type = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_dmb:
            barrier_type = 2;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("unknown barrier instruction");
            തിരികെ;
    }

    /* Default option = sy/full system. */
    option = 0xF;

    /* Check for an optional named or numeric barrier scope. */
    എങ്കിൽ (tok != TOK_LINEFEED) {
        option = parse_barrier_option_name(tok);
        എങ്കിൽ (option >= 0) {
            next();
        } അല്ലെങ്കിൽ {
            parse_operand(s1, &op);
            എങ്കിൽ (!(op.type & OP_IM) || op.e.sym) {
                tcc_error("barrier option must be an immediate or scope name");
                തിരികെ;
            }
            എങ്കിൽ (op.e.v > 0xF) {
                tcc_error("barrier option out of range");
                തിരികെ;
            }
            option = op.e.v;
        }
    }

    gen_barrier(barrier_type, option);
}

/* Generate immediate move sequence */
സ്ഥിതം ശൂന്യം gen_mov_imm(പൂർണ്ണസംഖ്യ rd, uint64_t imm, പൂർണ്ണസംഖ്യ is_64bit)
{
    uint16_t hw;
    പൂർണ്ണസംഖ്യ i, first = 1;

    വേണ്ടി (i = 0; i < (is_64bit ? 4 : 2); i++) {
        hw = (imm >> (i * 16)) & 0xFFFF;
        എങ്കിൽ (hw != 0 || i == 0) {
            എങ്കിൽ (first) {
                /* Pass halfword index (0-3), not bit count */
                gen_movz(rd, hw, i, is_64bit);
                first = 0;
            } അല്ലെങ്കിൽ {
                gen_movk(rd, hw, i, is_64bit);
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (!first) {
            gen_movk(rd, hw, i, is_64bit);
        }
    }
}

/* Handle mov instruction */
സ്ഥിതം ശൂന്യം asm_mov(TCCState *s1)
{
    Operand op1, op2;
    പൂർണ്ണസംഖ്യ rd, rn;
    പൂർണ്ണസംഖ്യ is_64bit;

    parse_operand(s1, &op1);
    എങ്കിൽ (tok == ',') next();
    parse_operand(s1, &op2);
    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);

    എങ്കിൽ (op2.type & OP_IM) {
        /* Handle immediate: mov x0, #123 */
        എങ്കിൽ (operand_is_sp(&op1)) {
            tcc_error("cannot move an immediate into sp");
            തിരികെ;
        }
        gen_mov_imm(rd, op2.e.v, is_64bit);
    } അല്ലെങ്കിൽ എങ്കിൽ (op2.type & OP_REG) {
        /* Handle register: mov x0, x1 */
        rn = op2.reg;
        എങ്കിൽ (operand_is_sp(&op1) || operand_is_sp(&op2))
            gen_add_imm(rd, rn, 0, 1, 0);
        അല്ലെങ്കിൽ
            gen_mov_reg(rd, rn, is_64bit);
    } അല്ലെങ്കിൽ {
        tcc_error("invalid operand for mov");
    }
}

/* Handle data processing instructions */
സ്ഥിതം ശൂന്യം asm_data_proc(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand op1, op2, op3;
    പൂർണ്ണസംഖ്യ rd, rn, rm;
    പൂർണ്ണസംഖ്യ is_64bit = 1;
    uint32_t opcode;

    തിരഞ്ഞെടുപ്പ് (token) {
        അവസ്ഥ TOK_ASM_add:
        അവസ്ഥ TOK_ASM_adds:
            opcode = token == TOK_ASM_add ? ARM64_ADD_REG : ARM64_ADDS_REG;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_sub:
        അവസ്ഥ TOK_ASM_subs:
            opcode = token == TOK_ASM_sub ? ARM64_SUB_REG : ARM64_SUBS_REG;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_and:
        അവസ്ഥ TOK_ASM_ands:
            opcode = token == TOK_ASM_and ? ARM64_AND_REG : ARM64_ANDS_REG;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_orr:
            opcode = ARM64_ORR_REG;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_eor:
            opcode = ARM64_EOR_REG;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_mul:
            opcode = ARM64_MUL_REG;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("unsupported data processing instruction");
            തിരികെ;
    }

    parse_operand(s1, &op1);
    എങ്കിൽ (tok == ',') next();
    parse_operand(s1, &op2);

    എങ്കിൽ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        തിരികെ;
    }
    എങ്കിൽ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        തിരികെ;
    }

    rd = op1.reg;
    rn = op2.reg;

    എങ്കിൽ (tok == ',') {
        next();
        parse_operand(s1, &op3);
        is_64bit = (op1.reg_type & REG_X);
        എങ്കിൽ (is_64bit != !!(op2.reg_type & REG_X)) {
            tcc_error("mismatched register widths");
            തിരികെ;
        }
        എങ്കിൽ (op3.type & OP_IM) {
            എങ്കിൽ (token == TOK_ASM_add || token == TOK_ASM_adds)
                gen_add_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_adds);
            അല്ലെങ്കിൽ എങ്കിൽ (token == TOK_ASM_sub || token == TOK_ASM_subs)
                gen_sub_imm(rd, rn, op3.e.v, is_64bit,
                            token == TOK_ASM_subs);
            അല്ലെങ്കിൽ എങ്കിൽ (token == TOK_ASM_and)
                gen_logical_imm(ARM64_AND_IMM, rd, rn, op3.e.v, is_64bit);
            അല്ലെങ്കിൽ എങ്കിൽ (token == TOK_ASM_ands)
                gen_logical_imm(ARM64_ANDS_IMM, rd, rn, op3.e.v, is_64bit);
            അല്ലെങ്കിൽ എങ്കിൽ (token == TOK_ASM_orr)
                gen_logical_imm(ARM64_ORR_IMM_BASE, rd, rn, op3.e.v, is_64bit);
            അല്ലെങ്കിൽ എങ്കിൽ (token == TOK_ASM_eor)
                gen_logical_imm(ARM64_EOR_IMM, rd, rn, op3.e.v, is_64bit);
            അല്ലെങ്കിൽ
                tcc_error("immediate operand not valid for this instruction");
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (!(op3.type & OP_REG)) {
                tcc_error("expected register in third operand");
                തിരികെ;
            }
            rm = op3.reg;
            എങ്കിൽ (is_64bit != !!(op2.reg_type & REG_X) || is_64bit != !!(op3.reg_type & REG_X)) {
                tcc_error("mismatched register widths");
                തിരികെ;
            }
            gen_dp_reg(opcode, rd, rn, rm, is_64bit);
        }
    } അല്ലെങ്കിൽ എങ്കിൽ (op2.type & OP_IM) {
        tcc_error("missing source register for immediate form");
    } അല്ലെങ്കിൽ {
        tcc_error("missing third operand");
    }
}

/* Handle load/store instructions */
സ്ഥിതം ശൂന്യം asm_ldst(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand op1, op2;
    പൂർണ്ണസംഖ്യ rt, rn;
    int32_t offset = 0;
    പൂർണ്ണസംഖ്യ size_log2 = 3;
    uint32_t base_opcode;

    parse_operand(s1, &op1);
    എങ്കിൽ (tok == ',') next();
    parse_operand(s1, &op2);

    എങ്കിൽ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        തിരികെ;
    }
    എങ്കിൽ (op2.type != OP_ADDR) {
        tcc_error("expected address operand in second operand");
        തിരികെ;
    }

    rt = op1.reg;
    rn = op2.reg;
    offset = op2.e.v;

    തിരഞ്ഞെടുപ്പ് (token) {
        അവസ്ഥ TOK_ASM_ldr:
            എങ്കിൽ (op1.reg_type & REG_X) {
                base_opcode = ARM64_LDR_X;
                size_log2 = 3;
            } അല്ലെങ്കിൽ എങ്കിൽ (op1.reg_type & REG_W) {
                base_opcode = ARM64_LDR_W;
                size_log2 = 2;
            } അല്ലെങ്കിൽ എങ്കിൽ (op1.reg_type & REG_D) {
                base_opcode = ARM64_LDR_D;
                size_log2 = 3;
            } അല്ലെങ്കിൽ {
                tcc_error("ldr requires a w, x, or d register");
                തിരികെ;
            }
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_ldrb:
            base_opcode = ARM64_LDR_B;
            size_log2 = 0;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_ldrh:
            base_opcode = ARM64_LDR_H;
            size_log2 = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_str:
            എങ്കിൽ (op1.reg_type & REG_X) {
                base_opcode = ARM64_STR_X;
                size_log2 = 3;
            } അല്ലെങ്കിൽ എങ്കിൽ (op1.reg_type & REG_W) {
                base_opcode = ARM64_STR_W;
                size_log2 = 2;
            } അല്ലെങ്കിൽ എങ്കിൽ (op1.reg_type & REG_D) {
                base_opcode = ARM64_STR_D;
                size_log2 = 3;
            } അല്ലെങ്കിൽ {
                tcc_error("str requires a w, x, or d register");
                തിരികെ;
            }
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_strb:
            base_opcode = ARM64_STR_B;
            size_log2 = 0;
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_strh:
            base_opcode = ARM64_STR_H;
            size_log2 = 1;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("unsupported load/store instruction");
            തിരികെ;
    }

    എങ്കിൽ (op2.addr_mode != ADDR_OFF)
        tcc_error("only offset addressing is implemented for ldr/str");
    gen_ldst_imm(base_opcode, rt, rn, offset, size_log2);
}

സ്ഥിതം ശൂന്യം asm_ldst_pair(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand op1, op2, op3;
    uint32_t base_opcode;
    പൂർണ്ണസംഖ്യ size_log2 = 3;

    parse_operand(s1, &op1);
    എങ്കിൽ (tok == ',')
        next();
    parse_operand(s1, &op2);
    എങ്കിൽ (tok == ',')
        next();
    parse_operand(s1, &op3);

    എങ്കിൽ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        തിരികെ;
    }
    എങ്കിൽ (!(op2.type & OP_REG)) {
        tcc_error("expected register in second operand");
        തിരികെ;
    }
    എങ്കിൽ (!(op3.type & OP_ADDR))
        tcc_error("pair load/store requires an address operand");

    എങ്കിൽ ((op1.reg_type & REG_X) && (op2.reg_type & REG_X)) {
        എങ്കിൽ (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_X_POST :
                          ARM64_STP_X;
        } അല്ലെങ്കിൽ {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_X_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_X_POST :
                          ARM64_LDP_X;
        }
    } അല്ലെങ്കിൽ എങ്കിൽ ((op1.reg_type & REG_D) && (op2.reg_type & REG_D)) {
        എങ്കിൽ (token == TOK_ASM_stp) {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_STP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_STP_D_POST :
                          ARM64_STP_D;
        } അല്ലെങ്കിൽ {
            base_opcode = op3.addr_mode == ADDR_PRE ? ARM64_LDP_D_PRE :
                          op3.addr_mode == ADDR_POST ? ARM64_LDP_D_POST :
                          ARM64_LDP_D;
        }
    } അല്ലെങ്കിൽ {
        tcc_error("stp/ldp requires matching x or d registers");
        തിരികെ;
    }

    gen_ldst_pair(base_opcode, op1.reg, op2.reg, op3.reg, op3.e.v, size_log2);
}

സ്ഥിതം ശൂന്യം asm_sysreg(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand op;
    പൂർണ്ണസംഖ്യ sysreg;

    എങ്കിൽ (token == TOK_ASM_mrs) {
        parse_operand(s1, &op);
        എങ്കിൽ (tok == ',')
            next();
        sysreg = parse_sysreg_name(tok);
        എങ്കിൽ (sysreg < 0)
            tcc_error("unsupported system register");
        next();
        gen_mrs(op.reg, sysreg);
        തിരികെ;
    }

    sysreg = parse_sysreg_name(tok);
    എങ്കിൽ (sysreg < 0)
        tcc_error("unsupported system register");
    next();
    എങ്കിൽ (tok == ',')
        next();
    parse_operand(s1, &op);
    gen_msr(op.reg, sysreg);
}

/* Get condition code from branch instruction token */
സ്ഥിതം പൂർണ്ണസംഖ്യ get_branch_condition(പൂർണ്ണസംഖ്യ branch_token)
{
    പൂർണ്ണസംഖ്യ cond_token;

    /* Map branch token to condition token (strip 'b' prefix) */
    തിരഞ്ഞെടുപ്പ് (branch_token) {
        അവസ്ഥ TOK_ASM_beq: cond_token = TOK_ASM_eq; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bne: cond_token = TOK_ASM_ne; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bcs:
        അവസ്ഥ TOK_ASM_bhs: cond_token = TOK_ASM_cs; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bcc:
        അവസ്ഥ TOK_ASM_blo: cond_token = TOK_ASM_cc; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bmi: cond_token = TOK_ASM_mi; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bpl: cond_token = TOK_ASM_pl; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bvs: cond_token = TOK_ASM_vs; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bvc: cond_token = TOK_ASM_vc; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bhi: cond_token = TOK_ASM_hi; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bls: cond_token = TOK_ASM_ls; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bge: cond_token = TOK_ASM_ge; നിർത്തുക;
        അവസ്ഥ TOK_ASM_blt: cond_token = TOK_ASM_lt; നിർത്തുക;
        അവസ്ഥ TOK_ASM_bgt: cond_token = TOK_ASM_gt; നിർത്തുക;
        അവസ്ഥ TOK_ASM_ble: cond_token = TOK_ASM_le; നിർത്തുക;
        സ്ഥിരസ്ഥിതി: തിരികെ -1;
    }

    തിരികെ parse_condition(cond_token);
}

/* Handle branch instructions */
സ്ഥിതം ശൂന്യം asm_branch(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand op;
    പൂർണ്ണസംഖ്യ cond;
    Sym *sym;
    int32_t offset;

    /* ret can be used without operand */
    എങ്കിൽ (token == TOK_ASM_ret && (tok == TOK_LINEFEED || tok == ';' || tok == TOK_EOF)) {
        gen_ret(30);  /* x30 is the link register */
        തിരികെ;
    }

    എങ്കിൽ (token == TOK_ASM_br || token == TOK_ASM_blr || token == TOK_ASM_ret)
        parse_operand(s1, &op);
    അല്ലെങ്കിൽ
        parse_വ്യഞ്ജകം_operand(s1, &op);

    എങ്കിൽ (op.type & OP_IM) {
        sym = op.e.sym;
        എങ്കിൽ (sym) {
            /* Symbolic address - emit relocation */
            offset = 0;

            cond = get_branch_condition(token);
            എങ്കിൽ (cond >= 0) {
                /* Conditional branch - use CONDBR19 relocation */
                gen_b_cond(cond, 0);
                greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
            } അല്ലെങ്കിൽ {
                തിരഞ്ഞെടുപ്പ് (token) {
                    അവസ്ഥ TOK_ASM_b:
                        gen_b(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_JUMP26, 0);
                        നിർത്തുക;
                    അവസ്ഥ TOK_ASM_bl:
                        gen_bl(0);
                        greloca(cur_text_section, sym, ind - 4, R_AARCH64_CALL26, 0);
                        നിർത്തുക;
                    സ്ഥിരസ്ഥിതി:
                        tcc_error("unsupported branch");
                }
            }
        } അല്ലെങ്കിൽ {
            offset = (int32_t)op.e.v - ind;

            cond = get_branch_condition(token);
            എങ്കിൽ (cond >= 0) {
                gen_b_cond(cond, offset);
            } അല്ലെങ്കിൽ {
                തിരഞ്ഞെടുപ്പ് (token) {
                    അവസ്ഥ TOK_ASM_b:
                        gen_b(offset);
                        നിർത്തുക;
                    അവസ്ഥ TOK_ASM_bl:
                        gen_bl(offset);
                        നിർത്തുക;
                    സ്ഥിരസ്ഥിതി:
                        tcc_error("unsupported branch");
                }
            }
        }
    } അല്ലെങ്കിൽ എങ്കിൽ (op.type & OP_REG) {
        തിരഞ്ഞെടുപ്പ് (token) {
            അവസ്ഥ TOK_ASM_br:
                gen_br(op.reg);
                നിർത്തുക;
            അവസ്ഥ TOK_ASM_blr:
                gen_blr(op.reg);
                നിർത്തുക;
            അവസ്ഥ TOK_ASM_ret:
                gen_ret(op.reg);
                നിർത്തുക;
            സ്ഥിരസ്ഥിതി:
                tcc_error("register branch not valid");
        }
    }
}

/* Handle CBZ/CBNZ */
സ്ഥിതം ശൂന്യം asm_cb(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand op1, op2;
    പൂർണ്ണസംഖ്യ rt, is_64bit;
    int32_t offset;
    Sym *sym;

    parse_operand(s1, &op1);
    എങ്കിൽ (tok == ',') next();
    parse_വ്യഞ്ജകം_operand(s1, &op2);

    rt = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    sym = op2.e.sym;

    എങ്കിൽ (sym) {
        /* Symbolic address - emit relocation */
        offset = 0;
        എങ്കിൽ (token == TOK_ASM_cbz) {
            gen_cbz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        } അല്ലെങ്കിൽ {
            gen_cbnz(rt, offset, is_64bit);
            greloca(cur_text_section, sym, ind - 4, R_AARCH64_CONDBR19, 0);
        }
    } അല്ലെങ്കിൽ {
        offset = (int32_t)op2.e.v - ind;
        എങ്കിൽ (token == TOK_ASM_cbz)
            gen_cbz(rt, offset, is_64bit);
        അല്ലെങ്കിൽ
            gen_cbnz(rt, offset, is_64bit);
    }
}

/* Handle MOVZ/MOVN/MOVK */
സ്ഥിതം ശൂന്യം asm_move_wide(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand op1, op2;
    പൂർണ്ണസംഖ്യ rd, is_64bit = 1;
    uint16_t imm;
    പൂർണ്ണസംഖ്യ shift = 0;

    parse_operand(s1, &op1);
    എങ്കിൽ (tok == ',') next();
    parse_operand(s1, &op2);

    എങ്കിൽ (!(op1.type & OP_REG)) {
        tcc_error("expected register in first operand");
        തിരികെ;
    }
    എങ്കിൽ (!(op2.type & OP_IM) || op2.e.sym) {
        tcc_error("expected immediate in second operand");
        തിരികെ;
    }

    rd = op1.reg;
    is_64bit = (op1.reg_type & REG_X);
    എങ്കിൽ ((uint64_t)op2.e.v > 0xFFFF) {
        tcc_error("move wide immediate out of range");
        തിരികെ;
    }
    imm = op2.e.v;

    എങ്കിൽ (tok == ',') {
        next();
        എങ്കിൽ (tok != TOK_ASM_lsl) {
            tcc_error("move wide shift must use lsl");
            തിരികെ;
        }
            next();
            എങ്കിൽ (tok == '#') next();
            asm_വ്യഞ്ജകം(s1, &op2.e);
        എങ്കിൽ (op2.e.sym || !is_valid_movw_shift((പൂർണ്ണസംഖ്യ)op2.e.v, is_64bit)) {
            tcc_error("move wide shift out of range");
            തിരികെ;
        }
            shift = (പൂർണ്ണസംഖ്യ)op2.e.v / 16;
        }

    തിരഞ്ഞെടുപ്പ് (token) {
        അവസ്ഥ TOK_ASM_movz:
            gen_movz(rd, imm, shift, is_64bit);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_movn:
            gen_movn(rd, imm, shift, is_64bit);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_movk:
            gen_movk(rd, imm, shift, is_64bit);
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("unknown move wide instruction");
    }
}

/* Main assembler opcode dispatcher */
ST_FUNC ശൂന്യം asm_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ opcode)
{
    തിരഞ്ഞെടുപ്പ് (opcode) {
        അവസ്ഥ TOK_ASM_add:
        അവസ്ഥ TOK_ASM_adds:
        അവസ്ഥ TOK_ASM_sub:
        അവസ്ഥ TOK_ASM_subs:
        അവസ്ഥ TOK_ASM_and:
        അവസ്ഥ TOK_ASM_ands:
        അവസ്ഥ TOK_ASM_orr:
        അവസ്ഥ TOK_ASM_eor:
        അവസ്ഥ TOK_ASM_mul:
            asm_data_proc(s1, opcode);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_mov:
            /* mov is handled separately - it's ORR with zero register */
            asm_mov(s1);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_lsl:
        അവസ്ഥ TOK_ASM_lsr:
        അവസ്ഥ TOK_ASM_asr:
        അവസ്ഥ TOK_ASM_ror:
            asm_shift(s1, opcode);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_ldr:
        അവസ്ഥ TOK_ASM_ldrb:
        അവസ്ഥ TOK_ASM_ldrh:
        അവസ്ഥ TOK_ASM_str:
        അവസ്ഥ TOK_ASM_strb:
        അവസ്ഥ TOK_ASM_strh:
            asm_ldst(s1, opcode);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_ldp:
        അവസ്ഥ TOK_ASM_stp:
            asm_ldst_pair(s1, opcode);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_b:
        അവസ്ഥ TOK_ASM_bl:
        അവസ്ഥ TOK_ASM_br:
        അവസ്ഥ TOK_ASM_blr:
        അവസ്ഥ TOK_ASM_ret:
        അവസ്ഥ TOK_ASM_beq:
        അവസ്ഥ TOK_ASM_bne:
        അവസ്ഥ TOK_ASM_bcs:
        അവസ്ഥ TOK_ASM_bhs:
        അവസ്ഥ TOK_ASM_bcc:
        അവസ്ഥ TOK_ASM_blo:
        അവസ്ഥ TOK_ASM_bmi:
        അവസ്ഥ TOK_ASM_bpl:
        അവസ്ഥ TOK_ASM_bvs:
        അവസ്ഥ TOK_ASM_bvc:
        അവസ്ഥ TOK_ASM_bhi:
        അവസ്ഥ TOK_ASM_bls:
        അവസ്ഥ TOK_ASM_bge:
        അവസ്ഥ TOK_ASM_blt:
        അവസ്ഥ TOK_ASM_bgt:
        അവസ്ഥ TOK_ASM_ble:
            asm_branch(s1, opcode);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_cbz:
        അവസ്ഥ TOK_ASM_cbnz:
            asm_cb(s1, opcode);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_movz:
        അവസ്ഥ TOK_ASM_movn:
        അവസ്ഥ TOK_ASM_movk:
            asm_move_wide(s1, opcode);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_mrs:
        അവസ്ഥ TOK_ASM_msr:
            asm_sysreg(s1, opcode);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_isb:
        അവസ്ഥ TOK_ASM_dsb:
        അവസ്ഥ TOK_ASM_dmb:
            asm_barrier(s1, opcode);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_nop:
            gen_nop();
            നിർത്തുക;

        സ്ഥിരസ്ഥിതി:
            tcc_error("ARM64 instruction '%s' not implemented",
                     get_tok_str(opcode, ശൂന്യ));
            നിർത്തുക;
    }
}

/* Substitute assembler operand */
ST_FUNC ശൂന്യം subst_asm_operand(CString *add_str, SValue *sv, പൂർണ്ണസംഖ്യ modifier)
{
    പൂർണ്ണസംഖ്യ r, reg, size, fp_reg, align;
    int64_t val;
    uint64_t uval;

    r = sv->r;
    എങ്കിൽ ((r & VT_VALMASK) == VT_CONST) {
        എങ്കിൽ ((modifier == 'w' || modifier == 'x') && !(r & VT_LVAL)
            && !(r & VT_SYM) && sv->c.i == 0) {
            cstr_cat(add_str, modifier == 'w' ? "wzr" : "xzr", -1);
            തിരികെ;
        }
        എങ്കിൽ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        എങ്കിൽ (r & VT_SYM) {
            സ്ഥിരം അക്ഷരം *name = get_tok_str(sv->sym->v, ശൂന്യ);
            എങ്കിൽ (sv->sym->v >= SYM_FIRST_ANOM)
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            എങ്കിൽ (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            എങ്കിൽ ((uint32_t) sv->c.i == 0)
                പോകുക no_offset;
            cstr_ccat(add_str, '+');
        }
        uval = sv->c.i;
        എങ്കിൽ (modifier == 'n') {
            val = -(int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        } അല്ലെങ്കിൽ എങ്കിൽ (uval > 0x7fffffffffffffffULL) {
            cstr_printf(add_str, "0x%llx", (unsigned long long)uval);
        } അല്ലെങ്കിൽ {
            val = (int64_t)uval;
            cstr_printf(add_str, "%lld", (long long)val);
        }
      no_offset:;
    } അല്ലെങ്കിൽ എങ്കിൽ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[x29,#%d]", (പൂർണ്ണസംഖ്യ) sv->c.i);
    } അല്ലെങ്കിൽ എങ്കിൽ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        എങ്കിൽ (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[x%d]", reg);
    } അല്ലെങ്കിൽ {
        /* register case */
        reg = r & VT_VALMASK;
        എങ്കിൽ (reg >= VT_CONST)
            tcc_internal_error("");

        എങ്കിൽ (ARM64_FREG_BASE <= reg && reg <= ARM64_FREG_LAST) {
            fp_reg = reg - ARM64_FREG_BASE;
            size = type_size(&sv->type, &align);

            എങ്കിൽ (modifier == 0)
                modifier = size <= 4 ? 's'
                         : size == 8 ? 'd'
                         : 'q';

            തിരഞ്ഞെടുപ്പ് (modifier) {
            അവസ്ഥ 'b':
            അവസ്ഥ 'h':
            അവസ്ഥ 's':
            അവസ്ഥ 'd':
            അവസ്ഥ 'q':
            അവസ്ഥ 'Z':
                cstr_printf(add_str, "%c%d", modifier == 'Z' ? 'z' : modifier,
                            fp_reg);
                തിരികെ;
            സ്ഥിരസ്ഥിതി:
                tcc_error("invalid operand modifier for SIMD/FP register");
                തിരികെ;
            }
        }

        /* choose register operand size */
        എങ്കിൽ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        അല്ലെങ്കിൽ എങ്കിൽ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        അല്ലെങ്കിൽ എങ്കിൽ ((sv->type.t & VT_BTYPE) == VT_LLONG ||
                 (sv->type.t & VT_BTYPE) == VT_PTR)
            size = 8;
        അല്ലെങ്കിൽ
            size = 4;

        എങ്കിൽ (modifier == 'x') {
            size = 8;
        } അല്ലെങ്കിൽ എങ്കിൽ (modifier == 'w' || modifier == 'k') {
            size = 4;
        } അല്ലെങ്കിൽ എങ്കിൽ (modifier == 'b') {
            size = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (modifier == 'h') {
            size = 2;
        } അല്ലെങ്കിൽ എങ്കിൽ (modifier == 'q') {
            size = 8;
        }

        എങ്കിൽ (size <= 4) {
            cstr_printf(add_str, "w%d", reg);
        } അല്ലെങ്കിൽ {
            cstr_printf(add_str, "x%d", reg);
        }
    }
}

ST_FUNC ശൂന്യം asm_gen_code(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands,
                          പൂർണ്ണസംഖ്യ nb_outputs, പൂർണ്ണസംഖ്യ is_output,
                          uint8_t *clobber_regs,
                          പൂർണ്ണസംഖ്യ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    പൂർണ്ണസംഖ്യ i, reg, saved_എണ്ണം, അട്ടി_size, അട്ടി_off;
    പൂർണ്ണസംഖ്യ saved_regs[12];
    സ്ഥിതം സ്ഥിരം uint8_t reg_saved[] = {
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30
    };

    memcpy(regs_allocated, clobber_regs, വലുപ്പം(regs_allocated));
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        എങ്കിൽ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }

    saved_എണ്ണം = 0;
    വേണ്ടി (i = 0; i < വലുപ്പം(reg_saved) / വലുപ്പം(reg_saved[0]); i++) {
        reg = reg_saved[i];
        എങ്കിൽ (regs_allocated[reg])
            saved_regs[saved_എണ്ണം++] = reg;
    }
    അട്ടി_size = ((saved_എണ്ണം + 1) / 2) * 16;

    എങ്കിൽ (!is_output) {
        എങ്കിൽ (saved_എണ്ണം > 0) {
            gen_sub_imm(31, 31, അട്ടി_size, 1, 0);

            വേണ്ടി (i = അട്ടി_off = 0; i < saved_എണ്ണം; ) {
                എങ്കിൽ (i + 1 < saved_എണ്ണം) {
                    gen_ldst_pair(ARM64_STP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, അട്ടി_off, 3);
                    അട്ടി_off += 16;
                    i += 2;
                } അല്ലെങ്കിൽ {
                    gen_ldst_imm(ARM64_STR_X, saved_regs[i], TREG_SP,
                                 അട്ടി_off, 3);
                    i++;
                }
            }
        }

        വേണ്ടി (i = 0; i < nb_operands; i++) {
            op = &operands[i];
            എങ്കിൽ (op->reg >= 0) {
                എങ്കിൽ (op->is_memory) {
                    arm64_load_memory_operand_base(op->reg, op->vt);
                } അല്ലെങ്കിൽ എങ്കിൽ (i >= nb_outputs || op->is_rw) {
                    load(op->reg, op->vt);
                }
            }
        }
    } അല്ലെങ്കിൽ {
        വേണ്ടി (i = 0; i < nb_outputs; i++) {
            op = &operands[i];
            എങ്കിൽ (op->reg >= 0) {
                എങ്കിൽ (op->is_memory)
                    തുടരുക;
                എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    എങ്കിൽ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } അല്ലെങ്കിൽ {
                    store(op->reg, op->vt);
                }
            }
        }

        എങ്കിൽ (saved_എണ്ണം > 0) {
            വേണ്ടി (i = അട്ടി_off = 0; i < saved_എണ്ണം; ) {
                എങ്കിൽ (i + 1 < saved_എണ്ണം) {
                    gen_ldst_pair(ARM64_LDP_X, saved_regs[i], saved_regs[i + 1],
                                  TREG_SP, അട്ടി_off, 3);
                    അട്ടി_off += 16;
                    i += 2;
                } അല്ലെങ്കിൽ {
                    gen_ldst_imm(ARM64_LDR_X, saved_regs[i], TREG_SP,
                                 അട്ടി_off, 3);
                    i++;
                }
            }
            gen_add_imm(31, 31, അട്ടി_size, 1, 0);
        }
    }
}

ST_FUNC ശൂന്യം asm_compute_constraints(ASMOperand *operands,
                                    പൂർണ്ണസംഖ്യ nb_operands, പൂർണ്ണസംഖ്യ nb_outputs,
                                    സ്ഥിരം uint8_t *clobber_regs,
                                    പൂർണ്ണസംഖ്യ *pout_reg)
{
    ASMOperand *op;
    പൂർണ്ണസംഖ്യ sorted_op[MAX_ASM_OPERANDS];
    പൂർണ്ണസംഖ്യ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    സ്ഥിരം അക്ഷരം *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    വേണ്ടി (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->നിവേശം_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
        op->is_llong = 0;
    }

    വേണ്ടി (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        എങ്കിൽ (isnum(*str) || *str == '[') {
            k = find_constraint(operands, nb_operands, str, ശൂന്യ);
            എങ്കിൽ ((unsigned)k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')", i, str);
            op->ref_index = k;
            എങ്കിൽ (operands[k].നിവേശം_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].നിവേശം_index = i;
            op->priority = 5;
        } അല്ലെങ്കിൽ എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } അല്ലെങ്കിൽ {
            op->priority = constraint_priority(str);
        }
    }

    വേണ്ടി (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    വേണ്ടി (i = 0; i < nb_operands - 1; i++) {
        വേണ്ടി (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            എങ്കിൽ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    വേണ്ടി (i = 0; i < NB_ASM_REGS; i++) {
        എങ്കിൽ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        അല്ലെങ്കിൽ
            regs_allocated[i] = 0;
    }

    വേണ്ടി (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        എങ്കിൽ (op->ref_index >= 0)
            തുടരുക;
        എങ്കിൽ (op->നിവേശം_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } അല്ലെങ്കിൽ എങ്കിൽ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } അല്ലെങ്കിൽ {
            reg_mask = REG_IN_MASK;
        }
        എങ്കിൽ (op->reg >= 0) {
            എങ്കിൽ (is_reg_allocated(op->reg))
                tcc_error("asm regvar requests register that's taken already");
            reg = op->reg;
            പോകുക reg_found;
        }
    try_next:
        c = *str++;
        തിരഞ്ഞെടുപ്പ് (c) {
        അവസ്ഥ '=':
            പോകുക try_next;
        അവസ്ഥ '+':
            op->is_rw = 1;
        അവസ്ഥ '&':
            എങ്കിൽ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            പോകുക try_next;
        അവസ്ഥ 'r':
            വേണ്ടി (reg = 0; reg < 31; reg++) {
                എങ്കിൽ (arm64_int_reg_is_allocatable(reg)
                    && !is_reg_allocated(reg))
                    പോകുക reg_found;
            }
            പോകുക try_next;
        അവസ്ഥ 'w':
        അവസ്ഥ 'f':
            വേണ്ടി (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                എങ്കിൽ (!is_reg_allocated(reg))
                    പോകുക reg_found;
            }
            പോകുക try_next;
        അവസ്ഥ 'x':
        അവസ്ഥ 'y':
            വേണ്ടി (reg = ARM64_FREG_BASE; reg <= ARM64_FREG_LAST; reg++) {
                എങ്കിൽ (!is_reg_allocated(reg))
                    പോകുക reg_found;
            }
            പോകുക try_next;
        അവസ്ഥ 'm':
        അവസ്ഥ 'g':
            എങ്കിൽ (j < nb_outputs || c == 'm') {
                എങ്കിൽ (!arm64_prepare_memory_operand(op, regs_allocated))
                    പോകുക try_next;
            }
            നിർത്തുക;
        അവസ്ഥ 'Q':
            എങ്കിൽ (!arm64_memory_is_base_only(op->vt))
                പോകുക try_next;
            എങ്കിൽ (!arm64_prepare_memory_operand(op, regs_allocated))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'S':
            എങ്കിൽ ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != (VT_CONST | VT_SYM))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'U':
            എങ്കിൽ (str[0] != 'm' || str[1] != 'p')
                പോകുക try_next;
            str += 2;
            എങ്കിൽ (!arm64_memory_is_pair_suitable(op->vt))
                പോകുക try_next;
            എങ്കിൽ (!arm64_prepare_memory_operand(op, regs_allocated))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'i':
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'I':
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                പോകുക try_next;
            എങ്കിൽ (!is_valid_add_imm(op->vt->c.i))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'J':
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                പോകുക try_next;
            എങ്കിൽ (!is_valid_add_imm(-op->vt->c.i))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'K':
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                പോകുക try_next;
            എങ്കിൽ (!is_valid_logical_imm(op->vt->c.i, 32))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'L':
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                പോകുക try_next;
            എങ്കിൽ (!is_valid_logical_imm(op->vt->c.i, 64))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'M':
        അവസ്ഥ 'N':
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                പോകുക try_next;
            എങ്കിൽ (!is_valid_movw_imm(op->vt->c.i))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'Z':
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST))
                പോകുക try_next;
            എങ്കിൽ (op->vt->c.i != 0)
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'n':
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                പോകുക try_next;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                       j, op->constraint);
            നിർത്തുക;
        }
        എങ്കിൽ (op->നിവേശം_index >= 0) {
            operands[op->നിവേശം_index].reg = op->reg;
            operands[op->നിവേശം_index].is_llong = op->is_llong;
        }
        തുടരുക;
    reg_found:
        op->is_llong = 0;
        op->reg = reg;
        regs_allocated[reg] |= reg_mask;
        എങ്കിൽ (op->നിവേശം_index >= 0) {
            operands[op->നിവേശം_index].reg = op->reg;
            operands[op->നിവേശം_index].is_llong = op->is_llong;
        }
    }

    *pout_reg = -1;
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        എങ്കിൽ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL &&
            !op->is_memory) {
            വേണ്ടി (reg = 0; reg < 31; reg++) {
                എങ്കിൽ (!(regs_allocated[reg] & REG_OUT_MASK))
                    പോകുക reg_found2;
            }
            tcc_error("could not find free output register for reloading");
        reg_found2:
            *pout_reg = reg;
            നിർത്തുക;
        }
    }
}

/* Handle clobber list */
ST_FUNC ശൂന്യം asm_clobber(uint8_t *clobber_regs, സ്ഥിരം അക്ഷരം *str)
{
    പൂർണ്ണസംഖ്യ reg;

    എങ്കിൽ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        തിരികെ;

    reg = arm64_parse_regvar(tok_alloc_const(str));
    എങ്കിൽ (reg == -1)
        tcc_error("invalid clobber register '%s'", str);
    clobber_regs[reg] = 1;
}

/* Parse register variable - this is the ST_FUNC that tcc.h expects */
ST_FUNC പൂർണ്ണസംഖ്യ asm_parse_regvar(പൂർണ്ണസംഖ്യ t)
{
    തിരികെ arm64_parse_regvar(t);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
