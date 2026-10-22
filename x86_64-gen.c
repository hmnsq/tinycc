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

#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

/* number of available registers */
#నిర్వచించు NB_REGS         25
#నిర్వచించు NB_ASM_REGS     16
#నిర్వచించు CONFIG_TCC_ASM

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#నిర్వచించు RC_INT     0x0001 /* generic integer register */
#నిర్వచించు RC_FLOAT   0x0002 /* generic float register */
#నిర్వచించు RC_RAX     0x0004
#నిర్వచించు RC_RDX     0x0008
#నిర్వచించు RC_RCX     0x0010
#నిర్వచించు RC_RSI     0x0020
#నిర్వచించు RC_RDI     0x0040
#నిర్వచించు RC_ST0     0x0080 /* only for long double */
#నిర్వచించు RC_R8      0x0100
#నిర్వచించు RC_R9      0x0200
#నిర్వచించు RC_R10     0x0400
#నిర్వచించు RC_R11     0x0800
#నిర్వచించు RC_XMM0    0x1000
#నిర్వచించు RC_XMM1    0x2000
#నిర్వచించు RC_XMM2    0x4000
#నిర్వచించు RC_XMM3    0x8000
#నిర్వచించు RC_XMM4    0x10000
#నిర్వచించు RC_XMM5    0x20000
#నిర్వచించు RC_XMM6    0x40000
#నిర్వచించు RC_XMM7    0x80000
#నిర్వచించు RC_IRET    RC_RAX /* function return: integer register */
#నిర్వచించు RC_IRE2    RC_RDX /* function return: second integer register */
#నిర్వచించు RC_FRET    RC_XMM0 /* function return: float register */
#నిర్వచించు RC_FRE2    RC_XMM1 /* function return: second float register */

/* pretty names for the registers */
గణన {
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

#నిర్వచించు REX_పునాది(reg) (((reg) >> 3) & 1)
#నిర్వచించు REG_విలువ(reg) ((reg) & 7)

/* return registers for function */
#నిర్వచించు REG_IRET TREG_RAX /* single word int return register */
#నిర్వచించు REG_IRE2 TREG_RDX /* second word return register (for long long) */
#నిర్వచించు REG_FRET TREG_XMM0 /* float return register */
#నిర్వచించు REG_FRE2 TREG_XMM1 /* second float return register */

/* defined if function parameters must be evaluated in reverse order */
#నిర్వచించు INVERT_FUNC_PARAMS

/* pointer size, in bytes */
#నిర్వచించు PTR_కొలత 8

/* long double size and alignment, in bytes */
#నిర్వచించు LDOUBLE_కొలత  16
#నిర్వచించు LDOUBLE_ALIGN 16
/* maximum alignment (for aligned attribute support) */
#నిర్వచించు MAX_ALIGN     16

/* define if return values need to be extended explicitely
   at caller side (for interfacing with non-TCC compilers) */
#నిర్వచించు PROMOTE_RET

#నిర్వచించు TCC_లక్ష్యం_NATIVE_STRUCT_COPY
ST_FUNC శూన్య gen_struct_copy(పూర్ణాంకం కొలత);

/******************************************************/
#లేకపోతే /* ! TARGET_DEFS_ONLY */
/******************************************************/
#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"
#అన్తర్భావ <assert.h>

ST_దత్తాంశం స్థిరరాశి అక్షరం * స్థిరరాశి లక్ష్యం_machine_defs =
    "__x86_64__\0"
    "__x86_64\0"
    "__amd64__\0"
    ;

ST_దత్తాంశం స్థిరరాశి పూర్ణాంకం reg_classes[NB_REGS] = {
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

స్థిర గుర్తులేని దీర్ఘ func_sub_sp_స్థానభ్రంశం;
స్థిర పూర్ణాంకం func_ret_sub;

#ఒకవేళ defined(CONFIG_TCC_BCHECK)
స్థిర addr_t func_bound_స్థానభ్రంశం;
స్థిర గుర్తులేని దీర్ఘ func_bound_ind;
ST_దత్తాంశం పూర్ణాంకం func_bound_కూడు_epilog;
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_లక్ష్యం_PE
స్థిర పూర్ణాంకం func_scratch, func_alloca;
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

ST_FUNC శూన్య gen_le64(int64_t c)
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

స్థిర శూన్య orex(పూర్ణాంకం ll, పూర్ణాంకం r, పూర్ణాంకం r2, పూర్ణాంకం b)
{
    ఒకవేళ ((r & VT_VALMASK) >= VT_CONST)
        r = 0;
    ఒకవేళ ((r2 & VT_VALMASK) >= VT_CONST)
        r2 = 0;
    ఒకవేళ (ll || REX_పునాది(r) || REX_పునాది(r2)) {
        ఒకవేళ ((b & 0xff) == 0x66) /* output prefix before rex byte */
            o(0x66), b >>= 8;
        o(0x40 | REX_పునాది(r) | (REX_పునాది(r2) << 2) | (ll << 3));
    }
    o(b);
}

/* output a symbol and patch all calls to it */
ST_FUNC శూన్య gsym_addr(పూర్ణాంకం t, పూర్ణాంకం a)
{
    అయితే (t) {
        గుర్తులేని అక్షరం *ptr = cur_పాఠ్యం_section->దత్తాంశం + t;
        uint32_t n = read32le(ptr); /* next value */
        write32le(ptr, a < 0 ? -a : a - t - 4);
        t = n;
    }
}

స్థిర పూర్ణాంకం is64_type(పూర్ణాంకం t)
{
    తిరిగి ((t & VT_BTYPE) == VT_PTR ||
            (t & VT_BTYPE) == VT_FUNC ||
            (t & VT_BTYPE) == VT_LLONG);
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

/* generate jmp to a label */
#నిర్వచించు gjmp2(instr,lbl) oad(instr,lbl)

ST_FUNC శూన్య gen_addr32(పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c)
{
    ఒకవేళ (r & VT_SYM)
        greloca(cur_పాఠ్యం_section, sym, ind, R_X86_64_32S, c), c=0;
    gen_le32(c);
}

/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC శూన్య gen_addrpc32(పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c)
{
    ఒకవేళ (r & VT_SYM)
        greloca(cur_పాఠ్యం_section, sym, ind, R_X86_64_PC32, c-4), c=4;
    gen_le32(c-4);
}

/* output got address with relocation */
స్థిర శూన్య gen_gotpcrel(పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c)
{
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    tcc_error("internal error: no GOT on PE: %s %x %x | %02x %02x %02x\n",
        get_tok_str(sym->v, ఖాళీ), c, r,
        cur_పాఠ్యం_section->దత్తాంశం[ind-3],
        cur_పాఠ్యం_section->దత్తాంశం[ind-2],
        cur_పాఠ్యం_section->దత్తాంశం[ind-1]
        );
#అయితే_ముగింపు
    greloca(cur_పాఠ్యం_section, sym, ind, R_X86_64_GOTPCREL, -4);
    gen_le32(0);
    ఒకవేళ (c) {
        /* we use add c, %xxx for displacement */
        orex(1, r, 0, 0x81);
        o(0xc0 + REG_విలువ(r));
        gen_le32(c);
    }
}

/* generate a modrm reference. 'op_reg' contains the additional 3
   opcode rsp. second register bits */
స్థిర శూన్య gen_modrm_impl(పూర్ణాంకం opcode, పూర్ణాంకం ll, పూర్ణాంకం op_reg_0, పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c)
{
    పూర్ణాంకం op_reg = REG_విలువ(op_reg_0) << 3;

    ఒకవేళ ((r & VT_SYM) && (sym->type.t & VT_TLS)) {
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        Sym *s2 = external_global_sym(TOK_tls_సూచీ, &int_type);
        r = get_reg(RC_INT);
        gen_modrm_impl(0x8B, 0,  r, VT_SYM|VT_CONST, s2, 0);
        o(0x03e0c148 | r << 16); /* shl 2,r */
        o(0x4865), oad(0x250403 | r << 11, 11*PTR_కొలత); /* add gs:0x58,r */
        gen_modrm_impl(0x8B, 1, r, r | VT_LVAL, 0, 0); /* mov (r),r */
        orex(ll, r, op_reg_0, opcode), oad(0x80 | op_reg | r, 0);
        greloca(cur_పాఠ్యం_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#లేకపోతే
        o(0x64); /* fs segment prefix */
        orex(ll, r, op_reg_0, opcode);
	o(0x04 | op_reg); /* [sib] | destreg */
	oad(0x25, 0);     /* disp32 (relocated) */
	greloca(cur_పాఠ్యం_section, sym, ind - 4, R_X86_64_TPOFF32, c);
#అయితే_ముగింపు
        తిరిగి;
    }

    orex(ll, r, op_reg_0, opcode);

    ఒకవేళ ((r & VT_VALMASK) == VT_CONST) {
        /* constant memory reference */
	ఒకవేళ (!(r & VT_SYM)) {
	    /* Absolute memory reference */
	    o(0x04 | op_reg); /* [sib] | destreg */
	    oad(0x25, c);     /* disp32 */
	} లేకపోతే {
	    o(0x05 | op_reg); /* (%rip)+disp32 | destreg */
	    ఒకవేళ (op_reg_0 & TREG_MEM) {
		gen_gotpcrel(r, sym, c);
	    } లేకపోతే {
		gen_addrpc32(r, sym, c);
	    }
	}
    } లేకపోతే ఒకవేళ ((r & VT_VALMASK) == VT_LOCAL) {
        /* currently, we use only ebp as base */
        ఒకవేళ (c == (గుర్తుగల అక్షరం)c) {
            /* short reference */
            o(0x45 | op_reg);
            g(c);
        } లేకపోతే {
            oad(0x85 | op_reg, c);
        }
    /* 'c' (mostly from vtop->c.i) is not valid unless when TREG_MEM is set */
    } లేకపోతే ఒకవేళ ((r & TREG_MEM) && c) {
        g(0x80 | op_reg | REG_విలువ(r));
        gen_le32(c);
    } లేకపోతే ఒకవేళ (r & VT_LVAL) {
        g(0x00 | op_reg | REG_విలువ(r));
    } లేకపోతే {
        g(0xc0 | op_reg | REG_విలువ(r));
    }
}

స్థిర శూన్య gen_modrm64(పూర్ణాంకం opcode, పూర్ణాంకం op_reg, పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c)
{
    gen_modrm_impl(opcode, 1, op_reg, r, sym, c);
}

స్థిర శూన్య gen_modrm32(పూర్ణాంకం opcode, పూర్ణాంకం op_reg, పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c)
{
    gen_modrm_impl(opcode, 0, op_reg, r, sym, c);
}

/* load 'r' from value 'sv' */
శూన్య ఎక్కించు(పూర్ణాంకం r, SValue *sv)
{
    పూర్ణాంకం v, t, ft, fc, fr;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t & ~(VT_DEFSIGN|VT_QUAL);
    fc = sv->c.i;

    ఒకవేళ (fc != sv->c.i && (fr & VT_SYM))
      tcc_error("64 bit addend in load");

#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_PE
    /* we use indirect access via got */
    ఒకవేళ ((fr & (VT_VALMASK|VT_SYM|VT_LVAL)) == (VT_CONST|VT_SYM|VT_LVAL)
        && !(sv->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* use the result register as a temporal register */
        పూర్ణాంకం tr = r | TREG_MEM;
        ఒకవేళ (is_float(ft)) {
            /* we cannot use float registers as a temporal register */
            tr = get_reg(RC_INT) | TREG_MEM;
        }
        gen_modrm64(0x8b, tr, fr, sv->sym, 0);

        /* load from the temporal register */
        fr = tr | VT_LVAL;
    }
#అయితే_ముగింపు

    v = fr & VT_VALMASK;
    ఒకవేళ (fr & VT_LVAL) {
        పూర్ణాంకం b, ll;
        ఒకవేళ (v == VT_LLOCAL) {
            v1.type.t = VT_PTR;
            v1.r = VT_LOCAL | VT_LVAL;
            v1.c.i = fc;
	    v1.sym = ఖాళీ;
            fr = r;
            ఒకవేళ (!(reg_classes[fr] & (RC_INT|RC_R11)))
                fr = get_reg(RC_INT);
            ఎక్కించు(fr, &v1);
            fr |= VT_LVAL;
        }
	ఒకవేళ (fc != sv->c.i) {
	    /* If the addends doesn't fit into a 32bit signed
	       we must use a 64bit move.  We've checked above
	       that this doesn't have a sym associated.  */
	    v1.type.t = VT_LLONG;
	    v1.r = VT_CONST;
	    v1.c.i = sv->c.i;
	    v1.sym = ఖాళీ;
	    fr = r;
	    ఒకవేళ (!(reg_classes[fr] & (RC_INT|RC_R11)))
	        fr = get_reg(RC_INT);
	    ఎక్కించు(fr, &v1);
	    fc = 0;
	}
        ll = 0;
	/* Like GCC we can load from small enough properly sized
	   structs and unions as well.
	   XXX maybe move to generic operand handling, but should
	   occur only with asm, so tccasm.c might also be a better place */
	ఒకవేళ ((ft & VT_BTYPE) == VT_STRUCT) {
	    పూర్ణాంకం align;
	    ఎంపిక (type_కొలత(&sv->type, &align)) {
		స్థితి 1: ft = VT_BYTE; ఆపు;
		స్థితి 2: ft = VT_SHORT; ఆపు;
		స్థితి 4: ft = VT_INT; ఆపు;
		స్థితి 8: ft = VT_LLONG; ఆపు;
		అప్రమేయ:
		    tcc_error("invalid aggregate type for register load");
		    ఆపు;
	    }
	}
        ఒకవేళ ((ft & VT_BTYPE) == VT_FLOAT) {
            b = 0x6e0f66;
            r = REG_విలువ(r); /* movd */
        } లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_DOUBLE) {
            b = 0x7e0ff3; /* movq */
            r = REG_విలువ(r);
        } లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_LDOUBLE) {
            b = 0xdb, r = 5; /* fldt */
        } లేకపోతే ఒకవేళ ((ft & VT_TYPE) == VT_BYTE || (ft & VT_TYPE) == VT_BOOL) {
            b = 0xbe0f;   /* movsbl */
        } లేకపోతే ఒకవేళ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
            b = 0xb60f;   /* movzbl */
        } లేకపోతే ఒకవేళ ((ft & VT_TYPE) == VT_SHORT) {
            b = 0xbf0f;   /* movswl */
        } లేకపోతే ఒకవేళ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
            b = 0xb70f;   /* movzwl */
        } లేకపోతే ఒకవేళ ((ft & VT_TYPE) == (VT_VOID)) {
            /* Can happen with zero size structs */
            తిరిగి;
        } లేకపోతే {
            ప్రతిజ్ఞా(((ft & VT_BTYPE) == VT_INT)
                   || ((ft & VT_BTYPE) == VT_LLONG)
                   || ((ft & VT_BTYPE) == VT_PTR)
                   || ((ft & VT_BTYPE) == VT_FUNC)
                );
            ll = is64_type(ft);
            b = 0x8b;
        }
        gen_modrm_impl(b, ll, r, fr, sv->sym, fc);
    } లేకపోతే {
        ఒకవేళ (v == VT_CONST) {
            ఒకవేళ (fr & VT_SYM) {
#నిర్వచితమైతే TCC_లక్ష్యం_PE
                gen_modrm64(0x8d, r, fr, sv->sym, fc);
#లేకపోతే
                ఒకవేళ (sv->sym->type.t & VT_TLS) {
                    /* mov fs:0, r */
                    o(0x64), gen_modrm64(0x8b, r, VT_CONST, ఖాళీ, 0);
                    /* add $tpoff,r */
                    orex(1,0,r,0x81), oad(0xC0 | REG_విలువ(r), 0);
                    greloca(cur_పాఠ్యం_section, sv->sym, ind - 4, R_X86_64_TPOFF32, fc);
                } లేకపోతే ఒకవేళ (sv->sym->type.t & VT_STATIC) {
                    orex(1,0,r,0x8d);
                    o(0x05 + REG_విలువ(r) * 8); /* lea xx(%rip), r */
                    gen_addrpc32(fr, sv->sym, fc);
                } లేకపోతే {
                    orex(1,0,r,0x8b);
                    o(0x05 + REG_విలువ(r) * 8); /* mov xx(%rip), r */
                    gen_gotpcrel(r, sv->sym, fc);
                }
#అయితే_ముగింపు
            } లేకపోతే ఒకవేళ (is64_type(ft)) {
                ఒకవేళ (sv->c.i >> 32) {
                    orex(1,r,0, 0xb8 + REG_విలువ(r)); /* movabs $xx, r */
                    gen_le64(sv->c.i);
                } లేకపోతే ఒకవేళ (sv->c.i > 0) {
                    orex(0,r,0, 0xb8 + REG_విలువ(r)); /* mov $xx, r */
                    gen_le32(sv->c.i);
                } లేకపోతే {
                    orex(0, r, r, 0x31); /* xor r, r */
                    o(0xc0 + REG_విలువ(r) * 9);
                }
            } లేకపోతే {
                orex(0,r,0, 0xb8 + REG_విలువ(r)); /* mov $xx, r */
                gen_le32(fc);
            }
        } లేకపోతే ఒకవేళ (v == VT_LOCAL) {
            gen_modrm64(0x8d, r, VT_LOCAL, sv->sym, fc);
        } లేకపోతే ఒకవేళ (v == VT_CMP) {
	    ఒకవేళ (fc & 0x100)
	      {
                v = vtop->cmp_r;
                fc &= ~0x100;
	        /* This was a float compare.  If the parity bit is
		   set the result was unordered, meaning false for everything
		   except TOK_NE, and true for TOK_NE.  */
                orex(0, r, 0, 0xb0 + REG_విలువ(r)); /* mov $0/1,%al */
                g(v ^ fc ^ (v == TOK_NE));
                o(0x037a + (REX_పునాది(r) << 8));
              }
            orex(0,r,0, 0x0f); /* setxx %br */
            o(fc);
            o(0xc0 + REG_విలువ(r));
            orex(0,r,0, 0x0f);
            o(0xc0b6 + REG_విలువ(r) * 0x900); /* movzbl %al, %eax */
        } లేకపోతే ఒకవేళ (v == VT_JMP || v == VT_JMPI) {
            t = v & 1;
            orex(0,r,0,0);
            oad(0xb8 + REG_విలువ(r), t); /* mov $1, r */
            o(0x05eb + (REX_పునాది(r) << 8)); /* jmp after */
            gsym(fc);
            orex(0,r,0,0);
            oad(0xb8 + REG_విలువ(r), t ^ 1); /* mov $0, r */
        } లేకపోతే ఒకవేళ (v != r) {
            ఒకవేళ ((r >= TREG_XMM0) && (r <= TREG_XMM7)) {
                ఒకవేళ (v == TREG_ST0) {
                    /* gen_cvt_ftof(VT_DOUBLE); */
                    o(0xf0245cdd); /* fstpl -0x10(%rsp) */
                    /* movsd -0x10(%rsp),%xmmN */
                    o(0x100ff2);
                    o(0x44 + REG_విలువ(r)*8); /* %xmmN */
                    o(0xf024);
                } లేకపోతే {
                    ప్రతిజ్ఞా((v >= TREG_XMM0) && (v <= TREG_XMM7));
                    ఒకవేళ ((ft & VT_BTYPE) == VT_FLOAT) {
                        o(0x100ff3);
                    } లేకపోతే {
                        ప్రతిజ్ఞా((ft & VT_BTYPE) == VT_DOUBLE);
                        o(0x100ff2);
                    }
                    o(0xc0 + REG_విలువ(v) + REG_విలువ(r)*8);
                }
            } లేకపోతే ఒకవేళ (r == TREG_ST0) {
                ప్రతిజ్ఞా((v >= TREG_XMM0) && (v <= TREG_XMM7));
                /* gen_cvt_ftof(VT_LDOUBLE); */
                /* movsd %xmmN,-0x10(%rsp) */
                o(0x110ff2);
                o(0x44 + REG_విలువ(r)*8); /* %xmmN */
                o(0xf024);
                o(0xf02444dd); /* fldl -0x10(%rsp) */
            } లేకపోతే {
                orex(is64_type(ft), r, v, 0x89);
                o(0xc0 + REG_విలువ(r) + REG_విలువ(v) * 8); /* mov v, r */
            }
        }
    }
}

/* store register 'r' in lvalue 'v' */
శూన్య store(పూర్ణాంకం r, SValue *v)
{
    పూర్ణాంకం fr, bt, fc;
    /* store the REX prefix in this variable when PIC is enabled */
    పూర్ణాంకం opc = 0, ll = 0;

    fr = v->r;
    fc = v->c.i;
    ఒకవేళ (fc != v->c.i && (fr & VT_SYM))
        tcc_error("64 bit addend in store");
    bt = v->type.t & VT_BTYPE;

#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_PE
    /* we need to access the variable via got */
    ఒకవేళ ((fr & (VT_VALMASK|VT_SYM)) == (VT_CONST|VT_SYM)
        && !(v->sym->type.t & (VT_STATIC|VT_TLS))) {
        /* mov xx(%rip), %r11 */
        o(0x1d8b4c);
        gen_gotpcrel(TREG_R11, v->sym, v->c.i);
        fr = TREG_R11 | VT_LVAL;
    }
#అయితే_ముగింపు

    /* XXX: incorrect if float reg to reg */
    ఒకవేళ (bt == VT_FLOAT) {
        opc = 0x7e0f66;
        r = REG_విలువ(r);
    } లేకపోతే ఒకవేళ (bt == VT_DOUBLE) {
        opc = 0xd60f66;
        r = REG_విలువ(r);
    } లేకపోతే ఒకవేళ (bt == VT_LDOUBLE) {
        o(0xc0d9); /* fld %st(0) */
        opc = 0xdb;
        r = 7;
    } లేకపోతే ఒకవేళ (bt == VT_BYTE || bt == VT_BOOL) {
        opc = 0x88;
    } లేకపోతే {
        opc = 0x89;
        ఒకవేళ (bt == VT_SHORT)
            opc = 0x8966;
        లేకపోతే ఒకవేళ (is64_type(bt))
            ll = 1;
    }
    gen_modrm_impl(opc, ll, r, fr, v->sym, fc);
}

/* 'is_jmp' is '1' if it is a jump */
స్థిర శూన్య gcall_or_jmp(పూర్ణాంకం is_jmp)
{
    పూర్ణాంకం r;
    ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	((vtop->r & VT_SYM) && (vtop->c.i-4) == (పూర్ణాంకం)(vtop->c.i-4))) {
        /* constant symbolic case -> simple relocation */
        greloca(cur_పాఠ్యం_section, vtop->sym, ind + 1, R_X86_64_PLT32, (పూర్ణాంకం)(vtop->c.i-4));
        oad(0xe8 + is_jmp, 0); /* call/jmp im */
    } లేకపోతే {
        /* otherwise, indirect call */
        r = TREG_R11;
        ఎక్కించు(r, vtop);
        o(0x41); /* REX */
        o(0xff); /* call/jmp *r */
        o(0xd0 + REG_విలువ(r) + (is_jmp << 4));
    }
}

#ఒకవేళ defined(CONFIG_TCC_BCHECK)

స్థిర శూన్య gen_bounds_call(పూర్ణాంకం v)
{
    Sym *sym = external_helper_sym(v);
    oad(0xe8, 0);
    greloca(cur_పాఠ్యం_section, sym, ind-4, R_X86_64_PLT32, -4);
}

#నిర్వచితమైతే TCC_లక్ష్యం_PE
# define TREG_FASTCALL_1 TREG_RCX
#లేకపోతే
# define TREG_FASTCALL_1 TREG_RDI
#అయితే_ముగింపు

స్థిర శూన్య gen_bounds_prolog(శూన్య)
{
    /* leave some room for bound checking code */
    func_bound_స్థానభ్రంశం = lbounds_section->దత్తాంశం_స్థానభ్రంశం;
    func_bound_ind = ind;
    func_bound_కూడు_epilog = 0;
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /*lbound section pointer */
    gen_le32 (0);
    oad(0xb8, 0); /* call to function */
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
        greloca(cur_పాఠ్యం_section, sym_దత్తాంశం, ind + 3, R_X86_64_PC32, -4);
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
    greloca(cur_పాఠ్యం_section, sym_దత్తాంశం, ind + 3, R_X86_64_PC32, -4);
    o(0x0d8d48 + ((TREG_FASTCALL_1 == TREG_RDI) * 0x300000)); /* lea xxx(%rip), %rcx/rdi */
    gen_le32 (0);
    gen_bounds_call(TOK___bound_local_delete);
    o(0x280f);     /* movaps 0x10(%rsp),%xmm0 */
    o(0x102444);
    o(0x240c280f); /* movaps (%rsp),%xmm1 */
    o(0x20c48348); /* add $32,%rsp */
    o(0x585a); /* restore returned value, if any */
}
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_లక్ష్యం_PE

#నిర్వచించు REGN 4
స్థిర స్థిరరాశి uint8_t arg_regs[REGN] = {
    TREG_RCX, TREG_RDX, TREG_R8, TREG_R9
};

/* Prepare arguments in R10 and R11 rather than RCX and RDX
   because gv() will not ever use these */
స్థిర పూర్ణాంకం arg_prepare_reg(పూర్ణాంకం idx) {
  ఒకవేళ (idx == 0 || idx == 1)
      /* idx=0: r10, idx=1: r11 */
      తిరిగి idx + 10;
  లేకపోతే
      తిరిగి idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */

స్థిర శూన్య gen_offs_sp(పూర్ణాంకం b, పూర్ణాంకం r, పూర్ణాంకం d)
{
    orex(1,0,r & 0x100 ? 0 : r, b);
    ఒకవేళ (d == (గుర్తుగల అక్షరం)d) {
        o(0x2444 | (REG_విలువ(r) << 3));
        g(d);
    } లేకపోతే {
        o(0x2484 | (REG_విలువ(r) << 3));
        gen_le32(d);
    }
}

స్థిర పూర్ణాంకం using_regs(పూర్ణాంకం కొలత)
{
    తిరిగి !(కొలత > 8 || (కొలత & (కొలత - 1)));
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC పూర్ణాంకం gfunc_sret(CType *vt, పూర్ణాంకం variadic, CType *ret, పూర్ణాంకం *ret_align, పూర్ణాంకం *regsize)
{
    పూర్ణాంకం కొలత, align;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8;
    కొలత = type_కొలత(vt, &align);
    ఒకవేళ (!using_regs(కొలత))
        తిరిగి 0;
    ఒకవేళ (కొలత == 8)
        ret->t = VT_LLONG;
    లేకపోతే ఒకవేళ (కొలత == 4)
        ret->t = VT_INT;
    లేకపోతే ఒకవేళ (కొలత == 2)
        ret->t = VT_SHORT;
    లేకపోతే
        ret->t = VT_BYTE;
    ret->ref = ఖాళీ;
    తిరిగి 1;
}

స్థిర పూర్ణాంకం is_sse_float(పూర్ణాంకం t) {
    పూర్ణాంకం bt;
    bt = t & VT_BTYPE;
    తిరిగి bt == VT_DOUBLE || bt == VT_FLOAT;
}

స్థిర పూర్ణాంకం gfunc_arg_కొలత(CType *type) {
    పూర్ణాంకం align;
    ఒకవేళ (type->t & (VT_ARRAY|VT_BITFIELD))
        తిరిగి 8;
    తిరిగి type_కొలత(type, &align);
}

శూన్య gfunc_call(పూర్ణాంకం nb_వాదనలు)
{
    పూర్ణాంకం కొలత, r, వాదనలు_కొలత, i, d, bt, struct_కొలత;
    పూర్ణాంకం arg;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gbound_వాదనలు(nb_వాదనలు);
#అయితే_ముగింపు

    save_regs(nb_వాదనలు);

    వాదనలు_కొలత = (nb_వాదనలు < REGN ? REGN : nb_వాదనలు) * PTR_కొలత;
    arg = nb_వాదనలు;

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    struct_కొలత = వాదనలు_కొలత;
    కొరకు(i = 0; i < nb_వాదనలు; i++) {
        SValue *sv;
        
        --arg;
        sv = &vtop[-i];
        bt = (sv->type.t & VT_BTYPE);
        కొలత = gfunc_arg_కొలత(&sv->type);

        ఒకవేళ (using_regs(కొలత))
            కొనసాగు; /* arguments smaller than 8 bytes passed in registers or on stack */

        ఒకవేళ (bt == VT_STRUCT) {
            /* align to stack align size */
            కొలత = (కొలత + 15) & ~15;
            /* generate structure store */
            r = get_reg(RC_INT);
            gen_offs_sp(0x8d, r, struct_కొలత);
            struct_కొలత += కొలత;

            /* generate memcpy call */
            vset(&sv->type, r | VT_LVAL, 0);
            vpushv(sv);
            vstore();
            --vtop;
        } లేకపోతే ఒకవేళ (bt == VT_LDOUBLE) {
            gv(RC_ST0);
            gen_offs_sp(0xdb, 0x107, struct_కొలత);
            struct_కొలత += 16;
        }
    }

    ఒకవేళ (func_scratch < struct_కొలత)
        func_scratch = struct_కొలత;

    arg = nb_వాదనలు;
    struct_కొలత = వాదనలు_కొలత;

    కొరకు(i = 0; i < nb_వాదనలు; i++) {
        --arg;
        bt = (vtop->type.t & VT_BTYPE);

        కొలత = gfunc_arg_కొలత(&vtop->type);
        ఒకవేళ (!using_regs(కొలత)) {
            /* align to stack align size */
            కొలత = (కొలత + 15) & ~15;
            ఒకవేళ (arg >= REGN) {
                d = get_reg(RC_INT);
                gen_offs_sp(0x8d, d, struct_కొలత);
                gen_offs_sp(0x89, d, arg*8);
            } లేకపోతే {
                d = arg_prepare_reg(arg);
                gen_offs_sp(0x8d, d, struct_కొలత);
            }
            struct_కొలత += కొలత;
        } లేకపోతే {
            ఒకవేళ (is_sse_float(vtop->type.t)) {
		ఒకవేళ (tcc_state->nosse)
		  tcc_error("SSE disabled");
                ఒకవేళ (arg >= REGN) {
                    gv(RC_XMM0);
                    /* movq %xmm0, j*8(%rsp) */
                    gen_offs_sp(0xd60f66, 0x100, arg*8);
                } లేకపోతే {
                    /* Load directly to xmmN register */
                    gv(RC_XMM0 << arg);
                    d = arg_prepare_reg(arg);
                    /* mov %xmmN, %rxx */
                    o(0x66);
                    orex(1,d,0, 0x7e0f);
                    o(0xc0 + arg*8 + REG_విలువ(d));
                }
            } లేకపోతే {
                ఒకవేళ (bt == VT_STRUCT) {
                    vtop->type.ref = ఖాళీ;
                    vtop->type.t = కొలత > 4 ? VT_LLONG : కొలత > 2 ? VT_INT
                        : కొలత > 1 ? VT_SHORT : VT_BYTE;
                }
                
                r = gv(RC_INT);
                ఒకవేళ (arg >= REGN) {
                    gen_offs_sp(0x89, r, arg*8);
                } లేకపోతే {
                    d = arg_prepare_reg(arg);
                    orex(1,d,r,0x89); /* mov */
                    o(0xc0 + REG_విలువ(r) * 8 + REG_విలువ(d));
                }
            }
        }
        vtop--;
    }

    /* Copy R10 and R11 into RCX and RDX, respectively */
    ఒకవేళ (nb_వాదనలు > 0) {
        o(0xd1894c); /* mov %r10, %rcx */
        ఒకవేళ (nb_వాదనలు > 1) {
            o(0xda894c); /* mov %r11, %rdx */
        }
    }
    
    gcall_or_jmp(0);

    ఒకవేళ ((vtop->r & VT_SYM) && vtop->sym->v == TOK_alloca) {
        /* need to add the "func_scratch" area after alloca */
        o(0x48); func_alloca = oad(0x05, func_alloca); /* add $NN, %rax */
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (tcc_state->do_bounds_check)
            gen_bounds_call(TOK___bound_alloca_nr); /* new region */
#అయితే_ముగింపు
    }
    vtop--;
}

#నిర్వచించు FUNC_PROLOG_కొలత 11

/* generate function prolog of type 't' */
శూన్య gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    పూర్ణాంకం addr, reg_param_సూచీ, bt, కొలత;
    Sym *sym;
    CType *type;

    func_ret_sub = 0;
    func_scratch = 32;
    func_alloca = 0;
    loc = 0;

    addr = PTR_కొలత * 2;
    ind += FUNC_PROLOG_కొలత;
    func_sub_sp_స్థానభ్రంశం = ind;
    reg_param_సూచీ = 0;

    sym = func_type->ref;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    కొలత = gfunc_arg_కొలత(&func_vt);
    ఒకవేళ (!using_regs(కొలత)) {
        gen_modrm64(0x89, arg_regs[reg_param_సూచీ], VT_LOCAL, ఖాళీ, addr);
        func_vc = addr;
        reg_param_సూచీ++;
        addr += 8;
    }

    /* define parameters */
    అయితే ((sym = sym->తదుపరి) != ఖాళీ) {
        type = &sym->type;
        bt = type->t & VT_BTYPE;
        కొలత = gfunc_arg_కొలత(type);
        ఒకవేళ (!using_regs(కొలత)) {
            ఒకవేళ (reg_param_సూచీ < REGN) {
                gen_modrm64(0x89, arg_regs[reg_param_సూచీ], VT_LOCAL, ఖాళీ, addr);
            }
            gfunc_సమితి_param(sym, addr, 1);
        } లేకపోతే {
            ఒకవేళ (reg_param_సూచీ < REGN) {
                /* save arguments passed by register */
                ఒకవేళ ((bt == VT_FLOAT) || (bt == VT_DOUBLE)) {
		    ఒకవేళ (tcc_state->nosse)
		      tcc_error("SSE disabled");
                    /* movq */
                    gen_modrm32(0xd60f66, reg_param_సూచీ, VT_LOCAL, ఖాళీ, addr);
                } లేకపోతే {
                    gen_modrm64(0x89, arg_regs[reg_param_సూచీ], VT_LOCAL, ఖాళీ, addr);
                }
            }
            gfunc_సమితి_param(sym, addr, 0);
        }
        addr += 8;
        reg_param_సూచీ++;
    }

    అయితే (reg_param_సూచీ < REGN) {
        ఒకవేళ (func_var) {
            gen_modrm64(0x89, arg_regs[reg_param_సూచీ], VT_LOCAL, ఖాళీ, addr);
            addr += 8;
        }
        reg_param_సూచీ++;
    }
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#అయితే_ముగింపు
}

/* generate function epilog */
శూన్య gfunc_epilog(శూన్య)
{
    పూర్ణాంకం v, ప్రారంభం;

    /* align local size to word & save local variables */
    func_scratch = (func_scratch + 15) & -16;
    loc = (loc & -16) - func_scratch;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#అయితే_ముగింపు

    o(0xc9); /* leave */
    ఒకవేళ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } లేకపోతే {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }

    v = -loc;
    ప్రారంభం = func_sub_sp_స్థానభ్రంశం - FUNC_PROLOG_కొలత;
    cur_పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం = ind;
    pe_కూడు_unwind_దత్తాంశం(ప్రారంభం, ind, v);

    ind = ప్రారంభం;
    ఒకవేళ (v >= 4096) {
        Sym *sym = external_helper_sym(TOK___chkstk);
        oad(0xb8, v); /* mov stacksize, %eax */
        oad(0xe8, 0); /* call __chkstk, (does the stackframe too) */
        greloca(cur_పాఠ్యం_section, sym, ind-4, R_X86_64_PLT32, -4);
        o(0x90); /* fill for FUNC_PROLOG_SIZE = 11 bytes */
    } లేకపోతే {
        o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
        o(0xec8148);  /* sub rsp, stacksize */
        gen_le32(v);
    }
    ind = cur_పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం;

    /* add the "func_scratch" area after each alloca seen */
    gsym_addr(func_alloca, -func_scratch);
}

#లేకపోతే

స్థిర శూన్య gadd_sp(పూర్ణాంకం val)
{
    ఒకవేళ (val == (గుర్తుగల అక్షరం)val) {
        o(0xc48348);
        g(val);
    } లేకపోతే {
        oad(0xc48148, val); /* add $xxx, %rsp */
    }
}

రకనిర్వచనం గణన X86_64_బహుళకం {
  x86_64_బహుళకం_none,
  x86_64_బహుళకం_జ్ఞాపకం,
  x86_64_బహుళకం_integer,
  x86_64_బహుళకం_sse,
  x86_64_బహుళకం_x87
} X86_64_బహుళకం;

స్థిర X86_64_బహుళకం classify_x86_64_విలీనం(X86_64_బహుళకం a, X86_64_బహుళకం b)
{
    ఒకవేళ (a == b)
        తిరిగి a;
    లేకపోతే ఒకవేళ (a == x86_64_బహుళకం_none)
        తిరిగి b;
    లేకపోతే ఒకవేళ (b == x86_64_బహుళకం_none)
        తిరిగి a;
    లేకపోతే ఒకవేళ ((a == x86_64_బహుళకం_జ్ఞాపకం) || (b == x86_64_బహుళకం_జ్ఞాపకం))
        తిరిగి x86_64_బహుళకం_జ్ఞాపకం;
    లేకపోతే ఒకవేళ ((a == x86_64_బహుళకం_integer) || (b == x86_64_బహుళకం_integer))
        తిరిగి x86_64_బహుళకం_integer;
    లేకపోతే ఒకవేళ ((a == x86_64_బహుళకం_x87) || (b == x86_64_బహుళకం_x87))
        తిరిగి x86_64_బహుళకం_జ్ఞాపకం;
    లేకపోతే
        తిరిగి x86_64_బహుళకం_sse;
}

స్థిర X86_64_బహుళకం classify_x86_64_inner(CType *ty)
{
    X86_64_బహుళకం బహుళకం;
    Sym *f;
    
    ఎంపిక (ty->t & VT_BTYPE) {
    స్థితి VT_VOID: తిరిగి x86_64_బహుళకం_none;
    
    స్థితి VT_INT:
    స్థితి VT_BYTE:
    స్థితి VT_SHORT:
    స్థితి VT_LLONG:
    స్థితి VT_BOOL:
    స్థితి VT_PTR:
    స్థితి VT_FUNC:
        తిరిగి x86_64_బహుళకం_integer;
    
    స్థితి VT_FLOAT:
    స్థితి VT_DOUBLE: తిరిగి x86_64_బహుళకం_sse;
    
    స్థితి VT_LDOUBLE: తిరిగి x86_64_బహుళకం_x87;
      
    స్థితి VT_STRUCT:
        f = ty->ref;

        బహుళకం = x86_64_బహుళకం_none;
        కొరకు (f = f->తదుపరి; f; f = f->తదుపరి)
            బహుళకం = classify_x86_64_విలీనం(బహుళకం, classify_x86_64_inner(&f->type));
        
        తిరిగి బహుళకం;
    }
    ప్రతిజ్ఞా(0);
    తిరిగి 0;
}

స్థిర X86_64_బహుళకం classify_x86_64_arg(CType *ty, CType *ret, పూర్ణాంకం *psize, పూర్ణాంకం *palign, పూర్ణాంకం *reg_లెక్క)
{
    X86_64_బహుళకం బహుళకం;
    పూర్ణాంకం కొలత, align, ret_t = 0;
    
    ఒకవేళ (ty->t & (VT_BITFIELD|VT_ARRAY)) {
        *psize = 8;
        *palign = 8;
        *reg_లెక్క = 1;
        ret_t = ty->t;
        బహుళకం = x86_64_బహుళకం_integer;
    } లేకపోతే {
        కొలత = type_కొలత(ty, &align);
        *psize = (కొలత + 7) & ~7;
        *palign = (align + 7) & ~7;
        *reg_లెక్క = 0; /* avoid compiler warning */

        ఒకవేళ (కొలత > 16) {
            బహుళకం = x86_64_బహుళకం_జ్ఞాపకం;
        } లేకపోతే {
            బహుళకం = classify_x86_64_inner(ty);
            ఎంపిక (బహుళకం) {
            స్థితి x86_64_బహుళకం_integer:
                ఒకవేళ (కొలత > 8) {
                    *reg_లెక్క = 2;
                    ret_t = VT_QLONG;
                } లేకపోతే {
                    *reg_లెక్క = 1;
                    ఒకవేళ (కొలత > 4)
                        ret_t = VT_LLONG;
                    లేకపోతే ఒకవేళ (కొలత > 2)
                        ret_t = VT_INT;
                    లేకపోతే ఒకవేళ (కొలత > 1)
                        ret_t = VT_SHORT;
                    లేకపోతే
                        ret_t = VT_BYTE;
                    ఒకవేళ ((ty->t & VT_BTYPE) == VT_STRUCT || (ty->t & VT_UNSIGNED))
                        ret_t |= VT_UNSIGNED;
                }
                ఆపు;
                
            స్థితి x86_64_బహుళకం_x87:
                *reg_లెక్క = 1;
                ret_t = VT_LDOUBLE;
                ఆపు;

            స్థితి x86_64_బహుళకం_sse:
                ఒకవేళ (కొలత > 8) {
                    *reg_లెక్క = 2;
                    ret_t = VT_QFLOAT;
                } లేకపోతే {
                    *reg_లెక్క = 1;
                    ret_t = (కొలత > 4) ? VT_DOUBLE : VT_FLOAT;
                }
                ఆపు;
            అప్రమేయ: ఆపు; /* nothing to be done for x86_64_mode_memory and x86_64_mode_none*/
            }
        }
    }
    
    ఒకవేళ (ret) {
        ret->ref = ఖాళీ;
        ret->t = ret_t;
    }
    
    తిరిగి బహుళకం;
}

ST_FUNC పూర్ణాంకం classify_x86_64_va_arg(CType *ty)
{
    /* This definition must be synced with stdarg.h */
    గణన __va_arg_type {
        __va_gen_reg, __va_float_reg, __va_stack
    };
    పూర్ణాంకం కొలత, align, reg_లెక్క;
    X86_64_బహుళకం బహుళకం = classify_x86_64_arg(ty, ఖాళీ, &కొలత, &align, &reg_లెక్క);
    ఎంపిక (బహుళకం) {
    అప్రమేయ: తిరిగి __va_stack;
    స్థితి x86_64_బహుళకం_integer: తిరిగి __va_gen_reg;
    స్థితి x86_64_బహుళకం_sse: తిరిగి __va_float_reg;
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC పూర్ణాంకం gfunc_sret(CType *vt, పూర్ణాంకం variadic, CType *ret, పూర్ణాంకం *ret_align, పూర్ణాంకం *regsize)
{
    పూర్ణాంకం కొలత, align, reg_లెక్క;
    ఒకవేళ (classify_x86_64_arg(vt, ret, &కొలత, &align, &reg_లెక్క) == x86_64_బహుళకం_జ్ఞాపకం)
        తిరిగి 0;
    *ret_align = 1; // Never have to re-align return values for x86-64
    *regsize = 8 * reg_లెక్క; /* the (virtual) regsize is 16 for VT_QLONG/QFLOAT */
    తిరిగి 1;
}

#నిర్వచించు REGN 6
స్థిర స్థిరరాశి uint8_t arg_regs[REGN] = {
    TREG_RDI, TREG_RSI, TREG_RDX, TREG_RCX, TREG_R8, TREG_R9
};

స్థిర పూర్ణాంకం arg_prepare_reg(పూర్ణాంకం idx) {
  ఒకవేళ (idx == 2 || idx == 3)
      /* idx=2: r10, idx=3: r11 */
      తిరిగి idx + 8;
  లేకపోతే
      తిరిగి idx >= 0 && idx < REGN ? arg_regs[idx] : 0;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
శూన్య gfunc_call(పూర్ణాంకం nb_వాదనలు)
{
    X86_64_బహుళకం బహుళకం;
    CType type;
    పూర్ణాంకం కొలత, align, r, వాదనలు_కొలత, దొంతర_adjust, i, reg_లెక్క, k;
    పూర్ణాంకం nb_reg_వాదనలు = 0;
    పూర్ణాంకం nb_sse_వాదనలు = 0;
    పూర్ణాంకం sse_reg, gen_reg;
    అక్షరం *onstack = tcc_malloc((nb_వాదనలు + 1) * పరిమాణం (అక్షరం));

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gbound_వాదనలు(nb_వాదనలు);
#అయితే_ముగింపు

    save_regs(nb_వాదనలు);

    /* calculate the number of integer/float register arguments, remember
       arguments to be passed via stack (in onstack[]), and also remember
       if we have to align the stack pointer to 16 (onstack[i] == 2).  Needs
       to be done in a left-to-right pass over arguments.  */
    దొంతర_adjust = 0;
    కొరకు(i = nb_వాదనలు - 1; i >= 0; i--) {
        బహుళకం = classify_x86_64_arg(&vtop[-i].type, ఖాళీ, &కొలత, &align, &reg_లెక్క);
        ఒకవేళ (కొలత == 0) కొనసాగు;
        ఒకవేళ (బహుళకం == x86_64_బహుళకం_sse && nb_sse_వాదనలు + reg_లెక్క <= 8) {
            nb_sse_వాదనలు += reg_లెక్క;
	    onstack[i] = 0;
	} లేకపోతే ఒకవేళ (బహుళకం == x86_64_బహుళకం_integer && nb_reg_వాదనలు + reg_లెక్క <= REGN) {
            nb_reg_వాదనలు += reg_లెక్క;
	    onstack[i] = 0;
	} లేకపోతే ఒకవేళ (బహుళకం == x86_64_బహుళకం_none) {
	    onstack[i] = 0;
	} లేకపోతే {
	    ఒకవేళ (align == 16 && (దొంతర_adjust &= 15)) {
		onstack[i] = 2;
		దొంతర_adjust = 0;
	    } లేకపోతే
	      onstack[i] = 1;
	    దొంతర_adjust += కొలత;
	}
    }

    ఒకవేళ (nb_sse_వాదనలు && tcc_state->nosse)
      tcc_error("SSE disabled but floating point arguments passed");

    /* for struct arguments, we need to call memcpy and the function
       call breaks register passing arguments we are preparing.
       So, we process arguments which will be passed by stack first. */
    gen_reg = nb_reg_వాదనలు;
    sse_reg = nb_sse_వాదనలు;
    వాదనలు_కొలత = 0;
    దొంతర_adjust &= 15;
    కొరకు (i = k = 0; i < nb_వాదనలు;) {
	బహుళకం = classify_x86_64_arg(&vtop[-i].type, ఖాళీ, &కొలత, &align, &reg_లెక్క);
	ఒకవేళ (కొలత) {
            ఒకవేళ (!onstack[i + k]) {
	        ++i;
	        కొనసాగు;
	    }
            /* Possibly adjust stack to align SSE boundary.  We're processing
	       args from right to left while allocating happens left to right
	       (stack grows down), so the adjustment needs to happen _after_
	       an argument that requires it.  */
            ఒకవేళ (దొంతర_adjust) {
	        o(0x50); /* push %rax; aka sub $8,%rsp */
                వాదనలు_కొలత += 8;
	        దొంతర_adjust = 0;
            }
	    ఒకవేళ (onstack[i + k] == 2)
	        దొంతర_adjust = 1;
        }

	vrotb(i+1);

	ఎంపిక (vtop->type.t & VT_BTYPE) {
	    స్థితి VT_STRUCT:
		/* allocate the necessary size on stack */
		o(0x48);
		oad(0xec81, కొలత); /* sub $xxx, %rsp */
		/* generate structure store */
		r = get_reg(RC_INT);
		orex(1, r, 0, 0x89); /* mov %rsp, r */
		o(0xe0 + REG_విలువ(r));
		vset(&vtop->type, r | VT_LVAL, 0);
		vswap();
		/* keep stack aligned for (__bound_)memmove call */
		o(0x10ec8348); /* sub $16,%rsp */
		o(0xf0e48348); /* and $-16,%rsp */
		orex(0,r,0,0x50 + REG_విలువ(r)); /* push r (last %rsp) */
		o(0x08ec8348); /* sub $8,%rsp */
		vstore();
		o(0x08c48348); /* add $8,%rsp */
		o(0x5c);       /* pop %rsp */
		ఆపు;

	    స్థితి VT_LDOUBLE:
                gv(RC_ST0);
                oad(0xec8148, కొలత); /* sub $xxx, %rsp */
                o(0x7cdb); /* fstpt 0(%rsp) */
                g(0x24);
                g(0x00);
		ఆపు;

	    స్థితి VT_FLOAT:
	    స్థితి VT_DOUBLE:
		ప్రతిజ్ఞా(బహుళకం == x86_64_బహుళకం_sse);
		r = gv(RC_FLOAT);
		o(0x50); /* push $rax */
		/* movq %xmmN, (%rsp) */
		o(0xd60f66);
		o(0x04 + REG_విలువ(r)*8);
		o(0x24);
		ఆపు;

	    అప్రమేయ:
		ప్రతిజ్ఞా(బహుళకం == x86_64_బహుళకం_integer);
		/* simple type */
		/* XXX: implicit cast ? */
		r = gv(RC_INT);
		orex(0,r,0,0x50 + REG_విలువ(r)); /* push r */
		ఆపు;
	}
	వాదనలు_కొలత += కొలత;

	vpop();
	--nb_వాదనలు;
	k++;
    }

    tcc_free(onstack);

    /* then, we prepare register passing arguments.
       Note that we cannot set RDX and RCX in this loop because gv()
       may break these temporary registers. Let's use R10 and R11
       instead of them */
    ప్రతిజ్ఞా(gen_reg <= REGN);
    ప్రతిజ్ఞా(sse_reg <= 8);
    కొరకు(i = 0; i < nb_వాదనలు; i++) {
        బహుళకం = classify_x86_64_arg(&vtop->type, &type, &కొలత, &align, &reg_లెక్క);
        ఒకవేళ (కొలత == 0) కొనసాగు;
        /* Alter stack entry type so that gv() knows how to treat it */
        vtop->type = type;
        ఒకవేళ (బహుళకం == x86_64_బహుళకం_sse) {
            ఒకవేళ (reg_లెక్క == 2) {
                sse_reg -= 2;
                gv(RC_FRET); /* Use pair load into xmm0 & xmm1 */
                ఒకవేళ (sse_reg) { /* avoid redundant movaps %xmm0, %xmm0 */
                    /* movaps %xmm1, %xmmN */
                    o(0x280f);
                    o(0xc1 + ((sse_reg+1) << 3));
                    /* movaps %xmm0, %xmmN */
                    o(0x280f);
                    o(0xc0 + (sse_reg << 3));
                }
            } లేకపోతే {
                ప్రతిజ్ఞా(reg_లెక్క == 1);
                --sse_reg;
                /* Load directly to register */
                gv(RC_XMM0 << sse_reg);
            }
        } లేకపోతే ఒకవేళ (బహుళకం == x86_64_బహుళకం_integer) {
            /* simple type */
            /* XXX: implicit cast ? */
            పూర్ణాంకం d;
            gen_reg -= reg_లెక్క;
            r = gv(RC_INT);
            d = arg_prepare_reg(gen_reg);
            orex(1,d,r,0x89); /* mov */
            o(0xc0 + REG_విలువ(r) * 8 + REG_విలువ(d));
            ఒకవేళ (reg_లెక్క == 2) {
                d = arg_prepare_reg(gen_reg+1);
                orex(1,d,vtop->r2,0x89); /* mov */
                o(0xc0 + REG_విలువ(vtop->r2) * 8 + REG_విలువ(d));
            }
        }
        vtop--;
    }
    ప్రతిజ్ఞా(gen_reg == 0);
    ప్రతిజ్ఞా(sse_reg == 0);

    /* Copy R10 and R11 into RDX and RCX, respectively */
    ఒకవేళ (nb_reg_వాదనలు > 2) {
        o(0xd2894c); /* mov %r10, %rdx */
        ఒకవేళ (nb_reg_వాదనలు > 3) {
            o(0xd9894c); /* mov %r11, %rcx */
        }
    }

    ఒకవేళ (vtop->type.ref->f.func_type != FUNC_NEW) /* implies FUNC_OLD or FUNC_ELLIPSIS */
        oad(0xb8, nb_sse_వాదనలు < 8 ? nb_sse_వాదనలు : 8); /* mov nb_sse_args, %eax */
    gcall_or_jmp(0);
    ఒకవేళ (వాదనలు_కొలత)
        gadd_sp(వాదనలు_కొలత);
    vtop--;
}

#నిర్వచించు FUNC_PROLOG_కొలత 11

స్థిర శూన్య నెట్టు_arg_reg(పూర్ణాంకం i) {
    loc -= 8;
    gen_modrm64(0x89, arg_regs[i], VT_LOCAL, ఖాళీ, loc);
}

/* generate function prolog of type 't' */
శూన్య gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    X86_64_బహుళకం బహుళకం, ret_బహుళకం;
    పూర్ణాంకం i, addr, align, కొలత, reg_లెక్క;
    పూర్ణాంకం param_addr = 0, reg_param_సూచీ, sse_param_సూచీ;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    addr = PTR_కొలత * 2;
    loc = 0;
    ind += FUNC_PROLOG_కొలత;
    func_sub_sp_స్థానభ్రంశం = ind;
    func_ret_sub = 0;
    ret_బహుళకం = classify_x86_64_arg(&func_vt, ఖాళీ, &కొలత, &align, &reg_లెక్క);

    ఒకవేళ (func_var) {
        పూర్ణాంకం చూసిన_reg_అంకె, చూసిన_sse_అంకె, చూసిన_దొంతర_కొలత;
        చూసిన_reg_అంకె = ret_బహుళకం == x86_64_బహుళకం_జ్ఞాపకం;
        చూసిన_sse_అంకె = 0;
        /* frame pointer and return address */
        చూసిన_దొంతర_కొలత = PTR_కొలత * 2;
        /* count the number of seen parameters */
        sym = func_type->ref;
        అయితే ((sym = sym->తదుపరి) != ఖాళీ) {
            type = &sym->type;
            బహుళకం = classify_x86_64_arg(type, ఖాళీ, &కొలత, &align, &reg_లెక్క);
            ఎంపిక (బహుళకం) {
            అప్రమేయ:
            దొంతర_arg:
                చూసిన_దొంతర_కొలత = ((చూసిన_దొంతర_కొలత + align - 1) & -align) + కొలత;
                ఆపు;
                
            స్థితి x86_64_బహుళకం_integer:
                ఒకవేళ (చూసిన_reg_అంకె + reg_లెక్క > REGN)
		    వెళ్ళు దొంతర_arg;
		చూసిన_reg_అంకె += reg_లెక్క;
                ఆపు;
                
            స్థితి x86_64_బహుళకం_sse:
                ఒకవేళ (చూసిన_sse_అంకె + reg_లెక్క > 8)
		    వెళ్ళు దొంతర_arg;
		చూసిన_sse_అంకె += reg_లెక్క;
                ఆపు;
            }
        }

        loc -= 24;
        /* movl $0x????????, -0x18(%rbp) */
        o(0xe845c7);
        gen_le32(చూసిన_reg_అంకె * 8);
        /* movl $0x????????, -0x14(%rbp) */
        o(0xec45c7);
        gen_le32(చూసిన_sse_అంకె * 16 + 48);
	/* leaq $0x????????, %r11 */
	o(0x9d8d4c);
	gen_le32(చూసిన_దొంతర_కొలత);
	/* movq %r11, -0x10(%rbp) */
	o(0xf05d894c);
	/* leaq $-200(%rbp), %r11 */
	o(0x9d8d4c);
	gen_le32(-176 - 24);
	/* movq %r11, -0x8(%rbp) */
	o(0xf85d894c);

        /* save all register passing arguments */
        కొరకు (i = 0; i < 8; i++) {
            loc -= 16;
	    ఒకవేళ (!tcc_state->nosse) {
                /* movq */
		gen_modrm32(0xd60f66, 7 - i, VT_LOCAL, ఖాళీ, loc);
	    }
            /* movq $0, loc+8(%rbp) */
            o(0x85c748);
            gen_le32(loc + 8);
            gen_le32(0);
        }
        కొరకు (i = 0; i < REGN; i++) {
            నెట్టు_arg_reg(REGN-1-i);
        }
    }

    sym = func_type->ref;
    reg_param_సూచీ = 0;
    sse_param_సూచీ = 0;

    /* if the function returns a structure, then add an
       implicit pointer parameter */
    ఒకవేళ (ret_బహుళకం == x86_64_బహుళకం_జ్ఞాపకం) {
        నెట్టు_arg_reg(reg_param_సూచీ);
        func_vc = loc;
        reg_param_సూచీ++;
    }
    /* define parameters */
    అయితే ((sym = sym->తదుపరి) != ఖాళీ) {
        type = &sym->type;
        బహుళకం = classify_x86_64_arg(type, ఖాళీ, &కొలత, &align, &reg_లెక్క);
        ఎంపిక (బహుళకం) {
        స్థితి x86_64_బహుళకం_sse:
	    ఒకవేళ (tcc_state->nosse)
	        tcc_error("SSE disabled but floating point arguments used");
            ఒకవేళ (sse_param_సూచీ + reg_లెక్క <= 8) {
                /* save arguments passed by register */
                loc -= reg_లెక్క * 8;
                param_addr = loc;
                కొరకు (i = 0; i < reg_లెక్క; ++i) {
                    gen_modrm32(0xd60f66, sse_param_సూచీ, VT_LOCAL, ఖాళీ, param_addr + i*8);
                    ++sse_param_సూచీ;
                }
            } లేకపోతే {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += కొలత;
            }
            ఆపు;
            
        స్థితి x86_64_బహుళకం_జ్ఞాపకం:
        స్థితి x86_64_బహుళకం_x87:
            addr = (addr + align - 1) & -align;
            param_addr = addr;
            addr += కొలత;
            ఆపు;
            
        స్థితి x86_64_బహుళకం_integer: {
            ఒకవేళ (reg_param_సూచీ + reg_లెక్క <= REGN) {
                /* save arguments passed by register */
                loc -= reg_లెక్క * 8;
                param_addr = loc;
                కొరకు (i = 0; i < reg_లెక్క; ++i) {
                    gen_modrm64(0x89, arg_regs[reg_param_సూచీ], VT_LOCAL, ఖాళీ, param_addr + i*8);
                    ++reg_param_సూచీ;
                }
            } లేకపోతే {
                addr = (addr + align - 1) & -align;
                param_addr = addr;
                addr += కొలత;
            }
            ఆపు;
        }
	అప్రమేయ: ఆపు; /* nothing to be done for x86_64_mode_none */
        }
        gfunc_సమితి_param(sym, param_addr, 0);
    }

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gen_bounds_prolog();
#అయితే_ముగింపు
}

/* generate function epilog */
శూన్య gfunc_epilog(శూన్య)
{
    పూర్ణాంకం v, saved_ind;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check)
        gen_bounds_epilog();
#అయితే_ముగింపు
    o(0xc9); /* leave */
    ఒకవేళ (func_ret_sub == 0) {
        o(0xc3); /* ret */
    } లేకపోతే {
        o(0xc2); /* ret n */
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    /* align local size to word & save local variables */
    v = (-loc + 15) & -16;
    saved_ind = ind;
    ind = func_sub_sp_స్థానభ్రంశం - FUNC_PROLOG_కొలత;
    o(0xe5894855);  /* push %rbp, mov %rsp, %rbp */
    o(0xec8148);  /* sub rsp, stacksize */
    gen_le32(v);
    ind = saved_ind;
}

#అయితే_ముగింపు /* not PE */

ST_FUNC శూన్య gen_fill_nops(పూర్ణాంకం బైట్లు)
{
    అయితే (బైట్లు--)
      g(0x90);
}

/* generate a jump to a label */
పూర్ణాంకం gjmp(పూర్ణాంకం t)
{
    తిరిగి gjmp2(0xe9, t);
}

/* generate a jump to a fixed address */
శూన్య gjmp_addr(పూర్ణాంకం a)
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
        ఒకవేళ (op & 0x100)
	  {
	    /* This was a float compare.  If the parity flag is set
	       the result was unordered.  For anything except != this
	       means false and we don't jump (anding both conditions).
	       For != this means true (oring both).
	       Take care about inverting the test.  We need to jump
	       to our target if the result was unordered and test wasn't NE,
	       otherwise if unordered we don't want to jump.  */
            పూర్ణాంకం v = vtop->cmp_r;
            op &= ~0x100;
            ఒకవేళ (op ^ v ^ (v != TOK_NE))
              o(0x067a);  /* jp +6 */
	    లేకపోతే
	      {
	        g(0x0f);
		t = gjmp2(0x8a, t); /* jp t */
	      }
	  }
        g(0x0f);
        t = gjmp2(op - 16, t);
        తిరిగి t;
}

/* generate an integer binary operation */
శూన్య gen_opi(పూర్ణాంకం op)
{
    పూర్ణాంకం r, fr, opc, c;
    పూర్ణాంకం ll, uu, cc;

    ll = is64_type(vtop[-1].type.t);
    uu = (vtop[-1].type.t & VT_UNSIGNED) != 0;
    cc = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;

    ఎంపిక(op) {
    స్థితి '+':
    స్థితి TOK_ADDC1: /* add with carry generation */
        opc = 0;
    gen_op8:
        ఒకవేళ (cc && (!ll || (పూర్ణాంకం)vtop->c.i == vtop->c.i)) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            c = vtop->c.i;
            ఒకవేళ (c == (గుర్తుగల అక్షరం)c) {
                /* XXX: generate inc and dec for smaller code ? */
                orex(ll, r, 0, 0x83);
                o(0xc0 | (opc << 3) | REG_విలువ(r));
                g(c);
            } లేకపోతే {
                orex(ll, r, 0, 0x81);
                oad(0xc0 | (opc << 3) | REG_విలువ(r), c);
            }
        } లేకపోతే {
            gv2(RC_INT, RC_INT);
            r = vtop[-1].r;
            fr = vtop[0].r;
            orex(ll, r, fr, (opc << 3) | 0x01);
            o(0xc0 + REG_విలువ(r) + REG_విలువ(fr) * 8);
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
        orex(ll, fr, r, 0xaf0f); /* imul fr, r */
        o(0xc0 + REG_విలువ(fr) + REG_విలువ(r) * 8);
        vtop--;
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
        ఒకవేళ (cc) {
            /* constant case */
            vswap();
            r = gv(RC_INT);
            vswap();
            orex(ll, r, 0, 0xc1); /* shl/shr/sar $xxx, r */
            o(opc | REG_విలువ(r));
            g(vtop->c.i & (ll ? 63 : 31));
        } లేకపోతే {
            /* we generate the shift in ecx */
            gv2(RC_INT, RC_RCX);
            r = vtop[-1].r;
            orex(ll, r, 0, 0xd3); /* shl/shr/sar %cl, r */
            o(opc | REG_విలువ(r));
        }
        vtop--;
        ఆపు;
    స్థితి TOK_UDIV:
    స్థితి TOK_UMOD:
        uu = 1;
        వెళ్ళు divmod;
    స్థితి '/':
    స్థితి '%':
    స్థితి TOK_PDIV:
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
        o((uu ? 0xf0 : 0xf8) + REG_విలువ(fr));
        ఒకవేళ (op == '%' || op == TOK_UMOD)
            r = TREG_RDX;
        లేకపోతే
            r = TREG_RAX;
        vtop->r = r;
        ఆపు;
    అప్రమేయ:
        opc = 7;
        వెళ్ళు gen_op8;
    }
}

శూన్య gen_opl(పూర్ణాంకం op)
{
    gen_opi(op);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
శూన్య gen_opf(పూర్ణాంకం op)
{
    పూర్ణాంకం a, ft, fc, swapped, r, opc;
    పూర్ణాంకం bt = vtop->type.t & VT_BTYPE;
    పూర్ణాంకం float_type = bt == VT_LDOUBLE ? RC_ST0 : RC_FLOAT;

    ఒకవేళ (op == TOK_NEG) { /* unary minus */
        gv(float_type);
        ఒకవేళ (float_type == RC_ST0) {
            o(0xe0d9); /* fchs */
        } లేకపోతే {
            save_reg(vtop->r);
            /* xor $0x80, $n(rbp) */
            gen_modrm32(0x80, 6, vtop->r, ఖాళీ, vtop->c.i + (bt == VT_DOUBLE ? 7 : 3));
            o(0x80);
            gv(float_type); /* -n is not a lvalue */
        }
        తిరిగి;
    }

    /* convert constants to memory references */
    ఒకవేళ ((vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
        vswap();
        gv(float_type);
        vswap();
    }
    ఒకవేళ ((vtop[0].r & (VT_VALMASK | VT_LVAL)) == VT_CONST)
        gv(float_type);

    /* must put at least one value in the floating point register */
    ఒకవేళ ((vtop[-1].r & VT_LVAL) &&
        (vtop[0].r & VT_LVAL)) {
        vswap();
        gv(float_type);
        vswap();
    }
    swapped = 0;
    /* swap the stack if needed so that t1 is the register and t2 is
       the memory reference */
    ఒకవేళ (vtop[-1].r & VT_LVAL) {
        vswap();
        swapped = 1;
    }
    ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
        ఒకవేళ (op >= TOK_ULT && op <= TOK_GT) {
            /* load on stack second operand */
            ఎక్కించు(TREG_ST0, vtop);
            save_reg(TREG_RAX); /* eax is used by FP comparison code */
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
            ఎక్కించు(TREG_ST0, vtop);
            swapped = !swapped;

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
            o(0xde); /* fxxxp %st, %st(1) */
            o(0xc1 + (a << 3));
            vtop--;
        }
    } లేకపోతే {
        ఒకవేళ (op >= TOK_ULT && op <= TOK_GT) {
            /* if saved lvalue, then we must reload it */
            r = vtop->r;
            fc = vtop->c.i;
            ఒకవేళ ((r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
                v1.sym = ఖాళీ;
                ఎక్కించు(r, &v1);
                fc = 0;
                vtop->r = r = r | VT_LVAL;
            }

            ఒకవేళ (op == TOK_EQ || op == TOK_NE) {
                swapped = 0;
            } లేకపోతే {
                ఒకవేళ (op == TOK_LE || op == TOK_LT)
                    swapped = !swapped;
                ఒకవేళ (op == TOK_LE || op == TOK_GE) {
                    op = 0x93; /* setae */
                } లేకపోతే {
                    op = 0x97; /* seta */
                }
            }

            ఒకవేళ (swapped) {
                gv(RC_FLOAT);
                vswap();
            }
            ప్రతిజ్ఞా(!(vtop[-1].r & VT_LVAL));
            
            ఒకవేళ (op == TOK_EQ || op == TOK_NE)
                opc = 0x2e0f; /* ucomisd */
            లేకపోతే
                opc = 0x2f0f; /* comisd */
            ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
                opc = opc << 8 | 0x66;

            gen_modrm32(opc, vtop[-1].r, vtop->r, vtop->sym, fc);
            vtop--;
            vset_VT_CMP(op | 0x100);
            vtop->cmp_r = op;
        } లేకపోతే {
            ప్రతిజ్ఞా((vtop->type.t & VT_BTYPE) != VT_LDOUBLE);
            ఎంపిక(op) {
            అప్రమేయ:
            స్థితి '+':
                a = 0;
                ఆపు;
            స్థితి '-':
                a = 4;
                ఆపు;
            స్థితి '*':
                a = 1;
                ఆపు;
            స్థితి '/':
                a = 6;
                ఆపు;
            }
            ft = vtop->type.t;
            fc = vtop->c.i;
            ప్రతిజ్ఞా((ft & VT_BTYPE) != VT_LDOUBLE);
            
            /* if saved lvalue, then we must reload it */
            ఒకవేళ ((vtop->r & VT_VALMASK) == VT_LLOCAL) {
                SValue v1;
                r = get_reg(RC_INT);
                v1.type.t = VT_PTR;
                v1.r = VT_LOCAL | VT_LVAL;
                v1.c.i = fc;
	        v1.sym = ఖాళీ;
                ఎక్కించు(r, &v1);
                fc = 0;
                vtop->r = r | VT_LVAL;
            }
            
            ప్రతిజ్ఞా(!(vtop[-1].r & VT_LVAL));
            ఒకవేళ (swapped) {
                ప్రతిజ్ఞా(vtop->r & VT_LVAL);
                gv(RC_FLOAT);
                vswap();
                fc = vtop->c.i; /* bcheck may have saved previous vtop[-1] */
            }
            
            ఒకవేళ ((ft & VT_BTYPE) == VT_DOUBLE) {
                o(0xf2);
            } లేకపోతే {
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
శూన్య gen_cvt_itof(పూర్ణాంకం t)
{
    ఒకవేళ ((t & VT_BTYPE) == VT_LDOUBLE) {
        save_reg(TREG_ST0);
        gv(RC_INT);
        ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
            /* signed long long to float/double/long double (unsigned case
               is handled generically) */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        } లేకపోతే ఒకవేళ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
                   (VT_INT | VT_UNSIGNED)) {
            /* unsigned int to float/double/long double */
            o(0x6a); /* push $0 */
            g(0x00);
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x242cdf); /* fildll (%rsp) */
            o(0x10c48348); /* add $16, %rsp */
        } లేకపోతే {
            /* int to float/double/long double */
            o(0x50 + (vtop->r & VT_VALMASK)); /* push r */
            o(0x2404db); /* fildl (%rsp) */
            o(0x08c48348); /* add $8, %rsp */
        }
        vtop->r = TREG_ST0;
    } లేకపోతే {
        పూర్ణాంకం r = get_reg(RC_FLOAT);
        gv(RC_INT);
        o(0xf2 + ((t & VT_BTYPE) == VT_FLOAT?1:0));
        ఒకవేళ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) ==
            (VT_INT | VT_UNSIGNED) ||
            (vtop->type.t & VT_BTYPE) == VT_LLONG) {
            o(0x48); /* REX */
        }
        o(0x2a0f);
        o(0xc0 + (vtop->r & VT_VALMASK) + REG_విలువ(r)*8); /* cvtsi2sd */
        vtop->r = r;
    }
}

/* convert from one floating point type to another */
శూన్య gen_cvt_ftof(పూర్ణాంకం t)
{
    పూర్ణాంకం ft, bt, tbt;

    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    tbt = t & VT_BTYPE;
    
    ఒకవేళ (bt == VT_FLOAT) {
        gv(RC_FLOAT);
        ఒకవేళ (tbt == VT_DOUBLE) {
            o(0x140f); /* unpcklps */
            o(0xc0 + REG_విలువ(vtop->r)*9);
            o(0x5a0f); /* cvtps2pd */
            o(0xc0 + REG_విలువ(vtop->r)*9);
        } లేకపోతే ఒకవేళ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movss %xmm0,-0x10(%rsp) */
            o(0x110ff3);
            o(0x44 + REG_విలువ(vtop->r)*8);
            o(0xf024);
            o(0xf02444d9); /* flds -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } లేకపోతే ఒకవేళ (bt == VT_DOUBLE) {
        gv(RC_FLOAT);
        ఒకవేళ (tbt == VT_FLOAT) {
            o(0x140f66); /* unpcklpd */
            o(0xc0 + REG_విలువ(vtop->r)*9);
            o(0x5a0f66); /* cvtpd2ps */
            o(0xc0 + REG_విలువ(vtop->r)*9);
        } లేకపోతే ఒకవేళ (tbt == VT_LDOUBLE) {
            save_reg(RC_ST0);
            /* movsd %xmm0,-0x10(%rsp) */
            o(0x110ff2);
            o(0x44 + REG_విలువ(vtop->r)*8);
            o(0xf024);
            o(0xf02444dd); /* fldl -0x10(%rsp) */
            vtop->r = TREG_ST0;
        }
    } లేకపోతే {
        పూర్ణాంకం r;
        gv(RC_ST0);
        r = get_reg(RC_FLOAT);
        ఒకవేళ (tbt == VT_DOUBLE) {
            o(0xf0245cdd); /* fstpl -0x10(%rsp) */
            /* movsd -0x10(%rsp),%xmm0 */
            o(0x100ff2);
            o(0x44 + REG_విలువ(r)*8);
            o(0xf024);
            vtop->r = r;
        } లేకపోతే ఒకవేళ (tbt == VT_FLOAT) {
            o(0xf0245cd9); /* fstps -0x10(%rsp) */
            /* movss -0x10(%rsp),%xmm0 */
            o(0x100ff3);
            o(0x44 + REG_విలువ(r)*8);
            o(0xf024);
            vtop->r = r;
        }
    }
}

/* convert fp to int 't' type */
శూన్య gen_cvt_ftoi(పూర్ణాంకం t)
{
    పూర్ణాంకం ft, bt, కొలత, r;
    ft = vtop->type.t;
    bt = ft & VT_BTYPE;
    ఒకవేళ (bt == VT_LDOUBLE) {
	ఒకవేళ (t != VT_INT) {
	    vpush_helper_func(TOK___fixxfdi);
	    vswap();
	    gfunc_call(1);
	    vpushi(0);
	    vtop->r = REG_IRET;
	    vtop->r2 = REG_IRE2;
	    తిరిగి;
	}
        gen_cvt_ftof(VT_DOUBLE);
        bt = VT_DOUBLE;
    }

    gv(RC_FLOAT);
    ఒకవేళ (t != VT_INT)
        కొలత = 8;
    లేకపోతే
        కొలత = 4;

    r = get_reg(RC_INT);
    ఒకవేళ (bt == VT_FLOAT) {
        o(0xf3);
    } లేకపోతే ఒకవేళ (bt == VT_DOUBLE) {
        o(0xf2);
    } లేకపోతే {
        ప్రతిజ్ఞా(0);
    }
    orex(కొలత == 8, r, 0, 0x2c0f); /* cvttss2si or cvttsd2si */
    o(0xc0 + REG_విలువ(vtop->r) + REG_విలువ(r)*8);
    vtop->r = r;
}

// Generate sign extension from 32 to 64 bits:
ST_FUNC శూన్య gen_cvt_sxtw(శూన్య)
{
    పూర్ణాంకం r = gv(RC_INT);
    /* x86_64 specific: movslq */
    o(0x6348);
    o(0xc0 + (REG_విలువ(r) << 3) + REG_విలువ(r));
}

/* char/short to int conversion */
ST_FUNC శూన్య gen_cvt_csti(పూర్ణాంకం t)
{
    పూర్ణాంకం r, sz, xl, ll;
    r = gv(RC_INT);
    sz = !(t & VT_UNSIGNED);
    xl = (t & VT_BTYPE) == VT_SHORT;
    ll = (vtop->type.t & VT_BTYPE) == VT_LLONG;
    orex(ll, r, 0, 0xc0b60f /* mov[sz] %a[xl], %eax */
        | (sz << 3 | xl) << 8
        | (REG_విలువ(r) << 3 | REG_విలువ(r)) << 16
        );
}

/* increment tcov counter */
ST_FUNC శూన్య gen_increment_tcov (SValue *sv)
{
   o(0x058348); /* addq $1, xxx(%rip) */
   greloca(cur_పాఠ్యం_section, sv->sym, ind, R_X86_64_PC32, -5);
   gen_le32(0);
   o(1);
}

/* computed goto support */
ST_FUNC శూన్య ggoto(శూన్య)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC శూన్య gen_vla_sp_save(పూర్ణాంకం addr) {
    /* mov %rsp,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RSP, VT_LOCAL, ఖాళీ, addr);
}

/* Restore the SP from a location on the stack */
ST_FUNC శూన్య gen_vla_sp_restore(పూర్ణాంకం addr) {
    gen_modrm64(0x8b, TREG_RSP, VT_LOCAL, ఖాళీ, addr);
}

#నిర్వచితమైతే TCC_లక్ష్యం_PE
/* Save result of gen_vla_alloc onto the stack */
ST_FUNC శూన్య gen_vla_ఫలితం(పూర్ణాంకం addr) {
    /* mov %rax,addr(%rbp)*/
    gen_modrm64(0x89, TREG_RAX, VT_LOCAL, ఖాళీ, addr);
}
#అయితే_ముగింపు

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC శూన్య gen_vla_alloc(CType *type, పూర్ణాంకం align) {
    పూర్ణాంకం use_call = 0;

#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    use_call = tcc_state->do_bounds_check;
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_PE	/* alloca does more than just adjust %rsp on Windows */
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
        o(0x2b48);
        o(0xe0 | REG_విలువ(r));
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
ST_FUNC శూన్య gen_struct_copy(పూర్ణాంకం కొలత)
{
    పూర్ణాంకం n = కొలత / PTR_కొలత;
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    o(0x5756); /* push rsi, rdi */
#అయితే_ముగింపు
    gv2(RC_RDI, RC_RSI);
    ఒకవేళ (n <= 4) {
        అయితే (n)
            o(0xa548), --n;
    } లేకపోతే {
        vpushi(n);
        gv(RC_RCX);
        o(0xa548f3);
        vpop();
    }
    ఒకవేళ (కొలత & 0x04)
        o(0xa5);
    ఒకవేళ (కొలత & 0x02)
        o(0xa566);
    ఒకవేళ (కొలత & 0x01)
        o(0xa4);
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    o(0x5e5f); /* pop rdi, rsi */
#అయితే_ముగింపు
    vpop();
    vpop();
}

/* end of x86-64 code generator */
/*************************************************************/
#అయితే_ముగింపు /* ! TARGET_DEFS_ONLY */
/******************************************************/
