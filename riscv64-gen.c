#اگر_تعریف_شدہ ہدف_DEFS_ONLY

// Number of registers available to allocator:
#تعریف_کرو NB_REGS 19 // x10-x17 aka a0-a7, f10-f17 aka fa0-fa7, xxx, ra, sp
#تعریف_کرو CONFIG_TCC_ASM

#تعریف_کرو TREG_R(x) (x) // x = 0..7
#تعریف_کرو TREG_F(x) (x + 8) // x = 0..7

// Register classes sorted from more general to more precise:
#تعریف_کرو RC_INT (1 << 0)
#تعریف_کرو RC_FLOAT (1 << 1)
#تعریف_کرو RC_R(x) (1 << (2 + (x))) // x = 0..7
#تعریف_کرو RC_F(x) (1 << (10 + (x))) // x = 0..7

#تعریف_کرو RC_IRET (RC_R(0)) // int return register class
#تعریف_کرو RC_IRE2 (RC_R(1)) // int 2nd return register class
#تعریف_کرو RC_FRET (RC_F(0)) // float return register class

#تعریف_کرو REG_IRET (TREG_R(0)) // int return register number
#تعریف_کرو REG_IRE2 (TREG_R(1)) // int 2nd return register number
#تعریف_کرو REG_FRET (TREG_F(0)) // float return register number

#تعریف_کرو PTR_سائز 8

#تعریف_کرو LDOUBLE_سائز 16
#تعریف_کرو LDOUBLE_ALIGN 16

#تعریف_کرو MAX_ALIGN 16

#تعریف_کرو CHAR_IS_UNSIGNED

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#تعریف_کرو PROMOTE_RET

#ورنہ
#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"
#شامل <assert.h>

#تعریف_کرو بالائی_2(x)	(((غیرعلامتی)(x) + 0x800u) & 0xfffff000)
#تعریف_کرو کم_حد_سے_تجاوز(x)	بالائی_2(x)
#تعریف_کرو SIGN7(x)	((((x) & 0xff) ^ 0x80) - 0x80)
#تعریف_کرو SIGN11(x)	((((x) & 0xfff) ^ 0x800) - 0x800)

ST_ڈیٹا ثابت حرف * ثابت ہدف_machine_defs =
    "__riscv\0"
    "__riscv_xlen 64\0"
    "__riscv_flen 64\0"
    "__riscv_div\0"
    "__riscv_mul\0"
    "__riscv_fdiv\0"
    "__riscv_fsqrt\0"
    "__riscv_float_abi_double\0"
    ;

#تعریف_کرو XLEN 8

#تعریف_کرو TREG_RA 17
#تعریف_کرو TREG_SP 18

ST_ڈیٹا ثابت صحیح reg_classes[NB_REGS] = {
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

#اگر defined(CONFIG_TCC_BCHECK)
ساکن addr_t func_bound_انحراف;
ساکن غیرعلامتی طویل func_bound_ind;
ST_ڈیٹا صحیح func_bound_جوڑو_epilog;
#اگر_ختم

ساکن صحیح ireg(صحیح r)
{
    اگر (r == TREG_RA)
      واپس 1; // ra
    اگر (r == TREG_SP)
      واپس 2; // sp
    أكد(r >= 0 && r < 8);
    واپس r + 10;  // tccrX --> aX == x(10+X)
}

ساکن صحیح is_ireg(صحیح r)
{
    واپس (غیرعلامتی)r < 8 || r == TREG_RA || r == TREG_SP;
}

ساکن صحیح freg(صحیح r)
{
    أكد(r >= 8 && r < 16);
    واپس r - 8 + 10;  // tccfX --> faX == f(10+X)
}

ساکن صحیح is_freg(صحیح r)
{
    واپس r >= 8 && r < 16;
}

ST_FUNC خالی o(غیرعلامتی صحیح c)
{
    صحیح ind1 = ind + 4;
    اگر (nocode_wanted)
        واپس;
    اگر (ind1 > cur_متن_section->ڈیٹا_allocated)
        section_realloc(cur_متن_section, ind1);
    write32le(cur_متن_section->ڈیٹا + ind, c);
    ind = ind1;
}

ساکن خالی EIu(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    o(opcode | (func3 << 12) | (rd << 7) | (rs1 << 15) | (imm << 20));
}

ساکن خالی ER(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t func7)
{
    o(opcode | func3 << 12 | rd << 7 | rs1 << 15 | rs2 << 20 | func7 << 25);
}

ساکن خالی EI(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    أكد(! کم_حد_سے_تجاوز(imm));
    EIu(opcode, func3, rd, rs1, imm);
}

ساکن خالی ES(uint32_t opcode, uint32_t func3,
               uint32_t rs1, uint32_t rs2, uint32_t imm)
{
    أكد(! کم_حد_سے_تجاوز(imm));
    o(opcode | (func3 << 12) | ((imm & 0x1f) << 7) | (rs1 << 15)
      | (rs2 << 20) | ((imm >> 5) << 25));
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC خالی gsym_addr(صحیح t_, صحیح a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    جب (t) {
        غیرعلامتی حرف *ptr = cur_متن_section->ڈیٹا + t;
        uint32_t اگلا = read32le(ptr);
        uint32_t r = a - t, imm;
        اگر ((r + (1 << 21)) & ~((1U << 22) - 2))
          tcc_error("out-of-range branch chain");
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        write32le(ptr, r == 4 ? 0x33 : 0x6f | imm); // nop || j imm
        t = اگلا;
    }
}

ساکن صحیح بھرو_symofs(صحیح r, SValue *sv, صحیح forstore, صحیح *new_fc)
{
    صحیح rr, doload = 0, large_addend = 0;
    صحیح fc = sv->c.i, v = sv->r & VT_VALMASK;
    اگر (sv->r & VT_SYM) {
        Sym label = {0};
        أكد(v == VT_CONST);
        اگر (sv->sym->type.t & VT_TLS) {
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
            واپس rr;
        }
        اگر (sv->sym->type.t & VT_STATIC) { // XXX do this per linker relax
            greloca(cur_متن_section, sv->sym, ind,
                    R_RISCV_PCREL_HI20, sv->c.i);
            *new_fc = 0;
        } ورنہ {
            اگر (کم_حد_سے_تجاوز(fc)){
              large_addend = 1;
            }
            greloca(cur_متن_section, sv->sym, ind,
                    R_RISCV_GOT_HI20, 0);
            doload = 1;
        }
        label.type.t = VT_VOID | VT_STATIC;
	اگر (!nocode_wanted)
            put_extern_sym(&label, cur_متن_section, ind, 0);
        rr = is_ireg(r) ? ireg(r) : 5;
        o(0x17 | (rr << 7));   // auipc RR, 0 %pcrel_hi(sym)+addend
        greloca(cur_متن_section, &label, ind,
                doload || !forstore
                  ? R_RISCV_PCREL_LO12_I : R_RISCV_PCREL_LO12_S, 0);
        اگر (doload) {
            EI(0x03, 3, rr, rr, 0); // ld RR, 0(RR)
            اگر (large_addend) {
                o(0x37 | (6 << 7) | بالائی_2(fc)); //lui t1, high(fc)
                ER(0x33, 0, rr, rr, 6, 0); // add RR, RR, t1
                *new_fc = SIGN11(fc);
            }
        }
    } ورنہ اگر (v == VT_LOCAL || v == VT_LLOCAL) {
        rr = 8; // s0
        اگر (fc != sv->c.i)
          tcc_error("unimp: store(giant local off) (0x%lx)", (طویل)sv->c.i);
        اگر (کم_حد_سے_تجاوز(fc)) {
            rr = is_ireg(r) ? ireg(r) : 5; // t0
            o(0x37 | (rr << 7) | بالائی_2(fc)); //lui RR, upper(fc)
            ER(0x33, 0, rr, rr, 8, 0); // add RR, RR, s0
            *new_fc = SIGN11(fc);
        }
    } ورنہ
      tcc_error("uhh");
    واپس rr;
}

ساکن خالی بھرو_large_constant(صحیح rr, صحیح fc, uint32_t pi)
{
    اگر (fc < 0)
	pi++;
    o(0x37 | (rr << 7) | بالائی_2(pi)); // lui RR, up(up(fc))
    EI(0x13, 0, rr, rr, SIGN11(pi));   // addi RR, RR, lo(up(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((غیرعلامتی)fc + (1 << 19)) >> 20)); // addi RR, RR, up(lo(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((غیرعلامتی)fc + (1 << 7)) >> 8));  // addi RR, RR, lo1(lo(fc))
    EI(0x13, 1, rr, rr, 8); // slli RR, RR, 8
}

ST_FUNC خالی بھرو(صحیح r, SValue *sv)
{
    صحیح fr = sv->r;
    صحیح v = fr & VT_VALMASK;
    صحیح rr = is_ireg(r) ? ireg(r) : freg(r);
    صحیح fc = sv->c.i;
    صحیح bt = sv->type.t & VT_BTYPE;
    صحیح align, سائز;
    اگر (fr & VT_LVAL) {
        صحیح func3, opcode = is_freg(r) ? 0x07 : 0x03, br;
        سائز = type_سائز(&sv->type, &align);
        أكد (!is_freg(r) || bt == VT_FLOAT || bt == VT_DOUBLE);
        اگر (bt == VT_PTR || bt == VT_FUNC) /* XXX should be done in generic code */
          سائز = PTR_سائز;
        func3 = سائز == 1 ? 0 : سائز == 2 ? 1 : سائز == 4 ? 2 : 3;
        اگر (سائز < 4 && !is_float(sv->type.t) && (sv->type.t & VT_UNSIGNED))
          func3 |= 4;
        اگر (v == VT_LOCAL || (fr & VT_SYM)) {
            br = بھرو_symofs(r, sv, 0, &fc);
        } ورنہ اگر (v < VT_CONST) {
            br = ireg(v);
            /*if (LOW_OVERFLOW(fc))
              tcc_error("unimp: load(large addend) (0x%x)", fc);*/
            fc = 0; // XXX store ofs in LVAL(reg)
        } ورنہ اگر (v == VT_LLOCAL) {
            br = بھرو_symofs(r, sv, 0, &fc);
            EI(0x03, 3, rr, br, fc); // ld RR, fc(BR)
            br = rr;
            fc = 0;
        } ورنہ اگر (v == VT_CONST) {
            int64_t si = sv->c.i;
            si >>= 32;
            اگر (si != 0) {
		بھرو_large_constant(rr, fc, si);
                fc = SIGN7(fc);
            } ورنہ {
                o(0x37 | (rr << 7) | بالائی_2(fc)); //lui RR, upper(fc)
                fc = SIGN11(fc);
	    }
            br = rr;
	} ورنہ {
            tcc_error("unimp: load(non-local lval)");
        }
        EI(opcode, func3, rr, br, fc); // l[bhwd][u] / fl[wd] RR, fc(BR)
    } ورنہ اگر (v == VT_CONST) {
        صحیح rb = 0, do32bit = 8, zext = 0;
        اگر (is_float(sv->type.t) && bt != VT_LDOUBLE) {
            /* load float/double constant: move bit pattern from int reg */
            uint64_t val = sv->c.i;
            صحیح is_dbl = bt == VT_DOUBLE;
            اگر (val == 0) {
                o(0x53 | (rr << 7) | ((غیرعلامتی)(0x78 | is_dbl) << 25));
                واپس;
            }
            اگر (is_dbl) {
                بھرو_large_constant(6, (صحیح)val, (صحیح)(val >> 32));
            } ورنہ {
                اگر (کم_حد_سے_تجاوز(fc))
                    o(0x37 | (6 << 7) | بالائی_2(fc)); // lui t1, upper
                EI(0x13 | 8, 0, 6, کم_حد_سے_تجاوز(fc) ? 6 : 0, SIGN11(fc)); // addiw t1,...
            }
            o(0x53 | (rr << 7) | (6 << 15) | ((غیرعلامتی)(0x78 | is_dbl) << 25));
            واپس;
        }
        أكد(is_ireg(r) || bt == VT_LDOUBLE);
        اگر (fr & VT_SYM) {
            rb = بھرو_symofs(r, sv, 0, &fc);
            do32bit = 0;
        }
        اگر (do32bit && fc != sv->c.i) {
            int64_t si = sv->c.i;
            si >>= 32;
            اگر (si != 0) {
		بھرو_large_constant(rr, fc, si);
                fc = SIGN7(fc);
                rb = rr;
                do32bit = 0;
            } ورنہ اگر (bt == VT_LLONG) {
                /* A 32bit unsigned constant for a 64bit type.
                   lui always sign extends, so we need to do an explicit zext.*/
                zext = 1;
            }
        }
        اگر (کم_حد_سے_تجاوز(fc))
            o(0x37 | (rr << 7) | بالائی_2(fc)), rb = rr; //lui RR, upper(fc)
        اگر (fc || (rr != rb) || do32bit || (fr & VT_SYM))
          EI(0x13 | do32bit, 0, rr, rb, SIGN11(fc)); // addi[w] R, x0|R, FC
        اگر (zext) {
            EI(0x13, 1, rr, rr, 32); // slli RR, RR, 32
            EI(0x13, 5, rr, rr, 32); // srli RR, RR, 32
        }
    } ورنہ اگر (v == VT_LOCAL) {
        صحیح br = بھرو_symofs(r, sv, 0, &fc);
        أكد(is_ireg(r));
        EI(0x13, 0, rr, br, fc); // addi R, s0, FC
    } ورنہ اگر (v < VT_CONST) { /* reg-reg */
        //assert(!fc); XXX support offseted regs
        اگر (is_freg(r) && is_freg(v))
          ER(0x53, 0, rr, freg(v), freg(v), bt == VT_DOUBLE ? 0x11 : 0x10); //fsgnj.[sd] RR, V, V == fmv.[sd] RR, V
        ورنہ اگر (is_ireg(r) && is_ireg(v))
          EI(0x13, 0, rr, ireg(v), 0); // addi RR, V, 0 == mv RR, V
        ورنہ {
            صحیح func7 = is_ireg(r) ? 0x70 : 0x78;
            سائز = type_سائز(&sv->type, &align);
            اگر (سائز == 8)
              func7 |= 1;
            أكد(سائز == 4 || سائز == 8);
            o(0x53 | (rr << 7) | ((is_freg(v) ? freg(v) : ireg(v)) << 15)
              | ((غیرعلامتی)func7 << 25)); // fmv.{w.x, x.w, d.x, x.d} RR, VR
        }
    } ورنہ اگر (v == VT_CMP) {
        صحیح op = vtop->cmp_op;
        صحیح a = vtop->cmp_r & 0xff;
        صحیح b = (vtop->cmp_r >> 8) & 0xff;
        صحیح inv = 0;
        انتخاب (op) {
            حالت TOK_ULT:
            حالت TOK_UGE:
            حالت TOK_ULE:
            حالت TOK_UGT:
            حالت TOK_LT:
            حالت TOK_GE:
            حالت TOK_LE:
            حالت TOK_GT:
                اگر (op & 1) { // remove [U]GE,GT
                    inv = 1;
                    op--;
                }
                اگر ((op & 7) == 6) { // [U]LE
                    صحیح t = a; a = b; b = t;
                    inv ^= 1;
                }
                ER(0x33, (op > TOK_UGT) ? 2 : 3, rr, a, b, 0); // slt[u] d, a, b
                اگر (inv)
                  EI(0x13, 4, rr, rr, 1); // xori d, d, 1
                توڑو;
            حالت TOK_NE:
            حالت TOK_EQ:
                اگر (rr != a || b)
                  ER(0x33, 0, rr, a, b, 0x20); // sub d, a, b
                اگر (op == TOK_NE)
                  ER(0x33, 3, rr, 0, rr, 0); // sltu d, x0, d == snez d,d
                ورنہ
                  EI(0x13, 3, rr, rr, 1); // sltiu d, d, 1 == seqz d,d
                توڑو;
        }
    } ورنہ اگر ((v & ~1) == VT_JMP) {
        صحیح t = v & 1;
        أكد(is_ireg(r));
        EI(0x13, 0, rr, 0, t);      // addi RR, x0, t
        gjmp_addr(ind + 8);
        gsym(fc);
        EI(0x13, 0, rr, 0, t ^ 1);  // addi RR, x0, !t
    } ورنہ
      tcc_error("unimp: load(non-const)");
}

ST_FUNC خالی store(صحیح r, SValue *sv)
{
    صحیح fr = sv->r & VT_VALMASK;
    صحیح rr = is_ireg(r) ? ireg(r) : freg(r), ptrreg;
    صحیح fc = sv->c.i;
    صحیح bt = sv->type.t & VT_BTYPE;
    صحیح align, سائز = type_سائز(&sv->type, &align);
    أكد(!is_float(bt) || is_freg(r) || bt == VT_LDOUBLE);
    /* long doubles are in two integer registers, but the load/store
       primitives only deal with one, so do as if it's one reg.  */
    اگر (bt == VT_LDOUBLE)
      سائز = align = 8;
    اگر (bt == VT_STRUCT)
      tcc_error("unimp: store(struct)");
    اگر (سائز > 8)
      tcc_error("unimp: large sized store");
    أكد(sv->r & VT_LVAL);
    اگر (fr == VT_LOCAL || (sv->r & VT_SYM)) {
        ptrreg = بھرو_symofs(-1, sv, 1, &fc);
    } ورنہ اگر (fr < VT_CONST) {
        ptrreg = ireg(fr);
        /*if (LOW_OVERFLOW(fc))
          tcc_error("unimp: store(large addend) (0x%x)", fc);*/
        fc = 0; // XXX support offsets regs
    } ورنہ اگر (fr == VT_CONST) {
        int64_t si = sv->c.i;
        ptrreg = 8; // s0
        si >>= 32;
        اگر (si != 0) {
	    بھرو_large_constant(ptrreg, fc, si);
            fc = SIGN7(fc);
        } ورنہ {
            o(0x37 | (ptrreg << 7) | بالائی_2(fc)); //lui RR, upper(fc)
            fc = SIGN11(fc);
	}
    } ورنہ
      tcc_error("implement me: %s(!local)", __FUNCTION__);
    ES(is_freg(r) ? 0x27 : 0x23,                          // fs... | s...
       سائز == 1 ? 0 : سائز == 2 ? 1 : سائز == 4 ? 2 : 3, // ... [wd] | [bhwd]
       ptrreg, rr, fc);                                   // RR, fc(base)
}

ساکن خالی gcall_or_jmp(صحیح docall)
{
    صحیح tr = docall ? 1 : 5; // ra or t0
    اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
        ((vtop->r & VT_SYM) && vtop->c.i == (صحیح)vtop->c.i)) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_متن_section, vtop->sym, ind,
                R_RISCV_CALL_PLT, (صحیح)vtop->c.i);
        o(0x17 | (tr << 7));   // auipc TR, 0 %call(func)
        EI(0x67, 0, tr, tr, 0);// jalr  TR, r(TR)
    } ورنہ اگر (vtop->r < VT_CONST) {
        صحیح r = ireg(vtop->r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    } ورنہ {
        صحیح r = TREG_RA;
        بھرو(r, vtop);
        r = ireg(r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    }
}

#اگر defined(CONFIG_TCC_BCHECK)

ساکن خالی gen_bounds_call(صحیح v)
{
    Sym *sym = external_helper_sym(v);

    greloca(cur_متن_section, sym, ind, R_RISCV_CALL_PLT, 0);
    o(0x17 | (1 << 7));   // auipc TR, 0 %call(func)
    EI(0x67, 0, 1, 1, 0); // jalr  TR, r(TR)
}

ساکن خالی gen_bounds_prolog(خالی)
{
    /* leave some room for bound checking code */
    func_bound_انحراف = lbounds_section->ڈیٹا_انحراف;
    func_bound_ind = ind;
    func_bound_جوڑو_epilog = 0;
    o(0x00000013);  /* ld a0,#lbound section pointer */
    o(0x00000013);
    o(0x00000013);  /* nop -> call __bound_local_new */
    o(0x00000013);
}

ساکن خالی gen_bounds_epilog(خالی)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ڈیٹا;
    Sym label = {0};

    صحیح انحراف_modified = func_bound_انحراف != lbounds_section->ڈیٹا_انحراف;

    اگر (!انحراف_modified && !func_bound_جوڑو_epilog)
        واپس;

    /* add end of table info */
    bounds_ptr = section_ptr_جوڑو(lbounds_section, حجم(addr_t));
    *bounds_ptr = 0;

    sym_ڈیٹا = get_sym_ref(&char_اشارہ_گر_type, lbounds_section,
                           func_bound_انحراف, PTR_سائز);

    label.type.t = VT_VOID | VT_STATIC;
    /* generate bound local allocation */
    اگر (انحراف_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        put_extern_sym(&label, cur_متن_section, ind, 0);
        greloca(cur_متن_section, sym_ڈیٹا, ind, R_RISCV_GOT_HI20, 0);
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
    greloca(cur_متن_section, sym_ڈیٹا, ind, R_RISCV_GOT_HI20, 0);
    o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
    greloca(cur_متن_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
    gen_bounds_call(TOK___bound_local_delete);
    o(0x65a26502); /* ld   a0,0(sp)   ld   a1,8(sp)   */
    o(0x61052542); /* fld  fa0,16(sp) addi sp,sp,32   */
}
#اگر_ختم

ساکن خالی reg_pass_rec(CType *type, صحیح *rc, صحیح *fieldofs, صحیح ofs)
{
    اگر ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *f;
        اگر (type->ref->type.t == VT_UNION)
          rc[0] = -1;
        ورنہ برائے (f = type->ref->اگلا; f; f = f->اگلا)
          reg_pass_rec(&f->type, rc, fieldofs, ofs + f->c);
    } ورنہ اگر (type->t & VT_ARRAY) {
        اگر (type->ref->c < 0 || type->ref->c > 2)
          rc[0] = -1;
        ورنہ {
            صحیح a, sz = type_سائز(&type->ref->type, &a);
            reg_pass_rec(&type->ref->type, rc, fieldofs, ofs);
            اگر (rc[0] > 2 || (rc[0] == 2 && type->ref->c > 1))
              rc[0] = -1;
            ورنہ اگر (type->ref->c == 2 && rc[0] && rc[1] == RC_FLOAT) {
              rc[++rc[0]] = RC_FLOAT;
              fieldofs[rc[0]] = ((ofs + sz) << 4)
                                | (type->ref->type.t & VT_BTYPE);
            } ورنہ اگر (type->ref->c == 2)
              rc[0] = -1;
        }
    } ورنہ اگر (rc[0] == 2 || rc[0] < 0 || (type->t & VT_BTYPE) == VT_LDOUBLE)
      rc[0] = -1;
    ورنہ اگر (!rc[0] || rc[1] == RC_FLOAT || is_float(type->t)) {
      rc[++rc[0]] = is_float(type->t) ? RC_FLOAT : RC_INT;
      fieldofs[rc[0]] = (ofs << 4) | ((type->t & VT_BTYPE) == VT_PTR ? VT_LLONG : type->t & VT_BTYPE);
    } ورنہ
      rc[0] = -1;
}

ساکن خالی reg_pass(CType *type, صحیح *prc, صحیح *fieldofs, صحیح named)
{
    prc[0] = 0;
    reg_pass_rec(type, prc, fieldofs, 0);
    اگر (prc[0] <= 0 || !named) {
        صحیح align, سائز = type_سائز(type, &align);
        prc[0] = (سائز + 7) >> 3;
        prc[1] = prc[2] = RC_INT;
        fieldofs[1] = (0 << 4) | (سائز <= 1 ? VT_BYTE : سائز <= 2 ? VT_SHORT : سائز <= 4 ? VT_INT : VT_LLONG);
        fieldofs[2] = (8 << 4) | (سائز <= 9 ? VT_BYTE : سائز <= 10 ? VT_SHORT : سائز <= 12 ? VT_INT : VT_LLONG);
    }
}

ST_FUNC خالی gfunc_call(صحیح nb_دلائل)
{
    صحیح i, align, سائز, areg[2];
    صحیح *info = tcc_malloc((nb_دلائل + 1) * حجم (صحیح));
    صحیح ڈھیر_adj = 0, tempspace = 0, ڈھیر_جوڑو, ofs, splitofs = 0;
    صحیح old = (vtop[-nb_دلائل].type.ref->f.func_type == FUNC_OLD);
    SValue *sv;
    Sym *sa;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    صحیح bc_save = tcc_state->do_bounds_check;
    اگر (tcc_state->do_bounds_check)
        gbound_دلائل(nb_دلائل);
#اگر_ختم

    areg[0] = 0; /* int arg regs */
    areg[1] = 8; /* float arg regs */
    sa = vtop[-nb_دلائل].type.ref->اگلا;
    برائے (i = 0; i < nb_دلائل; i++) {
        صحیح nregs, byref = 0, tempofs;
        صحیح prc[3], fieldofs[3];
        sv = &vtop[1 + i - nb_دلائل];
        sv->type.t &= ~VT_ARRAY; // XXX this should be done in tccgen.c
        سائز = type_سائز(&sv->type, &align);
        اگر (سائز > 16) {
            اگر (align < XLEN)
              align = XLEN;
            tempspace = (tempspace + align - 1) & -align;
            tempofs = tempspace;
            tempspace += سائز;
            سائز = align = 8;
            byref = 64 | (tempofs << 7);
        }
        reg_pass(&sv->type, prc, fieldofs, old || sa != 0);
        اگر (!old && !sa && align == 2*XLEN && سائز <= 2*XLEN)
          areg[0] = (areg[0] + 1) & ~1;
        nregs = prc[0];
        اگر (سائز == 0)
            info[i] = 0;
        ورنہ اگر ((prc[1] == RC_INT && areg[0] >= 8)
            || (prc[1] == RC_FLOAT && areg[1] >= 16)
            || (nregs == 2 && prc[1] == RC_FLOAT && prc[2] == RC_FLOAT
                && areg[1] >= 15)
            || (nregs == 2 && prc[1] != prc[2]
                && (areg[1] >= 16 || areg[0] >= 8))) {
            info[i] = 32;
            اگر (align < XLEN)
              align = XLEN;
            ڈھیر_adj += (سائز + align - 1) & -align;
            اگر (!old && !sa) /* one vararg on stack forces the rest on stack */
              areg[0] = 8, areg[1] = 16;
        } ورنہ {
            info[i] = areg[prc[1] - 1]++;
            اگر (!byref)
              info[i] |= (fieldofs[1] & VT_BTYPE) << 12;
            أكد(!(fieldofs[1] >> 4));
            اگر (nregs == 2) {
                اگر (prc[2] == RC_FLOAT || areg[0] < 8)
                  info[i] |= (1 + areg[prc[2] - 1]++) << 7;
                ورنہ {
                    info[i] |= 16;
                    ڈھیر_adj += 8;
                }
                اگر (!byref) {
                    أكد((fieldofs[2] >> 4) < 2048);
                    info[i] |= fieldofs[2] << (12 + 4); // includes offset
                }
            }
        }
        info[i] |= byref;
        اگر (sa)
          sa = sa->اگلا;
    }
    ڈھیر_adj = (ڈھیر_adj + 15) & -16;
    tempspace = (tempspace + 15) & -16;
    ڈھیر_جوڑو = ڈھیر_adj + tempspace;

    اگر (ڈھیر_جوڑو) {
        اگر (ڈھیر_جوڑو >= 0x800) {
            o(0x37 | (5 << 7) | بالائی_2(-ڈھیر_جوڑو)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(-ڈھیر_جوڑو)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        ورنہ
            EI(0x13, 0, 2, 2, -ڈھیر_جوڑو);   // addi sp, sp, -adj
        برائے (i = ofs = 0; i < nb_دلائل; i++) {
            اگر (info[i] & (64 | 32)) {
                vrotb(nb_دلائل - i);
                سائز = type_سائز(&vtop->type, &align);
                اگر (info[i] & 64) {
                    vset(&char_اشارہ_گر_type, TREG_SP, 0);
                    vpushi(ڈھیر_adj + (info[i] >> 7));
                    gen_op('+');
                    vpushv(vtop); // this replaces the old argument
                    vrott(3);
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vpop();
                    سائز = align = 8;
                }
                اگر (info[i] & 32) {
                    اگر (align < XLEN)
                      align = XLEN;
                    /* Once we support offseted regs we can do this:
                       vset(&vtop->type, TREG_SP | VT_LVAL, ofs);
                       to construct the lvalue for the outgoing stack slot,
                       until then we have to jump through hoops.  */
                    vset(&char_اشارہ_گر_type, TREG_SP, 0);
                    ofs = (ofs + align - 1) & -align;
                    vpushi(ofs);
                    gen_op('+');
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vtop->r = vtop->r2 = VT_CONST; // this arg is done
                    ofs += سائز;
                }
                vrott(nb_دلائل - i);
            } ورنہ اگر (info[i] & 16) {
                أكد(!splitofs);
                splitofs = ofs;
                ofs += 8;
            }
        }
    }
    برائے (i = 0; i < nb_دلائل; i++) {
        صحیح ii = info[nb_دلائل - 1 - i], r = ii, r2 = r;
        اگر (!(r & 32)) {
            CType origtype;
            صحیح loadt;
            r &= 15;
            r2 = r2 & 64 ? 0 : (r2 >> 7) & 31;
            أكد(r2 <= 16);
            vrotb(i+1);
            origtype = vtop->type;
            سائز = type_سائز(&vtop->type, &align);
            اگر (سائز == 0)
                جاؤ مکمل;
            loadt = vtop->type.t & VT_BTYPE;
            اگر (loadt == VT_STRUCT) {
                loadt = (ii >> 12) & VT_BTYPE;
            }
            اگر (info[nb_دلائل - 1 - i] & 16) {
                أكد(!r2);
                r2 = 1 + TREG_RA;
            }
            اگر (loadt == VT_LDOUBLE) {
                أكد(r2);
                r2--;
            } ورنہ اگر (r2) {
                test_lvalue();
                vpushv(vtop);
            }
            vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
            gv(r < 8 ? RC_R(r) : RC_F(r - 8));
            vtop->type = origtype;

            اگر (r2 && loadt != VT_LDOUBLE) {
                r2--;
                أكد(r2 < 16 || r2 == TREG_RA);
                vswap();
                gaddrof();
                vtop->type = char_اشارہ_گر_type;
                vpushi(ii >> 20);
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
		اگر ((origtype.t & VT_BTYPE) == VT_STRUCT)
                    tcc_state->do_bounds_check = 0;
#اگر_ختم
                gen_op('+');
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
		tcc_state->do_bounds_check = bc_save;
#اگر_ختم
                indir();
                vtop->type = origtype;
                loadt = vtop->type.t & VT_BTYPE;
                اگر (loadt == VT_STRUCT) {
                    loadt = (ii >> 16) & VT_BTYPE;
                }
                save_reg_upstack(r2, 1);
                vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
                بھرو(r2, vtop);
                أكد(r2 < VT_CONST);
                vtop--;
                vtop->r2 = r2;
            }
            اگر (info[nb_دلائل - 1 - i] & 16) {
                ES(0x23, 3, 2, ireg(vtop->r2), splitofs); // sd t0, ofs(sp)
                vtop->r2 = VT_CONST;
            } ورنہ اگر (loadt == VT_LDOUBLE && vtop->r2 != r2) {
                أكد(vtop->r2 <= 7 && r2 <= 7);
                /* XXX we'd like to have 'gv' move directly into
                   the right class instead of us fixing it up.  */
                EI(0x13, 0, ireg(r2), ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = r2;
            }
مکمل:
            vrott(i+1);
        }
    }
    vrotb(nb_دلائل + 1);
    save_regs(nb_دلائل + 1);
    gcall_or_jmp(1);
    vtop -= nb_دلائل + 1;
    اگر (ڈھیر_جوڑو) {
        اگر (ڈھیر_جوڑو >= 0x800) {
            o(0x37 | (5 << 7) | بالائی_2(ڈھیر_جوڑو)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(ڈھیر_جوڑو)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        ورنہ
            EI(0x13, 0, 2, 2, ڈھیر_جوڑو);      // addi sp, sp, adj
   }
   tcc_free(info);
}

ساکن صحیح func_sub_sp_انحراف, عدد_va_regs, func_va_list_ofs;

ST_FUNC خالی gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    صحیح i, addr, align, سائز;
    صحیح param_addr = 0;
    صحیح areg[2];
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    loc = -16; // for ra and s0
    func_sub_sp_انحراف = ind;
    ind += 5 * 4;

    areg[0] = 0, areg[1] = 0;
    addr = 0;
    /* if the function returns by reference, then add an
       implicit pointer parameter */
    سائز = type_سائز(&func_vt, &align);
    اگر (سائز > 2 * XLEN) {
        loc -= 8;
        func_vc = loc;
        ES(0x23, 3, 8, 10 + areg[0]++, loc); // sd a0, loc(s0)
    }
    /* define parameters */
    جب ((sym = sym->اگلا) != تہی) {
        صحیح byref = 0;
        صحیح regcount;
        صحیح prc[3], fieldofs[3];
        type = &sym->type;
        سائز = type_سائز(type, &align);
        اگر (سائز > 2 * XLEN) {
            type = &char_اشارہ_گر_type;
            سائز = align = byref = 8;
        }
        reg_pass(type, prc, fieldofs, 1);
        regcount = prc[0];
        اگر (areg[prc[1] - 1] >= 8
            || (regcount == 2
                && ((prc[1] == RC_FLOAT && prc[2] == RC_FLOAT && areg[1] >= 7)
                    || (prc[1] != prc[2] && (areg[1] >= 8 || areg[0] >= 8))))) {
            اگر (align < XLEN)
              align = XLEN;
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += سائز;
        } ورنہ {
            loc -= regcount * 8; // XXX could reserve only 'size' bytes
            param_addr = loc;
            برائے (i = 0; i < regcount; i++) {
                اگر (areg[prc[1+i] - 1] >= 8) {
                    أكد(i == 1 && regcount == 2 && !(addr & 7));
                    EI(0x03, 3, 5, 8, addr); // ld t0, addr(s0)
                    addr += 8;
                    ES(0x23, 3, 8, 5, loc + i*8); // sd t0, loc(s0)
                } ورنہ اگر (prc[1+i] == RC_FLOAT) {
                    ES(0x27, (سائز / regcount) == 4 ? 2 : 3, 8, 10 + areg[1]++, loc + (fieldofs[i+1] >> 4)); // fs[wd] FAi, loc(s0)
                } ورنہ {
                    ES(0x23, 3, 8, 10 + areg[0]++, loc + i*8); // sd aX, loc(s0) // XXX
                }
            }
        }
        gfunc_سیٹ_param(sym, param_addr, byref);
    }
    func_va_list_ofs = addr;
    عدد_va_regs = 0;
    اگر (func_var) {
        برائے (; areg[0] < 8; areg[0]++) {
            عدد_va_regs++;
            ES(0x23, 3, 8, 10 + areg[0], -8 + عدد_va_regs * 8); // sd aX, loc(s0)
        }
    }
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#اگر_ختم
}

ST_FUNC صحیح gfunc_sret(CType *vt, صحیح variadic, CType *ret,
                       صحیح *ret_align, صحیح *regsize)
{
    صحیح align, سائز = type_سائز(vt, &align), nregs;
    صحیح prc[3], fieldofs[3];
    *ret_align = 1;
    *regsize = 8;
    اگر (سائز > 16)
      واپس 0;
    reg_pass(vt, prc, fieldofs, 1);
    nregs = prc[0];
    اگر (nregs == 2 && prc[1] != prc[2])
      واپس -1;  /* generic code can't deal with this case */
    اگر (prc[1] == RC_FLOAT) {
        *regsize = سائز / nregs;
    }
    ret->t = fieldofs[1] & VT_BTYPE;
    ret->ref = تہی;
    واپس nregs;
}

ST_FUNC خالی arch_transfer_ret_regs(صحیح aftercall)
{
    صحیح prc[3], fieldofs[3];
    reg_pass(&vtop->type, prc, fieldofs, 1);
    أكد(prc[0] == 2 && prc[1] != prc[2] && !(fieldofs[1] >> 4));
    أكد(vtop->r == (VT_LOCAL | VT_LVAL));
    vpushv(vtop);
    vtop->type.t = fieldofs[1] & VT_BTYPE;
    (aftercall ? store : بھرو)(prc[1] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop->c.i += fieldofs[2] >> 4;
    vtop->type.t = fieldofs[2] & VT_BTYPE;
    (aftercall ? store : بھرو)(prc[2] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop--;
}

ST_FUNC خالی gfunc_epilog(خالی)
{
    صحیح v, saved_ind, d, large_ofs_ind;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#اگر_ختم

    loc = (loc - عدد_va_regs * 8);
    d = v = (-loc + 15) & -16;

    EI(0x13, 0, 2, 8, عدد_va_regs * 8); // addi sp, s0, num_va_regs*8
    EI(0x03, 3, 1, 8, -8); // ld ra, -8(s0)
    EI(0x03, 3, 8, 8, -16); // ld s0, -16(s0)
    EI(0x67, 0, 0, 1, 0); // jalr x0, 0(x1), aka ret

    large_ofs_ind = ind;
    اگر (v >= (1 << 11)) {
        d = 16;
        EI(0x13, 0, 8, 2, d - عدد_va_regs * 8);      // addi s0, sp, d
        o(0x37 | (5 << 7) | بالائی_2(v-16)); //lui t0, upper(v)
        EI(0x13, 0, 5, 5, SIGN11(v-16)); // addi t0, t0, lo(v)
        ER(0x33, 0, 2, 2, 5, 0x20); // sub sp, sp, t0
        gjmp_addr(func_sub_sp_انحراف + 5*4);
    }
    saved_ind = ind;

    ind = func_sub_sp_انحراف;
    EI(0x13, 0, 2, 2, -d);     // addi sp, sp, -d
    ES(0x23, 3, 2, 1, d - 8 - عدد_va_regs * 8);  // sd ra, d-8(sp)
    ES(0x23, 3, 2, 8, d - 16 - عدد_va_regs * 8); // sd s0, d-16(sp)
    اگر (v < (1 << 11))
      EI(0x13, 0, 8, 2, d - عدد_va_regs * 8);      // addi s0, sp, d
    ورنہ
      gjmp_addr(large_ofs_ind);
    اگر ((ind - func_sub_sp_انحراف) != 5*4)
      EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
    ind = saved_ind;
}

ST_FUNC خالی gen_va_آغاز(خالی)
{
    vtop--;
    vset(&char_اشارہ_گر_type, VT_LOCAL, func_va_list_ofs);
}

ST_FUNC خالی gen_fill_nops(صحیح بائٹیں)
{
    اگر ((بائٹیں & 3))
      tcc_error("alignment of code section not multiple of 4");
    جب (بائٹیں > 0) {
        EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
        بائٹیں -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC صحیح gjmp(صحیح t)
{
    اگر (nocode_wanted)
      واپس t;
    o(t);
    واپس ind - 4;
}

// Generate branch to known address:
ST_FUNC خالی gjmp_addr(صحیح a)
{
    uint32_t r = a - ind, imm;
    اگر ((r + (1 << 21)) & ~((1U << 22) - 2)) {
        o(0x17 | (5 << 7) | بالائی_2(r)); // lui RR, up(r)
        r = SIGN11(r);
        EI(0x67, 0, 0, 5, r);      // jalr x0, r(t0)
    } ورنہ {
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        o(0x6f | imm); // jal x0, imm ==  j imm
    }
}

ST_FUNC صحیح gjmp_cond(صحیح op, صحیح t)
{
    صحیح tmp;
    صحیح a = vtop->cmp_r & 0xff;
    صحیح b = (vtop->cmp_r >> 8) & 0xff;
    انتخاب (op) {
        حالت TOK_ULT: op = 6; توڑو;
        حالت TOK_UGE: op = 7; توڑو;
        حالت TOK_ULE: op = 7; tmp = a; a = b; b = tmp; توڑو;
        حالت TOK_UGT: op = 6; tmp = a; a = b; b = tmp; توڑو;
        حالت TOK_LT:  op = 4; توڑو;
        حالت TOK_GE:  op = 5; توڑو;
        حالت TOK_LE:  op = 5; tmp = a; a = b; b = tmp; توڑو;
        حالت TOK_GT:  op = 4; tmp = a; a = b; b = tmp; توڑو;
        حالت TOK_NE:  op = 1; توڑو;
        حالت TOK_EQ:  op = 0; توڑو;
    }
    o(0x63 | (op ^ 1) << 12 | a << 15 | b << 20 | 8 << 7); // bOP a,b,+4
    واپس gjmp(t);
}

ST_FUNC صحیح gjmp_append(صحیح n, صحیح t)
{
    خالی *p;
    /* insert jump list n into t */
    اگر (n) {
        uint32_t n1 = n, n2;
        جب ((n2 = read32le(p = cur_متن_section->ڈیٹا + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    واپس t;
}

ساکن خالی gen_opil(صحیح op, صحیح ll)
{
    صحیح a, b, d;
    صحیح func3 = 0;
    ll = ll ? 0 : 8;
    اگر ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
        صحیح fc = vtop->c.i;
        اگر (fc == vtop->c.i && !کم_حد_سے_تجاوز(fc)) {
            صحیح cll = 0;
            صحیح m = ll ? 31 : 63;
            vswap();
            gv(RC_INT);
            a = ireg(vtop[0].r);
            --vtop;
            d = get_reg(RC_INT);
            ++vtop;
            vswap();
            انتخاب (op) {
                حالت '-':
                    اگر (fc <= -(1 << 11))
                      توڑو;
                    fc = -fc;
                حالت '+':
                    func3 = 0; // addi d, a, fc
                    cll = ll;
                do_cop:
                    EI(0x13 | cll, func3, ireg(d), a, fc);
                    --vtop;
                    اگر (op >= TOK_ULT && op <= TOK_GT) {
                      vset_VT_CMP(TOK_NE);
                      vtop->cmp_r = ireg(d) | 0 << 8;
                    } ورنہ
                      vtop[0].r = d;
                    واپس;
                حالت TOK_LE:
                    اگر (fc >= (1 << 11) - 1)
                      توڑو;
                    ++fc;
                حالت TOK_LT:  func3 = 2; جاؤ do_cop; // slti d, a, fc
                حالت TOK_ULE:
                    اگر (fc >= (1 << 11) - 1 || fc == -1)
                      توڑو;
                    ++fc;
                حالت TOK_ULT: func3 = 3; جاؤ do_cop; // sltiu d, a, fc
                حالت '^':     func3 = 4; جاؤ do_cop; // xori d, a, fc
                حالت '|':     func3 = 6; جاؤ do_cop; // ori  d, a, fc
                حالت '&':     func3 = 7; جاؤ do_cop; // andi d, a, fc
                حالت TOK_SHL: func3 = 1; cll = ll; fc &= m; جاؤ do_cop; // slli d, a, fc
                حالت TOK_SHR: func3 = 5; cll = ll; fc &= m; جاؤ do_cop; // srli d, a, fc
                حالت TOK_SAR: func3 = 5; cll = ll; fc = 1024 | (fc & m); جاؤ do_cop;

                حالت TOK_UGE: /* -> TOK_ULT */
                حالت TOK_UGT: /* -> TOK_ULE */
                حالت TOK_GE:  /* -> TOK_LT */
                حالت TOK_GT:  /* -> TOK_LE */
                    gen_opil(op - 1, !ll);
                    vtop->cmp_op ^= 1;
                    واپس;

                حالت TOK_NE:
                حالت TOK_EQ:
                    اگر (fc)
                      gen_opil('-', !ll), a = ireg(vtop++->r);
                    --vtop;
                    vset_VT_CMP(op);
                    vtop->cmp_r = a | 0 << 8;
                    واپس;
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
    انتخاب (op) {
    طےشدہ:
        اگر (op >= TOK_ULT && op <= TOK_GT) {
            vset_VT_CMP(op);
            vtop->cmp_r = a | b << 8;
            توڑو;
        }
        tcc_error("implement me: %s(%s)", __FUNCTION__, get_tok_str(op, تہی));
        توڑو;

    حالت '+':
        ER(0x33 | ll, 0, d, a, b, 0); // add d, a, b
        توڑو;
    حالت '-':
        ER(0x33 | ll, 0, d, a, b, 0x20); // sub d, a, b
        توڑو;
    حالت TOK_SAR:
        ER(0x33 | ll | ll, 5, d, a, b, 0x20); // sra d, a, b
        توڑو;
    حالت TOK_SHR:
        ER(0x33 | ll | ll, 5, d, a, b, 0); // srl d, a, b
        توڑو;
    حالت TOK_SHL:
        ER(0x33 | ll, 1, d, a, b, 0); // sll d, a, b
        توڑو;
    حالت '*':
        ER(0x33 | ll, 0, d, a, b, 1); // mul d, a, b
        توڑو;
    حالت '/':
    حالت TOK_PDIV:
        ER(0x33 | ll, 4, d, a, b, 1); // div d, a, b
        توڑو;
    حالت '&':
        ER(0x33, 7, d, a, b, 0); // and d, a, b
        توڑو;
    حالت '^':
        ER(0x33, 4, d, a, b, 0); // xor d, a, b
        توڑو;
    حالت '|':
        ER(0x33, 6, d, a, b, 0); // or d, a, b
        توڑو;
    حالت '%':
        ER(ll ? 0x3b:  0x33, 6, d, a, b, 1); // rem d, a, b
        توڑو;
    حالت TOK_UMOD:
        ER(0x33 | ll, 7, d, a, b, 1); // remu d, a, b
        توڑو;
    حالت TOK_UDIV:
        ER(0x33 | ll, 5, d, a, b, 1); // divu d, a, b
        توڑو;
    }
}

ST_FUNC خالی gen_opi(صحیح op)
{
    gen_opil(op, 0);
}

ST_FUNC خالی gen_opl(صحیح op)
{
    gen_opil(op, 1);
}

ST_FUNC خالی gen_opf(صحیح op)
{
    صحیح rs1, rs2, rd, dbl, invert;
    اگر (vtop[0].type.t == VT_LDOUBLE) {
        CType type = vtop[0].type;
        صحیح func = 0;
        صحیح cond = -1;
        انتخاب (op) {
        حالت '*': func = TOK___multf3; توڑو;
        حالت '+': func = TOK___addtf3; توڑو;
        حالت '-': func = TOK___subtf3; توڑو;
        حالت '/': func = TOK___divtf3; توڑو;
        حالت TOK_EQ: func = TOK___eqtf2; cond = 1; توڑو;
        حالت TOK_NE: func = TOK___netf2; cond = 0; توڑو;
        حالت TOK_LT: func = TOK___lttf2; cond = 10; توڑو;
        حالت TOK_GE: func = TOK___getf2; cond = 11; توڑو;
        حالت TOK_LE: func = TOK___letf2; cond = 12; توڑو;
        حالت TOK_GT: func = TOK___gttf2; cond = 13; توڑو;
        طےشدہ: أكد(0); توڑو;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = REG_IRET;
        vtop->r2 = cond < 0 ? TREG_R(1) : VT_CONST;
        اگر (cond < 0)
            vtop->type = type;
        ورنہ {
            vpushi(0);
            gen_opil(op, 1);
        }
        واپس;
    }

    gv2(RC_FLOAT, RC_FLOAT);
    أكد(vtop->type.t == VT_DOUBLE || vtop->type.t == VT_FLOAT);
    dbl = vtop->type.t == VT_DOUBLE;
    rs1 = freg(vtop[-1].r);
    rs2 = freg(vtop->r);
    vtop--;
    invert = 0;
    انتخاب(op) {
    طےشدہ:
        أكد(0);
    حالت '+':
        op = 0; // fadd
    arithop:
        rd = get_reg(RC_FLOAT);
        vtop->r = rd;
        rd = freg(rd);
        ER(0x53, 7, rd, rs1, rs2, dbl | (op << 2)); // fop.[sd] RD, RS1, RS2 (dyn rm)
        توڑو;
    حالت '-':
        op = 1; // fsub
        جاؤ arithop;
    حالت '*':
        op = 2; // fmul
        جاؤ arithop;
    حالت '/':
        op = 3; // fdiv
        جاؤ arithop;
    حالت TOK_EQ:
        op = 2; // EQ
    cmpop:
        rd = get_reg(RC_INT);
        vtop->r = rd;
        rd = ireg(rd);
        ER(0x53, op, rd, rs1, rs2, dbl | 0x50); // fcmp.[sd] RD, RS1, RS2 (op == eq/lt/le)
        اگر (invert)
          EI(0x13, 4, rd, rd, 1); // xori RD, 1

        /* generate VT_CMP output */
        vset_VT_CMP(TOK_NE);
        vtop->cmp_r = rd | (0 << 8);
        توڑو;
    حالت TOK_NE:
        invert = 1;
        op = 2; // EQ
        جاؤ cmpop;
    حالت TOK_LT:
        op = 1; // LT
        جاؤ cmpop;
    حالت TOK_LE:
        op = 0; // LE
        جاؤ cmpop;
    حالت TOK_GT:
        op = 1; // LT
        rd = rs1, rs1 = rs2, rs2 = rd;
        جاؤ cmpop;
    حالت TOK_GE:
        op = 0; // LE
        rd = rs1, rs1 = rs2, rs2 = rd;
        جاؤ cmpop;
    }
}

ST_FUNC خالی gen_cvt_csti(صحیح t)
{
    صحیح r = ireg(gv(RC_INT));
    اگر ((t & VT_BTYPE) == VT_SHORT) {
        اگر (t & VT_UNSIGNED) {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EI(0x13, 5, r, r, 48); // srli r, r, 48
        } ورنہ {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EIu(0x13, 5, r, r, 0x400 | 48); // srai r, r, 48
        }
    } ورنہ {
        اگر (t & VT_UNSIGNED) {
            EI(0x13, 7, r, r, 0xff); // andi r, r, 0xff
        } ورنہ {
            EI(0x13, 1, r, r, 56); // slli r, r, 56
            EIu(0x13, 5, r, r, 0x400 | 56); // srai r, r, 56
        }
    }
}

ST_FUNC خالی gen_cvt_sxtw(خالی)
{
    صحیح r = ireg(gv(RC_INT));
    EI(0x1b, 0, r, r, 0); // addiw r, r, 0
}

ST_FUNC خالی gen_cvt_itof(صحیح t)
{
    صحیح rr = ireg(gv(RC_INT)), dr;
    صحیح u = vtop->type.t & VT_UNSIGNED;
    صحیح l = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    اگر (t == VT_LDOUBLE) {
        صحیح func = l ?
          (u ? TOK___floatunditf : TOK___floatditf) :
          (u ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        vtop->r2 = TREG_R(1);
    } ورنہ {
        vtop--;
        dr = get_reg(RC_FLOAT);
        vtop++;
        vtop->r = dr;
        dr = freg(dr);
        EIu(0x53, 7, dr, rr, ((0x68 | (t == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[sd].[wl][u]
    }
}

ST_FUNC خالی gen_cvt_ftoi(صحیح t)
{
    صحیح ft = vtop->type.t & VT_BTYPE;
    صحیح l = (t & VT_BTYPE) == VT_LLONG;
    صحیح u = t & VT_UNSIGNED;
    اگر (ft == VT_LDOUBLE) {
        صحیح func = l ?
          (u ? TOK___fixunstfdi : TOK___fixtfdi) :
          (u ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
    } ورنہ {
        صحیح rr = freg(gv(RC_FLOAT)), dr;
        vtop--;
        dr = get_reg(RC_INT);
        vtop++;
        vtop->r = dr;
        dr = ireg(dr);
        EIu(0x53, 1, dr, rr, ((0x60 | (ft == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[wl][u].[sd] rtz
    }
}

ST_FUNC خالی gen_cvt_ftof(صحیح dt)
{
    صحیح st = vtop->type.t & VT_BTYPE, rs, rd;
    dt &= VT_BTYPE;
    اگر (st == dt)
      واپس;
    اگر (dt == VT_LDOUBLE || st == VT_LDOUBLE) {
        صحیح func = (dt == VT_LDOUBLE) ?
            (st == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (dt == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        /* We can't use gfunc_call, as func_old_type works like vararg
           functions, and on riscv unnamed float args are passed like
           integers.  But we really need them in the float argument registers
           for extendsftf2/extenddftf2.  So, do it explicitely.  */
        save_regs(1);
        اگر (dt == VT_LDOUBLE)
          gv(RC_F(0));
        ورنہ {
            gv(RC_R(0));
            أكد(vtop->r2 < 7);
            اگر (vtop->r2 != 1 + vtop->r) {
                EI(0x13, 0, ireg(vtop->r) + 1, ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = 1 + vtop->r;
            }
        }
        vpush_helper_func(func);
        gcall_or_jmp(1);
        vtop -= 2;
        vpushi(0);
        vtop->type.t = dt;
        اگر (dt == VT_LDOUBLE)
          vtop->r = REG_IRET, vtop->r2 = REG_IRET+1;
        ورنہ
          vtop->r = REG_FRET;
    } ورنہ {
        أكد (dt == VT_FLOAT || dt == VT_DOUBLE);
        أكد (st == VT_FLOAT || st == VT_DOUBLE);
        rs = gv(RC_FLOAT);
        rd = get_reg(RC_FLOAT);
        اگر (dt == VT_DOUBLE)
          EI(0x53, 0, freg(rd), freg(rs), 0x21 << 5); // fcvt.d.s RD, RS (no rm)
        ورنہ
          EI(0x53, 7, freg(rd), freg(rs), (0x20 << 5) | 1); // fcvt.s.d RD, RS (dyn rm)
        vtop->r = rd;
    }
}

/* increment tcov counter */
ST_FUNC خالی gen_increment_tcov (SValue *sv)
{
    صحیح r1, r2;
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

ST_FUNC خالی ggoto(خالی)
{
    gcall_or_jmp(0);
    vtop--;
}

ST_FUNC خالی gen_vla_sp_save(صحیح addr)
{
    اگر (کم_حد_سے_تجاوز(addr)) {
	o(0x37 | (5 << 7) | بالائی_2(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        ES(0x23, 3, 5, 2, SIGN11(addr)); // sd sp, fc(t0)
    }
    ورنہ
        ES(0x23, 3, 8, 2, addr); // sd sp, fc(s0)
}

ST_FUNC خالی gen_vla_sp_restore(صحیح addr)
{
    اگر (کم_حد_سے_تجاوز(addr)) {
	o(0x37 | (5 << 7) | بالائی_2(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        EI(0x03, 3, 2, 5, SIGN11(addr)); // ld sp, fc(t0)
    }
    ورنہ
        EI(0x03, 3, 2, 8, addr); // ld sp, fc(s0)
}

ST_FUNC خالی gen_vla_alloc(CType *type, صحیح align)
{
    صحیح rr;
#اگر defined(CONFIG_TCC_BCHECK)
    اگر (tcc_state->do_bounds_check)
        vpushv(vtop);
#اگر_ختم
    rr = ireg(gv(RC_INT));
#اگر defined(CONFIG_TCC_BCHECK)
    اگر (tcc_state->do_bounds_check)
        EI(0x13, 0, rr, rr, 15+1);   // addi RR, RR, 15+1
    ورنہ
#اگر_ختم
    EI(0x13, 0, rr, rr, 15);   // addi RR, RR, 15
    EI(0x13, 7, rr, rr, -16);  // andi, RR, RR, -16
    ER(0x33, 0, 2, 2, rr, 0x20); // sub sp, sp, rr
    vpop();
#اگر defined(CONFIG_TCC_BCHECK)
    اگر (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x00010513); /* mv a0,sp */
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_جوڑو_epilog = 1;
    }
#اگر_ختم
}

ST_FUNC خالی gen_clear_cache(خالی)
{
    /* Zifencei extension: fence + fence.i for I/D synchronization.
       Required by RISC-V Linux ABI, present on all Linux-capable cores. */
    o(0x0ff0000f); // fence iorw, iorw
    o(0x0000100f); // fence.i
}
#اگر_ختم
