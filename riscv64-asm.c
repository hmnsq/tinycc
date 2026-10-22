/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

#ವ್ಯಾಖ್ಯಾನಿಸು CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#ವ್ಯಾಖ್ಯಾನಿಸು NB_ASM_REGS 64

ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಂಕ c);

/*************************************************************/
#ಇಲ್ಲದಿದ್ದರೆ
/*************************************************************/
#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

ಎಣಿಕೆ {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#ವ್ಯಾಖ್ಯಾನಿಸು REG_FLOAT_ಮುಖವಾಡ 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು REG_IS_FLOAT(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) ((ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) & REG_FLOAT_ಮುಖವಾಡ)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಮೌಲ್ಯ(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ)    ((ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) & (REG_FLOAT_ಮುಖವಾಡ-1))
#ವ್ಯಾಖ್ಯಾನಿಸು C_ENCODE_RS1(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) (REG_ಮೌಲ್ಯ(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) << 7)
#ವ್ಯಾಖ್ಯಾನಿಸು C_ENCODE_RS2(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) (REG_ಮೌಲ್ಯ(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) << 2)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_RD(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ)  (REG_ಮೌಲ್ಯ(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) << 7)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_RS1(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) (REG_ಮೌಲ್ಯ(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) << 15)
#ವ್ಯಾಖ್ಯಾನಿಸು ENCODE_RS2(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) (REG_ಮೌಲ್ಯ(ರಿಜಿಸ್ಟರ್_ಸೂಚ್ಯಂಕ) << 20)
#ವ್ಯಾಖ್ಯಾನಿಸು NTH_ಬಿಟ್(b, n) ((b >> n) & 1)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_IM12S (1 << OPT_IM12S)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_IM32 (1 << OPT_IM32)
#ವ್ಯಾಖ್ಯಾನಿಸು OP_REG (1 << OPT_REG)

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಕಾರ್ಯಾಂಶ {
    uint32_t type;
    ಒಕ್ಕೂಟ {
        uint8_t reg;
        uint16_t regset;
        ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    };
} ಕಾರ್ಯಾಂಶ;

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ zero = { OP_REG, { 0 }};
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ ra = { OP_REG, { 1 }};
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ zimm = { OP_IM12S };

ಸ್ಥಿರ ಶೂನ್ಯ asm_ದ್ವಿಮಾನ_opcode(TCCState* s1, ಪೂರ್ಣಾಂಕ token);
ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str);
ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands, ಪೂರ್ಣಾಂಕ nb_outputs, ಸ್ಥಿರಾಂಕ uint8_t *clobber_regs, ಪೂರ್ಣಾಂಕ *pout_reg);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_a(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd1, ಪೂರ್ಣಾಂಕ aq, ಪೂರ್ಣಾಂಕ rl);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_b(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_i(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_j(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_opcode(uint32_t opcode);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_r(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_s(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_u(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_f(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_fb(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_fq(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs3);
ST_FUNC ಶೂನ್ಯ asm_gen_ಸಂಕೇತ(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands, ಪೂರ್ಣಾಂಕ nb_outputs, ಪೂರ್ಣಾಂಕ is_output, uint8_t *clobber_regs, ಪೂರ್ಣಾಂಕ ಹೊರಹೋಗು_reg);
ಸ್ಥಿರ ಶೂನ್ಯ asm_nullary_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token);
ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asm_parse_csrvar(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಪೂರ್ಣಾಂಕ asm_parse_regvar(ಪೂರ್ಣಾಂಕ t);
ಸ್ಥಿರ ಶೂನ್ಯ asm_ternary_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token);
ಸ್ಥಿರ ಶೂನ್ಯ asm_unary_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token);
ಸ್ಥಿರ ಶೂನ್ಯ asm_branch_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token, ಪೂರ್ಣಾಂಕ argc);
ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe);
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op);
ಸ್ಥಿರ ಶೂನ್ಯ parse_branch_ಸ್ಥಾನಾಂತರ_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op);
ಸ್ಥಿರ ಶೂನ್ಯ parse_operands(TCCState *s1, ಕಾರ್ಯಾಂಶ *ops, ಪೂರ್ಣಾಂಕ ಎಣಿಕೆ_3);
ಸ್ಥಿರ ಶೂನ್ಯ parse_mem_access_operands(TCCState *s1, ಕಾರ್ಯಾಂಶ* ops);
ST_FUNC ಶೂನ್ಯ subst_asm_ಕಾರ್ಯಾಂಶ(CString *ಕೂಡಿಸು_str, SValue *sv, ಪೂರ್ಣಾಂಕ modifier);
/* C extension */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ca(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cb(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ci(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ciw(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cj(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cl(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cr(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cs(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_css(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm);

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

ST_FUNC ಶೂನ್ಯ gen_le16 (ಪೂರ್ಣಾಂಕ i)
{
    g(i);
    g(i>>8);
}

ST_FUNC ಶೂನ್ಯ gen_le32 (ಪೂರ್ಣಾಂಕ i)
{
    ಪೂರ್ಣಾಂಕ ind1;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    ind1 = ind + 4;
    ಆದರೆ (ind1 > cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_allocated)
        section_realloc(cur_ಪಠ್ಯ_section, ind1);
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = i & 0xFF;
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = (i >> 8) & 0xFF;
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = (i >> 16) & 0xFF;
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    gen_le32(pe->v);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_nullary_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಆಯ್ಕೆ (token) {
    // Sync instructions

    ಸ್ಥಿತಿ TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        ಹಿಂತಿರುಗಿ;

    // System calls

    ಸ್ಥಿತಿ TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        ಹಿಂತಿರುಗಿ;

    // Other

    ಸ್ಥಿತಿ TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        ಹಿಂತಿರುಗಿ;

    /* Pseudoinstructions */
    ಸ್ಥಿತಿ TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        ಹಿಂತಿರುಗಿ;

    /* C extension */
    ಸ್ಥಿತಿ TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        ಹಿಂತಿರುಗಿ;

    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op)
{
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    ಆದರೆ ((reg = asm_parse_regvar(tok)) != -1) {
        ಮುಂದಿನ(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        ಹಿಂತಿರುಗಿ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == '$') {
        /* constant value */
        ಮುಂದಿನ(); // skip '#' or '$'
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((e.v = asm_parse_csrvar(tok)) != -1) {
        ಮುಂದಿನ();
    } ಇಲ್ಲದಿದ್ದರೆ {
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ಆದರೆ (!op->e.sym) {
        ಆದರೆ ((ಪೂರ್ಣಾಂಕ) op->e.v >= -0x1000 && (ಪೂರ್ಣಾಂಕ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        ಆದರೆ (op->e.sym->type.t & VT_STATIC)
            greloca(cur_ಪಠ್ಯ_section, op->e.sym, ind, R_RISCV_PCREL_HI20, 0);
        ಇಲ್ಲದಿದ್ದರೆ
            greloca(cur_ಪಠ್ಯ_section, op->e.sym, ind, R_RISCV_GOT_HI20, 0);
        put_extern_sym(&label, cur_ಪಠ್ಯ_section, ind, 0);
        greloca(cur_ಪಠ್ಯ_section, &label, ind+4, R_RISCV_PCREL_LO12_I, 0);

        op->type = OP_IM12S;
        op->e.v = 0;
    } ಇಲ್ಲದಿದ್ದರೆ {
        expect("operand");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_branch_ಸ್ಥಾನಾಂತರ_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op){
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e = {0};

    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ಆದರೆ (!op->e.sym) {
        ಆದರೆ ((ಪೂರ್ಣಾಂಕ) op->e.v >= -0x1000 && (ಪೂರ್ಣಾಂಕ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } ಇಲ್ಲದಿದ್ದರೆ {
        expect("operand");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_jump_ಸ್ಥಾನಾಂತರ_ಕಾರ್ಯಾಂಶ(TCCState *s1, ಕಾರ್ಯಾಂಶ *op){
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e = {0};

    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ಆದರೆ (!op->e.sym) {
        ಆದರೆ ((ಪೂರ್ಣಾಂಕ) op->e.v >= -0x1000 && (ಪೂರ್ಣಾಂಕ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_ಪಠ್ಯ_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } ಇಲ್ಲದಿದ್ದರೆ {
        expect("operand");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_operands(TCCState *s1, ಕಾರ್ಯಾಂಶ* ops, ಪೂರ್ಣಾಂಕ ಎಣಿಕೆ_3){
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 0; i < ಎಣಿಕೆ_3; i++) {
        ಆದರೆ ( i != 0 )
            skip(',');
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
ಸ್ಥಿರ ಶೂನ್ಯ parse_mem_access_operands(TCCState *s1, ಕಾರ್ಯಾಂಶ* ops){

    ಕಾರ್ಯಾಂಶ op;

    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
    skip(',');
    ಆದರೆ ( tok == '(') {
        /* `X, (Y)` case*/
        ಮುಂದಿನ();
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } ಇಲ್ಲದಿದ್ದರೆ {
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[2]);
        ಆದರೆ ( tok == '('){
            /* `X, imm(Y)` case*/
            ಮುಂದಿನ();
            parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
            skip(')');
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* `X, Y` case*/
            /* we parsed Y thinking it was imm, swap and default imm to zero */
            op = ops[2];
            ops[1] = ops[2];
            ops[2] = op;
            ops[2] = zimm;
        }
    }
}

/* This is special: First operand is optional */
ಸ್ಥಿರ ಶೂನ್ಯ asm_jal_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token){
    ಕಾರ್ಯಾಂಶ ops[2];

    ಆದರೆ (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } ಇಲ್ಲದಿದ್ದರೆ {
        // jal reg, offset
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
        ಆದರೆ ( tok == ',') ಮುಂದಿನ(); ಇಲ್ಲದಿದ್ದರೆ expect("','");
    }
    parse_jump_ಸ್ಥಾನಾಂತರ_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
ಸ್ಥಿರ ಶೂನ್ಯ asm_jalr_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token){
    ಕಾರ್ಯಾಂಶ ops[3];
    ಕಾರ್ಯಾಂಶ op;

    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
    ಆದರೆ ( tok == ',')
        ಮುಂದಿನ();
    ಇಲ್ಲದಿದ್ದರೆ {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ ( tok == '(') {
        /* `X, (Y)` case*/
        ಮುಂದಿನ();
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } ಇಲ್ಲದಿದ್ದರೆ {
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[2]);
        ಆದರೆ ( tok == '('){
            /* `X, imm(Y)` case*/
            ಮುಂದಿನ();
            parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
            skip(')');
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* `X, Y` case*/
            /* we parsed Y thinking it was imm, swap and default imm to zero */
            op = ops[2];
            ops[1] = ops[2];
            ops[2] = op;
            ops[2] = zimm;
        }
    }
    /* jalr(RD, RS1, IMM); I-format */
    asm_emit_i(token, 0x67 | (0 << 12), &ops[0], &ops[1], &ops[2]);
}


ಸ್ಥಿರ ಶೂನ್ಯ asm_unary_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    ಕಾರ್ಯಾಂಶ op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    ಆಯ್ಕೆ (token) {
    /* pseudoinstructions */
    ಸ್ಥಿತಿ TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_ಪಠ್ಯ_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_ಬಾಲ:
        /* auipc x6, 0 */
        greloca(cur_ಪಠ್ಯ_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        ಹಿಂತಿರುಗಿ;

    /* C extension */
    ಸ್ಥಿತಿ TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        ಹಿಂತಿರುಗಿ;

    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("unary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_u(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs2)
{
    ಆದರೆ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ಖಾಲಿ));
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, ಖಾಲಿ));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ parse_fence_ಕಾರ್ಯಾಂಶ(){
    ಪೂರ್ಣಾಂಕ t = tok;
    ಆದರೆ ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    ಮುಂದಿನ();
    ಹಿಂತಿರುಗಿ t - (TOK_ASM_w_fence - 1);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_fence_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    ಪೂರ್ಣಾಂಕ succ = 0xF, pred = 0xF;
    ಆದರೆ (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_ಕಾರ್ಯಾಂಶ();
        ಆದರೆ ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, ಖಾಲಿ));
        }
        skip(',');
        succ = parse_fence_ಕಾರ್ಯಾಂಶ();
        ಆದರೆ ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, ಖಾಲಿ));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ದ್ವಿಮಾನ_opcode(TCCState* s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ imm = { OP_IM12S };
    ಕಾರ್ಯಾಂಶ ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    ಆಯ್ಕೆ (token) {
    ಸ್ಥಿತಿ TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        ಹಿಂತಿರುಗಿ;

    /* C extension */
    ಸ್ಥಿತಿ TOK_ASM_c_ಕೂಡಿಸು:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        ಹಿಂತಿರುಗಿ;

#ವ್ಯಾಖ್ಯಾನಿಸು CA (1 | (3 << 10) | (4 << 13))
    ಸ್ಥಿತಿ TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು CA

    ಸ್ಥಿತಿ TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;

    /* F/D extension */
    ಸ್ಥಿತಿ TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        ಹಿಂತಿರುಗಿ;

    /* pseudoinstructions */
    /* rd, sym */
    ಸ್ಥಿತಿ TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_li:
        ಆದರೆ(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, ಖಾಲಿ));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        ಆದರೆ(lo < 0){
            hi += 1;
        }
        imm.e.v = ((hi + 0x800) & 0xfffff000) >> 12;
        /* lui rd, HI_20(HI_32(imm)) */
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &imm);
        /* addi rd, rd, LO_12(HI_32(imm)) */
        imm.e.v = (int32_t)hi<<20>>20;
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[0], &imm);
        /* slli rd, rd, 12 */
        imm.e.v = 12;
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[0], &imm);
        /* addi rd, rd, HI_12(LO_32(imm)) */
        imm.e.v = (lo + (1<<19)) >> 20;
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[0], &imm);
        /* slli rd, rd, 12 */
        imm.e.v = 12;
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[0], &imm);
        /* addi rd, rd, HI_12(LO_20(LO_32imm)) */
        lo = lo << 12 >> 12;
        imm.e.v = lo >> 8;
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[0], &imm);
        /* slli rd, rd,  8 */
        imm.e.v = 8;
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[0], &imm);
        /* addi rd, rd, LO_8(LO_20(LO_32imm)) */
        lo &= 0xff;
        imm.e.v = lo << 20 >> 20;
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[0], &imm);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ಹಿಂತಿರುಗಿ;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    ಸ್ಥಿತಿ TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_ಪಠ್ಯ_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ಹಿಂತಿರುಗಿ;

    /* CSR pseudo-instructions */
    ಸ್ಥಿತಿ TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ಹಿಂತಿರುಗಿ;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_r(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs2)
{
    ಆದರೆ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, ಖಾಲಿ));
    }
    /* R-type instruction:
	     31...25 funct7
	     24...20 rs2
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg));
}

/* caller: Add rounding mode, fmt, funct5 to opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_f(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs2)
{
    ಆದರೆ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ಖಾಲಿ));
    }
    /* F-type instruction:
	     31...27 funct5
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode = OP-FP */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg));
}
/* caller: Add rounding mode, fmt, funct5 to opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_fb(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs)
{
    ಆದರೆ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, ಖಾಲಿ));
    }
    /* F-type instruction:
	     31...27 funct5
	     26...25 fmt
	     24...20 rs2 = 0
	     19...15 rs1 = rs
	     14...12 rm
	     11...7 rd
	     6...0 opcode = OP-FP */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs->reg) | ENCODE_RS2(0));
}
/* caller: Add rounding mode, fmt to opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_fq(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs3)
{
    ಆದರೆ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, ಖಾಲಿ));
    }
    /* F-type instruction:
	     31...27 rs3
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (REG_ಮೌಲ್ಯ(rs3->reg) << 27));
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_i(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs2)
{
    ಆದರೆ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ಖಾಲಿ));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_j(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs2)
{
    uint32_t imm;

    ಆದರೆ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ಖಾಲಿ));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    ಆದರೆ ((ಪೂರ್ಣಾಂಕ)imm > (1 << 20) -1 || (ಪೂರ್ಣಾಂಕ)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, ಖಾಲಿ));
    }
    /* J-type instruction:
    31      imm[20]
    30...21 imm[10:1]
    20      imm[11]
    19...12 imm[19:12]
    11...7  rd
    6...0   opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (((imm >> 20) & 1) << 31) | (((imm >> 1) & 0x3ff) << 21) | (((imm >> 11) & 1) << 20) | (((imm >> 12) & 0xff) << 12));
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_mem_access_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{

    ಕಾರ್ಯಾಂಶ ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    ಆದರೆ (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    ಆಯ್ಕೆ (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    ಸ್ಥಿತಿ TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    ಸ್ಥಿತಿ TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_branch_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token, ಪೂರ್ಣಾಂಕ argc)
{
    ಕಾರ್ಯಾಂಶ ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_ಸ್ಥಾನಾಂತರ_ಕಾರ್ಯಾಂಶ(s1, &ops[argc-1]);

    ಆಯ್ಕೆ(token){
    /* branch (RS1, RS2, IMM); B-format */
    ಸ್ಥಿತಿ TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    /* related pseudoinstructions */
    ಸ್ಥಿತಿ TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        ಹಿಂತಿರುಗಿ;
    /* shorter pseudoinstructions */
    ಸ್ಥಿತಿ TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        ಹಿಂತಿರುಗಿ;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ternary_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[3];
    parse_operands(s1, &ops[0], 3);

    ಆಯ್ಕೆ (token) {
    ಸ್ಥಿತಿ TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ಹಿಂತಿರುಗಿ;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    ಸ್ಥಿತಿ TOK_ASM_ಕೂಡಿಸು:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    ಸ್ಥಿತಿ TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    ಸ್ಥಿತಿ TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ಹಿಂತಿರುಗಿ;

    /* M extension */
    ಸ್ಥಿತಿ TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    ಸ್ಥಿತಿ TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        ಹಿಂತಿರುಗಿ;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    ಸ್ಥಿತಿ TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;

    /* F/D extension */
    ಸ್ಥಿತಿ TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ಹಿಂತಿರುಗಿ;

    /* F/D comparison: produce integer result, encode manually */
    ಸ್ಥಿತಿ TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಹಿಂತಿರುಗಿ;

    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("ternary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_quaternary_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[4];
    parse_operands(s1, &ops[0], 4);

    ಆಯ್ಕೆ (token) {
    ಸ್ಥಿತಿ TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ಹಿಂತಿರುಗಿ;

    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("quaternary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_atomic_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[3];

    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
    skip(',');

    ಆದರೆ ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } ಇಲ್ಲದಿದ್ದರೆ {
        parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[2]);
    skip(')');

    ಆಯ್ಕೆ(token){
        ಸ್ಥಿತಿ TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ನಿಲ್ಲಿಸು;

        /* AMO instructions (base, aq=0 rl=0) */
        ಸ್ಥಿತಿ TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ನಿಲ್ಲಿಸು;

        /* AMO aq/rl variants */
        ಸ್ಥಿತಿ TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ನಿಲ್ಲಿಸು;
    }
}

/* caller: Add funct3 and func5 to opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_a(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಪೂರ್ಣಾಂಕ aq, ಪೂರ್ಣಾಂಕ rl)
{
    ಆದರೆ (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    ಆದರೆ (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    ಆದರೆ (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, ಖಾಲಿ));
        /* A-type instruction:
	        31...27 funct5
	        26      aq
	        25      rl
	        24...20 rs2
	        19...15 rs1
	        14...11 funct3
	        11...7  rd
	        6...0 opcode
        opcode always fixed pos. */
    gen_le32(opcode | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | ENCODE_RD(rd1->reg) | aq << 26 | rl << 25);
}

/* caller: Add funct3 to opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_s(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ* imm)
{
    ಆದರೆ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, ಖಾಲಿ));
    }
    {
        uint16_t v = imm->e.v;
        /* S-type instruction:
	        31...25 imm[11:5]
	        24...20 rs2
	        19...15 rs1
	        14...12 funct3
	        11...7 imm[4:0]
	        6...0 opcode
        opcode always fixed pos. */
        gen_le32(opcode | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | ((v & 0x1F) << 7) | ((v >> 5) << 25));
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_b(ಪೂರ್ಣಾಂಕ token, uint32_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm)
{
    uint32_t ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }
    ಆದರೆ (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        ಪೂರ್ಣಾಂಕ b_ofs = ind;
        uint32_t inv_func3 = ((opcode >> 12) & 7) ^ 1;
        uint32_t inv_opcode = (opcode & ~(7 << 12)) | (inv_func3 << 12);
        /* b<inverse> .+8 */
        asm_emit_opcode(inv_opcode | ENCODE_RS1(rs1->reg)
                        | ENCODE_RS2(rs2->reg) | (1 << 8));
        /* auipc t0, 0 */
        greloca(cur_ಪಠ್ಯ_section, imm->e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(0x17 | ENCODE_RD(5));
        /* jalr x0, 0(t0) */
        write32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + b_ofs,
                  read32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + b_ofs)
                  | (((ind - b_ofs) >> 1) & 0xf) << 8
                  | (((ind - b_ofs) >> 5) & 0x3f) << 25
                  | (((ind - b_ofs) >> 11) & 1) << 7
                  | (((ind - b_ofs) >> 12) & 1) << 31);
        ಹಿಂತಿರುಗಿ;
    }
    ಆದರೆ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ಖಾಲಿ));
    }

    ಸ್ಥಾನಾಂತರ = imm->e.v;

    /* B-type instruction:
    31      imm[12]
    30...25 imm[10:5]
    24...20 rs2
    19...15 rs1
    14...12 funct3
    8...11  imm[4:1]
    7       imm[11]
    6...0   opcode */
    asm_emit_opcode(opcode | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (((ಸ್ಥಾನಾಂತರ >> 1) & 0xF) << 8) | (((ಸ್ಥಾನಾಂತರ >> 5) & 0x1f) << 25) | (((ಸ್ಥಾನಾಂತರ >> 11) & 1) << 7) | (((ಸ್ಥಾನಾಂತರ >> 12) & 1) << 31));
}

/* FCVT helper: parse optional rounding mode operand (GNU as syntax:
   fcvt.w.s rd, rs1 [, rtz/rne/rdn/rup/rmm]) */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asm_fcvt_rm(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ rm = 7; /* dynamic */
    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ();
        ಆಯ್ಕೆ (tok) {
            ಸ್ಥಿತಿ TOK_ASM_rne: rm = 0; ಮುಂದಿನ(); ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_ASM_rtz: rm = 1; ಮುಂದಿನ(); ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_ASM_rdn: rm = 2; ಮುಂದಿನ(); ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_ASM_rup: rm = 3; ಮುಂದಿನ(); ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_ASM_rmm: rm = 4; ಮುಂದಿನ(); ನಿಲ್ಲಿಸು;
            ಪೂರ್ವನಿಯೋಜಿತ: expect("rounding mode"); ನಿಲ್ಲಿಸು;
        }
    }
    ಹಿಂತಿರುಗಿ rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
ಸ್ಥಿರ ಶೂನ್ಯ asm_fcvt_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಕಾರ್ಯಾಂಶ ops[2];
    ಪೂರ್ಣಾಂಕ rm;
    uint32_t enc = 0;

    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[0]);
    skip(',');
    parse_ಕಾರ್ಯಾಂಶ(s1, &ops[1]);

    ಆಯ್ಕೆ (token) {
        ಸ್ಥಿತಿ TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ: expect("fcvt/fclass instruction"); ಹಿಂತಿರುಗಿ;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ token)
{
    ಆಯ್ಕೆ (token) {
    ಸ್ಥಿತಿ TOK_ASM_ebreak:
    ಸ್ಥಿತಿ TOK_ASM_ecall:
    ಸ್ಥಿತಿ TOK_ASM_fence_i:
    ಸ್ಥಿತಿ TOK_ASM_hrts:
    ಸ್ಥಿತಿ TOK_ASM_mrth:
    ಸ್ಥಿತಿ TOK_ASM_mrts:
    ಸ್ಥಿತಿ TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_rdcycle:
    ಸ್ಥಿತಿ TOK_ASM_rdcycleh:
    ಸ್ಥಿತಿ TOK_ASM_rdtime:
    ಸ್ಥಿತಿ TOK_ASM_rdtimeh:
    ಸ್ಥಿತಿ TOK_ASM_rdinstret:
    ಸ್ಥಿತಿ TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_lui:
    ಸ್ಥಿತಿ TOK_ASM_auipc:
    ಸ್ಥಿತಿ TOK_ASM_fsqrt_s:
    ಸ್ಥಿತಿ TOK_ASM_fsqrt_d:
        asm_ದ್ವಿಮಾನ_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    /* fcvt/fclass — separate handler for optional rounding operand */
    ಸ್ಥಿತಿ TOK_ASM_fcvt_w_s:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_wu_s:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_l_s:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_lu_s:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_s_w:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_s_wu:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_s_l:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_s_lu:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_w_d:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_wu_d:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_l_d:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_lu_d:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_d_w:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_d_wu:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_d_l:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_d_lu:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_s_d:
    ಸ್ಥಿತಿ TOK_ASM_fcvt_d_s:
    ಸ್ಥಿತಿ TOK_ASM_fclass_s:
    ಸ್ಥಿತಿ TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_lb:
    ಸ್ಥಿತಿ TOK_ASM_lh:
    ಸ್ಥಿತಿ TOK_ASM_lw:
    ಸ್ಥಿತಿ TOK_ASM_ld:
    ಸ್ಥಿತಿ TOK_ASM_fld:
    ಸ್ಥಿತಿ TOK_ASM_lbu:
    ಸ್ಥಿತಿ TOK_ASM_lhu:
    ಸ್ಥಿತಿ TOK_ASM_lwu:
    ಸ್ಥಿತಿ TOK_ASM_sb:
    ಸ್ಥಿತಿ TOK_ASM_sh:
    ಸ್ಥಿತಿ TOK_ASM_sw:
    ಸ್ಥಿತಿ TOK_ASM_sd:
    ಸ್ಥಿತಿ TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ TOK_ASM_ಕೂಡಿಸು:
    ಸ್ಥಿತಿ TOK_ASM_addi:
    ಸ್ಥಿತಿ TOK_ASM_addiw:
    ಸ್ಥಿತಿ TOK_ASM_addw:
    ಸ್ಥಿತಿ TOK_ASM_and:
    ಸ್ಥಿತಿ TOK_ASM_andi:
    ಸ್ಥಿತಿ TOK_ASM_or:
    ಸ್ಥಿತಿ TOK_ASM_ori:
    ಸ್ಥಿತಿ TOK_ASM_sll:
    ಸ್ಥಿತಿ TOK_ASM_slli:
    ಸ್ಥಿತಿ TOK_ASM_slliw:
    ಸ್ಥಿತಿ TOK_ASM_sllw:
    ಸ್ಥಿತಿ TOK_ASM_slt:
    ಸ್ಥಿತಿ TOK_ASM_slti:
    ಸ್ಥಿತಿ TOK_ASM_sltiu:
    ಸ್ಥಿತಿ TOK_ASM_sltu:
    ಸ್ಥಿತಿ TOK_ASM_sra:
    ಸ್ಥಿತಿ TOK_ASM_srai:
    ಸ್ಥಿತಿ TOK_ASM_sraiw:
    ಸ್ಥಿತಿ TOK_ASM_sraw:
    ಸ್ಥಿತಿ TOK_ASM_srl:
    ಸ್ಥಿತಿ TOK_ASM_srli:
    ಸ್ಥಿತಿ TOK_ASM_srliw:
    ಸ್ಥಿತಿ TOK_ASM_srlw:
    ಸ್ಥಿತಿ TOK_ASM_sub:
    ಸ್ಥಿತಿ TOK_ASM_subw:
    ಸ್ಥಿತಿ TOK_ASM_xor:
    ಸ್ಥಿತಿ TOK_ASM_xori:
    /* M extension */
    ಸ್ಥಿತಿ TOK_ASM_div:
    ಸ್ಥಿತಿ TOK_ASM_divu:
    ಸ್ಥಿತಿ TOK_ASM_divuw:
    ಸ್ಥಿತಿ TOK_ASM_divw:
    ಸ್ಥಿತಿ TOK_ASM_mul:
    ಸ್ಥಿತಿ TOK_ASM_mulh:
    ಸ್ಥಿತಿ TOK_ASM_mulhsu:
    ಸ್ಥಿತಿ TOK_ASM_mulhu:
    ಸ್ಥಿತಿ TOK_ASM_mulw:
    ಸ್ಥಿತಿ TOK_ASM_rem:
    ಸ್ಥಿತಿ TOK_ASM_remu:
    ಸ್ಥಿತಿ TOK_ASM_remuw:
    ಸ್ಥಿತಿ TOK_ASM_remw:
    /* Zicsr extension */
    ಸ್ಥಿತಿ TOK_ASM_csrrc:
    ಸ್ಥಿತಿ TOK_ASM_csrrci:
    ಸ್ಥಿತಿ TOK_ASM_csrrs:
    ಸ್ಥಿತಿ TOK_ASM_csrrsi:
    ಸ್ಥಿತಿ TOK_ASM_csrrw:
    ಸ್ಥಿತಿ TOK_ASM_csrrwi:
    /* F/D extension */
    ಸ್ಥಿತಿ TOK_ASM_fadd_s:
    ಸ್ಥಿತಿ TOK_ASM_fadd_d:
    ಸ್ಥಿತಿ TOK_ASM_fsub_s:
    ಸ್ಥಿತಿ TOK_ASM_fsub_d:
    ಸ್ಥಿತಿ TOK_ASM_fmul_s:
    ಸ್ಥಿತಿ TOK_ASM_fmul_d:
    ಸ್ಥಿತಿ TOK_ASM_fdiv_s:
    ಸ್ಥಿತಿ TOK_ASM_fdiv_d:
    ಸ್ಥಿತಿ TOK_ASM_fsgnj_d:
    ಸ್ಥಿತಿ TOK_ASM_fsgnj_s:
    ಸ್ಥಿತಿ TOK_ASM_fmax_s:
    ಸ್ಥಿತಿ TOK_ASM_fmax_d:
    ಸ್ಥಿತಿ TOK_ASM_fmin_s:
    ಸ್ಥಿತಿ TOK_ASM_fmin_d:
    ಸ್ಥಿತಿ TOK_ASM_feq_s:
    ಸ್ಥಿತಿ TOK_ASM_feq_d:
    ಸ್ಥಿತಿ TOK_ASM_flt_s:
    ಸ್ಥಿತಿ TOK_ASM_flt_d:
    ಸ್ಥಿತಿ TOK_ASM_fle_s:
    ಸ್ಥಿತಿ TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_fmadd_d:
    ಸ್ಥಿತಿ TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    /* Branches */
    ಸ್ಥಿತಿ TOK_ASM_beq:
    ಸ್ಥಿತಿ TOK_ASM_bge:
    ಸ್ಥಿತಿ TOK_ASM_bgeu:
    ಸ್ಥಿತಿ TOK_ASM_blt:
    ಸ್ಥಿತಿ TOK_ASM_bltu:
    ಸ್ಥಿತಿ TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        ನಿಲ್ಲಿಸು;

    /* C extension */
    ಸ್ಥಿತಿ TOK_ASM_c_ebreak:
    ಸ್ಥಿತಿ TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_c_j:
    ಸ್ಥಿತಿ TOK_ASM_c_jal:
    ಸ್ಥಿತಿ TOK_ASM_c_jalr:
    ಸ್ಥಿತಿ TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_c_ಕೂಡಿಸು:
    ಸ್ಥಿತಿ TOK_ASM_c_addi16sp:
    ಸ್ಥಿತಿ TOK_ASM_c_addi4spn:
    ಸ್ಥಿತಿ TOK_ASM_c_addi:
    ಸ್ಥಿತಿ TOK_ASM_c_addiw:
    ಸ್ಥಿತಿ TOK_ASM_c_addw:
    ಸ್ಥಿತಿ TOK_ASM_c_and:
    ಸ್ಥಿತಿ TOK_ASM_c_andi:
    ಸ್ಥಿತಿ TOK_ASM_c_beqz:
    ಸ್ಥಿತಿ TOK_ASM_c_bnez:
    ಸ್ಥಿತಿ TOK_ASM_c_fldsp:
    ಸ್ಥಿತಿ TOK_ASM_c_flwsp:
    ಸ್ಥಿತಿ TOK_ASM_c_fsdsp:
    ಸ್ಥಿತಿ TOK_ASM_c_fswsp:
    ಸ್ಥಿತಿ TOK_ASM_c_ldsp:
    ಸ್ಥಿತಿ TOK_ASM_c_li:
    ಸ್ಥಿತಿ TOK_ASM_c_lui:
    ಸ್ಥಿತಿ TOK_ASM_c_lwsp:
    ಸ್ಥಿತಿ TOK_ASM_c_mv:
    ಸ್ಥಿತಿ TOK_ASM_c_or:
    ಸ್ಥಿತಿ TOK_ASM_c_sdsp:
    ಸ್ಥಿತಿ TOK_ASM_c_slli:
    ಸ್ಥಿತಿ TOK_ASM_c_srai:
    ಸ್ಥಿತಿ TOK_ASM_c_srli:
    ಸ್ಥಿತಿ TOK_ASM_c_sub:
    ಸ್ಥಿತಿ TOK_ASM_c_subw:
    ಸ್ಥಿತಿ TOK_ASM_c_swsp:
    ಸ್ಥಿತಿ TOK_ASM_c_xor:
        asm_ದ್ವಿಮಾನ_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_c_fld:
    ಸ್ಥಿತಿ TOK_ASM_c_flw:
    ಸ್ಥಿತಿ TOK_ASM_c_fsd:
    ಸ್ಥಿತಿ TOK_ASM_c_fsw:
    ಸ್ಥಿತಿ TOK_ASM_c_ld:
    ಸ್ಥಿತಿ TOK_ASM_c_lw:
    ಸ್ಥಿತಿ TOK_ASM_c_sd:
    ಸ್ಥಿತಿ TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    /* pseudoinstructions */
    ಸ್ಥಿತಿ TOK_ASM_nop:
    ಸ್ಥಿತಿ TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_jr:
    ಸ್ಥಿತಿ TOK_ASM_call:
    ಸ್ಥಿತಿ TOK_ASM_ಬಾಲ:
    ಸ್ಥಿತಿ TOK_ASM_frflags:
    ಸ್ಥಿತಿ TOK_ASM_frrm:
    ಸ್ಥಿತಿ TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_la:
    ಸ್ಥಿತಿ TOK_ASM_lla:
    ಸ್ಥಿತಿ TOK_ASM_li:
    ಸ್ಥಿತಿ TOK_ASM_jump:
    ಸ್ಥಿತಿ TOK_ASM_seqz:
    ಸ್ಥಿತಿ TOK_ASM_snez:
    ಸ್ಥಿತಿ TOK_ASM_sltz:
    ಸ್ಥಿತಿ TOK_ASM_sgtz:
    ಸ್ಥಿತಿ TOK_ASM_mv:
    ಸ್ಥಿತಿ TOK_ASM_not:
    ಸ್ಥಿತಿ TOK_ASM_neg:
    ಸ್ಥಿತಿ TOK_ASM_negw:
    ಸ್ಥಿತಿ TOK_ASM_sext_w:
    ಸ್ಥಿತಿ TOK_ASM_fabs_s:
    ಸ್ಥಿತಿ TOK_ASM_fabs_d:
    ಸ್ಥಿತಿ TOK_ASM_fmv_s:
    ಸ್ಥಿತಿ TOK_ASM_fmv_d:
    ಸ್ಥಿತಿ TOK_ASM_fneg_s:
    ಸ್ಥಿತಿ TOK_ASM_fneg_d:
    ಸ್ಥಿತಿ TOK_ASM_csrc:
    ಸ್ಥಿತಿ TOK_ASM_csrs:
    ಸ್ಥಿತಿ TOK_ASM_csrr:
    ಸ್ಥಿತಿ TOK_ASM_csrw:
    ಸ್ಥಿತಿ TOK_ASM_csrwi:
    ಸ್ಥಿತಿ TOK_ASM_csrsi:
    ಸ್ಥಿತಿ TOK_ASM_csrci:
    ಸ್ಥಿತಿ TOK_ASM_fsrm:
    ಸ್ಥಿತಿ TOK_ASM_fscsr:
        asm_ದ್ವಿಮಾನ_opcode(s1, token);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_bnez:
    ಸ್ಥಿತಿ TOK_ASM_beqz:
    ಸ್ಥಿತಿ TOK_ASM_blez:
    ಸ್ಥಿತಿ TOK_ASM_bgez:
    ಸ್ಥಿತಿ TOK_ASM_bltz:
    ಸ್ಥಿತಿ TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        ಹಿಂತಿರುಗಿ;

    ಸ್ಥಿತಿ TOK_ASM_bgt:
    ಸ್ಥಿತಿ TOK_ASM_bgtu:
    ಸ್ಥಿತಿ TOK_ASM_ble:
    ಸ್ಥಿತಿ TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        ಹಿಂತಿರುಗಿ;

    /* Atomic operations */
    ಸ್ಥಿತಿ TOK_ASM_lr_w:
    ಸ್ಥಿತಿ TOK_ASM_lr_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_lr_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_lr_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_lr_d:
    ಸ್ಥಿತಿ TOK_ASM_lr_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_lr_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_lr_d_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_sc_w:
    ಸ್ಥಿತಿ TOK_ASM_sc_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_sc_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_sc_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_sc_d:
    ಸ್ಥಿತಿ TOK_ASM_sc_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_sc_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    ಸ್ಥಿತಿ TOK_ASM_amoadd_w:
    ಸ್ಥಿತಿ TOK_ASM_amoadd_d:
    ಸ್ಥಿತಿ TOK_ASM_amoswap_w:
    ಸ್ಥಿತಿ TOK_ASM_amoswap_d:
    ಸ್ಥಿತಿ TOK_ASM_amoand_w:
    ಸ್ಥಿತಿ TOK_ASM_amoand_d:
    ಸ್ಥಿತಿ TOK_ASM_amoor_w:
    ಸ್ಥಿತಿ TOK_ASM_amoor_d:
    ಸ್ಥಿತಿ TOK_ASM_amoxor_w:
    ಸ್ಥಿತಿ TOK_ASM_amoxor_d:
    ಸ್ಥಿತಿ TOK_ASM_amomax_w:
    ಸ್ಥಿತಿ TOK_ASM_amomax_d:
    ಸ್ಥಿತಿ TOK_ASM_amomaxu_w:
    ಸ್ಥಿತಿ TOK_ASM_amomaxu_d:
    ಸ್ಥಿತಿ TOK_ASM_amomin_w:
    ಸ್ಥಿತಿ TOK_ASM_amomin_d:
    ಸ್ಥಿತಿ TOK_ASM_amominu_w:
    ಸ್ಥಿತಿ TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    ಸ್ಥಿತಿ TOK_ASM_amoadd_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_amoadd_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_amoadd_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amoadd_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_amoadd_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    ಸ್ಥಿತಿ TOK_ASM_amoswap_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_amoswap_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_amoswap_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amoswap_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_amoswap_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_amoswap_d_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amoand_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_amoand_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_amoand_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amoand_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_amoand_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_amoand_d_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amoor_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_amoor_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_amoor_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amoor_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_amoor_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_amoor_d_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amoxor_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_amoxor_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_amoxor_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amoxor_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_amoxor_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_amoxor_d_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amomax_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_amomax_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_amomax_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amomax_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_amomax_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_amomax_d_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amomaxu_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_amomaxu_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_amomaxu_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amomaxu_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_amomaxu_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_amomaxu_d_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amomin_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_amomin_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_amomin_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amomin_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_amomin_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_amomin_d_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amominu_w_aq:
    ಸ್ಥಿತಿ TOK_ASM_amominu_w_rl:
    ಸ್ಥಿತಿ TOK_ASM_amominu_w_aqrl:
    ಸ್ಥಿತಿ TOK_ASM_amominu_d_aq:
    ಸ್ಥಿತಿ TOK_ASM_amominu_d_rl:
    ಸ್ಥಿತಿ TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        ನಿಲ್ಲಿಸು;

    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known instruction");
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asm_parse_csrvar(ಪೂರ್ಣಾಂಕ t)
{
    ಆಯ್ಕೆ (t) {
    ಸ್ಥಿತಿ TOK_ASM_ಚಕ್ರ:
        ಹಿಂತಿರುಗಿ 0xc00;
    ಸ್ಥಿತಿ TOK_ASM_fcsr:
        ಹಿಂತಿರುಗಿ 3;
    ಸ್ಥಿತಿ TOK_ASM_fflags:
        ಹಿಂತಿರುಗಿ 1;
    ಸ್ಥಿತಿ TOK_ASM_frm:
        ಹಿಂತಿರುಗಿ 2;
    ಸ್ಥಿತಿ TOK_ASM_instret:
        ಹಿಂತಿರುಗಿ 0xc02;
    ಸ್ಥಿತಿ TOK_ASM_ಸಮಯ:
        ಹಿಂತಿರುಗಿ 0xc01;
    ಸ್ಥಿತಿ TOK_ASM_cycleh:
        ಹಿಂತಿರುಗಿ 0xc80;
    ಸ್ಥಿತಿ TOK_ASM_instreth:
        ಹಿಂತಿರುಗಿ 0xc82;
    ಸ್ಥಿತಿ TOK_ASM_timeh:
        ಹಿಂತಿರುಗಿ 0xc81;
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಹಿಂತಿರುಗಿ -1;
    }
}

ST_FUNC ಶೂನ್ಯ subst_asm_ಕಾರ್ಯಾಂಶ(CString *ಕೂಡಿಸು_str, SValue *sv, ಪೂರ್ಣಾಂಕ modifier)
{
    ಪೂರ್ಣಾಂಕ r, reg, val;

    r = sv->r;
    ಆದರೆ ((r & VT_VALMASK) == VT_CONST) {
        ಆದರೆ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        ಆದರೆ (r & VT_SYM) {
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = get_tok_str(sv->sym->v, ಖಾಲಿ);
            ಆದರೆ (sv->sym->v >= SYM_ಮೊದಲ_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name))->tok, sv->sym);
            }
            ಆದರೆ (tcc_state->leading_underscore)
                cstr_ccat(ಕೂಡಿಸು_str, '_');
            cstr_cat(ಕೂಡಿಸು_str, name, -1);
            ಆದರೆ ((uint32_t) sv->c.i == 0)
                ಹೋಗು no_ಸ್ಥಾನಾಂತರ;
            cstr_ccat(ಕೂಡಿಸು_str, '+');
        }
        val = sv->c.i;
        ಆದರೆ (modifier == 'n')
            val = -val;
        ಆದರೆ (modifier == 'z' && val == 0) {
            cstr_cat(ಕೂಡಿಸು_str, "zero", -1);
        } ಇಲ್ಲದಿದ್ದರೆ {
            cstr_printf(ಕೂಡಿಸು_str, "%d", val);
        }
      no_ಸ್ಥಾನಾಂತರ:;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(ಕೂಡಿಸು_str, "%d", (ಪೂರ್ಣಾಂಕ) sv->c.i);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ಆದರೆ (reg >= VT_CONST)
            tcc_ಆಂತರಿಕ_error("");
        ಆದರೆ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_ಮೌಲ್ಯ(reg);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(ಕೂಡಿಸು_str, get_tok_str(reg, ಖಾಲಿ), -1);
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* register case */
        reg = r & VT_VALMASK;
        ಆದರೆ (reg >= VT_CONST)
            tcc_ಆಂತರಿಕ_error("");
        ಆದರೆ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_ಮೌಲ್ಯ(reg);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(ಕೂಡಿಸು_str, get_tok_str(reg, ಖಾಲಿ), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_ireg(ಪೂರ್ಣಾಂಕ r){
    ಹಿಂತಿರುಗಿ REG_ಮೌಲ್ಯ(r) - 10;
}
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_freg(ಪೂರ್ಣಾಂಕ r){
    ಹಿಂತಿರುಗಿ REG_ಮೌಲ್ಯ(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ಶೂನ್ಯ asm_gen_ಸಂಕೇತ(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands,
                         ಪೂರ್ಣಾಂಕ nb_outputs, ಪೂರ್ಣಾಂಕ is_output,
                         uint8_t *clobber_regs,
                         ಪೂರ್ಣಾಂಕ ಹೊರಹೋಗು_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ಪೂರ್ಣಾಂಕ i, reg;

    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    ಸ್ಮರಣೆ_ನಕಲು(regs_allocated, clobber_regs, ಗಾತ್ರ(regs_allocated));
    ಗಾಗಿ(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ಆದರೆ (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    ಆದರೆ(!is_output) {
        /* generate reg save code */
        ಗಾಗಿ(i = 0; i < ಗಾತ್ರ(reg_saved)/ಗಾತ್ರ(reg_saved[0]); i++) {
            reg = reg_saved[i];
            ಆದರೆ (regs_allocated[reg]) {
                /*ತಳ್ಳು*/
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (ಚಿಹ್ನೆರಹಿತ)-8 << 20);
                ಆದರೆ (REG_IS_FLOAT(reg)){
                    /* fsd reg, offset(sp) */
                    gen_le32( 0x27 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                } ಇಲ್ಲದಿದ್ದರೆ {
                    /* sd reg, offset(sp) */
                    gen_le32((0x8 << 2) | 3 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                }
            }
        }

        /* generate load code */
        ಗಾಗಿ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ಆದರೆ (op->reg >= 0) {
                ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_ಸ್ಮರಣೆ) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    ತುಂಬು(tcc_ireg(op->reg), &sv);
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    ಆದರೆ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        ತುಂಬು(tcc_freg(op->reg), op->vt);
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        ತುಂಬು(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register;
                       the load/store above already handles it correctly */
                }
            }
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* generate save code */
        ಗಾಗಿ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ಆದರೆ (op->reg >= 0) {
                ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ಆದರೆ (!op->is_ಸ್ಮರಣೆ) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        ತುಂಬು(tcc_ireg(ಹೊರಹೋಗು_reg), &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | ಹೊರಹೋಗು_reg;
                        store(tcc_ireg(op->reg), &sv);
                    }
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ಆದರೆ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        store(tcc_freg(op->reg), op->vt);
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        store(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register */
                }
            }
        }
        /* generate reg restore code for floating point registers */
        ಗಾಗಿ(i = ಗಾತ್ರ(reg_saved)/ಗಾತ್ರ(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            ಆದರೆ (regs_allocated[reg]) {
                /*ತೆಗೆ*/
                ಆದರೆ (REG_IS_FLOAT(reg)){
                    /* fld reg, offset(sp) */
                    gen_le32(7 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    /* ld reg, offset(sp) */
                    gen_le32(3 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                }
                /* addi sp, sp, offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | 8 << 20);
            }
        }
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ constraint_ಆದ್ಯತೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    // TODO: How is this chosen??
    ಪೂರ್ಣಾಂಕ ಆದ್ಯತೆ, c, pr;

    /* we take the lowest priority */
    ಆದ್ಯತೆ = 0;
    ಗಾಗಿ(;;) {
        c = *str;
        ಆದರೆ (c == '\0')
            ನಿಲ್ಲಿಸು;
        str++;
        ಆಯ್ಕೆ(c) {
        ಸ್ಥಿತಿ 'A': // address that is held in a general-purpose register.
        ಸ್ಥಿತಿ 'S': // constraint that matches an absolute symbolic address.
        ಸ್ಥಿತಿ 'f': // register [float]
        ಸ್ಥಿತಿ 'r': // register [general]
        ಸ್ಥಿತಿ 'p': // valid memory address for load,store [general]
            pr = 3;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'I': // 12 bit signed immedate
        ಸ್ಥಿತಿ 'i': // immediate integer operand, including symbolic constants [general]
        ಸ್ಥಿತಿ 'm': // memory operand [general]
        ಸ್ಥಿತಿ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'v':
            tcc_error("unimp: constraint '%c'", c);
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("unknown constraint '%d'", c);
        }
        ಆದರೆ (pr > ಆದ್ಯತೆ)
            ಆದ್ಯತೆ = pr;
    }
    ಹಿಂತಿರುಗಿ ಆದ್ಯತೆ;
}

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *skip_constraint_modifiers(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ಆಗ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ಹಿಂತಿರುಗಿ p;
}

#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಹೊರಹೋಗು_ಮುಖವಾಡ 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಒಳ_ಮುಖವಾಡ  0x02

#ವ್ಯಾಖ್ಯಾನಿಸು is_reg_allocated(reg) (regs_allocated[reg] & reg_ಮುಖವಾಡ)

ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands,
                                    ಪೂರ್ಣಾಂಕ nb_operands, ಪೂರ್ಣಾಂಕ nb_outputs,
                                    ಸ್ಥಿರಾಂಕ uint8_t *clobber_regs,
                                    ಪೂರ್ಣಾಂಕ *pout_reg)
{
    /* TODO: Simple constraints
        whitespace  ignored
        o  memory operand that is offsetable
        V  memory but not offsetable
        <  memory operand with autodecrement addressing is allowed.  Restrictions apply.
        >  memory operand with autoincrement addressing is allowed.  Restrictions apply.
        n  immediate integer operand with a known numeric value
        E  immediate floating operand (const_double) is allowed, but only if target=host
        F  immediate floating operand (const_double or const_vector) is allowed
        s  immediate integer operand whose value is not an explicit integer
        X  any operand whatsoever
        0...9 (postfix); (can also be more than 1 digit number);  an operand that matches the specified operand number is allowed
    */

    /* TODO: RISCV constraints
        J   The integer 0.
        K   A 5-bit unsigned immediate for CSR access instructions.
        A   An address that is held in a general-purpose register.
        S   A constraint that matches an absolute symbolic address.
        vr  A vector register (if available)..
        vd  A vector register, excluding v0 (if available).
        vm  A vector register, only v0 (if available).
    */
    ASMOperand *op;
    ಪೂರ್ಣಾಂಕ sorted_op[MAX_ASM_OPERANDS];
    ಪೂರ್ಣಾಂಕ i, j, k, p1, p2, tmp, reg, c, reg_ಮುಖವಾಡ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ = -1;
        op->ref_ಸೂಚ್ಯಂಕ = -1;
        op->reg = -1;
        op->is_ಸ್ಮರಣೆ = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ಆದರೆ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = ಕಂಡುಹಿಡಿ_constraint(operands, nb_operands, str, ಖಾಲಿ);
            ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
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

    /* sort operands according to their priority */
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

    /* allocate registers and generate corresponding asm moves */
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ಆದರೆ (op->ref_ಸೂಚ್ಯಂಕ >= 0)
            ಮುಂದುವರಿ;
        /* select if register is used for output, input or both */
        ಆದರೆ (op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ >= 0) {
            reg_ಮುಖವಾಡ = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (j < nb_outputs) {
            reg_ಮುಖವಾಡ = REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            reg_ಮುಖವಾಡ = REG_ಒಳ_ಮುಖವಾಡ;
        }
        ಆದರೆ (op->reg >= 0) {
            ಆದರೆ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_ಮುಂದಿನ:
        c = *str++;
        ಆಯ್ಕೆ (c) {
        ಸ್ಥಿತಿ '=': // Operand is written-to
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        ಸ್ಥಿತಿ '&': // Operand is clobbered before the instruction is done using the input operands
            ಆದರೆ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_ಮುಖವಾಡ = REG_ಒಳ_ಮುಖವಾಡ | REG_ಹೊರಹೋಗು_ಮುಖವಾಡ;
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ 'r': // general-purpose register
        ಸ್ಥಿತಿ 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            ಆದರೆ ((reg = op->reg) >= 0)
                ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            ಇಲ್ಲದಿದ್ದರೆ ಗಾಗಿ (reg = 10; reg <= 18; reg++) {
                ಆದರೆ (!is_reg_allocated(reg))
                    ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            }
            ಹೋಗು try_ಮುಂದಿನ;
          reg_ಸಿಕ್ಕಿತು:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_ಮುಖವಾಡ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            ಆದರೆ ((reg = op->reg) >= 0)
                ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            ಇಲ್ಲದಿದ್ದರೆ ಗಾಗಿ (reg = 42; reg <= 50; reg++) {
                ಆದರೆ (!is_reg_allocated(reg))
                    ಹೋಗು reg_ಸಿಕ್ಕಿತು;
            }
            ಹೋಗು try_ಮುಂದಿನ;
        ಸ್ಥಿತಿ 'I': // I-Type 12 bit signed immediate
        ಸ್ಥಿತಿ 'i': // immediate integer operand, including symbolic constants
            ಆದರೆ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ಹೋಗು try_ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'm': // memory operand
        ಸ್ಥಿತಿ 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ಆದರೆ (j < nb_outputs || c == 'm') {
                ಆದರೆ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    ಗಾಗಿ (reg = 10; reg <= 18; reg++) {
                        ಆದರೆ (!(regs_allocated[reg] & REG_ಒಳ_ಮುಖವಾಡ))
                            ಹೋಗು reg_found1;
                    }
                    ಹೋಗು try_ಮುಂದಿನ;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_ಒಳ_ಮುಖವಾಡ;
                    op->reg = reg;
                    op->is_ಸ್ಮರಣೆ = 1;
                }
            }
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ನಿಲ್ಲಿಸು;
        }
        /* if a reference is present for that operand, we assign it too */
        ಆದರೆ (op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ >= 0) {
            operands[op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ].reg = op->reg;
            operands[op->ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ಆದರೆ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_ಸ್ಮರಣೆ) {
            ಆದರೆ (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                ಗಾಗಿ (reg = 42; reg <= 50; reg++) {
                    ಆದರೆ (!(regs_allocated[reg] & REG_ಹೊರಹೋಗು_ಮುಖವಾಡ))
                        ಹೋಗು reg_found2;
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* From a0 to a7 */
                ಗಾಗಿ (reg = 10; reg <= 18; reg++) {
                    ಆದರೆ (!(regs_allocated[reg] & REG_ಹೊರಹೋಗು_ಮುಖವಾಡ))
                        ಹೋಗು reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ನಿಲ್ಲಿಸು;
        }
    }

    /* print sorted constraints */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ASM_DEBUG
    ಗಾಗಿ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        ಬರೆ("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ಖಾಲಿ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ಆದರೆ (*pout_reg >= 0)
        ಬರೆ("out_reg=%d\n", *pout_reg);
#ಆದರೆ_ಅಂತ್ಯ
}

ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಪೂರ್ಣಾಂಕ reg;
    TokenSym *ts;

    ಆದರೆ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ಹಿಂತಿರುಗಿ;
    ts = tok_alloc(str, ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str));
    reg = asm_parse_regvar(ts->tok);
    ಆದರೆ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC ಪೂರ್ಣಾಂಕ asm_parse_regvar (ಪೂರ್ಣಾಂಕ t)
{
    /* PC register not implemented */
    ಆದರೆ (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        ಹಿಂತಿರುಗಿ -1;

    ಆದರೆ (t < TOK_ASM_f0)
        ಹಿಂತಿರುಗಿ t - TOK_ASM_x0;

    ಆದರೆ (t < TOK_ASM_zero)
        ಹಿಂತಿರುಗಿ t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    ಆದರೆ (t < TOK_ASM_ft0)
        ಹಿಂತಿರುಗಿ t - TOK_ASM_zero;

    ಹಿಂತಿರುಗಿ t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ca(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2)
{
    uint8_t dst, src;

    ಆದರೆ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    ಆದರೆ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ಖಾಲಿ));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cb(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm)
{
    uint32_t ಸ್ಥಾನಾಂತರ;
    uint8_t src;

    ಆದರೆ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ಖಾಲಿ));
    }

    ಸ್ಥಾನಾಂತರ = imm->e.v;

    ಆದರೆ (ಸ್ಥಾನಾಂತರ & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ಖಾಲಿ));
    }

    src = rs1->reg - 8;

    ಆದರೆ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ಖಾಲಿ));
    }

    /* CB-type instruction:
    15...13 funct3
    12...10 offset
    9..7    rs1'
    6...2   offset
    1...0   opcode */

    /* non-branch also using CB:
    15...13 funct3
    12      imm
    11..10  funct2
    9...7   rd'/rs1'
    6..2    imm
    1...0   opcode */

    ಆಯ್ಕೆ (token) {
    ಸ್ಥಿತಿ TOK_ASM_c_beqz:
    ಸ್ಥಿತಿ TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 5) | (((ಸ್ಥಾನಾಂತರ >> 1) & 3) << 1) | (((ಸ್ಥಾನಾಂತರ >> 6) & 3) << 3)) << 2) | ((((ಸ್ಥಾನಾಂತರ >> 3) & 3) | NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 8)) << 10));
        ಹಿಂತಿರುಗಿ;
    ಪೂರ್ವನಿಯೋಜಿತ:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((ಸ್ಥಾನಾಂತರ & 0x1f) << 2) | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 5) << 12));
        ಹಿಂತಿರುಗಿ;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ci(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm)
{
    uint32_t ತಕ್ಷಣ;

    ಆದರೆ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ಖಾಲಿ));
    }

    ತಕ್ಷಣ = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    ಆಯ್ಕೆ (token) {
    ಸ್ಥಿತಿ TOK_ASM_c_addi:
    ಸ್ಥಿತಿ TOK_ASM_c_addiw:
    ಸ್ಥಿತಿ TOK_ASM_c_li:
    ಸ್ಥಿತಿ TOK_ASM_c_slli:
        gen_le16(opcode | ((ತಕ್ಷಣ & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_ಬಿಟ್(ತಕ್ಷಣ, 5) << 12));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_ಬಿಟ್(ತಕ್ಷಣ, 5) << 2 | (((ತಕ್ಷಣ >> 7) & 3) << 3) | NTH_ಬಿಟ್(ತಕ್ಷಣ, 6) << 5 | NTH_ಬಿಟ್(ತಕ್ಷಣ, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_ಬಿಟ್(ತಕ್ಷಣ, 9) << 12));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_lui:
        gen_le16(opcode | (((ತಕ್ಷಣ >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_ಬಿಟ್(ತಕ್ಷಣ, 17) << 12));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_fldsp:
    ಸ್ಥಿತಿ TOK_ASM_c_ldsp:
        gen_le16(opcode | (((ತಕ್ಷಣ >> 6) & 7) << 2) | (((ತಕ್ಷಣ >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_ಬಿಟ್(ತಕ್ಷಣ, 5) << 12));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_flwsp:
    ಸ್ಥಿತಿ TOK_ASM_c_lwsp:
        gen_le16(opcode | (((ತಕ್ಷಣ >> 6) & 3) << 2) | (((ತಕ್ಷಣ >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_ಬಿಟ್(ತಕ್ಷಣ, 5) << 12));
        ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_ASM_c_nop:
        gen_le16(opcode);
        ಹಿಂತಿರುಗಿ;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ciw(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    ಆದರೆ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ಖಾಲಿ));
    }

    dst = rd->reg - 8;

    ಆದರೆ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ಖಾಲಿ));
    }

    nzuimm = imm->e.v;

    ಆದರೆ (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, ಖಾಲಿ));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_ಬಿಟ್(nzuimm, 3) | (NTH_ಬಿಟ್(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cj(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm)
{
    uint32_t ಸ್ಥಾನಾಂತರ;

    /* +-2 KiB range */
    ಆದರೆ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, ಖಾಲಿ));
    }

    ಸ್ಥಾನಾಂತರ = imm->e.v;

    ಆದರೆ (ಸ್ಥಾನಾಂತರ & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ಖಾಲಿ));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 5) << 2) | (((ಸ್ಥಾನಾಂತರ >> 1) & 7) << 3) | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 7) << 6) | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 6) << 7) | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 10) << 8) | (((ಸ್ಥಾನಾಂತರ >> 8) & 3) << 9) | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 4) << 11) | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 11) << 12));
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cl(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm)
{
    uint32_t ಸ್ಥಾನಾಂತರ;
    uint8_t dst, src;

    ಆದರೆ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ಖಾಲಿ));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    ಆದರೆ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ಖಾಲಿ));
    }

    ಸ್ಥಾನಾಂತರ = imm->e.v;

    ಆದರೆ (ಸ್ಥಾನಾಂತರ > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (ಸ್ಥಾನಾಂತರ & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ಖಾಲಿ));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    ಆಯ್ಕೆ (token) {
    /* imm variant 1 */
    ಸ್ಥಿತಿ TOK_ASM_c_flw:
    ಸ್ಥಿತಿ TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 6) << 5) | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 2) << 6) | (((ಸ್ಥಾನಾಂತರ >> 3) & 7) << 10));
        ಹಿಂತಿರುಗಿ;
    /* imm variant 2 */
    ಸ್ಥಿತಿ TOK_ASM_c_fld:
    ಸ್ಥಿತಿ TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((ಸ್ಥಾನಾಂತರ >> 6) & 3) << 5) | (((ಸ್ಥಾನಾಂತರ >> 3) & 7) << 10));
        ಹಿಂತಿರುಗಿ;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cr(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rd, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2)
{
    ಆದರೆ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cs(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs1, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm)
{
    uint32_t ಸ್ಥಾನಾಂತರ;
    uint8_t ತಳ, src;

    ಆದರೆ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ಖಾಲಿ));
    }

    ತಳ = rs1->reg - 8;
    src = rs2->reg - 8;

    ಆದರೆ (ತಳ > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ಖಾಲಿ));
    }

    ಸ್ಥಾನಾಂತರ = imm->e.v;

    ಆದರೆ (ಸ್ಥಾನಾಂತರ > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (ಸ್ಥಾನಾಂತರ & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ಖಾಲಿ));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    ಆಯ್ಕೆ (token) {
    /* imm variant 1 */
    ಸ್ಥಿತಿ TOK_ASM_c_fsw:
    ಸ್ಥಿತಿ TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(ತಳ) | C_ENCODE_RS1(src) | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 6) << 5) | (NTH_ಬಿಟ್(ಸ್ಥಾನಾಂತರ, 2) << 6) | (((ಸ್ಥಾನಾಂತರ >> 3) & 7) << 10));
        ಹಿಂತಿರುಗಿ;
    /* imm variant 2 */
    ಸ್ಥಿತಿ TOK_ASM_c_fsd:
    ಸ್ಥಿತಿ TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(ತಳ) | C_ENCODE_RS1(src) | (((ಸ್ಥಾನಾಂತರ >> 6) & 3) << 5) | (((ಸ್ಥಾನಾಂತರ >> 3) & 7) << 10));
        ಹಿಂತಿರುಗಿ;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_css(ಪೂರ್ಣಾಂಕ token, uint16_t opcode, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *rs2, ಸ್ಥಿರಾಂಕ ಕಾರ್ಯಾಂಶ *imm)
{
    uint32_t ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ಖಾಲಿ));
    }

    ಸ್ಥಾನಾಂತರ = imm->e.v;

    ಆದರೆ (ಸ್ಥಾನಾಂತರ > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ಖಾಲಿ));
    }

    ಆದರೆ (ಸ್ಥಾನಾಂತರ & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ಖಾಲಿ));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    ಆಯ್ಕೆ (token) {
    /* imm variant 1 */
    ಸ್ಥಿತಿ TOK_ASM_c_fswsp:
    ಸ್ಥಿತಿ TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((ಸ್ಥಾನಾಂತರ >> 6) & 3) << 7) | (((ಸ್ಥಾನಾಂತರ >> 2) & 0xf) << 9));
        ಹಿಂತಿರುಗಿ;
    /* imm variant 2 */
    ಸ್ಥಿತಿ TOK_ASM_c_fsdsp:
    ಸ್ಥಿತಿ TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((ಸ್ಥಾನಾಂತರ >> 6) & 7) << 7) | (((ಸ್ಥಾನಾಂತರ >> 3) & 7) << 10));
        ಹಿಂತಿರುಗಿ;
    ಪೂರ್ವನಿಯೋಜಿತ:
        expect("known instruction");
    }
}

/*************************************************************/
#ಆದರೆ_ಅಂತ್ಯ /* ndef TARGET_DEFS_ONLY */
