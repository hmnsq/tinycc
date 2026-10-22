/*
 *  A64 code generator for TCC
 *
 *  Copyright (c) 2014-2015 Edmund Grimley Evans
 *
 * Copying and distribution of this file, with or without modification,
 * are permitted in any medium without royalty provided the copyright
 * notice and this notice are preserved.  This file is offered as-is,
 * without any warranty.
 */

#که_تعریف_شوی موخه_DEFS_ONLY

// Number of registers available to allocator:
#تعریف_کړه NB_REGS 28 // x0-x18, x30, v0-v7

#تعریف_کړه TREG_R(x) (x) // x = 0..18
#تعریف_کړه TREG_R30  19
#تعریف_کړه TREG_F(x) (x + 20) // x = 0..7

// Register classes sorted from more general to more precise:
#تعریف_کړه RC_INT (1 << 0)
#تعریف_کړه RC_FLOAT (1 << 1)
#تعریف_کړه RC_R(x) (1 << (2 + (x))) // x = 0..18
#تعریف_کړه RC_R30  (1 << 21)
#تعریف_کړه RC_F(x) (1 << (22 + (x))) // x = 0..7

#تعریف_کړه RC_IRET (RC_R(0)) // int return register class
#تعریف_کړه RC_FRET (RC_F(0)) // float return register class

#تعریف_کړه REG_IRET (TREG_R(0)) // int return register number
#تعریف_کړه REG_FRET (TREG_F(0)) // float return register number

#تعریف_کړه PTR_اندازه 8

#تعریف_کړه LDOUBLE_اندازه 16
#تعریف_کړه LDOUBLE_ALIGN 16

#تعریف_کړه MAX_ALIGN 16

#إذا !defined(TCC_موخه_MACHO) && !defined(TCC_موخه_PE)
#تعریف_کړه CHAR_IS_UNSIGNED
#د_که_پای

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#تعریف_کړه PROMOTE_RET
/******************************************************/
#وإلا /* ! TARGET_DEFS_ONLY */
/******************************************************/
#تعریف_کړه USING_GLOBALS
#ضمن "tcc.h"
#ضمن <assert.h>

ST_معلومات ثابت حرف * ثابت موخه_machine_defs =
    "__aarch64__\0"
#إذا defined(TCC_موخه_MACHO)
    "__arm64__\0"
#د_که_پای
    "__AARCH64EL__\0"
    ;

ST_معلومات ثابت صحيح reg_classes[NB_REGS] = {
  RC_INT | RC_R(0),
  RC_INT | RC_R(1),
  RC_INT | RC_R(2),
  RC_INT | RC_R(3),
  RC_INT | RC_R(4),
  RC_INT | RC_R(5),
  RC_INT | RC_R(6),
  RC_INT | RC_R(7),
  RC_INT | RC_R(8),
  RC_INT | RC_R(9),
  RC_INT | RC_R(10),
  RC_INT | RC_R(11),
  RC_INT | RC_R(12),
  RC_INT | RC_R(13),
  RC_INT | RC_R(14),
  RC_INT | RC_R(15),
  RC_R(16), /* reserved for generator (arm64_sym()) */
  RC_R(17), /* reserved for generator (arm64_sym()) */
  RC_R(18), /* reserved on Windows/OSX */
  RC_R30,   /* not in RC_INT as we make special use of x30 */
  RC_FLOAT | RC_F(0),
  RC_FLOAT | RC_F(1),
  RC_FLOAT | RC_F(2),
  RC_FLOAT | RC_F(3),
  RC_FLOAT | RC_F(4),
  RC_FLOAT | RC_F(5),
  RC_FLOAT | RC_F(6),
  RC_FLOAT | RC_F(7)
};

#إذا defined(CONFIG_TCC_BCHECK)
ساكن addr_t func_bound_دننه_واټن;
ساكن بینښه اوږد func_bound_ind;
ST_معلومات صحيح func_bound_جمع_کړه_epilog;
#د_که_پای

#تعریف_کړه IS_FREG(x) ((x) >= TREG_F(0))

ساكن uint32_t intr(صحيح r)
{
    أكد(TREG_R(0) <= r && r <= TREG_R30);
    أرجع r < TREG_R30 ? r : 30;
}

ساكن uint32_t fltr(صحيح r)
{
    أكد(TREG_F(0) <= r && r <= TREG_F(7));
    أرجع r - TREG_F(0);
}

// Add an instruction to text section:
ST_FUNC فراغ o(بینښه صحيح c)
{
    صحيح ind1 = ind + 4;
    إذا (nocode_wanted)
        أرجع;
    إذا (ind1 > cur_متن_section->معلومات_allocated)
        section_realloc(cur_متن_section, ind1);
    write32le(cur_متن_section->معلومات + ind, c);
    ind = ind1;
}

ساكن صحيح arm64_encode_bimm64(uint64_t x)
{
    صحيح neg = x & 1;
    صحيح rep, pos, len;

    إذا (neg)
        x = ~x;
    إذا (!x)
        أرجع -1;

    إذا (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    وإلا إذا (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    وإلا إذا (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    وإلا إذا (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    وإلا إذا (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    وإلا
        rep = 64;

    pos = 0;
    إذا (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    إذا (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    إذا (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    إذا (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    إذا (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    إذا (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    إذا (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    إذا (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    إذا (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    إذا (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    إذا (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    إذا (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    إذا (x)
        أرجع -1;
    إذا (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    أرجع ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ساكن uint32_t arm64_movi(صحيح r, uint64_t x)
{
    uint64_t m = 0xffff;
    صحيح e;
    إذا (!(x & ~m))
        أرجع ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    إذا (!(x & ~(m << 16)))
        أرجع (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    إذا (!(x & ~(m << 32)))
        أرجع (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    إذا (!(x & ~(m << 48)))
        أرجع (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    إذا ((x & ~m) == m << 16)
        أرجع (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    إذا ((x & ~(m << 16)) == m)
        أرجع (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    إذا (!~(x | m))
        أرجع (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    إذا (!~(x | m << 16))
        أرجع (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    إذا (!~(x | m << 32))
        أرجع (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    إذا (!~(x | m << 48))
        أرجع (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    إذا (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        أرجع (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    إذا ((e = arm64_encode_bimm64(x)) >= 0)
        أرجع (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    أرجع 0;
}

ساكن فراغ arm64_movimm(صحيح r, uint64_t x)
{
    uint32_t i;
    إذا ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    وإلا {
        // MOVZ/MOVN and 1-3 MOVKs
        صحيح z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        لكل (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        إذا (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        لكل (i = 0; i < 64; i += 16)
            إذا (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                اكسر;
            }
        لكل (i += 16; i < 64; i += 16)
            إذا (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC فراغ gsym_addr(صحيح t_, صحيح a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    طالما (t) {
        بینښه حرف *ptr = cur_متن_section->معلومات + t;
        uint32_t بل = read32le(ptr);
        إذا (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = بل;
    }
}

ساكن صحيح arm64_type_اندازه(صحيح t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    بدل (t & VT_BTYPE) {
    حالة VT_BYTE: أرجع 0;
    حالة VT_SHORT: أرجع 1;
    حالة VT_INT: أرجع 2;
    حالة VT_LLONG: أرجع 3;
    حالة VT_PTR: أرجع 3;
    حالة VT_FUNC: أرجع 3;
    حالة VT_STRUCT: أرجع 3;
    حالة VT_FLOAT: أرجع 2;
    حالة VT_DOUBLE: أرجع 3;
    حالة VT_LDOUBLE: أرجع 4;
    حالة VT_BOOL: أرجع 0;
    }
    أكد(0);
    أرجع 0;
}

ساكن فراغ arm64_spoff(صحيح reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    إذا (sub)
        off = -off;
    إذا (off < 4096)
        o(ARM64_جمع_کړه_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    وإلا {
        arm64_movimm(30, off);
        o(ARM64_جمع_کړه_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

ساكن uint64_t arm64_check_دننه_واټن(صحيح sz_, uint64_t off)
{
#که_نه_تعریف_شوی TCC_موخه_PE
    uint32_t sz = sz_;
    uint64_t scaled_ماسک = 0xffful << sz;
    إذا (!(off & ~scaled_ماسک) || (off < 256 || -off <= 256))
        أرجع ~0ull;
    إذا (off & scaled_ماسک)
        أرجع scaled_ماسک;
    إذا (off & 0x1fful)
        أرجع 0x1fful;
#د_که_پای
    أرجع 0;
}

ساكن فراغ arm64_ldrx(صحيح sg, صحيح sz_, صحيح dst, صحيح bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ماسک = 0xffful << sz;
    إذا (sz >= 2)
        sg = 0;
    إذا (!(off & ~scaled_ماسک))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    وإلا إذا (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    وإلا {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

ساكن فراغ arm64_ldrv(صحيح sz_, صحيح dst, صحيح bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ماسک = 0xffful << sz;

    إذا (!(off & ~scaled_ماسک))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    وإلا إذا (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    وإلا {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

ساكن فراغ arm64_ldrs(صحيح reg_, صحيح اندازه)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    بدل (اندازه) {
    افتراضي: أكد(0); اكسر;
    حالة 0:
        /* Can happen with zero size structs */
        اكسر;
    حالة 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        اكسر;
    حالة 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        اكسر;
    حالة 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        اكسر;
    حالة 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        اكسر;
    حالة 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        اكسر;
    حالة 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        اكسر;
    حالة 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        اكسر;
    حالة 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        اكسر;
    حالة 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        اكسر;
    حالة 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        اكسر;
    حالة 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        اكسر;
    حالة 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        اكسر;
    حالة 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        اكسر;
    حالة 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        اكسر;
    حالة 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        اكسر;
    حالة 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        اكسر;
    }
}

ساكن فراغ arm64_strx(صحيح sz_, صحيح dst, صحيح bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ماسک = 0xffful << sz;

    إذا (!(off & ~scaled_ماسک))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    وإلا إذا (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    وإلا {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

ساكن فراغ arm64_strv(صحيح sz_, صحيح dst, صحيح bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ماسک = 0xffful << sz;

    إذا (!(off & ~scaled_ماسک))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    وإلا إذا (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    وإلا {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

ساكن فراغ arm64_reloca(Sym *sym, صحيح reloc_type, uint64_t addend)
{
    greloca(cur_متن_section, sym, ind, reloc_type, addend);
}

ساكن فراغ arm64_sym(صحيح r, Sym *sym, addr_t addend)
{
    إذا (sym->type.t & VT_TLS) {
#که_تعریف_شوی TCC_موخه_PE
        Sym *s2 = external_global_sym(TOK_tls_شاخص, &int_type);
        صحيح r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#وإلا
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#د_که_پای
        arm64_reloca(sym, R_AARCH64_TLSLE_جمع_کړه_TPREL_HI12, addend);
        o(ARM64_جمع_کړه_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_جمع_کړه_TPREL_LO12, addend);
        o(ARM64_جمع_کړه_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#که_نه_تعریف_شوی TCC_موخه_PE /* no elf-style GOT on Windows */
    } وإلا إذا (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_پاڼه, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        إذا (addend > 0xffffff) {
            صحيح t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_جمع_کړه_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } وإلا {
           إذا (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_جمع_کړه_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            إذا (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_جمع_کړه_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#د_که_پای
    } وإلا {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_جمع_کړه_ABS_LO12_NC, addend);
        o(ARM64_جمع_کړه_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

ساكن فراغ arm64_بارول_cmp(صحيح r, SValue *sv);

ST_FUNC فراغ بارول(صحيح r, SValue *sv)
{
    صحيح svtt = sv->type.t;
    صحيح svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    صحيح svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    صحيح sb = !(svtt & VT_UNSIGNED);
    صحيح sz = arm64_type_اندازه(svtt);

    إذا (svr == (VT_LOCAL | VT_LVAL)) {
        إذا (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        وإلا
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        أرجع;
    }

    إذا (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        إذا (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        وإلا
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        أرجع;
    }

    إذا (svrv < VT_CONST && (svr & VT_LVAL)) {
        إذا (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        وإلا
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        أرجع;
    }

    إذا (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t ماسک = arm64_check_دننه_واټن(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~ماسک);
        إذا (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & ماسک);
        وإلا
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & ماسک);
        أرجع;
    }

    إذا (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        أرجع;
    }

    إذا (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        أرجع;
    }

    إذا (svr < VT_CONST) {
        إذا (IS_FREG(r) && IS_FREG(svr))
            إذا (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            وإلا
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        وإلا إذا (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        وإلا
            أكد(0);
      أرجع;
    }

    إذا (svr == VT_LOCAL) {
        إذا (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        وإلا {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        أرجع;
    }

    إذا (svr == VT_JMP || svr == VT_JMPI) {
        صحيح t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        أرجع;
    }

    إذا (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        إذا (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        وإلا
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        أرجع;
    }

    إذا (svr == VT_CMP) {
        arm64_بارول_cmp(r, sv);
        أرجع;
    }

    چاپ_کړه("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (اوږد)svcul);
    أكد(0);
}

ST_FUNC فراغ store(صحيح r, SValue *sv)
{
    صحيح svtt = sv->type.t;
    صحيح svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    صحيح svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    صحيح sz = arm64_type_اندازه(svtt);

    إذا (svr == (VT_LOCAL | VT_LVAL)) {
        إذا (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        وإلا
            arm64_strx(sz, intr(r), 29, svcoff);
        أرجع;
    }

    إذا (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        إذا (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        وإلا
            arm64_strx(sz, intr(r), 30, 0);
        أرجع;
    }

    إذا (svrv < VT_CONST && (svr & VT_LVAL)) {
        إذا (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        وإلا
            arm64_strx(sz, intr(r), intr(svrv), 0);
        أرجع;
    }

    إذا (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t ماسک = arm64_check_دننه_واټن(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~ماسک);
        إذا (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & ماسک);
        وإلا
            arm64_strx(sz, intr(r), 30, svcoff & ماسک);
        أرجع;
    }

    چاپ_کړه("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (اوږد)svcoff);
    أكد(0);
}

ساكن فراغ arm64_gen_bl_or_b(صحيح b)
{
    إذا ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    وإلا {
#که_تعریف_شوی CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#د_که_پای
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#إذا defined CONFIG_TCC_BCHECK || defined TCC_موخه_PE
ساكن فراغ gen_static_call(صحيح v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#د_که_پای

#إذا defined(CONFIG_TCC_BCHECK)
ساكن فراغ gen_bounds_prolog(فراغ)
{
    /* leave some room for bound checking code */
    func_bound_دننه_واټن = lbounds_section->معلومات_دننه_واټن;
    func_bound_ind = ind;
    func_bound_جمع_کړه_epilog = 0;
    o(ARM64_NOP);  /* nop -> mov x0, lbound section pointer */
    o(ARM64_NOP);
    o(ARM64_NOP);
    o(ARM64_NOP);  /* nop -> call __bound_local_new */
}

ساكن فراغ gen_bounds_epilog(فراغ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_معلومات;
    صحيح دننه_واټن_modified = func_bound_دننه_واټن != lbounds_section->معلومات_دننه_واټن;

    إذا (!دننه_واټن_modified && !func_bound_جمع_کړه_epilog)
        أرجع;

    /* add end of table info */
    bounds_ptr = section_ptr_جمع_کړه(lbounds_section, حجم(addr_t));
    *bounds_ptr = 0;

    sym_معلومات = get_sym_ref(&char_اشاره_ګر_type, lbounds_section,
                           func_bound_دننه_واټن, PTR_اندازه);

    /* generate bound local allocation */
    إذا (دننه_واټن_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        arm64_sym(0, sym_معلومات, 0);
        gen_static_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0xa9bf07e0); /* stp x0, x1, [sp, #-16]! */
    o(0x3c9f0fe0); /* str q0, [sp, #-16]! */
    arm64_sym(0, sym_معلومات, 0);
    gen_static_call(TOK___bound_local_delete);
    o(0x3cc107e0); /* ldr q0, [sp], #16 */
    o(0xa8c107e0); /* ldp x0, x1, [sp], #16 */
}
#د_که_پای

ساكن صحيح arm64_hfa_aux(CType *type, صحيح *fsize, صحيح عدد)
{
    إذا (is_float(type->t)) {
        صحيح a, n = type_اندازه(type, &a);
        إذا (عدد >= 4 || (*fsize && *fsize != n))
            أرجع -1;
        *fsize = n;
        أرجع عدد + 1;
    }
    وإلا إذا ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *ډګر;
        إذا (!IS_UNION(type->t)) {
            صحيح num0 = عدد;
            لكل (ډګر = type->ref->بل; ډګر; ډګر = ډګر->بل) {
                إذا (ډګر->c != (عدد - num0) * *fsize)
                    أرجع -1;
                عدد = arm64_hfa_aux(&ډګر->type, fsize, عدد);
                إذا (عدد == -1)
                    أرجع -1;
            }
            إذا (type->ref->c != (عدد - num0) * *fsize)
                أرجع -1;
            أرجع عدد;
        }
        وإلا { // union
            صحيح num0 = عدد;
            لكل (ډګر = type->ref->بل; ډګر; ډګر = ډګر->بل) {
                صحيح num1 = arm64_hfa_aux(&ډګر->type, fsize, num0);
                إذا (num1 == -1)
                    أرجع -1;
                عدد = num1 < عدد ? عدد : num1;
            }
            إذا (type->ref->c != (عدد - num0) * *fsize)
                أرجع -1;
            أرجع عدد;
        }
    }
    وإلا إذا (type->t & VT_ARRAY) { /* handle float array within struct */
        صحيح num1;
        إذا (!type->ref->c)
            أرجع عدد;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, عدد);
        إذا (num1 == -1 || (num1 != عدد && type->ref->c > 4))
            أرجع -1;
        num1 = عدد + type->ref->c * (num1 - عدد);
        إذا (num1 > 4)
            أرجع -1;
        أرجع num1;
    }
    أرجع -1;
}

ساكن صحيح arm64_hfa(CType *type, بینښه *fsize)
{
    إذا ((type->t & VT_BTYPE) == VT_STRUCT) {
        صحيح sz = 0;
        صحيح n = arm64_hfa_aux(type, &sz, 0);
        إذا (0 < n && n <= 4) {
            إذا (fsize)
                *fsize = sz;
            أرجع n;
        }
    }
    أرجع 0;
}

ساكن بینښه اوږد arm64_pcs_aux(صحيح variadic, صحيح n, CType **type, بینښه اوږد *a)
{
    صحيح nx = 0; // next integer register
    صحيح nv = 0; // next vector register
    بینښه اوږد ns = 32; // next stack offset
    صحيح i;

    لكل (i = 0; i < n; i++) {
        صحيح hfa = arm64_hfa(type[i], 0);
        صحيح اندازه, align, bt;

        bt = type[i]->t & VT_BTYPE;
        إذا (bt == VT_PTR || bt == VT_FUNC)
            اندازه = align = 8;
        وإلا
            اندازه = type_اندازه(type[i], &align);

#إذا defined(TCC_موخه_MACHO)
        إذا (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#وإلاإذا defined(TCC_موخه_PE)
        إذا (variadic && i >= variadic) {
            hfa = 0;
            إذا (is_float(bt))
                bt = VT_INT, اندازه = align = 8;
        }
#د_که_پای
        إذا (hfa)
            // B.2
            ;
        وإلا إذا (اندازه > 16) {
            // B.3: replace with pointer
            إذا (nx < 8)
                a[i] = nx++ << 1 | 1;
            وإلا {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            استمر;
        }
        وإلا إذا (bt == VT_STRUCT)
            // B.4
            اندازه = (اندازه + 7) & ~7;

        // C.1
        إذا (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            استمر;
        }

        // C.2
        إذا (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            استمر;
        }

        // C.3
        إذا (hfa) {
            nv = 8;
            اندازه = (اندازه + 7) & ~7;
        }

        // C.4
        إذا (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        إذا (bt == VT_FLOAT)
            اندازه = 8;

        // C.6
        إذا (hfa || is_float(bt)) {
            a[i] = ns;
            ns += اندازه;
            استمر;
        }

        // C.7
        إذا (bt != VT_STRUCT && اندازه <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            استمر;
        }

        // C.8
        إذا (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        إذا (bt != VT_STRUCT && اندازه == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            استمر;
        }

        // C.10
        إذا (bt == VT_STRUCT && اندازه <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (اندازه + 7) >> 3;
            استمر;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        إذا (bt == VT_STRUCT) {
            a[i] = ns;
            ns += اندازه;
            استمر;
        }

        // C.14
        إذا (اندازه < 8)
            اندازه = 8;

        // C.15
        a[i] = ns;
        ns += اندازه;
    }

    أرجع ns - 32;
}

ساكن بینښه اوږد arm64_pcs(صحيح variadic, صحيح n, CType **type, بینښه اوږد *a)
{
    بینښه اوږد ډېری;

    // Return type:
    إذا ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    وإلا {
        arm64_pcs_aux(0, 1, type, a);
        أكد(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    ډېری = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    إذا (0) {
        صحيح i;
        لكل (i = 0; i < n; i++) {
            إذا (!i)
                چاپ_کړه("arm64_pcs return: ");
            وإلا
                چاپ_کړه("arm64_pcs arg %d: ", i);
            إذا (a[i] == (بینښه اوږد)-1)
                چاپ_کړه("void\n");
            وإلا إذا (a[i] == 1 && !i)
                چاپ_کړه("X8 pointer\n");
            وإلا إذا (a[i] < 16)
                چاپ_کړه("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            وإلا إذا (a[i] < 32)
                چاپ_کړه("V%lu\n", a[i] / 2 - 8);
            وإلا
                چاپ_کړه("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    أرجع ډېری;
}

ساكن صحيح n_func_دلیلونه(CType *type)
{
    صحيح n_دلیلونه = 0;
    Sym *arg;

    لكل (arg = type->ref->بل; arg; arg = arg->بل)
        n_دلیلونه++;
    أرجع n_دلیلونه;
}

ساكن فراغ arm64_sub_sp(uint64_t diff)
{
    إذا (!diff)
        أرجع;
#که_تعریف_شوی TCC_موخه_PE
    إذا (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        أرجع;
    }
#د_که_پای
    إذا (!(diff >> 24)) {
        إذا (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        إذا (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } وإلا {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

ساكن صحيح gv_addr(صحيح r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    أرجع gv(r);
}

ST_FUNC فراغ gfunc_call(صحيح nb_دلیلونه)
{
    CType *return_type;
    CType **t;
    بینښه اوږد *a, *a1;
    بینښه اوږد ډېری;
    صحيح i;
    صحيح func_type = vtop[-nb_دلیلونه].type.ref->f.func_type;
    صحيح variadic = (func_type == FUNC_ELLIPSIS);
    صحيح old_style = (func_type == FUNC_OLD);
    صحيح var_nb_arg = variadic ? n_func_دلیلونه(&vtop[-nb_دلیلونه].type) : 0;

    save_regs(nb_دلیلونه + 1);

#که_تعریف_شوی CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gbound_دلیلونه(nb_دلیلونه);
#د_که_پای

    return_type = &vtop[-nb_دلیلونه].type.ref->type;
    إذا ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_دلیلونه;

    t = tcc_malloc((nb_دلیلونه + 1) * حجم(*t));
    a = tcc_malloc((nb_دلیلونه + 1) * حجم(*a));
    a1 = tcc_malloc((nb_دلیلونه + 1) * حجم(*a1));

    t[0] = return_type;
    لكل (i = 0; i < nb_دلیلونه; i++)
        t[nb_دلیلونه - i] = &vtop[-i].type;

    ډېری = arm64_pcs(
#که_تعریف_شوی TCC_موخه_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#د_که_پای
        var_nb_arg, nb_دلیلونه + 1, t, a);

    // Allocate space for structs replaced by pointer:
    لكل (i = nb_دلیلونه; i; i--)
        إذا (a[i] & 1) {
            SValue *arg = &vtop[i - nb_دلیلونه];
            صحيح align, اندازه = type_اندازه(&arg->type, &align);
            أكد((arg->type.t & VT_BTYPE) == VT_STRUCT);
            ډېری = (ډېری + align - 1) & -align;
            a1[i] = ډېری;
            ډېری += اندازه;
        }

    ډېری = (ډېری + 15) >> 4 << 4;

    إذا (ډېری >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", ډېری);
    arm64_sub_sp(ډېری);

    // First pass: set all values on stack
    لكل (i = nb_دلیلونه; i; i--) {
        vpushv(vtop - nb_دلیلونه + i);

        إذا (a[i] & 1) {
            // struct replaced by pointer
            صحيح r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            إذا (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        وإلا إذا (a[i] >= 32) {
            // value on stack
            إذا ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                صحيح r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            وإلا إذا (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_اندازه(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            وإلا {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    لكل (i = nb_دلیلونه; i; i--, vtop--) {
        إذا (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            إذا ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                إذا ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                وإلا
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            وإلا إذا ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                صحيح align, اندازه = type_اندازه(&vtop->type, &align);
                إذا (اندازه) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, اندازه);
                }
            }
            وإلا
                gv(RC_R(a[i] / 2));
        }
        وإلا إذا (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        وإلا إذا (a[i] < 32) {
            // value in floating-point registers
            إذا ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                إذا (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    لكل (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } وإلا {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            وإلا
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    إذا ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        إذا (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        وإلا
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    إذا (ډېری & 0xfff)
        o(0x910003ff | (ډېری & 0xfff) << 10); // add sp,sp,#(n)
    إذا (ډېری >> 12)
        o(0x914003ff | (ډېری >> 12) << 10);

    {
        صحيح rt = return_type->t;
        صحيح bt = rt & VT_BTYPE;
        إذا (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            إذا (a[0] == 0) {
                صحيح align, اندازه = type_اندازه(return_type, &align);
                أكد(اندازه <= 16);
                إذا (اندازه > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                وإلا إذا (اندازه)
                    arm64_strx(اندازه > 4 ? 3 : اندازه > 2 ? 2 : اندازه > 1, 0, 8, 0);

            }
            وإلا إذا (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                لكل (j = 0; j < n; j++)
                    o(0x3d000100 |
                      (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                      (fltr(REG_FRET) + j) |
                      j << 10); // str ([sdq])(j),[x8,#(j * sz)]
            }
        }
    }

    tcc_free(a1);
    tcc_free(a);
    tcc_free(t);
}

ساكن بینښه اوږد arm64_func_va_list_ډېری;
ساكن صحيح arm64_func_va_list_gr_offs;
ساكن صحيح arm64_func_va_list_vr_offs;
ساكن صحيح arm64_func_sub_sp_دننه_واټن;

ساكن بینښه arm64_func_پیل_دننه_واټن;
#تعریف_کړه ARM64_FUNC_ډېری_تیاری_SLOTS 6

#که_تعریف_شوی TCC_موخه_PE
ساكن بینښه اوږد arm64_pe_param_off(بینښه اوږد a)
{
    أرجع a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#د_که_پای

ST_FUNC فراغ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    صحيح n = 0;
    صحيح i = 0;
    Sym *sym;
    CType **t;
    بینښه اوږد *a;
    صحيح use_x8 = 0;
    صحيح وروستی_int = 0;
    صحيح وروستی_float = 0;
    صحيح variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    صحيح var_nb_arg = variadic ? n_func_دلیلونه(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    لكل (sym = func_type->ref; sym; sym = sym->بل)
        ++n;

#که_تعریف_شوی TCC_موخه_PE
    n += variadic;
#د_که_پای

    t = tcc_malloc(n * حجم(*t));
    a = tcc_malloc(n * حجم(*a));
    لكل (sym = func_type->ref; sym; sym = sym->بل)
        t[i++] = &sym->type;

#که_تعریف_شوی TCC_موخه_PE
    إذا (variadic)
        t[i] = &int_type;
#د_که_پای

    arm64_func_va_list_ډېری = arm64_pcs(var_nb_arg, n, t, a);

#که_تعریف_شوی TCC_موخه_PE
    إذا (variadic)
        arm64_func_va_list_ډېری = arm64_pe_param_off(a[n - 1]);
#د_که_پای

#إذا !defined(TCC_موخه_MACHO)
    إذا (variadic) {
        use_x8 = 1;
        وروستی_int = 4;
        وروستی_float = 4;
    }
#د_که_پای

    إذا (a && a[0] == 1)
        use_x8 = 1;
    لكل (i = 1, sym = func_type->ref->بل; sym; i++, sym = sym->بل) {
        إذا (a[i] < 16) {
            صحيح وروستی, align, اندازه = type_اندازه(&sym->type, &align);
	    وروستی = a[i] / 4 + 1 + (اندازه - 1) / 8;
	    وروستی_int = وروستی > وروستی_int ? وروستی : وروستی_int;
	}
        وإلا إذا (a[i] < 32) {
            صحيح وروستی, hfa = arm64_hfa(&sym->type, 0);
	    وروستی = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    وروستی_float = وروستی > وروستی_float ? وروستی : وروستی_float;
	}
    }

    وروستی_int = وروستی_int > 4 ? 4 : وروستی_int;
    وروستی_float = وروستی_float > 4 ? 4 : وروستی_float;

    arm64_func_پیل_دننه_واټن = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    لكل (i = 0; i < وروستی_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    إذا (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    لكل (i = 0; i < وروستی_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    لكل (i = 1, sym = func_type->ref->بل; sym; i++, sym = sym->بل) {
        صحيح off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_سېټ_param(sym, off, a[i] & 1);

        إذا (a[i] < 16) {
            صحيح align, اندازه = type_اندازه(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && اندازه > 8)) * 8;
        }
        وإلا إذا (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        إذا (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            إذا (k > 0 && sz < 16)
                لكل (j = 0; j < k; j++) {
                    o(0x3d0003e0 | -(sz & 8) << 27 | (sz & 4) << 29 |
                      ((a[i] - 16) / 2 + j) | (off / sz + j) << 10);
                    // str ([sdq])(j),[sp,#(j * sz)]
                }
        }
    }

    tcc_free(a);
    tcc_free(t);

    arm64_func_sub_sp_دننه_واټن = ind;
    /* In gfunc_epilog these will be replaced with stack setup code. */
    لكل (i = 0; i < ARM64_FUNC_ډېری_تیاری_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#که_تعریف_شوی CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#د_که_پای
}

ST_FUNC فراغ gen_va_پیل(فراغ)
{
    صحيح r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#که_تعریف_شوی TCC_موخه_PE
    إذا (arm64_func_va_list_ډېری) {
        arm64_movimm(30, arm64_func_va_list_ډېری);
        o(0x8b1e03be); // add x30,x29,x30
    } وإلا
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#وإلا
    إذا (arm64_func_va_list_ډېری) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_ډېری + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    وإلا
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#إذا !defined(TCC_موخه_MACHO)
    إذا (arm64_func_va_list_gr_offs) {
        إذا (arm64_func_va_list_ډېری)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    إذا (arm64_func_va_list_vr_offs) {
        o(0x910243be); // add x30,x29,#144
        o(0xf900081e | r << 5); // str x30,[x(r),#16]
    }

    arm64_movimm(30, arm64_func_va_list_gr_offs);
    o(0xb900181e | r << 5); // str w30,[x(r),#24]

    arm64_movimm(30, arm64_func_va_list_vr_offs);
    o(0xb9001c1e | r << 5); // str w30,[x(r),#28]
#د_که_پای
#د_که_پای

    --vtop;
}

ST_FUNC فراغ gen_va_arg(CType *t)
{
    صحيح align, اندازه = type_اندازه(t, &align);
    uint32_t r0, r1;

#که_تعریف_شوی TCC_موخه_PE
    صحيح غیرمستقیم = 0, خونه = (اندازه + 7) & -8;

    إذا (اندازه > 16)
        غیرمستقیم = 1, خونه = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    إذا (خونه) {
        إذا (خونه == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        إذا (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | خونه << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    إذا (غیرمستقیم)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#وإلا /* !PE */
    بینښه fsize = اندازه, hfa = 1;

    إذا (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    إذا (!hfa) {
        uint32_t n = اندازه > 16 ? 8 : (اندازه + 7) & -8;

#إذا !defined(TCC_موخه_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        إذا (align == 16) {
            أكد(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#د_که_پای

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        إذا (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#إذا !defined(TCC_موخه_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#د_که_پای

        إذا (اندازه > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    وإلا {
        uint32_t ssz = (اندازه + 7) & -(uint32_t)8;
#إذا !defined(TCC_موخه_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#د_که_پای
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        إذا (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#إذا !defined(TCC_موخه_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_متن_section->معلومات + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        إذا (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        وإلا {
            // We need to change the layout of this HFA.
            // Get some space on the stack using global variable "loc":
            loc = (loc - اندازه) & -(uint32_t)align;
            o(0x8b3ec000 | 30 | r1 << 5); // add x30,x(r1),w30,sxtw
            arm64_movimm(r1, loc);
            o(0x8b0003a0 | r1 | r1 << 16); // add x(r1),x29,x(r1)
            o(0x4c402bdc | (uint32_t)fsize << 7 |
              (uint32_t)(hfa == 2) << 15 |
              (uint32_t)(hfa == 3) << 14); // ld1 {v28.(4s|2d),...},[x30]
            o(0x0d00801c | r1 << 5 | (fsize == 8) << 10 |
              (uint32_t)(hfa != 2) << 13 |
              (uint32_t)(hfa != 3) << 21); // st(hfa) {v28.(s|d),...}[0],[x(r1)]
        }
        // lab2:
        write32le(cur_متن_section->معلومات + b2, ARM64_B | ((ind - b2) >> 2));
#د_که_پای
    }
#د_که_پای /* not pe */
}

ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret,
                       صحيح *align, صحيح *regsize)
{
    أرجع 0;
}

ST_FUNC فراغ gfunc_return(CType *func_type)
{
    CType *t = func_type;
    بینښه اوږد a;

    arm64_pcs(0, 1, &t, &a);

    بدل (a) {
    حالة -1:
        اكسر;
    حالة 0:
        إذا ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            صحيح align, اندازه = type_اندازه(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, اندازه);
        }
        وإلا
            gv(RC_IRET);
        اكسر;
    حالة 1: {
        CType type = *func_type;
        mk_اشاره_ګر(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        اكسر;
    }
    حالة 16:
        إذا ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          لكل (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        وإلا
            gv(RC_FRET);
        اكسر;
    افتراضي:
      أكد(0);
    }
    vtop--;
}

ST_FUNC فراغ gfunc_epilog(فراغ)
{
#که_تعریف_شوی CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#د_که_پای

    إذا (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        صحيح i;
        addr_t saved_ind = ind;
        addr_t patch_پای_ټکی = arm64_func_sub_sp_دننه_واټن + ARM64_FUNC_ډېری_تیاری_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_دننه_واټن;
        arm64_sub_sp(diff);
        لكل (i = ind; i < patch_پای_ټکی; i += 4)
            write32le(cur_متن_section->معلومات + i, ARM64_NOP); // nop
        ind = saved_ind;
    }
    o(0x910003bf); // mov sp,x29
    o(0xa8ce7bfd); // ldp x29,x30,[sp],#224

    o(0xd65f03c0); // ret

#که_تعریف_شوی TCC_موخه_PE
    pe_جمع_کړه_unwind_معلومات(arm64_func_پیل_دننه_واټن, ind, -loc);
#د_که_پای
}

ST_FUNC فراغ gen_fill_nops(صحيح بایټونه)
{
    إذا ((بایټونه & 3))
      tcc_error("alignment of code section not multiple of 4");
    طالما (بایټونه > 0) {
	o(ARM64_NOP); // nop
	بایټونه -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC صحيح gjmp(صحيح t)
{
    صحيح r = ind;
    إذا (nocode_wanted)
        أرجع t;
    o(t);
    أرجع r;
}

// Generate branch to known address:
ST_FUNC فراغ gjmp_addr(صحيح a)
{
    أكد(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC صحيح gjmp_append(صحيح n, صحيح t)
{
    فراغ *p;
    /* insert vtop->c jump list in t */
    إذا (n) {
        uint32_t n1 = n, n2;
        طالما ((n2 = read32le(p = cur_متن_section->معلومات + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    أرجع t;
}

فراغ arm64_vset_VT_CMP(صحيح op)
{
    إذا (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

ساكن فراغ arm64_gen_opil(صحيح op, uint32_t l);

ساكن فراغ arm64_بارول_cmp(صحيح r, SValue *sv)
{
    sv->r = sv->cmp_r;
    إذا (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    إذا (r != sv->r) {
        بارول(r, sv);
        sv->r = r;
    }
}

ST_FUNC صحيح gjmp_cond(صحيح op, صحيح t)
{
    صحيح bt = vtop->type.t & VT_BTYPE;

    صحيح inv = op & 1;
    vtop->r = vtop->cmp_r;

    إذا (bt == VT_LDOUBLE) {
        uint32_t a, b, f = fltr(gv(RC_FLOAT));
        a = get_reg(RC_INT);
        vpushi(0);
        vtop[0].r = a;
        b = get_reg(RC_INT);
        a = intr(a);
        b = intr(b);
        o(0x4e083c00 | a | f << 5); // mov x(a),v(f).d[0]
        o(0x4e183c00 | b | f << 5); // mov x(b),v(f).d[1]
        o(0xaa000400 | a | a << 5 | b << 16); // orr x(a),x(a),x(b),lsl #1
        o(0xb4000040 | a | !!inv << 24); // cbz/cbnz x(a),.+8
        --vtop;
    }
    وإلا إذا (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    وإلا {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    أرجع gjmp(t);
}

ساكن صحيح arm64_iconst(uint64_t *val, SValue *sv)
{
    إذا ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        أرجع 0;
    إذا (val) {
        صحيح t = sv->type.t;
	صحيح bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    أرجع 1;
}

ساكن صحيح arm64_gen_opic(صحيح op, uint32_t l, صحيح rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    إذا (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    بدل (op) {

    حالة '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        إذا (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        وإلا إذا (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        وإلا {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        أرجع 1;
      }

    حالة '-':
        إذا (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        وإلا إذا (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        وإلا {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        أرجع 1;

    حالة '^':
        إذا (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            أرجع 1;
        }
        // fall through
    حالة '&':
    حالة '|': {
        صحيح e = arm64_encode_bimm64(l ? val : val | val << 32);
        إذا (e < 0)
            أرجع 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        أرجع 1;
    }

    حالة TOK_SAR:
    حالة TOK_SHL:
    حالة TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        إذا (rev)
            أرجع 0;
        إذا (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            أرجع 1;
        }
        وإلا إذا (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        وإلا
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        أرجع 1;
    }

    }
    أرجع 0;
}

ساكن فراغ arm64_gen_opil(صحيح op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        صحيح rev = 1;

        إذا (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        إذا (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            إذا (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                أرجع;
            }
        }
        إذا (!rev)
            vswap();
    }

    gv2(RC_INT, RC_INT);
    أكد(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = intr(vtop[-1].r);
    b = intr(vtop[0].r);
    vtop -= 2;
    x = get_reg(RC_INT);
    ++vtop;
    vtop[0].r = x;
    x = intr(x);

    بدل (op) {
    حالة '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        اكسر;
    حالة '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        اكسر;
    حالة '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        اكسر;
    حالة '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        اكسر;
    حالة '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        اكسر;
    حالة '/':
    حالة TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        اكسر;
    حالة '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        اكسر;
    حالة '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        اكسر;
    حالة TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        اكسر;
    حالة TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        اكسر;
    حالة TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        اكسر;
    حالة TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        اكسر;
    حالة TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        اكسر;
    حالة TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        اكسر;
    حالة TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        اكسر;
    حالة TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        اكسر;
    حالة TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        اكسر;
    حالة TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        اكسر;
    حالة TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        اكسر;
    حالة TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        اكسر;
    حالة TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        اكسر;
    حالة TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        اكسر;
    حالة TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        اكسر;
    افتراضي:
        أكد(0);
    }
}

ST_FUNC فراغ gen_opi(صحيح op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC فراغ gen_opl(صحيح op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC فراغ gen_opf(صحيح op)
{
    uint32_t x, a, b, dbl;
    صحيح bt = vtop[0].type.t & VT_BTYPE;

    إذا (op == TOK_NEG) {
        إذا (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } وإلا {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        أرجع;
    }

    إذا (bt == VT_LDOUBLE) {
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
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        إذا (cond < 0)
            vtop->type = type;
        وإلا {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        أرجع;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    أكد(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    بدل (op) {
    حالة TOK_EQ: حالة TOK_NE:
    حالة TOK_LT: حالة TOK_GE: حالة TOK_LE: حالة TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        اكسر;
    افتراضي:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        اكسر;
    }

    بدل (op) {
    حالة '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        اكسر;
    حالة '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        اكسر;
    حالة '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        اكسر;
    حالة '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        اكسر;
    حالة TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        اكسر;
    حالة TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        اكسر;
    حالة TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        اكسر;
    حالة TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        اكسر;
    حالة TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        اكسر;
    حالة TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        اكسر;
    افتراضي:
        أكد(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC فراغ gen_cvt_sxtw(فراغ)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC فراغ gen_cvt_csti(صحيح t)
{
    صحيح r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC فراغ gen_cvt_itof(صحيح t)
{
    إذا (t == VT_LDOUBLE) {
        صحيح f = vtop->type.t;
        صحيح func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        أرجع;
    }
    وإلا {
        صحيح d, n = intr(gv(RC_INT));
        صحيح s = !(vtop->type.t & VT_UNSIGNED);
        uint32_t l = ((vtop->type.t & VT_BTYPE) == VT_LLONG);
        --vtop;
        d = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = d;
        o(0x1e220000 | (uint32_t)!s << 16 |
          (uint32_t)(t != VT_FLOAT) << 22 | fltr(d) |
          l << 31 | n << 5); // [us]cvtf [sd](d),[wx](n)
    }
}

ST_FUNC فراغ gen_cvt_ftoi(صحيح t)
{
    إذا ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        صحيح func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        أرجع;
    }
    وإلا {
        صحيح d, n = fltr(gv(RC_FLOAT));
        uint32_t l = ((vtop->type.t & VT_BTYPE) != VT_FLOAT);
        --vtop;
        d = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = d;
        o(0x1e380000 |
          (uint32_t)!!(t & VT_UNSIGNED) << 16 |
          (uint32_t)((t & VT_BTYPE) == VT_LLONG) << 31 | intr(d) |
          l << 22 | n << 5); // fcvtz[su] [wx](d),[sd](n)
    }
}

ST_FUNC فراغ gen_cvt_ftof(صحيح t)
{
    صحيح f = vtop[0].type.t & VT_BTYPE;
    أكد(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    أكد(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    إذا (t == f)
        أرجع;

    إذا (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        صحيح func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    وإلا {
        صحيح x, a;
        gv(RC_FLOAT);
        أكد(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        إذا (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        وإلا
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC فراغ gen_increment_tcov (SValue *sv)
{
    صحيح r1, r2;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    arm64_sym(r1, sv->sym, 0);
    o(ARM64_LDR_X | ARM64_RN(intr(r1)) | intr(r2)); // ldr r2, [r1]
    o(0x91000400 | (intr(r2)<<5) | intr(r2)); // add r2, r2, #1
    o(0xf9000000 | (intr(r1)<<5) | intr(r2)); // str r2, [r1]
    vpop();
}

ST_FUNC فراغ ggoto(فراغ)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC فراغ gen_clear_cache(فراغ)
{
    uint32_t beg, پای_ټکی, dsz, isz, p, lab1, b1;
    gv2(RC_INT, RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    beg = intr(vtop[-4].r); // x0
    پای_ټکی = intr(vtop[-3].r); // x1
    dsz = intr(vtop[-2].r); // x2
    isz = intr(vtop[-1].r); // x3
    p = intr(vtop[0].r);    // x4
    vtop -= 5;

    o(0xd53b0020 | isz); // mrs x(isz),ctr_el0
    o(0x52800080 | p); // mov w(p),#4
    o(0x53104c00 | dsz | isz << 5); // ubfx w(dsz),w(isz),#16,#4
    o(0x1ac02000 | dsz | p << 5 | dsz << 16); // lsl w(dsz),w(p),w(dsz)
    o(0x12000c00 | isz | isz << 5); // and w(isz),w(isz),#15
    o(0x1ac02000 | isz | p << 5 | isz << 16); // lsl w(isz),w(p),w(isz)
    o(0x51000400 | p | dsz << 5); // sub w(p),w(dsz),#1
    o(0x8a240004 | p | beg << 5 | p << 16); // bic x(p),x(beg),x(p)
    b1 = ind; o(ARM64_B); // b
    lab1 = ind;
    o(0xd50b7b20 | p); // dc cvau,x(p)
    o(0x8b000000 | p | p << 5 | dsz << 16); // add x(p),x(p),x(dsz)
    write32le(cur_متن_section->معلومات + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | پای_ټکی << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0x51000400 | p | isz << 5); // sub w(p),w(isz),#1
    o(0x8a240004 | p | beg << 5 | p << 16); // bic x(p),x(beg),x(p)
    b1 = ind; o(ARM64_B); // b
    lab1 = ind;
    o(0xd50b7520 | p); // ic ivau,x(p)
    o(0x8b000000 | p | p << 5 | isz << 16); // add x(p),x(p),x(isz)
    write32le(cur_متن_section->معلومات + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | پای_ټکی << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0xd5033fdf); // isb
}

ST_FUNC فراغ gen_vla_sp_save(صحيح addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC فراغ gen_vla_sp_restore(صحيح addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align) {
    uint32_t r;
#إذا defined(CONFIG_TCC_BCHECK)
    إذا (tcc_state->do_bounds_check)
        vpushv(vtop);
#د_که_پای
    r = intr(gv(RC_INT));
#إذا defined(CONFIG_TCC_BCHECK)
    إذا (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    وإلا
#د_که_پای
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#إذا defined(CONFIG_TCC_BCHECK)
    إذا (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x910003e0 | vtop->r); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_جمع_کړه_epilog = 1;
    }
#د_که_پای
}

/* end of A64 code generator */
/*************************************************************/
#د_که_پای
/*************************************************************/
