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

#अगर_घोषित TARGET_DEFS_ONLY

#अगर defined(TCC_ARM_EABI) && !defined(TCC_ARM_VFP)
#त्रुटि "Currently TinyCC only supports float computation with VFP instructions"
#पूर्ण_अगर

/* number of available registers */
#अगर_घोषित TCC_ARM_VFP
#घोषणा NB_REGS            13
#अन्यथा
#घोषणा NB_REGS             9
#पूर्ण_अगर

#अगर_अघोषित CONFIG_TCC_CPUVER
# define CONFIG_TCC_CPUVER 5
#पूर्ण_अगर

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#घोषणा RC_INT     0x0001 /* generic integer register */
#घोषणा RC_FLOAT   0x0002 /* generic float register */
#घोषणा RC_R0      0x0004
#घोषणा RC_R1      0x0008
#घोषणा RC_R2      0x0010
#घोषणा RC_R3      0x0020
#घोषणा RC_R12     0x0040
#घोषणा RC_F0      0x0080
#घोषणा RC_F1      0x0100
#घोषणा RC_F2      0x0200
#घोषणा RC_F3      0x0400
#अगर_घोषित TCC_ARM_VFP
#घोषणा RC_F4      0x0800
#घोषणा RC_F5      0x1000
#घोषणा RC_F6      0x2000
#घोषणा RC_F7      0x4000
#पूर्ण_अगर
#घोषणा RC_IRET    RC_R0  /* function return: integer register */
#घोषणा RC_IRE2    RC_R1  /* function return: second integer register */
#घोषणा RC_FRET    RC_F0  /* function return: float register */

/* pretty names for the registers */
क्रमागत {
    TREG_R0 = 0,
    TREG_R1,
    TREG_R2,
    TREG_R3,
    TREG_R12,
    TREG_F0,
    TREG_F1,
    TREG_F2,
    TREG_F3,
#अगर_घोषित TCC_ARM_VFP
    TREG_F4,
    TREG_F5,
    TREG_F6,
    TREG_F7,
#पूर्ण_अगर
    TREG_SP = 13,
    TREG_LR,
};

#अगर_घोषित TCC_ARM_VFP
#घोषणा T2CPR(t) (((t) & VT_BTYPE) != VT_FLOAT ? 0x100 : 0)
#पूर्ण_अगर

/* return registers for function */
#घोषणा REG_IRET TREG_R0 /* single word int return register */
#घोषणा REG_IRE2 TREG_R1 /* second word return register (for long long) */
#घोषणा REG_FRET TREG_F0 /* float return register */

#अगर_घोषित TCC_ARM_EABI
#घोषणा TOK___divdi3 TOK___aeabi_ldivmod
#घोषणा TOK___moddi3 TOK___aeabi_ldivmod
#घोषणा TOK___udivdi3 TOK___aeabi_uldivmod
#घोषणा TOK___umoddi3 TOK___aeabi_uldivmod
#पूर्ण_अगर

/* defined if function parameters must be evaluated in reverse order */
#घोषणा INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#घोषणा PTR_आकार 4

/* long double size and alignment, in bytes */
#अगर_घोषित TCC_ARM_VFP
#घोषणा LDOUBLE_आकार  8
#पूर्ण_अगर

#अगर_अघोषित LDOUBLE_आकार
#घोषणा LDOUBLE_आकार  8
#पूर्ण_अगर

#अगर_घोषित TCC_ARM_EABI
#घोषणा LDOUBLE_ALIGN 8
#अन्यथा
#घोषणा LDOUBLE_ALIGN 4
#पूर्ण_अगर

#अगर LDOUBLE_आकार == 8
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#पूर्ण_अगर

/* maximum alignment (for aligned attribute support) */
#घोषणा MAX_ALIGN     8

#घोषणा CHAR_IS_UNSIGNED

#घोषणा ARM_SOFTFP_FLOAT 0
#घोषणा ARM_HARD_FLOAT 1

/******************************************************/
#अन्यथा /* ! TARGET_DEFS_ONLY */
/******************************************************/
#घोषणा USING_GLOBALS
#समावेश "tcc.h"

ST_तथ्य स्थिर अक्षर * स्थिर target_machine_defs =
    "__arm__\0"
    "__arm\0"
    "arm\0"
    "__arm_elf__\0"
    "__arm_elf\0"
    "arm_elf\0"
    "__ARM_ARCH_4__\0"
    "__ARMEL__\0"
    "__APCS_32__\0"
#अगर defined TCC_ARM_EABI
    "__ARM_EABI__\0"
#पूर्ण_अगर
    ;

ST_तथ्य स्थिर पूर्णांक reg_classes[NB_REGS] = {
    /* r0 */ RC_INT | RC_R0,
    /* r1 */ RC_INT | RC_R1,
    /* r2 */ RC_INT | RC_R2,
    /* r3 */ RC_INT | RC_R3,
    /* r12 */ RC_INT | RC_R12,
    /* f0 */ RC_FLOAT | RC_F0,
    /* f1 */ RC_FLOAT | RC_F1,
    /* f2 */ RC_FLOAT | RC_F2,
    /* f3 */ RC_FLOAT | RC_F3,
#अगर_घोषित TCC_ARM_VFP
 /* d4/s8 */ RC_FLOAT | RC_F4,
/* d5/s10 */ RC_FLOAT | RC_F5,
/* d6/s12 */ RC_FLOAT | RC_F6,
/* d7/s14 */ RC_FLOAT | RC_F7,
#पूर्ण_अगर
};

अटल पूर्णांक float_abi;
अटल पूर्णांक func_sub_sp_offset, last_itod_magic;
अटल पूर्णांक leaffunc;

#अगर defined(CONFIG_TCC_BCHECK)
अटल addr_t func_bound_offset;
अटल अचिन्हित दीर्घ func_bound_ind;
ST_तथ्य पूर्णांक func_bound_add_epilog;
#पूर्ण_अगर

#अगर defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
अटल CType float_type, double_type, func_float_type, func_double_type;
ST_FUNC व्योम arm_init(काष्ठा TCCState *s)
{
    float_type.t = VT_FLOAT;
    double_type.t = VT_DOUBLE;
    func_float_type.t = VT_FUNC;
    func_float_type.ref = sym_धकेलो(SYM_FIELD, &float_type, FUNC_CDECL, FUNC_OLD);
    func_double_type.t = VT_FUNC;
    func_double_type.ref = sym_धकेलो(SYM_FIELD, &double_type, FUNC_CDECL, FUNC_OLD);

    float_abi = s->float_abi;
#अगर_अघोषित TCC_ARM_HARDFLOAT
// XXX: Works on OpenBSD
// # warning "soft float ABI currently not supported: default to softfp"
#पूर्ण_अगर
}
#अन्यथा
#घोषणा func_float_type func_old_type
#घोषणा func_double_type func_old_type
#घोषणा func_ldouble_type func_old_type
ST_FUNC व्योम arm_init(काष्ठा TCCState *s)
{
#अगर 0
#अगर !defined (TCC_ARM_VFP)
    tcc_warning("Support for FPA is deprecated and will be removed in next"
                " release");
#पूर्ण_अगर
#अगर !defined (TCC_ARM_EABI)
    tcc_warning("Support for OABI is deprecated and will be removed in next"
                " release");
#पूर्ण_अगर
#पूर्ण_अगर
}
#पूर्ण_अगर

#घोषणा CHECK_R(r) ((r) >= TREG_R0 && (r) <= TREG_LR)

अटल पूर्णांक two2mask(पूर्णांक a,पूर्णांक b) {
  अगर (!CHECK_R(a) || !CHECK_R(b))
    tcc_error("compiler error! registers %i,%i is not valid",a,b);
  वापस (reg_classes[a]|reg_classes[b])&~(RC_INT|RC_FLOAT);
}

अटल पूर्णांक regmask(पूर्णांक r) {
  अगर (!CHECK_R(r))
    tcc_error("compiler error! register %i is not valid",r);
  वापस reg_classes[r]&~(RC_INT|RC_FLOAT);
}

/******************************************************/

व्योम o(uint32_t i)
{
  /* this is a good place to start adding big-endian support*/
  पूर्णांक ind1;
  अगर (nocode_wanted)
    वापस;
  ind1 = ind + 4;
  अगर (!cur_text_section)
    tcc_error("compiler error! This happens f.ex. if the compiler\n"
         "can't evaluate constant expressions outside of a function.");
  अगर (ind1 > cur_text_section->तथ्य_allocated)
    section_realloc(cur_text_section, ind1);
  cur_text_section->तथ्य[ind++] = i&255;
  i>>=8;
  cur_text_section->तथ्य[ind++] = i&255;
  i>>=8;
  cur_text_section->तथ्य[ind++] = i&255;
  i>>=8;
  cur_text_section->तथ्य[ind++] = i;
}

अटल uint32_t stuff_const(uint32_t op, uint32_t c)
{
  पूर्णांक try_neg=0;
  uint32_t nc = 0, negop = 0;

  चयन(op&0x1F00000)
  {
    हाल 0x800000: //add
    हाल 0x400000: //sub
      try_neg=1;
      negop=op^0xC00000;
      nc=-c;
      अवरोध;
    हाल 0x1A00000: //mov
    हाल 0x1E00000: //mvn
      try_neg=1;
      negop=op^0x400000;
      nc=~c;
      अवरोध;
    हाल 0x200000: //xor
      अगर(c==~0)
	वापस (op&0xF010F000)|((op>>16)&0xF)|0x1E00000;
      अवरोध;
    हाल 0x0: //and
      अगर(c==~0)
	वापस (op&0xF010F000)|((op>>16)&0xF)|0x1A00000;
    हाल 0x1C00000: //bic
      try_neg=1;
      negop=op^0x1C00000;
      nc=~c;
      अवरोध;
    हाल 0x1800000: //orr
      अगर(c==~0)
	वापस (op&0xFFF0FFFF)|0x1E00000;
      अवरोध;
  }
  करो {
    uint32_t m;
    पूर्णांक i;
    अगर(c<256) /* catch undefined <<32 */
      वापस op|c;
    क्रम(i=2;i<32;i+=2) {
      m=(0xffu>>i)|(0xffu<<(32-i));
      अगर(!(c&~m))
	वापस op|(i<<7)|(c<<i)|(c>>(32-i));
    }
    op=negop;
    c=nc;
  } जबतक(try_neg--);
  वापस 0;
}


//only add,sub
व्योम stuff_const_harder(uint32_t op, uint32_t v) {
  uint32_t x;
  x=stuff_const(op,v);
  अगर(x)
    o(x);
  अन्यथा {
    uint32_t a[16], nv, no, o2, n2;
    पूर्णांक i,j,k;
    a[0]=0xff;
    o2=(op&0xfff0ffff)|((op&0xf000)<<4);;
    क्रम(i=1;i<16;i++)
      a[i]=(a[i-1]>>2)|(a[i-1]<<30);
    क्रम(i=0;i<12;i++)
      क्रम(j=i<4?i+12:15;j>=i+4;j--)
	अगर((v&(a[i]|a[j]))==v) {
	  o(stuff_const(op,v&a[i]));
	  o(stuff_const(o2,v&a[j]));
	  वापस;
	}
    no=op^0xC00000;
    n2=o2^0xC00000;
    nv=-v;
    क्रम(i=0;i<12;i++)
      क्रम(j=i<4?i+12:15;j>=i+4;j--)
	अगर((nv&(a[i]|a[j]))==nv) {
	  o(stuff_const(no,nv&a[i]));
	  o(stuff_const(n2,nv&a[j]));
	  वापस;
	}
    क्रम(i=0;i<8;i++)
      क्रम(j=i+4;j<12;j++)
	क्रम(k=i<4?i+12:15;k>=j+4;k--)
	  अगर((v&(a[i]|a[j]|a[k]))==v) {
	    o(stuff_const(op,v&a[i]));
	    o(stuff_const(o2,v&a[j]));
	    o(stuff_const(o2,v&a[k]));
	    वापस;
	  }
    no=op^0xC00000;
    nv=-v;
    क्रम(i=0;i<8;i++)
      क्रम(j=i+4;j<12;j++)
	क्रम(k=i<4?i+12:15;k>=j+4;k--)
	  अगर((nv&(a[i]|a[j]|a[k]))==nv) {
	    o(stuff_const(no,nv&a[i]));
	    o(stuff_const(n2,nv&a[j]));
	    o(stuff_const(n2,nv&a[k]));
	    वापस;
	  }
    o(stuff_const(op,v&a[0]));
    o(stuff_const(o2,v&a[4]));
    o(stuff_const(o2,v&a[8]));
    o(stuff_const(o2,v&a[12]));
  }
}

uint32_t encbranch(पूर्णांक pos, पूर्णांक addr, पूर्णांक fail)
{
  addr-=pos+8;
  addr/=4;
  अगर(addr>=0x1000000 || addr<-0x1000000) {
    अगर(fail)
      tcc_error("FIXME: function bigger than 32MB");
    वापस 0;
  }
  वापस 0x0A000000|(addr&0xffffff);
}

पूर्णांक decbranch(पूर्णांक pos)
{
  पूर्णांक x;
  x=*(uint32_t *)(cur_text_section->तथ्य + pos);
  x&=0x00ffffff;
  अगर(x&0x800000)
    x-=0x1000000;
  वापस x*4+pos+8;
}

/* output a symbol and patch all calls to it */
व्योम gsym_addr(पूर्णांक t, पूर्णांक a)
{
  uint32_t *x;
  पूर्णांक lt;
  जबतक(t) {
    x=(uint32_t *)(cur_text_section->तथ्य + t);
    t=decbranch(lt=t);
    अगर(a==lt+4)
      *x=0xE1A00000; // nop
    अन्यथा {
      *x &= 0xff000000;
      *x |= encbranch(lt,a,1);
    }
  }
}

#अगर_घोषित TCC_ARM_VFP
अटल uint32_t vfpr(पूर्णांक r)
{
  अगर(r<TREG_F0 || r>TREG_F7)
    tcc_error("compiler error! register %i is no vfp register",r);
  वापस r - TREG_F0;
}
#अन्यथा
अटल uint32_t fpr(पूर्णांक r)
{
  अगर(r<TREG_F0 || r>TREG_F3)
    tcc_error("compiler error! register %i is no fpa register",r);
  वापस r - TREG_F0;
}
#पूर्ण_अगर

अटल uint32_t intr(पूर्णांक r)
{
  अगर(r == TREG_R12)
    वापस 12;
  अगर(r >= TREG_R0 && r <= TREG_R3)
    वापस r - TREG_R0;
  अगर (!(r >= TREG_SP && r <= TREG_LR))
    tcc_error("compiler error! register %i is no int register",r);
  वापस r + (13 - TREG_SP);
}

अटल व्योम calcaddr(uint32_t *base, पूर्णांक *off, पूर्णांक *sgn, पूर्णांक maxoff, अचिन्हित shift)
{
  अगर(*off>maxoff || *off&((1<<shift)-1)) {
    uint32_t x, y;
    x=0xE280E000;
    अगर(*sgn)
      x=0xE240E000;
    x|=(*base)<<16;
    *base=14; // lr
    y=stuff_const(x,*off&~maxoff);
    अगर(y) {
      o(y);
      *off&=maxoff;
      वापस;
    }
    y=stuff_const(x,(*off+maxoff)&~maxoff);
    अगर(y) {
      o(y);
      *sgn=!*sgn;
      *off=((*off+maxoff)&~maxoff)-*off;
      वापस;
    }
    stuff_const_harder(x,*off&~maxoff);
    *off&=maxoff;
  }
}

अटल uint32_t mapcc(पूर्णांक cc)
{
  चयन(cc)
  {
    हाल TOK_ULT:
      वापस 0x30000000; /* CC/LO */
    हाल TOK_UGE:
      वापस 0x20000000; /* CS/HS */
    हाल TOK_EQ:
      वापस 0x00000000; /* EQ */
    हाल TOK_NE:
      वापस 0x10000000; /* NE */
    हाल TOK_ULE:
      वापस 0x90000000; /* LS */
    हाल TOK_UGT:
      वापस 0x80000000; /* HI */
    हाल TOK_Nset:
      वापस 0x40000000; /* MI */
    हाल TOK_Nclear:
      वापस 0x50000000; /* PL */
    हाल TOK_LT:
      वापस 0xB0000000; /* LT */
    हाल TOK_GE:
      वापस 0xA0000000; /* GE */
    हाल TOK_LE:
      वापस 0xD0000000; /* LE */
    हाल TOK_GT:
      वापस 0xC0000000; /* GT */
  }
  tcc_error("unexpected condition code");
  वापस 0xE0000000; /* AL */
}

अटल पूर्णांक negcc(पूर्णांक cc)
{
  चयन(cc)
  {
    हाल TOK_ULT:
      वापस TOK_UGE;
    हाल TOK_UGE:
      वापस TOK_ULT;
    हाल TOK_EQ:
      वापस TOK_NE;
    हाल TOK_NE:
      वापस TOK_EQ;
    हाल TOK_ULE:
      वापस TOK_UGT;
    हाल TOK_UGT:
      वापस TOK_ULE;
    हाल TOK_Nset:
      वापस TOK_Nclear;
    हाल TOK_Nclear:
      वापस TOK_Nset;
    हाल TOK_LT:
      वापस TOK_GE;
    हाल TOK_GE:
      वापस TOK_LT;
    हाल TOK_LE:
      वापस TOK_GT;
    हाल TOK_GT:
      वापस TOK_LE;
  }
  tcc_error("unexpected condition code");
  वापस TOK_NE;
}

/* Load value into register r.
   Use relative/got addressing to avoid setting DT_TEXTREL */
अटल व्योम load_मूल्य(SValue *sv, पूर्णांक r)
{
#अगर CONFIG_TCC_CPUVER >= 7
    अगर (!(sv->r & VT_SYM)) {
        अचिन्हित x=sv->c.i;
        o(0xE3000000|intr(r)<<12|(x&0xFFF)|(x<<4&0xF0000)); /* movw rx,#x(lo) */
        अगर (x&0xFFFF0000)
          o(0xE3400000|intr(r)<<12|(x>>16&0xFFF)|(x>>12&0xF0000)); /* movt rx,#x(hi) */
        वापस;
    }
#पूर्ण_अगर
    o(0xE59F0000|(intr(r)<<12)); /* ldr r, [pc] */
    o(0xEA000000); /* b $+4 */
#अगर_अघोषित CONFIG_TCC_PIC
    अगर(sv->r & VT_SYM)
        greloc(cur_text_section, sv->sym, ind, R_ARM_ABS32);
    o(sv->c.i);
#अन्यथा
    अगर(sv->r & VT_SYM) {
	अगर (sv->sym->type.t & VT_STATIC) {
            greloc(cur_text_section, sv->sym, ind, R_ARM_REL32);
            o(sv->c.i - 12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
        }
        अन्यथा {
            greloc(cur_text_section, sv->sym, ind, R_ARM_GOT_PREL);
            o(-12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
            o(0xe5900000 | (intr(r)<<12) | (intr(r)<<16));  // ldr rx,[rx]
            अगर (sv->c.i)
              stuff_const_harder(0xe2800000 | (intr(r)<<12) | (intr(r)<<16),
                                 sv->c.i);
        }
    }
    अन्यथा
        o(sv->c.i);
#पूर्ण_अगर
}

/* load 'r' from value 'sv' */
व्योम load(पूर्णांक r, SValue *sv)
{
  पूर्णांक v, ft, fc, fr, sign;
  uint32_t op, base;
  SValue v1;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  अगर(fc>=0)
    sign=0;
  अन्यथा {
    sign=1;
    fc=-(अचिन्हित)fc;
  }

  v = fr & VT_VALMASK;
  अगर (fr & VT_LVAL) {

    अगर ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe510e000; /* ldr r, [lr, #0] */
        greloca(cur_text_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        वापस;
    }

    base = 0xB; // fp
    अगर(v == VT_LLOCAL) {
      v1.type.t = VT_PTR;
      v1.r = VT_LOCAL | VT_LVAL;
      v1.c.i = sv->c.i;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } अन्यथा अगर(v == VT_CONST) {
      v1.type.t = VT_PTR;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } अन्यथा अगर(v < VT_CONST) {
      base=intr(v);
      fc=sign=0;
      v=VT_LOCAL;
    }
    अगर(v == VT_LOCAL) {
      अगर(is_float(ft)) {
	calcaddr(&base,&fc,&sign,1020,2);
#अगर_घोषित TCC_ARM_VFP
        op=0xED100A00; /* flds */
        अगर(!sign)
          op|=0x800000;
        अगर ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* flds -> fldd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(base<<16));
#अन्यथा
	op=0xED100100;
	अगर(!sign)
	  op|=0x800000;
	अगर ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#अगर LDOUBLE_आकार != 8
	अन्यथा अगर ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#पूर्ण_अगर
	o(op|(fpr(r)<<12)|(fc>>2)|(base<<16));
#पूर्ण_अगर
      } अन्यथा अगर((ft & (VT_BTYPE|VT_UNSIGNED)) == VT_BYTE
                || (ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&base,&fc,&sign,255,0);
	op=0xE1500090;
	अगर ((ft & VT_BTYPE) == VT_SHORT)
	  op|=0x20;
	अगर ((ft & VT_UNSIGNED) == 0)
	  op|=0x40;
	अगर(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(base<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } अन्यथा {
	calcaddr(&base,&fc,&sign,4095,0);
	op=0xE5100000;
	अगर(!sign)
	  op|=0x800000;
        अगर ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(base<<16));
      }
      वापस;
    }
  } अन्यथा {
    अगर (v == VT_CONST) {
      op=stuff_const(0xE3A00000|(intr(r)<<12),sv->c.i);
      अगर (fr & VT_SYM || !op)
	load_मूल्य(sv, r);
      अन्यथा
        o(op);
      वापस;
    } अन्यथा अगर (v == VT_LOCAL) {
      op=stuff_const(0xE28B0000|(intr(r)<<12),sv->c.i);
      अगर (fr & VT_SYM || !op) {
	load_मूल्य(sv, r);
	o(0xE08B0000|(intr(r)<<12)|intr(r));
      } अन्यथा
	o(op);
      वापस;
    } अन्यथा अगर(v == VT_CMP) {
      o(mapcc(sv->c.i)|0x3A00001|(intr(r)<<12));
      o(mapcc(negcc(sv->c.i))|0x3A00000|(intr(r)<<12));
      वापस;
    } अन्यथा अगर (v == VT_JMP || v == VT_JMPI) {
      पूर्णांक t;
      t = v & 1;
      o(0xE3A00000|(intr(r)<<12)|t);
      o(0xEA000000);
      gsym(sv->c.i);
      o(0xE3A00000|(intr(r)<<12)|(t^1));
      वापस;
    } अन्यथा अगर (v < VT_CONST) {
      अगर(is_float(ft))
#अगर_घोषित TCC_ARM_VFP
        o(0xEEB00A40|(vfpr(r)<<12)|vfpr(v)|T2CPR(ft)); /* fcpyX */
#अन्यथा
	o(0xEE008180|(fpr(r)<<12)|fpr(v));
#पूर्ण_अगर
      अन्यथा
	o(0xE1A00000|(intr(r)<<12)|intr(v));
      वापस;
    }
  }
  tcc_error("load unimplemented!");
}

/* store register 'r' in lvalue 'v' */
व्योम store(पूर्णांक r, SValue *sv)
{
  SValue v1;
  पूर्णांक v, ft, fc, fr, sign;
  uint32_t op, base;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  अगर(fc>=0)
    sign=0;
  अन्यथा {
    sign=1;
    fc=-fc;
  }

  v = fr & VT_VALMASK;
  अगर (fr & VT_LVAL || fr == VT_LOCAL) {

    अगर ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe500e000; /* str r, [lr, #0] */
        greloca(cur_text_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        वापस;
    }

    base = 0xb; /* fp */
    अगर(v < VT_CONST) {
      base=intr(v);
      v=VT_LOCAL;
      fc=sign=0;
    } अन्यथा अगर(v == VT_CONST) {
      v1.type.t = ft;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      load(TREG_LR, &v1);
      base = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    }
    अगर(v == VT_LOCAL) {
       अगर(is_float(ft)) {
	calcaddr(&base,&fc,&sign,1020,2);
#अगर_घोषित TCC_ARM_VFP
        op=0xED000A00; /* fsts */
        अगर(!sign)
          op|=0x800000;
        अगर ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* fsts -> fstd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(base<<16));
#अन्यथा
	op=0xED000100;
	अगर(!sign)
	  op|=0x800000;
	अगर ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#अगर LDOUBLE_आकार != 8
	अन्यथा अगर ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#पूर्ण_अगर
	o(op|(fpr(r)<<12)|(fc>>2)|(base<<16));
#पूर्ण_अगर
	वापस;
      } अन्यथा अगर((ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&base,&fc,&sign,255,0);
	op=0xE14000B0;
	अगर(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(base<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } अन्यथा {
	calcaddr(&base,&fc,&sign,4095,0);
	op=0xE5000000;
	अगर(!sign)
	  op|=0x800000;
        अगर ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(base<<16));
      }
      वापस;
    }
  }
  tcc_error("store unimplemented");
}

अटल व्योम gadd_sp(पूर्णांक val)
{
  stuff_const_harder(0xE28DD000,val);
}

/* 'is_jmp' is '1' if it is a jump */
अटल व्योम gcall_or_jmp(पूर्णांक is_jmp)
{
  पूर्णांक r;
  uint32_t x;
  अगर ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
    /* constant case */
    अगर(vtop->r & VT_SYM){
	x=encbranch(ind,ind+vtop->c.i,0);
	अगर(x) {
	    /* relocation case */
	    greloc(cur_text_section, vtop->sym, ind, R_ARM_PC24);
	    o(x|(is_jmp?0xE0000000:0xE1000000));
	} अन्यथा {
	    r = TREG_LR;
	    load_मूल्य(vtop, r);
	    अगर(is_jmp)
	        o(0xE1A0F000 | intr(r)); // mov pc, r
	    अन्यथा
		o(0xe12fff30 | intr(r)); // blx r
	}
     }अन्यथा{
	अगर(!is_jmp)
	    o(0xE28FE004); // add lr,pc,#4
	o(0xE51FF004);   // ldr pc,[pc,#-4]
	o(vtop->c.i);
     }
  } अन्यथा {
    /* otherwise, indirect call */
#अगर_घोषित CONFIG_TCC_BCHECK
    vtop->r &= ~VT_MUSTBOUND;
#पूर्ण_अगर
    r = gv(RC_INT);
    अगर(!is_jmp)
      o(0xE1A0E00F);       // mov lr,pc
    o(0xE1A0F000|intr(r)); // mov pc,r
  }
}

#अगर defined(CONFIG_TCC_BCHECK)

अटल व्योम gen_bounds_call(पूर्णांक v)
{
    Sym *sym = external_helper_sym(v);

    greloc(cur_text_section, sym, ind, R_ARM_PC24);
    o(0xebfffffe);
}

अटल व्योम gen_bounds_prolog(व्योम)
{
    /* leave some room for bound checking code */
    func_bound_offset = lbounds_section->तथ्य_offset;
    func_bound_ind = ind;
    func_bound_add_epilog = 0;
    o(0xe1a00000);  /* ld r0,lbounds_section->data_offset */
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);  /* call __bound_local_new */
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
        o(0xe59f0000);  /* ldr r0, [pc] */
        o(0xea000000);  /* b $+4 */
        greloc(cur_text_section, sym_तथ्य, ind, R_ARM_REL32);
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
    greloc(cur_text_section, sym_तथ्य, ind, R_ARM_REL32);
    o(-12);  /* lbounds_section->data_offset */
    o(0xe080000f);  /* add r0,r0,pc */
    gen_bounds_call(TOK___bound_local_delete);
    o(0xecbd0b04); /* vpop {d0,d1} */
    o(0xe8bd0003); /* pop {r0,r1} */
}
#पूर्ण_अगर

/* Return whether a structure is an homogeneous float aggregate or not.
   The answer is true if all the elements of the structure are of the same
   primitive float type and there is less than 4 elements.

   type: the type corresponding to the structure to be tested */
अटल पूर्णांक is_hgen_float_aggr(CType *type)
{
  अगर ((type->t & VT_BTYPE) == VT_STRUCT) {
    काष्ठा Sym *ref;
    पूर्णांक btype, nb_fields = 0;

    ref = type->ref->अग्र;
    अगर (ref) {
      btype = ref->type.t & VT_BTYPE;
      अगर (btype == VT_FLOAT || btype == VT_DOUBLE) {
        क्रम(; ref && btype == (ref->type.t & VT_BTYPE); ref = ref->अग्र, nb_fields++)
            ;
        वापस !ref && nb_fields <= 4;
      }
    }
  }
  वापस 0;
}

काष्ठा avail_regs {
  चिन्हित अक्षर avail[3]; /* 3 holes max with only float and double alignments */
  पूर्णांक first_hole; /* first available hole */
  पूर्णांक last_hole; /* last available hole (none if equal to first_hole) */
  पूर्णांक first_free_reg; /* next free register in the sequence, hole excluded */
};

/* Find suitable registers for a VFP Co-Processor Register Candidate (VFP CPRC
   param) according to the rules described in the procedure call standard for
   the ARM architecture (AAPCS). If found, the registers are assigned to this
   VFP CPRC parameter. Registers are allocated in sequence unless a hole exists
   and the parameter is a single float.

   avregs: opaque structure to keep track of available VFP co-processor regs
   align: alignment constraints for the param, as returned by type_size()
   size: size of the parameter, as returned by type_size() */
पूर्णांक assign_vfpreg(काष्ठा avail_regs *avregs, पूर्णांक align, पूर्णांक आकार)
{
  पूर्णांक first_reg = 0;

  अगर (avregs->first_free_reg == -1)
    वापस -1;
  अगर (align >> 3) { /* double alignment */
    first_reg = avregs->first_free_reg;
    /* alignment constraint not respected so use next reg and record hole */
    अगर (first_reg & 1)
      avregs->avail[avregs->last_hole++] = first_reg++;
  } अन्यथा { /* no special alignment (float or array of float) */
    /* if single float and a hole is available, assign the param to it */
    अगर (आकार == 4 && avregs->first_hole != avregs->last_hole)
      वापस avregs->avail[avregs->first_hole++];
    अन्यथा
      first_reg = avregs->first_free_reg;
  }
  अगर (first_reg + आकार / 4 <= 16) {
    avregs->first_free_reg = first_reg + आकार / 4;
    वापस first_reg;
  }
  avregs->first_free_reg = -1;
  वापस -1;
}

/* Returns whether all params need to be passed in core registers or not.
   This is the case for function part of the runtime ABI. */
पूर्णांक floats_in_core_regs(SValue *sval)
{
  अगर (!sval->sym)
    वापस 0;

  चयन (sval->sym->v) {
    हाल TOK___floatundisf:
    हाल TOK___floatundidf:
    हाल TOK___fixunssfdi:
    हाल TOK___fixunsdfdi:
#अगर_अघोषित TCC_ARM_VFP
    हाल TOK___fixunsxfdi:
#पूर्ण_अगर
    हाल TOK___floatdisf:
    हाल TOK___floatdidf:
    हाल TOK___fixsfdi:
    हाल TOK___fixdfdi:
      वापस 1;

    शेष:
      वापस 0;
  }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC पूर्णांक gfunc_sret(CType *vt, पूर्णांक variadic, CType *ret, पूर्णांक *ret_align, पूर्णांक *regsize) {
#अगर_घोषित TCC_ARM_EABI
    पूर्णांक आकार, align;
    आकार = type_आकार(vt, &align);
    अगर (float_abi == ARM_HARD_FLOAT && !variadic &&
        (is_float(vt->t) || is_hgen_float_aggr(vt))) {
        *ret_align = 8;
	*regsize = 8;
        ret->ref = शून्य;
        ret->t = VT_DOUBLE;
        वापस (आकार + 7) >> 3;
    } अन्यथा अगर (आकार > 0 && आकार <= 4) {
        *ret_align = 4;
	*regsize = 4;
        ret->ref = शून्य;
        ret->t = VT_INT;
        वापस 1;
    } अन्यथा
        वापस 0;
#अन्यथा
    वापस 0;
#पूर्ण_अगर
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
क्रमागत reg_class {
	ढेर_CLASS = 0,
	CORE_STRUCT_CLASS,
	VFP_CLASS,
	VFP_STRUCT_CLASS,
	CORE_CLASS,
	NB_CLASSES
};

काष्ठा param_plan {
    पूर्णांक start; /* first reg or addr used depending on the class */
    पूर्णांक end; /* last reg used or next free addr depending on the class */
    SValue *sval; /* pointer to SValue on the value stack */
    काष्ठा param_plan *पूर्व; /*  previous element in this class */
};

काष्ठा plan {
    काष्ठा param_plan *pplans; /* array of all the param plans */
    काष्ठा param_plan *clsplans[NB_CLASSES]; /* per class lists of param plans */
    पूर्णांक nb_plans;
};

अटल व्योम add_param_plan(काष्ठा plan* plan, पूर्णांक cls, पूर्णांक start, पूर्णांक end, SValue *v)
{
    काष्ठा param_plan *p = &plan->pplans[plan->nb_plans++];
    p->पूर्व = plan->clsplans[cls];
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
अटल पूर्णांक assign_regs(पूर्णांक nb_args, पूर्णांक float_abi, काष्ठा plan *plan, पूर्णांक *todo)
{
  पूर्णांक i, आकार, align;
  पूर्णांक ncrn /* next core register number */, nsaa /* next stacked argument address*/;
  काष्ठा avail_regs avregs = {{0}};

  ncrn = nsaa = 0;
  *todo = 0;

  क्रम(i = nb_args; i-- ;) {
    पूर्णांक j, start_vfpreg = 0;
    CType type = vtop[-i].type;
    type.t &= ~VT_ARRAY;
    आकार = type_आकार(&type, &align);
    आकार = (आकार + 3) & ~3;
    align = (align + 3) & ~3;
    चयन(vtop[-i].type.t & VT_BTYPE) {
      हाल VT_STRUCT:
      हाल VT_FLOAT:
      हाल VT_DOUBLE:
      हाल VT_LDOUBLE:
      अगर (float_abi == ARM_HARD_FLOAT) {
        पूर्णांक is_hfa = 0; /* Homogeneous float aggregate */

        अगर (is_float(vtop[-i].type.t)
            || (is_hfa = is_hgen_float_aggr(&vtop[-i].type))) {
          पूर्णांक end_vfpreg;

          start_vfpreg = assign_vfpreg(&avregs, align, आकार);
          end_vfpreg = start_vfpreg + ((आकार - 1) >> 2);
          अगर (start_vfpreg >= 0) {
            add_param_plan(plan, is_hfa ? VFP_STRUCT_CLASS : VFP_CLASS,
                start_vfpreg, end_vfpreg, &vtop[-i]);
            जारी;
          } अन्यथा
            अवरोध;
        }
      }
      ncrn = (ncrn + (align-1)/4) & ~((align/4) - 1);
      अगर (ncrn + आकार/4 <= 4 || (ncrn < 4 && start_vfpreg != -1)) {
        /* The parameter is allocated both in core register and on stack. As
	 * such, it can be of either class: it would either be the last of
	 * CORE_STRUCT_CLASS or the first of STACK_CLASS. */
        क्रम (j = ncrn; j < 4 && j < ncrn + आकार / 4; j++)
          *todo|=(1<<j);
        add_param_plan(plan, CORE_STRUCT_CLASS, ncrn, j, &vtop[-i]);
        ncrn += आकार/4;
        अगर (ncrn > 4)
          nsaa = (ncrn - 4) * 4;
      } अन्यथा {
        ncrn = 4;
        अवरोध;
      }
      जारी;
      शेष:
      अगर (ncrn < 4) {
        पूर्णांक is_long = (vtop[-i].type.t & VT_BTYPE) == VT_LLONG;

        अगर (is_long) {
          ncrn = (ncrn + 1) & -2;
          अगर (ncrn == 4)
            अवरोध;
        }
        add_param_plan(plan, CORE_CLASS, ncrn, ncrn + is_long, &vtop[-i]);
        ncrn += 1 + is_long;
        जारी;
      }
    }
    nsaa = (nsaa + (align - 1)) & ~(align - 1);
    add_param_plan(plan, ढेर_CLASS, nsaa, nsaa + आकार, &vtop[-i]);
    nsaa += आकार; /* size already rounded up before */
  }
  वापस nsaa;
}

/* Copy parameters to their final destination (core reg, VFP reg or stack) for
   function call.

   nb_args: number of parameters the function take
   plan: the overall assignment plan for parameters
   todo: a bitmap indicating what core reg will hold a parameter

   Returns the number of SValue added by this function on the value stack */
अटल पूर्णांक copy_params(पूर्णांक nb_args, काष्ठा plan *plan, पूर्णांक todo)
{
  पूर्णांक आकार, align, r, i, nb_extra_sval = 0;
  काष्ठा param_plan *pplan;
  पूर्णांक pass = 0;

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
  क्रम(i = 0; i < NB_CLASSES; i++) {
    क्रम(pplan = plan->clsplans[i]; pplan; pplan = pplan->पूर्व) {

      अगर (pass
          && (i != CORE_CLASS || pplan->sval->r < VT_CONST))
        जारी;

      vpushv(pplan->sval);
      pplan->sval->r = pplan->sval->r2 = VT_CONST; /* disable entry */
      चयन(i) {
        हाल ढेर_CLASS:
        हाल CORE_STRUCT_CLASS:
        हाल VFP_STRUCT_CLASS:
          अगर ((pplan->sval->type.t & VT_BTYPE) == VT_STRUCT) {
            पूर्णांक padding = 0;
            आकार = type_आकार(&pplan->sval->type, &align);
            /* align to stack align size */
            आकार = (आकार + 3) & ~3;
            अगर (i == ढेर_CLASS && pplan->पूर्व)
              padding = pplan->start - pplan->पूर्व->end;
            आकार += padding; /* Add padding if any */
            /* allocate the necessary size on stack */
            gadd_sp(-आकार);
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
            अगर (i == VFP_STRUCT_CLASS) {
              पूर्णांक first = pplan->start, nb = pplan->end - first + 1;
              /* vpop.32 {pplan->start, ..., pplan->end} */
              o(0xECBD0A00|(first&1)<<22|(first>>1)<<12|nb);
              /* No need to write the register used to a SValue since VFP regs
                 cannot be used for gcall_or_jmp */
            }
          } अन्यथा {
            अगर (is_float(pplan->sval->type.t)) {
#अगर_घोषित TCC_ARM_VFP
              r = vfpr(gv(RC_FLOAT)) << 12;
              अगर ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                आकार = 4;
              अन्यथा {
                आकार = 8;
                r |= 0x101; /* vpush.32 -> vpush.64 */
              }
              o(0xED2D0A01 + r); /* vpush */
#अन्यथा
              r = fpr(gv(RC_FLOAT)) << 12;
              अगर ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                आकार = 4;
              अन्यथा अगर ((pplan->sval->type.t & VT_BTYPE) == VT_DOUBLE)
                आकार = 8;
              अन्यथा
                आकार = LDOUBLE_आकार;
              अगर (आकार == 12)
                r |= 0x400000;
              अन्यथा अगर(आकार == 8)
                r|=0x8000;

              o(0xED2D0100|r|(आकार>>2)); /* some kind of vpush for FPA */
#पूर्ण_अगर
            } अन्यथा {
              /* simple type (currently always same size) */
              /* XXX: implicit cast ? */
              आकार=4;
              अगर ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
                lexpand();
                आकार = 8;
                r = gv(RC_INT);
                o(0xE52D0004|(intr(r)<<12)); /* push r */
                vtop--;
              }
              r = gv(RC_INT);
              o(0xE52D0004|(intr(r)<<12)); /* push r */
            }
            अगर (i == ढेर_CLASS && pplan->पूर्व)
              gadd_sp(pplan->पूर्व->end - pplan->start); /* Add padding if any */
          }
          अवरोध;

        हाल VFP_CLASS:
          gv(regmask(TREG_F0 + (pplan->start >> 1)));
          अगर (pplan->start & 1) { /* Must be in upper part of double register */
            o(0xEEF00A40|((pplan->start>>1)<<12)|(pplan->start>>1)); /* vmov.f32 s(n+1), sn */
            vtop->r = VT_CONST; /* avoid being saved on stack by gv for next float */
          }
          अवरोध;

        हाल CORE_CLASS:
          अगर ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
            lexpand();
            gv(regmask(pplan->end));
            pplan->sval->r2 = vtop->r;
            vtop--;
          }
          gv(regmask(pplan->start));
          /* Mark register as used so that gcall_or_jmp use another one
             (regs >=4 are free as never used to pass parameters) */
          pplan->sval->r = vtop->r;
          अवरोध;
      }
      vtop--;
    }
  }

  /* second pass to restore registers that were saved on stack by accident.
     Maybe redundant after the "lvalue_save" patch in tccgen.c:gv() */
  अगर (++pass < 2)
    जाओ again;

  अगर(todo) {
    o(0xE8BD0000|todo); /* pop {todo} */
    क्रम(pplan = plan->clsplans[CORE_STRUCT_CLASS]; pplan; pplan = pplan->पूर्व) {
      पूर्णांक r;
      pplan->sval->r = pplan->start;
      /* An SValue can only pin 2 registers at best (r and r2) but a structure
         can occupy more than 2 registers. Thus, we need to push on the value
         stack some fake parameter to have on SValue for each registers used
         by a structure (r2 is not used). */
      क्रम (r = pplan->start + 1; r <= pplan->end; r++) {
        अगर (todo & (1 << r)) {
          nb_extra_sval++;
          vpushi(0);
          vtop->r = r;
        }
      }
    }
  }
  वापस nb_extra_sval;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
व्योम gfunc_call(पूर्णांक nb_args)
{
  पूर्णांक args_आकार;
  पूर्णांक def_float_abi = float_abi;
  पूर्णांक todo;
  काष्ठा plan plan;
#अगर_घोषित TCC_ARM_EABI
  पूर्णांक variadic;
#पूर्ण_अगर

#अगर_घोषित CONFIG_TCC_BCHECK
  अगर (tcc_state->do_bounds_check)
    gbound_args(nb_args);
#पूर्ण_अगर

  save_regs(nb_args + 1);

#अगर_घोषित TCC_ARM_EABI
  अगर (float_abi == ARM_HARD_FLOAT) {
    variadic = (vtop[-nb_args].type.ref->f.func_type == FUNC_ELLIPSIS);
    अगर (variadic || floats_in_core_regs(&vtop[-nb_args]))
      float_abi = ARM_SOFTFP_FLOAT;
  }
#पूर्ण_अगर

  स_रखो(&plan, 0, माप plan);
  अगर (nb_args)
    plan.pplans = tcc_malloc(nb_args * माप(*plan.pplans));

  args_आकार = assign_regs(nb_args, float_abi, &plan, &todo);

#अगर_घोषित TCC_ARM_EABI
  अगर (args_आकार & 7) { /* Stack must be 8 byte aligned at fct call for EABI */
    args_आकार = (args_आकार + 7) & ~7;
    o(0xE24DD004); /* sub sp, sp, #4 */
  }
#पूर्ण_अगर

  nb_args += copy_params(nb_args, &plan, todo);
  tcc_free(plan.pplans);

  /* Move fct SValue on top as required by gcall_or_jmp */
  vrotb(nb_args + 1);
  gcall_or_jmp(0);
  अगर (args_आकार)
      gadd_sp(args_आकार); /* pop all parameters passed on the stack */
#अगर defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  अगर(float_abi == ARM_SOFTFP_FLOAT && is_float(vtop->type.ref->type.t)) {
    अगर((vtop->type.ref->type.t & VT_BTYPE) == VT_FLOAT) {
      o(0xEE000A10); /*vmov s0, r0 */
    } अन्यथा {
      o(0xEE000B10); /* vmov.32 d0[0], r0 */
      o(0xEE201B10); /* vmov.32 d0[1], r1 */
    }
  }
#पूर्ण_अगर
  vtop -= nb_args + 1; /* Pop all params and fct address from value stack */
  leaffunc = 0; /* we are calling a function, so we aren't in a leaf function */
  float_abi = def_float_abi;
}

/* generate function prolog of type 't' */
व्योम gfunc_prolog(Sym *func_sym)
{
  CType *func_type = &func_sym->type;
  Sym *sym,*sym2;
  पूर्णांक n, nf, आकार, align, rs, struct_ret = 0;
  पूर्णांक addr, pn, sn; /* pn=core, sn=stack */
  CType ret_type;

#अगर_घोषित TCC_ARM_EABI
  काष्ठा avail_regs avregs = {{0}};
#पूर्ण_अगर

  sym = func_type->ref;

  n = nf = 0;
  अगर ((func_vt.t & VT_BTYPE) == VT_STRUCT &&
      !gfunc_sret(&func_vt, func_var, &ret_type, &align, &rs))
  {
    n++;
    struct_ret = 1;
    func_vc = 12; /* Offset from fp of the place to store the result */
  }
  क्रम(sym2 = sym->अग्र; sym2 && (n < 4 || nf < 16); sym2 = sym2->अग्र) {
    आकार = type_आकार(&sym2->type, &align);
#अगर_घोषित TCC_ARM_EABI
    अगर (float_abi == ARM_HARD_FLOAT && !func_var &&
        (is_float(sym2->type.t) || is_hgen_float_aggr(&sym2->type))) {
      पूर्णांक tmpnf = assign_vfpreg(&avregs, align, आकार);
      tmpnf += (आकार + 3) / 4;
      nf = (tmpnf > nf) ? tmpnf : nf;
    } अन्यथा
#पूर्ण_अगर
    अगर (n < 4)
      n += (आकार + 3) / 4;
  }
  o(0xE1A0C00D); /* mov ip,sp */
  अगर (func_var)
    n=4;
  अगर (n) {
    अगर(n>4)
      n=4;
#अगर_घोषित TCC_ARM_EABI
    n=(n+1)&-2;
#पूर्ण_अगर
    o(0xE92D0000|((1<<n)-1)); /* save r0-r4 on stack if needed */
  }
  अगर (nf) {
    अगर (nf>16)
      nf=16;
    nf=(nf+1)&-2; /* nf => HARDFLOAT => EABI */
    o(0xED2D0A00|nf); /* save s0-s15 on stack if needed */
  }
  o(0xE92D5800); /* save fp, ip, lr */
  o(0xE1A0B00D); /* mov fp, sp */
  func_sub_sp_offset = ind;
  o(0xE1A00000); /* nop, leave space for stack adjustment in epilog */

#अगर_घोषित TCC_ARM_EABI
  अगर (float_abi == ARM_HARD_FLOAT) {
    func_vc += nf * 4;
    स_रखो(&avregs, 0, माप avregs);
  }
#पूर्ण_अगर
  pn = struct_ret, sn = 0;
  जबतक ((sym = sym->अग्र)) {
    CType *type;
    type = &sym->type;
    आकार = type_आकार(type, &align);
    आकार = (आकार + 3) >> 2;
    align = (align + 3) & ~3;
#अगर_घोषित TCC_ARM_EABI
    अगर (float_abi == ARM_HARD_FLOAT && !func_var && (is_float(sym->type.t)
        || is_hgen_float_aggr(&sym->type))) {
      पूर्णांक fpn = assign_vfpreg(&avregs, align, आकार << 2);
      अगर (fpn >= 0)
        addr = fpn * 4;
      अन्यथा
        जाओ from_ढेर;
    } अन्यथा
#पूर्ण_अगर
    अगर (pn < 4) {
#अगर_घोषित TCC_ARM_EABI
        pn = (pn + (align-1)/4) & -(align/4);
#पूर्ण_अगर
      addr = (nf + pn) * 4;
      pn += आकार;
      अगर (!sn && pn > 4)
        sn = (pn - 4);
    } अन्यथा {
#अगर_घोषित TCC_ARM_EABI
from_ढेर:
        sn = (sn + (align-1)/4) & -(align/4);
#पूर्ण_अगर
      addr = (n + nf + sn) * 4;
      sn += आकार;
    }
    gfunc_set_param(sym, addr + 12, 0);
  }
  last_itod_magic=0;
  leaffunc = 1;
  loc = 0;
#अगर_घोषित CONFIG_TCC_BCHECK
  अगर (tcc_state->do_bounds_check)
    gen_bounds_prolog();
#पूर्ण_अगर
}

/* generate function epilog */
व्योम gfunc_epilog(व्योम)
{
  uint32_t x;
  पूर्णांक diff;

#अगर_घोषित CONFIG_TCC_BCHECK
  अगर (tcc_state->do_bounds_check)
    gen_bounds_epilog();
#पूर्ण_अगर
  /* Copy float return value to core register if base standard is used and
     float computation is made with VFP */
#अगर defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  अगर ((float_abi == ARM_SOFTFP_FLOAT || func_var) && is_float(func_vt.t)) {
    अगर((func_vt.t & VT_BTYPE) == VT_FLOAT)
      o(0xEE100A10); /* fmrs r0, s0 */
    अन्यथा {
      o(0xEE100B10); /* fmrdl r0, d0 */
      o(0xEE301B10); /* fmrdh r1, d0 */
    }
  }
#पूर्ण_अगर
  o(0xE89BA800); /* restore fp, sp, pc */
  diff = (-loc + 3) & -4;
#अगर_घोषित TCC_ARM_EABI
  अगर(!leaffunc)
    diff = ((diff + 11) & -8) - 4;
#पूर्ण_अगर
  अगर(diff > 0) {
    x=stuff_const(0xE24BD000, diff); /* sub sp,fp,# */
    अगर(x)
      *(uint32_t *)(cur_text_section->तथ्य + func_sub_sp_offset) = x;
    अन्यथा {
      पूर्णांक addr;
      addr=ind;
      o(0xE59FC004); /* ldr ip,[pc+4] */
      o(0xE04BD00C); /* sub sp,fp,ip  */
      o(0xE1A0F00E); /* mov pc,lr */
      o(diff);
      *(uint32_t *)(cur_text_section->तथ्य + func_sub_sp_offset) = 0xE1000000|encbranch(func_sub_sp_offset,addr,1);
    }
  }
}

ST_FUNC व्योम gen_fill_nops(पूर्णांक bytes)
{
    अगर ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    जबतक (bytes > 0) {
	o(0xE1A00000);
	bytes -= 4;
    }
}

/* generate a jump to a label */
ST_FUNC पूर्णांक gjmp(पूर्णांक t)
{
  पूर्णांक r;
  अगर (nocode_wanted)
    वापस t;
  r=ind;
  o(0xE0000000|encbranch(r,t,1));
  वापस r;
}

/* generate a jump to a fixed address */
ST_FUNC व्योम gjmp_addr(पूर्णांक a)
{
  gjmp(a);
}

ST_FUNC पूर्णांक gjmp_cond(पूर्णांक op, पूर्णांक t)
{
  पूर्णांक r;
  अगर (nocode_wanted)
    वापस t;
  r=ind;
  op=mapcc(op);
  op|=encbranch(r,t,1);
  o(op);
  वापस r;
}

ST_FUNC पूर्णांक gjmp_append(पूर्णांक n, पूर्णांक t)
{
  uint32_t *x;
  पूर्णांक p,lp;
  अगर(n) {
    p = n;
    करो {
      p = decbranch(lp=p);
    } जबतक(p);
    x = (uint32_t *)(cur_text_section->तथ्य + lp);
    *x &= 0xff000000;
    *x |= encbranch(lp,t,1);
    t = n;
  }
  वापस t;
}

/* generate an integer binary operation */
व्योम gen_opi(पूर्णांक op)
{
  पूर्णांक c, func = 0;
  uint32_t opc = 0, r, fr;
  अचिन्हित लघु retreg = REG_IRET;

  c=0;
  चयन(op) {
    हाल '+':
      opc = 0x8;
      c=1;
      अवरोध;
    हाल TOK_ADDC1: /* add with carry generation */
      opc = 0x9;
      c=1;
      अवरोध;
    हाल '-':
      opc = 0x4;
      c=1;
      अवरोध;
    हाल TOK_SUBC1: /* sub with carry generation */
      opc = 0x5;
      c=1;
      अवरोध;
    हाल TOK_ADDC2: /* add with carry use */
      opc = 0xA;
      c=1;
      अवरोध;
    हाल TOK_SUBC2: /* sub with carry use */
      opc = 0xC;
      c=1;
      अवरोध;
    हाल '&':
      opc = 0x0;
      c=1;
      अवरोध;
    हाल '^':
      opc = 0x2;
      c=1;
      अवरोध;
    हाल '|':
      opc = 0x18;
      c=1;
      अवरोध;
    हाल '*':
      gv2(RC_INT, RC_INT);
      r = vtop[-1].r;
      fr = vtop[0].r;
      vtop--;
      o(0xE0000090|(intr(r)<<16)|(intr(r)<<8)|intr(fr));
      वापस;
    हाल TOK_SHL:
      opc = 0;
      c=2;
      अवरोध;
    हाल TOK_SHR:
      opc = 1;
      c=2;
      अवरोध;
    हाल TOK_SAR:
      opc = 2;
      c=2;
      अवरोध;
    हाल '/':
    हाल TOK_PDIV:
      func=TOK___divsi3;
      c=3;
      अवरोध;
    हाल TOK_UDIV:
      func=TOK___udivsi3;
      c=3;
      अवरोध;
    हाल '%':
#अगर_घोषित TCC_ARM_EABI
      func=TOK___aeabi_idivmod;
      retreg=REG_IRE2;
#अन्यथा
      func=TOK___modsi3;
#पूर्ण_अगर
      c=3;
      अवरोध;
    हाल TOK_UMOD:
#अगर_घोषित TCC_ARM_EABI
      func=TOK___aeabi_uidivmod;
      retreg=REG_IRE2;
#अन्यथा
      func=TOK___umodsi3;
#पूर्ण_अगर
      c=3;
      अवरोध;
    हाल TOK_UMULL:
      gv2(RC_INT, RC_INT);
      r=intr(vtop[-1].r2=get_reg(RC_INT));
      c=vtop[-1].r;
      vtop[-1].r=get_reg_ex(RC_INT,regmask(c));
      vtop--;
      o(0xE0800090|(r<<16)|(intr(vtop->r)<<12)|(intr(c)<<8)|intr(vtop[1].r));
      वापस;
    शेष:
      opc = 0x15;
      c=1;
      अवरोध;
  }
  चयन(c) {
    हाल 1:
      अगर((vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	अगर(opc == 4 || opc == 5 || opc == 0xc) {
	  vswap();
	  opc|=2; // sub -> rsb
	}
      }
      vswap();
      c=intr(gv(RC_INT));
      vswap();
      opc=0xE0000000|(opc<<20);
      अगर((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	uint32_t x;
	x=stuff_const(opc|0x2000000|(c<<16),vtop->c.i);
	अगर(x) {
	  अगर ((x & 0xfff00000) == 0xe3500000)   // cmp rx,#c
	    o(x);
	  अन्यथा {
	    r=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	    o(x|(r<<12));
	  }
	  जाओ done;
	}
      }
      fr=intr(gv(RC_INT));
#अगर_घोषित CONFIG_TCC_BCHECK
      अगर ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
        vswap();
        c=intr(gv(RC_INT));
        vswap();
      }
#पूर्ण_अगर
      अगर ((opc & 0xfff00000) == 0xe1500000) // cmp rx,ry
	o(opc|(c<<16)|fr);
      अन्यथा {
        r=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
        o(opc|(c<<16)|(r<<12)|fr);
      }
done:
      vtop--;
      अगर (op >= TOK_ULT && op <= TOK_GT)
        vset_VT_CMP(op);
      अवरोध;
    हाल 2:
      opc=0xE1A00000|(opc<<5);
      vswap();
      r=intr(gv(RC_INT));
      vswap();
      अगर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	fr=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	c = vtop->c.i & 0x1f;
	o(opc|r|(c<<7)|(fr<<12));
      } अन्यथा {
        fr=intr(gv(RC_INT));
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=intr(gv(RC_INT));
          vswap();
        }
#पूर्ण_अगर
	c=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
	o(opc|r|(c<<12)|(fr<<8)|0x10);
      }
      vtop--;
      अवरोध;
    हाल 3:
      vpush_helper_func(func);
      vrott(3);
      gfunc_call(2);
      vpushi(0);
      vtop->r = retreg;
      अवरोध;
    शेष:
      tcc_error("gen_opi %i unimplemented!",op);
  }
}

#अगर_घोषित TCC_ARM_VFP
अटल पूर्णांक is_zero(पूर्णांक i)
{
  अगर((vtop[i].r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    वापस 0;
  अगर (vtop[i].type.t == VT_FLOAT)
    वापस (vtop[i].c.f == 0.f);
  अन्यथा अगर (vtop[i].type.t == VT_DOUBLE)
    वापस (vtop[i].c.d == 0.0);
  वापस (vtop[i].c.ld == 0.l);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
 *    two operands are guaranteed to have the same floating point type */
व्योम gen_opf(पूर्णांक op)
{
  uint32_t x;
  पूर्णांक fneg=0,r;
  x=0xEE000A00|T2CPR(vtop->type.t);
  चयन(op) {
    हाल '+':
      अगर(is_zero(-1))
        vswap();
      अगर(is_zero(0)) {
        vtop--;
        वापस;
      }
      x|=0x300000;
      अवरोध;
    हाल '-':
      x|=0x300040;
      अगर(is_zero(0)) {
        vtop--;
        वापस;
      }
      अगर(is_zero(-1)) {
        x|=0x810000; /* fsubX -> fnegX */
        vswap();
        vtop--;
        fneg=1;
      }
      अवरोध;
    हाल '*':
      x|=0x200000;
      अवरोध;
    हाल '/':
      x|=0x800000;
      अवरोध;
    शेष:
      अगर(op < TOK_ULT || op > TOK_GT) {
        tcc_error("unknown fp op %x!",op);
        वापस;
      }
      अगर(is_zero(-1)) {
        vswap();
        चयन(op) {
          हाल TOK_LT: op=TOK_GT; अवरोध;
          हाल TOK_GE: op=TOK_ULE; अवरोध;
          हाल TOK_LE: op=TOK_GE; अवरोध;
          हाल TOK_GT: op=TOK_ULT; अवरोध;
        }
      }
      x|=0xB40040; /* fcmpX */
      अगर(op!=TOK_EQ && op!=TOK_NE)
        x|=0x80; /* fcmpX -> fcmpeX */
      अगर(is_zero(0)) {
        vtop--;
        o(x|0x10000|(vfpr(gv(RC_FLOAT))<<12)); /* fcmp(e)X -> fcmp(e)zX */
      } अन्यथा {
        gv2(RC_FLOAT,RC_FLOAT);
        x|=vfpr(vtop[0].r);
        o(x|(vfpr(vtop[-1].r) << 12));
        vtop--;
      }
      o(0xEEF1FA10); /* fmstat */

      चयन(op) {
        हाल TOK_LE: op=TOK_ULE; अवरोध;
        हाल TOK_LT: op=TOK_ULT; अवरोध;
        हाल TOK_UGE: op=TOK_GE; अवरोध;
        हाल TOK_UGT: op=TOK_GT; अवरोध;
      }
      vset_VT_CMP(op);
      वापस;
  }
  r=gv(RC_FLOAT);
  x|=vfpr(r);
  r=regmask(r);
  अगर(!fneg) {
    पूर्णांक r2;
    vswap();
    r2=gv(RC_FLOAT);
    x|=vfpr(r2)<<16;
    r|=regmask(r2);
#अगर_घोषित CONFIG_TCC_BCHECK
    अगर ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
      vswap();
      r=gv(RC_FLOAT);
      vswap();
      x=(x&~0xf)|vfpr(r);
    }
#पूर्ण_अगर
  }
  vtop->r=get_reg_ex(RC_FLOAT,r);
  अगर(!fneg)
    vtop--;
  o(x|(vfpr(vtop->r)<<12));
}

#अन्यथा
अटल uint32_t is_fconst()
{
  दीर्घ द्विगुन f;
  uint32_t r;
  अगर((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    वापस 0;
  अगर (vtop->type.t == VT_FLOAT)
    f = vtop->c.f;
  अन्यथा अगर (vtop->type.t == VT_DOUBLE)
    f = vtop->c.d;
  अन्यथा
    f = vtop->c.ld;
  अगर(!ieee_finite(f))
    वापस 0;
  r=0x8;
  अगर(f<0.0) {
    r=0x18;
    f=-f;
  }
  अगर(f==0.0)
    वापस r;
  अगर(f==1.0)
    वापस r|1;
  अगर(f==2.0)
    वापस r|2;
  अगर(f==3.0)
    वापस r|3;
  अगर(f==4.0)
    वापस r|4;
  अगर(f==5.0)
    वापस r|5;
  अगर(f==0.5)
    वापस r|6;
  अगर(f==10.0)
    वापस r|7;
  वापस 0;
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
व्योम gen_opf(पूर्णांक op)
{
  uint32_t x, r, r2, c1, c2;
  //fputs("gen_opf\n",stderr);
  vswap();
  c1 = is_fconst();
  vswap();
  c2 = is_fconst();
  x=0xEE000100;
  अगर ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
    x|=0x80;
#अगर LDOUBLE_आकार != 8
  अन्यथा अगर ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE)
    x|=0x80000;
#पूर्ण_अगर

  चयन(op)
  {
    हाल '+':
      अगर(!c2) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      अगर(c2) {
	अगर(c2>0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
      } अन्यथा {
	r2=fpr(gv(RC_FLOAT));
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#पूर्ण_अगर
      }
      अवरोध;
    हाल '-':
      अगर(c2) {
	अगर(c2<=0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } अन्यथा अगर(c1 && c1<=0xf) {
	x|=0x300000; // rsf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } अन्यथा {
	x|=0x200000; // suf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#पूर्ण_अगर
      }
      अवरोध;
    हाल '*':
      अगर(!c2 || c2>0xf) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      अगर(c2 && c2<=0xf)
	r2=c2;
      अन्यथा {
	r2=fpr(gv(RC_FLOAT));
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#पूर्ण_अगर
      }
      x|=0x100000; // muf
      अवरोध;
    हाल '/':
      अगर(c2 && c2<=0xf) {
	x|=0x400000; // dvf
	r2=c2;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } अन्यथा अगर(c1 && c1<=0xf) {
	x|=0x500000; // rdf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } अन्यथा {
	x|=0x400000; // dvf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#पूर्ण_अगर
      }
      अवरोध;
    शेष:
      अगर(op >= TOK_ULT && op <= TOK_GT) {
	x|=0xd0f110; // cmfe
/* bug (intention?) in Linux FPU emulator
   doesn't set carry if equal */
	चयन(op) {
	  हाल TOK_ULT:
	  हाल TOK_UGE:
	  हाल TOK_ULE:
	  हाल TOK_UGT:
            tcc_error("unsigned comparison on floats?");
	    अवरोध;
	  हाल TOK_LT:
            op=TOK_Nset;
	    अवरोध;
	  हाल TOK_LE:
            op=TOK_ULE; /* correct in unordered case only if AC bit in FPSR set */
	    अवरोध;
	  हाल TOK_EQ:
	  हाल TOK_NE:
	    x&=~0x400000; // cmfe -> cmf
	    अवरोध;
	}
	अगर(c1 && !c2) {
	  c2=c1;
	  vswap();
	  चयन(op) {
            हाल TOK_Nset:
              op=TOK_GT;
	      अवरोध;
            हाल TOK_GE:
	      op=TOK_ULE;
	      अवरोध;
	    हाल TOK_ULE:
              op=TOK_GE;
	      अवरोध;
            हाल TOK_GT:
              op=TOK_Nset;
	      अवरोध;
	  }
	}
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	अगर(c2) {
	  अगर(c2>0xf)
	    x|=0x200000;
	  r2=c2&0xf;
	} अन्यथा {
	  r2=fpr(gv(RC_FLOAT));
#अगर_घोषित CONFIG_TCC_BCHECK
          अगर ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            r=fpr(gv(RC_FLOAT));
            vswap();
          }
#पूर्ण_अगर
	}
        --vtop;
        vset_VT_CMP(op);
        ++vtop;
      } अन्यथा {
        tcc_error("unknown fp op %x!",op);
	वापस;
      }
  }
  अगर(vtop[-1].r == VT_CMP)
    c1=15;
  अन्यथा {
    c1=vtop->r;
    अगर(r2&0x8)
      c1=vtop[-1].r;
    vtop[-1].r=get_reg_ex(RC_FLOAT,two2mask(vtop[-1].r,c1));
    c1=fpr(vtop[-1].r);
  }
  vtop--;
  o(x|(r<<16)|(c1<<12)|r2);
}
#पूर्ण_अगर

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ST_FUNC व्योम gen_cvt_itof(पूर्णांक t)
{
  uint32_t r, r2;
  पूर्णांक bt;
  bt=vtop->type.t & VT_BTYPE;
  अगर(bt == VT_INT || bt == VT_SHORT || bt == VT_BYTE) {
#अगर_अघोषित TCC_ARM_VFP
    uint32_t dsize = 0;
#पूर्ण_अगर
    r=intr(gv(RC_INT));
#अगर_घोषित TCC_ARM_VFP
    r2=vfpr(vtop->r=get_reg(RC_FLOAT));
    o(0xEE000A10|(r<<12)|(r2<<16)); /* fmsr */
    r2|=r2<<12;
    अगर(!(vtop->type.t & VT_UNSIGNED))
      r2|=0x80;                /* fuitoX -> fsituX */
    o(0xEEB80A40|r2|T2CPR(t)); /* fYitoX*/
#अन्यथा
    r2=fpr(vtop->r=get_reg(RC_FLOAT));
    अगर((t & VT_BTYPE) != VT_FLOAT)
      dsize=0x80;    /* flts -> fltd */
    o(0xEE000110|dsize|(r2<<16)|(r<<12)); /* flts */
    अगर((vtop->type.t & (VT_UNSIGNED|VT_BTYPE)) == (VT_UNSIGNED|VT_INT)) {
      uint32_t off = 0;
      o(0xE3500000|(r<<12));        /* cmp */
      r=fpr(get_reg(RC_FLOAT));
      अगर(last_itod_magic) {
	off=ind+8-last_itod_magic;
	off/=4;
	अगर(off>255)
	  off=0;
      }
      o(0xBD1F0100|(r<<12)|off);    /* ldflts */
      अगर(!off) {
        o(0xEA000000);              /* b */
        last_itod_magic=ind;
        o(0x4F800000);              /* 4294967296.0f */
      }
      o(0xBE000100|dsize|(r2<<16)|(r2<<12)|r); /* adflt */
    }
#पूर्ण_अगर
    वापस;
  } अन्यथा अगर(bt == VT_LLONG) {
    पूर्णांक func;
    CType *func_type = 0;
    अगर((t & VT_BTYPE) == VT_FLOAT) {
      func_type = &func_float_type;
      अगर(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundisf;
      अन्यथा
        func=TOK___floatdisf;
    } अन्यथा अगर((t & VT_BTYPE) == VT_DOUBLE) {
      func_type = &func_double_type;
      अगर(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundidf;
      अन्यथा
        func=TOK___floatdidf;
#अगर LDOUBLE_आकार != 8
    } अन्यथा अगर((t & VT_BTYPE) == VT_LDOUBLE) {
      func_type = &func_ldouble_type;
      अगर(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundixf;
      अन्यथा
        func=TOK___floatdixf;
#पूर्ण_अगर
    }
    अगर(func_type) {
      vpushsym(func_type, external_helper_sym(func));
      vswap();
      gfunc_call(1);
      vpushi(0);
      vtop->r=TREG_F0;
      वापस;
    }
  }
  tcc_error("unimplemented gen_cvt_itof %x!",vtop->type.t);
}

/* convert fp to int 't' type */
व्योम gen_cvt_ftoi(पूर्णांक t)
{
  uint32_t r, r2;
  पूर्णांक u, func = 0;
  u=t&VT_UNSIGNED;
  t&=VT_BTYPE;
  r2=vtop->type.t & VT_BTYPE;
  अगर(t==VT_INT) {
#अगर_घोषित TCC_ARM_VFP
    r=vfpr(gv(RC_FLOAT));
    u=u?0:0x10000;
    o(0xEEBC0AC0|(r<<12)|r|T2CPR(r2)|u); /* ftoXizY */
    r2=intr(vtop->r=get_reg(RC_INT));
    o(0xEE100A10|(r<<16)|(r2<<12));
    वापस;
#अन्यथा
    अगर(u) {
      अगर(r2 == VT_FLOAT)
        func=TOK___fixunssfsi;
      अन्यथा अगर(r2 == VT_DOUBLE)
	func=TOK___fixunsdfsi;
#अगर LDOUBLE_आकार != 8
      अन्यथा अगर(r2 == VT_LDOUBLE)
	func=TOK___fixunsxfsi;
#पूर्ण_अगर
    } अन्यथा {
      r=fpr(gv(RC_FLOAT));
      r2=intr(vtop->r=get_reg(RC_INT));
      o(0xEE100170|(r2<<12)|r);
      वापस;
    }
#पूर्ण_अगर
  } अन्यथा अगर(t == VT_LLONG) { // unsigned handled in gen_cvt_ftoi1
    अगर(r2 == VT_FLOAT)
      func=TOK___fixsfdi;
    अन्यथा अगर(r2 == VT_DOUBLE)
      func=TOK___fixdfdi;
#अगर LDOUBLE_आकार != 8
    अन्यथा अगर(r2 == VT_LDOUBLE)
      func=TOK___fixxfdi;
#पूर्ण_अगर
  }
  अगर(func) {
    vpush_helper_func(func);
    vswap();
    gfunc_call(1);
    vpushi(0);
    अगर(t == VT_LLONG)
      vtop->r2 = REG_IRE2;
    vtop->r = REG_IRET;
    वापस;
  }
  tcc_error("unimplemented gen_cvt_ftoi!");
}

/* convert from one floating point type to another */
व्योम gen_cvt_ftof(पूर्णांक t)
{
#अगर_घोषित TCC_ARM_VFP
  uint32_t r = gv(RC_FLOAT);
  अगर(((vtop->type.t & VT_BTYPE) == VT_FLOAT) != ((t & VT_BTYPE) == VT_FLOAT)) {
    r = vfpr(r);
    o(0xEEB70AC0|(r<<12)|r|T2CPR(vtop->type.t));
  }
#अन्यथा
  /* all we have to do on i386 and FPA ARM is to put the float in a register */
  gv(RC_FLOAT);
#पूर्ण_अगर
}

/* increment tcov counter */
ST_FUNC व्योम gen_increment_tcov (SValue *sv)
{
  पूर्णांक r1, r2;

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
व्योम ggoto(व्योम)
{
  gcall_or_jmp(1);
  vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC व्योम gen_vla_sp_save(पूर्णांक addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    store(TREG_SP, &v);
}

/* Restore the SP from a location on the stack */
ST_FUNC व्योम gen_vla_sp_restore(पूर्णांक addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    load(TREG_SP, &v);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC व्योम gen_vla_alloc(CType *type, पूर्णांक align) {
    पूर्णांक r;
#अगर defined(CONFIG_TCC_BCHECK)
    अगर (tcc_state->do_bounds_check)
        vpushv(vtop);
#पूर्ण_अगर
    r = intr(gv(RC_INT));
#अगर defined(CONFIG_TCC_BCHECK)
    अगर (tcc_state->do_bounds_check)
        o(0xe2800001 | (r<<16)|(r<<12)); /* add r,r,#1 */
#पूर्ण_अगर
    o(0xE04D0000|(r<<12)|r); /* sub r, sp, r */
#अगर_घोषित TCC_ARM_EABI
    अगर (align < 8)
        align = 8;
#अन्यथा
    अगर (align < 4)
        align = 4;
#पूर्ण_अगर
    अगर (align & (align - 1))
        tcc_error("alignment is not a power of 2: %i", align);
    o(stuff_const(0xE3C0D000|(r<<16), align - 1)); /* bic sp, r, #align-1 */
    vpop();
#अगर defined(CONFIG_TCC_BCHECK)
    अगर (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R0;
        o(0xe1a0000d | (vtop->r << 12)); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_add_epilog = 1;
    }
#पूर्ण_अगर
}

/* end of ARM code generator */
/*************************************************************/
#पूर्ण_अगर
/*************************************************************/
