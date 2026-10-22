/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#ifdef TARGET_DEFS_ONLY

#define CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#define NB_ASM_REGS 64

ST_FUNC शून्य g(पूर्णाङ्क c);
ST_FUNC शून्य gen_le16(पूर्णाङ्क c);
ST_FUNC शून्य gen_le32(पूर्णाङ्क c);

/*************************************************************/
#अन्यथा
/*************************************************************/
#define USING_GLOBALS
#अन्तर्भाव "tcc.h"

गणना {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#define REG_FLOAT_MASK 0x20
#define REG_IS_FLOAT(register_index) ((register_index) & REG_FLOAT_MASK)
#define REG_मान(register_index)    ((register_index) & (REG_FLOAT_MASK-1))
#define C_ENCODE_RS1(register_index) (REG_मान(register_index) << 7)
#define C_ENCODE_RS2(register_index) (REG_मान(register_index) << 2)
#define ENCODE_RD(register_index)  (REG_मान(register_index) << 7)
#define ENCODE_RS1(register_index) (REG_मान(register_index) << 15)
#define ENCODE_RS2(register_index) (REG_मान(register_index) << 20)
#define NTH_BIT(b, n) ((b >> n) & 1)
#define OP_IM12S (1 << OPT_IM12S)
#define OP_IM32 (1 << OPT_IM32)
#define OP_REG (1 << OPT_REG)

प्रकारनिर्देश संरचना Operand {
    uint32_t type;
    सङ्घ {
        uint8_t reg;
        uint16_t regset;
        अभिव्यक्ति_मान e;
    };
} Operand;

स्थिर अचर Operand zero = { OP_REG, { 0 }};
स्थिर अचर Operand ra = { OP_REG, { 1 }};
स्थिर अचर Operand zimm = { OP_IM12S };

स्थिर शून्य asm_द्विआधारी_opcode(TCCState* s1, पूर्णाङ्क token);
ST_FUNC शून्य asm_clobber(uint8_t *clobber_regs, अचर वर्ण *str);
ST_FUNC शून्य asm_compute_constraints(ASMOperand *operands, पूर्णाङ्क nb_operands, पूर्णाङ्क nb_outputs, अचर uint8_t *clobber_regs, पूर्णाङ्क *pout_reg);
स्थिर शून्य asm_emit_a(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rs1, अचर Operand *rs2, अचर Operand *rd1, पूर्णाङ्क aq, पूर्णाङ्क rl);
स्थिर शून्य asm_emit_b(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rs1, अचर Operand *rs2, अचर Operand *imm);
स्थिर शून्य asm_emit_i(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rd, अचर Operand *rs1, अचर Operand *rs2);
स्थिर शून्य asm_emit_j(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rd, अचर Operand *rs2);
स्थिर शून्य asm_emit_opcode(uint32_t opcode);
स्थिर शून्य asm_emit_r(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rd, अचर Operand *rs1, अचर Operand *rs2);
स्थिर शून्य asm_emit_s(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rs1, अचर Operand *rs2, अचर Operand *imm);
स्थिर शून्य asm_emit_u(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rd, अचर Operand *rs2);
स्थिर शून्य asm_emit_f(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rd, अचर Operand *rs1, अचर Operand *rs2);
स्थिर शून्य asm_emit_fb(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rd, अचर Operand *rs);
स्थिर शून्य asm_emit_fq(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rd, अचर Operand *rs1, अचर Operand *rs2, अचर Operand *rs3);
ST_FUNC शून्य asm_gen_code(ASMOperand *operands, पूर्णाङ्क nb_operands, पूर्णाङ्क nb_outputs, पूर्णाङ्क is_output, uint8_t *clobber_regs, पूर्णाङ्क out_reg);
स्थिर शून्य asm_nullary_opcode(TCCState *s1, पूर्णाङ्क token);
ST_FUNC शून्य asm_opcode(TCCState *s1, पूर्णाङ्क token);
स्थिर पूर्णाङ्क asm_parse_csrvar(पूर्णाङ्क t);
ST_FUNC पूर्णाङ्क asm_parse_regvar(पूर्णाङ्क t);
स्थिर शून्य asm_ternary_opcode(TCCState *s1, पूर्णाङ्क token);
स्थिर शून्य asm_unary_opcode(TCCState *s1, पूर्णाङ्क token);
स्थिर शून्य asm_branch_opcode(TCCState *s1, पूर्णाङ्क token, पूर्णाङ्क argc);
ST_FUNC शून्य gen_expr32(अभिव्यक्ति_मान *pe);
स्थिर शून्य parse_operand(TCCState *s1, Operand *op);
स्थिर शून्य parse_branch_offset_operand(TCCState *s1, Operand *op);
स्थिर शून्य parse_operands(TCCState *s1, Operand *ops, पूर्णाङ्क गन्ती_2);
स्थिर शून्य parse_mem_access_operands(TCCState *s1, Operand* ops);
ST_FUNC शून्य subst_asm_operand(CString *add_str, SValue *sv, पूर्णाङ्क modifier);
/* C extension */
स्थिर शून्य asm_emit_ca(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rd, अचर Operand *rs2);
स्थिर शून्य asm_emit_cb(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rs1, अचर Operand *imm);
स्थिर शून्य asm_emit_ci(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rd, अचर Operand *imm);
स्थिर शून्य asm_emit_ciw(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rd, अचर Operand *imm);
स्थिर शून्य asm_emit_cj(पूर्णाङ्क token, uint16_t opcode, अचर Operand *imm);
स्थिर शून्य asm_emit_cl(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rd, अचर Operand *rs1, अचर Operand *imm);
स्थिर शून्य asm_emit_cr(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rd, अचर Operand *rs2);
स्थिर शून्य asm_emit_cs(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rs2, अचर Operand *rs1, अचर Operand *imm);
स्थिर शून्य asm_emit_css(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rs2, अचर Operand *imm);

/* XXX: make it faster ? */
ST_FUNC शून्य g(पूर्णाङ्क c)
{
    पूर्णाङ्क ind1;
    यदि (nocode_wanted)
        फर्काऊ;
    ind1 = ind + 1;
    यदि (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC शून्य gen_le16 (पूर्णाङ्क i)
{
    g(i);
    g(i>>8);
}

ST_FUNC शून्य gen_le32 (पूर्णाङ्क i)
{
    पूर्णाङ्क ind1;
    यदि (nocode_wanted)
        फर्काऊ;
    ind1 = ind + 4;
    यदि (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC शून्य gen_expr32(अभिव्यक्ति_मान *pe)
{
    gen_le32(pe->v);
}

स्थिर शून्य asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

स्थिर शून्य asm_nullary_opcode(TCCState *s1, पूर्णाङ्क token)
{
    विकल्प (token) {
    // Sync instructions

    पक्ष TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        फर्काऊ;

    // System calls

    पक्ष TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        फर्काऊ;
    पक्ष TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        फर्काऊ;

    // Other

    पक्ष TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        फर्काऊ;

    पक्ष TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        फर्काऊ;

    /* Pseudoinstructions */
    पक्ष TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        फर्काऊ;

    /* C extension */
    पक्ष TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        फर्काऊ;
    पक्ष TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        फर्काऊ;

    स्वभाव:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
स्थिर शून्य parse_operand(TCCState *s1, Operand *op)
{
    अभिव्यक्ति_मान e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    यदि ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        फर्काऊ;
    } अन्यथा यदि (tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    } अन्यथा यदि ((e.v = asm_parse_csrvar(tok)) != -1) {
        next();
    } अन्यथा {
        asm_अभिव्यक्ति(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    यदि (!op->e.sym) {
        यदि ((पूर्णाङ्क) op->e.v >= -0x1000 && (पूर्णाङ्क) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } अन्यथा यदि (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        यदि (op->e.sym->type.t & VT_STATIC)
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_PCREL_HI20, 0);
        अन्यथा
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_GOT_HI20, 0);
        put_extern_sym(&label, cur_text_section, ind, 0);
        greloca(cur_text_section, &label, ind+4, R_RISCV_PCREL_LO12_I, 0);

        op->type = OP_IM12S;
        op->e.v = 0;
    } अन्यथा {
        expect("operand");
    }
}

स्थिर शून्य parse_branch_offset_operand(TCCState *s1, Operand *op){
    अभिव्यक्ति_मान e = {0};

    asm_अभिव्यक्ति(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    यदि (!op->e.sym) {
        यदि ((पूर्णाङ्क) op->e.v >= -0x1000 && (पूर्णाङ्क) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } अन्यथा यदि (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } अन्यथा {
        expect("operand");
    }
}

स्थिर शून्य parse_jump_offset_operand(TCCState *s1, Operand *op){
    अभिव्यक्ति_मान e = {0};

    asm_अभिव्यक्ति(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    यदि (!op->e.sym) {
        यदि ((पूर्णाङ्क) op->e.v >= -0x1000 && (पूर्णाङ्क) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } अन्यथा यदि (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_text_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } अन्यथा {
        expect("operand");
    }
}

स्थिर शून्य parse_operands(TCCState *s1, Operand* ops, पूर्णाङ्क गन्ती_2){
    पूर्णाङ्क i;
    लागि (i = 0; i < गन्ती_2; i++) {
        यदि ( i != 0 )
            skip(',');
        parse_operand(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
स्थिर शून्य parse_mem_access_operands(TCCState *s1, Operand* ops){

    Operand op;

    parse_operand(s1, &ops[0]);
    skip(',');
    यदि ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } अन्यथा {
        parse_operand(s1, &ops[2]);
        यदि ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } अन्यथा {
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
स्थिर शून्य asm_jal_opcode(TCCState *s1, पूर्णाङ्क token){
    Operand ops[2];

    यदि (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } अन्यथा यदि (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } अन्यथा {
        // jal reg, offset
        parse_operand(s1, &ops[0]);
        यदि ( tok == ',') next(); अन्यथा expect("','");
    }
    parse_jump_offset_operand(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
स्थिर शून्य asm_jalr_opcode(TCCState *s1, पूर्णाङ्क token){
    Operand ops[3];
    Operand op;

    parse_operand(s1, &ops[0]);
    यदि ( tok == ',')
        next();
    अन्यथा {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        फर्काऊ;
    }

    यदि ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } अन्यथा {
        parse_operand(s1, &ops[2]);
        यदि ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } अन्यथा {
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


स्थिर शून्य asm_unary_opcode(TCCState *s1, पूर्णाङ्क token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    Operand op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    विकल्प (token) {
    /* pseudoinstructions */
    पक्ष TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        फर्काऊ;
    पक्ष TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        फर्काऊ;
    पक्ष TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        फर्काऊ;
    पक्ष TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        फर्काऊ;
    पक्ष TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        फर्काऊ;
    पक्ष TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        फर्काऊ;
    पक्ष TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        फर्काऊ;
    पक्ष TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        फर्काऊ;
    पक्ष TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        फर्काऊ;

    पक्ष TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        फर्काऊ;
    पक्ष TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        फर्काऊ;
    पक्ष TOK_ASM_tail:
        /* auipc x6, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        फर्काऊ;

    /* C extension */
    पक्ष TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        फर्काऊ;
    पक्ष TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        फर्काऊ;
    पक्ष TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        फर्काऊ;
    पक्ष TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        फर्काऊ;

    स्वभाव:
        expect("unary instruction");
    }
}

स्थिर शून्य asm_emit_u(पूर्णाङ्क token, uint32_t opcode, अचर Operand* rd, अचर Operand* rs2)
{
    यदि (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }
    यदि (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, रिक्त));
    } अन्यथा यदि (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, रिक्त));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

स्थिर पूर्णाङ्क parse_fence_operand(){
    पूर्णाङ्क t = tok;
    यदि ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    next();
    फर्काऊ t - (TOK_ASM_w_fence - 1);
}

स्थिर शून्य asm_fence_opcode(TCCState *s1, पूर्णाङ्क token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    पूर्णाङ्क succ = 0xF, pred = 0xF;
    यदि (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_operand();
        यदि ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, रिक्त));
        }
        skip(',');
        succ = parse_fence_operand();
        यदि ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, रिक्त));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

स्थिर शून्य asm_द्विआधारी_opcode(TCCState* s1, पूर्णाङ्क token)
{
    Operand imm = { OP_IM12S };
    Operand ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    विकल्प (token) {
    पक्ष TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        फर्काऊ;

    /* C extension */
    पक्ष TOK_ASM_c_add:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        फर्काऊ;

    पक्ष TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        फर्काऊ;

    पक्ष TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        फर्काऊ;

#define CA (1 | (3 << 10) | (4 << 13))
    पक्ष TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        फर्काऊ;
#undef CA

    पक्ष TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        फर्काऊ;

    पक्ष TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        फर्काऊ;

    /* F/D extension */
    पक्ष TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        फर्काऊ;

    /* pseudoinstructions */
    /* rd, sym */
    पक्ष TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_li:
        यदि(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, रिक्त));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        यदि(lo < 0){
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
        फर्काऊ;
    पक्ष TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        फर्काऊ;
    पक्ष TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        फर्काऊ;
    पक्ष TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        फर्काऊ;
    पक्ष TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        फर्काऊ;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    पक्ष TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_text_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        फर्काऊ;
    पक्ष TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        फर्काऊ;
    पक्ष TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        फर्काऊ;
    पक्ष TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        फर्काऊ;

    पक्ष TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        फर्काऊ;

    /* CSR pseudo-instructions */
    पक्ष TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        फर्काऊ;
    पक्ष TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        फर्काऊ;
    पक्ष TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        फर्काऊ;
    पक्ष TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        फर्काऊ;
    पक्ष TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        फर्काऊ;
    पक्ष TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        फर्काऊ;
    पक्ष TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        फर्काऊ;
    पक्ष TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        फर्काऊ;
    पक्ष TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        फर्काऊ;
    स्वभाव:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
स्थिर शून्य asm_emit_r(पूर्णाङ्क token, uint32_t opcode, अचर Operand* rd, अचर Operand* rs1, अचर Operand* rs2)
{
    यदि (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }
    यदि (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, रिक्त));
    }
    यदि (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, रिक्त));
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
स्थिर शून्य asm_emit_f(पूर्णाङ्क token, uint32_t opcode, अचर Operand* rd, अचर Operand* rs1, अचर Operand* rs2)
{
    यदि (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, रिक्त));
    }
    यदि (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, रिक्त));
    }
    यदि (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, रिक्त));
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
स्थिर शून्य asm_emit_fb(पूर्णाङ्क token, uint32_t opcode, अचर Operand* rd, अचर Operand* rs)
{
    यदि (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, रिक्त));
    }
    यदि (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, रिक्त));
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
स्थिर शून्य asm_emit_fq(पूर्णाङ्क token, uint32_t opcode, अचर Operand* rd, अचर Operand* rs1, अचर Operand* rs2, अचर Operand* rs3)
{
    यदि (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, रिक्त));
    }
    यदि (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, रिक्त));
    }
    यदि (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, रिक्त));
    }
    यदि (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, रिक्त));
    }
    /* F-type instruction:
	     31...27 rs3
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (REG_मान(rs3->reg) << 27));
}

/* caller: Add funct3 into opcode */
स्थिर शून्य asm_emit_i(पूर्णाङ्क token, uint32_t opcode, अचर Operand* rd, अचर Operand* rs1, अचर Operand* rs2)
{
    यदि (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }
    यदि (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, रिक्त));
    }
    यदि (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, रिक्त));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

स्थिर शून्य asm_emit_j(पूर्णाङ्क token, uint32_t opcode, अचर Operand* rd, अचर Operand* rs2)
{
    uint32_t imm;

    यदि (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }
    यदि (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, रिक्त));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    यदि ((पूर्णाङ्क)imm > (1 << 20) -1 || (पूर्णाङ्क)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, रिक्त));
    }

    यदि (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, रिक्त));
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

स्थिर शून्य asm_mem_access_opcode(TCCState *s1, पूर्णाङ्क token)
{

    Operand ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    यदि (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    विकल्प (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    पक्ष TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    पक्ष TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         फर्काऊ;
    }
}

स्थिर शून्य asm_branch_opcode(TCCState *s1, पूर्णाङ्क token, पूर्णाङ्क argc)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_offset_operand(s1, &ops[argc-1]);

    विकल्प(token){
    /* branch (RS1, RS2, IMM); B-format */
    पक्ष TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    /* related pseudoinstructions */
    पक्ष TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        फर्काऊ;
    /* shorter pseudoinstructions */
    पक्ष TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        फर्काऊ;
    पक्ष TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        फर्काऊ;
    }
}

स्थिर शून्य asm_ternary_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], 3);

    विकल्प (token) {
    पक्ष TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;
    पक्ष TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        फर्काऊ;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    पक्ष TOK_ASM_add:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    पक्ष TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    पक्ष TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;
    पक्ष TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         फर्काऊ;

    /* M extension */
    पक्ष TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        फर्काऊ;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    पक्ष TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        फर्काऊ;
    पक्ष TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        फर्काऊ;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    पक्ष TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        फर्काऊ;

    /* F/D extension */
    पक्ष TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;
    पक्ष TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        फर्काऊ;

    /* F/D comparison: produce integer result, encode manually */
    पक्ष TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        फर्काऊ;
    पक्ष TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        फर्काऊ;
    पक्ष TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        फर्काऊ;
    पक्ष TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        फर्काऊ;
    पक्ष TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        फर्काऊ;
    पक्ष TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        फर्काऊ;

    स्वभाव:
        expect("ternary instruction");
    }
}

स्थिर शून्य asm_quaternary_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[4];
    parse_operands(s1, &ops[0], 4);

    विकल्प (token) {
    पक्ष TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        फर्काऊ;
    पक्ष TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        फर्काऊ;

    स्वभाव:
        expect("quaternary instruction");
    }
}

स्थिर शून्य asm_atomic_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];

    parse_operand(s1, &ops[0]);
    skip(',');

    यदि ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } अन्यथा {
        parse_operand(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_operand(s1, &ops[2]);
    skip(')');

    विकल्प(token){
        पक्ष TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            रोक;
        पक्ष TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            रोक;
        पक्ष TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            रोक;
        पक्ष TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            रोक;

        पक्ष TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            रोक;
        पक्ष TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            रोक;
        पक्ष TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            रोक;
        पक्ष TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            रोक;

        पक्ष TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            रोक;
        पक्ष TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            रोक;
        पक्ष TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            रोक;
        पक्ष TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            रोक;

        पक्ष TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            रोक;
        पक्ष TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            रोक;
        पक्ष TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            रोक;
        पक्ष TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            रोक;

        /* AMO instructions (base, aq=0 rl=0) */
        पक्ष TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;
        पक्ष TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); रोक;

        /* AMO aq/rl variants */
        पक्ष TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;

        पक्ष TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
        पक्ष TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); रोक;
        पक्ष TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); रोक;
        पक्ष TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); रोक;
    }
}

/* caller: Add funct3 and func5 to opcode */
स्थिर शून्य asm_emit_a(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rd1, अचर Operand *rs2, अचर Operand *rs1, पूर्णाङ्क aq, पूर्णाङ्क rl)
{
    यदि (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, रिक्त));
    यदि (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, रिक्त));
    यदि (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, रिक्त));
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
स्थिर शून्य asm_emit_s(पूर्णाङ्क token, uint32_t opcode, अचर Operand* rs1, अचर Operand* rs2, अचर Operand* imm)
{
    यदि (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, रिक्त));
    }
    यदि (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, रिक्त));
    }
    यदि (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, रिक्त));
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

स्थिर शून्य asm_emit_b(पूर्णाङ्क token, uint32_t opcode, अचर Operand *rs1, अचर Operand *rs2, अचर Operand *imm)
{
    uint32_t offset;

    यदि (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, रिक्त));
    }
    यदि (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }
    यदि (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        पूर्णाङ्क b_ofs = ind;
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
        फर्काऊ;
    }
    यदि (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, रिक्त));
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
स्थिर पूर्णाङ्क asm_fcvt_rm(TCCState *s1)
{
    पूर्णाङ्क rm = 7; /* dynamic */
    यदि (tok == ',') {
        next();
        विकल्प (tok) {
            पक्ष TOK_ASM_rne: rm = 0; next(); रोक;
            पक्ष TOK_ASM_rtz: rm = 1; next(); रोक;
            पक्ष TOK_ASM_rdn: rm = 2; next(); रोक;
            पक्ष TOK_ASM_rup: rm = 3; next(); रोक;
            पक्ष TOK_ASM_rmm: rm = 4; next(); रोक;
            स्वभाव: expect("rounding mode"); रोक;
        }
    }
    फर्काऊ rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
स्थिर शून्य asm_fcvt_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[2];
    पूर्णाङ्क rm;
    uint32_t enc = 0;

    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);

    विकल्प (token) {
        पक्ष TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); रोक;
        पक्ष TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); रोक;
        पक्ष TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); रोक;
        पक्ष TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); रोक;
        पक्ष TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); रोक;
        पक्ष TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); रोक;
        पक्ष TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); रोक;
        पक्ष TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); रोक;
        पक्ष TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); रोक;
        पक्ष TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); रोक;
        पक्ष TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); रोक;
        पक्ष TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); रोक;
        पक्ष TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); रोक;
        पक्ष TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); रोक;
        पक्ष TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); रोक;
        पक्ष TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); रोक;
        पक्ष TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); रोक;
        पक्ष TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); रोक;
        पक्ष TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); रोक;
        पक्ष TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); रोक;
        स्वभाव: expect("fcvt/fclass instruction"); फर्काऊ;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC शून्य asm_opcode(TCCState *s1, पूर्णाङ्क token)
{
    विकल्प (token) {
    पक्ष TOK_ASM_ebreak:
    पक्ष TOK_ASM_ecall:
    पक्ष TOK_ASM_fence_i:
    पक्ष TOK_ASM_hrts:
    पक्ष TOK_ASM_mrth:
    पक्ष TOK_ASM_mrts:
    पक्ष TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        फर्काऊ;

    पक्ष TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        फर्काऊ;

    पक्ष TOK_ASM_rdcycle:
    पक्ष TOK_ASM_rdcycleh:
    पक्ष TOK_ASM_rdtime:
    पक्ष TOK_ASM_rdtimeh:
    पक्ष TOK_ASM_rdinstret:
    पक्ष TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        फर्काऊ;

    पक्ष TOK_ASM_lui:
    पक्ष TOK_ASM_auipc:
    पक्ष TOK_ASM_fsqrt_s:
    पक्ष TOK_ASM_fsqrt_d:
        asm_द्विआधारी_opcode(s1, token);
        फर्काऊ;

    /* fcvt/fclass — separate handler for optional rounding operand */
    पक्ष TOK_ASM_fcvt_w_s:
    पक्ष TOK_ASM_fcvt_wu_s:
    पक्ष TOK_ASM_fcvt_l_s:
    पक्ष TOK_ASM_fcvt_lu_s:
    पक्ष TOK_ASM_fcvt_s_w:
    पक्ष TOK_ASM_fcvt_s_wu:
    पक्ष TOK_ASM_fcvt_s_l:
    पक्ष TOK_ASM_fcvt_s_lu:
    पक्ष TOK_ASM_fcvt_w_d:
    पक्ष TOK_ASM_fcvt_wu_d:
    पक्ष TOK_ASM_fcvt_l_d:
    पक्ष TOK_ASM_fcvt_lu_d:
    पक्ष TOK_ASM_fcvt_d_w:
    पक्ष TOK_ASM_fcvt_d_wu:
    पक्ष TOK_ASM_fcvt_d_l:
    पक्ष TOK_ASM_fcvt_d_lu:
    पक्ष TOK_ASM_fcvt_s_d:
    पक्ष TOK_ASM_fcvt_d_s:
    पक्ष TOK_ASM_fclass_s:
    पक्ष TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        फर्काऊ;

    पक्ष TOK_ASM_lb:
    पक्ष TOK_ASM_lh:
    पक्ष TOK_ASM_lw:
    पक्ष TOK_ASM_ld:
    पक्ष TOK_ASM_fld:
    पक्ष TOK_ASM_lbu:
    पक्ष TOK_ASM_lhu:
    पक्ष TOK_ASM_lwu:
    पक्ष TOK_ASM_sb:
    पक्ष TOK_ASM_sh:
    पक्ष TOK_ASM_sw:
    पक्ष TOK_ASM_sd:
    पक्ष TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        रोक;

    पक्ष TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        रोक;
    पक्ष TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        फर्काऊ;
    पक्ष TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        रोक;

    पक्ष TOK_ASM_add:
    पक्ष TOK_ASM_addi:
    पक्ष TOK_ASM_addiw:
    पक्ष TOK_ASM_addw:
    पक्ष TOK_ASM_and:
    पक्ष TOK_ASM_andi:
    पक्ष TOK_ASM_or:
    पक्ष TOK_ASM_ori:
    पक्ष TOK_ASM_sll:
    पक्ष TOK_ASM_slli:
    पक्ष TOK_ASM_slliw:
    पक्ष TOK_ASM_sllw:
    पक्ष TOK_ASM_slt:
    पक्ष TOK_ASM_slti:
    पक्ष TOK_ASM_sltiu:
    पक्ष TOK_ASM_sltu:
    पक्ष TOK_ASM_sra:
    पक्ष TOK_ASM_srai:
    पक्ष TOK_ASM_sraiw:
    पक्ष TOK_ASM_sraw:
    पक्ष TOK_ASM_srl:
    पक्ष TOK_ASM_srli:
    पक्ष TOK_ASM_srliw:
    पक्ष TOK_ASM_srlw:
    पक्ष TOK_ASM_sub:
    पक्ष TOK_ASM_subw:
    पक्ष TOK_ASM_xor:
    पक्ष TOK_ASM_xori:
    /* M extension */
    पक्ष TOK_ASM_div:
    पक्ष TOK_ASM_divu:
    पक्ष TOK_ASM_divuw:
    पक्ष TOK_ASM_divw:
    पक्ष TOK_ASM_mul:
    पक्ष TOK_ASM_mulh:
    पक्ष TOK_ASM_mulhsu:
    पक्ष TOK_ASM_mulhu:
    पक्ष TOK_ASM_mulw:
    पक्ष TOK_ASM_rem:
    पक्ष TOK_ASM_remu:
    पक्ष TOK_ASM_remuw:
    पक्ष TOK_ASM_remw:
    /* Zicsr extension */
    पक्ष TOK_ASM_csrrc:
    पक्ष TOK_ASM_csrrci:
    पक्ष TOK_ASM_csrrs:
    पक्ष TOK_ASM_csrrsi:
    पक्ष TOK_ASM_csrrw:
    पक्ष TOK_ASM_csrrwi:
    /* F/D extension */
    पक्ष TOK_ASM_fadd_s:
    पक्ष TOK_ASM_fadd_d:
    पक्ष TOK_ASM_fsub_s:
    पक्ष TOK_ASM_fsub_d:
    पक्ष TOK_ASM_fmul_s:
    पक्ष TOK_ASM_fmul_d:
    पक्ष TOK_ASM_fdiv_s:
    पक्ष TOK_ASM_fdiv_d:
    पक्ष TOK_ASM_fsgnj_d:
    पक्ष TOK_ASM_fsgnj_s:
    पक्ष TOK_ASM_fmax_s:
    पक्ष TOK_ASM_fmax_d:
    पक्ष TOK_ASM_fmin_s:
    पक्ष TOK_ASM_fmin_d:
    पक्ष TOK_ASM_feq_s:
    पक्ष TOK_ASM_feq_d:
    पक्ष TOK_ASM_flt_s:
    पक्ष TOK_ASM_flt_d:
    पक्ष TOK_ASM_fle_s:
    पक्ष TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        फर्काऊ;
    पक्ष TOK_ASM_fmadd_d:
    पक्ष TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        फर्काऊ;

    /* Branches */
    पक्ष TOK_ASM_beq:
    पक्ष TOK_ASM_bge:
    पक्ष TOK_ASM_bgeu:
    पक्ष TOK_ASM_blt:
    पक्ष TOK_ASM_bltu:
    पक्ष TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        रोक;

    /* C extension */
    पक्ष TOK_ASM_c_ebreak:
    पक्ष TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        फर्काऊ;

    पक्ष TOK_ASM_c_j:
    पक्ष TOK_ASM_c_jal:
    पक्ष TOK_ASM_c_jalr:
    पक्ष TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        फर्काऊ;

    पक्ष TOK_ASM_c_add:
    पक्ष TOK_ASM_c_addi16sp:
    पक्ष TOK_ASM_c_addi4spn:
    पक्ष TOK_ASM_c_addi:
    पक्ष TOK_ASM_c_addiw:
    पक्ष TOK_ASM_c_addw:
    पक्ष TOK_ASM_c_and:
    पक्ष TOK_ASM_c_andi:
    पक्ष TOK_ASM_c_beqz:
    पक्ष TOK_ASM_c_bnez:
    पक्ष TOK_ASM_c_fldsp:
    पक्ष TOK_ASM_c_flwsp:
    पक्ष TOK_ASM_c_fsdsp:
    पक्ष TOK_ASM_c_fswsp:
    पक्ष TOK_ASM_c_ldsp:
    पक्ष TOK_ASM_c_li:
    पक्ष TOK_ASM_c_lui:
    पक्ष TOK_ASM_c_lwsp:
    पक्ष TOK_ASM_c_mv:
    पक्ष TOK_ASM_c_or:
    पक्ष TOK_ASM_c_sdsp:
    पक्ष TOK_ASM_c_slli:
    पक्ष TOK_ASM_c_srai:
    पक्ष TOK_ASM_c_srli:
    पक्ष TOK_ASM_c_sub:
    पक्ष TOK_ASM_c_subw:
    पक्ष TOK_ASM_c_swsp:
    पक्ष TOK_ASM_c_xor:
        asm_द्विआधारी_opcode(s1, token);
        फर्काऊ;

    पक्ष TOK_ASM_c_fld:
    पक्ष TOK_ASM_c_flw:
    पक्ष TOK_ASM_c_fsd:
    पक्ष TOK_ASM_c_fsw:
    पक्ष TOK_ASM_c_ld:
    पक्ष TOK_ASM_c_lw:
    पक्ष TOK_ASM_c_sd:
    पक्ष TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        फर्काऊ;

    /* pseudoinstructions */
    पक्ष TOK_ASM_nop:
    पक्ष TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        फर्काऊ;

    पक्ष TOK_ASM_jr:
    पक्ष TOK_ASM_call:
    पक्ष TOK_ASM_tail:
    पक्ष TOK_ASM_frflags:
    पक्ष TOK_ASM_frrm:
    पक्ष TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        फर्काऊ;

    पक्ष TOK_ASM_la:
    पक्ष TOK_ASM_lla:
    पक्ष TOK_ASM_li:
    पक्ष TOK_ASM_jump:
    पक्ष TOK_ASM_seqz:
    पक्ष TOK_ASM_snez:
    पक्ष TOK_ASM_sltz:
    पक्ष TOK_ASM_sgtz:
    पक्ष TOK_ASM_mv:
    पक्ष TOK_ASM_not:
    पक्ष TOK_ASM_neg:
    पक्ष TOK_ASM_negw:
    पक्ष TOK_ASM_sext_w:
    पक्ष TOK_ASM_fabs_s:
    पक्ष TOK_ASM_fabs_d:
    पक्ष TOK_ASM_fmv_s:
    पक्ष TOK_ASM_fmv_d:
    पक्ष TOK_ASM_fneg_s:
    पक्ष TOK_ASM_fneg_d:
    पक्ष TOK_ASM_csrc:
    पक्ष TOK_ASM_csrs:
    पक्ष TOK_ASM_csrr:
    पक्ष TOK_ASM_csrw:
    पक्ष TOK_ASM_csrwi:
    पक्ष TOK_ASM_csrsi:
    पक्ष TOK_ASM_csrci:
    पक्ष TOK_ASM_fsrm:
    पक्ष TOK_ASM_fscsr:
        asm_द्विआधारी_opcode(s1, token);
        फर्काऊ;

    पक्ष TOK_ASM_bnez:
    पक्ष TOK_ASM_beqz:
    पक्ष TOK_ASM_blez:
    पक्ष TOK_ASM_bgez:
    पक्ष TOK_ASM_bltz:
    पक्ष TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        फर्काऊ;

    पक्ष TOK_ASM_bgt:
    पक्ष TOK_ASM_bgtu:
    पक्ष TOK_ASM_ble:
    पक्ष TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        फर्काऊ;

    /* Atomic operations */
    पक्ष TOK_ASM_lr_w:
    पक्ष TOK_ASM_lr_w_aq:
    पक्ष TOK_ASM_lr_w_rl:
    पक्ष TOK_ASM_lr_w_aqrl:
    पक्ष TOK_ASM_lr_d:
    पक्ष TOK_ASM_lr_d_aq:
    पक्ष TOK_ASM_lr_d_rl:
    पक्ष TOK_ASM_lr_d_aqrl:
    पक्ष TOK_ASM_sc_w:
    पक्ष TOK_ASM_sc_w_aq:
    पक्ष TOK_ASM_sc_w_rl:
    पक्ष TOK_ASM_sc_w_aqrl:
    पक्ष TOK_ASM_sc_d:
    पक्ष TOK_ASM_sc_d_aq:
    पक्ष TOK_ASM_sc_d_rl:
    पक्ष TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    पक्ष TOK_ASM_amoadd_w:
    पक्ष TOK_ASM_amoadd_d:
    पक्ष TOK_ASM_amoswap_w:
    पक्ष TOK_ASM_amoswap_d:
    पक्ष TOK_ASM_amoand_w:
    पक्ष TOK_ASM_amoand_d:
    पक्ष TOK_ASM_amoor_w:
    पक्ष TOK_ASM_amoor_d:
    पक्ष TOK_ASM_amoxor_w:
    पक्ष TOK_ASM_amoxor_d:
    पक्ष TOK_ASM_amomax_w:
    पक्ष TOK_ASM_amomax_d:
    पक्ष TOK_ASM_amomaxu_w:
    पक्ष TOK_ASM_amomaxu_d:
    पक्ष TOK_ASM_amomin_w:
    पक्ष TOK_ASM_amomin_d:
    पक्ष TOK_ASM_amominu_w:
    पक्ष TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    पक्ष TOK_ASM_amoadd_w_aq:
    पक्ष TOK_ASM_amoadd_w_rl:
    पक्ष TOK_ASM_amoadd_w_aqrl:
    पक्ष TOK_ASM_amoadd_d_aq:
    पक्ष TOK_ASM_amoadd_d_rl:
    पक्ष TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    पक्ष TOK_ASM_amoswap_w_aq:
    पक्ष TOK_ASM_amoswap_w_rl:
    पक्ष TOK_ASM_amoswap_w_aqrl:
    पक्ष TOK_ASM_amoswap_d_aq:
    पक्ष TOK_ASM_amoswap_d_rl:
    पक्ष TOK_ASM_amoswap_d_aqrl:
    पक्ष TOK_ASM_amoand_w_aq:
    पक्ष TOK_ASM_amoand_w_rl:
    पक्ष TOK_ASM_amoand_w_aqrl:
    पक्ष TOK_ASM_amoand_d_aq:
    पक्ष TOK_ASM_amoand_d_rl:
    पक्ष TOK_ASM_amoand_d_aqrl:
    पक्ष TOK_ASM_amoor_w_aq:
    पक्ष TOK_ASM_amoor_w_rl:
    पक्ष TOK_ASM_amoor_w_aqrl:
    पक्ष TOK_ASM_amoor_d_aq:
    पक्ष TOK_ASM_amoor_d_rl:
    पक्ष TOK_ASM_amoor_d_aqrl:
    पक्ष TOK_ASM_amoxor_w_aq:
    पक्ष TOK_ASM_amoxor_w_rl:
    पक्ष TOK_ASM_amoxor_w_aqrl:
    पक्ष TOK_ASM_amoxor_d_aq:
    पक्ष TOK_ASM_amoxor_d_rl:
    पक्ष TOK_ASM_amoxor_d_aqrl:
    पक्ष TOK_ASM_amomax_w_aq:
    पक्ष TOK_ASM_amomax_w_rl:
    पक्ष TOK_ASM_amomax_w_aqrl:
    पक्ष TOK_ASM_amomax_d_aq:
    पक्ष TOK_ASM_amomax_d_rl:
    पक्ष TOK_ASM_amomax_d_aqrl:
    पक्ष TOK_ASM_amomaxu_w_aq:
    पक्ष TOK_ASM_amomaxu_w_rl:
    पक्ष TOK_ASM_amomaxu_w_aqrl:
    पक्ष TOK_ASM_amomaxu_d_aq:
    पक्ष TOK_ASM_amomaxu_d_rl:
    पक्ष TOK_ASM_amomaxu_d_aqrl:
    पक्ष TOK_ASM_amomin_w_aq:
    पक्ष TOK_ASM_amomin_w_rl:
    पक्ष TOK_ASM_amomin_w_aqrl:
    पक्ष TOK_ASM_amomin_d_aq:
    पक्ष TOK_ASM_amomin_d_rl:
    पक्ष TOK_ASM_amomin_d_aqrl:
    पक्ष TOK_ASM_amominu_w_aq:
    पक्ष TOK_ASM_amominu_w_rl:
    पक्ष TOK_ASM_amominu_w_aqrl:
    पक्ष TOK_ASM_amominu_d_aq:
    पक्ष TOK_ASM_amominu_d_rl:
    पक्ष TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        रोक;

    स्वभाव:
        expect("known instruction");
    }
}

स्थिर पूर्णाङ्क asm_parse_csrvar(पूर्णाङ्क t)
{
    विकल्प (t) {
    पक्ष TOK_ASM_cycle:
        फर्काऊ 0xc00;
    पक्ष TOK_ASM_fcsr:
        फर्काऊ 3;
    पक्ष TOK_ASM_fflags:
        फर्काऊ 1;
    पक्ष TOK_ASM_frm:
        फर्काऊ 2;
    पक्ष TOK_ASM_instret:
        फर्काऊ 0xc02;
    पक्ष TOK_ASM_time:
        फर्काऊ 0xc01;
    पक्ष TOK_ASM_cycleh:
        फर्काऊ 0xc80;
    पक्ष TOK_ASM_instreth:
        फर्काऊ 0xc82;
    पक्ष TOK_ASM_timeh:
        फर्काऊ 0xc81;
    स्वभाव:
        फर्काऊ -1;
    }
}

ST_FUNC शून्य subst_asm_operand(CString *add_str, SValue *sv, पूर्णाङ्क modifier)
{
    पूर्णाङ्क r, reg, val;

    r = sv->r;
    यदि ((r & VT_VALMASK) == VT_CONST) {
        यदि (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        यदि (r & VT_SYM) {
            अचर वर्ण *name = get_tok_str(sv->sym->v, रिक्त);
            यदि (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, म_माप(name))->tok, sv->sym);
            }
            यदि (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            यदि ((uint32_t) sv->c.i == 0)
                गच्छ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        यदि (modifier == 'n')
            val = -val;
        यदि (modifier == 'z' && val == 0) {
            cstr_cat(add_str, "zero", -1);
        } अन्यथा {
            cstr_printf(add_str, "%d", val);
        }
      no_offset:;
    } अन्यथा यदि ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d", (पूर्णाङ्क) sv->c.i);
    } अन्यथा यदि (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        यदि (reg >= VT_CONST)
            tcc_internal_error("");
        यदि ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_मान(reg);
        } अन्यथा {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, रिक्त), -1);
    } अन्यथा {
        /* register case */
        reg = r & VT_VALMASK;
        यदि (reg >= VT_CONST)
            tcc_internal_error("");
        यदि ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_मान(reg);
        } अन्यथा {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, रिक्त), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
स्थिर पूर्णाङ्क tcc_ireg(पूर्णाङ्क r){
    फर्काऊ REG_मान(r) - 10;
}
स्थिर पूर्णाङ्क tcc_freg(पूर्णाङ्क r){
    फर्काऊ REG_मान(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC शून्य asm_gen_code(ASMOperand *operands, पूर्णाङ्क nb_operands,
                         पूर्णाङ्क nb_outputs, पूर्णाङ्क is_output,
                         uint8_t *clobber_regs,
                         पूर्णाङ्क out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    पूर्णाङ्क i, reg;

    स्थिर अचर uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    स_नकल(regs_allocated, clobber_regs, परिमाण(regs_allocated));
    लागि(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        यदि (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    यदि(!is_output) {
        /* generate reg save code */
        लागि(i = 0; i < परिमाण(reg_saved)/परिमाण(reg_saved[0]); i++) {
            reg = reg_saved[i];
            यदि (regs_allocated[reg]) {
                /*थप*/
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (अचिन्हित)-8 << 20);
                यदि (REG_IS_FLOAT(reg)){
                    /* fsd reg, offset(sp) */
                    gen_le32( 0x27 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                } अन्यथा {
                    /* sd reg, offset(sp) */
                    gen_le32((0x8 << 2) | 3 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                }
            }
        }

        /* generate load code */
        लागि(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            यदि (op->reg >= 0) {
                यदि ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(tcc_ireg(op->reg), &sv);
                } अन्यथा यदि (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    यदि ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        load(tcc_freg(op->reg), op->vt);
                    } अन्यथा {
                        load(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register;
                       the load/store above already handles it correctly */
                }
            }
        }
    } अन्यथा {
        /* generate save code */
        लागि(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            यदि (op->reg >= 0) {
                यदि ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    यदि (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(tcc_ireg(out_reg), &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(tcc_ireg(op->reg), &sv);
                    }
                } अन्यथा {
                    यदि ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        store(tcc_freg(op->reg), op->vt);
                    } अन्यथा {
                        store(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register */
                }
            }
        }
        /* generate reg restore code for floating point registers */
        लागि(i = परिमाण(reg_saved)/परिमाण(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            यदि (regs_allocated[reg]) {
                /*झिक*/
                यदि (REG_IS_FLOAT(reg)){
                    /* fld reg, offset(sp) */
                    gen_le32(7 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                } अन्यथा {
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
स्थिर अन्तःस्थ पूर्णाङ्क constraint_priority(अचर वर्ण *str)
{
    // TODO: How is this chosen??
    पूर्णाङ्क priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    लागि(;;) {
        c = *str;
        यदि (c == '\0')
            रोक;
        str++;
        विकल्प(c) {
        पक्ष 'A': // address that is held in a general-purpose register.
        पक्ष 'S': // constraint that matches an absolute symbolic address.
        पक्ष 'f': // register [float]
        पक्ष 'r': // register [general]
        पक्ष 'p': // valid memory address for load,store [general]
            pr = 3;
            रोक;
        पक्ष 'I': // 12 bit signed immedate
        पक्ष 'i': // immediate integer operand, including symbolic constants [general]
        पक्ष 'm': // memory operand [general]
        पक्ष 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            रोक;
        पक्ष 'v':
            tcc_error("unimp: constraint '%c'", c);
        स्वभाव:
            tcc_error("unknown constraint '%d'", c);
        }
        यदि (pr > priority)
            priority = pr;
    }
    फर्काऊ priority;
}

स्थिर अचर वर्ण *skip_constraint_modifiers(अचर वर्ण *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    जबसम्म (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    फर्काऊ p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC शून्य asm_compute_constraints(ASMOperand *operands,
                                    पूर्णाङ्क nb_operands, पूर्णाङ्क nb_outputs,
                                    अचर uint8_t *clobber_regs,
                                    पूर्णाङ्क *pout_reg)
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
    पूर्णाङ्क sorted_op[MAX_ASM_OPERANDS];
    पूर्णाङ्क i, j, k, p1, p2, tmp, reg, c, reg_mask;
    अचर वर्ण *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    लागि (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->आगत_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    लागि (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        यदि (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, रिक्त);
            यदि ((अचिन्हित) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            यदि (operands[k].आगत_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].आगत_index = i;
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

    /* sort operands according to their priority */
    लागि (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    लागि (i = 0; i < nb_operands - 1; i++) {
        लागि (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            यदि (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    लागि (i = 0; i < NB_ASM_REGS; i++) {
        यदि (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        अन्यथा
            regs_allocated[i] = 0;
    }

    /* allocate registers and generate corresponding asm moves */
    लागि (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        यदि (op->ref_index >= 0)
            जारी;
        /* select if register is used for output, input or both */
        यदि (op->आगत_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अन्यथा यदि (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अन्यथा {
            reg_mask = REG_IN_MASK;
        }
        यदि (op->reg >= 0) {
            यदि (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        विकल्प (c) {
        पक्ष '=': // Operand is written-to
            गच्छ try_next;
        पक्ष '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        पक्ष '&': // Operand is clobbered before the instruction is done using the input operands
            यदि (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            गच्छ try_next;
        पक्ष 'r': // general-purpose register
        पक्ष 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            यदि ((reg = op->reg) >= 0)
                गच्छ reg_found;
            अन्यथा लागि (reg = 10; reg <= 18; reg++) {
                यदि (!is_reg_allocated(reg))
                    गच्छ reg_found;
            }
            गच्छ try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            रोक;
        पक्ष 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            यदि ((reg = op->reg) >= 0)
                गच्छ reg_found;
            अन्यथा लागि (reg = 42; reg <= 50; reg++) {
                यदि (!is_reg_allocated(reg))
                    गच्छ reg_found;
            }
            गच्छ try_next;
        पक्ष 'I': // I-Type 12 bit signed immediate
        पक्ष 'i': // immediate integer operand, including symbolic constants
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                गच्छ try_next;
            रोक;
        पक्ष 'm': // memory operand
        पक्ष 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            यदि (j < nb_outputs || c == 'm') {
                यदि ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    लागि (reg = 10; reg <= 18; reg++) {
                        यदि (!(regs_allocated[reg] & REG_IN_MASK))
                            गच्छ reg_found1;
                    }
                    गच्छ try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            रोक;
        स्वभाव:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            रोक;
        }
        /* if a reference is present for that operand, we assign it too */
        यदि (op->आगत_index >= 0) {
            operands[op->आगत_index].reg = op->reg;
            operands[op->आगत_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    लागि (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        यदि (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            यदि (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                लागि (reg = 42; reg <= 50; reg++) {
                    यदि (!(regs_allocated[reg] & REG_OUT_MASK))
                        गच्छ reg_found2;
                }
            } अन्यथा {
                /* From a0 to a7 */
                लागि (reg = 10; reg <= 18; reg++) {
                    यदि (!(regs_allocated[reg] & REG_OUT_MASK))
                        गच्छ reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            रोक;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    लागि (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        म_लिखो("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, रिक्त) : "",
               op->constraint, op->vt->r, op->reg);
    }
    यदि (*pout_reg >= 0)
        म_लिखो("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC शून्य asm_clobber(uint8_t *clobber_regs, अचर वर्ण *str)
{
    पूर्णाङ्क reg;
    TokenSym *ts;

    यदि (!म_भेद(str, "memory") ||
        !म_भेद(str, "cc") ||
        !म_भेद(str, "flags"))
        फर्काऊ;
    ts = tok_alloc(str, म_माप(str));
    reg = asm_parse_regvar(ts->tok);
    यदि (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC पूर्णाङ्क asm_parse_regvar (पूर्णाङ्क t)
{
    /* PC register not implemented */
    यदि (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        फर्काऊ -1;

    यदि (t < TOK_ASM_f0)
        फर्काऊ t - TOK_ASM_x0;

    यदि (t < TOK_ASM_zero)
        फर्काऊ t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    यदि (t < TOK_ASM_ft0)
        फर्काऊ t - TOK_ASM_zero;

    फर्काऊ t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
स्थिर शून्य asm_emit_ca(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rd, अचर Operand *rs2)
{
    uint8_t dst, src;

    यदि (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }

    यदि (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, रिक्त));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    यदि (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, रिक्त));
    }

    यदि (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, रिक्त));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

स्थिर शून्य asm_emit_cb(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rs1, अचर Operand *imm)
{
    uint32_t offset;
    uint8_t src;

    यदि (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, रिक्त));
    }

    यदि (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, रिक्त));
    }

    offset = imm->e.v;

    यदि (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, रिक्त));
    }

    src = rs1->reg - 8;

    यदि (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, रिक्त));
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

    विकल्प (token) {
    पक्ष TOK_ASM_c_beqz:
    पक्ष TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_BIT(offset, 5) | (((offset >> 1) & 3) << 1) | (((offset >> 6) & 3) << 3)) << 2) | ((((offset >> 3) & 3) | NTH_BIT(offset, 8)) << 10));
        फर्काऊ;
    स्वभाव:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((offset & 0x1f) << 2) | (NTH_BIT(offset, 5) << 12));
        फर्काऊ;
    }
}

स्थिर शून्य asm_emit_ci(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rd, अचर Operand *imm)
{
    uint32_t immediate;

    यदि (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }

    यदि (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, रिक्त));
    }

    immediate = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    विकल्प (token) {
    पक्ष TOK_ASM_c_addi:
    पक्ष TOK_ASM_c_addiw:
    पक्ष TOK_ASM_c_li:
    पक्ष TOK_ASM_c_slli:
        gen_le16(opcode | ((immediate & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        फर्काऊ;
    पक्ष TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_BIT(immediate, 5) << 2 | (((immediate >> 7) & 3) << 3) | NTH_BIT(immediate, 6) << 5 | NTH_BIT(immediate, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 9) << 12));
        फर्काऊ;
    पक्ष TOK_ASM_c_lui:
        gen_le16(opcode | (((immediate >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 17) << 12));
        फर्काऊ;
    पक्ष TOK_ASM_c_fldsp:
    पक्ष TOK_ASM_c_ldsp:
        gen_le16(opcode | (((immediate >> 6) & 7) << 2) | (((immediate >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        फर्काऊ;
    पक्ष TOK_ASM_c_flwsp:
    पक्ष TOK_ASM_c_lwsp:
        gen_le16(opcode | (((immediate >> 6) & 3) << 2) | (((immediate >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        फर्काऊ;
    पक्ष TOK_ASM_c_nop:
        gen_le16(opcode);
        फर्काऊ;
    स्वभाव:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
स्थिर शून्य asm_emit_ciw(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rd, अचर Operand *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    यदि (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }

    यदि (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, रिक्त));
    }

    dst = rd->reg - 8;

    यदि (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, रिक्त));
    }

    nzuimm = imm->e.v;

    यदि (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, रिक्त));
    }

    यदि (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, रिक्त));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_BIT(nzuimm, 3) | (NTH_BIT(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
स्थिर शून्य asm_emit_cj(पूर्णाङ्क token, uint16_t opcode, अचर Operand *imm)
{
    uint32_t offset;

    /* +-2 KiB range */
    यदि (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, रिक्त));
    }

    offset = imm->e.v;

    यदि (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, रिक्त));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_BIT(offset, 5) << 2) | (((offset >> 1) & 7) << 3) | (NTH_BIT(offset, 7) << 6) | (NTH_BIT(offset, 6) << 7) | (NTH_BIT(offset, 10) << 8) | (((offset >> 8) & 3) << 9) | (NTH_BIT(offset, 4) << 11) | (NTH_BIT(offset, 11) << 12));
}

/* caller: Add funct3 into opcode */
स्थिर शून्य asm_emit_cl(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rd, अचर Operand *rs1, अचर Operand *imm)
{
    uint32_t offset;
    uint8_t dst, src;

    यदि (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }

    यदि (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, रिक्त));
    }

    यदि (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, रिक्त));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    यदि (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, रिक्त));
    }

    यदि (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, रिक्त));
    }

    offset = imm->e.v;

    यदि (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, रिक्त));
    }

    यदि (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, रिक्त));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    विकल्प (token) {
    /* imm variant 1 */
    पक्ष TOK_ASM_c_flw:
    पक्ष TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        फर्काऊ;
    /* imm variant 2 */
    पक्ष TOK_ASM_c_fld:
    पक्ष TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        फर्काऊ;
    स्वभाव:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
स्थिर शून्य asm_emit_cr(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rd, अचर Operand *rs2)
{
    यदि (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }

    यदि (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, रिक्त));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
स्थिर शून्य asm_emit_cs(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rs2, अचर Operand *rs1, अचर Operand *imm)
{
    uint32_t offset;
    uint8_t base, src;

    यदि (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }

    यदि (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, रिक्त));
    }

    यदि (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, रिक्त));
    }

    base = rs1->reg - 8;
    src = rs2->reg - 8;

    यदि (base > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, रिक्त));
    }

    यदि (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, रिक्त));
    }

    offset = imm->e.v;

    यदि (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, रिक्त));
    }

    यदि (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, रिक्त));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    विकल्प (token) {
    /* imm variant 1 */
    पक्ष TOK_ASM_c_fsw:
    पक्ष TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        फर्काऊ;
    /* imm variant 2 */
    पक्ष TOK_ASM_c_fsd:
    पक्ष TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        फर्काऊ;
    स्वभाव:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
स्थिर शून्य asm_emit_css(पूर्णाङ्क token, uint16_t opcode, अचर Operand *rs2, अचर Operand *imm)
{
    uint32_t offset;

    यदि (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, रिक्त));
    }

    यदि (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, रिक्त));
    }

    offset = imm->e.v;

    यदि (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, रिक्त));
    }

    यदि (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, रिक्त));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    विकल्प (token) {
    /* imm variant 1 */
    पक्ष TOK_ASM_c_fswsp:
    पक्ष TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 3) << 7) | (((offset >> 2) & 0xf) << 9));
        फर्काऊ;
    /* imm variant 2 */
    पक्ष TOK_ASM_c_fsdsp:
    पक्ष TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 7) << 7) | (((offset >> 3) & 7) << 10));
        फर्काऊ;
    स्वभाव:
        expect("known instruction");
    }
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
