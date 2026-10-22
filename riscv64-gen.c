#ifdef TARGET_DEFS_ONLY

// Number of registers available to allocator:
#define NB_REGS 19 // x10-x17 aka a0-a7, f10-f17 aka fa0-fa7, xxx, ra, sp
#define CONFIG_TCC_ASM

#define TREG_R(x) (x) // x = 0..7
#define TREG_F(x) (x + 8) // x = 0..7

// Register classes sorted from more general to more precise:
#define RC_INT (1 << 0)
#define RC_FLOAT (1 << 1)
#define RC_R(x) (1 << (2 + (x))) // x = 0..7
#define RC_F(x) (1 << (10 + (x))) // x = 0..7

#define RC_IRET (RC_R(0)) // int return register class
#define RC_IRE2 (RC_R(1)) // int 2nd return register class
#define RC_FRET (RC_F(0)) // float return register class

#define REG_IRET (TREG_R(0)) // int return register number
#define REG_IRE2 (TREG_R(1)) // int 2nd return register number
#define REG_FRET (TREG_F(0)) // float return register number

#define PTR_SIZE 8

#define LDOUBLE_SIZE 16
#define LDOUBLE_ALIGN 16

#define MAX_ALIGN 16

#define CHAR_IS_UNSIGNED

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#define PROMOTE_RET

#இல்லையெனில்
#define USING_GLOBALS
#அந்தர்பாவ "tcc.h"
#அந்தர்பாவ <assert.h>

#define UPPER(x)	(((unsigned)(x) + 0x800u) & 0xfffff000)
#define கீழ்_OVERFLOW(x)	UPPER(x)
#define SIGN7(x)	((((x) & 0xff) ^ 0x80) - 0x80)
#define SIGN11(x)	((((x) & 0xfff) ^ 0x800) - 0x800)

ST_DATA மாறிலி எழுத்து * மாறிலி target_machine_defs =
    "__riscv\0"
    "__riscv_xlen 64\0"
    "__riscv_flen 64\0"
    "__riscv_div\0"
    "__riscv_mul\0"
    "__riscv_fdiv\0"
    "__riscv_fsqrt\0"
    "__riscv_float_abi_double\0"
    ;

#define XLEN 8

#define TREG_RA 17
#define TREG_SP 18

ST_DATA மாறிலி முழு reg_classes[NB_REGS] = {
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

#எனில் defined(CONFIG_TCC_BCHECK)
நிலையான addr_t func_bound_offset;
நிலையான unsigned long func_bound_ind;
ST_DATA முழு func_bound_add_epilog;
#endif

நிலையான முழு ireg(முழு r)
{
    எனில் (r == TREG_RA)
      திரும்பு 1; // ra
    எனில் (r == TREG_SP)
      திரும்பு 2; // sp
    ப்ரதிஜ்ஞா(r >= 0 && r < 8);
    திரும்பு r + 10;  // tccrX --> aX == x(10+X)
}

நிலையான முழு is_ireg(முழு r)
{
    திரும்பு (unsigned)r < 8 || r == TREG_RA || r == TREG_SP;
}

நிலையான முழு freg(முழு r)
{
    ப்ரதிஜ்ஞா(r >= 8 && r < 16);
    திரும்பு r - 8 + 10;  // tccfX --> faX == f(10+X)
}

நிலையான முழு is_freg(முழு r)
{
    திரும்பு r >= 8 && r < 16;
}

ST_FUNC வெறுமை o(unsigned முழு c)
{
    முழு ind1 = ind + 4;
    எனில் (nocode_wanted)
        திரும்பு;
    எனில் (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    write32le(cur_text_section->data + ind, c);
    ind = ind1;
}

நிலையான வெறுமை EIu(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    o(opcode | (func3 << 12) | (rd << 7) | (rs1 << 15) | (imm << 20));
}

நிலையான வெறுமை ER(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t func7)
{
    o(opcode | func3 << 12 | rd << 7 | rs1 << 15 | rs2 << 20 | func7 << 25);
}

நிலையான வெறுமை EI(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    ப்ரதிஜ்ஞா(! கீழ்_OVERFLOW(imm));
    EIu(opcode, func3, rd, rs1, imm);
}

நிலையான வெறுமை ES(uint32_t opcode, uint32_t func3,
               uint32_t rs1, uint32_t rs2, uint32_t imm)
{
    ப்ரதிஜ்ஞா(! கீழ்_OVERFLOW(imm));
    o(opcode | (func3 << 12) | ((imm & 0x1f) << 7) | (rs1 << 15)
      | (rs2 << 20) | ((imm >> 5) << 25));
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC வெறுமை gsym_addr(முழு t_, முழு a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    போது (t) {
        unsigned எழுத்து *ptr = cur_text_section->data + t;
        uint32_t next = read32le(ptr);
        uint32_t r = a - t, imm;
        எனில் ((r + (1 << 21)) & ~((1U << 22) - 2))
          tcc_error("out-of-range branch chain");
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        write32le(ptr, r == 4 ? 0x33 : 0x6f | imm); // nop || j imm
        t = next;
    }
}

நிலையான முழு load_symofs(முழு r, SValue *sv, முழு forstore, முழு *new_fc)
{
    முழு rr, doload = 0, large_addend = 0;
    முழு fc = sv->c.i, v = sv->r & VT_VALMASK;
    எனில் (sv->r & VT_SYM) {
        Sym label = {0};
        ப்ரதிஜ்ஞா(v == VT_CONST);
        எனில் (sv->sym->type.t & VT_TLS) {
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
            திரும்பு rr;
        }
        எனில் (sv->sym->type.t & VT_STATIC) { // XXX do this per linker relax
            greloca(cur_text_section, sv->sym, ind,
                    R_RISCV_PCREL_HI20, sv->c.i);
            *new_fc = 0;
        } இல்லையெனில் {
            எனில் (கீழ்_OVERFLOW(fc)){
              large_addend = 1;
            }
            greloca(cur_text_section, sv->sym, ind,
                    R_RISCV_GOT_HI20, 0);
            doload = 1;
        }
        label.type.t = VT_VOID | VT_STATIC;
	எனில் (!nocode_wanted)
            put_extern_sym(&label, cur_text_section, ind, 0);
        rr = is_ireg(r) ? ireg(r) : 5;
        o(0x17 | (rr << 7));   // auipc RR, 0 %pcrel_hi(sym)+addend
        greloca(cur_text_section, &label, ind,
                doload || !forstore
                  ? R_RISCV_PCREL_LO12_I : R_RISCV_PCREL_LO12_S, 0);
        எனில் (doload) {
            EI(0x03, 3, rr, rr, 0); // ld RR, 0(RR)
            எனில் (large_addend) {
                o(0x37 | (6 << 7) | UPPER(fc)); //lui t1, high(fc)
                ER(0x33, 0, rr, rr, 6, 0); // add RR, RR, t1
                *new_fc = SIGN11(fc);
            }
        }
    } இல்லையெனில் எனில் (v == VT_LOCAL || v == VT_LLOCAL) {
        rr = 8; // s0
        எனில் (fc != sv->c.i)
          tcc_error("unimp: store(giant local off) (0x%lx)", (long)sv->c.i);
        எனில் (கீழ்_OVERFLOW(fc)) {
            rr = is_ireg(r) ? ireg(r) : 5; // t0
            o(0x37 | (rr << 7) | UPPER(fc)); //lui RR, upper(fc)
            ER(0x33, 0, rr, rr, 8, 0); // add RR, RR, s0
            *new_fc = SIGN11(fc);
        }
    } இல்லையெனில்
      tcc_error("uhh");
    திரும்பு rr;
}

நிலையான வெறுமை load_large_constant(முழு rr, முழு fc, uint32_t pi)
{
    எனில் (fc < 0)
	pi++;
    o(0x37 | (rr << 7) | UPPER(pi)); // lui RR, up(up(fc))
    EI(0x13, 0, rr, rr, SIGN11(pi));   // addi RR, RR, lo(up(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((unsigned)fc + (1 << 19)) >> 20)); // addi RR, RR, up(lo(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((unsigned)fc + (1 << 7)) >> 8));  // addi RR, RR, lo1(lo(fc))
    EI(0x13, 1, rr, rr, 8); // slli RR, RR, 8
}

ST_FUNC வெறுமை load(முழு r, SValue *sv)
{
    முழு fr = sv->r;
    முழு v = fr & VT_VALMASK;
    முழு rr = is_ireg(r) ? ireg(r) : freg(r);
    முழு fc = sv->c.i;
    முழு bt = sv->type.t & VT_BTYPE;
    முழு align, size;
    எனில் (fr & VT_LVAL) {
        முழு func3, opcode = is_freg(r) ? 0x07 : 0x03, br;
        size = type_size(&sv->type, &align);
        ப்ரதிஜ்ஞா (!is_freg(r) || bt == VT_FLOAT || bt == VT_DOUBLE);
        எனில் (bt == VT_PTR || bt == VT_FUNC) /* XXX should be done in generic code */
          size = PTR_SIZE;
        func3 = size == 1 ? 0 : size == 2 ? 1 : size == 4 ? 2 : 3;
        எனில் (size < 4 && !is_float(sv->type.t) && (sv->type.t & VT_UNSIGNED))
          func3 |= 4;
        எனில் (v == VT_LOCAL || (fr & VT_SYM)) {
            br = load_symofs(r, sv, 0, &fc);
        } இல்லையெனில் எனில் (v < VT_CONST) {
            br = ireg(v);
            /*if (LOW_OVERFLOW(fc))
              tcc_error("unimp: load(large addend) (0x%x)", fc);*/
            fc = 0; // XXX store ofs in LVAL(reg)
        } இல்லையெனில் எனில் (v == VT_LLOCAL) {
            br = load_symofs(r, sv, 0, &fc);
            EI(0x03, 3, rr, br, fc); // ld RR, fc(BR)
            br = rr;
            fc = 0;
        } இல்லையெனில் எனில் (v == VT_CONST) {
            int64_t si = sv->c.i;
            si >>= 32;
            எனில் (si != 0) {
		load_large_constant(rr, fc, si);
                fc = SIGN7(fc);
            } இல்லையெனில் {
                o(0x37 | (rr << 7) | UPPER(fc)); //lui RR, upper(fc)
                fc = SIGN11(fc);
	    }
            br = rr;
	} இல்லையெனில் {
            tcc_error("unimp: load(non-local lval)");
        }
        EI(opcode, func3, rr, br, fc); // l[bhwd][u] / fl[wd] RR, fc(BR)
    } இல்லையெனில் எனில் (v == VT_CONST) {
        முழு rb = 0, do32bit = 8, zext = 0;
        எனில் (is_float(sv->type.t) && bt != VT_LDOUBLE) {
            /* load float/double constant: move bit pattern from int reg */
            uint64_t val = sv->c.i;
            முழு is_dbl = bt == VT_DOUBLE;
            எனில் (val == 0) {
                o(0x53 | (rr << 7) | ((unsigned)(0x78 | is_dbl) << 25));
                திரும்பு;
            }
            எனில் (is_dbl) {
                load_large_constant(6, (முழு)val, (முழு)(val >> 32));
            } இல்லையெனில் {
                எனில் (கீழ்_OVERFLOW(fc))
                    o(0x37 | (6 << 7) | UPPER(fc)); // lui t1, upper
                EI(0x13 | 8, 0, 6, கீழ்_OVERFLOW(fc) ? 6 : 0, SIGN11(fc)); // addiw t1,...
            }
            o(0x53 | (rr << 7) | (6 << 15) | ((unsigned)(0x78 | is_dbl) << 25));
            திரும்பு;
        }
        ப்ரதிஜ்ஞா(is_ireg(r) || bt == VT_LDOUBLE);
        எனில் (fr & VT_SYM) {
            rb = load_symofs(r, sv, 0, &fc);
            do32bit = 0;
        }
        எனில் (do32bit && fc != sv->c.i) {
            int64_t si = sv->c.i;
            si >>= 32;
            எனில் (si != 0) {
		load_large_constant(rr, fc, si);
                fc = SIGN7(fc);
                rb = rr;
                do32bit = 0;
            } இல்லையெனில் எனில் (bt == VT_LLONG) {
                /* A 32bit unsigned constant for a 64bit type.
                   lui always sign extends, so we need to do an explicit zext.*/
                zext = 1;
            }
        }
        எனில் (கீழ்_OVERFLOW(fc))
            o(0x37 | (rr << 7) | UPPER(fc)), rb = rr; //lui RR, upper(fc)
        எனில் (fc || (rr != rb) || do32bit || (fr & VT_SYM))
          EI(0x13 | do32bit, 0, rr, rb, SIGN11(fc)); // addi[w] R, x0|R, FC
        எனில் (zext) {
            EI(0x13, 1, rr, rr, 32); // slli RR, RR, 32
            EI(0x13, 5, rr, rr, 32); // srli RR, RR, 32
        }
    } இல்லையெனில் எனில் (v == VT_LOCAL) {
        முழு br = load_symofs(r, sv, 0, &fc);
        ப்ரதிஜ்ஞா(is_ireg(r));
        EI(0x13, 0, rr, br, fc); // addi R, s0, FC
    } இல்லையெனில் எனில் (v < VT_CONST) { /* reg-reg */
        //assert(!fc); XXX support offseted regs
        எனில் (is_freg(r) && is_freg(v))
          ER(0x53, 0, rr, freg(v), freg(v), bt == VT_DOUBLE ? 0x11 : 0x10); //fsgnj.[sd] RR, V, V == fmv.[sd] RR, V
        இல்லையெனில் எனில் (is_ireg(r) && is_ireg(v))
          EI(0x13, 0, rr, ireg(v), 0); // addi RR, V, 0 == mv RR, V
        இல்லையெனில் {
            முழு func7 = is_ireg(r) ? 0x70 : 0x78;
            size = type_size(&sv->type, &align);
            எனில் (size == 8)
              func7 |= 1;
            ப்ரதிஜ்ஞா(size == 4 || size == 8);
            o(0x53 | (rr << 7) | ((is_freg(v) ? freg(v) : ireg(v)) << 15)
              | ((unsigned)func7 << 25)); // fmv.{w.x, x.w, d.x, x.d} RR, VR
        }
    } இல்லையெனில் எனில் (v == VT_CMP) {
        முழு op = vtop->cmp_op;
        முழு a = vtop->cmp_r & 0xff;
        முழு b = (vtop->cmp_r >> 8) & 0xff;
        முழு inv = 0;
        தேர்வு (op) {
            நிலை TOK_ULT:
            நிலை TOK_UGE:
            நிலை TOK_ULE:
            நிலை TOK_UGT:
            நிலை TOK_LT:
            நிலை TOK_GE:
            நிலை TOK_LE:
            நிலை TOK_GT:
                எனில் (op & 1) { // remove [U]GE,GT
                    inv = 1;
                    op--;
                }
                எனில் ((op & 7) == 6) { // [U]LE
                    முழு t = a; a = b; b = t;
                    inv ^= 1;
                }
                ER(0x33, (op > TOK_UGT) ? 2 : 3, rr, a, b, 0); // slt[u] d, a, b
                எனில் (inv)
                  EI(0x13, 4, rr, rr, 1); // xori d, d, 1
                நிறுத்து;
            நிலை TOK_NE:
            நிலை TOK_EQ:
                எனில் (rr != a || b)
                  ER(0x33, 0, rr, a, b, 0x20); // sub d, a, b
                எனில் (op == TOK_NE)
                  ER(0x33, 3, rr, 0, rr, 0); // sltu d, x0, d == snez d,d
                இல்லையெனில்
                  EI(0x13, 3, rr, rr, 1); // sltiu d, d, 1 == seqz d,d
                நிறுத்து;
        }
    } இல்லையெனில் எனில் ((v & ~1) == VT_JMP) {
        முழு t = v & 1;
        ப்ரதிஜ்ஞா(is_ireg(r));
        EI(0x13, 0, rr, 0, t);      // addi RR, x0, t
        gjmp_addr(ind + 8);
        gsym(fc);
        EI(0x13, 0, rr, 0, t ^ 1);  // addi RR, x0, !t
    } இல்லையெனில்
      tcc_error("unimp: load(non-const)");
}

ST_FUNC வெறுமை store(முழு r, SValue *sv)
{
    முழு fr = sv->r & VT_VALMASK;
    முழு rr = is_ireg(r) ? ireg(r) : freg(r), ptrreg;
    முழு fc = sv->c.i;
    முழு bt = sv->type.t & VT_BTYPE;
    முழு align, size = type_size(&sv->type, &align);
    ப்ரதிஜ்ஞா(!is_float(bt) || is_freg(r) || bt == VT_LDOUBLE);
    /* long doubles are in two integer registers, but the load/store
       primitives only deal with one, so do as if it's one reg.  */
    எனில் (bt == VT_LDOUBLE)
      size = align = 8;
    எனில் (bt == VT_STRUCT)
      tcc_error("unimp: store(struct)");
    எனில் (size > 8)
      tcc_error("unimp: large sized store");
    ப்ரதிஜ்ஞா(sv->r & VT_LVAL);
    எனில் (fr == VT_LOCAL || (sv->r & VT_SYM)) {
        ptrreg = load_symofs(-1, sv, 1, &fc);
    } இல்லையெனில் எனில் (fr < VT_CONST) {
        ptrreg = ireg(fr);
        /*if (LOW_OVERFLOW(fc))
          tcc_error("unimp: store(large addend) (0x%x)", fc);*/
        fc = 0; // XXX support offsets regs
    } இல்லையெனில் எனில் (fr == VT_CONST) {
        int64_t si = sv->c.i;
        ptrreg = 8; // s0
        si >>= 32;
        எனில் (si != 0) {
	    load_large_constant(ptrreg, fc, si);
            fc = SIGN7(fc);
        } இல்லையெனில் {
            o(0x37 | (ptrreg << 7) | UPPER(fc)); //lui RR, upper(fc)
            fc = SIGN11(fc);
	}
    } இல்லையெனில்
      tcc_error("implement me: %s(!local)", __FUNCTION__);
    ES(is_freg(r) ? 0x27 : 0x23,                          // fs... | s...
       size == 1 ? 0 : size == 2 ? 1 : size == 4 ? 2 : 3, // ... [wd] | [bhwd]
       ptrreg, rr, fc);                                   // RR, fc(base)
}

நிலையான வெறுமை gcall_or_jmp(முழு docall)
{
    முழு tr = docall ? 1 : 5; // ra or t0
    எனில் ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
        ((vtop->r & VT_SYM) && vtop->c.i == (முழு)vtop->c.i)) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind,
                R_RISCV_CALL_PLT, (முழு)vtop->c.i);
        o(0x17 | (tr << 7));   // auipc TR, 0 %call(func)
        EI(0x67, 0, tr, tr, 0);// jalr  TR, r(TR)
    } இல்லையெனில் எனில் (vtop->r < VT_CONST) {
        முழு r = ireg(vtop->r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    } இல்லையெனில் {
        முழு r = TREG_RA;
        load(r, vtop);
        r = ireg(r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    }
}

#எனில் defined(CONFIG_TCC_BCHECK)

நிலையான வெறுமை gen_bounds_call(முழு v)
{
    Sym *sym = external_helper_sym(v);

    greloca(cur_text_section, sym, ind, R_RISCV_CALL_PLT, 0);
    o(0x17 | (1 << 7));   // auipc TR, 0 %call(func)
    EI(0x67, 0, 1, 1, 0); // jalr  TR, r(TR)
}

நிலையான வெறுமை gen_bounds_prolog(வெறுமை)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->data_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0x00000013);  /* ld a0,#lbound section pointer */
    o(0x00000013);
    o(0x00000013);  /* nop -> call __bound_local_new */
    o(0x00000013);
}

நிலையான வெறுமை gen_bounds_epilog(வெறுமை)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    Sym label = {0};

    முழு offset_modified = func_bound_offset != lbounds_section->data_offset;

    எனில் (!offset_modified && !func_bound_add_epilog)
        திரும்பு;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, அளவு(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    label.type.t = VT_VOID | VT_STATIC;
    /* generate bound local allocation */
    எனில் (offset_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        put_extern_sym(&label, cur_text_section, ind, 0);
        greloca(cur_text_section, sym_data, ind, R_RISCV_GOT_HI20, 0);
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
    greloca(cur_text_section, sym_data, ind, R_RISCV_GOT_HI20, 0);
    o(0x17 | (10 << 7));    // auipc a0, 0 %pcrel_hi(sym)+addend
    greloca(cur_text_section, &label, ind, R_RISCV_PCREL_LO12_I, 0);
    EI(0x03, 3, 10, 10, 0); // ld a0, 0(a0)
    gen_bounds_call(TOK___bound_local_delete);
    o(0x65a26502); /* ld   a0,0(sp)   ld   a1,8(sp)   */
    o(0x61052542); /* fld  fa0,16(sp) addi sp,sp,32   */
}
#endif

நிலையான வெறுமை reg_pass_rec(CType *type, முழு *rc, முழு *fieldofs, முழு ofs)
{
    எனில் ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *f;
        எனில் (type->ref->type.t == VT_UNION)
          rc[0] = -1;
        இல்லையெனில் க்கு (f = type->ref->next; f; f = f->next)
          reg_pass_rec(&f->type, rc, fieldofs, ofs + f->c);
    } இல்லையெனில் எனில் (type->t & VT_ARRAY) {
        எனில் (type->ref->c < 0 || type->ref->c > 2)
          rc[0] = -1;
        இல்லையெனில் {
            முழு a, sz = type_size(&type->ref->type, &a);
            reg_pass_rec(&type->ref->type, rc, fieldofs, ofs);
            எனில் (rc[0] > 2 || (rc[0] == 2 && type->ref->c > 1))
              rc[0] = -1;
            இல்லையெனில் எனில் (type->ref->c == 2 && rc[0] && rc[1] == RC_FLOAT) {
              rc[++rc[0]] = RC_FLOAT;
              fieldofs[rc[0]] = ((ofs + sz) << 4)
                                | (type->ref->type.t & VT_BTYPE);
            } இல்லையெனில் எனில் (type->ref->c == 2)
              rc[0] = -1;
        }
    } இல்லையெனில் எனில் (rc[0] == 2 || rc[0] < 0 || (type->t & VT_BTYPE) == VT_LDOUBLE)
      rc[0] = -1;
    இல்லையெனில் எனில் (!rc[0] || rc[1] == RC_FLOAT || is_float(type->t)) {
      rc[++rc[0]] = is_float(type->t) ? RC_FLOAT : RC_INT;
      fieldofs[rc[0]] = (ofs << 4) | ((type->t & VT_BTYPE) == VT_PTR ? VT_LLONG : type->t & VT_BTYPE);
    } இல்லையெனில்
      rc[0] = -1;
}

நிலையான வெறுமை reg_pass(CType *type, முழு *prc, முழு *fieldofs, முழு named)
{
    prc[0] = 0;
    reg_pass_rec(type, prc, fieldofs, 0);
    எனில் (prc[0] <= 0 || !named) {
        முழு align, size = type_size(type, &align);
        prc[0] = (size + 7) >> 3;
        prc[1] = prc[2] = RC_INT;
        fieldofs[1] = (0 << 4) | (size <= 1 ? VT_BYTE : size <= 2 ? VT_SHORT : size <= 4 ? VT_INT : VT_LLONG);
        fieldofs[2] = (8 << 4) | (size <= 9 ? VT_BYTE : size <= 10 ? VT_SHORT : size <= 12 ? VT_INT : VT_LLONG);
    }
}

ST_FUNC வெறுமை gfunc_call(முழு nb_args)
{
    முழு i, align, size, areg[2];
    முழு *info = tcc_malloc((nb_args + 1) * அளவு (முழு));
    முழு அடுக்கு_adj = 0, tempspace = 0, அடுக்கு_add, ofs, splitofs = 0;
    முழு old = (vtop[-nb_args].type.ref->f.func_type == FUNC_OLD);
    SValue *sv;
    Sym *sa;

#ifdef CONFIG_TCC_BCHECK
    முழு bc_save = tcc_state->do_bounds_check;
    எனில் (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    areg[0] = 0; /* int arg regs */
    areg[1] = 8; /* float arg regs */
    sa = vtop[-nb_args].type.ref->next;
    க்கு (i = 0; i < nb_args; i++) {
        முழு nregs, byref = 0, tempofs;
        முழு prc[3], fieldofs[3];
        sv = &vtop[1 + i - nb_args];
        sv->type.t &= ~VT_ARRAY; // XXX this should be done in tccgen.c
        size = type_size(&sv->type, &align);
        எனில் (size > 16) {
            எனில் (align < XLEN)
              align = XLEN;
            tempspace = (tempspace + align - 1) & -align;
            tempofs = tempspace;
            tempspace += size;
            size = align = 8;
            byref = 64 | (tempofs << 7);
        }
        reg_pass(&sv->type, prc, fieldofs, old || sa != 0);
        எனில் (!old && !sa && align == 2*XLEN && size <= 2*XLEN)
          areg[0] = (areg[0] + 1) & ~1;
        nregs = prc[0];
        எனில் (size == 0)
            info[i] = 0;
        இல்லையெனில் எனில் ((prc[1] == RC_INT && areg[0] >= 8)
            || (prc[1] == RC_FLOAT && areg[1] >= 16)
            || (nregs == 2 && prc[1] == RC_FLOAT && prc[2] == RC_FLOAT
                && areg[1] >= 15)
            || (nregs == 2 && prc[1] != prc[2]
                && (areg[1] >= 16 || areg[0] >= 8))) {
            info[i] = 32;
            எனில் (align < XLEN)
              align = XLEN;
            அடுக்கு_adj += (size + align - 1) & -align;
            எனில் (!old && !sa) /* one vararg on stack forces the rest on stack */
              areg[0] = 8, areg[1] = 16;
        } இல்லையெனில் {
            info[i] = areg[prc[1] - 1]++;
            எனில் (!byref)
              info[i] |= (fieldofs[1] & VT_BTYPE) << 12;
            ப்ரதிஜ்ஞா(!(fieldofs[1] >> 4));
            எனில் (nregs == 2) {
                எனில் (prc[2] == RC_FLOAT || areg[0] < 8)
                  info[i] |= (1 + areg[prc[2] - 1]++) << 7;
                இல்லையெனில் {
                    info[i] |= 16;
                    அடுக்கு_adj += 8;
                }
                எனில் (!byref) {
                    ப்ரதிஜ்ஞா((fieldofs[2] >> 4) < 2048);
                    info[i] |= fieldofs[2] << (12 + 4); // includes offset
                }
            }
        }
        info[i] |= byref;
        எனில் (sa)
          sa = sa->next;
    }
    அடுக்கு_adj = (அடுக்கு_adj + 15) & -16;
    tempspace = (tempspace + 15) & -16;
    அடுக்கு_add = அடுக்கு_adj + tempspace;

    எனில் (அடுக்கு_add) {
        எனில் (அடுக்கு_add >= 0x800) {
            o(0x37 | (5 << 7) | UPPER(-அடுக்கு_add)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(-அடுக்கு_add)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        இல்லையெனில்
            EI(0x13, 0, 2, 2, -அடுக்கு_add);   // addi sp, sp, -adj
        க்கு (i = ofs = 0; i < nb_args; i++) {
            எனில் (info[i] & (64 | 32)) {
                vrotb(nb_args - i);
                size = type_size(&vtop->type, &align);
                எனில் (info[i] & 64) {
                    vset(&char_pointer_type, TREG_SP, 0);
                    vpushi(அடுக்கு_adj + (info[i] >> 7));
                    gen_op('+');
                    vpushv(vtop); // this replaces the old argument
                    vrott(3);
                    indir();
                    vtop->type = vtop[-1].type;
                    vswap();
                    vstore();
                    vpop();
                    size = align = 8;
                }
                எனில் (info[i] & 32) {
                    எனில் (align < XLEN)
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
                    ofs += size;
                }
                vrott(nb_args - i);
            } இல்லையெனில் எனில் (info[i] & 16) {
                ப்ரதிஜ்ஞா(!splitofs);
                splitofs = ofs;
                ofs += 8;
            }
        }
    }
    க்கு (i = 0; i < nb_args; i++) {
        முழு ii = info[nb_args - 1 - i], r = ii, r2 = r;
        எனில் (!(r & 32)) {
            CType origtype;
            முழு loadt;
            r &= 15;
            r2 = r2 & 64 ? 0 : (r2 >> 7) & 31;
            ப்ரதிஜ்ஞா(r2 <= 16);
            vrotb(i+1);
            origtype = vtop->type;
            size = type_size(&vtop->type, &align);
            எனில் (size == 0)
                செல் done;
            loadt = vtop->type.t & VT_BTYPE;
            எனில் (loadt == VT_STRUCT) {
                loadt = (ii >> 12) & VT_BTYPE;
            }
            எனில் (info[nb_args - 1 - i] & 16) {
                ப்ரதிஜ்ஞா(!r2);
                r2 = 1 + TREG_RA;
            }
            எனில் (loadt == VT_LDOUBLE) {
                ப்ரதிஜ்ஞா(r2);
                r2--;
            } இல்லையெனில் எனில் (r2) {
                test_lvalue();
                vpushv(vtop);
            }
            vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
            gv(r < 8 ? RC_R(r) : RC_F(r - 8));
            vtop->type = origtype;

            எனில் (r2 && loadt != VT_LDOUBLE) {
                r2--;
                ப்ரதிஜ்ஞா(r2 < 16 || r2 == TREG_RA);
                vswap();
                gaddrof();
                vtop->type = char_pointer_type;
                vpushi(ii >> 20);
#ifdef CONFIG_TCC_BCHECK
		எனில் ((origtype.t & VT_BTYPE) == VT_STRUCT)
                    tcc_state->do_bounds_check = 0;
#endif
                gen_op('+');
#ifdef CONFIG_TCC_BCHECK
		tcc_state->do_bounds_check = bc_save;
#endif
                indir();
                vtop->type = origtype;
                loadt = vtop->type.t & VT_BTYPE;
                எனில் (loadt == VT_STRUCT) {
                    loadt = (ii >> 16) & VT_BTYPE;
                }
                save_reg_upstack(r2, 1);
                vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
                load(r2, vtop);
                ப்ரதிஜ்ஞா(r2 < VT_CONST);
                vtop--;
                vtop->r2 = r2;
            }
            எனில் (info[nb_args - 1 - i] & 16) {
                ES(0x23, 3, 2, ireg(vtop->r2), splitofs); // sd t0, ofs(sp)
                vtop->r2 = VT_CONST;
            } இல்லையெனில் எனில் (loadt == VT_LDOUBLE && vtop->r2 != r2) {
                ப்ரதிஜ்ஞா(vtop->r2 <= 7 && r2 <= 7);
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
    எனில் (அடுக்கு_add) {
        எனில் (அடுக்கு_add >= 0x800) {
            o(0x37 | (5 << 7) | UPPER(அடுக்கு_add)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(அடுக்கு_add)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        இல்லையெனில்
            EI(0x13, 0, 2, 2, அடுக்கு_add);      // addi sp, sp, adj
   }
   tcc_free(info);
}

நிலையான முழு func_sub_sp_offset, இலக்கம்_va_regs, func_va_list_ofs;

ST_FUNC வெறுமை gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    முழு i, addr, align, size;
    முழு param_addr = 0;
    முழு areg[2];
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
    size = type_size(&func_vt, &align);
    எனில் (size > 2 * XLEN) {
        loc -= 8;
        func_vc = loc;
        ES(0x23, 3, 8, 10 + areg[0]++, loc); // sd a0, loc(s0)
    }
    /* define parameters */
    போது ((sym = sym->next) != வெற்று) {
        முழு byref = 0;
        முழு regcount;
        முழு prc[3], fieldofs[3];
        type = &sym->type;
        size = type_size(type, &align);
        எனில் (size > 2 * XLEN) {
            type = &char_pointer_type;
            size = align = byref = 8;
        }
        reg_pass(type, prc, fieldofs, 1);
        regcount = prc[0];
        எனில் (areg[prc[1] - 1] >= 8
            || (regcount == 2
                && ((prc[1] == RC_FLOAT && prc[2] == RC_FLOAT && areg[1] >= 7)
                    || (prc[1] != prc[2] && (areg[1] >= 8 || areg[0] >= 8))))) {
            எனில் (align < XLEN)
              align = XLEN;
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += size;
        } இல்லையெனில் {
            loc -= regcount * 8; // XXX could reserve only 'size' bytes
            param_addr = loc;
            க்கு (i = 0; i < regcount; i++) {
                எனில் (areg[prc[1+i] - 1] >= 8) {
                    ப்ரதிஜ்ஞா(i == 1 && regcount == 2 && !(addr & 7));
                    EI(0x03, 3, 5, 8, addr); // ld t0, addr(s0)
                    addr += 8;
                    ES(0x23, 3, 8, 5, loc + i*8); // sd t0, loc(s0)
                } இல்லையெனில் எனில் (prc[1+i] == RC_FLOAT) {
                    ES(0x27, (size / regcount) == 4 ? 2 : 3, 8, 10 + areg[1]++, loc + (fieldofs[i+1] >> 4)); // fs[wd] FAi, loc(s0)
                } இல்லையெனில் {
                    ES(0x23, 3, 8, 10 + areg[0]++, loc + i*8); // sd aX, loc(s0) // XXX
                }
            }
        }
        gfunc_set_param(sym, param_addr, byref);
    }
    func_va_list_ofs = addr;
    இலக்கம்_va_regs = 0;
    எனில் (func_var) {
        க்கு (; areg[0] < 8; areg[0]++) {
            இலக்கம்_va_regs++;
            ES(0x23, 3, 8, 10 + areg[0], -8 + இலக்கம்_va_regs * 8); // sd aX, loc(s0)
        }
    }
#ifdef CONFIG_TCC_BCHECK
    எனில் (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

ST_FUNC முழு gfunc_sret(CType *vt, முழு variadic, CType *ret,
                       முழு *ret_align, முழு *regsize)
{
    முழு align, size = type_size(vt, &align), nregs;
    முழு prc[3], fieldofs[3];
    *ret_align = 1;
    *regsize = 8;
    எனில் (size > 16)
      திரும்பு 0;
    reg_pass(vt, prc, fieldofs, 1);
    nregs = prc[0];
    எனில் (nregs == 2 && prc[1] != prc[2])
      திரும்பு -1;  /* generic code can't deal with this case */
    எனில் (prc[1] == RC_FLOAT) {
        *regsize = size / nregs;
    }
    ret->t = fieldofs[1] & VT_BTYPE;
    ret->ref = வெற்று;
    திரும்பு nregs;
}

ST_FUNC வெறுமை arch_transfer_ret_regs(முழு aftercall)
{
    முழு prc[3], fieldofs[3];
    reg_pass(&vtop->type, prc, fieldofs, 1);
    ப்ரதிஜ்ஞா(prc[0] == 2 && prc[1] != prc[2] && !(fieldofs[1] >> 4));
    ப்ரதிஜ்ஞா(vtop->r == (VT_LOCAL | VT_LVAL));
    vpushv(vtop);
    vtop->type.t = fieldofs[1] & VT_BTYPE;
    (aftercall ? store : load)(prc[1] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop->c.i += fieldofs[2] >> 4;
    vtop->type.t = fieldofs[2] & VT_BTYPE;
    (aftercall ? store : load)(prc[2] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop--;
}

ST_FUNC வெறுமை gfunc_epilog(வெறுமை)
{
    முழு v, saved_ind, d, large_ofs_ind;

#ifdef CONFIG_TCC_BCHECK
    எனில் (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    loc = (loc - இலக்கம்_va_regs * 8);
    d = v = (-loc + 15) & -16;

    EI(0x13, 0, 2, 8, இலக்கம்_va_regs * 8); // addi sp, s0, num_va_regs*8
    EI(0x03, 3, 1, 8, -8); // ld ra, -8(s0)
    EI(0x03, 3, 8, 8, -16); // ld s0, -16(s0)
    EI(0x67, 0, 0, 1, 0); // jalr x0, 0(x1), aka ret

    large_ofs_ind = ind;
    எனில் (v >= (1 << 11)) {
        d = 16;
        EI(0x13, 0, 8, 2, d - இலக்கம்_va_regs * 8);      // addi s0, sp, d
        o(0x37 | (5 << 7) | UPPER(v-16)); //lui t0, upper(v)
        EI(0x13, 0, 5, 5, SIGN11(v-16)); // addi t0, t0, lo(v)
        ER(0x33, 0, 2, 2, 5, 0x20); // sub sp, sp, t0
        gjmp_addr(func_sub_sp_offset + 5*4);
    }
    saved_ind = ind;

    ind = func_sub_sp_offset;
    EI(0x13, 0, 2, 2, -d);     // addi sp, sp, -d
    ES(0x23, 3, 2, 1, d - 8 - இலக்கம்_va_regs * 8);  // sd ra, d-8(sp)
    ES(0x23, 3, 2, 8, d - 16 - இலக்கம்_va_regs * 8); // sd s0, d-16(sp)
    எனில் (v < (1 << 11))
      EI(0x13, 0, 8, 2, d - இலக்கம்_va_regs * 8);      // addi s0, sp, d
    இல்லையெனில்
      gjmp_addr(large_ofs_ind);
    எனில் ((ind - func_sub_sp_offset) != 5*4)
      EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
    ind = saved_ind;
}

ST_FUNC வெறுமை gen_va_start(வெறுமை)
{
    vtop--;
    vset(&char_pointer_type, VT_LOCAL, func_va_list_ofs);
}

ST_FUNC வெறுமை gen_fill_nops(முழு bytes)
{
    எனில் ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    போது (bytes > 0) {
        EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
        bytes -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC முழு gjmp(முழு t)
{
    எனில் (nocode_wanted)
      திரும்பு t;
    o(t);
    திரும்பு ind - 4;
}

// Generate branch to known address:
ST_FUNC வெறுமை gjmp_addr(முழு a)
{
    uint32_t r = a - ind, imm;
    எனில் ((r + (1 << 21)) & ~((1U << 22) - 2)) {
        o(0x17 | (5 << 7) | UPPER(r)); // lui RR, up(r)
        r = SIGN11(r);
        EI(0x67, 0, 0, 5, r);      // jalr x0, r(t0)
    } இல்லையெனில் {
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        o(0x6f | imm); // jal x0, imm ==  j imm
    }
}

ST_FUNC முழு gjmp_cond(முழு op, முழு t)
{
    முழு tmp;
    முழு a = vtop->cmp_r & 0xff;
    முழு b = (vtop->cmp_r >> 8) & 0xff;
    தேர்வு (op) {
        நிலை TOK_ULT: op = 6; நிறுத்து;
        நிலை TOK_UGE: op = 7; நிறுத்து;
        நிலை TOK_ULE: op = 7; tmp = a; a = b; b = tmp; நிறுத்து;
        நிலை TOK_UGT: op = 6; tmp = a; a = b; b = tmp; நிறுத்து;
        நிலை TOK_LT:  op = 4; நிறுத்து;
        நிலை TOK_GE:  op = 5; நிறுத்து;
        நிலை TOK_LE:  op = 5; tmp = a; a = b; b = tmp; நிறுத்து;
        நிலை TOK_GT:  op = 4; tmp = a; a = b; b = tmp; நிறுத்து;
        நிலை TOK_NE:  op = 1; நிறுத்து;
        நிலை TOK_EQ:  op = 0; நிறுத்து;
    }
    o(0x63 | (op ^ 1) << 12 | a << 15 | b << 20 | 8 << 7); // bOP a,b,+4
    திரும்பு gjmp(t);
}

ST_FUNC முழு gjmp_append(முழு n, முழு t)
{
    வெறுமை *p;
    /* insert jump list n into t */
    எனில் (n) {
        uint32_t n1 = n, n2;
        போது ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    திரும்பு t;
}

நிலையான வெறுமை gen_opil(முழு op, முழு ll)
{
    முழு a, b, d;
    முழு func3 = 0;
    ll = ll ? 0 : 8;
    எனில் ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
        முழு fc = vtop->c.i;
        எனில் (fc == vtop->c.i && !கீழ்_OVERFLOW(fc)) {
            முழு cll = 0;
            முழு m = ll ? 31 : 63;
            vswap();
            gv(RC_INT);
            a = ireg(vtop[0].r);
            --vtop;
            d = get_reg(RC_INT);
            ++vtop;
            vswap();
            தேர்வு (op) {
                நிலை '-':
                    எனில் (fc <= -(1 << 11))
                      நிறுத்து;
                    fc = -fc;
                நிலை '+':
                    func3 = 0; // addi d, a, fc
                    cll = ll;
                do_cop:
                    EI(0x13 | cll, func3, ireg(d), a, fc);
                    --vtop;
                    எனில் (op >= TOK_ULT && op <= TOK_GT) {
                      vset_VT_CMP(TOK_NE);
                      vtop->cmp_r = ireg(d) | 0 << 8;
                    } இல்லையெனில்
                      vtop[0].r = d;
                    திரும்பு;
                நிலை TOK_LE:
                    எனில் (fc >= (1 << 11) - 1)
                      நிறுத்து;
                    ++fc;
                நிலை TOK_LT:  func3 = 2; செல் do_cop; // slti d, a, fc
                நிலை TOK_ULE:
                    எனில் (fc >= (1 << 11) - 1 || fc == -1)
                      நிறுத்து;
                    ++fc;
                நிலை TOK_ULT: func3 = 3; செல் do_cop; // sltiu d, a, fc
                நிலை '^':     func3 = 4; செல் do_cop; // xori d, a, fc
                நிலை '|':     func3 = 6; செல் do_cop; // ori  d, a, fc
                நிலை '&':     func3 = 7; செல் do_cop; // andi d, a, fc
                நிலை TOK_SHL: func3 = 1; cll = ll; fc &= m; செல் do_cop; // slli d, a, fc
                நிலை TOK_SHR: func3 = 5; cll = ll; fc &= m; செல் do_cop; // srli d, a, fc
                நிலை TOK_SAR: func3 = 5; cll = ll; fc = 1024 | (fc & m); செல் do_cop;

                நிலை TOK_UGE: /* -> TOK_ULT */
                நிலை TOK_UGT: /* -> TOK_ULE */
                நிலை TOK_GE:  /* -> TOK_LT */
                நிலை TOK_GT:  /* -> TOK_LE */
                    gen_opil(op - 1, !ll);
                    vtop->cmp_op ^= 1;
                    திரும்பு;

                நிலை TOK_NE:
                நிலை TOK_EQ:
                    எனில் (fc)
                      gen_opil('-', !ll), a = ireg(vtop++->r);
                    --vtop;
                    vset_VT_CMP(op);
                    vtop->cmp_r = a | 0 << 8;
                    திரும்பு;
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
    தேர்வு (op) {
    இயல்பு:
        எனில் (op >= TOK_ULT && op <= TOK_GT) {
            vset_VT_CMP(op);
            vtop->cmp_r = a | b << 8;
            நிறுத்து;
        }
        tcc_error("implement me: %s(%s)", __FUNCTION__, get_tok_str(op, வெற்று));
        நிறுத்து;

    நிலை '+':
        ER(0x33 | ll, 0, d, a, b, 0); // add d, a, b
        நிறுத்து;
    நிலை '-':
        ER(0x33 | ll, 0, d, a, b, 0x20); // sub d, a, b
        நிறுத்து;
    நிலை TOK_SAR:
        ER(0x33 | ll | ll, 5, d, a, b, 0x20); // sra d, a, b
        நிறுத்து;
    நிலை TOK_SHR:
        ER(0x33 | ll | ll, 5, d, a, b, 0); // srl d, a, b
        நிறுத்து;
    நிலை TOK_SHL:
        ER(0x33 | ll, 1, d, a, b, 0); // sll d, a, b
        நிறுத்து;
    நிலை '*':
        ER(0x33 | ll, 0, d, a, b, 1); // mul d, a, b
        நிறுத்து;
    நிலை '/':
    நிலை TOK_PDIV:
        ER(0x33 | ll, 4, d, a, b, 1); // div d, a, b
        நிறுத்து;
    நிலை '&':
        ER(0x33, 7, d, a, b, 0); // and d, a, b
        நிறுத்து;
    நிலை '^':
        ER(0x33, 4, d, a, b, 0); // xor d, a, b
        நிறுத்து;
    நிலை '|':
        ER(0x33, 6, d, a, b, 0); // or d, a, b
        நிறுத்து;
    நிலை '%':
        ER(ll ? 0x3b:  0x33, 6, d, a, b, 1); // rem d, a, b
        நிறுத்து;
    நிலை TOK_UMOD:
        ER(0x33 | ll, 7, d, a, b, 1); // remu d, a, b
        நிறுத்து;
    நிலை TOK_UDIV:
        ER(0x33 | ll, 5, d, a, b, 1); // divu d, a, b
        நிறுத்து;
    }
}

ST_FUNC வெறுமை gen_opi(முழு op)
{
    gen_opil(op, 0);
}

ST_FUNC வெறுமை gen_opl(முழு op)
{
    gen_opil(op, 1);
}

ST_FUNC வெறுமை gen_opf(முழு op)
{
    முழு rs1, rs2, rd, dbl, invert;
    எனில் (vtop[0].type.t == VT_LDOUBLE) {
        CType type = vtop[0].type;
        முழு func = 0;
        முழு cond = -1;
        தேர்வு (op) {
        நிலை '*': func = TOK___multf3; நிறுத்து;
        நிலை '+': func = TOK___addtf3; நிறுத்து;
        நிலை '-': func = TOK___subtf3; நிறுத்து;
        நிலை '/': func = TOK___divtf3; நிறுத்து;
        நிலை TOK_EQ: func = TOK___eqtf2; cond = 1; நிறுத்து;
        நிலை TOK_NE: func = TOK___netf2; cond = 0; நிறுத்து;
        நிலை TOK_LT: func = TOK___lttf2; cond = 10; நிறுத்து;
        நிலை TOK_GE: func = TOK___getf2; cond = 11; நிறுத்து;
        நிலை TOK_LE: func = TOK___letf2; cond = 12; நிறுத்து;
        நிலை TOK_GT: func = TOK___gttf2; cond = 13; நிறுத்து;
        இயல்பு: ப்ரதிஜ்ஞா(0); நிறுத்து;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = REG_IRET;
        vtop->r2 = cond < 0 ? TREG_R(1) : VT_CONST;
        எனில் (cond < 0)
            vtop->type = type;
        இல்லையெனில் {
            vpushi(0);
            gen_opil(op, 1);
        }
        திரும்பு;
    }

    gv2(RC_FLOAT, RC_FLOAT);
    ப்ரதிஜ்ஞா(vtop->type.t == VT_DOUBLE || vtop->type.t == VT_FLOAT);
    dbl = vtop->type.t == VT_DOUBLE;
    rs1 = freg(vtop[-1].r);
    rs2 = freg(vtop->r);
    vtop--;
    invert = 0;
    தேர்வு(op) {
    இயல்பு:
        ப்ரதிஜ்ஞா(0);
    நிலை '+':
        op = 0; // fadd
    arithop:
        rd = get_reg(RC_FLOAT);
        vtop->r = rd;
        rd = freg(rd);
        ER(0x53, 7, rd, rs1, rs2, dbl | (op << 2)); // fop.[sd] RD, RS1, RS2 (dyn rm)
        நிறுத்து;
    நிலை '-':
        op = 1; // fsub
        செல் arithop;
    நிலை '*':
        op = 2; // fmul
        செல் arithop;
    நிலை '/':
        op = 3; // fdiv
        செல் arithop;
    நிலை TOK_EQ:
        op = 2; // EQ
    cmpop:
        rd = get_reg(RC_INT);
        vtop->r = rd;
        rd = ireg(rd);
        ER(0x53, op, rd, rs1, rs2, dbl | 0x50); // fcmp.[sd] RD, RS1, RS2 (op == eq/lt/le)
        எனில் (invert)
          EI(0x13, 4, rd, rd, 1); // xori RD, 1

        /* generate VT_CMP output */
        vset_VT_CMP(TOK_NE);
        vtop->cmp_r = rd | (0 << 8);
        நிறுத்து;
    நிலை TOK_NE:
        invert = 1;
        op = 2; // EQ
        செல் cmpop;
    நிலை TOK_LT:
        op = 1; // LT
        செல் cmpop;
    நிலை TOK_LE:
        op = 0; // LE
        செல் cmpop;
    நிலை TOK_GT:
        op = 1; // LT
        rd = rs1, rs1 = rs2, rs2 = rd;
        செல் cmpop;
    நிலை TOK_GE:
        op = 0; // LE
        rd = rs1, rs1 = rs2, rs2 = rd;
        செல் cmpop;
    }
}

ST_FUNC வெறுமை gen_cvt_csti(முழு t)
{
    முழு r = ireg(gv(RC_INT));
    எனில் ((t & VT_BTYPE) == VT_SHORT) {
        எனில் (t & VT_UNSIGNED) {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EI(0x13, 5, r, r, 48); // srli r, r, 48
        } இல்லையெனில் {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EIu(0x13, 5, r, r, 0x400 | 48); // srai r, r, 48
        }
    } இல்லையெனில் {
        எனில் (t & VT_UNSIGNED) {
            EI(0x13, 7, r, r, 0xff); // andi r, r, 0xff
        } இல்லையெனில் {
            EI(0x13, 1, r, r, 56); // slli r, r, 56
            EIu(0x13, 5, r, r, 0x400 | 56); // srai r, r, 56
        }
    }
}

ST_FUNC வெறுமை gen_cvt_sxtw(வெறுமை)
{
    முழு r = ireg(gv(RC_INT));
    EI(0x1b, 0, r, r, 0); // addiw r, r, 0
}

ST_FUNC வெறுமை gen_cvt_itof(முழு t)
{
    முழு rr = ireg(gv(RC_INT)), dr;
    முழு u = vtop->type.t & VT_UNSIGNED;
    முழு l = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    எனில் (t == VT_LDOUBLE) {
        முழு func = l ?
          (u ? TOK___floatunditf : TOK___floatditf) :
          (u ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        vtop->r2 = TREG_R(1);
    } இல்லையெனில் {
        vtop--;
        dr = get_reg(RC_FLOAT);
        vtop++;
        vtop->r = dr;
        dr = freg(dr);
        EIu(0x53, 7, dr, rr, ((0x68 | (t == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[sd].[wl][u]
    }
}

ST_FUNC வெறுமை gen_cvt_ftoi(முழு t)
{
    முழு ft = vtop->type.t & VT_BTYPE;
    முழு l = (t & VT_BTYPE) == VT_LLONG;
    முழு u = t & VT_UNSIGNED;
    எனில் (ft == VT_LDOUBLE) {
        முழு func = l ?
          (u ? TOK___fixunstfdi : TOK___fixtfdi) :
          (u ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
    } இல்லையெனில் {
        முழு rr = freg(gv(RC_FLOAT)), dr;
        vtop--;
        dr = get_reg(RC_INT);
        vtop++;
        vtop->r = dr;
        dr = ireg(dr);
        EIu(0x53, 1, dr, rr, ((0x60 | (ft == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[wl][u].[sd] rtz
    }
}

ST_FUNC வெறுமை gen_cvt_ftof(முழு dt)
{
    முழு st = vtop->type.t & VT_BTYPE, rs, rd;
    dt &= VT_BTYPE;
    எனில் (st == dt)
      திரும்பு;
    எனில் (dt == VT_LDOUBLE || st == VT_LDOUBLE) {
        முழு func = (dt == VT_LDOUBLE) ?
            (st == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (dt == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        /* We can't use gfunc_call, as func_old_type works like vararg
           functions, and on riscv unnamed float args are passed like
           integers.  But we really need them in the float argument registers
           for extendsftf2/extenddftf2.  So, do it explicitely.  */
        save_regs(1);
        எனில் (dt == VT_LDOUBLE)
          gv(RC_F(0));
        இல்லையெனில் {
            gv(RC_R(0));
            ப்ரதிஜ்ஞா(vtop->r2 < 7);
            எனில் (vtop->r2 != 1 + vtop->r) {
                EI(0x13, 0, ireg(vtop->r) + 1, ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = 1 + vtop->r;
            }
        }
        vpush_helper_func(func);
        gcall_or_jmp(1);
        vtop -= 2;
        vpushi(0);
        vtop->type.t = dt;
        எனில் (dt == VT_LDOUBLE)
          vtop->r = REG_IRET, vtop->r2 = REG_IRET+1;
        இல்லையெனில்
          vtop->r = REG_FRET;
    } இல்லையெனில் {
        ப்ரதிஜ்ஞா (dt == VT_FLOAT || dt == VT_DOUBLE);
        ப்ரதிஜ்ஞா (st == VT_FLOAT || st == VT_DOUBLE);
        rs = gv(RC_FLOAT);
        rd = get_reg(RC_FLOAT);
        எனில் (dt == VT_DOUBLE)
          EI(0x53, 0, freg(rd), freg(rs), 0x21 << 5); // fcvt.d.s RD, RS (no rm)
        இல்லையெனில்
          EI(0x53, 7, freg(rd), freg(rs), (0x20 << 5) | 1); // fcvt.s.d RD, RS (dyn rm)
        vtop->r = rd;
    }
}

/* increment tcov counter */
ST_FUNC வெறுமை gen_increment_tcov (SValue *sv)
{
    முழு r1, r2;
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

ST_FUNC வெறுமை ggoto(வெறுமை)
{
    gcall_or_jmp(0);
    vtop--;
}

ST_FUNC வெறுமை gen_vla_sp_save(முழு addr)
{
    எனில் (கீழ்_OVERFLOW(addr)) {
	o(0x37 | (5 << 7) | UPPER(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        ES(0x23, 3, 5, 2, SIGN11(addr)); // sd sp, fc(t0)
    }
    இல்லையெனில்
        ES(0x23, 3, 8, 2, addr); // sd sp, fc(s0)
}

ST_FUNC வெறுமை gen_vla_sp_restore(முழு addr)
{
    எனில் (கீழ்_OVERFLOW(addr)) {
	o(0x37 | (5 << 7) | UPPER(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        EI(0x03, 3, 2, 5, SIGN11(addr)); // ld sp, fc(t0)
    }
    இல்லையெனில்
        EI(0x03, 3, 2, 8, addr); // ld sp, fc(s0)
}

ST_FUNC வெறுமை gen_vla_alloc(CType *type, முழு align)
{
    முழு rr;
#எனில் defined(CONFIG_TCC_BCHECK)
    எனில் (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    rr = ireg(gv(RC_INT));
#எனில் defined(CONFIG_TCC_BCHECK)
    எனில் (tcc_state->do_bounds_check)
        EI(0x13, 0, rr, rr, 15+1);   // addi RR, RR, 15+1
    இல்லையெனில்
#endif
    EI(0x13, 0, rr, rr, 15);   // addi RR, RR, 15
    EI(0x13, 7, rr, rr, -16);  // andi, RR, RR, -16
    ER(0x33, 0, 2, 2, rr, 0x20); // sub sp, sp, rr
    vpop();
#எனில் defined(CONFIG_TCC_BCHECK)
    எனில் (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x00010513); /* mv a0,sp */
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_add_epilog = 1;
    }
#endif
}

ST_FUNC வெறுமை gen_clear_cache(வெறுமை)
{
    /* Zifencei extension: fence + fence.i for I/D synchronization.
       Required by RISC-V Linux ABI, present on all Linux-capable cores. */
    o(0x0ff0000f); // fence iorw, iorw
    o(0x0000100f); // fence.i
}
#endif
