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

#ifdef TARGET_DEFS_ONLY

/* number of available registers */
#define NB_REGS         5
#define NB_ASM_REGS     8
#define CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#define RC_INT     0x0001 /* generic integer register */
#define RC_FLOAT   0x0002 /* generic float register */
#define RC_EAX     0x0004
#define RC_EDX     0x0008
#define RC_ECX     0x0010
#define RC_EBX     0x0020
#define RC_ST0     0x0040

#define RC_IRET    RC_EAX /* function return: integer register */
#define RC_IRE2    RC_EDX /* function return: second integer register */
#define RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
गणना {
    TREG_EAX = 0,
    TREG_ECX,
    TREG_EDX,
    TREG_EBX,
    TREG_ST0,
    TREG_ESP = 4,
    TREG_MEM = 0x20
};

#define REG_मूल्य(reg) ((reg) & 7)

/* return registers for function */
#define REG_IRET TREG_EAX /* single word int return register */
#define REG_IRE2 TREG_EDX /* second word return register (for long long) */
#define REG_FRET TREG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
#define INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#define PTR_SIZE 4

/* long double size and alignment, in bytes */
#define LDOUBLE_SIZE  12
#define LDOUBLE_ALIGN 4
/* maximum alignment (for aligned attribute support) */
#define MAX_ALIGN     8

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#define PROMOTE_RET

/******************************************************/
#अन्यथा /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#अन्तर्भाव "tcc.h"

ST_DATA स्थिरांक अक्षर * स्थिरांक target_machine_defs =
    "__i386__\0"
    "__i386\0"
    ;

#जर defined CONFIG_TCC_PIC
# define USE_EBX 2
#अन्यथा
# define USE_EBX 0 /* define to 1 to have EBX as 4th register */
#endif

ST_DATA स्थिरांक पूर्णांक reg_classes[NB_REGS] = {
    /* eax */ RC_INT | RC_EAX,
    /* ecx */ RC_INT | RC_ECX,
    /* edx */ RC_INT | RC_EDX,
    /* ebx */ (RC_INT | RC_EBX) * (USE_EBX == 1),
    /* st0 */ RC_FLOAT | RC_ST0,
};

स्थिर अचिन्हित दीर्घ func_sub_sp_offset;
स्थिर पूर्णांक func_ret_sub;
#ifdef CONFIG_TCC_BCHECK
स्थिर addr_t func_bound_offset;
स्थिर अचिन्हित दीर्घ func_bound_ind;
ST_DATA पूर्णांक func_bound_add_epilog;
स्थिर शून्य gen_bounds_prolog(शून्य);
स्थिर शून्य gen_bounds_epilog(शून्य);
#endif

/* XXX: make it faster ? */
ST_FUNC शून्य g(पूर्णांक c)
{
    पूर्णांक ind1;
    जर (nocode_wanted)
        परत;
    ind1 = ind + 1;
    जर (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC शून्य o(अचिन्हित पूर्णांक c)
{
    पर्यंत (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC शून्य gen_le16(पूर्णांक v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC शून्य gen_le32(पूर्णांक c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

/* output a symbol and patch all calls to it */
ST_FUNC शून्य gsym_addr(पूर्णांक t, पूर्णांक a)
{
    पर्यंत (t) {
        अचिन्हित अक्षर *ptr = cur_text_section->data + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a - t - 4);
        t = n;
    }
}

/* instruction + 4 bytes data. Return the address of the data */
स्थिर पूर्णांक oad(पूर्णांक c, पूर्णांक s)
{
    पूर्णांक t;
    जर (nocode_wanted)
        परत s;
    o(c);
    t = ind;
    gen_le32(s);
    परत t;
}

ST_FUNC शून्य gen_fill_nops(पूर्णांक bytes)
{
    पर्यंत (bytes--)
      g(0x90);
}

#जर defined CONFIG_TCC_PIC
स्थिर शून्य gen_static_call(पूर्णांक v);
स्थिर शून्य get_pc_thunk(पूर्णांक r, पूर्णांक add)
{
    स्थिर स्थिरांक अक्षर * स्थिरांक pc_thunk_name[] = {
	"__x86.get_pc_thunk.ax",
	"__x86.get_pc_thunk.cx",
	"__x86.get_pc_thunk.dx",
	"__x86.get_pc_thunk.bx"
    };
    जर (nocode_wanted)
        परत;
    gen_static_call(tok_alloc_const(pc_thunk_name[r]));
    जर (add) {
        Sym label = {0};
        label.type.t = VT_VOID|VT_STATIC;
        put_extern_sym(&label, cur_text_section, ind, 0);
        r = REG_मूल्य(r);
	जर (r == 0)
	    oad(0x05, 1); /* add _GLOBAL_OFFSET_TABLE_, %eax */
	अन्यथा
            oad(0xc081 + r * 0x100, 2); /* add _GLOBAL_OFFSET_TABLE_, %erx */
        greloc(cur_text_section, &label, ind - 4, R_386_GOTPC);
    }
}

ST_FUNC शून्य gen_gotpcrel(पूर्णांक r, Sym *sym, पूर्णांक c)
{
    greloc(cur_text_section, sym, ind, R_386_GOT32X);
    gen_le32(0);
    जर (c) {
	r = REG_मूल्य(r);
	जर (r == 0)
            oad(0x05, c);
	अन्यथा
            oad(0xc081 + r * 0x100, c);
    }
}
#endif

/* generate jmp to a label */
#define gjmp2(instr,lbl) oad(instr,lbl)

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC शून्य gen_addr32(पूर्णांक r, Sym *sym, पूर्णांक c)
{
    जर (r & VT_SYM)
        greloc(cur_text_section, sym, ind, R_386_32);
    gen_le32(c);
}

ST_FUNC शून्य gen_addrpc32(पूर्णांक r, Sym *sym, पूर्णांक c)
{
    जर (r & VT_SYM)
        greloc(cur_text_section, sym, ind, R_386_PC32);
    gen_le32(c - 4);
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode bits */
स्थिर शून्य gen_modrm(पूर्णांक opc, पूर्णांक op_r2, पूर्णांक r, Sym *sym, पूर्णांक c)
{
    पूर्णांक op_reg = REG_मूल्य(op_r2) << 3;

    जर ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#ifdef TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK___tls_index, &int_type);
        r = get_reg(RC_INT);
        gen_modrm(0x8b, r, VT_SYM|VT_CONST, s2, 0); /* mov __tls_index, r */
        o(0x02e0c1 | r << 8); /* shl 2,r */
        oad(0x050364 | r << 19, 11*PTR_SIZE); /* add fs:0x2c,r */
        gen_modrm(0x8b, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        o(opc), oad(0x80 | op_reg | r, c); /* mov #c(r),op_reg */
        greloc(cur_text_section, sym, ind - 4, R_386_TLS_LE);
#अन्यथा
        o(0x65); /* gs segment prefix */
        o(opc), oad(0x05 | op_reg, c);
        greloc(cur_text_section, sym, ind - 4, R_386_TLS_LE);
#endif
#जर defined CONFIG_TCC_PIC
    } अन्यथा जर ((r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
        पूर्णांक is_got = (op_r2 & TREG_MEM) && !(sym->type.t & VT_STATIC);
        पूर्णांक here = ind;
        get_pc_thunk(TREG_EBX, is_got);
        o(opc);
        o(0x83 | op_reg);
        जर (is_got) {
            gen_gotpcrel(r, sym, c);
        } अन्यथा {
            gen_addrpc32(r, sym, c + (ind - here - 1));
        }
    } अन्यथा जर ((r & VT_VALMASK) < VT_CONST && (r & TREG_MEM)) {
        o(opc);
        जर (c) {
            g(0x80 | op_reg | REG_मूल्य(r));
            gen_le32(c);
        } अन्यथा {
            g(0x00 | op_reg | REG_मूल्य(r));
        }
#endif
    } अन्यथा जर ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
        o(opc);
        o(0x05 | op_reg);
        gen_addr32(r, sym, c);
    } अन्यथा जर ((r & VT_VALMASK) == VT_LOCAL) {
	o(opc);
        /* currently, we use only ebp as base */
        जर (c == (चिन्हित अक्षर)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } अन्यथा {
            oad(0x85 | op_reg, c);
        }
    } अन्यथा {
	o(opc);
        g(0x00 | op_reg | (r & VT_VALMASK));
    }
}

/* load 'r' from value 'sv' */
ST_FUNC शून्य load(पूर्णांक r, SValue *sv)
{
    पूर्णांक v, t, ft, fc, fr, opc;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~VT_DEFSIGN;
    fc = sv->c.i;
    ft &= ~VT_QUAL;
    v = fr & VT_VALMASK;

#जर defined CONFIG_TCC_PIC
    /* we use indirect access via got */
    जर ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        पूर्णांक tr = r | TREG_MEM;
        जर (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm(0x8b, tr, fr, sv->sym, 0);
        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#endif

    जर (fr & VT_LVAL) {
        जर (v == VT_LLOCAL) {
            v1.type.t = VT_INT;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
            v1.sym = रिक्त;
            fr = r;
            जर (!(reg_classes[fr] & RC_INT))
                fr = get_reg(RC_INT);
            load(fr, &v1);
        }
        जर ((ft & VT_BTYPE) == VT_FLOAT) {
            opc = 0xd9; /* flds */
            r = 0;
        } अन्यथा जर ((ft & VT_BTYPE) == VT_DOUBLE) {
            opc = 0xdd; /* fldl */
            r = 0;
        } अन्यथा जर ((ft & VT_BTYPE) == VT_LDOUBLE) {
            opc = 0xdb; /* fldt */
            r = 5;
        } अन्यथा जर ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            opc = 0xbe0f;   /* movsbl */
        } अन्यथा जर ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED) ||
		   (ft & VT_TYPE) == (VT_BOOL | VT_UNSIGNED)) {
            opc = 0xb60f;   /* movzbl */
        } अन्यथा जर ((ft & VT_TYPE) == VT_SHORT) {
            opc = 0xbf0f;   /* movswl */
        } अन्यथा जर ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            opc = 0xb70f;   /* movzwl */
        } अन्यथा {
            opc = 0x8b;     /* movl */
        }
        gen_modrm(opc, r, fr, sv->sym, fc);
    } अन्यथा {
        जर ((fr & VT_SYM) && (sv->sym->type.t & VT_TLS)) {
#ifdef TCC_TARGET_PE
            gen_modrm(0x8d, r, fr, sv->sym, fc);
#अन्यथा
            oad(0x058b65 | REG_मूल्य(r) << 19, 0); /* mov gs:0,r */
            oad(0xC081 | REG_मूल्य(r) << 8, fc); /* add tpoffs,r */
            greloc(cur_text_section, sv->sym, ind - 4, R_386_TLS_LE);
#endif
#जर defined CONFIG_TCC_PIC
        } अन्यथा जर ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
            जर (sv->sym->type.t & VT_STATIC) {
                get_pc_thunk(r, 0);
                o(0x808d | REG_मूल्य(r) * 0x900); /* lea $xx(r), r */
                gen_addrpc32(fr, sv->sym, fc + 6);
            } अन्यथा {
                get_pc_thunk(r, 1);
                o(0x808b | REG_मूल्य(r) * 0x900); /* mov $xx(r), r */
                gen_gotpcrel(r, sv->sym, fc);
            }
#endif
        } अन्यथा जर (v == VT_CONST) {
            o(0xb8 + r); /* mov $xx, r */
            gen_addr32(fr, sv->sym, fc);
        } अन्यथा जर (v == VT_LOCAL) {
            जर (fc) {
                /* lea xxx(%ebp), r */
                gen_modrm(0x8d, r, VT_LOCAL, sv->sym, fc);
            } अन्यथा {
                o(0x89);
                o(0xe8 + r); /* mov %ebp, r */
            }
        } अन्यथा जर (v == VT_CMP) {
            o(0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + r);
            o(0xc0b60f + r * 0x90000); /* movzbl %al, %eax */
        } अन्यथा जर (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            oad(0xb8 + r, t); /* mov $1, r */
            o(0x05eb); /* jmp after */
            gsym(fc);
            oad(0xb8 + r, t ^ 1); /* mov $0, r */
        } अन्यथा जर (v != r) {
            o(0x89);
            o(0xc0 + r + v * 8); /* mov v, r */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ST_FUNC शून्य store(पूर्णांक r, SValue *v)
{
    पूर्णांक fr, bt, fc, opc;

    bt = v->type.t & VT_BTYPE;

    /* XXX: incorrect if float reg to reg */
    जर (bt == VT_FLOAT) {
        opc = 0xd9; /* fsts */
        r = 2;
    } अन्यथा जर (bt == VT_DOUBLE) {
        opc = 0xdd; /* fstpl */
        r = 2;
    } अन्यथा जर (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0), fstpt */
        opc = 0xdb;
        r = 7;
    } अन्यथा जर (bt == VT_SHORT) {
        opc = 0x8966;
    } अन्यथा जर (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } अन्यथा {
        opc = 0x89;
    }

    fc = v->c.i;
    fr = v->r & VT_VALMASK;

#जर defined CONFIG_TCC_PIC
    /* we need to access the variable via got */
    जर ((v->r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
	get_pc_thunk(TREG_EBX, 1);
	o(0x9b8b); /* mov xx(%ebx),%ebx */
	gen_gotpcrel(TREG_EBX, v->sym, v->c.i);
	o(opc);
	o(3 + (r << 3));
    } अन्यथा
#endif

    जर (fr == VT_CONST || fr == VT_LOCAL || (v->r & VT_LVAL)) {
        gen_modrm(opc, r, v->r, v->sym, fc);
    } अन्यथा जर (fr != r) {
	o(opc);
        o(0xc0 + fr + r * 8); /* mov r, fr */
    }
}

स्थिर शून्य gadd_sp(पूर्णांक val)
{
    जर (val == (चिन्हित अक्षर)val) {
        o(0xc483);
        g(val);
    } अन्यथा {
        oad(0xc481, val); /* add $xxx, %esp */
    }
}

#जर defined TCC_TARGET_PE || defined CONFIG_TCC_PIC
स्थिर शून्य gen_static_call(पूर्णांक v)
{
    Sym *sym;

    sym = external_helper_sym(v);
    oad(0xe8, -4);
    greloc(cur_text_section, sym, ind - 4, R_386_PC32);
}
#endif

/* 'is_jmp' is '1' if it is a jump */
स्थिर शून्य gcall_or_jmp(पूर्णांक is_jmp)
{
    पूर्णांक r;
    जर ((vtop->r & (VT_VALMASK|VT_LVAL|VT_SYM)) == (VT_CONST|VT_SYM)) {
        /* constant and relocation case */
#जर defined CONFIG_TCC_PIC
	जर (!(vtop->sym->type.t & VT_STATIC)) {
	    get_pc_thunk(TREG_EBX, 1);
            oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
            greloc(cur_text_section, vtop->sym, ind - 4, R_386_PLT32);
            परत;
	}
#endif
        oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
        greloc(cur_text_section, vtop->sym, ind - 4, R_386_PC32);
    } अन्यथा {
        /* otherwise, indirect call */
        r = gv(RC_INT);
        o(0xff); /* call/jmp *r */
        o(0xd0 + r + (is_jmp << 4));
    }
}

स्थिर स्थिरांक uint8_t fastcall_regs[3] = { TREG_EAX, TREG_EDX, TREG_ECX };
स्थिर स्थिरांक uint8_t fastcallw_regs[2] = { TREG_ECX, TREG_EDX };

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC पूर्णांक gfunc_sret(CType *vt, पूर्णांक variadic, CType *ret, पूर्णांक *ret_align, पूर्णांक *regsize)
{
#जर defined(TCC_TARGET_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    पूर्णांक size, align, nregs;
    *ret_align = 1; // Never have to re-align return values for x86
    *regsize = 4;
    size = type_size(vt, &align);
    जर (size > 8 || (size & (size - 1)))
        परत 0;
    nregs = 1;
    जर (size == 8)
        ret->t = VT_INT, nregs = 2;
    अन्यथा जर (size == 4)
        ret->t = VT_INT;
    अन्यथा जर (size == 2)
        ret->t = VT_SHORT;
    अन्यथा
        ret->t = VT_BYTE;
    ret->ref = रिक्त;
    परत nregs;
#अन्यथा
    *ret_align = 1; // Never have to re-align return values for x86
    परत 0;
#endif
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ST_FUNC शून्य gfunc_call(पूर्णांक nb_args)
{
    पूर्णांक size, align, r, args_size, i, func_call;
    Sym *func_sym;

#ifdef CONFIG_TCC_BCHECK
    जर (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#endif

    save_regs(nb_args + 1);

    args_size = 0;
    साठी(i = 0;i < nb_args; i++) {
        जर ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
            size = type_size(&vtop->type, &align);
            /* align to stack align size */
            size = (size + 3) & ~3;
            /* allocate the necessary size on stack */
#ifdef TCC_TARGET_PE
            जर (size >= 4096) {
                save_reg(TREG_EDX);
                r = get_reg(RC_EAX);
                oad(0x68, size); // push size
                /* cannot call normal 'alloca' with bound checking */
                gen_static_call(tok_alloc_const("__alloca"));
                gadd_sp(4);
            } अन्यथा
#endif
            {
                oad(0xec81, size); /* sub $xxx, %esp */
                /* generate structure store */
                r = get_reg(RC_INT);
                o(0xe089 + (r << 8)); /* mov %esp, r */
            }
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            args_size += size;
        } अन्यथा जर (is_float(vtop->type.t)) {
            gv(RC_FLOAT); /* only one float register */
            जर ((vtop->type.t & VT_BTYPE) == VT_FLOAT)
                size = 4;
            अन्यथा जर ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                size = 8;
            अन्यथा
                size = 12;
            oad(0xec81, size); /* sub $xxx, %esp */
            जर (size == 12)
                o(0x7cdb);
            अन्यथा
                o(0x5cd9 + size - 4); /* fstp[s|l] 0(%esp) */
            g(0x24);
            g(0x00);
            args_size += size;
        } अन्यथा {
            /* simple type (currently always same size) */
            /* XXX: implicit cast ? */
            r = gv(RC_INT);
            जर ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
                size = 8;
                o(0x50 + vtop->r2); /* push r */
            } अन्यथा {
                size = 4;
            }
            o(0x50 + r); /* push r */
            args_size += size;
        }
        vtop--;
    }

    func_sym = vtop->type.ref;
    func_call = func_sym->f.func_call;
    /* fast call case */
    जर ((func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) ||
        func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL) {
        पूर्णांक fastcall_nb_regs;
        स्थिरांक uint8_t *fastcall_regs_ptr;
        जर (func_call == FUNC_FASTCALLW) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 2;
        } अन्यथा जर (func_call == FUNC_THISCALL) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 1;
        } अन्यथा {
            fastcall_regs_ptr = fastcall_regs;
            fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        }
        साठी(i = 0;i < fastcall_nb_regs; i++) {
            जर (args_size <= 0)
                थांबा;
            o(0x58 + fastcall_regs_ptr[i]); /* pop r */
            /* XXX: incorrect for struct/floats */
            args_size -= 4;
        }
    }
#जर !defined(TCC_TARGET_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    अन्यथा जर ((vtop->type.ref->type.t & VT_BTYPE) == VT_STRUCT)
        args_size -= 4;
#endif

    gcall_or_jmp(0);

    जर (args_size && func_call != FUNC_STDCALL && func_call != FUNC_THISCALL && func_call != FUNC_FASTCALLW)
        gadd_sp(args_size);
    vtop--;
}

#ifdef TCC_TARGET_PE
#define FUNC_PROLOG_SIZE (10 + !!USE_EBX)
#अन्यथा
#define FUNC_PROLOG_SIZE (9 + !!USE_EBX)
#endif

/* generate function prolog of type 't' */
ST_FUNC शून्य gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    पूर्णांक addr, align, size, func_call, fastcall_nb_regs;
    पूर्णांक param_index, param_addr;
    स्थिरांक uint8_t *fastcall_regs_ptr;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    func_call = sym->f.func_call;
    addr = 8;
    loc = 0;
    func_vc = 0;

    जर (func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) {
        fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        fastcall_regs_ptr = fastcall_regs;
    } अन्यथा जर (func_call == FUNC_FASTCALLW) {
        fastcall_nb_regs = 2;
        fastcall_regs_ptr = fastcallw_regs;
    } अन्यथा जर (func_call == FUNC_THISCALL) {
        fastcall_nb_regs = 1;
        fastcall_regs_ptr = fastcallw_regs;
    } अन्यथा {
        fastcall_nb_regs = 0;
        fastcall_regs_ptr = रिक्त;
    }
    param_index = 0;

    ind += FUNC_PROLOG_SIZE;
    func_sub_sp_offset = ind;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
#जर defined(TCC_TARGET_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    size = type_size(&func_vt,&align);
    जर (((func_vt.t & VT_BTYPE) == VT_STRUCT)
        && (size > 8 || (size & (size - 1)))) {
#अन्यथा
    जर ((func_vt.t & VT_BTYPE) == VT_STRUCT) {
#endif
        /* XXX: fastcall case ? */
        func_vc = addr;
        addr += 4;
        param_index++;
    }
    /* define parameters */
    पर्यंत ((sym = sym->next) != रिक्त) {
        type = &sym->type;
        size = type_size(type, &align);
        size = (size + 3) & ~3;
#ifdef FUNC_STRUCT_PARAM_AS_PTR
        /* structs are passed as pointer */
        जर ((type->t & VT_BTYPE) == VT_STRUCT) {
            size = 4;
        }
#endif
        जर (param_index < fastcall_nb_regs) {
            /* save FASTCALL register */
            loc -= 4;
            /* movl */
            gen_modrm(0x89, fastcall_regs_ptr[param_index], VT_LOCAL, रिक्त, loc);
            param_addr = loc;
        } अन्यथा {
            param_addr = addr;
            addr += size;
        }
        gfunc_set_param(sym, param_addr, 0);
        param_index++;
    }
    func_ret_sub = 0;
    /* pascal type call or fastcall ? */
    जर (func_call == FUNC_STDCALL || func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL)
        func_ret_sub = addr - 8;
#जर !defined(TCC_TARGET_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    अन्यथा जर (func_vc)
        func_ret_sub = 4;
#endif

#ifdef CONFIG_TCC_BCHECK
    जर (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#endif
}

/* generate function epilog */
ST_FUNC शून्य gfunc_epilog(शून्य)
{
    addr_t v, saved_ind;

#ifdef CONFIG_TCC_BCHECK
    जर (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#endif

    /* align local size to word & save local variables */
    v = (-loc + 3) & -4;

#जर USE_EBX
    gen_modrm(0x8b, TREG_EBX, VT_LOCAL, रिक्त, -(v+4));
#endif

    o(0xc9); /* leave */
    जर (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } अन्यथा {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    saved_ind = ind;
    ind = func_sub_sp_offset - FUNC_PROLOG_SIZE;
#ifdef TCC_TARGET_PE
    जर (v >= 4096) {
        oad(0xb8, v); /* mov stacksize, %eax */
        gen_static_call(TOK___chkstk); /* call __chkstk, (does the stackframe too) */
    } अन्यथा
#endif
    {
        o(0xe58955);  /* push %ebp, mov %esp, %ebp */
        o(0xec81);  /* sub esp, stacksize */
        gen_le32(v);
#ifdef TCC_TARGET_PE
        o(0x90);  /* adjust to FUNC_PROLOG_SIZE */
#endif
    }
#जर USE_EBX
    o(0x53); /* push ebx */
#endif
    ind = saved_ind;
}

/* generate a jump to a label */
ST_FUNC पूर्णांक gjmp(पूर्णांक t)
{
    परत gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ST_FUNC शून्य gjmp_addr(पूर्णांक a)
{
    पूर्णांक r;
    r = a - ind - 2;
    जर (r == (चिन्हित अक्षर)r) {
        g(0xeb);
        g(r);
    } अन्यथा {
        oad(0xe9, a - ind - 5);
    }
}

#जर 0
/* generate a jump to a fixed address */
ST_FUNC शून्य gjmp_cond_addr(पूर्णांक a, पूर्णांक op)
{
    पूर्णांक r = a - ind - 2;
    जर (r == (चिन्हित अक्षर)r)
        g(op - 32), g(r);
    अन्यथा
        g(0x0f), gjmp2(op - 16, r - 4);
}
#endif

ST_FUNC पूर्णांक gjmp_append(पूर्णांक n, पूर्णांक t)
{
    शून्य *p;
    /* insert vtop->c jump list in t */
    जर (n) {
        uint32_t n1 = n, n2;
        पर्यंत ((n2 = read32le(p = cur_text_section->data + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    परत t;
}

ST_FUNC पूर्णांक gjmp_cond(पूर्णांक op, पूर्णांक t)
{
    g(0x0f);
    t = gjmp2(op - 16, t);
    परत t;
}

ST_FUNC शून्य gen_opi(पूर्णांक op)
{
    पूर्णांक r, fr, opc, c;

    निवड(op) {
    स्थिती '+':
    स्थिती TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        जर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            जर (c == (चिन्हित अक्षर)c) {
                /* generate inc and dec for smaller code */
                जर ((c == 1 || c == -1) && (op == '+' || op == '-')) {
                    opc = (c == 1) ^ (op == '+');
                    o (0x40 | (opc << 3) | r); // inc,dec
                } अन्यथा {
                    o(0x83);
                    o(0xc0 | (opc << 3) | r);
                    g(c);
                }
            } अन्यथा {
                o(0x81);
                oad(0xc0 | (opc << 3) | r, c);
            }
        } अन्यथा {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            o((opc << 3) | 0x01);
            o(0xc0 + r + fr * 8); 
        }
        vtop--;
        जर (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        थांबा;
    स्थिती '-':
    स्थिती TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        जा gen_op8;
    स्थिती TOK_ADDC2: /* add with carry use */
        opc = 2;
        जा gen_op8;
    स्थिती TOK_SUBC2: /* sub with carry use */
        opc = 3;
        जा gen_op8;
    स्थिती '&':
        opc = 4;
        जा gen_op8;
    स्थिती '^':
        opc = 6;
        जा gen_op8;
    स्थिती '|':
        opc = 1;
        जा gen_op8;
    स्थिती '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        o(0xaf0f); /* imul fr, r */
        o(0xc0 + fr + r * 8);
        थांबा;
    स्थिती TOK_SHL:
        opc = 4;
        जा gen_shift;
    स्थिती TOK_SHR:
        opc = 5;
        जा gen_shift;
    स्थिती TOK_SAR:
        opc = 7;
    gen_shift:
        opc = 0xc0 | (opc << 3);
        जर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i & 0x1f;
            o(0xc1); /* shl/shr/sar $xxx, r */
            o(opc | r);
            g(c);
        } अन्यथा {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_ECX);
            r = vtop[-1].r;
            o(0xd3); /* shl/shr/sar %cl, r */
            o(opc | r);
        }
        vtop--;
        थांबा;
    स्थिती '/':
    स्थिती TOK_UDIV:
    स्थिती TOK_PDIV:
    स्थिती '%':
    स्थिती TOK_UMOD:
    स्थिती TOK_UMULL:
        /* first operand must be in eax */
        /* XXX: need better constraint for second operand */
        gv2(RC_EAX, RC_ECX);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        save_reg(TREG_EDX);
        /* save EAX too if used otherwise */
        save_reg_upstack(TREG_EAX, 1);
        जर (op == TOK_UMULL) {
            o(0xf7); /* mul fr */
            o(0xe0 + fr);
            vtop->r2 = TREG_EDX;
            r = TREG_EAX;
        } अन्यथा {
            जर (op == TOK_UDIV || op == TOK_UMOD) {
                o(0xf7d231); /* xor %edx, %edx, div fr, %eax */
                o(0xf0 + fr);
            } अन्यथा {
                o(0xf799); /* cltd, idiv fr, %eax */
                o(0xf8 + fr);
            }
            जर (op == '%' || op == TOK_UMOD)
                r = TREG_EDX;
            अन्यथा
                r = TREG_EAX;
        }
        vtop->r = r;
        थांबा;
    पूर्वनिर्धारित:
        opc = 7;
        जा gen_op8;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ST_FUNC शून्य gen_opf(पूर्णांक op)
{
    पूर्णांक a, ft, fc, swapped, r;

    जर (op == TOK_NEG) { /* unary minus */
        gv(RC_FLOAT);
        o(0xe0d9); /* fchs */
        परत;
    }

    /* convert constants to memory references */
    जर ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    जर ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(RC_FLOAT);

    /* must put at least one value in the floating point register */
    जर ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    जर (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    जर (op >= TOK_ULT && op <= TOK_GT) {
        /* load on stack second operand */
        load(TREG_ST0, vtop);
        save_reg(TREG_EAX); /* eax is used by FP comparison code */
        जर (op == TOK_GE || op == TOK_GT)
            swapped = !swapped;
        अन्यथा जर (op == TOK_EQ || op == TOK_NE)
            swapped = 0;
        जर (swapped)
            o(0xc9d9); /* fxch %st(1) */
        जर (op == TOK_EQ || op == TOK_NE)
            o(0xe9da); /* fucompp */
        अन्यथा
            o(0xd9de); /* fcompp */
        o(0xe0df); /* fnstsw %ax */
        जर (op == TOK_EQ) {
            o(0x45e480); /* and $0x45, %ah */
            o(0x40fC80); /* cmp $0x40, %ah */
        } अन्यथा जर (op == TOK_NE) {
            o(0x45e480); /* and $0x45, %ah */
            o(0x40f480); /* xor $0x40, %ah */
            op = TOK_NE;
        } अन्यथा जर (op == TOK_GE || op == TOK_LE) {
            o(0x05c4f6); /* test $0x05, %ah */
            op = TOK_EQ;
        } अन्यथा {
            o(0x45c4f6); /* test $0x45, %ah */
            op = TOK_EQ;
        }
        vtop--;
        vset_VT_CMP(op);
    } अन्यथा {
        /* no memory reference possible for long double operations */
        जर ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
            load(TREG_ST0, vtop);
            swapped = !swapped;
        }
        
        निवड(op) {
        पूर्वनिर्धारित:
        स्थिती '+':
            a = 0;
            थांबा;
        स्थिती '-':
            a = 4;
            जर (swapped)
                a++;
            थांबा;
        स्थिती '*':
            a = 1;
            थांबा;
        स्थिती '/':
            a = 6;
            जर (swapped)
                a++;
            थांबा;
        }
        ft = vtop->type.t;
        fc = vtop->c.i;
        जर ((ft & VT_BTYPE) == VT_LDOUBLE) {
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
        } अन्यथा {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            जर ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_INT;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = रिक्त;
                load(r, &v1);
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
ST_FUNC शून्य gen_cvt_itof(पूर्णांक t)
{
    save_reg(TREG_ST0);
    gv(RC_INT);
    जर ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
        /* signed long long to float/double/long double (unsigned case
           is handled generically) */
        o(0x50 + vtop->r2); /* push r2 */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
        vtop->r2 = VT_CONST;
    } अन्यथा जर ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
               (VT_INT | VT_UNSIGNED)) {
        /* unsigned int to float/double/long double */
        o(0x6a); /* push $0 */
        g(0x00);
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
    } अन्यथा {
        /* int to float/double/long double */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x2404db); /* fildl (%esp) */
        o(0x04c483); /* add $4, %esp */
    }
    vtop->r2 = VT_CONST;
    vtop->r = TREG_ST0;
}

/* convert fp to int 't' type */
ST_FUNC शून्य gen_cvt_ftoi(पूर्णांक t)
{
    पूर्णांक bt = vtop->type.t & VT_BTYPE;
    जर (bt == VT_FLOAT)
        vpush_helper_func(TOK___fixsfdi);
    अन्यथा जर (bt == VT_LDOUBLE)
        vpush_helper_func(TOK___fixxfdi);
    अन्यथा
        vpush_helper_func(TOK___fixdfdi);
    vswap();
    gfunc_call(1);
    vpushi(0);
    vtop->r = REG_IRET;
    जर ((t & VT_BTYPE) == VT_LLONG)
        vtop->r2 = REG_IRE2;
}

/* convert from one floating point type to another */
ST_FUNC शून्य gen_cvt_ftof(पूर्णांक t)
{
    /* all we have to do on i386 is to put the float in a register */
    gv(RC_FLOAT);
}

/* char/short to int conversion */
ST_FUNC शून्य gen_cvt_csti(पूर्णांक t)
{
    पूर्णांक r, sz, xl;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    o(0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (r << 3 | r) << 16
        );
}

/* increment tcov counter */
ST_FUNC शून्य gen_increment_tcov (SValue *sv)
{
   पूर्णांक indir, rel, add1, add2;
#जर defined CONFIG_TCC_PIC
   get_pc_thunk(TREG_EBX, 0);
   indir = 0x8300;
   rel = R_386_PC32;
   add1 = 2;
   add2 = 13;
#अन्यथा
   indir = 0x0500;
   rel = R_386_32;
   add1 = 0;
   add2 = 4;
#endif
   o(0x0083 + indir); /* addl $1, xxx(%ebx) */
   greloc(cur_text_section, sv->sym, ind, rel);
   gen_le32(add1);
   o(1);
   o(0x1083 + indir); /* adcl $0, xxx(%ebx) */
   greloc(cur_text_section, sv->sym, ind, rel);
   gen_le32(add2);
   g(0);
}

/* computed goto support */
ST_FUNC शून्य ggoto(शून्य)
{
    gcall_or_jmp(1);
    vtop--;
}

/* bound check support functions */
#ifdef CONFIG_TCC_BCHECK

/* Need PIC for shared libraries */
स्थिर शून्य gen_bound_call(पूर्णांक v)
{
    Sym *sym;

    sym = external_helper_sym(v);
#जर defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EBX, 1);
    oad(0xe8, -4);
    greloc(cur_text_section, sym, ind - 4, R_386_PLT32);
#अन्यथा
    oad(0xe8, -4);
    greloc(cur_text_section, sym, ind - 4, R_386_PC32);
#endif
}

स्थिर शून्य gen_bounds_prolog(शून्य)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->data_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
#जर defined CONFIG_TCC_PIC
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0x808d, 0); /* lea lbound section pointer */
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0xc381, 0); /* add _GLOBAL_OFFSET_TABLE_ */
    oad(0xb8, 0); /* call to function */
#अन्यथा
    oad(0xb8, 0); /* lbound section pointer */
    oad(0xb8, 0); /* call to function */
#endif
}

स्थिर शून्य gen_bounds_epilog(शून्य)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    पूर्णांक offset_modified = func_bound_offset != lbounds_section->data_offset;

    जर (!offset_modified && !func_bound_add_epilog)
        परत;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, आकार(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    जर (offset_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
#जर defined CONFIG_TCC_PIC
	get_pc_thunk(TREG_EAX, 0);
	o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
	greloc(cur_text_section, sym_data, ind, R_386_PC32);
	gen_le32(2);
#अन्यथा
        greloc(cur_text_section, sym_data, ind + 1, R_386_32);
        ind = ind + 5;
#endif
        gen_bound_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0x5250); /* save returned value, if any */
#जर defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EAX, 0);
    o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
    greloc(cur_text_section, sym_data, ind, R_386_PC32);
    gen_le32(2);
#अन्यथा
    greloc(cur_text_section, sym_data, ind + 1, R_386_32);
    oad(0xb8, 0); /* mov %eax, xxx */
#endif
    gen_bound_call(TOK___bound_local_delete);
    o(0x585a); /* restore returned value, if any */
}
#endif

/* Save the stack pointer onto the stack */
ST_FUNC शून्य gen_vla_sp_save(पूर्णांक addr) {
    /* mov %esp,addr(%ebp)*/
    gen_modrm(0x89, TREG_ESP, VT_LOCAL, रिक्त, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC शून्य gen_vla_sp_restore(पूर्णांक addr) {
    gen_modrm(0x8b, TREG_ESP, VT_LOCAL, रिक्त, addr);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC शून्य gen_vla_alloc(CType *type, पूर्णांक align) {
    पूर्णांक use_call = 0;

#जर defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#endif
#ifdef TCC_TARGET_PE    /* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#endif
    जर (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    अन्यथा {
        पूर्णांक r;
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
#endif
/*************************************************************/
