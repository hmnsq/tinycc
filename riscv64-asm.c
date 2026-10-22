/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#ifdef TARGET_DEFS_ONLY

#define CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#define NB_ASM_REGS 64

ST_FUNC শূন্য g(পূর্ণাঙ্ক c);
ST_FUNC শূন্য gen_le16(পূর্ণাঙ্ক c);
ST_FUNC শূন্য gen_le32(পূর্ণাঙ্ক c);

/*************************************************************/
#অন্যথা
/*************************************************************/
#define USING_GLOBALS
#অন্তর্ভাৱ "tcc.h"

গণনা {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#define REG_FLOAT_MASK 0x20
#define REG_IS_FLOAT(register_index) ((register_index) & REG_FLOAT_MASK)
#define REG_মান(register_index)    ((register_index) & (REG_FLOAT_MASK-1))
#define C_ENCODE_RS1(register_index) (REG_মান(register_index) << 7)
#define C_ENCODE_RS2(register_index) (REG_মান(register_index) << 2)
#define ENCODE_RD(register_index)  (REG_মান(register_index) << 7)
#define ENCODE_RS1(register_index) (REG_মান(register_index) << 15)
#define ENCODE_RS2(register_index) (REG_মান(register_index) << 20)
#define NTH_BIT(b, n) ((b >> n) & 1)
#define OP_IM12S (1 << OPT_IM12S)
#define OP_IM32 (1 << OPT_IM32)
#define OP_REG (1 << OPT_REG)

প্রকারনির্দেশ সংরচনা Operand {
    uint32_t type;
    সঙ্ঘ {
        uint8_t reg;
        uint16_t regset;
        ৰাশিমালা_মান e;
    };
} Operand;

স্থির ধ্রুৱ Operand zero = { OP_REG, { 0 }};
স্থির ধ্রুৱ Operand ra = { OP_REG, { 1 }};
স্থির ধ্রুৱ Operand zimm = { OP_IM12S };

স্থির শূন্য asm_দ্বিমিক_opcode(TCCState* s1, পূর্ণাঙ্ক token);
ST_FUNC শূন্য asm_clobber(uint8_t *clobber_regs, ধ্রুৱ ৱর্ণ *str);
ST_FUNC শূন্য asm_compute_constraints(ASMOperand *operands, পূর্ণাঙ্ক nb_operands, পূর্ণাঙ্ক nb_outputs, ধ্রুৱ uint8_t *clobber_regs, পূর্ণাঙ্ক *pout_reg);
স্থির শূন্য asm_emit_a(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *rs2, ধ্রুৱ Operand *rd1, পূর্ণাঙ্ক aq, পূর্ণাঙ্ক rl);
স্থির শূন্য asm_emit_b(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *rs2, ধ্রুৱ Operand *imm);
স্থির শূন্য asm_emit_i(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *rs2);
স্থির শূন্য asm_emit_j(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs2);
স্থির শূন্য asm_emit_opcode(uint32_t opcode);
স্থির শূন্য asm_emit_r(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *rs2);
স্থির শূন্য asm_emit_s(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *rs2, ধ্রুৱ Operand *imm);
স্থির শূন্য asm_emit_u(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs2);
স্থির শূন্য asm_emit_f(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *rs2);
স্থির শূন্য asm_emit_fb(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs);
স্থির শূন্য asm_emit_fq(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *rs2, ধ্রুৱ Operand *rs3);
ST_FUNC শূন্য asm_gen_code(ASMOperand *operands, পূর্ণাঙ্ক nb_operands, পূর্ণাঙ্ক nb_outputs, পূর্ণাঙ্ক is_output, uint8_t *clobber_regs, পূর্ণাঙ্ক out_reg);
স্থির শূন্য asm_nullary_opcode(TCCState *s1, পূর্ণাঙ্ক token);
ST_FUNC শূন্য asm_opcode(TCCState *s1, পূর্ণাঙ্ক token);
স্থির পূর্ণাঙ্ক asm_parse_csrvar(পূর্ণাঙ্ক t);
ST_FUNC পূর্ণাঙ্ক asm_parse_regvar(পূর্ণাঙ্ক t);
স্থির শূন্য asm_ternary_opcode(TCCState *s1, পূর্ণাঙ্ক token);
স্থির শূন্য asm_unary_opcode(TCCState *s1, পূর্ণাঙ্ক token);
স্থির শূন্য asm_branch_opcode(TCCState *s1, পূর্ণাঙ্ক token, পূর্ণাঙ্ক argc);
ST_FUNC শূন্য gen_expr32(ৰাশিমালা_মান *pe);
স্থির শূন্য parse_operand(TCCState *s1, Operand *op);
স্থির শূন্য parse_branch_offset_operand(TCCState *s1, Operand *op);
স্থির শূন্য parse_operands(TCCState *s1, Operand *ops, পূর্ণাঙ্ক গুনতি_2);
স্থির শূন্য parse_mem_access_operands(TCCState *s1, Operand* ops);
ST_FUNC শূন্য subst_asm_operand(CString *add_str, SValue *sv, পূর্ণাঙ্ক modifier);
/* C extension */
স্থির শূন্য asm_emit_ca(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs2);
স্থির শূন্য asm_emit_cb(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *imm);
স্থির শূন্য asm_emit_ci(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *imm);
স্থির শূন্য asm_emit_ciw(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *imm);
স্থির শূন্য asm_emit_cj(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *imm);
স্থির শূন্য asm_emit_cl(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *imm);
স্থির শূন্য asm_emit_cr(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs2);
স্থির শূন্য asm_emit_cs(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rs2, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *imm);
স্থির শূন্য asm_emit_css(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rs2, ধ্রুৱ Operand *imm);

/* XXX: make it faster ? */
ST_FUNC শূন্য g(পূর্ণাঙ্ক c)
{
    পূর্ণাঙ্ক ind1;
    যদি (nocode_wanted)
        ঘূৰাই;
    ind1 = ind + 1;
    যদি (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC শূন্য gen_le16 (পূর্ণাঙ্ক i)
{
    g(i);
    g(i>>8);
}

ST_FUNC শূন্য gen_le32 (পূর্ণাঙ্ক i)
{
    পূর্ণাঙ্ক ind1;
    যদি (nocode_wanted)
        ঘূৰাই;
    ind1 = ind + 4;
    যদি (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC শূন্য gen_expr32(ৰাশিমালা_মান *pe)
{
    gen_le32(pe->v);
}

স্থির শূন্য asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

স্থির শূন্য asm_nullary_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    ৱিকল্প (token) {
    // Sync instructions

    পক্ষ TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        ঘূৰাই;

    // System calls

    পক্ষ TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        ঘূৰাই;
    পক্ষ TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        ঘূৰাই;

    // Other

    পক্ষ TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        ঘূৰাই;

    পক্ষ TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        ঘূৰাই;

    /* Pseudoinstructions */
    পক্ষ TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        ঘূৰাই;

    /* C extension */
    পক্ষ TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        ঘূৰাই;

    স্ৱভাৱ:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
স্থির শূন্য parse_operand(TCCState *s1, Operand *op)
{
    ৰাশিমালা_মান e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    যদি ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        ঘূৰাই;
    } অন্যথা যদি (tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    } অন্যথা যদি ((e.v = asm_parse_csrvar(tok)) != -1) {
        next();
    } অন্যথা {
        asm_ৰাশিমালা(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    যদি (!op->e.sym) {
        যদি ((পূর্ণাঙ্ক) op->e.v >= -0x1000 && (পূর্ণাঙ্ক) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } অন্যথা যদি (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        যদি (op->e.sym->type.t & VT_STATIC)
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_PCREL_HI20, 0);
        অন্যথা
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_GOT_HI20, 0);
        put_extern_sym(&label, cur_text_section, ind, 0);
        greloca(cur_text_section, &label, ind+4, R_RISCV_PCREL_LO12_I, 0);

        op->type = OP_IM12S;
        op->e.v = 0;
    } অন্যথা {
        expect("operand");
    }
}

স্থির শূন্য parse_branch_offset_operand(TCCState *s1, Operand *op){
    ৰাশিমালা_মান e = {0};

    asm_ৰাশিমালা(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    যদি (!op->e.sym) {
        যদি ((পূর্ণাঙ্ক) op->e.v >= -0x1000 && (পূর্ণাঙ্ক) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } অন্যথা যদি (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } অন্যথা {
        expect("operand");
    }
}

স্থির শূন্য parse_jump_offset_operand(TCCState *s1, Operand *op){
    ৰাশিমালা_মান e = {0};

    asm_ৰাশিমালা(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    যদি (!op->e.sym) {
        যদি ((পূর্ণাঙ্ক) op->e.v >= -0x1000 && (পূর্ণাঙ্ক) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } অন্যথা যদি (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_text_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } অন্যথা {
        expect("operand");
    }
}

স্থির শূন্য parse_operands(TCCState *s1, Operand* ops, পূর্ণাঙ্ক গুনতি_2){
    পূর্ণাঙ্ক i;
    বাবে (i = 0; i < গুনতি_2; i++) {
        যদি ( i != 0 )
            skip(',');
        parse_operand(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
স্থির শূন্য parse_mem_access_operands(TCCState *s1, Operand* ops){

    Operand op;

    parse_operand(s1, &ops[0]);
    skip(',');
    যদি ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } অন্যথা {
        parse_operand(s1, &ops[2]);
        যদি ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } অন্যথা {
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
স্থির শূন্য asm_jal_opcode(TCCState *s1, পূর্ণাঙ্ক token){
    Operand ops[2];

    যদি (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } অন্যথা যদি (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } অন্যথা {
        // jal reg, offset
        parse_operand(s1, &ops[0]);
        যদি ( tok == ',') next(); অন্যথা expect("','");
    }
    parse_jump_offset_operand(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
স্থির শূন্য asm_jalr_opcode(TCCState *s1, পূর্ণাঙ্ক token){
    Operand ops[3];
    Operand op;

    parse_operand(s1, &ops[0]);
    যদি ( tok == ',')
        next();
    অন্যথা {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        ঘূৰাই;
    }

    যদি ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } অন্যথা {
        parse_operand(s1, &ops[2]);
        যদি ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } অন্যথা {
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


স্থির শূন্য asm_unary_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    Operand op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    ৱিকল্প (token) {
    /* pseudoinstructions */
    পক্ষ TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        ঘূৰাই;
    পক্ষ TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        ঘূৰাই;
    পক্ষ TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        ঘূৰাই;

    পক্ষ TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        ঘূৰাই;
    পক্ষ TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        ঘূৰাই;
    পক্ষ TOK_ASM_tail:
        /* auipc x6, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        ঘূৰাই;

    /* C extension */
    পক্ষ TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        ঘূৰাই;

    স্ৱভাৱ:
        expect("unary instruction");
    }
}

স্থির শূন্য asm_emit_u(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand* rd, ধ্রুৱ Operand* rs2)
{
    যদি (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }
    যদি (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, রিক্ত));
    } অন্যথা যদি (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, রিক্ত));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

স্থির পূর্ণাঙ্ক parse_fence_operand(){
    পূর্ণাঙ্ক t = tok;
    যদি ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    next();
    ঘূৰাই t - (TOK_ASM_w_fence - 1);
}

স্থির শূন্য asm_fence_opcode(TCCState *s1, পূর্ণাঙ্ক token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    পূর্ণাঙ্ক succ = 0xF, pred = 0xF;
    যদি (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_operand();
        যদি ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, রিক্ত));
        }
        skip(',');
        succ = parse_fence_operand();
        যদি ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, রিক্ত));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

স্থির শূন্য asm_দ্বিমিক_opcode(TCCState* s1, পূর্ণাঙ্ক token)
{
    Operand imm = { OP_IM12S };
    Operand ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    ৱিকল্প (token) {
    পক্ষ TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        ঘূৰাই;

    /* C extension */
    পক্ষ TOK_ASM_c_add:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        ঘূৰাই;

    পক্ষ TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        ঘূৰাই;

    পক্ষ TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        ঘূৰাই;

#define CA (1 | (3 << 10) | (4 << 13))
    পক্ষ TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        ঘূৰাই;
#undef CA

    পক্ষ TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        ঘূৰাই;

    পক্ষ TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        ঘূৰাই;

    /* F/D extension */
    পক্ষ TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        ঘূৰাই;

    /* pseudoinstructions */
    /* rd, sym */
    পক্ষ TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_li:
        যদি(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, রিক্ত));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        যদি(lo < 0){
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
        ঘূৰাই;
    পক্ষ TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        ঘূৰাই;
    পক্ষ TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        ঘূৰাই;
    পক্ষ TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        ঘূৰাই;
    পক্ষ TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ঘূৰাই;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    পক্ষ TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_text_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        ঘূৰাই;
    পক্ষ TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        ঘূৰাই;
    পক্ষ TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        ঘূৰাই;
    পক্ষ TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        ঘূৰাই;

    পক্ষ TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ঘূৰাই;

    /* CSR pseudo-instructions */
    পক্ষ TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ঘূৰাই;
    পক্ষ TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ঘূৰাই;
    পক্ষ TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ঘূৰাই;
    স্ৱভাৱ:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
স্থির শূন্য asm_emit_r(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand* rd, ধ্রুৱ Operand* rs1, ধ্রুৱ Operand* rs2)
{
    যদি (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }
    যদি (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, রিক্ত));
    }
    যদি (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, রিক্ত));
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
স্থির শূন্য asm_emit_f(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand* rd, ধ্রুৱ Operand* rs1, ধ্রুৱ Operand* rs2)
{
    যদি (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, রিক্ত));
    }
    যদি (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, রিক্ত));
    }
    যদি (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, রিক্ত));
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
স্থির শূন্য asm_emit_fb(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand* rd, ধ্রুৱ Operand* rs)
{
    যদি (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, রিক্ত));
    }
    যদি (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, রিক্ত));
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
স্থির শূন্য asm_emit_fq(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand* rd, ধ্রুৱ Operand* rs1, ধ্রুৱ Operand* rs2, ধ্রুৱ Operand* rs3)
{
    যদি (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, রিক্ত));
    }
    যদি (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, রিক্ত));
    }
    যদি (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, রিক্ত));
    }
    যদি (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, রিক্ত));
    }
    /* F-type instruction:
	     31...27 rs3
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (REG_মান(rs3->reg) << 27));
}

/* caller: Add funct3 into opcode */
স্থির শূন্য asm_emit_i(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand* rd, ধ্রুৱ Operand* rs1, ধ্রুৱ Operand* rs2)
{
    যদি (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }
    যদি (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, রিক্ত));
    }
    যদি (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, রিক্ত));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

স্থির শূন্য asm_emit_j(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand* rd, ধ্রুৱ Operand* rs2)
{
    uint32_t imm;

    যদি (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }
    যদি (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, রিক্ত));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    যদি ((পূর্ণাঙ্ক)imm > (1 << 20) -1 || (পূর্ণাঙ্ক)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, রিক্ত));
    }

    যদি (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, রিক্ত));
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

স্থির শূন্য asm_mem_access_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{

    Operand ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    যদি (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    ৱিকল্প (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    পক্ষ TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    পক্ষ TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ঘূৰাই;
    }
}

স্থির শূন্য asm_branch_opcode(TCCState *s1, পূর্ণাঙ্ক token, পূর্ণাঙ্ক argc)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_offset_operand(s1, &ops[argc-1]);

    ৱিকল্প(token){
    /* branch (RS1, RS2, IMM); B-format */
    পক্ষ TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    /* related pseudoinstructions */
    পক্ষ TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        ঘূৰাই;
    /* shorter pseudoinstructions */
    পক্ষ TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        ঘূৰাই;
    পক্ষ TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        ঘূৰাই;
    }
}

স্থির শূন্য asm_ternary_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], 3);

    ৱিকল্প (token) {
    পক্ষ TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;
    পক্ষ TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ঘূৰাই;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    পক্ষ TOK_ASM_add:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    পক্ষ TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    পক্ষ TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;
    পক্ষ TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ঘূৰাই;

    /* M extension */
    পক্ষ TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ঘূৰাই;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    পক্ষ TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        ঘূৰাই;
    পক্ষ TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        ঘূৰাই;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    পক্ষ TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        ঘূৰাই;

    /* F/D extension */
    পক্ষ TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;
    পক্ষ TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ঘূৰাই;

    /* F/D comparison: produce integer result, encode manually */
    পক্ষ TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ঘূৰাই;
    পক্ষ TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ঘূৰাই;

    স্ৱভাৱ:
        expect("ternary instruction");
    }
}

স্থির শূন্য asm_quaternary_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[4];
    parse_operands(s1, &ops[0], 4);

    ৱিকল্প (token) {
    পক্ষ TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ঘূৰাই;
    পক্ষ TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ঘূৰাই;

    স্ৱভাৱ:
        expect("quaternary instruction");
    }
}

স্থির শূন্য asm_atomic_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[3];

    parse_operand(s1, &ops[0]);
    skip(',');

    যদি ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } অন্যথা {
        parse_operand(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_operand(s1, &ops[2]);
    skip(')');

    ৱিকল্প(token){
        পক্ষ TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ভঙ্গ;
        পক্ষ TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ভঙ্গ;
        পক্ষ TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ভঙ্গ;
        পক্ষ TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ভঙ্গ;

        পক্ষ TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ভঙ্গ;
        পক্ষ TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ভঙ্গ;
        পক্ষ TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ভঙ্গ;
        পক্ষ TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ভঙ্গ;

        পক্ষ TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ভঙ্গ;
        পক্ষ TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ভঙ্গ;
        পক্ষ TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ভঙ্গ;
        পক্ষ TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ভঙ্গ;

        পক্ষ TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ভঙ্গ;
        পক্ষ TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ভঙ্গ;
        পক্ষ TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ভঙ্গ;
        পক্ষ TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ভঙ্গ;

        /* AMO instructions (base, aq=0 rl=0) */
        পক্ষ TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ভঙ্গ;

        /* AMO aq/rl variants */
        পক্ষ TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;

        পক্ষ TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ভঙ্গ;
        পক্ষ TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ভঙ্গ;
        পক্ষ TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ভঙ্গ;
    }
}

/* caller: Add funct3 and func5 to opcode */
স্থির শূন্য asm_emit_a(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rd1, ধ্রুৱ Operand *rs2, ধ্রুৱ Operand *rs1, পূর্ণাঙ্ক aq, পূর্ণাঙ্ক rl)
{
    যদি (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, রিক্ত));
    যদি (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, রিক্ত));
    যদি (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, রিক্ত));
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
স্থির শূন্য asm_emit_s(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand* rs1, ধ্রুৱ Operand* rs2, ধ্রুৱ Operand* imm)
{
    যদি (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, রিক্ত));
    }
    যদি (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, রিক্ত));
    }
    যদি (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, রিক্ত));
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

স্থির শূন্য asm_emit_b(পূর্ণাঙ্ক token, uint32_t opcode, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *rs2, ধ্রুৱ Operand *imm)
{
    uint32_t offset;

    যদি (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, রিক্ত));
    }
    যদি (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }
    যদি (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        পূর্ণাঙ্ক b_ofs = ind;
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
        ঘূৰাই;
    }
    যদি (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, রিক্ত));
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
স্থির পূর্ণাঙ্ক asm_fcvt_rm(TCCState *s1)
{
    পূর্ণাঙ্ক rm = 7; /* dynamic */
    যদি (tok == ',') {
        next();
        ৱিকল্প (tok) {
            পক্ষ TOK_ASM_rne: rm = 0; next(); ভঙ্গ;
            পক্ষ TOK_ASM_rtz: rm = 1; next(); ভঙ্গ;
            পক্ষ TOK_ASM_rdn: rm = 2; next(); ভঙ্গ;
            পক্ষ TOK_ASM_rup: rm = 3; next(); ভঙ্গ;
            পক্ষ TOK_ASM_rmm: rm = 4; next(); ভঙ্গ;
            স্ৱভাৱ: expect("rounding mode"); ভঙ্গ;
        }
    }
    ঘূৰাই rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
স্থির শূন্য asm_fcvt_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[2];
    পূর্ণাঙ্ক rm;
    uint32_t enc = 0;

    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);

    ৱিকল্প (token) {
        পক্ষ TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); ভঙ্গ;
        পক্ষ TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); ভঙ্গ;
        পক্ষ TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); ভঙ্গ;
        পক্ষ TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); ভঙ্গ;
        স্ৱভাৱ: expect("fcvt/fclass instruction"); ঘূৰাই;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC শূন্য asm_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    ৱিকল্প (token) {
    পক্ষ TOK_ASM_ebreak:
    পক্ষ TOK_ASM_ecall:
    পক্ষ TOK_ASM_fence_i:
    পক্ষ TOK_ASM_hrts:
    পক্ষ TOK_ASM_mrth:
    পক্ষ TOK_ASM_mrts:
    পক্ষ TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_rdcycle:
    পক্ষ TOK_ASM_rdcycleh:
    পক্ষ TOK_ASM_rdtime:
    পক্ষ TOK_ASM_rdtimeh:
    পক্ষ TOK_ASM_rdinstret:
    পক্ষ TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_lui:
    পক্ষ TOK_ASM_auipc:
    পক্ষ TOK_ASM_fsqrt_s:
    পক্ষ TOK_ASM_fsqrt_d:
        asm_দ্বিমিক_opcode(s1, token);
        ঘূৰাই;

    /* fcvt/fclass — separate handler for optional rounding operand */
    পক্ষ TOK_ASM_fcvt_w_s:
    পক্ষ TOK_ASM_fcvt_wu_s:
    পক্ষ TOK_ASM_fcvt_l_s:
    পক্ষ TOK_ASM_fcvt_lu_s:
    পক্ষ TOK_ASM_fcvt_s_w:
    পক্ষ TOK_ASM_fcvt_s_wu:
    পক্ষ TOK_ASM_fcvt_s_l:
    পক্ষ TOK_ASM_fcvt_s_lu:
    পক্ষ TOK_ASM_fcvt_w_d:
    পক্ষ TOK_ASM_fcvt_wu_d:
    পক্ষ TOK_ASM_fcvt_l_d:
    পক্ষ TOK_ASM_fcvt_lu_d:
    পক্ষ TOK_ASM_fcvt_d_w:
    পক্ষ TOK_ASM_fcvt_d_wu:
    পক্ষ TOK_ASM_fcvt_d_l:
    পক্ষ TOK_ASM_fcvt_d_lu:
    পক্ষ TOK_ASM_fcvt_s_d:
    পক্ষ TOK_ASM_fcvt_d_s:
    পক্ষ TOK_ASM_fclass_s:
    পক্ষ TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_lb:
    পক্ষ TOK_ASM_lh:
    পক্ষ TOK_ASM_lw:
    পক্ষ TOK_ASM_ld:
    পক্ষ TOK_ASM_fld:
    পক্ষ TOK_ASM_lbu:
    পক্ষ TOK_ASM_lhu:
    পক্ষ TOK_ASM_lwu:
    পক্ষ TOK_ASM_sb:
    পক্ষ TOK_ASM_sh:
    পক্ষ TOK_ASM_sw:
    পক্ষ TOK_ASM_sd:
    পক্ষ TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        ভঙ্গ;

    পক্ষ TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        ভঙ্গ;
    পক্ষ TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        ঘূৰাই;
    পক্ষ TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        ভঙ্গ;

    পক্ষ TOK_ASM_add:
    পক্ষ TOK_ASM_addi:
    পক্ষ TOK_ASM_addiw:
    পক্ষ TOK_ASM_addw:
    পক্ষ TOK_ASM_and:
    পক্ষ TOK_ASM_andi:
    পক্ষ TOK_ASM_or:
    পক্ষ TOK_ASM_ori:
    পক্ষ TOK_ASM_sll:
    পক্ষ TOK_ASM_slli:
    পক্ষ TOK_ASM_slliw:
    পক্ষ TOK_ASM_sllw:
    পক্ষ TOK_ASM_slt:
    পক্ষ TOK_ASM_slti:
    পক্ষ TOK_ASM_sltiu:
    পক্ষ TOK_ASM_sltu:
    পক্ষ TOK_ASM_sra:
    পক্ষ TOK_ASM_srai:
    পক্ষ TOK_ASM_sraiw:
    পক্ষ TOK_ASM_sraw:
    পক্ষ TOK_ASM_srl:
    পক্ষ TOK_ASM_srli:
    পক্ষ TOK_ASM_srliw:
    পক্ষ TOK_ASM_srlw:
    পক্ষ TOK_ASM_sub:
    পক্ষ TOK_ASM_subw:
    পক্ষ TOK_ASM_xor:
    পক্ষ TOK_ASM_xori:
    /* M extension */
    পক্ষ TOK_ASM_div:
    পক্ষ TOK_ASM_divu:
    পক্ষ TOK_ASM_divuw:
    পক্ষ TOK_ASM_divw:
    পক্ষ TOK_ASM_mul:
    পক্ষ TOK_ASM_mulh:
    পক্ষ TOK_ASM_mulhsu:
    পক্ষ TOK_ASM_mulhu:
    পক্ষ TOK_ASM_mulw:
    পক্ষ TOK_ASM_rem:
    পক্ষ TOK_ASM_remu:
    পক্ষ TOK_ASM_remuw:
    পক্ষ TOK_ASM_remw:
    /* Zicsr extension */
    পক্ষ TOK_ASM_csrrc:
    পক্ষ TOK_ASM_csrrci:
    পক্ষ TOK_ASM_csrrs:
    পক্ষ TOK_ASM_csrrsi:
    পক্ষ TOK_ASM_csrrw:
    পক্ষ TOK_ASM_csrrwi:
    /* F/D extension */
    পক্ষ TOK_ASM_fadd_s:
    পক্ষ TOK_ASM_fadd_d:
    পক্ষ TOK_ASM_fsub_s:
    পক্ষ TOK_ASM_fsub_d:
    পক্ষ TOK_ASM_fmul_s:
    পক্ষ TOK_ASM_fmul_d:
    পক্ষ TOK_ASM_fdiv_s:
    পক্ষ TOK_ASM_fdiv_d:
    পক্ষ TOK_ASM_fsgnj_d:
    পক্ষ TOK_ASM_fsgnj_s:
    পক্ষ TOK_ASM_fmax_s:
    পক্ষ TOK_ASM_fmax_d:
    পক্ষ TOK_ASM_fmin_s:
    পক্ষ TOK_ASM_fmin_d:
    পক্ষ TOK_ASM_feq_s:
    পক্ষ TOK_ASM_feq_d:
    পক্ষ TOK_ASM_flt_s:
    পক্ষ TOK_ASM_flt_d:
    পক্ষ TOK_ASM_fle_s:
    পক্ষ TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        ঘূৰাই;
    পক্ষ TOK_ASM_fmadd_d:
    পক্ষ TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        ঘূৰাই;

    /* Branches */
    পক্ষ TOK_ASM_beq:
    পক্ষ TOK_ASM_bge:
    পক্ষ TOK_ASM_bgeu:
    পক্ষ TOK_ASM_blt:
    পক্ষ TOK_ASM_bltu:
    পক্ষ TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        ভঙ্গ;

    /* C extension */
    পক্ষ TOK_ASM_c_ebreak:
    পক্ষ TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_c_j:
    পক্ষ TOK_ASM_c_jal:
    পক্ষ TOK_ASM_c_jalr:
    পক্ষ TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_c_add:
    পক্ষ TOK_ASM_c_addi16sp:
    পক্ষ TOK_ASM_c_addi4spn:
    পক্ষ TOK_ASM_c_addi:
    পক্ষ TOK_ASM_c_addiw:
    পক্ষ TOK_ASM_c_addw:
    পক্ষ TOK_ASM_c_and:
    পক্ষ TOK_ASM_c_andi:
    পক্ষ TOK_ASM_c_beqz:
    পক্ষ TOK_ASM_c_bnez:
    পক্ষ TOK_ASM_c_fldsp:
    পক্ষ TOK_ASM_c_flwsp:
    পক্ষ TOK_ASM_c_fsdsp:
    পক্ষ TOK_ASM_c_fswsp:
    পক্ষ TOK_ASM_c_ldsp:
    পক্ষ TOK_ASM_c_li:
    পক্ষ TOK_ASM_c_lui:
    পক্ষ TOK_ASM_c_lwsp:
    পক্ষ TOK_ASM_c_mv:
    পক্ষ TOK_ASM_c_or:
    পক্ষ TOK_ASM_c_sdsp:
    পক্ষ TOK_ASM_c_slli:
    পক্ষ TOK_ASM_c_srai:
    পক্ষ TOK_ASM_c_srli:
    পক্ষ TOK_ASM_c_sub:
    পক্ষ TOK_ASM_c_subw:
    পক্ষ TOK_ASM_c_swsp:
    পক্ষ TOK_ASM_c_xor:
        asm_দ্বিমিক_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_c_fld:
    পক্ষ TOK_ASM_c_flw:
    পক্ষ TOK_ASM_c_fsd:
    পক্ষ TOK_ASM_c_fsw:
    পক্ষ TOK_ASM_c_ld:
    পক্ষ TOK_ASM_c_lw:
    পক্ষ TOK_ASM_c_sd:
    পক্ষ TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        ঘূৰাই;

    /* pseudoinstructions */
    পক্ষ TOK_ASM_nop:
    পক্ষ TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_jr:
    পক্ষ TOK_ASM_call:
    পক্ষ TOK_ASM_tail:
    পক্ষ TOK_ASM_frflags:
    পক্ষ TOK_ASM_frrm:
    পক্ষ TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_la:
    পক্ষ TOK_ASM_lla:
    পক্ষ TOK_ASM_li:
    পক্ষ TOK_ASM_jump:
    পক্ষ TOK_ASM_seqz:
    পক্ষ TOK_ASM_snez:
    পক্ষ TOK_ASM_sltz:
    পক্ষ TOK_ASM_sgtz:
    পক্ষ TOK_ASM_mv:
    পক্ষ TOK_ASM_not:
    পক্ষ TOK_ASM_neg:
    পক্ষ TOK_ASM_negw:
    পক্ষ TOK_ASM_sext_w:
    পক্ষ TOK_ASM_fabs_s:
    পক্ষ TOK_ASM_fabs_d:
    পক্ষ TOK_ASM_fmv_s:
    পক্ষ TOK_ASM_fmv_d:
    পক্ষ TOK_ASM_fneg_s:
    পক্ষ TOK_ASM_fneg_d:
    পক্ষ TOK_ASM_csrc:
    পক্ষ TOK_ASM_csrs:
    পক্ষ TOK_ASM_csrr:
    পক্ষ TOK_ASM_csrw:
    পক্ষ TOK_ASM_csrwi:
    পক্ষ TOK_ASM_csrsi:
    পক্ষ TOK_ASM_csrci:
    পক্ষ TOK_ASM_fsrm:
    পক্ষ TOK_ASM_fscsr:
        asm_দ্বিমিক_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_bnez:
    পক্ষ TOK_ASM_beqz:
    পক্ষ TOK_ASM_blez:
    পক্ষ TOK_ASM_bgez:
    পক্ষ TOK_ASM_bltz:
    পক্ষ TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        ঘূৰাই;

    পক্ষ TOK_ASM_bgt:
    পক্ষ TOK_ASM_bgtu:
    পক্ষ TOK_ASM_ble:
    পক্ষ TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        ঘূৰাই;

    /* Atomic operations */
    পক্ষ TOK_ASM_lr_w:
    পক্ষ TOK_ASM_lr_w_aq:
    পক্ষ TOK_ASM_lr_w_rl:
    পক্ষ TOK_ASM_lr_w_aqrl:
    পক্ষ TOK_ASM_lr_d:
    পক্ষ TOK_ASM_lr_d_aq:
    পক্ষ TOK_ASM_lr_d_rl:
    পক্ষ TOK_ASM_lr_d_aqrl:
    পক্ষ TOK_ASM_sc_w:
    পক্ষ TOK_ASM_sc_w_aq:
    পক্ষ TOK_ASM_sc_w_rl:
    পক্ষ TOK_ASM_sc_w_aqrl:
    পক্ষ TOK_ASM_sc_d:
    পক্ষ TOK_ASM_sc_d_aq:
    পক্ষ TOK_ASM_sc_d_rl:
    পক্ষ TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    পক্ষ TOK_ASM_amoadd_w:
    পক্ষ TOK_ASM_amoadd_d:
    পক্ষ TOK_ASM_amoswap_w:
    পক্ষ TOK_ASM_amoswap_d:
    পক্ষ TOK_ASM_amoand_w:
    পক্ষ TOK_ASM_amoand_d:
    পক্ষ TOK_ASM_amoor_w:
    পক্ষ TOK_ASM_amoor_d:
    পক্ষ TOK_ASM_amoxor_w:
    পক্ষ TOK_ASM_amoxor_d:
    পক্ষ TOK_ASM_amomax_w:
    পক্ষ TOK_ASM_amomax_d:
    পক্ষ TOK_ASM_amomaxu_w:
    পক্ষ TOK_ASM_amomaxu_d:
    পক্ষ TOK_ASM_amomin_w:
    পক্ষ TOK_ASM_amomin_d:
    পক্ষ TOK_ASM_amominu_w:
    পক্ষ TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    পক্ষ TOK_ASM_amoadd_w_aq:
    পক্ষ TOK_ASM_amoadd_w_rl:
    পক্ষ TOK_ASM_amoadd_w_aqrl:
    পক্ষ TOK_ASM_amoadd_d_aq:
    পক্ষ TOK_ASM_amoadd_d_rl:
    পক্ষ TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    পক্ষ TOK_ASM_amoswap_w_aq:
    পক্ষ TOK_ASM_amoswap_w_rl:
    পক্ষ TOK_ASM_amoswap_w_aqrl:
    পক্ষ TOK_ASM_amoswap_d_aq:
    পক্ষ TOK_ASM_amoswap_d_rl:
    পক্ষ TOK_ASM_amoswap_d_aqrl:
    পক্ষ TOK_ASM_amoand_w_aq:
    পক্ষ TOK_ASM_amoand_w_rl:
    পক্ষ TOK_ASM_amoand_w_aqrl:
    পক্ষ TOK_ASM_amoand_d_aq:
    পক্ষ TOK_ASM_amoand_d_rl:
    পক্ষ TOK_ASM_amoand_d_aqrl:
    পক্ষ TOK_ASM_amoor_w_aq:
    পক্ষ TOK_ASM_amoor_w_rl:
    পক্ষ TOK_ASM_amoor_w_aqrl:
    পক্ষ TOK_ASM_amoor_d_aq:
    পক্ষ TOK_ASM_amoor_d_rl:
    পক্ষ TOK_ASM_amoor_d_aqrl:
    পক্ষ TOK_ASM_amoxor_w_aq:
    পক্ষ TOK_ASM_amoxor_w_rl:
    পক্ষ TOK_ASM_amoxor_w_aqrl:
    পক্ষ TOK_ASM_amoxor_d_aq:
    পক্ষ TOK_ASM_amoxor_d_rl:
    পক্ষ TOK_ASM_amoxor_d_aqrl:
    পক্ষ TOK_ASM_amomax_w_aq:
    পক্ষ TOK_ASM_amomax_w_rl:
    পক্ষ TOK_ASM_amomax_w_aqrl:
    পক্ষ TOK_ASM_amomax_d_aq:
    পক্ষ TOK_ASM_amomax_d_rl:
    পক্ষ TOK_ASM_amomax_d_aqrl:
    পক্ষ TOK_ASM_amomaxu_w_aq:
    পক্ষ TOK_ASM_amomaxu_w_rl:
    পক্ষ TOK_ASM_amomaxu_w_aqrl:
    পক্ষ TOK_ASM_amomaxu_d_aq:
    পক্ষ TOK_ASM_amomaxu_d_rl:
    পক্ষ TOK_ASM_amomaxu_d_aqrl:
    পক্ষ TOK_ASM_amomin_w_aq:
    পক্ষ TOK_ASM_amomin_w_rl:
    পক্ষ TOK_ASM_amomin_w_aqrl:
    পক্ষ TOK_ASM_amomin_d_aq:
    পক্ষ TOK_ASM_amomin_d_rl:
    পক্ষ TOK_ASM_amomin_d_aqrl:
    পক্ষ TOK_ASM_amominu_w_aq:
    পক্ষ TOK_ASM_amominu_w_rl:
    পক্ষ TOK_ASM_amominu_w_aqrl:
    পক্ষ TOK_ASM_amominu_d_aq:
    পক্ষ TOK_ASM_amominu_d_rl:
    পক্ষ TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        ভঙ্গ;

    স্ৱভাৱ:
        expect("known instruction");
    }
}

স্থির পূর্ণাঙ্ক asm_parse_csrvar(পূর্ণাঙ্ক t)
{
    ৱিকল্প (t) {
    পক্ষ TOK_ASM_cycle:
        ঘূৰাই 0xc00;
    পক্ষ TOK_ASM_fcsr:
        ঘূৰাই 3;
    পক্ষ TOK_ASM_fflags:
        ঘূৰাই 1;
    পক্ষ TOK_ASM_frm:
        ঘূৰাই 2;
    পক্ষ TOK_ASM_instret:
        ঘূৰাই 0xc02;
    পক্ষ TOK_ASM_time:
        ঘূৰাই 0xc01;
    পক্ষ TOK_ASM_cycleh:
        ঘূৰাই 0xc80;
    পক্ষ TOK_ASM_instreth:
        ঘূৰাই 0xc82;
    পক্ষ TOK_ASM_timeh:
        ঘূৰাই 0xc81;
    স্ৱভাৱ:
        ঘূৰাই -1;
    }
}

ST_FUNC শূন্য subst_asm_operand(CString *add_str, SValue *sv, পূর্ণাঙ্ক modifier)
{
    পূর্ণাঙ্ক r, reg, val;

    r = sv->r;
    যদি ((r & VT_VALMASK) == VT_CONST) {
        যদি (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        যদি (r & VT_SYM) {
            ধ্রুৱ ৱর্ণ *name = get_tok_str(sv->sym->v, রিক্ত);
            যদি (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            যদি (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            যদি ((uint32_t) sv->c.i == 0)
                গচ্ছ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        যদি (modifier == 'n')
            val = -val;
        যদি (modifier == 'z' && val == 0) {
            cstr_cat(add_str, "zero", -1);
        } অন্যথা {
            cstr_printf(add_str, "%d", val);
        }
      no_offset:;
    } অন্যথা যদি ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d", (পূর্ণাঙ্ক) sv->c.i);
    } অন্যথা যদি (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        যদি (reg >= VT_CONST)
            tcc_internal_error("");
        যদি ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_মান(reg);
        } অন্যথা {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, রিক্ত), -1);
    } অন্যথা {
        /* register case */
        reg = r & VT_VALMASK;
        যদি (reg >= VT_CONST)
            tcc_internal_error("");
        যদি ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_মান(reg);
        } অন্যথা {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, রিক্ত), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
স্থির পূর্ণাঙ্ক tcc_ireg(পূর্ণাঙ্ক r){
    ঘূৰাই REG_মান(r) - 10;
}
স্থির পূর্ণাঙ্ক tcc_freg(পূর্ণাঙ্ক r){
    ঘূৰাই REG_মান(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC শূন্য asm_gen_code(ASMOperand *operands, পূর্ণাঙ্ক nb_operands,
                         পূর্ণাঙ্ক nb_outputs, পূর্ণাঙ্ক is_output,
                         uint8_t *clobber_regs,
                         পূর্ণাঙ্ক out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    পূর্ণাঙ্ক i, reg;

    স্থির ধ্রুৱ uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, পরিমাণ(regs_allocated));
    বাবে(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        যদি (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    যদি(!is_output) {
        /* generate reg save code */
        বাবে(i = 0; i < পরিমাণ(reg_saved)/পরিমাণ(reg_saved[0]); i++) {
            reg = reg_saved[i];
            যদি (regs_allocated[reg]) {
                /*ঠেলো*/
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (unsigned)-8 << 20);
                যদি (REG_IS_FLOAT(reg)){
                    /* fsd reg, offset(sp) */
                    gen_le32( 0x27 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                } অন্যথা {
                    /* sd reg, offset(sp) */
                    gen_le32((0x8 << 2) | 3 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                }
            }
        }

        /* generate load code */
        বাবে(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            যদি (op->reg >= 0) {
                যদি ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(tcc_ireg(op->reg), &sv);
                } অন্যথা যদি (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    যদি ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        load(tcc_freg(op->reg), op->vt);
                    } অন্যথা {
                        load(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register;
                       the load/store above already handles it correctly */
                }
            }
        }
    } অন্যথা {
        /* generate save code */
        বাবে(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            যদি (op->reg >= 0) {
                যদি ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    যদি (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(tcc_ireg(out_reg), &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(tcc_ireg(op->reg), &sv);
                    }
                } অন্যথা {
                    যদি ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        store(tcc_freg(op->reg), op->vt);
                    } অন্যথা {
                        store(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register */
                }
            }
        }
        /* generate reg restore code for floating point registers */
        বাবে(i = পরিমাণ(reg_saved)/পরিমাণ(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            যদি (regs_allocated[reg]) {
                /*বেৰ কৰো*/
                যদি (REG_IS_FLOAT(reg)){
                    /* fld reg, offset(sp) */
                    gen_le32(7 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                } অন্যথা {
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
স্থির অন্তঃস্থ পূর্ণাঙ্ক constraint_priority(ধ্রুৱ ৱর্ণ *str)
{
    // TODO: How is this chosen??
    পূর্ণাঙ্ক priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    বাবে(;;) {
        c = *str;
        যদি (c == '\0')
            ভঙ্গ;
        str++;
        ৱিকল্প(c) {
        পক্ষ 'A': // address that is held in a general-purpose register.
        পক্ষ 'S': // constraint that matches an absolute symbolic address.
        পক্ষ 'f': // register [float]
        পক্ষ 'r': // register [general]
        পক্ষ 'p': // valid memory address for load,store [general]
            pr = 3;
            ভঙ্গ;
        পক্ষ 'I': // 12 bit signed immedate
        পক্ষ 'i': // immediate integer operand, including symbolic constants [general]
        পক্ষ 'm': // memory operand [general]
        পক্ষ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ভঙ্গ;
        পক্ষ 'v':
            tcc_error("unimp: constraint '%c'", c);
        স্ৱভাৱ:
            tcc_error("unknown constraint '%d'", c);
        }
        যদি (pr > priority)
            priority = pr;
    }
    ঘূৰাই priority;
}

স্থির ধ্রুৱ ৱর্ণ *skip_constraint_modifiers(ধ্রুৱ ৱর্ণ *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    যেতিয়ালৈ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ঘূৰাই p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC শূন্য asm_compute_constraints(ASMOperand *operands,
                                    পূর্ণাঙ্ক nb_operands, পূর্ণাঙ্ক nb_outputs,
                                    ধ্রুৱ uint8_t *clobber_regs,
                                    পূর্ণাঙ্ক *pout_reg)
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
    পূর্ণাঙ্ক sorted_op[MAX_ASM_OPERANDS];
    পূর্ণাঙ্ক i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ধ্রুৱ ৱর্ণ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    বাবে (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->প্ৰবেশ_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    বাবে (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        যদি (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, রিক্ত);
            যদি ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            যদি (operands[k].প্ৰবেশ_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].প্ৰবেশ_index = i;
            op->priority = 5;
        } অন্যথা যদি ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } অন্যথা {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    বাবে (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    বাবে (i = 0; i < nb_operands - 1; i++) {
        বাবে (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            যদি (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    বাবে (i = 0; i < NB_ASM_REGS; i++) {
        যদি (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        অন্যথা
            regs_allocated[i] = 0;
    }

    /* allocate registers and generate corresponding asm moves */
    বাবে (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        যদি (op->ref_index >= 0)
            অনুৱর্ত;
        /* select if register is used for output, input or both */
        যদি (op->প্ৰবেশ_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } অন্যথা যদি (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } অন্যথা {
            reg_mask = REG_IN_MASK;
        }
        যদি (op->reg >= 0) {
            যদি (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        ৱিকল্প (c) {
        পক্ষ '=': // Operand is written-to
            গচ্ছ try_next;
        পক্ষ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        পক্ষ '&': // Operand is clobbered before the instruction is done using the input operands
            যদি (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            গচ্ছ try_next;
        পক্ষ 'r': // general-purpose register
        পক্ষ 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            যদি ((reg = op->reg) >= 0)
                গচ্ছ reg_found;
            অন্যথা বাবে (reg = 10; reg <= 18; reg++) {
                যদি (!is_reg_allocated(reg))
                    গচ্ছ reg_found;
            }
            গচ্ছ try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            ভঙ্গ;
        পক্ষ 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            যদি ((reg = op->reg) >= 0)
                গচ্ছ reg_found;
            অন্যথা বাবে (reg = 42; reg <= 50; reg++) {
                যদি (!is_reg_allocated(reg))
                    গচ্ছ reg_found;
            }
            গচ্ছ try_next;
        পক্ষ 'I': // I-Type 12 bit signed immediate
        পক্ষ 'i': // immediate integer operand, including symbolic constants
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'm': // memory operand
        পক্ষ 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            যদি (j < nb_outputs || c == 'm') {
                যদি ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    বাবে (reg = 10; reg <= 18; reg++) {
                        যদি (!(regs_allocated[reg] & REG_IN_MASK))
                            গচ্ছ reg_found1;
                    }
                    গচ্ছ try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ভঙ্গ;
        }
        /* if a reference is present for that operand, we assign it too */
        যদি (op->প্ৰবেশ_index >= 0) {
            operands[op->প্ৰবেশ_index].reg = op->reg;
            operands[op->প্ৰবেশ_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    বাবে (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        যদি (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            যদি (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                বাবে (reg = 42; reg <= 50; reg++) {
                    যদি (!(regs_allocated[reg] & REG_OUT_MASK))
                        গচ্ছ reg_found2;
                }
            } অন্যথা {
                /* From a0 to a7 */
                বাবে (reg = 10; reg <= 18; reg++) {
                    যদি (!(regs_allocated[reg] & REG_OUT_MASK))
                        গচ্ছ reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ভঙ্গ;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    বাবে (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, রিক্ত) : "",
               op->constraint, op->vt->r, op->reg);
    }
    যদি (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC শূন্য asm_clobber(uint8_t *clobber_regs, ধ্রুৱ ৱর্ণ *str)
{
    পূর্ণাঙ্ক reg;
    TokenSym *ts;

    যদি (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ঘূৰাই;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    যদি (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC পূর্ণাঙ্ক asm_parse_regvar (পূর্ণাঙ্ক t)
{
    /* PC register not implemented */
    যদি (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        ঘূৰাই -1;

    যদি (t < TOK_ASM_f0)
        ঘূৰাই t - TOK_ASM_x0;

    যদি (t < TOK_ASM_zero)
        ঘূৰাই t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    যদি (t < TOK_ASM_ft0)
        ঘূৰাই t - TOK_ASM_zero;

    ঘূৰাই t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
স্থির শূন্য asm_emit_ca(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs2)
{
    uint8_t dst, src;

    যদি (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }

    যদি (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, রিক্ত));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    যদি (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, রিক্ত));
    }

    যদি (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, রিক্ত));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

স্থির শূন্য asm_emit_cb(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *imm)
{
    uint32_t offset;
    uint8_t src;

    যদি (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, রিক্ত));
    }

    যদি (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, রিক্ত));
    }

    offset = imm->e.v;

    যদি (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, রিক্ত));
    }

    src = rs1->reg - 8;

    যদি (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, রিক্ত));
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

    ৱিকল্প (token) {
    পক্ষ TOK_ASM_c_beqz:
    পক্ষ TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_BIT(offset, 5) | (((offset >> 1) & 3) << 1) | (((offset >> 6) & 3) << 3)) << 2) | ((((offset >> 3) & 3) | NTH_BIT(offset, 8)) << 10));
        ঘূৰাই;
    স্ৱভাৱ:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((offset & 0x1f) << 2) | (NTH_BIT(offset, 5) << 12));
        ঘূৰাই;
    }
}

স্থির শূন্য asm_emit_ci(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *imm)
{
    uint32_t immediate;

    যদি (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }

    যদি (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, রিক্ত));
    }

    immediate = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    ৱিকল্প (token) {
    পক্ষ TOK_ASM_c_addi:
    পক্ষ TOK_ASM_c_addiw:
    পক্ষ TOK_ASM_c_li:
    পক্ষ TOK_ASM_c_slli:
        gen_le16(opcode | ((immediate & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ঘূৰাই;
    পক্ষ TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_BIT(immediate, 5) << 2 | (((immediate >> 7) & 3) << 3) | NTH_BIT(immediate, 6) << 5 | NTH_BIT(immediate, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 9) << 12));
        ঘূৰাই;
    পক্ষ TOK_ASM_c_lui:
        gen_le16(opcode | (((immediate >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 17) << 12));
        ঘূৰাই;
    পক্ষ TOK_ASM_c_fldsp:
    পক্ষ TOK_ASM_c_ldsp:
        gen_le16(opcode | (((immediate >> 6) & 7) << 2) | (((immediate >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ঘূৰাই;
    পক্ষ TOK_ASM_c_flwsp:
    পক্ষ TOK_ASM_c_lwsp:
        gen_le16(opcode | (((immediate >> 6) & 3) << 2) | (((immediate >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        ঘূৰাই;
    পক্ষ TOK_ASM_c_nop:
        gen_le16(opcode);
        ঘূৰাই;
    স্ৱভাৱ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
স্থির শূন্য asm_emit_ciw(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    যদি (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }

    যদি (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, রিক্ত));
    }

    dst = rd->reg - 8;

    যদি (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, রিক্ত));
    }

    nzuimm = imm->e.v;

    যদি (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, রিক্ত));
    }

    যদি (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, রিক্ত));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_BIT(nzuimm, 3) | (NTH_BIT(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
স্থির শূন্য asm_emit_cj(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *imm)
{
    uint32_t offset;

    /* +-2 KiB range */
    যদি (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, রিক্ত));
    }

    offset = imm->e.v;

    যদি (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, রিক্ত));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_BIT(offset, 5) << 2) | (((offset >> 1) & 7) << 3) | (NTH_BIT(offset, 7) << 6) | (NTH_BIT(offset, 6) << 7) | (NTH_BIT(offset, 10) << 8) | (((offset >> 8) & 3) << 9) | (NTH_BIT(offset, 4) << 11) | (NTH_BIT(offset, 11) << 12));
}

/* caller: Add funct3 into opcode */
স্থির শূন্য asm_emit_cl(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *imm)
{
    uint32_t offset;
    uint8_t dst, src;

    যদি (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }

    যদি (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, রিক্ত));
    }

    যদি (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, রিক্ত));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    যদি (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, রিক্ত));
    }

    যদি (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, রিক্ত));
    }

    offset = imm->e.v;

    যদি (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, রিক্ত));
    }

    যদি (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, রিক্ত));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    ৱিকল্প (token) {
    /* imm variant 1 */
    পক্ষ TOK_ASM_c_flw:
    পক্ষ TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        ঘূৰাই;
    /* imm variant 2 */
    পক্ষ TOK_ASM_c_fld:
    পক্ষ TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        ঘূৰাই;
    স্ৱভাৱ:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
স্থির শূন্য asm_emit_cr(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rd, ধ্রুৱ Operand *rs2)
{
    যদি (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }

    যদি (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, রিক্ত));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
স্থির শূন্য asm_emit_cs(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rs2, ধ্রুৱ Operand *rs1, ধ্রুৱ Operand *imm)
{
    uint32_t offset;
    uint8_t base, src;

    যদি (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }

    যদি (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, রিক্ত));
    }

    যদি (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, রিক্ত));
    }

    base = rs1->reg - 8;
    src = rs2->reg - 8;

    যদি (base > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, রিক্ত));
    }

    যদি (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, রিক্ত));
    }

    offset = imm->e.v;

    যদি (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, রিক্ত));
    }

    যদি (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, রিক্ত));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    ৱিকল্প (token) {
    /* imm variant 1 */
    পক্ষ TOK_ASM_c_fsw:
    পক্ষ TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        ঘূৰাই;
    /* imm variant 2 */
    পক্ষ TOK_ASM_c_fsd:
    পক্ষ TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        ঘূৰাই;
    স্ৱভাৱ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
স্থির শূন্য asm_emit_css(পূর্ণাঙ্ক token, uint16_t opcode, ধ্রুৱ Operand *rs2, ধ্রুৱ Operand *imm)
{
    uint32_t offset;

    যদি (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, রিক্ত));
    }

    যদি (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, রিক্ত));
    }

    offset = imm->e.v;

    যদি (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, রিক্ত));
    }

    যদি (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, রিক্ত));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    ৱিকল্প (token) {
    /* imm variant 1 */
    পক্ষ TOK_ASM_c_fswsp:
    পক্ষ TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 3) << 7) | (((offset >> 2) & 0xf) << 9));
        ঘূৰাই;
    /* imm variant 2 */
    পক্ষ TOK_ASM_c_fsdsp:
    পক্ষ TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 7) << 7) | (((offset >> 3) & 7) << 10));
        ঘূৰাই;
    স্ৱভাৱ:
        expect("known instruction");
    }
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
