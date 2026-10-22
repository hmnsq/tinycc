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

#جيڪڏهن_وصف_ٿيل هدف_DEFS_ONLY

/* number of available registers */
#وصف_ڪريو NB_REGS         25
#وصف_ڪريو NB_ASM_REGS     16
#وصف_ڪريو CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#وصف_ڪريو RC_INT     0x0001 /* generic integer register */
#وصف_ڪريو RC_FLOAT   0x0002 /* generic float register */
#وصف_ڪريو RC_RAX     0x0004
#وصف_ڪريو RC_RDX     0x0008
#وصف_ڪريو RC_RCX     0x0010
#وصف_ڪريو RC_RSI     0x0020
#وصف_ڪريو RC_RDI     0x0040
#وصف_ڪريو RC_ST0     0x0080 /* only for long double */
#وصف_ڪريو RC_R8      0x0100
#وصف_ڪريو RC_R9      0x0200
#وصف_ڪريو RC_R10     0x0400
#وصف_ڪريو RC_R11     0x0800
#وصف_ڪريو RC_XMM0    0x1000
#وصف_ڪريو RC_XMM1    0x2000
#وصف_ڪريو RC_XMM2    0x4000
#وصف_ڪريو RC_XMM3    0x8000
#وصف_ڪريو RC_XMM4    0x10000
#وصف_ڪريو RC_XMM5    0x20000
#وصف_ڪريو RC_XMM6    0x40000
#وصف_ڪريو RC_XMM7    0x80000
#وصف_ڪريو RC_IRET    RC_RAX /* function return: integer register */
#وصف_ڪريو RC_IRE2    RC_RDX /* function return: second integer register */
#وصف_ڪريو RC_FRET    RC_XMM0 /* function return: float register */
#وصف_ڪريو RC_FRE2    RC_XMM1 /* function return: second float register */

/* pretty names for the registers */
تعداد {
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

#وصف_ڪريو REX_بنياد(reg) (((reg) >> 3) & 1)
#وصف_ڪريو REG_قدر(reg) ((reg) & 7)

/* return registers for function */
#وصف_ڪريو REG_IRET TREG_RAX /* single word int return register */
#وصف_ڪريو REG_IRE2 TREG_RDX /* second word return register (for long long) */
#وصف_ڪريو REG_FRET TREG_XMM0 /* float return register */
#وصف_ڪريو REG_FRE2 TREG_XMM1 /* second float return register */

/* defined if function parameters must be evaluated in reverse order */
#وصف_ڪريو INVERT_FUNC_PARAMS

/* pointer size, in bytes */
#وصف_ڪريو PTR_سائيز 8

/* long double size and alignment, in bytes */
#وصف_ڪريو LDOUBLE_سائيز  16
#وصف_ڪريو LDOUBLE_ALIGN 16
/* maximum alignment (for aligned attribute support) */
#وصف_ڪريو MAX_ALIGN     16

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#وصف_ڪريو PROMOTE_RET

#وصف_ڪريو TCC_هدف_NATIVE_STRUCT_COPY
ST_FUNC فراغ gen_struct_copy(صحيح سائيز);

/******************************************************/
#وإلا /* ! TARGET_DEFS_ONLY */
/******************************************************/
#وصف_ڪريو USING_GLOBALS
#ضمن "tcc.h"
#ضمن <assert.h>

ST_معلومات ثابت حرف * ثابت هدف_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_معلومات ثابت صحيح reg_classes[NB_REGS] = {
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

ساكن بنانشان ڊگهو func_sub_sp_وٿي;
ساكن صحيح func_ret_sub;

#إذا defined(CONFIG_TCC_BCHECK)
ساكن addr_t func_bound_وٿي;
ساكن بنانشان ڊگهو func_bound_ind;
ST_معلومات صحيح func_bound_جوڙيو_epilog;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
ساكن صحيح func_scratch, func_alloca;
#جيڪڏهن_پورو

/* XXX: make it faster ? */
ST_FUNC فراغ g(صحيح c)
{
    صحيح ind1;
    إذا (nocode_wanted)
        أرجع;
    ind1 = ind + 1;
    إذا (ind1 > cur_متن_section->معلومات_allocated)
        section_realloc(cur_متن_section, ind1);
    cur_متن_section->معلومات[ind] = c;
    ind = ind1;
}

ST_FUNC فراغ o(بنانشان صحيح c)
{
    طالما (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC فراغ gen_le16(صحيح v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC فراغ gen_le32(صحيح c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

ST_FUNC فراغ gen_le64(int64_t c)
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

ساكن فراغ orex(صحيح ll, صحيح r, صحيح r2, صحيح b)
{
    إذا ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    إذا ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    إذا (ll || REX_بنياد(r) || REX_بنياد(r2)) {
        إذا ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_بنياد(r) | (REX_بنياد(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC فراغ gsym_addr(صحيح t, صحيح a)
{
    طالما (t) {
        بنانشان حرف *ptr = cur_متن_section->معلومات + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

ساكن صحيح is64_type(صحيح t)
{
    أرجع ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
ساكن صحيح oad(صحيح c, صحيح s)
{
    صحيح t;
    إذا (nocode_wanted)
        أرجع s;
    o(c);
    t = ind;
    gen_le32(s);
    أرجع t;
}

/* generate jmp to a label */
#وصف_ڪريو gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC فراغ gen_addr32(صحيح r, Sym *sym, صحيح c)
{
    إذا (r & VT_SYM)
        greloca(cur_متن_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC فراغ gen_addrpc32(صحيح r, Sym *sym, صحيح c)
{
    إذا (r & VT_SYM)
        greloca(cur_متن_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
ساكن فراغ gen_gotpcrel(صحيح r, Sym *sym, صحيح c)
{
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, عدم), c, r,
        cur_متن_section->معلومات[ind-3],
        cur_متن_section->معلومات[ind-2],
        cur_متن_section->معلومات[ind-1]
        );
#جيڪڏهن_پورو
    greloca(cur_متن_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    إذا (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_قدر(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
ساكن فراغ gen_modrm_impl(صحيح opcode, صحيح ll, صحيح op_reg_0, صحيح r, Sym *sym, صحيح c)
{
    صحيح op_reg = REG_قدر(op_reg_0) << 3;

    إذا ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
        Sym *s2 = external_global_sym(TOK_tls_اشاريو, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_سائيز); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_متن_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#وإلا
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_متن_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#جيڪڏهن_پورو
        أرجع;
    }

    orex(ll, r, op_reg_0, opcode);

    إذا ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	إذا (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} وإلا {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    إذا (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } وإلا {
		gen_addrpc32(r, sym, c);
	    }
	}
    } وإلا إذا ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        إذا (c == (نشانوارو حرف)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } وإلا {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } وإلا إذا ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_قدر(r));
        gen_le32(c);
    } وإلا إذا (r & VT_LVAL) {
        g(0x00 | op_reg | REG_قدر(r));
    } وإلا {
        g(0xc0 | op_reg | REG_قدر(r));
    }
}

ساكن فراغ gen_modrm64(صحيح opcode, صحيح op_reg, صحيح r, Sym *sym, صحيح c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

ساكن فراغ gen_modrm32(صحيح opcode, صحيح op_reg, صحيح r, Sym *sym, صحيح c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
فراغ ڀريو(صحيح r, SValue *sv)
{
    صحيح v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    إذا (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#جيڪڏهن_وصف_نه_ٿيل TCC_هدف_PE
    /* we use indirect access via got */
    إذا ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        صحيح tr = r | TREG_MEM;
        إذا (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#جيڪڏهن_پورو

    v = fr & VT_VALMASK;
    إذا (fr & VT_LVAL) {
        صحيح b, ll;
        إذا (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = عدم;
            fr = r;
            إذا (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            ڀريو(fr, &v1);
            fr |= VT_LVAL;
        }
	إذا (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = عدم;
	    fr = r;
	    إذا (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    ڀريو(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	إذا ((ft & VT_BTYPE) == VT_STRUCT) {
	    صحيح align;
	    بدل (type_سائيز(&sv->type, &align)) {
		حالة 1: ft = VT_BYTE; اكسر;
		حالة 2: ft = VT_SHORT; اكسر;
		حالة 4: ft = VT_INT; اكسر;
		حالة 8: ft = VT_LLONG; اكسر;
		افتراضي:
		    tcc_error("invalid aggregate type for register load");
		    اكسر;
	    }
	}
        إذا ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_قدر(r); /* movd */
        } وإلا إذا ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_قدر(r);
        } وإلا إذا ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } وإلا إذا ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } وإلا إذا ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } وإلا إذا ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } وإلا إذا ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } وإلا إذا ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            أرجع;
        } وإلا {
            أكد(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } وإلا {
        إذا (v == VT_CONST) {
            إذا (fr & VT_SYM) {
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#وإلا
                إذا (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, عدم, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_قدر(r), 0);
                    greloca(cur_متن_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } وإلا إذا (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_قدر(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } وإلا {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_قدر(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#جيڪڏهن_پورو
            } وإلا إذا (is64_type(ft)) {
                إذا (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_قدر(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } وإلا إذا (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_قدر(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } وإلا {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_قدر(r) * 9);
                }
            } وإلا {
                orex(0,r,0, 0xb8 + REG_قدر(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } وإلا إذا (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } وإلا إذا (v == VT_CMP) {
	    إذا (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_قدر(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_بنياد(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_قدر(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_قدر(r) * 0x900); /* movzbl %al, %eax */
        } وإلا إذا (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_قدر(r), t); /* mov $1, r */
            o(0x05eb + (REX_بنياد(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_قدر(r), t ^ 1); /* mov $0, r */
        } وإلا إذا (v != r) {
            إذا ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                إذا (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_قدر(r)*8); /* %xmmN */
                    o(0xf024);
                } وإلا {
                    أكد((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    إذا ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } وإلا {
                        أكد((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_قدر(v) + REG_قدر(r)*8);
                }
            } وإلا إذا (r == TREG_ST0) {
                أكد((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_قدر(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } وإلا {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_قدر(r) + REG_قدر(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
فراغ store(صحيح r, SValue *v)
{
    صحيح fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    صحيح opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    إذا (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#جيڪڏهن_وصف_نه_ٿيل TCC_هدف_PE
    /* we need to access the variable via got */
    إذا ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#جيڪڏهن_پورو

    /* XXX: incorrect if float reg to reg */
    إذا (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_قدر(r);
    } وإلا إذا (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_قدر(r);
    } وإلا إذا (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } وإلا إذا (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } وإلا {
        opc = 0x89;
        إذا (bt == VT_SHORT)
            opc = 0x8966;
        وإلا إذا (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
ساكن فراغ gcall_or_jmp(صحيح is_jmp)
{
    صحيح r;
    إذا ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (صحيح)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_متن_section, vtop->sym, ind + 1, R_X86_64_PLT32, (صحيح)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } وإلا {
        /* otherwise, indirect call */
        r = TREG_R11;
        ڀريو(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_قدر(r) + (is_jmp << 4));
    }
}

#إذا defined(CONFIG_TCC_BCHECK)

ساكن فراغ gen_bounds_call(صحيح v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_متن_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
# define TREG_FASTCALL_1 TREG_RCX
#وإلا
# define TREG_FASTCALL_1 TREG_RDI
#جيڪڏهن_پورو

ساكن فراغ gen_bounds_prolog(فراغ)
{
    /* leave some room for bound checking code */
    func_bound_وٿي = lbounds_section->معلومات_وٿي;
    func_bound_ind = ind;
    func_bound_جوڙيو_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
}

ساكن فراغ gen_bounds_epilog(فراغ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_معلومات;
    صحيح وٿي_modified = func_bound_وٿي != lbounds_section->معلومات_وٿي;

    إذا (!وٿي_modified && !func_bound_جوڙيو_epilog)
        أرجع;

    /* add end of table info */
    bounds_ptr = section_ptr_جوڙيو(lbounds_section, حجم(addr_t));
    *bounds_ptr = 0;

    sym_معلومات = get_sym_ref(&char_اشارو_type, lbounds_section, 
                           func_bound_وٿي, PTR_سائيز);

    /* generate bound local allocation */
    إذا (وٿي_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        greloca(cur_متن_section, sym_معلومات, ind + 3, R_X86_64_PC32, -4);
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
    greloca(cur_متن_section, sym_معلومات, ind + 3, R_X86_64_PC32, -4);
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /* lea xxx(%rip), %rcx/rdi */
    gen_le32 (0);
    gen_bounds_call(TOK___bound_local_delete);
    o(0x280f);     /* movaps 0x10(%rsp),%xmm0 */
    o(0x102444);
    o(0x240c280f); /* movaps (%rsp),%xmm1 */
    o(0x20c48348); /* add $32,%rsp */
    o(0x585a); /* restore returned value, if any */
}
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل TCC_هدف_PE

#وصف_ڪريو REGN 4
ساكن ثابت uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
ساكن صحيح arg_prepare_reg(صحيح idx) {
  إذا (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      أرجع idx + 10;
  وإلا
      أرجع idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

ساكن فراغ gen_offs_sp(صحيح b, صحيح r, صحيح d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    إذا (d == (نشانوارو حرف)d) {
        o(0x2444 | (REG_قدر(r) << 3));
        g(d);
    } وإلا {
        o(0x2484 | (REG_قدر(r) << 3));
        gen_le32(d);
    }
}

ساكن صحيح using_regs(صحيح سائيز)
{
    أرجع !(سائيز > 8 || (سائيز & (سائيز - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret, صحيح *ret_align, صحيح *regsize)
{
    صحيح سائيز, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    سائيز = type_سائيز(vt, &align);
    إذا (!using_regs(سائيز))
        أرجع 0;
    إذا (سائيز == 8)
        ret->t = VT_LLONG;
    وإلا إذا (سائيز == 4)
        ret->t = VT_INT;
    وإلا إذا (سائيز == 2)
        ret->t = VT_SHORT;
    وإلا
        ret->t = VT_BYTE;
    ret->ref = عدم;
    أرجع 1;
}

ساكن صحيح is_sse_float(صحيح t) {
    صحيح bt;
    bt = t & VT_BTYPE;
    أرجع bt == VT_DOUBLE || bt == VT_FLOAT;
}

ساكن صحيح gfunc_arg_سائيز(CType *type) {
    صحيح align;
    إذا (type->t & (VT_ARRAY|VT_BITFIELD))
        أرجع 8;
    أرجع type_سائيز(type, &align);
}

فراغ gfunc_call(صحيح nb_دليلون)
{
    صحيح سائيز, r, دليلون_سائيز, i, d, bt, struct_سائيز;
    صحيح arg;

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gbound_دليلون(nb_دليلون);
#جيڪڏهن_پورو

    save_regs(nb_دليلون);

    دليلون_سائيز = (nb_دليلون < REGN ? REGN : nb_دليلون) * PTR_سائيز;
    arg = nb_دليلون;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_سائيز = دليلون_سائيز;
    لكل(i = 0; i < nb_دليلون; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        سائيز = gfunc_arg_سائيز(&sv->type);

        إذا (using_regs(سائيز))
            استمر; /* arguments smaller than 8 bytes passed in registers or on stack */

        إذا (bt == VT_STRUCT) {
            /* align to stack align size */
            سائيز = (سائيز + 15) & ~15;
            /* generate structure store */
            r = get_reg(RC_INT);
            gen_offs_sp(0x8d, r, struct_سائيز);
            struct_سائيز += سائيز;

            /* generate memcpy call */
            vset(&sv->type, r | VT_LVAL, 0);
            vpushv(sv);
            vstore();
            --vtop;
        } وإلا إذا (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_سائيز);
            struct_سائيز += 16;
        }
    }

    إذا (func_scratch < struct_سائيز)
        func_scratch = struct_سائيز;

    arg = nb_دليلون;
    struct_سائيز = دليلون_سائيز;

    لكل(i = 0; i < nb_دليلون; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        سائيز = gfunc_arg_سائيز(&vtop->type);
        إذا (!using_regs(سائيز)) {
            /* align to stack align size */
            سائيز = (سائيز + 15) & ~15;
            إذا (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_سائيز);
                gen_offs_sp(0x89, d, arg*8);
            } وإلا {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_سائيز);
            }
            struct_سائيز += سائيز;
        } وإلا {
            إذا (is_sse_float(vtop->type.t)) {
		إذا (tcc_state->nosse)
		  tcc_error("SSE disabled");
                إذا (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } وإلا {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_قدر(d));
                }
            } وإلا {
                إذا (bt == VT_STRUCT) {
                    vtop->type.ref = عدم;
                    vtop->type.t = سائيز > 4 ? VT_LLONG : سائيز > 2 ? VT_INT
                        : سائيز > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                إذا (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } وإلا {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_قدر(r) * 8 + REG_قدر(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    إذا (nb_دليلون > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        إذا (nb_دليلون > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    إذا ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
        إذا (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#جيڪڏهن_پورو
    }
    vtop--;
}

#وصف_ڪريو FUNC_PROLOG_سائيز 11

/* generate function prolog of type 't' */
فراغ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    صحيح addr, reg_param_اشاريو, bt, سائيز;
    Sym *sym;
    CType *type;

    func_ret_sub = 0;
    func_scratch = 32;
    func_alloca = 0;
    loc = 0;

    addr = PTR_سائيز * 2;
    ind += FUNC_PROLOG_سائيز;
    func_sub_sp_وٿي = ind;
    reg_param_اشاريو = 0;

    sym = func_type->ref;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    سائيز = gfunc_arg_سائيز(&func_vt);
    إذا (!using_regs(سائيز)) {
        gen_modrm64(0x89, arg_regs[reg_param_اشاريو], VT_LOCAL, عدم, addr);
        func_vc = addr;
        reg_param_اشاريو++;
        addr += 8;
    }

    /* define parameters */
    طالما ((sym = sym->ايندڙ) != عدم) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        سائيز = gfunc_arg_سائيز(type);
        إذا (!using_regs(سائيز)) {
            إذا (reg_param_اشاريو < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_اشاريو], VT_LOCAL, عدم, addr);
            }
            gfunc_سيٽ_param(sym, addr, 1);
        } وإلا {
            إذا (reg_param_اشاريو < REGN) {
                /* save arguments passed by register */
                إذا ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    إذا (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_اشاريو, VT_LOCAL, عدم, addr);
                } وإلا {
                    gen_modrm64(0x89, arg_regs[reg_param_اشاريو], VT_LOCAL, عدم, addr);
                }
            }
            gfunc_سيٽ_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_اشاريو++;
    }

    طالما (reg_param_اشاريو < REGN) {
        إذا (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_اشاريو], VT_LOCAL, عدم, addr);
            addr += 8;
        }
        reg_param_اشاريو++;
    }
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#جيڪڏهن_پورو
}

/* generate function epilog */
فراغ gfunc_epilog(فراغ)
{
    صحيح v, شروعات;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#جيڪڏهن_پورو

    o(0xc9); /* leave */
    إذا (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } وإلا {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    شروعات = func_sub_sp_وٿي - FUNC_PROLOG_سائيز;
    cur_متن_section->معلومات_وٿي = ind;
    pe_جوڙيو_unwind_معلومات(شروعات, ind, v);

    ind = شروعات;
    إذا (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_متن_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } وإلا {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_متن_section->معلومات_وٿي;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#وإلا

ساكن فراغ gadd_sp(صحيح val)
{
    إذا (val == (نشانوارو حرف)val) {
        o(0xc48348);
        g(val);
    } وإلا {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

تعريفنوع تعداد X86_64_گهڻائي {
  x86_64_گهڻائي_none,
  x86_64_گهڻائي_يادگيري,
  x86_64_گهڻائي_integer,
  x86_64_گهڻائي_sse,
  x86_64_گهڻائي_x87
} X86_64_گهڻائي;

ساكن X86_64_گهڻائي classify_x86_64_ملايو(X86_64_گهڻائي a, X86_64_گهڻائي b)
{
    إذا (a == b)
        أرجع a;
    وإلا إذا (a == x86_64_گهڻائي_none)
        أرجع b;
    وإلا إذا (b == x86_64_گهڻائي_none)
        أرجع a;
    وإلا إذا ((a == x86_64_گهڻائي_يادگيري) || (b == x86_64_گهڻائي_يادگيري))
        أرجع x86_64_گهڻائي_يادگيري;
    وإلا إذا ((a == x86_64_گهڻائي_integer) || (b == x86_64_گهڻائي_integer))
        أرجع x86_64_گهڻائي_integer;
    وإلا إذا ((a == x86_64_گهڻائي_x87) || (b == x86_64_گهڻائي_x87))
        أرجع x86_64_گهڻائي_يادگيري;
    وإلا
        أرجع x86_64_گهڻائي_sse;
}

ساكن X86_64_گهڻائي classify_x86_64_inner(CType *ty)
{
    X86_64_گهڻائي گهڻائي;
    Sym *f;
    
    بدل (ty->t & VT_BTYPE) {
    حالة VT_VOID: أرجع x86_64_گهڻائي_none;
    
    حالة VT_INT:
    حالة VT_BYTE:
    حالة VT_SHORT:
    حالة VT_LLONG:
    حالة VT_BOOL:
    حالة VT_PTR:
    حالة VT_FUNC:
        أرجع x86_64_گهڻائي_integer;
    
    حالة VT_FLOAT:
    حالة VT_DOUBLE: أرجع x86_64_گهڻائي_sse;
    
    حالة VT_LDOUBLE: أرجع x86_64_گهڻائي_x87;
      
    حالة VT_STRUCT:
        f = ty->ref;

        گهڻائي = x86_64_گهڻائي_none;
        لكل (f = f->ايندڙ; f; f = f->ايندڙ)
            گهڻائي = classify_x86_64_ملايو(گهڻائي, classify_x86_64_inner(&f->type));
        
        أرجع گهڻائي;
    }
    أكد(0);
    أرجع 0;
}

ساكن X86_64_گهڻائي classify_x86_64_arg(CType *ty, CType *ret, صحيح *psize, صحيح *palign, صحيح *reg_ڳڻپ)
{
    X86_64_گهڻائي گهڻائي;
    صحيح سائيز, align, ret_t = 0;
    
    إذا (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_ڳڻپ = 1;
        ret_t = ty->t;
        گهڻائي = x86_64_گهڻائي_integer;
    } وإلا {
        سائيز = type_سائيز(ty, &align);
        *psize = (سائيز + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_ڳڻپ = 0; /* avoid compiler warning */

        إذا (سائيز > 16) {
            گهڻائي = x86_64_گهڻائي_يادگيري;
        } وإلا {
            گهڻائي = classify_x86_64_inner(ty);
            بدل (گهڻائي) {
            حالة x86_64_گهڻائي_integer:
                إذا (سائيز > 8) {
                    *reg_ڳڻپ = 2;
                    ret_t = VT_QLONG;
                } وإلا {
                    *reg_ڳڻپ = 1;
                    إذا (سائيز > 4)
                        ret_t = VT_LLONG;
                    وإلا إذا (سائيز > 2)
                        ret_t = VT_INT;
                    وإلا إذا (سائيز > 1)
                        ret_t = VT_SHORT;
                    وإلا
                        ret_t = VT_BYTE;
                    إذا ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                اكسر;
                
            حالة x86_64_گهڻائي_x87:
                *reg_ڳڻپ = 1;
                ret_t = VT_LDOUBLE;
                اكسر;

            حالة x86_64_گهڻائي_sse:
                إذا (سائيز > 8) {
                    *reg_ڳڻپ = 2;
                    ret_t = VT_QFLOAT;
                } وإلا {
                    *reg_ڳڻپ = 1;
                    ret_t = (سائيز > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                اكسر;
            افتراضي: اكسر; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    إذا (ret) {
        ret->ref = عدم;
        ret->t = ret_t;
    }
    
    أرجع گهڻائي;
}

ST_FUNC صحيح classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    تعداد __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    صحيح سائيز, align, reg_ڳڻپ;
    X86_64_گهڻائي گهڻائي = classify_x86_64_arg(ty, عدم, &سائيز, &align, &reg_ڳڻپ);
    بدل (گهڻائي) {
    افتراضي: أرجع __va_stack;
    حالة x86_64_گهڻائي_integer: أرجع __va_gen_reg;
    حالة x86_64_گهڻائي_sse: أرجع __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret, صحيح *ret_align, صحيح *regsize)
{
    صحيح سائيز, align, reg_ڳڻپ;
    إذا (classify_x86_64_arg(vt, ret, &سائيز, &align, &reg_ڳڻپ) == x86_64_گهڻائي_يادگيري)
        أرجع 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_ڳڻپ; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    أرجع 1;
}

#وصف_ڪريو REGN 6
ساكن ثابت uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

ساكن صحيح arg_prepare_reg(صحيح idx) {
  إذا (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      أرجع idx + 8;
  وإلا
      أرجع idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
فراغ gfunc_call(صحيح nb_دليلون)
{
    X86_64_گهڻائي گهڻائي;
    CType type;
    صحيح سائيز, align, r, دليلون_سائيز, ڍير_adjust, i, reg_ڳڻپ, k;
    صحيح nb_reg_دليلون = 0;
    صحيح nb_sse_دليلون = 0;
    صحيح sse_reg, gen_reg;
    حرف *onstack = tcc_malloc((nb_دليلون + 1) * حجم (حرف));

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gbound_دليلون(nb_دليلون);
#جيڪڏهن_پورو

    save_regs(nb_دليلون);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    ڍير_adjust = 0;
    لكل(i = nb_دليلون - 1; i >= 0; i--) {
        گهڻائي = classify_x86_64_arg(&vtop[-i].type, عدم, &سائيز, &align, &reg_ڳڻپ);
        إذا (سائيز == 0) استمر;
        إذا (گهڻائي == x86_64_گهڻائي_sse && nb_sse_دليلون + reg_ڳڻپ <= 8) {
            nb_sse_دليلون += reg_ڳڻپ;
	    onstack[i] = 0;
	} وإلا إذا (گهڻائي == x86_64_گهڻائي_integer && nb_reg_دليلون + reg_ڳڻپ <= REGN) {
            nb_reg_دليلون += reg_ڳڻپ;
	    onstack[i] = 0;
	} وإلا إذا (گهڻائي == x86_64_گهڻائي_none) {
	    onstack[i] = 0;
	} وإلا {
	    إذا (align == 16 && (ڍير_adjust &= 15)) {
		onstack[i] = 2;
		ڍير_adjust = 0;
	    } وإلا
	      onstack[i] = 1;
	    ڍير_adjust += سائيز;
	}
    }

    إذا (nb_sse_دليلون && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_دليلون;
    sse_reg = nb_sse_دليلون;
    دليلون_سائيز = 0;
    ڍير_adjust &= 15;
    لكل (i = k = 0; i < nb_دليلون;) {
	گهڻائي = classify_x86_64_arg(&vtop[-i].type, عدم, &سائيز, &align, &reg_ڳڻپ);
	إذا (سائيز) {
            إذا (!onstack[i + k]) {
	        ++i;
	        استمر;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            إذا (ڍير_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                دليلون_سائيز += 8;
	        ڍير_adjust = 0;
            }
	    إذا (onstack[i + k] == 2)
	        ڍير_adjust = 1;
        }

	vrotb(i+1);

	بدل (vtop->type.t & VT_BTYPE) {
	    حالة VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, سائيز); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_قدر(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_قدر(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		اكسر;

	    حالة VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, سائيز); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		اكسر;

	    حالة VT_FLOAT:
	    حالة VT_DOUBLE:
		أكد(گهڻائي == x86_64_گهڻائي_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_قدر(r)*8);
		o(0x24);
		اكسر;

	    افتراضي:
		أكد(گهڻائي == x86_64_گهڻائي_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_قدر(r)); /* push r */
		اكسر;
	}
	دليلون_سائيز += سائيز;

	vpop();
	--nb_دليلون;
	k++;
    }

    tcc_free(onstack);

    /* then, we prepare register passing arguments.
       Note that we cannot set RDX and RCX in this loop because gv()
       may break these temporary registers. Let's use R10 and R11
       instead of them */
    أكد(gen_reg <= REGN);
    أكد(sse_reg <= 8);
    لكل(i = 0; i < nb_دليلون; i++) {
        گهڻائي = classify_x86_64_arg(&vtop->type, &type, &سائيز, &align, &reg_ڳڻپ);
        إذا (سائيز == 0) استمر;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        إذا (گهڻائي == x86_64_گهڻائي_sse) {
            إذا (reg_ڳڻپ == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                إذا (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } وإلا {
                أكد(reg_ڳڻپ == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } وإلا إذا (گهڻائي == x86_64_گهڻائي_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            صحيح d;
            gen_reg -= reg_ڳڻپ;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_قدر(r) * 8 + REG_قدر(d));
            إذا (reg_ڳڻپ == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_قدر(vtop->r2) * 8 + REG_قدر(d));
            }
        }
        vtop--;
    }
    أكد(gen_reg == 0);
    أكد(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    إذا (nb_reg_دليلون > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        إذا (nb_reg_دليلون > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    إذا (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_دليلون < 8 ? nb_sse_دليلون : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    إذا (دليلون_سائيز)
        gadd_sp(دليلون_سائيز);
    vtop--;
}

#وصف_ڪريو FUNC_PROLOG_سائيز 11

ساكن فراغ ڌڪو_arg_reg(صحيح i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, عدم, loc);
}

/* generate function prolog of type 't' */
فراغ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_گهڻائي گهڻائي, ret_گهڻائي;
    صحيح i, addr, align, سائيز, reg_ڳڻپ;
    صحيح param_addr = 0, reg_param_اشاريو, sse_param_اشاريو;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_سائيز * 2;
    loc = 0;
    ind += FUNC_PROLOG_سائيز;
    func_sub_sp_وٿي = ind;
    func_ret_sub = 0;
    ret_گهڻائي = classify_x86_64_arg(&func_vt, عدم, &سائيز, &align, &reg_ڳڻپ);

    إذا (func_var) {
        صحيح ڏٺل_reg_انگ, ڏٺل_sse_انگ, ڏٺل_ڍير_سائيز;
        ڏٺل_reg_انگ = ret_گهڻائي == x86_64_گهڻائي_يادگيري;
        ڏٺل_sse_انگ = 0;
        /* frame pointer and return address */
        ڏٺل_ڍير_سائيز = PTR_سائيز * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        طالما ((sym = sym->ايندڙ) != عدم) {
            type = &sym->type;
            گهڻائي = classify_x86_64_arg(type, عدم, &سائيز, &align, &reg_ڳڻپ);
            بدل (گهڻائي) {
            افتراضي:
            ڍير_arg:
                ڏٺل_ڍير_سائيز = ((ڏٺل_ڍير_سائيز + align - 1) & -align) + سائيز;
                اكسر;
                
            حالة x86_64_گهڻائي_integer:
                إذا (ڏٺل_reg_انگ + reg_ڳڻپ > REGN)
		    اذهب ڍير_arg;
		ڏٺل_reg_انگ += reg_ڳڻپ;
                اكسر;
                
            حالة x86_64_گهڻائي_sse:
                إذا (ڏٺل_sse_انگ + reg_ڳڻپ > 8)
		    اذهب ڍير_arg;
		ڏٺل_sse_انگ += reg_ڳڻپ;
                اكسر;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(ڏٺل_reg_انگ * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(ڏٺل_sse_انگ * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(ڏٺل_ڍير_سائيز);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        لكل (i = 0; i < 8; i++) {
            loc -= 16;
	    إذا (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, عدم, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        لكل (i = 0; i < REGN; i++) {
            ڌڪو_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_اشاريو = 0;
    sse_param_اشاريو = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    إذا (ret_گهڻائي == x86_64_گهڻائي_يادگيري) {
        ڌڪو_arg_reg(reg_param_اشاريو);
        func_vc = loc;
        reg_param_اشاريو++;
    }
    /* define parameters */
    طالما ((sym = sym->ايندڙ) != عدم) {
        type = &sym->type;
        گهڻائي = classify_x86_64_arg(type, عدم, &سائيز, &align, &reg_ڳڻپ);
        بدل (گهڻائي) {
        حالة x86_64_گهڻائي_sse:
	    إذا (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            إذا (sse_param_اشاريو + reg_ڳڻپ <= 8) {
                /* save arguments passed by register */
                loc -= reg_ڳڻپ * 8;
                param_addr = loc;
                لكل (i = 0; i < reg_ڳڻپ; ++i) {
                    gen_modrm32(0xd60f66, sse_param_اشاريو, VT_LOCAL, عدم, param_addr + i*8);
                    ++sse_param_اشاريو;
                }
            } وإلا {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += سائيز;
            }
            اكسر;
            
        حالة x86_64_گهڻائي_يادگيري:
        حالة x86_64_گهڻائي_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += سائيز;
            اكسر;
            
        حالة x86_64_گهڻائي_integer: {
            إذا (reg_param_اشاريو + reg_ڳڻپ <= REGN) {
                /* save arguments passed by register */
                loc -= reg_ڳڻپ * 8;
                param_addr = loc;
                لكل (i = 0; i < reg_ڳڻپ; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_اشاريو], VT_LOCAL, عدم, param_addr + i*8);
                    ++reg_param_اشاريو;
                }
            } وإلا {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += سائيز;
            }
            اكسر;
        }
	افتراضي: اكسر; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_سيٽ_param(sym, param_addr, 0);
    }

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#جيڪڏهن_پورو
}

/* generate function epilog */
فراغ gfunc_epilog(فراغ)
{
    صحيح v, saved_ind;

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#جيڪڏهن_پورو
    o(0xc9); /* leave */
    إذا (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } وإلا {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    /* align local size to word & save local variables */
    v = (-loc + 15) & -16;
    saved_ind = ind;
    ind = func_sub_sp_وٿي - FUNC_PROLOG_سائيز;
    o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
    o(0xec8148);  /* sub rsp, stacksize */
    gen_le32(v);
    ind = saved_ind;
}

#جيڪڏهن_پورو /* not PE */

ST_FUNC فراغ gen_fill_nops(صحيح بائيٽون)
{
    طالما (بائيٽون--)
      g(0x90);
}

/* generate a jump to a label */
صحيح gjmp(صحيح t)
{
    أرجع gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
فراغ gjmp_addr(صحيح a)
{
    صحيح r;
    r = a - ind - 2;
    إذا (r == (نشانوارو حرف)r) {
        g(0xeb);
        g(r);
    } وإلا {
        oad(0xe9, a - ind - 5);
    }
}

ST_FUNC صحيح gjmp_append(صحيح n, صحيح t)
{
    فراغ *p;
    /* insert vtop->c jump list in t */
    إذا (n) {
        uint32_t n1 = n, n2;
        طالما ((n2 = read32le(p = cur_متن_section->معلومات + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    أرجع t;
}

ST_FUNC صحيح gjmp_cond(صحيح op, صحيح t)
{
        إذا (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            صحيح v = vtop->cmp_r;
            op &= ~0x100;
            إذا (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    وإلا
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        أرجع t;
}

/* generate an integer binary operation */
فراغ gen_opi(صحيح op)
{
    صحيح r, fr, opc, c;
    صحيح ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    بدل(op) {
    حالة '+':
    حالة TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        إذا (cc && (!ll || (صحيح)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            إذا (c == (نشانوارو حرف)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_قدر(r));
                g(c);
            } وإلا {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_قدر(r), c);
            }
        } وإلا {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_قدر(r) + REG_قدر(fr) * 8);
        }
        vtop--;
        إذا (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        اكسر;
    حالة '-':
    حالة TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        اذهب gen_op8;
    حالة TOK_ADDC2: /* add with carry use */
        opc = 2;
        اذهب gen_op8;
    حالة TOK_SUBC2: /* sub with carry use */
        opc = 3;
        اذهب gen_op8;
    حالة '&':
        opc = 4;
        اذهب gen_op8;
    حالة '^':
        opc = 6;
        اذهب gen_op8;
    حالة '|':
        opc = 1;
        اذهب gen_op8;
    حالة '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_قدر(fr) + REG_قدر(r) * 8);
        vtop--;
        اكسر;
    حالة TOK_SHL:
        opc = 4;
        اذهب gen_سرڪايو;
    حالة TOK_SHR:
        opc = 5;
        اذهب gen_سرڪايو;
    حالة TOK_SAR:
        opc = 7;
    gen_سرڪايو:
        opc = 0xc0 | (opc << 3);
        إذا (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_قدر(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } وإلا {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_قدر(r));
        }
        vtop--;
        اكسر;
    حالة TOK_UDIV:
    حالة TOK_UMOD:
        uu = 1;
        اذهب divmod;
    حالة '/':
    حالة '%':
    حالة TOK_PDIV:
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
        o((uu ? 0xf0 : 0xf8) + REG_قدر(fr));
        إذا (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        وإلا
            r = TREG_RAX;
        vtop->r = r;
        اكسر;
    افتراضي:
        opc = 7;
        اذهب gen_op8;
    }
}

فراغ gen_opl(صحيح op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
فراغ gen_opf(صحيح op)
{
    صحيح a, ft, fc, swapped, r, opc;
    صحيح bt = vtop->type.t & VT_BTYPE;
    صحيح float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    إذا (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        إذا (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } وإلا {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, عدم, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        أرجع;
    }

    /* convert constants to memory references */
    إذا ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    إذا ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    إذا ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    إذا (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    إذا ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        إذا (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            ڀريو(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            إذا (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            وإلا إذا (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            إذا (swapped)
                o(0xc9d9); /* fxch %st(1) */
            إذا (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            وإلا
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            إذا (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } وإلا إذا (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } وإلا إذا (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } وإلا {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } وإلا {
            /* no memory reference possible for long double operations */
            ڀريو(TREG_ST0, vtop);
            swapped = !swapped;

            بدل(op) {
            افتراضي:
            حالة '+':
                a = 0;
                اكسر;
            حالة '-':
                a = 4;
                إذا (swapped)
                    a++;
                اكسر;
            حالة '*':
                a = 1;
                اكسر;
            حالة '/':
                a = 6;
                إذا (swapped)
                    a++;
                اكسر;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } وإلا {
        إذا (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            إذا ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = عدم;
                ڀريو(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            إذا (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } وإلا {
                إذا (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                إذا (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } وإلا {
                    op = 0x97; /* seta */
                }
            }

            إذا (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            أكد(!(vtop[-1].r & VT_LVAL));
            
            إذا (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            وإلا
                opc = 0x2f0f; /* comisd */
            إذا ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } وإلا {
            أكد((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            بدل(op) {
            افتراضي:
            حالة '+':
                a = 0;
                اكسر;
            حالة '-':
                a = 4;
                اكسر;
            حالة '*':
                a = 1;
                اكسر;
            حالة '/':
                a = 6;
                اكسر;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            أكد((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            إذا ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = عدم;
                ڀريو(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            أكد(!(vtop[-1].r & VT_LVAL));
            إذا (swapped) {
                أكد(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            إذا ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } وإلا {
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
فراغ gen_cvt_itof(صحيح t)
{
    إذا ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        إذا ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } وإلا إذا ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } وإلا {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } وإلا {
        صحيح r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        إذا ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_قدر(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
فراغ gen_cvt_ftof(صحيح t)
{
    صحيح ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    إذا (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        إذا (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_قدر(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_قدر(vtop->r)*9);
        } وإلا إذا (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_قدر(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } وإلا إذا (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        إذا (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_قدر(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_قدر(vtop->r)*9);
        } وإلا إذا (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_قدر(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } وإلا {
        صحيح r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        إذا (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_قدر(r)*8);
            o(0xf024);
            vtop->r = r;
        } وإلا إذا (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_قدر(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
فراغ gen_cvt_ftoi(صحيح t)
{
    صحيح ft, bt, سائيز, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    إذا (bt == VT_LDOUBLE) {
	إذا (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    أرجع;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    إذا (t != VT_INT)
        سائيز = 8;
    وإلا
        سائيز = 4;

    r = get_reg(RC_INT);
    إذا (bt == VT_FLOAT) {
        o(0xf3);
    } وإلا إذا (bt == VT_DOUBLE) {
        o(0xf2);
    } وإلا {
        أكد(0);
    }
    orex(سائيز == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_قدر(vtop->r) + REG_قدر(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC فراغ gen_cvt_sxtw(فراغ)
{
    صحيح r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_قدر(r) << 3) + REG_قدر(r));
}

/* char/short to int conversion */
ST_FUNC فراغ gen_cvt_csti(صحيح t)
{
    صحيح r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_قدر(r) << 3 | REG_قدر(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC فراغ gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_متن_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC فراغ ggoto(فراغ)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC فراغ gen_vla_sp_save(صحيح addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, عدم, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC فراغ gen_vla_sp_restore(صحيح addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, عدم, addr);
}

#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC فراغ gen_vla_نتيجو(صحيح addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, عدم, addr);
}
#جيڪڏهن_پورو

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align) {
    صحيح use_call = 0;

#إذا defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#جيڪڏهن_پورو
    إذا (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    وإلا {
        صحيح r;
        r = gv(RC_INT); /* allocation size */
        /* sub r,%rsp */
        o(0x2b48);
        o(0xe0 | REG_قدر(r));
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
ST_FUNC فراغ gen_struct_copy(صحيح سائيز)
{
    صحيح n = سائيز / PTR_سائيز;
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
    o(0x5756); /* push rsi, rdi */
#جيڪڏهن_پورو
    gv2(RC_RDI, RC_RSI);
    إذا (n <= 4) {
        طالما (n)
            o(0xa548), --n;
    } وإلا {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    إذا (سائيز & 0x04)
        o(0xa5);
    إذا (سائيز & 0x02)
        o(0xa566);
    إذا (سائيز & 0x01)
        o(0xa4);
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
    o(0x5e5f); /* pop rdi, rsi */
#جيڪڏهن_پورو
    vpop();
    vpop();
}

/* end of x86-64 code generator */
/*************************************************************/
#جيڪڏهن_پورو /* ! TARGET_DEFS_ONLY */
/******************************************************/
