/*
 *  X86 code generator for TCC
 * 
 *  Copyright (c) 2001-2004 Fabrice Bellard
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
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_REGS         5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_ASM_REGS     8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_INT     0x0001 /* generic integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FLOAT   0x0002 /* generic float register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_EAX     0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_EDX     0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_ECX     0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_EBX     0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_ST0     0x0040

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_IRET    RC_EAX /* function return: integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_IRE2    RC_EDX /* function return: second integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
ਗਿਣਤੀ {
    TREG_EAX = 0,
    TREG_ECX,
    TREG_EDX,
    TREG_EBX,
    TREG_ST0,
    TREG_ESP = 4,
    TREG_MEM = 0x20
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਮੁੱਲ(reg) ((reg) & 7)

/* return registers for function */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IRET TREG_EAX /* single word int return register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IRE2 TREG_EDX /* second word return register (for long long) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_FRET TREG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTR_ਮਾਪ 4

/* long double size and alignment, in bytes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ਮਾਪ  12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ALIGN 4
/* maximum alignment (for aligned attribute support) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_ALIGN     8

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROMOTE_RET

/******************************************************/
#ਨਹੀਂਤਾਂ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

ST_ਅੰਕੜੇ ਅਚਲ ਅੱਖਰ * ਅਚਲ ਨਿਸ਼ਾਨਾ_machine_defs =
    "__i386__\0"
    "__i386\0"
    ;

#ਜੇ defined CONFIG_TCC_PIC
# define USE_EBX 2
#ਨਹੀਂਤਾਂ
# define USE_EBX 0 /* define to 1 to have EBX as 4th register */
#ਜੇ_ਅੰਤ

ST_ਅੰਕੜੇ ਅਚਲ ਪੂਰਨ reg_classes[NB_REGS] = {
    /* eax */ RC_INT | RC_EAX,
    /* ecx */ RC_INT | RC_ECX,
    /* edx */ RC_INT | RC_EDX,
    /* ebx */ (RC_INT | RC_EBX) * (USE_EBX == 1),
    /* st0 */ RC_FLOAT | RC_ST0,
};

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ func_sub_sp_ਵਿੱਥ;
ਸਥਿਰ ਪੂਰਨ func_ret_sub;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
ਸਥਿਰ addr_t func_bound_ਵਿੱਥ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ func_bound_ind;
ST_ਅੰਕੜੇ ਪੂਰਨ func_bound_ਜੋੜੋ_epilog;
ਸਥਿਰ ਖਾਲੀ gen_bounds_prolog(ਖਾਲੀ);
ਸਥਿਰ ਖਾਲੀ gen_bounds_epilog(ਖਾਲੀ);
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

/* output a symbol and patch all calls to it */
ST_FUNC ਖਾਲੀ gsym_addr(ਪੂਰਨ t, ਪੂਰਨ a)
{
    ਜਦੋਂ (t) {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr = cur_ਪਾਠ_section->ਅੰਕੜੇ + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a - t - 4);
        t = n;
    }
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

ST_FUNC ਖਾਲੀ gen_fill_nops(ਪੂਰਨ ਬਾਈਟਾਂ)
{
    ਜਦੋਂ (ਬਾਈਟਾਂ--)
      g(0x90);
}

#ਜੇ defined CONFIG_TCC_PIC
ਸਥਿਰ ਖਾਲੀ gen_static_call(ਪੂਰਨ v);
ਸਥਿਰ ਖਾਲੀ get_pc_thunk(ਪੂਰਨ r, ਪੂਰਨ ਜੋੜੋ)
{
    ਸਥਿਰ ਅਚਲ ਅੱਖਰ * ਅਚਲ pc_thunk_name[] = {
	"__x86.get_pc_thunk.ax",
	"__x86.get_pc_thunk.cx",
	"__x86.get_pc_thunk.dx",
	"__x86.get_pc_thunk.bx"
    };
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    gen_static_call(tok_alloc_const(pc_thunk_name[r]));
    ਜੇ (ਜੋੜੋ) {
        Sym label = {0};
        label.type.t = VT_VOID|VT_STATIC;
        put_extern_sym(&label, cur_ਪਾਠ_section, ind, 0);
        r = REG_ਮੁੱਲ(r);
	ਜੇ (r == 0)
	    oad(0x05, 1); /* add _GLOBAL_OFFSET_TABLE_, %eax */
	ਨਹੀਂਤਾਂ
            oad(0xc081 + r * 0x100, 2); /* add _GLOBAL_OFFSET_TABLE_, %erx */
        greloc(cur_ਪਾਠ_section, &label, ind - 4, R_386_GOTPC);
    }
}

ST_FUNC ਖਾਲੀ gen_gotpcrel(ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c)
{
    greloc(cur_ਪਾਠ_section, sym, ind, R_386_GOT32X);
    gen_le32(0);
    ਜੇ (c) {
	r = REG_ਮੁੱਲ(r);
	ਜੇ (r == 0)
            oad(0x05, c);
	ਨਹੀਂਤਾਂ
            oad(0xc081 + r * 0x100, c);
    }
}
#ਜੇ_ਅੰਤ

/* generate jmp to a label */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ gjmp2(instr,lbl) oad(instr,lbl)

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ਖਾਲੀ gen_addr32(ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c)
{
    ਜੇ (r & VT_SYM)
        greloc(cur_ਪਾਠ_section, sym, ind, R_386_32);
    gen_le32(c);
}

ST_FUNC ਖਾਲੀ gen_addrpc32(ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c)
{
    ਜੇ (r & VT_SYM)
        greloc(cur_ਪਾਠ_section, sym, ind, R_386_PC32);
    gen_le32(c - 4);
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode bits */
ਸਥਿਰ ਖਾਲੀ gen_modrm(ਪੂਰਨ opc, ਪੂਰਨ op_r2, ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c)
{
    ਪੂਰਨ op_reg = REG_ਮੁੱਲ(op_r2) << 3;

    ਜੇ ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        Sym *s2 = external_global_sym(TOK_tls_ਸੂਚਕਾਂਕ, &int_type);
        r = get_reg(RC_INT);
        gen_modrm(0x8b, r, VT_SYM|VT_CONST, s2, 0); /* mov __tls_index, r */
        o(0x02e0c1 | r << 8); /* shl 2,r */
        oad(0x050364 | r << 19, 11*PTR_ਮਾਪ); /* add fs:0x2c,r */
        gen_modrm(0x8b, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        o(opc), oad(0x80 | op_reg | r, c); /* mov #c(r),op_reg */
        greloc(cur_ਪਾਠ_section, sym, ind - 4, R_386_TLS_LE);
#ਨਹੀਂਤਾਂ
        o(0x65); /* gs segment prefix */
        o(opc), oad(0x05 | op_reg, c);
        greloc(cur_ਪਾਠ_section, sym, ind - 4, R_386_TLS_LE);
#ਜੇ_ਅੰਤ
#ਜੇ defined CONFIG_TCC_PIC
    } ਨਹੀਂਤਾਂ ਜੇ ((r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
        ਪੂਰਨ is_got = (op_r2 & TREG_MEM) && !(sym->type.t & VT_STATIC);
        ਪੂਰਨ ਇੱਥੇ = ind;
        get_pc_thunk(TREG_EBX, is_got);
        o(opc);
        o(0x83 | op_reg);
        ਜੇ (is_got) {
            gen_gotpcrel(r, sym, c);
        } ਨਹੀਂਤਾਂ {
            gen_addrpc32(r, sym, c + (ind - ਇੱਥੇ - 1));
        }
    } ਨਹੀਂਤਾਂ ਜੇ ((r & VT_VALMASK) < VT_CONST && (r & TREG_MEM)) {
        o(opc);
        ਜੇ (c) {
            g(0x80 | op_reg | REG_ਮੁੱਲ(r));
            gen_le32(c);
        } ਨਹੀਂਤਾਂ {
            g(0x00 | op_reg | REG_ਮੁੱਲ(r));
        }
#ਜੇ_ਅੰਤ
    } ਨਹੀਂਤਾਂ ਜੇ ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
        o(opc);
        o(0x05 | op_reg);
        gen_addr32(r, sym, c);
    } ਨਹੀਂਤਾਂ ਜੇ ((r & VT_VALMASK) == VT_LOCAL) {
	o(opc);
        /* currently, we use only ebp as base */
        ਜੇ (c == (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } ਨਹੀਂਤਾਂ {
            oad(0x85 | op_reg, c);
        }
    } ਨਹੀਂਤਾਂ {
	o(opc);
        g(0x00 | op_reg | (r & VT_VALMASK));
    }
}

/* load 'r' from value 'sv' */
ST_FUNC ਖਾਲੀ ਲੱਦੋ(ਪੂਰਨ r, SValue *sv)
{
    ਪੂਰਨ v, t, ft, fc, fr, opc;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~VT_DEFSIGN;
    fc = sv->c.i;
    ft &= ~VT_QUAL;
    v = fr & VT_VALMASK;

#ਜੇ defined CONFIG_TCC_PIC
    /* we use indirect access via got */
    ਜੇ ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        ਪੂਰਨ tr = r | TREG_MEM;
        ਜੇ (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm(0x8b, tr, fr, sv->sym, 0);
        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#ਜੇ_ਅੰਤ

    ਜੇ (fr & VT_LVAL) {
        ਜੇ (v == VT_LLOCAL) {
            v1.type.t = VT_INT;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
            v1.sym = ਨਿਰਾ;
            fr = r;
            ਜੇ (!(reg_classes[fr] & RC_INT))
                fr = get_reg(RC_INT);
            ਲੱਦੋ(fr, &v1);
        }
        ਜੇ ((ft & VT_BTYPE) == VT_FLOAT) {
            opc = 0xd9; /* flds */
            r = 0;
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_DOUBLE) {
            opc = 0xdd; /* fldl */
            r = 0;
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            opc = 0xdb; /* fldt */
            r = 5;
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            opc = 0xbe0f;   /* movsbl */
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED) ||
		   (ft & VT_TYPE) == (VT_BOOL | VT_UNSIGNED)) {
            opc = 0xb60f;   /* movzbl */
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == VT_SHORT) {
            opc = 0xbf0f;   /* movswl */
        } ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            opc = 0xb70f;   /* movzwl */
        } ਨਹੀਂਤਾਂ {
            opc = 0x8b;     /* movl */
        }
        gen_modrm(opc, r, fr, sv->sym, fc);
    } ਨਹੀਂਤਾਂ {
        ਜੇ ((fr & VT_SYM) && (sv->sym->type.t & VT_TLS)) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            gen_modrm(0x8d, r, fr, sv->sym, fc);
#ਨਹੀਂਤਾਂ
            oad(0x058b65 | REG_ਮੁੱਲ(r) << 19, 0); /* mov gs:0,r */
            oad(0xC081 | REG_ਮੁੱਲ(r) << 8, fc); /* add tpoffs,r */
            greloc(cur_ਪਾਠ_section, sv->sym, ind - 4, R_386_TLS_LE);
#ਜੇ_ਅੰਤ
#ਜੇ defined CONFIG_TCC_PIC
        } ਨਹੀਂਤਾਂ ਜੇ ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
            ਜੇ (sv->sym->type.t & VT_STATIC) {
                get_pc_thunk(r, 0);
                o(0x808d | REG_ਮੁੱਲ(r) * 0x900); /* lea $xx(r), r */
                gen_addrpc32(fr, sv->sym, fc + 6);
            } ਨਹੀਂਤਾਂ {
                get_pc_thunk(r, 1);
                o(0x808b | REG_ਮੁੱਲ(r) * 0x900); /* mov $xx(r), r */
                gen_gotpcrel(r, sv->sym, fc);
            }
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_CONST) {
            o(0xb8 + r); /* mov $xx, r */
            gen_addr32(fr, sv->sym, fc);
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_LOCAL) {
            ਜੇ (fc) {
                /* lea xxx(%ebp), r */
                gen_modrm(0x8d, r, VT_LOCAL, sv->sym, fc);
            } ਨਹੀਂਤਾਂ {
                o(0x89);
                o(0xe8 + r); /* mov %ebp, r */
            }
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_CMP) {
            o(0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + r);
            o(0xc0b60f + r * 0x90000); /* movzbl %al, %eax */
        } ਨਹੀਂਤਾਂ ਜੇ (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            oad(0xb8 + r, t); /* mov $1, r */
            o(0x05eb); /* jmp after */
            gsym(fc);
            oad(0xb8 + r, t ^ 1); /* mov $0, r */
        } ਨਹੀਂਤਾਂ ਜੇ (v != r) {
            o(0x89);
            o(0xc0 + r + v * 8); /* mov v, r */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ST_FUNC ਖਾਲੀ store(ਪੂਰਨ r, SValue *v)
{
    ਪੂਰਨ fr, bt, fc, opc;

    bt = v->type.t & VT_BTYPE;

    /* XXX: incorrect if float reg to reg */
    ਜੇ (bt == VT_FLOAT) {
        opc = 0xd9; /* fsts */
        r = 2;
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_DOUBLE) {
        opc = 0xdd; /* fstpl */
        r = 2;
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0), fstpt */
        opc = 0xdb;
        r = 7;
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_SHORT) {
        opc = 0x8966;
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } ਨਹੀਂਤਾਂ {
        opc = 0x89;
    }

    fc = v->c.i;
    fr = v->r & VT_VALMASK;

#ਜੇ defined CONFIG_TCC_PIC
    /* we need to access the variable via got */
    ਜੇ ((v->r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
	get_pc_thunk(TREG_EBX, 1);
	o(0x9b8b); /* mov xx(%ebx),%ebx */
	gen_gotpcrel(TREG_EBX, v->sym, v->c.i);
	o(opc);
	o(3 + (r << 3));
    } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ

    ਜੇ (fr == VT_CONST || fr == VT_LOCAL || (v->r & VT_LVAL)) {
        gen_modrm(opc, r, v->r, v->sym, fc);
    } ਨਹੀਂਤਾਂ ਜੇ (fr != r) {
	o(opc);
        o(0xc0 + fr + r * 8); /* mov r, fr */
    }
}

ਸਥਿਰ ਖਾਲੀ gadd_sp(ਪੂਰਨ val)
{
    ਜੇ (val == (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)val) {
        o(0xc483);
        g(val);
    } ਨਹੀਂਤਾਂ {
        oad(0xc481, val); /* add $xxx, %esp */
    }
}

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_PE || defined CONFIG_TCC_PIC
ਸਥਿਰ ਖਾਲੀ gen_static_call(ਪੂਰਨ v)
{
    Sym *sym;

    sym = external_helper_sym(v);
    oad(0xe8, -4);
    greloc(cur_ਪਾਠ_section, sym, ind - 4, R_386_PC32);
}
#ਜੇ_ਅੰਤ

/* 'is_jmp' is '1' if it is a jump */
ਸਥਿਰ ਖਾਲੀ gcall_or_jmp(ਪੂਰਨ is_jmp)
{
    ਪੂਰਨ r;
    ਜੇ ((vtop->r & (VT_VALMASK|VT_LVAL|VT_SYM)) == (VT_CONST|VT_SYM)) {
        /* constant and relocation case */
#ਜੇ defined CONFIG_TCC_PIC
	ਜੇ (!(vtop->sym->type.t & VT_STATIC)) {
	    get_pc_thunk(TREG_EBX, 1);
            oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
            greloc(cur_ਪਾਠ_section, vtop->sym, ind - 4, R_386_PLT32);
            ਵਾਪਸ;
	}
#ਜੇ_ਅੰਤ
        oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
        greloc(cur_ਪਾਠ_section, vtop->sym, ind - 4, R_386_PC32);
    } ਨਹੀਂਤਾਂ {
        /* otherwise, indirect call */
        r = gv(RC_INT);
        o(0xff); /* call/jmp *r */
        o(0xd0 + r + (is_jmp << 4));
    }
}

ਸਥਿਰ ਅਚਲ uint8_t fastcall_regs[3] = { TREG_EAX, TREG_EDX, TREG_ECX };
ਸਥਿਰ ਅਚਲ uint8_t fastcallw_regs[2] = { TREG_ECX, TREG_EDX };

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ਪੂਰਨ gfunc_sret(CType *vt, ਪੂਰਨ variadic, CType *ret, ਪੂਰਨ *ret_align, ਪੂਰਨ *regsize)
{
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    ਪੂਰਨ ਮਾਪ, align, nregs;
    *ret_align = 1; // Never have to re-align return values for x86
    *regsize = 4;
    ਮਾਪ = type_ਮਾਪ(vt, &align);
    ਜੇ (ਮਾਪ > 8 || (ਮਾਪ & (ਮਾਪ - 1)))
        ਵਾਪਸ 0;
    nregs = 1;
    ਜੇ (ਮਾਪ == 8)
        ret->t = VT_INT, nregs = 2;
    ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ == 4)
        ret->t = VT_INT;
    ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ == 2)
        ret->t = VT_SHORT;
    ਨਹੀਂਤਾਂ
        ret->t = VT_BYTE;
    ret->ref = ਨਿਰਾ;
    ਵਾਪਸ nregs;
#ਨਹੀਂਤਾਂ
    *ret_align = 1; // Never have to re-align return values for x86
    ਵਾਪਸ 0;
#ਜੇ_ਅੰਤ
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ST_FUNC ਖਾਲੀ gfunc_call(ਪੂਰਨ nb_ਦਲੀਲਾਂ)
{
    ਪੂਰਨ ਮਾਪ, align, r, ਦਲੀਲਾਂ_ਮਾਪ, i, func_call;
    Sym *func_sym;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gbound_ਦਲੀਲਾਂ(nb_ਦਲੀਲਾਂ);
#ਜੇ_ਅੰਤ

    save_regs(nb_ਦਲੀਲਾਂ + 1);

    ਦਲੀਲਾਂ_ਮਾਪ = 0;
    ਲਈ(i = 0;i < nb_ਦਲੀਲਾਂ; i++) {
        ਜੇ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
            ਮਾਪ = type_ਮਾਪ(&vtop->type, &align);
            /* align to stack align size */
            ਮਾਪ = (ਮਾਪ + 3) & ~3;
            /* allocate the necessary size on stack */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            ਜੇ (ਮਾਪ >= 4096) {
                save_reg(TREG_EDX);
                r = get_reg(RC_EAX);
                oad(0x68, ਮਾਪ); // push size
                /* cannot call normal 'alloca' with bound checking */
                gen_static_call(tok_alloc_const("__alloca"));
                gadd_sp(4);
            } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
            {
                oad(0xec81, ਮਾਪ); /* sub $xxx, %esp */
                /* generate structure store */
                r = get_reg(RC_INT);
                o(0xe089 + (r << 8)); /* mov %esp, r */
            }
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            ਦਲੀਲਾਂ_ਮਾਪ += ਮਾਪ;
        } ਨਹੀਂਤਾਂ ਜੇ (is_float(vtop->type.t)) {
            gv(RC_FLOAT); /* only one float register */
            ਜੇ ((vtop->type.t & VT_BTYPE) == VT_FLOAT)
                ਮਾਪ = 4;
            ਨਹੀਂਤਾਂ ਜੇ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                ਮਾਪ = 8;
            ਨਹੀਂਤਾਂ
                ਮਾਪ = 12;
            oad(0xec81, ਮਾਪ); /* sub $xxx, %esp */
            ਜੇ (ਮਾਪ == 12)
                o(0x7cdb);
            ਨਹੀਂਤਾਂ
                o(0x5cd9 + ਮਾਪ - 4); /* fstp[s|l] 0(%esp) */
            g(0x24);
            g(0x00);
            ਦਲੀਲਾਂ_ਮਾਪ += ਮਾਪ;
        } ਨਹੀਂਤਾਂ {
            /* simple type (currently always same size) */
            /* XXX: implicit cast ? */
            r = gv(RC_INT);
            ਜੇ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
                ਮਾਪ = 8;
                o(0x50 + vtop->r2); /* push r */
            } ਨਹੀਂਤਾਂ {
                ਮਾਪ = 4;
            }
            o(0x50 + r); /* push r */
            ਦਲੀਲਾਂ_ਮਾਪ += ਮਾਪ;
        }
        vtop--;
    }

    func_sym = vtop->type.ref;
    func_call = func_sym->f.func_call;
    /* fast call case */
    ਜੇ ((func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) ||
        func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL) {
        ਪੂਰਨ fastcall_nb_regs;
        ਅਚਲ uint8_t *fastcall_regs_ptr;
        ਜੇ (func_call == FUNC_FASTCALLW) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 2;
        } ਨਹੀਂਤਾਂ ਜੇ (func_call == FUNC_THISCALL) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 1;
        } ਨਹੀਂਤਾਂ {
            fastcall_regs_ptr = fastcall_regs;
            fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        }
        ਲਈ(i = 0;i < fastcall_nb_regs; i++) {
            ਜੇ (ਦਲੀਲਾਂ_ਮਾਪ <= 0)
                ਰੋਕੋ;
            o(0x58 + fastcall_regs_ptr[i]); /* pop r */
            /* XXX: incorrect for struct/floats */
            ਦਲੀਲਾਂ_ਮਾਪ -= 4;
        }
    }
#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    ਨਹੀਂਤਾਂ ਜੇ ((vtop->type.ref->type.t & VT_BTYPE) == VT_STRUCT)
        ਦਲੀਲਾਂ_ਮਾਪ -= 4;
#ਜੇ_ਅੰਤ

    gcall_or_jmp(0);

    ਜੇ (ਦਲੀਲਾਂ_ਮਾਪ && func_call != FUNC_STDCALL && func_call != FUNC_THISCALL && func_call != FUNC_FASTCALLW)
        gadd_sp(ਦਲੀਲਾਂ_ਮਾਪ);
    vtop--;
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_PROLOG_ਮਾਪ (10 + !!USE_EBX)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_PROLOG_ਮਾਪ (9 + !!USE_EBX)
#ਜੇ_ਅੰਤ

/* generate function prolog of type 't' */
ST_FUNC ਖਾਲੀ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ਪੂਰਨ addr, align, ਮਾਪ, func_call, fastcall_nb_regs;
    ਪੂਰਨ param_ਸੂਚਕਾਂਕ, param_addr;
    ਅਚਲ uint8_t *fastcall_regs_ptr;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    func_call = sym->f.func_call;
    addr = 8;
    loc = 0;
    func_vc = 0;

    ਜੇ (func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) {
        fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        fastcall_regs_ptr = fastcall_regs;
    } ਨਹੀਂਤਾਂ ਜੇ (func_call == FUNC_FASTCALLW) {
        fastcall_nb_regs = 2;
        fastcall_regs_ptr = fastcallw_regs;
    } ਨਹੀਂਤਾਂ ਜੇ (func_call == FUNC_THISCALL) {
        fastcall_nb_regs = 1;
        fastcall_regs_ptr = fastcallw_regs;
    } ਨਹੀਂਤਾਂ {
        fastcall_nb_regs = 0;
        fastcall_regs_ptr = ਨਿਰਾ;
    }
    param_ਸੂਚਕਾਂਕ = 0;

    ind += FUNC_PROLOG_ਮਾਪ;
    func_sub_sp_ਵਿੱਥ = ind;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    ਮਾਪ = type_ਮਾਪ(&func_vt,&align);
    ਜੇ (((func_vt.t & VT_BTYPE) == VT_STRUCT)
        && (ਮਾਪ > 8 || (ਮਾਪ & (ਮਾਪ - 1)))) {
#ਨਹੀਂਤਾਂ
    ਜੇ ((func_vt.t & VT_BTYPE) == VT_STRUCT) {
#ਜੇ_ਅੰਤ
        /* XXX: fastcall case ? */
        func_vc = addr;
        addr += 4;
        param_ਸੂਚਕਾਂਕ++;
    }
    /* define parameters */
    ਜਦੋਂ ((sym = sym->ਅਗਲਾ) != ਨਿਰਾ) {
        type = &sym->type;
        ਮਾਪ = type_ਮਾਪ(type, &align);
        ਮਾਪ = (ਮਾਪ + 3) & ~3;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ FUNC_STRUCT_PARAM_AS_PTR
        /* structs are passed as pointer */
        ਜੇ ((type->t & VT_BTYPE) == VT_STRUCT) {
            ਮਾਪ = 4;
        }
#ਜੇ_ਅੰਤ
        ਜੇ (param_ਸੂਚਕਾਂਕ < fastcall_nb_regs) {
            /* save FASTCALL register */
            loc -= 4;
            /* movl */
            gen_modrm(0x89, fastcall_regs_ptr[param_ਸੂਚਕਾਂਕ], VT_LOCAL, ਨਿਰਾ, loc);
            param_addr = loc;
        } ਨਹੀਂਤਾਂ {
            param_addr = addr;
            addr += ਮਾਪ;
        }
        gfunc_ਸੈੱਟ_param(sym, param_addr, 0);
        param_ਸੂਚਕਾਂਕ++;
    }
    func_ret_sub = 0;
    /* pascal type call or fastcall ? */
    ਜੇ (func_call == FUNC_STDCALL || func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL)
        func_ret_sub = addr - 8;
#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    ਨਹੀਂਤਾਂ ਜੇ (func_vc)
        func_ret_sub = 4;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#ਜੇ_ਅੰਤ
}

/* generate function epilog */
ST_FUNC ਖਾਲੀ gfunc_epilog(ਖਾਲੀ)
{
    addr_t v, saved_ind;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#ਜੇ_ਅੰਤ

    /* align local size to word & save local variables */
    v = (-loc + 3) & -4;

#ਜੇ USE_EBX
    gen_modrm(0x8b, TREG_EBX, VT_LOCAL, ਨਿਰਾ, -(v+4));
#ਜੇ_ਅੰਤ

    o(0xc9); /* leave */
    ਜੇ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ਨਹੀਂਤਾਂ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    saved_ind = ind;
    ind = func_sub_sp_ਵਿੱਥ - FUNC_PROLOG_ਮਾਪ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਜੇ (v >= 4096) {
        oad(0xb8, v); /* mov stacksize, %eax */
        gen_static_call(TOK___chkstk); /* call __chkstk, (does the stackframe too) */
    } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
    {
        o(0xe58955);  /* push %ebp, mov %esp, %ebp */
        o(0xec81);  /* sub esp, stacksize */
        gen_le32(v);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        o(0x90);  /* adjust to FUNC_PROLOG_SIZE */
#ਜੇ_ਅੰਤ
    }
#ਜੇ USE_EBX
    o(0x53); /* push ebx */
#ਜੇ_ਅੰਤ
    ind = saved_ind;
}

/* generate a jump to a label */
ST_FUNC ਪੂਰਨ gjmp(ਪੂਰਨ t)
{
    ਵਾਪਸ gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ST_FUNC ਖਾਲੀ gjmp_addr(ਪੂਰਨ a)
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

#ਜੇ 0
/* generate a jump to a fixed address */
ST_FUNC ਖਾਲੀ gjmp_cond_addr(ਪੂਰਨ a, ਪੂਰਨ op)
{
    ਪੂਰਨ r = a - ind - 2;
    ਜੇ (r == (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)r)
        g(op - 32), g(r);
    ਨਹੀਂਤਾਂ
        g(0x0f), gjmp2(op - 16, r - 4);
}
#ਜੇ_ਅੰਤ

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
    g(0x0f);
    t = gjmp2(op - 16, t);
    ਵਾਪਸ t;
}

ST_FUNC ਖਾਲੀ gen_opi(ਪੂਰਨ op)
{
    ਪੂਰਨ r, fr, opc, c;

    ਚੋਣ(op) {
    ਹਾਲਤ '+':
    ਹਾਲਤ TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            ਜੇ (c == (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)c) {
                /* generate inc and dec for smaller code */
                ਜੇ ((c == 1 || c == -1) && (op == '+' || op == '-')) {
                    opc = (c == 1) ^ (op == '+');
                    o (0x40 | (opc << 3) | r); // inc,dec
                } ਨਹੀਂਤਾਂ {
                    o(0x83);
                    o(0xc0 | (opc << 3) | r);
                    g(c);
                }
            } ਨਹੀਂਤਾਂ {
                o(0x81);
                oad(0xc0 | (opc << 3) | r, c);
            }
        } ਨਹੀਂਤਾਂ {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            o((opc << 3) | 0x01);
            o(0xc0 + r + fr * 8); 
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
        vtop--;
        o(0xaf0f); /* imul fr, r */
        o(0xc0 + fr + r * 8);
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
        ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i & 0x1f;
            o(0xc1); /* shl/shr/sar $xxx, r */
            o(opc | r);
            g(c);
        } ਨਹੀਂਤਾਂ {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_ECX);
            r = vtop[-1].r;
            o(0xd3); /* shl/shr/sar %cl, r */
            o(opc | r);
        }
        vtop--;
        ਰੋਕੋ;
    ਹਾਲਤ '/':
    ਹਾਲਤ TOK_UDIV:
    ਹਾਲਤ TOK_PDIV:
    ਹਾਲਤ '%':
    ਹਾਲਤ TOK_UMOD:
    ਹਾਲਤ TOK_UMULL:
        /* first operand must be in eax */
        /* XXX: need better constraint for second operand */
        gv2(RC_EAX, RC_ECX);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        save_reg(TREG_EDX);
        /* save EAX too if used otherwise */
        save_reg_upstack(TREG_EAX, 1);
        ਜੇ (op == TOK_UMULL) {
            o(0xf7); /* mul fr */
            o(0xe0 + fr);
            vtop->r2 = TREG_EDX;
            r = TREG_EAX;
        } ਨਹੀਂਤਾਂ {
            ਜੇ (op == TOK_UDIV || op == TOK_UMOD) {
                o(0xf7d231); /* xor %edx, %edx, div fr, %eax */
                o(0xf0 + fr);
            } ਨਹੀਂਤਾਂ {
                o(0xf799); /* cltd, idiv fr, %eax */
                o(0xf8 + fr);
            }
            ਜੇ (op == '%' || op == TOK_UMOD)
                r = TREG_EDX;
            ਨਹੀਂਤਾਂ
                r = TREG_EAX;
        }
        vtop->r = r;
        ਰੋਕੋ;
    ਮੂਲ:
        opc = 7;
        ਜਾਓ gen_op8;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ST_FUNC ਖਾਲੀ gen_opf(ਪੂਰਨ op)
{
    ਪੂਰਨ a, ft, fc, swapped, r;

    ਜੇ (op == TOK_NEG) { /* unary minus */
        gv(RC_FLOAT);
        o(0xe0d9); /* fchs */
        ਵਾਪਸ;
    }

    /* convert constants to memory references */
    ਜੇ ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    ਜੇ ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(RC_FLOAT);

    /* must put at least one value in the floating point register */
    ਜੇ ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    ਜੇ (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    ਜੇ (op >= TOK_ULT && op <= TOK_GT) {
        /* load on stack second operand */
        ਲੱਦੋ(TREG_ST0, vtop);
        save_reg(TREG_EAX); /* eax is used by FP comparison code */
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
        ਜੇ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
            ਲੱਦੋ(TREG_ST0, vtop);
            swapped = !swapped;
        }
        
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
        ਜੇ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
        } ਨਹੀਂਤਾਂ {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            ਜੇ ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_INT;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = ਨਿਰਾ;
                ਲੱਦੋ(r, &v1);
                fc = 0;
            }

            gen_modrm((ft & VT_BTYPE) == VT_DOUBLE ? 0xdc : 0xd8,
		      a, r, vtop->sym, fc);
        }
        vtop--;
    }
}

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ST_FUNC ਖਾਲੀ gen_cvt_itof(ਪੂਰਨ t)
{
    save_reg(TREG_ST0);
    gv(RC_INT);
    ਜੇ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
        /* signed long long to float/double/long double (unsigned case
           is handled generically) */
        o(0x50 + vtop->r2); /* push r2 */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
        vtop->r2 = VT_CONST;
    } ਨਹੀਂਤਾਂ ਜੇ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
               (VT_INT | VT_UNSIGNED)) {
        /* unsigned int to float/double/long double */
        o(0x6a); /* push $0 */
        g(0x00);
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
    } ਨਹੀਂਤਾਂ {
        /* int to float/double/long double */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x2404db); /* fildl (%esp) */
        o(0x04c483); /* add $4, %esp */
    }
    vtop->r2 = VT_CONST;
    vtop->r = TREG_ST0;
}

/* convert fp to int 't' type */
ST_FUNC ਖਾਲੀ gen_cvt_ftoi(ਪੂਰਨ t)
{
    ਪੂਰਨ bt = vtop->type.t & VT_BTYPE;
    ਜੇ (bt == VT_FLOAT)
        vpush_helper_func(TOK___fixsfdi);
    ਨਹੀਂਤਾਂ ਜੇ (bt == VT_LDOUBLE)
        vpush_helper_func(TOK___fixxfdi);
    ਨਹੀਂਤਾਂ
        vpush_helper_func(TOK___fixdfdi);
    vswap();
    gfunc_call(1);
    vpushi(0);
    vtop->r = REG_IRET;
    ਜੇ ((t & VT_BTYPE) == VT_LLONG)
        vtop->r2 = REG_IRE2;
}

/* convert from one floating point type to another */
ST_FUNC ਖਾਲੀ gen_cvt_ftof(ਪੂਰਨ t)
{
    /* all we have to do on i386 is to put the float in a register */
    gv(RC_FLOAT);
}

/* char/short to int conversion */
ST_FUNC ਖਾਲੀ gen_cvt_csti(ਪੂਰਨ t)
{
    ਪੂਰਨ r, sz, xl;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    o(0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (r << 3 | r) << 16
        );
}

/* increment tcov counter */
ST_FUNC ਖਾਲੀ gen_increment_tcov (SValue *sv)
{
   ਪੂਰਨ indir, rel, add1, add2;
#ਜੇ defined CONFIG_TCC_PIC
   get_pc_thunk(TREG_EBX, 0);
   indir = 0x8300;
   rel = R_386_PC32;
   add1 = 2;
   add2 = 13;
#ਨਹੀਂਤਾਂ
   indir = 0x0500;
   rel = R_386_32;
   add1 = 0;
   add2 = 4;
#ਜੇ_ਅੰਤ
   o(0x0083 + indir); /* addl $1, xxx(%ebx) */
   greloc(cur_ਪਾਠ_section, sv->sym, ind, rel);
   gen_le32(add1);
   o(1);
   o(0x1083 + indir); /* adcl $0, xxx(%ebx) */
   greloc(cur_ਪਾਠ_section, sv->sym, ind, rel);
   gen_le32(add2);
   g(0);
}

/* computed goto support */
ST_FUNC ਖਾਲੀ ggoto(ਖਾਲੀ)
{
    gcall_or_jmp(1);
    vtop--;
}

/* bound check support functions */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK

/* Need PIC for shared libraries */
ਸਥਿਰ ਖਾਲੀ gen_bound_call(ਪੂਰਨ v)
{
    Sym *sym;

    sym = external_helper_sym(v);
#ਜੇ defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EBX, 1);
    oad(0xe8, -4);
    greloc(cur_ਪਾਠ_section, sym, ind - 4, R_386_PLT32);
#ਨਹੀਂਤਾਂ
    oad(0xe8, -4);
    greloc(cur_ਪਾਠ_section, sym, ind - 4, R_386_PC32);
#ਜੇ_ਅੰਤ
}

ਸਥਿਰ ਖਾਲੀ gen_bounds_prolog(ਖਾਲੀ)
{
    /* leave some room for bound checking code */
    func_bound_ਵਿੱਥ = lbounds_section->ਅੰਕੜੇ_ਵਿੱਥ;
    func_bound_ind = ind;
    func_bound_ਜੋੜੋ_epilog = 0;
#ਜੇ defined CONFIG_TCC_PIC
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0x808d, 0); /* lea lbound section pointer */
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0xc381, 0); /* add _GLOBAL_OFFSET_TABLE_ */
    oad(0xb8, 0); /* call to function */
#ਨਹੀਂਤਾਂ
    oad(0xb8, 0); /* lbound section pointer */
    oad(0xb8, 0); /* call to function */
#ਜੇ_ਅੰਤ
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
#ਜੇ defined CONFIG_TCC_PIC
	get_pc_thunk(TREG_EAX, 0);
	o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
	greloc(cur_ਪਾਠ_section, sym_ਅੰਕੜੇ, ind, R_386_PC32);
	gen_le32(2);
#ਨਹੀਂਤਾਂ
        greloc(cur_ਪਾਠ_section, sym_ਅੰਕੜੇ, ind + 1, R_386_32);
        ind = ind + 5;
#ਜੇ_ਅੰਤ
        gen_bound_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0x5250); /* save returned value, if any */
#ਜੇ defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EAX, 0);
    o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
    greloc(cur_ਪਾਠ_section, sym_ਅੰਕੜੇ, ind, R_386_PC32);
    gen_le32(2);
#ਨਹੀਂਤਾਂ
    greloc(cur_ਪਾਠ_section, sym_ਅੰਕੜੇ, ind + 1, R_386_32);
    oad(0xb8, 0); /* mov %eax, xxx */
#ਜੇ_ਅੰਤ
    gen_bound_call(TOK___bound_local_delete);
    o(0x585a); /* restore returned value, if any */
}
#ਜੇ_ਅੰਤ

/* Save the stack pointer onto the stack */
ST_FUNC ਖਾਲੀ gen_vla_sp_save(ਪੂਰਨ addr) {
    /* mov %esp,addr(%ebp)*/
    gen_modrm(0x89, TREG_ESP, VT_LOCAL, ਨਿਰਾ, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC ਖਾਲੀ gen_vla_sp_restore(ਪੂਰਨ addr) {
    gen_modrm(0x8b, TREG_ESP, VT_LOCAL, ਨਿਰਾ, addr);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC ਖਾਲੀ gen_vla_alloc(CType *type, ਪੂਰਨ align) {
    ਪੂਰਨ use_call = 0;

#ਜੇ defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE    /* alloca does more than just adjust %rsp on Windows */
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
        o(0x2b);
        o(0xe0 | r);
        /* We align to 16 bytes rather than align */
        /* and ~15, %esp */
        o(0xf0e483);
        vpop();
    }
}

/* end of X86 code generator */
/*************************************************************/
#ਜੇ_ਅੰਤ
/*************************************************************/
