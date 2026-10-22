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

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

// Number of registers available to allocator:
#ವ್ಯಾಖ್ಯಾನಿಸು NB_REGS 28 // x0-x18, x30, v0-v7

#ವ್ಯಾಖ್ಯಾನಿಸು TREG_R(x) (x) // x = 0..18
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_R30  19
#ವ್ಯಾಖ್ಯಾನಿಸು TREG_F(x) (x + 20) // x = 0..7

// Register classes sorted from more general to more precise:
#ವ್ಯಾಖ್ಯಾನಿಸು RC_INT (1 << 0)
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FLOAT (1 << 1)
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R(x) (1 << (2 + (x))) // x = 0..18
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R30  (1 << 21)
#ವ್ಯಾಖ್ಯಾನಿಸು RC_F(x) (1 << (22 + (x))) // x = 0..7

#ವ್ಯಾಖ್ಯಾನಿಸು RC_IRET (RC_R(0)) // int return register class
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FRET (RC_F(0)) // float return register class

#ವ್ಯಾಖ್ಯಾನಿಸು REG_IRET (TREG_R(0)) // int return register number
#ವ್ಯಾಖ್ಯಾನಿಸು REG_FRET (TREG_F(0)) // float return register number

#ವ್ಯಾಖ್ಯಾನಿಸು PTR_ಗಾತ್ರ 8

#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ಗಾತ್ರ 16
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ALIGN 16

#ವ್ಯಾಖ್ಯಾನಿಸು MAX_ALIGN 16

#ಆದರೆ !defined(TCC_ಗುರಿ_MACHO) && !defined(TCC_ಗುರಿ_PE)
#ವ್ಯಾಖ್ಯಾನಿಸು CHAR_IS_UNSIGNED
#ಆದರೆ_ಅಂತ್ಯ

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#ವ್ಯಾಖ್ಯಾನಿಸು PROMOTE_RET
/******************************************************/
#ಇಲ್ಲದಿದ್ದರೆ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"
#ಅನ್ತರ್ಭಾವ <assert.h>

ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ ಗುರಿ_machine_defs =
    "__aarch64__\0"
#ಆದರೆ defined(TCC_ಗುರಿ_MACHO)
    "__arm64__\0"
#ಆದರೆ_ಅಂತ್ಯ
    "__AARCH64EL__\0"
    ;

ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ reg_classes[NB_REGS] = {
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

#ಆದರೆ defined(CONFIG_TCC_BCHECK)
ಸ್ಥಿರ addr_t func_bound_ಸ್ಥಾನಾಂತರ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ func_bound_ind;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_bound_ಕೂಡಿಸು_epilog;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು IS_FREG(x) ((x) >= TREG_F(0))

ಸ್ಥಿರ uint32_t intr(ಪೂರ್ಣಾಂಕ r)
{
    ಪ್ರತಿಜ್ಞಾ(TREG_R(0) <= r && r <= TREG_R30);
    ಹಿಂತಿರುಗಿ r < TREG_R30 ? r : 30;
}

ಸ್ಥಿರ uint32_t fltr(ಪೂರ್ಣಾಂಕ r)
{
    ಪ್ರತಿಜ್ಞಾ(TREG_F(0) <= r && r <= TREG_F(7));
    ಹಿಂತಿರುಗಿ r - TREG_F(0);
}

// Add an instruction to text section:
ST_FUNC ಶೂನ್ಯ o(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ c)
{
    ಪೂರ್ಣಾಂಕ ind1 = ind + 4;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (ind1 > cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_allocated)
        section_realloc(cur_ಪಠ್ಯ_section, ind1);
    write32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + ind, c);
    ind = ind1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_encode_bimm64(uint64_t x)
{
    ಪೂರ್ಣಾಂಕ neg = x & 1;
    ಪೂರ್ಣಾಂಕ rep, pos, len;

    ಆದರೆ (neg)
        x = ~x;
    ಆದರೆ (!x)
        ಹಿಂತಿರುಗಿ -1;

    ಆದರೆ (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    ಇಲ್ಲದಿದ್ದರೆ
        rep = 64;

    pos = 0;
    ಆದರೆ (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    ಆದರೆ (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    ಆದರೆ (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    ಆದರೆ (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    ಆದರೆ (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    ಆದರೆ (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    ಆದರೆ (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    ಆದರೆ (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    ಆದರೆ (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    ಆದರೆ (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    ಆದರೆ (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    ಆದರೆ (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    ಆದರೆ (x)
        ಹಿಂತಿರುಗಿ -1;
    ಆದರೆ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    ಹಿಂತಿರುಗಿ ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ಸ್ಥಿರ uint32_t arm64_movi(ಪೂರ್ಣಾಂಕ r, uint64_t x)
{
    uint64_t m = 0xffff;
    ಪೂರ್ಣಾಂಕ e;
    ಆದರೆ (!(x & ~m))
        ಹಿಂತಿರುಗಿ ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    ಆದರೆ (!(x & ~(m << 16)))
        ಹಿಂತಿರುಗಿ (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    ಆದರೆ (!(x & ~(m << 32)))
        ಹಿಂತಿರುಗಿ (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    ಆದರೆ (!(x & ~(m << 48)))
        ಹಿಂತಿರುಗಿ (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    ಆದರೆ ((x & ~m) == m << 16)
        ಹಿಂತಿರುಗಿ (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    ಆದರೆ ((x & ~(m << 16)) == m)
        ಹಿಂತಿರುಗಿ (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    ಆದರೆ (!~(x | m))
        ಹಿಂತಿರುಗಿ (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    ಆದರೆ (!~(x | m << 16))
        ಹಿಂತಿರುಗಿ (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    ಆದರೆ (!~(x | m << 32))
        ಹಿಂತಿರುಗಿ (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ಆದರೆ (!~(x | m << 48))
        ಹಿಂತಿರುಗಿ (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ಆದರೆ (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        ಹಿಂತಿರುಗಿ (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    ಆದರೆ ((e = arm64_encode_bimm64(x)) >= 0)
        ಹಿಂತಿರುಗಿ (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_movimm(ಪೂರ್ಣಾಂಕ r, uint64_t x)
{
    uint32_t i;
    ಆದರೆ ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    ಇಲ್ಲದಿದ್ದರೆ {
        // MOVZ/MOVN and 1-3 MOVKs
        ಪೂರ್ಣಾಂಕ z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        ಗಾಗಿ (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        ಆದರೆ (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        ಗಾಗಿ (i = 0; i < 64; i += 16)
            ಆದರೆ (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                ನಿಲ್ಲಿಸು;
            }
        ಗಾಗಿ (i += 16; i < 64; i += 16)
            ಆದರೆ (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC ಶೂನ್ಯ gsym_addr(ಪೂರ್ಣಾಂಕ t_, ಪೂರ್ಣಾಂಕ a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    ಆಗ (t) {
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr = cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + t;
        uint32_t ಮುಂದಿನ = read32le(ptr);
        ಆದರೆ (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = ಮುಂದಿನ;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_type_ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    ಆಯ್ಕೆ (t & VT_BTYPE) {
    ಸ್ಥಿತಿ VT_BYTE: ಹಿಂತಿರುಗಿ 0;
    ಸ್ಥಿತಿ VT_SHORT: ಹಿಂತಿರುಗಿ 1;
    ಸ್ಥಿತಿ VT_INT: ಹಿಂತಿರುಗಿ 2;
    ಸ್ಥಿತಿ VT_LLONG: ಹಿಂತಿರುಗಿ 3;
    ಸ್ಥಿತಿ VT_PTR: ಹಿಂತಿರುಗಿ 3;
    ಸ್ಥಿತಿ VT_FUNC: ಹಿಂತಿರುಗಿ 3;
    ಸ್ಥಿತಿ VT_STRUCT: ಹಿಂತಿರುಗಿ 3;
    ಸ್ಥಿತಿ VT_FLOAT: ಹಿಂತಿರುಗಿ 2;
    ಸ್ಥಿತಿ VT_DOUBLE: ಹಿಂತಿರುಗಿ 3;
    ಸ್ಥಿತಿ VT_LDOUBLE: ಹಿಂತಿರುಗಿ 4;
    ಸ್ಥಿತಿ VT_BOOL: ಹಿಂತಿರುಗಿ 0;
    }
    ಪ್ರತಿಜ್ಞಾ(0);
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_spoff(ಪೂರ್ಣಾಂಕ reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    ಆದರೆ (sub)
        off = -off;
    ಆದರೆ (off < 4096)
        o(ARM64_ಕೂಡಿಸು_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    ಇಲ್ಲದಿದ್ದರೆ {
        arm64_movimm(30, off);
        o(ARM64_ಕೂಡಿಸು_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

ಸ್ಥಿರ uint64_t arm64_check_ಸ್ಥಾನಾಂತರ(ಪೂರ್ಣಾಂಕ sz_, uint64_t off)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_PE
    uint32_t sz = sz_;
    uint64_t scaled_ಮುಖವಾಡ = 0xffful << sz;
    ಆದರೆ (!(off & ~scaled_ಮುಖವಾಡ) || (off < 256 || -off <= 256))
        ಹಿಂತಿರುಗಿ ~0ull;
    ಆದರೆ (off & scaled_ಮುಖವಾಡ)
        ಹಿಂತಿರುಗಿ scaled_ಮುಖವಾಡ;
    ಆದರೆ (off & 0x1fful)
        ಹಿಂತಿರುಗಿ 0x1fful;
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_ldrx(ಪೂರ್ಣಾಂಕ sg, ಪೂರ್ಣಾಂಕ sz_, ಪೂರ್ಣಾಂಕ dst, ಪೂರ್ಣಾಂಕ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ಮುಖವಾಡ = 0xffful << sz;
    ಆದರೆ (sz >= 2)
        sg = 0;
    ಆದರೆ (!(off & ~scaled_ಮುಖವಾಡ))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    ಇಲ್ಲದಿದ್ದರೆ {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_ldrv(ಪೂರ್ಣಾಂಕ sz_, ಪೂರ್ಣಾಂಕ dst, ಪೂರ್ಣಾಂಕ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ಮುಖವಾಡ = 0xffful << sz;

    ಆದರೆ (!(off & ~scaled_ಮುಖವಾಡ))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    ಇಲ್ಲದಿದ್ದರೆ {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_ldrs(ಪೂರ್ಣಾಂಕ reg_, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    ಆಯ್ಕೆ (ಗಾತ್ರ_2) {
    ಪೂರ್ವನಿಯೋಜಿತ: ಪ್ರತಿಜ್ಞಾ(0); ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 0:
        /* Can happen with zero size structs */
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        ನಿಲ್ಲಿಸು;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_strx(ಪೂರ್ಣಾಂಕ sz_, ಪೂರ್ಣಾಂಕ dst, ಪೂರ್ಣಾಂಕ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ಮುಖವಾಡ = 0xffful << sz;

    ಆದರೆ (!(off & ~scaled_ಮುಖವಾಡ))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    ಇಲ್ಲದಿದ್ದರೆ {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_strv(ಪೂರ್ಣಾಂಕ sz_, ಪೂರ್ಣಾಂಕ dst, ಪೂರ್ಣಾಂಕ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ಮುಖವಾಡ = 0xffful << sz;

    ಆದರೆ (!(off & ~scaled_ಮುಖವಾಡ))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    ಇಲ್ಲದಿದ್ದರೆ {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_reloca(Sym *sym, ಪೂರ್ಣಾಂಕ reloc_type, uint64_t addend)
{
    greloca(cur_ಪಠ್ಯ_section, sym, ind, reloc_type, addend);
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_sym(ಪೂರ್ಣಾಂಕ r, Sym *sym, addr_t addend)
{
    ಆದರೆ (sym->type.t & VT_TLS) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        Sym *s2 = external_global_sym(TOK_tls_ಸೂಚ್ಯಂಕ, &int_type);
        ಪೂರ್ಣಾಂಕ r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#ಇಲ್ಲದಿದ್ದರೆ
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#ಆದರೆ_ಅಂತ್ಯ
        arm64_reloca(sym, R_AARCH64_TLSLE_ಕೂಡಿಸು_TPREL_HI12, addend);
        o(ARM64_ಕೂಡಿಸು_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_ಕೂಡಿಸು_TPREL_LO12, addend);
        o(ARM64_ಕೂಡಿಸು_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_PE /* no elf-style GOT on Windows */
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_ಪುಟ, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        ಆದರೆ (addend > 0xffffff) {
            ಪೂರ್ಣಾಂಕ t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_ಕೂಡಿಸು_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } ಇಲ್ಲದಿದ್ದರೆ {
           ಆದರೆ (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_ಕೂಡಿಸು_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            ಆದರೆ (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_ಕೂಡಿಸು_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#ಆದರೆ_ಅಂತ್ಯ
    } ಇಲ್ಲದಿದ್ದರೆ {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_ಕೂಡಿಸು_ABS_LO12_NC, addend);
        o(ARM64_ಕೂಡಿಸು_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_ತುಂಬು_cmp(ಪೂರ್ಣಾಂಕ r, SValue *sv);

ST_FUNC ಶೂನ್ಯ ತುಂಬು(ಪೂರ್ಣಾಂಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಂಕ svtt = sv->type.t;
    ಪೂರ್ಣಾಂಕ svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    ಪೂರ್ಣಾಂಕ svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    ಪೂರ್ಣಾಂಕ sb = !(svtt & VT_UNSIGNED);
    ಪೂರ್ಣಾಂಕ sz = arm64_type_ಗಾತ್ರ(svtt);

    ಆದರೆ (svr == (VT_LOCAL | VT_LVAL)) {
        ಆದರೆ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        ಇಲ್ಲದಿದ್ದರೆ
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        ಆದರೆ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        ಇಲ್ಲದಿದ್ದರೆ
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svrv < VT_CONST && (svr & VT_LVAL)) {
        ಆದರೆ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        ಇಲ್ಲದಿದ್ದರೆ
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t ಮುಖವಾಡ = arm64_check_ಸ್ಥಾನಾಂತರ(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~ಮುಖವಾಡ);
        ಆದರೆ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & ಮುಖವಾಡ);
        ಇಲ್ಲದಿದ್ದರೆ
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & ಮುಖವಾಡ);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr < VT_CONST) {
        ಆದರೆ (IS_FREG(r) && IS_FREG(svr))
            ಆದರೆ (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            ಇಲ್ಲದಿದ್ದರೆ
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        ಇಲ್ಲದಿದ್ದರೆ
            ಪ್ರತಿಜ್ಞಾ(0);
      ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr == VT_LOCAL) {
        ಆದರೆ (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        ಇಲ್ಲದಿದ್ದರೆ {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr == VT_JMP || svr == VT_JMPI) {
        ಪೂರ್ಣಾಂಕ t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        ಆದರೆ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        ಇಲ್ಲದಿದ್ದರೆ
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr == VT_CMP) {
        arm64_ತುಂಬು_cmp(r, sv);
        ಹಿಂತಿರುಗಿ;
    }

    ಬರೆ("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (ದೀರ್ಘ)svcul);
    ಪ್ರತಿಜ್ಞಾ(0);
}

ST_FUNC ಶೂನ್ಯ store(ಪೂರ್ಣಾಂಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಂಕ svtt = sv->type.t;
    ಪೂರ್ಣಾಂಕ svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    ಪೂರ್ಣಾಂಕ svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    ಪೂರ್ಣಾಂಕ sz = arm64_type_ಗಾತ್ರ(svtt);

    ಆದರೆ (svr == (VT_LOCAL | VT_LVAL)) {
        ಆದರೆ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        ಇಲ್ಲದಿದ್ದರೆ
            arm64_strx(sz, intr(r), 29, svcoff);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        ಆದರೆ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        ಇಲ್ಲದಿದ್ದರೆ
            arm64_strx(sz, intr(r), 30, 0);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svrv < VT_CONST && (svr & VT_LVAL)) {
        ಆದರೆ (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        ಇಲ್ಲದಿದ್ದರೆ
            arm64_strx(sz, intr(r), intr(svrv), 0);
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t ಮುಖವಾಡ = arm64_check_ಸ್ಥಾನಾಂತರ(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~ಮುಖವಾಡ);
        ಆದರೆ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & ಮುಖವಾಡ);
        ಇಲ್ಲದಿದ್ದರೆ
            arm64_strx(sz, intr(r), 30, svcoff & ಮುಖವಾಡ);
        ಹಿಂತಿರುಗಿ;
    }

    ಬರೆ("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (ದೀರ್ಘ)svcoff);
    ಪ್ರತಿಜ್ಞಾ(0);
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_gen_bl_or_b(ಪೂರ್ಣಾಂಕ b)
{
    ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    ಇಲ್ಲದಿದ್ದರೆ {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#ಆದರೆ_ಅಂತ್ಯ
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#ಆದರೆ defined CONFIG_TCC_BCHECK || defined TCC_ಗುರಿ_PE
ಸ್ಥಿರ ಶೂನ್ಯ gen_static_call(ಪೂರ್ಣಾಂಕ v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined(CONFIG_TCC_BCHECK)
ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_prolog(ಶೂನ್ಯ)
{
    /* leave some room for bound checking code */
    func_bound_ಸ್ಥಾನಾಂತರ = lbounds_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    func_bound_ind = ind;
    func_bound_ಕೂಡಿಸು_epilog = 0;
    o(ARM64_NOP);  /* nop -> mov x0, lbound section pointer */
    o(ARM64_NOP);
    o(ARM64_NOP);
    o(ARM64_NOP);  /* nop -> call __bound_local_new */
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_epilog(ಶೂನ್ಯ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ದತ್ತಾಂಶ;
    ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ_modified = func_bound_ಸ್ಥಾನಾಂತರ != lbounds_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (!ಸ್ಥಾನಾಂತರ_modified && !func_bound_ಕೂಡಿಸು_epilog)
        ಹಿಂತಿರುಗಿ;

    /* add end of table info */
    bounds_ptr = section_ptr_ಕೂಡಿಸು(lbounds_section, ಗಾತ್ರ(addr_t));
    *bounds_ptr = 0;

    sym_ದತ್ತಾಂಶ = get_sym_ref(&char_ಸೂಚಕ_type, lbounds_section,
                           func_bound_ಸ್ಥಾನಾಂತರ, PTR_ಗಾತ್ರ);

    /* generate bound local allocation */
    ಆದರೆ (ಸ್ಥಾನಾಂತರ_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        arm64_sym(0, sym_ದತ್ತಾಂಶ, 0);
        gen_static_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0xa9bf07e0); /* stp x0, x1, [sp, #-16]! */
    o(0x3c9f0fe0); /* str q0, [sp, #-16]! */
    arm64_sym(0, sym_ದತ್ತಾಂಶ, 0);
    gen_static_call(TOK___bound_local_delete);
    o(0x3cc107e0); /* ldr q0, [sp], #16 */
    o(0xa8c107e0); /* ldp x0, x1, [sp], #16 */
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_hfa_aux(CType *type, ಪೂರ್ಣಾಂಕ *fsize, ಪೂರ್ಣಾಂಕ ಅಂಕೆ)
{
    ಆದರೆ (is_float(type->t)) {
        ಪೂರ್ಣಾಂಕ a, n = type_ಗಾತ್ರ(type, &a);
        ಆದರೆ (ಅಂಕೆ >= 4 || (*fsize && *fsize != n))
            ಹಿಂತಿರುಗಿ -1;
        *fsize = n;
        ಹಿಂತಿರುಗಿ ಅಂಕೆ + 1;
    }
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *ಕ್ಷೇತ್ರ;
        ಆದರೆ (!IS_UNION(type->t)) {
            ಪೂರ್ಣಾಂಕ num0 = ಅಂಕೆ;
            ಗಾಗಿ (ಕ್ಷೇತ್ರ = type->ref->ಮುಂದಿನ; ಕ್ಷೇತ್ರ; ಕ್ಷೇತ್ರ = ಕ್ಷೇತ್ರ->ಮುಂದಿನ) {
                ಆದರೆ (ಕ್ಷೇತ್ರ->c != (ಅಂಕೆ - num0) * *fsize)
                    ಹಿಂತಿರುಗಿ -1;
                ಅಂಕೆ = arm64_hfa_aux(&ಕ್ಷೇತ್ರ->type, fsize, ಅಂಕೆ);
                ಆದರೆ (ಅಂಕೆ == -1)
                    ಹಿಂತಿರುಗಿ -1;
            }
            ಆದರೆ (type->ref->c != (ಅಂಕೆ - num0) * *fsize)
                ಹಿಂತಿರುಗಿ -1;
            ಹಿಂತಿರುಗಿ ಅಂಕೆ;
        }
        ಇಲ್ಲದಿದ್ದರೆ { // union
            ಪೂರ್ಣಾಂಕ num0 = ಅಂಕೆ;
            ಗಾಗಿ (ಕ್ಷೇತ್ರ = type->ref->ಮುಂದಿನ; ಕ್ಷೇತ್ರ; ಕ್ಷೇತ್ರ = ಕ್ಷೇತ್ರ->ಮುಂದಿನ) {
                ಪೂರ್ಣಾಂಕ num1 = arm64_hfa_aux(&ಕ್ಷೇತ್ರ->type, fsize, num0);
                ಆದರೆ (num1 == -1)
                    ಹಿಂತಿರುಗಿ -1;
                ಅಂಕೆ = num1 < ಅಂಕೆ ? ಅಂಕೆ : num1;
            }
            ಆದರೆ (type->ref->c != (ಅಂಕೆ - num0) * *fsize)
                ಹಿಂತಿರುಗಿ -1;
            ಹಿಂತಿರುಗಿ ಅಂಕೆ;
        }
    }
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (type->t & VT_ARRAY) { /* handle float array within struct */
        ಪೂರ್ಣಾಂಕ num1;
        ಆದರೆ (!type->ref->c)
            ಹಿಂತಿರುಗಿ ಅಂಕೆ;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, ಅಂಕೆ);
        ಆದರೆ (num1 == -1 || (num1 != ಅಂಕೆ && type->ref->c > 4))
            ಹಿಂತಿರುಗಿ -1;
        num1 = ಅಂಕೆ + type->ref->c * (num1 - ಅಂಕೆ);
        ಆದರೆ (num1 > 4)
            ಹಿಂತಿರುಗಿ -1;
        ಹಿಂತಿರುಗಿ num1;
    }
    ಹಿಂತಿರುಗಿ -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_hfa(CType *type, ಚಿಹ್ನೆರಹಿತ *fsize)
{
    ಆದರೆ ((type->t & VT_BTYPE) == VT_STRUCT) {
        ಪೂರ್ಣಾಂಕ sz = 0;
        ಪೂರ್ಣಾಂಕ n = arm64_hfa_aux(type, &sz, 0);
        ಆದರೆ (0 < n && n <= 4) {
            ಆದರೆ (fsize)
                *fsize = sz;
            ಹಿಂತಿರುಗಿ n;
        }
    }
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ arm64_pcs_aux(ಪೂರ್ಣಾಂಕ variadic, ಪೂರ್ಣಾಂಕ n, CType **type, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *a)
{
    ಪೂರ್ಣಾಂಕ nx = 0; // next integer register
    ಪೂರ್ಣಾಂಕ nv = 0; // next vector register
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ns = 32; // next stack offset
    ಪೂರ್ಣಾಂಕ i;

    ಗಾಗಿ (i = 0; i < n; i++) {
        ಪೂರ್ಣಾಂಕ hfa = arm64_hfa(type[i], 0);
        ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, bt;

        bt = type[i]->t & VT_BTYPE;
        ಆದರೆ (bt == VT_PTR || bt == VT_FUNC)
            ಗಾತ್ರ_2 = align = 8;
        ಇಲ್ಲದಿದ್ದರೆ
            ಗಾತ್ರ_2 = type_ಗಾತ್ರ(type[i], &align);

#ಆದರೆ defined(TCC_ಗುರಿ_MACHO)
        ಆದರೆ (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_PE)
        ಆದರೆ (variadic && i >= variadic) {
            hfa = 0;
            ಆದರೆ (is_float(bt))
                bt = VT_INT, ಗಾತ್ರ_2 = align = 8;
        }
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (hfa)
            // B.2
            ;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2 > 16) {
            // B.3: replace with pointer
            ಆದರೆ (nx < 8)
                a[i] = nx++ << 1 | 1;
            ಇಲ್ಲದಿದ್ದರೆ {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            ಮುಂದುವರಿ;
        }
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_STRUCT)
            // B.4
            ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 7) & ~7;

        // C.1
        ಆದರೆ (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            ಮುಂದುವರಿ;
        }

        // C.2
        ಆದರೆ (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            ಮುಂದುವರಿ;
        }

        // C.3
        ಆದರೆ (hfa) {
            nv = 8;
            ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 7) & ~7;
        }

        // C.4
        ಆದರೆ (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        ಆದರೆ (bt == VT_FLOAT)
            ಗಾತ್ರ_2 = 8;

        // C.6
        ಆದರೆ (hfa || is_float(bt)) {
            a[i] = ns;
            ns += ಗಾತ್ರ_2;
            ಮುಂದುವರಿ;
        }

        // C.7
        ಆದರೆ (bt != VT_STRUCT && ಗಾತ್ರ_2 <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            ಮುಂದುವರಿ;
        }

        // C.8
        ಆದರೆ (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        ಆದರೆ (bt != VT_STRUCT && ಗಾತ್ರ_2 == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            ಮುಂದುವರಿ;
        }

        // C.10
        ಆದರೆ (bt == VT_STRUCT && ಗಾತ್ರ_2 <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (ಗಾತ್ರ_2 + 7) >> 3;
            ಮುಂದುವರಿ;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        ಆದರೆ (bt == VT_STRUCT) {
            a[i] = ns;
            ns += ಗಾತ್ರ_2;
            ಮುಂದುವರಿ;
        }

        // C.14
        ಆದರೆ (ಗಾತ್ರ_2 < 8)
            ಗಾತ್ರ_2 = 8;

        // C.15
        a[i] = ns;
        ns += ಗಾತ್ರ_2;
    }

    ಹಿಂತಿರುಗಿ ns - 32;
}

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ arm64_pcs(ಪೂರ್ಣಾಂಕ variadic, ಪೂರ್ಣಾಂಕ n, CType **type, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *a)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ರಾಶಿ;

    // Return type:
    ಆದರೆ ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    ಇಲ್ಲದಿದ್ದರೆ {
        arm64_pcs_aux(0, 1, type, a);
        ಪ್ರತಿಜ್ಞಾ(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    ರಾಶಿ = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    ಆದರೆ (0) {
        ಪೂರ್ಣಾಂಕ i;
        ಗಾಗಿ (i = 0; i < n; i++) {
            ಆದರೆ (!i)
                ಬರೆ("arm64_pcs return: ");
            ಇಲ್ಲದಿದ್ದರೆ
                ಬರೆ("arm64_pcs arg %d: ", i);
            ಆದರೆ (a[i] == (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)-1)
                ಬರೆ("void\n");
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[i] == 1 && !i)
                ಬರೆ("X8 pointer\n");
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[i] < 16)
                ಬರೆ("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[i] < 32)
                ಬರೆ("V%lu\n", a[i] / 2 - 8);
            ಇಲ್ಲದಿದ್ದರೆ
                ಬರೆ("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    ಹಿಂತಿರುಗಿ ರಾಶಿ;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ n_func_ವಾದಗಳು(CType *type)
{
    ಪೂರ್ಣಾಂಕ n_ವಾದಗಳು = 0;
    Sym *arg;

    ಗಾಗಿ (arg = type->ref->ಮುಂದಿನ; arg; arg = arg->ಮುಂದಿನ)
        n_ವಾದಗಳು++;
    ಹಿಂತಿರುಗಿ n_ವಾದಗಳು;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_sub_sp(uint64_t diff)
{
    ಆದರೆ (!diff)
        ಹಿಂತಿರುಗಿ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಆದರೆ (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        ಹಿಂತಿರುಗಿ;
    }
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (!(diff >> 24)) {
        ಆದರೆ (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        ಆದರೆ (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } ಇಲ್ಲದಿದ್ದರೆ {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ gv_addr(ಪೂರ್ಣಾಂಕ r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    ಹಿಂತಿರುಗಿ gv(r);
}

ST_FUNC ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು)
{
    CType *return_type;
    CType **t;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *a, *a1;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ರಾಶಿ;
    ಪೂರ್ಣಾಂಕ i;
    ಪೂರ್ಣಾಂಕ func_type = vtop[-nb_ವಾದಗಳು].type.ref->f.func_type;
    ಪೂರ್ಣಾಂಕ variadic = (func_type == FUNC_ELLIPSIS);
    ಪೂರ್ಣಾಂಕ old_style = (func_type == FUNC_OLD);
    ಪೂರ್ಣಾಂಕ var_nb_arg = variadic ? n_func_ವಾದಗಳು(&vtop[-nb_ವಾದಗಳು].type) : 0;

    save_regs(nb_ವಾದಗಳು + 1);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gbound_ವಾದಗಳು(nb_ವಾದಗಳು);
#ಆದರೆ_ಅಂತ್ಯ

    return_type = &vtop[-nb_ವಾದಗಳು].type.ref->type;
    ಆದರೆ ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_ವಾದಗಳು;

    t = tcc_malloc((nb_ವಾದಗಳು + 1) * ಗಾತ್ರ(*t));
    a = tcc_malloc((nb_ವಾದಗಳು + 1) * ಗಾತ್ರ(*a));
    a1 = tcc_malloc((nb_ವಾದಗಳು + 1) * ಗಾತ್ರ(*a1));

    t[0] = return_type;
    ಗಾಗಿ (i = 0; i < nb_ವಾದಗಳು; i++)
        t[nb_ವಾದಗಳು - i] = &vtop[-i].type;

    ರಾಶಿ = arm64_pcs(
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#ಆದರೆ_ಅಂತ್ಯ
        var_nb_arg, nb_ವಾದಗಳು + 1, t, a);

    // Allocate space for structs replaced by pointer:
    ಗಾಗಿ (i = nb_ವಾದಗಳು; i; i--)
        ಆದರೆ (a[i] & 1) {
            SValue *arg = &vtop[i - nb_ವಾದಗಳು];
            ಪೂರ್ಣಾಂಕ align, ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&arg->type, &align);
            ಪ್ರತಿಜ್ಞಾ((arg->type.t & VT_BTYPE) == VT_STRUCT);
            ರಾಶಿ = (ರಾಶಿ + align - 1) & -align;
            a1[i] = ರಾಶಿ;
            ರಾಶಿ += ಗಾತ್ರ_2;
        }

    ರಾಶಿ = (ರಾಶಿ + 15) >> 4 << 4;

    ಆದರೆ (ರಾಶಿ >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", ರಾಶಿ);
    arm64_sub_sp(ರಾಶಿ);

    // First pass: set all values on stack
    ಗಾಗಿ (i = nb_ವಾದಗಳು; i; i--) {
        vpushv(vtop - nb_ವಾದಗಳು + i);

        ಆದರೆ (a[i] & 1) {
            // struct replaced by pointer
            ಪೂರ್ಣಾಂಕ r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            ಆದರೆ (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[i] >= 32) {
            // value on stack
            ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                ಪೂರ್ಣಾಂಕ r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_ಗಾತ್ರ(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            ಇಲ್ಲದಿದ್ದರೆ {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    ಗಾಗಿ (i = nb_ವಾದಗಳು; i; i--, vtop--) {
        ಆದರೆ (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            ಆದರೆ ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                ಇಲ್ಲದಿದ್ದರೆ
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                ಪೂರ್ಣಾಂಕ align, ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&vtop->type, &align);
                ಆದರೆ (ಗಾತ್ರ_2) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, ಗಾತ್ರ_2);
                }
            }
            ಇಲ್ಲದಿದ್ದರೆ
                gv(RC_R(a[i] / 2));
        }
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[i] < 32) {
            // value in floating-point registers
            ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                ಆದರೆ (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    ಗಾಗಿ (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } ಇಲ್ಲದಿದ್ದರೆ {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            ಇಲ್ಲದಿದ್ದರೆ
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    ಆದರೆ ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        ಆದರೆ (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        ಇಲ್ಲದಿದ್ದರೆ
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    ಆದರೆ (ರಾಶಿ & 0xfff)
        o(0x910003ff | (ರಾಶಿ & 0xfff) << 10); // add sp,sp,#(n)
    ಆದರೆ (ರಾಶಿ >> 12)
        o(0x914003ff | (ರಾಶಿ >> 12) << 10);

    {
        ಪೂರ್ಣಾಂಕ rt = return_type->t;
        ಪೂರ್ಣಾಂಕ bt = rt & VT_BTYPE;
        ಆದರೆ (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            ಆದರೆ (a[0] == 0) {
                ಪೂರ್ಣಾಂಕ align, ಗಾತ್ರ_2 = type_ಗಾತ್ರ(return_type, &align);
                ಪ್ರತಿಜ್ಞಾ(ಗಾತ್ರ_2 <= 16);
                ಆದರೆ (ಗಾತ್ರ_2 > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2)
                    arm64_strx(ಗಾತ್ರ_2 > 4 ? 3 : ಗಾತ್ರ_2 > 2 ? 2 : ಗಾತ್ರ_2 > 1, 0, 8, 0);

            }
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                ಗಾಗಿ (j = 0; j < n; j++)
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

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ arm64_func_va_list_ರಾಶಿ;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_func_va_list_gr_offs;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_func_va_list_vr_offs;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_func_sub_sp_ಸ್ಥಾನಾಂತರ;

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ arm64_func_ಆರಂಭ_ಸ್ಥಾನಾಂತರ;
#ವ್ಯಾಖ್ಯಾನಿಸು ARM64_FUNC_ರಾಶಿ_ಸಿದ್ಧತೆ_SLOTS 6

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ arm64_pe_param_off(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ a)
{
    ಹಿಂತಿರುಗಿ a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#ಆದರೆ_ಅಂತ್ಯ

ST_FUNC ಶೂನ್ಯ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ಪೂರ್ಣಾಂಕ n = 0;
    ಪೂರ್ಣಾಂಕ i = 0;
    Sym *sym;
    CType **t;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *a;
    ಪೂರ್ಣಾಂಕ use_x8 = 0;
    ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_int = 0;
    ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_float = 0;
    ಪೂರ್ಣಾಂಕ variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    ಪೂರ್ಣಾಂಕ var_nb_arg = variadic ? n_func_ವಾದಗಳು(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    ಗಾಗಿ (sym = func_type->ref; sym; sym = sym->ಮುಂದಿನ)
        ++n;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    n += variadic;
#ಆದರೆ_ಅಂತ್ಯ

    t = tcc_malloc(n * ಗಾತ್ರ(*t));
    a = tcc_malloc(n * ಗಾತ್ರ(*a));
    ಗಾಗಿ (sym = func_type->ref; sym; sym = sym->ಮುಂದಿನ)
        t[i++] = &sym->type;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಆದರೆ (variadic)
        t[i] = &int_type;
#ಆದರೆ_ಅಂತ್ಯ

    arm64_func_va_list_ರಾಶಿ = arm64_pcs(var_nb_arg, n, t, a);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಆದರೆ (variadic)
        arm64_func_va_list_ರಾಶಿ = arm64_pe_param_off(a[n - 1]);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(TCC_ಗುರಿ_MACHO)
    ಆದರೆ (variadic) {
        use_x8 = 1;
        ಕೊನೆಯ_int = 4;
        ಕೊನೆಯ_float = 4;
    }
#ಆದರೆ_ಅಂತ್ಯ

    ಆದರೆ (a && a[0] == 1)
        use_x8 = 1;
    ಗಾಗಿ (i = 1, sym = func_type->ref->ಮುಂದಿನ; sym; i++, sym = sym->ಮುಂದಿನ) {
        ಆದರೆ (a[i] < 16) {
            ಪೂರ್ಣಾಂಕ ಕೊನೆಯ, align, ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&sym->type, &align);
	    ಕೊನೆಯ = a[i] / 4 + 1 + (ಗಾತ್ರ_2 - 1) / 8;
	    ಕೊನೆಯ_int = ಕೊನೆಯ > ಕೊನೆಯ_int ? ಕೊನೆಯ : ಕೊನೆಯ_int;
	}
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[i] < 32) {
            ಪೂರ್ಣಾಂಕ ಕೊನೆಯ, hfa = arm64_hfa(&sym->type, 0);
	    ಕೊನೆಯ = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    ಕೊನೆಯ_float = ಕೊನೆಯ > ಕೊನೆಯ_float ? ಕೊನೆಯ : ಕೊನೆಯ_float;
	}
    }

    ಕೊನೆಯ_int = ಕೊನೆಯ_int > 4 ? 4 : ಕೊನೆಯ_int;
    ಕೊನೆಯ_float = ಕೊನೆಯ_float > 4 ? 4 : ಕೊನೆಯ_float;

    arm64_func_ಆರಂಭ_ಸ್ಥಾನಾಂತರ = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    ಗಾಗಿ (i = 0; i < ಕೊನೆಯ_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    ಆದರೆ (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    ಗಾಗಿ (i = 0; i < ಕೊನೆಯ_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    ಗಾಗಿ (i = 1, sym = func_type->ref->ಮುಂದಿನ; sym; i++, sym = sym->ಮುಂದಿನ) {
        ಪೂರ್ಣಾಂಕ off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_ಗಣ_param(sym, off, a[i] & 1);

        ಆದರೆ (a[i] < 16) {
            ಪೂರ್ಣಾಂಕ align, ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && ಗಾತ್ರ_2 > 8)) * 8;
        }
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        ಆದರೆ (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            ಆದರೆ (k > 0 && sz < 16)
                ಗಾಗಿ (j = 0; j < k; j++) {
                    o(0x3d0003e0 | -(sz & 8) << 27 | (sz & 4) << 29 |
                      ((a[i] - 16) / 2 + j) | (off / sz + j) << 10);
                    // str ([sdq])(j),[sp,#(j * sz)]
                }
        }
    }

    tcc_free(a);
    tcc_free(t);

    arm64_func_sub_sp_ಸ್ಥಾನಾಂತರ = ind;
    /* In gfunc_epilog these will be replaced with stack setup code. */
    ಗಾಗಿ (i = 0; i < ARM64_FUNC_ರಾಶಿ_ಸಿದ್ಧತೆ_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#ಆದರೆ_ಅಂತ್ಯ
}

ST_FUNC ಶೂನ್ಯ gen_va_ಆರಂಭ(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಆದರೆ (arm64_func_va_list_ರಾಶಿ) {
        arm64_movimm(30, arm64_func_va_list_ರಾಶಿ);
        o(0x8b1e03be); // add x30,x29,x30
    } ಇಲ್ಲದಿದ್ದರೆ
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ (arm64_func_va_list_ರಾಶಿ) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_ರಾಶಿ + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    ಇಲ್ಲದಿದ್ದರೆ
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#ಆದರೆ !defined(TCC_ಗುರಿ_MACHO)
    ಆದರೆ (arm64_func_va_list_gr_offs) {
        ಆದರೆ (arm64_func_va_list_ರಾಶಿ)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    ಆದರೆ (arm64_func_va_list_vr_offs) {
        o(0x910243be); // add x30,x29,#144
        o(0xf900081e | r << 5); // str x30,[x(r),#16]
    }

    arm64_movimm(30, arm64_func_va_list_gr_offs);
    o(0xb900181e | r << 5); // str w30,[x(r),#24]

    arm64_movimm(30, arm64_func_va_list_vr_offs);
    o(0xb9001c1e | r << 5); // str w30,[x(r),#28]
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

    --vtop;
}

ST_FUNC ಶೂನ್ಯ gen_va_arg(CType *t)
{
    ಪೂರ್ಣಾಂಕ align, ಗಾತ್ರ_2 = type_ಗಾತ್ರ(t, &align);
    uint32_t r0, r1;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಪೂರ್ಣಾಂಕ ಪರೋಕ್ಷ = 0, ಸ್ಥಾನ = (ಗಾತ್ರ_2 + 7) & -8;

    ಆದರೆ (ಗಾತ್ರ_2 > 16)
        ಪರೋಕ್ಷ = 1, ಸ್ಥಾನ = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    ಆದರೆ (ಸ್ಥಾನ) {
        ಆದರೆ (ಸ್ಥಾನ == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        ಆದರೆ (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ಸ್ಥಾನ << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    ಆದರೆ (ಪರೋಕ್ಷ)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#ಇಲ್ಲದಿದ್ದರೆ /* !PE */
    ಚಿಹ್ನೆರಹಿತ fsize = ಗಾತ್ರ_2, hfa = 1;

    ಆದರೆ (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    ಆದರೆ (!hfa) {
        uint32_t n = ಗಾತ್ರ_2 > 16 ? 8 : (ಗಾತ್ರ_2 + 7) & -8;

#ಆದರೆ !defined(TCC_ಗುರಿ_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        ಆದರೆ (align == 16) {
            ಪ್ರತಿಜ್ಞಾ(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#ಆದರೆ_ಅಂತ್ಯ

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ಆದರೆ (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#ಆದರೆ !defined(TCC_ಗುರಿ_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#ಆದರೆ_ಅಂತ್ಯ

        ಆದರೆ (ಗಾತ್ರ_2 > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        uint32_t ssz = (ಗಾತ್ರ_2 + 7) & -(uint32_t)8;
#ಆದರೆ !defined(TCC_ಗುರಿ_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#ಆದರೆ_ಅಂತ್ಯ
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ಆದರೆ (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#ಆದರೆ !defined(TCC_ಗುರಿ_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        ಆದರೆ (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        ಇಲ್ಲದಿದ್ದರೆ {
            // We need to change the layout of this HFA.
            // Get some space on the stack using global variable "loc":
            loc = (loc - ಗಾತ್ರ_2) & -(uint32_t)align;
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
        write32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + b2, ARM64_B | ((ind - b2) >> 2));
#ಆದರೆ_ಅಂತ್ಯ
    }
#ಆದರೆ_ಅಂತ್ಯ /* not pe */
}

ST_FUNC ಪೂರ್ಣಾಂಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಂಕ variadic, CType *ret,
                       ಪೂರ್ಣಾಂಕ *align, ಪೂರ್ಣಾಂಕ *regsize)
{
    ಹಿಂತಿರುಗಿ 0;
}

ST_FUNC ಶೂನ್ಯ gfunc_return(CType *func_type)
{
    CType *t = func_type;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ a;

    arm64_pcs(0, 1, &t, &a);

    ಆಯ್ಕೆ (a) {
    ಸ್ಥಿತಿ -1:
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 0:
        ಆದರೆ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            ಪೂರ್ಣಾಂಕ align, ಗಾತ್ರ_2 = type_ಗಾತ್ರ(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, ಗಾತ್ರ_2);
        }
        ಇಲ್ಲದಿದ್ದರೆ
            gv(RC_IRET);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 1: {
        CType type = *func_type;
        mk_ಸೂಚಕ(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        ನಿಲ್ಲಿಸು;
    }
    ಸ್ಥಿತಿ 16:
        ಆದರೆ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          ಗಾಗಿ (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        ಇಲ್ಲದಿದ್ದರೆ
            gv(RC_FRET);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
      ಪ್ರತಿಜ್ಞಾ(0);
    }
    vtop--;
}

ST_FUNC ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#ಆದರೆ_ಅಂತ್ಯ

    ಆದರೆ (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        ಪೂರ್ಣಾಂಕ i;
        addr_t saved_ind = ind;
        addr_t patch_ಕೊನೆ = arm64_func_sub_sp_ಸ್ಥಾನಾಂತರ + ARM64_FUNC_ರಾಶಿ_ಸಿದ್ಧತೆ_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_ಸ್ಥಾನಾಂತರ;
        arm64_sub_sp(diff);
        ಗಾಗಿ (i = ind; i < patch_ಕೊನೆ; i += 4)
            write32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + i, ARM64_NOP); // nop
        ind = saved_ind;
    }
    o(0x910003bf); // mov sp,x29
    o(0xa8ce7bfd); // ldp x29,x30,[sp],#224

    o(0xd65f03c0); // ret

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    pe_ಕೂಡಿಸು_unwind_ದತ್ತಾಂಶ(arm64_func_ಆರಂಭ_ಸ್ಥಾನಾಂತರ, ind, -loc);
#ಆದರೆ_ಅಂತ್ಯ
}

ST_FUNC ಶೂನ್ಯ gen_fill_nops(ಪೂರ್ಣಾಂಕ ಬೈಟುಗಳು)
{
    ಆದರೆ ((ಬೈಟುಗಳು & 3))
      tcc_error("alignment of code section not multiple of 4");
    ಆಗ (ಬೈಟುಗಳು > 0) {
	o(ARM64_NOP); // nop
	ಬೈಟುಗಳು -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC ಪೂರ್ಣಾಂಕ gjmp(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ r = ind;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ t;
    o(t);
    ಹಿಂತಿರುಗಿ r;
}

// Generate branch to known address:
ST_FUNC ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಂಕ a)
{
    ಪ್ರತಿಜ್ಞಾ(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC ಪೂರ್ಣಾಂಕ gjmp_append(ಪೂರ್ಣಾಂಕ n, ಪೂರ್ಣಾಂಕ t)
{
    ಶೂನ್ಯ *p;
    /* insert vtop->c jump list in t */
    ಆದರೆ (n) {
        uint32_t n1 = n, n2;
        ಆಗ ((n2 = read32le(p = cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    ಹಿಂತಿರುಗಿ t;
}

ಶೂನ್ಯ arm64_vset_VT_CMP(ಪೂರ್ಣಾಂಕ op)
{
    ಆದರೆ (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_gen_opil(ಪೂರ್ಣಾಂಕ op, uint32_t l);

ಸ್ಥಿರ ಶೂನ್ಯ arm64_ತುಂಬು_cmp(ಪೂರ್ಣಾಂಕ r, SValue *sv)
{
    sv->r = sv->cmp_r;
    ಆದರೆ (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    ಆದರೆ (r != sv->r) {
        ತುಂಬು(r, sv);
        sv->r = r;
    }
}

ST_FUNC ಪೂರ್ಣಾಂಕ gjmp_cond(ಪೂರ್ಣಾಂಕ op, ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ bt = vtop->type.t & VT_BTYPE;

    ಪೂರ್ಣಾಂಕ inv = op & 1;
    vtop->r = vtop->cmp_r;

    ಆದರೆ (bt == VT_LDOUBLE) {
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
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    ಹಿಂತಿರುಗಿ gjmp(t);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_iconst(uint64_t *val, SValue *sv)
{
    ಆದರೆ ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (val) {
        ಪೂರ್ಣಾಂಕ t = sv->type.t;
	ಪೂರ್ಣಾಂಕ bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    ಹಿಂತಿರುಗಿ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_gen_opic(ಪೂರ್ಣಾಂಕ op, uint32_t l, ಪೂರ್ಣಾಂಕ rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    ಆದರೆ (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    ಆಯ್ಕೆ (op) {

    ಸ್ಥಿತಿ '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        ಆದರೆ (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        ಇಲ್ಲದಿದ್ದರೆ {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        ಹಿಂತಿರುಗಿ 1;
      }

    ಸ್ಥಿತಿ '-':
        ಆದರೆ (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        ಇಲ್ಲದಿದ್ದರೆ {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        ಹಿಂತಿರುಗಿ 1;

    ಸ್ಥಿತಿ '^':
        ಆದರೆ (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            ಹಿಂತಿರುಗಿ 1;
        }
        // fall through
    ಸ್ಥಿತಿ '&':
    ಸ್ಥಿತಿ '|': {
        ಪೂರ್ಣಾಂಕ e = arm64_encode_bimm64(l ? val : val | val << 32);
        ಆದರೆ (e < 0)
            ಹಿಂತಿರುಗಿ 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        ಹಿಂತಿರುಗಿ 1;
    }

    ಸ್ಥಿತಿ TOK_SAR:
    ಸ್ಥಿತಿ TOK_SHL:
    ಸ್ಥಿತಿ TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        ಆದರೆ (rev)
            ಹಿಂತಿರುಗಿ 0;
        ಆದರೆ (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            ಹಿಂತಿರುಗಿ 1;
        }
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        ಇಲ್ಲದಿದ್ದರೆ
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        ಹಿಂತಿರುಗಿ 1;
    }

    }
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_gen_opil(ಪೂರ್ಣಾಂಕ op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        ಪೂರ್ಣಾಂಕ rev = 1;

        ಆದರೆ (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        ಆದರೆ (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            ಆದರೆ (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                ಹಿಂತಿರುಗಿ;
            }
        }
        ಆದರೆ (!rev)
            vswap();
    }

    gv2(RC_INT, RC_INT);
    ಪ್ರತಿಜ್ಞಾ(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = intr(vtop[-1].r);
    b = intr(vtop[0].r);
    vtop -= 2;
    x = get_reg(RC_INT);
    ++vtop;
    vtop[0].r = x;
    x = intr(x);

    ಆಯ್ಕೆ (op) {
    ಸ್ಥಿತಿ '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '/':
    ಸ್ಥಿತಿ TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಪ್ರತಿಜ್ಞಾ(0);
    }
}

ST_FUNC ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಂಕ op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಂಕ op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಂಕ op)
{
    uint32_t x, a, b, dbl;
    ಪೂರ್ಣಾಂಕ bt = vtop[0].type.t & VT_BTYPE;

    ಆದರೆ (op == TOK_NEG) {
        ಆದರೆ (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } ಇಲ್ಲದಿದ್ದರೆ {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        ಹಿಂತಿರುಗಿ;
    }

    ಆದರೆ (bt == VT_LDOUBLE) {
        CType type = vtop[0].type;
        ಪೂರ್ಣಾಂಕ func = 0;
        ಪೂರ್ಣಾಂಕ cond = -1;
        ಆಯ್ಕೆ (op) {
        ಸ್ಥಿತಿ '*': func = TOK___multf3; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '+': func = TOK___addtf3; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '-': func = TOK___subtf3; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '/': func = TOK___divtf3; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_EQ: func = TOK___eqtf2; cond = 1; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_NE: func = TOK___netf2; cond = 0; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_LT: func = TOK___lttf2; cond = 10; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_GE: func = TOK___getf2; cond = 11; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_LE: func = TOK___letf2; cond = 12; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_GT: func = TOK___gttf2; cond = 13; ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ: ಪ್ರತಿಜ್ಞಾ(0); ನಿಲ್ಲಿಸು;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        ಆದರೆ (cond < 0)
            vtop->type = type;
        ಇಲ್ಲದಿದ್ದರೆ {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        ಹಿಂತಿರುಗಿ;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    ಪ್ರತಿಜ್ಞಾ(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    ಆಯ್ಕೆ (op) {
    ಸ್ಥಿತಿ TOK_EQ: ಸ್ಥಿತಿ TOK_NE:
    ಸ್ಥಿತಿ TOK_LT: ಸ್ಥಿತಿ TOK_GE: ಸ್ಥಿತಿ TOK_LE: ಸ್ಥಿತಿ TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        ನಿಲ್ಲಿಸು;
    }

    ಆಯ್ಕೆ (op) {
    ಸ್ಥಿತಿ '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಪ್ರತಿಜ್ಞಾ(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC ಶೂನ್ಯ gen_cvt_sxtw(ಶೂನ್ಯ)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಂಕ t)
{
    ಆದರೆ (t == VT_LDOUBLE) {
        ಪೂರ್ಣಾಂಕ f = vtop->type.t;
        ಪೂರ್ಣಾಂಕ func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        ಹಿಂತಿರುಗಿ;
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        ಪೂರ್ಣಾಂಕ d, n = intr(gv(RC_INT));
        ಪೂರ್ಣಾಂಕ s = !(vtop->type.t & VT_UNSIGNED);
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

ST_FUNC ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಂಕ t)
{
    ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        ಪೂರ್ಣಾಂಕ func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        ಹಿಂತಿರುಗಿ;
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        ಪೂರ್ಣಾಂಕ d, n = fltr(gv(RC_FLOAT));
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

ST_FUNC ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ f = vtop[0].type.t & VT_BTYPE;
    ಪ್ರತಿಜ್ಞಾ(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    ಪ್ರತಿಜ್ಞಾ(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    ಆದರೆ (t == f)
        ಹಿಂತಿರುಗಿ;

    ಆದರೆ (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        ಪೂರ್ಣಾಂಕ func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        ಪೂರ್ಣಾಂಕ x, a;
        gv(RC_FLOAT);
        ಪ್ರತಿಜ್ಞಾ(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        ಆದರೆ (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        ಇಲ್ಲದಿದ್ದರೆ
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv)
{
    ಪೂರ್ಣಾಂಕ r1, r2;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    arm64_sym(r1, sv->sym, 0);
    o(ARM64_LDR_X | ARM64_RN(intr(r1)) | intr(r2)); // ldr r2, [r1]
    o(0x91000400 | (intr(r2)<<5) | intr(r2)); // add r2, r2, #1
    o(0xf9000000 | (intr(r1)<<5) | intr(r2)); // str r2, [r1]
    vpop();
}

ST_FUNC ಶೂನ್ಯ ggoto(ಶೂನ್ಯ)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC ಶೂನ್ಯ gen_clear_cache(ಶೂನ್ಯ)
{
    uint32_t beg, ಕೊನೆ, dsz, isz, p, lab1, b1;
    gv2(RC_INT, RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    beg = intr(vtop[-4].r); // x0
    ಕೊನೆ = intr(vtop[-3].r); // x1
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
    write32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | ಕೊನೆ << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0x51000400 | p | isz << 5); // sub w(p),w(isz),#1
    o(0x8a240004 | p | beg << 5 | p << 16); // bic x(p),x(beg),x(p)
    b1 = ind; o(ARM64_B); // b
    lab1 = ind;
    o(0xd50b7520 | p); // ic ivau,x(p)
    o(0x8b000000 | p | p << 5 | isz << 16); // add x(p),x(p),x(isz)
    write32le(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | ಕೊನೆ << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0xd5033fdf); // isb
}

ST_FUNC ಶೂನ್ಯ gen_vla_sp_save(ಪೂರ್ಣಾಂಕ addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC ಶೂನ್ಯ gen_vla_sp_restore(ಪೂರ್ಣಾಂಕ addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC ಶೂನ್ಯ gen_vla_alloc(CType *type, ಪೂರ್ಣಾಂಕ align) {
    uint32_t r;
#ಆದರೆ defined(CONFIG_TCC_BCHECK)
    ಆದರೆ (tcc_state->do_bounds_check)
        vpushv(vtop);
#ಆದರೆ_ಅಂತ್ಯ
    r = intr(gv(RC_INT));
#ಆದರೆ defined(CONFIG_TCC_BCHECK)
    ಆದರೆ (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#ಆದರೆ defined(CONFIG_TCC_BCHECK)
    ಆದರೆ (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x910003e0 | vtop->r); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_ಕೂಡಿಸು_epilog = 1;
    }
#ಆದರೆ_ಅಂತ್ಯ
}

/* end of A64 code generator */
/*************************************************************/
#ಆದರೆ_ಅಂತ್ಯ
/*************************************************************/
