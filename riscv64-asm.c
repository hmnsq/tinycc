/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#ifdef TARGET_DEFS_ONLY

#define CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#define NB_ASM_REGS 64

ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಙ್ಕ c);

/*************************************************************/
#ಅನ್ಯಥಾ
/*************************************************************/
#define USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

ಗಣನಾ {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#define REG_FLOAT_MASK 0x20
#define REG_IS_FLOAT(register_index) ((register_index) & REG_FLOAT_MASK)
#define REG_ಮೌಲ್ಯ(register_index)    ((register_index) & (REG_FLOAT_MASK-1))
#define C_ENCODE_RS1(register_index) (REG_ಮೌಲ್ಯ(register_index) << 7)
#define C_ENCODE_RS2(register_index) (REG_ಮೌಲ್ಯ(register_index) << 2)
#define ENCODE_RD(register_index)  (REG_ಮೌಲ್ಯ(register_index) << 7)
#define ENCODE_RS1(register_index) (REG_ಮೌಲ್ಯ(register_index) << 15)
#define ENCODE_RS2(register_index) (REG_ಮೌಲ್ಯ(register_index) << 20)
#define NTH_BIT(b, n) ((b >> n) & 1)
#define OP_IM12S (1 << OPT_IM12S)
#define OP_IM32 (1 << OPT_IM32)
#define OP_REG (1 << OPT_REG)

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ Operand {
    uint32_t type;
    ಸಙ್ಘ {
        uint8_t reg;
        uint16_t regset;
        ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    };
} Operand;

ಸ್ಥಿರ ಧ್ರುವ Operand zero = { OP_REG, { 0 }};
ಸ್ಥಿರ ಧ್ರುವ Operand ra = { OP_REG, { 1 }};
ಸ್ಥಿರ ಧ್ರುವ Operand zimm = { OP_IM12S };

ಸ್ಥಿರ ಶೂನ್ಯ asm_ದ್ವಿಮಾನ_opcode(TCCState* s1, ಪೂರ್ಣಾಙ್ಕ token);
ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಧ್ರುವ ವರ್ಣ *str);
ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands, ಪೂರ್ಣಾಙ್ಕ nb_outputs, ಧ್ರುವ uint8_t *clobber_regs, ಪೂರ್ಣಾಙ್ಕ *pout_reg);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_a(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *rs2, ಧ್ರುವ Operand *rd1, ಪೂರ್ಣಾಙ್ಕ aq, ಪೂರ್ಣಾಙ್ಕ rl);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_b(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *rs2, ಧ್ರುವ Operand *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_i(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_j(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_opcode(uint32_t opcode);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_r(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_s(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *rs2, ಧ್ರುವ Operand *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_u(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_f(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_fb(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_fq(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *rs2, ಧ್ರುವ Operand *rs3);
ST_FUNC ಶೂನ್ಯ asm_gen_code(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands, ಪೂರ್ಣಾಙ್ಕ nb_outputs, ಪೂರ್ಣಾಙ್ಕ is_output, uint8_t *clobber_regs, ಪೂರ್ಣಾಙ್ಕ out_reg);
ಸ್ಥಿರ ಶೂನ್ಯ asm_nullary_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token);
ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asm_parse_csrvar(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ asm_parse_regvar(ಪೂರ್ಣಾಙ್ಕ t);
ಸ್ಥಿರ ಶೂನ್ಯ asm_ternary_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token);
ಸ್ಥಿರ ಶೂನ್ಯ asm_unary_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token);
ಸ್ಥಿರ ಶೂನ್ಯ asm_branch_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token, ಪೂರ್ಣಾಙ್ಕ argc);
ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe);
ಸ್ಥಿರ ಶೂನ್ಯ parse_operand(TCCState *s1, Operand *op);
ಸ್ಥಿರ ಶೂನ್ಯ parse_branch_offset_operand(TCCState *s1, Operand *op);
ಸ್ಥಿರ ಶೂನ್ಯ parse_operands(TCCState *s1, Operand *ops, ಪೂರ್ಣಾಙ್ಕ ಎಣಿಕೆ_2);
ಸ್ಥಿರ ಶೂನ್ಯ parse_mem_access_operands(TCCState *s1, Operand* ops);
ST_FUNC ಶೂನ್ಯ subst_asm_operand(CString *add_str, SValue *sv, ಪೂರ್ಣಾಙ್ಕ modifier);
/* C extension */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ca(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cb(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ci(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ciw(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cj(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cl(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cr(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs2);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cs(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rs2, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *imm);
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_css(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rs2, ಧ್ರುವ Operand *imm);

/* XXX: make it faster ? */
ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಙ್ಕ c)
{
    ಪೂರ್ಣಾಙ್ಕ ind1;
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    ind1 = ind + 1;
    ಯದಿ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC ಶೂನ್ಯ gen_le16 (ಪೂರ್ಣಾಙ್ಕ i)
{
    g(i);
    g(i>>8);
}

ST_FUNC ಶೂನ್ಯ gen_le32 (ಪೂರ್ಣಾಙ್ಕ i)
{
    ಪೂರ್ಣಾಙ್ಕ ind1;
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    ind1 = ind + 4;
    ಯದಿ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    gen_le32(pe->v);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_nullary_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    ವಿಕಲ್ಪ (token) {
    // Sync instructions

    ಪಕ್ಷ TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        ಪ್ರತ್ಯಾಗಮ;

    // System calls

    ಪಕ್ಷ TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        ಪ್ರತ್ಯಾಗಮ;

    // Other

    ಪಕ್ಷ TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        ಪ್ರತ್ಯಾಗಮ;

    /* Pseudoinstructions */
    ಪಕ್ಷ TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        ಪ್ರತ್ಯಾಗಮ;

    /* C extension */
    ಪಕ್ಷ TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        ಪ್ರತ್ಯಾಗಮ;

    ಸ್ವಭಾವ:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
ಸ್ಥಿರ ಶೂನ್ಯ parse_operand(TCCState *s1, Operand *op)
{
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    ಯದಿ ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        ಪ್ರತ್ಯಾಗಮ;
    } ಅನ್ಯಥಾ ಯದಿ (tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    } ಅನ್ಯಥಾ ಯದಿ ((e.v = asm_parse_csrvar(tok)) != -1) {
        next();
    } ಅನ್ಯಥಾ {
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ಯದಿ (!op->e.sym) {
        ಯದಿ ((ಪೂರ್ಣಾಙ್ಕ) op->e.v >= -0x1000 && (ಪೂರ್ಣಾಙ್ಕ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ಅನ್ಯಥಾ ಯದಿ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        ಯದಿ (op->e.sym->type.t & VT_STATIC)
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_PCREL_HI20, 0);
        ಅನ್ಯಥಾ
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_GOT_HI20, 0);
        put_extern_sym(&label, cur_text_section, ind, 0);
        greloca(cur_text_section, &label, ind+4, R_RISCV_PCREL_LO12_I, 0);

        op->type = OP_IM12S;
        op->e.v = 0;
    } ಅನ್ಯಥಾ {
        expect("operand");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_branch_offset_operand(TCCState *s1, Operand *op){
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e = {0};

    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ಯದಿ (!op->e.sym) {
        ಯದಿ ((ಪೂರ್ಣಾಙ್ಕ) op->e.v >= -0x1000 && (ಪೂರ್ಣಾಙ್ಕ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ಅನ್ಯಥಾ ಯದಿ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } ಅನ್ಯಥಾ {
        expect("operand");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_jump_offset_operand(TCCState *s1, Operand *op){
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e = {0};

    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ಯದಿ (!op->e.sym) {
        ಯದಿ ((ಪೂರ್ಣಾಙ್ಕ) op->e.v >= -0x1000 && (ಪೂರ್ಣಾಙ್ಕ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ಅನ್ಯಥಾ ಯದಿ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_text_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } ಅನ್ಯಥಾ {
        expect("operand");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_operands(TCCState *s1, Operand* ops, ಪೂರ್ಣಾಙ್ಕ ಎಣಿಕೆ_2){
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 0; i < ಎಣಿಕೆ_2; i++) {
        ಯದಿ ( i != 0 )
            skip(',');
        parse_operand(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
ಸ್ಥಿರ ಶೂನ್ಯ parse_mem_access_operands(TCCState *s1, Operand* ops){

    Operand op;

    parse_operand(s1, &ops[0]);
    skip(',');
    ಯದಿ ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } ಅನ್ಯಥಾ {
        parse_operand(s1, &ops[2]);
        ಯದಿ ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } ಅನ್ಯಥಾ {
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
ಸ್ಥಿರ ಶೂನ್ಯ asm_jal_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token){
    Operand ops[2];

    ಯದಿ (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } ಅನ್ಯಥಾ ಯದಿ (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } ಅನ್ಯಥಾ {
        // jal reg, offset
        parse_operand(s1, &ops[0]);
        ಯದಿ ( tok == ',') next(); ಅನ್ಯಥಾ expect("','");
    }
    parse_jump_offset_operand(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
ಸ್ಥಿರ ಶೂನ್ಯ asm_jalr_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token){
    Operand ops[3];
    Operand op;

    parse_operand(s1, &ops[0]);
    ಯದಿ ( tok == ',')
        next();
    ಅನ್ಯಥಾ {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } ಅನ್ಯಥಾ {
        parse_operand(s1, &ops[2]);
        ಯದಿ ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } ಅನ್ಯಥಾ {
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


ಸ್ಥಿರ ಶೂನ್ಯ asm_unary_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    Operand op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    ವಿಕಲ್ಪ (token) {
    /* pseudoinstructions */
    ಪಕ್ಷ TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_tail:
        /* auipc x6, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        ಪ್ರತ್ಯಾಗಮ;

    /* C extension */
    ಪಕ್ಷ TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        ಪ್ರತ್ಯಾಗಮ;

    ಸ್ವಭಾವ:
        expect("unary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_u(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand* rd, ಧ್ರುವ Operand* rs2)
{
    ಯದಿ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ರಿಕ್ತ));
    } ಅನ್ಯಥಾ ಯದಿ (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, ರಿಕ್ತ));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ parse_fence_operand(){
    ಪೂರ್ಣಾಙ್ಕ t = tok;
    ಯದಿ ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    next();
    ಪ್ರತ್ಯಾಗಮ t - (TOK_ASM_w_fence - 1);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_fence_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    ಪೂರ್ಣಾಙ್ಕ succ = 0xF, pred = 0xF;
    ಯದಿ (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_operand();
        ಯದಿ ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, ರಿಕ್ತ));
        }
        skip(',');
        succ = parse_fence_operand();
        ಯದಿ ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, ರಿಕ್ತ));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ದ್ವಿಮಾನ_opcode(TCCState* s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand imm = { OP_IM12S };
    Operand ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    ವಿಕಲ್ಪ (token) {
    ಪಕ್ಷ TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;

    /* C extension */
    ಪಕ್ಷ TOK_ASM_c_add:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;

#define CA (1 | (3 << 10) | (4 << 13))
    ಪಕ್ಷ TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
#undef CA

    ಪಕ್ಷ TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;

    /* F/D extension */
    ಪಕ್ಷ TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;

    /* pseudoinstructions */
    /* rd, sym */
    ಪಕ್ಷ TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_li:
        ಯದಿ(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, ರಿಕ್ತ));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        ಯದಿ(lo < 0){
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
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    ಪಕ್ಷ TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_text_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;

    /* CSR pseudo-instructions */
    ಪಕ್ಷ TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ಪ್ರತ್ಯಾಗಮ;
    ಸ್ವಭಾವ:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_r(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand* rd, ಧ್ರುವ Operand* rs1, ಧ್ರುವ Operand* rs2)
{
    ಯದಿ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, ರಿಕ್ತ));
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
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_f(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand* rd, ಧ್ರುವ Operand* rs1, ಧ್ರುವ Operand* rs2)
{
    ಯದಿ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ರಿಕ್ತ));
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
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_fb(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand* rd, ಧ್ರುವ Operand* rs)
{
    ಯದಿ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, ರಿಕ್ತ));
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
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_fq(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand* rd, ಧ್ರುವ Operand* rs1, ಧ್ರುವ Operand* rs2, ಧ್ರುವ Operand* rs3)
{
    ಯದಿ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, ರಿಕ್ತ));
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
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_i(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand* rd, ಧ್ರುವ Operand* rs1, ಧ್ರುವ Operand* rs2)
{
    ಯದಿ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ರಿಕ್ತ));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_j(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand* rd, ಧ್ರುವ Operand* rs2)
{
    uint32_t imm;

    ಯದಿ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ರಿಕ್ತ));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    ಯದಿ ((ಪೂರ್ಣಾಙ್ಕ)imm > (1 << 20) -1 || (ಪೂರ್ಣಾಙ್ಕ)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, ರಿಕ್ತ));
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

ಸ್ಥಿರ ಶೂನ್ಯ asm_mem_access_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{

    Operand ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    ಯದಿ (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    ವಿಕಲ್ಪ (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    ಪಕ್ಷ TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    ಪಕ್ಷ TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_branch_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token, ಪೂರ್ಣಾಙ್ಕ argc)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_offset_operand(s1, &ops[argc-1]);

    ವಿಕಲ್ಪ(token){
    /* branch (RS1, RS2, IMM); B-format */
    ಪಕ್ಷ TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    /* related pseudoinstructions */
    ಪಕ್ಷ TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    /* shorter pseudoinstructions */
    ಪಕ್ಷ TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        ಪ್ರತ್ಯಾಗಮ;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ternary_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], 3);

    ವಿಕಲ್ಪ (token) {
    ಪಕ್ಷ TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ಪ್ರತ್ಯಾಗಮ;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    ಪಕ್ಷ TOK_ASM_add:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    ಪಕ್ಷ TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    ಪಕ್ಷ TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ಪ್ರತ್ಯಾಗಮ;

    /* M extension */
    ಪಕ್ಷ TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    ಪಕ್ಷ TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        ಪ್ರತ್ಯಾಗಮ;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    ಪಕ್ಷ TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;

    /* F/D extension */
    ಪಕ್ಷ TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ಪ್ರತ್ಯಾಗಮ;

    /* F/D comparison: produce integer result, encode manually */
    ಪಕ್ಷ TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ಪ್ರತ್ಯಾಗಮ;

    ಸ್ವಭಾವ:
        expect("ternary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_quaternary_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[4];
    parse_operands(s1, &ops[0], 4);

    ವಿಕಲ್ಪ (token) {
    ಪಕ್ಷ TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ಪ್ರತ್ಯಾಗಮ;

    ಸ್ವಭಾವ:
        expect("quaternary instruction");
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_atomic_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[3];

    parse_operand(s1, &ops[0]);
    skip(',');

    ಯದಿ ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } ಅನ್ಯಥಾ {
        parse_operand(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_operand(s1, &ops[2]);
    skip(')');

    ವಿಕಲ್ಪ(token){
        ಪಕ್ಷ TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ಭಙ್ಗ;

        /* AMO instructions (base, aq=0 rl=0) */
        ಪಕ್ಷ TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ಭಙ್ಗ;

        /* AMO aq/rl variants */
        ಪಕ್ಷ TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;

        ಪಕ್ಷ TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ಭಙ್ಗ;
    }
}

/* caller: Add funct3 and func5 to opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_a(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rd1, ಧ್ರುವ Operand *rs2, ಧ್ರುವ Operand *rs1, ಪೂರ್ಣಾಙ್ಕ aq, ಪೂರ್ಣಾಙ್ಕ rl)
{
    ಯದಿ (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    ಯದಿ (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    ಯದಿ (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
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
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_s(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand* rs1, ಧ್ರುವ Operand* rs2, ಧ್ರುವ Operand* imm)
{
    ಯದಿ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, ರಿಕ್ತ));
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

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_b(ಪೂರ್ಣಾಙ್ಕ token, uint32_t opcode, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *rs2, ಧ್ರುವ Operand *imm)
{
    uint32_t offset;

    ಯದಿ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }
    ಯದಿ (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        ಪೂರ್ಣಾಙ್ಕ b_ofs = ind;
        uint32_t inv_func3 = ((opcode >> 12) & 7) ^ 1;
        uint32_t inv_opcode = (opcode & ~(7 << 12)) | (inv_func3 << 12);
        /* b<inverse> .+8 */
        asm_emit_opcode(inv_opcode | ENCODE_RS1(rs1->reg)
                        | ENCODE_RS2(rs2->reg) | (1 << 8));
        /* auipc t0, 0 */
        greloca(cur_text_section, imm->e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(0x17 | ENCODE_RD(5));
        /* jalr x0, 0(t0) */
        write32le(cur_text_section->data + b_ofs,
                  read32le(cur_text_section->data + b_ofs)
                  | (((ind - b_ofs) >> 1) & 0xf) << 8
                  | (((ind - b_ofs) >> 5) & 0x3f) << 25
                  | (((ind - b_ofs) >> 11) & 1) << 7
                  | (((ind - b_ofs) >> 12) & 1) << 31);
        ಪ್ರತ್ಯಾಗಮ;
    }
    ಯದಿ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ರಿಕ್ತ));
    }

    offset = imm->e.v;

    /* B-type instruction:
    31      imm[12]
    30...25 imm[10:5]
    24...20 rs2
    19...15 rs1
    14...12 funct3
    8...11  imm[4:1]
    7       imm[11]
    6...0   opcode */
    asm_emit_opcode(opcode | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (((offset >> 1) & 0xF) << 8) | (((offset >> 5) & 0x1f) << 25) | (((offset >> 11) & 1) << 7) | (((offset >> 12) & 1) << 31));
}

/* FCVT helper: parse optional rounding mode operand (GNU as syntax:
   fcvt.w.s rd, rs1 [, rtz/rne/rdn/rup/rmm]) */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asm_fcvt_rm(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ rm = 7; /* dynamic */
    ಯದಿ (tok == ',') {
        next();
        ವಿಕಲ್ಪ (tok) {
            ಪಕ್ಷ TOK_ASM_rne: rm = 0; next(); ಭಙ್ಗ;
            ಪಕ್ಷ TOK_ASM_rtz: rm = 1; next(); ಭಙ್ಗ;
            ಪಕ್ಷ TOK_ASM_rdn: rm = 2; next(); ಭಙ್ಗ;
            ಪಕ್ಷ TOK_ASM_rup: rm = 3; next(); ಭಙ್ಗ;
            ಪಕ್ಷ TOK_ASM_rmm: rm = 4; next(); ಭಙ್ಗ;
            ಸ್ವಭಾವ: expect("rounding mode"); ಭಙ್ಗ;
        }
    }
    ಪ್ರತ್ಯಾಗಮ rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
ಸ್ಥಿರ ಶೂನ್ಯ asm_fcvt_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    Operand ops[2];
    ಪೂರ್ಣಾಙ್ಕ rm;
    uint32_t enc = 0;

    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);

    ವಿಕಲ್ಪ (token) {
        ಪಕ್ಷ TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); ಭಙ್ಗ;
        ಸ್ವಭಾವ: expect("fcvt/fclass instruction"); ಪ್ರತ್ಯಾಗಮ;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ token)
{
    ವಿಕಲ್ಪ (token) {
    ಪಕ್ಷ TOK_ASM_ebreak:
    ಪಕ್ಷ TOK_ASM_ecall:
    ಪಕ್ಷ TOK_ASM_fence_i:
    ಪಕ್ಷ TOK_ASM_hrts:
    ಪಕ್ಷ TOK_ASM_mrth:
    ಪಕ್ಷ TOK_ASM_mrts:
    ಪಕ್ಷ TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_rdcycle:
    ಪಕ್ಷ TOK_ASM_rdcycleh:
    ಪಕ್ಷ TOK_ASM_rdtime:
    ಪಕ್ಷ TOK_ASM_rdtimeh:
    ಪಕ್ಷ TOK_ASM_rdinstret:
    ಪಕ್ಷ TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_lui:
    ಪಕ್ಷ TOK_ASM_auipc:
    ಪಕ್ಷ TOK_ASM_fsqrt_s:
    ಪಕ್ಷ TOK_ASM_fsqrt_d:
        asm_ದ್ವಿಮಾನ_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    /* fcvt/fclass — separate handler for optional rounding operand */
    ಪಕ್ಷ TOK_ASM_fcvt_w_s:
    ಪಕ್ಷ TOK_ASM_fcvt_wu_s:
    ಪಕ್ಷ TOK_ASM_fcvt_l_s:
    ಪಕ್ಷ TOK_ASM_fcvt_lu_s:
    ಪಕ್ಷ TOK_ASM_fcvt_s_w:
    ಪಕ್ಷ TOK_ASM_fcvt_s_wu:
    ಪಕ್ಷ TOK_ASM_fcvt_s_l:
    ಪಕ್ಷ TOK_ASM_fcvt_s_lu:
    ಪಕ್ಷ TOK_ASM_fcvt_w_d:
    ಪಕ್ಷ TOK_ASM_fcvt_wu_d:
    ಪಕ್ಷ TOK_ASM_fcvt_l_d:
    ಪಕ್ಷ TOK_ASM_fcvt_lu_d:
    ಪಕ್ಷ TOK_ASM_fcvt_d_w:
    ಪಕ್ಷ TOK_ASM_fcvt_d_wu:
    ಪಕ್ಷ TOK_ASM_fcvt_d_l:
    ಪಕ್ಷ TOK_ASM_fcvt_d_lu:
    ಪಕ್ಷ TOK_ASM_fcvt_s_d:
    ಪಕ್ಷ TOK_ASM_fcvt_d_s:
    ಪಕ್ಷ TOK_ASM_fclass_s:
    ಪಕ್ಷ TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_lb:
    ಪಕ್ಷ TOK_ASM_lh:
    ಪಕ್ಷ TOK_ASM_lw:
    ಪಕ್ಷ TOK_ASM_ld:
    ಪಕ್ಷ TOK_ASM_fld:
    ಪಕ್ಷ TOK_ASM_lbu:
    ಪಕ್ಷ TOK_ASM_lhu:
    ಪಕ್ಷ TOK_ASM_lwu:
    ಪಕ್ಷ TOK_ASM_sb:
    ಪಕ್ಷ TOK_ASM_sh:
    ಪಕ್ಷ TOK_ASM_sw:
    ಪಕ್ಷ TOK_ASM_sd:
    ಪಕ್ಷ TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        ಭಙ್ಗ;

    ಪಕ್ಷ TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        ಭಙ್ಗ;

    ಪಕ್ಷ TOK_ASM_add:
    ಪಕ್ಷ TOK_ASM_addi:
    ಪಕ್ಷ TOK_ASM_addiw:
    ಪಕ್ಷ TOK_ASM_addw:
    ಪಕ್ಷ TOK_ASM_and:
    ಪಕ್ಷ TOK_ASM_andi:
    ಪಕ್ಷ TOK_ASM_or:
    ಪಕ್ಷ TOK_ASM_ori:
    ಪಕ್ಷ TOK_ASM_sll:
    ಪಕ್ಷ TOK_ASM_slli:
    ಪಕ್ಷ TOK_ASM_slliw:
    ಪಕ್ಷ TOK_ASM_sllw:
    ಪಕ್ಷ TOK_ASM_slt:
    ಪಕ್ಷ TOK_ASM_slti:
    ಪಕ್ಷ TOK_ASM_sltiu:
    ಪಕ್ಷ TOK_ASM_sltu:
    ಪಕ್ಷ TOK_ASM_sra:
    ಪಕ್ಷ TOK_ASM_srai:
    ಪಕ್ಷ TOK_ASM_sraiw:
    ಪಕ್ಷ TOK_ASM_sraw:
    ಪಕ್ಷ TOK_ASM_srl:
    ಪಕ್ಷ TOK_ASM_srli:
    ಪಕ್ಷ TOK_ASM_srliw:
    ಪಕ್ಷ TOK_ASM_srlw:
    ಪಕ್ಷ TOK_ASM_sub:
    ಪಕ್ಷ TOK_ASM_subw:
    ಪಕ್ಷ TOK_ASM_xor:
    ಪಕ್ಷ TOK_ASM_xori:
    /* M extension */
    ಪಕ್ಷ TOK_ASM_div:
    ಪಕ್ಷ TOK_ASM_divu:
    ಪಕ್ಷ TOK_ASM_divuw:
    ಪಕ್ಷ TOK_ASM_divw:
    ಪಕ್ಷ TOK_ASM_mul:
    ಪಕ್ಷ TOK_ASM_mulh:
    ಪಕ್ಷ TOK_ASM_mulhsu:
    ಪಕ್ಷ TOK_ASM_mulhu:
    ಪಕ್ಷ TOK_ASM_mulw:
    ಪಕ್ಷ TOK_ASM_rem:
    ಪಕ್ಷ TOK_ASM_remu:
    ಪಕ್ಷ TOK_ASM_remuw:
    ಪಕ್ಷ TOK_ASM_remw:
    /* Zicsr extension */
    ಪಕ್ಷ TOK_ASM_csrrc:
    ಪಕ್ಷ TOK_ASM_csrrci:
    ಪಕ್ಷ TOK_ASM_csrrs:
    ಪಕ್ಷ TOK_ASM_csrrsi:
    ಪಕ್ಷ TOK_ASM_csrrw:
    ಪಕ್ಷ TOK_ASM_csrrwi:
    /* F/D extension */
    ಪಕ್ಷ TOK_ASM_fadd_s:
    ಪಕ್ಷ TOK_ASM_fadd_d:
    ಪಕ್ಷ TOK_ASM_fsub_s:
    ಪಕ್ಷ TOK_ASM_fsub_d:
    ಪಕ್ಷ TOK_ASM_fmul_s:
    ಪಕ್ಷ TOK_ASM_fmul_d:
    ಪಕ್ಷ TOK_ASM_fdiv_s:
    ಪಕ್ಷ TOK_ASM_fdiv_d:
    ಪಕ್ಷ TOK_ASM_fsgnj_d:
    ಪಕ್ಷ TOK_ASM_fsgnj_s:
    ಪಕ್ಷ TOK_ASM_fmax_s:
    ಪಕ್ಷ TOK_ASM_fmax_d:
    ಪಕ್ಷ TOK_ASM_fmin_s:
    ಪಕ್ಷ TOK_ASM_fmin_d:
    ಪಕ್ಷ TOK_ASM_feq_s:
    ಪಕ್ಷ TOK_ASM_feq_d:
    ಪಕ್ಷ TOK_ASM_flt_s:
    ಪಕ್ಷ TOK_ASM_flt_d:
    ಪಕ್ಷ TOK_ASM_fle_s:
    ಪಕ್ಷ TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_fmadd_d:
    ಪಕ್ಷ TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    /* Branches */
    ಪಕ್ಷ TOK_ASM_beq:
    ಪಕ್ಷ TOK_ASM_bge:
    ಪಕ್ಷ TOK_ASM_bgeu:
    ಪಕ್ಷ TOK_ASM_blt:
    ಪಕ್ಷ TOK_ASM_bltu:
    ಪಕ್ಷ TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        ಭಙ್ಗ;

    /* C extension */
    ಪಕ್ಷ TOK_ASM_c_ebreak:
    ಪಕ್ಷ TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_c_j:
    ಪಕ್ಷ TOK_ASM_c_jal:
    ಪಕ್ಷ TOK_ASM_c_jalr:
    ಪಕ್ಷ TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_c_add:
    ಪಕ್ಷ TOK_ASM_c_addi16sp:
    ಪಕ್ಷ TOK_ASM_c_addi4spn:
    ಪಕ್ಷ TOK_ASM_c_addi:
    ಪಕ್ಷ TOK_ASM_c_addiw:
    ಪಕ್ಷ TOK_ASM_c_addw:
    ಪಕ್ಷ TOK_ASM_c_and:
    ಪಕ್ಷ TOK_ASM_c_andi:
    ಪಕ್ಷ TOK_ASM_c_beqz:
    ಪಕ್ಷ TOK_ASM_c_bnez:
    ಪಕ್ಷ TOK_ASM_c_fldsp:
    ಪಕ್ಷ TOK_ASM_c_flwsp:
    ಪಕ್ಷ TOK_ASM_c_fsdsp:
    ಪಕ್ಷ TOK_ASM_c_fswsp:
    ಪಕ್ಷ TOK_ASM_c_ldsp:
    ಪಕ್ಷ TOK_ASM_c_li:
    ಪಕ್ಷ TOK_ASM_c_lui:
    ಪಕ್ಷ TOK_ASM_c_lwsp:
    ಪಕ್ಷ TOK_ASM_c_mv:
    ಪಕ್ಷ TOK_ASM_c_or:
    ಪಕ್ಷ TOK_ASM_c_sdsp:
    ಪಕ್ಷ TOK_ASM_c_slli:
    ಪಕ್ಷ TOK_ASM_c_srai:
    ಪಕ್ಷ TOK_ASM_c_srli:
    ಪಕ್ಷ TOK_ASM_c_sub:
    ಪಕ್ಷ TOK_ASM_c_subw:
    ಪಕ್ಷ TOK_ASM_c_swsp:
    ಪಕ್ಷ TOK_ASM_c_xor:
        asm_ದ್ವಿಮಾನ_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_c_fld:
    ಪಕ್ಷ TOK_ASM_c_flw:
    ಪಕ್ಷ TOK_ASM_c_fsd:
    ಪಕ್ಷ TOK_ASM_c_fsw:
    ಪಕ್ಷ TOK_ASM_c_ld:
    ಪಕ್ಷ TOK_ASM_c_lw:
    ಪಕ್ಷ TOK_ASM_c_sd:
    ಪಕ್ಷ TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    /* pseudoinstructions */
    ಪಕ್ಷ TOK_ASM_nop:
    ಪಕ್ಷ TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_jr:
    ಪಕ್ಷ TOK_ASM_call:
    ಪಕ್ಷ TOK_ASM_tail:
    ಪಕ್ಷ TOK_ASM_frflags:
    ಪಕ್ಷ TOK_ASM_frrm:
    ಪಕ್ಷ TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_la:
    ಪಕ್ಷ TOK_ASM_lla:
    ಪಕ್ಷ TOK_ASM_li:
    ಪಕ್ಷ TOK_ASM_jump:
    ಪಕ್ಷ TOK_ASM_seqz:
    ಪಕ್ಷ TOK_ASM_snez:
    ಪಕ್ಷ TOK_ASM_sltz:
    ಪಕ್ಷ TOK_ASM_sgtz:
    ಪಕ್ಷ TOK_ASM_mv:
    ಪಕ್ಷ TOK_ASM_not:
    ಪಕ್ಷ TOK_ASM_neg:
    ಪಕ್ಷ TOK_ASM_negw:
    ಪಕ್ಷ TOK_ASM_sext_w:
    ಪಕ್ಷ TOK_ASM_fabs_s:
    ಪಕ್ಷ TOK_ASM_fabs_d:
    ಪಕ್ಷ TOK_ASM_fmv_s:
    ಪಕ್ಷ TOK_ASM_fmv_d:
    ಪಕ್ಷ TOK_ASM_fneg_s:
    ಪಕ್ಷ TOK_ASM_fneg_d:
    ಪಕ್ಷ TOK_ASM_csrc:
    ಪಕ್ಷ TOK_ASM_csrs:
    ಪಕ್ಷ TOK_ASM_csrr:
    ಪಕ್ಷ TOK_ASM_csrw:
    ಪಕ್ಷ TOK_ASM_csrwi:
    ಪಕ್ಷ TOK_ASM_csrsi:
    ಪಕ್ಷ TOK_ASM_csrci:
    ಪಕ್ಷ TOK_ASM_fsrm:
    ಪಕ್ಷ TOK_ASM_fscsr:
        asm_ದ್ವಿಮಾನ_opcode(s1, token);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_bnez:
    ಪಕ್ಷ TOK_ASM_beqz:
    ಪಕ್ಷ TOK_ASM_blez:
    ಪಕ್ಷ TOK_ASM_bgez:
    ಪಕ್ಷ TOK_ASM_bltz:
    ಪಕ್ಷ TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        ಪ್ರತ್ಯಾಗಮ;

    ಪಕ್ಷ TOK_ASM_bgt:
    ಪಕ್ಷ TOK_ASM_bgtu:
    ಪಕ್ಷ TOK_ASM_ble:
    ಪಕ್ಷ TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        ಪ್ರತ್ಯಾಗಮ;

    /* Atomic operations */
    ಪಕ್ಷ TOK_ASM_lr_w:
    ಪಕ್ಷ TOK_ASM_lr_w_aq:
    ಪಕ್ಷ TOK_ASM_lr_w_rl:
    ಪಕ್ಷ TOK_ASM_lr_w_aqrl:
    ಪಕ್ಷ TOK_ASM_lr_d:
    ಪಕ್ಷ TOK_ASM_lr_d_aq:
    ಪಕ್ಷ TOK_ASM_lr_d_rl:
    ಪಕ್ಷ TOK_ASM_lr_d_aqrl:
    ಪಕ್ಷ TOK_ASM_sc_w:
    ಪಕ್ಷ TOK_ASM_sc_w_aq:
    ಪಕ್ಷ TOK_ASM_sc_w_rl:
    ಪಕ್ಷ TOK_ASM_sc_w_aqrl:
    ಪಕ್ಷ TOK_ASM_sc_d:
    ಪಕ್ಷ TOK_ASM_sc_d_aq:
    ಪಕ್ಷ TOK_ASM_sc_d_rl:
    ಪಕ್ಷ TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    ಪಕ್ಷ TOK_ASM_amoadd_w:
    ಪಕ್ಷ TOK_ASM_amoadd_d:
    ಪಕ್ಷ TOK_ASM_amoswap_w:
    ಪಕ್ಷ TOK_ASM_amoswap_d:
    ಪಕ್ಷ TOK_ASM_amoand_w:
    ಪಕ್ಷ TOK_ASM_amoand_d:
    ಪಕ್ಷ TOK_ASM_amoor_w:
    ಪಕ್ಷ TOK_ASM_amoor_d:
    ಪಕ್ಷ TOK_ASM_amoxor_w:
    ಪಕ್ಷ TOK_ASM_amoxor_d:
    ಪಕ್ಷ TOK_ASM_amomax_w:
    ಪಕ್ಷ TOK_ASM_amomax_d:
    ಪಕ್ಷ TOK_ASM_amomaxu_w:
    ಪಕ್ಷ TOK_ASM_amomaxu_d:
    ಪಕ್ಷ TOK_ASM_amomin_w:
    ಪಕ್ಷ TOK_ASM_amomin_d:
    ಪಕ್ಷ TOK_ASM_amominu_w:
    ಪಕ್ಷ TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    ಪಕ್ಷ TOK_ASM_amoadd_w_aq:
    ಪಕ್ಷ TOK_ASM_amoadd_w_rl:
    ಪಕ್ಷ TOK_ASM_amoadd_w_aqrl:
    ಪಕ್ಷ TOK_ASM_amoadd_d_aq:
    ಪಕ್ಷ TOK_ASM_amoadd_d_rl:
    ಪಕ್ಷ TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    ಪಕ್ಷ TOK_ASM_amoswap_w_aq:
    ಪಕ್ಷ TOK_ASM_amoswap_w_rl:
    ಪಕ್ಷ TOK_ASM_amoswap_w_aqrl:
    ಪಕ್ಷ TOK_ASM_amoswap_d_aq:
    ಪಕ್ಷ TOK_ASM_amoswap_d_rl:
    ಪಕ್ಷ TOK_ASM_amoswap_d_aqrl:
    ಪಕ್ಷ TOK_ASM_amoand_w_aq:
    ಪಕ್ಷ TOK_ASM_amoand_w_rl:
    ಪಕ್ಷ TOK_ASM_amoand_w_aqrl:
    ಪಕ್ಷ TOK_ASM_amoand_d_aq:
    ಪಕ್ಷ TOK_ASM_amoand_d_rl:
    ಪಕ್ಷ TOK_ASM_amoand_d_aqrl:
    ಪಕ್ಷ TOK_ASM_amoor_w_aq:
    ಪಕ್ಷ TOK_ASM_amoor_w_rl:
    ಪಕ್ಷ TOK_ASM_amoor_w_aqrl:
    ಪಕ್ಷ TOK_ASM_amoor_d_aq:
    ಪಕ್ಷ TOK_ASM_amoor_d_rl:
    ಪಕ್ಷ TOK_ASM_amoor_d_aqrl:
    ಪಕ್ಷ TOK_ASM_amoxor_w_aq:
    ಪಕ್ಷ TOK_ASM_amoxor_w_rl:
    ಪಕ್ಷ TOK_ASM_amoxor_w_aqrl:
    ಪಕ್ಷ TOK_ASM_amoxor_d_aq:
    ಪಕ್ಷ TOK_ASM_amoxor_d_rl:
    ಪಕ್ಷ TOK_ASM_amoxor_d_aqrl:
    ಪಕ್ಷ TOK_ASM_amomax_w_aq:
    ಪಕ್ಷ TOK_ASM_amomax_w_rl:
    ಪಕ್ಷ TOK_ASM_amomax_w_aqrl:
    ಪಕ್ಷ TOK_ASM_amomax_d_aq:
    ಪಕ್ಷ TOK_ASM_amomax_d_rl:
    ಪಕ್ಷ TOK_ASM_amomax_d_aqrl:
    ಪಕ್ಷ TOK_ASM_amomaxu_w_aq:
    ಪಕ್ಷ TOK_ASM_amomaxu_w_rl:
    ಪಕ್ಷ TOK_ASM_amomaxu_w_aqrl:
    ಪಕ್ಷ TOK_ASM_amomaxu_d_aq:
    ಪಕ್ಷ TOK_ASM_amomaxu_d_rl:
    ಪಕ್ಷ TOK_ASM_amomaxu_d_aqrl:
    ಪಕ್ಷ TOK_ASM_amomin_w_aq:
    ಪಕ್ಷ TOK_ASM_amomin_w_rl:
    ಪಕ್ಷ TOK_ASM_amomin_w_aqrl:
    ಪಕ್ಷ TOK_ASM_amomin_d_aq:
    ಪಕ್ಷ TOK_ASM_amomin_d_rl:
    ಪಕ್ಷ TOK_ASM_amomin_d_aqrl:
    ಪಕ್ಷ TOK_ASM_amominu_w_aq:
    ಪಕ್ಷ TOK_ASM_amominu_w_rl:
    ಪಕ್ಷ TOK_ASM_amominu_w_aqrl:
    ಪಕ್ಷ TOK_ASM_amominu_d_aq:
    ಪಕ್ಷ TOK_ASM_amominu_d_rl:
    ಪಕ್ಷ TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        ಭಙ್ಗ;

    ಸ್ವಭಾವ:
        expect("known instruction");
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asm_parse_csrvar(ಪೂರ್ಣಾಙ್ಕ t)
{
    ವಿಕಲ್ಪ (t) {
    ಪಕ್ಷ TOK_ASM_cycle:
        ಪ್ರತ್ಯಾಗಮ 0xc00;
    ಪಕ್ಷ TOK_ASM_fcsr:
        ಪ್ರತ್ಯಾಗಮ 3;
    ಪಕ್ಷ TOK_ASM_fflags:
        ಪ್ರತ್ಯಾಗಮ 1;
    ಪಕ್ಷ TOK_ASM_frm:
        ಪ್ರತ್ಯಾಗಮ 2;
    ಪಕ್ಷ TOK_ASM_instret:
        ಪ್ರತ್ಯಾಗಮ 0xc02;
    ಪಕ್ಷ TOK_ASM_time:
        ಪ್ರತ್ಯಾಗಮ 0xc01;
    ಪಕ್ಷ TOK_ASM_cycleh:
        ಪ್ರತ್ಯಾಗಮ 0xc80;
    ಪಕ್ಷ TOK_ASM_instreth:
        ಪ್ರತ್ಯಾಗಮ 0xc82;
    ಪಕ್ಷ TOK_ASM_timeh:
        ಪ್ರತ್ಯಾಗಮ 0xc81;
    ಸ್ವಭಾವ:
        ಪ್ರತ್ಯಾಗಮ -1;
    }
}

ST_FUNC ಶೂನ್ಯ subst_asm_operand(CString *add_str, SValue *sv, ಪೂರ್ಣಾಙ್ಕ modifier)
{
    ಪೂರ್ಣಾಙ್ಕ r, reg, val;

    r = sv->r;
    ಯದಿ ((r & VT_VALMASK) == VT_CONST) {
        ಯದಿ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        ಯದಿ (r & VT_SYM) {
            ಧ್ರುವ ವರ್ಣ *name = get_tok_str(sv->sym->v, ರಿಕ್ತ);
            ಯದಿ (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            ಯದಿ (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            ಯದಿ ((uint32_t) sv->c.i == 0)
                ಗಚ್ಛ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        ಯದಿ (modifier == 'n')
            val = -val;
        ಯದಿ (modifier == 'z' && val == 0) {
            cstr_cat(add_str, "zero", -1);
        } ಅನ್ಯಥಾ {
            cstr_printf(add_str, "%d", val);
        }
      no_offset:;
    } ಅನ್ಯಥಾ ಯದಿ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d", (ಪೂರ್ಣಾಙ್ಕ) sv->c.i);
    } ಅನ್ಯಥಾ ಯದಿ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ಯದಿ (reg >= VT_CONST)
            tcc_internal_error("");
        ಯದಿ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_ಮೌಲ್ಯ(reg);
        } ಅನ್ಯಥಾ {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, ರಿಕ್ತ), -1);
    } ಅನ್ಯಥಾ {
        /* register case */
        reg = r & VT_VALMASK;
        ಯದಿ (reg >= VT_CONST)
            tcc_internal_error("");
        ಯದಿ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_ಮೌಲ್ಯ(reg);
        } ಅನ್ಯಥಾ {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, ರಿಕ್ತ), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_ireg(ಪೂರ್ಣಾಙ್ಕ r){
    ಪ್ರತ್ಯಾಗಮ REG_ಮೌಲ್ಯ(r) - 10;
}
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_freg(ಪೂರ್ಣಾಙ್ಕ r){
    ಪ್ರತ್ಯಾಗಮ REG_ಮೌಲ್ಯ(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ಶೂನ್ಯ asm_gen_code(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands,
                         ಪೂರ್ಣಾಙ್ಕ nb_outputs, ಪೂರ್ಣಾಙ್ಕ is_output,
                         uint8_t *clobber_regs,
                         ಪೂರ್ಣಾಙ್ಕ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ಪೂರ್ಣಾಙ್ಕ i, reg;

    ಸ್ಥಿರ ಧ್ರುವ uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, ಪರಿಮಾಣ(regs_allocated));
    ಪ್ರತಿ(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ಯದಿ (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    ಯದಿ(!is_output) {
        /* generate reg save code */
        ಪ್ರತಿ(i = 0; i < ಪರಿಮಾಣ(reg_saved)/ಪರಿಮಾಣ(reg_saved[0]); i++) {
            reg = reg_saved[i];
            ಯದಿ (regs_allocated[reg]) {
                /*ತಳ್ಳು*/
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (unsigned)-8 << 20);
                ಯದಿ (REG_IS_FLOAT(reg)){
                    /* fsd reg, offset(sp) */
                    gen_le32( 0x27 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                } ಅನ್ಯಥಾ {
                    /* sd reg, offset(sp) */
                    gen_le32((0x8 << 2) | 3 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                }
            }
        }

        /* generate load code */
        ಪ್ರತಿ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ಯದಿ (op->reg >= 0) {
                ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(tcc_ireg(op->reg), &sv);
                } ಅನ್ಯಥಾ ಯದಿ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    ಯದಿ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        load(tcc_freg(op->reg), op->vt);
                    } ಅನ್ಯಥಾ {
                        load(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register;
                       the load/store above already handles it correctly */
                }
            }
        }
    } ಅನ್ಯಥಾ {
        /* generate save code */
        ಪ್ರತಿ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ಯದಿ (op->reg >= 0) {
                ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ಯದಿ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(tcc_ireg(out_reg), &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(tcc_ireg(op->reg), &sv);
                    }
                } ಅನ್ಯಥಾ {
                    ಯದಿ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        store(tcc_freg(op->reg), op->vt);
                    } ಅನ್ಯಥಾ {
                        store(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register */
                }
            }
        }
        /* generate reg restore code for floating point registers */
        ಪ್ರತಿ(i = ಪರಿಮಾಣ(reg_saved)/ಪರಿಮಾಣ(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            ಯದಿ (regs_allocated[reg]) {
                /*ತೆಗೆ*/
                ಯದಿ (REG_IS_FLOAT(reg)){
                    /* fld reg, offset(sp) */
                    gen_le32(7 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                } ಅನ್ಯಥಾ {
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
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ constraint_priority(ಧ್ರುವ ವರ್ಣ *str)
{
    // TODO: How is this chosen??
    ಪೂರ್ಣಾಙ್ಕ priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    ಪ್ರತಿ(;;) {
        c = *str;
        ಯದಿ (c == '\0')
            ಭಙ್ಗ;
        str++;
        ವಿಕಲ್ಪ(c) {
        ಪಕ್ಷ 'A': // address that is held in a general-purpose register.
        ಪಕ್ಷ 'S': // constraint that matches an absolute symbolic address.
        ಪಕ್ಷ 'f': // register [float]
        ಪಕ್ಷ 'r': // register [general]
        ಪಕ್ಷ 'p': // valid memory address for load,store [general]
            pr = 3;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'I': // 12 bit signed immedate
        ಪಕ್ಷ 'i': // immediate integer operand, including symbolic constants [general]
        ಪಕ್ಷ 'm': // memory operand [general]
        ಪಕ್ಷ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'v':
            tcc_error("unimp: constraint '%c'", c);
        ಸ್ವಭಾವ:
            tcc_error("unknown constraint '%d'", c);
        }
        ಯದಿ (pr > priority)
            priority = pr;
    }
    ಪ್ರತ್ಯಾಗಮ priority;
}

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ *skip_constraint_modifiers(ಧ್ರುವ ವರ್ಣ *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ಯಾವತ್ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ಪ್ರತ್ಯಾಗಮ p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands,
                                    ಪೂರ್ಣಾಙ್ಕ nb_operands, ಪೂರ್ಣಾಙ್ಕ nb_outputs,
                                    ಧ್ರುವ uint8_t *clobber_regs,
                                    ಪೂರ್ಣಾಙ್ಕ *pout_reg)
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
    ಪೂರ್ಣಾಙ್ಕ sorted_op[MAX_ASM_OPERANDS];
    ಪೂರ್ಣಾಙ್ಕ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ಧ್ರುವ ವರ್ಣ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ಒಳಹರಿವು_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ಯದಿ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, ರಿಕ್ತ);
            ಯದಿ ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            ಯದಿ (operands[k].ಒಳಹರಿವು_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ಒಳಹರಿವು_index = i;
            op->priority = 5;
        } ಅನ್ಯಥಾ ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } ಅನ್ಯಥಾ {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    ಪ್ರತಿ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ಪ್ರತಿ (i = 0; i < nb_operands - 1; i++) {
        ಪ್ರತಿ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            ಯದಿ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ಪ್ರತಿ (i = 0; i < NB_ASM_REGS; i++) {
        ಯದಿ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        ಅನ್ಯಥಾ
            regs_allocated[i] = 0;
    }

    /* allocate registers and generate corresponding asm moves */
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ಯದಿ (op->ref_index >= 0)
            ಅನುವರ್ತ;
        /* select if register is used for output, input or both */
        ಯದಿ (op->ಒಳಹರಿವು_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } ಅನ್ಯಥಾ ಯದಿ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } ಅನ್ಯಥಾ {
            reg_mask = REG_IN_MASK;
        }
        ಯದಿ (op->reg >= 0) {
            ಯದಿ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        ವಿಕಲ್ಪ (c) {
        ಪಕ್ಷ '=': // Operand is written-to
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        ಪಕ್ಷ '&': // Operand is clobbered before the instruction is done using the input operands
            ಯದಿ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ 'r': // general-purpose register
        ಪಕ್ಷ 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            ಯದಿ ((reg = op->reg) >= 0)
                ಗಚ್ಛ reg_found;
            ಅನ್ಯಥಾ ಪ್ರತಿ (reg = 10; reg <= 18; reg++) {
                ಯದಿ (!is_reg_allocated(reg))
                    ಗಚ್ಛ reg_found;
            }
            ಗಚ್ಛ try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            ಯದಿ ((reg = op->reg) >= 0)
                ಗಚ್ಛ reg_found;
            ಅನ್ಯಥಾ ಪ್ರತಿ (reg = 42; reg <= 50; reg++) {
                ಯದಿ (!is_reg_allocated(reg))
                    ಗಚ್ಛ reg_found;
            }
            ಗಚ್ಛ try_next;
        ಪಕ್ಷ 'I': // I-Type 12 bit signed immediate
        ಪಕ್ಷ 'i': // immediate integer operand, including symbolic constants
            ಯದಿ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ಗಚ್ಛ try_next;
            ಭಙ್ಗ;
        ಪಕ್ಷ 'm': // memory operand
        ಪಕ್ಷ 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ಯದಿ (j < nb_outputs || c == 'm') {
                ಯದಿ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    ಪ್ರತಿ (reg = 10; reg <= 18; reg++) {
                        ಯದಿ (!(regs_allocated[reg] & REG_IN_MASK))
                            ಗಚ್ಛ reg_found1;
                    }
                    ಗಚ್ಛ try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ಭಙ್ಗ;
        }
        /* if a reference is present for that operand, we assign it too */
        ಯದಿ (op->ಒಳಹರಿವು_index >= 0) {
            operands[op->ಒಳಹರಿವು_index].reg = op->reg;
            operands[op->ಒಳಹರಿವು_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ಯದಿ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            ಯದಿ (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                ಪ್ರತಿ (reg = 42; reg <= 50; reg++) {
                    ಯದಿ (!(regs_allocated[reg] & REG_OUT_MASK))
                        ಗಚ್ಛ reg_found2;
                }
            } ಅನ್ಯಥಾ {
                /* From a0 to a7 */
                ಪ್ರತಿ (reg = 10; reg <= 18; reg++) {
                    ಯದಿ (!(regs_allocated[reg] & REG_OUT_MASK))
                        ಗಚ್ಛ reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ಭಙ್ಗ;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    ಪ್ರತಿ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ರಿಕ್ತ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ಯದಿ (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಧ್ರುವ ವರ್ಣ *str)
{
    ಪೂರ್ಣಾಙ್ಕ reg;
    TokenSym *ts;

    ಯದಿ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ಪ್ರತ್ಯಾಗಮ;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    ಯದಿ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ asm_parse_regvar (ಪೂರ್ಣಾಙ್ಕ t)
{
    /* PC register not implemented */
    ಯದಿ (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        ಪ್ರತ್ಯಾಗಮ -1;

    ಯದಿ (t < TOK_ASM_f0)
        ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_x0;

    ಯದಿ (t < TOK_ASM_zero)
        ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    ಯದಿ (t < TOK_ASM_ft0)
        ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_zero;

    ಪ್ರತ್ಯಾಗಮ t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ca(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs2)
{
    uint8_t dst, src;

    ಯದಿ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    ಯದಿ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ರಿಕ್ತ));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cb(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *imm)
{
    uint32_t offset;
    uint8_t src;

    ಯದಿ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ರಿಕ್ತ));
    }

    offset = imm->e.v;

    ಯದಿ (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ರಿಕ್ತ));
    }

    src = rs1->reg - 8;

    ಯದಿ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ರಿಕ್ತ));
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

    ವಿಕಲ್ಪ (token) {
    ಪಕ್ಷ TOK_ASM_c_beqz:
    ಪಕ್ಷ TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_BIT(offset, 5) | (((offset >> 1) & 3) << 1) | (((offset >> 6) & 3) << 3)) << 2) | ((((offset >> 3) & 3) | NTH_BIT(offset, 8)) << 10));
        ಪ್ರತ್ಯಾಗಮ;
    ಸ್ವಭಾವ:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((offset & 0x1f) << 2) | (NTH_BIT(offset, 5) << 12));
        ಪ್ರತ್ಯಾಗಮ;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ci(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *imm)
{
    uint32_t immediate;

    ಯದಿ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ರಿಕ್ತ));
    }

    immediate = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    ವಿಕಲ್ಪ (token) {
    ಪಕ್ಷ TOK_ASM_c_addi:
    ಪಕ್ಷ TOK_ASM_c_addiw:
    ಪಕ್ಷ TOK_ASM_c_li:
    ಪಕ್ಷ TOK_ASM_c_slli:
        gen_le16(opcode | ((immediate & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_BIT(immediate, 5) << 2 | (((immediate >> 7) & 3) << 3) | NTH_BIT(immediate, 6) << 5 | NTH_BIT(immediate, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 9) << 12));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_lui:
        gen_le16(opcode | (((immediate >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 17) << 12));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_fldsp:
    ಪಕ್ಷ TOK_ASM_c_ldsp:
        gen_le16(opcode | (((immediate >> 6) & 7) << 2) | (((immediate >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_flwsp:
    ಪಕ್ಷ TOK_ASM_c_lwsp:
        gen_le16(opcode | (((immediate >> 6) & 3) << 2) | (((immediate >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ಪ್ರತ್ಯಾಗಮ;
    ಪಕ್ಷ TOK_ASM_c_nop:
        gen_le16(opcode);
        ಪ್ರತ್ಯಾಗಮ;
    ಸ್ವಭಾವ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_ciw(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    ಯದಿ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ರಿಕ್ತ));
    }

    dst = rd->reg - 8;

    ಯದಿ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ರಿಕ್ತ));
    }

    nzuimm = imm->e.v;

    ಯದಿ (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, ರಿಕ್ತ));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_BIT(nzuimm, 3) | (NTH_BIT(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cj(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *imm)
{
    uint32_t offset;

    /* +-2 KiB range */
    ಯದಿ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, ರಿಕ್ತ));
    }

    offset = imm->e.v;

    ಯದಿ (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ರಿಕ್ತ));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_BIT(offset, 5) << 2) | (((offset >> 1) & 7) << 3) | (NTH_BIT(offset, 7) << 6) | (NTH_BIT(offset, 6) << 7) | (NTH_BIT(offset, 10) << 8) | (((offset >> 8) & 3) << 9) | (NTH_BIT(offset, 4) << 11) | (NTH_BIT(offset, 11) << 12));
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cl(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *imm)
{
    uint32_t offset;
    uint8_t dst, src;

    ಯದಿ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ರಿಕ್ತ));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    ಯದಿ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ರಿಕ್ತ));
    }

    offset = imm->e.v;

    ಯದಿ (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ರಿಕ್ತ));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    ವಿಕಲ್ಪ (token) {
    /* imm variant 1 */
    ಪಕ್ಷ TOK_ASM_c_flw:
    ಪಕ್ಷ TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        ಪ್ರತ್ಯಾಗಮ;
    /* imm variant 2 */
    ಪಕ್ಷ TOK_ASM_c_fld:
    ಪಕ್ಷ TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        ಪ್ರತ್ಯಾಗಮ;
    ಸ್ವಭಾವ:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cr(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rd, ಧ್ರುವ Operand *rs2)
{
    ಯದಿ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_cs(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rs2, ಧ್ರುವ Operand *rs1, ಧ್ರುವ Operand *imm)
{
    uint32_t offset;
    uint8_t base, src;

    ಯದಿ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ರಿಕ್ತ));
    }

    base = rs1->reg - 8;
    src = rs2->reg - 8;

    ಯದಿ (base > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ರಿಕ್ತ));
    }

    offset = imm->e.v;

    ಯದಿ (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ರಿಕ್ತ));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    ವಿಕಲ್ಪ (token) {
    /* imm variant 1 */
    ಪಕ್ಷ TOK_ASM_c_fsw:
    ಪಕ್ಷ TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        ಪ್ರತ್ಯಾಗಮ;
    /* imm variant 2 */
    ಪಕ್ಷ TOK_ASM_c_fsd:
    ಪಕ್ಷ TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        ಪ್ರತ್ಯಾಗಮ;
    ಸ್ವಭಾವ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
ಸ್ಥಿರ ಶೂನ್ಯ asm_emit_css(ಪೂರ್ಣಾಙ್ಕ token, uint16_t opcode, ಧ್ರುವ Operand *rs2, ಧ್ರುವ Operand *imm)
{
    uint32_t offset;

    ಯದಿ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ರಿಕ್ತ));
    }

    offset = imm->e.v;

    ಯದಿ (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ರಿಕ್ತ));
    }

    ಯದಿ (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ರಿಕ್ತ));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    ವಿಕಲ್ಪ (token) {
    /* imm variant 1 */
    ಪಕ್ಷ TOK_ASM_c_fswsp:
    ಪಕ್ಷ TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 3) << 7) | (((offset >> 2) & 0xf) << 9));
        ಪ್ರತ್ಯಾಗಮ;
    /* imm variant 2 */
    ಪಕ್ಷ TOK_ASM_c_fsdsp:
    ಪಕ್ಷ TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 7) << 7) | (((offset >> 3) & 7) << 10));
        ಪ್ರತ್ಯಾಗಮ;
    ಸ್ವಭಾವ:
        expect("known instruction");
    }
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
