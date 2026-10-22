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

#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

/* number of available registers */
#నిర్వచించు NB_REGS         5
#నిర్వచించు NB_ASM_REGS     8
#నిర్వచించు CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#నిర్వచించు RC_INT     0x0001 /* generic integer register */
#నిర్వచించు RC_FLOAT   0x0002 /* generic float register */
#నిర్వచించు RC_EAX     0x0004
#నిర్వచించు RC_EDX     0x0008
#నిర్వచించు RC_ECX     0x0010
#నిర్వచించు RC_EBX     0x0020
#నిర్వచించు RC_ST0     0x0040

#నిర్వచించు RC_IRET    RC_EAX /* function return: integer register */
#నిర్వచించు RC_IRE2    RC_EDX /* function return: second integer register */
#నిర్వచించు RC_FRET    RC_ST0 /* function return: float register */

/* pretty names for the registers */
గణన {
    TREG_EAX = 0,
    TREG_ECX,
    TREG_EDX,
    TREG_EBX,
    TREG_ST0,
    TREG_ESP = 4,
    TREG_MEM = 0x20
};

#నిర్వచించు REG_విలువ(reg) ((reg) & 7)

/* return registers for function */
#నిర్వచించు REG_IRET TREG_EAX /* single word int return register */
#నిర్వచించు REG_IRE2 TREG_EDX /* second word return register (for long long) */
#నిర్వచించు REG_FRET TREG_ST0 /* float return register */

/* defined if function parameters must be evaluated in reverse order */
#నిర్వచించు INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#నిర్వచించు PTR_కొలత 4

/* long double size and alignment, in bytes */
#నిర్వచించు LDOUBLE_కొలత  12
#నిర్వచించు LDOUBLE_ALIGN 4
/* maximum alignment (for aligned attribute support) */
#నిర్వచించు MAX_ALIGN     8

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#నిర్వచించు PROMOTE_RET

/******************************************************/
#లేకపోతే /* ! TARGET_DEFS_ONLY */
/******************************************************/
#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"

ST_దత్తాంశం స్థిరరాశి అక్షరం * స్థిరరాశి లక్ష్యం_machine_defs =
    "__i386__\0"
    "__i386\0"
    ;

#ఒకవేళ defined CONFIG_TCC_PIC
# define USE_EBX 2
#లేకపోతే
# define USE_EBX 0 /* define to 1 to have EBX as 4th register */
#అయితే_ముగింపు

ST_దత్తాంశం స్థిరరాశి పూర్ణాంకం reg_classes[NB_REGS] = {
    /* eax */ RC_INT | RC_EAX,
    /* ecx */ RC_INT | RC_ECX,
    /* edx */ RC_INT | RC_EDX,
    /* ebx */ (RC_INT | RC_EBX) * (USE_EBX == 1),
    /* st0 */ RC_FLOAT | RC_ST0,
};

స్థిర గుర్తులేని దీర్ఘ func_sub_sp_స్థానభ్రంశం;
స్థిర పూర్ణాంకం func_ret_sub;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
స్థిర addr_t func_bound_స్థానభ్రంశం;
స్థిర గుర్తులేని దీర్ఘ func_bound_ind;
ST_దత్తాంశం పూర్ణాంకం func_bound_కూడు_epilog;
స్థిర శూన్య gen_bounds_prolog(శూన్య);
స్థిర శూన్య gen_bounds_epilog(శూన్య);
#అయితే_ముగింపు

/* XXX: make it faster ? */
ST_FUNC శూన్య g(పూర్ణాంకం c)
{
    పూర్ణాంకం ind1;
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    ind1 = ind + 1;
    ఒకవేళ (ind1 > cur_పాఠ్యం_section->దత్తాంశం_allocated)
        section_realloc(cur_పాఠ్యం_section, ind1);
    cur_పాఠ్యం_section->దత్తాంశం[ind] = c;
    ind = ind1;
}

ST_FUNC శూన్య o(గుర్తులేని పూర్ణాంకం c)
{
    అయితే (c) {
        g(c);
        c = c >> 8;
    }
}

ST_FUNC శూన్య gen_le16(పూర్ణాంకం v)
{
    g(v);
    g(v >> 8);
}

ST_FUNC శూన్య gen_le32(పూర్ణాంకం c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}

/* output a symbol and patch all calls to it */
ST_FUNC శూన్య gsym_addr(పూర్ణాంకం t, పూర్ణాంకం a)
{
    అయితే (t) {
        గుర్తులేని అక్షరం *ptr = cur_పాఠ్యం_section->దత్తాంశం + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a - t - 4);
        t = n;
    }
}

/* instruction + 4 bytes data. Return the address of the data */
స్థిర పూర్ణాంకం oad(పూర్ణాంకం c, పూర్ణాంకం s)
{
    పూర్ణాంకం t;
    ఒకవేళ (nocode_wanted)
        తిరిగి s;
    o(c);
    t = ind;
    gen_le32(s);
    తిరిగి t;
}

ST_FUNC శూన్య gen_fill_nops(పూర్ణాంకం బైట్లు)
{
    అయితే (బైట్లు--)
      g(0x90);
}

#ఒకవేళ defined CONFIG_TCC_PIC
స్థిర శూన్య gen_static_call(పూర్ణాంకం v);
స్థిర శూన్య get_pc_thunk(పూర్ణాంకం r, పూర్ణాంకం కూడు)
{
    స్థిర స్థిరరాశి అక్షరం * స్థిరరాశి pc_thunk_name[] = {
	"__x86.get_pc_thunk.ax",
	"__x86.get_pc_thunk.cx",
	"__x86.get_pc_thunk.dx",
	"__x86.get_pc_thunk.bx"
    };
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    gen_static_call(tok_alloc_const(pc_thunk_name[r]));
    ఒకవేళ (కూడు) {
        Sym label = {0};
        label.type.t = VT_VOID|VT_STATIC;
        put_extern_sym(&label, cur_పాఠ్యం_section, ind, 0);
        r = REG_విలువ(r);
	ఒకవేళ (r == 0)
	    oad(0x05, 1); /* add _GLOBAL_OFFSET_TABLE_, %eax */
	లేకపోతే
            oad(0xc081 + r * 0x100, 2); /* add _GLOBAL_OFFSET_TABLE_, %erx */
        greloc(cur_పాఠ్యం_section, &label, ind - 4, R_386_GOTPC);
    }
}

ST_FUNC శూన్య gen_gotpcrel(పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c)
{
    greloc(cur_పాఠ్యం_section, sym, ind, R_386_GOT32X);
    gen_le32(0);
    ఒకవేళ (c) {
	r = REG_విలువ(r);
	ఒకవేళ (r == 0)
            oad(0x05, c);
	లేకపోతే
            oad(0xc081 + r * 0x100, c);
    }
}
#అయితే_ముగింపు

/* generate jmp to a label */
#నిర్వచించు gjmp2(instr,lbl) oad(instr,lbl)

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC శూన్య gen_addr32(పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c)
{
    ఒకవేళ (r & VT_SYM)
        greloc(cur_పాఠ్యం_section, sym, ind, R_386_32);
    gen_le32(c);
}

ST_FUNC శూన్య gen_addrpc32(పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c)
{
    ఒకవేళ (r & VT_SYM)
        greloc(cur_పాఠ్యం_section, sym, ind, R_386_PC32);
    gen_le32(c - 4);
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode bits */
స్థిర శూన్య gen_modrm(పూర్ణాంకం opc, పూర్ణాంకం op_r2, పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c)
{
    పూర్ణాంకం op_reg = REG_విలువ(op_r2) << 3;

    ఒకవేళ ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        Sym *s2 = external_global_sym(TOK_tls_సూచీ, &int_type);
        r = get_reg(RC_INT);
        gen_modrm(0x8b, r, VT_SYM|VT_CONST, s2, 0); /* mov __tls_index, r */
        o(0x02e0c1 | r << 8); /* shl 2,r */
        oad(0x050364 | r << 19, 11*PTR_కొలత); /* add fs:0x2c,r */
        gen_modrm(0x8b, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        o(opc), oad(0x80 | op_reg | r, c); /* mov #c(r),op_reg */
        greloc(cur_పాఠ్యం_section, sym, ind - 4, R_386_TLS_LE);
#లేకపోతే
        o(0x65); /* gs segment prefix */
        o(opc), oad(0x05 | op_reg, c);
        greloc(cur_పాఠ్యం_section, sym, ind - 4, R_386_TLS_LE);
#అయితే_ముగింపు
#ఒకవేళ defined CONFIG_TCC_PIC
    } లేకపోతే ఒకవేళ ((r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
        పూర్ణాంకం is_got = (op_r2 & TREG_MEM) && !(sym->type.t & VT_STATIC);
        పూర్ణాంకం ఇక్కడ = ind;
        get_pc_thunk(TREG_EBX, is_got);
        o(opc);
        o(0x83 | op_reg);
        ఒకవేళ (is_got) {
            gen_gotpcrel(r, sym, c);
        } లేకపోతే {
            gen_addrpc32(r, sym, c + (ind - ఇక్కడ - 1));
        }
    } లేకపోతే ఒకవేళ ((r & VT_VALMASK) < VT_CONST && (r & TREG_MEM)) {
        o(opc);
        ఒకవేళ (c) {
            g(0x80 | op_reg | REG_విలువ(r));
            gen_le32(c);
        } లేకపోతే {
            g(0x00 | op_reg | REG_విలువ(r));
        }
#అయితే_ముగింపు
    } లేకపోతే ఒకవేళ ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
        o(opc);
        o(0x05 | op_reg);
        gen_addr32(r, sym, c);
    } లేకపోతే ఒకవేళ ((r & VT_VALMASK) == VT_LOCAL) {
	o(opc);
        /* currently, we use only ebp as base */
        ఒకవేళ (c == (గుర్తుగల అక్షరం)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } లేకపోతే {
            oad(0x85 | op_reg, c);
        }
    } లేకపోతే {
	o(opc);
        g(0x00 | op_reg | (r & VT_VALMASK));
    }
}

/* load 'r' from value 'sv' */
ST_FUNC శూన్య ఎక్కించు(పూర్ణాంకం r, SValue *sv)
{
    పూర్ణాంకం v, t, ft, fc, fr, opc;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~VT_DEFSIGN;
    fc = sv->c.i;
    ft &= ~VT_QUAL;
    v = fr & VT_VALMASK;

#ఒకవేళ defined CONFIG_TCC_PIC
    /* we use indirect access via got */
    ఒకవేళ ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        పూర్ణాంకం tr = r | TREG_MEM;
        ఒకవేళ (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm(0x8b, tr, fr, sv->sym, 0);
        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#అయితే_ముగింపు

    ఒకవేళ (fr & VT_LVAL) {
        ఒకవేళ (v == VT_LLOCAL) {
            v1.type.t = VT_INT;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
            v1.sym = ఖాళీ;
            fr = r;
            ఒకవేళ (!(reg_classes[fr] & RC_INT))
                fr = get_reg(RC_INT);
            ఎక్కించు(fr, &v1);
        }
        ఒకవేళ ((ft & VT_BTYPE) == VT_FLOAT) {
            opc = 0xd9; /* flds */
            r = 0;
        } లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_DOUBLE) {
            opc = 0xdd; /* fldl */
            r = 0;
        } లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            opc = 0xdb; /* fldt */
            r = 5;
        } లేకపోతే ఒకవేళ ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            opc = 0xbe0f;   /* movsbl */
        } లేకపోతే ఒకవేళ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED) ||
		   (ft & VT_TYPE) == (VT_BOOL | VT_UNSIGNED)) {
            opc = 0xb60f;   /* movzbl */
        } లేకపోతే ఒకవేళ ((ft & VT_TYPE) == VT_SHORT) {
            opc = 0xbf0f;   /* movswl */
        } లేకపోతే ఒకవేళ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            opc = 0xb70f;   /* movzwl */
        } లేకపోతే {
            opc = 0x8b;     /* movl */
        }
        gen_modrm(opc, r, fr, sv->sym, fc);
    } లేకపోతే {
        ఒకవేళ ((fr & VT_SYM) && (sv->sym->type.t & VT_TLS)) {
#నిర్వచితమైతే TCC_లక్ష్యం_PE
            gen_modrm(0x8d, r, fr, sv->sym, fc);
#లేకపోతే
            oad(0x058b65 | REG_విలువ(r) << 19, 0); /* mov gs:0,r */
            oad(0xC081 | REG_విలువ(r) << 8, fc); /* add tpoffs,r */
            greloc(cur_పాఠ్యం_section, sv->sym, ind - 4, R_386_TLS_LE);
#అయితే_ముగింపు
#ఒకవేళ defined CONFIG_TCC_PIC
        } లేకపోతే ఒకవేళ ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)) {
            ఒకవేళ (sv->sym->type.t & VT_STATIC) {
                get_pc_thunk(r, 0);
                o(0x808d | REG_విలువ(r) * 0x900); /* lea $xx(r), r */
                gen_addrpc32(fr, sv->sym, fc + 6);
            } లేకపోతే {
                get_pc_thunk(r, 1);
                o(0x808b | REG_విలువ(r) * 0x900); /* mov $xx(r), r */
                gen_gotpcrel(r, sv->sym, fc);
            }
#అయితే_ముగింపు
        } లేకపోతే ఒకవేళ (v == VT_CONST) {
            o(0xb8 + r); /* mov $xx, r */
            gen_addr32(fr, sv->sym, fc);
        } లేకపోతే ఒకవేళ (v == VT_LOCAL) {
            ఒకవేళ (fc) {
                /* lea xxx(%ebp), r */
                gen_modrm(0x8d, r, VT_LOCAL, sv->sym, fc);
            } లేకపోతే {
                o(0x89);
                o(0xe8 + r); /* mov %ebp, r */
            }
        } లేకపోతే ఒకవేళ (v == VT_CMP) {
            o(0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + r);
            o(0xc0b60f + r * 0x90000); /* movzbl %al, %eax */
        } లేకపోతే ఒకవేళ (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            oad(0xb8 + r, t); /* mov $1, r */
            o(0x05eb); /* jmp after */
            gsym(fc);
            oad(0xb8 + r, t ^ 1); /* mov $0, r */
        } లేకపోతే ఒకవేళ (v != r) {
            o(0x89);
            o(0xc0 + r + v * 8); /* mov v, r */
        }
    }
}

/* store register 'r' in lvalue 'v' */
ST_FUNC శూన్య store(పూర్ణాంకం r, SValue *v)
{
    పూర్ణాంకం fr, bt, fc, opc;

    bt = v->type.t & VT_BTYPE;

    /* XXX: incorrect if float reg to reg */
    ఒకవేళ (bt == VT_FLOAT) {
        opc = 0xd9; /* fsts */
        r = 2;
    } లేకపోతే ఒకవేళ (bt == VT_DOUBLE) {
        opc = 0xdd; /* fstpl */
        r = 2;
    } లేకపోతే ఒకవేళ (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0), fstpt */
        opc = 0xdb;
        r = 7;
    } లేకపోతే ఒకవేళ (bt == VT_SHORT) {
        opc = 0x8966;
    } లేకపోతే ఒకవేళ (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } లేకపోతే {
        opc = 0x89;
    }

    fc = v->c.i;
    fr = v->r & VT_VALMASK;

#ఒకవేళ defined CONFIG_TCC_PIC
    /* we need to access the variable via got */
    ఒకవేళ ((v->r & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
	get_pc_thunk(TREG_EBX, 1);
	o(0x9b8b); /* mov xx(%ebx),%ebx */
	gen_gotpcrel(TREG_EBX, v->sym, v->c.i);
	o(opc);
	o(3 + (r << 3));
    } లేకపోతే
#అయితే_ముగింపు

    ఒకవేళ (fr == VT_CONST || fr == VT_LOCAL || (v->r & VT_LVAL)) {
        gen_modrm(opc, r, v->r, v->sym, fc);
    } లేకపోతే ఒకవేళ (fr != r) {
	o(opc);
        o(0xc0 + fr + r * 8); /* mov r, fr */
    }
}

స్థిర శూన్య gadd_sp(పూర్ణాంకం val)
{
    ఒకవేళ (val == (గుర్తుగల అక్షరం)val) {
        o(0xc483);
        g(val);
    } లేకపోతే {
        oad(0xc481, val); /* add $xxx, %esp */
    }
}

#ఒకవేళ defined TCC_లక్ష్యం_PE || defined CONFIG_TCC_PIC
స్థిర శూన్య gen_static_call(పూర్ణాంకం v)
{
    Sym *sym;

    sym = external_helper_sym(v);
    oad(0xe8, -4);
    greloc(cur_పాఠ్యం_section, sym, ind - 4, R_386_PC32);
}
#అయితే_ముగింపు

/* 'is_jmp' is '1' if it is a jump */
స్థిర శూన్య gcall_or_jmp(పూర్ణాంకం is_jmp)
{
    పూర్ణాంకం r;
    ఒకవేళ ((vtop->r & (VT_VALMASK|VT_LVAL|VT_SYM)) == (VT_CONST|VT_SYM)) {
        /* constant and relocation case */
#ఒకవేళ defined CONFIG_TCC_PIC
	ఒకవేళ (!(vtop->sym->type.t & VT_STATIC)) {
	    get_pc_thunk(TREG_EBX, 1);
            oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
            greloc(cur_పాఠ్యం_section, vtop->sym, ind - 4, R_386_PLT32);
            తిరిగి;
	}
#అయితే_ముగింపు
        oad(0xe8 + is_jmp, vtop->c.i - 4); /* call/jmp im */
        greloc(cur_పాఠ్యం_section, vtop->sym, ind - 4, R_386_PC32);
    } లేకపోతే {
        /* otherwise, indirect call */
        r = gv(RC_INT);
        o(0xff); /* call/jmp *r */
        o(0xd0 + r + (is_jmp << 4));
    }
}

స్థిర స్థిరరాశి uint8_t fastcall_regs[3] = { TREG_EAX, TREG_EDX, TREG_ECX };
స్థిర స్థిరరాశి uint8_t fastcallw_regs[2] = { TREG_ECX, TREG_EDX };

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC పూర్ణాంకం gfunc_sret(CType *vt, పూర్ణాంకం variadic, CType *ret, పూర్ణాంకం *ret_align, పూర్ణాంకం *regsize)
{
#ఒకవేళ defined(TCC_లక్ష్యం_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    పూర్ణాంకం కొలత, align, nregs;
    *ret_align = 1; // Never have to re-align return values for x86
    *regsize = 4;
    కొలత = type_కొలత(vt, &align);
    ఒకవేళ (కొలత > 8 || (కొలత & (కొలత - 1)))
        తిరిగి 0;
    nregs = 1;
    ఒకవేళ (కొలత == 8)
        ret->t = VT_INT, nregs = 2;
    లేకపోతే ఒకవేళ (కొలత == 4)
        ret->t = VT_INT;
    లేకపోతే ఒకవేళ (కొలత == 2)
        ret->t = VT_SHORT;
    లేకపోతే
        ret->t = VT_BYTE;
    ret->ref = ఖాళీ;
    తిరిగి nregs;
#లేకపోతే
    *ret_align = 1; // Never have to re-align return values for x86
    తిరిగి 0;
#అయితే_ముగింపు
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ST_FUNC శూన్య gfunc_call(పూర్ణాంకం nb_వాదనలు)
{
    పూర్ణాంకం కొలత, align, r, వాదనలు_కొలత, i, func_call;
    Sym *func_sym;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gbound_వాదనలు(nb_వాదనలు);
#అయితే_ముగింపు

    save_regs(nb_వాదనలు + 1);

    వాదనలు_కొలత = 0;
    కొరకు(i = 0;i < nb_వాదనలు; i++) {
        ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
            కొలత = type_కొలత(&vtop->type, &align);
            /* align to stack align size */
            కొలత = (కొలత + 3) & ~3;
            /* allocate the necessary size on stack */
#నిర్వచితమైతే TCC_లక్ష్యం_PE
            ఒకవేళ (కొలత >= 4096) {
                save_reg(TREG_EDX);
                r = get_reg(RC_EAX);
                oad(0x68, కొలత); // push size
                /* cannot call normal 'alloca' with bound checking */
                gen_static_call(tok_alloc_const("__alloca"));
                gadd_sp(4);
            } లేకపోతే
#అయితే_ముగింపు
            {
                oad(0xec81, కొలత); /* sub $xxx, %esp */
                /* generate structure store */
                r = get_reg(RC_INT);
                o(0xe089 + (r << 8)); /* mov %esp, r */
            }
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
            vstore();
            వాదనలు_కొలత += కొలత;
        } లేకపోతే ఒకవేళ (is_float(vtop->type.t)) {
            gv(RC_FLOAT); /* only one float register */
            ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_FLOAT)
                కొలత = 4;
            లేకపోతే ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                కొలత = 8;
            లేకపోతే
                కొలత = 12;
            oad(0xec81, కొలత); /* sub $xxx, %esp */
            ఒకవేళ (కొలత == 12)
                o(0x7cdb);
            లేకపోతే
                o(0x5cd9 + కొలత - 4); /* fstp[s|l] 0(%esp) */
            g(0x24);
            g(0x00);
            వాదనలు_కొలత += కొలత;
        } లేకపోతే {
            /* simple type (currently always same size) */
            /* XXX: implicit cast ? */
            r = gv(RC_INT);
            ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
                కొలత = 8;
                o(0x50 + vtop->r2); /* push r */
            } లేకపోతే {
                కొలత = 4;
            }
            o(0x50 + r); /* push r */
            వాదనలు_కొలత += కొలత;
        }
        vtop--;
    }

    func_sym = vtop->type.ref;
    func_call = func_sym->f.func_call;
    /* fast call case */
    ఒకవేళ ((func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) ||
        func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL) {
        పూర్ణాంకం fastcall_nb_regs;
        స్థిరరాశి uint8_t *fastcall_regs_ptr;
        ఒకవేళ (func_call == FUNC_FASTCALLW) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 2;
        } లేకపోతే ఒకవేళ (func_call == FUNC_THISCALL) {
            fastcall_regs_ptr = fastcallw_regs;
            fastcall_nb_regs = 1;
        } లేకపోతే {
            fastcall_regs_ptr = fastcall_regs;
            fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        }
        కొరకు(i = 0;i < fastcall_nb_regs; i++) {
            ఒకవేళ (వాదనలు_కొలత <= 0)
                ఆపు;
            o(0x58 + fastcall_regs_ptr[i]); /* pop r */
            /* XXX: incorrect for struct/floats */
            వాదనలు_కొలత -= 4;
        }
    }
#ఒకవేళ !defined(TCC_లక్ష్యం_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    లేకపోతే ఒకవేళ ((vtop->type.ref->type.t & VT_BTYPE) == VT_STRUCT)
        వాదనలు_కొలత -= 4;
#అయితే_ముగింపు

    gcall_or_jmp(0);

    ఒకవేళ (వాదనలు_కొలత && func_call != FUNC_STDCALL && func_call != FUNC_THISCALL && func_call != FUNC_FASTCALLW)
        gadd_sp(వాదనలు_కొలత);
    vtop--;
}

#నిర్వచితమైతే TCC_లక్ష్యం_PE
#నిర్వచించు FUNC_PROLOG_కొలత (10 + !!USE_EBX)
#లేకపోతే
#నిర్వచించు FUNC_PROLOG_కొలత (9 + !!USE_EBX)
#అయితే_ముగింపు

/* generate function prolog of type 't' */
ST_FUNC శూన్య gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    పూర్ణాంకం addr, align, కొలత, func_call, fastcall_nb_regs;
    పూర్ణాంకం param_సూచీ, param_addr;
    స్థిరరాశి uint8_t *fastcall_regs_ptr;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    func_call = sym->f.func_call;
    addr = 8;
    loc = 0;
    func_vc = 0;

    ఒకవేళ (func_call >= FUNC_FASTCALL1 && func_call <= FUNC_FASTCALL3) {
        fastcall_nb_regs = func_call - FUNC_FASTCALL1 + 1;
        fastcall_regs_ptr = fastcall_regs;
    } లేకపోతే ఒకవేళ (func_call == FUNC_FASTCALLW) {
        fastcall_nb_regs = 2;
        fastcall_regs_ptr = fastcallw_regs;
    } లేకపోతే ఒకవేళ (func_call == FUNC_THISCALL) {
        fastcall_nb_regs = 1;
        fastcall_regs_ptr = fastcallw_regs;
    } లేకపోతే {
        fastcall_nb_regs = 0;
        fastcall_regs_ptr = ఖాళీ;
    }
    param_సూచీ = 0;

    ind += FUNC_PROLOG_కొలత;
    func_sub_sp_స్థానభ్రంశం = ind;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
#ఒకవేళ defined(TCC_లక్ష్యం_PE) || TARGETOS_FreeBSD || TARGETOS_OpenBSD
    కొలత = type_కొలత(&func_vt,&align);
    ఒకవేళ (((func_vt.t & VT_BTYPE) == VT_STRUCT)
        && (కొలత > 8 || (కొలత & (కొలత - 1)))) {
#లేకపోతే
    ఒకవేళ ((func_vt.t & VT_BTYPE) == VT_STRUCT) {
#అయితే_ముగింపు
        /* XXX: fastcall case ? */
        func_vc = addr;
        addr += 4;
        param_సూచీ++;
    }
    /* define parameters */
    అయితే ((sym = sym->తదుపరి) != ఖాళీ) {
        type = &sym->type;
        కొలత = type_కొలత(type, &align);
        కొలత = (కొలత + 3) & ~3;
#నిర్వచితమైతే FUNC_STRUCT_PARAM_AS_PTR
        /* structs are passed as pointer */
        ఒకవేళ ((type->t & VT_BTYPE) == VT_STRUCT) {
            కొలత = 4;
        }
#అయితే_ముగింపు
        ఒకవేళ (param_సూచీ < fastcall_nb_regs) {
            /* save FASTCALL register */
            loc -= 4;
            /* movl */
            gen_modrm(0x89, fastcall_regs_ptr[param_సూచీ], VT_LOCAL, ఖాళీ, loc);
            param_addr = loc;
        } లేకపోతే {
            param_addr = addr;
            addr += కొలత;
        }
        gfunc_సమితి_param(sym, param_addr, 0);
        param_సూచీ++;
    }
    func_ret_sub = 0;
    /* pascal type call or fastcall ? */
    ఒకవేళ (func_call == FUNC_STDCALL || func_call == FUNC_FASTCALLW || func_call == FUNC_THISCALL)
        func_ret_sub = addr - 8;
#ఒకవేళ !defined(TCC_లక్ష్యం_PE) && !TARGETOS_FreeBSD || TARGETOS_OpenBSD
    లేకపోతే ఒకవేళ (func_vc)
        func_ret_sub = 4;
#అయితే_ముగింపు

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#అయితే_ముగింపు
}

/* generate function epilog */
ST_FUNC శూన్య gfunc_epilog(శూన్య)
{
    addr_t v, saved_ind;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#అయితే_ముగింపు

    /* align local size to word & save local variables */
    v = (-loc + 3) & -4;

#ఒకవేళ USE_EBX
    gen_modrm(0x8b, TREG_EBX, VT_LOCAL, ఖాళీ, -(v+4));
#అయితే_ముగింపు

    o(0xc9); /* leave */
    ఒకవేళ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } లేకపోతే {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    saved_ind = ind;
    ind = func_sub_sp_స్థానభ్రంశం - FUNC_PROLOG_కొలత;
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    ఒకవేళ (v >= 4096) {
        oad(0xb8, v); /* mov stacksize, %eax */
        gen_static_call(TOK___chkstk); /* call __chkstk, (does the stackframe too) */
    } లేకపోతే
#అయితే_ముగింపు
    {
        o(0xe58955);  /* push %ebp, mov %esp, %ebp */
        o(0xec81);  /* sub esp, stacksize */
        gen_le32(v);
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        o(0x90);  /* adjust to FUNC_PROLOG_SIZE */
#అయితే_ముగింపు
    }
#ఒకవేళ USE_EBX
    o(0x53); /* push ebx */
#అయితే_ముగింపు
    ind = saved_ind;
}

/* generate a jump to a label */
ST_FUNC పూర్ణాంకం gjmp(పూర్ణాంకం t)
{
    తిరిగి gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
ST_FUNC శూన్య gjmp_addr(పూర్ణాంకం a)
{
    పూర్ణాంకం r;
    r = a - ind - 2;
    ఒకవేళ (r == (గుర్తుగల అక్షరం)r) {
        g(0xeb);
        g(r);
    } లేకపోతే {
        oad(0xe9, a - ind - 5);
    }
}

#ఒకవేళ 0
/* generate a jump to a fixed address */
ST_FUNC శూన్య gjmp_cond_addr(పూర్ణాంకం a, పూర్ణాంకం op)
{
    పూర్ణాంకం r = a - ind - 2;
    ఒకవేళ (r == (గుర్తుగల అక్షరం)r)
        g(op - 32), g(r);
    లేకపోతే
        g(0x0f), gjmp2(op - 16, r - 4);
}
#అయితే_ముగింపు

ST_FUNC పూర్ణాంకం gjmp_append(పూర్ణాంకం n, పూర్ణాంకం t)
{
    శూన్య *p;
    /* insert vtop->c jump list in t */
    ఒకవేళ (n) {
        uint32_t n1 = n, n2;
        అయితే ((n2 = read32le(p = cur_పాఠ్యం_section->దత్తాంశం + n1)))
            n1 = n2;
        write32le(p, t);
        t = n;
    }
    తిరిగి t;
}

ST_FUNC పూర్ణాంకం gjmp_cond(పూర్ణాంకం op, పూర్ణాంకం t)
{
    g(0x0f);
    t = gjmp2(op - 16, t);
    తిరిగి t;
}

ST_FUNC శూన్య gen_opi(పూర్ణాంకం op)
{
    పూర్ణాంకం r, fr, opc, c;

    ఎంపిక(op) {
    స్థితి '+':
    స్థితి TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            ఒకవేళ (c == (గుర్తుగల అక్షరం)c) {
                /* generate inc and dec for smaller code */
                ఒకవేళ ((c == 1 || c == -1) && (op == '+' || op == '-')) {
                    opc = (c == 1) ^ (op == '+');
                    o (0x40 | (opc << 3) | r); // inc,dec
                } లేకపోతే {
                    o(0x83);
                    o(0xc0 | (opc << 3) | r);
                    g(c);
                }
            } లేకపోతే {
                o(0x81);
                oad(0xc0 | (opc << 3) | r, c);
            }
        } లేకపోతే {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            o((opc << 3) | 0x01);
            o(0xc0 + r + fr * 8); 
        }
        vtop--;
        ఒకవేళ (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(op);
        ఆపు;
    స్థితి '-':
    స్థితి TOK_SUBC1: /* sub with carry generation */
        opc = 5;
        వెళ్ళు gen_op8;
    స్థితి TOK_ADDC2: /* add with carry use */
        opc = 2;
        వెళ్ళు gen_op8;
    స్థితి TOK_SUBC2: /* sub with carry use */
        opc = 3;
        వెళ్ళు gen_op8;
    స్థితి '&':
        opc = 4;
        వెళ్ళు gen_op8;
    స్థితి '^':
        opc = 6;
        వెళ్ళు gen_op8;
    స్థితి '|':
        opc = 1;
        వెళ్ళు gen_op8;
    స్థితి '*':
        gv2(RC_INT, RC_INT);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        o(0xaf0f); /* imul fr, r */
        o(0xc0 + fr + r * 8);
        ఆపు;
    స్థితి TOK_SHL:
        opc = 4;
        వెళ్ళు gen_జరుపు;
    స్థితి TOK_SHR:
        opc = 5;
        వెళ్ళు gen_జరుపు;
    స్థితి TOK_SAR:
        opc = 7;
    gen_జరుపు:
        opc = 0xc0 | (opc << 3);
        ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i & 0x1f;
            o(0xc1); /* shl/shr/sar $xxx, r */
            o(opc | r);
            g(c);
        } లేకపోతే {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_ECX);
            r = vtop[-1].r;
            o(0xd3); /* shl/shr/sar %cl, r */
            o(opc | r);
        }
        vtop--;
        ఆపు;
    స్థితి '/':
    స్థితి TOK_UDIV:
    స్థితి TOK_PDIV:
    స్థితి '%':
    స్థితి TOK_UMOD:
    స్థితి TOK_UMULL:
        /* first operand must be in eax */
        /* XXX: need better constraint for second operand */
        gv2(RC_EAX, RC_ECX);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        save_reg(TREG_EDX);
        /* save EAX too if used otherwise */
        save_reg_upstack(TREG_EAX, 1);
        ఒకవేళ (op == TOK_UMULL) {
            o(0xf7); /* mul fr */
            o(0xe0 + fr);
            vtop->r2 = TREG_EDX;
            r = TREG_EAX;
        } లేకపోతే {
            ఒకవేళ (op == TOK_UDIV || op == TOK_UMOD) {
                o(0xf7d231); /* xor %edx, %edx, div fr, %eax */
                o(0xf0 + fr);
            } లేకపోతే {
                o(0xf799); /* cltd, idiv fr, %eax */
                o(0xf8 + fr);
            }
            ఒకవేళ (op == '%' || op == TOK_UMOD)
                r = TREG_EDX;
            లేకపోతే
                r = TREG_EAX;
        }
        vtop->r = r;
        ఆపు;
    అప్రమేయ:
        opc = 7;
        వెళ్ళు gen_op8;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
ST_FUNC శూన్య gen_opf(పూర్ణాంకం op)
{
    పూర్ణాంకం a, ft, fc, swapped, r;

    ఒకవేళ (op == TOK_NEG) { /* unary minus */
        gv(RC_FLOAT);
        o(0xe0d9); /* fchs */
        తిరిగి;
    }

    /* convert constants to memory references */
    ఒకవేళ ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    ఒకవేళ ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(RC_FLOAT);

    /* must put at least one value in the floating point register */
    ఒకవేళ ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(RC_FLOAT);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    ఒకవేళ (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    ఒకవేళ (op >= TOK_ULT && op <= TOK_GT) {
        /* load on stack second operand */
        ఎక్కించు(TREG_ST0, vtop);
        save_reg(TREG_EAX); /* eax is used by FP comparison code */
        ఒకవేళ (op == TOK_GE || op == TOK_GT)
            swapped = !swapped;
        లేకపోతే ఒకవేళ (op == TOK_EQ || op == TOK_NE)
            swapped = 0;
        ఒకవేళ (swapped)
            o(0xc9d9); /* fxch %st(1) */
        ఒకవేళ (op == TOK_EQ || op == TOK_NE)
            o(0xe9da); /* fucompp */
        లేకపోతే
            o(0xd9de); /* fcompp */
        o(0xe0df); /* fnstsw %ax */
        ఒకవేళ (op == TOK_EQ) {
            o(0x45e480); /* and $0x45, %ah */
            o(0x40fC80); /* cmp $0x40, %ah */
        } లేకపోతే ఒకవేళ (op == TOK_NE) {
            o(0x45e480); /* and $0x45, %ah */
            o(0x40f480); /* xor $0x40, %ah */
            op = TOK_NE;
        } లేకపోతే ఒకవేళ (op == TOK_GE || op == TOK_LE) {
            o(0x05c4f6); /* test $0x05, %ah */
            op = TOK_EQ;
        } లేకపోతే {
            o(0x45c4f6); /* test $0x45, %ah */
            op = TOK_EQ;
        }
        vtop--;
        vset_VT_CMP(op);
    } లేకపోతే {
        /* no memory reference possible for long double operations */
        ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
            ఎక్కించు(TREG_ST0, vtop);
            swapped = !swapped;
        }
        
        ఎంపిక(op) {
        అప్రమేయ:
        స్థితి '+':
            a = 0;
            ఆపు;
        స్థితి '-':
            a = 4;
            ఒకవేళ (swapped)
                a++;
            ఆపు;
        స్థితి '*':
            a = 1;
            ఆపు;
        స్థితి '/':
            a = 6;
            ఒకవేళ (swapped)
                a++;
            ఆపు;
        }
        ft = vtop->type.t;
        fc = vtop->c.i;
        ఒకవేళ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
        } లేకపోతే {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            ఒకవేళ ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_INT;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = ఖాళీ;
                ఎక్కించు(r, &v1);
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
ST_FUNC శూన్య gen_cvt_itof(పూర్ణాంకం t)
{
    save_reg(TREG_ST0);
    gv(RC_INT);
    ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
        /* signed long long to float/double/long double (unsigned case
           is handled generically) */
        o(0x50 + vtop->r2); /* push r2 */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
        vtop->r2 = VT_CONST;
    } లేకపోతే ఒకవేళ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
               (VT_INT | VT_UNSIGNED)) {
        /* unsigned int to float/double/long double */
        o(0x6a); /* push $0 */
        g(0x00);
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x242cdf); /* fildll (%esp) */
        o(0x08c483); /* add $8, %esp */
    } లేకపోతే {
        /* int to float/double/long double */
        o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
        o(0x2404db); /* fildl (%esp) */
        o(0x04c483); /* add $4, %esp */
    }
    vtop->r2 = VT_CONST;
    vtop->r = TREG_ST0;
}

/* convert fp to int 't' type */
ST_FUNC శూన్య gen_cvt_ftoi(పూర్ణాంకం t)
{
    పూర్ణాంకం bt = vtop->type.t & VT_BTYPE;
    ఒకవేళ (bt == VT_FLOAT)
        vpush_helper_func(TOK___fixsfdi);
    లేకపోతే ఒకవేళ (bt == VT_LDOUBLE)
        vpush_helper_func(TOK___fixxfdi);
    లేకపోతే
        vpush_helper_func(TOK___fixdfdi);
    vswap();
    gfunc_call(1);
    vpushi(0);
    vtop->r = REG_IRET;
    ఒకవేళ ((t & VT_BTYPE) == VT_LLONG)
        vtop->r2 = REG_IRE2;
}

/* convert from one floating point type to another */
ST_FUNC శూన్య gen_cvt_ftof(పూర్ణాంకం t)
{
    /* all we have to do on i386 is to put the float in a register */
    gv(RC_FLOAT);
}

/* char/short to int conversion */
ST_FUNC శూన్య gen_cvt_csti(పూర్ణాంకం t)
{
    పూర్ణాంకం r, sz, xl;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    o(0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (r << 3 | r) << 16
        );
}

/* increment tcov counter */
ST_FUNC శూన్య gen_increment_tcov (SValue *sv)
{
   పూర్ణాంకం indir, rel, add1, add2;
#ఒకవేళ defined CONFIG_TCC_PIC
   get_pc_thunk(TREG_EBX, 0);
   indir = 0x8300;
   rel = R_386_PC32;
   add1 = 2;
   add2 = 13;
#లేకపోతే
   indir = 0x0500;
   rel = R_386_32;
   add1 = 0;
   add2 = 4;
#అయితే_ముగింపు
   o(0x0083 + indir); /* addl $1, xxx(%ebx) */
   greloc(cur_పాఠ్యం_section, sv->sym, ind, rel);
   gen_le32(add1);
   o(1);
   o(0x1083 + indir); /* adcl $0, xxx(%ebx) */
   greloc(cur_పాఠ్యం_section, sv->sym, ind, rel);
   gen_le32(add2);
   g(0);
}

/* computed goto support */
ST_FUNC శూన్య ggoto(శూన్య)
{
    gcall_or_jmp(1);
    vtop--;
}

/* bound check support functions */
#నిర్వచితమైతే CONFIG_TCC_BCHECK

/* Need PIC for shared libraries */
స్థిర శూన్య gen_bound_call(పూర్ణాంకం v)
{
    Sym *sym;

    sym = external_helper_sym(v);
#ఒకవేళ defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EBX, 1);
    oad(0xe8, -4);
    greloc(cur_పాఠ్యం_section, sym, ind - 4, R_386_PLT32);
#లేకపోతే
    oad(0xe8, -4);
    greloc(cur_పాఠ్యం_section, sym, ind - 4, R_386_PC32);
#అయితే_ముగింపు
}

స్థిర శూన్య gen_bounds_prolog(శూన్య)
{
    /* leave some room for bound checking code */
    func_bound_స్థానభ్రంశం = lbounds_section->దత్తాంశం_స్థానభ్రంశం;
    func_bound_ind = ind;
    func_bound_కూడు_epilog = 0;
#ఒకవేళ defined CONFIG_TCC_PIC
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0x808d, 0); /* lea lbound section pointer */
    oad(0xb8, 0); /* call to pc_thunk function */
    oad(0xc381, 0); /* add _GLOBAL_OFFSET_TABLE_ */
    oad(0xb8, 0); /* call to function */
#లేకపోతే
    oad(0xb8, 0); /* lbound section pointer */
    oad(0xb8, 0); /* call to function */
#అయితే_ముగింపు
}

స్థిర శూన్య gen_bounds_epilog(శూన్య)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_దత్తాంశం;
    పూర్ణాంకం స్థానభ్రంశం_modified = func_bound_స్థానభ్రంశం != lbounds_section->దత్తాంశం_స్థానభ్రంశం;

    ఒకవేళ (!స్థానభ్రంశం_modified && !func_bound_కూడు_epilog)
        తిరిగి;

    /* add end of table info */
    bounds_ptr = section_ptr_కూడు(lbounds_section, పరిమాణం(addr_t));
    *bounds_ptr = 0;

    sym_దత్తాంశం = get_sym_ref(&char_సూచిక_type, lbounds_section,
                           func_bound_స్థానభ్రంశం, PTR_కొలత);

    /* generate bound local allocation */
    ఒకవేళ (స్థానభ్రంశం_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
#ఒకవేళ defined CONFIG_TCC_PIC
	get_pc_thunk(TREG_EAX, 0);
	o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
	greloc(cur_పాఠ్యం_section, sym_దత్తాంశం, ind, R_386_PC32);
	gen_le32(2);
#లేకపోతే
        greloc(cur_పాఠ్యం_section, sym_దత్తాంశం, ind + 1, R_386_32);
        ind = ind + 5;
#అయితే_ముగింపు
        gen_bound_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0x5250); /* save returned value, if any */
#ఒకవేళ defined CONFIG_TCC_PIC
    get_pc_thunk(TREG_EAX, 0);
    o(0x808d | TREG_EAX * 0x900); /* lea $xx(r), r */
    greloc(cur_పాఠ్యం_section, sym_దత్తాంశం, ind, R_386_PC32);
    gen_le32(2);
#లేకపోతే
    greloc(cur_పాఠ్యం_section, sym_దత్తాంశం, ind + 1, R_386_32);
    oad(0xb8, 0); /* mov %eax, xxx */
#అయితే_ముగింపు
    gen_bound_call(TOK___bound_local_delete);
    o(0x585a); /* restore returned value, if any */
}
#అయితే_ముగింపు

/* Save the stack pointer onto the stack */
ST_FUNC శూన్య gen_vla_sp_save(పూర్ణాంకం addr) {
    /* mov %esp,addr(%ebp)*/
    gen_modrm(0x89, TREG_ESP, VT_LOCAL, ఖాళీ, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC శూన్య gen_vla_sp_restore(పూర్ణాంకం addr) {
    gen_modrm(0x8b, TREG_ESP, VT_LOCAL, ఖాళీ, addr);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC శూన్య gen_vla_alloc(CType *type, పూర్ణాంకం align) {
    పూర్ణాంకం use_call = 0;

#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_PE    /* alloca does more than just adjust %rsp on Windows */
    use_call = 1;
#అయితే_ముగింపు
    ఒకవేళ (use_call)
    {
        vpush_helper_func(TOK_alloca);
        vswap(); /* Move alloca ref past allocation size */
        gfunc_call(1);
    }
    లేకపోతే {
        పూర్ణాంకం r;
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
#అయితే_ముగింపు
/*************************************************************/
