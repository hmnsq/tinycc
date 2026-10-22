#अगर_घोषित TARGET_DEFS_ONLY

// Number of registers available to allocator:
#घोषणा NB_REGS 19 // x10-x17 aka a0-a7, f10-f17 aka fa0-fa7, xxx, ra, sp
#घोषणा CONFIG_TCC_ASM

#घोषणा TREG_R(x) (x) // x = 0..7
#घोषणा TREG_F(x) (x + 8) // x = 0..7

// Register classes sorted from more general to more precise:
#घोषणा RC_INT (1 << 0)
#घोषणा RC_FLOAT (1 << 1)
#घोषणा RC_R(x) (1 << (2 + (x))) // x = 0..7
#घोषणा RC_F(x) (1 << (10 + (x))) // x = 0..7

#घोषणा RC_IRET (RC_R(0)) // int return register class
#घोषणा RC_IRE2 (RC_R(1)) // int 2nd return register class
#घोषणा RC_FRET (RC_F(0)) // float return register class

#घोषणा REG_IRET (TREG_R(0)) // int return register number
#घोषणा REG_IRE2 (TREG_R(1)) // int 2nd return register number
#घोषणा REG_FRET (TREG_F(0)) // float return register number

#घोषणा PTR_आकार 8

#घोषणा LDOUBLE_आकार 16
#घोषणा LDOUBLE_ALIGN 16

#घोषणा MAX_ALIGN 16

#घोषणा CHAR_IS_UNSIGNED

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#घोषणा PROMOTE_RET

#अन्यथा
#घोषणा USING_GLOBALS
#समावेश "tcc.h"
#समावेश <assert.h>

#घोषणा UPPER(x)	(((अचिन्हित)(x) + 0x800u) & 0xfffff000)
#घोषणा निचला_OVERFLOW(x)	UPPER(x)
#घोषणा SIGN7(x)	((((x) & 0xff) ^ 0x80) - 0x80)
#घोषणा SIGN11(x)	((((x) & 0xfff) ^ 0x800) - 0x800)

ST_तथ्य स्थिर अक्षर * स्थिर target_machine_defs =
    "__riscv\0"
    "__riscv_xlen 64\0"
    "__riscv_flen 64\0"
    "__riscv_div\0"
    "__riscv_mul\0"
    "__riscv_fdiv\0"
    "__riscv_fsqrt\0"
    "__riscv_float_abi_double\0"
    ;

#घोषणा XLEN 8

#घोषणा TREG_RA 17
#घोषणा TREG_SP 18

ST_तथ्य स्थिर पूर्णांक reg_classes[NB_REGS] = {
  RC_INT | RC_R(0),
  RC_INT | RC_R(1),
  RC_INT | RC_R(2),
  RC_INT | RC_R(3),
  RC_INT | RC_R(4),
  RC_INT | RC_R(5),
  RC_INT | RC_R(6),
  RC_INT | RC_R(7),
  RC_FLOAT | RC_F(0),
  RC_FLOAT | RC_F(1),
  RC_FLOAT | RC_F(2),
  RC_FLOAT | RC_F(3),
  RC_FLOAT | RC_F(4),
  RC_FLOAT | RC_F(5),
  RC_FLOAT | RC_F(6),
  RC_FLOAT | RC_F(7),
  0,
  1 << TREG_RA,
  1 << TREG_SP
};

#अगर defined(CONFIG_TCC_BCHECK)
अटल addr_t func_bound_offset;
अटल अचिन्हित दीर्घ func_bound_ind;
ST_तथ्य पूर्णांक func_bound_add_epilog;
#पूर्ण_अगर

अटल पूर्णांक ireg(पूर्णांक r)
{
    अगर (r == TREG_RA)
      वापस 1; // ra
    अगर (r == TREG_SP)
      वापस 2; // sp
    निश्चित(r >= 0 && r < 8);
    वापस r + 10;  // tccrX --> aX == x(10+X)
}

अटल पूर्णांक is_ireg(पूर्णांक r)
{
    वापस (अचिन्हित)r < 8 || r == TREG_RA || r == TREG_SP;
}

अटल पूर्णांक freg(पूर्णांक r)
{
    निश्चित(r >= 8 && r < 16);
    वापस r - 8 + 10;  // tccfX --> faX == f(10+X)
}

अटल पूर्णांक is_freg(पूर्णांक r)
{
    वापस r >= 8 && r < 16;
}

ST_FUNC व्योम o(अचिन्हित पूर्णांक c)
{
    पूर्णांक ind1 = ind + 4;
    अगर (nocode_wanted)
        वापस;
    अगर (ind1 > cur_text_section->तथ्य_allocated)
        section_realloc(cur_text_section, ind1);
    write32le(cur_text_section->तथ्य + ind, c);
    ind = ind1;
}

अटल व्योम EIu(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    o(opcode | (func3 << 12) | (rd << 7) | (rs1 << 15) | (imm << 20));
}

अटल व्योम ER(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t func7)
{
    o(opcode | func3 << 12 | rd << 7 | rs1 << 15 | rs2 << 20 | func7 << 25);
}

अटल व्योम EI(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    निश्चित(! निचला_OVERFLOW(imm));
    EIu(opcode, func3, rd, rs1, imm);
}

अटल व्योम ES(uint32_t opcode, uint32_t func3,
               uint32_t rs1, uint32_t rs2, uint32_t imm)
{
    निश्चित(! निचला_OVERFLOW(imm));
    o(opcode | (func3 << 12) | ((imm & 0x1f) << 7) | (rs1 << 15)
      | (rs2 << 20) | ((imm >> 5) << 25));
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC व्योम gsym_addr(पूर्णांक t_, पूर्णांक a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    जबतक (t) {
        अचिन्हित अक्षर *ptr = cur_text_section->तथ्य + t;
        uint32_t अग्र = read32le(ptr);
        uint32_t r = a - t, imm;
        अगर ((r + (1 << 21)) & ~((1U << 22) - 2))
          tcc_error("out-of-range branch chain");
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        write32le(ptr, r == 4 ? 0x33 : 0x6f | imm); // nop || j imm
        t = अग्र;
    }
}

अटल पूर्णांक load_symofs(पूर्णांक r, SValue *sv, पूर्णांक forstore, पूर्णांक *new_fc)
{
    पूर्णांक rr, doload = 0, large_addend = 0;
    पूर्णांक fc = sv->c.i, v = sv->r & VT_VALMASK;
    अगर (sv->r & VT_SYM) {
        Sym label = {0};
        निश्चित(v == VT_CONST);
        अगर (sv->sym->type.t & VT_TLS) {
            /* TLS Local Exec model: lui + addi + add tp */
            rr = is_ireg(r) ? ireg(r) : 5;
            greloca(cur_text_section, sv->sym, ind,
                    R_RISCV_TPREL_HI20, sv->c.i);
            o(0x37 | (rr << 7));  // lui RR, 0 %tprel_hi(sym)
            greloca(cur_text_section, sv->sym, ind,
                    R_RISCV_TPREL_LO12_I, sv->c.i);
            EI(0x13, 0, rr, rr, 0); // addi RR, RR, 0 %tprel_lo(sym)
            ER(0x33, 0, rr, rr, 4, 0); // add RR, RR, tp
            *new_fc = 0;
            वापस rr;
        }
        अगर (sv->sym->type.t & VT_STATIC) { // XXX do this per linker relax
            greloca(cur_text_section, sv->sym, ind,
                    R_RISCV_PCREL_HI20, sv->c.i);
            *new_fc = 0;
        } अन्यथा {
            अगर (निचला_OVERFLOW(fc)){
              large_addend = 1;
            }
            greloca(cur_text_section, sv->sym, ind,
                    R_RISCV_GOT_HI20, 0);
            doload = 1;
        }
        label.type.t = VT_VOID | VT_STATIC;
	अगर (!nocode_wanted)
            put_extern_sym(&label, cur_text_section, ind, 0);
        rr = is_ireg(r) ? ireg(r) : 5;
        o(0x17 | (rr << 7));   // auipc RR, 0 %pcrel_hi(sym)+addend
        greloca(cur_text_section, &label, ind,
                doload || !forstore
                  ? R_RISCV_PCREL_LO12_I : R_RISCV_PCREL_LO12_S, 0);
        अगर (doload) {
            EI(0x03, 3, rr, rr, 0); // ld RR, 0(RR)
            अगर (large_addend) {
                o(0x37 | (6 << 7) | UPPER(fc)); //lui t1, high(fc)
                ER(0x33, 0, rr, rr, 6, 0); // add RR, RR, t1
                *new_fc = SIGN11(fc);
            }
        }
    } अन्यथा अगर (v == VT_LOCAL || v == VT_LLOCAL) {
        rr = 8; // s0
        अगर (fc != sv->c.i)
          tcc_error("unimp: store(giant local off) (0x%lx)", (दीर्घ)sv->c.i);
        अगर (निचला_OVERFLOW(fc)) {
            rr = is_ireg(r) ? ireg(r) : 5; // t0
            o(0x37 | (rr << 7) | UPPER(fc)); //lui RR, upper(fc)
            ER(0x33, 0, rr, rr, 8, 0); // add RR, RR, s0
            *new_fc = SIGN11(fc);
        }
    } अन्यथा
      tcc_error("uhh");
    वापस rr;
}

अटल व्योम load_large_constant(पूर्णांक rr, पूर्णांक fc, uint32_t pi)
{
    अगर (fc < 0)
	pi++;
    o(0x37 | (rr << 7) | UPPER(pi)); // lui RR, up(up(fc))
    EI(0x13, 0, rr, rr, SIGN11(pi));   // addi RR, RR, lo(up(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((अचिन्हित)fc + (1 << 19)) >> 20)); // addi RR, RR, up(lo(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((अचिन्हित)fc + (1 << 7)) >> 8));  // addi RR, RR, lo1(lo(fc))
    EI(0x13, 1, rr, rr, 8); // slli RR, RR, 8
}

ST_FUNC व्योम load(पूर्णांक r, SValue *sv)
{
    पूर्णांक fr = sv->r;
    पूर्णांक v = fr & VT_VALMASK;
    पूर्णांक rr = is_ireg(r) ? ireg(r) : freg(r);
    पूर्णांक fc = sv->c.i;
    पूर्णांक bt = sv->type.t & VT_BTYPE;
    पूर्णांक align, आकार;
    अगर (fr & VT_LVAL) {
        पूर्णांक func3, opcode = is_freg(r) ? 0x07 : 0x03, br;
        आकार = type_आकार(&sv->type, &align);
        निश्चित (!is_freg(r) || bt == VT_FLOAT || bt == VT_DOUBLE);
        अगर (bt == VT_PTR || bt == VT_FUNC) /* XXX should be done in generic code */
          आकार = PTR_आकार;
        func3 = आकार == 1 ? 0 : आकार == 2 ? 1 : आकार == 4 ? 2 : 3;
        अगर (आकार < 4 && !is_float(sv->type.t) && (sv->type.t & VT_UNSIGNED))
          func3 |= 4;
        अगर (v == VT_LOCAL || (fr & VT_SYM)) {
            br = load_symofs(r, sv, 0, &fc);
        } अन्यथा अगर (v < VT_CONST) {
            br = ireg(v);
            /*if (LOW_OVERFLOW(fc))
              tcc_error("unimp: load(large addend) (0x%x)", fc);*/
            fc = 0; // XXX store ofs in LVAL(reg)
        } अन्यथा अगर (v == VT_LLOCAL) {
            br = load_symofs(r, sv, 0, &fc);
            EI(0x03, 3, rr, br, fc); // ld RR, fc(BR)
            br = rr;
            fc = 0;
        } अन्यथा अगर (v == VT_CONST) {
            int64_t si = sv->c.i;
            si >>= 32;
            अगर (si != 0) {
		load_large_constant(rr, fc, si);
                fc = SIGN7(fc);
            } अन्यथा {
                o(0x37 | (rr << 7) | UPPER(fc)); //lui RR, upper(fc)
                fc = SIGN11(fc);
	    }
            br = rr;
	} अन्यथा {
            tcc_error("unimp: load(non-local lval)");
        }
        EI(opcode, func3, rr, br, fc); // l[bhwd][u] / fl[wd] RR, fc(BR)
    } अन्यथा अगर (v == VT_CONST) {
        पूर्णांक rb = 0, do32bit = 8, zext = 0;
        अगर (is_float(sv->type.t) && bt != VT_LDOUBLE) {
            /* load float/double constant: move bit pattern from int reg */
            uint64_t val = sv->c.i;
            पूर्णांक is_dbl = bt == VT_DOUBLE;
            अगर (val == 0) {
                o(0x53 | (rr << 7) | ((अचिन्हित)(0x78 | is_dbl) << 25));
                वापस;
            }
            अगर (is_dbl) {
                load_large_constant(6, (पूर्णांक)val, (पूर्णांक)(val >> 32));
            } अन्यथा {
                अगर (निचला_OVERFLOW(fc))
                    o(0x37 | (6 << 7) | UPPER(fc)); // lui t1, upper
                EI(0x13 | 8, 0, 6, निचला_OVERFLOW(fc) ? 6 : 0, SIGN11(fc)); // addiw t1,...
            }
            o(0x53 | (rr << 7) | (6 << 15) | ((अचिन्हित)(0x78 | is_dbl) << 25));
            वापस;
        }
        निश्चित(is_ireg(r) || bt == VT_LDOUBLE);
        अगर (fr & VT_SYM) {
            rb = load_symofs(r, sv, 0, &fc);
            do32bit = 0;
        }
        अगर (do32bit && fc != sv->c.i) {
            int64_t si = sv->c.i;
            si >>= 32;
            अगर (si != 0) {
		load_large_constant(rr, fc, si);
                fc = SIGN7(fc);
                rb = rr;
                do32bit = 0;
            } अन्यथा अगर (bt == VT_LLONG) {
                /* A 32bit unsigned constant for a 64bit type.
                   lui always sign extends, so we need to do an explicit zext.*/
                zext = 1;
            }
        }
        अगर (निचला_OVERFLOW(fc))
            o(0x37 | (rr << 7) | UPPER(fc)), rb = rr; //lui RR, upper(fc)
        अगर (fc || (rr != rb) || do32bit || (fr & VT_SYM))
          EI(0x13 | do32bit, 0, rr, rb, SIGN11(fc)); // addi[w] R, x0|R, FC
        अगर (zext) {
            EI(0x13, 1, rr, rr, 32); // slli RR, RR, 32
            EI(0x13, 5, rr, rr, 32); // srli RR, RR, 32
        }
    } अन्यथा अगर (v == VT_LOCAL) {
        पूर्णांक br = load_symofs(r, sv, 0, &fc);
        निश्चित(is_ireg(r));
        EI(0x13, 0, rr, br, fc); // addi R, s0, FC
    } अन्यथा अगर (v < VT_CONST) { /* reg-reg */
        //assert(!fc); XXX support offseted regs
        अगर (is_freg(r) && is_freg(v))
          ER(0x53, 0, rr, freg(v), freg(v), bt == VT_DOUBLE ? 0x11 : 0x10); //fsgnj.[sd] RR, V, V == fmv.[sd] RR, V
        अन्यथा अगर (is_ireg(r) && is_ireg(v))
          EI(0x13, 0, rr, ireg(v), 0); // addi RR, V, 0 == mv RR, V
        अन्यथा {
            पूर्णांक func7 = is_ireg(r) ? 0x70 : 0x78;
            आकार = type_आकार(&sv->type, &align);
            अगर (आकार == 8)
              func7 |= 1;
            निश्चित(आकार == 4 || आकार == 8);
            o(0x53 | (rr << 7) | ((is_freg(v) ? freg(v) : ireg(v)) << 15)
              | ((अचिन्हित)func7 << 25)); // fmv.{w.x, x.w, d.x, x.d} RR, VR
        }
    } अन्यथा अगर (v == VT_CMP) {
        पूर्णांक op = vtop->cmp_op;
        पूर्णांक a = vtop->cmp_r & 0xff;
        पूर्णांक b = (vtop->cmp_r >> 8) & 0xff;
        पूर्णांक inv = 0;
        चयन (op) {
            हाल TOK_ULT:
            हाल TOK_UGE:
            हाल TOK_ULE:
            हाल TOK_UGT:
            हाल TOK_LT:
            हाल TOK_GE:
            हाल TOK_LE:
            हाल TOK_GT:
                अगर (op & 1) { // remove [U]GE,GT
                    inv = 1;
                    op--;
                }
                अगर ((op & 7) == 6) { // [U]LE
                    पूर्णांक t = a; a = b; b = t;
                    inv ^= 1;
                }
                ER(0x33, (op > TOK_UGT) ? 2 : 3, rr, a, b, 0); // slt[u] d, a, b
                अगर (inv)
                  EI(0x13, 4, rr, rr, 1); // xori d, d, 1
                अवरोध;
            हाल TOK_NE:
            हाल TOK_EQ:
                अगर (rr != a || b)
                  ER(0x33, 0, rr, a, b, 0x20); // sub d, a, b
                अगर (op == TOK_NE)
                  ER(0x33, 3, rr, 0, rr, 0); // sltu d, x0, d == snez d,d
                अन्यथा
                  EI(0x13, 3, rr, rr, 1); // sltiu d, d, 1 == seqz d,d
                अवरोध;
        }
    } अन्यथा अगर ((v & ~1) == VT_JMP) {
        पूर्णांक t = v & 1;
        निश्चित(is_ireg(r));
        EI(0x13, 0, rr, 0, t);      // addi RR, x0, t
        gjmp_addr(ind + 8);
        gsym(fc);
        EI(0x13, 0, rr, 0, t ^ 1);  // addi RR, x0, !t
    } अन्यथा
      tcc_error("unimp: load(non-const)");
}

ST_FUNC व्योम store(पूर्णांक r, SValue *sv)
{
    पूर्णांक fr = sv->r & VT_VALMASK;
    पूर्णांक rr = is_ireg(r) ? ireg(r) : freg(r), ptrreg;
    पूर्णांक fc = sv->c.i;
    पूर्णांक bt = sv->type.t & VT_BTYPE;
    पूर्णांक align, आकार = type_आकार(&sv->type, &align);
    निश्चित(!is_float(bt) || is_freg(r) || bt == VT_LDOUBLE);
    /* long doubles are in two integer registers, but the load/store
       primitives only deal with one, so do as if it's one reg.  */
    अगर (bt == VT_LDOUBLE)
      आकार = align = 8;
    अगर (bt == VT_STRUCT)
      tcc_error("unimp: store(struct)");
    अगर (आकार > 8)
      tcc_error("unimp: large sized store");
    निश्चित(sv->r & VT_LVAL);
    अगर (fr == VT_LOCAL || (sv->r & VT_SYM)) {
        ptrreg = load_symofs(-1, sv, 1, &fc);
    } अन्यथा अगर (fr < VT_CONST) {
        ptrreg = ireg(fr);
        /*if (LOW_OVERFLOW(fc))
          tcc_error("unimp: store(large addend) (0x%x)", fc);*/
        fc = 0; // XXX support offsets regs
    } अन्यथा अगर (fr == VT_CONST) {
        int64_t si = sv->c.i;
        ptrreg = 8; // s0
        si >>= 32;
        अगर (si != 0) {
	    load_large_constant(ptrreg, fc, si);
            fc = SIGN7(fc);
        } अन्यथा {
            o(0x37 | (ptrreg << 7) | UPPER(fc)); //lui RR, upper(fc)
            fc = SIGN11(fc);
	}
    } अन्यथा
      tcc_error("implement me: %s(!local)", __FUNCTION__);
    ES(is_freg(r) ? 0x27 : 0x23,                          // fs... | s...
       आकार == 1 ? 0 : आकार == 2 ? 1 : आकार == 4 ? 2 : 3, // ... [wd] | [bhwd]
       ptrreg, rr, fc);                                   // RR, fc(base)
}

अटल व्योम gcall_or_jmp(पूर्णांक docall)
{
    पूर्णांक tr = docall ? 1 : 5; // ra or t0
    अगर ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
        ((vtop->r & VT_SYM) && vtop->c.i == (पूर्णांक)vtop->c.i)) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind,
                R_RISCV_CALL_PLT, (पूर्णांक)vtop->c.i);
        o(0x17 | (tr << 7));   // auipc TR, 0 %call(func)
        EI(0x67, 0, tr, tr, 0);// jalr  TR, r(TR)
    } अन्यथा अगर (vtop->r < VT_CONST) {
        पूर्णांक r = ireg(vtop->r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    } अन्यथा {
        पूर्णांक r = TREG_RA;
        load(r, vtop);
        r = ireg(r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    }
}

#अगर defined(CONFIG_TCC_BCHECK)

अटल व्योम gen_bounds_call(पूर्णांक v)
{
    Sym *sym = external_helper_sym(v);

    greloca(cur_text_section, sym, ind, R_RISCV_CALL_PLT, 0);
    o(0x17 | (1 << 7));   // auipc TR, 0 %call(func)
    EI(0x67, 0, 1, 1, 0); // jalr  TR, r(TR)
}

अटल व्योम gen_bounds_prolog(व्योम)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->तथ्य_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0x00000013);  /* ld a0,#lbound section pointer */
    o(0x00000013);
    o(0x00000013);  /* nop -> call __bound_local_new */
    o(0x00000013);
}

अटल व्योम gen_bounds_epilog(व्योम)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_तथ्य;
    Sym label = {0};

    पूर्णांक offset_modified = func_bound_offset != lbounds_section->तथ्य_offset;

    अगर (!offset_modified && !func_bound_add_epilog)
        वापस;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, माप(addr_t));
    *bounds_ptr = 0;

    sym_तथ्य = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_आकार);

    label.type.t = VT_VOID | VT_STATIC;
    /* generate bound local allocation */
    अगर (offset_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        put_extern_sym(&label, cur_text_section, ind, 0);
        greloca(cur_text_section, sym_तथ्य, ind, R_RISCV_GOT_HI20, 0);
        o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
        greloca(cur_text_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
        EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
        gen_bounds_call(TOK___bound_local_new);
        ind = saved_ind;
        label.c = 0; /* force new local ELF symbol */
    }

    /* generate bound check local freeing */
    o(0xe02a1101); /* addi sp,sp,-32  sd   a0,0(sp)   */
    o(0xa82ae42e); /* sd   a1,8(sp)   fsd  fa0,16(sp) */
    put_extern_sym(&label, cur_text_section, ind, 0);
    greloca(cur_text_section, sym_तथ्य, ind, R_RISCV_GOT_HI20, 0);
    o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
    greloca(cur_text_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
    gen_bounds_call(TOK___bound_local_delete);
    o(0x65a26502); /* ld   a0,0(sp)   ld   a1,8(sp)   */
    o(0x61052542); /* fld  fa0,16(sp) addi sp,sp,32   */
}
#पूर्ण_अगर

अटल व्योम reg_pass_rec(CType *type, पूर्णांक *rc, पूर्णांक *fieldofs, पूर्णांक ofs)
{
    अगर ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *f;
        अगर (type->ref->type.t == VT_UNION)
          rc[0] = -1;
        अन्यथा क्रम (f = type->ref->अग्र; f; f = f->अग्र)
          reg_pass_rec(&f->type, rc, fieldofs, ofs + f->c);
    } अन्यथा अगर (type->t & VT_ARRAY) {
        अगर (type->ref->c < 0 || type->ref->c > 2)
          rc[0] = -1;
        अन्यथा {
            पूर्णांक a, sz = type_आकार(&type->ref->type, &a);
            reg_pass_rec(&type->ref->type, rc, fieldofs, ofs);
            अगर (rc[0] > 2 || (rc[0] == 2 && type->ref->c > 1))
              rc[0] = -1;
            अन्यथा अगर (type->ref->c == 2 && rc[0] && rc[1] == RC_FLOAT) {
              rc[++rc[0]] = RC_FLOAT;
              fieldofs[rc[0]] = ((ofs + sz) << 4)
                                | (type->ref->type.t & VT_BTYPE);
            } अन्यथा अगर (type->ref->c == 2)
              rc[0] = -1;
        }
    } अन्यथा अगर (rc[0] == 2 || rc[0] < 0 || (type->t & VT_BTYPE) == VT_LDOUBLE)
      rc[0] = -1;
    अन्यथा अगर (!rc[0] || rc[1] == RC_FLOAT || is_float(type->t)) {
      rc[++rc[0]] = is_float(type->t) ? RC_FLOAT : RC_INT;
      fieldofs[rc[0]] = (ofs << 4) | ((type->t & VT_BTYPE) == VT_PTR ? VT_LLONG : type->t & VT_BTYPE);
    } अन्यथा
      rc[0] = -1;
}

अटल व्योम reg_pass(CType *type, पूर्णांक *prc, पूर्णांक *fieldofs, पूर्णांक named)
{
    prc[0] = 0;
    reg_pass_rec(type, prc, fieldofs, 0);
    अगर (prc[0] <= 0 || !named) {
        पूर्णांक align, आकार = type_आकार(type, &align);
        prc[0] = (आकार + 7) >> 3;
        prc[1] = prc[2] = RC_INT;
        fieldofs[1] = (0 << 4) | (आकार <= 1 ? VT_BYTE : आकार <= 2 ? VT_SHORT : आकार <= 4 ? VT_INT : VT_LLONG);
        fieldofs[2] = (8 << 4) | (आकार <= 9 ? VT_BYTE : आकार <= 10 ? VT_SHORT : आकार <= 12 ? VT_INT : VT_LLONG);
    }
}

ST_FUNC व्योम gfunc_call(पूर्णांक nb_args)
{
    पूर्णांक i, align, आकार, areg[2];
    पूर्णांक *info = tcc_malloc((nb_args + 1) * माप (पूर्णांक));
    पूर्णांक ढेर_adj = 0, tempspace = 0, ढेर_add, ofs, splitofs = 0;
    पूर्णांक old = (vtop[-nb_args].type.ref->f.func_type == FUNC_OLD);
    SValue *sv;
    Sym *sa;

#अगर_घोषित CONFIG_TCC_BCHECK
    पूर्णांक bc_save = tcc_state->do_bounds_check;
    अगर (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#पूर्ण_अगर

    areg[0] = 0; /* int arg regs */
    areg[1] = 8; /* float arg regs */
    sa = vtop[-nb_args].type.ref->अग्र;
    क्रम (i = 0; i < nb_args; i++) {
        पूर्णांक nregs, byref = 0, tempofs;
        पूर्णांक prc[3], fieldofs[3];
        sv = &vtop[1 + i - nb_args];
        sv->type.t &= ~VT_ARRAY; // XXX this should be done in tccgen.c
        आकार = type_आकार(&sv->type, &align);
        अगर (आकार > 16) {
            अगर (align < XLEN)
              align = XLEN;
            tempspace = (tempspace + align - 1) & -align;
            tempofs = tempspace;
            tempspace += आकार;
            आकार = align = 8;
            byref = 64 | (tempofs << 7);
        }
        reg_pass(&sv->type, prc, fieldofs, old || sa != 0);
        अगर (!old && !sa && align == 2*XLEN && आकार <= 2*XLEN)
          areg[0] = (areg[0] + 1) & ~1;
        nregs = prc[0];
        अगर (आकार == 0)
            info[i] = 0;
        अन्यथा अगर ((prc[1] == RC_INT && areg[0] >= 8)
            || (prc[1] == RC_FLOAT && areg[1] >= 16)
            || (nregs == 2 && prc[1] == RC_FLOAT && prc[2] == RC_FLOAT
                && areg[1] >= 15)
            || (nregs == 2 && prc[1] != prc[2]
                && (areg[1] >= 16 || areg[0] >= 8))) {
            info[i] = 32;
            अगर (align < XLEN)
              align = XLEN;
            ढेर_adj += (आकार + align - 1) & -align;
            अगर (!old && !sa) /* one vararg on stack forces the rest on stack */
              areg[0] = 8, areg[1] = 16;
        } अन्यथा {
            info[i] = areg[prc[1] - 1]++;
            अगर (!byref)
              info[i] |= (fieldofs[1] & VT_BTYPE) << 12;
            निश्चित(!(fieldofs[1] >> 4));
            अगर (nregs == 2) {
                अगर (prc[2] == RC_FLOAT || areg[0] < 8)
                  info[i] |= (1 + areg[prc[2] - 1]++) << 7;
                अन्यथा {
                    info[i] |= 16;
                    ढेर_adj += 8;
                }
                अगर (!byref) {
                    निश्चित((fieldofs[2] >> 4) < 2048);
                    info[i] |= fieldofs[2] << (12 + 4); // includes offset
                }
            }
        }
        info[i] |= byref;
        अगर (sa)
          sa = sa->अग्र;
    }
    ढेर_adj = (ढेर_adj + 15) & -16;
    tempspace = (tempspace + 15) & -16;
    ढेर_add = ढेर_adj + tempspace;

    अगर (ढेर_add) {
        अगर (ढेर_add >= 0x800) {
            o(0x37 | (5 << 7) | UPPER(-ढेर_add)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(-ढेर_add)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        अन्यथा
            EI(0x13, 0, 2, 2, -ढेर_add);   // addi sp, sp, -adj
        क्रम (i = ofs = 0; i < nb_args; i++) {
            अगर (info[i] & (64 | 32)) {
                vrotb(nb_args - i);
                आकार = type_आकार(&vtop->type, &align);
                अगर (info[i] & 64) {
                    vset(&char_pointer_type, TREG_SP, 0);
                    vpushi(ढेर_adj + (info[i] >> 7));
                    gen_op('+');
                    vpushv(vtop); // this replaces the old argument
                    vrott(3);
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vpop();
                    आकार = align = 8;
                }
                अगर (info[i] & 32) {
                    अगर (align < XLEN)
                      align = XLEN;
                    /* Once we support offseted regs we can do this:
                       vset(&vtop->type, TREG_SP | VT_LVAL, ofs);
                       to construct the lvalue for the outgoing stack slot,
                       until then we have to jump through hoops.  */
                    vset(&char_pointer_type, TREG_SP, 0);
                    ofs = (ofs + align - 1) & -align;
                    vpushi(ofs);
                    gen_op('+');
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vtop->r = vtop->r2 = VT_CONST; // this arg is done
                    ofs += आकार;
                }
                vrott(nb_args - i);
            } अन्यथा अगर (info[i] & 16) {
                निश्चित(!splitofs);
                splitofs = ofs;
                ofs += 8;
            }
        }
    }
    क्रम (i = 0; i < nb_args; i++) {
        पूर्णांक ii = info[nb_args - 1 - i], r = ii, r2 = r;
        अगर (!(r & 32)) {
            CType origtype;
            पूर्णांक loadt;
            r &= 15;
            r2 = r2 & 64 ? 0 : (r2 >> 7) & 31;
            निश्चित(r2 <= 16);
            vrotb(i+1);
            origtype = vtop->type;
            आकार = type_आकार(&vtop->type, &align);
            अगर (आकार == 0)
                जाओ done;
            loadt = vtop->type.t & VT_BTYPE;
            अगर (loadt == VT_STRUCT) {
                loadt = (ii >> 12) & VT_BTYPE;
            }
            अगर (info[nb_args - 1 - i] & 16) {
                निश्चित(!r2);
                r2 = 1 + TREG_RA;
            }
            अगर (loadt == VT_LDOUBLE) {
                निश्चित(r2);
                r2--;
            } अन्यथा अगर (r2) {
                test_lvalue();
                vpushv(vtop);
            }
            vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
            gv(r < 8 ? RC_R(r) : RC_F(r - 8));
            vtop->type = origtype;

            अगर (r2 && loadt != VT_LDOUBLE) {
                r2--;
                निश्चित(r2 < 16 || r2 == TREG_RA);
                vswap();
                gaddrof();
                vtop->type = char_pointer_type;
                vpushi(ii >> 20);
#अगर_घोषित CONFIG_TCC_BCHECK
		अगर ((origtype.t & VT_BTYPE) == VT_STRUCT)
                    tcc_state->do_bounds_check = 0;
#पूर्ण_अगर
                gen_op('+');
#अगर_घोषित CONFIG_TCC_BCHECK
		tcc_state->do_bounds_check = bc_save;
#पूर्ण_अगर
                indir();
                vtop->type = origtype;
                loadt = vtop->type.t & VT_BTYPE;
                अगर (loadt == VT_STRUCT) {
                    loadt = (ii >> 16) & VT_BTYPE;
                }
                save_reg_upstack(r2, 1);
                vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
                load(r2, vtop);
                निश्चित(r2 < VT_CONST);
                vtop--;
                vtop->r2 = r2;
            }
            अगर (info[nb_args - 1 - i] & 16) {
                ES(0x23, 3, 2, ireg(vtop->r2), splitofs); // sd t0, ofs(sp)
                vtop->r2 = VT_CONST;
            } अन्यथा अगर (loadt == VT_LDOUBLE && vtop->r2 != r2) {
                निश्चित(vtop->r2 <= 7 && r2 <= 7);
                /* XXX we'd like to have 'gv' move directly into
                   the right class instead of us fixing it up.  */
                EI(0x13, 0, ireg(r2), ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = r2;
            }
done:
            vrott(i+1);
        }
    }
    vrotb(nb_args + 1);
    save_regs(nb_args + 1);
    gcall_or_jmp(1);
    vtop -= nb_args + 1;
    अगर (ढेर_add) {
        अगर (ढेर_add >= 0x800) {
            o(0x37 | (5 << 7) | UPPER(ढेर_add)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(ढेर_add)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        अन्यथा
            EI(0x13, 0, 2, 2, ढेर_add);      // addi sp, sp, adj
   }
   tcc_free(info);
}

अटल पूर्णांक func_sub_sp_offset, अंक_va_regs, func_va_list_ofs;

ST_FUNC व्योम gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    पूर्णांक i, addr, align, आकार;
    पूर्णांक param_addr = 0;
    पूर्णांक areg[2];
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    loc = -16; // for ra and s0
    func_sub_sp_offset = ind;
    ind += 5 * 4;

    areg[0] = 0, areg[1] = 0;
    addr = 0;
    /* if the function returns by reference, then add an
       implicit pointer parameter */
    आकार = type_आकार(&func_vt, &align);
    अगर (आकार > 2 * XLEN) {
        loc -= 8;
        func_vc = loc;
        ES(0x23, 3, 8, 10 + areg[0]++, loc); // sd a0, loc(s0)
    }
    /* define parameters */
    जबतक ((sym = sym->अग्र) != शून्य) {
        पूर्णांक byref = 0;
        पूर्णांक regcount;
        पूर्णांक prc[3], fieldofs[3];
        type = &sym->type;
        आकार = type_आकार(type, &align);
        अगर (आकार > 2 * XLEN) {
            type = &char_pointer_type;
            आकार = align = byref = 8;
        }
        reg_pass(type, prc, fieldofs, 1);
        regcount = prc[0];
        अगर (areg[prc[1] - 1] >= 8
            || (regcount == 2
                && ((prc[1] == RC_FLOAT && prc[2] == RC_FLOAT && areg[1] >= 7)
                    || (prc[1] != prc[2] && (areg[1] >= 8 || areg[0] >= 8))))) {
            अगर (align < XLEN)
              align = XLEN;
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += आकार;
        } अन्यथा {
            loc -= regcount * 8; // XXX could reserve only 'size' bytes
            param_addr = loc;
            क्रम (i = 0; i < regcount; i++) {
                अगर (areg[prc[1+i] - 1] >= 8) {
                    निश्चित(i == 1 && regcount == 2 && !(addr & 7));
                    EI(0x03, 3, 5, 8, addr); // ld t0, addr(s0)
                    addr += 8;
                    ES(0x23, 3, 8, 5, loc + i*8); // sd t0, loc(s0)
                } अन्यथा अगर (prc[1+i] == RC_FLOAT) {
                    ES(0x27, (आकार / regcount) == 4 ? 2 : 3, 8, 10 + areg[1]++, loc + (fieldofs[i+1] >> 4)); // fs[wd] FAi, loc(s0)
                } अन्यथा {
                    ES(0x23, 3, 8, 10 + areg[0]++, loc + i*8); // sd aX, loc(s0) // XXX
                }
            }
        }
        gfunc_set_param(sym, param_addr, byref);
    }
    func_va_list_ofs = addr;
    अंक_va_regs = 0;
    अगर (func_var) {
        क्रम (; areg[0] < 8; areg[0]++) {
            अंक_va_regs++;
            ES(0x23, 3, 8, 10 + areg[0], -8 + अंक_va_regs * 8); // sd aX, loc(s0)
        }
    }
#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#पूर्ण_अगर
}

ST_FUNC पूर्णांक gfunc_sret(CType *vt, पूर्णांक variadic, CType *ret,
                       पूर्णांक *ret_align, पूर्णांक *regsize)
{
    पूर्णांक align, आकार = type_आकार(vt, &align), nregs;
    पूर्णांक prc[3], fieldofs[3];
    *ret_align = 1;
    *regsize = 8;
    अगर (आकार > 16)
      वापस 0;
    reg_pass(vt, prc, fieldofs, 1);
    nregs = prc[0];
    अगर (nregs == 2 && prc[1] != prc[2])
      वापस -1;  /* generic code can't deal with this case */
    अगर (prc[1] == RC_FLOAT) {
        *regsize = आकार / nregs;
    }
    ret->t = fieldofs[1] & VT_BTYPE;
    ret->ref = शून्य;
    वापस nregs;
}

ST_FUNC व्योम arch_transfer_ret_regs(पूर्णांक aftercall)
{
    पूर्णांक prc[3], fieldofs[3];
    reg_pass(&vtop->type, prc, fieldofs, 1);
    निश्चित(prc[0] == 2 && prc[1] != prc[2] && !(fieldofs[1] >> 4));
    निश्चित(vtop->r == (VT_LOCAL | VT_LVAL));
    vpushv(vtop);
    vtop->type.t = fieldofs[1] & VT_BTYPE;
    (aftercall ? store : load)(prc[1] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop->c.i += fieldofs[2] >> 4;
    vtop->type.t = fieldofs[2] & VT_BTYPE;
    (aftercall ? store : load)(prc[2] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop--;
}

ST_FUNC व्योम gfunc_epilog(व्योम)
{
    पूर्णांक v, saved_ind, d, large_ofs_ind;

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#पूर्ण_अगर

    loc = (loc - अंक_va_regs * 8);
    d = v = (-loc + 15) & -16;

    EI(0x13, 0, 2, 8, अंक_va_regs * 8); // addi sp, s0, num_va_regs*8
    EI(0x03, 3, 1, 8, -8); // ld ra, -8(s0)
    EI(0x03, 3, 8, 8, -16); // ld s0, -16(s0)
    EI(0x67, 0, 0, 1, 0); // jalr x0, 0(x1), aka ret

    large_ofs_ind = ind;
    अगर (v >= (1 << 11)) {
        d = 16;
        EI(0x13, 0, 8, 2, d - अंक_va_regs * 8);      // addi s0, sp, d
        o(0x37 | (5 << 7) | UPPER(v-16)); //lui t0, upper(v)
        EI(0x13, 0, 5, 5, SIGN11(v-16)); // addi t0, t0, lo(v)
        ER(0x33, 0, 2, 2, 5, 0x20); // sub sp, sp, t0
        gjmp_addr(func_sub_sp_offset + 5*4);
    }
    saved_ind = ind;

    ind = func_sub_sp_offset;
    EI(0x13, 0, 2, 2, -d);     // addi sp, sp, -d
    ES(0x23, 3, 2, 1, d - 8 - अंक_va_regs * 8);  // sd ra, d-8(sp)
    ES(0x23, 3, 2, 8, d - 16 - अंक_va_regs * 8); // sd s0, d-16(sp)
    अगर (v < (1 << 11))
      EI(0x13, 0, 8, 2, d - अंक_va_regs * 8);      // addi s0, sp, d
    अन्यथा
      gjmp_addr(large_ofs_ind);
    अगर ((ind - func_sub_sp_offset) != 5*4)
      EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
    ind = saved_ind;
}

ST_FUNC व्योम gen_va_start(व्योम)
{
    vtop--;
    vset(&char_pointer_type, VT_LOCAL, func_va_list_ofs);
}

ST_FUNC व्योम gen_fill_nops(पूर्णांक bytes)
{
    अगर ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    जबतक (bytes > 0) {
        EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
        bytes -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC पूर्णांक gjmp(पूर्णांक t)
{
    अगर (nocode_wanted)
      वापस t;
    o(t);
    वापस ind - 4;
}

// Generate branch to known address:
ST_FUNC व्योम gjmp_addr(पूर्णांक a)
{
    uint32_t r = a - ind, imm;
    अगर ((r + (1 << 21)) & ~((1U << 22) - 2)) {
        o(0x17 | (5 << 7) | UPPER(r)); // lui RR, up(r)
        r = SIGN11(r);
        EI(0x67, 0, 0, 5, r);      // jalr x0, r(t0)
    } अन्यथा {
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        o(0x6f | imm); // jal x0, imm ==  j imm
    }
}

ST_FUNC पूर्णांक gjmp_cond(पूर्णांक op, पूर्णांक t)
{
    पूर्णांक tmp;
    पूर्णांक a = vtop->cmp_r & 0xff;
    पूर्णांक b = (vtop->cmp_r >> 8) & 0xff;
    चयन (op) {
        हाल TOK_ULT: op = 6; अवरोध;
        हाल TOK_UGE: op = 7; अवरोध;
        हाल TOK_ULE: op = 7; tmp = a; a = b; b = tmp; अवरोध;
        हाल TOK_UGT: op = 6; tmp = a; a = b; b = tmp; अवरोध;
        हाल TOK_LT:  op = 4; अवरोध;
        हाल TOK_GE:  op = 5; अवरोध;
        हाल TOK_LE:  op = 5; tmp = a; a = b; b = tmp; अवरोध;
        हाल TOK_GT:  op = 4; tmp = a; a = b; b = tmp; अवरोध;
        हाल TOK_NE:  op = 1; अवरोध;
        हाल TOK_EQ:  op = 0; अवरोध;
    }
    o(0x63 | (op ^ 1) << 12 | a << 15 | b << 20 | 8 << 7); // bOP a,b,+4
    वापस gjmp(t);
}

ST_FUNC पूर्णांक gjmp_append(पूर्णांक n, पूर्णांक t)
{
    व्योम *p;
    /* insert jump list n into t */
    अगर (n) {
        uint32_t n1 = n, n2;
        जबतक ((n2 = read32le(p = cur_text_section->तथ्य + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    वापस t;
}

अटल व्योम gen_opil(पूर्णांक op, पूर्णांक ll)
{
    पूर्णांक a, b, d;
    पूर्णांक func3 = 0;
    ll = ll ? 0 : 8;
    अगर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
        पूर्णांक fc = vtop->c.i;
        अगर (fc == vtop->c.i && !निचला_OVERFLOW(fc)) {
            पूर्णांक cll = 0;
            पूर्णांक m = ll ? 31 : 63;
            vswap();
            gv(RC_INT);
            a = ireg(vtop[0].r);
            --vtop;
            d = get_reg(RC_INT);
            ++vtop;
            vswap();
            चयन (op) {
                हाल '-':
                    अगर (fc <= -(1 << 11))
                      अवरोध;
                    fc = -fc;
                हाल '+':
                    func3 = 0; // addi d, a, fc
                    cll = ll;
                do_cop:
                    EI(0x13 | cll, func3, ireg(d), a, fc);
                    --vtop;
                    अगर (op >= TOK_ULT && op <= TOK_GT) {
                      vset_VT_CMP(TOK_NE);
                      vtop->cmp_r = ireg(d) | 0 << 8;
                    } अन्यथा
                      vtop[0].r = d;
                    वापस;
                हाल TOK_LE:
                    अगर (fc >= (1 << 11) - 1)
                      अवरोध;
                    ++fc;
                हाल TOK_LT:  func3 = 2; जाओ do_cop; // slti d, a, fc
                हाल TOK_ULE:
                    अगर (fc >= (1 << 11) - 1 || fc == -1)
                      अवरोध;
                    ++fc;
                हाल TOK_ULT: func3 = 3; जाओ do_cop; // sltiu d, a, fc
                हाल '^':     func3 = 4; जाओ do_cop; // xori d, a, fc
                हाल '|':     func3 = 6; जाओ do_cop; // ori  d, a, fc
                हाल '&':     func3 = 7; जाओ do_cop; // andi d, a, fc
                हाल TOK_SHL: func3 = 1; cll = ll; fc &= m; जाओ do_cop; // slli d, a, fc
                हाल TOK_SHR: func3 = 5; cll = ll; fc &= m; जाओ do_cop; // srli d, a, fc
                हाल TOK_SAR: func3 = 5; cll = ll; fc = 1024 | (fc & m); जाओ do_cop;

                हाल TOK_UGE: /* -> TOK_ULT */
                हाल TOK_UGT: /* -> TOK_ULE */
                हाल TOK_GE:  /* -> TOK_LT */
                हाल TOK_GT:  /* -> TOK_LE */
                    gen_opil(op - 1, !ll);
                    vtop->cmp_op ^= 1;
                    वापस;

                हाल TOK_NE:
                हाल TOK_EQ:
                    अगर (fc)
                      gen_opil('-', !ll), a = ireg(vtop++->r);
                    --vtop;
                    vset_VT_CMP(op);
                    vtop->cmp_r = a | 0 << 8;
                    वापस;
            }
        }
    }
    gv2(RC_INT, RC_INT);
    a = ireg(vtop[-1].r);
    b = ireg(vtop[0].r);
    vtop -= 2;
    d = get_reg(RC_INT);
    vtop++;
    vtop[0].r = d;
    d = ireg(d);
    चयन (op) {
    शेष:
        अगर (op >= TOK_ULT && op <= TOK_GT) {
            vset_VT_CMP(op);
            vtop->cmp_r = a | b << 8;
            अवरोध;
        }
        tcc_error("implement me: %s(%s)", __FUNCTION__, get_tok_str(op, शून्य));
        अवरोध;

    हाल '+':
        ER(0x33 | ll, 0, d, a, b, 0); // add d, a, b
        अवरोध;
    हाल '-':
        ER(0x33 | ll, 0, d, a, b, 0x20); // sub d, a, b
        अवरोध;
    हाल TOK_SAR:
        ER(0x33 | ll | ll, 5, d, a, b, 0x20); // sra d, a, b
        अवरोध;
    हाल TOK_SHR:
        ER(0x33 | ll | ll, 5, d, a, b, 0); // srl d, a, b
        अवरोध;
    हाल TOK_SHL:
        ER(0x33 | ll, 1, d, a, b, 0); // sll d, a, b
        अवरोध;
    हाल '*':
        ER(0x33 | ll, 0, d, a, b, 1); // mul d, a, b
        अवरोध;
    हाल '/':
    हाल TOK_PDIV:
        ER(0x33 | ll, 4, d, a, b, 1); // div d, a, b
        अवरोध;
    हाल '&':
        ER(0x33, 7, d, a, b, 0); // and d, a, b
        अवरोध;
    हाल '^':
        ER(0x33, 4, d, a, b, 0); // xor d, a, b
        अवरोध;
    हाल '|':
        ER(0x33, 6, d, a, b, 0); // or d, a, b
        अवरोध;
    हाल '%':
        ER(ll ? 0x3b:  0x33, 6, d, a, b, 1); // rem d, a, b
        अवरोध;
    हाल TOK_UMOD:
        ER(0x33 | ll, 7, d, a, b, 1); // remu d, a, b
        अवरोध;
    हाल TOK_UDIV:
        ER(0x33 | ll, 5, d, a, b, 1); // divu d, a, b
        अवरोध;
    }
}

ST_FUNC व्योम gen_opi(पूर्णांक op)
{
    gen_opil(op, 0);
}

ST_FUNC व्योम gen_opl(पूर्णांक op)
{
    gen_opil(op, 1);
}

ST_FUNC व्योम gen_opf(पूर्णांक op)
{
    पूर्णांक rs1, rs2, rd, dbl, invert;
    अगर (vtop[0].type.t == VT_LDOUBLE) {
        CType type = vtop[0].type;
        पूर्णांक func = 0;
        पूर्णांक cond = -1;
        चयन (op) {
        हाल '*': func = TOK___multf3; अवरोध;
        हाल '+': func = TOK___addtf3; अवरोध;
        हाल '-': func = TOK___subtf3; अवरोध;
        हाल '/': func = TOK___divtf3; अवरोध;
        हाल TOK_EQ: func = TOK___eqtf2; cond = 1; अवरोध;
        हाल TOK_NE: func = TOK___netf2; cond = 0; अवरोध;
        हाल TOK_LT: func = TOK___lttf2; cond = 10; अवरोध;
        हाल TOK_GE: func = TOK___getf2; cond = 11; अवरोध;
        हाल TOK_LE: func = TOK___letf2; cond = 12; अवरोध;
        हाल TOK_GT: func = TOK___gttf2; cond = 13; अवरोध;
        शेष: निश्चित(0); अवरोध;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = REG_IRET;
        vtop->r2 = cond < 0 ? TREG_R(1) : VT_CONST;
        अगर (cond < 0)
            vtop->type = type;
        अन्यथा {
            vpushi(0);
            gen_opil(op, 1);
        }
        वापस;
    }

    gv2(RC_FLOAT, RC_FLOAT);
    निश्चित(vtop->type.t == VT_DOUBLE || vtop->type.t == VT_FLOAT);
    dbl = vtop->type.t == VT_DOUBLE;
    rs1 = freg(vtop[-1].r);
    rs2 = freg(vtop->r);
    vtop--;
    invert = 0;
    चयन(op) {
    शेष:
        निश्चित(0);
    हाल '+':
        op = 0; // fadd
    arithop:
        rd = get_reg(RC_FLOAT);
        vtop->r = rd;
        rd = freg(rd);
        ER(0x53, 7, rd, rs1, rs2, dbl | (op << 2)); // fop.[sd] RD, RS1, RS2 (dyn rm)
        अवरोध;
    हाल '-':
        op = 1; // fsub
        जाओ arithop;
    हाल '*':
        op = 2; // fmul
        जाओ arithop;
    हाल '/':
        op = 3; // fdiv
        जाओ arithop;
    हाल TOK_EQ:
        op = 2; // EQ
    cmpop:
        rd = get_reg(RC_INT);
        vtop->r = rd;
        rd = ireg(rd);
        ER(0x53, op, rd, rs1, rs2, dbl | 0x50); // fcmp.[sd] RD, RS1, RS2 (op == eq/lt/le)
        अगर (invert)
          EI(0x13, 4, rd, rd, 1); // xori RD, 1

        /* generate VT_CMP output */
        vset_VT_CMP(TOK_NE);
        vtop->cmp_r = rd | (0 << 8);
        अवरोध;
    हाल TOK_NE:
        invert = 1;
        op = 2; // EQ
        जाओ cmpop;
    हाल TOK_LT:
        op = 1; // LT
        जाओ cmpop;
    हाल TOK_LE:
        op = 0; // LE
        जाओ cmpop;
    हाल TOK_GT:
        op = 1; // LT
        rd = rs1, rs1 = rs2, rs2 = rd;
        जाओ cmpop;
    हाल TOK_GE:
        op = 0; // LE
        rd = rs1, rs1 = rs2, rs2 = rd;
        जाओ cmpop;
    }
}

ST_FUNC व्योम gen_cvt_csti(पूर्णांक t)
{
    पूर्णांक r = ireg(gv(RC_INT));
    अगर ((t & VT_BTYPE) == VT_SHORT) {
        अगर (t & VT_UNSIGNED) {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EI(0x13, 5, r, r, 48); // srli r, r, 48
        } अन्यथा {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EIu(0x13, 5, r, r, 0x400 | 48); // srai r, r, 48
        }
    } अन्यथा {
        अगर (t & VT_UNSIGNED) {
            EI(0x13, 7, r, r, 0xff); // andi r, r, 0xff
        } अन्यथा {
            EI(0x13, 1, r, r, 56); // slli r, r, 56
            EIu(0x13, 5, r, r, 0x400 | 56); // srai r, r, 56
        }
    }
}

ST_FUNC व्योम gen_cvt_sxtw(व्योम)
{
    पूर्णांक r = ireg(gv(RC_INT));
    EI(0x1b, 0, r, r, 0); // addiw r, r, 0
}

ST_FUNC व्योम gen_cvt_itof(पूर्णांक t)
{
    पूर्णांक rr = ireg(gv(RC_INT)), dr;
    पूर्णांक u = vtop->type.t & VT_UNSIGNED;
    पूर्णांक l = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    अगर (t == VT_LDOUBLE) {
        पूर्णांक func = l ?
          (u ? TOK___floatunditf : TOK___floatditf) :
          (u ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        vtop->r2 = TREG_R(1);
    } अन्यथा {
        vtop--;
        dr = get_reg(RC_FLOAT);
        vtop++;
        vtop->r = dr;
        dr = freg(dr);
        EIu(0x53, 7, dr, rr, ((0x68 | (t == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[sd].[wl][u]
    }
}

ST_FUNC व्योम gen_cvt_ftoi(पूर्णांक t)
{
    पूर्णांक ft = vtop->type.t & VT_BTYPE;
    पूर्णांक l = (t & VT_BTYPE) == VT_LLONG;
    पूर्णांक u = t & VT_UNSIGNED;
    अगर (ft == VT_LDOUBLE) {
        पूर्णांक func = l ?
          (u ? TOK___fixunstfdi : TOK___fixtfdi) :
          (u ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
    } अन्यथा {
        पूर्णांक rr = freg(gv(RC_FLOAT)), dr;
        vtop--;
        dr = get_reg(RC_INT);
        vtop++;
        vtop->r = dr;
        dr = ireg(dr);
        EIu(0x53, 1, dr, rr, ((0x60 | (ft == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[wl][u].[sd] rtz
    }
}

ST_FUNC व्योम gen_cvt_ftof(पूर्णांक dt)
{
    पूर्णांक st = vtop->type.t & VT_BTYPE, rs, rd;
    dt &= VT_BTYPE;
    अगर (st == dt)
      वापस;
    अगर (dt == VT_LDOUBLE || st == VT_LDOUBLE) {
        पूर्णांक func = (dt == VT_LDOUBLE) ?
            (st == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (dt == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        /* We can't use gfunc_call, as func_old_type works like vararg
           functions, and on riscv unnamed float args are passed like
           integers.  But we really need them in the float argument registers
           for extendsftf2/extenddftf2.  So, do it explicitely.  */
        save_regs(1);
        अगर (dt == VT_LDOUBLE)
          gv(RC_F(0));
        अन्यथा {
            gv(RC_R(0));
            निश्चित(vtop->r2 < 7);
            अगर (vtop->r2 != 1 + vtop->r) {
                EI(0x13, 0, ireg(vtop->r) + 1, ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = 1 + vtop->r;
            }
        }
        vpush_helper_func(func);
        gcall_or_jmp(1);
        vtop -= 2;
        vpushi(0);
        vtop->type.t = dt;
        अगर (dt == VT_LDOUBLE)
          vtop->r = REG_IRET, vtop->r2 = REG_IRET+1;
        अन्यथा
          vtop->r = REG_FRET;
    } अन्यथा {
        निश्चित (dt == VT_FLOAT || dt == VT_DOUBLE);
        निश्चित (st == VT_FLOAT || st == VT_DOUBLE);
        rs = gv(RC_FLOAT);
        rd = get_reg(RC_FLOAT);
        अगर (dt == VT_DOUBLE)
          EI(0x53, 0, freg(rd), freg(rs), 0x21 << 5); // fcvt.d.s RD, RS (no rm)
        अन्यथा
          EI(0x53, 7, freg(rd), freg(rs), (0x20 << 5) | 1); // fcvt.s.d RD, RS (dyn rm)
        vtop->r = rd;
    }
}

/* increment tcov counter */
ST_FUNC व्योम gen_increment_tcov (SValue *sv)
{
    पूर्णांक r1, r2;
    Sym label = {0};
    label.type.t = VT_VOID | VT_STATIC;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    r1 = ireg(r1);
    r2 = ireg(r2);
    greloca(cur_text_section, sv->sym, ind, R_RISCV_PCREL_HI20, 0);
    put_extern_sym(&label, cur_text_section, ind, 0);
    o(0x17 | (r1 << 7)); // auipc RR, 0 %pcrel_hi(sym)
    greloca(cur_text_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, r2, r1, 0); // ld r2, x[r1]
    EI(0x13, 0, r2, r2, 1); // addi r2, r2, #1
    greloca(cur_text_section, sv->sym, ind, R_RISCV_PCREL_HI20, 0);
    label.c = 0; /* force new local ELF symbol */
    put_extern_sym(&label, cur_text_section, ind, 0);
    o(0x17 | (r1 << 7)); // auipc RR, 0 %pcrel_hi(sym)
    greloca(cur_text_section, &label, ind, R_RISCV_PCREL_LO12_S, 0);
    ES(0x23, 3, r1, r2, 0); // sd r2, [r1]
    vpop();
}

ST_FUNC व्योम ggoto(व्योम)
{
    gcall_or_jmp(0);
    vtop--;
}

ST_FUNC व्योम gen_vla_sp_save(पूर्णांक addr)
{
    अगर (निचला_OVERFLOW(addr)) {
	o(0x37 | (5 << 7) | UPPER(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        ES(0x23, 3, 5, 2, SIGN11(addr)); // sd sp, fc(t0)
    }
    अन्यथा
        ES(0x23, 3, 8, 2, addr); // sd sp, fc(s0)
}

ST_FUNC व्योम gen_vla_sp_restore(पूर्णांक addr)
{
    अगर (निचला_OVERFLOW(addr)) {
	o(0x37 | (5 << 7) | UPPER(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        EI(0x03, 3, 2, 5, SIGN11(addr)); // ld sp, fc(t0)
    }
    अन्यथा
        EI(0x03, 3, 2, 8, addr); // ld sp, fc(s0)
}

ST_FUNC व्योम gen_vla_alloc(CType *type, पूर्णांक align)
{
    पूर्णांक rr;
#अगर defined(CONFIG_TCC_BCHECK)
    अगर (tcc_state->do_bounds_check)
        vpushv(vtop);
#पूर्ण_अगर
    rr = ireg(gv(RC_INT));
#अगर defined(CONFIG_TCC_BCHECK)
    अगर (tcc_state->do_bounds_check)
        EI(0x13, 0, rr, rr, 15+1);   // addi RR, RR, 15+1
    अन्यथा
#पूर्ण_अगर
    EI(0x13, 0, rr, rr, 15);   // addi RR, RR, 15
    EI(0x13, 7, rr, rr, -16);  // andi, RR, RR, -16
    ER(0x33, 0, 2, 2, rr, 0x20); // sub sp, sp, rr
    vpop();
#अगर defined(CONFIG_TCC_BCHECK)
    अगर (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x00010513); /* mv a0,sp */
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_add_epilog = 1;
    }
#पूर्ण_अगर
}

ST_FUNC व्योम gen_clear_cache(व्योम)
{
    /* Zifencei extension: fence + fence.i for I/D synchronization.
       Required by RISC-V Linux ABI, present on all Linux-capable cores. */
    o(0x0ff0000f); // fence iorw, iorw
    o(0x0000100f); // fence.i
}
#पूर्ण_अगर
