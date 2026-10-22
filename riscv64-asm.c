/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

#నిర్వచించు CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#నిర్వచించు NB_ASM_REGS 64

ST_FUNC శూన్య g(పూర్ణాంకం c);
ST_FUNC శూన్య gen_le16(పూర్ణాంకం c);
ST_FUNC శూన్య gen_le32(పూర్ణాంకం c);

/*************************************************************/
#లేకపోతే
/*************************************************************/
#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"

గణన {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#నిర్వచించు REG_FLOAT_ముసుగు 0x20
#నిర్వచించు REG_IS_FLOAT(రిజిస్టరు_సూచీ) ((రిజిస్టరు_సూచీ) & REG_FLOAT_ముసుగు)
#నిర్వచించు REG_విలువ(రిజిస్టరు_సూచీ)    ((రిజిస్టరు_సూచీ) & (REG_FLOAT_ముసుగు-1))
#నిర్వచించు C_ENCODE_RS1(రిజిస్టరు_సూచీ) (REG_విలువ(రిజిస్టరు_సూచీ) << 7)
#నిర్వచించు C_ENCODE_RS2(రిజిస్టరు_సూచీ) (REG_విలువ(రిజిస్టరు_సూచీ) << 2)
#నిర్వచించు ENCODE_RD(రిజిస్టరు_సూచీ)  (REG_విలువ(రిజిస్టరు_సూచీ) << 7)
#నిర్వచించు ENCODE_RS1(రిజిస్టరు_సూచీ) (REG_విలువ(రిజిస్టరు_సూచీ) << 15)
#నిర్వచించు ENCODE_RS2(రిజిస్టరు_సూచీ) (REG_విలువ(రిజిస్టరు_సూచీ) << 20)
#నిర్వచించు NTH_బిట్టు(b, n) ((b >> n) & 1)
#నిర్వచించు OP_IM12S (1 << OPT_IM12S)
#నిర్వచించు OP_IM32 (1 << OPT_IM32)
#నిర్వచించు OP_REG (1 << OPT_REG)

రకనిర్వచనం నిర్మాణం నిర్వాహ్యం {
    uint32_t type;
    సంఘం {
        uint8_t reg;
        uint16_t regset;
        సమాసం_విలువ e;
    };
} నిర్వాహ్యం;

స్థిర స్థిరరాశి నిర్వాహ్యం zero = { OP_REG, { 0 }};
స్థిర స్థిరరాశి నిర్వాహ్యం ra = { OP_REG, { 1 }};
స్థిర స్థిరరాశి నిర్వాహ్యం zimm = { OP_IM12S };

స్థిర శూన్య asm_ద్విమాన_opcode(TCCState* s1, పూర్ణాంకం token);
ST_FUNC శూన్య asm_clobber(uint8_t *clobber_regs, స్థిరరాశి అక్షరం *str);
ST_FUNC శూన్య asm_compute_constraints(ASMOperand *operands, పూర్ణాంకం nb_operands, పూర్ణాంకం nb_outputs, స్థిరరాశి uint8_t *clobber_regs, పూర్ణాంకం *pout_reg);
స్థిర శూన్య asm_emit_a(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *rs2, స్థిరరాశి నిర్వాహ్యం *rd1, పూర్ణాంకం aq, పూర్ణాంకం rl);
స్థిర శూన్య asm_emit_b(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *rs2, స్థిరరాశి నిర్వాహ్యం *imm);
స్థిర శూన్య asm_emit_i(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *rs2);
స్థిర శూన్య asm_emit_j(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs2);
స్థిర శూన్య asm_emit_opcode(uint32_t opcode);
స్థిర శూన్య asm_emit_r(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *rs2);
స్థిర శూన్య asm_emit_s(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *rs2, స్థిరరాశి నిర్వాహ్యం *imm);
స్థిర శూన్య asm_emit_u(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs2);
స్థిర శూన్య asm_emit_f(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *rs2);
స్థిర శూన్య asm_emit_fb(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs);
స్థిర శూన్య asm_emit_fq(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *rs2, స్థిరరాశి నిర్వాహ్యం *rs3);
ST_FUNC శూన్య asm_gen_సంకేతం(ASMOperand *operands, పూర్ణాంకం nb_operands, పూర్ణాంకం nb_outputs, పూర్ణాంకం is_output, uint8_t *clobber_regs, పూర్ణాంకం బహిర్గతం_reg);
స్థిర శూన్య asm_nullary_opcode(TCCState *s1, పూర్ణాంకం token);
ST_FUNC శూన్య asm_opcode(TCCState *s1, పూర్ణాంకం token);
స్థిర పూర్ణాంకం asm_parse_csrvar(పూర్ణాంకం t);
ST_FUNC పూర్ణాంకం asm_parse_regvar(పూర్ణాంకం t);
స్థిర శూన్య asm_ternary_opcode(TCCState *s1, పూర్ణాంకం token);
స్థిర శూన్య asm_unary_opcode(TCCState *s1, పూర్ణాంకం token);
స్థిర శూన్య asm_branch_opcode(TCCState *s1, పూర్ణాంకం token, పూర్ణాంకం argc);
ST_FUNC శూన్య gen_expr32(సమాసం_విలువ *pe);
స్థిర శూన్య parse_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op);
స్థిర శూన్య parse_branch_స్థానభ్రంశం_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op);
స్థిర శూన్య parse_operands(TCCState *s1, నిర్వాహ్యం *ops, పూర్ణాంకం లెక్క_2);
స్థిర శూన్య parse_mem_access_operands(TCCState *s1, నిర్వాహ్యం* ops);
ST_FUNC శూన్య subst_asm_నిర్వాహ్యం(CString *కూడు_str, SValue *sv, పూర్ణాంకం modifier);
/* C extension */
స్థిర శూన్య asm_emit_ca(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs2);
స్థిర శూన్య asm_emit_cb(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *imm);
స్థిర శూన్య asm_emit_ci(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *imm);
స్థిర శూన్య asm_emit_ciw(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *imm);
స్థిర శూన్య asm_emit_cj(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *imm);
స్థిర శూన్య asm_emit_cl(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *imm);
స్థిర శూన్య asm_emit_cr(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs2);
స్థిర శూన్య asm_emit_cs(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rs2, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *imm);
స్థిర శూన్య asm_emit_css(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rs2, స్థిరరాశి నిర్వాహ్యం *imm);

/* XXX: make it faster ? */
ST_FUNC శూన్య g(పూర్ణాంకం c)
{
    పూర్ణాంకం ind1;
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    ind1 = ind + 1;
    ఒకవేళ (ind1 > cur_పాఠ్యం_section->దత్తాంశం_allocated)
        section_realloc(cur_పాఠ్యం_section, ind1);
    cur_పాఠ్యం_section->దత్తాంశం[ind] = c;
    ind = ind1;
}

ST_FUNC శూన్య gen_le16 (పూర్ణాంకం i)
{
    g(i);
    g(i>>8);
}

ST_FUNC శూన్య gen_le32 (పూర్ణాంకం i)
{
    పూర్ణాంకం ind1;
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    ind1 = ind + 4;
    ఒకవేళ (ind1 > cur_పాఠ్యం_section->దత్తాంశం_allocated)
        section_realloc(cur_పాఠ్యం_section, ind1);
    cur_పాఠ్యం_section->దత్తాంశం[ind++] = i & 0xFF;
    cur_పాఠ్యం_section->దత్తాంశం[ind++] = (i >> 8) & 0xFF;
    cur_పాఠ్యం_section->దత్తాంశం[ind++] = (i >> 16) & 0xFF;
    cur_పాఠ్యం_section->దత్తాంశం[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC శూన్య gen_expr32(సమాసం_విలువ *pe)
{
    gen_le32(pe->v);
}

స్థిర శూన్య asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

స్థిర శూన్య asm_nullary_opcode(TCCState *s1, పూర్ణాంకం token)
{
    ఎంపిక (token) {
    // Sync instructions

    స్థితి TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        తిరిగి;

    // System calls

    స్థితి TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        తిరిగి;
    స్థితి TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        తిరిగి;

    // Other

    స్థితి TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        తిరిగి;

    స్థితి TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        తిరిగి;

    /* Pseudoinstructions */
    స్థితి TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        తిరిగి;

    /* C extension */
    స్థితి TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        తిరిగి;
    స్థితి TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        తిరిగి;

    అప్రమేయ:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
స్థిర శూన్య parse_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op)
{
    సమాసం_విలువ e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    ఒకవేళ ((reg = asm_parse_regvar(tok)) != -1) {
        తదుపరి(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        తిరిగి;
    } లేకపోతే ఒకవేళ (tok == '$') {
        /* constant value */
        తదుపరి(); // skip '#' or '$'
    } లేకపోతే ఒకవేళ ((e.v = asm_parse_csrvar(tok)) != -1) {
        తదుపరి();
    } లేకపోతే {
        asm_సమాసం(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ఒకవేళ (!op->e.sym) {
        ఒకవేళ ((పూర్ణాంకం) op->e.v >= -0x1000 && (పూర్ణాంకం) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } లేకపోతే ఒకవేళ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        ఒకవేళ (op->e.sym->type.t & VT_STATIC)
            greloca(cur_పాఠ్యం_section, op->e.sym, ind, R_RISCV_PCREL_HI20, 0);
        లేకపోతే
            greloca(cur_పాఠ్యం_section, op->e.sym, ind, R_RISCV_GOT_HI20, 0);
        put_extern_sym(&label, cur_పాఠ్యం_section, ind, 0);
        greloca(cur_పాఠ్యం_section, &label, ind+4, R_RISCV_PCREL_LO12_I, 0);

        op->type = OP_IM12S;
        op->e.v = 0;
    } లేకపోతే {
        expect("operand");
    }
}

స్థిర శూన్య parse_branch_స్థానభ్రంశం_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op){
    సమాసం_విలువ e = {0};

    asm_సమాసం(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ఒకవేళ (!op->e.sym) {
        ఒకవేళ ((పూర్ణాంకం) op->e.v >= -0x1000 && (పూర్ణాంకం) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } లేకపోతే ఒకవేళ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } లేకపోతే {
        expect("operand");
    }
}

స్థిర శూన్య parse_jump_స్థానభ్రంశం_నిర్వాహ్యం(TCCState *s1, నిర్వాహ్యం *op){
    సమాసం_విలువ e = {0};

    asm_సమాసం(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ఒకవేళ (!op->e.sym) {
        ఒకవేళ ((పూర్ణాంకం) op->e.v >= -0x1000 && (పూర్ణాంకం) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } లేకపోతే ఒకవేళ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_పాఠ్యం_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } లేకపోతే {
        expect("operand");
    }
}

స్థిర శూన్య parse_operands(TCCState *s1, నిర్వాహ్యం* ops, పూర్ణాంకం లెక్క_2){
    పూర్ణాంకం i;
    కొరకు (i = 0; i < లెక్క_2; i++) {
        ఒకవేళ ( i != 0 )
            skip(',');
        parse_నిర్వాహ్యం(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
స్థిర శూన్య parse_mem_access_operands(TCCState *s1, నిర్వాహ్యం* ops){

    నిర్వాహ్యం op;

    parse_నిర్వాహ్యం(s1, &ops[0]);
    skip(',');
    ఒకవేళ ( tok == '(') {
        /* `X, (Y)` case*/
        తదుపరి();
        parse_నిర్వాహ్యం(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } లేకపోతే {
        parse_నిర్వాహ్యం(s1, &ops[2]);
        ఒకవేళ ( tok == '('){
            /* `X, imm(Y)` case*/
            తదుపరి();
            parse_నిర్వాహ్యం(s1, &ops[1]);
            skip(')');
        } లేకపోతే {
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
స్థిర శూన్య asm_jal_opcode(TCCState *s1, పూర్ణాంకం token){
    నిర్వాహ్యం ops[2];

    ఒకవేళ (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } లేకపోతే ఒకవేళ (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } లేకపోతే {
        // jal reg, offset
        parse_నిర్వాహ్యం(s1, &ops[0]);
        ఒకవేళ ( tok == ',') తదుపరి(); లేకపోతే expect("','");
    }
    parse_jump_స్థానభ్రంశం_నిర్వాహ్యం(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
స్థిర శూన్య asm_jalr_opcode(TCCState *s1, పూర్ణాంకం token){
    నిర్వాహ్యం ops[3];
    నిర్వాహ్యం op;

    parse_నిర్వాహ్యం(s1, &ops[0]);
    ఒకవేళ ( tok == ',')
        తదుపరి();
    లేకపోతే {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        తిరిగి;
    }

    ఒకవేళ ( tok == '(') {
        /* `X, (Y)` case*/
        తదుపరి();
        parse_నిర్వాహ్యం(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } లేకపోతే {
        parse_నిర్వాహ్యం(s1, &ops[2]);
        ఒకవేళ ( tok == '('){
            /* `X, imm(Y)` case*/
            తదుపరి();
            parse_నిర్వాహ్యం(s1, &ops[1]);
            skip(')');
        } లేకపోతే {
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


స్థిర శూన్య asm_unary_opcode(TCCState *s1, పూర్ణాంకం token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    నిర్వాహ్యం op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    ఎంపిక (token) {
    /* pseudoinstructions */
    స్థితి TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        తిరిగి;
    స్థితి TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        తిరిగి;
    స్థితి TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        తిరిగి;
    స్థితి TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        తిరిగి;
    స్థితి TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        తిరిగి;
    స్థితి TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        తిరిగి;
    స్థితి TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        తిరిగి;
    స్థితి TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        తిరిగి;
    స్థితి TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        తిరిగి;

    స్థితి TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        తిరిగి;
    స్థితి TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_పాఠ్యం_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        తిరిగి;
    స్థితి TOK_ASM_తోక:
        /* auipc x6, 0 */
        greloca(cur_పాఠ్యం_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        తిరిగి;

    /* C extension */
    స్థితి TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        తిరిగి;
    స్థితి TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        తిరిగి;
    స్థితి TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        తిరిగి;
    స్థితి TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        తిరిగి;

    అప్రమేయ:
        expect("unary instruction");
    }
}

స్థిర శూన్య asm_emit_u(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం* rd, స్థిరరాశి నిర్వాహ్యం* rs2)
{
    ఒకవేళ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ఖాళీ));
    } లేకపోతే ఒకవేళ (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, ఖాళీ));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

స్థిర పూర్ణాంకం parse_fence_నిర్వాహ్యం(){
    పూర్ణాంకం t = tok;
    ఒకవేళ ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    తదుపరి();
    తిరిగి t - (TOK_ASM_w_fence - 1);
}

స్థిర శూన్య asm_fence_opcode(TCCState *s1, పూర్ణాంకం token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    పూర్ణాంకం succ = 0xF, pred = 0xF;
    ఒకవేళ (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_నిర్వాహ్యం();
        ఒకవేళ ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, ఖాళీ));
        }
        skip(',');
        succ = parse_fence_నిర్వాహ్యం();
        ఒకవేళ ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, ఖాళీ));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

స్థిర శూన్య asm_ద్విమాన_opcode(TCCState* s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం imm = { OP_IM12S };
    నిర్వాహ్యం ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    ఎంపిక (token) {
    స్థితి TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        తిరిగి;

    /* C extension */
    స్థితి TOK_ASM_c_కూడు:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        తిరిగి;

    స్థితి TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        తిరిగి;

    స్థితి TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        తిరిగి;

#నిర్వచించు CA (1 | (3 << 10) | (4 << 13))
    స్థితి TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        తిరిగి;
#నిర్వచనం_రద్దు CA

    స్థితి TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        తిరిగి;

    స్థితి TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        తిరిగి;

    /* F/D extension */
    స్థితి TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        తిరిగి;

    /* pseudoinstructions */
    /* rd, sym */
    స్థితి TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_li:
        ఒకవేళ(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, ఖాళీ));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        ఒకవేళ(lo < 0){
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
        తిరిగి;
    స్థితి TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        తిరిగి;
    స్థితి TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        తిరిగి;
    స్థితి TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        తిరిగి;
    స్థితి TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        తిరిగి;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    స్థితి TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_పాఠ్యం_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        తిరిగి;
    స్థితి TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        తిరిగి;
    స్థితి TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        తిరిగి;
    స్థితి TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        తిరిగి;

    స్థితి TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        తిరిగి;

    /* CSR pseudo-instructions */
    స్థితి TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        తిరిగి;
    స్థితి TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        తిరిగి;
    స్థితి TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        తిరిగి;
    స్థితి TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        తిరిగి;
    స్థితి TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        తిరిగి;
    స్థితి TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        తిరిగి;
    స్థితి TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        తిరిగి;
    స్థితి TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        తిరిగి;
    స్థితి TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        తిరిగి;
    అప్రమేయ:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
స్థిర శూన్య asm_emit_r(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం* rd, స్థిరరాశి నిర్వాహ్యం* rs1, స్థిరరాశి నిర్వాహ్యం* rs2)
{
    ఒకవేళ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, ఖాళీ));
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
స్థిర శూన్య asm_emit_f(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం* rd, స్థిరరాశి నిర్వాహ్యం* rs1, స్థిరరాశి నిర్వాహ్యం* rs2)
{
    ఒకవేళ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ఖాళీ));
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
స్థిర శూన్య asm_emit_fb(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం* rd, స్థిరరాశి నిర్వాహ్యం* rs)
{
    ఒకవేళ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, ఖాళీ));
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
స్థిర శూన్య asm_emit_fq(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం* rd, స్థిరరాశి నిర్వాహ్యం* rs1, స్థిరరాశి నిర్వాహ్యం* rs2, స్థిరరాశి నిర్వాహ్యం* rs3)
{
    ఒకవేళ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, ఖాళీ));
    }
    /* F-type instruction:
	     31...27 rs3
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (REG_విలువ(rs3->reg) << 27));
}

/* caller: Add funct3 into opcode */
స్థిర శూన్య asm_emit_i(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం* rd, స్థిరరాశి నిర్వాహ్యం* rs1, స్థిరరాశి నిర్వాహ్యం* rs2)
{
    ఒకవేళ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ఖాళీ));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

స్థిర శూన్య asm_emit_j(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం* rd, స్థిరరాశి నిర్వాహ్యం* rs2)
{
    uint32_t imm;

    ఒకవేళ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ఖాళీ));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    ఒకవేళ ((పూర్ణాంకం)imm > (1 << 20) -1 || (పూర్ణాంకం)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, ఖాళీ));
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

స్థిర శూన్య asm_mem_access_opcode(TCCState *s1, పూర్ణాంకం token)
{

    నిర్వాహ్యం ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    ఒకవేళ (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    ఎంపిక (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    స్థితి TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    స్థితి TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         తిరిగి;
    }
}

స్థిర శూన్య asm_branch_opcode(TCCState *s1, పూర్ణాంకం token, పూర్ణాంకం argc)
{
    నిర్వాహ్యం ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_స్థానభ్రంశం_నిర్వాహ్యం(s1, &ops[argc-1]);

    ఎంపిక(token){
    /* branch (RS1, RS2, IMM); B-format */
    స్థితి TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    /* related pseudoinstructions */
    స్థితి TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        తిరిగి;
    /* shorter pseudoinstructions */
    స్థితి TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        తిరిగి;
    స్థితి TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        తిరిగి;
    }
}

స్థిర శూన్య asm_ternary_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[3];
    parse_operands(s1, &ops[0], 3);

    ఎంపిక (token) {
    స్థితి TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        తిరిగి;
    స్థితి TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        తిరిగి;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    స్థితి TOK_ASM_కూడు:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         తిరిగి;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    స్థితి TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    స్థితి TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;
    స్థితి TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         తిరిగి;

    /* M extension */
    స్థితి TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        తిరిగి;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    స్థితి TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        తిరిగి;
    స్థితి TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        తిరిగి;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    స్థితి TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        తిరిగి;

    /* F/D extension */
    స్థితి TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        తిరిగి;
    స్థితి TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        తిరిగి;

    /* F/D comparison: produce integer result, encode manually */
    స్థితి TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        తిరిగి;
    స్థితి TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        తిరిగి;
    స్థితి TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        తిరిగి;
    స్థితి TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        తిరిగి;
    స్థితి TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        తిరిగి;
    స్థితి TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        తిరిగి;

    అప్రమేయ:
        expect("ternary instruction");
    }
}

స్థిర శూన్య asm_quaternary_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[4];
    parse_operands(s1, &ops[0], 4);

    ఎంపిక (token) {
    స్థితి TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        తిరిగి;
    స్థితి TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        తిరిగి;

    అప్రమేయ:
        expect("quaternary instruction");
    }
}

స్థిర శూన్య asm_atomic_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[3];

    parse_నిర్వాహ్యం(s1, &ops[0]);
    skip(',');

    ఒకవేళ ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } లేకపోతే {
        parse_నిర్వాహ్యం(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_నిర్వాహ్యం(s1, &ops[2]);
    skip(')');

    ఎంపిక(token){
        స్థితి TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ఆపు;
        స్థితి TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ఆపు;
        స్థితి TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ఆపు;
        స్థితి TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ఆపు;

        స్థితి TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ఆపు;
        స్థితి TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ఆపు;
        స్థితి TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ఆపు;
        స్థితి TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ఆపు;

        స్థితి TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ఆపు;
        స్థితి TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ఆపు;
        స్థితి TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ఆపు;
        స్థితి TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ఆపు;

        స్థితి TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ఆపు;
        స్థితి TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ఆపు;
        స్థితి TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ఆపు;
        స్థితి TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ఆపు;

        /* AMO instructions (base, aq=0 rl=0) */
        స్థితి TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;
        స్థితి TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ఆపు;

        /* AMO aq/rl variants */
        స్థితి TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;

        స్థితి TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
        స్థితి TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ఆపు;
        స్థితి TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ఆపు;
        స్థితి TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ఆపు;
    }
}

/* caller: Add funct3 and func5 to opcode */
స్థిర శూన్య asm_emit_a(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rd1, స్థిరరాశి నిర్వాహ్యం *rs2, స్థిరరాశి నిర్వాహ్యం *rs1, పూర్ణాంకం aq, పూర్ణాంకం rl)
{
    ఒకవేళ (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, ఖాళీ));
    ఒకవేళ (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ఖాళీ));
    ఒకవేళ (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, ఖాళీ));
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
స్థిర శూన్య asm_emit_s(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం* rs1, స్థిరరాశి నిర్వాహ్యం* rs2, స్థిరరాశి నిర్వాహ్యం* imm)
{
    ఒకవేళ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, ఖాళీ));
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

స్థిర శూన్య asm_emit_b(పూర్ణాంకం token, uint32_t opcode, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *rs2, స్థిరరాశి నిర్వాహ్యం *imm)
{
    uint32_t స్థానభ్రంశం;

    ఒకవేళ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }
    ఒకవేళ (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        పూర్ణాంకం b_ofs = ind;
        uint32_t inv_func3 = ((opcode >> 12) & 7) ^ 1;
        uint32_t inv_opcode = (opcode & ~(7 << 12)) | (inv_func3 << 12);
        /* b<inverse> .+8 */
        asm_emit_opcode(inv_opcode | ENCODE_RS1(rs1->reg)
                        | ENCODE_RS2(rs2->reg) | (1 << 8));
        /* auipc t0, 0 */
        greloca(cur_పాఠ్యం_section, imm->e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(0x17 | ENCODE_RD(5));
        /* jalr x0, 0(t0) */
        write32le(cur_పాఠ్యం_section->దత్తాంశం + b_ofs,
                  read32le(cur_పాఠ్యం_section->దత్తాంశం + b_ofs)
                  | (((ind - b_ofs) >> 1) & 0xf) << 8
                  | (((ind - b_ofs) >> 5) & 0x3f) << 25
                  | (((ind - b_ofs) >> 11) & 1) << 7
                  | (((ind - b_ofs) >> 12) & 1) << 31);
        తిరిగి;
    }
    ఒకవేళ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ఖాళీ));
    }

    స్థానభ్రంశం = imm->e.v;

    /* B-type instruction:
    31      imm[12]
    30...25 imm[10:5]
    24...20 rs2
    19...15 rs1
    14...12 funct3
    8...11  imm[4:1]
    7       imm[11]
    6...0   opcode */
    asm_emit_opcode(opcode | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (((స్థానభ్రంశం >> 1) & 0xF) << 8) | (((స్థానభ్రంశం >> 5) & 0x1f) << 25) | (((స్థానభ్రంశం >> 11) & 1) << 7) | (((స్థానభ్రంశం >> 12) & 1) << 31));
}

/* FCVT helper: parse optional rounding mode operand (GNU as syntax:
   fcvt.w.s rd, rs1 [, rtz/rne/rdn/rup/rmm]) */
స్థిర పూర్ణాంకం asm_fcvt_rm(TCCState *s1)
{
    పూర్ణాంకం rm = 7; /* dynamic */
    ఒకవేళ (tok == ',') {
        తదుపరి();
        ఎంపిక (tok) {
            స్థితి TOK_ASM_rne: rm = 0; తదుపరి(); ఆపు;
            స్థితి TOK_ASM_rtz: rm = 1; తదుపరి(); ఆపు;
            స్థితి TOK_ASM_rdn: rm = 2; తదుపరి(); ఆపు;
            స్థితి TOK_ASM_rup: rm = 3; తదుపరి(); ఆపు;
            స్థితి TOK_ASM_rmm: rm = 4; తదుపరి(); ఆపు;
            అప్రమేయ: expect("rounding mode"); ఆపు;
        }
    }
    తిరిగి rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
స్థిర శూన్య asm_fcvt_opcode(TCCState *s1, పూర్ణాంకం token)
{
    నిర్వాహ్యం ops[2];
    పూర్ణాంకం rm;
    uint32_t enc = 0;

    parse_నిర్వాహ్యం(s1, &ops[0]);
    skip(',');
    parse_నిర్వాహ్యం(s1, &ops[1]);

    ఎంపిక (token) {
        స్థితి TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); ఆపు;
        స్థితి TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); ఆపు;
        స్థితి TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); ఆపు;
        స్థితి TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); ఆపు;
        స్థితి TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); ఆపు;
        స్థితి TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); ఆపు;
        స్థితి TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); ఆపు;
        స్థితి TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); ఆపు;
        అప్రమేయ: expect("fcvt/fclass instruction"); తిరిగి;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC శూన్య asm_opcode(TCCState *s1, పూర్ణాంకం token)
{
    ఎంపిక (token) {
    స్థితి TOK_ASM_ebreak:
    స్థితి TOK_ASM_ecall:
    స్థితి TOK_ASM_fence_i:
    స్థితి TOK_ASM_hrts:
    స్థితి TOK_ASM_mrth:
    స్థితి TOK_ASM_mrts:
    స్థితి TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_rdcycle:
    స్థితి TOK_ASM_rdcycleh:
    స్థితి TOK_ASM_rdtime:
    స్థితి TOK_ASM_rdtimeh:
    స్థితి TOK_ASM_rdinstret:
    స్థితి TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_lui:
    స్థితి TOK_ASM_auipc:
    స్థితి TOK_ASM_fsqrt_s:
    స్థితి TOK_ASM_fsqrt_d:
        asm_ద్విమాన_opcode(s1, token);
        తిరిగి;

    /* fcvt/fclass — separate handler for optional rounding operand */
    స్థితి TOK_ASM_fcvt_w_s:
    స్థితి TOK_ASM_fcvt_wu_s:
    స్థితి TOK_ASM_fcvt_l_s:
    స్థితి TOK_ASM_fcvt_lu_s:
    స్థితి TOK_ASM_fcvt_s_w:
    స్థితి TOK_ASM_fcvt_s_wu:
    స్థితి TOK_ASM_fcvt_s_l:
    స్థితి TOK_ASM_fcvt_s_lu:
    స్థితి TOK_ASM_fcvt_w_d:
    స్థితి TOK_ASM_fcvt_wu_d:
    స్థితి TOK_ASM_fcvt_l_d:
    స్థితి TOK_ASM_fcvt_lu_d:
    స్థితి TOK_ASM_fcvt_d_w:
    స్థితి TOK_ASM_fcvt_d_wu:
    స్థితి TOK_ASM_fcvt_d_l:
    స్థితి TOK_ASM_fcvt_d_lu:
    స్థితి TOK_ASM_fcvt_s_d:
    స్థితి TOK_ASM_fcvt_d_s:
    స్థితి TOK_ASM_fclass_s:
    స్థితి TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_lb:
    స్థితి TOK_ASM_lh:
    స్థితి TOK_ASM_lw:
    స్థితి TOK_ASM_ld:
    స్థితి TOK_ASM_fld:
    స్థితి TOK_ASM_lbu:
    స్థితి TOK_ASM_lhu:
    స్థితి TOK_ASM_lwu:
    స్థితి TOK_ASM_sb:
    స్థితి TOK_ASM_sh:
    స్థితి TOK_ASM_sw:
    స్థితి TOK_ASM_sd:
    స్థితి TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        ఆపు;

    స్థితి TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        ఆపు;
    స్థితి TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        తిరిగి;
    స్థితి TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        ఆపు;

    స్థితి TOK_ASM_కూడు:
    స్థితి TOK_ASM_addi:
    స్థితి TOK_ASM_addiw:
    స్థితి TOK_ASM_addw:
    స్థితి TOK_ASM_and:
    స్థితి TOK_ASM_andi:
    స్థితి TOK_ASM_or:
    స్థితి TOK_ASM_ori:
    స్థితి TOK_ASM_sll:
    స్థితి TOK_ASM_slli:
    స్థితి TOK_ASM_slliw:
    స్థితి TOK_ASM_sllw:
    స్థితి TOK_ASM_slt:
    స్థితి TOK_ASM_slti:
    స్థితి TOK_ASM_sltiu:
    స్థితి TOK_ASM_sltu:
    స్థితి TOK_ASM_sra:
    స్థితి TOK_ASM_srai:
    స్థితి TOK_ASM_sraiw:
    స్థితి TOK_ASM_sraw:
    స్థితి TOK_ASM_srl:
    స్థితి TOK_ASM_srli:
    స్థితి TOK_ASM_srliw:
    స్థితి TOK_ASM_srlw:
    స్థితి TOK_ASM_sub:
    స్థితి TOK_ASM_subw:
    స్థితి TOK_ASM_xor:
    స్థితి TOK_ASM_xori:
    /* M extension */
    స్థితి TOK_ASM_div:
    స్థితి TOK_ASM_divu:
    స్థితి TOK_ASM_divuw:
    స్థితి TOK_ASM_divw:
    స్థితి TOK_ASM_mul:
    స్థితి TOK_ASM_mulh:
    స్థితి TOK_ASM_mulhsu:
    స్థితి TOK_ASM_mulhu:
    స్థితి TOK_ASM_mulw:
    స్థితి TOK_ASM_rem:
    స్థితి TOK_ASM_remu:
    స్థితి TOK_ASM_remuw:
    స్థితి TOK_ASM_remw:
    /* Zicsr extension */
    స్థితి TOK_ASM_csrrc:
    స్థితి TOK_ASM_csrrci:
    స్థితి TOK_ASM_csrrs:
    స్థితి TOK_ASM_csrrsi:
    స్థితి TOK_ASM_csrrw:
    స్థితి TOK_ASM_csrrwi:
    /* F/D extension */
    స్థితి TOK_ASM_fadd_s:
    స్థితి TOK_ASM_fadd_d:
    స్థితి TOK_ASM_fsub_s:
    స్థితి TOK_ASM_fsub_d:
    స్థితి TOK_ASM_fmul_s:
    స్థితి TOK_ASM_fmul_d:
    స్థితి TOK_ASM_fdiv_s:
    స్థితి TOK_ASM_fdiv_d:
    స్థితి TOK_ASM_fsgnj_d:
    స్థితి TOK_ASM_fsgnj_s:
    స్థితి TOK_ASM_fmax_s:
    స్థితి TOK_ASM_fmax_d:
    స్థితి TOK_ASM_fmin_s:
    స్థితి TOK_ASM_fmin_d:
    స్థితి TOK_ASM_feq_s:
    స్థితి TOK_ASM_feq_d:
    స్థితి TOK_ASM_flt_s:
    స్థితి TOK_ASM_flt_d:
    స్థితి TOK_ASM_fle_s:
    స్థితి TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        తిరిగి;
    స్థితి TOK_ASM_fmadd_d:
    స్థితి TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        తిరిగి;

    /* Branches */
    స్థితి TOK_ASM_beq:
    స్థితి TOK_ASM_bge:
    స్థితి TOK_ASM_bgeu:
    స్థితి TOK_ASM_blt:
    స్థితి TOK_ASM_bltu:
    స్థితి TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        ఆపు;

    /* C extension */
    స్థితి TOK_ASM_c_ebreak:
    స్థితి TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_c_j:
    స్థితి TOK_ASM_c_jal:
    స్థితి TOK_ASM_c_jalr:
    స్థితి TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_c_కూడు:
    స్థితి TOK_ASM_c_addi16sp:
    స్థితి TOK_ASM_c_addi4spn:
    స్థితి TOK_ASM_c_addi:
    స్థితి TOK_ASM_c_addiw:
    స్థితి TOK_ASM_c_addw:
    స్థితి TOK_ASM_c_and:
    స్థితి TOK_ASM_c_andi:
    స్థితి TOK_ASM_c_beqz:
    స్థితి TOK_ASM_c_bnez:
    స్థితి TOK_ASM_c_fldsp:
    స్థితి TOK_ASM_c_flwsp:
    స్థితి TOK_ASM_c_fsdsp:
    స్థితి TOK_ASM_c_fswsp:
    స్థితి TOK_ASM_c_ldsp:
    స్థితి TOK_ASM_c_li:
    స్థితి TOK_ASM_c_lui:
    స్థితి TOK_ASM_c_lwsp:
    స్థితి TOK_ASM_c_mv:
    స్థితి TOK_ASM_c_or:
    స్థితి TOK_ASM_c_sdsp:
    స్థితి TOK_ASM_c_slli:
    స్థితి TOK_ASM_c_srai:
    స్థితి TOK_ASM_c_srli:
    స్థితి TOK_ASM_c_sub:
    స్థితి TOK_ASM_c_subw:
    స్థితి TOK_ASM_c_swsp:
    స్థితి TOK_ASM_c_xor:
        asm_ద్విమాన_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_c_fld:
    స్థితి TOK_ASM_c_flw:
    స్థితి TOK_ASM_c_fsd:
    స్థితి TOK_ASM_c_fsw:
    స్థితి TOK_ASM_c_ld:
    స్థితి TOK_ASM_c_lw:
    స్థితి TOK_ASM_c_sd:
    స్థితి TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        తిరిగి;

    /* pseudoinstructions */
    స్థితి TOK_ASM_nop:
    స్థితి TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_jr:
    స్థితి TOK_ASM_call:
    స్థితి TOK_ASM_తోక:
    స్థితి TOK_ASM_frflags:
    స్థితి TOK_ASM_frrm:
    స్థితి TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_la:
    స్థితి TOK_ASM_lla:
    స్థితి TOK_ASM_li:
    స్థితి TOK_ASM_jump:
    స్థితి TOK_ASM_seqz:
    స్థితి TOK_ASM_snez:
    స్థితి TOK_ASM_sltz:
    స్థితి TOK_ASM_sgtz:
    స్థితి TOK_ASM_mv:
    స్థితి TOK_ASM_not:
    స్థితి TOK_ASM_neg:
    స్థితి TOK_ASM_negw:
    స్థితి TOK_ASM_sext_w:
    స్థితి TOK_ASM_fabs_s:
    స్థితి TOK_ASM_fabs_d:
    స్థితి TOK_ASM_fmv_s:
    స్థితి TOK_ASM_fmv_d:
    స్థితి TOK_ASM_fneg_s:
    స్థితి TOK_ASM_fneg_d:
    స్థితి TOK_ASM_csrc:
    స్థితి TOK_ASM_csrs:
    స్థితి TOK_ASM_csrr:
    స్థితి TOK_ASM_csrw:
    స్థితి TOK_ASM_csrwi:
    స్థితి TOK_ASM_csrsi:
    స్థితి TOK_ASM_csrci:
    స్థితి TOK_ASM_fsrm:
    స్థితి TOK_ASM_fscsr:
        asm_ద్విమాన_opcode(s1, token);
        తిరిగి;

    స్థితి TOK_ASM_bnez:
    స్థితి TOK_ASM_beqz:
    స్థితి TOK_ASM_blez:
    స్థితి TOK_ASM_bgez:
    స్థితి TOK_ASM_bltz:
    స్థితి TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        తిరిగి;

    స్థితి TOK_ASM_bgt:
    స్థితి TOK_ASM_bgtu:
    స్థితి TOK_ASM_ble:
    స్థితి TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        తిరిగి;

    /* Atomic operations */
    స్థితి TOK_ASM_lr_w:
    స్థితి TOK_ASM_lr_w_aq:
    స్థితి TOK_ASM_lr_w_rl:
    స్థితి TOK_ASM_lr_w_aqrl:
    స్థితి TOK_ASM_lr_d:
    స్థితి TOK_ASM_lr_d_aq:
    స్థితి TOK_ASM_lr_d_rl:
    స్థితి TOK_ASM_lr_d_aqrl:
    స్థితి TOK_ASM_sc_w:
    స్థితి TOK_ASM_sc_w_aq:
    స్థితి TOK_ASM_sc_w_rl:
    స్థితి TOK_ASM_sc_w_aqrl:
    స్థితి TOK_ASM_sc_d:
    స్థితి TOK_ASM_sc_d_aq:
    స్థితి TOK_ASM_sc_d_rl:
    స్థితి TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    స్థితి TOK_ASM_amoadd_w:
    స్థితి TOK_ASM_amoadd_d:
    స్థితి TOK_ASM_amoswap_w:
    స్థితి TOK_ASM_amoswap_d:
    స్థితి TOK_ASM_amoand_w:
    స్థితి TOK_ASM_amoand_d:
    స్థితి TOK_ASM_amoor_w:
    స్థితి TOK_ASM_amoor_d:
    స్థితి TOK_ASM_amoxor_w:
    స్థితి TOK_ASM_amoxor_d:
    స్థితి TOK_ASM_amomax_w:
    స్థితి TOK_ASM_amomax_d:
    స్థితి TOK_ASM_amomaxu_w:
    స్థితి TOK_ASM_amomaxu_d:
    స్థితి TOK_ASM_amomin_w:
    స్థితి TOK_ASM_amomin_d:
    స్థితి TOK_ASM_amominu_w:
    స్థితి TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    స్థితి TOK_ASM_amoadd_w_aq:
    స్థితి TOK_ASM_amoadd_w_rl:
    స్థితి TOK_ASM_amoadd_w_aqrl:
    స్థితి TOK_ASM_amoadd_d_aq:
    స్థితి TOK_ASM_amoadd_d_rl:
    స్థితి TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    స్థితి TOK_ASM_amoswap_w_aq:
    స్థితి TOK_ASM_amoswap_w_rl:
    స్థితి TOK_ASM_amoswap_w_aqrl:
    స్థితి TOK_ASM_amoswap_d_aq:
    స్థితి TOK_ASM_amoswap_d_rl:
    స్థితి TOK_ASM_amoswap_d_aqrl:
    స్థితి TOK_ASM_amoand_w_aq:
    స్థితి TOK_ASM_amoand_w_rl:
    స్థితి TOK_ASM_amoand_w_aqrl:
    స్థితి TOK_ASM_amoand_d_aq:
    స్థితి TOK_ASM_amoand_d_rl:
    స్థితి TOK_ASM_amoand_d_aqrl:
    స్థితి TOK_ASM_amoor_w_aq:
    స్థితి TOK_ASM_amoor_w_rl:
    స్థితి TOK_ASM_amoor_w_aqrl:
    స్థితి TOK_ASM_amoor_d_aq:
    స్థితి TOK_ASM_amoor_d_rl:
    స్థితి TOK_ASM_amoor_d_aqrl:
    స్థితి TOK_ASM_amoxor_w_aq:
    స్థితి TOK_ASM_amoxor_w_rl:
    స్థితి TOK_ASM_amoxor_w_aqrl:
    స్థితి TOK_ASM_amoxor_d_aq:
    స్థితి TOK_ASM_amoxor_d_rl:
    స్థితి TOK_ASM_amoxor_d_aqrl:
    స్థితి TOK_ASM_amomax_w_aq:
    స్థితి TOK_ASM_amomax_w_rl:
    స్థితి TOK_ASM_amomax_w_aqrl:
    స్థితి TOK_ASM_amomax_d_aq:
    స్థితి TOK_ASM_amomax_d_rl:
    స్థితి TOK_ASM_amomax_d_aqrl:
    స్థితి TOK_ASM_amomaxu_w_aq:
    స్థితి TOK_ASM_amomaxu_w_rl:
    స్థితి TOK_ASM_amomaxu_w_aqrl:
    స్థితి TOK_ASM_amomaxu_d_aq:
    స్థితి TOK_ASM_amomaxu_d_rl:
    స్థితి TOK_ASM_amomaxu_d_aqrl:
    స్థితి TOK_ASM_amomin_w_aq:
    స్థితి TOK_ASM_amomin_w_rl:
    స్థితి TOK_ASM_amomin_w_aqrl:
    స్థితి TOK_ASM_amomin_d_aq:
    స్థితి TOK_ASM_amomin_d_rl:
    స్థితి TOK_ASM_amomin_d_aqrl:
    స్థితి TOK_ASM_amominu_w_aq:
    స్థితి TOK_ASM_amominu_w_rl:
    స్థితి TOK_ASM_amominu_w_aqrl:
    స్థితి TOK_ASM_amominu_d_aq:
    స్థితి TOK_ASM_amominu_d_rl:
    స్థితి TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        ఆపు;

    అప్రమేయ:
        expect("known instruction");
    }
}

స్థిర పూర్ణాంకం asm_parse_csrvar(పూర్ణాంకం t)
{
    ఎంపిక (t) {
    స్థితి TOK_ASM_చక్రం:
        తిరిగి 0xc00;
    స్థితి TOK_ASM_fcsr:
        తిరిగి 3;
    స్థితి TOK_ASM_fflags:
        తిరిగి 1;
    స్థితి TOK_ASM_frm:
        తిరిగి 2;
    స్థితి TOK_ASM_instret:
        తిరిగి 0xc02;
    స్థితి TOK_ASM_సమయం:
        తిరిగి 0xc01;
    స్థితి TOK_ASM_cycleh:
        తిరిగి 0xc80;
    స్థితి TOK_ASM_instreth:
        తిరిగి 0xc82;
    స్థితి TOK_ASM_timeh:
        తిరిగి 0xc81;
    అప్రమేయ:
        తిరిగి -1;
    }
}

ST_FUNC శూన్య subst_asm_నిర్వాహ్యం(CString *కూడు_str, SValue *sv, పూర్ణాంకం modifier)
{
    పూర్ణాంకం r, reg, val;

    r = sv->r;
    ఒకవేళ ((r & VT_VALMASK) == VT_CONST) {
        ఒకవేళ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        ఒకవేళ (r & VT_SYM) {
            స్థిరరాశి అక్షరం *name = get_tok_str(sv->sym->v, ఖాళీ);
            ఒకవేళ (sv->sym->v >= SYM_మొదటి_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, అక్షరశ్రేణి_పొడవు(name))->tok, sv->sym);
            }
            ఒకవేళ (tcc_state->leading_underscore)
                cstr_ccat(కూడు_str, '_');
            cstr_cat(కూడు_str, name, -1);
            ఒకవేళ ((uint32_t) sv->c.i == 0)
                వెళ్ళు no_స్థానభ్రంశం;
            cstr_ccat(కూడు_str, '+');
        }
        val = sv->c.i;
        ఒకవేళ (modifier == 'n')
            val = -val;
        ఒకవేళ (modifier == 'z' && val == 0) {
            cstr_cat(కూడు_str, "zero", -1);
        } లేకపోతే {
            cstr_printf(కూడు_str, "%d", val);
        }
      no_స్థానభ్రంశం:;
    } లేకపోతే ఒకవేళ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(కూడు_str, "%d", (పూర్ణాంకం) sv->c.i);
    } లేకపోతే ఒకవేళ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ఒకవేళ (reg >= VT_CONST)
            tcc_అంతర్గత_error("");
        ఒకవేళ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_విలువ(reg);
        } లేకపోతే {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(కూడు_str, get_tok_str(reg, ఖాళీ), -1);
    } లేకపోతే {
        /* register case */
        reg = r & VT_VALMASK;
        ఒకవేళ (reg >= VT_CONST)
            tcc_అంతర్గత_error("");
        ఒకవేళ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_విలువ(reg);
        } లేకపోతే {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(కూడు_str, get_tok_str(reg, ఖాళీ), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
స్థిర పూర్ణాంకం tcc_ireg(పూర్ణాంకం r){
    తిరిగి REG_విలువ(r) - 10;
}
స్థిర పూర్ణాంకం tcc_freg(పూర్ణాంకం r){
    తిరిగి REG_విలువ(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC శూన్య asm_gen_సంకేతం(ASMOperand *operands, పూర్ణాంకం nb_operands,
                         పూర్ణాంకం nb_outputs, పూర్ణాంకం is_output,
                         uint8_t *clobber_regs,
                         పూర్ణాంకం బహిర్గతం_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    పూర్ణాంకం i, reg;

    స్థిర స్థిరరాశి uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    జ్ఞాపకం_నకలు(regs_allocated, clobber_regs, పరిమాణం(regs_allocated));
    కొరకు(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ఒకవేళ (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    ఒకవేళ(!is_output) {
        /* generate reg save code */
        కొరకు(i = 0; i < పరిమాణం(reg_saved)/పరిమాణం(reg_saved[0]); i++) {
            reg = reg_saved[i];
            ఒకవేళ (regs_allocated[reg]) {
                /*నెట్టు*/
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (గుర్తులేని)-8 << 20);
                ఒకవేళ (REG_IS_FLOAT(reg)){
                    /* fsd reg, offset(sp) */
                    gen_le32( 0x27 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                } లేకపోతే {
                    /* sd reg, offset(sp) */
                    gen_le32((0x8 << 2) | 3 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                }
            }
        }

        /* generate load code */
        కొరకు(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ఒకవేళ (op->reg >= 0) {
                ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_జ్ఞాపకం) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    ఎక్కించు(tcc_ireg(op->reg), &sv);
                } లేకపోతే ఒకవేళ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    ఒకవేళ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        ఎక్కించు(tcc_freg(op->reg), op->vt);
                    } లేకపోతే {
                        ఎక్కించు(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register;
                       the load/store above already handles it correctly */
                }
            }
        }
    } లేకపోతే {
        /* generate save code */
        కొరకు(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ఒకవేళ (op->reg >= 0) {
                ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ఒకవేళ (!op->is_జ్ఞాపకం) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        ఎక్కించు(tcc_ireg(బహిర్గతం_reg), &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | బహిర్గతం_reg;
                        store(tcc_ireg(op->reg), &sv);
                    }
                } లేకపోతే {
                    ఒకవేళ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        store(tcc_freg(op->reg), op->vt);
                    } లేకపోతే {
                        store(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register */
                }
            }
        }
        /* generate reg restore code for floating point registers */
        కొరకు(i = పరిమాణం(reg_saved)/పరిమాణం(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            ఒకవేళ (regs_allocated[reg]) {
                /*తీయి*/
                ఒకవేళ (REG_IS_FLOAT(reg)){
                    /* fld reg, offset(sp) */
                    gen_le32(7 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                } లేకపోతే {
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
స్థిర అంతఃవరుస పూర్ణాంకం constraint_ప్రాధాన్యత(స్థిరరాశి అక్షరం *str)
{
    // TODO: How is this chosen??
    పూర్ణాంకం ప్రాధాన్యత, c, pr;

    /* we take the lowest priority */
    ప్రాధాన్యత = 0;
    కొరకు(;;) {
        c = *str;
        ఒకవేళ (c == '\0')
            ఆపు;
        str++;
        ఎంపిక(c) {
        స్థితి 'A': // address that is held in a general-purpose register.
        స్థితి 'S': // constraint that matches an absolute symbolic address.
        స్థితి 'f': // register [float]
        స్థితి 'r': // register [general]
        స్థితి 'p': // valid memory address for load,store [general]
            pr = 3;
            ఆపు;
        స్థితి 'I': // 12 bit signed immedate
        స్థితి 'i': // immediate integer operand, including symbolic constants [general]
        స్థితి 'm': // memory operand [general]
        స్థితి 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ఆపు;
        స్థితి 'v':
            tcc_error("unimp: constraint '%c'", c);
        అప్రమేయ:
            tcc_error("unknown constraint '%d'", c);
        }
        ఒకవేళ (pr > ప్రాధాన్యత)
            ప్రాధాన్యత = pr;
    }
    తిరిగి ప్రాధాన్యత;
}

స్థిర స్థిరరాశి అక్షరం *skip_constraint_modifiers(స్థిరరాశి అక్షరం *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    అయితే (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    తిరిగి p;
}

#నిర్వచించు REG_బహిర్గతం_ముసుగు 0x01
#నిర్వచించు REG_లోపల_ముసుగు  0x02

#నిర్వచించు is_reg_allocated(reg) (regs_allocated[reg] & reg_ముసుగు)

ST_FUNC శూన్య asm_compute_constraints(ASMOperand *operands,
                                    పూర్ణాంకం nb_operands, పూర్ణాంకం nb_outputs,
                                    స్థిరరాశి uint8_t *clobber_regs,
                                    పూర్ణాంకం *pout_reg)
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
    పూర్ణాంకం sorted_op[MAX_ASM_OPERANDS];
    పూర్ణాంకం i, j, k, p1, p2, tmp, reg, c, reg_ముసుగు;
    స్థిరరాశి అక్షరం *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    కొరకు (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ఆదానం_సూచీ = -1;
        op->ref_సూచీ = -1;
        op->reg = -1;
        op->is_జ్ఞాపకం = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    కొరకు (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ఒకవేళ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = కనుగొను_constraint(operands, nb_operands, str, ఖాళీ);
            ఒకవేళ ((గుర్తులేని) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_సూచీ = k;
            ఒకవేళ (operands[k].ఆదానం_సూచీ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ఆదానం_సూచీ = i;
            op->ప్రాధాన్యత = 5;
        } లేకపోతే ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->ప్రాధాన్యత = 1;
            op->reg = reg;
        } లేకపోతే {
            op->ప్రాధాన్యత = constraint_ప్రాధాన్యత(str);
        }
    }

    /* sort operands according to their priority */
    కొరకు (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    కొరకు (i = 0; i < nb_operands - 1; i++) {
        కొరకు (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].ప్రాధాన్యత;
            p2 = operands[sorted_op[j]].ప్రాధాన్యత;
            ఒకవేళ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    కొరకు (i = 0; i < NB_ASM_REGS; i++) {
        ఒకవేళ (clobber_regs[i])
            regs_allocated[i] = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
        లేకపోతే
            regs_allocated[i] = 0;
    }

    /* allocate registers and generate corresponding asm moves */
    కొరకు (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ఒకవేళ (op->ref_సూచీ >= 0)
            కొనసాగు;
        /* select if register is used for output, input or both */
        ఒకవేళ (op->ఆదానం_సూచీ >= 0) {
            reg_ముసుగు = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
        } లేకపోతే ఒకవేళ (j < nb_outputs) {
            reg_ముసుగు = REG_బహిర్గతం_ముసుగు;
        } లేకపోతే {
            reg_ముసుగు = REG_లోపల_ముసుగు;
        }
        ఒకవేళ (op->reg >= 0) {
            ఒకవేళ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_తదుపరి:
        c = *str++;
        ఎంపిక (c) {
        స్థితి '=': // Operand is written-to
            వెళ్ళు try_తదుపరి;
        స్థితి '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        స్థితి '&': // Operand is clobbered before the instruction is done using the input operands
            ఒకవేళ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_ముసుగు = REG_లోపల_ముసుగు | REG_బహిర్గతం_ముసుగు;
            వెళ్ళు try_తదుపరి;
        స్థితి 'r': // general-purpose register
        స్థితి 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            ఒకవేళ ((reg = op->reg) >= 0)
                వెళ్ళు reg_దొరికింది;
            లేకపోతే కొరకు (reg = 10; reg <= 18; reg++) {
                ఒకవేళ (!is_reg_allocated(reg))
                    వెళ్ళు reg_దొరికింది;
            }
            వెళ్ళు try_తదుపరి;
          reg_దొరికింది:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_ముసుగు;
            ఆపు;
        స్థితి 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            ఒకవేళ ((reg = op->reg) >= 0)
                వెళ్ళు reg_దొరికింది;
            లేకపోతే కొరకు (reg = 42; reg <= 50; reg++) {
                ఒకవేళ (!is_reg_allocated(reg))
                    వెళ్ళు reg_దొరికింది;
            }
            వెళ్ళు try_తదుపరి;
        స్థితి 'I': // I-Type 12 bit signed immediate
        స్థితి 'i': // immediate integer operand, including symbolic constants
            ఒకవేళ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                వెళ్ళు try_తదుపరి;
            ఆపు;
        స్థితి 'm': // memory operand
        స్థితి 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ఒకవేళ (j < nb_outputs || c == 'm') {
                ఒకవేళ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    కొరకు (reg = 10; reg <= 18; reg++) {
                        ఒకవేళ (!(regs_allocated[reg] & REG_లోపల_ముసుగు))
                            వెళ్ళు reg_found1;
                    }
                    వెళ్ళు try_తదుపరి;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_లోపల_ముసుగు;
                    op->reg = reg;
                    op->is_జ్ఞాపకం = 1;
                }
            }
            ఆపు;
        అప్రమేయ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ఆపు;
        }
        /* if a reference is present for that operand, we assign it too */
        ఒకవేళ (op->ఆదానం_సూచీ >= 0) {
            operands[op->ఆదానం_సూచీ].reg = op->reg;
            operands[op->ఆదానం_సూచీ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    కొరకు (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ఒకవేళ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_జ్ఞాపకం) {
            ఒకవేళ (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                కొరకు (reg = 42; reg <= 50; reg++) {
                    ఒకవేళ (!(regs_allocated[reg] & REG_బహిర్గతం_ముసుగు))
                        వెళ్ళు reg_found2;
                }
            } లేకపోతే {
                /* From a0 to a7 */
                కొరకు (reg = 10; reg <= 18; reg++) {
                    ఒకవేళ (!(regs_allocated[reg] & REG_బహిర్గతం_ముసుగు))
                        వెళ్ళు reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ఆపు;
        }
    }

    /* print sorted constraints */
#నిర్వచితమైతే ASM_DEBUG
    కొరకు (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        రాయి("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ఖాళీ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ఒకవేళ (*pout_reg >= 0)
        రాయి("out_reg=%d\n", *pout_reg);
#అయితే_ముగింపు
}

ST_FUNC శూన్య asm_clobber(uint8_t *clobber_regs, స్థిరరాశి అక్షరం *str)
{
    పూర్ణాంకం reg;
    TokenSym *ts;

    ఒకవేళ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        తిరిగి;
    ts = tok_alloc(str, అక్షరశ్రేణి_పొడవు(str));
    reg = asm_parse_regvar(ts->tok);
    ఒకవేళ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC పూర్ణాంకం asm_parse_regvar (పూర్ణాంకం t)
{
    /* PC register not implemented */
    ఒకవేళ (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        తిరిగి -1;

    ఒకవేళ (t < TOK_ASM_f0)
        తిరిగి t - TOK_ASM_x0;

    ఒకవేళ (t < TOK_ASM_zero)
        తిరిగి t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    ఒకవేళ (t < TOK_ASM_ft0)
        తిరిగి t - TOK_ASM_zero;

    తిరిగి t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
స్థిర శూన్య asm_emit_ca(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs2)
{
    uint8_t dst, src;

    ఒకవేళ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ఖాళీ));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    ఒకవేళ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ఖాళీ));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

స్థిర శూన్య asm_emit_cb(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *imm)
{
    uint32_t స్థానభ్రంశం;
    uint8_t src;

    ఒకవేళ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ఖాళీ));
    }

    స్థానభ్రంశం = imm->e.v;

    ఒకవేళ (స్థానభ్రంశం & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ఖాళీ));
    }

    src = rs1->reg - 8;

    ఒకవేళ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ఖాళీ));
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

    ఎంపిక (token) {
    స్థితి TOK_ASM_c_beqz:
    స్థితి TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_బిట్టు(స్థానభ్రంశం, 5) | (((స్థానభ్రంశం >> 1) & 3) << 1) | (((స్థానభ్రంశం >> 6) & 3) << 3)) << 2) | ((((స్థానభ్రంశం >> 3) & 3) | NTH_బిట్టు(స్థానభ్రంశం, 8)) << 10));
        తిరిగి;
    అప్రమేయ:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((స్థానభ్రంశం & 0x1f) << 2) | (NTH_బిట్టు(స్థానభ్రంశం, 5) << 12));
        తిరిగి;
    }
}

స్థిర శూన్య asm_emit_ci(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *imm)
{
    uint32_t తక్షణ;

    ఒకవేళ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ఖాళీ));
    }

    తక్షణ = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    ఎంపిక (token) {
    స్థితి TOK_ASM_c_addi:
    స్థితి TOK_ASM_c_addiw:
    స్థితి TOK_ASM_c_li:
    స్థితి TOK_ASM_c_slli:
        gen_le16(opcode | ((తక్షణ & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_బిట్టు(తక్షణ, 5) << 12));
        తిరిగి;
    స్థితి TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_బిట్టు(తక్షణ, 5) << 2 | (((తక్షణ >> 7) & 3) << 3) | NTH_బిట్టు(తక్షణ, 6) << 5 | NTH_బిట్టు(తక్షణ, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_బిట్టు(తక్షణ, 9) << 12));
        తిరిగి;
    స్థితి TOK_ASM_c_lui:
        gen_le16(opcode | (((తక్షణ >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_బిట్టు(తక్షణ, 17) << 12));
        తిరిగి;
    స్థితి TOK_ASM_c_fldsp:
    స్థితి TOK_ASM_c_ldsp:
        gen_le16(opcode | (((తక్షణ >> 6) & 7) << 2) | (((తక్షణ >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_బిట్టు(తక్షణ, 5) << 12));
        తిరిగి;
    స్థితి TOK_ASM_c_flwsp:
    స్థితి TOK_ASM_c_lwsp:
        gen_le16(opcode | (((తక్షణ >> 6) & 3) << 2) | (((తక్షణ >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_బిట్టు(తక్షణ, 5) << 12));
        తిరిగి;
    స్థితి TOK_ASM_c_nop:
        gen_le16(opcode);
        తిరిగి;
    అప్రమేయ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
స్థిర శూన్య asm_emit_ciw(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    ఒకవేళ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ఖాళీ));
    }

    dst = rd->reg - 8;

    ఒకవేళ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ఖాళీ));
    }

    nzuimm = imm->e.v;

    ఒకవేళ (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, ఖాళీ));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_బిట్టు(nzuimm, 3) | (NTH_బిట్టు(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
స్థిర శూన్య asm_emit_cj(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *imm)
{
    uint32_t స్థానభ్రంశం;

    /* +-2 KiB range */
    ఒకవేళ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, ఖాళీ));
    }

    స్థానభ్రంశం = imm->e.v;

    ఒకవేళ (స్థానభ్రంశం & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ఖాళీ));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_బిట్టు(స్థానభ్రంశం, 5) << 2) | (((స్థానభ్రంశం >> 1) & 7) << 3) | (NTH_బిట్టు(స్థానభ్రంశం, 7) << 6) | (NTH_బిట్టు(స్థానభ్రంశం, 6) << 7) | (NTH_బిట్టు(స్థానభ్రంశం, 10) << 8) | (((స్థానభ్రంశం >> 8) & 3) << 9) | (NTH_బిట్టు(స్థానభ్రంశం, 4) << 11) | (NTH_బిట్టు(స్థానభ్రంశం, 11) << 12));
}

/* caller: Add funct3 into opcode */
స్థిర శూన్య asm_emit_cl(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *imm)
{
    uint32_t స్థానభ్రంశం;
    uint8_t dst, src;

    ఒకవేళ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ఖాళీ));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    ఒకవేళ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ఖాళీ));
    }

    స్థానభ్రంశం = imm->e.v;

    ఒకవేళ (స్థానభ్రంశం > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (స్థానభ్రంశం & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ఖాళీ));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    ఎంపిక (token) {
    /* imm variant 1 */
    స్థితి TOK_ASM_c_flw:
    స్థితి TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_బిట్టు(స్థానభ్రంశం, 6) << 5) | (NTH_బిట్టు(స్థానభ్రంశం, 2) << 6) | (((స్థానభ్రంశం >> 3) & 7) << 10));
        తిరిగి;
    /* imm variant 2 */
    స్థితి TOK_ASM_c_fld:
    స్థితి TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((స్థానభ్రంశం >> 6) & 3) << 5) | (((స్థానభ్రంశం >> 3) & 7) << 10));
        తిరిగి;
    అప్రమేయ:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
స్థిర శూన్య asm_emit_cr(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rd, స్థిరరాశి నిర్వాహ్యం *rs2)
{
    ఒకవేళ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ఖాళీ));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
స్థిర శూన్య asm_emit_cs(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rs2, స్థిరరాశి నిర్వాహ్యం *rs1, స్థిరరాశి నిర్వాహ్యం *imm)
{
    uint32_t స్థానభ్రంశం;
    uint8_t పునాది, src;

    ఒకవేళ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ఖాళీ));
    }

    పునాది = rs1->reg - 8;
    src = rs2->reg - 8;

    ఒకవేళ (పునాది > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ఖాళీ));
    }

    స్థానభ్రంశం = imm->e.v;

    ఒకవేళ (స్థానభ్రంశం > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (స్థానభ్రంశం & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ఖాళీ));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    ఎంపిక (token) {
    /* imm variant 1 */
    స్థితి TOK_ASM_c_fsw:
    స్థితి TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(పునాది) | C_ENCODE_RS1(src) | (NTH_బిట్టు(స్థానభ్రంశం, 6) << 5) | (NTH_బిట్టు(స్థానభ్రంశం, 2) << 6) | (((స్థానభ్రంశం >> 3) & 7) << 10));
        తిరిగి;
    /* imm variant 2 */
    స్థితి TOK_ASM_c_fsd:
    స్థితి TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(పునాది) | C_ENCODE_RS1(src) | (((స్థానభ్రంశం >> 6) & 3) << 5) | (((స్థానభ్రంశం >> 3) & 7) << 10));
        తిరిగి;
    అప్రమేయ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
స్థిర శూన్య asm_emit_css(పూర్ణాంకం token, uint16_t opcode, స్థిరరాశి నిర్వాహ్యం *rs2, స్థిరరాశి నిర్వాహ్యం *imm)
{
    uint32_t స్థానభ్రంశం;

    ఒకవేళ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ఖాళీ));
    }

    స్థానభ్రంశం = imm->e.v;

    ఒకవేళ (స్థానభ్రంశం > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ఖాళీ));
    }

    ఒకవేళ (స్థానభ్రంశం & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ఖాళీ));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    ఎంపిక (token) {
    /* imm variant 1 */
    స్థితి TOK_ASM_c_fswsp:
    స్థితి TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((స్థానభ్రంశం >> 6) & 3) << 7) | (((స్థానభ్రంశం >> 2) & 0xf) << 9));
        తిరిగి;
    /* imm variant 2 */
    స్థితి TOK_ASM_c_fsdsp:
    స్థితి TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((స్థానభ్రంశం >> 6) & 7) << 7) | (((స్థానభ్రంశం >> 3) & 7) << 10));
        తిరిగి;
    అప్రమేయ:
        expect("known instruction");
    }
}

/*************************************************************/
#అయితే_ముగింపు /* ndef TARGET_DEFS_ONLY */
