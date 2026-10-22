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

#ប្រសិនបើ defined(TCC_ARM_EABI) && !defined(TCC_ARM_VFP)
#error "Currently TinyCC only supports float computation with VFP instructions"
#endif

/* number of available registers */
#ifdef TCC_ARM_VFP
#define NB_REGS            13
#បើមិនដូច្នេះ
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
ga_nanaa {
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
#define PTR_SIZE 4

/* long double size and alignment, in bytes */
#ifdef TCC_ARM_VFP
#define LDOUBLE_SIZE  8
#endif

#ifndef LDOUBLE_SIZE
#define LDOUBLE_SIZE  8
#endif

#ifdef TCC_ARM_EABI
#define LDOUBLE_ALIGN 8
#បើមិនដូច្នេះ
#define LDOUBLE_ALIGN 4
#endif

#ប្រសិនបើ LDOUBLE_SIZE == 8
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#endif

/* maximum alignment (for aligned attribute support) */
#define MAX_ALIGN     8

#define CHAR_IS_UNSIGNED

#define ARM_SOFTFP_FLOAT 0
#define ARM_HARD_FLOAT 1

/******************************************************/
#បើមិនដូច្នេះ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#include "tcc.h"

ST_DATA const var_na * const target_machine_defs =
    "__arm__\0"
    "__arm\0"
    "arm\0"
    "__arm_elf__\0"
    "__arm_elf\0"
    "arm_elf\0"
    "__ARM_ARCH_4__\0"
    "__ARMEL__\0"
    "__APCS_32__\0"
#ប្រសិនបើ defined TCC_ARM_EABI
    "__ARM_EABI__\0"
#endif
    ;

ST_DATA const ចំនួនគត់ reg_classes[NB_REGS] = {
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

static ចំនួនគត់ float_abi;
static ចំនួនគត់ func_sub_sp_offset, last_itod_magic;
static ចំនួនគត់ leaffunc;

#ប្រសិនបើ defined(CONFIG_TCC_BCHECK)
static addr_t func_bound_offset;
static unsigned long func_bound_ind;
ST_DATA ចំនួនគត់ func_bound_add_epilog;
#endif

#ប្រសិនបើ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
static CType float_type, double_type, func_float_type, func_double_type;
ST_FUNC void arm_init(sa_nracanaa TCCState *s)
{
    float_type.t = VT_FLOAT;
    double_type.t = VT_DOUBLE;
    func_float_type.t = VT_FUNC;
    func_float_type.ref = sym_push(SYM_FIELD, &float_type, FUNC_CDECL, FUNC_OLD);
    func_double_type.t = VT_FUNC;
    func_double_type.ref = sym_push(SYM_FIELD, &double_type, FUNC_CDECL, FUNC_OLD);

    float_abi = s->float_abi;
#ifndef TCC_ARM_HARDFLOAT
// XXX: Works on OpenBSD
// # warning "soft float ABI currently not supported: default to softfp"
#endif
}
#បើមិនដូច្នេះ
#define func_float_type func_old_type
#define func_double_type func_old_type
#define func_ldouble_type func_old_type
ST_FUNC void arm_init(sa_nracanaa TCCState *s)
{
#ប្រសិនបើ 0
#ប្រសិនបើ !defined (TCC_ARM_VFP)
    tcc_warning("Support for FPA is deprecated and will be removed in next"
                " release");
#endif
#ប្រសិនបើ !defined (TCC_ARM_EABI)
    tcc_warning("Support for OABI is deprecated and will be removed in next"
                " release");
#endif
#endif
}
#endif

#define CHECK_R(r) ((r) >= TREG_R0 && (r) <= TREG_LR)

static ចំនួនគត់ two2mask(ចំនួនគត់ a,ចំនួនគត់ b) {
  ប្រសិនបើ (!CHECK_R(a) || !CHECK_R(b))
    tcc_error("compiler error! registers %i,%i is not valid",a,b);
  ត្រឡប់ (reg_classes[a]|reg_classes[b])&~(RC_INT|RC_FLOAT);
}

static ចំនួនគត់ regmask(ចំនួនគត់ r) {
  ប្រសិនបើ (!CHECK_R(r))
    tcc_error("compiler error! register %i is not valid",r);
  ត្រឡប់ reg_classes[r]&~(RC_INT|RC_FLOAT);
}

/******************************************************/

void o(uint32_t i)
{
  /* this is a good place to start adding big-endian support*/
  ចំនួនគត់ ind1;
  ប្រសិនបើ (nocode_wanted)
    ត្រឡប់;
  ind1 = ind + 4;
  ប្រសិនបើ (!cur_text_section)
    tcc_error("compiler error! This happens f.ex. if the compiler\n"
         "can't evaluate constant expressions outside of a function.");
  ប្រសិនបើ (ind1 > cur_text_section->data_allocated)
    section_realloc(cur_text_section, ind1);
  cur_text_section->data[ind++] = i&255;
  i>>=8;
  cur_text_section->data[ind++] = i&255;
  i>>=8;
  cur_text_section->data[ind++] = i&255;
  i>>=8;
  cur_text_section->data[ind++] = i;
}

static uint32_t stuff_const(uint32_t op, uint32_t c)
{
  ចំនួនគត់ try_neg=0;
  uint32_t nc = 0, negop = 0;

  switch(op&0x1F00000)
  {
    pak_sa 0x800000: //add
    pak_sa 0x400000: //sub
      try_neg=1;
      negop=op^0xC00000;
      nc=-c;
      bha_nga;
    pak_sa 0x1A00000: //mov
    pak_sa 0x1E00000: //mvn
      try_neg=1;
      negop=op^0x400000;
      nc=~c;
      bha_nga;
    pak_sa 0x200000: //xor
      ប្រសិនបើ(c==~0)
	ត្រឡប់ (op&0xF010F000)|((op>>16)&0xF)|0x1E00000;
      bha_nga;
    pak_sa 0x0: //and
      ប្រសិនបើ(c==~0)
	ត្រឡប់ (op&0xF010F000)|((op>>16)&0xF)|0x1A00000;
    pak_sa 0x1C00000: //bic
      try_neg=1;
      negop=op^0x1C00000;
      nc=~c;
      bha_nga;
    pak_sa 0x1800000: //orr
      ប្រសិនបើ(c==~0)
	ត្រឡប់ (op&0xFFF0FFFF)|0x1E00000;
      bha_nga;
  }
  do {
    uint32_t m;
    ចំនួនគត់ i;
    ប្រសិនបើ(c<256) /* catch undefined <<32 */
      ត្រឡប់ op|c;
    សម្រាប់(i=2;i<32;i+=2) {
      m=(0xffu>>i)|(0xffu<<(32-i));
      ប្រសិនបើ(!(c&~m))
	ត្រឡប់ op|(i<<7)|(c<<i)|(c>>(32-i));
    }
    op=negop;
    c=nc;
  } ខណៈពេល(try_neg--);
  ត្រឡប់ 0;
}


//only add,sub
void stuff_const_harder(uint32_t op, uint32_t v) {
  uint32_t x;
  x=stuff_const(op,v);
  ប្រសិនបើ(x)
    o(x);
  បើមិនដូច្នេះ {
    uint32_t a[16], nv, no, o2, n2;
    ចំនួនគត់ i,j,k;
    a[0]=0xff;
    o2=(op&0xfff0ffff)|((op&0xf000)<<4);;
    សម្រាប់(i=1;i<16;i++)
      a[i]=(a[i-1]>>2)|(a[i-1]<<30);
    សម្រាប់(i=0;i<12;i++)
      សម្រាប់(j=i<4?i+12:15;j>=i+4;j--)
	ប្រសិនបើ((v&(a[i]|a[j]))==v) {
	  o(stuff_const(op,v&a[i]));
	  o(stuff_const(o2,v&a[j]));
	  ត្រឡប់;
	}
    no=op^0xC00000;
    n2=o2^0xC00000;
    nv=-v;
    សម្រាប់(i=0;i<12;i++)
      សម្រាប់(j=i<4?i+12:15;j>=i+4;j--)
	ប្រសិនបើ((nv&(a[i]|a[j]))==nv) {
	  o(stuff_const(no,nv&a[i]));
	  o(stuff_const(n2,nv&a[j]));
	  ត្រឡប់;
	}
    សម្រាប់(i=0;i<8;i++)
      សម្រាប់(j=i+4;j<12;j++)
	សម្រាប់(k=i<4?i+12:15;k>=j+4;k--)
	  ប្រសិនបើ((v&(a[i]|a[j]|a[k]))==v) {
	    o(stuff_const(op,v&a[i]));
	    o(stuff_const(o2,v&a[j]));
	    o(stuff_const(o2,v&a[k]));
	    ត្រឡប់;
	  }
    no=op^0xC00000;
    nv=-v;
    សម្រាប់(i=0;i<8;i++)
      សម្រាប់(j=i+4;j<12;j++)
	សម្រាប់(k=i<4?i+12:15;k>=j+4;k--)
	  ប្រសិនបើ((nv&(a[i]|a[j]|a[k]))==nv) {
	    o(stuff_const(no,nv&a[i]));
	    o(stuff_const(n2,nv&a[j]));
	    o(stuff_const(n2,nv&a[k]));
	    ត្រឡប់;
	  }
    o(stuff_const(op,v&a[0]));
    o(stuff_const(o2,v&a[4]));
    o(stuff_const(o2,v&a[8]));
    o(stuff_const(o2,v&a[12]));
  }
}

uint32_t encbranch(ចំនួនគត់ pos, ចំនួនគត់ addr, ចំនួនគត់ fail)
{
  addr-=pos+8;
  addr/=4;
  ប្រសិនបើ(addr>=0x1000000 || addr<-0x1000000) {
    ប្រសិនបើ(fail)
      tcc_error("FIXME: function bigger than 32MB");
    ត្រឡប់ 0;
  }
  ត្រឡប់ 0x0A000000|(addr&0xffffff);
}

ចំនួនគត់ decbranch(ចំនួនគត់ pos)
{
  ចំនួនគត់ x;
  x=*(uint32_t *)(cur_text_section->data + pos);
  x&=0x00ffffff;
  ប្រសិនបើ(x&0x800000)
    x-=0x1000000;
  ត្រឡប់ x*4+pos+8;
}

/* output a symbol and patch all calls to it */
void gsym_addr(ចំនួនគត់ t, ចំនួនគត់ a)
{
  uint32_t *x;
  ចំនួនគត់ lt;
  ខណៈពេល(t) {
    x=(uint32_t *)(cur_text_section->data + t);
    t=decbranch(lt=t);
    ប្រសិនបើ(a==lt+4)
      *x=0xE1A00000; // nop
    បើមិនដូច្នេះ {
      *x &= 0xff000000;
      *x |= encbranch(lt,a,1);
    }
  }
}

#ifdef TCC_ARM_VFP
static uint32_t vfpr(ចំនួនគត់ r)
{
  ប្រសិនបើ(r<TREG_F0 || r>TREG_F7)
    tcc_error("compiler error! register %i is no vfp register",r);
  ត្រឡប់ r - TREG_F0;
}
#បើមិនដូច្នេះ
static uint32_t fpr(ចំនួនគត់ r)
{
  ប្រសិនបើ(r<TREG_F0 || r>TREG_F3)
    tcc_error("compiler error! register %i is no fpa register",r);
  ត្រឡប់ r - TREG_F0;
}
#endif

static uint32_t intr(ចំនួនគត់ r)
{
  ប្រសិនបើ(r == TREG_R12)
    ត្រឡប់ 12;
  ប្រសិនបើ(r >= TREG_R0 && r <= TREG_R3)
    ត្រឡប់ r - TREG_R0;
  ប្រសិនបើ (!(r >= TREG_SP && r <= TREG_LR))
    tcc_error("compiler error! register %i is no int register",r);
  ត្រឡប់ r + (13 - TREG_SP);
}

static void calcaddr(uint32_t *base, ចំនួនគត់ *off, ចំនួនគត់ *sgn, ចំនួនគត់ maxoff, unsigned shift)
{
  ប្រសិនបើ(*off>maxoff || *off&((1<<shift)-1)) {
    uint32_t x, y;
    x=0xE280E000;
    ប្រសិនបើ(*sgn)
      x=0xE240E000;
    x|=(*base)<<16;
    *base=14; // lr
    y=stuff_const(x,*off&~maxoff);
    ប្រសិនបើ(y) {
      o(y);
      *off&=maxoff;
      ត្រឡប់;
    }
    y=stuff_const(x,(*off+maxoff)&~maxoff);
    ប្រសិនបើ(y) {
      o(y);
      *sgn=!*sgn;
      *off=((*off+maxoff)&~maxoff)-*off;
      ត្រឡប់;
    }
    stuff_const_harder(x,*off&~maxoff);
    *off&=maxoff;
  }
}

static uint32_t mapcc(ចំនួនគត់ cc)
{
  switch(cc)
  {
    pak_sa TOK_ULT:
      ត្រឡប់ 0x30000000; /* CC/LO */
    pak_sa TOK_UGE:
      ត្រឡប់ 0x20000000; /* CS/HS */
    pak_sa TOK_EQ:
      ត្រឡប់ 0x00000000; /* EQ */
    pak_sa TOK_NE:
      ត្រឡប់ 0x10000000; /* NE */
    pak_sa TOK_ULE:
      ត្រឡប់ 0x90000000; /* LS */
    pak_sa TOK_UGT:
      ត្រឡប់ 0x80000000; /* HI */
    pak_sa TOK_Nset:
      ត្រឡប់ 0x40000000; /* MI */
    pak_sa TOK_Nclear:
      ត្រឡប់ 0x50000000; /* PL */
    pak_sa TOK_LT:
      ត្រឡប់ 0xB0000000; /* LT */
    pak_sa TOK_GE:
      ត្រឡប់ 0xA0000000; /* GE */
    pak_sa TOK_LE:
      ត្រឡប់ 0xD0000000; /* LE */
    pak_sa TOK_GT:
      ត្រឡប់ 0xC0000000; /* GT */
  }
  tcc_error("unexpected condition code");
  ត្រឡប់ 0xE0000000; /* AL */
}

static ចំនួនគត់ negcc(ចំនួនគត់ cc)
{
  switch(cc)
  {
    pak_sa TOK_ULT:
      ត្រឡប់ TOK_UGE;
    pak_sa TOK_UGE:
      ត្រឡប់ TOK_ULT;
    pak_sa TOK_EQ:
      ត្រឡប់ TOK_NE;
    pak_sa TOK_NE:
      ត្រឡប់ TOK_EQ;
    pak_sa TOK_ULE:
      ត្រឡប់ TOK_UGT;
    pak_sa TOK_UGT:
      ត្រឡប់ TOK_ULE;
    pak_sa TOK_Nset:
      ត្រឡប់ TOK_Nclear;
    pak_sa TOK_Nclear:
      ត្រឡប់ TOK_Nset;
    pak_sa TOK_LT:
      ត្រឡប់ TOK_GE;
    pak_sa TOK_GE:
      ត្រឡប់ TOK_LT;
    pak_sa TOK_LE:
      ត្រឡប់ TOK_GT;
    pak_sa TOK_GT:
      ត្រឡប់ TOK_LE;
  }
  tcc_error("unexpected condition code");
  ត្រឡប់ TOK_NE;
}

/* Load value into register r.
   Use relative/got addressing to avoid setting DT_TEXTREL */
static void load_value(SValue *sv, ចំនួនគត់ r)
{
#ប្រសិនបើ CONFIG_TCC_CPUVER >= 7
    ប្រសិនបើ (!(sv->r & VT_SYM)) {
        unsigned x=sv->c.i;
        o(0xE3000000|intr(r)<<12|(x&0xFFF)|(x<<4&0xF0000)); /* movw rx,#x(lo) */
        ប្រសិនបើ (x&0xFFFF0000)
          o(0xE3400000|intr(r)<<12|(x>>16&0xFFF)|(x>>12&0xF0000)); /* movt rx,#x(hi) */
        ត្រឡប់;
    }
#endif
    o(0xE59F0000|(intr(r)<<12)); /* ldr r, [pc] */
    o(0xEA000000); /* b $+4 */
#ifndef CONFIG_TCC_PIC
    ប្រសិនបើ(sv->r & VT_SYM)
        greloc(cur_text_section, sv->sym, ind, R_ARM_ABS32);
    o(sv->c.i);
#បើមិនដូច្នេះ
    ប្រសិនបើ(sv->r & VT_SYM) {
	ប្រសិនបើ (sv->sym->type.t & VT_STATIC) {
            greloc(cur_text_section, sv->sym, ind, R_ARM_REL32);
            o(sv->c.i - 12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
        }
        បើមិនដូច្នេះ {
            greloc(cur_text_section, sv->sym, ind, R_ARM_GOT_PREL);
            o(-12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
            o(0xe5900000 | (intr(r)<<12) | (intr(r)<<16));  // ldr rx,[rx]
            ប្រសិនបើ (sv->c.i)
              stuff_const_harder(0xe2800000 | (intr(r)<<12) | (intr(r)<<16),
                                 sv->c.i);
        }
    }
    បើមិនដូច្នេះ
        o(sv->c.i);
#endif
}

/* load 'r' from value 'sv' */
void load(ចំនួនគត់ r, SValue *sv)
{
  ចំនួនគត់ v, ft, fc, fr, sign;
  uint32_t op, base;
  SValue v1;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  ប្រសិនបើ(fc>=0)
    sign=0;
  បើមិនដូច្នេះ {
    sign=1;
    fc=-(unsigned)fc;
  }

  v = fr & VT_VALMASK;
  ប្រសិនបើ (fr & VT_LVAL) {

    ប្រសិនបើ ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe510e000; /* ldr r, [lr, #0] */
        greloca(cur_text_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        ត្រឡប់;
    }

    base = 0xB; // fp
    ប្រសិនបើ(v == VT_LLOCAL) {
      v1.type.t = VT_PTR;
      v1.r = VT_LOCAL | VT_LVAL;
      v1.c.i = sv->c.i;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } បើមិនដូច្នេះ ប្រសិនបើ(v == VT_CONST) {
      v1.type.t = VT_PTR;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } បើមិនដូច្នេះ ប្រសិនបើ(v < VT_CONST) {
      base=intr(v);
      fc=sign=0;
      v=VT_LOCAL;
    }
    ប្រសិនបើ(v == VT_LOCAL) {
      ប្រសិនបើ(is_float(ft)) {
	calcaddr(&base,&fc,&sign,1020,2);
#ifdef TCC_ARM_VFP
        op=0xED100A00; /* flds */
        ប្រសិនបើ(!sign)
          op|=0x800000;
        ប្រសិនបើ ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* flds -> fldd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(base<<16));
#បើមិនដូច្នេះ
	op=0xED100100;
	ប្រសិនបើ(!sign)
	  op|=0x800000;
	ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#ប្រសិនបើ LDOUBLE_SIZE != 8
	បើមិនដូច្នេះ ប្រសិនបើ ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#endif
	o(op|(fpr(r)<<12)|(fc>>2)|(base<<16));
#endif
      } បើមិនដូច្នេះ ប្រសិនបើ((ft & (VT_BTYPE|VT_UNSIGNED)) == VT_BYTE
                || (ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&base,&fc,&sign,255,0);
	op=0xE1500090;
	ប្រសិនបើ ((ft & VT_BTYPE) == VT_SHORT)
	  op|=0x20;
	ប្រសិនបើ ((ft & VT_UNSIGNED) == 0)
	  op|=0x40;
	ប្រសិនបើ(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(base<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } បើមិនដូច្នេះ {
	calcaddr(&base,&fc,&sign,4095,0);
	op=0xE5100000;
	ប្រសិនបើ(!sign)
	  op|=0x800000;
        ប្រសិនបើ ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(base<<16));
      }
      ត្រឡប់;
    }
  } បើមិនដូច្នេះ {
    ប្រសិនបើ (v == VT_CONST) {
      op=stuff_const(0xE3A00000|(intr(r)<<12),sv->c.i);
      ប្រសិនបើ (fr & VT_SYM || !op)
	load_value(sv, r);
      បើមិនដូច្នេះ
        o(op);
      ត្រឡប់;
    } បើមិនដូច្នេះ ប្រសិនបើ (v == VT_LOCAL) {
      op=stuff_const(0xE28B0000|(intr(r)<<12),sv->c.i);
      ប្រសិនបើ (fr & VT_SYM || !op) {
	load_value(sv, r);
	o(0xE08B0000|(intr(r)<<12)|intr(r));
      } បើមិនដូច្នេះ
	o(op);
      ត្រឡប់;
    } បើមិនដូច្នេះ ប្រសិនបើ(v == VT_CMP) {
      o(mapcc(sv->c.i)|0x3A00001|(intr(r)<<12));
      o(mapcc(negcc(sv->c.i))|0x3A00000|(intr(r)<<12));
      ត្រឡប់;
    } បើមិនដូច្នេះ ប្រសិនបើ (v == VT_JMP || v == VT_JMPI) {
      ចំនួនគត់ t;
      t = v & 1;
      o(0xE3A00000|(intr(r)<<12)|t);
      o(0xEA000000);
      gsym(sv->c.i);
      o(0xE3A00000|(intr(r)<<12)|(t^1));
      ត្រឡប់;
    } បើមិនដូច្នេះ ប្រសិនបើ (v < VT_CONST) {
      ប្រសិនបើ(is_float(ft))
#ifdef TCC_ARM_VFP
        o(0xEEB00A40|(vfpr(r)<<12)|vfpr(v)|T2CPR(ft)); /* fcpyX */
#បើមិនដូច្នេះ
	o(0xEE008180|(fpr(r)<<12)|fpr(v));
#endif
      បើមិនដូច្នេះ
	o(0xE1A00000|(intr(r)<<12)|intr(v));
      ត្រឡប់;
    }
  }
  tcc_error("load unimplemented!");
}

/* store register 'r' in lvalue 'v' */
void store(ចំនួនគត់ r, SValue *sv)
{
  SValue v1;
  ចំនួនគត់ v, ft, fc, fr, sign;
  uint32_t op, base;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  ប្រសិនបើ(fc>=0)
    sign=0;
  បើមិនដូច្នេះ {
    sign=1;
    fc=-fc;
  }

  v = fr & VT_VALMASK;
  ប្រសិនបើ (fr & VT_LVAL || fr == VT_LOCAL) {

    ប្រសិនបើ ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe500e000; /* str r, [lr, #0] */
        greloca(cur_text_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        ត្រឡប់;
    }

    base = 0xb; /* fp */
    ប្រសិនបើ(v < VT_CONST) {
      base=intr(v);
      v=VT_LOCAL;
      fc=sign=0;
    } បើមិនដូច្នេះ ប្រសិនបើ(v == VT_CONST) {
      v1.type.t = ft;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    }
    ប្រសិនបើ(v == VT_LOCAL) {
       ប្រសិនបើ(is_float(ft)) {
	calcaddr(&base,&fc,&sign,1020,2);
#ifdef TCC_ARM_VFP
        op=0xED000A00; /* fsts */
        ប្រសិនបើ(!sign)
          op|=0x800000;
        ប្រសិនបើ ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* fsts -> fstd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(base<<16));
#បើមិនដូច្នេះ
	op=0xED000100;
	ប្រសិនបើ(!sign)
	  op|=0x800000;
	ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#ប្រសិនបើ LDOUBLE_SIZE != 8
	បើមិនដូច្នេះ ប្រសិនបើ ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#endif
	o(op|(fpr(r)<<12)|(fc>>2)|(base<<16));
#endif
	ត្រឡប់;
      } បើមិនដូច្នេះ ប្រសិនបើ((ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&base,&fc,&sign,255,0);
	op=0xE14000B0;
	ប្រសិនបើ(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(base<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } បើមិនដូច្នេះ {
	calcaddr(&base,&fc,&sign,4095,0);
	op=0xE5000000;
	ប្រសិនបើ(!sign)
	  op|=0x800000;
        ប្រសិនបើ ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(base<<16));
      }
      ត្រឡប់;
    }
  }
  tcc_error("store unimplemented");
}

static void gadd_sp(ចំនួនគត់ val)
{
  stuff_const_harder(0xE28DD000,val);
}

/* 'is_jmp' is '1' if it is a jump */
static void gcall_or_jmp(ចំនួនគត់ is_jmp)
{
  ចំនួនគត់ r;
  uint32_t x;
  ប្រសិនបើ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
    /* constant case */
    ប្រសិនបើ(vtop->r & VT_SYM){
	x=encbranch(ind,ind+vtop->c.i,0);
	ប្រសិនបើ(x) {
	    /* relocation case */
	    greloc(cur_text_section, vtop->sym, ind, R_ARM_PC24);
	    o(x|(is_jmp?0xE0000000:0xE1000000));
	} បើមិនដូច្នេះ {
	    r = TREG_LR;
	    load_value(vtop, r);
	    ប្រសិនបើ(is_jmp)
	        o(0xE1A0F000 | intr(r)); // mov pc, r
	    បើមិនដូច្នេះ
		o(0xe12fff30 | intr(r)); // blx r
	}
     }បើមិនដូច្នេះ{
	ប្រសិនបើ(!is_jmp)
	    o(0xE28FE004); // add lr,pc,#4
	o(0xE51FF004);   // ldr pc,[pc,#-4]
	o(vtop->c.i);
     }
  } បើមិនដូច្នេះ {
    /* otherwise, indirect call */
#ifdef CONFIG_TCC_BCHECK
    vtop->r &= ~VT_MUSTBOUND;
#endif
    r = gv(RC_INT);
    ប្រសិនបើ(!is_jmp)
      o(0xE1A0E00F);       // mov lr,pc
    o(0xE1A0F000|intr(r)); // mov pc,r
  }
}

#ប្រសិនបើ defined(CONFIG_TCC_BCHECK)

static void gen_bounds_call(ចំនួនគត់ v)
{
    Sym *sym = external_helper_sym(v);

    greloc(cur_text_section, sym, ind, R_ARM_PC24);
    o(0xebfffffe);
}

static void gen_bounds_prolog(void)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->data_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0xe1a00000);  /* ld r0,lbounds_section->data_offset */
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);  /* call __bound_local_new */
}

static void gen_bounds_epilog(void)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_data;
    ចំនួនគត់ offset_modified = func_bound_offset != lbounds_section->data_offset;

    ប្រសិនបើ (!offset_modified && !func_bound_add_epilog)
        ត្រឡប់;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, parimaa_na(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    ប្រសិនបើ (offset_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        o(0xe59f0000);  /* ldr r0, [pc] */
        o(0xea000000);  /* b $+4 */
        greloc(cur_text_section, sym_data, ind, R_ARM_REL32);
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
    greloc(cur_text_section, sym_data, ind, R_ARM_REL32);
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
static ចំនួនគត់ is_hgen_float_aggr(CType *type)
{
  ប្រសិនបើ ((type->t & VT_BTYPE) == VT_STRUCT) {
    sa_nracanaa Sym *ref;
    ចំនួនគត់ btype, nb_fields = 0;

    ref = type->ref->next;
    ប្រសិនបើ (ref) {
      btype = ref->type.t & VT_BTYPE;
      ប្រសិនបើ (btype == VT_FLOAT || btype == VT_DOUBLE) {
        សម្រាប់(; ref && btype == (ref->type.t & VT_BTYPE); ref = ref->next, nb_fields++)
            ;
        ត្រឡប់ !ref && nb_fields <= 4;
      }
    }
  }
  ត្រឡប់ 0;
}

sa_nracanaa avail_regs {
  signed var_na avail[3]; /* 3 holes max with only float and double alignments */
  ចំនួនគត់ first_hole; /* first available hole */
  ចំនួនគត់ last_hole; /* last available hole (none if equal to first_hole) */
  ចំនួនគត់ first_free_reg; /* next free register in the sequence, hole excluded */
};

/* Find suitable registers for a VFP Co-Processor Register Candidate (VFP CPRC
   param) according to the rules described in the procedure call standard for
   the ARM architecture (AAPCS). If found, the registers are assigned to this
   VFP CPRC parameter. Registers are allocated in sequence unless a hole exists
   and the parameter is a single float.

   avregs: opaque structure to keep track of available VFP co-processor regs
   align: alignment constraints for the param, as returned by type_size()
   size: size of the parameter, as returned by type_size() */
ចំនួនគត់ assign_vfpreg(sa_nracanaa avail_regs *avregs, ចំនួនគត់ align, ចំនួនគត់ size)
{
  ចំនួនគត់ first_reg = 0;

  ប្រសិនបើ (avregs->first_free_reg == -1)
    ត្រឡប់ -1;
  ប្រសិនបើ (align >> 3) { /* double alignment */
    first_reg = avregs->first_free_reg;
    /* alignment constraint not respected so use next reg and record hole */
    ប្រសិនបើ (first_reg & 1)
      avregs->avail[avregs->last_hole++] = first_reg++;
  } បើមិនដូច្នេះ { /* no special alignment (float or array of float) */
    /* if single float and a hole is available, assign the param to it */
    ប្រសិនបើ (size == 4 && avregs->first_hole != avregs->last_hole)
      ត្រឡប់ avregs->avail[avregs->first_hole++];
    បើមិនដូច្នេះ
      first_reg = avregs->first_free_reg;
  }
  ប្រសិនបើ (first_reg + size / 4 <= 16) {
    avregs->first_free_reg = first_reg + size / 4;
    ត្រឡប់ first_reg;
  }
  avregs->first_free_reg = -1;
  ត្រឡប់ -1;
}

/* Returns whether all params need to be passed in core registers or not.
   This is the case for function part of the runtime ABI. */
ចំនួនគត់ floats_in_core_regs(SValue *sval)
{
  ប្រសិនបើ (!sval->sym)
    ត្រឡប់ 0;

  switch (sval->sym->v) {
    pak_sa TOK___floatundisf:
    pak_sa TOK___floatundidf:
    pak_sa TOK___fixunssfdi:
    pak_sa TOK___fixunsdfdi:
#ifndef TCC_ARM_VFP
    pak_sa TOK___fixunsxfdi:
#endif
    pak_sa TOK___floatdisf:
    pak_sa TOK___floatdidf:
    pak_sa TOK___fixsfdi:
    pak_sa TOK___fixdfdi:
      ត្រឡប់ 1;

    default:
      ត្រឡប់ 0;
  }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ចំនួនគត់ gfunc_sret(CType *vt, ចំនួនគត់ variadic, CType *ret, ចំនួនគត់ *ret_align, ចំនួនគត់ *regsize) {
#ifdef TCC_ARM_EABI
    ចំនួនគត់ size, align;
    size = type_size(vt, &align);
    ប្រសិនបើ (float_abi == ARM_HARD_FLOAT && !variadic &&
        (is_float(vt->t) || is_hgen_float_aggr(vt))) {
        *ret_align = 8;
	*regsize = 8;
        ret->ref = NULL;
        ret->t = VT_DOUBLE;
        ត្រឡប់ (size + 7) >> 3;
    } បើមិនដូច្នេះ ប្រសិនបើ (size > 0 && size <= 4) {
        *ret_align = 4;
	*regsize = 4;
        ret->ref = NULL;
        ret->t = VT_INT;
        ត្រឡប់ 1;
    } បើមិនដូច្នេះ
        ត្រឡប់ 0;
#បើមិនដូច្នេះ
    ត្រឡប់ 0;
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
ga_nanaa reg_class {
	STACK_CLASS = 0,
	CORE_STRUCT_CLASS,
	VFP_CLASS,
	VFP_STRUCT_CLASS,
	CORE_CLASS,
	NB_CLASSES
};

sa_nracanaa param_plan {
    ចំនួនគត់ start; /* first reg or addr used depending on the class */
    ចំនួនគត់ end; /* last reg used or next free addr depending on the class */
    SValue *sval; /* pointer to SValue on the value stack */
    sa_nracanaa param_plan *prev; /*  previous element in this class */
};

sa_nracanaa plan {
    sa_nracanaa param_plan *pplans; /* array of all the param plans */
    sa_nracanaa param_plan *clsplans[NB_CLASSES]; /* per class lists of param plans */
    ចំនួនគត់ nb_plans;
};

static void add_param_plan(sa_nracanaa plan* plan, ចំនួនគត់ cls, ចំនួនគត់ start, ចំនួនគត់ end, SValue *v)
{
    sa_nracanaa param_plan *p = &plan->pplans[plan->nb_plans++];
    p->prev = plan->clsplans[cls];
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
static ចំនួនគត់ assign_regs(ចំនួនគត់ nb_args, ចំនួនគត់ float_abi, sa_nracanaa plan *plan, ចំនួនគត់ *todo)
{
  ចំនួនគត់ i, size, align;
  ចំនួនគត់ ncrn /* next core register number */, nsaa /* next stacked argument address*/;
  sa_nracanaa avail_regs avregs = {{0}};

  ncrn = nsaa = 0;
  *todo = 0;

  សម្រាប់(i = nb_args; i-- ;) {
    ចំនួនគត់ j, start_vfpreg = 0;
    CType type = vtop[-i].type;
    type.t &= ~VT_ARRAY;
    size = type_size(&type, &align);
    size = (size + 3) & ~3;
    align = (align + 3) & ~3;
    switch(vtop[-i].type.t & VT_BTYPE) {
      pak_sa VT_STRUCT:
      pak_sa VT_FLOAT:
      pak_sa VT_DOUBLE:
      pak_sa VT_LDOUBLE:
      ប្រសិនបើ (float_abi == ARM_HARD_FLOAT) {
        ចំនួនគត់ is_hfa = 0; /* Homogeneous float aggregate */

        ប្រសិនបើ (is_float(vtop[-i].type.t)
            || (is_hfa = is_hgen_float_aggr(&vtop[-i].type))) {
          ចំនួនគត់ end_vfpreg;

          start_vfpreg = assign_vfpreg(&avregs, align, size);
          end_vfpreg = start_vfpreg + ((size - 1) >> 2);
          ប្រសិនបើ (start_vfpreg >= 0) {
            add_param_plan(plan, is_hfa ? VFP_STRUCT_CLASS : VFP_CLASS,
                start_vfpreg, end_vfpreg, &vtop[-i]);
            continue;
          } បើមិនដូច្នេះ
            bha_nga;
        }
      }
      ncrn = (ncrn + (align-1)/4) & ~((align/4) - 1);
      ប្រសិនបើ (ncrn + size/4 <= 4 || (ncrn < 4 && start_vfpreg != -1)) {
        /* The parameter is allocated both in core register and on stack. As
	 * such, it can be of either class: it would either be the last of
	 * CORE_STRUCT_CLASS or the first of STACK_CLASS. */
        សម្រាប់ (j = ncrn; j < 4 && j < ncrn + size / 4; j++)
          *todo|=(1<<j);
        add_param_plan(plan, CORE_STRUCT_CLASS, ncrn, j, &vtop[-i]);
        ncrn += size/4;
        ប្រសិនបើ (ncrn > 4)
          nsaa = (ncrn - 4) * 4;
      } បើមិនដូច្នេះ {
        ncrn = 4;
        bha_nga;
      }
      continue;
      default:
      ប្រសិនបើ (ncrn < 4) {
        ចំនួនគត់ is_long = (vtop[-i].type.t & VT_BTYPE) == VT_LLONG;

        ប្រសិនបើ (is_long) {
          ncrn = (ncrn + 1) & -2;
          ប្រសិនបើ (ncrn == 4)
            bha_nga;
        }
        add_param_plan(plan, CORE_CLASS, ncrn, ncrn + is_long, &vtop[-i]);
        ncrn += 1 + is_long;
        continue;
      }
    }
    nsaa = (nsaa + (align - 1)) & ~(align - 1);
    add_param_plan(plan, STACK_CLASS, nsaa, nsaa + size, &vtop[-i]);
    nsaa += size; /* size already rounded up before */
  }
  ត្រឡប់ nsaa;
}

/* Copy parameters to their final destination (core reg, VFP reg or stack) for
   function call.

   nb_args: number of parameters the function take
   plan: the overall assignment plan for parameters
   todo: a bitmap indicating what core reg will hold a parameter

   Returns the number of SValue added by this function on the value stack */
static ចំនួនគត់ copy_params(ចំនួនគត់ nb_args, sa_nracanaa plan *plan, ចំនួនគត់ todo)
{
  ចំនួនគត់ size, align, r, i, nb_extra_sval = 0;
  sa_nracanaa param_plan *pplan;
  ចំនួនគត់ pass = 0;

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
  សម្រាប់(i = 0; i < NB_CLASSES; i++) {
    សម្រាប់(pplan = plan->clsplans[i]; pplan; pplan = pplan->prev) {

      ប្រសិនបើ (pass
          && (i != CORE_CLASS || pplan->sval->r < VT_CONST))
        continue;

      vpushv(pplan->sval);
      pplan->sval->r = pplan->sval->r2 = VT_CONST; /* disable entry */
      switch(i) {
        pak_sa STACK_CLASS:
        pak_sa CORE_STRUCT_CLASS:
        pak_sa VFP_STRUCT_CLASS:
          ប្រសិនបើ ((pplan->sval->type.t & VT_BTYPE) == VT_STRUCT) {
            ចំនួនគត់ padding = 0;
            size = type_size(&pplan->sval->type, &align);
            /* align to stack align size */
            size = (size + 3) & ~3;
            ប្រសិនបើ (i == STACK_CLASS && pplan->prev)
              padding = pplan->start - pplan->prev->end;
            size += padding; /* Add padding if any */
            /* allocate the necessary size on stack */
            gadd_sp(-size);
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
            ប្រសិនបើ (i == VFP_STRUCT_CLASS) {
              ចំនួនគត់ first = pplan->start, nb = pplan->end - first + 1;
              /* vpop.32 {pplan->start, ..., pplan->end} */
              o(0xECBD0A00|(first&1)<<22|(first>>1)<<12|nb);
              /* No need to write the register used to a SValue since VFP regs
                 cannot be used for gcall_or_jmp */
            }
          } បើមិនដូច្នេះ {
            ប្រសិនបើ (is_float(pplan->sval->type.t)) {
#ifdef TCC_ARM_VFP
              r = vfpr(gv(RC_FLOAT)) << 12;
              ប្រសិនបើ ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                size = 4;
              បើមិនដូច្នេះ {
                size = 8;
                r |= 0x101; /* vpush.32 -> vpush.64 */
              }
              o(0xED2D0A01 + r); /* vpush */
#បើមិនដូច្នេះ
              r = fpr(gv(RC_FLOAT)) << 12;
              ប្រសិនបើ ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                size = 4;
              បើមិនដូច្នេះ ប្រសិនបើ ((pplan->sval->type.t & VT_BTYPE) == VT_DOUBLE)
                size = 8;
              បើមិនដូច្នេះ
                size = LDOUBLE_SIZE;
              ប្រសិនបើ (size == 12)
                r |= 0x400000;
              បើមិនដូច្នេះ ប្រសិនបើ(size == 8)
                r|=0x8000;

              o(0xED2D0100|r|(size>>2)); /* some kind of vpush for FPA */
#endif
            } បើមិនដូច្នេះ {
              /* simple type (currently always same size) */
              /* XXX: implicit cast ? */
              size=4;
              ប្រសិនបើ ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
                lexpand();
                size = 8;
                r = gv(RC_INT);
                o(0xE52D0004|(intr(r)<<12)); /* push r */
                vtop--;
              }
              r = gv(RC_INT);
              o(0xE52D0004|(intr(r)<<12)); /* push r */
            }
            ប្រសិនបើ (i == STACK_CLASS && pplan->prev)
              gadd_sp(pplan->prev->end - pplan->start); /* Add padding if any */
          }
          bha_nga;

        pak_sa VFP_CLASS:
          gv(regmask(TREG_F0 + (pplan->start >> 1)));
          ប្រសិនបើ (pplan->start & 1) { /* Must be in upper part of double register */
            o(0xEEF00A40|((pplan->start>>1)<<12)|(pplan->start>>1)); /* vmov.f32 s(n+1), sn */
            vtop->r = VT_CONST; /* avoid being saved on stack by gv for next float */
          }
          bha_nga;

        pak_sa CORE_CLASS:
          ប្រសិនបើ ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
            lexpand();
            gv(regmask(pplan->end));
            pplan->sval->r2 = vtop->r;
            vtop--;
          }
          gv(regmask(pplan->start));
          /* Mark register as used so that gcall_or_jmp use another one
             (regs >=4 are free as never used to pass parameters) */
          pplan->sval->r = vtop->r;
          bha_nga;
      }
      vtop--;
    }
  }

  /* second pass to restore registers that were saved on stack by accident.
     Maybe redundant after the "lvalue_save" patch in tccgen.c:gv() */
  ប្រសិនបើ (++pass < 2)
    goto again;

  ប្រសិនបើ(todo) {
    o(0xE8BD0000|todo); /* pop {todo} */
    សម្រាប់(pplan = plan->clsplans[CORE_STRUCT_CLASS]; pplan; pplan = pplan->prev) {
      ចំនួនគត់ r;
      pplan->sval->r = pplan->start;
      /* An SValue can only pin 2 registers at best (r and r2) but a structure
         can occupy more than 2 registers. Thus, we need to push on the value
         stack some fake parameter to have on SValue for each registers used
         by a structure (r2 is not used). */
      សម្រាប់ (r = pplan->start + 1; r <= pplan->end; r++) {
        ប្រសិនបើ (todo & (1 << r)) {
          nb_extra_sval++;
          vpushi(0);
          vtop->r = r;
        }
      }
    }
  }
  ត្រឡប់ nb_extra_sval;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
void gfunc_call(ចំនួនគត់ nb_args)
{
  ចំនួនគត់ args_size;
  ចំនួនគត់ def_float_abi = float_abi;
  ចំនួនគត់ todo;
  sa_nracanaa plan plan;
#ifdef TCC_ARM_EABI
  ចំនួនគត់ variadic;
#endif

#ifdef CONFIG_TCC_BCHECK
  ប្រសិនបើ (tcc_state->do_bounds_check)
    gbound_args(nb_args);
#endif

  save_regs(nb_args + 1);

#ifdef TCC_ARM_EABI
  ប្រសិនបើ (float_abi == ARM_HARD_FLOAT) {
    variadic = (vtop[-nb_args].type.ref->f.func_type == FUNC_ELLIPSIS);
    ប្រសិនបើ (variadic || floats_in_core_regs(&vtop[-nb_args]))
      float_abi = ARM_SOFTFP_FLOAT;
  }
#endif

  memset(&plan, 0, parimaa_na plan);
  ប្រសិនបើ (nb_args)
    plan.pplans = tcc_malloc(nb_args * parimaa_na(*plan.pplans));

  args_size = assign_regs(nb_args, float_abi, &plan, &todo);

#ifdef TCC_ARM_EABI
  ប្រសិនបើ (args_size & 7) { /* Stack must be 8 byte aligned at fct call for EABI */
    args_size = (args_size + 7) & ~7;
    o(0xE24DD004); /* sub sp, sp, #4 */
  }
#endif

  nb_args += copy_params(nb_args, &plan, todo);
  tcc_free(plan.pplans);

  /* Move fct SValue on top as required by gcall_or_jmp */
  vrotb(nb_args + 1);
  gcall_or_jmp(0);
  ប្រសិនបើ (args_size)
      gadd_sp(args_size); /* pop all parameters passed on the stack */
#ប្រសិនបើ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  ប្រសិនបើ(float_abi == ARM_SOFTFP_FLOAT && is_float(vtop->type.ref->type.t)) {
    ប្រសិនបើ((vtop->type.ref->type.t & VT_BTYPE) == VT_FLOAT) {
      o(0xEE000A10); /*vmov s0, r0 */
    } បើមិនដូច្នេះ {
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
void gfunc_prolog(Sym *func_sym)
{
  CType *func_type = &func_sym->type;
  Sym *sym,*sym2;
  ចំនួនគត់ n, nf, size, align, rs, struct_ret = 0;
  ចំនួនគត់ addr, pn, sn; /* pn=core, sn=stack */
  CType ret_type;

#ifdef TCC_ARM_EABI
  sa_nracanaa avail_regs avregs = {{0}};
#endif

  sym = func_type->ref;

  n = nf = 0;
  ប្រសិនបើ ((func_vt.t & VT_BTYPE) == VT_STRUCT &&
      !gfunc_sret(&func_vt, func_var, &ret_type, &align, &rs))
  {
    n++;
    struct_ret = 1;
    func_vc = 12; /* Offset from fp of the place to store the result */
  }
  សម្រាប់(sym2 = sym->next; sym2 && (n < 4 || nf < 16); sym2 = sym2->next) {
    size = type_size(&sym2->type, &align);
#ifdef TCC_ARM_EABI
    ប្រសិនបើ (float_abi == ARM_HARD_FLOAT && !func_var &&
        (is_float(sym2->type.t) || is_hgen_float_aggr(&sym2->type))) {
      ចំនួនគត់ tmpnf = assign_vfpreg(&avregs, align, size);
      tmpnf += (size + 3) / 4;
      nf = (tmpnf > nf) ? tmpnf : nf;
    } បើមិនដូច្នេះ
#endif
    ប្រសិនបើ (n < 4)
      n += (size + 3) / 4;
  }
  o(0xE1A0C00D); /* mov ip,sp */
  ប្រសិនបើ (func_var)
    n=4;
  ប្រសិនបើ (n) {
    ប្រសិនបើ(n>4)
      n=4;
#ifdef TCC_ARM_EABI
    n=(n+1)&-2;
#endif
    o(0xE92D0000|((1<<n)-1)); /* save r0-r4 on stack if needed */
  }
  ប្រសិនបើ (nf) {
    ប្រសិនបើ (nf>16)
      nf=16;
    nf=(nf+1)&-2; /* nf => HARDFLOAT => EABI */
    o(0xED2D0A00|nf); /* save s0-s15 on stack if needed */
  }
  o(0xE92D5800); /* save fp, ip, lr */
  o(0xE1A0B00D); /* mov fp, sp */
  func_sub_sp_offset = ind;
  o(0xE1A00000); /* nop, leave space for stack adjustment in epilog */

#ifdef TCC_ARM_EABI
  ប្រសិនបើ (float_abi == ARM_HARD_FLOAT) {
    func_vc += nf * 4;
    memset(&avregs, 0, parimaa_na avregs);
  }
#endif
  pn = struct_ret, sn = 0;
  ខណៈពេល ((sym = sym->next)) {
    CType *type;
    type = &sym->type;
    size = type_size(type, &align);
    size = (size + 3) >> 2;
    align = (align + 3) & ~3;
#ifdef TCC_ARM_EABI
    ប្រសិនបើ (float_abi == ARM_HARD_FLOAT && !func_var && (is_float(sym->type.t)
        || is_hgen_float_aggr(&sym->type))) {
      ចំនួនគត់ fpn = assign_vfpreg(&avregs, align, size << 2);
      ប្រសិនបើ (fpn >= 0)
        addr = fpn * 4;
      បើមិនដូច្នេះ
        goto from_stack;
    } បើមិនដូច្នេះ
#endif
    ប្រសិនបើ (pn < 4) {
#ifdef TCC_ARM_EABI
        pn = (pn + (align-1)/4) & -(align/4);
#endif
      addr = (nf + pn) * 4;
      pn += size;
      ប្រសិនបើ (!sn && pn > 4)
        sn = (pn - 4);
    } បើមិនដូច្នេះ {
#ifdef TCC_ARM_EABI
from_stack:
        sn = (sn + (align-1)/4) & -(align/4);
#endif
      addr = (n + nf + sn) * 4;
      sn += size;
    }
    gfunc_set_param(sym, addr + 12, 0);
  }
  last_itod_magic=0;
  leaffunc = 1;
  loc = 0;
#ifdef CONFIG_TCC_BCHECK
  ប្រសិនបើ (tcc_state->do_bounds_check)
    gen_bounds_prolog();
#endif
}

/* generate function epilog */
void gfunc_epilog(void)
{
  uint32_t x;
  ចំនួនគត់ diff;

#ifdef CONFIG_TCC_BCHECK
  ប្រសិនបើ (tcc_state->do_bounds_check)
    gen_bounds_epilog();
#endif
  /* Copy float return value to core register if base standard is used and
     float computation is made with VFP */
#ប្រសិនបើ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  ប្រសិនបើ ((float_abi == ARM_SOFTFP_FLOAT || func_var) && is_float(func_vt.t)) {
    ប្រសិនបើ((func_vt.t & VT_BTYPE) == VT_FLOAT)
      o(0xEE100A10); /* fmrs r0, s0 */
    បើមិនដូច្នេះ {
      o(0xEE100B10); /* fmrdl r0, d0 */
      o(0xEE301B10); /* fmrdh r1, d0 */
    }
  }
#endif
  o(0xE89BA800); /* restore fp, sp, pc */
  diff = (-loc + 3) & -4;
#ifdef TCC_ARM_EABI
  ប្រសិនបើ(!leaffunc)
    diff = ((diff + 11) & -8) - 4;
#endif
  ប្រសិនបើ(diff > 0) {
    x=stuff_const(0xE24BD000, diff); /* sub sp,fp,# */
    ប្រសិនបើ(x)
      *(uint32_t *)(cur_text_section->data + func_sub_sp_offset) = x;
    បើមិនដូច្នេះ {
      ចំនួនគត់ addr;
      addr=ind;
      o(0xE59FC004); /* ldr ip,[pc+4] */
      o(0xE04BD00C); /* sub sp,fp,ip  */
      o(0xE1A0F00E); /* mov pc,lr */
      o(diff);
      *(uint32_t *)(cur_text_section->data + func_sub_sp_offset) = 0xE1000000|encbranch(func_sub_sp_offset,addr,1);
    }
  }
}

ST_FUNC void gen_fill_nops(ចំនួនគត់ bytes)
{
    ប្រសិនបើ ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    ខណៈពេល (bytes > 0) {
	o(0xE1A00000);
	bytes -= 4;
    }
}

/* generate a jump to a label */
ST_FUNC ចំនួនគត់ gjmp(ចំនួនគត់ t)
{
  ចំនួនគត់ r;
  ប្រសិនបើ (nocode_wanted)
    ត្រឡប់ t;
  r=ind;
  o(0xE0000000|encbranch(r,t,1));
  ត្រឡប់ r;
}

/* generate a jump to a fixed address */
ST_FUNC void gjmp_addr(ចំនួនគត់ a)
{
  gjmp(a);
}

ST_FUNC ចំនួនគត់ gjmp_cond(ចំនួនគត់ op, ចំនួនគត់ t)
{
  ចំនួនគត់ r;
  ប្រសិនបើ (nocode_wanted)
    ត្រឡប់ t;
  r=ind;
  op=mapcc(op);
  op|=encbranch(r,t,1);
  o(op);
  ត្រឡប់ r;
}

ST_FUNC ចំនួនគត់ gjmp_append(ចំនួនគត់ n, ចំនួនគត់ t)
{
  uint32_t *x;
  ចំនួនគត់ p,lp;
  ប្រសិនបើ(n) {
    p = n;
    do {
      p = decbranch(lp=p);
    } ខណៈពេល(p);
    x = (uint32_t *)(cur_text_section->data + lp);
    *x &= 0xff000000;
    *x |= encbranch(lp,t,1);
    t = n;
  }
  ត្រឡប់ t;
}

/* generate an integer binary operation */
void gen_opi(ចំនួនគត់ op)
{
  ចំនួនគត់ c, func = 0;
  uint32_t opc = 0, r, fr;
  unsigned short retreg = REG_IRET;

  c=0;
  switch(op) {
    pak_sa '+':
      opc = 0x8;
      c=1;
      bha_nga;
    pak_sa TOK_ADDC1: /* add with carry generation */
      opc = 0x9;
      c=1;
      bha_nga;
    pak_sa '-':
      opc = 0x4;
      c=1;
      bha_nga;
    pak_sa TOK_SUBC1: /* sub with carry generation */
      opc = 0x5;
      c=1;
      bha_nga;
    pak_sa TOK_ADDC2: /* add with carry use */
      opc = 0xA;
      c=1;
      bha_nga;
    pak_sa TOK_SUBC2: /* sub with carry use */
      opc = 0xC;
      c=1;
      bha_nga;
    pak_sa '&':
      opc = 0x0;
      c=1;
      bha_nga;
    pak_sa '^':
      opc = 0x2;
      c=1;
      bha_nga;
    pak_sa '|':
      opc = 0x18;
      c=1;
      bha_nga;
    pak_sa '*':
      gv2(RC_INT, RC_INT);
      r = vtop[-1].r;
      fr = vtop[0].r;
      vtop--;
      o(0xE0000090|(intr(r)<<16)|(intr(r)<<8)|intr(fr));
      ត្រឡប់;
    pak_sa TOK_SHL:
      opc = 0;
      c=2;
      bha_nga;
    pak_sa TOK_SHR:
      opc = 1;
      c=2;
      bha_nga;
    pak_sa TOK_SAR:
      opc = 2;
      c=2;
      bha_nga;
    pak_sa '/':
    pak_sa TOK_PDIV:
      func=TOK___divsi3;
      c=3;
      bha_nga;
    pak_sa TOK_UDIV:
      func=TOK___udivsi3;
      c=3;
      bha_nga;
    pak_sa '%':
#ifdef TCC_ARM_EABI
      func=TOK___aeabi_idivmod;
      retreg=REG_IRE2;
#បើមិនដូច្នេះ
      func=TOK___modsi3;
#endif
      c=3;
      bha_nga;
    pak_sa TOK_UMOD:
#ifdef TCC_ARM_EABI
      func=TOK___aeabi_uidivmod;
      retreg=REG_IRE2;
#បើមិនដូច្នេះ
      func=TOK___umodsi3;
#endif
      c=3;
      bha_nga;
    pak_sa TOK_UMULL:
      gv2(RC_INT, RC_INT);
      r=intr(vtop[-1].r2=get_reg(RC_INT));
      c=vtop[-1].r;
      vtop[-1].r=get_reg_ex(RC_INT,regmask(c));
      vtop--;
      o(0xE0800090|(r<<16)|(intr(vtop->r)<<12)|(intr(c)<<8)|intr(vtop[1].r));
      ត្រឡប់;
    default:
      opc = 0x15;
      c=1;
      bha_nga;
  }
  switch(c) {
    pak_sa 1:
      ប្រសិនបើ((vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	ប្រសិនបើ(opc == 4 || opc == 5 || opc == 0xc) {
	  vswap();
	  opc|=2; // sub -> rsb
	}
      }
      vswap();
      c=intr(gv(RC_INT));
      vswap();
      opc=0xE0000000|(opc<<20);
      ប្រសិនបើ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	uint32_t x;
	x=stuff_const(opc|0x2000000|(c<<16),vtop->c.i);
	ប្រសិនបើ(x) {
	  ប្រសិនបើ ((x & 0xfff00000) == 0xe3500000)   // cmp rx,#c
	    o(x);
	  បើមិនដូច្នេះ {
	    r=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	    o(x|(r<<12));
	  }
	  goto done;
	}
      }
      fr=intr(gv(RC_INT));
#ifdef CONFIG_TCC_BCHECK
      ប្រសិនបើ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
        vswap();
        c=intr(gv(RC_INT));
        vswap();
      }
#endif
      ប្រសិនបើ ((opc & 0xfff00000) == 0xe1500000) // cmp rx,ry
	o(opc|(c<<16)|fr);
      បើមិនដូច្នេះ {
        r=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
        o(opc|(c<<16)|(r<<12)|fr);
      }
done:
      vtop--;
      ប្រសិនបើ (op >= TOK_ULT && op <= TOK_GT)
        vset_VT_CMP(op);
      bha_nga;
    pak_sa 2:
      opc=0xE1A00000|(opc<<5);
      vswap();
      r=intr(gv(RC_INT));
      vswap();
      ប្រសិនបើ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	fr=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	c = vtop->c.i & 0x1f;
	o(opc|r|(c<<7)|(fr<<12));
      } បើមិនដូច្នេះ {
        fr=intr(gv(RC_INT));
#ifdef CONFIG_TCC_BCHECK
        ប្រសិនបើ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=intr(gv(RC_INT));
          vswap();
        }
#endif
	c=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
	o(opc|r|(c<<12)|(fr<<8)|0x10);
      }
      vtop--;
      bha_nga;
    pak_sa 3:
      vpush_helper_func(func);
      vrott(3);
      gfunc_call(2);
      vpushi(0);
      vtop->r = retreg;
      bha_nga;
    default:
      tcc_error("gen_opi %i unimplemented!",op);
  }
}

#ifdef TCC_ARM_VFP
static ចំនួនគត់ is_zero(ចំនួនគត់ i)
{
  ប្រសិនបើ((vtop[i].r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    ត្រឡប់ 0;
  ប្រសិនបើ (vtop[i].type.t == VT_FLOAT)
    ត្រឡប់ (vtop[i].c.f == 0.f);
  បើមិនដូច្នេះ ប្រសិនបើ (vtop[i].type.t == VT_DOUBLE)
    ត្រឡប់ (vtop[i].c.d == 0.0);
  ត្រឡប់ (vtop[i].c.ld == 0.l);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
 *    two operands are guaranteed to have the same floating point type */
void gen_opf(ចំនួនគត់ op)
{
  uint32_t x;
  ចំនួនគត់ fneg=0,r;
  x=0xEE000A00|T2CPR(vtop->type.t);
  switch(op) {
    pak_sa '+':
      ប្រសិនបើ(is_zero(-1))
        vswap();
      ប្រសិនបើ(is_zero(0)) {
        vtop--;
        ត្រឡប់;
      }
      x|=0x300000;
      bha_nga;
    pak_sa '-':
      x|=0x300040;
      ប្រសិនបើ(is_zero(0)) {
        vtop--;
        ត្រឡប់;
      }
      ប្រសិនបើ(is_zero(-1)) {
        x|=0x810000; /* fsubX -> fnegX */
        vswap();
        vtop--;
        fneg=1;
      }
      bha_nga;
    pak_sa '*':
      x|=0x200000;
      bha_nga;
    pak_sa '/':
      x|=0x800000;
      bha_nga;
    default:
      ប្រសិនបើ(op < TOK_ULT || op > TOK_GT) {
        tcc_error("unknown fp op %x!",op);
        ត្រឡប់;
      }
      ប្រសិនបើ(is_zero(-1)) {
        vswap();
        switch(op) {
          pak_sa TOK_LT: op=TOK_GT; bha_nga;
          pak_sa TOK_GE: op=TOK_ULE; bha_nga;
          pak_sa TOK_LE: op=TOK_GE; bha_nga;
          pak_sa TOK_GT: op=TOK_ULT; bha_nga;
        }
      }
      x|=0xB40040; /* fcmpX */
      ប្រសិនបើ(op!=TOK_EQ && op!=TOK_NE)
        x|=0x80; /* fcmpX -> fcmpeX */
      ប្រសិនបើ(is_zero(0)) {
        vtop--;
        o(x|0x10000|(vfpr(gv(RC_FLOAT))<<12)); /* fcmp(e)X -> fcmp(e)zX */
      } បើមិនដូច្នេះ {
        gv2(RC_FLOAT,RC_FLOAT);
        x|=vfpr(vtop[0].r);
        o(x|(vfpr(vtop[-1].r) << 12));
        vtop--;
      }
      o(0xEEF1FA10); /* fmstat */

      switch(op) {
        pak_sa TOK_LE: op=TOK_ULE; bha_nga;
        pak_sa TOK_LT: op=TOK_ULT; bha_nga;
        pak_sa TOK_UGE: op=TOK_GE; bha_nga;
        pak_sa TOK_UGT: op=TOK_GT; bha_nga;
      }
      vset_VT_CMP(op);
      ត្រឡប់;
  }
  r=gv(RC_FLOAT);
  x|=vfpr(r);
  r=regmask(r);
  ប្រសិនបើ(!fneg) {
    ចំនួនគត់ r2;
    vswap();
    r2=gv(RC_FLOAT);
    x|=vfpr(r2)<<16;
    r|=regmask(r2);
#ifdef CONFIG_TCC_BCHECK
    ប្រសិនបើ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
      vswap();
      r=gv(RC_FLOAT);
      vswap();
      x=(x&~0xf)|vfpr(r);
    }
#endif
  }
  vtop->r=get_reg_ex(RC_FLOAT,r);
  ប្រសិនបើ(!fneg)
    vtop--;
  o(x|(vfpr(vtop->r)<<12));
}

#បើមិនដូច្នេះ
static uint32_t is_fconst()
{
  long dviguu_na f;
  uint32_t r;
  ប្រសិនបើ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    ត្រឡប់ 0;
  ប្រសិនបើ (vtop->type.t == VT_FLOAT)
    f = vtop->c.f;
  បើមិនដូច្នេះ ប្រសិនបើ (vtop->type.t == VT_DOUBLE)
    f = vtop->c.d;
  បើមិនដូច្នេះ
    f = vtop->c.ld;
  ប្រសិនបើ(!ieee_finite(f))
    ត្រឡប់ 0;
  r=0x8;
  ប្រសិនបើ(f<0.0) {
    r=0x18;
    f=-f;
  }
  ប្រសិនបើ(f==0.0)
    ត្រឡប់ r;
  ប្រសិនបើ(f==1.0)
    ត្រឡប់ r|1;
  ប្រសិនបើ(f==2.0)
    ត្រឡប់ r|2;
  ប្រសិនបើ(f==3.0)
    ត្រឡប់ r|3;
  ប្រសិនបើ(f==4.0)
    ត្រឡប់ r|4;
  ប្រសិនបើ(f==5.0)
    ត្រឡប់ r|5;
  ប្រសិនបើ(f==0.5)
    ត្រឡប់ r|6;
  ប្រសិនបើ(f==10.0)
    ត្រឡប់ r|7;
  ត្រឡប់ 0;
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
void gen_opf(ចំនួនគត់ op)
{
  uint32_t x, r, r2, c1, c2;
  //fputs("gen_opf\n",stderr);
  vswap();
  c1 = is_fconst();
  vswap();
  c2 = is_fconst();
  x=0xEE000100;
  ប្រសិនបើ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
    x|=0x80;
#ប្រសិនបើ LDOUBLE_SIZE != 8
  បើមិនដូច្នេះ ប្រសិនបើ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE)
    x|=0x80000;
#endif

  switch(op)
  {
    pak_sa '+':
      ប្រសិនបើ(!c2) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      ប្រសិនបើ(c2) {
	ប្រសិនបើ(c2>0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
      } បើមិនដូច្នេះ {
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        ប្រសិនបើ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      bha_nga;
    pak_sa '-':
      ប្រសិនបើ(c2) {
	ប្រសិនបើ(c2<=0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } បើមិនដូច្នេះ ប្រសិនបើ(c1 && c1<=0xf) {
	x|=0x300000; // rsf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } បើមិនដូច្នេះ {
	x|=0x200000; // suf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        ប្រសិនបើ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      bha_nga;
    pak_sa '*':
      ប្រសិនបើ(!c2 || c2>0xf) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      ប្រសិនបើ(c2 && c2<=0xf)
	r2=c2;
      បើមិនដូច្នេះ {
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        ប្រសិនបើ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      x|=0x100000; // muf
      bha_nga;
    pak_sa '/':
      ប្រសិនបើ(c2 && c2<=0xf) {
	x|=0x400000; // dvf
	r2=c2;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } បើមិនដូច្នេះ ប្រសិនបើ(c1 && c1<=0xf) {
	x|=0x500000; // rdf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } បើមិនដូច្នេះ {
	x|=0x400000; // dvf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        ប្រសិនបើ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      bha_nga;
    default:
      ប្រសិនបើ(op >= TOK_ULT && op <= TOK_GT) {
	x|=0xd0f110; // cmfe
/* bug (intention?) in Linux FPU emulator
   doesn't set carry if equal */
	switch(op) {
	  pak_sa TOK_ULT:
	  pak_sa TOK_UGE:
	  pak_sa TOK_ULE:
	  pak_sa TOK_UGT:
            tcc_error("unsigned comparison on floats?");
	    bha_nga;
	  pak_sa TOK_LT:
            op=TOK_Nset;
	    bha_nga;
	  pak_sa TOK_LE:
            op=TOK_ULE; /* correct in unordered case only if AC bit in FPSR set */
	    bha_nga;
	  pak_sa TOK_EQ:
	  pak_sa TOK_NE:
	    x&=~0x400000; // cmfe -> cmf
	    bha_nga;
	}
	ប្រសិនបើ(c1 && !c2) {
	  c2=c1;
	  vswap();
	  switch(op) {
            pak_sa TOK_Nset:
              op=TOK_GT;
	      bha_nga;
            pak_sa TOK_GE:
	      op=TOK_ULE;
	      bha_nga;
	    pak_sa TOK_ULE:
              op=TOK_GE;
	      bha_nga;
            pak_sa TOK_GT:
              op=TOK_Nset;
	      bha_nga;
	  }
	}
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	ប្រសិនបើ(c2) {
	  ប្រសិនបើ(c2>0xf)
	    x|=0x200000;
	  r2=c2&0xf;
	} បើមិនដូច្នេះ {
	  r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
          ប្រសិនបើ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            r=fpr(gv(RC_FLOAT));
            vswap();
          }
#endif
	}
        --vtop;
        vset_VT_CMP(op);
        ++vtop;
      } បើមិនដូច្នេះ {
        tcc_error("unknown fp op %x!",op);
	ត្រឡប់;
      }
  }
  ប្រសិនបើ(vtop[-1].r == VT_CMP)
    c1=15;
  បើមិនដូច្នេះ {
    c1=vtop->r;
    ប្រសិនបើ(r2&0x8)
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
ST_FUNC void gen_cvt_itof(ចំនួនគត់ t)
{
  uint32_t r, r2;
  ចំនួនគត់ bt;
  bt=vtop->type.t & VT_BTYPE;
  ប្រសិនបើ(bt == VT_INT || bt == VT_SHORT || bt == VT_BYTE) {
#ifndef TCC_ARM_VFP
    uint32_t dsize = 0;
#endif
    r=intr(gv(RC_INT));
#ifdef TCC_ARM_VFP
    r2=vfpr(vtop->r=get_reg(RC_FLOAT));
    o(0xEE000A10|(r<<12)|(r2<<16)); /* fmsr */
    r2|=r2<<12;
    ប្រសិនបើ(!(vtop->type.t & VT_UNSIGNED))
      r2|=0x80;                /* fuitoX -> fsituX */
    o(0xEEB80A40|r2|T2CPR(t)); /* fYitoX*/
#បើមិនដូច្នេះ
    r2=fpr(vtop->r=get_reg(RC_FLOAT));
    ប្រសិនបើ((t & VT_BTYPE) != VT_FLOAT)
      dsize=0x80;    /* flts -> fltd */
    o(0xEE000110|dsize|(r2<<16)|(r<<12)); /* flts */
    ប្រសិនបើ((vtop->type.t & (VT_UNSIGNED|VT_BTYPE)) == (VT_UNSIGNED|VT_INT)) {
      uint32_t off = 0;
      o(0xE3500000|(r<<12));        /* cmp */
      r=fpr(get_reg(RC_FLOAT));
      ប្រសិនបើ(last_itod_magic) {
	off=ind+8-last_itod_magic;
	off/=4;
	ប្រសិនបើ(off>255)
	  off=0;
      }
      o(0xBD1F0100|(r<<12)|off);    /* ldflts */
      ប្រសិនបើ(!off) {
        o(0xEA000000);              /* b */
        last_itod_magic=ind;
        o(0x4F800000);              /* 4294967296.0f */
      }
      o(0xBE000100|dsize|(r2<<16)|(r2<<12)|r); /* adflt */
    }
#endif
    ត្រឡប់;
  } បើមិនដូច្នេះ ប្រសិនបើ(bt == VT_LLONG) {
    ចំនួនគត់ func;
    CType *func_type = 0;
    ប្រសិនបើ((t & VT_BTYPE) == VT_FLOAT) {
      func_type = &func_float_type;
      ប្រសិនបើ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundisf;
      បើមិនដូច្នេះ
        func=TOK___floatdisf;
    } បើមិនដូច្នេះ ប្រសិនបើ((t & VT_BTYPE) == VT_DOUBLE) {
      func_type = &func_double_type;
      ប្រសិនបើ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundidf;
      បើមិនដូច្នេះ
        func=TOK___floatdidf;
#ប្រសិនបើ LDOUBLE_SIZE != 8
    } បើមិនដូច្នេះ ប្រសិនបើ((t & VT_BTYPE) == VT_LDOUBLE) {
      func_type = &func_ldouble_type;
      ប្រសិនបើ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundixf;
      បើមិនដូច្នេះ
        func=TOK___floatdixf;
#endif
    }
    ប្រសិនបើ(func_type) {
      vpushsym(func_type, external_helper_sym(func));
      vswap();
      gfunc_call(1);
      vpushi(0);
      vtop->r=TREG_F0;
      ត្រឡប់;
    }
  }
  tcc_error("unimplemented gen_cvt_itof %x!",vtop->type.t);
}

/* convert fp to int 't' type */
void gen_cvt_ftoi(ចំនួនគត់ t)
{
  uint32_t r, r2;
  ចំនួនគត់ u, func = 0;
  u=t&VT_UNSIGNED;
  t&=VT_BTYPE;
  r2=vtop->type.t & VT_BTYPE;
  ប្រសិនបើ(t==VT_INT) {
#ifdef TCC_ARM_VFP
    r=vfpr(gv(RC_FLOAT));
    u=u?0:0x10000;
    o(0xEEBC0AC0|(r<<12)|r|T2CPR(r2)|u); /* ftoXizY */
    r2=intr(vtop->r=get_reg(RC_INT));
    o(0xEE100A10|(r<<16)|(r2<<12));
    ត្រឡប់;
#បើមិនដូច្នេះ
    ប្រសិនបើ(u) {
      ប្រសិនបើ(r2 == VT_FLOAT)
        func=TOK___fixunssfsi;
      បើមិនដូច្នេះ ប្រសិនបើ(r2 == VT_DOUBLE)
	func=TOK___fixunsdfsi;
#ប្រសិនបើ LDOUBLE_SIZE != 8
      បើមិនដូច្នេះ ប្រសិនបើ(r2 == VT_LDOUBLE)
	func=TOK___fixunsxfsi;
#endif
    } បើមិនដូច្នេះ {
      r=fpr(gv(RC_FLOAT));
      r2=intr(vtop->r=get_reg(RC_INT));
      o(0xEE100170|(r2<<12)|r);
      ត្រឡប់;
    }
#endif
  } បើមិនដូច្នេះ ប្រសិនបើ(t == VT_LLONG) { // unsigned handled in gen_cvt_ftoi1
    ប្រសិនបើ(r2 == VT_FLOAT)
      func=TOK___fixsfdi;
    បើមិនដូច្នេះ ប្រសិនបើ(r2 == VT_DOUBLE)
      func=TOK___fixdfdi;
#ប្រសិនបើ LDOUBLE_SIZE != 8
    បើមិនដូច្នេះ ប្រសិនបើ(r2 == VT_LDOUBLE)
      func=TOK___fixxfdi;
#endif
  }
  ប្រសិនបើ(func) {
    vpush_helper_func(func);
    vswap();
    gfunc_call(1);
    vpushi(0);
    ប្រសិនបើ(t == VT_LLONG)
      vtop->r2 = REG_IRE2;
    vtop->r = REG_IRET;
    ត្រឡប់;
  }
  tcc_error("unimplemented gen_cvt_ftoi!");
}

/* convert from one floating point type to another */
void gen_cvt_ftof(ចំនួនគត់ t)
{
#ifdef TCC_ARM_VFP
  uint32_t r = gv(RC_FLOAT);
  ប្រសិនបើ(((vtop->type.t & VT_BTYPE) == VT_FLOAT) != ((t & VT_BTYPE) == VT_FLOAT)) {
    r = vfpr(r);
    o(0xEEB70AC0|(r<<12)|r|T2CPR(vtop->type.t));
  }
#បើមិនដូច្នេះ
  /* all we have to do on i386 and FPA ARM is to put the float in a register */
  gv(RC_FLOAT);
#endif
}

/* increment tcov counter */
ST_FUNC void gen_increment_tcov (SValue *sv)
{
  ចំនួនគត់ r1, r2;

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
void ggoto(void)
{
  gcall_or_jmp(1);
  vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC void gen_vla_sp_save(ចំនួនគត់ addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    store(TREG_SP, &v);
}

/* Restore the SP from a location on the stack */
ST_FUNC void gen_vla_sp_restore(ចំនួនគត់ addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    load(TREG_SP, &v);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC void gen_vla_alloc(CType *type, ចំនួនគត់ align) {
    ចំនួនគត់ r;
#ប្រសិនបើ defined(CONFIG_TCC_BCHECK)
    ប្រសិនបើ (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    r = intr(gv(RC_INT));
#ប្រសិនបើ defined(CONFIG_TCC_BCHECK)
    ប្រសិនបើ (tcc_state->do_bounds_check)
        o(0xe2800001 | (r<<16)|(r<<12)); /* add r,r,#1 */
#endif
    o(0xE04D0000|(r<<12)|r); /* sub r, sp, r */
#ifdef TCC_ARM_EABI
    ប្រសិនបើ (align < 8)
        align = 8;
#បើមិនដូច្នេះ
    ប្រសិនបើ (align < 4)
        align = 4;
#endif
    ប្រសិនបើ (align & (align - 1))
        tcc_error("alignment is not a power of 2: %i", align);
    o(stuff_const(0xE3C0D000|(r<<16), align - 1)); /* bic sp, r, #align-1 */
    vpop();
#ប្រសិនបើ defined(CONFIG_TCC_BCHECK)
    ប្រសិនបើ (tcc_state->do_bounds_check) {
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
