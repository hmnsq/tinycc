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

#اگر_تعریف_شدہ ہدف_DEFS_ONLY

/* number of available registers */
#تعریف_کرو NB_REGS         25
#تعریف_کرو NB_ASM_REGS     16
#تعریف_کرو CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#تعریف_کرو RC_INT     0x0001 /* generic integer register */
#تعریف_کرو RC_FLOAT   0x0002 /* generic float register */
#تعریف_کرو RC_RAX     0x0004
#تعریف_کرو RC_RDX     0x0008
#تعریف_کرو RC_RCX     0x0010
#تعریف_کرو RC_RSI     0x0020
#تعریف_کرو RC_RDI     0x0040
#تعریف_کرو RC_ST0     0x0080 /* only for long double */
#تعریف_کرو RC_R8      0x0100
#تعریف_کرو RC_R9      0x0200
#تعریف_کرو RC_R10     0x0400
#تعریف_کرو RC_R11     0x0800
#تعریف_کرو RC_XMM0    0x1000
#تعریف_کرو RC_XMM1    0x2000
#تعریف_کرو RC_XMM2    0x4000
#تعریف_کرو RC_XMM3    0x8000
#تعریف_کرو RC_XMM4    0x10000
#تعریف_کرو RC_XMM5    0x20000
#تعریف_کرو RC_XMM6    0x40000
#تعریف_کرو RC_XMM7    0x80000
#تعریف_کرو RC_IRET    RC_RAX /* function return: integer register */
#تعریف_کرو RC_IRE2    RC_RDX /* function return: second integer register */
#تعریف_کرو RC_FRET    RC_XMM0 /* function return: float register */
#تعریف_کرو RC_FRE2    RC_XMM1 /* function return: second float register */

/* pretty names for the registers */
شمار {
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

#تعریف_کرو REX_بنیاد(reg) (((reg) >> 3) & 1)
#تعریف_کرو REG_قدر(reg) ((reg) & 7)

/* return registers for function */
#تعریف_کرو REG_IRET TREG_RAX /* single word int return register */
#تعریف_کرو REG_IRE2 TREG_RDX /* second word return register (for long long) */
#تعریف_کرو REG_FRET TREG_XMM0 /* float return register */
#تعریف_کرو REG_FRE2 TREG_XMM1 /* second float return register */

/* defined if function parameters must be evaluated in reverse order */
#تعریف_کرو INVERT_FUNC_PARAMS

/* pointer size, in bytes */
#تعریف_کرو PTR_سائز 8

/* long double size and alignment, in bytes */
#تعریف_کرو LDOUBLE_سائز  16
#تعریف_کرو LDOUBLE_ALIGN 16
/* maximum alignment (for aligned attribute support) */
#تعریف_کرو MAX_ALIGN     16

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#تعریف_کرو PROMOTE_RET

#تعریف_کرو TCC_ہدف_NATIVE_STRUCT_COPY
ST_FUNC خالی gen_struct_copy(صحیح سائز);

/******************************************************/
#ورنہ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"
#شامل <assert.h>

ST_ڈیٹا ثابت حرف * ثابت ہدف_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_ڈیٹا ثابت صحیح reg_classes[NB_REGS] = {
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

ساکن غیرعلامتی طویل func_sub_sp_انحراف;
ساکن صحیح func_ret_sub;

#اگر defined(CONFIG_TCC_BCHECK)
ساکن addr_t func_bound_انحراف;
ساکن غیرعلامتی طویل func_bound_ind;
ST_ڈیٹا صحیح func_bound_جوڑو_epilog;
#اگر_ختم

#اگر_تعریف_شدہ TCC_ہدف_PE
ساکن صحیح func_scratch, func_alloca;
#اگر_ختم

/* XXX: make it faster ? */
ST_FUNC خالی g(صحیح c)
{
    صحیح ind1;
    اگر (nocode_wanted)
        واپس;
    ind1 = ind + 1;
    اگر (ind1 > cur_متن_section->ڈیٹا_allocated)
        section_realloc(cur_متن_section, ind1);
    cur_متن_section->ڈیٹا[ind] = c;
    ind = ind1;
}

ST_FUNC خالی o(غیرعلامتی صحیح c)
{
    جب (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC خالی gen_le16(صحیح v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC خالی gen_le32(صحیح c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

ST_FUNC خالی gen_le64(int64_t c)
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

ساکن خالی orex(صحیح ll, صحیح r, صحیح r2, صحیح b)
{
    اگر ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    اگر ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    اگر (ll || REX_بنیاد(r) || REX_بنیاد(r2)) {
        اگر ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_بنیاد(r) | (REX_بنیاد(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC خالی gsym_addr(صحیح t, صحیح a)
{
    جب (t) {
        غیرعلامتی حرف *ptr = cur_متن_section->ڈیٹا + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

ساکن صحیح is64_type(صحیح t)
{
    واپس ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
ساکن صحیح oad(صحیح c, صحیح s)
{
    صحیح t;
    اگر (nocode_wanted)
        واپس s;
    o(c);
    t = ind;
    gen_le32(s);
    واپس t;
}

/* generate jmp to a label */
#تعریف_کرو gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC خالی gen_addr32(صحیح r, Sym *sym, صحیح c)
{
    اگر (r & VT_SYM)
        greloca(cur_متن_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC خالی gen_addrpc32(صحیح r, Sym *sym, صحیح c)
{
    اگر (r & VT_SYM)
        greloca(cur_متن_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
ساکن خالی gen_gotpcrel(صحیح r, Sym *sym, صحیح c)
{
#اگر_تعریف_شدہ TCC_ہدف_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, تہی), c, r,
        cur_متن_section->ڈیٹا[ind-3],
        cur_متن_section->ڈیٹا[ind-2],
        cur_متن_section->ڈیٹا[ind-1]
        );
#اگر_ختم
    greloca(cur_متن_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    اگر (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_قدر(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
ساکن خالی gen_modrm_impl(صحیح opcode, صحیح ll, صحیح op_reg_0, صحیح r, Sym *sym, صحیح c)
{
    صحیح op_reg = REG_قدر(op_reg_0) << 3;

    اگر ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#اگر_تعریف_شدہ TCC_ہدف_PE
        Sym *s2 = external_global_sym(TOK_tls_اشاریہ, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_سائز); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_متن_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#ورنہ
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_متن_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#اگر_ختم
        واپس;
    }

    orex(ll, r, op_reg_0, opcode);

    اگر ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	اگر (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} ورنہ {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    اگر (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } ورنہ {
		gen_addrpc32(r, sym, c);
	    }
	}
    } ورنہ اگر ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        اگر (c == (علامتی حرف)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } ورنہ {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } ورنہ اگر ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_قدر(r));
        gen_le32(c);
    } ورنہ اگر (r & VT_LVAL) {
        g(0x00 | op_reg | REG_قدر(r));
    } ورنہ {
        g(0xc0 | op_reg | REG_قدر(r));
    }
}

ساکن خالی gen_modrm64(صحیح opcode, صحیح op_reg, صحیح r, Sym *sym, صحیح c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

ساکن خالی gen_modrm32(صحیح opcode, صحیح op_reg, صحیح r, Sym *sym, صحیح c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
خالی بھرو(صحیح r, SValue *sv)
{
    صحیح v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    اگر (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#اگر_غیر_تعریف_شدہ TCC_ہدف_PE
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
#اگر_ختم

    v = fr & VT_VALMASK;
    اگر (fr & VT_LVAL) {
        صحیح b, ll;
        اگر (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = تہی;
            fr = r;
            اگر (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            بھرو(fr, &v1);
            fr |= VT_LVAL;
        }
	اگر (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = تہی;
	    fr = r;
	    اگر (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    بھرو(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	اگر ((ft & VT_BTYPE) == VT_STRUCT) {
	    صحیح align;
	    انتخاب (type_سائز(&sv->type, &align)) {
		حالت 1: ft = VT_BYTE; توڑو;
		حالت 2: ft = VT_SHORT; توڑو;
		حالت 4: ft = VT_INT; توڑو;
		حالت 8: ft = VT_LLONG; توڑو;
		طےشدہ:
		    tcc_error("invalid aggregate type for register load");
		    توڑو;
	    }
	}
        اگر ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_قدر(r); /* movd */
        } ورنہ اگر ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_قدر(r);
        } ورنہ اگر ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } ورنہ اگر ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } ورنہ اگر ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } ورنہ اگر ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } ورنہ اگر ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } ورنہ اگر ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            واپس;
        } ورنہ {
            أكد(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } ورنہ {
        اگر (v == VT_CONST) {
            اگر (fr & VT_SYM) {
#اگر_تعریف_شدہ TCC_ہدف_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#ورنہ
                اگر (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, تہی, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_قدر(r), 0);
                    greloca(cur_متن_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } ورنہ اگر (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_قدر(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } ورنہ {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_قدر(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#اگر_ختم
            } ورنہ اگر (is64_type(ft)) {
                اگر (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_قدر(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } ورنہ اگر (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_قدر(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } ورنہ {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_قدر(r) * 9);
                }
            } ورنہ {
                orex(0,r,0, 0xb8 + REG_قدر(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } ورنہ اگر (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } ورنہ اگر (v == VT_CMP) {
	    اگر (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_قدر(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_بنیاد(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_قدر(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_قدر(r) * 0x900); /* movzbl %al, %eax */
        } ورنہ اگر (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_قدر(r), t); /* mov $1, r */
            o(0x05eb + (REX_بنیاد(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_قدر(r), t ^ 1); /* mov $0, r */
        } ورنہ اگر (v != r) {
            اگر ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                اگر (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_قدر(r)*8); /* %xmmN */
                    o(0xf024);
                } ورنہ {
                    أكد((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    اگر ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } ورنہ {
                        أكد((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_قدر(v) + REG_قدر(r)*8);
                }
            } ورنہ اگر (r == TREG_ST0) {
                أكد((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_قدر(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } ورنہ {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_قدر(r) + REG_قدر(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
خالی store(صحیح r, SValue *v)
{
    صحیح fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    صحیح opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    اگر (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#اگر_غیر_تعریف_شدہ TCC_ہدف_PE
    /* we need to access the variable via got */
    اگر ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#اگر_ختم

    /* XXX: incorrect if float reg to reg */
    اگر (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_قدر(r);
    } ورنہ اگر (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_قدر(r);
    } ورنہ اگر (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } ورنہ اگر (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } ورنہ {
        opc = 0x89;
        اگر (bt == VT_SHORT)
            opc = 0x8966;
        ورنہ اگر (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
ساکن خالی gcall_or_jmp(صحیح is_jmp)
{
    صحیح r;
    اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (صحیح)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_متن_section, vtop->sym, ind + 1, R_X86_64_PLT32, (صحیح)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } ورنہ {
        /* otherwise, indirect call */
        r = TREG_R11;
        بھرو(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_قدر(r) + (is_jmp << 4));
    }
}

#اگر defined(CONFIG_TCC_BCHECK)

ساکن خالی gen_bounds_call(صحیح v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_متن_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#اگر_تعریف_شدہ TCC_ہدف_PE
# define TREG_FASTCALL_1 TREG_RCX
#ورنہ
# define TREG_FASTCALL_1 TREG_RDI
#اگر_ختم

ساکن خالی gen_bounds_prolog(خالی)
{
    /* leave some room for bound checking code */
    func_bound_انحراف = lbounds_section->ڈیٹا_انحراف;
    func_bound_ind = ind;
    func_bound_جوڑو_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
}

ساکن خالی gen_bounds_epilog(خالی)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ڈیٹا;
    صحیح انحراف_modified = func_bound_انحراف != lbounds_section->ڈیٹا_انحراف;

    اگر (!انحراف_modified && !func_bound_جوڑو_epilog)
        واپس;

    /* add end of table info */
    bounds_ptr = section_ptr_جوڑو(lbounds_section, حجم(addr_t));
    *bounds_ptr = 0;

    sym_ڈیٹا = get_sym_ref(&char_اشارہ_گر_type, lbounds_section, 
                           func_bound_انحراف, PTR_سائز);

    /* generate bound local allocation */
    اگر (انحراف_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        greloca(cur_متن_section, sym_ڈیٹا, ind + 3, R_X86_64_PC32, -4);
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
    greloca(cur_متن_section, sym_ڈیٹا, ind + 3, R_X86_64_PC32, -4);
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /* lea xxx(%rip), %rcx/rdi */
    gen_le32 (0);
    gen_bounds_call(TOK___bound_local_delete);
    o(0x280f);     /* movaps 0x10(%rsp),%xmm0 */
    o(0x102444);
    o(0x240c280f); /* movaps (%rsp),%xmm1 */
    o(0x20c48348); /* add $32,%rsp */
    o(0x585a); /* restore returned value, if any */
}
#اگر_ختم

#اگر_تعریف_شدہ TCC_ہدف_PE

#تعریف_کرو REGN 4
ساکن ثابت uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
ساکن صحیح arg_prepare_reg(صحیح idx) {
  اگر (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      واپس idx + 10;
  ورنہ
      واپس idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

ساکن خالی gen_offs_sp(صحیح b, صحیح r, صحیح d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    اگر (d == (علامتی حرف)d) {
        o(0x2444 | (REG_قدر(r) << 3));
        g(d);
    } ورنہ {
        o(0x2484 | (REG_قدر(r) << 3));
        gen_le32(d);
    }
}

ساکن صحیح using_regs(صحیح سائز)
{
    واپس !(سائز > 8 || (سائز & (سائز - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحیح gfunc_sret(CType *vt, صحیح variadic, CType *ret, صحیح *ret_align, صحیح *regsize)
{
    صحیح سائز, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    سائز = type_سائز(vt, &align);
    اگر (!using_regs(سائز))
        واپس 0;
    اگر (سائز == 8)
        ret->t = VT_LLONG;
    ورنہ اگر (سائز == 4)
        ret->t = VT_INT;
    ورنہ اگر (سائز == 2)
        ret->t = VT_SHORT;
    ورنہ
        ret->t = VT_BYTE;
    ret->ref = تہی;
    واپس 1;
}

ساکن صحیح is_sse_float(صحیح t) {
    صحیح bt;
    bt = t & VT_BTYPE;
    واپس bt == VT_DOUBLE || bt == VT_FLOAT;
}

ساکن صحیح gfunc_arg_سائز(CType *type) {
    صحیح align;
    اگر (type->t & (VT_ARRAY|VT_BITFIELD))
        واپس 8;
    واپس type_سائز(type, &align);
}

خالی gfunc_call(صحیح nb_دلائل)
{
    صحیح سائز, r, دلائل_سائز, i, d, bt, struct_سائز;
    صحیح arg;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gbound_دلائل(nb_دلائل);
#اگر_ختم

    save_regs(nb_دلائل);

    دلائل_سائز = (nb_دلائل < REGN ? REGN : nb_دلائل) * PTR_سائز;
    arg = nb_دلائل;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_سائز = دلائل_سائز;
    برائے(i = 0; i < nb_دلائل; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        سائز = gfunc_arg_سائز(&sv->type);

        اگر (using_regs(سائز))
            جاری; /* arguments smaller than 8 bytes passed in registers or on stack */

        اگر (bt == VT_STRUCT) {
            /* align to stack align size */
            سائز = (سائز + 15) & ~15;
            /* generate structure store */
            r = get_reg(RC_INT);
            gen_offs_sp(0x8d, r, struct_سائز);
            struct_سائز += سائز;

            /* generate memcpy call */
            vset(&sv->type, r | VT_LVAL, 0);
            vpushv(sv);
            vstore();
            --vtop;
        } ورنہ اگر (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_سائز);
            struct_سائز += 16;
        }
    }

    اگر (func_scratch < struct_سائز)
        func_scratch = struct_سائز;

    arg = nb_دلائل;
    struct_سائز = دلائل_سائز;

    برائے(i = 0; i < nb_دلائل; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        سائز = gfunc_arg_سائز(&vtop->type);
        اگر (!using_regs(سائز)) {
            /* align to stack align size */
            سائز = (سائز + 15) & ~15;
            اگر (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_سائز);
                gen_offs_sp(0x89, d, arg*8);
            } ورنہ {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_سائز);
            }
            struct_سائز += سائز;
        } ورنہ {
            اگر (is_sse_float(vtop->type.t)) {
		اگر (tcc_state->nosse)
		  tcc_error("SSE disabled");
                اگر (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } ورنہ {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_قدر(d));
                }
            } ورنہ {
                اگر (bt == VT_STRUCT) {
                    vtop->type.ref = تہی;
                    vtop->type.t = سائز > 4 ? VT_LLONG : سائز > 2 ? VT_INT
                        : سائز > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                اگر (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } ورنہ {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_قدر(r) * 8 + REG_قدر(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    اگر (nb_دلائل > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        اگر (nb_دلائل > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    اگر ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#اگر_ختم
    }
    vtop--;
}

#تعریف_کرو FUNC_PROLOG_سائز 11

/* generate function prolog of type 't' */
خالی gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    صحیح addr, reg_param_اشاریہ, bt, سائز;
    Sym *sym;
    CType *type;

    func_ret_sub = 0;
    func_scratch = 32;
    func_alloca = 0;
    loc = 0;

    addr = PTR_سائز * 2;
    ind += FUNC_PROLOG_سائز;
    func_sub_sp_انحراف = ind;
    reg_param_اشاریہ = 0;

    sym = func_type->ref;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    سائز = gfunc_arg_سائز(&func_vt);
    اگر (!using_regs(سائز)) {
        gen_modrm64(0x89, arg_regs[reg_param_اشاریہ], VT_LOCAL, تہی, addr);
        func_vc = addr;
        reg_param_اشاریہ++;
        addr += 8;
    }

    /* define parameters */
    جب ((sym = sym->اگلا) != تہی) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        سائز = gfunc_arg_سائز(type);
        اگر (!using_regs(سائز)) {
            اگر (reg_param_اشاریہ < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_اشاریہ], VT_LOCAL, تہی, addr);
            }
            gfunc_سیٹ_param(sym, addr, 1);
        } ورنہ {
            اگر (reg_param_اشاریہ < REGN) {
                /* save arguments passed by register */
                اگر ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    اگر (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_اشاریہ, VT_LOCAL, تہی, addr);
                } ورنہ {
                    gen_modrm64(0x89, arg_regs[reg_param_اشاریہ], VT_LOCAL, تہی, addr);
                }
            }
            gfunc_سیٹ_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_اشاریہ++;
    }

    جب (reg_param_اشاریہ < REGN) {
        اگر (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_اشاریہ], VT_LOCAL, تہی, addr);
            addr += 8;
        }
        reg_param_اشاریہ++;
    }
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#اگر_ختم
}

/* generate function epilog */
خالی gfunc_epilog(خالی)
{
    صحیح v, آغاز;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#اگر_ختم

    o(0xc9); /* leave */
    اگر (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ورنہ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    آغاز = func_sub_sp_انحراف - FUNC_PROLOG_سائز;
    cur_متن_section->ڈیٹا_انحراف = ind;
    pe_جوڑو_unwind_ڈیٹا(آغاز, ind, v);

    ind = آغاز;
    اگر (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_متن_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } ورنہ {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_متن_section->ڈیٹا_انحراف;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#ورنہ

ساکن خالی gadd_sp(صحیح val)
{
    اگر (val == (علامتی حرف)val) {
        o(0xc48348);
        g(val);
    } ورنہ {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

قسمتعریف شمار X86_64_منوال {
  x86_64_منوال_none,
  x86_64_منوال_حافظہ,
  x86_64_منوال_integer,
  x86_64_منوال_sse,
  x86_64_منوال_x87
} X86_64_منوال;

ساکن X86_64_منوال classify_x86_64_ملاؤ(X86_64_منوال a, X86_64_منوال b)
{
    اگر (a == b)
        واپس a;
    ورنہ اگر (a == x86_64_منوال_none)
        واپس b;
    ورنہ اگر (b == x86_64_منوال_none)
        واپس a;
    ورنہ اگر ((a == x86_64_منوال_حافظہ) || (b == x86_64_منوال_حافظہ))
        واپس x86_64_منوال_حافظہ;
    ورنہ اگر ((a == x86_64_منوال_integer) || (b == x86_64_منوال_integer))
        واپس x86_64_منوال_integer;
    ورنہ اگر ((a == x86_64_منوال_x87) || (b == x86_64_منوال_x87))
        واپس x86_64_منوال_حافظہ;
    ورنہ
        واپس x86_64_منوال_sse;
}

ساکن X86_64_منوال classify_x86_64_inner(CType *ty)
{
    X86_64_منوال منوال;
    Sym *f;
    
    انتخاب (ty->t & VT_BTYPE) {
    حالت VT_VOID: واپس x86_64_منوال_none;
    
    حالت VT_INT:
    حالت VT_BYTE:
    حالت VT_SHORT:
    حالت VT_LLONG:
    حالت VT_BOOL:
    حالت VT_PTR:
    حالت VT_FUNC:
        واپس x86_64_منوال_integer;
    
    حالت VT_FLOAT:
    حالت VT_DOUBLE: واپس x86_64_منوال_sse;
    
    حالت VT_LDOUBLE: واپس x86_64_منوال_x87;
      
    حالت VT_STRUCT:
        f = ty->ref;

        منوال = x86_64_منوال_none;
        برائے (f = f->اگلا; f; f = f->اگلا)
            منوال = classify_x86_64_ملاؤ(منوال, classify_x86_64_inner(&f->type));
        
        واپس منوال;
    }
    أكد(0);
    واپس 0;
}

ساکن X86_64_منوال classify_x86_64_arg(CType *ty, CType *ret, صحیح *psize, صحیح *palign, صحیح *reg_گنتی)
{
    X86_64_منوال منوال;
    صحیح سائز, align, ret_t = 0;
    
    اگر (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_گنتی = 1;
        ret_t = ty->t;
        منوال = x86_64_منوال_integer;
    } ورنہ {
        سائز = type_سائز(ty, &align);
        *psize = (سائز + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_گنتی = 0; /* avoid compiler warning */

        اگر (سائز > 16) {
            منوال = x86_64_منوال_حافظہ;
        } ورنہ {
            منوال = classify_x86_64_inner(ty);
            انتخاب (منوال) {
            حالت x86_64_منوال_integer:
                اگر (سائز > 8) {
                    *reg_گنتی = 2;
                    ret_t = VT_QLONG;
                } ورنہ {
                    *reg_گنتی = 1;
                    اگر (سائز > 4)
                        ret_t = VT_LLONG;
                    ورنہ اگر (سائز > 2)
                        ret_t = VT_INT;
                    ورنہ اگر (سائز > 1)
                        ret_t = VT_SHORT;
                    ورنہ
                        ret_t = VT_BYTE;
                    اگر ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                توڑو;
                
            حالت x86_64_منوال_x87:
                *reg_گنتی = 1;
                ret_t = VT_LDOUBLE;
                توڑو;

            حالت x86_64_منوال_sse:
                اگر (سائز > 8) {
                    *reg_گنتی = 2;
                    ret_t = VT_QFLOAT;
                } ورنہ {
                    *reg_گنتی = 1;
                    ret_t = (سائز > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                توڑو;
            طےشدہ: توڑو; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    اگر (ret) {
        ret->ref = تہی;
        ret->t = ret_t;
    }
    
    واپس منوال;
}

ST_FUNC صحیح classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    شمار __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    صحیح سائز, align, reg_گنتی;
    X86_64_منوال منوال = classify_x86_64_arg(ty, تہی, &سائز, &align, &reg_گنتی);
    انتخاب (منوال) {
    طےشدہ: واپس __va_stack;
    حالت x86_64_منوال_integer: واپس __va_gen_reg;
    حالت x86_64_منوال_sse: واپس __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحیح gfunc_sret(CType *vt, صحیح variadic, CType *ret, صحیح *ret_align, صحیح *regsize)
{
    صحیح سائز, align, reg_گنتی;
    اگر (classify_x86_64_arg(vt, ret, &سائز, &align, &reg_گنتی) == x86_64_منوال_حافظہ)
        واپس 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_گنتی; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    واپس 1;
}

#تعریف_کرو REGN 6
ساکن ثابت uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

ساکن صحیح arg_prepare_reg(صحیح idx) {
  اگر (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      واپس idx + 8;
  ورنہ
      واپس idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
خالی gfunc_call(صحیح nb_دلائل)
{
    X86_64_منوال منوال;
    CType type;
    صحیح سائز, align, r, دلائل_سائز, ڈھیر_adjust, i, reg_گنتی, k;
    صحیح nb_reg_دلائل = 0;
    صحیح nb_sse_دلائل = 0;
    صحیح sse_reg, gen_reg;
    حرف *onstack = tcc_malloc((nb_دلائل + 1) * حجم (حرف));

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gbound_دلائل(nb_دلائل);
#اگر_ختم

    save_regs(nb_دلائل);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    ڈھیر_adjust = 0;
    برائے(i = nb_دلائل - 1; i >= 0; i--) {
        منوال = classify_x86_64_arg(&vtop[-i].type, تہی, &سائز, &align, &reg_گنتی);
        اگر (سائز == 0) جاری;
        اگر (منوال == x86_64_منوال_sse && nb_sse_دلائل + reg_گنتی <= 8) {
            nb_sse_دلائل += reg_گنتی;
	    onstack[i] = 0;
	} ورنہ اگر (منوال == x86_64_منوال_integer && nb_reg_دلائل + reg_گنتی <= REGN) {
            nb_reg_دلائل += reg_گنتی;
	    onstack[i] = 0;
	} ورنہ اگر (منوال == x86_64_منوال_none) {
	    onstack[i] = 0;
	} ورنہ {
	    اگر (align == 16 && (ڈھیر_adjust &= 15)) {
		onstack[i] = 2;
		ڈھیر_adjust = 0;
	    } ورنہ
	      onstack[i] = 1;
	    ڈھیر_adjust += سائز;
	}
    }

    اگر (nb_sse_دلائل && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_دلائل;
    sse_reg = nb_sse_دلائل;
    دلائل_سائز = 0;
    ڈھیر_adjust &= 15;
    برائے (i = k = 0; i < nb_دلائل;) {
	منوال = classify_x86_64_arg(&vtop[-i].type, تہی, &سائز, &align, &reg_گنتی);
	اگر (سائز) {
            اگر (!onstack[i + k]) {
	        ++i;
	        جاری;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            اگر (ڈھیر_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                دلائل_سائز += 8;
	        ڈھیر_adjust = 0;
            }
	    اگر (onstack[i + k] == 2)
	        ڈھیر_adjust = 1;
        }

	vrotb(i+1);

	انتخاب (vtop->type.t & VT_BTYPE) {
	    حالت VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, سائز); /* sub $xxx, %rsp */
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
		توڑو;

	    حالت VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, سائز); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		توڑو;

	    حالت VT_FLOAT:
	    حالت VT_DOUBLE:
		أكد(منوال == x86_64_منوال_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_قدر(r)*8);
		o(0x24);
		توڑو;

	    طےشدہ:
		أكد(منوال == x86_64_منوال_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_قدر(r)); /* push r */
		توڑو;
	}
	دلائل_سائز += سائز;

	vpop();
	--nb_دلائل;
	k++;
    }

    tcc_free(onstack);

    /* then, we prepare register passing arguments.
       Note that we cannot set RDX and RCX in this loop because gv()
       may break these temporary registers. Let's use R10 and R11
       instead of them */
    أكد(gen_reg <= REGN);
    أكد(sse_reg <= 8);
    برائے(i = 0; i < nb_دلائل; i++) {
        منوال = classify_x86_64_arg(&vtop->type, &type, &سائز, &align, &reg_گنتی);
        اگر (سائز == 0) جاری;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        اگر (منوال == x86_64_منوال_sse) {
            اگر (reg_گنتی == 2) {
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
            } ورنہ {
                أكد(reg_گنتی == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } ورنہ اگر (منوال == x86_64_منوال_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            صحیح d;
            gen_reg -= reg_گنتی;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_قدر(r) * 8 + REG_قدر(d));
            اگر (reg_گنتی == 2) {
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
    اگر (nb_reg_دلائل > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        اگر (nb_reg_دلائل > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    اگر (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_دلائل < 8 ? nb_sse_دلائل : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    اگر (دلائل_سائز)
        gadd_sp(دلائل_سائز);
    vtop--;
}

#تعریف_کرو FUNC_PROLOG_سائز 11

ساکن خالی ڈالو_arg_reg(صحیح i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, تہی, loc);
}

/* generate function prolog of type 't' */
خالی gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_منوال منوال, ret_منوال;
    صحیح i, addr, align, سائز, reg_گنتی;
    صحیح param_addr = 0, reg_param_اشاریہ, sse_param_اشاریہ;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_سائز * 2;
    loc = 0;
    ind += FUNC_PROLOG_سائز;
    func_sub_sp_انحراف = ind;
    func_ret_sub = 0;
    ret_منوال = classify_x86_64_arg(&func_vt, تہی, &سائز, &align, &reg_گنتی);

    اگر (func_var) {
        صحیح نظر_آیا_reg_عدد, نظر_آیا_sse_عدد, نظر_آیا_ڈھیر_سائز;
        نظر_آیا_reg_عدد = ret_منوال == x86_64_منوال_حافظہ;
        نظر_آیا_sse_عدد = 0;
        /* frame pointer and return address */
        نظر_آیا_ڈھیر_سائز = PTR_سائز * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        جب ((sym = sym->اگلا) != تہی) {
            type = &sym->type;
            منوال = classify_x86_64_arg(type, تہی, &سائز, &align, &reg_گنتی);
            انتخاب (منوال) {
            طےشدہ:
            ڈھیر_arg:
                نظر_آیا_ڈھیر_سائز = ((نظر_آیا_ڈھیر_سائز + align - 1) & -align) + سائز;
                توڑو;
                
            حالت x86_64_منوال_integer:
                اگر (نظر_آیا_reg_عدد + reg_گنتی > REGN)
		    جاؤ ڈھیر_arg;
		نظر_آیا_reg_عدد += reg_گنتی;
                توڑو;
                
            حالت x86_64_منوال_sse:
                اگر (نظر_آیا_sse_عدد + reg_گنتی > 8)
		    جاؤ ڈھیر_arg;
		نظر_آیا_sse_عدد += reg_گنتی;
                توڑو;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(نظر_آیا_reg_عدد * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(نظر_آیا_sse_عدد * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(نظر_آیا_ڈھیر_سائز);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        برائے (i = 0; i < 8; i++) {
            loc -= 16;
	    اگر (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, تہی, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        برائے (i = 0; i < REGN; i++) {
            ڈالو_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_اشاریہ = 0;
    sse_param_اشاریہ = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    اگر (ret_منوال == x86_64_منوال_حافظہ) {
        ڈالو_arg_reg(reg_param_اشاریہ);
        func_vc = loc;
        reg_param_اشاریہ++;
    }
    /* define parameters */
    جب ((sym = sym->اگلا) != تہی) {
        type = &sym->type;
        منوال = classify_x86_64_arg(type, تہی, &سائز, &align, &reg_گنتی);
        انتخاب (منوال) {
        حالت x86_64_منوال_sse:
	    اگر (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            اگر (sse_param_اشاریہ + reg_گنتی <= 8) {
                /* save arguments passed by register */
                loc -= reg_گنتی * 8;
                param_addr = loc;
                برائے (i = 0; i < reg_گنتی; ++i) {
                    gen_modrm32(0xd60f66, sse_param_اشاریہ, VT_LOCAL, تہی, param_addr + i*8);
                    ++sse_param_اشاریہ;
                }
            } ورنہ {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += سائز;
            }
            توڑو;
            
        حالت x86_64_منوال_حافظہ:
        حالت x86_64_منوال_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += سائز;
            توڑو;
            
        حالت x86_64_منوال_integer: {
            اگر (reg_param_اشاریہ + reg_گنتی <= REGN) {
                /* save arguments passed by register */
                loc -= reg_گنتی * 8;
                param_addr = loc;
                برائے (i = 0; i < reg_گنتی; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_اشاریہ], VT_LOCAL, تہی, param_addr + i*8);
                    ++reg_param_اشاریہ;
                }
            } ورنہ {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += سائز;
            }
            توڑو;
        }
	طےشدہ: توڑو; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_سیٹ_param(sym, param_addr, 0);
    }

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#اگر_ختم
}

/* generate function epilog */
خالی gfunc_epilog(خالی)
{
    صحیح v, saved_ind;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#اگر_ختم
    o(0xc9); /* leave */
    اگر (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ورنہ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    /* align local size to word & save local variables */
    v = (-loc + 15) & -16;
    saved_ind = ind;
    ind = func_sub_sp_انحراف - FUNC_PROLOG_سائز;
    o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
    o(0xec8148);  /* sub rsp, stacksize */
    gen_le32(v);
    ind = saved_ind;
}

#اگر_ختم /* not PE */

ST_FUNC خالی gen_fill_nops(صحیح بائٹیں)
{
    جب (بائٹیں--)
      g(0x90);
}

/* generate a jump to a label */
صحیح gjmp(صحیح t)
{
    واپس gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
خالی gjmp_addr(صحیح a)
{
    صحیح r;
    r = a - ind - 2;
    اگر (r == (علامتی حرف)r) {
        g(0xeb);
        g(r);
    } ورنہ {
        oad(0xe9, a - ind - 5);
    }
}

ST_FUNC صحیح gjmp_append(صحیح n, صحیح t)
{
    خالی *p;
    /* insert vtop->c jump list in t */
    اگر (n) {
        uint32_t n1 = n, n2;
        جب ((n2 = read32le(p = cur_متن_section->ڈیٹا + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    واپس t;
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
	    ورنہ
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        واپس t;
}

/* generate an integer binary operation */
خالی gen_opi(صحیح op)
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
            اگر (c == (علامتی حرف)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_قدر(r));
                g(c);
            } ورنہ {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_قدر(r), c);
            }
        } ورنہ {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_قدر(r) + REG_قدر(fr) * 8);
        }
        vtop--;
        اگر (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        توڑو;
    حالت '-':
    حالت TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        جاؤ gen_op8;
    حالت TOK_ADDC2: /* add with carry use */
        opc = 2;
        جاؤ gen_op8;
    حالت TOK_SUBC2: /* sub with carry use */
        opc = 3;
        جاؤ gen_op8;
    حالت '&':
        opc = 4;
        جاؤ gen_op8;
    حالت '^':
        opc = 6;
        جاؤ gen_op8;
    حالت '|':
        opc = 1;
        جاؤ gen_op8;
    حالت '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_قدر(fr) + REG_قدر(r) * 8);
        vtop--;
        توڑو;
    حالت TOK_SHL:
        opc = 4;
        جاؤ gen_سرکاؤ;
    حالت TOK_SHR:
        opc = 5;
        جاؤ gen_سرکاؤ;
    حالت TOK_SAR:
        opc = 7;
    gen_سرکاؤ:
        opc = 0xc0 | (opc << 3);
        اگر (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_قدر(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } ورنہ {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_قدر(r));
        }
        vtop--;
        توڑو;
    حالت TOK_UDIV:
    حالت TOK_UMOD:
        uu = 1;
        جاؤ divmod;
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
        o((uu ? 0xf0 : 0xf8) + REG_قدر(fr));
        اگر (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        ورنہ
            r = TREG_RAX;
        vtop->r = r;
        توڑو;
    طےشدہ:
        opc = 7;
        جاؤ gen_op8;
    }
}

خالی gen_opl(صحیح op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
خالی gen_opf(صحیح op)
{
    صحیح a, ft, fc, swapped, r, opc;
    صحیح bt = vtop->type.t & VT_BTYPE;
    صحیح float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    اگر (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        اگر (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } ورنہ {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, تہی, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        واپس;
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
            بھرو(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            اگر (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            ورنہ اگر (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            اگر (swapped)
                o(0xc9d9); /* fxch %st(1) */
            اگر (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            ورنہ
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            اگر (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } ورنہ اگر (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } ورنہ اگر (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } ورنہ {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } ورنہ {
            /* no memory reference possible for long double operations */
            بھرو(TREG_ST0, vtop);
            swapped = !swapped;

            انتخاب(op) {
            طےشدہ:
            حالت '+':
                a = 0;
                توڑو;
            حالت '-':
                a = 4;
                اگر (swapped)
                    a++;
                توڑو;
            حالت '*':
                a = 1;
                توڑو;
            حالت '/':
                a = 6;
                اگر (swapped)
                    a++;
                توڑو;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } ورنہ {
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
                v1.sym = تہی;
                بھرو(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            اگر (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } ورنہ {
                اگر (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                اگر (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } ورنہ {
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
            ورنہ
                opc = 0x2f0f; /* comisd */
            اگر ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } ورنہ {
            أكد((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            انتخاب(op) {
            طےشدہ:
            حالت '+':
                a = 0;
                توڑو;
            حالت '-':
                a = 4;
                توڑو;
            حالت '*':
                a = 1;
                توڑو;
            حالت '/':
                a = 6;
                توڑو;
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
	        v1.sym = تہی;
                بھرو(r, &v1);
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
            } ورنہ {
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
خالی gen_cvt_itof(صحیح t)
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
        } ورنہ اگر ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } ورنہ {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } ورنہ {
        صحیح r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        اگر ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
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
خالی gen_cvt_ftof(صحیح t)
{
    صحیح ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    اگر (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        اگر (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_قدر(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_قدر(vtop->r)*9);
        } ورنہ اگر (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_قدر(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } ورنہ اگر (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        اگر (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_قدر(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_قدر(vtop->r)*9);
        } ورنہ اگر (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_قدر(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } ورنہ {
        صحیح r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        اگر (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_قدر(r)*8);
            o(0xf024);
            vtop->r = r;
        } ورنہ اگر (tbt == VT_FLOAT) {
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
خالی gen_cvt_ftoi(صحیح t)
{
    صحیح ft, bt, سائز, r;
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
	    واپس;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    اگر (t != VT_INT)
        سائز = 8;
    ورنہ
        سائز = 4;

    r = get_reg(RC_INT);
    اگر (bt == VT_FLOAT) {
        o(0xf3);
    } ورنہ اگر (bt == VT_DOUBLE) {
        o(0xf2);
    } ورنہ {
        أكد(0);
    }
    orex(سائز == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_قدر(vtop->r) + REG_قدر(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC خالی gen_cvt_sxtw(خالی)
{
    صحیح r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_قدر(r) << 3) + REG_قدر(r));
}

/* char/short to int conversion */
ST_FUNC خالی gen_cvt_csti(صحیح t)
{
    صحیح r, sz, xl, ll;
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
ST_FUNC خالی gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_متن_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC خالی ggoto(خالی)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC خالی gen_vla_sp_save(صحیح addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, تہی, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC خالی gen_vla_sp_restore(صحیح addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, تہی, addr);
}

#اگر_تعریف_شدہ TCC_ہدف_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC خالی gen_vla_نتیجہ(صحیح addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, تہی, addr);
}
#اگر_ختم

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC خالی gen_vla_alloc(CType *type, صحیح align) {
    صحیح use_call = 0;

#اگر defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#اگر_ختم
    اگر (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    ورنہ {
        صحیح r;
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
ST_FUNC خالی gen_struct_copy(صحیح سائز)
{
    صحیح n = سائز / PTR_سائز;
#اگر_تعریف_شدہ TCC_ہدف_PE
    o(0x5756); /* push rsi, rdi */
#اگر_ختم
    gv2(RC_RDI, RC_RSI);
    اگر (n <= 4) {
        جب (n)
            o(0xa548), --n;
    } ورنہ {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    اگر (سائز & 0x04)
        o(0xa5);
    اگر (سائز & 0x02)
        o(0xa566);
    اگر (سائز & 0x01)
        o(0xa4);
#اگر_تعریف_شدہ TCC_ہدف_PE
    o(0x5e5f); /* pop rdi, rsi */
#اگر_ختم
    vpop();
    vpop();
}

/* end of x86-64 code generator */
/*************************************************************/
#اگر_ختم /* ! TARGET_DEFS_ONLY */
/******************************************************/
