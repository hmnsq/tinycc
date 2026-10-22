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
شمارش {
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
#define REG_مقدار(reg) ((reg) & 7)

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
ST_FUNC تهی gen_struct_copy(صحیح size);

/******************************************************/
#وگرنه /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#شامل "tcc.h"
#شامل <assert.h>

ST_DATA ثابت نویسه * ثابت target_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_DATA ثابت صحیح reg_classes[NB_REGS] = {
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

ایستا unsigned long func_sub_sp_offset;
ایستا صحیح func_ret_sub;

#اگر defined(CONFIG_TCC_BCHECK)
ایستا addr_t func_bound_offset;
ایستا unsigned long func_bound_ind;
ST_DATA صحیح func_bound_add_epilog;
#endif

#ifdef TCC_TARGET_PE
ایستا صحیح func_scratch, func_alloca;
#endif

/* XXX: make it faster ? */
ST_FUNC تهی g(صحیح c)
{
    صحیح ind1;
    اگر (nocode_wanted)
        بازگشت;
    ind1 = ind + 1;
    اگر (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC تهی o(unsigned صحیح c)
{
    وقتی (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC تهی gen_le16(صحیح v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC تهی gen_le32(صحیح c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

ST_FUNC تهی gen_le64(int64_t c)
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

ایستا تهی orex(صحیح ll, صحیح r, صحیح r2, صحیح b)
{
    اگر ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    اگر ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    اگر (ll || REX_BASE(r) || REX_BASE(r2)) {
        اگر ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_BASE(r) | (REX_BASE(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC تهی gsym_addr(صحیح t, صحیح a)
{
    وقتی (t) {
        unsigned نویسه *ptr = cur_text_section->data + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

ایستا صحیح is64_type(صحیح t)
{
    بازگشت ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
ایستا صحیح oad(صحیح c, صحیح s)
{
    صحیح t;
    اگر (nocode_wanted)
        بازگشت s;
    o(c);
    t = ind;
    gen_le32(s);
    بازگشت t;
}

/* generate jmp to a label */
#define gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC تهی gen_addr32(صحیح r, Sym *sym, صحیح c)
{
    اگر (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC تهی gen_addrpc32(صحیح r, Sym *sym, صحیح c)
{
    اگر (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
ایستا تهی gen_gotpcrel(صحیح r, Sym *sym, صحیح c)
{
#ifdef TCC_TARGET_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, پوچ), c, r,
        cur_text_section->data[ind-3],
        cur_text_section->data[ind-2],
        cur_text_section->data[ind-1]
        );
#endif
    greloca(cur_text_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    اگر (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_مقدار(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
ایستا تهی gen_modrm_impl(صحیح opcode, صحیح ll, صحیح op_reg_0, صحیح r, Sym *sym, صحیح c)
{
    صحیح op_reg = REG_مقدار(op_reg_0) << 3;

    اگر ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_SIZE); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#وگرنه
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#endif
        بازگشت;
    }

    orex(ll, r, op_reg_0, opcode);

    اگر ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	اگر (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} وگرنه {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    اگر (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } وگرنه {
		gen_addrpc32(r, sym, c);
	    }
	}
    } وگرنه اگر ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        اگر (c == (signed نویسه)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } وگرنه {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } وگرنه اگر ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_مقدار(r));
        gen_le32(c);
    } وگرنه اگر (r & VT_LVAL) {
        g(0x00 | op_reg | REG_مقدار(r));
    } وگرنه {
        g(0xc0 | op_reg | REG_مقدار(r));
    }
}

ایستا تهی gen_modrm64(صحیح opcode, صحیح op_reg, صحیح r, Sym *sym, صحیح c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

ایستا تهی gen_modrm32(صحیح opcode, صحیح op_reg, صحیح r, Sym *sym, صحیح c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
تهی load(صحیح r, SValue *sv)
{
    صحیح v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    اگر (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#ifndef TCC_TARGET_PE
    /* we use indirect access via got */
    اگر ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        صحیح tr = r | TREG_MEM;
        اگر (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#endif

    v = fr & VT_VALMASK;
    اگر (fr & VT_LVAL) {
        صحیح b, ll;
        اگر (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = پوچ;
            fr = r;
            اگر (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            load(fr, &v1);
            fr |= VT_LVAL;
        }
	اگر (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = پوچ;
	    fr = r;
	    اگر (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    load(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	اگر ((ft & VT_BTYPE) == VT_STRUCT) {
	    صحیح align;
	    انتخاب (type_size(&sv->type, &align)) {
		حالت 1: ft = VT_BYTE; بشکن;
		حالت 2: ft = VT_SHORT; بشکن;
		حالت 4: ft = VT_INT; بشکن;
		حالت 8: ft = VT_LLONG; بشکن;
		پیشفرض:
		    tcc_error("invalid aggregate type for register load");
		    بشکن;
	    }
	}
        اگر ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_مقدار(r); /* movd */
        } وگرنه اگر ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_مقدار(r);
        } وگرنه اگر ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } وگرنه اگر ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } وگرنه اگر ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } وگرنه اگر ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } وگرنه اگر ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } وگرنه اگر ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            بازگشت;
        } وگرنه {
            أكد(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } وگرنه {
        اگر (v == VT_CONST) {
            اگر (fr & VT_SYM) {
#ifdef TCC_TARGET_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#وگرنه
                اگر (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, پوچ, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_مقدار(r), 0);
                    greloca(cur_text_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } وگرنه اگر (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_مقدار(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } وگرنه {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_مقدار(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#endif
            } وگرنه اگر (is64_type(ft)) {
                اگر (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_مقدار(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } وگرنه اگر (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_مقدار(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } وگرنه {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_مقدار(r) * 9);
                }
            } وگرنه {
                orex(0,r,0, 0xb8 + REG_مقدار(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } وگرنه اگر (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } وگرنه اگر (v == VT_CMP) {
	    اگر (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_مقدار(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_BASE(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_مقدار(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_مقدار(r) * 0x900); /* movzbl %al, %eax */
        } وگرنه اگر (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_مقدار(r), t); /* mov $1, r */
            o(0x05eb + (REX_BASE(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_مقدار(r), t ^ 1); /* mov $0, r */
        } وگرنه اگر (v != r) {
            اگر ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                اگر (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_مقدار(r)*8); /* %xmmN */
                    o(0xf024);
                } وگرنه {
                    أكد((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    اگر ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } وگرنه {
                        أكد((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_مقدار(v) + REG_مقدار(r)*8);
                }
            } وگرنه اگر (r == TREG_ST0) {
                أكد((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_مقدار(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } وگرنه {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_مقدار(r) + REG_مقدار(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
تهی store(صحیح r, SValue *v)
{
    صحیح fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    صحیح opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    اگر (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#ifndef TCC_TARGET_PE
    /* we need to access the variable via got */
    اگر ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#endif

    /* XXX: incorrect if float reg to reg */
    اگر (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_مقدار(r);
    } وگرنه اگر (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_مقدار(r);
    } وگرنه اگر (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } وگرنه اگر (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } وگرنه {
        opc = 0x89;
        اگر (bt == VT_SHORT)
            opc = 0x8966;
        وگرنه اگر (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
ایستا تهی gcall_or_jmp(صحیح is_jmp)
{
    صحیح r;
    اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (صحیح)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind + 1, R_X86_64_PLT32, (صحیح)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } وگرنه {
        /* otherwise, indirect call */
        r = TREG_R11;
        load(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_مقدار(r) + (is_jmp << 4));
    }
}

#اگر defined(CONFIG_TCC_BCHECK)

ایستا تهی gen_bounds_call(صحیح v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#ifdef TCC_TARGET_PE
# define TREG_FASTCALL_1 TREG_RCX
#وگرنه
# define TREG_FASTCALL_1 TREG_RDI
#endif

ایستا تهی gen_bounds_prolog(تهی)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->data_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
}

ایستا تهی gen_bounds_epilog(تهی)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    صحیح offset_modified = func_bound_offset != lbounds_section->data_offset;

    اگر (!offset_modified && !func_bound_add_epilog)
        بازگشت;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, اندازه(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section, 
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    اگر (offset_modified) {
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
ایستا ثابت uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
ایستا صحیح arg_prepare_reg(صحیح idx) {
  اگر (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      بازگشت idx + 10;
  وگرنه
      بازگشت idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

ایستا تهی gen_offs_sp(صحیح b, صحیح r, صحیح d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    اگر (d == (signed نویسه)d) {
        o(0x2444 | (REG_مقدار(r) << 3));
        g(d);
    } وگرنه {
        o(0x2484 | (REG_مقدار(r) << 3));
        gen_le32(d);
    }
}

ایستا صحیح using_regs(صحیح size)
{
    بازگشت !(size > 8 || (size & (size - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحیح gfunc_sret(CType *vt, صحیح variadic, CType *ret, صحیح *ret_align, صحیح *regsize)
{
    صحیح size, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    size = type_size(vt, &align);
    اگر (!using_regs(size))
        بازگشت 0;
    اگر (size == 8)
        ret->t = VT_LLONG;
    وگرنه اگر (size == 4)
        ret->t = VT_INT;
    وگرنه اگر (size == 2)
        ret->t = VT_SHORT;
    وگرنه
        ret->t = VT_BYTE;
    ret->ref = پوچ;
    بازگشت 1;
}

ایستا صحیح is_sse_float(صحیح t) {
    صحیح bt;
    bt = t & VT_BTYPE;
    بازگشت bt == VT_DOUBLE || bt == VT_FLOAT;
}

ایستا صحیح gfunc_arg_size(CType *type) {
    صحیح align;
    اگر (type->t & (VT_ARRAY|VT_BITFIELD))
        بازگشت 8;
    بازگشت type_size(type, &align);
}

تهی gfunc_call(صحیح nb_args)
{
    صحیح size, r, args_size, i, d, bt, struct_size;
    صحیح arg;

#ifdef CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    args_size = (nb_args < REGN ? REGN : nb_args) * PTR_SIZE;
    arg = nb_args;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_size = args_size;
    برای(i = 0; i < nb_args; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        size = gfunc_arg_size(&sv->type);

        اگر (using_regs(size))
            ادامه; /* arguments smaller than 8 bytes passed in registers or on stack */

        اگر (bt == VT_STRUCT) {
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
        } وگرنه اگر (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_size);
            struct_size += 16;
        }
    }

    اگر (func_scratch < struct_size)
        func_scratch = struct_size;

    arg = nb_args;
    struct_size = args_size;

    برای(i = 0; i < nb_args; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        size = gfunc_arg_size(&vtop->type);
        اگر (!using_regs(size)) {
            /* align to stack align size */
            size = (size + 15) & ~15;
            اگر (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_size);
                gen_offs_sp(0x89, d, arg*8);
            } وگرنه {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_size);
            }
            struct_size += size;
        } وگرنه {
            اگر (is_sse_float(vtop->type.t)) {
		اگر (tcc_state->nosse)
		  tcc_error("SSE disabled");
                اگر (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } وگرنه {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_مقدار(d));
                }
            } وگرنه {
                اگر (bt == VT_STRUCT) {
                    vtop->type.ref = پوچ;
                    vtop->type.t = size > 4 ? VT_LLONG : size > 2 ? VT_INT
                        : size > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                اگر (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } وگرنه {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_مقدار(r) * 8 + REG_مقدار(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    اگر (nb_args > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        اگر (nb_args > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    اگر ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#ifdef CONFIG_TCC_BCHECK
        اگر (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#endif
    }
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

/* generate function prolog of type 't' */
تهی gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    صحیح addr, reg_param_index, bt, size;
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
    اگر (!using_regs(size)) {
        gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, پوچ, addr);
        func_vc = addr;
        reg_param_index++;
        addr += 8;
    }

    /* define parameters */
    وقتی ((sym = sym->next) != پوچ) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        size = gfunc_arg_size(type);
        اگر (!using_regs(size)) {
            اگر (reg_param_index < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, پوچ, addr);
            }
            gfunc_set_param(sym, addr, 1);
        } وگرنه {
            اگر (reg_param_index < REGN) {
                /* save arguments passed by register */
                اگر ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    اگر (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_index, VT_LOCAL, پوچ, addr);
                } وگرنه {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, پوچ, addr);
                }
            }
            gfunc_set_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_index++;
    }

    وقتی (reg_param_index < REGN) {
        اگر (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, پوچ, addr);
            addr += 8;
        }
        reg_param_index++;
    }
#ifdef CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
تهی gfunc_epilog(تهی)
{
    صحیح v, start;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#ifdef CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    o(0xc9); /* leave */
    اگر (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } وگرنه {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    start = func_sub_sp_offset - FUNC_PROLOG_SIZE;
    cur_text_section->data_offset = ind;
    pe_add_unwind_data(start, ind, v);

    ind = start;
    اگر (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } وگرنه {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_text_section->data_offset;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#وگرنه

ایستا تهی gadd_sp(صحیح val)
{
    اگر (val == (signed نویسه)val) {
        o(0xc48348);
        g(val);
    } وگرنه {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

تعریفنوع شمارش X86_64_Mode {
  x86_64_mode_none,
  x86_64_mode_memory,
  x86_64_mode_integer,
  x86_64_mode_sse,
  x86_64_mode_x87
} X86_64_Mode;

ایستا X86_64_Mode classify_x86_64_merge(X86_64_Mode a, X86_64_Mode b)
{
    اگر (a == b)
        بازگشت a;
    وگرنه اگر (a == x86_64_mode_none)
        بازگشت b;
    وگرنه اگر (b == x86_64_mode_none)
        بازگشت a;
    وگرنه اگر ((a == x86_64_mode_memory) || (b == x86_64_mode_memory))
        بازگشت x86_64_mode_memory;
    وگرنه اگر ((a == x86_64_mode_integer) || (b == x86_64_mode_integer))
        بازگشت x86_64_mode_integer;
    وگرنه اگر ((a == x86_64_mode_x87) || (b == x86_64_mode_x87))
        بازگشت x86_64_mode_memory;
    وگرنه
        بازگشت x86_64_mode_sse;
}

ایستا X86_64_Mode classify_x86_64_inner(CType *ty)
{
    X86_64_Mode mode;
    Sym *f;
    
    انتخاب (ty->t & VT_BTYPE) {
    حالت VT_VOID: بازگشت x86_64_mode_none;
    
    حالت VT_INT:
    حالت VT_BYTE:
    حالت VT_SHORT:
    حالت VT_LLONG:
    حالت VT_BOOL:
    حالت VT_PTR:
    حالت VT_FUNC:
        بازگشت x86_64_mode_integer;
    
    حالت VT_FLOAT:
    حالت VT_DOUBLE: بازگشت x86_64_mode_sse;
    
    حالت VT_LDOUBLE: بازگشت x86_64_mode_x87;
      
    حالت VT_STRUCT:
        f = ty->ref;

        mode = x86_64_mode_none;
        برای (f = f->next; f; f = f->next)
            mode = classify_x86_64_merge(mode, classify_x86_64_inner(&f->type));
        
        بازگشت mode;
    }
    أكد(0);
    بازگشت 0;
}

ایستا X86_64_Mode classify_x86_64_arg(CType *ty, CType *ret, صحیح *psize, صحیح *palign, صحیح *reg_شمار)
{
    X86_64_Mode mode;
    صحیح size, align, ret_t = 0;
    
    اگر (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_شمار = 1;
        ret_t = ty->t;
        mode = x86_64_mode_integer;
    } وگرنه {
        size = type_size(ty, &align);
        *psize = (size + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_شمار = 0; /* avoid compiler warning */

        اگر (size > 16) {
            mode = x86_64_mode_memory;
        } وگرنه {
            mode = classify_x86_64_inner(ty);
            انتخاب (mode) {
            حالت x86_64_mode_integer:
                اگر (size > 8) {
                    *reg_شمار = 2;
                    ret_t = VT_QLONG;
                } وگرنه {
                    *reg_شمار = 1;
                    اگر (size > 4)
                        ret_t = VT_LLONG;
                    وگرنه اگر (size > 2)
                        ret_t = VT_INT;
                    وگرنه اگر (size > 1)
                        ret_t = VT_SHORT;
                    وگرنه
                        ret_t = VT_BYTE;
                    اگر ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                بشکن;
                
            حالت x86_64_mode_x87:
                *reg_شمار = 1;
                ret_t = VT_LDOUBLE;
                بشکن;

            حالت x86_64_mode_sse:
                اگر (size > 8) {
                    *reg_شمار = 2;
                    ret_t = VT_QFLOAT;
                } وگرنه {
                    *reg_شمار = 1;
                    ret_t = (size > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                بشکن;
            پیشفرض: بشکن; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    اگر (ret) {
        ret->ref = پوچ;
        ret->t = ret_t;
    }
    
    بازگشت mode;
}

ST_FUNC صحیح classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    شمارش __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    صحیح size, align, reg_شمار;
    X86_64_Mode mode = classify_x86_64_arg(ty, پوچ, &size, &align, &reg_شمار);
    انتخاب (mode) {
    پیشفرض: بازگشت __va_stack;
    حالت x86_64_mode_integer: بازگشت __va_gen_reg;
    حالت x86_64_mode_sse: بازگشت __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحیح gfunc_sret(CType *vt, صحیح variadic, CType *ret, صحیح *ret_align, صحیح *regsize)
{
    صحیح size, align, reg_شمار;
    اگر (classify_x86_64_arg(vt, ret, &size, &align, &reg_شمار) == x86_64_mode_memory)
        بازگشت 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_شمار; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    بازگشت 1;
}

#define REGN 6
ایستا ثابت uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

ایستا صحیح arg_prepare_reg(صحیح idx) {
  اگر (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      بازگشت idx + 8;
  وگرنه
      بازگشت idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
تهی gfunc_call(صحیح nb_args)
{
    X86_64_Mode mode;
    CType type;
    صحیح size, align, r, args_size, پشته_adjust, i, reg_شمار, k;
    صحیح nb_reg_args = 0;
    صحیح nb_sse_args = 0;
    صحیح sse_reg, gen_reg;
    نویسه *onstack = tcc_malloc((nb_args + 1) * اندازه (نویسه));

#ifdef CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    پشته_adjust = 0;
    برای(i = nb_args - 1; i >= 0; i--) {
        mode = classify_x86_64_arg(&vtop[-i].type, پوچ, &size, &align, &reg_شمار);
        اگر (size == 0) ادامه;
        اگر (mode == x86_64_mode_sse && nb_sse_args + reg_شمار <= 8) {
            nb_sse_args += reg_شمار;
	    onstack[i] = 0;
	} وگرنه اگر (mode == x86_64_mode_integer && nb_reg_args + reg_شمار <= REGN) {
            nb_reg_args += reg_شمار;
	    onstack[i] = 0;
	} وگرنه اگر (mode == x86_64_mode_none) {
	    onstack[i] = 0;
	} وگرنه {
	    اگر (align == 16 && (پشته_adjust &= 15)) {
		onstack[i] = 2;
		پشته_adjust = 0;
	    } وگرنه
	      onstack[i] = 1;
	    پشته_adjust += size;
	}
    }

    اگر (nb_sse_args && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_args;
    sse_reg = nb_sse_args;
    args_size = 0;
    پشته_adjust &= 15;
    برای (i = k = 0; i < nb_args;) {
	mode = classify_x86_64_arg(&vtop[-i].type, پوچ, &size, &align, &reg_شمار);
	اگر (size) {
            اگر (!onstack[i + k]) {
	        ++i;
	        ادامه;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            اگر (پشته_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                args_size += 8;
	        پشته_adjust = 0;
            }
	    اگر (onstack[i + k] == 2)
	        پشته_adjust = 1;
        }

	vrotb(i+1);

	انتخاب (vtop->type.t & VT_BTYPE) {
	    حالت VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, size); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_مقدار(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_مقدار(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		بشکن;

	    حالت VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, size); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		بشکن;

	    حالت VT_FLOAT:
	    حالت VT_DOUBLE:
		أكد(mode == x86_64_mode_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_مقدار(r)*8);
		o(0x24);
		بشکن;

	    پیشفرض:
		أكد(mode == x86_64_mode_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_مقدار(r)); /* push r */
		بشکن;
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
    أكد(gen_reg <= REGN);
    أكد(sse_reg <= 8);
    برای(i = 0; i < nb_args; i++) {
        mode = classify_x86_64_arg(&vtop->type, &type, &size, &align, &reg_شمار);
        اگر (size == 0) ادامه;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        اگر (mode == x86_64_mode_sse) {
            اگر (reg_شمار == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                اگر (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } وگرنه {
                أكد(reg_شمار == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } وگرنه اگر (mode == x86_64_mode_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            صحیح d;
            gen_reg -= reg_شمار;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_مقدار(r) * 8 + REG_مقدار(d));
            اگر (reg_شمار == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_مقدار(vtop->r2) * 8 + REG_مقدار(d));
            }
        }
        vtop--;
    }
    أكد(gen_reg == 0);
    أكد(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    اگر (nb_reg_args > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        اگر (nb_reg_args > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    اگر (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_args < 8 ? nb_sse_args : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    اگر (args_size)
        gadd_sp(args_size);
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

ایستا تهی افزودن_arg_reg(صحیح i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, پوچ, loc);
}

/* generate function prolog of type 't' */
تهی gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_Mode mode, ret_mode;
    صحیح i, addr, align, size, reg_شمار;
    صحیح param_addr = 0, reg_param_index, sse_param_index;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_SIZE * 2;
    loc = 0;
    ind += FUNC_PROLOG_SIZE;
    func_sub_sp_offset = ind;
    func_ret_sub = 0;
    ret_mode = classify_x86_64_arg(&func_vt, پوچ, &size, &align, &reg_شمار);

    اگر (func_var) {
        صحیح seen_reg_رقم, seen_sse_رقم, seen_پشته_size;
        seen_reg_رقم = ret_mode == x86_64_mode_memory;
        seen_sse_رقم = 0;
        /* frame pointer and return address */
        seen_پشته_size = PTR_SIZE * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        وقتی ((sym = sym->next) != پوچ) {
            type = &sym->type;
            mode = classify_x86_64_arg(type, پوچ, &size, &align, &reg_شمار);
            انتخاب (mode) {
            پیشفرض:
            پشته_arg:
                seen_پشته_size = ((seen_پشته_size + align - 1) & -align) + size;
                بشکن;
                
            حالت x86_64_mode_integer:
                اگر (seen_reg_رقم + reg_شمار > REGN)
		    برو پشته_arg;
		seen_reg_رقم += reg_شمار;
                بشکن;
                
            حالت x86_64_mode_sse:
                اگر (seen_sse_رقم + reg_شمار > 8)
		    برو پشته_arg;
		seen_sse_رقم += reg_شمار;
                بشکن;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(seen_reg_رقم * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(seen_sse_رقم * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(seen_پشته_size);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        برای (i = 0; i < 8; i++) {
            loc -= 16;
	    اگر (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, پوچ, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        برای (i = 0; i < REGN; i++) {
            افزودن_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_index = 0;
    sse_param_index = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    اگر (ret_mode == x86_64_mode_memory) {
        افزودن_arg_reg(reg_param_index);
        func_vc = loc;
        reg_param_index++;
    }
    /* define parameters */
    وقتی ((sym = sym->next) != پوچ) {
        type = &sym->type;
        mode = classify_x86_64_arg(type, پوچ, &size, &align, &reg_شمار);
        انتخاب (mode) {
        حالت x86_64_mode_sse:
	    اگر (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            اگر (sse_param_index + reg_شمار <= 8) {
                /* save arguments passed by register */
                loc -= reg_شمار * 8;
                param_addr = loc;
                برای (i = 0; i < reg_شمار; ++i) {
                    gen_modrm32(0xd60f66, sse_param_index, VT_LOCAL, پوچ, param_addr + i*8);
                    ++sse_param_index;
                }
            } وگرنه {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            بشکن;
            
        حالت x86_64_mode_memory:
        حالت x86_64_mode_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += size;
            بشکن;
            
        حالت x86_64_mode_integer: {
            اگر (reg_param_index + reg_شمار <= REGN) {
                /* save arguments passed by register */
                loc -= reg_شمار * 8;
                param_addr = loc;
                برای (i = 0; i < reg_شمار; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, پوچ, param_addr + i*8);
                    ++reg_param_index;
                }
            } وگرنه {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            بشکن;
        }
	پیشفرض: بشکن; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_set_param(sym, param_addr, 0);
    }

#ifdef CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
تهی gfunc_epilog(تهی)
{
    صحیح v, saved_ind;

#ifdef CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif
    o(0xc9); /* leave */
    اگر (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } وگرنه {
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

ST_FUNC تهی gen_fill_nops(صحیح bytes)
{
    وقتی (bytes--)
      g(0x90);
}

/* generate a jump to a label */
صحیح gjmp(صحیح t)
{
    بازگشت gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
تهی gjmp_addr(صحیح a)
{
    صحیح r;
    r = a - ind - 2;
    اگر (r == (signed نویسه)r) {
        g(0xeb);
        g(r);
    } وگرنه {
        oad(0xe9, a - ind - 5);
    }
}

ST_FUNC صحیح gjmp_append(صحیح n, صحیح t)
{
    تهی *p;
    /* insert vtop->c jump list in t */
    اگر (n) {
        uint32_t n1 = n, n2;
        وقتی ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    بازگشت t;
}

ST_FUNC صحیح gjmp_cond(صحیح op, صحیح t)
{
        اگر (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            صحیح v = vtop->cmp_r;
            op &= ~0x100;
            اگر (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    وگرنه
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        بازگشت t;
}

/* generate an integer binary operation */
تهی gen_opi(صحیح op)
{
    صحیح r, fr, opc, c;
    صحیح ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    انتخاب(op) {
    حالت '+':
    حالت TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        اگر (cc && (!ll || (صحیح)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            اگر (c == (signed نویسه)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_مقدار(r));
                g(c);
            } وگرنه {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_مقدار(r), c);
            }
        } وگرنه {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_مقدار(r) + REG_مقدار(fr) * 8);
        }
        vtop--;
        اگر (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        بشکن;
    حالت '-':
    حالت TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        برو gen_op8;
    حالت TOK_ADDC2: /* add with carry use */
        opc = 2;
        برو gen_op8;
    حالت TOK_SUBC2: /* sub with carry use */
        opc = 3;
        برو gen_op8;
    حالت '&':
        opc = 4;
        برو gen_op8;
    حالت '^':
        opc = 6;
        برو gen_op8;
    حالت '|':
        opc = 1;
        برو gen_op8;
    حالت '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_مقدار(fr) + REG_مقدار(r) * 8);
        vtop--;
        بشکن;
    حالت TOK_SHL:
        opc = 4;
        برو gen_shift;
    حالت TOK_SHR:
        opc = 5;
        برو gen_shift;
    حالت TOK_SAR:
        opc = 7;
    gen_shift:
        opc = 0xc0 | (opc << 3);
        اگر (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_مقدار(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } وگرنه {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_مقدار(r));
        }
        vtop--;
        بشکن;
    حالت TOK_UDIV:
    حالت TOK_UMOD:
        uu = 1;
        برو divmod;
    حالت '/':
    حالت '%':
    حالت TOK_PDIV:
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
        o((uu ? 0xf0 : 0xf8) + REG_مقدار(fr));
        اگر (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        وگرنه
            r = TREG_RAX;
        vtop->r = r;
        بشکن;
    پیشفرض:
        opc = 7;
        برو gen_op8;
    }
}

تهی gen_opl(صحیح op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
تهی gen_opf(صحیح op)
{
    صحیح a, ft, fc, swapped, r, opc;
    صحیح bt = vtop->type.t & VT_BTYPE;
    صحیح float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    اگر (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        اگر (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } وگرنه {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, پوچ, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        بازگشت;
    }

    /* convert constants to memory references */
    اگر ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    اگر ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    اگر ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    اگر (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    اگر ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        اگر (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            load(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            اگر (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            وگرنه اگر (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            اگر (swapped)
                o(0xc9d9); /* fxch %st(1) */
            اگر (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            وگرنه
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            اگر (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } وگرنه اگر (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } وگرنه اگر (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } وگرنه {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } وگرنه {
            /* no memory reference possible for long double operations */
            load(TREG_ST0, vtop);
            swapped = !swapped;

            انتخاب(op) {
            پیشفرض:
            حالت '+':
                a = 0;
                بشکن;
            حالت '-':
                a = 4;
                اگر (swapped)
                    a++;
                بشکن;
            حالت '*':
                a = 1;
                بشکن;
            حالت '/':
                a = 6;
                اگر (swapped)
                    a++;
                بشکن;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } وگرنه {
        اگر (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            اگر ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = پوچ;
                load(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            اگر (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } وگرنه {
                اگر (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                اگر (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } وگرنه {
                    op = 0x97; /* seta */
                }
            }

            اگر (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            أكد(!(vtop[-1].r & VT_LVAL));
            
            اگر (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            وگرنه
                opc = 0x2f0f; /* comisd */
            اگر ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } وگرنه {
            أكد((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            انتخاب(op) {
            پیشفرض:
            حالت '+':
                a = 0;
                بشکن;
            حالت '-':
                a = 4;
                بشکن;
            حالت '*':
                a = 1;
                بشکن;
            حالت '/':
                a = 6;
                بشکن;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            أكد((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            اگر ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = پوچ;
                load(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            أكد(!(vtop[-1].r & VT_LVAL));
            اگر (swapped) {
                أكد(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            اگر ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } وگرنه {
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
تهی gen_cvt_itof(صحیح t)
{
    اگر ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        اگر ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } وگرنه اگر ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } وگرنه {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } وگرنه {
        صحیح r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        اگر ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_مقدار(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
تهی gen_cvt_ftof(صحیح t)
{
    صحیح ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    اگر (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        اگر (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_مقدار(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_مقدار(vtop->r)*9);
        } وگرنه اگر (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_مقدار(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } وگرنه اگر (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        اگر (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_مقدار(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_مقدار(vtop->r)*9);
        } وگرنه اگر (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_مقدار(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } وگرنه {
        صحیح r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        اگر (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_مقدار(r)*8);
            o(0xf024);
            vtop->r = r;
        } وگرنه اگر (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_مقدار(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
تهی gen_cvt_ftoi(صحیح t)
{
    صحیح ft, bt, size, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    اگر (bt == VT_LDOUBLE) {
	اگر (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    بازگشت;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    اگر (t != VT_INT)
        size = 8;
    وگرنه
        size = 4;

    r = get_reg(RC_INT);
    اگر (bt == VT_FLOAT) {
        o(0xf3);
    } وگرنه اگر (bt == VT_DOUBLE) {
        o(0xf2);
    } وگرنه {
        أكد(0);
    }
    orex(size == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_مقدار(vtop->r) + REG_مقدار(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC تهی gen_cvt_sxtw(تهی)
{
    صحیح r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_مقدار(r) << 3) + REG_مقدار(r));
}

/* char/short to int conversion */
ST_FUNC تهی gen_cvt_csti(صحیح t)
{
    صحیح r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_مقدار(r) << 3 | REG_مقدار(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC تهی gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_text_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC تهی ggoto(تهی)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC تهی gen_vla_sp_save(صحیح addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, پوچ, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC تهی gen_vla_sp_restore(صحیح addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, پوچ, addr);
}

#ifdef TCC_TARGET_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC تهی gen_vla_result(صحیح addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, پوچ, addr);
}
#endif

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC تهی gen_vla_alloc(CType *type, صحیح align) {
    صحیح use_call = 0;

#اگر defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#endif
#ifdef TCC_TARGET_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#endif
    اگر (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    وگرنه {
        صحیح r;
        r = gv(RC_INT); /* allocation size */
        /* sub r,%rsp */
        o(0x2b48);
        o(0xe0 | REG_مقدار(r));
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
ST_FUNC تهی gen_struct_copy(صحیح size)
{
    صحیح n = size / PTR_SIZE;
#ifdef TCC_TARGET_PE
    o(0x5756); /* push rsi, rdi */
#endif
    gv2(RC_RDI, RC_RSI);
    اگر (n <= 4) {
        وقتی (n)
            o(0xa548), --n;
    } وگرنه {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    اگر (size & 0x04)
        o(0xa5);
    اگر (size & 0x02)
        o(0xa566);
    اگر (size & 0x01)
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
