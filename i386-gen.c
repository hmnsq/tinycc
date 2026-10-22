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

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

/* number of available registers */
#ವ್ಯಾಖ್ಯಾನಿಸು NB_REGS         5
#ವ್ಯಾಖ್ಯಾನಿಸು NB_ASM_REGS     8
#ವ್ಯಾಖ್ಯಾನಿಸು CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_INT     0x0001 /* generic integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FLOAT   0x0002 /* generic float register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_EAX     0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು RC_EDX     0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು RC_ECX     0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು RC_EBX     0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು RC_ST0     0x0040

#ವ್ಯಾಖ್ಯಾನಿಸು RC_IRET    RC_EAX /* function return: integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_IRE2    RC_EDX /* function return: second integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
ಎಣಿಕೆ {
    TREG_EAX = 0,
    TREG_ECX,
    TREG_EDX,
    TREG_EBX,
    TREG_ST0,
    TREG_ESP = 4,
    TREG_MEM = 0x20
};

#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಮೌಲ್ಯ(reg) ((reg) & 7)

/* return registers for function */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_IRET TREG_EAX /* single word int return register */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_IRE2 TREG_EDX /* second word return register (for long long) */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_FRET TREG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
#ವ್ಯಾಖ್ಯಾನಿಸು INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#ವ್ಯಾಖ್ಯಾನಿಸು PTR_ಗಾತ್ರ 4

/* long double size and alignment, in bytes */
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ಗಾತ್ರ  12
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ALIGN 4
/* maximum alignment (for aligned attribute support) */
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_ALIGN     8

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#ವ್ಯಾಖ್ಯಾನಿಸು PROMOTE_RET

/******************************************************/
#ಇಲ್ಲದಿದ್ದರೆ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ ಗುರಿ_machine_defs =
    "__i386__\0"
    "__i386\0"
    ;

#ಆದರೆ defined CONFIG_TCC_PIC
# define USE_EBX 2
#ಇಲ್ಲದಿದ್ದರೆ
# define USE_EBX 0 /* define to 1 to have EBX as 4th register */
#ಆದರೆ_ಅಂತ್ಯ

ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ reg_classes[NB_REGS] = {
    /* eax */ RC_INT | RC_EAX,
    /* ecx */ RC_INT | RC_ECX,
    /* edx */ RC_INT | RC_EDX,
    /* ebx */ (RC_INT | RC_EBX) * (USE_EBX == 1),
    /* st0 */ RC_FLOAT | RC_ST0,
};

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ func_sub_sp_ಸ್ಥಾನಾಂತರ;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ func_ret_sub;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
ಸ್ಥಿರ addr_t func_bound_ಸ್ಥಾನಾಂತರ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ func_bound_ind;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_bound_ಕೂಡಿಸು_epilog;
ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_prolog(ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_epilog(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ

/* XXX: make it faster ? */
ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಂಕ c)
{
    ಪೂರ್ಣಾಂಕ ind1;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    ind1 = ind + 1;
    ಆದರೆ (ind1 > cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_allocated)
        section_realloc(cur_ಪಠ್ಯ_section, ind1);
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind] = c;
    ind = ind1;
}

ST_FUNC ಶೂನ್ಯ o(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ c)
{
    ಆಗ (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಂಕ v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಂಕ c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

/* output a symbol and patch all calls to it */
ST_FUNC ಶೂನ್ಯ gsym_addr(ಪೂರ್ಣಾಂಕ t, ಪೂರ್ಣಾಂಕ a)
{
    ಆಗ (t) {
        ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr = cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a - t - 4);
        t = n;
    }
}

/* instruction + 4 bytes data. Return the address of the data */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ oad(ಪೂರ್ಣಾಂಕ c, ಪೂರ್ಣಾಂಕ s)
{
    ಪೂರ್ಣಾಂಕ t;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ s;
    o(c);
    t = ind;
    gen_le32(s);
    ಹಿಂತಿರುಗಿ t;
}

ST_FUNC ಶೂನ್ಯ gen_fill_nops(ಪೂರ್ಣಾಂಕ ಬೈಟುಗಳು)
{
    ಆಗ (ಬೈಟುಗಳು--)
      g(0x90);
}

#ಆದರೆ defined CONFIG_TCC_PIC
ಸ್ಥಿರ ಶೂನ್ಯ gen_static_call(ಪೂರ್ಣಾಂಕ v);
ಸ್ಥಿರ ಶೂನ್ಯ get_pc_thunk(ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ ಕೂಡಿಸು)
{
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ pc_thunk_name[] = {
	"__x86.get_pc_thunk.ax",
	"__x86.get_pc_thunk.cx",
	"__x86.get_pc_thunk.dx",
	"__x86.get_pc_thunk.bx"
    };
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    gen_static_call(tok_alloc_const(pc_thunk_name[r]));
    ಆದರೆ (ಕೂಡಿಸು) {
        Sym label = {0};
        label.type.t = VT_VOID|VT_STATIC;
        put_extern_sym(&label, cur_ಪಠ್ಯ_section, ind, 0);
        r = REG_ಮೌಲ್ಯ(r);
	ಆದರೆ (r == 0)
	    oad(0x05, 1); /* add _GLOBAL_OFFSET_TABLE_, %eax */
	ಇಲ್ಲದಿದ್ದರೆ
            oad(0xc081 + r * 0x100, 2); /* add _GLOBAL_OFFSET_TABLE_, %erx */
        greloc(cur_ಪಠ್ಯ_section, &label, ind - 4, R_386_GOTPC);
    }
}

ST_FUNC ಶೂನ್ಯ gen_gotpcrel(ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c)
{
    greloc(cur_ಪಠ್ಯ_section, sym, ind, R_386_GOT32X);
    gen_le32(0);
    ಆದರೆ (c) {
	r = REG_ಮೌಲ್ಯ(r);
	ಆದರೆ (r == 0)
            oad(0x05, c);
	ಇಲ್ಲದಿದ್ದರೆ
            oad(0xc081 + r * 0x100, c);
    }
}
#ಆದರೆ_ಅಂತ್ಯ

/* generate jmp to a label */
#ವ್ಯಾಖ್ಯಾನಿಸು gjmp2(instr,lbl) oad(instr,lbl)

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ಶೂನ್ಯ gen_addr32(ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c)
{
    ಆದರೆ (r & VT_SYM)
        greloc(cur_ಪಠ್ಯ_section, sym, ind, R_386_32);
    gen_le32(c);
}

ST_FUNC ಶೂನ್ಯ gen_addrpc32(ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c)
{
    ಆದರೆ (r & VT_SYM)
        greloc(cur_ಪಠ್ಯ_section, sym, ind, R_386_PC32);
    gen_le32(c - 4);
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode bits */
ಸ್ಥಿರ ಶೂನ್ಯ gen_modrm(ಪೂರ್ಣಾಂಕ opc, ಪೂರ್ಣಾಂಕ op_r2, ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c)
{
    ಪೂರ್ಣಾಂಕ op_reg = REG_ಮೌಲ್ಯ(op_r2) << 3;

    ಆದರೆ ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        Sym *s2 = external_global_sym(TOK_tls_ಸೂಚ್ಯಂಕ, &int_type);
        r = get_reg(RC_INT);
        gen_modrm(0x8b, r, VT_SYM|VT_CONST, s2, 0); /* mov __tls_index, r */
        o(0x02e0c1 | r << 8); /* shl 2,r */
        oad(0x050364 | r << 19, 11*PTR_ಗಾತ್ರ); /* add fs:0x2c,r */
        gen_modrm(0x8b, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        o(opc), oad(0x80 | op_reg | r, c); /* mov #c(r),op_reg */
        greloc(cur_ಪಠ್ಯ_section, sym, ind - 4, R_386_TLS_LE);
#ಇಲ್ಲದಿದ್ದರೆ
        o(0x65); /* gs segment prefix */
        o(opc), oad(0x05 | op_reg, c);
        greloc(cur_ಪಠ್ಯ_section, sym, ind - 4, R_386_TLS_LE);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined CONFIG_TCC_PIC
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
        ಪೂರ್ಣಾಂಕ is_got = (op_r2 & TREG_MEM) && !(sym->type.t & VT_STATIC);
        ಪೂರ್ಣಾಂಕ ಇಲ್ಲಿ = ind;
        get_pc_thunk(TREG_EBX, is_got);
        o(opc);
        o(0x83 | op_reg);
        ಆದರೆ (is_got) {
            gen_gotpcrel(r, sym, c);
        } ಇಲ್ಲದಿದ್ದರೆ {
            gen_addrpc32(r, sym, c + (ind - ಇಲ್ಲಿ - 1));
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((r & VT_VALMASK) < VT_CONST && (r & TREG_MEM)) {
        o(opc);
        ಆದರೆ (c) {
            g(0x80 | op_reg | REG_ಮೌಲ್ಯ(r));
            gen_le32(c);
        } ಇಲ್ಲದಿದ್ದರೆ {
            g(0x00 | op_reg | REG_ಮೌಲ್ಯ(r));
        }
#ಆದರೆ_ಅಂತ್ಯ
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
        o(opc);
        o(0x05 | op_reg);
        gen_addr32(r, sym, c);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((r & VT_VALMASK) == VT_LOCAL) {
	o(opc);
        /* currently, we use only ebp as base */
        ಆದರೆ (c == (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } ಇಲ್ಲದಿದ್ದರೆ {
            oad(0x85 | op_reg, c);
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
	o(opc);
        g(0x00 | op_reg | (r & VT_VALMASK));
    }
}

/* load 'r' from value 'sv' */
ST_FUNC ಶೂನ್ಯ ತುಂಬು(ಪೂರ್ಣಾಂಕ r, SValue *sv)
{
    ಪೂರ್ಣಾಂಕ v, t, ft, fc, fr, opc;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~VT_DEFSIGN;
    fc = sv->c.i;
    ft &= ~VT_QUAL;
    v = fr & VT_VALMASK;

#ಆದರೆ defined CONFIG_TCC_PIC
    /* we use indirect access via got */
    ಆದರೆ ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        ಪೂರ್ಣಾಂಕ tr = r | TREG_MEM;
        ಆದರೆ (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm(0x8b, tr, fr, sv->sym, 0);
        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#ಆದರೆ_ಅಂತ್ಯ

    ಆದರೆ (fr & VT_LVAL) {
        ಆದರೆ (v == VT_LLOCAL) {
            v1.type.t = VT_INT;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
            v1.sym = ಖಾಲಿ;
            fr = r;
            ಆದರೆ (!(reg_classes[fr] & RC_INT))
                fr = get_reg(RC_INT);
            ತುಂಬು(fr, &v1);
        }
        ಆದರೆ ((ft & VT_BTYPE) == VT_FLOAT) {
            opc = 0xd9; /* flds */
            r = 0;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_DOUBLE) {
            opc = 0xdd; /* fldl */
            r = 0;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            opc = 0xdb; /* fldt */
            r = 5;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            opc = 0xbe0f;   /* movsbl */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED) ||
		   (ft & VT_TYPE) == (VT_BOOL | VT_UNSIGNED)) {
            opc = 0xb60f;   /* movzbl */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == VT_SHORT) {
            opc = 0xbf0f;   /* movswl */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            opc = 0xb70f;   /* movzwl */
        } ಇಲ್ಲದಿದ್ದರೆ {
            opc = 0x8b;     /* movl */
        }
        gen_modrm(opc, r, fr, sv->sym, fc);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ ((fr & VT_SYM) && (sv->sym->type.t & VT_TLS)) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            gen_modrm(0x8d, r, fr, sv->sym, fc);
#ಇಲ್ಲದಿದ್ದರೆ
            oad(0x058b65 | REG_ಮೌಲ್ಯ(r) << 19, 0); /* mov gs:0,r */
            oad(0xC081 | REG_ಮೌಲ್ಯ(r) << 8, fc); /* add tpoffs,r */
            greloc(cur_ಪಠ್ಯ_section, sv->sym, ind - 4, R_386_TLS_LE);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined CONFIG_TCC_PIC
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
            ಆದರೆ (sv->sym->type.t & VT_STATIC) {
                get_pc_thunk(r, 0);
                o(0x808d | REG_ಮೌಲ್ಯ(r) * 0x900); /* lea $xx(r), r */
                gen_addrpc32(fr, sv->sym, fc + 6);
            } ಇಲ್ಲದಿದ್ದರೆ {
                get_pc_thunk(r, 1);
                o(0x808b | REG_ಮೌಲ್ಯ(r) * 0x900); /* mov $xx(r), r */
                gen_gotpcrel(r, sv->sym, fc);
            }
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_CONST) {
            o(0xb8 + r); /* mov $xx, r */
            gen_addr32(fr, sv->sym, fc);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_LOCAL) {
            ಆದರೆ (fc) {
                /* lea xxx(%ebp), r */
                gen_modrm(0x8d, r, VT_LOCAL, sv->sym, fc);
            } ಇಲ್ಲದಿದ್ದರೆ {
                o(0x89);
                o(0xe8 + r); /* mov %ebp, r */
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_CMP) {
            o(0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + r);
            o(0xc0b60f + r * 0x90000); /* movzbl %al, %eax */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            oad(0xb8 + r, t); /* mov $1, r */
            o(0x05eb); /* jmp after */
            gsym(fc);
            oad(0xb8 + r, t ^ 1); /* mov $0, r */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v != r) {
            o(0x89);
            o(0xc0 + r + v * 8); /* mov v, r */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ST_FUNC ಶೂನ್ಯ store(ಪೂರ್ಣಾಂಕ r, SValue *v)
{
    ಪೂರ್ಣಾಂಕ fr, bt, fc, opc;

    bt = v->type.t & VT_BTYPE;

    /* XXX: incorrect if float reg to reg */
    ಆದರೆ (bt == VT_FLOAT) {
        opc = 0xd9; /* fsts */
        r = 2;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_DOUBLE) {
        opc = 0xdd; /* fstpl */
        r = 2;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0), fstpt */
        opc = 0xdb;
        r = 7;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_SHORT) {
        opc = 0x8966;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } ಇಲ್ಲದಿದ್ದರೆ {
        opc = 0x89;
    }

    fc = v->c.i;
    fr = v->r & VT_VALMASK;

#ಆದರೆ defined CONFIG_TCC_PIC
    /* we need to access the variable via got */
    ಆದರೆ ((v->r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
	get_pc_thunk(TREG_EBX, 1);
	o(0x9b8b); /* mov xx(%ebx),%ebx */
	gen_gotpcrel(TREG_EBX, v->sym, v->c.i);
	o(opc);
	o(3 + (r << 3));
    } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ

    ಆದರೆ (fr == VT_CONST || fr == VT_LOCAL || (v->r & VT_LVAL)) {
        gen_modrm(opc, r, v->r, v->sym, fc);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (fr != r) {
	o(opc);
        o(0xc0 + fr + r * 8); /* mov r, fr */
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ gadd_sp(ಪೂರ್ಣಾಂಕ val)
{
    ಆದರೆ (val == (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)val) {
        o(0xc483);
        g(val);
    } ಇಲ್ಲದಿದ್ದರೆ {
        oad(0xc481, val); /* add $xxx, %esp */
    }
}

#ಆದರೆ defined TCC_ಗುರಿ_PE || defined CONFIG_TCC_PIC
ಸ್ಥಿರ ಶೂನ್ಯ gen_static_call(ಪೂರ್ಣಾಂಕ v)
{
    Sym *sym;

    sym = external_helper_sym(v);
    oad(0xe8, -4);
    greloc(cur_ಪಠ್ಯ_section, sym, ind - 4, R_386_PC32);
}
#ಆದರೆ_ಅಂತ್ಯ

/* 'is_jmp' is '1' if it is a jump */
ಸ್ಥಿರ ಶೂನ್ಯ gcall_or_jmp(ಪೂರ್ಣಾಂಕ is_jmp)
{
    ಪೂರ್ಣಾಂಕ r;
    ಆದರೆ ((vtop->r & (VT_VALMASK|VT_LVAL|VT_SYM)) == (VT_CONST|VT_SYM)) {
        /* constant and relocation case */
#ಆದರೆ defined CONFIG_TCC_PIC
	ಆದರೆ (!(vtop->sym->type.t & VT_STATIC)) {
	    get_pc_thunk(TREG_EBX, 1);
            oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
            greloc(cur_ಪಠ್ಯ_section, vtop->sym, ind - 4, R_386_PLT32);
            ಹಿಂತಿರುಗಿ;
	}
#ಆದರೆ_ಅಂತ್ಯ
        oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
        greloc(cur_ಪಠ್ಯ_section, vtop->sym, ind - 4, R_386_PC32);
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* otherwise, indirect call */
        r = gv(RC_INT);
        o(0xff); /* call/jmp *r */
        o(0xd0 + r + (is_jmp << 4));
    }
}

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t fastcall_regs[3] = { TREG_EAX, TREG_EDX, TREG_ECX };
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ uint8_t fastcallw_regs[2] = { TREG_ECX, TREG_EDX };

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ಪೂರ್ಣಾಂಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಂಕ variadic, CType *ret, ಪೂರ್ಣಾಂಕ *ret_align, ಪೂರ್ಣಾಂಕ *regsize)
{
#ಆದರೆ defined(TCC_ಗುರಿ_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, nregs;
    *ret_align = 1; // Never have to re-align return values for x86
    *regsize = 4;
    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(vt, &align);
    ಆದರೆ (ಗಾತ್ರ_2 > 8 || (ಗಾತ್ರ_2 & (ಗಾತ್ರ_2 - 1)))
        ಹಿಂತಿರುಗಿ 0;
    nregs = 1;
    ಆದರೆ (ಗಾತ್ರ_2 == 8)
        ret->t = VT_INT, nregs = 2;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2 == 4)
        ret->t = VT_INT;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2 == 2)
        ret->t = VT_SHORT;
    ಇಲ್ಲದಿದ್ದರೆ
        ret->t = VT_BYTE;
    ret->ref = ಖಾಲಿ;
    ಹಿಂತಿರುಗಿ nregs;
#ಇಲ್ಲದಿದ್ದರೆ
    *ret_align = 1; // Never have to re-align return values for x86
    ಹಿಂತಿರುಗಿ 0;
#ಆದರೆ_ಅಂತ್ಯ
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ST_FUNC ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, r, ವಾದಗಳು_ಗಾತ್ರ, i, func_call;
    Sym *func_sym;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gbound_ವಾದಗಳು(nb_ವಾದಗಳು);
#ಆದರೆ_ಅಂತ್ಯ

    save_regs(nb_ವಾದಗಳು + 1);

    ವಾದಗಳು_ಗಾತ್ರ = 0;
    ಗಾಗಿ(i = 0;i < nb_ವಾದಗಳು; i++) {
        ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
            ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&vtop->type, &align);
            /* align to stack align size */
            ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 3) & ~3;
            /* allocate the necessary size on stack */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            ಆದರೆ (ಗಾತ್ರ_2 >= 4096) {
                save_reg(TREG_EDX);
                r = get_reg(RC_EAX);
                oad(0x68, ಗಾತ್ರ_2); // push size
                /* cannot call normal 'alloca' with bound checking */
                gen_static_call(tok_alloc_const("__alloca"));
                gadd_sp(4);
            } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
            {
                oad(0xec81, ಗಾತ್ರ_2); /* sub $xxx, %esp */
                /* generate structure store */
                r = get_reg(RC_INT);
                o(0xe089 + (r << 8)); /* mov %esp, r */
            }
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            ವಾದಗಳು_ಗಾತ್ರ += ಗಾತ್ರ_2;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (is_float(vtop->type.t)) {
            gv(RC_FLOAT); /* only one float register */
            ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_FLOAT)
                ಗಾತ್ರ_2 = 4;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                ಗಾತ್ರ_2 = 8;
            ಇಲ್ಲದಿದ್ದರೆ
                ಗಾತ್ರ_2 = 12;
            oad(0xec81, ಗಾತ್ರ_2); /* sub $xxx, %esp */
            ಆದರೆ (ಗಾತ್ರ_2 == 12)
                o(0x7cdb);
            ಇಲ್ಲದಿದ್ದರೆ
                o(0x5cd9 + ಗಾತ್ರ_2 - 4); /* fstp[s|l] 0(%esp) */
            g(0x24);
            g(0x00);
            ವಾದಗಳು_ಗಾತ್ರ += ಗಾತ್ರ_2;
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* simple type (currently always same size) */
            /* XXX: implicit cast ? */
            r = gv(RC_INT);
            ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
                ಗಾತ್ರ_2 = 8;
                o(0x50 + vtop->r2); /* push r */
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಗಾತ್ರ_2 = 4;
            }
            o(0x50 + r); /* push r */
            ವಾದಗಳು_ಗಾತ್ರ += ಗಾತ್ರ_2;
        }
        vtop--;
    }

    func_sym = vtop->type.ref;
    func_call = func_sym->f.func_call;
    /* fast call case */
    ಆದರೆ ((func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) ||
        func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL) {
        ಪೂರ್ಣಾಂಕ fastcall_nb_regs;
        ಸ್ಥಿರಾಂಕ uint8_t *fastcall_regs_ptr;
        ಆದರೆ (func_call == FUNC_FASTCALLW) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 2;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (func_call == FUNC_THISCALL) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 1;
        } ಇಲ್ಲದಿದ್ದರೆ {
            fastcall_regs_ptr = fastcall_regs;
            fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        }
        ಗಾಗಿ(i = 0;i < fastcall_nb_regs; i++) {
            ಆದರೆ (ವಾದಗಳು_ಗಾತ್ರ <= 0)
                ನಿಲ್ಲಿಸು;
            o(0x58 + fastcall_regs_ptr[i]); /* pop r */
            /* XXX: incorrect for struct/floats */
            ವಾದಗಳು_ಗಾತ್ರ -= 4;
        }
    }
#ಆದರೆ !defined(TCC_ಗುರಿ_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((vtop->type.ref->type.t & VT_BTYPE) == VT_STRUCT)
        ವಾದಗಳು_ಗಾತ್ರ -= 4;
#ಆದರೆ_ಅಂತ್ಯ

    gcall_or_jmp(0);

    ಆದರೆ (ವಾದಗಳು_ಗಾತ್ರ && func_call != FUNC_STDCALL && func_call != FUNC_THISCALL && func_call != FUNC_FASTCALLW)
        gadd_sp(ವಾದಗಳು_ಗಾತ್ರ);
    vtop--;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_PROLOG_ಗಾತ್ರ (10 + !!USE_EBX)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_PROLOG_ಗಾತ್ರ (9 + !!USE_EBX)
#ಆದರೆ_ಅಂತ್ಯ

/* generate function prolog of type 't' */
ST_FUNC ಶೂನ್ಯ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ಪೂರ್ಣಾಂಕ addr, align, ಗಾತ್ರ_2, func_call, fastcall_nb_regs;
    ಪೂರ್ಣಾಂಕ param_ಸೂಚ್ಯಂಕ, param_addr;
    ಸ್ಥಿರಾಂಕ uint8_t *fastcall_regs_ptr;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    func_call = sym->f.func_call;
    addr = 8;
    loc = 0;
    func_vc = 0;

    ಆದರೆ (func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) {
        fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        fastcall_regs_ptr = fastcall_regs;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (func_call == FUNC_FASTCALLW) {
        fastcall_nb_regs = 2;
        fastcall_regs_ptr = fastcallw_regs;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (func_call == FUNC_THISCALL) {
        fastcall_nb_regs = 1;
        fastcall_regs_ptr = fastcallw_regs;
    } ಇಲ್ಲದಿದ್ದರೆ {
        fastcall_nb_regs = 0;
        fastcall_regs_ptr = ಖಾಲಿ;
    }
    param_ಸೂಚ್ಯಂಕ = 0;

    ind += FUNC_PROLOG_ಗಾತ್ರ;
    func_sub_sp_ಸ್ಥಾನಾಂತರ = ind;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
#ಆದರೆ defined(TCC_ಗುರಿ_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&func_vt,&align);
    ಆದರೆ (((func_vt.t & VT_BTYPE) == VT_STRUCT)
        && (ಗಾತ್ರ_2 > 8 || (ಗಾತ್ರ_2 & (ಗಾತ್ರ_2 - 1)))) {
#ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ ((func_vt.t & VT_BTYPE) == VT_STRUCT) {
#ಆದರೆ_ಅಂತ್ಯ
        /* XXX: fastcall case ? */
        func_vc = addr;
        addr += 4;
        param_ಸೂಚ್ಯಂಕ++;
    }
    /* define parameters */
    ಆಗ ((sym = sym->ಮುಂದಿನ) != ಖಾಲಿ) {
        type = &sym->type;
        ಗಾತ್ರ_2 = type_ಗಾತ್ರ(type, &align);
        ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 3) & ~3;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ FUNC_STRUCT_PARAM_AS_PTR
        /* structs are passed as pointer */
        ಆದರೆ ((type->t & VT_BTYPE) == VT_STRUCT) {
            ಗಾತ್ರ_2 = 4;
        }
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (param_ಸೂಚ್ಯಂಕ < fastcall_nb_regs) {
            /* save FASTCALL register */
            loc -= 4;
            /* movl */
            gen_modrm(0x89, fastcall_regs_ptr[param_ಸೂಚ್ಯಂಕ], VT_LOCAL, ಖಾಲಿ, loc);
            param_addr = loc;
        } ಇಲ್ಲದಿದ್ದರೆ {
            param_addr = addr;
            addr += ಗಾತ್ರ_2;
        }
        gfunc_ಗಣ_param(sym, param_addr, 0);
        param_ಸೂಚ್ಯಂಕ++;
    }
    func_ret_sub = 0;
    /* pascal type call or fastcall ? */
    ಆದರೆ (func_call == FUNC_STDCALL || func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL)
        func_ret_sub = addr - 8;
#ಆದರೆ !defined(TCC_ಗುರಿ_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (func_vc)
        func_ret_sub = 4;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#ಆದರೆ_ಅಂತ್ಯ
}

/* generate function epilog */
ST_FUNC ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
    addr_t v, saved_ind;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#ಆದರೆ_ಅಂತ್ಯ

    /* align local size to word & save local variables */
    v = (-loc + 3) & -4;

#ಆದರೆ USE_EBX
    gen_modrm(0x8b, TREG_EBX, VT_LOCAL, ಖಾಲಿ, -(v+4));
#ಆದರೆ_ಅಂತ್ಯ

    o(0xc9); /* leave */
    ಆದರೆ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ಇಲ್ಲದಿದ್ದರೆ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    saved_ind = ind;
    ind = func_sub_sp_ಸ್ಥಾನಾಂತರ - FUNC_PROLOG_ಗಾತ್ರ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಆದರೆ (v >= 4096) {
        oad(0xb8, v); /* mov stacksize, %eax */
        gen_static_call(TOK___chkstk); /* call __chkstk, (does the stackframe too) */
    } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
    {
        o(0xe58955);  /* push %ebp, mov %esp, %ebp */
        o(0xec81);  /* sub esp, stacksize */
        gen_le32(v);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        o(0x90);  /* adjust to FUNC_PROLOG_SIZE */
#ಆದರೆ_ಅಂತ್ಯ
    }
#ಆದರೆ USE_EBX
    o(0x53); /* push ebx */
#ಆದರೆ_ಅಂತ್ಯ
    ind = saved_ind;
}

/* generate a jump to a label */
ST_FUNC ಪೂರ್ಣಾಂಕ gjmp(ಪೂರ್ಣಾಂಕ t)
{
    ಹಿಂತಿರುಗಿ gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ST_FUNC ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಂಕ a)
{
    ಪೂರ್ಣಾಂಕ r;
    r = a - ind - 2;
    ಆದರೆ (r == (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)r) {
        g(0xeb);
        g(r);
    } ಇಲ್ಲದಿದ್ದರೆ {
        oad(0xe9, a - ind - 5);
    }
}

#ಆದರೆ 0
/* generate a jump to a fixed address */
ST_FUNC ಶೂನ್ಯ gjmp_cond_addr(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ op)
{
    ಪೂರ್ಣಾಂಕ r = a - ind - 2;
    ಆದರೆ (r == (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)r)
        g(op - 32), g(r);
    ಇಲ್ಲದಿದ್ದರೆ
        g(0x0f), gjmp2(op - 16, r - 4);
}
#ಆದರೆ_ಅಂತ್ಯ

ST_FUNC ಪೂರ್ಣಾಂಕ gjmp_append(ಪೂರ್ಣಾಂಕ n, ಪೂರ್ಣಾಂಕ t)
{
    ಶೂನ್ಯ *p;
    /* insert vtop->c jump list in t */
    ಆದರೆ (n) {
        uint32_t n1 = n, n2;
        ಆಗ ((n2 = read32le(p = cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    ಹಿಂತಿರುಗಿ t;
}

ST_FUNC ಪೂರ್ಣಾಂಕ gjmp_cond(ಪೂರ್ಣಾಂಕ op, ಪೂರ್ಣಾಂಕ t)
{
    g(0x0f);
    t = gjmp2(op - 16, t);
    ಹಿಂತಿರುಗಿ t;
}

ST_FUNC ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಂಕ op)
{
    ಪೂರ್ಣಾಂಕ r, fr, opc, c;

    ಆಯ್ಕೆ(op) {
    ಸ್ಥಿತಿ '+':
    ಸ್ಥಿತಿ TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            ಆದರೆ (c == (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)c) {
                /* generate inc and dec for smaller code */
                ಆದರೆ ((c == 1 || c == -1) && (op == '+' || op == '-')) {
                    opc = (c == 1) ^ (op == '+');
                    o (0x40 | (opc << 3) | r); // inc,dec
                } ಇಲ್ಲದಿದ್ದರೆ {
                    o(0x83);
                    o(0xc0 | (opc << 3) | r);
                    g(c);
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                o(0x81);
                oad(0xc0 | (opc << 3) | r, c);
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            o((opc << 3) | 0x01);
            o(0xc0 + r + fr * 8); 
        }
        vtop--;
        ಆದರೆ (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '-':
    ಸ್ಥಿತಿ TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ TOK_ADDC2: /* add with carry use */
        opc = 2;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ TOK_SUBC2: /* sub with carry use */
        opc = 3;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ '&':
        opc = 4;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ '^':
        opc = 6;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ '|':
        opc = 1;
        ಹೋಗು gen_op8;
    ಸ್ಥಿತಿ '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        o(0xaf0f); /* imul fr, r */
        o(0xc0 + fr + r * 8);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SHL:
        opc = 4;
        ಹೋಗು gen_ಸರಿಸು;
    ಸ್ಥಿತಿ TOK_SHR:
        opc = 5;
        ಹೋಗು gen_ಸರಿಸು;
    ಸ್ಥಿತಿ TOK_SAR:
        opc = 7;
    gen_ಸರಿಸು:
        opc = 0xc0 | (opc << 3);
        ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i & 0x1f;
            o(0xc1); /* shl/shr/sar $xxx, r */
            o(opc | r);
            g(c);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_ECX);
            r = vtop[-1].r;
            o(0xd3); /* shl/shr/sar %cl, r */
            o(opc | r);
        }
        vtop--;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '/':
    ಸ್ಥಿತಿ TOK_UDIV:
    ಸ್ಥಿತಿ TOK_PDIV:
    ಸ್ಥಿತಿ '%':
    ಸ್ಥಿತಿ TOK_UMOD:
    ಸ್ಥಿತಿ TOK_UMULL:
        /* first operand must be in eax */
        /* XXX: need better constraint for second operand */
        gv2(RC_EAX, RC_ECX);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        save_reg(TREG_EDX);
        /* save EAX too if used otherwise */
        save_reg_upstack(TREG_EAX, 1);
        ಆದರೆ (op == TOK_UMULL) {
            o(0xf7); /* mul fr */
            o(0xe0 + fr);
            vtop->r2 = TREG_EDX;
            r = TREG_EAX;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (op == TOK_UDIV || op == TOK_UMOD) {
                o(0xf7d231); /* xor %edx, %edx, div fr, %eax */
                o(0xf0 + fr);
            } ಇಲ್ಲದಿದ್ದರೆ {
                o(0xf799); /* cltd, idiv fr, %eax */
                o(0xf8 + fr);
            }
            ಆದರೆ (op == '%' || op == TOK_UMOD)
                r = TREG_EDX;
            ಇಲ್ಲದಿದ್ದರೆ
                r = TREG_EAX;
        }
        vtop->r = r;
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        opc = 7;
        ಹೋಗು gen_op8;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ST_FUNC ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಂಕ op)
{
    ಪೂರ್ಣಾಂಕ a, ft, fc, swapped, r;

    ಆದರೆ (op == TOK_NEG) { /* unary minus */
        gv(RC_FLOAT);
        o(0xe0d9); /* fchs */
        ಹಿಂತಿರುಗಿ;
    }

    /* convert constants to memory references */
    ಆದರೆ ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    ಆದರೆ ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(RC_FLOAT);

    /* must put at least one value in the floating point register */
    ಆದರೆ ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    ಆದರೆ (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    ಆದರೆ (op >= TOK_ULT && op <= TOK_GT) {
        /* load on stack second operand */
        ತುಂಬು(TREG_ST0, vtop);
        save_reg(TREG_EAX); /* eax is used by FP comparison code */
        ಆದರೆ (op == TOK_GE || op == TOK_GT)
            swapped = !swapped;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_EQ || op == TOK_NE)
            swapped = 0;
        ಆದರೆ (swapped)
            o(0xc9d9); /* fxch %st(1) */
        ಆದರೆ (op == TOK_EQ || op == TOK_NE)
            o(0xe9da); /* fucompp */
        ಇಲ್ಲದಿದ್ದರೆ
            o(0xd9de); /* fcompp */
        o(0xe0df); /* fnstsw %ax */
        ಆದರೆ (op == TOK_EQ) {
            o(0x45e480); /* and $0x45, %ah */
            o(0x40fC80); /* cmp $0x40, %ah */
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_NE) {
            o(0x45e480); /* and $0x45, %ah */
            o(0x40f480); /* xor $0x40, %ah */
            op = TOK_NE;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_GE || op == TOK_LE) {
            o(0x05c4f6); /* test $0x05, %ah */
            op = TOK_EQ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            o(0x45c4f6); /* test $0x45, %ah */
            op = TOK_EQ;
        }
        vtop--;
        vset_VT_CMP(op);
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* no memory reference possible for long double operations */
        ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
            ತುಂಬು(TREG_ST0, vtop);
            swapped = !swapped;
        }
        
        ಆಯ್ಕೆ(op) {
        ಪೂರ್ವನಿಯೋಜಿತ:
        ಸ್ಥಿತಿ '+':
            a = 0;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '-':
            a = 4;
            ಆದರೆ (swapped)
                a++;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '*':
            a = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '/':
            a = 6;
            ಆದರೆ (swapped)
                a++;
            ನಿಲ್ಲಿಸು;
        }
        ft = vtop->type.t;
        fc = vtop->c.i;
        ಆದರೆ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            ಆದರೆ ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_INT;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = ಖಾಲಿ;
                ತುಂಬು(r, &v1);
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
ST_FUNC ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಂಕ t)
{
    save_reg(TREG_ST0);
    gv(RC_INT);
    ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
        /* signed long long to float/double/long double (unsigned case
           is handled generically) */
        o(0x50 + vtop->r2); /* push r2 */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
        vtop->r2 = VT_CONST;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
               (VT_INT | VT_UNSIGNED)) {
        /* unsigned int to float/double/long double */
        o(0x6a); /* push $0 */
        g(0x00);
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* int to float/double/long double */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x2404db); /* fildl (%esp) */
        o(0x04c483); /* add $4, %esp */
    }
    vtop->r2 = VT_CONST;
    vtop->r = TREG_ST0;
}

/* convert fp to int 't' type */
ST_FUNC ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ bt = vtop->type.t & VT_BTYPE;
    ಆದರೆ (bt == VT_FLOAT)
        vpush_helper_func(TOK___fixsfdi);
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_LDOUBLE)
        vpush_helper_func(TOK___fixxfdi);
    ಇಲ್ಲದಿದ್ದರೆ
        vpush_helper_func(TOK___fixdfdi);
    vswap();
    gfunc_call(1);
    vpushi(0);
    vtop->r = REG_IRET;
    ಆದರೆ ((t & VT_BTYPE) == VT_LLONG)
        vtop->r2 = REG_IRE2;
}

/* convert from one floating point type to another */
ST_FUNC ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಂಕ t)
{
    /* all we have to do on i386 is to put the float in a register */
    gv(RC_FLOAT);
}

/* char/short to int conversion */
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ r, sz, xl;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    o(0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (r << 3 | r) << 16
        );
}

/* increment tcov counter */
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv)
{
   ಪೂರ್ಣಾಂಕ indir, rel, add1, add2;
#ಆದರೆ defined CONFIG_TCC_PIC
   get_pc_thunk(TREG_EBX, 0);
   indir = 0x8300;
   rel = R_386_PC32;
   add1 = 2;
   add2 = 13;
#ಇಲ್ಲದಿದ್ದರೆ
   indir = 0x0500;
   rel = R_386_32;
   add1 = 0;
   add2 = 4;
#ಆದರೆ_ಅಂತ್ಯ
   o(0x0083 + indir); /* addl $1, xxx(%ebx) */
   greloc(cur_ಪಠ್ಯ_section, sv->sym, ind, rel);
   gen_le32(add1);
   o(1);
   o(0x1083 + indir); /* adcl $0, xxx(%ebx) */
   greloc(cur_ಪಠ್ಯ_section, sv->sym, ind, rel);
   gen_le32(add2);
   g(0);
}

/* computed goto support */
ST_FUNC ಶೂನ್ಯ ggoto(ಶೂನ್ಯ)
{
    gcall_or_jmp(1);
    vtop--;
}

/* bound check support functions */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK

/* Need PIC for shared libraries */
ಸ್ಥಿರ ಶೂನ್ಯ gen_bound_call(ಪೂರ್ಣಾಂಕ v)
{
    Sym *sym;

    sym = external_helper_sym(v);
#ಆದರೆ defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EBX, 1);
    oad(0xe8, -4);
    greloc(cur_ಪಠ್ಯ_section, sym, ind - 4, R_386_PLT32);
#ಇಲ್ಲದಿದ್ದರೆ
    oad(0xe8, -4);
    greloc(cur_ಪಠ್ಯ_section, sym, ind - 4, R_386_PC32);
#ಆದರೆ_ಅಂತ್ಯ
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_prolog(ಶೂನ್ಯ)
{
    /* leave some room for bound checking code */
    func_bound_ಸ್ಥಾನಾಂತರ = lbounds_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    func_bound_ind = ind;
    func_bound_ಕೂಡಿಸು_epilog = 0;
#ಆದರೆ defined CONFIG_TCC_PIC
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0x808d, 0); /* lea lbound section pointer */
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0xc381, 0); /* add _GLOBAL_OFFSET_TABLE_ */
    oad(0xb8, 0); /* call to function */
#ಇಲ್ಲದಿದ್ದರೆ
    oad(0xb8, 0); /* lbound section pointer */
    oad(0xb8, 0); /* call to function */
#ಆದರೆ_ಅಂತ್ಯ
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_epilog(ಶೂನ್ಯ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ದತ್ತಾಂಶ;
    ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ_modified = func_bound_ಸ್ಥಾನಾಂತರ != lbounds_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (!ಸ್ಥಾನಾಂತರ_modified && !func_bound_ಕೂಡಿಸು_epilog)
        ಹಿಂತಿರುಗಿ;

    /* add end of table info */
    bounds_ptr = section_ptr_ಕೂಡಿಸು(lbounds_section, ಗಾತ್ರ(addr_t));
    *bounds_ptr = 0;

    sym_ದತ್ತಾಂಶ = get_sym_ref(&char_ಸೂಚಕ_type, lbounds_section,
                           func_bound_ಸ್ಥಾನಾಂತರ, PTR_ಗಾತ್ರ);

    /* generate bound local allocation */
    ಆದರೆ (ಸ್ಥಾನಾಂತರ_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
#ಆದರೆ defined CONFIG_TCC_PIC
	get_pc_thunk(TREG_EAX, 0);
	o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
	greloc(cur_ಪಠ್ಯ_section, sym_ದತ್ತಾಂಶ, ind, R_386_PC32);
	gen_le32(2);
#ಇಲ್ಲದಿದ್ದರೆ
        greloc(cur_ಪಠ್ಯ_section, sym_ದತ್ತಾಂಶ, ind + 1, R_386_32);
        ind = ind + 5;
#ಆದರೆ_ಅಂತ್ಯ
        gen_bound_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0x5250); /* save returned value, if any */
#ಆದರೆ defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EAX, 0);
    o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
    greloc(cur_ಪಠ್ಯ_section, sym_ದತ್ತಾಂಶ, ind, R_386_PC32);
    gen_le32(2);
#ಇಲ್ಲದಿದ್ದರೆ
    greloc(cur_ಪಠ್ಯ_section, sym_ದತ್ತಾಂಶ, ind + 1, R_386_32);
    oad(0xb8, 0); /* mov %eax, xxx */
#ಆದರೆ_ಅಂತ್ಯ
    gen_bound_call(TOK___bound_local_delete);
    o(0x585a); /* restore returned value, if any */
}
#ಆದರೆ_ಅಂತ್ಯ

/* Save the stack pointer onto the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_sp_save(ಪೂರ್ಣಾಂಕ addr) {
    /* mov %esp,addr(%ebp)*/
    gen_modrm(0x89, TREG_ESP, VT_LOCAL, ಖಾಲಿ, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_sp_restore(ಪೂರ್ಣಾಂಕ addr) {
    gen_modrm(0x8b, TREG_ESP, VT_LOCAL, ಖಾಲಿ, addr);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_alloc(CType *type, ಪೂರ್ಣಾಂಕ align) {
    ಪೂರ್ಣಾಂಕ use_call = 0;

#ಆದರೆ defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE    /* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        ಪೂರ್ಣಾಂಕ r;
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
#ಆದರೆ_ಅಂತ್ಯ
/*************************************************************/
