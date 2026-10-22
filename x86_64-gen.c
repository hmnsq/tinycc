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
എണ്ണൽ {
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
#define REG_മൂല്യം(reg) ((reg) & 7)

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
ST_FUNC ശൂന്യം gen_struct_copy(പൂർണ്ണസംഖ്യ size);

/******************************************************/
#അല്ലെങ്കിൽ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#അന്തര്ഭാവ "tcc.h"
#അന്തര്ഭാവ <assert.h>

ST_DATA സ്ഥിരം അക്ഷരം * സ്ഥിരം target_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_DATA സ്ഥിരം പൂർണ്ണസംഖ്യ reg_classes[NB_REGS] = {
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

സ്ഥിതം unsigned long func_sub_sp_offset;
സ്ഥിതം പൂർണ്ണസംഖ്യ func_ret_sub;

#എങ്കിൽ defined(CONFIG_TCC_BCHECK)
സ്ഥിതം addr_t func_bound_offset;
സ്ഥിതം unsigned long func_bound_ind;
ST_DATA പൂർണ്ണസംഖ്യ func_bound_add_epilog;
#endif

#ifdef TCC_TARGET_PE
സ്ഥിതം പൂർണ്ണസംഖ്യ func_scratch, func_alloca;
#endif

/* XXX: make it faster ? */
ST_FUNC ശൂന്യം g(പൂർണ്ണസംഖ്യ c)
{
    പൂർണ്ണസംഖ്യ ind1;
    എങ്കിൽ (nocode_wanted)
        തിരികെ;
    ind1 = ind + 1;
    എങ്കിൽ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC ശൂന്യം o(unsigned പൂർണ്ണസംഖ്യ c)
{
    ആകുമ്പോൾ (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC ശൂന്യം gen_le16(പൂർണ്ണസംഖ്യ v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC ശൂന്യം gen_le32(പൂർണ്ണസംഖ്യ c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

ST_FUNC ശൂന്യം gen_le64(int64_t c)
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

സ്ഥിതം ശൂന്യം orex(പൂർണ്ണസംഖ്യ ll, പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ r2, പൂർണ്ണസംഖ്യ b)
{
    എങ്കിൽ ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    എങ്കിൽ ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    എങ്കിൽ (ll || REX_BASE(r) || REX_BASE(r2)) {
        എങ്കിൽ ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_BASE(r) | (REX_BASE(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC ശൂന്യം gsym_addr(പൂർണ്ണസംഖ്യ t, പൂർണ്ണസംഖ്യ a)
{
    ആകുമ്പോൾ (t) {
        unsigned അക്ഷരം *ptr = cur_text_section->data + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ is64_type(പൂർണ്ണസംഖ്യ t)
{
    തിരികെ ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
സ്ഥിതം പൂർണ്ണസംഖ്യ oad(പൂർണ്ണസംഖ്യ c, പൂർണ്ണസംഖ്യ s)
{
    പൂർണ്ണസംഖ്യ t;
    എങ്കിൽ (nocode_wanted)
        തിരികെ s;
    o(c);
    t = ind;
    gen_le32(s);
    തിരികെ t;
}

/* generate jmp to a label */
#define gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC ശൂന്യം gen_addr32(പൂർണ്ണസംഖ്യ r, Sym *sym, പൂർണ്ണസംഖ്യ c)
{
    എങ്കിൽ (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ശൂന്യം gen_addrpc32(പൂർണ്ണസംഖ്യ r, Sym *sym, പൂർണ്ണസംഖ്യ c)
{
    എങ്കിൽ (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
സ്ഥിതം ശൂന്യം gen_gotpcrel(പൂർണ്ണസംഖ്യ r, Sym *sym, പൂർണ്ണസംഖ്യ c)
{
#ifdef TCC_TARGET_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, ശൂന്യ), c, r,
        cur_text_section->data[ind-3],
        cur_text_section->data[ind-2],
        cur_text_section->data[ind-1]
        );
#endif
    greloca(cur_text_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    എങ്കിൽ (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_മൂല്യം(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
സ്ഥിതം ശൂന്യം gen_modrm_impl(പൂർണ്ണസംഖ്യ opcode, പൂർണ്ണസംഖ്യ ll, പൂർണ്ണസംഖ്യ op_reg_0, പൂർണ്ണസംഖ്യ r, Sym *sym, പൂർണ്ണസംഖ്യ c)
{
    പൂർണ്ണസംഖ്യ op_reg = REG_മൂല്യം(op_reg_0) << 3;

    എങ്കിൽ ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_SIZE); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#അല്ലെങ്കിൽ
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#endif
        തിരികെ;
    }

    orex(ll, r, op_reg_0, opcode);

    എങ്കിൽ ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	എങ്കിൽ (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} അല്ലെങ്കിൽ {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    എങ്കിൽ (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } അല്ലെങ്കിൽ {
		gen_addrpc32(r, sym, c);
	    }
	}
    } അല്ലെങ്കിൽ എങ്കിൽ ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        എങ്കിൽ (c == (signed അക്ഷരം)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } അല്ലെങ്കിൽ {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } അല്ലെങ്കിൽ എങ്കിൽ ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_മൂല്യം(r));
        gen_le32(c);
    } അല്ലെങ്കിൽ എങ്കിൽ (r & VT_LVAL) {
        g(0x00 | op_reg | REG_മൂല്യം(r));
    } അല്ലെങ്കിൽ {
        g(0xc0 | op_reg | REG_മൂല്യം(r));
    }
}

സ്ഥിതം ശൂന്യം gen_modrm64(പൂർണ്ണസംഖ്യ opcode, പൂർണ്ണസംഖ്യ op_reg, പൂർണ്ണസംഖ്യ r, Sym *sym, പൂർണ്ണസംഖ്യ c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

സ്ഥിതം ശൂന്യം gen_modrm32(പൂർണ്ണസംഖ്യ opcode, പൂർണ്ണസംഖ്യ op_reg, പൂർണ്ണസംഖ്യ r, Sym *sym, പൂർണ്ണസംഖ്യ c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
ശൂന്യം load(പൂർണ്ണസംഖ്യ r, SValue *sv)
{
    പൂർണ്ണസംഖ്യ v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    എങ്കിൽ (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#ifndef TCC_TARGET_PE
    /* we use indirect access via got */
    എങ്കിൽ ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        പൂർണ്ണസംഖ്യ tr = r | TREG_MEM;
        എങ്കിൽ (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#endif

    v = fr & VT_VALMASK;
    എങ്കിൽ (fr & VT_LVAL) {
        പൂർണ്ണസംഖ്യ b, ll;
        എങ്കിൽ (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = ശൂന്യ;
            fr = r;
            എങ്കിൽ (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            load(fr, &v1);
            fr |= VT_LVAL;
        }
	എങ്കിൽ (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = ശൂന്യ;
	    fr = r;
	    എങ്കിൽ (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    load(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	എങ്കിൽ ((ft & VT_BTYPE) == VT_STRUCT) {
	    പൂർണ്ണസംഖ്യ align;
	    തിരഞ്ഞെടുപ്പ് (type_size(&sv->type, &align)) {
		അവസ്ഥ 1: ft = VT_BYTE; നിർത്തുക;
		അവസ്ഥ 2: ft = VT_SHORT; നിർത്തുക;
		അവസ്ഥ 4: ft = VT_INT; നിർത്തുക;
		അവസ്ഥ 8: ft = VT_LLONG; നിർത്തുക;
		സ്ഥിരസ്ഥിതി:
		    tcc_error("invalid aggregate type for register load");
		    നിർത്തുക;
	    }
	}
        എങ്കിൽ ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_മൂല്യം(r); /* movd */
        } അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_മൂല്യം(r);
        } അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } അല്ലെങ്കിൽ എങ്കിൽ ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            തിരികെ;
        } അല്ലെങ്കിൽ {
            പ്രതിജ്ഞാ(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (v == VT_CONST) {
            എങ്കിൽ (fr & VT_SYM) {
#ifdef TCC_TARGET_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#അല്ലെങ്കിൽ
                എങ്കിൽ (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, ശൂന്യ, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_മൂല്യം(r), 0);
                    greloca(cur_text_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } അല്ലെങ്കിൽ എങ്കിൽ (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_മൂല്യം(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } അല്ലെങ്കിൽ {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_മൂല്യം(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#endif
            } അല്ലെങ്കിൽ എങ്കിൽ (is64_type(ft)) {
                എങ്കിൽ (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_മൂല്യം(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } അല്ലെങ്കിൽ എങ്കിൽ (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_മൂല്യം(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } അല്ലെങ്കിൽ {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_മൂല്യം(r) * 9);
                }
            } അല്ലെങ്കിൽ {
                orex(0,r,0, 0xb8 + REG_മൂല്യം(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } അല്ലെങ്കിൽ എങ്കിൽ (v == VT_CMP) {
	    എങ്കിൽ (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_മൂല്യം(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_BASE(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_മൂല്യം(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_മൂല്യം(r) * 0x900); /* movzbl %al, %eax */
        } അല്ലെങ്കിൽ എങ്കിൽ (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_മൂല്യം(r), t); /* mov $1, r */
            o(0x05eb + (REX_BASE(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_മൂല്യം(r), t ^ 1); /* mov $0, r */
        } അല്ലെങ്കിൽ എങ്കിൽ (v != r) {
            എങ്കിൽ ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                എങ്കിൽ (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_മൂല്യം(r)*8); /* %xmmN */
                    o(0xf024);
                } അല്ലെങ്കിൽ {
                    പ്രതിജ്ഞാ((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    എങ്കിൽ ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } അല്ലെങ്കിൽ {
                        പ്രതിജ്ഞാ((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_മൂല്യം(v) + REG_മൂല്യം(r)*8);
                }
            } അല്ലെങ്കിൽ എങ്കിൽ (r == TREG_ST0) {
                പ്രതിജ്ഞാ((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_മൂല്യം(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } അല്ലെങ്കിൽ {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_മൂല്യം(r) + REG_മൂല്യം(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
ശൂന്യം store(പൂർണ്ണസംഖ്യ r, SValue *v)
{
    പൂർണ്ണസംഖ്യ fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    പൂർണ്ണസംഖ്യ opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    എങ്കിൽ (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#ifndef TCC_TARGET_PE
    /* we need to access the variable via got */
    എങ്കിൽ ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#endif

    /* XXX: incorrect if float reg to reg */
    എങ്കിൽ (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_മൂല്യം(r);
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_മൂല്യം(r);
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } അല്ലെങ്കിൽ {
        opc = 0x89;
        എങ്കിൽ (bt == VT_SHORT)
            opc = 0x8966;
        അല്ലെങ്കിൽ എങ്കിൽ (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
സ്ഥിതം ശൂന്യം gcall_or_jmp(പൂർണ്ണസംഖ്യ is_jmp)
{
    പൂർണ്ണസംഖ്യ r;
    എങ്കിൽ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (പൂർണ്ണസംഖ്യ)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind + 1, R_X86_64_PLT32, (പൂർണ്ണസംഖ്യ)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } അല്ലെങ്കിൽ {
        /* otherwise, indirect call */
        r = TREG_R11;
        load(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_മൂല്യം(r) + (is_jmp << 4));
    }
}

#എങ്കിൽ defined(CONFIG_TCC_BCHECK)

സ്ഥിതം ശൂന്യം gen_bounds_call(പൂർണ്ണസംഖ്യ v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#ifdef TCC_TARGET_PE
# define TREG_FASTCALL_1 TREG_RCX
#അല്ലെങ്കിൽ
# define TREG_FASTCALL_1 TREG_RDI
#endif

സ്ഥിതം ശൂന്യം gen_bounds_prolog(ശൂന്യം)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->data_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
}

സ്ഥിതം ശൂന്യം gen_bounds_epilog(ശൂന്യം)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    പൂർണ്ണസംഖ്യ offset_modified = func_bound_offset != lbounds_section->data_offset;

    എങ്കിൽ (!offset_modified && !func_bound_add_epilog)
        തിരികെ;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, വലുപ്പം(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section, 
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    എങ്കിൽ (offset_modified) {
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
സ്ഥിതം സ്ഥിരം uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
സ്ഥിതം പൂർണ്ണസംഖ്യ arg_prepare_reg(പൂർണ്ണസംഖ്യ idx) {
  എങ്കിൽ (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      തിരികെ idx + 10;
  അല്ലെങ്കിൽ
      തിരികെ idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

സ്ഥിതം ശൂന്യം gen_offs_sp(പൂർണ്ണസംഖ്യ b, പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    എങ്കിൽ (d == (signed അക്ഷരം)d) {
        o(0x2444 | (REG_മൂല്യം(r) << 3));
        g(d);
    } അല്ലെങ്കിൽ {
        o(0x2484 | (REG_മൂല്യം(r) << 3));
        gen_le32(d);
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ using_regs(പൂർണ്ണസംഖ്യ size)
{
    തിരികെ !(size > 8 || (size & (size - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC പൂർണ്ണസംഖ്യ gfunc_sret(CType *vt, പൂർണ്ണസംഖ്യ variadic, CType *ret, പൂർണ്ണസംഖ്യ *ret_align, പൂർണ്ണസംഖ്യ *regsize)
{
    പൂർണ്ണസംഖ്യ size, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    size = type_size(vt, &align);
    എങ്കിൽ (!using_regs(size))
        തിരികെ 0;
    എങ്കിൽ (size == 8)
        ret->t = VT_LLONG;
    അല്ലെങ്കിൽ എങ്കിൽ (size == 4)
        ret->t = VT_INT;
    അല്ലെങ്കിൽ എങ്കിൽ (size == 2)
        ret->t = VT_SHORT;
    അല്ലെങ്കിൽ
        ret->t = VT_BYTE;
    ret->ref = ശൂന്യ;
    തിരികെ 1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ is_sse_float(പൂർണ്ണസംഖ്യ t) {
    പൂർണ്ണസംഖ്യ bt;
    bt = t & VT_BTYPE;
    തിരികെ bt == VT_DOUBLE || bt == VT_FLOAT;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ gfunc_arg_size(CType *type) {
    പൂർണ്ണസംഖ്യ align;
    എങ്കിൽ (type->t & (VT_ARRAY|VT_BITFIELD))
        തിരികെ 8;
    തിരികെ type_size(type, &align);
}

ശൂന്യം gfunc_call(പൂർണ്ണസംഖ്യ nb_args)
{
    പൂർണ്ണസംഖ്യ size, r, args_size, i, d, bt, struct_size;
    പൂർണ്ണസംഖ്യ arg;

#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    args_size = (nb_args < REGN ? REGN : nb_args) * PTR_SIZE;
    arg = nb_args;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_size = args_size;
    വേണ്ടി(i = 0; i < nb_args; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        size = gfunc_arg_size(&sv->type);

        എങ്കിൽ (using_regs(size))
            തുടരുക; /* arguments smaller than 8 bytes passed in registers or on stack */

        എങ്കിൽ (bt == VT_STRUCT) {
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
        } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_size);
            struct_size += 16;
        }
    }

    എങ്കിൽ (func_scratch < struct_size)
        func_scratch = struct_size;

    arg = nb_args;
    struct_size = args_size;

    വേണ്ടി(i = 0; i < nb_args; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        size = gfunc_arg_size(&vtop->type);
        എങ്കിൽ (!using_regs(size)) {
            /* align to stack align size */
            size = (size + 15) & ~15;
            എങ്കിൽ (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_size);
                gen_offs_sp(0x89, d, arg*8);
            } അല്ലെങ്കിൽ {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_size);
            }
            struct_size += size;
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (is_sse_float(vtop->type.t)) {
		എങ്കിൽ (tcc_state->nosse)
		  tcc_error("SSE disabled");
                എങ്കിൽ (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } അല്ലെങ്കിൽ {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_മൂല്യം(d));
                }
            } അല്ലെങ്കിൽ {
                എങ്കിൽ (bt == VT_STRUCT) {
                    vtop->type.ref = ശൂന്യ;
                    vtop->type.t = size > 4 ? VT_LLONG : size > 2 ? VT_INT
                        : size > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                എങ്കിൽ (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } അല്ലെങ്കിൽ {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_മൂല്യം(r) * 8 + REG_മൂല്യം(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    എങ്കിൽ (nb_args > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        എങ്കിൽ (nb_args > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    എങ്കിൽ ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#endif
    }
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

/* generate function prolog of type 't' */
ശൂന്യം gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    പൂർണ്ണസംഖ്യ addr, reg_param_index, bt, size;
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
    എങ്കിൽ (!using_regs(size)) {
        gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ശൂന്യ, addr);
        func_vc = addr;
        reg_param_index++;
        addr += 8;
    }

    /* define parameters */
    ആകുമ്പോൾ ((sym = sym->next) != ശൂന്യ) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        size = gfunc_arg_size(type);
        എങ്കിൽ (!using_regs(size)) {
            എങ്കിൽ (reg_param_index < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ശൂന്യ, addr);
            }
            gfunc_set_param(sym, addr, 1);
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (reg_param_index < REGN) {
                /* save arguments passed by register */
                എങ്കിൽ ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    എങ്കിൽ (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_index, VT_LOCAL, ശൂന്യ, addr);
                } അല്ലെങ്കിൽ {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ശൂന്യ, addr);
                }
            }
            gfunc_set_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_index++;
    }

    ആകുമ്പോൾ (reg_param_index < REGN) {
        എങ്കിൽ (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ശൂന്യ, addr);
            addr += 8;
        }
        reg_param_index++;
    }
#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
ശൂന്യം gfunc_epilog(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ v, start;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    o(0xc9); /* leave */
    എങ്കിൽ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } അല്ലെങ്കിൽ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    start = func_sub_sp_offset - FUNC_PROLOG_SIZE;
    cur_text_section->data_offset = ind;
    pe_add_unwind_data(start, ind, v);

    ind = start;
    എങ്കിൽ (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } അല്ലെങ്കിൽ {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_text_section->data_offset;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#അല്ലെങ്കിൽ

സ്ഥിതം ശൂന്യം gadd_sp(പൂർണ്ണസംഖ്യ val)
{
    എങ്കിൽ (val == (signed അക്ഷരം)val) {
        o(0xc48348);
        g(val);
    } അല്ലെങ്കിൽ {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

തരനിർവചനം എണ്ണൽ X86_64_Mode {
  x86_64_mode_none,
  x86_64_mode_memory,
  x86_64_mode_integer,
  x86_64_mode_sse,
  x86_64_mode_x87
} X86_64_Mode;

സ്ഥിതം X86_64_Mode classify_x86_64_merge(X86_64_Mode a, X86_64_Mode b)
{
    എങ്കിൽ (a == b)
        തിരികെ a;
    അല്ലെങ്കിൽ എങ്കിൽ (a == x86_64_mode_none)
        തിരികെ b;
    അല്ലെങ്കിൽ എങ്കിൽ (b == x86_64_mode_none)
        തിരികെ a;
    അല്ലെങ്കിൽ എങ്കിൽ ((a == x86_64_mode_memory) || (b == x86_64_mode_memory))
        തിരികെ x86_64_mode_memory;
    അല്ലെങ്കിൽ എങ്കിൽ ((a == x86_64_mode_integer) || (b == x86_64_mode_integer))
        തിരികെ x86_64_mode_integer;
    അല്ലെങ്കിൽ എങ്കിൽ ((a == x86_64_mode_x87) || (b == x86_64_mode_x87))
        തിരികെ x86_64_mode_memory;
    അല്ലെങ്കിൽ
        തിരികെ x86_64_mode_sse;
}

സ്ഥിതം X86_64_Mode classify_x86_64_inner(CType *ty)
{
    X86_64_Mode mode;
    Sym *f;
    
    തിരഞ്ഞെടുപ്പ് (ty->t & VT_BTYPE) {
    അവസ്ഥ VT_VOID: തിരികെ x86_64_mode_none;
    
    അവസ്ഥ VT_INT:
    അവസ്ഥ VT_BYTE:
    അവസ്ഥ VT_SHORT:
    അവസ്ഥ VT_LLONG:
    അവസ്ഥ VT_BOOL:
    അവസ്ഥ VT_PTR:
    അവസ്ഥ VT_FUNC:
        തിരികെ x86_64_mode_integer;
    
    അവസ്ഥ VT_FLOAT:
    അവസ്ഥ VT_DOUBLE: തിരികെ x86_64_mode_sse;
    
    അവസ്ഥ VT_LDOUBLE: തിരികെ x86_64_mode_x87;
      
    അവസ്ഥ VT_STRUCT:
        f = ty->ref;

        mode = x86_64_mode_none;
        വേണ്ടി (f = f->next; f; f = f->next)
            mode = classify_x86_64_merge(mode, classify_x86_64_inner(&f->type));
        
        തിരികെ mode;
    }
    പ്രതിജ്ഞാ(0);
    തിരികെ 0;
}

സ്ഥിതം X86_64_Mode classify_x86_64_arg(CType *ty, CType *ret, പൂർണ്ണസംഖ്യ *psize, പൂർണ്ണസംഖ്യ *palign, പൂർണ്ണസംഖ്യ *reg_എണ്ണം)
{
    X86_64_Mode mode;
    പൂർണ്ണസംഖ്യ size, align, ret_t = 0;
    
    എങ്കിൽ (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_എണ്ണം = 1;
        ret_t = ty->t;
        mode = x86_64_mode_integer;
    } അല്ലെങ്കിൽ {
        size = type_size(ty, &align);
        *psize = (size + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_എണ്ണം = 0; /* avoid compiler warning */

        എങ്കിൽ (size > 16) {
            mode = x86_64_mode_memory;
        } അല്ലെങ്കിൽ {
            mode = classify_x86_64_inner(ty);
            തിരഞ്ഞെടുപ്പ് (mode) {
            അവസ്ഥ x86_64_mode_integer:
                എങ്കിൽ (size > 8) {
                    *reg_എണ്ണം = 2;
                    ret_t = VT_QLONG;
                } അല്ലെങ്കിൽ {
                    *reg_എണ്ണം = 1;
                    എങ്കിൽ (size > 4)
                        ret_t = VT_LLONG;
                    അല്ലെങ്കിൽ എങ്കിൽ (size > 2)
                        ret_t = VT_INT;
                    അല്ലെങ്കിൽ എങ്കിൽ (size > 1)
                        ret_t = VT_SHORT;
                    അല്ലെങ്കിൽ
                        ret_t = VT_BYTE;
                    എങ്കിൽ ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                നിർത്തുക;
                
            അവസ്ഥ x86_64_mode_x87:
                *reg_എണ്ണം = 1;
                ret_t = VT_LDOUBLE;
                നിർത്തുക;

            അവസ്ഥ x86_64_mode_sse:
                എങ്കിൽ (size > 8) {
                    *reg_എണ്ണം = 2;
                    ret_t = VT_QFLOAT;
                } അല്ലെങ്കിൽ {
                    *reg_എണ്ണം = 1;
                    ret_t = (size > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                നിർത്തുക;
            സ്ഥിരസ്ഥിതി: നിർത്തുക; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    എങ്കിൽ (ret) {
        ret->ref = ശൂന്യ;
        ret->t = ret_t;
    }
    
    തിരികെ mode;
}

ST_FUNC പൂർണ്ണസംഖ്യ classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    എണ്ണൽ __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    പൂർണ്ണസംഖ്യ size, align, reg_എണ്ണം;
    X86_64_Mode mode = classify_x86_64_arg(ty, ശൂന്യ, &size, &align, &reg_എണ്ണം);
    തിരഞ്ഞെടുപ്പ് (mode) {
    സ്ഥിരസ്ഥിതി: തിരികെ __va_stack;
    അവസ്ഥ x86_64_mode_integer: തിരികെ __va_gen_reg;
    അവസ്ഥ x86_64_mode_sse: തിരികെ __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC പൂർണ്ണസംഖ്യ gfunc_sret(CType *vt, പൂർണ്ണസംഖ്യ variadic, CType *ret, പൂർണ്ണസംഖ്യ *ret_align, പൂർണ്ണസംഖ്യ *regsize)
{
    പൂർണ്ണസംഖ്യ size, align, reg_എണ്ണം;
    എങ്കിൽ (classify_x86_64_arg(vt, ret, &size, &align, &reg_എണ്ണം) == x86_64_mode_memory)
        തിരികെ 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_എണ്ണം; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    തിരികെ 1;
}

#define REGN 6
സ്ഥിതം സ്ഥിരം uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

സ്ഥിതം പൂർണ്ണസംഖ്യ arg_prepare_reg(പൂർണ്ണസംഖ്യ idx) {
  എങ്കിൽ (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      തിരികെ idx + 8;
  അല്ലെങ്കിൽ
      തിരികെ idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ശൂന്യം gfunc_call(പൂർണ്ണസംഖ്യ nb_args)
{
    X86_64_Mode mode;
    CType type;
    പൂർണ്ണസംഖ്യ size, align, r, args_size, അട്ടി_adjust, i, reg_എണ്ണം, k;
    പൂർണ്ണസംഖ്യ nb_reg_args = 0;
    പൂർണ്ണസംഖ്യ nb_sse_args = 0;
    പൂർണ്ണസംഖ്യ sse_reg, gen_reg;
    അക്ഷരം *onstack = tcc_malloc((nb_args + 1) * വലുപ്പം (അക്ഷരം));

#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    അട്ടി_adjust = 0;
    വേണ്ടി(i = nb_args - 1; i >= 0; i--) {
        mode = classify_x86_64_arg(&vtop[-i].type, ശൂന്യ, &size, &align, &reg_എണ്ണം);
        എങ്കിൽ (size == 0) തുടരുക;
        എങ്കിൽ (mode == x86_64_mode_sse && nb_sse_args + reg_എണ്ണം <= 8) {
            nb_sse_args += reg_എണ്ണം;
	    onstack[i] = 0;
	} അല്ലെങ്കിൽ എങ്കിൽ (mode == x86_64_mode_integer && nb_reg_args + reg_എണ്ണം <= REGN) {
            nb_reg_args += reg_എണ്ണം;
	    onstack[i] = 0;
	} അല്ലെങ്കിൽ എങ്കിൽ (mode == x86_64_mode_none) {
	    onstack[i] = 0;
	} അല്ലെങ്കിൽ {
	    എങ്കിൽ (align == 16 && (അട്ടി_adjust &= 15)) {
		onstack[i] = 2;
		അട്ടി_adjust = 0;
	    } അല്ലെങ്കിൽ
	      onstack[i] = 1;
	    അട്ടി_adjust += size;
	}
    }

    എങ്കിൽ (nb_sse_args && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_args;
    sse_reg = nb_sse_args;
    args_size = 0;
    അട്ടി_adjust &= 15;
    വേണ്ടി (i = k = 0; i < nb_args;) {
	mode = classify_x86_64_arg(&vtop[-i].type, ശൂന്യ, &size, &align, &reg_എണ്ണം);
	എങ്കിൽ (size) {
            എങ്കിൽ (!onstack[i + k]) {
	        ++i;
	        തുടരുക;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            എങ്കിൽ (അട്ടി_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                args_size += 8;
	        അട്ടി_adjust = 0;
            }
	    എങ്കിൽ (onstack[i + k] == 2)
	        അട്ടി_adjust = 1;
        }

	vrotb(i+1);

	തിരഞ്ഞെടുപ്പ് (vtop->type.t & VT_BTYPE) {
	    അവസ്ഥ VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, size); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_മൂല്യം(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_മൂല്യം(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		നിർത്തുക;

	    അവസ്ഥ VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, size); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		നിർത്തുക;

	    അവസ്ഥ VT_FLOAT:
	    അവസ്ഥ VT_DOUBLE:
		പ്രതിജ്ഞാ(mode == x86_64_mode_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_മൂല്യം(r)*8);
		o(0x24);
		നിർത്തുക;

	    സ്ഥിരസ്ഥിതി:
		പ്രതിജ്ഞാ(mode == x86_64_mode_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_മൂല്യം(r)); /* push r */
		നിർത്തുക;
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
    പ്രതിജ്ഞാ(gen_reg <= REGN);
    പ്രതിജ്ഞാ(sse_reg <= 8);
    വേണ്ടി(i = 0; i < nb_args; i++) {
        mode = classify_x86_64_arg(&vtop->type, &type, &size, &align, &reg_എണ്ണം);
        എങ്കിൽ (size == 0) തുടരുക;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        എങ്കിൽ (mode == x86_64_mode_sse) {
            എങ്കിൽ (reg_എണ്ണം == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                എങ്കിൽ (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } അല്ലെങ്കിൽ {
                പ്രതിജ്ഞാ(reg_എണ്ണം == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (mode == x86_64_mode_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            പൂർണ്ണസംഖ്യ d;
            gen_reg -= reg_എണ്ണം;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_മൂല്യം(r) * 8 + REG_മൂല്യം(d));
            എങ്കിൽ (reg_എണ്ണം == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_മൂല്യം(vtop->r2) * 8 + REG_മൂല്യം(d));
            }
        }
        vtop--;
    }
    പ്രതിജ്ഞാ(gen_reg == 0);
    പ്രതിജ്ഞാ(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    എങ്കിൽ (nb_reg_args > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        എങ്കിൽ (nb_reg_args > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    എങ്കിൽ (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_args < 8 ? nb_sse_args : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    എങ്കിൽ (args_size)
        gadd_sp(args_size);
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

സ്ഥിതം ശൂന്യം തള്ളുക_arg_reg(പൂർണ്ണസംഖ്യ i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, ശൂന്യ, loc);
}

/* generate function prolog of type 't' */
ശൂന്യം gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_Mode mode, ret_mode;
    പൂർണ്ണസംഖ്യ i, addr, align, size, reg_എണ്ണം;
    പൂർണ്ണസംഖ്യ param_addr = 0, reg_param_index, sse_param_index;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_SIZE * 2;
    loc = 0;
    ind += FUNC_PROLOG_SIZE;
    func_sub_sp_offset = ind;
    func_ret_sub = 0;
    ret_mode = classify_x86_64_arg(&func_vt, ശൂന്യ, &size, &align, &reg_എണ്ണം);

    എങ്കിൽ (func_var) {
        പൂർണ്ണസംഖ്യ seen_reg_അക്കം, seen_sse_അക്കം, seen_അട്ടി_size;
        seen_reg_അക്കം = ret_mode == x86_64_mode_memory;
        seen_sse_അക്കം = 0;
        /* frame pointer and return address */
        seen_അട്ടി_size = PTR_SIZE * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        ആകുമ്പോൾ ((sym = sym->next) != ശൂന്യ) {
            type = &sym->type;
            mode = classify_x86_64_arg(type, ശൂന്യ, &size, &align, &reg_എണ്ണം);
            തിരഞ്ഞെടുപ്പ് (mode) {
            സ്ഥിരസ്ഥിതി:
            അട്ടി_arg:
                seen_അട്ടി_size = ((seen_അട്ടി_size + align - 1) & -align) + size;
                നിർത്തുക;
                
            അവസ്ഥ x86_64_mode_integer:
                എങ്കിൽ (seen_reg_അക്കം + reg_എണ്ണം > REGN)
		    പോകുക അട്ടി_arg;
		seen_reg_അക്കം += reg_എണ്ണം;
                നിർത്തുക;
                
            അവസ്ഥ x86_64_mode_sse:
                എങ്കിൽ (seen_sse_അക്കം + reg_എണ്ണം > 8)
		    പോകുക അട്ടി_arg;
		seen_sse_അക്കം += reg_എണ്ണം;
                നിർത്തുക;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(seen_reg_അക്കം * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(seen_sse_അക്കം * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(seen_അട്ടി_size);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        വേണ്ടി (i = 0; i < 8; i++) {
            loc -= 16;
	    എങ്കിൽ (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, ശൂന്യ, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        വേണ്ടി (i = 0; i < REGN; i++) {
            തള്ളുക_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_index = 0;
    sse_param_index = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    എങ്കിൽ (ret_mode == x86_64_mode_memory) {
        തള്ളുക_arg_reg(reg_param_index);
        func_vc = loc;
        reg_param_index++;
    }
    /* define parameters */
    ആകുമ്പോൾ ((sym = sym->next) != ശൂന്യ) {
        type = &sym->type;
        mode = classify_x86_64_arg(type, ശൂന്യ, &size, &align, &reg_എണ്ണം);
        തിരഞ്ഞെടുപ്പ് (mode) {
        അവസ്ഥ x86_64_mode_sse:
	    എങ്കിൽ (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            എങ്കിൽ (sse_param_index + reg_എണ്ണം <= 8) {
                /* save arguments passed by register */
                loc -= reg_എണ്ണം * 8;
                param_addr = loc;
                വേണ്ടി (i = 0; i < reg_എണ്ണം; ++i) {
                    gen_modrm32(0xd60f66, sse_param_index, VT_LOCAL, ശൂന്യ, param_addr + i*8);
                    ++sse_param_index;
                }
            } അല്ലെങ്കിൽ {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            നിർത്തുക;
            
        അവസ്ഥ x86_64_mode_memory:
        അവസ്ഥ x86_64_mode_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += size;
            നിർത്തുക;
            
        അവസ്ഥ x86_64_mode_integer: {
            എങ്കിൽ (reg_param_index + reg_എണ്ണം <= REGN) {
                /* save arguments passed by register */
                loc -= reg_എണ്ണം * 8;
                param_addr = loc;
                വേണ്ടി (i = 0; i < reg_എണ്ണം; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, ശൂന്യ, param_addr + i*8);
                    ++reg_param_index;
                }
            } അല്ലെങ്കിൽ {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            നിർത്തുക;
        }
	സ്ഥിരസ്ഥിതി: നിർത്തുക; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_set_param(sym, param_addr, 0);
    }

#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
ശൂന്യം gfunc_epilog(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ v, saved_ind;

#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif
    o(0xc9); /* leave */
    എങ്കിൽ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } അല്ലെങ്കിൽ {
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

ST_FUNC ശൂന്യം gen_fill_nops(പൂർണ്ണസംഖ്യ bytes)
{
    ആകുമ്പോൾ (bytes--)
      g(0x90);
}

/* generate a jump to a label */
പൂർണ്ണസംഖ്യ gjmp(പൂർണ്ണസംഖ്യ t)
{
    തിരികെ gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ശൂന്യം gjmp_addr(പൂർണ്ണസംഖ്യ a)
{
    പൂർണ്ണസംഖ്യ r;
    r = a - ind - 2;
    എങ്കിൽ (r == (signed അക്ഷരം)r) {
        g(0xeb);
        g(r);
    } അല്ലെങ്കിൽ {
        oad(0xe9, a - ind - 5);
    }
}

ST_FUNC പൂർണ്ണസംഖ്യ gjmp_append(പൂർണ്ണസംഖ്യ n, പൂർണ്ണസംഖ്യ t)
{
    ശൂന്യം *p;
    /* insert vtop->c jump list in t */
    എങ്കിൽ (n) {
        uint32_t n1 = n, n2;
        ആകുമ്പോൾ ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    തിരികെ t;
}

ST_FUNC പൂർണ്ണസംഖ്യ gjmp_cond(പൂർണ്ണസംഖ്യ op, പൂർണ്ണസംഖ്യ t)
{
        എങ്കിൽ (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            പൂർണ്ണസംഖ്യ v = vtop->cmp_r;
            op &= ~0x100;
            എങ്കിൽ (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    അല്ലെങ്കിൽ
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        തിരികെ t;
}

/* generate an integer binary operation */
ശൂന്യം gen_opi(പൂർണ്ണസംഖ്യ op)
{
    പൂർണ്ണസംഖ്യ r, fr, opc, c;
    പൂർണ്ണസംഖ്യ ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    തിരഞ്ഞെടുപ്പ്(op) {
    അവസ്ഥ '+':
    അവസ്ഥ TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        എങ്കിൽ (cc && (!ll || (പൂർണ്ണസംഖ്യ)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            എങ്കിൽ (c == (signed അക്ഷരം)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_മൂല്യം(r));
                g(c);
            } അല്ലെങ്കിൽ {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_മൂല്യം(r), c);
            }
        } അല്ലെങ്കിൽ {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_മൂല്യം(r) + REG_മൂല്യം(fr) * 8);
        }
        vtop--;
        എങ്കിൽ (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        നിർത്തുക;
    അവസ്ഥ '-':
    അവസ്ഥ TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        പോകുക gen_op8;
    അവസ്ഥ TOK_ADDC2: /* add with carry use */
        opc = 2;
        പോകുക gen_op8;
    അവസ്ഥ TOK_SUBC2: /* sub with carry use */
        opc = 3;
        പോകുക gen_op8;
    അവസ്ഥ '&':
        opc = 4;
        പോകുക gen_op8;
    അവസ്ഥ '^':
        opc = 6;
        പോകുക gen_op8;
    അവസ്ഥ '|':
        opc = 1;
        പോകുക gen_op8;
    അവസ്ഥ '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_മൂല്യം(fr) + REG_മൂല്യം(r) * 8);
        vtop--;
        നിർത്തുക;
    അവസ്ഥ TOK_SHL:
        opc = 4;
        പോകുക gen_shift;
    അവസ്ഥ TOK_SHR:
        opc = 5;
        പോകുക gen_shift;
    അവസ്ഥ TOK_SAR:
        opc = 7;
    gen_shift:
        opc = 0xc0 | (opc << 3);
        എങ്കിൽ (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_മൂല്യം(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } അല്ലെങ്കിൽ {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_മൂല്യം(r));
        }
        vtop--;
        നിർത്തുക;
    അവസ്ഥ TOK_UDIV:
    അവസ്ഥ TOK_UMOD:
        uu = 1;
        പോകുക divmod;
    അവസ്ഥ '/':
    അവസ്ഥ '%':
    അവസ്ഥ TOK_PDIV:
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
        o((uu ? 0xf0 : 0xf8) + REG_മൂല്യം(fr));
        എങ്കിൽ (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        അല്ലെങ്കിൽ
            r = TREG_RAX;
        vtop->r = r;
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        opc = 7;
        പോകുക gen_op8;
    }
}

ശൂന്യം gen_opl(പൂർണ്ണസംഖ്യ op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ശൂന്യം gen_opf(പൂർണ്ണസംഖ്യ op)
{
    പൂർണ്ണസംഖ്യ a, ft, fc, swapped, r, opc;
    പൂർണ്ണസംഖ്യ bt = vtop->type.t & VT_BTYPE;
    പൂർണ്ണസംഖ്യ float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    എങ്കിൽ (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        എങ്കിൽ (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } അല്ലെങ്കിൽ {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, ശൂന്യ, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        തിരികെ;
    }

    /* convert constants to memory references */
    എങ്കിൽ ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    എങ്കിൽ ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    എങ്കിൽ ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    എങ്കിൽ (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    എങ്കിൽ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        എങ്കിൽ (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            load(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            എങ്കിൽ (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            അല്ലെങ്കിൽ എങ്കിൽ (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            എങ്കിൽ (swapped)
                o(0xc9d9); /* fxch %st(1) */
            എങ്കിൽ (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            അല്ലെങ്കിൽ
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            എങ്കിൽ (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } അല്ലെങ്കിൽ എങ്കിൽ (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } അല്ലെങ്കിൽ എങ്കിൽ (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } അല്ലെങ്കിൽ {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } അല്ലെങ്കിൽ {
            /* no memory reference possible for long double operations */
            load(TREG_ST0, vtop);
            swapped = !swapped;

            തിരഞ്ഞെടുപ്പ്(op) {
            സ്ഥിരസ്ഥിതി:
            അവസ്ഥ '+':
                a = 0;
                നിർത്തുക;
            അവസ്ഥ '-':
                a = 4;
                എങ്കിൽ (swapped)
                    a++;
                നിർത്തുക;
            അവസ്ഥ '*':
                a = 1;
                നിർത്തുക;
            അവസ്ഥ '/':
                a = 6;
                എങ്കിൽ (swapped)
                    a++;
                നിർത്തുക;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            എങ്കിൽ ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = ശൂന്യ;
                load(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            എങ്കിൽ (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } അല്ലെങ്കിൽ {
                എങ്കിൽ (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                എങ്കിൽ (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } അല്ലെങ്കിൽ {
                    op = 0x97; /* seta */
                }
            }

            എങ്കിൽ (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            പ്രതിജ്ഞാ(!(vtop[-1].r & VT_LVAL));
            
            എങ്കിൽ (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            അല്ലെങ്കിൽ
                opc = 0x2f0f; /* comisd */
            എങ്കിൽ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } അല്ലെങ്കിൽ {
            പ്രതിജ്ഞാ((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            തിരഞ്ഞെടുപ്പ്(op) {
            സ്ഥിരസ്ഥിതി:
            അവസ്ഥ '+':
                a = 0;
                നിർത്തുക;
            അവസ്ഥ '-':
                a = 4;
                നിർത്തുക;
            അവസ്ഥ '*':
                a = 1;
                നിർത്തുക;
            അവസ്ഥ '/':
                a = 6;
                നിർത്തുക;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            പ്രതിജ്ഞാ((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            എങ്കിൽ ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = ശൂന്യ;
                load(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            പ്രതിജ്ഞാ(!(vtop[-1].r & VT_LVAL));
            എങ്കിൽ (swapped) {
                പ്രതിജ്ഞാ(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            എങ്കിൽ ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } അല്ലെങ്കിൽ {
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
ശൂന്യം gen_cvt_itof(പൂർണ്ണസംഖ്യ t)
{
    എങ്കിൽ ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        എങ്കിൽ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } അല്ലെങ്കിൽ എങ്കിൽ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } അല്ലെങ്കിൽ {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } അല്ലെങ്കിൽ {
        പൂർണ്ണസംഖ്യ r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        എങ്കിൽ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_മൂല്യം(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
ശൂന്യം gen_cvt_ftof(പൂർണ്ണസംഖ്യ t)
{
    പൂർണ്ണസംഖ്യ ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    എങ്കിൽ (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        എങ്കിൽ (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_മൂല്യം(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_മൂല്യം(vtop->r)*9);
        } അല്ലെങ്കിൽ എങ്കിൽ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_മൂല്യം(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        എങ്കിൽ (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_മൂല്യം(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_മൂല്യം(vtop->r)*9);
        } അല്ലെങ്കിൽ എങ്കിൽ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_മൂല്യം(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } അല്ലെങ്കിൽ {
        പൂർണ്ണസംഖ്യ r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        എങ്കിൽ (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_മൂല്യം(r)*8);
            o(0xf024);
            vtop->r = r;
        } അല്ലെങ്കിൽ എങ്കിൽ (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_മൂല്യം(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
ശൂന്യം gen_cvt_ftoi(പൂർണ്ണസംഖ്യ t)
{
    പൂർണ്ണസംഖ്യ ft, bt, size, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    എങ്കിൽ (bt == VT_LDOUBLE) {
	എങ്കിൽ (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    തിരികെ;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    എങ്കിൽ (t != VT_INT)
        size = 8;
    അല്ലെങ്കിൽ
        size = 4;

    r = get_reg(RC_INT);
    എങ്കിൽ (bt == VT_FLOAT) {
        o(0xf3);
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_DOUBLE) {
        o(0xf2);
    } അല്ലെങ്കിൽ {
        പ്രതിജ്ഞാ(0);
    }
    orex(size == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_മൂല്യം(vtop->r) + REG_മൂല്യം(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC ശൂന്യം gen_cvt_sxtw(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_മൂല്യം(r) << 3) + REG_മൂല്യം(r));
}

/* char/short to int conversion */
ST_FUNC ശൂന്യം gen_cvt_csti(പൂർണ്ണസംഖ്യ t)
{
    പൂർണ്ണസംഖ്യ r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_മൂല്യം(r) << 3 | REG_മൂല്യം(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC ശൂന്യം gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_text_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC ശൂന്യം ggoto(ശൂന്യം)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC ശൂന്യം gen_vla_sp_save(പൂർണ്ണസംഖ്യ addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, ശൂന്യ, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC ശൂന്യം gen_vla_sp_restore(പൂർണ്ണസംഖ്യ addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, ശൂന്യ, addr);
}

#ifdef TCC_TARGET_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC ശൂന്യം gen_vla_result(പൂർണ്ണസംഖ്യ addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, ശൂന്യ, addr);
}
#endif

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC ശൂന്യം gen_vla_alloc(CType *type, പൂർണ്ണസംഖ്യ align) {
    പൂർണ്ണസംഖ്യ use_call = 0;

#എങ്കിൽ defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#endif
#ifdef TCC_TARGET_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#endif
    എങ്കിൽ (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    അല്ലെങ്കിൽ {
        പൂർണ്ണസംഖ്യ r;
        r = gv(RC_INT); /* allocation size */
        /* sub r,%rsp */
        o(0x2b48);
        o(0xe0 | REG_മൂല്യം(r));
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
ST_FUNC ശൂന്യം gen_struct_copy(പൂർണ്ണസംഖ്യ size)
{
    പൂർണ്ണസംഖ്യ n = size / PTR_SIZE;
#ifdef TCC_TARGET_PE
    o(0x5756); /* push rsi, rdi */
#endif
    gv2(RC_RDI, RC_RSI);
    എങ്കിൽ (n <= 4) {
        ആകുമ്പോൾ (n)
            o(0xa548), --n;
    } അല്ലെങ്കിൽ {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    എങ്കിൽ (size & 0x04)
        o(0xa5);
    എങ്കിൽ (size & 0x02)
        o(0xa566);
    എങ്കിൽ (size & 0x01)
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
