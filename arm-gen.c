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

#నిర్వచితమైతే లక్ష్యం_DEFS_ONLY

#ఒకవేళ defined(TCC_ARM_EABI) && !defined(TCC_ARM_VFP)
#దోషం "Currently TinyCC only supports float computation with VFP instructions"
#అయితే_ముగింపు

/* number of available registers */
#నిర్వచితమైతే TCC_ARM_VFP
#నిర్వచించు NB_REGS            13
#లేకపోతే
#నిర్వచించు NB_REGS             9
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే CONFIG_TCC_CPUVER
# define CONFIG_TCC_CPUVER 5
#అయితే_ముగింపు

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#నిర్వచించు RC_INT     0x0001 /* generic integer register */
#నిర్వచించు RC_FLOAT   0x0002 /* generic float register */
#నిర్వచించు RC_R0      0x0004
#నిర్వచించు RC_R1      0x0008
#నిర్వచించు RC_R2      0x0010
#నిర్వచించు RC_R3      0x0020
#నిర్వచించు RC_R12     0x0040
#నిర్వచించు RC_F0      0x0080
#నిర్వచించు RC_F1      0x0100
#నిర్వచించు RC_F2      0x0200
#నిర్వచించు RC_F3      0x0400
#నిర్వచితమైతే TCC_ARM_VFP
#నిర్వచించు RC_F4      0x0800
#నిర్వచించు RC_F5      0x1000
#నిర్వచించు RC_F6      0x2000
#నిర్వచించు RC_F7      0x4000
#అయితే_ముగింపు
#నిర్వచించు RC_IRET    RC_R0  /* function return: integer register */
#నిర్వచించు RC_IRE2    RC_R1  /* function return: second integer register */
#నిర్వచించు RC_FRET    RC_F0  /* function return: float register */

/* pretty names for the registers */
గణన {
    TREG_R0 = 0,
    TREG_R1,
    TREG_R2,
    TREG_R3,
    TREG_R12,
    TREG_F0,
    TREG_F1,
    TREG_F2,
    TREG_F3,
#నిర్వచితమైతే TCC_ARM_VFP
    TREG_F4,
    TREG_F5,
    TREG_F6,
    TREG_F7,
#అయితే_ముగింపు
    TREG_SP = 13,
    TREG_LR,
};

#నిర్వచితమైతే TCC_ARM_VFP
#నిర్వచించు T2CPR(t) (((t) & VT_BTYPE) != VT_FLOAT ? 0x100 : 0)
#అయితే_ముగింపు

/* return registers for function */
#నిర్వచించు REG_IRET TREG_R0 /* single word int return register */
#నిర్వచించు REG_IRE2 TREG_R1 /* second word return register (for long long) */
#నిర్వచించు REG_FRET TREG_F0 /* float return register */

#నిర్వచితమైతే TCC_ARM_EABI
#నిర్వచించు TOK___divdi3 TOK___aeabi_ldivmod
#నిర్వచించు TOK___moddi3 TOK___aeabi_ldivmod
#నిర్వచించు TOK___udivdi3 TOK___aeabi_uldivmod
#నిర్వచించు TOK___umoddi3 TOK___aeabi_uldivmod
#అయితే_ముగింపు

/* defined if function parameters must be evaluated in reverse order */
#నిర్వచించు INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#నిర్వచించు PTR_కొలత 4

/* long double size and alignment, in bytes */
#నిర్వచితమైతే TCC_ARM_VFP
#నిర్వచించు LDOUBLE_కొలత  8
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే LDOUBLE_కొలత
#నిర్వచించు LDOUBLE_కొలత  8
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_ARM_EABI
#నిర్వచించు LDOUBLE_ALIGN 8
#లేకపోతే
#నిర్వచించు LDOUBLE_ALIGN 4
#అయితే_ముగింపు

#ఒకవేళ LDOUBLE_కొలత == 8
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#అయితే_ముగింపు

/* maximum alignment (for aligned attribute support) */
#నిర్వచించు MAX_ALIGN     8

#నిర్వచించు CHAR_IS_UNSIGNED

#నిర్వచించు ARM_SOFTFP_FLOAT 0
#నిర్వచించు ARM_HARD_FLOAT 1

/******************************************************/
#లేకపోతే /* ! TARGET_DEFS_ONLY */
/******************************************************/
#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"

ST_దత్తాంశం స్థిరరాశి అక్షరం * స్థిరరాశి లక్ష్యం_machine_defs =
    "__arm__\0"
    "__arm\0"
    "arm\0"
    "__arm_elf__\0"
    "__arm_elf\0"
    "arm_elf\0"
    "__ARM_ARCH_4__\0"
    "__ARMEL__\0"
    "__APCS_32__\0"
#ఒకవేళ defined TCC_ARM_EABI
    "__ARM_EABI__\0"
#అయితే_ముగింపు
    ;

ST_దత్తాంశం స్థిరరాశి పూర్ణాంకం reg_classes[NB_REGS] = {
    /* r0 */ RC_INT | RC_R0,
    /* r1 */ RC_INT | RC_R1,
    /* r2 */ RC_INT | RC_R2,
    /* r3 */ RC_INT | RC_R3,
    /* r12 */ RC_INT | RC_R12,
    /* f0 */ RC_FLOAT | RC_F0,
    /* f1 */ RC_FLOAT | RC_F1,
    /* f2 */ RC_FLOAT | RC_F2,
    /* f3 */ RC_FLOAT | RC_F3,
#నిర్వచితమైతే TCC_ARM_VFP
 /* d4/s8 */ RC_FLOAT | RC_F4,
/* d5/s10 */ RC_FLOAT | RC_F5,
/* d6/s12 */ RC_FLOAT | RC_F6,
/* d7/s14 */ RC_FLOAT | RC_F7,
#అయితే_ముగింపు
};

స్థిర పూర్ణాంకం float_abi;
స్థిర పూర్ణాంకం func_sub_sp_స్థానభ్రంశం, చివరి_itod_magic;
స్థిర పూర్ణాంకం leaffunc;

#ఒకవేళ defined(CONFIG_TCC_BCHECK)
స్థిర addr_t func_bound_స్థానభ్రంశం;
స్థిర గుర్తులేని దీర్ఘ func_bound_ind;
ST_దత్తాంశం పూర్ణాంకం func_bound_కూడు_epilog;
#అయితే_ముగింపు

#ఒకవేళ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
స్థిర CType float_type, double_type, func_float_type, func_double_type;
ST_FUNC శూన్య arm_init(నిర్మాణం TCCState *s)
{
    float_type.t = VT_FLOAT;
    double_type.t = VT_DOUBLE;
    func_float_type.t = VT_FUNC;
    func_float_type.ref = sym_నెట్టు(SYM_క్షేత్రం, &float_type, FUNC_CDECL, FUNC_OLD);
    func_double_type.t = VT_FUNC;
    func_double_type.ref = sym_నెట్టు(SYM_క్షేత్రం, &double_type, FUNC_CDECL, FUNC_OLD);

    float_abi = s->float_abi;
#నిర్వచితం_కాకపోతే TCC_ARM_HARDFLOAT
// XXX: Works on OpenBSD
// # warning "soft float ABI currently not supported: default to softfp"
#అయితే_ముగింపు
}
#లేకపోతే
#నిర్వచించు func_float_type func_old_type
#నిర్వచించు func_double_type func_old_type
#నిర్వచించు func_ldouble_type func_old_type
ST_FUNC శూన్య arm_init(నిర్మాణం TCCState *s)
{
#ఒకవేళ 0
#ఒకవేళ !defined (TCC_ARM_VFP)
    tcc_warning("Support for FPA is deprecated and will be removed in next"
                " release");
#అయితే_ముగింపు
#ఒకవేళ !defined (TCC_ARM_EABI)
    tcc_warning("Support for OABI is deprecated and will be removed in next"
                " release");
#అయితే_ముగింపు
#అయితే_ముగింపు
}
#అయితే_ముగింపు

#నిర్వచించు CHECK_R(r) ((r) >= TREG_R0 && (r) <= TREG_LR)

స్థిర పూర్ణాంకం two2mask(పూర్ణాంకం a,పూర్ణాంకం b) {
  ఒకవేళ (!CHECK_R(a) || !CHECK_R(b))
    tcc_error("compiler error! registers %i,%i is not valid",a,b);
  తిరిగి (reg_classes[a]|reg_classes[b])&~(RC_INT|RC_FLOAT);
}

స్థిర పూర్ణాంకం regmask(పూర్ణాంకం r) {
  ఒకవేళ (!CHECK_R(r))
    tcc_error("compiler error! register %i is not valid",r);
  తిరిగి reg_classes[r]&~(RC_INT|RC_FLOAT);
}

/******************************************************/

శూన్య o(uint32_t i)
{
  /* this is a good place to start adding big-endian support*/
  పూర్ణాంకం ind1;
  ఒకవేళ (nocode_wanted)
    తిరిగి;
  ind1 = ind + 4;
  ఒకవేళ (!cur_పాఠ్యం_section)
    tcc_error("compiler error! This happens f.ex. if the compiler\n"
         "can't evaluate constant expressions outside of a function.");
  ఒకవేళ (ind1 > cur_పాఠ్యం_section->దత్తాంశం_allocated)
    section_realloc(cur_పాఠ్యం_section, ind1);
  cur_పాఠ్యం_section->దత్తాంశం[ind++] = i&255;
  i>>=8;
  cur_పాఠ్యం_section->దత్తాంశం[ind++] = i&255;
  i>>=8;
  cur_పాఠ్యం_section->దత్తాంశం[ind++] = i&255;
  i>>=8;
  cur_పాఠ్యం_section->దత్తాంశం[ind++] = i;
}

స్థిర uint32_t stuff_const(uint32_t op, uint32_t c)
{
  పూర్ణాంకం try_neg=0;
  uint32_t nc = 0, negop = 0;

  ఎంపిక(op&0x1F00000)
  {
    స్థితి 0x800000: //add
    స్థితి 0x400000: //sub
      try_neg=1;
      negop=op^0xC00000;
      nc=-c;
      ఆపు;
    స్థితి 0x1A00000: //mov
    స్థితి 0x1E00000: //mvn
      try_neg=1;
      negop=op^0x400000;
      nc=~c;
      ఆపు;
    స్థితి 0x200000: //xor
      ఒకవేళ(c==~0)
	తిరిగి (op&0xF010F000)|((op>>16)&0xF)|0x1E00000;
      ఆపు;
    స్థితి 0x0: //and
      ఒకవేళ(c==~0)
	తిరిగి (op&0xF010F000)|((op>>16)&0xF)|0x1A00000;
    స్థితి 0x1C00000: //bic
      try_neg=1;
      negop=op^0x1C00000;
      nc=~c;
      ఆపు;
    స్థితి 0x1800000: //orr
      ఒకవేళ(c==~0)
	తిరిగి (op&0xFFF0FFFF)|0x1E00000;
      ఆపు;
  }
  చేయి {
    uint32_t m;
    పూర్ణాంకం i;
    ఒకవేళ(c<256) /* catch undefined <<32 */
      తిరిగి op|c;
    కొరకు(i=2;i<32;i+=2) {
      m=(0xffu>>i)|(0xffu<<(32-i));
      ఒకవేళ(!(c&~m))
	తిరిగి op|(i<<7)|(c<<i)|(c>>(32-i));
    }
    op=negop;
    c=nc;
  } అయితే(try_neg--);
  తిరిగి 0;
}


//only add,sub
శూన్య stuff_const_harder(uint32_t op, uint32_t v) {
  uint32_t x;
  x=stuff_const(op,v);
  ఒకవేళ(x)
    o(x);
  లేకపోతే {
    uint32_t a[16], nv, no, o2, n2;
    పూర్ణాంకం i,j,k;
    a[0]=0xff;
    o2=(op&0xfff0ffff)|((op&0xf000)<<4);;
    కొరకు(i=1;i<16;i++)
      a[i]=(a[i-1]>>2)|(a[i-1]<<30);
    కొరకు(i=0;i<12;i++)
      కొరకు(j=i<4?i+12:15;j>=i+4;j--)
	ఒకవేళ((v&(a[i]|a[j]))==v) {
	  o(stuff_const(op,v&a[i]));
	  o(stuff_const(o2,v&a[j]));
	  తిరిగి;
	}
    no=op^0xC00000;
    n2=o2^0xC00000;
    nv=-v;
    కొరకు(i=0;i<12;i++)
      కొరకు(j=i<4?i+12:15;j>=i+4;j--)
	ఒకవేళ((nv&(a[i]|a[j]))==nv) {
	  o(stuff_const(no,nv&a[i]));
	  o(stuff_const(n2,nv&a[j]));
	  తిరిగి;
	}
    కొరకు(i=0;i<8;i++)
      కొరకు(j=i+4;j<12;j++)
	కొరకు(k=i<4?i+12:15;k>=j+4;k--)
	  ఒకవేళ((v&(a[i]|a[j]|a[k]))==v) {
	    o(stuff_const(op,v&a[i]));
	    o(stuff_const(o2,v&a[j]));
	    o(stuff_const(o2,v&a[k]));
	    తిరిగి;
	  }
    no=op^0xC00000;
    nv=-v;
    కొరకు(i=0;i<8;i++)
      కొరకు(j=i+4;j<12;j++)
	కొరకు(k=i<4?i+12:15;k>=j+4;k--)
	  ఒకవేళ((nv&(a[i]|a[j]|a[k]))==nv) {
	    o(stuff_const(no,nv&a[i]));
	    o(stuff_const(n2,nv&a[j]));
	    o(stuff_const(n2,nv&a[k]));
	    తిరిగి;
	  }
    o(stuff_const(op,v&a[0]));
    o(stuff_const(o2,v&a[4]));
    o(stuff_const(o2,v&a[8]));
    o(stuff_const(o2,v&a[12]));
  }
}

uint32_t encbranch(పూర్ణాంకం pos, పూర్ణాంకం addr, పూర్ణాంకం fail)
{
  addr-=pos+8;
  addr/=4;
  ఒకవేళ(addr>=0x1000000 || addr<-0x1000000) {
    ఒకవేళ(fail)
      tcc_error("FIXME: function bigger than 32MB");
    తిరిగి 0;
  }
  తిరిగి 0x0A000000|(addr&0xffffff);
}

పూర్ణాంకం decbranch(పూర్ణాంకం pos)
{
  పూర్ణాంకం x;
  x=*(uint32_t *)(cur_పాఠ్యం_section->దత్తాంశం + pos);
  x&=0x00ffffff;
  ఒకవేళ(x&0x800000)
    x-=0x1000000;
  తిరిగి x*4+pos+8;
}

/* output a symbol and patch all calls to it */
శూన్య gsym_addr(పూర్ణాంకం t, పూర్ణాంకం a)
{
  uint32_t *x;
  పూర్ణాంకం lt;
  అయితే(t) {
    x=(uint32_t *)(cur_పాఠ్యం_section->దత్తాంశం + t);
    t=decbranch(lt=t);
    ఒకవేళ(a==lt+4)
      *x=0xE1A00000; // nop
    లేకపోతే {
      *x &= 0xff000000;
      *x |= encbranch(lt,a,1);
    }
  }
}

#నిర్వచితమైతే TCC_ARM_VFP
స్థిర uint32_t vfpr(పూర్ణాంకం r)
{
  ఒకవేళ(r<TREG_F0 || r>TREG_F7)
    tcc_error("compiler error! register %i is no vfp register",r);
  తిరిగి r - TREG_F0;
}
#లేకపోతే
స్థిర uint32_t fpr(పూర్ణాంకం r)
{
  ఒకవేళ(r<TREG_F0 || r>TREG_F3)
    tcc_error("compiler error! register %i is no fpa register",r);
  తిరిగి r - TREG_F0;
}
#అయితే_ముగింపు

స్థిర uint32_t intr(పూర్ణాంకం r)
{
  ఒకవేళ(r == TREG_R12)
    తిరిగి 12;
  ఒకవేళ(r >= TREG_R0 && r <= TREG_R3)
    తిరిగి r - TREG_R0;
  ఒకవేళ (!(r >= TREG_SP && r <= TREG_LR))
    tcc_error("compiler error! register %i is no int register",r);
  తిరిగి r + (13 - TREG_SP);
}

స్థిర శూన్య calcaddr(uint32_t *పునాది, పూర్ణాంకం *off, పూర్ణాంకం *sgn, పూర్ణాంకం maxoff, గుర్తులేని జరుపు)
{
  ఒకవేళ(*off>maxoff || *off&((1<<జరుపు)-1)) {
    uint32_t x, y;
    x=0xE280E000;
    ఒకవేళ(*sgn)
      x=0xE240E000;
    x|=(*పునాది)<<16;
    *పునాది=14; // lr
    y=stuff_const(x,*off&~maxoff);
    ఒకవేళ(y) {
      o(y);
      *off&=maxoff;
      తిరిగి;
    }
    y=stuff_const(x,(*off+maxoff)&~maxoff);
    ఒకవేళ(y) {
      o(y);
      *sgn=!*sgn;
      *off=((*off+maxoff)&~maxoff)-*off;
      తిరిగి;
    }
    stuff_const_harder(x,*off&~maxoff);
    *off&=maxoff;
  }
}

స్థిర uint32_t mapcc(పూర్ణాంకం cc)
{
  ఎంపిక(cc)
  {
    స్థితి TOK_ULT:
      తిరిగి 0x30000000; /* CC/LO */
    స్థితి TOK_UGE:
      తిరిగి 0x20000000; /* CS/HS */
    స్థితి TOK_EQ:
      తిరిగి 0x00000000; /* EQ */
    స్థితి TOK_NE:
      తిరిగి 0x10000000; /* NE */
    స్థితి TOK_ULE:
      తిరిగి 0x90000000; /* LS */
    స్థితి TOK_UGT:
      తిరిగి 0x80000000; /* HI */
    స్థితి TOK_Nset:
      తిరిగి 0x40000000; /* MI */
    స్థితి TOK_Nclear:
      తిరిగి 0x50000000; /* PL */
    స్థితి TOK_LT:
      తిరిగి 0xB0000000; /* LT */
    స్థితి TOK_GE:
      తిరిగి 0xA0000000; /* GE */
    స్థితి TOK_LE:
      తిరిగి 0xD0000000; /* LE */
    స్థితి TOK_GT:
      తిరిగి 0xC0000000; /* GT */
  }
  tcc_error("unexpected condition code");
  తిరిగి 0xE0000000; /* AL */
}

స్థిర పూర్ణాంకం negcc(పూర్ణాంకం cc)
{
  ఎంపిక(cc)
  {
    స్థితి TOK_ULT:
      తిరిగి TOK_UGE;
    స్థితి TOK_UGE:
      తిరిగి TOK_ULT;
    స్థితి TOK_EQ:
      తిరిగి TOK_NE;
    స్థితి TOK_NE:
      తిరిగి TOK_EQ;
    స్థితి TOK_ULE:
      తిరిగి TOK_UGT;
    స్థితి TOK_UGT:
      తిరిగి TOK_ULE;
    స్థితి TOK_Nset:
      తిరిగి TOK_Nclear;
    స్థితి TOK_Nclear:
      తిరిగి TOK_Nset;
    స్థితి TOK_LT:
      తిరిగి TOK_GE;
    స్థితి TOK_GE:
      తిరిగి TOK_LT;
    స్థితి TOK_LE:
      తిరిగి TOK_GT;
    స్థితి TOK_GT:
      తిరిగి TOK_LE;
  }
  tcc_error("unexpected condition code");
  తిరిగి TOK_NE;
}

/* Load value into register r.
   Use relative/got addressing to avoid setting DT_TEXTREL */
స్థిర శూన్య ఎక్కించు_విలువ(SValue *sv, పూర్ణాంకం r)
{
#ఒకవేళ CONFIG_TCC_CPUVER >= 7
    ఒకవేళ (!(sv->r & VT_SYM)) {
        గుర్తులేని x=sv->c.i;
        o(0xE3000000|intr(r)<<12|(x&0xFFF)|(x<<4&0xF0000)); /* movw rx,#x(lo) */
        ఒకవేళ (x&0xFFFF0000)
          o(0xE3400000|intr(r)<<12|(x>>16&0xFFF)|(x>>12&0xF0000)); /* movt rx,#x(hi) */
        తిరిగి;
    }
#అయితే_ముగింపు
    o(0xE59F0000|(intr(r)<<12)); /* ldr r, [pc] */
    o(0xEA000000); /* b $+4 */
#నిర్వచితం_కాకపోతే CONFIG_TCC_PIC
    ఒకవేళ(sv->r & VT_SYM)
        greloc(cur_పాఠ్యం_section, sv->sym, ind, R_ARM_ABS32);
    o(sv->c.i);
#లేకపోతే
    ఒకవేళ(sv->r & VT_SYM) {
	ఒకవేళ (sv->sym->type.t & VT_STATIC) {
            greloc(cur_పాఠ్యం_section, sv->sym, ind, R_ARM_REL32);
            o(sv->c.i - 12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
        }
        లేకపోతే {
            greloc(cur_పాఠ్యం_section, sv->sym, ind, R_ARM_GOT_PREL);
            o(-12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
            o(0xe5900000 | (intr(r)<<12) | (intr(r)<<16));  // ldr rx,[rx]
            ఒకవేళ (sv->c.i)
              stuff_const_harder(0xe2800000 | (intr(r)<<12) | (intr(r)<<16),
                                 sv->c.i);
        }
    }
    లేకపోతే
        o(sv->c.i);
#అయితే_ముగింపు
}

/* load 'r' from value 'sv' */
శూన్య ఎక్కించు(పూర్ణాంకం r, SValue *sv)
{
  పూర్ణాంకం v, ft, fc, fr, sign;
  uint32_t op, పునాది;
  SValue v1;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  ఒకవేళ(fc>=0)
    sign=0;
  లేకపోతే {
    sign=1;
    fc=-(గుర్తులేని)fc;
  }

  v = fr & VT_VALMASK;
  ఒకవేళ (fr & VT_LVAL) {

    ఒకవేళ ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe510e000; /* ldr r, [lr, #0] */
        greloca(cur_పాఠ్యం_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        తిరిగి;
    }

    పునాది = 0xB; // fp
    ఒకవేళ(v == VT_LLOCAL) {
      v1.type.t = VT_PTR;
      v1.r = VT_LOCAL | VT_LVAL;
      v1.c.i = sv->c.i;
      ఎక్కించు(TREG_LR, &v1);
      పునాది = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } లేకపోతే ఒకవేళ(v == VT_CONST) {
      v1.type.t = VT_PTR;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      ఎక్కించు(TREG_LR, &v1);
      పునాది = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } లేకపోతే ఒకవేళ(v < VT_CONST) {
      పునాది=intr(v);
      fc=sign=0;
      v=VT_LOCAL;
    }
    ఒకవేళ(v == VT_LOCAL) {
      ఒకవేళ(is_float(ft)) {
	calcaddr(&పునాది,&fc,&sign,1020,2);
#నిర్వచితమైతే TCC_ARM_VFP
        op=0xED100A00; /* flds */
        ఒకవేళ(!sign)
          op|=0x800000;
        ఒకవేళ ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* flds -> fldd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(పునాది<<16));
#లేకపోతే
	op=0xED100100;
	ఒకవేళ(!sign)
	  op|=0x800000;
	ఒకవేళ ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#ఒకవేళ LDOUBLE_కొలత != 8
	లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#అయితే_ముగింపు
	o(op|(fpr(r)<<12)|(fc>>2)|(పునాది<<16));
#అయితే_ముగింపు
      } లేకపోతే ఒకవేళ((ft & (VT_BTYPE|VT_UNSIGNED)) == VT_BYTE
                || (ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&పునాది,&fc,&sign,255,0);
	op=0xE1500090;
	ఒకవేళ ((ft & VT_BTYPE) == VT_SHORT)
	  op|=0x20;
	ఒకవేళ ((ft & VT_UNSIGNED) == 0)
	  op|=0x40;
	ఒకవేళ(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(పునాది<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } లేకపోతే {
	calcaddr(&పునాది,&fc,&sign,4095,0);
	op=0xE5100000;
	ఒకవేళ(!sign)
	  op|=0x800000;
        ఒకవేళ ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(పునాది<<16));
      }
      తిరిగి;
    }
  } లేకపోతే {
    ఒకవేళ (v == VT_CONST) {
      op=stuff_const(0xE3A00000|(intr(r)<<12),sv->c.i);
      ఒకవేళ (fr & VT_SYM || !op)
	ఎక్కించు_విలువ(sv, r);
      లేకపోతే
        o(op);
      తిరిగి;
    } లేకపోతే ఒకవేళ (v == VT_LOCAL) {
      op=stuff_const(0xE28B0000|(intr(r)<<12),sv->c.i);
      ఒకవేళ (fr & VT_SYM || !op) {
	ఎక్కించు_విలువ(sv, r);
	o(0xE08B0000|(intr(r)<<12)|intr(r));
      } లేకపోతే
	o(op);
      తిరిగి;
    } లేకపోతే ఒకవేళ(v == VT_CMP) {
      o(mapcc(sv->c.i)|0x3A00001|(intr(r)<<12));
      o(mapcc(negcc(sv->c.i))|0x3A00000|(intr(r)<<12));
      తిరిగి;
    } లేకపోతే ఒకవేళ (v == VT_JMP || v == VT_JMPI) {
      పూర్ణాంకం t;
      t = v & 1;
      o(0xE3A00000|(intr(r)<<12)|t);
      o(0xEA000000);
      gsym(sv->c.i);
      o(0xE3A00000|(intr(r)<<12)|(t^1));
      తిరిగి;
    } లేకపోతే ఒకవేళ (v < VT_CONST) {
      ఒకవేళ(is_float(ft))
#నిర్వచితమైతే TCC_ARM_VFP
        o(0xEEB00A40|(vfpr(r)<<12)|vfpr(v)|T2CPR(ft)); /* fcpyX */
#లేకపోతే
	o(0xEE008180|(fpr(r)<<12)|fpr(v));
#అయితే_ముగింపు
      లేకపోతే
	o(0xE1A00000|(intr(r)<<12)|intr(v));
      తిరిగి;
    }
  }
  tcc_error("load unimplemented!");
}

/* store register 'r' in lvalue 'v' */
శూన్య store(పూర్ణాంకం r, SValue *sv)
{
  SValue v1;
  పూర్ణాంకం v, ft, fc, fr, sign;
  uint32_t op, పునాది;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  ఒకవేళ(fc>=0)
    sign=0;
  లేకపోతే {
    sign=1;
    fc=-fc;
  }

  v = fr & VT_VALMASK;
  ఒకవేళ (fr & VT_LVAL || fr == VT_LOCAL) {

    ఒకవేళ ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe500e000; /* str r, [lr, #0] */
        greloca(cur_పాఠ్యం_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        తిరిగి;
    }

    పునాది = 0xb; /* fp */
    ఒకవేళ(v < VT_CONST) {
      పునాది=intr(v);
      v=VT_LOCAL;
      fc=sign=0;
    } లేకపోతే ఒకవేళ(v == VT_CONST) {
      v1.type.t = ft;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      ఎక్కించు(TREG_LR, &v1);
      పునాది = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    }
    ఒకవేళ(v == VT_LOCAL) {
       ఒకవేళ(is_float(ft)) {
	calcaddr(&పునాది,&fc,&sign,1020,2);
#నిర్వచితమైతే TCC_ARM_VFP
        op=0xED000A00; /* fsts */
        ఒకవేళ(!sign)
          op|=0x800000;
        ఒకవేళ ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* fsts -> fstd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(పునాది<<16));
#లేకపోతే
	op=0xED000100;
	ఒకవేళ(!sign)
	  op|=0x800000;
	ఒకవేళ ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#ఒకవేళ LDOUBLE_కొలత != 8
	లేకపోతే ఒకవేళ ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#అయితే_ముగింపు
	o(op|(fpr(r)<<12)|(fc>>2)|(పునాది<<16));
#అయితే_ముగింపు
	తిరిగి;
      } లేకపోతే ఒకవేళ((ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&పునాది,&fc,&sign,255,0);
	op=0xE14000B0;
	ఒకవేళ(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(పునాది<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } లేకపోతే {
	calcaddr(&పునాది,&fc,&sign,4095,0);
	op=0xE5000000;
	ఒకవేళ(!sign)
	  op|=0x800000;
        ఒకవేళ ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(పునాది<<16));
      }
      తిరిగి;
    }
  }
  tcc_error("store unimplemented");
}

స్థిర శూన్య gadd_sp(పూర్ణాంకం val)
{
  stuff_const_harder(0xE28DD000,val);
}

/* 'is_jmp' is '1' if it is a jump */
స్థిర శూన్య gcall_or_jmp(పూర్ణాంకం is_jmp)
{
  పూర్ణాంకం r;
  uint32_t x;
  ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
    /* constant case */
    ఒకవేళ(vtop->r & VT_SYM){
	x=encbranch(ind,ind+vtop->c.i,0);
	ఒకవేళ(x) {
	    /* relocation case */
	    greloc(cur_పాఠ్యం_section, vtop->sym, ind, R_ARM_PC24);
	    o(x|(is_jmp?0xE0000000:0xE1000000));
	} లేకపోతే {
	    r = TREG_LR;
	    ఎక్కించు_విలువ(vtop, r);
	    ఒకవేళ(is_jmp)
	        o(0xE1A0F000 | intr(r)); // mov pc, r
	    లేకపోతే
		o(0xe12fff30 | intr(r)); // blx r
	}
     }లేకపోతే{
	ఒకవేళ(!is_jmp)
	    o(0xE28FE004); // add lr,pc,#4
	o(0xE51FF004);   // ldr pc,[pc,#-4]
	o(vtop->c.i);
     }
  } లేకపోతే {
    /* otherwise, indirect call */
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    vtop->r &= ~VT_MUSTBOUND;
#అయితే_ముగింపు
    r = gv(RC_INT);
    ఒకవేళ(!is_jmp)
      o(0xE1A0E00F);       // mov lr,pc
    o(0xE1A0F000|intr(r)); // mov pc,r
  }
}

#ఒకవేళ defined(CONFIG_TCC_BCHECK)

స్థిర శూన్య gen_bounds_call(పూర్ణాంకం v)
{
    Sym *sym = external_helper_sym(v);

    greloc(cur_పాఠ్యం_section, sym, ind, R_ARM_PC24);
    o(0xebfffffe);
}

స్థిర శూన్య gen_bounds_prolog(శూన్య)
{
    /* leave some room for bound checking code */
    func_bound_స్థానభ్రంశం = lbounds_section->దత్తాంశం_స్థానభ్రంశం;
    func_bound_ind = ind;
    func_bound_కూడు_epilog = 0;
    o(0xe1a00000);  /* ld r0,lbounds_section->data_offset */
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);  /* call __bound_local_new */
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
        o(0xe59f0000);  /* ldr r0, [pc] */
        o(0xea000000);  /* b $+4 */
        greloc(cur_పాఠ్యం_section, sym_దత్తాంశం, ind, R_ARM_REL32);
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
    greloc(cur_పాఠ్యం_section, sym_దత్తాంశం, ind, R_ARM_REL32);
    o(-12);  /* lbounds_section->data_offset */
    o(0xe080000f);  /* add r0,r0,pc */
    gen_bounds_call(TOK___bound_local_delete);
    o(0xecbd0b04); /* vpop {d0,d1} */
    o(0xe8bd0003); /* pop {r0,r1} */
}
#అయితే_ముగింపు

/* Return whether a structure is an homogeneous float aggregate or not.
   The answer is true if all the elements of the structure are of the same
   primitive float type and there is less than 4 elements.

   type: the type corresponding to the structure to be tested */
స్థిర పూర్ణాంకం is_hgen_float_aggr(CType *type)
{
  ఒకవేళ ((type->t & VT_BTYPE) == VT_STRUCT) {
    నిర్మాణం Sym *ref;
    పూర్ణాంకం btype, nb_fields = 0;

    ref = type->ref->తదుపరి;
    ఒకవేళ (ref) {
      btype = ref->type.t & VT_BTYPE;
      ఒకవేళ (btype == VT_FLOAT || btype == VT_DOUBLE) {
        కొరకు(; ref && btype == (ref->type.t & VT_BTYPE); ref = ref->తదుపరి, nb_fields++)
            ;
        తిరిగి !ref && nb_fields <= 4;
      }
    }
  }
  తిరిగి 0;
}

నిర్మాణం avail_regs {
  గుర్తుగల అక్షరం avail[3]; /* 3 holes max with only float and double alignments */
  పూర్ణాంకం మొదటి_hole; /* first available hole */
  పూర్ణాంకం చివరి_hole; /* last available hole (none if equal to first_hole) */
  పూర్ణాంకం మొదటి_free_reg; /* next free register in the sequence, hole excluded */
};

/* Find suitable registers for a VFP Co-Processor Register Candidate (VFP CPRC
   param) according to the rules described in the procedure call standard for
   the ARM architecture (AAPCS). If found, the registers are assigned to this
   VFP CPRC parameter. Registers are allocated in sequence unless a hole exists
   and the parameter is a single float.

   avregs: opaque structure to keep track of available VFP co-processor regs
   align: alignment constraints for the param, as returned by type_size()
   size: size of the parameter, as returned by type_size() */
పూర్ణాంకం కేటాయించు_vfpreg(నిర్మాణం avail_regs *avregs, పూర్ణాంకం align, పూర్ణాంకం కొలత)
{
  పూర్ణాంకం మొదటి_reg = 0;

  ఒకవేళ (avregs->మొదటి_free_reg == -1)
    తిరిగి -1;
  ఒకవేళ (align >> 3) { /* double alignment */
    మొదటి_reg = avregs->మొదటి_free_reg;
    /* alignment constraint not respected so use next reg and record hole */
    ఒకవేళ (మొదటి_reg & 1)
      avregs->avail[avregs->చివరి_hole++] = మొదటి_reg++;
  } లేకపోతే { /* no special alignment (float or array of float) */
    /* if single float and a hole is available, assign the param to it */
    ఒకవేళ (కొలత == 4 && avregs->మొదటి_hole != avregs->చివరి_hole)
      తిరిగి avregs->avail[avregs->మొదటి_hole++];
    లేకపోతే
      మొదటి_reg = avregs->మొదటి_free_reg;
  }
  ఒకవేళ (మొదటి_reg + కొలత / 4 <= 16) {
    avregs->మొదటి_free_reg = మొదటి_reg + కొలత / 4;
    తిరిగి మొదటి_reg;
  }
  avregs->మొదటి_free_reg = -1;
  తిరిగి -1;
}

/* Returns whether all params need to be passed in core registers or not.
   This is the case for function part of the runtime ABI. */
పూర్ణాంకం floats_లోపల_core_regs(SValue *sval)
{
  ఒకవేళ (!sval->sym)
    తిరిగి 0;

  ఎంపిక (sval->sym->v) {
    స్థితి TOK___floatundisf:
    స్థితి TOK___floatundidf:
    స్థితి TOK___fixunssfdi:
    స్థితి TOK___fixunsdfdi:
#నిర్వచితం_కాకపోతే TCC_ARM_VFP
    స్థితి TOK___fixunsxfdi:
#అయితే_ముగింపు
    స్థితి TOK___floatdisf:
    స్థితి TOK___floatdidf:
    స్థితి TOK___fixsfdi:
    స్థితి TOK___fixdfdi:
      తిరిగి 1;

    అప్రమేయ:
      తిరిగి 0;
  }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC పూర్ణాంకం gfunc_sret(CType *vt, పూర్ణాంకం variadic, CType *ret, పూర్ణాంకం *ret_align, పూర్ణాంకం *regsize) {
#నిర్వచితమైతే TCC_ARM_EABI
    పూర్ణాంకం కొలత, align;
    కొలత = type_కొలత(vt, &align);
    ఒకవేళ (float_abi == ARM_HARD_FLOAT && !variadic &&
        (is_float(vt->t) || is_hgen_float_aggr(vt))) {
        *ret_align = 8;
	*regsize = 8;
        ret->ref = ఖాళీ;
        ret->t = VT_DOUBLE;
        తిరిగి (కొలత + 7) >> 3;
    } లేకపోతే ఒకవేళ (కొలత > 0 && కొలత <= 4) {
        *ret_align = 4;
	*regsize = 4;
        ret->ref = ఖాళీ;
        ret->t = VT_INT;
        తిరిగి 1;
    } లేకపోతే
        తిరిగి 0;
#లేకపోతే
    తిరిగి 0;
#అయితే_ముగింపు
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
గణన reg_class {
	దొంతర_CLASS = 0,
	CORE_STRUCT_CLASS,
	VFP_CLASS,
	VFP_STRUCT_CLASS,
	CORE_CLASS,
	NB_CLASSES
};

నిర్మాణం param_plan {
    పూర్ణాంకం ప్రారంభం; /* first reg or addr used depending on the class */
    పూర్ణాంకం చివర; /* last reg used or next free addr depending on the class */
    SValue *sval; /* pointer to SValue on the value stack */
    నిర్మాణం param_plan *prev; /*  previous element in this class */
};

నిర్మాణం plan {
    నిర్మాణం param_plan *pplans; /* array of all the param plans */
    నిర్మాణం param_plan *clsplans[NB_CLASSES]; /* per class lists of param plans */
    పూర్ణాంకం nb_plans;
};

స్థిర శూన్య కూడు_param_plan(నిర్మాణం plan* plan, పూర్ణాంకం cls, పూర్ణాంకం ప్రారంభం, పూర్ణాంకం చివర, SValue *v)
{
    నిర్మాణం param_plan *p = &plan->pplans[plan->nb_plans++];
    p->prev = plan->clsplans[cls];
    plan->clsplans[cls] = p;
    p->ప్రారంభం = ప్రారంభం, p->చివర = చివర, p->sval = v;
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
స్థిర పూర్ణాంకం కేటాయించు_regs(పూర్ణాంకం nb_వాదనలు, పూర్ణాంకం float_abi, నిర్మాణం plan *plan, పూర్ణాంకం *todo)
{
  పూర్ణాంకం i, కొలత, align;
  పూర్ణాంకం ncrn /* next core register number */, nsaa /* next stacked argument address*/;
  నిర్మాణం avail_regs avregs = {{0}};

  ncrn = nsaa = 0;
  *todo = 0;

  కొరకు(i = nb_వాదనలు; i-- ;) {
    పూర్ణాంకం j, ప్రారంభం_vfpreg = 0;
    CType type = vtop[-i].type;
    type.t &= ~VT_ARRAY;
    కొలత = type_కొలత(&type, &align);
    కొలత = (కొలత + 3) & ~3;
    align = (align + 3) & ~3;
    ఎంపిక(vtop[-i].type.t & VT_BTYPE) {
      స్థితి VT_STRUCT:
      స్థితి VT_FLOAT:
      స్థితి VT_DOUBLE:
      స్థితి VT_LDOUBLE:
      ఒకవేళ (float_abi == ARM_HARD_FLOAT) {
        పూర్ణాంకం is_hfa = 0; /* Homogeneous float aggregate */

        ఒకవేళ (is_float(vtop[-i].type.t)
            || (is_hfa = is_hgen_float_aggr(&vtop[-i].type))) {
          పూర్ణాంకం చివర_vfpreg;

          ప్రారంభం_vfpreg = కేటాయించు_vfpreg(&avregs, align, కొలత);
          చివర_vfpreg = ప్రారంభం_vfpreg + ((కొలత - 1) >> 2);
          ఒకవేళ (ప్రారంభం_vfpreg >= 0) {
            కూడు_param_plan(plan, is_hfa ? VFP_STRUCT_CLASS : VFP_CLASS,
                ప్రారంభం_vfpreg, చివర_vfpreg, &vtop[-i]);
            కొనసాగు;
          } లేకపోతే
            ఆపు;
        }
      }
      ncrn = (ncrn + (align-1)/4) & ~((align/4) - 1);
      ఒకవేళ (ncrn + కొలత/4 <= 4 || (ncrn < 4 && ప్రారంభం_vfpreg != -1)) {
        /* The parameter is allocated both in core register and on stack. As
	 * such, it can be of either class: it would either be the last of
	 * CORE_STRUCT_CLASS or the first of STACK_CLASS. */
        కొరకు (j = ncrn; j < 4 && j < ncrn + కొలత / 4; j++)
          *todo|=(1<<j);
        కూడు_param_plan(plan, CORE_STRUCT_CLASS, ncrn, j, &vtop[-i]);
        ncrn += కొలత/4;
        ఒకవేళ (ncrn > 4)
          nsaa = (ncrn - 4) * 4;
      } లేకపోతే {
        ncrn = 4;
        ఆపు;
      }
      కొనసాగు;
      అప్రమేయ:
      ఒకవేళ (ncrn < 4) {
        పూర్ణాంకం is_long = (vtop[-i].type.t & VT_BTYPE) == VT_LLONG;

        ఒకవేళ (is_long) {
          ncrn = (ncrn + 1) & -2;
          ఒకవేళ (ncrn == 4)
            ఆపు;
        }
        కూడు_param_plan(plan, CORE_CLASS, ncrn, ncrn + is_long, &vtop[-i]);
        ncrn += 1 + is_long;
        కొనసాగు;
      }
    }
    nsaa = (nsaa + (align - 1)) & ~(align - 1);
    కూడు_param_plan(plan, దొంతర_CLASS, nsaa, nsaa + కొలత, &vtop[-i]);
    nsaa += కొలత; /* size already rounded up before */
  }
  తిరిగి nsaa;
}

/* Copy parameters to their final destination (core reg, VFP reg or stack) for
   function call.

   nb_args: number of parameters the function take
   plan: the overall assignment plan for parameters
   todo: a bitmap indicating what core reg will hold a parameter

   Returns the number of SValue added by this function on the value stack */
స్థిర పూర్ణాంకం copy_params(పూర్ణాంకం nb_వాదనలు, నిర్మాణం plan *plan, పూర్ణాంకం todo)
{
  పూర్ణాంకం కొలత, align, r, i, nb_extra_sval = 0;
  నిర్మాణం param_plan *pplan;
  పూర్ణాంకం pass = 0;

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
  కొరకు(i = 0; i < NB_CLASSES; i++) {
    కొరకు(pplan = plan->clsplans[i]; pplan; pplan = pplan->prev) {

      ఒకవేళ (pass
          && (i != CORE_CLASS || pplan->sval->r < VT_CONST))
        కొనసాగు;

      vpushv(pplan->sval);
      pplan->sval->r = pplan->sval->r2 = VT_CONST; /* disable entry */
      ఎంపిక(i) {
        స్థితి దొంతర_CLASS:
        స్థితి CORE_STRUCT_CLASS:
        స్థితి VFP_STRUCT_CLASS:
          ఒకవేళ ((pplan->sval->type.t & VT_BTYPE) == VT_STRUCT) {
            పూర్ణాంకం padding = 0;
            కొలత = type_కొలత(&pplan->sval->type, &align);
            /* align to stack align size */
            కొలత = (కొలత + 3) & ~3;
            ఒకవేళ (i == దొంతర_CLASS && pplan->prev)
              padding = pplan->ప్రారంభం - pplan->prev->చివర;
            కొలత += padding; /* Add padding if any */
            /* allocate the necessary size on stack */
            gadd_sp(-కొలత);
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
            ఒకవేళ (i == VFP_STRUCT_CLASS) {
              పూర్ణాంకం మొదటి = pplan->ప్రారంభం, nb = pplan->చివర - మొదటి + 1;
              /* vpop.32 {pplan->start, ..., pplan->end} */
              o(0xECBD0A00|(మొదటి&1)<<22|(మొదటి>>1)<<12|nb);
              /* No need to write the register used to a SValue since VFP regs
                 cannot be used for gcall_or_jmp */
            }
          } లేకపోతే {
            ఒకవేళ (is_float(pplan->sval->type.t)) {
#నిర్వచితమైతే TCC_ARM_VFP
              r = vfpr(gv(RC_FLOAT)) << 12;
              ఒకవేళ ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                కొలత = 4;
              లేకపోతే {
                కొలత = 8;
                r |= 0x101; /* vpush.32 -> vpush.64 */
              }
              o(0xED2D0A01 + r); /* vpush */
#లేకపోతే
              r = fpr(gv(RC_FLOAT)) << 12;
              ఒకవేళ ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                కొలత = 4;
              లేకపోతే ఒకవేళ ((pplan->sval->type.t & VT_BTYPE) == VT_DOUBLE)
                కొలత = 8;
              లేకపోతే
                కొలత = LDOUBLE_కొలత;
              ఒకవేళ (కొలత == 12)
                r |= 0x400000;
              లేకపోతే ఒకవేళ(కొలత == 8)
                r|=0x8000;

              o(0xED2D0100|r|(కొలత>>2)); /* some kind of vpush for FPA */
#అయితే_ముగింపు
            } లేకపోతే {
              /* simple type (currently always same size) */
              /* XXX: implicit cast ? */
              కొలత=4;
              ఒకవేళ ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
                lexpand();
                కొలత = 8;
                r = gv(RC_INT);
                o(0xE52D0004|(intr(r)<<12)); /* push r */
                vtop--;
              }
              r = gv(RC_INT);
              o(0xE52D0004|(intr(r)<<12)); /* push r */
            }
            ఒకవేళ (i == దొంతర_CLASS && pplan->prev)
              gadd_sp(pplan->prev->చివర - pplan->ప్రారంభం); /* Add padding if any */
          }
          ఆపు;

        స్థితి VFP_CLASS:
          gv(regmask(TREG_F0 + (pplan->ప్రారంభం >> 1)));
          ఒకవేళ (pplan->ప్రారంభం & 1) { /* Must be in upper part of double register */
            o(0xEEF00A40|((pplan->ప్రారంభం>>1)<<12)|(pplan->ప్రారంభం>>1)); /* vmov.f32 s(n+1), sn */
            vtop->r = VT_CONST; /* avoid being saved on stack by gv for next float */
          }
          ఆపు;

        స్థితి CORE_CLASS:
          ఒకవేళ ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
            lexpand();
            gv(regmask(pplan->చివర));
            pplan->sval->r2 = vtop->r;
            vtop--;
          }
          gv(regmask(pplan->ప్రారంభం));
          /* Mark register as used so that gcall_or_jmp use another one
             (regs >=4 are free as never used to pass parameters) */
          pplan->sval->r = vtop->r;
          ఆపు;
      }
      vtop--;
    }
  }

  /* second pass to restore registers that were saved on stack by accident.
     Maybe redundant after the "lvalue_save" patch in tccgen.c:gv() */
  ఒకవేళ (++pass < 2)
    వెళ్ళు again;

  ఒకవేళ(todo) {
    o(0xE8BD0000|todo); /* pop {todo} */
    కొరకు(pplan = plan->clsplans[CORE_STRUCT_CLASS]; pplan; pplan = pplan->prev) {
      పూర్ణాంకం r;
      pplan->sval->r = pplan->ప్రారంభం;
      /* An SValue can only pin 2 registers at best (r and r2) but a structure
         can occupy more than 2 registers. Thus, we need to push on the value
         stack some fake parameter to have on SValue for each registers used
         by a structure (r2 is not used). */
      కొరకు (r = pplan->ప్రారంభం + 1; r <= pplan->చివర; r++) {
        ఒకవేళ (todo & (1 << r)) {
          nb_extra_sval++;
          vpushi(0);
          vtop->r = r;
        }
      }
    }
  }
  తిరిగి nb_extra_sval;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
శూన్య gfunc_call(పూర్ణాంకం nb_వాదనలు)
{
  పూర్ణాంకం వాదనలు_కొలత;
  పూర్ణాంకం def_float_abi = float_abi;
  పూర్ణాంకం todo;
  నిర్మాణం plan plan;
#నిర్వచితమైతే TCC_ARM_EABI
  పూర్ణాంకం variadic;
#అయితే_ముగింపు

#నిర్వచితమైతే CONFIG_TCC_BCHECK
  ఒకవేళ (tcc_state->do_bounds_check)
    gbound_వాదనలు(nb_వాదనలు);
#అయితే_ముగింపు

  save_regs(nb_వాదనలు + 1);

#నిర్వచితమైతే TCC_ARM_EABI
  ఒకవేళ (float_abi == ARM_HARD_FLOAT) {
    variadic = (vtop[-nb_వాదనలు].type.ref->f.func_type == FUNC_ELLIPSIS);
    ఒకవేళ (variadic || floats_లోపల_core_regs(&vtop[-nb_వాదనలు]))
      float_abi = ARM_SOFTFP_FLOAT;
  }
#అయితే_ముగింపు

  memset(&plan, 0, పరిమాణం plan);
  ఒకవేళ (nb_వాదనలు)
    plan.pplans = tcc_malloc(nb_వాదనలు * పరిమాణం(*plan.pplans));

  వాదనలు_కొలత = కేటాయించు_regs(nb_వాదనలు, float_abi, &plan, &todo);

#నిర్వచితమైతే TCC_ARM_EABI
  ఒకవేళ (వాదనలు_కొలత & 7) { /* Stack must be 8 byte aligned at fct call for EABI */
    వాదనలు_కొలత = (వాదనలు_కొలత + 7) & ~7;
    o(0xE24DD004); /* sub sp, sp, #4 */
  }
#అయితే_ముగింపు

  nb_వాదనలు += copy_params(nb_వాదనలు, &plan, todo);
  tcc_free(plan.pplans);

  /* Move fct SValue on top as required by gcall_or_jmp */
  vrotb(nb_వాదనలు + 1);
  gcall_or_jmp(0);
  ఒకవేళ (వాదనలు_కొలత)
      gadd_sp(వాదనలు_కొలత); /* pop all parameters passed on the stack */
#ఒకవేళ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  ఒకవేళ(float_abi == ARM_SOFTFP_FLOAT && is_float(vtop->type.ref->type.t)) {
    ఒకవేళ((vtop->type.ref->type.t & VT_BTYPE) == VT_FLOAT) {
      o(0xEE000A10); /*vmov s0, r0 */
    } లేకపోతే {
      o(0xEE000B10); /* vmov.32 d0[0], r0 */
      o(0xEE201B10); /* vmov.32 d0[1], r1 */
    }
  }
#అయితే_ముగింపు
  vtop -= nb_వాదనలు + 1; /* Pop all params and fct address from value stack */
  leaffunc = 0; /* we are calling a function, so we aren't in a leaf function */
  float_abi = def_float_abi;
}

/* generate function prolog of type 't' */
శూన్య gfunc_prolog(Sym *func_sym)
{
  CType *func_type = &func_sym->type;
  Sym *sym,*sym2;
  పూర్ణాంకం n, nf, కొలత, align, rs, struct_ret = 0;
  పూర్ణాంకం addr, pn, sn; /* pn=core, sn=stack */
  CType ret_type;

#నిర్వచితమైతే TCC_ARM_EABI
  నిర్మాణం avail_regs avregs = {{0}};
#అయితే_ముగింపు

  sym = func_type->ref;

  n = nf = 0;
  ఒకవేళ ((func_vt.t & VT_BTYPE) == VT_STRUCT &&
      !gfunc_sret(&func_vt, func_var, &ret_type, &align, &rs))
  {
    n++;
    struct_ret = 1;
    func_vc = 12; /* Offset from fp of the place to store the result */
  }
  కొరకు(sym2 = sym->తదుపరి; sym2 && (n < 4 || nf < 16); sym2 = sym2->తదుపరి) {
    కొలత = type_కొలత(&sym2->type, &align);
#నిర్వచితమైతే TCC_ARM_EABI
    ఒకవేళ (float_abi == ARM_HARD_FLOAT && !func_var &&
        (is_float(sym2->type.t) || is_hgen_float_aggr(&sym2->type))) {
      పూర్ణాంకం tmpnf = కేటాయించు_vfpreg(&avregs, align, కొలత);
      tmpnf += (కొలత + 3) / 4;
      nf = (tmpnf > nf) ? tmpnf : nf;
    } లేకపోతే
#అయితే_ముగింపు
    ఒకవేళ (n < 4)
      n += (కొలత + 3) / 4;
  }
  o(0xE1A0C00D); /* mov ip,sp */
  ఒకవేళ (func_var)
    n=4;
  ఒకవేళ (n) {
    ఒకవేళ(n>4)
      n=4;
#నిర్వచితమైతే TCC_ARM_EABI
    n=(n+1)&-2;
#అయితే_ముగింపు
    o(0xE92D0000|((1<<n)-1)); /* save r0-r4 on stack if needed */
  }
  ఒకవేళ (nf) {
    ఒకవేళ (nf>16)
      nf=16;
    nf=(nf+1)&-2; /* nf => HARDFLOAT => EABI */
    o(0xED2D0A00|nf); /* save s0-s15 on stack if needed */
  }
  o(0xE92D5800); /* save fp, ip, lr */
  o(0xE1A0B00D); /* mov fp, sp */
  func_sub_sp_స్థానభ్రంశం = ind;
  o(0xE1A00000); /* nop, leave space for stack adjustment in epilog */

#నిర్వచితమైతే TCC_ARM_EABI
  ఒకవేళ (float_abi == ARM_HARD_FLOAT) {
    func_vc += nf * 4;
    memset(&avregs, 0, పరిమాణం avregs);
  }
#అయితే_ముగింపు
  pn = struct_ret, sn = 0;
  అయితే ((sym = sym->తదుపరి)) {
    CType *type;
    type = &sym->type;
    కొలత = type_కొలత(type, &align);
    కొలత = (కొలత + 3) >> 2;
    align = (align + 3) & ~3;
#నిర్వచితమైతే TCC_ARM_EABI
    ఒకవేళ (float_abi == ARM_HARD_FLOAT && !func_var && (is_float(sym->type.t)
        || is_hgen_float_aggr(&sym->type))) {
      పూర్ణాంకం fpn = కేటాయించు_vfpreg(&avregs, align, కొలత << 2);
      ఒకవేళ (fpn >= 0)
        addr = fpn * 4;
      లేకపోతే
        వెళ్ళు from_దొంతర;
    } లేకపోతే
#అయితే_ముగింపు
    ఒకవేళ (pn < 4) {
#నిర్వచితమైతే TCC_ARM_EABI
        pn = (pn + (align-1)/4) & -(align/4);
#అయితే_ముగింపు
      addr = (nf + pn) * 4;
      pn += కొలత;
      ఒకవేళ (!sn && pn > 4)
        sn = (pn - 4);
    } లేకపోతే {
#నిర్వచితమైతే TCC_ARM_EABI
from_దొంతర:
        sn = (sn + (align-1)/4) & -(align/4);
#అయితే_ముగింపు
      addr = (n + nf + sn) * 4;
      sn += కొలత;
    }
    gfunc_సమితి_param(sym, addr + 12, 0);
  }
  చివరి_itod_magic=0;
  leaffunc = 1;
  loc = 0;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
  ఒకవేళ (tcc_state->do_bounds_check)
    gen_bounds_prolog();
#అయితే_ముగింపు
}

/* generate function epilog */
శూన్య gfunc_epilog(శూన్య)
{
  uint32_t x;
  పూర్ణాంకం diff;

#నిర్వచితమైతే CONFIG_TCC_BCHECK
  ఒకవేళ (tcc_state->do_bounds_check)
    gen_bounds_epilog();
#అయితే_ముగింపు
  /* Copy float return value to core register if base standard is used and
     float computation is made with VFP */
#ఒకవేళ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  ఒకవేళ ((float_abi == ARM_SOFTFP_FLOAT || func_var) && is_float(func_vt.t)) {
    ఒకవేళ((func_vt.t & VT_BTYPE) == VT_FLOAT)
      o(0xEE100A10); /* fmrs r0, s0 */
    లేకపోతే {
      o(0xEE100B10); /* fmrdl r0, d0 */
      o(0xEE301B10); /* fmrdh r1, d0 */
    }
  }
#అయితే_ముగింపు
  o(0xE89BA800); /* restore fp, sp, pc */
  diff = (-loc + 3) & -4;
#నిర్వచితమైతే TCC_ARM_EABI
  ఒకవేళ(!leaffunc)
    diff = ((diff + 11) & -8) - 4;
#అయితే_ముగింపు
  ఒకవేళ(diff > 0) {
    x=stuff_const(0xE24BD000, diff); /* sub sp,fp,# */
    ఒకవేళ(x)
      *(uint32_t *)(cur_పాఠ్యం_section->దత్తాంశం + func_sub_sp_స్థానభ్రంశం) = x;
    లేకపోతే {
      పూర్ణాంకం addr;
      addr=ind;
      o(0xE59FC004); /* ldr ip,[pc+4] */
      o(0xE04BD00C); /* sub sp,fp,ip  */
      o(0xE1A0F00E); /* mov pc,lr */
      o(diff);
      *(uint32_t *)(cur_పాఠ్యం_section->దత్తాంశం + func_sub_sp_స్థానభ్రంశం) = 0xE1000000|encbranch(func_sub_sp_స్థానభ్రంశం,addr,1);
    }
  }
}

ST_FUNC శూన్య gen_fill_nops(పూర్ణాంకం బైట్లు)
{
    ఒకవేళ ((బైట్లు & 3))
      tcc_error("alignment of code section not multiple of 4");
    అయితే (బైట్లు > 0) {
	o(0xE1A00000);
	బైట్లు -= 4;
    }
}

/* generate a jump to a label */
ST_FUNC పూర్ణాంకం gjmp(పూర్ణాంకం t)
{
  పూర్ణాంకం r;
  ఒకవేళ (nocode_wanted)
    తిరిగి t;
  r=ind;
  o(0xE0000000|encbranch(r,t,1));
  తిరిగి r;
}

/* generate a jump to a fixed address */
ST_FUNC శూన్య gjmp_addr(పూర్ణాంకం a)
{
  gjmp(a);
}

ST_FUNC పూర్ణాంకం gjmp_cond(పూర్ణాంకం op, పూర్ణాంకం t)
{
  పూర్ణాంకం r;
  ఒకవేళ (nocode_wanted)
    తిరిగి t;
  r=ind;
  op=mapcc(op);
  op|=encbranch(r,t,1);
  o(op);
  తిరిగి r;
}

ST_FUNC పూర్ణాంకం gjmp_append(పూర్ణాంకం n, పూర్ణాంకం t)
{
  uint32_t *x;
  పూర్ణాంకం p,lp;
  ఒకవేళ(n) {
    p = n;
    చేయి {
      p = decbranch(lp=p);
    } అయితే(p);
    x = (uint32_t *)(cur_పాఠ్యం_section->దత్తాంశం + lp);
    *x &= 0xff000000;
    *x |= encbranch(lp,t,1);
    t = n;
  }
  తిరిగి t;
}

/* generate an integer binary operation */
శూన్య gen_opi(పూర్ణాంకం op)
{
  పూర్ణాంకం c, func = 0;
  uint32_t opc = 0, r, fr;
  గుర్తులేని పొట్టి retreg = REG_IRET;

  c=0;
  ఎంపిక(op) {
    స్థితి '+':
      opc = 0x8;
      c=1;
      ఆపు;
    స్థితి TOK_ADDC1: /* add with carry generation */
      opc = 0x9;
      c=1;
      ఆపు;
    స్థితి '-':
      opc = 0x4;
      c=1;
      ఆపు;
    స్థితి TOK_SUBC1: /* sub with carry generation */
      opc = 0x5;
      c=1;
      ఆపు;
    స్థితి TOK_ADDC2: /* add with carry use */
      opc = 0xA;
      c=1;
      ఆపు;
    స్థితి TOK_SUBC2: /* sub with carry use */
      opc = 0xC;
      c=1;
      ఆపు;
    స్థితి '&':
      opc = 0x0;
      c=1;
      ఆపు;
    స్థితి '^':
      opc = 0x2;
      c=1;
      ఆపు;
    స్థితి '|':
      opc = 0x18;
      c=1;
      ఆపు;
    స్థితి '*':
      gv2(RC_INT, RC_INT);
      r = vtop[-1].r;
      fr = vtop[0].r;
      vtop--;
      o(0xE0000090|(intr(r)<<16)|(intr(r)<<8)|intr(fr));
      తిరిగి;
    స్థితి TOK_SHL:
      opc = 0;
      c=2;
      ఆపు;
    స్థితి TOK_SHR:
      opc = 1;
      c=2;
      ఆపు;
    స్థితి TOK_SAR:
      opc = 2;
      c=2;
      ఆపు;
    స్థితి '/':
    స్థితి TOK_PDIV:
      func=TOK___divsi3;
      c=3;
      ఆపు;
    స్థితి TOK_UDIV:
      func=TOK___udivsi3;
      c=3;
      ఆపు;
    స్థితి '%':
#నిర్వచితమైతే TCC_ARM_EABI
      func=TOK___aeabi_idivmod;
      retreg=REG_IRE2;
#లేకపోతే
      func=TOK___modsi3;
#అయితే_ముగింపు
      c=3;
      ఆపు;
    స్థితి TOK_UMOD:
#నిర్వచితమైతే TCC_ARM_EABI
      func=TOK___aeabi_uidivmod;
      retreg=REG_IRE2;
#లేకపోతే
      func=TOK___umodsi3;
#అయితే_ముగింపు
      c=3;
      ఆపు;
    స్థితి TOK_UMULL:
      gv2(RC_INT, RC_INT);
      r=intr(vtop[-1].r2=get_reg(RC_INT));
      c=vtop[-1].r;
      vtop[-1].r=get_reg_ex(RC_INT,regmask(c));
      vtop--;
      o(0xE0800090|(r<<16)|(intr(vtop->r)<<12)|(intr(c)<<8)|intr(vtop[1].r));
      తిరిగి;
    అప్రమేయ:
      opc = 0x15;
      c=1;
      ఆపు;
  }
  ఎంపిక(c) {
    స్థితి 1:
      ఒకవేళ((vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	ఒకవేళ(opc == 4 || opc == 5 || opc == 0xc) {
	  vswap();
	  opc|=2; // sub -> rsb
	}
      }
      vswap();
      c=intr(gv(RC_INT));
      vswap();
      opc=0xE0000000|(opc<<20);
      ఒకవేళ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	uint32_t x;
	x=stuff_const(opc|0x2000000|(c<<16),vtop->c.i);
	ఒకవేళ(x) {
	  ఒకవేళ ((x & 0xfff00000) == 0xe3500000)   // cmp rx,#c
	    o(x);
	  లేకపోతే {
	    r=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	    o(x|(r<<12));
	  }
	  వెళ్ళు పూర్తి;
	}
      }
      fr=intr(gv(RC_INT));
#నిర్వచితమైతే CONFIG_TCC_BCHECK
      ఒకవేళ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
        vswap();
        c=intr(gv(RC_INT));
        vswap();
      }
#అయితే_ముగింపు
      ఒకవేళ ((opc & 0xfff00000) == 0xe1500000) // cmp rx,ry
	o(opc|(c<<16)|fr);
      లేకపోతే {
        r=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
        o(opc|(c<<16)|(r<<12)|fr);
      }
పూర్తి:
      vtop--;
      ఒకవేళ (op >= TOK_ULT && op <= TOK_GT)
        vset_VT_CMP(op);
      ఆపు;
    స్థితి 2:
      opc=0xE1A00000|(opc<<5);
      vswap();
      r=intr(gv(RC_INT));
      vswap();
      ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	fr=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	c = vtop->c.i & 0x1f;
	o(opc|r|(c<<7)|(fr<<12));
      } లేకపోతే {
        fr=intr(gv(RC_INT));
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=intr(gv(RC_INT));
          vswap();
        }
#అయితే_ముగింపు
	c=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
	o(opc|r|(c<<12)|(fr<<8)|0x10);
      }
      vtop--;
      ఆపు;
    స్థితి 3:
      vpush_helper_func(func);
      vrott(3);
      gfunc_call(2);
      vpushi(0);
      vtop->r = retreg;
      ఆపు;
    అప్రమేయ:
      tcc_error("gen_opi %i unimplemented!",op);
  }
}

#నిర్వచితమైతే TCC_ARM_VFP
స్థిర పూర్ణాంకం is_zero(పూర్ణాంకం i)
{
  ఒకవేళ((vtop[i].r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    తిరిగి 0;
  ఒకవేళ (vtop[i].type.t == VT_FLOAT)
    తిరిగి (vtop[i].c.f == 0.f);
  లేకపోతే ఒకవేళ (vtop[i].type.t == VT_DOUBLE)
    తిరిగి (vtop[i].c.d == 0.0);
  తిరిగి (vtop[i].c.ld == 0.l);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
 *    two operands are guaranteed to have the same floating point type */
శూన్య gen_opf(పూర్ణాంకం op)
{
  uint32_t x;
  పూర్ణాంకం fneg=0,r;
  x=0xEE000A00|T2CPR(vtop->type.t);
  ఎంపిక(op) {
    స్థితి '+':
      ఒకవేళ(is_zero(-1))
        vswap();
      ఒకవేళ(is_zero(0)) {
        vtop--;
        తిరిగి;
      }
      x|=0x300000;
      ఆపు;
    స్థితి '-':
      x|=0x300040;
      ఒకవేళ(is_zero(0)) {
        vtop--;
        తిరిగి;
      }
      ఒకవేళ(is_zero(-1)) {
        x|=0x810000; /* fsubX -> fnegX */
        vswap();
        vtop--;
        fneg=1;
      }
      ఆపు;
    స్థితి '*':
      x|=0x200000;
      ఆపు;
    స్థితి '/':
      x|=0x800000;
      ఆపు;
    అప్రమేయ:
      ఒకవేళ(op < TOK_ULT || op > TOK_GT) {
        tcc_error("unknown fp op %x!",op);
        తిరిగి;
      }
      ఒకవేళ(is_zero(-1)) {
        vswap();
        ఎంపిక(op) {
          స్థితి TOK_LT: op=TOK_GT; ఆపు;
          స్థితి TOK_GE: op=TOK_ULE; ఆపు;
          స్థితి TOK_LE: op=TOK_GE; ఆపు;
          స్థితి TOK_GT: op=TOK_ULT; ఆపు;
        }
      }
      x|=0xB40040; /* fcmpX */
      ఒకవేళ(op!=TOK_EQ && op!=TOK_NE)
        x|=0x80; /* fcmpX -> fcmpeX */
      ఒకవేళ(is_zero(0)) {
        vtop--;
        o(x|0x10000|(vfpr(gv(RC_FLOAT))<<12)); /* fcmp(e)X -> fcmp(e)zX */
      } లేకపోతే {
        gv2(RC_FLOAT,RC_FLOAT);
        x|=vfpr(vtop[0].r);
        o(x|(vfpr(vtop[-1].r) << 12));
        vtop--;
      }
      o(0xEEF1FA10); /* fmstat */

      ఎంపిక(op) {
        స్థితి TOK_LE: op=TOK_ULE; ఆపు;
        స్థితి TOK_LT: op=TOK_ULT; ఆపు;
        స్థితి TOK_UGE: op=TOK_GE; ఆపు;
        స్థితి TOK_UGT: op=TOK_GT; ఆపు;
      }
      vset_VT_CMP(op);
      తిరిగి;
  }
  r=gv(RC_FLOAT);
  x|=vfpr(r);
  r=regmask(r);
  ఒకవేళ(!fneg) {
    పూర్ణాంకం r2;
    vswap();
    r2=gv(RC_FLOAT);
    x|=vfpr(r2)<<16;
    r|=regmask(r2);
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
      vswap();
      r=gv(RC_FLOAT);
      vswap();
      x=(x&~0xf)|vfpr(r);
    }
#అయితే_ముగింపు
  }
  vtop->r=get_reg_ex(RC_FLOAT,r);
  ఒకవేళ(!fneg)
    vtop--;
  o(x|(vfpr(vtop->r)<<12));
}

#లేకపోతే
స్థిర uint32_t is_fconst()
{
  దీర్ఘ ద్విగుణ f;
  uint32_t r;
  ఒకవేళ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    తిరిగి 0;
  ఒకవేళ (vtop->type.t == VT_FLOAT)
    f = vtop->c.f;
  లేకపోతే ఒకవేళ (vtop->type.t == VT_DOUBLE)
    f = vtop->c.d;
  లేకపోతే
    f = vtop->c.ld;
  ఒకవేళ(!ieee_finite(f))
    తిరిగి 0;
  r=0x8;
  ఒకవేళ(f<0.0) {
    r=0x18;
    f=-f;
  }
  ఒకవేళ(f==0.0)
    తిరిగి r;
  ఒకవేళ(f==1.0)
    తిరిగి r|1;
  ఒకవేళ(f==2.0)
    తిరిగి r|2;
  ఒకవేళ(f==3.0)
    తిరిగి r|3;
  ఒకవేళ(f==4.0)
    తిరిగి r|4;
  ఒకవేళ(f==5.0)
    తిరిగి r|5;
  ఒకవేళ(f==0.5)
    తిరిగి r|6;
  ఒకవేళ(f==10.0)
    తిరిగి r|7;
  తిరిగి 0;
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
శూన్య gen_opf(పూర్ణాంకం op)
{
  uint32_t x, r, r2, c1, c2;
  //fputs("gen_opf\n",stderr);
  vswap();
  c1 = is_fconst();
  vswap();
  c2 = is_fconst();
  x=0xEE000100;
  ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
    x|=0x80;
#ఒకవేళ LDOUBLE_కొలత != 8
  లేకపోతే ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE)
    x|=0x80000;
#అయితే_ముగింపు

  ఎంపిక(op)
  {
    స్థితి '+':
      ఒకవేళ(!c2) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      ఒకవేళ(c2) {
	ఒకవేళ(c2>0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
      } లేకపోతే {
	r2=fpr(gv(RC_FLOAT));
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#అయితే_ముగింపు
      }
      ఆపు;
    స్థితి '-':
      ఒకవేళ(c2) {
	ఒకవేళ(c2<=0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } లేకపోతే ఒకవేళ(c1 && c1<=0xf) {
	x|=0x300000; // rsf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } లేకపోతే {
	x|=0x200000; // suf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#అయితే_ముగింపు
      }
      ఆపు;
    స్థితి '*':
      ఒకవేళ(!c2 || c2>0xf) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      ఒకవేళ(c2 && c2<=0xf)
	r2=c2;
      లేకపోతే {
	r2=fpr(gv(RC_FLOAT));
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#అయితే_ముగింపు
      }
      x|=0x100000; // muf
      ఆపు;
    స్థితి '/':
      ఒకవేళ(c2 && c2<=0xf) {
	x|=0x400000; // dvf
	r2=c2;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } లేకపోతే ఒకవేళ(c1 && c1<=0xf) {
	x|=0x500000; // rdf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } లేకపోతే {
	x|=0x400000; // dvf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#అయితే_ముగింపు
      }
      ఆపు;
    అప్రమేయ:
      ఒకవేళ(op >= TOK_ULT && op <= TOK_GT) {
	x|=0xd0f110; // cmfe
/* bug (intention?) in Linux FPU emulator
   doesn't set carry if equal */
	ఎంపిక(op) {
	  స్థితి TOK_ULT:
	  స్థితి TOK_UGE:
	  స్థితి TOK_ULE:
	  స్థితి TOK_UGT:
            tcc_error("unsigned comparison on floats?");
	    ఆపు;
	  స్థితి TOK_LT:
            op=TOK_Nset;
	    ఆపు;
	  స్థితి TOK_LE:
            op=TOK_ULE; /* correct in unordered case only if AC bit in FPSR set */
	    ఆపు;
	  స్థితి TOK_EQ:
	  స్థితి TOK_NE:
	    x&=~0x400000; // cmfe -> cmf
	    ఆపు;
	}
	ఒకవేళ(c1 && !c2) {
	  c2=c1;
	  vswap();
	  ఎంపిక(op) {
            స్థితి TOK_Nset:
              op=TOK_GT;
	      ఆపు;
            స్థితి TOK_GE:
	      op=TOK_ULE;
	      ఆపు;
	    స్థితి TOK_ULE:
              op=TOK_GE;
	      ఆపు;
            స్థితి TOK_GT:
              op=TOK_Nset;
	      ఆపు;
	  }
	}
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	ఒకవేళ(c2) {
	  ఒకవేళ(c2>0xf)
	    x|=0x200000;
	  r2=c2&0xf;
	} లేకపోతే {
	  r2=fpr(gv(RC_FLOAT));
#నిర్వచితమైతే CONFIG_TCC_BCHECK
          ఒకవేళ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            r=fpr(gv(RC_FLOAT));
            vswap();
          }
#అయితే_ముగింపు
	}
        --vtop;
        vset_VT_CMP(op);
        ++vtop;
      } లేకపోతే {
        tcc_error("unknown fp op %x!",op);
	తిరిగి;
      }
  }
  ఒకవేళ(vtop[-1].r == VT_CMP)
    c1=15;
  లేకపోతే {
    c1=vtop->r;
    ఒకవేళ(r2&0x8)
      c1=vtop[-1].r;
    vtop[-1].r=get_reg_ex(RC_FLOAT,two2mask(vtop[-1].r,c1));
    c1=fpr(vtop[-1].r);
  }
  vtop--;
  o(x|(r<<16)|(c1<<12)|r2);
}
#అయితే_ముగింపు

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ST_FUNC శూన్య gen_cvt_itof(పూర్ణాంకం t)
{
  uint32_t r, r2;
  పూర్ణాంకం bt;
  bt=vtop->type.t & VT_BTYPE;
  ఒకవేళ(bt == VT_INT || bt == VT_SHORT || bt == VT_BYTE) {
#నిర్వచితం_కాకపోతే TCC_ARM_VFP
    uint32_t dsize = 0;
#అయితే_ముగింపు
    r=intr(gv(RC_INT));
#నిర్వచితమైతే TCC_ARM_VFP
    r2=vfpr(vtop->r=get_reg(RC_FLOAT));
    o(0xEE000A10|(r<<12)|(r2<<16)); /* fmsr */
    r2|=r2<<12;
    ఒకవేళ(!(vtop->type.t & VT_UNSIGNED))
      r2|=0x80;                /* fuitoX -> fsituX */
    o(0xEEB80A40|r2|T2CPR(t)); /* fYitoX*/
#లేకపోతే
    r2=fpr(vtop->r=get_reg(RC_FLOAT));
    ఒకవేళ((t & VT_BTYPE) != VT_FLOAT)
      dsize=0x80;    /* flts -> fltd */
    o(0xEE000110|dsize|(r2<<16)|(r<<12)); /* flts */
    ఒకవేళ((vtop->type.t & (VT_UNSIGNED|VT_BTYPE)) == (VT_UNSIGNED|VT_INT)) {
      uint32_t off = 0;
      o(0xE3500000|(r<<12));        /* cmp */
      r=fpr(get_reg(RC_FLOAT));
      ఒకవేళ(చివరి_itod_magic) {
	off=ind+8-చివరి_itod_magic;
	off/=4;
	ఒకవేళ(off>255)
	  off=0;
      }
      o(0xBD1F0100|(r<<12)|off);    /* ldflts */
      ఒకవేళ(!off) {
        o(0xEA000000);              /* b */
        చివరి_itod_magic=ind;
        o(0x4F800000);              /* 4294967296.0f */
      }
      o(0xBE000100|dsize|(r2<<16)|(r2<<12)|r); /* adflt */
    }
#అయితే_ముగింపు
    తిరిగి;
  } లేకపోతే ఒకవేళ(bt == VT_LLONG) {
    పూర్ణాంకం func;
    CType *func_type = 0;
    ఒకవేళ((t & VT_BTYPE) == VT_FLOAT) {
      func_type = &func_float_type;
      ఒకవేళ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundisf;
      లేకపోతే
        func=TOK___floatdisf;
    } లేకపోతే ఒకవేళ((t & VT_BTYPE) == VT_DOUBLE) {
      func_type = &func_double_type;
      ఒకవేళ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundidf;
      లేకపోతే
        func=TOK___floatdidf;
#ఒకవేళ LDOUBLE_కొలత != 8
    } లేకపోతే ఒకవేళ((t & VT_BTYPE) == VT_LDOUBLE) {
      func_type = &func_ldouble_type;
      ఒకవేళ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundixf;
      లేకపోతే
        func=TOK___floatdixf;
#అయితే_ముగింపు
    }
    ఒకవేళ(func_type) {
      vpushsym(func_type, external_helper_sym(func));
      vswap();
      gfunc_call(1);
      vpushi(0);
      vtop->r=TREG_F0;
      తిరిగి;
    }
  }
  tcc_error("unimplemented gen_cvt_itof %x!",vtop->type.t);
}

/* convert fp to int 't' type */
శూన్య gen_cvt_ftoi(పూర్ణాంకం t)
{
  uint32_t r, r2;
  పూర్ణాంకం u, func = 0;
  u=t&VT_UNSIGNED;
  t&=VT_BTYPE;
  r2=vtop->type.t & VT_BTYPE;
  ఒకవేళ(t==VT_INT) {
#నిర్వచితమైతే TCC_ARM_VFP
    r=vfpr(gv(RC_FLOAT));
    u=u?0:0x10000;
    o(0xEEBC0AC0|(r<<12)|r|T2CPR(r2)|u); /* ftoXizY */
    r2=intr(vtop->r=get_reg(RC_INT));
    o(0xEE100A10|(r<<16)|(r2<<12));
    తిరిగి;
#లేకపోతే
    ఒకవేళ(u) {
      ఒకవేళ(r2 == VT_FLOAT)
        func=TOK___fixunssfsi;
      లేకపోతే ఒకవేళ(r2 == VT_DOUBLE)
	func=TOK___fixunsdfsi;
#ఒకవేళ LDOUBLE_కొలత != 8
      లేకపోతే ఒకవేళ(r2 == VT_LDOUBLE)
	func=TOK___fixunsxfsi;
#అయితే_ముగింపు
    } లేకపోతే {
      r=fpr(gv(RC_FLOAT));
      r2=intr(vtop->r=get_reg(RC_INT));
      o(0xEE100170|(r2<<12)|r);
      తిరిగి;
    }
#అయితే_ముగింపు
  } లేకపోతే ఒకవేళ(t == VT_LLONG) { // unsigned handled in gen_cvt_ftoi1
    ఒకవేళ(r2 == VT_FLOAT)
      func=TOK___fixsfdi;
    లేకపోతే ఒకవేళ(r2 == VT_DOUBLE)
      func=TOK___fixdfdi;
#ఒకవేళ LDOUBLE_కొలత != 8
    లేకపోతే ఒకవేళ(r2 == VT_LDOUBLE)
      func=TOK___fixxfdi;
#అయితే_ముగింపు
  }
  ఒకవేళ(func) {
    vpush_helper_func(func);
    vswap();
    gfunc_call(1);
    vpushi(0);
    ఒకవేళ(t == VT_LLONG)
      vtop->r2 = REG_IRE2;
    vtop->r = REG_IRET;
    తిరిగి;
  }
  tcc_error("unimplemented gen_cvt_ftoi!");
}

/* convert from one floating point type to another */
శూన్య gen_cvt_ftof(పూర్ణాంకం t)
{
#నిర్వచితమైతే TCC_ARM_VFP
  uint32_t r = gv(RC_FLOAT);
  ఒకవేళ(((vtop->type.t & VT_BTYPE) == VT_FLOAT) != ((t & VT_BTYPE) == VT_FLOAT)) {
    r = vfpr(r);
    o(0xEEB70AC0|(r<<12)|r|T2CPR(vtop->type.t));
  }
#లేకపోతే
  /* all we have to do on i386 and FPA ARM is to put the float in a register */
  gv(RC_FLOAT);
#అయితే_ముగింపు
}

/* increment tcov counter */
ST_FUNC శూన్య gen_increment_tcov (SValue *sv)
{
  పూర్ణాంకం r1, r2;

  vpushv(sv);
  vtop->r = r1 = get_reg(RC_INT);
  r2 = get_reg(RC_INT);
  o(0xE59F0000 | (intr(r1)<<12)); // ldr r1,[pc]
  o(0xEA000000); // b $+4
  greloc(cur_పాఠ్యం_section, sv->sym, ind, R_ARM_REL32);
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
శూన్య ggoto(శూన్య)
{
  gcall_or_jmp(1);
  vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC శూన్య gen_vla_sp_save(పూర్ణాంకం addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    store(TREG_SP, &v);
}

/* Restore the SP from a location on the stack */
ST_FUNC శూన్య gen_vla_sp_restore(పూర్ణాంకం addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    ఎక్కించు(TREG_SP, &v);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC శూన్య gen_vla_alloc(CType *type, పూర్ణాంకం align) {
    పూర్ణాంకం r;
#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    ఒకవేళ (tcc_state->do_bounds_check)
        vpushv(vtop);
#అయితే_ముగింపు
    r = intr(gv(RC_INT));
#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    ఒకవేళ (tcc_state->do_bounds_check)
        o(0xe2800001 | (r<<16)|(r<<12)); /* add r,r,#1 */
#అయితే_ముగింపు
    o(0xE04D0000|(r<<12)|r); /* sub r, sp, r */
#నిర్వచితమైతే TCC_ARM_EABI
    ఒకవేళ (align < 8)
        align = 8;
#లేకపోతే
    ఒకవేళ (align < 4)
        align = 4;
#అయితే_ముగింపు
    ఒకవేళ (align & (align - 1))
        tcc_error("alignment is not a power of 2: %i", align);
    o(stuff_const(0xE3C0D000|(r<<16), align - 1)); /* bic sp, r, #align-1 */
    vpop();
#ఒకవేళ defined(CONFIG_TCC_BCHECK)
    ఒకవేళ (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R0;
        o(0xe1a0000d | (vtop->r << 12)); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_కూడు_epilog = 1;
    }
#అయితే_ముగింపు
}

/* end of ARM code generator */
/*************************************************************/
#అయితే_ముగింపు
/*************************************************************/
