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
গণনা {
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
#define REG_মান(reg) ((reg) & 7)

/* return registers for function */
#define REG_IRET TREG_RAX /* single word int return register */
#define REG_IRE2 TREG_RDX /* second word return register (for long long) */
#define REG_FRET TREG_XMM0 /* float return register */
#define REG_FRE2 TREG_XMM1 /* second float return register */

/* defined if function parameters must be evaluated in reverse order */
#define INVERT_FUNC_PARAMS

/* pointer size, in bytes */
#define PTR_আকার 8

/* long double size and alignment, in bytes */
#define LDOUBLE_আকার  16
#define LDOUBLE_ALIGN 16
/* maximum alignment (for aligned attribute support) */
#define MAX_ALIGN     16

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#define PROMOTE_RET

#define TCC_TARGET_NATIVE_STRUCT_COPY
ST_FUNC শূন্য gen_struct_copy(পূর্ণসংখ্যা আকার_2);

/******************************************************/
#অন্যথা /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#অন্তর্ভাব "tcc.h"
#অন্তর্ভাব <assert.h>

ST_তথ্য ধ্রুবক অক্ষর * ধ্রুবক target_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_তথ্য ধ্রুবক পূর্ণসংখ্যা reg_classes[NB_REGS] = {
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

স্থির unsigned long func_sub_sp_offset;
স্থির পূর্ণসংখ্যা func_ret_sub;

#যদি defined(CONFIG_TCC_BCHECK)
স্থির addr_t func_bound_offset;
স্থির unsigned long func_bound_ind;
ST_তথ্য পূর্ণসংখ্যা func_bound_add_epilog;
#endif

#ifdef TCC_TARGET_PE
স্থির পূর্ণসংখ্যা func_scratch, func_alloca;
#endif

/* XXX: make it faster ? */
ST_FUNC শূন্য g(পূর্ণসংখ্যা c)
{
    পূর্ণসংখ্যা ind1;
    যদি (nocode_wanted)
        ফেরত;
    ind1 = ind + 1;
    যদি (ind1 > cur_text_section->তথ্য_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->তথ্য[ind] = c;
    ind = ind1;
}

ST_FUNC শূন্য o(unsigned পূর্ণসংখ্যা c)
{
    যখন (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC শূন্য gen_le16(পূর্ণসংখ্যা v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC শূন্য gen_le32(পূর্ণসংখ্যা c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

ST_FUNC শূন্য gen_le64(int64_t c)
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

স্থির শূন্য orex(পূর্ণসংখ্যা ll, পূর্ণসংখ্যা r, পূর্ণসংখ্যা r2, পূর্ণসংখ্যা b)
{
    যদি ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    যদি ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    যদি (ll || REX_BASE(r) || REX_BASE(r2)) {
        যদি ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_BASE(r) | (REX_BASE(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC শূন্য gsym_addr(পূর্ণসংখ্যা t, পূর্ণসংখ্যা a)
{
    যখন (t) {
        unsigned অক্ষর *ptr = cur_text_section->তথ্য + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

স্থির পূর্ণসংখ্যা is64_type(পূর্ণসংখ্যা t)
{
    ফেরত ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
স্থির পূর্ণসংখ্যা oad(পূর্ণসংখ্যা c, পূর্ণসংখ্যা s)
{
    পূর্ণসংখ্যা t;
    যদি (nocode_wanted)
        ফেরত s;
    o(c);
    t = ind;
    gen_le32(s);
    ফেরত t;
}

/* generate jmp to a label */
#define gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC শূন্য gen_addr32(পূর্ণসংখ্যা r, Sym *sym, পূর্ণসংখ্যা c)
{
    যদি (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC শূন্য gen_addrpc32(পূর্ণসংখ্যা r, Sym *sym, পূর্ণসংখ্যা c)
{
    যদি (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
স্থির শূন্য gen_gotpcrel(পূর্ণসংখ্যা r, Sym *sym, পূর্ণসংখ্যা c)
{
#ifdef TCC_TARGET_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, ফাঁকা), c, r,
        cur_text_section->তথ্য[ind-3],
        cur_text_section->তথ্য[ind-2],
        cur_text_section->তথ্য[ind-1]
        );
#endif
    greloca(cur_text_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    যদি (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_মান(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
স্থির শূন্য gen_modrm_impl(পূর্ণসংখ্যা opcode, পূর্ণসংখ্যা ll, পূর্ণসংখ্যা op_reg_0, পূর্ণসংখ্যা r, Sym *sym, পূর্ণসংখ্যা c)
{
    পূর্ণসংখ্যা op_reg = REG_মান(op_reg_0) << 3;

    যদি ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK_tls_সূচক, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_আকার); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#অন্যথা
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#endif
        ফেরত;
    }

    orex(ll, r, op_reg_0, opcode);

    যদি ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	যদি (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} অন্যথা {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    যদি (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } অন্যথা {
		gen_addrpc32(r, sym, c);
	    }
	}
    } অন্যথা যদি ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        যদি (c == (signed অক্ষর)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } অন্যথা {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } অন্যথা যদি ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_মান(r));
        gen_le32(c);
    } অন্যথা যদি (r & VT_LVAL) {
        g(0x00 | op_reg | REG_মান(r));
    } অন্যথা {
        g(0xc0 | op_reg | REG_মান(r));
    }
}

স্থির শূন্য gen_modrm64(পূর্ণসংখ্যা opcode, পূর্ণসংখ্যা op_reg, পূর্ণসংখ্যা r, Sym *sym, পূর্ণসংখ্যা c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

স্থির শূন্য gen_modrm32(পূর্ণসংখ্যা opcode, পূর্ণসংখ্যা op_reg, পূর্ণসংখ্যা r, Sym *sym, পূর্ণসংখ্যা c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
শূন্য load(পূর্ণসংখ্যা r, SValue *sv)
{
    পূর্ণসংখ্যা v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    যদি (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#ifndef TCC_TARGET_PE
    /* we use indirect access via got */
    যদি ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        পূর্ণসংখ্যা tr = r | TREG_MEM;
        যদি (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#endif

    v = fr & VT_VALMASK;
    যদি (fr & VT_LVAL) {
        পূর্ণসংখ্যা b, ll;
        যদি (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = ফাঁকা;
            fr = r;
            যদি (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            load(fr, &v1);
            fr |= VT_LVAL;
        }
	যদি (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = ফাঁকা;
	    fr = r;
	    যদি (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    load(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	যদি ((ft & VT_BTYPE) == VT_STRUCT) {
	    পূর্ণসংখ্যা align;
	    নির্বাচন (type_আকার(&sv->type, &align)) {
		ক্ষেত্র 1: ft = VT_BYTE; বিরতি;
		ক্ষেত্র 2: ft = VT_SHORT; বিরতি;
		ক্ষেত্র 4: ft = VT_INT; বিরতি;
		ক্ষেত্র 8: ft = VT_LLONG; বিরতি;
		পূর্বনির্ধারিত:
		    tcc_error("invalid aggregate type for register load");
		    বিরতি;
	    }
	}
        যদি ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_মান(r); /* movd */
        } অন্যথা যদি ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_মান(r);
        } অন্যথা যদি ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } অন্যথা যদি ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } অন্যথা যদি ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } অন্যথা যদি ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } অন্যথা যদি ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } অন্যথা যদি ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            ফেরত;
        } অন্যথা {
            প্রতিজ্ঞা(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } অন্যথা {
        যদি (v == VT_CONST) {
            যদি (fr & VT_SYM) {
#ifdef TCC_TARGET_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#অন্যথা
                যদি (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, ফাঁকা, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_মান(r), 0);
                    greloca(cur_text_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } অন্যথা যদি (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_মান(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } অন্যথা {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_মান(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#endif
            } অন্যথা যদি (is64_type(ft)) {
                যদি (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_মান(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } অন্যথা যদি (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_মান(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } অন্যথা {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_মান(r) * 9);
                }
            } অন্যথা {
                orex(0,r,0, 0xb8 + REG_মান(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } অন্যথা যদি (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } অন্যথা যদি (v == VT_CMP) {
	    যদি (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_মান(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_BASE(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_মান(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_মান(r) * 0x900); /* movzbl %al, %eax */
        } অন্যথা যদি (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_মান(r), t); /* mov $1, r */
            o(0x05eb + (REX_BASE(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_মান(r), t ^ 1); /* mov $0, r */
        } অন্যথা যদি (v != r) {
            যদি ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                যদি (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_মান(r)*8); /* %xmmN */
                    o(0xf024);
                } অন্যথা {
                    প্রতিজ্ঞা((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    যদি ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } অন্যথা {
                        প্রতিজ্ঞা((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_মান(v) + REG_মান(r)*8);
                }
            } অন্যথা যদি (r == TREG_ST0) {
                প্রতিজ্ঞা((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_মান(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } অন্যথা {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_মান(r) + REG_মান(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
শূন্য store(পূর্ণসংখ্যা r, SValue *v)
{
    পূর্ণসংখ্যা fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    পূর্ণসংখ্যা opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    যদি (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#ifndef TCC_TARGET_PE
    /* we need to access the variable via got */
    যদি ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#endif

    /* XXX: incorrect if float reg to reg */
    যদি (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_মান(r);
    } অন্যথা যদি (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_মান(r);
    } অন্যথা যদি (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } অন্যথা যদি (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } অন্যথা {
        opc = 0x89;
        যদি (bt == VT_SHORT)
            opc = 0x8966;
        অন্যথা যদি (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
স্থির শূন্য gcall_or_jmp(পূর্ণসংখ্যা is_jmp)
{
    পূর্ণসংখ্যা r;
    যদি ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (পূর্ণসংখ্যা)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind + 1, R_X86_64_PLT32, (পূর্ণসংখ্যা)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } অন্যথা {
        /* otherwise, indirect call */
        r = TREG_R11;
        load(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_মান(r) + (is_jmp << 4));
    }
}

#যদি defined(CONFIG_TCC_BCHECK)

স্থির শূন্য gen_bounds_call(পূর্ণসংখ্যা v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#ifdef TCC_TARGET_PE
# define TREG_FASTCALL_1 TREG_RCX
#অন্যথা
# define TREG_FASTCALL_1 TREG_RDI
#endif

স্থির শূন্য gen_bounds_prolog(শূন্য)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->তথ্য_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
}

স্থির শূন্য gen_bounds_epilog(শূন্য)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_তথ্য;
    পূর্ণসংখ্যা offset_modified = func_bound_offset != lbounds_section->তথ্য_offset;

    যদি (!offset_modified && !func_bound_add_epilog)
        ফেরত;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, আকার(addr_t));
    *bounds_ptr = 0;

    sym_তথ্য = get_sym_ref(&char_pointer_type, lbounds_section, 
                           func_bound_offset, PTR_আকার);

    /* generate bound local allocation */
    যদি (offset_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        greloca(cur_text_section, sym_তথ্য, ind + 3, R_X86_64_PC32, -4);
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
    greloca(cur_text_section, sym_তথ্য, ind + 3, R_X86_64_PC32, -4);
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
স্থির ধ্রুবক uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
স্থির পূর্ণসংখ্যা arg_prepare_reg(পূর্ণসংখ্যা idx) {
  যদি (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      ফেরত idx + 10;
  অন্যথা
      ফেরত idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

স্থির শূন্য gen_offs_sp(পূর্ণসংখ্যা b, পূর্ণসংখ্যা r, পূর্ণসংখ্যা d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    যদি (d == (signed অক্ষর)d) {
        o(0x2444 | (REG_মান(r) << 3));
        g(d);
    } অন্যথা {
        o(0x2484 | (REG_মান(r) << 3));
        gen_le32(d);
    }
}

স্থির পূর্ণসংখ্যা using_regs(পূর্ণসংখ্যা আকার_2)
{
    ফেরত !(আকার_2 > 8 || (আকার_2 & (আকার_2 - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC পূর্ণসংখ্যা gfunc_sret(CType *vt, পূর্ণসংখ্যা variadic, CType *ret, পূর্ণসংখ্যা *ret_align, পূর্ণসংখ্যা *regsize)
{
    পূর্ণসংখ্যা আকার_2, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    আকার_2 = type_আকার(vt, &align);
    যদি (!using_regs(আকার_2))
        ফেরত 0;
    যদি (আকার_2 == 8)
        ret->t = VT_LLONG;
    অন্যথা যদি (আকার_2 == 4)
        ret->t = VT_INT;
    অন্যথা যদি (আকার_2 == 2)
        ret->t = VT_SHORT;
    অন্যথা
        ret->t = VT_BYTE;
    ret->ref = ফাঁকা;
    ফেরত 1;
}

স্থির পূর্ণসংখ্যা is_sse_float(পূর্ণসংখ্যা t) {
    পূর্ণসংখ্যা bt;
    bt = t & VT_BTYPE;
    ফেরত bt == VT_DOUBLE || bt == VT_FLOAT;
}

স্থির পূর্ণসংখ্যা gfunc_arg_আকার(CType *type) {
    পূর্ণসংখ্যা align;
    যদি (type->t & (VT_ARRAY|VT_BITFIELD))
        ফেরত 8;
    ফেরত type_আকার(type, &align);
}

শূন্য gfunc_call(পূর্ণসংখ্যা nb_args)
{
    পূর্ণসংখ্যা আকার_2, r, args_আকার, i, d, bt, struct_আকার;
    পূর্ণসংখ্যা arg;

#ifdef CONFIG_TCC_BCHECK
    যদি (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    args_আকার = (nb_args < REGN ? REGN : nb_args) * PTR_আকার;
    arg = nb_args;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_আকার = args_আকার;
    জন্য(i = 0; i < nb_args; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        আকার_2 = gfunc_arg_আকার(&sv->type);

        যদি (using_regs(আকার_2))
            চালু; /* arguments smaller than 8 bytes passed in registers or on stack */

        যদি (bt == VT_STRUCT) {
            /* align to stack align size */
            আকার_2 = (আকার_2 + 15) & ~15;
            /* generate structure store */
            r = get_reg(RC_INT);
            gen_offs_sp(0x8d, r, struct_আকার);
            struct_আকার += আকার_2;

            /* generate memcpy call */
            vset(&sv->type, r | VT_LVAL, 0);
            vpushv(sv);
            vstore();
            --vtop;
        } অন্যথা যদি (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_আকার);
            struct_আকার += 16;
        }
    }

    যদি (func_scratch < struct_আকার)
        func_scratch = struct_আকার;

    arg = nb_args;
    struct_আকার = args_আকার;

    জন্য(i = 0; i < nb_args; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        আকার_2 = gfunc_arg_আকার(&vtop->type);
        যদি (!using_regs(আকার_2)) {
            /* align to stack align size */
            আকার_2 = (আকার_2 + 15) & ~15;
            যদি (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_আকার);
                gen_offs_sp(0x89, d, arg*8);
            } অন্যথা {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_আকার);
            }
            struct_আকার += আকার_2;
        } অন্যথা {
            যদি (is_sse_float(vtop->type.t)) {
		যদি (tcc_state->nosse)
		  tcc_error("SSE disabled");
                যদি (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } অন্যথা {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_মান(d));
                }
            } অন্যথা {
                যদি (bt == VT_STRUCT) {
                    vtop->type.ref = ফাঁকা;
                    vtop->type.t = আকার_2 > 4 ? VT_LLONG : আকার_2 > 2 ? VT_INT
                        : আকার_2 > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                যদি (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } অন্যথা {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_মান(r) * 8 + REG_মান(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    যদি (nb_args > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        যদি (nb_args > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    যদি ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#ifdef CONFIG_TCC_BCHECK
        যদি (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#endif
    }
    vtop--;
}

#define FUNC_PROLOG_আকার 11

/* generate function prolog of type 't' */
শূন্য gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    পূর্ণসংখ্যা addr, reg_param_সূচক, bt, আকার_2;
    Sym *sym;
    CType *type;

    func_ret_sub = 0;
    func_scratch = 32;
    func_alloca = 0;
    loc = 0;

    addr = PTR_আকার * 2;
    ind += FUNC_PROLOG_আকার;
    func_sub_sp_offset = ind;
    reg_param_সূচক = 0;

    sym = func_type->ref;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    আকার_2 = gfunc_arg_আকার(&func_vt);
    যদি (!using_regs(আকার_2)) {
        gen_modrm64(0x89, arg_regs[reg_param_সূচক], VT_LOCAL, ফাঁকা, addr);
        func_vc = addr;
        reg_param_সূচক++;
        addr += 8;
    }

    /* define parameters */
    যখন ((sym = sym->পরবর্তী) != ফাঁকা) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        আকার_2 = gfunc_arg_আকার(type);
        যদি (!using_regs(আকার_2)) {
            যদি (reg_param_সূচক < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_সূচক], VT_LOCAL, ফাঁকা, addr);
            }
            gfunc_set_param(sym, addr, 1);
        } অন্যথা {
            যদি (reg_param_সূচক < REGN) {
                /* save arguments passed by register */
                যদি ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    যদি (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_সূচক, VT_LOCAL, ফাঁকা, addr);
                } অন্যথা {
                    gen_modrm64(0x89, arg_regs[reg_param_সূচক], VT_LOCAL, ফাঁকা, addr);
                }
            }
            gfunc_set_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_সূচক++;
    }

    যখন (reg_param_সূচক < REGN) {
        যদি (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_সূচক], VT_LOCAL, ফাঁকা, addr);
            addr += 8;
        }
        reg_param_সূচক++;
    }
#ifdef CONFIG_TCC_BCHECK
    যদি (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
শূন্য gfunc_epilog(শূন্য)
{
    পূর্ণসংখ্যা v, start;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#ifdef CONFIG_TCC_BCHECK
    যদি (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    o(0xc9); /* leave */
    যদি (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } অন্যথা {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    start = func_sub_sp_offset - FUNC_PROLOG_আকার;
    cur_text_section->তথ্য_offset = ind;
    pe_add_unwind_তথ্য(start, ind, v);

    ind = start;
    যদি (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } অন্যথা {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_text_section->তথ্য_offset;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#অন্যথা

স্থির শূন্য gadd_sp(পূর্ণসংখ্যা val)
{
    যদি (val == (signed অক্ষর)val) {
        o(0xc48348);
        g(val);
    } অন্যথা {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

প্রকারলেখ গণনা X86_64_Mode {
  x86_64_mode_none,
  x86_64_mode_memory,
  x86_64_mode_integer,
  x86_64_mode_sse,
  x86_64_mode_x87
} X86_64_Mode;

স্থির X86_64_Mode classify_x86_64_merge(X86_64_Mode a, X86_64_Mode b)
{
    যদি (a == b)
        ফেরত a;
    অন্যথা যদি (a == x86_64_mode_none)
        ফেরত b;
    অন্যথা যদি (b == x86_64_mode_none)
        ফেরত a;
    অন্যথা যদি ((a == x86_64_mode_memory) || (b == x86_64_mode_memory))
        ফেরত x86_64_mode_memory;
    অন্যথা যদি ((a == x86_64_mode_integer) || (b == x86_64_mode_integer))
        ফেরত x86_64_mode_integer;
    অন্যথা যদি ((a == x86_64_mode_x87) || (b == x86_64_mode_x87))
        ফেরত x86_64_mode_memory;
    অন্যথা
        ফেরত x86_64_mode_sse;
}

স্থির X86_64_Mode classify_x86_64_inner(CType *ty)
{
    X86_64_Mode mode;
    Sym *f;
    
    নির্বাচন (ty->t & VT_BTYPE) {
    ক্ষেত্র VT_VOID: ফেরত x86_64_mode_none;
    
    ক্ষেত্র VT_INT:
    ক্ষেত্র VT_BYTE:
    ক্ষেত্র VT_SHORT:
    ক্ষেত্র VT_LLONG:
    ক্ষেত্র VT_BOOL:
    ক্ষেত্র VT_PTR:
    ক্ষেত্র VT_FUNC:
        ফেরত x86_64_mode_integer;
    
    ক্ষেত্র VT_FLOAT:
    ক্ষেত্র VT_DOUBLE: ফেরত x86_64_mode_sse;
    
    ক্ষেত্র VT_LDOUBLE: ফেরত x86_64_mode_x87;
      
    ক্ষেত্র VT_STRUCT:
        f = ty->ref;

        mode = x86_64_mode_none;
        জন্য (f = f->পরবর্তী; f; f = f->পরবর্তী)
            mode = classify_x86_64_merge(mode, classify_x86_64_inner(&f->type));
        
        ফেরত mode;
    }
    প্রতিজ্ঞা(0);
    ফেরত 0;
}

স্থির X86_64_Mode classify_x86_64_arg(CType *ty, CType *ret, পূর্ণসংখ্যা *psize, পূর্ণসংখ্যা *palign, পূর্ণসংখ্যা *reg_গুনতি)
{
    X86_64_Mode mode;
    পূর্ণসংখ্যা আকার_2, align, ret_t = 0;
    
    যদি (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_গুনতি = 1;
        ret_t = ty->t;
        mode = x86_64_mode_integer;
    } অন্যথা {
        আকার_2 = type_আকার(ty, &align);
        *psize = (আকার_2 + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_গুনতি = 0; /* avoid compiler warning */

        যদি (আকার_2 > 16) {
            mode = x86_64_mode_memory;
        } অন্যথা {
            mode = classify_x86_64_inner(ty);
            নির্বাচন (mode) {
            ক্ষেত্র x86_64_mode_integer:
                যদি (আকার_2 > 8) {
                    *reg_গুনতি = 2;
                    ret_t = VT_QLONG;
                } অন্যথা {
                    *reg_গুনতি = 1;
                    যদি (আকার_2 > 4)
                        ret_t = VT_LLONG;
                    অন্যথা যদি (আকার_2 > 2)
                        ret_t = VT_INT;
                    অন্যথা যদি (আকার_2 > 1)
                        ret_t = VT_SHORT;
                    অন্যথা
                        ret_t = VT_BYTE;
                    যদি ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                বিরতি;
                
            ক্ষেত্র x86_64_mode_x87:
                *reg_গুনতি = 1;
                ret_t = VT_LDOUBLE;
                বিরতি;

            ক্ষেত্র x86_64_mode_sse:
                যদি (আকার_2 > 8) {
                    *reg_গুনতি = 2;
                    ret_t = VT_QFLOAT;
                } অন্যথা {
                    *reg_গুনতি = 1;
                    ret_t = (আকার_2 > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                বিরতি;
            পূর্বনির্ধারিত: বিরতি; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    যদি (ret) {
        ret->ref = ফাঁকা;
        ret->t = ret_t;
    }
    
    ফেরত mode;
}

ST_FUNC পূর্ণসংখ্যা classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    গণনা __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    পূর্ণসংখ্যা আকার_2, align, reg_গুনতি;
    X86_64_Mode mode = classify_x86_64_arg(ty, ফাঁকা, &আকার_2, &align, &reg_গুনতি);
    নির্বাচন (mode) {
    পূর্বনির্ধারিত: ফেরত __va_stack;
    ক্ষেত্র x86_64_mode_integer: ফেরত __va_gen_reg;
    ক্ষেত্র x86_64_mode_sse: ফেরত __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC পূর্ণসংখ্যা gfunc_sret(CType *vt, পূর্ণসংখ্যা variadic, CType *ret, পূর্ণসংখ্যা *ret_align, পূর্ণসংখ্যা *regsize)
{
    পূর্ণসংখ্যা আকার_2, align, reg_গুনতি;
    যদি (classify_x86_64_arg(vt, ret, &আকার_2, &align, &reg_গুনতি) == x86_64_mode_memory)
        ফেরত 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_গুনতি; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    ফেরত 1;
}

#define REGN 6
স্থির ধ্রুবক uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

স্থির পূর্ণসংখ্যা arg_prepare_reg(পূর্ণসংখ্যা idx) {
  যদি (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      ফেরত idx + 8;
  অন্যথা
      ফেরত idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
শূন্য gfunc_call(পূর্ণসংখ্যা nb_args)
{
    X86_64_Mode mode;
    CType type;
    পূর্ণসংখ্যা আকার_2, align, r, args_আকার, স্তূপ_adjust, i, reg_গুনতি, k;
    পূর্ণসংখ্যা nb_reg_args = 0;
    পূর্ণসংখ্যা nb_sse_args = 0;
    পূর্ণসংখ্যা sse_reg, gen_reg;
    অক্ষর *onstack = tcc_malloc((nb_args + 1) * আকার (অক্ষর));

#ifdef CONFIG_TCC_BCHECK
    যদি (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    স্তূপ_adjust = 0;
    জন্য(i = nb_args - 1; i >= 0; i--) {
        mode = classify_x86_64_arg(&vtop[-i].type, ফাঁকা, &আকার_2, &align, &reg_গুনতি);
        যদি (আকার_2 == 0) চালু;
        যদি (mode == x86_64_mode_sse && nb_sse_args + reg_গুনতি <= 8) {
            nb_sse_args += reg_গুনতি;
	    onstack[i] = 0;
	} অন্যথা যদি (mode == x86_64_mode_integer && nb_reg_args + reg_গুনতি <= REGN) {
            nb_reg_args += reg_গুনতি;
	    onstack[i] = 0;
	} অন্যথা যদি (mode == x86_64_mode_none) {
	    onstack[i] = 0;
	} অন্যথা {
	    যদি (align == 16 && (স্তূপ_adjust &= 15)) {
		onstack[i] = 2;
		স্তূপ_adjust = 0;
	    } অন্যথা
	      onstack[i] = 1;
	    স্তূপ_adjust += আকার_2;
	}
    }

    যদি (nb_sse_args && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_args;
    sse_reg = nb_sse_args;
    args_আকার = 0;
    স্তূপ_adjust &= 15;
    জন্য (i = k = 0; i < nb_args;) {
	mode = classify_x86_64_arg(&vtop[-i].type, ফাঁকা, &আকার_2, &align, &reg_গুনতি);
	যদি (আকার_2) {
            যদি (!onstack[i + k]) {
	        ++i;
	        চালু;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            যদি (স্তূপ_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                args_আকার += 8;
	        স্তূপ_adjust = 0;
            }
	    যদি (onstack[i + k] == 2)
	        স্তূপ_adjust = 1;
        }

	vrotb(i+1);

	নির্বাচন (vtop->type.t & VT_BTYPE) {
	    ক্ষেত্র VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, আকার_2); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_মান(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_মান(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		বিরতি;

	    ক্ষেত্র VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, আকার_2); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		বিরতি;

	    ক্ষেত্র VT_FLOAT:
	    ক্ষেত্র VT_DOUBLE:
		প্রতিজ্ঞা(mode == x86_64_mode_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_মান(r)*8);
		o(0x24);
		বিরতি;

	    পূর্বনির্ধারিত:
		প্রতিজ্ঞা(mode == x86_64_mode_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_মান(r)); /* push r */
		বিরতি;
	}
	args_আকার += আকার_2;

	vpop();
	--nb_args;
	k++;
    }

    tcc_free(onstack);

    /* then, we prepare register passing arguments.
       Note that we cannot set RDX and RCX in this loop because gv()
       may break these temporary registers. Let's use R10 and R11
       instead of them */
    প্রতিজ্ঞা(gen_reg <= REGN);
    প্রতিজ্ঞা(sse_reg <= 8);
    জন্য(i = 0; i < nb_args; i++) {
        mode = classify_x86_64_arg(&vtop->type, &type, &আকার_2, &align, &reg_গুনতি);
        যদি (আকার_2 == 0) চালু;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        যদি (mode == x86_64_mode_sse) {
            যদি (reg_গুনতি == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                যদি (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } অন্যথা {
                প্রতিজ্ঞা(reg_গুনতি == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } অন্যথা যদি (mode == x86_64_mode_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            পূর্ণসংখ্যা d;
            gen_reg -= reg_গুনতি;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_মান(r) * 8 + REG_মান(d));
            যদি (reg_গুনতি == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_মান(vtop->r2) * 8 + REG_মান(d));
            }
        }
        vtop--;
    }
    প্রতিজ্ঞা(gen_reg == 0);
    প্রতিজ্ঞা(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    যদি (nb_reg_args > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        যদি (nb_reg_args > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    যদি (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_args < 8 ? nb_sse_args : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    যদি (args_আকার)
        gadd_sp(args_আকার);
    vtop--;
}

#define FUNC_PROLOG_আকার 11

স্থির শূন্য ঠেলো_arg_reg(পূর্ণসংখ্যা i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, ফাঁকা, loc);
}

/* generate function prolog of type 't' */
শূন্য gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_Mode mode, ret_mode;
    পূর্ণসংখ্যা i, addr, align, আকার_2, reg_গুনতি;
    পূর্ণসংখ্যা param_addr = 0, reg_param_সূচক, sse_param_সূচক;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_আকার * 2;
    loc = 0;
    ind += FUNC_PROLOG_আকার;
    func_sub_sp_offset = ind;
    func_ret_sub = 0;
    ret_mode = classify_x86_64_arg(&func_vt, ফাঁকা, &আকার_2, &align, &reg_গুনতি);

    যদি (func_var) {
        পূর্ণসংখ্যা seen_reg_অঙ্ক, seen_sse_অঙ্ক, seen_স্তূপ_আকার;
        seen_reg_অঙ্ক = ret_mode == x86_64_mode_memory;
        seen_sse_অঙ্ক = 0;
        /* frame pointer and return address */
        seen_স্তূপ_আকার = PTR_আকার * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        যখন ((sym = sym->পরবর্তী) != ফাঁকা) {
            type = &sym->type;
            mode = classify_x86_64_arg(type, ফাঁকা, &আকার_2, &align, &reg_গুনতি);
            নির্বাচন (mode) {
            পূর্বনির্ধারিত:
            স্তূপ_arg:
                seen_স্তূপ_আকার = ((seen_স্তূপ_আকার + align - 1) & -align) + আকার_2;
                বিরতি;
                
            ক্ষেত্র x86_64_mode_integer:
                যদি (seen_reg_অঙ্ক + reg_গুনতি > REGN)
		    যাও স্তূপ_arg;
		seen_reg_অঙ্ক += reg_গুনতি;
                বিরতি;
                
            ক্ষেত্র x86_64_mode_sse:
                যদি (seen_sse_অঙ্ক + reg_গুনতি > 8)
		    যাও স্তূপ_arg;
		seen_sse_অঙ্ক += reg_গুনতি;
                বিরতি;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(seen_reg_অঙ্ক * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(seen_sse_অঙ্ক * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(seen_স্তূপ_আকার);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        জন্য (i = 0; i < 8; i++) {
            loc -= 16;
	    যদি (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, ফাঁকা, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        জন্য (i = 0; i < REGN; i++) {
            ঠেলো_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_সূচক = 0;
    sse_param_সূচক = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    যদি (ret_mode == x86_64_mode_memory) {
        ঠেলো_arg_reg(reg_param_সূচক);
        func_vc = loc;
        reg_param_সূচক++;
    }
    /* define parameters */
    যখন ((sym = sym->পরবর্তী) != ফাঁকা) {
        type = &sym->type;
        mode = classify_x86_64_arg(type, ফাঁকা, &আকার_2, &align, &reg_গুনতি);
        নির্বাচন (mode) {
        ক্ষেত্র x86_64_mode_sse:
	    যদি (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            যদি (sse_param_সূচক + reg_গুনতি <= 8) {
                /* save arguments passed by register */
                loc -= reg_গুনতি * 8;
                param_addr = loc;
                জন্য (i = 0; i < reg_গুনতি; ++i) {
                    gen_modrm32(0xd60f66, sse_param_সূচক, VT_LOCAL, ফাঁকা, param_addr + i*8);
                    ++sse_param_সূচক;
                }
            } অন্যথা {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += আকার_2;
            }
            বিরতি;
            
        ক্ষেত্র x86_64_mode_memory:
        ক্ষেত্র x86_64_mode_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += আকার_2;
            বিরতি;
            
        ক্ষেত্র x86_64_mode_integer: {
            যদি (reg_param_সূচক + reg_গুনতি <= REGN) {
                /* save arguments passed by register */
                loc -= reg_গুনতি * 8;
                param_addr = loc;
                জন্য (i = 0; i < reg_গুনতি; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_সূচক], VT_LOCAL, ফাঁকা, param_addr + i*8);
                    ++reg_param_সূচক;
                }
            } অন্যথা {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += আকার_2;
            }
            বিরতি;
        }
	পূর্বনির্ধারিত: বিরতি; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_set_param(sym, param_addr, 0);
    }

#ifdef CONFIG_TCC_BCHECK
    যদি (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
শূন্য gfunc_epilog(শূন্য)
{
    পূর্ণসংখ্যা v, saved_ind;

#ifdef CONFIG_TCC_BCHECK
    যদি (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif
    o(0xc9); /* leave */
    যদি (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } অন্যথা {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    /* align local size to word & save local variables */
    v = (-loc + 15) & -16;
    saved_ind = ind;
    ind = func_sub_sp_offset - FUNC_PROLOG_আকার;
    o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
    o(0xec8148);  /* sub rsp, stacksize */
    gen_le32(v);
    ind = saved_ind;
}

#endif /* not PE */

ST_FUNC শূন্য gen_fill_nops(পূর্ণসংখ্যা bytes)
{
    যখন (bytes--)
      g(0x90);
}

/* generate a jump to a label */
পূর্ণসংখ্যা gjmp(পূর্ণসংখ্যা t)
{
    ফেরত gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
শূন্য gjmp_addr(পূর্ণসংখ্যা a)
{
    পূর্ণসংখ্যা r;
    r = a - ind - 2;
    যদি (r == (signed অক্ষর)r) {
        g(0xeb);
        g(r);
    } অন্যথা {
        oad(0xe9, a - ind - 5);
    }
}

ST_FUNC পূর্ণসংখ্যা gjmp_append(পূর্ণসংখ্যা n, পূর্ণসংখ্যা t)
{
    শূন্য *p;
    /* insert vtop->c jump list in t */
    যদি (n) {
        uint32_t n1 = n, n2;
        যখন ((n2 = read32le(p = cur_text_section->তথ্য + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    ফেরত t;
}

ST_FUNC পূর্ণসংখ্যা gjmp_cond(পূর্ণসংখ্যা op, পূর্ণসংখ্যা t)
{
        যদি (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            পূর্ণসংখ্যা v = vtop->cmp_r;
            op &= ~0x100;
            যদি (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    অন্যথা
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        ফেরত t;
}

/* generate an integer binary operation */
শূন্য gen_opi(পূর্ণসংখ্যা op)
{
    পূর্ণসংখ্যা r, fr, opc, c;
    পূর্ণসংখ্যা ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    নির্বাচন(op) {
    ক্ষেত্র '+':
    ক্ষেত্র TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        যদি (cc && (!ll || (পূর্ণসংখ্যা)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            যদি (c == (signed অক্ষর)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_মান(r));
                g(c);
            } অন্যথা {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_মান(r), c);
            }
        } অন্যথা {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_মান(r) + REG_মান(fr) * 8);
        }
        vtop--;
        যদি (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        বিরতি;
    ক্ষেত্র '-':
    ক্ষেত্র TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        যাও gen_op8;
    ক্ষেত্র TOK_ADDC2: /* add with carry use */
        opc = 2;
        যাও gen_op8;
    ক্ষেত্র TOK_SUBC2: /* sub with carry use */
        opc = 3;
        যাও gen_op8;
    ক্ষেত্র '&':
        opc = 4;
        যাও gen_op8;
    ক্ষেত্র '^':
        opc = 6;
        যাও gen_op8;
    ক্ষেত্র '|':
        opc = 1;
        যাও gen_op8;
    ক্ষেত্র '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_মান(fr) + REG_মান(r) * 8);
        vtop--;
        বিরতি;
    ক্ষেত্র TOK_SHL:
        opc = 4;
        যাও gen_shift;
    ক্ষেত্র TOK_SHR:
        opc = 5;
        যাও gen_shift;
    ক্ষেত্র TOK_SAR:
        opc = 7;
    gen_shift:
        opc = 0xc0 | (opc << 3);
        যদি (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_মান(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } অন্যথা {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_মান(r));
        }
        vtop--;
        বিরতি;
    ক্ষেত্র TOK_UDIV:
    ক্ষেত্র TOK_UMOD:
        uu = 1;
        যাও divmod;
    ক্ষেত্র '/':
    ক্ষেত্র '%':
    ক্ষেত্র TOK_PDIV:
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
        o((uu ? 0xf0 : 0xf8) + REG_মান(fr));
        যদি (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        অন্যথা
            r = TREG_RAX;
        vtop->r = r;
        বিরতি;
    পূর্বনির্ধারিত:
        opc = 7;
        যাও gen_op8;
    }
}

শূন্য gen_opl(পূর্ণসংখ্যা op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
শূন্য gen_opf(পূর্ণসংখ্যা op)
{
    পূর্ণসংখ্যা a, ft, fc, swapped, r, opc;
    পূর্ণসংখ্যা bt = vtop->type.t & VT_BTYPE;
    পূর্ণসংখ্যা float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    যদি (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        যদি (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } অন্যথা {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, ফাঁকা, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        ফেরত;
    }

    /* convert constants to memory references */
    যদি ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    যদি ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    যদি ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    যদি (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    যদি ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        যদি (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            load(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            যদি (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            অন্যথা যদি (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            যদি (swapped)
                o(0xc9d9); /* fxch %st(1) */
            যদি (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            অন্যথা
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            যদি (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } অন্যথা যদি (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } অন্যথা যদি (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } অন্যথা {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } অন্যথা {
            /* no memory reference possible for long double operations */
            load(TREG_ST0, vtop);
            swapped = !swapped;

            নির্বাচন(op) {
            পূর্বনির্ধারিত:
            ক্ষেত্র '+':
                a = 0;
                বিরতি;
            ক্ষেত্র '-':
                a = 4;
                যদি (swapped)
                    a++;
                বিরতি;
            ক্ষেত্র '*':
                a = 1;
                বিরতি;
            ক্ষেত্র '/':
                a = 6;
                যদি (swapped)
                    a++;
                বিরতি;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } অন্যথা {
        যদি (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            যদি ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = ফাঁকা;
                load(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            যদি (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } অন্যথা {
                যদি (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                যদি (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } অন্যথা {
                    op = 0x97; /* seta */
                }
            }

            যদি (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            প্রতিজ্ঞা(!(vtop[-1].r & VT_LVAL));
            
            যদি (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            অন্যথা
                opc = 0x2f0f; /* comisd */
            যদি ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } অন্যথা {
            প্রতিজ্ঞা((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            নির্বাচন(op) {
            পূর্বনির্ধারিত:
            ক্ষেত্র '+':
                a = 0;
                বিরতি;
            ক্ষেত্র '-':
                a = 4;
                বিরতি;
            ক্ষেত্র '*':
                a = 1;
                বিরতি;
            ক্ষেত্র '/':
                a = 6;
                বিরতি;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            প্রতিজ্ঞা((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            যদি ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = ফাঁকা;
                load(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            প্রতিজ্ঞা(!(vtop[-1].r & VT_LVAL));
            যদি (swapped) {
                প্রতিজ্ঞা(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            যদি ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } অন্যথা {
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
শূন্য gen_cvt_itof(পূর্ণসংখ্যা t)
{
    যদি ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        যদি ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } অন্যথা যদি ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } অন্যথা {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } অন্যথা {
        পূর্ণসংখ্যা r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        যদি ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_মান(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
শূন্য gen_cvt_ftof(পূর্ণসংখ্যা t)
{
    পূর্ণসংখ্যা ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    যদি (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        যদি (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_মান(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_মান(vtop->r)*9);
        } অন্যথা যদি (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_মান(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } অন্যথা যদি (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        যদি (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_মান(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_মান(vtop->r)*9);
        } অন্যথা যদি (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_মান(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } অন্যথা {
        পূর্ণসংখ্যা r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        যদি (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_মান(r)*8);
            o(0xf024);
            vtop->r = r;
        } অন্যথা যদি (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_মান(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
শূন্য gen_cvt_ftoi(পূর্ণসংখ্যা t)
{
    পূর্ণসংখ্যা ft, bt, আকার_2, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    যদি (bt == VT_LDOUBLE) {
	যদি (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    ফেরত;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    যদি (t != VT_INT)
        আকার_2 = 8;
    অন্যথা
        আকার_2 = 4;

    r = get_reg(RC_INT);
    যদি (bt == VT_FLOAT) {
        o(0xf3);
    } অন্যথা যদি (bt == VT_DOUBLE) {
        o(0xf2);
    } অন্যথা {
        প্রতিজ্ঞা(0);
    }
    orex(আকার_2 == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_মান(vtop->r) + REG_মান(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC শূন্য gen_cvt_sxtw(শূন্য)
{
    পূর্ণসংখ্যা r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_মান(r) << 3) + REG_মান(r));
}

/* char/short to int conversion */
ST_FUNC শূন্য gen_cvt_csti(পূর্ণসংখ্যা t)
{
    পূর্ণসংখ্যা r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_মান(r) << 3 | REG_মান(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC শূন্য gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_text_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC শূন্য ggoto(শূন্য)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC শূন্য gen_vla_sp_save(পূর্ণসংখ্যা addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, ফাঁকা, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC শূন্য gen_vla_sp_restore(পূর্ণসংখ্যা addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, ফাঁকা, addr);
}

#ifdef TCC_TARGET_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC শূন্য gen_vla_ফলাফল(পূর্ণসংখ্যা addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, ফাঁকা, addr);
}
#endif

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC শূন্য gen_vla_alloc(CType *type, পূর্ণসংখ্যা align) {
    পূর্ণসংখ্যা use_call = 0;

#যদি defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#endif
#ifdef TCC_TARGET_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#endif
    যদি (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    অন্যথা {
        পূর্ণসংখ্যা r;
        r = gv(RC_INT); /* allocation size */
        /* sub r,%rsp */
        o(0x2b48);
        o(0xe0 | REG_মান(r));
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
ST_FUNC শূন্য gen_struct_copy(পূর্ণসংখ্যা আকার_2)
{
    পূর্ণসংখ্যা n = আকার_2 / PTR_আকার;
#ifdef TCC_TARGET_PE
    o(0x5756); /* push rsi, rdi */
#endif
    gv2(RC_RDI, RC_RSI);
    যদি (n <= 4) {
        যখন (n)
            o(0xa548), --n;
    } অন্যথা {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    যদি (আকার_2 & 0x04)
        o(0xa5);
    যদি (আকার_2 & 0x02)
        o(0xa566);
    যদি (আকার_2 & 0x01)
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
