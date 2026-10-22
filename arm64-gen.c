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

#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

// Number of registers available to allocator:
#నిర్వచించు NB_REGS 28 // x0-x18, x30, v0-v7

#నిర్వచించు TREG_R(x) (x) // x = 0..18
#నిర్వచించు TREG_R30  19
#నిర్వచించు TREG_F(x) (x + 20) // x = 0..7

// Register classes sorted from more general to more precise:
#నిర్వచించు RC_INT (1 << 0)
#నిర్వచించు RC_FLOAT (1 << 1)
#నిర్వచించు RC_R(x) (1 << (2 + (x))) // x = 0..18
#నిర్వచించు RC_R30  (1 << 21)
#నిర్వచించు RC_F(x) (1 << (22 + (x))) // x = 0..7

#నిర్వచించు RC_IRET (RC_R(0)) // int return register class
#నిర్వచించు RC_FRET (RC_F(0)) // float return register class

#నిర్వచించు REG_IRET (TREG_R(0)) // int return register number
#నిర్వచించు REG_FRET (TREG_F(0)) // float return register number

#నిర్వచించు PTR_కొలత 8

#నిర్వచించు LDOUBLE_కొలత 16
#నిర్వచించు LDOUBLE_ALIGN 16

#నిర్వచించు MAX_ALIGN 16

#ఒకవేళ !defined(TCC_లక్ష్యం_MACHO) && !defined(TCC_లక్ష్యం_PE)
#నిర్వచించు CHAR_IS_UNSIGNED
#అయితే_ముగింపు

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#నిర్వచించు PROMOTE_RET
/******************************************************/
#లేకపోతే /* ! TARGET_DEFS_ONLY */
/******************************************************/
#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"
#అన్తర్భావ <assert.h>

ST_దత్తాంశం స్థిరరాశి అక్షరం * స్థిరరాశి లక్ష్యం_machine_defs =
    "__aarch64__\0"
#ఒకవేళ defined(TCC_లక్ష్యం_MACHO)
    "__arm64__\0"
#అయితే_ముగింపు
    "__AARCH64EL__\0"
    ;

ST_దత్తాంశం స్థిరరాశి పూర్ణాంకం reg_classes[NB_REGS] = {
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

#ఒకవేళ defined(CONFIG_TCC_BCHECK)
స్థిర addr_t func_bound_స్థానభ్రంశం;
స్థిర గుర్తులేని దీర్ఘ func_bound_ind;
ST_దత్తాంశం పూర్ణాంకం func_bound_కూడు_epilog;
#అయితే_ముగింపు

#నిర్వచించు IS_FREG(x) ((x) >= TREG_F(0))

స్థిర uint32_t intr(పూర్ణాంకం r)
{
    ప్రతిజ్ఞా(TREG_R(0) <= r && r <= TREG_R30);
    తిరిగి r < TREG_R30 ? r : 30;
}

స్థిర uint32_t fltr(పూర్ణాంకం r)
{
    ప్రతిజ్ఞా(TREG_F(0) <= r && r <= TREG_F(7));
    తిరిగి r - TREG_F(0);
}

// Add an instruction to text section:
ST_FUNC శూన్య o(గుర్తులేని పూర్ణాంకం c)
{
    పూర్ణాంకం ind1 = ind + 4;
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    ఒకవేళ (ind1 > cur_పాఠ్యం_section->దత్తాంశం_allocated)
        section_realloc(cur_పాఠ్యం_section, ind1);
    write32le(cur_పాఠ్యం_section->దత్తాంశం + ind, c);
    ind = ind1;
}

స్థిర పూర్ణాంకం arm64_encode_bimm64(uint64_t x)
{
    పూర్ణాంకం neg = x & 1;
    పూర్ణాంకం rep, pos, len;

    ఒకవేళ (neg)
        x = ~x;
    ఒకవేళ (!x)
        తిరిగి -1;

    ఒకవేళ (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    లేకపోతే ఒకవేళ (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    లేకపోతే ఒకవేళ (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    లేకపోతే ఒకవేళ (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    లేకపోతే ఒకవేళ (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    లేకపోతే
        rep = 64;

    pos = 0;
    ఒకవేళ (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    ఒకవేళ (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    ఒకవేళ (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    ఒకవేళ (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    ఒకవేళ (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    ఒకవేళ (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    ఒకవేళ (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    ఒకవేళ (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    ఒకవేళ (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    ఒకవేళ (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    ఒకవేళ (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    ఒకవేళ (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    ఒకవేళ (x)
        తిరిగి -1;
    ఒకవేళ (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    తిరిగి ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

స్థిర uint32_t arm64_movi(పూర్ణాంకం r, uint64_t x)
{
    uint64_t m = 0xffff;
    పూర్ణాంకం e;
    ఒకవేళ (!(x & ~m))
        తిరిగి ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    ఒకవేళ (!(x & ~(m << 16)))
        తిరిగి (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    ఒకవేళ (!(x & ~(m << 32)))
        తిరిగి (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    ఒకవేళ (!(x & ~(m << 48)))
        తిరిగి (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    ఒకవేళ ((x & ~m) == m << 16)
        తిరిగి (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    ఒకవేళ ((x & ~(m << 16)) == m)
        తిరిగి (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    ఒకవేళ (!~(x | m))
        తిరిగి (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    ఒకవేళ (!~(x | m << 16))
        తిరిగి (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    ఒకవేళ (!~(x | m << 32))
        తిరిగి (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ఒకవేళ (!~(x | m << 48))
        తిరిగి (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    ఒకవేళ (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        తిరిగి (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    ఒకవేళ ((e = arm64_encode_bimm64(x)) >= 0)
        తిరిగి (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    తిరిగి 0;
}

స్థిర శూన్య arm64_movimm(పూర్ణాంకం r, uint64_t x)
{
    uint32_t i;
    ఒకవేళ ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    లేకపోతే {
        // MOVZ/MOVN and 1-3 MOVKs
        పూర్ణాంకం z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        కొరకు (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        ఒకవేళ (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        కొరకు (i = 0; i < 64; i += 16)
            ఒకవేళ (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                ఆపు;
            }
        కొరకు (i += 16; i < 64; i += 16)
            ఒకవేళ (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC శూన్య gsym_addr(పూర్ణాంకం t_, పూర్ణాంకం a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    అయితే (t) {
        గుర్తులేని అక్షరం *ptr = cur_పాఠ్యం_section->దత్తాంశం + t;
        uint32_t తదుపరి = read32le(ptr);
        ఒకవేళ (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = తదుపరి;
    }
}

స్థిర పూర్ణాంకం arm64_type_కొలత(పూర్ణాంకం t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    ఎంపిక (t & VT_BTYPE) {
    స్థితి VT_BYTE: తిరిగి 0;
    స్థితి VT_SHORT: తిరిగి 1;
    స్థితి VT_INT: తిరిగి 2;
    స్థితి VT_LLONG: తిరిగి 3;
    స్థితి VT_PTR: తిరిగి 3;
    స్థితి VT_FUNC: తిరిగి 3;
    స్థితి VT_STRUCT: తిరిగి 3;
    స్థితి VT_FLOAT: తిరిగి 2;
    స్థితి VT_DOUBLE: తిరిగి 3;
    స్థితి VT_LDOUBLE: తిరిగి 4;
    స్థితి VT_BOOL: తిరిగి 0;
    }
    ప్రతిజ్ఞా(0);
    తిరిగి 0;
}

స్థిర శూన్య arm64_spoff(పూర్ణాంకం reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    ఒకవేళ (sub)
        off = -off;
    ఒకవేళ (off < 4096)
        o(ARM64_కూడు_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    లేకపోతే {
        arm64_movimm(30, off);
        o(ARM64_కూడు_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

స్థిర uint64_t arm64_check_స్థానభ్రంశం(పూర్ణాంకం sz_, uint64_t off)
{
#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_PE
    uint32_t sz = sz_;
    uint64_t scaled_ముసుగు = 0xffful << sz;
    ఒకవేళ (!(off & ~scaled_ముసుగు) || (off < 256 || -off <= 256))
        తిరిగి ~0ull;
    ఒకవేళ (off & scaled_ముసుగు)
        తిరిగి scaled_ముసుగు;
    ఒకవేళ (off & 0x1fful)
        తిరిగి 0x1fful;
#అయితే_ముగింపు
    తిరిగి 0;
}

స్థిర శూన్య arm64_ldrx(పూర్ణాంకం sg, పూర్ణాంకం sz_, పూర్ణాంకం dst, పూర్ణాంకం bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ముసుగు = 0xffful << sz;
    ఒకవేళ (sz >= 2)
        sg = 0;
    ఒకవేళ (!(off & ~scaled_ముసుగు))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    లేకపోతే ఒకవేళ (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    లేకపోతే {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

స్థిర శూన్య arm64_ldrv(పూర్ణాంకం sz_, పూర్ణాంకం dst, పూర్ణాంకం bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ముసుగు = 0xffful << sz;

    ఒకవేళ (!(off & ~scaled_ముసుగు))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    లేకపోతే ఒకవేళ (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    లేకపోతే {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

స్థిర శూన్య arm64_ldrs(పూర్ణాంకం reg_, పూర్ణాంకం కొలత)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    ఎంపిక (కొలత) {
    అప్రమేయ: ప్రతిజ్ఞా(0); ఆపు;
    స్థితి 0:
        /* Can happen with zero size structs */
        ఆపు;
    స్థితి 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        ఆపు;
    స్థితి 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        ఆపు;
    స్థితి 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        ఆపు;
    స్థితి 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        ఆపు;
    స్థితి 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ఆపు;
    స్థితి 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ఆపు;
    స్థితి 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        ఆపు;
    స్థితి 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        ఆపు;
    స్థితి 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ఆపు;
    స్థితి 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ఆపు;
    స్థితి 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ఆపు;
    స్థితి 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        ఆపు;
    స్థితి 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        ఆపు;
    స్థితి 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        ఆపు;
    స్థితి 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        ఆపు;
    స్థితి 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        ఆపు;
    }
}

స్థిర శూన్య arm64_strx(పూర్ణాంకం sz_, పూర్ణాంకం dst, పూర్ణాంకం bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ముసుగు = 0xffful << sz;

    ఒకవేళ (!(off & ~scaled_ముసుగు))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    లేకపోతే ఒకవేళ (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    లేకపోతే {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

స్థిర శూన్య arm64_strv(పూర్ణాంకం sz_, పూర్ణాంకం dst, పూర్ణాంకం bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_ముసుగు = 0xffful << sz;

    ఒకవేళ (!(off & ~scaled_ముసుగు))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    లేకపోతే ఒకవేళ (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    లేకపోతే {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

స్థిర శూన్య arm64_reloca(Sym *sym, పూర్ణాంకం reloc_type, uint64_t addend)
{
    greloca(cur_పాఠ్యం_section, sym, ind, reloc_type, addend);
}

స్థిర శూన్య arm64_sym(పూర్ణాంకం r, Sym *sym, addr_t addend)
{
    ఒకవేళ (sym->type.t & VT_TLS) {
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        Sym *s2 = external_global_sym(TOK_tls_సూచీ, &int_type);
        పూర్ణాంకం r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#లేకపోతే
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#అయితే_ముగింపు
        arm64_reloca(sym, R_AARCH64_TLSLE_కూడు_TPREL_HI12, addend);
        o(ARM64_కూడు_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_కూడు_TPREL_LO12, addend);
        o(ARM64_కూడు_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_PE /* no elf-style GOT on Windows */
    } లేకపోతే ఒకవేళ (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_పుట, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        ఒకవేళ (addend > 0xffffff) {
            పూర్ణాంకం t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_కూడు_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } లేకపోతే {
           ఒకవేళ (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_కూడు_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            ఒకవేళ (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_కూడు_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#అయితే_ముగింపు
    } లేకపోతే {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_కూడు_ABS_LO12_NC, addend);
        o(ARM64_కూడు_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

స్థిర శూన్య arm64_ఎక్కించు_cmp(పూర్ణాంకం r, SValue *sv);

ST_FUNC శూన్య ఎక్కించు(పూర్ణాంకం r, SValue *sv)
{
    పూర్ణాంకం svtt = sv->type.t;
    పూర్ణాంకం svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    పూర్ణాంకం svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    పూర్ణాంకం sb = !(svtt & VT_UNSIGNED);
    పూర్ణాంకం sz = arm64_type_కొలత(svtt);

    ఒకవేళ (svr == (VT_LOCAL | VT_LVAL)) {
        ఒకవేళ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        లేకపోతే
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        తిరిగి;
    }

    ఒకవేళ (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        ఒకవేళ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        లేకపోతే
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        తిరిగి;
    }

    ఒకవేళ (svrv < VT_CONST && (svr & VT_LVAL)) {
        ఒకవేళ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        లేకపోతే
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        తిరిగి;
    }

    ఒకవేళ (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t ముసుగు = arm64_check_స్థానభ్రంశం(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~ముసుగు);
        ఒకవేళ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & ముసుగు);
        లేకపోతే
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & ముసుగు);
        తిరిగి;
    }

    ఒకవేళ (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        తిరిగి;
    }

    ఒకవేళ (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        తిరిగి;
    }

    ఒకవేళ (svr < VT_CONST) {
        ఒకవేళ (IS_FREG(r) && IS_FREG(svr))
            ఒకవేళ (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            లేకపోతే
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        లేకపోతే ఒకవేళ (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        లేకపోతే
            ప్రతిజ్ఞా(0);
      తిరిగి;
    }

    ఒకవేళ (svr == VT_LOCAL) {
        ఒకవేళ (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        లేకపోతే {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        తిరిగి;
    }

    ఒకవేళ (svr == VT_JMP || svr == VT_JMPI) {
        పూర్ణాంకం t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        తిరిగి;
    }

    ఒకవేళ (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        ఒకవేళ (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        లేకపోతే
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        తిరిగి;
    }

    ఒకవేళ (svr == VT_CMP) {
        arm64_ఎక్కించు_cmp(r, sv);
        తిరిగి;
    }

    రాయి("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (దీర్ఘ)svcul);
    ప్రతిజ్ఞా(0);
}

ST_FUNC శూన్య store(పూర్ణాంకం r, SValue *sv)
{
    పూర్ణాంకం svtt = sv->type.t;
    పూర్ణాంకం svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    పూర్ణాంకం svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    పూర్ణాంకం sz = arm64_type_కొలత(svtt);

    ఒకవేళ (svr == (VT_LOCAL | VT_LVAL)) {
        ఒకవేళ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        లేకపోతే
            arm64_strx(sz, intr(r), 29, svcoff);
        తిరిగి;
    }

    ఒకవేళ (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        ఒకవేళ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        లేకపోతే
            arm64_strx(sz, intr(r), 30, 0);
        తిరిగి;
    }

    ఒకవేళ (svrv < VT_CONST && (svr & VT_LVAL)) {
        ఒకవేళ (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        లేకపోతే
            arm64_strx(sz, intr(r), intr(svrv), 0);
        తిరిగి;
    }

    ఒకవేళ (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t ముసుగు = arm64_check_స్థానభ్రంశం(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~ముసుగు);
        ఒకవేళ (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & ముసుగు);
        లేకపోతే
            arm64_strx(sz, intr(r), 30, svcoff & ముసుగు);
        తిరిగి;
    }

    రాయి("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (దీర్ఘ)svcoff);
    ప్రతిజ్ఞా(0);
}

స్థిర శూన్య arm64_gen_bl_or_b(పూర్ణాంకం b)
{
    ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    లేకపోతే {
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#అయితే_ముగింపు
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#ఒకవేళ defined CONFIG_TCC_BCHECK || defined TCC_లక్ష్యం_PE
స్థిర శూన్య gen_static_call(పూర్ణాంకం v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#అయితే_ముగింపు

#ఒకవేళ defined(CONFIG_TCC_BCHECK)
స్థిర శూన్య gen_bounds_prolog(శూన్య)
{
    /* leave some room for bound checking code */
    func_bound_స్థానభ్రంశం = lbounds_section->దత్తాంశం_స్థానభ్రంశం;
    func_bound_ind = ind;
    func_bound_కూడు_epilog = 0;
    o(ARM64_NOP);  /* nop -> mov x0, lbound section pointer */
    o(ARM64_NOP);
    o(ARM64_NOP);
    o(ARM64_NOP);  /* nop -> call __bound_local_new */
}

స్థిర శూన్య gen_bounds_epilog(శూన్య)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_దత్తాంశం;
    పూర్ణాంకం స్థానభ్రంశం_modified = func_bound_స్థానభ్రంశం != lbounds_section->దత్తాంశం_స్థానభ్రంశం;

    ఒకవేళ (!స్థానభ్రంశం_modified && !func_bound_కూడు_epilog)
        తిరిగి;

    /* add end of table info */
    bounds_ptr = section_ptr_కూడు(lbounds_section, పరిమాణం(addr_t));
    *bounds_ptr = 0;

    sym_దత్తాంశం = get_sym_ref(&char_సూచిక_type, lbounds_section,
                           func_bound_స్థానభ్రంశం, PTR_కొలత);

    /* generate bound local allocation */
    ఒకవేళ (స్థానభ్రంశం_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        arm64_sym(0, sym_దత్తాంశం, 0);
        gen_static_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0xa9bf07e0); /* stp x0, x1, [sp, #-16]! */
    o(0x3c9f0fe0); /* str q0, [sp, #-16]! */
    arm64_sym(0, sym_దత్తాంశం, 0);
    gen_static_call(TOK___bound_local_delete);
    o(0x3cc107e0); /* ldr q0, [sp], #16 */
    o(0xa8c107e0); /* ldp x0, x1, [sp], #16 */
}
#అయితే_ముగింపు

స్థిర పూర్ణాంకం arm64_hfa_aux(CType *type, పూర్ణాంకం *fsize, పూర్ణాంకం అంకె)
{
    ఒకవేళ (is_float(type->t)) {
        పూర్ణాంకం a, n = type_కొలత(type, &a);
        ఒకవేళ (అంకె >= 4 || (*fsize && *fsize != n))
            తిరిగి -1;
        *fsize = n;
        తిరిగి అంకె + 1;
    }
    లేకపోతే ఒకవేళ ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *క్షేత్రం;
        ఒకవేళ (!IS_UNION(type->t)) {
            పూర్ణాంకం num0 = అంకె;
            కొరకు (క్షేత్రం = type->ref->తదుపరి; క్షేత్రం; క్షేత్రం = క్షేత్రం->తదుపరి) {
                ఒకవేళ (క్షేత్రం->c != (అంకె - num0) * *fsize)
                    తిరిగి -1;
                అంకె = arm64_hfa_aux(&క్షేత్రం->type, fsize, అంకె);
                ఒకవేళ (అంకె == -1)
                    తిరిగి -1;
            }
            ఒకవేళ (type->ref->c != (అంకె - num0) * *fsize)
                తిరిగి -1;
            తిరిగి అంకె;
        }
        లేకపోతే { // union
            పూర్ణాంకం num0 = అంకె;
            కొరకు (క్షేత్రం = type->ref->తదుపరి; క్షేత్రం; క్షేత్రం = క్షేత్రం->తదుపరి) {
                పూర్ణాంకం num1 = arm64_hfa_aux(&క్షేత్రం->type, fsize, num0);
                ఒకవేళ (num1 == -1)
                    తిరిగి -1;
                అంకె = num1 < అంకె ? అంకె : num1;
            }
            ఒకవేళ (type->ref->c != (అంకె - num0) * *fsize)
                తిరిగి -1;
            తిరిగి అంకె;
        }
    }
    లేకపోతే ఒకవేళ (type->t & VT_ARRAY) { /* handle float array within struct */
        పూర్ణాంకం num1;
        ఒకవేళ (!type->ref->c)
            తిరిగి అంకె;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, అంకె);
        ఒకవేళ (num1 == -1 || (num1 != అంకె && type->ref->c > 4))
            తిరిగి -1;
        num1 = అంకె + type->ref->c * (num1 - అంకె);
        ఒకవేళ (num1 > 4)
            తిరిగి -1;
        తిరిగి num1;
    }
    తిరిగి -1;
}

స్థిర పూర్ణాంకం arm64_hfa(CType *type, గుర్తులేని *fsize)
{
    ఒకవేళ ((type->t & VT_BTYPE) == VT_STRUCT) {
        పూర్ణాంకం sz = 0;
        పూర్ణాంకం n = arm64_hfa_aux(type, &sz, 0);
        ఒకవేళ (0 < n && n <= 4) {
            ఒకవేళ (fsize)
                *fsize = sz;
            తిరిగి n;
        }
    }
    తిరిగి 0;
}

స్థిర గుర్తులేని దీర్ఘ arm64_pcs_aux(పూర్ణాంకం variadic, పూర్ణాంకం n, CType **type, గుర్తులేని దీర్ఘ *a)
{
    పూర్ణాంకం nx = 0; // next integer register
    పూర్ణాంకం nv = 0; // next vector register
    గుర్తులేని దీర్ఘ ns = 32; // next stack offset
    పూర్ణాంకం i;

    కొరకు (i = 0; i < n; i++) {
        పూర్ణాంకం hfa = arm64_hfa(type[i], 0);
        పూర్ణాంకం కొలత, align, bt;

        bt = type[i]->t & VT_BTYPE;
        ఒకవేళ (bt == VT_PTR || bt == VT_FUNC)
            కొలత = align = 8;
        లేకపోతే
            కొలత = type_కొలత(type[i], &align);

#ఒకవేళ defined(TCC_లక్ష్యం_MACHO)
        ఒకవేళ (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#లేదావేళ defined(TCC_లక్ష్యం_PE)
        ఒకవేళ (variadic && i >= variadic) {
            hfa = 0;
            ఒకవేళ (is_float(bt))
                bt = VT_INT, కొలత = align = 8;
        }
#అయితే_ముగింపు
        ఒకవేళ (hfa)
            // B.2
            ;
        లేకపోతే ఒకవేళ (కొలత > 16) {
            // B.3: replace with pointer
            ఒకవేళ (nx < 8)
                a[i] = nx++ << 1 | 1;
            లేకపోతే {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            కొనసాగు;
        }
        లేకపోతే ఒకవేళ (bt == VT_STRUCT)
            // B.4
            కొలత = (కొలత + 7) & ~7;

        // C.1
        ఒకవేళ (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            కొనసాగు;
        }

        // C.2
        ఒకవేళ (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            కొనసాగు;
        }

        // C.3
        ఒకవేళ (hfa) {
            nv = 8;
            కొలత = (కొలత + 7) & ~7;
        }

        // C.4
        ఒకవేళ (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        ఒకవేళ (bt == VT_FLOAT)
            కొలత = 8;

        // C.6
        ఒకవేళ (hfa || is_float(bt)) {
            a[i] = ns;
            ns += కొలత;
            కొనసాగు;
        }

        // C.7
        ఒకవేళ (bt != VT_STRUCT && కొలత <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            కొనసాగు;
        }

        // C.8
        ఒకవేళ (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        ఒకవేళ (bt != VT_STRUCT && కొలత == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            కొనసాగు;
        }

        // C.10
        ఒకవేళ (bt == VT_STRUCT && కొలత <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (కొలత + 7) >> 3;
            కొనసాగు;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        ఒకవేళ (bt == VT_STRUCT) {
            a[i] = ns;
            ns += కొలత;
            కొనసాగు;
        }

        // C.14
        ఒకవేళ (కొలత < 8)
            కొలత = 8;

        // C.15
        a[i] = ns;
        ns += కొలత;
    }

    తిరిగి ns - 32;
}

స్థిర గుర్తులేని దీర్ఘ arm64_pcs(పూర్ణాంకం variadic, పూర్ణాంకం n, CType **type, గుర్తులేని దీర్ఘ *a)
{
    గుర్తులేని దీర్ఘ దొంతర;

    // Return type:
    ఒకవేళ ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    లేకపోతే {
        arm64_pcs_aux(0, 1, type, a);
        ప్రతిజ్ఞా(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    దొంతర = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    ఒకవేళ (0) {
        పూర్ణాంకం i;
        కొరకు (i = 0; i < n; i++) {
            ఒకవేళ (!i)
                రాయి("arm64_pcs return: ");
            లేకపోతే
                రాయి("arm64_pcs arg %d: ", i);
            ఒకవేళ (a[i] == (గుర్తులేని దీర్ఘ)-1)
                రాయి("void\n");
            లేకపోతే ఒకవేళ (a[i] == 1 && !i)
                రాయి("X8 pointer\n");
            లేకపోతే ఒకవేళ (a[i] < 16)
                రాయి("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            లేకపోతే ఒకవేళ (a[i] < 32)
                రాయి("V%lu\n", a[i] / 2 - 8);
            లేకపోతే
                రాయి("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    తిరిగి దొంతర;
}

స్థిర పూర్ణాంకం n_func_వాదనలు(CType *type)
{
    పూర్ణాంకం n_వాదనలు = 0;
    Sym *arg;

    కొరకు (arg = type->ref->తదుపరి; arg; arg = arg->తదుపరి)
        n_వాదనలు++;
    తిరిగి n_వాదనలు;
}

స్థిర శూన్య arm64_sub_sp(uint64_t diff)
{
    ఒకవేళ (!diff)
        తిరిగి;
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    ఒకవేళ (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        తిరిగి;
    }
#అయితే_ముగింపు
    ఒకవేళ (!(diff >> 24)) {
        ఒకవేళ (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        ఒకవేళ (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } లేకపోతే {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

స్థిర పూర్ణాంకం gv_addr(పూర్ణాంకం r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    తిరిగి gv(r);
}

ST_FUNC శూన్య gfunc_call(పూర్ణాంకం nb_వాదనలు)
{
    CType *return_type;
    CType **t;
    గుర్తులేని దీర్ఘ *a, *a1;
    గుర్తులేని దీర్ఘ దొంతర;
    పూర్ణాంకం i;
    పూర్ణాంకం func_type = vtop[-nb_వాదనలు].type.ref->f.func_type;
    పూర్ణాంకం variadic = (func_type == FUNC_ELLIPSIS);
    పూర్ణాంకం old_style = (func_type == FUNC_OLD);
    పూర్ణాంకం var_nb_arg = variadic ? n_func_వాదనలు(&vtop[-nb_వాదనలు].type) : 0;

    save_regs(nb_వాదనలు + 1);

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gbound_వాదనలు(nb_వాదనలు);
#అయితే_ముగింపు

    return_type = &vtop[-nb_వాదనలు].type.ref->type;
    ఒకవేళ ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_వాదనలు;

    t = tcc_malloc((nb_వాదనలు + 1) * పరిమాణం(*t));
    a = tcc_malloc((nb_వాదనలు + 1) * పరిమాణం(*a));
    a1 = tcc_malloc((nb_వాదనలు + 1) * పరిమాణం(*a1));

    t[0] = return_type;
    కొరకు (i = 0; i < nb_వాదనలు; i++)
        t[nb_వాదనలు - i] = &vtop[-i].type;

    దొంతర = arm64_pcs(
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#అయితే_ముగింపు
        var_nb_arg, nb_వాదనలు + 1, t, a);

    // Allocate space for structs replaced by pointer:
    కొరకు (i = nb_వాదనలు; i; i--)
        ఒకవేళ (a[i] & 1) {
            SValue *arg = &vtop[i - nb_వాదనలు];
            పూర్ణాంకం align, కొలత = type_కొలత(&arg->type, &align);
            ప్రతిజ్ఞా((arg->type.t & VT_BTYPE) == VT_STRUCT);
            దొంతర = (దొంతర + align - 1) & -align;
            a1[i] = దొంతర;
            దొంతర += కొలత;
        }

    దొంతర = (దొంతర + 15) >> 4 << 4;

    ఒకవేళ (దొంతర >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", దొంతర);
    arm64_sub_sp(దొంతర);

    // First pass: set all values on stack
    కొరకు (i = nb_వాదనలు; i; i--) {
        vpushv(vtop - nb_వాదనలు + i);

        ఒకవేళ (a[i] & 1) {
            // struct replaced by pointer
            పూర్ణాంకం r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            ఒకవేళ (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        లేకపోతే ఒకవేళ (a[i] >= 32) {
            // value on stack
            ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                పూర్ణాంకం r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            లేకపోతే ఒకవేళ (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_కొలత(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            లేకపోతే {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    కొరకు (i = nb_వాదనలు; i; i--, vtop--) {
        ఒకవేళ (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            ఒకవేళ ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                లేకపోతే
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            లేకపోతే ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                పూర్ణాంకం align, కొలత = type_కొలత(&vtop->type, &align);
                ఒకవేళ (కొలత) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, కొలత);
                }
            }
            లేకపోతే
                gv(RC_R(a[i] / 2));
        }
        లేకపోతే ఒకవేళ (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        లేకపోతే ఒకవేళ (a[i] < 32) {
            // value in floating-point registers
            ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                ఒకవేళ (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    కొరకు (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } లేకపోతే {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            లేకపోతే
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    ఒకవేళ ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        ఒకవేళ (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        లేకపోతే
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    ఒకవేళ (దొంతర & 0xfff)
        o(0x910003ff | (దొంతర & 0xfff) << 10); // add sp,sp,#(n)
    ఒకవేళ (దొంతర >> 12)
        o(0x914003ff | (దొంతర >> 12) << 10);

    {
        పూర్ణాంకం rt = return_type->t;
        పూర్ణాంకం bt = rt & VT_BTYPE;
        ఒకవేళ (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            ఒకవేళ (a[0] == 0) {
                పూర్ణాంకం align, కొలత = type_కొలత(return_type, &align);
                ప్రతిజ్ఞా(కొలత <= 16);
                ఒకవేళ (కొలత > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                లేకపోతే ఒకవేళ (కొలత)
                    arm64_strx(కొలత > 4 ? 3 : కొలత > 2 ? 2 : కొలత > 1, 0, 8, 0);

            }
            లేకపోతే ఒకవేళ (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                కొరకు (j = 0; j < n; j++)
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

స్థిర గుర్తులేని దీర్ఘ arm64_func_va_list_దొంతర;
స్థిర పూర్ణాంకం arm64_func_va_list_gr_offs;
స్థిర పూర్ణాంకం arm64_func_va_list_vr_offs;
స్థిర పూర్ణాంకం arm64_func_sub_sp_స్థానభ్రంశం;

స్థిర గుర్తులేని arm64_func_ప్రారంభం_స్థానభ్రంశం;
#నిర్వచించు ARM64_FUNC_దొంతర_అమరిక_SLOTS 6

#నిర్వచితమైతే TCC_లక్ష్యం_PE
స్థిర గుర్తులేని దీర్ఘ arm64_pe_param_off(గుర్తులేని దీర్ఘ a)
{
    తిరిగి a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#అయితే_ముగింపు

ST_FUNC శూన్య gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    పూర్ణాంకం n = 0;
    పూర్ణాంకం i = 0;
    Sym *sym;
    CType **t;
    గుర్తులేని దీర్ఘ *a;
    పూర్ణాంకం use_x8 = 0;
    పూర్ణాంకం చివరి_int = 0;
    పూర్ణాంకం చివరి_float = 0;
    పూర్ణాంకం variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    పూర్ణాంకం var_nb_arg = variadic ? n_func_వాదనలు(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    కొరకు (sym = func_type->ref; sym; sym = sym->తదుపరి)
        ++n;

#నిర్వచితమైతే TCC_లక్ష్యం_PE
    n += variadic;
#అయితే_ముగింపు

    t = tcc_malloc(n * పరిమాణం(*t));
    a = tcc_malloc(n * పరిమాణం(*a));
    కొరకు (sym = func_type->ref; sym; sym = sym->తదుపరి)
        t[i++] = &sym->type;

#నిర్వచితమైతే TCC_లక్ష్యం_PE
    ఒకవేళ (variadic)
        t[i] = &int_type;
#అయితే_ముగింపు

    arm64_func_va_list_దొంతర = arm64_pcs(var_nb_arg, n, t, a);

#నిర్వచితమైతే TCC_లక్ష్యం_PE
    ఒకవేళ (variadic)
        arm64_func_va_list_దొంతర = arm64_pe_param_off(a[n - 1]);
#అయితే_ముగింపు

#ఒకవేళ !defined(TCC_లక్ష్యం_MACHO)
    ఒకవేళ (variadic) {
        use_x8 = 1;
        చివరి_int = 4;
        చివరి_float = 4;
    }
#అయితే_ముగింపు

    ఒకవేళ (a && a[0] == 1)
        use_x8 = 1;
    కొరకు (i = 1, sym = func_type->ref->తదుపరి; sym; i++, sym = sym->తదుపరి) {
        ఒకవేళ (a[i] < 16) {
            పూర్ణాంకం చివరి, align, కొలత = type_కొలత(&sym->type, &align);
	    చివరి = a[i] / 4 + 1 + (కొలత - 1) / 8;
	    చివరి_int = చివరి > చివరి_int ? చివరి : చివరి_int;
	}
        లేకపోతే ఒకవేళ (a[i] < 32) {
            పూర్ణాంకం చివరి, hfa = arm64_hfa(&sym->type, 0);
	    చివరి = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    చివరి_float = చివరి > చివరి_float ? చివరి : చివరి_float;
	}
    }

    చివరి_int = చివరి_int > 4 ? 4 : చివరి_int;
    చివరి_float = చివరి_float > 4 ? 4 : చివరి_float;

    arm64_func_ప్రారంభం_స్థానభ్రంశం = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    కొరకు (i = 0; i < చివరి_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    ఒకవేళ (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    కొరకు (i = 0; i < చివరి_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    కొరకు (i = 1, sym = func_type->ref->తదుపరి; sym; i++, sym = sym->తదుపరి) {
        పూర్ణాంకం off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_సమితి_param(sym, off, a[i] & 1);

        ఒకవేళ (a[i] < 16) {
            పూర్ణాంకం align, కొలత = type_కొలత(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && కొలత > 8)) * 8;
        }
        లేకపోతే ఒకవేళ (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        ఒకవేళ (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            ఒకవేళ (k > 0 && sz < 16)
                కొరకు (j = 0; j < k; j++) {
                    o(0x3d0003e0 | -(sz & 8) << 27 | (sz & 4) << 29 |
                      ((a[i] - 16) / 2 + j) | (off / sz + j) << 10);
                    // str ([sdq])(j),[sp,#(j * sz)]
                }
        }
    }

    tcc_free(a);
    tcc_free(t);

    arm64_func_sub_sp_స్థానభ్రంశం = ind;
    /* In gfunc_epilog these will be replaced with stack setup code. */
    కొరకు (i = 0; i < ARM64_FUNC_దొంతర_అమరిక_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#అయితే_ముగింపు
}

ST_FUNC శూన్య gen_va_ప్రారంభం(శూన్య)
{
    పూర్ణాంకం r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#నిర్వచితమైతే TCC_లక్ష్యం_PE
    ఒకవేళ (arm64_func_va_list_దొంతర) {
        arm64_movimm(30, arm64_func_va_list_దొంతర);
        o(0x8b1e03be); // add x30,x29,x30
    } లేకపోతే
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#లేకపోతే
    ఒకవేళ (arm64_func_va_list_దొంతర) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_దొంతర + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    లేకపోతే
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#ఒకవేళ !defined(TCC_లక్ష్యం_MACHO)
    ఒకవేళ (arm64_func_va_list_gr_offs) {
        ఒకవేళ (arm64_func_va_list_దొంతర)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    ఒకవేళ (arm64_func_va_list_vr_offs) {
        o(0x910243be); // add x30,x29,#144
        o(0xf900081e | r << 5); // str x30,[x(r),#16]
    }

    arm64_movimm(30, arm64_func_va_list_gr_offs);
    o(0xb900181e | r << 5); // str w30,[x(r),#24]

    arm64_movimm(30, arm64_func_va_list_vr_offs);
    o(0xb9001c1e | r << 5); // str w30,[x(r),#28]
#అయితే_ముగింపు
#అయితే_ముగింపు

    --vtop;
}

ST_FUNC శూన్య gen_va_arg(CType *t)
{
    పూర్ణాంకం align, కొలత = type_కొలత(t, &align);
    uint32_t r0, r1;

#నిర్వచితమైతే TCC_లక్ష్యం_PE
    పూర్ణాంకం పరోక్ష = 0, స్థానం = (కొలత + 7) & -8;

    ఒకవేళ (కొలత > 16)
        పరోక్ష = 1, స్థానం = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    ఒకవేళ (స్థానం) {
        ఒకవేళ (స్థానం == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        ఒకవేళ (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | స్థానం << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    ఒకవేళ (పరోక్ష)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#లేకపోతే /* !PE */
    గుర్తులేని fsize = కొలత, hfa = 1;

    ఒకవేళ (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    ఒకవేళ (!hfa) {
        uint32_t n = కొలత > 16 ? 8 : (కొలత + 7) & -8;

#ఒకవేళ !defined(TCC_లక్ష్యం_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        ఒకవేళ (align == 16) {
            ప్రతిజ్ఞా(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#అయితే_ముగింపు

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ఒకవేళ (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#ఒకవేళ !defined(TCC_లక్ష్యం_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#అయితే_ముగింపు

        ఒకవేళ (కొలత > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    లేకపోతే {
        uint32_t ssz = (కొలత + 7) & -(uint32_t)8;
#ఒకవేళ !defined(TCC_లక్ష్యం_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#అయితే_ముగింపు
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        ఒకవేళ (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#ఒకవేళ !defined(TCC_లక్ష్యం_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_పాఠ్యం_section->దత్తాంశం + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        ఒకవేళ (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        లేకపోతే {
            // We need to change the layout of this HFA.
            // Get some space on the stack using global variable "loc":
            loc = (loc - కొలత) & -(uint32_t)align;
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
        write32le(cur_పాఠ్యం_section->దత్తాంశం + b2, ARM64_B | ((ind - b2) >> 2));
#అయితే_ముగింపు
    }
#అయితే_ముగింపు /* not pe */
}

ST_FUNC పూర్ణాంకం gfunc_sret(CType *vt, పూర్ణాంకం variadic, CType *ret,
                       పూర్ణాంకం *align, పూర్ణాంకం *regsize)
{
    తిరిగి 0;
}

ST_FUNC శూన్య gfunc_return(CType *func_type)
{
    CType *t = func_type;
    గుర్తులేని దీర్ఘ a;

    arm64_pcs(0, 1, &t, &a);

    ఎంపిక (a) {
    స్థితి -1:
        ఆపు;
    స్థితి 0:
        ఒకవేళ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            పూర్ణాంకం align, కొలత = type_కొలత(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, కొలత);
        }
        లేకపోతే
            gv(RC_IRET);
        ఆపు;
    స్థితి 1: {
        CType type = *func_type;
        mk_సూచిక(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        ఆపు;
    }
    స్థితి 16:
        ఒకవేళ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          కొరకు (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        లేకపోతే
            gv(RC_FRET);
        ఆపు;
    అప్రమేయ:
      ప్రతిజ్ఞా(0);
    }
    vtop--;
}

ST_FUNC శూన్య gfunc_epilog(శూన్య)
{
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#అయితే_ముగింపు

    ఒకవేళ (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        పూర్ణాంకం i;
        addr_t saved_ind = ind;
        addr_t patch_చివర = arm64_func_sub_sp_స్థానభ్రంశం + ARM64_FUNC_దొంతర_అమరిక_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_స్థానభ్రంశం;
        arm64_sub_sp(diff);
        కొరకు (i = ind; i < patch_చివర; i += 4)
            write32le(cur_పాఠ్యం_section->దత్తాంశం + i, ARM64_NOP); // nop
        ind = saved_ind;
    }
    o(0x910003bf); // mov sp,x29
    o(0xa8ce7bfd); // ldp x29,x30,[sp],#224

    o(0xd65f03c0); // ret

#నిర్వచితమైతే TCC_లక్ష్యం_PE
    pe_కూడు_unwind_దత్తాంశం(arm64_func_ప్రారంభం_స్థానభ్రంశం, ind, -loc);
#అయితే_ముగింపు
}

ST_FUNC శూన్య gen_fill_nops(పూర్ణాంకం బైట్లు)
{
    ఒకవేళ ((బైట్లు & 3))
      tcc_error("alignment of code section not multiple of 4");
    అయితే (బైట్లు > 0) {
	o(ARM64_NOP); // nop
	బైట్లు -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC పూర్ణాంకం gjmp(పూర్ణాంకం t)
{
    పూర్ణాంకం r = ind;
    ఒకవేళ (nocode_wanted)
        తిరిగి t;
    o(t);
    తిరిగి r;
}

// Generate branch to known address:
ST_FUNC శూన్య gjmp_addr(పూర్ణాంకం a)
{
    ప్రతిజ్ఞా(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC పూర్ణాంకం gjmp_append(పూర్ణాంకం n, పూర్ణాంకం t)
{
    శూన్య *p;
    /* insert vtop->c jump list in t */
    ఒకవేళ (n) {
        uint32_t n1 = n, n2;
        అయితే ((n2 = read32le(p = cur_పాఠ్యం_section->దత్తాంశం + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    తిరిగి t;
}

శూన్య arm64_vset_VT_CMP(పూర్ణాంకం op)
{
    ఒకవేళ (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

స్థిర శూన్య arm64_gen_opil(పూర్ణాంకం op, uint32_t l);

స్థిర శూన్య arm64_ఎక్కించు_cmp(పూర్ణాంకం r, SValue *sv)
{
    sv->r = sv->cmp_r;
    ఒకవేళ (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    ఒకవేళ (r != sv->r) {
        ఎక్కించు(r, sv);
        sv->r = r;
    }
}

ST_FUNC పూర్ణాంకం gjmp_cond(పూర్ణాంకం op, పూర్ణాంకం t)
{
    పూర్ణాంకం bt = vtop->type.t & VT_BTYPE;

    పూర్ణాంకం inv = op & 1;
    vtop->r = vtop->cmp_r;

    ఒకవేళ (bt == VT_LDOUBLE) {
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
    లేకపోతే ఒకవేళ (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    లేకపోతే {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    తిరిగి gjmp(t);
}

స్థిర పూర్ణాంకం arm64_iconst(uint64_t *val, SValue *sv)
{
    ఒకవేళ ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        తిరిగి 0;
    ఒకవేళ (val) {
        పూర్ణాంకం t = sv->type.t;
	పూర్ణాంకం bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    తిరిగి 1;
}

స్థిర పూర్ణాంకం arm64_gen_opic(పూర్ణాంకం op, uint32_t l, పూర్ణాంకం rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    ఒకవేళ (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    ఎంపిక (op) {

    స్థితి '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        ఒకవేళ (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        లేకపోతే ఒకవేళ (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        లేకపోతే {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        తిరిగి 1;
      }

    స్థితి '-':
        ఒకవేళ (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        లేకపోతే ఒకవేళ (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        లేకపోతే {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        తిరిగి 1;

    స్థితి '^':
        ఒకవేళ (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            తిరిగి 1;
        }
        // fall through
    స్థితి '&':
    స్థితి '|': {
        పూర్ణాంకం e = arm64_encode_bimm64(l ? val : val | val << 32);
        ఒకవేళ (e < 0)
            తిరిగి 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        తిరిగి 1;
    }

    స్థితి TOK_SAR:
    స్థితి TOK_SHL:
    స్థితి TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        ఒకవేళ (rev)
            తిరిగి 0;
        ఒకవేళ (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            తిరిగి 1;
        }
        లేకపోతే ఒకవేళ (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        లేకపోతే
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        తిరిగి 1;
    }

    }
    తిరిగి 0;
}

స్థిర శూన్య arm64_gen_opil(పూర్ణాంకం op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        పూర్ణాంకం rev = 1;

        ఒకవేళ (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        ఒకవేళ (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            ఒకవేళ (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                తిరిగి;
            }
        }
        ఒకవేళ (!rev)
            vswap();
    }

    gv2(RC_INT, RC_INT);
    ప్రతిజ్ఞా(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = intr(vtop[-1].r);
    b = intr(vtop[0].r);
    vtop -= 2;
    x = get_reg(RC_INT);
    ++vtop;
    vtop[0].r = x;
    x = intr(x);

    ఎంపిక (op) {
    స్థితి '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ఆపు;
    స్థితి '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        ఆపు;
    స్థితి '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        ఆపు;
    స్థితి '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        ఆపు;
    స్థితి '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        ఆపు;
    స్థితి '/':
    స్థితి TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        ఆపు;
    స్థితి '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        ఆపు;
    స్థితి '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        ఆపు;
    స్థితి TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        ఆపు;
    స్థితి TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        ఆపు;
    స్థితి TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        ఆపు;
    స్థితి TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        ఆపు;
    స్థితి TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        ఆపు;
    స్థితి TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        ఆపు;
    స్థితి TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        ఆపు;
    స్థితి TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        ఆపు;
    స్థితి TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        ఆపు;
    స్థితి TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        ఆపు;
    స్థితి TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        ఆపు;
    స్థితి TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        ఆపు;
    స్థితి TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        ఆపు;
    స్థితి TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        ఆపు;
    స్థితి TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        ఆపు;
    అప్రమేయ:
        ప్రతిజ్ఞా(0);
    }
}

ST_FUNC శూన్య gen_opi(పూర్ణాంకం op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC శూన్య gen_opl(పూర్ణాంకం op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC శూన్య gen_opf(పూర్ణాంకం op)
{
    uint32_t x, a, b, dbl;
    పూర్ణాంకం bt = vtop[0].type.t & VT_BTYPE;

    ఒకవేళ (op == TOK_NEG) {
        ఒకవేళ (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } లేకపోతే {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        తిరిగి;
    }

    ఒకవేళ (bt == VT_LDOUBLE) {
        CType type = vtop[0].type;
        పూర్ణాంకం func = 0;
        పూర్ణాంకం cond = -1;
        ఎంపిక (op) {
        స్థితి '*': func = TOK___multf3; ఆపు;
        స్థితి '+': func = TOK___addtf3; ఆపు;
        స్థితి '-': func = TOK___subtf3; ఆపు;
        స్థితి '/': func = TOK___divtf3; ఆపు;
        స్థితి TOK_EQ: func = TOK___eqtf2; cond = 1; ఆపు;
        స్థితి TOK_NE: func = TOK___netf2; cond = 0; ఆపు;
        స్థితి TOK_LT: func = TOK___lttf2; cond = 10; ఆపు;
        స్థితి TOK_GE: func = TOK___getf2; cond = 11; ఆపు;
        స్థితి TOK_LE: func = TOK___letf2; cond = 12; ఆపు;
        స్థితి TOK_GT: func = TOK___gttf2; cond = 13; ఆపు;
        అప్రమేయ: ప్రతిజ్ఞా(0); ఆపు;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        ఒకవేళ (cond < 0)
            vtop->type = type;
        లేకపోతే {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        తిరిగి;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    ప్రతిజ్ఞా(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    ఎంపిక (op) {
    స్థితి TOK_EQ: స్థితి TOK_NE:
    స్థితి TOK_LT: స్థితి TOK_GE: స్థితి TOK_LE: స్థితి TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        ఆపు;
    అప్రమేయ:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        ఆపు;
    }

    ఎంపిక (op) {
    స్థితి '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        ఆపు;
    స్థితి '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        ఆపు;
    స్థితి '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        ఆపు;
    స్థితి '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        ఆపు;
    స్థితి TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        ఆపు;
    స్థితి TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        ఆపు;
    స్థితి TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        ఆపు;
    స్థితి TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        ఆపు;
    స్థితి TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        ఆపు;
    స్థితి TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        ఆపు;
    అప్రమేయ:
        ప్రతిజ్ఞా(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC శూన్య gen_cvt_sxtw(శూన్య)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC శూన్య gen_cvt_csti(పూర్ణాంకం t)
{
    పూర్ణాంకం r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC శూన్య gen_cvt_itof(పూర్ణాంకం t)
{
    ఒకవేళ (t == VT_LDOUBLE) {
        పూర్ణాంకం f = vtop->type.t;
        పూర్ణాంకం func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        తిరిగి;
    }
    లేకపోతే {
        పూర్ణాంకం d, n = intr(gv(RC_INT));
        పూర్ణాంకం s = !(vtop->type.t & VT_UNSIGNED);
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

ST_FUNC శూన్య gen_cvt_ftoi(పూర్ణాంకం t)
{
    ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        పూర్ణాంకం func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        తిరిగి;
    }
    లేకపోతే {
        పూర్ణాంకం d, n = fltr(gv(RC_FLOAT));
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

ST_FUNC శూన్య gen_cvt_ftof(పూర్ణాంకం t)
{
    పూర్ణాంకం f = vtop[0].type.t & VT_BTYPE;
    ప్రతిజ్ఞా(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    ప్రతిజ్ఞా(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    ఒకవేళ (t == f)
        తిరిగి;

    ఒకవేళ (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        పూర్ణాంకం func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    లేకపోతే {
        పూర్ణాంకం x, a;
        gv(RC_FLOAT);
        ప్రతిజ్ఞా(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        ఒకవేళ (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        లేకపోతే
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC శూన్య gen_increment_tcov (SValue *sv)
{
    పూర్ణాంకం r1, r2;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    arm64_sym(r1, sv->sym, 0);
    o(ARM64_LDR_X | ARM64_RN(intr(r1)) | intr(r2)); // ldr r2, [r1]
    o(0x91000400 | (intr(r2)<<5) | intr(r2)); // add r2, r2, #1
    o(0xf9000000 | (intr(r1)<<5) | intr(r2)); // str r2, [r1]
    vpop();
}

ST_FUNC శూన్య ggoto(శూన్య)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC శూన్య gen_clear_cache(శూన్య)
{
    uint32_t beg, చివర, dsz, isz, p, lab1, b1;
    gv2(RC_INT, RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    vpushi(0);
    vtop->r = get_reg(RC_INT);
    beg = intr(vtop[-4].r); // x0
    చివర = intr(vtop[-3].r); // x1
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
    write32le(cur_పాఠ్యం_section->దత్తాంశం + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | చివర << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0x51000400 | p | isz << 5); // sub w(p),w(isz),#1
    o(0x8a240004 | p | beg << 5 | p << 16); // bic x(p),x(beg),x(p)
    b1 = ind; o(ARM64_B); // b
    lab1 = ind;
    o(0xd50b7520 | p); // ic ivau,x(p)
    o(0x8b000000 | p | p << 5 | isz << 16); // add x(p),x(p),x(isz)
    write32le(cur_పాఠ్యం_section->దత్తాంశం + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | చివర << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0xd5033fdf); // isb
}

ST_FUNC శూన్య gen_vla_sp_save(పూర్ణాంకం addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC శూన్య gen_vla_sp_restore(పూర్ణాంకం addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC శూన్య gen_vla_alloc(CType *type, పూర్ణాంకం align) {
    uint32_t r;
#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    ఒకవేళ (tcc_state->do_bounds_check)
        vpushv(vtop);
#అయితే_ముగింపు
    r = intr(gv(RC_INT));
#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    ఒకవేళ (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    లేకపోతే
#అయితే_ముగింపు
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    ఒకవేళ (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x910003e0 | vtop->r); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_కూడు_epilog = 1;
    }
#అయితే_ముగింపు
}

/* end of A64 code generator */
/*************************************************************/
#అయితే_ముగింపు
/*************************************************************/
