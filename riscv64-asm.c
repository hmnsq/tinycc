/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#ifdef TARGET_DEFS_ONLY

#define CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#define NB_ASM_REGS 64

ST_FUNC void g(ຈຳນວນເຕັມ c);
ST_FUNC void gen_le16(ຈຳນວນເຕັມ c);
ST_FUNC void gen_le32(ຈຳນວນເຕັມ c);

/*************************************************************/
#ບໍ່ດັ່ງນັ້ນ
/*************************************************************/
#define USING_GLOBALS
#include "tcc.h"

ga_nanaa {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#define REG_FLOAT_MASK 0x20
#define REG_IS_FLOAT(register_index) ((register_index) & REG_FLOAT_MASK)
#define REG_VALUE(register_index)    ((register_index) & (REG_FLOAT_MASK-1))
#define C_ENCODE_RS1(register_index) (REG_VALUE(register_index) << 7)
#define C_ENCODE_RS2(register_index) (REG_VALUE(register_index) << 2)
#define ENCODE_RD(register_index)  (REG_VALUE(register_index) << 7)
#define ENCODE_RS1(register_index) (REG_VALUE(register_index) << 15)
#define ENCODE_RS2(register_index) (REG_VALUE(register_index) << 20)
#define NTH_BIT(b, n) ((b >> n) & 1)
#define OP_IM12S (1 << OPT_IM12S)
#define OP_IM32 (1 << OPT_IM32)
#define OP_REG (1 << OPT_REG)

typedef sa_nracanaa Operand {
    uint32_t type;
    sa_ngha {
        uint8_t reg;
        uint16_t regset;
        ExprValue e;
    };
} Operand;

static const Operand zero = { OP_REG, { 0 }};
static const Operand ra = { OP_REG, { 1 }};
static const Operand zimm = { OP_IM12S };

static void asm_binary_opcode(TCCState* s1, ຈຳນວນເຕັມ token);
ST_FUNC void asm_clobber(uint8_t *clobber_regs, const var_na *str);
ST_FUNC void asm_compute_constraints(ASMOperand *operands, ຈຳນວນເຕັມ nb_operands, ຈຳນວນເຕັມ nb_outputs, const uint8_t *clobber_regs, ຈຳນວນເຕັມ *pout_reg);
static void asm_emit_a(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rs1, const Operand *rs2, const Operand *rd1, ຈຳນວນເຕັມ aq, ຈຳນວນເຕັມ rl);
static void asm_emit_b(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rs1, const Operand *rs2, const Operand *imm);
static void asm_emit_i(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rd, const Operand *rs1, const Operand *rs2);
static void asm_emit_j(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rd, const Operand *rs2);
static void asm_emit_opcode(uint32_t opcode);
static void asm_emit_r(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rd, const Operand *rs1, const Operand *rs2);
static void asm_emit_s(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rs1, const Operand *rs2, const Operand *imm);
static void asm_emit_u(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rd, const Operand *rs2);
static void asm_emit_f(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rd, const Operand *rs1, const Operand *rs2);
static void asm_emit_fb(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rd, const Operand *rs);
static void asm_emit_fq(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rd, const Operand *rs1, const Operand *rs2, const Operand *rs3);
ST_FUNC void asm_gen_code(ASMOperand *operands, ຈຳນວນເຕັມ nb_operands, ຈຳນວນເຕັມ nb_outputs, ຈຳນວນເຕັມ is_output, uint8_t *clobber_regs, ຈຳນວນເຕັມ out_reg);
static void asm_nullary_opcode(TCCState *s1, ຈຳນວນເຕັມ token);
ST_FUNC void asm_opcode(TCCState *s1, ຈຳນວນເຕັມ token);
static ຈຳນວນເຕັມ asm_parse_csrvar(ຈຳນວນເຕັມ t);
ST_FUNC ຈຳນວນເຕັມ asm_parse_regvar(ຈຳນວນເຕັມ t);
static void asm_ternary_opcode(TCCState *s1, ຈຳນວນເຕັມ token);
static void asm_unary_opcode(TCCState *s1, ຈຳນວນເຕັມ token);
static void asm_branch_opcode(TCCState *s1, ຈຳນວນເຕັມ token, ຈຳນວນເຕັມ argc);
ST_FUNC void gen_expr32(ExprValue *pe);
static void parse_operand(TCCState *s1, Operand *op);
static void parse_branch_offset_operand(TCCState *s1, Operand *op);
static void parse_operands(TCCState *s1, Operand *ops, ຈຳນວນເຕັມ count);
static void parse_mem_access_operands(TCCState *s1, Operand* ops);
ST_FUNC void subst_asm_operand(CString *add_str, SValue *sv, ຈຳນວນເຕັມ modifier);
/* C extension */
static void asm_emit_ca(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rd, const Operand *rs2);
static void asm_emit_cb(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rs1, const Operand *imm);
static void asm_emit_ci(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rd, const Operand *imm);
static void asm_emit_ciw(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rd, const Operand *imm);
static void asm_emit_cj(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *imm);
static void asm_emit_cl(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rd, const Operand *rs1, const Operand *imm);
static void asm_emit_cr(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rd, const Operand *rs2);
static void asm_emit_cs(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rs2, const Operand *rs1, const Operand *imm);
static void asm_emit_css(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rs2, const Operand *imm);

/* XXX: make it faster ? */
ST_FUNC void g(ຈຳນວນເຕັມ c)
{
    ຈຳນວນເຕັມ ind1;
    ຖ້າ (nocode_wanted)
        ສົ່ງຄືນ;
    ind1 = ind + 1;
    ຖ້າ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC void gen_le16 (ຈຳນວນເຕັມ i)
{
    g(i);
    g(i>>8);
}

ST_FUNC void gen_le32 (ຈຳນວນເຕັມ i)
{
    ຈຳນວນເຕັມ ind1;
    ຖ້າ (nocode_wanted)
        ສົ່ງຄືນ;
    ind1 = ind + 4;
    ຖ້າ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC void gen_expr32(ExprValue *pe)
{
    gen_le32(pe->v);
}

static void asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

static void asm_nullary_opcode(TCCState *s1, ຈຳນວນເຕັມ token)
{
    switch (token) {
    // Sync instructions

    pak_sa TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        ສົ່ງຄືນ;

    // System calls

    pak_sa TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        ສົ່ງຄືນ;

    // Other

    pak_sa TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        ສົ່ງຄືນ;

    /* Pseudoinstructions */
    pak_sa TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        ສົ່ງຄືນ;

    /* C extension */
    pak_sa TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        ສົ່ງຄືນ;

    default:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
static void parse_operand(TCCState *s1, Operand *op)
{
    ExprValue e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    ຖ້າ ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        ສົ່ງຄືນ;
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ (tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ ((e.v = asm_parse_csrvar(tok)) != -1) {
        next();
    } ບໍ່ດັ່ງນັ້ນ {
        asm_expr(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ຖ້າ (!op->e.sym) {
        ຖ້າ ((ຈຳນວນເຕັມ) op->e.v >= -0x1000 && (ຈຳນວນເຕັມ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        ຖ້າ (op->e.sym->type.t & VT_STATIC)
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_PCREL_HI20, 0);
        ບໍ່ດັ່ງນັ້ນ
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_GOT_HI20, 0);
        put_extern_sym(&label, cur_text_section, ind, 0);
        greloca(cur_text_section, &label, ind+4, R_RISCV_PCREL_LO12_I, 0);

        op->type = OP_IM12S;
        op->e.v = 0;
    } ບໍ່ດັ່ງນັ້ນ {
        expect("operand");
    }
}

static void parse_branch_offset_operand(TCCState *s1, Operand *op){
    ExprValue e = {0};

    asm_expr(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ຖ້າ (!op->e.sym) {
        ຖ້າ ((ຈຳນວນເຕັມ) op->e.v >= -0x1000 && (ຈຳນວນເຕັມ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } ບໍ່ດັ່ງນັ້ນ {
        expect("operand");
    }
}

static void parse_jump_offset_operand(TCCState *s1, Operand *op){
    ExprValue e = {0};

    asm_expr(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ຖ້າ (!op->e.sym) {
        ຖ້າ ((ຈຳນວນເຕັມ) op->e.v >= -0x1000 && (ຈຳນວນເຕັມ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_text_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } ບໍ່ດັ່ງນັ້ນ {
        expect("operand");
    }
}

static void parse_operands(TCCState *s1, Operand* ops, ຈຳນວນເຕັມ count){
    ຈຳນວນເຕັມ i;
    ສຳລັບ (i = 0; i < count; i++) {
        ຖ້າ ( i != 0 )
            skip(',');
        parse_operand(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
static void parse_mem_access_operands(TCCState *s1, Operand* ops){

    Operand op;

    parse_operand(s1, &ops[0]);
    skip(',');
    ຖ້າ ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } ບໍ່ດັ່ງນັ້ນ {
        parse_operand(s1, &ops[2]);
        ຖ້າ ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } ບໍ່ດັ່ງນັ້ນ {
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
static void asm_jal_opcode(TCCState *s1, ຈຳນວນເຕັມ token){
    Operand ops[2];

    ຖ້າ (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } ບໍ່ດັ່ງນັ້ນ {
        // jal reg, offset
        parse_operand(s1, &ops[0]);
        ຖ້າ ( tok == ',') next(); ບໍ່ດັ່ງນັ້ນ expect("','");
    }
    parse_jump_offset_operand(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
static void asm_jalr_opcode(TCCState *s1, ຈຳນວນເຕັມ token){
    Operand ops[3];
    Operand op;

    parse_operand(s1, &ops[0]);
    ຖ້າ ( tok == ',')
        next();
    ບໍ່ດັ່ງນັ້ນ {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        ສົ່ງຄືນ;
    }

    ຖ້າ ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } ບໍ່ດັ່ງນັ້ນ {
        parse_operand(s1, &ops[2]);
        ຖ້າ ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } ບໍ່ດັ່ງນັ້ນ {
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


static void asm_unary_opcode(TCCState *s1, ຈຳນວນເຕັມ token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    Operand op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    switch (token) {
    /* pseudoinstructions */
    pak_sa TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_tail:
        /* auipc x6, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        ສົ່ງຄືນ;

    /* C extension */
    pak_sa TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        ສົ່ງຄືນ;

    default:
        expect("unary instruction");
    }
}

static void asm_emit_u(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand* rd, const Operand* rs2)
{
    ຖ້າ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, NULL));
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, NULL));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

static ຈຳນວນເຕັມ parse_fence_operand(){
    ຈຳນວນເຕັມ t = tok;
    ຖ້າ ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    next();
    ສົ່ງຄືນ t - (TOK_ASM_w_fence - 1);
}

static void asm_fence_opcode(TCCState *s1, ຈຳນວນເຕັມ token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    ຈຳນວນເຕັມ succ = 0xF, pred = 0xF;
    ຖ້າ (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_operand();
        ຖ້າ ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, NULL));
        }
        skip(',');
        succ = parse_fence_operand();
        ຖ້າ ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, NULL));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

static void asm_binary_opcode(TCCState* s1, ຈຳນວນເຕັມ token)
{
    Operand imm = { OP_IM12S };
    Operand ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    switch (token) {
    pak_sa TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        ສົ່ງຄືນ;

    /* C extension */
    pak_sa TOK_ASM_c_add:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        ສົ່ງຄືນ;

#define CA (1 | (3 << 10) | (4 << 13))
    pak_sa TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        ສົ່ງຄືນ;
#undef CA

    pak_sa TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        ສົ່ງຄືນ;

    /* F/D extension */
    pak_sa TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        ສົ່ງຄືນ;

    /* pseudoinstructions */
    /* rd, sym */
    pak_sa TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_li:
        ຖ້າ(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, NULL));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        ຖ້າ(lo < 0){
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
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ສົ່ງຄືນ;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    pak_sa TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_text_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ສົ່ງຄືນ;

    /* CSR pseudo-instructions */
    pak_sa TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ສົ່ງຄືນ;
    default:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
static void asm_emit_r(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand* rd, const Operand* rs1, const Operand* rs2)
{
    ຖ້າ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, NULL));
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
static void asm_emit_f(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand* rd, const Operand* rs1, const Operand* rs2)
{
    ຖ້າ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, NULL));
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
static void asm_emit_fb(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand* rd, const Operand* rs)
{
    ຖ້າ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, NULL));
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
static void asm_emit_fq(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand* rd, const Operand* rs1, const Operand* rs2, const Operand* rs3)
{
    ຖ້າ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, NULL));
    }
    /* F-type instruction:
	     31...27 rs3
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (REG_VALUE(rs3->reg) << 27));
}

/* caller: Add funct3 into opcode */
static void asm_emit_i(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand* rd, const Operand* rs1, const Operand* rs2)
{
    ຖ້າ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, NULL));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

static void asm_emit_j(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand* rd, const Operand* rs2)
{
    uint32_t imm;

    ຖ້າ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, NULL));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    ຖ້າ ((ຈຳນວນເຕັມ)imm > (1 << 20) -1 || (ຈຳນວນເຕັມ)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, NULL));
    }

    ຖ້າ (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, NULL));
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

static void asm_mem_access_opcode(TCCState *s1, ຈຳນວນເຕັມ token)
{

    Operand ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    ຖ້າ (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    switch (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    pak_sa TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    pak_sa TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ສົ່ງຄືນ;
    }
}

static void asm_branch_opcode(TCCState *s1, ຈຳນວນເຕັມ token, ຈຳນວນເຕັມ argc)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_offset_operand(s1, &ops[argc-1]);

    switch(token){
    /* branch (RS1, RS2, IMM); B-format */
    pak_sa TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    /* related pseudoinstructions */
    pak_sa TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        ສົ່ງຄືນ;
    /* shorter pseudoinstructions */
    pak_sa TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        ສົ່ງຄືນ;
    }
}

static void asm_ternary_opcode(TCCState *s1, ຈຳນວນເຕັມ token)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], 3);

    switch (token) {
    pak_sa TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ສົ່ງຄືນ;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    pak_sa TOK_ASM_add:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    pak_sa TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    pak_sa TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;
    pak_sa TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ສົ່ງຄືນ;

    /* M extension */
    pak_sa TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    pak_sa TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        ສົ່ງຄືນ;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    pak_sa TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;

    /* F/D extension */
    pak_sa TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ສົ່ງຄືນ;

    /* F/D comparison: produce integer result, encode manually */
    pak_sa TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ສົ່ງຄືນ;

    default:
        expect("ternary instruction");
    }
}

static void asm_quaternary_opcode(TCCState *s1, ຈຳນວນເຕັມ token)
{
    Operand ops[4];
    parse_operands(s1, &ops[0], 4);

    switch (token) {
    pak_sa TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ສົ່ງຄືນ;

    default:
        expect("quaternary instruction");
    }
}

static void asm_atomic_opcode(TCCState *s1, ຈຳນວນເຕັມ token)
{
    Operand ops[3];

    parse_operand(s1, &ops[0]);
    skip(',');

    ຖ້າ ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } ບໍ່ດັ່ງນັ້ນ {
        parse_operand(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_operand(s1, &ops[2]);
    skip(')');

    switch(token){
        pak_sa TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            bha_nga;
        pak_sa TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            bha_nga;
        pak_sa TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            bha_nga;
        pak_sa TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            bha_nga;

        pak_sa TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            bha_nga;
        pak_sa TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            bha_nga;
        pak_sa TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            bha_nga;
        pak_sa TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            bha_nga;

        pak_sa TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            bha_nga;
        pak_sa TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            bha_nga;
        pak_sa TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            bha_nga;
        pak_sa TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            bha_nga;

        pak_sa TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            bha_nga;
        pak_sa TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            bha_nga;
        pak_sa TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            bha_nga;
        pak_sa TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            bha_nga;

        /* AMO instructions (base, aq=0 rl=0) */
        pak_sa TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;
        pak_sa TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); bha_nga;

        /* AMO aq/rl variants */
        pak_sa TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;

        pak_sa TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
        pak_sa TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); bha_nga;
        pak_sa TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); bha_nga;
        pak_sa TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); bha_nga;
    }
}

/* caller: Add funct3 and func5 to opcode */
static void asm_emit_a(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rd1, const Operand *rs2, const Operand *rs1, ຈຳນວນເຕັມ aq, ຈຳນວນເຕັມ rl)
{
    ຖ້າ (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, NULL));
    ຖ້າ (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, NULL));
    ຖ້າ (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, NULL));
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
static void asm_emit_s(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand* rs1, const Operand* rs2, const Operand* imm)
{
    ຖ້າ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, NULL));
    }
    ຖ້າ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, NULL));
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

static void asm_emit_b(ຈຳນວນເຕັມ token, uint32_t opcode, const Operand *rs1, const Operand *rs2, const Operand *imm)
{
    uint32_t offset;

    ຖ້າ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, NULL));
    }
    ຖ້າ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }
    ຖ້າ (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        ຈຳນວນເຕັມ b_ofs = ind;
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
        ສົ່ງຄືນ;
    }
    ຖ້າ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, NULL));
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
static ຈຳນວນເຕັມ asm_fcvt_rm(TCCState *s1)
{
    ຈຳນວນເຕັມ rm = 7; /* dynamic */
    ຖ້າ (tok == ',') {
        next();
        switch (tok) {
            pak_sa TOK_ASM_rne: rm = 0; next(); bha_nga;
            pak_sa TOK_ASM_rtz: rm = 1; next(); bha_nga;
            pak_sa TOK_ASM_rdn: rm = 2; next(); bha_nga;
            pak_sa TOK_ASM_rup: rm = 3; next(); bha_nga;
            pak_sa TOK_ASM_rmm: rm = 4; next(); bha_nga;
            default: expect("rounding mode"); bha_nga;
        }
    }
    ສົ່ງຄືນ rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
static void asm_fcvt_opcode(TCCState *s1, ຈຳນວນເຕັມ token)
{
    Operand ops[2];
    ຈຳນວນເຕັມ rm;
    uint32_t enc = 0;

    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);

    switch (token) {
        pak_sa TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); bha_nga;
        pak_sa TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); bha_nga;
        pak_sa TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); bha_nga;
        pak_sa TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); bha_nga;
        pak_sa TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); bha_nga;
        pak_sa TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); bha_nga;
        pak_sa TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); bha_nga;
        pak_sa TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); bha_nga;
        default: expect("fcvt/fclass instruction"); ສົ່ງຄືນ;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC void asm_opcode(TCCState *s1, ຈຳນວນເຕັມ token)
{
    switch (token) {
    pak_sa TOK_ASM_ebreak:
    pak_sa TOK_ASM_ecall:
    pak_sa TOK_ASM_fence_i:
    pak_sa TOK_ASM_hrts:
    pak_sa TOK_ASM_mrth:
    pak_sa TOK_ASM_mrts:
    pak_sa TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_rdcycle:
    pak_sa TOK_ASM_rdcycleh:
    pak_sa TOK_ASM_rdtime:
    pak_sa TOK_ASM_rdtimeh:
    pak_sa TOK_ASM_rdinstret:
    pak_sa TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_lui:
    pak_sa TOK_ASM_auipc:
    pak_sa TOK_ASM_fsqrt_s:
    pak_sa TOK_ASM_fsqrt_d:
        asm_binary_opcode(s1, token);
        ສົ່ງຄືນ;

    /* fcvt/fclass — separate handler for optional rounding operand */
    pak_sa TOK_ASM_fcvt_w_s:
    pak_sa TOK_ASM_fcvt_wu_s:
    pak_sa TOK_ASM_fcvt_l_s:
    pak_sa TOK_ASM_fcvt_lu_s:
    pak_sa TOK_ASM_fcvt_s_w:
    pak_sa TOK_ASM_fcvt_s_wu:
    pak_sa TOK_ASM_fcvt_s_l:
    pak_sa TOK_ASM_fcvt_s_lu:
    pak_sa TOK_ASM_fcvt_w_d:
    pak_sa TOK_ASM_fcvt_wu_d:
    pak_sa TOK_ASM_fcvt_l_d:
    pak_sa TOK_ASM_fcvt_lu_d:
    pak_sa TOK_ASM_fcvt_d_w:
    pak_sa TOK_ASM_fcvt_d_wu:
    pak_sa TOK_ASM_fcvt_d_l:
    pak_sa TOK_ASM_fcvt_d_lu:
    pak_sa TOK_ASM_fcvt_s_d:
    pak_sa TOK_ASM_fcvt_d_s:
    pak_sa TOK_ASM_fclass_s:
    pak_sa TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_lb:
    pak_sa TOK_ASM_lh:
    pak_sa TOK_ASM_lw:
    pak_sa TOK_ASM_ld:
    pak_sa TOK_ASM_fld:
    pak_sa TOK_ASM_lbu:
    pak_sa TOK_ASM_lhu:
    pak_sa TOK_ASM_lwu:
    pak_sa TOK_ASM_sb:
    pak_sa TOK_ASM_sh:
    pak_sa TOK_ASM_sw:
    pak_sa TOK_ASM_sd:
    pak_sa TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        bha_nga;

    pak_sa TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        bha_nga;
    pak_sa TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        bha_nga;

    pak_sa TOK_ASM_add:
    pak_sa TOK_ASM_addi:
    pak_sa TOK_ASM_addiw:
    pak_sa TOK_ASM_addw:
    pak_sa TOK_ASM_and:
    pak_sa TOK_ASM_andi:
    pak_sa TOK_ASM_or:
    pak_sa TOK_ASM_ori:
    pak_sa TOK_ASM_sll:
    pak_sa TOK_ASM_slli:
    pak_sa TOK_ASM_slliw:
    pak_sa TOK_ASM_sllw:
    pak_sa TOK_ASM_slt:
    pak_sa TOK_ASM_slti:
    pak_sa TOK_ASM_sltiu:
    pak_sa TOK_ASM_sltu:
    pak_sa TOK_ASM_sra:
    pak_sa TOK_ASM_srai:
    pak_sa TOK_ASM_sraiw:
    pak_sa TOK_ASM_sraw:
    pak_sa TOK_ASM_srl:
    pak_sa TOK_ASM_srli:
    pak_sa TOK_ASM_srliw:
    pak_sa TOK_ASM_srlw:
    pak_sa TOK_ASM_sub:
    pak_sa TOK_ASM_subw:
    pak_sa TOK_ASM_xor:
    pak_sa TOK_ASM_xori:
    /* M extension */
    pak_sa TOK_ASM_div:
    pak_sa TOK_ASM_divu:
    pak_sa TOK_ASM_divuw:
    pak_sa TOK_ASM_divw:
    pak_sa TOK_ASM_mul:
    pak_sa TOK_ASM_mulh:
    pak_sa TOK_ASM_mulhsu:
    pak_sa TOK_ASM_mulhu:
    pak_sa TOK_ASM_mulw:
    pak_sa TOK_ASM_rem:
    pak_sa TOK_ASM_remu:
    pak_sa TOK_ASM_remuw:
    pak_sa TOK_ASM_remw:
    /* Zicsr extension */
    pak_sa TOK_ASM_csrrc:
    pak_sa TOK_ASM_csrrci:
    pak_sa TOK_ASM_csrrs:
    pak_sa TOK_ASM_csrrsi:
    pak_sa TOK_ASM_csrrw:
    pak_sa TOK_ASM_csrrwi:
    /* F/D extension */
    pak_sa TOK_ASM_fadd_s:
    pak_sa TOK_ASM_fadd_d:
    pak_sa TOK_ASM_fsub_s:
    pak_sa TOK_ASM_fsub_d:
    pak_sa TOK_ASM_fmul_s:
    pak_sa TOK_ASM_fmul_d:
    pak_sa TOK_ASM_fdiv_s:
    pak_sa TOK_ASM_fdiv_d:
    pak_sa TOK_ASM_fsgnj_d:
    pak_sa TOK_ASM_fsgnj_s:
    pak_sa TOK_ASM_fmax_s:
    pak_sa TOK_ASM_fmax_d:
    pak_sa TOK_ASM_fmin_s:
    pak_sa TOK_ASM_fmin_d:
    pak_sa TOK_ASM_feq_s:
    pak_sa TOK_ASM_feq_d:
    pak_sa TOK_ASM_flt_s:
    pak_sa TOK_ASM_flt_d:
    pak_sa TOK_ASM_fle_s:
    pak_sa TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_fmadd_d:
    pak_sa TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        ສົ່ງຄືນ;

    /* Branches */
    pak_sa TOK_ASM_beq:
    pak_sa TOK_ASM_bge:
    pak_sa TOK_ASM_bgeu:
    pak_sa TOK_ASM_blt:
    pak_sa TOK_ASM_bltu:
    pak_sa TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        bha_nga;

    /* C extension */
    pak_sa TOK_ASM_c_ebreak:
    pak_sa TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_c_j:
    pak_sa TOK_ASM_c_jal:
    pak_sa TOK_ASM_c_jalr:
    pak_sa TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_c_add:
    pak_sa TOK_ASM_c_addi16sp:
    pak_sa TOK_ASM_c_addi4spn:
    pak_sa TOK_ASM_c_addi:
    pak_sa TOK_ASM_c_addiw:
    pak_sa TOK_ASM_c_addw:
    pak_sa TOK_ASM_c_and:
    pak_sa TOK_ASM_c_andi:
    pak_sa TOK_ASM_c_beqz:
    pak_sa TOK_ASM_c_bnez:
    pak_sa TOK_ASM_c_fldsp:
    pak_sa TOK_ASM_c_flwsp:
    pak_sa TOK_ASM_c_fsdsp:
    pak_sa TOK_ASM_c_fswsp:
    pak_sa TOK_ASM_c_ldsp:
    pak_sa TOK_ASM_c_li:
    pak_sa TOK_ASM_c_lui:
    pak_sa TOK_ASM_c_lwsp:
    pak_sa TOK_ASM_c_mv:
    pak_sa TOK_ASM_c_or:
    pak_sa TOK_ASM_c_sdsp:
    pak_sa TOK_ASM_c_slli:
    pak_sa TOK_ASM_c_srai:
    pak_sa TOK_ASM_c_srli:
    pak_sa TOK_ASM_c_sub:
    pak_sa TOK_ASM_c_subw:
    pak_sa TOK_ASM_c_swsp:
    pak_sa TOK_ASM_c_xor:
        asm_binary_opcode(s1, token);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_c_fld:
    pak_sa TOK_ASM_c_flw:
    pak_sa TOK_ASM_c_fsd:
    pak_sa TOK_ASM_c_fsw:
    pak_sa TOK_ASM_c_ld:
    pak_sa TOK_ASM_c_lw:
    pak_sa TOK_ASM_c_sd:
    pak_sa TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        ສົ່ງຄືນ;

    /* pseudoinstructions */
    pak_sa TOK_ASM_nop:
    pak_sa TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_jr:
    pak_sa TOK_ASM_call:
    pak_sa TOK_ASM_tail:
    pak_sa TOK_ASM_frflags:
    pak_sa TOK_ASM_frrm:
    pak_sa TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_la:
    pak_sa TOK_ASM_lla:
    pak_sa TOK_ASM_li:
    pak_sa TOK_ASM_jump:
    pak_sa TOK_ASM_seqz:
    pak_sa TOK_ASM_snez:
    pak_sa TOK_ASM_sltz:
    pak_sa TOK_ASM_sgtz:
    pak_sa TOK_ASM_mv:
    pak_sa TOK_ASM_not:
    pak_sa TOK_ASM_neg:
    pak_sa TOK_ASM_negw:
    pak_sa TOK_ASM_sext_w:
    pak_sa TOK_ASM_fabs_s:
    pak_sa TOK_ASM_fabs_d:
    pak_sa TOK_ASM_fmv_s:
    pak_sa TOK_ASM_fmv_d:
    pak_sa TOK_ASM_fneg_s:
    pak_sa TOK_ASM_fneg_d:
    pak_sa TOK_ASM_csrc:
    pak_sa TOK_ASM_csrs:
    pak_sa TOK_ASM_csrr:
    pak_sa TOK_ASM_csrw:
    pak_sa TOK_ASM_csrwi:
    pak_sa TOK_ASM_csrsi:
    pak_sa TOK_ASM_csrci:
    pak_sa TOK_ASM_fsrm:
    pak_sa TOK_ASM_fscsr:
        asm_binary_opcode(s1, token);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_bnez:
    pak_sa TOK_ASM_beqz:
    pak_sa TOK_ASM_blez:
    pak_sa TOK_ASM_bgez:
    pak_sa TOK_ASM_bltz:
    pak_sa TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        ສົ່ງຄືນ;

    pak_sa TOK_ASM_bgt:
    pak_sa TOK_ASM_bgtu:
    pak_sa TOK_ASM_ble:
    pak_sa TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        ສົ່ງຄືນ;

    /* Atomic operations */
    pak_sa TOK_ASM_lr_w:
    pak_sa TOK_ASM_lr_w_aq:
    pak_sa TOK_ASM_lr_w_rl:
    pak_sa TOK_ASM_lr_w_aqrl:
    pak_sa TOK_ASM_lr_d:
    pak_sa TOK_ASM_lr_d_aq:
    pak_sa TOK_ASM_lr_d_rl:
    pak_sa TOK_ASM_lr_d_aqrl:
    pak_sa TOK_ASM_sc_w:
    pak_sa TOK_ASM_sc_w_aq:
    pak_sa TOK_ASM_sc_w_rl:
    pak_sa TOK_ASM_sc_w_aqrl:
    pak_sa TOK_ASM_sc_d:
    pak_sa TOK_ASM_sc_d_aq:
    pak_sa TOK_ASM_sc_d_rl:
    pak_sa TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    pak_sa TOK_ASM_amoadd_w:
    pak_sa TOK_ASM_amoadd_d:
    pak_sa TOK_ASM_amoswap_w:
    pak_sa TOK_ASM_amoswap_d:
    pak_sa TOK_ASM_amoand_w:
    pak_sa TOK_ASM_amoand_d:
    pak_sa TOK_ASM_amoor_w:
    pak_sa TOK_ASM_amoor_d:
    pak_sa TOK_ASM_amoxor_w:
    pak_sa TOK_ASM_amoxor_d:
    pak_sa TOK_ASM_amomax_w:
    pak_sa TOK_ASM_amomax_d:
    pak_sa TOK_ASM_amomaxu_w:
    pak_sa TOK_ASM_amomaxu_d:
    pak_sa TOK_ASM_amomin_w:
    pak_sa TOK_ASM_amomin_d:
    pak_sa TOK_ASM_amominu_w:
    pak_sa TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    pak_sa TOK_ASM_amoadd_w_aq:
    pak_sa TOK_ASM_amoadd_w_rl:
    pak_sa TOK_ASM_amoadd_w_aqrl:
    pak_sa TOK_ASM_amoadd_d_aq:
    pak_sa TOK_ASM_amoadd_d_rl:
    pak_sa TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    pak_sa TOK_ASM_amoswap_w_aq:
    pak_sa TOK_ASM_amoswap_w_rl:
    pak_sa TOK_ASM_amoswap_w_aqrl:
    pak_sa TOK_ASM_amoswap_d_aq:
    pak_sa TOK_ASM_amoswap_d_rl:
    pak_sa TOK_ASM_amoswap_d_aqrl:
    pak_sa TOK_ASM_amoand_w_aq:
    pak_sa TOK_ASM_amoand_w_rl:
    pak_sa TOK_ASM_amoand_w_aqrl:
    pak_sa TOK_ASM_amoand_d_aq:
    pak_sa TOK_ASM_amoand_d_rl:
    pak_sa TOK_ASM_amoand_d_aqrl:
    pak_sa TOK_ASM_amoor_w_aq:
    pak_sa TOK_ASM_amoor_w_rl:
    pak_sa TOK_ASM_amoor_w_aqrl:
    pak_sa TOK_ASM_amoor_d_aq:
    pak_sa TOK_ASM_amoor_d_rl:
    pak_sa TOK_ASM_amoor_d_aqrl:
    pak_sa TOK_ASM_amoxor_w_aq:
    pak_sa TOK_ASM_amoxor_w_rl:
    pak_sa TOK_ASM_amoxor_w_aqrl:
    pak_sa TOK_ASM_amoxor_d_aq:
    pak_sa TOK_ASM_amoxor_d_rl:
    pak_sa TOK_ASM_amoxor_d_aqrl:
    pak_sa TOK_ASM_amomax_w_aq:
    pak_sa TOK_ASM_amomax_w_rl:
    pak_sa TOK_ASM_amomax_w_aqrl:
    pak_sa TOK_ASM_amomax_d_aq:
    pak_sa TOK_ASM_amomax_d_rl:
    pak_sa TOK_ASM_amomax_d_aqrl:
    pak_sa TOK_ASM_amomaxu_w_aq:
    pak_sa TOK_ASM_amomaxu_w_rl:
    pak_sa TOK_ASM_amomaxu_w_aqrl:
    pak_sa TOK_ASM_amomaxu_d_aq:
    pak_sa TOK_ASM_amomaxu_d_rl:
    pak_sa TOK_ASM_amomaxu_d_aqrl:
    pak_sa TOK_ASM_amomin_w_aq:
    pak_sa TOK_ASM_amomin_w_rl:
    pak_sa TOK_ASM_amomin_w_aqrl:
    pak_sa TOK_ASM_amomin_d_aq:
    pak_sa TOK_ASM_amomin_d_rl:
    pak_sa TOK_ASM_amomin_d_aqrl:
    pak_sa TOK_ASM_amominu_w_aq:
    pak_sa TOK_ASM_amominu_w_rl:
    pak_sa TOK_ASM_amominu_w_aqrl:
    pak_sa TOK_ASM_amominu_d_aq:
    pak_sa TOK_ASM_amominu_d_rl:
    pak_sa TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        bha_nga;

    default:
        expect("known instruction");
    }
}

static ຈຳນວນເຕັມ asm_parse_csrvar(ຈຳນວນເຕັມ t)
{
    switch (t) {
    pak_sa TOK_ASM_cycle:
        ສົ່ງຄືນ 0xc00;
    pak_sa TOK_ASM_fcsr:
        ສົ່ງຄືນ 3;
    pak_sa TOK_ASM_fflags:
        ສົ່ງຄືນ 1;
    pak_sa TOK_ASM_frm:
        ສົ່ງຄືນ 2;
    pak_sa TOK_ASM_instret:
        ສົ່ງຄືນ 0xc02;
    pak_sa TOK_ASM_time:
        ສົ່ງຄືນ 0xc01;
    pak_sa TOK_ASM_cycleh:
        ສົ່ງຄືນ 0xc80;
    pak_sa TOK_ASM_instreth:
        ສົ່ງຄືນ 0xc82;
    pak_sa TOK_ASM_timeh:
        ສົ່ງຄືນ 0xc81;
    default:
        ສົ່ງຄືນ -1;
    }
}

ST_FUNC void subst_asm_operand(CString *add_str, SValue *sv, ຈຳນວນເຕັມ modifier)
{
    ຈຳນວນເຕັມ r, reg, val;

    r = sv->r;
    ຖ້າ ((r & VT_VALMASK) == VT_CONST) {
        ຖ້າ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        ຖ້າ (r & VT_SYM) {
            const var_na *name = get_tok_str(sv->sym->v, NULL);
            ຖ້າ (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            ຖ້າ (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            ຖ້າ ((uint32_t) sv->c.i == 0)
                goto no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        ຖ້າ (modifier == 'n')
            val = -val;
        ຖ້າ (modifier == 'z' && val == 0) {
            cstr_cat(add_str, "zero", -1);
        } ບໍ່ດັ່ງນັ້ນ {
            cstr_printf(add_str, "%d", val);
        }
      no_offset:;
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d", (ຈຳນວນເຕັມ) sv->c.i);
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ຖ້າ (reg >= VT_CONST)
            tcc_internal_error("");
        ຖ້າ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_VALUE(reg);
        } ບໍ່ດັ່ງນັ້ນ {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, NULL), -1);
    } ບໍ່ດັ່ງນັ້ນ {
        /* register case */
        reg = r & VT_VALMASK;
        ຖ້າ (reg >= VT_CONST)
            tcc_internal_error("");
        ຖ້າ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_VALUE(reg);
        } ບໍ່ດັ່ງນັ້ນ {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, NULL), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
static ຈຳນວນເຕັມ tcc_ireg(ຈຳນວນເຕັມ r){
    ສົ່ງຄືນ REG_VALUE(r) - 10;
}
static ຈຳນວນເຕັມ tcc_freg(ຈຳນວນເຕັມ r){
    ສົ່ງຄືນ REG_VALUE(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC void asm_gen_code(ASMOperand *operands, ຈຳນວນເຕັມ nb_operands,
                         ຈຳນວນເຕັມ nb_outputs, ຈຳນວນເຕັມ is_output,
                         uint8_t *clobber_regs,
                         ຈຳນວນເຕັມ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ຈຳນວນເຕັມ i, reg;

    static const uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, parimaa_na(regs_allocated));
    ສຳລັບ(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ຖ້າ (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    ຖ້າ(!is_output) {
        /* generate reg save code */
        ສຳລັບ(i = 0; i < parimaa_na(reg_saved)/parimaa_na(reg_saved[0]); i++) {
            reg = reg_saved[i];
            ຖ້າ (regs_allocated[reg]) {
                /* push */
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (unsigned)-8 << 20);
                ຖ້າ (REG_IS_FLOAT(reg)){
                    /* fsd reg, offset(sp) */
                    gen_le32( 0x27 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                } ບໍ່ດັ່ງນັ້ນ {
                    /* sd reg, offset(sp) */
                    gen_le32((0x8 << 2) | 3 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                }
            }
        }

        /* generate load code */
        ສຳລັບ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ຖ້າ (op->reg >= 0) {
                ຖ້າ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(tcc_ireg(op->reg), &sv);
                } ບໍ່ດັ່ງນັ້ນ ຖ້າ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    ຖ້າ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        load(tcc_freg(op->reg), op->vt);
                    } ບໍ່ດັ່ງນັ້ນ {
                        load(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register;
                       the load/store above already handles it correctly */
                }
            }
        }
    } ບໍ່ດັ່ງນັ້ນ {
        /* generate save code */
        ສຳລັບ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ຖ້າ (op->reg >= 0) {
                ຖ້າ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ຖ້າ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(tcc_ireg(out_reg), &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(tcc_ireg(op->reg), &sv);
                    }
                } ບໍ່ດັ່ງນັ້ນ {
                    ຖ້າ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        store(tcc_freg(op->reg), op->vt);
                    } ບໍ່ດັ່ງນັ້ນ {
                        store(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register */
                }
            }
        }
        /* generate reg restore code for floating point registers */
        ສຳລັບ(i = parimaa_na(reg_saved)/parimaa_na(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            ຖ້າ (regs_allocated[reg]) {
                /* pop */
                ຖ້າ (REG_IS_FLOAT(reg)){
                    /* fld reg, offset(sp) */
                    gen_le32(7 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                } ບໍ່ດັ່ງນັ້ນ {
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
static anta_hstha ຈຳນວນເຕັມ constraint_priority(const var_na *str)
{
    // TODO: How is this chosen??
    ຈຳນວນເຕັມ priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    ສຳລັບ(;;) {
        c = *str;
        ຖ້າ (c == '\0')
            bha_nga;
        str++;
        switch(c) {
        pak_sa 'A': // address that is held in a general-purpose register.
        pak_sa 'S': // constraint that matches an absolute symbolic address.
        pak_sa 'f': // register [float]
        pak_sa 'r': // register [general]
        pak_sa 'p': // valid memory address for load,store [general]
            pr = 3;
            bha_nga;
        pak_sa 'I': // 12 bit signed immedate
        pak_sa 'i': // immediate integer operand, including symbolic constants [general]
        pak_sa 'm': // memory operand [general]
        pak_sa 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            bha_nga;
        pak_sa 'v':
            tcc_error("unimp: constraint '%c'", c);
        default:
            tcc_error("unknown constraint '%d'", c);
        }
        ຖ້າ (pr > priority)
            priority = pr;
    }
    ສົ່ງຄືນ priority;
}

static const var_na *skip_constraint_modifiers(const var_na *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ໃນຂະນະທີ່ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ສົ່ງຄືນ p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC void asm_compute_constraints(ASMOperand *operands,
                                    ຈຳນວນເຕັມ nb_operands, ຈຳນວນເຕັມ nb_outputs,
                                    const uint8_t *clobber_regs,
                                    ຈຳນວນເຕັມ *pout_reg)
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
    ຈຳນວນເຕັມ sorted_op[MAX_ASM_OPERANDS];
    ຈຳນວນເຕັມ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    const var_na *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ສຳລັບ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->input_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ສຳລັບ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ຖ້າ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, NULL);
            ຖ້າ ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            ຖ້າ (operands[k].input_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].input_index = i;
            op->priority = 5;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } ບໍ່ດັ່ງນັ້ນ {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    ສຳລັບ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ສຳລັບ (i = 0; i < nb_operands - 1; i++) {
        ສຳລັບ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            ຖ້າ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ສຳລັບ (i = 0; i < NB_ASM_REGS; i++) {
        ຖ້າ (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        ບໍ່ດັ່ງນັ້ນ
            regs_allocated[i] = 0;
    }

    /* allocate registers and generate corresponding asm moves */
    ສຳລັບ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ຖ້າ (op->ref_index >= 0)
            continue;
        /* select if register is used for output, input or both */
        ຖ້າ (op->input_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } ບໍ່ດັ່ງນັ້ນ {
            reg_mask = REG_IN_MASK;
        }
        ຖ້າ (op->reg >= 0) {
            ຖ້າ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        switch (c) {
        pak_sa '=': // Operand is written-to
            goto try_next;
        pak_sa '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        pak_sa '&': // Operand is clobbered before the instruction is done using the input operands
            ຖ້າ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            goto try_next;
        pak_sa 'r': // general-purpose register
        pak_sa 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            ຖ້າ ((reg = op->reg) >= 0)
                goto reg_found;
            ບໍ່ດັ່ງນັ້ນ ສຳລັບ (reg = 10; reg <= 18; reg++) {
                ຖ້າ (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            bha_nga;
        pak_sa 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            ຖ້າ ((reg = op->reg) >= 0)
                goto reg_found;
            ບໍ່ດັ່ງນັ້ນ ສຳລັບ (reg = 42; reg <= 50; reg++) {
                ຖ້າ (!is_reg_allocated(reg))
                    goto reg_found;
            }
            goto try_next;
        pak_sa 'I': // I-Type 12 bit signed immediate
        pak_sa 'i': // immediate integer operand, including symbolic constants
            ຖ້າ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                goto try_next;
            bha_nga;
        pak_sa 'm': // memory operand
        pak_sa 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ຖ້າ (j < nb_outputs || c == 'm') {
                ຖ້າ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    ສຳລັບ (reg = 10; reg <= 18; reg++) {
                        ຖ້າ (!(regs_allocated[reg] & REG_IN_MASK))
                            goto reg_found1;
                    }
                    goto try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            bha_nga;
        default:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            bha_nga;
        }
        /* if a reference is present for that operand, we assign it too */
        ຖ້າ (op->input_index >= 0) {
            operands[op->input_index].reg = op->reg;
            operands[op->input_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ສຳລັບ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ຖ້າ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            ຖ້າ (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                ສຳລັບ (reg = 42; reg <= 50; reg++) {
                    ຖ້າ (!(regs_allocated[reg] & REG_OUT_MASK))
                        goto reg_found2;
                }
            } ບໍ່ດັ່ງນັ້ນ {
                /* From a0 to a7 */
                ສຳລັບ (reg = 10; reg <= 18; reg++) {
                    ຖ້າ (!(regs_allocated[reg] & REG_OUT_MASK))
                        goto reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            bha_nga;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    ສຳລັບ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, NULL) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ຖ້າ (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC void asm_clobber(uint8_t *clobber_regs, const var_na *str)
{
    ຈຳນວນເຕັມ reg;
    TokenSym *ts;

    ຖ້າ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ສົ່ງຄືນ;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    ຖ້າ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC ຈຳນວນເຕັມ asm_parse_regvar (ຈຳນວນເຕັມ t)
{
    /* PC register not implemented */
    ຖ້າ (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        ສົ່ງຄືນ -1;

    ຖ້າ (t < TOK_ASM_f0)
        ສົ່ງຄືນ t - TOK_ASM_x0;

    ຖ້າ (t < TOK_ASM_zero)
        ສົ່ງຄືນ t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    ຖ້າ (t < TOK_ASM_ft0)
        ສົ່ງຄືນ t - TOK_ASM_zero;

    ສົ່ງຄືນ t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
static void asm_emit_ca(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rd, const Operand *rs2)
{
    uint8_t dst, src;

    ຖ້າ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }

    ຖ້າ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, NULL));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    ຖ້າ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, NULL));
    }

    ຖ້າ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, NULL));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

static void asm_emit_cb(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rs1, const Operand *imm)
{
    uint32_t offset;
    uint8_t src;

    ຖ້າ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, NULL));
    }

    ຖ້າ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, NULL));
    }

    offset = imm->e.v;

    ຖ້າ (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, NULL));
    }

    src = rs1->reg - 8;

    ຖ້າ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, NULL));
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

    switch (token) {
    pak_sa TOK_ASM_c_beqz:
    pak_sa TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_BIT(offset, 5) | (((offset >> 1) & 3) << 1) | (((offset >> 6) & 3) << 3)) << 2) | ((((offset >> 3) & 3) | NTH_BIT(offset, 8)) << 10));
        ສົ່ງຄືນ;
    default:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((offset & 0x1f) << 2) | (NTH_BIT(offset, 5) << 12));
        ສົ່ງຄືນ;
    }
}

static void asm_emit_ci(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rd, const Operand *imm)
{
    uint32_t immediate;

    ຖ້າ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }

    ຖ້າ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, NULL));
    }

    immediate = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    switch (token) {
    pak_sa TOK_ASM_c_addi:
    pak_sa TOK_ASM_c_addiw:
    pak_sa TOK_ASM_c_li:
    pak_sa TOK_ASM_c_slli:
        gen_le16(opcode | ((immediate & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_BIT(immediate, 5) << 2 | (((immediate >> 7) & 3) << 3) | NTH_BIT(immediate, 6) << 5 | NTH_BIT(immediate, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 9) << 12));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_lui:
        gen_le16(opcode | (((immediate >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 17) << 12));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_fldsp:
    pak_sa TOK_ASM_c_ldsp:
        gen_le16(opcode | (((immediate >> 6) & 7) << 2) | (((immediate >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_flwsp:
    pak_sa TOK_ASM_c_lwsp:
        gen_le16(opcode | (((immediate >> 6) & 3) << 2) | (((immediate >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ສົ່ງຄືນ;
    pak_sa TOK_ASM_c_nop:
        gen_le16(opcode);
        ສົ່ງຄືນ;
    default:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
static void asm_emit_ciw(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rd, const Operand *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    ຖ້າ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }

    ຖ້າ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, NULL));
    }

    dst = rd->reg - 8;

    ຖ້າ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, NULL));
    }

    nzuimm = imm->e.v;

    ຖ້າ (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, NULL));
    }

    ຖ້າ (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, NULL));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_BIT(nzuimm, 3) | (NTH_BIT(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
static void asm_emit_cj(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *imm)
{
    uint32_t offset;

    /* +-2 KiB range */
    ຖ້າ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, NULL));
    }

    offset = imm->e.v;

    ຖ້າ (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, NULL));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_BIT(offset, 5) << 2) | (((offset >> 1) & 7) << 3) | (NTH_BIT(offset, 7) << 6) | (NTH_BIT(offset, 6) << 7) | (NTH_BIT(offset, 10) << 8) | (((offset >> 8) & 3) << 9) | (NTH_BIT(offset, 4) << 11) | (NTH_BIT(offset, 11) << 12));
}

/* caller: Add funct3 into opcode */
static void asm_emit_cl(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rd, const Operand *rs1, const Operand *imm)
{
    uint32_t offset;
    uint8_t dst, src;

    ຖ້າ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }

    ຖ້າ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, NULL));
    }

    ຖ້າ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, NULL));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    ຖ້າ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, NULL));
    }

    ຖ້າ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, NULL));
    }

    offset = imm->e.v;

    ຖ້າ (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, NULL));
    }

    ຖ້າ (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, NULL));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    switch (token) {
    /* imm variant 1 */
    pak_sa TOK_ASM_c_flw:
    pak_sa TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        ສົ່ງຄືນ;
    /* imm variant 2 */
    pak_sa TOK_ASM_c_fld:
    pak_sa TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        ສົ່ງຄືນ;
    default:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
static void asm_emit_cr(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rd, const Operand *rs2)
{
    ຖ້າ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }

    ຖ້າ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, NULL));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
static void asm_emit_cs(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rs2, const Operand *rs1, const Operand *imm)
{
    uint32_t offset;
    uint8_t base, src;

    ຖ້າ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }

    ຖ້າ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, NULL));
    }

    ຖ້າ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, NULL));
    }

    base = rs1->reg - 8;
    src = rs2->reg - 8;

    ຖ້າ (base > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, NULL));
    }

    ຖ້າ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, NULL));
    }

    offset = imm->e.v;

    ຖ້າ (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, NULL));
    }

    ຖ້າ (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, NULL));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    switch (token) {
    /* imm variant 1 */
    pak_sa TOK_ASM_c_fsw:
    pak_sa TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        ສົ່ງຄືນ;
    /* imm variant 2 */
    pak_sa TOK_ASM_c_fsd:
    pak_sa TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        ສົ່ງຄືນ;
    default:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
static void asm_emit_css(ຈຳນວນເຕັມ token, uint16_t opcode, const Operand *rs2, const Operand *imm)
{
    uint32_t offset;

    ຖ້າ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, NULL));
    }

    ຖ້າ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, NULL));
    }

    offset = imm->e.v;

    ຖ້າ (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, NULL));
    }

    ຖ້າ (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, NULL));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    switch (token) {
    /* imm variant 1 */
    pak_sa TOK_ASM_c_fswsp:
    pak_sa TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 3) << 7) | (((offset >> 2) & 0xf) << 9));
        ສົ່ງຄືນ;
    /* imm variant 2 */
    pak_sa TOK_ASM_c_fsdsp:
    pak_sa TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 7) << 7) | (((offset >> 3) & 7) << 10));
        ສົ່ງຄືນ;
    default:
        expect("known instruction");
    }
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
