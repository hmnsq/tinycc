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

#अगर_घोषित TARGET_DEFS_ONLY

// Number of registers available to allocator:
#घोषणा NB_REGS 28 // x0-x18, x30, v0-v7

#घोषणा TREG_R(x) (x) // x = 0..18
#घोषणा TREG_R30  19
#घोषणा TREG_F(x) (x + 20) // x = 0..7

// Register classes sorted from more general to more precise:
#घोषणा RC_INT (1 << 0)
#घोषणा RC_FLOAT (1 << 1)
#घोषणा RC_R(x) (1 << (2 + (x))) // x = 0..18
#घोषणा RC_R30  (1 << 21)
#घोषणा RC_F(x) (1 << (22 + (x))) // x = 0..7

#घोषणा RC_IRET (RC_R(0)) // int return register class
#घोषणा RC_FRET (RC_F(0)) // float return register class

#घोषणा REG_IRET (TREG_R(0)) // int return register number
#घोषणा REG_FRET (TREG_F(0)) // float return register number

#घोषणा PTR_आकार 8

#घोषणा LDOUBLE_आकार 16
#घोषणा LDOUBLE_ALIGN 16

#घोषणा MAX_ALIGN 16

#अगर !defined(TCC_TARGET_MACHO) && !defined(TCC_TARGET_PE)
#घोषणा CHAR_IS_UNSIGNED
#पूर्ण_अगर

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#घोषणा PROMOTE_RET
/******************************************************/
#अन्यथा /* ! TARGET_DEFS_ONLY */
/******************************************************/
#घोषणा USING_GLOBALS
#समावेश "tcc.h"
#समावेश <assert.h>

ST_तथ्य स्थिर अक्षर * स्थिर target_machine_defs =
    "__aarch64__\0"
#अगर defined(TCC_TARGET_MACHO)
    "__arm64__\0"
#पूर्ण_अगर
    "__AARCH64EL__\0"
    ;

ST_तथ्य स्थिर पूर्णांक reg_classes[NB_REGS] = {
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

#अगर defined(CONFIG_TCC_BCHECK)
अटल addr_t func_bound_offset;
अटल अचिन्हित दीर्घ func_bound_ind;
ST_तथ्य पूर्णांक func_bound_add_epilog;
#पूर्ण_अगर

#घोषणा IS_FREG(x) ((x) >= TREG_F(0))

अटल uint32_t intr(पूर्णांक r)
{
    निश्चित(TREG_R(0) <= r && r <= TREG_R30);
    वापस r < TREG_R30 ? r : 30;
}

अटल uint32_t fltr(पूर्णांक r)
{
    निश्चित(TREG_F(0) <= r && r <= TREG_F(7));
    वापस r - TREG_F(0);
}

// Add an instruction to text section:
ST_FUNC व्योम o(अचिन्हित पूर्णांक c)
{
    पूर्णांक ind1 = ind + 4;
    अगर (nocode_wanted)
        वापस;
    अगर (ind1 > cur_text_section->तथ्य_allocated)
        section_realloc(cur_text_section, ind1);
    write32le(cur_text_section->तथ्य + ind, c);
    ind = ind1;
}

अटल पूर्णांक arm64_encode_bimm64(uint64_t x)
{
    पूर्णांक neg = x & 1;
    पूर्णांक rep, pos, len;

    अगर (neg)
        x = ~x;
    अगर (!x)
        वापस -1;

    अगर (x >> 2 == (x & (((uint64_t)1 << (64 - 2)) - 1)))
        rep = 2, x &= ((uint64_t)1 << 2) - 1;
    अन्यथा अगर (x >> 4 == (x & (((uint64_t)1 << (64 - 4)) - 1)))
        rep = 4, x &= ((uint64_t)1 <<  4) - 1;
    अन्यथा अगर (x >> 8 == (x & (((uint64_t)1 << (64 - 8)) - 1)))
        rep = 8, x &= ((uint64_t)1 <<  8) - 1;
    अन्यथा अगर (x >> 16 == (x & (((uint64_t)1 << (64 - 16)) - 1)))
        rep = 16, x &= ((uint64_t)1 << 16) - 1;
    अन्यथा अगर (x >> 32 == (x & (((uint64_t)1 << (64 - 32)) - 1)))
        rep = 32, x &= ((uint64_t)1 << 32) - 1;
    अन्यथा
        rep = 64;

    pos = 0;
    अगर (!(x & (((uint64_t)1 << 32) - 1))) x >>= 32, pos += 32;
    अगर (!(x & (((uint64_t)1 << 16) - 1))) x >>= 16, pos += 16;
    अगर (!(x & (((uint64_t)1 <<  8) - 1))) x >>= 8, pos += 8;
    अगर (!(x & (((uint64_t)1 <<  4) - 1))) x >>= 4, pos += 4;
    अगर (!(x & (((uint64_t)1 <<  2) - 1))) x >>= 2, pos += 2;
    अगर (!(x & (((uint64_t)1 <<  1) - 1))) x >>= 1, pos += 1;

    len = 0;
    अगर (!(~x & (((uint64_t)1 << 32) - 1))) x >>= 32, len += 32;
    अगर (!(~x & (((uint64_t)1 << 16) - 1))) x >>= 16, len += 16;
    अगर (!(~x & (((uint64_t)1 << 8) - 1))) x >>= 8, len += 8;
    अगर (!(~x & (((uint64_t)1 << 4) - 1))) x >>= 4, len += 4;
    अगर (!(~x & (((uint64_t)1 << 2) - 1))) x >>= 2, len += 2;
    अगर (!(~x & (((uint64_t)1 << 1) - 1))) x >>= 1, len += 1;

    अगर (x)
        वापस -1;
    अगर (neg) {
        pos = (pos + len) & (rep - 1);
        len = rep - len;
    }
    वापस ((0x1000 & rep << 6) | (((rep - 1) ^ 31) << 1 & 63) |
            ((rep - pos) & (rep - 1)) << 6 | (len - 1));
}

अटल uint32_t arm64_movi(पूर्णांक r, uint64_t x)
{
    uint64_t m = 0xffff;
    पूर्णांक e;
    अगर (!(x & ~m))
        वापस ARM64_MOVZ | r | x << 5; // movz w(r),#(x)
    अगर (!(x & ~(m << 16)))
        वापस (ARM64_MOVZ | ARM64_HW(1) | r | x >> 11); // movz w(r),#(x >> 16),lsl #16
    अगर (!(x & ~(m << 32)))
        वापस (ARM64_MOVZ64 | ARM64_HW(2) | r | x >> 27); // movz x(r),#(x >> 32),lsl #32
    अगर (!(x & ~(m << 48)))
        वापस (ARM64_MOVZ64 | ARM64_HW(3) | r | x >> 43); // movz x(r),#(x >> 48),lsl #48
    अगर ((x & ~m) == m << 16)
        वापस (ARM64_MOVN | r |
                (~x << 5 & 0x1fffe0)); // movn w(r),#(~x)
    अगर ((x & ~(m << 16)) == m)
        वापस (ARM64_MOVN | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn w(r),#(~x >> 16),lsl #16
    अगर (!~(x | m))
        वापस (ARM64_MOVN64 | r |
                (~x << 5 & 0x1fffe0)); // movn x(r),#(~x)
    अगर (!~(x | m << 16))
        वापस (ARM64_MOVN64 | ARM64_HW(1) | r |
                (~x >> 11 & 0x1fffe0)); // movn x(r),#(~x >> 16),lsl #16
    अगर (!~(x | m << 32))
        वापस (ARM64_MOVN64 | ARM64_HW(2) | r |
                (~x >> 27 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    अगर (!~(x | m << 48))
        वापस (ARM64_MOVN64 | ARM64_HW(3) | r |
                (~x >> 43 & 0x1fffe0)); // movn x(r),#(~x >> 32),lsl #32
    अगर (!(x >> 32) && (e = arm64_encode_bimm64(x | x << 32)) >= 0)
        वापस (ARM64_ORR_IMM | r | (uint32_t)e << 10); // movi w(r),#(x)
    अगर ((e = arm64_encode_bimm64(x)) >= 0)
        वापस (ARM64_ORR_IMM | ARM64_SF(1) | r | (uint32_t)e << 10); // movi x(r),#(x)
    वापस 0;
}

अटल व्योम arm64_movimm(पूर्णांक r, uint64_t x)
{
    uint32_t i;
    अगर ((i = arm64_movi(r, x)))
        o(i); // a single MOV
    अन्यथा {
        // MOVZ/MOVN and 1-3 MOVKs
        पूर्णांक z = 0, m = 0;
        uint32_t mov1 = ARM64_MOVZ64; // movz
        uint64_t x1 = x;
        क्रम (i = 0; i < 64; i += 16) {
            z += !(x >> i & 0xffff);
            m += !(~x >> i & 0xffff);
        }
        अगर (m > z) {
            x1 = ~x;
            mov1 = ARM64_MOVN64; // movn
        }
        क्रम (i = 0; i < 64; i += 16)
            अगर (x1 >> i & 0xffff) {
                o(mov1 | r | (x1 >> i & 0xffff) << 5 | i << 17);
                // movz/movn x(r),#(*),lsl #(i)
                अवरोध;
            }
        क्रम (i += 16; i < 64; i += 16)
            अगर (x1 >> i & 0xffff)
                o(ARM64_MOVK | ARM64_SF(1) | r | (x >> i & 0xffff) << 5 | i << 17);
                // movk x(r),#(*),lsl #(i)
    }
}

// Patch all branches in list pointed to by t to branch to a:
ST_FUNC व्योम gsym_addr(पूर्णांक t_, पूर्णांक a_)
{
    uint32_t t = t_;
    uint32_t a = a_;
    जबतक (t) {
        अचिन्हित अक्षर *ptr = cur_text_section->तथ्य + t;
        uint32_t अग्र = read32le(ptr);
        अगर (a - t + 0x8000000 >= 0x10000000)
            tcc_error("branch out of range");
        write32le(ptr, (a - t == 4 ? ARM64_NOP :
                        ARM64_B | ((a - t) >> 2 & 0x3ffffff)));
        t = अग्र;
    }
}

अटल पूर्णांक arm64_type_आकार(पूर्णांक t)
{
    /*
     * case values are in increasing order (from 1 to 11).
     * which 'may' help compiler optimizers. See tcc.h
     */
    चयन (t & VT_BTYPE) {
    हाल VT_BYTE: वापस 0;
    हाल VT_SHORT: वापस 1;
    हाल VT_INT: वापस 2;
    हाल VT_LLONG: वापस 3;
    हाल VT_PTR: वापस 3;
    हाल VT_FUNC: वापस 3;
    हाल VT_STRUCT: वापस 3;
    हाल VT_FLOAT: वापस 2;
    हाल VT_DOUBLE: वापस 3;
    हाल VT_LDOUBLE: वापस 4;
    हाल VT_BOOL: वापस 0;
    }
    निश्चित(0);
    वापस 0;
}

अटल व्योम arm64_spoff(पूर्णांक reg, uint64_t off)
{
    uint32_t sub = off >> 63;
    अगर (sub)
        off = -off;
    अगर (off < 4096)
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(31) | ARM64_RD(reg) | ARM64_IMM12(off));
    अन्यथा {
        arm64_movimm(30, off);
        o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(30) | ARM64_RN(31) | ARM64_RD(reg) | (sub << 30));
    }
}

अटल uint64_t arm64_check_offset(पूर्णांक sz_, uint64_t off)
{
#अगर_अघोषित TCC_TARGET_PE
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    अगर (!(off & ~scaled_mask) || (off < 256 || -off <= 256))
        वापस ~0ull;
    अगर (off & scaled_mask)
        वापस scaled_mask;
    अगर (off & 0x1fful)
        वापस 0x1fful;
#पूर्ण_अगर
    वापस 0;
}

अटल व्योम arm64_ldrx(पूर्णांक sg, पूर्णांक sz_, पूर्णांक dst, पूर्णांक bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;
    अगर (sz >= 2)
        sg = 0;
    अगर (!(off & ~scaled_mask))
        o(ARM64_LDR_B | dst | bas << 5 | off << (10 - sz) |
          (uint32_t)!!sg << 23 | sz << 30); // ldr(*) x(dst),[x(bas),#(off)]
    अन्यथा अगर (off < 256 || -off <= 256)
        o(ARM64_LDUR_B | dst | bas << 5 | (off & 511) << 12 |
          (uint32_t)!!sg << 23 | sz << 30); // ldur(*) x(dst),[x(bas),#(off)]
    अन्यथा {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_B_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          (uint32_t)(!!sg + 1) << 22 | sz << 30); // ldr(*) x(dst),[x(bas),x30]
    }
}

अटल व्योम arm64_ldrv(पूर्णांक sz_, पूर्णांक dst, पूर्णांक bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    अगर (!(off & ~scaled_mask))
        o(ARM64_LDR_SCALAR | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // ldr (s|d|q)(dst),[x(bas),#(off)]
    अन्यथा अगर (off < 256 || -off <= 256)
        o(ARM64_LDUR_Q_SIMD | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // ldur (s|d|q)(dst),[x(bas),#(off)]
    अन्यथा {
        arm64_movimm(30, off); // use x30 for offset
        o(ARM64_LDR_Q_REG | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // ldr (s|d|q)(dst),[x(bas),x30]
    }
}

अटल व्योम arm64_ldrs(पूर्णांक reg_, पूर्णांक आकार)
{
    uint32_t reg = reg_;
    // Use x30 for intermediate value in some cases.
    चयन (आकार) {
    शेष: निश्चित(0); अवरोध;
    हाल 0:
        /* Can happen with zero size structs */
        अवरोध;
    हाल 1:
        arm64_ldrx(0, 0, reg, reg, 0);
        अवरोध;
    हाल 2:
        arm64_ldrx(0, 1, reg, reg, 0);
        अवरोध;
    हाल 3:
        arm64_ldrx(0, 1, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 2);
        o(0x2a0043c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #16
        अवरोध;
    हाल 4:
        arm64_ldrx(0, 2, reg, reg, 0);
        अवरोध;
    हाल 5:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 0, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        अवरोध;
    हाल 6:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 1, reg, reg, 4);
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        अवरोध;
    हाल 7:
        arm64_ldrx(0, 2, 30, reg, 0);
        arm64_ldrx(0, 2, reg, reg, 3);
        o(0x53087c00 | reg | reg << 5); // lsr w(reg), w(reg), #8
        o(0xaa0083c0 | reg | reg << 16); // orr x(reg),x30,x(reg),lsl #32
        अवरोध;
    हाल 8:
        arm64_ldrx(0, 3, reg, reg, 0);
        अवरोध;
    हाल 9:
        arm64_ldrx(0, 0, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        अवरोध;
    हाल 10:
        arm64_ldrx(0, 1, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        अवरोध;
    हाल 11:
        arm64_ldrx(0, 2, reg + 1, reg, 7);
        o(0x53087c00 | (reg+1) | (reg+1) << 5); // lsr w(reg+1), w(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        अवरोध;
    हाल 12:
        arm64_ldrx(0, 2, reg + 1, reg, 8);
        arm64_ldrx(0, 3, reg, reg, 0);
        अवरोध;
    हाल 13:
        arm64_ldrx(0, 3, reg + 1, reg, 5);
        o(0xd358fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #24
        arm64_ldrx(0, 3, reg, reg, 0);
        अवरोध;
    हाल 14:
        arm64_ldrx(0, 3, reg + 1, reg, 6);
        o(0xd350fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #16
        arm64_ldrx(0, 3, reg, reg, 0);
        अवरोध;
    हाल 15:
        arm64_ldrx(0, 3, reg + 1, reg, 7);
        o(0xd348fc00 | (reg+1) | (reg+1) << 5); // lsr x(reg+1), x(reg+1), #8
        arm64_ldrx(0, 3, reg, reg, 0);
        अवरोध;
    हाल 16:
        o(0xa9400000 | reg | (reg+1) << 10 | reg << 5);
        // ldp x(reg),x(reg+1),[x(reg)]
        अवरोध;
    }
}

अटल व्योम arm64_strx(पूर्णांक sz_, पूर्णांक dst, पूर्णांक bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    अगर (!(off & ~scaled_mask))
        o(0x39000000 | dst | bas << 5 | off << (10 - sz) | sz << 30);
        // str(*) x(dst),[x(bas],#(off)]
    अन्यथा अगर (off < 256 || -off <= 256)
        o(0x38000000 | dst | bas << 5 | (off & 511) << 12 | sz << 30);
        // stur(*) x(dst),[x(bas],#(off)]
    अन्यथा {
        arm64_movimm(30, off); // use x30 for offset
        o(0x38206800 | dst | bas << 5 | (uint32_t)30 << 16 | sz << 30);
        // str(*) x(dst),[x(bas),x30]
    }
}

अटल व्योम arm64_strv(पूर्णांक sz_, पूर्णांक dst, पूर्णांक bas, uint64_t off)
{
    uint32_t sz = sz_;
    uint64_t scaled_mask = 0xffful << sz;

    अगर (!(off & ~scaled_mask))
        o(0x3d000000 | dst | bas << 5 | off << (10 - sz) |
          (sz & 4) << 21 | (sz & 3) << 30); // str (s|d|q)(dst),[x(bas),#(off)]
    अन्यथा अगर (off < 256 || -off <= 256)
        o(0x3c000000 | dst | bas << 5 | (off & 511) << 12 |
          (sz & 4) << 21 | (sz & 3) << 30); // stur (s|d|q)(dst),[x(bas),#(off)]
    अन्यथा {
        arm64_movimm(30, off); // use x30 for offset
        o(0x3c206800 | dst | bas << 5 | (uint32_t)30 << 16 |
          sz << 30 | (sz & 4) << 21); // str (s|d|q)(dst),[x(bas),x30]
    }
}

अटल व्योम arm64_reloca(Sym *sym, पूर्णांक reloc_type, uint64_t addend)
{
    greloca(cur_text_section, sym, ind, reloc_type, addend);
}

अटल व्योम arm64_sym(पूर्णांक r, Sym *sym, addr_t addend)
{
    अगर (sym->type.t & VT_TLS) {
#अगर_घोषित TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK_tls_सूचकांक, &int_type);
        पूर्णांक r2 = get_reg(RC_R(16));
        arm64_sym(30, s2, 0);
        o(0xb94003de); // ldr w30, [x30]
        o(0xf9402e40 | r2); // ldr r2, [x18, #88]
        o(0x8b1e0c1e | r2 << 5); // add x30, r2, x30, lsl #3
        o(0xf94003c0 | r); // ldr xr, [x30]
#अन्यथा
        o(0xd53bd040 | r); /* mrs xr, tpidr_el0 */
#पूर्ण_अगर
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_HI12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0, lsl #12 */
        arm64_reloca(sym, R_AARCH64_TLSLE_ADD_TPREL_LO12, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | ARM64_RD(r)); /* add xr, xr, #0 */
#अगर_अघोषित TCC_TARGET_PE /* no elf-style GOT on Windows */
    } अन्यथा अगर (!(sym->type.t & VT_STATIC)) {
        arm64_reloca(sym, R_AARCH64_ADR_GOT_PAGE, 0);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_LD64_GOT_LO12_NC, 0);
        o(ARM64_LDR_X | ARM64_RN(r) | r); /* ld xr,[xr, #sym] */
        अगर (addend > 0xffffff) {
            पूर्णांक t = get_reg(RC_R(16));
            arm64_movimm(t, addend); // use xt for addent
            o(ARM64_ADD_REG | ARM64_SF(1) | ARM64_RM(t) | ARM64_RN(r) | r); /* add xr, xr, xt */
        } अन्यथा {
           अगर (addend & 0xfff) /* add xr, xr, #addend */
                o(ARM64_ADD_IMM | ARM64_SF(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
            addend >>= 12;
            अगर (addend & 0xfff) /* add xr, xr, #addend, lsl #12 */
                o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_SH(1)
                    | ARM64_RN(r) | r | (addend & 0xfff) << 10);
        }
#पूर्ण_अगर
    } अन्यथा {
        arm64_reloca(sym, R_AARCH64_ADR_PREL_PG_HI21, addend);
        o(ARM64_ADRP | r); /* adrp xr, #sym */
        arm64_reloca(sym, R_AARCH64_ADD_ABS_LO12_NC, addend);
        o(ARM64_ADD_IMM | ARM64_SF(1) | ARM64_RN(r) | r); /* add xr, xr, #sym */
    }
}

अटल व्योम arm64_load_cmp(पूर्णांक r, SValue *sv);

ST_FUNC व्योम load(पूर्णांक r, SValue *sv)
{
    पूर्णांक svtt = sv->type.t;
    पूर्णांक svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    पूर्णांक svrv = svr & VT_VALMASK;
    uint64_t svcul = sv->c.i;
    uint64_t svcoff = (int32_t)sv->c.i;
    पूर्णांक sb = !(svtt & VT_UNSIGNED);
    पूर्णांक sz = arm64_type_आकार(svtt);

    अगर (svr == (VT_LOCAL | VT_LVAL)) {
        अगर (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 29, svcoff);
        अन्यथा
            arm64_ldrx(sb, sz, intr(r), 29, svcoff);
        वापस;
    }

    अगर (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, svcul);
        अगर (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        अन्यथा
            arm64_ldrx(sb, sz, intr(r), 30, 0);
        वापस;
    }

    अगर (svrv < VT_CONST && (svr & VT_LVAL)) {
        अगर (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), intr(svrv), 0);
        अन्यथा
            arm64_ldrx(sb, sz, intr(r), intr(svrv), 0);
        वापस;
    }

    अगर (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        अगर (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, svcoff & mask);
        अन्यथा
            arm64_ldrx(sb, sz, intr(r), 30, svcoff & mask);
        वापस;
    }

    अगर (svr == (VT_CONST | VT_SYM)) {
        arm64_sym(intr(r), sv->sym, svcul);
        वापस;
    }

    अगर (svr == VT_CONST) {
        arm64_movimm(intr(r), sz == 3 ? svcul : (uint32_t)svcul);
        वापस;
    }

    अगर (svr < VT_CONST) {
        अगर (IS_FREG(r) && IS_FREG(svr))
            अगर (svtt == VT_LDOUBLE)
                o(ARM64_MOV_V16B | fltr(r) | fltr(svr) * 0x10020);
                    // mov v(r).16b,v(svr).16b
            अन्यथा
                o(ARM64_FMOV_SCALAR | fltr(r) | fltr(svr) << 5); // fmov d(r),d(svr)
        अन्यथा अगर (!IS_FREG(r) && !IS_FREG(svr))
            o(ARM64_MOV_REG | ARM64_SF(1) | intr(r) | intr(svr) << 16); // mov x(r),x(svr)
        अन्यथा
            निश्चित(0);
      वापस;
    }

    अगर (svr == VT_LOCAL) {
        अगर (-svcoff < 0x1000)
            o(0xd10003a0 | intr(r) | -svcoff << 10); // sub x(r),x29,#...
        अन्यथा {
            arm64_movimm(30, -svcoff); // use x30 for offset
            o(0xcb0003a0 | intr(r) | (uint32_t)30 << 16); // sub x(r),x29,x30
        }
        वापस;
    }

    अगर (svr == VT_JMP || svr == VT_JMPI) {
        पूर्णांक t = (svr == VT_JMPI);
        arm64_movimm(intr(r), t);
        o(ARM64_B | 2); // b .+8
        gsym(svcul);
        arm64_movimm(intr(r), t ^ 1);
        वापस;
    }

    अगर (svr == (VT_LLOCAL | VT_LVAL)) {
        arm64_ldrx(0, 3, 30, 29, svcoff); // use x30 for offset
        अगर (IS_FREG(r))
            arm64_ldrv(sz, fltr(r), 30, 0);
        अन्यथा
            arm64_ldrx(sb, sz,
                       intr(r), 30, 0);
        वापस;
    }

    अगर (svr == VT_CMP) {
        arm64_load_cmp(r, sv);
        वापस;
    }

    म_लिखो("load(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (दीर्घ)svcul);
    निश्चित(0);
}

ST_FUNC व्योम store(पूर्णांक r, SValue *sv)
{
    पूर्णांक svtt = sv->type.t;
    पूर्णांक svr = sv->r & (VT_VALMASK | VT_LVAL | VT_SYM);
    पूर्णांक svrv = svr & VT_VALMASK;
    uint64_t svcoff = (int32_t)sv->c.i;
    पूर्णांक sz = arm64_type_आकार(svtt);

    अगर (svr == (VT_LOCAL | VT_LVAL)) {
        अगर (IS_FREG(r))
            arm64_strv(sz, fltr(r), 29, svcoff);
        अन्यथा
            arm64_strx(sz, intr(r), 29, svcoff);
        वापस;
    }

    अगर (svr == (VT_CONST | VT_LVAL)) {
	arm64_movimm (30, sv->c.i);
        अगर (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, 0);
        अन्यथा
            arm64_strx(sz, intr(r), 30, 0);
        वापस;
    }

    अगर (svrv < VT_CONST && (svr & VT_LVAL)) {
        अगर (IS_FREG(r))
            arm64_strv(sz, fltr(r), intr(svrv), 0);
        अन्यथा
            arm64_strx(sz, intr(r), intr(svrv), 0);
        वापस;
    }

    अगर (svr == (VT_CONST | VT_LVAL | VT_SYM)) {
        uint64_t mask = arm64_check_offset(sz, svcoff);
        arm64_sym(30, sv->sym, svcoff & ~mask);
        अगर (IS_FREG(r))
            arm64_strv(sz, fltr(r), 30, svcoff & mask);
        अन्यथा
            arm64_strx(sz, intr(r), 30, svcoff & mask);
        वापस;
    }

    म_लिखो("store(%x, (%x, %x, %lx))\n", r, svtt, sv->r, (दीर्घ)svcoff);
    निश्चित(0);
}

अटल व्योम arm64_gen_bl_or_b(पूर्णांक b)
{
    अगर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM)) {
	arm64_reloca(vtop->sym,
                b ? R_AARCH64_JUMP26 :  R_AARCH64_CALL26, 0);
	o(b ? ARM64_B : ARM64_BL); // b/bl .
    }
    अन्यथा {
#अगर_घोषित CONFIG_TCC_BCHECK
        vtop->r &= ~VT_MUSTBOUND;
#पूर्ण_अगर
        o((b ? ARM64_BR : ARM64_BLR) | intr(gv(RC_R30)) << 5); // br/blr
    }
}

#अगर defined CONFIG_TCC_BCHECK || defined TCC_TARGET_PE
अटल व्योम gen_static_call(पूर्णांक v)
{
    Sym *sym = external_helper_sym(v);
    arm64_reloca(sym, R_AARCH64_CALL26, 0);
    o(ARM64_BL); // bl
}
#पूर्ण_अगर

#अगर defined(CONFIG_TCC_BCHECK)
अटल व्योम gen_bounds_prolog(व्योम)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->तथ्य_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(ARM64_NOP);  /* nop -> mov x0, lbound section pointer */
    o(ARM64_NOP);
    o(ARM64_NOP);
    o(ARM64_NOP);  /* nop -> call __bound_local_new */
}

अटल व्योम gen_bounds_epilog(व्योम)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_तथ्य;
    पूर्णांक offset_modified = func_bound_offset != lbounds_section->तथ्य_offset;

    अगर (!offset_modified && !func_bound_add_epilog)
        वापस;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, माप(addr_t));
    *bounds_ptr = 0;

    sym_तथ्य = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_आकार);

    /* generate bound local allocation */
    अगर (offset_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        arm64_sym(0, sym_तथ्य, 0);
        gen_static_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0xa9bf07e0); /* stp x0, x1, [sp, #-16]! */
    o(0x3c9f0fe0); /* str q0, [sp, #-16]! */
    arm64_sym(0, sym_तथ्य, 0);
    gen_static_call(TOK___bound_local_delete);
    o(0x3cc107e0); /* ldr q0, [sp], #16 */
    o(0xa8c107e0); /* ldp x0, x1, [sp], #16 */
}
#पूर्ण_अगर

अटल पूर्णांक arm64_hfa_aux(CType *type, पूर्णांक *fsize, पूर्णांक अंक)
{
    अगर (is_float(type->t)) {
        पूर्णांक a, n = type_आकार(type, &a);
        अगर (अंक >= 4 || (*fsize && *fsize != n))
            वापस -1;
        *fsize = n;
        वापस अंक + 1;
    }
    अन्यथा अगर ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field;
        अगर (!IS_UNION(type->t)) {
            पूर्णांक num0 = अंक;
            क्रम (field = type->ref->अग्र; field; field = field->अग्र) {
                अगर (field->c != (अंक - num0) * *fsize)
                    वापस -1;
                अंक = arm64_hfa_aux(&field->type, fsize, अंक);
                अगर (अंक == -1)
                    वापस -1;
            }
            अगर (type->ref->c != (अंक - num0) * *fsize)
                वापस -1;
            वापस अंक;
        }
        अन्यथा { // union
            पूर्णांक num0 = अंक;
            क्रम (field = type->ref->अग्र; field; field = field->अग्र) {
                पूर्णांक num1 = arm64_hfa_aux(&field->type, fsize, num0);
                अगर (num1 == -1)
                    वापस -1;
                अंक = num1 < अंक ? अंक : num1;
            }
            अगर (type->ref->c != (अंक - num0) * *fsize)
                वापस -1;
            वापस अंक;
        }
    }
    अन्यथा अगर (type->t & VT_ARRAY) { /* handle float array within struct */
        पूर्णांक num1;
        अगर (!type->ref->c)
            वापस अंक;
        num1 = arm64_hfa_aux(&type->ref->type, fsize, अंक);
        अगर (num1 == -1 || (num1 != अंक && type->ref->c > 4))
            वापस -1;
        num1 = अंक + type->ref->c * (num1 - अंक);
        अगर (num1 > 4)
            वापस -1;
        वापस num1;
    }
    वापस -1;
}

अटल पूर्णांक arm64_hfa(CType *type, अचिन्हित *fsize)
{
    अगर ((type->t & VT_BTYPE) == VT_STRUCT) {
        पूर्णांक sz = 0;
        पूर्णांक n = arm64_hfa_aux(type, &sz, 0);
        अगर (0 < n && n <= 4) {
            अगर (fsize)
                *fsize = sz;
            वापस n;
        }
    }
    वापस 0;
}

अटल अचिन्हित दीर्घ arm64_pcs_aux(पूर्णांक variadic, पूर्णांक n, CType **type, अचिन्हित दीर्घ *a)
{
    पूर्णांक nx = 0; // next integer register
    पूर्णांक nv = 0; // next vector register
    अचिन्हित दीर्घ ns = 32; // next stack offset
    पूर्णांक i;

    क्रम (i = 0; i < n; i++) {
        पूर्णांक hfa = arm64_hfa(type[i], 0);
        पूर्णांक आकार, align, bt;

        bt = type[i]->t & VT_BTYPE;
        अगर (bt == VT_PTR || bt == VT_FUNC)
            आकार = align = 8;
        अन्यथा
            आकार = type_आकार(type[i], &align);

#अगर defined(TCC_TARGET_MACHO)
        अगर (variadic && i == variadic) {
            nx = 8;
            nv = 8;
	}

#या_अगर defined(TCC_TARGET_PE)
        अगर (variadic && i >= variadic) {
            hfa = 0;
            अगर (is_float(bt))
                bt = VT_INT, आकार = align = 8;
        }
#पूर्ण_अगर
        अगर (hfa)
            // B.2
            ;
        अन्यथा अगर (आकार > 16) {
            // B.3: replace with pointer
            अगर (nx < 8)
                a[i] = nx++ << 1 | 1;
            अन्यथा {
                ns = (ns + 7) & ~7;
                a[i] = ns | 1;
                ns += 8;
            }
            जारी;
        }
        अन्यथा अगर (bt == VT_STRUCT)
            // B.4
            आकार = (आकार + 7) & ~7;

        // C.1
        अगर (is_float(bt) && nv < 8) {
            a[i] = 16 + (nv++ << 1);
            जारी;
        }

        // C.2
        अगर (hfa && nv + hfa <= 8) {
            a[i] = 16 + (nv << 1);
            nv += hfa;
            जारी;
        }

        // C.3
        अगर (hfa) {
            nv = 8;
            आकार = (आकार + 7) & ~7;
        }

        // C.4
        अगर (hfa || bt == VT_LDOUBLE) {
            ns = (ns + 7) & ~7;
            ns = (ns + align - 1) & -align;
        }

        // C.5
        अगर (bt == VT_FLOAT)
            आकार = 8;

        // C.6
        अगर (hfa || is_float(bt)) {
            a[i] = ns;
            ns += आकार;
            जारी;
        }

        // C.7
        अगर (bt != VT_STRUCT && आकार <= 8 && nx < 8) {
            a[i] = nx++ << 1;
            जारी;
        }

        // C.8
        अगर (align == 16)
            nx = (nx + 1) & ~1;

        // C.9
        अगर (bt != VT_STRUCT && आकार == 16 && nx < 7) {
            a[i] = nx << 1;
            nx += 2;
            जारी;
        }

        // C.10
        अगर (bt == VT_STRUCT && आकार <= (8 - nx) * 8) {
            a[i] = nx << 1;
            nx += (आकार + 7) >> 3;
            जारी;
        }

        // C.11
        nx = 8;

        // C.12
        ns = (ns + 7) & ~7;
        ns = (ns + align - 1) & -align;

        // C.13
        अगर (bt == VT_STRUCT) {
            a[i] = ns;
            ns += आकार;
            जारी;
        }

        // C.14
        अगर (आकार < 8)
            आकार = 8;

        // C.15
        a[i] = ns;
        ns += आकार;
    }

    वापस ns - 32;
}

अटल अचिन्हित दीर्घ arm64_pcs(पूर्णांक variadic, पूर्णांक n, CType **type, अचिन्हित दीर्घ *a)
{
    अचिन्हित दीर्घ ढेर;

    // Return type:
    अगर ((type[0]->t & VT_BTYPE) == VT_VOID)
        a[0] = -1;
    अन्यथा {
        arm64_pcs_aux(0, 1, type, a);
        निश्चित(a[0] == 0 || a[0] == 1 || a[0] == 16);
    }

    // Argument types:
    ढेर = arm64_pcs_aux(variadic, n - 1, type + 1, a + 1);

    अगर (0) {
        पूर्णांक i;
        क्रम (i = 0; i < n; i++) {
            अगर (!i)
                म_लिखो("arm64_pcs return: ");
            अन्यथा
                म_लिखो("arm64_pcs arg %d: ", i);
            अगर (a[i] == (अचिन्हित दीर्घ)-1)
                म_लिखो("void\n");
            अन्यथा अगर (a[i] == 1 && !i)
                म_लिखो("X8 pointer\n");
            अन्यथा अगर (a[i] < 16)
                म_लिखो("X%lu%s\n", a[i] / 2, a[i] & 1 ? " pointer" : "");
            अन्यथा अगर (a[i] < 32)
                म_लिखो("V%lu\n", a[i] / 2 - 8);
            अन्यथा
                म_लिखो("stack %lu%s\n",
                       (a[i] - 32) & ~1, a[i] & 1 ? " pointer" : "");
        }
    }

    वापस ढेर;
}

अटल पूर्णांक n_func_args(CType *type)
{
    पूर्णांक n_args = 0;
    Sym *arg;

    क्रम (arg = type->ref->अग्र; arg; arg = arg->अग्र)
        n_args++;
    वापस n_args;
}

अटल व्योम arm64_sub_sp(uint64_t diff)
{
    अगर (!diff)
        वापस;
#अगर_घोषित TCC_TARGET_PE
    अगर (diff >= 4096) {
        arm64_movimm(15, diff >> 4);
        gen_static_call(TOK___chkstk);
        o(0xcb2f73ff); // sub sp,sp,x15,lsl #4
        वापस;
    }
#पूर्ण_अगर
    अगर (!(diff >> 24)) {
        अगर (diff & 0xffful)
            o(ARM64_SUB_IMM | ARM64_SF(1) | 0           | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12(diff & 0xfff));
        अगर (diff >> 12)
            o(ARM64_SUB_IMM | ARM64_SF(1) | ARM64_SH(1) | ARM64_RN(31) | ARM64_RD(31) | ARM64_IMM12((diff >> 12) & 0xfff));
    } अन्यथा {
        arm64_movimm(16, diff);
        o(0xCB3063FFU); // sub sp,sp,x16
    }
}

अटल पूर्णांक gv_addr(पूर्णांक r)
{
    gaddrof();
    vtop->type.t = VT_PTR;
    वापस gv(r);
}

ST_FUNC व्योम gfunc_call(पूर्णांक nb_args)
{
    CType *return_type;
    CType **t;
    अचिन्हित दीर्घ *a, *a1;
    अचिन्हित दीर्घ ढेर;
    पूर्णांक i;
    पूर्णांक func_type = vtop[-nb_args].type.ref->f.func_type;
    पूर्णांक variadic = (func_type == FUNC_ELLIPSIS);
    पूर्णांक old_style = (func_type == FUNC_OLD);
    पूर्णांक var_nb_arg = variadic ? n_func_args(&vtop[-nb_args].type) : 0;

    save_regs(nb_args + 1);

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#पूर्ण_अगर

    return_type = &vtop[-nb_args].type.ref->type;
    अगर ((return_type->t & VT_BTYPE) == VT_STRUCT)
        --nb_args;

    t = tcc_malloc((nb_args + 1) * माप(*t));
    a = tcc_malloc((nb_args + 1) * माप(*a));
    a1 = tcc_malloc((nb_args + 1) * माप(*a1));

    t[0] = return_type;
    क्रम (i = 0; i < nb_args; i++)
        t[nb_args - i] = &vtop[-i].type;

    ढेर = arm64_pcs(
#अगर_घोषित TCC_TARGET_PE
        old_style ? /* all args like varargs in K&R style */ -1 :
#पूर्ण_अगर
        var_nb_arg, nb_args + 1, t, a);

    // Allocate space for structs replaced by pointer:
    क्रम (i = nb_args; i; i--)
        अगर (a[i] & 1) {
            SValue *arg = &vtop[i - nb_args];
            पूर्णांक align, आकार = type_आकार(&arg->type, &align);
            निश्चित((arg->type.t & VT_BTYPE) == VT_STRUCT);
            ढेर = (ढेर + align - 1) & -align;
            a1[i] = ढेर;
            ढेर += आकार;
        }

    ढेर = (ढेर + 15) >> 4 << 4;

    अगर (ढेर >= 0x1000000) // 16Mb
        tcc_error("stack size too big %lu", ढेर);
    arm64_sub_sp(ढेर);

    // First pass: set all values on stack
    क्रम (i = nb_args; i; i--) {
        vpushv(vtop - nb_args + i);

        अगर (a[i] & 1) {
            // struct replaced by pointer
            पूर्णांक r = get_reg(RC_INT);
            arm64_spoff(intr(r), a1[i]);
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            अगर (a[i] >= 32) {
                // pointer on stack
                r = get_reg(RC_INT);
                arm64_spoff(intr(r), a1[i]);
                arm64_strx(3, intr(r), 31, (a[i] - 32) >> 1 << 1);
            }
        }
        अन्यथा अगर (a[i] >= 32) {
            // value on stack
            अगर ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                पूर्णांक r = get_reg(RC_INT);
                arm64_spoff(intr(r), a[i] - 32);
                vset(&vtop->type, r | VT_LVAL, 0);
                vswap();
                vstore();
            }
            अन्यथा अगर (is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                arm64_strv(arm64_type_आकार(vtop[0].type.t),
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
    क्रम (i = nb_args; i; i--, vtop--) {
        अगर (a[i] < 16 && !(a[i] & 1)) {
            // value in general-purpose registers
            अगर ((variadic || old_style) && i > var_nb_arg && is_float(vtop->type.t)) {
                gv(RC_FLOAT);
                अगर ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                    o(ARM64_FMOV_XD | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov xN,dM
                अन्यथा
                    o(ARM64_FMOV_WS | intr(a[i] / 2) | fltr(vtop->r) << 5); // fmov wN,sM
            }
            अन्यथा अगर ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                पूर्णांक align, आकार = type_आकार(&vtop->type, &align);
                अगर (आकार) {
                    gv_addr(RC_R(a[i] / 2));
                    arm64_ldrs(a[i] / 2, आकार);
                }
            }
            अन्यथा
                gv(RC_R(a[i] / 2));
        }
        अन्यथा अगर (a[i] < 16)
            // struct replaced by pointer in register
            arm64_spoff(a[i] / 2, a1[i]);
        अन्यथा अगर (a[i] < 32) {
            // value in floating-point registers
            अगर ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
                uint32_t j, sz, n = arm64_hfa(&vtop->type, &sz);
                अगर (n > 0) {
                    /* HFA struct - load from memory into float registers */
                    gv_addr(RC_R30);
                    क्रम (j = 0; j < n; j++)
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

    अगर ((return_type->t & VT_BTYPE) == VT_STRUCT) {
        अगर (a[0] == 1) {
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
    अगर (ढेर & 0xfff)
        o(0x910003ff | (ढेर & 0xfff) << 10); // add sp,sp,#(n)
    अगर (ढेर >> 12)
        o(0x914003ff | (ढेर >> 12) << 10);

    {
        पूर्णांक rt = return_type->t;
        पूर्णांक bt = rt & VT_BTYPE;
        अगर (bt == VT_STRUCT && !(a[0] & 1)) {
            // A struct was returned in registers, so write it out:
            gv_addr(RC_R(8));
            --vtop;
            अगर (a[0] == 0) {
                पूर्णांक align, आकार = type_आकार(return_type, &align);
                निश्चित(आकार <= 16);
                अगर (आकार > 8)
                    o(0xa9000500); // stp x0,x1,[x8]
                अन्यथा अगर (आकार)
                    arm64_strx(आकार > 4 ? 3 : आकार > 2 ? 2 : आकार > 1, 0, 8, 0);

            }
            अन्यथा अगर (a[0] == 16) {
                /* HFA struct return - store from float registers to the address in x8 */
                uint32_t j, sz, n = arm64_hfa(return_type, &sz);
                क्रम (j = 0; j < n; j++)
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

अटल अचिन्हित दीर्घ arm64_func_va_list_ढेर;
अटल पूर्णांक arm64_func_va_list_gr_offs;
अटल पूर्णांक arm64_func_va_list_vr_offs;
अटल पूर्णांक arm64_func_sub_sp_offset;

अटल अचिन्हित arm64_func_start_offset;
#घोषणा ARM64_FUNC_ढेर_SETUP_SLOTS 6

#अगर_घोषित TCC_TARGET_PE
अटल अचिन्हित दीर्घ arm64_pe_param_off(अचिन्हित दीर्घ a)
{
    वापस a < 16 ? 160 + a / 2 * 8 :
           a < 32 ? 16 + (a - 16) / 2 * 16 :
           224 + ((a - 32) >> 1 << 1);
}
#पूर्ण_अगर

ST_FUNC व्योम gfunc_prolog(Sym *func_sym)
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

    क्रम (sym = func_type->ref; sym; sym = sym->अग्र)
        ++n;

#अगर_घोषित TCC_TARGET_PE
    n += variadic;
#पूर्ण_अगर

    t = tcc_malloc(n * माप(*t));
    a = tcc_malloc(n * माप(*a));
    क्रम (sym = func_type->ref; sym; sym = sym->अग्र)
        t[i++] = &sym->type;

#अगर_घोषित TCC_TARGET_PE
    अगर (variadic)
        t[i] = &int_type;
#पूर्ण_अगर

    arm64_func_va_list_ढेर = arm64_pcs(var_nb_arg, n, t, a);

#अगर_घोषित TCC_TARGET_PE
    अगर (variadic)
        arm64_func_va_list_ढेर = arm64_pe_param_off(a[n - 1]);
#पूर्ण_अगर

#अगर !defined(TCC_TARGET_MACHO)
    अगर (variadic) {
        use_x8 = 1;
        last_int = 4;
        last_float = 4;
    }
#पूर्ण_अगर

    अगर (a && a[0] == 1)
        use_x8 = 1;
    क्रम (i = 1, sym = func_type->ref->अग्र; sym; i++, sym = sym->अग्र) {
        अगर (a[i] < 16) {
            पूर्णांक last, align, आकार = type_आकार(&sym->type, &align);
	    last = a[i] / 4 + 1 + (आकार - 1) / 8;
	    last_int = last > last_int ? last : last_int;
	}
        अन्यथा अगर (a[i] < 32) {
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

    क्रम (i = 0; i < last_float; i++)
        // stp q0,q1,[sp,#16], stp q2,q3,[sp,#48]
        // stp q4,q5,[sp,#80], stp q6,q7,[sp,#112]
        o(0xad0087e0 + i * 0x10000 + (i << 11) + (i << 1));
    अगर (use_x8)
        o(0xa90923e8); // stp x8,x8,[sp,#144]
    क्रम (i = 0; i < last_int; i++)
        // stp x0,x1,[sp,#160], stp x2,x3,[sp,#176]
        // stp x4,x5,[sp,#192], stp x6,x7,[sp,#208]
        o(0xa90a07e0 + i * 0x10000 + (i << 11) + (i << 1));

    arm64_func_va_list_gr_offs = -64;
    arm64_func_va_list_vr_offs = -128;

    क्रम (i = 1, sym = func_type->ref->अग्र; sym; i++, sym = sym->अग्र) {
        पूर्णांक off = (a[i] < 16 ? 160 + a[i] / 2 * 8 :
                   a[i] < 32 ? 16 + (a[i] - 16) / 2 * 16 :
                   224 + ((a[i] - 32) >> 1 << 1));

        gfunc_set_param(sym, off, a[i] & 1);

        अगर (a[i] < 16) {
            पूर्णांक align, आकार = type_आकार(&sym->type, &align);
            arm64_func_va_list_gr_offs = (a[i] / 2 - 7 +
                                          (!(a[i] & 1) && आकार > 8)) * 8;
        }
        अन्यथा अगर (a[i] < 32) {
            uint32_t hfa = arm64_hfa(&sym->type, 0);
            arm64_func_va_list_vr_offs = (a[i] / 2 - 16 +
                                          (hfa ? hfa : 1)) * 16;
        }

        // HFAs of float and double need to be written differently:
        अगर (16 <= a[i] && a[i] < 32 && (sym->type.t & VT_BTYPE) == VT_STRUCT) {
            uint32_t j, sz, k = arm64_hfa(&sym->type, &sz);
            अगर (k > 0 && sz < 16)
                क्रम (j = 0; j < k; j++) {
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
    क्रम (i = 0; i < ARM64_FUNC_ढेर_SETUP_SLOTS; ++i)
        o(ARM64_NOP); // nop
    loc = 0;
#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#पूर्ण_अगर
}

ST_FUNC व्योम gen_va_start(व्योम)
{
    पूर्णांक r;
    --vtop; // we don't need the "arg"
    r = intr(gv_addr(RC_INT));

#अगर_घोषित TCC_TARGET_PE
    अगर (arm64_func_va_list_ढेर) {
        arm64_movimm(30, arm64_func_va_list_ढेर);
        o(0x8b1e03be); // add x30,x29,x30
    } अन्यथा
        o(0x910283be); // add x30,x29,#160
    o(0xf900001e | r << 5); // str x30,[x(r)]
#अन्यथा
    अगर (arm64_func_va_list_ढेर) {
        //xx could use add (immediate) here
        arm64_movimm(30, arm64_func_va_list_ढेर + 224);
        o(0x8b1e03be); // add x30,x29,x30
    }
    अन्यथा
        o(0x910383be); // add x30,x29,#224
    o(0xf900001e | r << 5); // str x30,[x(r)]

#अगर !defined(TCC_TARGET_MACHO)
    अगर (arm64_func_va_list_gr_offs) {
        अगर (arm64_func_va_list_ढेर)
            o(0x910383be); // add x30,x29,#224
        o(0xf900041e | r << 5); // str x30,[x(r),#8]
    }

    अगर (arm64_func_va_list_vr_offs) {
        o(0x910243be); // add x30,x29,#144
        o(0xf900081e | r << 5); // str x30,[x(r),#16]
    }

    arm64_movimm(30, arm64_func_va_list_gr_offs);
    o(0xb900181e | r << 5); // str w30,[x(r),#24]

    arm64_movimm(30, arm64_func_va_list_vr_offs);
    o(0xb9001c1e | r << 5); // str w30,[x(r),#28]
#पूर्ण_अगर
#पूर्ण_अगर

    --vtop;
}

ST_FUNC व्योम gen_va_arg(CType *t)
{
    पूर्णांक align, आकार = type_आकार(t, &align);
    uint32_t r0, r1;

#अगर_घोषित TCC_TARGET_PE
    पूर्णांक indirect = 0, slot = (आकार + 7) & -8;

    अगर (आकार > 16)
        indirect = 1, slot = 8;

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // ap
    अगर (slot) {
        अगर (slot == 16) {
            o(0x910363be); // add x30,x29,#216
            o(0xeb1e003f | r1 << 5); // cmp x(r1),x30
            o(0x54000041); // b.ne .+8
            o(0x910383a0 | r1 | 29 << 5); // add x(r1),x29,#224
        }
        अगर (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | slot << 10); // add x30,x(r1),#(slot)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // ap += slot
    }
    अगर (indirect)
        o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]

#अन्यथा /* !PE */
    अचिन्हित fsize = आकार, hfa = 1;

    अगर (!is_float(t->t))
        hfa = arm64_hfa(t, &fsize);

    r0 = intr(gv_addr(RC_INT));
    r1 = get_reg(RC_INT);
    vtop[0].r = r1 | VT_LVAL;
    r1 = intr(r1);

    अगर (!hfa) {
        uint32_t n = आकार > 16 ? 8 : (आकार + 7) & -8;

#अगर !defined(TCC_TARGET_MACHO)
        o(0xb940181e | r0 << 5); // ldr w30,[x(r0),#24] // __gr_offs
        अगर (align == 16) {
            निश्चित(0); // this path untested but needed for __uint128_t
            o(0x11003fde); // add w30,w30,#15
            o(0x121c6fde); // and w30,w30,#-16
        }
        o(0x310003c0 | r1 | n << 10); // adds w(r1),w30,#(n)
        o(0x540000ad); // b.le .+20
#पूर्ण_अगर

        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        अगर (align == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | n << 10); // add x30,x(r1),#(n)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack

#अगर !defined(TCC_TARGET_MACHO)
        o(ARM64_B | 4); // b .+16
        o(0xb9001800 | r1 | r0 << 5); // str w(r1),[x(r0),#24] // __gr_offs
        o(0xf9400400 | r1 | r0 << 5); // ldr x(r1),[x(r0),#8] // __gr_top
        o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
#पूर्ण_अगर

        अगर (आकार > 16)
            o(ARM64_LDR_X | ARM64_RN(r1) | r1); // ldr x(r1),[x(r1)]
    }
    अन्यथा {
        uint32_t ssz = (आकार + 7) & -(uint32_t)8;
#अगर !defined(TCC_TARGET_MACHO)
        uint32_t rsz = hfa << 4;
        uint32_t b1, b2;
        o(0xb9401c1e | r0 << 5); // ldr w30,[x(r0),#28] // __vr_offs
        o(0x310003c0 | r1 | rsz << 10); // adds w(r1),w30,#(rsz)
        b1 = ind; o(0x5400000d); // b.le lab1
#पूर्ण_अगर
        o(ARM64_LDR_X | ARM64_RN(r0) | r1); // ldr x(r1),[x(r0)] // __stack
        अगर (fsize == 16) {
            o(0x91003c00 | r1 | r1 << 5); // add x(r1),x(r1),#15
            o(0x927cec00 | r1 | r1 << 5); // and x(r1),x(r1),#-16
        }
        o(0x9100001e | r1 << 5 | ssz << 10); // add x30,x(r1),#(ssz)
        o(0xf900001e | r0 << 5); // str x30,[x(r0)] // __stack
#अगर !defined(TCC_TARGET_MACHO)
        b2 = ind; o(ARM64_B); // b lab2
        // lab1:
        write32le(cur_text_section->तथ्य + b1, 0x5400000d | (ind - b1) << 3);
        o(0xb9001c00 | r1 | r0 << 5); // str w(r1),[x(r0),#28] // __vr_offs
        o(0xf9400800 | r1 | r0 << 5); // ldr x(r1),[x(r0),#16] // __vr_top
        अगर (hfa == 1 || fsize == 16)
            o(0x8b3ec000 | r1 | r1 << 5); // add x(r1),x(r1),w30,sxtw
        अन्यथा {
            // We need to change the layout of this HFA.
            // Get some space on the stack using global variable "loc":
            loc = (loc - आकार) & -(uint32_t)align;
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
        write32le(cur_text_section->तथ्य + b2, ARM64_B | ((ind - b2) >> 2));
#पूर्ण_अगर
    }
#पूर्ण_अगर /* not pe */
}

ST_FUNC पूर्णांक gfunc_sret(CType *vt, पूर्णांक variadic, CType *ret,
                       पूर्णांक *align, पूर्णांक *regsize)
{
    वापस 0;
}

ST_FUNC व्योम gfunc_return(CType *func_type)
{
    CType *t = func_type;
    अचिन्हित दीर्घ a;

    arm64_pcs(0, 1, &t, &a);

    चयन (a) {
    हाल -1:
        अवरोध;
    हाल 0:
        अगर ((func_type->t & VT_BTYPE) == VT_STRUCT) {
            पूर्णांक align, आकार = type_आकार(func_type, &align);
            gv_addr(RC_R(0));
            arm64_ldrs(0, आकार);
        }
        अन्यथा
            gv(RC_IRET);
        अवरोध;
    हाल 1: {
        CType type = *func_type;
        mk_pointer(&type);
        vset(&type, VT_LOCAL | VT_LVAL, func_vc);
        indir();
        vswap();
        vstore();
        अवरोध;
    }
    हाल 16:
        अगर ((func_type->t & VT_BTYPE) == VT_STRUCT) {
          /* HFA struct return - load from the address on vtop into float registers */
          uint32_t j, sz, n = arm64_hfa(func_type, &sz);
          gv_addr(RC_R(0));
          क्रम (j = 0; j < n; j++)
              o(0x3d400000 |
                (sz & 16) << 19 | -(sz & 8) << 27 | (sz & 4) << 29 |
                (fltr(REG_FRET) + j) | j << 10); // ldr ([sdq])(j),[x0,#(j * sz)]
        }
        अन्यथा
            gv(RC_FRET);
        अवरोध;
    शेष:
      निश्चित(0);
    }
    vtop--;
}

ST_FUNC व्योम gfunc_epilog(व्योम)
{
#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#पूर्ण_अगर

    अगर (loc) {
        // Insert instructions to subtract size of stack frame from SP.
        पूर्णांक i;
        addr_t saved_ind = ind;
        addr_t patch_end = arm64_func_sub_sp_offset + ARM64_FUNC_ढेर_SETUP_SLOTS * 4;
        uint64_t diff = (-loc + 15) & ~15;
        ind = arm64_func_sub_sp_offset;
        arm64_sub_sp(diff);
        क्रम (i = ind; i < patch_end; i += 4)
            write32le(cur_text_section->तथ्य + i, ARM64_NOP); // nop
        ind = saved_ind;
    }
    o(0x910003bf); // mov sp,x29
    o(0xa8ce7bfd); // ldp x29,x30,[sp],#224

    o(0xd65f03c0); // ret

#अगर_घोषित TCC_TARGET_PE
    pe_add_unwind_तथ्य(arm64_func_start_offset, ind, -loc);
#पूर्ण_अगर
}

ST_FUNC व्योम gen_fill_nops(पूर्णांक bytes)
{
    अगर ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    जबतक (bytes > 0) {
	o(ARM64_NOP); // nop
	bytes -= 4;
    }
}

// Generate forward branch to label:
ST_FUNC पूर्णांक gjmp(पूर्णांक t)
{
    पूर्णांक r = ind;
    अगर (nocode_wanted)
        वापस t;
    o(t);
    वापस r;
}

// Generate branch to known address:
ST_FUNC व्योम gjmp_addr(पूर्णांक a)
{
    निश्चित(a - ind + 0x8000000 < 0x10000000);
    o(ARM64_B | (((a - ind) >> 2) & 0x3ffffff));
}

ST_FUNC पूर्णांक gjmp_append(पूर्णांक n, पूर्णांक t)
{
    व्योम *p;
    /* insert vtop->c jump list in t */
    अगर (n) {
        uint32_t n1 = n, n2;
        जबतक ((n2 = read32le(p = cur_text_section->तथ्य + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    वापस t;
}

व्योम arm64_vset_VT_CMP(पूर्णांक op)
{
    अगर (op >= TOK_ULT && op <= TOK_GT) {
        vtop->cmp_r = vtop->r;
        vset_VT_CMP(0x80);
    }
}

अटल व्योम arm64_gen_opil(पूर्णांक op, uint32_t l);

अटल व्योम arm64_load_cmp(पूर्णांक r, SValue *sv)
{
    sv->r = sv->cmp_r;
    अगर (sv->c.i & 1) {
        vpushi(1);
        arm64_gen_opil('^', 0);
    }
    अगर (r != sv->r) {
        load(r, sv);
        sv->r = r;
    }
}

ST_FUNC पूर्णांक gjmp_cond(पूर्णांक op, पूर्णांक t)
{
    पूर्णांक bt = vtop->type.t & VT_BTYPE;

    पूर्णांक inv = op & 1;
    vtop->r = vtop->cmp_r;

    अगर (bt == VT_LDOUBLE) {
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
    अन्यथा अगर (bt == VT_FLOAT || bt == VT_DOUBLE) {
        uint32_t a = fltr(gv(RC_FLOAT));
        o(0x1e202008 | a << 5 | (bt != VT_FLOAT) << 22); // fcmp
        o(0x54000040 | !!inv); // b.eq/b.ne .+8
    }
    अन्यथा {
        uint32_t ll = (bt == VT_PTR || bt == VT_LLONG);
        uint32_t a = intr(gv(RC_INT));
        o(0x34000040 | a | !!inv << 24 | ll << 31); // cbz/cbnz wA,.+8
    }
    वापस gjmp(t);
}

अटल पूर्णांक arm64_iconst(uint64_t *val, SValue *sv)
{
    अगर ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        वापस 0;
    अगर (val) {
        पूर्णांक t = sv->type.t;
	पूर्णांक bt = t & VT_BTYPE;
        *val = ((bt == VT_LLONG || bt == VT_PTR) ? sv->c.i :
                (uint32_t)sv->c.i |
                (t & VT_UNSIGNED ? 0 : -(sv->c.i & 0x80000000)));
    }
    वापस 1;
}

अटल पूर्णांक arm64_gen_opic(पूर्णांक op, uint32_t l, पूर्णांक rev, uint64_t val,
                          uint32_t x, uint32_t a)
{
    अगर (op == '-' && !rev) {
        val = -val;
        op = '+';
    }
    val = l ? val : (uint32_t)val;

    चयन (op) {

    हाल '+': {
        uint32_t s = l ? val >> 63 : val >> 31;
        val = s ? -val : val;
        val = l ? val : (uint32_t)val;
        अगर (!(val & ~0xfffull))
            o(0x11000000 | l << 31 | s << 30 | x | a << 5 | val << 10);
        अन्यथा अगर (!(val & ~0xfff000ull))
            o(0x11400000 | l << 31 | s << 30 | x | a << 5 | val >> 12 << 10);
        अन्यथा {
            arm64_movimm(30, val); // use x30
            o(0x0b1e0000 | l << 31 | s << 30 | x | a << 5);
        }
        वापस 1;
      }

    हाल '-':
        अगर (!val)
            o(0x4b0003e0 | l << 31 | x | a << 16); // neg
        अन्यथा अगर (val == (l ? (uint64_t)-1 : (uint32_t)-1))
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
        अन्यथा {
            arm64_movimm(30, val); // use x30
            o(0x4b0003c0 | l << 31 | x | a << 16); // sub
        }
        वापस 1;

    हाल '^':
        अगर (val == -1 || (val == 0xffffffff && !l)) {
            o(0x2a2003e0 | l << 31 | x | a << 16); // mvn
            वापस 1;
        }
        // fall through
    हाल '&':
    हाल '|': {
        पूर्णांक e = arm64_encode_bimm64(l ? val : val | val << 32);
        अगर (e < 0)
            वापस 0;
        o((op == '&' ? 0x12000000 :
           op == '|' ? 0x32000000 : 0x52000000) |
          l << 31 | x | a << 5 | (uint32_t)e << 10);
        वापस 1;
    }

    हाल TOK_SAR:
    हाल TOK_SHL:
    हाल TOK_SHR: {
        uint32_t n = 32 << l;
        val = val & (n - 1);
        अगर (rev)
            वापस 0;
        अगर (!val) {
            // tcc_warning("shift count >= width of type");
            o(0x2a0003e0 | l << 31 | a << 16);
            वापस 1;
        }
        अन्यथा अगर (op == TOK_SHL)
            o(0x53000000 | l << 31 | l << 22 | x | a << 5 |
              (n - val) << 16 | (n - 1 - val) << 10); // lsl
        अन्यथा
            o(0x13000000 | (op == TOK_SHR) << 30 | l << 31 | l << 22 |
              x | a << 5 | val << 16 | (n - 1) << 10); // lsr/asr
        वापस 1;
    }

    }
    वापस 0;
}

अटल व्योम arm64_gen_opil(पूर्णांक op, uint32_t l)
{
    uint32_t x, a, b;

    // Special treatment for operations with a constant operand:
    {
        uint64_t val;
        पूर्णांक rev = 1;

        अगर (arm64_iconst(0, &vtop[0])) {
            vswap();
            rev = 0;
        }
        अगर (arm64_iconst(&val, &vtop[-1])) {
            gv(RC_INT);
            a = intr(vtop[0].r);
            --vtop;
            x = get_reg(RC_INT);
            ++vtop;
            अगर (arm64_gen_opic(op, l, rev, val, intr(x), a)) {
                vtop[0].r = x;
                vswap();
                --vtop;
                वापस;
            }
        }
        अगर (!rev)
            vswap();
    }

    gv2(RC_INT, RC_INT);
    निश्चित(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = intr(vtop[-1].r);
    b = intr(vtop[0].r);
    vtop -= 2;
    x = get_reg(RC_INT);
    ++vtop;
    vtop[0].r = x;
    x = intr(x);

    चयन (op) {
    हाल '%':
        // Use x30 for quotient:
        o(0x1ac00c00 | l << 31 | 30 | a << 5 | b << 16); // sdiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        अवरोध;
    हाल '&':
        o(0x0a000000 | l << 31 | x | a << 5 | b << 16); // and
        अवरोध;
    हाल '*':
        o(0x1b007c00 | l << 31 | x | a << 5 | b << 16); // mul
        अवरोध;
    हाल '+':
        o(0x0b000000 | l << 31 | x | a << 5 | b << 16); // add
        अवरोध;
    हाल '-':
        o(0x4b000000 | l << 31 | x | a << 5 | b << 16); // sub
        अवरोध;
    हाल '/':
    हाल TOK_PDIV:
        o(0x1ac00c00 | l << 31 | x | a << 5 | b << 16); // sdiv
        अवरोध;
    हाल '^':
        o(0x4a000000 | l << 31 | x | a << 5 | b << 16); // eor
        अवरोध;
    हाल '|':
        o(0x2a000000 | l << 31 | x | a << 5 | b << 16); // orr
        अवरोध;
    हाल TOK_EQ:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f17e0 | x); // cset wA,eq
        अवरोध;
    हाल TOK_GE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fb7e0 | x); // cset wA,ge
        अवरोध;
    हाल TOK_GT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fd7e0 | x); // cset wA,gt
        अवरोध;
    हाल TOK_LE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fc7e0 | x); // cset wA,le
        अवरोध;
    हाल TOK_LT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9fa7e0 | x); // cset wA,lt
        अवरोध;
    हाल TOK_NE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f07e0 | x); // cset wA,ne
        अवरोध;
    हाल TOK_SAR:
        o(0x1ac02800 | l << 31 | x | a << 5 | b << 16); // asr
        अवरोध;
    हाल TOK_SHL:
        o(0x1ac02000 | l << 31 | x | a << 5 | b << 16); // lsl
        अवरोध;
    हाल TOK_SHR:
        o(0x1ac02400 | l << 31 | x | a << 5 | b << 16); // lsr
        अवरोध;
    हाल TOK_UDIV:
        o(0x1ac00800 | l << 31 | x | a << 5 | b << 16); // udiv
        अवरोध;
    हाल TOK_UGE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f37e0 | x); // cset wA,cs
        अवरोध;
    हाल TOK_UGT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f97e0 | x); // cset wA,hi
        अवरोध;
    हाल TOK_ULT:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f27e0 | x); // cset wA,cc
        अवरोध;
    हाल TOK_ULE:
        o(0x6b00001f | l << 31 | a << 5 | b << 16); // cmp
        o(0x1a9f87e0 | x); // cset wA,ls
        अवरोध;
    हाल TOK_UMOD:
        // Use x30 for quotient:
        o(0x1ac00800 | l << 31 | 30 | a << 5 | b << 16); // udiv
        o(0x1b008000 | l << 31 | x | (uint32_t)30 << 5 |
          b << 16 | a << 10); // msub
        अवरोध;
    शेष:
        निश्चित(0);
    }
}

ST_FUNC व्योम gen_opi(पूर्णांक op)
{
    arm64_gen_opil(op, 0);
    arm64_vset_VT_CMP(op);
}

ST_FUNC व्योम gen_opl(पूर्णांक op)
{
    arm64_gen_opil(op, 1);
    arm64_vset_VT_CMP(op);
}

ST_FUNC व्योम gen_opf(पूर्णांक op)
{
    uint32_t x, a, b, dbl;
    पूर्णांक bt = vtop[0].type.t & VT_BTYPE;

    अगर (op == TOK_NEG) {
        अगर (bt == VT_LDOUBLE) {
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
        वापस;
    }

    अगर (bt == VT_LDOUBLE) {
        CType type = vtop[0].type;
        पूर्णांक func = 0;
        पूर्णांक cond = -1;
        चयन (op) {
        हाल '*': func = TOK___multf3; अवरोध;
        हाल '+': func = TOK___addtf3; अवरोध;
        हाल '-': func = TOK___subtf3; अवरोध;
        हाल '/': func = TOK___divtf3; अवरोध;
        हाल TOK_EQ: func = TOK___eqtf2; cond = 1; अवरोध;
        हाल TOK_NE: func = TOK___netf2; cond = 0; अवरोध;
        हाल TOK_LT: func = TOK___lttf2; cond = 10; अवरोध;
        हाल TOK_GE: func = TOK___getf2; cond = 11; अवरोध;
        हाल TOK_LE: func = TOK___letf2; cond = 12; अवरोध;
        हाल TOK_GT: func = TOK___gttf2; cond = 13; अवरोध;
        शेष: निश्चित(0); अवरोध;
        }
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = cond < 0 ? REG_FRET : REG_IRET;
        अगर (cond < 0)
            vtop->type = type;
        अन्यथा {
            o(0x7100001f); // cmp w0,#0
            o(0x1a9f07e0 | (uint32_t)cond << 12); // cset w0,(cond)
        }
        arm64_vset_VT_CMP(op);
        वापस;
    }

    dbl = bt != VT_FLOAT;
    gv2(RC_FLOAT, RC_FLOAT);
    निश्चित(vtop[-1].r < VT_CONST && vtop[0].r < VT_CONST);
    a = fltr(vtop[-1].r);
    b = fltr(vtop[0].r);
    vtop -= 2;
    चयन (op) {
    हाल TOK_EQ: हाल TOK_NE:
    हाल TOK_LT: हाल TOK_GE: हाल TOK_LE: हाल TOK_GT:
        x = get_reg(RC_INT);
        ++vtop;
        vtop[0].r = x;
        x = intr(x);
        अवरोध;
    शेष:
        x = get_reg(RC_FLOAT);
        ++vtop;
        vtop[0].r = x;
        x = fltr(x);
        अवरोध;
    }

    चयन (op) {
    हाल '*':
        o(0x1e200800 | dbl << 22 | x | a << 5 | b << 16); // fmul
        अवरोध;
    हाल '+':
        o(0x1e202800 | dbl << 22 | x | a << 5 | b << 16); // fadd
        अवरोध;
    हाल '-':
        o(0x1e203800 | dbl << 22 | x | a << 5 | b << 16); // fsub
        अवरोध;
    हाल '/':
        o(0x1e201800 | dbl << 22 | x | a << 5 | b << 16); // fdiv
        अवरोध;
    हाल TOK_EQ:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f17e0 | x); // cset w(x),eq
        अवरोध;
    हाल TOK_GE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fb7e0 | x); // cset w(x),ge
        अवरोध;
    हाल TOK_GT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9fd7e0 | x); // cset w(x),gt
        अवरोध;
    हाल TOK_LE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f87e0 | x); // cset w(x),ls
        अवरोध;
    हाल TOK_LT:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f57e0 | x); // cset w(x),mi
        अवरोध;
    हाल TOK_NE:
        o(0x1e202000 | dbl << 22 | a << 5 | b << 16); // fcmp
        o(0x1a9f07e0 | x); // cset w(x),ne
        अवरोध;
    शेष:
        निश्चित(0);
    }
    arm64_vset_VT_CMP(op);
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC व्योम gen_cvt_sxtw(व्योम)
{
    uint32_t r = intr(gv(RC_INT));
    o(0x93407c00 | r | r << 5); // sxtw x(r),w(r)
}

/* char/short to int conversion */
ST_FUNC व्योम gen_cvt_csti(पूर्णांक t)
{
    पूर्णांक r = intr(gv(RC_INT));
    o(0x13001c00
        | ((t & VT_BTYPE) == VT_SHORT) << 13
        | (uint32_t)!!(t & VT_UNSIGNED) << 30
        | r | r << 5); // [su]xt[bh] w(r),w(r)
}

ST_FUNC व्योम gen_cvt_itof(पूर्णांक t)
{
    अगर (t == VT_LDOUBLE) {
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
        वापस;
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

ST_FUNC व्योम gen_cvt_ftoi(पूर्णांक t)
{
    अगर ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        पूर्णांक func = (t & VT_BTYPE) == VT_LLONG ?
          (t & VT_UNSIGNED ? TOK___fixunstfdi : TOK___fixtfdi) :
          (t & VT_UNSIGNED ? TOK___fixunstfsi : TOK___fixtfsi);
        vpush_helper_func(func);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        vtop->type.t = t;
        vtop->r = REG_IRET;
        वापस;
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

ST_FUNC व्योम gen_cvt_ftof(पूर्णांक t)
{
    पूर्णांक f = vtop[0].type.t & VT_BTYPE;
    निश्चित(t == VT_FLOAT || t == VT_DOUBLE || t == VT_LDOUBLE);
    निश्चित(f == VT_FLOAT || f == VT_DOUBLE || f == VT_LDOUBLE);
    अगर (t == f)
        वापस;

    अगर (t == VT_LDOUBLE || f == VT_LDOUBLE) {
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
        निश्चित(vtop[0].r < VT_CONST);
        a = fltr(vtop[0].r);
        x = a;
        अगर (f == VT_FLOAT)
            o(0x1e22c000 | x | a << 5); // fcvt d(x),s(a)
        अन्यथा
            o(0x1e624000 | x | a << 5); // fcvt s(x),d(a)
    }
}

/* increment tcov counter */
ST_FUNC व्योम gen_increment_tcov (SValue *sv)
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

ST_FUNC व्योम ggoto(व्योम)
{
    arm64_gen_bl_or_b(1);
    --vtop;
}

ST_FUNC व्योम gen_clear_cache(व्योम)
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
    write32le(cur_text_section->तथ्य + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | end << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0x51000400 | p | isz << 5); // sub w(p),w(isz),#1
    o(0x8a240004 | p | beg << 5 | p << 16); // bic x(p),x(beg),x(p)
    b1 = ind; o(ARM64_B); // b
    lab1 = ind;
    o(0xd50b7520 | p); // ic ivau,x(p)
    o(0x8b000000 | p | p << 5 | isz << 16); // add x(p),x(p),x(isz)
    write32le(cur_text_section->तथ्य + b1, ARM64_B | ((ind - b1) >> 2));
    o(0xeb00001f | p << 5 | end << 16); // cmp x(p),x(end)
    o(0x54ffffa3 | ((lab1 - ind) << 3 & 0xffffe0)); // b.cc lab1
    o(0xd5033b9f); // dsb ish
    o(0xd5033fdf); // isb
}

ST_FUNC व्योम gen_vla_sp_save(पूर्णांक addr) {
    uint32_t r = intr(get_reg(RC_INT));
    o(0x910003e0 | r); // mov x(r),sp
    arm64_strx(3, r, 29, addr);
}

ST_FUNC व्योम gen_vla_sp_restore(पूर्णांक addr) {
    // Use x30 because this function can be called when there
    // is a live return value in x0 but there is nothing on
    // the value stack to prevent get_reg from returning x0.
    uint32_t r = 30;
    arm64_ldrx(0, 3, r, 29, addr);
    o(0x9100001f | r << 5); // mov sp,x(r)
}

ST_FUNC व्योम gen_vla_alloc(CType *type, पूर्णांक align) {
    uint32_t r;
#अगर defined(CONFIG_TCC_BCHECK)
    अगर (tcc_state->do_bounds_check)
        vpushv(vtop);
#पूर्ण_अगर
    r = intr(gv(RC_INT));
#अगर defined(CONFIG_TCC_BCHECK)
    अगर (tcc_state->do_bounds_check)
        o(0x91004000 | r | r << 5); // add x(r),x(r),#15+1
    अन्यथा
#पूर्ण_अगर
    o(0x91003c00 | r | r << 5); // add x(r),x(r),#15
    o(0x927cec00 | r | r << 5); // bic x(r),x(r),#15
    o(0xcb2063ff | r << 16); // sub sp,sp,x(r)
    vpop();
#अगर defined(CONFIG_TCC_BCHECK)
    अगर (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R(0);
        o(0x910003e0 | vtop->r); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_add_epilog = 1;
    }
#पूर्ण_अगर
}

/* end of A64 code generator */
/*************************************************************/
#पूर्ण_अगर
/*************************************************************/
