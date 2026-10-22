/*************************************************************/
/*
 *  RISCV64 assembler for TCC
 *
 */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONFIG_TCC_ASM
/* 32 general purpose + 32 floating point registers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_ASM_REGS 64

ST_FUNC ਖਾਲੀ g(ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ gen_le16(ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ gen_le32(ਪੂਰਨ c);

/*************************************************************/
#ਨਹੀਂਤਾਂ
/*************************************************************/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

ਗਿਣਤੀ {
    OPT_REG,
    OPT_IM12S,
    OPT_IM32,
};
// Registers go from 0 to 31. We use next bit to choose general/float
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_FLOAT_ਨਕਾਬ 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IS_FLOAT(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) ((ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) & REG_FLOAT_ਨਕਾਬ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਮੁੱਲ(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ)    ((ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) & (REG_FLOAT_ਨਕਾਬ-1))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ C_ENCODE_RS1(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) (REG_ਮੁੱਲ(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) << 7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ C_ENCODE_RS2(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) (REG_ਮੁੱਲ(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) << 2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_RD(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ)  (REG_ਮੁੱਲ(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) << 7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_RS1(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) (REG_ਮੁੱਲ(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) << 15)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_RS2(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) (REG_ਮੁੱਲ(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) << 20)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(b, n) ((b >> n) & 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_IM12S (1 << OPT_IM12S)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_IM32 (1 << OPT_IM32)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_REG (1 << OPT_REG)

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਸੰਕਾਰਜ {
    uint32_t type;
    ਸੰਘ {
        uint8_t reg;
        uint16_t regset;
        ਵਿਅੰਜਕ_ਮੁੱਲ e;
    };
} ਸੰਕਾਰਜ;

ਸਥਿਰ ਅਚਲ ਸੰਕਾਰਜ zero = { OP_REG, { 0 }};
ਸਥਿਰ ਅਚਲ ਸੰਕਾਰਜ ra = { OP_REG, { 1 }};
ਸਥਿਰ ਅਚਲ ਸੰਕਾਰਜ zimm = { OP_IM12S };

ਸਥਿਰ ਖਾਲੀ asm_ਦੁਆਧਾਰੀ_opcode(TCCState* s1, ਪੂਰਨ token);
ST_FUNC ਖਾਲੀ asm_clobber(uint8_t *clobber_regs, ਅਚਲ ਅੱਖਰ *str);
ST_FUNC ਖਾਲੀ asm_compute_constraints(ASMOperand *operands, ਪੂਰਨ nb_operands, ਪੂਰਨ nb_outputs, ਅਚਲ uint8_t *clobber_regs, ਪੂਰਨ *pout_reg);
ਸਥਿਰ ਖਾਲੀ asm_emit_a(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *rs2, ਅਚਲ ਸੰਕਾਰਜ *rd1, ਪੂਰਨ aq, ਪੂਰਨ rl);
ਸਥਿਰ ਖਾਲੀ asm_emit_b(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *rs2, ਅਚਲ ਸੰਕਾਰਜ *imm);
ਸਥਿਰ ਖਾਲੀ asm_emit_i(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *rs2);
ਸਥਿਰ ਖਾਲੀ asm_emit_j(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs2);
ਸਥਿਰ ਖਾਲੀ asm_emit_opcode(uint32_t opcode);
ਸਥਿਰ ਖਾਲੀ asm_emit_r(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *rs2);
ਸਥਿਰ ਖਾਲੀ asm_emit_s(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *rs2, ਅਚਲ ਸੰਕਾਰਜ *imm);
ਸਥਿਰ ਖਾਲੀ asm_emit_u(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs2);
ਸਥਿਰ ਖਾਲੀ asm_emit_f(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *rs2);
ਸਥਿਰ ਖਾਲੀ asm_emit_fb(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs);
ਸਥਿਰ ਖਾਲੀ asm_emit_fq(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *rs2, ਅਚਲ ਸੰਕਾਰਜ *rs3);
ST_FUNC ਖਾਲੀ asm_gen_ਕੋਡ(ASMOperand *operands, ਪੂਰਨ nb_operands, ਪੂਰਨ nb_outputs, ਪੂਰਨ is_output, uint8_t *clobber_regs, ਪੂਰਨ ਬਾਹਰਲਾ_reg);
ਸਥਿਰ ਖਾਲੀ asm_nullary_opcode(TCCState *s1, ਪੂਰਨ token);
ST_FUNC ਖਾਲੀ asm_opcode(TCCState *s1, ਪੂਰਨ token);
ਸਥਿਰ ਪੂਰਨ asm_parse_csrvar(ਪੂਰਨ t);
ST_FUNC ਪੂਰਨ asm_parse_regvar(ਪੂਰਨ t);
ਸਥਿਰ ਖਾਲੀ asm_ternary_opcode(TCCState *s1, ਪੂਰਨ token);
ਸਥਿਰ ਖਾਲੀ asm_unary_opcode(TCCState *s1, ਪੂਰਨ token);
ਸਥਿਰ ਖਾਲੀ asm_branch_opcode(TCCState *s1, ਪੂਰਨ token, ਪੂਰਨ argc);
ST_FUNC ਖਾਲੀ gen_expr32(ਵਿਅੰਜਕ_ਮੁੱਲ *pe);
ਸਥਿਰ ਖਾਲੀ parse_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op);
ਸਥਿਰ ਖਾਲੀ parse_branch_ਵਿੱਥ_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op);
ਸਥਿਰ ਖਾਲੀ parse_operands(TCCState *s1, ਸੰਕਾਰਜ *ops, ਪੂਰਨ ਗਿਣਤੀ_3);
ਸਥਿਰ ਖਾਲੀ parse_mem_access_operands(TCCState *s1, ਸੰਕਾਰਜ* ops);
ST_FUNC ਖਾਲੀ subst_asm_ਸੰਕਾਰਜ(CString *ਜੋੜੋ_str, SValue *sv, ਪੂਰਨ modifier);
/* C extension */
ਸਥਿਰ ਖਾਲੀ asm_emit_ca(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs2);
ਸਥਿਰ ਖਾਲੀ asm_emit_cb(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *imm);
ਸਥਿਰ ਖਾਲੀ asm_emit_ci(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *imm);
ਸਥਿਰ ਖਾਲੀ asm_emit_ciw(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *imm);
ਸਥਿਰ ਖਾਲੀ asm_emit_cj(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *imm);
ਸਥਿਰ ਖਾਲੀ asm_emit_cl(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *imm);
ਸਥਿਰ ਖਾਲੀ asm_emit_cr(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs2);
ਸਥਿਰ ਖਾਲੀ asm_emit_cs(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rs2, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *imm);
ਸਥਿਰ ਖਾਲੀ asm_emit_css(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rs2, ਅਚਲ ਸੰਕਾਰਜ *imm);

/* XXX: make it faster ? */
ST_FUNC ਖਾਲੀ g(ਪੂਰਨ c)
{
    ਪੂਰਨ ind1;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    ind1 = ind + 1;
    ਜੇ (ind1 > cur_ਪਾਠ_section->ਅੰਕੜੇ_allocated)
        section_realloc(cur_ਪਾਠ_section, ind1);
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind] = c;
    ind = ind1;
}

ST_FUNC ਖਾਲੀ gen_le16 (ਪੂਰਨ i)
{
    g(i);
    g(i>>8);
}

ST_FUNC ਖਾਲੀ gen_le32 (ਪੂਰਨ i)
{
    ਪੂਰਨ ind1;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    ind1 = ind + 4;
    ਜੇ (ind1 > cur_ਪਾਠ_section->ਅੰਕੜੇ_allocated)
        section_realloc(cur_ਪਾਠ_section, ind1);
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = i & 0xFF;
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = (i >> 8) & 0xFF;
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = (i >> 16) & 0xFF;
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC ਖਾਲੀ gen_expr32(ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    gen_le32(pe->v);
}

ਸਥਿਰ ਖਾਲੀ asm_emit_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ਸਥਿਰ ਖਾਲੀ asm_nullary_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਚੋਣ (token) {
    // Sync instructions

    ਹਾਲਤ TOK_ASM_fence_i: // I
        asm_emit_opcode((0x3 << 2) | 3| (1 << 12));
        ਵਾਪਸ;

    // System calls

    ਹਾਲਤ TOK_ASM_ecall: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_ebreak: // I (pseudo)
        asm_emit_opcode((0x1C << 2) | 3 | (0 << 12) | (1 << 20));
        ਵਾਪਸ;

    // Other

    ਹਾਲਤ TOK_ASM_nop:
        asm_emit_i(token, (4 << 2) | 3, &zero, &zero, &zimm);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_wfi:
        asm_emit_opcode((0x1C << 2) | 3 | (0x105 << 20));
        ਵਾਪਸ;

    /* Pseudoinstructions */
    ਹਾਲਤ TOK_ASM_ret:
        /* jalr zero, x1, 0 */
        asm_emit_opcode( 0x67 | (0 << 12) | ENCODE_RS1(1) );
        ਵਾਪਸ;

    /* C extension */
    ਹਾਲਤ TOK_ASM_c_ebreak:
        asm_emit_cr(token, 2 | (9 << 12), &zero, &zero);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_nop:
        asm_emit_ci(token, 1, &zero, &zimm);
        ਵਾਪਸ;

    ਮੂਲ:
        expect("nullary instruction");
    }
}

/* Parse a text containing operand and store the result in OP */
ਸਥਿਰ ਖਾਲੀ parse_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op)
{
    ਵਿਅੰਜਕ_ਮੁੱਲ e = {0};
    Sym label = {0};
    int8_t reg;

    op->type = 0;

    ਜੇ ((reg = asm_parse_regvar(tok)) != -1) {
        ਅਗਲਾ(); // skip register name
        op->type = OP_REG;
        op->reg = (uint8_t) reg;
        ਵਾਪਸ;
    } ਨਹੀਂਤਾਂ ਜੇ (tok == '$') {
        /* constant value */
        ਅਗਲਾ(); // skip '#' or '$'
    } ਨਹੀਂਤਾਂ ਜੇ ((e.v = asm_parse_csrvar(tok)) != -1) {
        ਅਗਲਾ();
    } ਨਹੀਂਤਾਂ {
        asm_ਵਿਅੰਜਕ(s1, &e);
    }
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ਜੇ (!op->e.sym) {
        ਜੇ ((ਪੂਰਨ) op->e.v >= -0x1000 && (ਪੂਰਨ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ਨਹੀਂਤਾਂ ਜੇ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* see also: "RISC-V ABIs Specification" V1.0

           section 5.2 recommends using a GOT for
           "possibly-undefined weak symbols"

           section 5.3: "Medium position independent code model"
           if this is a non-local symbol: use a GOT
           non-local: outside of a pc-relative +- 2 GiB range
        */

        label.type.t = VT_VOID | VT_STATIC;

        /* use the medium PIC model: GOT, auipc, lw */
        ਜੇ (op->e.sym->type.t & VT_STATIC)
            greloca(cur_ਪਾਠ_section, op->e.sym, ind, R_RISCV_PCREL_HI20, 0);
        ਨਹੀਂਤਾਂ
            greloca(cur_ਪਾਠ_section, op->e.sym, ind, R_RISCV_GOT_HI20, 0);
        put_extern_sym(&label, cur_ਪਾਠ_section, ind, 0);
        greloca(cur_ਪਾਠ_section, &label, ind+4, R_RISCV_PCREL_LO12_I, 0);

        op->type = OP_IM12S;
        op->e.v = 0;
    } ਨਹੀਂਤਾਂ {
        expect("operand");
    }
}

ਸਥਿਰ ਖਾਲੀ parse_branch_ਵਿੱਥ_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op){
    ਵਿਅੰਜਕ_ਮੁੱਲ e = {0};

    asm_ਵਿਅੰਜਕ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ਜੇ (!op->e.sym) {
        ਜੇ ((ਪੂਰਨ) op->e.v >= -0x1000 && (ਪੂਰਨ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ਨਹੀਂਤਾਂ ਜੇ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        /* For extern/static symbols, always use far-branch expansion
           since linker relaxation (R_RISCV_RELAX) is not implemented. */
        op->type = OP_IM32;
        op->e.v = 0;
    } ਨਹੀਂਤਾਂ {
        expect("operand");
    }
}

ਸਥਿਰ ਖਾਲੀ parse_jump_ਵਿੱਥ_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op){
    ਵਿਅੰਜਕ_ਮੁੱਲ e = {0};

    asm_ਵਿਅੰਜਕ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    /* compare against unsigned 12-bit maximum */
    ਜੇ (!op->e.sym) {
        ਜੇ ((ਪੂਰਨ) op->e.v >= -0x1000 && (ਪੂਰਨ) op->e.v < 0x1000)
            op->type = OP_IM12S;
    } ਨਹੀਂਤਾਂ ਜੇ (op->e.sym->type.t & (VT_EXTERN | VT_STATIC)) {
        greloca(cur_ਪਾਠ_section, op->e.sym, ind, R_RISCV_JAL, 0);
        op->type = OP_IM12S;
        op->e.v = 0;
    } ਨਹੀਂਤਾਂ {
        expect("operand");
    }
}

ਸਥਿਰ ਖਾਲੀ parse_operands(TCCState *s1, ਸੰਕਾਰਜ* ops, ਪੂਰਨ ਗਿਣਤੀ_3){
    ਪੂਰਨ i;
    ਲਈ (i = 0; i < ਗਿਣਤੀ_3; i++) {
        ਜੇ ( i != 0 )
            skip(',');
        parse_ਸੰਕਾਰਜ(s1, &ops[i]);
    }
}

/* parse `X, imm(Y)` to {X, Y, imm} operands */
ਸਥਿਰ ਖਾਲੀ parse_mem_access_operands(TCCState *s1, ਸੰਕਾਰਜ* ops){

    ਸੰਕਾਰਜ op;

    parse_ਸੰਕਾਰਜ(s1, &ops[0]);
    skip(',');
    ਜੇ ( tok == '(') {
        /* `X, (Y)` case*/
        ਅਗਲਾ();
        parse_ਸੰਕਾਰਜ(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } ਨਹੀਂਤਾਂ {
        parse_ਸੰਕਾਰਜ(s1, &ops[2]);
        ਜੇ ( tok == '('){
            /* `X, imm(Y)` case*/
            ਅਗਲਾ();
            parse_ਸੰਕਾਰਜ(s1, &ops[1]);
            skip(')');
        } ਨਹੀਂਤਾਂ {
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
ਸਥਿਰ ਖਾਲੀ asm_jal_opcode(TCCState *s1, ਪੂਰਨ token){
    ਸੰਕਾਰਜ ops[2];

    ਜੇ (token == TOK_ASM_j ){
        ops[0] = zero; // j offset
    } ਨਹੀਂਤਾਂ ਜੇ (asm_parse_regvar(tok) == -1) {
        ops[0] = ra;   // jal offset
    } ਨਹੀਂਤਾਂ {
        // jal reg, offset
        parse_ਸੰਕਾਰਜ(s1, &ops[0]);
        ਜੇ ( tok == ',') ਅਗਲਾ(); ਨਹੀਂਤਾਂ expect("','");
    }
    parse_jump_ਵਿੱਥ_ਸੰਕਾਰਜ(s1, &ops[1]);
    asm_emit_j(token, 0x6f, &ops[0], &ops[1]);
}

/* This is special: It can be a pseudointruction or a instruction */
ਸਥਿਰ ਖਾਲੀ asm_jalr_opcode(TCCState *s1, ਪੂਰਨ token){
    ਸੰਕਾਰਜ ops[3];
    ਸੰਕਾਰਜ op;

    parse_ਸੰਕਾਰਜ(s1, &ops[0]);
    ਜੇ ( tok == ',')
        ਅਗਲਾ();
    ਨਹੀਂਤਾਂ {
        /* no more operands, it's the pseudoinstruction:
         *  jalr rs
         * Expand to:
         *  jalr ra, 0(rs)
         */
        asm_emit_i(token, 0x67 | (0 << 12), &ra, &ops[0], &zimm);
        ਵਾਪਸ;
    }

    ਜੇ ( tok == '(') {
        /* `X, (Y)` case*/
        ਅਗਲਾ();
        parse_ਸੰਕਾਰਜ(s1, &ops[1]);
        skip(')');
        ops[2] = zimm;
    } ਨਹੀਂਤਾਂ {
        parse_ਸੰਕਾਰਜ(s1, &ops[2]);
        ਜੇ ( tok == '('){
            /* `X, imm(Y)` case*/
            ਅਗਲਾ();
            parse_ਸੰਕਾਰਜ(s1, &ops[1]);
            skip(')');
        } ਨਹੀਂਤਾਂ {
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


ਸਥਿਰ ਖਾਲੀ asm_unary_opcode(TCCState *s1, ਪੂਰਨ token)
{
    uint32_t opcode = (0x1C << 2) | 3 | (2 << 12);
    ਸੰਕਾਰਜ op;

    parse_operands(s1, &op, 1);
    /* Note: Those all map to CSR--so they are pseudo-instructions. */
    opcode |= ENCODE_RD(op.reg);

    ਚੋਣ (token) {
    /* pseudoinstructions */
    ਹਾਲਤ TOK_ASM_rdcycle:
        asm_emit_opcode(opcode | (0xC00 << 20));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_rdcycleh:
        asm_emit_opcode(opcode | (0xC80 << 20));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_rdtime:
        asm_emit_opcode(opcode | (0xC01 << 20) | ENCODE_RD(op.reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_rdtimeh:
        asm_emit_opcode(opcode | (0xC81 << 20) | ENCODE_RD(op.reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_rdinstret:
        asm_emit_opcode(opcode | (0xC02 << 20) | ENCODE_RD(op.reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_rdinstreth:
        asm_emit_opcode(opcode | (0xC82 << 20) | ENCODE_RD(op.reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_frflags:
        asm_emit_opcode(opcode | (0x001 << 20) | ENCODE_RD(op.reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_frrm:
        asm_emit_opcode(opcode | (0x002 << 20) | ENCODE_RD(op.reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_frcsr:
        asm_emit_opcode(opcode | (0x003 << 20) | ENCODE_RD(op.reg));
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_jr:
        /* jalr zero, 0(rs)*/
        asm_emit_i(token, 0x67 | (0 << 12), &zero, &op, &zimm);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_call:
        /* auipc ra, 0 */
        greloca(cur_ਪਾਠ_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(1));
        /* jalr zero, 0(ra) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(1));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_ਪੂਛ:
        /* auipc x6, 0 */
        greloca(cur_ਪਾਠ_section, op.e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(6));
        /* jalr zero, 0(x6) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(6));
        ਵਾਪਸ;

    /* C extension */
    ਹਾਲਤ TOK_ASM_c_j:
        asm_emit_cj(token, 1 | (5 << 13), &op);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_jal: /* RV32C-only */
        asm_emit_cj(token, 1 | (1 << 13), &op);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_jalr:
        asm_emit_cr(token, 2 | (9 << 12), &op, &zero);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_jr:
        asm_emit_cr(token, 2 | (8 << 12), &op, &zero);
        ਵਾਪਸ;

    ਮੂਲ:
        expect("unary instruction");
    }
}

ਸਥਿਰ ਖਾਲੀ asm_emit_u(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ* rd, ਅਚਲ ਸੰਕਾਰਜ* rs2)
{
    ਜੇ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ਨਿਰਾ));
    } ਨਹੀਂਤਾਂ ਜੇ (rs2->e.v >= 0x100000) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0xfffff", get_tok_str(token, ਨਿਰਾ));
    }
    /* U-type instruction:
	      31...12 imm[31:12]
	      11...7 rd
	      6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | (rs2->e.v << 12));
}

ਸਥਿਰ ਪੂਰਨ parse_fence_ਸੰਕਾਰਜ(){
    ਪੂਰਨ t = tok;
    ਜੇ ( tok == TOK_ASM_or ){
        // we are in a fence instruction, parse as output read
        t = TOK_ASM_or_fence;
    }
    ਅਗਲਾ();
    ਵਾਪਸ t - (TOK_ASM_w_fence - 1);
}

ਸਥਿਰ ਖਾਲੀ asm_fence_opcode(TCCState *s1, ਪੂਰਨ token){
    // `fence` is both an instruction and a pseudoinstruction:
    // `fence` expands to `fence iorw, iorw`
    ਪੂਰਨ succ = 0xF, pred = 0xF;
    ਜੇ (tok != TOK_LINEFEED && tok != ';' && tok != CH_EOF){
        pred = parse_fence_ਸੰਕਾਰਜ();
        ਜੇ ( pred > 0xF || pred < 0) {
            tcc_error("'%s': Expected first operand that is a valid predecessor operand", get_tok_str(token, ਨਿਰਾ));
        }
        skip(',');
        succ = parse_fence_ਸੰਕਾਰਜ();
        ਜੇ ( succ > 0xF || succ < 0) {
            tcc_error("'%s': Expected second operand that is a valid successor operand", get_tok_str(token, ਨਿਰਾ));
        }
    }
    asm_emit_opcode((0x3 << 2) | 3 | (0 << 12) | succ<<20 | pred<<24);
}

ਸਥਿਰ ਖਾਲੀ asm_ਦੁਆਧਾਰੀ_opcode(TCCState* s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ imm = { OP_IM12S };
    ਸੰਕਾਰਜ ops[2];
    int32_t lo;
    uint32_t hi;

    parse_operands(s1, &ops[0], 2);
    ਚੋਣ (token) {
    ਹਾਲਤ TOK_ASM_lui:
        asm_emit_u(token, (0xD << 2) | 3, &ops[0], &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_auipc:
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[1]);
        ਵਾਪਸ;

    /* C extension */
    ਹਾਲਤ TOK_ASM_c_ਜੋੜੋ:
        asm_emit_cr(token, 2 | (9 << 12), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_mv:
        asm_emit_cr(token, 2 | (8 << 12), ops, ops + 1);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_c_addi16sp:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_addi:
        asm_emit_ci(token, 1, ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_addiw:
        asm_emit_ci(token, 1 | (1 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_fldsp:
        asm_emit_ci(token, 2 | (1 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_flwsp: /* RV32FC-only */
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_ldsp:
        asm_emit_ci(token, 2 | (3 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_li:
        asm_emit_ci(token, 1 | (2 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_lui:
        asm_emit_ci(token, 1 | (3 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_lwsp:
        asm_emit_ci(token, 2 | (2 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_slli:
        asm_emit_ci(token, 2, ops, ops + 1);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_c_addi4spn:
        asm_emit_ciw(token, 0, ops, ops + 1);
        ਵਾਪਸ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CA (1 | (3 << 10) | (4 << 13))
    ਹਾਲਤ TOK_ASM_c_addw:
        asm_emit_ca(token, CA | (1 << 5) | (1 << 12), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_and:
        asm_emit_ca(token, CA | (3 << 5), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_or:
        asm_emit_ca(token, CA | (2 << 5), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_sub:
        asm_emit_ca(token, CA, ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_subw:
        asm_emit_ca(token, CA | (1 << 12), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_xor:
        asm_emit_ca(token, CA | (1 << 5), ops, ops + 1);
        ਵਾਪਸ;
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ CA

    ਹਾਲਤ TOK_ASM_c_andi:
        asm_emit_cb(token, 1 | (2 << 10) | (4 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_beqz:
        asm_emit_cb(token, 1 | (6 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_bnez:
        asm_emit_cb(token, 1 | (7 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_srai:
        asm_emit_cb(token, 1 | (1 << 10) | (4 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_srli:
        asm_emit_cb(token, 1 | (4 << 13), ops, ops + 1);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_c_sdsp:
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_swsp:
        asm_emit_css(token, 2 | (6 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_fswsp: /* RV32FC-only */
        asm_emit_css(token, 2 | (7 << 13), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_fsdsp:
        asm_emit_css(token, 2 | (5 << 13), ops, ops + 1);
        ਵਾਪਸ;

    /* F/D extension */
    ਹਾਲਤ TOK_ASM_fsqrt_d:
        asm_emit_fb(token, 0x53 | (11 << 27) | (1 << 25) | (7 << 12), ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fsqrt_s:
        asm_emit_fb(token, 0x53 | (11 << 27) | (0 << 25) | (7 << 12), ops, ops + 1);
        ਵਾਪਸ;

    /* pseudoinstructions */
    /* rd, sym */
    ਹਾਲਤ TOK_ASM_la:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* lw rd, rd, 0 */
        asm_emit_i(token, 3 | (2 << 12), ops, ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_lla:
        /* auipc rd, 0 */
        asm_emit_u(token, 3 | (5 << 2), ops, ops + 1);
        /* addi rd, rd, 0 */
        asm_emit_i(token, 3 | (4 << 2), ops, ops, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_li:
        ਜੇ(ops[1].type != OP_IM32 && ops[1].type != OP_IM12S){
            tcc_error("'%s': Expected first source operand that is an immediate value between 0 and 0xFFFFFFFFFFFFFFFF", get_tok_str(token, ਨਿਰਾ));
        }
        lo = ops[1].e.v;
        hi = (int64_t)ops[1].e.v >> 32;
        ਜੇ(lo < 0){
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
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_mv:
        /* addi rd, rs, 0 */
        asm_emit_i(token, 3 | (4 << 2), &ops[0], &ops[1], &imm);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_not:
        /* xori rd, rs, -1 */
        imm.e.v = -1;
        asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &imm);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_neg:
        /* sub rd, x0, rs2 */
        asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_negw:
        /* subw rd, x0, rs2 */
        asm_emit_r(token, (0xE << 2) | 3 | (32 << 25), &ops[0], &zero, &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sext_w:
        /* addiw rd, rs, 0 */
        asm_emit_i(token, 0x1b, &ops[0], &ops[1], &zimm);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fneg_s:
        /* fsgnjn.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fneg_d:
        /* fsgnjn.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (1 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fmv_s:
        /* fsgnj.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (0 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fmv_d:
        /* fsgnj.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (0 << 12) | (1 << 25) | (4 << 27), &ops[0], &ops[1], &ops[1]);
        ਵਾਪਸ;
    /* FCVT instructions now handled by asm_fcvt_opcode() with
       optional rounding mode operand (GNU as syntax:
       fcvt.w.s rd, rs1 [, rtz/rne/...) */

    ਹਾਲਤ TOK_ASM_jump:
        /* auipc x5, 0 */
        asm_emit_opcode(3 | (5 << 2) | ENCODE_RD(5));
        greloca(cur_ਪਾਠ_section, ops->e.sym, ind, R_RISCV_CALL, 0);
        /* jalr zero, 0(x5) */
        asm_emit_opcode(0x67 | (0 << 12) | ENCODE_RS1(5));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_seqz:
        /* sltiu rd, rs, 1 */
        imm.e.v = 1;
        asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &imm);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_snez:
        /* sltu rd, zero, rs */
        imm.e.v = 1;
        asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &zero, &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sltz:
        /* slt rd, rs, zero */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &zero);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sgtz:
        /* slt rd, zero, rs */
        asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &zero, &ops[1]);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_fabs_d:
        /* fsgnjx.d rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fabs_s:
        /* fsgnjx.s rd, rs, rs */
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (2 << 12), &ops[0], &ops[1], &ops[1]);
        ਵਾਪਸ;

    /* CSR pseudo-instructions */
    ਹਾਲਤ TOK_ASM_csrr:
        /* csrrs rd, csr, x0 */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[1].e.v << 20) | ENCODE_RD(ops[0].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrw:
        /* csrrw x0, csr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrs:
        /* csrrs x0, csr, rs */
        asm_emit_opcode(0x73 | (2 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrc:
        /* csrrc x0, csr, rs */
        asm_emit_opcode(0x73 | (3 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fsrm:
        /* csrrw rd, frm, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (2 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fscsr:
        /* csrrw rd, fcsr, rs */
        asm_emit_opcode(0x73 | (1 << 12) | (3 << 20) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrwi:
        /* csrrwi x0, csr, uimm */
        asm_emit_opcode(0x73 | (5 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrsi:
        /* csrrsi x0, csr, uimm */
        asm_emit_opcode(0x73 | (6 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrci:
        /* csrrci x0, csr, uimm */
        asm_emit_opcode(0x73 | (7 << 12) | (ops[0].e.v << 20) | ENCODE_RS1(ops[1].e.v));
        ਵਾਪਸ;
    ਮੂਲ:
        expect("binary instruction");
    }
}

/* caller: Add funct3, funct7 into opcode */
ਸਥਿਰ ਖਾਲੀ asm_emit_r(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ* rd, ਅਚਲ ਸੰਕਾਰਜ* rs1, ਅਚਲ ਸੰਕਾਰਜ* rs2)
{
    ਜੇ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register or immediate", get_tok_str(token, ਨਿਰਾ));
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
ਸਥਿਰ ਖਾਲੀ asm_emit_f(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ* rd, ਅਚਲ ਸੰਕਾਰਜ* rs1, ਅਚਲ ਸੰਕਾਰਜ* rs2)
{
    ਜੇ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ਨਿਰਾ));
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
ਸਥਿਰ ਖਾਲੀ asm_emit_fb(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ* rd, ਅਚਲ ਸੰਕਾਰਜ* rs)
{
    ਜੇ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs->type != OP_REG || !REG_IS_FLOAT(rs->reg)) {
        tcc_error("'%s': Expected source operand that is a floating-point register", get_tok_str(token, ਨਿਰਾ));
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
ਸਥਿਰ ਖਾਲੀ asm_emit_fq(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ* rd, ਅਚਲ ਸੰਕਾਰਜ* rs1, ਅਚਲ ਸੰਕਾਰਜ* rs2, ਅਚਲ ਸੰਕਾਰਜ* rs3)
{
    ਜੇ (rd->type != OP_REG || !REG_IS_FLOAT(rd->reg)) {
        tcc_error("'%s': Expected destination operand that is a floating-point register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs1->type != OP_REG || !REG_IS_FLOAT(rs1->reg)) {
        tcc_error("'%s': Expected first source operand that is a floating-point register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs2->type != OP_REG || !REG_IS_FLOAT(rs2->reg)) {
        tcc_error("'%s': Expected second source operand that is a floating-point register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs3->type != OP_REG || !REG_IS_FLOAT(rs3->reg)) {
        tcc_error("'%s': Expected third source operand that is a floating-point register", get_tok_str(token, ਨਿਰਾ));
    }
    /* F-type instruction:
	     31...27 rs3
	     26...25 fmt
	     24...20 rs2
	     19...15 rs1
	     14...12 rm
	     11...7 rd
	     6...0 opcode */
    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (REG_ਮੁੱਲ(rs3->reg) << 27));
}

/* caller: Add funct3 into opcode */
ਸਥਿਰ ਖਾਲੀ asm_emit_i(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ* rd, ਅਚਲ ਸੰਕਾਰਜ* rs1, ਅਚਲ ਸੰਕਾਰਜ* rs2)
{
    ਜੇ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs2->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ਨਿਰਾ));
    }
    /* I-type instruction:
	     31...20 imm[11:0]
	     19...15 rs1
	     14...12 funct3
	     11...7 rd
	     6...0 opcode */

    gen_le32(opcode | ENCODE_RD(rd->reg) | ENCODE_RS1(rs1->reg) | (rs2->e.v << 20));
}

ਸਥਿਰ ਖਾਲੀ asm_emit_j(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ* rd, ਅਚਲ ਸੰਕਾਰਜ* rs2)
{
    uint32_t imm;

    ਜੇ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs2->type != OP_IM12S && rs2->type != OP_IM32) {
        tcc_error("'%s': Expected second source operand that is an immediate value", get_tok_str(token, ਨਿਰਾ));
    }

    imm = rs2->e.v;

    /* even offsets in a +- 1 MiB range */
    ਜੇ ((ਪੂਰਨ)imm > (1 << 20) -1 || (ਪੂਰਨ)imm <= -1 * ((1 << 20) -1)) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 0x1fffff", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (imm & 1) {
        tcc_error("'%s': Expected second source operand that is an even immediate value", get_tok_str(token, ਨਿਰਾ));
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

ਸਥਿਰ ਖਾਲੀ asm_mem_access_opcode(TCCState *s1, ਪੂਰਨ token)
{

    ਸੰਕਾਰਜ ops[3];
    parse_mem_access_operands(s1, &ops[0]);

    /* Pseudoinstruction: inst reg, label
     * expand to:
     *   auipc reg, 0
     *   inst reg, 0(reg)
     * And with the proper relocation to label
     */
    ਜੇ (ops[1].type == OP_IM32 && ops[1].e.sym && ops[1].e.sym->type.t & VT_STATIC){
        ops[1] = ops[0];
        /* set the offset to zero */
        ops[2].type = OP_IM12S;
        ops[2].e.v  = 0;
        /* auipc reg, 0 */
        asm_emit_u(token, (0x05 << 2) | 3, &ops[0], &ops[2]);
    }

    ਚੋਣ (token) {
    // l{b|h|w|d}[u] rd, imm(rs1); I-format
    ਹਾਲਤ TOK_ASM_lb:
         asm_emit_i(token, (0x0 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_lh:
         asm_emit_i(token, (0x0 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_lw:
         asm_emit_i(token, (0x0 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_ld:
         asm_emit_i(token, (0x0 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_lbu:
         asm_emit_i(token, (0x0 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_lhu:
         asm_emit_i(token, (0x0 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_lwu:
         asm_emit_i(token, (0x0 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fld:
         asm_emit_i(token, (0x1 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;

    // s{b|h|w|d} rs2, imm(rs1); S-format (with rsX swapped)
    ਹਾਲਤ TOK_ASM_sb:
         asm_emit_s(token, (0x8 << 2) | 3 | (0 << 12), &ops[1], &ops[0], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sh:
         asm_emit_s(token, (0x8 << 2) | 3 | (1 << 12), &ops[1], &ops[0], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sw:
         asm_emit_s(token, (0x8 << 2) | 3 | (2 << 12), &ops[1], &ops[0], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sd:
         asm_emit_s(token, (0x8 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fsd:
         asm_emit_s(token, (0x9 << 2) | 3 | (3 << 12), &ops[1], &ops[0], &ops[2]);
         ਵਾਪਸ;
    }
}

ਸਥਿਰ ਖਾਲੀ asm_branch_opcode(TCCState *s1, ਪੂਰਨ token, ਪੂਰਨ argc)
{
    ਸੰਕਾਰਜ ops[3];
    parse_operands(s1, &ops[0], argc-1);
    skip(',');
    parse_branch_ਵਿੱਥ_ਸੰਕਾਰਜ(s1, &ops[argc-1]);

    ਚੋਣ(token){
    /* branch (RS1, RS2, IMM); B-format */
    ਹਾਲਤ TOK_ASM_beq:
        asm_emit_b(token, 0x63 | (0 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_bne:
        asm_emit_b(token, 0x63 | (1 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_blt:
        asm_emit_b(token, 0x63 | (4 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_bge:
        asm_emit_b(token, 0x63 | (5 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_bltu:
        asm_emit_b(token, 0x63 | (6 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_bgeu:
        asm_emit_b(token, 0x63 | (7 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    /* related pseudoinstructions */
    ਹਾਲਤ TOK_ASM_bgt:
        asm_emit_b(token, 0x63 | (4 << 12), ops + 1, ops, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_ble:
        asm_emit_b(token, 0x63 | (5 << 12), ops + 1, ops, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_bgtu:
        asm_emit_b(token, 0x63 | (6 << 12), ops + 1, ops, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_bleu:
        asm_emit_b(token, 0x63 | (7 << 12), ops + 1, ops, ops + 2);
        ਵਾਪਸ;
    /* shorter pseudoinstructions */
    ਹਾਲਤ TOK_ASM_bnez:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (1 << 12), &ops[0], &zero, &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_beqz:
        /* bne rs, zero, offset */
        asm_emit_b(token, 0x63 | (0 << 12), &ops[0], &zero, &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_blez:
        /* bge rs, zero, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &ops[0], &zero, &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_bgez:
        /* bge zero, rs, offset */
        asm_emit_b(token, 0x63 | (5 << 12), &zero, &ops[0], &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_bltz:
        /* blt rs, zero, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &ops[0], &zero, &ops[1]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_bgtz:
        /* blt zero, rs, offset */
        asm_emit_b(token, 0x63 | (4 << 12), &zero, &ops[0], &ops[1]);
        ਵਾਪਸ;
    }
}

ਸਥਿਰ ਖਾਲੀ asm_ternary_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[3];
    parse_operands(s1, &ops[0], 3);

    ਚੋਣ (token) {
    ਹਾਲਤ TOK_ASM_sll:
        asm_emit_r(token, (0xC << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_slli:
        asm_emit_i(token, (4 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_srl:
        asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_srli:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sra:
        asm_emit_r(token, (0xC << 2) | 3 | (5 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_srai:
        asm_emit_i(token, (0x4 << 2) | 3 | (5 << 12) | (16 << 26), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sllw:
        asm_emit_r(token, (0xE << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_slliw:
        asm_emit_i(token, (6 << 2) | 3 | (1 << 12), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_srlw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_srliw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sraw:
        asm_emit_r(token, (0xE << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sraiw:
        asm_emit_i(token, (0x6 << 2) | 3 | (5 << 12), &ops[0], &ops[1], &ops[2]);
        ਵਾਪਸ;

    // Arithmetic (RD,RS1,(RS2|IMM)); R-format, I-format or U-format

    ਹਾਲਤ TOK_ASM_ਜੋੜੋ:
         asm_emit_r(token, (0xC << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_addi:
         asm_emit_i(token, (4 << 2) | 3, &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sub:
         asm_emit_r(token, (0xC << 2) | 3 | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_addw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_addiw: // 64 bit
         asm_emit_i(token, (0x6 << 2) | 3 | (0 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_subw:
         asm_emit_r(token, (0xE << 2) | 3 | (0 << 12) | (32 << 25), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;

    // Logical (RD,RS1,(RS2|IMM)); R-format or I-format

    ਹਾਲਤ TOK_ASM_xor:
         asm_emit_r(token, (0xC << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_xori:
         asm_emit_i(token, (0x4 << 2) | 3 | (4 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_or:
         asm_emit_r(token, (0xC << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_ori:
         asm_emit_i(token, (0x4 << 2) | 3 | (6 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_and:
         asm_emit_r(token, (0xC << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_andi:
         asm_emit_i(token, (0x4 << 2) | 3 | (7 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;

    // Compare (RD,RS1,(RS2|IMM)); R-format or I-format

    ਹਾਲਤ TOK_ASM_slt:
         asm_emit_r(token, (0xC << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_slti:
         asm_emit_i(token, (0x4 << 2) | 3 | (2 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sltu:
         asm_emit_r(token, (0xC << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_sltiu:
         asm_emit_i(token, (0x4 << 2) | 3 | (3 << 12), &ops[0], &ops[1], &ops[2]);
         ਵਾਪਸ;

    /* M extension */
    ਹਾਲਤ TOK_ASM_div:
        asm_emit_r(token, 0x33 | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_divu:
        asm_emit_r(token, 0x33 | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_divuw:
        asm_emit_r(token, 0x3b | (5 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_divw:
        asm_emit_r(token, 0x3b | (4 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_mul:
        asm_emit_r(token, 0x33 | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_mulh:
        asm_emit_r(token, 0x33 | (1 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_mulhsu:
        asm_emit_r(token, 0x33 | (2 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_mulhu:
        asm_emit_r(token, 0x33 | (3 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_mulw:
        asm_emit_r(token, 0x3b | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_rem:
        asm_emit_r(token, 0x33 | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_remu:
        asm_emit_r(token, 0x33 | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_remuw:
        asm_emit_r(token, 0x3b | (7 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_remw:
        asm_emit_r(token, 0x3b | (6 << 12) | (1 << 25), ops, ops + 1, ops + 2);
        ਵਾਪਸ;

    /* Zicsr extension; (rd, csr, rs/uimm) */
    ਹਾਲਤ TOK_ASM_csrrc:
        asm_emit_i(token, 0x73 | (3 << 12), ops, ops + 2, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrrci:
        /* using rs1 field for uimmm */
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (7 << 12), ops, ops + 2, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrrs:
        asm_emit_i(token, 0x73 | (2 << 12), ops, ops + 2, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrrsi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (6 << 12), ops, ops + 2, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrrw:
        asm_emit_i(token, 0x73 | (1 << 12), ops, ops + 2, ops + 1);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_csrrwi:
        ops[2].type = OP_REG;
        asm_emit_i(token, 0x73 | (5 << 12), ops, ops + 2, ops + 1);
        ਵਾਪਸ;

    /* C extension */
    /* register-based loads and stores (RD, RS1, IMM); CL-format */
    ਹਾਲਤ TOK_ASM_c_fld:
        asm_emit_cl(token, 1 << 13, ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_flw: /* RV32FC-only */
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_fsd:
        asm_emit_cs(token, 5 << 13, ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_fsw: /* RV32FC-only */
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_ld:
        asm_emit_cl(token, 3 << 13, ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_lw:
        asm_emit_cl(token, 2 << 13, ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_sd:
        asm_emit_cs(token, 7 << 13, ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_sw:
        asm_emit_cs(token, 6 << 13, ops, ops + 1, ops + 2);
        ਵਾਪਸ;

    /* F/D extension */
    ਹਾਲਤ TOK_ASM_fadd_d:
        asm_emit_f(token, 0x53 | (0 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fadd_s:
        asm_emit_f(token, 0x53 | (0 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fsub_d:
        asm_emit_f(token, 0x53 | (1 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fsub_s:
        asm_emit_f(token, 0x53 | (1 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fmul_d:
        asm_emit_f(token, 0x53 | (2 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fmul_s:
        asm_emit_f(token, 0x53 | (2 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fdiv_d:
        asm_emit_f(token, 0x53 | (3 << 27) | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fdiv_s:
        asm_emit_f(token, 0x53 | (3 << 27) | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fsgnj_d:
        asm_emit_f(token, 0x53 | (4 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fsgnj_s:
        asm_emit_f(token, 0x53 | (4 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fmax_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fmax_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (1 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fmin_d:
        asm_emit_f(token, 0x53 | (5 << 27) | (1 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fmin_s:
        asm_emit_f(token, 0x53 | (5 << 27) | (0 << 25) | (0 << 12), ops, ops + 1, ops + 2);
        ਵਾਪਸ;

    /* F/D comparison: produce integer result, encode manually */
    ਹਾਲਤ TOK_ASM_feq_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_feq_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (2 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_flt_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_flt_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (1 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fle_s:
        asm_emit_opcode(0x53 | (0x14 << 27) | (0 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fle_d:
        asm_emit_opcode(0x53 | (0x14 << 27) | (1 << 25) | (0 << 12) | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg) | ENCODE_RS2(ops[2].reg));
        ਵਾਪਸ;

    ਮੂਲ:
        expect("ternary instruction");
    }
}

ਸਥਿਰ ਖਾਲੀ asm_quaternary_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[4];
    parse_operands(s1, &ops[0], 4);

    ਚੋਣ (token) {
    ਹਾਲਤ TOK_ASM_fmadd_d:
        asm_emit_fq(token, 0x43 | (1 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fmadd_s:
        asm_emit_fq(token, 0x43 | (0 << 25) | (7 << 12), ops, ops + 1, ops + 2, ops + 3);
        ਵਾਪਸ;

    ਮੂਲ:
        expect("quaternary instruction");
    }
}

ਸਥਿਰ ਖਾਲੀ asm_atomic_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[3];

    parse_ਸੰਕਾਰਜ(s1, &ops[0]);
    skip(',');

    ਜੇ ( token <= TOK_ASM_lr_d_aqrl && token >= TOK_ASM_lr_w ) {
        ops[1] = zero;
    } ਨਹੀਂਤਾਂ {
        parse_ਸੰਕਾਰਜ(s1, &ops[1]);
        skip(',');
    }

    skip('(');
    parse_ਸੰਕਾਰਜ(s1, &ops[2]);
    skip(')');

    ਚੋਣ(token){
        ਹਾਲਤ TOK_ASM_lr_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_lr_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_lr_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_lr_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_lr_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_lr_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_lr_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_lr_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_sc_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_sc_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_sc_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_sc_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_sc_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_sc_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_sc_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_sc_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1);
            ਰੋਕੋ;

        /* AMO instructions (base, aq=0 rl=0) */
        ਹਾਲਤ TOK_ASM_amoadd_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoadd_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoswap_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoswap_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoand_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoand_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0xC<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoxor_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoxor_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomax_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomax_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomaxu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomaxu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x1C<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomin_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomin_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amominu_w:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amominu_d:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 0); ਰੋਕੋ;

        /* AMO aq/rl variants */
        ਹਾਲਤ TOK_ASM_amoadd_w_aq:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoadd_w_rl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoadd_w_aqrl:
            asm_emit_a(token, 0x2F | 0x2<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoadd_d_aq:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoadd_d_rl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoadd_d_aqrl:
            asm_emit_a(token, 0x2F | 0x3<<12 | 0x0<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;

        ਹਾਲਤ TOK_ASM_amoswap_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoswap_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoswap_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoswap_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoswap_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoswap_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoand_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoand_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoand_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoand_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoand_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoand_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0xc<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x8<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoxor_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoxor_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoxor_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoxor_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoxor_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amoxor_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x4<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomax_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomax_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomax_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomax_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomax_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomax_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x14<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomaxu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomaxu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomaxu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomaxu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomaxu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomaxu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x1c<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomin_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomin_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomin_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomin_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomin_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amomin_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x10<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amominu_w_aq:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amominu_w_rl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amominu_w_aqrl:
            asm_emit_a(token, 0x2F | 2<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amominu_d_aq:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 0); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amominu_d_rl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 0, 1); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_amominu_d_aqrl:
            asm_emit_a(token, 0x2F | 3<<12 | 0x18<<27, &ops[0], &ops[1], &ops[2], 1, 1); ਰੋਕੋ;
    }
}

/* caller: Add funct3 and func5 to opcode */
ਸਥਿਰ ਖਾਲੀ asm_emit_a(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd1, ਅਚਲ ਸੰਕਾਰਜ *rs2, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਪੂਰਨ aq, ਪੂਰਨ rl)
{
    ਜੇ (rd1->type != OP_REG)
        tcc_error("'%s': Expected first destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    ਜੇ (rs2->type != OP_REG)
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    ਜੇ (rs1->type != OP_REG)
        tcc_error("'%s': Expected third source operand that is a register", get_tok_str(token, ਨਿਰਾ));
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
ਸਥਿਰ ਖਾਲੀ asm_emit_s(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ* rs1, ਅਚਲ ਸੰਕਾਰਜ* rs2, ਅਚਲ ਸੰਕਾਰਜ* imm)
{
    ਜੇ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected second source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected third operand that is an immediate value between 0 and 8191", get_tok_str(token, ਨਿਰਾ));
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

ਸਥਿਰ ਖਾਲੀ asm_emit_b(ਪੂਰਨ token, uint32_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *rs2, ਅਚਲ ਸੰਕਾਰਜ *imm)
{
    uint32_t ਵਿੱਥ;

    ਜੇ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected first source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }
    ਜੇ (imm->type == OP_IM32 && imm->e.sym) {
        /* far branch: expand to inverted short branch + auipc + jalr */
        ਪੂਰਨ b_ofs = ind;
        uint32_t inv_func3 = ((opcode >> 12) & 7) ^ 1;
        uint32_t inv_opcode = (opcode & ~(7 << 12)) | (inv_func3 << 12);
        /* b<inverse> .+8 */
        asm_emit_opcode(inv_opcode | ENCODE_RS1(rs1->reg)
                        | ENCODE_RS2(rs2->reg) | (1 << 8));
        /* auipc t0, 0 */
        greloca(cur_ਪਾਠ_section, imm->e.sym, ind, R_RISCV_CALL, 0);
        asm_emit_opcode(0x17 | ENCODE_RD(5));
        /* jalr x0, 0(t0) */
        write32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + b_ofs,
                  read32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + b_ofs)
                  | (((ind - b_ofs) >> 1) & 0xf) << 8
                  | (((ind - b_ofs) >> 5) & 0x3f) << 25
                  | (((ind - b_ofs) >> 11) & 1) << 7
                  | (((ind - b_ofs) >> 12) & 1) << 31);
        ਵਾਪਸ;
    }
    ਜੇ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected second source operand that is an immediate value between 0 and 8191", get_tok_str(token, ਨਿਰਾ));
    }

    ਵਿੱਥ = imm->e.v;

    /* B-type instruction:
    31      imm[12]
    30...25 imm[10:5]
    24...20 rs2
    19...15 rs1
    14...12 funct3
    8...11  imm[4:1]
    7       imm[11]
    6...0   opcode */
    asm_emit_opcode(opcode | ENCODE_RS1(rs1->reg) | ENCODE_RS2(rs2->reg) | (((ਵਿੱਥ >> 1) & 0xF) << 8) | (((ਵਿੱਥ >> 5) & 0x1f) << 25) | (((ਵਿੱਥ >> 11) & 1) << 7) | (((ਵਿੱਥ >> 12) & 1) << 31));
}

/* FCVT helper: parse optional rounding mode operand (GNU as syntax:
   fcvt.w.s rd, rs1 [, rtz/rne/rdn/rup/rmm]) */
ਸਥਿਰ ਪੂਰਨ asm_fcvt_rm(TCCState *s1)
{
    ਪੂਰਨ rm = 7; /* dynamic */
    ਜੇ (tok == ',') {
        ਅਗਲਾ();
        ਚੋਣ (tok) {
            ਹਾਲਤ TOK_ASM_rne: rm = 0; ਅਗਲਾ(); ਰੋਕੋ;
            ਹਾਲਤ TOK_ASM_rtz: rm = 1; ਅਗਲਾ(); ਰੋਕੋ;
            ਹਾਲਤ TOK_ASM_rdn: rm = 2; ਅਗਲਾ(); ਰੋਕੋ;
            ਹਾਲਤ TOK_ASM_rup: rm = 3; ਅਗਲਾ(); ਰੋਕੋ;
            ਹਾਲਤ TOK_ASM_rmm: rm = 4; ਅਗਲਾ(); ਰੋਕੋ;
            ਮੂਲ: expect("rounding mode"); ਰੋਕੋ;
        }
    }
    ਵਾਪਸ rm;
}

/* fcvt + fclass handler (all are binary with optional rounding operand) */
ਸਥਿਰ ਖਾਲੀ asm_fcvt_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[2];
    ਪੂਰਨ rm;
    uint32_t enc = 0;

    parse_ਸੰਕਾਰਜ(s1, &ops[0]);
    skip(',');
    parse_ਸੰਕਾਰਜ(s1, &ops[1]);

    ਚੋਣ (token) {
        ਹਾਲਤ TOK_ASM_fcvt_w_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_wu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (1 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_l_s:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (2 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_lu_s: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x60 << 25) | (rm << 12) | (3 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_s_w:  enc = 0x53 | (0x68 << 25) | (7 << 12); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_s_wu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (1 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_s_l:  enc = 0x53 | (0x68 << 25) | (7 << 12) | (2 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_s_lu: enc = 0x53 | (0x68 << 25) | (7 << 12) | (3 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_w_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_wu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (1 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_l_d:  rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (2 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_lu_d: rm = asm_fcvt_rm(s1); enc = 0x53 | (0x61 << 25) | (rm << 12) | (3 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_d_w:  enc = 0x53 | (0x69 << 25) | (7 << 12); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_d_wu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (1 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_d_l:  enc = 0x53 | (0x69 << 25) | (7 << 12) | (2 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_d_lu: enc = 0x53 | (0x69 << 25) | (7 << 12) | (3 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_s_d:  enc = 0x53 | (0x20 << 25) | (7 << 12) | (1 << 20); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fcvt_d_s:  enc = 0x53 | (0x21 << 25) | (7 << 12); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fclass_s:  enc = 0x53 | (0x70 << 25) | (1 << 12); ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_fclass_d:  enc = 0x53 | (0x71 << 25) | (1 << 12); ਰੋਕੋ;
        ਮੂਲ: expect("fcvt/fclass instruction"); ਵਾਪਸ;
    }
    asm_emit_opcode(enc | ENCODE_RD(ops[0].reg) | ENCODE_RS1(ops[1].reg));
}

ST_FUNC ਖਾਲੀ asm_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਚੋਣ (token) {
    ਹਾਲਤ TOK_ASM_ebreak:
    ਹਾਲਤ TOK_ASM_ecall:
    ਹਾਲਤ TOK_ASM_fence_i:
    ਹਾਲਤ TOK_ASM_hrts:
    ਹਾਲਤ TOK_ASM_mrth:
    ਹਾਲਤ TOK_ASM_mrts:
    ਹਾਲਤ TOK_ASM_wfi:
        asm_nullary_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_fence:
        asm_fence_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_rdcycle:
    ਹਾਲਤ TOK_ASM_rdcycleh:
    ਹਾਲਤ TOK_ASM_rdtime:
    ਹਾਲਤ TOK_ASM_rdtimeh:
    ਹਾਲਤ TOK_ASM_rdinstret:
    ਹਾਲਤ TOK_ASM_rdinstreth:
        asm_unary_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_lui:
    ਹਾਲਤ TOK_ASM_auipc:
    ਹਾਲਤ TOK_ASM_fsqrt_s:
    ਹਾਲਤ TOK_ASM_fsqrt_d:
        asm_ਦੁਆਧਾਰੀ_opcode(s1, token);
        ਵਾਪਸ;

    /* fcvt/fclass — separate handler for optional rounding operand */
    ਹਾਲਤ TOK_ASM_fcvt_w_s:
    ਹਾਲਤ TOK_ASM_fcvt_wu_s:
    ਹਾਲਤ TOK_ASM_fcvt_l_s:
    ਹਾਲਤ TOK_ASM_fcvt_lu_s:
    ਹਾਲਤ TOK_ASM_fcvt_s_w:
    ਹਾਲਤ TOK_ASM_fcvt_s_wu:
    ਹਾਲਤ TOK_ASM_fcvt_s_l:
    ਹਾਲਤ TOK_ASM_fcvt_s_lu:
    ਹਾਲਤ TOK_ASM_fcvt_w_d:
    ਹਾਲਤ TOK_ASM_fcvt_wu_d:
    ਹਾਲਤ TOK_ASM_fcvt_l_d:
    ਹਾਲਤ TOK_ASM_fcvt_lu_d:
    ਹਾਲਤ TOK_ASM_fcvt_d_w:
    ਹਾਲਤ TOK_ASM_fcvt_d_wu:
    ਹਾਲਤ TOK_ASM_fcvt_d_l:
    ਹਾਲਤ TOK_ASM_fcvt_d_lu:
    ਹਾਲਤ TOK_ASM_fcvt_s_d:
    ਹਾਲਤ TOK_ASM_fcvt_d_s:
    ਹਾਲਤ TOK_ASM_fclass_s:
    ਹਾਲਤ TOK_ASM_fclass_d:
        asm_fcvt_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_lb:
    ਹਾਲਤ TOK_ASM_lh:
    ਹਾਲਤ TOK_ASM_lw:
    ਹਾਲਤ TOK_ASM_ld:
    ਹਾਲਤ TOK_ASM_fld:
    ਹਾਲਤ TOK_ASM_lbu:
    ਹਾਲਤ TOK_ASM_lhu:
    ਹਾਲਤ TOK_ASM_lwu:
    ਹਾਲਤ TOK_ASM_sb:
    ਹਾਲਤ TOK_ASM_sh:
    ਹਾਲਤ TOK_ASM_sw:
    ਹਾਲਤ TOK_ASM_sd:
    ਹਾਲਤ TOK_ASM_fsd:
        asm_mem_access_opcode(s1, token);
        ਰੋਕੋ;

    ਹਾਲਤ TOK_ASM_jalr:
        asm_jalr_opcode(s1, token); /* it can be a pseudo instruction too*/
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_j:
        asm_jal_opcode(s1, token); /* jal zero, offset*/
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_jal:
        asm_jal_opcode(s1, token); /* it can be a pseudo instruction too*/
        ਰੋਕੋ;

    ਹਾਲਤ TOK_ASM_ਜੋੜੋ:
    ਹਾਲਤ TOK_ASM_addi:
    ਹਾਲਤ TOK_ASM_addiw:
    ਹਾਲਤ TOK_ASM_addw:
    ਹਾਲਤ TOK_ASM_and:
    ਹਾਲਤ TOK_ASM_andi:
    ਹਾਲਤ TOK_ASM_or:
    ਹਾਲਤ TOK_ASM_ori:
    ਹਾਲਤ TOK_ASM_sll:
    ਹਾਲਤ TOK_ASM_slli:
    ਹਾਲਤ TOK_ASM_slliw:
    ਹਾਲਤ TOK_ASM_sllw:
    ਹਾਲਤ TOK_ASM_slt:
    ਹਾਲਤ TOK_ASM_slti:
    ਹਾਲਤ TOK_ASM_sltiu:
    ਹਾਲਤ TOK_ASM_sltu:
    ਹਾਲਤ TOK_ASM_sra:
    ਹਾਲਤ TOK_ASM_srai:
    ਹਾਲਤ TOK_ASM_sraiw:
    ਹਾਲਤ TOK_ASM_sraw:
    ਹਾਲਤ TOK_ASM_srl:
    ਹਾਲਤ TOK_ASM_srli:
    ਹਾਲਤ TOK_ASM_srliw:
    ਹਾਲਤ TOK_ASM_srlw:
    ਹਾਲਤ TOK_ASM_sub:
    ਹਾਲਤ TOK_ASM_subw:
    ਹਾਲਤ TOK_ASM_xor:
    ਹਾਲਤ TOK_ASM_xori:
    /* M extension */
    ਹਾਲਤ TOK_ASM_div:
    ਹਾਲਤ TOK_ASM_divu:
    ਹਾਲਤ TOK_ASM_divuw:
    ਹਾਲਤ TOK_ASM_divw:
    ਹਾਲਤ TOK_ASM_mul:
    ਹਾਲਤ TOK_ASM_mulh:
    ਹਾਲਤ TOK_ASM_mulhsu:
    ਹਾਲਤ TOK_ASM_mulhu:
    ਹਾਲਤ TOK_ASM_mulw:
    ਹਾਲਤ TOK_ASM_rem:
    ਹਾਲਤ TOK_ASM_remu:
    ਹਾਲਤ TOK_ASM_remuw:
    ਹਾਲਤ TOK_ASM_remw:
    /* Zicsr extension */
    ਹਾਲਤ TOK_ASM_csrrc:
    ਹਾਲਤ TOK_ASM_csrrci:
    ਹਾਲਤ TOK_ASM_csrrs:
    ਹਾਲਤ TOK_ASM_csrrsi:
    ਹਾਲਤ TOK_ASM_csrrw:
    ਹਾਲਤ TOK_ASM_csrrwi:
    /* F/D extension */
    ਹਾਲਤ TOK_ASM_fadd_s:
    ਹਾਲਤ TOK_ASM_fadd_d:
    ਹਾਲਤ TOK_ASM_fsub_s:
    ਹਾਲਤ TOK_ASM_fsub_d:
    ਹਾਲਤ TOK_ASM_fmul_s:
    ਹਾਲਤ TOK_ASM_fmul_d:
    ਹਾਲਤ TOK_ASM_fdiv_s:
    ਹਾਲਤ TOK_ASM_fdiv_d:
    ਹਾਲਤ TOK_ASM_fsgnj_d:
    ਹਾਲਤ TOK_ASM_fsgnj_s:
    ਹਾਲਤ TOK_ASM_fmax_s:
    ਹਾਲਤ TOK_ASM_fmax_d:
    ਹਾਲਤ TOK_ASM_fmin_s:
    ਹਾਲਤ TOK_ASM_fmin_d:
    ਹਾਲਤ TOK_ASM_feq_s:
    ਹਾਲਤ TOK_ASM_feq_d:
    ਹਾਲਤ TOK_ASM_flt_s:
    ਹਾਲਤ TOK_ASM_flt_d:
    ਹਾਲਤ TOK_ASM_fle_s:
    ਹਾਲਤ TOK_ASM_fle_d:
        asm_ternary_opcode(s1, token);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_fmadd_d:
    ਹਾਲਤ TOK_ASM_fmadd_s:
        asm_quaternary_opcode(s1, token);
        ਵਾਪਸ;

    /* Branches */
    ਹਾਲਤ TOK_ASM_beq:
    ਹਾਲਤ TOK_ASM_bge:
    ਹਾਲਤ TOK_ASM_bgeu:
    ਹਾਲਤ TOK_ASM_blt:
    ਹਾਲਤ TOK_ASM_bltu:
    ਹਾਲਤ TOK_ASM_bne:
        asm_branch_opcode(s1, token, 3);
        ਰੋਕੋ;

    /* C extension */
    ਹਾਲਤ TOK_ASM_c_ebreak:
    ਹਾਲਤ TOK_ASM_c_nop:
        asm_nullary_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_c_j:
    ਹਾਲਤ TOK_ASM_c_jal:
    ਹਾਲਤ TOK_ASM_c_jalr:
    ਹਾਲਤ TOK_ASM_c_jr:
        asm_unary_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_c_ਜੋੜੋ:
    ਹਾਲਤ TOK_ASM_c_addi16sp:
    ਹਾਲਤ TOK_ASM_c_addi4spn:
    ਹਾਲਤ TOK_ASM_c_addi:
    ਹਾਲਤ TOK_ASM_c_addiw:
    ਹਾਲਤ TOK_ASM_c_addw:
    ਹਾਲਤ TOK_ASM_c_and:
    ਹਾਲਤ TOK_ASM_c_andi:
    ਹਾਲਤ TOK_ASM_c_beqz:
    ਹਾਲਤ TOK_ASM_c_bnez:
    ਹਾਲਤ TOK_ASM_c_fldsp:
    ਹਾਲਤ TOK_ASM_c_flwsp:
    ਹਾਲਤ TOK_ASM_c_fsdsp:
    ਹਾਲਤ TOK_ASM_c_fswsp:
    ਹਾਲਤ TOK_ASM_c_ldsp:
    ਹਾਲਤ TOK_ASM_c_li:
    ਹਾਲਤ TOK_ASM_c_lui:
    ਹਾਲਤ TOK_ASM_c_lwsp:
    ਹਾਲਤ TOK_ASM_c_mv:
    ਹਾਲਤ TOK_ASM_c_or:
    ਹਾਲਤ TOK_ASM_c_sdsp:
    ਹਾਲਤ TOK_ASM_c_slli:
    ਹਾਲਤ TOK_ASM_c_srai:
    ਹਾਲਤ TOK_ASM_c_srli:
    ਹਾਲਤ TOK_ASM_c_sub:
    ਹਾਲਤ TOK_ASM_c_subw:
    ਹਾਲਤ TOK_ASM_c_swsp:
    ਹਾਲਤ TOK_ASM_c_xor:
        asm_ਦੁਆਧਾਰੀ_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_c_fld:
    ਹਾਲਤ TOK_ASM_c_flw:
    ਹਾਲਤ TOK_ASM_c_fsd:
    ਹਾਲਤ TOK_ASM_c_fsw:
    ਹਾਲਤ TOK_ASM_c_ld:
    ਹਾਲਤ TOK_ASM_c_lw:
    ਹਾਲਤ TOK_ASM_c_sd:
    ਹਾਲਤ TOK_ASM_c_sw:
        asm_ternary_opcode(s1, token);
        ਵਾਪਸ;

    /* pseudoinstructions */
    ਹਾਲਤ TOK_ASM_nop:
    ਹਾਲਤ TOK_ASM_ret:
        asm_nullary_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_jr:
    ਹਾਲਤ TOK_ASM_call:
    ਹਾਲਤ TOK_ASM_ਪੂਛ:
    ਹਾਲਤ TOK_ASM_frflags:
    ਹਾਲਤ TOK_ASM_frrm:
    ਹਾਲਤ TOK_ASM_frcsr:
        asm_unary_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_la:
    ਹਾਲਤ TOK_ASM_lla:
    ਹਾਲਤ TOK_ASM_li:
    ਹਾਲਤ TOK_ASM_jump:
    ਹਾਲਤ TOK_ASM_seqz:
    ਹਾਲਤ TOK_ASM_snez:
    ਹਾਲਤ TOK_ASM_sltz:
    ਹਾਲਤ TOK_ASM_sgtz:
    ਹਾਲਤ TOK_ASM_mv:
    ਹਾਲਤ TOK_ASM_not:
    ਹਾਲਤ TOK_ASM_neg:
    ਹਾਲਤ TOK_ASM_negw:
    ਹਾਲਤ TOK_ASM_sext_w:
    ਹਾਲਤ TOK_ASM_fabs_s:
    ਹਾਲਤ TOK_ASM_fabs_d:
    ਹਾਲਤ TOK_ASM_fmv_s:
    ਹਾਲਤ TOK_ASM_fmv_d:
    ਹਾਲਤ TOK_ASM_fneg_s:
    ਹਾਲਤ TOK_ASM_fneg_d:
    ਹਾਲਤ TOK_ASM_csrc:
    ਹਾਲਤ TOK_ASM_csrs:
    ਹਾਲਤ TOK_ASM_csrr:
    ਹਾਲਤ TOK_ASM_csrw:
    ਹਾਲਤ TOK_ASM_csrwi:
    ਹਾਲਤ TOK_ASM_csrsi:
    ਹਾਲਤ TOK_ASM_csrci:
    ਹਾਲਤ TOK_ASM_fsrm:
    ਹਾਲਤ TOK_ASM_fscsr:
        asm_ਦੁਆਧਾਰੀ_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_bnez:
    ਹਾਲਤ TOK_ASM_beqz:
    ਹਾਲਤ TOK_ASM_blez:
    ਹਾਲਤ TOK_ASM_bgez:
    ਹਾਲਤ TOK_ASM_bltz:
    ਹਾਲਤ TOK_ASM_bgtz:
        asm_branch_opcode(s1, token, 2);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_bgt:
    ਹਾਲਤ TOK_ASM_bgtu:
    ਹਾਲਤ TOK_ASM_ble:
    ਹਾਲਤ TOK_ASM_bleu:
        asm_branch_opcode(s1, token, 3);
        ਵਾਪਸ;

    /* Atomic operations */
    ਹਾਲਤ TOK_ASM_lr_w:
    ਹਾਲਤ TOK_ASM_lr_w_aq:
    ਹਾਲਤ TOK_ASM_lr_w_rl:
    ਹਾਲਤ TOK_ASM_lr_w_aqrl:
    ਹਾਲਤ TOK_ASM_lr_d:
    ਹਾਲਤ TOK_ASM_lr_d_aq:
    ਹਾਲਤ TOK_ASM_lr_d_rl:
    ਹਾਲਤ TOK_ASM_lr_d_aqrl:
    ਹਾਲਤ TOK_ASM_sc_w:
    ਹਾਲਤ TOK_ASM_sc_w_aq:
    ਹਾਲਤ TOK_ASM_sc_w_rl:
    ਹਾਲਤ TOK_ASM_sc_w_aqrl:
    ਹਾਲਤ TOK_ASM_sc_d:
    ਹਾਲਤ TOK_ASM_sc_d_aq:
    ਹਾਲਤ TOK_ASM_sc_d_rl:
    ਹਾਲਤ TOK_ASM_sc_d_aqrl:
    /* AMO instructions */
    ਹਾਲਤ TOK_ASM_amoadd_w:
    ਹਾਲਤ TOK_ASM_amoadd_d:
    ਹਾਲਤ TOK_ASM_amoswap_w:
    ਹਾਲਤ TOK_ASM_amoswap_d:
    ਹਾਲਤ TOK_ASM_amoand_w:
    ਹਾਲਤ TOK_ASM_amoand_d:
    ਹਾਲਤ TOK_ASM_amoor_w:
    ਹਾਲਤ TOK_ASM_amoor_d:
    ਹਾਲਤ TOK_ASM_amoxor_w:
    ਹਾਲਤ TOK_ASM_amoxor_d:
    ਹਾਲਤ TOK_ASM_amomax_w:
    ਹਾਲਤ TOK_ASM_amomax_d:
    ਹਾਲਤ TOK_ASM_amomaxu_w:
    ਹਾਲਤ TOK_ASM_amomaxu_d:
    ਹਾਲਤ TOK_ASM_amomin_w:
    ਹਾਲਤ TOK_ASM_amomin_d:
    ਹਾਲਤ TOK_ASM_amominu_w:
    ਹਾਲਤ TOK_ASM_amominu_d:
        
    /* AMO aq/rl */
    ਹਾਲਤ TOK_ASM_amoadd_w_aq:
    ਹਾਲਤ TOK_ASM_amoadd_w_rl:
    ਹਾਲਤ TOK_ASM_amoadd_w_aqrl:
    ਹਾਲਤ TOK_ASM_amoadd_d_aq:
    ਹਾਲਤ TOK_ASM_amoadd_d_rl:
    ਹਾਲਤ TOK_ASM_amoadd_d_aqrl:
    /* AMO aq/rl (all ops) */
    ਹਾਲਤ TOK_ASM_amoswap_w_aq:
    ਹਾਲਤ TOK_ASM_amoswap_w_rl:
    ਹਾਲਤ TOK_ASM_amoswap_w_aqrl:
    ਹਾਲਤ TOK_ASM_amoswap_d_aq:
    ਹਾਲਤ TOK_ASM_amoswap_d_rl:
    ਹਾਲਤ TOK_ASM_amoswap_d_aqrl:
    ਹਾਲਤ TOK_ASM_amoand_w_aq:
    ਹਾਲਤ TOK_ASM_amoand_w_rl:
    ਹਾਲਤ TOK_ASM_amoand_w_aqrl:
    ਹਾਲਤ TOK_ASM_amoand_d_aq:
    ਹਾਲਤ TOK_ASM_amoand_d_rl:
    ਹਾਲਤ TOK_ASM_amoand_d_aqrl:
    ਹਾਲਤ TOK_ASM_amoor_w_aq:
    ਹਾਲਤ TOK_ASM_amoor_w_rl:
    ਹਾਲਤ TOK_ASM_amoor_w_aqrl:
    ਹਾਲਤ TOK_ASM_amoor_d_aq:
    ਹਾਲਤ TOK_ASM_amoor_d_rl:
    ਹਾਲਤ TOK_ASM_amoor_d_aqrl:
    ਹਾਲਤ TOK_ASM_amoxor_w_aq:
    ਹਾਲਤ TOK_ASM_amoxor_w_rl:
    ਹਾਲਤ TOK_ASM_amoxor_w_aqrl:
    ਹਾਲਤ TOK_ASM_amoxor_d_aq:
    ਹਾਲਤ TOK_ASM_amoxor_d_rl:
    ਹਾਲਤ TOK_ASM_amoxor_d_aqrl:
    ਹਾਲਤ TOK_ASM_amomax_w_aq:
    ਹਾਲਤ TOK_ASM_amomax_w_rl:
    ਹਾਲਤ TOK_ASM_amomax_w_aqrl:
    ਹਾਲਤ TOK_ASM_amomax_d_aq:
    ਹਾਲਤ TOK_ASM_amomax_d_rl:
    ਹਾਲਤ TOK_ASM_amomax_d_aqrl:
    ਹਾਲਤ TOK_ASM_amomaxu_w_aq:
    ਹਾਲਤ TOK_ASM_amomaxu_w_rl:
    ਹਾਲਤ TOK_ASM_amomaxu_w_aqrl:
    ਹਾਲਤ TOK_ASM_amomaxu_d_aq:
    ਹਾਲਤ TOK_ASM_amomaxu_d_rl:
    ਹਾਲਤ TOK_ASM_amomaxu_d_aqrl:
    ਹਾਲਤ TOK_ASM_amomin_w_aq:
    ਹਾਲਤ TOK_ASM_amomin_w_rl:
    ਹਾਲਤ TOK_ASM_amomin_w_aqrl:
    ਹਾਲਤ TOK_ASM_amomin_d_aq:
    ਹਾਲਤ TOK_ASM_amomin_d_rl:
    ਹਾਲਤ TOK_ASM_amomin_d_aqrl:
    ਹਾਲਤ TOK_ASM_amominu_w_aq:
    ਹਾਲਤ TOK_ASM_amominu_w_rl:
    ਹਾਲਤ TOK_ASM_amominu_w_aqrl:
    ਹਾਲਤ TOK_ASM_amominu_d_aq:
    ਹਾਲਤ TOK_ASM_amominu_d_rl:
    ਹਾਲਤ TOK_ASM_amominu_d_aqrl:
asm_atomic_opcode(s1, token);
        ਰੋਕੋ;

    ਮੂਲ:
        expect("known instruction");
    }
}

ਸਥਿਰ ਪੂਰਨ asm_parse_csrvar(ਪੂਰਨ t)
{
    ਚੋਣ (t) {
    ਹਾਲਤ TOK_ASM_ਚੱਕਰ:
        ਵਾਪਸ 0xc00;
    ਹਾਲਤ TOK_ASM_fcsr:
        ਵਾਪਸ 3;
    ਹਾਲਤ TOK_ASM_fflags:
        ਵਾਪਸ 1;
    ਹਾਲਤ TOK_ASM_frm:
        ਵਾਪਸ 2;
    ਹਾਲਤ TOK_ASM_instret:
        ਵਾਪਸ 0xc02;
    ਹਾਲਤ TOK_ASM_ਸਮਾਂ:
        ਵਾਪਸ 0xc01;
    ਹਾਲਤ TOK_ASM_cycleh:
        ਵਾਪਸ 0xc80;
    ਹਾਲਤ TOK_ASM_instreth:
        ਵਾਪਸ 0xc82;
    ਹਾਲਤ TOK_ASM_timeh:
        ਵਾਪਸ 0xc81;
    ਮੂਲ:
        ਵਾਪਸ -1;
    }
}

ST_FUNC ਖਾਲੀ subst_asm_ਸੰਕਾਰਜ(CString *ਜੋੜੋ_str, SValue *sv, ਪੂਰਨ modifier)
{
    ਪੂਰਨ r, reg, val;

    r = sv->r;
    ਜੇ ((r & VT_VALMASK) == VT_CONST) {
        ਜੇ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P') {
            //cstr_ccat(add_str, '#');
        }
        ਜੇ (r & VT_SYM) {
            ਅਚਲ ਅੱਖਰ *name = get_tok_str(sv->sym->v, ਨਿਰਾ);
            ਜੇ (sv->sym->v >= SYM_ਪਹਿਲਾ_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, ਲੜੀ_ਲੰਬਾਈ(name))->tok, sv->sym);
            }
            ਜੇ (tcc_state->leading_underscore)
                cstr_ccat(ਜੋੜੋ_str, '_');
            cstr_cat(ਜੋੜੋ_str, name, -1);
            ਜੇ ((uint32_t) sv->c.i == 0)
                ਜਾਓ no_ਵਿੱਥ;
            cstr_ccat(ਜੋੜੋ_str, '+');
        }
        val = sv->c.i;
        ਜੇ (modifier == 'n')
            val = -val;
        ਜੇ (modifier == 'z' && val == 0) {
            cstr_cat(ਜੋੜੋ_str, "zero", -1);
        } ਨਹੀਂਤਾਂ {
            cstr_printf(ਜੋੜੋ_str, "%d", val);
        }
      no_ਵਿੱਥ:;
    } ਨਹੀਂਤਾਂ ਜੇ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(ਜੋੜੋ_str, "%d", (ਪੂਰਨ) sv->c.i);
    } ਨਹੀਂਤਾਂ ਜੇ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ਜੇ (reg >= VT_CONST)
            tcc_ਅੰਦਰੂਨੀ_error("");
        ਜੇ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_ਮੁੱਲ(reg);
        } ਨਹੀਂਤਾਂ {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(ਜੋੜੋ_str, get_tok_str(reg, ਨਿਰਾ), -1);
    } ਨਹੀਂਤਾਂ {
        /* register case */
        reg = r & VT_VALMASK;
        ਜੇ (reg >= VT_CONST)
            tcc_ਅੰਦਰੂਨੀ_error("");
        ਜੇ ((sv->type.t & VT_BTYPE) == VT_FLOAT ||
            (sv->type.t & VT_BTYPE) == VT_DOUBLE) {
            /* floating point register */
            reg = TOK_ASM_f0 + REG_ਮੁੱਲ(reg);
        } ਨਹੀਂਤਾਂ {
            /* general purpose register */
            reg = TOK_ASM_x0 + reg;
        }
        cstr_cat(ਜੋੜੋ_str, get_tok_str(reg, ਨਿਰਾ), -1);
    }
}

/* TCC does not use RISC-V register numbers internally, it uses 0-8 for
 * integers and 8-16 for floats instead */
ਸਥਿਰ ਪੂਰਨ tcc_ireg(ਪੂਰਨ r){
    ਵਾਪਸ REG_ਮੁੱਲ(r) - 10;
}
ਸਥਿਰ ਪੂਰਨ tcc_freg(ਪੂਰਨ r){
    ਵਾਪਸ REG_ਮੁੱਲ(r) - 10 + 8;
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ਖਾਲੀ asm_gen_ਕੋਡ(ASMOperand *operands, ਪੂਰਨ nb_operands,
                         ਪੂਰਨ nb_outputs, ਪੂਰਨ is_output,
                         uint8_t *clobber_regs,
                         ਪੂਰਨ ਬਾਹਰਲਾ_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ਪੂਰਨ i, reg;

    ਸਥਿਰ ਅਚਲ uint8_t reg_saved[] = {
        // General purpose regs
        8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
        // Float regs
        40, 41, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59
    };

    /* mark all used registers */
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(regs_allocated, clobber_regs, ਆਕਾਰ(regs_allocated));
    ਲਈ(i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ਜੇ (op->reg >= 0) {
            regs_allocated[op->reg] = 1;
        }
    }

    ਜੇ(!is_output) {
        /* generate reg save code */
        ਲਈ(i = 0; i < ਆਕਾਰ(reg_saved)/ਆਕਾਰ(reg_saved[0]); i++) {
            reg = reg_saved[i];
            ਜੇ (regs_allocated[reg]) {
                /*ਧੱਕੋ*/
                /* addi sp, sp, -offset */
                gen_le32((4 << 2) | 3 |
                        ENCODE_RD(2) | ENCODE_RS1(2) | (ਬਿਨਾਨਿਸ਼ਾਨੀ)-8 << 20);
                ਜੇ (REG_IS_FLOAT(reg)){
                    /* fsd reg, offset(sp) */
                    gen_le32( 0x27 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                } ਨਹੀਂਤਾਂ {
                    /* sd reg, offset(sp) */
                    gen_le32((0x8 << 2) | 3 | (3 << 12) |
                            ENCODE_RS2(reg) | ENCODE_RS1(2) );
                }
            }
        }

        /* generate load code */
        ਲਈ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ਜੇ (op->reg >= 0) {
                ਜੇ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_ਸਮ੍ਰਿਤੀ) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    ਲੱਦੋ(tcc_ireg(op->reg), &sv);
                } ਨਹੀਂਤਾਂ ਜੇ (i >= nb_outputs || op->is_rw) {
                    /* load value in register */
                    ਜੇ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        ਲੱਦੋ(tcc_freg(op->reg), op->vt);
                    } ਨਹੀਂਤਾਂ {
                        ਲੱਦੋ(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register;
                       the load/store above already handles it correctly */
                }
            }
        }
    } ਨਹੀਂਤਾਂ {
        /* generate save code */
        ਲਈ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ਜੇ (op->reg >= 0) {
                ਜੇ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ਜੇ (!op->is_ਸਮ੍ਰਿਤੀ) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        ਲੱਦੋ(tcc_ireg(ਬਾਹਰਲਾ_reg), &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | ਬਾਹਰਲਾ_reg;
                        store(tcc_ireg(op->reg), &sv);
                    }
                } ਨਹੀਂਤਾਂ {
                    ਜੇ ((op->vt->type.t & VT_BTYPE) == VT_FLOAT ||
                        (op->vt->type.t & VT_BTYPE) == VT_DOUBLE) {
                        store(tcc_freg(op->reg), op->vt);
                    } ਨਹੀਂਤਾਂ {
                        store(tcc_ireg(op->reg), op->vt);
                    }
                    /* RV64: long long fits in a single 64-bit register */
                }
            }
        }
        /* generate reg restore code for floating point registers */
        ਲਈ(i = ਆਕਾਰ(reg_saved)/ਆਕਾਰ(reg_saved[0]) - 1; i >= 0; i--) {
            reg = reg_saved[i];
            ਜੇ (regs_allocated[reg]) {
                /*ਕੱਢੋ*/
                ਜੇ (REG_IS_FLOAT(reg)){
                    /* fld reg, offset(sp) */
                    gen_le32(7 | (3 << 12) |
                            ENCODE_RD(reg) | ENCODE_RS1(2) | 0);
                } ਨਹੀਂਤਾਂ {
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
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ constraint_ਤਰਜੀਹ(ਅਚਲ ਅੱਖਰ *str)
{
    // TODO: How is this chosen??
    ਪੂਰਨ ਤਰਜੀਹ, c, pr;

    /* we take the lowest priority */
    ਤਰਜੀਹ = 0;
    ਲਈ(;;) {
        c = *str;
        ਜੇ (c == '\0')
            ਰੋਕੋ;
        str++;
        ਚੋਣ(c) {
        ਹਾਲਤ 'A': // address that is held in a general-purpose register.
        ਹਾਲਤ 'S': // constraint that matches an absolute symbolic address.
        ਹਾਲਤ 'f': // register [float]
        ਹਾਲਤ 'r': // register [general]
        ਹਾਲਤ 'p': // valid memory address for load,store [general]
            pr = 3;
            ਰੋਕੋ;
        ਹਾਲਤ 'I': // 12 bit signed immedate
        ਹਾਲਤ 'i': // immediate integer operand, including symbolic constants [general]
        ਹਾਲਤ 'm': // memory operand [general]
        ਹਾਲਤ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ਰੋਕੋ;
        ਹਾਲਤ 'v':
            tcc_error("unimp: constraint '%c'", c);
        ਮੂਲ:
            tcc_error("unknown constraint '%d'", c);
        }
        ਜੇ (pr > ਤਰਜੀਹ)
            ਤਰਜੀਹ = pr;
    }
    ਵਾਪਸ ਤਰਜੀਹ;
}

ਸਥਿਰ ਅਚਲ ਅੱਖਰ *skip_constraint_modifiers(ਅਚਲ ਅੱਖਰ *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ਜਦੋਂ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ਵਾਪਸ p;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਬਾਹਰਲਾ_ਨਕਾਬ 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਵਿੱਚ_ਨਕਾਬ  0x02

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ is_reg_allocated(reg) (regs_allocated[reg] & reg_ਨਕਾਬ)

ST_FUNC ਖਾਲੀ asm_compute_constraints(ASMOperand *operands,
                                    ਪੂਰਨ nb_operands, ਪੂਰਨ nb_outputs,
                                    ਅਚਲ uint8_t *clobber_regs,
                                    ਪੂਰਨ *pout_reg)
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
    ਪੂਰਨ sorted_op[MAX_ASM_OPERANDS];
    ਪੂਰਨ i, j, k, p1, p2, tmp, reg, c, reg_ਨਕਾਬ;
    ਅਚਲ ਅੱਖਰ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ਲਈ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ = -1;
        op->ref_ਸੂਚਕਾਂਕ = -1;
        op->reg = -1;
        op->is_ਸਮ੍ਰਿਤੀ = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ਲਈ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ਜੇ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = ਲੱਭੋ_constraint(operands, nb_operands, str, ਨਿਰਾ);
            ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_ਸੂਚਕਾਂਕ = k;
            ਜੇ (operands[k].ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ = i;
            op->ਤਰਜੀਹ = 5;
        } ਨਹੀਂਤਾਂ ਜੇ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->ਤਰਜੀਹ = 1;
            op->reg = reg;
        } ਨਹੀਂਤਾਂ {
            op->ਤਰਜੀਹ = constraint_ਤਰਜੀਹ(str);
        }
    }

    /* sort operands according to their priority */
    ਲਈ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ਲਈ (i = 0; i < nb_operands - 1; i++) {
        ਲਈ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].ਤਰਜੀਹ;
            p2 = operands[sorted_op[j]].ਤਰਜੀਹ;
            ਜੇ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ਲਈ (i = 0; i < NB_ASM_REGS; i++) {
        ਜੇ (clobber_regs[i])
            regs_allocated[i] = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
        ਨਹੀਂਤਾਂ
            regs_allocated[i] = 0;
    }

    /* allocate registers and generate corresponding asm moves */
    ਲਈ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ਜੇ (op->ref_ਸੂਚਕਾਂਕ >= 0)
            ਜਾਰੀ;
        /* select if register is used for output, input or both */
        ਜੇ (op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0) {
            reg_ਨਕਾਬ = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
        } ਨਹੀਂਤਾਂ ਜੇ (j < nb_outputs) {
            reg_ਨਕਾਬ = REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
        } ਨਹੀਂਤਾਂ {
            reg_ਨਕਾਬ = REG_ਵਿੱਚ_ਨਕਾਬ;
        }
        ਜੇ (op->reg >= 0) {
            ਜੇ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_ਅਗਲਾ:
        c = *str++;
        ਚੋਣ (c) {
        ਹਾਲਤ '=': // Operand is written-to
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        ਹਾਲਤ '&': // Operand is clobbered before the instruction is done using the input operands
            ਜੇ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs", c);
            reg_ਨਕਾਬ = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ 'r': // general-purpose register
        ਹਾਲਤ 'p': // loadable/storable address
            /* any general register */
            /* From a0 to a7 */
            ਜੇ ((reg = op->reg) >= 0)
                ਜਾਓ reg_ਮਿਲਿਆ;
            ਨਹੀਂਤਾਂ ਲਈ (reg = 10; reg <= 18; reg++) {
                ਜੇ (!is_reg_allocated(reg))
                    ਜਾਓ reg_ਮਿਲਿਆ;
            }
            ਜਾਓ try_ਅਗਲਾ;
          reg_ਮਿਲਿਆ:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_ਨਕਾਬ;
            ਰੋਕੋ;
        ਹਾਲਤ 'f': // floating pont register
            /* floating point register */
            /* From fa0 to fa7 */
            ਜੇ ((reg = op->reg) >= 0)
                ਜਾਓ reg_ਮਿਲਿਆ;
            ਨਹੀਂਤਾਂ ਲਈ (reg = 42; reg <= 50; reg++) {
                ਜੇ (!is_reg_allocated(reg))
                    ਜਾਓ reg_ਮਿਲਿਆ;
            }
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ 'I': // I-Type 12 bit signed immediate
        ਹਾਲਤ 'i': // immediate integer operand, including symbolic constants
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'm': // memory operand
        ਹਾਲਤ 'g': // any register
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ਜੇ (j < nb_outputs || c == 'm') {
                ਜੇ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register: from a0 to a7 */
                    ਲਈ (reg = 10; reg <= 18; reg++) {
                        ਜੇ (!(regs_allocated[reg] & REG_ਵਿੱਚ_ਨਕਾਬ))
                            ਜਾਓ reg_found1;
                    }
                    ਜਾਓ try_ਅਗਲਾ;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_ਵਿੱਚ_ਨਕਾਬ;
                    op->reg = reg;
                    op->is_ਸਮ੍ਰਿਤੀ = 1;
                }
            }
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ਰੋਕੋ;
        }
        /* if a reference is present for that operand, we assign it too */
        ਜੇ (op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0) {
            operands[op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ].reg = op->reg;
            operands[op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ਲਈ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ਜੇ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_ਸਮ੍ਰਿਤੀ) {
            ਜੇ (REG_IS_FLOAT(op->reg)){
                /* From fa0 to fa7 */
                ਲਈ (reg = 42; reg <= 50; reg++) {
                    ਜੇ (!(regs_allocated[reg] & REG_ਬਾਹਰਲਾ_ਨਕਾਬ))
                        ਜਾਓ reg_found2;
                }
            } ਨਹੀਂਤਾਂ {
                /* From a0 to a7 */
                ਲਈ (reg = 10; reg <= 18; reg++) {
                    ਜੇ (!(regs_allocated[reg] & REG_ਬਾਹਰਲਾ_ਨਕਾਬ))
                        ਜਾਓ reg_found2;
                }
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ਰੋਕੋ;
        }
    }

    /* print sorted constraints */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ASM_DEBUG
    ਲਈ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        ਲਿਖੋ("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ਨਿਰਾ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ਜੇ (*pout_reg >= 0)
        ਲਿਖੋ("out_reg=%d\n", *pout_reg);
#ਜੇ_ਅੰਤ
}

ST_FUNC ਖਾਲੀ asm_clobber(uint8_t *clobber_regs, ਅਚਲ ਅੱਖਰ *str)
{
    ਪੂਰਨ reg;
    TokenSym *ts;

    ਜੇ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ਵਾਪਸ;
    ts = tok_alloc(str, ਲੜੀ_ਲੰਬਾਈ(str));
    reg = asm_parse_regvar(ts->tok);
    ਜੇ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

ST_FUNC ਪੂਰਨ asm_parse_regvar (ਪੂਰਨ t)
{
    /* PC register not implemented */
    ਜੇ (t >= TOK_ASM_pc || t < TOK_ASM_x0)
        ਵਾਪਸ -1;

    ਜੇ (t < TOK_ASM_f0)
        ਵਾਪਸ t - TOK_ASM_x0;

    ਜੇ (t < TOK_ASM_zero)
        ਵਾਪਸ t - TOK_ASM_f0 + 32; // Use higher 32 for floating point

    /* ABI mnemonic */
    ਜੇ (t < TOK_ASM_ft0)
        ਵਾਪਸ t - TOK_ASM_zero;

    ਵਾਪਸ t - TOK_ASM_ft0 + 32; // Use higher 32 for floating point
}

/*************************************************************/
/* C extension */

/* caller: Add funct6, funct2 into opcode */
ਸਥਿਰ ਖਾਲੀ asm_emit_ca(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs2)
{
    uint8_t dst, src;

    ਜੇ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    /* subtract index of x8 */
    dst = rd->reg - 8;
    src = rs2->reg - 8;

    /* only registers {x,f}8 to {x,f}15 are valid (3-bit) */
    ਜੇ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ਨਿਰਾ));
    }

    /* CA-type instruction:
    15...10 funct6
    9...7   rd'/rs1'
    6..5    funct2
    4...2   rs2'
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS2(src) | C_ENCODE_RS1(dst));
}

ਸਥਿਰ ਖਾਲੀ asm_emit_cb(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *imm)
{
    uint32_t ਵਿੱਥ;
    uint8_t src;

    ਜੇ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ਨਿਰਾ));
    }

    ਵਿੱਥ = imm->e.v;

    ਜੇ (ਵਿੱਥ & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ਨਿਰਾ));
    }

    src = rs1->reg - 8;

    ਜੇ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ਨਿਰਾ));
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

    ਚੋਣ (token) {
    ਹਾਲਤ TOK_ASM_c_beqz:
    ਹਾਲਤ TOK_ASM_c_bnez:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 5) | (((ਵਿੱਥ >> 1) & 3) << 1) | (((ਵਿੱਥ >> 6) & 3) << 3)) << 2) | ((((ਵਿੱਥ >> 3) & 3) | NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 8)) << 10));
        ਵਾਪਸ;
    ਮੂਲ:
        gen_le16(opcode | C_ENCODE_RS1(src) | ((ਵਿੱਥ & 0x1f) << 2) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 5) << 12));
        ਵਾਪਸ;
    }
}

ਸਥਿਰ ਖਾਲੀ asm_emit_ci(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *imm)
{
    uint32_t ਤੁਰੰਤ;

    ਜੇ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ਨਿਰਾ));
    }

    ਤੁਰੰਤ = imm->e.v;

    /* CI-type instruction:
    15...13 funct3
    12      imm
    11...7  rd/rs1
    6...2   imm
    1...0   opcode */

    ਚੋਣ (token) {
    ਹਾਲਤ TOK_ASM_c_addi:
    ਹਾਲਤ TOK_ASM_c_addiw:
    ਹਾਲਤ TOK_ASM_c_li:
    ਹਾਲਤ TOK_ASM_c_slli:
        gen_le16(opcode | ((ਤੁਰੰਤ & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਤੁਰੰਤ, 5) << 12));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_addi16sp:
        gen_le16(opcode | NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਤੁਰੰਤ, 5) << 2 | (((ਤੁਰੰਤ >> 7) & 3) << 3) | NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਤੁਰੰਤ, 6) << 5 | NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਤੁਰੰਤ, 4) << 6 | ENCODE_RD(rd->reg) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਤੁਰੰਤ, 9) << 12));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_lui:
        gen_le16(opcode | (((ਤੁਰੰਤ >> 12) & 0x1f) << 2) | ENCODE_RD(rd->reg) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਤੁਰੰਤ, 17) << 12));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_fldsp:
    ਹਾਲਤ TOK_ASM_c_ldsp:
        gen_le16(opcode | (((ਤੁਰੰਤ >> 6) & 7) << 2) | (((ਤੁਰੰਤ >> 3) & 2) << 5) | ENCODE_RD(rd->reg) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਤੁਰੰਤ, 5) << 12));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_flwsp:
    ਹਾਲਤ TOK_ASM_c_lwsp:
        gen_le16(opcode | (((ਤੁਰੰਤ >> 6) & 3) << 2) | (((ਤੁਰੰਤ >> 2) & 7) << 4) | ENCODE_RD(rd->reg) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਤੁਰੰਤ, 5) << 12));
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_c_nop:
        gen_le16(opcode);
        ਵਾਪਸ;
    ਮੂਲ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
ਸਥਿਰ ਖਾਲੀ asm_emit_ciw(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *imm)
{
    uint32_t nzuimm;
    uint8_t dst;

    ਜੇ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ਨਿਰਾ));
    }

    dst = rd->reg - 8;

    ਜੇ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ਨਿਰਾ));
    }

    nzuimm = imm->e.v;

    ਜੇ (nzuimm > 0x3fc) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0x3ff", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (nzuimm & 3) {
        tcc_error("'%s': Expected source operand that is a non-zero immediate value divisible by 4", get_tok_str(token, ਨਿਰਾ));
    }

    /* CIW-type instruction:
    15...13 funct3
    12...5  imm
    4...2   rd'
    1...0   opcode */

    gen_le16(opcode | ENCODE_RS2(rd->reg) | ((NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(nzuimm, 3) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(nzuimm, 2) << 1) | (((nzuimm >> 6) & 0xf) << 2) | (((nzuimm >> 4) & 3) << 6)) << 5));
}

/* caller: Add funct3 into opcode */
ਸਥਿਰ ਖਾਲੀ asm_emit_cj(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *imm)
{
    uint32_t ਵਿੱਥ;

    /* +-2 KiB range */
    ਜੇ (imm->type != OP_IM12S) {
        tcc_error("'%s': Expected source operand that is a 12-bit immediate value", get_tok_str(token, ਨਿਰਾ));
    }

    ਵਿੱਥ = imm->e.v;

    ਜੇ (ਵਿੱਥ & 1) {
        tcc_error("'%s': Expected source operand that is an even immediate value", get_tok_str(token, ਨਿਰਾ));
    }

    /* CJ-type instruction:
    15...13 funct3
    12...2  offset[11|4|9:8|10|6|7|3:1|5]
    1...0   opcode */

    gen_le16(opcode | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 5) << 2) | (((ਵਿੱਥ >> 1) & 7) << 3) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 7) << 6) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 6) << 7) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 10) << 8) | (((ਵਿੱਥ >> 8) & 3) << 9) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 4) << 11) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 11) << 12));
}

/* caller: Add funct3 into opcode */
ਸਥਿਰ ਖਾਲੀ asm_emit_cl(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *imm)
{
    uint32_t ਵਿੱਥ;
    uint8_t dst, src;

    ਜੇ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ਨਿਰਾ));
    }

    dst = rd->reg - 8;
    src = rs1->reg - 8;

    ਜੇ (dst > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ਨਿਰਾ));
    }

    ਵਿੱਥ = imm->e.v;

    ਜੇ (ਵਿੱਥ > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (ਵਿੱਥ & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ਨਿਰਾ));
    }

    /* CL-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rd'
    1...0   opcode */

    ਚੋਣ (token) {
    /* imm variant 1 */
    ਹਾਲਤ TOK_ASM_c_flw:
    ਹਾਲਤ TOK_ASM_c_lw:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 6) << 5) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 2) << 6) | (((ਵਿੱਥ >> 3) & 7) << 10));
        ਵਾਪਸ;
    /* imm variant 2 */
    ਹਾਲਤ TOK_ASM_c_fld:
    ਹਾਲਤ TOK_ASM_c_ld:
        gen_le16(opcode | C_ENCODE_RS2(dst) | C_ENCODE_RS1(src) | (((ਵਿੱਥ >> 6) & 3) << 5) | (((ਵਿੱਥ >> 3) & 7) << 10));
        ਵਾਪਸ;
    ਮੂਲ:
        expect("known instruction");
    }
}

/* caller: Add funct4 into opcode */
ਸਥਿਰ ਖਾਲੀ asm_emit_cr(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rd, ਅਚਲ ਸੰਕਾਰਜ *rs2)
{
    ਜੇ (rd->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    /* CR-type instruction:
    15...12 funct4
    11..7   rd/rs1
    6...2   rs2
    1...0   opcode */

    gen_le16(opcode | C_ENCODE_RS1(rd->reg) | C_ENCODE_RS2(rs2->reg));
}

/* caller: Add funct3 into opcode */
ਸਥਿਰ ਖਾਲੀ asm_emit_cs(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rs2, ਅਚਲ ਸੰਕਾਰਜ *rs1, ਅਚਲ ਸੰਕਾਰਜ *imm)
{
    uint32_t ਵਿੱਥ;
    uint8_t ਅਧਾਰ, src;

    ਜੇ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (rs1->type != OP_REG) {
        tcc_error("'%s': Expected source operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ਨਿਰਾ));
    }

    ਅਧਾਰ = rs1->reg - 8;
    src = rs2->reg - 8;

    ਜੇ (ਅਧਾਰ > 7) {
        tcc_error("'%s': Expected destination operand that is a valid C-extension register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (src > 7) {
        tcc_error("'%s': Expected source operand that is a valid C-extension register", get_tok_str(token, ਨਿਰਾ));
    }

    ਵਿੱਥ = imm->e.v;

    ਜੇ (ਵਿੱਥ > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (ਵਿੱਥ & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ਨਿਰਾ));
    }

    /* CS-type instruction:
    15...13 funct3
    12...10 imm
    9...7   rs1'
    6...5   imm
    4...2   rs2'
    1...0   opcode */
    ਚੋਣ (token) {
    /* imm variant 1 */
    ਹਾਲਤ TOK_ASM_c_fsw:
    ਹਾਲਤ TOK_ASM_c_sw:
        gen_le16(opcode | C_ENCODE_RS2(ਅਧਾਰ) | C_ENCODE_RS1(src) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 6) << 5) | (NTH_ਦੋਆਧਾਰੀ_ਅੰਕ(ਵਿੱਥ, 2) << 6) | (((ਵਿੱਥ >> 3) & 7) << 10));
        ਵਾਪਸ;
    /* imm variant 2 */
    ਹਾਲਤ TOK_ASM_c_fsd:
    ਹਾਲਤ TOK_ASM_c_sd:
        gen_le16(opcode | C_ENCODE_RS2(ਅਧਾਰ) | C_ENCODE_RS1(src) | (((ਵਿੱਥ >> 6) & 3) << 5) | (((ਵਿੱਥ >> 3) & 7) << 10));
        ਵਾਪਸ;
    ਮੂਲ:
        expect("known instruction");
    }
}

/* caller: Add funct3 into opcode */
ਸਥਿਰ ਖਾਲੀ asm_emit_css(ਪੂਰਨ token, uint16_t opcode, ਅਚਲ ਸੰਕਾਰਜ *rs2, ਅਚਲ ਸੰਕਾਰਜ *imm)
{
    uint32_t ਵਿੱਥ;

    ਜੇ (rs2->type != OP_REG) {
        tcc_error("'%s': Expected destination operand that is a register", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (imm->type != OP_IM12S && imm->type != OP_IM32) {
        tcc_error("'%s': Expected source operand that is an immediate value", get_tok_str(token, ਨਿਰਾ));
    }

    ਵਿੱਥ = imm->e.v;

    ਜੇ (ਵਿੱਥ > 0xff) {
        tcc_error("'%s': Expected source operand that is an immediate value between 0 and 0xff", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (ਵਿੱਥ & 3) {
        tcc_error("'%s': Expected source operand that is an immediate value divisible by 4", get_tok_str(token, ਨਿਰਾ));
    }

    /* CSS-type instruction:
    15...13 funct3
    12...7  imm
    6...2   rs2
    1...0   opcode */

    ਚੋਣ (token) {
    /* imm variant 1 */
    ਹਾਲਤ TOK_ASM_c_fswsp:
    ਹਾਲਤ TOK_ASM_c_swsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((ਵਿੱਥ >> 6) & 3) << 7) | (((ਵਿੱਥ >> 2) & 0xf) << 9));
        ਵਾਪਸ;
    /* imm variant 2 */
    ਹਾਲਤ TOK_ASM_c_fsdsp:
    ਹਾਲਤ TOK_ASM_c_sdsp:
        gen_le16(opcode | ENCODE_RS2(rs2->reg) | (((ਵਿੱਥ >> 6) & 7) << 7) | (((ਵਿੱਥ >> 3) & 7) << 10));
        ਵਾਪਸ;
    ਮੂਲ:
        expect("known instruction");
    }
}

/*************************************************************/
#ਜੇ_ਅੰਤ /* ndef TARGET_DEFS_ONLY */
