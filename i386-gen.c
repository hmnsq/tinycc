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

#अगर_घोषित TARGET_DEFS_ONLY

/* number of available registers */
#घोषणा NB_REGS         5
#घोषणा NB_ASM_REGS     8
#घोषणा CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#घोषणा RC_INT     0x0001 /* generic integer register */
#घोषणा RC_FLOAT   0x0002 /* generic float register */
#घोषणा RC_EAX     0x0004
#घोषणा RC_EDX     0x0008
#घोषणा RC_ECX     0x0010
#घोषणा RC_EBX     0x0020
#घोषणा RC_ST0     0x0040

#घोषणा RC_IRET    RC_EAX /* function return: integer register */
#घोषणा RC_IRE2    RC_EDX /* function return: second integer register */
#घोषणा RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
क्रमागत {
    TREG_EAX = 0,
    TREG_ECX,
    TREG_EDX,
    TREG_EBX,
    TREG_ST0,
    TREG_ESP = 4,
    TREG_MEM = 0x20
};

#घोषणा REG_मूल्य(reg) ((reg) & 7)

/* return registers for function */
#घोषणा REG_IRET TREG_EAX /* single word int return register */
#घोषणा REG_IRE2 TREG_EDX /* second word return register (for long long) */
#घोषणा REG_FRET TREG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
#घोषणा INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#घोषणा PTR_आकार 4

/* long double size and alignment, in bytes */
#घोषणा LDOUBLE_आकार  12
#घोषणा LDOUBLE_ALIGN 4
/* maximum alignment (for aligned attribute support) */
#घोषणा MAX_ALIGN     8

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#घोषणा PROMOTE_RET

/******************************************************/
#अन्यथा /* ! TARGET_DEFS_ONLY */
/******************************************************/
#घोषणा USING_GLOBALS
#समावेश "tcc.h"

ST_तथ्य स्थिर अक्षर * स्थिर target_machine_defs =
    "__i386__\0"
    "__i386\0"
    ;

#अगर defined CONFIG_TCC_PIC
# define USE_EBX 2
#अन्यथा
# define USE_EBX 0 /* define to 1 to have EBX as 4th register */
#पूर्ण_अगर

ST_तथ्य स्थिर पूर्णांक reg_classes[NB_REGS] = {
    /* eax */ RC_INT | RC_EAX,
    /* ecx */ RC_INT | RC_ECX,
    /* edx */ RC_INT | RC_EDX,
    /* ebx */ (RC_INT | RC_EBX) * (USE_EBX == 1),
    /* st0 */ RC_FLOAT | RC_ST0,
};

अटल अचिन्हित दीर्घ func_sub_sp_offset;
अटल पूर्णांक func_ret_sub;
#अगर_घोषित CONFIG_TCC_BCHECK
अटल addr_t func_bound_offset;
अटल अचिन्हित दीर्घ func_bound_ind;
ST_तथ्य पूर्णांक func_bound_add_epilog;
अटल व्योम gen_bounds_prolog(व्योम);
अटल व्योम gen_bounds_epilog(व्योम);
#पूर्ण_अगर

/* XXX: make it faster ? */
ST_FUNC व्योम g(पूर्णांक c)
{
    पूर्णांक ind1;
    अगर (nocode_wanted)
        वापस;
    ind1 = ind + 1;
    अगर (ind1 > cur_text_section->तथ्य_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->तथ्य[ind] = c;
    ind = ind1;
}

ST_FUNC व्योम o(अचिन्हित पूर्णांक c)
{
    जबतक (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC व्योम gen_le16(पूर्णांक v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC व्योम gen_le32(पूर्णांक c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

/* output a symbol and patch all calls to it */
ST_FUNC व्योम gsym_addr(पूर्णांक t, पूर्णांक a)
{
    जबतक (t) {
        अचिन्हित अक्षर *ptr = cur_text_section->तथ्य + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a - t - 4);
        t = n;
    }
}

/* instruction + 4 bytes data. Return the address of the data */
अटल पूर्णांक oad(पूर्णांक c, पूर्णांक s)
{
    पूर्णांक t;
    अगर (nocode_wanted)
        वापस s;
    o(c);
    t = ind;
    gen_le32(s);
    वापस t;
}

ST_FUNC व्योम gen_fill_nops(पूर्णांक bytes)
{
    जबतक (bytes--)
      g(0x90);
}

#अगर defined CONFIG_TCC_PIC
अटल व्योम gen_static_call(पूर्णांक v);
अटल व्योम get_pc_thunk(पूर्णांक r, पूर्णांक add)
{
    अटल स्थिर अक्षर * स्थिर pc_thunk_name[] = {
	"__x86.get_pc_thunk.ax",
	"__x86.get_pc_thunk.cx",
	"__x86.get_pc_thunk.dx",
	"__x86.get_pc_thunk.bx"
    };
    अगर (nocode_wanted)
        वापस;
    gen_static_call(tok_alloc_const(pc_thunk_name[r]));
    अगर (add) {
        Sym label = {0};
        label.type.t = VT_VOID|VT_STATIC;
        put_extern_sym(&label, cur_text_section, ind, 0);
        r = REG_मूल्य(r);
	अगर (r == 0)
	    oad(0x05, 1); /* add _GLOBAL_OFFSET_TABLE_, %eax */
	अन्यथा
            oad(0xc081 + r * 0x100, 2); /* add _GLOBAL_OFFSET_TABLE_, %erx */
        greloc(cur_text_section, &label, ind - 4, R_386_GOTPC);
    }
}

ST_FUNC व्योम gen_gotpcrel(पूर्णांक r, Sym *sym, पूर्णांक c)
{
    greloc(cur_text_section, sym, ind, R_386_GOT32X);
    gen_le32(0);
    अगर (c) {
	r = REG_मूल्य(r);
	अगर (r == 0)
            oad(0x05, c);
	अन्यथा
            oad(0xc081 + r * 0x100, c);
    }
}
#पूर्ण_अगर

/* generate jmp to a label */
#घोषणा gjmp2(instr,lbl) oad(instr,lbl)

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC व्योम gen_addr32(पूर्णांक r, Sym *sym, पूर्णांक c)
{
    अगर (r & VT_SYM)
        greloc(cur_text_section, sym, ind, R_386_32);
    gen_le32(c);
}

ST_FUNC व्योम gen_addrpc32(पूर्णांक r, Sym *sym, पूर्णांक c)
{
    अगर (r & VT_SYM)
        greloc(cur_text_section, sym, ind, R_386_PC32);
    gen_le32(c - 4);
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode bits */
अटल व्योम gen_modrm(पूर्णांक opc, पूर्णांक op_r2, पूर्णांक r, Sym *sym, पूर्णांक c)
{
    पूर्णांक op_reg = REG_मूल्य(op_r2) << 3;

    अगर ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#अगर_घोषित TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK_tls_सूचकांक, &int_type);
        r = get_reg(RC_INT);
        gen_modrm(0x8b, r, VT_SYM|VT_CONST, s2, 0); /* mov __tls_index, r */
        o(0x02e0c1 | r << 8); /* shl 2,r */
        oad(0x050364 | r << 19, 11*PTR_आकार); /* add fs:0x2c,r */
        gen_modrm(0x8b, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        o(opc), oad(0x80 | op_reg | r, c); /* mov #c(r),op_reg */
        greloc(cur_text_section, sym, ind - 4, R_386_TLS_LE);
#अन्यथा
        o(0x65); /* gs segment prefix */
        o(opc), oad(0x05 | op_reg, c);
        greloc(cur_text_section, sym, ind - 4, R_386_TLS_LE);
#पूर्ण_अगर
#अगर defined CONFIG_TCC_PIC
    } अन्यथा अगर ((r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
        पूर्णांक is_got = (op_r2 & TREG_MEM) && !(sym->type.t & VT_STATIC);
        पूर्णांक here = ind;
        get_pc_thunk(TREG_EBX, is_got);
        o(opc);
        o(0x83 | op_reg);
        अगर (is_got) {
            gen_gotpcrel(r, sym, c);
        } अन्यथा {
            gen_addrpc32(r, sym, c + (ind - here - 1));
        }
    } अन्यथा अगर ((r & VT_VALMASK) < VT_CONST && (r & TREG_MEM)) {
        o(opc);
        अगर (c) {
            g(0x80 | op_reg | REG_मूल्य(r));
            gen_le32(c);
        } अन्यथा {
            g(0x00 | op_reg | REG_मूल्य(r));
        }
#पूर्ण_अगर
    } अन्यथा अगर ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
        o(opc);
        o(0x05 | op_reg);
        gen_addr32(r, sym, c);
    } अन्यथा अगर ((r & VT_VALMASK) == VT_LOCAL) {
	o(opc);
        /* currently, we use only ebp as base */
        अगर (c == (चिन्हित अक्षर)c) {
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
ST_FUNC व्योम load(पूर्णांक r, SValue *sv)
{
    पूर्णांक v, t, ft, fc, fr, opc;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~VT_DEFSIGN;
    fc = sv->c.i;
    ft &= ~VT_QUAL;
    v = fr & VT_VALMASK;

#अगर defined CONFIG_TCC_PIC
    /* we use indirect access via got */
    अगर ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        पूर्णांक tr = r | TREG_MEM;
        अगर (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm(0x8b, tr, fr, sv->sym, 0);
        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#पूर्ण_अगर

    अगर (fr & VT_LVAL) {
        अगर (v == VT_LLOCAL) {
            v1.type.t = VT_INT;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
            v1.sym = शून्य;
            fr = r;
            अगर (!(reg_classes[fr] & RC_INT))
                fr = get_reg(RC_INT);
            load(fr, &v1);
        }
        अगर ((ft & VT_BTYPE) == VT_FLOAT) {
            opc = 0xd9; /* flds */
            r = 0;
        } अन्यथा अगर ((ft & VT_BTYPE) == VT_DOUBLE) {
            opc = 0xdd; /* fldl */
            r = 0;
        } अन्यथा अगर ((ft & VT_BTYPE) == VT_LDOUBLE) {
            opc = 0xdb; /* fldt */
            r = 5;
        } अन्यथा अगर ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            opc = 0xbe0f;   /* movsbl */
        } अन्यथा अगर ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED) ||
		   (ft & VT_TYPE) == (VT_BOOL | VT_UNSIGNED)) {
            opc = 0xb60f;   /* movzbl */
        } अन्यथा अगर ((ft & VT_TYPE) == VT_SHORT) {
            opc = 0xbf0f;   /* movswl */
        } अन्यथा अगर ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            opc = 0xb70f;   /* movzwl */
        } अन्यथा {
            opc = 0x8b;     /* movl */
        }
        gen_modrm(opc, r, fr, sv->sym, fc);
    } अन्यथा {
        अगर ((fr & VT_SYM) && (sv->sym->type.t & VT_TLS)) {
#अगर_घोषित TCC_TARGET_PE
            gen_modrm(0x8d, r, fr, sv->sym, fc);
#अन्यथा
            oad(0x058b65 | REG_मूल्य(r) << 19, 0); /* mov gs:0,r */
            oad(0xC081 | REG_मूल्य(r) << 8, fc); /* add tpoffs,r */
            greloc(cur_text_section, sv->sym, ind - 4, R_386_TLS_LE);
#पूर्ण_अगर
#अगर defined CONFIG_TCC_PIC
        } अन्यथा अगर ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
            अगर (sv->sym->type.t & VT_STATIC) {
                get_pc_thunk(r, 0);
                o(0x808d | REG_मूल्य(r) * 0x900); /* lea $xx(r), r */
                gen_addrpc32(fr, sv->sym, fc + 6);
            } अन्यथा {
                get_pc_thunk(r, 1);
                o(0x808b | REG_मूल्य(r) * 0x900); /* mov $xx(r), r */
                gen_gotpcrel(r, sv->sym, fc);
            }
#पूर्ण_अगर
        } अन्यथा अगर (v == VT_CONST) {
            o(0xb8 + r); /* mov $xx, r */
            gen_addr32(fr, sv->sym, fc);
        } अन्यथा अगर (v == VT_LOCAL) {
            अगर (fc) {
                /* lea xxx(%ebp), r */
                gen_modrm(0x8d, r, VT_LOCAL, sv->sym, fc);
            } अन्यथा {
                o(0x89);
                o(0xe8 + r); /* mov %ebp, r */
            }
        } अन्यथा अगर (v == VT_CMP) {
            o(0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + r);
            o(0xc0b60f + r * 0x90000); /* movzbl %al, %eax */
        } अन्यथा अगर (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            oad(0xb8 + r, t); /* mov $1, r */
            o(0x05eb); /* jmp after */
            gsym(fc);
            oad(0xb8 + r, t ^ 1); /* mov $0, r */
        } अन्यथा अगर (v != r) {
            o(0x89);
            o(0xc0 + r + v * 8); /* mov v, r */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ST_FUNC व्योम store(पूर्णांक r, SValue *v)
{
    पूर्णांक fr, bt, fc, opc;

    bt = v->type.t & VT_BTYPE;

    /* XXX: incorrect if float reg to reg */
    अगर (bt == VT_FLOAT) {
        opc = 0xd9; /* fsts */
        r = 2;
    } अन्यथा अगर (bt == VT_DOUBLE) {
        opc = 0xdd; /* fstpl */
        r = 2;
    } अन्यथा अगर (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0), fstpt */
        opc = 0xdb;
        r = 7;
    } अन्यथा अगर (bt == VT_SHORT) {
        opc = 0x8966;
    } अन्यथा अगर (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } अन्यथा {
        opc = 0x89;
    }

    fc = v->c.i;
    fr = v->r & VT_VALMASK;

#अगर defined CONFIG_TCC_PIC
    /* we need to access the variable via got */
    अगर ((v->r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
	get_pc_thunk(TREG_EBX, 1);
	o(0x9b8b); /* mov xx(%ebx),%ebx */
	gen_gotpcrel(TREG_EBX, v->sym, v->c.i);
	o(opc);
	o(3 + (r << 3));
    } अन्यथा
#पूर्ण_अगर

    अगर (fr == VT_CONST || fr == VT_LOCAL || (v->r & VT_LVAL)) {
        gen_modrm(opc, r, v->r, v->sym, fc);
    } अन्यथा अगर (fr != r) {
	o(opc);
        o(0xc0 + fr + r * 8); /* mov r, fr */
    }
}

अटल व्योम gadd_sp(पूर्णांक val)
{
    अगर (val == (चिन्हित अक्षर)val) {
        o(0xc483);
        g(val);
    } अन्यथा {
        oad(0xc481, val); /* add $xxx, %esp */
    }
}

#अगर defined TCC_TARGET_PE || defined CONFIG_TCC_PIC
अटल व्योम gen_static_call(पूर्णांक v)
{
    Sym *sym;

    sym = external_helper_sym(v);
    oad(0xe8, -4);
    greloc(cur_text_section, sym, ind - 4, R_386_PC32);
}
#पूर्ण_अगर

/* 'is_jmp' is '1' if it is a jump */
अटल व्योम gcall_or_jmp(पूर्णांक is_jmp)
{
    पूर्णांक r;
    अगर ((vtop->r & (VT_VALMASK|VT_LVAL|VT_SYM)) == (VT_CONST|VT_SYM)) {
        /* constant and relocation case */
#अगर defined CONFIG_TCC_PIC
	अगर (!(vtop->sym->type.t & VT_STATIC)) {
	    get_pc_thunk(TREG_EBX, 1);
            oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
            greloc(cur_text_section, vtop->sym, ind - 4, R_386_PLT32);
            वापस;
	}
#पूर्ण_अगर
        oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
        greloc(cur_text_section, vtop->sym, ind - 4, R_386_PC32);
    } अन्यथा {
        /* otherwise, indirect call */
        r = gv(RC_INT);
        o(0xff); /* call/jmp *r */
        o(0xd0 + r + (is_jmp << 4));
    }
}

अटल स्थिर uint8_t fastcall_regs[3] = { TREG_EAX, TREG_EDX, TREG_ECX };
अटल स्थिर uint8_t fastcallw_regs[2] = { TREG_ECX, TREG_EDX };

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC पूर्णांक gfunc_sret(CType *vt, पूर्णांक variadic, CType *ret, पूर्णांक *ret_align, पूर्णांक *regsize)
{
#अगर defined(TCC_TARGET_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    पूर्णांक आकार, align, nregs;
    *ret_align = 1; // Never have to re-align return values for x86
    *regsize = 4;
    आकार = type_आकार(vt, &align);
    अगर (आकार > 8 || (आकार & (आकार - 1)))
        वापस 0;
    nregs = 1;
    अगर (आकार == 8)
        ret->t = VT_INT, nregs = 2;
    अन्यथा अगर (आकार == 4)
        ret->t = VT_INT;
    अन्यथा अगर (आकार == 2)
        ret->t = VT_SHORT;
    अन्यथा
        ret->t = VT_BYTE;
    ret->ref = शून्य;
    वापस nregs;
#अन्यथा
    *ret_align = 1; // Never have to re-align return values for x86
    वापस 0;
#पूर्ण_अगर
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ST_FUNC व्योम gfunc_call(पूर्णांक nb_args)
{
    पूर्णांक आकार, align, r, args_आकार, i, func_call;
    Sym *func_sym;

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#पूर्ण_अगर

    save_regs(nb_args + 1);

    args_आकार = 0;
    क्रम(i = 0;i < nb_args; i++) {
        अगर ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
            आकार = type_आकार(&vtop->type, &align);
            /* align to stack align size */
            आकार = (आकार + 3) & ~3;
            /* allocate the necessary size on stack */
#अगर_घोषित TCC_TARGET_PE
            अगर (आकार >= 4096) {
                save_reg(TREG_EDX);
                r = get_reg(RC_EAX);
                oad(0x68, आकार); // push size
                /* cannot call normal 'alloca' with bound checking */
                gen_static_call(tok_alloc_const("__alloca"));
                gadd_sp(4);
            } अन्यथा
#पूर्ण_अगर
            {
                oad(0xec81, आकार); /* sub $xxx, %esp */
                /* generate structure store */
                r = get_reg(RC_INT);
                o(0xe089 + (r << 8)); /* mov %esp, r */
            }
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            args_आकार += आकार;
        } अन्यथा अगर (is_float(vtop->type.t)) {
            gv(RC_FLOAT); /* only one float register */
            अगर ((vtop->type.t & VT_BTYPE) == VT_FLOAT)
                आकार = 4;
            अन्यथा अगर ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                आकार = 8;
            अन्यथा
                आकार = 12;
            oad(0xec81, आकार); /* sub $xxx, %esp */
            अगर (आकार == 12)
                o(0x7cdb);
            अन्यथा
                o(0x5cd9 + आकार - 4); /* fstp[s|l] 0(%esp) */
            g(0x24);
            g(0x00);
            args_आकार += आकार;
        } अन्यथा {
            /* simple type (currently always same size) */
            /* XXX: implicit cast ? */
            r = gv(RC_INT);
            अगर ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
                आकार = 8;
                o(0x50 + vtop->r2); /* push r */
            } अन्यथा {
                आकार = 4;
            }
            o(0x50 + r); /* push r */
            args_आकार += आकार;
        }
        vtop--;
    }

    func_sym = vtop->type.ref;
    func_call = func_sym->f.func_call;
    /* fast call case */
    अगर ((func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) ||
        func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL) {
        पूर्णांक fastcall_nb_regs;
        स्थिर uint8_t *fastcall_regs_ptr;
        अगर (func_call == FUNC_FASTCALLW) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 2;
        } अन्यथा अगर (func_call == FUNC_THISCALL) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 1;
        } अन्यथा {
            fastcall_regs_ptr = fastcall_regs;
            fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        }
        क्रम(i = 0;i < fastcall_nb_regs; i++) {
            अगर (args_आकार <= 0)
                अवरोध;
            o(0x58 + fastcall_regs_ptr[i]); /* pop r */
            /* XXX: incorrect for struct/floats */
            args_आकार -= 4;
        }
    }
#अगर !defined(TCC_TARGET_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    अन्यथा अगर ((vtop->type.ref->type.t & VT_BTYPE) == VT_STRUCT)
        args_आकार -= 4;
#पूर्ण_अगर

    gcall_or_jmp(0);

    अगर (args_आकार && func_call != FUNC_STDCALL && func_call != FUNC_THISCALL && func_call != FUNC_FASTCALLW)
        gadd_sp(args_आकार);
    vtop--;
}

#अगर_घोषित TCC_TARGET_PE
#घोषणा FUNC_PROLOG_आकार (10 + !!USE_EBX)
#अन्यथा
#घोषणा FUNC_PROLOG_आकार (9 + !!USE_EBX)
#पूर्ण_अगर

/* generate function prolog of type 't' */
ST_FUNC व्योम gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    पूर्णांक addr, align, आकार, func_call, fastcall_nb_regs;
    पूर्णांक param_सूचकांक, param_addr;
    स्थिर uint8_t *fastcall_regs_ptr;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    func_call = sym->f.func_call;
    addr = 8;
    loc = 0;
    func_vc = 0;

    अगर (func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) {
        fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        fastcall_regs_ptr = fastcall_regs;
    } अन्यथा अगर (func_call == FUNC_FASTCALLW) {
        fastcall_nb_regs = 2;
        fastcall_regs_ptr = fastcallw_regs;
    } अन्यथा अगर (func_call == FUNC_THISCALL) {
        fastcall_nb_regs = 1;
        fastcall_regs_ptr = fastcallw_regs;
    } अन्यथा {
        fastcall_nb_regs = 0;
        fastcall_regs_ptr = शून्य;
    }
    param_सूचकांक = 0;

    ind += FUNC_PROLOG_आकार;
    func_sub_sp_offset = ind;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
#अगर defined(TCC_TARGET_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    आकार = type_आकार(&func_vt,&align);
    अगर (((func_vt.t & VT_BTYPE) == VT_STRUCT)
        && (आकार > 8 || (आकार & (आकार - 1)))) {
#अन्यथा
    अगर ((func_vt.t & VT_BTYPE) == VT_STRUCT) {
#पूर्ण_अगर
        /* XXX: fastcall case ? */
        func_vc = addr;
        addr += 4;
        param_सूचकांक++;
    }
    /* define parameters */
    जबतक ((sym = sym->अग्र) != शून्य) {
        type = &sym->type;
        आकार = type_आकार(type, &align);
        आकार = (आकार + 3) & ~3;
#अगर_घोषित FUNC_STRUCT_PARAM_AS_PTR
        /* structs are passed as pointer */
        अगर ((type->t & VT_BTYPE) == VT_STRUCT) {
            आकार = 4;
        }
#पूर्ण_अगर
        अगर (param_सूचकांक < fastcall_nb_regs) {
            /* save FASTCALL register */
            loc -= 4;
            /* movl */
            gen_modrm(0x89, fastcall_regs_ptr[param_सूचकांक], VT_LOCAL, शून्य, loc);
            param_addr = loc;
        } अन्यथा {
            param_addr = addr;
            addr += आकार;
        }
        gfunc_set_param(sym, param_addr, 0);
        param_सूचकांक++;
    }
    func_ret_sub = 0;
    /* pascal type call or fastcall ? */
    अगर (func_call == FUNC_STDCALL || func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL)
        func_ret_sub = addr - 8;
#अगर !defined(TCC_TARGET_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    अन्यथा अगर (func_vc)
        func_ret_sub = 4;
#पूर्ण_अगर

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#पूर्ण_अगर
}

/* generate function epilog */
ST_FUNC व्योम gfunc_epilog(व्योम)
{
    addr_t v, saved_ind;

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#पूर्ण_अगर

    /* align local size to word & save local variables */
    v = (-loc + 3) & -4;

#अगर USE_EBX
    gen_modrm(0x8b, TREG_EBX, VT_LOCAL, शून्य, -(v+4));
#पूर्ण_अगर

    o(0xc9); /* leave */
    अगर (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } अन्यथा {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    saved_ind = ind;
    ind = func_sub_sp_offset - FUNC_PROLOG_आकार;
#अगर_घोषित TCC_TARGET_PE
    अगर (v >= 4096) {
        oad(0xb8, v); /* mov stacksize, %eax */
        gen_static_call(TOK___chkstk); /* call __chkstk, (does the stackframe too) */
    } अन्यथा
#पूर्ण_अगर
    {
        o(0xe58955);  /* push %ebp, mov %esp, %ebp */
        o(0xec81);  /* sub esp, stacksize */
        gen_le32(v);
#अगर_घोषित TCC_TARGET_PE
        o(0x90);  /* adjust to FUNC_PROLOG_SIZE */
#पूर्ण_अगर
    }
#अगर USE_EBX
    o(0x53); /* push ebx */
#पूर्ण_अगर
    ind = saved_ind;
}

/* generate a jump to a label */
ST_FUNC पूर्णांक gjmp(पूर्णांक t)
{
    वापस gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ST_FUNC व्योम gjmp_addr(पूर्णांक a)
{
    पूर्णांक r;
    r = a - ind - 2;
    अगर (r == (चिन्हित अक्षर)r) {
        g(0xeb);
        g(r);
    } अन्यथा {
        oad(0xe9, a - ind - 5);
    }
}

#अगर 0
/* generate a jump to a fixed address */
ST_FUNC व्योम gjmp_cond_addr(पूर्णांक a, पूर्णांक op)
{
    पूर्णांक r = a - ind - 2;
    अगर (r == (चिन्हित अक्षर)r)
        g(op - 32), g(r);
    अन्यथा
        g(0x0f), gjmp2(op - 16, r - 4);
}
#पूर्ण_अगर

ST_FUNC पूर्णांक gjmp_append(पूर्णांक n, पूर्णांक t)
{
    व्योम *p;
    /* insert vtop->c jump list in t */
    अगर (n) {
        uint32_t n1 = n, n2;
        जबतक ((n2 = read32le(p = cur_text_section->तथ्य + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    वापस t;
}

ST_FUNC पूर्णांक gjmp_cond(पूर्णांक op, पूर्णांक t)
{
    g(0x0f);
    t = gjmp2(op - 16, t);
    वापस t;
}

ST_FUNC व्योम gen_opi(पूर्णांक op)
{
    पूर्णांक r, fr, opc, c;

    चयन(op) {
    हाल '+':
    हाल TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        अगर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            अगर (c == (चिन्हित अक्षर)c) {
                /* generate inc and dec for smaller code */
                अगर ((c == 1 || c == -1) && (op == '+' || op == '-')) {
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
        अगर (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        अवरोध;
    हाल '-':
    हाल TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        जाओ gen_op8;
    हाल TOK_ADDC2: /* add with carry use */
        opc = 2;
        जाओ gen_op8;
    हाल TOK_SUBC2: /* sub with carry use */
        opc = 3;
        जाओ gen_op8;
    हाल '&':
        opc = 4;
        जाओ gen_op8;
    हाल '^':
        opc = 6;
        जाओ gen_op8;
    हाल '|':
        opc = 1;
        जाओ gen_op8;
    हाल '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        o(0xaf0f); /* imul fr, r */
        o(0xc0 + fr + r * 8);
        अवरोध;
    हाल TOK_SHL:
        opc = 4;
        जाओ gen_shift;
    हाल TOK_SHR:
        opc = 5;
        जाओ gen_shift;
    हाल TOK_SAR:
        opc = 7;
    gen_shift:
        opc = 0xc0 | (opc << 3);
        अगर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
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
        अवरोध;
    हाल '/':
    हाल TOK_UDIV:
    हाल TOK_PDIV:
    हाल '%':
    हाल TOK_UMOD:
    हाल TOK_UMULL:
        /* first operand must be in eax */
        /* XXX: need better constraint for second operand */
        gv2(RC_EAX, RC_ECX);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        save_reg(TREG_EDX);
        /* save EAX too if used otherwise */
        save_reg_upstack(TREG_EAX, 1);
        अगर (op == TOK_UMULL) {
            o(0xf7); /* mul fr */
            o(0xe0 + fr);
            vtop->r2 = TREG_EDX;
            r = TREG_EAX;
        } अन्यथा {
            अगर (op == TOK_UDIV || op == TOK_UMOD) {
                o(0xf7d231); /* xor %edx, %edx, div fr, %eax */
                o(0xf0 + fr);
            } अन्यथा {
                o(0xf799); /* cltd, idiv fr, %eax */
                o(0xf8 + fr);
            }
            अगर (op == '%' || op == TOK_UMOD)
                r = TREG_EDX;
            अन्यथा
                r = TREG_EAX;
        }
        vtop->r = r;
        अवरोध;
    शेष:
        opc = 7;
        जाओ gen_op8;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ST_FUNC व्योम gen_opf(पूर्णांक op)
{
    पूर्णांक a, ft, fc, swapped, r;

    अगर (op == TOK_NEG) { /* unary minus */
        gv(RC_FLOAT);
        o(0xe0d9); /* fchs */
        वापस;
    }

    /* convert constants to memory references */
    अगर ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    अगर ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(RC_FLOAT);

    /* must put at least one value in the floating point register */
    अगर ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    अगर (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    अगर (op >= TOK_ULT && op <= TOK_GT) {
        /* load on stack second operand */
        load(TREG_ST0, vtop);
        save_reg(TREG_EAX); /* eax is used by FP comparison code */
        अगर (op == TOK_GE || op == TOK_GT)
            swapped = !swapped;
        अन्यथा अगर (op == TOK_EQ || op == TOK_NE)
            swapped = 0;
        अगर (swapped)
            o(0xc9d9); /* fxch %st(1) */
        अगर (op == TOK_EQ || op == TOK_NE)
            o(0xe9da); /* fucompp */
        अन्यथा
            o(0xd9de); /* fcompp */
        o(0xe0df); /* fnstsw %ax */
        अगर (op == TOK_EQ) {
            o(0x45e480); /* and $0x45, %ah */
            o(0x40fC80); /* cmp $0x40, %ah */
        } अन्यथा अगर (op == TOK_NE) {
            o(0x45e480); /* and $0x45, %ah */
            o(0x40f480); /* xor $0x40, %ah */
            op = TOK_NE;
        } अन्यथा अगर (op == TOK_GE || op == TOK_LE) {
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
        अगर ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
            load(TREG_ST0, vtop);
            swapped = !swapped;
        }
        
        चयन(op) {
        शेष:
        हाल '+':
            a = 0;
            अवरोध;
        हाल '-':
            a = 4;
            अगर (swapped)
                a++;
            अवरोध;
        हाल '*':
            a = 1;
            अवरोध;
        हाल '/':
            a = 6;
            अगर (swapped)
                a++;
            अवरोध;
        }
        ft = vtop->type.t;
        fc = vtop->c.i;
        अगर ((ft & VT_BTYPE) == VT_LDOUBLE) {
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
        } अन्यथा {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            अगर ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_INT;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = शून्य;
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
ST_FUNC व्योम gen_cvt_itof(पूर्णांक t)
{
    save_reg(TREG_ST0);
    gv(RC_INT);
    अगर ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
        /* signed long long to float/double/long double (unsigned case
           is handled generically) */
        o(0x50 + vtop->r2); /* push r2 */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
        vtop->r2 = VT_CONST;
    } अन्यथा अगर ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
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
ST_FUNC व्योम gen_cvt_ftoi(पूर्णांक t)
{
    पूर्णांक bt = vtop->type.t & VT_BTYPE;
    अगर (bt == VT_FLOAT)
        vpush_helper_func(TOK___fixsfdi);
    अन्यथा अगर (bt == VT_LDOUBLE)
        vpush_helper_func(TOK___fixxfdi);
    अन्यथा
        vpush_helper_func(TOK___fixdfdi);
    vswap();
    gfunc_call(1);
    vpushi(0);
    vtop->r = REG_IRET;
    अगर ((t & VT_BTYPE) == VT_LLONG)
        vtop->r2 = REG_IRE2;
}

/* convert from one floating point type to another */
ST_FUNC व्योम gen_cvt_ftof(पूर्णांक t)
{
    /* all we have to do on i386 is to put the float in a register */
    gv(RC_FLOAT);
}

/* char/short to int conversion */
ST_FUNC व्योम gen_cvt_csti(पूर्णांक t)
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
ST_FUNC व्योम gen_increment_tcov (SValue *sv)
{
   पूर्णांक indir, rel, add1, add2;
#अगर defined CONFIG_TCC_PIC
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
#पूर्ण_अगर
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
ST_FUNC व्योम ggoto(व्योम)
{
    gcall_or_jmp(1);
    vtop--;
}

/* bound check support functions */
#अगर_घोषित CONFIG_TCC_BCHECK

/* Need PIC for shared libraries */
अटल व्योम gen_bound_call(पूर्णांक v)
{
    Sym *sym;

    sym = external_helper_sym(v);
#अगर defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EBX, 1);
    oad(0xe8, -4);
    greloc(cur_text_section, sym, ind - 4, R_386_PLT32);
#अन्यथा
    oad(0xe8, -4);
    greloc(cur_text_section, sym, ind - 4, R_386_PC32);
#पूर्ण_अगर
}

अटल व्योम gen_bounds_prolog(व्योम)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->तथ्य_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
#अगर defined CONFIG_TCC_PIC
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0x808d, 0); /* lea lbound section pointer */
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0xc381, 0); /* add _GLOBAL_OFFSET_TABLE_ */
    oad(0xb8, 0); /* call to function */
#अन्यथा
    oad(0xb8, 0); /* lbound section pointer */
    oad(0xb8, 0); /* call to function */
#पूर्ण_अगर
}

अटल व्योम gen_bounds_epilog(व्योम)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_तथ्य;
    पूर्णांक offset_modified = func_bound_offset != lbounds_section->तथ्य_offset;

    अगर (!offset_modified && !func_bound_add_epilog)
        वापस;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, माप(addr_t));
    *bounds_ptr = 0;

    sym_तथ्य = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_आकार);

    /* generate bound local allocation */
    अगर (offset_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
#अगर defined CONFIG_TCC_PIC
	get_pc_thunk(TREG_EAX, 0);
	o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
	greloc(cur_text_section, sym_तथ्य, ind, R_386_PC32);
	gen_le32(2);
#अन्यथा
        greloc(cur_text_section, sym_तथ्य, ind + 1, R_386_32);
        ind = ind + 5;
#पूर्ण_अगर
        gen_bound_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0x5250); /* save returned value, if any */
#अगर defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EAX, 0);
    o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
    greloc(cur_text_section, sym_तथ्य, ind, R_386_PC32);
    gen_le32(2);
#अन्यथा
    greloc(cur_text_section, sym_तथ्य, ind + 1, R_386_32);
    oad(0xb8, 0); /* mov %eax, xxx */
#पूर्ण_अगर
    gen_bound_call(TOK___bound_local_delete);
    o(0x585a); /* restore returned value, if any */
}
#पूर्ण_अगर

/* Save the stack pointer onto the stack */
ST_FUNC व्योम gen_vla_sp_save(पूर्णांक addr) {
    /* mov %esp,addr(%ebp)*/
    gen_modrm(0x89, TREG_ESP, VT_LOCAL, शून्य, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC व्योम gen_vla_sp_restore(पूर्णांक addr) {
    gen_modrm(0x8b, TREG_ESP, VT_LOCAL, शून्य, addr);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC व्योम gen_vla_alloc(CType *type, पूर्णांक align) {
    पूर्णांक use_call = 0;

#अगर defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_PE    /* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#पूर्ण_अगर
    अगर (use_call)
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
#पूर्ण_अगर
/*************************************************************/
