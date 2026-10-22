/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#ifdef TARGET_DEFS_ONLY

#define CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#define NB_ASM_REGS 64

ST_FUNC ശൂന്യം g(പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം gen_le16(പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം gen_le32(പൂർണ്ണസംഖ്യ c);

/*************************************************************/
#അല്ലെങ്കിൽ
/*************************************************************/
#define USING_GLOBALS
#അന്തര്ഭാവ "tcc.h"

എണ്ണൽ {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#define REG_FLOAT_MASK 0x20
#define REG_IS_FLOAT(register_index) ((register_index) & REG_FLOAT_MASK)
#define REG_മൂല്യം(register_index)    ((register_index) & (REG_FLOAT_MASK-1))
#define C_ENCODE_RS1(register_index) (REG_മൂല്യം(register_index) << 7)
#define C_ENCODE_RS2(register_index) (REG_മൂല്യം(register_index) << 2)
#define ENCODE_RD(register_index)  (REG_മൂല്യം(register_index) << 7)
#define ENCODE_RS1(register_index) (REG_മൂല്യം(register_index) << 15)
#define ENCODE_RS2(register_index) (REG_മൂല്യം(register_index) << 20)
#define NTH_BIT(b, n) ((b >> n) & 1)
#define OP_IM12S (1 << OPT_IM12S)
#define OP_IM32 (1 << OPT_IM32)
#define OP_REG (1 << OPT_REG)

തരനിർവചനം ഘടന Operand {
    uint32_t type;
    സംഘം {
        uint8_t reg;
        uint16_t regset;
        വ്യഞ്ജകം_മൂല്യം e;
    };
} Operand;

സ്ഥിതം സ്ഥിരം Operand zero = { OP_REG, { 0 }};
സ്ഥിതം സ്ഥിരം Operand ra = { OP_REG, { 1 }};
സ്ഥിതം സ്ഥിരം Operand zimm = { OP_IM12S };

സ്ഥിതം ശൂന്യം asm_ദ്വിമാന_opcode(TCCState* s1, പൂർണ്ണസംഖ്യ token);
ST_FUNC ശൂന്യം asm_clobber(uint8_t *clobber_regs, സ്ഥിരം അക്ഷരം *str);
ST_FUNC ശൂന്യം asm_compute_constraints(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands, പൂർണ്ണസംഖ്യ nb_outputs, സ്ഥിരം uint8_t *clobber_regs, പൂർണ്ണസംഖ്യ *pout_reg);
സ്ഥിതം ശൂന്യം asm_emit_a(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *rs2, സ്ഥിരം Operand *rd1, പൂർണ്ണസംഖ്യ aq, പൂർണ്ണസംഖ്യ rl);
സ്ഥിതം ശൂന്യം asm_emit_b(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *rs2, സ്ഥിരം Operand *imm);
സ്ഥിതം ശൂന്യം asm_emit_i(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *rs2);
സ്ഥിതം ശൂന്യം asm_emit_j(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs2);
സ്ഥിതം ശൂന്യം asm_emit_opcode(uint32_t opcode);
സ്ഥിതം ശൂന്യം asm_emit_r(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *rs2);
സ്ഥിതം ശൂന്യം asm_emit_s(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *rs2, സ്ഥിരം Operand *imm);
സ്ഥിതം ശൂന്യം asm_emit_u(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs2);
സ്ഥിതം ശൂന്യം asm_emit_f(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *rs2);
സ്ഥിതം ശൂന്യം asm_emit_fb(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs);
സ്ഥിതം ശൂന്യം asm_emit_fq(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *rs2, സ്ഥിരം Operand *rs3);
ST_FUNC ശൂന്യം asm_gen_code(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands, പൂർണ്ണസംഖ്യ nb_outputs, പൂർണ്ണസംഖ്യ is_output, uint8_t *clobber_regs, പൂർണ്ണസംഖ്യ out_reg);
സ്ഥിതം ശൂന്യം asm_nullary_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token);
ST_FUNC ശൂന്യം asm_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token);
സ്ഥിതം പൂർണ്ണസംഖ്യ asm_parse_csrvar(പൂർണ്ണസംഖ്യ t);
ST_FUNC പൂർണ്ണസംഖ്യ asm_parse_regvar(പൂർണ്ണസംഖ്യ t);
സ്ഥിതം ശൂന്യം asm_ternary_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token);
സ്ഥിതം ശൂന്യം asm_unary_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token);
സ്ഥിതം ശൂന്യം asm_branch_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token, പൂർണ്ണസംഖ്യ argc);
ST_FUNC ശൂന്യം gen_expr32(വ്യഞ്ജകം_മൂല്യം *pe);
സ്ഥിതം ശൂന്യം parse_operand(TCCState *s1, Operand *op);
സ്ഥിതം ശൂന്യം parse_branch_offset_operand(TCCState *s1, Operand *op);
സ്ഥിതം ശൂന്യം parse_operands(TCCState *s1, Operand *ops, പൂർണ്ണസംഖ്യ എണ്ണം_2);
സ്ഥിതം ശൂന്യം parse_mem_access_operands(TCCState *s1, Operand* ops);
ST_FUNC ശൂന്യം subst_asm_operand(CString *add_str, SValue *sv, പൂർണ്ണസംഖ്യ modifier);
/* C extension */
സ്ഥിതം ശൂന്യം asm_emit_ca(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs2);
സ്ഥിതം ശൂന്യം asm_emit_cb(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *imm);
സ്ഥിതം ശൂന്യം asm_emit_ci(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *imm);
സ്ഥിതം ശൂന്യം asm_emit_ciw(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *imm);
സ്ഥിതം ശൂന്യം asm_emit_cj(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *imm);
സ്ഥിതം ശൂന്യം asm_emit_cl(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *imm);
സ്ഥിതം ശൂന്യം asm_emit_cr(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs2);
സ്ഥിതം ശൂന്യം asm_emit_cs(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rs2, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *imm);
സ്ഥിതം ശൂന്യം asm_emit_css(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rs2, സ്ഥിരം Operand *imm);

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

ST_FUNC ശൂന്യം gen_le16 (പൂർണ്ണസംഖ്യ i)
{
    g(i);
    g(i>>8);
}

ST_FUNC ശൂന്യം gen_le32 (പൂർണ്ണസംഖ്യ i)
{
    പൂർണ്ണസംഖ്യ ind1;
    എങ്കിൽ (nocode_wanted)
        തിരികെ;
    ind1 = ind + 4;
    എങ്കിൽ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC ശൂന്യം gen_expr32(വ്യഞ്ജകം_മൂല്യം *pe)
{
    gen_le32(pe->v);
}

സ്ഥിതം ശൂന്യം asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

സ്ഥിതം ശൂന്യം asm_nullary_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    തിരഞ്ഞെടുപ്പ് (token) {
    // Sync instructions

    അവസ്ഥ TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        തിരികെ;

    // System calls

    അവസ്ഥ TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        തിരികെ;
    അവസ്ഥ TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        തിരികെ;

    // Other

    അവസ്ഥ TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        തിരികെ;

    അവസ്ഥ TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        തിരികെ;

    /* Pseudoinstructions */
    അവസ്ഥ TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        തിരികെ;

    /* C extension */
    അവസ്ഥ TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        തിരികെ;

    സ്ഥിരസ്ഥിതി:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
സ്ഥിതം ശൂന്യം parse_operand(TCCState *s1, Operand *op)
{
    വ്യഞ്ജകം_മൂല്യം e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    എങ്കിൽ ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        തിരികെ;
    } അല്ലെങ്കിൽ എങ്കിൽ (tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    } അല്ലെങ്കിൽ എങ്കിൽ ((e.v = asm_parse_csrvar(tok)) != -1) {
        next();
    } അല്ലെങ്കിൽ {
        asm_വ്യഞ്ജകം(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    എങ്കിൽ (!op->e.sym) {
        എങ്കിൽ ((പൂർണ്ണസംഖ്യ) op->e.v >= -0x1000 && (പൂർണ്ണസംഖ്യ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } അല്ലെങ്കിൽ എങ്കിൽ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        എങ്കിൽ (op->e.sym->type.t & VT_STATIC)
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_PCREL_HI20, 0);
        അല്ലെങ്കിൽ
            greloca(cur_text_section, op->e.sym, ind, R_RISCV_GOT_HI20, 0);
        put_extern_sym(&label, cur_text_section, ind, 0);
        greloca(cur_text_section, &label, ind+4, R_RISCV_PCREL_LO12_I, 0);

        op->type = OP_IM12S;
        op->e.v = 0;
    } അല്ലെങ്കിൽ {
        expect("operand");
    }
}

സ്ഥിതം ശൂന്യം parse_branch_offset_operand(TCCState *s1, Operand *op){
    വ്യഞ്ജകം_മൂല്യം e = {0};

    asm_വ്യഞ്ജകം(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    എങ്കിൽ (!op->e.sym) {
        എങ്കിൽ ((പൂർണ്ണസംഖ്യ) op->e.v >= -0x1000 && (പൂർണ്ണസംഖ്യ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } അല്ലെങ്കിൽ എങ്കിൽ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } അല്ലെങ്കിൽ {
        expect("operand");
    }
}

സ്ഥിതം ശൂന്യം parse_jump_offset_operand(TCCState *s1, Operand *op){
    വ്യഞ്ജകം_മൂല്യം e = {0};

    asm_വ്യഞ്ജകം(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    എങ്കിൽ (!op->e.sym) {
        എങ്കിൽ ((പൂർണ്ണസംഖ്യ) op->e.v >= -0x1000 && (പൂർണ്ണസംഖ്യ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } അല്ലെങ്കിൽ എങ്കിൽ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_text_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } അല്ലെങ്കിൽ {
        expect("operand");
    }
}

സ്ഥിതം ശൂന്യം parse_operands(TCCState *s1, Operand* ops, പൂർണ്ണസംഖ്യ എണ്ണം_2){
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 0; i < എണ്ണം_2; i++) {
        എങ്കിൽ ( i != 0 )
            skip(',');
        parse_operand(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
സ്ഥിതം ശൂന്യം parse_mem_access_operands(TCCState *s1, Operand* ops){

    Operand op;

    parse_operand(s1, &ops[0]);
    skip(',');
    എങ്കിൽ ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } അല്ലെങ്കിൽ {
        parse_operand(s1, &ops[2]);
        എങ്കിൽ ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } അല്ലെങ്കിൽ {
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
സ്ഥിതം ശൂന്യം asm_jal_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token){
    Operand ops[2];

    എങ്കിൽ (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } അല്ലെങ്കിൽ എങ്കിൽ (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } അല്ലെങ്കിൽ {
        // jal reg, offset
        parse_operand(s1, &ops[0]);
        എങ്കിൽ ( tok == ',') next(); അല്ലെങ്കിൽ expect("','");
    }
    parse_jump_offset_operand(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
സ്ഥിതം ശൂന്യം asm_jalr_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token){
    Operand ops[3];
    Operand op;

    parse_operand(s1, &ops[0]);
    എങ്കിൽ ( tok == ',')
        next();
    അല്ലെങ്കിൽ {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        തിരികെ;
    }

    എങ്കിൽ ( tok == '(') {
        /* `X, (Y)` case*/
        next();
        parse_operand(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } അല്ലെങ്കിൽ {
        parse_operand(s1, &ops[2]);
        എങ്കിൽ ( tok == '('){
            /* `X, imm(Y)` case*/
            next();
            parse_operand(s1, &ops[1]);
            skip(')');
        } അല്ലെങ്കിൽ {
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


സ്ഥിതം ശൂന്യം asm_unary_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    Operand op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    തിരഞ്ഞെടുപ്പ് (token) {
    /* pseudoinstructions */
    അവസ്ഥ TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        തിരികെ;
    അവസ്ഥ TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        തിരികെ;
    അവസ്ഥ TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        തിരികെ;

    അവസ്ഥ TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        തിരികെ;
    അവസ്ഥ TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        തിരികെ;
    അവസ്ഥ TOK_ASM_tail:
        /* auipc x6, 0 */
        greloca(cur_text_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        തിരികെ;

    /* C extension */
    അവസ്ഥ TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        തിരികെ;

    സ്ഥിരസ്ഥിതി:
        expect("unary instruction");
    }
}

സ്ഥിതം ശൂന്യം asm_emit_u(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand* rd, സ്ഥിരം Operand* rs2)
{
    എങ്കിൽ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ശൂന്യ));
    } അല്ലെങ്കിൽ എങ്കിൽ (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, ശൂന്യ));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

സ്ഥിതം പൂർണ്ണസംഖ്യ parse_fence_operand(){
    പൂർണ്ണസംഖ്യ t = tok;
    എങ്കിൽ ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    next();
    തിരികെ t - (TOK_ASM_w_fence - 1);
}

സ്ഥിതം ശൂന്യം asm_fence_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    പൂർണ്ണസംഖ്യ succ = 0xF, pred = 0xF;
    എങ്കിൽ (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_operand();
        എങ്കിൽ ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, ശൂന്യ));
        }
        skip(',');
        succ = parse_fence_operand();
        എങ്കിൽ ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, ശൂന്യ));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

സ്ഥിതം ശൂന്യം asm_ദ്വിമാന_opcode(TCCState* s1, പൂർണ്ണസംഖ്യ token)
{
    Operand imm = { OP_IM12S };
    Operand ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    തിരഞ്ഞെടുപ്പ് (token) {
    അവസ്ഥ TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        തിരികെ;

    /* C extension */
    അവസ്ഥ TOK_ASM_c_add:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        തിരികെ;

    അവസ്ഥ TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        തിരികെ;

    അവസ്ഥ TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        തിരികെ;

#define CA (1 | (3 << 10) | (4 << 13))
    അവസ്ഥ TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        തിരികെ;
#undef CA

    അവസ്ഥ TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        തിരികെ;

    അവസ്ഥ TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        തിരികെ;

    /* F/D extension */
    അവസ്ഥ TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        തിരികെ;

    /* pseudoinstructions */
    /* rd, sym */
    അവസ്ഥ TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_li:
        എങ്കിൽ(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, ശൂന്യ));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        എങ്കിൽ(lo < 0){
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
        തിരികെ;
    അവസ്ഥ TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        തിരികെ;
    അവസ്ഥ TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        തിരികെ;
    അവസ്ഥ TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        തിരികെ;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    അവസ്ഥ TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_text_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        തിരികെ;
    അവസ്ഥ TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        തിരികെ;
    അവസ്ഥ TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        തിരികെ;
    അവസ്ഥ TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        തിരികെ;

    അവസ്ഥ TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        തിരികെ;

    /* CSR pseudo-instructions */
    അവസ്ഥ TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        തിരികെ;
    സ്ഥിരസ്ഥിതി:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
സ്ഥിതം ശൂന്യം asm_emit_r(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand* rd, സ്ഥിരം Operand* rs1, സ്ഥിരം Operand* rs2)
{
    എങ്കിൽ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, ശൂന്യ));
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
സ്ഥിതം ശൂന്യം asm_emit_f(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand* rd, സ്ഥിരം Operand* rs1, സ്ഥിരം Operand* rs2)
{
    എങ്കിൽ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ശൂന്യ));
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
സ്ഥിതം ശൂന്യം asm_emit_fb(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand* rd, സ്ഥിരം Operand* rs)
{
    എങ്കിൽ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, ശൂന്യ));
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
സ്ഥിതം ശൂന്യം asm_emit_fq(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand* rd, സ്ഥിരം Operand* rs1, സ്ഥിരം Operand* rs2, സ്ഥിരം Operand* rs3)
{
    എങ്കിൽ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, ശൂന്യ));
    }
    /* F-type instruction:
	     31...27 rs3
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (REG_മൂല്യം(rs3->reg) << 27));
}

/* caller: Add funct3 into opcode */
സ്ഥിതം ശൂന്യം asm_emit_i(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand* rd, സ്ഥിരം Operand* rs1, സ്ഥിരം Operand* rs2)
{
    എങ്കിൽ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ശൂന്യ));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

സ്ഥിതം ശൂന്യം asm_emit_j(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand* rd, സ്ഥിരം Operand* rs2)
{
    uint32_t imm;

    എങ്കിൽ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ശൂന്യ));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    എങ്കിൽ ((പൂർണ്ണസംഖ്യ)imm > (1 << 20) -1 || (പൂർണ്ണസംഖ്യ)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, ശൂന്യ));
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

സ്ഥിതം ശൂന്യം asm_mem_access_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{

    Operand ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    എങ്കിൽ (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    തിരഞ്ഞെടുപ്പ് (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    അവസ്ഥ TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    അവസ്ഥ TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         തിരികെ;
    }
}

സ്ഥിതം ശൂന്യം asm_branch_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token, പൂർണ്ണസംഖ്യ argc)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_offset_operand(s1, &ops[argc-1]);

    തിരഞ്ഞെടുപ്പ്(token){
    /* branch (RS1, RS2, IMM); B-format */
    അവസ്ഥ TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    /* related pseudoinstructions */
    അവസ്ഥ TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        തിരികെ;
    /* shorter pseudoinstructions */
    അവസ്ഥ TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        തിരികെ;
    }
}

സ്ഥിതം ശൂന്യം asm_ternary_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[3];
    parse_operands(s1, &ops[0], 3);

    തിരഞ്ഞെടുപ്പ് (token) {
    അവസ്ഥ TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        തിരികെ;
    അവസ്ഥ TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        തിരികെ;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    അവസ്ഥ TOK_ASM_add:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         തിരികെ;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    അവസ്ഥ TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    അവസ്ഥ TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;
    അവസ്ഥ TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         തിരികെ;

    /* M extension */
    അവസ്ഥ TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        തിരികെ;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    അവസ്ഥ TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        തിരികെ;
    അവസ്ഥ TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        തിരികെ;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    അവസ്ഥ TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        തിരികെ;

    /* F/D extension */
    അവസ്ഥ TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        തിരികെ;

    /* F/D comparison: produce integer result, encode manually */
    അവസ്ഥ TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        തിരികെ;
    അവസ്ഥ TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        തിരികെ;

    സ്ഥിരസ്ഥിതി:
        expect("ternary instruction");
    }
}

സ്ഥിതം ശൂന്യം asm_quaternary_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[4];
    parse_operands(s1, &ops[0], 4);

    തിരഞ്ഞെടുപ്പ് (token) {
    അവസ്ഥ TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        തിരികെ;

    സ്ഥിരസ്ഥിതി:
        expect("quaternary instruction");
    }
}

സ്ഥിതം ശൂന്യം asm_atomic_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[3];

    parse_operand(s1, &ops[0]);
    skip(',');

    എങ്കിൽ ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } അല്ലെങ്കിൽ {
        parse_operand(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_operand(s1, &ops[2]);
    skip(')');

    തിരഞ്ഞെടുപ്പ്(token){
        അവസ്ഥ TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            നിർത്തുക;

        അവസ്ഥ TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            നിർത്തുക;
        അവസ്ഥ TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            നിർത്തുക;

        /* AMO instructions (base, aq=0 rl=0) */
        അവസ്ഥ TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); നിർത്തുക;

        /* AMO aq/rl variants */
        അവസ്ഥ TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;

        അവസ്ഥ TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); നിർത്തുക;
        അവസ്ഥ TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); നിർത്തുക;
    }
}

/* caller: Add funct3 and func5 to opcode */
സ്ഥിതം ശൂന്യം asm_emit_a(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rd1, സ്ഥിരം Operand *rs2, സ്ഥിരം Operand *rs1, പൂർണ്ണസംഖ്യ aq, പൂർണ്ണസംഖ്യ rl)
{
    എങ്കിൽ (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, ശൂന്യ));
    എങ്കിൽ (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ശൂന്യ));
    എങ്കിൽ (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, ശൂന്യ));
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
സ്ഥിതം ശൂന്യം asm_emit_s(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand* rs1, സ്ഥിരം Operand* rs2, സ്ഥിരം Operand* imm)
{
    എങ്കിൽ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, ശൂന്യ));
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

സ്ഥിതം ശൂന്യം asm_emit_b(പൂർണ്ണസംഖ്യ token, uint32_t opcode, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *rs2, സ്ഥിരം Operand *imm)
{
    uint32_t offset;

    എങ്കിൽ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }
    എങ്കിൽ (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        പൂർണ്ണസംഖ്യ b_ofs = ind;
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
        തിരികെ;
    }
    എങ്കിൽ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ശൂന്യ));
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
സ്ഥിതം പൂർണ്ണസംഖ്യ asm_fcvt_rm(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ rm = 7; /* dynamic */
    എങ്കിൽ (tok == ',') {
        next();
        തിരഞ്ഞെടുപ്പ് (tok) {
            അവസ്ഥ TOK_ASM_rne: rm = 0; next(); നിർത്തുക;
            അവസ്ഥ TOK_ASM_rtz: rm = 1; next(); നിർത്തുക;
            അവസ്ഥ TOK_ASM_rdn: rm = 2; next(); നിർത്തുക;
            അവസ്ഥ TOK_ASM_rup: rm = 3; next(); നിർത്തുക;
            അവസ്ഥ TOK_ASM_rmm: rm = 4; next(); നിർത്തുക;
            സ്ഥിരസ്ഥിതി: expect("rounding mode"); നിർത്തുക;
        }
    }
    തിരികെ rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
സ്ഥിതം ശൂന്യം asm_fcvt_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    Operand ops[2];
    പൂർണ്ണസംഖ്യ rm;
    uint32_t enc = 0;

    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);

    തിരഞ്ഞെടുപ്പ് (token) {
        അവസ്ഥ TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); നിർത്തുക;
        അവസ്ഥ TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); നിർത്തുക;
        സ്ഥിരസ്ഥിതി: expect("fcvt/fclass instruction"); തിരികെ;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC ശൂന്യം asm_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ token)
{
    തിരഞ്ഞെടുപ്പ് (token) {
    അവസ്ഥ TOK_ASM_ebreak:
    അവസ്ഥ TOK_ASM_ecall:
    അവസ്ഥ TOK_ASM_fence_i:
    അവസ്ഥ TOK_ASM_hrts:
    അവസ്ഥ TOK_ASM_mrth:
    അവസ്ഥ TOK_ASM_mrts:
    അവസ്ഥ TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_rdcycle:
    അവസ്ഥ TOK_ASM_rdcycleh:
    അവസ്ഥ TOK_ASM_rdtime:
    അവസ്ഥ TOK_ASM_rdtimeh:
    അവസ്ഥ TOK_ASM_rdinstret:
    അവസ്ഥ TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_lui:
    അവസ്ഥ TOK_ASM_auipc:
    അവസ്ഥ TOK_ASM_fsqrt_s:
    അവസ്ഥ TOK_ASM_fsqrt_d:
        asm_ദ്വിമാന_opcode(s1, token);
        തിരികെ;

    /* fcvt/fclass — separate handler for optional rounding operand */
    അവസ്ഥ TOK_ASM_fcvt_w_s:
    അവസ്ഥ TOK_ASM_fcvt_wu_s:
    അവസ്ഥ TOK_ASM_fcvt_l_s:
    അവസ്ഥ TOK_ASM_fcvt_lu_s:
    അവസ്ഥ TOK_ASM_fcvt_s_w:
    അവസ്ഥ TOK_ASM_fcvt_s_wu:
    അവസ്ഥ TOK_ASM_fcvt_s_l:
    അവസ്ഥ TOK_ASM_fcvt_s_lu:
    അവസ്ഥ TOK_ASM_fcvt_w_d:
    അവസ്ഥ TOK_ASM_fcvt_wu_d:
    അവസ്ഥ TOK_ASM_fcvt_l_d:
    അവസ്ഥ TOK_ASM_fcvt_lu_d:
    അവസ്ഥ TOK_ASM_fcvt_d_w:
    അവസ്ഥ TOK_ASM_fcvt_d_wu:
    അവസ്ഥ TOK_ASM_fcvt_d_l:
    അവസ്ഥ TOK_ASM_fcvt_d_lu:
    അവസ്ഥ TOK_ASM_fcvt_s_d:
    അവസ്ഥ TOK_ASM_fcvt_d_s:
    അവസ്ഥ TOK_ASM_fclass_s:
    അവസ്ഥ TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_lb:
    അവസ്ഥ TOK_ASM_lh:
    അവസ്ഥ TOK_ASM_lw:
    അവസ്ഥ TOK_ASM_ld:
    അവസ്ഥ TOK_ASM_fld:
    അവസ്ഥ TOK_ASM_lbu:
    അവസ്ഥ TOK_ASM_lhu:
    അവസ്ഥ TOK_ASM_lwu:
    അവസ്ഥ TOK_ASM_sb:
    അവസ്ഥ TOK_ASM_sh:
    അവസ്ഥ TOK_ASM_sw:
    അവസ്ഥ TOK_ASM_sd:
    അവസ്ഥ TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        നിർത്തുക;

    അവസ്ഥ TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        നിർത്തുക;
    അവസ്ഥ TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        തിരികെ;
    അവസ്ഥ TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        നിർത്തുക;

    അവസ്ഥ TOK_ASM_add:
    അവസ്ഥ TOK_ASM_addi:
    അവസ്ഥ TOK_ASM_addiw:
    അവസ്ഥ TOK_ASM_addw:
    അവസ്ഥ TOK_ASM_and:
    അവസ്ഥ TOK_ASM_andi:
    അവസ്ഥ TOK_ASM_or:
    അവസ്ഥ TOK_ASM_ori:
    അവസ്ഥ TOK_ASM_sll:
    അവസ്ഥ TOK_ASM_slli:
    അവസ്ഥ TOK_ASM_slliw:
    അവസ്ഥ TOK_ASM_sllw:
    അവസ്ഥ TOK_ASM_slt:
    അവസ്ഥ TOK_ASM_slti:
    അവസ്ഥ TOK_ASM_sltiu:
    അവസ്ഥ TOK_ASM_sltu:
    അവസ്ഥ TOK_ASM_sra:
    അവസ്ഥ TOK_ASM_srai:
    അവസ്ഥ TOK_ASM_sraiw:
    അവസ്ഥ TOK_ASM_sraw:
    അവസ്ഥ TOK_ASM_srl:
    അവസ്ഥ TOK_ASM_srli:
    അവസ്ഥ TOK_ASM_srliw:
    അവസ്ഥ TOK_ASM_srlw:
    അവസ്ഥ TOK_ASM_sub:
    അവസ്ഥ TOK_ASM_subw:
    അവസ്ഥ TOK_ASM_xor:
    അവസ്ഥ TOK_ASM_xori:
    /* M extension */
    അവസ്ഥ TOK_ASM_div:
    അവസ്ഥ TOK_ASM_divu:
    അവസ്ഥ TOK_ASM_divuw:
    അവസ്ഥ TOK_ASM_divw:
    അവസ്ഥ TOK_ASM_mul:
    അവസ്ഥ TOK_ASM_mulh:
    അവസ്ഥ TOK_ASM_mulhsu:
    അവസ്ഥ TOK_ASM_mulhu:
    അവസ്ഥ TOK_ASM_mulw:
    അവസ്ഥ TOK_ASM_rem:
    അവസ്ഥ TOK_ASM_remu:
    അവസ്ഥ TOK_ASM_remuw:
    അവസ്ഥ TOK_ASM_remw:
    /* Zicsr extension */
    അവസ്ഥ TOK_ASM_csrrc:
    അവസ്ഥ TOK_ASM_csrrci:
    അവസ്ഥ TOK_ASM_csrrs:
    അവസ്ഥ TOK_ASM_csrrsi:
    അവസ്ഥ TOK_ASM_csrrw:
    അവസ്ഥ TOK_ASM_csrrwi:
    /* F/D extension */
    അവസ്ഥ TOK_ASM_fadd_s:
    അവസ്ഥ TOK_ASM_fadd_d:
    അവസ്ഥ TOK_ASM_fsub_s:
    അവസ്ഥ TOK_ASM_fsub_d:
    അവസ്ഥ TOK_ASM_fmul_s:
    അവസ്ഥ TOK_ASM_fmul_d:
    അവസ്ഥ TOK_ASM_fdiv_s:
    അവസ്ഥ TOK_ASM_fdiv_d:
    അവസ്ഥ TOK_ASM_fsgnj_d:
    അവസ്ഥ TOK_ASM_fsgnj_s:
    അവസ്ഥ TOK_ASM_fmax_s:
    അവസ്ഥ TOK_ASM_fmax_d:
    അവസ്ഥ TOK_ASM_fmin_s:
    അവസ്ഥ TOK_ASM_fmin_d:
    അവസ്ഥ TOK_ASM_feq_s:
    അവസ്ഥ TOK_ASM_feq_d:
    അവസ്ഥ TOK_ASM_flt_s:
    അവസ്ഥ TOK_ASM_flt_d:
    അവസ്ഥ TOK_ASM_fle_s:
    അവസ്ഥ TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        തിരികെ;
    അവസ്ഥ TOK_ASM_fmadd_d:
    അവസ്ഥ TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        തിരികെ;

    /* Branches */
    അവസ്ഥ TOK_ASM_beq:
    അവസ്ഥ TOK_ASM_bge:
    അവസ്ഥ TOK_ASM_bgeu:
    അവസ്ഥ TOK_ASM_blt:
    അവസ്ഥ TOK_ASM_bltu:
    അവസ്ഥ TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        നിർത്തുക;

    /* C extension */
    അവസ്ഥ TOK_ASM_c_ebreak:
    അവസ്ഥ TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_c_j:
    അവസ്ഥ TOK_ASM_c_jal:
    അവസ്ഥ TOK_ASM_c_jalr:
    അവസ്ഥ TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_c_add:
    അവസ്ഥ TOK_ASM_c_addi16sp:
    അവസ്ഥ TOK_ASM_c_addi4spn:
    അവസ്ഥ TOK_ASM_c_addi:
    അവസ്ഥ TOK_ASM_c_addiw:
    അവസ്ഥ TOK_ASM_c_addw:
    അവസ്ഥ TOK_ASM_c_and:
    അവസ്ഥ TOK_ASM_c_andi:
    അവസ്ഥ TOK_ASM_c_beqz:
    അവസ്ഥ TOK_ASM_c_bnez:
    അവസ്ഥ TOK_ASM_c_fldsp:
    അവസ്ഥ TOK_ASM_c_flwsp:
    അവസ്ഥ TOK_ASM_c_fsdsp:
    അവസ്ഥ TOK_ASM_c_fswsp:
    അവസ്ഥ TOK_ASM_c_ldsp:
    അവസ്ഥ TOK_ASM_c_li:
    അവസ്ഥ TOK_ASM_c_lui:
    അവസ്ഥ TOK_ASM_c_lwsp:
    അവസ്ഥ TOK_ASM_c_mv:
    അവസ്ഥ TOK_ASM_c_or:
    അവസ്ഥ TOK_ASM_c_sdsp:
    അവസ്ഥ TOK_ASM_c_slli:
    അവസ്ഥ TOK_ASM_c_srai:
    അവസ്ഥ TOK_ASM_c_srli:
    അവസ്ഥ TOK_ASM_c_sub:
    അവസ്ഥ TOK_ASM_c_subw:
    അവസ്ഥ TOK_ASM_c_swsp:
    അവസ്ഥ TOK_ASM_c_xor:
        asm_ദ്വിമാന_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_c_fld:
    അവസ്ഥ TOK_ASM_c_flw:
    അവസ്ഥ TOK_ASM_c_fsd:
    അവസ്ഥ TOK_ASM_c_fsw:
    അവസ്ഥ TOK_ASM_c_ld:
    അവസ്ഥ TOK_ASM_c_lw:
    അവസ്ഥ TOK_ASM_c_sd:
    അവസ്ഥ TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        തിരികെ;

    /* pseudoinstructions */
    അവസ്ഥ TOK_ASM_nop:
    അവസ്ഥ TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_jr:
    അവസ്ഥ TOK_ASM_call:
    അവസ്ഥ TOK_ASM_tail:
    അവസ്ഥ TOK_ASM_frflags:
    അവസ്ഥ TOK_ASM_frrm:
    അവസ്ഥ TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_la:
    അവസ്ഥ TOK_ASM_lla:
    അവസ്ഥ TOK_ASM_li:
    അവസ്ഥ TOK_ASM_jump:
    അവസ്ഥ TOK_ASM_seqz:
    അവസ്ഥ TOK_ASM_snez:
    അവസ്ഥ TOK_ASM_sltz:
    അവസ്ഥ TOK_ASM_sgtz:
    അവസ്ഥ TOK_ASM_mv:
    അവസ്ഥ TOK_ASM_not:
    അവസ്ഥ TOK_ASM_neg:
    അവസ്ഥ TOK_ASM_negw:
    അവസ്ഥ TOK_ASM_sext_w:
    അവസ്ഥ TOK_ASM_fabs_s:
    അവസ്ഥ TOK_ASM_fabs_d:
    അവസ്ഥ TOK_ASM_fmv_s:
    അവസ്ഥ TOK_ASM_fmv_d:
    അവസ്ഥ TOK_ASM_fneg_s:
    അവസ്ഥ TOK_ASM_fneg_d:
    അവസ്ഥ TOK_ASM_csrc:
    അവസ്ഥ TOK_ASM_csrs:
    അവസ്ഥ TOK_ASM_csrr:
    അവസ്ഥ TOK_ASM_csrw:
    അവസ്ഥ TOK_ASM_csrwi:
    അവസ്ഥ TOK_ASM_csrsi:
    അവസ്ഥ TOK_ASM_csrci:
    അവസ്ഥ TOK_ASM_fsrm:
    അവസ്ഥ TOK_ASM_fscsr:
        asm_ദ്വിമാന_opcode(s1, token);
        തിരികെ;

    അവസ്ഥ TOK_ASM_bnez:
    അവസ്ഥ TOK_ASM_beqz:
    അവസ്ഥ TOK_ASM_blez:
    അവസ്ഥ TOK_ASM_bgez:
    അവസ്ഥ TOK_ASM_bltz:
    അവസ്ഥ TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        തിരികെ;

    അവസ്ഥ TOK_ASM_bgt:
    അവസ്ഥ TOK_ASM_bgtu:
    അവസ്ഥ TOK_ASM_ble:
    അവസ്ഥ TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        തിരികെ;

    /* Atomic operations */
    അവസ്ഥ TOK_ASM_lr_w:
    അവസ്ഥ TOK_ASM_lr_w_aq:
    അവസ്ഥ TOK_ASM_lr_w_rl:
    അവസ്ഥ TOK_ASM_lr_w_aqrl:
    അവസ്ഥ TOK_ASM_lr_d:
    അവസ്ഥ TOK_ASM_lr_d_aq:
    അവസ്ഥ TOK_ASM_lr_d_rl:
    അവസ്ഥ TOK_ASM_lr_d_aqrl:
    അവസ്ഥ TOK_ASM_sc_w:
    അവസ്ഥ TOK_ASM_sc_w_aq:
    അവസ്ഥ TOK_ASM_sc_w_rl:
    അവസ്ഥ TOK_ASM_sc_w_aqrl:
    അവസ്ഥ TOK_ASM_sc_d:
    അവസ്ഥ TOK_ASM_sc_d_aq:
    അവസ്ഥ TOK_ASM_sc_d_rl:
    അവസ്ഥ TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    അവസ്ഥ TOK_ASM_amoadd_w:
    അവസ്ഥ TOK_ASM_amoadd_d:
    അവസ്ഥ TOK_ASM_amoswap_w:
    അവസ്ഥ TOK_ASM_amoswap_d:
    അവസ്ഥ TOK_ASM_amoand_w:
    അവസ്ഥ TOK_ASM_amoand_d:
    അവസ്ഥ TOK_ASM_amoor_w:
    അവസ്ഥ TOK_ASM_amoor_d:
    അവസ്ഥ TOK_ASM_amoxor_w:
    അവസ്ഥ TOK_ASM_amoxor_d:
    അവസ്ഥ TOK_ASM_amomax_w:
    അവസ്ഥ TOK_ASM_amomax_d:
    അവസ്ഥ TOK_ASM_amomaxu_w:
    അവസ്ഥ TOK_ASM_amomaxu_d:
    അവസ്ഥ TOK_ASM_amomin_w:
    അവസ്ഥ TOK_ASM_amomin_d:
    അവസ്ഥ TOK_ASM_amominu_w:
    അവസ്ഥ TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    അവസ്ഥ TOK_ASM_amoadd_w_aq:
    അവസ്ഥ TOK_ASM_amoadd_w_rl:
    അവസ്ഥ TOK_ASM_amoadd_w_aqrl:
    അവസ്ഥ TOK_ASM_amoadd_d_aq:
    അവസ്ഥ TOK_ASM_amoadd_d_rl:
    അവസ്ഥ TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    അവസ്ഥ TOK_ASM_amoswap_w_aq:
    അവസ്ഥ TOK_ASM_amoswap_w_rl:
    അവസ്ഥ TOK_ASM_amoswap_w_aqrl:
    അവസ്ഥ TOK_ASM_amoswap_d_aq:
    അവസ്ഥ TOK_ASM_amoswap_d_rl:
    അവസ്ഥ TOK_ASM_amoswap_d_aqrl:
    അവസ്ഥ TOK_ASM_amoand_w_aq:
    അവസ്ഥ TOK_ASM_amoand_w_rl:
    അവസ്ഥ TOK_ASM_amoand_w_aqrl:
    അവസ്ഥ TOK_ASM_amoand_d_aq:
    അവസ്ഥ TOK_ASM_amoand_d_rl:
    അവസ്ഥ TOK_ASM_amoand_d_aqrl:
    അവസ്ഥ TOK_ASM_amoor_w_aq:
    അവസ്ഥ TOK_ASM_amoor_w_rl:
    അവസ്ഥ TOK_ASM_amoor_w_aqrl:
    അവസ്ഥ TOK_ASM_amoor_d_aq:
    അവസ്ഥ TOK_ASM_amoor_d_rl:
    അവസ്ഥ TOK_ASM_amoor_d_aqrl:
    അവസ്ഥ TOK_ASM_amoxor_w_aq:
    അവസ്ഥ TOK_ASM_amoxor_w_rl:
    അവസ്ഥ TOK_ASM_amoxor_w_aqrl:
    അവസ്ഥ TOK_ASM_amoxor_d_aq:
    അവസ്ഥ TOK_ASM_amoxor_d_rl:
    അവസ്ഥ TOK_ASM_amoxor_d_aqrl:
    അവസ്ഥ TOK_ASM_amomax_w_aq:
    അവസ്ഥ TOK_ASM_amomax_w_rl:
    അവസ്ഥ TOK_ASM_amomax_w_aqrl:
    അവസ്ഥ TOK_ASM_amomax_d_aq:
    അവസ്ഥ TOK_ASM_amomax_d_rl:
    അവസ്ഥ TOK_ASM_amomax_d_aqrl:
    അവസ്ഥ TOK_ASM_amomaxu_w_aq:
    അവസ്ഥ TOK_ASM_amomaxu_w_rl:
    അവസ്ഥ TOK_ASM_amomaxu_w_aqrl:
    അവസ്ഥ TOK_ASM_amomaxu_d_aq:
    അവസ്ഥ TOK_ASM_amomaxu_d_rl:
    അവസ്ഥ TOK_ASM_amomaxu_d_aqrl:
    അവസ്ഥ TOK_ASM_amomin_w_aq:
    അവസ്ഥ TOK_ASM_amomin_w_rl:
    അവസ്ഥ TOK_ASM_amomin_w_aqrl:
    അവസ്ഥ TOK_ASM_amomin_d_aq:
    അവസ്ഥ TOK_ASM_amomin_d_rl:
    അവസ്ഥ TOK_ASM_amomin_d_aqrl:
    അവസ്ഥ TOK_ASM_amominu_w_aq:
    അവസ്ഥ TOK_ASM_amominu_w_rl:
    അവസ്ഥ TOK_ASM_amominu_w_aqrl:
    അവസ്ഥ TOK_ASM_amominu_d_aq:
    അവസ്ഥ TOK_ASM_amominu_d_rl:
    അവസ്ഥ TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        നിർത്തുക;

    സ്ഥിരസ്ഥിതി:
        expect("known instruction");
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ asm_parse_csrvar(പൂർണ്ണസംഖ്യ t)
{
    തിരഞ്ഞെടുപ്പ് (t) {
    അവസ്ഥ TOK_ASM_cycle:
        തിരികെ 0xc00;
    അവസ്ഥ TOK_ASM_fcsr:
        തിരികെ 3;
    അവസ്ഥ TOK_ASM_fflags:
        തിരികെ 1;
    അവസ്ഥ TOK_ASM_frm:
        തിരികെ 2;
    അവസ്ഥ TOK_ASM_instret:
        തിരികെ 0xc02;
    അവസ്ഥ TOK_ASM_time:
        തിരികെ 0xc01;
    അവസ്ഥ TOK_ASM_cycleh:
        തിരികെ 0xc80;
    അവസ്ഥ TOK_ASM_instreth:
        തിരികെ 0xc82;
    അവസ്ഥ TOK_ASM_timeh:
        തിരികെ 0xc81;
    സ്ഥിരസ്ഥിതി:
        തിരികെ -1;
    }
}

ST_FUNC ശൂന്യം subst_asm_operand(CString *add_str, SValue *sv, പൂർണ്ണസംഖ്യ modifier)
{
    പൂർണ്ണസംഖ്യ r, reg, val;

    r = sv->r;
    എങ്കിൽ ((r & VT_VALMASK) == VT_CONST) {
        എങ്കിൽ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        എങ്കിൽ (r & VT_SYM) {
            സ്ഥിരം അക്ഷരം *name = get_tok_str(sv->sym->v, ശൂന്യ);
            എങ്കിൽ (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            എങ്കിൽ (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            എങ്കിൽ ((uint32_t) sv->c.i == 0)
                പോകുക no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        എങ്കിൽ (modifier == 'n')
            val = -val;
        എങ്കിൽ (modifier == 'z' && val == 0) {
            cstr_cat(add_str, "zero", -1);
        } അല്ലെങ്കിൽ {
            cstr_printf(add_str, "%d", val);
        }
      no_offset:;
    } അല്ലെങ്കിൽ എങ്കിൽ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "%d", (പൂർണ്ണസംഖ്യ) sv->c.i);
    } അല്ലെങ്കിൽ എങ്കിൽ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        എങ്കിൽ (reg >= VT_CONST)
            tcc_internal_error("");
        എങ്കിൽ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_മൂല്യം(reg);
        } അല്ലെങ്കിൽ {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, ശൂന്യ), -1);
    } അല്ലെങ്കിൽ {
        /* register case */
        reg = r & VT_VALMASK;
        എങ്കിൽ (reg >= VT_CONST)
            tcc_internal_error("");
        എങ്കിൽ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_മൂല്യം(reg);
        } അല്ലെങ്കിൽ {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(add_str, get_tok_str(reg, ശൂന്യ), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_ireg(പൂർണ്ണസംഖ്യ r){
    തിരികെ REG_മൂല്യം(r) - 10;
}
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_freg(പൂർണ്ണസംഖ്യ r){
    തിരികെ REG_മൂല്യം(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ശൂന്യം asm_gen_code(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands,
                         പൂർണ്ണസംഖ്യ nb_outputs, പൂർണ്ണസംഖ്യ is_output,
                         uint8_t *clobber_regs,
                         പൂർണ്ണസംഖ്യ out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    പൂർണ്ണസംഖ്യ i, reg;

    സ്ഥിതം സ്ഥിരം uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, വലുപ്പം(regs_allocated));
    വേണ്ടി(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        എങ്കിൽ (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    എങ്കിൽ(!is_output) {
        /* generate reg save code */
        വേണ്ടി(i = 0; i < വലുപ്പം(reg_saved)/വലുപ്പം(reg_saved[0]); i++) {
            reg = reg_saved[i];
            എങ്കിൽ (regs_allocated[reg]) {
                /*തള്ളുക*/
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (unsigned)-8 << 20);
                എങ്കിൽ (REG_IS_FLOAT(reg)){
                    /* fsd reg, offset(sp) */
                    gen_le32( 0x27 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                } അല്ലെങ്കിൽ {
                    /* sd reg, offset(sp) */
                    gen_le32((0x8 << 2) | 3 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                }
            }
        }

        /* generate load code */
        വേണ്ടി(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            എങ്കിൽ (op->reg >= 0) {
                എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(tcc_ireg(op->reg), &sv);
                } അല്ലെങ്കിൽ എങ്കിൽ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    എങ്കിൽ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        load(tcc_freg(op->reg), op->vt);
                    } അല്ലെങ്കിൽ {
                        load(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register;
                       the load/store above already handles it correctly */
                }
            }
        }
    } അല്ലെങ്കിൽ {
        /* generate save code */
        വേണ്ടി(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            എങ്കിൽ (op->reg >= 0) {
                എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    എങ്കിൽ (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(tcc_ireg(out_reg), &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(tcc_ireg(op->reg), &sv);
                    }
                } അല്ലെങ്കിൽ {
                    എങ്കിൽ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        store(tcc_freg(op->reg), op->vt);
                    } അല്ലെങ്കിൽ {
                        store(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register */
                }
            }
        }
        /* generate reg restore code for floating point registers */
        വേണ്ടി(i = വലുപ്പം(reg_saved)/വലുപ്പം(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            എങ്കിൽ (regs_allocated[reg]) {
                /*എടുക്കുക*/
                എങ്കിൽ (REG_IS_FLOAT(reg)){
                    /* fld reg, offset(sp) */
                    gen_le32(7 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                } അല്ലെങ്കിൽ {
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
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ constraint_priority(സ്ഥിരം അക്ഷരം *str)
{
    // TODO: How is this chosen??
    പൂർണ്ണസംഖ്യ priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    വേണ്ടി(;;) {
        c = *str;
        എങ്കിൽ (c == '\0')
            നിർത്തുക;
        str++;
        തിരഞ്ഞെടുപ്പ്(c) {
        അവസ്ഥ 'A': // address that is held in a general-purpose register.
        അവസ്ഥ 'S': // constraint that matches an absolute symbolic address.
        അവസ്ഥ 'f': // register [float]
        അവസ്ഥ 'r': // register [general]
        അവസ്ഥ 'p': // valid memory address for load,store [general]
            pr = 3;
            നിർത്തുക;
        അവസ്ഥ 'I': // 12 bit signed immedate
        അവസ്ഥ 'i': // immediate integer operand, including symbolic constants [general]
        അവസ്ഥ 'm': // memory operand [general]
        അവസ്ഥ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            നിർത്തുക;
        അവസ്ഥ 'v':
            tcc_error("unimp: constraint '%c'", c);
        സ്ഥിരസ്ഥിതി:
            tcc_error("unknown constraint '%d'", c);
        }
        എങ്കിൽ (pr > priority)
            priority = pr;
    }
    തിരികെ priority;
}

സ്ഥിതം സ്ഥിരം അക്ഷരം *skip_constraint_modifiers(സ്ഥിരം അക്ഷരം *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ആകുമ്പോൾ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    തിരികെ p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC ശൂന്യം asm_compute_constraints(ASMOperand *operands,
                                    പൂർണ്ണസംഖ്യ nb_operands, പൂർണ്ണസംഖ്യ nb_outputs,
                                    സ്ഥിരം uint8_t *clobber_regs,
                                    പൂർണ്ണസംഖ്യ *pout_reg)
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
    പൂർണ്ണസംഖ്യ sorted_op[MAX_ASM_OPERANDS];
    പൂർണ്ണസംഖ്യ i, j, k, p1, p2, tmp, reg, c, reg_mask;
    സ്ഥിരം അക്ഷരം *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->നിവേശം_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        എങ്കിൽ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, ശൂന്യ);
            എങ്കിൽ ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
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

    /* sort operands according to their priority */
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

    /* allocate registers and generate corresponding asm moves */
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        എങ്കിൽ (op->ref_index >= 0)
            തുടരുക;
        /* select if register is used for output, input or both */
        എങ്കിൽ (op->നിവേശം_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } അല്ലെങ്കിൽ എങ്കിൽ (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } അല്ലെങ്കിൽ {
            reg_mask = REG_IN_MASK;
        }
        എങ്കിൽ (op->reg >= 0) {
            എങ്കിൽ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        തിരഞ്ഞെടുപ്പ് (c) {
        അവസ്ഥ '=': // Operand is written-to
            പോകുക try_next;
        അവസ്ഥ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        അവസ്ഥ '&': // Operand is clobbered before the instruction is done using the input operands
            എങ്കിൽ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            പോകുക try_next;
        അവസ്ഥ 'r': // general-purpose register
        അവസ്ഥ 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            എങ്കിൽ ((reg = op->reg) >= 0)
                പോകുക reg_found;
            അല്ലെങ്കിൽ വേണ്ടി (reg = 10; reg <= 18; reg++) {
                എങ്കിൽ (!is_reg_allocated(reg))
                    പോകുക reg_found;
            }
            പോകുക try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            നിർത്തുക;
        അവസ്ഥ 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            എങ്കിൽ ((reg = op->reg) >= 0)
                പോകുക reg_found;
            അല്ലെങ്കിൽ വേണ്ടി (reg = 42; reg <= 50; reg++) {
                എങ്കിൽ (!is_reg_allocated(reg))
                    പോകുക reg_found;
            }
            പോകുക try_next;
        അവസ്ഥ 'I': // I-Type 12 bit signed immediate
        അവസ്ഥ 'i': // immediate integer operand, including symbolic constants
            എങ്കിൽ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                പോകുക try_next;
            നിർത്തുക;
        അവസ്ഥ 'm': // memory operand
        അവസ്ഥ 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            എങ്കിൽ (j < nb_outputs || c == 'm') {
                എങ്കിൽ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    വേണ്ടി (reg = 10; reg <= 18; reg++) {
                        എങ്കിൽ (!(regs_allocated[reg] & REG_IN_MASK))
                            പോകുക reg_found1;
                    }
                    പോകുക try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            നിർത്തുക;
        }
        /* if a reference is present for that operand, we assign it too */
        എങ്കിൽ (op->നിവേശം_index >= 0) {
            operands[op->നിവേശം_index].reg = op->reg;
            operands[op->നിവേശം_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        എങ്കിൽ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            എങ്കിൽ (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                വേണ്ടി (reg = 42; reg <= 50; reg++) {
                    എങ്കിൽ (!(regs_allocated[reg] & REG_OUT_MASK))
                        പോകുക reg_found2;
                }
            } അല്ലെങ്കിൽ {
                /* From a0 to a7 */
                വേണ്ടി (reg = 10; reg <= 18; reg++) {
                    എങ്കിൽ (!(regs_allocated[reg] & REG_OUT_MASK))
                        പോകുക reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            നിർത്തുക;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    വേണ്ടി (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ശൂന്യ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    എങ്കിൽ (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC ശൂന്യം asm_clobber(uint8_t *clobber_regs, സ്ഥിരം അക്ഷരം *str)
{
    പൂർണ്ണസംഖ്യ reg;
    TokenSym *ts;

    എങ്കിൽ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        തിരികെ;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    എങ്കിൽ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC പൂർണ്ണസംഖ്യ asm_parse_regvar (പൂർണ്ണസംഖ്യ t)
{
    /* PC register not implemented */
    എങ്കിൽ (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        തിരികെ -1;

    എങ്കിൽ (t < TOK_ASM_f0)
        തിരികെ t - TOK_ASM_x0;

    എങ്കിൽ (t < TOK_ASM_zero)
        തിരികെ t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    എങ്കിൽ (t < TOK_ASM_ft0)
        തിരികെ t - TOK_ASM_zero;

    തിരികെ t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
സ്ഥിതം ശൂന്യം asm_emit_ca(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs2)
{
    uint8_t dst, src;

    എങ്കിൽ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    എങ്കിൽ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ശൂന്യ));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

സ്ഥിതം ശൂന്യം asm_emit_cb(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *imm)
{
    uint32_t offset;
    uint8_t src;

    എങ്കിൽ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ശൂന്യ));
    }

    offset = imm->e.v;

    എങ്കിൽ (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ശൂന്യ));
    }

    src = rs1->reg - 8;

    എങ്കിൽ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ശൂന്യ));
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

    തിരഞ്ഞെടുപ്പ് (token) {
    അവസ്ഥ TOK_ASM_c_beqz:
    അവസ്ഥ TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_BIT(offset, 5) | (((offset >> 1) & 3) << 1) | (((offset >> 6) & 3) << 3)) << 2) | ((((offset >> 3) & 3) | NTH_BIT(offset, 8)) << 10));
        തിരികെ;
    സ്ഥിരസ്ഥിതി:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((offset & 0x1f) << 2) | (NTH_BIT(offset, 5) << 12));
        തിരികെ;
    }
}

സ്ഥിതം ശൂന്യം asm_emit_ci(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *imm)
{
    uint32_t immediate;

    എങ്കിൽ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ശൂന്യ));
    }

    immediate = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    തിരഞ്ഞെടുപ്പ് (token) {
    അവസ്ഥ TOK_ASM_c_addi:
    അവസ്ഥ TOK_ASM_c_addiw:
    അവസ്ഥ TOK_ASM_c_li:
    അവസ്ഥ TOK_ASM_c_slli:
        gen_le16(opcode | ((immediate & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_BIT(immediate, 5) << 2 | (((immediate >> 7) & 3) << 3) | NTH_BIT(immediate, 6) << 5 | NTH_BIT(immediate, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 9) << 12));
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_lui:
        gen_le16(opcode | (((immediate >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 17) << 12));
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_fldsp:
    അവസ്ഥ TOK_ASM_c_ldsp:
        gen_le16(opcode | (((immediate >> 6) & 7) << 2) | (((immediate >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_flwsp:
    അവസ്ഥ TOK_ASM_c_lwsp:
        gen_le16(opcode | (((immediate >> 6) & 3) << 2) | (((immediate >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_BIT(immediate, 5) << 12));
        തിരികെ;
    അവസ്ഥ TOK_ASM_c_nop:
        gen_le16(opcode);
        തിരികെ;
    സ്ഥിരസ്ഥിതി:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
സ്ഥിതം ശൂന്യം asm_emit_ciw(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    എങ്കിൽ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ശൂന്യ));
    }

    dst = rd->reg - 8;

    എങ്കിൽ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ശൂന്യ));
    }

    nzuimm = imm->e.v;

    എങ്കിൽ (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, ശൂന്യ));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_BIT(nzuimm, 3) | (NTH_BIT(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
സ്ഥിതം ശൂന്യം asm_emit_cj(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *imm)
{
    uint32_t offset;

    /* +-2 KiB range */
    എങ്കിൽ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, ശൂന്യ));
    }

    offset = imm->e.v;

    എങ്കിൽ (offset & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ശൂന്യ));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_BIT(offset, 5) << 2) | (((offset >> 1) & 7) << 3) | (NTH_BIT(offset, 7) << 6) | (NTH_BIT(offset, 6) << 7) | (NTH_BIT(offset, 10) << 8) | (((offset >> 8) & 3) << 9) | (NTH_BIT(offset, 4) << 11) | (NTH_BIT(offset, 11) << 12));
}

/* caller: Add funct3 into opcode */
സ്ഥിതം ശൂന്യം asm_emit_cl(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *imm)
{
    uint32_t offset;
    uint8_t dst, src;

    എങ്കിൽ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ശൂന്യ));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    എങ്കിൽ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ശൂന്യ));
    }

    offset = imm->e.v;

    എങ്കിൽ (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ശൂന്യ));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    തിരഞ്ഞെടുപ്പ് (token) {
    /* imm variant 1 */
    അവസ്ഥ TOK_ASM_c_flw:
    അവസ്ഥ TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        തിരികെ;
    /* imm variant 2 */
    അവസ്ഥ TOK_ASM_c_fld:
    അവസ്ഥ TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        തിരികെ;
    സ്ഥിരസ്ഥിതി:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
സ്ഥിതം ശൂന്യം asm_emit_cr(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rd, സ്ഥിരം Operand *rs2)
{
    എങ്കിൽ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
സ്ഥിതം ശൂന്യം asm_emit_cs(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rs2, സ്ഥിരം Operand *rs1, സ്ഥിരം Operand *imm)
{
    uint32_t offset;
    uint8_t base, src;

    എങ്കിൽ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ശൂന്യ));
    }

    base = rs1->reg - 8;
    src = rs2->reg - 8;

    എങ്കിൽ (base > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ശൂന്യ));
    }

    offset = imm->e.v;

    എങ്കിൽ (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ശൂന്യ));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    തിരഞ്ഞെടുപ്പ് (token) {
    /* imm variant 1 */
    അവസ്ഥ TOK_ASM_c_fsw:
    അവസ്ഥ TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (NTH_BIT(offset, 6) << 5) | (NTH_BIT(offset, 2) << 6) | (((offset >> 3) & 7) << 10));
        തിരികെ;
    /* imm variant 2 */
    അവസ്ഥ TOK_ASM_c_fsd:
    അവസ്ഥ TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(base) | C_ENCODE_RS1(src) | (((offset >> 6) & 3) << 5) | (((offset >> 3) & 7) << 10));
        തിരികെ;
    സ്ഥിരസ്ഥിതി:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
സ്ഥിതം ശൂന്യം asm_emit_css(പൂർണ്ണസംഖ്യ token, uint16_t opcode, സ്ഥിരം Operand *rs2, സ്ഥിരം Operand *imm)
{
    uint32_t offset;

    എങ്കിൽ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ശൂന്യ));
    }

    offset = imm->e.v;

    എങ്കിൽ (offset > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ശൂന്യ));
    }

    എങ്കിൽ (offset & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ശൂന്യ));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    തിരഞ്ഞെടുപ്പ് (token) {
    /* imm variant 1 */
    അവസ്ഥ TOK_ASM_c_fswsp:
    അവസ്ഥ TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 3) << 7) | (((offset >> 2) & 0xf) << 9));
        തിരികെ;
    /* imm variant 2 */
    അവസ്ഥ TOK_ASM_c_fsdsp:
    അവസ്ഥ TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((offset >> 6) & 7) << 7) | (((offset >> 3) & 7) << 10));
        തിരികെ;
    സ്ഥിരസ്ഥിതി:
        expect("known instruction");
    }
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */
