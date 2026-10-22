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

#اگر_تعریف_شده هدف_DEFS_ONLY

/* number of available registers */
#تعریف_کن NB_REGS         5
#تعریف_کن NB_ASM_REGS     8
#تعریف_کن CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#تعریف_کن RC_INT     0x0001 /* generic integer register */
#تعریف_کن RC_FLOAT   0x0002 /* generic float register */
#تعریف_کن RC_EAX     0x0004
#تعریف_کن RC_EDX     0x0008
#تعریف_کن RC_ECX     0x0010
#تعریف_کن RC_EBX     0x0020
#تعریف_کن RC_ST0     0x0040

#تعریف_کن RC_IRET    RC_EAX /* function return: integer register */
#تعریف_کن RC_IRE2    RC_EDX /* function return: second integer register */
#تعریف_کن RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
تعداد {
    TREG_EAX = 0,
    TREG_ECX,
    TREG_EDX,
    TREG_EBX,
    TREG_ST0,
    TREG_ESP = 4,
    TREG_MEM = 0x20
};

#تعریف_کن REG_مقدار(reg) ((reg) & 7)

/* return registers for function */
#تعریف_کن REG_IRET TREG_EAX /* single word int return register */
#تعریف_کن REG_IRE2 TREG_EDX /* second word return register (for long long) */
#تعریف_کن REG_FRET TREG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
#تعریف_کن INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#تعریف_کن PTR_اندازه 4

/* long double size and alignment, in bytes */
#تعریف_کن LDOUBLE_اندازه  12
#تعریف_کن LDOUBLE_ALIGN 4
/* maximum alignment (for aligned attribute support) */
#تعریف_کن MAX_ALIGN     8

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#تعریف_کن PROMOTE_RET

/******************************************************/
#وإلا /* ! TARGET_DEFS_ONLY */
/******************************************************/
#تعریف_کن USING_GLOBALS
#ضمن "tcc.h"

ST_داده ثابت حرف * ثابت هدف_machine_defs =
    "__i386__\0"
    "__i386\0"
    ;

#إذا defined CONFIG_TCC_PIC
# define USE_EBX 2
#وإلا
# define USE_EBX 0 /* define to 1 to have EBX as 4th register */
#پایان_اگر

ST_داده ثابت صحيح reg_classes[NB_REGS] = {
    /* eax */ RC_INT | RC_EAX,
    /* ecx */ RC_INT | RC_ECX,
    /* edx */ RC_INT | RC_EDX,
    /* ebx */ (RC_INT | RC_EBX) * (USE_EBX == 1),
    /* st0 */ RC_FLOAT | RC_ST0,
};

ساكن بیعلامت دراز func_sub_sp_جابه_جایی;
ساكن صحيح func_ret_sub;
#اگر_تعریف_شده CONFIG_TCC_BCHECK
ساكن addr_t func_bound_جابه_جایی;
ساكن بیعلامت دراز func_bound_ind;
ST_داده صحيح func_bound_جمع_کن_epilog;
ساكن فراغ gen_bounds_prolog(فراغ);
ساكن فراغ gen_bounds_epilog(فراغ);
#پایان_اگر

/* XXX: make it faster ? */
ST_FUNC فراغ g(صحيح c)
{
    صحيح ind1;
    إذا (nocode_wanted)
        أرجع;
    ind1 = ind + 1;
    إذا (ind1 > cur_متن_section->داده_allocated)
        section_realloc(cur_متن_section, ind1);
    cur_متن_section->داده[ind] = c;
    ind = ind1;
}

ST_FUNC فراغ o(بیعلامت صحيح c)
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

/* output a symbol and patch all calls to it */
ST_FUNC فراغ gsym_addr(صحيح t, صحيح a)
{
    طالما (t) {
        بیعلامت حرف *ptr = cur_متن_section->داده + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a - t - 4);
        t = n;
    }
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

ST_FUNC فراغ gen_fill_nops(صحيح بایتها)
{
    طالما (بایتها--)
      g(0x90);
}

#إذا defined CONFIG_TCC_PIC
ساكن فراغ gen_static_call(صحيح v);
ساكن فراغ get_pc_thunk(صحيح r, صحيح جمع_کن)
{
    ساكن ثابت حرف * ثابت pc_thunk_name[] = {
	"__x86.get_pc_thunk.ax",
	"__x86.get_pc_thunk.cx",
	"__x86.get_pc_thunk.dx",
	"__x86.get_pc_thunk.bx"
    };
    إذا (nocode_wanted)
        أرجع;
    gen_static_call(tok_alloc_const(pc_thunk_name[r]));
    إذا (جمع_کن) {
        Sym label = {0};
        label.type.t = VT_VOID|VT_STATIC;
        put_extern_sym(&label, cur_متن_section, ind, 0);
        r = REG_مقدار(r);
	إذا (r == 0)
	    oad(0x05, 1); /* add _GLOBAL_OFFSET_TABLE_, %eax */
	وإلا
            oad(0xc081 + r * 0x100, 2); /* add _GLOBAL_OFFSET_TABLE_, %erx */
        greloc(cur_متن_section, &label, ind - 4, R_386_GOTPC);
    }
}

ST_FUNC فراغ gen_gotpcrel(صحيح r, Sym *sym, صحيح c)
{
    greloc(cur_متن_section, sym, ind, R_386_GOT32X);
    gen_le32(0);
    إذا (c) {
	r = REG_مقدار(r);
	إذا (r == 0)
            oad(0x05, c);
	وإلا
            oad(0xc081 + r * 0x100, c);
    }
}
#پایان_اگر

/* generate jmp to a label */
#تعریف_کن gjmp2(instr,lbl) oad(instr,lbl)

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC فراغ gen_addr32(صحيح r, Sym *sym, صحيح c)
{
    إذا (r & VT_SYM)
        greloc(cur_متن_section, sym, ind, R_386_32);
    gen_le32(c);
}

ST_FUNC فراغ gen_addrpc32(صحيح r, Sym *sym, صحيح c)
{
    إذا (r & VT_SYM)
        greloc(cur_متن_section, sym, ind, R_386_PC32);
    gen_le32(c - 4);
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode bits */
ساكن فراغ gen_modrm(صحيح opc, صحيح op_r2, صحيح r, Sym *sym, صحيح c)
{
    صحيح op_reg = REG_مقدار(op_r2) << 3;

    إذا ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#اگر_تعریف_شده TCC_هدف_PE
        Sym *s2 = external_global_sym(TOK_tls_شاخص, &int_type);
        r = get_reg(RC_INT);
        gen_modrm(0x8b, r, VT_SYM|VT_CONST, s2, 0); /* mov __tls_index, r */
        o(0x02e0c1 | r << 8); /* shl 2,r */
        oad(0x050364 | r << 19, 11*PTR_اندازه); /* add fs:0x2c,r */
        gen_modrm(0x8b, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        o(opc), oad(0x80 | op_reg | r, c); /* mov #c(r),op_reg */
        greloc(cur_متن_section, sym, ind - 4, R_386_TLS_LE);
#وإلا
        o(0x65); /* gs segment prefix */
        o(opc), oad(0x05 | op_reg, c);
        greloc(cur_متن_section, sym, ind - 4, R_386_TLS_LE);
#پایان_اگر
#إذا defined CONFIG_TCC_PIC
    } وإلا إذا ((r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
        صحيح is_got = (op_r2 & TREG_MEM) && !(sym->type.t & VT_STATIC);
        صحيح اینجا = ind;
        get_pc_thunk(TREG_EBX, is_got);
        o(opc);
        o(0x83 | op_reg);
        إذا (is_got) {
            gen_gotpcrel(r, sym, c);
        } وإلا {
            gen_addrpc32(r, sym, c + (ind - اینجا - 1));
        }
    } وإلا إذا ((r & VT_VALMASK) < VT_CONST && (r & TREG_MEM)) {
        o(opc);
        إذا (c) {
            g(0x80 | op_reg | REG_مقدار(r));
            gen_le32(c);
        } وإلا {
            g(0x00 | op_reg | REG_مقدار(r));
        }
#پایان_اگر
    } وإلا إذا ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
        o(opc);
        o(0x05 | op_reg);
        gen_addr32(r, sym, c);
    } وإلا إذا ((r & VT_VALMASK) == VT_LOCAL) {
	o(opc);
        /* currently, we use only ebp as base */
        إذا (c == (علامتدار حرف)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } وإلا {
            oad(0x85 | op_reg, c);
        }
    } وإلا {
	o(opc);
        g(0x00 | op_reg | (r & VT_VALMASK));
    }
}

/* load 'r' from value 'sv' */
ST_FUNC فراغ بارگیری(صحيح r, SValue *sv)
{
    صحيح v, t, ft, fc, fr, opc;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~VT_DEFSIGN;
    fc = sv->c.i;
    ft &= ~VT_QUAL;
    v = fr & VT_VALMASK;

#إذا defined CONFIG_TCC_PIC
    /* we use indirect access via got */
    إذا ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        صحيح tr = r | TREG_MEM;
        إذا (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm(0x8b, tr, fr, sv->sym, 0);
        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#پایان_اگر

    إذا (fr & VT_LVAL) {
        إذا (v == VT_LLOCAL) {
            v1.type.t = VT_INT;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
            v1.sym = عدم;
            fr = r;
            إذا (!(reg_classes[fr] & RC_INT))
                fr = get_reg(RC_INT);
            بارگیری(fr, &v1);
        }
        إذا ((ft & VT_BTYPE) == VT_FLOAT) {
            opc = 0xd9; /* flds */
            r = 0;
        } وإلا إذا ((ft & VT_BTYPE) == VT_DOUBLE) {
            opc = 0xdd; /* fldl */
            r = 0;
        } وإلا إذا ((ft & VT_BTYPE) == VT_LDOUBLE) {
            opc = 0xdb; /* fldt */
            r = 5;
        } وإلا إذا ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            opc = 0xbe0f;   /* movsbl */
        } وإلا إذا ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED) ||
		   (ft & VT_TYPE) == (VT_BOOL | VT_UNSIGNED)) {
            opc = 0xb60f;   /* movzbl */
        } وإلا إذا ((ft & VT_TYPE) == VT_SHORT) {
            opc = 0xbf0f;   /* movswl */
        } وإلا إذا ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            opc = 0xb70f;   /* movzwl */
        } وإلا {
            opc = 0x8b;     /* movl */
        }
        gen_modrm(opc, r, fr, sv->sym, fc);
    } وإلا {
        إذا ((fr & VT_SYM) && (sv->sym->type.t & VT_TLS)) {
#اگر_تعریف_شده TCC_هدف_PE
            gen_modrm(0x8d, r, fr, sv->sym, fc);
#وإلا
            oad(0x058b65 | REG_مقدار(r) << 19, 0); /* mov gs:0,r */
            oad(0xC081 | REG_مقدار(r) << 8, fc); /* add tpoffs,r */
            greloc(cur_متن_section, sv->sym, ind - 4, R_386_TLS_LE);
#پایان_اگر
#إذا defined CONFIG_TCC_PIC
        } وإلا إذا ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
            إذا (sv->sym->type.t & VT_STATIC) {
                get_pc_thunk(r, 0);
                o(0x808d | REG_مقدار(r) * 0x900); /* lea $xx(r), r */
                gen_addrpc32(fr, sv->sym, fc + 6);
            } وإلا {
                get_pc_thunk(r, 1);
                o(0x808b | REG_مقدار(r) * 0x900); /* mov $xx(r), r */
                gen_gotpcrel(r, sv->sym, fc);
            }
#پایان_اگر
        } وإلا إذا (v == VT_CONST) {
            o(0xb8 + r); /* mov $xx, r */
            gen_addr32(fr, sv->sym, fc);
        } وإلا إذا (v == VT_LOCAL) {
            إذا (fc) {
                /* lea xxx(%ebp), r */
                gen_modrm(0x8d, r, VT_LOCAL, sv->sym, fc);
            } وإلا {
                o(0x89);
                o(0xe8 + r); /* mov %ebp, r */
            }
        } وإلا إذا (v == VT_CMP) {
            o(0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + r);
            o(0xc0b60f + r * 0x90000); /* movzbl %al, %eax */
        } وإلا إذا (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            oad(0xb8 + r, t); /* mov $1, r */
            o(0x05eb); /* jmp after */
            gsym(fc);
            oad(0xb8 + r, t ^ 1); /* mov $0, r */
        } وإلا إذا (v != r) {
            o(0x89);
            o(0xc0 + r + v * 8); /* mov v, r */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ST_FUNC فراغ store(صحيح r, SValue *v)
{
    صحيح fr, bt, fc, opc;

    bt = v->type.t & VT_BTYPE;

    /* XXX: incorrect if float reg to reg */
    إذا (bt == VT_FLOAT) {
        opc = 0xd9; /* fsts */
        r = 2;
    } وإلا إذا (bt == VT_DOUBLE) {
        opc = 0xdd; /* fstpl */
        r = 2;
    } وإلا إذا (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0), fstpt */
        opc = 0xdb;
        r = 7;
    } وإلا إذا (bt == VT_SHORT) {
        opc = 0x8966;
    } وإلا إذا (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } وإلا {
        opc = 0x89;
    }

    fc = v->c.i;
    fr = v->r & VT_VALMASK;

#إذا defined CONFIG_TCC_PIC
    /* we need to access the variable via got */
    إذا ((v->r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
	get_pc_thunk(TREG_EBX, 1);
	o(0x9b8b); /* mov xx(%ebx),%ebx */
	gen_gotpcrel(TREG_EBX, v->sym, v->c.i);
	o(opc);
	o(3 + (r << 3));
    } وإلا
#پایان_اگر

    إذا (fr == VT_CONST || fr == VT_LOCAL || (v->r & VT_LVAL)) {
        gen_modrm(opc, r, v->r, v->sym, fc);
    } وإلا إذا (fr != r) {
	o(opc);
        o(0xc0 + fr + r * 8); /* mov r, fr */
    }
}

ساكن فراغ gadd_sp(صحيح val)
{
    إذا (val == (علامتدار حرف)val) {
        o(0xc483);
        g(val);
    } وإلا {
        oad(0xc481, val); /* add $xxx, %esp */
    }
}

#إذا defined TCC_هدف_PE || defined CONFIG_TCC_PIC
ساكن فراغ gen_static_call(صحيح v)
{
    Sym *sym;

    sym = external_helper_sym(v);
    oad(0xe8, -4);
    greloc(cur_متن_section, sym, ind - 4, R_386_PC32);
}
#پایان_اگر

/* 'is_jmp' is '1' if it is a jump */
ساكن فراغ gcall_or_jmp(صحيح is_jmp)
{
    صحيح r;
    إذا ((vtop->r & (VT_VALMASK|VT_LVAL|VT_SYM)) == (VT_CONST|VT_SYM)) {
        /* constant and relocation case */
#إذا defined CONFIG_TCC_PIC
	إذا (!(vtop->sym->type.t & VT_STATIC)) {
	    get_pc_thunk(TREG_EBX, 1);
            oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
            greloc(cur_متن_section, vtop->sym, ind - 4, R_386_PLT32);
            أرجع;
	}
#پایان_اگر
        oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
        greloc(cur_متن_section, vtop->sym, ind - 4, R_386_PC32);
    } وإلا {
        /* otherwise, indirect call */
        r = gv(RC_INT);
        o(0xff); /* call/jmp *r */
        o(0xd0 + r + (is_jmp << 4));
    }
}

ساكن ثابت uint8_t fastcall_regs[3] = { TREG_EAX, TREG_EDX, TREG_ECX };
ساكن ثابت uint8_t fastcallw_regs[2] = { TREG_ECX, TREG_EDX };

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret, صحيح *ret_align, صحيح *regsize)
{
#إذا defined(TCC_هدف_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    صحيح اندازه, align, nregs;
    *ret_align = 1; // Never have to re-align return values for x86
    *regsize = 4;
    اندازه = type_اندازه(vt, &align);
    إذا (اندازه > 8 || (اندازه & (اندازه - 1)))
        أرجع 0;
    nregs = 1;
    إذا (اندازه == 8)
        ret->t = VT_INT, nregs = 2;
    وإلا إذا (اندازه == 4)
        ret->t = VT_INT;
    وإلا إذا (اندازه == 2)
        ret->t = VT_SHORT;
    وإلا
        ret->t = VT_BYTE;
    ret->ref = عدم;
    أرجع nregs;
#وإلا
    *ret_align = 1; // Never have to re-align return values for x86
    أرجع 0;
#پایان_اگر
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ST_FUNC فراغ gfunc_call(صحيح nb_آرگومانها)
{
    صحيح اندازه, align, r, آرگومانها_اندازه, i, func_call;
    Sym *func_sym;

#اگر_تعریف_شده CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gbound_آرگومانها(nb_آرگومانها);
#پایان_اگر

    save_regs(nb_آرگومانها + 1);

    آرگومانها_اندازه = 0;
    لكل(i = 0;i < nb_آرگومانها; i++) {
        إذا ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
            اندازه = type_اندازه(&vtop->type, &align);
            /* align to stack align size */
            اندازه = (اندازه + 3) & ~3;
            /* allocate the necessary size on stack */
#اگر_تعریف_شده TCC_هدف_PE
            إذا (اندازه >= 4096) {
                save_reg(TREG_EDX);
                r = get_reg(RC_EAX);
                oad(0x68, اندازه); // push size
                /* cannot call normal 'alloca' with bound checking */
                gen_static_call(tok_alloc_const("__alloca"));
                gadd_sp(4);
            } وإلا
#پایان_اگر
            {
                oad(0xec81, اندازه); /* sub $xxx, %esp */
                /* generate structure store */
                r = get_reg(RC_INT);
                o(0xe089 + (r << 8)); /* mov %esp, r */
            }
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            آرگومانها_اندازه += اندازه;
        } وإلا إذا (is_float(vtop->type.t)) {
            gv(RC_FLOAT); /* only one float register */
            إذا ((vtop->type.t & VT_BTYPE) == VT_FLOAT)
                اندازه = 4;
            وإلا إذا ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                اندازه = 8;
            وإلا
                اندازه = 12;
            oad(0xec81, اندازه); /* sub $xxx, %esp */
            إذا (اندازه == 12)
                o(0x7cdb);
            وإلا
                o(0x5cd9 + اندازه - 4); /* fstp[s|l] 0(%esp) */
            g(0x24);
            g(0x00);
            آرگومانها_اندازه += اندازه;
        } وإلا {
            /* simple type (currently always same size) */
            /* XXX: implicit cast ? */
            r = gv(RC_INT);
            إذا ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
                اندازه = 8;
                o(0x50 + vtop->r2); /* push r */
            } وإلا {
                اندازه = 4;
            }
            o(0x50 + r); /* push r */
            آرگومانها_اندازه += اندازه;
        }
        vtop--;
    }

    func_sym = vtop->type.ref;
    func_call = func_sym->f.func_call;
    /* fast call case */
    إذا ((func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) ||
        func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL) {
        صحيح fastcall_nb_regs;
        ثابت uint8_t *fastcall_regs_ptr;
        إذا (func_call == FUNC_FASTCALLW) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 2;
        } وإلا إذا (func_call == FUNC_THISCALL) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 1;
        } وإلا {
            fastcall_regs_ptr = fastcall_regs;
            fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        }
        لكل(i = 0;i < fastcall_nb_regs; i++) {
            إذا (آرگومانها_اندازه <= 0)
                اكسر;
            o(0x58 + fastcall_regs_ptr[i]); /* pop r */
            /* XXX: incorrect for struct/floats */
            آرگومانها_اندازه -= 4;
        }
    }
#إذا !defined(TCC_هدف_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    وإلا إذا ((vtop->type.ref->type.t & VT_BTYPE) == VT_STRUCT)
        آرگومانها_اندازه -= 4;
#پایان_اگر

    gcall_or_jmp(0);

    إذا (آرگومانها_اندازه && func_call != FUNC_STDCALL && func_call != FUNC_THISCALL && func_call != FUNC_FASTCALLW)
        gadd_sp(آرگومانها_اندازه);
    vtop--;
}

#اگر_تعریف_شده TCC_هدف_PE
#تعریف_کن FUNC_PROLOG_اندازه (10 + !!USE_EBX)
#وإلا
#تعریف_کن FUNC_PROLOG_اندازه (9 + !!USE_EBX)
#پایان_اگر

/* generate function prolog of type 't' */
ST_FUNC فراغ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    صحيح addr, align, اندازه, func_call, fastcall_nb_regs;
    صحيح param_شاخص, param_addr;
    ثابت uint8_t *fastcall_regs_ptr;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    func_call = sym->f.func_call;
    addr = 8;
    loc = 0;
    func_vc = 0;

    إذا (func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) {
        fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        fastcall_regs_ptr = fastcall_regs;
    } وإلا إذا (func_call == FUNC_FASTCALLW) {
        fastcall_nb_regs = 2;
        fastcall_regs_ptr = fastcallw_regs;
    } وإلا إذا (func_call == FUNC_THISCALL) {
        fastcall_nb_regs = 1;
        fastcall_regs_ptr = fastcallw_regs;
    } وإلا {
        fastcall_nb_regs = 0;
        fastcall_regs_ptr = عدم;
    }
    param_شاخص = 0;

    ind += FUNC_PROLOG_اندازه;
    func_sub_sp_جابه_جایی = ind;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
#إذا defined(TCC_هدف_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    اندازه = type_اندازه(&func_vt,&align);
    إذا (((func_vt.t & VT_BTYPE) == VT_STRUCT)
        && (اندازه > 8 || (اندازه & (اندازه - 1)))) {
#وإلا
    إذا ((func_vt.t & VT_BTYPE) == VT_STRUCT) {
#پایان_اگر
        /* XXX: fastcall case ? */
        func_vc = addr;
        addr += 4;
        param_شاخص++;
    }
    /* define parameters */
    طالما ((sym = sym->بعدی) != عدم) {
        type = &sym->type;
        اندازه = type_اندازه(type, &align);
        اندازه = (اندازه + 3) & ~3;
#اگر_تعریف_شده FUNC_STRUCT_PARAM_AS_PTR
        /* structs are passed as pointer */
        إذا ((type->t & VT_BTYPE) == VT_STRUCT) {
            اندازه = 4;
        }
#پایان_اگر
        إذا (param_شاخص < fastcall_nb_regs) {
            /* save FASTCALL register */
            loc -= 4;
            /* movl */
            gen_modrm(0x89, fastcall_regs_ptr[param_شاخص], VT_LOCAL, عدم, loc);
            param_addr = loc;
        } وإلا {
            param_addr = addr;
            addr += اندازه;
        }
        gfunc_مجموعه_param(sym, param_addr, 0);
        param_شاخص++;
    }
    func_ret_sub = 0;
    /* pascal type call or fastcall ? */
    إذا (func_call == FUNC_STDCALL || func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL)
        func_ret_sub = addr - 8;
#إذا !defined(TCC_هدف_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    وإلا إذا (func_vc)
        func_ret_sub = 4;
#پایان_اگر

#اگر_تعریف_شده CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#پایان_اگر
}

/* generate function epilog */
ST_FUNC فراغ gfunc_epilog(فراغ)
{
    addr_t v, saved_ind;

#اگر_تعریف_شده CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#پایان_اگر

    /* align local size to word & save local variables */
    v = (-loc + 3) & -4;

#إذا USE_EBX
    gen_modrm(0x8b, TREG_EBX, VT_LOCAL, عدم, -(v+4));
#پایان_اگر

    o(0xc9); /* leave */
    إذا (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } وإلا {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    saved_ind = ind;
    ind = func_sub_sp_جابه_جایی - FUNC_PROLOG_اندازه;
#اگر_تعریف_شده TCC_هدف_PE
    إذا (v >= 4096) {
        oad(0xb8, v); /* mov stacksize, %eax */
        gen_static_call(TOK___chkstk); /* call __chkstk, (does the stackframe too) */
    } وإلا
#پایان_اگر
    {
        o(0xe58955);  /* push %ebp, mov %esp, %ebp */
        o(0xec81);  /* sub esp, stacksize */
        gen_le32(v);
#اگر_تعریف_شده TCC_هدف_PE
        o(0x90);  /* adjust to FUNC_PROLOG_SIZE */
#پایان_اگر
    }
#إذا USE_EBX
    o(0x53); /* push ebx */
#پایان_اگر
    ind = saved_ind;
}

/* generate a jump to a label */
ST_FUNC صحيح gjmp(صحيح t)
{
    أرجع gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ST_FUNC فراغ gjmp_addr(صحيح a)
{
    صحيح r;
    r = a - ind - 2;
    إذا (r == (علامتدار حرف)r) {
        g(0xeb);
        g(r);
    } وإلا {
        oad(0xe9, a - ind - 5);
    }
}

#إذا 0
/* generate a jump to a fixed address */
ST_FUNC فراغ gjmp_cond_addr(صحيح a, صحيح op)
{
    صحيح r = a - ind - 2;
    إذا (r == (علامتدار حرف)r)
        g(op - 32), g(r);
    وإلا
        g(0x0f), gjmp2(op - 16, r - 4);
}
#پایان_اگر

ST_FUNC صحيح gjmp_append(صحيح n, صحيح t)
{
    فراغ *p;
    /* insert vtop->c jump list in t */
    إذا (n) {
        uint32_t n1 = n, n2;
        طالما ((n2 = read32le(p = cur_متن_section->داده + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    أرجع t;
}

ST_FUNC صحيح gjmp_cond(صحيح op, صحيح t)
{
    g(0x0f);
    t = gjmp2(op - 16, t);
    أرجع t;
}

ST_FUNC فراغ gen_opi(صحيح op)
{
    صحيح r, fr, opc, c;

    بدل(op) {
    حالة '+':
    حالة TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        إذا ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            إذا (c == (علامتدار حرف)c) {
                /* generate inc and dec for smaller code */
                إذا ((c == 1 || c == -1) && (op == '+' || op == '-')) {
                    opc = (c == 1) ^ (op == '+');
                    o (0x40 | (opc << 3) | r); // inc,dec
                } وإلا {
                    o(0x83);
                    o(0xc0 | (opc << 3) | r);
                    g(c);
                }
            } وإلا {
                o(0x81);
                oad(0xc0 | (opc << 3) | r, c);
            }
        } وإلا {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            o((opc << 3) | 0x01);
            o(0xc0 + r + fr * 8); 
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
        vtop--;
        o(0xaf0f); /* imul fr, r */
        o(0xc0 + fr + r * 8);
        اكسر;
    حالة TOK_SHL:
        opc = 4;
        اذهب gen_لغزش;
    حالة TOK_SHR:
        opc = 5;
        اذهب gen_لغزش;
    حالة TOK_SAR:
        opc = 7;
    gen_لغزش:
        opc = 0xc0 | (opc << 3);
        إذا ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i & 0x1f;
            o(0xc1); /* shl/shr/sar $xxx, r */
            o(opc | r);
            g(c);
        } وإلا {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_ECX);
            r = vtop[-1].r;
            o(0xd3); /* shl/shr/sar %cl, r */
            o(opc | r);
        }
        vtop--;
        اكسر;
    حالة '/':
    حالة TOK_UDIV:
    حالة TOK_PDIV:
    حالة '%':
    حالة TOK_UMOD:
    حالة TOK_UMULL:
        /* first operand must be in eax */
        /* XXX: need better constraint for second operand */
        gv2(RC_EAX, RC_ECX);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        save_reg(TREG_EDX);
        /* save EAX too if used otherwise */
        save_reg_upstack(TREG_EAX, 1);
        إذا (op == TOK_UMULL) {
            o(0xf7); /* mul fr */
            o(0xe0 + fr);
            vtop->r2 = TREG_EDX;
            r = TREG_EAX;
        } وإلا {
            إذا (op == TOK_UDIV || op == TOK_UMOD) {
                o(0xf7d231); /* xor %edx, %edx, div fr, %eax */
                o(0xf0 + fr);
            } وإلا {
                o(0xf799); /* cltd, idiv fr, %eax */
                o(0xf8 + fr);
            }
            إذا (op == '%' || op == TOK_UMOD)
                r = TREG_EDX;
            وإلا
                r = TREG_EAX;
        }
        vtop->r = r;
        اكسر;
    افتراضي:
        opc = 7;
        اذهب gen_op8;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ST_FUNC فراغ gen_opf(صحيح op)
{
    صحيح a, ft, fc, swapped, r;

    إذا (op == TOK_NEG) { /* unary minus */
        gv(RC_FLOAT);
        o(0xe0d9); /* fchs */
        أرجع;
    }

    /* convert constants to memory references */
    إذا ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    إذا ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(RC_FLOAT);

    /* must put at least one value in the floating point register */
    إذا ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    إذا (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    إذا (op >= TOK_ULT && op <= TOK_GT) {
        /* load on stack second operand */
        بارگیری(TREG_ST0, vtop);
        save_reg(TREG_EAX); /* eax is used by FP comparison code */
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
        إذا ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
            بارگیری(TREG_ST0, vtop);
            swapped = !swapped;
        }
        
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
        إذا ((ft & VT_BTYPE) == VT_LDOUBLE) {
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
        } وإلا {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            إذا ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_INT;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = عدم;
                بارگیری(r, &v1);
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
ST_FUNC فراغ gen_cvt_itof(صحيح t)
{
    save_reg(TREG_ST0);
    gv(RC_INT);
    إذا ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
        /* signed long long to float/double/long double (unsigned case
           is handled generically) */
        o(0x50 + vtop->r2); /* push r2 */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
        vtop->r2 = VT_CONST;
    } وإلا إذا ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
               (VT_INT | VT_UNSIGNED)) {
        /* unsigned int to float/double/long double */
        o(0x6a); /* push $0 */
        g(0x00);
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
    } وإلا {
        /* int to float/double/long double */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x2404db); /* fildl (%esp) */
        o(0x04c483); /* add $4, %esp */
    }
    vtop->r2 = VT_CONST;
    vtop->r = TREG_ST0;
}

/* convert fp to int 't' type */
ST_FUNC فراغ gen_cvt_ftoi(صحيح t)
{
    صحيح bt = vtop->type.t & VT_BTYPE;
    إذا (bt == VT_FLOAT)
        vpush_helper_func(TOK___fixsfdi);
    وإلا إذا (bt == VT_LDOUBLE)
        vpush_helper_func(TOK___fixxfdi);
    وإلا
        vpush_helper_func(TOK___fixdfdi);
    vswap();
    gfunc_call(1);
    vpushi(0);
    vtop->r = REG_IRET;
    إذا ((t & VT_BTYPE) == VT_LLONG)
        vtop->r2 = REG_IRE2;
}

/* convert from one floating point type to another */
ST_FUNC فراغ gen_cvt_ftof(صحيح t)
{
    /* all we have to do on i386 is to put the float in a register */
    gv(RC_FLOAT);
}

/* char/short to int conversion */
ST_FUNC فراغ gen_cvt_csti(صحيح t)
{
    صحيح r, sz, xl;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    o(0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (r << 3 | r) << 16
        );
}

/* increment tcov counter */
ST_FUNC فراغ gen_increment_tcov (SValue *sv)
{
   صحيح indir, rel, add1, add2;
#إذا defined CONFIG_TCC_PIC
   get_pc_thunk(TREG_EBX, 0);
   indir = 0x8300;
   rel = R_386_PC32;
   add1 = 2;
   add2 = 13;
#وإلا
   indir = 0x0500;
   rel = R_386_32;
   add1 = 0;
   add2 = 4;
#پایان_اگر
   o(0x0083 + indir); /* addl $1, xxx(%ebx) */
   greloc(cur_متن_section, sv->sym, ind, rel);
   gen_le32(add1);
   o(1);
   o(0x1083 + indir); /* adcl $0, xxx(%ebx) */
   greloc(cur_متن_section, sv->sym, ind, rel);
   gen_le32(add2);
   g(0);
}

/* computed goto support */
ST_FUNC فراغ ggoto(فراغ)
{
    gcall_or_jmp(1);
    vtop--;
}

/* bound check support functions */
#اگر_تعریف_شده CONFIG_TCC_BCHECK

/* Need PIC for shared libraries */
ساكن فراغ gen_bound_call(صحيح v)
{
    Sym *sym;

    sym = external_helper_sym(v);
#إذا defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EBX, 1);
    oad(0xe8, -4);
    greloc(cur_متن_section, sym, ind - 4, R_386_PLT32);
#وإلا
    oad(0xe8, -4);
    greloc(cur_متن_section, sym, ind - 4, R_386_PC32);
#پایان_اگر
}

ساكن فراغ gen_bounds_prolog(فراغ)
{
    /* leave some room for bound checking code */
    func_bound_جابه_جایی = lbounds_section->داده_جابه_جایی;
    func_bound_ind = ind;
    func_bound_جمع_کن_epilog = 0;
#إذا defined CONFIG_TCC_PIC
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0x808d, 0); /* lea lbound section pointer */
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0xc381, 0); /* add _GLOBAL_OFFSET_TABLE_ */
    oad(0xb8, 0); /* call to function */
#وإلا
    oad(0xb8, 0); /* lbound section pointer */
    oad(0xb8, 0); /* call to function */
#پایان_اگر
}

ساكن فراغ gen_bounds_epilog(فراغ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_داده;
    صحيح جابه_جایی_modified = func_bound_جابه_جایی != lbounds_section->داده_جابه_جایی;

    إذا (!جابه_جایی_modified && !func_bound_جمع_کن_epilog)
        أرجع;

    /* add end of table info */
    bounds_ptr = section_ptr_جمع_کن(lbounds_section, حجم(addr_t));
    *bounds_ptr = 0;

    sym_داده = get_sym_ref(&char_اشاره_گر_type, lbounds_section,
                           func_bound_جابه_جایی, PTR_اندازه);

    /* generate bound local allocation */
    إذا (جابه_جایی_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
#إذا defined CONFIG_TCC_PIC
	get_pc_thunk(TREG_EAX, 0);
	o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
	greloc(cur_متن_section, sym_داده, ind, R_386_PC32);
	gen_le32(2);
#وإلا
        greloc(cur_متن_section, sym_داده, ind + 1, R_386_32);
        ind = ind + 5;
#پایان_اگر
        gen_bound_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0x5250); /* save returned value, if any */
#إذا defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EAX, 0);
    o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
    greloc(cur_متن_section, sym_داده, ind, R_386_PC32);
    gen_le32(2);
#وإلا
    greloc(cur_متن_section, sym_داده, ind + 1, R_386_32);
    oad(0xb8, 0); /* mov %eax, xxx */
#پایان_اگر
    gen_bound_call(TOK___bound_local_delete);
    o(0x585a); /* restore returned value, if any */
}
#پایان_اگر

/* Save the stack pointer onto the stack */
ST_FUNC فراغ gen_vla_sp_save(صحيح addr) {
    /* mov %esp,addr(%ebp)*/
    gen_modrm(0x89, TREG_ESP, VT_LOCAL, عدم, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC فراغ gen_vla_sp_restore(صحيح addr) {
    gen_modrm(0x8b, TREG_ESP, VT_LOCAL, عدم, addr);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align) {
    صحيح use_call = 0;

#إذا defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#پایان_اگر
#اگر_تعریف_شده TCC_هدف_PE    /* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#پایان_اگر
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
#پایان_اگر
/*************************************************************/
