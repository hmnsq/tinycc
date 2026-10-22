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

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

// Number of registers available to allocator:
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_REGS 28 // x0-x18, x30, v0-v7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_R(x) (x) // x = 0..18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_R30  19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TREG_F(x) (x + 20) // x = 0..7

// Register classes sorted from more general to more precise:
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_INT (1 << 0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FLOAT (1 << 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R(x) (1 << (2 + (x))) // x = 0..18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R30  (1 << 21)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_F(x) (1 << (22 + (x))) // x = 0..7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_IRET (RC_R(0)) // int return register class
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FRET (RC_F(0)) // float return register class

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IRET (TREG_R(0)) // int return register number
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_FRET (TREG_F(0)) // float return register number

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTR_ਮਾਪ 8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ਮਾਪ 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ALIGN 16

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_ALIGN 16

#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO) && !defined(TCC_ਨਿਸ਼ਾਨਾ_PE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHAR_IS_UNSIGNED
#ਜੇ_ਅੰਤ

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROMOTE_RET
/******************************************************/
#ਨਹੀਂਤਾਂ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"
#ਅਨ੍ਤਰ੍ਭਾਵ <assert.h>

ST_ਅੰਕੜੇ ਅਚਲ ਅੱਖਰ * ਅਚਲ ਨਿਸ਼ਾਨਾ_machine_defs =
    "__aarch64__\0"
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
    "__arm64__\0"
#ਜੇ_ਅੰਤ
    "__AARCH64EL__\0"
    ;

ST_ਅੰਕੜੇ ਅਚਲ ਪੂਰਨ reg_classes[NB_REGS] = {
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

#ਜੇ defined(CONFIG_TCC_BCHECK)
ਸਥਿਰ addr_t func_bound_ਵਿੱਥ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ func_bound_ind;
ST_ਅੰਕੜੇ ਪੂਰਨ func_bound_ਜੋੜੋ_epilog;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_FREG(x) ((x) >= TREG_F(0))

ਸਥਿਰ uint32_t intr(ਪੂਰਨ r)
{
    ਪ੍ਰਤਿਜ੍ਞਾ(TREG_R(0) <= r && r <= TREG_R30);
    ਵਾਪਸ r < TREG_R30 ? r : 30;
}

ਸਥਿਰ uint32_t fltr(ਪੂਰਨ r)
{
    ਪ੍ਰਤਿਜ੍ਞਾ(TREG_F(0) <= r && r <= TREG_F(7));
    ਵਾਪਸ r - TREG_F(0);
}

// Add an instruction to text section:
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

ਸਥਿਰ ਪੂਰਨ arm64_encode_bimm64(uint64_t x)
{
    ਪੂਰਨ neg = x & 1;
    ਪੂਰਨ rep, pos, len;

    ਜੇ (neg)
        x = ~x;
    ਜੇ (!x)
        ਵਾਪਸ -1;

    ਜੇ (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    ਨਹੀਂਤਾਂ ਜੇ (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    ਨਹੀਂਤਾਂ ਜੇ (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    ਨਹੀਂਤਾਂ ਜੇ (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    ਨਹੀਂਤਾਂ ਜੇ (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    ਨਹੀਂਤਾਂ
        rep = 64;

    pos = 0;
    ਜੇ (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    ਜੇ (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    ਜੇ (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    ਜੇ (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    ਜੇ (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    ਜੇ (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    ਜੇ (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    ਜੇ (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    ਜੇ (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    ਜੇ (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    ਜੇ (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    ਜੇ (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    ਜੇ (x)
        ਵਾਪਸ -1;
    ਜੇ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    ਵਾਪਸ ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ਸਥਿਰ uint32_t arm64_movi(ਪੂਰਨ r, uint64_t x)
{
    uint64_t m = 0xffff;
    ਪੂਰਨ e;
    ਜੇ (!(x & ~m))
        ਵਾਪਸ ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    ਜੇ (!(x & ~(m << 16)))
        ਵਾਪਸ (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    ਜੇ (!(x & ~(m << 32)))
        ਵਾਪਸ (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    ਜੇ (!(x & ~(m << 48)))
        ਵਾਪਸ (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    ਜੇ ((x & ~m) == m << 16)
        ਵਾਪਸ (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    ਜੇ ((x & ~(m << 16)) == m)
        ਵਾਪਸ (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    ਜੇ (!~(x | m))
        ਵਾਪਸ (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    ਜੇ (!~(x | m << 16))
        ਵਾਪਸ (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    ਜੇ (!~(x | m << 32))
        ਵਾਪਸ (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ਜੇ (!~(x | m << 48))
        ਵਾਪਸ (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ਜੇ (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        ਵਾਪਸ (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    ਜੇ ((e = arm64_encode_bimm64(x)) >= 0)
        ਵਾਪਸ (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਖਾਲੀ arm64_movimm(ਪੂਰਨ r, uint64_t x)
{
    uint32_t i;
    ਜੇ ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    ਨਹੀਂਤਾਂ {
        // MOVZ/MOVN and 1-3 MOVKs
        ਪੂਰਨ z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        ਲਈ (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        ਜੇ (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        ਲਈ (i = 0; i < 64; i += 16)
            ਜੇ (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                ਰੋਕੋ;
            }
        ਲਈ (i += 16; i < 64; i += 16)
            ਜੇ (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC ਖਾਲੀ gsym_addr(ਪੂਰਨ t_, ਪੂਰਨ a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    ਜਦੋਂ (t) {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr = cur_ਪਾਠ_section->ਅੰਕੜੇ + t;
        uint32_t ਅਗਲਾ = read32le(ptr);
        ਜੇ (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = ਅਗਲਾ;
    }
}

ਸਥਿਰ ਪੂਰਨ arm64_type_ਮਾਪ(ਪੂਰਨ t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    ਚੋਣ (t & VT_BTYPE) {
    ਹਾਲਤ VT_BYTE: ਵਾਪਸ 0;
    ਹਾਲਤ VT_SHORT: ਵਾਪਸ 1;
    ਹਾਲਤ VT_INT: ਵਾਪਸ 2;
    ਹਾਲਤ VT_LLONG: ਵਾਪਸ 3;
    ਹਾਲਤ VT_PTR: ਵਾਪਸ 3;
    ਹਾਲਤ VT_FUNC: ਵਾਪਸ 3;
    ਹਾਲਤ VT_STRUCT: ਵਾਪਸ 3;
    ਹਾਲਤ VT_FLOAT: ਵਾਪਸ 2;
    ਹਾਲਤ VT_DOUBLE: ਵਾਪਸ 3;
    ਹਾਲਤ VT_LDOUBLE: ਵਾਪਸ 4;
    ਹਾਲਤ VT_BOOL: ਵਾਪਸ 0;
    }
    ਪ੍ਰਤਿਜ੍ਞਾ(0);
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਖਾਲੀ arm64_spoff(ਪੂਰਨ reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    ਜੇ (sub)
        off = -off;
    ਜੇ (off < 4096)
        o(ARM64_ਜੋੜੋ_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    ਨਹੀਂਤਾਂ {
        arm64_movimm(30, off);
        o(ARM64_ਜੋੜੋ_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

ਸਥਿਰ uint64_t arm64_check_ਵਿੱਥ(ਪੂਰਨ sz_, uint64_t off)
{
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    uint32_t sz = sz_;
    uint64_t scaled_ਨਕਾਬ = 0xffful << sz;
    ਜੇ (!(off & ~scaled_ਨਕਾਬ) || (off < 256 || -off <= 256))
        ਵਾਪਸ ~0ull;
    ਜੇ (off & scaled_ਨਕਾਬ)
        ਵਾਪਸ scaled_ਨਕਾਬ;
    ਜੇ (off & 0x1fful)
        ਵਾਪਸ 0x1fful;
#ਜੇ_ਅੰਤ
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਖਾਲੀ arm64_ldrx(ਪੂਰਨ sg, ਪੂਰਨ sz_, ਪੂਰਨ dst, ਪੂਰਨ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ਨਕਾਬ = 0xffful << sz;
    ਜੇ (sz >= 2)
        sg = 0;
    ਜੇ (!(off & ~scaled_ਨਕਾਬ))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    ਨਹੀਂਤਾਂ ਜੇ (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    ਨਹੀਂਤਾਂ {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

ਸਥਿਰ ਖਾਲੀ arm64_ldrv(ਪੂਰਨ sz_, ਪੂਰਨ dst, ਪੂਰਨ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ਨਕਾਬ = 0xffful << sz;

    ਜੇ (!(off & ~scaled_ਨਕਾਬ))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    ਨਹੀਂਤਾਂ ਜੇ (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    ਨਹੀਂਤਾਂ {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

ਸਥਿਰ ਖਾਲੀ arm64_ldrs(ਪੂਰਨ reg_, ਪੂਰਨ ਮਾਪ)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    ਚੋਣ (ਮਾਪ) {
    ਮੂਲ: ਪ੍ਰਤਿਜ੍ਞਾ(0); ਰੋਕੋ;
    ਹਾਲਤ 0:
        /* Can happen with zero size structs */
        ਰੋਕੋ;
    ਹਾਲਤ 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        ਰੋਕੋ;
    ਹਾਲਤ 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ਰੋਕੋ;
    ਹਾਲਤ 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ਰੋਕੋ;
    ਹਾਲਤ 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ਰੋਕੋ;
    ਹਾਲਤ 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ਰੋਕੋ;
    ਹਾਲਤ 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        ਰੋਕੋ;
    }
}

ਸਥਿਰ ਖਾਲੀ arm64_strx(ਪੂਰਨ sz_, ਪੂਰਨ dst, ਪੂਰਨ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ਨਕਾਬ = 0xffful << sz;

    ਜੇ (!(off & ~scaled_ਨਕਾਬ))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    ਨਹੀਂਤਾਂ ਜੇ (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    ਨਹੀਂਤਾਂ {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

ਸਥਿਰ ਖਾਲੀ arm64_strv(ਪੂਰਨ sz_, ਪੂਰਨ dst, ਪੂਰਨ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ਨਕਾਬ = 0xffful << sz;

    ਜੇ (!(off & ~scaled_ਨਕਾਬ))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    ਨਹੀਂਤਾਂ ਜੇ (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    ਨਹੀਂਤਾਂ {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

ਸਥਿਰ ਖਾਲੀ arm64_reloca(Sym *sym, ਪੂਰਨ reloc_type, uint64_t addend)
{
    greloca(cur_ਪਾਠ_section, sym, ind, reloc_type, addend);
}

ਸਥਿਰ ਖਾਲੀ arm64_sym(ਪੂਰਨ r, Sym *sym, addr_t addend)
{
    ਜੇ (sym->type.t & VT_TLS) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        Sym *s2 = external_global_sym(TOK_tls_ਸੂਚਕਾਂਕ, &int_type);
        ਪੂਰਨ r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#ਨਹੀਂਤਾਂ
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#ਜੇ_ਅੰਤ
        arm64_reloca(sym, R_AARCH64_TLSLE_ਜੋੜੋ_TPREL_HI12, addend);
        o(ARM64_ਜੋੜੋ_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_ਜੋੜੋ_TPREL_LO12, addend);
        o(ARM64_ਜੋੜੋ_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE /* no elf-style GOT on Windows */
    } ਨਹੀਂਤਾਂ ਜੇ (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_ਪੰਨਾ, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        ਜੇ (addend > 0xffffff) {
            ਪੂਰਨ t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_ਜੋੜੋ_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } ਨਹੀਂਤਾਂ {
           ਜੇ (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_ਜੋੜੋ_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            ਜੇ (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_ਜੋੜੋ_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#ਜੇ_ਅੰਤ
    } ਨਹੀਂਤਾਂ {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_ਜੋੜੋ_ABS_LO12_NC, addend);
        o(ARM64_ਜੋੜੋ_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

ਸਥਿਰ ਖਾਲੀ arm64_ਲੱਦੋ_cmp(ਪੂਰਨ r, SValue *sv);

ST_FUNC ਖਾਲੀ ਲੱਦੋ(ਪੂਰਨ r, SValue *sv)
{
    ਪੂਰਨ svtt = sv->type.t;
    ਪੂਰਨ svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    ਪੂਰਨ svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    ਪੂਰਨ sb = !(svtt & VT_UNSIGNED);
    ਪੂਰਨ sz = arm64_type_ਮਾਪ(svtt);

    ਜੇ (svr == (VT_LOCAL | VT_LVAL)) {
        ਜੇ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        ਨਹੀਂਤਾਂ
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        ਵਾਪਸ;
    }

    ਜੇ (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        ਜੇ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        ਨਹੀਂਤਾਂ
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        ਵਾਪਸ;
    }

    ਜੇ (svrv < VT_CONST && (svr & VT_LVAL)) {
        ਜੇ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        ਨਹੀਂਤਾਂ
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        ਵਾਪਸ;
    }

    ਜੇ (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t ਨਕਾਬ = arm64_check_ਵਿੱਥ(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~ਨਕਾਬ);
        ਜੇ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & ਨਕਾਬ);
        ਨਹੀਂਤਾਂ
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & ਨਕਾਬ);
        ਵਾਪਸ;
    }

    ਜੇ (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        ਵਾਪਸ;
    }

    ਜੇ (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        ਵਾਪਸ;
    }

    ਜੇ (svr < VT_CONST) {
        ਜੇ (IS_FREG(r) && IS_FREG(svr))
            ਜੇ (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            ਨਹੀਂਤਾਂ
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        ਨਹੀਂਤਾਂ ਜੇ (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        ਨਹੀਂਤਾਂ
            ਪ੍ਰਤਿਜ੍ਞਾ(0);
      ਵਾਪਸ;
    }

    ਜੇ (svr == VT_LOCAL) {
        ਜੇ (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        ਨਹੀਂਤਾਂ {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        ਵਾਪਸ;
    }

    ਜੇ (svr == VT_JMP || svr == VT_JMPI) {
        ਪੂਰਨ t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        ਵਾਪਸ;
    }

    ਜੇ (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        ਜੇ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        ਨਹੀਂਤਾਂ
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        ਵਾਪਸ;
    }

    ਜੇ (svr == VT_CMP) {
        arm64_ਲੱਦੋ_cmp(r, sv);
        ਵਾਪਸ;
    }

    ਲਿਖੋ("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (ਲੰਮਾ)svcul);
    ਪ੍ਰਤਿਜ੍ਞਾ(0);
}

ST_FUNC ਖਾਲੀ store(ਪੂਰਨ r, SValue *sv)
{
    ਪੂਰਨ svtt = sv->type.t;
    ਪੂਰਨ svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    ਪੂਰਨ svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    ਪੂਰਨ sz = arm64_type_ਮਾਪ(svtt);

    ਜੇ (svr == (VT_LOCAL | VT_LVAL)) {
        ਜੇ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        ਨਹੀਂਤਾਂ
            arm64_strx(sz, intr(r), 29, svcoff);
        ਵਾਪਸ;
    }

    ਜੇ (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        ਜੇ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        ਨਹੀਂਤਾਂ
            arm64_strx(sz, intr(r), 30, 0);
        ਵਾਪਸ;
    }

    ਜੇ (svrv < VT_CONST && (svr & VT_LVAL)) {
        ਜੇ (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        ਨਹੀਂਤਾਂ
            arm64_strx(sz, intr(r), intr(svrv), 0);
        ਵਾਪਸ;
    }

    ਜੇ (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t ਨਕਾਬ = arm64_check_ਵਿੱਥ(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~ਨਕਾਬ);
        ਜੇ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & ਨਕਾਬ);
        ਨਹੀਂਤਾਂ
            arm64_strx(sz, intr(r), 30, svcoff & ਨਕਾਬ);
        ਵਾਪਸ;
    }

    ਲਿਖੋ("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (ਲੰਮਾ)svcoff);
    ਪ੍ਰਤਿਜ੍ਞਾ(0);
}

ਸਥਿਰ ਖਾਲੀ arm64_gen_bl_or_b(ਪੂਰਨ b)
{
    ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    ਨਹੀਂਤਾਂ {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#ਜੇ_ਅੰਤ
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#ਜੇ defined CONFIG_TCC_BCHECK || defined TCC_ਨਿਸ਼ਾਨਾ_PE
ਸਥਿਰ ਖਾਲੀ gen_static_call(ਪੂਰਨ v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#ਜੇ_ਅੰਤ

#ਜੇ defined(CONFIG_TCC_BCHECK)
ਸਥਿਰ ਖਾਲੀ gen_bounds_prolog(ਖਾਲੀ)
{
    /* leave some room for bound checking code */
    func_bound_ਵਿੱਥ = lbounds_section->ਅੰਕੜੇ_ਵਿੱਥ;
    func_bound_ind = ind;
    func_bound_ਜੋੜੋ_epilog = 0;
    o(ARM64_NOP);  /* nop -> mov x0, lbound section pointer */
    o(ARM64_NOP);
    o(ARM64_NOP);
    o(ARM64_NOP);  /* nop -> call __bound_local_new */
}

ਸਥਿਰ ਖਾਲੀ gen_bounds_epilog(ਖਾਲੀ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ਅੰਕੜੇ;
    ਪੂਰਨ ਵਿੱਥ_modified = func_bound_ਵਿੱਥ != lbounds_section->ਅੰਕੜੇ_ਵਿੱਥ;

    ਜੇ (!ਵਿੱਥ_modified && !func_bound_ਜੋੜੋ_epilog)
        ਵਾਪਸ;

    /* add end of table info */
    bounds_ptr = section_ptr_ਜੋੜੋ(lbounds_section, ਆਕਾਰ(addr_t));
    *bounds_ptr = 0;

    sym_ਅੰਕੜੇ = get_sym_ref(&char_ਸੂਚਕ_type, lbounds_section,
                           func_bound_ਵਿੱਥ, PTR_ਮਾਪ);

    /* generate bound local allocation */
    ਜੇ (ਵਿੱਥ_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        arm64_sym(0, sym_ਅੰਕੜੇ, 0);
        gen_static_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0xa9bf07e0); /* stp x0, x1, [sp, #-16]! */
    o(0x3c9f0fe0); /* str q0, [sp, #-16]! */
    arm64_sym(0, sym_ਅੰਕੜੇ, 0);
    gen_static_call(TOK___bound_local_delete);
    o(0x3cc107e0); /* ldr q0, [sp], #16 */
    o(0xa8c107e0); /* ldp x0, x1, [sp], #16 */
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ arm64_hfa_aux(CType *type, ਪੂਰਨ *fsize, ਪੂਰਨ ਅੰਕ)
{
    ਜੇ (is_float(type->t)) {
        ਪੂਰਨ a, n = type_ਮਾਪ(type, &a);
        ਜੇ (ਅੰਕ >= 4 || (*fsize && *fsize != n))
            ਵਾਪਸ -1;
        *fsize = n;
        ਵਾਪਸ ਅੰਕ + 1;
    }
    ਨਹੀਂਤਾਂ ਜੇ ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *ਖੇਤਰ;
        ਜੇ (!IS_UNION(type->t)) {
            ਪੂਰਨ num0 = ਅੰਕ;
            ਲਈ (ਖੇਤਰ = type->ref->ਅਗਲਾ; ਖੇਤਰ; ਖੇਤਰ = ਖੇਤਰ->ਅਗਲਾ) {
                ਜੇ (ਖੇਤਰ->c != (ਅੰਕ - num0) * *fsize)
                    ਵਾਪਸ -1;
                ਅੰਕ = arm64_hfa_aux(&ਖੇਤਰ->type, fsize, ਅੰਕ);
                ਜੇ (ਅੰਕ == -1)
                    ਵਾਪਸ -1;
            }
            ਜੇ (type->ref->c != (ਅੰਕ - num0) * *fsize)
                ਵਾਪਸ -1;
            ਵਾਪਸ ਅੰਕ;
        }
        ਨਹੀਂਤਾਂ { // union
            ਪੂਰਨ num0 = ਅੰਕ;
            ਲਈ (ਖੇਤਰ = type->ref->ਅਗਲਾ; ਖੇਤਰ; ਖੇਤਰ = ਖੇਤਰ->ਅਗਲਾ) {
                ਪੂਰਨ num1 = arm64_hfa_aux(&ਖੇਤਰ->type, fsize, num0);
                ਜੇ (num1 == -1)
                    ਵਾਪਸ -1;
                ਅੰਕ = num1 < ਅੰਕ ? ਅੰਕ : num1;
            }
            ਜੇ (type->ref->c != (ਅੰਕ - num0) * *fsize)
                ਵਾਪਸ -1;
            ਵਾਪਸ ਅੰਕ;
        }
    }
    ਨਹੀਂਤਾਂ ਜੇ (type->t & VT_ARRAY) { /* handle float array within struct */
        ਪੂਰਨ num1;
        ਜੇ (!type->ref->c)
            ਵਾਪਸ ਅੰਕ;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, ਅੰਕ);
        ਜੇ (num1 == -1 || (num1 != ਅੰਕ && type->ref->c > 4))
            ਵਾਪਸ -1;
        num1 = ਅੰਕ + type->ref->c * (num1 - ਅੰਕ);
        ਜੇ (num1 > 4)
            ਵਾਪਸ -1;
        ਵਾਪਸ num1;
    }
    ਵਾਪਸ -1;
}

ਸਥਿਰ ਪੂਰਨ arm64_hfa(CType *type, ਬਿਨਾਨਿਸ਼ਾਨੀ *fsize)
{
    ਜੇ ((type->t & VT_BTYPE) == VT_STRUCT) {
        ਪੂਰਨ sz = 0;
        ਪੂਰਨ n = arm64_hfa_aux(type, &sz, 0);
        ਜੇ (0 < n && n <= 4) {
            ਜੇ (fsize)
                *fsize = sz;
            ਵਾਪਸ n;
        }
    }
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ arm64_pcs_aux(ਪੂਰਨ variadic, ਪੂਰਨ n, CType **type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *a)
{
    ਪੂਰਨ nx = 0; // next integer register
    ਪੂਰਨ nv = 0; // next vector register
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ns = 32; // next stack offset
    ਪੂਰਨ i;

    ਲਈ (i = 0; i < n; i++) {
        ਪੂਰਨ hfa = arm64_hfa(type[i], 0);
        ਪੂਰਨ ਮਾਪ, align, bt;

        bt = type[i]->t & VT_BTYPE;
        ਜੇ (bt == VT_PTR || bt == VT_FUNC)
            ਮਾਪ = align = 8;
        ਨਹੀਂਤਾਂ
            ਮਾਪ = type_ਮਾਪ(type[i], &align);

#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
        ਜੇ (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_PE)
        ਜੇ (variadic && i >= variadic) {
            hfa = 0;
            ਜੇ (is_float(bt))
                bt = VT_INT, ਮਾਪ = align = 8;
        }
#ਜੇ_ਅੰਤ
        ਜੇ (hfa)
            // B.2
            ;
        ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ > 16) {
            // B.3: replace with pointer
            ਜੇ (nx < 8)
                a[i] = nx++ << 1 | 1;
            ਨਹੀਂਤਾਂ {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            ਜਾਰੀ;
        }
        ਨਹੀਂਤਾਂ ਜੇ (bt == VT_STRUCT)
            // B.4
            ਮਾਪ = (ਮਾਪ + 7) & ~7;

        // C.1
        ਜੇ (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            ਜਾਰੀ;
        }

        // C.2
        ਜੇ (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            ਜਾਰੀ;
        }

        // C.3
        ਜੇ (hfa) {
            nv = 8;
            ਮਾਪ = (ਮਾਪ + 7) & ~7;
        }

        // C.4
        ਜੇ (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        ਜੇ (bt == VT_FLOAT)
            ਮਾਪ = 8;

        // C.6
        ਜੇ (hfa || is_float(bt)) {
            a[i] = ns;
            ns += ਮਾਪ;
            ਜਾਰੀ;
        }

        // C.7
        ਜੇ (bt != VT_STRUCT && ਮਾਪ <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            ਜਾਰੀ;
        }

        // C.8
        ਜੇ (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        ਜੇ (bt != VT_STRUCT && ਮਾਪ == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            ਜਾਰੀ;
        }

        // C.10
        ਜੇ (bt == VT_STRUCT && ਮਾਪ <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (ਮਾਪ + 7) >> 3;
            ਜਾਰੀ;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        ਜੇ (bt == VT_STRUCT) {
            a[i] = ns;
            ns += ਮਾਪ;
            ਜਾਰੀ;
        }

        // C.14
        ਜੇ (ਮਾਪ < 8)
            ਮਾਪ = 8;

        // C.15
        a[i] = ns;
        ns += ਮਾਪ;
    }

    ਵਾਪਸ ns - 32;
}

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ arm64_pcs(ਪੂਰਨ variadic, ਪੂਰਨ n, CType **type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *a)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਢੇਰ;

    // Return type:
    ਜੇ ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    ਨਹੀਂਤਾਂ {
        arm64_pcs_aux(0, 1, type, a);
        ਪ੍ਰਤਿਜ੍ਞਾ(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    ਢੇਰ = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    ਜੇ (0) {
        ਪੂਰਨ i;
        ਲਈ (i = 0; i < n; i++) {
            ਜੇ (!i)
                ਲਿਖੋ("arm64_pcs return: ");
            ਨਹੀਂਤਾਂ
                ਲਿਖੋ("arm64_pcs arg %d: ", i);
            ਜੇ (a[i] == (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)-1)
                ਲਿਖੋ("void\n");
            ਨਹੀਂਤਾਂ ਜੇ (a[i] == 1 && !i)
                ਲਿਖੋ("X8 pointer\n");
            ਨਹੀਂਤਾਂ ਜੇ (a[i] < 16)
                ਲਿਖੋ("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            ਨਹੀਂਤਾਂ ਜੇ (a[i] < 32)
                ਲਿਖੋ("V%lu\n", a[i] / 2 - 8);
            ਨਹੀਂਤਾਂ
                ਲਿਖੋ("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    ਵਾਪਸ ਢੇਰ;
}

ਸਥਿਰ ਪੂਰਨ n_func_ਦਲੀਲਾਂ(CType *type)
{
    ਪੂਰਨ n_ਦਲੀਲਾਂ = 0;
    Sym *arg;

    ਲਈ (arg = type->ref->ਅਗਲਾ; arg; arg = arg->ਅਗਲਾ)
        n_ਦਲੀਲਾਂ++;
    ਵਾਪਸ n_ਦਲੀਲਾਂ;
}

ਸਥਿਰ ਖਾਲੀ arm64_sub_sp(uint64_t diff)
{
    ਜੇ (!diff)
        ਵਾਪਸ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਜੇ (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        ਵਾਪਸ;
    }
#ਜੇ_ਅੰਤ
    ਜੇ (!(diff >> 24)) {
        ਜੇ (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        ਜੇ (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } ਨਹੀਂਤਾਂ {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

ਸਥਿਰ ਪੂਰਨ gv_addr(ਪੂਰਨ r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    ਵਾਪਸ gv(r);
}

ST_FUNC ਖਾਲੀ gfunc_call(ਪੂਰਨ nb_ਦਲੀਲਾਂ)
{
    CType *return_type;
    CType **t;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *a, *a1;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਢੇਰ;
    ਪੂਰਨ i;
    ਪੂਰਨ func_type = vtop[-nb_ਦਲੀਲਾਂ].type.ref->f.func_type;
    ਪੂਰਨ variadic = (func_type == FUNC_ELLIPSIS);
    ਪੂਰਨ old_style = (func_type == FUNC_OLD);
    ਪੂਰਨ var_nb_arg = variadic ? n_func_ਦਲੀਲਾਂ(&vtop[-nb_ਦਲੀਲਾਂ].type) : 0;

    save_regs(nb_ਦਲੀਲਾਂ + 1);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gbound_ਦਲੀਲਾਂ(nb_ਦਲੀਲਾਂ);
#ਜੇ_ਅੰਤ

    return_type = &vtop[-nb_ਦਲੀਲਾਂ].type.ref->type;
    ਜੇ ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_ਦਲੀਲਾਂ;

    t = tcc_malloc((nb_ਦਲੀਲਾਂ + 1) * ਆਕਾਰ(*t));
    a = tcc_malloc((nb_ਦਲੀਲਾਂ + 1) * ਆਕਾਰ(*a));
    a1 = tcc_malloc((nb_ਦਲੀਲਾਂ + 1) * ਆਕਾਰ(*a1));

    t[0] = return_type;
    ਲਈ (i = 0; i < nb_ਦਲੀਲਾਂ; i++)
        t[nb_ਦਲੀਲਾਂ - i] = &vtop[-i].type;

    ਢੇਰ = arm64_pcs(
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#ਜੇ_ਅੰਤ
        var_nb_arg, nb_ਦਲੀਲਾਂ + 1, t, a);

    // Allocate space for structs replaced by pointer:
    ਲਈ (i = nb_ਦਲੀਲਾਂ; i; i--)
        ਜੇ (a[i] & 1) {
            SValue *arg = &vtop[i - nb_ਦਲੀਲਾਂ];
            ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(&arg->type, &align);
            ਪ੍ਰਤਿਜ੍ਞਾ((arg->type.t & VT_BTYPE) == VT_STRUCT);
            ਢੇਰ = (ਢੇਰ + align - 1) & -align;
            a1[i] = ਢੇਰ;
            ਢੇਰ += ਮਾਪ;
        }

    ਢੇਰ = (ਢੇਰ + 15) >> 4 << 4;

    ਜੇ (ਢੇਰ >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", ਢੇਰ);
    arm64_sub_sp(ਢੇਰ);

    // First pass: set all values on stack
    ਲਈ (i = nb_ਦਲੀਲਾਂ; i; i--) {
        vpushv(vtop - nb_ਦਲੀਲਾਂ + i);

        ਜੇ (a[i] & 1) {
            // struct replaced by pointer
            ਪੂਰਨ r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            ਜੇ (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        ਨਹੀਂਤਾਂ ਜੇ (a[i] >= 32) {
            // value on stack
            ਜੇ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                ਪੂਰਨ r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            ਨਹੀਂਤਾਂ ਜੇ (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_ਮਾਪ(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            ਨਹੀਂਤਾਂ {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    ਲਈ (i = nb_ਦਲੀਲਾਂ; i; i--, vtop--) {
        ਜੇ (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            ਜੇ ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                ਜੇ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                ਨਹੀਂਤਾਂ
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            ਨਹੀਂਤਾਂ ਜੇ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(&vtop->type, &align);
                ਜੇ (ਮਾਪ) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, ਮਾਪ);
                }
            }
            ਨਹੀਂਤਾਂ
                gv(RC_R(a[i] / 2));
        }
        ਨਹੀਂਤਾਂ ਜੇ (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        ਨਹੀਂਤਾਂ ਜੇ (a[i] < 32) {
            // value in floating-point registers
            ਜੇ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                ਜੇ (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    ਲਈ (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } ਨਹੀਂਤਾਂ {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            ਨਹੀਂਤਾਂ
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    ਜੇ ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        ਜੇ (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        ਨਹੀਂਤਾਂ
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    ਜੇ (ਢੇਰ & 0xfff)
        o(0x910003ff | (ਢੇਰ & 0xfff) << 10); // add sp,sp,#(n)
    ਜੇ (ਢੇਰ >> 12)
        o(0x914003ff | (ਢੇਰ >> 12) << 10);

    {
        ਪੂਰਨ rt = return_type->t;
        ਪੂਰਨ bt = rt & VT_BTYPE;
        ਜੇ (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            ਜੇ (a[0] == 0) {
                ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(return_type, &align);
                ਪ੍ਰਤਿਜ੍ਞਾ(ਮਾਪ <= 16);
                ਜੇ (ਮਾਪ > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ)
                    arm64_strx(ਮਾਪ > 4 ? 3 : ਮਾਪ > 2 ? 2 : ਮਾਪ > 1, 0, 8, 0);

            }
            ਨਹੀਂਤਾਂ ਜੇ (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                ਲਈ (j = 0; j < n; j++)
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

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ arm64_func_va_list_ਢੇਰ;
ਸਥਿਰ ਪੂਰਨ arm64_func_va_list_gr_offs;
ਸਥਿਰ ਪੂਰਨ arm64_func_va_list_vr_offs;
ਸਥਿਰ ਪੂਰਨ arm64_func_sub_sp_ਵਿੱਥ;

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ arm64_func_ਸ਼ੁਰੂ_ਵਿੱਥ;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARM64_FUNC_ਢੇਰ_ਤਿਆਰੀ_SLOTS 6

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ arm64_pe_param_off(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ a)
{
    ਵਾਪਸ a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#ਜੇ_ਅੰਤ

ST_FUNC ਖਾਲੀ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ਪੂਰਨ n = 0;
    ਪੂਰਨ i = 0;
    Sym *sym;
    CType **t;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *a;
    ਪੂਰਨ use_x8 = 0;
    ਪੂਰਨ ਆਖਰੀ_int = 0;
    ਪੂਰਨ ਆਖਰੀ_float = 0;
    ਪੂਰਨ variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    ਪੂਰਨ var_nb_arg = variadic ? n_func_ਦਲੀਲਾਂ(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    ਲਈ (sym = func_type->ref; sym; sym = sym->ਅਗਲਾ)
        ++n;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    n += variadic;
#ਜੇ_ਅੰਤ

    t = tcc_malloc(n * ਆਕਾਰ(*t));
    a = tcc_malloc(n * ਆਕਾਰ(*a));
    ਲਈ (sym = func_type->ref; sym; sym = sym->ਅਗਲਾ)
        t[i++] = &sym->type;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਜੇ (variadic)
        t[i] = &int_type;
#ਜੇ_ਅੰਤ

    arm64_func_va_list_ਢੇਰ = arm64_pcs(var_nb_arg, n, t, a);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਜੇ (variadic)
        arm64_func_va_list_ਢੇਰ = arm64_pe_param_off(a[n - 1]);
#ਜੇ_ਅੰਤ

#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
    ਜੇ (variadic) {
        use_x8 = 1;
        ਆਖਰੀ_int = 4;
        ਆਖਰੀ_float = 4;
    }
#ਜੇ_ਅੰਤ

    ਜੇ (a && a[0] == 1)
        use_x8 = 1;
    ਲਈ (i = 1, sym = func_type->ref->ਅਗਲਾ; sym; i++, sym = sym->ਅਗਲਾ) {
        ਜੇ (a[i] < 16) {
            ਪੂਰਨ ਆਖਰੀ, align, ਮਾਪ = type_ਮਾਪ(&sym->type, &align);
	    ਆਖਰੀ = a[i] / 4 + 1 + (ਮਾਪ - 1) / 8;
	    ਆਖਰੀ_int = ਆਖਰੀ > ਆਖਰੀ_int ? ਆਖਰੀ : ਆਖਰੀ_int;
	}
        ਨਹੀਂਤਾਂ ਜੇ (a[i] < 32) {
            ਪੂਰਨ ਆਖਰੀ, hfa = arm64_hfa(&sym->type, 0);
	    ਆਖਰੀ = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    ਆਖਰੀ_float = ਆਖਰੀ > ਆਖਰੀ_float ? ਆਖਰੀ : ਆਖਰੀ_float;
	}
    }

    ਆਖਰੀ_int = ਆਖਰੀ_int > 4 ? 4 : ਆਖਰੀ_int;
    ਆਖਰੀ_float = ਆਖਰੀ_float > 4 ? 4 : ਆਖਰੀ_float;

    arm64_func_ਸ਼ੁਰੂ_ਵਿੱਥ = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    ਲਈ (i = 0; i < ਆਖਰੀ_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    ਜੇ (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    ਲਈ (i = 0; i < ਆਖਰੀ_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    ਲਈ (i = 1, sym = func_type->ref->ਅਗਲਾ; sym; i++, sym = sym->ਅਗਲਾ) {
        ਪੂਰਨ off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_ਸੈੱਟ_param(sym, off, a[i] & 1);

        ਜੇ (a[i] < 16) {
            ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && ਮਾਪ > 8)) * 8;
        }
        ਨਹੀਂਤਾਂ ਜੇ (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        ਜੇ (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            ਜੇ (k > 0 && sz < 16)
                ਲਈ (j = 0; j < k; j++) {
                    o(0x3d0003e0 | -(sz & 8) << 27 | (sz & 4) << 29 |
                      ((a[i] - 16) / 2 + j) | (off / sz + j) << 10);
                    // str ([sdq])(j),[sp,#(j * sz)]
                }
        }
    }

    tcc_free(a);
    tcc_free(t);

    arm64_func_sub_sp_ਵਿੱਥ = ind;
    /* In gfunc_epilog these will be replaced with stack setup code. */
    ਲਈ (i = 0; i < ARM64_FUNC_ਢੇਰ_ਤਿਆਰੀ_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#ਜੇ_ਅੰਤ
}

ST_FUNC ਖਾਲੀ gen_va_ਸ਼ੁਰੂ(ਖਾਲੀ)
{
    ਪੂਰਨ r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਜੇ (arm64_func_va_list_ਢੇਰ) {
        arm64_movimm(30, arm64_func_va_list_ਢੇਰ);
        o(0x8b1e03be); // add x30,x29,x30
    } ਨਹੀਂਤਾਂ
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#ਨਹੀਂਤਾਂ
    ਜੇ (arm64_func_va_list_ਢੇਰ) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_ਢੇਰ + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    ਨਹੀਂਤਾਂ
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
    ਜੇ (arm64_func_va_list_gr_offs) {
        ਜੇ (arm64_func_va_list_ਢੇਰ)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    ਜੇ (arm64_func_va_list_vr_offs) {
        o(0x910243be); // add x30,x29,#144
        o(0xf900081e | r << 5); // str x30,[x(r),#16]
    }

    arm64_movimm(30, arm64_func_va_list_gr_offs);
    o(0xb900181e | r << 5); // str w30,[x(r),#24]

    arm64_movimm(30, arm64_func_va_list_vr_offs);
    o(0xb9001c1e | r << 5); // str w30,[x(r),#28]
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

    --vtop;
}

ST_FUNC ਖਾਲੀ gen_va_arg(CType *t)
{
    ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(t, &align);
    uint32_t r0, r1;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਪੂਰਨ ਅਸਿੱਧਾ = 0, ਥਾਂ = (ਮਾਪ + 7) & -8;

    ਜੇ (ਮਾਪ > 16)
        ਅਸਿੱਧਾ = 1, ਥਾਂ = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    ਜੇ (ਥਾਂ) {
        ਜੇ (ਥਾਂ == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        ਜੇ (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ਥਾਂ << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    ਜੇ (ਅਸਿੱਧਾ)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#ਨਹੀਂਤਾਂ /* !PE */
    ਬਿਨਾਨਿਸ਼ਾਨੀ fsize = ਮਾਪ, hfa = 1;

    ਜੇ (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    ਜੇ (!hfa) {
        uint32_t n = ਮਾਪ > 16 ? 8 : (ਮਾਪ + 7) & -8;

#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        ਜੇ (align == 16) {
            ਪ੍ਰਤਿਜ੍ਞਾ(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#ਜੇ_ਅੰਤ

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ਜੇ (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#ਜੇ_ਅੰਤ

        ਜੇ (ਮਾਪ > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    ਨਹੀਂਤਾਂ {
        uint32_t ssz = (ਮਾਪ + 7) & -(uint32_t)8;
#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#ਜੇ_ਅੰਤ
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ਜੇ (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        ਜੇ (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        ਨਹੀਂਤਾਂ {
            // We need to change the layout of this HFA.
            // Get some space on the stack using global variable "loc":
            loc = (loc - ਮਾਪ) & -(uint32_t)align;
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
        write32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + b2, ARM64_B | ((ind - b2) >> 2));
#ਜੇ_ਅੰਤ
    }
#ਜੇ_ਅੰਤ /* not pe */
}

ST_FUNC ਪੂਰਨ gfunc_sret(CType *vt, ਪੂਰਨ variadic, CType *ret,
                       ਪੂਰਨ *align, ਪੂਰਨ *regsize)
{
    ਵਾਪਸ 0;
}

ST_FUNC ਖਾਲੀ gfunc_return(CType *func_type)
{
    CType *t = func_type;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ a;

    arm64_pcs(0, 1, &t, &a);

    ਚੋਣ (a) {
    ਹਾਲਤ -1:
        ਰੋਕੋ;
    ਹਾਲਤ 0:
        ਜੇ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, ਮਾਪ);
        }
        ਨਹੀਂਤਾਂ
            gv(RC_IRET);
        ਰੋਕੋ;
    ਹਾਲਤ 1: {
        CType type = *func_type;
        mk_ਸੂਚਕ(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        ਰੋਕੋ;
    }
    ਹਾਲਤ 16:
        ਜੇ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          ਲਈ (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        ਨਹੀਂਤਾਂ
            gv(RC_FRET);
        ਰੋਕੋ;
    ਮੂਲ:
      ਪ੍ਰਤਿਜ੍ਞਾ(0);
    }
    vtop--;
}

ST_FUNC ਖਾਲੀ gfunc_epilog(ਖਾਲੀ)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#ਜੇ_ਅੰਤ

    ਜੇ (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        ਪੂਰਨ i;
        addr_t saved_ind = ind;
        addr_t patch_ਸਿਰਾ = arm64_func_sub_sp_ਵਿੱਥ + ARM64_FUNC_ਢੇਰ_ਤਿਆਰੀ_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_ਵਿੱਥ;
        arm64_sub_sp(diff);
        ਲਈ (i = ind; i < patch_ਸਿਰਾ; i += 4)
            write32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + i, ARM64_NOP); // nop
        ind = saved_ind;
    }
    o(0x910003bf); // mov sp,x29
    o(0xa8ce7bfd); // ldp x29,x30,[sp],#224

    o(0xd65f03c0); // ret

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    pe_ਜੋੜੋ_unwind_ਅੰਕੜੇ(arm64_func_ਸ਼ੁਰੂ_ਵਿੱਥ, ind, -loc);
#ਜੇ_ਅੰਤ
}

ST_FUNC ਖਾਲੀ gen_fill_nops(ਪੂਰਨ ਬਾਈਟਾਂ)
{
    ਜੇ ((ਬਾਈਟਾਂ & 3))
      tcc_error("alignment of code section not multiple of 4");
    ਜਦੋਂ (ਬਾਈਟਾਂ > 0) {
	o(ARM64_NOP); // nop
	ਬਾਈਟਾਂ -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC ਪੂਰਨ gjmp(ਪੂਰਨ t)
{
    ਪੂਰਨ r = ind;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ t;
    o(t);
    ਵਾਪਸ r;
}

// Generate branch to known address:
ST_FUNC ਖਾਲੀ gjmp_addr(ਪੂਰਨ a)
{
    ਪ੍ਰਤਿਜ੍ਞਾ(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC ਪੂਰਨ gjmp_append(ਪੂਰਨ n, ਪੂਰਨ t)
{
    ਖਾਲੀ *p;
    /* insert vtop->c jump list in t */
    ਜੇ (n) {
        uint32_t n1 = n, n2;
        ਜਦੋਂ ((n2 = read32le(p = cur_ਪਾਠ_section->ਅੰਕੜੇ + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    ਵਾਪਸ t;
}

ਖਾਲੀ arm64_vset_VT_CMP(ਪੂਰਨ op)
{
    ਜੇ (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

ਸਥਿਰ ਖਾਲੀ arm64_gen_opil(ਪੂਰਨ op, uint32_t l);

ਸਥਿਰ ਖਾਲੀ arm64_ਲੱਦੋ_cmp(ਪੂਰਨ r, SValue *sv)
{
    sv->r = sv->cmp_r;
    ਜੇ (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    ਜੇ (r != sv->r) {
        ਲੱਦੋ(r, sv);
        sv->r = r;
    }
}

ST_FUNC ਪੂਰਨ gjmp_cond(ਪੂਰਨ op, ਪੂਰਨ t)
{
    ਪੂਰਨ bt = vtop->type.t & VT_BTYPE;

    ਪੂਰਨ inv = op & 1;
    vtop->r = vtop->cmp_r;

    ਜੇ (bt == VT_LDOUBLE) {
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
    ਨਹੀਂਤਾਂ ਜੇ (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    ਨਹੀਂਤਾਂ {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    ਵਾਪਸ gjmp(t);
}

ਸਥਿਰ ਪੂਰਨ arm64_iconst(uint64_t *val, SValue *sv)
{
    ਜੇ ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        ਵਾਪਸ 0;
    ਜੇ (val) {
        ਪੂਰਨ t = sv->type.t;
	ਪੂਰਨ bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    ਵਾਪਸ 1;
}

ਸਥਿਰ ਪੂਰਨ arm64_gen_opic(ਪੂਰਨ op, uint32_t l, ਪੂਰਨ rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    ਜੇ (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    ਚੋਣ (op) {

    ਹਾਲਤ '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        ਜੇ (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        ਨਹੀਂਤਾਂ ਜੇ (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        ਨਹੀਂਤਾਂ {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        ਵਾਪਸ 1;
      }

    ਹਾਲਤ '-':
        ਜੇ (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        ਨਹੀਂਤਾਂ ਜੇ (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        ਨਹੀਂਤਾਂ {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        ਵਾਪਸ 1;

    ਹਾਲਤ '^':
        ਜੇ (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            ਵਾਪਸ 1;
        }
        // fall through
    ਹਾਲਤ '&':
    ਹਾਲਤ '|': {
        ਪੂਰਨ e = arm64_encode_bimm64(l ? val : val | val << 32);
        ਜੇ (e < 0)
            ਵਾਪਸ 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        ਵਾਪਸ 1;
    }

    ਹਾਲਤ TOK_SAR:
    ਹਾਲਤ TOK_SHL:
    ਹਾਲਤ TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        ਜੇ (rev)
            ਵਾਪਸ 0;
        ਜੇ (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            ਵਾਪਸ 1;
        }
        ਨਹੀਂਤਾਂ ਜੇ (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        ਨਹੀਂਤਾਂ
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        ਵਾਪਸ 1;
    }

    }
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਖਾਲੀ arm64_gen_opil(ਪੂਰਨ op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        ਪੂਰਨ rev = 1;

        ਜੇ (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        ਜੇ (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            ਜੇ (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                ਵਾਪਸ;
            }
        }
        ਜੇ (!rev)
            vswap();
    }

    gv2(RC_INT, RC_INT);
    ਪ੍ਰਤਿਜ੍ਞਾ(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = intr(vtop[-1].r);
    b = intr(vtop[0].r);
    vtop -= 2;
    x = get_reg(RC_INT);
    ++vtop;
    vtop[0].r = x;
    x = intr(x);

    ਚੋਣ (op) {
    ਹਾਲਤ '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ਰੋਕੋ;
    ਹਾਲਤ '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        ਰੋਕੋ;
    ਹਾਲਤ '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        ਰੋਕੋ;
    ਹਾਲਤ '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        ਰੋਕੋ;
    ਹਾਲਤ '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        ਰੋਕੋ;
    ਹਾਲਤ '/':
    ਹਾਲਤ TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        ਰੋਕੋ;
    ਹਾਲਤ '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        ਰੋਕੋ;
    ਹਾਲਤ '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        ਰੋਕੋ;
    ਹਾਲਤ TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        ਰੋਕੋ;
    ਹਾਲਤ TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        ਰੋਕੋ;
    ਹਾਲਤ TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        ਰੋਕੋ;
    ਹਾਲਤ TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        ਰੋਕੋ;
    ਹਾਲਤ TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        ਰੋਕੋ;
    ਹਾਲਤ TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        ਰੋਕੋ;
    ਹਾਲਤ TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        ਰੋਕੋ;
    ਹਾਲਤ TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        ਰੋਕੋ;
    ਹਾਲਤ TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        ਰੋਕੋ;
    ਹਾਲਤ TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        ਰੋਕੋ;
    ਹਾਲਤ TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        ਰੋਕੋ;
    ਹਾਲਤ TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        ਰੋਕੋ;
    ਹਾਲਤ TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ਰੋਕੋ;
    ਮੂਲ:
        ਪ੍ਰਤਿਜ੍ਞਾ(0);
    }
}

ST_FUNC ਖਾਲੀ gen_opi(ਪੂਰਨ op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC ਖਾਲੀ gen_opl(ਪੂਰਨ op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC ਖਾਲੀ gen_opf(ਪੂਰਨ op)
{
    uint32_t x, a, b, dbl;
    ਪੂਰਨ bt = vtop[0].type.t & VT_BTYPE;

    ਜੇ (op == TOK_NEG) {
        ਜੇ (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } ਨਹੀਂਤਾਂ {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        ਵਾਪਸ;
    }

    ਜੇ (bt == VT_LDOUBLE) {
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
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        ਜੇ (cond < 0)
            vtop->type = type;
        ਨਹੀਂਤਾਂ {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        ਵਾਪਸ;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    ਪ੍ਰਤਿਜ੍ਞਾ(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    ਚੋਣ (op) {
    ਹਾਲਤ TOK_EQ: ਹਾਲਤ TOK_NE:
    ਹਾਲਤ TOK_LT: ਹਾਲਤ TOK_GE: ਹਾਲਤ TOK_LE: ਹਾਲਤ TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        ਰੋਕੋ;
    ਮੂਲ:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        ਰੋਕੋ;
    }

    ਚੋਣ (op) {
    ਹਾਲਤ '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        ਰੋਕੋ;
    ਹਾਲਤ '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        ਰੋਕੋ;
    ਹਾਲਤ '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        ਰੋਕੋ;
    ਹਾਲਤ '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        ਰੋਕੋ;
    ਹਾਲਤ TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        ਰੋਕੋ;
    ਹਾਲਤ TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        ਰੋਕੋ;
    ਹਾਲਤ TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        ਰੋਕੋ;
    ਹਾਲਤ TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        ਰੋਕੋ;
    ਹਾਲਤ TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        ਰੋਕੋ;
    ਹਾਲਤ TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        ਰੋਕੋ;
    ਮੂਲ:
        ਪ੍ਰਤਿਜ੍ਞਾ(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC ਖਾਲੀ gen_cvt_sxtw(ਖਾਲੀ)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC ਖਾਲੀ gen_cvt_csti(ਪੂਰਨ t)
{
    ਪੂਰਨ r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC ਖਾਲੀ gen_cvt_itof(ਪੂਰਨ t)
{
    ਜੇ (t == VT_LDOUBLE) {
        ਪੂਰਨ f = vtop->type.t;
        ਪੂਰਨ func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        ਵਾਪਸ;
    }
    ਨਹੀਂਤਾਂ {
        ਪੂਰਨ d, n = intr(gv(RC_INT));
        ਪੂਰਨ s = !(vtop->type.t & VT_UNSIGNED);
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

ST_FUNC ਖਾਲੀ gen_cvt_ftoi(ਪੂਰਨ t)
{
    ਜੇ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        ਪੂਰਨ func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        ਵਾਪਸ;
    }
    ਨਹੀਂਤਾਂ {
        ਪੂਰਨ d, n = fltr(gv(RC_FLOAT));
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

ST_FUNC ਖਾਲੀ gen_cvt_ftof(ਪੂਰਨ t)
{
    ਪੂਰਨ f = vtop[0].type.t & VT_BTYPE;
    ਪ੍ਰਤਿਜ੍ਞਾ(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    ਪ੍ਰਤਿਜ੍ਞਾ(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    ਜੇ (t == f)
        ਵਾਪਸ;

    ਜੇ (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        ਪੂਰਨ func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    ਨਹੀਂਤਾਂ {
        ਪੂਰਨ x, a;
        gv(RC_FLOAT);
        ਪ੍ਰਤਿਜ੍ਞਾ(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        ਜੇ (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        ਨਹੀਂਤਾਂ
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC ਖਾਲੀ gen_increment_tcov (SValue *sv)
{
    ਪੂਰਨ r1, r2;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    arm64_sym(r1, sv->sym, 0);
    o(ARM64_LDR_X | ARM64_RN(intr(r1)) | intr(r2)); // ldr r2, [r1]
    o(0x91000400 | (intr(r2)<<5) | intr(r2)); // add r2, r2, #1
    o(0xf9000000 | (intr(r1)<<5) | intr(r2)); // str r2, [r1]
    vpop();
}

ST_FUNC ਖਾਲੀ ggoto(ਖਾਲੀ)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC ਖਾਲੀ gen_clear_cache(ਖਾਲੀ)
{
    uint32_t beg, ਸਿਰਾ, dsz, isz, p, lab1, b1;
    gv2(RC_INT, RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    beg = intr(vtop[-4].r); // x0
    ਸਿਰਾ = intr(vtop[-3].r); // x1
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
    write32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | ਸਿਰਾ << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0x51000400 | p | isz << 5); // sub w(p),w(isz),#1
    o(0x8a240004 | p | beg << 5 | p << 16); // bic x(p),x(beg),x(p)
    b1 = ind; o(ARM64_B); // b
    lab1 = ind;
    o(0xd50b7520 | p); // ic ivau,x(p)
    o(0x8b000000 | p | p << 5 | isz << 16); // add x(p),x(p),x(isz)
    write32le(cur_ਪਾਠ_section->ਅੰਕੜੇ + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | ਸਿਰਾ << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0xd5033fdf); // isb
}

ST_FUNC ਖਾਲੀ gen_vla_sp_save(ਪੂਰਨ addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC ਖਾਲੀ gen_vla_sp_restore(ਪੂਰਨ addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC ਖਾਲੀ gen_vla_alloc(CType *type, ਪੂਰਨ align) {
    uint32_t r;
#ਜੇ defined(CONFIG_TCC_BCHECK)
    ਜੇ (tcc_state->do_bounds_check)
        vpushv(vtop);
#ਜੇ_ਅੰਤ
    r = intr(gv(RC_INT));
#ਜੇ defined(CONFIG_TCC_BCHECK)
    ਜੇ (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#ਜੇ defined(CONFIG_TCC_BCHECK)
    ਜੇ (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x910003e0 | vtop->r); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_ਜੋੜੋ_epilog = 1;
    }
#ਜੇ_ਅੰਤ
}

/* end of A64 code generator */
/*************************************************************/
#ਜੇ_ਅੰਤ
/*************************************************************/
