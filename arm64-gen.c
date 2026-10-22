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

#যদি !defined(TCC_TARGET_MACHO) && !defined(TCC_TARGET_PE)
#define CHAR_IS_UNSIGNED
#endif

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#define PROMOTE_RET
/******************************************************/
#অন্যথা /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#অন্তর্ভাব "tcc.h"
#অন্তর্ভাব <assert.h>

ST_DATA ধ্রুব বর্ণ * ধ্রুব target_machine_defs =
    "__aarch64__\0"
#যদি defined(TCC_TARGET_MACHO)
    "__arm64__\0"
#endif
    "__AARCH64EL__\0"
    ;

ST_DATA ধ্রুব পূর্ণাঙ্ক reg_classes[NB_REGS] = {
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

#যদি defined(CONFIG_TCC_BCHECK)
স্থির addr_t func_bound_offset;
স্থির unsigned long func_bound_ind;
ST_DATA পূর্ণাঙ্ক func_bound_add_epilog;
#endif

#define IS_FREG(x) ((x) >= TREG_F(0))

স্থির uint32_t intr(পূর্ণাঙ্ক r)
{
    প্রতিজ্ঞা(TREG_R(0) <= r && r <= TREG_R30);
    প্রত্যাগম r < TREG_R30 ? r : 30;
}

স্থির uint32_t fltr(পূর্ণাঙ্ক r)
{
    প্রতিজ্ঞা(TREG_F(0) <= r && r <= TREG_F(7));
    প্রত্যাগম r - TREG_F(0);
}

// Add an instruction to text section:
ST_FUNC শূন্য o(unsigned পূর্ণাঙ্ক c)
{
    পূর্ণাঙ্ক ind1 = ind + 4;
    যদি (nocode_wanted)
        প্রত্যাগম;
    যদি (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    write32le(cur_text_section->data + ind, c);
    ind = ind1;
}

স্থির পূর্ণাঙ্ক arm64_encode_bimm64(uint64_t x)
{
    পূর্ণাঙ্ক neg = x & 1;
    পূর্ণাঙ্ক rep, pos, len;

    যদি (neg)
        x = ~x;
    যদি (!x)
        প্রত্যাগম -1;

    যদি (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    অন্যথা যদি (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    অন্যথা যদি (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    অন্যথা যদি (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    অন্যথা যদি (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    অন্যথা
        rep = 64;

    pos = 0;
    যদি (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    যদি (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    যদি (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    যদি (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    যদি (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    যদি (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    যদি (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    যদি (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    যদি (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    যদি (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    যদি (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    যদি (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    যদি (x)
        প্রত্যাগম -1;
    যদি (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    প্রত্যাগম ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

স্থির uint32_t arm64_movi(পূর্ণাঙ্ক r, uint64_t x)
{
    uint64_t m = 0xffff;
    পূর্ণাঙ্ক e;
    যদি (!(x & ~m))
        প্রত্যাগম ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    যদি (!(x & ~(m << 16)))
        প্রত্যাগম (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    যদি (!(x & ~(m << 32)))
        প্রত্যাগম (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    যদি (!(x & ~(m << 48)))
        প্রত্যাগম (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    যদি ((x & ~m) == m << 16)
        প্রত্যাগম (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    যদি ((x & ~(m << 16)) == m)
        প্রত্যাগম (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    যদি (!~(x | m))
        প্রত্যাগম (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    যদি (!~(x | m << 16))
        প্রত্যাগম (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    যদি (!~(x | m << 32))
        প্রত্যাগম (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    যদি (!~(x | m << 48))
        প্রত্যাগম (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    যদি (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        প্রত্যাগম (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    যদি ((e = arm64_encode_bimm64(x)) >= 0)
        প্রত্যাগম (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    প্রত্যাগম 0;
}

স্থির শূন্য arm64_movimm(পূর্ণাঙ্ক r, uint64_t x)
{
    uint32_t i;
    যদি ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    অন্যথা {
        // MOVZ/MOVN and 1-3 MOVKs
        পূর্ণাঙ্ক z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        প্রতি (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        যদি (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        প্রতি (i = 0; i < 64; i += 16)
            যদি (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                ভঙ্গ;
            }
        প্রতি (i += 16; i < 64; i += 16)
            যদি (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC শূন্য gsym_addr(পূর্ণাঙ্ক t_, পূর্ণাঙ্ক a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    যাবত্ (t) {
        unsigned বর্ণ *ptr = cur_text_section->data + t;
        uint32_t next = read32le(ptr);
        যদি (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = next;
    }
}

স্থির পূর্ণাঙ্ক arm64_type_size(পূর্ণাঙ্ক t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    বিকল্প (t & VT_BTYPE) {
    পক্ষ VT_BYTE: প্রত্যাগম 0;
    পক্ষ VT_SHORT: প্রত্যাগম 1;
    পক্ষ VT_INT: প্রত্যাগম 2;
    পক্ষ VT_LLONG: প্রত্যাগম 3;
    পক্ষ VT_PTR: প্রত্যাগম 3;
    পক্ষ VT_FUNC: প্রত্যাগম 3;
    পক্ষ VT_STRUCT: প্রত্যাগম 3;
    পক্ষ VT_FLOAT: প্রত্যাগম 2;
    পক্ষ VT_DOUBLE: প্রত্যাগম 3;
    পক্ষ VT_LDOUBLE: প্রত্যাগম 4;
    পক্ষ VT_BOOL: প্রত্যাগম 0;
    }
    প্রতিজ্ঞা(0);
    প্রত্যাগম 0;
}

স্থির শূন্য arm64_spoff(পূর্ণাঙ্ক reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    যদি (sub)
        off = -off;
    যদি (off < 4096)
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    অন্যথা {
        arm64_movimm(30, off);
        o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

স্থির uint64_t arm64_check_offset(পূর্ণাঙ্ক sz_, uint64_t off)
{
#ifndef TCC_TARGET_PE
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    যদি (!(off & ~scaled_mask) || (off < 256 || -off <= 256))
        প্রত্যাগম ~0ull;
    যদি (off & scaled_mask)
        প্রত্যাগম scaled_mask;
    যদি (off & 0x1fful)
        প্রত্যাগম 0x1fful;
#endif
    প্রত্যাগম 0;
}

স্থির শূন্য arm64_ldrx(পূর্ণাঙ্ক sg, পূর্ণাঙ্ক sz_, পূর্ণাঙ্ক dst, পূর্ণাঙ্ক bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    যদি (sz >= 2)
        sg = 0;
    যদি (!(off & ~scaled_mask))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    অন্যথা যদি (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    অন্যথা {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

স্থির শূন্য arm64_ldrv(পূর্ণাঙ্ক sz_, পূর্ণাঙ্ক dst, পূর্ণাঙ্ক bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    যদি (!(off & ~scaled_mask))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    অন্যথা যদি (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    অন্যথা {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

স্থির শূন্য arm64_ldrs(পূর্ণাঙ্ক reg_, পূর্ণাঙ্ক size)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    বিকল্প (size) {
    স্বভাব: প্রতিজ্ঞা(0); ভঙ্গ;
    পক্ষ 0:
        /* Can happen with zero size structs */
        ভঙ্গ;
    পক্ষ 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        ভঙ্গ;
    পক্ষ 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ভঙ্গ;
    পক্ষ 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ভঙ্গ;
    পক্ষ 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ভঙ্গ;
    পক্ষ 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ভঙ্গ;
    পক্ষ 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        ভঙ্গ;
    }
}

স্থির শূন্য arm64_strx(পূর্ণাঙ্ক sz_, পূর্ণাঙ্ক dst, পূর্ণাঙ্ক bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    যদি (!(off & ~scaled_mask))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    অন্যথা যদি (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    অন্যথা {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

স্থির শূন্য arm64_strv(পূর্ণাঙ্ক sz_, পূর্ণাঙ্ক dst, পূর্ণাঙ্ক bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    যদি (!(off & ~scaled_mask))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    অন্যথা যদি (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    অন্যথা {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

স্থির শূন্য arm64_reloca(Sym *sym, পূর্ণাঙ্ক reloc_type, uint64_t addend)
{
    greloca(cur_text_section, sym, ind, reloc_type, addend);
}

স্থির শূন্য arm64_sym(পূর্ণাঙ্ক r, Sym *sym, addr_t addend)
{
    যদি (sym->type.t & VT_TLS) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        পূর্ণাঙ্ক r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#অন্যথা
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#endif
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_HI12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_LO12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#ifndef TCC_TARGET_PE /* no elf-style GOT on Windows */
    } অন্যথা যদি (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_PAGE, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        যদি (addend > 0xffffff) {
            পূর্ণাঙ্ক t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } অন্যথা {
           যদি (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_ADD_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            যদি (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#endif
    } অন্যথা {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_ADD_ABS_LO12_NC, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

স্থির শূন্য arm64_load_cmp(পূর্ণাঙ্ক r, SValue *sv);

ST_FUNC শূন্য load(পূর্ণাঙ্ক r, SValue *sv)
{
    পূর্ণাঙ্ক svtt = sv->type.t;
    পূর্ণাঙ্ক svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    পূর্ণাঙ্ক svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    পূর্ণাঙ্ক sb = !(svtt & VT_UNSIGNED);
    পূর্ণাঙ্ক sz = arm64_type_size(svtt);

    যদি (svr == (VT_LOCAL | VT_LVAL)) {
        যদি (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        অন্যথা
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        প্রত্যাগম;
    }

    যদি (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        যদি (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        অন্যথা
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        প্রত্যাগম;
    }

    যদি (svrv < VT_CONST && (svr & VT_LVAL)) {
        যদি (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        অন্যথা
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        প্রত্যাগম;
    }

    যদি (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        যদি (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & mask);
        অন্যথা
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & mask);
        প্রত্যাগম;
    }

    যদি (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        প্রত্যাগম;
    }

    যদি (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        প্রত্যাগম;
    }

    যদি (svr < VT_CONST) {
        যদি (IS_FREG(r) && IS_FREG(svr))
            যদি (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            অন্যথা
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        অন্যথা যদি (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        অন্যথা
            প্রতিজ্ঞা(0);
      প্রত্যাগম;
    }

    যদি (svr == VT_LOCAL) {
        যদি (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        অন্যথা {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        প্রত্যাগম;
    }

    যদি (svr == VT_JMP || svr == VT_JMPI) {
        পূর্ণাঙ্ক t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        প্রত্যাগম;
    }

    যদি (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        যদি (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        অন্যথা
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        প্রত্যাগম;
    }

    যদি (svr == VT_CMP) {
        arm64_load_cmp(r, sv);
        প্রত্যাগম;
    }

    printf("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (long)svcul);
    প্রতিজ্ঞা(0);
}

ST_FUNC শূন্য store(পূর্ণাঙ্ক r, SValue *sv)
{
    পূর্ণাঙ্ক svtt = sv->type.t;
    পূর্ণাঙ্ক svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    পূর্ণাঙ্ক svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    পূর্ণাঙ্ক sz = arm64_type_size(svtt);

    যদি (svr == (VT_LOCAL | VT_LVAL)) {
        যদি (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        অন্যথা
            arm64_strx(sz, intr(r), 29, svcoff);
        প্রত্যাগম;
    }

    যদি (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        যদি (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        অন্যথা
            arm64_strx(sz, intr(r), 30, 0);
        প্রত্যাগম;
    }

    যদি (svrv < VT_CONST && (svr & VT_LVAL)) {
        যদি (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        অন্যথা
            arm64_strx(sz, intr(r), intr(svrv), 0);
        প্রত্যাগম;
    }

    যদি (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        যদি (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & mask);
        অন্যথা
            arm64_strx(sz, intr(r), 30, svcoff & mask);
        প্রত্যাগম;
    }

    printf("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (long)svcoff);
    প্রতিজ্ঞা(0);
}

স্থির শূন্য arm64_gen_bl_or_b(পূর্ণাঙ্ক b)
{
    যদি ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    অন্যথা {
#ifdef CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#endif
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#যদি defined CONFIG_TCC_BCHECK || defined TCC_TARGET_PE
স্থির শূন্য gen_static_call(পূর্ণাঙ্ক v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#endif

#যদি defined(CONFIG_TCC_BCHECK)
স্থির শূন্য gen_bounds_prolog(শূন্য)
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

স্থির শূন্য gen_bounds_epilog(শূন্য)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    পূর্ণাঙ্ক offset_modified = func_bound_offset != lbounds_section->data_offset;

    যদি (!offset_modified && !func_bound_add_epilog)
        প্রত্যাগম;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, পরিমাণ(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    যদি (offset_modified) {
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

স্থির পূর্ণাঙ্ক arm64_hfa_aux(CType *type, পূর্ণাঙ্ক *fsize, পূর্ণাঙ্ক অঙ্ক)
{
    যদি (is_float(type->t)) {
        পূর্ণাঙ্ক a, n = type_size(type, &a);
        যদি (অঙ্ক >= 4 || (*fsize && *fsize != n))
            প্রত্যাগম -1;
        *fsize = n;
        প্রত্যাগম অঙ্ক + 1;
    }
    অন্যথা যদি ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field;
        যদি (!IS_UNION(type->t)) {
            পূর্ণাঙ্ক num0 = অঙ্ক;
            প্রতি (field = type->ref->next; field; field = field->next) {
                যদি (field->c != (অঙ্ক - num0) * *fsize)
                    প্রত্যাগম -1;
                অঙ্ক = arm64_hfa_aux(&field->type, fsize, অঙ্ক);
                যদি (অঙ্ক == -1)
                    প্রত্যাগম -1;
            }
            যদি (type->ref->c != (অঙ্ক - num0) * *fsize)
                প্রত্যাগম -1;
            প্রত্যাগম অঙ্ক;
        }
        অন্যথা { // union
            পূর্ণাঙ্ক num0 = অঙ্ক;
            প্রতি (field = type->ref->next; field; field = field->next) {
                পূর্ণাঙ্ক num1 = arm64_hfa_aux(&field->type, fsize, num0);
                যদি (num1 == -1)
                    প্রত্যাগম -1;
                অঙ্ক = num1 < অঙ্ক ? অঙ্ক : num1;
            }
            যদি (type->ref->c != (অঙ্ক - num0) * *fsize)
                প্রত্যাগম -1;
            প্রত্যাগম অঙ্ক;
        }
    }
    অন্যথা যদি (type->t & VT_ARRAY) { /* handle float array within struct */
        পূর্ণাঙ্ক num1;
        যদি (!type->ref->c)
            প্রত্যাগম অঙ্ক;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, অঙ্ক);
        যদি (num1 == -1 || (num1 != অঙ্ক && type->ref->c > 4))
            প্রত্যাগম -1;
        num1 = অঙ্ক + type->ref->c * (num1 - অঙ্ক);
        যদি (num1 > 4)
            প্রত্যাগম -1;
        প্রত্যাগম num1;
    }
    প্রত্যাগম -1;
}

স্থির পূর্ণাঙ্ক arm64_hfa(CType *type, unsigned *fsize)
{
    যদি ((type->t & VT_BTYPE) == VT_STRUCT) {
        পূর্ণাঙ্ক sz = 0;
        পূর্ণাঙ্ক n = arm64_hfa_aux(type, &sz, 0);
        যদি (0 < n && n <= 4) {
            যদি (fsize)
                *fsize = sz;
            প্রত্যাগম n;
        }
    }
    প্রত্যাগম 0;
}

স্থির unsigned long arm64_pcs_aux(পূর্ণাঙ্ক variadic, পূর্ণাঙ্ক n, CType **type, unsigned long *a)
{
    পূর্ণাঙ্ক nx = 0; // next integer register
    পূর্ণাঙ্ক nv = 0; // next vector register
    unsigned long ns = 32; // next stack offset
    পূর্ণাঙ্ক i;

    প্রতি (i = 0; i < n; i++) {
        পূর্ণাঙ্ক hfa = arm64_hfa(type[i], 0);
        পূর্ণাঙ্ক size, align, bt;

        bt = type[i]->t & VT_BTYPE;
        যদি (bt == VT_PTR || bt == VT_FUNC)
            size = align = 8;
        অন্যথা
            size = type_size(type[i], &align);

#যদি defined(TCC_TARGET_MACHO)
        যদি (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#নোচেদ্যদি defined(TCC_TARGET_PE)
        যদি (variadic && i >= variadic) {
            hfa = 0;
            যদি (is_float(bt))
                bt = VT_INT, size = align = 8;
        }
#endif
        যদি (hfa)
            // B.2
            ;
        অন্যথা যদি (size > 16) {
            // B.3: replace with pointer
            যদি (nx < 8)
                a[i] = nx++ << 1 | 1;
            অন্যথা {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            অনুবর্ত;
        }
        অন্যথা যদি (bt == VT_STRUCT)
            // B.4
            size = (size + 7) & ~7;

        // C.1
        যদি (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            অনুবর্ত;
        }

        // C.2
        যদি (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            অনুবর্ত;
        }

        // C.3
        যদি (hfa) {
            nv = 8;
            size = (size + 7) & ~7;
        }

        // C.4
        যদি (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        যদি (bt == VT_FLOAT)
            size = 8;

        // C.6
        যদি (hfa || is_float(bt)) {
            a[i] = ns;
            ns += size;
            অনুবর্ত;
        }

        // C.7
        যদি (bt != VT_STRUCT && size <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            অনুবর্ত;
        }

        // C.8
        যদি (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        যদি (bt != VT_STRUCT && size == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            অনুবর্ত;
        }

        // C.10
        যদি (bt == VT_STRUCT && size <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (size + 7) >> 3;
            অনুবর্ত;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        যদি (bt == VT_STRUCT) {
            a[i] = ns;
            ns += size;
            অনুবর্ত;
        }

        // C.14
        যদি (size < 8)
            size = 8;

        // C.15
        a[i] = ns;
        ns += size;
    }

    প্রত্যাগম ns - 32;
}

স্থির unsigned long arm64_pcs(পূর্ণাঙ্ক variadic, পূর্ণাঙ্ক n, CType **type, unsigned long *a)
{
    unsigned long স্তূপ;

    // Return type:
    যদি ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    অন্যথা {
        arm64_pcs_aux(0, 1, type, a);
        প্রতিজ্ঞা(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    স্তূপ = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    যদি (0) {
        পূর্ণাঙ্ক i;
        প্রতি (i = 0; i < n; i++) {
            যদি (!i)
                printf("arm64_pcs return: ");
            অন্যথা
                printf("arm64_pcs arg %d: ", i);
            যদি (a[i] == (unsigned long)-1)
                printf("void\n");
            অন্যথা যদি (a[i] == 1 && !i)
                printf("X8 pointer\n");
            অন্যথা যদি (a[i] < 16)
                printf("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            অন্যথা যদি (a[i] < 32)
                printf("V%lu\n", a[i] / 2 - 8);
            অন্যথা
                printf("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    প্রত্যাগম স্তূপ;
}

স্থির পূর্ণাঙ্ক n_func_args(CType *type)
{
    পূর্ণাঙ্ক n_args = 0;
    Sym *arg;

    প্রতি (arg = type->ref->next; arg; arg = arg->next)
        n_args++;
    প্রত্যাগম n_args;
}

স্থির শূন্য arm64_sub_sp(uint64_t diff)
{
    যদি (!diff)
        প্রত্যাগম;
#ifdef TCC_TARGET_PE
    যদি (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        প্রত্যাগম;
    }
#endif
    যদি (!(diff >> 24)) {
        যদি (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        যদি (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } অন্যথা {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

স্থির পূর্ণাঙ্ক gv_addr(পূর্ণাঙ্ক r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    প্রত্যাগম gv(r);
}

ST_FUNC শূন্য gfunc_call(পূর্ণাঙ্ক nb_args)
{
    CType *return_type;
    CType **t;
    unsigned long *a, *a1;
    unsigned long স্তূপ;
    পূর্ণাঙ্ক i;
    পূর্ণাঙ্ক func_type = vtop[-nb_args].type.ref->f.func_type;
    পূর্ণাঙ্ক variadic = (func_type == FUNC_ELLIPSIS);
    পূর্ণাঙ্ক old_style = (func_type == FUNC_OLD);
    পূর্ণাঙ্ক var_nb_arg = variadic ? n_func_args(&vtop[-nb_args].type) : 0;

    save_regs(nb_args + 1);

#ifdef CONFIG_TCC_BCHECK
    যদি (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    return_type = &vtop[-nb_args].type.ref->type;
    যদি ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_args;

    t = tcc_malloc((nb_args + 1) * পরিমাণ(*t));
    a = tcc_malloc((nb_args + 1) * পরিমাণ(*a));
    a1 = tcc_malloc((nb_args + 1) * পরিমাণ(*a1));

    t[0] = return_type;
    প্রতি (i = 0; i < nb_args; i++)
        t[nb_args - i] = &vtop[-i].type;

    স্তূপ = arm64_pcs(
#ifdef TCC_TARGET_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#endif
        var_nb_arg, nb_args + 1, t, a);

    // Allocate space for structs replaced by pointer:
    প্রতি (i = nb_args; i; i--)
        যদি (a[i] & 1) {
            SValue *arg = &vtop[i - nb_args];
            পূর্ণাঙ্ক align, size = type_size(&arg->type, &align);
            প্রতিজ্ঞা((arg->type.t & VT_BTYPE) == VT_STRUCT);
            স্তূপ = (স্তূপ + align - 1) & -align;
            a1[i] = স্তূপ;
            স্তূপ += size;
        }

    স্তূপ = (স্তূপ + 15) >> 4 << 4;

    যদি (স্তূপ >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", স্তূপ);
    arm64_sub_sp(স্তূপ);

    // First pass: set all values on stack
    প্রতি (i = nb_args; i; i--) {
        vpushv(vtop - nb_args + i);

        যদি (a[i] & 1) {
            // struct replaced by pointer
            পূর্ণাঙ্ক r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            যদি (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        অন্যথা যদি (a[i] >= 32) {
            // value on stack
            যদি ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                পূর্ণাঙ্ক r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            অন্যথা যদি (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_size(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            অন্যথা {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    প্রতি (i = nb_args; i; i--, vtop--) {
        যদি (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            যদি ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                যদি ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                অন্যথা
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            অন্যথা যদি ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                পূর্ণাঙ্ক align, size = type_size(&vtop->type, &align);
                যদি (size) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, size);
                }
            }
            অন্যথা
                gv(RC_R(a[i] / 2));
        }
        অন্যথা যদি (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        অন্যথা যদি (a[i] < 32) {
            // value in floating-point registers
            যদি ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                যদি (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    প্রতি (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } অন্যথা {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            অন্যথা
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    যদি ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        যদি (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        অন্যথা
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    যদি (স্তূপ & 0xfff)
        o(0x910003ff | (স্তূপ & 0xfff) << 10); // add sp,sp,#(n)
    যদি (স্তূপ >> 12)
        o(0x914003ff | (স্তূপ >> 12) << 10);

    {
        পূর্ণাঙ্ক rt = return_type->t;
        পূর্ণাঙ্ক bt = rt & VT_BTYPE;
        যদি (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            যদি (a[0] == 0) {
                পূর্ণাঙ্ক align, size = type_size(return_type, &align);
                প্রতিজ্ঞা(size <= 16);
                যদি (size > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                অন্যথা যদি (size)
                    arm64_strx(size > 4 ? 3 : size > 2 ? 2 : size > 1, 0, 8, 0);

            }
            অন্যথা যদি (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                প্রতি (j = 0; j < n; j++)
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

স্থির unsigned long arm64_func_va_list_স্তূপ;
স্থির পূর্ণাঙ্ক arm64_func_va_list_gr_offs;
স্থির পূর্ণাঙ্ক arm64_func_va_list_vr_offs;
স্থির পূর্ণাঙ্ক arm64_func_sub_sp_offset;

স্থির unsigned arm64_func_start_offset;
#define ARM64_FUNC_স্তূপ_SETUP_SLOTS 6

#ifdef TCC_TARGET_PE
স্থির unsigned long arm64_pe_param_off(unsigned long a)
{
    প্রত্যাগম a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#endif

ST_FUNC শূন্য gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    পূর্ণাঙ্ক n = 0;
    পূর্ণাঙ্ক i = 0;
    Sym *sym;
    CType **t;
    unsigned long *a;
    পূর্ণাঙ্ক use_x8 = 0;
    পূর্ণাঙ্ক last_int = 0;
    পূর্ণাঙ্ক last_float = 0;
    পূর্ণাঙ্ক variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    পূর্ণাঙ্ক var_nb_arg = variadic ? n_func_args(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    প্রতি (sym = func_type->ref; sym; sym = sym->next)
        ++n;

#ifdef TCC_TARGET_PE
    n += variadic;
#endif

    t = tcc_malloc(n * পরিমাণ(*t));
    a = tcc_malloc(n * পরিমাণ(*a));
    প্রতি (sym = func_type->ref; sym; sym = sym->next)
        t[i++] = &sym->type;

#ifdef TCC_TARGET_PE
    যদি (variadic)
        t[i] = &int_type;
#endif

    arm64_func_va_list_স্তূপ = arm64_pcs(var_nb_arg, n, t, a);

#ifdef TCC_TARGET_PE
    যদি (variadic)
        arm64_func_va_list_স্তূপ = arm64_pe_param_off(a[n - 1]);
#endif

#যদি !defined(TCC_TARGET_MACHO)
    যদি (variadic) {
        use_x8 = 1;
        last_int = 4;
        last_float = 4;
    }
#endif

    যদি (a && a[0] == 1)
        use_x8 = 1;
    প্রতি (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        যদি (a[i] < 16) {
            পূর্ণাঙ্ক last, align, size = type_size(&sym->type, &align);
	    last = a[i] / 4 + 1 + (size - 1) / 8;
	    last_int = last > last_int ? last : last_int;
	}
        অন্যথা যদি (a[i] < 32) {
            পূর্ণাঙ্ক last, hfa = arm64_hfa(&sym->type, 0);
	    last = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    last_float = last > last_float ? last : last_float;
	}
    }

    last_int = last_int > 4 ? 4 : last_int;
    last_float = last_float > 4 ? 4 : last_float;

    arm64_func_start_offset = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    প্রতি (i = 0; i < last_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    যদি (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    প্রতি (i = 0; i < last_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    প্রতি (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        পূর্ণাঙ্ক off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_set_param(sym, off, a[i] & 1);

        যদি (a[i] < 16) {
            পূর্ণাঙ্ক align, size = type_size(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && size > 8)) * 8;
        }
        অন্যথা যদি (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        যদি (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            যদি (k > 0 && sz < 16)
                প্রতি (j = 0; j < k; j++) {
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
    প্রতি (i = 0; i < ARM64_FUNC_স্তূপ_SETUP_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#ifdef CONFIG_TCC_BCHECK
    যদি (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

ST_FUNC শূন্য gen_va_start(শূন্য)
{
    পূর্ণাঙ্ক r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#ifdef TCC_TARGET_PE
    যদি (arm64_func_va_list_স্তূপ) {
        arm64_movimm(30, arm64_func_va_list_স্তূপ);
        o(0x8b1e03be); // add x30,x29,x30
    } অন্যথা
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#অন্যথা
    যদি (arm64_func_va_list_স্তূপ) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_স্তূপ + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    অন্যথা
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#যদি !defined(TCC_TARGET_MACHO)
    যদি (arm64_func_va_list_gr_offs) {
        যদি (arm64_func_va_list_স্তূপ)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    যদি (arm64_func_va_list_vr_offs) {
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

ST_FUNC শূন্য gen_va_arg(CType *t)
{
    পূর্ণাঙ্ক align, size = type_size(t, &align);
    uint32_t r0, r1;

#ifdef TCC_TARGET_PE
    পূর্ণাঙ্ক indirect = 0, slot = (size + 7) & -8;

    যদি (size > 16)
        indirect = 1, slot = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    যদি (slot) {
        যদি (slot == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        যদি (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | slot << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    যদি (indirect)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#অন্যথা /* !PE */
    unsigned fsize = size, hfa = 1;

    যদি (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    যদি (!hfa) {
        uint32_t n = size > 16 ? 8 : (size + 7) & -8;

#যদি !defined(TCC_TARGET_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        যদি (align == 16) {
            প্রতিজ্ঞা(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#endif

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        যদি (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#যদি !defined(TCC_TARGET_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#endif

        যদি (size > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    অন্যথা {
        uint32_t ssz = (size + 7) & -(uint32_t)8;
#যদি !defined(TCC_TARGET_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#endif
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        যদি (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#যদি !defined(TCC_TARGET_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_text_section->data + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        যদি (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        অন্যথা {
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

ST_FUNC পূর্ণাঙ্ক gfunc_sret(CType *vt, পূর্ণাঙ্ক variadic, CType *ret,
                       পূর্ণাঙ্ক *align, পূর্ণাঙ্ক *regsize)
{
    প্রত্যাগম 0;
}

ST_FUNC শূন্য gfunc_return(CType *func_type)
{
    CType *t = func_type;
    unsigned long a;

    arm64_pcs(0, 1, &t, &a);

    বিকল্প (a) {
    পক্ষ -1:
        ভঙ্গ;
    পক্ষ 0:
        যদি ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            পূর্ণাঙ্ক align, size = type_size(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, size);
        }
        অন্যথা
            gv(RC_IRET);
        ভঙ্গ;
    পক্ষ 1: {
        CType type = *func_type;
        mk_pointer(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        ভঙ্গ;
    }
    পক্ষ 16:
        যদি ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          প্রতি (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        অন্যথা
            gv(RC_FRET);
        ভঙ্গ;
    স্বভাব:
      প্রতিজ্ঞা(0);
    }
    vtop--;
}

ST_FUNC শূন্য gfunc_epilog(শূন্য)
{
#ifdef CONFIG_TCC_BCHECK
    যদি (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    যদি (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        পূর্ণাঙ্ক i;
        addr_t saved_ind = ind;
        addr_t patch_end = arm64_func_sub_sp_offset + ARM64_FUNC_স্তূপ_SETUP_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_offset;
        arm64_sub_sp(diff);
        প্রতি (i = ind; i < patch_end; i += 4)
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

ST_FUNC শূন্য gen_fill_nops(পূর্ণাঙ্ক bytes)
{
    যদি ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    যাবত্ (bytes > 0) {
	o(ARM64_NOP); // nop
	bytes -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC পূর্ণাঙ্ক gjmp(পূর্ণাঙ্ক t)
{
    পূর্ণাঙ্ক r = ind;
    যদি (nocode_wanted)
        প্রত্যাগম t;
    o(t);
    প্রত্যাগম r;
}

// Generate branch to known address:
ST_FUNC শূন্য gjmp_addr(পূর্ণাঙ্ক a)
{
    প্রতিজ্ঞা(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC পূর্ণাঙ্ক gjmp_append(পূর্ণাঙ্ক n, পূর্ণাঙ্ক t)
{
    শূন্য *p;
    /* insert vtop->c jump list in t */
    যদি (n) {
        uint32_t n1 = n, n2;
        যাবত্ ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    প্রত্যাগম t;
}

শূন্য arm64_vset_VT_CMP(পূর্ণাঙ্ক op)
{
    যদি (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

স্থির শূন্য arm64_gen_opil(পূর্ণাঙ্ক op, uint32_t l);

স্থির শূন্য arm64_load_cmp(পূর্ণাঙ্ক r, SValue *sv)
{
    sv->r = sv->cmp_r;
    যদি (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    যদি (r != sv->r) {
        load(r, sv);
        sv->r = r;
    }
}

ST_FUNC পূর্ণাঙ্ক gjmp_cond(পূর্ণাঙ্ক op, পূর্ণাঙ্ক t)
{
    পূর্ণাঙ্ক bt = vtop->type.t & VT_BTYPE;

    পূর্ণাঙ্ক inv = op & 1;
    vtop->r = vtop->cmp_r;

    যদি (bt == VT_LDOUBLE) {
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
    অন্যথা যদি (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    অন্যথা {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    প্রত্যাগম gjmp(t);
}

স্থির পূর্ণাঙ্ক arm64_iconst(uint64_t *val, SValue *sv)
{
    যদি ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        প্রত্যাগম 0;
    যদি (val) {
        পূর্ণাঙ্ক t = sv->type.t;
	পূর্ণাঙ্ক bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    প্রত্যাগম 1;
}

স্থির পূর্ণাঙ্ক arm64_gen_opic(পূর্ণাঙ্ক op, uint32_t l, পূর্ণাঙ্ক rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    যদি (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    বিকল্প (op) {

    পক্ষ '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        যদি (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        অন্যথা যদি (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        অন্যথা {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        প্রত্যাগম 1;
      }

    পক্ষ '-':
        যদি (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        অন্যথা যদি (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        অন্যথা {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        প্রত্যাগম 1;

    পক্ষ '^':
        যদি (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            প্রত্যাগম 1;
        }
        // fall through
    পক্ষ '&':
    পক্ষ '|': {
        পূর্ণাঙ্ক e = arm64_encode_bimm64(l ? val : val | val << 32);
        যদি (e < 0)
            প্রত্যাগম 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        প্রত্যাগম 1;
    }

    পক্ষ TOK_SAR:
    পক্ষ TOK_SHL:
    পক্ষ TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        যদি (rev)
            প্রত্যাগম 0;
        যদি (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            প্রত্যাগম 1;
        }
        অন্যথা যদি (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        অন্যথা
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        প্রত্যাগম 1;
    }

    }
    প্রত্যাগম 0;
}

স্থির শূন্য arm64_gen_opil(পূর্ণাঙ্ক op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        পূর্ণাঙ্ক rev = 1;

        যদি (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        যদি (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            যদি (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                প্রত্যাগম;
            }
        }
        যদি (!rev)
            vswap();
    }

    gv2(RC_INT, RC_INT);
    প্রতিজ্ঞা(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = intr(vtop[-1].r);
    b = intr(vtop[0].r);
    vtop -= 2;
    x = get_reg(RC_INT);
    ++vtop;
    vtop[0].r = x;
    x = intr(x);

    বিকল্প (op) {
    পক্ষ '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ভঙ্গ;
    পক্ষ '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        ভঙ্গ;
    পক্ষ '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        ভঙ্গ;
    পক্ষ '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        ভঙ্গ;
    পক্ষ '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        ভঙ্গ;
    পক্ষ '/':
    পক্ষ TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        ভঙ্গ;
    পক্ষ '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        ভঙ্গ;
    পক্ষ '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        ভঙ্গ;
    পক্ষ TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        ভঙ্গ;
    পক্ষ TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        ভঙ্গ;
    পক্ষ TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        ভঙ্গ;
    পক্ষ TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        ভঙ্গ;
    পক্ষ TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        ভঙ্গ;
    পক্ষ TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        ভঙ্গ;
    পক্ষ TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        ভঙ্গ;
    পক্ষ TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        ভঙ্গ;
    পক্ষ TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        ভঙ্গ;
    পক্ষ TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        ভঙ্গ;
    পক্ষ TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        ভঙ্গ;
    পক্ষ TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        ভঙ্গ;
    পক্ষ TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        ভঙ্গ;
    পক্ষ TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        ভঙ্গ;
    পক্ষ TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ভঙ্গ;
    স্বভাব:
        প্রতিজ্ঞা(0);
    }
}

ST_FUNC শূন্য gen_opi(পূর্ণাঙ্ক op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC শূন্য gen_opl(পূর্ণাঙ্ক op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC শূন্য gen_opf(পূর্ণাঙ্ক op)
{
    uint32_t x, a, b, dbl;
    পূর্ণাঙ্ক bt = vtop[0].type.t & VT_BTYPE;

    যদি (op == TOK_NEG) {
        যদি (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } অন্যথা {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        প্রত্যাগম;
    }

    যদি (bt == VT_LDOUBLE) {
        CType type = vtop[0].type;
        পূর্ণাঙ্ক func = 0;
        পূর্ণাঙ্ক cond = -1;
        বিকল্প (op) {
        পক্ষ '*': func = TOK___multf3; ভঙ্গ;
        পক্ষ '+': func = TOK___addtf3; ভঙ্গ;
        পক্ষ '-': func = TOK___subtf3; ভঙ্গ;
        পক্ষ '/': func = TOK___divtf3; ভঙ্গ;
        পক্ষ TOK_EQ: func = TOK___eqtf2; cond = 1; ভঙ্গ;
        পক্ষ TOK_NE: func = TOK___netf2; cond = 0; ভঙ্গ;
        পক্ষ TOK_LT: func = TOK___lttf2; cond = 10; ভঙ্গ;
        পক্ষ TOK_GE: func = TOK___getf2; cond = 11; ভঙ্গ;
        পক্ষ TOK_LE: func = TOK___letf2; cond = 12; ভঙ্গ;
        পক্ষ TOK_GT: func = TOK___gttf2; cond = 13; ভঙ্গ;
        স্বভাব: প্রতিজ্ঞা(0); ভঙ্গ;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        যদি (cond < 0)
            vtop->type = type;
        অন্যথা {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        প্রত্যাগম;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    প্রতিজ্ঞা(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    বিকল্প (op) {
    পক্ষ TOK_EQ: পক্ষ TOK_NE:
    পক্ষ TOK_LT: পক্ষ TOK_GE: পক্ষ TOK_LE: পক্ষ TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        ভঙ্গ;
    স্বভাব:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        ভঙ্গ;
    }

    বিকল্প (op) {
    পক্ষ '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        ভঙ্গ;
    পক্ষ '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        ভঙ্গ;
    পক্ষ '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        ভঙ্গ;
    পক্ষ '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        ভঙ্গ;
    পক্ষ TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        ভঙ্গ;
    পক্ষ TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        ভঙ্গ;
    পক্ষ TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        ভঙ্গ;
    পক্ষ TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        ভঙ্গ;
    পক্ষ TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        ভঙ্গ;
    পক্ষ TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        ভঙ্গ;
    স্বভাব:
        প্রতিজ্ঞা(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC শূন্য gen_cvt_sxtw(শূন্য)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC শূন্য gen_cvt_csti(পূর্ণাঙ্ক t)
{
    পূর্ণাঙ্ক r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC শূন্য gen_cvt_itof(পূর্ণাঙ্ক t)
{
    যদি (t == VT_LDOUBLE) {
        পূর্ণাঙ্ক f = vtop->type.t;
        পূর্ণাঙ্ক func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        প্রত্যাগম;
    }
    অন্যথা {
        পূর্ণাঙ্ক d, n = intr(gv(RC_INT));
        পূর্ণাঙ্ক s = !(vtop->type.t & VT_UNSIGNED);
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

ST_FUNC শূন্য gen_cvt_ftoi(পূর্ণাঙ্ক t)
{
    যদি ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        পূর্ণাঙ্ক func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        প্রত্যাগম;
    }
    অন্যথা {
        পূর্ণাঙ্ক d, n = fltr(gv(RC_FLOAT));
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

ST_FUNC শূন্য gen_cvt_ftof(পূর্ণাঙ্ক t)
{
    পূর্ণাঙ্ক f = vtop[0].type.t & VT_BTYPE;
    প্রতিজ্ঞা(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    প্রতিজ্ঞা(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    যদি (t == f)
        প্রত্যাগম;

    যদি (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        পূর্ণাঙ্ক func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    অন্যথা {
        পূর্ণাঙ্ক x, a;
        gv(RC_FLOAT);
        প্রতিজ্ঞা(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        যদি (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        অন্যথা
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC শূন্য gen_increment_tcov (SValue *sv)
{
    পূর্ণাঙ্ক r1, r2;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    arm64_sym(r1, sv->sym, 0);
    o(ARM64_LDR_X | ARM64_RN(intr(r1)) | intr(r2)); // ldr r2, [r1]
    o(0x91000400 | (intr(r2)<<5) | intr(r2)); // add r2, r2, #1
    o(0xf9000000 | (intr(r1)<<5) | intr(r2)); // str r2, [r1]
    vpop();
}

ST_FUNC শূন্য ggoto(শূন্য)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC শূন্য gen_clear_cache(শূন্য)
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

ST_FUNC শূন্য gen_vla_sp_save(পূর্ণাঙ্ক addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC শূন্য gen_vla_sp_restore(পূর্ণাঙ্ক addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC শূন্য gen_vla_alloc(CType *type, পূর্ণাঙ্ক align) {
    uint32_t r;
#যদি defined(CONFIG_TCC_BCHECK)
    যদি (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    r = intr(gv(RC_INT));
#যদি defined(CONFIG_TCC_BCHECK)
    যদি (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    অন্যথা
#endif
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#যদি defined(CONFIG_TCC_BCHECK)
    যদি (tcc_state->do_bounds_check) {
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
