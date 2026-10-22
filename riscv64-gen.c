#यदि_परिभाषितम् TARGET_DEFS_ONLY

// Number of registers available to allocator:
#परिभाषय NB_REGS 19 // x10-x17 aka a0-a7, f10-f17 aka fa0-fa7, xxx, ra, sp
#परिभाषय CONFIG_TCC_ASM

#परिभाषय TREG_R(x) (x) // x = 0..7
#परिभाषय TREG_F(x) (x + 8) // x = 0..7

// Register classes sorted from more general to more precise:
#परिभाषय RC_INT (1 << 0)
#परिभाषय RC_FLOAT (1 << 1)
#परिभाषय RC_R(x) (1 << (2 + (x))) // x = 0..7
#परिभाषय RC_F(x) (1 << (10 + (x))) // x = 0..7

#परिभाषय RC_IRET (RC_R(0)) // int return register class
#परिभाषय RC_IRE2 (RC_R(1)) // int 2nd return register class
#परिभाषय RC_FRET (RC_F(0)) // float return register class

#परिभाषय REG_IRET (TREG_R(0)) // int return register number
#परिभाषय REG_IRE2 (TREG_R(1)) // int 2nd return register number
#परिभाषय REG_FRET (TREG_F(0)) // float return register number

#परिभाषय PTR_आकार 8

#परिभाषय LDOUBLE_आकार 16
#परिभाषय LDOUBLE_ALIGN 16

#परिभाषय MAX_ALIGN 16

#परिभाषय CHAR_IS_UNSIGNED

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#परिभाषय PROMOTE_RET

#अन्यथा
#परिभाषय USING_GLOBALS
#अन्तर्भाव "tcc.h"
#अन्तर्भाव <assert.h>

#परिभाषय ऊर्ध्वस्थम्_2(x)	(((अचिह्नित)(x) + 0x800u) & 0xfffff000)
#परिभाषय नीचः_अतिप्रवाहः(x)	ऊर्ध्वस्थम्_2(x)
#परिभाषय SIGN7(x)	((((x) & 0xff) ^ 0x80) - 0x80)
#परिभाषय SIGN11(x)	((((x) & 0xfff) ^ 0x800) - 0x800)

ST_दत्त ध्रुव वर्ण * ध्रुव target_machine_defs =
    "__riscv\0"
    "__riscv_xlen 64\0"
    "__riscv_flen 64\0"
    "__riscv_div\0"
    "__riscv_mul\0"
    "__riscv_fdiv\0"
    "__riscv_fsqrt\0"
    "__riscv_float_abi_double\0"
    ;

#परिभाषय XLEN 8

#परिभाषय TREG_RA 17
#परिभाषय TREG_SP 18

ST_दत्त ध्रुव पूर्णाङ्क reg_classes[NB_REGS] = {
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

#यदि defined(CONFIG_TCC_BCHECK)
स्थिर addr_t func_bound_विस्थापनम्;
स्थिर अचिह्नित दीर्घ func_bound_ind;
ST_दत्त पूर्णाङ्क func_bound_सङ्कलय_epilog;
#यदि_अन्तः

स्थिर पूर्णाङ्क ireg(पूर्णाङ्क r)
{
    यदि (r == TREG_RA)
      प्रत्यागम 1; // ra
    यदि (r == TREG_SP)
      प्रत्यागम 2; // sp
    प्रतिज्ञा(r >= 0 && r < 8);
    प्रत्यागम r + 10;  // tccrX --> aX == x(10+X)
}

स्थिर पूर्णाङ्क is_ireg(पूर्णाङ्क r)
{
    प्रत्यागम (अचिह्नित)r < 8 || r == TREG_RA || r == TREG_SP;
}

स्थिर पूर्णाङ्क freg(पूर्णाङ्क r)
{
    प्रतिज्ञा(r >= 8 && r < 16);
    प्रत्यागम r - 8 + 10;  // tccfX --> faX == f(10+X)
}

स्थिर पूर्णाङ्क is_freg(पूर्णाङ्क r)
{
    प्रत्यागम r >= 8 && r < 16;
}

ST_FUNC शून्य o(अचिह्नित पूर्णाङ्क c)
{
    पूर्णाङ्क ind1 = ind + 4;
    यदि (nocode_wanted)
        प्रत्यागम;
    यदि (ind1 > cur_text_section->दत्त_allocated)
        section_realloc(cur_text_section, ind1);
    write32le(cur_text_section->दत्त + ind, c);
    ind = ind1;
}

स्थिर शून्य EIu(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    o(opcode | (func3 << 12) | (rd << 7) | (rs1 << 15) | (imm << 20));
}

स्थिर शून्य ER(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t func7)
{
    o(opcode | func3 << 12 | rd << 7 | rs1 << 15 | rs2 << 20 | func7 << 25);
}

स्थिर शून्य EI(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    प्रतिज्ञा(! नीचः_अतिप्रवाहः(imm));
    EIu(opcode, func3, rd, rs1, imm);
}

स्थिर शून्य ES(uint32_t opcode, uint32_t func3,
               uint32_t rs1, uint32_t rs2, uint32_t imm)
{
    प्रतिज्ञा(! नीचः_अतिप्रवाहः(imm));
    o(opcode | (func3 << 12) | ((imm & 0x1f) << 7) | (rs1 << 15)
      | (rs2 << 20) | ((imm >> 5) << 25));
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC शून्य gsym_addr(पूर्णाङ्क t_, पूर्णाङ्क a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    यावत् (t) {
        अचिह्नित वर्ण *ptr = cur_text_section->दत्त + t;
        uint32_t अग्र = read32le(ptr);
        uint32_t r = a - t, imm;
        यदि ((r + (1 << 21)) & ~((1U << 22) - 2))
          tcc_error("out-of-range branch chain");
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        write32le(ptr, r == 4 ? 0x33 : 0x6f | imm); // nop || j imm
        t = अग्र;
    }
}

स्थिर पूर्णाङ्क आरोपय_symofs(पूर्णाङ्क r, SValue *sv, पूर्णाङ्क forstore, पूर्णाङ्क *new_fc)
{
    पूर्णाङ्क rr, doload = 0, large_addend = 0;
    पूर्णाङ्क fc = sv->c.i, v = sv->r & VT_VALMASK;
    यदि (sv->r & VT_SYM) {
        Sym label = {0};
        प्रतिज्ञा(v == VT_CONST);
        यदि (sv->sym->type.t & VT_TLS) {
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
            प्रत्यागम rr;
        }
        यदि (sv->sym->type.t & VT_STATIC) { // XXX do this per linker relax
            greloca(cur_text_section, sv->sym, ind,
                    R_RISCV_PCREL_HI20, sv->c.i);
            *new_fc = 0;
        } अन्यथा {
            यदि (नीचः_अतिप्रवाहः(fc)){
              large_addend = 1;
            }
            greloca(cur_text_section, sv->sym, ind,
                    R_RISCV_GOT_HI20, 0);
            doload = 1;
        }
        label.type.t = VT_VOID | VT_STATIC;
	यदि (!nocode_wanted)
            put_extern_sym(&label, cur_text_section, ind, 0);
        rr = is_ireg(r) ? ireg(r) : 5;
        o(0x17 | (rr << 7));   // auipc RR, 0 %pcrel_hi(sym)+addend
        greloca(cur_text_section, &label, ind,
                doload || !forstore
                  ? R_RISCV_PCREL_LO12_I : R_RISCV_PCREL_LO12_S, 0);
        यदि (doload) {
            EI(0x03, 3, rr, rr, 0); // ld RR, 0(RR)
            यदि (large_addend) {
                o(0x37 | (6 << 7) | ऊर्ध्वस्थम्_2(fc)); //lui t1, high(fc)
                ER(0x33, 0, rr, rr, 6, 0); // add RR, RR, t1
                *new_fc = SIGN11(fc);
            }
        }
    } अन्यथा यदि (v == VT_LOCAL || v == VT_LLOCAL) {
        rr = 8; // s0
        यदि (fc != sv->c.i)
          tcc_error("unimp: store(giant local off) (0x%lx)", (दीर्घ)sv->c.i);
        यदि (नीचः_अतिप्रवाहः(fc)) {
            rr = is_ireg(r) ? ireg(r) : 5; // t0
            o(0x37 | (rr << 7) | ऊर्ध्वस्थम्_2(fc)); //lui RR, upper(fc)
            ER(0x33, 0, rr, rr, 8, 0); // add RR, RR, s0
            *new_fc = SIGN11(fc);
        }
    } अन्यथा
      tcc_error("uhh");
    प्रत्यागम rr;
}

स्थिर शून्य आरोपय_large_constant(पूर्णाङ्क rr, पूर्णाङ्क fc, uint32_t pi)
{
    यदि (fc < 0)
	pi++;
    o(0x37 | (rr << 7) | ऊर्ध्वस्थम्_2(pi)); // lui RR, up(up(fc))
    EI(0x13, 0, rr, rr, SIGN11(pi));   // addi RR, RR, lo(up(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((अचिह्नित)fc + (1 << 19)) >> 20)); // addi RR, RR, up(lo(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((अचिह्नित)fc + (1 << 7)) >> 8));  // addi RR, RR, lo1(lo(fc))
    EI(0x13, 1, rr, rr, 8); // slli RR, RR, 8
}

ST_FUNC शून्य आरोपय(पूर्णाङ्क r, SValue *sv)
{
    पूर्णाङ्क fr = sv->r;
    पूर्णाङ्क v = fr & VT_VALMASK;
    पूर्णाङ्क rr = is_ireg(r) ? ireg(r) : freg(r);
    पूर्णाङ्क fc = sv->c.i;
    पूर्णाङ्क bt = sv->type.t & VT_BTYPE;
    पूर्णाङ्क align, आकार;
    यदि (fr & VT_LVAL) {
        पूर्णाङ्क func3, opcode = is_freg(r) ? 0x07 : 0x03, br;
        आकार = type_आकार(&sv->type, &align);
        प्रतिज्ञा (!is_freg(r) || bt == VT_FLOAT || bt == VT_DOUBLE);
        यदि (bt == VT_PTR || bt == VT_FUNC) /* XXX should be done in generic code */
          आकार = PTR_आकार;
        func3 = आकार == 1 ? 0 : आकार == 2 ? 1 : आकार == 4 ? 2 : 3;
        यदि (आकार < 4 && !is_float(sv->type.t) && (sv->type.t & VT_UNSIGNED))
          func3 |= 4;
        यदि (v == VT_LOCAL || (fr & VT_SYM)) {
            br = आरोपय_symofs(r, sv, 0, &fc);
        } अन्यथा यदि (v < VT_CONST) {
            br = ireg(v);
            /*if (LOW_OVERFLOW(fc))
              tcc_error("unimp: load(large addend) (0x%x)", fc);*/
            fc = 0; // XXX store ofs in LVAL(reg)
        } अन्यथा यदि (v == VT_LLOCAL) {
            br = आरोपय_symofs(r, sv, 0, &fc);
            EI(0x03, 3, rr, br, fc); // ld RR, fc(BR)
            br = rr;
            fc = 0;
        } अन्यथा यदि (v == VT_CONST) {
            int64_t si = sv->c.i;
            si >>= 32;
            यदि (si != 0) {
		आरोपय_large_constant(rr, fc, si);
                fc = SIGN7(fc);
            } अन्यथा {
                o(0x37 | (rr << 7) | ऊर्ध्वस्थम्_2(fc)); //lui RR, upper(fc)
                fc = SIGN11(fc);
	    }
            br = rr;
	} अन्यथा {
            tcc_error("unimp: load(non-local lval)");
        }
        EI(opcode, func3, rr, br, fc); // l[bhwd][u] / fl[wd] RR, fc(BR)
    } अन्यथा यदि (v == VT_CONST) {
        पूर्णाङ्क rb = 0, do32bit = 8, zext = 0;
        यदि (is_float(sv->type.t) && bt != VT_LDOUBLE) {
            /* load float/double constant: move bit pattern from int reg */
            uint64_t val = sv->c.i;
            पूर्णाङ्क is_dbl = bt == VT_DOUBLE;
            यदि (val == 0) {
                o(0x53 | (rr << 7) | ((अचिह्नित)(0x78 | is_dbl) << 25));
                प्रत्यागम;
            }
            यदि (is_dbl) {
                आरोपय_large_constant(6, (पूर्णाङ्क)val, (पूर्णाङ्क)(val >> 32));
            } अन्यथा {
                यदि (नीचः_अतिप्रवाहः(fc))
                    o(0x37 | (6 << 7) | ऊर्ध्वस्थम्_2(fc)); // lui t1, upper
                EI(0x13 | 8, 0, 6, नीचः_अतिप्रवाहः(fc) ? 6 : 0, SIGN11(fc)); // addiw t1,...
            }
            o(0x53 | (rr << 7) | (6 << 15) | ((अचिह्नित)(0x78 | is_dbl) << 25));
            प्रत्यागम;
        }
        प्रतिज्ञा(is_ireg(r) || bt == VT_LDOUBLE);
        यदि (fr & VT_SYM) {
            rb = आरोपय_symofs(r, sv, 0, &fc);
            do32bit = 0;
        }
        यदि (do32bit && fc != sv->c.i) {
            int64_t si = sv->c.i;
            si >>= 32;
            यदि (si != 0) {
		आरोपय_large_constant(rr, fc, si);
                fc = SIGN7(fc);
                rb = rr;
                do32bit = 0;
            } अन्यथा यदि (bt == VT_LLONG) {
                /* A 32bit unsigned constant for a 64bit type.
                   lui always sign extends, so we need to do an explicit zext.*/
                zext = 1;
            }
        }
        यदि (नीचः_अतिप्रवाहः(fc))
            o(0x37 | (rr << 7) | ऊर्ध्वस्थम्_2(fc)), rb = rr; //lui RR, upper(fc)
        यदि (fc || (rr != rb) || do32bit || (fr & VT_SYM))
          EI(0x13 | do32bit, 0, rr, rb, SIGN11(fc)); // addi[w] R, x0|R, FC
        यदि (zext) {
            EI(0x13, 1, rr, rr, 32); // slli RR, RR, 32
            EI(0x13, 5, rr, rr, 32); // srli RR, RR, 32
        }
    } अन्यथा यदि (v == VT_LOCAL) {
        पूर्णाङ्क br = आरोपय_symofs(r, sv, 0, &fc);
        प्रतिज्ञा(is_ireg(r));
        EI(0x13, 0, rr, br, fc); // addi R, s0, FC
    } अन्यथा यदि (v < VT_CONST) { /* reg-reg */
        //assert(!fc); XXX support offseted regs
        यदि (is_freg(r) && is_freg(v))
          ER(0x53, 0, rr, freg(v), freg(v), bt == VT_DOUBLE ? 0x11 : 0x10); //fsgnj.[sd] RR, V, V == fmv.[sd] RR, V
        अन्यथा यदि (is_ireg(r) && is_ireg(v))
          EI(0x13, 0, rr, ireg(v), 0); // addi RR, V, 0 == mv RR, V
        अन्यथा {
            पूर्णाङ्क func7 = is_ireg(r) ? 0x70 : 0x78;
            आकार = type_आकार(&sv->type, &align);
            यदि (आकार == 8)
              func7 |= 1;
            प्रतिज्ञा(आकार == 4 || आकार == 8);
            o(0x53 | (rr << 7) | ((is_freg(v) ? freg(v) : ireg(v)) << 15)
              | ((अचिह्नित)func7 << 25)); // fmv.{w.x, x.w, d.x, x.d} RR, VR
        }
    } अन्यथा यदि (v == VT_CMP) {
        पूर्णाङ्क op = vtop->cmp_op;
        पूर्णाङ्क a = vtop->cmp_r & 0xff;
        पूर्णाङ्क b = (vtop->cmp_r >> 8) & 0xff;
        पूर्णाङ्क inv = 0;
        विकल्प (op) {
            पक्ष TOK_ULT:
            पक्ष TOK_UGE:
            पक्ष TOK_ULE:
            पक्ष TOK_UGT:
            पक्ष TOK_LT:
            पक्ष TOK_GE:
            पक्ष TOK_LE:
            पक्ष TOK_GT:
                यदि (op & 1) { // remove [U]GE,GT
                    inv = 1;
                    op--;
                }
                यदि ((op & 7) == 6) { // [U]LE
                    पूर्णाङ्क t = a; a = b; b = t;
                    inv ^= 1;
                }
                ER(0x33, (op > TOK_UGT) ? 2 : 3, rr, a, b, 0); // slt[u] d, a, b
                यदि (inv)
                  EI(0x13, 4, rr, rr, 1); // xori d, d, 1
                भङ्ग;
            पक्ष TOK_NE:
            पक्ष TOK_EQ:
                यदि (rr != a || b)
                  ER(0x33, 0, rr, a, b, 0x20); // sub d, a, b
                यदि (op == TOK_NE)
                  ER(0x33, 3, rr, 0, rr, 0); // sltu d, x0, d == snez d,d
                अन्यथा
                  EI(0x13, 3, rr, rr, 1); // sltiu d, d, 1 == seqz d,d
                भङ्ग;
        }
    } अन्यथा यदि ((v & ~1) == VT_JMP) {
        पूर्णाङ्क t = v & 1;
        प्रतिज्ञा(is_ireg(r));
        EI(0x13, 0, rr, 0, t);      // addi RR, x0, t
        gjmp_addr(ind + 8);
        gsym(fc);
        EI(0x13, 0, rr, 0, t ^ 1);  // addi RR, x0, !t
    } अन्यथा
      tcc_error("unimp: load(non-const)");
}

ST_FUNC शून्य store(पूर्णाङ्क r, SValue *sv)
{
    पूर्णाङ्क fr = sv->r & VT_VALMASK;
    पूर्णाङ्क rr = is_ireg(r) ? ireg(r) : freg(r), ptrreg;
    पूर्णाङ्क fc = sv->c.i;
    पूर्णाङ्क bt = sv->type.t & VT_BTYPE;
    पूर्णाङ्क align, आकार = type_आकार(&sv->type, &align);
    प्रतिज्ञा(!is_float(bt) || is_freg(r) || bt == VT_LDOUBLE);
    /* long doubles are in two integer registers, but the load/store
       primitives only deal with one, so do as if it's one reg.  */
    यदि (bt == VT_LDOUBLE)
      आकार = align = 8;
    यदि (bt == VT_STRUCT)
      tcc_error("unimp: store(struct)");
    यदि (आकार > 8)
      tcc_error("unimp: large sized store");
    प्रतिज्ञा(sv->r & VT_LVAL);
    यदि (fr == VT_LOCAL || (sv->r & VT_SYM)) {
        ptrreg = आरोपय_symofs(-1, sv, 1, &fc);
    } अन्यथा यदि (fr < VT_CONST) {
        ptrreg = ireg(fr);
        /*if (LOW_OVERFLOW(fc))
          tcc_error("unimp: store(large addend) (0x%x)", fc);*/
        fc = 0; // XXX support offsets regs
    } अन्यथा यदि (fr == VT_CONST) {
        int64_t si = sv->c.i;
        ptrreg = 8; // s0
        si >>= 32;
        यदि (si != 0) {
	    आरोपय_large_constant(ptrreg, fc, si);
            fc = SIGN7(fc);
        } अन्यथा {
            o(0x37 | (ptrreg << 7) | ऊर्ध्वस्थम्_2(fc)); //lui RR, upper(fc)
            fc = SIGN11(fc);
	}
    } अन्यथा
      tcc_error("implement me: %s(!local)", __FUNCTION__);
    ES(is_freg(r) ? 0x27 : 0x23,                          // fs... | s...
       आकार == 1 ? 0 : आकार == 2 ? 1 : आकार == 4 ? 2 : 3, // ... [wd] | [bhwd]
       ptrreg, rr, fc);                                   // RR, fc(base)
}

स्थिर शून्य gcall_or_jmp(पूर्णाङ्क docall)
{
    पूर्णाङ्क tr = docall ? 1 : 5; // ra or t0
    यदि ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
        ((vtop->r & VT_SYM) && vtop->c.i == (पूर्णाङ्क)vtop->c.i)) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind,
                R_RISCV_CALL_PLT, (पूर्णाङ्क)vtop->c.i);
        o(0x17 | (tr << 7));   // auipc TR, 0 %call(func)
        EI(0x67, 0, tr, tr, 0);// jalr  TR, r(TR)
    } अन्यथा यदि (vtop->r < VT_CONST) {
        पूर्णाङ्क r = ireg(vtop->r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    } अन्यथा {
        पूर्णाङ्क r = TREG_RA;
        आरोपय(r, vtop);
        r = ireg(r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    }
}

#यदि defined(CONFIG_TCC_BCHECK)

स्थिर शून्य gen_bounds_call(पूर्णाङ्क v)
{
    Sym *sym = external_helper_sym(v);

    greloca(cur_text_section, sym, ind, R_RISCV_CALL_PLT, 0);
    o(0x17 | (1 << 7));   // auipc TR, 0 %call(func)
    EI(0x67, 0, 1, 1, 0); // jalr  TR, r(TR)
}

स्थिर शून्य gen_bounds_prolog(शून्य)
{
    /* leave some room for bound checking code */
    func_bound_विस्थापनम् = lbounds_section->दत्त_विस्थापनम्;
    func_bound_ind = ind;
    func_bound_सङ्कलय_epilog = 0;
    o(0x00000013);  /* ld a0,#lbound section pointer */
    o(0x00000013);
    o(0x00000013);  /* nop -> call __bound_local_new */
    o(0x00000013);
}

स्थिर शून्य gen_bounds_epilog(शून्य)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_दत्त;
    Sym label = {0};

    पूर्णाङ्क विस्थापनम्_modified = func_bound_विस्थापनम् != lbounds_section->दत्त_विस्थापनम्;

    यदि (!विस्थापनम्_modified && !func_bound_सङ्कलय_epilog)
        प्रत्यागम;

    /* add end of table info */
    bounds_ptr = section_ptr_सङ्कलय(lbounds_section, परिमाण(addr_t));
    *bounds_ptr = 0;

    sym_दत्त = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_विस्थापनम्, PTR_आकार);

    label.type.t = VT_VOID | VT_STATIC;
    /* generate bound local allocation */
    यदि (विस्थापनम्_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        put_extern_sym(&label, cur_text_section, ind, 0);
        greloca(cur_text_section, sym_दत्त, ind, R_RISCV_GOT_HI20, 0);
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
    greloca(cur_text_section, sym_दत्त, ind, R_RISCV_GOT_HI20, 0);
    o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
    greloca(cur_text_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
    gen_bounds_call(TOK___bound_local_delete);
    o(0x65a26502); /* ld   a0,0(sp)   ld   a1,8(sp)   */
    o(0x61052542); /* fld  fa0,16(sp) addi sp,sp,32   */
}
#यदि_अन्तः

स्थिर शून्य reg_pass_rec(CType *type, पूर्णाङ्क *rc, पूर्णाङ्क *fieldofs, पूर्णाङ्क ofs)
{
    यदि ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *f;
        यदि (type->ref->type.t == VT_UNION)
          rc[0] = -1;
        अन्यथा प्रति (f = type->ref->अग्र; f; f = f->अग्र)
          reg_pass_rec(&f->type, rc, fieldofs, ofs + f->c);
    } अन्यथा यदि (type->t & VT_ARRAY) {
        यदि (type->ref->c < 0 || type->ref->c > 2)
          rc[0] = -1;
        अन्यथा {
            पूर्णाङ्क a, sz = type_आकार(&type->ref->type, &a);
            reg_pass_rec(&type->ref->type, rc, fieldofs, ofs);
            यदि (rc[0] > 2 || (rc[0] == 2 && type->ref->c > 1))
              rc[0] = -1;
            अन्यथा यदि (type->ref->c == 2 && rc[0] && rc[1] == RC_FLOAT) {
              rc[++rc[0]] = RC_FLOAT;
              fieldofs[rc[0]] = ((ofs + sz) << 4)
                                | (type->ref->type.t & VT_BTYPE);
            } अन्यथा यदि (type->ref->c == 2)
              rc[0] = -1;
        }
    } अन्यथा यदि (rc[0] == 2 || rc[0] < 0 || (type->t & VT_BTYPE) == VT_LDOUBLE)
      rc[0] = -1;
    अन्यथा यदि (!rc[0] || rc[1] == RC_FLOAT || is_float(type->t)) {
      rc[++rc[0]] = is_float(type->t) ? RC_FLOAT : RC_INT;
      fieldofs[rc[0]] = (ofs << 4) | ((type->t & VT_BTYPE) == VT_PTR ? VT_LLONG : type->t & VT_BTYPE);
    } अन्यथा
      rc[0] = -1;
}

स्थिर शून्य reg_pass(CType *type, पूर्णाङ्क *prc, पूर्णाङ्क *fieldofs, पूर्णाङ्क named)
{
    prc[0] = 0;
    reg_pass_rec(type, prc, fieldofs, 0);
    यदि (prc[0] <= 0 || !named) {
        पूर्णाङ्क align, आकार = type_आकार(type, &align);
        prc[0] = (आकार + 7) >> 3;
        prc[1] = prc[2] = RC_INT;
        fieldofs[1] = (0 << 4) | (आकार <= 1 ? VT_BYTE : आकार <= 2 ? VT_SHORT : आकार <= 4 ? VT_INT : VT_LLONG);
        fieldofs[2] = (8 << 4) | (आकार <= 9 ? VT_BYTE : आकार <= 10 ? VT_SHORT : आकार <= 12 ? VT_INT : VT_LLONG);
    }
}

ST_FUNC शून्य gfunc_call(पूर्णाङ्क nb_तर्काः)
{
    पूर्णाङ्क i, align, आकार, areg[2];
    पूर्णाङ्क *info = tcc_malloc((nb_तर्काः + 1) * परिमाण (पूर्णाङ्क));
    पूर्णाङ्क राशिः_adj = 0, tempspace = 0, राशिः_सङ्कलय, ofs, splitofs = 0;
    पूर्णाङ्क old = (vtop[-nb_तर्काः].type.ref->f.func_type == FUNC_OLD);
    SValue *sv;
    Sym *sa;

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    पूर्णाङ्क bc_save = tcc_state->do_bounds_check;
    यदि (tcc_state->do_bounds_check)
        gbound_तर्काः(nb_तर्काः);
#यदि_अन्तः

    areg[0] = 0; /* int arg regs */
    areg[1] = 8; /* float arg regs */
    sa = vtop[-nb_तर्काः].type.ref->अग्र;
    प्रति (i = 0; i < nb_तर्काः; i++) {
        पूर्णाङ्क nregs, byref = 0, tempofs;
        पूर्णाङ्क prc[3], fieldofs[3];
        sv = &vtop[1 + i - nb_तर्काः];
        sv->type.t &= ~VT_ARRAY; // XXX this should be done in tccgen.c
        आकार = type_आकार(&sv->type, &align);
        यदि (आकार > 16) {
            यदि (align < XLEN)
              align = XLEN;
            tempspace = (tempspace + align - 1) & -align;
            tempofs = tempspace;
            tempspace += आकार;
            आकार = align = 8;
            byref = 64 | (tempofs << 7);
        }
        reg_pass(&sv->type, prc, fieldofs, old || sa != 0);
        यदि (!old && !sa && align == 2*XLEN && आकार <= 2*XLEN)
          areg[0] = (areg[0] + 1) & ~1;
        nregs = prc[0];
        यदि (आकार == 0)
            info[i] = 0;
        अन्यथा यदि ((prc[1] == RC_INT && areg[0] >= 8)
            || (prc[1] == RC_FLOAT && areg[1] >= 16)
            || (nregs == 2 && prc[1] == RC_FLOAT && prc[2] == RC_FLOAT
                && areg[1] >= 15)
            || (nregs == 2 && prc[1] != prc[2]
                && (areg[1] >= 16 || areg[0] >= 8))) {
            info[i] = 32;
            यदि (align < XLEN)
              align = XLEN;
            राशिः_adj += (आकार + align - 1) & -align;
            यदि (!old && !sa) /* one vararg on stack forces the rest on stack */
              areg[0] = 8, areg[1] = 16;
        } अन्यथा {
            info[i] = areg[prc[1] - 1]++;
            यदि (!byref)
              info[i] |= (fieldofs[1] & VT_BTYPE) << 12;
            प्रतिज्ञा(!(fieldofs[1] >> 4));
            यदि (nregs == 2) {
                यदि (prc[2] == RC_FLOAT || areg[0] < 8)
                  info[i] |= (1 + areg[prc[2] - 1]++) << 7;
                अन्यथा {
                    info[i] |= 16;
                    राशिः_adj += 8;
                }
                यदि (!byref) {
                    प्रतिज्ञा((fieldofs[2] >> 4) < 2048);
                    info[i] |= fieldofs[2] << (12 + 4); // includes offset
                }
            }
        }
        info[i] |= byref;
        यदि (sa)
          sa = sa->अग्र;
    }
    राशिः_adj = (राशिः_adj + 15) & -16;
    tempspace = (tempspace + 15) & -16;
    राशिः_सङ्कलय = राशिः_adj + tempspace;

    यदि (राशिः_सङ्कलय) {
        यदि (राशिः_सङ्कलय >= 0x800) {
            o(0x37 | (5 << 7) | ऊर्ध्वस्थम्_2(-राशिः_सङ्कलय)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(-राशिः_सङ्कलय)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        अन्यथा
            EI(0x13, 0, 2, 2, -राशिः_सङ्कलय);   // addi sp, sp, -adj
        प्रति (i = ofs = 0; i < nb_तर्काः; i++) {
            यदि (info[i] & (64 | 32)) {
                vrotb(nb_तर्काः - i);
                आकार = type_आकार(&vtop->type, &align);
                यदि (info[i] & 64) {
                    vset(&char_pointer_type, TREG_SP, 0);
                    vpushi(राशिः_adj + (info[i] >> 7));
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
                यदि (info[i] & 32) {
                    यदि (align < XLEN)
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
                vrott(nb_तर्काः - i);
            } अन्यथा यदि (info[i] & 16) {
                प्रतिज्ञा(!splitofs);
                splitofs = ofs;
                ofs += 8;
            }
        }
    }
    प्रति (i = 0; i < nb_तर्काः; i++) {
        पूर्णाङ्क ii = info[nb_तर्काः - 1 - i], r = ii, r2 = r;
        यदि (!(r & 32)) {
            CType origtype;
            पूर्णाङ्क loadt;
            r &= 15;
            r2 = r2 & 64 ? 0 : (r2 >> 7) & 31;
            प्रतिज्ञा(r2 <= 16);
            vrotb(i+1);
            origtype = vtop->type;
            आकार = type_आकार(&vtop->type, &align);
            यदि (आकार == 0)
                गच्छ समाप्तम्;
            loadt = vtop->type.t & VT_BTYPE;
            यदि (loadt == VT_STRUCT) {
                loadt = (ii >> 12) & VT_BTYPE;
            }
            यदि (info[nb_तर्काः - 1 - i] & 16) {
                प्रतिज्ञा(!r2);
                r2 = 1 + TREG_RA;
            }
            यदि (loadt == VT_LDOUBLE) {
                प्रतिज्ञा(r2);
                r2--;
            } अन्यथा यदि (r2) {
                test_lvalue();
                vpushv(vtop);
            }
            vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
            gv(r < 8 ? RC_R(r) : RC_F(r - 8));
            vtop->type = origtype;

            यदि (r2 && loadt != VT_LDOUBLE) {
                r2--;
                प्रतिज्ञा(r2 < 16 || r2 == TREG_RA);
                vswap();
                gaddrof();
                vtop->type = char_pointer_type;
                vpushi(ii >> 20);
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
		यदि ((origtype.t & VT_BTYPE) == VT_STRUCT)
                    tcc_state->do_bounds_check = 0;
#यदि_अन्तः
                gen_op('+');
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
		tcc_state->do_bounds_check = bc_save;
#यदि_अन्तः
                indir();
                vtop->type = origtype;
                loadt = vtop->type.t & VT_BTYPE;
                यदि (loadt == VT_STRUCT) {
                    loadt = (ii >> 16) & VT_BTYPE;
                }
                save_reg_upstack(r2, 1);
                vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
                आरोपय(r2, vtop);
                प्रतिज्ञा(r2 < VT_CONST);
                vtop--;
                vtop->r2 = r2;
            }
            यदि (info[nb_तर्काः - 1 - i] & 16) {
                ES(0x23, 3, 2, ireg(vtop->r2), splitofs); // sd t0, ofs(sp)
                vtop->r2 = VT_CONST;
            } अन्यथा यदि (loadt == VT_LDOUBLE && vtop->r2 != r2) {
                प्रतिज्ञा(vtop->r2 <= 7 && r2 <= 7);
                /* XXX we'd like to have 'gv' move directly into
                   the right class instead of us fixing it up.  */
                EI(0x13, 0, ireg(r2), ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = r2;
            }
समाप्तम्:
            vrott(i+1);
        }
    }
    vrotb(nb_तर्काः + 1);
    save_regs(nb_तर्काः + 1);
    gcall_or_jmp(1);
    vtop -= nb_तर्काः + 1;
    यदि (राशिः_सङ्कलय) {
        यदि (राशिः_सङ्कलय >= 0x800) {
            o(0x37 | (5 << 7) | ऊर्ध्वस्थम्_2(राशिः_सङ्कलय)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(राशिः_सङ्कलय)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        अन्यथा
            EI(0x13, 0, 2, 2, राशिः_सङ्कलय);      // addi sp, sp, adj
   }
   tcc_free(info);
}

स्थिर पूर्णाङ्क func_sub_sp_विस्थापनम्, अङ्कः_va_regs, func_va_list_ofs;

ST_FUNC शून्य gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    पूर्णाङ्क i, addr, align, आकार;
    पूर्णाङ्क param_addr = 0;
    पूर्णाङ्क areg[2];
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    loc = -16; // for ra and s0
    func_sub_sp_विस्थापनम् = ind;
    ind += 5 * 4;

    areg[0] = 0, areg[1] = 0;
    addr = 0;
    /* if the function returns by reference, then add an
       implicit pointer parameter */
    आकार = type_आकार(&func_vt, &align);
    यदि (आकार > 2 * XLEN) {
        loc -= 8;
        func_vc = loc;
        ES(0x23, 3, 8, 10 + areg[0]++, loc); // sd a0, loc(s0)
    }
    /* define parameters */
    यावत् ((sym = sym->अग्र) != रिक्त) {
        पूर्णाङ्क byref = 0;
        पूर्णाङ्क regcount;
        पूर्णाङ्क prc[3], fieldofs[3];
        type = &sym->type;
        आकार = type_आकार(type, &align);
        यदि (आकार > 2 * XLEN) {
            type = &char_pointer_type;
            आकार = align = byref = 8;
        }
        reg_pass(type, prc, fieldofs, 1);
        regcount = prc[0];
        यदि (areg[prc[1] - 1] >= 8
            || (regcount == 2
                && ((prc[1] == RC_FLOAT && prc[2] == RC_FLOAT && areg[1] >= 7)
                    || (prc[1] != prc[2] && (areg[1] >= 8 || areg[0] >= 8))))) {
            यदि (align < XLEN)
              align = XLEN;
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += आकार;
        } अन्यथा {
            loc -= regcount * 8; // XXX could reserve only 'size' bytes
            param_addr = loc;
            प्रति (i = 0; i < regcount; i++) {
                यदि (areg[prc[1+i] - 1] >= 8) {
                    प्रतिज्ञा(i == 1 && regcount == 2 && !(addr & 7));
                    EI(0x03, 3, 5, 8, addr); // ld t0, addr(s0)
                    addr += 8;
                    ES(0x23, 3, 8, 5, loc + i*8); // sd t0, loc(s0)
                } अन्यथा यदि (prc[1+i] == RC_FLOAT) {
                    ES(0x27, (आकार / regcount) == 4 ? 2 : 3, 8, 10 + areg[1]++, loc + (fieldofs[i+1] >> 4)); // fs[wd] FAi, loc(s0)
                } अन्यथा {
                    ES(0x23, 3, 8, 10 + areg[0]++, loc + i*8); // sd aX, loc(s0) // XXX
                }
            }
        }
        gfunc_समुच्चयः_param(sym, param_addr, byref);
    }
    func_va_list_ofs = addr;
    अङ्कः_va_regs = 0;
    यदि (func_var) {
        प्रति (; areg[0] < 8; areg[0]++) {
            अङ्कः_va_regs++;
            ES(0x23, 3, 8, 10 + areg[0], -8 + अङ्कः_va_regs * 8); // sd aX, loc(s0)
        }
    }
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    यदि (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#यदि_अन्तः
}

ST_FUNC पूर्णाङ्क gfunc_sret(CType *vt, पूर्णाङ्क variadic, CType *ret,
                       पूर्णाङ्क *ret_align, पूर्णाङ्क *regsize)
{
    पूर्णाङ्क align, आकार = type_आकार(vt, &align), nregs;
    पूर्णाङ्क prc[3], fieldofs[3];
    *ret_align = 1;
    *regsize = 8;
    यदि (आकार > 16)
      प्रत्यागम 0;
    reg_pass(vt, prc, fieldofs, 1);
    nregs = prc[0];
    यदि (nregs == 2 && prc[1] != prc[2])
      प्रत्यागम -1;  /* generic code can't deal with this case */
    यदि (prc[1] == RC_FLOAT) {
        *regsize = आकार / nregs;
    }
    ret->t = fieldofs[1] & VT_BTYPE;
    ret->ref = रिक्त;
    प्रत्यागम nregs;
}

ST_FUNC शून्य arch_transfer_ret_regs(पूर्णाङ्क aftercall)
{
    पूर्णाङ्क prc[3], fieldofs[3];
    reg_pass(&vtop->type, prc, fieldofs, 1);
    प्रतिज्ञा(prc[0] == 2 && prc[1] != prc[2] && !(fieldofs[1] >> 4));
    प्रतिज्ञा(vtop->r == (VT_LOCAL | VT_LVAL));
    vpushv(vtop);
    vtop->type.t = fieldofs[1] & VT_BTYPE;
    (aftercall ? store : आरोपय)(prc[1] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop->c.i += fieldofs[2] >> 4;
    vtop->type.t = fieldofs[2] & VT_BTYPE;
    (aftercall ? store : आरोपय)(prc[2] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop--;
}

ST_FUNC शून्य gfunc_epilog(शून्य)
{
    पूर्णाङ्क v, saved_ind, d, large_ofs_ind;

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    यदि (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#यदि_अन्तः

    loc = (loc - अङ्कः_va_regs * 8);
    d = v = (-loc + 15) & -16;

    EI(0x13, 0, 2, 8, अङ्कः_va_regs * 8); // addi sp, s0, num_va_regs*8
    EI(0x03, 3, 1, 8, -8); // ld ra, -8(s0)
    EI(0x03, 3, 8, 8, -16); // ld s0, -16(s0)
    EI(0x67, 0, 0, 1, 0); // jalr x0, 0(x1), aka ret

    large_ofs_ind = ind;
    यदि (v >= (1 << 11)) {
        d = 16;
        EI(0x13, 0, 8, 2, d - अङ्कः_va_regs * 8);      // addi s0, sp, d
        o(0x37 | (5 << 7) | ऊर्ध्वस्थम्_2(v-16)); //lui t0, upper(v)
        EI(0x13, 0, 5, 5, SIGN11(v-16)); // addi t0, t0, lo(v)
        ER(0x33, 0, 2, 2, 5, 0x20); // sub sp, sp, t0
        gjmp_addr(func_sub_sp_विस्थापनम् + 5*4);
    }
    saved_ind = ind;

    ind = func_sub_sp_विस्थापनम्;
    EI(0x13, 0, 2, 2, -d);     // addi sp, sp, -d
    ES(0x23, 3, 2, 1, d - 8 - अङ्कः_va_regs * 8);  // sd ra, d-8(sp)
    ES(0x23, 3, 2, 8, d - 16 - अङ्कः_va_regs * 8); // sd s0, d-16(sp)
    यदि (v < (1 << 11))
      EI(0x13, 0, 8, 2, d - अङ्कः_va_regs * 8);      // addi s0, sp, d
    अन्यथा
      gjmp_addr(large_ofs_ind);
    यदि ((ind - func_sub_sp_विस्थापनम्) != 5*4)
      EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
    ind = saved_ind;
}

ST_FUNC शून्य gen_va_start(शून्य)
{
    vtop--;
    vset(&char_pointer_type, VT_LOCAL, func_va_list_ofs);
}

ST_FUNC शून्य gen_fill_nops(पूर्णाङ्क अष्टकानि)
{
    यदि ((अष्टकानि & 3))
      tcc_error("alignment of code section not multiple of 4");
    यावत् (अष्टकानि > 0) {
        EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
        अष्टकानि -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC पूर्णाङ्क gjmp(पूर्णाङ्क t)
{
    यदि (nocode_wanted)
      प्रत्यागम t;
    o(t);
    प्रत्यागम ind - 4;
}

// Generate branch to known address:
ST_FUNC शून्य gjmp_addr(पूर्णाङ्क a)
{
    uint32_t r = a - ind, imm;
    यदि ((r + (1 << 21)) & ~((1U << 22) - 2)) {
        o(0x17 | (5 << 7) | ऊर्ध्वस्थम्_2(r)); // lui RR, up(r)
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

ST_FUNC पूर्णाङ्क gjmp_cond(पूर्णाङ्क op, पूर्णाङ्क t)
{
    पूर्णाङ्क tmp;
    पूर्णाङ्क a = vtop->cmp_r & 0xff;
    पूर्णाङ्क b = (vtop->cmp_r >> 8) & 0xff;
    विकल्प (op) {
        पक्ष TOK_ULT: op = 6; भङ्ग;
        पक्ष TOK_UGE: op = 7; भङ्ग;
        पक्ष TOK_ULE: op = 7; tmp = a; a = b; b = tmp; भङ्ग;
        पक्ष TOK_UGT: op = 6; tmp = a; a = b; b = tmp; भङ्ग;
        पक्ष TOK_LT:  op = 4; भङ्ग;
        पक्ष TOK_GE:  op = 5; भङ्ग;
        पक्ष TOK_LE:  op = 5; tmp = a; a = b; b = tmp; भङ्ग;
        पक्ष TOK_GT:  op = 4; tmp = a; a = b; b = tmp; भङ्ग;
        पक्ष TOK_NE:  op = 1; भङ्ग;
        पक्ष TOK_EQ:  op = 0; भङ्ग;
    }
    o(0x63 | (op ^ 1) << 12 | a << 15 | b << 20 | 8 << 7); // bOP a,b,+4
    प्रत्यागम gjmp(t);
}

ST_FUNC पूर्णाङ्क gjmp_append(पूर्णाङ्क n, पूर्णाङ्क t)
{
    शून्य *p;
    /* insert jump list n into t */
    यदि (n) {
        uint32_t n1 = n, n2;
        यावत् ((n2 = read32le(p = cur_text_section->दत्त + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    प्रत्यागम t;
}

स्थिर शून्य gen_opil(पूर्णाङ्क op, पूर्णाङ्क ll)
{
    पूर्णाङ्क a, b, d;
    पूर्णाङ्क func3 = 0;
    ll = ll ? 0 : 8;
    यदि ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
        पूर्णाङ्क fc = vtop->c.i;
        यदि (fc == vtop->c.i && !नीचः_अतिप्रवाहः(fc)) {
            पूर्णाङ्क cll = 0;
            पूर्णाङ्क m = ll ? 31 : 63;
            vswap();
            gv(RC_INT);
            a = ireg(vtop[0].r);
            --vtop;
            d = get_reg(RC_INT);
            ++vtop;
            vswap();
            विकल्प (op) {
                पक्ष '-':
                    यदि (fc <= -(1 << 11))
                      भङ्ग;
                    fc = -fc;
                पक्ष '+':
                    func3 = 0; // addi d, a, fc
                    cll = ll;
                do_cop:
                    EI(0x13 | cll, func3, ireg(d), a, fc);
                    --vtop;
                    यदि (op >= TOK_ULT && op <= TOK_GT) {
                      vset_VT_CMP(TOK_NE);
                      vtop->cmp_r = ireg(d) | 0 << 8;
                    } अन्यथा
                      vtop[0].r = d;
                    प्रत्यागम;
                पक्ष TOK_LE:
                    यदि (fc >= (1 << 11) - 1)
                      भङ्ग;
                    ++fc;
                पक्ष TOK_LT:  func3 = 2; गच्छ do_cop; // slti d, a, fc
                पक्ष TOK_ULE:
                    यदि (fc >= (1 << 11) - 1 || fc == -1)
                      भङ्ग;
                    ++fc;
                पक्ष TOK_ULT: func3 = 3; गच्छ do_cop; // sltiu d, a, fc
                पक्ष '^':     func3 = 4; गच्छ do_cop; // xori d, a, fc
                पक्ष '|':     func3 = 6; गच्छ do_cop; // ori  d, a, fc
                पक्ष '&':     func3 = 7; गच्छ do_cop; // andi d, a, fc
                पक्ष TOK_SHL: func3 = 1; cll = ll; fc &= m; गच्छ do_cop; // slli d, a, fc
                पक्ष TOK_SHR: func3 = 5; cll = ll; fc &= m; गच्छ do_cop; // srli d, a, fc
                पक्ष TOK_SAR: func3 = 5; cll = ll; fc = 1024 | (fc & m); गच्छ do_cop;

                पक्ष TOK_UGE: /* -> TOK_ULT */
                पक्ष TOK_UGT: /* -> TOK_ULE */
                पक्ष TOK_GE:  /* -> TOK_LT */
                पक्ष TOK_GT:  /* -> TOK_LE */
                    gen_opil(op - 1, !ll);
                    vtop->cmp_op ^= 1;
                    प्रत्यागम;

                पक्ष TOK_NE:
                पक्ष TOK_EQ:
                    यदि (fc)
                      gen_opil('-', !ll), a = ireg(vtop++->r);
                    --vtop;
                    vset_VT_CMP(op);
                    vtop->cmp_r = a | 0 << 8;
                    प्रत्यागम;
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
    विकल्प (op) {
    स्वभाव:
        यदि (op >= TOK_ULT && op <= TOK_GT) {
            vset_VT_CMP(op);
            vtop->cmp_r = a | b << 8;
            भङ्ग;
        }
        tcc_error("implement me: %s(%s)", __FUNCTION__, get_tok_str(op, रिक्त));
        भङ्ग;

    पक्ष '+':
        ER(0x33 | ll, 0, d, a, b, 0); // add d, a, b
        भङ्ग;
    पक्ष '-':
        ER(0x33 | ll, 0, d, a, b, 0x20); // sub d, a, b
        भङ्ग;
    पक्ष TOK_SAR:
        ER(0x33 | ll | ll, 5, d, a, b, 0x20); // sra d, a, b
        भङ्ग;
    पक्ष TOK_SHR:
        ER(0x33 | ll | ll, 5, d, a, b, 0); // srl d, a, b
        भङ्ग;
    पक्ष TOK_SHL:
        ER(0x33 | ll, 1, d, a, b, 0); // sll d, a, b
        भङ्ग;
    पक्ष '*':
        ER(0x33 | ll, 0, d, a, b, 1); // mul d, a, b
        भङ्ग;
    पक्ष '/':
    पक्ष TOK_PDIV:
        ER(0x33 | ll, 4, d, a, b, 1); // div d, a, b
        भङ्ग;
    पक्ष '&':
        ER(0x33, 7, d, a, b, 0); // and d, a, b
        भङ्ग;
    पक्ष '^':
        ER(0x33, 4, d, a, b, 0); // xor d, a, b
        भङ्ग;
    पक्ष '|':
        ER(0x33, 6, d, a, b, 0); // or d, a, b
        भङ्ग;
    पक्ष '%':
        ER(ll ? 0x3b:  0x33, 6, d, a, b, 1); // rem d, a, b
        भङ्ग;
    पक्ष TOK_UMOD:
        ER(0x33 | ll, 7, d, a, b, 1); // remu d, a, b
        भङ्ग;
    पक्ष TOK_UDIV:
        ER(0x33 | ll, 5, d, a, b, 1); // divu d, a, b
        भङ्ग;
    }
}

ST_FUNC शून्य gen_opi(पूर्णाङ्क op)
{
    gen_opil(op, 0);
}

ST_FUNC शून्य gen_opl(पूर्णाङ्क op)
{
    gen_opil(op, 1);
}

ST_FUNC शून्य gen_opf(पूर्णाङ्क op)
{
    पूर्णाङ्क rs1, rs2, rd, dbl, invert;
    यदि (vtop[0].type.t == VT_LDOUBLE) {
        CType type = vtop[0].type;
        पूर्णाङ्क func = 0;
        पूर्णाङ्क cond = -1;
        विकल्प (op) {
        पक्ष '*': func = TOK___multf3; भङ्ग;
        पक्ष '+': func = TOK___addtf3; भङ्ग;
        पक्ष '-': func = TOK___subtf3; भङ्ग;
        पक्ष '/': func = TOK___divtf3; भङ्ग;
        पक्ष TOK_EQ: func = TOK___eqtf2; cond = 1; भङ्ग;
        पक्ष TOK_NE: func = TOK___netf2; cond = 0; भङ्ग;
        पक्ष TOK_LT: func = TOK___lttf2; cond = 10; भङ्ग;
        पक्ष TOK_GE: func = TOK___getf2; cond = 11; भङ्ग;
        पक्ष TOK_LE: func = TOK___letf2; cond = 12; भङ्ग;
        पक्ष TOK_GT: func = TOK___gttf2; cond = 13; भङ्ग;
        स्वभाव: प्रतिज्ञा(0); भङ्ग;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = REG_IRET;
        vtop->r2 = cond < 0 ? TREG_R(1) : VT_CONST;
        यदि (cond < 0)
            vtop->type = type;
        अन्यथा {
            vpushi(0);
            gen_opil(op, 1);
        }
        प्रत्यागम;
    }

    gv2(RC_FLOAT, RC_FLOAT);
    प्रतिज्ञा(vtop->type.t == VT_DOUBLE || vtop->type.t == VT_FLOAT);
    dbl = vtop->type.t == VT_DOUBLE;
    rs1 = freg(vtop[-1].r);
    rs2 = freg(vtop->r);
    vtop--;
    invert = 0;
    विकल्प(op) {
    स्वभाव:
        प्रतिज्ञा(0);
    पक्ष '+':
        op = 0; // fadd
    arithop:
        rd = get_reg(RC_FLOAT);
        vtop->r = rd;
        rd = freg(rd);
        ER(0x53, 7, rd, rs1, rs2, dbl | (op << 2)); // fop.[sd] RD, RS1, RS2 (dyn rm)
        भङ्ग;
    पक्ष '-':
        op = 1; // fsub
        गच्छ arithop;
    पक्ष '*':
        op = 2; // fmul
        गच्छ arithop;
    पक्ष '/':
        op = 3; // fdiv
        गच्छ arithop;
    पक्ष TOK_EQ:
        op = 2; // EQ
    cmpop:
        rd = get_reg(RC_INT);
        vtop->r = rd;
        rd = ireg(rd);
        ER(0x53, op, rd, rs1, rs2, dbl | 0x50); // fcmp.[sd] RD, RS1, RS2 (op == eq/lt/le)
        यदि (invert)
          EI(0x13, 4, rd, rd, 1); // xori RD, 1

        /* generate VT_CMP output */
        vset_VT_CMP(TOK_NE);
        vtop->cmp_r = rd | (0 << 8);
        भङ्ग;
    पक्ष TOK_NE:
        invert = 1;
        op = 2; // EQ
        गच्छ cmpop;
    पक्ष TOK_LT:
        op = 1; // LT
        गच्छ cmpop;
    पक्ष TOK_LE:
        op = 0; // LE
        गच्छ cmpop;
    पक्ष TOK_GT:
        op = 1; // LT
        rd = rs1, rs1 = rs2, rs2 = rd;
        गच्छ cmpop;
    पक्ष TOK_GE:
        op = 0; // LE
        rd = rs1, rs1 = rs2, rs2 = rd;
        गच्छ cmpop;
    }
}

ST_FUNC शून्य gen_cvt_csti(पूर्णाङ्क t)
{
    पूर्णाङ्क r = ireg(gv(RC_INT));
    यदि ((t & VT_BTYPE) == VT_SHORT) {
        यदि (t & VT_UNSIGNED) {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EI(0x13, 5, r, r, 48); // srli r, r, 48
        } अन्यथा {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EIu(0x13, 5, r, r, 0x400 | 48); // srai r, r, 48
        }
    } अन्यथा {
        यदि (t & VT_UNSIGNED) {
            EI(0x13, 7, r, r, 0xff); // andi r, r, 0xff
        } अन्यथा {
            EI(0x13, 1, r, r, 56); // slli r, r, 56
            EIu(0x13, 5, r, r, 0x400 | 56); // srai r, r, 56
        }
    }
}

ST_FUNC शून्य gen_cvt_sxtw(शून्य)
{
    पूर्णाङ्क r = ireg(gv(RC_INT));
    EI(0x1b, 0, r, r, 0); // addiw r, r, 0
}

ST_FUNC शून्य gen_cvt_itof(पूर्णाङ्क t)
{
    पूर्णाङ्क rr = ireg(gv(RC_INT)), dr;
    पूर्णाङ्क u = vtop->type.t & VT_UNSIGNED;
    पूर्णाङ्क l = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    यदि (t == VT_LDOUBLE) {
        पूर्णाङ्क func = l ?
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

ST_FUNC शून्य gen_cvt_ftoi(पूर्णाङ्क t)
{
    पूर्णाङ्क ft = vtop->type.t & VT_BTYPE;
    पूर्णाङ्क l = (t & VT_BTYPE) == VT_LLONG;
    पूर्णाङ्क u = t & VT_UNSIGNED;
    यदि (ft == VT_LDOUBLE) {
        पूर्णाङ्क func = l ?
          (u ? TOK___fixunstfdi : TOK___fixtfdi) :
          (u ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
    } अन्यथा {
        पूर्णाङ्क rr = freg(gv(RC_FLOAT)), dr;
        vtop--;
        dr = get_reg(RC_INT);
        vtop++;
        vtop->r = dr;
        dr = ireg(dr);
        EIu(0x53, 1, dr, rr, ((0x60 | (ft == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[wl][u].[sd] rtz
    }
}

ST_FUNC शून्य gen_cvt_ftof(पूर्णाङ्क dt)
{
    पूर्णाङ्क st = vtop->type.t & VT_BTYPE, rs, rd;
    dt &= VT_BTYPE;
    यदि (st == dt)
      प्रत्यागम;
    यदि (dt == VT_LDOUBLE || st == VT_LDOUBLE) {
        पूर्णाङ्क func = (dt == VT_LDOUBLE) ?
            (st == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (dt == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        /* We can't use gfunc_call, as func_old_type works like vararg
           functions, and on riscv unnamed float args are passed like
           integers.  But we really need them in the float argument registers
           for extendsftf2/extenddftf2.  So, do it explicitely.  */
        save_regs(1);
        यदि (dt == VT_LDOUBLE)
          gv(RC_F(0));
        अन्यथा {
            gv(RC_R(0));
            प्रतिज्ञा(vtop->r2 < 7);
            यदि (vtop->r2 != 1 + vtop->r) {
                EI(0x13, 0, ireg(vtop->r) + 1, ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = 1 + vtop->r;
            }
        }
        vpush_helper_func(func);
        gcall_or_jmp(1);
        vtop -= 2;
        vpushi(0);
        vtop->type.t = dt;
        यदि (dt == VT_LDOUBLE)
          vtop->r = REG_IRET, vtop->r2 = REG_IRET+1;
        अन्यथा
          vtop->r = REG_FRET;
    } अन्यथा {
        प्रतिज्ञा (dt == VT_FLOAT || dt == VT_DOUBLE);
        प्रतिज्ञा (st == VT_FLOAT || st == VT_DOUBLE);
        rs = gv(RC_FLOAT);
        rd = get_reg(RC_FLOAT);
        यदि (dt == VT_DOUBLE)
          EI(0x53, 0, freg(rd), freg(rs), 0x21 << 5); // fcvt.d.s RD, RS (no rm)
        अन्यथा
          EI(0x53, 7, freg(rd), freg(rs), (0x20 << 5) | 1); // fcvt.s.d RD, RS (dyn rm)
        vtop->r = rd;
    }
}

/* increment tcov counter */
ST_FUNC शून्य gen_increment_tcov (SValue *sv)
{
    पूर्णाङ्क r1, r2;
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

ST_FUNC शून्य ggoto(शून्य)
{
    gcall_or_jmp(0);
    vtop--;
}

ST_FUNC शून्य gen_vla_sp_save(पूर्णाङ्क addr)
{
    यदि (नीचः_अतिप्रवाहः(addr)) {
	o(0x37 | (5 << 7) | ऊर्ध्वस्थम्_2(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        ES(0x23, 3, 5, 2, SIGN11(addr)); // sd sp, fc(t0)
    }
    अन्यथा
        ES(0x23, 3, 8, 2, addr); // sd sp, fc(s0)
}

ST_FUNC शून्य gen_vla_sp_restore(पूर्णाङ्क addr)
{
    यदि (नीचः_अतिप्रवाहः(addr)) {
	o(0x37 | (5 << 7) | ऊर्ध्वस्थम्_2(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        EI(0x03, 3, 2, 5, SIGN11(addr)); // ld sp, fc(t0)
    }
    अन्यथा
        EI(0x03, 3, 2, 8, addr); // ld sp, fc(s0)
}

ST_FUNC शून्य gen_vla_alloc(CType *type, पूर्णाङ्क align)
{
    पूर्णाङ्क rr;
#यदि defined(CONFIG_TCC_BCHECK)
    यदि (tcc_state->do_bounds_check)
        vpushv(vtop);
#यदि_अन्तः
    rr = ireg(gv(RC_INT));
#यदि defined(CONFIG_TCC_BCHECK)
    यदि (tcc_state->do_bounds_check)
        EI(0x13, 0, rr, rr, 15+1);   // addi RR, RR, 15+1
    अन्यथा
#यदि_अन्तः
    EI(0x13, 0, rr, rr, 15);   // addi RR, RR, 15
    EI(0x13, 7, rr, rr, -16);  // andi, RR, RR, -16
    ER(0x33, 0, 2, 2, rr, 0x20); // sub sp, sp, rr
    vpop();
#यदि defined(CONFIG_TCC_BCHECK)
    यदि (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x00010513); /* mv a0,sp */
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_सङ्कलय_epilog = 1;
    }
#यदि_अन्तः
}

ST_FUNC शून्य gen_clear_cache(शून्य)
{
    /* Zifencei extension: fence + fence.i for I/D synchronization.
       Required by RISC-V Linux ABI, present on all Linux-capable cores. */
    o(0x0ff0000f); // fence iorw, iorw
    o(0x0000100f); // fence.i
}
#यदि_अन्तः
