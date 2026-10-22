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

#اگر_تعریف_شدہ ہدف_DEFS_ONLY

/* number of available registers */
#تعریف_کرو NB_REGS         5
#تعریف_کرو NB_ASM_REGS     8
#تعریف_کرو CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#تعریف_کرو RC_INT     0x0001 /* generic integer register */
#تعریف_کرو RC_FLOAT   0x0002 /* generic float register */
#تعریف_کرو RC_EAX     0x0004
#تعریف_کرو RC_EDX     0x0008
#تعریف_کرو RC_ECX     0x0010
#تعریف_کرو RC_EBX     0x0020
#تعریف_کرو RC_ST0     0x0040

#تعریف_کرو RC_IRET    RC_EAX /* function return: integer register */
#تعریف_کرو RC_IRE2    RC_EDX /* function return: second integer register */
#تعریف_کرو RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
شمار {
    TREG_EAX = 0,
    TREG_ECX,
    TREG_EDX,
    TREG_EBX,
    TREG_ST0,
    TREG_ESP = 4,
    TREG_MEM = 0x20
};

#تعریف_کرو REG_قدر(reg) ((reg) & 7)

/* return registers for function */
#تعریف_کرو REG_IRET TREG_EAX /* single word int return register */
#تعریف_کرو REG_IRE2 TREG_EDX /* second word return register (for long long) */
#تعریف_کرو REG_FRET TREG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
#تعریف_کرو INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#تعریف_کرو PTR_سائز 4

/* long double size and alignment, in bytes */
#تعریف_کرو LDOUBLE_سائز  12
#تعریف_کرو LDOUBLE_ALIGN 4
/* maximum alignment (for aligned attribute support) */
#تعریف_کرو MAX_ALIGN     8

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#تعریف_کرو PROMOTE_RET

/******************************************************/
#ورنہ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"

ST_ڈیٹا ثابت حرف * ثابت ہدف_machine_defs =
    "__i386__\0"
    "__i386\0"
    ;

#اگر defined CONFIG_TCC_PIC
# define USE_EBX 2
#ورنہ
# define USE_EBX 0 /* define to 1 to have EBX as 4th register */
#اگر_ختم

ST_ڈیٹا ثابت صحیح reg_classes[NB_REGS] = {
    /* eax */ RC_INT | RC_EAX,
    /* ecx */ RC_INT | RC_ECX,
    /* edx */ RC_INT | RC_EDX,
    /* ebx */ (RC_INT | RC_EBX) * (USE_EBX == 1),
    /* st0 */ RC_FLOAT | RC_ST0,
};

ساکن غیرعلامتی طویل func_sub_sp_انحراف;
ساکن صحیح func_ret_sub;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
ساکن addr_t func_bound_انحراف;
ساکن غیرعلامتی طویل func_bound_ind;
ST_ڈیٹا صحیح func_bound_جوڑو_epilog;
ساکن خالی gen_bounds_prolog(خالی);
ساکن خالی gen_bounds_epilog(خالی);
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

/* output a symbol and patch all calls to it */
ST_FUNC خالی gsym_addr(صحیح t, صحیح a)
{
    جب (t) {
        غیرعلامتی حرف *ptr = cur_متن_section->ڈیٹا + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a - t - 4);
        t = n;
    }
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

ST_FUNC خالی gen_fill_nops(صحیح بائٹیں)
{
    جب (بائٹیں--)
      g(0x90);
}

#اگر defined CONFIG_TCC_PIC
ساکن خالی gen_static_call(صحیح v);
ساکن خالی get_pc_thunk(صحیح r, صحیح جوڑو)
{
    ساکن ثابت حرف * ثابت pc_thunk_name[] = {
	"__x86.get_pc_thunk.ax",
	"__x86.get_pc_thunk.cx",
	"__x86.get_pc_thunk.dx",
	"__x86.get_pc_thunk.bx"
    };
    اگر (nocode_wanted)
        واپس;
    gen_static_call(tok_alloc_const(pc_thunk_name[r]));
    اگر (جوڑو) {
        Sym label = {0};
        label.type.t = VT_VOID|VT_STATIC;
        put_extern_sym(&label, cur_متن_section, ind, 0);
        r = REG_قدر(r);
	اگر (r == 0)
	    oad(0x05, 1); /* add _GLOBAL_OFFSET_TABLE_, %eax */
	ورنہ
            oad(0xc081 + r * 0x100, 2); /* add _GLOBAL_OFFSET_TABLE_, %erx */
        greloc(cur_متن_section, &label, ind - 4, R_386_GOTPC);
    }
}

ST_FUNC خالی gen_gotpcrel(صحیح r, Sym *sym, صحیح c)
{
    greloc(cur_متن_section, sym, ind, R_386_GOT32X);
    gen_le32(0);
    اگر (c) {
	r = REG_قدر(r);
	اگر (r == 0)
            oad(0x05, c);
	ورنہ
            oad(0xc081 + r * 0x100, c);
    }
}
#اگر_ختم

/* generate jmp to a label */
#تعریف_کرو gjmp2(instr,lbl) oad(instr,lbl)

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC خالی gen_addr32(صحیح r, Sym *sym, صحیح c)
{
    اگر (r & VT_SYM)
        greloc(cur_متن_section, sym, ind, R_386_32);
    gen_le32(c);
}

ST_FUNC خالی gen_addrpc32(صحیح r, Sym *sym, صحیح c)
{
    اگر (r & VT_SYM)
        greloc(cur_متن_section, sym, ind, R_386_PC32);
    gen_le32(c - 4);
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode bits */
ساکن خالی gen_modrm(صحیح opc, صحیح op_r2, صحیح r, Sym *sym, صحیح c)
{
    صحیح op_reg = REG_قدر(op_r2) << 3;

    اگر ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#اگر_تعریف_شدہ TCC_ہدف_PE
        Sym *s2 = external_global_sym(TOK_tls_اشاریہ, &int_type);
        r = get_reg(RC_INT);
        gen_modrm(0x8b, r, VT_SYM|VT_CONST, s2, 0); /* mov __tls_index, r */
        o(0x02e0c1 | r << 8); /* shl 2,r */
        oad(0x050364 | r << 19, 11*PTR_سائز); /* add fs:0x2c,r */
        gen_modrm(0x8b, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        o(opc), oad(0x80 | op_reg | r, c); /* mov #c(r),op_reg */
        greloc(cur_متن_section, sym, ind - 4, R_386_TLS_LE);
#ورنہ
        o(0x65); /* gs segment prefix */
        o(opc), oad(0x05 | op_reg, c);
        greloc(cur_متن_section, sym, ind - 4, R_386_TLS_LE);
#اگر_ختم
#اگر defined CONFIG_TCC_PIC
    } ورنہ اگر ((r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
        صحیح is_got = (op_r2 & TREG_MEM) && !(sym->type.t & VT_STATIC);
        صحیح یہاں = ind;
        get_pc_thunk(TREG_EBX, is_got);
        o(opc);
        o(0x83 | op_reg);
        اگر (is_got) {
            gen_gotpcrel(r, sym, c);
        } ورنہ {
            gen_addrpc32(r, sym, c + (ind - یہاں - 1));
        }
    } ورنہ اگر ((r & VT_VALMASK) < VT_CONST && (r & TREG_MEM)) {
        o(opc);
        اگر (c) {
            g(0x80 | op_reg | REG_قدر(r));
            gen_le32(c);
        } ورنہ {
            g(0x00 | op_reg | REG_قدر(r));
        }
#اگر_ختم
    } ورنہ اگر ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
        o(opc);
        o(0x05 | op_reg);
        gen_addr32(r, sym, c);
    } ورنہ اگر ((r & VT_VALMASK) == VT_LOCAL) {
	o(opc);
        /* currently, we use only ebp as base */
        اگر (c == (علامتی حرف)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } ورنہ {
            oad(0x85 | op_reg, c);
        }
    } ورنہ {
	o(opc);
        g(0x00 | op_reg | (r & VT_VALMASK));
    }
}

/* load 'r' from value 'sv' */
ST_FUNC خالی بھرو(صحیح r, SValue *sv)
{
    صحیح v, t, ft, fc, fr, opc;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~VT_DEFSIGN;
    fc = sv->c.i;
    ft &= ~VT_QUAL;
    v = fr & VT_VALMASK;

#اگر defined CONFIG_TCC_PIC
    /* we use indirect access via got */
    اگر ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        صحیح tr = r | TREG_MEM;
        اگر (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm(0x8b, tr, fr, sv->sym, 0);
        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#اگر_ختم

    اگر (fr & VT_LVAL) {
        اگر (v == VT_LLOCAL) {
            v1.type.t = VT_INT;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
            v1.sym = تہی;
            fr = r;
            اگر (!(reg_classes[fr] & RC_INT))
                fr = get_reg(RC_INT);
            بھرو(fr, &v1);
        }
        اگر ((ft & VT_BTYPE) == VT_FLOAT) {
            opc = 0xd9; /* flds */
            r = 0;
        } ورنہ اگر ((ft & VT_BTYPE) == VT_DOUBLE) {
            opc = 0xdd; /* fldl */
            r = 0;
        } ورنہ اگر ((ft & VT_BTYPE) == VT_LDOUBLE) {
            opc = 0xdb; /* fldt */
            r = 5;
        } ورنہ اگر ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            opc = 0xbe0f;   /* movsbl */
        } ورنہ اگر ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED) ||
		   (ft & VT_TYPE) == (VT_BOOL | VT_UNSIGNED)) {
            opc = 0xb60f;   /* movzbl */
        } ورنہ اگر ((ft & VT_TYPE) == VT_SHORT) {
            opc = 0xbf0f;   /* movswl */
        } ورنہ اگر ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            opc = 0xb70f;   /* movzwl */
        } ورنہ {
            opc = 0x8b;     /* movl */
        }
        gen_modrm(opc, r, fr, sv->sym, fc);
    } ورنہ {
        اگر ((fr & VT_SYM) && (sv->sym->type.t & VT_TLS)) {
#اگر_تعریف_شدہ TCC_ہدف_PE
            gen_modrm(0x8d, r, fr, sv->sym, fc);
#ورنہ
            oad(0x058b65 | REG_قدر(r) << 19, 0); /* mov gs:0,r */
            oad(0xC081 | REG_قدر(r) << 8, fc); /* add tpoffs,r */
            greloc(cur_متن_section, sv->sym, ind - 4, R_386_TLS_LE);
#اگر_ختم
#اگر defined CONFIG_TCC_PIC
        } ورنہ اگر ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
            اگر (sv->sym->type.t & VT_STATIC) {
                get_pc_thunk(r, 0);
                o(0x808d | REG_قدر(r) * 0x900); /* lea $xx(r), r */
                gen_addrpc32(fr, sv->sym, fc + 6);
            } ورنہ {
                get_pc_thunk(r, 1);
                o(0x808b | REG_قدر(r) * 0x900); /* mov $xx(r), r */
                gen_gotpcrel(r, sv->sym, fc);
            }
#اگر_ختم
        } ورنہ اگر (v == VT_CONST) {
            o(0xb8 + r); /* mov $xx, r */
            gen_addr32(fr, sv->sym, fc);
        } ورنہ اگر (v == VT_LOCAL) {
            اگر (fc) {
                /* lea xxx(%ebp), r */
                gen_modrm(0x8d, r, VT_LOCAL, sv->sym, fc);
            } ورنہ {
                o(0x89);
                o(0xe8 + r); /* mov %ebp, r */
            }
        } ورنہ اگر (v == VT_CMP) {
            o(0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + r);
            o(0xc0b60f + r * 0x90000); /* movzbl %al, %eax */
        } ورنہ اگر (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            oad(0xb8 + r, t); /* mov $1, r */
            o(0x05eb); /* jmp after */
            gsym(fc);
            oad(0xb8 + r, t ^ 1); /* mov $0, r */
        } ورنہ اگر (v != r) {
            o(0x89);
            o(0xc0 + r + v * 8); /* mov v, r */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ST_FUNC خالی store(صحیح r, SValue *v)
{
    صحیح fr, bt, fc, opc;

    bt = v->type.t & VT_BTYPE;

    /* XXX: incorrect if float reg to reg */
    اگر (bt == VT_FLOAT) {
        opc = 0xd9; /* fsts */
        r = 2;
    } ورنہ اگر (bt == VT_DOUBLE) {
        opc = 0xdd; /* fstpl */
        r = 2;
    } ورنہ اگر (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0), fstpt */
        opc = 0xdb;
        r = 7;
    } ورنہ اگر (bt == VT_SHORT) {
        opc = 0x8966;
    } ورنہ اگر (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } ورنہ {
        opc = 0x89;
    }

    fc = v->c.i;
    fr = v->r & VT_VALMASK;

#اگر defined CONFIG_TCC_PIC
    /* we need to access the variable via got */
    اگر ((v->r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
	get_pc_thunk(TREG_EBX, 1);
	o(0x9b8b); /* mov xx(%ebx),%ebx */
	gen_gotpcrel(TREG_EBX, v->sym, v->c.i);
	o(opc);
	o(3 + (r << 3));
    } ورنہ
#اگر_ختم

    اگر (fr == VT_CONST || fr == VT_LOCAL || (v->r & VT_LVAL)) {
        gen_modrm(opc, r, v->r, v->sym, fc);
    } ورنہ اگر (fr != r) {
	o(opc);
        o(0xc0 + fr + r * 8); /* mov r, fr */
    }
}

ساکن خالی gadd_sp(صحیح val)
{
    اگر (val == (علامتی حرف)val) {
        o(0xc483);
        g(val);
    } ورنہ {
        oad(0xc481, val); /* add $xxx, %esp */
    }
}

#اگر defined TCC_ہدف_PE || defined CONFIG_TCC_PIC
ساکن خالی gen_static_call(صحیح v)
{
    Sym *sym;

    sym = external_helper_sym(v);
    oad(0xe8, -4);
    greloc(cur_متن_section, sym, ind - 4, R_386_PC32);
}
#اگر_ختم

/* 'is_jmp' is '1' if it is a jump */
ساکن خالی gcall_or_jmp(صحیح is_jmp)
{
    صحیح r;
    اگر ((vtop->r & (VT_VALMASK|VT_LVAL|VT_SYM)) == (VT_CONST|VT_SYM)) {
        /* constant and relocation case */
#اگر defined CONFIG_TCC_PIC
	اگر (!(vtop->sym->type.t & VT_STATIC)) {
	    get_pc_thunk(TREG_EBX, 1);
            oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
            greloc(cur_متن_section, vtop->sym, ind - 4, R_386_PLT32);
            واپس;
	}
#اگر_ختم
        oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
        greloc(cur_متن_section, vtop->sym, ind - 4, R_386_PC32);
    } ورنہ {
        /* otherwise, indirect call */
        r = gv(RC_INT);
        o(0xff); /* call/jmp *r */
        o(0xd0 + r + (is_jmp << 4));
    }
}

ساکن ثابت uint8_t fastcall_regs[3] = { TREG_EAX, TREG_EDX, TREG_ECX };
ساکن ثابت uint8_t fastcallw_regs[2] = { TREG_ECX, TREG_EDX };

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحیح gfunc_sret(CType *vt, صحیح variadic, CType *ret, صحیح *ret_align, صحیح *regsize)
{
#اگر defined(TCC_ہدف_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    صحیح سائز, align, nregs;
    *ret_align = 1; // Never have to re-align return values for x86
    *regsize = 4;
    سائز = type_سائز(vt, &align);
    اگر (سائز > 8 || (سائز & (سائز - 1)))
        واپس 0;
    nregs = 1;
    اگر (سائز == 8)
        ret->t = VT_INT, nregs = 2;
    ورنہ اگر (سائز == 4)
        ret->t = VT_INT;
    ورنہ اگر (سائز == 2)
        ret->t = VT_SHORT;
    ورنہ
        ret->t = VT_BYTE;
    ret->ref = تہی;
    واپس nregs;
#ورنہ
    *ret_align = 1; // Never have to re-align return values for x86
    واپس 0;
#اگر_ختم
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ST_FUNC خالی gfunc_call(صحیح nb_دلائل)
{
    صحیح سائز, align, r, دلائل_سائز, i, func_call;
    Sym *func_sym;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gbound_دلائل(nb_دلائل);
#اگر_ختم

    save_regs(nb_دلائل + 1);

    دلائل_سائز = 0;
    برائے(i = 0;i < nb_دلائل; i++) {
        اگر ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
            سائز = type_سائز(&vtop->type, &align);
            /* align to stack align size */
            سائز = (سائز + 3) & ~3;
            /* allocate the necessary size on stack */
#اگر_تعریف_شدہ TCC_ہدف_PE
            اگر (سائز >= 4096) {
                save_reg(TREG_EDX);
                r = get_reg(RC_EAX);
                oad(0x68, سائز); // push size
                /* cannot call normal 'alloca' with bound checking */
                gen_static_call(tok_alloc_const("__alloca"));
                gadd_sp(4);
            } ورنہ
#اگر_ختم
            {
                oad(0xec81, سائز); /* sub $xxx, %esp */
                /* generate structure store */
                r = get_reg(RC_INT);
                o(0xe089 + (r << 8)); /* mov %esp, r */
            }
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            دلائل_سائز += سائز;
        } ورنہ اگر (is_float(vtop->type.t)) {
            gv(RC_FLOAT); /* only one float register */
            اگر ((vtop->type.t & VT_BTYPE) == VT_FLOAT)
                سائز = 4;
            ورنہ اگر ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                سائز = 8;
            ورنہ
                سائز = 12;
            oad(0xec81, سائز); /* sub $xxx, %esp */
            اگر (سائز == 12)
                o(0x7cdb);
            ورنہ
                o(0x5cd9 + سائز - 4); /* fstp[s|l] 0(%esp) */
            g(0x24);
            g(0x00);
            دلائل_سائز += سائز;
        } ورنہ {
            /* simple type (currently always same size) */
            /* XXX: implicit cast ? */
            r = gv(RC_INT);
            اگر ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
                سائز = 8;
                o(0x50 + vtop->r2); /* push r */
            } ورنہ {
                سائز = 4;
            }
            o(0x50 + r); /* push r */
            دلائل_سائز += سائز;
        }
        vtop--;
    }

    func_sym = vtop->type.ref;
    func_call = func_sym->f.func_call;
    /* fast call case */
    اگر ((func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) ||
        func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL) {
        صحیح fastcall_nb_regs;
        ثابت uint8_t *fastcall_regs_ptr;
        اگر (func_call == FUNC_FASTCALLW) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 2;
        } ورنہ اگر (func_call == FUNC_THISCALL) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 1;
        } ورنہ {
            fastcall_regs_ptr = fastcall_regs;
            fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        }
        برائے(i = 0;i < fastcall_nb_regs; i++) {
            اگر (دلائل_سائز <= 0)
                توڑو;
            o(0x58 + fastcall_regs_ptr[i]); /* pop r */
            /* XXX: incorrect for struct/floats */
            دلائل_سائز -= 4;
        }
    }
#اگر !defined(TCC_ہدف_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    ورنہ اگر ((vtop->type.ref->type.t & VT_BTYPE) == VT_STRUCT)
        دلائل_سائز -= 4;
#اگر_ختم

    gcall_or_jmp(0);

    اگر (دلائل_سائز && func_call != FUNC_STDCALL && func_call != FUNC_THISCALL && func_call != FUNC_FASTCALLW)
        gadd_sp(دلائل_سائز);
    vtop--;
}

#اگر_تعریف_شدہ TCC_ہدف_PE
#تعریف_کرو FUNC_PROLOG_سائز (10 + !!USE_EBX)
#ورنہ
#تعریف_کرو FUNC_PROLOG_سائز (9 + !!USE_EBX)
#اگر_ختم

/* generate function prolog of type 't' */
ST_FUNC خالی gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    صحیح addr, align, سائز, func_call, fastcall_nb_regs;
    صحیح param_اشاریہ, param_addr;
    ثابت uint8_t *fastcall_regs_ptr;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    func_call = sym->f.func_call;
    addr = 8;
    loc = 0;
    func_vc = 0;

    اگر (func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) {
        fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        fastcall_regs_ptr = fastcall_regs;
    } ورنہ اگر (func_call == FUNC_FASTCALLW) {
        fastcall_nb_regs = 2;
        fastcall_regs_ptr = fastcallw_regs;
    } ورنہ اگر (func_call == FUNC_THISCALL) {
        fastcall_nb_regs = 1;
        fastcall_regs_ptr = fastcallw_regs;
    } ورنہ {
        fastcall_nb_regs = 0;
        fastcall_regs_ptr = تہی;
    }
    param_اشاریہ = 0;

    ind += FUNC_PROLOG_سائز;
    func_sub_sp_انحراف = ind;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
#اگر defined(TCC_ہدف_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    سائز = type_سائز(&func_vt,&align);
    اگر (((func_vt.t & VT_BTYPE) == VT_STRUCT)
        && (سائز > 8 || (سائز & (سائز - 1)))) {
#ورنہ
    اگر ((func_vt.t & VT_BTYPE) == VT_STRUCT) {
#اگر_ختم
        /* XXX: fastcall case ? */
        func_vc = addr;
        addr += 4;
        param_اشاریہ++;
    }
    /* define parameters */
    جب ((sym = sym->اگلا) != تہی) {
        type = &sym->type;
        سائز = type_سائز(type, &align);
        سائز = (سائز + 3) & ~3;
#اگر_تعریف_شدہ FUNC_STRUCT_PARAM_AS_PTR
        /* structs are passed as pointer */
        اگر ((type->t & VT_BTYPE) == VT_STRUCT) {
            سائز = 4;
        }
#اگر_ختم
        اگر (param_اشاریہ < fastcall_nb_regs) {
            /* save FASTCALL register */
            loc -= 4;
            /* movl */
            gen_modrm(0x89, fastcall_regs_ptr[param_اشاریہ], VT_LOCAL, تہی, loc);
            param_addr = loc;
        } ورنہ {
            param_addr = addr;
            addr += سائز;
        }
        gfunc_سیٹ_param(sym, param_addr, 0);
        param_اشاریہ++;
    }
    func_ret_sub = 0;
    /* pascal type call or fastcall ? */
    اگر (func_call == FUNC_STDCALL || func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL)
        func_ret_sub = addr - 8;
#اگر !defined(TCC_ہدف_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    ورنہ اگر (func_vc)
        func_ret_sub = 4;
#اگر_ختم

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#اگر_ختم
}

/* generate function epilog */
ST_FUNC خالی gfunc_epilog(خالی)
{
    addr_t v, saved_ind;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#اگر_ختم

    /* align local size to word & save local variables */
    v = (-loc + 3) & -4;

#اگر USE_EBX
    gen_modrm(0x8b, TREG_EBX, VT_LOCAL, تہی, -(v+4));
#اگر_ختم

    o(0xc9); /* leave */
    اگر (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } ورنہ {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    saved_ind = ind;
    ind = func_sub_sp_انحراف - FUNC_PROLOG_سائز;
#اگر_تعریف_شدہ TCC_ہدف_PE
    اگر (v >= 4096) {
        oad(0xb8, v); /* mov stacksize, %eax */
        gen_static_call(TOK___chkstk); /* call __chkstk, (does the stackframe too) */
    } ورنہ
#اگر_ختم
    {
        o(0xe58955);  /* push %ebp, mov %esp, %ebp */
        o(0xec81);  /* sub esp, stacksize */
        gen_le32(v);
#اگر_تعریف_شدہ TCC_ہدف_PE
        o(0x90);  /* adjust to FUNC_PROLOG_SIZE */
#اگر_ختم
    }
#اگر USE_EBX
    o(0x53); /* push ebx */
#اگر_ختم
    ind = saved_ind;
}

/* generate a jump to a label */
ST_FUNC صحیح gjmp(صحیح t)
{
    واپس gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ST_FUNC خالی gjmp_addr(صحیح a)
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

#اگر 0
/* generate a jump to a fixed address */
ST_FUNC خالی gjmp_cond_addr(صحیح a, صحیح op)
{
    صحیح r = a - ind - 2;
    اگر (r == (علامتی حرف)r)
        g(op - 32), g(r);
    ورنہ
        g(0x0f), gjmp2(op - 16, r - 4);
}
#اگر_ختم

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
    g(0x0f);
    t = gjmp2(op - 16, t);
    واپس t;
}

ST_FUNC خالی gen_opi(صحیح op)
{
    صحیح r, fr, opc, c;

    انتخاب(op) {
    حالت '+':
    حالت TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        اگر ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            اگر (c == (علامتی حرف)c) {
                /* generate inc and dec for smaller code */
                اگر ((c == 1 || c == -1) && (op == '+' || op == '-')) {
                    opc = (c == 1) ^ (op == '+');
                    o (0x40 | (opc << 3) | r); // inc,dec
                } ورنہ {
                    o(0x83);
                    o(0xc0 | (opc << 3) | r);
                    g(c);
                }
            } ورنہ {
                o(0x81);
                oad(0xc0 | (opc << 3) | r, c);
            }
        } ورنہ {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            o((opc << 3) | 0x01);
            o(0xc0 + r + fr * 8); 
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
        vtop--;
        o(0xaf0f); /* imul fr, r */
        o(0xc0 + fr + r * 8);
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
        اگر ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i & 0x1f;
            o(0xc1); /* shl/shr/sar $xxx, r */
            o(opc | r);
            g(c);
        } ورنہ {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_ECX);
            r = vtop[-1].r;
            o(0xd3); /* shl/shr/sar %cl, r */
            o(opc | r);
        }
        vtop--;
        توڑو;
    حالت '/':
    حالت TOK_UDIV:
    حالت TOK_PDIV:
    حالت '%':
    حالت TOK_UMOD:
    حالت TOK_UMULL:
        /* first operand must be in eax */
        /* XXX: need better constraint for second operand */
        gv2(RC_EAX, RC_ECX);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        save_reg(TREG_EDX);
        /* save EAX too if used otherwise */
        save_reg_upstack(TREG_EAX, 1);
        اگر (op == TOK_UMULL) {
            o(0xf7); /* mul fr */
            o(0xe0 + fr);
            vtop->r2 = TREG_EDX;
            r = TREG_EAX;
        } ورنہ {
            اگر (op == TOK_UDIV || op == TOK_UMOD) {
                o(0xf7d231); /* xor %edx, %edx, div fr, %eax */
                o(0xf0 + fr);
            } ورنہ {
                o(0xf799); /* cltd, idiv fr, %eax */
                o(0xf8 + fr);
            }
            اگر (op == '%' || op == TOK_UMOD)
                r = TREG_EDX;
            ورنہ
                r = TREG_EAX;
        }
        vtop->r = r;
        توڑو;
    طےشدہ:
        opc = 7;
        جاؤ gen_op8;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ST_FUNC خالی gen_opf(صحیح op)
{
    صحیح a, ft, fc, swapped, r;

    اگر (op == TOK_NEG) { /* unary minus */
        gv(RC_FLOAT);
        o(0xe0d9); /* fchs */
        واپس;
    }

    /* convert constants to memory references */
    اگر ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    اگر ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(RC_FLOAT);

    /* must put at least one value in the floating point register */
    اگر ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    اگر (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    اگر (op >= TOK_ULT && op <= TOK_GT) {
        /* load on stack second operand */
        بھرو(TREG_ST0, vtop);
        save_reg(TREG_EAX); /* eax is used by FP comparison code */
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
        اگر ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
            بھرو(TREG_ST0, vtop);
            swapped = !swapped;
        }
        
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
        اگر ((ft & VT_BTYPE) == VT_LDOUBLE) {
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
        } ورنہ {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            اگر ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_INT;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = تہی;
                بھرو(r, &v1);
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
ST_FUNC خالی gen_cvt_itof(صحیح t)
{
    save_reg(TREG_ST0);
    gv(RC_INT);
    اگر ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
        /* signed long long to float/double/long double (unsigned case
           is handled generically) */
        o(0x50 + vtop->r2); /* push r2 */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
        vtop->r2 = VT_CONST;
    } ورنہ اگر ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
               (VT_INT | VT_UNSIGNED)) {
        /* unsigned int to float/double/long double */
        o(0x6a); /* push $0 */
        g(0x00);
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
    } ورنہ {
        /* int to float/double/long double */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x2404db); /* fildl (%esp) */
        o(0x04c483); /* add $4, %esp */
    }
    vtop->r2 = VT_CONST;
    vtop->r = TREG_ST0;
}

/* convert fp to int 't' type */
ST_FUNC خالی gen_cvt_ftoi(صحیح t)
{
    صحیح bt = vtop->type.t & VT_BTYPE;
    اگر (bt == VT_FLOAT)
        vpush_helper_func(TOK___fixsfdi);
    ورنہ اگر (bt == VT_LDOUBLE)
        vpush_helper_func(TOK___fixxfdi);
    ورنہ
        vpush_helper_func(TOK___fixdfdi);
    vswap();
    gfunc_call(1);
    vpushi(0);
    vtop->r = REG_IRET;
    اگر ((t & VT_BTYPE) == VT_LLONG)
        vtop->r2 = REG_IRE2;
}

/* convert from one floating point type to another */
ST_FUNC خالی gen_cvt_ftof(صحیح t)
{
    /* all we have to do on i386 is to put the float in a register */
    gv(RC_FLOAT);
}

/* char/short to int conversion */
ST_FUNC خالی gen_cvt_csti(صحیح t)
{
    صحیح r, sz, xl;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    o(0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (r << 3 | r) << 16
        );
}

/* increment tcov counter */
ST_FUNC خالی gen_increment_tcov (SValue *sv)
{
   صحیح indir, rel, add1, add2;
#اگر defined CONFIG_TCC_PIC
   get_pc_thunk(TREG_EBX, 0);
   indir = 0x8300;
   rel = R_386_PC32;
   add1 = 2;
   add2 = 13;
#ورنہ
   indir = 0x0500;
   rel = R_386_32;
   add1 = 0;
   add2 = 4;
#اگر_ختم
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
ST_FUNC خالی ggoto(خالی)
{
    gcall_or_jmp(1);
    vtop--;
}

/* bound check support functions */
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK

/* Need PIC for shared libraries */
ساکن خالی gen_bound_call(صحیح v)
{
    Sym *sym;

    sym = external_helper_sym(v);
#اگر defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EBX, 1);
    oad(0xe8, -4);
    greloc(cur_متن_section, sym, ind - 4, R_386_PLT32);
#ورنہ
    oad(0xe8, -4);
    greloc(cur_متن_section, sym, ind - 4, R_386_PC32);
#اگر_ختم
}

ساکن خالی gen_bounds_prolog(خالی)
{
    /* leave some room for bound checking code */
    func_bound_انحراف = lbounds_section->ڈیٹا_انحراف;
    func_bound_ind = ind;
    func_bound_جوڑو_epilog = 0;
#اگر defined CONFIG_TCC_PIC
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0x808d, 0); /* lea lbound section pointer */
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0xc381, 0); /* add _GLOBAL_OFFSET_TABLE_ */
    oad(0xb8, 0); /* call to function */
#ورنہ
    oad(0xb8, 0); /* lbound section pointer */
    oad(0xb8, 0); /* call to function */
#اگر_ختم
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
#اگر defined CONFIG_TCC_PIC
	get_pc_thunk(TREG_EAX, 0);
	o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
	greloc(cur_متن_section, sym_ڈیٹا, ind, R_386_PC32);
	gen_le32(2);
#ورنہ
        greloc(cur_متن_section, sym_ڈیٹا, ind + 1, R_386_32);
        ind = ind + 5;
#اگر_ختم
        gen_bound_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0x5250); /* save returned value, if any */
#اگر defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EAX, 0);
    o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
    greloc(cur_متن_section, sym_ڈیٹا, ind, R_386_PC32);
    gen_le32(2);
#ورنہ
    greloc(cur_متن_section, sym_ڈیٹا, ind + 1, R_386_32);
    oad(0xb8, 0); /* mov %eax, xxx */
#اگر_ختم
    gen_bound_call(TOK___bound_local_delete);
    o(0x585a); /* restore returned value, if any */
}
#اگر_ختم

/* Save the stack pointer onto the stack */
ST_FUNC خالی gen_vla_sp_save(صحیح addr) {
    /* mov %esp,addr(%ebp)*/
    gen_modrm(0x89, TREG_ESP, VT_LOCAL, تہی, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC خالی gen_vla_sp_restore(صحیح addr) {
    gen_modrm(0x8b, TREG_ESP, VT_LOCAL, تہی, addr);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC خالی gen_vla_alloc(CType *type, صحیح align) {
    صحیح use_call = 0;

#اگر defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_PE    /* alloca does more than just adjust %rsp on Windows */
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
#اگر_ختم
/*************************************************************/
