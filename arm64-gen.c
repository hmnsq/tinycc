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

#ଯଦି !defined(TCC_TARGET_MACHO) && !defined(TCC_TARGET_PE)
#define CHAR_IS_UNSIGNED
#endif

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#define PROMOTE_RET
/******************************************************/
#ଅନ୍ୟଥା /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#ଅନ୍ତର୍ଭାଵ "tcc.h"
#ଅନ୍ତର୍ଭାଵ <assert.h>

ST_DATA ଅଚଳ ଅକ୍ଷର * ଅଚଳ target_machine_defs =
    "__aarch64__\0"
#ଯଦି defined(TCC_TARGET_MACHO)
    "__arm64__\0"
#endif
    "__AARCH64EL__\0"
    ;

ST_DATA ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା reg_classes[NB_REGS] = {
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

#ଯଦି defined(CONFIG_TCC_BCHECK)
ସ୍ଥିର addr_t func_bound_offset;
ସ୍ଥିର unsigned long func_bound_ind;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_bound_add_epilog;
#endif

#define IS_FREG(x) ((x) >= TREG_F(0))

ସ୍ଥିର uint32_t intr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r)
{
    ପ୍ରତିଜ୍ଞା(TREG_R(0) <= r && r <= TREG_R30);
    ଫେରନ୍ତୁ r < TREG_R30 ? r : 30;
}

ସ୍ଥିର uint32_t fltr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r)
{
    ପ୍ରତିଜ୍ଞା(TREG_F(0) <= r && r <= TREG_F(7));
    ଫେରନ୍ତୁ r - TREG_F(0);
}

// Add an instruction to text section:
ST_FUNC ଶୂନ୍ୟ o(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ind1 = ind + 4;
    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ;
    ଯଦି (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    write32le(cur_text_section->data + ind, c);
    ind = ind1;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_encode_bimm64(uint64_t x)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା neg = x & 1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା rep, pos, len;

    ଯଦି (neg)
        x = ~x;
    ଯଦି (!x)
        ଫେରନ୍ତୁ -1;

    ଯଦି (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    ଅନ୍ୟଥା ଯଦି (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    ଅନ୍ୟଥା ଯଦି (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    ଅନ୍ୟଥା ଯଦି (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    ଅନ୍ୟଥା ଯଦି (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    ଅନ୍ୟଥା
        rep = 64;

    pos = 0;
    ଯଦି (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    ଯଦି (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    ଯଦି (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    ଯଦି (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    ଯଦି (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    ଯଦି (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    ଯଦି (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    ଯଦି (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    ଯଦି (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    ଯଦି (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    ଯଦି (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    ଯଦି (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    ଯଦି (x)
        ଫେରନ୍ତୁ -1;
    ଯଦି (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    ଫେରନ୍ତୁ ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ସ୍ଥିର uint32_t arm64_movi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, uint64_t x)
{
    uint64_t m = 0xffff;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା e;
    ଯଦି (!(x & ~m))
        ଫେରନ୍ତୁ ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    ଯଦି (!(x & ~(m << 16)))
        ଫେରନ୍ତୁ (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    ଯଦି (!(x & ~(m << 32)))
        ଫେରନ୍ତୁ (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    ଯଦି (!(x & ~(m << 48)))
        ଫେରନ୍ତୁ (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    ଯଦି ((x & ~m) == m << 16)
        ଫେରନ୍ତୁ (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    ଯଦି ((x & ~(m << 16)) == m)
        ଫେରନ୍ତୁ (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    ଯଦି (!~(x | m))
        ଫେରନ୍ତୁ (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    ଯଦି (!~(x | m << 16))
        ଫେରନ୍ତୁ (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    ଯଦି (!~(x | m << 32))
        ଫେରନ୍ତୁ (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ଯଦି (!~(x | m << 48))
        ଫେରନ୍ତୁ (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ଯଦି (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        ଫେରନ୍ତୁ (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    ଯଦି ((e = arm64_encode_bimm64(x)) >= 0)
        ଫେରନ୍ତୁ (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    ଫେରନ୍ତୁ 0;
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_movimm(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, uint64_t x)
{
    uint32_t i;
    ଯଦି ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    ଅନ୍ୟଥା {
        // MOVZ/MOVN and 1-3 MOVKs
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        ପାଇଁ (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        ଯଦି (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        ପାଇଁ (i = 0; i < 64; i += 16)
            ଯଦି (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                ଭାଙ୍ଗ;
            }
        ପାଇଁ (i += 16; i < 64; i += 16)
            ଯଦି (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC ଶୂନ୍ୟ gsym_addr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t_, ପୂର୍ଣ୍ଣସଂଖ୍ୟା a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    ଯେତେବେଳେ (t) {
        unsigned ଅକ୍ଷର *ptr = cur_text_section->data + t;
        uint32_t next = read32le(ptr);
        ଯଦି (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = next;
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_type_size(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    ବାଛ (t & VT_BTYPE) {
    ସ୍ଥିତି VT_BYTE: ଫେରନ୍ତୁ 0;
    ସ୍ଥିତି VT_SHORT: ଫେରନ୍ତୁ 1;
    ସ୍ଥିତି VT_INT: ଫେରନ୍ତୁ 2;
    ସ୍ଥିତି VT_LLONG: ଫେରନ୍ତୁ 3;
    ସ୍ଥିତି VT_PTR: ଫେରନ୍ତୁ 3;
    ସ୍ଥିତି VT_FUNC: ଫେରନ୍ତୁ 3;
    ସ୍ଥିତି VT_STRUCT: ଫେରନ୍ତୁ 3;
    ସ୍ଥିତି VT_FLOAT: ଫେରନ୍ତୁ 2;
    ସ୍ଥିତି VT_DOUBLE: ଫେରନ୍ତୁ 3;
    ସ୍ଥିତି VT_LDOUBLE: ଫେରନ୍ତୁ 4;
    ସ୍ଥିତି VT_BOOL: ଫେରନ୍ତୁ 0;
    }
    ପ୍ରତିଜ୍ଞା(0);
    ଫେରନ୍ତୁ 0;
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_spoff(ପୂର୍ଣ୍ଣସଂଖ୍ୟା reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    ଯଦି (sub)
        off = -off;
    ଯଦି (off < 4096)
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    ଅନ୍ୟଥା {
        arm64_movimm(30, off);
        o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

ସ୍ଥିର uint64_t arm64_check_offset(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sz_, uint64_t off)
{
#ifndef TCC_TARGET_PE
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    ଯଦି (!(off & ~scaled_mask) || (off < 256 || -off <= 256))
        ଫେରନ୍ତୁ ~0ull;
    ଯଦି (off & scaled_mask)
        ଫେରନ୍ତୁ scaled_mask;
    ଯଦି (off & 0x1fful)
        ଫେରନ୍ତୁ 0x1fful;
#endif
    ଫେରନ୍ତୁ 0;
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_ldrx(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sg, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sz_, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dst, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    ଯଦି (sz >= 2)
        sg = 0;
    ଯଦି (!(off & ~scaled_mask))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    ଅନ୍ୟଥା ଯଦି (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    ଅନ୍ୟଥା {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_ldrv(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sz_, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dst, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    ଯଦି (!(off & ~scaled_mask))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    ଅନ୍ୟଥା ଯଦି (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    ଅନ୍ୟଥା {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_ldrs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା reg_, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    ବାଛ (size) {
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ: ପ୍ରତିଜ୍ଞା(0); ଭାଙ୍ଗ;
    ସ୍ଥିତି 0:
        /* Can happen with zero size structs */
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        ଭାଙ୍ଗ;
    }
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_strx(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sz_, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dst, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    ଯଦି (!(off & ~scaled_mask))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    ଅନ୍ୟଥା ଯଦି (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    ଅନ୍ୟଥା {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_strv(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sz_, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dst, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    ଯଦି (!(off & ~scaled_mask))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    ଅନ୍ୟଥା ଯଦି (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    ଅନ୍ୟଥା {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_reloca(Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା reloc_type, uint64_t addend)
{
    greloca(cur_text_section, sym, ind, reloc_type, addend);
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_sym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, Sym *sym, addr_t addend)
{
    ଯଦି (sym->type.t & VT_TLS) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#ଅନ୍ୟଥା
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#endif
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_HI12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_LO12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#ifndef TCC_TARGET_PE /* no elf-style GOT on Windows */
    } ଅନ୍ୟଥା ଯଦି (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_PAGE, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        ଯଦି (addend > 0xffffff) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } ଅନ୍ୟଥା {
           ଯଦି (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_ADD_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            ଯଦି (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#endif
    } ଅନ୍ୟଥା {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_ADD_ABS_LO12_NC, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_load_cmp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, SValue *sv);

ST_FUNC ଶୂନ୍ୟ load(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, SValue *sv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା svtt = sv->type.t;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sb = !(svtt & VT_UNSIGNED);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sz = arm64_type_size(svtt);

    ଯଦି (svr == (VT_LOCAL | VT_LVAL)) {
        ଯଦି (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        ଅନ୍ୟଥା
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        ଯଦି (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        ଅନ୍ୟଥା
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svrv < VT_CONST && (svr & VT_LVAL)) {
        ଯଦି (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        ଅନ୍ୟଥା
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        ଯଦି (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & mask);
        ଅନ୍ୟଥା
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & mask);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svr < VT_CONST) {
        ଯଦି (IS_FREG(r) && IS_FREG(svr))
            ଯଦି (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            ଅନ୍ୟଥା
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        ଅନ୍ୟଥା ଯଦି (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        ଅନ୍ୟଥା
            ପ୍ରତିଜ୍ଞା(0);
      ଫେରନ୍ତୁ;
    }

    ଯଦି (svr == VT_LOCAL) {
        ଯଦି (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        ଅନ୍ୟଥା {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svr == VT_JMP || svr == VT_JMPI) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        ଯଦି (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        ଅନ୍ୟଥା
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svr == VT_CMP) {
        arm64_load_cmp(r, sv);
        ଫେରନ୍ତୁ;
    }

    printf("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (long)svcul);
    ପ୍ରତିଜ୍ଞା(0);
}

ST_FUNC ଶୂନ୍ୟ store(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, SValue *sv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା svtt = sv->type.t;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sz = arm64_type_size(svtt);

    ଯଦି (svr == (VT_LOCAL | VT_LVAL)) {
        ଯଦି (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        ଅନ୍ୟଥା
            arm64_strx(sz, intr(r), 29, svcoff);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        ଯଦି (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        ଅନ୍ୟଥା
            arm64_strx(sz, intr(r), 30, 0);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svrv < VT_CONST && (svr & VT_LVAL)) {
        ଯଦି (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        ଅନ୍ୟଥା
            arm64_strx(sz, intr(r), intr(svrv), 0);
        ଫେରନ୍ତୁ;
    }

    ଯଦି (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        ଯଦି (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & mask);
        ଅନ୍ୟଥା
            arm64_strx(sz, intr(r), 30, svcoff & mask);
        ଫେରନ୍ତୁ;
    }

    printf("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (long)svcoff);
    ପ୍ରତିଜ୍ଞା(0);
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_gen_bl_or_b(ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
    ଯଦି ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    ଅନ୍ୟଥା {
#ifdef CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#endif
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#ଯଦି defined CONFIG_TCC_BCHECK || defined TCC_TARGET_PE
ସ୍ଥିର ଶୂନ୍ୟ gen_static_call(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#endif

#ଯଦି defined(CONFIG_TCC_BCHECK)
ସ୍ଥିର ଶୂନ୍ୟ gen_bounds_prolog(ଶୂନ୍ୟ)
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

ସ୍ଥିର ଶୂନ୍ୟ gen_bounds_epilog(ଶୂନ୍ୟ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା offset_modified = func_bound_offset != lbounds_section->data_offset;

    ଯଦି (!offset_modified && !func_bound_add_epilog)
        ଫେରନ୍ତୁ;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, ଆକାର(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    ଯଦି (offset_modified) {
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

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_hfa_aux(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *fsize, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ)
{
    ଯଦି (is_float(type->t)) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, n = type_size(type, &a);
        ଯଦି (ଅଙ୍କ >= 4 || (*fsize && *fsize != n))
            ଫେରନ୍ତୁ -1;
        *fsize = n;
        ଫେରନ୍ତୁ ଅଙ୍କ + 1;
    }
    ଅନ୍ୟଥା ଯଦି ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field;
        ଯଦି (!IS_UNION(type->t)) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା num0 = ଅଙ୍କ;
            ପାଇଁ (field = type->ref->next; field; field = field->next) {
                ଯଦି (field->c != (ଅଙ୍କ - num0) * *fsize)
                    ଫେରନ୍ତୁ -1;
                ଅଙ୍କ = arm64_hfa_aux(&field->type, fsize, ଅଙ୍କ);
                ଯଦି (ଅଙ୍କ == -1)
                    ଫେରନ୍ତୁ -1;
            }
            ଯଦି (type->ref->c != (ଅଙ୍କ - num0) * *fsize)
                ଫେରନ୍ତୁ -1;
            ଫେରନ୍ତୁ ଅଙ୍କ;
        }
        ଅନ୍ୟଥା { // union
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା num0 = ଅଙ୍କ;
            ପାଇଁ (field = type->ref->next; field; field = field->next) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା num1 = arm64_hfa_aux(&field->type, fsize, num0);
                ଯଦି (num1 == -1)
                    ଫେରନ୍ତୁ -1;
                ଅଙ୍କ = num1 < ଅଙ୍କ ? ଅଙ୍କ : num1;
            }
            ଯଦି (type->ref->c != (ଅଙ୍କ - num0) * *fsize)
                ଫେରନ୍ତୁ -1;
            ଫେରନ୍ତୁ ଅଙ୍କ;
        }
    }
    ଅନ୍ୟଥା ଯଦି (type->t & VT_ARRAY) { /* handle float array within struct */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା num1;
        ଯଦି (!type->ref->c)
            ଫେରନ୍ତୁ ଅଙ୍କ;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, ଅଙ୍କ);
        ଯଦି (num1 == -1 || (num1 != ଅଙ୍କ && type->ref->c > 4))
            ଫେରନ୍ତୁ -1;
        num1 = ଅଙ୍କ + type->ref->c * (num1 - ଅଙ୍କ);
        ଯଦି (num1 > 4)
            ଫେରନ୍ତୁ -1;
        ଫେରନ୍ତୁ num1;
    }
    ଫେରନ୍ତୁ -1;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_hfa(CType *type, unsigned *fsize)
{
    ଯଦି ((type->t & VT_BTYPE) == VT_STRUCT) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା sz = 0;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = arm64_hfa_aux(type, &sz, 0);
        ଯଦି (0 < n && n <= 4) {
            ଯଦି (fsize)
                *fsize = sz;
            ଫେରନ୍ତୁ n;
        }
    }
    ଫେରନ୍ତୁ 0;
}

ସ୍ଥିର unsigned long arm64_pcs_aux(ପୂର୍ଣ୍ଣସଂଖ୍ୟା variadic, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, CType **type, unsigned long *a)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nx = 0; // next integer register
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nv = 0; // next vector register
    unsigned long ns = 32; // next stack offset
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    ପାଇଁ (i = 0; i < n; i++) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା hfa = arm64_hfa(type[i], 0);
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align, bt;

        bt = type[i]->t & VT_BTYPE;
        ଯଦି (bt == VT_PTR || bt == VT_FUNC)
            size = align = 8;
        ଅନ୍ୟଥା
            size = type_size(type[i], &align);

#ଯଦି defined(TCC_TARGET_MACHO)
        ଯଦି (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#ନଚେତଯଦି defined(TCC_TARGET_PE)
        ଯଦି (variadic && i >= variadic) {
            hfa = 0;
            ଯଦି (is_float(bt))
                bt = VT_INT, size = align = 8;
        }
#endif
        ଯଦି (hfa)
            // B.2
            ;
        ଅନ୍ୟଥା ଯଦି (size > 16) {
            // B.3: replace with pointer
            ଯଦି (nx < 8)
                a[i] = nx++ << 1 | 1;
            ଅନ୍ୟଥା {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            ଜାରି;
        }
        ଅନ୍ୟଥା ଯଦି (bt == VT_STRUCT)
            // B.4
            size = (size + 7) & ~7;

        // C.1
        ଯଦି (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            ଜାରି;
        }

        // C.2
        ଯଦି (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            ଜାରି;
        }

        // C.3
        ଯଦି (hfa) {
            nv = 8;
            size = (size + 7) & ~7;
        }

        // C.4
        ଯଦି (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        ଯଦି (bt == VT_FLOAT)
            size = 8;

        // C.6
        ଯଦି (hfa || is_float(bt)) {
            a[i] = ns;
            ns += size;
            ଜାରି;
        }

        // C.7
        ଯଦି (bt != VT_STRUCT && size <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            ଜାରି;
        }

        // C.8
        ଯଦି (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        ଯଦି (bt != VT_STRUCT && size == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            ଜାରି;
        }

        // C.10
        ଯଦି (bt == VT_STRUCT && size <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (size + 7) >> 3;
            ଜାରି;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        ଯଦି (bt == VT_STRUCT) {
            a[i] = ns;
            ns += size;
            ଜାରି;
        }

        // C.14
        ଯଦି (size < 8)
            size = 8;

        // C.15
        a[i] = ns;
        ns += size;
    }

    ଫେରନ୍ତୁ ns - 32;
}

ସ୍ଥିର unsigned long arm64_pcs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା variadic, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, CType **type, unsigned long *a)
{
    unsigned long ଗଦା;

    // Return type:
    ଯଦି ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    ଅନ୍ୟଥା {
        arm64_pcs_aux(0, 1, type, a);
        ପ୍ରତିଜ୍ଞା(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    ଗଦା = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    ଯଦି (0) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
        ପାଇଁ (i = 0; i < n; i++) {
            ଯଦି (!i)
                printf("arm64_pcs return: ");
            ଅନ୍ୟଥା
                printf("arm64_pcs arg %d: ", i);
            ଯଦି (a[i] == (unsigned long)-1)
                printf("void\n");
            ଅନ୍ୟଥା ଯଦି (a[i] == 1 && !i)
                printf("X8 pointer\n");
            ଅନ୍ୟଥା ଯଦି (a[i] < 16)
                printf("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            ଅନ୍ୟଥା ଯଦି (a[i] < 32)
                printf("V%lu\n", a[i] / 2 - 8);
            ଅନ୍ୟଥା
                printf("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    ଫେରନ୍ତୁ ଗଦା;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_func_args(CType *type)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_args = 0;
    Sym *arg;

    ପାଇଁ (arg = type->ref->next; arg; arg = arg->next)
        n_args++;
    ଫେରନ୍ତୁ n_args;
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_sub_sp(uint64_t diff)
{
    ଯଦି (!diff)
        ଫେରନ୍ତୁ;
#ifdef TCC_TARGET_PE
    ଯଦି (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        ଫେରନ୍ତୁ;
    }
#endif
    ଯଦି (!(diff >> 24)) {
        ଯଦି (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        ଯଦି (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } ଅନ୍ୟଥା {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା gv_addr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    ଫେରନ୍ତୁ gv(r);
}

ST_FUNC ଶୂନ୍ୟ gfunc_call(ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_args)
{
    CType *return_type;
    CType **t;
    unsigned long *a, *a1;
    unsigned long ଗଦା;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_type = vtop[-nb_args].type.ref->f.func_type;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା variadic = (func_type == FUNC_ELLIPSIS);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା old_style = (func_type == FUNC_OLD);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା var_nb_arg = variadic ? n_func_args(&vtop[-nb_args].type) : 0;

    save_regs(nb_args + 1);

#ifdef CONFIG_TCC_BCHECK
    ଯଦି (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    return_type = &vtop[-nb_args].type.ref->type;
    ଯଦି ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_args;

    t = tcc_malloc((nb_args + 1) * ଆକାର(*t));
    a = tcc_malloc((nb_args + 1) * ଆକାର(*a));
    a1 = tcc_malloc((nb_args + 1) * ଆକାର(*a1));

    t[0] = return_type;
    ପାଇଁ (i = 0; i < nb_args; i++)
        t[nb_args - i] = &vtop[-i].type;

    ଗଦା = arm64_pcs(
#ifdef TCC_TARGET_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#endif
        var_nb_arg, nb_args + 1, t, a);

    // Allocate space for structs replaced by pointer:
    ପାଇଁ (i = nb_args; i; i--)
        ଯଦି (a[i] & 1) {
            SValue *arg = &vtop[i - nb_args];
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା align, size = type_size(&arg->type, &align);
            ପ୍ରତିଜ୍ଞା((arg->type.t & VT_BTYPE) == VT_STRUCT);
            ଗଦା = (ଗଦା + align - 1) & -align;
            a1[i] = ଗଦା;
            ଗଦା += size;
        }

    ଗଦା = (ଗଦା + 15) >> 4 << 4;

    ଯଦି (ଗଦା >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", ଗଦା);
    arm64_sub_sp(ଗଦା);

    // First pass: set all values on stack
    ପାଇଁ (i = nb_args; i; i--) {
        vpushv(vtop - nb_args + i);

        ଯଦି (a[i] & 1) {
            // struct replaced by pointer
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            ଯଦି (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        ଅନ୍ୟଥା ଯଦି (a[i] >= 32) {
            // value on stack
            ଯଦି ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            ଅନ୍ୟଥା ଯଦି (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_size(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            ଅନ୍ୟଥା {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    ପାଇଁ (i = nb_args; i; i--, vtop--) {
        ଯଦି (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            ଯଦି ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                ଯଦି ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                ଅନ୍ୟଥା
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            ଅନ୍ୟଥା ଯଦି ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା align, size = type_size(&vtop->type, &align);
                ଯଦି (size) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, size);
                }
            }
            ଅନ୍ୟଥା
                gv(RC_R(a[i] / 2));
        }
        ଅନ୍ୟଥା ଯଦି (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        ଅନ୍ୟଥା ଯଦି (a[i] < 32) {
            // value in floating-point registers
            ଯଦି ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                ଯଦି (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    ପାଇଁ (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } ଅନ୍ୟଥା {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            ଅନ୍ୟଥା
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    ଯଦି ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        ଯଦି (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        ଅନ୍ୟଥା
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    ଯଦି (ଗଦା & 0xfff)
        o(0x910003ff | (ଗଦା & 0xfff) << 10); // add sp,sp,#(n)
    ଯଦି (ଗଦା >> 12)
        o(0x914003ff | (ଗଦା >> 12) << 10);

    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt = return_type->t;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt = rt & VT_BTYPE;
        ଯଦି (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            ଯଦି (a[0] == 0) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା align, size = type_size(return_type, &align);
                ପ୍ରତିଜ୍ଞା(size <= 16);
                ଯଦି (size > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                ଅନ୍ୟଥା ଯଦି (size)
                    arm64_strx(size > 4 ? 3 : size > 2 ? 2 : size > 1, 0, 8, 0);

            }
            ଅନ୍ୟଥା ଯଦି (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                ପାଇଁ (j = 0; j < n; j++)
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

ସ୍ଥିର unsigned long arm64_func_va_list_ଗଦା;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_func_va_list_gr_offs;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_func_va_list_vr_offs;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_func_sub_sp_offset;

ସ୍ଥିର unsigned arm64_func_start_offset;
#define ARM64_FUNC_ଗଦା_SETUP_SLOTS 6

#ifdef TCC_TARGET_PE
ସ୍ଥିର unsigned long arm64_pe_param_off(unsigned long a)
{
    ଫେରନ୍ତୁ a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#endif

ST_FUNC ଶୂନ୍ୟ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0;
    Sym *sym;
    CType **t;
    unsigned long *a;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା use_x8 = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_int = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_float = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା var_nb_arg = variadic ? n_func_args(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    ପାଇଁ (sym = func_type->ref; sym; sym = sym->next)
        ++n;

#ifdef TCC_TARGET_PE
    n += variadic;
#endif

    t = tcc_malloc(n * ଆକାର(*t));
    a = tcc_malloc(n * ଆକାର(*a));
    ପାଇଁ (sym = func_type->ref; sym; sym = sym->next)
        t[i++] = &sym->type;

#ifdef TCC_TARGET_PE
    ଯଦି (variadic)
        t[i] = &int_type;
#endif

    arm64_func_va_list_ଗଦା = arm64_pcs(var_nb_arg, n, t, a);

#ifdef TCC_TARGET_PE
    ଯଦି (variadic)
        arm64_func_va_list_ଗଦା = arm64_pe_param_off(a[n - 1]);
#endif

#ଯଦି !defined(TCC_TARGET_MACHO)
    ଯଦି (variadic) {
        use_x8 = 1;
        last_int = 4;
        last_float = 4;
    }
#endif

    ଯଦି (a && a[0] == 1)
        use_x8 = 1;
    ପାଇଁ (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        ଯଦି (a[i] < 16) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା last, align, size = type_size(&sym->type, &align);
	    last = a[i] / 4 + 1 + (size - 1) / 8;
	    last_int = last > last_int ? last : last_int;
	}
        ଅନ୍ୟଥା ଯଦି (a[i] < 32) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା last, hfa = arm64_hfa(&sym->type, 0);
	    last = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    last_float = last > last_float ? last : last_float;
	}
    }

    last_int = last_int > 4 ? 4 : last_int;
    last_float = last_float > 4 ? 4 : last_float;

    arm64_func_start_offset = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    ପାଇଁ (i = 0; i < last_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    ଯଦି (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    ପାଇଁ (i = 0; i < last_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    ପାଇଁ (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_set_param(sym, off, a[i] & 1);

        ଯଦି (a[i] < 16) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା align, size = type_size(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && size > 8)) * 8;
        }
        ଅନ୍ୟଥା ଯଦି (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        ଯଦି (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            ଯଦି (k > 0 && sz < 16)
                ପାଇଁ (j = 0; j < k; j++) {
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
    ପାଇଁ (i = 0; i < ARM64_FUNC_ଗଦା_SETUP_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#ifdef CONFIG_TCC_BCHECK
    ଯଦି (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

ST_FUNC ଶୂନ୍ୟ gen_va_start(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#ifdef TCC_TARGET_PE
    ଯଦି (arm64_func_va_list_ଗଦା) {
        arm64_movimm(30, arm64_func_va_list_ଗଦା);
        o(0x8b1e03be); // add x30,x29,x30
    } ଅନ୍ୟଥା
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#ଅନ୍ୟଥା
    ଯଦି (arm64_func_va_list_ଗଦା) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_ଗଦା + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    ଅନ୍ୟଥା
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#ଯଦି !defined(TCC_TARGET_MACHO)
    ଯଦି (arm64_func_va_list_gr_offs) {
        ଯଦି (arm64_func_va_list_ଗଦା)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    ଯଦି (arm64_func_va_list_vr_offs) {
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

ST_FUNC ଶୂନ୍ୟ gen_va_arg(CType *t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା align, size = type_size(t, &align);
    uint32_t r0, r1;

#ifdef TCC_TARGET_PE
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା indirect = 0, slot = (size + 7) & -8;

    ଯଦି (size > 16)
        indirect = 1, slot = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    ଯଦି (slot) {
        ଯଦି (slot == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        ଯଦି (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | slot << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    ଯଦି (indirect)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#ଅନ୍ୟଥା /* !PE */
    unsigned fsize = size, hfa = 1;

    ଯଦି (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    ଯଦି (!hfa) {
        uint32_t n = size > 16 ? 8 : (size + 7) & -8;

#ଯଦି !defined(TCC_TARGET_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        ଯଦି (align == 16) {
            ପ୍ରତିଜ୍ଞା(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#endif

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ଯଦି (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#ଯଦି !defined(TCC_TARGET_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#endif

        ଯଦି (size > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    ଅନ୍ୟଥା {
        uint32_t ssz = (size + 7) & -(uint32_t)8;
#ଯଦି !defined(TCC_TARGET_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#endif
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ଯଦି (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#ଯଦି !defined(TCC_TARGET_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_text_section->data + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        ଯଦି (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        ଅନ୍ୟଥା {
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

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gfunc_sret(CType *vt, ପୂର୍ଣ୍ଣସଂଖ୍ୟା variadic, CType *ret,
                       ପୂର୍ଣ୍ଣସଂଖ୍ୟା *align, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *regsize)
{
    ଫେରନ୍ତୁ 0;
}

ST_FUNC ଶୂନ୍ୟ gfunc_return(CType *func_type)
{
    CType *t = func_type;
    unsigned long a;

    arm64_pcs(0, 1, &t, &a);

    ବାଛ (a) {
    ସ୍ଥିତି -1:
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 0:
        ଯଦି ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା align, size = type_size(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, size);
        }
        ଅନ୍ୟଥା
            gv(RC_IRET);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 1: {
        CType type = *func_type;
        mk_pointer(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        ଭାଙ୍ଗ;
    }
    ସ୍ଥିତି 16:
        ଯଦି ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          ପାଇଁ (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        ଅନ୍ୟଥା
            gv(RC_FRET);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
      ପ୍ରତିଜ୍ଞା(0);
    }
    vtop--;
}

ST_FUNC ଶୂନ୍ୟ gfunc_epilog(ଶୂନ୍ୟ)
{
#ifdef CONFIG_TCC_BCHECK
    ଯଦି (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    ଯଦି (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
        addr_t saved_ind = ind;
        addr_t patch_end = arm64_func_sub_sp_offset + ARM64_FUNC_ଗଦା_SETUP_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_offset;
        arm64_sub_sp(diff);
        ପାଇଁ (i = ind; i < patch_end; i += 4)
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

ST_FUNC ଶୂନ୍ୟ gen_fill_nops(ପୂର୍ଣ୍ଣସଂଖ୍ୟା bytes)
{
    ଯଦି ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    ଯେତେବେଳେ (bytes > 0) {
	o(ARM64_NOP); // nop
	bytes -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gjmp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r = ind;
    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ t;
    o(t);
    ଫେରନ୍ତୁ r;
}

// Generate branch to known address:
ST_FUNC ଶୂନ୍ୟ gjmp_addr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
    ପ୍ରତିଜ୍ଞା(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gjmp_append(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଶୂନ୍ୟ *p;
    /* insert vtop->c jump list in t */
    ଯଦି (n) {
        uint32_t n1 = n, n2;
        ଯେତେବେଳେ ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    ଫେରନ୍ତୁ t;
}

ଶୂନ୍ୟ arm64_vset_VT_CMP(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    ଯଦି (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_gen_opil(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, uint32_t l);

ସ୍ଥିର ଶୂନ୍ୟ arm64_load_cmp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, SValue *sv)
{
    sv->r = sv->cmp_r;
    ଯଦି (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    ଯଦି (r != sv->r) {
        load(r, sv);
        sv->r = r;
    }
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gjmp_cond(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt = vtop->type.t & VT_BTYPE;

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା inv = op & 1;
    vtop->r = vtop->cmp_r;

    ଯଦି (bt == VT_LDOUBLE) {
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
    ଅନ୍ୟଥା ଯଦି (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    ଅନ୍ୟଥା {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    ଫେରନ୍ତୁ gjmp(t);
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_iconst(uint64_t *val, SValue *sv)
{
    ଯଦି ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        ଫେରନ୍ତୁ 0;
    ଯଦି (val) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = sv->type.t;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    ଫେରନ୍ତୁ 1;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arm64_gen_opic(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, uint32_t l, ପୂର୍ଣ୍ଣସଂଖ୍ୟା rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    ଯଦି (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    ବାଛ (op) {

    ସ୍ଥିତି '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        ଯଦି (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        ଅନ୍ୟଥା ଯଦି (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        ଅନ୍ୟଥା {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        ଫେରନ୍ତୁ 1;
      }

    ସ୍ଥିତି '-':
        ଯଦି (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        ଅନ୍ୟଥା ଯଦି (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        ଅନ୍ୟଥା {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        ଫେରନ୍ତୁ 1;

    ସ୍ଥିତି '^':
        ଯଦି (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            ଫେରନ୍ତୁ 1;
        }
        // fall through
    ସ୍ଥିତି '&':
    ସ୍ଥିତି '|': {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା e = arm64_encode_bimm64(l ? val : val | val << 32);
        ଯଦି (e < 0)
            ଫେରନ୍ତୁ 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        ଫେରନ୍ତୁ 1;
    }

    ସ୍ଥିତି TOK_SAR:
    ସ୍ଥିତି TOK_SHL:
    ସ୍ଥିତି TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        ଯଦି (rev)
            ଫେରନ୍ତୁ 0;
        ଯଦି (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            ଫେରନ୍ତୁ 1;
        }
        ଅନ୍ୟଥା ଯଦି (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        ଅନ୍ୟଥା
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        ଫେରନ୍ତୁ 1;
    }

    }
    ଫେରନ୍ତୁ 0;
}

ସ୍ଥିର ଶୂନ୍ୟ arm64_gen_opil(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା rev = 1;

        ଯଦି (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        ଯଦି (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            ଯଦି (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                ଫେରନ୍ତୁ;
            }
        }
        ଯଦି (!rev)
            vswap();
    }

    gv2(RC_INT, RC_INT);
    ପ୍ରତିଜ୍ଞା(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = intr(vtop[-1].r);
    b = intr(vtop[0].r);
    vtop -= 2;
    x = get_reg(RC_INT);
    ++vtop;
    vtop[0].r = x;
    x = intr(x);

    ବାଛ (op) {
    ସ୍ଥିତି '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '/':
    ସ୍ଥିତି TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ପ୍ରତିଜ୍ଞା(0);
    }
}

ST_FUNC ଶୂନ୍ୟ gen_opi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC ଶୂନ୍ୟ gen_opl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC ଶୂନ୍ୟ gen_opf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    uint32_t x, a, b, dbl;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt = vtop[0].type.t & VT_BTYPE;

    ଯଦି (op == TOK_NEG) {
        ଯଦି (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } ଅନ୍ୟଥା {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        ଫେରନ୍ତୁ;
    }

    ଯଦି (bt == VT_LDOUBLE) {
        CType type = vtop[0].type;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା func = 0;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା cond = -1;
        ବାଛ (op) {
        ସ୍ଥିତି '*': func = TOK___multf3; ଭାଙ୍ଗ;
        ସ୍ଥିତି '+': func = TOK___addtf3; ଭାଙ୍ଗ;
        ସ୍ଥିତି '-': func = TOK___subtf3; ଭାଙ୍ଗ;
        ସ୍ଥିତି '/': func = TOK___divtf3; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_EQ: func = TOK___eqtf2; cond = 1; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_NE: func = TOK___netf2; cond = 0; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_LT: func = TOK___lttf2; cond = 10; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_GE: func = TOK___getf2; cond = 11; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_LE: func = TOK___letf2; cond = 12; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_GT: func = TOK___gttf2; cond = 13; ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ: ପ୍ରତିଜ୍ଞା(0); ଭାଙ୍ଗ;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        ଯଦି (cond < 0)
            vtop->type = type;
        ଅନ୍ୟଥା {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        ଫେରନ୍ତୁ;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    ପ୍ରତିଜ୍ଞା(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    ବାଛ (op) {
    ସ୍ଥିତି TOK_EQ: ସ୍ଥିତି TOK_NE:
    ସ୍ଥିତି TOK_LT: ସ୍ଥିତି TOK_GE: ସ୍ଥିତି TOK_LE: ସ୍ଥିତି TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        ଭାଙ୍ଗ;
    }

    ବାଛ (op) {
    ସ୍ଥିତି '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ପ୍ରତିଜ୍ଞା(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC ଶୂନ୍ୟ gen_cvt_sxtw(ଶୂନ୍ୟ)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC ଶୂନ୍ୟ gen_cvt_csti(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC ଶୂନ୍ୟ gen_cvt_itof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଯଦି (t == VT_LDOUBLE) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f = vtop->type.t;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        ଫେରନ୍ତୁ;
    }
    ଅନ୍ୟଥା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା d, n = intr(gv(RC_INT));
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା s = !(vtop->type.t & VT_UNSIGNED);
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

ST_FUNC ଶୂନ୍ୟ gen_cvt_ftoi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଯଦି ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        ଫେରନ୍ତୁ;
    }
    ଅନ୍ୟଥା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା d, n = fltr(gv(RC_FLOAT));
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

ST_FUNC ଶୂନ୍ୟ gen_cvt_ftof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା f = vtop[0].type.t & VT_BTYPE;
    ପ୍ରତିଜ୍ଞା(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    ପ୍ରତିଜ୍ଞା(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    ଯଦି (t == f)
        ଫେରନ୍ତୁ;

    ଯଦି (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    ଅନ୍ୟଥା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା x, a;
        gv(RC_FLOAT);
        ପ୍ରତିଜ୍ଞା(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        ଯଦି (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        ଅନ୍ୟଥା
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC ଶୂନ୍ୟ gen_increment_tcov (SValue *sv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r1, r2;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    arm64_sym(r1, sv->sym, 0);
    o(ARM64_LDR_X | ARM64_RN(intr(r1)) | intr(r2)); // ldr r2, [r1]
    o(0x91000400 | (intr(r2)<<5) | intr(r2)); // add r2, r2, #1
    o(0xf9000000 | (intr(r1)<<5) | intr(r2)); // str r2, [r1]
    vpop();
}

ST_FUNC ଶୂନ୍ୟ ggoto(ଶୂନ୍ୟ)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC ଶୂନ୍ୟ gen_clear_cache(ଶୂନ୍ୟ)
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

ST_FUNC ଶୂନ୍ୟ gen_vla_sp_save(ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC ଶୂନ୍ୟ gen_vla_sp_restore(ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC ଶୂନ୍ୟ gen_vla_alloc(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା align) {
    uint32_t r;
#ଯଦି defined(CONFIG_TCC_BCHECK)
    ଯଦି (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    r = intr(gv(RC_INT));
#ଯଦି defined(CONFIG_TCC_BCHECK)
    ଯଦି (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    ଅନ୍ୟଥା
#endif
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#ଯଦି defined(CONFIG_TCC_BCHECK)
    ଯଦି (tcc_state->do_bounds_check) {
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
