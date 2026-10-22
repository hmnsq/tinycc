/*
 *  ARMv4 code generator for TCC
 *
 *  Copyright (c) 2003 Daniel Glöckner
 *  Copyright (c) 2012 Thomas Preud'homme
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

#যদি defined(TCC_ARM_EABI) && !defined(TCC_ARM_VFP)
#error "Currently TinyCC only supports float computation with VFP instructions"
#endif

/* number of available registers */
#ifdef TCC_ARM_VFP
#define NB_REGS            13
#অন্যথা
#define NB_REGS             9
#endif

#ifndef CONFIG_TCC_CPUVER
# define CONFIG_TCC_CPUVER 5
#endif

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#define RC_INT     0x0001 /* generic integer register */
#define RC_FLOAT   0x0002 /* generic float register */
#define RC_R0      0x0004
#define RC_R1      0x0008
#define RC_R2      0x0010
#define RC_R3      0x0020
#define RC_R12     0x0040
#define RC_F0      0x0080
#define RC_F1      0x0100
#define RC_F2      0x0200
#define RC_F3      0x0400
#ifdef TCC_ARM_VFP
#define RC_F4      0x0800
#define RC_F5      0x1000
#define RC_F6      0x2000
#define RC_F7      0x4000
#endif
#define RC_IRET    RC_R0  /* function return: integer register */
#define RC_IRE2    RC_R1  /* function return: second integer register */
#define RC_FRET    RC_F0  /* function return: float register */

/* pretty names for the registers */
গণনা {
    TREG_R0 = 0,
    TREG_R1,
    TREG_R2,
    TREG_R3,
    TREG_R12,
    TREG_F0,
    TREG_F1,
    TREG_F2,
    TREG_F3,
#ifdef TCC_ARM_VFP
    TREG_F4,
    TREG_F5,
    TREG_F6,
    TREG_F7,
#endif
    TREG_SP = 13,
    TREG_LR,
};

#ifdef TCC_ARM_VFP
#define T2CPR(t) (((t) & VT_BTYPE) != VT_FLOAT ? 0x100 : 0)
#endif

/* return registers for function */
#define REG_IRET TREG_R0 /* single word int return register */
#define REG_IRE2 TREG_R1 /* second word return register (for long long) */
#define REG_FRET TREG_F0 /* float return register */

#ifdef TCC_ARM_EABI
#define TOK___divdi3 TOK___aeabi_ldivmod
#define TOK___moddi3 TOK___aeabi_ldivmod
#define TOK___udivdi3 TOK___aeabi_uldivmod
#define TOK___umoddi3 TOK___aeabi_uldivmod
#endif

/* defined if function parameters must be evaluated in reverse order */
#define INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#define PTR_আকার 4

/* long double size and alignment, in bytes */
#ifdef TCC_ARM_VFP
#define LDOUBLE_আকার  8
#endif

#ifndef LDOUBLE_আকার
#define LDOUBLE_আকার  8
#endif

#ifdef TCC_ARM_EABI
#define LDOUBLE_ALIGN 8
#অন্যথা
#define LDOUBLE_ALIGN 4
#endif

#যদি LDOUBLE_আকার == 8
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#endif

/* maximum alignment (for aligned attribute support) */
#define MAX_ALIGN     8

#define CHAR_IS_UNSIGNED

#define ARM_SOFTFP_FLOAT 0
#define ARM_HARD_FLOAT 1

/******************************************************/
#অন্যথা /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#অন্তর্ভাব "tcc.h"

ST_তথ্য ধ্রুবক অক্ষর * ধ্রুবক target_machine_defs =
    "__arm__\0"
    "__arm\0"
    "arm\0"
    "__arm_elf__\0"
    "__arm_elf\0"
    "arm_elf\0"
    "__ARM_ARCH_4__\0"
    "__ARMEL__\0"
    "__APCS_32__\0"
#যদি defined TCC_ARM_EABI
    "__ARM_EABI__\0"
#endif
    ;

ST_তথ্য ধ্রুবক পূর্ণসংখ্যা reg_classes[NB_REGS] = {
    /* r0 */ RC_INT | RC_R0,
    /* r1 */ RC_INT | RC_R1,
    /* r2 */ RC_INT | RC_R2,
    /* r3 */ RC_INT | RC_R3,
    /* r12 */ RC_INT | RC_R12,
    /* f0 */ RC_FLOAT | RC_F0,
    /* f1 */ RC_FLOAT | RC_F1,
    /* f2 */ RC_FLOAT | RC_F2,
    /* f3 */ RC_FLOAT | RC_F3,
#ifdef TCC_ARM_VFP
 /* d4/s8 */ RC_FLOAT | RC_F4,
/* d5/s10 */ RC_FLOAT | RC_F5,
/* d6/s12 */ RC_FLOAT | RC_F6,
/* d7/s14 */ RC_FLOAT | RC_F7,
#endif
};

স্থির পূর্ণসংখ্যা float_abi;
স্থির পূর্ণসংখ্যা func_sub_sp_offset, last_itod_magic;
স্থির পূর্ণসংখ্যা leaffunc;

#যদি defined(CONFIG_TCC_BCHECK)
স্থির addr_t func_bound_offset;
স্থির unsigned long func_bound_ind;
ST_তথ্য পূর্ণসংখ্যা func_bound_add_epilog;
#endif

#যদি defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
স্থির CType float_type, double_type, func_float_type, func_double_type;
ST_FUNC শূন্য arm_init(কাঠামো TCCState *s)
{
    float_type.t = VT_FLOAT;
    double_type.t = VT_DOUBLE;
    func_float_type.t = VT_FUNC;
    func_float_type.ref = sym_ঠেলো(SYM_FIELD, &float_type, FUNC_CDECL, FUNC_OLD);
    func_double_type.t = VT_FUNC;
    func_double_type.ref = sym_ঠেলো(SYM_FIELD, &double_type, FUNC_CDECL, FUNC_OLD);

    float_abi = s->float_abi;
#ifndef TCC_ARM_HARDFLOAT
// XXX: Works on OpenBSD
// # warning "soft float ABI currently not supported: default to softfp"
#endif
}
#অন্যথা
#define func_float_type func_old_type
#define func_double_type func_old_type
#define func_ldouble_type func_old_type
ST_FUNC শূন্য arm_init(কাঠামো TCCState *s)
{
#যদি 0
#যদি !defined (TCC_ARM_VFP)
    tcc_warning("Support for FPA is deprecated and will be removed in next"
                " release");
#endif
#যদি !defined (TCC_ARM_EABI)
    tcc_warning("Support for OABI is deprecated and will be removed in next"
                " release");
#endif
#endif
}
#endif

#define CHECK_R(r) ((r) >= TREG_R0 && (r) <= TREG_LR)

স্থির পূর্ণসংখ্যা two2mask(পূর্ণসংখ্যা a,পূর্ণসংখ্যা b) {
  যদি (!CHECK_R(a) || !CHECK_R(b))
    tcc_error("compiler error! registers %i,%i is not valid",a,b);
  ফেরত (reg_classes[a]|reg_classes[b])&~(RC_INT|RC_FLOAT);
}

স্থির পূর্ণসংখ্যা regmask(পূর্ণসংখ্যা r) {
  যদি (!CHECK_R(r))
    tcc_error("compiler error! register %i is not valid",r);
  ফেরত reg_classes[r]&~(RC_INT|RC_FLOAT);
}

/******************************************************/

শূন্য o(uint32_t i)
{
  /* this is a good place to start adding big-endian support*/
  পূর্ণসংখ্যা ind1;
  যদি (nocode_wanted)
    ফেরত;
  ind1 = ind + 4;
  যদি (!cur_text_section)
    tcc_error("compiler error! This happens f.ex. if the compiler\n"
         "can't evaluate constant expressions outside of a function.");
  যদি (ind1 > cur_text_section->তথ্য_allocated)
    section_realloc(cur_text_section, ind1);
  cur_text_section->তথ্য[ind++] = i&255;
  i>>=8;
  cur_text_section->তথ্য[ind++] = i&255;
  i>>=8;
  cur_text_section->তথ্য[ind++] = i&255;
  i>>=8;
  cur_text_section->তথ্য[ind++] = i;
}

স্থির uint32_t stuff_const(uint32_t op, uint32_t c)
{
  পূর্ণসংখ্যা try_neg=0;
  uint32_t nc = 0, negop = 0;

  নির্বাচন(op&0x1F00000)
  {
    ক্ষেত্র 0x800000: //add
    ক্ষেত্র 0x400000: //sub
      try_neg=1;
      negop=op^0xC00000;
      nc=-c;
      বিরতি;
    ক্ষেত্র 0x1A00000: //mov
    ক্ষেত্র 0x1E00000: //mvn
      try_neg=1;
      negop=op^0x400000;
      nc=~c;
      বিরতি;
    ক্ষেত্র 0x200000: //xor
      যদি(c==~0)
	ফেরত (op&0xF010F000)|((op>>16)&0xF)|0x1E00000;
      বিরতি;
    ক্ষেত্র 0x0: //and
      যদি(c==~0)
	ফেরত (op&0xF010F000)|((op>>16)&0xF)|0x1A00000;
    ক্ষেত্র 0x1C00000: //bic
      try_neg=1;
      negop=op^0x1C00000;
      nc=~c;
      বিরতি;
    ক্ষেত্র 0x1800000: //orr
      যদি(c==~0)
	ফেরত (op&0xFFF0FFFF)|0x1E00000;
      বিরতি;
  }
  করো {
    uint32_t m;
    পূর্ণসংখ্যা i;
    যদি(c<256) /* catch undefined <<32 */
      ফেরত op|c;
    জন্য(i=2;i<32;i+=2) {
      m=(0xffu>>i)|(0xffu<<(32-i));
      যদি(!(c&~m))
	ফেরত op|(i<<7)|(c<<i)|(c>>(32-i));
    }
    op=negop;
    c=nc;
  } যখন(try_neg--);
  ফেরত 0;
}


//only add,sub
শূন্য stuff_const_harder(uint32_t op, uint32_t v) {
  uint32_t x;
  x=stuff_const(op,v);
  যদি(x)
    o(x);
  অন্যথা {
    uint32_t a[16], nv, no, o2, n2;
    পূর্ণসংখ্যা i,j,k;
    a[0]=0xff;
    o2=(op&0xfff0ffff)|((op&0xf000)<<4);;
    জন্য(i=1;i<16;i++)
      a[i]=(a[i-1]>>2)|(a[i-1]<<30);
    জন্য(i=0;i<12;i++)
      জন্য(j=i<4?i+12:15;j>=i+4;j--)
	যদি((v&(a[i]|a[j]))==v) {
	  o(stuff_const(op,v&a[i]));
	  o(stuff_const(o2,v&a[j]));
	  ফেরত;
	}
    no=op^0xC00000;
    n2=o2^0xC00000;
    nv=-v;
    জন্য(i=0;i<12;i++)
      জন্য(j=i<4?i+12:15;j>=i+4;j--)
	যদি((nv&(a[i]|a[j]))==nv) {
	  o(stuff_const(no,nv&a[i]));
	  o(stuff_const(n2,nv&a[j]));
	  ফেরত;
	}
    জন্য(i=0;i<8;i++)
      জন্য(j=i+4;j<12;j++)
	জন্য(k=i<4?i+12:15;k>=j+4;k--)
	  যদি((v&(a[i]|a[j]|a[k]))==v) {
	    o(stuff_const(op,v&a[i]));
	    o(stuff_const(o2,v&a[j]));
	    o(stuff_const(o2,v&a[k]));
	    ফেরত;
	  }
    no=op^0xC00000;
    nv=-v;
    জন্য(i=0;i<8;i++)
      জন্য(j=i+4;j<12;j++)
	জন্য(k=i<4?i+12:15;k>=j+4;k--)
	  যদি((nv&(a[i]|a[j]|a[k]))==nv) {
	    o(stuff_const(no,nv&a[i]));
	    o(stuff_const(n2,nv&a[j]));
	    o(stuff_const(n2,nv&a[k]));
	    ফেরত;
	  }
    o(stuff_const(op,v&a[0]));
    o(stuff_const(o2,v&a[4]));
    o(stuff_const(o2,v&a[8]));
    o(stuff_const(o2,v&a[12]));
  }
}

uint32_t encbranch(পূর্ণসংখ্যা pos, পূর্ণসংখ্যা addr, পূর্ণসংখ্যা fail)
{
  addr-=pos+8;
  addr/=4;
  যদি(addr>=0x1000000 || addr<-0x1000000) {
    যদি(fail)
      tcc_error("FIXME: function bigger than 32MB");
    ফেরত 0;
  }
  ফেরত 0x0A000000|(addr&0xffffff);
}

পূর্ণসংখ্যা decbranch(পূর্ণসংখ্যা pos)
{
  পূর্ণসংখ্যা x;
  x=*(uint32_t *)(cur_text_section->তথ্য + pos);
  x&=0x00ffffff;
  যদি(x&0x800000)
    x-=0x1000000;
  ফেরত x*4+pos+8;
}

/* output a symbol and patch all calls to it */
শূন্য gsym_addr(পূর্ণসংখ্যা t, পূর্ণসংখ্যা a)
{
  uint32_t *x;
  পূর্ণসংখ্যা lt;
  যখন(t) {
    x=(uint32_t *)(cur_text_section->তথ্য + t);
    t=decbranch(lt=t);
    যদি(a==lt+4)
      *x=0xE1A00000; // nop
    অন্যথা {
      *x &= 0xff000000;
      *x |= encbranch(lt,a,1);
    }
  }
}

#ifdef TCC_ARM_VFP
স্থির uint32_t vfpr(পূর্ণসংখ্যা r)
{
  যদি(r<TREG_F0 || r>TREG_F7)
    tcc_error("compiler error! register %i is no vfp register",r);
  ফেরত r - TREG_F0;
}
#অন্যথা
স্থির uint32_t fpr(পূর্ণসংখ্যা r)
{
  যদি(r<TREG_F0 || r>TREG_F3)
    tcc_error("compiler error! register %i is no fpa register",r);
  ফেরত r - TREG_F0;
}
#endif

স্থির uint32_t intr(পূর্ণসংখ্যা r)
{
  যদি(r == TREG_R12)
    ফেরত 12;
  যদি(r >= TREG_R0 && r <= TREG_R3)
    ফেরত r - TREG_R0;
  যদি (!(r >= TREG_SP && r <= TREG_LR))
    tcc_error("compiler error! register %i is no int register",r);
  ফেরত r + (13 - TREG_SP);
}

স্থির শূন্য calcaddr(uint32_t *base, পূর্ণসংখ্যা *off, পূর্ণসংখ্যা *sgn, পূর্ণসংখ্যা maxoff, unsigned shift)
{
  যদি(*off>maxoff || *off&((1<<shift)-1)) {
    uint32_t x, y;
    x=0xE280E000;
    যদি(*sgn)
      x=0xE240E000;
    x|=(*base)<<16;
    *base=14; // lr
    y=stuff_const(x,*off&~maxoff);
    যদি(y) {
      o(y);
      *off&=maxoff;
      ফেরত;
    }
    y=stuff_const(x,(*off+maxoff)&~maxoff);
    যদি(y) {
      o(y);
      *sgn=!*sgn;
      *off=((*off+maxoff)&~maxoff)-*off;
      ফেরত;
    }
    stuff_const_harder(x,*off&~maxoff);
    *off&=maxoff;
  }
}

স্থির uint32_t mapcc(পূর্ণসংখ্যা cc)
{
  নির্বাচন(cc)
  {
    ক্ষেত্র TOK_ULT:
      ফেরত 0x30000000; /* CC/LO */
    ক্ষেত্র TOK_UGE:
      ফেরত 0x20000000; /* CS/HS */
    ক্ষেত্র TOK_EQ:
      ফেরত 0x00000000; /* EQ */
    ক্ষেত্র TOK_NE:
      ফেরত 0x10000000; /* NE */
    ক্ষেত্র TOK_ULE:
      ফেরত 0x90000000; /* LS */
    ক্ষেত্র TOK_UGT:
      ফেরত 0x80000000; /* HI */
    ক্ষেত্র TOK_Nset:
      ফেরত 0x40000000; /* MI */
    ক্ষেত্র TOK_Nclear:
      ফেরত 0x50000000; /* PL */
    ক্ষেত্র TOK_LT:
      ফেরত 0xB0000000; /* LT */
    ক্ষেত্র TOK_GE:
      ফেরত 0xA0000000; /* GE */
    ক্ষেত্র TOK_LE:
      ফেরত 0xD0000000; /* LE */
    ক্ষেত্র TOK_GT:
      ফেরত 0xC0000000; /* GT */
  }
  tcc_error("unexpected condition code");
  ফেরত 0xE0000000; /* AL */
}

স্থির পূর্ণসংখ্যা negcc(পূর্ণসংখ্যা cc)
{
  নির্বাচন(cc)
  {
    ক্ষেত্র TOK_ULT:
      ফেরত TOK_UGE;
    ক্ষেত্র TOK_UGE:
      ফেরত TOK_ULT;
    ক্ষেত্র TOK_EQ:
      ফেরত TOK_NE;
    ক্ষেত্র TOK_NE:
      ফেরত TOK_EQ;
    ক্ষেত্র TOK_ULE:
      ফেরত TOK_UGT;
    ক্ষেত্র TOK_UGT:
      ফেরত TOK_ULE;
    ক্ষেত্র TOK_Nset:
      ফেরত TOK_Nclear;
    ক্ষেত্র TOK_Nclear:
      ফেরত TOK_Nset;
    ক্ষেত্র TOK_LT:
      ফেরত TOK_GE;
    ক্ষেত্র TOK_GE:
      ফেরত TOK_LT;
    ক্ষেত্র TOK_LE:
      ফেরত TOK_GT;
    ক্ষেত্র TOK_GT:
      ফেরত TOK_LE;
  }
  tcc_error("unexpected condition code");
  ফেরত TOK_NE;
}

/* Load value into register r.
   Use relative/got addressing to avoid setting DT_TEXTREL */
স্থির শূন্য load_মান(SValue *sv, পূর্ণসংখ্যা r)
{
#যদি CONFIG_TCC_CPUVER >= 7
    যদি (!(sv->r & VT_SYM)) {
        unsigned x=sv->c.i;
        o(0xE3000000|intr(r)<<12|(x&0xFFF)|(x<<4&0xF0000)); /* movw rx,#x(lo) */
        যদি (x&0xFFFF0000)
          o(0xE3400000|intr(r)<<12|(x>>16&0xFFF)|(x>>12&0xF0000)); /* movt rx,#x(hi) */
        ফেরত;
    }
#endif
    o(0xE59F0000|(intr(r)<<12)); /* ldr r, [pc] */
    o(0xEA000000); /* b $+4 */
#ifndef CONFIG_TCC_PIC
    যদি(sv->r & VT_SYM)
        greloc(cur_text_section, sv->sym, ind, R_ARM_ABS32);
    o(sv->c.i);
#অন্যথা
    যদি(sv->r & VT_SYM) {
	যদি (sv->sym->type.t & VT_STATIC) {
            greloc(cur_text_section, sv->sym, ind, R_ARM_REL32);
            o(sv->c.i - 12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
        }
        অন্যথা {
            greloc(cur_text_section, sv->sym, ind, R_ARM_GOT_PREL);
            o(-12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
            o(0xe5900000 | (intr(r)<<12) | (intr(r)<<16));  // ldr rx,[rx]
            যদি (sv->c.i)
              stuff_const_harder(0xe2800000 | (intr(r)<<12) | (intr(r)<<16),
                                 sv->c.i);
        }
    }
    অন্যথা
        o(sv->c.i);
#endif
}

/* load 'r' from value 'sv' */
শূন্য load(পূর্ণসংখ্যা r, SValue *sv)
{
  পূর্ণসংখ্যা v, ft, fc, fr, sign;
  uint32_t op, base;
  SValue v1;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  যদি(fc>=0)
    sign=0;
  অন্যথা {
    sign=1;
    fc=-(unsigned)fc;
  }

  v = fr & VT_VALMASK;
  যদি (fr & VT_LVAL) {

    যদি ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe510e000; /* ldr r, [lr, #0] */
        greloca(cur_text_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        ফেরত;
    }

    base = 0xB; // fp
    যদি(v == VT_LLOCAL) {
      v1.type.t = VT_PTR;
      v1.r = VT_LOCAL | VT_LVAL;
      v1.c.i = sv->c.i;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } অন্যথা যদি(v == VT_CONST) {
      v1.type.t = VT_PTR;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } অন্যথা যদি(v < VT_CONST) {
      base=intr(v);
      fc=sign=0;
      v=VT_LOCAL;
    }
    যদি(v == VT_LOCAL) {
      যদি(is_float(ft)) {
	calcaddr(&base,&fc,&sign,1020,2);
#ifdef TCC_ARM_VFP
        op=0xED100A00; /* flds */
        যদি(!sign)
          op|=0x800000;
        যদি ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* flds -> fldd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(base<<16));
#অন্যথা
	op=0xED100100;
	যদি(!sign)
	  op|=0x800000;
	যদি ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#যদি LDOUBLE_আকার != 8
	অন্যথা যদি ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#endif
	o(op|(fpr(r)<<12)|(fc>>2)|(base<<16));
#endif
      } অন্যথা যদি((ft & (VT_BTYPE|VT_UNSIGNED)) == VT_BYTE
                || (ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&base,&fc,&sign,255,0);
	op=0xE1500090;
	যদি ((ft & VT_BTYPE) == VT_SHORT)
	  op|=0x20;
	যদি ((ft & VT_UNSIGNED) == 0)
	  op|=0x40;
	যদি(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(base<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } অন্যথা {
	calcaddr(&base,&fc,&sign,4095,0);
	op=0xE5100000;
	যদি(!sign)
	  op|=0x800000;
        যদি ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(base<<16));
      }
      ফেরত;
    }
  } অন্যথা {
    যদি (v == VT_CONST) {
      op=stuff_const(0xE3A00000|(intr(r)<<12),sv->c.i);
      যদি (fr & VT_SYM || !op)
	load_মান(sv, r);
      অন্যথা
        o(op);
      ফেরত;
    } অন্যথা যদি (v == VT_LOCAL) {
      op=stuff_const(0xE28B0000|(intr(r)<<12),sv->c.i);
      যদি (fr & VT_SYM || !op) {
	load_মান(sv, r);
	o(0xE08B0000|(intr(r)<<12)|intr(r));
      } অন্যথা
	o(op);
      ফেরত;
    } অন্যথা যদি(v == VT_CMP) {
      o(mapcc(sv->c.i)|0x3A00001|(intr(r)<<12));
      o(mapcc(negcc(sv->c.i))|0x3A00000|(intr(r)<<12));
      ফেরত;
    } অন্যথা যদি (v == VT_JMP || v == VT_JMPI) {
      পূর্ণসংখ্যা t;
      t = v & 1;
      o(0xE3A00000|(intr(r)<<12)|t);
      o(0xEA000000);
      gsym(sv->c.i);
      o(0xE3A00000|(intr(r)<<12)|(t^1));
      ফেরত;
    } অন্যথা যদি (v < VT_CONST) {
      যদি(is_float(ft))
#ifdef TCC_ARM_VFP
        o(0xEEB00A40|(vfpr(r)<<12)|vfpr(v)|T2CPR(ft)); /* fcpyX */
#অন্যথা
	o(0xEE008180|(fpr(r)<<12)|fpr(v));
#endif
      অন্যথা
	o(0xE1A00000|(intr(r)<<12)|intr(v));
      ফেরত;
    }
  }
  tcc_error("load unimplemented!");
}

/* store register 'r' in lvalue 'v' */
শূন্য store(পূর্ণসংখ্যা r, SValue *sv)
{
  SValue v1;
  পূর্ণসংখ্যা v, ft, fc, fr, sign;
  uint32_t op, base;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  যদি(fc>=0)
    sign=0;
  অন্যথা {
    sign=1;
    fc=-fc;
  }

  v = fr & VT_VALMASK;
  যদি (fr & VT_LVAL || fr == VT_LOCAL) {

    যদি ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe500e000; /* str r, [lr, #0] */
        greloca(cur_text_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        ফেরত;
    }

    base = 0xb; /* fp */
    যদি(v < VT_CONST) {
      base=intr(v);
      v=VT_LOCAL;
      fc=sign=0;
    } অন্যথা যদি(v == VT_CONST) {
      v1.type.t = ft;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    }
    যদি(v == VT_LOCAL) {
       যদি(is_float(ft)) {
	calcaddr(&base,&fc,&sign,1020,2);
#ifdef TCC_ARM_VFP
        op=0xED000A00; /* fsts */
        যদি(!sign)
          op|=0x800000;
        যদি ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* fsts -> fstd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(base<<16));
#অন্যথা
	op=0xED000100;
	যদি(!sign)
	  op|=0x800000;
	যদি ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#যদি LDOUBLE_আকার != 8
	অন্যথা যদি ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#endif
	o(op|(fpr(r)<<12)|(fc>>2)|(base<<16));
#endif
	ফেরত;
      } অন্যথা যদি((ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&base,&fc,&sign,255,0);
	op=0xE14000B0;
	যদি(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(base<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } অন্যথা {
	calcaddr(&base,&fc,&sign,4095,0);
	op=0xE5000000;
	যদি(!sign)
	  op|=0x800000;
        যদি ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(base<<16));
      }
      ফেরত;
    }
  }
  tcc_error("store unimplemented");
}

স্থির শূন্য gadd_sp(পূর্ণসংখ্যা val)
{
  stuff_const_harder(0xE28DD000,val);
}

/* 'is_jmp' is '1' if it is a jump */
স্থির শূন্য gcall_or_jmp(পূর্ণসংখ্যা is_jmp)
{
  পূর্ণসংখ্যা r;
  uint32_t x;
  যদি ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
    /* constant case */
    যদি(vtop->r & VT_SYM){
	x=encbranch(ind,ind+vtop->c.i,0);
	যদি(x) {
	    /* relocation case */
	    greloc(cur_text_section, vtop->sym, ind, R_ARM_PC24);
	    o(x|(is_jmp?0xE0000000:0xE1000000));
	} অন্যথা {
	    r = TREG_LR;
	    load_মান(vtop, r);
	    যদি(is_jmp)
	        o(0xE1A0F000 | intr(r)); // mov pc, r
	    অন্যথা
		o(0xe12fff30 | intr(r)); // blx r
	}
     }অন্যথা{
	যদি(!is_jmp)
	    o(0xE28FE004); // add lr,pc,#4
	o(0xE51FF004);   // ldr pc,[pc,#-4]
	o(vtop->c.i);
     }
  } অন্যথা {
    /* otherwise, indirect call */
#ifdef CONFIG_TCC_BCHECK
    vtop->r &= ~VT_MUSTBOUND;
#endif
    r = gv(RC_INT);
    যদি(!is_jmp)
      o(0xE1A0E00F);       // mov lr,pc
    o(0xE1A0F000|intr(r)); // mov pc,r
  }
}

#যদি defined(CONFIG_TCC_BCHECK)

স্থির শূন্য gen_bounds_call(পূর্ণসংখ্যা v)
{
    Sym *sym = external_helper_sym(v);

    greloc(cur_text_section, sym, ind, R_ARM_PC24);
    o(0xebfffffe);
}

স্থির শূন্য gen_bounds_prolog(শূন্য)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->তথ্য_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0xe1a00000);  /* ld r0,lbounds_section->data_offset */
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);  /* call __bound_local_new */
}

স্থির শূন্য gen_bounds_epilog(শূন্য)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_তথ্য;
    পূর্ণসংখ্যা offset_modified = func_bound_offset != lbounds_section->তথ্য_offset;

    যদি (!offset_modified && !func_bound_add_epilog)
        ফেরত;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, আকার(addr_t));
    *bounds_ptr = 0;

    sym_তথ্য = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_আকার);

    /* generate bound local allocation */
    যদি (offset_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        o(0xe59f0000);  /* ldr r0, [pc] */
        o(0xea000000);  /* b $+4 */
        greloc(cur_text_section, sym_তথ্য, ind, R_ARM_REL32);
        o(-12);  /* lbounds_section->data_offset */
	o(0xe080000f);  /* add r0,r0,pc */
        gen_bounds_call(TOK___bound_local_new);
        ind = saved_ind;
    }

    /* generate bound check local freeing */
    o(0xe92d0003);  /* push {r0,r1} */
    o(0xed2d0b04);  /* vpush {d0,d1} */
    o(0xe59f0000);  /* ldr r0, [pc] */
    o(0xea000000);  /* b $+4 */
    greloc(cur_text_section, sym_তথ্য, ind, R_ARM_REL32);
    o(-12);  /* lbounds_section->data_offset */
    o(0xe080000f);  /* add r0,r0,pc */
    gen_bounds_call(TOK___bound_local_delete);
    o(0xecbd0b04); /* vpop {d0,d1} */
    o(0xe8bd0003); /* pop {r0,r1} */
}
#endif

/* Return whether a structure is an homogeneous float aggregate or not.
   The answer is true if all the elements of the structure are of the same
   primitive float type and there is less than 4 elements.

   type: the type corresponding to the structure to be tested */
স্থির পূর্ণসংখ্যা is_hgen_float_aggr(CType *type)
{
  যদি ((type->t & VT_BTYPE) == VT_STRUCT) {
    কাঠামো Sym *ref;
    পূর্ণসংখ্যা btype, nb_fields = 0;

    ref = type->ref->পরবর্তী;
    যদি (ref) {
      btype = ref->type.t & VT_BTYPE;
      যদি (btype == VT_FLOAT || btype == VT_DOUBLE) {
        জন্য(; ref && btype == (ref->type.t & VT_BTYPE); ref = ref->পরবর্তী, nb_fields++)
            ;
        ফেরত !ref && nb_fields <= 4;
      }
    }
  }
  ফেরত 0;
}

কাঠামো avail_regs {
  signed অক্ষর avail[3]; /* 3 holes max with only float and double alignments */
  পূর্ণসংখ্যা first_hole; /* first available hole */
  পূর্ণসংখ্যা last_hole; /* last available hole (none if equal to first_hole) */
  পূর্ণসংখ্যা first_free_reg; /* next free register in the sequence, hole excluded */
};

/* Find suitable registers for a VFP Co-Processor Register Candidate (VFP CPRC
   param) according to the rules described in the procedure call standard for
   the ARM architecture (AAPCS). If found, the registers are assigned to this
   VFP CPRC parameter. Registers are allocated in sequence unless a hole exists
   and the parameter is a single float.

   avregs: opaque structure to keep track of available VFP co-processor regs
   align: alignment constraints for the param, as returned by type_size()
   size: size of the parameter, as returned by type_size() */
পূর্ণসংখ্যা assign_vfpreg(কাঠামো avail_regs *avregs, পূর্ণসংখ্যা align, পূর্ণসংখ্যা আকার_2)
{
  পূর্ণসংখ্যা first_reg = 0;

  যদি (avregs->first_free_reg == -1)
    ফেরত -1;
  যদি (align >> 3) { /* double alignment */
    first_reg = avregs->first_free_reg;
    /* alignment constraint not respected so use next reg and record hole */
    যদি (first_reg & 1)
      avregs->avail[avregs->last_hole++] = first_reg++;
  } অন্যথা { /* no special alignment (float or array of float) */
    /* if single float and a hole is available, assign the param to it */
    যদি (আকার_2 == 4 && avregs->first_hole != avregs->last_hole)
      ফেরত avregs->avail[avregs->first_hole++];
    অন্যথা
      first_reg = avregs->first_free_reg;
  }
  যদি (first_reg + আকার_2 / 4 <= 16) {
    avregs->first_free_reg = first_reg + আকার_2 / 4;
    ফেরত first_reg;
  }
  avregs->first_free_reg = -1;
  ফেরত -1;
}

/* Returns whether all params need to be passed in core registers or not.
   This is the case for function part of the runtime ABI. */
পূর্ণসংখ্যা floats_in_core_regs(SValue *sval)
{
  যদি (!sval->sym)
    ফেরত 0;

  নির্বাচন (sval->sym->v) {
    ক্ষেত্র TOK___floatundisf:
    ক্ষেত্র TOK___floatundidf:
    ক্ষেত্র TOK___fixunssfdi:
    ক্ষেত্র TOK___fixunsdfdi:
#ifndef TCC_ARM_VFP
    ক্ষেত্র TOK___fixunsxfdi:
#endif
    ক্ষেত্র TOK___floatdisf:
    ক্ষেত্র TOK___floatdidf:
    ক্ষেত্র TOK___fixsfdi:
    ক্ষেত্র TOK___fixdfdi:
      ফেরত 1;

    পূর্বনির্ধারিত:
      ফেরত 0;
  }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC পূর্ণসংখ্যা gfunc_sret(CType *vt, পূর্ণসংখ্যা variadic, CType *ret, পূর্ণসংখ্যা *ret_align, পূর্ণসংখ্যা *regsize) {
#ifdef TCC_ARM_EABI
    পূর্ণসংখ্যা আকার_2, align;
    আকার_2 = type_আকার(vt, &align);
    যদি (float_abi == ARM_HARD_FLOAT && !variadic &&
        (is_float(vt->t) || is_hgen_float_aggr(vt))) {
        *ret_align = 8;
	*regsize = 8;
        ret->ref = ফাঁকা;
        ret->t = VT_DOUBLE;
        ফেরত (আকার_2 + 7) >> 3;
    } অন্যথা যদি (আকার_2 > 0 && আকার_2 <= 4) {
        *ret_align = 4;
	*regsize = 4;
        ret->ref = ফাঁকা;
        ret->t = VT_INT;
        ফেরত 1;
    } অন্যথা
        ফেরত 0;
#অন্যথা
    ফেরত 0;
#endif
}

/* Parameters are classified according to how they are copied to their final
   destination for the function call. Because the copying is performed class
   after class according to the order in the union below, it is important that
   some constraints about the order of the members of this union are respected:
   - CORE_STRUCT_CLASS must come after STACK_CLASS;
   - CORE_CLASS must come after STACK_CLASS, CORE_STRUCT_CLASS and
     VFP_STRUCT_CLASS;
   - VFP_STRUCT_CLASS must come after VFP_CLASS.
   See the comment for the main loop in copy_params() for the reason. */
গণনা reg_class {
	স্তূপ_CLASS = 0,
	CORE_STRUCT_CLASS,
	VFP_CLASS,
	VFP_STRUCT_CLASS,
	CORE_CLASS,
	NB_CLASSES
};

কাঠামো param_plan {
    পূর্ণসংখ্যা start; /* first reg or addr used depending on the class */
    পূর্ণসংখ্যা end; /* last reg used or next free addr depending on the class */
    SValue *sval; /* pointer to SValue on the value stack */
    কাঠামো param_plan *পূর্ব; /*  previous element in this class */
};

কাঠামো plan {
    কাঠামো param_plan *pplans; /* array of all the param plans */
    কাঠামো param_plan *clsplans[NB_CLASSES]; /* per class lists of param plans */
    পূর্ণসংখ্যা nb_plans;
};

স্থির শূন্য add_param_plan(কাঠামো plan* plan, পূর্ণসংখ্যা cls, পূর্ণসংখ্যা start, পূর্ণসংখ্যা end, SValue *v)
{
    কাঠামো param_plan *p = &plan->pplans[plan->nb_plans++];
    p->পূর্ব = plan->clsplans[cls];
    plan->clsplans[cls] = p;
    p->start = start, p->end = end, p->sval = v;
}

/* Assign parameters to registers and stack with alignment according to the
   rules in the procedure call standard for the ARM architecture (AAPCS).
   The overall assignment is recorded in an array of per parameter structures
   called parameter plans. The parameter plans are also further organized in a
   number of linked lists, one per class of parameter (see the comment for the
   definition of union reg_class).

   nb_args: number of parameters of the function for which a call is generated
   float_abi: float ABI in use for this function call
   plan: the structure where the overall assignment is recorded
   todo: a bitmap that record which core registers hold a parameter

   Returns the amount of stack space needed for parameter passing

   Note: this function allocated an array in plan->pplans with tcc_malloc. It
   is the responsibility of the caller to free this array once used (ie not
   before copy_params). */
স্থির পূর্ণসংখ্যা assign_regs(পূর্ণসংখ্যা nb_args, পূর্ণসংখ্যা float_abi, কাঠামো plan *plan, পূর্ণসংখ্যা *todo)
{
  পূর্ণসংখ্যা i, আকার_2, align;
  পূর্ণসংখ্যা ncrn /* next core register number */, nsaa /* next stacked argument address*/;
  কাঠামো avail_regs avregs = {{0}};

  ncrn = nsaa = 0;
  *todo = 0;

  জন্য(i = nb_args; i-- ;) {
    পূর্ণসংখ্যা j, start_vfpreg = 0;
    CType type = vtop[-i].type;
    type.t &= ~VT_ARRAY;
    আকার_2 = type_আকার(&type, &align);
    আকার_2 = (আকার_2 + 3) & ~3;
    align = (align + 3) & ~3;
    নির্বাচন(vtop[-i].type.t & VT_BTYPE) {
      ক্ষেত্র VT_STRUCT:
      ক্ষেত্র VT_FLOAT:
      ক্ষেত্র VT_DOUBLE:
      ক্ষেত্র VT_LDOUBLE:
      যদি (float_abi == ARM_HARD_FLOAT) {
        পূর্ণসংখ্যা is_hfa = 0; /* Homogeneous float aggregate */

        যদি (is_float(vtop[-i].type.t)
            || (is_hfa = is_hgen_float_aggr(&vtop[-i].type))) {
          পূর্ণসংখ্যা end_vfpreg;

          start_vfpreg = assign_vfpreg(&avregs, align, আকার_2);
          end_vfpreg = start_vfpreg + ((আকার_2 - 1) >> 2);
          যদি (start_vfpreg >= 0) {
            add_param_plan(plan, is_hfa ? VFP_STRUCT_CLASS : VFP_CLASS,
                start_vfpreg, end_vfpreg, &vtop[-i]);
            চালু;
          } অন্যথা
            বিরতি;
        }
      }
      ncrn = (ncrn + (align-1)/4) & ~((align/4) - 1);
      যদি (ncrn + আকার_2/4 <= 4 || (ncrn < 4 && start_vfpreg != -1)) {
        /* The parameter is allocated both in core register and on stack. As
	 * such, it can be of either class: it would either be the last of
	 * CORE_STRUCT_CLASS or the first of STACK_CLASS. */
        জন্য (j = ncrn; j < 4 && j < ncrn + আকার_2 / 4; j++)
          *todo|=(1<<j);
        add_param_plan(plan, CORE_STRUCT_CLASS, ncrn, j, &vtop[-i]);
        ncrn += আকার_2/4;
        যদি (ncrn > 4)
          nsaa = (ncrn - 4) * 4;
      } অন্যথা {
        ncrn = 4;
        বিরতি;
      }
      চালু;
      পূর্বনির্ধারিত:
      যদি (ncrn < 4) {
        পূর্ণসংখ্যা is_long = (vtop[-i].type.t & VT_BTYPE) == VT_LLONG;

        যদি (is_long) {
          ncrn = (ncrn + 1) & -2;
          যদি (ncrn == 4)
            বিরতি;
        }
        add_param_plan(plan, CORE_CLASS, ncrn, ncrn + is_long, &vtop[-i]);
        ncrn += 1 + is_long;
        চালু;
      }
    }
    nsaa = (nsaa + (align - 1)) & ~(align - 1);
    add_param_plan(plan, স্তূপ_CLASS, nsaa, nsaa + আকার_2, &vtop[-i]);
    nsaa += আকার_2; /* size already rounded up before */
  }
  ফেরত nsaa;
}

/* Copy parameters to their final destination (core reg, VFP reg or stack) for
   function call.

   nb_args: number of parameters the function take
   plan: the overall assignment plan for parameters
   todo: a bitmap indicating what core reg will hold a parameter

   Returns the number of SValue added by this function on the value stack */
স্থির পূর্ণসংখ্যা copy_params(পূর্ণসংখ্যা nb_args, কাঠামো plan *plan, পূর্ণসংখ্যা todo)
{
  পূর্ণসংখ্যা আকার_2, align, r, i, nb_extra_sval = 0;
  কাঠামো param_plan *pplan;
  পূর্ণসংখ্যা pass = 0;

   /* Several constraints require parameters to be copied in a specific order:
      - structures are copied to the stack before being loaded in a reg;
      - floats loaded to an odd numbered VFP reg are first copied to the
        preceding even numbered VFP reg and then moved to the next VFP reg.

      It is thus important that:
      - structures assigned to core regs must be copied after parameters
        assigned to the stack but before structures assigned to VFP regs because
        a structure can lie partly in core registers and partly on the stack;
      - parameters assigned to the stack and all structures be copied before
        parameters assigned to a core reg since copying a parameter to the stack
        require using a core reg;
      - parameters assigned to VFP regs be copied before structures assigned to
        VFP regs as the copy might use an even numbered VFP reg that already
        holds part of a structure. */
again:
  জন্য(i = 0; i < NB_CLASSES; i++) {
    জন্য(pplan = plan->clsplans[i]; pplan; pplan = pplan->পূর্ব) {

      যদি (pass
          && (i != CORE_CLASS || pplan->sval->r < VT_CONST))
        চালু;

      vpushv(pplan->sval);
      pplan->sval->r = pplan->sval->r2 = VT_CONST; /* disable entry */
      নির্বাচন(i) {
        ক্ষেত্র স্তূপ_CLASS:
        ক্ষেত্র CORE_STRUCT_CLASS:
        ক্ষেত্র VFP_STRUCT_CLASS:
          যদি ((pplan->sval->type.t & VT_BTYPE) == VT_STRUCT) {
            পূর্ণসংখ্যা padding = 0;
            আকার_2 = type_আকার(&pplan->sval->type, &align);
            /* align to stack align size */
            আকার_2 = (আকার_2 + 3) & ~3;
            যদি (i == স্তূপ_CLASS && pplan->পূর্ব)
              padding = pplan->start - pplan->পূর্ব->end;
            আকার_2 += padding; /* Add padding if any */
            /* allocate the necessary size on stack */
            gadd_sp(-আকার_2);
            /* generate structure store */
            r = get_reg(RC_INT);
            o(0xE28D0000|(intr(r)<<12)|padding); /* add r, sp, padding */
            vset(&vtop->type, r | VT_LVAL, 0);
            vswap();
	    /* XXX: optimize. Save all register because memcpy can use them */
	    o(0xED2D0A00|(0&1)<<22|(0>>1)<<12|16); /* vpush {s0-s15} */
            vstore(); /* memcpy to current sp + potential padding */
	    o(0xECBD0A00|(0&1)<<22|(0>>1)<<12|16); /* vpop {s0-s15} */

            /* Homogeneous float aggregate are loaded to VFP registers
               immediately since there is no way of loading data in multiple
               non consecutive VFP registers as what is done for other
               structures (see the use of todo). */
            যদি (i == VFP_STRUCT_CLASS) {
              পূর্ণসংখ্যা first = pplan->start, nb = pplan->end - first + 1;
              /* vpop.32 {pplan->start, ..., pplan->end} */
              o(0xECBD0A00|(first&1)<<22|(first>>1)<<12|nb);
              /* No need to write the register used to a SValue since VFP regs
                 cannot be used for gcall_or_jmp */
            }
          } অন্যথা {
            যদি (is_float(pplan->sval->type.t)) {
#ifdef TCC_ARM_VFP
              r = vfpr(gv(RC_FLOAT)) << 12;
              যদি ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                আকার_2 = 4;
              অন্যথা {
                আকার_2 = 8;
                r |= 0x101; /* vpush.32 -> vpush.64 */
              }
              o(0xED2D0A01 + r); /* vpush */
#অন্যথা
              r = fpr(gv(RC_FLOAT)) << 12;
              যদি ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                আকার_2 = 4;
              অন্যথা যদি ((pplan->sval->type.t & VT_BTYPE) == VT_DOUBLE)
                আকার_2 = 8;
              অন্যথা
                আকার_2 = LDOUBLE_আকার;
              যদি (আকার_2 == 12)
                r |= 0x400000;
              অন্যথা যদি(আকার_2 == 8)
                r|=0x8000;

              o(0xED2D0100|r|(আকার_2>>2)); /* some kind of vpush for FPA */
#endif
            } অন্যথা {
              /* simple type (currently always same size) */
              /* XXX: implicit cast ? */
              আকার_2=4;
              যদি ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
                lexpand();
                আকার_2 = 8;
                r = gv(RC_INT);
                o(0xE52D0004|(intr(r)<<12)); /* push r */
                vtop--;
              }
              r = gv(RC_INT);
              o(0xE52D0004|(intr(r)<<12)); /* push r */
            }
            যদি (i == স্তূপ_CLASS && pplan->পূর্ব)
              gadd_sp(pplan->পূর্ব->end - pplan->start); /* Add padding if any */
          }
          বিরতি;

        ক্ষেত্র VFP_CLASS:
          gv(regmask(TREG_F0 + (pplan->start >> 1)));
          যদি (pplan->start & 1) { /* Must be in upper part of double register */
            o(0xEEF00A40|((pplan->start>>1)<<12)|(pplan->start>>1)); /* vmov.f32 s(n+1), sn */
            vtop->r = VT_CONST; /* avoid being saved on stack by gv for next float */
          }
          বিরতি;

        ক্ষেত্র CORE_CLASS:
          যদি ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
            lexpand();
            gv(regmask(pplan->end));
            pplan->sval->r2 = vtop->r;
            vtop--;
          }
          gv(regmask(pplan->start));
          /* Mark register as used so that gcall_or_jmp use another one
             (regs >=4 are free as never used to pass parameters) */
          pplan->sval->r = vtop->r;
          বিরতি;
      }
      vtop--;
    }
  }

  /* second pass to restore registers that were saved on stack by accident.
     Maybe redundant after the "lvalue_save" patch in tccgen.c:gv() */
  যদি (++pass < 2)
    যাও again;

  যদি(todo) {
    o(0xE8BD0000|todo); /* pop {todo} */
    জন্য(pplan = plan->clsplans[CORE_STRUCT_CLASS]; pplan; pplan = pplan->পূর্ব) {
      পূর্ণসংখ্যা r;
      pplan->sval->r = pplan->start;
      /* An SValue can only pin 2 registers at best (r and r2) but a structure
         can occupy more than 2 registers. Thus, we need to push on the value
         stack some fake parameter to have on SValue for each registers used
         by a structure (r2 is not used). */
      জন্য (r = pplan->start + 1; r <= pplan->end; r++) {
        যদি (todo & (1 << r)) {
          nb_extra_sval++;
          vpushi(0);
          vtop->r = r;
        }
      }
    }
  }
  ফেরত nb_extra_sval;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
শূন্য gfunc_call(পূর্ণসংখ্যা nb_args)
{
  পূর্ণসংখ্যা args_আকার;
  পূর্ণসংখ্যা def_float_abi = float_abi;
  পূর্ণসংখ্যা todo;
  কাঠামো plan plan;
#ifdef TCC_ARM_EABI
  পূর্ণসংখ্যা variadic;
#endif

#ifdef CONFIG_TCC_BCHECK
  যদি (tcc_state->do_bounds_check)
    gbound_args(nb_args);
#endif

  save_regs(nb_args + 1);

#ifdef TCC_ARM_EABI
  যদি (float_abi == ARM_HARD_FLOAT) {
    variadic = (vtop[-nb_args].type.ref->f.func_type == FUNC_ELLIPSIS);
    যদি (variadic || floats_in_core_regs(&vtop[-nb_args]))
      float_abi = ARM_SOFTFP_FLOAT;
  }
#endif

  memset(&plan, 0, আকার plan);
  যদি (nb_args)
    plan.pplans = tcc_malloc(nb_args * আকার(*plan.pplans));

  args_আকার = assign_regs(nb_args, float_abi, &plan, &todo);

#ifdef TCC_ARM_EABI
  যদি (args_আকার & 7) { /* Stack must be 8 byte aligned at fct call for EABI */
    args_আকার = (args_আকার + 7) & ~7;
    o(0xE24DD004); /* sub sp, sp, #4 */
  }
#endif

  nb_args += copy_params(nb_args, &plan, todo);
  tcc_free(plan.pplans);

  /* Move fct SValue on top as required by gcall_or_jmp */
  vrotb(nb_args + 1);
  gcall_or_jmp(0);
  যদি (args_আকার)
      gadd_sp(args_আকার); /* pop all parameters passed on the stack */
#যদি defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  যদি(float_abi == ARM_SOFTFP_FLOAT && is_float(vtop->type.ref->type.t)) {
    যদি((vtop->type.ref->type.t & VT_BTYPE) == VT_FLOAT) {
      o(0xEE000A10); /*vmov s0, r0 */
    } অন্যথা {
      o(0xEE000B10); /* vmov.32 d0[0], r0 */
      o(0xEE201B10); /* vmov.32 d0[1], r1 */
    }
  }
#endif
  vtop -= nb_args + 1; /* Pop all params and fct address from value stack */
  leaffunc = 0; /* we are calling a function, so we aren't in a leaf function */
  float_abi = def_float_abi;
}

/* generate function prolog of type 't' */
শূন্য gfunc_prolog(Sym *func_sym)
{
  CType *func_type = &func_sym->type;
  Sym *sym,*sym2;
  পূর্ণসংখ্যা n, nf, আকার_2, align, rs, struct_ret = 0;
  পূর্ণসংখ্যা addr, pn, sn; /* pn=core, sn=stack */
  CType ret_type;

#ifdef TCC_ARM_EABI
  কাঠামো avail_regs avregs = {{0}};
#endif

  sym = func_type->ref;

  n = nf = 0;
  যদি ((func_vt.t & VT_BTYPE) == VT_STRUCT &&
      !gfunc_sret(&func_vt, func_var, &ret_type, &align, &rs))
  {
    n++;
    struct_ret = 1;
    func_vc = 12; /* Offset from fp of the place to store the result */
  }
  জন্য(sym2 = sym->পরবর্তী; sym2 && (n < 4 || nf < 16); sym2 = sym2->পরবর্তী) {
    আকার_2 = type_আকার(&sym2->type, &align);
#ifdef TCC_ARM_EABI
    যদি (float_abi == ARM_HARD_FLOAT && !func_var &&
        (is_float(sym2->type.t) || is_hgen_float_aggr(&sym2->type))) {
      পূর্ণসংখ্যা tmpnf = assign_vfpreg(&avregs, align, আকার_2);
      tmpnf += (আকার_2 + 3) / 4;
      nf = (tmpnf > nf) ? tmpnf : nf;
    } অন্যথা
#endif
    যদি (n < 4)
      n += (আকার_2 + 3) / 4;
  }
  o(0xE1A0C00D); /* mov ip,sp */
  যদি (func_var)
    n=4;
  যদি (n) {
    যদি(n>4)
      n=4;
#ifdef TCC_ARM_EABI
    n=(n+1)&-2;
#endif
    o(0xE92D0000|((1<<n)-1)); /* save r0-r4 on stack if needed */
  }
  যদি (nf) {
    যদি (nf>16)
      nf=16;
    nf=(nf+1)&-2; /* nf => HARDFLOAT => EABI */
    o(0xED2D0A00|nf); /* save s0-s15 on stack if needed */
  }
  o(0xE92D5800); /* save fp, ip, lr */
  o(0xE1A0B00D); /* mov fp, sp */
  func_sub_sp_offset = ind;
  o(0xE1A00000); /* nop, leave space for stack adjustment in epilog */

#ifdef TCC_ARM_EABI
  যদি (float_abi == ARM_HARD_FLOAT) {
    func_vc += nf * 4;
    memset(&avregs, 0, আকার avregs);
  }
#endif
  pn = struct_ret, sn = 0;
  যখন ((sym = sym->পরবর্তী)) {
    CType *type;
    type = &sym->type;
    আকার_2 = type_আকার(type, &align);
    আকার_2 = (আকার_2 + 3) >> 2;
    align = (align + 3) & ~3;
#ifdef TCC_ARM_EABI
    যদি (float_abi == ARM_HARD_FLOAT && !func_var && (is_float(sym->type.t)
        || is_hgen_float_aggr(&sym->type))) {
      পূর্ণসংখ্যা fpn = assign_vfpreg(&avregs, align, আকার_2 << 2);
      যদি (fpn >= 0)
        addr = fpn * 4;
      অন্যথা
        যাও from_স্তূপ;
    } অন্যথা
#endif
    যদি (pn < 4) {
#ifdef TCC_ARM_EABI
        pn = (pn + (align-1)/4) & -(align/4);
#endif
      addr = (nf + pn) * 4;
      pn += আকার_2;
      যদি (!sn && pn > 4)
        sn = (pn - 4);
    } অন্যথা {
#ifdef TCC_ARM_EABI
from_স্তূপ:
        sn = (sn + (align-1)/4) & -(align/4);
#endif
      addr = (n + nf + sn) * 4;
      sn += আকার_2;
    }
    gfunc_set_param(sym, addr + 12, 0);
  }
  last_itod_magic=0;
  leaffunc = 1;
  loc = 0;
#ifdef CONFIG_TCC_BCHECK
  যদি (tcc_state->do_bounds_check)
    gen_bounds_prolog();
#endif
}

/* generate function epilog */
শূন্য gfunc_epilog(শূন্য)
{
  uint32_t x;
  পূর্ণসংখ্যা diff;

#ifdef CONFIG_TCC_BCHECK
  যদি (tcc_state->do_bounds_check)
    gen_bounds_epilog();
#endif
  /* Copy float return value to core register if base standard is used and
     float computation is made with VFP */
#যদি defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  যদি ((float_abi == ARM_SOFTFP_FLOAT || func_var) && is_float(func_vt.t)) {
    যদি((func_vt.t & VT_BTYPE) == VT_FLOAT)
      o(0xEE100A10); /* fmrs r0, s0 */
    অন্যথা {
      o(0xEE100B10); /* fmrdl r0, d0 */
      o(0xEE301B10); /* fmrdh r1, d0 */
    }
  }
#endif
  o(0xE89BA800); /* restore fp, sp, pc */
  diff = (-loc + 3) & -4;
#ifdef TCC_ARM_EABI
  যদি(!leaffunc)
    diff = ((diff + 11) & -8) - 4;
#endif
  যদি(diff > 0) {
    x=stuff_const(0xE24BD000, diff); /* sub sp,fp,# */
    যদি(x)
      *(uint32_t *)(cur_text_section->তথ্য + func_sub_sp_offset) = x;
    অন্যথা {
      পূর্ণসংখ্যা addr;
      addr=ind;
      o(0xE59FC004); /* ldr ip,[pc+4] */
      o(0xE04BD00C); /* sub sp,fp,ip  */
      o(0xE1A0F00E); /* mov pc,lr */
      o(diff);
      *(uint32_t *)(cur_text_section->তথ্য + func_sub_sp_offset) = 0xE1000000|encbranch(func_sub_sp_offset,addr,1);
    }
  }
}

ST_FUNC শূন্য gen_fill_nops(পূর্ণসংখ্যা bytes)
{
    যদি ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    যখন (bytes > 0) {
	o(0xE1A00000);
	bytes -= 4;
    }
}

/* generate a jump to a label */
ST_FUNC পূর্ণসংখ্যা gjmp(পূর্ণসংখ্যা t)
{
  পূর্ণসংখ্যা r;
  যদি (nocode_wanted)
    ফেরত t;
  r=ind;
  o(0xE0000000|encbranch(r,t,1));
  ফেরত r;
}

/* generate a jump to a fixed address */
ST_FUNC শূন্য gjmp_addr(পূর্ণসংখ্যা a)
{
  gjmp(a);
}

ST_FUNC পূর্ণসংখ্যা gjmp_cond(পূর্ণসংখ্যা op, পূর্ণসংখ্যা t)
{
  পূর্ণসংখ্যা r;
  যদি (nocode_wanted)
    ফেরত t;
  r=ind;
  op=mapcc(op);
  op|=encbranch(r,t,1);
  o(op);
  ফেরত r;
}

ST_FUNC পূর্ণসংখ্যা gjmp_append(পূর্ণসংখ্যা n, পূর্ণসংখ্যা t)
{
  uint32_t *x;
  পূর্ণসংখ্যা p,lp;
  যদি(n) {
    p = n;
    করো {
      p = decbranch(lp=p);
    } যখন(p);
    x = (uint32_t *)(cur_text_section->তথ্য + lp);
    *x &= 0xff000000;
    *x |= encbranch(lp,t,1);
    t = n;
  }
  ফেরত t;
}

/* generate an integer binary operation */
শূন্য gen_opi(পূর্ণসংখ্যা op)
{
  পূর্ণসংখ্যা c, func = 0;
  uint32_t opc = 0, r, fr;
  unsigned short retreg = REG_IRET;

  c=0;
  নির্বাচন(op) {
    ক্ষেত্র '+':
      opc = 0x8;
      c=1;
      বিরতি;
    ক্ষেত্র TOK_ADDC1: /* add with carry generation */
      opc = 0x9;
      c=1;
      বিরতি;
    ক্ষেত্র '-':
      opc = 0x4;
      c=1;
      বিরতি;
    ক্ষেত্র TOK_SUBC1: /* sub with carry generation */
      opc = 0x5;
      c=1;
      বিরতি;
    ক্ষেত্র TOK_ADDC2: /* add with carry use */
      opc = 0xA;
      c=1;
      বিরতি;
    ক্ষেত্র TOK_SUBC2: /* sub with carry use */
      opc = 0xC;
      c=1;
      বিরতি;
    ক্ষেত্র '&':
      opc = 0x0;
      c=1;
      বিরতি;
    ক্ষেত্র '^':
      opc = 0x2;
      c=1;
      বিরতি;
    ক্ষেত্র '|':
      opc = 0x18;
      c=1;
      বিরতি;
    ক্ষেত্র '*':
      gv2(RC_INT, RC_INT);
      r = vtop[-1].r;
      fr = vtop[0].r;
      vtop--;
      o(0xE0000090|(intr(r)<<16)|(intr(r)<<8)|intr(fr));
      ফেরত;
    ক্ষেত্র TOK_SHL:
      opc = 0;
      c=2;
      বিরতি;
    ক্ষেত্র TOK_SHR:
      opc = 1;
      c=2;
      বিরতি;
    ক্ষেত্র TOK_SAR:
      opc = 2;
      c=2;
      বিরতি;
    ক্ষেত্র '/':
    ক্ষেত্র TOK_PDIV:
      func=TOK___divsi3;
      c=3;
      বিরতি;
    ক্ষেত্র TOK_UDIV:
      func=TOK___udivsi3;
      c=3;
      বিরতি;
    ক্ষেত্র '%':
#ifdef TCC_ARM_EABI
      func=TOK___aeabi_idivmod;
      retreg=REG_IRE2;
#অন্যথা
      func=TOK___modsi3;
#endif
      c=3;
      বিরতি;
    ক্ষেত্র TOK_UMOD:
#ifdef TCC_ARM_EABI
      func=TOK___aeabi_uidivmod;
      retreg=REG_IRE2;
#অন্যথা
      func=TOK___umodsi3;
#endif
      c=3;
      বিরতি;
    ক্ষেত্র TOK_UMULL:
      gv2(RC_INT, RC_INT);
      r=intr(vtop[-1].r2=get_reg(RC_INT));
      c=vtop[-1].r;
      vtop[-1].r=get_reg_ex(RC_INT,regmask(c));
      vtop--;
      o(0xE0800090|(r<<16)|(intr(vtop->r)<<12)|(intr(c)<<8)|intr(vtop[1].r));
      ফেরত;
    পূর্বনির্ধারিত:
      opc = 0x15;
      c=1;
      বিরতি;
  }
  নির্বাচন(c) {
    ক্ষেত্র 1:
      যদি((vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	যদি(opc == 4 || opc == 5 || opc == 0xc) {
	  vswap();
	  opc|=2; // sub -> rsb
	}
      }
      vswap();
      c=intr(gv(RC_INT));
      vswap();
      opc=0xE0000000|(opc<<20);
      যদি((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	uint32_t x;
	x=stuff_const(opc|0x2000000|(c<<16),vtop->c.i);
	যদি(x) {
	  যদি ((x & 0xfff00000) == 0xe3500000)   // cmp rx,#c
	    o(x);
	  অন্যথা {
	    r=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	    o(x|(r<<12));
	  }
	  যাও done;
	}
      }
      fr=intr(gv(RC_INT));
#ifdef CONFIG_TCC_BCHECK
      যদি ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
        vswap();
        c=intr(gv(RC_INT));
        vswap();
      }
#endif
      যদি ((opc & 0xfff00000) == 0xe1500000) // cmp rx,ry
	o(opc|(c<<16)|fr);
      অন্যথা {
        r=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
        o(opc|(c<<16)|(r<<12)|fr);
      }
done:
      vtop--;
      যদি (op >= TOK_ULT && op <= TOK_GT)
        vset_VT_CMP(op);
      বিরতি;
    ক্ষেত্র 2:
      opc=0xE1A00000|(opc<<5);
      vswap();
      r=intr(gv(RC_INT));
      vswap();
      যদি ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	fr=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	c = vtop->c.i & 0x1f;
	o(opc|r|(c<<7)|(fr<<12));
      } অন্যথা {
        fr=intr(gv(RC_INT));
#ifdef CONFIG_TCC_BCHECK
        যদি ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=intr(gv(RC_INT));
          vswap();
        }
#endif
	c=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
	o(opc|r|(c<<12)|(fr<<8)|0x10);
      }
      vtop--;
      বিরতি;
    ক্ষেত্র 3:
      vpush_helper_func(func);
      vrott(3);
      gfunc_call(2);
      vpushi(0);
      vtop->r = retreg;
      বিরতি;
    পূর্বনির্ধারিত:
      tcc_error("gen_opi %i unimplemented!",op);
  }
}

#ifdef TCC_ARM_VFP
স্থির পূর্ণসংখ্যা is_zero(পূর্ণসংখ্যা i)
{
  যদি((vtop[i].r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    ফেরত 0;
  যদি (vtop[i].type.t == VT_FLOAT)
    ফেরত (vtop[i].c.f == 0.f);
  অন্যথা যদি (vtop[i].type.t == VT_DOUBLE)
    ফেরত (vtop[i].c.d == 0.0);
  ফেরত (vtop[i].c.ld == 0.l);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
 *    two operands are guaranteed to have the same floating point type */
শূন্য gen_opf(পূর্ণসংখ্যা op)
{
  uint32_t x;
  পূর্ণসংখ্যা fneg=0,r;
  x=0xEE000A00|T2CPR(vtop->type.t);
  নির্বাচন(op) {
    ক্ষেত্র '+':
      যদি(is_zero(-1))
        vswap();
      যদি(is_zero(0)) {
        vtop--;
        ফেরত;
      }
      x|=0x300000;
      বিরতি;
    ক্ষেত্র '-':
      x|=0x300040;
      যদি(is_zero(0)) {
        vtop--;
        ফেরত;
      }
      যদি(is_zero(-1)) {
        x|=0x810000; /* fsubX -> fnegX */
        vswap();
        vtop--;
        fneg=1;
      }
      বিরতি;
    ক্ষেত্র '*':
      x|=0x200000;
      বিরতি;
    ক্ষেত্র '/':
      x|=0x800000;
      বিরতি;
    পূর্বনির্ধারিত:
      যদি(op < TOK_ULT || op > TOK_GT) {
        tcc_error("unknown fp op %x!",op);
        ফেরত;
      }
      যদি(is_zero(-1)) {
        vswap();
        নির্বাচন(op) {
          ক্ষেত্র TOK_LT: op=TOK_GT; বিরতি;
          ক্ষেত্র TOK_GE: op=TOK_ULE; বিরতি;
          ক্ষেত্র TOK_LE: op=TOK_GE; বিরতি;
          ক্ষেত্র TOK_GT: op=TOK_ULT; বিরতি;
        }
      }
      x|=0xB40040; /* fcmpX */
      যদি(op!=TOK_EQ && op!=TOK_NE)
        x|=0x80; /* fcmpX -> fcmpeX */
      যদি(is_zero(0)) {
        vtop--;
        o(x|0x10000|(vfpr(gv(RC_FLOAT))<<12)); /* fcmp(e)X -> fcmp(e)zX */
      } অন্যথা {
        gv2(RC_FLOAT,RC_FLOAT);
        x|=vfpr(vtop[0].r);
        o(x|(vfpr(vtop[-1].r) << 12));
        vtop--;
      }
      o(0xEEF1FA10); /* fmstat */

      নির্বাচন(op) {
        ক্ষেত্র TOK_LE: op=TOK_ULE; বিরতি;
        ক্ষেত্র TOK_LT: op=TOK_ULT; বিরতি;
        ক্ষেত্র TOK_UGE: op=TOK_GE; বিরতি;
        ক্ষেত্র TOK_UGT: op=TOK_GT; বিরতি;
      }
      vset_VT_CMP(op);
      ফেরত;
  }
  r=gv(RC_FLOAT);
  x|=vfpr(r);
  r=regmask(r);
  যদি(!fneg) {
    পূর্ণসংখ্যা r2;
    vswap();
    r2=gv(RC_FLOAT);
    x|=vfpr(r2)<<16;
    r|=regmask(r2);
#ifdef CONFIG_TCC_BCHECK
    যদি ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
      vswap();
      r=gv(RC_FLOAT);
      vswap();
      x=(x&~0xf)|vfpr(r);
    }
#endif
  }
  vtop->r=get_reg_ex(RC_FLOAT,r);
  যদি(!fneg)
    vtop--;
  o(x|(vfpr(vtop->r)<<12));
}

#অন্যথা
স্থির uint32_t is_fconst()
{
  long দ্বিগুণ f;
  uint32_t r;
  যদি((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    ফেরত 0;
  যদি (vtop->type.t == VT_FLOAT)
    f = vtop->c.f;
  অন্যথা যদি (vtop->type.t == VT_DOUBLE)
    f = vtop->c.d;
  অন্যথা
    f = vtop->c.ld;
  যদি(!ieee_finite(f))
    ফেরত 0;
  r=0x8;
  যদি(f<0.0) {
    r=0x18;
    f=-f;
  }
  যদি(f==0.0)
    ফেরত r;
  যদি(f==1.0)
    ফেরত r|1;
  যদি(f==2.0)
    ফেরত r|2;
  যদি(f==3.0)
    ফেরত r|3;
  যদি(f==4.0)
    ফেরত r|4;
  যদি(f==5.0)
    ফেরত r|5;
  যদি(f==0.5)
    ফেরত r|6;
  যদি(f==10.0)
    ফেরত r|7;
  ফেরত 0;
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
শূন্য gen_opf(পূর্ণসংখ্যা op)
{
  uint32_t x, r, r2, c1, c2;
  //fputs("gen_opf\n",stderr);
  vswap();
  c1 = is_fconst();
  vswap();
  c2 = is_fconst();
  x=0xEE000100;
  যদি ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
    x|=0x80;
#যদি LDOUBLE_আকার != 8
  অন্যথা যদি ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE)
    x|=0x80000;
#endif

  নির্বাচন(op)
  {
    ক্ষেত্র '+':
      যদি(!c2) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      যদি(c2) {
	যদি(c2>0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
      } অন্যথা {
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        যদি ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      বিরতি;
    ক্ষেত্র '-':
      যদি(c2) {
	যদি(c2<=0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } অন্যথা যদি(c1 && c1<=0xf) {
	x|=0x300000; // rsf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } অন্যথা {
	x|=0x200000; // suf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        যদি ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      বিরতি;
    ক্ষেত্র '*':
      যদি(!c2 || c2>0xf) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      যদি(c2 && c2<=0xf)
	r2=c2;
      অন্যথা {
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        যদি ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      x|=0x100000; // muf
      বিরতি;
    ক্ষেত্র '/':
      যদি(c2 && c2<=0xf) {
	x|=0x400000; // dvf
	r2=c2;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } অন্যথা যদি(c1 && c1<=0xf) {
	x|=0x500000; // rdf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } অন্যথা {
	x|=0x400000; // dvf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        যদি ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      বিরতি;
    পূর্বনির্ধারিত:
      যদি(op >= TOK_ULT && op <= TOK_GT) {
	x|=0xd0f110; // cmfe
/* bug (intention?) in Linux FPU emulator
   doesn't set carry if equal */
	নির্বাচন(op) {
	  ক্ষেত্র TOK_ULT:
	  ক্ষেত্র TOK_UGE:
	  ক্ষেত্র TOK_ULE:
	  ক্ষেত্র TOK_UGT:
            tcc_error("unsigned comparison on floats?");
	    বিরতি;
	  ক্ষেত্র TOK_LT:
            op=TOK_Nset;
	    বিরতি;
	  ক্ষেত্র TOK_LE:
            op=TOK_ULE; /* correct in unordered case only if AC bit in FPSR set */
	    বিরতি;
	  ক্ষেত্র TOK_EQ:
	  ক্ষেত্র TOK_NE:
	    x&=~0x400000; // cmfe -> cmf
	    বিরতি;
	}
	যদি(c1 && !c2) {
	  c2=c1;
	  vswap();
	  নির্বাচন(op) {
            ক্ষেত্র TOK_Nset:
              op=TOK_GT;
	      বিরতি;
            ক্ষেত্র TOK_GE:
	      op=TOK_ULE;
	      বিরতি;
	    ক্ষেত্র TOK_ULE:
              op=TOK_GE;
	      বিরতি;
            ক্ষেত্র TOK_GT:
              op=TOK_Nset;
	      বিরতি;
	  }
	}
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	যদি(c2) {
	  যদি(c2>0xf)
	    x|=0x200000;
	  r2=c2&0xf;
	} অন্যথা {
	  r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
          যদি ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            r=fpr(gv(RC_FLOAT));
            vswap();
          }
#endif
	}
        --vtop;
        vset_VT_CMP(op);
        ++vtop;
      } অন্যথা {
        tcc_error("unknown fp op %x!",op);
	ফেরত;
      }
  }
  যদি(vtop[-1].r == VT_CMP)
    c1=15;
  অন্যথা {
    c1=vtop->r;
    যদি(r2&0x8)
      c1=vtop[-1].r;
    vtop[-1].r=get_reg_ex(RC_FLOAT,two2mask(vtop[-1].r,c1));
    c1=fpr(vtop[-1].r);
  }
  vtop--;
  o(x|(r<<16)|(c1<<12)|r2);
}
#endif

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ST_FUNC শূন্য gen_cvt_itof(পূর্ণসংখ্যা t)
{
  uint32_t r, r2;
  পূর্ণসংখ্যা bt;
  bt=vtop->type.t & VT_BTYPE;
  যদি(bt == VT_INT || bt == VT_SHORT || bt == VT_BYTE) {
#ifndef TCC_ARM_VFP
    uint32_t dsize = 0;
#endif
    r=intr(gv(RC_INT));
#ifdef TCC_ARM_VFP
    r2=vfpr(vtop->r=get_reg(RC_FLOAT));
    o(0xEE000A10|(r<<12)|(r2<<16)); /* fmsr */
    r2|=r2<<12;
    যদি(!(vtop->type.t & VT_UNSIGNED))
      r2|=0x80;                /* fuitoX -> fsituX */
    o(0xEEB80A40|r2|T2CPR(t)); /* fYitoX*/
#অন্যথা
    r2=fpr(vtop->r=get_reg(RC_FLOAT));
    যদি((t & VT_BTYPE) != VT_FLOAT)
      dsize=0x80;    /* flts -> fltd */
    o(0xEE000110|dsize|(r2<<16)|(r<<12)); /* flts */
    যদি((vtop->type.t & (VT_UNSIGNED|VT_BTYPE)) == (VT_UNSIGNED|VT_INT)) {
      uint32_t off = 0;
      o(0xE3500000|(r<<12));        /* cmp */
      r=fpr(get_reg(RC_FLOAT));
      যদি(last_itod_magic) {
	off=ind+8-last_itod_magic;
	off/=4;
	যদি(off>255)
	  off=0;
      }
      o(0xBD1F0100|(r<<12)|off);    /* ldflts */
      যদি(!off) {
        o(0xEA000000);              /* b */
        last_itod_magic=ind;
        o(0x4F800000);              /* 4294967296.0f */
      }
      o(0xBE000100|dsize|(r2<<16)|(r2<<12)|r); /* adflt */
    }
#endif
    ফেরত;
  } অন্যথা যদি(bt == VT_LLONG) {
    পূর্ণসংখ্যা func;
    CType *func_type = 0;
    যদি((t & VT_BTYPE) == VT_FLOAT) {
      func_type = &func_float_type;
      যদি(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundisf;
      অন্যথা
        func=TOK___floatdisf;
    } অন্যথা যদি((t & VT_BTYPE) == VT_DOUBLE) {
      func_type = &func_double_type;
      যদি(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundidf;
      অন্যথা
        func=TOK___floatdidf;
#যদি LDOUBLE_আকার != 8
    } অন্যথা যদি((t & VT_BTYPE) == VT_LDOUBLE) {
      func_type = &func_ldouble_type;
      যদি(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundixf;
      অন্যথা
        func=TOK___floatdixf;
#endif
    }
    যদি(func_type) {
      vpushsym(func_type, external_helper_sym(func));
      vswap();
      gfunc_call(1);
      vpushi(0);
      vtop->r=TREG_F0;
      ফেরত;
    }
  }
  tcc_error("unimplemented gen_cvt_itof %x!",vtop->type.t);
}

/* convert fp to int 't' type */
শূন্য gen_cvt_ftoi(পূর্ণসংখ্যা t)
{
  uint32_t r, r2;
  পূর্ণসংখ্যা u, func = 0;
  u=t&VT_UNSIGNED;
  t&=VT_BTYPE;
  r2=vtop->type.t & VT_BTYPE;
  যদি(t==VT_INT) {
#ifdef TCC_ARM_VFP
    r=vfpr(gv(RC_FLOAT));
    u=u?0:0x10000;
    o(0xEEBC0AC0|(r<<12)|r|T2CPR(r2)|u); /* ftoXizY */
    r2=intr(vtop->r=get_reg(RC_INT));
    o(0xEE100A10|(r<<16)|(r2<<12));
    ফেরত;
#অন্যথা
    যদি(u) {
      যদি(r2 == VT_FLOAT)
        func=TOK___fixunssfsi;
      অন্যথা যদি(r2 == VT_DOUBLE)
	func=TOK___fixunsdfsi;
#যদি LDOUBLE_আকার != 8
      অন্যথা যদি(r2 == VT_LDOUBLE)
	func=TOK___fixunsxfsi;
#endif
    } অন্যথা {
      r=fpr(gv(RC_FLOAT));
      r2=intr(vtop->r=get_reg(RC_INT));
      o(0xEE100170|(r2<<12)|r);
      ফেরত;
    }
#endif
  } অন্যথা যদি(t == VT_LLONG) { // unsigned handled in gen_cvt_ftoi1
    যদি(r2 == VT_FLOAT)
      func=TOK___fixsfdi;
    অন্যথা যদি(r2 == VT_DOUBLE)
      func=TOK___fixdfdi;
#যদি LDOUBLE_আকার != 8
    অন্যথা যদি(r2 == VT_LDOUBLE)
      func=TOK___fixxfdi;
#endif
  }
  যদি(func) {
    vpush_helper_func(func);
    vswap();
    gfunc_call(1);
    vpushi(0);
    যদি(t == VT_LLONG)
      vtop->r2 = REG_IRE2;
    vtop->r = REG_IRET;
    ফেরত;
  }
  tcc_error("unimplemented gen_cvt_ftoi!");
}

/* convert from one floating point type to another */
শূন্য gen_cvt_ftof(পূর্ণসংখ্যা t)
{
#ifdef TCC_ARM_VFP
  uint32_t r = gv(RC_FLOAT);
  যদি(((vtop->type.t & VT_BTYPE) == VT_FLOAT) != ((t & VT_BTYPE) == VT_FLOAT)) {
    r = vfpr(r);
    o(0xEEB70AC0|(r<<12)|r|T2CPR(vtop->type.t));
  }
#অন্যথা
  /* all we have to do on i386 and FPA ARM is to put the float in a register */
  gv(RC_FLOAT);
#endif
}

/* increment tcov counter */
ST_FUNC শূন্য gen_increment_tcov (SValue *sv)
{
  পূর্ণসংখ্যা r1, r2;

  vpushv(sv);
  vtop->r = r1 = get_reg(RC_INT);
  r2 = get_reg(RC_INT);
  o(0xE59F0000 | (intr(r1)<<12)); // ldr r1,[pc]
  o(0xEA000000); // b $+4
  greloc(cur_text_section, sv->sym, ind, R_ARM_REL32);
  o(-12);
  o(0xe080000f | (intr(r1)<<16) | (intr(r1)<<12)); // add r1,r1,pc
  o(0xe5900000 | (intr(r1)<<16) | (intr(r2)<<12)); // ldr r2, [r1]
  o(0xe2900001 | (intr(r2)<<16) | (intr(r2)<<12)); // adds r2, r2, #1
  o(0xe5800000 | (intr(r1)<<16) | (intr(r2)<<12)); // str r2, [r1]
  o(0xe2800004 | (intr(r1)<<16) | (intr(r1)<<12)); // add r1, r1, #4
  o(0xe5900000 | (intr(r1)<<16) | (intr(r2)<<12)); // ldr r2, [r1]
  o(0xe2a00000 | (intr(r2)<<16) | (intr(r2)<<12)); // adc r2, r2, #0
  o(0xe5800000 | (intr(r1)<<16) | (intr(r2)<<12)); // str r2, [r1]
  vpop();
}

/* computed goto support */
শূন্য ggoto(শূন্য)
{
  gcall_or_jmp(1);
  vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC শূন্য gen_vla_sp_save(পূর্ণসংখ্যা addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    store(TREG_SP, &v);
}

/* Restore the SP from a location on the stack */
ST_FUNC শূন্য gen_vla_sp_restore(পূর্ণসংখ্যা addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    load(TREG_SP, &v);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC শূন্য gen_vla_alloc(CType *type, পূর্ণসংখ্যা align) {
    পূর্ণসংখ্যা r;
#যদি defined(CONFIG_TCC_BCHECK)
    যদি (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    r = intr(gv(RC_INT));
#যদি defined(CONFIG_TCC_BCHECK)
    যদি (tcc_state->do_bounds_check)
        o(0xe2800001 | (r<<16)|(r<<12)); /* add r,r,#1 */
#endif
    o(0xE04D0000|(r<<12)|r); /* sub r, sp, r */
#ifdef TCC_ARM_EABI
    যদি (align < 8)
        align = 8;
#অন্যথা
    যদি (align < 4)
        align = 4;
#endif
    যদি (align & (align - 1))
        tcc_error("alignment is not a power of 2: %i", align);
    o(stuff_const(0xE3C0D000|(r<<16), align - 1)); /* bic sp, r, #align-1 */
    vpop();
#যদি defined(CONFIG_TCC_BCHECK)
    যদি (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R0;
        o(0xe1a0000d | (vtop->r << 12)); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_add_epilog = 1;
    }
#endif
}

/* end of ARM code generator */
/*************************************************************/
#endif
/*************************************************************/
