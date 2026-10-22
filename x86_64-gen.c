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

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

/* number of available registers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_REGS         25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_ASM_REGS     16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_INT     0x0001 /* generic integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FLOAT   0x0002 /* generic float register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_RAX     0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_RDX     0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_RCX     0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_RSI     0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_RDI     0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_ST0     0x0080 /* only for long double */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R8      0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R9      0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R10     0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R11     0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_XMM0    0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_XMM1    0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_XMM2    0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_XMM3    0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_XMM4    0x10000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_XMM5    0x20000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_XMM6    0x40000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_XMM7    0x80000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_IRET    RC_RAX /* function return: integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_IRE2    RC_RDX /* function return: second integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FRET    RC_XMM0 /* function return: float register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FRE2    RC_XMM1 /* function return: second float register */

/* pretty names for the registers */
ਗਿਣਤੀ {
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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REX_ਅਧਾਰ(reg) (((reg) >> 3) & 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਮੁੱਲ(reg) ((reg) & 7)

/* return registers for function */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IRET TREG_RAX /* single word int return register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IRE2 TREG_RDX /* second word return register (for long long) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_FRET TREG_XMM0 /* float return register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_FRE2 TREG_XMM1 /* second float return register */

/* defined if function parameters must be evaluated in reverse order */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INVERT_FUNC_PARAMS

/* pointer size, in bytes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTR_ਮਾਪ 8

/* long double size and alignment, in bytes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ਮਾਪ  16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ALIGN 16
/* maximum alignment (for aligned attribute support) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_ALIGN     16

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROMOTE_RET

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_ਨਿਸ਼ਾਨਾ_NATIVE_STRUCT_COPY
ST_FUNC ਖਾਲੀ gen_struct_copy(ਪੂਰਨ ਮਾਪ);

/******************************************************/
#ਨਹੀਂਤਾਂ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"
#ਅਨ੍ਤਰ੍ਭਾਵ <assert.h>

ST_ਅੰਕੜੇ ਅਚਲ ਅੱਖਰ * ਅਚਲ ਨਿਸ਼ਾਨਾ_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_ਅੰਕੜੇ ਅਚਲ ਪੂਰਨ reg_classes[NB_REGS] = {
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

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ func_sub_sp_ਵਿੱਥ;
ਸਥਿਰ ਪੂਰਨ func_ret_sub;

#ਜੇ defined(CONFIG_TCC_BCHECK)
ਸਥਿਰ addr_t func_bound_ਵਿੱਥ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ func_bound_ind;
ST_ਅੰਕੜੇ ਪੂਰਨ func_bound_ਜੋੜੋ_epilog;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
ਸਥਿਰ ਪੂਰਨ func_scratch, func_alloca;
#ਜੇ_ਅੰਤ

/* XXX: make it faster ? */
ST_FUNC ਖਾਲੀ g(ਪੂਰਨ c)
{
    ਪੂਰਨ ind1;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    ind1 = ind + 1;
    ਜੇ (ind1 > cur_ਪਾਠ_section->ਅੰਕੜੇ_allocated)
        section_realloc(cur_ਪਾਠ_section, ind1);
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind] = c;
    ind = ind1;
}

ST_FUNC ਖਾਲੀ o(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ c)
{
    ਜਦੋਂ (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC ਖਾਲੀ gen_le16(ਪੂਰਨ v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC ਖਾਲੀ gen_le32(ਪੂਰਨ c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

ST_FUNC ਖਾਲੀ gen_le64(int64_t c)
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

ਸਥਿਰ ਖਾਲੀ orex(ਪੂਰਨ ll, ਪੂਰਨ r, ਪੂਰਨ r2, ਪੂਰਨ b)
{
    ਜੇ ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    ਜੇ ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    ਜੇ (ll || REX_ਅਧਾਰ(r) || REX_ਅਧਾਰ(r2)) {
        ਜੇ ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_ਅਧਾਰ(r) | (REX_ਅਧਾਰ(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC ਖਾਲੀ gsym_addr(ਪੂਰਨ t, ਪੂਰਨ a)
{
    ਜਦੋਂ (t) {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr = cur_ਪਾਠ_section->ਅੰਕੜੇ + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

ਸਥਿਰ ਪੂਰਨ is64_type(ਪੂਰਨ t)
{
    ਵਾਪਸ ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
ਸਥਿਰ ਪੂਰਨ oad(ਪੂਰਨ c, ਪੂਰਨ s)
{
    ਪੂਰਨ t;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ s;
    o(c);
    t = ind;
    gen_le32(s);
    ਵਾਪਸ t;
}

/* generate jmp to a label */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC ਖਾਲੀ gen_addr32(ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c)
{
    ਜੇ (r & VT_SYM)
        greloca(cur_ਪਾਠ_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ਖਾਲੀ gen_addrpc32(ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c)
{
    ਜੇ (r & VT_SYM)
        greloca(cur_ਪਾਠ_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
ਸਥਿਰ ਖਾਲੀ gen_gotpcrel(ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, ਨਿਰਾ), c, r,
        cur_ਪਾਠ_section->ਅੰਕੜੇ[ind-3],
        cur_ਪਾਠ_section->ਅੰਕੜੇ[ind-2],
        cur_ਪਾਠ_section->ਅੰਕੜੇ[ind-1]
        );
#ਜੇ_ਅੰਤ
    greloca(cur_ਪਾਠ_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    ਜੇ (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_ਮੁੱਲ(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
ਸਥਿਰ ਖਾਲੀ gen_modrm_impl(ਪੂਰਨ opcode, ਪੂਰਨ ll, ਪੂਰਨ op_reg_0, ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c)
{
    ਪੂਰਨ op_reg = REG_ਮੁੱਲ(op_reg_0) << 3;

    ਜੇ ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        Sym *s2 = external_global_sym(TOK_tls_ਸੂਚਕਾਂਕ, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_ਮਾਪ); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_ਪਾਠ_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#ਨਹੀਂਤਾਂ
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_ਪਾਠ_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#ਜੇ_ਅੰਤ
        ਵਾਪਸ;
    }

    orex(ll, r, op_reg_0, opcode);

    ਜੇ ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	ਜੇ (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} ਨਹੀਂਤਾਂ {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    ਜੇ (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } ਨਹੀਂਤਾਂ {
		gen_addrpc32(r, sym, c);
	    }
	}
    } ਨਹੀਂਤਾਂ ਜੇ ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        ਜੇ (c == (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } ਨਹੀਂਤਾਂ {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } ਨਹੀਂਤਾਂ ਜੇ ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_ਮੁੱਲ(r));
        gen_le32(c);
    } ਨਹੀਂਤਾਂ ਜੇ (r & VT_LVAL) {
        g(0x00 | op_reg | REG_ਮੁੱਲ(r));
    } ਨਹੀਂਤਾਂ {
        g(0xc0 | op_reg | REG_ਮੁੱਲ(r));
    }
}

ਸਥਿਰ ਖਾਲੀ gen_modrm64(ਪੂਰਨ opcode, ਪੂਰਨ op_reg, ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

ਸਥਿਰ ਖਾਲੀ gen_modrm32(ਪੂਰਨ opcode, ਪੂਰਨ op_reg, ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
ਖਾਲੀ ਲੱਦੋ(ਪੂਰਨ r, SValue *sv)
{
    ਪੂਰਨ v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    ਜੇ (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    /* we use indirect access via got */
    ਜੇ ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        ਪੂਰਨ tr = r | TREG_MEM;
        ਜੇ (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#ਜੇ_ਅੰਤ

    v = fr & VT_VALMASK;
    ਜੇ (fr & VT_LVAL) {
        ਪੂਰਨ b, ll;
        ਜੇ (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = ਨਿਰਾ;
            fr = r;
            ਜੇ (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            ਲੱਦੋ(fr, &v1);
            fr |= VT_LVAL;
        }
	ਜੇ (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = ਨਿਰਾ;
	    fr = r;
	    ਜੇ (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    ਲੱਦੋ(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	ਜੇ ((ft & VT_BTYPE) == VT_STRUCT) {
	    ਪੂਰਨ align;
	    ਚੋਣ (type_ਮਾਪ(&sv->type, &align)) {
		ਹਾਲਤ 1: ft = VT_BYTE; ਰੋਕੋ;
		ਹਾਲਤ 2: ft = VT_SHORT; ਰੋਕੋ;
		ਹਾਲਤ 4: ft = VT_INT; ਰੋਕੋ;
		ਹਾਲਤ 8: ft = VT_LLONG; ਰੋਕੋ;
		ਮੂਲ:
		    tcc_error("invalid aggregate type for register load");
		    ਰੋਕੋ;
	    }
	}
        ਜੇ ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_ਮੁੱਲ(r); /* movd */
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_ਮੁੱਲ(r);
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            ਵਾਪਸ;
        } ਨਹੀਂਤਾਂ {
            ਪ੍ਰਤਿਜ੍ਞਾ(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } ਨਹੀਂਤਾਂ {
        ਜੇ (v == VT_CONST) {
            ਜੇ (fr & VT_SYM) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#ਨਹੀਂਤਾਂ
                ਜੇ (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, ਨਿਰਾ, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_ਮੁੱਲ(r), 0);
                    greloca(cur_ਪਾਠ_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } ਨਹੀਂਤਾਂ ਜੇ (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_ਮੁੱਲ(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } ਨਹੀਂਤਾਂ {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_ਮੁੱਲ(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#ਜੇ_ਅੰਤ
            } ਨਹੀਂਤਾਂ ਜੇ (is64_type(ft)) {
                ਜੇ (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_ਮੁੱਲ(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } ਨਹੀਂਤਾਂ ਜੇ (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_ਮੁੱਲ(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } ਨਹੀਂਤਾਂ {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_ਮੁੱਲ(r) * 9);
                }
            } ਨਹੀਂਤਾਂ {
                orex(0,r,0, 0xb8 + REG_ਮੁੱਲ(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_CMP) {
	    ਜੇ (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_ਮੁੱਲ(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_ਅਧਾਰ(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_ਮੁੱਲ(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_ਮੁੱਲ(r) * 0x900); /* movzbl %al, %eax */
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_ਮੁੱਲ(r), t); /* mov $1, r */
            o(0x05eb + (REX_ਅਧਾਰ(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_ਮੁੱਲ(r), t ^ 1); /* mov $0, r */
        } ਨਹੀਂਤਾਂ ਜੇ (v != r) {
            ਜੇ ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                ਜੇ (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_ਮੁੱਲ(r)*8); /* %xmmN */
                    o(0xf024);
                } ਨਹੀਂਤਾਂ {
                    ਪ੍ਰਤਿਜ੍ਞਾ((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    ਜੇ ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } ਨਹੀਂਤਾਂ {
                        ਪ੍ਰਤਿਜ੍ਞਾ((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_ਮੁੱਲ(v) + REG_ਮੁੱਲ(r)*8);
                }
            } ਨਹੀਂਤਾਂ ਜੇ (r == TREG_ST0) {
                ਪ੍ਰਤਿਜ੍ਞਾ((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_ਮੁੱਲ(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } ਨਹੀਂਤਾਂ {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_ਮੁੱਲ(r) + REG_ਮੁੱਲ(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
ਖਾਲੀ store(ਪੂਰਨ r, SValue *v)
{
    ਪੂਰਨ fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    ਪੂਰਨ opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    ਜੇ (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    /* we need to access the variable via got */
    ਜੇ ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#ਜੇ_ਅੰਤ

    /* XXX: incorrect if float reg to reg */
    ਜੇ (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_ਮੁੱਲ(r);
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_ਮੁੱਲ(r);
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } ਨਹੀਂਤਾਂ {
        opc = 0x89;
        ਜੇ (bt == VT_SHORT)
            opc = 0x8966;
        ਨਹੀਂਤਾਂ ਜੇ (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
ਸਥਿਰ ਖਾਲੀ gcall_or_jmp(ਪੂਰਨ is_jmp)
{
    ਪੂਰਨ r;
    ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (ਪੂਰਨ)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_ਪਾਠ_section, vtop->sym, ind + 1, R_X86_64_PLT32, (ਪੂਰਨ)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } ਨਹੀਂਤਾਂ {
        /* otherwise, indirect call */
        r = TREG_R11;
        ਲੱਦੋ(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_ਮੁੱਲ(r) + (is_jmp << 4));
    }
}

#ਜੇ defined(CONFIG_TCC_BCHECK)

ਸਥਿਰ ਖਾਲੀ gen_bounds_call(ਪੂਰਨ v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_ਪਾਠ_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
# define TREG_FASTCALL_1 TREG_RCX
#ਨਹੀਂਤਾਂ
# define TREG_FASTCALL_1 TREG_RDI
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਖਾਲੀ gen_bounds_prolog(ਖਾਲੀ)
{
    /* leave some room for bound checking code */
    func_bound_ਵਿੱਥ = lbounds_section->ਅੰਕੜੇ_ਵਿੱਥ;
    func_bound_ind = ind;
    func_bound_ਜੋੜੋ_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
}

ਸਥਿਰ ਖਾਲੀ gen_bounds_epilog(ਖਾਲੀ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ਅੰਕੜੇ;
    ਪੂਰਨ ਵਿੱਥ_modified = func_bound_ਵਿੱਥ != lbounds_section->ਅੰਕੜੇ_ਵਿੱਥ;

    ਜੇ (!ਵਿੱਥ_modified && !func_bound_ਜੋੜੋ_epilog)
        ਵਾਪਸ;

    /* add end of table info */
    bounds_ptr = section_ptr_ਜੋੜੋ(lbounds_section, ਆਕਾਰ(addr_t));
    *bounds_ptr = 0;

    sym_ਅੰਕੜੇ = get_sym_ref(&char_ਸੂਚਕ_type, lbounds_section, 
                           func_bound_ਵਿੱਥ, PTR_ਮਾਪ);

    /* generate bound local allocation */
    ਜੇ (ਵਿੱਥ_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        greloca(cur_ਪਾਠ_section, sym_ਅੰਕੜੇ, ind + 3, R_X86_64_PC32, -4);
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
    greloca(cur_ਪਾਠ_section, sym_ਅੰਕੜੇ, ind + 3, R_X86_64_PC32, -4);
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /* lea xxx(%rip), %rcx/rdi */
    gen_le32 (0);
    gen_bounds_call(TOK___bound_local_delete);
    o(0x280f);     /* movaps 0x10(%rsp),%xmm0 */
    o(0x102444);
    o(0x240c280f); /* movaps (%rsp),%xmm1 */
    o(0x20c48348); /* add $32,%rsp */
    o(0x585a); /* restore returned value, if any */
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REGN 4
ਸਥਿਰ ਅਚਲ uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
ਸਥਿਰ ਪੂਰਨ arg_prepare_reg(ਪੂਰਨ idx) {
  ਜੇ (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      ਵਾਪਸ idx + 10;
  ਨਹੀਂਤਾਂ
      ਵਾਪਸ idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

ਸਥਿਰ ਖਾਲੀ gen_offs_sp(ਪੂਰਨ b, ਪੂਰਨ r, ਪੂਰਨ d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    ਜੇ (d == (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)d) {
        o(0x2444 | (REG_ਮੁੱਲ(r) << 3));
        g(d);
    } ਨਹੀਂਤਾਂ {
        o(0x2484 | (REG_ਮੁੱਲ(r) << 3));
        gen_le32(d);
    }
}

ਸਥਿਰ ਪੂਰਨ using_regs(ਪੂਰਨ ਮਾਪ)
{
    ਵਾਪਸ !(ਮਾਪ > 8 || (ਮਾਪ & (ਮਾਪ - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ਪੂਰਨ gfunc_sret(CType *vt, ਪੂਰਨ variadic, CType *ret, ਪੂਰਨ *ret_align, ਪੂਰਨ *regsize)
{
    ਪੂਰਨ ਮਾਪ, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    ਮਾਪ = type_ਮਾਪ(vt, &align);
    ਜੇ (!using_regs(ਮਾਪ))
        ਵਾਪਸ 0;
    ਜੇ (ਮਾਪ == 8)
        ret->t = VT_LLONG;
    ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ == 4)
        ret->t = VT_INT;
    ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ == 2)
        ret->t = VT_SHORT;
    ਨਹੀਂਤਾਂ
        ret->t = VT_BYTE;
    ret->ref = ਨਿਰਾ;
    ਵਾਪਸ 1;
}

ਸਥਿਰ ਪੂਰਨ is_sse_float(ਪੂਰਨ t) {
    ਪੂਰਨ bt;
    bt = t & VT_BTYPE;
    ਵਾਪਸ bt == VT_DOUBLE || bt == VT_FLOAT;
}

ਸਥਿਰ ਪੂਰਨ gfunc_arg_ਮਾਪ(CType *type) {
    ਪੂਰਨ align;
    ਜੇ (type->t & (VT_ARRAY|VT_BITFIELD))
        ਵਾਪਸ 8;
    ਵਾਪਸ type_ਮਾਪ(type, &align);
}

ਖਾਲੀ gfunc_call(ਪੂਰਨ nb_ਦਲੀਲਾਂ)
{
    ਪੂਰਨ ਮਾਪ, r, ਦਲੀਲਾਂ_ਮਾਪ, i, d, bt, struct_ਮਾਪ;
    ਪੂਰਨ arg;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gbound_ਦਲੀਲਾਂ(nb_ਦਲੀਲਾਂ);
#ਜੇ_ਅੰਤ

    save_regs(nb_ਦਲੀਲਾਂ);

    ਦਲੀਲਾਂ_ਮਾਪ = (nb_ਦਲੀਲਾਂ < REGN ? REGN : nb_ਦਲੀਲਾਂ) * PTR_ਮਾਪ;
    arg = nb_ਦਲੀਲਾਂ;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_ਮਾਪ = ਦਲੀਲਾਂ_ਮਾਪ;
    ਲਈ(i = 0; i < nb_ਦਲੀਲਾਂ; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        ਮਾਪ = gfunc_arg_ਮਾਪ(&sv->type);

        ਜੇ (using_regs(ਮਾਪ))
            ਜਾਰੀ; /* arguments smaller than 8 bytes passed in registers or on stack */

        ਜੇ (bt == VT_STRUCT) {
            /* align to stack align size */
            ਮਾਪ = (ਮਾਪ + 15) & ~15;
            /* generate structure store */
            r = get_reg(RC_INT);
            gen_offs_sp(0x8d, r, struct_ਮਾਪ);
            struct_ਮਾਪ += ਮਾਪ;

            /* generate memcpy call */
            vset(&sv->type, r | VT_LVAL, 0);
            vpushv(sv);
            vstore();
            --vtop;
        } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_ਮਾਪ);
            struct_ਮਾਪ += 16;
        }
    }

    ਜੇ (func_scratch < struct_ਮਾਪ)
        func_scratch = struct_ਮਾਪ;

    arg = nb_ਦਲੀਲਾਂ;
    struct_ਮਾਪ = ਦਲੀਲਾਂ_ਮਾਪ;

    ਲਈ(i = 0; i < nb_ਦਲੀਲਾਂ; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        ਮਾਪ = gfunc_arg_ਮਾਪ(&vtop->type);
        ਜੇ (!using_regs(ਮਾਪ)) {
            /* align to stack align size */
            ਮਾਪ = (ਮਾਪ + 15) & ~15;
            ਜੇ (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_ਮਾਪ);
                gen_offs_sp(0x89, d, arg*8);
            } ਨਹੀਂਤਾਂ {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_ਮਾਪ);
            }
            struct_ਮਾਪ += ਮਾਪ;
        } ਨਹੀਂਤਾਂ {
            ਜੇ (is_sse_float(vtop->type.t)) {
		ਜੇ (tcc_state->nosse)
		  tcc_error("SSE disabled");
                ਜੇ (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } ਨਹੀਂਤਾਂ {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_ਮੁੱਲ(d));
                }
            } ਨਹੀਂਤਾਂ {
                ਜੇ (bt == VT_STRUCT) {
                    vtop->type.ref = ਨਿਰਾ;
                    vtop->type.t = ਮਾਪ > 4 ? VT_LLONG : ਮਾਪ > 2 ? VT_INT
                        : ਮਾਪ > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                ਜੇ (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } ਨਹੀਂਤਾਂ {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_ਮੁੱਲ(r) * 8 + REG_ਮੁੱਲ(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    ਜੇ (nb_ਦਲੀਲਾਂ > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        ਜੇ (nb_ਦਲੀਲਾਂ > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    ਜੇ ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#ਜੇ_ਅੰਤ
    }
    vtop--;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_PROLOG_ਮਾਪ 11

/* generate function prolog of type 't' */
ਖਾਲੀ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ਪੂਰਨ addr, reg_param_ਸੂਚਕਾਂਕ, bt, ਮਾਪ;
    Sym *sym;
    CType *type;

    func_ret_sub = 0;
    func_scratch = 32;
    func_alloca = 0;
    loc = 0;

    addr = PTR_ਮਾਪ * 2;
    ind += FUNC_PROLOG_ਮਾਪ;
    func_sub_sp_ਵਿੱਥ = ind;
    reg_param_ਸੂਚਕਾਂਕ = 0;

    sym = func_type->ref;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    ਮਾਪ = gfunc_arg_ਮਾਪ(&func_vt);
    ਜੇ (!using_regs(ਮਾਪ)) {
        gen_modrm64(0x89, arg_regs[reg_param_ਸੂਚਕਾਂਕ], VT_LOCAL, ਨਿਰਾ, addr);
        func_vc = addr;
        reg_param_ਸੂਚਕਾਂਕ++;
        addr += 8;
    }

    /* define parameters */
    ਜਦੋਂ ((sym = sym->ਅਗਲਾ) != ਨਿਰਾ) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        ਮਾਪ = gfunc_arg_ਮਾਪ(type);
        ਜੇ (!using_regs(ਮਾਪ)) {
            ਜੇ (reg_param_ਸੂਚਕਾਂਕ < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_ਸੂਚਕਾਂਕ], VT_LOCAL, ਨਿਰਾ, addr);
            }
            gfunc_ਸੈੱਟ_param(sym, addr, 1);
        } ਨਹੀਂਤਾਂ {
            ਜੇ (reg_param_ਸੂਚਕਾਂਕ < REGN) {
                /* save arguments passed by register */
                ਜੇ ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    ਜੇ (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_ਸੂਚਕਾਂਕ, VT_LOCAL, ਨਿਰਾ, addr);
                } ਨਹੀਂਤਾਂ {
                    gen_modrm64(0x89, arg_regs[reg_param_ਸੂਚਕਾਂਕ], VT_LOCAL, ਨਿਰਾ, addr);
                }
            }
            gfunc_ਸੈੱਟ_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_ਸੂਚਕਾਂਕ++;
    }

    ਜਦੋਂ (reg_param_ਸੂਚਕਾਂਕ < REGN) {
        ਜੇ (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_ਸੂਚਕਾਂਕ], VT_LOCAL, ਨਿਰਾ, addr);
            addr += 8;
        }
        reg_param_ਸੂਚਕਾਂਕ++;
    }
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#ਜੇ_ਅੰਤ
}

/* generate function epilog */
ਖਾਲੀ gfunc_epilog(ਖਾਲੀ)
{
    ਪੂਰਨ v, ਸ਼ੁਰੂ;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#ਜੇ_ਅੰਤ

    o(0xc9); /* leave */
    ਜੇ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ਨਹੀਂਤਾਂ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    ਸ਼ੁਰੂ = func_sub_sp_ਵਿੱਥ - FUNC_PROLOG_ਮਾਪ;
    cur_ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ = ind;
    pe_ਜੋੜੋ_unwind_ਅੰਕੜੇ(ਸ਼ੁਰੂ, ind, v);

    ind = ਸ਼ੁਰੂ;
    ਜੇ (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_ਪਾਠ_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } ਨਹੀਂਤਾਂ {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#ਨਹੀਂਤਾਂ

ਸਥਿਰ ਖਾਲੀ gadd_sp(ਪੂਰਨ val)
{
    ਜੇ (val == (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)val) {
        o(0xc48348);
        g(val);
    } ਨਹੀਂਤਾਂ {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ X86_64_ਬਹੁਲਕ {
  x86_64_ਬਹੁਲਕ_none,
  x86_64_ਬਹੁਲਕ_ਸਮ੍ਰਿਤੀ,
  x86_64_ਬਹੁਲਕ_integer,
  x86_64_ਬਹੁਲਕ_sse,
  x86_64_ਬਹੁਲਕ_x87
} X86_64_ਬਹੁਲਕ;

ਸਥਿਰ X86_64_ਬਹੁਲਕ classify_x86_64_ਮਿਲਾਓ(X86_64_ਬਹੁਲਕ a, X86_64_ਬਹੁਲਕ b)
{
    ਜੇ (a == b)
        ਵਾਪਸ a;
    ਨਹੀਂਤਾਂ ਜੇ (a == x86_64_ਬਹੁਲਕ_none)
        ਵਾਪਸ b;
    ਨਹੀਂਤਾਂ ਜੇ (b == x86_64_ਬਹੁਲਕ_none)
        ਵਾਪਸ a;
    ਨਹੀਂਤਾਂ ਜੇ ((a == x86_64_ਬਹੁਲਕ_ਸਮ੍ਰਿਤੀ) || (b == x86_64_ਬਹੁਲਕ_ਸਮ੍ਰਿਤੀ))
        ਵਾਪਸ x86_64_ਬਹੁਲਕ_ਸਮ੍ਰਿਤੀ;
    ਨਹੀਂਤਾਂ ਜੇ ((a == x86_64_ਬਹੁਲਕ_integer) || (b == x86_64_ਬਹੁਲਕ_integer))
        ਵਾਪਸ x86_64_ਬਹੁਲਕ_integer;
    ਨਹੀਂਤਾਂ ਜੇ ((a == x86_64_ਬਹੁਲਕ_x87) || (b == x86_64_ਬਹੁਲਕ_x87))
        ਵਾਪਸ x86_64_ਬਹੁਲਕ_ਸਮ੍ਰਿਤੀ;
    ਨਹੀਂਤਾਂ
        ਵਾਪਸ x86_64_ਬਹੁਲਕ_sse;
}

ਸਥਿਰ X86_64_ਬਹੁਲਕ classify_x86_64_inner(CType *ty)
{
    X86_64_ਬਹੁਲਕ ਬਹੁਲਕ;
    Sym *f;
    
    ਚੋਣ (ty->t & VT_BTYPE) {
    ਹਾਲਤ VT_VOID: ਵਾਪਸ x86_64_ਬਹੁਲਕ_none;
    
    ਹਾਲਤ VT_INT:
    ਹਾਲਤ VT_BYTE:
    ਹਾਲਤ VT_SHORT:
    ਹਾਲਤ VT_LLONG:
    ਹਾਲਤ VT_BOOL:
    ਹਾਲਤ VT_PTR:
    ਹਾਲਤ VT_FUNC:
        ਵਾਪਸ x86_64_ਬਹੁਲਕ_integer;
    
    ਹਾਲਤ VT_FLOAT:
    ਹਾਲਤ VT_DOUBLE: ਵਾਪਸ x86_64_ਬਹੁਲਕ_sse;
    
    ਹਾਲਤ VT_LDOUBLE: ਵਾਪਸ x86_64_ਬਹੁਲਕ_x87;
      
    ਹਾਲਤ VT_STRUCT:
        f = ty->ref;

        ਬਹੁਲਕ = x86_64_ਬਹੁਲਕ_none;
        ਲਈ (f = f->ਅਗਲਾ; f; f = f->ਅਗਲਾ)
            ਬਹੁਲਕ = classify_x86_64_ਮਿਲਾਓ(ਬਹੁਲਕ, classify_x86_64_inner(&f->type));
        
        ਵਾਪਸ ਬਹੁਲਕ;
    }
    ਪ੍ਰਤਿਜ੍ਞਾ(0);
    ਵਾਪਸ 0;
}

ਸਥਿਰ X86_64_ਬਹੁਲਕ classify_x86_64_arg(CType *ty, CType *ret, ਪੂਰਨ *psize, ਪੂਰਨ *palign, ਪੂਰਨ *reg_ਗਿਣਤੀ)
{
    X86_64_ਬਹੁਲਕ ਬਹੁਲਕ;
    ਪੂਰਨ ਮਾਪ, align, ret_t = 0;
    
    ਜੇ (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_ਗਿਣਤੀ = 1;
        ret_t = ty->t;
        ਬਹੁਲਕ = x86_64_ਬਹੁਲਕ_integer;
    } ਨਹੀਂਤਾਂ {
        ਮਾਪ = type_ਮਾਪ(ty, &align);
        *psize = (ਮਾਪ + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_ਗਿਣਤੀ = 0; /* avoid compiler warning */

        ਜੇ (ਮਾਪ > 16) {
            ਬਹੁਲਕ = x86_64_ਬਹੁਲਕ_ਸਮ੍ਰਿਤੀ;
        } ਨਹੀਂਤਾਂ {
            ਬਹੁਲਕ = classify_x86_64_inner(ty);
            ਚੋਣ (ਬਹੁਲਕ) {
            ਹਾਲਤ x86_64_ਬਹੁਲਕ_integer:
                ਜੇ (ਮਾਪ > 8) {
                    *reg_ਗਿਣਤੀ = 2;
                    ret_t = VT_QLONG;
                } ਨਹੀਂਤਾਂ {
                    *reg_ਗਿਣਤੀ = 1;
                    ਜੇ (ਮਾਪ > 4)
                        ret_t = VT_LLONG;
                    ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ > 2)
                        ret_t = VT_INT;
                    ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ > 1)
                        ret_t = VT_SHORT;
                    ਨਹੀਂਤਾਂ
                        ret_t = VT_BYTE;
                    ਜੇ ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                ਰੋਕੋ;
                
            ਹਾਲਤ x86_64_ਬਹੁਲਕ_x87:
                *reg_ਗਿਣਤੀ = 1;
                ret_t = VT_LDOUBLE;
                ਰੋਕੋ;

            ਹਾਲਤ x86_64_ਬਹੁਲਕ_sse:
                ਜੇ (ਮਾਪ > 8) {
                    *reg_ਗਿਣਤੀ = 2;
                    ret_t = VT_QFLOAT;
                } ਨਹੀਂਤਾਂ {
                    *reg_ਗਿਣਤੀ = 1;
                    ret_t = (ਮਾਪ > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                ਰੋਕੋ;
            ਮੂਲ: ਰੋਕੋ; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    ਜੇ (ret) {
        ret->ref = ਨਿਰਾ;
        ret->t = ret_t;
    }
    
    ਵਾਪਸ ਬਹੁਲਕ;
}

ST_FUNC ਪੂਰਨ classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    ਗਿਣਤੀ __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    ਪੂਰਨ ਮਾਪ, align, reg_ਗਿਣਤੀ;
    X86_64_ਬਹੁਲਕ ਬਹੁਲਕ = classify_x86_64_arg(ty, ਨਿਰਾ, &ਮਾਪ, &align, &reg_ਗਿਣਤੀ);
    ਚੋਣ (ਬਹੁਲਕ) {
    ਮੂਲ: ਵਾਪਸ __va_stack;
    ਹਾਲਤ x86_64_ਬਹੁਲਕ_integer: ਵਾਪਸ __va_gen_reg;
    ਹਾਲਤ x86_64_ਬਹੁਲਕ_sse: ਵਾਪਸ __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ਪੂਰਨ gfunc_sret(CType *vt, ਪੂਰਨ variadic, CType *ret, ਪੂਰਨ *ret_align, ਪੂਰਨ *regsize)
{
    ਪੂਰਨ ਮਾਪ, align, reg_ਗਿਣਤੀ;
    ਜੇ (classify_x86_64_arg(vt, ret, &ਮਾਪ, &align, &reg_ਗਿਣਤੀ) == x86_64_ਬਹੁਲਕ_ਸਮ੍ਰਿਤੀ)
        ਵਾਪਸ 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_ਗਿਣਤੀ; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    ਵਾਪਸ 1;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REGN 6
ਸਥਿਰ ਅਚਲ uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

ਸਥਿਰ ਪੂਰਨ arg_prepare_reg(ਪੂਰਨ idx) {
  ਜੇ (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      ਵਾਪਸ idx + 8;
  ਨਹੀਂਤਾਂ
      ਵਾਪਸ idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ਖਾਲੀ gfunc_call(ਪੂਰਨ nb_ਦਲੀਲਾਂ)
{
    X86_64_ਬਹੁਲਕ ਬਹੁਲਕ;
    CType type;
    ਪੂਰਨ ਮਾਪ, align, r, ਦਲੀਲਾਂ_ਮਾਪ, ਢੇਰ_adjust, i, reg_ਗਿਣਤੀ, k;
    ਪੂਰਨ nb_reg_ਦਲੀਲਾਂ = 0;
    ਪੂਰਨ nb_sse_ਦਲੀਲਾਂ = 0;
    ਪੂਰਨ sse_reg, gen_reg;
    ਅੱਖਰ *onstack = tcc_malloc((nb_ਦਲੀਲਾਂ + 1) * ਆਕਾਰ (ਅੱਖਰ));

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gbound_ਦਲੀਲਾਂ(nb_ਦਲੀਲਾਂ);
#ਜੇ_ਅੰਤ

    save_regs(nb_ਦਲੀਲਾਂ);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    ਢੇਰ_adjust = 0;
    ਲਈ(i = nb_ਦਲੀਲਾਂ - 1; i >= 0; i--) {
        ਬਹੁਲਕ = classify_x86_64_arg(&vtop[-i].type, ਨਿਰਾ, &ਮਾਪ, &align, &reg_ਗਿਣਤੀ);
        ਜੇ (ਮਾਪ == 0) ਜਾਰੀ;
        ਜੇ (ਬਹੁਲਕ == x86_64_ਬਹੁਲਕ_sse && nb_sse_ਦਲੀਲਾਂ + reg_ਗਿਣਤੀ <= 8) {
            nb_sse_ਦਲੀਲਾਂ += reg_ਗਿਣਤੀ;
	    onstack[i] = 0;
	} ਨਹੀਂਤਾਂ ਜੇ (ਬਹੁਲਕ == x86_64_ਬਹੁਲਕ_integer && nb_reg_ਦਲੀਲਾਂ + reg_ਗਿਣਤੀ <= REGN) {
            nb_reg_ਦਲੀਲਾਂ += reg_ਗਿਣਤੀ;
	    onstack[i] = 0;
	} ਨਹੀਂਤਾਂ ਜੇ (ਬਹੁਲਕ == x86_64_ਬਹੁਲਕ_none) {
	    onstack[i] = 0;
	} ਨਹੀਂਤਾਂ {
	    ਜੇ (align == 16 && (ਢੇਰ_adjust &= 15)) {
		onstack[i] = 2;
		ਢੇਰ_adjust = 0;
	    } ਨਹੀਂਤਾਂ
	      onstack[i] = 1;
	    ਢੇਰ_adjust += ਮਾਪ;
	}
    }

    ਜੇ (nb_sse_ਦਲੀਲਾਂ && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_ਦਲੀਲਾਂ;
    sse_reg = nb_sse_ਦਲੀਲਾਂ;
    ਦਲੀਲਾਂ_ਮਾਪ = 0;
    ਢੇਰ_adjust &= 15;
    ਲਈ (i = k = 0; i < nb_ਦਲੀਲਾਂ;) {
	ਬਹੁਲਕ = classify_x86_64_arg(&vtop[-i].type, ਨਿਰਾ, &ਮਾਪ, &align, &reg_ਗਿਣਤੀ);
	ਜੇ (ਮਾਪ) {
            ਜੇ (!onstack[i + k]) {
	        ++i;
	        ਜਾਰੀ;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            ਜੇ (ਢੇਰ_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                ਦਲੀਲਾਂ_ਮਾਪ += 8;
	        ਢੇਰ_adjust = 0;
            }
	    ਜੇ (onstack[i + k] == 2)
	        ਢੇਰ_adjust = 1;
        }

	vrotb(i+1);

	ਚੋਣ (vtop->type.t & VT_BTYPE) {
	    ਹਾਲਤ VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, ਮਾਪ); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_ਮੁੱਲ(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_ਮੁੱਲ(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		ਰੋਕੋ;

	    ਹਾਲਤ VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, ਮਾਪ); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		ਰੋਕੋ;

	    ਹਾਲਤ VT_FLOAT:
	    ਹਾਲਤ VT_DOUBLE:
		ਪ੍ਰਤਿਜ੍ਞਾ(ਬਹੁਲਕ == x86_64_ਬਹੁਲਕ_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_ਮੁੱਲ(r)*8);
		o(0x24);
		ਰੋਕੋ;

	    ਮੂਲ:
		ਪ੍ਰਤਿਜ੍ਞਾ(ਬਹੁਲਕ == x86_64_ਬਹੁਲਕ_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_ਮੁੱਲ(r)); /* push r */
		ਰੋਕੋ;
	}
	ਦਲੀਲਾਂ_ਮਾਪ += ਮਾਪ;

	vpop();
	--nb_ਦਲੀਲਾਂ;
	k++;
    }

    tcc_free(onstack);

    /* then, we prepare register passing arguments.
       Note that we cannot set RDX and RCX in this loop because gv()
       may break these temporary registers. Let's use R10 and R11
       instead of them */
    ਪ੍ਰਤਿਜ੍ਞਾ(gen_reg <= REGN);
    ਪ੍ਰਤਿਜ੍ਞਾ(sse_reg <= 8);
    ਲਈ(i = 0; i < nb_ਦਲੀਲਾਂ; i++) {
        ਬਹੁਲਕ = classify_x86_64_arg(&vtop->type, &type, &ਮਾਪ, &align, &reg_ਗਿਣਤੀ);
        ਜੇ (ਮਾਪ == 0) ਜਾਰੀ;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        ਜੇ (ਬਹੁਲਕ == x86_64_ਬਹੁਲਕ_sse) {
            ਜੇ (reg_ਗਿਣਤੀ == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                ਜੇ (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } ਨਹੀਂਤਾਂ {
                ਪ੍ਰਤਿਜ੍ਞਾ(reg_ਗਿਣਤੀ == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } ਨਹੀਂਤਾਂ ਜੇ (ਬਹੁਲਕ == x86_64_ਬਹੁਲਕ_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            ਪੂਰਨ d;
            gen_reg -= reg_ਗਿਣਤੀ;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_ਮੁੱਲ(r) * 8 + REG_ਮੁੱਲ(d));
            ਜੇ (reg_ਗਿਣਤੀ == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_ਮੁੱਲ(vtop->r2) * 8 + REG_ਮੁੱਲ(d));
            }
        }
        vtop--;
    }
    ਪ੍ਰਤਿਜ੍ਞਾ(gen_reg == 0);
    ਪ੍ਰਤਿਜ੍ਞਾ(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    ਜੇ (nb_reg_ਦਲੀਲਾਂ > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        ਜੇ (nb_reg_ਦਲੀਲਾਂ > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    ਜੇ (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_ਦਲੀਲਾਂ < 8 ? nb_sse_ਦਲੀਲਾਂ : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    ਜੇ (ਦਲੀਲਾਂ_ਮਾਪ)
        gadd_sp(ਦਲੀਲਾਂ_ਮਾਪ);
    vtop--;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_PROLOG_ਮਾਪ 11

ਸਥਿਰ ਖਾਲੀ ਧੱਕੋ_arg_reg(ਪੂਰਨ i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, ਨਿਰਾ, loc);
}

/* generate function prolog of type 't' */
ਖਾਲੀ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_ਬਹੁਲਕ ਬਹੁਲਕ, ret_ਬਹੁਲਕ;
    ਪੂਰਨ i, addr, align, ਮਾਪ, reg_ਗਿਣਤੀ;
    ਪੂਰਨ param_addr = 0, reg_param_ਸੂਚਕਾਂਕ, sse_param_ਸੂਚਕਾਂਕ;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_ਮਾਪ * 2;
    loc = 0;
    ind += FUNC_PROLOG_ਮਾਪ;
    func_sub_sp_ਵਿੱਥ = ind;
    func_ret_sub = 0;
    ret_ਬਹੁਲਕ = classify_x86_64_arg(&func_vt, ਨਿਰਾ, &ਮਾਪ, &align, &reg_ਗਿਣਤੀ);

    ਜੇ (func_var) {
        ਪੂਰਨ ਵੇਖਿਆ_reg_ਅੰਕ, ਵੇਖਿਆ_sse_ਅੰਕ, ਵੇਖਿਆ_ਢੇਰ_ਮਾਪ;
        ਵੇਖਿਆ_reg_ਅੰਕ = ret_ਬਹੁਲਕ == x86_64_ਬਹੁਲਕ_ਸਮ੍ਰਿਤੀ;
        ਵੇਖਿਆ_sse_ਅੰਕ = 0;
        /* frame pointer and return address */
        ਵੇਖਿਆ_ਢੇਰ_ਮਾਪ = PTR_ਮਾਪ * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        ਜਦੋਂ ((sym = sym->ਅਗਲਾ) != ਨਿਰਾ) {
            type = &sym->type;
            ਬਹੁਲਕ = classify_x86_64_arg(type, ਨਿਰਾ, &ਮਾਪ, &align, &reg_ਗਿਣਤੀ);
            ਚੋਣ (ਬਹੁਲਕ) {
            ਮੂਲ:
            ਢੇਰ_arg:
                ਵੇਖਿਆ_ਢੇਰ_ਮਾਪ = ((ਵੇਖਿਆ_ਢੇਰ_ਮਾਪ + align - 1) & -align) + ਮਾਪ;
                ਰੋਕੋ;
                
            ਹਾਲਤ x86_64_ਬਹੁਲਕ_integer:
                ਜੇ (ਵੇਖਿਆ_reg_ਅੰਕ + reg_ਗਿਣਤੀ > REGN)
		    ਜਾਓ ਢੇਰ_arg;
		ਵੇਖਿਆ_reg_ਅੰਕ += reg_ਗਿਣਤੀ;
                ਰੋਕੋ;
                
            ਹਾਲਤ x86_64_ਬਹੁਲਕ_sse:
                ਜੇ (ਵੇਖਿਆ_sse_ਅੰਕ + reg_ਗਿਣਤੀ > 8)
		    ਜਾਓ ਢੇਰ_arg;
		ਵੇਖਿਆ_sse_ਅੰਕ += reg_ਗਿਣਤੀ;
                ਰੋਕੋ;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(ਵੇਖਿਆ_reg_ਅੰਕ * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(ਵੇਖਿਆ_sse_ਅੰਕ * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(ਵੇਖਿਆ_ਢੇਰ_ਮਾਪ);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        ਲਈ (i = 0; i < 8; i++) {
            loc -= 16;
	    ਜੇ (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, ਨਿਰਾ, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        ਲਈ (i = 0; i < REGN; i++) {
            ਧੱਕੋ_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_ਸੂਚਕਾਂਕ = 0;
    sse_param_ਸੂਚਕਾਂਕ = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    ਜੇ (ret_ਬਹੁਲਕ == x86_64_ਬਹੁਲਕ_ਸਮ੍ਰਿਤੀ) {
        ਧੱਕੋ_arg_reg(reg_param_ਸੂਚਕਾਂਕ);
        func_vc = loc;
        reg_param_ਸੂਚਕਾਂਕ++;
    }
    /* define parameters */
    ਜਦੋਂ ((sym = sym->ਅਗਲਾ) != ਨਿਰਾ) {
        type = &sym->type;
        ਬਹੁਲਕ = classify_x86_64_arg(type, ਨਿਰਾ, &ਮਾਪ, &align, &reg_ਗਿਣਤੀ);
        ਚੋਣ (ਬਹੁਲਕ) {
        ਹਾਲਤ x86_64_ਬਹੁਲਕ_sse:
	    ਜੇ (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            ਜੇ (sse_param_ਸੂਚਕਾਂਕ + reg_ਗਿਣਤੀ <= 8) {
                /* save arguments passed by register */
                loc -= reg_ਗਿਣਤੀ * 8;
                param_addr = loc;
                ਲਈ (i = 0; i < reg_ਗਿਣਤੀ; ++i) {
                    gen_modrm32(0xd60f66, sse_param_ਸੂਚਕਾਂਕ, VT_LOCAL, ਨਿਰਾ, param_addr + i*8);
                    ++sse_param_ਸੂਚਕਾਂਕ;
                }
            } ਨਹੀਂਤਾਂ {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += ਮਾਪ;
            }
            ਰੋਕੋ;
            
        ਹਾਲਤ x86_64_ਬਹੁਲਕ_ਸਮ੍ਰਿਤੀ:
        ਹਾਲਤ x86_64_ਬਹੁਲਕ_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += ਮਾਪ;
            ਰੋਕੋ;
            
        ਹਾਲਤ x86_64_ਬਹੁਲਕ_integer: {
            ਜੇ (reg_param_ਸੂਚਕਾਂਕ + reg_ਗਿਣਤੀ <= REGN) {
                /* save arguments passed by register */
                loc -= reg_ਗਿਣਤੀ * 8;
                param_addr = loc;
                ਲਈ (i = 0; i < reg_ਗਿਣਤੀ; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_ਸੂਚਕਾਂਕ], VT_LOCAL, ਨਿਰਾ, param_addr + i*8);
                    ++reg_param_ਸੂਚਕਾਂਕ;
                }
            } ਨਹੀਂਤਾਂ {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += ਮਾਪ;
            }
            ਰੋਕੋ;
        }
	ਮੂਲ: ਰੋਕੋ; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_ਸੈੱਟ_param(sym, param_addr, 0);
    }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#ਜੇ_ਅੰਤ
}

/* generate function epilog */
ਖਾਲੀ gfunc_epilog(ਖਾਲੀ)
{
    ਪੂਰਨ v, saved_ind;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#ਜੇ_ਅੰਤ
    o(0xc9); /* leave */
    ਜੇ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ਨਹੀਂਤਾਂ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    /* align local size to word & save local variables */
    v = (-loc + 15) & -16;
    saved_ind = ind;
    ind = func_sub_sp_ਵਿੱਥ - FUNC_PROLOG_ਮਾਪ;
    o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
    o(0xec8148);  /* sub rsp, stacksize */
    gen_le32(v);
    ind = saved_ind;
}

#ਜੇ_ਅੰਤ /* not PE */

ST_FUNC ਖਾਲੀ gen_fill_nops(ਪੂਰਨ ਬਾਈਟਾਂ)
{
    ਜਦੋਂ (ਬਾਈਟਾਂ--)
      g(0x90);
}

/* generate a jump to a label */
ਪੂਰਨ gjmp(ਪੂਰਨ t)
{
    ਵਾਪਸ gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ਖਾਲੀ gjmp_addr(ਪੂਰਨ a)
{
    ਪੂਰਨ r;
    r = a - ind - 2;
    ਜੇ (r == (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)r) {
        g(0xeb);
        g(r);
    } ਨਹੀਂਤਾਂ {
        oad(0xe9, a - ind - 5);
    }
}

ST_FUNC ਪੂਰਨ gjmp_append(ਪੂਰਨ n, ਪੂਰਨ t)
{
    ਖਾਲੀ *p;
    /* insert vtop->c jump list in t */
    ਜੇ (n) {
        uint32_t n1 = n, n2;
        ਜਦੋਂ ((n2 = read32le(p = cur_ਪਾਠ_section->ਅੰਕੜੇ + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    ਵਾਪਸ t;
}

ST_FUNC ਪੂਰਨ gjmp_cond(ਪੂਰਨ op, ਪੂਰਨ t)
{
        ਜੇ (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            ਪੂਰਨ v = vtop->cmp_r;
            op &= ~0x100;
            ਜੇ (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    ਨਹੀਂਤਾਂ
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        ਵਾਪਸ t;
}

/* generate an integer binary operation */
ਖਾਲੀ gen_opi(ਪੂਰਨ op)
{
    ਪੂਰਨ r, fr, opc, c;
    ਪੂਰਨ ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    ਚੋਣ(op) {
    ਹਾਲਤ '+':
    ਹਾਲਤ TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        ਜੇ (cc && (!ll || (ਪੂਰਨ)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            ਜੇ (c == (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_ਮੁੱਲ(r));
                g(c);
            } ਨਹੀਂਤਾਂ {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_ਮੁੱਲ(r), c);
            }
        } ਨਹੀਂਤਾਂ {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_ਮੁੱਲ(r) + REG_ਮੁੱਲ(fr) * 8);
        }
        vtop--;
        ਜੇ (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        ਰੋਕੋ;
    ਹਾਲਤ '-':
    ਹਾਲਤ TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        ਜਾਓ gen_op8;
    ਹਾਲਤ TOK_ADDC2: /* add with carry use */
        opc = 2;
        ਜਾਓ gen_op8;
    ਹਾਲਤ TOK_SUBC2: /* sub with carry use */
        opc = 3;
        ਜਾਓ gen_op8;
    ਹਾਲਤ '&':
        opc = 4;
        ਜਾਓ gen_op8;
    ਹਾਲਤ '^':
        opc = 6;
        ਜਾਓ gen_op8;
    ਹਾਲਤ '|':
        opc = 1;
        ਜਾਓ gen_op8;
    ਹਾਲਤ '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_ਮੁੱਲ(fr) + REG_ਮੁੱਲ(r) * 8);
        vtop--;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_SHL:
        opc = 4;
        ਜਾਓ gen_ਖਿਸਕਾਓ;
    ਹਾਲਤ TOK_SHR:
        opc = 5;
        ਜਾਓ gen_ਖਿਸਕਾਓ;
    ਹਾਲਤ TOK_SAR:
        opc = 7;
    gen_ਖਿਸਕਾਓ:
        opc = 0xc0 | (opc << 3);
        ਜੇ (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_ਮੁੱਲ(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } ਨਹੀਂਤਾਂ {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_ਮੁੱਲ(r));
        }
        vtop--;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_UDIV:
    ਹਾਲਤ TOK_UMOD:
        uu = 1;
        ਜਾਓ divmod;
    ਹਾਲਤ '/':
    ਹਾਲਤ '%':
    ਹਾਲਤ TOK_PDIV:
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
        o((uu ? 0xf0 : 0xf8) + REG_ਮੁੱਲ(fr));
        ਜੇ (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        ਨਹੀਂਤਾਂ
            r = TREG_RAX;
        vtop->r = r;
        ਰੋਕੋ;
    ਮੂਲ:
        opc = 7;
        ਜਾਓ gen_op8;
    }
}

ਖਾਲੀ gen_opl(ਪੂਰਨ op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ਖਾਲੀ gen_opf(ਪੂਰਨ op)
{
    ਪੂਰਨ a, ft, fc, swapped, r, opc;
    ਪੂਰਨ bt = vtop->type.t & VT_BTYPE;
    ਪੂਰਨ float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    ਜੇ (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        ਜੇ (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } ਨਹੀਂਤਾਂ {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, ਨਿਰਾ, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        ਵਾਪਸ;
    }

    /* convert constants to memory references */
    ਜੇ ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    ਜੇ ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    ਜੇ ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    ਜੇ (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    ਜੇ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        ਜੇ (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            ਲੱਦੋ(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            ਜੇ (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            ਨਹੀਂਤਾਂ ਜੇ (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            ਜੇ (swapped)
                o(0xc9d9); /* fxch %st(1) */
            ਜੇ (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            ਨਹੀਂਤਾਂ
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            ਜੇ (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } ਨਹੀਂਤਾਂ ਜੇ (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } ਨਹੀਂਤਾਂ ਜੇ (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } ਨਹੀਂਤਾਂ {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } ਨਹੀਂਤਾਂ {
            /* no memory reference possible for long double operations */
            ਲੱਦੋ(TREG_ST0, vtop);
            swapped = !swapped;

            ਚੋਣ(op) {
            ਮੂਲ:
            ਹਾਲਤ '+':
                a = 0;
                ਰੋਕੋ;
            ਹਾਲਤ '-':
                a = 4;
                ਜੇ (swapped)
                    a++;
                ਰੋਕੋ;
            ਹਾਲਤ '*':
                a = 1;
                ਰੋਕੋ;
            ਹਾਲਤ '/':
                a = 6;
                ਜੇ (swapped)
                    a++;
                ਰੋਕੋ;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } ਨਹੀਂਤਾਂ {
        ਜੇ (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            ਜੇ ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = ਨਿਰਾ;
                ਲੱਦੋ(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            ਜੇ (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } ਨਹੀਂਤਾਂ {
                ਜੇ (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                ਜੇ (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } ਨਹੀਂਤਾਂ {
                    op = 0x97; /* seta */
                }
            }

            ਜੇ (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            ਪ੍ਰਤਿਜ੍ਞਾ(!(vtop[-1].r & VT_LVAL));
            
            ਜੇ (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            ਨਹੀਂਤਾਂ
                opc = 0x2f0f; /* comisd */
            ਜੇ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } ਨਹੀਂਤਾਂ {
            ਪ੍ਰਤਿਜ੍ਞਾ((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            ਚੋਣ(op) {
            ਮੂਲ:
            ਹਾਲਤ '+':
                a = 0;
                ਰੋਕੋ;
            ਹਾਲਤ '-':
                a = 4;
                ਰੋਕੋ;
            ਹਾਲਤ '*':
                a = 1;
                ਰੋਕੋ;
            ਹਾਲਤ '/':
                a = 6;
                ਰੋਕੋ;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            ਪ੍ਰਤਿਜ੍ਞਾ((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            ਜੇ ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = ਨਿਰਾ;
                ਲੱਦੋ(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            ਪ੍ਰਤਿਜ੍ਞਾ(!(vtop[-1].r & VT_LVAL));
            ਜੇ (swapped) {
                ਪ੍ਰਤਿਜ੍ਞਾ(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            ਜੇ ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } ਨਹੀਂਤਾਂ {
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
ਖਾਲੀ gen_cvt_itof(ਪੂਰਨ t)
{
    ਜੇ ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        ਜੇ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } ਨਹੀਂਤਾਂ ਜੇ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } ਨਹੀਂਤਾਂ {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } ਨਹੀਂਤਾਂ {
        ਪੂਰਨ r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        ਜੇ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_ਮੁੱਲ(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
ਖਾਲੀ gen_cvt_ftof(ਪੂਰਨ t)
{
    ਪੂਰਨ ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    ਜੇ (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        ਜੇ (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_ਮੁੱਲ(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_ਮੁੱਲ(vtop->r)*9);
        } ਨਹੀਂਤਾਂ ਜੇ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_ਮੁੱਲ(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        ਜੇ (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_ਮੁੱਲ(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_ਮੁੱਲ(vtop->r)*9);
        } ਨਹੀਂਤਾਂ ਜੇ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_ਮੁੱਲ(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } ਨਹੀਂਤਾਂ {
        ਪੂਰਨ r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        ਜੇ (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_ਮੁੱਲ(r)*8);
            o(0xf024);
            vtop->r = r;
        } ਨਹੀਂਤਾਂ ਜੇ (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_ਮੁੱਲ(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
ਖਾਲੀ gen_cvt_ftoi(ਪੂਰਨ t)
{
    ਪੂਰਨ ft, bt, ਮਾਪ, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    ਜੇ (bt == VT_LDOUBLE) {
	ਜੇ (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    ਵਾਪਸ;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    ਜੇ (t != VT_INT)
        ਮਾਪ = 8;
    ਨਹੀਂਤਾਂ
        ਮਾਪ = 4;

    r = get_reg(RC_INT);
    ਜੇ (bt == VT_FLOAT) {
        o(0xf3);
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_DOUBLE) {
        o(0xf2);
    } ਨਹੀਂਤਾਂ {
        ਪ੍ਰਤਿਜ੍ਞਾ(0);
    }
    orex(ਮਾਪ == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_ਮੁੱਲ(vtop->r) + REG_ਮੁੱਲ(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC ਖਾਲੀ gen_cvt_sxtw(ਖਾਲੀ)
{
    ਪੂਰਨ r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_ਮੁੱਲ(r) << 3) + REG_ਮੁੱਲ(r));
}

/* char/short to int conversion */
ST_FUNC ਖਾਲੀ gen_cvt_csti(ਪੂਰਨ t)
{
    ਪੂਰਨ r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_ਮੁੱਲ(r) << 3 | REG_ਮੁੱਲ(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC ਖਾਲੀ gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_ਪਾਠ_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC ਖਾਲੀ ggoto(ਖਾਲੀ)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC ਖਾਲੀ gen_vla_sp_save(ਪੂਰਨ addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, ਨਿਰਾ, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC ਖਾਲੀ gen_vla_sp_restore(ਪੂਰਨ addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, ਨਿਰਾ, addr);
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC ਖਾਲੀ gen_vla_ਨਤੀਜਾ(ਪੂਰਨ addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, ਨਿਰਾ, addr);
}
#ਜੇ_ਅੰਤ

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC ਖਾਲੀ gen_vla_alloc(CType *type, ਪੂਰਨ align) {
    ਪੂਰਨ use_call = 0;

#ਜੇ defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#ਜੇ_ਅੰਤ
    ਜੇ (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    ਨਹੀਂਤਾਂ {
        ਪੂਰਨ r;
        r = gv(RC_INT); /* allocation size */
        /* sub r,%rsp */
        o(0x2b48);
        o(0xe0 | REG_ਮੁੱਲ(r));
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
ST_FUNC ਖਾਲੀ gen_struct_copy(ਪੂਰਨ ਮਾਪ)
{
    ਪੂਰਨ n = ਮਾਪ / PTR_ਮਾਪ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    o(0x5756); /* push rsi, rdi */
#ਜੇ_ਅੰਤ
    gv2(RC_RDI, RC_RSI);
    ਜੇ (n <= 4) {
        ਜਦੋਂ (n)
            o(0xa548), --n;
    } ਨਹੀਂਤਾਂ {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    ਜੇ (ਮਾਪ & 0x04)
        o(0xa5);
    ਜੇ (ਮਾਪ & 0x02)
        o(0xa566);
    ਜੇ (ਮਾਪ & 0x01)
        o(0xa4);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    o(0x5e5f); /* pop rdi, rsi */
#ਜੇ_ਅੰਤ
    vpop();
    vpop();
}

/* end of x86-64 code generator */
/*************************************************************/
#ਜੇ_ਅੰਤ /* ! TARGET_DEFS_ONLY */
/******************************************************/
