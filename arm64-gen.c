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

#જો !defined(TCC_TARGET_MACHO) && !defined(TCC_TARGET_PE)
#define CHAR_IS_UNSIGNED
#endif

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#define PROMOTE_RET
/******************************************************/
#નહીંતર /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#અન્તર્ભાવ "tcc.h"
#અન્તર્ભાવ <assert.h>

ST_DATA અચલ અક્ષર * અચલ target_machine_defs =
    "__aarch64__\0"
#જો defined(TCC_TARGET_MACHO)
    "__arm64__\0"
#endif
    "__AARCH64EL__\0"
    ;

ST_DATA અચલ પૂર્ણાંક reg_classes[NB_REGS] = {
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

#જો defined(CONFIG_TCC_BCHECK)
સ્થિર addr_t func_bound_offset;
સ્થિર unsigned long func_bound_ind;
ST_DATA પૂર્ણાંક func_bound_add_epilog;
#endif

#define IS_FREG(x) ((x) >= TREG_F(0))

સ્થિર uint32_t intr(પૂર્ણાંક r)
{
    પ્રતિજ્ઞા(TREG_R(0) <= r && r <= TREG_R30);
    પાછા r < TREG_R30 ? r : 30;
}

સ્થિર uint32_t fltr(પૂર્ણાંક r)
{
    પ્રતિજ્ઞા(TREG_F(0) <= r && r <= TREG_F(7));
    પાછા r - TREG_F(0);
}

// Add an instruction to text section:
ST_FUNC શૂન્ય o(unsigned પૂર્ણાંક c)
{
    પૂર્ણાંક ind1 = ind + 4;
    જો (nocode_wanted)
        પાછા;
    જો (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    write32le(cur_text_section->data + ind, c);
    ind = ind1;
}

સ્થિર પૂર્ણાંક arm64_encode_bimm64(uint64_t x)
{
    પૂર્ણાંક neg = x & 1;
    પૂર્ણાંક rep, pos, len;

    જો (neg)
        x = ~x;
    જો (!x)
        પાછા -1;

    જો (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    નહીંતર જો (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    નહીંતર જો (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    નહીંતર જો (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    નહીંતર જો (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    નહીંતર
        rep = 64;

    pos = 0;
    જો (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    જો (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    જો (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    જો (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    જો (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    જો (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    જો (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    જો (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    જો (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    જો (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    જો (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    જો (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    જો (x)
        પાછા -1;
    જો (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    પાછા ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

સ્થિર uint32_t arm64_movi(પૂર્ણાંક r, uint64_t x)
{
    uint64_t m = 0xffff;
    પૂર્ણાંક e;
    જો (!(x & ~m))
        પાછા ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    જો (!(x & ~(m << 16)))
        પાછા (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    જો (!(x & ~(m << 32)))
        પાછા (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    જો (!(x & ~(m << 48)))
        પાછા (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    જો ((x & ~m) == m << 16)
        પાછા (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    જો ((x & ~(m << 16)) == m)
        પાછા (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    જો (!~(x | m))
        પાછા (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    જો (!~(x | m << 16))
        પાછા (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    જો (!~(x | m << 32))
        પાછા (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    જો (!~(x | m << 48))
        પાછા (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    જો (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        પાછા (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    જો ((e = arm64_encode_bimm64(x)) >= 0)
        પાછા (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    પાછા 0;
}

સ્થિર શૂન્ય arm64_movimm(પૂર્ણાંક r, uint64_t x)
{
    uint32_t i;
    જો ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    નહીંતર {
        // MOVZ/MOVN and 1-3 MOVKs
        પૂર્ણાંક z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        માટે (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        જો (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        માટે (i = 0; i < 64; i += 16)
            જો (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                તોડો;
            }
        માટે (i += 16; i < 64; i += 16)
            જો (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC શૂન્ય gsym_addr(પૂર્ણાંક t_, પૂર્ણાંક a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    જ્યારે (t) {
        unsigned અક્ષર *ptr = cur_text_section->data + t;
        uint32_t next = read32le(ptr);
        જો (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = next;
    }
}

સ્થિર પૂર્ણાંક arm64_type_size(પૂર્ણાંક t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    પસંદગી (t & VT_BTYPE) {
    સ્થિતિ VT_BYTE: પાછા 0;
    સ્થિતિ VT_SHORT: પાછા 1;
    સ્થિતિ VT_INT: પાછા 2;
    સ્થિતિ VT_LLONG: પાછા 3;
    સ્થિતિ VT_PTR: પાછા 3;
    સ્થિતિ VT_FUNC: પાછા 3;
    સ્થિતિ VT_STRUCT: પાછા 3;
    સ્થિતિ VT_FLOAT: પાછા 2;
    સ્થિતિ VT_DOUBLE: પાછા 3;
    સ્થિતિ VT_LDOUBLE: પાછા 4;
    સ્થિતિ VT_BOOL: પાછા 0;
    }
    પ્રતિજ્ઞા(0);
    પાછા 0;
}

સ્થિર શૂન્ય arm64_spoff(પૂર્ણાંક reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    જો (sub)
        off = -off;
    જો (off < 4096)
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    નહીંતર {
        arm64_movimm(30, off);
        o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

સ્થિર uint64_t arm64_check_offset(પૂર્ણાંક sz_, uint64_t off)
{
#ifndef TCC_TARGET_PE
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    જો (!(off & ~scaled_mask) || (off < 256 || -off <= 256))
        પાછા ~0ull;
    જો (off & scaled_mask)
        પાછા scaled_mask;
    જો (off & 0x1fful)
        પાછા 0x1fful;
#endif
    પાછા 0;
}

સ્થિર શૂન્ય arm64_ldrx(પૂર્ણાંક sg, પૂર્ણાંક sz_, પૂર્ણાંક dst, પૂર્ણાંક bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    જો (sz >= 2)
        sg = 0;
    જો (!(off & ~scaled_mask))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    નહીંતર જો (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    નહીંતર {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

સ્થિર શૂન્ય arm64_ldrv(પૂર્ણાંક sz_, પૂર્ણાંક dst, પૂર્ણાંક bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    જો (!(off & ~scaled_mask))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    નહીંતર જો (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    નહીંતર {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

સ્થિર શૂન્ય arm64_ldrs(પૂર્ણાંક reg_, પૂર્ણાંક size)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    પસંદગી (size) {
    મૂળભૂત: પ્રતિજ્ઞા(0); તોડો;
    સ્થિતિ 0:
        /* Can happen with zero size structs */
        તોડો;
    સ્થિતિ 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        તોડો;
    સ્થિતિ 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        તોડો;
    સ્થિતિ 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        તોડો;
    સ્થિતિ 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        તોડો;
    સ્થિતિ 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        તોડો;
    સ્થિતિ 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        તોડો;
    સ્થિતિ 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        તોડો;
    સ્થિતિ 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        તોડો;
    સ્થિતિ 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        તોડો;
    સ્થિતિ 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        તોડો;
    સ્થિતિ 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        તોડો;
    સ્થિતિ 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        તોડો;
    સ્થિતિ 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        તોડો;
    સ્થિતિ 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        તોડો;
    સ્થિતિ 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        તોડો;
    સ્થિતિ 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        તોડો;
    }
}

સ્થિર શૂન્ય arm64_strx(પૂર્ણાંક sz_, પૂર્ણાંક dst, પૂર્ણાંક bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    જો (!(off & ~scaled_mask))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    નહીંતર જો (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    નહીંતર {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

સ્થિર શૂન્ય arm64_strv(પૂર્ણાંક sz_, પૂર્ણાંક dst, પૂર્ણાંક bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    જો (!(off & ~scaled_mask))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    નહીંતર જો (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    નહીંતર {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

સ્થિર શૂન્ય arm64_reloca(Sym *sym, પૂર્ણાંક reloc_type, uint64_t addend)
{
    greloca(cur_text_section, sym, ind, reloc_type, addend);
}

સ્થિર શૂન્ય arm64_sym(પૂર્ણાંક r, Sym *sym, addr_t addend)
{
    જો (sym->type.t & VT_TLS) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        પૂર્ણાંક r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#નહીંતર
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#endif
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_HI12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_LO12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#ifndef TCC_TARGET_PE /* no elf-style GOT on Windows */
    } નહીંતર જો (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_PAGE, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        જો (addend > 0xffffff) {
            પૂર્ણાંક t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } નહીંતર {
           જો (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_ADD_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            જો (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#endif
    } નહીંતર {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_ADD_ABS_LO12_NC, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

સ્થિર શૂન્ય arm64_load_cmp(પૂર્ણાંક r, SValue *sv);

ST_FUNC શૂન્ય load(પૂર્ણાંક r, SValue *sv)
{
    પૂર્ણાંક svtt = sv->type.t;
    પૂર્ણાંક svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    પૂર્ણાંક svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    પૂર્ણાંક sb = !(svtt & VT_UNSIGNED);
    પૂર્ણાંક sz = arm64_type_size(svtt);

    જો (svr == (VT_LOCAL | VT_LVAL)) {
        જો (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        નહીંતર
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        પાછા;
    }

    જો (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        જો (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        નહીંતર
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        પાછા;
    }

    જો (svrv < VT_CONST && (svr & VT_LVAL)) {
        જો (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        નહીંતર
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        પાછા;
    }

    જો (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        જો (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & mask);
        નહીંતર
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & mask);
        પાછા;
    }

    જો (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        પાછા;
    }

    જો (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        પાછા;
    }

    જો (svr < VT_CONST) {
        જો (IS_FREG(r) && IS_FREG(svr))
            જો (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            નહીંતર
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        નહીંતર જો (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        નહીંતર
            પ્રતિજ્ઞા(0);
      પાછા;
    }

    જો (svr == VT_LOCAL) {
        જો (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        નહીંતર {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        પાછા;
    }

    જો (svr == VT_JMP || svr == VT_JMPI) {
        પૂર્ણાંક t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        પાછા;
    }

    જો (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        જો (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        નહીંતર
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        પાછા;
    }

    જો (svr == VT_CMP) {
        arm64_load_cmp(r, sv);
        પાછા;
    }

    printf("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (long)svcul);
    પ્રતિજ્ઞા(0);
}

ST_FUNC શૂન્ય store(પૂર્ણાંક r, SValue *sv)
{
    પૂર્ણાંક svtt = sv->type.t;
    પૂર્ણાંક svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    પૂર્ણાંક svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    પૂર્ણાંક sz = arm64_type_size(svtt);

    જો (svr == (VT_LOCAL | VT_LVAL)) {
        જો (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        નહીંતર
            arm64_strx(sz, intr(r), 29, svcoff);
        પાછા;
    }

    જો (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        જો (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        નહીંતર
            arm64_strx(sz, intr(r), 30, 0);
        પાછા;
    }

    જો (svrv < VT_CONST && (svr & VT_LVAL)) {
        જો (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        નહીંતર
            arm64_strx(sz, intr(r), intr(svrv), 0);
        પાછા;
    }

    જો (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        જો (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & mask);
        નહીંતર
            arm64_strx(sz, intr(r), 30, svcoff & mask);
        પાછા;
    }

    printf("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (long)svcoff);
    પ્રતિજ્ઞા(0);
}

સ્થિર શૂન્ય arm64_gen_bl_or_b(પૂર્ણાંક b)
{
    જો ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    નહીંતર {
#ifdef CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#endif
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#જો defined CONFIG_TCC_BCHECK || defined TCC_TARGET_PE
સ્થિર શૂન્ય gen_static_call(પૂર્ણાંક v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#endif

#જો defined(CONFIG_TCC_BCHECK)
સ્થિર શૂન્ય gen_bounds_prolog(શૂન્ય)
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

સ્થિર શૂન્ય gen_bounds_epilog(શૂન્ય)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    પૂર્ણાંક offset_modified = func_bound_offset != lbounds_section->data_offset;

    જો (!offset_modified && !func_bound_add_epilog)
        પાછા;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, કદ(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    જો (offset_modified) {
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

સ્થિર પૂર્ણાંક arm64_hfa_aux(CType *type, પૂર્ણાંક *fsize, પૂર્ણાંક અંક)
{
    જો (is_float(type->t)) {
        પૂર્ણાંક a, n = type_size(type, &a);
        જો (અંક >= 4 || (*fsize && *fsize != n))
            પાછા -1;
        *fsize = n;
        પાછા અંક + 1;
    }
    નહીંતર જો ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field;
        જો (!IS_UNION(type->t)) {
            પૂર્ણાંક num0 = અંક;
            માટે (field = type->ref->next; field; field = field->next) {
                જો (field->c != (અંક - num0) * *fsize)
                    પાછા -1;
                અંક = arm64_hfa_aux(&field->type, fsize, અંક);
                જો (અંક == -1)
                    પાછા -1;
            }
            જો (type->ref->c != (અંક - num0) * *fsize)
                પાછા -1;
            પાછા અંક;
        }
        નહીંતર { // union
            પૂર્ણાંક num0 = અંક;
            માટે (field = type->ref->next; field; field = field->next) {
                પૂર્ણાંક num1 = arm64_hfa_aux(&field->type, fsize, num0);
                જો (num1 == -1)
                    પાછા -1;
                અંક = num1 < અંક ? અંક : num1;
            }
            જો (type->ref->c != (અંક - num0) * *fsize)
                પાછા -1;
            પાછા અંક;
        }
    }
    નહીંતર જો (type->t & VT_ARRAY) { /* handle float array within struct */
        પૂર્ણાંક num1;
        જો (!type->ref->c)
            પાછા અંક;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, અંક);
        જો (num1 == -1 || (num1 != અંક && type->ref->c > 4))
            પાછા -1;
        num1 = અંક + type->ref->c * (num1 - અંક);
        જો (num1 > 4)
            પાછા -1;
        પાછા num1;
    }
    પાછા -1;
}

સ્થિર પૂર્ણાંક arm64_hfa(CType *type, unsigned *fsize)
{
    જો ((type->t & VT_BTYPE) == VT_STRUCT) {
        પૂર્ણાંક sz = 0;
        પૂર્ણાંક n = arm64_hfa_aux(type, &sz, 0);
        જો (0 < n && n <= 4) {
            જો (fsize)
                *fsize = sz;
            પાછા n;
        }
    }
    પાછા 0;
}

સ્થિર unsigned long arm64_pcs_aux(પૂર્ણાંક variadic, પૂર્ણાંક n, CType **type, unsigned long *a)
{
    પૂર્ણાંક nx = 0; // next integer register
    પૂર્ણાંક nv = 0; // next vector register
    unsigned long ns = 32; // next stack offset
    પૂર્ણાંક i;

    માટે (i = 0; i < n; i++) {
        પૂર્ણાંક hfa = arm64_hfa(type[i], 0);
        પૂર્ણાંક size, align, bt;

        bt = type[i]->t & VT_BTYPE;
        જો (bt == VT_PTR || bt == VT_FUNC)
            size = align = 8;
        નહીંતર
            size = type_size(type[i], &align);

#જો defined(TCC_TARGET_MACHO)
        જો (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#અથવાજો defined(TCC_TARGET_PE)
        જો (variadic && i >= variadic) {
            hfa = 0;
            જો (is_float(bt))
                bt = VT_INT, size = align = 8;
        }
#endif
        જો (hfa)
            // B.2
            ;
        નહીંતર જો (size > 16) {
            // B.3: replace with pointer
            જો (nx < 8)
                a[i] = nx++ << 1 | 1;
            નહીંતર {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            ચાલુ;
        }
        નહીંતર જો (bt == VT_STRUCT)
            // B.4
            size = (size + 7) & ~7;

        // C.1
        જો (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            ચાલુ;
        }

        // C.2
        જો (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            ચાલુ;
        }

        // C.3
        જો (hfa) {
            nv = 8;
            size = (size + 7) & ~7;
        }

        // C.4
        જો (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        જો (bt == VT_FLOAT)
            size = 8;

        // C.6
        જો (hfa || is_float(bt)) {
            a[i] = ns;
            ns += size;
            ચાલુ;
        }

        // C.7
        જો (bt != VT_STRUCT && size <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            ચાલુ;
        }

        // C.8
        જો (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        જો (bt != VT_STRUCT && size == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            ચાલુ;
        }

        // C.10
        જો (bt == VT_STRUCT && size <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (size + 7) >> 3;
            ચાલુ;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        જો (bt == VT_STRUCT) {
            a[i] = ns;
            ns += size;
            ચાલુ;
        }

        // C.14
        જો (size < 8)
            size = 8;

        // C.15
        a[i] = ns;
        ns += size;
    }

    પાછા ns - 32;
}

સ્થિર unsigned long arm64_pcs(પૂર્ણાંક variadic, પૂર્ણાંક n, CType **type, unsigned long *a)
{
    unsigned long ઢગલો;

    // Return type:
    જો ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    નહીંતર {
        arm64_pcs_aux(0, 1, type, a);
        પ્રતિજ્ઞા(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    ઢગલો = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    જો (0) {
        પૂર્ણાંક i;
        માટે (i = 0; i < n; i++) {
            જો (!i)
                printf("arm64_pcs return: ");
            નહીંતર
                printf("arm64_pcs arg %d: ", i);
            જો (a[i] == (unsigned long)-1)
                printf("void\n");
            નહીંતર જો (a[i] == 1 && !i)
                printf("X8 pointer\n");
            નહીંતર જો (a[i] < 16)
                printf("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            નહીંતર જો (a[i] < 32)
                printf("V%lu\n", a[i] / 2 - 8);
            નહીંતર
                printf("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    પાછા ઢગલો;
}

સ્થિર પૂર્ણાંક n_func_args(CType *type)
{
    પૂર્ણાંક n_args = 0;
    Sym *arg;

    માટે (arg = type->ref->next; arg; arg = arg->next)
        n_args++;
    પાછા n_args;
}

સ્થિર શૂન્ય arm64_sub_sp(uint64_t diff)
{
    જો (!diff)
        પાછા;
#ifdef TCC_TARGET_PE
    જો (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        પાછા;
    }
#endif
    જો (!(diff >> 24)) {
        જો (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        જો (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } નહીંતર {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

સ્થિર પૂર્ણાંક gv_addr(પૂર્ણાંક r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    પાછા gv(r);
}

ST_FUNC શૂન્ય gfunc_call(પૂર્ણાંક nb_args)
{
    CType *return_type;
    CType **t;
    unsigned long *a, *a1;
    unsigned long ઢગલો;
    પૂર્ણાંક i;
    પૂર્ણાંક func_type = vtop[-nb_args].type.ref->f.func_type;
    પૂર્ણાંક variadic = (func_type == FUNC_ELLIPSIS);
    પૂર્ણાંક old_style = (func_type == FUNC_OLD);
    પૂર્ણાંક var_nb_arg = variadic ? n_func_args(&vtop[-nb_args].type) : 0;

    save_regs(nb_args + 1);

#ifdef CONFIG_TCC_BCHECK
    જો (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    return_type = &vtop[-nb_args].type.ref->type;
    જો ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_args;

    t = tcc_malloc((nb_args + 1) * કદ(*t));
    a = tcc_malloc((nb_args + 1) * કદ(*a));
    a1 = tcc_malloc((nb_args + 1) * કદ(*a1));

    t[0] = return_type;
    માટે (i = 0; i < nb_args; i++)
        t[nb_args - i] = &vtop[-i].type;

    ઢગલો = arm64_pcs(
#ifdef TCC_TARGET_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#endif
        var_nb_arg, nb_args + 1, t, a);

    // Allocate space for structs replaced by pointer:
    માટે (i = nb_args; i; i--)
        જો (a[i] & 1) {
            SValue *arg = &vtop[i - nb_args];
            પૂર્ણાંક align, size = type_size(&arg->type, &align);
            પ્રતિજ્ઞા((arg->type.t & VT_BTYPE) == VT_STRUCT);
            ઢગલો = (ઢગલો + align - 1) & -align;
            a1[i] = ઢગલો;
            ઢગલો += size;
        }

    ઢગલો = (ઢગલો + 15) >> 4 << 4;

    જો (ઢગલો >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", ઢગલો);
    arm64_sub_sp(ઢગલો);

    // First pass: set all values on stack
    માટે (i = nb_args; i; i--) {
        vpushv(vtop - nb_args + i);

        જો (a[i] & 1) {
            // struct replaced by pointer
            પૂર્ણાંક r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            જો (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        નહીંતર જો (a[i] >= 32) {
            // value on stack
            જો ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                પૂર્ણાંક r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            નહીંતર જો (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_size(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            નહીંતર {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    માટે (i = nb_args; i; i--, vtop--) {
        જો (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            જો ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                જો ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                નહીંતર
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            નહીંતર જો ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                પૂર્ણાંક align, size = type_size(&vtop->type, &align);
                જો (size) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, size);
                }
            }
            નહીંતર
                gv(RC_R(a[i] / 2));
        }
        નહીંતર જો (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        નહીંતર જો (a[i] < 32) {
            // value in floating-point registers
            જો ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                જો (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    માટે (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } નહીંતર {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            નહીંતર
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    જો ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        જો (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        નહીંતર
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    જો (ઢગલો & 0xfff)
        o(0x910003ff | (ઢગલો & 0xfff) << 10); // add sp,sp,#(n)
    જો (ઢગલો >> 12)
        o(0x914003ff | (ઢગલો >> 12) << 10);

    {
        પૂર્ણાંક rt = return_type->t;
        પૂર્ણાંક bt = rt & VT_BTYPE;
        જો (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            જો (a[0] == 0) {
                પૂર્ણાંક align, size = type_size(return_type, &align);
                પ્રતિજ્ઞા(size <= 16);
                જો (size > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                નહીંતર જો (size)
                    arm64_strx(size > 4 ? 3 : size > 2 ? 2 : size > 1, 0, 8, 0);

            }
            નહીંતર જો (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                માટે (j = 0; j < n; j++)
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

સ્થિર unsigned long arm64_func_va_list_ઢગલો;
સ્થિર પૂર્ણાંક arm64_func_va_list_gr_offs;
સ્થિર પૂર્ણાંક arm64_func_va_list_vr_offs;
સ્થિર પૂર્ણાંક arm64_func_sub_sp_offset;

સ્થિર unsigned arm64_func_start_offset;
#define ARM64_FUNC_ઢગલો_SETUP_SLOTS 6

#ifdef TCC_TARGET_PE
સ્થિર unsigned long arm64_pe_param_off(unsigned long a)
{
    પાછા a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#endif

ST_FUNC શૂન્ય gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    પૂર્ણાંક n = 0;
    પૂર્ણાંક i = 0;
    Sym *sym;
    CType **t;
    unsigned long *a;
    પૂર્ણાંક use_x8 = 0;
    પૂર્ણાંક last_int = 0;
    પૂર્ણાંક last_float = 0;
    પૂર્ણાંક variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    પૂર્ણાંક var_nb_arg = variadic ? n_func_args(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    માટે (sym = func_type->ref; sym; sym = sym->next)
        ++n;

#ifdef TCC_TARGET_PE
    n += variadic;
#endif

    t = tcc_malloc(n * કદ(*t));
    a = tcc_malloc(n * કદ(*a));
    માટે (sym = func_type->ref; sym; sym = sym->next)
        t[i++] = &sym->type;

#ifdef TCC_TARGET_PE
    જો (variadic)
        t[i] = &int_type;
#endif

    arm64_func_va_list_ઢગલો = arm64_pcs(var_nb_arg, n, t, a);

#ifdef TCC_TARGET_PE
    જો (variadic)
        arm64_func_va_list_ઢગલો = arm64_pe_param_off(a[n - 1]);
#endif

#જો !defined(TCC_TARGET_MACHO)
    જો (variadic) {
        use_x8 = 1;
        last_int = 4;
        last_float = 4;
    }
#endif

    જો (a && a[0] == 1)
        use_x8 = 1;
    માટે (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        જો (a[i] < 16) {
            પૂર્ણાંક last, align, size = type_size(&sym->type, &align);
	    last = a[i] / 4 + 1 + (size - 1) / 8;
	    last_int = last > last_int ? last : last_int;
	}
        નહીંતર જો (a[i] < 32) {
            પૂર્ણાંક last, hfa = arm64_hfa(&sym->type, 0);
	    last = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    last_float = last > last_float ? last : last_float;
	}
    }

    last_int = last_int > 4 ? 4 : last_int;
    last_float = last_float > 4 ? 4 : last_float;

    arm64_func_start_offset = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    માટે (i = 0; i < last_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    જો (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    માટે (i = 0; i < last_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    માટે (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        પૂર્ણાંક off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_set_param(sym, off, a[i] & 1);

        જો (a[i] < 16) {
            પૂર્ણાંક align, size = type_size(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && size > 8)) * 8;
        }
        નહીંતર જો (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        જો (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            જો (k > 0 && sz < 16)
                માટે (j = 0; j < k; j++) {
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
    માટે (i = 0; i < ARM64_FUNC_ઢગલો_SETUP_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#ifdef CONFIG_TCC_BCHECK
    જો (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

ST_FUNC શૂન્ય gen_va_start(શૂન્ય)
{
    પૂર્ણાંક r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#ifdef TCC_TARGET_PE
    જો (arm64_func_va_list_ઢગલો) {
        arm64_movimm(30, arm64_func_va_list_ઢગલો);
        o(0x8b1e03be); // add x30,x29,x30
    } નહીંતર
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#નહીંતર
    જો (arm64_func_va_list_ઢગલો) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_ઢગલો + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    નહીંતર
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#જો !defined(TCC_TARGET_MACHO)
    જો (arm64_func_va_list_gr_offs) {
        જો (arm64_func_va_list_ઢગલો)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    જો (arm64_func_va_list_vr_offs) {
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

ST_FUNC શૂન્ય gen_va_arg(CType *t)
{
    પૂર્ણાંક align, size = type_size(t, &align);
    uint32_t r0, r1;

#ifdef TCC_TARGET_PE
    પૂર્ણાંક indirect = 0, slot = (size + 7) & -8;

    જો (size > 16)
        indirect = 1, slot = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    જો (slot) {
        જો (slot == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        જો (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | slot << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    જો (indirect)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#નહીંતર /* !PE */
    unsigned fsize = size, hfa = 1;

    જો (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    જો (!hfa) {
        uint32_t n = size > 16 ? 8 : (size + 7) & -8;

#જો !defined(TCC_TARGET_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        જો (align == 16) {
            પ્રતિજ્ઞા(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#endif

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        જો (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#જો !defined(TCC_TARGET_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#endif

        જો (size > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    નહીંતર {
        uint32_t ssz = (size + 7) & -(uint32_t)8;
#જો !defined(TCC_TARGET_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#endif
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        જો (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#જો !defined(TCC_TARGET_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_text_section->data + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        જો (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        નહીંતર {
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

ST_FUNC પૂર્ણાંક gfunc_sret(CType *vt, પૂર્ણાંક variadic, CType *ret,
                       પૂર્ણાંક *align, પૂર્ણાંક *regsize)
{
    પાછા 0;
}

ST_FUNC શૂન્ય gfunc_return(CType *func_type)
{
    CType *t = func_type;
    unsigned long a;

    arm64_pcs(0, 1, &t, &a);

    પસંદગી (a) {
    સ્થિતિ -1:
        તોડો;
    સ્થિતિ 0:
        જો ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            પૂર્ણાંક align, size = type_size(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, size);
        }
        નહીંતર
            gv(RC_IRET);
        તોડો;
    સ્થિતિ 1: {
        CType type = *func_type;
        mk_pointer(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        તોડો;
    }
    સ્થિતિ 16:
        જો ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          માટે (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        નહીંતર
            gv(RC_FRET);
        તોડો;
    મૂળભૂત:
      પ્રતિજ્ઞા(0);
    }
    vtop--;
}

ST_FUNC શૂન્ય gfunc_epilog(શૂન્ય)
{
#ifdef CONFIG_TCC_BCHECK
    જો (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    જો (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        પૂર્ણાંક i;
        addr_t saved_ind = ind;
        addr_t patch_end = arm64_func_sub_sp_offset + ARM64_FUNC_ઢગલો_SETUP_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_offset;
        arm64_sub_sp(diff);
        માટે (i = ind; i < patch_end; i += 4)
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

ST_FUNC શૂન્ય gen_fill_nops(પૂર્ણાંક bytes)
{
    જો ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    જ્યારે (bytes > 0) {
	o(ARM64_NOP); // nop
	bytes -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC પૂર્ણાંક gjmp(પૂર્ણાંક t)
{
    પૂર્ણાંક r = ind;
    જો (nocode_wanted)
        પાછા t;
    o(t);
    પાછા r;
}

// Generate branch to known address:
ST_FUNC શૂન્ય gjmp_addr(પૂર્ણાંક a)
{
    પ્રતિજ્ઞા(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC પૂર્ણાંક gjmp_append(પૂર્ણાંક n, પૂર્ણાંક t)
{
    શૂન્ય *p;
    /* insert vtop->c jump list in t */
    જો (n) {
        uint32_t n1 = n, n2;
        જ્યારે ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    પાછા t;
}

શૂન્ય arm64_vset_VT_CMP(પૂર્ણાંક op)
{
    જો (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

સ્થિર શૂન્ય arm64_gen_opil(પૂર્ણાંક op, uint32_t l);

સ્થિર શૂન્ય arm64_load_cmp(પૂર્ણાંક r, SValue *sv)
{
    sv->r = sv->cmp_r;
    જો (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    જો (r != sv->r) {
        load(r, sv);
        sv->r = r;
    }
}

ST_FUNC પૂર્ણાંક gjmp_cond(પૂર્ણાંક op, પૂર્ણાંક t)
{
    પૂર્ણાંક bt = vtop->type.t & VT_BTYPE;

    પૂર્ણાંક inv = op & 1;
    vtop->r = vtop->cmp_r;

    જો (bt == VT_LDOUBLE) {
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
    નહીંતર જો (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    નહીંતર {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    પાછા gjmp(t);
}

સ્થિર પૂર્ણાંક arm64_iconst(uint64_t *val, SValue *sv)
{
    જો ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        પાછા 0;
    જો (val) {
        પૂર્ણાંક t = sv->type.t;
	પૂર્ણાંક bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    પાછા 1;
}

સ્થિર પૂર્ણાંક arm64_gen_opic(પૂર્ણાંક op, uint32_t l, પૂર્ણાંક rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    જો (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    પસંદગી (op) {

    સ્થિતિ '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        જો (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        નહીંતર જો (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        નહીંતર {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        પાછા 1;
      }

    સ્થિતિ '-':
        જો (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        નહીંતર જો (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        નહીંતર {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        પાછા 1;

    સ્થિતિ '^':
        જો (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            પાછા 1;
        }
        // fall through
    સ્થિતિ '&':
    સ્થિતિ '|': {
        પૂર્ણાંક e = arm64_encode_bimm64(l ? val : val | val << 32);
        જો (e < 0)
            પાછા 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        પાછા 1;
    }

    સ્થિતિ TOK_SAR:
    સ્થિતિ TOK_SHL:
    સ્થિતિ TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        જો (rev)
            પાછા 0;
        જો (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            પાછા 1;
        }
        નહીંતર જો (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        નહીંતર
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        પાછા 1;
    }

    }
    પાછા 0;
}

સ્થિર શૂન્ય arm64_gen_opil(પૂર્ણાંક op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        પૂર્ણાંક rev = 1;

        જો (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        જો (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            જો (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                પાછા;
            }
        }
        જો (!rev)
            vswap();
    }

    gv2(RC_INT, RC_INT);
    પ્રતિજ્ઞા(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = intr(vtop[-1].r);
    b = intr(vtop[0].r);
    vtop -= 2;
    x = get_reg(RC_INT);
    ++vtop;
    vtop[0].r = x;
    x = intr(x);

    પસંદગી (op) {
    સ્થિતિ '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        તોડો;
    સ્થિતિ '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        તોડો;
    સ્થિતિ '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        તોડો;
    સ્થિતિ '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        તોડો;
    સ્થિતિ '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        તોડો;
    સ્થિતિ '/':
    સ્થિતિ TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        તોડો;
    સ્થિતિ '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        તોડો;
    સ્થિતિ '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        તોડો;
    સ્થિતિ TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        તોડો;
    સ્થિતિ TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        તોડો;
    સ્થિતિ TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        તોડો;
    સ્થિતિ TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        તોડો;
    સ્થિતિ TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        તોડો;
    સ્થિતિ TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        તોડો;
    સ્થિતિ TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        તોડો;
    સ્થિતિ TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        તોડો;
    સ્થિતિ TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        તોડો;
    સ્થિતિ TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        તોડો;
    સ્થિતિ TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        તોડો;
    સ્થિતિ TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        તોડો;
    સ્થિતિ TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        તોડો;
    સ્થિતિ TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        તોડો;
    સ્થિતિ TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        તોડો;
    મૂળભૂત:
        પ્રતિજ્ઞા(0);
    }
}

ST_FUNC શૂન્ય gen_opi(પૂર્ણાંક op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC શૂન્ય gen_opl(પૂર્ણાંક op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC શૂન્ય gen_opf(પૂર્ણાંક op)
{
    uint32_t x, a, b, dbl;
    પૂર્ણાંક bt = vtop[0].type.t & VT_BTYPE;

    જો (op == TOK_NEG) {
        જો (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } નહીંતર {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        પાછા;
    }

    જો (bt == VT_LDOUBLE) {
        CType type = vtop[0].type;
        પૂર્ણાંક func = 0;
        પૂર્ણાંક cond = -1;
        પસંદગી (op) {
        સ્થિતિ '*': func = TOK___multf3; તોડો;
        સ્થિતિ '+': func = TOK___addtf3; તોડો;
        સ્થિતિ '-': func = TOK___subtf3; તોડો;
        સ્થિતિ '/': func = TOK___divtf3; તોડો;
        સ્થિતિ TOK_EQ: func = TOK___eqtf2; cond = 1; તોડો;
        સ્થિતિ TOK_NE: func = TOK___netf2; cond = 0; તોડો;
        સ્થિતિ TOK_LT: func = TOK___lttf2; cond = 10; તોડો;
        સ્થિતિ TOK_GE: func = TOK___getf2; cond = 11; તોડો;
        સ્થિતિ TOK_LE: func = TOK___letf2; cond = 12; તોડો;
        સ્થિતિ TOK_GT: func = TOK___gttf2; cond = 13; તોડો;
        મૂળભૂત: પ્રતિજ્ઞા(0); તોડો;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        જો (cond < 0)
            vtop->type = type;
        નહીંતર {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        પાછા;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    પ્રતિજ્ઞા(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    પસંદગી (op) {
    સ્થિતિ TOK_EQ: સ્થિતિ TOK_NE:
    સ્થિતિ TOK_LT: સ્થિતિ TOK_GE: સ્થિતિ TOK_LE: સ્થિતિ TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        તોડો;
    મૂળભૂત:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        તોડો;
    }

    પસંદગી (op) {
    સ્થિતિ '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        તોડો;
    સ્થિતિ '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        તોડો;
    સ્થિતિ '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        તોડો;
    સ્થિતિ '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        તોડો;
    સ્થિતિ TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        તોડો;
    સ્થિતિ TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        તોડો;
    સ્થિતિ TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        તોડો;
    સ્થિતિ TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        તોડો;
    સ્થિતિ TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        તોડો;
    સ્થિતિ TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        તોડો;
    મૂળભૂત:
        પ્રતિજ્ઞા(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC શૂન્ય gen_cvt_sxtw(શૂન્ય)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC શૂન્ય gen_cvt_csti(પૂર્ણાંક t)
{
    પૂર્ણાંક r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC શૂન્ય gen_cvt_itof(પૂર્ણાંક t)
{
    જો (t == VT_LDOUBLE) {
        પૂર્ણાંક f = vtop->type.t;
        પૂર્ણાંક func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        પાછા;
    }
    નહીંતર {
        પૂર્ણાંક d, n = intr(gv(RC_INT));
        પૂર્ણાંક s = !(vtop->type.t & VT_UNSIGNED);
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

ST_FUNC શૂન્ય gen_cvt_ftoi(પૂર્ણાંક t)
{
    જો ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        પૂર્ણાંક func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        પાછા;
    }
    નહીંતર {
        પૂર્ણાંક d, n = fltr(gv(RC_FLOAT));
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

ST_FUNC શૂન્ય gen_cvt_ftof(પૂર્ણાંક t)
{
    પૂર્ણાંક f = vtop[0].type.t & VT_BTYPE;
    પ્રતિજ્ઞા(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    પ્રતિજ્ઞા(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    જો (t == f)
        પાછા;

    જો (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        પૂર્ણાંક func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    નહીંતર {
        પૂર્ણાંક x, a;
        gv(RC_FLOAT);
        પ્રતિજ્ઞા(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        જો (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        નહીંતર
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC શૂન્ય gen_increment_tcov (SValue *sv)
{
    પૂર્ણાંક r1, r2;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    arm64_sym(r1, sv->sym, 0);
    o(ARM64_LDR_X | ARM64_RN(intr(r1)) | intr(r2)); // ldr r2, [r1]
    o(0x91000400 | (intr(r2)<<5) | intr(r2)); // add r2, r2, #1
    o(0xf9000000 | (intr(r1)<<5) | intr(r2)); // str r2, [r1]
    vpop();
}

ST_FUNC શૂન્ય ggoto(શૂન્ય)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC શૂન્ય gen_clear_cache(શૂન્ય)
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

ST_FUNC શૂન્ય gen_vla_sp_save(પૂર્ણાંક addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC શૂન્ય gen_vla_sp_restore(પૂર્ણાંક addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC શૂન્ય gen_vla_alloc(CType *type, પૂર્ણાંક align) {
    uint32_t r;
#જો defined(CONFIG_TCC_BCHECK)
    જો (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    r = intr(gv(RC_INT));
#જો defined(CONFIG_TCC_BCHECK)
    જો (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    નહીંતર
#endif
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#જો defined(CONFIG_TCC_BCHECK)
    જો (tcc_state->do_bounds_check) {
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
