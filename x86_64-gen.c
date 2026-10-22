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
गणना {
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
#define REG_मानम्(reg) ((reg) & 7)

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
ST_FUNC शून्य gen_struct_copy(पूर्णाङ्क size);

/******************************************************/
#अण्णहा /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#अन्तर्भाव "tcc.h"
#अन्तर्भाव <assert.h>

ST_DATA ध्रुव वर्ण * ध्रुव target_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_DATA ध्रुव पूर्णाङ्क reg_classes[NB_REGS] = {
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

स्थिर unsigned long func_sub_sp_offset;
स्थिर पूर्णाङ्क func_ret_sub;

#जइ defined(CONFIG_TCC_BCHECK)
स्थिर addr_t func_bound_offset;
स्थिर unsigned long func_bound_ind;
ST_DATA पूर्णाङ्क func_bound_add_epilog;
#endif

#ifdef TCC_TARGET_PE
स्थिर पूर्णाङ्क func_scratch, func_alloca;
#endif

/* XXX: make it faster ? */
ST_FUNC शून्य g(पूर्णाङ्क c)
{
    पूर्णाङ्क ind1;
    जइ (nocode_wanted)
        प्रत्यागम;
    ind1 = ind + 1;
    जइ (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC शून्य o(unsigned पूर्णाङ्क c)
{
    जाव (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC शून्य gen_le16(पूर्णाङ्क v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC शून्य gen_le32(पूर्णाङ्क c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

ST_FUNC शून्य gen_le64(int64_t c)
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

स्थिर शून्य orex(पूर्णाङ्क ll, पूर्णाङ्क r, पूर्णाङ्क r2, पूर्णाङ्क b)
{
    जइ ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    जइ ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    जइ (ll || REX_BASE(r) || REX_BASE(r2)) {
        जइ ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_BASE(r) | (REX_BASE(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC शून्य gsym_addr(पूर्णाङ्क t, पूर्णाङ्क a)
{
    जाव (t) {
        unsigned वर्ण *ptr = cur_text_section->data + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

स्थिर पूर्णाङ्क is64_type(पूर्णाङ्क t)
{
    प्रत्यागम ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
}

/* instruction + 4 bytes data. Return the address of the data */
स्थिर पूर्णाङ्क oad(पूर्णाङ्क c, पूर्णाङ्क s)
{
    पूर्णाङ्क t;
    जइ (nocode_wanted)
        प्रत्यागम s;
    o(c);
    t = ind;
    gen_le32(s);
    प्रत्यागम t;
}

/* generate jmp to a label */
#define gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC शून्य gen_addr32(पूर्णाङ्क r, Sym *sym, पूर्णाङ्क c)
{
    जइ (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC शून्य gen_addrpc32(पूर्णाङ्क r, Sym *sym, पूर्णाङ्क c)
{
    जइ (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
स्थिर शून्य gen_gotpcrel(पूर्णाङ्क r, Sym *sym, पूर्णाङ्क c)
{
#ifdef TCC_TARGET_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, रिक्त), c, r,
        cur_text_section->data[ind-3],
        cur_text_section->data[ind-2],
        cur_text_section->data[ind-1]
        );
#endif
    greloca(cur_text_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    जइ (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_मानम्(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
स्थिर शून्य gen_modrm_impl(पूर्णाङ्क opcode, पूर्णाङ्क ll, पूर्णाङ्क op_reg_0, पूर्णाङ्क r, Sym *sym, पूर्णाङ्क c)
{
    पूर्णाङ्क op_reg = REG_मानम्(op_reg_0) << 3;

    जइ ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_SIZE); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#अण्णहा
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#endif
        प्रत्यागम;
    }

    orex(ll, r, op_reg_0, opcode);

    जइ ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	जइ (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} अण्णहा {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    जइ (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } अण्णहा {
		gen_addrpc32(r, sym, c);
	    }
	}
    } अण्णहा जइ ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        जइ (c == (signed वर्ण)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } अण्णहा {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } अण्णहा जइ ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_मानम्(r));
        gen_le32(c);
    } अण्णहा जइ (r & VT_LVAL) {
        g(0x00 | op_reg | REG_मानम्(r));
    } अण्णहा {
        g(0xc0 | op_reg | REG_मानम्(r));
    }
}

स्थिर शून्य gen_modrm64(पूर्णाङ्क opcode, पूर्णाङ्क op_reg, पूर्णाङ्क r, Sym *sym, पूर्णाङ्क c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

स्थिर शून्य gen_modrm32(पूर्णाङ्क opcode, पूर्णाङ्क op_reg, पूर्णाङ्क r, Sym *sym, पूर्णाङ्क c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
शून्य load(पूर्णाङ्क r, SValue *sv)
{
    पूर्णाङ्क v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    जइ (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#ifndef TCC_TARGET_PE
    /* we use indirect access via got */
    जइ ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        पूर्णाङ्क tr = r | TREG_MEM;
        जइ (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#endif

    v = fr & VT_VALMASK;
    जइ (fr & VT_LVAL) {
        पूर्णाङ्क b, ll;
        जइ (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = रिक्त;
            fr = r;
            जइ (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            load(fr, &v1);
            fr |= VT_LVAL;
        }
	जइ (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = रिक्त;
	    fr = r;
	    जइ (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    load(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	जइ ((ft & VT_BTYPE) == VT_STRUCT) {
	    पूर्णाङ्क align;
	    विकल्प (type_size(&sv->type, &align)) {
		पक्ष 1: ft = VT_BYTE; भङ्ग;
		पक्ष 2: ft = VT_SHORT; भङ्ग;
		पक्ष 4: ft = VT_INT; भङ्ग;
		पक्ष 8: ft = VT_LLONG; भङ्ग;
		स्वभाव:
		    tcc_error("invalid aggregate type for register load");
		    भङ्ग;
	    }
	}
        जइ ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_मानम्(r); /* movd */
        } अण्णहा जइ ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_मानम्(r);
        } अण्णहा जइ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } अण्णहा जइ ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } अण्णहा जइ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } अण्णहा जइ ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } अण्णहा जइ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } अण्णहा जइ ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            प्रत्यागम;
        } अण्णहा {
            प्रतिज्ञा(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } अण्णहा {
        जइ (v == VT_CONST) {
            जइ (fr & VT_SYM) {
#ifdef TCC_TARGET_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#अण्णहा
                जइ (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, रिक्त, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_मानम्(r), 0);
                    greloca(cur_text_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } अण्णहा जइ (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_मानम्(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } अण्णहा {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_मानम्(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#endif
            } अण्णहा जइ (is64_type(ft)) {
                जइ (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_मानम्(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } अण्णहा जइ (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_मानम्(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } अण्णहा {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_मानम्(r) * 9);
                }
            } अण्णहा {
                orex(0,r,0, 0xb8 + REG_मानम्(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } अण्णहा जइ (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } अण्णहा जइ (v == VT_CMP) {
	    जइ (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_मानम्(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_BASE(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_मानम्(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_मानम्(r) * 0x900); /* movzbl %al, %eax */
        } अण्णहा जइ (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_मानम्(r), t); /* mov $1, r */
            o(0x05eb + (REX_BASE(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_मानम्(r), t ^ 1); /* mov $0, r */
        } अण्णहा जइ (v != r) {
            जइ ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                जइ (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_मानम्(r)*8); /* %xmmN */
                    o(0xf024);
                } अण्णहा {
                    प्रतिज्ञा((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    जइ ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } अण्णहा {
                        प्रतिज्ञा((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_मानम्(v) + REG_मानम्(r)*8);
                }
            } अण्णहा जइ (r == TREG_ST0) {
                प्रतिज्ञा((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_मानम्(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } अण्णहा {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_मानम्(r) + REG_मानम्(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
शून्य store(पूर्णाङ्क r, SValue *v)
{
    पूर्णाङ्क fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    पूर्णाङ्क opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    जइ (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#ifndef TCC_TARGET_PE
    /* we need to access the variable via got */
    जइ ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#endif

    /* XXX: incorrect if float reg to reg */
    जइ (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_मानम्(r);
    } अण्णहा जइ (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_मानम्(r);
    } अण्णहा जइ (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } अण्णहा जइ (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } अण्णहा {
        opc = 0x89;
        जइ (bt == VT_SHORT)
            opc = 0x8966;
        अण्णहा जइ (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
स्थिर शून्य gcall_or_jmp(पूर्णाङ्क is_jmp)
{
    पूर्णाङ्क r;
    जइ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (पूर्णाङ्क)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind + 1, R_X86_64_PLT32, (पूर्णाङ्क)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } अण्णहा {
        /* otherwise, indirect call */
        r = TREG_R11;
        load(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_मानम्(r) + (is_jmp << 4));
    }
}

#जइ defined(CONFIG_TCC_BCHECK)

स्थिर शून्य gen_bounds_call(पूर्णाङ्क v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#ifdef TCC_TARGET_PE
# define TREG_FASTCALL_1 TREG_RCX
#अण्णहा
# define TREG_FASTCALL_1 TREG_RDI
#endif

स्थिर शून्य gen_bounds_prolog(शून्य)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->data_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
}

स्थिर शून्य gen_bounds_epilog(शून्य)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    पूर्णाङ्क offset_modified = func_bound_offset != lbounds_section->data_offset;

    जइ (!offset_modified && !func_bound_add_epilog)
        प्रत्यागम;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, परिमाण(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section, 
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    जइ (offset_modified) {
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
स्थिर ध्रुव uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
स्थिर पूर्णाङ्क arg_prepare_reg(पूर्णाङ्क idx) {
  जइ (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      प्रत्यागम idx + 10;
  अण्णहा
      प्रत्यागम idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

स्थिर शून्य gen_offs_sp(पूर्णाङ्क b, पूर्णाङ्क r, पूर्णाङ्क d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    जइ (d == (signed वर्ण)d) {
        o(0x2444 | (REG_मानम्(r) << 3));
        g(d);
    } अण्णहा {
        o(0x2484 | (REG_मानम्(r) << 3));
        gen_le32(d);
    }
}

स्थिर पूर्णाङ्क using_regs(पूर्णाङ्क size)
{
    प्रत्यागम !(size > 8 || (size & (size - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC पूर्णाङ्क gfunc_sret(CType *vt, पूर्णाङ्क variadic, CType *ret, पूर्णाङ्क *ret_align, पूर्णाङ्क *regsize)
{
    पूर्णाङ्क size, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    size = type_size(vt, &align);
    जइ (!using_regs(size))
        प्रत्यागम 0;
    जइ (size == 8)
        ret->t = VT_LLONG;
    अण्णहा जइ (size == 4)
        ret->t = VT_INT;
    अण्णहा जइ (size == 2)
        ret->t = VT_SHORT;
    अण्णहा
        ret->t = VT_BYTE;
    ret->ref = रिक्त;
    प्रत्यागम 1;
}

स्थिर पूर्णाङ्क is_sse_float(पूर्णाङ्क t) {
    पूर्णाङ्क bt;
    bt = t & VT_BTYPE;
    प्रत्यागम bt == VT_DOUBLE || bt == VT_FLOAT;
}

स्थिर पूर्णाङ्क gfunc_arg_size(CType *type) {
    पूर्णाङ्क align;
    जइ (type->t & (VT_ARRAY|VT_BITFIELD))
        प्रत्यागम 8;
    प्रत्यागम type_size(type, &align);
}

शून्य gfunc_call(पूर्णाङ्क nb_args)
{
    पूर्णाङ्क size, r, args_size, i, d, bt, struct_size;
    पूर्णाङ्क arg;

#ifdef CONFIG_TCC_BCHECK
    जइ (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    args_size = (nb_args < REGN ? REGN : nb_args) * PTR_SIZE;
    arg = nb_args;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_size = args_size;
    प्रति(i = 0; i < nb_args; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        size = gfunc_arg_size(&sv->type);

        जइ (using_regs(size))
            अनुवर्त; /* arguments smaller than 8 bytes passed in registers or on stack */

        जइ (bt == VT_STRUCT) {
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
        } अण्णहा जइ (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_size);
            struct_size += 16;
        }
    }

    जइ (func_scratch < struct_size)
        func_scratch = struct_size;

    arg = nb_args;
    struct_size = args_size;

    प्रति(i = 0; i < nb_args; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        size = gfunc_arg_size(&vtop->type);
        जइ (!using_regs(size)) {
            /* align to stack align size */
            size = (size + 15) & ~15;
            जइ (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_size);
                gen_offs_sp(0x89, d, arg*8);
            } अण्णहा {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_size);
            }
            struct_size += size;
        } अण्णहा {
            जइ (is_sse_float(vtop->type.t)) {
		जइ (tcc_state->nosse)
		  tcc_error("SSE disabled");
                जइ (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } अण्णहा {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_मानम्(d));
                }
            } अण्णहा {
                जइ (bt == VT_STRUCT) {
                    vtop->type.ref = रिक्त;
                    vtop->type.t = size > 4 ? VT_LLONG : size > 2 ? VT_INT
                        : size > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                जइ (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } अण्णहा {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_मानम्(r) * 8 + REG_मानम्(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    जइ (nb_args > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        जइ (nb_args > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    जइ ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#ifdef CONFIG_TCC_BCHECK
        जइ (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#endif
    }
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

/* generate function prolog of type 't' */
शून्य gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    पूर्णाङ्क addr, reg_param_index, bt, size;
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
    जइ (!using_regs(size)) {
        gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, रिक्त, addr);
        func_vc = addr;
        reg_param_index++;
        addr += 8;
    }

    /* define parameters */
    जाव ((sym = sym->next) != रिक्त) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        size = gfunc_arg_size(type);
        जइ (!using_regs(size)) {
            जइ (reg_param_index < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, रिक्त, addr);
            }
            gfunc_set_param(sym, addr, 1);
        } अण्णहा {
            जइ (reg_param_index < REGN) {
                /* save arguments passed by register */
                जइ ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    जइ (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_index, VT_LOCAL, रिक्त, addr);
                } अण्णहा {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, रिक्त, addr);
                }
            }
            gfunc_set_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_index++;
    }

    जाव (reg_param_index < REGN) {
        जइ (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, रिक्त, addr);
            addr += 8;
        }
        reg_param_index++;
    }
#ifdef CONFIG_TCC_BCHECK
    जइ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
शून्य gfunc_epilog(शून्य)
{
    पूर्णाङ्क v, start;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#ifdef CONFIG_TCC_BCHECK
    जइ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    o(0xc9); /* leave */
    जइ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } अण्णहा {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    start = func_sub_sp_offset - FUNC_PROLOG_SIZE;
    cur_text_section->data_offset = ind;
    pe_add_unwind_data(start, ind, v);

    ind = start;
    जइ (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } अण्णहा {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_text_section->data_offset;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#अण्णहा

स्थिर शून्य gadd_sp(पूर्णाङ्क val)
{
    जइ (val == (signed वर्ण)val) {
        o(0xc48348);
        g(val);
    } अण्णहा {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

प्रकारनिर्देश गणना X86_64_Mode {
  x86_64_mode_none,
  x86_64_mode_memory,
  x86_64_mode_integer,
  x86_64_mode_sse,
  x86_64_mode_x87
} X86_64_Mode;

स्थिर X86_64_Mode classify_x86_64_merge(X86_64_Mode a, X86_64_Mode b)
{
    जइ (a == b)
        प्रत्यागम a;
    अण्णहा जइ (a == x86_64_mode_none)
        प्रत्यागम b;
    अण्णहा जइ (b == x86_64_mode_none)
        प्रत्यागम a;
    अण्णहा जइ ((a == x86_64_mode_memory) || (b == x86_64_mode_memory))
        प्रत्यागम x86_64_mode_memory;
    अण्णहा जइ ((a == x86_64_mode_integer) || (b == x86_64_mode_integer))
        प्रत्यागम x86_64_mode_integer;
    अण्णहा जइ ((a == x86_64_mode_x87) || (b == x86_64_mode_x87))
        प्रत्यागम x86_64_mode_memory;
    अण्णहा
        प्रत्यागम x86_64_mode_sse;
}

स्थिर X86_64_Mode classify_x86_64_inner(CType *ty)
{
    X86_64_Mode mode;
    Sym *f;
    
    विकल्प (ty->t & VT_BTYPE) {
    पक्ष VT_VOID: प्रत्यागम x86_64_mode_none;
    
    पक्ष VT_INT:
    पक्ष VT_BYTE:
    पक्ष VT_SHORT:
    पक्ष VT_LLONG:
    पक्ष VT_BOOL:
    पक्ष VT_PTR:
    पक्ष VT_FUNC:
        प्रत्यागम x86_64_mode_integer;
    
    पक्ष VT_FLOAT:
    पक्ष VT_DOUBLE: प्रत्यागम x86_64_mode_sse;
    
    पक्ष VT_LDOUBLE: प्रत्यागम x86_64_mode_x87;
      
    पक्ष VT_STRUCT:
        f = ty->ref;

        mode = x86_64_mode_none;
        प्रति (f = f->next; f; f = f->next)
            mode = classify_x86_64_merge(mode, classify_x86_64_inner(&f->type));
        
        प्रत्यागम mode;
    }
    प्रतिज्ञा(0);
    प्रत्यागम 0;
}

स्थिर X86_64_Mode classify_x86_64_arg(CType *ty, CType *ret, पूर्णाङ्क *psize, पूर्णाङ्क *palign, पूर्णाङ्क *reg_गणनम्)
{
    X86_64_Mode mode;
    पूर्णाङ्क size, align, ret_t = 0;
    
    जइ (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_गणनम् = 1;
        ret_t = ty->t;
        mode = x86_64_mode_integer;
    } अण्णहा {
        size = type_size(ty, &align);
        *psize = (size + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_गणनम् = 0; /* avoid compiler warning */

        जइ (size > 16) {
            mode = x86_64_mode_memory;
        } अण्णहा {
            mode = classify_x86_64_inner(ty);
            विकल्प (mode) {
            पक्ष x86_64_mode_integer:
                जइ (size > 8) {
                    *reg_गणनम् = 2;
                    ret_t = VT_QLONG;
                } अण्णहा {
                    *reg_गणनम् = 1;
                    जइ (size > 4)
                        ret_t = VT_LLONG;
                    अण्णहा जइ (size > 2)
                        ret_t = VT_INT;
                    अण्णहा जइ (size > 1)
                        ret_t = VT_SHORT;
                    अण्णहा
                        ret_t = VT_BYTE;
                    जइ ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                भङ्ग;
                
            पक्ष x86_64_mode_x87:
                *reg_गणनम् = 1;
                ret_t = VT_LDOUBLE;
                भङ्ग;

            पक्ष x86_64_mode_sse:
                जइ (size > 8) {
                    *reg_गणनम् = 2;
                    ret_t = VT_QFLOAT;
                } अण्णहा {
                    *reg_गणनम् = 1;
                    ret_t = (size > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                भङ्ग;
            स्वभाव: भङ्ग; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    जइ (ret) {
        ret->ref = रिक्त;
        ret->t = ret_t;
    }
    
    प्रत्यागम mode;
}

ST_FUNC पूर्णाङ्क classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    गणना __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    पूर्णाङ्क size, align, reg_गणनम्;
    X86_64_Mode mode = classify_x86_64_arg(ty, रिक्त, &size, &align, &reg_गणनम्);
    विकल्प (mode) {
    स्वभाव: प्रत्यागम __va_stack;
    पक्ष x86_64_mode_integer: प्रत्यागम __va_gen_reg;
    पक्ष x86_64_mode_sse: प्रत्यागम __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC पूर्णाङ्क gfunc_sret(CType *vt, पूर्णाङ्क variadic, CType *ret, पूर्णाङ्क *ret_align, पूर्णाङ्क *regsize)
{
    पूर्णाङ्क size, align, reg_गणनम्;
    जइ (classify_x86_64_arg(vt, ret, &size, &align, &reg_गणनम्) == x86_64_mode_memory)
        प्रत्यागम 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_गणनम्; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    प्रत्यागम 1;
}

#define REGN 6
स्थिर ध्रुव uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

स्थिर पूर्णाङ्क arg_prepare_reg(पूर्णाङ्क idx) {
  जइ (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      प्रत्यागम idx + 8;
  अण्णहा
      प्रत्यागम idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
शून्य gfunc_call(पूर्णाङ्क nb_args)
{
    X86_64_Mode mode;
    CType type;
    पूर्णाङ्क size, align, r, args_size, राशिः_adjust, i, reg_गणनम्, k;
    पूर्णाङ्क nb_reg_args = 0;
    पूर्णाङ्क nb_sse_args = 0;
    पूर्णाङ्क sse_reg, gen_reg;
    वर्ण *onstack = tcc_malloc((nb_args + 1) * परिमाण (वर्ण));

#ifdef CONFIG_TCC_BCHECK
    जइ (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    राशिः_adjust = 0;
    प्रति(i = nb_args - 1; i >= 0; i--) {
        mode = classify_x86_64_arg(&vtop[-i].type, रिक्त, &size, &align, &reg_गणनम्);
        जइ (size == 0) अनुवर्त;
        जइ (mode == x86_64_mode_sse && nb_sse_args + reg_गणनम् <= 8) {
            nb_sse_args += reg_गणनम्;
	    onstack[i] = 0;
	} अण्णहा जइ (mode == x86_64_mode_integer && nb_reg_args + reg_गणनम् <= REGN) {
            nb_reg_args += reg_गणनम्;
	    onstack[i] = 0;
	} अण्णहा जइ (mode == x86_64_mode_none) {
	    onstack[i] = 0;
	} अण्णहा {
	    जइ (align == 16 && (राशिः_adjust &= 15)) {
		onstack[i] = 2;
		राशिः_adjust = 0;
	    } अण्णहा
	      onstack[i] = 1;
	    राशिः_adjust += size;
	}
    }

    जइ (nb_sse_args && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_args;
    sse_reg = nb_sse_args;
    args_size = 0;
    राशिः_adjust &= 15;
    प्रति (i = k = 0; i < nb_args;) {
	mode = classify_x86_64_arg(&vtop[-i].type, रिक्त, &size, &align, &reg_गणनम्);
	जइ (size) {
            जइ (!onstack[i + k]) {
	        ++i;
	        अनुवर्त;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            जइ (राशिः_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                args_size += 8;
	        राशिः_adjust = 0;
            }
	    जइ (onstack[i + k] == 2)
	        राशिः_adjust = 1;
        }

	vrotb(i+1);

	विकल्प (vtop->type.t & VT_BTYPE) {
	    पक्ष VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, size); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_मानम्(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_मानम्(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		भङ्ग;

	    पक्ष VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, size); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		भङ्ग;

	    पक्ष VT_FLOAT:
	    पक्ष VT_DOUBLE:
		प्रतिज्ञा(mode == x86_64_mode_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_मानम्(r)*8);
		o(0x24);
		भङ्ग;

	    स्वभाव:
		प्रतिज्ञा(mode == x86_64_mode_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_मानम्(r)); /* push r */
		भङ्ग;
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
    प्रतिज्ञा(gen_reg <= REGN);
    प्रतिज्ञा(sse_reg <= 8);
    प्रति(i = 0; i < nb_args; i++) {
        mode = classify_x86_64_arg(&vtop->type, &type, &size, &align, &reg_गणनम्);
        जइ (size == 0) अनुवर्त;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        जइ (mode == x86_64_mode_sse) {
            जइ (reg_गणनम् == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                जइ (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } अण्णहा {
                प्रतिज्ञा(reg_गणनम् == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } अण्णहा जइ (mode == x86_64_mode_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            पूर्णाङ्क d;
            gen_reg -= reg_गणनम्;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_मानम्(r) * 8 + REG_मानम्(d));
            जइ (reg_गणनम् == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_मानम्(vtop->r2) * 8 + REG_मानम्(d));
            }
        }
        vtop--;
    }
    प्रतिज्ञा(gen_reg == 0);
    प्रतिज्ञा(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    जइ (nb_reg_args > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        जइ (nb_reg_args > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    जइ (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_args < 8 ? nb_sse_args : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    जइ (args_size)
        gadd_sp(args_size);
    vtop--;
}

#define FUNC_PROLOG_SIZE 11

स्थिर शून्य प्रक्षिप_arg_reg(पूर्णाङ्क i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, रिक्त, loc);
}

/* generate function prolog of type 't' */
शून्य gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_Mode mode, ret_mode;
    पूर्णाङ्क i, addr, align, size, reg_गणनम्;
    पूर्णाङ्क param_addr = 0, reg_param_index, sse_param_index;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_SIZE * 2;
    loc = 0;
    ind += FUNC_PROLOG_SIZE;
    func_sub_sp_offset = ind;
    func_ret_sub = 0;
    ret_mode = classify_x86_64_arg(&func_vt, रिक्त, &size, &align, &reg_गणनम्);

    जइ (func_var) {
        पूर्णाङ्क seen_reg_अङ्कः, seen_sse_अङ्कः, seen_राशिः_size;
        seen_reg_अङ्कः = ret_mode == x86_64_mode_memory;
        seen_sse_अङ्कः = 0;
        /* frame pointer and return address */
        seen_राशिः_size = PTR_SIZE * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        जाव ((sym = sym->next) != रिक्त) {
            type = &sym->type;
            mode = classify_x86_64_arg(type, रिक्त, &size, &align, &reg_गणनम्);
            विकल्प (mode) {
            स्वभाव:
            राशिः_arg:
                seen_राशिः_size = ((seen_राशिः_size + align - 1) & -align) + size;
                भङ्ग;
                
            पक्ष x86_64_mode_integer:
                जइ (seen_reg_अङ्कः + reg_गणनम् > REGN)
		    गच्छ राशिः_arg;
		seen_reg_अङ्कः += reg_गणनम्;
                भङ्ग;
                
            पक्ष x86_64_mode_sse:
                जइ (seen_sse_अङ्कः + reg_गणनम् > 8)
		    गच्छ राशिः_arg;
		seen_sse_अङ्कः += reg_गणनम्;
                भङ्ग;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(seen_reg_अङ्कः * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(seen_sse_अङ्कः * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(seen_राशिः_size);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        प्रति (i = 0; i < 8; i++) {
            loc -= 16;
	    जइ (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, रिक्त, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        प्रति (i = 0; i < REGN; i++) {
            प्रक्षिप_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_index = 0;
    sse_param_index = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    जइ (ret_mode == x86_64_mode_memory) {
        प्रक्षिप_arg_reg(reg_param_index);
        func_vc = loc;
        reg_param_index++;
    }
    /* define parameters */
    जाव ((sym = sym->next) != रिक्त) {
        type = &sym->type;
        mode = classify_x86_64_arg(type, रिक्त, &size, &align, &reg_गणनम्);
        विकल्प (mode) {
        पक्ष x86_64_mode_sse:
	    जइ (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            जइ (sse_param_index + reg_गणनम् <= 8) {
                /* save arguments passed by register */
                loc -= reg_गणनम् * 8;
                param_addr = loc;
                प्रति (i = 0; i < reg_गणनम्; ++i) {
                    gen_modrm32(0xd60f66, sse_param_index, VT_LOCAL, रिक्त, param_addr + i*8);
                    ++sse_param_index;
                }
            } अण्णहा {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            भङ्ग;
            
        पक्ष x86_64_mode_memory:
        पक्ष x86_64_mode_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += size;
            भङ्ग;
            
        पक्ष x86_64_mode_integer: {
            जइ (reg_param_index + reg_गणनम् <= REGN) {
                /* save arguments passed by register */
                loc -= reg_गणनम् * 8;
                param_addr = loc;
                प्रति (i = 0; i < reg_गणनम्; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_index], VT_LOCAL, रिक्त, param_addr + i*8);
                    ++reg_param_index;
                }
            } अण्णहा {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += size;
            }
            भङ्ग;
        }
	स्वभाव: भङ्ग; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_set_param(sym, param_addr, 0);
    }

#ifdef CONFIG_TCC_BCHECK
    जइ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
शून्य gfunc_epilog(शून्य)
{
    पूर्णाङ्क v, saved_ind;

#ifdef CONFIG_TCC_BCHECK
    जइ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif
    o(0xc9); /* leave */
    जइ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } अण्णहा {
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

ST_FUNC शून्य gen_fill_nops(पूर्णाङ्क bytes)
{
    जाव (bytes--)
      g(0x90);
}

/* generate a jump to a label */
पूर्णाङ्क gjmp(पूर्णाङ्क t)
{
    प्रत्यागम gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
शून्य gjmp_addr(पूर्णाङ्क a)
{
    पूर्णाङ्क r;
    r = a - ind - 2;
    जइ (r == (signed वर्ण)r) {
        g(0xeb);
        g(r);
    } अण्णहा {
        oad(0xe9, a - ind - 5);
    }
}

ST_FUNC पूर्णाङ्क gjmp_append(पूर्णाङ्क n, पूर्णाङ्क t)
{
    शून्य *p;
    /* insert vtop->c jump list in t */
    जइ (n) {
        uint32_t n1 = n, n2;
        जाव ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    प्रत्यागम t;
}

ST_FUNC पूर्णाङ्क gjmp_cond(पूर्णाङ्क op, पूर्णाङ्क t)
{
        जइ (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            पूर्णाङ्क v = vtop->cmp_r;
            op &= ~0x100;
            जइ (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    अण्णहा
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        प्रत्यागम t;
}

/* generate an integer binary operation */
शून्य gen_opi(पूर्णाङ्क op)
{
    पूर्णाङ्क r, fr, opc, c;
    पूर्णाङ्क ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    विकल्प(op) {
    पक्ष '+':
    पक्ष TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        जइ (cc && (!ll || (पूर्णाङ्क)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            जइ (c == (signed वर्ण)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_मानम्(r));
                g(c);
            } अण्णहा {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_मानम्(r), c);
            }
        } अण्णहा {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_मानम्(r) + REG_मानम्(fr) * 8);
        }
        vtop--;
        जइ (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        भङ्ग;
    पक्ष '-':
    पक्ष TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        गच्छ gen_op8;
    पक्ष TOK_ADDC2: /* add with carry use */
        opc = 2;
        गच्छ gen_op8;
    पक्ष TOK_SUBC2: /* sub with carry use */
        opc = 3;
        गच्छ gen_op8;
    पक्ष '&':
        opc = 4;
        गच्छ gen_op8;
    पक्ष '^':
        opc = 6;
        गच्छ gen_op8;
    पक्ष '|':
        opc = 1;
        गच्छ gen_op8;
    पक्ष '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_मानम्(fr) + REG_मानम्(r) * 8);
        vtop--;
        भङ्ग;
    पक्ष TOK_SHL:
        opc = 4;
        गच्छ gen_shift;
    पक्ष TOK_SHR:
        opc = 5;
        गच्छ gen_shift;
    पक्ष TOK_SAR:
        opc = 7;
    gen_shift:
        opc = 0xc0 | (opc << 3);
        जइ (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_मानम्(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } अण्णहा {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_मानम्(r));
        }
        vtop--;
        भङ्ग;
    पक्ष TOK_UDIV:
    पक्ष TOK_UMOD:
        uu = 1;
        गच्छ divmod;
    पक्ष '/':
    पक्ष '%':
    पक्ष TOK_PDIV:
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
        o((uu ? 0xf0 : 0xf8) + REG_मानम्(fr));
        जइ (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        अण्णहा
            r = TREG_RAX;
        vtop->r = r;
        भङ्ग;
    स्वभाव:
        opc = 7;
        गच्छ gen_op8;
    }
}

शून्य gen_opl(पूर्णाङ्क op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
शून्य gen_opf(पूर्णाङ्क op)
{
    पूर्णाङ्क a, ft, fc, swapped, r, opc;
    पूर्णाङ्क bt = vtop->type.t & VT_BTYPE;
    पूर्णाङ्क float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    जइ (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        जइ (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } अण्णहा {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, रिक्त, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        प्रत्यागम;
    }

    /* convert constants to memory references */
    जइ ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    जइ ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    जइ ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    जइ (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    जइ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        जइ (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            load(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
            जइ (op == TOK_GE || op == TOK_GT)
                swapped = !swapped;
            अण्णहा जइ (op == TOK_EQ || op == TOK_NE)
                swapped = 0;
            जइ (swapped)
                o(0xc9d9); /* fxch %st(1) */
            जइ (op == TOK_EQ || op == TOK_NE)
                o(0xe9da); /* fucompp */
            अण्णहा
                o(0xd9de); /* fcompp */
            o(0xe0df); /* fnstsw %ax */
            जइ (op == TOK_EQ) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40fC80); /* cmp $0x40, %ah */
            } अण्णहा जइ (op == TOK_NE) {
                o(0x45e480); /* and $0x45, %ah */
                o(0x40f480); /* xor $0x40, %ah */
                op = TOK_NE;
            } अण्णहा जइ (op == TOK_GE || op == TOK_LE) {
                o(0x05c4f6); /* test $0x05, %ah */
                op = TOK_EQ;
            } अण्णहा {
                o(0x45c4f6); /* test $0x45, %ah */
                op = TOK_EQ;
            }
            vtop--;
            vset_VT_CMP(op);
        } अण्णहा {
            /* no memory reference possible for long double operations */
            load(TREG_ST0, vtop);
            swapped = !swapped;

            विकल्प(op) {
            स्वभाव:
            पक्ष '+':
                a = 0;
                भङ्ग;
            पक्ष '-':
                a = 4;
                जइ (swapped)
                    a++;
                भङ्ग;
            पक्ष '*':
                a = 1;
                भङ्ग;
            पक्ष '/':
                a = 6;
                जइ (swapped)
                    a++;
                भङ्ग;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } अण्णहा {
        जइ (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            जइ ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = रिक्त;
                load(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            जइ (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } अण्णहा {
                जइ (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                जइ (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } अण्णहा {
                    op = 0x97; /* seta */
                }
            }

            जइ (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            प्रतिज्ञा(!(vtop[-1].r & VT_LVAL));
            
            जइ (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            अण्णहा
                opc = 0x2f0f; /* comisd */
            जइ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } अण्णहा {
            प्रतिज्ञा((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            विकल्प(op) {
            स्वभाव:
            पक्ष '+':
                a = 0;
                भङ्ग;
            पक्ष '-':
                a = 4;
                भङ्ग;
            पक्ष '*':
                a = 1;
                भङ्ग;
            पक्ष '/':
                a = 6;
                भङ्ग;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            प्रतिज्ञा((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            जइ ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = रिक्त;
                load(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            प्रतिज्ञा(!(vtop[-1].r & VT_LVAL));
            जइ (swapped) {
                प्रतिज्ञा(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            जइ ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } अण्णहा {
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
शून्य gen_cvt_itof(पूर्णाङ्क t)
{
    जइ ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        जइ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } अण्णहा जइ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } अण्णहा {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } अण्णहा {
        पूर्णाङ्क r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        जइ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_मानम्(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
शून्य gen_cvt_ftof(पूर्णाङ्क t)
{
    पूर्णाङ्क ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    जइ (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        जइ (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_मानम्(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_मानम्(vtop->r)*9);
        } अण्णहा जइ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_मानम्(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } अण्णहा जइ (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        जइ (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_मानम्(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_मानम्(vtop->r)*9);
        } अण्णहा जइ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_मानम्(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } अण्णहा {
        पूर्णाङ्क r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        जइ (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_मानम्(r)*8);
            o(0xf024);
            vtop->r = r;
        } अण्णहा जइ (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_मानम्(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
शून्य gen_cvt_ftoi(पूर्णाङ्क t)
{
    पूर्णाङ्क ft, bt, size, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    जइ (bt == VT_LDOUBLE) {
	जइ (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    प्रत्यागम;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    जइ (t != VT_INT)
        size = 8;
    अण्णहा
        size = 4;

    r = get_reg(RC_INT);
    जइ (bt == VT_FLOAT) {
        o(0xf3);
    } अण्णहा जइ (bt == VT_DOUBLE) {
        o(0xf2);
    } अण्णहा {
        प्रतिज्ञा(0);
    }
    orex(size == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_मानम्(vtop->r) + REG_मानम्(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC शून्य gen_cvt_sxtw(शून्य)
{
    पूर्णाङ्क r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_मानम्(r) << 3) + REG_मानम्(r));
}

/* char/short to int conversion */
ST_FUNC शून्य gen_cvt_csti(पूर्णाङ्क t)
{
    पूर्णाङ्क r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_मानम्(r) << 3 | REG_मानम्(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC शून्य gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_text_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC शून्य ggoto(शून्य)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC शून्य gen_vla_sp_save(पूर्णाङ्क addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, रिक्त, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC शून्य gen_vla_sp_restore(पूर्णाङ्क addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, रिक्त, addr);
}

#ifdef TCC_TARGET_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC शून्य gen_vla_result(पूर्णाङ्क addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, रिक्त, addr);
}
#endif

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC शून्य gen_vla_alloc(CType *type, पूर्णाङ्क align) {
    पूर्णाङ्क use_call = 0;

#जइ defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#endif
#ifdef TCC_TARGET_PE	/* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#endif
    जइ (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    अण्णहा {
        पूर्णाङ्क r;
        r = gv(RC_INT); /* allocation size */
        /* sub r,%rsp */
        o(0x2b48);
        o(0xe0 | REG_मानम्(r));
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
ST_FUNC शून्य gen_struct_copy(पूर्णाङ्क size)
{
    पूर्णाङ्क n = size / PTR_SIZE;
#ifdef TCC_TARGET_PE
    o(0x5756); /* push rsi, rdi */
#endif
    gv2(RC_RDI, RC_RSI);
    जइ (n <= 4) {
        जाव (n)
            o(0xa548), --n;
    } अण्णहा {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    जइ (size & 0x04)
        o(0xa5);
    जइ (size & 0x02)
        o(0xa566);
    जइ (size & 0x01)
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
