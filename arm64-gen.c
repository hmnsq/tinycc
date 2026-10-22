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

#जर !defined(TCC_TARGET_MACHO) && !defined(TCC_TARGET_PE)
#define CHAR_IS_UNSIGNED
#endif

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#define PROMOTE_RET
/******************************************************/
#अन्यथा /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#अन्तर्भाव "tcc.h"
#अन्तर्भाव <assert.h>

ST_DATA स्थिरांक अक्षर * स्थिरांक target_machine_defs =
    "__aarch64__\0"
#जर defined(TCC_TARGET_MACHO)
    "__arm64__\0"
#endif
    "__AARCH64EL__\0"
    ;

ST_DATA स्थिरांक पूर्णांक reg_classes[NB_REGS] = {
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

#जर defined(CONFIG_TCC_BCHECK)
स्थिर addr_t func_bound_offset;
स्थिर अचिन्हित दीर्घ func_bound_ind;
ST_DATA पूर्णांक func_bound_add_epilog;
#endif

#define IS_FREG(x) ((x) >= TREG_F(0))

स्थिर uint32_t intr(पूर्णांक r)
{
    प्रतिज्ञा(TREG_R(0) <= r && r <= TREG_R30);
    परत r < TREG_R30 ? r : 30;
}

स्थिर uint32_t fltr(पूर्णांक r)
{
    प्रतिज्ञा(TREG_F(0) <= r && r <= TREG_F(7));
    परत r - TREG_F(0);
}

// Add an instruction to text section:
ST_FUNC शून्य o(अचिन्हित पूर्णांक c)
{
    पूर्णांक ind1 = ind + 4;
    जर (nocode_wanted)
        परत;
    जर (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    write32le(cur_text_section->data + ind, c);
    ind = ind1;
}

स्थिर पूर्णांक arm64_encode_bimm64(uint64_t x)
{
    पूर्णांक neg = x & 1;
    पूर्णांक rep, pos, len;

    जर (neg)
        x = ~x;
    जर (!x)
        परत -1;

    जर (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    अन्यथा जर (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    अन्यथा जर (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    अन्यथा जर (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    अन्यथा जर (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    अन्यथा
        rep = 64;

    pos = 0;
    जर (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    जर (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    जर (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    जर (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    जर (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    जर (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    जर (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    जर (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    जर (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    जर (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    जर (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    जर (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    जर (x)
        परत -1;
    जर (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    परत ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

स्थिर uint32_t arm64_movi(पूर्णांक r, uint64_t x)
{
    uint64_t m = 0xffff;
    पूर्णांक e;
    जर (!(x & ~m))
        परत ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    जर (!(x & ~(m << 16)))
        परत (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    जर (!(x & ~(m << 32)))
        परत (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    जर (!(x & ~(m << 48)))
        परत (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    जर ((x & ~m) == m << 16)
        परत (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    जर ((x & ~(m << 16)) == m)
        परत (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    जर (!~(x | m))
        परत (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    जर (!~(x | m << 16))
        परत (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    जर (!~(x | m << 32))
        परत (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    जर (!~(x | m << 48))
        परत (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    जर (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        परत (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    जर ((e = arm64_encode_bimm64(x)) >= 0)
        परत (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    परत 0;
}

स्थिर शून्य arm64_movimm(पूर्णांक r, uint64_t x)
{
    uint32_t i;
    जर ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    अन्यथा {
        // MOVZ/MOVN and 1-3 MOVKs
        पूर्णांक z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        साठी (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        जर (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        साठी (i = 0; i < 64; i += 16)
            जर (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                थांबा;
            }
        साठी (i += 16; i < 64; i += 16)
            जर (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC शून्य gsym_addr(पूर्णांक t_, पूर्णांक a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    पर्यंत (t) {
        अचिन्हित अक्षर *ptr = cur_text_section->data + t;
        uint32_t next = read32le(ptr);
        जर (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = next;
    }
}

स्थिर पूर्णांक arm64_type_size(पूर्णांक t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    निवड (t & VT_BTYPE) {
    स्थिती VT_BYTE: परत 0;
    स्थिती VT_SHORT: परत 1;
    स्थिती VT_INT: परत 2;
    स्थिती VT_LLONG: परत 3;
    स्थिती VT_PTR: परत 3;
    स्थिती VT_FUNC: परत 3;
    स्थिती VT_STRUCT: परत 3;
    स्थिती VT_FLOAT: परत 2;
    स्थिती VT_DOUBLE: परत 3;
    स्थिती VT_LDOUBLE: परत 4;
    स्थिती VT_BOOL: परत 0;
    }
    प्रतिज्ञा(0);
    परत 0;
}

स्थिर शून्य arm64_spoff(पूर्णांक reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    जर (sub)
        off = -off;
    जर (off < 4096)
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    अन्यथा {
        arm64_movimm(30, off);
        o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

स्थिर uint64_t arm64_check_offset(पूर्णांक sz_, uint64_t off)
{
#ifndef TCC_TARGET_PE
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    जर (!(off & ~scaled_mask) || (off < 256 || -off <= 256))
        परत ~0ull;
    जर (off & scaled_mask)
        परत scaled_mask;
    जर (off & 0x1fful)
        परत 0x1fful;
#endif
    परत 0;
}

स्थिर शून्य arm64_ldrx(पूर्णांक sg, पूर्णांक sz_, पूर्णांक dst, पूर्णांक bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    जर (sz >= 2)
        sg = 0;
    जर (!(off & ~scaled_mask))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    अन्यथा जर (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    अन्यथा {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

स्थिर शून्य arm64_ldrv(पूर्णांक sz_, पूर्णांक dst, पूर्णांक bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    जर (!(off & ~scaled_mask))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    अन्यथा जर (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    अन्यथा {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

स्थिर शून्य arm64_ldrs(पूर्णांक reg_, पूर्णांक size)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    निवड (size) {
    पूर्वनिर्धारित: प्रतिज्ञा(0); थांबा;
    स्थिती 0:
        /* Can happen with zero size structs */
        थांबा;
    स्थिती 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        थांबा;
    स्थिती 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        थांबा;
    स्थिती 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        थांबा;
    स्थिती 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        थांबा;
    स्थिती 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        थांबा;
    स्थिती 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        थांबा;
    स्थिती 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        थांबा;
    स्थिती 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        थांबा;
    स्थिती 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        थांबा;
    स्थिती 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        थांबा;
    स्थिती 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        थांबा;
    स्थिती 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        थांबा;
    स्थिती 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        थांबा;
    स्थिती 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        थांबा;
    स्थिती 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        थांबा;
    स्थिती 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        थांबा;
    }
}

स्थिर शून्य arm64_strx(पूर्णांक sz_, पूर्णांक dst, पूर्णांक bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    जर (!(off & ~scaled_mask))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    अन्यथा जर (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    अन्यथा {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

स्थिर शून्य arm64_strv(पूर्णांक sz_, पूर्णांक dst, पूर्णांक bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    जर (!(off & ~scaled_mask))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    अन्यथा जर (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    अन्यथा {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

स्थिर शून्य arm64_reloca(Sym *sym, पूर्णांक reloc_type, uint64_t addend)
{
    greloca(cur_text_section, sym, ind, reloc_type, addend);
}

स्थिर शून्य arm64_sym(पूर्णांक r, Sym *sym, addr_t addend)
{
    जर (sym->type.t & VT_TLS) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        पूर्णांक r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#अन्यथा
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#endif
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_HI12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_LO12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#ifndef TCC_TARGET_PE /* no elf-style GOT on Windows */
    } अन्यथा जर (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_PAGE, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        जर (addend > 0xffffff) {
            पूर्णांक t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } अन्यथा {
           जर (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_ADD_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            जर (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#endif
    } अन्यथा {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_ADD_ABS_LO12_NC, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

स्थिर शून्य arm64_load_cmp(पूर्णांक r, SValue *sv);

ST_FUNC शून्य load(पूर्णांक r, SValue *sv)
{
    पूर्णांक svtt = sv->type.t;
    पूर्णांक svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    पूर्णांक svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    पूर्णांक sb = !(svtt & VT_UNSIGNED);
    पूर्णांक sz = arm64_type_size(svtt);

    जर (svr == (VT_LOCAL | VT_LVAL)) {
        जर (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        अन्यथा
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        परत;
    }

    जर (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        जर (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        अन्यथा
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        परत;
    }

    जर (svrv < VT_CONST && (svr & VT_LVAL)) {
        जर (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        अन्यथा
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        परत;
    }

    जर (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        जर (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & mask);
        अन्यथा
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & mask);
        परत;
    }

    जर (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        परत;
    }

    जर (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        परत;
    }

    जर (svr < VT_CONST) {
        जर (IS_FREG(r) && IS_FREG(svr))
            जर (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            अन्यथा
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        अन्यथा जर (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        अन्यथा
            प्रतिज्ञा(0);
      परत;
    }

    जर (svr == VT_LOCAL) {
        जर (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        अन्यथा {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        परत;
    }

    जर (svr == VT_JMP || svr == VT_JMPI) {
        पूर्णांक t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        परत;
    }

    जर (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        जर (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        अन्यथा
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        परत;
    }

    जर (svr == VT_CMP) {
        arm64_load_cmp(r, sv);
        परत;
    }

    म_लिखो("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (दीर्घ)svcul);
    प्रतिज्ञा(0);
}

ST_FUNC शून्य store(पूर्णांक r, SValue *sv)
{
    पूर्णांक svtt = sv->type.t;
    पूर्णांक svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    पूर्णांक svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    पूर्णांक sz = arm64_type_size(svtt);

    जर (svr == (VT_LOCAL | VT_LVAL)) {
        जर (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        अन्यथा
            arm64_strx(sz, intr(r), 29, svcoff);
        परत;
    }

    जर (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        जर (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        अन्यथा
            arm64_strx(sz, intr(r), 30, 0);
        परत;
    }

    जर (svrv < VT_CONST && (svr & VT_LVAL)) {
        जर (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        अन्यथा
            arm64_strx(sz, intr(r), intr(svrv), 0);
        परत;
    }

    जर (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        जर (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & mask);
        अन्यथा
            arm64_strx(sz, intr(r), 30, svcoff & mask);
        परत;
    }

    म_लिखो("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (दीर्घ)svcoff);
    प्रतिज्ञा(0);
}

स्थिर शून्य arm64_gen_bl_or_b(पूर्णांक b)
{
    जर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    अन्यथा {
#ifdef CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#endif
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#जर defined CONFIG_TCC_BCHECK || defined TCC_TARGET_PE
स्थिर शून्य gen_static_call(पूर्णांक v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#endif

#जर defined(CONFIG_TCC_BCHECK)
स्थिर शून्य gen_bounds_prolog(शून्य)
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

स्थिर शून्य gen_bounds_epilog(शून्य)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    पूर्णांक offset_modified = func_bound_offset != lbounds_section->data_offset;

    जर (!offset_modified && !func_bound_add_epilog)
        परत;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, आकार(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    जर (offset_modified) {
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

स्थिर पूर्णांक arm64_hfa_aux(CType *type, पूर्णांक *fsize, पूर्णांक अंक)
{
    जर (is_float(type->t)) {
        पूर्णांक a, n = type_size(type, &a);
        जर (अंक >= 4 || (*fsize && *fsize != n))
            परत -1;
        *fsize = n;
        परत अंक + 1;
    }
    अन्यथा जर ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field;
        जर (!IS_UNION(type->t)) {
            पूर्णांक num0 = अंक;
            साठी (field = type->ref->next; field; field = field->next) {
                जर (field->c != (अंक - num0) * *fsize)
                    परत -1;
                अंक = arm64_hfa_aux(&field->type, fsize, अंक);
                जर (अंक == -1)
                    परत -1;
            }
            जर (type->ref->c != (अंक - num0) * *fsize)
                परत -1;
            परत अंक;
        }
        अन्यथा { // union
            पूर्णांक num0 = अंक;
            साठी (field = type->ref->next; field; field = field->next) {
                पूर्णांक num1 = arm64_hfa_aux(&field->type, fsize, num0);
                जर (num1 == -1)
                    परत -1;
                अंक = num1 < अंक ? अंक : num1;
            }
            जर (type->ref->c != (अंक - num0) * *fsize)
                परत -1;
            परत अंक;
        }
    }
    अन्यथा जर (type->t & VT_ARRAY) { /* handle float array within struct */
        पूर्णांक num1;
        जर (!type->ref->c)
            परत अंक;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, अंक);
        जर (num1 == -1 || (num1 != अंक && type->ref->c > 4))
            परत -1;
        num1 = अंक + type->ref->c * (num1 - अंक);
        जर (num1 > 4)
            परत -1;
        परत num1;
    }
    परत -1;
}

स्थिर पूर्णांक arm64_hfa(CType *type, अचिन्हित *fsize)
{
    जर ((type->t & VT_BTYPE) == VT_STRUCT) {
        पूर्णांक sz = 0;
        पूर्णांक n = arm64_hfa_aux(type, &sz, 0);
        जर (0 < n && n <= 4) {
            जर (fsize)
                *fsize = sz;
            परत n;
        }
    }
    परत 0;
}

स्थिर अचिन्हित दीर्घ arm64_pcs_aux(पूर्णांक variadic, पूर्णांक n, CType **type, अचिन्हित दीर्घ *a)
{
    पूर्णांक nx = 0; // next integer register
    पूर्णांक nv = 0; // next vector register
    अचिन्हित दीर्घ ns = 32; // next stack offset
    पूर्णांक i;

    साठी (i = 0; i < n; i++) {
        पूर्णांक hfa = arm64_hfa(type[i], 0);
        पूर्णांक size, align, bt;

        bt = type[i]->t & VT_BTYPE;
        जर (bt == VT_PTR || bt == VT_FUNC)
            size = align = 8;
        अन्यथा
            size = type_size(type[i], &align);

#जर defined(TCC_TARGET_MACHO)
        जर (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#किंवाजर defined(TCC_TARGET_PE)
        जर (variadic && i >= variadic) {
            hfa = 0;
            जर (is_float(bt))
                bt = VT_INT, size = align = 8;
        }
#endif
        जर (hfa)
            // B.2
            ;
        अन्यथा जर (size > 16) {
            // B.3: replace with pointer
            जर (nx < 8)
                a[i] = nx++ << 1 | 1;
            अन्यथा {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            सुरूठेवा;
        }
        अन्यथा जर (bt == VT_STRUCT)
            // B.4
            size = (size + 7) & ~7;

        // C.1
        जर (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            सुरूठेवा;
        }

        // C.2
        जर (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            सुरूठेवा;
        }

        // C.3
        जर (hfa) {
            nv = 8;
            size = (size + 7) & ~7;
        }

        // C.4
        जर (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        जर (bt == VT_FLOAT)
            size = 8;

        // C.6
        जर (hfa || is_float(bt)) {
            a[i] = ns;
            ns += size;
            सुरूठेवा;
        }

        // C.7
        जर (bt != VT_STRUCT && size <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            सुरूठेवा;
        }

        // C.8
        जर (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        जर (bt != VT_STRUCT && size == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            सुरूठेवा;
        }

        // C.10
        जर (bt == VT_STRUCT && size <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (size + 7) >> 3;
            सुरूठेवा;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        जर (bt == VT_STRUCT) {
            a[i] = ns;
            ns += size;
            सुरूठेवा;
        }

        // C.14
        जर (size < 8)
            size = 8;

        // C.15
        a[i] = ns;
        ns += size;
    }

    परत ns - 32;
}

स्थिर अचिन्हित दीर्घ arm64_pcs(पूर्णांक variadic, पूर्णांक n, CType **type, अचिन्हित दीर्घ *a)
{
    अचिन्हित दीर्घ चळत;

    // Return type:
    जर ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    अन्यथा {
        arm64_pcs_aux(0, 1, type, a);
        प्रतिज्ञा(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    चळत = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    जर (0) {
        पूर्णांक i;
        साठी (i = 0; i < n; i++) {
            जर (!i)
                म_लिखो("arm64_pcs return: ");
            अन्यथा
                म_लिखो("arm64_pcs arg %d: ", i);
            जर (a[i] == (अचिन्हित दीर्घ)-1)
                म_लिखो("void\n");
            अन्यथा जर (a[i] == 1 && !i)
                म_लिखो("X8 pointer\n");
            अन्यथा जर (a[i] < 16)
                म_लिखो("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            अन्यथा जर (a[i] < 32)
                म_लिखो("V%lu\n", a[i] / 2 - 8);
            अन्यथा
                म_लिखो("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    परत चळत;
}

स्थिर पूर्णांक n_func_args(CType *type)
{
    पूर्णांक n_args = 0;
    Sym *arg;

    साठी (arg = type->ref->next; arg; arg = arg->next)
        n_args++;
    परत n_args;
}

स्थिर शून्य arm64_sub_sp(uint64_t diff)
{
    जर (!diff)
        परत;
#ifdef TCC_TARGET_PE
    जर (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        परत;
    }
#endif
    जर (!(diff >> 24)) {
        जर (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        जर (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } अन्यथा {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

स्थिर पूर्णांक gv_addr(पूर्णांक r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    परत gv(r);
}

ST_FUNC शून्य gfunc_call(पूर्णांक nb_args)
{
    CType *return_type;
    CType **t;
    अचिन्हित दीर्घ *a, *a1;
    अचिन्हित दीर्घ चळत;
    पूर्णांक i;
    पूर्णांक func_type = vtop[-nb_args].type.ref->f.func_type;
    पूर्णांक variadic = (func_type == FUNC_ELLIPSIS);
    पूर्णांक old_style = (func_type == FUNC_OLD);
    पूर्णांक var_nb_arg = variadic ? n_func_args(&vtop[-nb_args].type) : 0;

    save_regs(nb_args + 1);

#ifdef CONFIG_TCC_BCHECK
    जर (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    return_type = &vtop[-nb_args].type.ref->type;
    जर ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_args;

    t = tcc_malloc((nb_args + 1) * आकार(*t));
    a = tcc_malloc((nb_args + 1) * आकार(*a));
    a1 = tcc_malloc((nb_args + 1) * आकार(*a1));

    t[0] = return_type;
    साठी (i = 0; i < nb_args; i++)
        t[nb_args - i] = &vtop[-i].type;

    चळत = arm64_pcs(
#ifdef TCC_TARGET_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#endif
        var_nb_arg, nb_args + 1, t, a);

    // Allocate space for structs replaced by pointer:
    साठी (i = nb_args; i; i--)
        जर (a[i] & 1) {
            SValue *arg = &vtop[i - nb_args];
            पूर्णांक align, size = type_size(&arg->type, &align);
            प्रतिज्ञा((arg->type.t & VT_BTYPE) == VT_STRUCT);
            चळत = (चळत + align - 1) & -align;
            a1[i] = चळत;
            चळत += size;
        }

    चळत = (चळत + 15) >> 4 << 4;

    जर (चळत >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", चळत);
    arm64_sub_sp(चळत);

    // First pass: set all values on stack
    साठी (i = nb_args; i; i--) {
        vpushv(vtop - nb_args + i);

        जर (a[i] & 1) {
            // struct replaced by pointer
            पूर्णांक r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            जर (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        अन्यथा जर (a[i] >= 32) {
            // value on stack
            जर ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                पूर्णांक r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            अन्यथा जर (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_size(vtop[0].type.t),
                           fltr(vtop[0].r), 31, a[i] - 32);
            }
            अन्यथा {
                gv(RC_INT);
                arm64_strx(3, // arm64_type_size(vtop[0].type.t),
                           intr(vtop[0].r), 31, a[i] - 32);
            }
        }

        --vtop;
    }

    // Second pass: assign values to registers
    साठी (i = nb_args; i; i--, vtop--) {
        जर (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            जर ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                जर ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                अन्यथा
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            अन्यथा जर ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                पूर्णांक align, size = type_size(&vtop->type, &align);
                जर (size) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, size);
                }
            }
            अन्यथा
                gv(RC_R(a[i] / 2));
        }
        अन्यथा जर (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        अन्यथा जर (a[i] < 32) {
            // value in floating-point registers
            जर ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                जर (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    साठी (j = 0; j < n; j++)
                        o(0x3d4003c0 |
                          (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                          (a[i] / 2 - 8 + j) |
                          j << 10); // ldr ([sdq])(*),[x30,#(j * sz)]
                } अन्यथा {
                    /* Non-HFA struct in float register slot - shouldn't happen */
                    gv(RC_F(a[i] / 2 - 8));
                }
            }
            अन्यथा
                gv(RC_F(a[i] / 2 - 8));
        }
    }

    जर ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        जर (a[0] == 1) {
            // indirect return: set x8 and discard the stack value
            gv_addr(RC_R(8));
            --vtop;
        }
        अन्यथा
            // return in registers: keep the address for after the call
            vswap();
    }

    arm64_gen_bl_or_b(0);
    --vtop;
    जर (चळत & 0xfff)
        o(0x910003ff | (चळत & 0xfff) << 10); // add sp,sp,#(n)
    जर (चळत >> 12)
        o(0x914003ff | (चळत >> 12) << 10);

    {
        पूर्णांक rt = return_type->t;
        पूर्णांक bt = rt & VT_BTYPE;
        जर (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            जर (a[0] == 0) {
                पूर्णांक align, size = type_size(return_type, &align);
                प्रतिज्ञा(size <= 16);
                जर (size > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                अन्यथा जर (size)
                    arm64_strx(size > 4 ? 3 : size > 2 ? 2 : size > 1, 0, 8, 0);

            }
            अन्यथा जर (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                साठी (j = 0; j < n; j++)
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

स्थिर अचिन्हित दीर्घ arm64_func_va_list_चळत;
स्थिर पूर्णांक arm64_func_va_list_gr_offs;
स्थिर पूर्णांक arm64_func_va_list_vr_offs;
स्थिर पूर्णांक arm64_func_sub_sp_offset;

स्थिर अचिन्हित arm64_func_start_offset;
#define ARM64_FUNC_चळत_SETUP_SLOTS 6

#ifdef TCC_TARGET_PE
स्थिर अचिन्हित दीर्घ arm64_pe_param_off(अचिन्हित दीर्घ a)
{
    परत a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#endif

ST_FUNC शून्य gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    पूर्णांक n = 0;
    पूर्णांक i = 0;
    Sym *sym;
    CType **t;
    अचिन्हित दीर्घ *a;
    पूर्णांक use_x8 = 0;
    पूर्णांक last_int = 0;
    पूर्णांक last_float = 0;
    पूर्णांक variadic = func_sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    पूर्णांक var_nb_arg = variadic ? n_func_args(&func_sym->type) : 0;

    func_vc = 144; // offset of where x8 is stored

    साठी (sym = func_type->ref; sym; sym = sym->next)
        ++n;

#ifdef TCC_TARGET_PE
    n += variadic;
#endif

    t = tcc_malloc(n * आकार(*t));
    a = tcc_malloc(n * आकार(*a));
    साठी (sym = func_type->ref; sym; sym = sym->next)
        t[i++] = &sym->type;

#ifdef TCC_TARGET_PE
    जर (variadic)
        t[i] = &int_type;
#endif

    arm64_func_va_list_चळत = arm64_pcs(var_nb_arg, n, t, a);

#ifdef TCC_TARGET_PE
    जर (variadic)
        arm64_func_va_list_चळत = arm64_pe_param_off(a[n - 1]);
#endif

#जर !defined(TCC_TARGET_MACHO)
    जर (variadic) {
        use_x8 = 1;
        last_int = 4;
        last_float = 4;
    }
#endif

    जर (a && a[0] == 1)
        use_x8 = 1;
    साठी (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        जर (a[i] < 16) {
            पूर्णांक last, align, size = type_size(&sym->type, &align);
	    last = a[i] / 4 + 1 + (size - 1) / 8;
	    last_int = last > last_int ? last : last_int;
	}
        अन्यथा जर (a[i] < 32) {
            पूर्णांक last, hfa = arm64_hfa(&sym->type, 0);
	    last = a[i] / 4 - 3 + (hfa ? hfa - 1 : 0);
	    last_float = last > last_float ? last : last_float;
	}
    }

    last_int = last_int > 4 ? 4 : last_int;
    last_float = last_float > 4 ? 4 : last_float;

    arm64_func_start_offset = ind;
    o(0xa9b27bfd); // stp x29,x30,[sp,#-224]!
    o(0x910003fd); // mov x29,sp

    साठी (i = 0; i < last_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    जर (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    साठी (i = 0; i < last_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    साठी (i = 1, sym = func_type->ref->next; sym; i++, sym = sym->next) {
        पूर्णांक off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_set_param(sym, off, a[i] & 1);

        जर (a[i] < 16) {
            पूर्णांक align, size = type_size(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && size > 8)) * 8;
        }
        अन्यथा जर (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        जर (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            जर (k > 0 && sz < 16)
                साठी (j = 0; j < k; j++) {
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
    साठी (i = 0; i < ARM64_FUNC_चळत_SETUP_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#ifdef CONFIG_TCC_BCHECK
    जर (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

ST_FUNC शून्य gen_va_start(शून्य)
{
    पूर्णांक r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#ifdef TCC_TARGET_PE
    जर (arm64_func_va_list_चळत) {
        arm64_movimm(30, arm64_func_va_list_चळत);
        o(0x8b1e03be); // add x30,x29,x30
    } अन्यथा
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#अन्यथा
    जर (arm64_func_va_list_चळत) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_चळत + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    अन्यथा
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#जर !defined(TCC_TARGET_MACHO)
    जर (arm64_func_va_list_gr_offs) {
        जर (arm64_func_va_list_चळत)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    जर (arm64_func_va_list_vr_offs) {
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

ST_FUNC शून्य gen_va_arg(CType *t)
{
    पूर्णांक align, size = type_size(t, &align);
    uint32_t r0, r1;

#ifdef TCC_TARGET_PE
    पूर्णांक indirect = 0, slot = (size + 7) & -8;

    जर (size > 16)
        indirect = 1, slot = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    जर (slot) {
        जर (slot == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        जर (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | slot << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    जर (indirect)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#अन्यथा /* !PE */
    अचिन्हित fsize = size, hfa = 1;

    जर (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    जर (!hfa) {
        uint32_t n = size > 16 ? 8 : (size + 7) & -8;

#जर !defined(TCC_TARGET_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        जर (align == 16) {
            प्रतिज्ञा(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#endif

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        जर (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#जर !defined(TCC_TARGET_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#endif

        जर (size > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    अन्यथा {
        uint32_t ssz = (size + 7) & -(uint32_t)8;
#जर !defined(TCC_TARGET_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#endif
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        जर (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#जर !defined(TCC_TARGET_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_text_section->data + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        जर (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        अन्यथा {
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

ST_FUNC पूर्णांक gfunc_sret(CType *vt, पूर्णांक variadic, CType *ret,
                       पूर्णांक *align, पूर्णांक *regsize)
{
    परत 0;
}

ST_FUNC शून्य gfunc_return(CType *func_type)
{
    CType *t = func_type;
    अचिन्हित दीर्घ a;

    arm64_pcs(0, 1, &t, &a);

    निवड (a) {
    स्थिती -1:
        थांबा;
    स्थिती 0:
        जर ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            पूर्णांक align, size = type_size(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, size);
        }
        अन्यथा
            gv(RC_IRET);
        थांबा;
    स्थिती 1: {
        CType type = *func_type;
        mk_pointer(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        थांबा;
    }
    स्थिती 16:
        जर ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          साठी (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        अन्यथा
            gv(RC_FRET);
        थांबा;
    पूर्वनिर्धारित:
      प्रतिज्ञा(0);
    }
    vtop--;
}

ST_FUNC शून्य gfunc_epilog(शून्य)
{
#ifdef CONFIG_TCC_BCHECK
    जर (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    जर (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        पूर्णांक i;
        addr_t saved_ind = ind;
        addr_t patch_end = arm64_func_sub_sp_offset + ARM64_FUNC_चळत_SETUP_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_offset;
        arm64_sub_sp(diff);
        साठी (i = ind; i < patch_end; i += 4)
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

ST_FUNC शून्य gen_fill_nops(पूर्णांक bytes)
{
    जर ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    पर्यंत (bytes > 0) {
	o(ARM64_NOP); // nop
	bytes -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC पूर्णांक gjmp(पूर्णांक t)
{
    पूर्णांक r = ind;
    जर (nocode_wanted)
        परत t;
    o(t);
    परत r;
}

// Generate branch to known address:
ST_FUNC शून्य gjmp_addr(पूर्णांक a)
{
    प्रतिज्ञा(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC पूर्णांक gjmp_append(पूर्णांक n, पूर्णांक t)
{
    शून्य *p;
    /* insert vtop->c jump list in t */
    जर (n) {
        uint32_t n1 = n, n2;
        पर्यंत ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    परत t;
}

शून्य arm64_vset_VT_CMP(पूर्णांक op)
{
    जर (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

स्थिर शून्य arm64_gen_opil(पूर्णांक op, uint32_t l);

स्थिर शून्य arm64_load_cmp(पूर्णांक r, SValue *sv)
{
    sv->r = sv->cmp_r;
    जर (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    जर (r != sv->r) {
        load(r, sv);
        sv->r = r;
    }
}

ST_FUNC पूर्णांक gjmp_cond(पूर्णांक op, पूर्णांक t)
{
    पूर्णांक bt = vtop->type.t & VT_BTYPE;

    पूर्णांक inv = op & 1;
    vtop->r = vtop->cmp_r;

    जर (bt == VT_LDOUBLE) {
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
    अन्यथा जर (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    अन्यथा {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    परत gjmp(t);
}

स्थिर पूर्णांक arm64_iconst(uint64_t *val, SValue *sv)
{
    जर ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        परत 0;
    जर (val) {
        पूर्णांक t = sv->type.t;
	पूर्णांक bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    परत 1;
}

स्थिर पूर्णांक arm64_gen_opic(पूर्णांक op, uint32_t l, पूर्णांक rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    जर (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    निवड (op) {

    स्थिती '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        जर (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        अन्यथा जर (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        अन्यथा {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        परत 1;
      }

    स्थिती '-':
        जर (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        अन्यथा जर (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        अन्यथा {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        परत 1;

    स्थिती '^':
        जर (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            परत 1;
        }
        // fall through
    स्थिती '&':
    स्थिती '|': {
        पूर्णांक e = arm64_encode_bimm64(l ? val : val | val << 32);
        जर (e < 0)
            परत 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        परत 1;
    }

    स्थिती TOK_SAR:
    स्थिती TOK_SHL:
    स्थिती TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        जर (rev)
            परत 0;
        जर (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            परत 1;
        }
        अन्यथा जर (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        अन्यथा
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        परत 1;
    }

    }
    परत 0;
}

स्थिर शून्य arm64_gen_opil(पूर्णांक op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        पूर्णांक rev = 1;

        जर (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        जर (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            जर (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                परत;
            }
        }
        जर (!rev)
            vswap();
    }

    gv2(RC_INT, RC_INT);
    प्रतिज्ञा(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = intr(vtop[-1].r);
    b = intr(vtop[0].r);
    vtop -= 2;
    x = get_reg(RC_INT);
    ++vtop;
    vtop[0].r = x;
    x = intr(x);

    निवड (op) {
    स्थिती '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        थांबा;
    स्थिती '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        थांबा;
    स्थिती '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        थांबा;
    स्थिती '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        थांबा;
    स्थिती '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        थांबा;
    स्थिती '/':
    स्थिती TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        थांबा;
    स्थिती '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        थांबा;
    स्थिती '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        थांबा;
    स्थिती TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        थांबा;
    स्थिती TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        थांबा;
    स्थिती TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        थांबा;
    स्थिती TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        थांबा;
    स्थिती TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        थांबा;
    स्थिती TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        थांबा;
    स्थिती TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        थांबा;
    स्थिती TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        थांबा;
    स्थिती TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        थांबा;
    स्थिती TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        थांबा;
    स्थिती TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        थांबा;
    स्थिती TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        थांबा;
    स्थिती TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        थांबा;
    स्थिती TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        थांबा;
    स्थिती TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        थांबा;
    पूर्वनिर्धारित:
        प्रतिज्ञा(0);
    }
}

ST_FUNC शून्य gen_opi(पूर्णांक op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC शून्य gen_opl(पूर्णांक op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC शून्य gen_opf(पूर्णांक op)
{
    uint32_t x, a, b, dbl;
    पूर्णांक bt = vtop[0].type.t & VT_BTYPE;

    जर (op == TOK_NEG) {
        जर (bt == VT_LDOUBLE) {
            vpush_helper_func(TOK___negtf2);
            vrott(2);
            gfunc_call(1);
            vpushi(0);
            vtop->type.t = bt;
            vtop->r = REG_FRET;
        } अन्यथा {
            gv(RC_FLOAT);
            dbl = bt == VT_DOUBLE;
            a = fltr(vtop[0].r);
            o(0x1e214000 | dbl << 22 | a | a << 5);
        }
        परत;
    }

    जर (bt == VT_LDOUBLE) {
        CType type = vtop[0].type;
        पूर्णांक func = 0;
        पूर्णांक cond = -1;
        निवड (op) {
        स्थिती '*': func = TOK___multf3; थांबा;
        स्थिती '+': func = TOK___addtf3; थांबा;
        स्थिती '-': func = TOK___subtf3; थांबा;
        स्थिती '/': func = TOK___divtf3; थांबा;
        स्थिती TOK_EQ: func = TOK___eqtf2; cond = 1; थांबा;
        स्थिती TOK_NE: func = TOK___netf2; cond = 0; थांबा;
        स्थिती TOK_LT: func = TOK___lttf2; cond = 10; थांबा;
        स्थिती TOK_GE: func = TOK___getf2; cond = 11; थांबा;
        स्थिती TOK_LE: func = TOK___letf2; cond = 12; थांबा;
        स्थिती TOK_GT: func = TOK___gttf2; cond = 13; थांबा;
        पूर्वनिर्धारित: प्रतिज्ञा(0); थांबा;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        जर (cond < 0)
            vtop->type = type;
        अन्यथा {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        परत;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    प्रतिज्ञा(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    निवड (op) {
    स्थिती TOK_EQ: स्थिती TOK_NE:
    स्थिती TOK_LT: स्थिती TOK_GE: स्थिती TOK_LE: स्थिती TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        थांबा;
    पूर्वनिर्धारित:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        थांबा;
    }

    निवड (op) {
    स्थिती '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        थांबा;
    स्थिती '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        थांबा;
    स्थिती '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        थांबा;
    स्थिती '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        थांबा;
    स्थिती TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        थांबा;
    स्थिती TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        थांबा;
    स्थिती TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        थांबा;
    स्थिती TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        थांबा;
    स्थिती TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        थांबा;
    स्थिती TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        थांबा;
    पूर्वनिर्धारित:
        प्रतिज्ञा(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC शून्य gen_cvt_sxtw(शून्य)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC शून्य gen_cvt_csti(पूर्णांक t)
{
    पूर्णांक r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC शून्य gen_cvt_itof(पूर्णांक t)
{
    जर (t == VT_LDOUBLE) {
        पूर्णांक f = vtop->type.t;
        पूर्णांक func = (f & VT_BTYPE) == VT_LLONG ?
          (f & VT_UNSIGNED ? TOK___floatunditf : TOK___floatditf) :
          (f & VT_UNSIGNED ? TOK___floatunsitf : TOK___floatsitf);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
        परत;
    }
    अन्यथा {
        पूर्णांक d, n = intr(gv(RC_INT));
        पूर्णांक s = !(vtop->type.t & VT_UNSIGNED);
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

ST_FUNC शून्य gen_cvt_ftoi(पूर्णांक t)
{
    जर ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        पूर्णांक func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        परत;
    }
    अन्यथा {
        पूर्णांक d, n = fltr(gv(RC_FLOAT));
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

ST_FUNC शून्य gen_cvt_ftof(पूर्णांक t)
{
    पूर्णांक f = vtop[0].type.t & VT_BTYPE;
    प्रतिज्ञा(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    प्रतिज्ञा(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    जर (t == f)
        परत;

    जर (t == VT_LDOUBLE || f == VT_LDOUBLE) {
        पूर्णांक func = (t == VT_LDOUBLE) ?
            (f == VT_FLOAT ? TOK___extendsftf2 : TOK___extenddftf2) :
            (t == VT_FLOAT ? TOK___trunctfsf2 : TOK___trunctfdf2);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_FRET;
    }
    अन्यथा {
        पूर्णांक x, a;
        gv(RC_FLOAT);
        प्रतिज्ञा(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        जर (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        अन्यथा
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC शून्य gen_increment_tcov (SValue *sv)
{
    पूर्णांक r1, r2;

    vpushv(sv);
    vtop->r = r1 = get_reg(RC_INT);
    r2 = get_reg(RC_INT);
    arm64_sym(r1, sv->sym, 0);
    o(ARM64_LDR_X | ARM64_RN(intr(r1)) | intr(r2)); // ldr r2, [r1]
    o(0x91000400 | (intr(r2)<<5) | intr(r2)); // add r2, r2, #1
    o(0xf9000000 | (intr(r1)<<5) | intr(r2)); // str r2, [r1]
    vpop();
}

ST_FUNC शून्य ggoto(शून्य)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC शून्य gen_clear_cache(शून्य)
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

ST_FUNC शून्य gen_vla_sp_save(पूर्णांक addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC शून्य gen_vla_sp_restore(पूर्णांक addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC शून्य gen_vla_alloc(CType *type, पूर्णांक align) {
    uint32_t r;
#जर defined(CONFIG_TCC_BCHECK)
    जर (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    r = intr(gv(RC_INT));
#जर defined(CONFIG_TCC_BCHECK)
    जर (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    अन्यथा
#endif
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#जर defined(CONFIG_TCC_BCHECK)
    जर (tcc_state->do_bounds_check) {
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
