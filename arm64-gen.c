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

#ifdef TARGET_DEFS_ONLY

// Number of registers available to allocator:
#define NB_REGS 28 // x0-x18, x30, v0-v7

#define TREG_R(x) (x) // x = 0..18
#define TREG_R30  19
#define TREG_F(x) (x + 20) // x = 0..7

// Register classes sorted from more general to more precise:
#define RC_INT (1 << 0)
#define RC_FLOAT (1 << 1)
#define RC_R(x) (1 << (2 + (x))) // x = 0..18
#define RC_R30  (1 << 21)
#define RC_F(x) (1 << (22 + (x))) // x = 0..7

#define RC_IRET (RC_R(0)) // int return register class
#define RC_FRET (RC_F(0)) // float return register class

#define REG_IRET (TREG_R(0)) // int return register number
#define REG_FRET (TREG_F(0)) // float return register number

#define PTR_SIZE 8

#define LDOUBLE_SIZE 16
#define LDOUBLE_ALIGN 16

#define MAX_ALIGN 16

#ಯದಿ !defined(TCC_TARGET_MACHO) && !defined(TCC_TARGET_PE)
#define CHAR_IS_UNSIGNED
#endif

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#define PROMOTE_RET
/******************************************************/
#ಅನ್ಯಥಾ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"
#ಅನ್ತರ್ಭಾವ <assert.h>

ST_DATA ಧ್ರುವ ವರ್ಣ * ಧ್ರುವ target_machine_defs =
    "__aarch64__\0"
#ಯದಿ defined(TCC_TARGET_MACHO)
    "__arm64__\0"
#endif
    "__AARCH64EL__\0"
    ;

ST_DATA ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ reg_classes[NB_REGS] = {
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

#ಯದಿ defined(CONFIG_TCC_BCHECK)
ಸ್ಥಿರ addr_t func_bound_offset;
ಸ್ಥಿರ unsigned long func_bound_ind;
ST_DATA ಪೂರ್ಣಾಙ್ಕ func_bound_add_epilog;
#endif

#define IS_FREG(x) ((x) >= TREG_F(0))

ಸ್ಥಿರ uint32_t intr(ಪೂರ್ಣಾಙ್ಕ r)
{
    ಪ್ರತಿಜ್ಞಾ(TREG_R(0) <= r && r <= TREG_R30);
    ಪ್ರತ್ಯಾಗಮ r < TREG_R30 ? r : 30;
}

ಸ್ಥಿರ uint32_t fltr(ಪೂರ್ಣಾಙ್ಕ r)
{
    ಪ್ರತಿಜ್ಞಾ(TREG_F(0) <= r && r <= TREG_F(7));
    ಪ್ರತ್ಯಾಗಮ r - TREG_F(0);
}

// Add an instruction to text section:
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

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_encode_bimm64(uint64_t x)
{
    ಪೂರ್ಣಾಙ್ಕ neg = x & 1;
    ಪೂರ್ಣಾಙ್ಕ rep, pos, len;

    ಯದಿ (neg)
        x = ~x;
    ಯದಿ (!x)
        ಪ್ರತ್ಯಾಗಮ -1;

    ಯದಿ (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    ಅನ್ಯಥಾ ಯದಿ (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    ಅನ್ಯಥಾ ಯದಿ (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    ಅನ್ಯಥಾ ಯದಿ (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    ಅನ್ಯಥಾ ಯದಿ (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    ಅನ್ಯಥಾ
        rep = 64;

    pos = 0;
    ಯದಿ (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    ಯದಿ (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    ಯದಿ (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    ಯದಿ (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    ಯದಿ (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    ಯದಿ (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    ಯದಿ (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    ಯದಿ (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    ಯದಿ (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    ಯದಿ (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    ಯದಿ (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    ಯದಿ (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    ಯದಿ (x)
        ಪ್ರತ್ಯಾಗಮ -1;
    ಯದಿ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    ಪ್ರತ್ಯಾಗಮ ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ಸ್ಥಿರ uint32_t arm64_movi(ಪೂರ್ಣಾಙ್ಕ r, uint64_t x)
{
    uint64_t m = 0xffff;
    ಪೂರ್ಣಾಙ್ಕ e;
    ಯದಿ (!(x & ~m))
        ಪ್ರತ್ಯಾಗಮ ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    ಯದಿ (!(x & ~(m << 16)))
        ಪ್ರತ್ಯಾಗಮ (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    ಯದಿ (!(x & ~(m << 32)))
        ಪ್ರತ್ಯಾಗಮ (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    ಯದಿ (!(x & ~(m << 48)))
        ಪ್ರತ್ಯಾಗಮ (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    ಯದಿ ((x & ~m) == m << 16)
        ಪ್ರತ್ಯಾಗಮ (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    ಯದಿ ((x & ~(m << 16)) == m)
        ಪ್ರತ್ಯಾಗಮ (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    ಯದಿ (!~(x | m))
        ಪ್ರತ್ಯಾಗಮ (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    ಯದಿ (!~(x | m << 16))
        ಪ್ರತ್ಯಾಗಮ (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    ಯದಿ (!~(x | m << 32))
        ಪ್ರತ್ಯಾಗಮ (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ಯದಿ (!~(x | m << 48))
        ಪ್ರತ್ಯಾಗಮ (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ಯದಿ (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        ಪ್ರತ್ಯಾಗಮ (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    ಯದಿ ((e = arm64_encode_bimm64(x)) >= 0)
        ಪ್ರತ್ಯಾಗಮ (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_movimm(ಪೂರ್ಣಾಙ್ಕ r, uint64_t x)
{
    uint32_t i;
    ಯದಿ ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    ಅನ್ಯಥಾ {
        // MOVZ/MOVN and 1-3 MOVKs
        ಪೂರ್ಣಾಙ್ಕ z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        ಪ್ರತಿ (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        ಯದಿ (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        ಪ್ರತಿ (i = 0; i < 64; i += 16)
            ಯದಿ (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                ಭಙ್ಗ;
            }
        ಪ್ರತಿ (i += 16; i < 64; i += 16)
            ಯದಿ (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC ಶೂನ್ಯ gsym_addr(ಪೂರ್ಣಾಙ್ಕ t_, ಪೂರ್ಣಾಙ್ಕ a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    ಯಾವತ್ (t) {
        unsigned ವರ್ಣ *ptr = cur_text_section->data + t;
        uint32_t next = read32le(ptr);
        ಯದಿ (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = next;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_type_size(ಪೂರ್ಣಾಙ್ಕ t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    ವಿಕಲ್ಪ (t & VT_BTYPE) {
    ಪಕ್ಷ VT_BYTE: ಪ್ರತ್ಯಾಗಮ 0;
    ಪಕ್ಷ VT_SHORT: ಪ್ರತ್ಯಾಗಮ 1;
    ಪಕ್ಷ VT_INT: ಪ್ರತ್ಯಾಗಮ 2;
    ಪಕ್ಷ VT_LLONG: ಪ್ರತ್ಯಾಗಮ 3;
    ಪಕ್ಷ VT_PTR: ಪ್ರತ್ಯಾಗಮ 3;
    ಪಕ್ಷ VT_FUNC: ಪ್ರತ್ಯಾಗಮ 3;
    ಪಕ್ಷ VT_STRUCT: ಪ್ರತ್ಯಾಗಮ 3;
    ಪಕ್ಷ VT_FLOAT: ಪ್ರತ್ಯಾಗಮ 2;
    ಪಕ್ಷ VT_DOUBLE: ಪ್ರತ್ಯಾಗಮ 3;
    ಪಕ್ಷ VT_LDOUBLE: ಪ್ರತ್ಯಾಗಮ 4;
    ಪಕ್ಷ VT_BOOL: ಪ್ರತ್ಯಾಗಮ 0;
    }
    ಪ್ರತಿಜ್ಞಾ(0);
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_spoff(ಪೂರ್ಣಾಙ್ಕ reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    ಯದಿ (sub)
        off = -off;
    ಯದಿ (off < 4096)
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    ಅನ್ಯಥಾ {
        arm64_movimm(30, off);
        o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

ಸ್ಥಿರ uint64_t arm64_check_offset(ಪೂರ್ಣಾಙ್ಕ sz_, uint64_t off)
{
#ifndef TCC_TARGET_PE
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    ಯದಿ (!(off & ~scaled_mask) || (off < 256 || -off <= 256))
        ಪ್ರತ್ಯಾಗಮ ~0ull;
    ಯದಿ (off & scaled_mask)
        ಪ್ರತ್ಯಾಗಮ scaled_mask;
    ಯದಿ (off & 0x1fful)
        ಪ್ರತ್ಯಾಗಮ 0x1fful;
#endif
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_ldrx(ಪೂರ್ಣಾಙ್ಕ sg, ಪೂರ್ಣಾಙ್ಕ sz_, ಪೂರ್ಣಾಙ್ಕ dst, ಪೂರ್ಣಾಙ್ಕ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    ಯದಿ (sz >= 2)
        sg = 0;
    ಯದಿ (!(off & ~scaled_mask))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    ಅನ್ಯಥಾ ಯದಿ (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    ಅನ್ಯಥಾ {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_ldrv(ಪೂರ್ಣಾಙ್ಕ sz_, ಪೂರ್ಣಾಙ್ಕ dst, ಪೂರ್ಣಾಙ್ಕ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    ಯದಿ (!(off & ~scaled_mask))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    ಅನ್ಯಥಾ ಯದಿ (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    ಅನ್ಯಥಾ {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_ldrs(ಪೂರ್ಣಾಙ್ಕ reg_, ಪೂರ್ಣಾಙ್ಕ size)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    ವಿಕಲ್ಪ (size) {
    ಸ್ವಭಾವ: ಪ್ರತಿಜ್ಞಾ(0); ಭಙ್ಗ;
    ಪಕ್ಷ 0:
        /* Can happen with zero size structs */
        ಭಙ್ಗ;
    ಪಕ್ಷ 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        ಭಙ್ಗ;
    ಪಕ್ಷ 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ಭಙ್ಗ;
    ಪಕ್ಷ 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ಭಙ್ಗ;
    ಪಕ್ಷ 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ಭಙ್ಗ;
    ಪಕ್ಷ 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        ಭಙ್ಗ;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_strx(ಪೂರ್ಣಾಙ್ಕ sz_, ಪೂರ್ಣಾಙ್ಕ dst, ಪೂರ್ಣಾಙ್ಕ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    ಯದಿ (!(off & ~scaled_mask))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    ಅನ್ಯಥಾ ಯದಿ (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    ಅನ್ಯಥಾ {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_strv(ಪೂರ್ಣಾಙ್ಕ sz_, ಪೂರ್ಣಾಙ್ಕ dst, ಪೂರ್ಣಾಙ್ಕ bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    ಯದಿ (!(off & ~scaled_mask))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    ಅನ್ಯಥಾ ಯದಿ (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    ಅನ್ಯಥಾ {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_reloca(Sym *sym, ಪೂರ್ಣಾಙ್ಕ reloc_type, uint64_t addend)
{
    greloca(cur_text_section, sym, ind, reloc_type, addend);
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_sym(ಪೂರ್ಣಾಙ್ಕ r, Sym *sym, addr_t addend)
{
    ಯದಿ (sym->type.t & VT_TLS) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        ಪೂರ್ಣಾಙ್ಕ r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#ಅನ್ಯಥಾ
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#endif
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_HI12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_LO12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#ifndef TCC_TARGET_PE /* no elf-style GOT on Windows */
    } ಅನ್ಯಥಾ ಯದಿ (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_PAGE, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        ಯದಿ (addend > 0xffffff) {
            ಪೂರ್ಣಾಙ್ಕ t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } ಅನ್ಯಥಾ {
           ಯದಿ (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_ADD_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            ಯದಿ (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#endif
    } ಅನ್ಯಥಾ {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_ADD_ABS_LO12_NC, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_load_cmp(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv);

ST_FUNC ಶೂನ್ಯ load(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ svtt = sv->type.t;
    ಪೂರ್ಣಾಙ್ಕ svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    ಪೂರ್ಣಾಙ್ಕ svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    ಪೂರ್ಣಾಙ್ಕ sb = !(svtt & VT_UNSIGNED);
    ಪೂರ್ಣಾಙ್ಕ sz = arm64_type_size(svtt);

    ಯದಿ (svr == (VT_LOCAL | VT_LVAL)) {
        ಯದಿ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        ಅನ್ಯಥಾ
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        ಯದಿ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        ಅನ್ಯಥಾ
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svrv < VT_CONST && (svr & VT_LVAL)) {
        ಯದಿ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        ಅನ್ಯಥಾ
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        ಯದಿ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & mask);
        ಅನ್ಯಥಾ
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & mask);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr < VT_CONST) {
        ಯದಿ (IS_FREG(r) && IS_FREG(svr))
            ಯದಿ (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            ಅನ್ಯಥಾ
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        ಅನ್ಯಥಾ ಯದಿ (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        ಅನ್ಯಥಾ
            ಪ್ರತಿಜ್ಞಾ(0);
      ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr == VT_LOCAL) {
        ಯದಿ (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        ಅನ್ಯಥಾ {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr == VT_JMP || svr == VT_JMPI) {
        ಪೂರ್ಣಾಙ್ಕ t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        ಯದಿ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        ಅನ್ಯಥಾ
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr == VT_CMP) {
        arm64_load_cmp(r, sv);
        ಪ್ರತ್ಯಾಗಮ;
    }

    printf("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (long)svcul);
    ಪ್ರತಿಜ್ಞಾ(0);
}

ST_FUNC ಶೂನ್ಯ store(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ svtt = sv->type.t;
    ಪೂರ್ಣಾಙ್ಕ svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    ಪೂರ್ಣಾಙ್ಕ svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    ಪೂರ್ಣಾಙ್ಕ sz = arm64_type_size(svtt);

    ಯದಿ (svr == (VT_LOCAL | VT_LVAL)) {
        ಯದಿ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        ಅನ್ಯಥಾ
            arm64_strx(sz, intr(r), 29, svcoff);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        ಯದಿ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        ಅನ್ಯಥಾ
            arm64_strx(sz, intr(r), 30, 0);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svrv < VT_CONST && (svr & VT_LVAL)) {
        ಯದಿ (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        ಅನ್ಯಥಾ
            arm64_strx(sz, intr(r), intr(svrv), 0);
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        ಯದಿ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & mask);
        ಅನ್ಯಥಾ
            arm64_strx(sz, intr(r), 30, svcoff & mask);
        ಪ್ರತ್ಯಾಗಮ;
    }

    printf("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (long)svcoff);
    ಪ್ರತಿಜ್ಞಾ(0);
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_gen_bl_or_b(ಪೂರ್ಣಾಙ್ಕ b)
{
    ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    ಅನ್ಯಥಾ {
#ifdef CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#endif
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#ಯದಿ defined CONFIG_TCC_BCHECK || defined TCC_TARGET_PE
ಸ್ಥಿರ ಶೂನ್ಯ gen_static_call(ಪೂರ್ಣಾಙ್ಕ v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#endif

#ಯದಿ defined(CONFIG_TCC_BCHECK)
ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_prolog(ಶೂನ್ಯ)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->data_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(ARM64_NOP);  /* nop -> mov x0, lbound section pointer */
    o(ARM64_NOP);
    o(ARM64_NOP);
    o(ARM64_NOP);  /* nop -> call __bound_local_new */
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_epilog(ಶೂನ್ಯ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    ಪೂರ್ಣಾಙ್ಕ offset_modified = func_bound_offset != lbounds_section->data_offset;

    ಯದಿ (!offset_modified && !func_bound_add_epilog)
        ಪ್ರತ್ಯಾಗಮ;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, ಪರಿಮಾಣ(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    ಯದಿ (offset_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        arm64_sym(0, sym_data, 0);
        gen_static_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0xa9bf07e0); /* stp x0, x1, [sp, #-16]! */
    o(0x3c9f0fe0); /* str q0, [sp, #-16]! */
    arm64_sym(0, sym_data, 0);
    gen_static_call(TOK___bound_local_delete);
    o(0x3cc107e0); /* ldr q0, [sp], #16 */
    o(0xa8c107e0); /* ldp x0, x1, [sp], #16 */
}
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_hfa_aux(CType *type, ಪೂರ್ಣಾಙ್ಕ *fsize, ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ)
{
    ಯದಿ (is_float(type->t)) {
        ಪೂರ್ಣಾಙ್ಕ a, n = type_size(type, &a);
        ಯದಿ (ಅಂಕೆ >= 4 || (*fsize && *fsize != n))
            ಪ್ರತ್ಯಾಗಮ -1;
        *fsize = n;
        ಪ್ರತ್ಯಾಗಮ ಅಂಕೆ + 1;
    }
    ಅನ್ಯಥಾ ಯದಿ ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field;
        ಯದಿ (!IS_UNION(type->t)) {
            ಪೂರ್ಣಾಙ್ಕ num0 = ಅಂಕೆ;
            ಪ್ರತಿ (field = type->ref->next; field; field = field->next) {
                ಯದಿ (field->c != (ಅಂಕೆ - num0) * *fsize)
                    ಪ್ರತ್ಯಾಗಮ -1;
                ಅಂಕೆ = arm64_hfa_aux(&field->type, fsize, ಅಂಕೆ);
                ಯದಿ (ಅಂಕೆ == -1)
                    ಪ್ರತ್ಯಾಗಮ -1;
            }
            ಯದಿ (type->ref->c != (ಅಂಕೆ - num0) * *fsize)
                ಪ್ರತ್ಯಾಗಮ -1;
            ಪ್ರತ್ಯಾಗಮ ಅಂಕೆ;
        }
        ಅನ್ಯಥಾ { // union
            ಪೂರ್ಣಾಙ್ಕ num0 = ಅಂಕೆ;
            ಪ್ರತಿ (field = type->ref->next; field; field = field->next) {
                ಪೂರ್ಣಾಙ್ಕ num1 = arm64_hfa_aux(&field->type, fsize, num0);
                ಯದಿ (num1 == -1)
                    ಪ್ರತ್ಯಾಗಮ -1;
                ಅಂಕೆ = num1 < ಅಂಕೆ ? ಅಂಕೆ : num1;
            }
            ಯದಿ (type->ref->c != (ಅಂಕೆ - num0) * *fsize)
                ಪ್ರತ್ಯಾಗಮ -1;
            ಪ್ರತ್ಯಾಗಮ ಅಂಕೆ;
        }
    }
    ಅನ್ಯಥಾ ಯದಿ (type->t & VT_ARRAY) { /* handle float array within struct */
        ಪೂರ್ಣಾಙ್ಕ num1;
        ಯದಿ (!type->ref->c)
            ಪ್ರತ್ಯಾಗಮ ಅಂಕೆ;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, ಅಂಕೆ);
        ಯದಿ (num1 == -1 || (num1 != ಅಂಕೆ && type->ref->c > 4))
            ಪ್ರತ್ಯಾಗಮ -1;
        num1 = ಅಂಕೆ + type->ref->c * (num1 - ಅಂಕೆ);
        ಯದಿ (num1 > 4)
            ಪ್ರತ್ಯಾಗಮ -1;
        ಪ್ರತ್ಯಾಗಮ num1;
    }
    ಪ್ರತ್ಯಾಗಮ -1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_hfa(CType *type, unsigned *fsize)
{
    ಯದಿ ((type->t & VT_BTYPE) == VT_STRUCT) {
        ಪೂರ್ಣಾಙ್ಕ sz = 0;
        ಪೂರ್ಣಾಙ್ಕ n = arm64_hfa_aux(type, &sz, 0);
        ಯದಿ (0 < n && n <= 4) {
            ಯದಿ (fsize)
                *fsize = sz;
            ಪ್ರತ್ಯಾಗಮ n;
        }
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ unsigned long arm64_pcs_aux(ಪೂರ್ಣಾಙ್ಕ variadic, ಪೂರ್ಣಾಙ್ಕ n, CType **type, unsigned long *a)
{
    ಪೂರ್ಣಾಙ್ಕ nx = 0; // next integer register
    ಪೂರ್ಣಾಙ್ಕ nv = 0; // next vector register
    unsigned long ns = 32; // next stack offset
    ಪೂರ್ಣಾಙ್ಕ i;

    ಪ್ರತಿ (i = 0; i < n; i++) {
        ಪೂರ್ಣಾಙ್ಕ hfa = arm64_hfa(type[i], 0);
        ಪೂರ್ಣಾಙ್ಕ size, align, bt;

        bt = type[i]->t & VT_BTYPE;
        ಯದಿ (bt == VT_PTR || bt == VT_FUNC)
            size = align = 8;
        ಅನ್ಯಥಾ
            size = type_size(type[i], &align);

#ಯದಿ defined(TCC_TARGET_MACHO)
        ಯದಿ (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_PE)
        ಯದಿ (variadic && i >= variadic) {
            hfa = 0;
            ಯದಿ (is_float(bt))
                bt = VT_INT, size = align = 8;
        }
#endif
        ಯದಿ (hfa)
            // B.2
            ;
        ಅನ್ಯಥಾ ಯದಿ (size > 16) {
            // B.3: replace with pointer
            ಯದಿ (nx < 8)
                a[i] = nx++ << 1 | 1;
            ಅನ್ಯಥಾ {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            ಅನುವರ್ತ;
        }
        ಅನ್ಯಥಾ ಯದಿ (bt == VT_STRUCT)
            // B.4
            size = (size + 7) & ~7;

        // C.1
        ಯದಿ (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            ಅನುವರ್ತ;
        }

        // C.2
        ಯದಿ (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            ಅನುವರ್ತ;
        }

        // C.3
        ಯದಿ (hfa) {
            nv = 8;
            size = (size + 7) & ~7;
        }

        // C.4
        ಯದಿ (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        ಯದಿ (bt == VT_FLOAT)
            size = 8;

        // C.6
        ಯದಿ (hfa || is_float(bt)) {
            a[i] = ns;
            ns += size;
            ಅನುವರ್ತ;
        }

        // C.7
        ಯದಿ (bt != VT_STRUCT && size <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            ಅನುವರ್ತ;
        }

        // C.8
        ಯದಿ (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        ಯದಿ (bt != VT_STRUCT && size == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            ಅನುವರ್ತ;
        }

        // C.10
        ಯದಿ (bt == VT_STRUCT && size <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (size + 7) >> 3;
            ಅನುವರ್ತ;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        ಯದಿ (bt == VT_STRUCT) {
            a[i] = ns;
            ns += size;
            ಅನುವರ್ತ;
        }

        // C.14
        ಯದಿ (size < 8)
            size = 8;

        // C.15
        a[i] = ns;
        ns += size;
    }

    ಪ್ರತ್ಯಾಗಮ ns - 32;
}

ಸ್ಥಿರ unsigned long arm64_pcs(ಪೂರ್ಣಾಙ್ಕ variadic, ಪೂರ್ಣಾಙ್ಕ n, CType **type, unsigned long *a)
{
    unsigned long ರಾಶಿ;

    // Return type:
    ಯದಿ ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    ಅನ್ಯಥಾ {
        arm64_pcs_aux(0, 1, type, a);
        ಪ್ರತಿಜ್ಞಾ(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    ರಾಶಿ = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    ಯದಿ (0) {
        ಪೂರ್ಣಾಙ್ಕ i;
        ಪ್ರತಿ (i = 0; i < n; i++) {
            ಯದಿ (!i)
                printf("arm64_pcs return: ");
            ಅನ್ಯಥಾ
                printf("arm64_pcs arg %d: ", i);
            ಯದಿ (a[i] == (unsigned long)-1)
                printf("void\n");
            ಅನ್ಯಥಾ ಯದಿ (a[i] == 1 && !i)
                printf("X8 pointer\n");
            ಅನ್ಯಥಾ ಯದಿ (a[i] < 16)
                printf("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            ಅನ್ಯಥಾ ಯದಿ (a[i] < 32)
                printf("V%lu\n", a[i] / 2 - 8);
            ಅನ್ಯಥಾ
                printf("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    ಪ್ರತ್ಯಾಗಮ ರಾಶಿ;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ n_func_args(CType *type)
{
    ಪೂರ್ಣಾಙ್ಕ n_args = 0;
    Sym *arg;

    ಪ್ರತಿ (arg = type->ref->next; arg; arg = arg->next)
        n_args++;
    ಪ್ರತ್ಯಾಗಮ n_args;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_sub_sp(uint64_t diff)
{
    ಯದಿ (!diff)
        ಪ್ರತ್ಯಾಗಮ;
#ifdef TCC_TARGET_PE
    ಯದಿ (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        ಪ್ರತ್ಯಾಗಮ;
    }
#endif
    ಯದಿ (!(diff >> 24)) {
        ಯದಿ (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        ಯದಿ (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } ಅನ್ಯಥಾ {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ gv_addr(ಪೂರ್ಣಾಙ್ಕ r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    ಪ್ರತ್ಯಾಗಮ gv(r);
}

ST_FUNC ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಙ್ಕ nb_args)
{
    CType *return_type;
    CType **t;
    unsigned long *a, *a1;
    unsigned long ರಾಶಿ;
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪೂರ್ಣಾಙ್ಕ func_type = vtop[-nb_args].type.ref->f.func_type;
    ಪೂರ್ಣಾಙ್ಕ variadic = (func_type == FUNC_ELLIPSIS);
    ಪೂರ್ಣಾಙ್ಕ old_style = (func_type == FUNC_OLD);
    ಪೂರ್ಣಾಙ್ಕ var_nb_arg = variadic ? n_func_args(&vtop[-nb_args].type) : 0;

    save_regs(nb_args + 1);

#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    return_type = &vtop[-nb_args].type.ref->type;
    ಯದಿ ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_args;

    t = tcc_malloc((nb_args + 1) * ಪರಿಮಾಣ(*t));
    a = tcc_malloc((nb_args + 1) * ಪರಿಮಾಣ(*a));
    a1 = tcc_malloc((nb_args + 1) * ಪರಿಮಾಣ(*a1));

    t[0] = return_type;
    ಪ್ರತಿ (i = 0; i < nb_args; i++)
        t[nb_args - i] = &vtop[-i].type;

    ರಾಶಿ = arm64_pcs(
#ifdef TCC_TARGET_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#endif
        var_nb_arg, nb_args + 1, t, a);

    // Allocate space for structs replaced by pointer:
    ಪ್ರತಿ (i = nb_args; i; i--)
        ಯದಿ (a[i] & 1) {
            SValue *arg = &vtop[i - nb_args];
            ಪೂರ್ಣಾಙ್ಕ align, size = type_size(&arg->type, &align);
            ಪ್ರತಿಜ್ಞಾ((arg->type.t & VT_BTYPE) == VT_STRUCT);
            ರಾಶಿ = (ರಾಶಿ + align - 1) & -align;
            a1[i] = ರಾಶಿ;
            ರಾಶಿ += size;
        }

    ರಾಶಿ = (ರಾಶಿ + 15) >> 4 << 4;

    ಯದಿ (ರಾಶಿ >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", ರಾಶಿ);
    arm64_sub_sp(ರಾಶಿ);

    // First pass: set all values on stack
    ಪ್ರತಿ (i = nb_args; i; i--) {
        vpushv(vtop - nb_args + i);

        ಯದಿ (a[i] & 1) {
            // struct replaced by pointer
            ಪೂರ್ಣಾಙ್ಕ r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            ಯದಿ (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        ಅನ್ಯಥಾ ಯದಿ (a[i] >= 32) {
            // value on stack
            ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                ಪೂರ್ಣಾಙ್ಕ r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            ಅನ್ಯಥಾ ಯದಿ (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_size(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            ಅನ್ಯಥಾ {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    ಪ್ರತಿ (i = nb_args; i; i--, vtop--) {
        ಯದಿ (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            ಯದಿ ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                ಅನ್ಯಥಾ
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            ಅನ್ಯಥಾ ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                ಪೂರ್ಣಾಙ್ಕ align, size = type_size(&vtop->type, &align);
                ಯದಿ (size) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, size);
                }
            }
            ಅನ್ಯಥಾ
                gv(RC_R(a[i] / 2));
        }
        ಅನ್ಯಥಾ ಯದಿ (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        ಅನ್ಯಥಾ ಯದಿ (a[i] < 32) {
            // value in floating-point registers
            ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                ಯದಿ (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    ಪ್ರತಿ (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } ಅನ್ಯಥಾ {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            ಅನ್ಯಥಾ
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    ಯದಿ ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        ಯದಿ (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        ಅನ್ಯಥಾ
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    ಯದಿ (ರಾಶಿ & 0xfff)
        o(0x910003ff | (ರಾಶಿ & 0xfff) << 10); // add sp,sp,#(n)
    ಯದಿ (ರಾಶಿ >> 12)
        o(0x914003ff | (ರಾಶಿ >> 12) << 10);

    {
        ಪೂರ್ಣಾಙ್ಕ rt = return_type->t;
        ಪೂರ್ಣಾಙ್ಕ bt = rt & VT_BTYPE;
        ಯದಿ (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            ಯದಿ (a[0] == 0) {
                ಪೂರ್ಣಾಙ್ಕ align, size = type_size(return_type, &align);
                ಪ್ರತಿಜ್ಞಾ(size <= 16);
                ಯದಿ (size > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                ಅನ್ಯಥಾ ಯದಿ (size)
                    arm64_strx(size > 4 ? 3 : size > 2 ? 2 : size > 1, 0, 8, 0);

            }
            ಅನ್ಯಥಾ ಯದಿ (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                ಪ್ರತಿ (j = 0; j < n; j++)
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

ಸ್ಥಿರ unsigned long arm64_func_va_list_ರಾಶಿ;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_func_va_list_gr_offs;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_func_va_list_vr_offs;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_func_sub_sp_offset;

ಸ್ಥಿರ unsigned arm64_func_start_offset;
#define ARM64_FUNC_ರಾಶಿ_SETUP_SLOTS 6

#ifdef TCC_TARGET_PE
ಸ್ಥಿರ unsigned long arm64_pe_param_off(unsigned long a)
{
    ಪ್ರತ್ಯಾಗಮ a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#endif

ST_FUNC ಶೂನ್ಯ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ಪೂರ್ಣಾಙ್ಕ n = 0;
    ಪೂರ್ಣಾಙ್ಕ i = 0;
    Sym *sym;
    CType **t;
    unsigned long *a;
    ಪೂರ್ಣಾಙ್ಕ use_x8 = 0;
    ಪೂರ್ಣಾಙ್ಕ last_int = 0;
    ಪೂರ್ಣಾಙ್ಕ last_float = 0;
    ಪೂರ್ಣಾಙ್ಕ variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    ಪೂರ್ಣಾಙ್ಕ var_nb_arg = variadic ? n_func_args(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    ಪ್ರತಿ (sym = func_type->ref; sym; sym = sym->next)
        ++n;

#ifdef TCC_TARGET_PE
    n += variadic;
#endif

    t = tcc_malloc(n * ಪರಿಮಾಣ(*t));
    a = tcc_malloc(n * ಪರಿಮಾಣ(*a));
    ಪ್ರತಿ (sym = func_type->ref; sym; sym = sym->next)
        t[i++] = &sym->type;

#ifdef TCC_TARGET_PE
    ಯದಿ (variadic)
        t[i] = &int_type;
#endif

    arm64_func_va_list_ರಾಶಿ = arm64_pcs(var_nb_arg, n, t, a);

#ifdef TCC_TARGET_PE
    ಯದಿ (variadic)
        arm64_func_va_list_ರಾಶಿ = arm64_pe_param_off(a[n - 1]);
#endif

#ಯದಿ !defined(TCC_TARGET_MACHO)
    ಯದಿ (variadic) {
        use_x8 = 1;
        last_int = 4;
        last_float = 4;
    }
#endif

    ಯದಿ (a && a[0] == 1)
        use_x8 = 1;
    ಪ್ರತಿ (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        ಯದಿ (a[i] < 16) {
            ಪೂರ್ಣಾಙ್ಕ last, align, size = type_size(&sym->type, &align);
	    last = a[i] / 4 + 1 + (size - 1) / 8;
	    last_int = last > last_int ? last : last_int;
	}
        ಅನ್ಯಥಾ ಯದಿ (a[i] < 32) {
            ಪೂರ್ಣಾಙ್ಕ last, hfa = arm64_hfa(&sym->type, 0);
	    last = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    last_float = last > last_float ? last : last_float;
	}
    }

    last_int = last_int > 4 ? 4 : last_int;
    last_float = last_float > 4 ? 4 : last_float;

    arm64_func_start_offset = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    ಪ್ರತಿ (i = 0; i < last_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    ಯದಿ (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    ಪ್ರತಿ (i = 0; i < last_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    ಪ್ರತಿ (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        ಪೂರ್ಣಾಙ್ಕ off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_set_param(sym, off, a[i] & 1);

        ಯದಿ (a[i] < 16) {
            ಪೂರ್ಣಾಙ್ಕ align, size = type_size(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && size > 8)) * 8;
        }
        ಅನ್ಯಥಾ ಯದಿ (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        ಯದಿ (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            ಯದಿ (k > 0 && sz < 16)
                ಪ್ರತಿ (j = 0; j < k; j++) {
                    o(0x3d0003e0 | -(sz & 8) << 27 | (sz & 4) << 29 |
                      ((a[i] - 16) / 2 + j) | (off / sz + j) << 10);
                    // str ([sdq])(j),[sp,#(j * sz)]
                }
        }
    }

    tcc_free(a);
    tcc_free(t);

    arm64_func_sub_sp_offset = ind;
    /* In gfunc_epilog these will be replaced with stack setup code. */
    ಪ್ರತಿ (i = 0; i < ARM64_FUNC_ರಾಶಿ_SETUP_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

ST_FUNC ಶೂನ್ಯ gen_va_start(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#ifdef TCC_TARGET_PE
    ಯದಿ (arm64_func_va_list_ರಾಶಿ) {
        arm64_movimm(30, arm64_func_va_list_ರಾಶಿ);
        o(0x8b1e03be); // add x30,x29,x30
    } ಅನ್ಯಥಾ
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#ಅನ್ಯಥಾ
    ಯದಿ (arm64_func_va_list_ರಾಶಿ) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_ರಾಶಿ + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    ಅನ್ಯಥಾ
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#ಯದಿ !defined(TCC_TARGET_MACHO)
    ಯದಿ (arm64_func_va_list_gr_offs) {
        ಯದಿ (arm64_func_va_list_ರಾಶಿ)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    ಯದಿ (arm64_func_va_list_vr_offs) {
        o(0x910243be); // add x30,x29,#144
        o(0xf900081e | r << 5); // str x30,[x(r),#16]
    }

    arm64_movimm(30, arm64_func_va_list_gr_offs);
    o(0xb900181e | r << 5); // str w30,[x(r),#24]

    arm64_movimm(30, arm64_func_va_list_vr_offs);
    o(0xb9001c1e | r << 5); // str w30,[x(r),#28]
#endif
#endif

    --vtop;
}

ST_FUNC ಶೂನ್ಯ gen_va_arg(CType *t)
{
    ಪೂರ್ಣಾಙ್ಕ align, size = type_size(t, &align);
    uint32_t r0, r1;

#ifdef TCC_TARGET_PE
    ಪೂರ್ಣಾಙ್ಕ indirect = 0, slot = (size + 7) & -8;

    ಯದಿ (size > 16)
        indirect = 1, slot = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    ಯದಿ (slot) {
        ಯದಿ (slot == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        ಯದಿ (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | slot << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    ಯದಿ (indirect)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#ಅನ್ಯಥಾ /* !PE */
    unsigned fsize = size, hfa = 1;

    ಯದಿ (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    ಯದಿ (!hfa) {
        uint32_t n = size > 16 ? 8 : (size + 7) & -8;

#ಯದಿ !defined(TCC_TARGET_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        ಯದಿ (align == 16) {
            ಪ್ರತಿಜ್ಞಾ(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#endif

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ಯದಿ (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#ಯದಿ !defined(TCC_TARGET_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#endif

        ಯದಿ (size > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    ಅನ್ಯಥಾ {
        uint32_t ssz = (size + 7) & -(uint32_t)8;
#ಯದಿ !defined(TCC_TARGET_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#endif
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ಯದಿ (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#ಯದಿ !defined(TCC_TARGET_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_text_section->data + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        ಯದಿ (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        ಅನ್ಯಥಾ {
            // We need to change the layout of this HFA.
            // Get some space on the stack using global variable "loc":
            loc = (loc - size) & -(uint32_t)align;
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
        write32le(cur_text_section->data + b2, ARM64_B | ((ind - b2) >> 2));
#endif
    }
#endif /* not pe */
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಙ್ಕ variadic, CType *ret,
                       ಪೂರ್ಣಾಙ್ಕ *align, ಪೂರ್ಣಾಙ್ಕ *regsize)
{
    ಪ್ರತ್ಯಾಗಮ 0;
}

ST_FUNC ಶೂನ್ಯ gfunc_return(CType *func_type)
{
    CType *t = func_type;
    unsigned long a;

    arm64_pcs(0, 1, &t, &a);

    ವಿಕಲ್ಪ (a) {
    ಪಕ್ಷ -1:
        ಭಙ್ಗ;
    ಪಕ್ಷ 0:
        ಯದಿ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            ಪೂರ್ಣಾಙ್ಕ align, size = type_size(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, size);
        }
        ಅನ್ಯಥಾ
            gv(RC_IRET);
        ಭಙ್ಗ;
    ಪಕ್ಷ 1: {
        CType type = *func_type;
        mk_pointer(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        ಭಙ್ಗ;
    }
    ಪಕ್ಷ 16:
        ಯದಿ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          ಪ್ರತಿ (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        ಅನ್ಯಥಾ
            gv(RC_FRET);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
      ಪ್ರತಿಜ್ಞಾ(0);
    }
    vtop--;
}

ST_FUNC ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    ಯದಿ (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        ಪೂರ್ಣಾಙ್ಕ i;
        addr_t saved_ind = ind;
        addr_t patch_end = arm64_func_sub_sp_offset + ARM64_FUNC_ರಾಶಿ_SETUP_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_offset;
        arm64_sub_sp(diff);
        ಪ್ರತಿ (i = ind; i < patch_end; i += 4)
            write32le(cur_text_section->data + i, ARM64_NOP); // nop
        ind = saved_ind;
    }
    o(0x910003bf); // mov sp,x29
    o(0xa8ce7bfd); // ldp x29,x30,[sp],#224

    o(0xd65f03c0); // ret

#ifdef TCC_TARGET_PE
    pe_add_unwind_data(arm64_func_start_offset, ind, -loc);
#endif
}

ST_FUNC ಶೂನ್ಯ gen_fill_nops(ಪೂರ್ಣಾಙ್ಕ bytes)
{
    ಯದಿ ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    ಯಾವತ್ (bytes > 0) {
	o(ARM64_NOP); // nop
	bytes -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gjmp(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ r = ind;
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ t;
    o(t);
    ಪ್ರತ್ಯಾಗಮ r;
}

// Generate branch to known address:
ST_FUNC ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಙ್ಕ a)
{
    ಪ್ರತಿಜ್ಞಾ(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ gjmp_append(ಪೂರ್ಣಾಙ್ಕ n, ಪೂರ್ಣಾಙ್ಕ t)
{
    ಶೂನ್ಯ *p;
    /* insert vtop->c jump list in t */
    ಯದಿ (n) {
        uint32_t n1 = n, n2;
        ಯಾವತ್ ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    ಪ್ರತ್ಯಾಗಮ t;
}

ಶೂನ್ಯ arm64_vset_VT_CMP(ಪೂರ್ಣಾಙ್ಕ op)
{
    ಯದಿ (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_gen_opil(ಪೂರ್ಣಾಙ್ಕ op, uint32_t l);

ಸ್ಥಿರ ಶೂನ್ಯ arm64_load_cmp(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv)
{
    sv->r = sv->cmp_r;
    ಯದಿ (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    ಯದಿ (r != sv->r) {
        load(r, sv);
        sv->r = r;
    }
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ gjmp_cond(ಪೂರ್ಣಾಙ್ಕ op, ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ bt = vtop->type.t & VT_BTYPE;

    ಪೂರ್ಣಾಙ್ಕ inv = op & 1;
    vtop->r = vtop->cmp_r;

    ಯದಿ (bt == VT_LDOUBLE) {
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
    ಅನ್ಯಥಾ ಯದಿ (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    ಅನ್ಯಥಾ {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    ಪ್ರತ್ಯಾಗಮ gjmp(t);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_iconst(uint64_t *val, SValue *sv)
{
    ಯದಿ ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (val) {
        ಪೂರ್ಣಾಙ್ಕ t = sv->type.t;
	ಪೂರ್ಣಾಙ್ಕ bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    ಪ್ರತ್ಯಾಗಮ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arm64_gen_opic(ಪೂರ್ಣಾಙ್ಕ op, uint32_t l, ಪೂರ್ಣಾಙ್ಕ rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    ಯದಿ (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    ವಿಕಲ್ಪ (op) {

    ಪಕ್ಷ '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        ಯದಿ (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        ಅನ್ಯಥಾ ಯದಿ (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        ಅನ್ಯಥಾ {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        ಪ್ರತ್ಯಾಗಮ 1;
      }

    ಪಕ್ಷ '-':
        ಯದಿ (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        ಅನ್ಯಥಾ ಯದಿ (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        ಅನ್ಯಥಾ {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        ಪ್ರತ್ಯಾಗಮ 1;

    ಪಕ್ಷ '^':
        ಯದಿ (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            ಪ್ರತ್ಯಾಗಮ 1;
        }
        // fall through
    ಪಕ್ಷ '&':
    ಪಕ್ಷ '|': {
        ಪೂರ್ಣಾಙ್ಕ e = arm64_encode_bimm64(l ? val : val | val << 32);
        ಯದಿ (e < 0)
            ಪ್ರತ್ಯಾಗಮ 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        ಪ್ರತ್ಯಾಗಮ 1;
    }

    ಪಕ್ಷ TOK_SAR:
    ಪಕ್ಷ TOK_SHL:
    ಪಕ್ಷ TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        ಯದಿ (rev)
            ಪ್ರತ್ಯಾಗಮ 0;
        ಯದಿ (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            ಪ್ರತ್ಯಾಗಮ 1;
        }
        ಅನ್ಯಥಾ ಯದಿ (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        ಅನ್ಯಥಾ
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        ಪ್ರತ್ಯಾಗಮ 1;
    }

    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ arm64_gen_opil(ಪೂರ್ಣಾಙ್ಕ op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        ಪೂರ್ಣಾಙ್ಕ rev = 1;

        ಯದಿ (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        ಯದಿ (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            ಯದಿ (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                ಪ್ರತ್ಯಾಗಮ;
            }
        }
        ಯದಿ (!rev)
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

    ವಿಕಲ್ಪ (op) {
    ಪಕ್ಷ '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ಭಙ್ಗ;
    ಪಕ್ಷ '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        ಭಙ್ಗ;
    ಪಕ್ಷ '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        ಭಙ್ಗ;
    ಪಕ್ಷ '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        ಭಙ್ಗ;
    ಪಕ್ಷ '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        ಭಙ್ಗ;
    ಪಕ್ಷ '/':
    ಪಕ್ಷ TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        ಭಙ್ಗ;
    ಪಕ್ಷ '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        ಭಙ್ಗ;
    ಪಕ್ಷ '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        ಪ್ರತಿಜ್ಞಾ(0);
    }
}

ST_FUNC ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಙ್ಕ op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಙ್ಕ op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಙ್ಕ op)
{
    uint32_t x, a, b, dbl;
    ಪೂರ್ಣಾಙ್ಕ bt = vtop[0].type.t & VT_BTYPE;

    ಯದಿ (op == TOK_NEG) {
        ಯದಿ (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } ಅನ್ಯಥಾ {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        ಪ್ರತ್ಯಾಗಮ;
    }

    ಯದಿ (bt == VT_LDOUBLE) {
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
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        ಯದಿ (cond < 0)
            vtop->type = type;
        ಅನ್ಯಥಾ {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        ಪ್ರತ್ಯಾಗಮ;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    ಪ್ರತಿಜ್ಞಾ(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    ವಿಕಲ್ಪ (op) {
    ಪಕ್ಷ TOK_EQ: ಪಕ್ಷ TOK_NE:
    ಪಕ್ಷ TOK_LT: ಪಕ್ಷ TOK_GE: ಪಕ್ಷ TOK_LE: ಪಕ್ಷ TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        ಭಙ್ಗ;
    }

    ವಿಕಲ್ಪ (op) {
    ಪಕ್ಷ '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        ಭಙ್ಗ;
    ಪಕ್ಷ '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        ಭಙ್ಗ;
    ಪಕ್ಷ '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        ಭಙ್ಗ;
    ಪಕ್ಷ '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
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
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಯದಿ (t == VT_LDOUBLE) {
        ಪೂರ್ಣಾಙ್ಕ f = vtop->type.t;
        ಪೂರ್ಣಾಙ್ಕ func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        ಪ್ರತ್ಯಾಗಮ;
    }
    ಅನ್ಯಥಾ {
        ಪೂರ್ಣಾಙ್ಕ d, n = intr(gv(RC_INT));
        ಪೂರ್ಣಾಙ್ಕ s = !(vtop->type.t & VT_UNSIGNED);
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

ST_FUNC ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        ಪೂರ್ಣಾಙ್ಕ func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        ಪ್ರತ್ಯಾಗಮ;
    }
    ಅನ್ಯಥಾ {
        ಪೂರ್ಣಾಙ್ಕ d, n = fltr(gv(RC_FLOAT));
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

ST_FUNC ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ f = vtop[0].type.t & VT_BTYPE;
    ಪ್ರತಿಜ್ಞಾ(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    ಪ್ರತಿಜ್ಞಾ(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    ಯದಿ (t == f)
        ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        ಪೂರ್ಣಾಙ್ಕ func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    ಅನ್ಯಥಾ {
        ಪೂರ್ಣಾಙ್ಕ x, a;
        gv(RC_FLOAT);
        ಪ್ರತಿಜ್ಞಾ(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        ಯದಿ (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        ಅನ್ಯಥಾ
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ r1, r2;

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
    uint32_t beg, end, dsz, isz, p, lab1, b1;
    gv2(RC_INT, RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    beg = intr(vtop[-4].r); // x0
    end = intr(vtop[-3].r); // x1
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
    write32le(cur_text_section->data + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | end << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0x51000400 | p | isz << 5); // sub w(p),w(isz),#1
    o(0x8a240004 | p | beg << 5 | p << 16); // bic x(p),x(beg),x(p)
    b1 = ind; o(ARM64_B); // b
    lab1 = ind;
    o(0xd50b7520 | p); // ic ivau,x(p)
    o(0x8b000000 | p | p << 5 | isz << 16); // add x(p),x(p),x(isz)
    write32le(cur_text_section->data + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | end << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0xd5033fdf); // isb
}

ST_FUNC ಶೂನ್ಯ gen_vla_sp_save(ಪೂರ್ಣಾಙ್ಕ addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC ಶೂನ್ಯ gen_vla_sp_restore(ಪೂರ್ಣಾಙ್ಕ addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC ಶೂನ್ಯ gen_vla_alloc(CType *type, ಪೂರ್ಣಾಙ್ಕ align) {
    uint32_t r;
#ಯದಿ defined(CONFIG_TCC_BCHECK)
    ಯದಿ (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    r = intr(gv(RC_INT));
#ಯದಿ defined(CONFIG_TCC_BCHECK)
    ಯದಿ (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    ಅನ್ಯಥಾ
#endif
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#ಯದಿ defined(CONFIG_TCC_BCHECK)
    ಯದಿ (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x910003e0 | vtop->r); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_add_epilog = 1;
    }
#endif
}

/* end of A64 code generator */
/*************************************************************/
#endif
/*************************************************************/
