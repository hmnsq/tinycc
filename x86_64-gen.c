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

#ifdef TARGET_DEFS_ONLY

/* number of available registers */
#define NB_REGS         25
#define NB_ASM_REGS     16
#define CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#define RC_INT     0x0001 /* generic integer register */
#define RC_FLOAT   0x0002 /* generic float register */
#define RC_RAX     0x0004
#define RC_RDX     0x0008
#define RC_RCX     0x0010
#define RC_RSI     0x0020
#define RC_RDI     0x0040
#define RC_ST0     0x0080 /* only for long double */
#define RC_R8      0x0100
#define RC_R9      0x0200
#define RC_R10     0x0400
#define RC_R11     0x0800
#define RC_XMM0    0x1000
#define RC_XMM1    0x2000
#define RC_XMM2    0x4000
#define RC_XMM3    0x8000
#define RC_XMM4    0x10000
#define RC_XMM5    0x20000
#define RC_XMM6    0x40000
#define RC_XMM7    0x80000
#define RC_IRET    RC_RAX /* function return: integer register */
#define RC_IRE2    RC_RDX /* function return: second integer register */
#define RC_FRET    RC_XMM0 /* function return: float register */
#define RC_FRE2    RC_XMM1 /* function return: second float register */

/* pretty names for the registers */
ಗಣನಾ {
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

#define REX_BASE(reg) (((reg) >> 3) & 1)
#define REG_ಮೌಲ್ಯ(reg) ((reg) & 7)

/* return registers for function */
#define REG_IRET TREG_RAX /* single word int return register */
#define REG_IRE2 TREG_RDX /* second word return register (for long long) */
#define REG_FRET TREG_XMM0 /* float return register */
#define REG_FRE2 TREG_XMM1 /* second float return register */

/* defined if function parameters must be evaluated in reverse order */
#define INVERT_FUNC_PARAMS

/* pointer size, in bytes */
#define PTR_SIZE 8

/* long double size and alignment, in bytes */
#define LDOUBLE_SIZE  16
#define LDOUBLE_ALIGN 16
/* maximum alignment (for aligned attribute support) */
#define MAX_ALIGN     16

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#define PROMOTE_RET

#define TCC_TARGET_NATIVE_STRUCT_COPY
ST_FUNC ಶೂನ್ಯ gen_struct_copy(ಪೂರ್ಣಾಙ್ಕ size);

/******************************************************/
#ಅನ್ಯಥಾ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"
#ಅನ್ತರ್ಭಾವ <assert.h>

ST_DATA ಧ್ರುವ ವರ್ಣ * ಧ್ರುವ target_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_DATA ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ reg_classes[NB_REGS] = {
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

ಸ್ಥಿರ unsigned long func_sub_sp_offset;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ func_ret_sub;

#ಯದಿ defined(CONFIG_TCC_BCHECK)
ಸ್ಥಿರ addr_t func_bound_offset;
ಸ್ಥಿರ unsigned long func_bound_ind;
ST_DATA ಪೂರ್ಣಾಙ್ಕ func_bound_add_epilog;
#endif

#ifdef TCC_TARGET_PE
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ func_scratch, func_alloca;
#endif

/* XXX: make it faster ? */
ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಙ್ಕ c)
{
    ಪೂರ್ಣಾಙ್ಕ ind1;
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    ind1 = ind + 1;
    ಯದಿ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC ಶೂನ್ಯ o(unsigned ಪೂರ್ಣಾಙ್ಕ c)
{
    ಯಾವತ್ (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಙ್ಕ v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಙ್ಕ c)
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

ಸ್ಥಿರ ಶೂನ್ಯ orex(ಪೂರ್ಣಾಙ್ಕ ll, ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ r2, ಪೂರ್ಣಾಙ್ಕ b)
{
    ಯದಿ ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    ಯದಿ ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    ಯದಿ (ll || REX_BASE(r) || REX_BASE(r2)) {
        ಯದಿ ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_BASE(r) | (REX_BASE(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC ಶೂನ್ಯ gsym_addr(ಪೂರ್ಣಾಙ್ಕ t, ಪೂರ್ಣಾಙ್ಕ a)
{
    ಯಾವತ್ (t) {
        unsigned ವರ್ಣ *ptr = cur_text_section->data + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is64_type(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪ್ರತ್ಯಾಗಮ ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ oad(ಪೂರ್ಣಾಙ್ಕ c, ಪೂರ್ಣಾಙ್ಕ s)
{
    ಪೂರ್ಣಾಙ್ಕ t;
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ s;
    o(c);
    t = ind;
    gen_le32(s);
    ಪ್ರತ್ಯಾಗಮ t;
}

/* generate jmp to a label */
#define gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC ಶೂನ್ಯ gen_addr32(ಪೂರ್ಣಾಙ್ಕ r, Sym *sym, ಪೂರ್ಣಾಙ್ಕ c)
{
    ಯದಿ (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ಶೂನ್ಯ gen_addrpc32(ಪೂರ್ಣಾಙ್ಕ r, Sym *sym, ಪೂರ್ಣಾಙ್ಕ c)
{
    ಯದಿ (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
ಸ್ಥಿರ ಶೂನ್ಯ gen_gotpcrel(ಪೂರ್ಣಾಙ್ಕ r, Sym *sym, ಪೂರ್ಣಾಙ್ಕ c)
{
#ifdef TCC_TARGET_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, ರಿಕ್ತ), c, r,
        cur_text_section->data[ind-3],
        cur_text_section->data[ind-2],
        cur_text_section->data[ind-1]
        );
#endif
    greloca(cur_text_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    ಯದಿ (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_ಮೌಲ್ಯ(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
ಸ್ಥಿರ ಶೂನ್ಯ gen_modrm_impl(ಪೂರ್ಣಾಙ್ಕ opcode, ಪೂರ್ಣಾಙ್ಕ ll, ಪೂರ್ಣಾಙ್ಕ op_reg_0, ಪೂರ್ಣಾಙ್ಕ r, Sym *sym, ಪೂರ್ಣಾಙ್ಕ c)
{
    ಪೂರ್ಣಾಙ್ಕ op_reg = REG_ಮೌಲ್ಯ(op_reg_0) << 3;

    ಯದಿ ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_SIZE); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#ಅನ್ಯಥಾ
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#endif
        ಪ್ರತ್ಯಾಗಮ;
    }

    orex(ll, r, op_reg_0, opcode);

    ಯದಿ ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	ಯದಿ (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} ಅನ್ಯಥಾ {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    ಯದಿ (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } ಅನ್ಯಥಾ {
		gen_addrpc32(r, sym, c);
	    }
	}
    } ಅನ್ಯಥಾ ಯದಿ ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        ಯದಿ (c == (signed ವರ್ಣ)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } ಅನ್ಯಥಾ {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } ಅನ್ಯಥಾ ಯದಿ ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_ಮೌಲ್ಯ(r));
        gen_le32(c);
    } ಅನ್ಯಥಾ ಯದಿ (r & VT_LVAL) {
        g(0x00 | op_reg | REG_ಮೌಲ್ಯ(r));
    } ಅನ್ಯಥಾ {
        g(0xc0 | op_reg | REG_ಮೌಲ್ಯ(r));
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_modrm64(ಪೂರ್ಣಾಙ್ಕ opcode, ಪೂರ್ಣಾಙ್ಕ op_reg, ಪೂರ್ಣಾಙ್ಕ r, Sym *sym, ಪೂರ್ಣಾಙ್ಕ c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_modrm32(ಪೂರ್ಣಾಙ್ಕ opcode, ಪೂರ್ಣಾಙ್ಕ op_reg, ಪೂರ್ಣಾಙ್ಕ r, Sym *sym, ಪೂರ್ಣಾಙ್ಕ c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
ಶೂನ್ಯ load(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಙ್ಕ v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    ಯದಿ (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#ifndef TCC_TARGET_PE
    /* we use indirect access via got */
    ಯದಿ ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        ಪೂರ್ಣಾಙ್ಕ tr = r | TREG_MEM;
        ಯದಿ (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#endif

    v = fr & VT_VALMASK;
    ಯದಿ (fr & VT_LVAL) {
        ಪೂರ್ಣಾಙ್ಕ b, ll;
        ಯದಿ (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = ರಿಕ್ತ;
            fr = r;
            ಯದಿ (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            load(fr, &v1);
            fr |= VT_LVAL;
        }
	ಯದಿ (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = ರಿಕ್ತ;
	    fr = r;
	    ಯದಿ (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    load(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	ಯದಿ ((ft & VT_BTYPE) == VT_STRUCT) {
	    ಪೂರ್ಣಾಙ್ಕ align;
	    ವಿಕಲ್ಪ (type_size(&sv->type, &align)) {
		ಪಕ್ಷ 1: ft = VT_BYTE; ಭಙ್ಗ;
		ಪಕ್ಷ 2: ft = VT_SHORT; ಭಙ್ಗ;
		ಪಕ್ಷ 4: ft = VT_INT; ಭಙ್ಗ;
		ಪಕ್ಷ 8: ft = VT_LLONG; ಭಙ್ಗ;
		ಸ್ವಭಾವ:
		    tcc_error("invalid aggregate type for register load");
		    ಭಙ್ಗ;
	    }
	}
        ಯದಿ ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_ಮೌಲ್ಯ(r); /* movd */
        } ಅನ್ಯಥಾ ಯದಿ ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_ಮೌಲ್ಯ(r);
        } ಅನ್ಯಥಾ ಯದಿ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } ಅನ್ಯಥಾ ಯದಿ ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } ಅನ್ಯಥಾ ಯದಿ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } ಅನ್ಯಥಾ ಯದಿ ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } ಅನ್ಯಥಾ ಯದಿ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } ಅನ್ಯಥಾ ಯದಿ ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            ಪ್ರತ್ಯಾಗಮ;
        } ಅನ್ಯಥಾ {
            ಪ್ರತಿಜ್ಞಾ(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } ಅನ್ಯಥಾ {
        ಯದಿ (v == VT_CONST) {
            ಯದಿ (fr & VT_SYM) {
#ifdef TCC_TARGET_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#ಅನ್ಯಥಾ
                ಯದಿ (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, ರಿಕ್ತ, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_ಮೌಲ್ಯ(r), 0);
                    greloca(cur_text_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } ಅನ್ಯಥಾ ಯದಿ (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_ಮೌಲ್ಯ(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } ಅನ್ಯಥಾ {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_ಮೌಲ್ಯ(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#endif
            } ಅನ್ಯಥಾ ಯದಿ (is64_type(ft)) {
                ಯದಿ (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_ಮೌಲ್ಯ(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } ಅನ್ಯಥಾ ಯದಿ (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_ಮೌಲ್ಯ(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } ಅನ್ಯಥಾ {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_ಮೌಲ್ಯ(r) * 9);
                }
            } ಅನ್ಯಥಾ {
                orex(0,r,0, 0xb8 + REG_ಮೌಲ್ಯ(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } ಅನ್ಯಥಾ ಯದಿ (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } ಅನ್ಯಥಾ ಯದಿ (v == VT_CMP) {
	    ಯದಿ (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_ಮೌಲ್ಯ(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_BASE(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_ಮೌಲ್ಯ(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_ಮೌಲ್ಯ(r) * 0x900); /* movzbl %al, %eax */
        } ಅನ್ಯಥಾ ಯದಿ (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_ಮೌಲ್ಯ(r), t); /* mov $1, r */
            o(0x05eb + (REX_BASE(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_ಮೌಲ್ಯ(r), t ^ 1); /* mov $0, r */
        } ಅನ್ಯಥಾ ಯದಿ (v != r) {
            ಯದಿ ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                ಯದಿ (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_ಮೌಲ್ಯ(r)*8); /* %xmmN */
                    o(0xf024);
                } ಅನ್ಯಥಾ {
                    ಪ್ರತಿಜ್ಞಾ((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    ಯದಿ ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } ಅನ್ಯಥಾ {
                        ಪ್ರತಿಜ್ಞಾ((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_ಮೌಲ್ಯ(v) + REG_ಮೌಲ್ಯ(r)*8);
                }
            } ಅನ್ಯಥಾ ಯದಿ (r == TREG_ST0) {
                ಪ್ರತಿಜ್ಞಾ((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_ಮೌಲ್ಯ(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } ಅನ್ಯಥಾ {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_ಮೌಲ್ಯ(r) + REG_ಮೌಲ್ಯ(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
ಶೂನ್ಯ store(ಪೂರ್ಣಾಙ್ಕ r, SValue *v)
{
    ಪೂರ್ಣಾಙ್ಕ fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    ಪೂರ್ಣಾಙ್ಕ opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    ಯದಿ (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#ifndef TCC_TARGET_PE
    /* we need to access the variable via got */
    ಯದಿ ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#endif

    /* XXX: incorrect if float reg to reg */
    ಯದಿ (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_ಮೌಲ್ಯ(r);
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_ಮೌಲ್ಯ(r);
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } ಅನ್ಯಥಾ {
        opc = 0x89;
        ಯದಿ (bt == VT_SHORT)
            opc = 0x8966;
        ಅನ್ಯಥಾ ಯದಿ (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
ಸ್ಥಿರ ಶೂನ್ಯ gcall_or_jmp(ಪೂರ್ಣಾಙ್ಕ is_jmp)
{
    ಪೂರ್ಣಾಙ್ಕ r;
    ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (ಪೂರ್ಣಾಙ್ಕ)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind + 1, R_X86_64_PLT32, (ಪೂರ್ಣಾಙ್ಕ)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } ಅನ್ಯಥಾ {
        /* otherwise, indirect call */
        r = TREG_R11;
        load(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_ಮೌಲ್ಯ(r) + (is_jmp << 4));
    }
}

#ಯದಿ defined(CONFIG_TCC_BCHECK)

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_call(ಪೂರ್ಣಾಙ್ಕ v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#ifdef TCC_TARGET_PE
# define TREG_FASTCALL_1 TREG_RCX
#ಅನ್ಯಥಾ
# define TREG_FASTCALL_1 TREG_RDI
#endif

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_prolog(ಶೂನ್ಯ)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->data_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
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
        greloca(cur_text_section, sym_data, ind + 3, R_X86_64_PC32, -4);
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
    greloca(cur_text_section, sym_data, ind + 3, R_X86_64_PC32, -4);
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /* lea xxx(%rip), %rcx/rdi */
    gen_le32 (0);
    gen_bounds_call(TOK___bound_local_delete);
    o(0x280f);     /* movaps 0x10(%rsp),%xmm0 */
    o(0x102444);
    o(0x240c280f); /* movaps (%rsp),%xmm1 */
    o(0x20c48348); /* add $32,%rsp */
    o(0x585a); /* restore returned value, if any */
}
#endif

#ifdef TCC_TARGET_PE

#define REGN 4
ಸ್ಥಿರ ಧ್ರುವ uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arg_prepare_reg(ಪೂರ್ಣಾಙ್ಕ idx) {
  ಯದಿ (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      ಪ್ರತ್ಯಾಗಮ idx + 10;
  ಅನ್ಯಥಾ
      ಪ್ರತ್ಯಾಗಮ idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

ಸ್ಥಿರ ಶೂನ್ಯ gen_offs_sp(ಪೂರ್ಣಾಙ್ಕ b, ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    ಯದಿ (d == (signed ವರ್ಣ)d) {
        o(0x2444 | (REG_ಮೌಲ್ಯ(r) << 3));
        g(d);
    } ಅನ್ಯಥಾ {
        o(0x2484 | (REG_ಮೌಲ್ಯ(r) << 3));
        gen_le32(d);
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ using_regs(ಪೂರ್ಣಾಙ್ಕ size)
{
    ಪ್ರತ್ಯಾಗಮ !(size > 8 || (size & (size - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಙ್ಕ variadic, CType *ret, ಪೂರ್ಣಾಙ್ಕ *ret_align, ಪೂರ್ಣಾಙ್ಕ *regsize)
{
    ಪೂರ್ಣಾಙ್ಕ size, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    size = type_size(vt, &align);
    ಯದಿ (!using_regs(size))
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (size == 8)
        ret->t = VT_LLONG;
    ಅನ್ಯಥಾ ಯದಿ (size == 4)
        ret->t = VT_INT;
    ಅನ್ಯಥಾ ಯದಿ (size == 2)
        ret->t = VT_SHORT;
    ಅನ್ಯಥಾ
        ret->t = VT_BYTE;
    ret->ref = ರಿಕ್ತ;
    ಪ್ರತ್ಯಾಗಮ 1;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_sse_float(ಪೂರ್ಣಾಙ್ಕ t) {
    ಪೂರ್ಣಾಙ್ಕ bt;
    bt = t & VT_BTYPE;
    ಪ್ರತ್ಯಾಗಮ bt == VT_DOUBLE || bt == VT_FLOAT;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ gfunc_arg_size(CType *type) {
    ಪೂರ್ಣಾಙ್ಕ align;
    ಯದಿ (type->t & (VT_ARRAY|VT_BITFIELD))
        ಪ್ರತ್ಯಾಗಮ 8;
    ಪ್ರತ್ಯಾಗಮ type_size(type, &align);
}

ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಙ್ಕ nb_args)
{
    ಪೂರ್ಣಾಙ್ಕ size, r, args_size, i, d, bt, struct_size;
    ಪೂರ್ಣಾಙ್ಕ arg;

#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    args_size = (nb_args < REGN ? REGN : nb_args) * PTR_SIZE;
    arg = nb_args;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_size = args_size;
    ಪ್ರತಿ(i = 0; i < nb_args; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        size = gfunc_arg_size(&sv->type);

        ಯದಿ (using_regs(size))
            ಅನುವರ್ತ; /* arguments smaller than 8 bytes passed in registers or on stack */

        ಯದಿ (bt == VT_STRUCT) {
            /* align to stack align size */
            size = (size + 15) & ~15;
            /* generate structure store */
            r = get_reg(RC_INT);
            gen_offs_sp(0x8d, r, struct_size);
            struct_size += size;

            /* generate memcpy call */
            vset(&sv->type, r | VT_LVAL, 0);
            vpushv(sv);
            vstore();
            --vtop;
        } ಅನ್ಯಥಾ ಯದಿ (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_size);
            struct_size += 16;
        }
    }

    ಯದಿ (func_scratch < struct_size)
        func_scratch = struct_size;

    arg = nb_args;
    struct_size = args_size;

    ಪ್ರತಿ(i = 0; i < nb_args; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        size = gfunc_arg_size(&vtop->type);
        ಯದಿ (!using_regs(size)) {
            /* align to stack align size */
            size = (size + 15) & ~15;
            ಯದಿ (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_size);
                gen_offs_sp(0x89, d, arg*8);
            } ಅನ್ಯಥಾ {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_size);
            }
            struct_size += size;
        } ಅನ್ಯಥಾ {
            ಯದಿ (is_sse_float(vtop->type.t)) {
		ಯದಿ (tcc_state->nosse)
		  tcc_error("SSE disabled");
                ಯದಿ (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } ಅನ್ಯಥಾ {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_ಮೌಲ್ಯ(d));
                }
            } ಅನ್ಯಥಾ {
                ಯದಿ (bt == VT_STRUCT) {
                    vtop->type.ref = ರಿಕ್ತ;
                    vtop->type.t = size > 4 ? VT_LLONG : size > 2 ? VT_INT
                        : size > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                ಯದಿ (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } ಅನ್ಯಥಾ {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_ಮೌಲ್ಯ(r) * 8 + REG_ಮೌಲ್ಯ(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    ಯದಿ (nb_args > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        ಯದಿ (nb_args > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    ಯದಿ ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#endif
    }
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

/* generate function prolog of type 't' */
ಶೂನ್ಯ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ಪೂರ್ಣಾಙ್ಕ addr, reg_param_index, bt, size;
    Sym *sym;
    CType *type;

    func_ret_sub = 0;
    func_scratch = 32;
    func_alloca = 0;
    loc = 0;

    addr = PTR_SIZE * 2;
    ind += FUNC_PROLOG_SIZE;
    func_sub_sp_offset = ind;
    reg_param_index = 0;

    sym = func_type->ref;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    size = gfunc_arg_size(&func_vt);
    ಯದಿ (!using_regs(size)) {
        gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ರಿಕ್ತ, addr);
        func_vc = addr;
        reg_param_index++;
        addr += 8;
    }

    /* define parameters */
    ಯಾವತ್ ((sym = sym->next) != ರಿಕ್ತ) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        size = gfunc_arg_size(type);
        ಯದಿ (!using_regs(size)) {
            ಯದಿ (reg_param_index < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ರಿಕ್ತ, addr);
            }
            gfunc_set_param(sym, addr, 1);
        } ಅನ್ಯಥಾ {
            ಯದಿ (reg_param_index < REGN) {
                /* save arguments passed by register */
                ಯದಿ ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    ಯದಿ (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_index, VT_LOCAL, ರಿಕ್ತ, addr);
                } ಅನ್ಯಥಾ {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ರಿಕ್ತ, addr);
                }
            }
            gfunc_set_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_index++;
    }

    ಯಾವತ್ (reg_param_index < REGN) {
        ಯದಿ (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ರಿಕ್ತ, addr);
            addr += 8;
        }
        reg_param_index++;
    }
#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ v, start;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    o(0xc9); /* leave */
    ಯದಿ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ಅನ್ಯಥಾ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    start = func_sub_sp_offset - FUNC_PROLOG_SIZE;
    cur_text_section->data_offset = ind;
    pe_add_unwind_data(start, ind, v);

    ind = start;
    ಯದಿ (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } ಅನ್ಯಥಾ {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_text_section->data_offset;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#ಅನ್ಯಥಾ

ಸ್ಥಿರ ಶೂನ್ಯ gadd_sp(ಪೂರ್ಣಾಙ್ಕ val)
{
    ಯದಿ (val == (signed ವರ್ಣ)val) {
        o(0xc48348);
        g(val);
    } ಅನ್ಯಥಾ {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಗಣನಾ X86_64_Mode {
  x86_64_mode_none,
  x86_64_mode_memory,
  x86_64_mode_integer,
  x86_64_mode_sse,
  x86_64_mode_x87
} X86_64_Mode;

ಸ್ಥಿರ X86_64_Mode classify_x86_64_merge(X86_64_Mode a, X86_64_Mode b)
{
    ಯದಿ (a == b)
        ಪ್ರತ್ಯಾಗಮ a;
    ಅನ್ಯಥಾ ಯದಿ (a == x86_64_mode_none)
        ಪ್ರತ್ಯಾಗಮ b;
    ಅನ್ಯಥಾ ಯದಿ (b == x86_64_mode_none)
        ಪ್ರತ್ಯಾಗಮ a;
    ಅನ್ಯಥಾ ಯದಿ ((a == x86_64_mode_memory) || (b == x86_64_mode_memory))
        ಪ್ರತ್ಯಾಗಮ x86_64_mode_memory;
    ಅನ್ಯಥಾ ಯದಿ ((a == x86_64_mode_integer) || (b == x86_64_mode_integer))
        ಪ್ರತ್ಯಾಗಮ x86_64_mode_integer;
    ಅನ್ಯಥಾ ಯದಿ ((a == x86_64_mode_x87) || (b == x86_64_mode_x87))
        ಪ್ರತ್ಯಾಗಮ x86_64_mode_memory;
    ಅನ್ಯಥಾ
        ಪ್ರತ್ಯಾಗಮ x86_64_mode_sse;
}

ಸ್ಥಿರ X86_64_Mode classify_x86_64_inner(CType *ty)
{
    X86_64_Mode mode;
    Sym *f;
    
    ವಿಕಲ್ಪ (ty->t & VT_BTYPE) {
    ಪಕ್ಷ VT_VOID: ಪ್ರತ್ಯಾಗಮ x86_64_mode_none;
    
    ಪಕ್ಷ VT_INT:
    ಪಕ್ಷ VT_BYTE:
    ಪಕ್ಷ VT_SHORT:
    ಪಕ್ಷ VT_LLONG:
    ಪಕ್ಷ VT_BOOL:
    ಪಕ್ಷ VT_PTR:
    ಪಕ್ಷ VT_FUNC:
        ಪ್ರತ್ಯಾಗಮ x86_64_mode_integer;
    
    ಪಕ್ಷ VT_FLOAT:
    ಪಕ್ಷ VT_DOUBLE: ಪ್ರತ್ಯಾಗಮ x86_64_mode_sse;
    
    ಪಕ್ಷ VT_LDOUBLE: ಪ್ರತ್ಯಾಗಮ x86_64_mode_x87;
      
    ಪಕ್ಷ VT_STRUCT:
        f = ty->ref;

        mode = x86_64_mode_none;
        ಪ್ರತಿ (f = f->next; f; f = f->next)
            mode = classify_x86_64_merge(mode, classify_x86_64_inner(&f->type));
        
        ಪ್ರತ್ಯಾಗಮ mode;
    }
    ಪ್ರತಿಜ್ಞಾ(0);
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ X86_64_Mode classify_x86_64_arg(CType *ty, CType *ret, ಪೂರ್ಣಾಙ್ಕ *psize, ಪೂರ್ಣಾಙ್ಕ *palign, ಪೂರ್ಣಾಙ್ಕ *reg_ಎಣಿಕೆ)
{
    X86_64_Mode mode;
    ಪೂರ್ಣಾಙ್ಕ size, align, ret_t = 0;
    
    ಯದಿ (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_ಎಣಿಕೆ = 1;
        ret_t = ty->t;
        mode = x86_64_mode_integer;
    } ಅನ್ಯಥಾ {
        size = type_size(ty, &align);
        *psize = (size + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_ಎಣಿಕೆ = 0; /* avoid compiler warning */

        ಯದಿ (size > 16) {
            mode = x86_64_mode_memory;
        } ಅನ್ಯಥಾ {
            mode = classify_x86_64_inner(ty);
            ವಿಕಲ್ಪ (mode) {
            ಪಕ್ಷ x86_64_mode_integer:
                ಯದಿ (size > 8) {
                    *reg_ಎಣಿಕೆ = 2;
                    ret_t = VT_QLONG;
                } ಅನ್ಯಥಾ {
                    *reg_ಎಣಿಕೆ = 1;
                    ಯದಿ (size > 4)
                        ret_t = VT_LLONG;
                    ಅನ್ಯಥಾ ಯದಿ (size > 2)
                        ret_t = VT_INT;
                    ಅನ್ಯಥಾ ಯದಿ (size > 1)
                        ret_t = VT_SHORT;
                    ಅನ್ಯಥಾ
                        ret_t = VT_BYTE;
                    ಯದಿ ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                ಭಙ್ಗ;
                
            ಪಕ್ಷ x86_64_mode_x87:
                *reg_ಎಣಿಕೆ = 1;
                ret_t = VT_LDOUBLE;
                ಭಙ್ಗ;

            ಪಕ್ಷ x86_64_mode_sse:
                ಯದಿ (size > 8) {
                    *reg_ಎಣಿಕೆ = 2;
                    ret_t = VT_QFLOAT;
                } ಅನ್ಯಥಾ {
                    *reg_ಎಣಿಕೆ = 1;
                    ret_t = (size > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                ಭಙ್ಗ;
            ಸ್ವಭಾವ: ಭಙ್ಗ; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    ಯದಿ (ret) {
        ret->ref = ರಿಕ್ತ;
        ret->t = ret_t;
    }
    
    ಪ್ರತ್ಯಾಗಮ mode;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    ಗಣನಾ __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    ಪೂರ್ಣಾಙ್ಕ size, align, reg_ಎಣಿಕೆ;
    X86_64_Mode mode = classify_x86_64_arg(ty, ರಿಕ್ತ, &size, &align, &reg_ಎಣಿಕೆ);
    ವಿಕಲ್ಪ (mode) {
    ಸ್ವಭಾವ: ಪ್ರತ್ಯಾಗಮ __va_stack;
    ಪಕ್ಷ x86_64_mode_integer: ಪ್ರತ್ಯಾಗಮ __va_gen_reg;
    ಪಕ್ಷ x86_64_mode_sse: ಪ್ರತ್ಯಾಗಮ __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಙ್ಕ variadic, CType *ret, ಪೂರ್ಣಾಙ್ಕ *ret_align, ಪೂರ್ಣಾಙ್ಕ *regsize)
{
    ಪೂರ್ಣಾಙ್ಕ size, align, reg_ಎಣಿಕೆ;
    ಯದಿ (classify_x86_64_arg(vt, ret, &size, &align, &reg_ಎಣಿಕೆ) == x86_64_mode_memory)
        ಪ್ರತ್ಯಾಗಮ 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_ಎಣಿಕೆ; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    ಪ್ರತ್ಯಾಗಮ 1;
}

#define REGN 6
ಸ್ಥಿರ ಧ್ರುವ uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ arg_prepare_reg(ಪೂರ್ಣಾಙ್ಕ idx) {
  ಯದಿ (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      ಪ್ರತ್ಯಾಗಮ idx + 8;
  ಅನ್ಯಥಾ
      ಪ್ರತ್ಯಾಗಮ idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಙ್ಕ nb_args)
{
    X86_64_Mode mode;
    CType type;
    ಪೂರ್ಣಾಙ್ಕ size, align, r, args_size, ರಾಶಿ_adjust, i, reg_ಎಣಿಕೆ, k;
    ಪೂರ್ಣಾಙ್ಕ nb_reg_args = 0;
    ಪೂರ್ಣಾಙ್ಕ nb_sse_args = 0;
    ಪೂರ್ಣಾಙ್ಕ sse_reg, gen_reg;
    ವರ್ಣ *onstack = tcc_malloc((nb_args + 1) * ಪರಿಮಾಣ (ವರ್ಣ));

#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    ರಾಶಿ_adjust = 0;
    ಪ್ರತಿ(i = nb_args - 1; i >= 0; i--) {
        mode = classify_x86_64_arg(&vtop[-i].type, ರಿಕ್ತ, &size, &align, &reg_ಎಣಿಕೆ);
        ಯದಿ (size == 0) ಅನುವರ್ತ;
        ಯದಿ (mode == x86_64_mode_sse && nb_sse_args + reg_ಎಣಿಕೆ <= 8) {
            nb_sse_args += reg_ಎಣಿಕೆ;
	    onstack[i] = 0;
	} ಅನ್ಯಥಾ ಯದಿ (mode == x86_64_mode_integer && nb_reg_args + reg_ಎಣಿಕೆ <= REGN) {
            nb_reg_args += reg_ಎಣಿಕೆ;
	    onstack[i] = 0;
	} ಅನ್ಯಥಾ ಯದಿ (mode == x86_64_mode_none) {
	    onstack[i] = 0;
	} ಅನ್ಯಥಾ {
	    ಯದಿ (align == 16 && (ರಾಶಿ_adjust &= 15)) {
		onstack[i] = 2;
		ರಾಶಿ_adjust = 0;
	    } ಅನ್ಯಥಾ
	      onstack[i] = 1;
	    ರಾಶಿ_adjust += size;
	}
    }

    ಯದಿ (nb_sse_args && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_args;
    sse_reg = nb_sse_args;
    args_size = 0;
    ರಾಶಿ_adjust &= 15;
    ಪ್ರತಿ (i = k = 0; i < nb_args;) {
	mode = classify_x86_64_arg(&vtop[-i].type, ರಿಕ್ತ, &size, &align, &reg_ಎಣಿಕೆ);
	ಯದಿ (size) {
            ಯದಿ (!onstack[i + k]) {
	        ++i;
	        ಅನುವರ್ತ;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            ಯದಿ (ರಾಶಿ_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                args_size += 8;
	        ರಾಶಿ_adjust = 0;
            }
	    ಯದಿ (onstack[i + k] == 2)
	        ರಾಶಿ_adjust = 1;
        }

	vrotb(i+1);

	ವಿಕಲ್ಪ (vtop->type.t & VT_BTYPE) {
	    ಪಕ್ಷ VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, size); /* sub $xxx, %rsp */
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
		ಭಙ್ಗ;

	    ಪಕ್ಷ VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, size); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		ಭಙ್ಗ;

	    ಪಕ್ಷ VT_FLOAT:
	    ಪಕ್ಷ VT_DOUBLE:
		ಪ್ರತಿಜ್ಞಾ(mode == x86_64_mode_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_ಮೌಲ್ಯ(r)*8);
		o(0x24);
		ಭಙ್ಗ;

	    ಸ್ವಭಾವ:
		ಪ್ರತಿಜ್ಞಾ(mode == x86_64_mode_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_ಮೌಲ್ಯ(r)); /* push r */
		ಭಙ್ಗ;
	}
	args_size += size;

	vpop();
	--nb_args;
	k++;
    }

    tcc_free(onstack);

    /* then, we prepare register passing arguments.
       Note that we cannot set RDX and RCX in this loop because gv()
       may break these temporary registers. Let's use R10 and R11
       instead of them */
    ಪ್ರತಿಜ್ಞಾ(gen_reg <= REGN);
    ಪ್ರತಿಜ್ಞಾ(sse_reg <= 8);
    ಪ್ರತಿ(i = 0; i < nb_args; i++) {
        mode = classify_x86_64_arg(&vtop->type, &type, &size, &align, &reg_ಎಣಿಕೆ);
        ಯದಿ (size == 0) ಅನುವರ್ತ;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        ಯದಿ (mode == x86_64_mode_sse) {
            ಯದಿ (reg_ಎಣಿಕೆ == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                ಯದಿ (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } ಅನ್ಯಥಾ {
                ಪ್ರತಿಜ್ಞಾ(reg_ಎಣಿಕೆ == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } ಅನ್ಯಥಾ ಯದಿ (mode == x86_64_mode_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            ಪೂರ್ಣಾಙ್ಕ d;
            gen_reg -= reg_ಎಣಿಕೆ;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_ಮೌಲ್ಯ(r) * 8 + REG_ಮೌಲ್ಯ(d));
            ಯದಿ (reg_ಎಣಿಕೆ == 2) {
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
    ಯದಿ (nb_reg_args > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        ಯದಿ (nb_reg_args > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    ಯದಿ (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_args < 8 ? nb_sse_args : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    ಯದಿ (args_size)
        gadd_sp(args_size);
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

ಸ್ಥಿರ ಶೂನ್ಯ ತಳ್ಳು_arg_reg(ಪೂರ್ಣಾಙ್ಕ i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, ರಿಕ್ತ, loc);
}

/* generate function prolog of type 't' */
ಶೂನ್ಯ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_Mode mode, ret_mode;
    ಪೂರ್ಣಾಙ್ಕ i, addr, align, size, reg_ಎಣಿಕೆ;
    ಪೂರ್ಣಾಙ್ಕ param_addr = 0, reg_param_index, sse_param_index;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_SIZE * 2;
    loc = 0;
    ind += FUNC_PROLOG_SIZE;
    func_sub_sp_offset = ind;
    func_ret_sub = 0;
    ret_mode = classify_x86_64_arg(&func_vt, ರಿಕ್ತ, &size, &align, &reg_ಎಣಿಕೆ);

    ಯದಿ (func_var) {
        ಪೂರ್ಣಾಙ್ಕ seen_reg_ಅಂಕೆ, seen_sse_ಅಂಕೆ, seen_ರಾಶಿ_size;
        seen_reg_ಅಂಕೆ = ret_mode == x86_64_mode_memory;
        seen_sse_ಅಂಕೆ = 0;
        /* frame pointer and return address */
        seen_ರಾಶಿ_size = PTR_SIZE * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        ಯಾವತ್ ((sym = sym->next) != ರಿಕ್ತ) {
            type = &sym->type;
            mode = classify_x86_64_arg(type, ರಿಕ್ತ, &size, &align, &reg_ಎಣಿಕೆ);
            ವಿಕಲ್ಪ (mode) {
            ಸ್ವಭಾವ:
            ರಾಶಿ_arg:
                seen_ರಾಶಿ_size = ((seen_ರಾಶಿ_size + align - 1) & -align) + size;
                ಭಙ್ಗ;
                
            ಪಕ್ಷ x86_64_mode_integer:
                ಯದಿ (seen_reg_ಅಂಕೆ + reg_ಎಣಿಕೆ > REGN)
		    ಗಚ್ಛ ರಾಶಿ_arg;
		seen_reg_ಅಂಕೆ += reg_ಎಣಿಕೆ;
                ಭಙ್ಗ;
                
            ಪಕ್ಷ x86_64_mode_sse:
                ಯದಿ (seen_sse_ಅಂಕೆ + reg_ಎಣಿಕೆ > 8)
		    ಗಚ್ಛ ರಾಶಿ_arg;
		seen_sse_ಅಂಕೆ += reg_ಎಣಿಕೆ;
                ಭಙ್ಗ;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(seen_reg_ಅಂಕೆ * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(seen_sse_ಅಂಕೆ * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(seen_ರಾಶಿ_size);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        ಪ್ರತಿ (i = 0; i < 8; i++) {
            loc -= 16;
	    ಯದಿ (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, ರಿಕ್ತ, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        ಪ್ರತಿ (i = 0; i < REGN; i++) {
            ತಳ್ಳು_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_index = 0;
    sse_param_index = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    ಯದಿ (ret_mode == x86_64_mode_memory) {
        ತಳ್ಳು_arg_reg(reg_param_index);
        func_vc = loc;
        reg_param_index++;
    }
    /* define parameters */
    ಯಾವತ್ ((sym = sym->next) != ರಿಕ್ತ) {
        type = &sym->type;
        mode = classify_x86_64_arg(type, ರಿಕ್ತ, &size, &align, &reg_ಎಣಿಕೆ);
        ವಿಕಲ್ಪ (mode) {
        ಪಕ್ಷ x86_64_mode_sse:
	    ಯದಿ (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            ಯದಿ (sse_param_index + reg_ಎಣಿಕೆ <= 8) {
                /* save arguments passed by register */
                loc -= reg_ಎಣಿಕೆ * 8;
                param_addr = loc;
                ಪ್ರತಿ (i = 0; i < reg_ಎಣಿಕೆ; ++i) {
                    gen_modrm32(0xd60f66, sse_param_index, VT_LOCAL, ರಿಕ್ತ, param_addr + i*8);
                    ++sse_param_index;
                }
            } ಅನ್ಯಥಾ {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            ಭಙ್ಗ;
            
        ಪಕ್ಷ x86_64_mode_memory:
        ಪಕ್ಷ x86_64_mode_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += size;
            ಭಙ್ಗ;
            
        ಪಕ್ಷ x86_64_mode_integer: {
            ಯದಿ (reg_param_index + reg_ಎಣಿಕೆ <= REGN) {
                /* save arguments passed by register */
                loc -= reg_ಎಣಿಕೆ * 8;
                param_addr = loc;
                ಪ್ರತಿ (i = 0; i < reg_ಎಣಿಕೆ; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ರಿಕ್ತ, param_addr + i*8);
                    ++reg_param_index;
                }
            } ಅನ್ಯಥಾ {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            ಭಙ್ಗ;
        }
	ಸ್ವಭಾವ: ಭಙ್ಗ; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_set_param(sym, param_addr, 0);
    }

#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ v, saved_ind;

#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif
    o(0xc9); /* leave */
    ಯದಿ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ಅನ್ಯಥಾ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    /* align local size to word & save local variables */
    v = (-loc + 15) & -16;
    saved_ind = ind;
    ind = func_sub_sp_offset - FUNC_PROLOG_SIZE;
    o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
    o(0xec8148);  /* sub rsp, stacksize */
    gen_le32(v);
    ind = saved_ind;
}

#endif /* not PE */

ST_FUNC ಶೂನ್ಯ gen_fill_nops(ಪೂರ್ಣಾಙ್ಕ bytes)
{
    ಯಾವತ್ (bytes--)
      g(0x90);
}

/* generate a jump to a label */
ಪೂರ್ಣಾಙ್ಕ gjmp(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪ್ರತ್ಯಾಗಮ gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಙ್ಕ a)
{
    ಪೂರ್ಣಾಙ್ಕ r;
    r = a - ind - 2;
    ಯದಿ (r == (signed ವರ್ಣ)r) {
        g(0xeb);
        g(r);
    } ಅನ್ಯಥಾ {
        oad(0xe9, a - ind - 5);
    }
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

ST_FUNC ಪೂರ್ಣಾಙ್ಕ gjmp_cond(ಪೂರ್ಣಾಙ್ಕ op, ಪೂರ್ಣಾಙ್ಕ t)
{
        ಯದಿ (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            ಪೂರ್ಣಾಙ್ಕ v = vtop->cmp_r;
            op &= ~0x100;
            ಯದಿ (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    ಅನ್ಯಥಾ
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        ಪ್ರತ್ಯಾಗಮ t;
}

/* generate an integer binary operation */
ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಙ್ಕ op)
{
    ಪೂರ್ಣಾಙ್ಕ r, fr, opc, c;
    ಪೂರ್ಣಾಙ್ಕ ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    ವಿಕಲ್ಪ(op) {
    ಪಕ್ಷ '+':
    ಪಕ್ಷ TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        ಯದಿ (cc && (!ll || (ಪೂರ್ಣಾಙ್ಕ)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            ಯದಿ (c == (signed ವರ್ಣ)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_ಮೌಲ್ಯ(r));
                g(c);
            } ಅನ್ಯಥಾ {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_ಮೌಲ್ಯ(r), c);
            }
        } ಅನ್ಯಥಾ {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_ಮೌಲ್ಯ(r) + REG_ಮೌಲ್ಯ(fr) * 8);
        }
        vtop--;
        ಯದಿ (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        ಭಙ್ಗ;
    ಪಕ್ಷ '-':
    ಪಕ್ಷ TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        ಗಚ್ಛ gen_op8;
    ಪಕ್ಷ TOK_ADDC2: /* add with carry use */
        opc = 2;
        ಗಚ್ಛ gen_op8;
    ಪಕ್ಷ TOK_SUBC2: /* sub with carry use */
        opc = 3;
        ಗಚ್ಛ gen_op8;
    ಪಕ್ಷ '&':
        opc = 4;
        ಗಚ್ಛ gen_op8;
    ಪಕ್ಷ '^':
        opc = 6;
        ಗಚ್ಛ gen_op8;
    ಪಕ್ಷ '|':
        opc = 1;
        ಗಚ್ಛ gen_op8;
    ಪಕ್ಷ '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_ಮೌಲ್ಯ(fr) + REG_ಮೌಲ್ಯ(r) * 8);
        vtop--;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_SHL:
        opc = 4;
        ಗಚ್ಛ gen_shift;
    ಪಕ್ಷ TOK_SHR:
        opc = 5;
        ಗಚ್ಛ gen_shift;
    ಪಕ್ಷ TOK_SAR:
        opc = 7;
    gen_shift:
        opc = 0xc0 | (opc << 3);
        ಯದಿ (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_ಮೌಲ್ಯ(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } ಅನ್ಯಥಾ {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_ಮೌಲ್ಯ(r));
        }
        vtop--;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_UDIV:
    ಪಕ್ಷ TOK_UMOD:
        uu = 1;
        ಗಚ್ಛ divmod;
    ಪಕ್ಷ '/':
    ಪಕ್ಷ '%':
    ಪಕ್ಷ TOK_PDIV:
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
        ಯದಿ (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        ಅನ್ಯಥಾ
            r = TREG_RAX;
        vtop->r = r;
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        opc = 7;
        ಗಚ್ಛ gen_op8;
    }
}

ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಙ್ಕ op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಙ್ಕ op)
{
    ಪೂರ್ಣಾಙ್ಕ a, ft, fc, swapped, r, opc;
    ಪೂರ್ಣಾಙ್ಕ bt = vtop->type.t & VT_BTYPE;
    ಪೂರ್ಣಾಙ್ಕ float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    ಯದಿ (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        ಯದಿ (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } ಅನ್ಯಥಾ {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, ರಿಕ್ತ, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        ಪ್ರತ್ಯಾಗಮ;
    }

    /* convert constants to memory references */
    ಯದಿ ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    ಯದಿ ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    ಯದಿ ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    ಯದಿ (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        ಯದಿ (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            load(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            ಯದಿ (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            ಅನ್ಯಥಾ ಯದಿ (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            ಯದಿ (swapped)
                o(0xc9d9); /* fxch %st(1) */
            ಯದಿ (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            ಅನ್ಯಥಾ
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            ಯದಿ (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } ಅನ್ಯಥಾ ಯದಿ (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } ಅನ್ಯಥಾ ಯದಿ (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } ಅನ್ಯಥಾ {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } ಅನ್ಯಥಾ {
            /* no memory reference possible for long double operations */
            load(TREG_ST0, vtop);
            swapped = !swapped;

            ವಿಕಲ್ಪ(op) {
            ಸ್ವಭಾವ:
            ಪಕ್ಷ '+':
                a = 0;
                ಭಙ್ಗ;
            ಪಕ್ಷ '-':
                a = 4;
                ಯದಿ (swapped)
                    a++;
                ಭಙ್ಗ;
            ಪಕ್ಷ '*':
                a = 1;
                ಭಙ್ಗ;
            ಪಕ್ಷ '/':
                a = 6;
                ಯದಿ (swapped)
                    a++;
                ಭಙ್ಗ;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } ಅನ್ಯಥಾ {
        ಯದಿ (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            ಯದಿ ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = ರಿಕ್ತ;
                load(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            ಯದಿ (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } ಅನ್ಯಥಾ {
                ಯದಿ (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                ಯದಿ (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } ಅನ್ಯಥಾ {
                    op = 0x97; /* seta */
                }
            }

            ಯದಿ (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            ಪ್ರತಿಜ್ಞಾ(!(vtop[-1].r & VT_LVAL));
            
            ಯದಿ (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            ಅನ್ಯಥಾ
                opc = 0x2f0f; /* comisd */
            ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } ಅನ್ಯಥಾ {
            ಪ್ರತಿಜ್ಞಾ((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            ವಿಕಲ್ಪ(op) {
            ಸ್ವಭಾವ:
            ಪಕ್ಷ '+':
                a = 0;
                ಭಙ್ಗ;
            ಪಕ್ಷ '-':
                a = 4;
                ಭಙ್ಗ;
            ಪಕ್ಷ '*':
                a = 1;
                ಭಙ್ಗ;
            ಪಕ್ಷ '/':
                a = 6;
                ಭಙ್ಗ;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            ಪ್ರತಿಜ್ಞಾ((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            ಯದಿ ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = ರಿಕ್ತ;
                load(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            ಪ್ರತಿಜ್ಞಾ(!(vtop[-1].r & VT_LVAL));
            ಯದಿ (swapped) {
                ಪ್ರತಿಜ್ಞಾ(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            ಯದಿ ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } ಅನ್ಯಥಾ {
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
ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಯದಿ ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } ಅನ್ಯಥಾ ಯದಿ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } ಅನ್ಯಥಾ {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } ಅನ್ಯಥಾ {
        ಪೂರ್ಣಾಙ್ಕ r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        ಯದಿ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
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
ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    ಯದಿ (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        ಯದಿ (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r)*9);
        } ಅನ್ಯಥಾ ಯದಿ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_ಮೌಲ್ಯ(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        ಯದಿ (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r)*9);
        } ಅನ್ಯಥಾ ಯದಿ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_ಮೌಲ್ಯ(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } ಅನ್ಯಥಾ {
        ಪೂರ್ಣಾಙ್ಕ r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        ಯದಿ (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_ಮೌಲ್ಯ(r)*8);
            o(0xf024);
            vtop->r = r;
        } ಅನ್ಯಥಾ ಯದಿ (tbt == VT_FLOAT) {
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
ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ ft, bt, size, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    ಯದಿ (bt == VT_LDOUBLE) {
	ಯದಿ (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    ಪ್ರತ್ಯಾಗಮ;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    ಯದಿ (t != VT_INT)
        size = 8;
    ಅನ್ಯಥಾ
        size = 4;

    r = get_reg(RC_INT);
    ಯದಿ (bt == VT_FLOAT) {
        o(0xf3);
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_DOUBLE) {
        o(0xf2);
    } ಅನ್ಯಥಾ {
        ಪ್ರತಿಜ್ಞಾ(0);
    }
    orex(size == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_ಮೌಲ್ಯ(vtop->r) + REG_ಮೌಲ್ಯ(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC ಶೂನ್ಯ gen_cvt_sxtw(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_ಮೌಲ್ಯ(r) << 3) + REG_ಮೌಲ್ಯ(r));
}

/* char/short to int conversion */
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ r, sz, xl, ll;
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
   greloca(cur_text_section, sv->sym, ind, R_X86_64_PC32, -5);
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
ST_FUNC ಶೂನ್ಯ gen_vla_sp_save(ಪೂರ್ಣಾಙ್ಕ addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, ರಿಕ್ತ, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_sp_restore(ಪೂರ್ಣಾಙ್ಕ addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, ರಿಕ್ತ, addr);
}

#ifdef TCC_TARGET_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_result(ಪೂರ್ಣಾಙ್ಕ addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, ರಿಕ್ತ, addr);
}
#endif

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_alloc(CType *type, ಪೂರ್ಣಾಙ್ಕ align) {
    ಪೂರ್ಣಾಙ್ಕ use_call = 0;

#ಯದಿ defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#endif
#ifdef TCC_TARGET_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#endif
    ಯದಿ (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    ಅನ್ಯಥಾ {
        ಪೂರ್ಣಾಙ್ಕ r;
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
ST_FUNC ಶೂನ್ಯ gen_struct_copy(ಪೂರ್ಣಾಙ್ಕ size)
{
    ಪೂರ್ಣಾಙ್ಕ n = size / PTR_SIZE;
#ifdef TCC_TARGET_PE
    o(0x5756); /* push rsi, rdi */
#endif
    gv2(RC_RDI, RC_RSI);
    ಯದಿ (n <= 4) {
        ಯಾವತ್ (n)
            o(0xa548), --n;
    } ಅನ್ಯಥಾ {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    ಯದಿ (size & 0x04)
        o(0xa5);
    ಯದಿ (size & 0x02)
        o(0xa566);
    ಯದಿ (size & 0x01)
        o(0xa4);
#ifdef TCC_TARGET_PE
    o(0x5e5f); /* pop rdi, rsi */
#endif
    vpop();
    vpop();
}

/* end of x86-64 code generator */
/*************************************************************/
#endif /* ! TARGET_DEFS_ONLY */
/******************************************************/
