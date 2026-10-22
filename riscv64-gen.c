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

#ಅನ್ಯಥಾ
#define USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"
#ಅನ್ತರ್ಭಾವ <assert.h>

#define UPPER(x)	(((unsigned)(x) + 0x800u) & 0xfffff000)
#define ಕೆಳಗಿನ_OVERFLOW(x)	UPPER(x)
#define SIGN7(x)	((((x) & 0xff) ^ 0x80) - 0x80)
#define SIGN11(x)	((((x) & 0xfff) ^ 0x800) - 0x800)

ST_DATA ಧ್ರುವ ವರ್ಣ * ಧ್ರುವ target_machine_defs =
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

ST_DATA ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ reg_classes[NB_REGS] = {
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

#ಯದಿ defined(CONFIG_TCC_BCHECK)
ಸ್ಥಿರ addr_t func_bound_offset;
ಸ್ಥಿರ unsigned long func_bound_ind;
ST_DATA ಪೂರ್ಣಾಙ್ಕ func_bound_add_epilog;
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ireg(ಪೂರ್ಣಾಙ್ಕ r)
{
    ಯದಿ (r == TREG_RA)
      ಪ್ರತ್ಯಾಗಮ 1; // ra
    ಯದಿ (r == TREG_SP)
      ಪ್ರತ್ಯಾಗಮ 2; // sp
    ಪ್ರತಿಜ್ಞಾ(r >= 0 && r < 8);
    ಪ್ರತ್ಯಾಗಮ r + 10;  // tccrX --> aX == x(10+X)
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_ireg(ಪೂರ್ಣಾಙ್ಕ r)
{
    ಪ್ರತ್ಯಾಗಮ (unsigned)r < 8 || r == TREG_RA || r == TREG_SP;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ freg(ಪೂರ್ಣಾಙ್ಕ r)
{
    ಪ್ರತಿಜ್ಞಾ(r >= 8 && r < 16);
    ಪ್ರತ್ಯಾಗಮ r - 8 + 10;  // tccfX --> faX == f(10+X)
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_freg(ಪೂರ್ಣಾಙ್ಕ r)
{
    ಪ್ರತ್ಯಾಗಮ r >= 8 && r < 16;
}

ST_FUNC ಶೂನ್ಯ o(unsigned ಪೂರ್ಣಾಙ್ಕ c)
{
    ಪೂರ್ಣಾಙ್ಕ ind1 = ind + 4;
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    write32le(cur_text_section->data + ind, c);
    ind = ind1;
}

ಸ್ಥಿರ ಶೂನ್ಯ EIu(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    o(opcode | (func3 << 12) | (rd << 7) | (rs1 << 15) | (imm << 20));
}

ಸ್ಥಿರ ಶೂನ್ಯ ER(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t rs2, uint32_t func7)
{
    o(opcode | func3 << 12 | rd << 7 | rs1 << 15 | rs2 << 20 | func7 << 25);
}

ಸ್ಥಿರ ಶೂನ್ಯ EI(uint32_t opcode, uint32_t func3,
               uint32_t rd, uint32_t rs1, uint32_t imm)
{
    ಪ್ರತಿಜ್ಞಾ(! ಕೆಳಗಿನ_OVERFLOW(imm));
    EIu(opcode, func3, rd, rs1, imm);
}

ಸ್ಥಿರ ಶೂನ್ಯ ES(uint32_t opcode, uint32_t func3,
               uint32_t rs1, uint32_t rs2, uint32_t imm)
{
    ಪ್ರತಿಜ್ಞಾ(! ಕೆಳಗಿನ_OVERFLOW(imm));
    o(opcode | (func3 << 12) | ((imm & 0x1f) << 7) | (rs1 << 15)
      | (rs2 << 20) | ((imm >> 5) << 25));
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC ಶೂನ್ಯ gsym_addr(ಪೂರ್ಣಾಙ್ಕ t_, ಪೂರ್ಣಾಙ್ಕ a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    ಯಾವತ್ (t) {
        unsigned ವರ್ಣ *ptr = cur_text_section->data + t;
        uint32_t next = read32le(ptr);
        uint32_t r = a - t, imm;
        ಯದಿ ((r + (1 << 21)) & ~((1U << 22) - 2))
          tcc_error("out-of-range branch chain");
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        write32le(ptr, r == 4 ? 0x33 : 0x6f | imm); // nop || j imm
        t = next;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ load_symofs(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv, ಪೂರ್ಣಾಙ್ಕ forstore, ಪೂರ್ಣಾಙ್ಕ *new_fc)
{
    ಪೂರ್ಣಾಙ್ಕ rr, doload = 0, large_addend = 0;
    ಪೂರ್ಣಾಙ್ಕ fc = sv->c.i, v = sv->r & VT_VALMASK;
    ಯದಿ (sv->r & VT_SYM) {
        Sym label = {0};
        ಪ್ರತಿಜ್ಞಾ(v == VT_CONST);
        ಯದಿ (sv->sym->type.t & VT_TLS) {
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
            ಪ್ರತ್ಯಾಗಮ rr;
        }
        ಯದಿ (sv->sym->type.t & VT_STATIC) { // XXX do this per linker relax
            greloca(cur_text_section, sv->sym, ind,
                    R_RISCV_PCREL_HI20, sv->c.i);
            *new_fc = 0;
        } ಅನ್ಯಥಾ {
            ಯದಿ (ಕೆಳಗಿನ_OVERFLOW(fc)){
              large_addend = 1;
            }
            greloca(cur_text_section, sv->sym, ind,
                    R_RISCV_GOT_HI20, 0);
            doload = 1;
        }
        label.type.t = VT_VOID | VT_STATIC;
	ಯದಿ (!nocode_wanted)
            put_extern_sym(&label, cur_text_section, ind, 0);
        rr = is_ireg(r) ? ireg(r) : 5;
        o(0x17 | (rr << 7));   // auipc RR, 0 %pcrel_hi(sym)+addend
        greloca(cur_text_section, &label, ind,
                doload || !forstore
                  ? R_RISCV_PCREL_LO12_I : R_RISCV_PCREL_LO12_S, 0);
        ಯದಿ (doload) {
            EI(0x03, 3, rr, rr, 0); // ld RR, 0(RR)
            ಯದಿ (large_addend) {
                o(0x37 | (6 << 7) | UPPER(fc)); //lui t1, high(fc)
                ER(0x33, 0, rr, rr, 6, 0); // add RR, RR, t1
                *new_fc = SIGN11(fc);
            }
        }
    } ಅನ್ಯಥಾ ಯದಿ (v == VT_LOCAL || v == VT_LLOCAL) {
        rr = 8; // s0
        ಯದಿ (fc != sv->c.i)
          tcc_error("unimp: store(giant local off) (0x%lx)", (long)sv->c.i);
        ಯದಿ (ಕೆಳಗಿನ_OVERFLOW(fc)) {
            rr = is_ireg(r) ? ireg(r) : 5; // t0
            o(0x37 | (rr << 7) | UPPER(fc)); //lui RR, upper(fc)
            ER(0x33, 0, rr, rr, 8, 0); // add RR, RR, s0
            *new_fc = SIGN11(fc);
        }
    } ಅನ್ಯಥಾ
      tcc_error("uhh");
    ಪ್ರತ್ಯಾಗಮ rr;
}

ಸ್ಥಿರ ಶೂನ್ಯ load_large_constant(ಪೂರ್ಣಾಙ್ಕ rr, ಪೂರ್ಣಾಙ್ಕ fc, uint32_t pi)
{
    ಯದಿ (fc < 0)
	pi++;
    o(0x37 | (rr << 7) | UPPER(pi)); // lui RR, up(up(fc))
    EI(0x13, 0, rr, rr, SIGN11(pi));   // addi RR, RR, lo(up(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((unsigned)fc + (1 << 19)) >> 20)); // addi RR, RR, up(lo(fc))
    EI(0x13, 1, rr, rr, 12); // slli RR, RR, 12
    EI(0x13, 0, rr, rr, SIGN11(((unsigned)fc + (1 << 7)) >> 8));  // addi RR, RR, lo1(lo(fc))
    EI(0x13, 1, rr, rr, 8); // slli RR, RR, 8
}

ST_FUNC ಶೂನ್ಯ load(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ fr = sv->r;
    ಪೂರ್ಣಾಙ್ಕ v = fr & VT_VALMASK;
    ಪೂರ್ಣಾಙ್ಕ rr = is_ireg(r) ? ireg(r) : freg(r);
    ಪೂರ್ಣಾಙ್ಕ fc = sv->c.i;
    ಪೂರ್ಣಾಙ್ಕ bt = sv->type.t & VT_BTYPE;
    ಪೂರ್ಣಾಙ್ಕ align, size;
    ಯದಿ (fr & VT_LVAL) {
        ಪೂರ್ಣಾಙ್ಕ func3, opcode = is_freg(r) ? 0x07 : 0x03, br;
        size = type_size(&sv->type, &align);
        ಪ್ರತಿಜ್ಞಾ (!is_freg(r) || bt == VT_FLOAT || bt == VT_DOUBLE);
        ಯದಿ (bt == VT_PTR || bt == VT_FUNC) /* XXX should be done in generic code */
          size = PTR_SIZE;
        func3 = size == 1 ? 0 : size == 2 ? 1 : size == 4 ? 2 : 3;
        ಯದಿ (size < 4 && !is_float(sv->type.t) && (sv->type.t & VT_UNSIGNED))
          func3 |= 4;
        ಯದಿ (v == VT_LOCAL || (fr & VT_SYM)) {
            br = load_symofs(r, sv, 0, &fc);
        } ಅನ್ಯಥಾ ಯದಿ (v < VT_CONST) {
            br = ireg(v);
            /*if (LOW_OVERFLOW(fc))
              tcc_error("unimp: load(large addend) (0x%x)", fc);*/
            fc = 0; // XXX store ofs in LVAL(reg)
        } ಅನ್ಯಥಾ ಯದಿ (v == VT_LLOCAL) {
            br = load_symofs(r, sv, 0, &fc);
            EI(0x03, 3, rr, br, fc); // ld RR, fc(BR)
            br = rr;
            fc = 0;
        } ಅನ್ಯಥಾ ಯದಿ (v == VT_CONST) {
            int64_t si = sv->c.i;
            si >>= 32;
            ಯದಿ (si != 0) {
		load_large_constant(rr, fc, si);
                fc = SIGN7(fc);
            } ಅನ್ಯಥಾ {
                o(0x37 | (rr << 7) | UPPER(fc)); //lui RR, upper(fc)
                fc = SIGN11(fc);
	    }
            br = rr;
	} ಅನ್ಯಥಾ {
            tcc_error("unimp: load(non-local lval)");
        }
        EI(opcode, func3, rr, br, fc); // l[bhwd][u] / fl[wd] RR, fc(BR)
    } ಅನ್ಯಥಾ ಯದಿ (v == VT_CONST) {
        ಪೂರ್ಣಾಙ್ಕ rb = 0, do32bit = 8, zext = 0;
        ಯದಿ (is_float(sv->type.t) && bt != VT_LDOUBLE) {
            /* load float/double constant: move bit pattern from int reg */
            uint64_t val = sv->c.i;
            ಪೂರ್ಣಾಙ್ಕ is_dbl = bt == VT_DOUBLE;
            ಯದಿ (val == 0) {
                o(0x53 | (rr << 7) | ((unsigned)(0x78 | is_dbl) << 25));
                ಪ್ರತ್ಯಾಗಮ;
            }
            ಯದಿ (is_dbl) {
                load_large_constant(6, (ಪೂರ್ಣಾಙ್ಕ)val, (ಪೂರ್ಣಾಙ್ಕ)(val >> 32));
            } ಅನ್ಯಥಾ {
                ಯದಿ (ಕೆಳಗಿನ_OVERFLOW(fc))
                    o(0x37 | (6 << 7) | UPPER(fc)); // lui t1, upper
                EI(0x13 | 8, 0, 6, ಕೆಳಗಿನ_OVERFLOW(fc) ? 6 : 0, SIGN11(fc)); // addiw t1,...
            }
            o(0x53 | (rr << 7) | (6 << 15) | ((unsigned)(0x78 | is_dbl) << 25));
            ಪ್ರತ್ಯಾಗಮ;
        }
        ಪ್ರತಿಜ್ಞಾ(is_ireg(r) || bt == VT_LDOUBLE);
        ಯದಿ (fr & VT_SYM) {
            rb = load_symofs(r, sv, 0, &fc);
            do32bit = 0;
        }
        ಯದಿ (do32bit && fc != sv->c.i) {
            int64_t si = sv->c.i;
            si >>= 32;
            ಯದಿ (si != 0) {
		load_large_constant(rr, fc, si);
                fc = SIGN7(fc);
                rb = rr;
                do32bit = 0;
            } ಅನ್ಯಥಾ ಯದಿ (bt == VT_LLONG) {
                /* A 32bit unsigned constant for a 64bit type.
                   lui always sign extends, so we need to do an explicit zext.*/
                zext = 1;
            }
        }
        ಯದಿ (ಕೆಳಗಿನ_OVERFLOW(fc))
            o(0x37 | (rr << 7) | UPPER(fc)), rb = rr; //lui RR, upper(fc)
        ಯದಿ (fc || (rr != rb) || do32bit || (fr & VT_SYM))
          EI(0x13 | do32bit, 0, rr, rb, SIGN11(fc)); // addi[w] R, x0|R, FC
        ಯದಿ (zext) {
            EI(0x13, 1, rr, rr, 32); // slli RR, RR, 32
            EI(0x13, 5, rr, rr, 32); // srli RR, RR, 32
        }
    } ಅನ್ಯಥಾ ಯದಿ (v == VT_LOCAL) {
        ಪೂರ್ಣಾಙ್ಕ br = load_symofs(r, sv, 0, &fc);
        ಪ್ರತಿಜ್ಞಾ(is_ireg(r));
        EI(0x13, 0, rr, br, fc); // addi R, s0, FC
    } ಅನ್ಯಥಾ ಯದಿ (v < VT_CONST) { /* reg-reg */
        //assert(!fc); XXX support offseted regs
        ಯದಿ (is_freg(r) && is_freg(v))
          ER(0x53, 0, rr, freg(v), freg(v), bt == VT_DOUBLE ? 0x11 : 0x10); //fsgnj.[sd] RR, V, V == fmv.[sd] RR, V
        ಅನ್ಯಥಾ ಯದಿ (is_ireg(r) && is_ireg(v))
          EI(0x13, 0, rr, ireg(v), 0); // addi RR, V, 0 == mv RR, V
        ಅನ್ಯಥಾ {
            ಪೂರ್ಣಾಙ್ಕ func7 = is_ireg(r) ? 0x70 : 0x78;
            size = type_size(&sv->type, &align);
            ಯದಿ (size == 8)
              func7 |= 1;
            ಪ್ರತಿಜ್ಞಾ(size == 4 || size == 8);
            o(0x53 | (rr << 7) | ((is_freg(v) ? freg(v) : ireg(v)) << 15)
              | ((unsigned)func7 << 25)); // fmv.{w.x, x.w, d.x, x.d} RR, VR
        }
    } ಅನ್ಯಥಾ ಯದಿ (v == VT_CMP) {
        ಪೂರ್ಣಾಙ್ಕ op = vtop->cmp_op;
        ಪೂರ್ಣಾಙ್ಕ a = vtop->cmp_r & 0xff;
        ಪೂರ್ಣಾಙ್ಕ b = (vtop->cmp_r >> 8) & 0xff;
        ಪೂರ್ಣಾಙ್ಕ inv = 0;
        ವಿಕಲ್ಪ (op) {
            ಪಕ್ಷ TOK_ULT:
            ಪಕ್ಷ TOK_UGE:
            ಪಕ್ಷ TOK_ULE:
            ಪಕ್ಷ TOK_UGT:
            ಪಕ್ಷ TOK_LT:
            ಪಕ್ಷ TOK_GE:
            ಪಕ್ಷ TOK_LE:
            ಪಕ್ಷ TOK_GT:
                ಯದಿ (op & 1) { // remove [U]GE,GT
                    inv = 1;
                    op--;
                }
                ಯದಿ ((op & 7) == 6) { // [U]LE
                    ಪೂರ್ಣಾಙ್ಕ t = a; a = b; b = t;
                    inv ^= 1;
                }
                ER(0x33, (op > TOK_UGT) ? 2 : 3, rr, a, b, 0); // slt[u] d, a, b
                ಯದಿ (inv)
                  EI(0x13, 4, rr, rr, 1); // xori d, d, 1
                ಭಙ್ಗ;
            ಪಕ್ಷ TOK_NE:
            ಪಕ್ಷ TOK_EQ:
                ಯದಿ (rr != a || b)
                  ER(0x33, 0, rr, a, b, 0x20); // sub d, a, b
                ಯದಿ (op == TOK_NE)
                  ER(0x33, 3, rr, 0, rr, 0); // sltu d, x0, d == snez d,d
                ಅನ್ಯಥಾ
                  EI(0x13, 3, rr, rr, 1); // sltiu d, d, 1 == seqz d,d
                ಭಙ್ಗ;
        }
    } ಅನ್ಯಥಾ ಯದಿ ((v & ~1) == VT_JMP) {
        ಪೂರ್ಣಾಙ್ಕ t = v & 1;
        ಪ್ರತಿಜ್ಞಾ(is_ireg(r));
        EI(0x13, 0, rr, 0, t);      // addi RR, x0, t
        gjmp_addr(ind + 8);
        gsym(fc);
        EI(0x13, 0, rr, 0, t ^ 1);  // addi RR, x0, !t
    } ಅನ್ಯಥಾ
      tcc_error("unimp: load(non-const)");
}

ST_FUNC ಶೂನ್ಯ store(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ fr = sv->r & VT_VALMASK;
    ಪೂರ್ಣಾಙ್ಕ rr = is_ireg(r) ? ireg(r) : freg(r), ptrreg;
    ಪೂರ್ಣಾಙ್ಕ fc = sv->c.i;
    ಪೂರ್ಣಾಙ್ಕ bt = sv->type.t & VT_BTYPE;
    ಪೂರ್ಣಾಙ್ಕ align, size = type_size(&sv->type, &align);
    ಪ್ರತಿಜ್ಞಾ(!is_float(bt) || is_freg(r) || bt == VT_LDOUBLE);
    /* long doubles are in two integer registers, but the load/store
       primitives only deal with one, so do as if it's one reg.  */
    ಯದಿ (bt == VT_LDOUBLE)
      size = align = 8;
    ಯದಿ (bt == VT_STRUCT)
      tcc_error("unimp: store(struct)");
    ಯದಿ (size > 8)
      tcc_error("unimp: large sized store");
    ಪ್ರತಿಜ್ಞಾ(sv->r & VT_LVAL);
    ಯದಿ (fr == VT_LOCAL || (sv->r & VT_SYM)) {
        ptrreg = load_symofs(-1, sv, 1, &fc);
    } ಅನ್ಯಥಾ ಯದಿ (fr < VT_CONST) {
        ptrreg = ireg(fr);
        /*if (LOW_OVERFLOW(fc))
          tcc_error("unimp: store(large addend) (0x%x)", fc);*/
        fc = 0; // XXX support offsets regs
    } ಅನ್ಯಥಾ ಯದಿ (fr == VT_CONST) {
        int64_t si = sv->c.i;
        ptrreg = 8; // s0
        si >>= 32;
        ಯದಿ (si != 0) {
	    load_large_constant(ptrreg, fc, si);
            fc = SIGN7(fc);
        } ಅನ್ಯಥಾ {
            o(0x37 | (ptrreg << 7) | UPPER(fc)); //lui RR, upper(fc)
            fc = SIGN11(fc);
	}
    } ಅನ್ಯಥಾ
      tcc_error("implement me: %s(!local)", __FUNCTION__);
    ES(is_freg(r) ? 0x27 : 0x23,                          // fs... | s...
       size == 1 ? 0 : size == 2 ? 1 : size == 4 ? 2 : 3, // ... [wd] | [bhwd]
       ptrreg, rr, fc);                                   // RR, fc(base)
}

ಸ್ಥಿರ ಶೂನ್ಯ gcall_or_jmp(ಪೂರ್ಣಾಙ್ಕ docall)
{
    ಪೂರ್ಣಾಙ್ಕ tr = docall ? 1 : 5; // ra or t0
    ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
        ((vtop->r & VT_SYM) && vtop->c.i == (ಪೂರ್ಣಾಙ್ಕ)vtop->c.i)) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind,
                R_RISCV_CALL_PLT, (ಪೂರ್ಣಾಙ್ಕ)vtop->c.i);
        o(0x17 | (tr << 7));   // auipc TR, 0 %call(func)
        EI(0x67, 0, tr, tr, 0);// jalr  TR, r(TR)
    } ಅನ್ಯಥಾ ಯದಿ (vtop->r < VT_CONST) {
        ಪೂರ್ಣಾಙ್ಕ r = ireg(vtop->r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    } ಅನ್ಯಥಾ {
        ಪೂರ್ಣಾಙ್ಕ r = TREG_RA;
        load(r, vtop);
        r = ireg(r);
        EI(0x67, 0, tr, r, 0);      // jalr TR, 0(R)
    }
}

#ಯದಿ defined(CONFIG_TCC_BCHECK)

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_call(ಪೂರ್ಣಾಙ್ಕ v)
{
    Sym *sym = external_helper_sym(v);

    greloca(cur_text_section, sym, ind, R_RISCV_CALL_PLT, 0);
    o(0x17 | (1 << 7));   // auipc TR, 0 %call(func)
    EI(0x67, 0, 1, 1, 0); // jalr  TR, r(TR)
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_prolog(ಶೂನ್ಯ)
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

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_epilog(ಶೂನ್ಯ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    Sym label = {0};

    ಪೂರ್ಣಾಙ್ಕ offset_modified = func_bound_offset != lbounds_section->data_offset;

    ಯದಿ (!offset_modified && !func_bound_add_epilog)
        ಪ್ರತ್ಯಾಗಮ;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, ಪರಿಮಾಣ(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    label.type.t = VT_VOID | VT_STATIC;
    /* generate bound local allocation */
    ಯದಿ (offset_modified) {
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

ಸ್ಥಿರ ಶೂನ್ಯ reg_pass_rec(CType *type, ಪೂರ್ಣಾಙ್ಕ *rc, ಪೂರ್ಣಾಙ್ಕ *fieldofs, ಪೂರ್ಣಾಙ್ಕ ofs)
{
    ಯದಿ ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *f;
        ಯದಿ (type->ref->type.t == VT_UNION)
          rc[0] = -1;
        ಅನ್ಯಥಾ ಪ್ರತಿ (f = type->ref->next; f; f = f->next)
          reg_pass_rec(&f->type, rc, fieldofs, ofs + f->c);
    } ಅನ್ಯಥಾ ಯದಿ (type->t & VT_ARRAY) {
        ಯದಿ (type->ref->c < 0 || type->ref->c > 2)
          rc[0] = -1;
        ಅನ್ಯಥಾ {
            ಪೂರ್ಣಾಙ್ಕ a, sz = type_size(&type->ref->type, &a);
            reg_pass_rec(&type->ref->type, rc, fieldofs, ofs);
            ಯದಿ (rc[0] > 2 || (rc[0] == 2 && type->ref->c > 1))
              rc[0] = -1;
            ಅನ್ಯಥಾ ಯದಿ (type->ref->c == 2 && rc[0] && rc[1] == RC_FLOAT) {
              rc[++rc[0]] = RC_FLOAT;
              fieldofs[rc[0]] = ((ofs + sz) << 4)
                                | (type->ref->type.t & VT_BTYPE);
            } ಅನ್ಯಥಾ ಯದಿ (type->ref->c == 2)
              rc[0] = -1;
        }
    } ಅನ್ಯಥಾ ಯದಿ (rc[0] == 2 || rc[0] < 0 || (type->t & VT_BTYPE) == VT_LDOUBLE)
      rc[0] = -1;
    ಅನ್ಯಥಾ ಯದಿ (!rc[0] || rc[1] == RC_FLOAT || is_float(type->t)) {
      rc[++rc[0]] = is_float(type->t) ? RC_FLOAT : RC_INT;
      fieldofs[rc[0]] = (ofs << 4) | ((type->t & VT_BTYPE) == VT_PTR ? VT_LLONG : type->t & VT_BTYPE);
    } ಅನ್ಯಥಾ
      rc[0] = -1;
}

ಸ್ಥಿರ ಶೂನ್ಯ reg_pass(CType *type, ಪೂರ್ಣಾಙ್ಕ *prc, ಪೂರ್ಣಾಙ್ಕ *fieldofs, ಪೂರ್ಣಾಙ್ಕ named)
{
    prc[0] = 0;
    reg_pass_rec(type, prc, fieldofs, 0);
    ಯದಿ (prc[0] <= 0 || !named) {
        ಪೂರ್ಣಾಙ್ಕ align, size = type_size(type, &align);
        prc[0] = (size + 7) >> 3;
        prc[1] = prc[2] = RC_INT;
        fieldofs[1] = (0 << 4) | (size <= 1 ? VT_BYTE : size <= 2 ? VT_SHORT : size <= 4 ? VT_INT : VT_LLONG);
        fieldofs[2] = (8 << 4) | (size <= 9 ? VT_BYTE : size <= 10 ? VT_SHORT : size <= 12 ? VT_INT : VT_LLONG);
    }
}

ST_FUNC ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಙ್ಕ nb_args)
{
    ಪೂರ್ಣಾಙ್ಕ i, align, size, areg[2];
    ಪೂರ್ಣಾಙ್ಕ *info = tcc_malloc((nb_args + 1) * ಪರಿಮಾಣ (ಪೂರ್ಣಾಙ್ಕ));
    ಪೂರ್ಣಾಙ್ಕ ರಾಶಿ_adj = 0, tempspace = 0, ರಾಶಿ_add, ofs, splitofs = 0;
    ಪೂರ್ಣಾಙ್ಕ old = (vtop[-nb_args].type.ref->f.func_type == FUNC_OLD);
    SValue *sv;
    Sym *sa;

#ifdef CONFIG_TCC_BCHECK
    ಪೂರ್ಣಾಙ್ಕ bc_save = tcc_state->do_bounds_check;
    ಯದಿ (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    areg[0] = 0; /* int arg regs */
    areg[1] = 8; /* float arg regs */
    sa = vtop[-nb_args].type.ref->next;
    ಪ್ರತಿ (i = 0; i < nb_args; i++) {
        ಪೂರ್ಣಾಙ್ಕ nregs, byref = 0, tempofs;
        ಪೂರ್ಣಾಙ್ಕ prc[3], fieldofs[3];
        sv = &vtop[1 + i - nb_args];
        sv->type.t &= ~VT_ARRAY; // XXX this should be done in tccgen.c
        size = type_size(&sv->type, &align);
        ಯದಿ (size > 16) {
            ಯದಿ (align < XLEN)
              align = XLEN;
            tempspace = (tempspace + align - 1) & -align;
            tempofs = tempspace;
            tempspace += size;
            size = align = 8;
            byref = 64 | (tempofs << 7);
        }
        reg_pass(&sv->type, prc, fieldofs, old || sa != 0);
        ಯದಿ (!old && !sa && align == 2*XLEN && size <= 2*XLEN)
          areg[0] = (areg[0] + 1) & ~1;
        nregs = prc[0];
        ಯದಿ (size == 0)
            info[i] = 0;
        ಅನ್ಯಥಾ ಯದಿ ((prc[1] == RC_INT && areg[0] >= 8)
            || (prc[1] == RC_FLOAT && areg[1] >= 16)
            || (nregs == 2 && prc[1] == RC_FLOAT && prc[2] == RC_FLOAT
                && areg[1] >= 15)
            || (nregs == 2 && prc[1] != prc[2]
                && (areg[1] >= 16 || areg[0] >= 8))) {
            info[i] = 32;
            ಯದಿ (align < XLEN)
              align = XLEN;
            ರಾಶಿ_adj += (size + align - 1) & -align;
            ಯದಿ (!old && !sa) /* one vararg on stack forces the rest on stack */
              areg[0] = 8, areg[1] = 16;
        } ಅನ್ಯಥಾ {
            info[i] = areg[prc[1] - 1]++;
            ಯದಿ (!byref)
              info[i] |= (fieldofs[1] & VT_BTYPE) << 12;
            ಪ್ರತಿಜ್ಞಾ(!(fieldofs[1] >> 4));
            ಯದಿ (nregs == 2) {
                ಯದಿ (prc[2] == RC_FLOAT || areg[0] < 8)
                  info[i] |= (1 + areg[prc[2] - 1]++) << 7;
                ಅನ್ಯಥಾ {
                    info[i] |= 16;
                    ರಾಶಿ_adj += 8;
                }
                ಯದಿ (!byref) {
                    ಪ್ರತಿಜ್ಞಾ((fieldofs[2] >> 4) < 2048);
                    info[i] |= fieldofs[2] << (12 + 4); // includes offset
                }
            }
        }
        info[i] |= byref;
        ಯದಿ (sa)
          sa = sa->next;
    }
    ರಾಶಿ_adj = (ರಾಶಿ_adj + 15) & -16;
    tempspace = (tempspace + 15) & -16;
    ರಾಶಿ_add = ರಾಶಿ_adj + tempspace;

    ಯದಿ (ರಾಶಿ_add) {
        ಯದಿ (ರಾಶಿ_add >= 0x800) {
            o(0x37 | (5 << 7) | UPPER(-ರಾಶಿ_add)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(-ರಾಶಿ_add)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        ಅನ್ಯಥಾ
            EI(0x13, 0, 2, 2, -ರಾಶಿ_add);   // addi sp, sp, -adj
        ಪ್ರತಿ (i = ofs = 0; i < nb_args; i++) {
            ಯದಿ (info[i] & (64 | 32)) {
                vrotb(nb_args - i);
                size = type_size(&vtop->type, &align);
                ಯದಿ (info[i] & 64) {
                    vset(&char_pointer_type, TREG_SP, 0);
                    vpushi(ರಾಶಿ_adj + (info[i] >> 7));
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
                ಯದಿ (info[i] & 32) {
                    ಯದಿ (align < XLEN)
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
            } ಅನ್ಯಥಾ ಯದಿ (info[i] & 16) {
                ಪ್ರತಿಜ್ಞಾ(!splitofs);
                splitofs = ofs;
                ofs += 8;
            }
        }
    }
    ಪ್ರತಿ (i = 0; i < nb_args; i++) {
        ಪೂರ್ಣಾಙ್ಕ ii = info[nb_args - 1 - i], r = ii, r2 = r;
        ಯದಿ (!(r & 32)) {
            CType origtype;
            ಪೂರ್ಣಾಙ್ಕ loadt;
            r &= 15;
            r2 = r2 & 64 ? 0 : (r2 >> 7) & 31;
            ಪ್ರತಿಜ್ಞಾ(r2 <= 16);
            vrotb(i+1);
            origtype = vtop->type;
            size = type_size(&vtop->type, &align);
            ಯದಿ (size == 0)
                ಗಚ್ಛ done;
            loadt = vtop->type.t & VT_BTYPE;
            ಯದಿ (loadt == VT_STRUCT) {
                loadt = (ii >> 12) & VT_BTYPE;
            }
            ಯದಿ (info[nb_args - 1 - i] & 16) {
                ಪ್ರತಿಜ್ಞಾ(!r2);
                r2 = 1 + TREG_RA;
            }
            ಯದಿ (loadt == VT_LDOUBLE) {
                ಪ್ರತಿಜ್ಞಾ(r2);
                r2--;
            } ಅನ್ಯಥಾ ಯದಿ (r2) {
                test_lvalue();
                vpushv(vtop);
            }
            vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
            gv(r < 8 ? RC_R(r) : RC_F(r - 8));
            vtop->type = origtype;

            ಯದಿ (r2 && loadt != VT_LDOUBLE) {
                r2--;
                ಪ್ರತಿಜ್ಞಾ(r2 < 16 || r2 == TREG_RA);
                vswap();
                gaddrof();
                vtop->type = char_pointer_type;
                vpushi(ii >> 20);
#ifdef CONFIG_TCC_BCHECK
		ಯದಿ ((origtype.t & VT_BTYPE) == VT_STRUCT)
                    tcc_state->do_bounds_check = 0;
#endif
                gen_op('+');
#ifdef CONFIG_TCC_BCHECK
		tcc_state->do_bounds_check = bc_save;
#endif
                indir();
                vtop->type = origtype;
                loadt = vtop->type.t & VT_BTYPE;
                ಯದಿ (loadt == VT_STRUCT) {
                    loadt = (ii >> 16) & VT_BTYPE;
                }
                save_reg_upstack(r2, 1);
                vtop->type.t = loadt | (vtop->type.t & VT_UNSIGNED);
                load(r2, vtop);
                ಪ್ರತಿಜ್ಞಾ(r2 < VT_CONST);
                vtop--;
                vtop->r2 = r2;
            }
            ಯದಿ (info[nb_args - 1 - i] & 16) {
                ES(0x23, 3, 2, ireg(vtop->r2), splitofs); // sd t0, ofs(sp)
                vtop->r2 = VT_CONST;
            } ಅನ್ಯಥಾ ಯದಿ (loadt == VT_LDOUBLE && vtop->r2 != r2) {
                ಪ್ರತಿಜ್ಞಾ(vtop->r2 <= 7 && r2 <= 7);
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
    ಯದಿ (ರಾಶಿ_add) {
        ಯದಿ (ರಾಶಿ_add >= 0x800) {
            o(0x37 | (5 << 7) | UPPER(ರಾಶಿ_add)); //lui t0, upper(v)
            EI(0x13, 0, 5, 5, SIGN11(ರಾಶಿ_add)); // addi t0, t0, lo(v)
            ER(0x33, 0, 2, 2, 5, 0); // add sp, sp, t0
        }
        ಅನ್ಯಥಾ
            EI(0x13, 0, 2, 2, ರಾಶಿ_add);      // addi sp, sp, adj
   }
   tcc_free(info);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ func_sub_sp_offset, ಅಂಕೆ_va_regs, func_va_list_ofs;

ST_FUNC ಶೂನ್ಯ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ಪೂರ್ಣಾಙ್ಕ i, addr, align, size;
    ಪೂರ್ಣಾಙ್ಕ param_addr = 0;
    ಪೂರ್ಣಾಙ್ಕ areg[2];
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
    ಯದಿ (size > 2 * XLEN) {
        loc -= 8;
        func_vc = loc;
        ES(0x23, 3, 8, 10 + areg[0]++, loc); // sd a0, loc(s0)
    }
    /* define parameters */
    ಯಾವತ್ ((sym = sym->next) != ರಿಕ್ತ) {
        ಪೂರ್ಣಾಙ್ಕ byref = 0;
        ಪೂರ್ಣಾಙ್ಕ regcount;
        ಪೂರ್ಣಾಙ್ಕ prc[3], fieldofs[3];
        type = &sym->type;
        size = type_size(type, &align);
        ಯದಿ (size > 2 * XLEN) {
            type = &char_pointer_type;
            size = align = byref = 8;
        }
        reg_pass(type, prc, fieldofs, 1);
        regcount = prc[0];
        ಯದಿ (areg[prc[1] - 1] >= 8
            || (regcount == 2
                && ((prc[1] == RC_FLOAT && prc[2] == RC_FLOAT && areg[1] >= 7)
                    || (prc[1] != prc[2] && (areg[1] >= 8 || areg[0] >= 8))))) {
            ಯದಿ (align < XLEN)
              align = XLEN;
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += size;
        } ಅನ್ಯಥಾ {
            loc -= regcount * 8; // XXX could reserve only 'size' bytes
            param_addr = loc;
            ಪ್ರತಿ (i = 0; i < regcount; i++) {
                ಯದಿ (areg[prc[1+i] - 1] >= 8) {
                    ಪ್ರತಿಜ್ಞಾ(i == 1 && regcount == 2 && !(addr & 7));
                    EI(0x03, 3, 5, 8, addr); // ld t0, addr(s0)
                    addr += 8;
                    ES(0x23, 3, 8, 5, loc + i*8); // sd t0, loc(s0)
                } ಅನ್ಯಥಾ ಯದಿ (prc[1+i] == RC_FLOAT) {
                    ES(0x27, (size / regcount) == 4 ? 2 : 3, 8, 10 + areg[1]++, loc + (fieldofs[i+1] >> 4)); // fs[wd] FAi, loc(s0)
                } ಅನ್ಯಥಾ {
                    ES(0x23, 3, 8, 10 + areg[0]++, loc + i*8); // sd aX, loc(s0) // XXX
                }
            }
        }
        gfunc_set_param(sym, param_addr, byref);
    }
    func_va_list_ofs = addr;
    ಅಂಕೆ_va_regs = 0;
    ಯದಿ (func_var) {
        ಪ್ರತಿ (; areg[0] < 8; areg[0]++) {
            ಅಂಕೆ_va_regs++;
            ES(0x23, 3, 8, 10 + areg[0], -8 + ಅಂಕೆ_va_regs * 8); // sd aX, loc(s0)
        }
    }
#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಙ್ಕ variadic, CType *ret,
                       ಪೂರ್ಣಾಙ್ಕ *ret_align, ಪೂರ್ಣಾಙ್ಕ *regsize)
{
    ಪೂರ್ಣಾಙ್ಕ align, size = type_size(vt, &align), nregs;
    ಪೂರ್ಣಾಙ್ಕ prc[3], fieldofs[3];
    *ret_align = 1;
    *regsize = 8;
    ಯದಿ (size > 16)
      ಪ್ರತ್ಯಾಗಮ 0;
    reg_pass(vt, prc, fieldofs, 1);
    nregs = prc[0];
    ಯದಿ (nregs == 2 && prc[1] != prc[2])
      ಪ್ರತ್ಯಾಗಮ -1;  /* generic code can't deal with this case */
    ಯದಿ (prc[1] == RC_FLOAT) {
        *regsize = size / nregs;
    }
    ret->t = fieldofs[1] & VT_BTYPE;
    ret->ref = ರಿಕ್ತ;
    ಪ್ರತ್ಯಾಗಮ nregs;
}

ST_FUNC ಶೂನ್ಯ arch_transfer_ret_regs(ಪೂರ್ಣಾಙ್ಕ aftercall)
{
    ಪೂರ್ಣಾಙ್ಕ prc[3], fieldofs[3];
    reg_pass(&vtop->type, prc, fieldofs, 1);
    ಪ್ರತಿಜ್ಞಾ(prc[0] == 2 && prc[1] != prc[2] && !(fieldofs[1] >> 4));
    ಪ್ರತಿಜ್ಞಾ(vtop->r == (VT_LOCAL | VT_LVAL));
    vpushv(vtop);
    vtop->type.t = fieldofs[1] & VT_BTYPE;
    (aftercall ? store : load)(prc[1] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop->c.i += fieldofs[2] >> 4;
    vtop->type.t = fieldofs[2] & VT_BTYPE;
    (aftercall ? store : load)(prc[2] == RC_INT ? REG_IRET : REG_FRET, vtop);
    vtop--;
}

ST_FUNC ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ v, saved_ind, d, large_ofs_ind;

#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    loc = (loc - ಅಂಕೆ_va_regs * 8);
    d = v = (-loc + 15) & -16;

    EI(0x13, 0, 2, 8, ಅಂಕೆ_va_regs * 8); // addi sp, s0, num_va_regs*8
    EI(0x03, 3, 1, 8, -8); // ld ra, -8(s0)
    EI(0x03, 3, 8, 8, -16); // ld s0, -16(s0)
    EI(0x67, 0, 0, 1, 0); // jalr x0, 0(x1), aka ret

    large_ofs_ind = ind;
    ಯದಿ (v >= (1 << 11)) {
        d = 16;
        EI(0x13, 0, 8, 2, d - ಅಂಕೆ_va_regs * 8);      // addi s0, sp, d
        o(0x37 | (5 << 7) | UPPER(v-16)); //lui t0, upper(v)
        EI(0x13, 0, 5, 5, SIGN11(v-16)); // addi t0, t0, lo(v)
        ER(0x33, 0, 2, 2, 5, 0x20); // sub sp, sp, t0
        gjmp_addr(func_sub_sp_offset + 5*4);
    }
    saved_ind = ind;

    ind = func_sub_sp_offset;
    EI(0x13, 0, 2, 2, -d);     // addi sp, sp, -d
    ES(0x23, 3, 2, 1, d - 8 - ಅಂಕೆ_va_regs * 8);  // sd ra, d-8(sp)
    ES(0x23, 3, 2, 8, d - 16 - ಅಂಕೆ_va_regs * 8); // sd s0, d-16(sp)
    ಯದಿ (v < (1 << 11))
      EI(0x13, 0, 8, 2, d - ಅಂಕೆ_va_regs * 8);      // addi s0, sp, d
    ಅನ್ಯಥಾ
      gjmp_addr(large_ofs_ind);
    ಯದಿ ((ind - func_sub_sp_offset) != 5*4)
      EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
    ind = saved_ind;
}

ST_FUNC ಶೂನ್ಯ gen_va_start(ಶೂನ್ಯ)
{
    vtop--;
    vset(&char_pointer_type, VT_LOCAL, func_va_list_ofs);
}

ST_FUNC ಶೂನ್ಯ gen_fill_nops(ಪೂರ್ಣಾಙ್ಕ bytes)
{
    ಯದಿ ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    ಯಾವತ್ (bytes > 0) {
        EI(0x13, 0, 0, 0, 0);      // addi x0, x0, 0 == nop
        bytes -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gjmp(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಯದಿ (nocode_wanted)
      ಪ್ರತ್ಯಾಗಮ t;
    o(t);
    ಪ್ರತ್ಯಾಗಮ ind - 4;
}

// Generate branch to known address:
ST_FUNC ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಙ್ಕ a)
{
    uint32_t r = a - ind, imm;
    ಯದಿ ((r + (1 << 21)) & ~((1U << 22) - 2)) {
        o(0x17 | (5 << 7) | UPPER(r)); // lui RR, up(r)
        r = SIGN11(r);
        EI(0x67, 0, 0, 5, r);      // jalr x0, r(t0)
    } ಅನ್ಯಥಾ {
        imm = (((r >> 12) &  0xff) << 12)
            | (((r >> 11) &     1) << 20)
            | (((r >>  1) & 0x3ff) << 21)
            | (((r >> 20) &     1) << 31);
        o(0x6f | imm); // jal x0, imm ==  j imm
    }
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ gjmp_cond(ಪೂರ್ಣಾಙ್ಕ op, ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ tmp;
    ಪೂರ್ಣಾಙ್ಕ a = vtop->cmp_r & 0xff;
    ಪೂರ್ಣಾಙ್ಕ b = (vtop->cmp_r >> 8) & 0xff;
    ವಿಕಲ್ಪ (op) {
        ಪಕ್ಷ TOK_ULT: op = 6; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_UGE: op = 7; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ULE: op = 7; tmp = a; a = b; b = tmp; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_UGT: op = 6; tmp = a; a = b; b = tmp; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_LT:  op = 4; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_GE:  op = 5; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_LE:  op = 5; tmp = a; a = b; b = tmp; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_GT:  op = 4; tmp = a; a = b; b = tmp; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_NE:  op = 1; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_EQ:  op = 0; ಭಙ್ಗ;
    }
    o(0x63 | (op ^ 1) << 12 | a << 15 | b << 20 | 8 << 7); // bOP a,b,+4
    ಪ್ರತ್ಯಾಗಮ gjmp(t);
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ gjmp_append(ಪೂರ್ಣಾಙ್ಕ n, ಪೂರ್ಣಾಙ್ಕ t)
{
    ಶೂನ್ಯ *p;
    /* insert jump list n into t */
    ಯದಿ (n) {
        uint32_t n1 = n, n2;
        ಯಾವತ್ ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    ಪ್ರತ್ಯಾಗಮ t;
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_opil(ಪೂರ್ಣಾಙ್ಕ op, ಪೂರ್ಣಾಙ್ಕ ll)
{
    ಪೂರ್ಣಾಙ್ಕ a, b, d;
    ಪೂರ್ಣಾಙ್ಕ func3 = 0;
    ll = ll ? 0 : 8;
    ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
        ಪೂರ್ಣಾಙ್ಕ fc = vtop->c.i;
        ಯದಿ (fc == vtop->c.i && !ಕೆಳಗಿನ_OVERFLOW(fc)) {
            ಪೂರ್ಣಾಙ್ಕ cll = 0;
            ಪೂರ್ಣಾಙ್ಕ m = ll ? 31 : 63;
            vswap();
            gv(RC_INT);
            a = ireg(vtop[0].r);
            --vtop;
            d = get_reg(RC_INT);
            ++vtop;
            vswap();
            ವಿಕಲ್ಪ (op) {
                ಪಕ್ಷ '-':
                    ಯದಿ (fc <= -(1 << 11))
                      ಭಙ್ಗ;
                    fc = -fc;
                ಪಕ್ಷ '+':
                    func3 = 0; // addi d, a, fc
                    cll = ll;
                do_cop:
                    EI(0x13 | cll, func3, ireg(d), a, fc);
                    --vtop;
                    ಯದಿ (op >= TOK_ULT && op <= TOK_GT) {
                      vset_VT_CMP(TOK_NE);
                      vtop->cmp_r = ireg(d) | 0 << 8;
                    } ಅನ್ಯಥಾ
                      vtop[0].r = d;
                    ಪ್ರತ್ಯಾಗಮ;
                ಪಕ್ಷ TOK_LE:
                    ಯದಿ (fc >= (1 << 11) - 1)
                      ಭಙ್ಗ;
                    ++fc;
                ಪಕ್ಷ TOK_LT:  func3 = 2; ಗಚ್ಛ do_cop; // slti d, a, fc
                ಪಕ್ಷ TOK_ULE:
                    ಯದಿ (fc >= (1 << 11) - 1 || fc == -1)
                      ಭಙ್ಗ;
                    ++fc;
                ಪಕ್ಷ TOK_ULT: func3 = 3; ಗಚ್ಛ do_cop; // sltiu d, a, fc
                ಪಕ್ಷ '^':     func3 = 4; ಗಚ್ಛ do_cop; // xori d, a, fc
                ಪಕ್ಷ '|':     func3 = 6; ಗಚ್ಛ do_cop; // ori  d, a, fc
                ಪಕ್ಷ '&':     func3 = 7; ಗಚ್ಛ do_cop; // andi d, a, fc
                ಪಕ್ಷ TOK_SHL: func3 = 1; cll = ll; fc &= m; ಗಚ್ಛ do_cop; // slli d, a, fc
                ಪಕ್ಷ TOK_SHR: func3 = 5; cll = ll; fc &= m; ಗಚ್ಛ do_cop; // srli d, a, fc
                ಪಕ್ಷ TOK_SAR: func3 = 5; cll = ll; fc = 1024 | (fc & m); ಗಚ್ಛ do_cop;

                ಪಕ್ಷ TOK_UGE: /* -> TOK_ULT */
                ಪಕ್ಷ TOK_UGT: /* -> TOK_ULE */
                ಪಕ್ಷ TOK_GE:  /* -> TOK_LT */
                ಪಕ್ಷ TOK_GT:  /* -> TOK_LE */
                    gen_opil(op - 1, !ll);
                    vtop->cmp_op ^= 1;
                    ಪ್ರತ್ಯಾಗಮ;

                ಪಕ್ಷ TOK_NE:
                ಪಕ್ಷ TOK_EQ:
                    ಯದಿ (fc)
                      gen_opil('-', !ll), a = ireg(vtop++->r);
                    --vtop;
                    vset_VT_CMP(op);
                    vtop->cmp_r = a | 0 << 8;
                    ಪ್ರತ್ಯಾಗಮ;
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
    ವಿಕಲ್ಪ (op) {
    ಸ್ವಭಾವ:
        ಯದಿ (op >= TOK_ULT && op <= TOK_GT) {
            vset_VT_CMP(op);
            vtop->cmp_r = a | b << 8;
            ಭಙ್ಗ;
        }
        tcc_error("implement me: %s(%s)", __FUNCTION__, get_tok_str(op, ರಿಕ್ತ));
        ಭಙ್ಗ;

    ಪಕ್ಷ '+':
        ER(0x33 | ll, 0, d, a, b, 0); // add d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ '-':
        ER(0x33 | ll, 0, d, a, b, 0x20); // sub d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_SAR:
        ER(0x33 | ll | ll, 5, d, a, b, 0x20); // sra d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_SHR:
        ER(0x33 | ll | ll, 5, d, a, b, 0); // srl d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_SHL:
        ER(0x33 | ll, 1, d, a, b, 0); // sll d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ '*':
        ER(0x33 | ll, 0, d, a, b, 1); // mul d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ '/':
    ಪಕ್ಷ TOK_PDIV:
        ER(0x33 | ll, 4, d, a, b, 1); // div d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ '&':
        ER(0x33, 7, d, a, b, 0); // and d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ '^':
        ER(0x33, 4, d, a, b, 0); // xor d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ '|':
        ER(0x33, 6, d, a, b, 0); // or d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ '%':
        ER(ll ? 0x3b:  0x33, 6, d, a, b, 1); // rem d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_UMOD:
        ER(0x33 | ll, 7, d, a, b, 1); // remu d, a, b
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_UDIV:
        ER(0x33 | ll, 5, d, a, b, 1); // divu d, a, b
        ಭಙ್ಗ;
    }
}

ST_FUNC ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಙ್ಕ op)
{
    gen_opil(op, 0);
}

ST_FUNC ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಙ್ಕ op)
{
    gen_opil(op, 1);
}

ST_FUNC ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಙ್ಕ op)
{
    ಪೂರ್ಣಾಙ್ಕ rs1, rs2, rd, dbl, invert;
    ಯದಿ (vtop[0].type.t == VT_LDOUBLE) {
        CType type = vtop[0].type;
        ಪೂರ್ಣಾಙ್ಕ func = 0;
        ಪೂರ್ಣಾಙ್ಕ cond = -1;
        ವಿಕಲ್ಪ (op) {
        ಪಕ್ಷ '*': func = TOK___multf3; ಭಙ್ಗ;
        ಪಕ್ಷ '+': func = TOK___addtf3; ಭಙ್ಗ;
        ಪಕ್ಷ '-': func = TOK___subtf3; ಭಙ್ಗ;
        ಪಕ್ಷ '/': func = TOK___divtf3; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_EQ: func = TOK___eqtf2; cond = 1; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_NE: func = TOK___netf2; cond = 0; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_LT: func = TOK___lttf2; cond = 10; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_GE: func = TOK___getf2; cond = 11; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_LE: func = TOK___letf2; cond = 12; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_GT: func = TOK___gttf2; cond = 13; ಭಙ್ಗ;
        ಸ್ವಭಾವ: ಪ್ರತಿಜ್ಞಾ(0); ಭಙ್ಗ;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = REG_IRET;
        vtop->r2 = cond < 0 ? TREG_R(1) : VT_CONST;
        ಯದಿ (cond < 0)
            vtop->type = type;
        ಅನ್ಯಥಾ {
            vpushi(0);
            gen_opil(op, 1);
        }
        ಪ್ರತ್ಯಾಗಮ;
    }

    gv2(RC_FLOAT, RC_FLOAT);
    ಪ್ರತಿಜ್ಞಾ(vtop->type.t == VT_DOUBLE || vtop->type.t == VT_FLOAT);
    dbl = vtop->type.t == VT_DOUBLE;
    rs1 = freg(vtop[-1].r);
    rs2 = freg(vtop->r);
    vtop--;
    invert = 0;
    ವಿಕಲ್ಪ(op) {
    ಸ್ವಭಾವ:
        ಪ್ರತಿಜ್ಞಾ(0);
    ಪಕ್ಷ '+':
        op = 0; // fadd
    arithop:
        rd = get_reg(RC_FLOAT);
        vtop->r = rd;
        rd = freg(rd);
        ER(0x53, 7, rd, rs1, rs2, dbl | (op << 2)); // fop.[sd] RD, RS1, RS2 (dyn rm)
        ಭಙ್ಗ;
    ಪಕ್ಷ '-':
        op = 1; // fsub
        ಗಚ್ಛ arithop;
    ಪಕ್ಷ '*':
        op = 2; // fmul
        ಗಚ್ಛ arithop;
    ಪಕ್ಷ '/':
        op = 3; // fdiv
        ಗಚ್ಛ arithop;
    ಪಕ್ಷ TOK_EQ:
        op = 2; // EQ
    cmpop:
        rd = get_reg(RC_INT);
        vtop->r = rd;
        rd = ireg(rd);
        ER(0x53, op, rd, rs1, rs2, dbl | 0x50); // fcmp.[sd] RD, RS1, RS2 (op == eq/lt/le)
        ಯದಿ (invert)
          EI(0x13, 4, rd, rd, 1); // xori RD, 1

        /* generate VT_CMP output */
        vset_VT_CMP(TOK_NE);
        vtop->cmp_r = rd | (0 << 8);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_NE:
        invert = 1;
        op = 2; // EQ
        ಗಚ್ಛ cmpop;
    ಪಕ್ಷ TOK_LT:
        op = 1; // LT
        ಗಚ್ಛ cmpop;
    ಪಕ್ಷ TOK_LE:
        op = 0; // LE
        ಗಚ್ಛ cmpop;
    ಪಕ್ಷ TOK_GT:
        op = 1; // LT
        rd = rs1, rs1 = rs2, rs2 = rd;
        ಗಚ್ಛ cmpop;
    ಪಕ್ಷ TOK_GE:
        op = 0; // LE
        rd = rs1, rs1 = rs2, rs2 = rd;
        ಗಚ್ಛ cmpop;
    }
}

ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ r = ireg(gv(RC_INT));
    ಯದಿ ((t & VT_BTYPE) == VT_SHORT) {
        ಯದಿ (t & VT_UNSIGNED) {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EI(0x13, 5, r, r, 48); // srli r, r, 48
        } ಅನ್ಯಥಾ {
            EI(0x13, 1, r, r, 48); // slli r, r, 48
            EIu(0x13, 5, r, r, 0x400 | 48); // srai r, r, 48
        }
    } ಅನ್ಯಥಾ {
        ಯದಿ (t & VT_UNSIGNED) {
            EI(0x13, 7, r, r, 0xff); // andi r, r, 0xff
        } ಅನ್ಯಥಾ {
            EI(0x13, 1, r, r, 56); // slli r, r, 56
            EIu(0x13, 5, r, r, 0x400 | 56); // srai r, r, 56
        }
    }
}

ST_FUNC ಶೂನ್ಯ gen_cvt_sxtw(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ r = ireg(gv(RC_INT));
    EI(0x1b, 0, r, r, 0); // addiw r, r, 0
}

ST_FUNC ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ rr = ireg(gv(RC_INT)), dr;
    ಪೂರ್ಣಾಙ್ಕ u = vtop->type.t & VT_UNSIGNED;
    ಪೂರ್ಣಾಙ್ಕ l = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    ಯದಿ (t == VT_LDOUBLE) {
        ಪೂರ್ಣಾಙ್ಕ func = l ?
          (u ? TOK___floatunditf : TOK___floatditf) :
          (u ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        vtop->r2 = TREG_R(1);
    } ಅನ್ಯಥಾ {
        vtop--;
        dr = get_reg(RC_FLOAT);
        vtop++;
        vtop->r = dr;
        dr = freg(dr);
        EIu(0x53, 7, dr, rr, ((0x68 | (t == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[sd].[wl][u]
    }
}

ST_FUNC ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ ft = vtop->type.t & VT_BTYPE;
    ಪೂರ್ಣಾಙ್ಕ l = (t & VT_BTYPE) == VT_LLONG;
    ಪೂರ್ಣಾಙ್ಕ u = t & VT_UNSIGNED;
    ಯದಿ (ft == VT_LDOUBLE) {
        ಪೂರ್ಣಾಙ್ಕ func = l ?
          (u ? TOK___fixunstfdi : TOK___fixtfdi) :
          (u ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
    } ಅನ್ಯಥಾ {
        ಪೂರ್ಣಾಙ್ಕ rr = freg(gv(RC_FLOAT)), dr;
        vtop--;
        dr = get_reg(RC_INT);
        vtop++;
        vtop->r = dr;
        dr = ireg(dr);
        EIu(0x53, 1, dr, rr, ((0x60 | (ft == VT_DOUBLE ? 1 : 0)) << 5) | (u ? 1 : 0) | (l ? 2 : 0)); // fcvt.[wl][u].[sd] rtz
    }
}

ST_FUNC ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಙ್ಕ dt)
{
    ಪೂರ್ಣಾಙ್ಕ st = vtop->type.t & VT_BTYPE, rs, rd;
    dt &= VT_BTYPE;
    ಯದಿ (st == dt)
      ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (dt == VT_LDOUBLE || st == VT_LDOUBLE) {
        ಪೂರ್ಣಾಙ್ಕ func = (dt == VT_LDOUBLE) ?
            (st == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (dt == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        /* We can't use gfunc_call, as func_old_type works like vararg
           functions, and on riscv unnamed float args are passed like
           integers.  But we really need them in the float argument registers
           for extendsftf2/extenddftf2.  So, do it explicitely.  */
        save_regs(1);
        ಯದಿ (dt == VT_LDOUBLE)
          gv(RC_F(0));
        ಅನ್ಯಥಾ {
            gv(RC_R(0));
            ಪ್ರತಿಜ್ಞಾ(vtop->r2 < 7);
            ಯದಿ (vtop->r2 != 1 + vtop->r) {
                EI(0x13, 0, ireg(vtop->r) + 1, ireg(vtop->r2), 0); // mv Ra+1, RR2
                vtop->r2 = 1 + vtop->r;
            }
        }
        vpush_helper_func(func);
        gcall_or_jmp(1);
        vtop -= 2;
        vpushi(0);
        vtop->type.t = dt;
        ಯದಿ (dt == VT_LDOUBLE)
          vtop->r = REG_IRET, vtop->r2 = REG_IRET+1;
        ಅನ್ಯಥಾ
          vtop->r = REG_FRET;
    } ಅನ್ಯಥಾ {
        ಪ್ರತಿಜ್ಞಾ (dt == VT_FLOAT || dt == VT_DOUBLE);
        ಪ್ರತಿಜ್ಞಾ (st == VT_FLOAT || st == VT_DOUBLE);
        rs = gv(RC_FLOAT);
        rd = get_reg(RC_FLOAT);
        ಯದಿ (dt == VT_DOUBLE)
          EI(0x53, 0, freg(rd), freg(rs), 0x21 << 5); // fcvt.d.s RD, RS (no rm)
        ಅನ್ಯಥಾ
          EI(0x53, 7, freg(rd), freg(rs), (0x20 << 5) | 1); // fcvt.s.d RD, RS (dyn rm)
        vtop->r = rd;
    }
}

/* increment tcov counter */
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ r1, r2;
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

ST_FUNC ಶೂನ್ಯ ggoto(ಶೂನ್ಯ)
{
    gcall_or_jmp(0);
    vtop--;
}

ST_FUNC ಶೂನ್ಯ gen_vla_sp_save(ಪೂರ್ಣಾಙ್ಕ addr)
{
    ಯದಿ (ಕೆಳಗಿನ_OVERFLOW(addr)) {
	o(0x37 | (5 << 7) | UPPER(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        ES(0x23, 3, 5, 2, SIGN11(addr)); // sd sp, fc(t0)
    }
    ಅನ್ಯಥಾ
        ES(0x23, 3, 8, 2, addr); // sd sp, fc(s0)
}

ST_FUNC ಶೂನ್ಯ gen_vla_sp_restore(ಪೂರ್ಣಾಙ್ಕ addr)
{
    ಯದಿ (ಕೆಳಗಿನ_OVERFLOW(addr)) {
	o(0x37 | (5 << 7) | UPPER(addr)); //lui t0,upper(addr)
        ER(0x33, 0, 5, 5, 8, 0); // add t0, t0, s0
        EI(0x03, 3, 2, 5, SIGN11(addr)); // ld sp, fc(t0)
    }
    ಅನ್ಯಥಾ
        EI(0x03, 3, 2, 8, addr); // ld sp, fc(s0)
}

ST_FUNC ಶೂನ್ಯ gen_vla_alloc(CType *type, ಪೂರ್ಣಾಙ್ಕ align)
{
    ಪೂರ್ಣಾಙ್ಕ rr;
#ಯದಿ defined(CONFIG_TCC_BCHECK)
    ಯದಿ (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    rr = ireg(gv(RC_INT));
#ಯದಿ defined(CONFIG_TCC_BCHECK)
    ಯದಿ (tcc_state->do_bounds_check)
        EI(0x13, 0, rr, rr, 15+1);   // addi RR, RR, 15+1
    ಅನ್ಯಥಾ
#endif
    EI(0x13, 0, rr, rr, 15);   // addi RR, RR, 15
    EI(0x13, 7, rr, rr, -16);  // andi, RR, RR, -16
    ER(0x33, 0, 2, 2, rr, 0x20); // sub sp, sp, rr
    vpop();
#ಯದಿ defined(CONFIG_TCC_BCHECK)
    ಯದಿ (tcc_state->do_bounds_check) {
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

ST_FUNC ಶೂನ್ಯ gen_clear_cache(ಶೂನ್ಯ)
{
    /* Zifencei extension: fence + fence.i for I/D synchronization.
       Required by RISC-V Linux ABI, present on all Linux-capable cores. */
    o(0x0ff0000f); // fence iorw, iorw
    o(0x0000100f); // fence.i
}
#endif
