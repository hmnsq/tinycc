/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#ifdef TARGET_DEFS_ONLY

#define CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#define NB_ASM_REGS 64

ST_FUNC ଶୂନ୍ୟ g(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC ଶୂନ୍ୟ gen_le16(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC ଶୂନ୍ୟ gen_le32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);

/*************************************************************/
#ଅନ୍ୟଥା
/*************************************************************/
#define USING_GLOBALS
#ଅନ୍ତର୍ଭାଵ "tcc.h"

ଗଣନା {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#define REG_FLOAT_MASK 0x20
#define REG_IS_FLOAT(register_index) ((register_index) & REG_FLOAT_MASK)
#define REG_ମୂଲ୍ୟ(register_index)    ((register_index) & (REG_FLOAT_MASK-1))
#define C_ENCODE_RS1(register_index) (REG_ମୂଲ୍ୟ(register_index) << 7)
#define C_ENCODE_RS2(register_index) (REG_ମୂଲ୍ୟ(register_index) << 2)
#define ENCODE_RD(register_index)  (REG_ମୂଲ୍ୟ(register_index) << 7)
#define ENCODE_RS1(register_index) (REG_ମୂଲ୍ୟ(register_index) << 15)
#define ENCODE_RS2(register_index) (REG_ମୂଲ୍ୟ(register_index) << 20)
#define NTH_BIT(b, n) ((b >> n) & 1)
#define OP_IM12S (1 << OPT_IM12S)
#define OP_IM32 (1 << OPT_IM32)
#define OP_REG (1 << OPT_REG)

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା Operand {
    uint32_t type;
    ସଂଘ {
        uint8_t reg;
        uint16_t regset;
        ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e;
    };
} Operand;

ସ୍ଥିର ଅଚଳ Operand zero = { OP_REG, { 0 }};
ସ୍ଥିର ଅଚଳ Operand ra = { OP_REG, { 1 }};
ସ୍ଥିର ଅଚଳ Operand zimm = { OP_IM12S };

ସ୍ଥିର ଶୂନ୍ୟ asm_ଦ୍ୱିମିକ_opcode(TCCState* s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token);
ST_FUNC ଶୂନ୍ୟ asm_clobber(uint8_t *clobber_regs, ଅଚଳ ଅକ୍ଷର *str);
ST_FUNC ଶୂନ୍ୟ asm_compute_constraints(ASMOperand *operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_outputs, ଅଚଳ uint8_t *clobber_regs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pout_reg);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_a(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rs1, ଅଚଳ Operand *rs2, ଅଚଳ Operand *rd1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା aq, ପୂର୍ଣ୍ଣସଂଖ୍ୟା rl);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_b(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rs1, ଅଚଳ Operand *rs2, ଅଚଳ Operand *imm);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_i(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs1, ଅଚଳ Operand *rs2);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_j(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs2);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_opcode(uint32_t opcode);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_r(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs1, ଅଚଳ Operand *rs2);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_s(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rs1, ଅଚଳ Operand *rs2, ଅଚଳ Operand *imm);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_u(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs2);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_f(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs1, ଅଚଳ Operand *rs2);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_fb(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_fq(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs1, ଅଚଳ Operand *rs2, ଅଚଳ Operand *rs3);
ST_FUNC ଶୂନ୍ୟ asm_gen_code(ASMOperand *operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_outputs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_output, uint8_t *clobber_regs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା out_reg);
ସ୍ଥିର ଶୂନ୍ୟ asm_nullary_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token);
ST_FUNC ଶୂନ୍ୟ asm_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_parse_csrvar(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_parse_regvar(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ସ୍ଥିର ଶୂନ୍ୟ asm_ternary_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token);
ସ୍ଥିର ଶୂନ୍ୟ asm_unary_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token);
ସ୍ଥିର ଶୂନ୍ୟ asm_branch_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc);
ST_FUNC ଶୂନ୍ୟ gen_expr32(ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe);
ସ୍ଥିର ଶୂନ୍ୟ parse_operand(TCCState *s1, Operand *op);
ସ୍ଥିର ଶୂନ୍ୟ parse_branch_offset_operand(TCCState *s1, Operand *op);
ସ୍ଥିର ଶୂନ୍ୟ parse_operands(TCCState *s1, Operand *ops, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଗଣନା_3);
ସ୍ଥିର ଶୂନ୍ୟ parse_mem_access_operands(TCCState *s1, Operand* ops);
ST_FUNC ଶୂନ୍ୟ subst_asm_operand(CString *add_str, SValue *sv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା modifier);
/* C extension */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_ca(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs2);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_cb(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rs1, ଅଚଳ Operand *imm);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_ci(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *imm);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_ciw(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *imm);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_cj(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *imm);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_cl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs1, ଅଚଳ Operand *imm);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_cr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs2);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_cs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rs2, ଅଚଳ Operand *rs1, ଅଚଳ Operand *imm);
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_css(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rs2, ଅଚଳ Operand *imm);

/* XXX: make it faster ? */
ST_FUNC ଶୂନ୍ୟ g(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ind1;
    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ;
    ind1 = ind + 1;
    ଯଦି (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC ଶୂନ୍ୟ gen_le16 (ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
    g(i);
    g(i>>8);
}

ST_FUNC ଶୂନ୍ୟ gen_le32 (ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ind1;
    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ;
    ind1 = ind + 4;
    ଯଦି (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC ଶୂନ୍ୟ gen_expr32(ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe)
{
    gen_le32(pe->v);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_nullary_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    ବାଛ (token) {
    // Sync instructions

    ସ୍ଥିତି TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        ଫେରନ୍ତୁ;

    // System calls

    ସ୍ଥିତି TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        ଫେରନ୍ତୁ;

    // Other

    ସ୍ଥିତି TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        ଫେରନ୍ତୁ;

    /* Pseudoinstructions */
    ସ୍ଥିତି TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        ଫେରନ୍ତୁ;

    /* C extension */
    ସ୍ଥିତି TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        ଫେରନ୍ତୁ;

    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
ସ୍ଥିର ଶୂନ୍ୟ parse_operand(TCCState *s1, Operand *op)
{
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    ଯଦି ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        ଫେରନ୍ତୁ;
    } ଅନ୍ୟଥା ଯଦି (tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    } ଅନ୍ୟଥା ଯଦି ((e.v = asm_parse_csrvar(tok)) != -1) {
        next();
    } ଅନ୍ୟଥା {
        asm_ପଦସମଷ୍ଟି(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ଯଦି (!op->e.sym) {
        ଯଦି ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା) op->e.v >= -0x1000 && (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ଅନ୍ୟଥା ଯଦି (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        ଯଦି (op->e.sym->type.t & VT_STATIC)
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_PCREL_HI20, 0);
        ଅନ୍ୟଥା
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_GOT_HI20, 0);
        put_extern_sym(&label, cur_text_section, ind, 0);
        greloca(cur_text_section, &label, ind+4, R_RISCV_PCREL_LO12_I, 0);

        op->type = OP_IM12S;
        op->e.v = 0;
    } ଅନ୍ୟଥା {
        expect("operand");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ parse_branch_offset_operand(TCCState *s1, Operand *op){
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e = {0};

    asm_ପଦସମଷ୍ଟି(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ଯଦି (!op->e.sym) {
        ଯଦି ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା) op->e.v >= -0x1000 && (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ଅନ୍ୟଥା ଯଦି (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } ଅନ୍ୟଥା {
        expect("operand");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ parse_jump_offset_operand(TCCState *s1, Operand *op){
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e = {0};

    asm_ପଦସମଷ୍ଟି(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ଯଦି (!op->e.sym) {
        ଯଦି ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା) op->e.v >= -0x1000 && (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ଅନ୍ୟଥା ଯଦି (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_text_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } ଅନ୍ୟଥା {
        expect("operand");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ parse_operands(TCCState *s1, Operand* ops, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଗଣନା_3){
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = 0; i < ଗଣନା_3; i++) {
        ଯଦି ( i != 0 )
            skip(',');
        parse_operand(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
ସ୍ଥିର ଶୂନ୍ୟ parse_mem_access_operands(TCCState *s1, Operand* ops){

    Operand op;

    parse_operand(s1, &ops[0]);
    skip(',');
    ଯଦି ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } ଅନ୍ୟଥା {
        parse_operand(s1, &ops[2]);
        ଯଦି ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } ଅନ୍ୟଥା {
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
ସ୍ଥିର ଶୂନ୍ୟ asm_jal_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token){
    Operand ops[2];

    ଯଦି (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } ଅନ୍ୟଥା ଯଦି (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } ଅନ୍ୟଥା {
        // jal reg, offset
        parse_operand(s1, &ops[0]);
        ଯଦି ( tok == ',') next(); ଅନ୍ୟଥା expect("','");
    }
    parse_jump_offset_operand(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
ସ୍ଥିର ଶୂନ୍ୟ asm_jalr_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token){
    Operand ops[3];
    Operand op;

    parse_operand(s1, &ops[0]);
    ଯଦି ( tok == ',')
        next();
    ଅନ୍ୟଥା {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        ଫେରନ୍ତୁ;
    }

    ଯଦି ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } ଅନ୍ୟଥା {
        parse_operand(s1, &ops[2]);
        ଯଦି ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } ଅନ୍ୟଥା {
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


ସ୍ଥିର ଶୂନ୍ୟ asm_unary_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    Operand op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    ବାଛ (token) {
    /* pseudoinstructions */
    ସ୍ଥିତି TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_tail:
        /* auipc x6, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        ଫେରନ୍ତୁ;

    /* C extension */
    ସ୍ଥିତି TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        ଫେରନ୍ତୁ;

    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("unary instruction");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_emit_u(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand* rd, ଅଚଳ Operand* rs2)
{
    ଯଦି (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ଖାଲି));
    } ଅନ୍ୟଥା ଯଦି (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, ଖାଲି));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା parse_fence_operand(){
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = tok;
    ଯଦି ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    next();
    ଫେରନ୍ତୁ t - (TOK_ASM_w_fence - 1);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_fence_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା succ = 0xF, pred = 0xF;
    ଯଦି (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_operand();
        ଯଦି ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, ଖାଲି));
        }
        skip(',');
        succ = parse_fence_operand();
        ଯଦି ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, ଖାଲି));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_ଦ୍ୱିମିକ_opcode(TCCState* s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand imm = { OP_IM12S };
    Operand ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    ବାଛ (token) {
    ସ୍ଥିତି TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        ଫେରନ୍ତୁ;

    /* C extension */
    ସ୍ଥିତି TOK_ASM_c_add:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        ଫେରନ୍ତୁ;

#define CA (1 | (3 << 10) | (4 << 13))
    ସ୍ଥିତି TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        ଫେରନ୍ତୁ;
#undef CA

    ସ୍ଥିତି TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        ଫେରନ୍ତୁ;

    /* F/D extension */
    ସ୍ଥିତି TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        ଫେରନ୍ତୁ;

    /* pseudoinstructions */
    /* rd, sym */
    ସ୍ଥିତି TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_li:
        ଯଦି(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, ଖାଲି));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        ଯଦି(lo < 0){
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
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ଫେରନ୍ତୁ;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    ସ୍ଥିତି TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_text_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ଫେରନ୍ତୁ;

    /* CSR pseudo-instructions */
    ସ୍ଥିତି TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ଫେରନ୍ତୁ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_r(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand* rd, ଅଚଳ Operand* rs1, ଅଚଳ Operand* rs2)
{
    ଯଦି (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, ଖାଲି));
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
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_f(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand* rd, ଅଚଳ Operand* rs1, ଅଚଳ Operand* rs2)
{
    ଯଦି (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ଖାଲି));
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
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_fb(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand* rd, ଅଚଳ Operand* rs)
{
    ଯଦି (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, ଖାଲି));
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
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_fq(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand* rd, ଅଚଳ Operand* rs1, ଅଚଳ Operand* rs2, ଅଚଳ Operand* rs3)
{
    ଯଦି (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, ଖାଲି));
    }
    /* F-type instruction:
	     31...27 rs3
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (REG_ମୂଲ୍ୟ(rs3->reg) << 27));
}

/* caller: Add funct3 into opcode */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_i(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand* rd, ଅଚଳ Operand* rs1, ଅଚଳ Operand* rs2)
{
    ଯଦି (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ଖାଲି));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

ସ୍ଥିର ଶୂନ୍ୟ asm_emit_j(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand* rd, ଅଚଳ Operand* rs2)
{
    uint32_t imm;

    ଯଦି (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ଖାଲି));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    ଯଦି ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା)imm > (1 << 20) -1 || (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, ଖାଲି));
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

ସ୍ଥିର ଶୂନ୍ୟ asm_mem_access_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{

    Operand ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    ଯଦି (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    ବାଛ (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    ସ୍ଥିତି TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    ସ୍ଥିତି TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ଫେରନ୍ତୁ;
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_branch_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_offset_operand(s1, &ops[argc-1]);

    ବାଛ(token){
    /* branch (RS1, RS2, IMM); B-format */
    ସ୍ଥିତି TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    /* related pseudoinstructions */
    ସ୍ଥିତି TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        ଫେରନ୍ତୁ;
    /* shorter pseudoinstructions */
    ସ୍ଥିତି TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        ଫେରନ୍ତୁ;
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_ternary_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], 3);

    ବାଛ (token) {
    ସ୍ଥିତି TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ଫେରନ୍ତୁ;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    ସ୍ଥିତି TOK_ASM_add:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    ସ୍ଥିତି TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    ସ୍ଥିତି TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ଫେରନ୍ତୁ;

    /* M extension */
    ସ୍ଥିତି TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    ସ୍ଥିତି TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        ଫେରନ୍ତୁ;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    ସ୍ଥିତି TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;

    /* F/D extension */
    ସ୍ଥିତି TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ଫେରନ୍ତୁ;

    /* F/D comparison: produce integer result, encode manually */
    ସ୍ଥିତି TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ଫେରନ୍ତୁ;

    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("ternary instruction");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_quaternary_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[4];
    parse_operands(s1, &ops[0], 4);

    ବାଛ (token) {
    ସ୍ଥିତି TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ଫେରନ୍ତୁ;

    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("quaternary instruction");
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_atomic_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[3];

    parse_operand(s1, &ops[0]);
    skip(',');

    ଯଦି ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } ଅନ୍ୟଥା {
        parse_operand(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_operand(s1, &ops[2]);
    skip(')');

    ବାଛ(token){
        ସ୍ଥିତି TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ଭାଙ୍ଗ;

        ସ୍ଥିତି TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ଭାଙ୍ଗ;

        ସ୍ଥିତି TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ଭାଙ୍ଗ;

        ସ୍ଥିତି TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ଭାଙ୍ଗ;

        /* AMO instructions (base, aq=0 rl=0) */
        ସ୍ଥିତି TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ଭାଙ୍ଗ;

        /* AMO aq/rl variants */
        ସ୍ଥିତି TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;

        ସ୍ଥିତି TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ଭାଙ୍ଗ;
    }
}

/* caller: Add funct3 and func5 to opcode */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_a(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rd1, ଅଚଳ Operand *rs2, ଅଚଳ Operand *rs1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା aq, ପୂର୍ଣ୍ଣସଂଖ୍ୟା rl)
{
    ଯଦି (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, ଖାଲି));
    ଯଦି (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ଖାଲି));
    ଯଦି (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, ଖାଲି));
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
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_s(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand* rs1, ଅଚଳ Operand* rs2, ଅଚଳ Operand* imm)
{
    ଯଦି (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, ଖାଲି));
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

ସ୍ଥିର ଶୂନ୍ୟ asm_emit_b(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint32_t opcode, ଅଚଳ Operand *rs1, ଅଚଳ Operand *rs2, ଅଚଳ Operand *imm)
{
    uint32_t offset;

    ଯଦି (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }
    ଯଦି (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା b_ofs = ind;
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
        ଫେରନ୍ତୁ;
    }
    ଯଦି (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ଖାଲି));
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
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_fcvt_rm(TCCState *s1)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା rm = 7; /* dynamic */
    ଯଦି (tok == ',') {
        next();
        ବାଛ (tok) {
            ସ୍ଥିତି TOK_ASM_rne: rm = 0; next(); ଭାଙ୍ଗ;
            ସ୍ଥିତି TOK_ASM_rtz: rm = 1; next(); ଭାଙ୍ଗ;
            ସ୍ଥିତି TOK_ASM_rdn: rm = 2; next(); ଭାଙ୍ଗ;
            ସ୍ଥିତି TOK_ASM_rup: rm = 3; next(); ଭାଙ୍ଗ;
            ସ୍ଥିତି TOK_ASM_rmm: rm = 4; next(); ଭାଙ୍ଗ;
            ପୂର୍ବନିର୍ଦ୍ଧାରିତ: expect("rounding mode"); ଭାଙ୍ଗ;
        }
    }
    ଫେରନ୍ତୁ rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
ସ୍ଥିର ଶୂନ୍ୟ asm_fcvt_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    Operand ops[2];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା rm;
    uint32_t enc = 0;

    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);

    ବାଛ (token) {
        ସ୍ଥିତି TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ: expect("fcvt/fclass instruction"); ଫେରନ୍ତୁ;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC ଶୂନ୍ୟ asm_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା token)
{
    ବାଛ (token) {
    ସ୍ଥିତି TOK_ASM_ebreak:
    ସ୍ଥିତି TOK_ASM_ecall:
    ସ୍ଥିତି TOK_ASM_fence_i:
    ସ୍ଥିତି TOK_ASM_hrts:
    ସ୍ଥିତି TOK_ASM_mrth:
    ସ୍ଥିତି TOK_ASM_mrts:
    ସ୍ଥିତି TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_rdcycle:
    ସ୍ଥିତି TOK_ASM_rdcycleh:
    ସ୍ଥିତି TOK_ASM_rdtime:
    ସ୍ଥିତି TOK_ASM_rdtimeh:
    ସ୍ଥିତି TOK_ASM_rdinstret:
    ସ୍ଥିତି TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_lui:
    ସ୍ଥିତି TOK_ASM_auipc:
    ସ୍ଥିତି TOK_ASM_fsqrt_s:
    ସ୍ଥିତି TOK_ASM_fsqrt_d:
        asm_ଦ୍ୱିମିକ_opcode(s1, token);
        ଫେରନ୍ତୁ;

    /* fcvt/fclass — separate handler for optional rounding operand */
    ସ୍ଥିତି TOK_ASM_fcvt_w_s:
    ସ୍ଥିତି TOK_ASM_fcvt_wu_s:
    ସ୍ଥିତି TOK_ASM_fcvt_l_s:
    ସ୍ଥିତି TOK_ASM_fcvt_lu_s:
    ସ୍ଥିତି TOK_ASM_fcvt_s_w:
    ସ୍ଥିତି TOK_ASM_fcvt_s_wu:
    ସ୍ଥିତି TOK_ASM_fcvt_s_l:
    ସ୍ଥିତି TOK_ASM_fcvt_s_lu:
    ସ୍ଥିତି TOK_ASM_fcvt_w_d:
    ସ୍ଥିତି TOK_ASM_fcvt_wu_d:
    ସ୍ଥିତି TOK_ASM_fcvt_l_d:
    ସ୍ଥିତି TOK_ASM_fcvt_lu_d:
    ସ୍ଥିତି TOK_ASM_fcvt_d_w:
    ସ୍ଥିତି TOK_ASM_fcvt_d_wu:
    ସ୍ଥିତି TOK_ASM_fcvt_d_l:
    ସ୍ଥିତି TOK_ASM_fcvt_d_lu:
    ସ୍ଥିତି TOK_ASM_fcvt_s_d:
    ସ୍ଥିତି TOK_ASM_fcvt_d_s:
    ସ୍ଥିତି TOK_ASM_fclass_s:
    ସ୍ଥିତି TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_lb:
    ସ୍ଥିତି TOK_ASM_lh:
    ସ୍ଥିତି TOK_ASM_lw:
    ସ୍ଥିତି TOK_ASM_ld:
    ସ୍ଥିତି TOK_ASM_fld:
    ସ୍ଥିତି TOK_ASM_lbu:
    ସ୍ଥିତି TOK_ASM_lhu:
    ସ୍ଥିତି TOK_ASM_lwu:
    ସ୍ଥିତି TOK_ASM_sb:
    ସ୍ଥିତି TOK_ASM_sh:
    ସ୍ଥିତି TOK_ASM_sw:
    ସ୍ଥିତି TOK_ASM_sd:
    ସ୍ଥିତି TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        ଭାଙ୍ଗ;

    ସ୍ଥିତି TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        ଭାଙ୍ଗ;

    ସ୍ଥିତି TOK_ASM_add:
    ସ୍ଥିତି TOK_ASM_addi:
    ସ୍ଥିତି TOK_ASM_addiw:
    ସ୍ଥିତି TOK_ASM_addw:
    ସ୍ଥିତି TOK_ASM_and:
    ସ୍ଥିତି TOK_ASM_andi:
    ସ୍ଥିତି TOK_ASM_or:
    ସ୍ଥିତି TOK_ASM_ori:
    ସ୍ଥିତି TOK_ASM_sll:
    ସ୍ଥିତି TOK_ASM_slli:
    ସ୍ଥିତି TOK_ASM_slliw:
    ସ୍ଥିତି TOK_ASM_sllw:
    ସ୍ଥିତି TOK_ASM_slt:
    ସ୍ଥିତି TOK_ASM_slti:
    ସ୍ଥିତି TOK_ASM_sltiu:
    ସ୍ଥିତି TOK_ASM_sltu:
    ସ୍ଥିତି TOK_ASM_sra:
    ସ୍ଥିତି TOK_ASM_srai:
    ସ୍ଥିତି TOK_ASM_sraiw:
    ସ୍ଥିତି TOK_ASM_sraw:
    ସ୍ଥିତି TOK_ASM_srl:
    ସ୍ଥିତି TOK_ASM_srli:
    ସ୍ଥିତି TOK_ASM_srliw:
    ସ୍ଥିତି TOK_ASM_srlw:
    ସ୍ଥିତି TOK_ASM_sub:
    ସ୍ଥିତି TOK_ASM_subw:
    ସ୍ଥିତି TOK_ASM_xor:
    ସ୍ଥିତି TOK_ASM_xori:
    /* M extension */
    ସ୍ଥିତି TOK_ASM_div:
    ସ୍ଥିତି TOK_ASM_divu:
    ସ୍ଥିତି TOK_ASM_divuw:
    ସ୍ଥିତି TOK_ASM_divw:
    ସ୍ଥିତି TOK_ASM_mul:
    ସ୍ଥିତି TOK_ASM_mulh:
    ସ୍ଥିତି TOK_ASM_mulhsu:
    ସ୍ଥିତି TOK_ASM_mulhu:
    ସ୍ଥିତି TOK_ASM_mulw:
    ସ୍ଥିତି TOK_ASM_rem:
    ସ୍ଥିତି TOK_ASM_remu:
    ସ୍ଥିତି TOK_ASM_remuw:
    ସ୍ଥିତି TOK_ASM_remw:
    /* Zicsr extension */
    ସ୍ଥିତି TOK_ASM_csrrc:
    ସ୍ଥିତି TOK_ASM_csrrci:
    ସ୍ଥିତି TOK_ASM_csrrs:
    ସ୍ଥିତି TOK_ASM_csrrsi:
    ସ୍ଥିତି TOK_ASM_csrrw:
    ସ୍ଥିତି TOK_ASM_csrrwi:
    /* F/D extension */
    ସ୍ଥିତି TOK_ASM_fadd_s:
    ସ୍ଥିତି TOK_ASM_fadd_d:
    ସ୍ଥିତି TOK_ASM_fsub_s:
    ସ୍ଥିତି TOK_ASM_fsub_d:
    ସ୍ଥିତି TOK_ASM_fmul_s:
    ସ୍ଥିତି TOK_ASM_fmul_d:
    ସ୍ଥିତି TOK_ASM_fdiv_s:
    ସ୍ଥିତି TOK_ASM_fdiv_d:
    ସ୍ଥିତି TOK_ASM_fsgnj_d:
    ସ୍ଥିତି TOK_ASM_fsgnj_s:
    ସ୍ଥିତି TOK_ASM_fmax_s:
    ସ୍ଥିତି TOK_ASM_fmax_d:
    ସ୍ଥିତି TOK_ASM_fmin_s:
    ସ୍ଥିତି TOK_ASM_fmin_d:
    ସ୍ଥିତି TOK_ASM_feq_s:
    ସ୍ଥିତି TOK_ASM_feq_d:
    ସ୍ଥିତି TOK_ASM_flt_s:
    ସ୍ଥିତି TOK_ASM_flt_d:
    ସ୍ଥିତି TOK_ASM_fle_s:
    ସ୍ଥିତି TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_fmadd_d:
    ସ୍ଥିତି TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        ଫେରନ୍ତୁ;

    /* Branches */
    ସ୍ଥିତି TOK_ASM_beq:
    ସ୍ଥିତି TOK_ASM_bge:
    ସ୍ଥିତି TOK_ASM_bgeu:
    ସ୍ଥିତି TOK_ASM_blt:
    ସ୍ଥିତି TOK_ASM_bltu:
    ସ୍ଥିତି TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        ଭାଙ୍ଗ;

    /* C extension */
    ସ୍ଥିତି TOK_ASM_c_ebreak:
    ସ୍ଥିତି TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_c_j:
    ସ୍ଥିତି TOK_ASM_c_jal:
    ସ୍ଥିତି TOK_ASM_c_jalr:
    ସ୍ଥିତି TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_c_add:
    ସ୍ଥିତି TOK_ASM_c_addi16sp:
    ସ୍ଥିତି TOK_ASM_c_addi4spn:
    ସ୍ଥିତି TOK_ASM_c_addi:
    ସ୍ଥିତି TOK_ASM_c_addiw:
    ସ୍ଥିତି TOK_ASM_c_addw:
    ସ୍ଥିତି TOK_ASM_c_and:
    ସ୍ଥିତି TOK_ASM_c_andi:
    ସ୍ଥିତି TOK_ASM_c_beqz:
    ସ୍ଥିତି TOK_ASM_c_bnez:
    ସ୍ଥିତି TOK_ASM_c_fldsp:
    ସ୍ଥିତି TOK_ASM_c_flwsp:
    ସ୍ଥିତି TOK_ASM_c_fsdsp:
    ସ୍ଥିତି TOK_ASM_c_fswsp:
    ସ୍ଥିତି TOK_ASM_c_ldsp:
    ସ୍ଥିତି TOK_ASM_c_li:
    ସ୍ଥିତି TOK_ASM_c_lui:
    ସ୍ଥିତି TOK_ASM_c_lwsp:
    ସ୍ଥିତି TOK_ASM_c_mv:
    ସ୍ଥିତି TOK_ASM_c_or:
    ସ୍ଥିତି TOK_ASM_c_sdsp:
    ସ୍ଥିତି TOK_ASM_c_slli:
    ସ୍ଥିତି TOK_ASM_c_srai:
    ସ୍ଥିତି TOK_ASM_c_srli:
    ସ୍ଥିତି TOK_ASM_c_sub:
    ସ୍ଥିତି TOK_ASM_c_subw:
    ସ୍ଥିତି TOK_ASM_c_swsp:
    ସ୍ଥିତି TOK_ASM_c_xor:
        asm_ଦ୍ୱିମିକ_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_c_fld:
    ସ୍ଥିତି TOK_ASM_c_flw:
    ସ୍ଥିତି TOK_ASM_c_fsd:
    ସ୍ଥିତି TOK_ASM_c_fsw:
    ସ୍ଥିତି TOK_ASM_c_ld:
    ସ୍ଥିତି TOK_ASM_c_lw:
    ସ୍ଥିତି TOK_ASM_c_sd:
    ସ୍ଥିତି TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        ଫେରନ୍ତୁ;

    /* pseudoinstructions */
    ସ୍ଥିତି TOK_ASM_nop:
    ସ୍ଥିତି TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_jr:
    ସ୍ଥିତି TOK_ASM_call:
    ସ୍ଥିତି TOK_ASM_tail:
    ସ୍ଥିତି TOK_ASM_frflags:
    ସ୍ଥିତି TOK_ASM_frrm:
    ସ୍ଥିତି TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_la:
    ସ୍ଥିତି TOK_ASM_lla:
    ସ୍ଥିତି TOK_ASM_li:
    ସ୍ଥିତି TOK_ASM_jump:
    ସ୍ଥିତି TOK_ASM_seqz:
    ସ୍ଥିତି TOK_ASM_snez:
    ସ୍ଥିତି TOK_ASM_sltz:
    ସ୍ଥିତି TOK_ASM_sgtz:
    ସ୍ଥିତି TOK_ASM_mv:
    ସ୍ଥିତି TOK_ASM_not:
    ସ୍ଥିତି TOK_ASM_neg:
    ସ୍ଥିତି TOK_ASM_negw:
    ସ୍ଥିତି TOK_ASM_sext_w:
    ସ୍ଥିତି TOK_ASM_fabs_s:
    ସ୍ଥିତି TOK_ASM_fabs_d:
    ସ୍ଥିତି TOK_ASM_fmv_s:
    ସ୍ଥିତି TOK_ASM_fmv_d:
    ସ୍ଥିତି TOK_ASM_fneg_s:
    ସ୍ଥିତି TOK_ASM_fneg_d:
    ସ୍ଥିତି TOK_ASM_csrc:
    ସ୍ଥିତି TOK_ASM_csrs:
    ସ୍ଥିତି TOK_ASM_csrr:
    ସ୍ଥିତି TOK_ASM_csrw:
    ସ୍ଥିତି TOK_ASM_csrwi:
    ସ୍ଥିତି TOK_ASM_csrsi:
    ସ୍ଥିତି TOK_ASM_csrci:
    ସ୍ଥିତି TOK_ASM_fsrm:
    ସ୍ଥିତି TOK_ASM_fscsr:
        asm_ଦ୍ୱିମିକ_opcode(s1, token);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_bnez:
    ସ୍ଥିତି TOK_ASM_beqz:
    ସ୍ଥିତି TOK_ASM_blez:
    ସ୍ଥିତି TOK_ASM_bgez:
    ସ୍ଥିତି TOK_ASM_bltz:
    ସ୍ଥିତି TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        ଫେରନ୍ତୁ;

    ସ୍ଥିତି TOK_ASM_bgt:
    ସ୍ଥିତି TOK_ASM_bgtu:
    ସ୍ଥିତି TOK_ASM_ble:
    ସ୍ଥିତି TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        ଫେରନ୍ତୁ;

    /* Atomic operations */
    ସ୍ଥିତି TOK_ASM_lr_w:
    ସ୍ଥିତି TOK_ASM_lr_w_aq:
    ସ୍ଥିତି TOK_ASM_lr_w_rl:
    ସ୍ଥିତି TOK_ASM_lr_w_aqrl:
    ସ୍ଥିତି TOK_ASM_lr_d:
    ସ୍ଥିତି TOK_ASM_lr_d_aq:
    ସ୍ଥିତି TOK_ASM_lr_d_rl:
    ସ୍ଥିତି TOK_ASM_lr_d_aqrl:
    ସ୍ଥିତି TOK_ASM_sc_w:
    ସ୍ଥିତି TOK_ASM_sc_w_aq:
    ସ୍ଥିତି TOK_ASM_sc_w_rl:
    ସ୍ଥିତି TOK_ASM_sc_w_aqrl:
    ସ୍ଥିତି TOK_ASM_sc_d:
    ସ୍ଥିତି TOK_ASM_sc_d_aq:
    ସ୍ଥିତି TOK_ASM_sc_d_rl:
    ସ୍ଥିତି TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    ସ୍ଥିତି TOK_ASM_amoadd_w:
    ସ୍ଥିତି TOK_ASM_amoadd_d:
    ସ୍ଥିତି TOK_ASM_amoswap_w:
    ସ୍ଥିତି TOK_ASM_amoswap_d:
    ସ୍ଥିତି TOK_ASM_amoand_w:
    ସ୍ଥିତି TOK_ASM_amoand_d:
    ସ୍ଥିତି TOK_ASM_amoor_w:
    ସ୍ଥିତି TOK_ASM_amoor_d:
    ସ୍ଥିତି TOK_ASM_amoxor_w:
    ସ୍ଥିତି TOK_ASM_amoxor_d:
    ସ୍ଥିତି TOK_ASM_amomax_w:
    ସ୍ଥିତି TOK_ASM_amomax_d:
    ସ୍ଥିତି TOK_ASM_amomaxu_w:
    ସ୍ଥିତି TOK_ASM_amomaxu_d:
    ସ୍ଥିତି TOK_ASM_amomin_w:
    ସ୍ଥିତି TOK_ASM_amomin_d:
    ସ୍ଥିତି TOK_ASM_amominu_w:
    ସ୍ଥିତି TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    ସ୍ଥିତି TOK_ASM_amoadd_w_aq:
    ସ୍ଥିତି TOK_ASM_amoadd_w_rl:
    ସ୍ଥିତି TOK_ASM_amoadd_w_aqrl:
    ସ୍ଥିତି TOK_ASM_amoadd_d_aq:
    ସ୍ଥିତି TOK_ASM_amoadd_d_rl:
    ସ୍ଥିତି TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    ସ୍ଥିତି TOK_ASM_amoswap_w_aq:
    ସ୍ଥିତି TOK_ASM_amoswap_w_rl:
    ସ୍ଥିତି TOK_ASM_amoswap_w_aqrl:
    ସ୍ଥିତି TOK_ASM_amoswap_d_aq:
    ସ୍ଥିତି TOK_ASM_amoswap_d_rl:
    ସ୍ଥିତି TOK_ASM_amoswap_d_aqrl:
    ସ୍ଥିତି TOK_ASM_amoand_w_aq:
    ସ୍ଥିତି TOK_ASM_amoand_w_rl:
    ସ୍ଥିତି TOK_ASM_amoand_w_aqrl:
    ସ୍ଥିତି TOK_ASM_amoand_d_aq:
    ସ୍ଥିତି TOK_ASM_amoand_d_rl:
    ସ୍ଥିତି TOK_ASM_amoand_d_aqrl:
    ସ୍ଥିତି TOK_ASM_amoor_w_aq:
    ସ୍ଥିତି TOK_ASM_amoor_w_rl:
    ସ୍ଥିତି TOK_ASM_amoor_w_aqrl:
    ସ୍ଥିତି TOK_ASM_amoor_d_aq:
    ସ୍ଥିତି TOK_ASM_amoor_d_rl:
    ସ୍ଥିତି TOK_ASM_amoor_d_aqrl:
    ସ୍ଥିତି TOK_ASM_amoxor_w_aq:
    ସ୍ଥିତି TOK_ASM_amoxor_w_rl:
    ସ୍ଥିତି TOK_ASM_amoxor_w_aqrl:
    ସ୍ଥିତି TOK_ASM_amoxor_d_aq:
    ସ୍ଥିତି TOK_ASM_amoxor_d_rl:
    ସ୍ଥିତି TOK_ASM_amoxor_d_aqrl:
    ସ୍ଥିତି TOK_ASM_amomax_w_aq:
    ସ୍ଥିତି TOK_ASM_amomax_w_rl:
    ସ୍ଥିତି TOK_ASM_amomax_w_aqrl:
    ସ୍ଥିତି TOK_ASM_amomax_d_aq:
    ସ୍ଥିତି TOK_ASM_amomax_d_rl:
    ସ୍ଥିତି TOK_ASM_amomax_d_aqrl:
    ସ୍ଥିତି TOK_ASM_amomaxu_w_aq:
    ସ୍ଥିତି TOK_ASM_amomaxu_w_rl:
    ସ୍ଥିତି TOK_ASM_amomaxu_w_aqrl:
    ସ୍ଥିତି TOK_ASM_amomaxu_d_aq:
    ସ୍ଥିତି TOK_ASM_amomaxu_d_rl:
    ସ୍ଥିତି TOK_ASM_amomaxu_d_aqrl:
    ସ୍ଥିତି TOK_ASM_amomin_w_aq:
    ସ୍ଥିତି TOK_ASM_amomin_w_rl:
    ସ୍ଥିତି TOK_ASM_amomin_w_aqrl:
    ସ୍ଥିତି TOK_ASM_amomin_d_aq:
    ସ୍ଥିତି TOK_ASM_amomin_d_rl:
    ସ୍ଥିତି TOK_ASM_amomin_d_aqrl:
    ସ୍ଥିତି TOK_ASM_amominu_w_aq:
    ସ୍ଥିତି TOK_ASM_amominu_w_rl:
    ସ୍ଥିତି TOK_ASM_amominu_w_aqrl:
    ସ୍ଥିତି TOK_ASM_amominu_d_aq:
    ସ୍ଥିତି TOK_ASM_amominu_d_rl:
    ସ୍ଥିତି TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        ଭାଙ୍ଗ;

    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("known instruction");
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_parse_csrvar(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ବାଛ (t) {
    ସ୍ଥିତି TOK_ASM_cycle:
        ଫେରନ୍ତୁ 0xc00;
    ସ୍ଥିତି TOK_ASM_fcsr:
        ଫେରନ୍ତୁ 3;
    ସ୍ଥିତି TOK_ASM_fflags:
        ଫେରନ୍ତୁ 1;
    ସ୍ଥିତି TOK_ASM_frm:
        ଫେରନ୍ତୁ 2;
    ସ୍ଥିତି TOK_ASM_instret:
        ଫେରନ୍ତୁ 0xc02;
    ସ୍ଥିତି TOK_ASM_time:
        ଫେରନ୍ତୁ 0xc01;
    ସ୍ଥିତି TOK_ASM_cycleh:
        ଫେରନ୍ତୁ 0xc80;
    ସ୍ଥିତି TOK_ASM_instreth:
        ଫେରନ୍ତୁ 0xc82;
    ସ୍ଥିତି TOK_ASM_timeh:
        ଫେରନ୍ତୁ 0xc81;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ଫେରନ୍ତୁ -1;
    }
}

ST_FUNC ଶୂନ୍ୟ subst_asm_operand(CString *add_str, SValue *sv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା modifier)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, reg, val;

    r = sv->r;
    ଯଦି ((r & VT_VALMASK) == VT_CONST) {
        ଯଦି (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        ଯଦି (r & VT_SYM) {
            ଅଚଳ ଅକ୍ଷର *name = get_tok_str(sv->sym->v, ଖାଲି);
            ଯଦି (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            ଯଦି (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            ଯଦି ((uint32_t) sv->c.i == 0)
                ଯାଅ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        ଯଦି (modifier == 'n')
            val = -val;
        ଯଦି (modifier == 'z' && val == 0) {
            cstr_cat(add_str, "zero", -1);
        } ଅନ୍ୟଥା {
            cstr_printf(add_str, "%d", val);
        }
      no_offset:;
    } ଅନ୍ୟଥା ଯଦି ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) sv->c.i);
    } ଅନ୍ୟଥା ଯଦି (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ଯଦି (reg >= VT_CONST)
            tcc_internal_error("");
        ଯଦି ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_ମୂଲ୍ୟ(reg);
        } ଅନ୍ୟଥା {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, ଖାଲି), -1);
    } ଅନ୍ୟଥା {
        /* register case */
        reg = r & VT_VALMASK;
        ଯଦି (reg >= VT_CONST)
            tcc_internal_error("");
        ଯଦି ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_ମୂଲ୍ୟ(reg);
        } ଅନ୍ୟଥା {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, ଖାଲି), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_ireg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r){
    ଫେରନ୍ତୁ REG_ମୂଲ୍ୟ(r) - 10;
}
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_freg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r){
    ଫେରନ୍ତୁ REG_ମୂଲ୍ୟ(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ଶୂନ୍ୟ asm_gen_code(ASMOperand *operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands,
                         ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_outputs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_output,
                         uint8_t *clobber_regs,
                         ପୂର୍ଣ୍ଣସଂଖ୍ୟା out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, reg;

    ସ୍ଥିର ଅଚଳ uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, ଆକାର(regs_allocated));
    ପାଇଁ(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ଯଦି (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    ଯଦି(!is_output) {
        /* generate reg save code */
        ପାଇଁ(i = 0; i < ଆକାର(reg_saved)/ଆକାର(reg_saved[0]); i++) {
            reg = reg_saved[i];
            ଯଦି (regs_allocated[reg]) {
                /*ଠେଲ*/
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (unsigned)-8 << 20);
                ଯଦି (REG_IS_FLOAT(reg)){
                    /* fsd reg, offset(sp) */
                    gen_le32( 0x27 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                } ଅନ୍ୟଥା {
                    /* sd reg, offset(sp) */
                    gen_le32((0x8 << 2) | 3 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                }
            }
        }

        /* generate load code */
        ପାଇଁ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ଯଦି (op->reg >= 0) {
                ଯଦି ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(tcc_ireg(op->reg), &sv);
                } ଅନ୍ୟଥା ଯଦି (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    ଯଦି ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        load(tcc_freg(op->reg), op->vt);
                    } ଅନ୍ୟଥା {
                        load(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register;
                       the load/store above already handles it correctly */
                }
            }
        }
    } ଅନ୍ୟଥା {
        /* generate save code */
        ପାଇଁ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ଯଦି (op->reg >= 0) {
                ଯଦି ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ଯଦି (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(tcc_ireg(out_reg), &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(tcc_ireg(op->reg), &sv);
                    }
                } ଅନ୍ୟଥା {
                    ଯଦି ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        store(tcc_freg(op->reg), op->vt);
                    } ଅନ୍ୟଥା {
                        store(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register */
                }
            }
        }
        /* generate reg restore code for floating point registers */
        ପାଇଁ(i = ଆକାର(reg_saved)/ଆକାର(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            ଯଦି (regs_allocated[reg]) {
                /*କାଢ଼*/
                ଯଦି (REG_IS_FLOAT(reg)){
                    /* fld reg, offset(sp) */
                    gen_le32(7 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                } ଅନ୍ୟଥା {
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
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା constraint_priority(ଅଚଳ ଅକ୍ଷର *str)
{
    // TODO: How is this chosen??
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    ପାଇଁ(;;) {
        c = *str;
        ଯଦି (c == '\0')
            ଭାଙ୍ଗ;
        str++;
        ବାଛ(c) {
        ସ୍ଥିତି 'A': // address that is held in a general-purpose register.
        ସ୍ଥିତି 'S': // constraint that matches an absolute symbolic address.
        ସ୍ଥିତି 'f': // register [float]
        ସ୍ଥିତି 'r': // register [general]
        ସ୍ଥିତି 'p': // valid memory address for load,store [general]
            pr = 3;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'I': // 12 bit signed immedate
        ସ୍ଥିତି 'i': // immediate integer operand, including symbolic constants [general]
        ସ୍ଥିତି 'm': // memory operand [general]
        ସ୍ଥିତି 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'v':
            tcc_error("unimp: constraint '%c'", c);
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            tcc_error("unknown constraint '%d'", c);
        }
        ଯଦି (pr > priority)
            priority = pr;
    }
    ଫେରନ୍ତୁ priority;
}

ସ୍ଥିର ଅଚଳ ଅକ୍ଷର *skip_constraint_modifiers(ଅଚଳ ଅକ୍ଷର *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ଯେତେବେଳେ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ଫେରନ୍ତୁ p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC ଶୂନ୍ୟ asm_compute_constraints(ASMOperand *operands,
                                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_outputs,
                                    ଅଚଳ uint8_t *clobber_regs,
                                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pout_reg)
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
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sorted_op[MAX_ASM_OPERANDS];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ଅଚଳ ଅକ୍ଷର *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ପାଇଁ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ନିବେଶ_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ପାଇଁ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ଯଦି (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, ଖାଲି);
            ଯଦି ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            ଯଦି (operands[k].ନିବେଶ_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ନିବେଶ_index = i;
            op->priority = 5;
        } ଅନ୍ୟଥା ଯଦି ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } ଅନ୍ୟଥା {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    ପାଇଁ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ପାଇଁ (i = 0; i < nb_operands - 1; i++) {
        ପାଇଁ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            ଯଦି (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ପାଇଁ (i = 0; i < NB_ASM_REGS; i++) {
        ଯଦି (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        ଅନ୍ୟଥା
            regs_allocated[i] = 0;
    }

    /* allocate registers and generate corresponding asm moves */
    ପାଇଁ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ଯଦି (op->ref_index >= 0)
            ଜାରି;
        /* select if register is used for output, input or both */
        ଯଦି (op->ନିବେଶ_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } ଅନ୍ୟଥା ଯଦି (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } ଅନ୍ୟଥା {
            reg_mask = REG_IN_MASK;
        }
        ଯଦି (op->reg >= 0) {
            ଯଦି (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        ବାଛ (c) {
        ସ୍ଥିତି '=': // Operand is written-to
            ଯାଅ try_next;
        ସ୍ଥିତି '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        ସ୍ଥିତି '&': // Operand is clobbered before the instruction is done using the input operands
            ଯଦି (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            ଯାଅ try_next;
        ସ୍ଥିତି 'r': // general-purpose register
        ସ୍ଥିତି 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            ଯଦି ((reg = op->reg) >= 0)
                ଯାଅ reg_found;
            ଅନ୍ୟଥା ପାଇଁ (reg = 10; reg <= 18; reg++) {
                ଯଦି (!is_reg_allocated(reg))
                    ଯାଅ reg_found;
            }
            ଯାଅ try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            ଯଦି ((reg = op->reg) >= 0)
                ଯାଅ reg_found;
            ଅନ୍ୟଥା ପାଇଁ (reg = 42; reg <= 50; reg++) {
                ଯଦି (!is_reg_allocated(reg))
                    ଯାଅ reg_found;
            }
            ଯାଅ try_next;
        ସ୍ଥିତି 'I': // I-Type 12 bit signed immediate
        ସ୍ଥିତି 'i': // immediate integer operand, including symbolic constants
            ଯଦି (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ଯାଅ try_next;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'm': // memory operand
        ସ୍ଥିତି 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ଯଦି (j < nb_outputs || c == 'm') {
                ଯଦି ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    ପାଇଁ (reg = 10; reg <= 18; reg++) {
                        ଯଦି (!(regs_allocated[reg] & REG_IN_MASK))
                            ଯାଅ reg_found1;
                    }
                    ଯାଅ try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ଭାଙ୍ଗ;
        }
        /* if a reference is present for that operand, we assign it too */
        ଯଦି (op->ନିବେଶ_index >= 0) {
            operands[op->ନିବେଶ_index].reg = op->reg;
            operands[op->ନିବେଶ_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ପାଇଁ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ଯଦି (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            ଯଦି (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                ପାଇଁ (reg = 42; reg <= 50; reg++) {
                    ଯଦି (!(regs_allocated[reg] & REG_OUT_MASK))
                        ଯାଅ reg_found2;
                }
            } ଅନ୍ୟଥା {
                /* From a0 to a7 */
                ପାଇଁ (reg = 10; reg <= 18; reg++) {
                    ଯଦି (!(regs_allocated[reg] & REG_OUT_MASK))
                        ଯାଅ reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ଭାଙ୍ଗ;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    ପାଇଁ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ଖାଲି) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ଯଦି (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC ଶୂନ୍ୟ asm_clobber(uint8_t *clobber_regs, ଅଚଳ ଅକ୍ଷର *str)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା reg;
    TokenSym *ts;

    ଯଦି (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ଫେରନ୍ତୁ;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    ଯଦି (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_parse_regvar (ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    /* PC register not implemented */
    ଯଦି (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        ଫେରନ୍ତୁ -1;

    ଯଦି (t < TOK_ASM_f0)
        ଫେରନ୍ତୁ t - TOK_ASM_x0;

    ଯଦି (t < TOK_ASM_zero)
        ଫେରନ୍ତୁ t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    ଯଦି (t < TOK_ASM_ft0)
        ଫେରନ୍ତୁ t - TOK_ASM_zero;

    ଫେରନ୍ତୁ t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_ca(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs2)
{
    uint8_t dst, src;

    ଯଦି (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ଖାଲି));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    ଯଦି (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ଖାଲି));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

ସ୍ଥିର ଶୂନ୍ୟ asm_emit_cb(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rs1, ଅଚଳ Operand *imm)
{
    uint32_t offset;
    uint8_t src;

    ଯଦି (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ଖାଲି));
    }

    offset = imm->e.v;

    ଯଦି (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ଖାଲି));
    }

    src = rs1->reg - 8;

    ଯଦି (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ଖାଲି));
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

    ବାଛ (token) {
    ସ୍ଥିତି TOK_ASM_c_beqz:
    ସ୍ଥିତି TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_BIT(offset, 5) | (((offset >> 1) & 3) << 1) | (((offset >> 6) & 3) << 3)) << 2) | ((((offset >> 3) & 3) | NTH_BIT(offset, 8)) << 10));
        ଫେରନ୍ତୁ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((offset & 0x1f) << 2) | (NTH_BIT(offset, 5) << 12));
        ଫେରନ୍ତୁ;
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_emit_ci(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *imm)
{
    uint32_t immediate;

    ଯଦି (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ଖାଲି));
    }

    immediate = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    ବାଛ (token) {
    ସ୍ଥିତି TOK_ASM_c_addi:
    ସ୍ଥିତି TOK_ASM_c_addiw:
    ସ୍ଥିତି TOK_ASM_c_li:
    ସ୍ଥିତି TOK_ASM_c_slli:
        gen_le16(opcode | ((immediate & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_BIT(immediate, 5) << 2 | (((immediate >> 7) & 3) << 3) | NTH_BIT(immediate, 6) << 5 | NTH_BIT(immediate, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 9) << 12));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_lui:
        gen_le16(opcode | (((immediate >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 17) << 12));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_fldsp:
    ସ୍ଥିତି TOK_ASM_c_ldsp:
        gen_le16(opcode | (((immediate >> 6) & 7) << 2) | (((immediate >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_flwsp:
    ସ୍ଥିତି TOK_ASM_c_lwsp:
        gen_le16(opcode | (((immediate >> 6) & 3) << 2) | (((immediate >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ଫେରନ୍ତୁ;
    ସ୍ଥିତି TOK_ASM_c_nop:
        gen_le16(opcode);
        ଫେରନ୍ତୁ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_ciw(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    ଯଦି (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ଖାଲି));
    }

    dst = rd->reg - 8;

    ଯଦି (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ଖାଲି));
    }

    nzuimm = imm->e.v;

    ଯଦି (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, ଖାଲି));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_BIT(nzuimm, 3) | (NTH_BIT(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_cj(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *imm)
{
    uint32_t offset;

    /* +-2 KiB range */
    ଯଦି (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, ଖାଲି));
    }

    offset = imm->e.v;

    ଯଦି (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ଖାଲି));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_BIT(offset, 5) << 2) | (((offset >> 1) & 7) << 3) | (NTH_BIT(offset, 7) << 6) | (NTH_BIT(offset, 6) << 7) | (NTH_BIT(offset, 10) << 8) | (((offset >> 8) & 3) << 9) | (NTH_BIT(offset, 4) << 11) | (NTH_BIT(offset, 11) << 12));
}

/* caller: Add funct3 into opcode */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_cl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs1, ଅଚଳ Operand *imm)
{
    uint32_t offset;
    uint8_t dst, src;

    ଯଦି (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ଖାଲି));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    ଯଦି (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ଖାଲି));
    }

    offset = imm->e.v;

    ଯଦି (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ଖାଲି));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    ବାଛ (token) {
    /* imm variant 1 */
    ସ୍ଥିତି TOK_ASM_c_flw:
    ସ୍ଥିତି TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        ଫେରନ୍ତୁ;
    /* imm variant 2 */
    ସ୍ଥିତି TOK_ASM_c_fld:
    ସ୍ଥିତି TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        ଫେରନ୍ତୁ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_cr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rd, ଅଚଳ Operand *rs2)
{
    ଯଦି (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ଖାଲି));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_cs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rs2, ଅଚଳ Operand *rs1, ଅଚଳ Operand *imm)
{
    uint32_t offset;
    uint8_t base, src;

    ଯଦି (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ଖାଲି));
    }

    base = rs1->reg - 8;
    src = rs2->reg - 8;

    ଯଦି (base > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ଖାଲି));
    }

    offset = imm->e.v;

    ଯଦି (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ଖାଲି));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    ବାଛ (token) {
    /* imm variant 1 */
    ସ୍ଥିତି TOK_ASM_c_fsw:
    ସ୍ଥିତି TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        ଫେରନ୍ତୁ;
    /* imm variant 2 */
    ସ୍ଥିତି TOK_ASM_c_fsd:
    ସ୍ଥିତି TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        ଫେରନ୍ତୁ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
ସ୍ଥିର ଶୂନ୍ୟ asm_emit_css(ପୂର୍ଣ୍ଣସଂଖ୍ୟା token, uint16_t opcode, ଅଚଳ Operand *rs2, ଅଚଳ Operand *imm)
{
    uint32_t offset;

    ଯଦି (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ଖାଲି));
    }

    offset = imm->e.v;

    ଯଦି (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ଖାଲି));
    }

    ଯଦି (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ଖାଲି));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    ବାଛ (token) {
    /* imm variant 1 */
    ସ୍ଥିତି TOK_ASM_c_fswsp:
    ସ୍ଥିତି TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 3) << 7) | (((offset >> 2) & 0xf) << 9));
        ଫେରନ୍ତୁ;
    /* imm variant 2 */
    ସ୍ଥିତି TOK_ASM_c_fsdsp:
    ସ୍ଥିତି TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 7) << 7) | (((offset >> 3) & 7) << 10));
        ଫେରନ୍ତୁ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        expect("known instruction");
    }
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
