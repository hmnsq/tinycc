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

#جے_تعریف_شدہ نشانہ_DEFS_ONLY

#إذا defined(TCC_ARM_EABI) && !defined(TCC_ARM_VFP)
#غلطی "Currently TinyCC only supports float computation with VFP instructions"
#جے_انت

/* number of available registers */
#جے_تعریف_شدہ TCC_ARM_VFP
#تعریف_کرو NB_REGS            13
#وإلا
#تعریف_کرو NB_REGS             9
#جے_انت

#جے_بنا_تعریف CONFIG_TCC_CPUVER
# define CONFIG_TCC_CPUVER 5
#جے_انت

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#تعریف_کرو RC_INT     0x0001 /* generic integer register */
#تعریف_کرو RC_FLOAT   0x0002 /* generic float register */
#تعریف_کرو RC_R0      0x0004
#تعریف_کرو RC_R1      0x0008
#تعریف_کرو RC_R2      0x0010
#تعریف_کرو RC_R3      0x0020
#تعریف_کرو RC_R12     0x0040
#تعریف_کرو RC_F0      0x0080
#تعریف_کرو RC_F1      0x0100
#تعریف_کرو RC_F2      0x0200
#تعریف_کرو RC_F3      0x0400
#جے_تعریف_شدہ TCC_ARM_VFP
#تعریف_کرو RC_F4      0x0800
#تعریف_کرو RC_F5      0x1000
#تعریف_کرو RC_F6      0x2000
#تعریف_کرو RC_F7      0x4000
#جے_انت
#تعریف_کرو RC_IRET    RC_R0  /* function return: integer register */
#تعریف_کرو RC_IRE2    RC_R1  /* function return: second integer register */
#تعریف_کرو RC_FRET    RC_F0  /* function return: float register */

/* pretty names for the registers */
تعداد {
    TREG_R0 = 0,
    TREG_R1,
    TREG_R2,
    TREG_R3,
    TREG_R12,
    TREG_F0,
    TREG_F1,
    TREG_F2,
    TREG_F3,
#جے_تعریف_شدہ TCC_ARM_VFP
    TREG_F4,
    TREG_F5,
    TREG_F6,
    TREG_F7,
#جے_انت
    TREG_SP = 13,
    TREG_LR,
};

#جے_تعریف_شدہ TCC_ARM_VFP
#تعریف_کرو T2CPR(t) (((t) & VT_BTYPE) != VT_FLOAT ? 0x100 : 0)
#جے_انت

/* return registers for function */
#تعریف_کرو REG_IRET TREG_R0 /* single word int return register */
#تعریف_کرو REG_IRE2 TREG_R1 /* second word return register (for long long) */
#تعریف_کرو REG_FRET TREG_F0 /* float return register */

#جے_تعریف_شدہ TCC_ARM_EABI
#تعریف_کرو TOK___divdi3 TOK___aeabi_ldivmod
#تعریف_کرو TOK___moddi3 TOK___aeabi_ldivmod
#تعریف_کرو TOK___udivdi3 TOK___aeabi_uldivmod
#تعریف_کرو TOK___umoddi3 TOK___aeabi_uldivmod
#جے_انت

/* defined if function parameters must be evaluated in reverse order */
#تعریف_کرو INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#تعریف_کرو PTR_ناپ 4

/* long double size and alignment, in bytes */
#جے_تعریف_شدہ TCC_ARM_VFP
#تعریف_کرو LDOUBLE_ناپ  8
#جے_انت

#جے_بنا_تعریف LDOUBLE_ناپ
#تعریف_کرو LDOUBLE_ناپ  8
#جے_انت

#جے_تعریف_شدہ TCC_ARM_EABI
#تعریف_کرو LDOUBLE_ALIGN 8
#وإلا
#تعریف_کرو LDOUBLE_ALIGN 4
#جے_انت

#إذا LDOUBLE_ناپ == 8
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#جے_انت

/* maximum alignment (for aligned attribute support) */
#تعریف_کرو MAX_ALIGN     8

#تعریف_کرو CHAR_IS_UNSIGNED

#تعریف_کرو ARM_SOFTFP_FLOAT 0
#تعریف_کرو ARM_HARD_FLOAT 1

/******************************************************/
#وإلا /* ! TARGET_DEFS_ONLY */
/******************************************************/
#تعریف_کرو USING_GLOBALS
#ضمن "tcc.h"

ST_انکڑے ثابت حرف * ثابت نشانہ_machine_defs =
    "__arm__\0"
    "__arm\0"
    "arm\0"
    "__arm_elf__\0"
    "__arm_elf\0"
    "arm_elf\0"
    "__ARM_ARCH_4__\0"
    "__ARMEL__\0"
    "__APCS_32__\0"
#إذا defined TCC_ARM_EABI
    "__ARM_EABI__\0"
#جے_انت
    ;

ST_انکڑے ثابت صحيح reg_classes[NB_REGS] = {
    /* r0 */ RC_INT | RC_R0,
    /* r1 */ RC_INT | RC_R1,
    /* r2 */ RC_INT | RC_R2,
    /* r3 */ RC_INT | RC_R3,
    /* r12 */ RC_INT | RC_R12,
    /* f0 */ RC_FLOAT | RC_F0,
    /* f1 */ RC_FLOAT | RC_F1,
    /* f2 */ RC_FLOAT | RC_F2,
    /* f3 */ RC_FLOAT | RC_F3,
#جے_تعریف_شدہ TCC_ARM_VFP
 /* d4/s8 */ RC_FLOAT | RC_F4,
/* d5/s10 */ RC_FLOAT | RC_F5,
/* d6/s12 */ RC_FLOAT | RC_F6,
/* d7/s14 */ RC_FLOAT | RC_F7,
#جے_انت
};

ساكن صحيح float_abi;
ساكن صحيح func_sub_sp_وتھ, آخری_itod_magic;
ساكن صحيح leaffunc;

#إذا defined(CONFIG_TCC_BCHECK)
ساكن addr_t func_bound_وتھ;
ساكن بنانشانی لما func_bound_ind;
ST_انکڑے صحيح func_bound_جوڑو_epilog;
#جے_انت

#إذا defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
ساكن CType float_type, double_type, func_float_type, func_double_type;
ST_FUNC فراغ arm_init(بنية TCCState *s)
{
    float_type.t = VT_FLOAT;
    double_type.t = VT_DOUBLE;
    func_float_type.t = VT_FUNC;
    func_float_type.ref = sym_ڈالو(SYM_میدان, &float_type, FUNC_CDECL, FUNC_OLD);
    func_double_type.t = VT_FUNC;
    func_double_type.ref = sym_ڈالو(SYM_میدان, &double_type, FUNC_CDECL, FUNC_OLD);

    float_abi = s->float_abi;
#جے_بنا_تعریف TCC_ARM_HARDFLOAT
// XXX: Works on OpenBSD
// # warning "soft float ABI currently not supported: default to softfp"
#جے_انت
}
#وإلا
#تعریف_کرو func_float_type func_old_type
#تعریف_کرو func_double_type func_old_type
#تعریف_کرو func_ldouble_type func_old_type
ST_FUNC فراغ arm_init(بنية TCCState *s)
{
#إذا 0
#إذا !defined (TCC_ARM_VFP)
    tcc_warning("Support for FPA is deprecated and will be removed in next"
                " release");
#جے_انت
#إذا !defined (TCC_ARM_EABI)
    tcc_warning("Support for OABI is deprecated and will be removed in next"
                " release");
#جے_انت
#جے_انت
}
#جے_انت

#تعریف_کرو CHECK_R(r) ((r) >= TREG_R0 && (r) <= TREG_LR)

ساكن صحيح two2mask(صحيح a,صحيح b) {
  إذا (!CHECK_R(a) || !CHECK_R(b))
    tcc_error("compiler error! registers %i,%i is not valid",a,b);
  أرجع (reg_classes[a]|reg_classes[b])&~(RC_INT|RC_FLOAT);
}

ساكن صحيح regmask(صحيح r) {
  إذا (!CHECK_R(r))
    tcc_error("compiler error! register %i is not valid",r);
  أرجع reg_classes[r]&~(RC_INT|RC_FLOAT);
}

/******************************************************/

فراغ o(uint32_t i)
{
  /* this is a good place to start adding big-endian support*/
  صحيح ind1;
  إذا (nocode_wanted)
    أرجع;
  ind1 = ind + 4;
  إذا (!cur_متن_section)
    tcc_error("compiler error! This happens f.ex. if the compiler\n"
         "can't evaluate constant expressions outside of a function.");
  إذا (ind1 > cur_متن_section->انکڑے_allocated)
    section_realloc(cur_متن_section, ind1);
  cur_متن_section->انکڑے[ind++] = i&255;
  i>>=8;
  cur_متن_section->انکڑے[ind++] = i&255;
  i>>=8;
  cur_متن_section->انکڑے[ind++] = i&255;
  i>>=8;
  cur_متن_section->انکڑے[ind++] = i;
}

ساكن uint32_t stuff_const(uint32_t op, uint32_t c)
{
  صحيح try_neg=0;
  uint32_t nc = 0, negop = 0;

  بدل(op&0x1F00000)
  {
    حالة 0x800000: //add
    حالة 0x400000: //sub
      try_neg=1;
      negop=op^0xC00000;
      nc=-c;
      اكسر;
    حالة 0x1A00000: //mov
    حالة 0x1E00000: //mvn
      try_neg=1;
      negop=op^0x400000;
      nc=~c;
      اكسر;
    حالة 0x200000: //xor
      إذا(c==~0)
	أرجع (op&0xF010F000)|((op>>16)&0xF)|0x1E00000;
      اكسر;
    حالة 0x0: //and
      إذا(c==~0)
	أرجع (op&0xF010F000)|((op>>16)&0xF)|0x1A00000;
    حالة 0x1C00000: //bic
      try_neg=1;
      negop=op^0x1C00000;
      nc=~c;
      اكسر;
    حالة 0x1800000: //orr
      إذا(c==~0)
	أرجع (op&0xFFF0FFFF)|0x1E00000;
      اكسر;
  }
  افعل {
    uint32_t m;
    صحيح i;
    إذا(c<256) /* catch undefined <<32 */
      أرجع op|c;
    لكل(i=2;i<32;i+=2) {
      m=(0xffu>>i)|(0xffu<<(32-i));
      إذا(!(c&~m))
	أرجع op|(i<<7)|(c<<i)|(c>>(32-i));
    }
    op=negop;
    c=nc;
  } طالما(try_neg--);
  أرجع 0;
}


//only add,sub
فراغ stuff_const_harder(uint32_t op, uint32_t v) {
  uint32_t x;
  x=stuff_const(op,v);
  إذا(x)
    o(x);
  وإلا {
    uint32_t a[16], nv, no, o2, n2;
    صحيح i,j,k;
    a[0]=0xff;
    o2=(op&0xfff0ffff)|((op&0xf000)<<4);;
    لكل(i=1;i<16;i++)
      a[i]=(a[i-1]>>2)|(a[i-1]<<30);
    لكل(i=0;i<12;i++)
      لكل(j=i<4?i+12:15;j>=i+4;j--)
	إذا((v&(a[i]|a[j]))==v) {
	  o(stuff_const(op,v&a[i]));
	  o(stuff_const(o2,v&a[j]));
	  أرجع;
	}
    no=op^0xC00000;
    n2=o2^0xC00000;
    nv=-v;
    لكل(i=0;i<12;i++)
      لكل(j=i<4?i+12:15;j>=i+4;j--)
	إذا((nv&(a[i]|a[j]))==nv) {
	  o(stuff_const(no,nv&a[i]));
	  o(stuff_const(n2,nv&a[j]));
	  أرجع;
	}
    لكل(i=0;i<8;i++)
      لكل(j=i+4;j<12;j++)
	لكل(k=i<4?i+12:15;k>=j+4;k--)
	  إذا((v&(a[i]|a[j]|a[k]))==v) {
	    o(stuff_const(op,v&a[i]));
	    o(stuff_const(o2,v&a[j]));
	    o(stuff_const(o2,v&a[k]));
	    أرجع;
	  }
    no=op^0xC00000;
    nv=-v;
    لكل(i=0;i<8;i++)
      لكل(j=i+4;j<12;j++)
	لكل(k=i<4?i+12:15;k>=j+4;k--)
	  إذا((nv&(a[i]|a[j]|a[k]))==nv) {
	    o(stuff_const(no,nv&a[i]));
	    o(stuff_const(n2,nv&a[j]));
	    o(stuff_const(n2,nv&a[k]));
	    أرجع;
	  }
    o(stuff_const(op,v&a[0]));
    o(stuff_const(o2,v&a[4]));
    o(stuff_const(o2,v&a[8]));
    o(stuff_const(o2,v&a[12]));
  }
}

uint32_t encbranch(صحيح pos, صحيح addr, صحيح fail)
{
  addr-=pos+8;
  addr/=4;
  إذا(addr>=0x1000000 || addr<-0x1000000) {
    إذا(fail)
      tcc_error("FIXME: function bigger than 32MB");
    أرجع 0;
  }
  أرجع 0x0A000000|(addr&0xffffff);
}

صحيح decbranch(صحيح pos)
{
  صحيح x;
  x=*(uint32_t *)(cur_متن_section->انکڑے + pos);
  x&=0x00ffffff;
  إذا(x&0x800000)
    x-=0x1000000;
  أرجع x*4+pos+8;
}

/* output a symbol and patch all calls to it */
فراغ gsym_addr(صحيح t, صحيح a)
{
  uint32_t *x;
  صحيح lt;
  طالما(t) {
    x=(uint32_t *)(cur_متن_section->انکڑے + t);
    t=decbranch(lt=t);
    إذا(a==lt+4)
      *x=0xE1A00000; // nop
    وإلا {
      *x &= 0xff000000;
      *x |= encbranch(lt,a,1);
    }
  }
}

#جے_تعریف_شدہ TCC_ARM_VFP
ساكن uint32_t vfpr(صحيح r)
{
  إذا(r<TREG_F0 || r>TREG_F7)
    tcc_error("compiler error! register %i is no vfp register",r);
  أرجع r - TREG_F0;
}
#وإلا
ساكن uint32_t fpr(صحيح r)
{
  إذا(r<TREG_F0 || r>TREG_F3)
    tcc_error("compiler error! register %i is no fpa register",r);
  أرجع r - TREG_F0;
}
#جے_انت

ساكن uint32_t intr(صحيح r)
{
  إذا(r == TREG_R12)
    أرجع 12;
  إذا(r >= TREG_R0 && r <= TREG_R3)
    أرجع r - TREG_R0;
  إذا (!(r >= TREG_SP && r <= TREG_LR))
    tcc_error("compiler error! register %i is no int register",r);
  أرجع r + (13 - TREG_SP);
}

ساكن فراغ calcaddr(uint32_t *ادھار, صحيح *off, صحيح *sgn, صحيح maxoff, بنانشانی کھسکاؤ)
{
  إذا(*off>maxoff || *off&((1<<کھسکاؤ)-1)) {
    uint32_t x, y;
    x=0xE280E000;
    إذا(*sgn)
      x=0xE240E000;
    x|=(*ادھار)<<16;
    *ادھار=14; // lr
    y=stuff_const(x,*off&~maxoff);
    إذا(y) {
      o(y);
      *off&=maxoff;
      أرجع;
    }
    y=stuff_const(x,(*off+maxoff)&~maxoff);
    إذا(y) {
      o(y);
      *sgn=!*sgn;
      *off=((*off+maxoff)&~maxoff)-*off;
      أرجع;
    }
    stuff_const_harder(x,*off&~maxoff);
    *off&=maxoff;
  }
}

ساكن uint32_t mapcc(صحيح cc)
{
  بدل(cc)
  {
    حالة TOK_ULT:
      أرجع 0x30000000; /* CC/LO */
    حالة TOK_UGE:
      أرجع 0x20000000; /* CS/HS */
    حالة TOK_EQ:
      أرجع 0x00000000; /* EQ */
    حالة TOK_NE:
      أرجع 0x10000000; /* NE */
    حالة TOK_ULE:
      أرجع 0x90000000; /* LS */
    حالة TOK_UGT:
      أرجع 0x80000000; /* HI */
    حالة TOK_Nset:
      أرجع 0x40000000; /* MI */
    حالة TOK_Nclear:
      أرجع 0x50000000; /* PL */
    حالة TOK_LT:
      أرجع 0xB0000000; /* LT */
    حالة TOK_GE:
      أرجع 0xA0000000; /* GE */
    حالة TOK_LE:
      أرجع 0xD0000000; /* LE */
    حالة TOK_GT:
      أرجع 0xC0000000; /* GT */
  }
  tcc_error("unexpected condition code");
  أرجع 0xE0000000; /* AL */
}

ساكن صحيح negcc(صحيح cc)
{
  بدل(cc)
  {
    حالة TOK_ULT:
      أرجع TOK_UGE;
    حالة TOK_UGE:
      أرجع TOK_ULT;
    حالة TOK_EQ:
      أرجع TOK_NE;
    حالة TOK_NE:
      أرجع TOK_EQ;
    حالة TOK_ULE:
      أرجع TOK_UGT;
    حالة TOK_UGT:
      أرجع TOK_ULE;
    حالة TOK_Nset:
      أرجع TOK_Nclear;
    حالة TOK_Nclear:
      أرجع TOK_Nset;
    حالة TOK_LT:
      أرجع TOK_GE;
    حالة TOK_GE:
      أرجع TOK_LT;
    حالة TOK_LE:
      أرجع TOK_GT;
    حالة TOK_GT:
      أرجع TOK_LE;
  }
  tcc_error("unexpected condition code");
  أرجع TOK_NE;
}

/* Load value into register r.
   Use relative/got addressing to avoid setting DT_TEXTREL */
ساكن فراغ لدو_قدر(SValue *sv, صحيح r)
{
#إذا CONFIG_TCC_CPUVER >= 7
    إذا (!(sv->r & VT_SYM)) {
        بنانشانی x=sv->c.i;
        o(0xE3000000|intr(r)<<12|(x&0xFFF)|(x<<4&0xF0000)); /* movw rx,#x(lo) */
        إذا (x&0xFFFF0000)
          o(0xE3400000|intr(r)<<12|(x>>16&0xFFF)|(x>>12&0xF0000)); /* movt rx,#x(hi) */
        أرجع;
    }
#جے_انت
    o(0xE59F0000|(intr(r)<<12)); /* ldr r, [pc] */
    o(0xEA000000); /* b $+4 */
#جے_بنا_تعریف CONFIG_TCC_PIC
    إذا(sv->r & VT_SYM)
        greloc(cur_متن_section, sv->sym, ind, R_ARM_ABS32);
    o(sv->c.i);
#وإلا
    إذا(sv->r & VT_SYM) {
	إذا (sv->sym->type.t & VT_STATIC) {
            greloc(cur_متن_section, sv->sym, ind, R_ARM_REL32);
            o(sv->c.i - 12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
        }
        وإلا {
            greloc(cur_متن_section, sv->sym, ind, R_ARM_GOT_PREL);
            o(-12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
            o(0xe5900000 | (intr(r)<<12) | (intr(r)<<16));  // ldr rx,[rx]
            إذا (sv->c.i)
              stuff_const_harder(0xe2800000 | (intr(r)<<12) | (intr(r)<<16),
                                 sv->c.i);
        }
    }
    وإلا
        o(sv->c.i);
#جے_انت
}

/* load 'r' from value 'sv' */
فراغ لدو(صحيح r, SValue *sv)
{
  صحيح v, ft, fc, fr, sign;
  uint32_t op, ادھار;
  SValue v1;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  إذا(fc>=0)
    sign=0;
  وإلا {
    sign=1;
    fc=-(بنانشانی)fc;
  }

  v = fr & VT_VALMASK;
  إذا (fr & VT_LVAL) {

    إذا ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe510e000; /* ldr r, [lr, #0] */
        greloca(cur_متن_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        أرجع;
    }

    ادھار = 0xB; // fp
    إذا(v == VT_LLOCAL) {
      v1.type.t = VT_PTR;
      v1.r = VT_LOCAL | VT_LVAL;
      v1.c.i = sv->c.i;
      لدو(TREG_LR, &v1);
      ادھار = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } وإلا إذا(v == VT_CONST) {
      v1.type.t = VT_PTR;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      لدو(TREG_LR, &v1);
      ادھار = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } وإلا إذا(v < VT_CONST) {
      ادھار=intr(v);
      fc=sign=0;
      v=VT_LOCAL;
    }
    إذا(v == VT_LOCAL) {
      إذا(is_float(ft)) {
	calcaddr(&ادھار,&fc,&sign,1020,2);
#جے_تعریف_شدہ TCC_ARM_VFP
        op=0xED100A00; /* flds */
        إذا(!sign)
          op|=0x800000;
        إذا ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* flds -> fldd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(ادھار<<16));
#وإلا
	op=0xED100100;
	إذا(!sign)
	  op|=0x800000;
	إذا ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#إذا LDOUBLE_ناپ != 8
	وإلا إذا ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#جے_انت
	o(op|(fpr(r)<<12)|(fc>>2)|(ادھار<<16));
#جے_انت
      } وإلا إذا((ft & (VT_BTYPE|VT_UNSIGNED)) == VT_BYTE
                || (ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&ادھار,&fc,&sign,255,0);
	op=0xE1500090;
	إذا ((ft & VT_BTYPE) == VT_SHORT)
	  op|=0x20;
	إذا ((ft & VT_UNSIGNED) == 0)
	  op|=0x40;
	إذا(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(ادھار<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } وإلا {
	calcaddr(&ادھار,&fc,&sign,4095,0);
	op=0xE5100000;
	إذا(!sign)
	  op|=0x800000;
        إذا ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(ادھار<<16));
      }
      أرجع;
    }
  } وإلا {
    إذا (v == VT_CONST) {
      op=stuff_const(0xE3A00000|(intr(r)<<12),sv->c.i);
      إذا (fr & VT_SYM || !op)
	لدو_قدر(sv, r);
      وإلا
        o(op);
      أرجع;
    } وإلا إذا (v == VT_LOCAL) {
      op=stuff_const(0xE28B0000|(intr(r)<<12),sv->c.i);
      إذا (fr & VT_SYM || !op) {
	لدو_قدر(sv, r);
	o(0xE08B0000|(intr(r)<<12)|intr(r));
      } وإلا
	o(op);
      أرجع;
    } وإلا إذا(v == VT_CMP) {
      o(mapcc(sv->c.i)|0x3A00001|(intr(r)<<12));
      o(mapcc(negcc(sv->c.i))|0x3A00000|(intr(r)<<12));
      أرجع;
    } وإلا إذا (v == VT_JMP || v == VT_JMPI) {
      صحيح t;
      t = v & 1;
      o(0xE3A00000|(intr(r)<<12)|t);
      o(0xEA000000);
      gsym(sv->c.i);
      o(0xE3A00000|(intr(r)<<12)|(t^1));
      أرجع;
    } وإلا إذا (v < VT_CONST) {
      إذا(is_float(ft))
#جے_تعریف_شدہ TCC_ARM_VFP
        o(0xEEB00A40|(vfpr(r)<<12)|vfpr(v)|T2CPR(ft)); /* fcpyX */
#وإلا
	o(0xEE008180|(fpr(r)<<12)|fpr(v));
#جے_انت
      وإلا
	o(0xE1A00000|(intr(r)<<12)|intr(v));
      أرجع;
    }
  }
  tcc_error("load unimplemented!");
}

/* store register 'r' in lvalue 'v' */
فراغ store(صحيح r, SValue *sv)
{
  SValue v1;
  صحيح v, ft, fc, fr, sign;
  uint32_t op, ادھار;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  إذا(fc>=0)
    sign=0;
  وإلا {
    sign=1;
    fc=-fc;
  }

  v = fr & VT_VALMASK;
  إذا (fr & VT_LVAL || fr == VT_LOCAL) {

    إذا ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe500e000; /* str r, [lr, #0] */
        greloca(cur_متن_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        أرجع;
    }

    ادھار = 0xb; /* fp */
    إذا(v < VT_CONST) {
      ادھار=intr(v);
      v=VT_LOCAL;
      fc=sign=0;
    } وإلا إذا(v == VT_CONST) {
      v1.type.t = ft;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      لدو(TREG_LR, &v1);
      ادھار = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    }
    إذا(v == VT_LOCAL) {
       إذا(is_float(ft)) {
	calcaddr(&ادھار,&fc,&sign,1020,2);
#جے_تعریف_شدہ TCC_ARM_VFP
        op=0xED000A00; /* fsts */
        إذا(!sign)
          op|=0x800000;
        إذا ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* fsts -> fstd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(ادھار<<16));
#وإلا
	op=0xED000100;
	إذا(!sign)
	  op|=0x800000;
	إذا ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#إذا LDOUBLE_ناپ != 8
	وإلا إذا ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#جے_انت
	o(op|(fpr(r)<<12)|(fc>>2)|(ادھار<<16));
#جے_انت
	أرجع;
      } وإلا إذا((ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&ادھار,&fc,&sign,255,0);
	op=0xE14000B0;
	إذا(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(ادھار<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } وإلا {
	calcaddr(&ادھار,&fc,&sign,4095,0);
	op=0xE5000000;
	إذا(!sign)
	  op|=0x800000;
        إذا ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(ادھار<<16));
      }
      أرجع;
    }
  }
  tcc_error("store unimplemented");
}

ساكن فراغ gadd_sp(صحيح val)
{
  stuff_const_harder(0xE28DD000,val);
}

/* 'is_jmp' is '1' if it is a jump */
ساكن فراغ gcall_or_jmp(صحيح is_jmp)
{
  صحيح r;
  uint32_t x;
  إذا ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
    /* constant case */
    إذا(vtop->r & VT_SYM){
	x=encbranch(ind,ind+vtop->c.i,0);
	إذا(x) {
	    /* relocation case */
	    greloc(cur_متن_section, vtop->sym, ind, R_ARM_PC24);
	    o(x|(is_jmp?0xE0000000:0xE1000000));
	} وإلا {
	    r = TREG_LR;
	    لدو_قدر(vtop, r);
	    إذا(is_jmp)
	        o(0xE1A0F000 | intr(r)); // mov pc, r
	    وإلا
		o(0xe12fff30 | intr(r)); // blx r
	}
     }وإلا{
	إذا(!is_jmp)
	    o(0xE28FE004); // add lr,pc,#4
	o(0xE51FF004);   // ldr pc,[pc,#-4]
	o(vtop->c.i);
     }
  } وإلا {
    /* otherwise, indirect call */
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
    vtop->r &= ~VT_MUSTBOUND;
#جے_انت
    r = gv(RC_INT);
    إذا(!is_jmp)
      o(0xE1A0E00F);       // mov lr,pc
    o(0xE1A0F000|intr(r)); // mov pc,r
  }
}

#إذا defined(CONFIG_TCC_BCHECK)

ساكن فراغ gen_bounds_call(صحيح v)
{
    Sym *sym = external_helper_sym(v);

    greloc(cur_متن_section, sym, ind, R_ARM_PC24);
    o(0xebfffffe);
}

ساكن فراغ gen_bounds_prolog(فراغ)
{
    /* leave some room for bound checking code */
    func_bound_وتھ = lbounds_section->انکڑے_وتھ;
    func_bound_ind = ind;
    func_bound_جوڑو_epilog = 0;
    o(0xe1a00000);  /* ld r0,lbounds_section->data_offset */
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);  /* call __bound_local_new */
}

ساكن فراغ gen_bounds_epilog(فراغ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_انکڑے;
    صحيح وتھ_modified = func_bound_وتھ != lbounds_section->انکڑے_وتھ;

    إذا (!وتھ_modified && !func_bound_جوڑو_epilog)
        أرجع;

    /* add end of table info */
    bounds_ptr = section_ptr_جوڑو(lbounds_section, حجم(addr_t));
    *bounds_ptr = 0;

    sym_انکڑے = get_sym_ref(&char_اشارہ_گر_type, lbounds_section,
                           func_bound_وتھ, PTR_ناپ);

    /* generate bound local allocation */
    إذا (وتھ_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        o(0xe59f0000);  /* ldr r0, [pc] */
        o(0xea000000);  /* b $+4 */
        greloc(cur_متن_section, sym_انکڑے, ind, R_ARM_REL32);
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
    greloc(cur_متن_section, sym_انکڑے, ind, R_ARM_REL32);
    o(-12);  /* lbounds_section->data_offset */
    o(0xe080000f);  /* add r0,r0,pc */
    gen_bounds_call(TOK___bound_local_delete);
    o(0xecbd0b04); /* vpop {d0,d1} */
    o(0xe8bd0003); /* pop {r0,r1} */
}
#جے_انت

/* Return whether a structure is an homogeneous float aggregate or not.
   The answer is true if all the elements of the structure are of the same
   primitive float type and there is less than 4 elements.

   type: the type corresponding to the structure to be tested */
ساكن صحيح is_hgen_float_aggr(CType *type)
{
  إذا ((type->t & VT_BTYPE) == VT_STRUCT) {
    بنية Sym *ref;
    صحيح btype, nb_fields = 0;

    ref = type->ref->اگلا;
    إذا (ref) {
      btype = ref->type.t & VT_BTYPE;
      إذا (btype == VT_FLOAT || btype == VT_DOUBLE) {
        لكل(; ref && btype == (ref->type.t & VT_BTYPE); ref = ref->اگلا, nb_fields++)
            ;
        أرجع !ref && nb_fields <= 4;
      }
    }
  }
  أرجع 0;
}

بنية avail_regs {
  نشانیوالا حرف avail[3]; /* 3 holes max with only float and double alignments */
  صحيح پہلا_hole; /* first available hole */
  صحيح آخری_hole; /* last available hole (none if equal to first_hole) */
  صحيح پہلا_free_reg; /* next free register in the sequence, hole excluded */
};

/* Find suitable registers for a VFP Co-Processor Register Candidate (VFP CPRC
   param) according to the rules described in the procedure call standard for
   the ARM architecture (AAPCS). If found, the registers are assigned to this
   VFP CPRC parameter. Registers are allocated in sequence unless a hole exists
   and the parameter is a single float.

   avregs: opaque structure to keep track of available VFP co-processor regs
   align: alignment constraints for the param, as returned by type_size()
   size: size of the parameter, as returned by type_size() */
صحيح سونپو_vfpreg(بنية avail_regs *avregs, صحيح align, صحيح ناپ)
{
  صحيح پہلا_reg = 0;

  إذا (avregs->پہلا_free_reg == -1)
    أرجع -1;
  إذا (align >> 3) { /* double alignment */
    پہلا_reg = avregs->پہلا_free_reg;
    /* alignment constraint not respected so use next reg and record hole */
    إذا (پہلا_reg & 1)
      avregs->avail[avregs->آخری_hole++] = پہلا_reg++;
  } وإلا { /* no special alignment (float or array of float) */
    /* if single float and a hole is available, assign the param to it */
    إذا (ناپ == 4 && avregs->پہلا_hole != avregs->آخری_hole)
      أرجع avregs->avail[avregs->پہلا_hole++];
    وإلا
      پہلا_reg = avregs->پہلا_free_reg;
  }
  إذا (پہلا_reg + ناپ / 4 <= 16) {
    avregs->پہلا_free_reg = پہلا_reg + ناپ / 4;
    أرجع پہلا_reg;
  }
  avregs->پہلا_free_reg = -1;
  أرجع -1;
}

/* Returns whether all params need to be passed in core registers or not.
   This is the case for function part of the runtime ABI. */
صحيح floats_وچ_core_regs(SValue *sval)
{
  إذا (!sval->sym)
    أرجع 0;

  بدل (sval->sym->v) {
    حالة TOK___floatundisf:
    حالة TOK___floatundidf:
    حالة TOK___fixunssfdi:
    حالة TOK___fixunsdfdi:
#جے_بنا_تعریف TCC_ARM_VFP
    حالة TOK___fixunsxfdi:
#جے_انت
    حالة TOK___floatdisf:
    حالة TOK___floatdidf:
    حالة TOK___fixsfdi:
    حالة TOK___fixdfdi:
      أرجع 1;

    افتراضي:
      أرجع 0;
  }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret, صحيح *ret_align, صحيح *regsize) {
#جے_تعریف_شدہ TCC_ARM_EABI
    صحيح ناپ, align;
    ناپ = type_ناپ(vt, &align);
    إذا (float_abi == ARM_HARD_FLOAT && !variadic &&
        (is_float(vt->t) || is_hgen_float_aggr(vt))) {
        *ret_align = 8;
	*regsize = 8;
        ret->ref = عدم;
        ret->t = VT_DOUBLE;
        أرجع (ناپ + 7) >> 3;
    } وإلا إذا (ناپ > 0 && ناپ <= 4) {
        *ret_align = 4;
	*regsize = 4;
        ret->ref = عدم;
        ret->t = VT_INT;
        أرجع 1;
    } وإلا
        أرجع 0;
#وإلا
    أرجع 0;
#جے_انت
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
تعداد reg_class {
	ڈھیر_CLASS = 0,
	CORE_STRUCT_CLASS,
	VFP_CLASS,
	VFP_STRUCT_CLASS,
	CORE_CLASS,
	NB_CLASSES
};

بنية param_plan {
    صحيح شروع; /* first reg or addr used depending on the class */
    صحيح سرا; /* last reg used or next free addr depending on the class */
    SValue *sval; /* pointer to SValue on the value stack */
    بنية param_plan *prev; /*  previous element in this class */
};

بنية plan {
    بنية param_plan *pplans; /* array of all the param plans */
    بنية param_plan *clsplans[NB_CLASSES]; /* per class lists of param plans */
    صحيح nb_plans;
};

ساكن فراغ جوڑو_param_plan(بنية plan* plan, صحيح cls, صحيح شروع, صحيح سرا, SValue *v)
{
    بنية param_plan *p = &plan->pplans[plan->nb_plans++];
    p->prev = plan->clsplans[cls];
    plan->clsplans[cls] = p;
    p->شروع = شروع, p->سرا = سرا, p->sval = v;
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
ساكن صحيح سونپو_regs(صحيح nb_دلیلاں, صحيح float_abi, بنية plan *plan, صحيح *todo)
{
  صحيح i, ناپ, align;
  صحيح ncrn /* next core register number */, nsaa /* next stacked argument address*/;
  بنية avail_regs avregs = {{0}};

  ncrn = nsaa = 0;
  *todo = 0;

  لكل(i = nb_دلیلاں; i-- ;) {
    صحيح j, شروع_vfpreg = 0;
    CType type = vtop[-i].type;
    type.t &= ~VT_ARRAY;
    ناپ = type_ناپ(&type, &align);
    ناپ = (ناپ + 3) & ~3;
    align = (align + 3) & ~3;
    بدل(vtop[-i].type.t & VT_BTYPE) {
      حالة VT_STRUCT:
      حالة VT_FLOAT:
      حالة VT_DOUBLE:
      حالة VT_LDOUBLE:
      إذا (float_abi == ARM_HARD_FLOAT) {
        صحيح is_hfa = 0; /* Homogeneous float aggregate */

        إذا (is_float(vtop[-i].type.t)
            || (is_hfa = is_hgen_float_aggr(&vtop[-i].type))) {
          صحيح سرا_vfpreg;

          شروع_vfpreg = سونپو_vfpreg(&avregs, align, ناپ);
          سرا_vfpreg = شروع_vfpreg + ((ناپ - 1) >> 2);
          إذا (شروع_vfpreg >= 0) {
            جوڑو_param_plan(plan, is_hfa ? VFP_STRUCT_CLASS : VFP_CLASS,
                شروع_vfpreg, سرا_vfpreg, &vtop[-i]);
            استمر;
          } وإلا
            اكسر;
        }
      }
      ncrn = (ncrn + (align-1)/4) & ~((align/4) - 1);
      إذا (ncrn + ناپ/4 <= 4 || (ncrn < 4 && شروع_vfpreg != -1)) {
        /* The parameter is allocated both in core register and on stack. As
	 * such, it can be of either class: it would either be the last of
	 * CORE_STRUCT_CLASS or the first of STACK_CLASS. */
        لكل (j = ncrn; j < 4 && j < ncrn + ناپ / 4; j++)
          *todo|=(1<<j);
        جوڑو_param_plan(plan, CORE_STRUCT_CLASS, ncrn, j, &vtop[-i]);
        ncrn += ناپ/4;
        إذا (ncrn > 4)
          nsaa = (ncrn - 4) * 4;
      } وإلا {
        ncrn = 4;
        اكسر;
      }
      استمر;
      افتراضي:
      إذا (ncrn < 4) {
        صحيح is_long = (vtop[-i].type.t & VT_BTYPE) == VT_LLONG;

        إذا (is_long) {
          ncrn = (ncrn + 1) & -2;
          إذا (ncrn == 4)
            اكسر;
        }
        جوڑو_param_plan(plan, CORE_CLASS, ncrn, ncrn + is_long, &vtop[-i]);
        ncrn += 1 + is_long;
        استمر;
      }
    }
    nsaa = (nsaa + (align - 1)) & ~(align - 1);
    جوڑو_param_plan(plan, ڈھیر_CLASS, nsaa, nsaa + ناپ, &vtop[-i]);
    nsaa += ناپ; /* size already rounded up before */
  }
  أرجع nsaa;
}

/* Copy parameters to their final destination (core reg, VFP reg or stack) for
   function call.

   nb_args: number of parameters the function take
   plan: the overall assignment plan for parameters
   todo: a bitmap indicating what core reg will hold a parameter

   Returns the number of SValue added by this function on the value stack */
ساكن صحيح copy_params(صحيح nb_دلیلاں, بنية plan *plan, صحيح todo)
{
  صحيح ناپ, align, r, i, nb_extra_sval = 0;
  بنية param_plan *pplan;
  صحيح pass = 0;

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
  لكل(i = 0; i < NB_CLASSES; i++) {
    لكل(pplan = plan->clsplans[i]; pplan; pplan = pplan->prev) {

      إذا (pass
          && (i != CORE_CLASS || pplan->sval->r < VT_CONST))
        استمر;

      vpushv(pplan->sval);
      pplan->sval->r = pplan->sval->r2 = VT_CONST; /* disable entry */
      بدل(i) {
        حالة ڈھیر_CLASS:
        حالة CORE_STRUCT_CLASS:
        حالة VFP_STRUCT_CLASS:
          إذا ((pplan->sval->type.t & VT_BTYPE) == VT_STRUCT) {
            صحيح padding = 0;
            ناپ = type_ناپ(&pplan->sval->type, &align);
            /* align to stack align size */
            ناپ = (ناپ + 3) & ~3;
            إذا (i == ڈھیر_CLASS && pplan->prev)
              padding = pplan->شروع - pplan->prev->سرا;
            ناپ += padding; /* Add padding if any */
            /* allocate the necessary size on stack */
            gadd_sp(-ناپ);
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
            إذا (i == VFP_STRUCT_CLASS) {
              صحيح پہلا = pplan->شروع, nb = pplan->سرا - پہلا + 1;
              /* vpop.32 {pplan->start, ..., pplan->end} */
              o(0xECBD0A00|(پہلا&1)<<22|(پہلا>>1)<<12|nb);
              /* No need to write the register used to a SValue since VFP regs
                 cannot be used for gcall_or_jmp */
            }
          } وإلا {
            إذا (is_float(pplan->sval->type.t)) {
#جے_تعریف_شدہ TCC_ARM_VFP
              r = vfpr(gv(RC_FLOAT)) << 12;
              إذا ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                ناپ = 4;
              وإلا {
                ناپ = 8;
                r |= 0x101; /* vpush.32 -> vpush.64 */
              }
              o(0xED2D0A01 + r); /* vpush */
#وإلا
              r = fpr(gv(RC_FLOAT)) << 12;
              إذا ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                ناپ = 4;
              وإلا إذا ((pplan->sval->type.t & VT_BTYPE) == VT_DOUBLE)
                ناپ = 8;
              وإلا
                ناپ = LDOUBLE_ناپ;
              إذا (ناپ == 12)
                r |= 0x400000;
              وإلا إذا(ناپ == 8)
                r|=0x8000;

              o(0xED2D0100|r|(ناپ>>2)); /* some kind of vpush for FPA */
#جے_انت
            } وإلا {
              /* simple type (currently always same size) */
              /* XXX: implicit cast ? */
              ناپ=4;
              إذا ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
                lexpand();
                ناپ = 8;
                r = gv(RC_INT);
                o(0xE52D0004|(intr(r)<<12)); /* push r */
                vtop--;
              }
              r = gv(RC_INT);
              o(0xE52D0004|(intr(r)<<12)); /* push r */
            }
            إذا (i == ڈھیر_CLASS && pplan->prev)
              gadd_sp(pplan->prev->سرا - pplan->شروع); /* Add padding if any */
          }
          اكسر;

        حالة VFP_CLASS:
          gv(regmask(TREG_F0 + (pplan->شروع >> 1)));
          إذا (pplan->شروع & 1) { /* Must be in upper part of double register */
            o(0xEEF00A40|((pplan->شروع>>1)<<12)|(pplan->شروع>>1)); /* vmov.f32 s(n+1), sn */
            vtop->r = VT_CONST; /* avoid being saved on stack by gv for next float */
          }
          اكسر;

        حالة CORE_CLASS:
          إذا ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
            lexpand();
            gv(regmask(pplan->سرا));
            pplan->sval->r2 = vtop->r;
            vtop--;
          }
          gv(regmask(pplan->شروع));
          /* Mark register as used so that gcall_or_jmp use another one
             (regs >=4 are free as never used to pass parameters) */
          pplan->sval->r = vtop->r;
          اكسر;
      }
      vtop--;
    }
  }

  /* second pass to restore registers that were saved on stack by accident.
     Maybe redundant after the "lvalue_save" patch in tccgen.c:gv() */
  إذا (++pass < 2)
    اذهب again;

  إذا(todo) {
    o(0xE8BD0000|todo); /* pop {todo} */
    لكل(pplan = plan->clsplans[CORE_STRUCT_CLASS]; pplan; pplan = pplan->prev) {
      صحيح r;
      pplan->sval->r = pplan->شروع;
      /* An SValue can only pin 2 registers at best (r and r2) but a structure
         can occupy more than 2 registers. Thus, we need to push on the value
         stack some fake parameter to have on SValue for each registers used
         by a structure (r2 is not used). */
      لكل (r = pplan->شروع + 1; r <= pplan->سرا; r++) {
        إذا (todo & (1 << r)) {
          nb_extra_sval++;
          vpushi(0);
          vtop->r = r;
        }
      }
    }
  }
  أرجع nb_extra_sval;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
فراغ gfunc_call(صحيح nb_دلیلاں)
{
  صحيح دلیلاں_ناپ;
  صحيح def_float_abi = float_abi;
  صحيح todo;
  بنية plan plan;
#جے_تعریف_شدہ TCC_ARM_EABI
  صحيح variadic;
#جے_انت

#جے_تعریف_شدہ CONFIG_TCC_BCHECK
  إذا (tcc_state->do_bounds_check)
    gbound_دلیلاں(nb_دلیلاں);
#جے_انت

  save_regs(nb_دلیلاں + 1);

#جے_تعریف_شدہ TCC_ARM_EABI
  إذا (float_abi == ARM_HARD_FLOAT) {
    variadic = (vtop[-nb_دلیلاں].type.ref->f.func_type == FUNC_ELLIPSIS);
    إذا (variadic || floats_وچ_core_regs(&vtop[-nb_دلیلاں]))
      float_abi = ARM_SOFTFP_FLOAT;
  }
#جے_انت

  memset(&plan, 0, حجم plan);
  إذا (nb_دلیلاں)
    plan.pplans = tcc_malloc(nb_دلیلاں * حجم(*plan.pplans));

  دلیلاں_ناپ = سونپو_regs(nb_دلیلاں, float_abi, &plan, &todo);

#جے_تعریف_شدہ TCC_ARM_EABI
  إذا (دلیلاں_ناپ & 7) { /* Stack must be 8 byte aligned at fct call for EABI */
    دلیلاں_ناپ = (دلیلاں_ناپ + 7) & ~7;
    o(0xE24DD004); /* sub sp, sp, #4 */
  }
#جے_انت

  nb_دلیلاں += copy_params(nb_دلیلاں, &plan, todo);
  tcc_free(plan.pplans);

  /* Move fct SValue on top as required by gcall_or_jmp */
  vrotb(nb_دلیلاں + 1);
  gcall_or_jmp(0);
  إذا (دلیلاں_ناپ)
      gadd_sp(دلیلاں_ناپ); /* pop all parameters passed on the stack */
#إذا defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  إذا(float_abi == ARM_SOFTFP_FLOAT && is_float(vtop->type.ref->type.t)) {
    إذا((vtop->type.ref->type.t & VT_BTYPE) == VT_FLOAT) {
      o(0xEE000A10); /*vmov s0, r0 */
    } وإلا {
      o(0xEE000B10); /* vmov.32 d0[0], r0 */
      o(0xEE201B10); /* vmov.32 d0[1], r1 */
    }
  }
#جے_انت
  vtop -= nb_دلیلاں + 1; /* Pop all params and fct address from value stack */
  leaffunc = 0; /* we are calling a function, so we aren't in a leaf function */
  float_abi = def_float_abi;
}

/* generate function prolog of type 't' */
فراغ gfunc_prolog(Sym *func_sym)
{
  CType *func_type = &func_sym->type;
  Sym *sym,*sym2;
  صحيح n, nf, ناپ, align, rs, struct_ret = 0;
  صحيح addr, pn, sn; /* pn=core, sn=stack */
  CType ret_type;

#جے_تعریف_شدہ TCC_ARM_EABI
  بنية avail_regs avregs = {{0}};
#جے_انت

  sym = func_type->ref;

  n = nf = 0;
  إذا ((func_vt.t & VT_BTYPE) == VT_STRUCT &&
      !gfunc_sret(&func_vt, func_var, &ret_type, &align, &rs))
  {
    n++;
    struct_ret = 1;
    func_vc = 12; /* Offset from fp of the place to store the result */
  }
  لكل(sym2 = sym->اگلا; sym2 && (n < 4 || nf < 16); sym2 = sym2->اگلا) {
    ناپ = type_ناپ(&sym2->type, &align);
#جے_تعریف_شدہ TCC_ARM_EABI
    إذا (float_abi == ARM_HARD_FLOAT && !func_var &&
        (is_float(sym2->type.t) || is_hgen_float_aggr(&sym2->type))) {
      صحيح tmpnf = سونپو_vfpreg(&avregs, align, ناپ);
      tmpnf += (ناپ + 3) / 4;
      nf = (tmpnf > nf) ? tmpnf : nf;
    } وإلا
#جے_انت
    إذا (n < 4)
      n += (ناپ + 3) / 4;
  }
  o(0xE1A0C00D); /* mov ip,sp */
  إذا (func_var)
    n=4;
  إذا (n) {
    إذا(n>4)
      n=4;
#جے_تعریف_شدہ TCC_ARM_EABI
    n=(n+1)&-2;
#جے_انت
    o(0xE92D0000|((1<<n)-1)); /* save r0-r4 on stack if needed */
  }
  إذا (nf) {
    إذا (nf>16)
      nf=16;
    nf=(nf+1)&-2; /* nf => HARDFLOAT => EABI */
    o(0xED2D0A00|nf); /* save s0-s15 on stack if needed */
  }
  o(0xE92D5800); /* save fp, ip, lr */
  o(0xE1A0B00D); /* mov fp, sp */
  func_sub_sp_وتھ = ind;
  o(0xE1A00000); /* nop, leave space for stack adjustment in epilog */

#جے_تعریف_شدہ TCC_ARM_EABI
  إذا (float_abi == ARM_HARD_FLOAT) {
    func_vc += nf * 4;
    memset(&avregs, 0, حجم avregs);
  }
#جے_انت
  pn = struct_ret, sn = 0;
  طالما ((sym = sym->اگلا)) {
    CType *type;
    type = &sym->type;
    ناپ = type_ناپ(type, &align);
    ناپ = (ناپ + 3) >> 2;
    align = (align + 3) & ~3;
#جے_تعریف_شدہ TCC_ARM_EABI
    إذا (float_abi == ARM_HARD_FLOAT && !func_var && (is_float(sym->type.t)
        || is_hgen_float_aggr(&sym->type))) {
      صحيح fpn = سونپو_vfpreg(&avregs, align, ناپ << 2);
      إذا (fpn >= 0)
        addr = fpn * 4;
      وإلا
        اذهب from_ڈھیر;
    } وإلا
#جے_انت
    إذا (pn < 4) {
#جے_تعریف_شدہ TCC_ARM_EABI
        pn = (pn + (align-1)/4) & -(align/4);
#جے_انت
      addr = (nf + pn) * 4;
      pn += ناپ;
      إذا (!sn && pn > 4)
        sn = (pn - 4);
    } وإلا {
#جے_تعریف_شدہ TCC_ARM_EABI
from_ڈھیر:
        sn = (sn + (align-1)/4) & -(align/4);
#جے_انت
      addr = (n + nf + sn) * 4;
      sn += ناپ;
    }
    gfunc_سیٹ_param(sym, addr + 12, 0);
  }
  آخری_itod_magic=0;
  leaffunc = 1;
  loc = 0;
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
  إذا (tcc_state->do_bounds_check)
    gen_bounds_prolog();
#جے_انت
}

/* generate function epilog */
فراغ gfunc_epilog(فراغ)
{
  uint32_t x;
  صحيح diff;

#جے_تعریف_شدہ CONFIG_TCC_BCHECK
  إذا (tcc_state->do_bounds_check)
    gen_bounds_epilog();
#جے_انت
  /* Copy float return value to core register if base standard is used and
     float computation is made with VFP */
#إذا defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  إذا ((float_abi == ARM_SOFTFP_FLOAT || func_var) && is_float(func_vt.t)) {
    إذا((func_vt.t & VT_BTYPE) == VT_FLOAT)
      o(0xEE100A10); /* fmrs r0, s0 */
    وإلا {
      o(0xEE100B10); /* fmrdl r0, d0 */
      o(0xEE301B10); /* fmrdh r1, d0 */
    }
  }
#جے_انت
  o(0xE89BA800); /* restore fp, sp, pc */
  diff = (-loc + 3) & -4;
#جے_تعریف_شدہ TCC_ARM_EABI
  إذا(!leaffunc)
    diff = ((diff + 11) & -8) - 4;
#جے_انت
  إذا(diff > 0) {
    x=stuff_const(0xE24BD000, diff); /* sub sp,fp,# */
    إذا(x)
      *(uint32_t *)(cur_متن_section->انکڑے + func_sub_sp_وتھ) = x;
    وإلا {
      صحيح addr;
      addr=ind;
      o(0xE59FC004); /* ldr ip,[pc+4] */
      o(0xE04BD00C); /* sub sp,fp,ip  */
      o(0xE1A0F00E); /* mov pc,lr */
      o(diff);
      *(uint32_t *)(cur_متن_section->انکڑے + func_sub_sp_وتھ) = 0xE1000000|encbranch(func_sub_sp_وتھ,addr,1);
    }
  }
}

ST_FUNC فراغ gen_fill_nops(صحيح بائٹاں)
{
    إذا ((بائٹاں & 3))
      tcc_error("alignment of code section not multiple of 4");
    طالما (بائٹاں > 0) {
	o(0xE1A00000);
	بائٹاں -= 4;
    }
}

/* generate a jump to a label */
ST_FUNC صحيح gjmp(صحيح t)
{
  صحيح r;
  إذا (nocode_wanted)
    أرجع t;
  r=ind;
  o(0xE0000000|encbranch(r,t,1));
  أرجع r;
}

/* generate a jump to a fixed address */
ST_FUNC فراغ gjmp_addr(صحيح a)
{
  gjmp(a);
}

ST_FUNC صحيح gjmp_cond(صحيح op, صحيح t)
{
  صحيح r;
  إذا (nocode_wanted)
    أرجع t;
  r=ind;
  op=mapcc(op);
  op|=encbranch(r,t,1);
  o(op);
  أرجع r;
}

ST_FUNC صحيح gjmp_append(صحيح n, صحيح t)
{
  uint32_t *x;
  صحيح p,lp;
  إذا(n) {
    p = n;
    افعل {
      p = decbranch(lp=p);
    } طالما(p);
    x = (uint32_t *)(cur_متن_section->انکڑے + lp);
    *x &= 0xff000000;
    *x |= encbranch(lp,t,1);
    t = n;
  }
  أرجع t;
}

/* generate an integer binary operation */
فراغ gen_opi(صحيح op)
{
  صحيح c, func = 0;
  uint32_t opc = 0, r, fr;
  بنانشانی چھوٹا retreg = REG_IRET;

  c=0;
  بدل(op) {
    حالة '+':
      opc = 0x8;
      c=1;
      اكسر;
    حالة TOK_ADDC1: /* add with carry generation */
      opc = 0x9;
      c=1;
      اكسر;
    حالة '-':
      opc = 0x4;
      c=1;
      اكسر;
    حالة TOK_SUBC1: /* sub with carry generation */
      opc = 0x5;
      c=1;
      اكسر;
    حالة TOK_ADDC2: /* add with carry use */
      opc = 0xA;
      c=1;
      اكسر;
    حالة TOK_SUBC2: /* sub with carry use */
      opc = 0xC;
      c=1;
      اكسر;
    حالة '&':
      opc = 0x0;
      c=1;
      اكسر;
    حالة '^':
      opc = 0x2;
      c=1;
      اكسر;
    حالة '|':
      opc = 0x18;
      c=1;
      اكسر;
    حالة '*':
      gv2(RC_INT, RC_INT);
      r = vtop[-1].r;
      fr = vtop[0].r;
      vtop--;
      o(0xE0000090|(intr(r)<<16)|(intr(r)<<8)|intr(fr));
      أرجع;
    حالة TOK_SHL:
      opc = 0;
      c=2;
      اكسر;
    حالة TOK_SHR:
      opc = 1;
      c=2;
      اكسر;
    حالة TOK_SAR:
      opc = 2;
      c=2;
      اكسر;
    حالة '/':
    حالة TOK_PDIV:
      func=TOK___divsi3;
      c=3;
      اكسر;
    حالة TOK_UDIV:
      func=TOK___udivsi3;
      c=3;
      اكسر;
    حالة '%':
#جے_تعریف_شدہ TCC_ARM_EABI
      func=TOK___aeabi_idivmod;
      retreg=REG_IRE2;
#وإلا
      func=TOK___modsi3;
#جے_انت
      c=3;
      اكسر;
    حالة TOK_UMOD:
#جے_تعریف_شدہ TCC_ARM_EABI
      func=TOK___aeabi_uidivmod;
      retreg=REG_IRE2;
#وإلا
      func=TOK___umodsi3;
#جے_انت
      c=3;
      اكسر;
    حالة TOK_UMULL:
      gv2(RC_INT, RC_INT);
      r=intr(vtop[-1].r2=get_reg(RC_INT));
      c=vtop[-1].r;
      vtop[-1].r=get_reg_ex(RC_INT,regmask(c));
      vtop--;
      o(0xE0800090|(r<<16)|(intr(vtop->r)<<12)|(intr(c)<<8)|intr(vtop[1].r));
      أرجع;
    افتراضي:
      opc = 0x15;
      c=1;
      اكسر;
  }
  بدل(c) {
    حالة 1:
      إذا((vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	إذا(opc == 4 || opc == 5 || opc == 0xc) {
	  vswap();
	  opc|=2; // sub -> rsb
	}
      }
      vswap();
      c=intr(gv(RC_INT));
      vswap();
      opc=0xE0000000|(opc<<20);
      إذا((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	uint32_t x;
	x=stuff_const(opc|0x2000000|(c<<16),vtop->c.i);
	إذا(x) {
	  إذا ((x & 0xfff00000) == 0xe3500000)   // cmp rx,#c
	    o(x);
	  وإلا {
	    r=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	    o(x|(r<<12));
	  }
	  اذهب پورا;
	}
      }
      fr=intr(gv(RC_INT));
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
      إذا ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
        vswap();
        c=intr(gv(RC_INT));
        vswap();
      }
#جے_انت
      إذا ((opc & 0xfff00000) == 0xe1500000) // cmp rx,ry
	o(opc|(c<<16)|fr);
      وإلا {
        r=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
        o(opc|(c<<16)|(r<<12)|fr);
      }
پورا:
      vtop--;
      إذا (op >= TOK_ULT && op <= TOK_GT)
        vset_VT_CMP(op);
      اكسر;
    حالة 2:
      opc=0xE1A00000|(opc<<5);
      vswap();
      r=intr(gv(RC_INT));
      vswap();
      إذا ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	fr=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	c = vtop->c.i & 0x1f;
	o(opc|r|(c<<7)|(fr<<12));
      } وإلا {
        fr=intr(gv(RC_INT));
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
        إذا ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=intr(gv(RC_INT));
          vswap();
        }
#جے_انت
	c=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
	o(opc|r|(c<<12)|(fr<<8)|0x10);
      }
      vtop--;
      اكسر;
    حالة 3:
      vpush_helper_func(func);
      vrott(3);
      gfunc_call(2);
      vpushi(0);
      vtop->r = retreg;
      اكسر;
    افتراضي:
      tcc_error("gen_opi %i unimplemented!",op);
  }
}

#جے_تعریف_شدہ TCC_ARM_VFP
ساكن صحيح is_zero(صحيح i)
{
  إذا((vtop[i].r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    أرجع 0;
  إذا (vtop[i].type.t == VT_FLOAT)
    أرجع (vtop[i].c.f == 0.f);
  وإلا إذا (vtop[i].type.t == VT_DOUBLE)
    أرجع (vtop[i].c.d == 0.0);
  أرجع (vtop[i].c.ld == 0.l);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
 *    two operands are guaranteed to have the same floating point type */
فراغ gen_opf(صحيح op)
{
  uint32_t x;
  صحيح fneg=0,r;
  x=0xEE000A00|T2CPR(vtop->type.t);
  بدل(op) {
    حالة '+':
      إذا(is_zero(-1))
        vswap();
      إذا(is_zero(0)) {
        vtop--;
        أرجع;
      }
      x|=0x300000;
      اكسر;
    حالة '-':
      x|=0x300040;
      إذا(is_zero(0)) {
        vtop--;
        أرجع;
      }
      إذا(is_zero(-1)) {
        x|=0x810000; /* fsubX -> fnegX */
        vswap();
        vtop--;
        fneg=1;
      }
      اكسر;
    حالة '*':
      x|=0x200000;
      اكسر;
    حالة '/':
      x|=0x800000;
      اكسر;
    افتراضي:
      إذا(op < TOK_ULT || op > TOK_GT) {
        tcc_error("unknown fp op %x!",op);
        أرجع;
      }
      إذا(is_zero(-1)) {
        vswap();
        بدل(op) {
          حالة TOK_LT: op=TOK_GT; اكسر;
          حالة TOK_GE: op=TOK_ULE; اكسر;
          حالة TOK_LE: op=TOK_GE; اكسر;
          حالة TOK_GT: op=TOK_ULT; اكسر;
        }
      }
      x|=0xB40040; /* fcmpX */
      إذا(op!=TOK_EQ && op!=TOK_NE)
        x|=0x80; /* fcmpX -> fcmpeX */
      إذا(is_zero(0)) {
        vtop--;
        o(x|0x10000|(vfpr(gv(RC_FLOAT))<<12)); /* fcmp(e)X -> fcmp(e)zX */
      } وإلا {
        gv2(RC_FLOAT,RC_FLOAT);
        x|=vfpr(vtop[0].r);
        o(x|(vfpr(vtop[-1].r) << 12));
        vtop--;
      }
      o(0xEEF1FA10); /* fmstat */

      بدل(op) {
        حالة TOK_LE: op=TOK_ULE; اكسر;
        حالة TOK_LT: op=TOK_ULT; اكسر;
        حالة TOK_UGE: op=TOK_GE; اكسر;
        حالة TOK_UGT: op=TOK_GT; اكسر;
      }
      vset_VT_CMP(op);
      أرجع;
  }
  r=gv(RC_FLOAT);
  x|=vfpr(r);
  r=regmask(r);
  إذا(!fneg) {
    صحيح r2;
    vswap();
    r2=gv(RC_FLOAT);
    x|=vfpr(r2)<<16;
    r|=regmask(r2);
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
    إذا ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
      vswap();
      r=gv(RC_FLOAT);
      vswap();
      x=(x&~0xf)|vfpr(r);
    }
#جے_انت
  }
  vtop->r=get_reg_ex(RC_FLOAT,r);
  إذا(!fneg)
    vtop--;
  o(x|(vfpr(vtop->r)<<12));
}

#وإلا
ساكن uint32_t is_fconst()
{
  لما مزدوج f;
  uint32_t r;
  إذا((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    أرجع 0;
  إذا (vtop->type.t == VT_FLOAT)
    f = vtop->c.f;
  وإلا إذا (vtop->type.t == VT_DOUBLE)
    f = vtop->c.d;
  وإلا
    f = vtop->c.ld;
  إذا(!ieee_finite(f))
    أرجع 0;
  r=0x8;
  إذا(f<0.0) {
    r=0x18;
    f=-f;
  }
  إذا(f==0.0)
    أرجع r;
  إذا(f==1.0)
    أرجع r|1;
  إذا(f==2.0)
    أرجع r|2;
  إذا(f==3.0)
    أرجع r|3;
  إذا(f==4.0)
    أرجع r|4;
  إذا(f==5.0)
    أرجع r|5;
  إذا(f==0.5)
    أرجع r|6;
  إذا(f==10.0)
    أرجع r|7;
  أرجع 0;
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
فراغ gen_opf(صحيح op)
{
  uint32_t x, r, r2, c1, c2;
  //fputs("gen_opf\n",stderr);
  vswap();
  c1 = is_fconst();
  vswap();
  c2 = is_fconst();
  x=0xEE000100;
  إذا ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
    x|=0x80;
#إذا LDOUBLE_ناپ != 8
  وإلا إذا ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE)
    x|=0x80000;
#جے_انت

  بدل(op)
  {
    حالة '+':
      إذا(!c2) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      إذا(c2) {
	إذا(c2>0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
      } وإلا {
	r2=fpr(gv(RC_FLOAT));
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
        إذا ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#جے_انت
      }
      اكسر;
    حالة '-':
      إذا(c2) {
	إذا(c2<=0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } وإلا إذا(c1 && c1<=0xf) {
	x|=0x300000; // rsf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } وإلا {
	x|=0x200000; // suf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
        إذا ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#جے_انت
      }
      اكسر;
    حالة '*':
      إذا(!c2 || c2>0xf) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      إذا(c2 && c2<=0xf)
	r2=c2;
      وإلا {
	r2=fpr(gv(RC_FLOAT));
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
        إذا ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#جے_انت
      }
      x|=0x100000; // muf
      اكسر;
    حالة '/':
      إذا(c2 && c2<=0xf) {
	x|=0x400000; // dvf
	r2=c2;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } وإلا إذا(c1 && c1<=0xf) {
	x|=0x500000; // rdf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } وإلا {
	x|=0x400000; // dvf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
        إذا ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#جے_انت
      }
      اكسر;
    افتراضي:
      إذا(op >= TOK_ULT && op <= TOK_GT) {
	x|=0xd0f110; // cmfe
/* bug (intention?) in Linux FPU emulator
   doesn't set carry if equal */
	بدل(op) {
	  حالة TOK_ULT:
	  حالة TOK_UGE:
	  حالة TOK_ULE:
	  حالة TOK_UGT:
            tcc_error("unsigned comparison on floats?");
	    اكسر;
	  حالة TOK_LT:
            op=TOK_Nset;
	    اكسر;
	  حالة TOK_LE:
            op=TOK_ULE; /* correct in unordered case only if AC bit in FPSR set */
	    اكسر;
	  حالة TOK_EQ:
	  حالة TOK_NE:
	    x&=~0x400000; // cmfe -> cmf
	    اكسر;
	}
	إذا(c1 && !c2) {
	  c2=c1;
	  vswap();
	  بدل(op) {
            حالة TOK_Nset:
              op=TOK_GT;
	      اكسر;
            حالة TOK_GE:
	      op=TOK_ULE;
	      اكسر;
	    حالة TOK_ULE:
              op=TOK_GE;
	      اكسر;
            حالة TOK_GT:
              op=TOK_Nset;
	      اكسر;
	  }
	}
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	إذا(c2) {
	  إذا(c2>0xf)
	    x|=0x200000;
	  r2=c2&0xf;
	} وإلا {
	  r2=fpr(gv(RC_FLOAT));
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
          إذا ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            r=fpr(gv(RC_FLOAT));
            vswap();
          }
#جے_انت
	}
        --vtop;
        vset_VT_CMP(op);
        ++vtop;
      } وإلا {
        tcc_error("unknown fp op %x!",op);
	أرجع;
      }
  }
  إذا(vtop[-1].r == VT_CMP)
    c1=15;
  وإلا {
    c1=vtop->r;
    إذا(r2&0x8)
      c1=vtop[-1].r;
    vtop[-1].r=get_reg_ex(RC_FLOAT,two2mask(vtop[-1].r,c1));
    c1=fpr(vtop[-1].r);
  }
  vtop--;
  o(x|(r<<16)|(c1<<12)|r2);
}
#جے_انت

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ST_FUNC فراغ gen_cvt_itof(صحيح t)
{
  uint32_t r, r2;
  صحيح bt;
  bt=vtop->type.t & VT_BTYPE;
  إذا(bt == VT_INT || bt == VT_SHORT || bt == VT_BYTE) {
#جے_بنا_تعریف TCC_ARM_VFP
    uint32_t dsize = 0;
#جے_انت
    r=intr(gv(RC_INT));
#جے_تعریف_شدہ TCC_ARM_VFP
    r2=vfpr(vtop->r=get_reg(RC_FLOAT));
    o(0xEE000A10|(r<<12)|(r2<<16)); /* fmsr */
    r2|=r2<<12;
    إذا(!(vtop->type.t & VT_UNSIGNED))
      r2|=0x80;                /* fuitoX -> fsituX */
    o(0xEEB80A40|r2|T2CPR(t)); /* fYitoX*/
#وإلا
    r2=fpr(vtop->r=get_reg(RC_FLOAT));
    إذا((t & VT_BTYPE) != VT_FLOAT)
      dsize=0x80;    /* flts -> fltd */
    o(0xEE000110|dsize|(r2<<16)|(r<<12)); /* flts */
    إذا((vtop->type.t & (VT_UNSIGNED|VT_BTYPE)) == (VT_UNSIGNED|VT_INT)) {
      uint32_t off = 0;
      o(0xE3500000|(r<<12));        /* cmp */
      r=fpr(get_reg(RC_FLOAT));
      إذا(آخری_itod_magic) {
	off=ind+8-آخری_itod_magic;
	off/=4;
	إذا(off>255)
	  off=0;
      }
      o(0xBD1F0100|(r<<12)|off);    /* ldflts */
      إذا(!off) {
        o(0xEA000000);              /* b */
        آخری_itod_magic=ind;
        o(0x4F800000);              /* 4294967296.0f */
      }
      o(0xBE000100|dsize|(r2<<16)|(r2<<12)|r); /* adflt */
    }
#جے_انت
    أرجع;
  } وإلا إذا(bt == VT_LLONG) {
    صحيح func;
    CType *func_type = 0;
    إذا((t & VT_BTYPE) == VT_FLOAT) {
      func_type = &func_float_type;
      إذا(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundisf;
      وإلا
        func=TOK___floatdisf;
    } وإلا إذا((t & VT_BTYPE) == VT_DOUBLE) {
      func_type = &func_double_type;
      إذا(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundidf;
      وإلا
        func=TOK___floatdidf;
#إذا LDOUBLE_ناپ != 8
    } وإلا إذا((t & VT_BTYPE) == VT_LDOUBLE) {
      func_type = &func_ldouble_type;
      إذا(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundixf;
      وإلا
        func=TOK___floatdixf;
#جے_انت
    }
    إذا(func_type) {
      vpushsym(func_type, external_helper_sym(func));
      vswap();
      gfunc_call(1);
      vpushi(0);
      vtop->r=TREG_F0;
      أرجع;
    }
  }
  tcc_error("unimplemented gen_cvt_itof %x!",vtop->type.t);
}

/* convert fp to int 't' type */
فراغ gen_cvt_ftoi(صحيح t)
{
  uint32_t r, r2;
  صحيح u, func = 0;
  u=t&VT_UNSIGNED;
  t&=VT_BTYPE;
  r2=vtop->type.t & VT_BTYPE;
  إذا(t==VT_INT) {
#جے_تعریف_شدہ TCC_ARM_VFP
    r=vfpr(gv(RC_FLOAT));
    u=u?0:0x10000;
    o(0xEEBC0AC0|(r<<12)|r|T2CPR(r2)|u); /* ftoXizY */
    r2=intr(vtop->r=get_reg(RC_INT));
    o(0xEE100A10|(r<<16)|(r2<<12));
    أرجع;
#وإلا
    إذا(u) {
      إذا(r2 == VT_FLOAT)
        func=TOK___fixunssfsi;
      وإلا إذا(r2 == VT_DOUBLE)
	func=TOK___fixunsdfsi;
#إذا LDOUBLE_ناپ != 8
      وإلا إذا(r2 == VT_LDOUBLE)
	func=TOK___fixunsxfsi;
#جے_انت
    } وإلا {
      r=fpr(gv(RC_FLOAT));
      r2=intr(vtop->r=get_reg(RC_INT));
      o(0xEE100170|(r2<<12)|r);
      أرجع;
    }
#جے_انت
  } وإلا إذا(t == VT_LLONG) { // unsigned handled in gen_cvt_ftoi1
    إذا(r2 == VT_FLOAT)
      func=TOK___fixsfdi;
    وإلا إذا(r2 == VT_DOUBLE)
      func=TOK___fixdfdi;
#إذا LDOUBLE_ناپ != 8
    وإلا إذا(r2 == VT_LDOUBLE)
      func=TOK___fixxfdi;
#جے_انت
  }
  إذا(func) {
    vpush_helper_func(func);
    vswap();
    gfunc_call(1);
    vpushi(0);
    إذا(t == VT_LLONG)
      vtop->r2 = REG_IRE2;
    vtop->r = REG_IRET;
    أرجع;
  }
  tcc_error("unimplemented gen_cvt_ftoi!");
}

/* convert from one floating point type to another */
فراغ gen_cvt_ftof(صحيح t)
{
#جے_تعریف_شدہ TCC_ARM_VFP
  uint32_t r = gv(RC_FLOAT);
  إذا(((vtop->type.t & VT_BTYPE) == VT_FLOAT) != ((t & VT_BTYPE) == VT_FLOAT)) {
    r = vfpr(r);
    o(0xEEB70AC0|(r<<12)|r|T2CPR(vtop->type.t));
  }
#وإلا
  /* all we have to do on i386 and FPA ARM is to put the float in a register */
  gv(RC_FLOAT);
#جے_انت
}

/* increment tcov counter */
ST_FUNC فراغ gen_increment_tcov (SValue *sv)
{
  صحيح r1, r2;

  vpushv(sv);
  vtop->r = r1 = get_reg(RC_INT);
  r2 = get_reg(RC_INT);
  o(0xE59F0000 | (intr(r1)<<12)); // ldr r1,[pc]
  o(0xEA000000); // b $+4
  greloc(cur_متن_section, sv->sym, ind, R_ARM_REL32);
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
فراغ ggoto(فراغ)
{
  gcall_or_jmp(1);
  vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC فراغ gen_vla_sp_save(صحيح addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    store(TREG_SP, &v);
}

/* Restore the SP from a location on the stack */
ST_FUNC فراغ gen_vla_sp_restore(صحيح addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    لدو(TREG_SP, &v);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align) {
    صحيح r;
#إذا defined(CONFIG_TCC_BCHECK)
    إذا (tcc_state->do_bounds_check)
        vpushv(vtop);
#جے_انت
    r = intr(gv(RC_INT));
#إذا defined(CONFIG_TCC_BCHECK)
    إذا (tcc_state->do_bounds_check)
        o(0xe2800001 | (r<<16)|(r<<12)); /* add r,r,#1 */
#جے_انت
    o(0xE04D0000|(r<<12)|r); /* sub r, sp, r */
#جے_تعریف_شدہ TCC_ARM_EABI
    إذا (align < 8)
        align = 8;
#وإلا
    إذا (align < 4)
        align = 4;
#جے_انت
    إذا (align & (align - 1))
        tcc_error("alignment is not a power of 2: %i", align);
    o(stuff_const(0xE3C0D000|(r<<16), align - 1)); /* bic sp, r, #align-1 */
    vpop();
#إذا defined(CONFIG_TCC_BCHECK)
    إذا (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R0;
        o(0xe1a0000d | (vtop->r << 12)); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_جوڑو_epilog = 1;
    }
#جے_انت
}

/* end of ARM code generator */
/*************************************************************/
#جے_انت
/*************************************************************/
