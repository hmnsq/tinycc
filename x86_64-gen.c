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
ga_nanaa {
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
#define REG_VALUE(reg) ((reg) & 7)

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
ST_FUNC void gen_struct_copy(จำนวนเต็ม size);

/******************************************************/
#มิฉะนั้น /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#include "tcc.h"
#include <assert.h>

ST_DATA const var_na * const target_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_DATA const จำนวนเต็ม reg_classes[NB_REGS] = {
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

static unsigned long func_sub_sp_offset;
static จำนวนเต็ม func_ret_sub;

#ถ้า defined(CONFIG_TCC_BCHECK)
static addr_t func_bound_offset;
static unsigned long func_bound_ind;
ST_DATA จำนวนเต็ม func_bound_add_epilog;
#endif

#ifdef TCC_TARGET_PE
static จำนวนเต็ม func_scratch, func_alloca;
#endif

/* XXX: make it faster ? */
ST_FUNC void g(จำนวนเต็ม c)
{
    จำนวนเต็ม ind1;
    ถ้า (nocode_wanted)
        คืน;
    ind1 = ind + 1;
    ถ้า (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC void o(unsigned จำนวนเต็ม c)
{
    ขณะ (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC void gen_le16(จำนวนเต็ม v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC void gen_le32(จำนวนเต็ม c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

ST_FUNC void gen_le64(int64_t c)
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

static void orex(จำนวนเต็ม ll, จำนวนเต็ม r, จำนวนเต็ม r2, จำนวนเต็ม b)
{
    ถ้า ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    ถ้า ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    ถ้า (ll || REX_BASE(r) || REX_BASE(r2)) {
        ถ้า ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_BASE(r) | (REX_BASE(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC void gsym_addr(จำนวนเต็ม t, จำนวนเต็ม a)
{
    ขณะ (t) {
        unsigned var_na *ptr = cur_text_section->data + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

static จำนวนเต็ม is64_type(จำนวนเต็ม t)
{
    คืน ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
static จำนวนเต็ม oad(จำนวนเต็ม c, จำนวนเต็ม s)
{
    จำนวนเต็ม t;
    ถ้า (nocode_wanted)
        คืน s;
    o(c);
    t = ind;
    gen_le32(s);
    คืน t;
}

/* generate jmp to a label */
#define gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC void gen_addr32(จำนวนเต็ม r, Sym *sym, จำนวนเต็ม c)
{
    ถ้า (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC void gen_addrpc32(จำนวนเต็ม r, Sym *sym, จำนวนเต็ม c)
{
    ถ้า (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
static void gen_gotpcrel(จำนวนเต็ม r, Sym *sym, จำนวนเต็ม c)
{
#ifdef TCC_TARGET_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, NULL), c, r,
        cur_text_section->data[ind-3],
        cur_text_section->data[ind-2],
        cur_text_section->data[ind-1]
        );
#endif
    greloca(cur_text_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    ถ้า (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_VALUE(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
static void gen_modrm_impl(จำนวนเต็ม opcode, จำนวนเต็ม ll, จำนวนเต็ม op_reg_0, จำนวนเต็ม r, Sym *sym, จำนวนเต็ม c)
{
    จำนวนเต็ม op_reg = REG_VALUE(op_reg_0) << 3;

    ถ้า ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_SIZE); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#มิฉะนั้น
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#endif
        คืน;
    }

    orex(ll, r, op_reg_0, opcode);

    ถ้า ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	ถ้า (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} มิฉะนั้น {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    ถ้า (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } มิฉะนั้น {
		gen_addrpc32(r, sym, c);
	    }
	}
    } มิฉะนั้น ถ้า ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        ถ้า (c == (signed var_na)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } มิฉะนั้น {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } มิฉะนั้น ถ้า ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_VALUE(r));
        gen_le32(c);
    } มิฉะนั้น ถ้า (r & VT_LVAL) {
        g(0x00 | op_reg | REG_VALUE(r));
    } มิฉะนั้น {
        g(0xc0 | op_reg | REG_VALUE(r));
    }
}

static void gen_modrm64(จำนวนเต็ม opcode, จำนวนเต็ม op_reg, จำนวนเต็ม r, Sym *sym, จำนวนเต็ม c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

static void gen_modrm32(จำนวนเต็ม opcode, จำนวนเต็ม op_reg, จำนวนเต็ม r, Sym *sym, จำนวนเต็ม c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
void load(จำนวนเต็ม r, SValue *sv)
{
    จำนวนเต็ม v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    ถ้า (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#ifndef TCC_TARGET_PE
    /* we use indirect access via got */
    ถ้า ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        จำนวนเต็ม tr = r | TREG_MEM;
        ถ้า (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#endif

    v = fr & VT_VALMASK;
    ถ้า (fr & VT_LVAL) {
        จำนวนเต็ม b, ll;
        ถ้า (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = NULL;
            fr = r;
            ถ้า (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            load(fr, &v1);
            fr |= VT_LVAL;
        }
	ถ้า (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = NULL;
	    fr = r;
	    ถ้า (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    load(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	ถ้า ((ft & VT_BTYPE) == VT_STRUCT) {
	    จำนวนเต็ม align;
	    switch (type_size(&sv->type, &align)) {
		pak_sa 1: ft = VT_BYTE; bha_nga;
		pak_sa 2: ft = VT_SHORT; bha_nga;
		pak_sa 4: ft = VT_INT; bha_nga;
		pak_sa 8: ft = VT_LLONG; bha_nga;
		default:
		    tcc_error("invalid aggregate type for register load");
		    bha_nga;
	    }
	}
        ถ้า ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_VALUE(r); /* movd */
        } มิฉะนั้น ถ้า ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_VALUE(r);
        } มิฉะนั้น ถ้า ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } มิฉะนั้น ถ้า ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } มิฉะนั้น ถ้า ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } มิฉะนั้น ถ้า ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } มิฉะนั้น ถ้า ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } มิฉะนั้น ถ้า ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            คืน;
        } มิฉะนั้น {
            assert(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } มิฉะนั้น {
        ถ้า (v == VT_CONST) {
            ถ้า (fr & VT_SYM) {
#ifdef TCC_TARGET_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#มิฉะนั้น
                ถ้า (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, NULL, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_VALUE(r), 0);
                    greloca(cur_text_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } มิฉะนั้น ถ้า (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_VALUE(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } มิฉะนั้น {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_VALUE(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#endif
            } มิฉะนั้น ถ้า (is64_type(ft)) {
                ถ้า (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_VALUE(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } มิฉะนั้น ถ้า (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_VALUE(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } มิฉะนั้น {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_VALUE(r) * 9);
                }
            } มิฉะนั้น {
                orex(0,r,0, 0xb8 + REG_VALUE(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } มิฉะนั้น ถ้า (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } มิฉะนั้น ถ้า (v == VT_CMP) {
	    ถ้า (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_VALUE(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_BASE(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_VALUE(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_VALUE(r) * 0x900); /* movzbl %al, %eax */
        } มิฉะนั้น ถ้า (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_VALUE(r), t); /* mov $1, r */
            o(0x05eb + (REX_BASE(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_VALUE(r), t ^ 1); /* mov $0, r */
        } มิฉะนั้น ถ้า (v != r) {
            ถ้า ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                ถ้า (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_VALUE(r)*8); /* %xmmN */
                    o(0xf024);
                } มิฉะนั้น {
                    assert((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    ถ้า ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } มิฉะนั้น {
                        assert((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_VALUE(v) + REG_VALUE(r)*8);
                }
            } มิฉะนั้น ถ้า (r == TREG_ST0) {
                assert((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_VALUE(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } มิฉะนั้น {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_VALUE(r) + REG_VALUE(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
void store(จำนวนเต็ม r, SValue *v)
{
    จำนวนเต็ม fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    จำนวนเต็ม opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    ถ้า (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#ifndef TCC_TARGET_PE
    /* we need to access the variable via got */
    ถ้า ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#endif

    /* XXX: incorrect if float reg to reg */
    ถ้า (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_VALUE(r);
    } มิฉะนั้น ถ้า (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_VALUE(r);
    } มิฉะนั้น ถ้า (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } มิฉะนั้น ถ้า (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } มิฉะนั้น {
        opc = 0x89;
        ถ้า (bt == VT_SHORT)
            opc = 0x8966;
        มิฉะนั้น ถ้า (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
static void gcall_or_jmp(จำนวนเต็ม is_jmp)
{
    จำนวนเต็ม r;
    ถ้า ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (จำนวนเต็ม)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind + 1, R_X86_64_PLT32, (จำนวนเต็ม)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } มิฉะนั้น {
        /* otherwise, indirect call */
        r = TREG_R11;
        load(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_VALUE(r) + (is_jmp << 4));
    }
}

#ถ้า defined(CONFIG_TCC_BCHECK)

static void gen_bounds_call(จำนวนเต็ม v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#ifdef TCC_TARGET_PE
# define TREG_FASTCALL_1 TREG_RCX
#มิฉะนั้น
# define TREG_FASTCALL_1 TREG_RDI
#endif

static void gen_bounds_prolog(void)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->data_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
}

static void gen_bounds_epilog(void)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    จำนวนเต็ม offset_modified = func_bound_offset != lbounds_section->data_offset;

    ถ้า (!offset_modified && !func_bound_add_epilog)
        คืน;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, parimaa_na(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section, 
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    ถ้า (offset_modified) {
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
static const uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
static จำนวนเต็ม arg_prepare_reg(จำนวนเต็ม idx) {
  ถ้า (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      คืน idx + 10;
  มิฉะนั้น
      คืน idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

static void gen_offs_sp(จำนวนเต็ม b, จำนวนเต็ม r, จำนวนเต็ม d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    ถ้า (d == (signed var_na)d) {
        o(0x2444 | (REG_VALUE(r) << 3));
        g(d);
    } มิฉะนั้น {
        o(0x2484 | (REG_VALUE(r) << 3));
        gen_le32(d);
    }
}

static จำนวนเต็ม using_regs(จำนวนเต็ม size)
{
    คืน !(size > 8 || (size & (size - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC จำนวนเต็ม gfunc_sret(CType *vt, จำนวนเต็ม variadic, CType *ret, จำนวนเต็ม *ret_align, จำนวนเต็ม *regsize)
{
    จำนวนเต็ม size, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    size = type_size(vt, &align);
    ถ้า (!using_regs(size))
        คืน 0;
    ถ้า (size == 8)
        ret->t = VT_LLONG;
    มิฉะนั้น ถ้า (size == 4)
        ret->t = VT_INT;
    มิฉะนั้น ถ้า (size == 2)
        ret->t = VT_SHORT;
    มิฉะนั้น
        ret->t = VT_BYTE;
    ret->ref = NULL;
    คืน 1;
}

static จำนวนเต็ม is_sse_float(จำนวนเต็ม t) {
    จำนวนเต็ม bt;
    bt = t & VT_BTYPE;
    คืน bt == VT_DOUBLE || bt == VT_FLOAT;
}

static จำนวนเต็ม gfunc_arg_size(CType *type) {
    จำนวนเต็ม align;
    ถ้า (type->t & (VT_ARRAY|VT_BITFIELD))
        คืน 8;
    คืน type_size(type, &align);
}

void gfunc_call(จำนวนเต็ม nb_args)
{
    จำนวนเต็ม size, r, args_size, i, d, bt, struct_size;
    จำนวนเต็ม arg;

#ifdef CONFIG_TCC_BCHECK
    ถ้า (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    args_size = (nb_args < REGN ? REGN : nb_args) * PTR_SIZE;
    arg = nb_args;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_size = args_size;
    สำหรับ(i = 0; i < nb_args; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        size = gfunc_arg_size(&sv->type);

        ถ้า (using_regs(size))
            continue; /* arguments smaller than 8 bytes passed in registers or on stack */

        ถ้า (bt == VT_STRUCT) {
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
        } มิฉะนั้น ถ้า (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_size);
            struct_size += 16;
        }
    }

    ถ้า (func_scratch < struct_size)
        func_scratch = struct_size;

    arg = nb_args;
    struct_size = args_size;

    สำหรับ(i = 0; i < nb_args; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        size = gfunc_arg_size(&vtop->type);
        ถ้า (!using_regs(size)) {
            /* align to stack align size */
            size = (size + 15) & ~15;
            ถ้า (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_size);
                gen_offs_sp(0x89, d, arg*8);
            } มิฉะนั้น {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_size);
            }
            struct_size += size;
        } มิฉะนั้น {
            ถ้า (is_sse_float(vtop->type.t)) {
		ถ้า (tcc_state->nosse)
		  tcc_error("SSE disabled");
                ถ้า (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } มิฉะนั้น {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_VALUE(d));
                }
            } มิฉะนั้น {
                ถ้า (bt == VT_STRUCT) {
                    vtop->type.ref = NULL;
                    vtop->type.t = size > 4 ? VT_LLONG : size > 2 ? VT_INT
                        : size > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                ถ้า (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } มิฉะนั้น {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_VALUE(r) * 8 + REG_VALUE(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    ถ้า (nb_args > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        ถ้า (nb_args > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    ถ้า ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#ifdef CONFIG_TCC_BCHECK
        ถ้า (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#endif
    }
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

/* generate function prolog of type 't' */
void gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    จำนวนเต็ม addr, reg_param_index, bt, size;
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
    ถ้า (!using_regs(size)) {
        gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, NULL, addr);
        func_vc = addr;
        reg_param_index++;
        addr += 8;
    }

    /* define parameters */
    ขณะ ((sym = sym->next) != NULL) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        size = gfunc_arg_size(type);
        ถ้า (!using_regs(size)) {
            ถ้า (reg_param_index < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, NULL, addr);
            }
            gfunc_set_param(sym, addr, 1);
        } มิฉะนั้น {
            ถ้า (reg_param_index < REGN) {
                /* save arguments passed by register */
                ถ้า ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    ถ้า (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_index, VT_LOCAL, NULL, addr);
                } มิฉะนั้น {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, NULL, addr);
                }
            }
            gfunc_set_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_index++;
    }

    ขณะ (reg_param_index < REGN) {
        ถ้า (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, NULL, addr);
            addr += 8;
        }
        reg_param_index++;
    }
#ifdef CONFIG_TCC_BCHECK
    ถ้า (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
void gfunc_epilog(void)
{
    จำนวนเต็ม v, start;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#ifdef CONFIG_TCC_BCHECK
    ถ้า (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    o(0xc9); /* leave */
    ถ้า (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } มิฉะนั้น {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    start = func_sub_sp_offset - FUNC_PROLOG_SIZE;
    cur_text_section->data_offset = ind;
    pe_add_unwind_data(start, ind, v);

    ind = start;
    ถ้า (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } มิฉะนั้น {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_text_section->data_offset;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#มิฉะนั้น

static void gadd_sp(จำนวนเต็ม val)
{
    ถ้า (val == (signed var_na)val) {
        o(0xc48348);
        g(val);
    } มิฉะนั้น {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

typedef ga_nanaa X86_64_Mode {
  x86_64_mode_none,
  x86_64_mode_memory,
  x86_64_mode_integer,
  x86_64_mode_sse,
  x86_64_mode_x87
} X86_64_Mode;

static X86_64_Mode classify_x86_64_merge(X86_64_Mode a, X86_64_Mode b)
{
    ถ้า (a == b)
        คืน a;
    มิฉะนั้น ถ้า (a == x86_64_mode_none)
        คืน b;
    มิฉะนั้น ถ้า (b == x86_64_mode_none)
        คืน a;
    มิฉะนั้น ถ้า ((a == x86_64_mode_memory) || (b == x86_64_mode_memory))
        คืน x86_64_mode_memory;
    มิฉะนั้น ถ้า ((a == x86_64_mode_integer) || (b == x86_64_mode_integer))
        คืน x86_64_mode_integer;
    มิฉะนั้น ถ้า ((a == x86_64_mode_x87) || (b == x86_64_mode_x87))
        คืน x86_64_mode_memory;
    มิฉะนั้น
        คืน x86_64_mode_sse;
}

static X86_64_Mode classify_x86_64_inner(CType *ty)
{
    X86_64_Mode mode;
    Sym *f;
    
    switch (ty->t & VT_BTYPE) {
    pak_sa VT_VOID: คืน x86_64_mode_none;
    
    pak_sa VT_INT:
    pak_sa VT_BYTE:
    pak_sa VT_SHORT:
    pak_sa VT_LLONG:
    pak_sa VT_BOOL:
    pak_sa VT_PTR:
    pak_sa VT_FUNC:
        คืน x86_64_mode_integer;
    
    pak_sa VT_FLOAT:
    pak_sa VT_DOUBLE: คืน x86_64_mode_sse;
    
    pak_sa VT_LDOUBLE: คืน x86_64_mode_x87;
      
    pak_sa VT_STRUCT:
        f = ty->ref;

        mode = x86_64_mode_none;
        สำหรับ (f = f->next; f; f = f->next)
            mode = classify_x86_64_merge(mode, classify_x86_64_inner(&f->type));
        
        คืน mode;
    }
    assert(0);
    คืน 0;
}

static X86_64_Mode classify_x86_64_arg(CType *ty, CType *ret, จำนวนเต็ม *psize, จำนวนเต็ม *palign, จำนวนเต็ม *reg_count)
{
    X86_64_Mode mode;
    จำนวนเต็ม size, align, ret_t = 0;
    
    ถ้า (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_count = 1;
        ret_t = ty->t;
        mode = x86_64_mode_integer;
    } มิฉะนั้น {
        size = type_size(ty, &align);
        *psize = (size + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_count = 0; /* avoid compiler warning */

        ถ้า (size > 16) {
            mode = x86_64_mode_memory;
        } มิฉะนั้น {
            mode = classify_x86_64_inner(ty);
            switch (mode) {
            pak_sa x86_64_mode_integer:
                ถ้า (size > 8) {
                    *reg_count = 2;
                    ret_t = VT_QLONG;
                } มิฉะนั้น {
                    *reg_count = 1;
                    ถ้า (size > 4)
                        ret_t = VT_LLONG;
                    มิฉะนั้น ถ้า (size > 2)
                        ret_t = VT_INT;
                    มิฉะนั้น ถ้า (size > 1)
                        ret_t = VT_SHORT;
                    มิฉะนั้น
                        ret_t = VT_BYTE;
                    ถ้า ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                bha_nga;
                
            pak_sa x86_64_mode_x87:
                *reg_count = 1;
                ret_t = VT_LDOUBLE;
                bha_nga;

            pak_sa x86_64_mode_sse:
                ถ้า (size > 8) {
                    *reg_count = 2;
                    ret_t = VT_QFLOAT;
                } มิฉะนั้น {
                    *reg_count = 1;
                    ret_t = (size > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                bha_nga;
            default: bha_nga; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    ถ้า (ret) {
        ret->ref = NULL;
        ret->t = ret_t;
    }
    
    คืน mode;
}

ST_FUNC จำนวนเต็ม classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    ga_nanaa __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    จำนวนเต็ม size, align, reg_count;
    X86_64_Mode mode = classify_x86_64_arg(ty, NULL, &size, &align, &reg_count);
    switch (mode) {
    default: คืน __va_stack;
    pak_sa x86_64_mode_integer: คืน __va_gen_reg;
    pak_sa x86_64_mode_sse: คืน __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC จำนวนเต็ม gfunc_sret(CType *vt, จำนวนเต็ม variadic, CType *ret, จำนวนเต็ม *ret_align, จำนวนเต็ม *regsize)
{
    จำนวนเต็ม size, align, reg_count;
    ถ้า (classify_x86_64_arg(vt, ret, &size, &align, &reg_count) == x86_64_mode_memory)
        คืน 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_count; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    คืน 1;
}

#define REGN 6
static const uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

static จำนวนเต็ม arg_prepare_reg(จำนวนเต็ม idx) {
  ถ้า (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      คืน idx + 8;
  มิฉะนั้น
      คืน idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
void gfunc_call(จำนวนเต็ม nb_args)
{
    X86_64_Mode mode;
    CType type;
    จำนวนเต็ม size, align, r, args_size, stack_adjust, i, reg_count, k;
    จำนวนเต็ม nb_reg_args = 0;
    จำนวนเต็ม nb_sse_args = 0;
    จำนวนเต็ม sse_reg, gen_reg;
    var_na *onstack = tcc_malloc((nb_args + 1) * parimaa_na (var_na));

#ifdef CONFIG_TCC_BCHECK
    ถ้า (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    stack_adjust = 0;
    สำหรับ(i = nb_args - 1; i >= 0; i--) {
        mode = classify_x86_64_arg(&vtop[-i].type, NULL, &size, &align, &reg_count);
        ถ้า (size == 0) continue;
        ถ้า (mode == x86_64_mode_sse && nb_sse_args + reg_count <= 8) {
            nb_sse_args += reg_count;
	    onstack[i] = 0;
	} มิฉะนั้น ถ้า (mode == x86_64_mode_integer && nb_reg_args + reg_count <= REGN) {
            nb_reg_args += reg_count;
	    onstack[i] = 0;
	} มิฉะนั้น ถ้า (mode == x86_64_mode_none) {
	    onstack[i] = 0;
	} มิฉะนั้น {
	    ถ้า (align == 16 && (stack_adjust &= 15)) {
		onstack[i] = 2;
		stack_adjust = 0;
	    } มิฉะนั้น
	      onstack[i] = 1;
	    stack_adjust += size;
	}
    }

    ถ้า (nb_sse_args && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_args;
    sse_reg = nb_sse_args;
    args_size = 0;
    stack_adjust &= 15;
    สำหรับ (i = k = 0; i < nb_args;) {
	mode = classify_x86_64_arg(&vtop[-i].type, NULL, &size, &align, &reg_count);
	ถ้า (size) {
            ถ้า (!onstack[i + k]) {
	        ++i;
	        continue;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            ถ้า (stack_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                args_size += 8;
	        stack_adjust = 0;
            }
	    ถ้า (onstack[i + k] == 2)
	        stack_adjust = 1;
        }

	vrotb(i+1);

	switch (vtop->type.t & VT_BTYPE) {
	    pak_sa VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, size); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_VALUE(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_VALUE(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		bha_nga;

	    pak_sa VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, size); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		bha_nga;

	    pak_sa VT_FLOAT:
	    pak_sa VT_DOUBLE:
		assert(mode == x86_64_mode_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_VALUE(r)*8);
		o(0x24);
		bha_nga;

	    default:
		assert(mode == x86_64_mode_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_VALUE(r)); /* push r */
		bha_nga;
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
    assert(gen_reg <= REGN);
    assert(sse_reg <= 8);
    สำหรับ(i = 0; i < nb_args; i++) {
        mode = classify_x86_64_arg(&vtop->type, &type, &size, &align, &reg_count);
        ถ้า (size == 0) continue;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        ถ้า (mode == x86_64_mode_sse) {
            ถ้า (reg_count == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                ถ้า (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } มิฉะนั้น {
                assert(reg_count == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } มิฉะนั้น ถ้า (mode == x86_64_mode_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            จำนวนเต็ม d;
            gen_reg -= reg_count;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_VALUE(r) * 8 + REG_VALUE(d));
            ถ้า (reg_count == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_VALUE(vtop->r2) * 8 + REG_VALUE(d));
            }
        }
        vtop--;
    }
    assert(gen_reg == 0);
    assert(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    ถ้า (nb_reg_args > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        ถ้า (nb_reg_args > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    ถ้า (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_args < 8 ? nb_sse_args : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    ถ้า (args_size)
        gadd_sp(args_size);
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

static void push_arg_reg(จำนวนเต็ม i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, NULL, loc);
}

/* generate function prolog of type 't' */
void gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_Mode mode, ret_mode;
    จำนวนเต็ม i, addr, align, size, reg_count;
    จำนวนเต็ม param_addr = 0, reg_param_index, sse_param_index;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_SIZE * 2;
    loc = 0;
    ind += FUNC_PROLOG_SIZE;
    func_sub_sp_offset = ind;
    func_ret_sub = 0;
    ret_mode = classify_x86_64_arg(&func_vt, NULL, &size, &align, &reg_count);

    ถ้า (func_var) {
        จำนวนเต็ม seen_reg_num, seen_sse_num, seen_stack_size;
        seen_reg_num = ret_mode == x86_64_mode_memory;
        seen_sse_num = 0;
        /* frame pointer and return address */
        seen_stack_size = PTR_SIZE * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        ขณะ ((sym = sym->next) != NULL) {
            type = &sym->type;
            mode = classify_x86_64_arg(type, NULL, &size, &align, &reg_count);
            switch (mode) {
            default:
            stack_arg:
                seen_stack_size = ((seen_stack_size + align - 1) & -align) + size;
                bha_nga;
                
            pak_sa x86_64_mode_integer:
                ถ้า (seen_reg_num + reg_count > REGN)
		    goto stack_arg;
		seen_reg_num += reg_count;
                bha_nga;
                
            pak_sa x86_64_mode_sse:
                ถ้า (seen_sse_num + reg_count > 8)
		    goto stack_arg;
		seen_sse_num += reg_count;
                bha_nga;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(seen_reg_num * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(seen_sse_num * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(seen_stack_size);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        สำหรับ (i = 0; i < 8; i++) {
            loc -= 16;
	    ถ้า (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, NULL, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        สำหรับ (i = 0; i < REGN; i++) {
            push_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_index = 0;
    sse_param_index = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    ถ้า (ret_mode == x86_64_mode_memory) {
        push_arg_reg(reg_param_index);
        func_vc = loc;
        reg_param_index++;
    }
    /* define parameters */
    ขณะ ((sym = sym->next) != NULL) {
        type = &sym->type;
        mode = classify_x86_64_arg(type, NULL, &size, &align, &reg_count);
        switch (mode) {
        pak_sa x86_64_mode_sse:
	    ถ้า (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            ถ้า (sse_param_index + reg_count <= 8) {
                /* save arguments passed by register */
                loc -= reg_count * 8;
                param_addr = loc;
                สำหรับ (i = 0; i < reg_count; ++i) {
                    gen_modrm32(0xd60f66, sse_param_index, VT_LOCAL, NULL, param_addr + i*8);
                    ++sse_param_index;
                }
            } มิฉะนั้น {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            bha_nga;
            
        pak_sa x86_64_mode_memory:
        pak_sa x86_64_mode_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += size;
            bha_nga;
            
        pak_sa x86_64_mode_integer: {
            ถ้า (reg_param_index + reg_count <= REGN) {
                /* save arguments passed by register */
                loc -= reg_count * 8;
                param_addr = loc;
                สำหรับ (i = 0; i < reg_count; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, NULL, param_addr + i*8);
                    ++reg_param_index;
                }
            } มิฉะนั้น {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            bha_nga;
        }
	default: bha_nga; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_set_param(sym, param_addr, 0);
    }

#ifdef CONFIG_TCC_BCHECK
    ถ้า (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
void gfunc_epilog(void)
{
    จำนวนเต็ม v, saved_ind;

#ifdef CONFIG_TCC_BCHECK
    ถ้า (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif
    o(0xc9); /* leave */
    ถ้า (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } มิฉะนั้น {
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

ST_FUNC void gen_fill_nops(จำนวนเต็ม bytes)
{
    ขณะ (bytes--)
      g(0x90);
}

/* generate a jump to a label */
จำนวนเต็ม gjmp(จำนวนเต็ม t)
{
    คืน gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
void gjmp_addr(จำนวนเต็ม a)
{
    จำนวนเต็ม r;
    r = a - ind - 2;
    ถ้า (r == (signed var_na)r) {
        g(0xeb);
        g(r);
    } มิฉะนั้น {
        oad(0xe9, a - ind - 5);
    }
}

ST_FUNC จำนวนเต็ม gjmp_append(จำนวนเต็ม n, จำนวนเต็ม t)
{
    void *p;
    /* insert vtop->c jump list in t */
    ถ้า (n) {
        uint32_t n1 = n, n2;
        ขณะ ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    คืน t;
}

ST_FUNC จำนวนเต็ม gjmp_cond(จำนวนเต็ม op, จำนวนเต็ม t)
{
        ถ้า (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            จำนวนเต็ม v = vtop->cmp_r;
            op &= ~0x100;
            ถ้า (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    มิฉะนั้น
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        คืน t;
}

/* generate an integer binary operation */
void gen_opi(จำนวนเต็ม op)
{
    จำนวนเต็ม r, fr, opc, c;
    จำนวนเต็ม ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    switch(op) {
    pak_sa '+':
    pak_sa TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        ถ้า (cc && (!ll || (จำนวนเต็ม)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            ถ้า (c == (signed var_na)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_VALUE(r));
                g(c);
            } มิฉะนั้น {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_VALUE(r), c);
            }
        } มิฉะนั้น {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_VALUE(r) + REG_VALUE(fr) * 8);
        }
        vtop--;
        ถ้า (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        bha_nga;
    pak_sa '-':
    pak_sa TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        goto gen_op8;
    pak_sa TOK_ADDC2: /* add with carry use */
        opc = 2;
        goto gen_op8;
    pak_sa TOK_SUBC2: /* sub with carry use */
        opc = 3;
        goto gen_op8;
    pak_sa '&':
        opc = 4;
        goto gen_op8;
    pak_sa '^':
        opc = 6;
        goto gen_op8;
    pak_sa '|':
        opc = 1;
        goto gen_op8;
    pak_sa '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_VALUE(fr) + REG_VALUE(r) * 8);
        vtop--;
        bha_nga;
    pak_sa TOK_SHL:
        opc = 4;
        goto gen_shift;
    pak_sa TOK_SHR:
        opc = 5;
        goto gen_shift;
    pak_sa TOK_SAR:
        opc = 7;
    gen_shift:
        opc = 0xc0 | (opc << 3);
        ถ้า (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_VALUE(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } มิฉะนั้น {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_VALUE(r));
        }
        vtop--;
        bha_nga;
    pak_sa TOK_UDIV:
    pak_sa TOK_UMOD:
        uu = 1;
        goto divmod;
    pak_sa '/':
    pak_sa '%':
    pak_sa TOK_PDIV:
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
        o((uu ? 0xf0 : 0xf8) + REG_VALUE(fr));
        ถ้า (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        มิฉะนั้น
            r = TREG_RAX;
        vtop->r = r;
        bha_nga;
    default:
        opc = 7;
        goto gen_op8;
    }
}

void gen_opl(จำนวนเต็ม op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
void gen_opf(จำนวนเต็ม op)
{
    จำนวนเต็ม a, ft, fc, swapped, r, opc;
    จำนวนเต็ม bt = vtop->type.t & VT_BTYPE;
    จำนวนเต็ม float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    ถ้า (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        ถ้า (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } มิฉะนั้น {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, NULL, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        คืน;
    }

    /* convert constants to memory references */
    ถ้า ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    ถ้า ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    ถ้า ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    ถ้า (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    ถ้า ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        ถ้า (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            load(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            ถ้า (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            มิฉะนั้น ถ้า (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            ถ้า (swapped)
                o(0xc9d9); /* fxch %st(1) */
            ถ้า (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            มิฉะนั้น
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            ถ้า (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } มิฉะนั้น ถ้า (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } มิฉะนั้น ถ้า (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } มิฉะนั้น {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } มิฉะนั้น {
            /* no memory reference possible for long double operations */
            load(TREG_ST0, vtop);
            swapped = !swapped;

            switch(op) {
            default:
            pak_sa '+':
                a = 0;
                bha_nga;
            pak_sa '-':
                a = 4;
                ถ้า (swapped)
                    a++;
                bha_nga;
            pak_sa '*':
                a = 1;
                bha_nga;
            pak_sa '/':
                a = 6;
                ถ้า (swapped)
                    a++;
                bha_nga;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } มิฉะนั้น {
        ถ้า (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            ถ้า ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = NULL;
                load(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            ถ้า (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } มิฉะนั้น {
                ถ้า (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                ถ้า (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } มิฉะนั้น {
                    op = 0x97; /* seta */
                }
            }

            ถ้า (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            assert(!(vtop[-1].r & VT_LVAL));
            
            ถ้า (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            มิฉะนั้น
                opc = 0x2f0f; /* comisd */
            ถ้า ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } มิฉะนั้น {
            assert((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            switch(op) {
            default:
            pak_sa '+':
                a = 0;
                bha_nga;
            pak_sa '-':
                a = 4;
                bha_nga;
            pak_sa '*':
                a = 1;
                bha_nga;
            pak_sa '/':
                a = 6;
                bha_nga;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            assert((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            ถ้า ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = NULL;
                load(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            assert(!(vtop[-1].r & VT_LVAL));
            ถ้า (swapped) {
                assert(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            ถ้า ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } มิฉะนั้น {
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
void gen_cvt_itof(จำนวนเต็ม t)
{
    ถ้า ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        ถ้า ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } มิฉะนั้น ถ้า ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } มิฉะนั้น {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } มิฉะนั้น {
        จำนวนเต็ม r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        ถ้า ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_VALUE(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
void gen_cvt_ftof(จำนวนเต็ม t)
{
    จำนวนเต็ม ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    ถ้า (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        ถ้า (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_VALUE(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_VALUE(vtop->r)*9);
        } มิฉะนั้น ถ้า (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_VALUE(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } มิฉะนั้น ถ้า (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        ถ้า (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_VALUE(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_VALUE(vtop->r)*9);
        } มิฉะนั้น ถ้า (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_VALUE(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } มิฉะนั้น {
        จำนวนเต็ม r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        ถ้า (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_VALUE(r)*8);
            o(0xf024);
            vtop->r = r;
        } มิฉะนั้น ถ้า (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_VALUE(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
void gen_cvt_ftoi(จำนวนเต็ม t)
{
    จำนวนเต็ม ft, bt, size, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    ถ้า (bt == VT_LDOUBLE) {
	ถ้า (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    คืน;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    ถ้า (t != VT_INT)
        size = 8;
    มิฉะนั้น
        size = 4;

    r = get_reg(RC_INT);
    ถ้า (bt == VT_FLOAT) {
        o(0xf3);
    } มิฉะนั้น ถ้า (bt == VT_DOUBLE) {
        o(0xf2);
    } มิฉะนั้น {
        assert(0);
    }
    orex(size == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_VALUE(vtop->r) + REG_VALUE(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC void gen_cvt_sxtw(void)
{
    จำนวนเต็ม r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_VALUE(r) << 3) + REG_VALUE(r));
}

/* char/short to int conversion */
ST_FUNC void gen_cvt_csti(จำนวนเต็ม t)
{
    จำนวนเต็ม r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_VALUE(r) << 3 | REG_VALUE(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC void gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_text_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC void ggoto(void)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC void gen_vla_sp_save(จำนวนเต็ม addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, NULL, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC void gen_vla_sp_restore(จำนวนเต็ม addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, NULL, addr);
}

#ifdef TCC_TARGET_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC void gen_vla_result(จำนวนเต็ม addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, NULL, addr);
}
#endif

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC void gen_vla_alloc(CType *type, จำนวนเต็ม align) {
    จำนวนเต็ม use_call = 0;

#ถ้า defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#endif
#ifdef TCC_TARGET_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#endif
    ถ้า (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    มิฉะนั้น {
        จำนวนเต็ม r;
        r = gv(RC_INT); /* allocation size */
        /* sub r,%rsp */
        o(0x2b48);
        o(0xe0 | REG_VALUE(r));
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
ST_FUNC void gen_struct_copy(จำนวนเต็ม size)
{
    จำนวนเต็ม n = size / PTR_SIZE;
#ifdef TCC_TARGET_PE
    o(0x5756); /* push rsi, rdi */
#endif
    gv2(RC_RDI, RC_RSI);
    ถ้า (n <= 4) {
        ขณะ (n)
            o(0xa548), --n;
    } มิฉะนั้น {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    ถ้า (size & 0x04)
        o(0xa5);
    ถ้า (size & 0x02)
        o(0xa566);
    ถ้า (size & 0x01)
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
