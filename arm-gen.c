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

#ако defined(TCC_ARM_EABI) && !defined(TCC_ARM_VFP)
#error "Currently TinyCC only supports float computation with VFP instructions"
#endif

/* number of available registers */
#ifdef TCC_ARM_VFP
#define NB_REGS            13
#иначе
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
enum {
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
#иначе
#define LDOUBLE_ALIGN 4
#endif

#ако LDOUBLE_SIZE == 8
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#endif

/* maximum alignment (for aligned attribute support) */
#define MAX_ALIGN     8

#define CHAR_IS_UNSIGNED

#define ARM_SOFTFP_FLOAT 0
#define ARM_HARD_FLOAT 1

/******************************************************/
#иначе /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#include "tcc.h"

ST_DATA const char * const target_machine_defs =
    "__arm__\0"
    "__arm\0"
    "arm\0"
    "__arm_elf__\0"
    "__arm_elf\0"
    "arm_elf\0"
    "__ARM_ARCH_4__\0"
    "__ARMEL__\0"
    "__APCS_32__\0"
#ако defined TCC_ARM_EABI
    "__ARM_EABI__\0"
#endif
    ;

ST_DATA const цяло reg_classes[NB_REGS] = {
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

static цяло float_abi;
static цяло func_sub_sp_offset, last_itod_magic;
static цяло leaffunc;

#ако defined(CONFIG_TCC_BCHECK)
static addr_t func_bound_offset;
static unsigned long func_bound_ind;
ST_DATA цяло func_bound_add_epilog;
#endif

#ако defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
static CType float_type, double_type, func_float_type, func_double_type;
ST_FUNC void arm_init(struct TCCState *s)
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
#иначе
#define func_float_type func_old_type
#define func_double_type func_old_type
#define func_ldouble_type func_old_type
ST_FUNC void arm_init(struct TCCState *s)
{
#ако 0
#ако !defined (TCC_ARM_VFP)
    tcc_warning("Support for FPA is deprecated and will be removed in next"
                " release");
#endif
#ако !defined (TCC_ARM_EABI)
    tcc_warning("Support for OABI is deprecated and will be removed in next"
                " release");
#endif
#endif
}
#endif

#define CHECK_R(r) ((r) >= TREG_R0 && (r) <= TREG_LR)

static цяло two2mask(цяло a,цяло b) {
  ако (!CHECK_R(a) || !CHECK_R(b))
    tcc_error("compiler error! registers %i,%i is not valid",a,b);
  върни (reg_classes[a]|reg_classes[b])&~(RC_INT|RC_FLOAT);
}

static цяло regmask(цяло r) {
  ако (!CHECK_R(r))
    tcc_error("compiler error! register %i is not valid",r);
  върни reg_classes[r]&~(RC_INT|RC_FLOAT);
}

/******************************************************/

void o(uint32_t i)
{
  /* this is a good place to start adding big-endian support*/
  цяло ind1;
  ако (nocode_wanted)
    върни;
  ind1 = ind + 4;
  ако (!cur_text_section)
    tcc_error("compiler error! This happens f.ex. if the compiler\n"
         "can't evaluate constant expressions outside of a function.");
  ако (ind1 > cur_text_section->data_allocated)
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
  цяло try_neg=0;
  uint32_t nc = 0, negop = 0;

  switch(op&0x1F00000)
  {
    case 0x800000: //add
    case 0x400000: //sub
      try_neg=1;
      negop=op^0xC00000;
      nc=-c;
      break;
    case 0x1A00000: //mov
    case 0x1E00000: //mvn
      try_neg=1;
      negop=op^0x400000;
      nc=~c;
      break;
    case 0x200000: //xor
      ако(c==~0)
	върни (op&0xF010F000)|((op>>16)&0xF)|0x1E00000;
      break;
    case 0x0: //and
      ако(c==~0)
	върни (op&0xF010F000)|((op>>16)&0xF)|0x1A00000;
    case 0x1C00000: //bic
      try_neg=1;
      negop=op^0x1C00000;
      nc=~c;
      break;
    case 0x1800000: //orr
      ако(c==~0)
	върни (op&0xFFF0FFFF)|0x1E00000;
      break;
  }
  do {
    uint32_t m;
    цяло i;
    ако(c<256) /* catch undefined <<32 */
      върни op|c;
    за(i=2;i<32;i+=2) {
      m=(0xffu>>i)|(0xffu<<(32-i));
      ако(!(c&~m))
	върни op|(i<<7)|(c<<i)|(c>>(32-i));
    }
    op=negop;
    c=nc;
  } докато(try_neg--);
  върни 0;
}


//only add,sub
void stuff_const_harder(uint32_t op, uint32_t v) {
  uint32_t x;
  x=stuff_const(op,v);
  ако(x)
    o(x);
  иначе {
    uint32_t a[16], nv, no, o2, n2;
    цяло i,j,k;
    a[0]=0xff;
    o2=(op&0xfff0ffff)|((op&0xf000)<<4);;
    за(i=1;i<16;i++)
      a[i]=(a[i-1]>>2)|(a[i-1]<<30);
    за(i=0;i<12;i++)
      за(j=i<4?i+12:15;j>=i+4;j--)
	ако((v&(a[i]|a[j]))==v) {
	  o(stuff_const(op,v&a[i]));
	  o(stuff_const(o2,v&a[j]));
	  върни;
	}
    no=op^0xC00000;
    n2=o2^0xC00000;
    nv=-v;
    за(i=0;i<12;i++)
      за(j=i<4?i+12:15;j>=i+4;j--)
	ако((nv&(a[i]|a[j]))==nv) {
	  o(stuff_const(no,nv&a[i]));
	  o(stuff_const(n2,nv&a[j]));
	  върни;
	}
    за(i=0;i<8;i++)
      за(j=i+4;j<12;j++)
	за(k=i<4?i+12:15;k>=j+4;k--)
	  ако((v&(a[i]|a[j]|a[k]))==v) {
	    o(stuff_const(op,v&a[i]));
	    o(stuff_const(o2,v&a[j]));
	    o(stuff_const(o2,v&a[k]));
	    върни;
	  }
    no=op^0xC00000;
    nv=-v;
    за(i=0;i<8;i++)
      за(j=i+4;j<12;j++)
	за(k=i<4?i+12:15;k>=j+4;k--)
	  ако((nv&(a[i]|a[j]|a[k]))==nv) {
	    o(stuff_const(no,nv&a[i]));
	    o(stuff_const(n2,nv&a[j]));
	    o(stuff_const(n2,nv&a[k]));
	    върни;
	  }
    o(stuff_const(op,v&a[0]));
    o(stuff_const(o2,v&a[4]));
    o(stuff_const(o2,v&a[8]));
    o(stuff_const(o2,v&a[12]));
  }
}

uint32_t encbranch(цяло pos, цяло addr, цяло fail)
{
  addr-=pos+8;
  addr/=4;
  ако(addr>=0x1000000 || addr<-0x1000000) {
    ако(fail)
      tcc_error("FIXME: function bigger than 32MB");
    върни 0;
  }
  върни 0x0A000000|(addr&0xffffff);
}

цяло decbranch(цяло pos)
{
  цяло x;
  x=*(uint32_t *)(cur_text_section->data + pos);
  x&=0x00ffffff;
  ако(x&0x800000)
    x-=0x1000000;
  върни x*4+pos+8;
}

/* output a symbol and patch all calls to it */
void gsym_addr(цяло t, цяло a)
{
  uint32_t *x;
  цяло lt;
  докато(t) {
    x=(uint32_t *)(cur_text_section->data + t);
    t=decbranch(lt=t);
    ако(a==lt+4)
      *x=0xE1A00000; // nop
    иначе {
      *x &= 0xff000000;
      *x |= encbranch(lt,a,1);
    }
  }
}

#ifdef TCC_ARM_VFP
static uint32_t vfpr(цяло r)
{
  ако(r<TREG_F0 || r>TREG_F7)
    tcc_error("compiler error! register %i is no vfp register",r);
  върни r - TREG_F0;
}
#иначе
static uint32_t fpr(цяло r)
{
  ако(r<TREG_F0 || r>TREG_F3)
    tcc_error("compiler error! register %i is no fpa register",r);
  върни r - TREG_F0;
}
#endif

static uint32_t intr(цяло r)
{
  ако(r == TREG_R12)
    върни 12;
  ако(r >= TREG_R0 && r <= TREG_R3)
    върни r - TREG_R0;
  ако (!(r >= TREG_SP && r <= TREG_LR))
    tcc_error("compiler error! register %i is no int register",r);
  върни r + (13 - TREG_SP);
}

static void calcaddr(uint32_t *base, цяло *off, цяло *sgn, цяло maxoff, unsigned shift)
{
  ако(*off>maxoff || *off&((1<<shift)-1)) {
    uint32_t x, y;
    x=0xE280E000;
    ако(*sgn)
      x=0xE240E000;
    x|=(*base)<<16;
    *base=14; // lr
    y=stuff_const(x,*off&~maxoff);
    ако(y) {
      o(y);
      *off&=maxoff;
      върни;
    }
    y=stuff_const(x,(*off+maxoff)&~maxoff);
    ако(y) {
      o(y);
      *sgn=!*sgn;
      *off=((*off+maxoff)&~maxoff)-*off;
      върни;
    }
    stuff_const_harder(x,*off&~maxoff);
    *off&=maxoff;
  }
}

static uint32_t mapcc(цяло cc)
{
  switch(cc)
  {
    case TOK_ULT:
      върни 0x30000000; /* CC/LO */
    case TOK_UGE:
      върни 0x20000000; /* CS/HS */
    case TOK_EQ:
      върни 0x00000000; /* EQ */
    case TOK_NE:
      върни 0x10000000; /* NE */
    case TOK_ULE:
      върни 0x90000000; /* LS */
    case TOK_UGT:
      върни 0x80000000; /* HI */
    case TOK_Nset:
      върни 0x40000000; /* MI */
    case TOK_Nclear:
      върни 0x50000000; /* PL */
    case TOK_LT:
      върни 0xB0000000; /* LT */
    case TOK_GE:
      върни 0xA0000000; /* GE */
    case TOK_LE:
      върни 0xD0000000; /* LE */
    case TOK_GT:
      върни 0xC0000000; /* GT */
  }
  tcc_error("unexpected condition code");
  върни 0xE0000000; /* AL */
}

static цяло negcc(цяло cc)
{
  switch(cc)
  {
    case TOK_ULT:
      върни TOK_UGE;
    case TOK_UGE:
      върни TOK_ULT;
    case TOK_EQ:
      върни TOK_NE;
    case TOK_NE:
      върни TOK_EQ;
    case TOK_ULE:
      върни TOK_UGT;
    case TOK_UGT:
      върни TOK_ULE;
    case TOK_Nset:
      върни TOK_Nclear;
    case TOK_Nclear:
      върни TOK_Nset;
    case TOK_LT:
      върни TOK_GE;
    case TOK_GE:
      върни TOK_LT;
    case TOK_LE:
      върни TOK_GT;
    case TOK_GT:
      върни TOK_LE;
  }
  tcc_error("unexpected condition code");
  върни TOK_NE;
}

/* Load value into register r.
   Use relative/got addressing to avoid setting DT_TEXTREL */
static void load_value(SValue *sv, цяло r)
{
#ако CONFIG_TCC_CPUVER >= 7
    ако (!(sv->r & VT_SYM)) {
        unsigned x=sv->c.i;
        o(0xE3000000|intr(r)<<12|(x&0xFFF)|(x<<4&0xF0000)); /* movw rx,#x(lo) */
        ако (x&0xFFFF0000)
          o(0xE3400000|intr(r)<<12|(x>>16&0xFFF)|(x>>12&0xF0000)); /* movt rx,#x(hi) */
        върни;
    }
#endif
    o(0xE59F0000|(intr(r)<<12)); /* ldr r, [pc] */
    o(0xEA000000); /* b $+4 */
#ifndef CONFIG_TCC_PIC
    ако(sv->r & VT_SYM)
        greloc(cur_text_section, sv->sym, ind, R_ARM_ABS32);
    o(sv->c.i);
#иначе
    ако(sv->r & VT_SYM) {
	ако (sv->sym->type.t & VT_STATIC) {
            greloc(cur_text_section, sv->sym, ind, R_ARM_REL32);
            o(sv->c.i - 12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
        }
        иначе {
            greloc(cur_text_section, sv->sym, ind, R_ARM_GOT_PREL);
            o(-12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
            o(0xe5900000 | (intr(r)<<12) | (intr(r)<<16));  // ldr rx,[rx]
            ако (sv->c.i)
              stuff_const_harder(0xe2800000 | (intr(r)<<12) | (intr(r)<<16),
                                 sv->c.i);
        }
    }
    иначе
        o(sv->c.i);
#endif
}

/* load 'r' from value 'sv' */
void load(цяло r, SValue *sv)
{
  цяло v, ft, fc, fr, sign;
  uint32_t op, base;
  SValue v1;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  ако(fc>=0)
    sign=0;
  иначе {
    sign=1;
    fc=-(unsigned)fc;
  }

  v = fr & VT_VALMASK;
  ако (fr & VT_LVAL) {

    ако ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe510e000; /* ldr r, [lr, #0] */
        greloca(cur_text_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        върни;
    }

    base = 0xB; // fp
    ако(v == VT_LLOCAL) {
      v1.type.t = VT_PTR;
      v1.r = VT_LOCAL | VT_LVAL;
      v1.c.i = sv->c.i;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } иначе ако(v == VT_CONST) {
      v1.type.t = VT_PTR;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } иначе ако(v < VT_CONST) {
      base=intr(v);
      fc=sign=0;
      v=VT_LOCAL;
    }
    ако(v == VT_LOCAL) {
      ако(is_float(ft)) {
	calcaddr(&base,&fc,&sign,1020,2);
#ifdef TCC_ARM_VFP
        op=0xED100A00; /* flds */
        ако(!sign)
          op|=0x800000;
        ако ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* flds -> fldd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(base<<16));
#иначе
	op=0xED100100;
	ако(!sign)
	  op|=0x800000;
	ако ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#ако LDOUBLE_SIZE != 8
	иначе ако ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#endif
	o(op|(fpr(r)<<12)|(fc>>2)|(base<<16));
#endif
      } иначе ако((ft & (VT_BTYPE|VT_UNSIGNED)) == VT_BYTE
                || (ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&base,&fc,&sign,255,0);
	op=0xE1500090;
	ако ((ft & VT_BTYPE) == VT_SHORT)
	  op|=0x20;
	ако ((ft & VT_UNSIGNED) == 0)
	  op|=0x40;
	ако(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(base<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } иначе {
	calcaddr(&base,&fc,&sign,4095,0);
	op=0xE5100000;
	ако(!sign)
	  op|=0x800000;
        ако ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(base<<16));
      }
      върни;
    }
  } иначе {
    ако (v == VT_CONST) {
      op=stuff_const(0xE3A00000|(intr(r)<<12),sv->c.i);
      ако (fr & VT_SYM || !op)
	load_value(sv, r);
      иначе
        o(op);
      върни;
    } иначе ако (v == VT_LOCAL) {
      op=stuff_const(0xE28B0000|(intr(r)<<12),sv->c.i);
      ако (fr & VT_SYM || !op) {
	load_value(sv, r);
	o(0xE08B0000|(intr(r)<<12)|intr(r));
      } иначе
	o(op);
      върни;
    } иначе ако(v == VT_CMP) {
      o(mapcc(sv->c.i)|0x3A00001|(intr(r)<<12));
      o(mapcc(negcc(sv->c.i))|0x3A00000|(intr(r)<<12));
      върни;
    } иначе ако (v == VT_JMP || v == VT_JMPI) {
      цяло t;
      t = v & 1;
      o(0xE3A00000|(intr(r)<<12)|t);
      o(0xEA000000);
      gsym(sv->c.i);
      o(0xE3A00000|(intr(r)<<12)|(t^1));
      върни;
    } иначе ако (v < VT_CONST) {
      ако(is_float(ft))
#ifdef TCC_ARM_VFP
        o(0xEEB00A40|(vfpr(r)<<12)|vfpr(v)|T2CPR(ft)); /* fcpyX */
#иначе
	o(0xEE008180|(fpr(r)<<12)|fpr(v));
#endif
      иначе
	o(0xE1A00000|(intr(r)<<12)|intr(v));
      върни;
    }
  }
  tcc_error("load unimplemented!");
}

/* store register 'r' in lvalue 'v' */
void store(цяло r, SValue *sv)
{
  SValue v1;
  цяло v, ft, fc, fr, sign;
  uint32_t op, base;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  ако(fc>=0)
    sign=0;
  иначе {
    sign=1;
    fc=-fc;
  }

  v = fr & VT_VALMASK;
  ако (fr & VT_LVAL || fr == VT_LOCAL) {

    ако ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe500e000; /* str r, [lr, #0] */
        greloca(cur_text_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        върни;
    }

    base = 0xb; /* fp */
    ако(v < VT_CONST) {
      base=intr(v);
      v=VT_LOCAL;
      fc=sign=0;
    } иначе ако(v == VT_CONST) {
      v1.type.t = ft;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    }
    ако(v == VT_LOCAL) {
       ако(is_float(ft)) {
	calcaddr(&base,&fc,&sign,1020,2);
#ifdef TCC_ARM_VFP
        op=0xED000A00; /* fsts */
        ако(!sign)
          op|=0x800000;
        ако ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* fsts -> fstd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(base<<16));
#иначе
	op=0xED000100;
	ако(!sign)
	  op|=0x800000;
	ако ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#ако LDOUBLE_SIZE != 8
	иначе ако ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#endif
	o(op|(fpr(r)<<12)|(fc>>2)|(base<<16));
#endif
	върни;
      } иначе ако((ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&base,&fc,&sign,255,0);
	op=0xE14000B0;
	ако(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(base<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } иначе {
	calcaddr(&base,&fc,&sign,4095,0);
	op=0xE5000000;
	ако(!sign)
	  op|=0x800000;
        ако ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(base<<16));
      }
      върни;
    }
  }
  tcc_error("store unimplemented");
}

static void gadd_sp(цяло val)
{
  stuff_const_harder(0xE28DD000,val);
}

/* 'is_jmp' is '1' if it is a jump */
static void gcall_or_jmp(цяло is_jmp)
{
  цяло r;
  uint32_t x;
  ако ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
    /* constant case */
    ако(vtop->r & VT_SYM){
	x=encbranch(ind,ind+vtop->c.i,0);
	ако(x) {
	    /* relocation case */
	    greloc(cur_text_section, vtop->sym, ind, R_ARM_PC24);
	    o(x|(is_jmp?0xE0000000:0xE1000000));
	} иначе {
	    r = TREG_LR;
	    load_value(vtop, r);
	    ако(is_jmp)
	        o(0xE1A0F000 | intr(r)); // mov pc, r
	    иначе
		o(0xe12fff30 | intr(r)); // blx r
	}
     }иначе{
	ако(!is_jmp)
	    o(0xE28FE004); // add lr,pc,#4
	o(0xE51FF004);   // ldr pc,[pc,#-4]
	o(vtop->c.i);
     }
  } иначе {
    /* otherwise, indirect call */
#ifdef CONFIG_TCC_BCHECK
    vtop->r &= ~VT_MUSTBOUND;
#endif
    r = gv(RC_INT);
    ако(!is_jmp)
      o(0xE1A0E00F);       // mov lr,pc
    o(0xE1A0F000|intr(r)); // mov pc,r
  }
}

#ако defined(CONFIG_TCC_BCHECK)

static void gen_bounds_call(цяло v)
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
    цяло offset_modified = func_bound_offset != lbounds_section->data_offset;

    ако (!offset_modified && !func_bound_add_epilog)
        върни;

    /* add end of table info */
    bounds_ptr = section_ptr_add(lbounds_section, sizeof(addr_t));
    *bounds_ptr = 0;

    sym_data = get_sym_ref(&char_pointer_type, lbounds_section,
                           func_bound_offset, PTR_SIZE);

    /* generate bound local allocation */
    ако (offset_modified) {
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
static цяло is_hgen_float_aggr(CType *type)
{
  ако ((type->t & VT_BTYPE) == VT_STRUCT) {
    struct Sym *ref;
    цяло btype, nb_fields = 0;

    ref = type->ref->next;
    ако (ref) {
      btype = ref->type.t & VT_BTYPE;
      ако (btype == VT_FLOAT || btype == VT_DOUBLE) {
        за(; ref && btype == (ref->type.t & VT_BTYPE); ref = ref->next, nb_fields++)
            ;
        върни !ref && nb_fields <= 4;
      }
    }
  }
  върни 0;
}

struct avail_regs {
  signed char avail[3]; /* 3 holes max with only float and double alignments */
  цяло first_hole; /* first available hole */
  цяло last_hole; /* last available hole (none if equal to first_hole) */
  цяло first_free_reg; /* next free register in the sequence, hole excluded */
};

/* Find suitable registers for a VFP Co-Processor Register Candidate (VFP CPRC
   param) according to the rules described in the procedure call standard for
   the ARM architecture (AAPCS). If found, the registers are assigned to this
   VFP CPRC parameter. Registers are allocated in sequence unless a hole exists
   and the parameter is a single float.

   avregs: opaque structure to keep track of available VFP co-processor regs
   align: alignment constraints for the param, as returned by type_size()
   size: size of the parameter, as returned by type_size() */
цяло assign_vfpreg(struct avail_regs *avregs, цяло align, цяло size)
{
  цяло first_reg = 0;

  ако (avregs->first_free_reg == -1)
    върни -1;
  ако (align >> 3) { /* double alignment */
    first_reg = avregs->first_free_reg;
    /* alignment constraint not respected so use next reg and record hole */
    ако (first_reg & 1)
      avregs->avail[avregs->last_hole++] = first_reg++;
  } иначе { /* no special alignment (float or array of float) */
    /* if single float and a hole is available, assign the param to it */
    ако (size == 4 && avregs->first_hole != avregs->last_hole)
      върни avregs->avail[avregs->first_hole++];
    иначе
      first_reg = avregs->first_free_reg;
  }
  ако (first_reg + size / 4 <= 16) {
    avregs->first_free_reg = first_reg + size / 4;
    върни first_reg;
  }
  avregs->first_free_reg = -1;
  върни -1;
}

/* Returns whether all params need to be passed in core registers or not.
   This is the case for function part of the runtime ABI. */
цяло floats_in_core_regs(SValue *sval)
{
  ако (!sval->sym)
    върни 0;

  switch (sval->sym->v) {
    case TOK___floatundisf:
    case TOK___floatundidf:
    case TOK___fixunssfdi:
    case TOK___fixunsdfdi:
#ifndef TCC_ARM_VFP
    case TOK___fixunsxfdi:
#endif
    case TOK___floatdisf:
    case TOK___floatdidf:
    case TOK___fixsfdi:
    case TOK___fixdfdi:
      върни 1;

    default:
      върни 0;
  }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC цяло gfunc_sret(CType *vt, цяло variadic, CType *ret, цяло *ret_align, цяло *regsize) {
#ifdef TCC_ARM_EABI
    цяло size, align;
    size = type_size(vt, &align);
    ако (float_abi == ARM_HARD_FLOAT && !variadic &&
        (is_float(vt->t) || is_hgen_float_aggr(vt))) {
        *ret_align = 8;
	*regsize = 8;
        ret->ref = NULL;
        ret->t = VT_DOUBLE;
        върни (size + 7) >> 3;
    } иначе ако (size > 0 && size <= 4) {
        *ret_align = 4;
	*regsize = 4;
        ret->ref = NULL;
        ret->t = VT_INT;
        върни 1;
    } иначе
        върни 0;
#иначе
    върни 0;
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
enum reg_class {
	STACK_CLASS = 0,
	CORE_STRUCT_CLASS,
	VFP_CLASS,
	VFP_STRUCT_CLASS,
	CORE_CLASS,
	NB_CLASSES
};

struct param_plan {
    цяло start; /* first reg or addr used depending on the class */
    цяло end; /* last reg used or next free addr depending on the class */
    SValue *sval; /* pointer to SValue on the value stack */
    struct param_plan *prev; /*  previous element in this class */
};

struct plan {
    struct param_plan *pplans; /* array of all the param plans */
    struct param_plan *clsplans[NB_CLASSES]; /* per class lists of param plans */
    цяло nb_plans;
};

static void add_param_plan(struct plan* plan, цяло cls, цяло start, цяло end, SValue *v)
{
    struct param_plan *p = &plan->pplans[plan->nb_plans++];
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
static цяло assign_regs(цяло nb_args, цяло float_abi, struct plan *plan, цяло *todo)
{
  цяло i, size, align;
  цяло ncrn /* next core register number */, nsaa /* next stacked argument address*/;
  struct avail_regs avregs = {{0}};

  ncrn = nsaa = 0;
  *todo = 0;

  за(i = nb_args; i-- ;) {
    цяло j, start_vfpreg = 0;
    CType type = vtop[-i].type;
    type.t &= ~VT_ARRAY;
    size = type_size(&type, &align);
    size = (size + 3) & ~3;
    align = (align + 3) & ~3;
    switch(vtop[-i].type.t & VT_BTYPE) {
      case VT_STRUCT:
      case VT_FLOAT:
      case VT_DOUBLE:
      case VT_LDOUBLE:
      ако (float_abi == ARM_HARD_FLOAT) {
        цяло is_hfa = 0; /* Homogeneous float aggregate */

        ако (is_float(vtop[-i].type.t)
            || (is_hfa = is_hgen_float_aggr(&vtop[-i].type))) {
          цяло end_vfpreg;

          start_vfpreg = assign_vfpreg(&avregs, align, size);
          end_vfpreg = start_vfpreg + ((size - 1) >> 2);
          ако (start_vfpreg >= 0) {
            add_param_plan(plan, is_hfa ? VFP_STRUCT_CLASS : VFP_CLASS,
                start_vfpreg, end_vfpreg, &vtop[-i]);
            continue;
          } иначе
            break;
        }
      }
      ncrn = (ncrn + (align-1)/4) & ~((align/4) - 1);
      ако (ncrn + size/4 <= 4 || (ncrn < 4 && start_vfpreg != -1)) {
        /* The parameter is allocated both in core register and on stack. As
	 * such, it can be of either class: it would either be the last of
	 * CORE_STRUCT_CLASS or the first of STACK_CLASS. */
        за (j = ncrn; j < 4 && j < ncrn + size / 4; j++)
          *todo|=(1<<j);
        add_param_plan(plan, CORE_STRUCT_CLASS, ncrn, j, &vtop[-i]);
        ncrn += size/4;
        ако (ncrn > 4)
          nsaa = (ncrn - 4) * 4;
      } иначе {
        ncrn = 4;
        break;
      }
      continue;
      default:
      ако (ncrn < 4) {
        цяло is_long = (vtop[-i].type.t & VT_BTYPE) == VT_LLONG;

        ако (is_long) {
          ncrn = (ncrn + 1) & -2;
          ако (ncrn == 4)
            break;
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
  върни nsaa;
}

/* Copy parameters to their final destination (core reg, VFP reg or stack) for
   function call.

   nb_args: number of parameters the function take
   plan: the overall assignment plan for parameters
   todo: a bitmap indicating what core reg will hold a parameter

   Returns the number of SValue added by this function on the value stack */
static цяло copy_params(цяло nb_args, struct plan *plan, цяло todo)
{
  цяло size, align, r, i, nb_extra_sval = 0;
  struct param_plan *pplan;
  цяло pass = 0;

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
  за(i = 0; i < NB_CLASSES; i++) {
    за(pplan = plan->clsplans[i]; pplan; pplan = pplan->prev) {

      ако (pass
          && (i != CORE_CLASS || pplan->sval->r < VT_CONST))
        continue;

      vpushv(pplan->sval);
      pplan->sval->r = pplan->sval->r2 = VT_CONST; /* disable entry */
      switch(i) {
        case STACK_CLASS:
        case CORE_STRUCT_CLASS:
        case VFP_STRUCT_CLASS:
          ако ((pplan->sval->type.t & VT_BTYPE) == VT_STRUCT) {
            цяло padding = 0;
            size = type_size(&pplan->sval->type, &align);
            /* align to stack align size */
            size = (size + 3) & ~3;
            ако (i == STACK_CLASS && pplan->prev)
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
            ако (i == VFP_STRUCT_CLASS) {
              цяло first = pplan->start, nb = pplan->end - first + 1;
              /* vpop.32 {pplan->start, ..., pplan->end} */
              o(0xECBD0A00|(first&1)<<22|(first>>1)<<12|nb);
              /* No need to write the register used to a SValue since VFP regs
                 cannot be used for gcall_or_jmp */
            }
          } иначе {
            ако (is_float(pplan->sval->type.t)) {
#ifdef TCC_ARM_VFP
              r = vfpr(gv(RC_FLOAT)) << 12;
              ако ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                size = 4;
              иначе {
                size = 8;
                r |= 0x101; /* vpush.32 -> vpush.64 */
              }
              o(0xED2D0A01 + r); /* vpush */
#иначе
              r = fpr(gv(RC_FLOAT)) << 12;
              ако ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                size = 4;
              иначе ако ((pplan->sval->type.t & VT_BTYPE) == VT_DOUBLE)
                size = 8;
              иначе
                size = LDOUBLE_SIZE;
              ако (size == 12)
                r |= 0x400000;
              иначе ако(size == 8)
                r|=0x8000;

              o(0xED2D0100|r|(size>>2)); /* some kind of vpush for FPA */
#endif
            } иначе {
              /* simple type (currently always same size) */
              /* XXX: implicit cast ? */
              size=4;
              ако ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
                lexpand();
                size = 8;
                r = gv(RC_INT);
                o(0xE52D0004|(intr(r)<<12)); /* push r */
                vtop--;
              }
              r = gv(RC_INT);
              o(0xE52D0004|(intr(r)<<12)); /* push r */
            }
            ако (i == STACK_CLASS && pplan->prev)
              gadd_sp(pplan->prev->end - pplan->start); /* Add padding if any */
          }
          break;

        case VFP_CLASS:
          gv(regmask(TREG_F0 + (pplan->start >> 1)));
          ако (pplan->start & 1) { /* Must be in upper part of double register */
            o(0xEEF00A40|((pplan->start>>1)<<12)|(pplan->start>>1)); /* vmov.f32 s(n+1), sn */
            vtop->r = VT_CONST; /* avoid being saved on stack by gv for next float */
          }
          break;

        case CORE_CLASS:
          ако ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
            lexpand();
            gv(regmask(pplan->end));
            pplan->sval->r2 = vtop->r;
            vtop--;
          }
          gv(regmask(pplan->start));
          /* Mark register as used so that gcall_or_jmp use another one
             (regs >=4 are free as never used to pass parameters) */
          pplan->sval->r = vtop->r;
          break;
      }
      vtop--;
    }
  }

  /* second pass to restore registers that were saved on stack by accident.
     Maybe redundant after the "lvalue_save" patch in tccgen.c:gv() */
  ако (++pass < 2)
    goto again;

  ако(todo) {
    o(0xE8BD0000|todo); /* pop {todo} */
    за(pplan = plan->clsplans[CORE_STRUCT_CLASS]; pplan; pplan = pplan->prev) {
      цяло r;
      pplan->sval->r = pplan->start;
      /* An SValue can only pin 2 registers at best (r and r2) but a structure
         can occupy more than 2 registers. Thus, we need to push on the value
         stack some fake parameter to have on SValue for each registers used
         by a structure (r2 is not used). */
      за (r = pplan->start + 1; r <= pplan->end; r++) {
        ако (todo & (1 << r)) {
          nb_extra_sval++;
          vpushi(0);
          vtop->r = r;
        }
      }
    }
  }
  върни nb_extra_sval;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
void gfunc_call(цяло nb_args)
{
  цяло args_size;
  цяло def_float_abi = float_abi;
  цяло todo;
  struct plan plan;
#ifdef TCC_ARM_EABI
  цяло variadic;
#endif

#ifdef CONFIG_TCC_BCHECK
  ако (tcc_state->do_bounds_check)
    gbound_args(nb_args);
#endif

  save_regs(nb_args + 1);

#ifdef TCC_ARM_EABI
  ако (float_abi == ARM_HARD_FLOAT) {
    variadic = (vtop[-nb_args].type.ref->f.func_type == FUNC_ELLIPSIS);
    ако (variadic || floats_in_core_regs(&vtop[-nb_args]))
      float_abi = ARM_SOFTFP_FLOAT;
  }
#endif

  memset(&plan, 0, sizeof plan);
  ако (nb_args)
    plan.pplans = tcc_malloc(nb_args * sizeof(*plan.pplans));

  args_size = assign_regs(nb_args, float_abi, &plan, &todo);

#ifdef TCC_ARM_EABI
  ако (args_size & 7) { /* Stack must be 8 byte aligned at fct call for EABI */
    args_size = (args_size + 7) & ~7;
    o(0xE24DD004); /* sub sp, sp, #4 */
  }
#endif

  nb_args += copy_params(nb_args, &plan, todo);
  tcc_free(plan.pplans);

  /* Move fct SValue on top as required by gcall_or_jmp */
  vrotb(nb_args + 1);
  gcall_or_jmp(0);
  ако (args_size)
      gadd_sp(args_size); /* pop all parameters passed on the stack */
#ако defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  ако(float_abi == ARM_SOFTFP_FLOAT && is_float(vtop->type.ref->type.t)) {
    ако((vtop->type.ref->type.t & VT_BTYPE) == VT_FLOAT) {
      o(0xEE000A10); /*vmov s0, r0 */
    } иначе {
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
  цяло n, nf, size, align, rs, struct_ret = 0;
  цяло addr, pn, sn; /* pn=core, sn=stack */
  CType ret_type;

#ifdef TCC_ARM_EABI
  struct avail_regs avregs = {{0}};
#endif

  sym = func_type->ref;

  n = nf = 0;
  ако ((func_vt.t & VT_BTYPE) == VT_STRUCT &&
      !gfunc_sret(&func_vt, func_var, &ret_type, &align, &rs))
  {
    n++;
    struct_ret = 1;
    func_vc = 12; /* Offset from fp of the place to store the result */
  }
  за(sym2 = sym->next; sym2 && (n < 4 || nf < 16); sym2 = sym2->next) {
    size = type_size(&sym2->type, &align);
#ifdef TCC_ARM_EABI
    ако (float_abi == ARM_HARD_FLOAT && !func_var &&
        (is_float(sym2->type.t) || is_hgen_float_aggr(&sym2->type))) {
      цяло tmpnf = assign_vfpreg(&avregs, align, size);
      tmpnf += (size + 3) / 4;
      nf = (tmpnf > nf) ? tmpnf : nf;
    } иначе
#endif
    ако (n < 4)
      n += (size + 3) / 4;
  }
  o(0xE1A0C00D); /* mov ip,sp */
  ако (func_var)
    n=4;
  ако (n) {
    ако(n>4)
      n=4;
#ifdef TCC_ARM_EABI
    n=(n+1)&-2;
#endif
    o(0xE92D0000|((1<<n)-1)); /* save r0-r4 on stack if needed */
  }
  ако (nf) {
    ако (nf>16)
      nf=16;
    nf=(nf+1)&-2; /* nf => HARDFLOAT => EABI */
    o(0xED2D0A00|nf); /* save s0-s15 on stack if needed */
  }
  o(0xE92D5800); /* save fp, ip, lr */
  o(0xE1A0B00D); /* mov fp, sp */
  func_sub_sp_offset = ind;
  o(0xE1A00000); /* nop, leave space for stack adjustment in epilog */

#ifdef TCC_ARM_EABI
  ако (float_abi == ARM_HARD_FLOAT) {
    func_vc += nf * 4;
    memset(&avregs, 0, sizeof avregs);
  }
#endif
  pn = struct_ret, sn = 0;
  докато ((sym = sym->next)) {
    CType *type;
    type = &sym->type;
    size = type_size(type, &align);
    size = (size + 3) >> 2;
    align = (align + 3) & ~3;
#ifdef TCC_ARM_EABI
    ако (float_abi == ARM_HARD_FLOAT && !func_var && (is_float(sym->type.t)
        || is_hgen_float_aggr(&sym->type))) {
      цяло fpn = assign_vfpreg(&avregs, align, size << 2);
      ако (fpn >= 0)
        addr = fpn * 4;
      иначе
        goto from_stack;
    } иначе
#endif
    ако (pn < 4) {
#ifdef TCC_ARM_EABI
        pn = (pn + (align-1)/4) & -(align/4);
#endif
      addr = (nf + pn) * 4;
      pn += size;
      ако (!sn && pn > 4)
        sn = (pn - 4);
    } иначе {
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
  ако (tcc_state->do_bounds_check)
    gen_bounds_prolog();
#endif
}

/* generate function epilog */
void gfunc_epilog(void)
{
  uint32_t x;
  цяло diff;

#ifdef CONFIG_TCC_BCHECK
  ако (tcc_state->do_bounds_check)
    gen_bounds_epilog();
#endif
  /* Copy float return value to core register if base standard is used and
     float computation is made with VFP */
#ако defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  ако ((float_abi == ARM_SOFTFP_FLOAT || func_var) && is_float(func_vt.t)) {
    ако((func_vt.t & VT_BTYPE) == VT_FLOAT)
      o(0xEE100A10); /* fmrs r0, s0 */
    иначе {
      o(0xEE100B10); /* fmrdl r0, d0 */
      o(0xEE301B10); /* fmrdh r1, d0 */
    }
  }
#endif
  o(0xE89BA800); /* restore fp, sp, pc */
  diff = (-loc + 3) & -4;
#ifdef TCC_ARM_EABI
  ако(!leaffunc)
    diff = ((diff + 11) & -8) - 4;
#endif
  ако(diff > 0) {
    x=stuff_const(0xE24BD000, diff); /* sub sp,fp,# */
    ако(x)
      *(uint32_t *)(cur_text_section->data + func_sub_sp_offset) = x;
    иначе {
      цяло addr;
      addr=ind;
      o(0xE59FC004); /* ldr ip,[pc+4] */
      o(0xE04BD00C); /* sub sp,fp,ip  */
      o(0xE1A0F00E); /* mov pc,lr */
      o(diff);
      *(uint32_t *)(cur_text_section->data + func_sub_sp_offset) = 0xE1000000|encbranch(func_sub_sp_offset,addr,1);
    }
  }
}

ST_FUNC void gen_fill_nops(цяло bytes)
{
    ако ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    докато (bytes > 0) {
	o(0xE1A00000);
	bytes -= 4;
    }
}

/* generate a jump to a label */
ST_FUNC цяло gjmp(цяло t)
{
  цяло r;
  ако (nocode_wanted)
    върни t;
  r=ind;
  o(0xE0000000|encbranch(r,t,1));
  върни r;
}

/* generate a jump to a fixed address */
ST_FUNC void gjmp_addr(цяло a)
{
  gjmp(a);
}

ST_FUNC цяло gjmp_cond(цяло op, цяло t)
{
  цяло r;
  ако (nocode_wanted)
    върни t;
  r=ind;
  op=mapcc(op);
  op|=encbranch(r,t,1);
  o(op);
  върни r;
}

ST_FUNC цяло gjmp_append(цяло n, цяло t)
{
  uint32_t *x;
  цяло p,lp;
  ако(n) {
    p = n;
    do {
      p = decbranch(lp=p);
    } докато(p);
    x = (uint32_t *)(cur_text_section->data + lp);
    *x &= 0xff000000;
    *x |= encbranch(lp,t,1);
    t = n;
  }
  върни t;
}

/* generate an integer binary operation */
void gen_opi(цяло op)
{
  цяло c, func = 0;
  uint32_t opc = 0, r, fr;
  unsigned short retreg = REG_IRET;

  c=0;
  switch(op) {
    case '+':
      opc = 0x8;
      c=1;
      break;
    case TOK_ADDC1: /* add with carry generation */
      opc = 0x9;
      c=1;
      break;
    case '-':
      opc = 0x4;
      c=1;
      break;
    case TOK_SUBC1: /* sub with carry generation */
      opc = 0x5;
      c=1;
      break;
    case TOK_ADDC2: /* add with carry use */
      opc = 0xA;
      c=1;
      break;
    case TOK_SUBC2: /* sub with carry use */
      opc = 0xC;
      c=1;
      break;
    case '&':
      opc = 0x0;
      c=1;
      break;
    case '^':
      opc = 0x2;
      c=1;
      break;
    case '|':
      opc = 0x18;
      c=1;
      break;
    case '*':
      gv2(RC_INT, RC_INT);
      r = vtop[-1].r;
      fr = vtop[0].r;
      vtop--;
      o(0xE0000090|(intr(r)<<16)|(intr(r)<<8)|intr(fr));
      върни;
    case TOK_SHL:
      opc = 0;
      c=2;
      break;
    case TOK_SHR:
      opc = 1;
      c=2;
      break;
    case TOK_SAR:
      opc = 2;
      c=2;
      break;
    case '/':
    case TOK_PDIV:
      func=TOK___divsi3;
      c=3;
      break;
    case TOK_UDIV:
      func=TOK___udivsi3;
      c=3;
      break;
    case '%':
#ifdef TCC_ARM_EABI
      func=TOK___aeabi_idivmod;
      retreg=REG_IRE2;
#иначе
      func=TOK___modsi3;
#endif
      c=3;
      break;
    case TOK_UMOD:
#ifdef TCC_ARM_EABI
      func=TOK___aeabi_uidivmod;
      retreg=REG_IRE2;
#иначе
      func=TOK___umodsi3;
#endif
      c=3;
      break;
    case TOK_UMULL:
      gv2(RC_INT, RC_INT);
      r=intr(vtop[-1].r2=get_reg(RC_INT));
      c=vtop[-1].r;
      vtop[-1].r=get_reg_ex(RC_INT,regmask(c));
      vtop--;
      o(0xE0800090|(r<<16)|(intr(vtop->r)<<12)|(intr(c)<<8)|intr(vtop[1].r));
      върни;
    default:
      opc = 0x15;
      c=1;
      break;
  }
  switch(c) {
    case 1:
      ако((vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	ако(opc == 4 || opc == 5 || opc == 0xc) {
	  vswap();
	  opc|=2; // sub -> rsb
	}
      }
      vswap();
      c=intr(gv(RC_INT));
      vswap();
      opc=0xE0000000|(opc<<20);
      ако((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	uint32_t x;
	x=stuff_const(opc|0x2000000|(c<<16),vtop->c.i);
	ако(x) {
	  ако ((x & 0xfff00000) == 0xe3500000)   // cmp rx,#c
	    o(x);
	  иначе {
	    r=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	    o(x|(r<<12));
	  }
	  goto done;
	}
      }
      fr=intr(gv(RC_INT));
#ifdef CONFIG_TCC_BCHECK
      ако ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
        vswap();
        c=intr(gv(RC_INT));
        vswap();
      }
#endif
      ако ((opc & 0xfff00000) == 0xe1500000) // cmp rx,ry
	o(opc|(c<<16)|fr);
      иначе {
        r=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
        o(opc|(c<<16)|(r<<12)|fr);
      }
done:
      vtop--;
      ако (op >= TOK_ULT && op <= TOK_GT)
        vset_VT_CMP(op);
      break;
    case 2:
      opc=0xE1A00000|(opc<<5);
      vswap();
      r=intr(gv(RC_INT));
      vswap();
      ако ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	fr=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	c = vtop->c.i & 0x1f;
	o(opc|r|(c<<7)|(fr<<12));
      } иначе {
        fr=intr(gv(RC_INT));
#ifdef CONFIG_TCC_BCHECK
        ако ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=intr(gv(RC_INT));
          vswap();
        }
#endif
	c=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
	o(opc|r|(c<<12)|(fr<<8)|0x10);
      }
      vtop--;
      break;
    case 3:
      vpush_helper_func(func);
      vrott(3);
      gfunc_call(2);
      vpushi(0);
      vtop->r = retreg;
      break;
    default:
      tcc_error("gen_opi %i unimplemented!",op);
  }
}

#ifdef TCC_ARM_VFP
static цяло is_zero(цяло i)
{
  ако((vtop[i].r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    върни 0;
  ако (vtop[i].type.t == VT_FLOAT)
    върни (vtop[i].c.f == 0.f);
  иначе ако (vtop[i].type.t == VT_DOUBLE)
    върни (vtop[i].c.d == 0.0);
  върни (vtop[i].c.ld == 0.l);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
 *    two operands are guaranteed to have the same floating point type */
void gen_opf(цяло op)
{
  uint32_t x;
  цяло fneg=0,r;
  x=0xEE000A00|T2CPR(vtop->type.t);
  switch(op) {
    case '+':
      ако(is_zero(-1))
        vswap();
      ако(is_zero(0)) {
        vtop--;
        върни;
      }
      x|=0x300000;
      break;
    case '-':
      x|=0x300040;
      ако(is_zero(0)) {
        vtop--;
        върни;
      }
      ако(is_zero(-1)) {
        x|=0x810000; /* fsubX -> fnegX */
        vswap();
        vtop--;
        fneg=1;
      }
      break;
    case '*':
      x|=0x200000;
      break;
    case '/':
      x|=0x800000;
      break;
    default:
      ако(op < TOK_ULT || op > TOK_GT) {
        tcc_error("unknown fp op %x!",op);
        върни;
      }
      ако(is_zero(-1)) {
        vswap();
        switch(op) {
          case TOK_LT: op=TOK_GT; break;
          case TOK_GE: op=TOK_ULE; break;
          case TOK_LE: op=TOK_GE; break;
          case TOK_GT: op=TOK_ULT; break;
        }
      }
      x|=0xB40040; /* fcmpX */
      ако(op!=TOK_EQ && op!=TOK_NE)
        x|=0x80; /* fcmpX -> fcmpeX */
      ако(is_zero(0)) {
        vtop--;
        o(x|0x10000|(vfpr(gv(RC_FLOAT))<<12)); /* fcmp(e)X -> fcmp(e)zX */
      } иначе {
        gv2(RC_FLOAT,RC_FLOAT);
        x|=vfpr(vtop[0].r);
        o(x|(vfpr(vtop[-1].r) << 12));
        vtop--;
      }
      o(0xEEF1FA10); /* fmstat */

      switch(op) {
        case TOK_LE: op=TOK_ULE; break;
        case TOK_LT: op=TOK_ULT; break;
        case TOK_UGE: op=TOK_GE; break;
        case TOK_UGT: op=TOK_GT; break;
      }
      vset_VT_CMP(op);
      върни;
  }
  r=gv(RC_FLOAT);
  x|=vfpr(r);
  r=regmask(r);
  ако(!fneg) {
    цяло r2;
    vswap();
    r2=gv(RC_FLOAT);
    x|=vfpr(r2)<<16;
    r|=regmask(r2);
#ifdef CONFIG_TCC_BCHECK
    ако ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
      vswap();
      r=gv(RC_FLOAT);
      vswap();
      x=(x&~0xf)|vfpr(r);
    }
#endif
  }
  vtop->r=get_reg_ex(RC_FLOAT,r);
  ако(!fneg)
    vtop--;
  o(x|(vfpr(vtop->r)<<12));
}

#иначе
static uint32_t is_fconst()
{
  long double f;
  uint32_t r;
  ако((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    върни 0;
  ако (vtop->type.t == VT_FLOAT)
    f = vtop->c.f;
  иначе ако (vtop->type.t == VT_DOUBLE)
    f = vtop->c.d;
  иначе
    f = vtop->c.ld;
  ако(!ieee_finite(f))
    върни 0;
  r=0x8;
  ако(f<0.0) {
    r=0x18;
    f=-f;
  }
  ако(f==0.0)
    върни r;
  ако(f==1.0)
    върни r|1;
  ако(f==2.0)
    върни r|2;
  ако(f==3.0)
    върни r|3;
  ако(f==4.0)
    върни r|4;
  ако(f==5.0)
    върни r|5;
  ако(f==0.5)
    върни r|6;
  ако(f==10.0)
    върни r|7;
  върни 0;
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
void gen_opf(цяло op)
{
  uint32_t x, r, r2, c1, c2;
  //fputs("gen_opf\n",stderr);
  vswap();
  c1 = is_fconst();
  vswap();
  c2 = is_fconst();
  x=0xEE000100;
  ако ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
    x|=0x80;
#ако LDOUBLE_SIZE != 8
  иначе ако ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE)
    x|=0x80000;
#endif

  switch(op)
  {
    case '+':
      ако(!c2) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      ако(c2) {
	ако(c2>0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
      } иначе {
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        ако ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      break;
    case '-':
      ако(c2) {
	ако(c2<=0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } иначе ако(c1 && c1<=0xf) {
	x|=0x300000; // rsf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } иначе {
	x|=0x200000; // suf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        ако ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      break;
    case '*':
      ако(!c2 || c2>0xf) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      ако(c2 && c2<=0xf)
	r2=c2;
      иначе {
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        ако ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      x|=0x100000; // muf
      break;
    case '/':
      ако(c2 && c2<=0xf) {
	x|=0x400000; // dvf
	r2=c2;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } иначе ако(c1 && c1<=0xf) {
	x|=0x500000; // rdf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } иначе {
	x|=0x400000; // dvf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
        ако ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#endif
      }
      break;
    default:
      ако(op >= TOK_ULT && op <= TOK_GT) {
	x|=0xd0f110; // cmfe
/* bug (intention?) in Linux FPU emulator
   doesn't set carry if equal */
	switch(op) {
	  case TOK_ULT:
	  case TOK_UGE:
	  case TOK_ULE:
	  case TOK_UGT:
            tcc_error("unsigned comparison on floats?");
	    break;
	  case TOK_LT:
            op=TOK_Nset;
	    break;
	  case TOK_LE:
            op=TOK_ULE; /* correct in unordered case only if AC bit in FPSR set */
	    break;
	  case TOK_EQ:
	  case TOK_NE:
	    x&=~0x400000; // cmfe -> cmf
	    break;
	}
	ако(c1 && !c2) {
	  c2=c1;
	  vswap();
	  switch(op) {
            case TOK_Nset:
              op=TOK_GT;
	      break;
            case TOK_GE:
	      op=TOK_ULE;
	      break;
	    case TOK_ULE:
              op=TOK_GE;
	      break;
            case TOK_GT:
              op=TOK_Nset;
	      break;
	  }
	}
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	ако(c2) {
	  ако(c2>0xf)
	    x|=0x200000;
	  r2=c2&0xf;
	} иначе {
	  r2=fpr(gv(RC_FLOAT));
#ifdef CONFIG_TCC_BCHECK
          ако ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            r=fpr(gv(RC_FLOAT));
            vswap();
          }
#endif
	}
        --vtop;
        vset_VT_CMP(op);
        ++vtop;
      } иначе {
        tcc_error("unknown fp op %x!",op);
	върни;
      }
  }
  ако(vtop[-1].r == VT_CMP)
    c1=15;
  иначе {
    c1=vtop->r;
    ако(r2&0x8)
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
ST_FUNC void gen_cvt_itof(цяло t)
{
  uint32_t r, r2;
  цяло bt;
  bt=vtop->type.t & VT_BTYPE;
  ако(bt == VT_INT || bt == VT_SHORT || bt == VT_BYTE) {
#ifndef TCC_ARM_VFP
    uint32_t dsize = 0;
#endif
    r=intr(gv(RC_INT));
#ifdef TCC_ARM_VFP
    r2=vfpr(vtop->r=get_reg(RC_FLOAT));
    o(0xEE000A10|(r<<12)|(r2<<16)); /* fmsr */
    r2|=r2<<12;
    ако(!(vtop->type.t & VT_UNSIGNED))
      r2|=0x80;                /* fuitoX -> fsituX */
    o(0xEEB80A40|r2|T2CPR(t)); /* fYitoX*/
#иначе
    r2=fpr(vtop->r=get_reg(RC_FLOAT));
    ако((t & VT_BTYPE) != VT_FLOAT)
      dsize=0x80;    /* flts -> fltd */
    o(0xEE000110|dsize|(r2<<16)|(r<<12)); /* flts */
    ако((vtop->type.t & (VT_UNSIGNED|VT_BTYPE)) == (VT_UNSIGNED|VT_INT)) {
      uint32_t off = 0;
      o(0xE3500000|(r<<12));        /* cmp */
      r=fpr(get_reg(RC_FLOAT));
      ако(last_itod_magic) {
	off=ind+8-last_itod_magic;
	off/=4;
	ако(off>255)
	  off=0;
      }
      o(0xBD1F0100|(r<<12)|off);    /* ldflts */
      ако(!off) {
        o(0xEA000000);              /* b */
        last_itod_magic=ind;
        o(0x4F800000);              /* 4294967296.0f */
      }
      o(0xBE000100|dsize|(r2<<16)|(r2<<12)|r); /* adflt */
    }
#endif
    върни;
  } иначе ако(bt == VT_LLONG) {
    цяло func;
    CType *func_type = 0;
    ако((t & VT_BTYPE) == VT_FLOAT) {
      func_type = &func_float_type;
      ако(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundisf;
      иначе
        func=TOK___floatdisf;
    } иначе ако((t & VT_BTYPE) == VT_DOUBLE) {
      func_type = &func_double_type;
      ако(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundidf;
      иначе
        func=TOK___floatdidf;
#ако LDOUBLE_SIZE != 8
    } иначе ако((t & VT_BTYPE) == VT_LDOUBLE) {
      func_type = &func_ldouble_type;
      ако(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundixf;
      иначе
        func=TOK___floatdixf;
#endif
    }
    ако(func_type) {
      vpushsym(func_type, external_helper_sym(func));
      vswap();
      gfunc_call(1);
      vpushi(0);
      vtop->r=TREG_F0;
      върни;
    }
  }
  tcc_error("unimplemented gen_cvt_itof %x!",vtop->type.t);
}

/* convert fp to int 't' type */
void gen_cvt_ftoi(цяло t)
{
  uint32_t r, r2;
  цяло u, func = 0;
  u=t&VT_UNSIGNED;
  t&=VT_BTYPE;
  r2=vtop->type.t & VT_BTYPE;
  ако(t==VT_INT) {
#ifdef TCC_ARM_VFP
    r=vfpr(gv(RC_FLOAT));
    u=u?0:0x10000;
    o(0xEEBC0AC0|(r<<12)|r|T2CPR(r2)|u); /* ftoXizY */
    r2=intr(vtop->r=get_reg(RC_INT));
    o(0xEE100A10|(r<<16)|(r2<<12));
    върни;
#иначе
    ако(u) {
      ако(r2 == VT_FLOAT)
        func=TOK___fixunssfsi;
      иначе ако(r2 == VT_DOUBLE)
	func=TOK___fixunsdfsi;
#ако LDOUBLE_SIZE != 8
      иначе ако(r2 == VT_LDOUBLE)
	func=TOK___fixunsxfsi;
#endif
    } иначе {
      r=fpr(gv(RC_FLOAT));
      r2=intr(vtop->r=get_reg(RC_INT));
      o(0xEE100170|(r2<<12)|r);
      върни;
    }
#endif
  } иначе ако(t == VT_LLONG) { // unsigned handled in gen_cvt_ftoi1
    ако(r2 == VT_FLOAT)
      func=TOK___fixsfdi;
    иначе ако(r2 == VT_DOUBLE)
      func=TOK___fixdfdi;
#ако LDOUBLE_SIZE != 8
    иначе ако(r2 == VT_LDOUBLE)
      func=TOK___fixxfdi;
#endif
  }
  ако(func) {
    vpush_helper_func(func);
    vswap();
    gfunc_call(1);
    vpushi(0);
    ако(t == VT_LLONG)
      vtop->r2 = REG_IRE2;
    vtop->r = REG_IRET;
    върни;
  }
  tcc_error("unimplemented gen_cvt_ftoi!");
}

/* convert from one floating point type to another */
void gen_cvt_ftof(цяло t)
{
#ifdef TCC_ARM_VFP
  uint32_t r = gv(RC_FLOAT);
  ако(((vtop->type.t & VT_BTYPE) == VT_FLOAT) != ((t & VT_BTYPE) == VT_FLOAT)) {
    r = vfpr(r);
    o(0xEEB70AC0|(r<<12)|r|T2CPR(vtop->type.t));
  }
#иначе
  /* all we have to do on i386 and FPA ARM is to put the float in a register */
  gv(RC_FLOAT);
#endif
}

/* increment tcov counter */
ST_FUNC void gen_increment_tcov (SValue *sv)
{
  цяло r1, r2;

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
ST_FUNC void gen_vla_sp_save(цяло addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    store(TREG_SP, &v);
}

/* Restore the SP from a location on the stack */
ST_FUNC void gen_vla_sp_restore(цяло addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    load(TREG_SP, &v);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC void gen_vla_alloc(CType *type, цяло align) {
    цяло r;
#ако defined(CONFIG_TCC_BCHECK)
    ако (tcc_state->do_bounds_check)
        vpushv(vtop);
#endif
    r = intr(gv(RC_INT));
#ако defined(CONFIG_TCC_BCHECK)
    ако (tcc_state->do_bounds_check)
        o(0xe2800001 | (r<<16)|(r<<12)); /* add r,r,#1 */
#endif
    o(0xE04D0000|(r<<12)|r); /* sub r, sp, r */
#ifdef TCC_ARM_EABI
    ако (align < 8)
        align = 8;
#иначе
    ако (align < 4)
        align = 4;
#endif
    ако (align & (align - 1))
        tcc_error("alignment is not a power of 2: %i", align);
    o(stuff_const(0xE3C0D000|(r<<16), align - 1)); /* bic sp, r, #align-1 */
    vpop();
#ако defined(CONFIG_TCC_BCHECK)
    ако (tcc_state->do_bounds_check) {
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
