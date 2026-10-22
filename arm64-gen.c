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

#اگر_تعریف_شدہ ہدف_DEFS_ONLY

// Number of registers available to allocator:
#تعریف_کرو NB_REGS 28 // x0-x18, x30, v0-v7

#تعریف_کرو TREG_R(x) (x) // x = 0..18
#تعریف_کرو TREG_R30  19
#تعریف_کرو TREG_F(x) (x + 20) // x = 0..7

// Register classes sorted from more general to more precise:
#تعریف_کرو RC_INT (1 << 0)
#تعریف_کرو RC_FLOAT (1 << 1)
#تعریف_کرو RC_R(x) (1 << (2 + (x))) // x = 0..18
#تعریف_کرو RC_R30  (1 << 21)
#تعریف_کرو RC_F(x) (1 << (22 + (x))) // x = 0..7

#تعریف_کرو RC_IRET (RC_R(0)) // int return register class
#تعریف_کرو RC_FRET (RC_F(0)) // float return register class

#تعریف_کرو REG_IRET (TREG_R(0)) // int return register number
#تعریف_کرو REG_FRET (TREG_F(0)) // float return register number

#تعریف_کرو PTR_سائز 8

#تعریف_کرو LDOUBLE_سائز 16
#تعریف_کرو LDOUBLE_ALIGN 16

#تعریف_کرو MAX_ALIGN 16

#اگر !defined(TCC_ہدف_MACHO) && !defined(TCC_ہدف_PE)
#تعریف_کرو CHAR_IS_UNSIGNED
#اگر_ختم

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#تعریف_کرو PROMOTE_RET
/******************************************************/
#ورنہ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"
#شامل <assert.h>

ST_ڈیٹا ثابت حرف * ثابت ہدف_machine_defs =
    "__aarch64__\0"
#اگر defined(TCC_ہدف_MACHO)
    "__arm64__\0"
#اگر_ختم
    "__AARCH64EL__\0"
    ;

ST_ڈیٹا ثابت صحیح reg_classes[NB_REGS] = {
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

#اگر defined(CONFIG_TCC_BCHECK)
ساکن addr_t func_bound_انحراف;
ساکن غیرعلامتی طویل func_bound_ind;
ST_ڈیٹا صحیح func_bound_جوڑو_epilog;
#اگر_ختم

#تعریف_کرو IS_FREG(x) ((x) >= TREG_F(0))

ساکن uint32_t intr(صحیح r)
{
    أكد(TREG_R(0) <= r && r <= TREG_R30);
    واپس r < TREG_R30 ? r : 30;
}

ساکن uint32_t fltr(صحیح r)
{
    أكد(TREG_F(0) <= r && r <= TREG_F(7));
    واپس r - TREG_F(0);
}

// Add an instruction to text section:
ST_FUNC خالی o(غیرعلامتی صحیح c)
{
    صحیح ind1 = ind + 4;
    اگر (nocode_wanted)
        واپس;
    اگر (ind1 > cur_متن_section->ڈیٹا_allocated)
        section_realloc(cur_متن_section, ind1);
    write32le(cur_متن_section->ڈیٹا + ind, c);
    ind = ind1;
}

ساکن صحیح arm64_encode_bimm64(uint64_t x)
{
    صحیح neg = x & 1;
    صحیح rep, pos, len;

    اگر (neg)
        x = ~x;
    اگر (!x)
        واپس -1;

    اگر (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    ورنہ اگر (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    ورنہ اگر (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    ورنہ اگر (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    ورنہ اگر (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    ورنہ
        rep = 64;

    pos = 0;
    اگر (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    اگر (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    اگر (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    اگر (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    اگر (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    اگر (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    اگر (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    اگر (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    اگر (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    اگر (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    اگر (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    اگر (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    اگر (x)
        واپس -1;
    اگر (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    واپس ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

ساکن uint32_t arm64_movi(صحیح r, uint64_t x)
{
    uint64_t m = 0xffff;
    صحیح e;
    اگر (!(x & ~m))
        واپس ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    اگر (!(x & ~(m << 16)))
        واپس (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    اگر (!(x & ~(m << 32)))
        واپس (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    اگر (!(x & ~(m << 48)))
        واپس (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    اگر ((x & ~m) == m << 16)
        واپس (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    اگر ((x & ~(m << 16)) == m)
        واپس (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    اگر (!~(x | m))
        واپس (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    اگر (!~(x | m << 16))
        واپس (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    اگر (!~(x | m << 32))
        واپس (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    اگر (!~(x | m << 48))
        واپس (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    اگر (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        واپس (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    اگر ((e = arm64_encode_bimm64(x)) >= 0)
        واپس (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    واپس 0;
}

ساکن خالی arm64_movimm(صحیح r, uint64_t x)
{
    uint32_t i;
    اگر ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    ورنہ {
        // MOVZ/MOVN and 1-3 MOVKs
        صحیح z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        برائے (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        اگر (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        برائے (i = 0; i < 64; i += 16)
            اگر (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                توڑو;
            }
        برائے (i += 16; i < 64; i += 16)
            اگر (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC خالی gsym_addr(صحیح t_, صحیح a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    جب (t) {
        غیرعلامتی حرف *ptr = cur_متن_section->ڈیٹا + t;
        uint32_t اگلا = read32le(ptr);
        اگر (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = اگلا;
    }
}

ساکن صحیح arm64_type_سائز(صحیح t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    انتخاب (t & VT_BTYPE) {
    حالت VT_BYTE: واپس 0;
    حالت VT_SHORT: واپس 1;
    حالت VT_INT: واپس 2;
    حالت VT_LLONG: واپس 3;
    حالت VT_PTR: واپس 3;
    حالت VT_FUNC: واپس 3;
    حالت VT_STRUCT: واپس 3;
    حالت VT_FLOAT: واپس 2;
    حالت VT_DOUBLE: واپس 3;
    حالت VT_LDOUBLE: واپس 4;
    حالت VT_BOOL: واپس 0;
    }
    أكد(0);
    واپس 0;
}

ساکن خالی arm64_spoff(صحیح reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    اگر (sub)
        off = -off;
    اگر (off < 4096)
        o(ARM64_جوڑو_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    ورنہ {
        arm64_movimm(30, off);
        o(ARM64_جوڑو_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

ساکن uint64_t arm64_check_انحراف(صحیح sz_, uint64_t off)
{
#اگر_غیر_تعریف_شدہ TCC_ہدف_PE
    uint32_t sz = sz_;
    uint64_t scaled_نقاب = 0xffful << sz;
    اگر (!(off & ~scaled_نقاب) || (off < 256 || -off <= 256))
        واپس ~0ull;
    اگر (off & scaled_نقاب)
        واپس scaled_نقاب;
    اگر (off & 0x1fful)
        واپس 0x1fful;
#اگر_ختم
    واپس 0;
}

ساکن خالی arm64_ldrx(صحیح sg, صحیح sz_, صحیح dst, صحیح bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_نقاب = 0xffful << sz;
    اگر (sz >= 2)
        sg = 0;
    اگر (!(off & ~scaled_نقاب))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    ورنہ اگر (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    ورنہ {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

ساکن خالی arm64_ldrv(صحیح sz_, صحیح dst, صحیح bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_نقاب = 0xffful << sz;

    اگر (!(off & ~scaled_نقاب))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    ورنہ اگر (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    ورنہ {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

ساکن خالی arm64_ldrs(صحیح reg_, صحیح سائز)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    انتخاب (سائز) {
    طےشدہ: أكد(0); توڑو;
    حالت 0:
        /* Can happen with zero size structs */
        توڑو;
    حالت 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        توڑو;
    حالت 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        توڑو;
    حالت 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        توڑو;
    حالت 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        توڑو;
    حالت 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        توڑو;
    حالت 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        توڑو;
    حالت 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        توڑو;
    حالت 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        توڑو;
    حالت 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        توڑو;
    حالت 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        توڑو;
    حالت 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        توڑو;
    حالت 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        توڑو;
    حالت 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        توڑو;
    حالت 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        توڑو;
    حالت 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        توڑو;
    حالت 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        توڑو;
    }
}

ساکن خالی arm64_strx(صحیح sz_, صحیح dst, صحیح bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_نقاب = 0xffful << sz;

    اگر (!(off & ~scaled_نقاب))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    ورنہ اگر (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    ورنہ {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

ساکن خالی arm64_strv(صحیح sz_, صحیح dst, صحیح bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_نقاب = 0xffful << sz;

    اگر (!(off & ~scaled_نقاب))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    ورنہ اگر (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    ورنہ {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

ساکن خالی arm64_reloca(Sym *sym, صحیح reloc_type, uint64_t addend)
{
    greloca(cur_متن_section, sym, ind, reloc_type, addend);
}

ساکن خالی arm64_sym(صحیح r, Sym *sym, addr_t addend)
{
    اگر (sym->type.t & VT_TLS) {
#اگر_تعریف_شدہ TCC_ہدف_PE
        Sym *s2 = external_global_sym(TOK_tls_اشاریہ, &int_type);
        صحیح r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#ورنہ
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#اگر_ختم
        arm64_reloca(sym, R_AARCH64_TLSLE_جوڑو_TPREL_HI12, addend);
        o(ARM64_جوڑو_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_جوڑو_TPREL_LO12, addend);
        o(ARM64_جوڑو_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#اگر_غیر_تعریف_شدہ TCC_ہدف_PE /* no elf-style GOT on Windows */
    } ورنہ اگر (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_صفحہ, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        اگر (addend > 0xffffff) {
            صحیح t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_جوڑو_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } ورنہ {
           اگر (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_جوڑو_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            اگر (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_جوڑو_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#اگر_ختم
    } ورنہ {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_جوڑو_ABS_LO12_NC, addend);
        o(ARM64_جوڑو_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

ساکن خالی arm64_بھرو_cmp(صحیح r, SValue *sv);

ST_FUNC خالی بھرو(صحیح r, SValue *sv)
{
    صحیح svtt = sv->type.t;
    صحیح svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    صحیح svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    صحیح sb = !(svtt & VT_UNSIGNED);
    صحیح sz = arm64_type_سائز(svtt);

    اگر (svr == (VT_LOCAL | VT_LVAL)) {
        اگر (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        ورنہ
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        واپس;
    }

    اگر (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        اگر (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        ورنہ
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        واپس;
    }

    اگر (svrv < VT_CONST && (svr & VT_LVAL)) {
        اگر (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        ورنہ
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        واپس;
    }

    اگر (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t نقاب = arm64_check_انحراف(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~نقاب);
        اگر (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & نقاب);
        ورنہ
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & نقاب);
        واپس;
    }

    اگر (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        واپس;
    }

    اگر (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        واپس;
    }

    اگر (svr < VT_CONST) {
        اگر (IS_FREG(r) && IS_FREG(svr))
            اگر (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            ورنہ
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        ورنہ اگر (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        ورنہ
            أكد(0);
      واپس;
    }

    اگر (svr == VT_LOCAL) {
        اگر (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        ورنہ {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        واپس;
    }

    اگر (svr == VT_JMP || svr == VT_JMPI) {
        صحیح t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        واپس;
    }

    اگر (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        اگر (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        ورنہ
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        واپس;
    }

    اگر (svr == VT_CMP) {
        arm64_بھرو_cmp(r, sv);
        واپس;
    }

    لکھو("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (طویل)svcul);
    أكد(0);
}

ST_FUNC خالی store(صحیح r, SValue *sv)
{
    صحیح svtt = sv->type.t;
    صحیح svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    صحیح svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    صحیح sz = arm64_type_سائز(svtt);

    اگر (svr == (VT_LOCAL | VT_LVAL)) {
        اگر (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        ورنہ
            arm64_strx(sz, intr(r), 29, svcoff);
        واپس;
    }

    اگر (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        اگر (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        ورنہ
            arm64_strx(sz, intr(r), 30, 0);
        واپس;
    }

    اگر (svrv < VT_CONST && (svr & VT_LVAL)) {
        اگر (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        ورنہ
            arm64_strx(sz, intr(r), intr(svrv), 0);
        واپس;
    }

    اگر (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t نقاب = arm64_check_انحراف(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~نقاب);
        اگر (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & نقاب);
        ورنہ
            arm64_strx(sz, intr(r), 30, svcoff & نقاب);
        واپس;
    }

    لکھو("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (طویل)svcoff);
    أكد(0);
}

ساکن خالی arm64_gen_bl_or_b(صحیح b)
{
    اگر ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    ورنہ {
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#اگر_ختم
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#اگر defined CONFIG_TCC_BCHECK || defined TCC_ہدف_PE
ساکن خالی gen_static_call(صحیح v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#اگر_ختم

#اگر defined(CONFIG_TCC_BCHECK)
ساکن خالی gen_bounds_prolog(خالی)
{
    /* leave some room for bound checking code */
    func_bound_انحراف = lbounds_section->ڈیٹا_انحراف;
    func_bound_ind = ind;
    func_bound_جوڑو_epilog = 0;
    o(ARM64_NOP);  /* nop -> mov x0, lbound section pointer */
    o(ARM64_NOP);
    o(ARM64_NOP);
    o(ARM64_NOP);  /* nop -> call __bound_local_new */
}

ساکن خالی gen_bounds_epilog(خالی)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ڈیٹا;
    صحیح انحراف_modified = func_bound_انحراف != lbounds_section->ڈیٹا_انحراف;

    اگر (!انحراف_modified && !func_bound_جوڑو_epilog)
        واپس;

    /* add end of table info */
    bounds_ptr = section_ptr_جوڑو(lbounds_section, حجم(addr_t));
    *bounds_ptr = 0;

    sym_ڈیٹا = get_sym_ref(&char_اشارہ_گر_type, lbounds_section,
                           func_bound_انحراف, PTR_سائز);

    /* generate bound local allocation */
    اگر (انحراف_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        arm64_sym(0, sym_ڈیٹا, 0);
        gen_static_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0xa9bf07e0); /* stp x0, x1, [sp, #-16]! */
    o(0x3c9f0fe0); /* str q0, [sp, #-16]! */
    arm64_sym(0, sym_ڈیٹا, 0);
    gen_static_call(TOK___bound_local_delete);
    o(0x3cc107e0); /* ldr q0, [sp], #16 */
    o(0xa8c107e0); /* ldp x0, x1, [sp], #16 */
}
#اگر_ختم

ساکن صحیح arm64_hfa_aux(CType *type, صحیح *fsize, صحیح عدد)
{
    اگر (is_float(type->t)) {
        صحیح a, n = type_سائز(type, &a);
        اگر (عدد >= 4 || (*fsize && *fsize != n))
            واپس -1;
        *fsize = n;
        واپس عدد + 1;
    }
    ورنہ اگر ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *میدان;
        اگر (!IS_UNION(type->t)) {
            صحیح num0 = عدد;
            برائے (میدان = type->ref->اگلا; میدان; میدان = میدان->اگلا) {
                اگر (میدان->c != (عدد - num0) * *fsize)
                    واپس -1;
                عدد = arm64_hfa_aux(&میدان->type, fsize, عدد);
                اگر (عدد == -1)
                    واپس -1;
            }
            اگر (type->ref->c != (عدد - num0) * *fsize)
                واپس -1;
            واپس عدد;
        }
        ورنہ { // union
            صحیح num0 = عدد;
            برائے (میدان = type->ref->اگلا; میدان; میدان = میدان->اگلا) {
                صحیح num1 = arm64_hfa_aux(&میدان->type, fsize, num0);
                اگر (num1 == -1)
                    واپس -1;
                عدد = num1 < عدد ? عدد : num1;
            }
            اگر (type->ref->c != (عدد - num0) * *fsize)
                واپس -1;
            واپس عدد;
        }
    }
    ورنہ اگر (type->t & VT_ARRAY) { /* handle float array within struct */
        صحیح num1;
        اگر (!type->ref->c)
            واپس عدد;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, عدد);
        اگر (num1 == -1 || (num1 != عدد && type->ref->c > 4))
            واپس -1;
        num1 = عدد + type->ref->c * (num1 - عدد);
        اگر (num1 > 4)
            واپس -1;
        واپس num1;
    }
    واپس -1;
}

ساکن صحیح arm64_hfa(CType *type, غیرعلامتی *fsize)
{
    اگر ((type->t & VT_BTYPE) == VT_STRUCT) {
        صحیح sz = 0;
        صحیح n = arm64_hfa_aux(type, &sz, 0);
        اگر (0 < n && n <= 4) {
            اگر (fsize)
                *fsize = sz;
            واپس n;
        }
    }
    واپس 0;
}

ساکن غیرعلامتی طویل arm64_pcs_aux(صحیح variadic, صحیح n, CType **type, غیرعلامتی طویل *a)
{
    صحیح nx = 0; // next integer register
    صحیح nv = 0; // next vector register
    غیرعلامتی طویل ns = 32; // next stack offset
    صحیح i;

    برائے (i = 0; i < n; i++) {
        صحیح hfa = arm64_hfa(type[i], 0);
        صحیح سائز, align, bt;

        bt = type[i]->t & VT_BTYPE;
        اگر (bt == VT_PTR || bt == VT_FUNC)
            سائز = align = 8;
        ورنہ
            سائز = type_سائز(type[i], &align);

#اگر defined(TCC_ہدف_MACHO)
        اگر (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#وگرنہ_اگر defined(TCC_ہدف_PE)
        اگر (variadic && i >= variadic) {
            hfa = 0;
            اگر (is_float(bt))
                bt = VT_INT, سائز = align = 8;
        }
#اگر_ختم
        اگر (hfa)
            // B.2
            ;
        ورنہ اگر (سائز > 16) {
            // B.3: replace with pointer
            اگر (nx < 8)
                a[i] = nx++ << 1 | 1;
            ورنہ {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            جاری;
        }
        ورنہ اگر (bt == VT_STRUCT)
            // B.4
            سائز = (سائز + 7) & ~7;

        // C.1
        اگر (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            جاری;
        }

        // C.2
        اگر (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            جاری;
        }

        // C.3
        اگر (hfa) {
            nv = 8;
            سائز = (سائز + 7) & ~7;
        }

        // C.4
        اگر (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        اگر (bt == VT_FLOAT)
            سائز = 8;

        // C.6
        اگر (hfa || is_float(bt)) {
            a[i] = ns;
            ns += سائز;
            جاری;
        }

        // C.7
        اگر (bt != VT_STRUCT && سائز <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            جاری;
        }

        // C.8
        اگر (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        اگر (bt != VT_STRUCT && سائز == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            جاری;
        }

        // C.10
        اگر (bt == VT_STRUCT && سائز <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (سائز + 7) >> 3;
            جاری;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        اگر (bt == VT_STRUCT) {
            a[i] = ns;
            ns += سائز;
            جاری;
        }

        // C.14
        اگر (سائز < 8)
            سائز = 8;

        // C.15
        a[i] = ns;
        ns += سائز;
    }

    واپس ns - 32;
}

ساکن غیرعلامتی طویل arm64_pcs(صحیح variadic, صحیح n, CType **type, غیرعلامتی طویل *a)
{
    غیرعلامتی طویل ڈھیر;

    // Return type:
    اگر ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    ورنہ {
        arm64_pcs_aux(0, 1, type, a);
        أكد(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    ڈھیر = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    اگر (0) {
        صحیح i;
        برائے (i = 0; i < n; i++) {
            اگر (!i)
                لکھو("arm64_pcs return: ");
            ورنہ
                لکھو("arm64_pcs arg %d: ", i);
            اگر (a[i] == (غیرعلامتی طویل)-1)
                لکھو("void\n");
            ورنہ اگر (a[i] == 1 && !i)
                لکھو("X8 pointer\n");
            ورنہ اگر (a[i] < 16)
                لکھو("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            ورنہ اگر (a[i] < 32)
                لکھو("V%lu\n", a[i] / 2 - 8);
            ورنہ
                لکھو("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    واپس ڈھیر;
}

ساکن صحیح n_func_دلائل(CType *type)
{
    صحیح n_دلائل = 0;
    Sym *arg;

    برائے (arg = type->ref->اگلا; arg; arg = arg->اگلا)
        n_دلائل++;
    واپس n_دلائل;
}

ساکن خالی arm64_sub_sp(uint64_t diff)
{
    اگر (!diff)
        واپس;
#اگر_تعریف_شدہ TCC_ہدف_PE
    اگر (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        واپس;
    }
#اگر_ختم
    اگر (!(diff >> 24)) {
        اگر (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        اگر (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } ورنہ {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

ساکن صحیح gv_addr(صحیح r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    واپس gv(r);
}

ST_FUNC خالی gfunc_call(صحیح nb_دلائل)
{
    CType *return_type;
    CType **t;
    غیرعلامتی طویل *a, *a1;
    غیرعلامتی طویل ڈھیر;
    صحیح i;
    صحیح func_type = vtop[-nb_دلائل].type.ref->f.func_type;
    صحیح variadic = (func_type == FUNC_ELLIPSIS);
    صحیح old_style = (func_type == FUNC_OLD);
    صحیح var_nb_arg = variadic ? n_func_دلائل(&vtop[-nb_دلائل].type) : 0;

    save_regs(nb_دلائل + 1);

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gbound_دلائل(nb_دلائل);
#اگر_ختم

    return_type = &vtop[-nb_دلائل].type.ref->type;
    اگر ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_دلائل;

    t = tcc_malloc((nb_دلائل + 1) * حجم(*t));
    a = tcc_malloc((nb_دلائل + 1) * حجم(*a));
    a1 = tcc_malloc((nb_دلائل + 1) * حجم(*a1));

    t[0] = return_type;
    برائے (i = 0; i < nb_دلائل; i++)
        t[nb_دلائل - i] = &vtop[-i].type;

    ڈھیر = arm64_pcs(
#اگر_تعریف_شدہ TCC_ہدف_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#اگر_ختم
        var_nb_arg, nb_دلائل + 1, t, a);

    // Allocate space for structs replaced by pointer:
    برائے (i = nb_دلائل; i; i--)
        اگر (a[i] & 1) {
            SValue *arg = &vtop[i - nb_دلائل];
            صحیح align, سائز = type_سائز(&arg->type, &align);
            أكد((arg->type.t & VT_BTYPE) == VT_STRUCT);
            ڈھیر = (ڈھیر + align - 1) & -align;
            a1[i] = ڈھیر;
            ڈھیر += سائز;
        }

    ڈھیر = (ڈھیر + 15) >> 4 << 4;

    اگر (ڈھیر >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", ڈھیر);
    arm64_sub_sp(ڈھیر);

    // First pass: set all values on stack
    برائے (i = nb_دلائل; i; i--) {
        vpushv(vtop - nb_دلائل + i);

        اگر (a[i] & 1) {
            // struct replaced by pointer
            صحیح r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            اگر (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        ورنہ اگر (a[i] >= 32) {
            // value on stack
            اگر ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                صحیح r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            ورنہ اگر (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_سائز(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            ورنہ {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    برائے (i = nb_دلائل; i; i--, vtop--) {
        اگر (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            اگر ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                اگر ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                ورنہ
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            ورنہ اگر ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                صحیح align, سائز = type_سائز(&vtop->type, &align);
                اگر (سائز) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, سائز);
                }
            }
            ورنہ
                gv(RC_R(a[i] / 2));
        }
        ورنہ اگر (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        ورنہ اگر (a[i] < 32) {
            // value in floating-point registers
            اگر ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                اگر (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    برائے (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } ورنہ {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            ورنہ
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    اگر ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        اگر (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        ورنہ
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    اگر (ڈھیر & 0xfff)
        o(0x910003ff | (ڈھیر & 0xfff) << 10); // add sp,sp,#(n)
    اگر (ڈھیر >> 12)
        o(0x914003ff | (ڈھیر >> 12) << 10);

    {
        صحیح rt = return_type->t;
        صحیح bt = rt & VT_BTYPE;
        اگر (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            اگر (a[0] == 0) {
                صحیح align, سائز = type_سائز(return_type, &align);
                أكد(سائز <= 16);
                اگر (سائز > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                ورنہ اگر (سائز)
                    arm64_strx(سائز > 4 ? 3 : سائز > 2 ? 2 : سائز > 1, 0, 8, 0);

            }
            ورنہ اگر (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                برائے (j = 0; j < n; j++)
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

ساکن غیرعلامتی طویل arm64_func_va_list_ڈھیر;
ساکن صحیح arm64_func_va_list_gr_offs;
ساکن صحیح arm64_func_va_list_vr_offs;
ساکن صحیح arm64_func_sub_sp_انحراف;

ساکن غیرعلامتی arm64_func_آغاز_انحراف;
#تعریف_کرو ARM64_FUNC_ڈھیر_تیاری_SLOTS 6

#اگر_تعریف_شدہ TCC_ہدف_PE
ساکن غیرعلامتی طویل arm64_pe_param_off(غیرعلامتی طویل a)
{
    واپس a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#اگر_ختم

ST_FUNC خالی gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    صحیح n = 0;
    صحیح i = 0;
    Sym *sym;
    CType **t;
    غیرعلامتی طویل *a;
    صحیح use_x8 = 0;
    صحیح آخری_int = 0;
    صحیح آخری_float = 0;
    صحیح variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    صحیح var_nb_arg = variadic ? n_func_دلائل(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    برائے (sym = func_type->ref; sym; sym = sym->اگلا)
        ++n;

#اگر_تعریف_شدہ TCC_ہدف_PE
    n += variadic;
#اگر_ختم

    t = tcc_malloc(n * حجم(*t));
    a = tcc_malloc(n * حجم(*a));
    برائے (sym = func_type->ref; sym; sym = sym->اگلا)
        t[i++] = &sym->type;

#اگر_تعریف_شدہ TCC_ہدف_PE
    اگر (variadic)
        t[i] = &int_type;
#اگر_ختم

    arm64_func_va_list_ڈھیر = arm64_pcs(var_nb_arg, n, t, a);

#اگر_تعریف_شدہ TCC_ہدف_PE
    اگر (variadic)
        arm64_func_va_list_ڈھیر = arm64_pe_param_off(a[n - 1]);
#اگر_ختم

#اگر !defined(TCC_ہدف_MACHO)
    اگر (variadic) {
        use_x8 = 1;
        آخری_int = 4;
        آخری_float = 4;
    }
#اگر_ختم

    اگر (a && a[0] == 1)
        use_x8 = 1;
    برائے (i = 1, sym = func_type->ref->اگلا; sym; i++, sym = sym->اگلا) {
        اگر (a[i] < 16) {
            صحیح آخری, align, سائز = type_سائز(&sym->type, &align);
	    آخری = a[i] / 4 + 1 + (سائز - 1) / 8;
	    آخری_int = آخری > آخری_int ? آخری : آخری_int;
	}
        ورنہ اگر (a[i] < 32) {
            صحیح آخری, hfa = arm64_hfa(&sym->type, 0);
	    آخری = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    آخری_float = آخری > آخری_float ? آخری : آخری_float;
	}
    }

    آخری_int = آخری_int > 4 ? 4 : آخری_int;
    آخری_float = آخری_float > 4 ? 4 : آخری_float;

    arm64_func_آغاز_انحراف = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    برائے (i = 0; i < آخری_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    اگر (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    برائے (i = 0; i < آخری_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    برائے (i = 1, sym = func_type->ref->اگلا; sym; i++, sym = sym->اگلا) {
        صحیح off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_سیٹ_param(sym, off, a[i] & 1);

        اگر (a[i] < 16) {
            صحیح align, سائز = type_سائز(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && سائز > 8)) * 8;
        }
        ورنہ اگر (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        اگر (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            اگر (k > 0 && sz < 16)
                برائے (j = 0; j < k; j++) {
                    o(0x3d0003e0 | -(sz & 8) << 27 | (sz & 4) << 29 |
                      ((a[i] - 16) / 2 + j) | (off / sz + j) << 10);
                    // str ([sdq])(j),[sp,#(j * sz)]
                }
        }
    }

    tcc_free(a);
    tcc_free(t);

    arm64_func_sub_sp_انحراف = ind;
    /* In gfunc_epilog these will be replaced with stack setup code. */
    برائے (i = 0; i < ARM64_FUNC_ڈھیر_تیاری_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#اگر_ختم
}

ST_FUNC خالی gen_va_آغاز(خالی)
{
    صحیح r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#اگر_تعریف_شدہ TCC_ہدف_PE
    اگر (arm64_func_va_list_ڈھیر) {
        arm64_movimm(30, arm64_func_va_list_ڈھیر);
        o(0x8b1e03be); // add x30,x29,x30
    } ورنہ
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#ورنہ
    اگر (arm64_func_va_list_ڈھیر) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_ڈھیر + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    ورنہ
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#اگر !defined(TCC_ہدف_MACHO)
    اگر (arm64_func_va_list_gr_offs) {
        اگر (arm64_func_va_list_ڈھیر)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    اگر (arm64_func_va_list_vr_offs) {
        o(0x910243be); // add x30,x29,#144
        o(0xf900081e | r << 5); // str x30,[x(r),#16]
    }

    arm64_movimm(30, arm64_func_va_list_gr_offs);
    o(0xb900181e | r << 5); // str w30,[x(r),#24]

    arm64_movimm(30, arm64_func_va_list_vr_offs);
    o(0xb9001c1e | r << 5); // str w30,[x(r),#28]
#اگر_ختم
#اگر_ختم

    --vtop;
}

ST_FUNC خالی gen_va_arg(CType *t)
{
    صحیح align, سائز = type_سائز(t, &align);
    uint32_t r0, r1;

#اگر_تعریف_شدہ TCC_ہدف_PE
    صحیح بالواسطہ = 0, خانہ = (سائز + 7) & -8;

    اگر (سائز > 16)
        بالواسطہ = 1, خانہ = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    اگر (خانہ) {
        اگر (خانہ == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        اگر (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | خانہ << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    اگر (بالواسطہ)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#ورنہ /* !PE */
    غیرعلامتی fsize = سائز, hfa = 1;

    اگر (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    اگر (!hfa) {
        uint32_t n = سائز > 16 ? 8 : (سائز + 7) & -8;

#اگر !defined(TCC_ہدف_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        اگر (align == 16) {
            أكد(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#اگر_ختم

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        اگر (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#اگر !defined(TCC_ہدف_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#اگر_ختم

        اگر (سائز > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    ورنہ {
        uint32_t ssz = (سائز + 7) & -(uint32_t)8;
#اگر !defined(TCC_ہدف_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#اگر_ختم
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        اگر (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#اگر !defined(TCC_ہدف_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_متن_section->ڈیٹا + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        اگر (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        ورنہ {
            // We need to change the layout of this HFA.
            // Get some space on the stack using global variable "loc":
            loc = (loc - سائز) & -(uint32_t)align;
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
        write32le(cur_متن_section->ڈیٹا + b2, ARM64_B | ((ind - b2) >> 2));
#اگر_ختم
    }
#اگر_ختم /* not pe */
}

ST_FUNC صحیح gfunc_sret(CType *vt, صحیح variadic, CType *ret,
                       صحیح *align, صحیح *regsize)
{
    واپس 0;
}

ST_FUNC خالی gfunc_return(CType *func_type)
{
    CType *t = func_type;
    غیرعلامتی طویل a;

    arm64_pcs(0, 1, &t, &a);

    انتخاب (a) {
    حالت -1:
        توڑو;
    حالت 0:
        اگر ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            صحیح align, سائز = type_سائز(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, سائز);
        }
        ورنہ
            gv(RC_IRET);
        توڑو;
    حالت 1: {
        CType type = *func_type;
        mk_اشارہ_گر(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        توڑو;
    }
    حالت 16:
        اگر ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          برائے (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        ورنہ
            gv(RC_FRET);
        توڑو;
    طےشدہ:
      أكد(0);
    }
    vtop--;
}

ST_FUNC خالی gfunc_epilog(خالی)
{
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#اگر_ختم

    اگر (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        صحیح i;
        addr_t saved_ind = ind;
        addr_t patch_انتہا = arm64_func_sub_sp_انحراف + ARM64_FUNC_ڈھیر_تیاری_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_انحراف;
        arm64_sub_sp(diff);
        برائے (i = ind; i < patch_انتہا; i += 4)
            write32le(cur_متن_section->ڈیٹا + i, ARM64_NOP); // nop
        ind = saved_ind;
    }
    o(0x910003bf); // mov sp,x29
    o(0xa8ce7bfd); // ldp x29,x30,[sp],#224

    o(0xd65f03c0); // ret

#اگر_تعریف_شدہ TCC_ہدف_PE
    pe_جوڑو_unwind_ڈیٹا(arm64_func_آغاز_انحراف, ind, -loc);
#اگر_ختم
}

ST_FUNC خالی gen_fill_nops(صحیح بائٹیں)
{
    اگر ((بائٹیں & 3))
      tcc_error("alignment of code section not multiple of 4");
    جب (بائٹیں > 0) {
	o(ARM64_NOP); // nop
	بائٹیں -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC صحیح gjmp(صحیح t)
{
    صحیح r = ind;
    اگر (nocode_wanted)
        واپس t;
    o(t);
    واپس r;
}

// Generate branch to known address:
ST_FUNC خالی gjmp_addr(صحیح a)
{
    أكد(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC صحیح gjmp_append(صحیح n, صحیح t)
{
    خالی *p;
    /* insert vtop->c jump list in t */
    اگر (n) {
        uint32_t n1 = n, n2;
        جب ((n2 = read32le(p = cur_متن_section->ڈیٹا + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    واپس t;
}

خالی arm64_vset_VT_CMP(صحیح op)
{
    اگر (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

ساکن خالی arm64_gen_opil(صحیح op, uint32_t l);

ساکن خالی arm64_بھرو_cmp(صحیح r, SValue *sv)
{
    sv->r = sv->cmp_r;
    اگر (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    اگر (r != sv->r) {
        بھرو(r, sv);
        sv->r = r;
    }
}

ST_FUNC صحیح gjmp_cond(صحیح op, صحیح t)
{
    صحیح bt = vtop->type.t & VT_BTYPE;

    صحیح inv = op & 1;
    vtop->r = vtop->cmp_r;

    اگر (bt == VT_LDOUBLE) {
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
    ورنہ اگر (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    ورنہ {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    واپس gjmp(t);
}

ساکن صحیح arm64_iconst(uint64_t *val, SValue *sv)
{
    اگر ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        واپس 0;
    اگر (val) {
        صحیح t = sv->type.t;
	صحیح bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    واپس 1;
}

ساکن صحیح arm64_gen_opic(صحیح op, uint32_t l, صحیح rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    اگر (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    انتخاب (op) {

    حالت '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        اگر (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        ورنہ اگر (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        ورنہ {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        واپس 1;
      }

    حالت '-':
        اگر (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        ورنہ اگر (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        ورنہ {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        واپس 1;

    حالت '^':
        اگر (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            واپس 1;
        }
        // fall through
    حالت '&':
    حالت '|': {
        صحیح e = arm64_encode_bimm64(l ? val : val | val << 32);
        اگر (e < 0)
            واپس 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        واپس 1;
    }

    حالت TOK_SAR:
    حالت TOK_SHL:
    حالت TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        اگر (rev)
            واپس 0;
        اگر (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            واپس 1;
        }
        ورنہ اگر (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        ورنہ
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        واپس 1;
    }

    }
    واپس 0;
}

ساکن خالی arm64_gen_opil(صحیح op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        صحیح rev = 1;

        اگر (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        اگر (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            اگر (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                واپس;
            }
        }
        اگر (!rev)
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

    انتخاب (op) {
    حالت '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        توڑو;
    حالت '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        توڑو;
    حالت '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        توڑو;
    حالت '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        توڑو;
    حالت '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        توڑو;
    حالت '/':
    حالت TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        توڑو;
    حالت '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        توڑو;
    حالت '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        توڑو;
    حالت TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        توڑو;
    حالت TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        توڑو;
    حالت TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        توڑو;
    حالت TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        توڑو;
    حالت TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        توڑو;
    حالت TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        توڑو;
    حالت TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        توڑو;
    حالت TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        توڑو;
    حالت TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        توڑو;
    حالت TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        توڑو;
    حالت TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        توڑو;
    حالت TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        توڑو;
    حالت TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        توڑو;
    حالت TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        توڑو;
    حالت TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        توڑو;
    طےشدہ:
        أكد(0);
    }
}

ST_FUNC خالی gen_opi(صحیح op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC خالی gen_opl(صحیح op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC خالی gen_opf(صحیح op)
{
    uint32_t x, a, b, dbl;
    صحیح bt = vtop[0].type.t & VT_BTYPE;

    اگر (op == TOK_NEG) {
        اگر (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } ورنہ {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        واپس;
    }

    اگر (bt == VT_LDOUBLE) {
        CType type = vtop[0].type;
        صحیح func = 0;
        صحیح cond = -1;
        انتخاب (op) {
        حالت '*': func = TOK___multf3; توڑو;
        حالت '+': func = TOK___addtf3; توڑو;
        حالت '-': func = TOK___subtf3; توڑو;
        حالت '/': func = TOK___divtf3; توڑو;
        حالت TOK_EQ: func = TOK___eqtf2; cond = 1; توڑو;
        حالت TOK_NE: func = TOK___netf2; cond = 0; توڑو;
        حالت TOK_LT: func = TOK___lttf2; cond = 10; توڑو;
        حالت TOK_GE: func = TOK___getf2; cond = 11; توڑو;
        حالت TOK_LE: func = TOK___letf2; cond = 12; توڑو;
        حالت TOK_GT: func = TOK___gttf2; cond = 13; توڑو;
        طےشدہ: أكد(0); توڑو;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        اگر (cond < 0)
            vtop->type = type;
        ورنہ {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        واپس;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    أكد(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    انتخاب (op) {
    حالت TOK_EQ: حالت TOK_NE:
    حالت TOK_LT: حالت TOK_GE: حالت TOK_LE: حالت TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        توڑو;
    طےشدہ:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        توڑو;
    }

    انتخاب (op) {
    حالت '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        توڑو;
    حالت '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        توڑو;
    حالت '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        توڑو;
    حالت '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        توڑو;
    حالت TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        توڑو;
    حالت TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        توڑو;
    حالت TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        توڑو;
    حالت TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        توڑو;
    حالت TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        توڑو;
    حالت TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        توڑو;
    طےشدہ:
        أكد(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC خالی gen_cvt_sxtw(خالی)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC خالی gen_cvt_csti(صحیح t)
{
    صحیح r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC خالی gen_cvt_itof(صحیح t)
{
    اگر (t == VT_LDOUBLE) {
        صحیح f = vtop->type.t;
        صحیح func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        واپس;
    }
    ورنہ {
        صحیح d, n = intr(gv(RC_INT));
        صحیح s = !(vtop->type.t & VT_UNSIGNED);
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

ST_FUNC خالی gen_cvt_ftoi(صحیح t)
{
    اگر ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        صحیح func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        واپس;
    }
    ورنہ {
        صحیح d, n = fltr(gv(RC_FLOAT));
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

ST_FUNC خالی gen_cvt_ftof(صحیح t)
{
    صحیح f = vtop[0].type.t & VT_BTYPE;
    أكد(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    أكد(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    اگر (t == f)
        واپس;

    اگر (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        صحیح func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    ورنہ {
        صحیح x, a;
        gv(RC_FLOAT);
        أكد(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        اگر (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        ورنہ
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC خالی gen_increment_tcov (SValue *sv)
{
    صحیح r1, r2;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    arm64_sym(r1, sv->sym, 0);
    o(ARM64_LDR_X | ARM64_RN(intr(r1)) | intr(r2)); // ldr r2, [r1]
    o(0x91000400 | (intr(r2)<<5) | intr(r2)); // add r2, r2, #1
    o(0xf9000000 | (intr(r1)<<5) | intr(r2)); // str r2, [r1]
    vpop();
}

ST_FUNC خالی ggoto(خالی)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC خالی gen_clear_cache(خالی)
{
    uint32_t beg, انتہا, dsz, isz, p, lab1, b1;
    gv2(RC_INT, RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    beg = intr(vtop[-4].r); // x0
    انتہا = intr(vtop[-3].r); // x1
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
    write32le(cur_متن_section->ڈیٹا + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | انتہا << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0x51000400 | p | isz << 5); // sub w(p),w(isz),#1
    o(0x8a240004 | p | beg << 5 | p << 16); // bic x(p),x(beg),x(p)
    b1 = ind; o(ARM64_B); // b
    lab1 = ind;
    o(0xd50b7520 | p); // ic ivau,x(p)
    o(0x8b000000 | p | p << 5 | isz << 16); // add x(p),x(p),x(isz)
    write32le(cur_متن_section->ڈیٹا + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | انتہا << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0xd5033fdf); // isb
}

ST_FUNC خالی gen_vla_sp_save(صحیح addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC خالی gen_vla_sp_restore(صحیح addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC خالی gen_vla_alloc(CType *type, صحیح align) {
    uint32_t r;
#اگر defined(CONFIG_TCC_BCHECK)
    اگر (tcc_state->do_bounds_check)
        vpushv(vtop);
#اگر_ختم
    r = intr(gv(RC_INT));
#اگر defined(CONFIG_TCC_BCHECK)
    اگر (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    ورنہ
#اگر_ختم
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#اگر defined(CONFIG_TCC_BCHECK)
    اگر (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x910003e0 | vtop->r); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_جوڑو_epilog = 1;
    }
#اگر_ختم
}

/* end of A64 code generator */
/*************************************************************/
#اگر_ختم
/*************************************************************/
