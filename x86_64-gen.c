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
ଗଣନା {
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
#define REG_ମୂଲ୍ୟ(reg) ((reg) & 7)

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
ST_FUNC ଶୂନ୍ୟ gen_struct_copy(ପୂର୍ଣ୍ଣସଂଖ୍ୟା size);

/******************************************************/
#ଅନ୍ୟଥା /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#ଅନ୍ତର୍ଭାଵ "tcc.h"
#ଅନ୍ତର୍ଭାଵ <assert.h>

ST_DATA ଅଚଳ ଅକ୍ଷର * ଅଚଳ target_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_DATA ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା reg_classes[NB_REGS] = {
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

ସ୍ଥିର unsigned long func_sub_sp_offset;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_ret_sub;

#ଯଦି defined(CONFIG_TCC_BCHECK)
ସ୍ଥିର addr_t func_bound_offset;
ସ୍ଥିର unsigned long func_bound_ind;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_bound_add_epilog;
#endif

#ifdef TCC_TARGET_PE
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_scratch, func_alloca;
#endif

/* XXX: make it faster ? */
ST_FUNC ଶୂନ୍ୟ g(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ind1;
    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ;
    ind1 = ind + 1;
    ଯଦି (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC ଶୂନ୍ୟ o(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଯେତେବେଳେ (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC ଶୂନ୍ୟ gen_le16(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC ଶୂନ୍ୟ gen_le32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

ST_FUNC ଶୂନ୍ୟ gen_le64(int64_t c)
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

ସ୍ଥିର ଶୂନ୍ୟ orex(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ll, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r2, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
    ଯଦି ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    ଯଦି ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    ଯଦି (ll || REX_BASE(r) || REX_BASE(r2)) {
        ଯଦି ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_BASE(r) | (REX_BASE(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC ଶୂନ୍ୟ gsym_addr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
    ଯେତେବେଳେ (t) {
        unsigned ଅକ୍ଷର *ptr = cur_text_section->data + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା is64_type(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଫେରନ୍ତୁ ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା oad(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;
    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ s;
    o(c);
    t = ind;
    gen_le32(s);
    ଫେରନ୍ତୁ t;
}

/* generate jmp to a label */
#define gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC ଶୂନ୍ୟ gen_addr32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଯଦି (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ଶୂନ୍ୟ gen_addrpc32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଯଦି (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
ସ୍ଥିର ଶୂନ୍ୟ gen_gotpcrel(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
#ifdef TCC_TARGET_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, ଖାଲି), c, r,
        cur_text_section->data[ind-3],
        cur_text_section->data[ind-2],
        cur_text_section->data[ind-1]
        );
#endif
    greloca(cur_text_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    ଯଦି (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_ମୂଲ୍ୟ(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
ସ୍ଥିର ଶୂନ୍ୟ gen_modrm_impl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା opcode, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ll, ପୂର୍ଣ୍ଣସଂଖ୍ୟା op_reg_0, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op_reg = REG_ମୂଲ୍ୟ(op_reg_0) << 3;

    ଯଦି ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_SIZE); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#ଅନ୍ୟଥା
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#endif
        ଫେରନ୍ତୁ;
    }

    orex(ll, r, op_reg_0, opcode);

    ଯଦି ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	ଯଦି (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} ଅନ୍ୟଥା {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    ଯଦି (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } ଅନ୍ୟଥା {
		gen_addrpc32(r, sym, c);
	    }
	}
    } ଅନ୍ୟଥା ଯଦି ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        ଯଦି (c == (signed ଅକ୍ଷର)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } ଅନ୍ୟଥା {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } ଅନ୍ୟଥା ଯଦି ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_ମୂଲ୍ୟ(r));
        gen_le32(c);
    } ଅନ୍ୟଥା ଯଦି (r & VT_LVAL) {
        g(0x00 | op_reg | REG_ମୂଲ୍ୟ(r));
    } ଅନ୍ୟଥା {
        g(0xc0 | op_reg | REG_ମୂଲ୍ୟ(r));
    }
}

ସ୍ଥିର ଶୂନ୍ୟ gen_modrm64(ପୂର୍ଣ୍ଣସଂଖ୍ୟା opcode, ପୂର୍ଣ୍ଣସଂଖ୍ୟା op_reg, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

ସ୍ଥିର ଶୂନ୍ୟ gen_modrm32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା opcode, ପୂର୍ଣ୍ଣସଂଖ୍ୟା op_reg, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
ଶୂନ୍ୟ load(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, SValue *sv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    ଯଦି (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#ifndef TCC_TARGET_PE
    /* we use indirect access via got */
    ଯଦି ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା tr = r | TREG_MEM;
        ଯଦି (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#endif

    v = fr & VT_VALMASK;
    ଯଦି (fr & VT_LVAL) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, ll;
        ଯଦି (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = ଖାଲି;
            fr = r;
            ଯଦି (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            load(fr, &v1);
            fr |= VT_LVAL;
        }
	ଯଦି (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = ଖାଲି;
	    fr = r;
	    ଯଦି (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    load(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	ଯଦି ((ft & VT_BTYPE) == VT_STRUCT) {
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା align;
	    ବାଛ (type_size(&sv->type, &align)) {
		ସ୍ଥିତି 1: ft = VT_BYTE; ଭାଙ୍ଗ;
		ସ୍ଥିତି 2: ft = VT_SHORT; ଭାଙ୍ଗ;
		ସ୍ଥିତି 4: ft = VT_INT; ଭାଙ୍ଗ;
		ସ୍ଥିତି 8: ft = VT_LLONG; ଭାଙ୍ଗ;
		ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
		    tcc_error("invalid aggregate type for register load");
		    ଭାଙ୍ଗ;
	    }
	}
        ଯଦି ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_ମୂଲ୍ୟ(r); /* movd */
        } ଅନ୍ୟଥା ଯଦି ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_ମୂଲ୍ୟ(r);
        } ଅନ୍ୟଥା ଯଦି ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } ଅନ୍ୟଥା ଯଦି ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } ଅନ୍ୟଥା ଯଦି ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } ଅନ୍ୟଥା ଯଦି ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } ଅନ୍ୟଥା ଯଦି ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } ଅନ୍ୟଥା ଯଦି ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            ଫେରନ୍ତୁ;
        } ଅନ୍ୟଥା {
            ପ୍ରତିଜ୍ଞା(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } ଅନ୍ୟଥା {
        ଯଦି (v == VT_CONST) {
            ଯଦି (fr & VT_SYM) {
#ifdef TCC_TARGET_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#ଅନ୍ୟଥା
                ଯଦି (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, ଖାଲି, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_ମୂଲ୍ୟ(r), 0);
                    greloca(cur_text_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } ଅନ୍ୟଥା ଯଦି (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_ମୂଲ୍ୟ(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } ଅନ୍ୟଥା {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_ମୂଲ୍ୟ(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#endif
            } ଅନ୍ୟଥା ଯଦି (is64_type(ft)) {
                ଯଦି (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_ମୂଲ୍ୟ(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } ଅନ୍ୟଥା ଯଦି (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_ମୂଲ୍ୟ(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } ଅନ୍ୟଥା {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_ମୂଲ୍ୟ(r) * 9);
                }
            } ଅନ୍ୟଥା {
                orex(0,r,0, 0xb8 + REG_ମୂଲ୍ୟ(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } ଅନ୍ୟଥା ଯଦି (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } ଅନ୍ୟଥା ଯଦି (v == VT_CMP) {
	    ଯଦି (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_ମୂଲ୍ୟ(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_BASE(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_ମୂଲ୍ୟ(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_ମୂଲ୍ୟ(r) * 0x900); /* movzbl %al, %eax */
        } ଅନ୍ୟଥା ଯଦି (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_ମୂଲ୍ୟ(r), t); /* mov $1, r */
            o(0x05eb + (REX_BASE(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_ମୂଲ୍ୟ(r), t ^ 1); /* mov $0, r */
        } ଅନ୍ୟଥା ଯଦି (v != r) {
            ଯଦି ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                ଯଦି (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_ମୂଲ୍ୟ(r)*8); /* %xmmN */
                    o(0xf024);
                } ଅନ୍ୟଥା {
                    ପ୍ରତିଜ୍ଞା((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    ଯଦି ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } ଅନ୍ୟଥା {
                        ପ୍ରତିଜ୍ଞା((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_ମୂଲ୍ୟ(v) + REG_ମୂଲ୍ୟ(r)*8);
                }
            } ଅନ୍ୟଥା ଯଦି (r == TREG_ST0) {
                ପ୍ରତିଜ୍ଞା((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_ମୂଲ୍ୟ(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } ଅନ୍ୟଥା {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_ମୂଲ୍ୟ(r) + REG_ମୂଲ୍ୟ(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
ଶୂନ୍ୟ store(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, SValue *v)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    ଯଦି (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#ifndef TCC_TARGET_PE
    /* we need to access the variable via got */
    ଯଦି ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#endif

    /* XXX: incorrect if float reg to reg */
    ଯଦି (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_ମୂଲ୍ୟ(r);
    } ଅନ୍ୟଥା ଯଦି (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_ମୂଲ୍ୟ(r);
    } ଅନ୍ୟଥା ଯଦି (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } ଅନ୍ୟଥା ଯଦି (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } ଅନ୍ୟଥା {
        opc = 0x89;
        ଯଦି (bt == VT_SHORT)
            opc = 0x8966;
        ଅନ୍ୟଥା ଯଦି (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
ସ୍ଥିର ଶୂନ୍ୟ gcall_or_jmp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_jmp)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
    ଯଦି ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind + 1, R_X86_64_PLT32, (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } ଅନ୍ୟଥା {
        /* otherwise, indirect call */
        r = TREG_R11;
        load(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_ମୂଲ୍ୟ(r) + (is_jmp << 4));
    }
}

#ଯଦି defined(CONFIG_TCC_BCHECK)

ସ୍ଥିର ଶୂନ୍ୟ gen_bounds_call(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#ifdef TCC_TARGET_PE
# define TREG_FASTCALL_1 TREG_RCX
#ଅନ୍ୟଥା
# define TREG_FASTCALL_1 TREG_RDI
#endif

ସ୍ଥିର ଶୂନ୍ୟ gen_bounds_prolog(ଶୂନ୍ୟ)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->data_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
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
ସ୍ଥିର ଅଚଳ uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arg_prepare_reg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା idx) {
  ଯଦି (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      ଫେରନ୍ତୁ idx + 10;
  ଅନ୍ୟଥା
      ଫେରନ୍ତୁ idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

ସ୍ଥିର ଶୂନ୍ୟ gen_offs_sp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    ଯଦି (d == (signed ଅକ୍ଷର)d) {
        o(0x2444 | (REG_ମୂଲ୍ୟ(r) << 3));
        g(d);
    } ଅନ୍ୟଥା {
        o(0x2484 | (REG_ମୂଲ୍ୟ(r) << 3));
        gen_le32(d);
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା using_regs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା size)
{
    ଫେରନ୍ତୁ !(size > 8 || (size & (size - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gfunc_sret(CType *vt, ପୂର୍ଣ୍ଣସଂଖ୍ୟା variadic, CType *ret, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ret_align, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *regsize)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    size = type_size(vt, &align);
    ଯଦି (!using_regs(size))
        ଫେରନ୍ତୁ 0;
    ଯଦି (size == 8)
        ret->t = VT_LLONG;
    ଅନ୍ୟଥା ଯଦି (size == 4)
        ret->t = VT_INT;
    ଅନ୍ୟଥା ଯଦି (size == 2)
        ret->t = VT_SHORT;
    ଅନ୍ୟଥା
        ret->t = VT_BYTE;
    ret->ref = ଖାଲି;
    ଫେରନ୍ତୁ 1;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_sse_float(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t) {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt;
    bt = t & VT_BTYPE;
    ଫେରନ୍ତୁ bt == VT_DOUBLE || bt == VT_FLOAT;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା gfunc_arg_size(CType *type) {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା align;
    ଯଦି (type->t & (VT_ARRAY|VT_BITFIELD))
        ଫେରନ୍ତୁ 8;
    ଫେରନ୍ତୁ type_size(type, &align);
}

ଶୂନ୍ୟ gfunc_call(ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_args)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, r, args_size, i, d, bt, struct_size;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା arg;

#ifdef CONFIG_TCC_BCHECK
    ଯଦି (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    args_size = (nb_args < REGN ? REGN : nb_args) * PTR_SIZE;
    arg = nb_args;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_size = args_size;
    ପାଇଁ(i = 0; i < nb_args; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        size = gfunc_arg_size(&sv->type);

        ଯଦି (using_regs(size))
            ଜାରି; /* arguments smaller than 8 bytes passed in registers or on stack */

        ଯଦି (bt == VT_STRUCT) {
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
        } ଅନ୍ୟଥା ଯଦି (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_size);
            struct_size += 16;
        }
    }

    ଯଦି (func_scratch < struct_size)
        func_scratch = struct_size;

    arg = nb_args;
    struct_size = args_size;

    ପାଇଁ(i = 0; i < nb_args; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        size = gfunc_arg_size(&vtop->type);
        ଯଦି (!using_regs(size)) {
            /* align to stack align size */
            size = (size + 15) & ~15;
            ଯଦି (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_size);
                gen_offs_sp(0x89, d, arg*8);
            } ଅନ୍ୟଥା {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_size);
            }
            struct_size += size;
        } ଅନ୍ୟଥା {
            ଯଦି (is_sse_float(vtop->type.t)) {
		ଯଦି (tcc_state->nosse)
		  tcc_error("SSE disabled");
                ଯଦି (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } ଅନ୍ୟଥା {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_ମୂଲ୍ୟ(d));
                }
            } ଅନ୍ୟଥା {
                ଯଦି (bt == VT_STRUCT) {
                    vtop->type.ref = ଖାଲି;
                    vtop->type.t = size > 4 ? VT_LLONG : size > 2 ? VT_INT
                        : size > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                ଯଦି (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } ଅନ୍ୟଥା {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_ମୂଲ୍ୟ(r) * 8 + REG_ମୂଲ୍ୟ(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    ଯଦି (nb_args > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        ଯଦି (nb_args > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    ଯଦି ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#ifdef CONFIG_TCC_BCHECK
        ଯଦି (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#endif
    }
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

/* generate function prolog of type 't' */
ଶୂନ୍ୟ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr, reg_param_index, bt, size;
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
    ଯଦି (!using_regs(size)) {
        gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ଖାଲି, addr);
        func_vc = addr;
        reg_param_index++;
        addr += 8;
    }

    /* define parameters */
    ଯେତେବେଳେ ((sym = sym->next) != ଖାଲି) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        size = gfunc_arg_size(type);
        ଯଦି (!using_regs(size)) {
            ଯଦି (reg_param_index < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ଖାଲି, addr);
            }
            gfunc_set_param(sym, addr, 1);
        } ଅନ୍ୟଥା {
            ଯଦି (reg_param_index < REGN) {
                /* save arguments passed by register */
                ଯଦି ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    ଯଦି (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_index, VT_LOCAL, ଖାଲି, addr);
                } ଅନ୍ୟଥା {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ଖାଲି, addr);
                }
            }
            gfunc_set_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_index++;
    }

    ଯେତେବେଳେ (reg_param_index < REGN) {
        ଯଦି (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ଖାଲି, addr);
            addr += 8;
        }
        reg_param_index++;
    }
#ifdef CONFIG_TCC_BCHECK
    ଯଦି (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
ଶୂନ୍ୟ gfunc_epilog(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, start;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#ifdef CONFIG_TCC_BCHECK
    ଯଦି (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    o(0xc9); /* leave */
    ଯଦି (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ଅନ୍ୟଥା {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    start = func_sub_sp_offset - FUNC_PROLOG_SIZE;
    cur_text_section->data_offset = ind;
    pe_add_unwind_data(start, ind, v);

    ind = start;
    ଯଦି (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } ଅନ୍ୟଥା {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_text_section->data_offset;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#ଅନ୍ୟଥା

ସ୍ଥିର ଶୂନ୍ୟ gadd_sp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା val)
{
    ଯଦି (val == (signed ଅକ୍ଷର)val) {
        o(0xc48348);
        g(val);
    } ଅନ୍ୟଥା {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ଗଣନା X86_64_Mode {
  x86_64_mode_none,
  x86_64_mode_memory,
  x86_64_mode_integer,
  x86_64_mode_sse,
  x86_64_mode_x87
} X86_64_Mode;

ସ୍ଥିର X86_64_Mode classify_x86_64_merge(X86_64_Mode a, X86_64_Mode b)
{
    ଯଦି (a == b)
        ଫେରନ୍ତୁ a;
    ଅନ୍ୟଥା ଯଦି (a == x86_64_mode_none)
        ଫେରନ୍ତୁ b;
    ଅନ୍ୟଥା ଯଦି (b == x86_64_mode_none)
        ଫେରନ୍ତୁ a;
    ଅନ୍ୟଥା ଯଦି ((a == x86_64_mode_memory) || (b == x86_64_mode_memory))
        ଫେରନ୍ତୁ x86_64_mode_memory;
    ଅନ୍ୟଥା ଯଦି ((a == x86_64_mode_integer) || (b == x86_64_mode_integer))
        ଫେରନ୍ତୁ x86_64_mode_integer;
    ଅନ୍ୟଥା ଯଦି ((a == x86_64_mode_x87) || (b == x86_64_mode_x87))
        ଫେରନ୍ତୁ x86_64_mode_memory;
    ଅନ୍ୟଥା
        ଫେରନ୍ତୁ x86_64_mode_sse;
}

ସ୍ଥିର X86_64_Mode classify_x86_64_inner(CType *ty)
{
    X86_64_Mode mode;
    Sym *f;
    
    ବାଛ (ty->t & VT_BTYPE) {
    ସ୍ଥିତି VT_VOID: ଫେରନ୍ତୁ x86_64_mode_none;
    
    ସ୍ଥିତି VT_INT:
    ସ୍ଥିତି VT_BYTE:
    ସ୍ଥିତି VT_SHORT:
    ସ୍ଥିତି VT_LLONG:
    ସ୍ଥିତି VT_BOOL:
    ସ୍ଥିତି VT_PTR:
    ସ୍ଥିତି VT_FUNC:
        ଫେରନ୍ତୁ x86_64_mode_integer;
    
    ସ୍ଥିତି VT_FLOAT:
    ସ୍ଥିତି VT_DOUBLE: ଫେରନ୍ତୁ x86_64_mode_sse;
    
    ସ୍ଥିତି VT_LDOUBLE: ଫେରନ୍ତୁ x86_64_mode_x87;
      
    ସ୍ଥିତି VT_STRUCT:
        f = ty->ref;

        mode = x86_64_mode_none;
        ପାଇଁ (f = f->next; f; f = f->next)
            mode = classify_x86_64_merge(mode, classify_x86_64_inner(&f->type));
        
        ଫେରନ୍ତୁ mode;
    }
    ପ୍ରତିଜ୍ଞା(0);
    ଫେରନ୍ତୁ 0;
}

ସ୍ଥିର X86_64_Mode classify_x86_64_arg(CType *ty, CType *ret, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *psize, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *palign, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *reg_ଗଣନା)
{
    X86_64_Mode mode;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align, ret_t = 0;
    
    ଯଦି (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_ଗଣନା = 1;
        ret_t = ty->t;
        mode = x86_64_mode_integer;
    } ଅନ୍ୟଥା {
        size = type_size(ty, &align);
        *psize = (size + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_ଗଣନା = 0; /* avoid compiler warning */

        ଯଦି (size > 16) {
            mode = x86_64_mode_memory;
        } ଅନ୍ୟଥା {
            mode = classify_x86_64_inner(ty);
            ବାଛ (mode) {
            ସ୍ଥିତି x86_64_mode_integer:
                ଯଦି (size > 8) {
                    *reg_ଗଣନା = 2;
                    ret_t = VT_QLONG;
                } ଅନ୍ୟଥା {
                    *reg_ଗଣନା = 1;
                    ଯଦି (size > 4)
                        ret_t = VT_LLONG;
                    ଅନ୍ୟଥା ଯଦି (size > 2)
                        ret_t = VT_INT;
                    ଅନ୍ୟଥା ଯଦି (size > 1)
                        ret_t = VT_SHORT;
                    ଅନ୍ୟଥା
                        ret_t = VT_BYTE;
                    ଯଦି ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                ଭାଙ୍ଗ;
                
            ସ୍ଥିତି x86_64_mode_x87:
                *reg_ଗଣନା = 1;
                ret_t = VT_LDOUBLE;
                ଭାଙ୍ଗ;

            ସ୍ଥିତି x86_64_mode_sse:
                ଯଦି (size > 8) {
                    *reg_ଗଣନା = 2;
                    ret_t = VT_QFLOAT;
                } ଅନ୍ୟଥା {
                    *reg_ଗଣନା = 1;
                    ret_t = (size > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                ଭାଙ୍ଗ;
            ପୂର୍ବନିର୍ଦ୍ଧାରିତ: ଭାଙ୍ଗ; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    ଯଦି (ret) {
        ret->ref = ଖାଲି;
        ret->t = ret_t;
    }
    
    ଫେରନ୍ତୁ mode;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    ଗଣନା __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align, reg_ଗଣନା;
    X86_64_Mode mode = classify_x86_64_arg(ty, ଖାଲି, &size, &align, &reg_ଗଣନା);
    ବାଛ (mode) {
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ: ଫେରନ୍ତୁ __va_stack;
    ସ୍ଥିତି x86_64_mode_integer: ଫେରନ୍ତୁ __va_gen_reg;
    ସ୍ଥିତି x86_64_mode_sse: ଫେରନ୍ତୁ __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gfunc_sret(CType *vt, ପୂର୍ଣ୍ଣସଂଖ୍ୟା variadic, CType *ret, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ret_align, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *regsize)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align, reg_ଗଣନା;
    ଯଦି (classify_x86_64_arg(vt, ret, &size, &align, &reg_ଗଣନା) == x86_64_mode_memory)
        ଫେରନ୍ତୁ 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_ଗଣନା; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    ଫେରନ୍ତୁ 1;
}

#define REGN 6
ସ୍ଥିର ଅଚଳ uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା arg_prepare_reg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା idx) {
  ଯଦି (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      ଫେରନ୍ତୁ idx + 8;
  ଅନ୍ୟଥା
      ଫେରନ୍ତୁ idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ଶୂନ୍ୟ gfunc_call(ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_args)
{
    X86_64_Mode mode;
    CType type;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align, r, args_size, ଗଦା_adjust, i, reg_ଗଣନା, k;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_reg_args = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_sse_args = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sse_reg, gen_reg;
    ଅକ୍ଷର *onstack = tcc_malloc((nb_args + 1) * ଆକାର (ଅକ୍ଷର));

#ifdef CONFIG_TCC_BCHECK
    ଯଦି (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    ଗଦା_adjust = 0;
    ପାଇଁ(i = nb_args - 1; i >= 0; i--) {
        mode = classify_x86_64_arg(&vtop[-i].type, ଖାଲି, &size, &align, &reg_ଗଣନା);
        ଯଦି (size == 0) ଜାରି;
        ଯଦି (mode == x86_64_mode_sse && nb_sse_args + reg_ଗଣନା <= 8) {
            nb_sse_args += reg_ଗଣନା;
	    onstack[i] = 0;
	} ଅନ୍ୟଥା ଯଦି (mode == x86_64_mode_integer && nb_reg_args + reg_ଗଣନା <= REGN) {
            nb_reg_args += reg_ଗଣନା;
	    onstack[i] = 0;
	} ଅନ୍ୟଥା ଯଦି (mode == x86_64_mode_none) {
	    onstack[i] = 0;
	} ଅନ୍ୟଥା {
	    ଯଦି (align == 16 && (ଗଦା_adjust &= 15)) {
		onstack[i] = 2;
		ଗଦା_adjust = 0;
	    } ଅନ୍ୟଥା
	      onstack[i] = 1;
	    ଗଦା_adjust += size;
	}
    }

    ଯଦି (nb_sse_args && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_args;
    sse_reg = nb_sse_args;
    args_size = 0;
    ଗଦା_adjust &= 15;
    ପାଇଁ (i = k = 0; i < nb_args;) {
	mode = classify_x86_64_arg(&vtop[-i].type, ଖାଲି, &size, &align, &reg_ଗଣନା);
	ଯଦି (size) {
            ଯଦି (!onstack[i + k]) {
	        ++i;
	        ଜାରି;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            ଯଦି (ଗଦା_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                args_size += 8;
	        ଗଦା_adjust = 0;
            }
	    ଯଦି (onstack[i + k] == 2)
	        ଗଦା_adjust = 1;
        }

	vrotb(i+1);

	ବାଛ (vtop->type.t & VT_BTYPE) {
	    ସ୍ଥିତି VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, size); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_ମୂଲ୍ୟ(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_ମୂଲ୍ୟ(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		ଭାଙ୍ଗ;

	    ସ୍ଥିତି VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, size); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		ଭାଙ୍ଗ;

	    ସ୍ଥିତି VT_FLOAT:
	    ସ୍ଥିତି VT_DOUBLE:
		ପ୍ରତିଜ୍ଞା(mode == x86_64_mode_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_ମୂଲ୍ୟ(r)*8);
		o(0x24);
		ଭାଙ୍ଗ;

	    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
		ପ୍ରତିଜ୍ଞା(mode == x86_64_mode_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_ମୂଲ୍ୟ(r)); /* push r */
		ଭାଙ୍ଗ;
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
    ପ୍ରତିଜ୍ଞା(gen_reg <= REGN);
    ପ୍ରତିଜ୍ଞା(sse_reg <= 8);
    ପାଇଁ(i = 0; i < nb_args; i++) {
        mode = classify_x86_64_arg(&vtop->type, &type, &size, &align, &reg_ଗଣନା);
        ଯଦି (size == 0) ଜାରି;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        ଯଦି (mode == x86_64_mode_sse) {
            ଯଦି (reg_ଗଣନା == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                ଯଦି (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } ଅନ୍ୟଥା {
                ପ୍ରତିଜ୍ଞା(reg_ଗଣନା == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } ଅନ୍ୟଥା ଯଦି (mode == x86_64_mode_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା d;
            gen_reg -= reg_ଗଣନା;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_ମୂଲ୍ୟ(r) * 8 + REG_ମୂଲ୍ୟ(d));
            ଯଦି (reg_ଗଣନା == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_ମୂଲ୍ୟ(vtop->r2) * 8 + REG_ମୂଲ୍ୟ(d));
            }
        }
        vtop--;
    }
    ପ୍ରତିଜ୍ଞା(gen_reg == 0);
    ପ୍ରତିଜ୍ଞା(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    ଯଦି (nb_reg_args > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        ଯଦି (nb_reg_args > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    ଯଦି (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_args < 8 ? nb_sse_args : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    ଯଦି (args_size)
        gadd_sp(args_size);
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

ସ୍ଥିର ଶୂନ୍ୟ ଠେଲ_arg_reg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, ଖାଲି, loc);
}

/* generate function prolog of type 't' */
ଶୂନ୍ୟ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_Mode mode, ret_mode;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, addr, align, size, reg_ଗଣନା;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା param_addr = 0, reg_param_index, sse_param_index;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_SIZE * 2;
    loc = 0;
    ind += FUNC_PROLOG_SIZE;
    func_sub_sp_offset = ind;
    func_ret_sub = 0;
    ret_mode = classify_x86_64_arg(&func_vt, ଖାଲି, &size, &align, &reg_ଗଣନା);

    ଯଦି (func_var) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା seen_reg_ଅଙ୍କ, seen_sse_ଅଙ୍କ, seen_ଗଦା_size;
        seen_reg_ଅଙ୍କ = ret_mode == x86_64_mode_memory;
        seen_sse_ଅଙ୍କ = 0;
        /* frame pointer and return address */
        seen_ଗଦା_size = PTR_SIZE * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        ଯେତେବେଳେ ((sym = sym->next) != ଖାଲି) {
            type = &sym->type;
            mode = classify_x86_64_arg(type, ଖାଲି, &size, &align, &reg_ଗଣନା);
            ବାଛ (mode) {
            ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            ଗଦା_arg:
                seen_ଗଦା_size = ((seen_ଗଦା_size + align - 1) & -align) + size;
                ଭାଙ୍ଗ;
                
            ସ୍ଥିତି x86_64_mode_integer:
                ଯଦି (seen_reg_ଅଙ୍କ + reg_ଗଣନା > REGN)
		    ଯାଅ ଗଦା_arg;
		seen_reg_ଅଙ୍କ += reg_ଗଣନା;
                ଭାଙ୍ଗ;
                
            ସ୍ଥିତି x86_64_mode_sse:
                ଯଦି (seen_sse_ଅଙ୍କ + reg_ଗଣନା > 8)
		    ଯାଅ ଗଦା_arg;
		seen_sse_ଅଙ୍କ += reg_ଗଣନା;
                ଭାଙ୍ଗ;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(seen_reg_ଅଙ୍କ * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(seen_sse_ଅଙ୍କ * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(seen_ଗଦା_size);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        ପାଇଁ (i = 0; i < 8; i++) {
            loc -= 16;
	    ଯଦି (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, ଖାଲି, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        ପାଇଁ (i = 0; i < REGN; i++) {
            ଠେଲ_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_index = 0;
    sse_param_index = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    ଯଦି (ret_mode == x86_64_mode_memory) {
        ଠେଲ_arg_reg(reg_param_index);
        func_vc = loc;
        reg_param_index++;
    }
    /* define parameters */
    ଯେତେବେଳେ ((sym = sym->next) != ଖାଲି) {
        type = &sym->type;
        mode = classify_x86_64_arg(type, ଖାଲି, &size, &align, &reg_ଗଣନା);
        ବାଛ (mode) {
        ସ୍ଥିତି x86_64_mode_sse:
	    ଯଦି (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            ଯଦି (sse_param_index + reg_ଗଣନା <= 8) {
                /* save arguments passed by register */
                loc -= reg_ଗଣନା * 8;
                param_addr = loc;
                ପାଇଁ (i = 0; i < reg_ଗଣନା; ++i) {
                    gen_modrm32(0xd60f66, sse_param_index, VT_LOCAL, ଖାଲି, param_addr + i*8);
                    ++sse_param_index;
                }
            } ଅନ୍ୟଥା {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            ଭାଙ୍ଗ;
            
        ସ୍ଥିତି x86_64_mode_memory:
        ସ୍ଥିତି x86_64_mode_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += size;
            ଭାଙ୍ଗ;
            
        ସ୍ଥିତି x86_64_mode_integer: {
            ଯଦି (reg_param_index + reg_ଗଣନା <= REGN) {
                /* save arguments passed by register */
                loc -= reg_ଗଣନା * 8;
                param_addr = loc;
                ପାଇଁ (i = 0; i < reg_ଗଣନା; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ଖାଲି, param_addr + i*8);
                    ++reg_param_index;
                }
            } ଅନ୍ୟଥା {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            ଭାଙ୍ଗ;
        }
	ପୂର୍ବନିର୍ଦ୍ଧାରିତ: ଭାଙ୍ଗ; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_set_param(sym, param_addr, 0);
    }

#ifdef CONFIG_TCC_BCHECK
    ଯଦି (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
ଶୂନ୍ୟ gfunc_epilog(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, saved_ind;

#ifdef CONFIG_TCC_BCHECK
    ଯଦି (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif
    o(0xc9); /* leave */
    ଯଦି (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ଅନ୍ୟଥା {
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

ST_FUNC ଶୂନ୍ୟ gen_fill_nops(ପୂର୍ଣ୍ଣସଂଖ୍ୟା bytes)
{
    ଯେତେବେଳେ (bytes--)
      g(0x90);
}

/* generate a jump to a label */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା gjmp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଫେରନ୍ତୁ gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ଶୂନ୍ୟ gjmp_addr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
    r = a - ind - 2;
    ଯଦି (r == (signed ଅକ୍ଷର)r) {
        g(0xeb);
        g(r);
    } ଅନ୍ୟଥା {
        oad(0xe9, a - ind - 5);
    }
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

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gjmp_cond(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
        ଯଦି (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା v = vtop->cmp_r;
            op &= ~0x100;
            ଯଦି (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    ଅନ୍ୟଥା
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        ଫେରନ୍ତୁ t;
}

/* generate an integer binary operation */
ଶୂନ୍ୟ gen_opi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, fr, opc, c;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    ବାଛ(op) {
    ସ୍ଥିତି '+':
    ସ୍ଥିତି TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        ଯଦି (cc && (!ll || (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            ଯଦି (c == (signed ଅକ୍ଷର)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_ମୂଲ୍ୟ(r));
                g(c);
            } ଅନ୍ୟଥା {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_ମୂଲ୍ୟ(r), c);
            }
        } ଅନ୍ୟଥା {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_ମୂଲ୍ୟ(r) + REG_ମୂଲ୍ୟ(fr) * 8);
        }
        vtop--;
        ଯଦି (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '-':
    ସ୍ଥିତି TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        ଯାଅ gen_op8;
    ସ୍ଥିତି TOK_ADDC2: /* add with carry use */
        opc = 2;
        ଯାଅ gen_op8;
    ସ୍ଥିତି TOK_SUBC2: /* sub with carry use */
        opc = 3;
        ଯାଅ gen_op8;
    ସ୍ଥିତି '&':
        opc = 4;
        ଯାଅ gen_op8;
    ସ୍ଥିତି '^':
        opc = 6;
        ଯାଅ gen_op8;
    ସ୍ଥିତି '|':
        opc = 1;
        ଯାଅ gen_op8;
    ସ୍ଥିତି '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_ମୂଲ୍ୟ(fr) + REG_ମୂଲ୍ୟ(r) * 8);
        vtop--;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_SHL:
        opc = 4;
        ଯାଅ gen_shift;
    ସ୍ଥିତି TOK_SHR:
        opc = 5;
        ଯାଅ gen_shift;
    ସ୍ଥିତି TOK_SAR:
        opc = 7;
    gen_shift:
        opc = 0xc0 | (opc << 3);
        ଯଦି (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_ମୂଲ୍ୟ(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } ଅନ୍ୟଥା {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_ମୂଲ୍ୟ(r));
        }
        vtop--;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_UDIV:
    ସ୍ଥିତି TOK_UMOD:
        uu = 1;
        ଯାଅ divmod;
    ସ୍ଥିତି '/':
    ସ୍ଥିତି '%':
    ସ୍ଥିତି TOK_PDIV:
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
        o((uu ? 0xf0 : 0xf8) + REG_ମୂଲ୍ୟ(fr));
        ଯଦି (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        ଅନ୍ୟଥା
            r = TREG_RAX;
        vtop->r = r;
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        opc = 7;
        ଯାଅ gen_op8;
    }
}

ଶୂନ୍ୟ gen_opl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ଶୂନ୍ୟ gen_opf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ft, fc, swapped, r, opc;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt = vtop->type.t & VT_BTYPE;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    ଯଦି (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        ଯଦି (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } ଅନ୍ୟଥା {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, ଖାଲି, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        ଫେରନ୍ତୁ;
    }

    /* convert constants to memory references */
    ଯଦି ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    ଯଦି ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    ଯଦି ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    ଯଦି (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    ଯଦି ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        ଯଦି (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            load(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            ଯଦି (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            ଅନ୍ୟଥା ଯଦି (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            ଯଦି (swapped)
                o(0xc9d9); /* fxch %st(1) */
            ଯଦି (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            ଅନ୍ୟଥା
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            ଯଦି (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } ଅନ୍ୟଥା ଯଦି (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } ଅନ୍ୟଥା ଯଦି (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } ଅନ୍ୟଥା {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } ଅନ୍ୟଥା {
            /* no memory reference possible for long double operations */
            load(TREG_ST0, vtop);
            swapped = !swapped;

            ବାଛ(op) {
            ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            ସ୍ଥିତି '+':
                a = 0;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି '-':
                a = 4;
                ଯଦି (swapped)
                    a++;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି '*':
                a = 1;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି '/':
                a = 6;
                ଯଦି (swapped)
                    a++;
                ଭାଙ୍ଗ;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } ଅନ୍ୟଥା {
        ଯଦି (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            ଯଦି ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = ଖାଲି;
                load(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            ଯଦି (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } ଅନ୍ୟଥା {
                ଯଦି (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                ଯଦି (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } ଅନ୍ୟଥା {
                    op = 0x97; /* seta */
                }
            }

            ଯଦି (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            ପ୍ରତିଜ୍ଞା(!(vtop[-1].r & VT_LVAL));
            
            ଯଦି (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            ଅନ୍ୟଥା
                opc = 0x2f0f; /* comisd */
            ଯଦି ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } ଅନ୍ୟଥା {
            ପ୍ରତିଜ୍ଞା((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            ବାଛ(op) {
            ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            ସ୍ଥିତି '+':
                a = 0;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି '-':
                a = 4;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି '*':
                a = 1;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି '/':
                a = 6;
                ଭାଙ୍ଗ;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            ପ୍ରତିଜ୍ଞା((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            ଯଦି ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = ଖାଲି;
                load(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            ପ୍ରତିଜ୍ଞା(!(vtop[-1].r & VT_LVAL));
            ଯଦି (swapped) {
                ପ୍ରତିଜ୍ଞା(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            ଯଦି ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } ଅନ୍ୟଥା {
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
ଶୂନ୍ୟ gen_cvt_itof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଯଦି ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        ଯଦି ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } ଅନ୍ୟଥା ଯଦି ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } ଅନ୍ୟଥା {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } ଅନ୍ୟଥା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        ଯଦି ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_ମୂଲ୍ୟ(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
ଶୂନ୍ୟ gen_cvt_ftof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    ଯଦି (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        ଯଦି (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_ମୂଲ୍ୟ(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_ମୂଲ୍ୟ(vtop->r)*9);
        } ଅନ୍ୟଥା ଯଦି (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_ମୂଲ୍ୟ(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } ଅନ୍ୟଥା ଯଦି (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        ଯଦି (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_ମୂଲ୍ୟ(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_ମୂଲ୍ୟ(vtop->r)*9);
        } ଅନ୍ୟଥା ଯଦି (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_ମୂଲ୍ୟ(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } ଅନ୍ୟଥା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        ଯଦି (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_ମୂଲ୍ୟ(r)*8);
            o(0xf024);
            vtop->r = r;
        } ଅନ୍ୟଥା ଯଦି (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_ମୂଲ୍ୟ(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
ଶୂନ୍ୟ gen_cvt_ftoi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ft, bt, size, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    ଯଦି (bt == VT_LDOUBLE) {
	ଯଦି (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    ଫେରନ୍ତୁ;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    ଯଦି (t != VT_INT)
        size = 8;
    ଅନ୍ୟଥା
        size = 4;

    r = get_reg(RC_INT);
    ଯଦି (bt == VT_FLOAT) {
        o(0xf3);
    } ଅନ୍ୟଥା ଯଦି (bt == VT_DOUBLE) {
        o(0xf2);
    } ଅନ୍ୟଥା {
        ପ୍ରତିଜ୍ଞା(0);
    }
    orex(size == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_ମୂଲ୍ୟ(vtop->r) + REG_ମୂଲ୍ୟ(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC ଶୂନ୍ୟ gen_cvt_sxtw(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_ମୂଲ୍ୟ(r) << 3) + REG_ମୂଲ୍ୟ(r));
}

/* char/short to int conversion */
ST_FUNC ଶୂନ୍ୟ gen_cvt_csti(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_ମୂଲ୍ୟ(r) << 3 | REG_ମୂଲ୍ୟ(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC ଶୂନ୍ୟ gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_text_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC ଶୂନ୍ୟ ggoto(ଶୂନ୍ୟ)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC ଶୂନ୍ୟ gen_vla_sp_save(ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, ଖାଲି, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC ଶୂନ୍ୟ gen_vla_sp_restore(ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, ଖାଲି, addr);
}

#ifdef TCC_TARGET_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC ଶୂନ୍ୟ gen_vla_result(ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, ଖାଲି, addr);
}
#endif

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC ଶୂନ୍ୟ gen_vla_alloc(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା align) {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା use_call = 0;

#ଯଦି defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#endif
#ifdef TCC_TARGET_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#endif
    ଯଦି (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    ଅନ୍ୟଥା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
        r = gv(RC_INT); /* allocation size */
        /* sub r,%rsp */
        o(0x2b48);
        o(0xe0 | REG_ମୂଲ୍ୟ(r));
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
ST_FUNC ଶୂନ୍ୟ gen_struct_copy(ପୂର୍ଣ୍ଣସଂଖ୍ୟା size)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = size / PTR_SIZE;
#ifdef TCC_TARGET_PE
    o(0x5756); /* push rsi, rdi */
#endif
    gv2(RC_RDI, RC_RSI);
    ଯଦି (n <= 4) {
        ଯେତେବେଳେ (n)
            o(0xa548), --n;
    } ଅନ୍ୟଥା {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    ଯଦି (size & 0x04)
        o(0xa5);
    ଯଦି (size & 0x02)
        o(0xa566);
    ଯଦି (size & 0x01)
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
