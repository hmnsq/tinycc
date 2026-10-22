#اگر_تعریف_شده هدف_DEFS_ONLY

// Number of registers available to allocator:
#تعریف_کن NB_REGS 19 // x10-x17 aka a0-a7, f10-f17 aka fa0-fa7, xxx, ra, sp
#تعریف_کن CONFIG_TCC_ASM

#تعریف_کن TREG_R(x) (x) // x = 0..7
#تعریف_کن TREG_F(x) (x + 8) // x = 0..7

// Register classes sorted from more general to more precise:
#تعریف_کن RC_INT (1 << 0)
#تعریف_کن RC_FLOAT (1 << 1)
#تعریف_کن RC_R(x) (1 << (2 + (x))) // x = 0..7
#تعریف_کن RC_F(x) (1 << (10 + (x))) // x = 0..7

#تعریف_کن RC_IRET (RC_R(0)) // int return register class
#تعریف_کن RC_IRE2 (RC_R(1)) // int 2nd return register class
#تعریف_کن RC_FRET (RC_F(0)) // float return register class

#تعریف_کن REG_IRET (TREG_R(0)) // int return register number
#تعریف_کن REG_IRE2 (TREG_R(1)) // int 2nd return register number
#تعریف_کن REG_FRET (TREG_F(0)) // float return register number

#تعریف_کن PTR_اندازه 8

#تعریف_کن LDOUBLE_اندازه 16
#تعریف_کن LDOUBLE_ALIGN 16

#تعریف_کن MAX_ALIGN 16

#تعریف_کن CHAR_IS_UNSIGNED

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#تعریف_کن PROMOTE_RET

#وإلا
#تعریف_کن USING_GLOBALS
#ضمن "tcc.h"
#ضمن <assert.h>

#تعریف_کن فوقانی_2(x)	(((بیعلامت)(x) + 0x800u) & 0xfffff000)
#تعریف_کن کم_سرریز(x)	فوقانی_2(x)
#تعریف_کن SIGN7(x)	((((x) & 0xff) ^ 0x80) - 0x80)
#تعریف_کن SIGN11(x)	((((x) & 0xfff) ^ 0x800) - 0x800)

ST_داده ثابت حرف * ثابت هدف_machine_defs =
    "__riscv\0"
    "__riscv_xlen 64\0"
    "__riscv_flen 64\0"
    "__riscv_div\0"
    "__riscv_mul\0"
    "__riscv_fdiv\0"
    "__riscv_fsqrt\0"
    "__riscv_float_abi_double\0"
    ;

#تعریف_کن XLEN 8

#تعریف_کن TREG_RA 17
#تعریف_کن TREG_SP 18

ST_داده ثابت صحيح reg_classes[NB_REGS] = {
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

#إذا defined(CONFIG_TCC_BCHECK)
ساكن addr_t func_bound_جابه_جایی;
ساكن بیعلامت دراز func_bound_ind;
ST_داده صحيح func_bound_جمع_کن_epilog;
#پایان_اگر

ساكن صحيح ireg(صحيح r)
{
    إذا (r == TREG_RA)
      أرجع 1; // ra
    إذا (r == TREG_SP)
      أرجع 2; // sp
    أكد(r >= 0 && r < 8);
    أرجع r + 10;  // tccrX --> aX == x(10+X)
}

ساكن صحيح is_ireg(صحيح r)
{
    أرجع (بیعلامت)r < 8 || r == TREG_RA || r == TREG_SP;
}

ساكن صحيح freg(صحيح r)
{
    أكد(r >= 8 && r < 16);
    أرجع r - 8 + 10;  // tccfX --> faX == f(10+X)
}

ساكن صحيح is_freg(صحيح r)
{
    أرجع r >= 8 && r < 16;
}

ST_FUNC فراغ o(بیعلامت صحيح c)
{
    صحيح ind1 = ind + 4;
    إذا (nocode_wanted)
        أرجع;
    إذا (ind1 > cur_متن_section->داده_allocated)
        section_realloc(cur_متن_section, ind1);
    write32le(cur_متن_section->داده + ind, c);
    ind = ind1;
}

ساكن فراغ EIu(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    o(opcode | (func3 << 12) | (rd << 7) | (rs1 << 15) | (imm << 20));
}

ساكن فراغ ER(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t func7)
{
    o(opcode | func3 << 12 | rd << 7 | rs1 << 15 | rs2 << 20 | func7 << 25);
}

ساكن فراغ EI(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    أكد(! کم_سرریز(imm));
    EIu(opcode, func3, rd, rs1, imm);
}

ساكن فراغ ES(uint32_t opcode, uint32_t func3,
               uint32_t rs1, uint32_t rs2, uint32_t imm)
{
    أكد(! کم_سرریز(imm));
    o(opcode | (func3 << 12) | ((imm & 0x1f) << 7) | (rs1 << 15)
      | (rs2 << 20) | ((imm >> 5) << 25));
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC فراغ gsym_addr(صحيح t_, صحيح a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    طالما (t) {
        بیعلامت حرف *ptr = cur_متن_section->داده + t;
        uint32_t بعدی = read32le(ptr);
        uint32_t r = a - t, imm;
        إذا ((r + (1 << 21)) & ~((1U << 22) - 2))
          tcc_error("out-of-range branch chain");
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        write32le(ptr, r == 4 ? 0x33 : 0x6f | imm); // nop || j imm
        t = بعدی;
    }
}

ساكن صحيح بارگیری_symofs(صحيح r, SValue *sv, صحيح forstore, صحيح *new_fc)
{
    صحيح rr, doload = 0, large_addend = 0;
    صحيح fc = sv->c.i, v = sv->r & VT_VALMASK;
    إذا (sv->r & VT_SYM) {
        Sym label = {0};
        أكد(v == VT_CONST);
        إذا (sv->sym->type.t & VT_TLS) {
            /* TLS Local Exec model: lui + addi + add tp */
            rr = is_ireg(r) ? ireg(r) : 5;
            greloca(cur_متن_section, sv->sym, ind,
                    R_RISCV_TPREL_HI20, sv->c.i);
            o(0x37 | (rr << 7));  // lui RR, 0 %tprel_hi(sym)
            greloca(cur_متن_section, sv->sym, ind,
                    R_RISCV_TPREL_LO12_I, sv->c.i);
            EI(0x13, 0, rr, rr, 0); // addi RR, RR, 0 %tprel_lo(sym)
            ER(0x33, 0, rr, rr, 4, 0); // add RR, RR, tp
            *new_fc = 0;
            أرجع rr;
        }
        إذا (sv->sym->type.t & VT_STATIC) { // XXX do this per linker relax
            greloca(cur_متن_section, sv->sym, ind,
                    R_RISCV_PCREL_HI20, sv->c.i);
            *new_fc = 0;
        } وإلا {
            إذا (کم_سرریز(fc)){
              large_addend = 1;
            }
            greloca(cur_متن_section, sv->sym, ind,
                    R_RISCV_GOT_HI20, 0);
            doload = 1;
        }
        label.type.t = VT_VOID | VT_STATIC;
	إذا (!nocode_wanted)
            put_extern_sym(&label, cur_متن_section, ind, 0);
        rr = is_ireg(r) ? ireg(r) : 5;
        o(0x17 | (rr << 7));   // auipc RR, 0 %pcrel_hi(sym)+addend
        greloca(cur_متن_section, &label, ind,
                doload || !forstore
                  ? R_RISCV_PCREL_LO12_I : R_RISCV_PCREL_LO12_S, 0);
        إذا (doload) {
            EI(0x03, 3, rr, rr, 0); // ld RR, 0(RR)
            إذا (large_addend) {
                o(0x37 | (6 << 7) | فوقانی_2(fc)); //lui t1, high(fc)
                ER(0x33, 0, rr, rr, 6, 0); // add RR, RR, t1
                *new_fc = SIGN11(fc);
            }
        }
    } وإلا إذا (v == VT_LOCAL || v == VT_LLOCAL) {
        rr = 8; // s0
        إذا (fc != sv->c.i)
          tcc_error("unimp: store(giant local off) (0x%lx)", (دراز)sv->c.i);
        إذا (کم_سرریز(fc)) {
            rr = is_ireg(r) ? ireg(r) : 5; // t0
            o(0x37 | (rr << 7) | فوقانی_2(fc)); //lui RR, upper(fc)
            ER(0x33, 0, rr, rr, 8, 0); // add RR, RR, s0
            *new_fc = SIGN11(fc);
        }
    } وإلا
      tcc_error("uhh");
    أرجع rr;
}

ساكن فراغ بارگیری_large_constant(صحيح rr, صحيح fc, uint32_t pi)
{
    إذا (fc < 0)
	pi++;
    o(0x37 | (rr << 7) | فوقانی_2(pi)); // lui RR, up(up(fc))
    EI(0x13, 0, rr, rr, SIGN11(pi));   // addi RR, RR, lo(up(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((بیعلامت)fc + (1 << 19)) >> 20)); // addi RR, RR, up(lo(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((بیعلامت)fc + (1 << 7)) >> 8));  // addi RR, RR, lo1(lo(fc))
    EI(0x13, 1, rr, rr, 8); // slli RR, RR, 8
}

ST_FUNC فراغ بارگیری(صحيح r, SValue *sv)
{
    صحيح fr = sv->r;
    صحيح v = fr & VT_VALMASK;
    صحيح rr = is_ireg(r) ? ireg(r) : freg(r);
    صحيح fc = sv->c.i;
    صحيح bt = sv->type.t & VT_BTYPE;
    صحيح align, اندازه;
    إذا (fr & VT_LVAL) {
        صحيح func3, opcode = is_freg(r) ? 0x07 : 0x03, br;
        اندازه = type_اندازه(&sv->type, &align);
        أكد (!is_freg(r) || bt == VT_FLOAT || bt == VT_DOUBLE);
        إذا (bt == VT_PTR || bt == VT_FUNC) /* XXX should be done in generic code */
          اندازه = PTR_اندازه;
        func3 = اندازه == 1 ? 0 : اندازه == 2 ? 1 : اندازه == 4 ? 2 : 3;
        إذا (اندازه < 4 && !is_float(sv->type.t) && (sv->type.t & VT_UNSIGNED))
          func3 |= 4;
        إذا (v == VT_LOCAL || (fr & VT_SYM)) {
            br = بارگیری_symofs(r, sv, 0, &fc);
        } وإلا إذا (v < VT_CONST) {
            br = ireg(v);
            /*if (LOW_OVERFLOW(fc))
              tcc_error("unimp: load(large addend) (0x%x)", fc);*/
            fc = 0; // XXX store ofs in LVAL(reg)
        } وإلا إذا (v == VT_LLOCAL) {
            br = بارگیری_symofs(r, sv, 0, &fc);
            EI(0x03, 3, rr, br, fc); // ld RR, fc(BR)
            br = rr;
            fc = 0;
        } وإلا إذا (v == VT_CONST) {
            int64_t si = sv->c.i;
            si >>= 32;
            إذا (si != 0) {
		بارگیری_large_constant(rr, fc, si);
                fc = SIGN7(fc);
            } وإلا {
                o(0x37 | (rr << 7) | فوقانی_2(fc)); //lui RR, upper(fc)
                fc = SIGN11(fc);
	    }
            br = rr;
	} وإلا {
            tcc_error("unimp: load(non-local lval)");
        }
        EI(opcode, func3, rr, br, fc); // l[bhwd][u] / fl[wd] RR, fc(BR)
    } وإلا إذا (v == VT_CONST) {
        صحيح rb = 0, do32bit = 8, zext = 0;
        إذا (is_float(sv->type.t) && bt != VT_LDOUBLE) {
            /* load float/double constant: move bit pattern from int reg */
            uint64_t val = sv->c.i;
            صحيح is_dbl = bt == VT_DOUBLE;
            إذا (val == 0) {
                o(0x53 | (rr << 7) | ((بیعلامت)(0x78 | is_dbl) << 25));
                أرجع;
            }
            إذا (is_dbl) {
                بارگیری_large_constant(6, (صحيح)val, (صحيح)(val >> 32));
            } وإلا {
                إذا (کم_سرریز(fc))
                    o(0x37 | (6 << 7) | فوقانی_2(fc)); // lui t1, upper
                EI(0x13 | 8, 0, 6, کم_سرریز(fc) ? 6 : 0, SIGN11(fc)); // addiw t1,...
            }
            o(0x53 | (rr << 7) | (6 << 15) | ((بیعلامت)(0x78 | is_dbl) << 25));
            أرجع;
        }
        أكد(is_ireg(r) || bt == VT_LDOUBLE);
        إذا (fr & VT_SYM) {
            rb = بارگیری_symofs(r, sv, 0, &fc);
            do32bit = 0;
        }
        إذا (do32bit && fc != sv->c.i) {
            int64_t si = sv->c.i;
            si >>= 32;
            إذا (si != 0) {
		بارگیری_large_constant(rr, fc, si);
                fc = SIGN7(fc);
                rb = rr;
                do32bit = 0;
            } وإلا إذا (bt == VT_LLONG) {
                /* A 32bit unsigned constant for a 64bit type.
                   lui always sign extends, so we need to do an explicit zext.*/
                zext = 1;
            }
        }
        إذا (کم_سرریز(fc))
            o(0x37 | (rr << 7) | فوقانی_2(fc)), rb = rr; //lui RR, upper(fc)
        إذا (fc || (rr != rb) || do32bit || (fr & VT_SYM))
          EI(0x13 | do32bit, 0, rr, rb, SIGN11(fc)); // addi[w] R, x0|R, FC
        إذا (zext) {
            EI(0x13, 1, rr, rr, 32); // slli RR, RR, 32
            EI(0x13, 5, rr, rr, 32); // srli RR, RR, 32
        }
    } وإلا إذا (v == VT_LOCAL) {
        صحيح br = بارگیری_symofs(r, sv, 0, &fc);
        أكد(is_ireg(r));
        EI(0x13, 0, rr, br, fc); // addi R, s0, FC
    } وإلا إذا (v < VT_CONST) { /* reg-reg */
        //assert(!fc); XXX support offseted regs
        إذا (is_freg(r) && is_freg(v))
          ER(0x53, 0, rr, freg(v), freg(v), bt == VT_DOUBLE ? 0x11 : 0x10); //fsgnj.[sd] RR, V, V == fmv.[sd] RR, V
        وإلا إذا (is_ireg(r) && is_ireg(v))
          EI(0x13, 0, rr, ireg(v), 0); // addi RR, V, 0 == mv RR, V
        وإلا {
            صحيح func7 = is_ireg(r) ? 0x70 : 0x78;
            اندازه = type_اندازه(&sv->type, &align);
            إذا (اندازه == 8)
              func7 |= 1;
            أكد(اندازه == 4 || اندازه == 8);
            o(0x53 | (rr << 7) | ((is_freg(v) ? freg(v) : ireg(v)) << 15)
              | ((بیعلامت)func7 << 25)); // fmv.{w.x, x.w, d.x, x.d} RR, VR
        }
    } وإلا إذا (v == VT_CMP) {
        صحيح op = vtop->cmp_op;
        صحيح a = vtop->cmp_r & 0xff;
        صحيح b = (vtop->cmp_r >> 8) & 0xff;
        صحيح inv = 0;
        بدل (op) {
            حالة TOK_ULT:
            حالة TOK_UGE:
            حالة TOK_ULE:
            حالة TOK_UGT:
            حالة TOK_LT:
            حالة TOK_GE:
            حالة TOK_LE:
            حالة TOK_GT:
                إذا (op & 1) { // remove [U]GE,GT
                    inv = 1;
                    op--;
                }
                إذا ((op & 7) == 6) { // [U]LE
                    صحيح t = a; a = b; b = t;
                    inv ^= 1;
                }
                ER(0x33, (op > TOK_UGT) ? 2 : 3, rr, a, b, 0); // slt[u] d, a, b
                إذا (inv)
                  EI(0x13, 4, rr, rr, 1); // xori d, d, 1
                اكسر;
            حالة TOK_NE:
            حالة TOK_EQ:
                إذا (rr != a || b)
                  ER(0x33, 0, rr, a, b, 0x20); // sub d, a, b
                إذا (op == TOK_NE)
                  ER(0x33, 3, rr, 0, rr, 0); // sltu d, x0, d == snez d,d
                وإلا
                  EI(0x13, 3, rr, rr, 1); // sltiu d, d, 1 == seqz d,d
                اكسر;
        }
    } وإلا إذا ((v & ~1) == VT_JMP) {
        صحيح t = v & 1;
        أكد(is_ireg(r));
        EI(0x13, 0, rr, 0, t);      // addi RR, x0, t
        gjmp_addr(ind + 8);
        gsym(fc);
        EI(0x13, 0, rr, 0, t ^ 1);  // addi RR, x0, !t
    } وإلا
      tcc_error("unimp: load(non-const)");
}

ST_FUNC فراغ store(صحيح r, SValue *sv)
{
    صحيح fr = sv->r & VT_VALMASK;
    صحيح rr = is_ireg(r) ? ireg(r) : freg(r), ptrreg;
    صحيح fc = sv->c.i;
    صحيح bt = sv->type.t & VT_BTYPE;
    صحيح align, اندازه = type_اندازه(&sv->type, &align);
    أكد(!is_float(bt) || is_freg(r) || bt == VT_LDOUBLE);
    /* long doubles are in two integer registers, but the load/store
       primitives only deal with one, so do as if it's one reg.  */
    إذا (bt == VT_LDOUBLE)
      اندازه = align = 8;
    إذا (bt == VT_STRUCT)
      tcc_error("unimp: store(struct)");
    إذا (اندازه > 8)
      tcc_error("unimp: large sized store");
    أكد(sv->r & VT_LVAL);
    إذا (fr == VT_LOCAL || (sv->r & VT_SYM)) {
        ptrreg = بارگیری_symofs(-1, sv, 1, &fc);
    } وإلا إذا (fr < VT_CONST) {
        ptrreg = ireg(fr);
        /*if (LOW_OVERFLOW(fc))
          tcc_error("unimp: store(large addend) (0x%x)", fc);*/
        fc = 0; // XXX support offsets regs
    } وإلا إذا (fr == VT_CONST) {
        int64_t si = sv->c.i;
        ptrreg = 8; // s0
        si >>= 32;
        إذا (si != 0) {
	    بارگیری_large_constant(ptrreg, fc, si);
            fc = SIGN7(fc);
        } وإلا {
            o(0x37 | (ptrreg << 7) | فوقانی_2(fc)); //lui RR, upper(fc)
            fc = SIGN11(fc);
	}
    } وإلا
      tcc_error("implement me: %s(!local)", __FUNCTION__);
    ES(is_freg(r) ? 0x27 : 0x23,                          // fs... | s...
       اندازه == 1 ? 0 : اندازه == 2 ? 1 : اندازه == 4 ? 2 : 3, // ... [wd] | [bhwd]
       ptrreg, rr, fc);                                   // RR, fc(base)
}

ساكن فراغ gcall_or_jmp(صحيح docall)
{
    صحيح tr = docall ? 1 : 5; // ra or t0
    إذا ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
        ((vtop->r & VT_SYM) && vtop->c.i == (صحيح)vtop->c.i)) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_متن_section, vtop->sym, ind,
                R_RISCV_CALL_PLT, (صحيح)vtop->c.i);
        o(0x17 | (tr << 7));   // auipc TR, 0 %call(func)
        EI(0x67, 0, tr, tr, 0);// jalr  TR, r(TR)
    } وإلا إذا (vtop->r < VT_CONST) {
        صحيح r = ireg(vtop->r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    } وإلا {
        صحيح r = TREG_RA;
        بارگیری(r, vtop);
        r = ireg(r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    }
}

#إذا defined(CONFIG_TCC_BCHECK)

ساكن فراغ gen_bounds_call(صحيح v)
{
    Sym *sym = external_helper_sym(v);

    greloca(cur_متن_section, sym, ind, R_RISCV_CALL_PLT, 0);
    o(0x17 | (1 << 7));   // auipc TR, 0 %call(func)
    EI(0x67, 0, 1, 1, 0); // jalr  TR, r(TR)
}

ساكن فراغ gen_bounds_prolog(فراغ)
{
    /* leave some room for bound checking code */
    func_bound_جابه_جایی = lbounds_section->داده_جابه_جایی;
    func_bound_ind = ind;
    func_bound_جمع_کن_epilog = 0;
    o(0x00000013);  /* ld a0,#lbound section pointer */
    o(0x00000013);
    o(0x00000013);  /* nop -> call __bound_local_new */
    o(0x00000013);
}

ساكن فراغ gen_bounds_epilog(فراغ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_داده;
    Sym label = {0};

    صحيح جابه_جایی_modified = func_bound_جابه_جایی != lbounds_section->داده_جابه_جایی;

    إذا (!جابه_جایی_modified && !func_bound_جمع_کن_epilog)
        أرجع;

    /* add end of table info */
    bounds_ptr = section_ptr_جمع_کن(lbounds_section, حجم(addr_t));
    *bounds_ptr = 0;

    sym_داده = get_sym_ref(&char_اشاره_گر_type, lbounds_section,
                           func_bound_جابه_جایی, PTR_اندازه);

    label.type.t = VT_VOID | VT_STATIC;
    /* generate bound local allocation */
    إذا (جابه_جایی_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        put_extern_sym(&label, cur_متن_section, ind, 0);
        greloca(cur_متن_section, sym_داده, ind, R_RISCV_GOT_HI20, 0);
        o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
        greloca(cur_متن_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
        EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
        gen_bounds_call(TOK___bound_local_new);
        ind = saved_ind;
        label.c = 0; /* force new local ELF symbol */
    }

    /* generate bound check local freeing */
    o(0xe02a1101); /* addi sp,sp,-32  sd   a0,0(sp)   */
    o(0xa82ae42e); /* sd   a1,8(sp)   fsd  fa0,16(sp) */
    put_extern_sym(&label, cur_متن_section, ind, 0);
    greloca(cur_متن_section, sym_داده, ind, R_RISCV_GOT_HI20, 0);
    o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
    greloca(cur_متن_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
    gen_bounds_call(TOK___bound_local_delete);
    o(0x65a26502); /* ld   a0,0(sp)   ld   a1,8(sp)   */
    o(0x61052542); /* fld  fa0,16(sp) addi sp,sp,32   */
}
#پایان_اگر

ساكن فراغ reg_pass_rec(CType *type, صحيح *rc, صحيح *fieldofs, صحيح ofs)
{
    إذا ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *f;
        إذا (type->ref->type.t == VT_UNION)
          rc[0] = -1;
        وإلا لكل (f = type->ref->بعدی; f; f = f->بعدی)
          reg_pass_rec(&f->type, rc, fieldofs, ofs + f->c);
    } وإلا إذا (type->t & VT_ARRAY) {
        إذا (type->ref->c < 0 || type->ref->c > 2)
          rc[0] = -1;
        وإلا {
            صحيح a, sz = type_اندازه(&type->ref->type, &a);
            reg_pass_rec(&type->ref->type, rc, fieldofs, ofs);
            إذا (rc[0] > 2 || (rc[0] == 2 && type->ref->c > 1))
              rc[0] = -1;
            وإلا إذا (type->ref->c == 2 && rc[0] && rc[1] == RC_FLOAT) {
              rc[++rc[0]] = RC_FLOAT;
              fieldofs[rc[0]] = ((ofs + sz) << 4)
                                | (type->ref->type.t & VT_BTYPE);
            } وإلا إذا (type->ref->c == 2)
              rc[0] = -1;
        }
    } وإلا إذا (rc[0] == 2 || rc[0] < 0 || (type->t & VT_BTYPE) == VT_LDOUBLE)
      rc[0] = -1;
    وإلا إذا (!rc[0] || rc[1] == RC_FLOAT || is_float(type->t)) {
      rc[++rc[0]] = is_float(type->t) ? RC_FLOAT : RC_INT;
      fieldofs[rc[0]] = (ofs << 4) | ((type->t & VT_BTYPE) == VT_PTR ? VT_LLONG : type->t & VT_BTYPE);
    } وإلا
      rc[0] = -1;
}

ساكن فراغ reg_pass(CType *type, صحيح *prc, صحيح *fieldofs, صحيح named)
{
    prc[0] = 0;
    reg_pass_rec(type, prc, fieldofs, 0);
    إذا (prc[0] <= 0 || !named) {
        صحيح align, اندازه = type_اندازه(type, &align);
        prc[0] = (اندازه + 7) >> 3;
        prc[1] = prc[2] = RC_INT;
        fieldofs[1] = (0 << 4) | (اندازه <= 1 ? VT_BYTE : اندازه <= 2 ? VT_SHORT : اندازه <= 4 ? VT_INT : VT_LLONG);
        fieldofs[2] = (8 << 4) | (اندازه <= 9 ? VT_BYTE : اندازه <= 10 ? VT_SHORT : اندازه <= 12 ? VT_INT : VT_LLONG);
    }
}

ST_FUNC فراغ gfunc_call(صحيح nb_آرگومانها)
{
    صحيح i, align, اندازه, areg[2];
    صحيح *info = tcc_malloc((nb_آرگومانها + 1) * حجم (صحيح));
    صحيح پشته_adj = 0, tempspace = 0, پشته_جمع_کن, ofs, splitofs = 0;
    صحيح old = (vtop[-nb_آرگومانها].type.ref->f.func_type == FUNC_OLD);
    SValue *sv;
    Sym *sa;

#اگر_تعریف_شده CONFIG_TCC_BCHECK
    صحيح bc_save = tcc_state->do_bounds_check;
    إذا (tcc_state->do_bounds_check)
        gbound_آرگومانها(nb_آرگومانها);
#پایان_اگر

    areg[0] = 0; /* int arg regs */
    areg[1] = 8; /* float arg regs */
    sa = vtop[-nb_آرگومانها].type.ref->بعدی;
    لكل (i = 0; i < nb_آرگومانها; i++) {
        صحيح nregs, byref = 0, tempofs;
        صحيح prc[3], fieldofs[3];
        sv = &vtop[1 + i - nb_آرگومانها];
        sv->type.t &= ~VT_ARRAY; // XXX this should be done in tccgen.c
        اندازه = type_اندازه(&sv->type, &align);
        إذا (اندازه > 16) {
            إذا (align < XLEN)
              align = XLEN;
            tempspace = (tempspace + align - 1) & -align;
            tempofs = tempspace;
            tempspace += اندازه;
            اندازه = align = 8;
            byref = 64 | (tempofs << 7);
        }
        reg_pass(&sv->type, prc, fieldofs, old || sa != 0);
        إذا (!old && !sa && align == 2*XLEN && اندازه <= 2*XLEN)
          areg[0] = (areg[0] + 1) & ~1;
        nregs = prc[0];
        إذا (اندازه == 0)
            info[i] = 0;
        وإلا إذا ((prc[1] == RC_INT && areg[0] >= 8)
            || (prc[1] == RC_FLOAT && areg[1] >= 16)
            || (nregs == 2 && prc[1] == RC_FLOAT && prc[2] == RC_FLOAT
                && areg[1] >= 15)
            || (nregs == 2 && prc[1] != prc[2]
                && (areg[1] >= 16 || areg[0] >= 8))) {
            info[i] = 32;
            إذا (align < XLEN)
              align = XLEN;
            پشته_adj += (اندازه + align - 1) & -align;
            إذا (!old && !sa) /* one vararg on stack forces the rest on stack */
              areg[0] = 8, areg[1] = 16;
        } وإلا {
            info[i] = areg[prc[1] - 1]++;
            إذا (!byref)
              info[i] |= (fieldofs[1] & VT_BTYPE) << 12;
            أكد(!(fieldofs[1] >> 4));
            إذا (nregs == 2) {
                إذا (prc[2] == RC_FLOAT || areg[0] < 8)
                  info[i] |= (1 + areg[prc[2] - 1]++) << 7;
                وإلا {
                    info[i] |= 16;
                    پشته_adj += 8;
                }
                إذا (!byref) {
                    أكد((fieldofs[2] >> 4) < 2048);
                    info[i] |= fieldofs[2] << (12 + 4); // includes offset
                }
            }
        }
        info[i] |= byref;
        إذا (sa)
          sa = sa->بعدی;
    }
    پشته_adj = (پشته_adj + 15) & -16;
    tempspace = (tempspace + 15) & -16;
    پشته_جمع_کن = پشته_adj + tempspace;

    إذا (پشته_جمع_کن) {
        إذا (پشته_جمع_کن >= 0x800) {
            o(0x37 | (5 << 7) | فوقانی_2(-پشته_جمع_کن)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(-پشته_جمع_کن)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        وإلا
            EI(0x13, 0, 2, 2, -پشته_جمع_کن);   // addi sp, sp, -adj
        لكل (i = ofs = 0; i < nb_آرگومانها; i++) {
            إذا (info[i] & (64 | 32)) {
                vrotb(nb_آرگومانها - i);
                اندازه = type_اندازه(&vtop->type, &align);
                إذا (info[i] & 64) {
                    vset(&char_اشاره_گر_type, TREG_SP, 0);
                    vpushi(پشته_adj + (info[i] >> 7));
                    gen_op('+');
                    vpushv(vtop); // this replaces the old argument
                    vrott(3);
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vpop();
                    اندازه = align = 8;
                }
                إذا (info[i] & 32) {
                    إذا (align < XLEN)
                      align = XLEN;
                    /* Once we support offseted regs we can do this:
                       vset(&vtop->type, TREG_SP | VT_LVAL, ofs);
                       to construct the lvalue for the outgoing stack slot,
                       until then we have to jump through hoops.  */
                    vset(&char_اشاره_گر_type, TREG_SP, 0);
                    ofs = (ofs + align - 1) & -align;
                    vpushi(ofs);
                    gen_op('+');
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vtop->r = vtop->r2 = VT_CONST; // this arg is done
                    ofs += اندازه;
                }
                vrott(nb_آرگومانها - i);
            } وإلا إذا (info[i] & 16) {
                أكد(!splitofs);
                splitofs = ofs;
                ofs += 8;
            }
        }
    }
    لكل (i = 0; i < nb_آرگومانها; i++) {
        صحيح ii = info[nb_آرگومانها - 1 - i], r = ii, r2 = r;
        إذا (!(r & 32)) {
            CType origtype;
            صحيح loadt;
            r &= 15;
            r2 = r2 & 64 ? 0 : (r2 >> 7) & 31;
            أكد(r2 <= 16);
            vrotb(i+1);
            origtype = vtop->type;
            اندازه = type_اندازه(&vtop->type, &align);
            إذا (اندازه == 0)
                اذهب انجامشده;
            loadt = vtop->type.t & VT_BTYPE;
            إذا (loadt == VT_STRUCT) {
                loadt = (ii >> 12) & VT_BTYPE;
            }
            إذا (info[nb_آرگومانها - 1 - i] & 16) {
                أكد(!r2);
                r2 = 1 + TREG_RA;
            }
            إذا (loadt == VT_LDOUBLE) {
                أكد(r2);
                r2--;
            } وإلا إذا (r2) {
                test_lvalue();
                vpushv(vtop);
            }
            vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
            gv(r < 8 ? RC_R(r) : RC_F(r - 8));
            vtop->type = origtype;

            إذا (r2 && loadt != VT_LDOUBLE) {
                r2--;
                أكد(r2 < 16 || r2 == TREG_RA);
                vswap();
                gaddrof();
                vtop->type = char_اشاره_گر_type;
                vpushi(ii >> 20);
#اگر_تعریف_شده CONFIG_TCC_BCHECK
		إذا ((origtype.t & VT_BTYPE) == VT_STRUCT)
                    tcc_state->do_bounds_check = 0;
#پایان_اگر
                gen_op('+');
#اگر_تعریف_شده CONFIG_TCC_BCHECK
		tcc_state->do_bounds_check = bc_save;
#پایان_اگر
                indir();
                vtop->type = origtype;
                loadt = vtop->type.t & VT_BTYPE;
                إذا (loadt == VT_STRUCT) {
                    loadt = (ii >> 16) & VT_BTYPE;
                }
                save_reg_upstack(r2, 1);
                vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
                بارگیری(r2, vtop);
                أكد(r2 < VT_CONST);
                vtop--;
                vtop->r2 = r2;
            }
            إذا (info[nb_آرگومانها - 1 - i] & 16) {
                ES(0x23, 3, 2, ireg(vtop->r2), splitofs); // sd t0, ofs(sp)
                vtop->r2 = VT_CONST;
            } وإلا إذا (loadt == VT_LDOUBLE && vtop->r2 != r2) {
                أكد(vtop->r2 <= 7 && r2 <= 7);
                /* XXX we'd like to have 'gv' move directly into
                   the right class instead of us fixing it up.  */
                EI(0x13, 0, ireg(r2), ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = r2;
            }
انجامشده:
            vrott(i+1);
        }
    }
    vrotb(nb_آرگومانها + 1);
    save_regs(nb_آرگومانها + 1);
    gcall_or_jmp(1);
    vtop -= nb_آرگومانها + 1;
    إذا (پشته_جمع_کن) {
        إذا (پشته_جمع_کن >= 0x800) {
            o(0x37 | (5 << 7) | فوقانی_2(پشته_جمع_کن)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(پشته_جمع_کن)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        وإلا
            EI(0x13, 0, 2, 2, پشته_جمع_کن);      // addi sp, sp, adj
   }
   tcc_free(info);
}

ساكن صحيح func_sub_sp_جابه_جایی, رقم_va_regs, func_va_list_ofs;

ST_FUNC فراغ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    صحيح i, addr, align, اندازه;
    صحيح param_addr = 0;
    صحيح areg[2];
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    loc = -16; // for ra and s0
    func_sub_sp_جابه_جایی = ind;
    ind += 5 * 4;

    areg[0] = 0, areg[1] = 0;
    addr = 0;
    /* if the function returns by reference, then add an
       implicit pointer parameter */
    اندازه = type_اندازه(&func_vt, &align);
    إذا (اندازه > 2 * XLEN) {
        loc -= 8;
        func_vc = loc;
        ES(0x23, 3, 8, 10 + areg[0]++, loc); // sd a0, loc(s0)
    }
    /* define parameters */
    طالما ((sym = sym->بعدی) != عدم) {
        صحيح byref = 0;
        صحيح regcount;
        صحيح prc[3], fieldofs[3];
        type = &sym->type;
        اندازه = type_اندازه(type, &align);
        إذا (اندازه > 2 * XLEN) {
            type = &char_اشاره_گر_type;
            اندازه = align = byref = 8;
        }
        reg_pass(type, prc, fieldofs, 1);
        regcount = prc[0];
        إذا (areg[prc[1] - 1] >= 8
            || (regcount == 2
                && ((prc[1] == RC_FLOAT && prc[2] == RC_FLOAT && areg[1] >= 7)
                    || (prc[1] != prc[2] && (areg[1] >= 8 || areg[0] >= 8))))) {
            إذا (align < XLEN)
              align = XLEN;
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += اندازه;
        } وإلا {
            loc -= regcount * 8; // XXX could reserve only 'size' bytes
            param_addr = loc;
            لكل (i = 0; i < regcount; i++) {
                إذا (areg[prc[1+i] - 1] >= 8) {
                    أكد(i == 1 && regcount == 2 && !(addr & 7));
                    EI(0x03, 3, 5, 8, addr); // ld t0, addr(s0)
                    addr += 8;
                    ES(0x23, 3, 8, 5, loc + i*8); // sd t0, loc(s0)
                } وإلا إذا (prc[1+i] == RC_FLOAT) {
                    ES(0x27, (اندازه / regcount) == 4 ? 2 : 3, 8, 10 + areg[1]++, loc + (fieldofs[i+1] >> 4)); // fs[wd] FAi, loc(s0)
                } وإلا {
                    ES(0x23, 3, 8, 10 + areg[0]++, loc + i*8); // sd aX, loc(s0) // XXX
                }
            }
        }
        gfunc_مجموعه_param(sym, param_addr, byref);
    }
    func_va_list_ofs = addr;
    رقم_va_regs = 0;
    إذا (func_var) {
        لكل (; areg[0] < 8; areg[0]++) {
            رقم_va_regs++;
            ES(0x23, 3, 8, 10 + areg[0], -8 + رقم_va_regs * 8); // sd aX, loc(s0)
        }
    }
#اگر_تعریف_شده CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#پایان_اگر
}

ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret,
                       صحيح *ret_align, صحيح *regsize)
{
    صحيح align, اندازه = type_اندازه(vt, &align), nregs;
    صحيح prc[3], fieldofs[3];
    *ret_align = 1;
    *regsize = 8;
    إذا (اندازه > 16)
      أرجع 0;
    reg_pass(vt, prc, fieldofs, 1);
    nregs = prc[0];
    إذا (nregs == 2 && prc[1] != prc[2])
      أرجع -1;  /* generic code can't deal with this case */
    إذا (prc[1] == RC_FLOAT) {
        *regsize = اندازه / nregs;
    }
    ret->t = fieldofs[1] & VT_BTYPE;
    ret->ref = عدم;
    أرجع nregs;
}

ST_FUNC فراغ arch_transfer_ret_regs(صحيح aftercall)
{
    صحيح prc[3], fieldofs[3];
    reg_pass(&vtop->type, prc, fieldofs, 1);
    أكد(prc[0] == 2 && prc[1] != prc[2] && !(fieldofs[1] >> 4));
    أكد(vtop->r == (VT_LOCAL | VT_LVAL));
    vpushv(vtop);
    vtop->type.t = fieldofs[1] & VT_BTYPE;
    (aftercall ? store : بارگیری)(prc[1] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop->c.i += fieldofs[2] >> 4;
    vtop->type.t = fieldofs[2] & VT_BTYPE;
    (aftercall ? store : بارگیری)(prc[2] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop--;
}

ST_FUNC فراغ gfunc_epilog(فراغ)
{
    صحيح v, saved_ind, d, large_ofs_ind;

#اگر_تعریف_شده CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#پایان_اگر

    loc = (loc - رقم_va_regs * 8);
    d = v = (-loc + 15) & -16;

    EI(0x13, 0, 2, 8, رقم_va_regs * 8); // addi sp, s0, num_va_regs*8
    EI(0x03, 3, 1, 8, -8); // ld ra, -8(s0)
    EI(0x03, 3, 8, 8, -16); // ld s0, -16(s0)
    EI(0x67, 0, 0, 1, 0); // jalr x0, 0(x1), aka ret

    large_ofs_ind = ind;
    إذا (v >= (1 << 11)) {
        d = 16;
        EI(0x13, 0, 8, 2, d - رقم_va_regs * 8);      // addi s0, sp, d
        o(0x37 | (5 << 7) | فوقانی_2(v-16)); //lui t0, upper(v)
        EI(0x13, 0, 5, 5, SIGN11(v-16)); // addi t0, t0, lo(v)
        ER(0x33, 0, 2, 2, 5, 0x20); // sub sp, sp, t0
        gjmp_addr(func_sub_sp_جابه_جایی + 5*4);
    }
    saved_ind = ind;

    ind = func_sub_sp_جابه_جایی;
    EI(0x13, 0, 2, 2, -d);     // addi sp, sp, -d
    ES(0x23, 3, 2, 1, d - 8 - رقم_va_regs * 8);  // sd ra, d-8(sp)
    ES(0x23, 3, 2, 8, d - 16 - رقم_va_regs * 8); // sd s0, d-16(sp)
    إذا (v < (1 << 11))
      EI(0x13, 0, 8, 2, d - رقم_va_regs * 8);      // addi s0, sp, d
    وإلا
      gjmp_addr(large_ofs_ind);
    إذا ((ind - func_sub_sp_جابه_جایی) != 5*4)
      EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
    ind = saved_ind;
}

ST_FUNC فراغ gen_va_شروع(فراغ)
{
    vtop--;
    vset(&char_اشاره_گر_type, VT_LOCAL, func_va_list_ofs);
}

ST_FUNC فراغ gen_fill_nops(صحيح بایتها)
{
    إذا ((بایتها & 3))
      tcc_error("alignment of code section not multiple of 4");
    طالما (بایتها > 0) {
        EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
        بایتها -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC صحيح gjmp(صحيح t)
{
    إذا (nocode_wanted)
      أرجع t;
    o(t);
    أرجع ind - 4;
}

// Generate branch to known address:
ST_FUNC فراغ gjmp_addr(صحيح a)
{
    uint32_t r = a - ind, imm;
    إذا ((r + (1 << 21)) & ~((1U << 22) - 2)) {
        o(0x17 | (5 << 7) | فوقانی_2(r)); // lui RR, up(r)
        r = SIGN11(r);
        EI(0x67, 0, 0, 5, r);      // jalr x0, r(t0)
    } وإلا {
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        o(0x6f | imm); // jal x0, imm ==  j imm
    }
}

ST_FUNC صحيح gjmp_cond(صحيح op, صحيح t)
{
    صحيح tmp;
    صحيح a = vtop->cmp_r & 0xff;
    صحيح b = (vtop->cmp_r >> 8) & 0xff;
    بدل (op) {
        حالة TOK_ULT: op = 6; اكسر;
        حالة TOK_UGE: op = 7; اكسر;
        حالة TOK_ULE: op = 7; tmp = a; a = b; b = tmp; اكسر;
        حالة TOK_UGT: op = 6; tmp = a; a = b; b = tmp; اكسر;
        حالة TOK_LT:  op = 4; اكسر;
        حالة TOK_GE:  op = 5; اكسر;
        حالة TOK_LE:  op = 5; tmp = a; a = b; b = tmp; اكسر;
        حالة TOK_GT:  op = 4; tmp = a; a = b; b = tmp; اكسر;
        حالة TOK_NE:  op = 1; اكسر;
        حالة TOK_EQ:  op = 0; اكسر;
    }
    o(0x63 | (op ^ 1) << 12 | a << 15 | b << 20 | 8 << 7); // bOP a,b,+4
    أرجع gjmp(t);
}

ST_FUNC صحيح gjmp_append(صحيح n, صحيح t)
{
    فراغ *p;
    /* insert jump list n into t */
    إذا (n) {
        uint32_t n1 = n, n2;
        طالما ((n2 = read32le(p = cur_متن_section->داده + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    أرجع t;
}

ساكن فراغ gen_opil(صحيح op, صحيح ll)
{
    صحيح a, b, d;
    صحيح func3 = 0;
    ll = ll ? 0 : 8;
    إذا ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
        صحيح fc = vtop->c.i;
        إذا (fc == vtop->c.i && !کم_سرریز(fc)) {
            صحيح cll = 0;
            صحيح m = ll ? 31 : 63;
            vswap();
            gv(RC_INT);
            a = ireg(vtop[0].r);
            --vtop;
            d = get_reg(RC_INT);
            ++vtop;
            vswap();
            بدل (op) {
                حالة '-':
                    إذا (fc <= -(1 << 11))
                      اكسر;
                    fc = -fc;
                حالة '+':
                    func3 = 0; // addi d, a, fc
                    cll = ll;
                do_cop:
                    EI(0x13 | cll, func3, ireg(d), a, fc);
                    --vtop;
                    إذا (op >= TOK_ULT && op <= TOK_GT) {
                      vset_VT_CMP(TOK_NE);
                      vtop->cmp_r = ireg(d) | 0 << 8;
                    } وإلا
                      vtop[0].r = d;
                    أرجع;
                حالة TOK_LE:
                    إذا (fc >= (1 << 11) - 1)
                      اكسر;
                    ++fc;
                حالة TOK_LT:  func3 = 2; اذهب do_cop; // slti d, a, fc
                حالة TOK_ULE:
                    إذا (fc >= (1 << 11) - 1 || fc == -1)
                      اكسر;
                    ++fc;
                حالة TOK_ULT: func3 = 3; اذهب do_cop; // sltiu d, a, fc
                حالة '^':     func3 = 4; اذهب do_cop; // xori d, a, fc
                حالة '|':     func3 = 6; اذهب do_cop; // ori  d, a, fc
                حالة '&':     func3 = 7; اذهب do_cop; // andi d, a, fc
                حالة TOK_SHL: func3 = 1; cll = ll; fc &= m; اذهب do_cop; // slli d, a, fc
                حالة TOK_SHR: func3 = 5; cll = ll; fc &= m; اذهب do_cop; // srli d, a, fc
                حالة TOK_SAR: func3 = 5; cll = ll; fc = 1024 | (fc & m); اذهب do_cop;

                حالة TOK_UGE: /* -> TOK_ULT */
                حالة TOK_UGT: /* -> TOK_ULE */
                حالة TOK_GE:  /* -> TOK_LT */
                حالة TOK_GT:  /* -> TOK_LE */
                    gen_opil(op - 1, !ll);
                    vtop->cmp_op ^= 1;
                    أرجع;

                حالة TOK_NE:
                حالة TOK_EQ:
                    إذا (fc)
                      gen_opil('-', !ll), a = ireg(vtop++->r);
                    --vtop;
                    vset_VT_CMP(op);
                    vtop->cmp_r = a | 0 << 8;
                    أرجع;
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
    بدل (op) {
    افتراضي:
        إذا (op >= TOK_ULT && op <= TOK_GT) {
            vset_VT_CMP(op);
            vtop->cmp_r = a | b << 8;
            اكسر;
        }
        tcc_error("implement me: %s(%s)", __FUNCTION__, get_tok_str(op, عدم));
        اكسر;

    حالة '+':
        ER(0x33 | ll, 0, d, a, b, 0); // add d, a, b
        اكسر;
    حالة '-':
        ER(0x33 | ll, 0, d, a, b, 0x20); // sub d, a, b
        اكسر;
    حالة TOK_SAR:
        ER(0x33 | ll | ll, 5, d, a, b, 0x20); // sra d, a, b
        اكسر;
    حالة TOK_SHR:
        ER(0x33 | ll | ll, 5, d, a, b, 0); // srl d, a, b
        اكسر;
    حالة TOK_SHL:
        ER(0x33 | ll, 1, d, a, b, 0); // sll d, a, b
        اكسر;
    حالة '*':
        ER(0x33 | ll, 0, d, a, b, 1); // mul d, a, b
        اكسر;
    حالة '/':
    حالة TOK_PDIV:
        ER(0x33 | ll, 4, d, a, b, 1); // div d, a, b
        اكسر;
    حالة '&':
        ER(0x33, 7, d, a, b, 0); // and d, a, b
        اكسر;
    حالة '^':
        ER(0x33, 4, d, a, b, 0); // xor d, a, b
        اكسر;
    حالة '|':
        ER(0x33, 6, d, a, b, 0); // or d, a, b
        اكسر;
    حالة '%':
        ER(ll ? 0x3b:  0x33, 6, d, a, b, 1); // rem d, a, b
        اكسر;
    حالة TOK_UMOD:
        ER(0x33 | ll, 7, d, a, b, 1); // remu d, a, b
        اكسر;
    حالة TOK_UDIV:
        ER(0x33 | ll, 5, d, a, b, 1); // divu d, a, b
        اكسر;
    }
}

ST_FUNC فراغ gen_opi(صحيح op)
{
    gen_opil(op, 0);
}

ST_FUNC فراغ gen_opl(صحيح op)
{
    gen_opil(op, 1);
}

ST_FUNC فراغ gen_opf(صحيح op)
{
    صحيح rs1, rs2, rd, dbl, invert;
    إذا (vtop[0].type.t == VT_LDOUBLE) {
        CType type = vtop[0].type;
        صحيح func = 0;
        صحيح cond = -1;
        بدل (op) {
        حالة '*': func = TOK___multf3; اكسر;
        حالة '+': func = TOK___addtf3; اكسر;
        حالة '-': func = TOK___subtf3; اكسر;
        حالة '/': func = TOK___divtf3; اكسر;
        حالة TOK_EQ: func = TOK___eqtf2; cond = 1; اكسر;
        حالة TOK_NE: func = TOK___netf2; cond = 0; اكسر;
        حالة TOK_LT: func = TOK___lttf2; cond = 10; اكسر;
        حالة TOK_GE: func = TOK___getf2; cond = 11; اكسر;
        حالة TOK_LE: func = TOK___letf2; cond = 12; اكسر;
        حالة TOK_GT: func = TOK___gttf2; cond = 13; اكسر;
        افتراضي: أكد(0); اكسر;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = REG_IRET;
        vtop->r2 = cond < 0 ? TREG_R(1) : VT_CONST;
        إذا (cond < 0)
            vtop->type = type;
        وإلا {
            vpushi(0);
            gen_opil(op, 1);
        }
        أرجع;
    }

    gv2(RC_FLOAT, RC_FLOAT);
    أكد(vtop->type.t == VT_DOUBLE || vtop->type.t == VT_FLOAT);
    dbl = vtop->type.t == VT_DOUBLE;
    rs1 = freg(vtop[-1].r);
    rs2 = freg(vtop->r);
    vtop--;
    invert = 0;
    بدل(op) {
    افتراضي:
        أكد(0);
    حالة '+':
        op = 0; // fadd
    arithop:
        rd = get_reg(RC_FLOAT);
        vtop->r = rd;
        rd = freg(rd);
        ER(0x53, 7, rd, rs1, rs2, dbl | (op << 2)); // fop.[sd] RD, RS1, RS2 (dyn rm)
        اكسر;
    حالة '-':
        op = 1; // fsub
        اذهب arithop;
    حالة '*':
        op = 2; // fmul
        اذهب arithop;
    حالة '/':
        op = 3; // fdiv
        اذهب arithop;
    حالة TOK_EQ:
        op = 2; // EQ
    cmpop:
        rd = get_reg(RC_INT);
        vtop->r = rd;
        rd = ireg(rd);
        ER(0x53, op, rd, rs1, rs2, dbl | 0x50); // fcmp.[sd] RD, RS1, RS2 (op == eq/lt/le)
        إذا (invert)
          EI(0x13, 4, rd, rd, 1); // xori RD, 1

        /* generate VT_CMP output */
        vset_VT_CMP(TOK_NE);
        vtop->cmp_r = rd | (0 << 8);
        اكسر;
    حالة TOK_NE:
        invert = 1;
        op = 2; // EQ
        اذهب cmpop;
    حالة TOK_LT:
        op = 1; // LT
        اذهب cmpop;
    حالة TOK_LE:
        op = 0; // LE
        اذهب cmpop;
    حالة TOK_GT:
        op = 1; // LT
        rd = rs1, rs1 = rs2, rs2 = rd;
        اذهب cmpop;
    حالة TOK_GE:
        op = 0; // LE
        rd = rs1, rs1 = rs2, rs2 = rd;
        اذهب cmpop;
    }
}

ST_FUNC فراغ gen_cvt_csti(صحيح t)
{
    صحيح r = ireg(gv(RC_INT));
    إذا ((t & VT_BTYPE) == VT_SHORT) {
        إذا (t & VT_UNSIGNED) {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EI(0x13, 5, r, r, 48); // srli r, r, 48
        } وإلا {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EIu(0x13, 5, r, r, 0x400 | 48); // srai r, r, 48
        }
    } وإلا {
        إذا (t & VT_UNSIGNED) {
            EI(0x13, 7, r, r, 0xff); // andi r, r, 0xff
        } وإلا {
            EI(0x13, 1, r, r, 56); // slli r, r, 56
            EIu(0x13, 5, r, r, 0x400 | 56); // srai r, r, 56
        }
    }
}

ST_FUNC فراغ gen_cvt_sxtw(فراغ)
{
    صحيح r = ireg(gv(RC_INT));
    EI(0x1b, 0, r, r, 0); // addiw r, r, 0
}

ST_FUNC فراغ gen_cvt_itof(صحيح t)
{
    صحيح rr = ireg(gv(RC_INT)), dr;
    صحيح u = vtop->type.t & VT_UNSIGNED;
    صحيح l = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    إذا (t == VT_LDOUBLE) {
        صحيح func = l ?
          (u ? TOK___floatunditf : TOK___floatditf) :
          (u ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        vtop->r2 = TREG_R(1);
    } وإلا {
        vtop--;
        dr = get_reg(RC_FLOAT);
        vtop++;
        vtop->r = dr;
        dr = freg(dr);
        EIu(0x53, 7, dr, rr, ((0x68 | (t == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[sd].[wl][u]
    }
}

ST_FUNC فراغ gen_cvt_ftoi(صحيح t)
{
    صحيح ft = vtop->type.t & VT_BTYPE;
    صحيح l = (t & VT_BTYPE) == VT_LLONG;
    صحيح u = t & VT_UNSIGNED;
    إذا (ft == VT_LDOUBLE) {
        صحيح func = l ?
          (u ? TOK___fixunstfdi : TOK___fixtfdi) :
          (u ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
    } وإلا {
        صحيح rr = freg(gv(RC_FLOAT)), dr;
        vtop--;
        dr = get_reg(RC_INT);
        vtop++;
        vtop->r = dr;
        dr = ireg(dr);
        EIu(0x53, 1, dr, rr, ((0x60 | (ft == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[wl][u].[sd] rtz
    }
}

ST_FUNC فراغ gen_cvt_ftof(صحيح dt)
{
    صحيح st = vtop->type.t & VT_BTYPE, rs, rd;
    dt &= VT_BTYPE;
    إذا (st == dt)
      أرجع;
    إذا (dt == VT_LDOUBLE || st == VT_LDOUBLE) {
        صحيح func = (dt == VT_LDOUBLE) ?
            (st == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (dt == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        /* We can't use gfunc_call, as func_old_type works like vararg
           functions, and on riscv unnamed float args are passed like
           integers.  But we really need them in the float argument registers
           for extendsftf2/extenddftf2.  So, do it explicitely.  */
        save_regs(1);
        إذا (dt == VT_LDOUBLE)
          gv(RC_F(0));
        وإلا {
            gv(RC_R(0));
            أكد(vtop->r2 < 7);
            إذا (vtop->r2 != 1 + vtop->r) {
                EI(0x13, 0, ireg(vtop->r) + 1, ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = 1 + vtop->r;
            }
        }
        vpush_helper_func(func);
        gcall_or_jmp(1);
        vtop -= 2;
        vpushi(0);
        vtop->type.t = dt;
        إذا (dt == VT_LDOUBLE)
          vtop->r = REG_IRET, vtop->r2 = REG_IRET+1;
        وإلا
          vtop->r = REG_FRET;
    } وإلا {
        أكد (dt == VT_FLOAT || dt == VT_DOUBLE);
        أكد (st == VT_FLOAT || st == VT_DOUBLE);
        rs = gv(RC_FLOAT);
        rd = get_reg(RC_FLOAT);
        إذا (dt == VT_DOUBLE)
          EI(0x53, 0, freg(rd), freg(rs), 0x21 << 5); // fcvt.d.s RD, RS (no rm)
        وإلا
          EI(0x53, 7, freg(rd), freg(rs), (0x20 << 5) | 1); // fcvt.s.d RD, RS (dyn rm)
        vtop->r = rd;
    }
}

/* increment tcov counter */
ST_FUNC فراغ gen_increment_tcov (SValue *sv)
{
    صحيح r1, r2;
    Sym label = {0};
    label.type.t = VT_VOID | VT_STATIC;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    r1 = ireg(r1);
    r2 = ireg(r2);
    greloca(cur_متن_section, sv->sym, ind, R_RISCV_PCREL_HI20, 0);
    put_extern_sym(&label, cur_متن_section, ind, 0);
    o(0x17 | (r1 << 7)); // auipc RR, 0 %pcrel_hi(sym)
    greloca(cur_متن_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, r2, r1, 0); // ld r2, x[r1]
    EI(0x13, 0, r2, r2, 1); // addi r2, r2, #1
    greloca(cur_متن_section, sv->sym, ind, R_RISCV_PCREL_HI20, 0);
    label.c = 0; /* force new local ELF symbol */
    put_extern_sym(&label, cur_متن_section, ind, 0);
    o(0x17 | (r1 << 7)); // auipc RR, 0 %pcrel_hi(sym)
    greloca(cur_متن_section, &label, ind, R_RISCV_PCREL_LO12_S, 0);
    ES(0x23, 3, r1, r2, 0); // sd r2, [r1]
    vpop();
}

ST_FUNC فراغ ggoto(فراغ)
{
    gcall_or_jmp(0);
    vtop--;
}

ST_FUNC فراغ gen_vla_sp_save(صحيح addr)
{
    إذا (کم_سرریز(addr)) {
	o(0x37 | (5 << 7) | فوقانی_2(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        ES(0x23, 3, 5, 2, SIGN11(addr)); // sd sp, fc(t0)
    }
    وإلا
        ES(0x23, 3, 8, 2, addr); // sd sp, fc(s0)
}

ST_FUNC فراغ gen_vla_sp_restore(صحيح addr)
{
    إذا (کم_سرریز(addr)) {
	o(0x37 | (5 << 7) | فوقانی_2(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        EI(0x03, 3, 2, 5, SIGN11(addr)); // ld sp, fc(t0)
    }
    وإلا
        EI(0x03, 3, 2, 8, addr); // ld sp, fc(s0)
}

ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align)
{
    صحيح rr;
#إذا defined(CONFIG_TCC_BCHECK)
    إذا (tcc_state->do_bounds_check)
        vpushv(vtop);
#پایان_اگر
    rr = ireg(gv(RC_INT));
#إذا defined(CONFIG_TCC_BCHECK)
    إذا (tcc_state->do_bounds_check)
        EI(0x13, 0, rr, rr, 15+1);   // addi RR, RR, 15+1
    وإلا
#پایان_اگر
    EI(0x13, 0, rr, rr, 15);   // addi RR, RR, 15
    EI(0x13, 7, rr, rr, -16);  // andi, RR, RR, -16
    ER(0x33, 0, 2, 2, rr, 0x20); // sub sp, sp, rr
    vpop();
#إذا defined(CONFIG_TCC_BCHECK)
    إذا (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x00010513); /* mv a0,sp */
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_جمع_کن_epilog = 1;
    }
#پایان_اگر
}

ST_FUNC فراغ gen_clear_cache(فراغ)
{
    /* Zifencei extension: fence + fence.i for I/D synchronization.
       Required by RISC-V Linux ABI, present on all Linux-capable cores. */
    o(0x0ff0000f); // fence iorw, iorw
    o(0x0000100f); // fence.i
}
#پایان_اگر
