/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#अगर_घोषित TARGET_DEFS_ONLY

#घोषणा CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#घोषणा NB_ASM_REGS 64

ST_FUNC व्योम g(पूर्णांक c);
ST_FUNC व्योम gen_le16(पूर्णांक c);
ST_FUNC व्योम gen_le32(पूर्णांक c);

/*************************************************************/
#अन्यथा
/*************************************************************/
#घोषणा USING_GLOBALS
#समावेश "tcc.h"

क्रमागत {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#घोषणा REG_FLOAT_MASK 0x20
#घोषणा REG_IS_FLOAT(register_सूचकांक) ((register_सूचकांक) & REG_FLOAT_MASK)
#घोषणा REG_मूल्य(register_सूचकांक)    ((register_सूचकांक) & (REG_FLOAT_MASK-1))
#घोषणा C_ENCODE_RS1(register_सूचकांक) (REG_मूल्य(register_सूचकांक) << 7)
#घोषणा C_ENCODE_RS2(register_सूचकांक) (REG_मूल्य(register_सूचकांक) << 2)
#घोषणा ENCODE_RD(register_सूचकांक)  (REG_मूल्य(register_सूचकांक) << 7)
#घोषणा ENCODE_RS1(register_सूचकांक) (REG_मूल्य(register_सूचकांक) << 15)
#घोषणा ENCODE_RS2(register_सूचकांक) (REG_मूल्य(register_सूचकांक) << 20)
#घोषणा NTH_BIT(b, n) ((b >> n) & 1)
#घोषणा OP_IM12S (1 << OPT_IM12S)
#घोषणा OP_IM32 (1 << OPT_IM32)
#घोषणा OP_REG (1 << OPT_REG)

प्रकार काष्ठा Operand {
    uint32_t type;
    जोड़ {
        uint8_t reg;
        uint16_t regset;
        व्यंजक_मूल्य e;
    };
} Operand;

अटल स्थिर Operand zero = { OP_REG, { 0 }};
अटल स्थिर Operand ra = { OP_REG, { 1 }};
अटल स्थिर Operand zimm = { OP_IM12S };

अटल व्योम asm_द्विआधारी_opcode(TCCState* s1, पूर्णांक token);
ST_FUNC व्योम asm_clobber(uint8_t *clobber_regs, स्थिर अक्षर *str);
ST_FUNC व्योम asm_compute_constraints(ASMOperand *operands, पूर्णांक nb_operands, पूर्णांक nb_outputs, स्थिर uint8_t *clobber_regs, पूर्णांक *pout_reg);
अटल व्योम asm_emit_a(पूर्णांक token, uint32_t opcode, स्थिर Operand *rs1, स्थिर Operand *rs2, स्थिर Operand *rd1, पूर्णांक aq, पूर्णांक rl);
अटल व्योम asm_emit_b(पूर्णांक token, uint32_t opcode, स्थिर Operand *rs1, स्थिर Operand *rs2, स्थिर Operand *imm);
अटल व्योम asm_emit_i(पूर्णांक token, uint32_t opcode, स्थिर Operand *rd, स्थिर Operand *rs1, स्थिर Operand *rs2);
अटल व्योम asm_emit_j(पूर्णांक token, uint32_t opcode, स्थिर Operand *rd, स्थिर Operand *rs2);
अटल व्योम asm_emit_opcode(uint32_t opcode);
अटल व्योम asm_emit_r(पूर्णांक token, uint32_t opcode, स्थिर Operand *rd, स्थिर Operand *rs1, स्थिर Operand *rs2);
अटल व्योम asm_emit_s(पूर्णांक token, uint32_t opcode, स्थिर Operand *rs1, स्थिर Operand *rs2, स्थिर Operand *imm);
अटल व्योम asm_emit_u(पूर्णांक token, uint32_t opcode, स्थिर Operand *rd, स्थिर Operand *rs2);
अटल व्योम asm_emit_f(पूर्णांक token, uint32_t opcode, स्थिर Operand *rd, स्थिर Operand *rs1, स्थिर Operand *rs2);
अटल व्योम asm_emit_fb(पूर्णांक token, uint32_t opcode, स्थिर Operand *rd, स्थिर Operand *rs);
अटल व्योम asm_emit_fq(पूर्णांक token, uint32_t opcode, स्थिर Operand *rd, स्थिर Operand *rs1, स्थिर Operand *rs2, स्थिर Operand *rs3);
ST_FUNC व्योम asm_gen_code(ASMOperand *operands, पूर्णांक nb_operands, पूर्णांक nb_outputs, पूर्णांक is_output, uint8_t *clobber_regs, पूर्णांक out_reg);
अटल व्योम asm_nullary_opcode(TCCState *s1, पूर्णांक token);
ST_FUNC व्योम asm_opcode(TCCState *s1, पूर्णांक token);
अटल पूर्णांक asm_parse_csrvar(पूर्णांक t);
ST_FUNC पूर्णांक asm_parse_regvar(पूर्णांक t);
अटल व्योम asm_ternary_opcode(TCCState *s1, पूर्णांक token);
अटल व्योम asm_unary_opcode(TCCState *s1, पूर्णांक token);
अटल व्योम asm_branch_opcode(TCCState *s1, पूर्णांक token, पूर्णांक argc);
ST_FUNC व्योम gen_expr32(व्यंजक_मूल्य *pe);
अटल व्योम parse_operand(TCCState *s1, Operand *op);
अटल व्योम parse_branch_offset_operand(TCCState *s1, Operand *op);
अटल व्योम parse_operands(TCCState *s1, Operand *ops, पूर्णांक गिनती_2);
अटल व्योम parse_mem_access_operands(TCCState *s1, Operand* ops);
ST_FUNC व्योम subst_asm_operand(CString *add_str, SValue *sv, पूर्णांक modifier);
/* C extension */
अटल व्योम asm_emit_ca(पूर्णांक token, uint16_t opcode, स्थिर Operand *rd, स्थिर Operand *rs2);
अटल व्योम asm_emit_cb(पूर्णांक token, uint16_t opcode, स्थिर Operand *rs1, स्थिर Operand *imm);
अटल व्योम asm_emit_ci(पूर्णांक token, uint16_t opcode, स्थिर Operand *rd, स्थिर Operand *imm);
अटल व्योम asm_emit_ciw(पूर्णांक token, uint16_t opcode, स्थिर Operand *rd, स्थिर Operand *imm);
अटल व्योम asm_emit_cj(पूर्णांक token, uint16_t opcode, स्थिर Operand *imm);
अटल व्योम asm_emit_cl(पूर्णांक token, uint16_t opcode, स्थिर Operand *rd, स्थिर Operand *rs1, स्थिर Operand *imm);
अटल व्योम asm_emit_cr(पूर्णांक token, uint16_t opcode, स्थिर Operand *rd, स्थिर Operand *rs2);
अटल व्योम asm_emit_cs(पूर्णांक token, uint16_t opcode, स्थिर Operand *rs2, स्थिर Operand *rs1, स्थिर Operand *imm);
अटल व्योम asm_emit_css(पूर्णांक token, uint16_t opcode, स्थिर Operand *rs2, स्थिर Operand *imm);

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

ST_FUNC व्योम gen_le16 (पूर्णांक i)
{
    g(i);
    g(i>>8);
}

ST_FUNC व्योम gen_le32 (पूर्णांक i)
{
    पूर्णांक ind1;
    अगर (nocode_wanted)
        वापस;
    ind1 = ind + 4;
    अगर (ind1 > cur_text_section->तथ्य_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->तथ्य[ind++] = i & 0xFF;
    cur_text_section->तथ्य[ind++] = (i >> 8) & 0xFF;
    cur_text_section->तथ्य[ind++] = (i >> 16) & 0xFF;
    cur_text_section->तथ्य[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC व्योम gen_expr32(व्यंजक_मूल्य *pe)
{
    gen_le32(pe->v);
}

अटल व्योम asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

अटल व्योम asm_nullary_opcode(TCCState *s1, पूर्णांक token)
{
    चयन (token) {
    // Sync instructions

    हाल TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        वापस;

    // System calls

    हाल TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        वापस;
    हाल TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        वापस;

    // Other

    हाल TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        वापस;

    हाल TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        वापस;

    /* Pseudoinstructions */
    हाल TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        वापस;

    /* C extension */
    हाल TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        वापस;
    हाल TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        वापस;

    शेष:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
अटल व्योम parse_operand(TCCState *s1, Operand *op)
{
    व्यंजक_मूल्य e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    अगर ((reg = asm_parse_regvar(tok)) != -1) {
        अग्र(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        वापस;
    } अन्यथा अगर (tok == '$') {
        /* constant value */
        अग्र(); // skip '#' or '$'
    } अन्यथा अगर ((e.v = asm_parse_csrvar(tok)) != -1) {
        अग्र();
    } अन्यथा {
        asm_व्यंजक(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    अगर (!op->e.sym) {
        अगर ((पूर्णांक) op->e.v >= -0x1000 && (पूर्णांक) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } अन्यथा अगर (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        अगर (op->e.sym->type.t & VT_STATIC)
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

अटल व्योम parse_branch_offset_operand(TCCState *s1, Operand *op){
    व्यंजक_मूल्य e = {0};

    asm_व्यंजक(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    अगर (!op->e.sym) {
        अगर ((पूर्णांक) op->e.v >= -0x1000 && (पूर्णांक) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } अन्यथा अगर (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } अन्यथा {
        expect("operand");
    }
}

अटल व्योम parse_jump_offset_operand(TCCState *s1, Operand *op){
    व्यंजक_मूल्य e = {0};

    asm_व्यंजक(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    अगर (!op->e.sym) {
        अगर ((पूर्णांक) op->e.v >= -0x1000 && (पूर्णांक) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } अन्यथा अगर (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_text_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } अन्यथा {
        expect("operand");
    }
}

अटल व्योम parse_operands(TCCState *s1, Operand* ops, पूर्णांक गिनती_2){
    पूर्णांक i;
    क्रम (i = 0; i < गिनती_2; i++) {
        अगर ( i != 0 )
            skip(',');
        parse_operand(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
अटल व्योम parse_mem_access_operands(TCCState *s1, Operand* ops){

    Operand op;

    parse_operand(s1, &ops[0]);
    skip(',');
    अगर ( tok == '(') {
        /* `X, (Y)` case*/
        अग्र();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } अन्यथा {
        parse_operand(s1, &ops[2]);
        अगर ( tok == '('){
            /* `X, imm(Y)` case*/
            अग्र();
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
अटल व्योम asm_jal_opcode(TCCState *s1, पूर्णांक token){
    Operand ops[2];

    अगर (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } अन्यथा अगर (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } अन्यथा {
        // jal reg, offset
        parse_operand(s1, &ops[0]);
        अगर ( tok == ',') अग्र(); अन्यथा expect("','");
    }
    parse_jump_offset_operand(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
अटल व्योम asm_jalr_opcode(TCCState *s1, पूर्णांक token){
    Operand ops[3];
    Operand op;

    parse_operand(s1, &ops[0]);
    अगर ( tok == ',')
        अग्र();
    अन्यथा {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        वापस;
    }

    अगर ( tok == '(') {
        /* `X, (Y)` case*/
        अग्र();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } अन्यथा {
        parse_operand(s1, &ops[2]);
        अगर ( tok == '('){
            /* `X, imm(Y)` case*/
            अग्र();
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


अटल व्योम asm_unary_opcode(TCCState *s1, पूर्णांक token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    Operand op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    चयन (token) {
    /* pseudoinstructions */
    हाल TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        वापस;
    हाल TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        वापस;
    हाल TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        वापस;
    हाल TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        वापस;
    हाल TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        वापस;
    हाल TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        वापस;
    हाल TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        वापस;
    हाल TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        वापस;
    हाल TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        वापस;

    हाल TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        वापस;
    हाल TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        वापस;
    हाल TOK_ASM_पुच्छ:
        /* auipc x6, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        वापस;

    /* C extension */
    हाल TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        वापस;
    हाल TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        वापस;
    हाल TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        वापस;
    हाल TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        वापस;

    शेष:
        expect("unary instruction");
    }
}

अटल व्योम asm_emit_u(पूर्णांक token, uint32_t opcode, स्थिर Operand* rd, स्थिर Operand* rs2)
{
    अगर (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }
    अगर (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, शून्य));
    } अन्यथा अगर (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, शून्य));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

अटल पूर्णांक parse_fence_operand(){
    पूर्णांक t = tok;
    अगर ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    अग्र();
    वापस t - (TOK_ASM_w_fence - 1);
}

अटल व्योम asm_fence_opcode(TCCState *s1, पूर्णांक token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    पूर्णांक succ = 0xF, pred = 0xF;
    अगर (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_operand();
        अगर ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, शून्य));
        }
        skip(',');
        succ = parse_fence_operand();
        अगर ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, शून्य));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

अटल व्योम asm_द्विआधारी_opcode(TCCState* s1, पूर्णांक token)
{
    Operand imm = { OP_IM12S };
    Operand ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    चयन (token) {
    हाल TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        वापस;
    हाल TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        वापस;

    /* C extension */
    हाल TOK_ASM_c_add:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        वापस;

    हाल TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        वापस;

    हाल TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        वापस;

#घोषणा CA (1 | (3 << 10) | (4 << 13))
    हाल TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        वापस;
#अघोषित CA

    हाल TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        वापस;

    हाल TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        वापस;
    हाल TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        वापस;

    /* F/D extension */
    हाल TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        वापस;
    हाल TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        वापस;

    /* pseudoinstructions */
    /* rd, sym */
    हाल TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        वापस;
    हाल TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        वापस;
    हाल TOK_ASM_li:
        अगर(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, शून्य));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        अगर(lo < 0){
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
        वापस;
    हाल TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        वापस;
    हाल TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        वापस;
    हाल TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        वापस;
    हाल TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        वापस;
    हाल TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        वापस;
    हाल TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        वापस;
    हाल TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        वापस;
    हाल TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        वापस;
    हाल TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        वापस;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    हाल TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_text_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        वापस;
    हाल TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        वापस;
    हाल TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        वापस;
    हाल TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        वापस;
    हाल TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        वापस;

    हाल TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        वापस;
    हाल TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        वापस;

    /* CSR pseudo-instructions */
    हाल TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        वापस;
    हाल TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        वापस;
    हाल TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        वापस;
    हाल TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        वापस;
    हाल TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        वापस;
    हाल TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        वापस;
    हाल TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        वापस;
    हाल TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        वापस;
    हाल TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        वापस;
    शेष:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
अटल व्योम asm_emit_r(पूर्णांक token, uint32_t opcode, स्थिर Operand* rd, स्थिर Operand* rs1, स्थिर Operand* rs2)
{
    अगर (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }
    अगर (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, शून्य));
    }
    अगर (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, शून्य));
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
अटल व्योम asm_emit_f(पूर्णांक token, uint32_t opcode, स्थिर Operand* rd, स्थिर Operand* rs1, स्थिर Operand* rs2)
{
    अगर (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, शून्य));
    }
    अगर (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, शून्य));
    }
    अगर (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, शून्य));
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
अटल व्योम asm_emit_fb(पूर्णांक token, uint32_t opcode, स्थिर Operand* rd, स्थिर Operand* rs)
{
    अगर (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, शून्य));
    }
    अगर (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, शून्य));
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
अटल व्योम asm_emit_fq(पूर्णांक token, uint32_t opcode, स्थिर Operand* rd, स्थिर Operand* rs1, स्थिर Operand* rs2, स्थिर Operand* rs3)
{
    अगर (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, शून्य));
    }
    अगर (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, शून्य));
    }
    अगर (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, शून्य));
    }
    अगर (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, शून्य));
    }
    /* F-type instruction:
	     31...27 rs3
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (REG_मूल्य(rs3->reg) << 27));
}

/* caller: Add funct3 into opcode */
अटल व्योम asm_emit_i(पूर्णांक token, uint32_t opcode, स्थिर Operand* rd, स्थिर Operand* rs1, स्थिर Operand* rs2)
{
    अगर (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }
    अगर (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, शून्य));
    }
    अगर (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, शून्य));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

अटल व्योम asm_emit_j(पूर्णांक token, uint32_t opcode, स्थिर Operand* rd, स्थिर Operand* rs2)
{
    uint32_t imm;

    अगर (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }
    अगर (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, शून्य));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    अगर ((पूर्णांक)imm > (1 << 20) -1 || (पूर्णांक)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, शून्य));
    }

    अगर (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, शून्य));
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

अटल व्योम asm_mem_access_opcode(TCCState *s1, पूर्णांक token)
{

    Operand ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    अगर (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    चयन (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    हाल TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    हाल TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         वापस;
    हाल TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         वापस;
    हाल TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         वापस;
    हाल TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         वापस;
    हाल TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         वापस;
    }
}

अटल व्योम asm_branch_opcode(TCCState *s1, पूर्णांक token, पूर्णांक argc)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_offset_operand(s1, &ops[argc-1]);

    चयन(token){
    /* branch (RS1, RS2, IMM); B-format */
    हाल TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        वापस;
    /* related pseudoinstructions */
    हाल TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        वापस;
    हाल TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        वापस;
    हाल TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        वापस;
    हाल TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        वापस;
    /* shorter pseudoinstructions */
    हाल TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        वापस;
    हाल TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        वापस;
    हाल TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        वापस;
    हाल TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        वापस;
    हाल TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        वापस;
    हाल TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        वापस;
    }
}

अटल व्योम asm_ternary_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], 3);

    चयन (token) {
    हाल TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        वापस;
    हाल TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        वापस;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    हाल TOK_ASM_add:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         वापस;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    हाल TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    हाल TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;
    हाल TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         वापस;

    /* M extension */
    हाल TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        वापस;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    हाल TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        वापस;
    हाल TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        वापस;
    हाल TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        वापस;
    हाल TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        वापस;
    हाल TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        वापस;
    हाल TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        वापस;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    हाल TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        वापस;

    /* F/D extension */
    हाल TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        वापस;
    हाल TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        वापस;

    /* F/D comparison: produce integer result, encode manually */
    हाल TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        वापस;
    हाल TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        वापस;
    हाल TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        वापस;
    हाल TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        वापस;
    हाल TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        वापस;
    हाल TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        वापस;

    शेष:
        expect("ternary instruction");
    }
}

अटल व्योम asm_quaternary_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[4];
    parse_operands(s1, &ops[0], 4);

    चयन (token) {
    हाल TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        वापस;
    हाल TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        वापस;

    शेष:
        expect("quaternary instruction");
    }
}

अटल व्योम asm_atomic_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];

    parse_operand(s1, &ops[0]);
    skip(',');

    अगर ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } अन्यथा {
        parse_operand(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_operand(s1, &ops[2]);
    skip(')');

    चयन(token){
        हाल TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            अवरोध;
        हाल TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            अवरोध;
        हाल TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            अवरोध;
        हाल TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            अवरोध;

        हाल TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            अवरोध;
        हाल TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            अवरोध;
        हाल TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            अवरोध;
        हाल TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            अवरोध;

        हाल TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            अवरोध;
        हाल TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            अवरोध;
        हाल TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            अवरोध;
        हाल TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            अवरोध;

        हाल TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            अवरोध;
        हाल TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            अवरोध;
        हाल TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            अवरोध;
        हाल TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            अवरोध;

        /* AMO instructions (base, aq=0 rl=0) */
        हाल TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;
        हाल TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); अवरोध;

        /* AMO aq/rl variants */
        हाल TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;

        हाल TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
        हाल TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); अवरोध;
        हाल TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); अवरोध;
        हाल TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); अवरोध;
    }
}

/* caller: Add funct3 and func5 to opcode */
अटल व्योम asm_emit_a(पूर्णांक token, uint32_t opcode, स्थिर Operand *rd1, स्थिर Operand *rs2, स्थिर Operand *rs1, पूर्णांक aq, पूर्णांक rl)
{
    अगर (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, शून्य));
    अगर (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, शून्य));
    अगर (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, शून्य));
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
अटल व्योम asm_emit_s(पूर्णांक token, uint32_t opcode, स्थिर Operand* rs1, स्थिर Operand* rs2, स्थिर Operand* imm)
{
    अगर (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, शून्य));
    }
    अगर (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, शून्य));
    }
    अगर (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, शून्य));
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

अटल व्योम asm_emit_b(पूर्णांक token, uint32_t opcode, स्थिर Operand *rs1, स्थिर Operand *rs2, स्थिर Operand *imm)
{
    uint32_t offset;

    अगर (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, शून्य));
    }
    अगर (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }
    अगर (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        पूर्णांक b_ofs = ind;
        uint32_t inv_func3 = ((opcode >> 12) & 7) ^ 1;
        uint32_t inv_opcode = (opcode & ~(7 << 12)) | (inv_func3 << 12);
        /* b<inverse> .+8 */
        asm_emit_opcode(inv_opcode | ENCODE_RS1(rs1->reg)
                        | ENCODE_RS2(rs2->reg) | (1 << 8));
        /* auipc t0, 0 */
        greloca(cur_text_section, imm->e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(0x17 | ENCODE_RD(5));
        /* jalr x0, 0(t0) */
        write32le(cur_text_section->तथ्य + b_ofs,
                  read32le(cur_text_section->तथ्य + b_ofs)
                  | (((ind - b_ofs) >> 1) & 0xf) << 8
                  | (((ind - b_ofs) >> 5) & 0x3f) << 25
                  | (((ind - b_ofs) >> 11) & 1) << 7
                  | (((ind - b_ofs) >> 12) & 1) << 31);
        वापस;
    }
    अगर (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, शून्य));
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
अटल पूर्णांक asm_fcvt_rm(TCCState *s1)
{
    पूर्णांक rm = 7; /* dynamic */
    अगर (tok == ',') {
        अग्र();
        चयन (tok) {
            हाल TOK_ASM_rne: rm = 0; अग्र(); अवरोध;
            हाल TOK_ASM_rtz: rm = 1; अग्र(); अवरोध;
            हाल TOK_ASM_rdn: rm = 2; अग्र(); अवरोध;
            हाल TOK_ASM_rup: rm = 3; अग्र(); अवरोध;
            हाल TOK_ASM_rmm: rm = 4; अग्र(); अवरोध;
            शेष: expect("rounding mode"); अवरोध;
        }
    }
    वापस rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
अटल व्योम asm_fcvt_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[2];
    पूर्णांक rm;
    uint32_t enc = 0;

    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);

    चयन (token) {
        हाल TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); अवरोध;
        हाल TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); अवरोध;
        हाल TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); अवरोध;
        हाल TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); अवरोध;
        हाल TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); अवरोध;
        हाल TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); अवरोध;
        हाल TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); अवरोध;
        हाल TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); अवरोध;
        हाल TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); अवरोध;
        हाल TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); अवरोध;
        हाल TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); अवरोध;
        हाल TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); अवरोध;
        हाल TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); अवरोध;
        हाल TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); अवरोध;
        हाल TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); अवरोध;
        हाल TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); अवरोध;
        हाल TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); अवरोध;
        हाल TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); अवरोध;
        हाल TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); अवरोध;
        हाल TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); अवरोध;
        शेष: expect("fcvt/fclass instruction"); वापस;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC व्योम asm_opcode(TCCState *s1, पूर्णांक token)
{
    चयन (token) {
    हाल TOK_ASM_ebreak:
    हाल TOK_ASM_ecall:
    हाल TOK_ASM_fence_i:
    हाल TOK_ASM_hrts:
    हाल TOK_ASM_mrth:
    हाल TOK_ASM_mrts:
    हाल TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        वापस;

    हाल TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        वापस;

    हाल TOK_ASM_rdcycle:
    हाल TOK_ASM_rdcycleh:
    हाल TOK_ASM_rdtime:
    हाल TOK_ASM_rdtimeh:
    हाल TOK_ASM_rdinstret:
    हाल TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        वापस;

    हाल TOK_ASM_lui:
    हाल TOK_ASM_auipc:
    हाल TOK_ASM_fsqrt_s:
    हाल TOK_ASM_fsqrt_d:
        asm_द्विआधारी_opcode(s1, token);
        वापस;

    /* fcvt/fclass — separate handler for optional rounding operand */
    हाल TOK_ASM_fcvt_w_s:
    हाल TOK_ASM_fcvt_wu_s:
    हाल TOK_ASM_fcvt_l_s:
    हाल TOK_ASM_fcvt_lu_s:
    हाल TOK_ASM_fcvt_s_w:
    हाल TOK_ASM_fcvt_s_wu:
    हाल TOK_ASM_fcvt_s_l:
    हाल TOK_ASM_fcvt_s_lu:
    हाल TOK_ASM_fcvt_w_d:
    हाल TOK_ASM_fcvt_wu_d:
    हाल TOK_ASM_fcvt_l_d:
    हाल TOK_ASM_fcvt_lu_d:
    हाल TOK_ASM_fcvt_d_w:
    हाल TOK_ASM_fcvt_d_wu:
    हाल TOK_ASM_fcvt_d_l:
    हाल TOK_ASM_fcvt_d_lu:
    हाल TOK_ASM_fcvt_s_d:
    हाल TOK_ASM_fcvt_d_s:
    हाल TOK_ASM_fclass_s:
    हाल TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        वापस;

    हाल TOK_ASM_lb:
    हाल TOK_ASM_lh:
    हाल TOK_ASM_lw:
    हाल TOK_ASM_ld:
    हाल TOK_ASM_fld:
    हाल TOK_ASM_lbu:
    हाल TOK_ASM_lhu:
    हाल TOK_ASM_lwu:
    हाल TOK_ASM_sb:
    हाल TOK_ASM_sh:
    हाल TOK_ASM_sw:
    हाल TOK_ASM_sd:
    हाल TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        अवरोध;

    हाल TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        अवरोध;
    हाल TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        वापस;
    हाल TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        अवरोध;

    हाल TOK_ASM_add:
    हाल TOK_ASM_addi:
    हाल TOK_ASM_addiw:
    हाल TOK_ASM_addw:
    हाल TOK_ASM_and:
    हाल TOK_ASM_andi:
    हाल TOK_ASM_or:
    हाल TOK_ASM_ori:
    हाल TOK_ASM_sll:
    हाल TOK_ASM_slli:
    हाल TOK_ASM_slliw:
    हाल TOK_ASM_sllw:
    हाल TOK_ASM_slt:
    हाल TOK_ASM_slti:
    हाल TOK_ASM_sltiu:
    हाल TOK_ASM_sltu:
    हाल TOK_ASM_sra:
    हाल TOK_ASM_srai:
    हाल TOK_ASM_sraiw:
    हाल TOK_ASM_sraw:
    हाल TOK_ASM_srl:
    हाल TOK_ASM_srli:
    हाल TOK_ASM_srliw:
    हाल TOK_ASM_srlw:
    हाल TOK_ASM_sub:
    हाल TOK_ASM_subw:
    हाल TOK_ASM_xor:
    हाल TOK_ASM_xori:
    /* M extension */
    हाल TOK_ASM_div:
    हाल TOK_ASM_divu:
    हाल TOK_ASM_divuw:
    हाल TOK_ASM_divw:
    हाल TOK_ASM_mul:
    हाल TOK_ASM_mulh:
    हाल TOK_ASM_mulhsu:
    हाल TOK_ASM_mulhu:
    हाल TOK_ASM_mulw:
    हाल TOK_ASM_rem:
    हाल TOK_ASM_remu:
    हाल TOK_ASM_remuw:
    हाल TOK_ASM_remw:
    /* Zicsr extension */
    हाल TOK_ASM_csrrc:
    हाल TOK_ASM_csrrci:
    हाल TOK_ASM_csrrs:
    हाल TOK_ASM_csrrsi:
    हाल TOK_ASM_csrrw:
    हाल TOK_ASM_csrrwi:
    /* F/D extension */
    हाल TOK_ASM_fadd_s:
    हाल TOK_ASM_fadd_d:
    हाल TOK_ASM_fsub_s:
    हाल TOK_ASM_fsub_d:
    हाल TOK_ASM_fmul_s:
    हाल TOK_ASM_fmul_d:
    हाल TOK_ASM_fdiv_s:
    हाल TOK_ASM_fdiv_d:
    हाल TOK_ASM_fsgnj_d:
    हाल TOK_ASM_fsgnj_s:
    हाल TOK_ASM_fmax_s:
    हाल TOK_ASM_fmax_d:
    हाल TOK_ASM_fmin_s:
    हाल TOK_ASM_fmin_d:
    हाल TOK_ASM_feq_s:
    हाल TOK_ASM_feq_d:
    हाल TOK_ASM_flt_s:
    हाल TOK_ASM_flt_d:
    हाल TOK_ASM_fle_s:
    हाल TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        वापस;
    हाल TOK_ASM_fmadd_d:
    हाल TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        वापस;

    /* Branches */
    हाल TOK_ASM_beq:
    हाल TOK_ASM_bge:
    हाल TOK_ASM_bgeu:
    हाल TOK_ASM_blt:
    हाल TOK_ASM_bltu:
    हाल TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        अवरोध;

    /* C extension */
    हाल TOK_ASM_c_ebreak:
    हाल TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        वापस;

    हाल TOK_ASM_c_j:
    हाल TOK_ASM_c_jal:
    हाल TOK_ASM_c_jalr:
    हाल TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        वापस;

    हाल TOK_ASM_c_add:
    हाल TOK_ASM_c_addi16sp:
    हाल TOK_ASM_c_addi4spn:
    हाल TOK_ASM_c_addi:
    हाल TOK_ASM_c_addiw:
    हाल TOK_ASM_c_addw:
    हाल TOK_ASM_c_and:
    हाल TOK_ASM_c_andi:
    हाल TOK_ASM_c_beqz:
    हाल TOK_ASM_c_bnez:
    हाल TOK_ASM_c_fldsp:
    हाल TOK_ASM_c_flwsp:
    हाल TOK_ASM_c_fsdsp:
    हाल TOK_ASM_c_fswsp:
    हाल TOK_ASM_c_ldsp:
    हाल TOK_ASM_c_li:
    हाल TOK_ASM_c_lui:
    हाल TOK_ASM_c_lwsp:
    हाल TOK_ASM_c_mv:
    हाल TOK_ASM_c_or:
    हाल TOK_ASM_c_sdsp:
    हाल TOK_ASM_c_slli:
    हाल TOK_ASM_c_srai:
    हाल TOK_ASM_c_srli:
    हाल TOK_ASM_c_sub:
    हाल TOK_ASM_c_subw:
    हाल TOK_ASM_c_swsp:
    हाल TOK_ASM_c_xor:
        asm_द्विआधारी_opcode(s1, token);
        वापस;

    हाल TOK_ASM_c_fld:
    हाल TOK_ASM_c_flw:
    हाल TOK_ASM_c_fsd:
    हाल TOK_ASM_c_fsw:
    हाल TOK_ASM_c_ld:
    हाल TOK_ASM_c_lw:
    हाल TOK_ASM_c_sd:
    हाल TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        वापस;

    /* pseudoinstructions */
    हाल TOK_ASM_nop:
    हाल TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        वापस;

    हाल TOK_ASM_jr:
    हाल TOK_ASM_call:
    हाल TOK_ASM_पुच्छ:
    हाल TOK_ASM_frflags:
    हाल TOK_ASM_frrm:
    हाल TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        वापस;

    हाल TOK_ASM_la:
    हाल TOK_ASM_lla:
    हाल TOK_ASM_li:
    हाल TOK_ASM_jump:
    हाल TOK_ASM_seqz:
    हाल TOK_ASM_snez:
    हाल TOK_ASM_sltz:
    हाल TOK_ASM_sgtz:
    हाल TOK_ASM_mv:
    हाल TOK_ASM_not:
    हाल TOK_ASM_neg:
    हाल TOK_ASM_negw:
    हाल TOK_ASM_sext_w:
    हाल TOK_ASM_fabs_s:
    हाल TOK_ASM_fabs_d:
    हाल TOK_ASM_fmv_s:
    हाल TOK_ASM_fmv_d:
    हाल TOK_ASM_fneg_s:
    हाल TOK_ASM_fneg_d:
    हाल TOK_ASM_csrc:
    हाल TOK_ASM_csrs:
    हाल TOK_ASM_csrr:
    हाल TOK_ASM_csrw:
    हाल TOK_ASM_csrwi:
    हाल TOK_ASM_csrsi:
    हाल TOK_ASM_csrci:
    हाल TOK_ASM_fsrm:
    हाल TOK_ASM_fscsr:
        asm_द्विआधारी_opcode(s1, token);
        वापस;

    हाल TOK_ASM_bnez:
    हाल TOK_ASM_beqz:
    हाल TOK_ASM_blez:
    हाल TOK_ASM_bgez:
    हाल TOK_ASM_bltz:
    हाल TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        वापस;

    हाल TOK_ASM_bgt:
    हाल TOK_ASM_bgtu:
    हाल TOK_ASM_ble:
    हाल TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        वापस;

    /* Atomic operations */
    हाल TOK_ASM_lr_w:
    हाल TOK_ASM_lr_w_aq:
    हाल TOK_ASM_lr_w_rl:
    हाल TOK_ASM_lr_w_aqrl:
    हाल TOK_ASM_lr_d:
    हाल TOK_ASM_lr_d_aq:
    हाल TOK_ASM_lr_d_rl:
    हाल TOK_ASM_lr_d_aqrl:
    हाल TOK_ASM_sc_w:
    हाल TOK_ASM_sc_w_aq:
    हाल TOK_ASM_sc_w_rl:
    हाल TOK_ASM_sc_w_aqrl:
    हाल TOK_ASM_sc_d:
    हाल TOK_ASM_sc_d_aq:
    हाल TOK_ASM_sc_d_rl:
    हाल TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    हाल TOK_ASM_amoadd_w:
    हाल TOK_ASM_amoadd_d:
    हाल TOK_ASM_amoswap_w:
    हाल TOK_ASM_amoswap_d:
    हाल TOK_ASM_amoand_w:
    हाल TOK_ASM_amoand_d:
    हाल TOK_ASM_amoor_w:
    हाल TOK_ASM_amoor_d:
    हाल TOK_ASM_amoxor_w:
    हाल TOK_ASM_amoxor_d:
    हाल TOK_ASM_amomax_w:
    हाल TOK_ASM_amomax_d:
    हाल TOK_ASM_amomaxu_w:
    हाल TOK_ASM_amomaxu_d:
    हाल TOK_ASM_amomin_w:
    हाल TOK_ASM_amomin_d:
    हाल TOK_ASM_amominu_w:
    हाल TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    हाल TOK_ASM_amoadd_w_aq:
    हाल TOK_ASM_amoadd_w_rl:
    हाल TOK_ASM_amoadd_w_aqrl:
    हाल TOK_ASM_amoadd_d_aq:
    हाल TOK_ASM_amoadd_d_rl:
    हाल TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    हाल TOK_ASM_amoswap_w_aq:
    हाल TOK_ASM_amoswap_w_rl:
    हाल TOK_ASM_amoswap_w_aqrl:
    हाल TOK_ASM_amoswap_d_aq:
    हाल TOK_ASM_amoswap_d_rl:
    हाल TOK_ASM_amoswap_d_aqrl:
    हाल TOK_ASM_amoand_w_aq:
    हाल TOK_ASM_amoand_w_rl:
    हाल TOK_ASM_amoand_w_aqrl:
    हाल TOK_ASM_amoand_d_aq:
    हाल TOK_ASM_amoand_d_rl:
    हाल TOK_ASM_amoand_d_aqrl:
    हाल TOK_ASM_amoor_w_aq:
    हाल TOK_ASM_amoor_w_rl:
    हाल TOK_ASM_amoor_w_aqrl:
    हाल TOK_ASM_amoor_d_aq:
    हाल TOK_ASM_amoor_d_rl:
    हाल TOK_ASM_amoor_d_aqrl:
    हाल TOK_ASM_amoxor_w_aq:
    हाल TOK_ASM_amoxor_w_rl:
    हाल TOK_ASM_amoxor_w_aqrl:
    हाल TOK_ASM_amoxor_d_aq:
    हाल TOK_ASM_amoxor_d_rl:
    हाल TOK_ASM_amoxor_d_aqrl:
    हाल TOK_ASM_amomax_w_aq:
    हाल TOK_ASM_amomax_w_rl:
    हाल TOK_ASM_amomax_w_aqrl:
    हाल TOK_ASM_amomax_d_aq:
    हाल TOK_ASM_amomax_d_rl:
    हाल TOK_ASM_amomax_d_aqrl:
    हाल TOK_ASM_amomaxu_w_aq:
    हाल TOK_ASM_amomaxu_w_rl:
    हाल TOK_ASM_amomaxu_w_aqrl:
    हाल TOK_ASM_amomaxu_d_aq:
    हाल TOK_ASM_amomaxu_d_rl:
    हाल TOK_ASM_amomaxu_d_aqrl:
    हाल TOK_ASM_amomin_w_aq:
    हाल TOK_ASM_amomin_w_rl:
    हाल TOK_ASM_amomin_w_aqrl:
    हाल TOK_ASM_amomin_d_aq:
    हाल TOK_ASM_amomin_d_rl:
    हाल TOK_ASM_amomin_d_aqrl:
    हाल TOK_ASM_amominu_w_aq:
    हाल TOK_ASM_amominu_w_rl:
    हाल TOK_ASM_amominu_w_aqrl:
    हाल TOK_ASM_amominu_d_aq:
    हाल TOK_ASM_amominu_d_rl:
    हाल TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        अवरोध;

    शेष:
        expect("known instruction");
    }
}

अटल पूर्णांक asm_parse_csrvar(पूर्णांक t)
{
    चयन (t) {
    हाल TOK_ASM_cycle:
        वापस 0xc00;
    हाल TOK_ASM_fcsr:
        वापस 3;
    हाल TOK_ASM_fflags:
        वापस 1;
    हाल TOK_ASM_frm:
        वापस 2;
    हाल TOK_ASM_instret:
        वापस 0xc02;
    हाल TOK_ASM_time:
        वापस 0xc01;
    हाल TOK_ASM_cycleh:
        वापस 0xc80;
    हाल TOK_ASM_instreth:
        वापस 0xc82;
    हाल TOK_ASM_timeh:
        वापस 0xc81;
    शेष:
        वापस -1;
    }
}

ST_FUNC व्योम subst_asm_operand(CString *add_str, SValue *sv, पूर्णांक modifier)
{
    पूर्णांक r, reg, val;

    r = sv->r;
    अगर ((r & VT_VALMASK) == VT_CONST) {
        अगर (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        अगर (r & VT_SYM) {
            स्थिर अक्षर *name = get_tok_str(sv->sym->v, शून्य);
            अगर (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, म_माप(name))->tok, sv->sym);
            }
            अगर (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            अगर ((uint32_t) sv->c.i == 0)
                जाओ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        अगर (modifier == 'n')
            val = -val;
        अगर (modifier == 'z' && val == 0) {
            cstr_cat(add_str, "zero", -1);
        } अन्यथा {
            cstr_printf(add_str, "%d", val);
        }
      no_offset:;
    } अन्यथा अगर ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d", (पूर्णांक) sv->c.i);
    } अन्यथा अगर (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        अगर (reg >= VT_CONST)
            tcc_internal_error("");
        अगर ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_मूल्य(reg);
        } अन्यथा {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, शून्य), -1);
    } अन्यथा {
        /* register case */
        reg = r & VT_VALMASK;
        अगर (reg >= VT_CONST)
            tcc_internal_error("");
        अगर ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_मूल्य(reg);
        } अन्यथा {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, शून्य), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
अटल पूर्णांक tcc_ireg(पूर्णांक r){
    वापस REG_मूल्य(r) - 10;
}
अटल पूर्णांक tcc_freg(पूर्णांक r){
    वापस REG_मूल्य(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC व्योम asm_gen_code(ASMOperand *operands, पूर्णांक nb_operands,
                         पूर्णांक nb_outputs, पूर्णांक is_output,
                         uint8_t *clobber_regs,
                         पूर्णांक out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    पूर्णांक i, reg;

    अटल स्थिर uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    स_नकल(regs_allocated, clobber_regs, माप(regs_allocated));
    क्रम(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        अगर (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    अगर(!is_output) {
        /* generate reg save code */
        क्रम(i = 0; i < माप(reg_saved)/माप(reg_saved[0]); i++) {
            reg = reg_saved[i];
            अगर (regs_allocated[reg]) {
                /*धकेलो*/
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (अचिन्हित)-8 << 20);
                अगर (REG_IS_FLOAT(reg)){
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
        क्रम(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            अगर (op->reg >= 0) {
                अगर ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(tcc_ireg(op->reg), &sv);
                } अन्यथा अगर (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    अगर ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
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
        क्रम(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            अगर (op->reg >= 0) {
                अगर ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    अगर (!op->is_memory) {
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
                    अगर ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
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
        क्रम(i = माप(reg_saved)/माप(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            अगर (regs_allocated[reg]) {
                /*निकालो*/
                अगर (REG_IS_FLOAT(reg)){
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
अटल अंतरभूत पूर्णांक constraint_priority(स्थिर अक्षर *str)
{
    // TODO: How is this chosen??
    पूर्णांक priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    क्रम(;;) {
        c = *str;
        अगर (c == '\0')
            अवरोध;
        str++;
        चयन(c) {
        हाल 'A': // address that is held in a general-purpose register.
        हाल 'S': // constraint that matches an absolute symbolic address.
        हाल 'f': // register [float]
        हाल 'r': // register [general]
        हाल 'p': // valid memory address for load,store [general]
            pr = 3;
            अवरोध;
        हाल 'I': // 12 bit signed immedate
        हाल 'i': // immediate integer operand, including symbolic constants [general]
        हाल 'm': // memory operand [general]
        हाल 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            अवरोध;
        हाल 'v':
            tcc_error("unimp: constraint '%c'", c);
        शेष:
            tcc_error("unknown constraint '%d'", c);
        }
        अगर (pr > priority)
            priority = pr;
    }
    वापस priority;
}

अटल स्थिर अक्षर *skip_constraint_modifiers(स्थिर अक्षर *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    जबतक (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    वापस p;
}

#घोषणा REG_OUT_MASK 0x01
#घोषणा REG_IN_MASK  0x02

#घोषणा is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC व्योम asm_compute_constraints(ASMOperand *operands,
                                    पूर्णांक nb_operands, पूर्णांक nb_outputs,
                                    स्थिर uint8_t *clobber_regs,
                                    पूर्णांक *pout_reg)
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
    पूर्णांक sorted_op[MAX_ASM_OPERANDS];
    पूर्णांक i, j, k, p1, p2, tmp, reg, c, reg_mask;
    स्थिर अक्षर *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    क्रम (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->निवेश_सूचकांक = -1;
        op->ref_सूचकांक = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    क्रम (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        अगर (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, शून्य);
            अगर ((अचिन्हित) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
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

    /* sort operands according to their priority */
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

    /* allocate registers and generate corresponding asm moves */
    क्रम (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        अगर (op->ref_सूचकांक >= 0)
            जारी;
        /* select if register is used for output, input or both */
        अगर (op->निवेश_सूचकांक >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अन्यथा अगर (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अन्यथा {
            reg_mask = REG_IN_MASK;
        }
        अगर (op->reg >= 0) {
            अगर (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_अग्र:
        c = *str++;
        चयन (c) {
        हाल '=': // Operand is written-to
            जाओ try_अग्र;
        हाल '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        हाल '&': // Operand is clobbered before the instruction is done using the input operands
            अगर (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            जाओ try_अग्र;
        हाल 'r': // general-purpose register
        हाल 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            अगर ((reg = op->reg) >= 0)
                जाओ reg_found;
            अन्यथा क्रम (reg = 10; reg <= 18; reg++) {
                अगर (!is_reg_allocated(reg))
                    जाओ reg_found;
            }
            जाओ try_अग्र;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            अवरोध;
        हाल 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            अगर ((reg = op->reg) >= 0)
                जाओ reg_found;
            अन्यथा क्रम (reg = 42; reg <= 50; reg++) {
                अगर (!is_reg_allocated(reg))
                    जाओ reg_found;
            }
            जाओ try_अग्र;
        हाल 'I': // I-Type 12 bit signed immediate
        हाल 'i': // immediate integer operand, including symbolic constants
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                जाओ try_अग्र;
            अवरोध;
        हाल 'm': // memory operand
        हाल 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            अगर (j < nb_outputs || c == 'm') {
                अगर ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    क्रम (reg = 10; reg <= 18; reg++) {
                        अगर (!(regs_allocated[reg] & REG_IN_MASK))
                            जाओ reg_found1;
                    }
                    जाओ try_अग्र;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            अवरोध;
        शेष:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            अवरोध;
        }
        /* if a reference is present for that operand, we assign it too */
        अगर (op->निवेश_सूचकांक >= 0) {
            operands[op->निवेश_सूचकांक].reg = op->reg;
            operands[op->निवेश_सूचकांक].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    क्रम (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        अगर (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            अगर (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                क्रम (reg = 42; reg <= 50; reg++) {
                    अगर (!(regs_allocated[reg] & REG_OUT_MASK))
                        जाओ reg_found2;
                }
            } अन्यथा {
                /* From a0 to a7 */
                क्रम (reg = 10; reg <= 18; reg++) {
                    अगर (!(regs_allocated[reg] & REG_OUT_MASK))
                        जाओ reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            अवरोध;
        }
    }

    /* print sorted constraints */
#अगर_घोषित ASM_DEBUG
    क्रम (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        म_लिखो("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, शून्य) : "",
               op->constraint, op->vt->r, op->reg);
    }
    अगर (*pout_reg >= 0)
        म_लिखो("out_reg=%d\n", *pout_reg);
#पूर्ण_अगर
}

ST_FUNC व्योम asm_clobber(uint8_t *clobber_regs, स्थिर अक्षर *str)
{
    पूर्णांक reg;
    TokenSym *ts;

    अगर (!म_भेद(str, "memory") ||
        !म_भेद(str, "cc") ||
        !म_भेद(str, "flags"))
        वापस;
    ts = tok_alloc(str, म_माप(str));
    reg = asm_parse_regvar(ts->tok);
    अगर (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC पूर्णांक asm_parse_regvar (पूर्णांक t)
{
    /* PC register not implemented */
    अगर (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        वापस -1;

    अगर (t < TOK_ASM_f0)
        वापस t - TOK_ASM_x0;

    अगर (t < TOK_ASM_zero)
        वापस t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    अगर (t < TOK_ASM_ft0)
        वापस t - TOK_ASM_zero;

    वापस t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
अटल व्योम asm_emit_ca(पूर्णांक token, uint16_t opcode, स्थिर Operand *rd, स्थिर Operand *rs2)
{
    uint8_t dst, src;

    अगर (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }

    अगर (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, शून्य));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    अगर (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, शून्य));
    }

    अगर (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, शून्य));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

अटल व्योम asm_emit_cb(पूर्णांक token, uint16_t opcode, स्थिर Operand *rs1, स्थिर Operand *imm)
{
    uint32_t offset;
    uint8_t src;

    अगर (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, शून्य));
    }

    अगर (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, शून्य));
    }

    offset = imm->e.v;

    अगर (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, शून्य));
    }

    src = rs1->reg - 8;

    अगर (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, शून्य));
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

    चयन (token) {
    हाल TOK_ASM_c_beqz:
    हाल TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_BIT(offset, 5) | (((offset >> 1) & 3) << 1) | (((offset >> 6) & 3) << 3)) << 2) | ((((offset >> 3) & 3) | NTH_BIT(offset, 8)) << 10));
        वापस;
    शेष:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((offset & 0x1f) << 2) | (NTH_BIT(offset, 5) << 12));
        वापस;
    }
}

अटल व्योम asm_emit_ci(पूर्णांक token, uint16_t opcode, स्थिर Operand *rd, स्थिर Operand *imm)
{
    uint32_t immediate;

    अगर (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }

    अगर (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, शून्य));
    }

    immediate = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    चयन (token) {
    हाल TOK_ASM_c_addi:
    हाल TOK_ASM_c_addiw:
    हाल TOK_ASM_c_li:
    हाल TOK_ASM_c_slli:
        gen_le16(opcode | ((immediate & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        वापस;
    हाल TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_BIT(immediate, 5) << 2 | (((immediate >> 7) & 3) << 3) | NTH_BIT(immediate, 6) << 5 | NTH_BIT(immediate, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 9) << 12));
        वापस;
    हाल TOK_ASM_c_lui:
        gen_le16(opcode | (((immediate >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 17) << 12));
        वापस;
    हाल TOK_ASM_c_fldsp:
    हाल TOK_ASM_c_ldsp:
        gen_le16(opcode | (((immediate >> 6) & 7) << 2) | (((immediate >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        वापस;
    हाल TOK_ASM_c_flwsp:
    हाल TOK_ASM_c_lwsp:
        gen_le16(opcode | (((immediate >> 6) & 3) << 2) | (((immediate >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        वापस;
    हाल TOK_ASM_c_nop:
        gen_le16(opcode);
        वापस;
    शेष:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
अटल व्योम asm_emit_ciw(पूर्णांक token, uint16_t opcode, स्थिर Operand *rd, स्थिर Operand *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    अगर (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }

    अगर (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, शून्य));
    }

    dst = rd->reg - 8;

    अगर (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, शून्य));
    }

    nzuimm = imm->e.v;

    अगर (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, शून्य));
    }

    अगर (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, शून्य));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_BIT(nzuimm, 3) | (NTH_BIT(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
अटल व्योम asm_emit_cj(पूर्णांक token, uint16_t opcode, स्थिर Operand *imm)
{
    uint32_t offset;

    /* +-2 KiB range */
    अगर (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, शून्य));
    }

    offset = imm->e.v;

    अगर (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, शून्य));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_BIT(offset, 5) << 2) | (((offset >> 1) & 7) << 3) | (NTH_BIT(offset, 7) << 6) | (NTH_BIT(offset, 6) << 7) | (NTH_BIT(offset, 10) << 8) | (((offset >> 8) & 3) << 9) | (NTH_BIT(offset, 4) << 11) | (NTH_BIT(offset, 11) << 12));
}

/* caller: Add funct3 into opcode */
अटल व्योम asm_emit_cl(पूर्णांक token, uint16_t opcode, स्थिर Operand *rd, स्थिर Operand *rs1, स्थिर Operand *imm)
{
    uint32_t offset;
    uint8_t dst, src;

    अगर (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }

    अगर (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, शून्य));
    }

    अगर (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, शून्य));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    अगर (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, शून्य));
    }

    अगर (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, शून्य));
    }

    offset = imm->e.v;

    अगर (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, शून्य));
    }

    अगर (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, शून्य));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    चयन (token) {
    /* imm variant 1 */
    हाल TOK_ASM_c_flw:
    हाल TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        वापस;
    /* imm variant 2 */
    हाल TOK_ASM_c_fld:
    हाल TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        वापस;
    शेष:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
अटल व्योम asm_emit_cr(पूर्णांक token, uint16_t opcode, स्थिर Operand *rd, स्थिर Operand *rs2)
{
    अगर (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }

    अगर (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, शून्य));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
अटल व्योम asm_emit_cs(पूर्णांक token, uint16_t opcode, स्थिर Operand *rs2, स्थिर Operand *rs1, स्थिर Operand *imm)
{
    uint32_t offset;
    uint8_t base, src;

    अगर (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }

    अगर (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, शून्य));
    }

    अगर (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, शून्य));
    }

    base = rs1->reg - 8;
    src = rs2->reg - 8;

    अगर (base > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, शून्य));
    }

    अगर (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, शून्य));
    }

    offset = imm->e.v;

    अगर (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, शून्य));
    }

    अगर (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, शून्य));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    चयन (token) {
    /* imm variant 1 */
    हाल TOK_ASM_c_fsw:
    हाल TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        वापस;
    /* imm variant 2 */
    हाल TOK_ASM_c_fsd:
    हाल TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        वापस;
    शेष:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
अटल व्योम asm_emit_css(पूर्णांक token, uint16_t opcode, स्थिर Operand *rs2, स्थिर Operand *imm)
{
    uint32_t offset;

    अगर (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, शून्य));
    }

    अगर (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, शून्य));
    }

    offset = imm->e.v;

    अगर (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, शून्य));
    }

    अगर (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, शून्य));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    चयन (token) {
    /* imm variant 1 */
    हाल TOK_ASM_c_fswsp:
    हाल TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 3) << 7) | (((offset >> 2) & 0xf) << 9));
        वापस;
    /* imm variant 2 */
    हाल TOK_ASM_c_fsdsp:
    हाल TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 7) << 7) | (((offset >> 3) & 7) << 10));
        वापस;
    शेष:
        expect("known instruction");
    }
}

/*************************************************************/
#पूर्ण_अगर /* ndef TARGET_DEFS_ONLY */
