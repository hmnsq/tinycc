/*
 *  x86-64 code generator for TCC
 *
 *  Copyright (c) 2008 Shinichiro Hamaji
 *
 *  Based on i386-gen.c by Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

/* number of available registers */
#ವ್ಯಾಖ್ಯಾನಿಸು NB_REGS         25
#ವ್ಯಾಖ್ಯಾನಿಸು NB_ASM_REGS     16
#ವ್ಯಾಖ್ಯಾನಿಸು CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_INT     0x0001 /* generic integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FLOAT   0x0002 /* generic float register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_RAX     0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು RC_RDX     0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು RC_RCX     0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು RC_RSI     0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು RC_RDI     0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು RC_ST0     0x0080 /* only for long double */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R8      0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R9      0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R10     0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R11     0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು RC_XMM0    0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_XMM1    0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_XMM2    0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_XMM3    0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_XMM4    0x10000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_XMM5    0x20000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_XMM6    0x40000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_XMM7    0x80000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_IRET    RC_RAX /* function return: integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_IRE2    RC_RDX /* function return: second integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FRET    RC_XMM0 /* function return: float register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FRE2    RC_XMM1 /* function return: second float register */

/* pretty names for the registers */
ಎಣಿಕೆ {
    TREG_RAX = 0,
    TREG_RCX = 1,
    TREG_RDX = 2,
    TREG_RSP = 4,
    TREG_RSI = 6,
    TREG_RDI = 7,

    TREG_R8  = 8,
    TREG_R9  = 9,
    TREG_R10 = 10,
    TREG_R11 = 11,

    TREG_XMM0 = 16,
    TREG_XMM1 = 17,
    TREG_XMM2 = 18,
    TREG_XMM3 = 19,
    TREG_XMM4 = 20,
    TREG_XMM5 = 21,
    TREG_XMM6 = 22,
    TREG_XMM7 = 23,

    TREG_ST0 = 24,

    TREG_MEM = 0x20
};

#ವ್ಯಾಖ್ಯಾನಿಸು REX_ತಳ(reg) (((reg) >> 3) & 1)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಮೌಲ್ಯ(reg) ((reg) & 7)

/* return registers for function */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_IRET TREG_RAX /* single word int return register */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_IRE2 TREG_RDX /* second word return register (for long long) */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_FRET TREG_XMM0 /* float return register */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_FRE2 TREG_XMM1 /* second float return register */

/* defined if function parameters must be evaluated in reverse order */
#ವ್ಯಾಖ್ಯಾನಿಸು INVERT_FUNC_PARAMS

/* pointer size, in bytes */
#ವ್ಯಾಖ್ಯಾನಿಸು PTR_ಗಾತ್ರ 8

/* long double size and alignment, in bytes */
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ಗಾತ್ರ  16
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ALIGN 16
/* maximum alignment (for aligned attribute support) */
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_ALIGN     16

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#ವ್ಯಾಖ್ಯಾನಿಸು PROMOTE_RET

#ವ್ಯಾಖ್ಯಾನಿಸು TCC_ಗುರಿ_NATIVE_STRUCT_COPY
ST_FUNC ಶೂನ್ಯ gen_struct_copy(ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2);

/******************************************************/
#ಇಲ್ಲದಿದ್ದರೆ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"
#ಅನ್ತರ್ಭಾವ <assert.h>

ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ ಗುರಿ_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ reg_classes[NB_REGS] = {
    /* eax */ RC_INT | RC_RAX,
    /* ecx */ RC_INT | RC_RCX,
    /* edx */ RC_INT | RC_RDX,
    0,
    0,
    0,
    RC_RSI,
    RC_RDI,
    RC_R8,
    RC_R9,
    RC_R10,
    RC_R11,
    0,
    0,
    0,
    0,
    /* xmm0 */ RC_FLOAT | RC_XMM0,
    /* xmm1 */ RC_FLOAT | RC_XMM1,
    /* xmm2 */ RC_FLOAT | RC_XMM2,
    /* xmm3 */ RC_FLOAT | RC_XMM3,
    /* xmm4 */ RC_FLOAT | RC_XMM4,
    /* xmm5 */ RC_FLOAT | RC_XMM5,
    /* xmm6 an xmm7 are included so gv() can be used on them,
       but they are not tagged with RC_FLOAT because they are
       callee saved on Windows */
    RC_XMM6,
    RC_XMM7,
    /* st0 */ RC_ST0
};

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ func_sub_sp_ಸ್ಥಾನಾಂತರ;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ func_ret_sub;

#ಆದರೆ defined(CONFIG_TCC_BCHECK)
ಸ್ಥಿರ addr_t func_bound_ಸ್ಥಾನಾಂತರ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ func_bound_ind;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_bound_ಕೂಡಿಸು_epilog;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ func_scratch, func_alloca;
#ಆದರೆ_ಅಂತ್ಯ

/* XXX: make it faster ? */
ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಂಕ c)
{
    ಪೂರ್ಣಾಂಕ ind1;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    ind1 = ind + 1;
    ಆದರೆ (ind1 > cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_allocated)
        section_realloc(cur_ಪಠ್ಯ_section, ind1);
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind] = c;
    ind = ind1;
}

ST_FUNC ಶೂನ್ಯ o(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ c)
{
    ಆಗ (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಂಕ v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಂಕ c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

ST_FUNC ಶೂನ್ಯ gen_le64(int64_t c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
    g(c >> 32);
    g(c >> 40);
    g(c >> 48);
    g(c >> 56);
}

ಸ್ಥಿರ ಶೂನ್ಯ orex(ಪೂರ್ಣಾಂಕ ll, ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ r2, ಪೂರ್ಣಾಂಕ b)
{
    ಆದರೆ ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    ಆದರೆ ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    ಆದರೆ (ll || REX_ತಳ(r) || REX_ತಳ(r2)) {
        ಆದರೆ ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_ತಳ(r) | (REX_ತಳ(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC ಶೂನ್ಯ gsym_addr(ಪೂರ್ಣಾಂಕ t, ಪೂರ್ಣಾಂಕ a)
{
    ಆಗ (t) {
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr = cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is64_type(ಪೂರ್ಣಾಂಕ t)
{
    ಹಿಂತಿರುಗಿ ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ oad(ಪೂರ್ಣಾಂಕ c, ಪೂರ್ಣಾಂಕ s)
{
    ಪೂರ್ಣಾಂಕ t;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ s;
    o(c);
    t = ind;
    gen_le32(s);
    ಹಿಂತಿರುಗಿ t;
}

/* generate jmp to a label */
#ವ್ಯಾಖ್ಯಾನಿಸು gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC ಶೂನ್ಯ gen_addr32(ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c)
{
    ಆದರೆ (r & VT_SYM)
        greloca(cur_ಪಠ್ಯ_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ಶೂನ್ಯ gen_addrpc32(ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c)
{
    ಆದರೆ (r & VT_SYM)
        greloca(cur_ಪಠ್ಯ_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
ಸ್ಥಿರ ಶೂನ್ಯ gen_gotpcrel(ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, ಖಾಲಿ), c, r,
        cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind-3],
        cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind-2],
        cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind-1]
        );
#ಆದರೆ_ಅಂತ್ಯ
    greloca(cur_ಪಠ್ಯ_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    ಆದರೆ (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_ಮೌಲ್ಯ(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
ಸ್ಥಿರ ಶೂನ್ಯ gen_modrm_impl(ಪೂರ್ಣಾಂಕ opcode, ಪೂರ್ಣಾಂಕ ll, ಪೂರ್ಣಾಂಕ op_reg_0, ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c)
{
    ಪೂರ್ಣಾಂಕ op_reg = REG_ಮೌಲ್ಯ(op_reg_0) << 3;

    ಆದರೆ ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        Sym *s2 = external_global_sym(TOK_tls_ಸೂಚ್ಯಂಕ, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_ಗಾತ್ರ); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_ಪಠ್ಯ_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#ಇಲ್ಲದಿದ್ದರೆ
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_ಪಠ್ಯ_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#ಆದರೆ_ಅಂತ್ಯ
        ಹಿಂತಿರುಗಿ;
    }

    orex(ll, r, op_reg_0, opcode);

    ಆದರೆ ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	ಆದರೆ (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} ಇಲ್ಲದಿದ್ದರೆ {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    ಆದರೆ (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } ಇಲ್ಲದಿದ್ದರೆ {
		gen_addrpc32(r, sym, c);
	    }
	}
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        ಆದರೆ (c == (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } ಇಲ್ಲದಿದ್ದರೆ {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_ಮೌಲ್ಯ(r));
        gen_le32(c);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (r & VT_LVAL) {
        g(0x00 | op_reg | REG_ಮೌಲ್ಯ(r));
    } ಇಲ್ಲದಿದ್ದರೆ {
        g(0xc0 | op_reg | REG_ಮೌಲ್ಯ(r));
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_modrm64(ಪೂರ್ಣಾಂಕ opcode, ಪೂರ್ಣಾಂಕ op_reg, ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_modrm32(ಪೂರ್ಣಾಂಕ opcode, ಪೂರ್ಣಾಂಕ op_reg, ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
ಶೂನ್ಯ ತುಂಬು(ಪೂರ್ಣಾಂಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಂಕ v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    ಆದರೆ (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_PE
    /* we use indirect access via got */
    ಆದರೆ ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        ಪೂರ್ಣಾಂಕ tr = r | TREG_MEM;
        ಆದರೆ (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#ಆದರೆ_ಅಂತ್ಯ

    v = fr & VT_VALMASK;
    ಆದರೆ (fr & VT_LVAL) {
        ಪೂರ್ಣಾಂಕ b, ll;
        ಆದರೆ (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = ಖಾಲಿ;
            fr = r;
            ಆದರೆ (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            ತುಂಬು(fr, &v1);
            fr |= VT_LVAL;
        }
	ಆದರೆ (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = ಖಾಲಿ;
	    fr = r;
	    ಆದರೆ (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    ತುಂಬು(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	ಆದರೆ ((ft & VT_BTYPE) == VT_STRUCT) {
	    ಪೂರ್ಣಾಂಕ align;
	    ಆಯ್ಕೆ (type_ಗಾತ್ರ(&sv->type, &align)) {
		ಸ್ಥಿತಿ 1: ft = VT_BYTE; ನಿಲ್ಲಿಸು;
		ಸ್ಥಿತಿ 2: ft = VT_SHORT; ನಿಲ್ಲಿಸು;
		ಸ್ಥಿತಿ 4: ft = VT_INT; ನಿಲ್ಲಿಸು;
		ಸ್ಥಿತಿ 8: ft = VT_LLONG; ನಿಲ್ಲಿಸು;
		ಪೂರ್ವನಿಯೋಜಿತ:
		    tcc_error("invalid aggregate type for register load");
		    ನಿಲ್ಲಿಸು;
	    }
	}
        ಆದರೆ ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_ಮೌಲ್ಯ(r); /* movd */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_ಮೌಲ್ಯ(r);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            ಹಿಂತಿರುಗಿ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಪ್ರತಿಜ್ಞಾ(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (v == VT_CONST) {
            ಆದರೆ (fr & VT_SYM) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#ಇಲ್ಲದಿದ್ದರೆ
                ಆದರೆ (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, ಖಾಲಿ, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_ಮೌಲ್ಯ(r), 0);
                    greloca(cur_ಪಠ್ಯ_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_ಮೌಲ್ಯ(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_ಮೌಲ್ಯ(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#ಆದರೆ_ಅಂತ್ಯ
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (is64_type(ft)) {
                ಆದರೆ (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_ಮೌಲ್ಯ(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_ಮೌಲ್ಯ(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_ಮೌಲ್ಯ(r) * 9);
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                orex(0,r,0, 0xb8 + REG_ಮೌಲ್ಯ(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_CMP) {
	    ಆದರೆ (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_ಮೌಲ್ಯ(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_ತಳ(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_ಮೌಲ್ಯ(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_ಮೌಲ್ಯ(r) * 0x900); /* movzbl %al, %eax */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_ಮೌಲ್ಯ(r), t); /* mov $1, r */
            o(0x05eb + (REX_ತಳ(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_ಮೌಲ್ಯ(r), t ^ 1); /* mov $0, r */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v != r) {
            ಆದರೆ ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                ಆದರೆ (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_ಮೌಲ್ಯ(r)*8); /* %xmmN */
                    o(0xf024);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ಪ್ರತಿಜ್ಞಾ((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    ಆದರೆ ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        ಪ್ರತಿಜ್ಞಾ((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_ಮೌಲ್ಯ(v) + REG_ಮೌಲ್ಯ(r)*8);
                }
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (r == TREG_ST0) {
                ಪ್ರತಿಜ್ಞಾ((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_ಮೌಲ್ಯ(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } ಇಲ್ಲದಿದ್ದರೆ {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_ಮೌಲ್ಯ(r) + REG_ಮೌಲ್ಯ(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
ಶೂನ್ಯ store(ಪೂರ್ಣಾಂಕ r, SValue *v)
{
    ಪೂರ್ಣಾಂಕ fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    ಪೂರ್ಣಾಂಕ opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    ಆದರೆ (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_PE
    /* we need to access the variable via got */
    ಆದರೆ ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#ಆದರೆ_ಅಂತ್ಯ

    /* XXX: incorrect if float reg to reg */
    ಆದರೆ (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_ಮೌಲ್ಯ(r);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_ಮೌಲ್ಯ(r);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } ಇಲ್ಲದಿದ್ದರೆ {
        opc = 0x89;
        ಆದರೆ (bt == VT_SHORT)
            opc = 0x8966;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
ಸ್ಥಿರ ಶೂನ್ಯ gcall_or_jmp(ಪೂರ್ಣಾಂಕ is_jmp)
{
    ಪೂರ್ಣಾಂಕ r;
    ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (ಪೂರ್ಣಾಂಕ)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_ಪಠ್ಯ_section, vtop->sym, ind + 1, R_X86_64_PLT32, (ಪೂರ್ಣಾಂಕ)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* otherwise, indirect call */
        r = TREG_R11;
        ತುಂಬು(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_ಮೌಲ್ಯ(r) + (is_jmp << 4));
    }
}

#ಆದರೆ defined(CONFIG_TCC_BCHECK)

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_call(ಪೂರ್ಣಾಂಕ v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_ಪಠ್ಯ_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
# define TREG_FASTCALL_1 TREG_RCX
#ಇಲ್ಲದಿದ್ದರೆ
# define TREG_FASTCALL_1 TREG_RDI
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_prolog(ಶೂನ್ಯ)
{
    /* leave some room for bound checking code */
    func_bound_ಸ್ಥಾನಾಂತರ = lbounds_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    func_bound_ind = ind;
    func_bound_ಕೂಡಿಸು_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
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
        greloca(cur_ಪಠ್ಯ_section, sym_ದತ್ತಾಂಶ, ind + 3, R_X86_64_PC32, -4);
        ind = ind + 7;
        gen_bounds_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0x5250); /* save returned value, if any */
    o(0x20ec8348); /* sub $32,%rsp */
    o(0x290f);     /* movaps %xmm0,0x10(%rsp) */
    o(0x102444);
    o(0x240c290f); /* movaps %xmm1,(%rsp) */
    greloca(cur_ಪಠ್ಯ_section, sym_ದತ್ತಾಂಶ, ind + 3, R_X86_64_PC32, -4);
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /* lea xxx(%rip), %rcx/rdi */
    gen_le32 (0);
    gen_bounds_call(TOK___bound_local_delete);
    o(0x280f);     /* movaps 0x10(%rsp),%xmm0 */
    o(0x102444);
    o(0x240c280f); /* movaps (%rsp),%xmm1 */
    o(0x20c48348); /* add $32,%rsp */
    o(0x585a); /* restore returned value, if any */
}
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE

#ವ್ಯಾಖ್ಯಾನಿಸು REGN 4
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arg_prepare_reg(ಪೂರ್ಣಾಂಕ idx) {
  ಆದರೆ (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      ಹಿಂತಿರುಗಿ idx + 10;
  ಇಲ್ಲದಿದ್ದರೆ
      ಹಿಂತಿರುಗಿ idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

ಸ್ಥಿರ ಶೂನ್ಯ gen_offs_sp(ಪೂರ್ಣಾಂಕ b, ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    ಆದರೆ (d == (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)d) {
        o(0x2444 | (REG_ಮೌಲ್ಯ(r) << 3));
        g(d);
    } ಇಲ್ಲದಿದ್ದರೆ {
        o(0x2484 | (REG_ಮೌಲ್ಯ(r) << 3));
        gen_le32(d);
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ using_regs(ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
    ಹಿಂತಿರುಗಿ !(ಗಾತ್ರ_2 > 8 || (ಗಾತ್ರ_2 & (ಗಾತ್ರ_2 - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ಪೂರ್ಣಾಂಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಂಕ variadic, CType *ret, ಪೂರ್ಣಾಂಕ *ret_align, ಪೂರ್ಣಾಂಕ *regsize)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(vt, &align);
    ಆದರೆ (!using_regs(ಗಾತ್ರ_2))
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (ಗಾತ್ರ_2 == 8)
        ret->t = VT_LLONG;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2 == 4)
        ret->t = VT_INT;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2 == 2)
        ret->t = VT_SHORT;
    ಇಲ್ಲದಿದ್ದರೆ
        ret->t = VT_BYTE;
    ret->ref = ಖಾಲಿ;
    ಹಿಂತಿರುಗಿ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_sse_float(ಪೂರ್ಣಾಂಕ t) {
    ಪೂರ್ಣಾಂಕ bt;
    bt = t & VT_BTYPE;
    ಹಿಂತಿರುಗಿ bt == VT_DOUBLE || bt == VT_FLOAT;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ gfunc_arg_ಗಾತ್ರ(CType *type) {
    ಪೂರ್ಣಾಂಕ align;
    ಆದರೆ (type->t & (VT_ARRAY|VT_BITFIELD))
        ಹಿಂತಿರುಗಿ 8;
    ಹಿಂತಿರುಗಿ type_ಗಾತ್ರ(type, &align);
}

ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, r, ವಾದಗಳು_ಗಾತ್ರ, i, d, bt, struct_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ arg;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gbound_ವಾದಗಳು(nb_ವಾದಗಳು);
#ಆದರೆ_ಅಂತ್ಯ

    save_regs(nb_ವಾದಗಳು);

    ವಾದಗಳು_ಗಾತ್ರ = (nb_ವಾದಗಳು < REGN ? REGN : nb_ವಾದಗಳು) * PTR_ಗಾತ್ರ;
    arg = nb_ವಾದಗಳು;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_ಗಾತ್ರ = ವಾದಗಳು_ಗಾತ್ರ;
    ಗಾಗಿ(i = 0; i < nb_ವಾದಗಳು; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        ಗಾತ್ರ_2 = gfunc_arg_ಗಾತ್ರ(&sv->type);

        ಆದರೆ (using_regs(ಗಾತ್ರ_2))
            ಮುಂದುವರಿ; /* arguments smaller than 8 bytes passed in registers or on stack */

        ಆದರೆ (bt == VT_STRUCT) {
            /* align to stack align size */
            ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 15) & ~15;
            /* generate structure store */
            r = get_reg(RC_INT);
            gen_offs_sp(0x8d, r, struct_ಗಾತ್ರ);
            struct_ಗಾತ್ರ += ಗಾತ್ರ_2;

            /* generate memcpy call */
            vset(&sv->type, r | VT_LVAL, 0);
            vpushv(sv);
            vstore();
            --vtop;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_ಗಾತ್ರ);
            struct_ಗಾತ್ರ += 16;
        }
    }

    ಆದರೆ (func_scratch < struct_ಗಾತ್ರ)
        func_scratch = struct_ಗಾತ್ರ;

    arg = nb_ವಾದಗಳು;
    struct_ಗಾತ್ರ = ವಾದಗಳು_ಗಾತ್ರ;

    ಗಾಗಿ(i = 0; i < nb_ವಾದಗಳು; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        ಗಾತ್ರ_2 = gfunc_arg_ಗಾತ್ರ(&vtop->type);
        ಆದರೆ (!using_regs(ಗಾತ್ರ_2)) {
            /* align to stack align size */
            ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 15) & ~15;
            ಆದರೆ (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_ಗಾತ್ರ);
                gen_offs_sp(0x89, d, arg*8);
            } ಇಲ್ಲದಿದ್ದರೆ {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_ಗಾತ್ರ);
            }
            struct_ಗಾತ್ರ += ಗಾತ್ರ_2;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (is_sse_float(vtop->type.t)) {
		ಆದರೆ (tcc_state->nosse)
		  tcc_error("SSE disabled");
                ಆದರೆ (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_ಮೌಲ್ಯ(d));
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ (bt == VT_STRUCT) {
                    vtop->type.ref = ಖಾಲಿ;
                    vtop->type.t = ಗಾತ್ರ_2 > 4 ? VT_LLONG : ಗಾತ್ರ_2 > 2 ? VT_INT
                        : ಗಾತ್ರ_2 > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                ಆದರೆ (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_ಮೌಲ್ಯ(r) * 8 + REG_ಮೌಲ್ಯ(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    ಆದರೆ (nb_ವಾದಗಳು > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        ಆದರೆ (nb_ವಾದಗಳು > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    ಆದರೆ ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#ಆದರೆ_ಅಂತ್ಯ
    }
    vtop--;
}

#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_PROLOG_ಗಾತ್ರ 11

/* generate function prolog of type 't' */
ಶೂನ್ಯ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ಪೂರ್ಣಾಂಕ addr, reg_param_ಸೂಚ್ಯಂಕ, bt, ಗಾತ್ರ_2;
    Sym *sym;
    CType *type;

    func_ret_sub = 0;
    func_scratch = 32;
    func_alloca = 0;
    loc = 0;

    addr = PTR_ಗಾತ್ರ * 2;
    ind += FUNC_PROLOG_ಗಾತ್ರ;
    func_sub_sp_ಸ್ಥಾನಾಂತರ = ind;
    reg_param_ಸೂಚ್ಯಂಕ = 0;

    sym = func_type->ref;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    ಗಾತ್ರ_2 = gfunc_arg_ಗಾತ್ರ(&func_vt);
    ಆದರೆ (!using_regs(ಗಾತ್ರ_2)) {
        gen_modrm64(0x89, arg_regs[reg_param_ಸೂಚ್ಯಂಕ], VT_LOCAL, ಖಾಲಿ, addr);
        func_vc = addr;
        reg_param_ಸೂಚ್ಯಂಕ++;
        addr += 8;
    }

    /* define parameters */
    ಆಗ ((sym = sym->ಮುಂದಿನ) != ಖಾಲಿ) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        ಗಾತ್ರ_2 = gfunc_arg_ಗಾತ್ರ(type);
        ಆದರೆ (!using_regs(ಗಾತ್ರ_2)) {
            ಆದರೆ (reg_param_ಸೂಚ್ಯಂಕ < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_ಸೂಚ್ಯಂಕ], VT_LOCAL, ಖಾಲಿ, addr);
            }
            gfunc_ಗಣ_param(sym, addr, 1);
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (reg_param_ಸೂಚ್ಯಂಕ < REGN) {
                /* save arguments passed by register */
                ಆದರೆ ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    ಆದರೆ (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_ಸೂಚ್ಯಂಕ, VT_LOCAL, ಖಾಲಿ, addr);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    gen_modrm64(0x89, arg_regs[reg_param_ಸೂಚ್ಯಂಕ], VT_LOCAL, ಖಾಲಿ, addr);
                }
            }
            gfunc_ಗಣ_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_ಸೂಚ್ಯಂಕ++;
    }

    ಆಗ (reg_param_ಸೂಚ್ಯಂಕ < REGN) {
        ಆದರೆ (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_ಸೂಚ್ಯಂಕ], VT_LOCAL, ಖಾಲಿ, addr);
            addr += 8;
        }
        reg_param_ಸೂಚ್ಯಂಕ++;
    }
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#ಆದರೆ_ಅಂತ್ಯ
}

/* generate function epilog */
ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ v, ಆರಂಭ;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#ಆದರೆ_ಅಂತ್ಯ

    o(0xc9); /* leave */
    ಆದರೆ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ಇಲ್ಲದಿದ್ದರೆ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    ಆರಂಭ = func_sub_sp_ಸ್ಥಾನಾಂತರ - FUNC_PROLOG_ಗಾತ್ರ;
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = ind;
    pe_ಕೂಡಿಸು_unwind_ದತ್ತಾಂಶ(ಆರಂಭ, ind, v);

    ind = ಆರಂಭ;
    ಆದರೆ (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_ಪಠ್ಯ_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } ಇಲ್ಲದಿದ್ದರೆ {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#ಇಲ್ಲದಿದ್ದರೆ

ಸ್ಥಿರ ಶೂನ್ಯ gadd_sp(ಪೂರ್ಣಾಂಕ val)
{
    ಆದರೆ (val == (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)val) {
        o(0xc48348);
        g(val);
    } ಇಲ್ಲದಿದ್ದರೆ {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ X86_64_ಬಹುಲಕ {
  x86_64_ಬಹುಲಕ_none,
  x86_64_ಬಹುಲಕ_ಸ್ಮರಣೆ,
  x86_64_ಬಹುಲಕ_integer,
  x86_64_ಬಹುಲಕ_sse,
  x86_64_ಬಹುಲಕ_x87
} X86_64_ಬಹುಲಕ;

ಸ್ಥಿರ X86_64_ಬಹುಲಕ classify_x86_64_ವಿಲೀನ(X86_64_ಬಹುಲಕ a, X86_64_ಬಹುಲಕ b)
{
    ಆದರೆ (a == b)
        ಹಿಂತಿರುಗಿ a;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a == x86_64_ಬಹುಲಕ_none)
        ಹಿಂತಿರುಗಿ b;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (b == x86_64_ಬಹುಲಕ_none)
        ಹಿಂತಿರುಗಿ a;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((a == x86_64_ಬಹುಲಕ_ಸ್ಮರಣೆ) || (b == x86_64_ಬಹುಲಕ_ಸ್ಮರಣೆ))
        ಹಿಂತಿರುಗಿ x86_64_ಬಹುಲಕ_ಸ್ಮರಣೆ;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((a == x86_64_ಬಹುಲಕ_integer) || (b == x86_64_ಬಹುಲಕ_integer))
        ಹಿಂತಿರುಗಿ x86_64_ಬಹುಲಕ_integer;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((a == x86_64_ಬಹುಲಕ_x87) || (b == x86_64_ಬಹುಲಕ_x87))
        ಹಿಂತಿರುಗಿ x86_64_ಬಹುಲಕ_ಸ್ಮರಣೆ;
    ಇಲ್ಲದಿದ್ದರೆ
        ಹಿಂತಿರುಗಿ x86_64_ಬಹುಲಕ_sse;
}

ಸ್ಥಿರ X86_64_ಬಹುಲಕ classify_x86_64_inner(CType *ty)
{
    X86_64_ಬಹುಲಕ ಬಹುಲಕ;
    Sym *f;
    
    ಆಯ್ಕೆ (ty->t & VT_BTYPE) {
    ಸ್ಥಿತಿ VT_VOID: ಹಿಂತಿರುಗಿ x86_64_ಬಹುಲಕ_none;
    
    ಸ್ಥಿತಿ VT_INT:
    ಸ್ಥಿತಿ VT_BYTE:
    ಸ್ಥಿತಿ VT_SHORT:
    ಸ್ಥಿತಿ VT_LLONG:
    ಸ್ಥಿತಿ VT_BOOL:
    ಸ್ಥಿತಿ VT_PTR:
    ಸ್ಥಿತಿ VT_FUNC:
        ಹಿಂತಿರುಗಿ x86_64_ಬಹುಲಕ_integer;
    
    ಸ್ಥಿತಿ VT_FLOAT:
    ಸ್ಥಿತಿ VT_DOUBLE: ಹಿಂತಿರುಗಿ x86_64_ಬಹುಲಕ_sse;
    
    ಸ್ಥಿತಿ VT_LDOUBLE: ಹಿಂತಿರುಗಿ x86_64_ಬಹುಲಕ_x87;
      
    ಸ್ಥಿತಿ VT_STRUCT:
        f = ty->ref;

        ಬಹುಲಕ = x86_64_ಬಹುಲಕ_none;
        ಗಾಗಿ (f = f->ಮುಂದಿನ; f; f = f->ಮುಂದಿನ)
            ಬಹುಲಕ = classify_x86_64_ವಿಲೀನ(ಬಹುಲಕ, classify_x86_64_inner(&f->type));
        
        ಹಿಂತಿರುಗಿ ಬಹುಲಕ;
    }
    ಪ್ರತಿಜ್ಞಾ(0);
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ X86_64_ಬಹುಲಕ classify_x86_64_arg(CType *ty, CType *ret, ಪೂರ್ಣಾಂಕ *psize, ಪೂರ್ಣಾಂಕ *palign, ಪೂರ್ಣಾಂಕ *reg_ಎಣಿಕೆ)
{
    X86_64_ಬಹುಲಕ ಬಹುಲಕ;
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, ret_t = 0;
    
    ಆದರೆ (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_ಎಣಿಕೆ = 1;
        ret_t = ty->t;
        ಬಹುಲಕ = x86_64_ಬಹುಲಕ_integer;
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಗಾತ್ರ_2 = type_ಗಾತ್ರ(ty, &align);
        *psize = (ಗಾತ್ರ_2 + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_ಎಣಿಕೆ = 0; /* avoid compiler warning */

        ಆದರೆ (ಗಾತ್ರ_2 > 16) {
            ಬಹುಲಕ = x86_64_ಬಹುಲಕ_ಸ್ಮರಣೆ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಬಹುಲಕ = classify_x86_64_inner(ty);
            ಆಯ್ಕೆ (ಬಹುಲಕ) {
            ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_integer:
                ಆದರೆ (ಗಾತ್ರ_2 > 8) {
                    *reg_ಎಣಿಕೆ = 2;
                    ret_t = VT_QLONG;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    *reg_ಎಣಿಕೆ = 1;
                    ಆದರೆ (ಗಾತ್ರ_2 > 4)
                        ret_t = VT_LLONG;
                    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2 > 2)
                        ret_t = VT_INT;
                    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2 > 1)
                        ret_t = VT_SHORT;
                    ಇಲ್ಲದಿದ್ದರೆ
                        ret_t = VT_BYTE;
                    ಆದರೆ ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                ನಿಲ್ಲಿಸು;
                
            ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_x87:
                *reg_ಎಣಿಕೆ = 1;
                ret_t = VT_LDOUBLE;
                ನಿಲ್ಲಿಸು;

            ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_sse:
                ಆದರೆ (ಗಾತ್ರ_2 > 8) {
                    *reg_ಎಣಿಕೆ = 2;
                    ret_t = VT_QFLOAT;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    *reg_ಎಣಿಕೆ = 1;
                    ret_t = (ಗಾತ್ರ_2 > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                ನಿಲ್ಲಿಸು;
            ಪೂರ್ವನಿಯೋಜಿತ: ನಿಲ್ಲಿಸು; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    ಆದರೆ (ret) {
        ret->ref = ಖಾಲಿ;
        ret->t = ret_t;
    }
    
    ಹಿಂತಿರುಗಿ ಬಹುಲಕ;
}

ST_FUNC ಪೂರ್ಣಾಂಕ classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    ಎಣಿಕೆ __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, reg_ಎಣಿಕೆ;
    X86_64_ಬಹುಲಕ ಬಹುಲಕ = classify_x86_64_arg(ty, ಖಾಲಿ, &ಗಾತ್ರ_2, &align, &reg_ಎಣಿಕೆ);
    ಆಯ್ಕೆ (ಬಹುಲಕ) {
    ಪೂರ್ವನಿಯೋಜಿತ: ಹಿಂತಿರುಗಿ __va_stack;
    ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_integer: ಹಿಂತಿರುಗಿ __va_gen_reg;
    ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_sse: ಹಿಂತಿರುಗಿ __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ಪೂರ್ಣಾಂಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಂಕ variadic, CType *ret, ಪೂರ್ಣಾಂಕ *ret_align, ಪೂರ್ಣಾಂಕ *regsize)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, reg_ಎಣಿಕೆ;
    ಆದರೆ (classify_x86_64_arg(vt, ret, &ಗಾತ್ರ_2, &align, &reg_ಎಣಿಕೆ) == x86_64_ಬಹುಲಕ_ಸ್ಮರಣೆ)
        ಹಿಂತಿರುಗಿ 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_ಎಣಿಕೆ; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    ಹಿಂತಿರುಗಿ 1;
}

#ವ್ಯಾಖ್ಯಾನಿಸು REGN 6
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arg_prepare_reg(ಪೂರ್ಣಾಂಕ idx) {
  ಆದರೆ (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      ಹಿಂತಿರುಗಿ idx + 8;
  ಇಲ್ಲದಿದ್ದರೆ
      ಹಿಂತಿರುಗಿ idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು)
{
    X86_64_ಬಹುಲಕ ಬಹುಲಕ;
    CType type;
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, r, ವಾದಗಳು_ಗಾತ್ರ, ರಾಶಿ_adjust, i, reg_ಎಣಿಕೆ, k;
    ಪೂರ್ಣಾಂಕ nb_reg_ವಾದಗಳು = 0;
    ಪೂರ್ಣಾಂಕ nb_sse_ವಾದಗಳು = 0;
    ಪೂರ್ಣಾಂಕ sse_reg, gen_reg;
    ಅಕ್ಷರ *onstack = tcc_malloc((nb_ವಾದಗಳು + 1) * ಗಾತ್ರ (ಅಕ್ಷರ));

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gbound_ವಾದಗಳು(nb_ವಾದಗಳು);
#ಆದರೆ_ಅಂತ್ಯ

    save_regs(nb_ವಾದಗಳು);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    ರಾಶಿ_adjust = 0;
    ಗಾಗಿ(i = nb_ವಾದಗಳು - 1; i >= 0; i--) {
        ಬಹುಲಕ = classify_x86_64_arg(&vtop[-i].type, ಖಾಲಿ, &ಗಾತ್ರ_2, &align, &reg_ಎಣಿಕೆ);
        ಆದರೆ (ಗಾತ್ರ_2 == 0) ಮುಂದುವರಿ;
        ಆದರೆ (ಬಹುಲಕ == x86_64_ಬಹುಲಕ_sse && nb_sse_ವಾದಗಳು + reg_ಎಣಿಕೆ <= 8) {
            nb_sse_ವಾದಗಳು += reg_ಎಣಿಕೆ;
	    onstack[i] = 0;
	} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಬಹುಲಕ == x86_64_ಬಹುಲಕ_integer && nb_reg_ವಾದಗಳು + reg_ಎಣಿಕೆ <= REGN) {
            nb_reg_ವಾದಗಳು += reg_ಎಣಿಕೆ;
	    onstack[i] = 0;
	} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಬಹುಲಕ == x86_64_ಬಹುಲಕ_none) {
	    onstack[i] = 0;
	} ಇಲ್ಲದಿದ್ದರೆ {
	    ಆದರೆ (align == 16 && (ರಾಶಿ_adjust &= 15)) {
		onstack[i] = 2;
		ರಾಶಿ_adjust = 0;
	    } ಇಲ್ಲದಿದ್ದರೆ
	      onstack[i] = 1;
	    ರಾಶಿ_adjust += ಗಾತ್ರ_2;
	}
    }

    ಆದರೆ (nb_sse_ವಾದಗಳು && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_ವಾದಗಳು;
    sse_reg = nb_sse_ವಾದಗಳು;
    ವಾದಗಳು_ಗಾತ್ರ = 0;
    ರಾಶಿ_adjust &= 15;
    ಗಾಗಿ (i = k = 0; i < nb_ವಾದಗಳು;) {
	ಬಹುಲಕ = classify_x86_64_arg(&vtop[-i].type, ಖಾಲಿ, &ಗಾತ್ರ_2, &align, &reg_ಎಣಿಕೆ);
	ಆದರೆ (ಗಾತ್ರ_2) {
            ಆದರೆ (!onstack[i + k]) {
	        ++i;
	        ಮುಂದುವರಿ;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            ಆದರೆ (ರಾಶಿ_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                ವಾದಗಳು_ಗಾತ್ರ += 8;
	        ರಾಶಿ_adjust = 0;
            }
	    ಆದರೆ (onstack[i + k] == 2)
	        ರಾಶಿ_adjust = 1;
        }

	vrotb(i+1);

	ಆಯ್ಕೆ (vtop->type.t & VT_BTYPE) {
	    ಸ್ಥಿತಿ VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, ಗಾತ್ರ_2); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_ಮೌಲ್ಯ(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_ಮೌಲ್ಯ(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		ನಿಲ್ಲಿಸು;

	    ಸ್ಥಿತಿ VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, ಗಾತ್ರ_2); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		ನಿಲ್ಲಿಸು;

	    ಸ್ಥಿತಿ VT_FLOAT:
	    ಸ್ಥಿತಿ VT_DOUBLE:
		ಪ್ರತಿಜ್ಞಾ(ಬಹುಲಕ == x86_64_ಬಹುಲಕ_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_ಮೌಲ್ಯ(r)*8);
		o(0x24);
		ನಿಲ್ಲಿಸು;

	    ಪೂರ್ವನಿಯೋಜಿತ:
		ಪ್ರತಿಜ್ಞಾ(ಬಹುಲಕ == x86_64_ಬಹುಲಕ_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_ಮೌಲ್ಯ(r)); /* push r */
		ನಿಲ್ಲಿಸು;
	}
	ವಾದಗಳು_ಗಾತ್ರ += ಗಾತ್ರ_2;

	vpop();
	--nb_ವಾದಗಳು;
	k++;
    }

    tcc_free(onstack);

    /* then, we prepare register passing arguments.
       Note that we cannot set RDX and RCX in this loop because gv()
       may break these temporary registers. Let's use R10 and R11
       instead of them */
    ಪ್ರತಿಜ್ಞಾ(gen_reg <= REGN);
    ಪ್ರತಿಜ್ಞಾ(sse_reg <= 8);
    ಗಾಗಿ(i = 0; i < nb_ವಾದಗಳು; i++) {
        ಬಹುಲಕ = classify_x86_64_arg(&vtop->type, &type, &ಗಾತ್ರ_2, &align, &reg_ಎಣಿಕೆ);
        ಆದರೆ (ಗಾತ್ರ_2 == 0) ಮುಂದುವರಿ;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        ಆದರೆ (ಬಹುಲಕ == x86_64_ಬಹುಲಕ_sse) {
            ಆದರೆ (reg_ಎಣಿಕೆ == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                ಆದರೆ (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಪ್ರತಿಜ್ಞಾ(reg_ಎಣಿಕೆ == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಬಹುಲಕ == x86_64_ಬಹುಲಕ_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            ಪೂರ್ಣಾಂಕ d;
            gen_reg -= reg_ಎಣಿಕೆ;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_ಮೌಲ್ಯ(r) * 8 + REG_ಮೌಲ್ಯ(d));
            ಆದರೆ (reg_ಎಣಿಕೆ == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r2) * 8 + REG_ಮೌಲ್ಯ(d));
            }
        }
        vtop--;
    }
    ಪ್ರತಿಜ್ಞಾ(gen_reg == 0);
    ಪ್ರತಿಜ್ಞಾ(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    ಆದರೆ (nb_reg_ವಾದಗಳು > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        ಆದರೆ (nb_reg_ವಾದಗಳು > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    ಆದರೆ (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_ವಾದಗಳು < 8 ? nb_sse_ವಾದಗಳು : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    ಆದರೆ (ವಾದಗಳು_ಗಾತ್ರ)
        gadd_sp(ವಾದಗಳು_ಗಾತ್ರ);
    vtop--;
}

#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_PROLOG_ಗಾತ್ರ 11

ಸ್ಥಿರ ಶೂನ್ಯ ತಳ್ಳು_arg_reg(ಪೂರ್ಣಾಂಕ i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, ಖಾಲಿ, loc);
}

/* generate function prolog of type 't' */
ಶೂನ್ಯ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_ಬಹುಲಕ ಬಹುಲಕ, ret_ಬಹುಲಕ;
    ಪೂರ್ಣಾಂಕ i, addr, align, ಗಾತ್ರ_2, reg_ಎಣಿಕೆ;
    ಪೂರ್ಣಾಂಕ param_addr = 0, reg_param_ಸೂಚ್ಯಂಕ, sse_param_ಸೂಚ್ಯಂಕ;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_ಗಾತ್ರ * 2;
    loc = 0;
    ind += FUNC_PROLOG_ಗಾತ್ರ;
    func_sub_sp_ಸ್ಥಾನಾಂತರ = ind;
    func_ret_sub = 0;
    ret_ಬಹುಲಕ = classify_x86_64_arg(&func_vt, ಖಾಲಿ, &ಗಾತ್ರ_2, &align, &reg_ಎಣಿಕೆ);

    ಆದರೆ (func_var) {
        ಪೂರ್ಣಾಂಕ ನೋಡಿದ_reg_ಅಂಕೆ, ನೋಡಿದ_sse_ಅಂಕೆ, ನೋಡಿದ_ರಾಶಿ_ಗಾತ್ರ;
        ನೋಡಿದ_reg_ಅಂಕೆ = ret_ಬಹುಲಕ == x86_64_ಬಹುಲಕ_ಸ್ಮರಣೆ;
        ನೋಡಿದ_sse_ಅಂಕೆ = 0;
        /* frame pointer and return address */
        ನೋಡಿದ_ರಾಶಿ_ಗಾತ್ರ = PTR_ಗಾತ್ರ * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        ಆಗ ((sym = sym->ಮುಂದಿನ) != ಖಾಲಿ) {
            type = &sym->type;
            ಬಹುಲಕ = classify_x86_64_arg(type, ಖಾಲಿ, &ಗಾತ್ರ_2, &align, &reg_ಎಣಿಕೆ);
            ಆಯ್ಕೆ (ಬಹುಲಕ) {
            ಪೂರ್ವನಿಯೋಜಿತ:
            ರಾಶಿ_arg:
                ನೋಡಿದ_ರಾಶಿ_ಗಾತ್ರ = ((ನೋಡಿದ_ರಾಶಿ_ಗಾತ್ರ + align - 1) & -align) + ಗಾತ್ರ_2;
                ನಿಲ್ಲಿಸು;
                
            ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_integer:
                ಆದರೆ (ನೋಡಿದ_reg_ಅಂಕೆ + reg_ಎಣಿಕೆ > REGN)
		    ಹೋಗು ರಾಶಿ_arg;
		ನೋಡಿದ_reg_ಅಂಕೆ += reg_ಎಣಿಕೆ;
                ನಿಲ್ಲಿಸು;
                
            ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_sse:
                ಆದರೆ (ನೋಡಿದ_sse_ಅಂಕೆ + reg_ಎಣಿಕೆ > 8)
		    ಹೋಗು ರಾಶಿ_arg;
		ನೋಡಿದ_sse_ಅಂಕೆ += reg_ಎಣಿಕೆ;
                ನಿಲ್ಲಿಸು;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(ನೋಡಿದ_reg_ಅಂಕೆ * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(ನೋಡಿದ_sse_ಅಂಕೆ * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(ನೋಡಿದ_ರಾಶಿ_ಗಾತ್ರ);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        ಗಾಗಿ (i = 0; i < 8; i++) {
            loc -= 16;
	    ಆದರೆ (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, ಖಾಲಿ, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        ಗಾಗಿ (i = 0; i < REGN; i++) {
            ತಳ್ಳು_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_ಸೂಚ್ಯಂಕ = 0;
    sse_param_ಸೂಚ್ಯಂಕ = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    ಆದರೆ (ret_ಬಹುಲಕ == x86_64_ಬಹುಲಕ_ಸ್ಮರಣೆ) {
        ತಳ್ಳು_arg_reg(reg_param_ಸೂಚ್ಯಂಕ);
        func_vc = loc;
        reg_param_ಸೂಚ್ಯಂಕ++;
    }
    /* define parameters */
    ಆಗ ((sym = sym->ಮುಂದಿನ) != ಖಾಲಿ) {
        type = &sym->type;
        ಬಹುಲಕ = classify_x86_64_arg(type, ಖಾಲಿ, &ಗಾತ್ರ_2, &align, &reg_ಎಣಿಕೆ);
        ಆಯ್ಕೆ (ಬಹುಲಕ) {
        ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_sse:
	    ಆದರೆ (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            ಆದರೆ (sse_param_ಸೂಚ್ಯಂಕ + reg_ಎಣಿಕೆ <= 8) {
                /* save arguments passed by register */
                loc -= reg_ಎಣಿಕೆ * 8;
                param_addr = loc;
                ಗಾಗಿ (i = 0; i < reg_ಎಣಿಕೆ; ++i) {
                    gen_modrm32(0xd60f66, sse_param_ಸೂಚ್ಯಂಕ, VT_LOCAL, ಖಾಲಿ, param_addr + i*8);
                    ++sse_param_ಸೂಚ್ಯಂಕ;
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += ಗಾತ್ರ_2;
            }
            ನಿಲ್ಲಿಸು;
            
        ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_ಸ್ಮರಣೆ:
        ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += ಗಾತ್ರ_2;
            ನಿಲ್ಲಿಸು;
            
        ಸ್ಥಿತಿ x86_64_ಬಹುಲಕ_integer: {
            ಆದರೆ (reg_param_ಸೂಚ್ಯಂಕ + reg_ಎಣಿಕೆ <= REGN) {
                /* save arguments passed by register */
                loc -= reg_ಎಣಿಕೆ * 8;
                param_addr = loc;
                ಗಾಗಿ (i = 0; i < reg_ಎಣಿಕೆ; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_ಸೂಚ್ಯಂಕ], VT_LOCAL, ಖಾಲಿ, param_addr + i*8);
                    ++reg_param_ಸೂಚ್ಯಂಕ;
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += ಗಾತ್ರ_2;
            }
            ನಿಲ್ಲಿಸು;
        }
	ಪೂರ್ವನಿಯೋಜಿತ: ನಿಲ್ಲಿಸು; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_ಗಣ_param(sym, param_addr, 0);
    }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#ಆದರೆ_ಅಂತ್ಯ
}

/* generate function epilog */
ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ v, saved_ind;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#ಆದರೆ_ಅಂತ್ಯ
    o(0xc9); /* leave */
    ಆದರೆ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ಇಲ್ಲದಿದ್ದರೆ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    /* align local size to word & save local variables */
    v = (-loc + 15) & -16;
    saved_ind = ind;
    ind = func_sub_sp_ಸ್ಥಾನಾಂತರ - FUNC_PROLOG_ಗಾತ್ರ;
    o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
    o(0xec8148);  /* sub rsp, stacksize */
    gen_le32(v);
    ind = saved_ind;
}

#ಆದರೆ_ಅಂತ್ಯ /* not PE */

ST_FUNC ಶೂನ್ಯ gen_fill_nops(ಪೂರ್ಣಾಂಕ ಬೈಟುಗಳು)
{
    ಆಗ (ಬೈಟುಗಳು--)
      g(0x90);
}

/* generate a jump to a label */
ಪೂರ್ಣಾಂಕ gjmp(ಪೂರ್ಣಾಂಕ t)
{
    ಹಿಂತಿರುಗಿ gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಂಕ a)
{
    ಪೂರ್ಣಾಂಕ r;
    r = a - ind - 2;
    ಆದರೆ (r == (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)r) {
        g(0xeb);
        g(r);
    } ಇಲ್ಲದಿದ್ದರೆ {
        oad(0xe9, a - ind - 5);
    }
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

ST_FUNC ಪೂರ್ಣಾಂಕ gjmp_cond(ಪೂರ್ಣಾಂಕ op, ಪೂರ್ಣಾಂಕ t)
{
        ಆದರೆ (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            ಪೂರ್ಣಾಂಕ v = vtop->cmp_r;
            op &= ~0x100;
            ಆದರೆ (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    ಇಲ್ಲದಿದ್ದರೆ
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        ಹಿಂತಿರುಗಿ t;
}

/* generate an integer binary operation */
ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಂಕ op)
{
    ಪೂರ್ಣಾಂಕ r, fr, opc, c;
    ಪೂರ್ಣಾಂಕ ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    ಆಯ್ಕೆ(op) {
    ಸ್ಥಿತಿ '+':
    ಸ್ಥಿತಿ TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        ಆದರೆ (cc && (!ll || (ಪೂರ್ಣಾಂಕ)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            ಆದರೆ (c == (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_ಮೌಲ್ಯ(r));
                g(c);
            } ಇಲ್ಲದಿದ್ದರೆ {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_ಮೌಲ್ಯ(r), c);
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_ಮೌಲ್ಯ(r) + REG_ಮೌಲ್ಯ(fr) * 8);
        }
        vtop--;
        ಆದರೆ (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '-':
    ಸ್ಥಿತಿ TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ TOK_ADDC2: /* add with carry use */
        opc = 2;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ TOK_SUBC2: /* sub with carry use */
        opc = 3;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ '&':
        opc = 4;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ '^':
        opc = 6;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ '|':
        opc = 1;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_ಮೌಲ್ಯ(fr) + REG_ಮೌಲ್ಯ(r) * 8);
        vtop--;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SHL:
        opc = 4;
        ಹೋಗು gen_ಸರಿಸು;
    ಸ್ಥಿತಿ TOK_SHR:
        opc = 5;
        ಹೋಗು gen_ಸರಿಸು;
    ಸ್ಥಿತಿ TOK_SAR:
        opc = 7;
    gen_ಸರಿಸು:
        opc = 0xc0 | (opc << 3);
        ಆದರೆ (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_ಮೌಲ್ಯ(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_ಮೌಲ್ಯ(r));
        }
        vtop--;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_UDIV:
    ಸ್ಥಿತಿ TOK_UMOD:
        uu = 1;
        ಹೋಗು divmod;
    ಸ್ಥಿತಿ '/':
    ಸ್ಥಿತಿ '%':
    ಸ್ಥಿತಿ TOK_PDIV:
        uu = 0;
    divmod:
        /* first operand must be in eax */
        /* XXX: need better constraint for second operand */
        gv2(RC_RAX, RC_RCX);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        save_reg(TREG_RDX);
        orex(ll, 0, 0, uu ? 0xd231 : 0x99); /* xor %edx,%edx : cqto */
        orex(ll, fr, 0, 0xf7); /* div fr, %eax */
        o((uu ? 0xf0 : 0xf8) + REG_ಮೌಲ್ಯ(fr));
        ಆದರೆ (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        ಇಲ್ಲದಿದ್ದರೆ
            r = TREG_RAX;
        vtop->r = r;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        opc = 7;
        ಹೋಗು gen_op8;
    }
}

ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಂಕ op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಂಕ op)
{
    ಪೂರ್ಣಾಂಕ a, ft, fc, swapped, r, opc;
    ಪೂರ್ಣಾಂಕ bt = vtop->type.t & VT_BTYPE;
    ಪೂರ್ಣಾಂಕ float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    ಆದರೆ (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        ಆದರೆ (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } ಇಲ್ಲದಿದ್ದರೆ {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, ಖಾಲಿ, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        ಹಿಂತಿರುಗಿ;
    }

    /* convert constants to memory references */
    ಆದರೆ ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    ಆದರೆ ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    ಆದರೆ ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    ಆದರೆ (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        ಆದರೆ (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            ತುಂಬು(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            ಆದರೆ (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            ಆದರೆ (swapped)
                o(0xc9d9); /* fxch %st(1) */
            ಆದರೆ (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            ಇಲ್ಲದಿದ್ದರೆ
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            ಆದರೆ (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } ಇಲ್ಲದಿದ್ದರೆ {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* no memory reference possible for long double operations */
            ತುಂಬು(TREG_ST0, vtop);
            swapped = !swapped;

            ಆಯ್ಕೆ(op) {
            ಪೂರ್ವನಿಯೋಜಿತ:
            ಸ್ಥಿತಿ '+':
                a = 0;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ '-':
                a = 4;
                ಆದರೆ (swapped)
                    a++;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ '*':
                a = 1;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ '/':
                a = 6;
                ಆದರೆ (swapped)
                    a++;
                ನಿಲ್ಲಿಸು;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            ಆದರೆ ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = ಖಾಲಿ;
                ತುಂಬು(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            ಆದರೆ (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                ಆದರೆ (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } ಇಲ್ಲದಿದ್ದರೆ {
                    op = 0x97; /* seta */
                }
            }

            ಆದರೆ (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            ಪ್ರತಿಜ್ಞಾ(!(vtop[-1].r & VT_LVAL));
            
            ಆದರೆ (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            ಇಲ್ಲದಿದ್ದರೆ
                opc = 0x2f0f; /* comisd */
            ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಪ್ರತಿಜ್ಞಾ((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            ಆಯ್ಕೆ(op) {
            ಪೂರ್ವನಿಯೋಜಿತ:
            ಸ್ಥಿತಿ '+':
                a = 0;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ '-':
                a = 4;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ '*':
                a = 1;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ '/':
                a = 6;
                ನಿಲ್ಲಿಸು;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            ಪ್ರತಿಜ್ಞಾ((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            ಆದರೆ ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = ಖಾಲಿ;
                ತುಂಬು(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            ಪ್ರತಿಜ್ಞಾ(!(vtop[-1].r & VT_LVAL));
            ಆದರೆ (swapped) {
                ಪ್ರತಿಜ್ಞಾ(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            ಆದರೆ ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } ಇಲ್ಲದಿದ್ದರೆ {
                o(0xf3);
            }
            o(0x0f);
            opc = 0x58 + a;
            
            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
        }
    }
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಂಕ t)
{
    ಆದರೆ ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಪೂರ್ಣಾಂಕ r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        ಆದರೆ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_ಮೌಲ್ಯ(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    ಆದರೆ (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        ಆದರೆ (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r)*9);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_ಮೌಲ್ಯ(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        ಆದರೆ (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r)*9);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_ಮೌಲ್ಯ(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಪೂರ್ಣಾಂಕ r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        ಆದರೆ (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_ಮೌಲ್ಯ(r)*8);
            o(0xf024);
            vtop->r = r;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_ಮೌಲ್ಯ(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ ft, bt, ಗಾತ್ರ_2, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    ಆದರೆ (bt == VT_LDOUBLE) {
	ಆದರೆ (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    ಹಿಂತಿರುಗಿ;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    ಆದರೆ (t != VT_INT)
        ಗಾತ್ರ_2 = 8;
    ಇಲ್ಲದಿದ್ದರೆ
        ಗಾತ್ರ_2 = 4;

    r = get_reg(RC_INT);
    ಆದರೆ (bt == VT_FLOAT) {
        o(0xf3);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_DOUBLE) {
        o(0xf2);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಪ್ರತಿಜ್ಞಾ(0);
    }
    orex(ಗಾತ್ರ_2 == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r) + REG_ಮೌಲ್ಯ(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC ಶೂನ್ಯ gen_cvt_sxtw(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_ಮೌಲ್ಯ(r) << 3) + REG_ಮೌಲ್ಯ(r));
}

/* char/short to int conversion */
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_ಮೌಲ್ಯ(r) << 3 | REG_ಮೌಲ್ಯ(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_ಪಠ್ಯ_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC ಶೂನ್ಯ ggoto(ಶೂನ್ಯ)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC ಶೂನ್ಯ gen_vla_sp_save(ಪೂರ್ಣಾಂಕ addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, ಖಾಲಿ, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_sp_restore(ಪೂರ್ಣಾಂಕ addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, ಖಾಲಿ, addr);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_ಫಲಿತಾಂಶ(ಪೂರ್ಣಾಂಕ addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, ಖಾಲಿ, addr);
}
#ಆದರೆ_ಅಂತ್ಯ

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_alloc(CType *type, ಪೂರ್ಣಾಂಕ align) {
    ಪೂರ್ಣಾಂಕ use_call = 0;

#ಆದರೆ defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        ಪೂರ್ಣಾಂಕ r;
        r = gv(RC_INT); /* allocation size */
        /* sub r,%rsp */
        o(0x2b48);
        o(0xe0 | REG_ಮೌಲ್ಯ(r));
        /* We align to 16 bytes rather than align */
        /* and ~15, %rsp */
        o(0xf0e48348);
        vpop();
    }
}

/*
 * Assmuing the top part of the stack looks like below,
 *  src dest src
 */
ST_FUNC ಶೂನ್ಯ gen_struct_copy(ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
    ಪೂರ್ಣಾಂಕ n = ಗಾತ್ರ_2 / PTR_ಗಾತ್ರ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    o(0x5756); /* push rsi, rdi */
#ಆದರೆ_ಅಂತ್ಯ
    gv2(RC_RDI, RC_RSI);
    ಆದರೆ (n <= 4) {
        ಆಗ (n)
            o(0xa548), --n;
    } ಇಲ್ಲದಿದ್ದರೆ {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    ಆದರೆ (ಗಾತ್ರ_2 & 0x04)
        o(0xa5);
    ಆದರೆ (ಗಾತ್ರ_2 & 0x02)
        o(0xa566);
    ಆದರೆ (ಗಾತ್ರ_2 & 0x01)
        o(0xa4);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    o(0x5e5f); /* pop rdi, rsi */
#ಆದರೆ_ಅಂತ್ಯ
    vpop();
    vpop();
}

/* end of x86-64 code generator */
/*************************************************************/
#ಆದರೆ_ಅಂತ್ಯ /* ! TARGET_DEFS_ONLY */
/******************************************************/
