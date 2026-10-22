#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

// Number of registers available to allocator:
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_REGS 19 // x10-x17 aka a0-a7, f10-f17 aka fa0-fa7, xxx, ra, sp
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONFIG_TCC_ASM

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_R(x) (x) // x = 0..7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_F(x) (x + 8) // x = 0..7

// Register classes sorted from more general to more precise:
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_INT (1 << 0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FLOAT (1 << 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R(x) (1 << (2 + (x))) // x = 0..7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_F(x) (1 << (10 + (x))) // x = 0..7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_IRET (RC_R(0)) // int return register class
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_IRE2 (RC_R(1)) // int 2nd return register class
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FRET (RC_F(0)) // float return register class

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IRET (TREG_R(0)) // int return register number
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IRE2 (TREG_R(1)) // int 2nd return register number
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_FRET (TREG_F(0)) // float return register number

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTR_ਮਾਪ 8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ਮਾਪ 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ALIGN 16

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_ALIGN 16

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHAR_IS_UNSIGNED

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROMOTE_RET

#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"
#ਅਨ੍ਤਰ੍ਭਾਵ <assert.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਉੱਤਲਾ_2(x)	(((ਬਿਨਾਨਿਸ਼ਾਨੀ)(x) + 0x800u) & 0xfffff000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨੀਵਾਂ_ਉਛਾਲ(x)	ਉੱਤਲਾ_2(x)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGN7(x)	((((x) & 0xff) ^ 0x80) - 0x80)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGN11(x)	((((x) & 0xfff) ^ 0x800) - 0x800)

ST_ਅੰਕੜੇ ਅਚਲ ਅੱਖਰ * ਅਚਲ ਨਿਸ਼ਾਨਾ_machine_defs =
    "__riscv\0"
    "__riscv_xlen 64\0"
    "__riscv_flen 64\0"
    "__riscv_div\0"
    "__riscv_mul\0"
    "__riscv_fdiv\0"
    "__riscv_fsqrt\0"
    "__riscv_float_abi_double\0"
    ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XLEN 8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_RA 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_SP 18

ST_ਅੰਕੜੇ ਅਚਲ ਪੂਰਨ reg_classes[NB_REGS] = {
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

#ਜੇ defined(CONFIG_TCC_BCHECK)
ਸਥਿਰ addr_t func_bound_ਵਿੱਥ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ func_bound_ind;
ST_ਅੰਕੜੇ ਪੂਰਨ func_bound_ਜੋੜੋ_epilog;
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ ireg(ਪੂਰਨ r)
{
    ਜੇ (r == TREG_RA)
      ਵਾਪਸ 1; // ra
    ਜੇ (r == TREG_SP)
      ਵਾਪਸ 2; // sp
    ਪ੍ਰਤਿਜ੍ਞਾ(r >= 0 && r < 8);
    ਵਾਪਸ r + 10;  // tccrX --> aX == x(10+X)
}

ਸਥਿਰ ਪੂਰਨ is_ireg(ਪੂਰਨ r)
{
    ਵਾਪਸ (ਬਿਨਾਨਿਸ਼ਾਨੀ)r < 8 || r == TREG_RA || r == TREG_SP;
}

ਸਥਿਰ ਪੂਰਨ freg(ਪੂਰਨ r)
{
    ਪ੍ਰਤਿਜ੍ਞਾ(r >= 8 && r < 16);
    ਵਾਪਸ r - 8 + 10;  // tccfX --> faX == f(10+X)
}

ਸਥਿਰ ਪੂਰਨ is_freg(ਪੂਰਨ r)
{
    ਵਾਪਸ r >= 8 && r < 16;
}

ST_FUNC ਖਾਲੀ o(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ c)
{
    ਪੂਰਨ ind1 = ind + 4;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    ਜੇ (ind1 > cur_ਪਾਠ_section->ਅੰਕੜੇ_allocated)
        section_realloc(cur_ਪਾਠ_section, ind1);
    write32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + ind, c);
    ind = ind1;
}

ਸਥਿਰ ਖਾਲੀ EIu(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    o(opcode | (func3 << 12) | (rd << 7) | (rs1 << 15) | (imm << 20));
}

ਸਥਿਰ ਖਾਲੀ ER(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t func7)
{
    o(opcode | func3 << 12 | rd << 7 | rs1 << 15 | rs2 << 20 | func7 << 25);
}

ਸਥਿਰ ਖਾਲੀ EI(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    ਪ੍ਰਤਿਜ੍ਞਾ(! ਨੀਵਾਂ_ਉਛਾਲ(imm));
    EIu(opcode, func3, rd, rs1, imm);
}

ਸਥਿਰ ਖਾਲੀ ES(uint32_t opcode, uint32_t func3,
               uint32_t rs1, uint32_t rs2, uint32_t imm)
{
    ਪ੍ਰਤਿਜ੍ਞਾ(! ਨੀਵਾਂ_ਉਛਾਲ(imm));
    o(opcode | (func3 << 12) | ((imm & 0x1f) << 7) | (rs1 << 15)
      | (rs2 << 20) | ((imm >> 5) << 25));
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC ਖਾਲੀ gsym_addr(ਪੂਰਨ t_, ਪੂਰਨ a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    ਜਦੋਂ (t) {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr = cur_ਪਾਠ_section->ਅੰਕੜੇ + t;
        uint32_t ਅਗਲਾ = read32le(ptr);
        uint32_t r = a - t, imm;
        ਜੇ ((r + (1 << 21)) & ~((1U << 22) - 2))
          tcc_error("out-of-range branch chain");
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        write32le(ptr, r == 4 ? 0x33 : 0x6f | imm); // nop || j imm
        t = ਅਗਲਾ;
    }
}

ਸਥਿਰ ਪੂਰਨ ਲੱਦੋ_symofs(ਪੂਰਨ r, SValue *sv, ਪੂਰਨ forstore, ਪੂਰਨ *new_fc)
{
    ਪੂਰਨ rr, doload = 0, large_addend = 0;
    ਪੂਰਨ fc = sv->c.i, v = sv->r & VT_VALMASK;
    ਜੇ (sv->r & VT_SYM) {
        Sym label = {0};
        ਪ੍ਰਤਿਜ੍ਞਾ(v == VT_CONST);
        ਜੇ (sv->sym->type.t & VT_TLS) {
            /* TLS Local Exec model: lui + addi + add tp */
            rr = is_ireg(r) ? ireg(r) : 5;
            greloca(cur_ਪਾਠ_section, sv->sym, ind,
                    R_RISCV_TPREL_HI20, sv->c.i);
            o(0x37 | (rr << 7));  // lui RR, 0 %tprel_hi(sym)
            greloca(cur_ਪਾਠ_section, sv->sym, ind,
                    R_RISCV_TPREL_LO12_I, sv->c.i);
            EI(0x13, 0, rr, rr, 0); // addi RR, RR, 0 %tprel_lo(sym)
            ER(0x33, 0, rr, rr, 4, 0); // add RR, RR, tp
            *new_fc = 0;
            ਵਾਪਸ rr;
        }
        ਜੇ (sv->sym->type.t & VT_STATIC) { // XXX do this per linker relax
            greloca(cur_ਪਾਠ_section, sv->sym, ind,
                    R_RISCV_PCREL_HI20, sv->c.i);
            *new_fc = 0;
        } ਨਹੀਂਤਾਂ {
            ਜੇ (ਨੀਵਾਂ_ਉਛਾਲ(fc)){
              large_addend = 1;
            }
            greloca(cur_ਪਾਠ_section, sv->sym, ind,
                    R_RISCV_GOT_HI20, 0);
            doload = 1;
        }
        label.type.t = VT_VOID | VT_STATIC;
	ਜੇ (!nocode_wanted)
            put_extern_sym(&label, cur_ਪਾਠ_section, ind, 0);
        rr = is_ireg(r) ? ireg(r) : 5;
        o(0x17 | (rr << 7));   // auipc RR, 0 %pcrel_hi(sym)+addend
        greloca(cur_ਪਾਠ_section, &label, ind,
                doload || !forstore
                  ? R_RISCV_PCREL_LO12_I : R_RISCV_PCREL_LO12_S, 0);
        ਜੇ (doload) {
            EI(0x03, 3, rr, rr, 0); // ld RR, 0(RR)
            ਜੇ (large_addend) {
                o(0x37 | (6 << 7) | ਉੱਤਲਾ_2(fc)); //lui t1, high(fc)
                ER(0x33, 0, rr, rr, 6, 0); // add RR, RR, t1
                *new_fc = SIGN11(fc);
            }
        }
    } ਨਹੀਂਤਾਂ ਜੇ (v == VT_LOCAL || v == VT_LLOCAL) {
        rr = 8; // s0
        ਜੇ (fc != sv->c.i)
          tcc_error("unimp: store(giant local off) (0x%lx)", (ਲੰਮਾ)sv->c.i);
        ਜੇ (ਨੀਵਾਂ_ਉਛਾਲ(fc)) {
            rr = is_ireg(r) ? ireg(r) : 5; // t0
            o(0x37 | (rr << 7) | ਉੱਤਲਾ_2(fc)); //lui RR, upper(fc)
            ER(0x33, 0, rr, rr, 8, 0); // add RR, RR, s0
            *new_fc = SIGN11(fc);
        }
    } ਨਹੀਂਤਾਂ
      tcc_error("uhh");
    ਵਾਪਸ rr;
}

ਸਥਿਰ ਖਾਲੀ ਲੱਦੋ_large_constant(ਪੂਰਨ rr, ਪੂਰਨ fc, uint32_t pi)
{
    ਜੇ (fc < 0)
	pi++;
    o(0x37 | (rr << 7) | ਉੱਤਲਾ_2(pi)); // lui RR, up(up(fc))
    EI(0x13, 0, rr, rr, SIGN11(pi));   // addi RR, RR, lo(up(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((ਬਿਨਾਨਿਸ਼ਾਨੀ)fc + (1 << 19)) >> 20)); // addi RR, RR, up(lo(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((ਬਿਨਾਨਿਸ਼ਾਨੀ)fc + (1 << 7)) >> 8));  // addi RR, RR, lo1(lo(fc))
    EI(0x13, 1, rr, rr, 8); // slli RR, RR, 8
}

ST_FUNC ਖਾਲੀ ਲੱਦੋ(ਪੂਰਨ r, SValue *sv)
{
    ਪੂਰਨ fr = sv->r;
    ਪੂਰਨ v = fr & VT_VALMASK;
    ਪੂਰਨ rr = is_ireg(r) ? ireg(r) : freg(r);
    ਪੂਰਨ fc = sv->c.i;
    ਪੂਰਨ bt = sv->type.t & VT_BTYPE;
    ਪੂਰਨ align, ਮਾਪ;
    ਜੇ (fr & VT_LVAL) {
        ਪੂਰਨ func3, opcode = is_freg(r) ? 0x07 : 0x03, br;
        ਮਾਪ = type_ਮਾਪ(&sv->type, &align);
        ਪ੍ਰਤਿਜ੍ਞਾ (!is_freg(r) || bt == VT_FLOAT || bt == VT_DOUBLE);
        ਜੇ (bt == VT_PTR || bt == VT_FUNC) /* XXX should be done in generic code */
          ਮਾਪ = PTR_ਮਾਪ;
        func3 = ਮਾਪ == 1 ? 0 : ਮਾਪ == 2 ? 1 : ਮਾਪ == 4 ? 2 : 3;
        ਜੇ (ਮਾਪ < 4 && !is_float(sv->type.t) && (sv->type.t & VT_UNSIGNED))
          func3 |= 4;
        ਜੇ (v == VT_LOCAL || (fr & VT_SYM)) {
            br = ਲੱਦੋ_symofs(r, sv, 0, &fc);
        } ਨਹੀਂਤਾਂ ਜੇ (v < VT_CONST) {
            br = ireg(v);
            /*if (LOW_OVERFLOW(fc))
              tcc_error("unimp: load(large addend) (0x%x)", fc);*/
            fc = 0; // XXX store ofs in LVAL(reg)
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_LLOCAL) {
            br = ਲੱਦੋ_symofs(r, sv, 0, &fc);
            EI(0x03, 3, rr, br, fc); // ld RR, fc(BR)
            br = rr;
            fc = 0;
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_CONST) {
            int64_t si = sv->c.i;
            si >>= 32;
            ਜੇ (si != 0) {
		ਲੱਦੋ_large_constant(rr, fc, si);
                fc = SIGN7(fc);
            } ਨਹੀਂਤਾਂ {
                o(0x37 | (rr << 7) | ਉੱਤਲਾ_2(fc)); //lui RR, upper(fc)
                fc = SIGN11(fc);
	    }
            br = rr;
	} ਨਹੀਂਤਾਂ {
            tcc_error("unimp: load(non-local lval)");
        }
        EI(opcode, func3, rr, br, fc); // l[bhwd][u] / fl[wd] RR, fc(BR)
    } ਨਹੀਂਤਾਂ ਜੇ (v == VT_CONST) {
        ਪੂਰਨ rb = 0, do32bit = 8, zext = 0;
        ਜੇ (is_float(sv->type.t) && bt != VT_LDOUBLE) {
            /* load float/double constant: move bit pattern from int reg */
            uint64_t val = sv->c.i;
            ਪੂਰਨ is_dbl = bt == VT_DOUBLE;
            ਜੇ (val == 0) {
                o(0x53 | (rr << 7) | ((ਬਿਨਾਨਿਸ਼ਾਨੀ)(0x78 | is_dbl) << 25));
                ਵਾਪਸ;
            }
            ਜੇ (is_dbl) {
                ਲੱਦੋ_large_constant(6, (ਪੂਰਨ)val, (ਪੂਰਨ)(val >> 32));
            } ਨਹੀਂਤਾਂ {
                ਜੇ (ਨੀਵਾਂ_ਉਛਾਲ(fc))
                    o(0x37 | (6 << 7) | ਉੱਤਲਾ_2(fc)); // lui t1, upper
                EI(0x13 | 8, 0, 6, ਨੀਵਾਂ_ਉਛਾਲ(fc) ? 6 : 0, SIGN11(fc)); // addiw t1,...
            }
            o(0x53 | (rr << 7) | (6 << 15) | ((ਬਿਨਾਨਿਸ਼ਾਨੀ)(0x78 | is_dbl) << 25));
            ਵਾਪਸ;
        }
        ਪ੍ਰਤਿਜ੍ਞਾ(is_ireg(r) || bt == VT_LDOUBLE);
        ਜੇ (fr & VT_SYM) {
            rb = ਲੱਦੋ_symofs(r, sv, 0, &fc);
            do32bit = 0;
        }
        ਜੇ (do32bit && fc != sv->c.i) {
            int64_t si = sv->c.i;
            si >>= 32;
            ਜੇ (si != 0) {
		ਲੱਦੋ_large_constant(rr, fc, si);
                fc = SIGN7(fc);
                rb = rr;
                do32bit = 0;
            } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_LLONG) {
                /* A 32bit unsigned constant for a 64bit type.
                   lui always sign extends, so we need to do an explicit zext.*/
                zext = 1;
            }
        }
        ਜੇ (ਨੀਵਾਂ_ਉਛਾਲ(fc))
            o(0x37 | (rr << 7) | ਉੱਤਲਾ_2(fc)), rb = rr; //lui RR, upper(fc)
        ਜੇ (fc || (rr != rb) || do32bit || (fr & VT_SYM))
          EI(0x13 | do32bit, 0, rr, rb, SIGN11(fc)); // addi[w] R, x0|R, FC
        ਜੇ (zext) {
            EI(0x13, 1, rr, rr, 32); // slli RR, RR, 32
            EI(0x13, 5, rr, rr, 32); // srli RR, RR, 32
        }
    } ਨਹੀਂਤਾਂ ਜੇ (v == VT_LOCAL) {
        ਪੂਰਨ br = ਲੱਦੋ_symofs(r, sv, 0, &fc);
        ਪ੍ਰਤਿਜ੍ਞਾ(is_ireg(r));
        EI(0x13, 0, rr, br, fc); // addi R, s0, FC
    } ਨਹੀਂਤਾਂ ਜੇ (v < VT_CONST) { /* reg-reg */
        //assert(!fc); XXX support offseted regs
        ਜੇ (is_freg(r) && is_freg(v))
          ER(0x53, 0, rr, freg(v), freg(v), bt == VT_DOUBLE ? 0x11 : 0x10); //fsgnj.[sd] RR, V, V == fmv.[sd] RR, V
        ਨਹੀਂਤਾਂ ਜੇ (is_ireg(r) && is_ireg(v))
          EI(0x13, 0, rr, ireg(v), 0); // addi RR, V, 0 == mv RR, V
        ਨਹੀਂਤਾਂ {
            ਪੂਰਨ func7 = is_ireg(r) ? 0x70 : 0x78;
            ਮਾਪ = type_ਮਾਪ(&sv->type, &align);
            ਜੇ (ਮਾਪ == 8)
              func7 |= 1;
            ਪ੍ਰਤਿਜ੍ਞਾ(ਮਾਪ == 4 || ਮਾਪ == 8);
            o(0x53 | (rr << 7) | ((is_freg(v) ? freg(v) : ireg(v)) << 15)
              | ((ਬਿਨਾਨਿਸ਼ਾਨੀ)func7 << 25)); // fmv.{w.x, x.w, d.x, x.d} RR, VR
        }
    } ਨਹੀਂਤਾਂ ਜੇ (v == VT_CMP) {
        ਪੂਰਨ op = vtop->cmp_op;
        ਪੂਰਨ a = vtop->cmp_r & 0xff;
        ਪੂਰਨ b = (vtop->cmp_r >> 8) & 0xff;
        ਪੂਰਨ inv = 0;
        ਚੋਣ (op) {
            ਹਾਲਤ TOK_ULT:
            ਹਾਲਤ TOK_UGE:
            ਹਾਲਤ TOK_ULE:
            ਹਾਲਤ TOK_UGT:
            ਹਾਲਤ TOK_LT:
            ਹਾਲਤ TOK_GE:
            ਹਾਲਤ TOK_LE:
            ਹਾਲਤ TOK_GT:
                ਜੇ (op & 1) { // remove [U]GE,GT
                    inv = 1;
                    op--;
                }
                ਜੇ ((op & 7) == 6) { // [U]LE
                    ਪੂਰਨ t = a; a = b; b = t;
                    inv ^= 1;
                }
                ER(0x33, (op > TOK_UGT) ? 2 : 3, rr, a, b, 0); // slt[u] d, a, b
                ਜੇ (inv)
                  EI(0x13, 4, rr, rr, 1); // xori d, d, 1
                ਰੋਕੋ;
            ਹਾਲਤ TOK_NE:
            ਹਾਲਤ TOK_EQ:
                ਜੇ (rr != a || b)
                  ER(0x33, 0, rr, a, b, 0x20); // sub d, a, b
                ਜੇ (op == TOK_NE)
                  ER(0x33, 3, rr, 0, rr, 0); // sltu d, x0, d == snez d,d
                ਨਹੀਂਤਾਂ
                  EI(0x13, 3, rr, rr, 1); // sltiu d, d, 1 == seqz d,d
                ਰੋਕੋ;
        }
    } ਨਹੀਂਤਾਂ ਜੇ ((v & ~1) == VT_JMP) {
        ਪੂਰਨ t = v & 1;
        ਪ੍ਰਤਿਜ੍ਞਾ(is_ireg(r));
        EI(0x13, 0, rr, 0, t);      // addi RR, x0, t
        gjmp_addr(ind + 8);
        gsym(fc);
        EI(0x13, 0, rr, 0, t ^ 1);  // addi RR, x0, !t
    } ਨਹੀਂਤਾਂ
      tcc_error("unimp: load(non-const)");
}

ST_FUNC ਖਾਲੀ store(ਪੂਰਨ r, SValue *sv)
{
    ਪੂਰਨ fr = sv->r & VT_VALMASK;
    ਪੂਰਨ rr = is_ireg(r) ? ireg(r) : freg(r), ptrreg;
    ਪੂਰਨ fc = sv->c.i;
    ਪੂਰਨ bt = sv->type.t & VT_BTYPE;
    ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(&sv->type, &align);
    ਪ੍ਰਤਿਜ੍ਞਾ(!is_float(bt) || is_freg(r) || bt == VT_LDOUBLE);
    /* long doubles are in two integer registers, but the load/store
       primitives only deal with one, so do as if it's one reg.  */
    ਜੇ (bt == VT_LDOUBLE)
      ਮਾਪ = align = 8;
    ਜੇ (bt == VT_STRUCT)
      tcc_error("unimp: store(struct)");
    ਜੇ (ਮਾਪ > 8)
      tcc_error("unimp: large sized store");
    ਪ੍ਰਤਿਜ੍ਞਾ(sv->r & VT_LVAL);
    ਜੇ (fr == VT_LOCAL || (sv->r & VT_SYM)) {
        ptrreg = ਲੱਦੋ_symofs(-1, sv, 1, &fc);
    } ਨਹੀਂਤਾਂ ਜੇ (fr < VT_CONST) {
        ptrreg = ireg(fr);
        /*if (LOW_OVERFLOW(fc))
          tcc_error("unimp: store(large addend) (0x%x)", fc);*/
        fc = 0; // XXX support offsets regs
    } ਨਹੀਂਤਾਂ ਜੇ (fr == VT_CONST) {
        int64_t si = sv->c.i;
        ptrreg = 8; // s0
        si >>= 32;
        ਜੇ (si != 0) {
	    ਲੱਦੋ_large_constant(ptrreg, fc, si);
            fc = SIGN7(fc);
        } ਨਹੀਂਤਾਂ {
            o(0x37 | (ptrreg << 7) | ਉੱਤਲਾ_2(fc)); //lui RR, upper(fc)
            fc = SIGN11(fc);
	}
    } ਨਹੀਂਤਾਂ
      tcc_error("implement me: %s(!local)", __FUNCTION__);
    ES(is_freg(r) ? 0x27 : 0x23,                          // fs... | s...
       ਮਾਪ == 1 ? 0 : ਮਾਪ == 2 ? 1 : ਮਾਪ == 4 ? 2 : 3, // ... [wd] | [bhwd]
       ptrreg, rr, fc);                                   // RR, fc(base)
}

ਸਥਿਰ ਖਾਲੀ gcall_or_jmp(ਪੂਰਨ docall)
{
    ਪੂਰਨ tr = docall ? 1 : 5; // ra or t0
    ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
        ((vtop->r & VT_SYM) && vtop->c.i == (ਪੂਰਨ)vtop->c.i)) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_ਪਾਠ_section, vtop->sym, ind,
                R_RISCV_CALL_PLT, (ਪੂਰਨ)vtop->c.i);
        o(0x17 | (tr << 7));   // auipc TR, 0 %call(func)
        EI(0x67, 0, tr, tr, 0);// jalr  TR, r(TR)
    } ਨਹੀਂਤਾਂ ਜੇ (vtop->r < VT_CONST) {
        ਪੂਰਨ r = ireg(vtop->r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    } ਨਹੀਂਤਾਂ {
        ਪੂਰਨ r = TREG_RA;
        ਲੱਦੋ(r, vtop);
        r = ireg(r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    }
}

#ਜੇ defined(CONFIG_TCC_BCHECK)

ਸਥਿਰ ਖਾਲੀ gen_bounds_call(ਪੂਰਨ v)
{
    Sym *sym = external_helper_sym(v);

    greloca(cur_ਪਾਠ_section, sym, ind, R_RISCV_CALL_PLT, 0);
    o(0x17 | (1 << 7));   // auipc TR, 0 %call(func)
    EI(0x67, 0, 1, 1, 0); // jalr  TR, r(TR)
}

ਸਥਿਰ ਖਾਲੀ gen_bounds_prolog(ਖਾਲੀ)
{
    /* leave some room for bound checking code */
    func_bound_ਵਿੱਥ = lbounds_section->ਅੰਕੜੇ_ਵਿੱਥ;
    func_bound_ind = ind;
    func_bound_ਜੋੜੋ_epilog = 0;
    o(0x00000013);  /* ld a0,#lbound section pointer */
    o(0x00000013);
    o(0x00000013);  /* nop -> call __bound_local_new */
    o(0x00000013);
}

ਸਥਿਰ ਖਾਲੀ gen_bounds_epilog(ਖਾਲੀ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ਅੰਕੜੇ;
    Sym label = {0};

    ਪੂਰਨ ਵਿੱਥ_modified = func_bound_ਵਿੱਥ != lbounds_section->ਅੰਕੜੇ_ਵਿੱਥ;

    ਜੇ (!ਵਿੱਥ_modified && !func_bound_ਜੋੜੋ_epilog)
        ਵਾਪਸ;

    /* add end of table info */
    bounds_ptr = section_ptr_ਜੋੜੋ(lbounds_section, ਆਕਾਰ(addr_t));
    *bounds_ptr = 0;

    sym_ਅੰਕੜੇ = get_sym_ref(&char_ਸੂਚਕ_type, lbounds_section,
                           func_bound_ਵਿੱਥ, PTR_ਮਾਪ);

    label.type.t = VT_VOID | VT_STATIC;
    /* generate bound local allocation */
    ਜੇ (ਵਿੱਥ_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        put_extern_sym(&label, cur_ਪਾਠ_section, ind, 0);
        greloca(cur_ਪਾਠ_section, sym_ਅੰਕੜੇ, ind, R_RISCV_GOT_HI20, 0);
        o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
        greloca(cur_ਪਾਠ_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
        EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
        gen_bounds_call(TOK___bound_local_new);
        ind = saved_ind;
        label.c = 0; /* force new local ELF symbol */
    }

    /* generate bound check local freeing */
    o(0xe02a1101); /* addi sp,sp,-32  sd   a0,0(sp)   */
    o(0xa82ae42e); /* sd   a1,8(sp)   fsd  fa0,16(sp) */
    put_extern_sym(&label, cur_ਪਾਠ_section, ind, 0);
    greloca(cur_ਪਾਠ_section, sym_ਅੰਕੜੇ, ind, R_RISCV_GOT_HI20, 0);
    o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
    greloca(cur_ਪਾਠ_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
    gen_bounds_call(TOK___bound_local_delete);
    o(0x65a26502); /* ld   a0,0(sp)   ld   a1,8(sp)   */
    o(0x61052542); /* fld  fa0,16(sp) addi sp,sp,32   */
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਖਾਲੀ reg_pass_rec(CType *type, ਪੂਰਨ *rc, ਪੂਰਨ *fieldofs, ਪੂਰਨ ofs)
{
    ਜੇ ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *f;
        ਜੇ (type->ref->type.t == VT_UNION)
          rc[0] = -1;
        ਨਹੀਂਤਾਂ ਲਈ (f = type->ref->ਅਗਲਾ; f; f = f->ਅਗਲਾ)
          reg_pass_rec(&f->type, rc, fieldofs, ofs + f->c);
    } ਨਹੀਂਤਾਂ ਜੇ (type->t & VT_ARRAY) {
        ਜੇ (type->ref->c < 0 || type->ref->c > 2)
          rc[0] = -1;
        ਨਹੀਂਤਾਂ {
            ਪੂਰਨ a, sz = type_ਮਾਪ(&type->ref->type, &a);
            reg_pass_rec(&type->ref->type, rc, fieldofs, ofs);
            ਜੇ (rc[0] > 2 || (rc[0] == 2 && type->ref->c > 1))
              rc[0] = -1;
            ਨਹੀਂਤਾਂ ਜੇ (type->ref->c == 2 && rc[0] && rc[1] == RC_FLOAT) {
              rc[++rc[0]] = RC_FLOAT;
              fieldofs[rc[0]] = ((ofs + sz) << 4)
                                | (type->ref->type.t & VT_BTYPE);
            } ਨਹੀਂਤਾਂ ਜੇ (type->ref->c == 2)
              rc[0] = -1;
        }
    } ਨਹੀਂਤਾਂ ਜੇ (rc[0] == 2 || rc[0] < 0 || (type->t & VT_BTYPE) == VT_LDOUBLE)
      rc[0] = -1;
    ਨਹੀਂਤਾਂ ਜੇ (!rc[0] || rc[1] == RC_FLOAT || is_float(type->t)) {
      rc[++rc[0]] = is_float(type->t) ? RC_FLOAT : RC_INT;
      fieldofs[rc[0]] = (ofs << 4) | ((type->t & VT_BTYPE) == VT_PTR ? VT_LLONG : type->t & VT_BTYPE);
    } ਨਹੀਂਤਾਂ
      rc[0] = -1;
}

ਸਥਿਰ ਖਾਲੀ reg_pass(CType *type, ਪੂਰਨ *prc, ਪੂਰਨ *fieldofs, ਪੂਰਨ named)
{
    prc[0] = 0;
    reg_pass_rec(type, prc, fieldofs, 0);
    ਜੇ (prc[0] <= 0 || !named) {
        ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(type, &align);
        prc[0] = (ਮਾਪ + 7) >> 3;
        prc[1] = prc[2] = RC_INT;
        fieldofs[1] = (0 << 4) | (ਮਾਪ <= 1 ? VT_BYTE : ਮਾਪ <= 2 ? VT_SHORT : ਮਾਪ <= 4 ? VT_INT : VT_LLONG);
        fieldofs[2] = (8 << 4) | (ਮਾਪ <= 9 ? VT_BYTE : ਮਾਪ <= 10 ? VT_SHORT : ਮਾਪ <= 12 ? VT_INT : VT_LLONG);
    }
}

ST_FUNC ਖਾਲੀ gfunc_call(ਪੂਰਨ nb_ਦਲੀਲਾਂ)
{
    ਪੂਰਨ i, align, ਮਾਪ, areg[2];
    ਪੂਰਨ *info = tcc_malloc((nb_ਦਲੀਲਾਂ + 1) * ਆਕਾਰ (ਪੂਰਨ));
    ਪੂਰਨ ਢੇਰ_adj = 0, tempspace = 0, ਢੇਰ_ਜੋੜੋ, ofs, splitofs = 0;
    ਪੂਰਨ old = (vtop[-nb_ਦਲੀਲਾਂ].type.ref->f.func_type == FUNC_OLD);
    SValue *sv;
    Sym *sa;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਪੂਰਨ bc_save = tcc_state->do_bounds_check;
    ਜੇ (tcc_state->do_bounds_check)
        gbound_ਦਲੀਲਾਂ(nb_ਦਲੀਲਾਂ);
#ਜੇ_ਅੰਤ

    areg[0] = 0; /* int arg regs */
    areg[1] = 8; /* float arg regs */
    sa = vtop[-nb_ਦਲੀਲਾਂ].type.ref->ਅਗਲਾ;
    ਲਈ (i = 0; i < nb_ਦਲੀਲਾਂ; i++) {
        ਪੂਰਨ nregs, byref = 0, tempofs;
        ਪੂਰਨ prc[3], fieldofs[3];
        sv = &vtop[1 + i - nb_ਦਲੀਲਾਂ];
        sv->type.t &= ~VT_ARRAY; // XXX this should be done in tccgen.c
        ਮਾਪ = type_ਮਾਪ(&sv->type, &align);
        ਜੇ (ਮਾਪ > 16) {
            ਜੇ (align < XLEN)
              align = XLEN;
            tempspace = (tempspace + align - 1) & -align;
            tempofs = tempspace;
            tempspace += ਮਾਪ;
            ਮਾਪ = align = 8;
            byref = 64 | (tempofs << 7);
        }
        reg_pass(&sv->type, prc, fieldofs, old || sa != 0);
        ਜੇ (!old && !sa && align == 2*XLEN && ਮਾਪ <= 2*XLEN)
          areg[0] = (areg[0] + 1) & ~1;
        nregs = prc[0];
        ਜੇ (ਮਾਪ == 0)
            info[i] = 0;
        ਨਹੀਂਤਾਂ ਜੇ ((prc[1] == RC_INT && areg[0] >= 8)
            || (prc[1] == RC_FLOAT && areg[1] >= 16)
            || (nregs == 2 && prc[1] == RC_FLOAT && prc[2] == RC_FLOAT
                && areg[1] >= 15)
            || (nregs == 2 && prc[1] != prc[2]
                && (areg[1] >= 16 || areg[0] >= 8))) {
            info[i] = 32;
            ਜੇ (align < XLEN)
              align = XLEN;
            ਢੇਰ_adj += (ਮਾਪ + align - 1) & -align;
            ਜੇ (!old && !sa) /* one vararg on stack forces the rest on stack */
              areg[0] = 8, areg[1] = 16;
        } ਨਹੀਂਤਾਂ {
            info[i] = areg[prc[1] - 1]++;
            ਜੇ (!byref)
              info[i] |= (fieldofs[1] & VT_BTYPE) << 12;
            ਪ੍ਰਤਿਜ੍ਞਾ(!(fieldofs[1] >> 4));
            ਜੇ (nregs == 2) {
                ਜੇ (prc[2] == RC_FLOAT || areg[0] < 8)
                  info[i] |= (1 + areg[prc[2] - 1]++) << 7;
                ਨਹੀਂਤਾਂ {
                    info[i] |= 16;
                    ਢੇਰ_adj += 8;
                }
                ਜੇ (!byref) {
                    ਪ੍ਰਤਿਜ੍ਞਾ((fieldofs[2] >> 4) < 2048);
                    info[i] |= fieldofs[2] << (12 + 4); // includes offset
                }
            }
        }
        info[i] |= byref;
        ਜੇ (sa)
          sa = sa->ਅਗਲਾ;
    }
    ਢੇਰ_adj = (ਢੇਰ_adj + 15) & -16;
    tempspace = (tempspace + 15) & -16;
    ਢੇਰ_ਜੋੜੋ = ਢੇਰ_adj + tempspace;

    ਜੇ (ਢੇਰ_ਜੋੜੋ) {
        ਜੇ (ਢੇਰ_ਜੋੜੋ >= 0x800) {
            o(0x37 | (5 << 7) | ਉੱਤਲਾ_2(-ਢੇਰ_ਜੋੜੋ)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(-ਢੇਰ_ਜੋੜੋ)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        ਨਹੀਂਤਾਂ
            EI(0x13, 0, 2, 2, -ਢੇਰ_ਜੋੜੋ);   // addi sp, sp, -adj
        ਲਈ (i = ofs = 0; i < nb_ਦਲੀਲਾਂ; i++) {
            ਜੇ (info[i] & (64 | 32)) {
                vrotb(nb_ਦਲੀਲਾਂ - i);
                ਮਾਪ = type_ਮਾਪ(&vtop->type, &align);
                ਜੇ (info[i] & 64) {
                    vset(&char_ਸੂਚਕ_type, TREG_SP, 0);
                    vpushi(ਢੇਰ_adj + (info[i] >> 7));
                    gen_op('+');
                    vpushv(vtop); // this replaces the old argument
                    vrott(3);
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vpop();
                    ਮਾਪ = align = 8;
                }
                ਜੇ (info[i] & 32) {
                    ਜੇ (align < XLEN)
                      align = XLEN;
                    /* Once we support offseted regs we can do this:
                       vset(&vtop->type, TREG_SP | VT_LVAL, ofs);
                       to construct the lvalue for the outgoing stack slot,
                       until then we have to jump through hoops.  */
                    vset(&char_ਸੂਚਕ_type, TREG_SP, 0);
                    ofs = (ofs + align - 1) & -align;
                    vpushi(ofs);
                    gen_op('+');
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vtop->r = vtop->r2 = VT_CONST; // this arg is done
                    ofs += ਮਾਪ;
                }
                vrott(nb_ਦਲੀਲਾਂ - i);
            } ਨਹੀਂਤਾਂ ਜੇ (info[i] & 16) {
                ਪ੍ਰਤਿਜ੍ਞਾ(!splitofs);
                splitofs = ofs;
                ofs += 8;
            }
        }
    }
    ਲਈ (i = 0; i < nb_ਦਲੀਲਾਂ; i++) {
        ਪੂਰਨ ii = info[nb_ਦਲੀਲਾਂ - 1 - i], r = ii, r2 = r;
        ਜੇ (!(r & 32)) {
            CType origtype;
            ਪੂਰਨ loadt;
            r &= 15;
            r2 = r2 & 64 ? 0 : (r2 >> 7) & 31;
            ਪ੍ਰਤਿਜ੍ਞਾ(r2 <= 16);
            vrotb(i+1);
            origtype = vtop->type;
            ਮਾਪ = type_ਮਾਪ(&vtop->type, &align);
            ਜੇ (ਮਾਪ == 0)
                ਜਾਓ ਪੂਰਾ;
            loadt = vtop->type.t & VT_BTYPE;
            ਜੇ (loadt == VT_STRUCT) {
                loadt = (ii >> 12) & VT_BTYPE;
            }
            ਜੇ (info[nb_ਦਲੀਲਾਂ - 1 - i] & 16) {
                ਪ੍ਰਤਿਜ੍ਞਾ(!r2);
                r2 = 1 + TREG_RA;
            }
            ਜੇ (loadt == VT_LDOUBLE) {
                ਪ੍ਰਤਿਜ੍ਞਾ(r2);
                r2--;
            } ਨਹੀਂਤਾਂ ਜੇ (r2) {
                test_lvalue();
                vpushv(vtop);
            }
            vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
            gv(r < 8 ? RC_R(r) : RC_F(r - 8));
            vtop->type = origtype;

            ਜੇ (r2 && loadt != VT_LDOUBLE) {
                r2--;
                ਪ੍ਰਤਿਜ੍ਞਾ(r2 < 16 || r2 == TREG_RA);
                vswap();
                gaddrof();
                vtop->type = char_ਸੂਚਕ_type;
                vpushi(ii >> 20);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
		ਜੇ ((origtype.t & VT_BTYPE) == VT_STRUCT)
                    tcc_state->do_bounds_check = 0;
#ਜੇ_ਅੰਤ
                gen_op('+');
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
		tcc_state->do_bounds_check = bc_save;
#ਜੇ_ਅੰਤ
                indir();
                vtop->type = origtype;
                loadt = vtop->type.t & VT_BTYPE;
                ਜੇ (loadt == VT_STRUCT) {
                    loadt = (ii >> 16) & VT_BTYPE;
                }
                save_reg_upstack(r2, 1);
                vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
                ਲੱਦੋ(r2, vtop);
                ਪ੍ਰਤਿਜ੍ਞਾ(r2 < VT_CONST);
                vtop--;
                vtop->r2 = r2;
            }
            ਜੇ (info[nb_ਦਲੀਲਾਂ - 1 - i] & 16) {
                ES(0x23, 3, 2, ireg(vtop->r2), splitofs); // sd t0, ofs(sp)
                vtop->r2 = VT_CONST;
            } ਨਹੀਂਤਾਂ ਜੇ (loadt == VT_LDOUBLE && vtop->r2 != r2) {
                ਪ੍ਰਤਿਜ੍ਞਾ(vtop->r2 <= 7 && r2 <= 7);
                /* XXX we'd like to have 'gv' move directly into
                   the right class instead of us fixing it up.  */
                EI(0x13, 0, ireg(r2), ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = r2;
            }
ਪੂਰਾ:
            vrott(i+1);
        }
    }
    vrotb(nb_ਦਲੀਲਾਂ + 1);
    save_regs(nb_ਦਲੀਲਾਂ + 1);
    gcall_or_jmp(1);
    vtop -= nb_ਦਲੀਲਾਂ + 1;
    ਜੇ (ਢੇਰ_ਜੋੜੋ) {
        ਜੇ (ਢੇਰ_ਜੋੜੋ >= 0x800) {
            o(0x37 | (5 << 7) | ਉੱਤਲਾ_2(ਢੇਰ_ਜੋੜੋ)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(ਢੇਰ_ਜੋੜੋ)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        ਨਹੀਂਤਾਂ
            EI(0x13, 0, 2, 2, ਢੇਰ_ਜੋੜੋ);      // addi sp, sp, adj
   }
   tcc_free(info);
}

ਸਥਿਰ ਪੂਰਨ func_sub_sp_ਵਿੱਥ, ਅੰਕ_va_regs, func_va_list_ofs;

ST_FUNC ਖਾਲੀ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ਪੂਰਨ i, addr, align, ਮਾਪ;
    ਪੂਰਨ param_addr = 0;
    ਪੂਰਨ areg[2];
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    loc = -16; // for ra and s0
    func_sub_sp_ਵਿੱਥ = ind;
    ind += 5 * 4;

    areg[0] = 0, areg[1] = 0;
    addr = 0;
    /* if the function returns by reference, then add an
       implicit pointer parameter */
    ਮਾਪ = type_ਮਾਪ(&func_vt, &align);
    ਜੇ (ਮਾਪ > 2 * XLEN) {
        loc -= 8;
        func_vc = loc;
        ES(0x23, 3, 8, 10 + areg[0]++, loc); // sd a0, loc(s0)
    }
    /* define parameters */
    ਜਦੋਂ ((sym = sym->ਅਗਲਾ) != ਨਿਰਾ) {
        ਪੂਰਨ byref = 0;
        ਪੂਰਨ regcount;
        ਪੂਰਨ prc[3], fieldofs[3];
        type = &sym->type;
        ਮਾਪ = type_ਮਾਪ(type, &align);
        ਜੇ (ਮਾਪ > 2 * XLEN) {
            type = &char_ਸੂਚਕ_type;
            ਮਾਪ = align = byref = 8;
        }
        reg_pass(type, prc, fieldofs, 1);
        regcount = prc[0];
        ਜੇ (areg[prc[1] - 1] >= 8
            || (regcount == 2
                && ((prc[1] == RC_FLOAT && prc[2] == RC_FLOAT && areg[1] >= 7)
                    || (prc[1] != prc[2] && (areg[1] >= 8 || areg[0] >= 8))))) {
            ਜੇ (align < XLEN)
              align = XLEN;
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += ਮਾਪ;
        } ਨਹੀਂਤਾਂ {
            loc -= regcount * 8; // XXX could reserve only 'size' bytes
            param_addr = loc;
            ਲਈ (i = 0; i < regcount; i++) {
                ਜੇ (areg[prc[1+i] - 1] >= 8) {
                    ਪ੍ਰਤਿਜ੍ਞਾ(i == 1 && regcount == 2 && !(addr & 7));
                    EI(0x03, 3, 5, 8, addr); // ld t0, addr(s0)
                    addr += 8;
                    ES(0x23, 3, 8, 5, loc + i*8); // sd t0, loc(s0)
                } ਨਹੀਂਤਾਂ ਜੇ (prc[1+i] == RC_FLOAT) {
                    ES(0x27, (ਮਾਪ / regcount) == 4 ? 2 : 3, 8, 10 + areg[1]++, loc + (fieldofs[i+1] >> 4)); // fs[wd] FAi, loc(s0)
                } ਨਹੀਂਤਾਂ {
                    ES(0x23, 3, 8, 10 + areg[0]++, loc + i*8); // sd aX, loc(s0) // XXX
                }
            }
        }
        gfunc_ਸੈੱਟ_param(sym, param_addr, byref);
    }
    func_va_list_ofs = addr;
    ਅੰਕ_va_regs = 0;
    ਜੇ (func_var) {
        ਲਈ (; areg[0] < 8; areg[0]++) {
            ਅੰਕ_va_regs++;
            ES(0x23, 3, 8, 10 + areg[0], -8 + ਅੰਕ_va_regs * 8); // sd aX, loc(s0)
        }
    }
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#ਜੇ_ਅੰਤ
}

ST_FUNC ਪੂਰਨ gfunc_sret(CType *vt, ਪੂਰਨ variadic, CType *ret,
                       ਪੂਰਨ *ret_align, ਪੂਰਨ *regsize)
{
    ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(vt, &align), nregs;
    ਪੂਰਨ prc[3], fieldofs[3];
    *ret_align = 1;
    *regsize = 8;
    ਜੇ (ਮਾਪ > 16)
      ਵਾਪਸ 0;
    reg_pass(vt, prc, fieldofs, 1);
    nregs = prc[0];
    ਜੇ (nregs == 2 && prc[1] != prc[2])
      ਵਾਪਸ -1;  /* generic code can't deal with this case */
    ਜੇ (prc[1] == RC_FLOAT) {
        *regsize = ਮਾਪ / nregs;
    }
    ret->t = fieldofs[1] & VT_BTYPE;
    ret->ref = ਨਿਰਾ;
    ਵਾਪਸ nregs;
}

ST_FUNC ਖਾਲੀ arch_transfer_ret_regs(ਪੂਰਨ aftercall)
{
    ਪੂਰਨ prc[3], fieldofs[3];
    reg_pass(&vtop->type, prc, fieldofs, 1);
    ਪ੍ਰਤਿਜ੍ਞਾ(prc[0] == 2 && prc[1] != prc[2] && !(fieldofs[1] >> 4));
    ਪ੍ਰਤਿਜ੍ਞਾ(vtop->r == (VT_LOCAL | VT_LVAL));
    vpushv(vtop);
    vtop->type.t = fieldofs[1] & VT_BTYPE;
    (aftercall ? store : ਲੱਦੋ)(prc[1] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop->c.i += fieldofs[2] >> 4;
    vtop->type.t = fieldofs[2] & VT_BTYPE;
    (aftercall ? store : ਲੱਦੋ)(prc[2] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop--;
}

ST_FUNC ਖਾਲੀ gfunc_epilog(ਖਾਲੀ)
{
    ਪੂਰਨ v, saved_ind, d, large_ofs_ind;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#ਜੇ_ਅੰਤ

    loc = (loc - ਅੰਕ_va_regs * 8);
    d = v = (-loc + 15) & -16;

    EI(0x13, 0, 2, 8, ਅੰਕ_va_regs * 8); // addi sp, s0, num_va_regs*8
    EI(0x03, 3, 1, 8, -8); // ld ra, -8(s0)
    EI(0x03, 3, 8, 8, -16); // ld s0, -16(s0)
    EI(0x67, 0, 0, 1, 0); // jalr x0, 0(x1), aka ret

    large_ofs_ind = ind;
    ਜੇ (v >= (1 << 11)) {
        d = 16;
        EI(0x13, 0, 8, 2, d - ਅੰਕ_va_regs * 8);      // addi s0, sp, d
        o(0x37 | (5 << 7) | ਉੱਤਲਾ_2(v-16)); //lui t0, upper(v)
        EI(0x13, 0, 5, 5, SIGN11(v-16)); // addi t0, t0, lo(v)
        ER(0x33, 0, 2, 2, 5, 0x20); // sub sp, sp, t0
        gjmp_addr(func_sub_sp_ਵਿੱਥ + 5*4);
    }
    saved_ind = ind;

    ind = func_sub_sp_ਵਿੱਥ;
    EI(0x13, 0, 2, 2, -d);     // addi sp, sp, -d
    ES(0x23, 3, 2, 1, d - 8 - ਅੰਕ_va_regs * 8);  // sd ra, d-8(sp)
    ES(0x23, 3, 2, 8, d - 16 - ਅੰਕ_va_regs * 8); // sd s0, d-16(sp)
    ਜੇ (v < (1 << 11))
      EI(0x13, 0, 8, 2, d - ਅੰਕ_va_regs * 8);      // addi s0, sp, d
    ਨਹੀਂਤਾਂ
      gjmp_addr(large_ofs_ind);
    ਜੇ ((ind - func_sub_sp_ਵਿੱਥ) != 5*4)
      EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
    ind = saved_ind;
}

ST_FUNC ਖਾਲੀ gen_va_ਸ਼ੁਰੂ(ਖਾਲੀ)
{
    vtop--;
    vset(&char_ਸੂਚਕ_type, VT_LOCAL, func_va_list_ofs);
}

ST_FUNC ਖਾਲੀ gen_fill_nops(ਪੂਰਨ ਬਾਈਟਾਂ)
{
    ਜੇ ((ਬਾਈਟਾਂ & 3))
      tcc_error("alignment of code section not multiple of 4");
    ਜਦੋਂ (ਬਾਈਟਾਂ > 0) {
        EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
        ਬਾਈਟਾਂ -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC ਪੂਰਨ gjmp(ਪੂਰਨ t)
{
    ਜੇ (nocode_wanted)
      ਵਾਪਸ t;
    o(t);
    ਵਾਪਸ ind - 4;
}

// Generate branch to known address:
ST_FUNC ਖਾਲੀ gjmp_addr(ਪੂਰਨ a)
{
    uint32_t r = a - ind, imm;
    ਜੇ ((r + (1 << 21)) & ~((1U << 22) - 2)) {
        o(0x17 | (5 << 7) | ਉੱਤਲਾ_2(r)); // lui RR, up(r)
        r = SIGN11(r);
        EI(0x67, 0, 0, 5, r);      // jalr x0, r(t0)
    } ਨਹੀਂਤਾਂ {
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        o(0x6f | imm); // jal x0, imm ==  j imm
    }
}

ST_FUNC ਪੂਰਨ gjmp_cond(ਪੂਰਨ op, ਪੂਰਨ t)
{
    ਪੂਰਨ tmp;
    ਪੂਰਨ a = vtop->cmp_r & 0xff;
    ਪੂਰਨ b = (vtop->cmp_r >> 8) & 0xff;
    ਚੋਣ (op) {
        ਹਾਲਤ TOK_ULT: op = 6; ਰੋਕੋ;
        ਹਾਲਤ TOK_UGE: op = 7; ਰੋਕੋ;
        ਹਾਲਤ TOK_ULE: op = 7; tmp = a; a = b; b = tmp; ਰੋਕੋ;
        ਹਾਲਤ TOK_UGT: op = 6; tmp = a; a = b; b = tmp; ਰੋਕੋ;
        ਹਾਲਤ TOK_LT:  op = 4; ਰੋਕੋ;
        ਹਾਲਤ TOK_GE:  op = 5; ਰੋਕੋ;
        ਹਾਲਤ TOK_LE:  op = 5; tmp = a; a = b; b = tmp; ਰੋਕੋ;
        ਹਾਲਤ TOK_GT:  op = 4; tmp = a; a = b; b = tmp; ਰੋਕੋ;
        ਹਾਲਤ TOK_NE:  op = 1; ਰੋਕੋ;
        ਹਾਲਤ TOK_EQ:  op = 0; ਰੋਕੋ;
    }
    o(0x63 | (op ^ 1) << 12 | a << 15 | b << 20 | 8 << 7); // bOP a,b,+4
    ਵਾਪਸ gjmp(t);
}

ST_FUNC ਪੂਰਨ gjmp_append(ਪੂਰਨ n, ਪੂਰਨ t)
{
    ਖਾਲੀ *p;
    /* insert jump list n into t */
    ਜੇ (n) {
        uint32_t n1 = n, n2;
        ਜਦੋਂ ((n2 = read32le(p = cur_ਪਾਠ_section->ਅੰਕੜੇ + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    ਵਾਪਸ t;
}

ਸਥਿਰ ਖਾਲੀ gen_opil(ਪੂਰਨ op, ਪੂਰਨ ll)
{
    ਪੂਰਨ a, b, d;
    ਪੂਰਨ func3 = 0;
    ll = ll ? 0 : 8;
    ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
        ਪੂਰਨ fc = vtop->c.i;
        ਜੇ (fc == vtop->c.i && !ਨੀਵਾਂ_ਉਛਾਲ(fc)) {
            ਪੂਰਨ cll = 0;
            ਪੂਰਨ m = ll ? 31 : 63;
            vswap();
            gv(RC_INT);
            a = ireg(vtop[0].r);
            --vtop;
            d = get_reg(RC_INT);
            ++vtop;
            vswap();
            ਚੋਣ (op) {
                ਹਾਲਤ '-':
                    ਜੇ (fc <= -(1 << 11))
                      ਰੋਕੋ;
                    fc = -fc;
                ਹਾਲਤ '+':
                    func3 = 0; // addi d, a, fc
                    cll = ll;
                do_cop:
                    EI(0x13 | cll, func3, ireg(d), a, fc);
                    --vtop;
                    ਜੇ (op >= TOK_ULT && op <= TOK_GT) {
                      vset_VT_CMP(TOK_NE);
                      vtop->cmp_r = ireg(d) | 0 << 8;
                    } ਨਹੀਂਤਾਂ
                      vtop[0].r = d;
                    ਵਾਪਸ;
                ਹਾਲਤ TOK_LE:
                    ਜੇ (fc >= (1 << 11) - 1)
                      ਰੋਕੋ;
                    ++fc;
                ਹਾਲਤ TOK_LT:  func3 = 2; ਜਾਓ do_cop; // slti d, a, fc
                ਹਾਲਤ TOK_ULE:
                    ਜੇ (fc >= (1 << 11) - 1 || fc == -1)
                      ਰੋਕੋ;
                    ++fc;
                ਹਾਲਤ TOK_ULT: func3 = 3; ਜਾਓ do_cop; // sltiu d, a, fc
                ਹਾਲਤ '^':     func3 = 4; ਜਾਓ do_cop; // xori d, a, fc
                ਹਾਲਤ '|':     func3 = 6; ਜਾਓ do_cop; // ori  d, a, fc
                ਹਾਲਤ '&':     func3 = 7; ਜਾਓ do_cop; // andi d, a, fc
                ਹਾਲਤ TOK_SHL: func3 = 1; cll = ll; fc &= m; ਜਾਓ do_cop; // slli d, a, fc
                ਹਾਲਤ TOK_SHR: func3 = 5; cll = ll; fc &= m; ਜਾਓ do_cop; // srli d, a, fc
                ਹਾਲਤ TOK_SAR: func3 = 5; cll = ll; fc = 1024 | (fc & m); ਜਾਓ do_cop;

                ਹਾਲਤ TOK_UGE: /* -> TOK_ULT */
                ਹਾਲਤ TOK_UGT: /* -> TOK_ULE */
                ਹਾਲਤ TOK_GE:  /* -> TOK_LT */
                ਹਾਲਤ TOK_GT:  /* -> TOK_LE */
                    gen_opil(op - 1, !ll);
                    vtop->cmp_op ^= 1;
                    ਵਾਪਸ;

                ਹਾਲਤ TOK_NE:
                ਹਾਲਤ TOK_EQ:
                    ਜੇ (fc)
                      gen_opil('-', !ll), a = ireg(vtop++->r);
                    --vtop;
                    vset_VT_CMP(op);
                    vtop->cmp_r = a | 0 << 8;
                    ਵਾਪਸ;
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
    ਚੋਣ (op) {
    ਮੂਲ:
        ਜੇ (op >= TOK_ULT && op <= TOK_GT) {
            vset_VT_CMP(op);
            vtop->cmp_r = a | b << 8;
            ਰੋਕੋ;
        }
        tcc_error("implement me: %s(%s)", __FUNCTION__, get_tok_str(op, ਨਿਰਾ));
        ਰੋਕੋ;

    ਹਾਲਤ '+':
        ER(0x33 | ll, 0, d, a, b, 0); // add d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ '-':
        ER(0x33 | ll, 0, d, a, b, 0x20); // sub d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ TOK_SAR:
        ER(0x33 | ll | ll, 5, d, a, b, 0x20); // sra d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ TOK_SHR:
        ER(0x33 | ll | ll, 5, d, a, b, 0); // srl d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ TOK_SHL:
        ER(0x33 | ll, 1, d, a, b, 0); // sll d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ '*':
        ER(0x33 | ll, 0, d, a, b, 1); // mul d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ '/':
    ਹਾਲਤ TOK_PDIV:
        ER(0x33 | ll, 4, d, a, b, 1); // div d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ '&':
        ER(0x33, 7, d, a, b, 0); // and d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ '^':
        ER(0x33, 4, d, a, b, 0); // xor d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ '|':
        ER(0x33, 6, d, a, b, 0); // or d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ '%':
        ER(ll ? 0x3b:  0x33, 6, d, a, b, 1); // rem d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ TOK_UMOD:
        ER(0x33 | ll, 7, d, a, b, 1); // remu d, a, b
        ਰੋਕੋ;
    ਹਾਲਤ TOK_UDIV:
        ER(0x33 | ll, 5, d, a, b, 1); // divu d, a, b
        ਰੋਕੋ;
    }
}

ST_FUNC ਖਾਲੀ gen_opi(ਪੂਰਨ op)
{
    gen_opil(op, 0);
}

ST_FUNC ਖਾਲੀ gen_opl(ਪੂਰਨ op)
{
    gen_opil(op, 1);
}

ST_FUNC ਖਾਲੀ gen_opf(ਪੂਰਨ op)
{
    ਪੂਰਨ rs1, rs2, rd, dbl, invert;
    ਜੇ (vtop[0].type.t == VT_LDOUBLE) {
        CType type = vtop[0].type;
        ਪੂਰਨ func = 0;
        ਪੂਰਨ cond = -1;
        ਚੋਣ (op) {
        ਹਾਲਤ '*': func = TOK___multf3; ਰੋਕੋ;
        ਹਾਲਤ '+': func = TOK___addtf3; ਰੋਕੋ;
        ਹਾਲਤ '-': func = TOK___subtf3; ਰੋਕੋ;
        ਹਾਲਤ '/': func = TOK___divtf3; ਰੋਕੋ;
        ਹਾਲਤ TOK_EQ: func = TOK___eqtf2; cond = 1; ਰੋਕੋ;
        ਹਾਲਤ TOK_NE: func = TOK___netf2; cond = 0; ਰੋਕੋ;
        ਹਾਲਤ TOK_LT: func = TOK___lttf2; cond = 10; ਰੋਕੋ;
        ਹਾਲਤ TOK_GE: func = TOK___getf2; cond = 11; ਰੋਕੋ;
        ਹਾਲਤ TOK_LE: func = TOK___letf2; cond = 12; ਰੋਕੋ;
        ਹਾਲਤ TOK_GT: func = TOK___gttf2; cond = 13; ਰੋਕੋ;
        ਮੂਲ: ਪ੍ਰਤਿਜ੍ਞਾ(0); ਰੋਕੋ;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = REG_IRET;
        vtop->r2 = cond < 0 ? TREG_R(1) : VT_CONST;
        ਜੇ (cond < 0)
            vtop->type = type;
        ਨਹੀਂਤਾਂ {
            vpushi(0);
            gen_opil(op, 1);
        }
        ਵਾਪਸ;
    }

    gv2(RC_FLOAT, RC_FLOAT);
    ਪ੍ਰਤਿਜ੍ਞਾ(vtop->type.t == VT_DOUBLE || vtop->type.t == VT_FLOAT);
    dbl = vtop->type.t == VT_DOUBLE;
    rs1 = freg(vtop[-1].r);
    rs2 = freg(vtop->r);
    vtop--;
    invert = 0;
    ਚੋਣ(op) {
    ਮੂਲ:
        ਪ੍ਰਤਿਜ੍ਞਾ(0);
    ਹਾਲਤ '+':
        op = 0; // fadd
    arithop:
        rd = get_reg(RC_FLOAT);
        vtop->r = rd;
        rd = freg(rd);
        ER(0x53, 7, rd, rs1, rs2, dbl | (op << 2)); // fop.[sd] RD, RS1, RS2 (dyn rm)
        ਰੋਕੋ;
    ਹਾਲਤ '-':
        op = 1; // fsub
        ਜਾਓ arithop;
    ਹਾਲਤ '*':
        op = 2; // fmul
        ਜਾਓ arithop;
    ਹਾਲਤ '/':
        op = 3; // fdiv
        ਜਾਓ arithop;
    ਹਾਲਤ TOK_EQ:
        op = 2; // EQ
    cmpop:
        rd = get_reg(RC_INT);
        vtop->r = rd;
        rd = ireg(rd);
        ER(0x53, op, rd, rs1, rs2, dbl | 0x50); // fcmp.[sd] RD, RS1, RS2 (op == eq/lt/le)
        ਜੇ (invert)
          EI(0x13, 4, rd, rd, 1); // xori RD, 1

        /* generate VT_CMP output */
        vset_VT_CMP(TOK_NE);
        vtop->cmp_r = rd | (0 << 8);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_NE:
        invert = 1;
        op = 2; // EQ
        ਜਾਓ cmpop;
    ਹਾਲਤ TOK_LT:
        op = 1; // LT
        ਜਾਓ cmpop;
    ਹਾਲਤ TOK_LE:
        op = 0; // LE
        ਜਾਓ cmpop;
    ਹਾਲਤ TOK_GT:
        op = 1; // LT
        rd = rs1, rs1 = rs2, rs2 = rd;
        ਜਾਓ cmpop;
    ਹਾਲਤ TOK_GE:
        op = 0; // LE
        rd = rs1, rs1 = rs2, rs2 = rd;
        ਜਾਓ cmpop;
    }
}

ST_FUNC ਖਾਲੀ gen_cvt_csti(ਪੂਰਨ t)
{
    ਪੂਰਨ r = ireg(gv(RC_INT));
    ਜੇ ((t & VT_BTYPE) == VT_SHORT) {
        ਜੇ (t & VT_UNSIGNED) {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EI(0x13, 5, r, r, 48); // srli r, r, 48
        } ਨਹੀਂਤਾਂ {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EIu(0x13, 5, r, r, 0x400 | 48); // srai r, r, 48
        }
    } ਨਹੀਂਤਾਂ {
        ਜੇ (t & VT_UNSIGNED) {
            EI(0x13, 7, r, r, 0xff); // andi r, r, 0xff
        } ਨਹੀਂਤਾਂ {
            EI(0x13, 1, r, r, 56); // slli r, r, 56
            EIu(0x13, 5, r, r, 0x400 | 56); // srai r, r, 56
        }
    }
}

ST_FUNC ਖਾਲੀ gen_cvt_sxtw(ਖਾਲੀ)
{
    ਪੂਰਨ r = ireg(gv(RC_INT));
    EI(0x1b, 0, r, r, 0); // addiw r, r, 0
}

ST_FUNC ਖਾਲੀ gen_cvt_itof(ਪੂਰਨ t)
{
    ਪੂਰਨ rr = ireg(gv(RC_INT)), dr;
    ਪੂਰਨ u = vtop->type.t & VT_UNSIGNED;
    ਪੂਰਨ l = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    ਜੇ (t == VT_LDOUBLE) {
        ਪੂਰਨ func = l ?
          (u ? TOK___floatunditf : TOK___floatditf) :
          (u ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        vtop->r2 = TREG_R(1);
    } ਨਹੀਂਤਾਂ {
        vtop--;
        dr = get_reg(RC_FLOAT);
        vtop++;
        vtop->r = dr;
        dr = freg(dr);
        EIu(0x53, 7, dr, rr, ((0x68 | (t == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[sd].[wl][u]
    }
}

ST_FUNC ਖਾਲੀ gen_cvt_ftoi(ਪੂਰਨ t)
{
    ਪੂਰਨ ft = vtop->type.t & VT_BTYPE;
    ਪੂਰਨ l = (t & VT_BTYPE) == VT_LLONG;
    ਪੂਰਨ u = t & VT_UNSIGNED;
    ਜੇ (ft == VT_LDOUBLE) {
        ਪੂਰਨ func = l ?
          (u ? TOK___fixunstfdi : TOK___fixtfdi) :
          (u ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
    } ਨਹੀਂਤਾਂ {
        ਪੂਰਨ rr = freg(gv(RC_FLOAT)), dr;
        vtop--;
        dr = get_reg(RC_INT);
        vtop++;
        vtop->r = dr;
        dr = ireg(dr);
        EIu(0x53, 1, dr, rr, ((0x60 | (ft == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[wl][u].[sd] rtz
    }
}

ST_FUNC ਖਾਲੀ gen_cvt_ftof(ਪੂਰਨ dt)
{
    ਪੂਰਨ st = vtop->type.t & VT_BTYPE, rs, rd;
    dt &= VT_BTYPE;
    ਜੇ (st == dt)
      ਵਾਪਸ;
    ਜੇ (dt == VT_LDOUBLE || st == VT_LDOUBLE) {
        ਪੂਰਨ func = (dt == VT_LDOUBLE) ?
            (st == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (dt == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        /* We can't use gfunc_call, as func_old_type works like vararg
           functions, and on riscv unnamed float args are passed like
           integers.  But we really need them in the float argument registers
           for extendsftf2/extenddftf2.  So, do it explicitely.  */
        save_regs(1);
        ਜੇ (dt == VT_LDOUBLE)
          gv(RC_F(0));
        ਨਹੀਂਤਾਂ {
            gv(RC_R(0));
            ਪ੍ਰਤਿਜ੍ਞਾ(vtop->r2 < 7);
            ਜੇ (vtop->r2 != 1 + vtop->r) {
                EI(0x13, 0, ireg(vtop->r) + 1, ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = 1 + vtop->r;
            }
        }
        vpush_helper_func(func);
        gcall_or_jmp(1);
        vtop -= 2;
        vpushi(0);
        vtop->type.t = dt;
        ਜੇ (dt == VT_LDOUBLE)
          vtop->r = REG_IRET, vtop->r2 = REG_IRET+1;
        ਨਹੀਂਤਾਂ
          vtop->r = REG_FRET;
    } ਨਹੀਂਤਾਂ {
        ਪ੍ਰਤਿਜ੍ਞਾ (dt == VT_FLOAT || dt == VT_DOUBLE);
        ਪ੍ਰਤਿਜ੍ਞਾ (st == VT_FLOAT || st == VT_DOUBLE);
        rs = gv(RC_FLOAT);
        rd = get_reg(RC_FLOAT);
        ਜੇ (dt == VT_DOUBLE)
          EI(0x53, 0, freg(rd), freg(rs), 0x21 << 5); // fcvt.d.s RD, RS (no rm)
        ਨਹੀਂਤਾਂ
          EI(0x53, 7, freg(rd), freg(rs), (0x20 << 5) | 1); // fcvt.s.d RD, RS (dyn rm)
        vtop->r = rd;
    }
}

/* increment tcov counter */
ST_FUNC ਖਾਲੀ gen_increment_tcov (SValue *sv)
{
    ਪੂਰਨ r1, r2;
    Sym label = {0};
    label.type.t = VT_VOID | VT_STATIC;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    r1 = ireg(r1);
    r2 = ireg(r2);
    greloca(cur_ਪਾਠ_section, sv->sym, ind, R_RISCV_PCREL_HI20, 0);
    put_extern_sym(&label, cur_ਪਾਠ_section, ind, 0);
    o(0x17 | (r1 << 7)); // auipc RR, 0 %pcrel_hi(sym)
    greloca(cur_ਪਾਠ_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, r2, r1, 0); // ld r2, x[r1]
    EI(0x13, 0, r2, r2, 1); // addi r2, r2, #1
    greloca(cur_ਪਾਠ_section, sv->sym, ind, R_RISCV_PCREL_HI20, 0);
    label.c = 0; /* force new local ELF symbol */
    put_extern_sym(&label, cur_ਪਾਠ_section, ind, 0);
    o(0x17 | (r1 << 7)); // auipc RR, 0 %pcrel_hi(sym)
    greloca(cur_ਪਾਠ_section, &label, ind, R_RISCV_PCREL_LO12_S, 0);
    ES(0x23, 3, r1, r2, 0); // sd r2, [r1]
    vpop();
}

ST_FUNC ਖਾਲੀ ggoto(ਖਾਲੀ)
{
    gcall_or_jmp(0);
    vtop--;
}

ST_FUNC ਖਾਲੀ gen_vla_sp_save(ਪੂਰਨ addr)
{
    ਜੇ (ਨੀਵਾਂ_ਉਛਾਲ(addr)) {
	o(0x37 | (5 << 7) | ਉੱਤਲਾ_2(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        ES(0x23, 3, 5, 2, SIGN11(addr)); // sd sp, fc(t0)
    }
    ਨਹੀਂਤਾਂ
        ES(0x23, 3, 8, 2, addr); // sd sp, fc(s0)
}

ST_FUNC ਖਾਲੀ gen_vla_sp_restore(ਪੂਰਨ addr)
{
    ਜੇ (ਨੀਵਾਂ_ਉਛਾਲ(addr)) {
	o(0x37 | (5 << 7) | ਉੱਤਲਾ_2(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        EI(0x03, 3, 2, 5, SIGN11(addr)); // ld sp, fc(t0)
    }
    ਨਹੀਂਤਾਂ
        EI(0x03, 3, 2, 8, addr); // ld sp, fc(s0)
}

ST_FUNC ਖਾਲੀ gen_vla_alloc(CType *type, ਪੂਰਨ align)
{
    ਪੂਰਨ rr;
#ਜੇ defined(CONFIG_TCC_BCHECK)
    ਜੇ (tcc_state->do_bounds_check)
        vpushv(vtop);
#ਜੇ_ਅੰਤ
    rr = ireg(gv(RC_INT));
#ਜੇ defined(CONFIG_TCC_BCHECK)
    ਜੇ (tcc_state->do_bounds_check)
        EI(0x13, 0, rr, rr, 15+1);   // addi RR, RR, 15+1
    ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
    EI(0x13, 0, rr, rr, 15);   // addi RR, RR, 15
    EI(0x13, 7, rr, rr, -16);  // andi, RR, RR, -16
    ER(0x33, 0, 2, 2, rr, 0x20); // sub sp, sp, rr
    vpop();
#ਜੇ defined(CONFIG_TCC_BCHECK)
    ਜੇ (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x00010513); /* mv a0,sp */
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_ਜੋੜੋ_epilog = 1;
    }
#ਜੇ_ਅੰਤ
}

ST_FUNC ਖਾਲੀ gen_clear_cache(ਖਾਲੀ)
{
    /* Zifencei extension: fence + fence.i for I/D synchronization.
       Required by RISC-V Linux ABI, present on all Linux-capable cores. */
    o(0x0ff0000f); // fence iorw, iorw
    o(0x0000100f); // fence.i
}
#ਜੇ_ਅੰਤ
