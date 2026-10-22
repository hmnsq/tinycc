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

#अगर_घोषित TARGET_DEFS_ONLY

/* number of available registers */
#घोषणा NB_REGS         25
#घोषणा NB_ASM_REGS     16
#घोषणा CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#घोषणा RC_INT     0x0001 /* generic integer register */
#घोषणा RC_FLOAT   0x0002 /* generic float register */
#घोषणा RC_RAX     0x0004
#घोषणा RC_RDX     0x0008
#घोषणा RC_RCX     0x0010
#घोषणा RC_RSI     0x0020
#घोषणा RC_RDI     0x0040
#घोषणा RC_ST0     0x0080 /* only for long double */
#घोषणा RC_R8      0x0100
#घोषणा RC_R9      0x0200
#घोषणा RC_R10     0x0400
#घोषणा RC_R11     0x0800
#घोषणा RC_XMM0    0x1000
#घोषणा RC_XMM1    0x2000
#घोषणा RC_XMM2    0x4000
#घोषणा RC_XMM3    0x8000
#घोषणा RC_XMM4    0x10000
#घोषणा RC_XMM5    0x20000
#घोषणा RC_XMM6    0x40000
#घोषणा RC_XMM7    0x80000
#घोषणा RC_IRET    RC_RAX /* function return: integer register */
#घोषणा RC_IRE2    RC_RDX /* function return: second integer register */
#घोषणा RC_FRET    RC_XMM0 /* function return: float register */
#घोषणा RC_FRE2    RC_XMM1 /* function return: second float register */

/* pretty names for the registers */
क्रमागत {
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

#घोषणा REX_BASE(reg) (((reg) >> 3) & 1)
#घोषणा REG_मूल्य(reg) ((reg) & 7)

/* return registers for function */
#घोषणा REG_IRET TREG_RAX /* single word int return register */
#घोषणा REG_IRE2 TREG_RDX /* second word return register (for long long) */
#घोषणा REG_FRET TREG_XMM0 /* float return register */
#घोषणा REG_FRE2 TREG_XMM1 /* second float return register */

/* defined if function parameters must be evaluated in reverse order */
#घोषणा INVERT_FUNC_PARAMS

/* pointer size, in bytes */
#घोषणा PTR_आकार 8

/* long double size and alignment, in bytes */
#घोषणा LDOUBLE_आकार  16
#घोषणा LDOUBLE_ALIGN 16
/* maximum alignment (for aligned attribute support) */
#घोषणा MAX_ALIGN     16

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#घोषणा PROMOTE_RET

#घोषणा TCC_TARGET_NATIVE_STRUCT_COPY
ST_FUNC व्योम gen_struct_copy(पूर्णांक आकार);

/******************************************************/
#अन्यथा /* ! TARGET_DEFS_ONLY */
/******************************************************/
#घोषणा USING_GLOBALS
#समावेश "tcc.h"
#समावेश <assert.h>

ST_तथ्य स्थिर अक्षर * स्थिर target_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_तथ्य स्थिर पूर्णांक reg_classes[NB_REGS] = {
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

अटल अचिन्हित दीर्घ func_sub_sp_offset;
अटल पूर्णांक func_ret_sub;

#अगर defined(CONFIG_TCC_BCHECK)
अटल addr_t func_bound_offset;
अटल अचिन्हित दीर्घ func_bound_ind;
ST_तथ्य पूर्णांक func_bound_add_epilog;
#पूर्ण_अगर

#अगर_घोषित TCC_TARGET_PE
अटल पूर्णांक func_scratch, func_alloca;
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

ST_FUNC व्योम gen_le64(int64_t c)
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

अटल व्योम orex(पूर्णांक ll, पूर्णांक r, पूर्णांक r2, पूर्णांक b)
{
    अगर ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    अगर ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    अगर (ll || REX_BASE(r) || REX_BASE(r2)) {
        अगर ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_BASE(r) | (REX_BASE(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC व्योम gsym_addr(पूर्णांक t, पूर्णांक a)
{
    जबतक (t) {
        अचिन्हित अक्षर *ptr = cur_text_section->तथ्य + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

अटल पूर्णांक is64_type(पूर्णांक t)
{
    वापस ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
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

/* generate jmp to a label */
#घोषणा gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC व्योम gen_addr32(पूर्णांक r, Sym *sym, पूर्णांक c)
{
    अगर (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC व्योम gen_addrpc32(पूर्णांक r, Sym *sym, पूर्णांक c)
{
    अगर (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
अटल व्योम gen_gotpcrel(पूर्णांक r, Sym *sym, पूर्णांक c)
{
#अगर_घोषित TCC_TARGET_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, शून्य), c, r,
        cur_text_section->तथ्य[ind-3],
        cur_text_section->तथ्य[ind-2],
        cur_text_section->तथ्य[ind-1]
        );
#पूर्ण_अगर
    greloca(cur_text_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    अगर (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_मूल्य(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
अटल व्योम gen_modrm_impl(पूर्णांक opcode, पूर्णांक ll, पूर्णांक op_reg_0, पूर्णांक r, Sym *sym, पूर्णांक c)
{
    पूर्णांक op_reg = REG_मूल्य(op_reg_0) << 3;

    अगर ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#अगर_घोषित TCC_TARGET_PE
        Sym *s2 = external_global_sym(TOK_tls_सूचकांक, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_आकार); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#अन्यथा
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_text_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#पूर्ण_अगर
        वापस;
    }

    orex(ll, r, op_reg_0, opcode);

    अगर ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	अगर (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} अन्यथा {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    अगर (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } अन्यथा {
		gen_addrpc32(r, sym, c);
	    }
	}
    } अन्यथा अगर ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        अगर (c == (चिन्हित अक्षर)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } अन्यथा {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } अन्यथा अगर ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_मूल्य(r));
        gen_le32(c);
    } अन्यथा अगर (r & VT_LVAL) {
        g(0x00 | op_reg | REG_मूल्य(r));
    } अन्यथा {
        g(0xc0 | op_reg | REG_मूल्य(r));
    }
}

अटल व्योम gen_modrm64(पूर्णांक opcode, पूर्णांक op_reg, पूर्णांक r, Sym *sym, पूर्णांक c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

अटल व्योम gen_modrm32(पूर्णांक opcode, पूर्णांक op_reg, पूर्णांक r, Sym *sym, पूर्णांक c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
व्योम load(पूर्णांक r, SValue *sv)
{
    पूर्णांक v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    अगर (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#अगर_अघोषित TCC_TARGET_PE
    /* we use indirect access via got */
    अगर ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        पूर्णांक tr = r | TREG_MEM;
        अगर (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#पूर्ण_अगर

    v = fr & VT_VALMASK;
    अगर (fr & VT_LVAL) {
        पूर्णांक b, ll;
        अगर (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = शून्य;
            fr = r;
            अगर (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            load(fr, &v1);
            fr |= VT_LVAL;
        }
	अगर (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = शून्य;
	    fr = r;
	    अगर (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    load(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	अगर ((ft & VT_BTYPE) == VT_STRUCT) {
	    पूर्णांक align;
	    चयन (type_आकार(&sv->type, &align)) {
		हाल 1: ft = VT_BYTE; अवरोध;
		हाल 2: ft = VT_SHORT; अवरोध;
		हाल 4: ft = VT_INT; अवरोध;
		हाल 8: ft = VT_LLONG; अवरोध;
		शेष:
		    tcc_error("invalid aggregate type for register load");
		    अवरोध;
	    }
	}
        अगर ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_मूल्य(r); /* movd */
        } अन्यथा अगर ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_मूल्य(r);
        } अन्यथा अगर ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } अन्यथा अगर ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } अन्यथा अगर ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } अन्यथा अगर ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } अन्यथा अगर ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } अन्यथा अगर ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            वापस;
        } अन्यथा {
            निश्चित(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } अन्यथा {
        अगर (v == VT_CONST) {
            अगर (fr & VT_SYM) {
#अगर_घोषित TCC_TARGET_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#अन्यथा
                अगर (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, शून्य, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_मूल्य(r), 0);
                    greloca(cur_text_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } अन्यथा अगर (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_मूल्य(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } अन्यथा {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_मूल्य(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#पूर्ण_अगर
            } अन्यथा अगर (is64_type(ft)) {
                अगर (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_मूल्य(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } अन्यथा अगर (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_मूल्य(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } अन्यथा {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_मूल्य(r) * 9);
                }
            } अन्यथा {
                orex(0,r,0, 0xb8 + REG_मूल्य(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } अन्यथा अगर (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } अन्यथा अगर (v == VT_CMP) {
	    अगर (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_मूल्य(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_BASE(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_मूल्य(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_मूल्य(r) * 0x900); /* movzbl %al, %eax */
        } अन्यथा अगर (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_मूल्य(r), t); /* mov $1, r */
            o(0x05eb + (REX_BASE(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_मूल्य(r), t ^ 1); /* mov $0, r */
        } अन्यथा अगर (v != r) {
            अगर ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                अगर (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_मूल्य(r)*8); /* %xmmN */
                    o(0xf024);
                } अन्यथा {
                    निश्चित((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    अगर ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } अन्यथा {
                        निश्चित((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_मूल्य(v) + REG_मूल्य(r)*8);
                }
            } अन्यथा अगर (r == TREG_ST0) {
                निश्चित((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_मूल्य(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } अन्यथा {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_मूल्य(r) + REG_मूल्य(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
व्योम store(पूर्णांक r, SValue *v)
{
    पूर्णांक fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    पूर्णांक opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    अगर (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#अगर_अघोषित TCC_TARGET_PE
    /* we need to access the variable via got */
    अगर ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#पूर्ण_अगर

    /* XXX: incorrect if float reg to reg */
    अगर (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_मूल्य(r);
    } अन्यथा अगर (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_मूल्य(r);
    } अन्यथा अगर (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } अन्यथा अगर (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } अन्यथा {
        opc = 0x89;
        अगर (bt == VT_SHORT)
            opc = 0x8966;
        अन्यथा अगर (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
अटल व्योम gcall_or_jmp(पूर्णांक is_jmp)
{
    पूर्णांक r;
    अगर ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (पूर्णांक)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_text_section, vtop->sym, ind + 1, R_X86_64_PLT32, (पूर्णांक)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } अन्यथा {
        /* otherwise, indirect call */
        r = TREG_R11;
        load(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_मूल्य(r) + (is_jmp << 4));
    }
}

#अगर defined(CONFIG_TCC_BCHECK)

अटल व्योम gen_bounds_call(पूर्णांक v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#अगर_घोषित TCC_TARGET_PE
# define TREG_FASTCALL_1 TREG_RCX
#अन्यथा
# define TREG_FASTCALL_1 TREG_RDI
#पूर्ण_अगर

अटल व्योम gen_bounds_prolog(व्योम)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->तथ्य_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
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
        greloca(cur_text_section, sym_तथ्य, ind + 3, R_X86_64_PC32, -4);
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
    greloca(cur_text_section, sym_तथ्य, ind + 3, R_X86_64_PC32, -4);
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /* lea xxx(%rip), %rcx/rdi */
    gen_le32 (0);
    gen_bounds_call(TOK___bound_local_delete);
    o(0x280f);     /* movaps 0x10(%rsp),%xmm0 */
    o(0x102444);
    o(0x240c280f); /* movaps (%rsp),%xmm1 */
    o(0x20c48348); /* add $32,%rsp */
    o(0x585a); /* restore returned value, if any */
}
#पूर्ण_अगर

#अगर_घोषित TCC_TARGET_PE

#घोषणा REGN 4
अटल स्थिर uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
अटल पूर्णांक arg_prepare_reg(पूर्णांक idx) {
  अगर (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      वापस idx + 10;
  अन्यथा
      वापस idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

अटल व्योम gen_offs_sp(पूर्णांक b, पूर्णांक r, पूर्णांक d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    अगर (d == (चिन्हित अक्षर)d) {
        o(0x2444 | (REG_मूल्य(r) << 3));
        g(d);
    } अन्यथा {
        o(0x2484 | (REG_मूल्य(r) << 3));
        gen_le32(d);
    }
}

अटल पूर्णांक using_regs(पूर्णांक आकार)
{
    वापस !(आकार > 8 || (आकार & (आकार - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC पूर्णांक gfunc_sret(CType *vt, पूर्णांक variadic, CType *ret, पूर्णांक *ret_align, पूर्णांक *regsize)
{
    पूर्णांक आकार, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    आकार = type_आकार(vt, &align);
    अगर (!using_regs(आकार))
        वापस 0;
    अगर (आकार == 8)
        ret->t = VT_LLONG;
    अन्यथा अगर (आकार == 4)
        ret->t = VT_INT;
    अन्यथा अगर (आकार == 2)
        ret->t = VT_SHORT;
    अन्यथा
        ret->t = VT_BYTE;
    ret->ref = शून्य;
    वापस 1;
}

अटल पूर्णांक is_sse_float(पूर्णांक t) {
    पूर्णांक bt;
    bt = t & VT_BTYPE;
    वापस bt == VT_DOUBLE || bt == VT_FLOAT;
}

अटल पूर्णांक gfunc_arg_आकार(CType *type) {
    पूर्णांक align;
    अगर (type->t & (VT_ARRAY|VT_BITFIELD))
        वापस 8;
    वापस type_आकार(type, &align);
}

व्योम gfunc_call(पूर्णांक nb_args)
{
    पूर्णांक आकार, r, args_आकार, i, d, bt, struct_आकार;
    पूर्णांक arg;

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#पूर्ण_अगर

    save_regs(nb_args);

    args_आकार = (nb_args < REGN ? REGN : nb_args) * PTR_आकार;
    arg = nb_args;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_आकार = args_आकार;
    क्रम(i = 0; i < nb_args; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        आकार = gfunc_arg_आकार(&sv->type);

        अगर (using_regs(आकार))
            जारी; /* arguments smaller than 8 bytes passed in registers or on stack */

        अगर (bt == VT_STRUCT) {
            /* align to stack align size */
            आकार = (आकार + 15) & ~15;
            /* generate structure store */
            r = get_reg(RC_INT);
            gen_offs_sp(0x8d, r, struct_आकार);
            struct_आकार += आकार;

            /* generate memcpy call */
            vset(&sv->type, r | VT_LVAL, 0);
            vpushv(sv);
            vstore();
            --vtop;
        } अन्यथा अगर (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_आकार);
            struct_आकार += 16;
        }
    }

    अगर (func_scratch < struct_आकार)
        func_scratch = struct_आकार;

    arg = nb_args;
    struct_आकार = args_आकार;

    क्रम(i = 0; i < nb_args; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        आकार = gfunc_arg_आकार(&vtop->type);
        अगर (!using_regs(आकार)) {
            /* align to stack align size */
            आकार = (आकार + 15) & ~15;
            अगर (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_आकार);
                gen_offs_sp(0x89, d, arg*8);
            } अन्यथा {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_आकार);
            }
            struct_आकार += आकार;
        } अन्यथा {
            अगर (is_sse_float(vtop->type.t)) {
		अगर (tcc_state->nosse)
		  tcc_error("SSE disabled");
                अगर (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } अन्यथा {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_मूल्य(d));
                }
            } अन्यथा {
                अगर (bt == VT_STRUCT) {
                    vtop->type.ref = शून्य;
                    vtop->type.t = आकार > 4 ? VT_LLONG : आकार > 2 ? VT_INT
                        : आकार > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                अगर (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } अन्यथा {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_मूल्य(r) * 8 + REG_मूल्य(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    अगर (nb_args > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        अगर (nb_args > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    अगर ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#पूर्ण_अगर
    }
    vtop--;
}

#घोषणा FUNC_PROLOG_आकार 11

/* generate function prolog of type 't' */
व्योम gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    पूर्णांक addr, reg_param_सूचकांक, bt, आकार;
    Sym *sym;
    CType *type;

    func_ret_sub = 0;
    func_scratch = 32;
    func_alloca = 0;
    loc = 0;

    addr = PTR_आकार * 2;
    ind += FUNC_PROLOG_आकार;
    func_sub_sp_offset = ind;
    reg_param_सूचकांक = 0;

    sym = func_type->ref;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    आकार = gfunc_arg_आकार(&func_vt);
    अगर (!using_regs(आकार)) {
        gen_modrm64(0x89, arg_regs[reg_param_सूचकांक], VT_LOCAL, शून्य, addr);
        func_vc = addr;
        reg_param_सूचकांक++;
        addr += 8;
    }

    /* define parameters */
    जबतक ((sym = sym->अग्र) != शून्य) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        आकार = gfunc_arg_आकार(type);
        अगर (!using_regs(आकार)) {
            अगर (reg_param_सूचकांक < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_सूचकांक], VT_LOCAL, शून्य, addr);
            }
            gfunc_set_param(sym, addr, 1);
        } अन्यथा {
            अगर (reg_param_सूचकांक < REGN) {
                /* save arguments passed by register */
                अगर ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    अगर (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_सूचकांक, VT_LOCAL, शून्य, addr);
                } अन्यथा {
                    gen_modrm64(0x89, arg_regs[reg_param_सूचकांक], VT_LOCAL, शून्य, addr);
                }
            }
            gfunc_set_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_सूचकांक++;
    }

    जबतक (reg_param_सूचकांक < REGN) {
        अगर (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_सूचकांक], VT_LOCAL, शून्य, addr);
            addr += 8;
        }
        reg_param_सूचकांक++;
    }
#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#पूर्ण_अगर
}

/* generate function epilog */
व्योम gfunc_epilog(व्योम)
{
    पूर्णांक v, start;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#पूर्ण_अगर

    o(0xc9); /* leave */
    अगर (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } अन्यथा {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    start = func_sub_sp_offset - FUNC_PROLOG_आकार;
    cur_text_section->तथ्य_offset = ind;
    pe_add_unwind_तथ्य(start, ind, v);

    ind = start;
    अगर (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_text_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } अन्यथा {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_text_section->तथ्य_offset;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#अन्यथा

अटल व्योम gadd_sp(पूर्णांक val)
{
    अगर (val == (चिन्हित अक्षर)val) {
        o(0xc48348);
        g(val);
    } अन्यथा {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

प्रकार क्रमागत X86_64_Mode {
  x86_64_mode_none,
  x86_64_mode_memory,
  x86_64_mode_integer,
  x86_64_mode_sse,
  x86_64_mode_x87
} X86_64_Mode;

अटल X86_64_Mode classify_x86_64_merge(X86_64_Mode a, X86_64_Mode b)
{
    अगर (a == b)
        वापस a;
    अन्यथा अगर (a == x86_64_mode_none)
        वापस b;
    अन्यथा अगर (b == x86_64_mode_none)
        वापस a;
    अन्यथा अगर ((a == x86_64_mode_memory) || (b == x86_64_mode_memory))
        वापस x86_64_mode_memory;
    अन्यथा अगर ((a == x86_64_mode_integer) || (b == x86_64_mode_integer))
        वापस x86_64_mode_integer;
    अन्यथा अगर ((a == x86_64_mode_x87) || (b == x86_64_mode_x87))
        वापस x86_64_mode_memory;
    अन्यथा
        वापस x86_64_mode_sse;
}

अटल X86_64_Mode classify_x86_64_inner(CType *ty)
{
    X86_64_Mode mode;
    Sym *f;
    
    चयन (ty->t & VT_BTYPE) {
    हाल VT_VOID: वापस x86_64_mode_none;
    
    हाल VT_INT:
    हाल VT_BYTE:
    हाल VT_SHORT:
    हाल VT_LLONG:
    हाल VT_BOOL:
    हाल VT_PTR:
    हाल VT_FUNC:
        वापस x86_64_mode_integer;
    
    हाल VT_FLOAT:
    हाल VT_DOUBLE: वापस x86_64_mode_sse;
    
    हाल VT_LDOUBLE: वापस x86_64_mode_x87;
      
    हाल VT_STRUCT:
        f = ty->ref;

        mode = x86_64_mode_none;
        क्रम (f = f->अग्र; f; f = f->अग्र)
            mode = classify_x86_64_merge(mode, classify_x86_64_inner(&f->type));
        
        वापस mode;
    }
    निश्चित(0);
    वापस 0;
}

अटल X86_64_Mode classify_x86_64_arg(CType *ty, CType *ret, पूर्णांक *psize, पूर्णांक *palign, पूर्णांक *reg_गिनती)
{
    X86_64_Mode mode;
    पूर्णांक आकार, align, ret_t = 0;
    
    अगर (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_गिनती = 1;
        ret_t = ty->t;
        mode = x86_64_mode_integer;
    } अन्यथा {
        आकार = type_आकार(ty, &align);
        *psize = (आकार + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_गिनती = 0; /* avoid compiler warning */

        अगर (आकार > 16) {
            mode = x86_64_mode_memory;
        } अन्यथा {
            mode = classify_x86_64_inner(ty);
            चयन (mode) {
            हाल x86_64_mode_integer:
                अगर (आकार > 8) {
                    *reg_गिनती = 2;
                    ret_t = VT_QLONG;
                } अन्यथा {
                    *reg_गिनती = 1;
                    अगर (आकार > 4)
                        ret_t = VT_LLONG;
                    अन्यथा अगर (आकार > 2)
                        ret_t = VT_INT;
                    अन्यथा अगर (आकार > 1)
                        ret_t = VT_SHORT;
                    अन्यथा
                        ret_t = VT_BYTE;
                    अगर ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                अवरोध;
                
            हाल x86_64_mode_x87:
                *reg_गिनती = 1;
                ret_t = VT_LDOUBLE;
                अवरोध;

            हाल x86_64_mode_sse:
                अगर (आकार > 8) {
                    *reg_गिनती = 2;
                    ret_t = VT_QFLOAT;
                } अन्यथा {
                    *reg_गिनती = 1;
                    ret_t = (आकार > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                अवरोध;
            शेष: अवरोध; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    अगर (ret) {
        ret->ref = शून्य;
        ret->t = ret_t;
    }
    
    वापस mode;
}

ST_FUNC पूर्णांक classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    क्रमागत __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    पूर्णांक आकार, align, reg_गिनती;
    X86_64_Mode mode = classify_x86_64_arg(ty, शून्य, &आकार, &align, &reg_गिनती);
    चयन (mode) {
    शेष: वापस __va_stack;
    हाल x86_64_mode_integer: वापस __va_gen_reg;
    हाल x86_64_mode_sse: वापस __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC पूर्णांक gfunc_sret(CType *vt, पूर्णांक variadic, CType *ret, पूर्णांक *ret_align, पूर्णांक *regsize)
{
    पूर्णांक आकार, align, reg_गिनती;
    अगर (classify_x86_64_arg(vt, ret, &आकार, &align, &reg_गिनती) == x86_64_mode_memory)
        वापस 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_गिनती; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    वापस 1;
}

#घोषणा REGN 6
अटल स्थिर uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

अटल पूर्णांक arg_prepare_reg(पूर्णांक idx) {
  अगर (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      वापस idx + 8;
  अन्यथा
      वापस idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
व्योम gfunc_call(पूर्णांक nb_args)
{
    X86_64_Mode mode;
    CType type;
    पूर्णांक आकार, align, r, args_आकार, ढेर_adjust, i, reg_गिनती, k;
    पूर्णांक nb_reg_args = 0;
    पूर्णांक nb_sse_args = 0;
    पूर्णांक sse_reg, gen_reg;
    अक्षर *onstack = tcc_malloc((nb_args + 1) * माप (अक्षर));

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gbound_args(nb_args);
#पूर्ण_अगर

    save_regs(nb_args);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    ढेर_adjust = 0;
    क्रम(i = nb_args - 1; i >= 0; i--) {
        mode = classify_x86_64_arg(&vtop[-i].type, शून्य, &आकार, &align, &reg_गिनती);
        अगर (आकार == 0) जारी;
        अगर (mode == x86_64_mode_sse && nb_sse_args + reg_गिनती <= 8) {
            nb_sse_args += reg_गिनती;
	    onstack[i] = 0;
	} अन्यथा अगर (mode == x86_64_mode_integer && nb_reg_args + reg_गिनती <= REGN) {
            nb_reg_args += reg_गिनती;
	    onstack[i] = 0;
	} अन्यथा अगर (mode == x86_64_mode_none) {
	    onstack[i] = 0;
	} अन्यथा {
	    अगर (align == 16 && (ढेर_adjust &= 15)) {
		onstack[i] = 2;
		ढेर_adjust = 0;
	    } अन्यथा
	      onstack[i] = 1;
	    ढेर_adjust += आकार;
	}
    }

    अगर (nb_sse_args && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_args;
    sse_reg = nb_sse_args;
    args_आकार = 0;
    ढेर_adjust &= 15;
    क्रम (i = k = 0; i < nb_args;) {
	mode = classify_x86_64_arg(&vtop[-i].type, शून्य, &आकार, &align, &reg_गिनती);
	अगर (आकार) {
            अगर (!onstack[i + k]) {
	        ++i;
	        जारी;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            अगर (ढेर_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                args_आकार += 8;
	        ढेर_adjust = 0;
            }
	    अगर (onstack[i + k] == 2)
	        ढेर_adjust = 1;
        }

	vrotb(i+1);

	चयन (vtop->type.t & VT_BTYPE) {
	    हाल VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, आकार); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_मूल्य(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_मूल्य(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		अवरोध;

	    हाल VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, आकार); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		अवरोध;

	    हाल VT_FLOAT:
	    हाल VT_DOUBLE:
		निश्चित(mode == x86_64_mode_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_मूल्य(r)*8);
		o(0x24);
		अवरोध;

	    शेष:
		निश्चित(mode == x86_64_mode_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_मूल्य(r)); /* push r */
		अवरोध;
	}
	args_आकार += आकार;

	vpop();
	--nb_args;
	k++;
    }

    tcc_free(onstack);

    /* then, we prepare register passing arguments.
       Note that we cannot set RDX and RCX in this loop because gv()
       may break these temporary registers. Let's use R10 and R11
       instead of them */
    निश्चित(gen_reg <= REGN);
    निश्चित(sse_reg <= 8);
    क्रम(i = 0; i < nb_args; i++) {
        mode = classify_x86_64_arg(&vtop->type, &type, &आकार, &align, &reg_गिनती);
        अगर (आकार == 0) जारी;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        अगर (mode == x86_64_mode_sse) {
            अगर (reg_गिनती == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                अगर (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } अन्यथा {
                निश्चित(reg_गिनती == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } अन्यथा अगर (mode == x86_64_mode_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            पूर्णांक d;
            gen_reg -= reg_गिनती;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_मूल्य(r) * 8 + REG_मूल्य(d));
            अगर (reg_गिनती == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_मूल्य(vtop->r2) * 8 + REG_मूल्य(d));
            }
        }
        vtop--;
    }
    निश्चित(gen_reg == 0);
    निश्चित(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    अगर (nb_reg_args > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        अगर (nb_reg_args > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    अगर (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_args < 8 ? nb_sse_args : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    अगर (args_आकार)
        gadd_sp(args_आकार);
    vtop--;
}

#घोषणा FUNC_PROLOG_आकार 11

अटल व्योम धकेलो_arg_reg(पूर्णांक i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, शून्य, loc);
}

/* generate function prolog of type 't' */
व्योम gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_Mode mode, ret_mode;
    पूर्णांक i, addr, align, आकार, reg_गिनती;
    पूर्णांक param_addr = 0, reg_param_सूचकांक, sse_param_सूचकांक;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_आकार * 2;
    loc = 0;
    ind += FUNC_PROLOG_आकार;
    func_sub_sp_offset = ind;
    func_ret_sub = 0;
    ret_mode = classify_x86_64_arg(&func_vt, शून्य, &आकार, &align, &reg_गिनती);

    अगर (func_var) {
        पूर्णांक seen_reg_अंक, seen_sse_अंक, seen_ढेर_आकार;
        seen_reg_अंक = ret_mode == x86_64_mode_memory;
        seen_sse_अंक = 0;
        /* frame pointer and return address */
        seen_ढेर_आकार = PTR_आकार * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        जबतक ((sym = sym->अग्र) != शून्य) {
            type = &sym->type;
            mode = classify_x86_64_arg(type, शून्य, &आकार, &align, &reg_गिनती);
            चयन (mode) {
            शेष:
            ढेर_arg:
                seen_ढेर_आकार = ((seen_ढेर_आकार + align - 1) & -align) + आकार;
                अवरोध;
                
            हाल x86_64_mode_integer:
                अगर (seen_reg_अंक + reg_गिनती > REGN)
		    जाओ ढेर_arg;
		seen_reg_अंक += reg_गिनती;
                अवरोध;
                
            हाल x86_64_mode_sse:
                अगर (seen_sse_अंक + reg_गिनती > 8)
		    जाओ ढेर_arg;
		seen_sse_अंक += reg_गिनती;
                अवरोध;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(seen_reg_अंक * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(seen_sse_अंक * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(seen_ढेर_आकार);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        क्रम (i = 0; i < 8; i++) {
            loc -= 16;
	    अगर (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, शून्य, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        क्रम (i = 0; i < REGN; i++) {
            धकेलो_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_सूचकांक = 0;
    sse_param_सूचकांक = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    अगर (ret_mode == x86_64_mode_memory) {
        धकेलो_arg_reg(reg_param_सूचकांक);
        func_vc = loc;
        reg_param_सूचकांक++;
    }
    /* define parameters */
    जबतक ((sym = sym->अग्र) != शून्य) {
        type = &sym->type;
        mode = classify_x86_64_arg(type, शून्य, &आकार, &align, &reg_गिनती);
        चयन (mode) {
        हाल x86_64_mode_sse:
	    अगर (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            अगर (sse_param_सूचकांक + reg_गिनती <= 8) {
                /* save arguments passed by register */
                loc -= reg_गिनती * 8;
                param_addr = loc;
                क्रम (i = 0; i < reg_गिनती; ++i) {
                    gen_modrm32(0xd60f66, sse_param_सूचकांक, VT_LOCAL, शून्य, param_addr + i*8);
                    ++sse_param_सूचकांक;
                }
            } अन्यथा {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += आकार;
            }
            अवरोध;
            
        हाल x86_64_mode_memory:
        हाल x86_64_mode_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += आकार;
            अवरोध;
            
        हाल x86_64_mode_integer: {
            अगर (reg_param_सूचकांक + reg_गिनती <= REGN) {
                /* save arguments passed by register */
                loc -= reg_गिनती * 8;
                param_addr = loc;
                क्रम (i = 0; i < reg_गिनती; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_सूचकांक], VT_LOCAL, शून्य, param_addr + i*8);
                    ++reg_param_सूचकांक;
                }
            } अन्यथा {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += आकार;
            }
            अवरोध;
        }
	शेष: अवरोध; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_set_param(sym, param_addr, 0);
    }

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#पूर्ण_अगर
}

/* generate function epilog */
व्योम gfunc_epilog(व्योम)
{
    पूर्णांक v, saved_ind;

#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#पूर्ण_अगर
    o(0xc9); /* leave */
    अगर (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } अन्यथा {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    /* align local size to word & save local variables */
    v = (-loc + 15) & -16;
    saved_ind = ind;
    ind = func_sub_sp_offset - FUNC_PROLOG_आकार;
    o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
    o(0xec8148);  /* sub rsp, stacksize */
    gen_le32(v);
    ind = saved_ind;
}

#पूर्ण_अगर /* not PE */

ST_FUNC व्योम gen_fill_nops(पूर्णांक bytes)
{
    जबतक (bytes--)
      g(0x90);
}

/* generate a jump to a label */
पूर्णांक gjmp(पूर्णांक t)
{
    वापस gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
व्योम gjmp_addr(पूर्णांक a)
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
        अगर (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            पूर्णांक v = vtop->cmp_r;
            op &= ~0x100;
            अगर (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    अन्यथा
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        वापस t;
}

/* generate an integer binary operation */
व्योम gen_opi(पूर्णांक op)
{
    पूर्णांक r, fr, opc, c;
    पूर्णांक ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    चयन(op) {
    हाल '+':
    हाल TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        अगर (cc && (!ll || (पूर्णांक)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            अगर (c == (चिन्हित अक्षर)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_मूल्य(r));
                g(c);
            } अन्यथा {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_मूल्य(r), c);
            }
        } अन्यथा {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_मूल्य(r) + REG_मूल्य(fr) * 8);
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
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_मूल्य(fr) + REG_मूल्य(r) * 8);
        vtop--;
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
        अगर (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_मूल्य(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } अन्यथा {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_मूल्य(r));
        }
        vtop--;
        अवरोध;
    हाल TOK_UDIV:
    हाल TOK_UMOD:
        uu = 1;
        जाओ divmod;
    हाल '/':
    हाल '%':
    हाल TOK_PDIV:
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
        o((uu ? 0xf0 : 0xf8) + REG_मूल्य(fr));
        अगर (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        अन्यथा
            r = TREG_RAX;
        vtop->r = r;
        अवरोध;
    शेष:
        opc = 7;
        जाओ gen_op8;
    }
}

व्योम gen_opl(पूर्णांक op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
व्योम gen_opf(पूर्णांक op)
{
    पूर्णांक a, ft, fc, swapped, r, opc;
    पूर्णांक bt = vtop->type.t & VT_BTYPE;
    पूर्णांक float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    अगर (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        अगर (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } अन्यथा {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, शून्य, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        वापस;
    }

    /* convert constants to memory references */
    अगर ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    अगर ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    अगर ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    अगर (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    अगर ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        अगर (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            load(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
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
            load(TREG_ST0, vtop);
            swapped = !swapped;

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
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } अन्यथा {
        अगर (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            अगर ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = शून्य;
                load(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            अगर (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } अन्यथा {
                अगर (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                अगर (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } अन्यथा {
                    op = 0x97; /* seta */
                }
            }

            अगर (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            निश्चित(!(vtop[-1].r & VT_LVAL));
            
            अगर (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            अन्यथा
                opc = 0x2f0f; /* comisd */
            अगर ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } अन्यथा {
            निश्चित((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            चयन(op) {
            शेष:
            हाल '+':
                a = 0;
                अवरोध;
            हाल '-':
                a = 4;
                अवरोध;
            हाल '*':
                a = 1;
                अवरोध;
            हाल '/':
                a = 6;
                अवरोध;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            निश्चित((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            अगर ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = शून्य;
                load(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            निश्चित(!(vtop[-1].r & VT_LVAL));
            अगर (swapped) {
                निश्चित(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            अगर ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } अन्यथा {
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
व्योम gen_cvt_itof(पूर्णांक t)
{
    अगर ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        अगर ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } अन्यथा अगर ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } अन्यथा {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } अन्यथा {
        पूर्णांक r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        अगर ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_मूल्य(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
व्योम gen_cvt_ftof(पूर्णांक t)
{
    पूर्णांक ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    अगर (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        अगर (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_मूल्य(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_मूल्य(vtop->r)*9);
        } अन्यथा अगर (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_मूल्य(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } अन्यथा अगर (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        अगर (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_मूल्य(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_मूल्य(vtop->r)*9);
        } अन्यथा अगर (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_मूल्य(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } अन्यथा {
        पूर्णांक r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        अगर (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_मूल्य(r)*8);
            o(0xf024);
            vtop->r = r;
        } अन्यथा अगर (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_मूल्य(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
व्योम gen_cvt_ftoi(पूर्णांक t)
{
    पूर्णांक ft, bt, आकार, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    अगर (bt == VT_LDOUBLE) {
	अगर (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    वापस;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    अगर (t != VT_INT)
        आकार = 8;
    अन्यथा
        आकार = 4;

    r = get_reg(RC_INT);
    अगर (bt == VT_FLOAT) {
        o(0xf3);
    } अन्यथा अगर (bt == VT_DOUBLE) {
        o(0xf2);
    } अन्यथा {
        निश्चित(0);
    }
    orex(आकार == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_मूल्य(vtop->r) + REG_मूल्य(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC व्योम gen_cvt_sxtw(व्योम)
{
    पूर्णांक r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_मूल्य(r) << 3) + REG_मूल्य(r));
}

/* char/short to int conversion */
ST_FUNC व्योम gen_cvt_csti(पूर्णांक t)
{
    पूर्णांक r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_मूल्य(r) << 3 | REG_मूल्य(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC व्योम gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_text_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC व्योम ggoto(व्योम)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC व्योम gen_vla_sp_save(पूर्णांक addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, शून्य, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC व्योम gen_vla_sp_restore(पूर्णांक addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, शून्य, addr);
}

#अगर_घोषित TCC_TARGET_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC व्योम gen_vla_परिणाम(पूर्णांक addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, शून्य, addr);
}
#पूर्ण_अगर

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC व्योम gen_vla_alloc(CType *type, पूर्णांक align) {
    पूर्णांक use_call = 0;

#अगर defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_PE	/* alloca does more than just adjust %rsp on Windows */
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
        o(0x2b48);
        o(0xe0 | REG_मूल्य(r));
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
ST_FUNC व्योम gen_struct_copy(पूर्णांक आकार)
{
    पूर्णांक n = आकार / PTR_आकार;
#अगर_घोषित TCC_TARGET_PE
    o(0x5756); /* push rsi, rdi */
#पूर्ण_अगर
    gv2(RC_RDI, RC_RSI);
    अगर (n <= 4) {
        जबतक (n)
            o(0xa548), --n;
    } अन्यथा {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    अगर (आकार & 0x04)
        o(0xa5);
    अगर (आकार & 0x02)
        o(0xa566);
    अगर (आकार & 0x01)
        o(0xa4);
#अगर_घोषित TCC_TARGET_PE
    o(0x5e5f); /* pop rdi, rsi */
#पूर्ण_अगर
    vpop();
    vpop();
}

/* end of x86-64 code generator */
/*************************************************************/
#पूर्ण_अगर /* ! TARGET_DEFS_ONLY */
/******************************************************/
