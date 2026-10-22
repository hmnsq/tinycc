/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#ifdef TARGET_DEFS_ONLY

#define CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#define NB_ASM_REGS 64

ST_FUNC تهی g(صحیح c);
ST_FUNC تهی gen_le16(صحیح c);
ST_FUNC تهی gen_le32(صحیح c);

/*************************************************************/
#وگرنه
/*************************************************************/
#define USING_GLOBALS
#شامل "tcc.h"

شمارش {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#define REG_FLOAT_MASK 0x20
#define REG_IS_FLOAT(register_index) ((register_index) & REG_FLOAT_MASK)
#define REG_مقدار(register_index)    ((register_index) & (REG_FLOAT_MASK-1))
#define C_ENCODE_RS1(register_index) (REG_مقدار(register_index) << 7)
#define C_ENCODE_RS2(register_index) (REG_مقدار(register_index) << 2)
#define ENCODE_RD(register_index)  (REG_مقدار(register_index) << 7)
#define ENCODE_RS1(register_index) (REG_مقدار(register_index) << 15)
#define ENCODE_RS2(register_index) (REG_مقدار(register_index) << 20)
#define NTH_BIT(b, n) ((b >> n) & 1)
#define OP_IM12S (1 << OPT_IM12S)
#define OP_IM32 (1 << OPT_IM32)
#define OP_REG (1 << OPT_REG)

تعریفنوع ساختار Operand {
    uint32_t type;
    اجتماع {
        uint8_t reg;
        uint16_t regset;
        عبارت_مقدار e;
    };
} Operand;

ایستا ثابت Operand zero = { OP_REG, { 0 }};
ایستا ثابت Operand ra = { OP_REG, { 1 }};
ایستا ثابت Operand zimm = { OP_IM12S };

ایستا تهی asm_دودویی_opcode(TCCState* s1, صحیح token);
ST_FUNC تهی asm_clobber(uint8_t *clobber_regs, ثابت نویسه *str);
ST_FUNC تهی asm_compute_constraints(ASMOperand *operands, صحیح nb_operands, صحیح nb_outputs, ثابت uint8_t *clobber_regs, صحیح *pout_reg);
ایستا تهی asm_emit_a(صحیح token, uint32_t opcode, ثابت Operand *rs1, ثابت Operand *rs2, ثابت Operand *rd1, صحیح aq, صحیح rl);
ایستا تهی asm_emit_b(صحیح token, uint32_t opcode, ثابت Operand *rs1, ثابت Operand *rs2, ثابت Operand *imm);
ایستا تهی asm_emit_i(صحیح token, uint32_t opcode, ثابت Operand *rd, ثابت Operand *rs1, ثابت Operand *rs2);
ایستا تهی asm_emit_j(صحیح token, uint32_t opcode, ثابت Operand *rd, ثابت Operand *rs2);
ایستا تهی asm_emit_opcode(uint32_t opcode);
ایستا تهی asm_emit_r(صحیح token, uint32_t opcode, ثابت Operand *rd, ثابت Operand *rs1, ثابت Operand *rs2);
ایستا تهی asm_emit_s(صحیح token, uint32_t opcode, ثابت Operand *rs1, ثابت Operand *rs2, ثابت Operand *imm);
ایستا تهی asm_emit_u(صحیح token, uint32_t opcode, ثابت Operand *rd, ثابت Operand *rs2);
ایستا تهی asm_emit_f(صحیح token, uint32_t opcode, ثابت Operand *rd, ثابت Operand *rs1, ثابت Operand *rs2);
ایستا تهی asm_emit_fb(صحیح token, uint32_t opcode, ثابت Operand *rd, ثابت Operand *rs);
ایستا تهی asm_emit_fq(صحیح token, uint32_t opcode, ثابت Operand *rd, ثابت Operand *rs1, ثابت Operand *rs2, ثابت Operand *rs3);
ST_FUNC تهی asm_gen_code(ASMOperand *operands, صحیح nb_operands, صحیح nb_outputs, صحیح is_output, uint8_t *clobber_regs, صحیح out_reg);
ایستا تهی asm_nullary_opcode(TCCState *s1, صحیح token);
ST_FUNC تهی asm_opcode(TCCState *s1, صحیح token);
ایستا صحیح asm_parse_csrvar(صحیح t);
ST_FUNC صحیح asm_parse_regvar(صحیح t);
ایستا تهی asm_ternary_opcode(TCCState *s1, صحیح token);
ایستا تهی asm_unary_opcode(TCCState *s1, صحیح token);
ایستا تهی asm_branch_opcode(TCCState *s1, صحیح token, صحیح argc);
ST_FUNC تهی gen_expr32(عبارت_مقدار *pe);
ایستا تهی parse_operand(TCCState *s1, Operand *op);
ایستا تهی parse_branch_offset_operand(TCCState *s1, Operand *op);
ایستا تهی parse_operands(TCCState *s1, Operand *ops, صحیح شمار_2);
ایستا تهی parse_mem_access_operands(TCCState *s1, Operand* ops);
ST_FUNC تهی subst_asm_operand(CString *add_str, SValue *sv, صحیح modifier);
/* C extension */
ایستا تهی asm_emit_ca(صحیح token, uint16_t opcode, ثابت Operand *rd, ثابت Operand *rs2);
ایستا تهی asm_emit_cb(صحیح token, uint16_t opcode, ثابت Operand *rs1, ثابت Operand *imm);
ایستا تهی asm_emit_ci(صحیح token, uint16_t opcode, ثابت Operand *rd, ثابت Operand *imm);
ایستا تهی asm_emit_ciw(صحیح token, uint16_t opcode, ثابت Operand *rd, ثابت Operand *imm);
ایستا تهی asm_emit_cj(صحیح token, uint16_t opcode, ثابت Operand *imm);
ایستا تهی asm_emit_cl(صحیح token, uint16_t opcode, ثابت Operand *rd, ثابت Operand *rs1, ثابت Operand *imm);
ایستا تهی asm_emit_cr(صحیح token, uint16_t opcode, ثابت Operand *rd, ثابت Operand *rs2);
ایستا تهی asm_emit_cs(صحیح token, uint16_t opcode, ثابت Operand *rs2, ثابت Operand *rs1, ثابت Operand *imm);
ایستا تهی asm_emit_css(صحیح token, uint16_t opcode, ثابت Operand *rs2, ثابت Operand *imm);

/* XXX: make it faster ? */
ST_FUNC تهی g(صحیح c)
{
    صحیح ind1;
    اگر (nocode_wanted)
        بازگشت;
    ind1 = ind + 1;
    اگر (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC تهی gen_le16 (صحیح i)
{
    g(i);
    g(i>>8);
}

ST_FUNC تهی gen_le32 (صحیح i)
{
    صحیح ind1;
    اگر (nocode_wanted)
        بازگشت;
    ind1 = ind + 4;
    اگر (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC تهی gen_expr32(عبارت_مقدار *pe)
{
    gen_le32(pe->v);
}

ایستا تهی asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ایستا تهی asm_nullary_opcode(TCCState *s1, صحیح token)
{
    انتخاب (token) {
    // Sync instructions

    حالت TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        بازگشت;

    // System calls

    حالت TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        بازگشت;
    حالت TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        بازگشت;

    // Other

    حالت TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        بازگشت;

    حالت TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        بازگشت;

    /* Pseudoinstructions */
    حالت TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        بازگشت;

    /* C extension */
    حالت TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        بازگشت;
    حالت TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        بازگشت;

    پیشفرض:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
ایستا تهی parse_operand(TCCState *s1, Operand *op)
{
    عبارت_مقدار e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    اگر ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        بازگشت;
    } وگرنه اگر (tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    } وگرنه اگر ((e.v = asm_parse_csrvar(tok)) != -1) {
        next();
    } وگرنه {
        asm_عبارت(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    اگر (!op->e.sym) {
        اگر ((صحیح) op->e.v >= -0x1000 && (صحیح) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } وگرنه اگر (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        اگر (op->e.sym->type.t & VT_STATIC)
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_PCREL_HI20, 0);
        وگرنه
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_GOT_HI20, 0);
        put_extern_sym(&label, cur_text_section, ind, 0);
        greloca(cur_text_section, &label, ind+4, R_RISCV_PCREL_LO12_I, 0);

        op->type = OP_IM12S;
        op->e.v = 0;
    } وگرنه {
        expect("operand");
    }
}

ایستا تهی parse_branch_offset_operand(TCCState *s1, Operand *op){
    عبارت_مقدار e = {0};

    asm_عبارت(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    اگر (!op->e.sym) {
        اگر ((صحیح) op->e.v >= -0x1000 && (صحیح) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } وگرنه اگر (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } وگرنه {
        expect("operand");
    }
}

ایستا تهی parse_jump_offset_operand(TCCState *s1, Operand *op){
    عبارت_مقدار e = {0};

    asm_عبارت(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    اگر (!op->e.sym) {
        اگر ((صحیح) op->e.v >= -0x1000 && (صحیح) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } وگرنه اگر (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_text_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } وگرنه {
        expect("operand");
    }
}

ایستا تهی parse_operands(TCCState *s1, Operand* ops, صحیح شمار_2){
    صحیح i;
    برای (i = 0; i < شمار_2; i++) {
        اگر ( i != 0 )
            skip(',');
        parse_operand(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
ایستا تهی parse_mem_access_operands(TCCState *s1, Operand* ops){

    Operand op;

    parse_operand(s1, &ops[0]);
    skip(',');
    اگر ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } وگرنه {
        parse_operand(s1, &ops[2]);
        اگر ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } وگرنه {
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
ایستا تهی asm_jal_opcode(TCCState *s1, صحیح token){
    Operand ops[2];

    اگر (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } وگرنه اگر (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } وگرنه {
        // jal reg, offset
        parse_operand(s1, &ops[0]);
        اگر ( tok == ',') next(); وگرنه expect("','");
    }
    parse_jump_offset_operand(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
ایستا تهی asm_jalr_opcode(TCCState *s1, صحیح token){
    Operand ops[3];
    Operand op;

    parse_operand(s1, &ops[0]);
    اگر ( tok == ',')
        next();
    وگرنه {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        بازگشت;
    }

    اگر ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } وگرنه {
        parse_operand(s1, &ops[2]);
        اگر ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } وگرنه {
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


ایستا تهی asm_unary_opcode(TCCState *s1, صحیح token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    Operand op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    انتخاب (token) {
    /* pseudoinstructions */
    حالت TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        بازگشت;
    حالت TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        بازگشت;
    حالت TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        بازگشت;
    حالت TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        بازگشت;
    حالت TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        بازگشت;
    حالت TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        بازگشت;
    حالت TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        بازگشت;
    حالت TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        بازگشت;
    حالت TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        بازگشت;

    حالت TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        بازگشت;
    حالت TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        بازگشت;
    حالت TOK_ASM_tail:
        /* auipc x6, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        بازگشت;

    /* C extension */
    حالت TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        بازگشت;
    حالت TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        بازگشت;
    حالت TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        بازگشت;
    حالت TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        بازگشت;

    پیشفرض:
        expect("unary instruction");
    }
}

ایستا تهی asm_emit_u(صحیح token, uint32_t opcode, ثابت Operand* rd, ثابت Operand* rs2)
{
    اگر (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }
    اگر (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, پوچ));
    } وگرنه اگر (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, پوچ));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

ایستا صحیح parse_fence_operand(){
    صحیح t = tok;
    اگر ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    next();
    بازگشت t - (TOK_ASM_w_fence - 1);
}

ایستا تهی asm_fence_opcode(TCCState *s1, صحیح token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    صحیح succ = 0xF, pred = 0xF;
    اگر (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_operand();
        اگر ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, پوچ));
        }
        skip(',');
        succ = parse_fence_operand();
        اگر ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, پوچ));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

ایستا تهی asm_دودویی_opcode(TCCState* s1, صحیح token)
{
    Operand imm = { OP_IM12S };
    Operand ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    انتخاب (token) {
    حالت TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        بازگشت;
    حالت TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        بازگشت;

    /* C extension */
    حالت TOK_ASM_c_add:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        بازگشت;

    حالت TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        بازگشت;

    حالت TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        بازگشت;

#define CA (1 | (3 << 10) | (4 << 13))
    حالت TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        بازگشت;
#undef CA

    حالت TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        بازگشت;

    حالت TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        بازگشت;

    /* F/D extension */
    حالت TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        بازگشت;

    /* pseudoinstructions */
    /* rd, sym */
    حالت TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        بازگشت;
    حالت TOK_ASM_li:
        اگر(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, پوچ));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        اگر(lo < 0){
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
        بازگشت;
    حالت TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        بازگشت;
    حالت TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        بازگشت;
    حالت TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        بازگشت;
    حالت TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        بازگشت;
    حالت TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        بازگشت;
    حالت TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        بازگشت;
    حالت TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        بازگشت;
    حالت TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        بازگشت;
    حالت TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        بازگشت;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    حالت TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_text_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        بازگشت;
    حالت TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        بازگشت;
    حالت TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        بازگشت;
    حالت TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        بازگشت;
    حالت TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        بازگشت;

    حالت TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        بازگشت;
    حالت TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        بازگشت;

    /* CSR pseudo-instructions */
    حالت TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        بازگشت;
    حالت TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        بازگشت;
    حالت TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        بازگشت;
    حالت TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        بازگشت;
    حالت TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        بازگشت;
    حالت TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        بازگشت;
    حالت TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        بازگشت;
    حالت TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        بازگشت;
    حالت TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        بازگشت;
    پیشفرض:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
ایستا تهی asm_emit_r(صحیح token, uint32_t opcode, ثابت Operand* rd, ثابت Operand* rs1, ثابت Operand* rs2)
{
    اگر (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }
    اگر (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, پوچ));
    }
    اگر (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, پوچ));
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
ایستا تهی asm_emit_f(صحیح token, uint32_t opcode, ثابت Operand* rd, ثابت Operand* rs1, ثابت Operand* rs2)
{
    اگر (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, پوچ));
    }
    اگر (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, پوچ));
    }
    اگر (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, پوچ));
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
ایستا تهی asm_emit_fb(صحیح token, uint32_t opcode, ثابت Operand* rd, ثابت Operand* rs)
{
    اگر (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, پوچ));
    }
    اگر (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, پوچ));
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
ایستا تهی asm_emit_fq(صحیح token, uint32_t opcode, ثابت Operand* rd, ثابت Operand* rs1, ثابت Operand* rs2, ثابت Operand* rs3)
{
    اگر (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, پوچ));
    }
    اگر (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, پوچ));
    }
    اگر (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, پوچ));
    }
    اگر (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, پوچ));
    }
    /* F-type instruction:
	     31...27 rs3
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (REG_مقدار(rs3->reg) << 27));
}

/* caller: Add funct3 into opcode */
ایستا تهی asm_emit_i(صحیح token, uint32_t opcode, ثابت Operand* rd, ثابت Operand* rs1, ثابت Operand* rs2)
{
    اگر (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }
    اگر (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, پوچ));
    }
    اگر (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, پوچ));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

ایستا تهی asm_emit_j(صحیح token, uint32_t opcode, ثابت Operand* rd, ثابت Operand* rs2)
{
    uint32_t imm;

    اگر (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }
    اگر (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, پوچ));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    اگر ((صحیح)imm > (1 << 20) -1 || (صحیح)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, پوچ));
    }

    اگر (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, پوچ));
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

ایستا تهی asm_mem_access_opcode(TCCState *s1, صحیح token)
{

    Operand ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    اگر (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    انتخاب (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    حالت TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    حالت TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         بازگشت;
    حالت TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         بازگشت;
    حالت TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         بازگشت;
    حالت TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         بازگشت;
    حالت TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         بازگشت;
    }
}

ایستا تهی asm_branch_opcode(TCCState *s1, صحیح token, صحیح argc)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_offset_operand(s1, &ops[argc-1]);

    انتخاب(token){
    /* branch (RS1, RS2, IMM); B-format */
    حالت TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    /* related pseudoinstructions */
    حالت TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        بازگشت;
    حالت TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        بازگشت;
    حالت TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        بازگشت;
    حالت TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        بازگشت;
    /* shorter pseudoinstructions */
    حالت TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        بازگشت;
    حالت TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        بازگشت;
    حالت TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        بازگشت;
    حالت TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        بازگشت;
    حالت TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        بازگشت;
    حالت TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        بازگشت;
    }
}

ایستا تهی asm_ternary_opcode(TCCState *s1, صحیح token)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], 3);

    انتخاب (token) {
    حالت TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        بازگشت;
    حالت TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        بازگشت;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    حالت TOK_ASM_add:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         بازگشت;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    حالت TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    حالت TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;
    حالت TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         بازگشت;

    /* M extension */
    حالت TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        بازگشت;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    حالت TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        بازگشت;
    حالت TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        بازگشت;
    حالت TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        بازگشت;
    حالت TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        بازگشت;
    حالت TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        بازگشت;
    حالت TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        بازگشت;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    حالت TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        بازگشت;

    /* F/D extension */
    حالت TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        بازگشت;
    حالت TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        بازگشت;

    /* F/D comparison: produce integer result, encode manually */
    حالت TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        بازگشت;
    حالت TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        بازگشت;
    حالت TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        بازگشت;
    حالت TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        بازگشت;
    حالت TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        بازگشت;
    حالت TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        بازگشت;

    پیشفرض:
        expect("ternary instruction");
    }
}

ایستا تهی asm_quaternary_opcode(TCCState *s1, صحیح token)
{
    Operand ops[4];
    parse_operands(s1, &ops[0], 4);

    انتخاب (token) {
    حالت TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        بازگشت;
    حالت TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        بازگشت;

    پیشفرض:
        expect("quaternary instruction");
    }
}

ایستا تهی asm_atomic_opcode(TCCState *s1, صحیح token)
{
    Operand ops[3];

    parse_operand(s1, &ops[0]);
    skip(',');

    اگر ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } وگرنه {
        parse_operand(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_operand(s1, &ops[2]);
    skip(')');

    انتخاب(token){
        حالت TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            بشکن;
        حالت TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            بشکن;
        حالت TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            بشکن;
        حالت TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            بشکن;

        حالت TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            بشکن;
        حالت TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            بشکن;
        حالت TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            بشکن;
        حالت TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            بشکن;

        حالت TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            بشکن;
        حالت TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            بشکن;
        حالت TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            بشکن;
        حالت TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            بشکن;

        حالت TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            بشکن;
        حالت TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            بشکن;
        حالت TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            بشکن;
        حالت TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            بشکن;

        /* AMO instructions (base, aq=0 rl=0) */
        حالت TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;
        حالت TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); بشکن;

        /* AMO aq/rl variants */
        حالت TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;

        حالت TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
        حالت TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); بشکن;
        حالت TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); بشکن;
        حالت TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); بشکن;
    }
}

/* caller: Add funct3 and func5 to opcode */
ایستا تهی asm_emit_a(صحیح token, uint32_t opcode, ثابت Operand *rd1, ثابت Operand *rs2, ثابت Operand *rs1, صحیح aq, صحیح rl)
{
    اگر (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, پوچ));
    اگر (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, پوچ));
    اگر (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, پوچ));
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
ایستا تهی asm_emit_s(صحیح token, uint32_t opcode, ثابت Operand* rs1, ثابت Operand* rs2, ثابت Operand* imm)
{
    اگر (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, پوچ));
    }
    اگر (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, پوچ));
    }
    اگر (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, پوچ));
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

ایستا تهی asm_emit_b(صحیح token, uint32_t opcode, ثابت Operand *rs1, ثابت Operand *rs2, ثابت Operand *imm)
{
    uint32_t offset;

    اگر (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, پوچ));
    }
    اگر (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }
    اگر (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        صحیح b_ofs = ind;
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
        بازگشت;
    }
    اگر (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, پوچ));
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
ایستا صحیح asm_fcvt_rm(TCCState *s1)
{
    صحیح rm = 7; /* dynamic */
    اگر (tok == ',') {
        next();
        انتخاب (tok) {
            حالت TOK_ASM_rne: rm = 0; next(); بشکن;
            حالت TOK_ASM_rtz: rm = 1; next(); بشکن;
            حالت TOK_ASM_rdn: rm = 2; next(); بشکن;
            حالت TOK_ASM_rup: rm = 3; next(); بشکن;
            حالت TOK_ASM_rmm: rm = 4; next(); بشکن;
            پیشفرض: expect("rounding mode"); بشکن;
        }
    }
    بازگشت rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
ایستا تهی asm_fcvt_opcode(TCCState *s1, صحیح token)
{
    Operand ops[2];
    صحیح rm;
    uint32_t enc = 0;

    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);

    انتخاب (token) {
        حالت TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); بشکن;
        حالت TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); بشکن;
        حالت TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); بشکن;
        حالت TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); بشکن;
        حالت TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); بشکن;
        حالت TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); بشکن;
        حالت TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); بشکن;
        حالت TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); بشکن;
        حالت TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); بشکن;
        حالت TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); بشکن;
        حالت TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); بشکن;
        حالت TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); بشکن;
        حالت TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); بشکن;
        حالت TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); بشکن;
        حالت TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); بشکن;
        حالت TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); بشکن;
        حالت TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); بشکن;
        حالت TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); بشکن;
        حالت TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); بشکن;
        حالت TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); بشکن;
        پیشفرض: expect("fcvt/fclass instruction"); بازگشت;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC تهی asm_opcode(TCCState *s1, صحیح token)
{
    انتخاب (token) {
    حالت TOK_ASM_ebreak:
    حالت TOK_ASM_ecall:
    حالت TOK_ASM_fence_i:
    حالت TOK_ASM_hrts:
    حالت TOK_ASM_mrth:
    حالت TOK_ASM_mrts:
    حالت TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_rdcycle:
    حالت TOK_ASM_rdcycleh:
    حالت TOK_ASM_rdtime:
    حالت TOK_ASM_rdtimeh:
    حالت TOK_ASM_rdinstret:
    حالت TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_lui:
    حالت TOK_ASM_auipc:
    حالت TOK_ASM_fsqrt_s:
    حالت TOK_ASM_fsqrt_d:
        asm_دودویی_opcode(s1, token);
        بازگشت;

    /* fcvt/fclass — separate handler for optional rounding operand */
    حالت TOK_ASM_fcvt_w_s:
    حالت TOK_ASM_fcvt_wu_s:
    حالت TOK_ASM_fcvt_l_s:
    حالت TOK_ASM_fcvt_lu_s:
    حالت TOK_ASM_fcvt_s_w:
    حالت TOK_ASM_fcvt_s_wu:
    حالت TOK_ASM_fcvt_s_l:
    حالت TOK_ASM_fcvt_s_lu:
    حالت TOK_ASM_fcvt_w_d:
    حالت TOK_ASM_fcvt_wu_d:
    حالت TOK_ASM_fcvt_l_d:
    حالت TOK_ASM_fcvt_lu_d:
    حالت TOK_ASM_fcvt_d_w:
    حالت TOK_ASM_fcvt_d_wu:
    حالت TOK_ASM_fcvt_d_l:
    حالت TOK_ASM_fcvt_d_lu:
    حالت TOK_ASM_fcvt_s_d:
    حالت TOK_ASM_fcvt_d_s:
    حالت TOK_ASM_fclass_s:
    حالت TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_lb:
    حالت TOK_ASM_lh:
    حالت TOK_ASM_lw:
    حالت TOK_ASM_ld:
    حالت TOK_ASM_fld:
    حالت TOK_ASM_lbu:
    حالت TOK_ASM_lhu:
    حالت TOK_ASM_lwu:
    حالت TOK_ASM_sb:
    حالت TOK_ASM_sh:
    حالت TOK_ASM_sw:
    حالت TOK_ASM_sd:
    حالت TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        بشکن;

    حالت TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        بشکن;
    حالت TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        بازگشت;
    حالت TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        بشکن;

    حالت TOK_ASM_add:
    حالت TOK_ASM_addi:
    حالت TOK_ASM_addiw:
    حالت TOK_ASM_addw:
    حالت TOK_ASM_and:
    حالت TOK_ASM_andi:
    حالت TOK_ASM_or:
    حالت TOK_ASM_ori:
    حالت TOK_ASM_sll:
    حالت TOK_ASM_slli:
    حالت TOK_ASM_slliw:
    حالت TOK_ASM_sllw:
    حالت TOK_ASM_slt:
    حالت TOK_ASM_slti:
    حالت TOK_ASM_sltiu:
    حالت TOK_ASM_sltu:
    حالت TOK_ASM_sra:
    حالت TOK_ASM_srai:
    حالت TOK_ASM_sraiw:
    حالت TOK_ASM_sraw:
    حالت TOK_ASM_srl:
    حالت TOK_ASM_srli:
    حالت TOK_ASM_srliw:
    حالت TOK_ASM_srlw:
    حالت TOK_ASM_sub:
    حالت TOK_ASM_subw:
    حالت TOK_ASM_xor:
    حالت TOK_ASM_xori:
    /* M extension */
    حالت TOK_ASM_div:
    حالت TOK_ASM_divu:
    حالت TOK_ASM_divuw:
    حالت TOK_ASM_divw:
    حالت TOK_ASM_mul:
    حالت TOK_ASM_mulh:
    حالت TOK_ASM_mulhsu:
    حالت TOK_ASM_mulhu:
    حالت TOK_ASM_mulw:
    حالت TOK_ASM_rem:
    حالت TOK_ASM_remu:
    حالت TOK_ASM_remuw:
    حالت TOK_ASM_remw:
    /* Zicsr extension */
    حالت TOK_ASM_csrrc:
    حالت TOK_ASM_csrrci:
    حالت TOK_ASM_csrrs:
    حالت TOK_ASM_csrrsi:
    حالت TOK_ASM_csrrw:
    حالت TOK_ASM_csrrwi:
    /* F/D extension */
    حالت TOK_ASM_fadd_s:
    حالت TOK_ASM_fadd_d:
    حالت TOK_ASM_fsub_s:
    حالت TOK_ASM_fsub_d:
    حالت TOK_ASM_fmul_s:
    حالت TOK_ASM_fmul_d:
    حالت TOK_ASM_fdiv_s:
    حالت TOK_ASM_fdiv_d:
    حالت TOK_ASM_fsgnj_d:
    حالت TOK_ASM_fsgnj_s:
    حالت TOK_ASM_fmax_s:
    حالت TOK_ASM_fmax_d:
    حالت TOK_ASM_fmin_s:
    حالت TOK_ASM_fmin_d:
    حالت TOK_ASM_feq_s:
    حالت TOK_ASM_feq_d:
    حالت TOK_ASM_flt_s:
    حالت TOK_ASM_flt_d:
    حالت TOK_ASM_fle_s:
    حالت TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        بازگشت;
    حالت TOK_ASM_fmadd_d:
    حالت TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        بازگشت;

    /* Branches */
    حالت TOK_ASM_beq:
    حالت TOK_ASM_bge:
    حالت TOK_ASM_bgeu:
    حالت TOK_ASM_blt:
    حالت TOK_ASM_bltu:
    حالت TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        بشکن;

    /* C extension */
    حالت TOK_ASM_c_ebreak:
    حالت TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_c_j:
    حالت TOK_ASM_c_jal:
    حالت TOK_ASM_c_jalr:
    حالت TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_c_add:
    حالت TOK_ASM_c_addi16sp:
    حالت TOK_ASM_c_addi4spn:
    حالت TOK_ASM_c_addi:
    حالت TOK_ASM_c_addiw:
    حالت TOK_ASM_c_addw:
    حالت TOK_ASM_c_and:
    حالت TOK_ASM_c_andi:
    حالت TOK_ASM_c_beqz:
    حالت TOK_ASM_c_bnez:
    حالت TOK_ASM_c_fldsp:
    حالت TOK_ASM_c_flwsp:
    حالت TOK_ASM_c_fsdsp:
    حالت TOK_ASM_c_fswsp:
    حالت TOK_ASM_c_ldsp:
    حالت TOK_ASM_c_li:
    حالت TOK_ASM_c_lui:
    حالت TOK_ASM_c_lwsp:
    حالت TOK_ASM_c_mv:
    حالت TOK_ASM_c_or:
    حالت TOK_ASM_c_sdsp:
    حالت TOK_ASM_c_slli:
    حالت TOK_ASM_c_srai:
    حالت TOK_ASM_c_srli:
    حالت TOK_ASM_c_sub:
    حالت TOK_ASM_c_subw:
    حالت TOK_ASM_c_swsp:
    حالت TOK_ASM_c_xor:
        asm_دودویی_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_c_fld:
    حالت TOK_ASM_c_flw:
    حالت TOK_ASM_c_fsd:
    حالت TOK_ASM_c_fsw:
    حالت TOK_ASM_c_ld:
    حالت TOK_ASM_c_lw:
    حالت TOK_ASM_c_sd:
    حالت TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        بازگشت;

    /* pseudoinstructions */
    حالت TOK_ASM_nop:
    حالت TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_jr:
    حالت TOK_ASM_call:
    حالت TOK_ASM_tail:
    حالت TOK_ASM_frflags:
    حالت TOK_ASM_frrm:
    حالت TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_la:
    حالت TOK_ASM_lla:
    حالت TOK_ASM_li:
    حالت TOK_ASM_jump:
    حالت TOK_ASM_seqz:
    حالت TOK_ASM_snez:
    حالت TOK_ASM_sltz:
    حالت TOK_ASM_sgtz:
    حالت TOK_ASM_mv:
    حالت TOK_ASM_not:
    حالت TOK_ASM_neg:
    حالت TOK_ASM_negw:
    حالت TOK_ASM_sext_w:
    حالت TOK_ASM_fabs_s:
    حالت TOK_ASM_fabs_d:
    حالت TOK_ASM_fmv_s:
    حالت TOK_ASM_fmv_d:
    حالت TOK_ASM_fneg_s:
    حالت TOK_ASM_fneg_d:
    حالت TOK_ASM_csrc:
    حالت TOK_ASM_csrs:
    حالت TOK_ASM_csrr:
    حالت TOK_ASM_csrw:
    حالت TOK_ASM_csrwi:
    حالت TOK_ASM_csrsi:
    حالت TOK_ASM_csrci:
    حالت TOK_ASM_fsrm:
    حالت TOK_ASM_fscsr:
        asm_دودویی_opcode(s1, token);
        بازگشت;

    حالت TOK_ASM_bnez:
    حالت TOK_ASM_beqz:
    حالت TOK_ASM_blez:
    حالت TOK_ASM_bgez:
    حالت TOK_ASM_bltz:
    حالت TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        بازگشت;

    حالت TOK_ASM_bgt:
    حالت TOK_ASM_bgtu:
    حالت TOK_ASM_ble:
    حالت TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        بازگشت;

    /* Atomic operations */
    حالت TOK_ASM_lr_w:
    حالت TOK_ASM_lr_w_aq:
    حالت TOK_ASM_lr_w_rl:
    حالت TOK_ASM_lr_w_aqrl:
    حالت TOK_ASM_lr_d:
    حالت TOK_ASM_lr_d_aq:
    حالت TOK_ASM_lr_d_rl:
    حالت TOK_ASM_lr_d_aqrl:
    حالت TOK_ASM_sc_w:
    حالت TOK_ASM_sc_w_aq:
    حالت TOK_ASM_sc_w_rl:
    حالت TOK_ASM_sc_w_aqrl:
    حالت TOK_ASM_sc_d:
    حالت TOK_ASM_sc_d_aq:
    حالت TOK_ASM_sc_d_rl:
    حالت TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    حالت TOK_ASM_amoadd_w:
    حالت TOK_ASM_amoadd_d:
    حالت TOK_ASM_amoswap_w:
    حالت TOK_ASM_amoswap_d:
    حالت TOK_ASM_amoand_w:
    حالت TOK_ASM_amoand_d:
    حالت TOK_ASM_amoor_w:
    حالت TOK_ASM_amoor_d:
    حالت TOK_ASM_amoxor_w:
    حالت TOK_ASM_amoxor_d:
    حالت TOK_ASM_amomax_w:
    حالت TOK_ASM_amomax_d:
    حالت TOK_ASM_amomaxu_w:
    حالت TOK_ASM_amomaxu_d:
    حالت TOK_ASM_amomin_w:
    حالت TOK_ASM_amomin_d:
    حالت TOK_ASM_amominu_w:
    حالت TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    حالت TOK_ASM_amoadd_w_aq:
    حالت TOK_ASM_amoadd_w_rl:
    حالت TOK_ASM_amoadd_w_aqrl:
    حالت TOK_ASM_amoadd_d_aq:
    حالت TOK_ASM_amoadd_d_rl:
    حالت TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    حالت TOK_ASM_amoswap_w_aq:
    حالت TOK_ASM_amoswap_w_rl:
    حالت TOK_ASM_amoswap_w_aqrl:
    حالت TOK_ASM_amoswap_d_aq:
    حالت TOK_ASM_amoswap_d_rl:
    حالت TOK_ASM_amoswap_d_aqrl:
    حالت TOK_ASM_amoand_w_aq:
    حالت TOK_ASM_amoand_w_rl:
    حالت TOK_ASM_amoand_w_aqrl:
    حالت TOK_ASM_amoand_d_aq:
    حالت TOK_ASM_amoand_d_rl:
    حالت TOK_ASM_amoand_d_aqrl:
    حالت TOK_ASM_amoor_w_aq:
    حالت TOK_ASM_amoor_w_rl:
    حالت TOK_ASM_amoor_w_aqrl:
    حالت TOK_ASM_amoor_d_aq:
    حالت TOK_ASM_amoor_d_rl:
    حالت TOK_ASM_amoor_d_aqrl:
    حالت TOK_ASM_amoxor_w_aq:
    حالت TOK_ASM_amoxor_w_rl:
    حالت TOK_ASM_amoxor_w_aqrl:
    حالت TOK_ASM_amoxor_d_aq:
    حالت TOK_ASM_amoxor_d_rl:
    حالت TOK_ASM_amoxor_d_aqrl:
    حالت TOK_ASM_amomax_w_aq:
    حالت TOK_ASM_amomax_w_rl:
    حالت TOK_ASM_amomax_w_aqrl:
    حالت TOK_ASM_amomax_d_aq:
    حالت TOK_ASM_amomax_d_rl:
    حالت TOK_ASM_amomax_d_aqrl:
    حالت TOK_ASM_amomaxu_w_aq:
    حالت TOK_ASM_amomaxu_w_rl:
    حالت TOK_ASM_amomaxu_w_aqrl:
    حالت TOK_ASM_amomaxu_d_aq:
    حالت TOK_ASM_amomaxu_d_rl:
    حالت TOK_ASM_amomaxu_d_aqrl:
    حالت TOK_ASM_amomin_w_aq:
    حالت TOK_ASM_amomin_w_rl:
    حالت TOK_ASM_amomin_w_aqrl:
    حالت TOK_ASM_amomin_d_aq:
    حالت TOK_ASM_amomin_d_rl:
    حالت TOK_ASM_amomin_d_aqrl:
    حالت TOK_ASM_amominu_w_aq:
    حالت TOK_ASM_amominu_w_rl:
    حالت TOK_ASM_amominu_w_aqrl:
    حالت TOK_ASM_amominu_d_aq:
    حالت TOK_ASM_amominu_d_rl:
    حالت TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        بشکن;

    پیشفرض:
        expect("known instruction");
    }
}

ایستا صحیح asm_parse_csrvar(صحیح t)
{
    انتخاب (t) {
    حالت TOK_ASM_cycle:
        بازگشت 0xc00;
    حالت TOK_ASM_fcsr:
        بازگشت 3;
    حالت TOK_ASM_fflags:
        بازگشت 1;
    حالت TOK_ASM_frm:
        بازگشت 2;
    حالت TOK_ASM_instret:
        بازگشت 0xc02;
    حالت TOK_ASM_time:
        بازگشت 0xc01;
    حالت TOK_ASM_cycleh:
        بازگشت 0xc80;
    حالت TOK_ASM_instreth:
        بازگشت 0xc82;
    حالت TOK_ASM_timeh:
        بازگشت 0xc81;
    پیشفرض:
        بازگشت -1;
    }
}

ST_FUNC تهی subst_asm_operand(CString *add_str, SValue *sv, صحیح modifier)
{
    صحیح r, reg, val;

    r = sv->r;
    اگر ((r & VT_VALMASK) == VT_CONST) {
        اگر (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        اگر (r & VT_SYM) {
            ثابت نویسه *name = get_tok_str(sv->sym->v, پوچ);
            اگر (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            اگر (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            اگر ((uint32_t) sv->c.i == 0)
                برو no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        اگر (modifier == 'n')
            val = -val;
        اگر (modifier == 'z' && val == 0) {
            cstr_cat(add_str, "zero", -1);
        } وگرنه {
            cstr_printf(add_str, "%d", val);
        }
      no_offset:;
    } وگرنه اگر ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d", (صحیح) sv->c.i);
    } وگرنه اگر (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_internal_error("");
        اگر ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_مقدار(reg);
        } وگرنه {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, پوچ), -1);
    } وگرنه {
        /* register case */
        reg = r & VT_VALMASK;
        اگر (reg >= VT_CONST)
            tcc_internal_error("");
        اگر ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_مقدار(reg);
        } وگرنه {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, پوچ), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
ایستا صحیح tcc_ireg(صحیح r){
    بازگشت REG_مقدار(r) - 10;
}
ایستا صحیح tcc_freg(صحیح r){
    بازگشت REG_مقدار(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC تهی asm_gen_code(ASMOperand *operands, صحیح nb_operands,
                         صحیح nb_outputs, صحیح is_output,
                         uint8_t *clobber_regs,
                         صحیح out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    صحیح i, reg;

    ایستا ثابت uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, اندازه(regs_allocated));
    برای(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        اگر (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    اگر(!is_output) {
        /* generate reg save code */
        برای(i = 0; i < اندازه(reg_saved)/اندازه(reg_saved[0]); i++) {
            reg = reg_saved[i];
            اگر (regs_allocated[reg]) {
                /*افزودن*/
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (unsigned)-8 << 20);
                اگر (REG_IS_FLOAT(reg)){
                    /* fsd reg, offset(sp) */
                    gen_le32( 0x27 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                } وگرنه {
                    /* sd reg, offset(sp) */
                    gen_le32((0x8 << 2) | 3 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                }
            }
        }

        /* generate load code */
        برای(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(tcc_ireg(op->reg), &sv);
                } وگرنه اگر (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    اگر ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        load(tcc_freg(op->reg), op->vt);
                    } وگرنه {
                        load(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register;
                       the load/store above already handles it correctly */
                }
            }
        }
    } وگرنه {
        /* generate save code */
        برای(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            اگر (op->reg >= 0) {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    اگر (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(tcc_ireg(out_reg), &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(tcc_ireg(op->reg), &sv);
                    }
                } وگرنه {
                    اگر ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        store(tcc_freg(op->reg), op->vt);
                    } وگرنه {
                        store(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register */
                }
            }
        }
        /* generate reg restore code for floating point registers */
        برای(i = اندازه(reg_saved)/اندازه(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            اگر (regs_allocated[reg]) {
                /*برداشت*/
                اگر (REG_IS_FLOAT(reg)){
                    /* fld reg, offset(sp) */
                    gen_le32(7 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                } وگرنه {
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
ایستا درونخطی صحیح constraint_priority(ثابت نویسه *str)
{
    // TODO: How is this chosen??
    صحیح priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    برای(;;) {
        c = *str;
        اگر (c == '\0')
            بشکن;
        str++;
        انتخاب(c) {
        حالت 'A': // address that is held in a general-purpose register.
        حالت 'S': // constraint that matches an absolute symbolic address.
        حالت 'f': // register [float]
        حالت 'r': // register [general]
        حالت 'p': // valid memory address for load,store [general]
            pr = 3;
            بشکن;
        حالت 'I': // 12 bit signed immedate
        حالت 'i': // immediate integer operand, including symbolic constants [general]
        حالت 'm': // memory operand [general]
        حالت 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            بشکن;
        حالت 'v':
            tcc_error("unimp: constraint '%c'", c);
        پیشفرض:
            tcc_error("unknown constraint '%d'", c);
        }
        اگر (pr > priority)
            priority = pr;
    }
    بازگشت priority;
}

ایستا ثابت نویسه *skip_constraint_modifiers(ثابت نویسه *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    وقتی (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    بازگشت p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC تهی asm_compute_constraints(ASMOperand *operands,
                                    صحیح nb_operands, صحیح nb_outputs,
                                    ثابت uint8_t *clobber_regs,
                                    صحیح *pout_reg)
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
    صحیح sorted_op[MAX_ASM_OPERANDS];
    صحیح i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ثابت نویسه *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    برای (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->درون_داد_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    برای (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        اگر (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, پوچ);
            اگر ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            اگر (operands[k].درون_داد_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].درون_داد_index = i;
            op->priority = 5;
        } وگرنه اگر ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } وگرنه {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    برای (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    برای (i = 0; i < nb_operands - 1; i++) {
        برای (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            اگر (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    برای (i = 0; i < NB_ASM_REGS; i++) {
        اگر (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        وگرنه
            regs_allocated[i] = 0;
    }

    /* allocate registers and generate corresponding asm moves */
    برای (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        اگر (op->ref_index >= 0)
            ادامه;
        /* select if register is used for output, input or both */
        اگر (op->درون_داد_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } وگرنه اگر (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } وگرنه {
            reg_mask = REG_IN_MASK;
        }
        اگر (op->reg >= 0) {
            اگر (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        انتخاب (c) {
        حالت '=': // Operand is written-to
            برو try_next;
        حالت '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        حالت '&': // Operand is clobbered before the instruction is done using the input operands
            اگر (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            برو try_next;
        حالت 'r': // general-purpose register
        حالت 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            اگر ((reg = op->reg) >= 0)
                برو reg_found;
            وگرنه برای (reg = 10; reg <= 18; reg++) {
                اگر (!is_reg_allocated(reg))
                    برو reg_found;
            }
            برو try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            بشکن;
        حالت 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            اگر ((reg = op->reg) >= 0)
                برو reg_found;
            وگرنه برای (reg = 42; reg <= 50; reg++) {
                اگر (!is_reg_allocated(reg))
                    برو reg_found;
            }
            برو try_next;
        حالت 'I': // I-Type 12 bit signed immediate
        حالت 'i': // immediate integer operand, including symbolic constants
            اگر (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                برو try_next;
            بشکن;
        حالت 'm': // memory operand
        حالت 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            اگر (j < nb_outputs || c == 'm') {
                اگر ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    برای (reg = 10; reg <= 18; reg++) {
                        اگر (!(regs_allocated[reg] & REG_IN_MASK))
                            برو reg_found1;
                    }
                    برو try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            بشکن;
        پیشفرض:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            بشکن;
        }
        /* if a reference is present for that operand, we assign it too */
        اگر (op->درون_داد_index >= 0) {
            operands[op->درون_داد_index].reg = op->reg;
            operands[op->درون_داد_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    برای (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        اگر (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            اگر (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                برای (reg = 42; reg <= 50; reg++) {
                    اگر (!(regs_allocated[reg] & REG_OUT_MASK))
                        برو reg_found2;
                }
            } وگرنه {
                /* From a0 to a7 */
                برای (reg = 10; reg <= 18; reg++) {
                    اگر (!(regs_allocated[reg] & REG_OUT_MASK))
                        برو reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            بشکن;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    برای (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, پوچ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    اگر (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC تهی asm_clobber(uint8_t *clobber_regs, ثابت نویسه *str)
{
    صحیح reg;
    TokenSym *ts;

    اگر (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        بازگشت;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    اگر (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC صحیح asm_parse_regvar (صحیح t)
{
    /* PC register not implemented */
    اگر (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        بازگشت -1;

    اگر (t < TOK_ASM_f0)
        بازگشت t - TOK_ASM_x0;

    اگر (t < TOK_ASM_zero)
        بازگشت t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    اگر (t < TOK_ASM_ft0)
        بازگشت t - TOK_ASM_zero;

    بازگشت t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
ایستا تهی asm_emit_ca(صحیح token, uint16_t opcode, ثابت Operand *rd, ثابت Operand *rs2)
{
    uint8_t dst, src;

    اگر (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }

    اگر (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, پوچ));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    اگر (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, پوچ));
    }

    اگر (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, پوچ));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

ایستا تهی asm_emit_cb(صحیح token, uint16_t opcode, ثابت Operand *rs1, ثابت Operand *imm)
{
    uint32_t offset;
    uint8_t src;

    اگر (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, پوچ));
    }

    اگر (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, پوچ));
    }

    offset = imm->e.v;

    اگر (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, پوچ));
    }

    src = rs1->reg - 8;

    اگر (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, پوچ));
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

    انتخاب (token) {
    حالت TOK_ASM_c_beqz:
    حالت TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_BIT(offset, 5) | (((offset >> 1) & 3) << 1) | (((offset >> 6) & 3) << 3)) << 2) | ((((offset >> 3) & 3) | NTH_BIT(offset, 8)) << 10));
        بازگشت;
    پیشفرض:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((offset & 0x1f) << 2) | (NTH_BIT(offset, 5) << 12));
        بازگشت;
    }
}

ایستا تهی asm_emit_ci(صحیح token, uint16_t opcode, ثابت Operand *rd, ثابت Operand *imm)
{
    uint32_t immediate;

    اگر (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }

    اگر (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, پوچ));
    }

    immediate = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    انتخاب (token) {
    حالت TOK_ASM_c_addi:
    حالت TOK_ASM_c_addiw:
    حالت TOK_ASM_c_li:
    حالت TOK_ASM_c_slli:
        gen_le16(opcode | ((immediate & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        بازگشت;
    حالت TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_BIT(immediate, 5) << 2 | (((immediate >> 7) & 3) << 3) | NTH_BIT(immediate, 6) << 5 | NTH_BIT(immediate, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 9) << 12));
        بازگشت;
    حالت TOK_ASM_c_lui:
        gen_le16(opcode | (((immediate >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 17) << 12));
        بازگشت;
    حالت TOK_ASM_c_fldsp:
    حالت TOK_ASM_c_ldsp:
        gen_le16(opcode | (((immediate >> 6) & 7) << 2) | (((immediate >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        بازگشت;
    حالت TOK_ASM_c_flwsp:
    حالت TOK_ASM_c_lwsp:
        gen_le16(opcode | (((immediate >> 6) & 3) << 2) | (((immediate >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        بازگشت;
    حالت TOK_ASM_c_nop:
        gen_le16(opcode);
        بازگشت;
    پیشفرض:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
ایستا تهی asm_emit_ciw(صحیح token, uint16_t opcode, ثابت Operand *rd, ثابت Operand *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    اگر (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }

    اگر (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, پوچ));
    }

    dst = rd->reg - 8;

    اگر (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, پوچ));
    }

    nzuimm = imm->e.v;

    اگر (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, پوچ));
    }

    اگر (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, پوچ));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_BIT(nzuimm, 3) | (NTH_BIT(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
ایستا تهی asm_emit_cj(صحیح token, uint16_t opcode, ثابت Operand *imm)
{
    uint32_t offset;

    /* +-2 KiB range */
    اگر (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, پوچ));
    }

    offset = imm->e.v;

    اگر (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, پوچ));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_BIT(offset, 5) << 2) | (((offset >> 1) & 7) << 3) | (NTH_BIT(offset, 7) << 6) | (NTH_BIT(offset, 6) << 7) | (NTH_BIT(offset, 10) << 8) | (((offset >> 8) & 3) << 9) | (NTH_BIT(offset, 4) << 11) | (NTH_BIT(offset, 11) << 12));
}

/* caller: Add funct3 into opcode */
ایستا تهی asm_emit_cl(صحیح token, uint16_t opcode, ثابت Operand *rd, ثابت Operand *rs1, ثابت Operand *imm)
{
    uint32_t offset;
    uint8_t dst, src;

    اگر (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }

    اگر (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, پوچ));
    }

    اگر (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, پوچ));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    اگر (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, پوچ));
    }

    اگر (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, پوچ));
    }

    offset = imm->e.v;

    اگر (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, پوچ));
    }

    اگر (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, پوچ));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    انتخاب (token) {
    /* imm variant 1 */
    حالت TOK_ASM_c_flw:
    حالت TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        بازگشت;
    /* imm variant 2 */
    حالت TOK_ASM_c_fld:
    حالت TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        بازگشت;
    پیشفرض:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
ایستا تهی asm_emit_cr(صحیح token, uint16_t opcode, ثابت Operand *rd, ثابت Operand *rs2)
{
    اگر (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }

    اگر (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, پوچ));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
ایستا تهی asm_emit_cs(صحیح token, uint16_t opcode, ثابت Operand *rs2, ثابت Operand *rs1, ثابت Operand *imm)
{
    uint32_t offset;
    uint8_t base, src;

    اگر (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }

    اگر (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, پوچ));
    }

    اگر (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, پوچ));
    }

    base = rs1->reg - 8;
    src = rs2->reg - 8;

    اگر (base > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, پوچ));
    }

    اگر (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, پوچ));
    }

    offset = imm->e.v;

    اگر (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, پوچ));
    }

    اگر (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, پوچ));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    انتخاب (token) {
    /* imm variant 1 */
    حالت TOK_ASM_c_fsw:
    حالت TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        بازگشت;
    /* imm variant 2 */
    حالت TOK_ASM_c_fsd:
    حالت TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        بازگشت;
    پیشفرض:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
ایستا تهی asm_emit_css(صحیح token, uint16_t opcode, ثابت Operand *rs2, ثابت Operand *imm)
{
    uint32_t offset;

    اگر (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, پوچ));
    }

    اگر (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, پوچ));
    }

    offset = imm->e.v;

    اگر (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, پوچ));
    }

    اگر (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, پوچ));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    انتخاب (token) {
    /* imm variant 1 */
    حالت TOK_ASM_c_fswsp:
    حالت TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 3) << 7) | (((offset >> 2) & 0xf) << 9));
        بازگشت;
    /* imm variant 2 */
    حالت TOK_ASM_c_fsdsp:
    حالت TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 7) << 7) | (((offset >> 3) & 7) << 10));
        بازگشت;
    پیشفرض:
        expect("known instruction");
    }
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
