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

#ถ้า !defined(TCC_TARGET_MACHO) && !defined(TCC_TARGET_PE)
#define CHAR_IS_UNSIGNED
#endif

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#define PROMOTE_RET
/******************************************************/
#มิฉะนั้น /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#include "tcc.h"
#include <assert.h>

ST_DATA const var_na * const target_machine_defs =
    "__aarch64__\0"
#ถ้า defined(TCC_TARGET_MACHO)
    "__arm64__\0"
#endif
    "__AARCH64EL__\0"
    ;

ST_DATA const จำนวนเต็ม reg_classes[NB_REGS] = {
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

#ถ้า defined(CONFIG_TCC_BCHECK)
static addr_t func_bound_offset;
static unsigned long func_bound_ind;
ST_DATA จำนวนเต็ม func_bound_add_epilog;
#endif

#define IS_FREG(x) ((x) >= TREG_F(0))

static uint32_t intr(จำนวนเต็ม r)
{
    assert(TREG_R(0) <= r && r <= TREG_R30);
    คืน r < TREG_R30 ? r : 30;
}

static uint32_t fltr(จำนวนเต็ม r)
{
    assert(TREG_F(0) <= r && r <= TREG_F(7));
    คืน r - TREG_F(0);
}

// Add an instruction to text section:
ST_FUNC void o(unsigned จำนวนเต็ม c)
{
    จำนวนเต็ม ind1 = ind + 4;
    ถ้า (nocode_wanted)
        คืน;
    ถ้า (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    write32le(cur_text_section->data + ind, c);
    ind = ind1;
}

static จำนวนเต็ม arm64_encode_bimm64(uint64_t x)
{
    จำนวนเต็ม neg = x & 1;
    จำนวนเต็ม rep, pos, len;

    ถ้า (neg)
        x = ~x;
    ถ้า (!x)
        คืน -1;

    ถ้า (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    มิฉะนั้น ถ้า (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    มิฉะนั้น ถ้า (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    มิฉะนั้น ถ้า (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    มิฉะนั้น ถ้า (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    มิฉะนั้น
        rep = 64;

    pos = 0;
    ถ้า (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    ถ้า (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    ถ้า (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    ถ้า (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    ถ้า (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    ถ้า (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    ถ้า (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    ถ้า (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    ถ้า (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    ถ้า (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    ถ้า (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    ถ้า (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    ถ้า (x)
        คืน -1;
    ถ้า (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    คืน ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

static uint32_t arm64_movi(จำนวนเต็ม r, uint64_t x)
{
    uint64_t m = 0xffff;
    จำนวนเต็ม e;
    ถ้า (!(x & ~m))
        คืน ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    ถ้า (!(x & ~(m << 16)))
        คืน (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    ถ้า (!(x & ~(m << 32)))
        คืน (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    ถ้า (!(x & ~(m << 48)))
        คืน (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    ถ้า ((x & ~m) == m << 16)
        คืน (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    ถ้า ((x & ~(m << 16)) == m)
        คืน (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    ถ้า (!~(x | m))
        คืน (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    ถ้า (!~(x | m << 16))
        คืน (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    ถ้า (!~(x | m << 32))
        คืน (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ถ้า (!~(x | m << 48))
        คืน (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ถ้า (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        คืน (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    ถ้า ((e = arm64_encode_bimm64(x)) >= 0)
        คืน (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    คืน 0;
}

static void arm64_movimm(จำนวนเต็ม r, uint64_t x)
{
    uint32_t i;
    ถ้า ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    มิฉะนั้น {
        // MOVZ/MOVN and 1-3 MOVKs
        จำนวนเต็ม z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        สำหรับ (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        ถ้า (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        สำหรับ (i = 0; i < 64; i += 16)
            ถ้า (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                bha_nga;
            }
        สำหรับ (i += 16; i < 64; i += 16)
            ถ้า (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC void gsym_addr(จำนวนเต็ม t_, จำนวนเต็ม a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    ขณะ (t) {
        unsigned var_na *ptr = cur_text_section->data + t;
        uint32_t next = read32le(ptr);
        ถ้า (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = next;
    }
}

static จำนวนเต็ม arm64_type_size(จำนวนเต็ม t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    switch (t & VT_BTYPE) {
    pak_sa VT_BYTE: คืน 0;
    pak_sa VT_SHORT: คืน 1;
    pak_sa VT_INT: คืน 2;
    pak_sa VT_LLONG: คืน 3;
    pak_sa VT_PTR: คืน 3;
    pak_sa VT_FUNC: คืน 3;
    pak_sa VT_STRUCT: คืน 3;
    pak_sa VT_FLOAT: คืน 2;
    pak_sa VT_DOUBLE: คืน 3;
    pak_sa VT_LDOUBLE: คืน 4;
    pak_sa VT_BOOL: คืน 0;
    }
    assert(0);
    คืน 0;
}

static void arm64_spoff(จำนวนเต็ม reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    ถ้า (sub)
        off = -off;
    ถ้า (off < 4096)
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    มิฉะนั้น {
        arm64_movimm(30, off);
        o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

static uint64_t arm64_check_offset(จำนวนเต็ม sz_, uint64_t off)
{
#ifndef TCC_TARGET_PE
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    ถ้า (!(off & ~scaled_mask) || (off < 256 || -off <= 256))
        คืน ~0ull;
    ถ้า (off & scaled_mask)
        คืน scaled_mask;
    ถ้า (off & 0x1fful)
        คืน 0x1fful;
#endif
    คืน 0;
}

static void arm64_ldrx(จำนวนเต็ม sg, จำนวนเต็ม sz_, จำนวนเต็ม dst, จำนวนเต็ม bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    ถ้า (sz >= 2)
        sg = 0;
    ถ้า (!(off & ~scaled_mask))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    มิฉะนั้น ถ้า (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    มิฉะนั้น {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

static void arm64_ldrv(จำนวนเต็ม sz_, จำนวนเต็ม dst, จำนวนเต็ม bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    ถ้า (!(off & ~scaled_mask))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    มิฉะนั้น ถ้า (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    มิฉะนั้น {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

static void arm64_ldrs(จำนวนเต็ม reg_, จำนวนเต็ม size)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    switch (size) {
    default: assert(0); bha_nga;
    pak_sa 0:
        /* Can happen with zero size structs */
        bha_nga;
    pak_sa 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        bha_nga;
    pak_sa 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        bha_nga;
    pak_sa 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        bha_nga;
    pak_sa 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        bha_nga;
    pak_sa 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        bha_nga;
    pak_sa 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        bha_nga;
    pak_sa 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        bha_nga;
    pak_sa 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        bha_nga;
    pak_sa 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        bha_nga;
    pak_sa 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        bha_nga;
    pak_sa 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        bha_nga;
    pak_sa 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        bha_nga;
    pak_sa 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        bha_nga;
    pak_sa 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        bha_nga;
    pak_sa 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        bha_nga;
    pak_sa 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        bha_nga;
    }
}

static void arm64_strx(จำนวนเต็ม sz_, จำนวนเต็ม dst, จำนวนเต็ม bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    ถ้า (!(off & ~scaled_mask))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    มิฉะนั้น ถ้า (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    มิฉะนั้น {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

static void arm64_strv(จำนวนเต็ม sz_, จำนวนเต็ม dst, จำนวนเต็ม bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    ถ้า (!(off & ~scaled_mask))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    มิฉะนั้น ถ้า (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    มิฉะนั้น {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

static void arm64_reloca(Sym *sym, จำนวนเต็ม reloc_type, uint64_t addend)
{
    greloca(cur_text_section, sym, ind, reloc_type, addend);
}

static void arm64_sym(จำนวนเต็ม r, Sym *sym, addr_t addend)
{
    ถ้า (sym->type.t & VT_TLS) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        จำนวนเต็ม r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#มิฉะนั้น
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#endif
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_HI12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_LO12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#ifndef TCC_TARGET_PE /* no elf-style GOT on Windows */
    } มิฉะนั้น ถ้า (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_PAGE, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        ถ้า (addend > 0xffffff) {
            จำนวนเต็ม t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } มิฉะนั้น {
           ถ้า (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_ADD_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            ถ้า (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#endif
    } มิฉะนั้น {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_ADD_ABS_LO12_NC, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

static void arm64_load_cmp(จำนวนเต็ม r, SValue *sv);

ST_FUNC void load(จำนวนเต็ม r, SValue *sv)
{
    จำนวนเต็ม svtt = sv->type.t;
    จำนวนเต็ม svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    จำนวนเต็ม svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    จำนวนเต็ม sb = !(svtt & VT_UNSIGNED);
    จำนวนเต็ม sz = arm64_type_size(svtt);

    ถ้า (svr == (VT_LOCAL | VT_LVAL)) {
        ถ้า (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        มิฉะนั้น
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        คืน;
    }

    ถ้า (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        ถ้า (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        มิฉะนั้น
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        คืน;
    }

    ถ้า (svrv < VT_CONST && (svr & VT_LVAL)) {
        ถ้า (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        มิฉะนั้น
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        คืน;
    }

    ถ้า (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        ถ้า (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & mask);
        มิฉะนั้น
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & mask);
        คืน;
    }

    ถ้า (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        คืน;
    }

    ถ้า (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        คืน;
    }

    ถ้า (svr < VT_CONST) {
        ถ้า (IS_FREG(r) && IS_FREG(svr))
            ถ้า (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            มิฉะนั้น
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        มิฉะนั้น ถ้า (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        มิฉะนั้น
            assert(0);
      คืน;
    }

    ถ้า (svr == VT_LOCAL) {
        ถ้า (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        มิฉะนั้น {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        คืน;
    }

    ถ้า (svr == VT_JMP || svr == VT_JMPI) {
        จำนวนเต็ม t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        คืน;
    }

    ถ้า (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        ถ้า (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        มิฉะนั้น
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        คืน;
    }

    ถ้า (svr == VT_CMP) {
        arm64_load_cmp(r, sv);
        คืน;
    }

    printf("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (long)svcul);
    assert(0);
}

ST_FUNC void store(จำนวนเต็ม r, SValue *sv)
{
    จำนวนเต็ม svtt = sv->type.t;
    จำนวนเต็ม svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    จำนวนเต็ม svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    จำนวนเต็ม sz = arm64_type_size(svtt);

    ถ้า (svr == (VT_LOCAL | VT_LVAL)) {
        ถ้า (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        มิฉะนั้น
            arm64_strx(sz, intr(r), 29, svcoff);
        คืน;
    }

    ถ้า (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        ถ้า (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        มิฉะนั้น
            arm64_strx(sz, intr(r), 30, 0);
        คืน;
    }

    ถ้า (svrv < VT_CONST && (svr & VT_LVAL)) {
        ถ้า (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        มิฉะนั้น
            arm64_strx(sz, intr(r), intr(svrv), 0);
        คืน;
    }

    ถ้า (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        ถ้า (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & mask);
        มิฉะนั้น
            arm64_strx(sz, intr(r), 30, svcoff & mask);
        คืน;
    }

    printf("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (long)svcoff);
    assert(0);
}

static void arm64_gen_bl_or_b(จำนวนเต็ม b)
{
    ถ้า ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    มิฉะนั้น {
#ifdef CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#endif
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#ถ้า defined CONFIG_TCC_BCHECK || defined TCC_TARGET_PE
static void gen_static_call(จำนวนเต็ม v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#endif

#ถ้า defined(CONFIG_TCC_BCHECK)
static void gen_bounds_prolog(void)
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

static void gen_bounds_epilog(void)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    จำนวนเต็ม offset_modified = func_bound_offset != lbounds_section->data_offset;

    ถ้า (!offset_modified && !func_bound_add_epilog)
        คืน;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, parimaa_na(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    ถ้า (offset_modified) {
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

static จำนวนเต็ม arm64_hfa_aux(CType *type, จำนวนเต็ม *fsize, จำนวนเต็ม num)
{
    ถ้า (is_float(type->t)) {
        จำนวนเต็ม a, n = type_size(type, &a);
        ถ้า (num >= 4 || (*fsize && *fsize != n))
            คืน -1;
        *fsize = n;
        คืน num + 1;
    }
    มิฉะนั้น ถ้า ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field;
        ถ้า (!IS_UNION(type->t)) {
            จำนวนเต็ม num0 = num;
            สำหรับ (field = type->ref->next; field; field = field->next) {
                ถ้า (field->c != (num - num0) * *fsize)
                    คืน -1;
                num = arm64_hfa_aux(&field->type, fsize, num);
                ถ้า (num == -1)
                    คืน -1;
            }
            ถ้า (type->ref->c != (num - num0) * *fsize)
                คืน -1;
            คืน num;
        }
        มิฉะนั้น { // union
            จำนวนเต็ม num0 = num;
            สำหรับ (field = type->ref->next; field; field = field->next) {
                จำนวนเต็ม num1 = arm64_hfa_aux(&field->type, fsize, num0);
                ถ้า (num1 == -1)
                    คืน -1;
                num = num1 < num ? num : num1;
            }
            ถ้า (type->ref->c != (num - num0) * *fsize)
                คืน -1;
            คืน num;
        }
    }
    มิฉะนั้น ถ้า (type->t & VT_ARRAY) { /* handle float array within struct */
        จำนวนเต็ม num1;
        ถ้า (!type->ref->c)
            คืน num;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, num);
        ถ้า (num1 == -1 || (num1 != num && type->ref->c > 4))
            คืน -1;
        num1 = num + type->ref->c * (num1 - num);
        ถ้า (num1 > 4)
            คืน -1;
        คืน num1;
    }
    คืน -1;
}

static จำนวนเต็ม arm64_hfa(CType *type, unsigned *fsize)
{
    ถ้า ((type->t & VT_BTYPE) == VT_STRUCT) {
        จำนวนเต็ม sz = 0;
        จำนวนเต็ม n = arm64_hfa_aux(type, &sz, 0);
        ถ้า (0 < n && n <= 4) {
            ถ้า (fsize)
                *fsize = sz;
            คืน n;
        }
    }
    คืน 0;
}

static unsigned long arm64_pcs_aux(จำนวนเต็ม variadic, จำนวนเต็ม n, CType **type, unsigned long *a)
{
    จำนวนเต็ม nx = 0; // next integer register
    จำนวนเต็ม nv = 0; // next vector register
    unsigned long ns = 32; // next stack offset
    จำนวนเต็ม i;

    สำหรับ (i = 0; i < n; i++) {
        จำนวนเต็ม hfa = arm64_hfa(type[i], 0);
        จำนวนเต็ม size, align, bt;

        bt = type[i]->t & VT_BTYPE;
        ถ้า (bt == VT_PTR || bt == VT_FUNC)
            size = align = 8;
        มิฉะนั้น
            size = type_size(type[i], &align);

#ถ้า defined(TCC_TARGET_MACHO)
        ถ้า (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#elif defined(TCC_TARGET_PE)
        ถ้า (variadic && i >= variadic) {
            hfa = 0;
            ถ้า (is_float(bt))
                bt = VT_INT, size = align = 8;
        }
#endif
        ถ้า (hfa)
            // B.2
            ;
        มิฉะนั้น ถ้า (size > 16) {
            // B.3: replace with pointer
            ถ้า (nx < 8)
                a[i] = nx++ << 1 | 1;
            มิฉะนั้น {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            continue;
        }
        มิฉะนั้น ถ้า (bt == VT_STRUCT)
            // B.4
            size = (size + 7) & ~7;

        // C.1
        ถ้า (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            continue;
        }

        // C.2
        ถ้า (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            continue;
        }

        // C.3
        ถ้า (hfa) {
            nv = 8;
            size = (size + 7) & ~7;
        }

        // C.4
        ถ้า (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        ถ้า (bt == VT_FLOAT)
            size = 8;

        // C.6
        ถ้า (hfa || is_float(bt)) {
            a[i] = ns;
            ns += size;
            continue;
        }

        // C.7
        ถ้า (bt != VT_STRUCT && size <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            continue;
        }

        // C.8
        ถ้า (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        ถ้า (bt != VT_STRUCT && size == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            continue;
        }

        // C.10
        ถ้า (bt == VT_STRUCT && size <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (size + 7) >> 3;
            continue;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        ถ้า (bt == VT_STRUCT) {
            a[i] = ns;
            ns += size;
            continue;
        }

        // C.14
        ถ้า (size < 8)
            size = 8;

        // C.15
        a[i] = ns;
        ns += size;
    }

    คืน ns - 32;
}

static unsigned long arm64_pcs(จำนวนเต็ม variadic, จำนวนเต็ม n, CType **type, unsigned long *a)
{
    unsigned long stack;

    // Return type:
    ถ้า ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    มิฉะนั้น {
        arm64_pcs_aux(0, 1, type, a);
        assert(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    stack = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    ถ้า (0) {
        จำนวนเต็ม i;
        สำหรับ (i = 0; i < n; i++) {
            ถ้า (!i)
                printf("arm64_pcs return: ");
            มิฉะนั้น
                printf("arm64_pcs arg %d: ", i);
            ถ้า (a[i] == (unsigned long)-1)
                printf("void\n");
            มิฉะนั้น ถ้า (a[i] == 1 && !i)
                printf("X8 pointer\n");
            มิฉะนั้น ถ้า (a[i] < 16)
                printf("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            มิฉะนั้น ถ้า (a[i] < 32)
                printf("V%lu\n", a[i] / 2 - 8);
            มิฉะนั้น
                printf("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    คืน stack;
}

static จำนวนเต็ม n_func_args(CType *type)
{
    จำนวนเต็ม n_args = 0;
    Sym *arg;

    สำหรับ (arg = type->ref->next; arg; arg = arg->next)
        n_args++;
    คืน n_args;
}

static void arm64_sub_sp(uint64_t diff)
{
    ถ้า (!diff)
        คืน;
#ifdef TCC_TARGET_PE
    ถ้า (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        คืน;
    }
#endif
    ถ้า (!(diff >> 24)) {
        ถ้า (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        ถ้า (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } มิฉะนั้น {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

static จำนวนเต็ม gv_addr(จำนวนเต็ม r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    คืน gv(r);
}

ST_FUNC void gfunc_call(จำนวนเต็ม nb_args)
{
    CType *return_type;
    CType **t;
    unsigned long *a, *a1;
    unsigned long stack;
    จำนวนเต็ม i;
    จำนวนเต็ม func_type = vtop[-nb_args].type.ref->f.func_type;
    จำนวนเต็ม variadic = (func_type == FUNC_ELLIPSIS);
    จำนวนเต็ม old_style = (func_type == FUNC_OLD);
    จำนวนเต็ม var_nb_arg = variadic ? n_func_args(&vtop[-nb_args].type) : 0;

    save_regs(nb_args + 1);

#ifdef CONFIG_TCC_BCHECK
    ถ้า (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    return_type = &vtop[-nb_args].type.ref->type;
    ถ้า ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_args;

    t = tcc_malloc((nb_args + 1) * parimaa_na(*t));
    a = tcc_malloc((nb_args + 1) * parimaa_na(*a));
    a1 = tcc_malloc((nb_args + 1) * parimaa_na(*a1));

    t[0] = return_type;
    สำหรับ (i = 0; i < nb_args; i++)
        t[nb_args - i] = &vtop[-i].type;

    stack = arm64_pcs(
#ifdef TCC_TARGET_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#endif
        var_nb_arg, nb_args + 1, t, a);

    // Allocate space for structs replaced by pointer:
    สำหรับ (i = nb_args; i; i--)
        ถ้า (a[i] & 1) {
            SValue *arg = &vtop[i - nb_args];
            จำนวนเต็ม align, size = type_size(&arg->type, &align);
            assert((arg->type.t & VT_BTYPE) == VT_STRUCT);
            stack = (stack + align - 1) & -align;
            a1[i] = stack;
            stack += size;
        }

    stack = (stack + 15) >> 4 << 4;

    ถ้า (stack >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", stack);
    arm64_sub_sp(stack);

    // First pass: set all values on stack
    สำหรับ (i = nb_args; i; i--) {
        vpushv(vtop - nb_args + i);

        ถ้า (a[i] & 1) {
            // struct replaced by pointer
            จำนวนเต็ม r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            ถ้า (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        มิฉะนั้น ถ้า (a[i] >= 32) {
            // value on stack
            ถ้า ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                จำนวนเต็ม r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            มิฉะนั้น ถ้า (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_size(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            มิฉะนั้น {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    สำหรับ (i = nb_args; i; i--, vtop--) {
        ถ้า (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            ถ้า ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                ถ้า ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                มิฉะนั้น
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            มิฉะนั้น ถ้า ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                จำนวนเต็ม align, size = type_size(&vtop->type, &align);
                ถ้า (size) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, size);
                }
            }
            มิฉะนั้น
                gv(RC_R(a[i] / 2));
        }
        มิฉะนั้น ถ้า (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        มิฉะนั้น ถ้า (a[i] < 32) {
            // value in floating-point registers
            ถ้า ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                ถ้า (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    สำหรับ (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } มิฉะนั้น {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            มิฉะนั้น
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    ถ้า ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        ถ้า (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        มิฉะนั้น
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    ถ้า (stack & 0xfff)
        o(0x910003ff | (stack & 0xfff) << 10); // add sp,sp,#(n)
    ถ้า (stack >> 12)
        o(0x914003ff | (stack >> 12) << 10);

    {
        จำนวนเต็ม rt = return_type->t;
        จำนวนเต็ม bt = rt & VT_BTYPE;
        ถ้า (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            ถ้า (a[0] == 0) {
                จำนวนเต็ม align, size = type_size(return_type, &align);
                assert(size <= 16);
                ถ้า (size > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                มิฉะนั้น ถ้า (size)
                    arm64_strx(size > 4 ? 3 : size > 2 ? 2 : size > 1, 0, 8, 0);

            }
            มิฉะนั้น ถ้า (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                สำหรับ (j = 0; j < n; j++)
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

static unsigned long arm64_func_va_list_stack;
static จำนวนเต็ม arm64_func_va_list_gr_offs;
static จำนวนเต็ม arm64_func_va_list_vr_offs;
static จำนวนเต็ม arm64_func_sub_sp_offset;

static unsigned arm64_func_start_offset;
#define ARM64_FUNC_STACK_SETUP_SLOTS 6

#ifdef TCC_TARGET_PE
static unsigned long arm64_pe_param_off(unsigned long a)
{
    คืน a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#endif

ST_FUNC void gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    จำนวนเต็ม n = 0;
    จำนวนเต็ม i = 0;
    Sym *sym;
    CType **t;
    unsigned long *a;
    จำนวนเต็ม use_x8 = 0;
    จำนวนเต็ม last_int = 0;
    จำนวนเต็ม last_float = 0;
    จำนวนเต็ม variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    จำนวนเต็ม var_nb_arg = variadic ? n_func_args(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    สำหรับ (sym = func_type->ref; sym; sym = sym->next)
        ++n;

#ifdef TCC_TARGET_PE
    n += variadic;
#endif

    t = tcc_malloc(n * parimaa_na(*t));
    a = tcc_malloc(n * parimaa_na(*a));
    สำหรับ (sym = func_type->ref; sym; sym = sym->next)
        t[i++] = &sym->type;

#ifdef TCC_TARGET_PE
    ถ้า (variadic)
        t[i] = &int_type;
#endif

    arm64_func_va_list_stack = arm64_pcs(var_nb_arg, n, t, a);

#ifdef TCC_TARGET_PE
    ถ้า (variadic)
        arm64_func_va_list_stack = arm64_pe_param_off(a[n - 1]);
#endif

#ถ้า !defined(TCC_TARGET_MACHO)
    ถ้า (variadic) {
        use_x8 = 1;
        last_int = 4;
        last_float = 4;
    }
#endif

    ถ้า (a && a[0] == 1)
        use_x8 = 1;
    สำหรับ (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        ถ้า (a[i] < 16) {
            จำนวนเต็ม last, align, size = type_size(&sym->type, &align);
	    last = a[i] / 4 + 1 + (size - 1) / 8;
	    last_int = last > last_int ? last : last_int;
	}
        มิฉะนั้น ถ้า (a[i] < 32) {
            จำนวนเต็ม last, hfa = arm64_hfa(&sym->type, 0);
	    last = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    last_float = last > last_float ? last : last_float;
	}
    }

    last_int = last_int > 4 ? 4 : last_int;
    last_float = last_float > 4 ? 4 : last_float;

    arm64_func_start_offset = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    สำหรับ (i = 0; i < last_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    ถ้า (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    สำหรับ (i = 0; i < last_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    สำหรับ (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        จำนวนเต็ม off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_set_param(sym, off, a[i] & 1);

        ถ้า (a[i] < 16) {
            จำนวนเต็ม align, size = type_size(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && size > 8)) * 8;
        }
        มิฉะนั้น ถ้า (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        ถ้า (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            ถ้า (k > 0 && sz < 16)
                สำหรับ (j = 0; j < k; j++) {
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
    สำหรับ (i = 0; i < ARM64_FUNC_STACK_SETUP_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#ifdef CONFIG_TCC_BCHECK
    ถ้า (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

ST_FUNC void gen_va_start(void)
{
    จำนวนเต็ม r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#ifdef TCC_TARGET_PE
    ถ้า (arm64_func_va_list_stack) {
        arm64_movimm(30, arm64_func_va_list_stack);
        o(0x8b1e03be); // add x30,x29,x30
    } มิฉะนั้น
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#มิฉะนั้น
    ถ้า (arm64_func_va_list_stack) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_stack + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    มิฉะนั้น
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#ถ้า !defined(TCC_TARGET_MACHO)
    ถ้า (arm64_func_va_list_gr_offs) {
        ถ้า (arm64_func_va_list_stack)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    ถ้า (arm64_func_va_list_vr_offs) {
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

ST_FUNC void gen_va_arg(CType *t)
{
    จำนวนเต็ม align, size = type_size(t, &align);
    uint32_t r0, r1;

#ifdef TCC_TARGET_PE
    จำนวนเต็ม indirect = 0, slot = (size + 7) & -8;

    ถ้า (size > 16)
        indirect = 1, slot = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    ถ้า (slot) {
        ถ้า (slot == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        ถ้า (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | slot << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    ถ้า (indirect)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#มิฉะนั้น /* !PE */
    unsigned fsize = size, hfa = 1;

    ถ้า (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    ถ้า (!hfa) {
        uint32_t n = size > 16 ? 8 : (size + 7) & -8;

#ถ้า !defined(TCC_TARGET_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        ถ้า (align == 16) {
            assert(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#endif

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ถ้า (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#ถ้า !defined(TCC_TARGET_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#endif

        ถ้า (size > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    มิฉะนั้น {
        uint32_t ssz = (size + 7) & -(uint32_t)8;
#ถ้า !defined(TCC_TARGET_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#endif
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ถ้า (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#ถ้า !defined(TCC_TARGET_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_text_section->data + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        ถ้า (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        มิฉะนั้น {
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

ST_FUNC จำนวนเต็ม gfunc_sret(CType *vt, จำนวนเต็ม variadic, CType *ret,
                       จำนวนเต็ม *align, จำนวนเต็ม *regsize)
{
    คืน 0;
}

ST_FUNC void gfunc_return(CType *func_type)
{
    CType *t = func_type;
    unsigned long a;

    arm64_pcs(0, 1, &t, &a);

    switch (a) {
    pak_sa -1:
        bha_nga;
    pak_sa 0:
        ถ้า ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            จำนวนเต็ม align, size = type_size(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, size);
        }
        มิฉะนั้น
            gv(RC_IRET);
        bha_nga;
    pak_sa 1: {
        CType type = *func_type;
        mk_pointer(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        bha_nga;
    }
    pak_sa 16:
        ถ้า ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          สำหรับ (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        มิฉะนั้น
            gv(RC_FRET);
        bha_nga;
    default:
      assert(0);
    }
    vtop--;
}

ST_FUNC void gfunc_epilog(void)
{
#ifdef CONFIG_TCC_BCHECK
    ถ้า (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    ถ้า (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        จำนวนเต็ม i;
        addr_t saved_ind = ind;
        addr_t patch_end = arm64_func_sub_sp_offset + ARM64_FUNC_STACK_SETUP_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_offset;
        arm64_sub_sp(diff);
        สำหรับ (i = ind; i < patch_end; i += 4)
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

ST_FUNC void gen_fill_nops(จำนวนเต็ม bytes)
{
    ถ้า ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    ขณะ (bytes > 0) {
	o(ARM64_NOP); // nop
	bytes -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC จำนวนเต็ม gjmp(จำนวนเต็ม t)
{
    จำนวนเต็ม r = ind;
    ถ้า (nocode_wanted)
        คืน t;
    o(t);
    คืน r;
}

// Generate branch to known address:
ST_FUNC void gjmp_addr(จำนวนเต็ม a)
{
    assert(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC จำนวนเต็ม gjmp_append(จำนวนเต็ม n, จำนวนเต็ม t)
{
    void *p;
    /* insert vtop->c jump list in t */
    ถ้า (n) {
        uint32_t n1 = n, n2;
        ขณะ ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    คืน t;
}

void arm64_vset_VT_CMP(จำนวนเต็ม op)
{
    ถ้า (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

static void arm64_gen_opil(จำนวนเต็ม op, uint32_t l);

static void arm64_load_cmp(จำนวนเต็ม r, SValue *sv)
{
    sv->r = sv->cmp_r;
    ถ้า (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    ถ้า (r != sv->r) {
        load(r, sv);
        sv->r = r;
    }
}

ST_FUNC จำนวนเต็ม gjmp_cond(จำนวนเต็ม op, จำนวนเต็ม t)
{
    จำนวนเต็ม bt = vtop->type.t & VT_BTYPE;

    จำนวนเต็ม inv = op & 1;
    vtop->r = vtop->cmp_r;

    ถ้า (bt == VT_LDOUBLE) {
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
    มิฉะนั้น ถ้า (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    มิฉะนั้น {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    คืน gjmp(t);
}

static จำนวนเต็ม arm64_iconst(uint64_t *val, SValue *sv)
{
    ถ้า ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        คืน 0;
    ถ้า (val) {
        จำนวนเต็ม t = sv->type.t;
	จำนวนเต็ม bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    คืน 1;
}

static จำนวนเต็ม arm64_gen_opic(จำนวนเต็ม op, uint32_t l, จำนวนเต็ม rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    ถ้า (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    switch (op) {

    pak_sa '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        ถ้า (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        มิฉะนั้น ถ้า (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        มิฉะนั้น {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        คืน 1;
      }

    pak_sa '-':
        ถ้า (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        มิฉะนั้น ถ้า (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        มิฉะนั้น {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        คืน 1;

    pak_sa '^':
        ถ้า (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            คืน 1;
        }
        // fall through
    pak_sa '&':
    pak_sa '|': {
        จำนวนเต็ม e = arm64_encode_bimm64(l ? val : val | val << 32);
        ถ้า (e < 0)
            คืน 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        คืน 1;
    }

    pak_sa TOK_SAR:
    pak_sa TOK_SHL:
    pak_sa TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        ถ้า (rev)
            คืน 0;
        ถ้า (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            คืน 1;
        }
        มิฉะนั้น ถ้า (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        มิฉะนั้น
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        คืน 1;
    }

    }
    คืน 0;
}

static void arm64_gen_opil(จำนวนเต็ม op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        จำนวนเต็ม rev = 1;

        ถ้า (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        ถ้า (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            ถ้า (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                คืน;
            }
        }
        ถ้า (!rev)
            vswap();
    }

    gv2(RC_INT, RC_INT);
    assert(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = intr(vtop[-1].r);
    b = intr(vtop[0].r);
    vtop -= 2;
    x = get_reg(RC_INT);
    ++vtop;
    vtop[0].r = x;
    x = intr(x);

    switch (op) {
    pak_sa '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        bha_nga;
    pak_sa '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        bha_nga;
    pak_sa '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        bha_nga;
    pak_sa '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        bha_nga;
    pak_sa '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        bha_nga;
    pak_sa '/':
    pak_sa TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        bha_nga;
    pak_sa '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        bha_nga;
    pak_sa '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        bha_nga;
    pak_sa TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        bha_nga;
    pak_sa TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        bha_nga;
    pak_sa TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        bha_nga;
    pak_sa TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        bha_nga;
    pak_sa TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        bha_nga;
    pak_sa TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        bha_nga;
    pak_sa TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        bha_nga;
    pak_sa TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        bha_nga;
    pak_sa TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        bha_nga;
    pak_sa TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        bha_nga;
    pak_sa TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        bha_nga;
    pak_sa TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        bha_nga;
    pak_sa TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        bha_nga;
    pak_sa TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        bha_nga;
    pak_sa TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        bha_nga;
    default:
        assert(0);
    }
}

ST_FUNC void gen_opi(จำนวนเต็ม op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC void gen_opl(จำนวนเต็ม op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC void gen_opf(จำนวนเต็ม op)
{
    uint32_t x, a, b, dbl;
    จำนวนเต็ม bt = vtop[0].type.t & VT_BTYPE;

    ถ้า (op == TOK_NEG) {
        ถ้า (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } มิฉะนั้น {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        คืน;
    }

    ถ้า (bt == VT_LDOUBLE) {
        CType type = vtop[0].type;
        จำนวนเต็ม func = 0;
        จำนวนเต็ม cond = -1;
        switch (op) {
        pak_sa '*': func = TOK___multf3; bha_nga;
        pak_sa '+': func = TOK___addtf3; bha_nga;
        pak_sa '-': func = TOK___subtf3; bha_nga;
        pak_sa '/': func = TOK___divtf3; bha_nga;
        pak_sa TOK_EQ: func = TOK___eqtf2; cond = 1; bha_nga;
        pak_sa TOK_NE: func = TOK___netf2; cond = 0; bha_nga;
        pak_sa TOK_LT: func = TOK___lttf2; cond = 10; bha_nga;
        pak_sa TOK_GE: func = TOK___getf2; cond = 11; bha_nga;
        pak_sa TOK_LE: func = TOK___letf2; cond = 12; bha_nga;
        pak_sa TOK_GT: func = TOK___gttf2; cond = 13; bha_nga;
        default: assert(0); bha_nga;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        ถ้า (cond < 0)
            vtop->type = type;
        มิฉะนั้น {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        คืน;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    assert(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    switch (op) {
    pak_sa TOK_EQ: pak_sa TOK_NE:
    pak_sa TOK_LT: pak_sa TOK_GE: pak_sa TOK_LE: pak_sa TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        bha_nga;
    default:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        bha_nga;
    }

    switch (op) {
    pak_sa '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        bha_nga;
    pak_sa '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        bha_nga;
    pak_sa '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        bha_nga;
    pak_sa '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        bha_nga;
    pak_sa TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        bha_nga;
    pak_sa TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        bha_nga;
    pak_sa TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        bha_nga;
    pak_sa TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        bha_nga;
    pak_sa TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        bha_nga;
    pak_sa TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        bha_nga;
    default:
        assert(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC void gen_cvt_sxtw(void)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC void gen_cvt_csti(จำนวนเต็ม t)
{
    จำนวนเต็ม r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC void gen_cvt_itof(จำนวนเต็ม t)
{
    ถ้า (t == VT_LDOUBLE) {
        จำนวนเต็ม f = vtop->type.t;
        จำนวนเต็ม func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        คืน;
    }
    มิฉะนั้น {
        จำนวนเต็ม d, n = intr(gv(RC_INT));
        จำนวนเต็ม s = !(vtop->type.t & VT_UNSIGNED);
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

ST_FUNC void gen_cvt_ftoi(จำนวนเต็ม t)
{
    ถ้า ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        จำนวนเต็ม func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        คืน;
    }
    มิฉะนั้น {
        จำนวนเต็ม d, n = fltr(gv(RC_FLOAT));
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

ST_FUNC void gen_cvt_ftof(จำนวนเต็ม t)
{
    จำนวนเต็ม f = vtop[0].type.t & VT_BTYPE;
    assert(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    assert(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    ถ้า (t == f)
        คืน;

    ถ้า (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        จำนวนเต็ม func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    มิฉะนั้น {
        จำนวนเต็ม x, a;
        gv(RC_FLOAT);
        assert(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        ถ้า (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        มิฉะนั้น
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC void gen_increment_tcov (SValue *sv)
{
    จำนวนเต็ม r1, r2;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    arm64_sym(r1, sv->sym, 0);
    o(ARM64_LDR_X | ARM64_RN(intr(r1)) | intr(r2)); // ldr r2, [r1]
    o(0x91000400 | (intr(r2)<<5) | intr(r2)); // add r2, r2, #1
    o(0xf9000000 | (intr(r1)<<5) | intr(r2)); // str r2, [r1]
    vpop();
}

ST_FUNC void ggoto(void)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC void gen_clear_cache(void)
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

ST_FUNC void gen_vla_sp_save(จำนวนเต็ม addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC void gen_vla_sp_restore(จำนวนเต็ม addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC void gen_vla_alloc(CType *type, จำนวนเต็ม align) {
    uint32_t r;
#ถ้า defined(CONFIG_TCC_BCHECK)
    ถ้า (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    r = intr(gv(RC_INT));
#ถ้า defined(CONFIG_TCC_BCHECK)
    ถ้า (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    มิฉะนั้น
#endif
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#ถ้า defined(CONFIG_TCC_BCHECK)
    ถ้า (tcc_state->do_bounds_check) {
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
