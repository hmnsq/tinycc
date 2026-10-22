#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

// Number of registers available to allocator:
#నిర్వచించు NB_REGS 19 // x10-x17 aka a0-a7, f10-f17 aka fa0-fa7, xxx, ra, sp
#నిర్వచించు CONFIG_TCC_ASM

#నిర్వచించు TREG_R(x) (x) // x = 0..7
#నిర్వచించు TREG_F(x) (x + 8) // x = 0..7

// Register classes sorted from more general to more precise:
#నిర్వచించు RC_INT (1 << 0)
#నిర్వచించు RC_FLOAT (1 << 1)
#నిర్వచించు RC_R(x) (1 << (2 + (x))) // x = 0..7
#నిర్వచించు RC_F(x) (1 << (10 + (x))) // x = 0..7

#నిర్వచించు RC_IRET (RC_R(0)) // int return register class
#నిర్వచించు RC_IRE2 (RC_R(1)) // int 2nd return register class
#నిర్వచించు RC_FRET (RC_F(0)) // float return register class

#నిర్వచించు REG_IRET (TREG_R(0)) // int return register number
#నిర్వచించు REG_IRE2 (TREG_R(1)) // int 2nd return register number
#నిర్వచించు REG_FRET (TREG_F(0)) // float return register number

#నిర్వచించు PTR_కొలత 8

#నిర్వచించు LDOUBLE_కొలత 16
#నిర్వచించు LDOUBLE_ALIGN 16

#నిర్వచించు MAX_ALIGN 16

#నిర్వచించు CHAR_IS_UNSIGNED

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#నిర్వచించు PROMOTE_RET

#లేకపోతే
#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"
#అన్తర్భావ <assert.h>

#నిర్వచించు పై_2(x)	(((గుర్తులేని)(x) + 0x800u) & 0xfffff000)
#నిర్వచించు దిగువ_అధికప్రవాహం(x)	పై_2(x)
#నిర్వచించు SIGN7(x)	((((x) & 0xff) ^ 0x80) - 0x80)
#నిర్వచించు SIGN11(x)	((((x) & 0xfff) ^ 0x800) - 0x800)

ST_దత్తాంశం స్థిరరాశి అక్షరం * స్థిరరాశి లక్ష్యం_machine_defs =
    "__riscv\0"
    "__riscv_xlen 64\0"
    "__riscv_flen 64\0"
    "__riscv_div\0"
    "__riscv_mul\0"
    "__riscv_fdiv\0"
    "__riscv_fsqrt\0"
    "__riscv_float_abi_double\0"
    ;

#నిర్వచించు XLEN 8

#నిర్వచించు TREG_RA 17
#నిర్వచించు TREG_SP 18

ST_దత్తాంశం స్థిరరాశి పూర్ణాంకం reg_classes[NB_REGS] = {
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

#ఒకవేళ defined(CONFIG_TCC_BCHECK)
స్థిర addr_t func_bound_స్థానభ్రంశం;
స్థిర గుర్తులేని దీర్ఘ func_bound_ind;
ST_దత్తాంశం పూర్ణాంకం func_bound_కూడు_epilog;
#అయితే_ముగింపు

స్థిర పూర్ణాంకం ireg(పూర్ణాంకం r)
{
    ఒకవేళ (r == TREG_RA)
      తిరిగి 1; // ra
    ఒకవేళ (r == TREG_SP)
      తిరిగి 2; // sp
    ప్రతిజ్ఞా(r >= 0 && r < 8);
    తిరిగి r + 10;  // tccrX --> aX == x(10+X)
}

స్థిర పూర్ణాంకం is_ireg(పూర్ణాంకం r)
{
    తిరిగి (గుర్తులేని)r < 8 || r == TREG_RA || r == TREG_SP;
}

స్థిర పూర్ణాంకం freg(పూర్ణాంకం r)
{
    ప్రతిజ్ఞా(r >= 8 && r < 16);
    తిరిగి r - 8 + 10;  // tccfX --> faX == f(10+X)
}

స్థిర పూర్ణాంకం is_freg(పూర్ణాంకం r)
{
    తిరిగి r >= 8 && r < 16;
}

ST_FUNC శూన్య o(గుర్తులేని పూర్ణాంకం c)
{
    పూర్ణాంకం ind1 = ind + 4;
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    ఒకవేళ (ind1 > cur_పాఠ్యం_section->దత్తాంశం_allocated)
        section_realloc(cur_పాఠ్యం_section, ind1);
    write32le(cur_పాఠ్యం_section->దత్తాంశం + ind, c);
    ind = ind1;
}

స్థిర శూన్య EIu(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    o(opcode | (func3 << 12) | (rd << 7) | (rs1 << 15) | (imm << 20));
}

స్థిర శూన్య ER(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t func7)
{
    o(opcode | func3 << 12 | rd << 7 | rs1 << 15 | rs2 << 20 | func7 << 25);
}

స్థిర శూన్య EI(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    ప్రతిజ్ఞా(! దిగువ_అధికప్రవాహం(imm));
    EIu(opcode, func3, rd, rs1, imm);
}

స్థిర శూన్య ES(uint32_t opcode, uint32_t func3,
               uint32_t rs1, uint32_t rs2, uint32_t imm)
{
    ప్రతిజ్ఞా(! దిగువ_అధికప్రవాహం(imm));
    o(opcode | (func3 << 12) | ((imm & 0x1f) << 7) | (rs1 << 15)
      | (rs2 << 20) | ((imm >> 5) << 25));
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC శూన్య gsym_addr(పూర్ణాంకం t_, పూర్ణాంకం a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    అయితే (t) {
        గుర్తులేని అక్షరం *ptr = cur_పాఠ్యం_section->దత్తాంశం + t;
        uint32_t తదుపరి = read32le(ptr);
        uint32_t r = a - t, imm;
        ఒకవేళ ((r + (1 << 21)) & ~((1U << 22) - 2))
          tcc_error("out-of-range branch chain");
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        write32le(ptr, r == 4 ? 0x33 : 0x6f | imm); // nop || j imm
        t = తదుపరి;
    }
}

స్థిర పూర్ణాంకం ఎక్కించు_symofs(పూర్ణాంకం r, SValue *sv, పూర్ణాంకం forstore, పూర్ణాంకం *new_fc)
{
    పూర్ణాంకం rr, doload = 0, large_addend = 0;
    పూర్ణాంకం fc = sv->c.i, v = sv->r & VT_VALMASK;
    ఒకవేళ (sv->r & VT_SYM) {
        Sym label = {0};
        ప్రతిజ్ఞా(v == VT_CONST);
        ఒకవేళ (sv->sym->type.t & VT_TLS) {
            /* TLS Local Exec model: lui + addi + add tp */
            rr = is_ireg(r) ? ireg(r) : 5;
            greloca(cur_పాఠ్యం_section, sv->sym, ind,
                    R_RISCV_TPREL_HI20, sv->c.i);
            o(0x37 | (rr << 7));  // lui RR, 0 %tprel_hi(sym)
            greloca(cur_పాఠ్యం_section, sv->sym, ind,
                    R_RISCV_TPREL_LO12_I, sv->c.i);
            EI(0x13, 0, rr, rr, 0); // addi RR, RR, 0 %tprel_lo(sym)
            ER(0x33, 0, rr, rr, 4, 0); // add RR, RR, tp
            *new_fc = 0;
            తిరిగి rr;
        }
        ఒకవేళ (sv->sym->type.t & VT_STATIC) { // XXX do this per linker relax
            greloca(cur_పాఠ్యం_section, sv->sym, ind,
                    R_RISCV_PCREL_HI20, sv->c.i);
            *new_fc = 0;
        } లేకపోతే {
            ఒకవేళ (దిగువ_అధికప్రవాహం(fc)){
              large_addend = 1;
            }
            greloca(cur_పాఠ్యం_section, sv->sym, ind,
                    R_RISCV_GOT_HI20, 0);
            doload = 1;
        }
        label.type.t = VT_VOID | VT_STATIC;
	ఒకవేళ (!nocode_wanted)
            put_extern_sym(&label, cur_పాఠ్యం_section, ind, 0);
        rr = is_ireg(r) ? ireg(r) : 5;
        o(0x17 | (rr << 7));   // auipc RR, 0 %pcrel_hi(sym)+addend
        greloca(cur_పాఠ్యం_section, &label, ind,
                doload || !forstore
                  ? R_RISCV_PCREL_LO12_I : R_RISCV_PCREL_LO12_S, 0);
        ఒకవేళ (doload) {
            EI(0x03, 3, rr, rr, 0); // ld RR, 0(RR)
            ఒకవేళ (large_addend) {
                o(0x37 | (6 << 7) | పై_2(fc)); //lui t1, high(fc)
                ER(0x33, 0, rr, rr, 6, 0); // add RR, RR, t1
                *new_fc = SIGN11(fc);
            }
        }
    } లేకపోతే ఒకవేళ (v == VT_LOCAL || v == VT_LLOCAL) {
        rr = 8; // s0
        ఒకవేళ (fc != sv->c.i)
          tcc_error("unimp: store(giant local off) (0x%lx)", (దీర్ఘ)sv->c.i);
        ఒకవేళ (దిగువ_అధికప్రవాహం(fc)) {
            rr = is_ireg(r) ? ireg(r) : 5; // t0
            o(0x37 | (rr << 7) | పై_2(fc)); //lui RR, upper(fc)
            ER(0x33, 0, rr, rr, 8, 0); // add RR, RR, s0
            *new_fc = SIGN11(fc);
        }
    } లేకపోతే
      tcc_error("uhh");
    తిరిగి rr;
}

స్థిర శూన్య ఎక్కించు_large_constant(పూర్ణాంకం rr, పూర్ణాంకం fc, uint32_t pi)
{
    ఒకవేళ (fc < 0)
	pi++;
    o(0x37 | (rr << 7) | పై_2(pi)); // lui RR, up(up(fc))
    EI(0x13, 0, rr, rr, SIGN11(pi));   // addi RR, RR, lo(up(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((గుర్తులేని)fc + (1 << 19)) >> 20)); // addi RR, RR, up(lo(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((గుర్తులేని)fc + (1 << 7)) >> 8));  // addi RR, RR, lo1(lo(fc))
    EI(0x13, 1, rr, rr, 8); // slli RR, RR, 8
}

ST_FUNC శూన్య ఎక్కించు(పూర్ణాంకం r, SValue *sv)
{
    పూర్ణాంకం fr = sv->r;
    పూర్ణాంకం v = fr & VT_VALMASK;
    పూర్ణాంకం rr = is_ireg(r) ? ireg(r) : freg(r);
    పూర్ణాంకం fc = sv->c.i;
    పూర్ణాంకం bt = sv->type.t & VT_BTYPE;
    పూర్ణాంకం align, కొలత;
    ఒకవేళ (fr & VT_LVAL) {
        పూర్ణాంకం func3, opcode = is_freg(r) ? 0x07 : 0x03, br;
        కొలత = type_కొలత(&sv->type, &align);
        ప్రతిజ్ఞా (!is_freg(r) || bt == VT_FLOAT || bt == VT_DOUBLE);
        ఒకవేళ (bt == VT_PTR || bt == VT_FUNC) /* XXX should be done in generic code */
          కొలత = PTR_కొలత;
        func3 = కొలత == 1 ? 0 : కొలత == 2 ? 1 : కొలత == 4 ? 2 : 3;
        ఒకవేళ (కొలత < 4 && !is_float(sv->type.t) && (sv->type.t & VT_UNSIGNED))
          func3 |= 4;
        ఒకవేళ (v == VT_LOCAL || (fr & VT_SYM)) {
            br = ఎక్కించు_symofs(r, sv, 0, &fc);
        } లేకపోతే ఒకవేళ (v < VT_CONST) {
            br = ireg(v);
            /*if (LOW_OVERFLOW(fc))
              tcc_error("unimp: load(large addend) (0x%x)", fc);*/
            fc = 0; // XXX store ofs in LVAL(reg)
        } లేకపోతే ఒకవేళ (v == VT_LLOCAL) {
            br = ఎక్కించు_symofs(r, sv, 0, &fc);
            EI(0x03, 3, rr, br, fc); // ld RR, fc(BR)
            br = rr;
            fc = 0;
        } లేకపోతే ఒకవేళ (v == VT_CONST) {
            int64_t si = sv->c.i;
            si >>= 32;
            ఒకవేళ (si != 0) {
		ఎక్కించు_large_constant(rr, fc, si);
                fc = SIGN7(fc);
            } లేకపోతే {
                o(0x37 | (rr << 7) | పై_2(fc)); //lui RR, upper(fc)
                fc = SIGN11(fc);
	    }
            br = rr;
	} లేకపోతే {
            tcc_error("unimp: load(non-local lval)");
        }
        EI(opcode, func3, rr, br, fc); // l[bhwd][u] / fl[wd] RR, fc(BR)
    } లేకపోతే ఒకవేళ (v == VT_CONST) {
        పూర్ణాంకం rb = 0, do32bit = 8, zext = 0;
        ఒకవేళ (is_float(sv->type.t) && bt != VT_LDOUBLE) {
            /* load float/double constant: move bit pattern from int reg */
            uint64_t val = sv->c.i;
            పూర్ణాంకం is_dbl = bt == VT_DOUBLE;
            ఒకవేళ (val == 0) {
                o(0x53 | (rr << 7) | ((గుర్తులేని)(0x78 | is_dbl) << 25));
                తిరిగి;
            }
            ఒకవేళ (is_dbl) {
                ఎక్కించు_large_constant(6, (పూర్ణాంకం)val, (పూర్ణాంకం)(val >> 32));
            } లేకపోతే {
                ఒకవేళ (దిగువ_అధికప్రవాహం(fc))
                    o(0x37 | (6 << 7) | పై_2(fc)); // lui t1, upper
                EI(0x13 | 8, 0, 6, దిగువ_అధికప్రవాహం(fc) ? 6 : 0, SIGN11(fc)); // addiw t1,...
            }
            o(0x53 | (rr << 7) | (6 << 15) | ((గుర్తులేని)(0x78 | is_dbl) << 25));
            తిరిగి;
        }
        ప్రతిజ్ఞా(is_ireg(r) || bt == VT_LDOUBLE);
        ఒకవేళ (fr & VT_SYM) {
            rb = ఎక్కించు_symofs(r, sv, 0, &fc);
            do32bit = 0;
        }
        ఒకవేళ (do32bit && fc != sv->c.i) {
            int64_t si = sv->c.i;
            si >>= 32;
            ఒకవేళ (si != 0) {
		ఎక్కించు_large_constant(rr, fc, si);
                fc = SIGN7(fc);
                rb = rr;
                do32bit = 0;
            } లేకపోతే ఒకవేళ (bt == VT_LLONG) {
                /* A 32bit unsigned constant for a 64bit type.
                   lui always sign extends, so we need to do an explicit zext.*/
                zext = 1;
            }
        }
        ఒకవేళ (దిగువ_అధికప్రవాహం(fc))
            o(0x37 | (rr << 7) | పై_2(fc)), rb = rr; //lui RR, upper(fc)
        ఒకవేళ (fc || (rr != rb) || do32bit || (fr & VT_SYM))
          EI(0x13 | do32bit, 0, rr, rb, SIGN11(fc)); // addi[w] R, x0|R, FC
        ఒకవేళ (zext) {
            EI(0x13, 1, rr, rr, 32); // slli RR, RR, 32
            EI(0x13, 5, rr, rr, 32); // srli RR, RR, 32
        }
    } లేకపోతే ఒకవేళ (v == VT_LOCAL) {
        పూర్ణాంకం br = ఎక్కించు_symofs(r, sv, 0, &fc);
        ప్రతిజ్ఞా(is_ireg(r));
        EI(0x13, 0, rr, br, fc); // addi R, s0, FC
    } లేకపోతే ఒకవేళ (v < VT_CONST) { /* reg-reg */
        //assert(!fc); XXX support offseted regs
        ఒకవేళ (is_freg(r) && is_freg(v))
          ER(0x53, 0, rr, freg(v), freg(v), bt == VT_DOUBLE ? 0x11 : 0x10); //fsgnj.[sd] RR, V, V == fmv.[sd] RR, V
        లేకపోతే ఒకవేళ (is_ireg(r) && is_ireg(v))
          EI(0x13, 0, rr, ireg(v), 0); // addi RR, V, 0 == mv RR, V
        లేకపోతే {
            పూర్ణాంకం func7 = is_ireg(r) ? 0x70 : 0x78;
            కొలత = type_కొలత(&sv->type, &align);
            ఒకవేళ (కొలత == 8)
              func7 |= 1;
            ప్రతిజ్ఞా(కొలత == 4 || కొలత == 8);
            o(0x53 | (rr << 7) | ((is_freg(v) ? freg(v) : ireg(v)) << 15)
              | ((గుర్తులేని)func7 << 25)); // fmv.{w.x, x.w, d.x, x.d} RR, VR
        }
    } లేకపోతే ఒకవేళ (v == VT_CMP) {
        పూర్ణాంకం op = vtop->cmp_op;
        పూర్ణాంకం a = vtop->cmp_r & 0xff;
        పూర్ణాంకం b = (vtop->cmp_r >> 8) & 0xff;
        పూర్ణాంకం inv = 0;
        ఎంపిక (op) {
            స్థితి TOK_ULT:
            స్థితి TOK_UGE:
            స్థితి TOK_ULE:
            స్థితి TOK_UGT:
            స్థితి TOK_LT:
            స్థితి TOK_GE:
            స్థితి TOK_LE:
            స్థితి TOK_GT:
                ఒకవేళ (op & 1) { // remove [U]GE,GT
                    inv = 1;
                    op--;
                }
                ఒకవేళ ((op & 7) == 6) { // [U]LE
                    పూర్ణాంకం t = a; a = b; b = t;
                    inv ^= 1;
                }
                ER(0x33, (op > TOK_UGT) ? 2 : 3, rr, a, b, 0); // slt[u] d, a, b
                ఒకవేళ (inv)
                  EI(0x13, 4, rr, rr, 1); // xori d, d, 1
                ఆపు;
            స్థితి TOK_NE:
            స్థితి TOK_EQ:
                ఒకవేళ (rr != a || b)
                  ER(0x33, 0, rr, a, b, 0x20); // sub d, a, b
                ఒకవేళ (op == TOK_NE)
                  ER(0x33, 3, rr, 0, rr, 0); // sltu d, x0, d == snez d,d
                లేకపోతే
                  EI(0x13, 3, rr, rr, 1); // sltiu d, d, 1 == seqz d,d
                ఆపు;
        }
    } లేకపోతే ఒకవేళ ((v & ~1) == VT_JMP) {
        పూర్ణాంకం t = v & 1;
        ప్రతిజ్ఞా(is_ireg(r));
        EI(0x13, 0, rr, 0, t);      // addi RR, x0, t
        gjmp_addr(ind + 8);
        gsym(fc);
        EI(0x13, 0, rr, 0, t ^ 1);  // addi RR, x0, !t
    } లేకపోతే
      tcc_error("unimp: load(non-const)");
}

ST_FUNC శూన్య store(పూర్ణాంకం r, SValue *sv)
{
    పూర్ణాంకం fr = sv->r & VT_VALMASK;
    పూర్ణాంకం rr = is_ireg(r) ? ireg(r) : freg(r), ptrreg;
    పూర్ణాంకం fc = sv->c.i;
    పూర్ణాంకం bt = sv->type.t & VT_BTYPE;
    పూర్ణాంకం align, కొలత = type_కొలత(&sv->type, &align);
    ప్రతిజ్ఞా(!is_float(bt) || is_freg(r) || bt == VT_LDOUBLE);
    /* long doubles are in two integer registers, but the load/store
       primitives only deal with one, so do as if it's one reg.  */
    ఒకవేళ (bt == VT_LDOUBLE)
      కొలత = align = 8;
    ఒకవేళ (bt == VT_STRUCT)
      tcc_error("unimp: store(struct)");
    ఒకవేళ (కొలత > 8)
      tcc_error("unimp: large sized store");
    ప్రతిజ్ఞా(sv->r & VT_LVAL);
    ఒకవేళ (fr == VT_LOCAL || (sv->r & VT_SYM)) {
        ptrreg = ఎక్కించు_symofs(-1, sv, 1, &fc);
    } లేకపోతే ఒకవేళ (fr < VT_CONST) {
        ptrreg = ireg(fr);
        /*if (LOW_OVERFLOW(fc))
          tcc_error("unimp: store(large addend) (0x%x)", fc);*/
        fc = 0; // XXX support offsets regs
    } లేకపోతే ఒకవేళ (fr == VT_CONST) {
        int64_t si = sv->c.i;
        ptrreg = 8; // s0
        si >>= 32;
        ఒకవేళ (si != 0) {
	    ఎక్కించు_large_constant(ptrreg, fc, si);
            fc = SIGN7(fc);
        } లేకపోతే {
            o(0x37 | (ptrreg << 7) | పై_2(fc)); //lui RR, upper(fc)
            fc = SIGN11(fc);
	}
    } లేకపోతే
      tcc_error("implement me: %s(!local)", __FUNCTION__);
    ES(is_freg(r) ? 0x27 : 0x23,                          // fs... | s...
       కొలత == 1 ? 0 : కొలత == 2 ? 1 : కొలత == 4 ? 2 : 3, // ... [wd] | [bhwd]
       ptrreg, rr, fc);                                   // RR, fc(base)
}

స్థిర శూన్య gcall_or_jmp(పూర్ణాంకం docall)
{
    పూర్ణాంకం tr = docall ? 1 : 5; // ra or t0
    ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
        ((vtop->r & VT_SYM) && vtop->c.i == (పూర్ణాంకం)vtop->c.i)) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_పాఠ్యం_section, vtop->sym, ind,
                R_RISCV_CALL_PLT, (పూర్ణాంకం)vtop->c.i);
        o(0x17 | (tr << 7));   // auipc TR, 0 %call(func)
        EI(0x67, 0, tr, tr, 0);// jalr  TR, r(TR)
    } లేకపోతే ఒకవేళ (vtop->r < VT_CONST) {
        పూర్ణాంకం r = ireg(vtop->r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    } లేకపోతే {
        పూర్ణాంకం r = TREG_RA;
        ఎక్కించు(r, vtop);
        r = ireg(r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    }
}

#ఒకవేళ defined(CONFIG_TCC_BCHECK)

స్థిర శూన్య gen_bounds_call(పూర్ణాంకం v)
{
    Sym *sym = external_helper_sym(v);

    greloca(cur_పాఠ్యం_section, sym, ind, R_RISCV_CALL_PLT, 0);
    o(0x17 | (1 << 7));   // auipc TR, 0 %call(func)
    EI(0x67, 0, 1, 1, 0); // jalr  TR, r(TR)
}

స్థిర శూన్య gen_bounds_prolog(శూన్య)
{
    /* leave some room for bound checking code */
    func_bound_స్థానభ్రంశం = lbounds_section->దత్తాంశం_స్థానభ్రంశం;
    func_bound_ind = ind;
    func_bound_కూడు_epilog = 0;
    o(0x00000013);  /* ld a0,#lbound section pointer */
    o(0x00000013);
    o(0x00000013);  /* nop -> call __bound_local_new */
    o(0x00000013);
}

స్థిర శూన్య gen_bounds_epilog(శూన్య)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_దత్తాంశం;
    Sym label = {0};

    పూర్ణాంకం స్థానభ్రంశం_modified = func_bound_స్థానభ్రంశం != lbounds_section->దత్తాంశం_స్థానభ్రంశం;

    ఒకవేళ (!స్థానభ్రంశం_modified && !func_bound_కూడు_epilog)
        తిరిగి;

    /* add end of table info */
    bounds_ptr = section_ptr_కూడు(lbounds_section, పరిమాణం(addr_t));
    *bounds_ptr = 0;

    sym_దత్తాంశం = get_sym_ref(&char_సూచిక_type, lbounds_section,
                           func_bound_స్థానభ్రంశం, PTR_కొలత);

    label.type.t = VT_VOID | VT_STATIC;
    /* generate bound local allocation */
    ఒకవేళ (స్థానభ్రంశం_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        put_extern_sym(&label, cur_పాఠ్యం_section, ind, 0);
        greloca(cur_పాఠ్యం_section, sym_దత్తాంశం, ind, R_RISCV_GOT_HI20, 0);
        o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
        greloca(cur_పాఠ్యం_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
        EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
        gen_bounds_call(TOK___bound_local_new);
        ind = saved_ind;
        label.c = 0; /* force new local ELF symbol */
    }

    /* generate bound check local freeing */
    o(0xe02a1101); /* addi sp,sp,-32  sd   a0,0(sp)   */
    o(0xa82ae42e); /* sd   a1,8(sp)   fsd  fa0,16(sp) */
    put_extern_sym(&label, cur_పాఠ్యం_section, ind, 0);
    greloca(cur_పాఠ్యం_section, sym_దత్తాంశం, ind, R_RISCV_GOT_HI20, 0);
    o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
    greloca(cur_పాఠ్యం_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
    gen_bounds_call(TOK___bound_local_delete);
    o(0x65a26502); /* ld   a0,0(sp)   ld   a1,8(sp)   */
    o(0x61052542); /* fld  fa0,16(sp) addi sp,sp,32   */
}
#అయితే_ముగింపు

స్థిర శూన్య reg_pass_rec(CType *type, పూర్ణాంకం *rc, పూర్ణాంకం *fieldofs, పూర్ణాంకం ofs)
{
    ఒకవేళ ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *f;
        ఒకవేళ (type->ref->type.t == VT_UNION)
          rc[0] = -1;
        లేకపోతే కొరకు (f = type->ref->తదుపరి; f; f = f->తదుపరి)
          reg_pass_rec(&f->type, rc, fieldofs, ofs + f->c);
    } లేకపోతే ఒకవేళ (type->t & VT_ARRAY) {
        ఒకవేళ (type->ref->c < 0 || type->ref->c > 2)
          rc[0] = -1;
        లేకపోతే {
            పూర్ణాంకం a, sz = type_కొలత(&type->ref->type, &a);
            reg_pass_rec(&type->ref->type, rc, fieldofs, ofs);
            ఒకవేళ (rc[0] > 2 || (rc[0] == 2 && type->ref->c > 1))
              rc[0] = -1;
            లేకపోతే ఒకవేళ (type->ref->c == 2 && rc[0] && rc[1] == RC_FLOAT) {
              rc[++rc[0]] = RC_FLOAT;
              fieldofs[rc[0]] = ((ofs + sz) << 4)
                                | (type->ref->type.t & VT_BTYPE);
            } లేకపోతే ఒకవేళ (type->ref->c == 2)
              rc[0] = -1;
        }
    } లేకపోతే ఒకవేళ (rc[0] == 2 || rc[0] < 0 || (type->t & VT_BTYPE) == VT_LDOUBLE)
      rc[0] = -1;
    లేకపోతే ఒకవేళ (!rc[0] || rc[1] == RC_FLOAT || is_float(type->t)) {
      rc[++rc[0]] = is_float(type->t) ? RC_FLOAT : RC_INT;
      fieldofs[rc[0]] = (ofs << 4) | ((type->t & VT_BTYPE) == VT_PTR ? VT_LLONG : type->t & VT_BTYPE);
    } లేకపోతే
      rc[0] = -1;
}

స్థిర శూన్య reg_pass(CType *type, పూర్ణాంకం *prc, పూర్ణాంకం *fieldofs, పూర్ణాంకం named)
{
    prc[0] = 0;
    reg_pass_rec(type, prc, fieldofs, 0);
    ఒకవేళ (prc[0] <= 0 || !named) {
        పూర్ణాంకం align, కొలత = type_కొలత(type, &align);
        prc[0] = (కొలత + 7) >> 3;
        prc[1] = prc[2] = RC_INT;
        fieldofs[1] = (0 << 4) | (కొలత <= 1 ? VT_BYTE : కొలత <= 2 ? VT_SHORT : కొలత <= 4 ? VT_INT : VT_LLONG);
        fieldofs[2] = (8 << 4) | (కొలత <= 9 ? VT_BYTE : కొలత <= 10 ? VT_SHORT : కొలత <= 12 ? VT_INT : VT_LLONG);
    }
}

ST_FUNC శూన్య gfunc_call(పూర్ణాంకం nb_వాదనలు)
{
    పూర్ణాంకం i, align, కొలత, areg[2];
    పూర్ణాంకం *info = tcc_malloc((nb_వాదనలు + 1) * పరిమాణం (పూర్ణాంకం));
    పూర్ణాంకం దొంతర_adj = 0, tempspace = 0, దొంతర_కూడు, ofs, splitofs = 0;
    పూర్ణాంకం old = (vtop[-nb_వాదనలు].type.ref->f.func_type == FUNC_OLD);
    SValue *sv;
    Sym *sa;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    పూర్ణాంకం bc_save = tcc_state->do_bounds_check;
    ఒకవేళ (tcc_state->do_bounds_check)
        gbound_వాదనలు(nb_వాదనలు);
#అయితే_ముగింపు

    areg[0] = 0; /* int arg regs */
    areg[1] = 8; /* float arg regs */
    sa = vtop[-nb_వాదనలు].type.ref->తదుపరి;
    కొరకు (i = 0; i < nb_వాదనలు; i++) {
        పూర్ణాంకం nregs, byref = 0, tempofs;
        పూర్ణాంకం prc[3], fieldofs[3];
        sv = &vtop[1 + i - nb_వాదనలు];
        sv->type.t &= ~VT_ARRAY; // XXX this should be done in tccgen.c
        కొలత = type_కొలత(&sv->type, &align);
        ఒకవేళ (కొలత > 16) {
            ఒకవేళ (align < XLEN)
              align = XLEN;
            tempspace = (tempspace + align - 1) & -align;
            tempofs = tempspace;
            tempspace += కొలత;
            కొలత = align = 8;
            byref = 64 | (tempofs << 7);
        }
        reg_pass(&sv->type, prc, fieldofs, old || sa != 0);
        ఒకవేళ (!old && !sa && align == 2*XLEN && కొలత <= 2*XLEN)
          areg[0] = (areg[0] + 1) & ~1;
        nregs = prc[0];
        ఒకవేళ (కొలత == 0)
            info[i] = 0;
        లేకపోతే ఒకవేళ ((prc[1] == RC_INT && areg[0] >= 8)
            || (prc[1] == RC_FLOAT && areg[1] >= 16)
            || (nregs == 2 && prc[1] == RC_FLOAT && prc[2] == RC_FLOAT
                && areg[1] >= 15)
            || (nregs == 2 && prc[1] != prc[2]
                && (areg[1] >= 16 || areg[0] >= 8))) {
            info[i] = 32;
            ఒకవేళ (align < XLEN)
              align = XLEN;
            దొంతర_adj += (కొలత + align - 1) & -align;
            ఒకవేళ (!old && !sa) /* one vararg on stack forces the rest on stack */
              areg[0] = 8, areg[1] = 16;
        } లేకపోతే {
            info[i] = areg[prc[1] - 1]++;
            ఒకవేళ (!byref)
              info[i] |= (fieldofs[1] & VT_BTYPE) << 12;
            ప్రతిజ్ఞా(!(fieldofs[1] >> 4));
            ఒకవేళ (nregs == 2) {
                ఒకవేళ (prc[2] == RC_FLOAT || areg[0] < 8)
                  info[i] |= (1 + areg[prc[2] - 1]++) << 7;
                లేకపోతే {
                    info[i] |= 16;
                    దొంతర_adj += 8;
                }
                ఒకవేళ (!byref) {
                    ప్రతిజ్ఞా((fieldofs[2] >> 4) < 2048);
                    info[i] |= fieldofs[2] << (12 + 4); // includes offset
                }
            }
        }
        info[i] |= byref;
        ఒకవేళ (sa)
          sa = sa->తదుపరి;
    }
    దొంతర_adj = (దొంతర_adj + 15) & -16;
    tempspace = (tempspace + 15) & -16;
    దొంతర_కూడు = దొంతర_adj + tempspace;

    ఒకవేళ (దొంతర_కూడు) {
        ఒకవేళ (దొంతర_కూడు >= 0x800) {
            o(0x37 | (5 << 7) | పై_2(-దొంతర_కూడు)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(-దొంతర_కూడు)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        లేకపోతే
            EI(0x13, 0, 2, 2, -దొంతర_కూడు);   // addi sp, sp, -adj
        కొరకు (i = ofs = 0; i < nb_వాదనలు; i++) {
            ఒకవేళ (info[i] & (64 | 32)) {
                vrotb(nb_వాదనలు - i);
                కొలత = type_కొలత(&vtop->type, &align);
                ఒకవేళ (info[i] & 64) {
                    vset(&char_సూచిక_type, TREG_SP, 0);
                    vpushi(దొంతర_adj + (info[i] >> 7));
                    gen_op('+');
                    vpushv(vtop); // this replaces the old argument
                    vrott(3);
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vpop();
                    కొలత = align = 8;
                }
                ఒకవేళ (info[i] & 32) {
                    ఒకవేళ (align < XLEN)
                      align = XLEN;
                    /* Once we support offseted regs we can do this:
                       vset(&vtop->type, TREG_SP | VT_LVAL, ofs);
                       to construct the lvalue for the outgoing stack slot,
                       until then we have to jump through hoops.  */
                    vset(&char_సూచిక_type, TREG_SP, 0);
                    ofs = (ofs + align - 1) & -align;
                    vpushi(ofs);
                    gen_op('+');
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vtop->r = vtop->r2 = VT_CONST; // this arg is done
                    ofs += కొలత;
                }
                vrott(nb_వాదనలు - i);
            } లేకపోతే ఒకవేళ (info[i] & 16) {
                ప్రతిజ్ఞా(!splitofs);
                splitofs = ofs;
                ofs += 8;
            }
        }
    }
    కొరకు (i = 0; i < nb_వాదనలు; i++) {
        పూర్ణాంకం ii = info[nb_వాదనలు - 1 - i], r = ii, r2 = r;
        ఒకవేళ (!(r & 32)) {
            CType origtype;
            పూర్ణాంకం loadt;
            r &= 15;
            r2 = r2 & 64 ? 0 : (r2 >> 7) & 31;
            ప్రతిజ్ఞా(r2 <= 16);
            vrotb(i+1);
            origtype = vtop->type;
            కొలత = type_కొలత(&vtop->type, &align);
            ఒకవేళ (కొలత == 0)
                వెళ్ళు పూర్తి;
            loadt = vtop->type.t & VT_BTYPE;
            ఒకవేళ (loadt == VT_STRUCT) {
                loadt = (ii >> 12) & VT_BTYPE;
            }
            ఒకవేళ (info[nb_వాదనలు - 1 - i] & 16) {
                ప్రతిజ్ఞా(!r2);
                r2 = 1 + TREG_RA;
            }
            ఒకవేళ (loadt == VT_LDOUBLE) {
                ప్రతిజ్ఞా(r2);
                r2--;
            } లేకపోతే ఒకవేళ (r2) {
                test_lvalue();
                vpushv(vtop);
            }
            vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
            gv(r < 8 ? RC_R(r) : RC_F(r - 8));
            vtop->type = origtype;

            ఒకవేళ (r2 && loadt != VT_LDOUBLE) {
                r2--;
                ప్రతిజ్ఞా(r2 < 16 || r2 == TREG_RA);
                vswap();
                gaddrof();
                vtop->type = char_సూచిక_type;
                vpushi(ii >> 20);
#నిర్వచితమైతే CONFIG_TCC_BCHECK
		ఒకవేళ ((origtype.t & VT_BTYPE) == VT_STRUCT)
                    tcc_state->do_bounds_check = 0;
#అయితే_ముగింపు
                gen_op('+');
#నిర్వచితమైతే CONFIG_TCC_BCHECK
		tcc_state->do_bounds_check = bc_save;
#అయితే_ముగింపు
                indir();
                vtop->type = origtype;
                loadt = vtop->type.t & VT_BTYPE;
                ఒకవేళ (loadt == VT_STRUCT) {
                    loadt = (ii >> 16) & VT_BTYPE;
                }
                save_reg_upstack(r2, 1);
                vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
                ఎక్కించు(r2, vtop);
                ప్రతిజ్ఞా(r2 < VT_CONST);
                vtop--;
                vtop->r2 = r2;
            }
            ఒకవేళ (info[nb_వాదనలు - 1 - i] & 16) {
                ES(0x23, 3, 2, ireg(vtop->r2), splitofs); // sd t0, ofs(sp)
                vtop->r2 = VT_CONST;
            } లేకపోతే ఒకవేళ (loadt == VT_LDOUBLE && vtop->r2 != r2) {
                ప్రతిజ్ఞా(vtop->r2 <= 7 && r2 <= 7);
                /* XXX we'd like to have 'gv' move directly into
                   the right class instead of us fixing it up.  */
                EI(0x13, 0, ireg(r2), ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = r2;
            }
పూర్తి:
            vrott(i+1);
        }
    }
    vrotb(nb_వాదనలు + 1);
    save_regs(nb_వాదనలు + 1);
    gcall_or_jmp(1);
    vtop -= nb_వాదనలు + 1;
    ఒకవేళ (దొంతర_కూడు) {
        ఒకవేళ (దొంతర_కూడు >= 0x800) {
            o(0x37 | (5 << 7) | పై_2(దొంతర_కూడు)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(దొంతర_కూడు)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        లేకపోతే
            EI(0x13, 0, 2, 2, దొంతర_కూడు);      // addi sp, sp, adj
   }
   tcc_free(info);
}

స్థిర పూర్ణాంకం func_sub_sp_స్థానభ్రంశం, అంకె_va_regs, func_va_list_ofs;

ST_FUNC శూన్య gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    పూర్ణాంకం i, addr, align, కొలత;
    పూర్ణాంకం param_addr = 0;
    పూర్ణాంకం areg[2];
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    loc = -16; // for ra and s0
    func_sub_sp_స్థానభ్రంశం = ind;
    ind += 5 * 4;

    areg[0] = 0, areg[1] = 0;
    addr = 0;
    /* if the function returns by reference, then add an
       implicit pointer parameter */
    కొలత = type_కొలత(&func_vt, &align);
    ఒకవేళ (కొలత > 2 * XLEN) {
        loc -= 8;
        func_vc = loc;
        ES(0x23, 3, 8, 10 + areg[0]++, loc); // sd a0, loc(s0)
    }
    /* define parameters */
    అయితే ((sym = sym->తదుపరి) != ఖాళీ) {
        పూర్ణాంకం byref = 0;
        పూర్ణాంకం regcount;
        పూర్ణాంకం prc[3], fieldofs[3];
        type = &sym->type;
        కొలత = type_కొలత(type, &align);
        ఒకవేళ (కొలత > 2 * XLEN) {
            type = &char_సూచిక_type;
            కొలత = align = byref = 8;
        }
        reg_pass(type, prc, fieldofs, 1);
        regcount = prc[0];
        ఒకవేళ (areg[prc[1] - 1] >= 8
            || (regcount == 2
                && ((prc[1] == RC_FLOAT && prc[2] == RC_FLOAT && areg[1] >= 7)
                    || (prc[1] != prc[2] && (areg[1] >= 8 || areg[0] >= 8))))) {
            ఒకవేళ (align < XLEN)
              align = XLEN;
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += కొలత;
        } లేకపోతే {
            loc -= regcount * 8; // XXX could reserve only 'size' bytes
            param_addr = loc;
            కొరకు (i = 0; i < regcount; i++) {
                ఒకవేళ (areg[prc[1+i] - 1] >= 8) {
                    ప్రతిజ్ఞా(i == 1 && regcount == 2 && !(addr & 7));
                    EI(0x03, 3, 5, 8, addr); // ld t0, addr(s0)
                    addr += 8;
                    ES(0x23, 3, 8, 5, loc + i*8); // sd t0, loc(s0)
                } లేకపోతే ఒకవేళ (prc[1+i] == RC_FLOAT) {
                    ES(0x27, (కొలత / regcount) == 4 ? 2 : 3, 8, 10 + areg[1]++, loc + (fieldofs[i+1] >> 4)); // fs[wd] FAi, loc(s0)
                } లేకపోతే {
                    ES(0x23, 3, 8, 10 + areg[0]++, loc + i*8); // sd aX, loc(s0) // XXX
                }
            }
        }
        gfunc_సమితి_param(sym, param_addr, byref);
    }
    func_va_list_ofs = addr;
    అంకె_va_regs = 0;
    ఒకవేళ (func_var) {
        కొరకు (; areg[0] < 8; areg[0]++) {
            అంకె_va_regs++;
            ES(0x23, 3, 8, 10 + areg[0], -8 + అంకె_va_regs * 8); // sd aX, loc(s0)
        }
    }
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#అయితే_ముగింపు
}

ST_FUNC పూర్ణాంకం gfunc_sret(CType *vt, పూర్ణాంకం variadic, CType *ret,
                       పూర్ణాంకం *ret_align, పూర్ణాంకం *regsize)
{
    పూర్ణాంకం align, కొలత = type_కొలత(vt, &align), nregs;
    పూర్ణాంకం prc[3], fieldofs[3];
    *ret_align = 1;
    *regsize = 8;
    ఒకవేళ (కొలత > 16)
      తిరిగి 0;
    reg_pass(vt, prc, fieldofs, 1);
    nregs = prc[0];
    ఒకవేళ (nregs == 2 && prc[1] != prc[2])
      తిరిగి -1;  /* generic code can't deal with this case */
    ఒకవేళ (prc[1] == RC_FLOAT) {
        *regsize = కొలత / nregs;
    }
    ret->t = fieldofs[1] & VT_BTYPE;
    ret->ref = ఖాళీ;
    తిరిగి nregs;
}

ST_FUNC శూన్య arch_transfer_ret_regs(పూర్ణాంకం aftercall)
{
    పూర్ణాంకం prc[3], fieldofs[3];
    reg_pass(&vtop->type, prc, fieldofs, 1);
    ప్రతిజ్ఞా(prc[0] == 2 && prc[1] != prc[2] && !(fieldofs[1] >> 4));
    ప్రతిజ్ఞా(vtop->r == (VT_LOCAL | VT_LVAL));
    vpushv(vtop);
    vtop->type.t = fieldofs[1] & VT_BTYPE;
    (aftercall ? store : ఎక్కించు)(prc[1] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop->c.i += fieldofs[2] >> 4;
    vtop->type.t = fieldofs[2] & VT_BTYPE;
    (aftercall ? store : ఎక్కించు)(prc[2] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop--;
}

ST_FUNC శూన్య gfunc_epilog(శూన్య)
{
    పూర్ణాంకం v, saved_ind, d, large_ofs_ind;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#అయితే_ముగింపు

    loc = (loc - అంకె_va_regs * 8);
    d = v = (-loc + 15) & -16;

    EI(0x13, 0, 2, 8, అంకె_va_regs * 8); // addi sp, s0, num_va_regs*8
    EI(0x03, 3, 1, 8, -8); // ld ra, -8(s0)
    EI(0x03, 3, 8, 8, -16); // ld s0, -16(s0)
    EI(0x67, 0, 0, 1, 0); // jalr x0, 0(x1), aka ret

    large_ofs_ind = ind;
    ఒకవేళ (v >= (1 << 11)) {
        d = 16;
        EI(0x13, 0, 8, 2, d - అంకె_va_regs * 8);      // addi s0, sp, d
        o(0x37 | (5 << 7) | పై_2(v-16)); //lui t0, upper(v)
        EI(0x13, 0, 5, 5, SIGN11(v-16)); // addi t0, t0, lo(v)
        ER(0x33, 0, 2, 2, 5, 0x20); // sub sp, sp, t0
        gjmp_addr(func_sub_sp_స్థానభ్రంశం + 5*4);
    }
    saved_ind = ind;

    ind = func_sub_sp_స్థానభ్రంశం;
    EI(0x13, 0, 2, 2, -d);     // addi sp, sp, -d
    ES(0x23, 3, 2, 1, d - 8 - అంకె_va_regs * 8);  // sd ra, d-8(sp)
    ES(0x23, 3, 2, 8, d - 16 - అంకె_va_regs * 8); // sd s0, d-16(sp)
    ఒకవేళ (v < (1 << 11))
      EI(0x13, 0, 8, 2, d - అంకె_va_regs * 8);      // addi s0, sp, d
    లేకపోతే
      gjmp_addr(large_ofs_ind);
    ఒకవేళ ((ind - func_sub_sp_స్థానభ్రంశం) != 5*4)
      EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
    ind = saved_ind;
}

ST_FUNC శూన్య gen_va_ప్రారంభం(శూన్య)
{
    vtop--;
    vset(&char_సూచిక_type, VT_LOCAL, func_va_list_ofs);
}

ST_FUNC శూన్య gen_fill_nops(పూర్ణాంకం బైట్లు)
{
    ఒకవేళ ((బైట్లు & 3))
      tcc_error("alignment of code section not multiple of 4");
    అయితే (బైట్లు > 0) {
        EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
        బైట్లు -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC పూర్ణాంకం gjmp(పూర్ణాంకం t)
{
    ఒకవేళ (nocode_wanted)
      తిరిగి t;
    o(t);
    తిరిగి ind - 4;
}

// Generate branch to known address:
ST_FUNC శూన్య gjmp_addr(పూర్ణాంకం a)
{
    uint32_t r = a - ind, imm;
    ఒకవేళ ((r + (1 << 21)) & ~((1U << 22) - 2)) {
        o(0x17 | (5 << 7) | పై_2(r)); // lui RR, up(r)
        r = SIGN11(r);
        EI(0x67, 0, 0, 5, r);      // jalr x0, r(t0)
    } లేకపోతే {
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        o(0x6f | imm); // jal x0, imm ==  j imm
    }
}

ST_FUNC పూర్ణాంకం gjmp_cond(పూర్ణాంకం op, పూర్ణాంకం t)
{
    పూర్ణాంకం tmp;
    పూర్ణాంకం a = vtop->cmp_r & 0xff;
    పూర్ణాంకం b = (vtop->cmp_r >> 8) & 0xff;
    ఎంపిక (op) {
        స్థితి TOK_ULT: op = 6; ఆపు;
        స్థితి TOK_UGE: op = 7; ఆపు;
        స్థితి TOK_ULE: op = 7; tmp = a; a = b; b = tmp; ఆపు;
        స్థితి TOK_UGT: op = 6; tmp = a; a = b; b = tmp; ఆపు;
        స్థితి TOK_LT:  op = 4; ఆపు;
        స్థితి TOK_GE:  op = 5; ఆపు;
        స్థితి TOK_LE:  op = 5; tmp = a; a = b; b = tmp; ఆపు;
        స్థితి TOK_GT:  op = 4; tmp = a; a = b; b = tmp; ఆపు;
        స్థితి TOK_NE:  op = 1; ఆపు;
        స్థితి TOK_EQ:  op = 0; ఆపు;
    }
    o(0x63 | (op ^ 1) << 12 | a << 15 | b << 20 | 8 << 7); // bOP a,b,+4
    తిరిగి gjmp(t);
}

ST_FUNC పూర్ణాంకం gjmp_append(పూర్ణాంకం n, పూర్ణాంకం t)
{
    శూన్య *p;
    /* insert jump list n into t */
    ఒకవేళ (n) {
        uint32_t n1 = n, n2;
        అయితే ((n2 = read32le(p = cur_పాఠ్యం_section->దత్తాంశం + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    తిరిగి t;
}

స్థిర శూన్య gen_opil(పూర్ణాంకం op, పూర్ణాంకం ll)
{
    పూర్ణాంకం a, b, d;
    పూర్ణాంకం func3 = 0;
    ll = ll ? 0 : 8;
    ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
        పూర్ణాంకం fc = vtop->c.i;
        ఒకవేళ (fc == vtop->c.i && !దిగువ_అధికప్రవాహం(fc)) {
            పూర్ణాంకం cll = 0;
            పూర్ణాంకం m = ll ? 31 : 63;
            vswap();
            gv(RC_INT);
            a = ireg(vtop[0].r);
            --vtop;
            d = get_reg(RC_INT);
            ++vtop;
            vswap();
            ఎంపిక (op) {
                స్థితి '-':
                    ఒకవేళ (fc <= -(1 << 11))
                      ఆపు;
                    fc = -fc;
                స్థితి '+':
                    func3 = 0; // addi d, a, fc
                    cll = ll;
                do_cop:
                    EI(0x13 | cll, func3, ireg(d), a, fc);
                    --vtop;
                    ఒకవేళ (op >= TOK_ULT && op <= TOK_GT) {
                      vset_VT_CMP(TOK_NE);
                      vtop->cmp_r = ireg(d) | 0 << 8;
                    } లేకపోతే
                      vtop[0].r = d;
                    తిరిగి;
                స్థితి TOK_LE:
                    ఒకవేళ (fc >= (1 << 11) - 1)
                      ఆపు;
                    ++fc;
                స్థితి TOK_LT:  func3 = 2; వెళ్ళు do_cop; // slti d, a, fc
                స్థితి TOK_ULE:
                    ఒకవేళ (fc >= (1 << 11) - 1 || fc == -1)
                      ఆపు;
                    ++fc;
                స్థితి TOK_ULT: func3 = 3; వెళ్ళు do_cop; // sltiu d, a, fc
                స్థితి '^':     func3 = 4; వెళ్ళు do_cop; // xori d, a, fc
                స్థితి '|':     func3 = 6; వెళ్ళు do_cop; // ori  d, a, fc
                స్థితి '&':     func3 = 7; వెళ్ళు do_cop; // andi d, a, fc
                స్థితి TOK_SHL: func3 = 1; cll = ll; fc &= m; వెళ్ళు do_cop; // slli d, a, fc
                స్థితి TOK_SHR: func3 = 5; cll = ll; fc &= m; వెళ్ళు do_cop; // srli d, a, fc
                స్థితి TOK_SAR: func3 = 5; cll = ll; fc = 1024 | (fc & m); వెళ్ళు do_cop;

                స్థితి TOK_UGE: /* -> TOK_ULT */
                స్థితి TOK_UGT: /* -> TOK_ULE */
                స్థితి TOK_GE:  /* -> TOK_LT */
                స్థితి TOK_GT:  /* -> TOK_LE */
                    gen_opil(op - 1, !ll);
                    vtop->cmp_op ^= 1;
                    తిరిగి;

                స్థితి TOK_NE:
                స్థితి TOK_EQ:
                    ఒకవేళ (fc)
                      gen_opil('-', !ll), a = ireg(vtop++->r);
                    --vtop;
                    vset_VT_CMP(op);
                    vtop->cmp_r = a | 0 << 8;
                    తిరిగి;
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
    ఎంపిక (op) {
    అప్రమేయ:
        ఒకవేళ (op >= TOK_ULT && op <= TOK_GT) {
            vset_VT_CMP(op);
            vtop->cmp_r = a | b << 8;
            ఆపు;
        }
        tcc_error("implement me: %s(%s)", __FUNCTION__, get_tok_str(op, ఖాళీ));
        ఆపు;

    స్థితి '+':
        ER(0x33 | ll, 0, d, a, b, 0); // add d, a, b
        ఆపు;
    స్థితి '-':
        ER(0x33 | ll, 0, d, a, b, 0x20); // sub d, a, b
        ఆపు;
    స్థితి TOK_SAR:
        ER(0x33 | ll | ll, 5, d, a, b, 0x20); // sra d, a, b
        ఆపు;
    స్థితి TOK_SHR:
        ER(0x33 | ll | ll, 5, d, a, b, 0); // srl d, a, b
        ఆపు;
    స్థితి TOK_SHL:
        ER(0x33 | ll, 1, d, a, b, 0); // sll d, a, b
        ఆపు;
    స్థితి '*':
        ER(0x33 | ll, 0, d, a, b, 1); // mul d, a, b
        ఆపు;
    స్థితి '/':
    స్థితి TOK_PDIV:
        ER(0x33 | ll, 4, d, a, b, 1); // div d, a, b
        ఆపు;
    స్థితి '&':
        ER(0x33, 7, d, a, b, 0); // and d, a, b
        ఆపు;
    స్థితి '^':
        ER(0x33, 4, d, a, b, 0); // xor d, a, b
        ఆపు;
    స్థితి '|':
        ER(0x33, 6, d, a, b, 0); // or d, a, b
        ఆపు;
    స్థితి '%':
        ER(ll ? 0x3b:  0x33, 6, d, a, b, 1); // rem d, a, b
        ఆపు;
    స్థితి TOK_UMOD:
        ER(0x33 | ll, 7, d, a, b, 1); // remu d, a, b
        ఆపు;
    స్థితి TOK_UDIV:
        ER(0x33 | ll, 5, d, a, b, 1); // divu d, a, b
        ఆపు;
    }
}

ST_FUNC శూన్య gen_opi(పూర్ణాంకం op)
{
    gen_opil(op, 0);
}

ST_FUNC శూన్య gen_opl(పూర్ణాంకం op)
{
    gen_opil(op, 1);
}

ST_FUNC శూన్య gen_opf(పూర్ణాంకం op)
{
    పూర్ణాంకం rs1, rs2, rd, dbl, invert;
    ఒకవేళ (vtop[0].type.t == VT_LDOUBLE) {
        CType type = vtop[0].type;
        పూర్ణాంకం func = 0;
        పూర్ణాంకం cond = -1;
        ఎంపిక (op) {
        స్థితి '*': func = TOK___multf3; ఆపు;
        స్థితి '+': func = TOK___addtf3; ఆపు;
        స్థితి '-': func = TOK___subtf3; ఆపు;
        స్థితి '/': func = TOK___divtf3; ఆపు;
        స్థితి TOK_EQ: func = TOK___eqtf2; cond = 1; ఆపు;
        స్థితి TOK_NE: func = TOK___netf2; cond = 0; ఆపు;
        స్థితి TOK_LT: func = TOK___lttf2; cond = 10; ఆపు;
        స్థితి TOK_GE: func = TOK___getf2; cond = 11; ఆపు;
        స్థితి TOK_LE: func = TOK___letf2; cond = 12; ఆపు;
        స్థితి TOK_GT: func = TOK___gttf2; cond = 13; ఆపు;
        అప్రమేయ: ప్రతిజ్ఞా(0); ఆపు;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = REG_IRET;
        vtop->r2 = cond < 0 ? TREG_R(1) : VT_CONST;
        ఒకవేళ (cond < 0)
            vtop->type = type;
        లేకపోతే {
            vpushi(0);
            gen_opil(op, 1);
        }
        తిరిగి;
    }

    gv2(RC_FLOAT, RC_FLOAT);
    ప్రతిజ్ఞా(vtop->type.t == VT_DOUBLE || vtop->type.t == VT_FLOAT);
    dbl = vtop->type.t == VT_DOUBLE;
    rs1 = freg(vtop[-1].r);
    rs2 = freg(vtop->r);
    vtop--;
    invert = 0;
    ఎంపిక(op) {
    అప్రమేయ:
        ప్రతిజ్ఞా(0);
    స్థితి '+':
        op = 0; // fadd
    arithop:
        rd = get_reg(RC_FLOAT);
        vtop->r = rd;
        rd = freg(rd);
        ER(0x53, 7, rd, rs1, rs2, dbl | (op << 2)); // fop.[sd] RD, RS1, RS2 (dyn rm)
        ఆపు;
    స్థితి '-':
        op = 1; // fsub
        వెళ్ళు arithop;
    స్థితి '*':
        op = 2; // fmul
        వెళ్ళు arithop;
    స్థితి '/':
        op = 3; // fdiv
        వెళ్ళు arithop;
    స్థితి TOK_EQ:
        op = 2; // EQ
    cmpop:
        rd = get_reg(RC_INT);
        vtop->r = rd;
        rd = ireg(rd);
        ER(0x53, op, rd, rs1, rs2, dbl | 0x50); // fcmp.[sd] RD, RS1, RS2 (op == eq/lt/le)
        ఒకవేళ (invert)
          EI(0x13, 4, rd, rd, 1); // xori RD, 1

        /* generate VT_CMP output */
        vset_VT_CMP(TOK_NE);
        vtop->cmp_r = rd | (0 << 8);
        ఆపు;
    స్థితి TOK_NE:
        invert = 1;
        op = 2; // EQ
        వెళ్ళు cmpop;
    స్థితి TOK_LT:
        op = 1; // LT
        వెళ్ళు cmpop;
    స్థితి TOK_LE:
        op = 0; // LE
        వెళ్ళు cmpop;
    స్థితి TOK_GT:
        op = 1; // LT
        rd = rs1, rs1 = rs2, rs2 = rd;
        వెళ్ళు cmpop;
    స్థితి TOK_GE:
        op = 0; // LE
        rd = rs1, rs1 = rs2, rs2 = rd;
        వెళ్ళు cmpop;
    }
}

ST_FUNC శూన్య gen_cvt_csti(పూర్ణాంకం t)
{
    పూర్ణాంకం r = ireg(gv(RC_INT));
    ఒకవేళ ((t & VT_BTYPE) == VT_SHORT) {
        ఒకవేళ (t & VT_UNSIGNED) {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EI(0x13, 5, r, r, 48); // srli r, r, 48
        } లేకపోతే {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EIu(0x13, 5, r, r, 0x400 | 48); // srai r, r, 48
        }
    } లేకపోతే {
        ఒకవేళ (t & VT_UNSIGNED) {
            EI(0x13, 7, r, r, 0xff); // andi r, r, 0xff
        } లేకపోతే {
            EI(0x13, 1, r, r, 56); // slli r, r, 56
            EIu(0x13, 5, r, r, 0x400 | 56); // srai r, r, 56
        }
    }
}

ST_FUNC శూన్య gen_cvt_sxtw(శూన్య)
{
    పూర్ణాంకం r = ireg(gv(RC_INT));
    EI(0x1b, 0, r, r, 0); // addiw r, r, 0
}

ST_FUNC శూన్య gen_cvt_itof(పూర్ణాంకం t)
{
    పూర్ణాంకం rr = ireg(gv(RC_INT)), dr;
    పూర్ణాంకం u = vtop->type.t & VT_UNSIGNED;
    పూర్ణాంకం l = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    ఒకవేళ (t == VT_LDOUBLE) {
        పూర్ణాంకం func = l ?
          (u ? TOK___floatunditf : TOK___floatditf) :
          (u ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        vtop->r2 = TREG_R(1);
    } లేకపోతే {
        vtop--;
        dr = get_reg(RC_FLOAT);
        vtop++;
        vtop->r = dr;
        dr = freg(dr);
        EIu(0x53, 7, dr, rr, ((0x68 | (t == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[sd].[wl][u]
    }
}

ST_FUNC శూన్య gen_cvt_ftoi(పూర్ణాంకం t)
{
    పూర్ణాంకం ft = vtop->type.t & VT_BTYPE;
    పూర్ణాంకం l = (t & VT_BTYPE) == VT_LLONG;
    పూర్ణాంకం u = t & VT_UNSIGNED;
    ఒకవేళ (ft == VT_LDOUBLE) {
        పూర్ణాంకం func = l ?
          (u ? TOK___fixunstfdi : TOK___fixtfdi) :
          (u ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
    } లేకపోతే {
        పూర్ణాంకం rr = freg(gv(RC_FLOAT)), dr;
        vtop--;
        dr = get_reg(RC_INT);
        vtop++;
        vtop->r = dr;
        dr = ireg(dr);
        EIu(0x53, 1, dr, rr, ((0x60 | (ft == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[wl][u].[sd] rtz
    }
}

ST_FUNC శూన్య gen_cvt_ftof(పూర్ణాంకం dt)
{
    పూర్ణాంకం st = vtop->type.t & VT_BTYPE, rs, rd;
    dt &= VT_BTYPE;
    ఒకవేళ (st == dt)
      తిరిగి;
    ఒకవేళ (dt == VT_LDOUBLE || st == VT_LDOUBLE) {
        పూర్ణాంకం func = (dt == VT_LDOUBLE) ?
            (st == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (dt == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        /* We can't use gfunc_call, as func_old_type works like vararg
           functions, and on riscv unnamed float args are passed like
           integers.  But we really need them in the float argument registers
           for extendsftf2/extenddftf2.  So, do it explicitely.  */
        save_regs(1);
        ఒకవేళ (dt == VT_LDOUBLE)
          gv(RC_F(0));
        లేకపోతే {
            gv(RC_R(0));
            ప్రతిజ్ఞా(vtop->r2 < 7);
            ఒకవేళ (vtop->r2 != 1 + vtop->r) {
                EI(0x13, 0, ireg(vtop->r) + 1, ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = 1 + vtop->r;
            }
        }
        vpush_helper_func(func);
        gcall_or_jmp(1);
        vtop -= 2;
        vpushi(0);
        vtop->type.t = dt;
        ఒకవేళ (dt == VT_LDOUBLE)
          vtop->r = REG_IRET, vtop->r2 = REG_IRET+1;
        లేకపోతే
          vtop->r = REG_FRET;
    } లేకపోతే {
        ప్రతిజ్ఞా (dt == VT_FLOAT || dt == VT_DOUBLE);
        ప్రతిజ్ఞా (st == VT_FLOAT || st == VT_DOUBLE);
        rs = gv(RC_FLOAT);
        rd = get_reg(RC_FLOAT);
        ఒకవేళ (dt == VT_DOUBLE)
          EI(0x53, 0, freg(rd), freg(rs), 0x21 << 5); // fcvt.d.s RD, RS (no rm)
        లేకపోతే
          EI(0x53, 7, freg(rd), freg(rs), (0x20 << 5) | 1); // fcvt.s.d RD, RS (dyn rm)
        vtop->r = rd;
    }
}

/* increment tcov counter */
ST_FUNC శూన్య gen_increment_tcov (SValue *sv)
{
    పూర్ణాంకం r1, r2;
    Sym label = {0};
    label.type.t = VT_VOID | VT_STATIC;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    r1 = ireg(r1);
    r2 = ireg(r2);
    greloca(cur_పాఠ్యం_section, sv->sym, ind, R_RISCV_PCREL_HI20, 0);
    put_extern_sym(&label, cur_పాఠ్యం_section, ind, 0);
    o(0x17 | (r1 << 7)); // auipc RR, 0 %pcrel_hi(sym)
    greloca(cur_పాఠ్యం_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, r2, r1, 0); // ld r2, x[r1]
    EI(0x13, 0, r2, r2, 1); // addi r2, r2, #1
    greloca(cur_పాఠ్యం_section, sv->sym, ind, R_RISCV_PCREL_HI20, 0);
    label.c = 0; /* force new local ELF symbol */
    put_extern_sym(&label, cur_పాఠ్యం_section, ind, 0);
    o(0x17 | (r1 << 7)); // auipc RR, 0 %pcrel_hi(sym)
    greloca(cur_పాఠ్యం_section, &label, ind, R_RISCV_PCREL_LO12_S, 0);
    ES(0x23, 3, r1, r2, 0); // sd r2, [r1]
    vpop();
}

ST_FUNC శూన్య ggoto(శూన్య)
{
    gcall_or_jmp(0);
    vtop--;
}

ST_FUNC శూన్య gen_vla_sp_save(పూర్ణాంకం addr)
{
    ఒకవేళ (దిగువ_అధికప్రవాహం(addr)) {
	o(0x37 | (5 << 7) | పై_2(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        ES(0x23, 3, 5, 2, SIGN11(addr)); // sd sp, fc(t0)
    }
    లేకపోతే
        ES(0x23, 3, 8, 2, addr); // sd sp, fc(s0)
}

ST_FUNC శూన్య gen_vla_sp_restore(పూర్ణాంకం addr)
{
    ఒకవేళ (దిగువ_అధికప్రవాహం(addr)) {
	o(0x37 | (5 << 7) | పై_2(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        EI(0x03, 3, 2, 5, SIGN11(addr)); // ld sp, fc(t0)
    }
    లేకపోతే
        EI(0x03, 3, 2, 8, addr); // ld sp, fc(s0)
}

ST_FUNC శూన్య gen_vla_alloc(CType *type, పూర్ణాంకం align)
{
    పూర్ణాంకం rr;
#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    ఒకవేళ (tcc_state->do_bounds_check)
        vpushv(vtop);
#అయితే_ముగింపు
    rr = ireg(gv(RC_INT));
#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    ఒకవేళ (tcc_state->do_bounds_check)
        EI(0x13, 0, rr, rr, 15+1);   // addi RR, RR, 15+1
    లేకపోతే
#అయితే_ముగింపు
    EI(0x13, 0, rr, rr, 15);   // addi RR, RR, 15
    EI(0x13, 7, rr, rr, -16);  // andi, RR, RR, -16
    ER(0x33, 0, 2, 2, rr, 0x20); // sub sp, sp, rr
    vpop();
#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    ఒకవేళ (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x00010513); /* mv a0,sp */
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_కూడు_epilog = 1;
    }
#అయితే_ముగింపు
}

ST_FUNC శూన్య gen_clear_cache(శూన్య)
{
    /* Zifencei extension: fence + fence.i for I/D synchronization.
       Required by RISC-V Linux ABI, present on all Linux-capable cores. */
    o(0x0ff0000f); // fence iorw, iorw
    o(0x0000100f); // fence.i
}
#అయితే_ముగింపు
