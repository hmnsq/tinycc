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

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಗುರಿ_DEFS_ONLY

#ಆದರೆ defined(TCC_ARM_EABI) && !defined(TCC_ARM_VFP)
#ದೋಷ "Currently TinyCC only supports float computation with VFP instructions"
#ಆದರೆ_ಅಂತ್ಯ

/* number of available registers */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
#ವ್ಯಾಖ್ಯಾನಿಸು NB_REGS            13
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು NB_REGS             9
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_CPUVER
# define CONFIG_TCC_CPUVER 5
#ಆದರೆ_ಅಂತ್ಯ

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_INT     0x0001 /* generic integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FLOAT   0x0002 /* generic float register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R0      0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R1      0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R2      0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R3      0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು RC_R12     0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು RC_F0      0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು RC_F1      0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು RC_F2      0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು RC_F3      0x0400
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
#ವ್ಯಾಖ್ಯಾನಿಸು RC_F4      0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು RC_F5      0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_F6      0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_F7      0x4000
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು RC_IRET    RC_R0  /* function return: integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_IRE2    RC_R1  /* function return: second integer register */
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FRET    RC_F0  /* function return: float register */

/* pretty names for the registers */
ಎಣಿಕೆ {
    TREG_R0 = 0,
    TREG_R1,
    TREG_R2,
    TREG_R3,
    TREG_R12,
    TREG_F0,
    TREG_F1,
    TREG_F2,
    TREG_F3,
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
    TREG_F4,
    TREG_F5,
    TREG_F6,
    TREG_F7,
#ಆದರೆ_ಅಂತ್ಯ
    TREG_SP = 13,
    TREG_LR,
};

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
#ವ್ಯಾಖ್ಯಾನಿಸು T2CPR(t) (((t) & VT_BTYPE) != VT_FLOAT ? 0x100 : 0)
#ಆದರೆ_ಅಂತ್ಯ

/* return registers for function */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_IRET TREG_R0 /* single word int return register */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_IRE2 TREG_R1 /* second word return register (for long long) */
#ವ್ಯಾಖ್ಯಾನಿಸು REG_FRET TREG_F0 /* float return register */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
#ವ್ಯಾಖ್ಯಾನಿಸು TOK___divdi3 TOK___aeabi_ldivmod
#ವ್ಯಾಖ್ಯಾನಿಸು TOK___moddi3 TOK___aeabi_ldivmod
#ವ್ಯಾಖ್ಯಾನಿಸು TOK___udivdi3 TOK___aeabi_uldivmod
#ವ್ಯಾಖ್ಯಾನಿಸು TOK___umoddi3 TOK___aeabi_uldivmod
#ಆದರೆ_ಅಂತ್ಯ

/* defined if function parameters must be evaluated in reverse order */
#ವ್ಯಾಖ್ಯಾನಿಸು INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#ವ್ಯಾಖ್ಯಾನಿಸು PTR_ಗಾತ್ರ 4

/* long double size and alignment, in bytes */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ಗಾತ್ರ  8
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ LDOUBLE_ಗಾತ್ರ
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ಗಾತ್ರ  8
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ALIGN 8
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ALIGN 4
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ LDOUBLE_ಗಾತ್ರ == 8
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#ಆದರೆ_ಅಂತ್ಯ

/* maximum alignment (for aligned attribute support) */
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_ALIGN     8

#ವ್ಯಾಖ್ಯಾನಿಸು CHAR_IS_UNSIGNED

#ವ್ಯಾಖ್ಯಾನಿಸು ARM_SOFTFP_FLOAT 0
#ವ್ಯಾಖ್ಯಾನಿಸು ARM_HARD_FLOAT 1

/******************************************************/
#ಇಲ್ಲದಿದ್ದರೆ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ ಗುರಿ_machine_defs =
    "__arm__\0"
    "__arm\0"
    "arm\0"
    "__arm_elf__\0"
    "__arm_elf\0"
    "arm_elf\0"
    "__ARM_ARCH_4__\0"
    "__ARMEL__\0"
    "__APCS_32__\0"
#ಆದರೆ defined TCC_ARM_EABI
    "__ARM_EABI__\0"
#ಆದರೆ_ಅಂತ್ಯ
    ;

ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ reg_classes[NB_REGS] = {
    /* r0 */ RC_INT | RC_R0,
    /* r1 */ RC_INT | RC_R1,
    /* r2 */ RC_INT | RC_R2,
    /* r3 */ RC_INT | RC_R3,
    /* r12 */ RC_INT | RC_R12,
    /* f0 */ RC_FLOAT | RC_F0,
    /* f1 */ RC_FLOAT | RC_F1,
    /* f2 */ RC_FLOAT | RC_F2,
    /* f3 */ RC_FLOAT | RC_F3,
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
 /* d4/s8 */ RC_FLOAT | RC_F4,
/* d5/s10 */ RC_FLOAT | RC_F5,
/* d6/s12 */ RC_FLOAT | RC_F6,
/* d7/s14 */ RC_FLOAT | RC_F7,
#ಆದರೆ_ಅಂತ್ಯ
};

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ float_abi;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ func_sub_sp_ಸ್ಥಾನಾಂತರ, ಕೊನೆಯ_itod_magic;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ leaffunc;

#ಆದರೆ defined(CONFIG_TCC_BCHECK)
ಸ್ಥಿರ addr_t func_bound_ಸ್ಥಾನಾಂತರ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ func_bound_ind;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_bound_ಕೂಡಿಸು_epilog;
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
ಸ್ಥಿರ CType float_type, double_type, func_float_type, func_double_type;
ST_FUNC ಶೂನ್ಯ arm_init(ರಚನೆ TCCState *s)
{
    float_type.t = VT_FLOAT;
    double_type.t = VT_DOUBLE;
    func_float_type.t = VT_FUNC;
    func_float_type.ref = sym_ತಳ್ಳು(SYM_ಕ್ಷೇತ್ರ, &float_type, FUNC_CDECL, FUNC_OLD);
    func_double_type.t = VT_FUNC;
    func_double_type.ref = sym_ತಳ್ಳು(SYM_ಕ್ಷೇತ್ರ, &double_type, FUNC_CDECL, FUNC_OLD);

    float_abi = s->float_abi;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ARM_HARDFLOAT
// XXX: Works on OpenBSD
// # warning "soft float ABI currently not supported: default to softfp"
#ಆದರೆ_ಅಂತ್ಯ
}
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು func_float_type func_old_type
#ವ್ಯಾಖ್ಯಾನಿಸು func_double_type func_old_type
#ವ್ಯಾಖ್ಯಾನಿಸು func_ldouble_type func_old_type
ST_FUNC ಶೂನ್ಯ arm_init(ರಚನೆ TCCState *s)
{
#ಆದರೆ 0
#ಆದರೆ !defined (TCC_ARM_VFP)
    tcc_warning("Support for FPA is deprecated and will be removed in next"
                " release");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ !defined (TCC_ARM_EABI)
    tcc_warning("Support for OABI is deprecated and will be removed in next"
                " release");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
}
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು CHECK_R(r) ((r) >= TREG_R0 && (r) <= TREG_LR)

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ two2mask(ಪೂರ್ಣಾಂಕ a,ಪೂರ್ಣಾಂಕ b) {
  ಆದರೆ (!CHECK_R(a) || !CHECK_R(b))
    tcc_error("compiler error! registers %i,%i is not valid",a,b);
  ಹಿಂತಿರುಗಿ (reg_classes[a]|reg_classes[b])&~(RC_INT|RC_FLOAT);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ regmask(ಪೂರ್ಣಾಂಕ r) {
  ಆದರೆ (!CHECK_R(r))
    tcc_error("compiler error! register %i is not valid",r);
  ಹಿಂತಿರುಗಿ reg_classes[r]&~(RC_INT|RC_FLOAT);
}

/******************************************************/

ಶೂನ್ಯ o(uint32_t i)
{
  /* this is a good place to start adding big-endian support*/
  ಪೂರ್ಣಾಂಕ ind1;
  ಆದರೆ (nocode_wanted)
    ಹಿಂತಿರುಗಿ;
  ind1 = ind + 4;
  ಆದರೆ (!cur_ಪಠ್ಯ_section)
    tcc_error("compiler error! This happens f.ex. if the compiler\n"
         "can't evaluate constant expressions outside of a function.");
  ಆದರೆ (ind1 > cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_allocated)
    section_realloc(cur_ಪಠ್ಯ_section, ind1);
  cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = i&255;
  i>>=8;
  cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = i&255;
  i>>=8;
  cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = i&255;
  i>>=8;
  cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ[ind++] = i;
}

ಸ್ಥಿರ uint32_t stuff_const(uint32_t op, uint32_t c)
{
  ಪೂರ್ಣಾಂಕ try_neg=0;
  uint32_t nc = 0, negop = 0;

  ಆಯ್ಕೆ(op&0x1F00000)
  {
    ಸ್ಥಿತಿ 0x800000: //add
    ಸ್ಥಿತಿ 0x400000: //sub
      try_neg=1;
      negop=op^0xC00000;
      nc=-c;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 0x1A00000: //mov
    ಸ್ಥಿತಿ 0x1E00000: //mvn
      try_neg=1;
      negop=op^0x400000;
      nc=~c;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 0x200000: //xor
      ಆದರೆ(c==~0)
	ಹಿಂತಿರುಗಿ (op&0xF010F000)|((op>>16)&0xF)|0x1E00000;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 0x0: //and
      ಆದರೆ(c==~0)
	ಹಿಂತಿರುಗಿ (op&0xF010F000)|((op>>16)&0xF)|0x1A00000;
    ಸ್ಥಿತಿ 0x1C00000: //bic
      try_neg=1;
      negop=op^0x1C00000;
      nc=~c;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 0x1800000: //orr
      ಆದರೆ(c==~0)
	ಹಿಂತಿರುಗಿ (op&0xFFF0FFFF)|0x1E00000;
      ನಿಲ್ಲಿಸು;
  }
  ಮಾಡು {
    uint32_t m;
    ಪೂರ್ಣಾಂಕ i;
    ಆದರೆ(c<256) /* catch undefined <<32 */
      ಹಿಂತಿರುಗಿ op|c;
    ಗಾಗಿ(i=2;i<32;i+=2) {
      m=(0xffu>>i)|(0xffu<<(32-i));
      ಆದರೆ(!(c&~m))
	ಹಿಂತಿರುಗಿ op|(i<<7)|(c<<i)|(c>>(32-i));
    }
    op=negop;
    c=nc;
  } ಆಗ(try_neg--);
  ಹಿಂತಿರುಗಿ 0;
}


//only add,sub
ಶೂನ್ಯ stuff_const_harder(uint32_t op, uint32_t v) {
  uint32_t x;
  x=stuff_const(op,v);
  ಆದರೆ(x)
    o(x);
  ಇಲ್ಲದಿದ್ದರೆ {
    uint32_t a[16], nv, no, o2, n2;
    ಪೂರ್ಣಾಂಕ i,j,k;
    a[0]=0xff;
    o2=(op&0xfff0ffff)|((op&0xf000)<<4);;
    ಗಾಗಿ(i=1;i<16;i++)
      a[i]=(a[i-1]>>2)|(a[i-1]<<30);
    ಗಾಗಿ(i=0;i<12;i++)
      ಗಾಗಿ(j=i<4?i+12:15;j>=i+4;j--)
	ಆದರೆ((v&(a[i]|a[j]))==v) {
	  o(stuff_const(op,v&a[i]));
	  o(stuff_const(o2,v&a[j]));
	  ಹಿಂತಿರುಗಿ;
	}
    no=op^0xC00000;
    n2=o2^0xC00000;
    nv=-v;
    ಗಾಗಿ(i=0;i<12;i++)
      ಗಾಗಿ(j=i<4?i+12:15;j>=i+4;j--)
	ಆದರೆ((nv&(a[i]|a[j]))==nv) {
	  o(stuff_const(no,nv&a[i]));
	  o(stuff_const(n2,nv&a[j]));
	  ಹಿಂತಿರುಗಿ;
	}
    ಗಾಗಿ(i=0;i<8;i++)
      ಗಾಗಿ(j=i+4;j<12;j++)
	ಗಾಗಿ(k=i<4?i+12:15;k>=j+4;k--)
	  ಆದರೆ((v&(a[i]|a[j]|a[k]))==v) {
	    o(stuff_const(op,v&a[i]));
	    o(stuff_const(o2,v&a[j]));
	    o(stuff_const(o2,v&a[k]));
	    ಹಿಂತಿರುಗಿ;
	  }
    no=op^0xC00000;
    nv=-v;
    ಗಾಗಿ(i=0;i<8;i++)
      ಗಾಗಿ(j=i+4;j<12;j++)
	ಗಾಗಿ(k=i<4?i+12:15;k>=j+4;k--)
	  ಆದರೆ((nv&(a[i]|a[j]|a[k]))==nv) {
	    o(stuff_const(no,nv&a[i]));
	    o(stuff_const(n2,nv&a[j]));
	    o(stuff_const(n2,nv&a[k]));
	    ಹಿಂತಿರುಗಿ;
	  }
    o(stuff_const(op,v&a[0]));
    o(stuff_const(o2,v&a[4]));
    o(stuff_const(o2,v&a[8]));
    o(stuff_const(o2,v&a[12]));
  }
}

uint32_t encbranch(ಪೂರ್ಣಾಂಕ pos, ಪೂರ್ಣಾಂಕ addr, ಪೂರ್ಣಾಂಕ fail)
{
  addr-=pos+8;
  addr/=4;
  ಆದರೆ(addr>=0x1000000 || addr<-0x1000000) {
    ಆದರೆ(fail)
      tcc_error("FIXME: function bigger than 32MB");
    ಹಿಂತಿರುಗಿ 0;
  }
  ಹಿಂತಿರುಗಿ 0x0A000000|(addr&0xffffff);
}

ಪೂರ್ಣಾಂಕ decbranch(ಪೂರ್ಣಾಂಕ pos)
{
  ಪೂರ್ಣಾಂಕ x;
  x=*(uint32_t *)(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + pos);
  x&=0x00ffffff;
  ಆದರೆ(x&0x800000)
    x-=0x1000000;
  ಹಿಂತಿರುಗಿ x*4+pos+8;
}

/* output a symbol and patch all calls to it */
ಶೂನ್ಯ gsym_addr(ಪೂರ್ಣಾಂಕ t, ಪೂರ್ಣಾಂಕ a)
{
  uint32_t *x;
  ಪೂರ್ಣಾಂಕ lt;
  ಆಗ(t) {
    x=(uint32_t *)(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + t);
    t=decbranch(lt=t);
    ಆದರೆ(a==lt+4)
      *x=0xE1A00000; // nop
    ಇಲ್ಲದಿದ್ದರೆ {
      *x &= 0xff000000;
      *x |= encbranch(lt,a,1);
    }
  }
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
ಸ್ಥಿರ uint32_t vfpr(ಪೂರ್ಣಾಂಕ r)
{
  ಆದರೆ(r<TREG_F0 || r>TREG_F7)
    tcc_error("compiler error! register %i is no vfp register",r);
  ಹಿಂತಿರುಗಿ r - TREG_F0;
}
#ಇಲ್ಲದಿದ್ದರೆ
ಸ್ಥಿರ uint32_t fpr(ಪೂರ್ಣಾಂಕ r)
{
  ಆದರೆ(r<TREG_F0 || r>TREG_F3)
    tcc_error("compiler error! register %i is no fpa register",r);
  ಹಿಂತಿರುಗಿ r - TREG_F0;
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ uint32_t intr(ಪೂರ್ಣಾಂಕ r)
{
  ಆದರೆ(r == TREG_R12)
    ಹಿಂತಿರುಗಿ 12;
  ಆದರೆ(r >= TREG_R0 && r <= TREG_R3)
    ಹಿಂತಿರುಗಿ r - TREG_R0;
  ಆದರೆ (!(r >= TREG_SP && r <= TREG_LR))
    tcc_error("compiler error! register %i is no int register",r);
  ಹಿಂತಿರುಗಿ r + (13 - TREG_SP);
}

ಸ್ಥಿರ ಶೂನ್ಯ calcaddr(uint32_t *ತಳ, ಪೂರ್ಣಾಂಕ *off, ಪೂರ್ಣಾಂಕ *sgn, ಪೂರ್ಣಾಂಕ maxoff, ಚಿಹ್ನೆರಹಿತ ಸರಿಸು)
{
  ಆದರೆ(*off>maxoff || *off&((1<<ಸರಿಸು)-1)) {
    uint32_t x, y;
    x=0xE280E000;
    ಆದರೆ(*sgn)
      x=0xE240E000;
    x|=(*ತಳ)<<16;
    *ತಳ=14; // lr
    y=stuff_const(x,*off&~maxoff);
    ಆದರೆ(y) {
      o(y);
      *off&=maxoff;
      ಹಿಂತಿರುಗಿ;
    }
    y=stuff_const(x,(*off+maxoff)&~maxoff);
    ಆದರೆ(y) {
      o(y);
      *sgn=!*sgn;
      *off=((*off+maxoff)&~maxoff)-*off;
      ಹಿಂತಿರುಗಿ;
    }
    stuff_const_harder(x,*off&~maxoff);
    *off&=maxoff;
  }
}

ಸ್ಥಿರ uint32_t mapcc(ಪೂರ್ಣಾಂಕ cc)
{
  ಆಯ್ಕೆ(cc)
  {
    ಸ್ಥಿತಿ TOK_ULT:
      ಹಿಂತಿರುಗಿ 0x30000000; /* CC/LO */
    ಸ್ಥಿತಿ TOK_UGE:
      ಹಿಂತಿರುಗಿ 0x20000000; /* CS/HS */
    ಸ್ಥಿತಿ TOK_EQ:
      ಹಿಂತಿರುಗಿ 0x00000000; /* EQ */
    ಸ್ಥಿತಿ TOK_NE:
      ಹಿಂತಿರುಗಿ 0x10000000; /* NE */
    ಸ್ಥಿತಿ TOK_ULE:
      ಹಿಂತಿರುಗಿ 0x90000000; /* LS */
    ಸ್ಥಿತಿ TOK_UGT:
      ಹಿಂತಿರುಗಿ 0x80000000; /* HI */
    ಸ್ಥಿತಿ TOK_Nset:
      ಹಿಂತಿರುಗಿ 0x40000000; /* MI */
    ಸ್ಥಿತಿ TOK_Nclear:
      ಹಿಂತಿರುಗಿ 0x50000000; /* PL */
    ಸ್ಥಿತಿ TOK_LT:
      ಹಿಂತಿರುಗಿ 0xB0000000; /* LT */
    ಸ್ಥಿತಿ TOK_GE:
      ಹಿಂತಿರುಗಿ 0xA0000000; /* GE */
    ಸ್ಥಿತಿ TOK_LE:
      ಹಿಂತಿರುಗಿ 0xD0000000; /* LE */
    ಸ್ಥಿತಿ TOK_GT:
      ಹಿಂತಿರುಗಿ 0xC0000000; /* GT */
  }
  tcc_error("unexpected condition code");
  ಹಿಂತಿರುಗಿ 0xE0000000; /* AL */
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ negcc(ಪೂರ್ಣಾಂಕ cc)
{
  ಆಯ್ಕೆ(cc)
  {
    ಸ್ಥಿತಿ TOK_ULT:
      ಹಿಂತಿರುಗಿ TOK_UGE;
    ಸ್ಥಿತಿ TOK_UGE:
      ಹಿಂತಿರುಗಿ TOK_ULT;
    ಸ್ಥಿತಿ TOK_EQ:
      ಹಿಂತಿರುಗಿ TOK_NE;
    ಸ್ಥಿತಿ TOK_NE:
      ಹಿಂತಿರುಗಿ TOK_EQ;
    ಸ್ಥಿತಿ TOK_ULE:
      ಹಿಂತಿರುಗಿ TOK_UGT;
    ಸ್ಥಿತಿ TOK_UGT:
      ಹಿಂತಿರುಗಿ TOK_ULE;
    ಸ್ಥಿತಿ TOK_Nset:
      ಹಿಂತಿರುಗಿ TOK_Nclear;
    ಸ್ಥಿತಿ TOK_Nclear:
      ಹಿಂತಿರುಗಿ TOK_Nset;
    ಸ್ಥಿತಿ TOK_LT:
      ಹಿಂತಿರುಗಿ TOK_GE;
    ಸ್ಥಿತಿ TOK_GE:
      ಹಿಂತಿರುಗಿ TOK_LT;
    ಸ್ಥಿತಿ TOK_LE:
      ಹಿಂತಿರುಗಿ TOK_GT;
    ಸ್ಥಿತಿ TOK_GT:
      ಹಿಂತಿರುಗಿ TOK_LE;
  }
  tcc_error("unexpected condition code");
  ಹಿಂತಿರುಗಿ TOK_NE;
}

/* Load value into register r.
   Use relative/got addressing to avoid setting DT_TEXTREL */
ಸ್ಥಿರ ಶೂನ್ಯ ತುಂಬು_ಮೌಲ್ಯ(SValue *sv, ಪೂರ್ಣಾಂಕ r)
{
#ಆದರೆ CONFIG_TCC_CPUVER >= 7
    ಆದರೆ (!(sv->r & VT_SYM)) {
        ಚಿಹ್ನೆರಹಿತ x=sv->c.i;
        o(0xE3000000|intr(r)<<12|(x&0xFFF)|(x<<4&0xF0000)); /* movw rx,#x(lo) */
        ಆದರೆ (x&0xFFFF0000)
          o(0xE3400000|intr(r)<<12|(x>>16&0xFFF)|(x>>12&0xF0000)); /* movt rx,#x(hi) */
        ಹಿಂತಿರುಗಿ;
    }
#ಆದರೆ_ಅಂತ್ಯ
    o(0xE59F0000|(intr(r)<<12)); /* ldr r, [pc] */
    o(0xEA000000); /* b $+4 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_PIC
    ಆದರೆ(sv->r & VT_SYM)
        greloc(cur_ಪಠ್ಯ_section, sv->sym, ind, R_ARM_ABS32);
    o(sv->c.i);
#ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ(sv->r & VT_SYM) {
	ಆದರೆ (sv->sym->type.t & VT_STATIC) {
            greloc(cur_ಪಠ್ಯ_section, sv->sym, ind, R_ARM_REL32);
            o(sv->c.i - 12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
        }
        ಇಲ್ಲದಿದ್ದರೆ {
            greloc(cur_ಪಠ್ಯ_section, sv->sym, ind, R_ARM_GOT_PREL);
            o(-12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
            o(0xe5900000 | (intr(r)<<12) | (intr(r)<<16));  // ldr rx,[rx]
            ಆದರೆ (sv->c.i)
              stuff_const_harder(0xe2800000 | (intr(r)<<12) | (intr(r)<<16),
                                 sv->c.i);
        }
    }
    ಇಲ್ಲದಿದ್ದರೆ
        o(sv->c.i);
#ಆದರೆ_ಅಂತ್ಯ
}

/* load 'r' from value 'sv' */
ಶೂನ್ಯ ತುಂಬು(ಪೂರ್ಣಾಂಕ r, SValue *sv)
{
  ಪೂರ್ಣಾಂಕ v, ft, fc, fr, sign;
  uint32_t op, ತಳ;
  SValue v1;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  ಆದರೆ(fc>=0)
    sign=0;
  ಇಲ್ಲದಿದ್ದರೆ {
    sign=1;
    fc=-(ಚಿಹ್ನೆರಹಿತ)fc;
  }

  v = fr & VT_VALMASK;
  ಆದರೆ (fr & VT_LVAL) {

    ಆದರೆ ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe510e000; /* ldr r, [lr, #0] */
        greloca(cur_ಪಠ್ಯ_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        ಹಿಂತಿರುಗಿ;
    }

    ತಳ = 0xB; // fp
    ಆದರೆ(v == VT_LLOCAL) {
      v1.type.t = VT_PTR;
      v1.r = VT_LOCAL | VT_LVAL;
      v1.c.i = sv->c.i;
      ತುಂಬು(TREG_LR, &v1);
      ತಳ = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(v == VT_CONST) {
      v1.type.t = VT_PTR;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      ತುಂಬು(TREG_LR, &v1);
      ತಳ = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(v < VT_CONST) {
      ತಳ=intr(v);
      fc=sign=0;
      v=VT_LOCAL;
    }
    ಆದರೆ(v == VT_LOCAL) {
      ಆದರೆ(is_float(ft)) {
	calcaddr(&ತಳ,&fc,&sign,1020,2);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
        op=0xED100A00; /* flds */
        ಆದರೆ(!sign)
          op|=0x800000;
        ಆದರೆ ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* flds -> fldd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(ತಳ<<16));
#ಇಲ್ಲದಿದ್ದರೆ
	op=0xED100100;
	ಆದರೆ(!sign)
	  op|=0x800000;
	ಆದರೆ ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#ಆದರೆ LDOUBLE_ಗಾತ್ರ != 8
	ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#ಆದರೆ_ಅಂತ್ಯ
	o(op|(fpr(r)<<12)|(fc>>2)|(ತಳ<<16));
#ಆದರೆ_ಅಂತ್ಯ
      } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ((ft & (VT_BTYPE|VT_UNSIGNED)) == VT_BYTE
                || (ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&ತಳ,&fc,&sign,255,0);
	op=0xE1500090;
	ಆದರೆ ((ft & VT_BTYPE) == VT_SHORT)
	  op|=0x20;
	ಆದರೆ ((ft & VT_UNSIGNED) == 0)
	  op|=0x40;
	ಆದರೆ(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(ತಳ<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } ಇಲ್ಲದಿದ್ದರೆ {
	calcaddr(&ತಳ,&fc,&sign,4095,0);
	op=0xE5100000;
	ಆದರೆ(!sign)
	  op|=0x800000;
        ಆದರೆ ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(ತಳ<<16));
      }
      ಹಿಂತಿರುಗಿ;
    }
  } ಇಲ್ಲದಿದ್ದರೆ {
    ಆದರೆ (v == VT_CONST) {
      op=stuff_const(0xE3A00000|(intr(r)<<12),sv->c.i);
      ಆದರೆ (fr & VT_SYM || !op)
	ತುಂಬು_ಮೌಲ್ಯ(sv, r);
      ಇಲ್ಲದಿದ್ದರೆ
        o(op);
      ಹಿಂತಿರುಗಿ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_LOCAL) {
      op=stuff_const(0xE28B0000|(intr(r)<<12),sv->c.i);
      ಆದರೆ (fr & VT_SYM || !op) {
	ತುಂಬು_ಮೌಲ್ಯ(sv, r);
	o(0xE08B0000|(intr(r)<<12)|intr(r));
      } ಇಲ್ಲದಿದ್ದರೆ
	o(op);
      ಹಿಂತಿರುಗಿ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(v == VT_CMP) {
      o(mapcc(sv->c.i)|0x3A00001|(intr(r)<<12));
      o(mapcc(negcc(sv->c.i))|0x3A00000|(intr(r)<<12));
      ಹಿಂತಿರುಗಿ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == VT_JMP || v == VT_JMPI) {
      ಪೂರ್ಣಾಂಕ t;
      t = v & 1;
      o(0xE3A00000|(intr(r)<<12)|t);
      o(0xEA000000);
      gsym(sv->c.i);
      o(0xE3A00000|(intr(r)<<12)|(t^1));
      ಹಿಂತಿರುಗಿ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v < VT_CONST) {
      ಆದರೆ(is_float(ft))
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
        o(0xEEB00A40|(vfpr(r)<<12)|vfpr(v)|T2CPR(ft)); /* fcpyX */
#ಇಲ್ಲದಿದ್ದರೆ
	o(0xEE008180|(fpr(r)<<12)|fpr(v));
#ಆದರೆ_ಅಂತ್ಯ
      ಇಲ್ಲದಿದ್ದರೆ
	o(0xE1A00000|(intr(r)<<12)|intr(v));
      ಹಿಂತಿರುಗಿ;
    }
  }
  tcc_error("load unimplemented!");
}

/* store register 'r' in lvalue 'v' */
ಶೂನ್ಯ store(ಪೂರ್ಣಾಂಕ r, SValue *sv)
{
  SValue v1;
  ಪೂರ್ಣಾಂಕ v, ft, fc, fr, sign;
  uint32_t op, ತಳ;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  ಆದರೆ(fc>=0)
    sign=0;
  ಇಲ್ಲದಿದ್ದರೆ {
    sign=1;
    fc=-fc;
  }

  v = fr & VT_VALMASK;
  ಆದರೆ (fr & VT_LVAL || fr == VT_LOCAL) {

    ಆದರೆ ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe500e000; /* str r, [lr, #0] */
        greloca(cur_ಪಠ್ಯ_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        ಹಿಂತಿರುಗಿ;
    }

    ತಳ = 0xb; /* fp */
    ಆದರೆ(v < VT_CONST) {
      ತಳ=intr(v);
      v=VT_LOCAL;
      fc=sign=0;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(v == VT_CONST) {
      v1.type.t = ft;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      ತುಂಬು(TREG_LR, &v1);
      ತಳ = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    }
    ಆದರೆ(v == VT_LOCAL) {
       ಆದರೆ(is_float(ft)) {
	calcaddr(&ತಳ,&fc,&sign,1020,2);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
        op=0xED000A00; /* fsts */
        ಆದರೆ(!sign)
          op|=0x800000;
        ಆದರೆ ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* fsts -> fstd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(ತಳ<<16));
#ಇಲ್ಲದಿದ್ದರೆ
	op=0xED000100;
	ಆದರೆ(!sign)
	  op|=0x800000;
	ಆದರೆ ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#ಆದರೆ LDOUBLE_ಗಾತ್ರ != 8
	ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#ಆದರೆ_ಅಂತ್ಯ
	o(op|(fpr(r)<<12)|(fc>>2)|(ತಳ<<16));
#ಆದರೆ_ಅಂತ್ಯ
	ಹಿಂತಿರುಗಿ;
      } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ((ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&ತಳ,&fc,&sign,255,0);
	op=0xE14000B0;
	ಆದರೆ(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(ತಳ<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } ಇಲ್ಲದಿದ್ದರೆ {
	calcaddr(&ತಳ,&fc,&sign,4095,0);
	op=0xE5000000;
	ಆದರೆ(!sign)
	  op|=0x800000;
        ಆದರೆ ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(ತಳ<<16));
      }
      ಹಿಂತಿರುಗಿ;
    }
  }
  tcc_error("store unimplemented");
}

ಸ್ಥಿರ ಶೂನ್ಯ gadd_sp(ಪೂರ್ಣಾಂಕ val)
{
  stuff_const_harder(0xE28DD000,val);
}

/* 'is_jmp' is '1' if it is a jump */
ಸ್ಥಿರ ಶೂನ್ಯ gcall_or_jmp(ಪೂರ್ಣಾಂಕ is_jmp)
{
  ಪೂರ್ಣಾಂಕ r;
  uint32_t x;
  ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
    /* constant case */
    ಆದರೆ(vtop->r & VT_SYM){
	x=encbranch(ind,ind+vtop->c.i,0);
	ಆದರೆ(x) {
	    /* relocation case */
	    greloc(cur_ಪಠ್ಯ_section, vtop->sym, ind, R_ARM_PC24);
	    o(x|(is_jmp?0xE0000000:0xE1000000));
	} ಇಲ್ಲದಿದ್ದರೆ {
	    r = TREG_LR;
	    ತುಂಬು_ಮೌಲ್ಯ(vtop, r);
	    ಆದರೆ(is_jmp)
	        o(0xE1A0F000 | intr(r)); // mov pc, r
	    ಇಲ್ಲದಿದ್ದರೆ
		o(0xe12fff30 | intr(r)); // blx r
	}
     }ಇಲ್ಲದಿದ್ದರೆ{
	ಆದರೆ(!is_jmp)
	    o(0xE28FE004); // add lr,pc,#4
	o(0xE51FF004);   // ldr pc,[pc,#-4]
	o(vtop->c.i);
     }
  } ಇಲ್ಲದಿದ್ದರೆ {
    /* otherwise, indirect call */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    vtop->r &= ~VT_MUSTBOUND;
#ಆದರೆ_ಅಂತ್ಯ
    r = gv(RC_INT);
    ಆದರೆ(!is_jmp)
      o(0xE1A0E00F);       // mov lr,pc
    o(0xE1A0F000|intr(r)); // mov pc,r
  }
}

#ಆದರೆ defined(CONFIG_TCC_BCHECK)

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_call(ಪೂರ್ಣಾಂಕ v)
{
    Sym *sym = external_helper_sym(v);

    greloc(cur_ಪಠ್ಯ_section, sym, ind, R_ARM_PC24);
    o(0xebfffffe);
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_prolog(ಶೂನ್ಯ)
{
    /* leave some room for bound checking code */
    func_bound_ಸ್ಥಾನಾಂತರ = lbounds_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    func_bound_ind = ind;
    func_bound_ಕೂಡಿಸು_epilog = 0;
    o(0xe1a00000);  /* ld r0,lbounds_section->data_offset */
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);  /* call __bound_local_new */
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_bounds_epilog(ಶೂನ್ಯ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ದತ್ತಾಂಶ;
    ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ_modified = func_bound_ಸ್ಥಾನಾಂತರ != lbounds_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    ಆದರೆ (!ಸ್ಥಾನಾಂತರ_modified && !func_bound_ಕೂಡಿಸು_epilog)
        ಹಿಂತಿರುಗಿ;

    /* add end of table info */
    bounds_ptr = section_ptr_ಕೂಡಿಸು(lbounds_section, ಗಾತ್ರ(addr_t));
    *bounds_ptr = 0;

    sym_ದತ್ತಾಂಶ = get_sym_ref(&char_ಸೂಚಕ_type, lbounds_section,
                           func_bound_ಸ್ಥಾನಾಂತರ, PTR_ಗಾತ್ರ);

    /* generate bound local allocation */
    ಆದರೆ (ಸ್ಥಾನಾಂತರ_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        o(0xe59f0000);  /* ldr r0, [pc] */
        o(0xea000000);  /* b $+4 */
        greloc(cur_ಪಠ್ಯ_section, sym_ದತ್ತಾಂಶ, ind, R_ARM_REL32);
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
    greloc(cur_ಪಠ್ಯ_section, sym_ದತ್ತಾಂಶ, ind, R_ARM_REL32);
    o(-12);  /* lbounds_section->data_offset */
    o(0xe080000f);  /* add r0,r0,pc */
    gen_bounds_call(TOK___bound_local_delete);
    o(0xecbd0b04); /* vpop {d0,d1} */
    o(0xe8bd0003); /* pop {r0,r1} */
}
#ಆದರೆ_ಅಂತ್ಯ

/* Return whether a structure is an homogeneous float aggregate or not.
   The answer is true if all the elements of the structure are of the same
   primitive float type and there is less than 4 elements.

   type: the type corresponding to the structure to be tested */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_hgen_float_aggr(CType *type)
{
  ಆದರೆ ((type->t & VT_BTYPE) == VT_STRUCT) {
    ರಚನೆ Sym *ref;
    ಪೂರ್ಣಾಂಕ btype, nb_fields = 0;

    ref = type->ref->ಮುಂದಿನ;
    ಆದರೆ (ref) {
      btype = ref->type.t & VT_BTYPE;
      ಆದರೆ (btype == VT_FLOAT || btype == VT_DOUBLE) {
        ಗಾಗಿ(; ref && btype == (ref->type.t & VT_BTYPE); ref = ref->ಮುಂದಿನ, nb_fields++)
            ;
        ಹಿಂತಿರುಗಿ !ref && nb_fields <= 4;
      }
    }
  }
  ಹಿಂತಿರುಗಿ 0;
}

ರಚನೆ avail_regs {
  ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ avail[3]; /* 3 holes max with only float and double alignments */
  ಪೂರ್ಣಾಂಕ ಮೊದಲ_hole; /* first available hole */
  ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_hole; /* last available hole (none if equal to first_hole) */
  ಪೂರ್ಣಾಂಕ ಮೊದಲ_free_reg; /* next free register in the sequence, hole excluded */
};

/* Find suitable registers for a VFP Co-Processor Register Candidate (VFP CPRC
   param) according to the rules described in the procedure call standard for
   the ARM architecture (AAPCS). If found, the registers are assigned to this
   VFP CPRC parameter. Registers are allocated in sequence unless a hole exists
   and the parameter is a single float.

   avregs: opaque structure to keep track of available VFP co-processor regs
   align: alignment constraints for the param, as returned by type_size()
   size: size of the parameter, as returned by type_size() */
ಪೂರ್ಣಾಂಕ ನಿಯೋಜಿಸು_vfpreg(ರಚನೆ avail_regs *avregs, ಪೂರ್ಣಾಂಕ align, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
  ಪೂರ್ಣಾಂಕ ಮೊದಲ_reg = 0;

  ಆದರೆ (avregs->ಮೊದಲ_free_reg == -1)
    ಹಿಂತಿರುಗಿ -1;
  ಆದರೆ (align >> 3) { /* double alignment */
    ಮೊದಲ_reg = avregs->ಮೊದಲ_free_reg;
    /* alignment constraint not respected so use next reg and record hole */
    ಆದರೆ (ಮೊದಲ_reg & 1)
      avregs->avail[avregs->ಕೊನೆಯ_hole++] = ಮೊದಲ_reg++;
  } ಇಲ್ಲದಿದ್ದರೆ { /* no special alignment (float or array of float) */
    /* if single float and a hole is available, assign the param to it */
    ಆದರೆ (ಗಾತ್ರ_2 == 4 && avregs->ಮೊದಲ_hole != avregs->ಕೊನೆಯ_hole)
      ಹಿಂತಿರುಗಿ avregs->avail[avregs->ಮೊದಲ_hole++];
    ಇಲ್ಲದಿದ್ದರೆ
      ಮೊದಲ_reg = avregs->ಮೊದಲ_free_reg;
  }
  ಆದರೆ (ಮೊದಲ_reg + ಗಾತ್ರ_2 / 4 <= 16) {
    avregs->ಮೊದಲ_free_reg = ಮೊದಲ_reg + ಗಾತ್ರ_2 / 4;
    ಹಿಂತಿರುಗಿ ಮೊದಲ_reg;
  }
  avregs->ಮೊದಲ_free_reg = -1;
  ಹಿಂತಿರುಗಿ -1;
}

/* Returns whether all params need to be passed in core registers or not.
   This is the case for function part of the runtime ABI. */
ಪೂರ್ಣಾಂಕ floats_ಒಳ_core_regs(SValue *sval)
{
  ಆದರೆ (!sval->sym)
    ಹಿಂತಿರುಗಿ 0;

  ಆಯ್ಕೆ (sval->sym->v) {
    ಸ್ಥಿತಿ TOK___floatundisf:
    ಸ್ಥಿತಿ TOK___floatundidf:
    ಸ್ಥಿತಿ TOK___fixunssfdi:
    ಸ್ಥಿತಿ TOK___fixunsdfdi:
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ARM_VFP
    ಸ್ಥಿತಿ TOK___fixunsxfdi:
#ಆದರೆ_ಅಂತ್ಯ
    ಸ್ಥಿತಿ TOK___floatdisf:
    ಸ್ಥಿತಿ TOK___floatdidf:
    ಸ್ಥಿತಿ TOK___fixsfdi:
    ಸ್ಥಿತಿ TOK___fixdfdi:
      ಹಿಂತಿರುಗಿ 1;

    ಪೂರ್ವನಿಯೋಜಿತ:
      ಹಿಂತಿರುಗಿ 0;
  }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ಪೂರ್ಣಾಂಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಂಕ variadic, CType *ret, ಪೂರ್ಣಾಂಕ *ret_align, ಪೂರ್ಣಾಂಕ *regsize) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align;
    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(vt, &align);
    ಆದರೆ (float_abi == ARM_HARD_FLOAT && !variadic &&
        (is_float(vt->t) || is_hgen_float_aggr(vt))) {
        *ret_align = 8;
	*regsize = 8;
        ret->ref = ಖಾಲಿ;
        ret->t = VT_DOUBLE;
        ಹಿಂತಿರುಗಿ (ಗಾತ್ರ_2 + 7) >> 3;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2 > 0 && ಗಾತ್ರ_2 <= 4) {
        *ret_align = 4;
	*regsize = 4;
        ret->ref = ಖಾಲಿ;
        ret->t = VT_INT;
        ಹಿಂತಿರುಗಿ 1;
    } ಇಲ್ಲದಿದ್ದರೆ
        ಹಿಂತಿರುಗಿ 0;
#ಇಲ್ಲದಿದ್ದರೆ
    ಹಿಂತಿರುಗಿ 0;
#ಆದರೆ_ಅಂತ್ಯ
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
ಎಣಿಕೆ reg_class {
	ರಾಶಿ_CLASS = 0,
	CORE_STRUCT_CLASS,
	VFP_CLASS,
	VFP_STRUCT_CLASS,
	CORE_CLASS,
	NB_CLASSES
};

ರಚನೆ param_plan {
    ಪೂರ್ಣಾಂಕ ಆರಂಭ; /* first reg or addr used depending on the class */
    ಪೂರ್ಣಾಂಕ ಕೊನೆ; /* last reg used or next free addr depending on the class */
    SValue *sval; /* pointer to SValue on the value stack */
    ರಚನೆ param_plan *prev; /*  previous element in this class */
};

ರಚನೆ plan {
    ರಚನೆ param_plan *pplans; /* array of all the param plans */
    ರಚನೆ param_plan *clsplans[NB_CLASSES]; /* per class lists of param plans */
    ಪೂರ್ಣಾಂಕ nb_plans;
};

ಸ್ಥಿರ ಶೂನ್ಯ ಕೂಡಿಸು_param_plan(ರಚನೆ plan* plan, ಪೂರ್ಣಾಂಕ cls, ಪೂರ್ಣಾಂಕ ಆರಂಭ, ಪೂರ್ಣಾಂಕ ಕೊನೆ, SValue *v)
{
    ರಚನೆ param_plan *p = &plan->pplans[plan->nb_plans++];
    p->prev = plan->clsplans[cls];
    plan->clsplans[cls] = p;
    p->ಆರಂಭ = ಆರಂಭ, p->ಕೊನೆ = ಕೊನೆ, p->sval = v;
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
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ನಿಯೋಜಿಸು_regs(ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು, ಪೂರ್ಣಾಂಕ float_abi, ರಚನೆ plan *plan, ಪೂರ್ಣಾಂಕ *todo)
{
  ಪೂರ್ಣಾಂಕ i, ಗಾತ್ರ_2, align;
  ಪೂರ್ಣಾಂಕ ncrn /* next core register number */, nsaa /* next stacked argument address*/;
  ರಚನೆ avail_regs avregs = {{0}};

  ncrn = nsaa = 0;
  *todo = 0;

  ಗಾಗಿ(i = nb_ವಾದಗಳು; i-- ;) {
    ಪೂರ್ಣಾಂಕ j, ಆರಂಭ_vfpreg = 0;
    CType type = vtop[-i].type;
    type.t &= ~VT_ARRAY;
    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&type, &align);
    ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 3) & ~3;
    align = (align + 3) & ~3;
    ಆಯ್ಕೆ(vtop[-i].type.t & VT_BTYPE) {
      ಸ್ಥಿತಿ VT_STRUCT:
      ಸ್ಥಿತಿ VT_FLOAT:
      ಸ್ಥಿತಿ VT_DOUBLE:
      ಸ್ಥಿತಿ VT_LDOUBLE:
      ಆದರೆ (float_abi == ARM_HARD_FLOAT) {
        ಪೂರ್ಣಾಂಕ is_hfa = 0; /* Homogeneous float aggregate */

        ಆದರೆ (is_float(vtop[-i].type.t)
            || (is_hfa = is_hgen_float_aggr(&vtop[-i].type))) {
          ಪೂರ್ಣಾಂಕ ಕೊನೆ_vfpreg;

          ಆರಂಭ_vfpreg = ನಿಯೋಜಿಸು_vfpreg(&avregs, align, ಗಾತ್ರ_2);
          ಕೊನೆ_vfpreg = ಆರಂಭ_vfpreg + ((ಗಾತ್ರ_2 - 1) >> 2);
          ಆದರೆ (ಆರಂಭ_vfpreg >= 0) {
            ಕೂಡಿಸು_param_plan(plan, is_hfa ? VFP_STRUCT_CLASS : VFP_CLASS,
                ಆರಂಭ_vfpreg, ಕೊನೆ_vfpreg, &vtop[-i]);
            ಮುಂದುವರಿ;
          } ಇಲ್ಲದಿದ್ದರೆ
            ನಿಲ್ಲಿಸು;
        }
      }
      ncrn = (ncrn + (align-1)/4) & ~((align/4) - 1);
      ಆದರೆ (ncrn + ಗಾತ್ರ_2/4 <= 4 || (ncrn < 4 && ಆರಂಭ_vfpreg != -1)) {
        /* The parameter is allocated both in core register and on stack. As
	 * such, it can be of either class: it would either be the last of
	 * CORE_STRUCT_CLASS or the first of STACK_CLASS. */
        ಗಾಗಿ (j = ncrn; j < 4 && j < ncrn + ಗಾತ್ರ_2 / 4; j++)
          *todo|=(1<<j);
        ಕೂಡಿಸು_param_plan(plan, CORE_STRUCT_CLASS, ncrn, j, &vtop[-i]);
        ncrn += ಗಾತ್ರ_2/4;
        ಆದರೆ (ncrn > 4)
          nsaa = (ncrn - 4) * 4;
      } ಇಲ್ಲದಿದ್ದರೆ {
        ncrn = 4;
        ನಿಲ್ಲಿಸು;
      }
      ಮುಂದುವರಿ;
      ಪೂರ್ವನಿಯೋಜಿತ:
      ಆದರೆ (ncrn < 4) {
        ಪೂರ್ಣಾಂಕ is_long = (vtop[-i].type.t & VT_BTYPE) == VT_LLONG;

        ಆದರೆ (is_long) {
          ncrn = (ncrn + 1) & -2;
          ಆದರೆ (ncrn == 4)
            ನಿಲ್ಲಿಸು;
        }
        ಕೂಡಿಸು_param_plan(plan, CORE_CLASS, ncrn, ncrn + is_long, &vtop[-i]);
        ncrn += 1 + is_long;
        ಮುಂದುವರಿ;
      }
    }
    nsaa = (nsaa + (align - 1)) & ~(align - 1);
    ಕೂಡಿಸು_param_plan(plan, ರಾಶಿ_CLASS, nsaa, nsaa + ಗಾತ್ರ_2, &vtop[-i]);
    nsaa += ಗಾತ್ರ_2; /* size already rounded up before */
  }
  ಹಿಂತಿರುಗಿ nsaa;
}

/* Copy parameters to their final destination (core reg, VFP reg or stack) for
   function call.

   nb_args: number of parameters the function take
   plan: the overall assignment plan for parameters
   todo: a bitmap indicating what core reg will hold a parameter

   Returns the number of SValue added by this function on the value stack */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ copy_params(ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು, ರಚನೆ plan *plan, ಪೂರ್ಣಾಂಕ todo)
{
  ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, r, i, nb_extra_sval = 0;
  ರಚನೆ param_plan *pplan;
  ಪೂರ್ಣಾಂಕ pass = 0;

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
  ಗಾಗಿ(i = 0; i < NB_CLASSES; i++) {
    ಗಾಗಿ(pplan = plan->clsplans[i]; pplan; pplan = pplan->prev) {

      ಆದರೆ (pass
          && (i != CORE_CLASS || pplan->sval->r < VT_CONST))
        ಮುಂದುವರಿ;

      vpushv(pplan->sval);
      pplan->sval->r = pplan->sval->r2 = VT_CONST; /* disable entry */
      ಆಯ್ಕೆ(i) {
        ಸ್ಥಿತಿ ರಾಶಿ_CLASS:
        ಸ್ಥಿತಿ CORE_STRUCT_CLASS:
        ಸ್ಥಿತಿ VFP_STRUCT_CLASS:
          ಆದರೆ ((pplan->sval->type.t & VT_BTYPE) == VT_STRUCT) {
            ಪೂರ್ಣಾಂಕ padding = 0;
            ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&pplan->sval->type, &align);
            /* align to stack align size */
            ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 3) & ~3;
            ಆದರೆ (i == ರಾಶಿ_CLASS && pplan->prev)
              padding = pplan->ಆರಂಭ - pplan->prev->ಕೊನೆ;
            ಗಾತ್ರ_2 += padding; /* Add padding if any */
            /* allocate the necessary size on stack */
            gadd_sp(-ಗಾತ್ರ_2);
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
            ಆದರೆ (i == VFP_STRUCT_CLASS) {
              ಪೂರ್ಣಾಂಕ ಮೊದಲ = pplan->ಆರಂಭ, nb = pplan->ಕೊನೆ - ಮೊದಲ + 1;
              /* vpop.32 {pplan->start, ..., pplan->end} */
              o(0xECBD0A00|(ಮೊದಲ&1)<<22|(ಮೊದಲ>>1)<<12|nb);
              /* No need to write the register used to a SValue since VFP regs
                 cannot be used for gcall_or_jmp */
            }
          } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (is_float(pplan->sval->type.t)) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
              r = vfpr(gv(RC_FLOAT)) << 12;
              ಆದರೆ ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                ಗಾತ್ರ_2 = 4;
              ಇಲ್ಲದಿದ್ದರೆ {
                ಗಾತ್ರ_2 = 8;
                r |= 0x101; /* vpush.32 -> vpush.64 */
              }
              o(0xED2D0A01 + r); /* vpush */
#ಇಲ್ಲದಿದ್ದರೆ
              r = fpr(gv(RC_FLOAT)) << 12;
              ಆದರೆ ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                ಗಾತ್ರ_2 = 4;
              ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((pplan->sval->type.t & VT_BTYPE) == VT_DOUBLE)
                ಗಾತ್ರ_2 = 8;
              ಇಲ್ಲದಿದ್ದರೆ
                ಗಾತ್ರ_2 = LDOUBLE_ಗಾತ್ರ;
              ಆದರೆ (ಗಾತ್ರ_2 == 12)
                r |= 0x400000;
              ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(ಗಾತ್ರ_2 == 8)
                r|=0x8000;

              o(0xED2D0100|r|(ಗಾತ್ರ_2>>2)); /* some kind of vpush for FPA */
#ಆದರೆ_ಅಂತ್ಯ
            } ಇಲ್ಲದಿದ್ದರೆ {
              /* simple type (currently always same size) */
              /* XXX: implicit cast ? */
              ಗಾತ್ರ_2=4;
              ಆದರೆ ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
                lexpand();
                ಗಾತ್ರ_2 = 8;
                r = gv(RC_INT);
                o(0xE52D0004|(intr(r)<<12)); /* push r */
                vtop--;
              }
              r = gv(RC_INT);
              o(0xE52D0004|(intr(r)<<12)); /* push r */
            }
            ಆದರೆ (i == ರಾಶಿ_CLASS && pplan->prev)
              gadd_sp(pplan->prev->ಕೊನೆ - pplan->ಆರಂಭ); /* Add padding if any */
          }
          ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ VFP_CLASS:
          gv(regmask(TREG_F0 + (pplan->ಆರಂಭ >> 1)));
          ಆದರೆ (pplan->ಆರಂಭ & 1) { /* Must be in upper part of double register */
            o(0xEEF00A40|((pplan->ಆರಂಭ>>1)<<12)|(pplan->ಆರಂಭ>>1)); /* vmov.f32 s(n+1), sn */
            vtop->r = VT_CONST; /* avoid being saved on stack by gv for next float */
          }
          ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ CORE_CLASS:
          ಆದರೆ ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
            lexpand();
            gv(regmask(pplan->ಕೊನೆ));
            pplan->sval->r2 = vtop->r;
            vtop--;
          }
          gv(regmask(pplan->ಆರಂಭ));
          /* Mark register as used so that gcall_or_jmp use another one
             (regs >=4 are free as never used to pass parameters) */
          pplan->sval->r = vtop->r;
          ನಿಲ್ಲಿಸು;
      }
      vtop--;
    }
  }

  /* second pass to restore registers that were saved on stack by accident.
     Maybe redundant after the "lvalue_save" patch in tccgen.c:gv() */
  ಆದರೆ (++pass < 2)
    ಹೋಗು again;

  ಆದರೆ(todo) {
    o(0xE8BD0000|todo); /* pop {todo} */
    ಗಾಗಿ(pplan = plan->clsplans[CORE_STRUCT_CLASS]; pplan; pplan = pplan->prev) {
      ಪೂರ್ಣಾಂಕ r;
      pplan->sval->r = pplan->ಆರಂಭ;
      /* An SValue can only pin 2 registers at best (r and r2) but a structure
         can occupy more than 2 registers. Thus, we need to push on the value
         stack some fake parameter to have on SValue for each registers used
         by a structure (r2 is not used). */
      ಗಾಗಿ (r = pplan->ಆರಂಭ + 1; r <= pplan->ಕೊನೆ; r++) {
        ಆದರೆ (todo & (1 << r)) {
          nb_extra_sval++;
          vpushi(0);
          vtop->r = r;
        }
      }
    }
  }
  ಹಿಂತಿರುಗಿ nb_extra_sval;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು)
{
  ಪೂರ್ಣಾಂಕ ವಾದಗಳು_ಗಾತ್ರ;
  ಪೂರ್ಣಾಂಕ def_float_abi = float_abi;
  ಪೂರ್ಣಾಂಕ todo;
  ರಚನೆ plan plan;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
  ಪೂರ್ಣಾಂಕ variadic;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
  ಆದರೆ (tcc_state->do_bounds_check)
    gbound_ವಾದಗಳು(nb_ವಾದಗಳು);
#ಆದರೆ_ಅಂತ್ಯ

  save_regs(nb_ವಾದಗಳು + 1);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
  ಆದರೆ (float_abi == ARM_HARD_FLOAT) {
    variadic = (vtop[-nb_ವಾದಗಳು].type.ref->f.func_type == FUNC_ELLIPSIS);
    ಆದರೆ (variadic || floats_ಒಳ_core_regs(&vtop[-nb_ವಾದಗಳು]))
      float_abi = ARM_SOFTFP_FLOAT;
  }
#ಆದರೆ_ಅಂತ್ಯ

  memset(&plan, 0, ಗಾತ್ರ plan);
  ಆದರೆ (nb_ವಾದಗಳು)
    plan.pplans = tcc_malloc(nb_ವಾದಗಳು * ಗಾತ್ರ(*plan.pplans));

  ವಾದಗಳು_ಗಾತ್ರ = ನಿಯೋಜಿಸು_regs(nb_ವಾದಗಳು, float_abi, &plan, &todo);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
  ಆದರೆ (ವಾದಗಳು_ಗಾತ್ರ & 7) { /* Stack must be 8 byte aligned at fct call for EABI */
    ವಾದಗಳು_ಗಾತ್ರ = (ವಾದಗಳು_ಗಾತ್ರ + 7) & ~7;
    o(0xE24DD004); /* sub sp, sp, #4 */
  }
#ಆದರೆ_ಅಂತ್ಯ

  nb_ವಾದಗಳು += copy_params(nb_ವಾದಗಳು, &plan, todo);
  tcc_free(plan.pplans);

  /* Move fct SValue on top as required by gcall_or_jmp */
  vrotb(nb_ವಾದಗಳು + 1);
  gcall_or_jmp(0);
  ಆದರೆ (ವಾದಗಳು_ಗಾತ್ರ)
      gadd_sp(ವಾದಗಳು_ಗಾತ್ರ); /* pop all parameters passed on the stack */
#ಆದರೆ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  ಆದರೆ(float_abi == ARM_SOFTFP_FLOAT && is_float(vtop->type.ref->type.t)) {
    ಆದರೆ((vtop->type.ref->type.t & VT_BTYPE) == VT_FLOAT) {
      o(0xEE000A10); /*vmov s0, r0 */
    } ಇಲ್ಲದಿದ್ದರೆ {
      o(0xEE000B10); /* vmov.32 d0[0], r0 */
      o(0xEE201B10); /* vmov.32 d0[1], r1 */
    }
  }
#ಆದರೆ_ಅಂತ್ಯ
  vtop -= nb_ವಾದಗಳು + 1; /* Pop all params and fct address from value stack */
  leaffunc = 0; /* we are calling a function, so we aren't in a leaf function */
  float_abi = def_float_abi;
}

/* generate function prolog of type 't' */
ಶೂನ್ಯ gfunc_prolog(Sym *func_sym)
{
  CType *func_type = &func_sym->type;
  Sym *sym,*sym2;
  ಪೂರ್ಣಾಂಕ n, nf, ಗಾತ್ರ_2, align, rs, struct_ret = 0;
  ಪೂರ್ಣಾಂಕ addr, pn, sn; /* pn=core, sn=stack */
  CType ret_type;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
  ರಚನೆ avail_regs avregs = {{0}};
#ಆದರೆ_ಅಂತ್ಯ

  sym = func_type->ref;

  n = nf = 0;
  ಆದರೆ ((func_vt.t & VT_BTYPE) == VT_STRUCT &&
      !gfunc_sret(&func_vt, func_var, &ret_type, &align, &rs))
  {
    n++;
    struct_ret = 1;
    func_vc = 12; /* Offset from fp of the place to store the result */
  }
  ಗಾಗಿ(sym2 = sym->ಮುಂದಿನ; sym2 && (n < 4 || nf < 16); sym2 = sym2->ಮುಂದಿನ) {
    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&sym2->type, &align);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
    ಆದರೆ (float_abi == ARM_HARD_FLOAT && !func_var &&
        (is_float(sym2->type.t) || is_hgen_float_aggr(&sym2->type))) {
      ಪೂರ್ಣಾಂಕ tmpnf = ನಿಯೋಜಿಸು_vfpreg(&avregs, align, ಗಾತ್ರ_2);
      tmpnf += (ಗಾತ್ರ_2 + 3) / 4;
      nf = (tmpnf > nf) ? tmpnf : nf;
    } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (n < 4)
      n += (ಗಾತ್ರ_2 + 3) / 4;
  }
  o(0xE1A0C00D); /* mov ip,sp */
  ಆದರೆ (func_var)
    n=4;
  ಆದರೆ (n) {
    ಆದರೆ(n>4)
      n=4;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
    n=(n+1)&-2;
#ಆದರೆ_ಅಂತ್ಯ
    o(0xE92D0000|((1<<n)-1)); /* save r0-r4 on stack if needed */
  }
  ಆದರೆ (nf) {
    ಆದರೆ (nf>16)
      nf=16;
    nf=(nf+1)&-2; /* nf => HARDFLOAT => EABI */
    o(0xED2D0A00|nf); /* save s0-s15 on stack if needed */
  }
  o(0xE92D5800); /* save fp, ip, lr */
  o(0xE1A0B00D); /* mov fp, sp */
  func_sub_sp_ಸ್ಥಾನಾಂತರ = ind;
  o(0xE1A00000); /* nop, leave space for stack adjustment in epilog */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
  ಆದರೆ (float_abi == ARM_HARD_FLOAT) {
    func_vc += nf * 4;
    memset(&avregs, 0, ಗಾತ್ರ avregs);
  }
#ಆದರೆ_ಅಂತ್ಯ
  pn = struct_ret, sn = 0;
  ಆಗ ((sym = sym->ಮುಂದಿನ)) {
    CType *type;
    type = &sym->type;
    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(type, &align);
    ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + 3) >> 2;
    align = (align + 3) & ~3;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
    ಆದರೆ (float_abi == ARM_HARD_FLOAT && !func_var && (is_float(sym->type.t)
        || is_hgen_float_aggr(&sym->type))) {
      ಪೂರ್ಣಾಂಕ fpn = ನಿಯೋಜಿಸು_vfpreg(&avregs, align, ಗಾತ್ರ_2 << 2);
      ಆದರೆ (fpn >= 0)
        addr = fpn * 4;
      ಇಲ್ಲದಿದ್ದರೆ
        ಹೋಗು from_ರಾಶಿ;
    } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (pn < 4) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
        pn = (pn + (align-1)/4) & -(align/4);
#ಆದರೆ_ಅಂತ್ಯ
      addr = (nf + pn) * 4;
      pn += ಗಾತ್ರ_2;
      ಆದರೆ (!sn && pn > 4)
        sn = (pn - 4);
    } ಇಲ್ಲದಿದ್ದರೆ {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
from_ರಾಶಿ:
        sn = (sn + (align-1)/4) & -(align/4);
#ಆದರೆ_ಅಂತ್ಯ
      addr = (n + nf + sn) * 4;
      sn += ಗಾತ್ರ_2;
    }
    gfunc_ಗಣ_param(sym, addr + 12, 0);
  }
  ಕೊನೆಯ_itod_magic=0;
  leaffunc = 1;
  loc = 0;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
  ಆದರೆ (tcc_state->do_bounds_check)
    gen_bounds_prolog();
#ಆದರೆ_ಅಂತ್ಯ
}

/* generate function epilog */
ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ)
{
  uint32_t x;
  ಪೂರ್ಣಾಂಕ diff;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
  ಆದರೆ (tcc_state->do_bounds_check)
    gen_bounds_epilog();
#ಆದರೆ_ಅಂತ್ಯ
  /* Copy float return value to core register if base standard is used and
     float computation is made with VFP */
#ಆದರೆ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  ಆದರೆ ((float_abi == ARM_SOFTFP_FLOAT || func_var) && is_float(func_vt.t)) {
    ಆದರೆ((func_vt.t & VT_BTYPE) == VT_FLOAT)
      o(0xEE100A10); /* fmrs r0, s0 */
    ಇಲ್ಲದಿದ್ದರೆ {
      o(0xEE100B10); /* fmrdl r0, d0 */
      o(0xEE301B10); /* fmrdh r1, d0 */
    }
  }
#ಆದರೆ_ಅಂತ್ಯ
  o(0xE89BA800); /* restore fp, sp, pc */
  diff = (-loc + 3) & -4;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
  ಆದರೆ(!leaffunc)
    diff = ((diff + 11) & -8) - 4;
#ಆದರೆ_ಅಂತ್ಯ
  ಆದರೆ(diff > 0) {
    x=stuff_const(0xE24BD000, diff); /* sub sp,fp,# */
    ಆದರೆ(x)
      *(uint32_t *)(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + func_sub_sp_ಸ್ಥಾನಾಂತರ) = x;
    ಇಲ್ಲದಿದ್ದರೆ {
      ಪೂರ್ಣಾಂಕ addr;
      addr=ind;
      o(0xE59FC004); /* ldr ip,[pc+4] */
      o(0xE04BD00C); /* sub sp,fp,ip  */
      o(0xE1A0F00E); /* mov pc,lr */
      o(diff);
      *(uint32_t *)(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + func_sub_sp_ಸ್ಥಾನಾಂತರ) = 0xE1000000|encbranch(func_sub_sp_ಸ್ಥಾನಾಂತರ,addr,1);
    }
  }
}

ST_FUNC ಶೂನ್ಯ gen_fill_nops(ಪೂರ್ಣಾಂಕ ಬೈಟುಗಳು)
{
    ಆದರೆ ((ಬೈಟುಗಳು & 3))
      tcc_error("alignment of code section not multiple of 4");
    ಆಗ (ಬೈಟುಗಳು > 0) {
	o(0xE1A00000);
	ಬೈಟುಗಳು -= 4;
    }
}

/* generate a jump to a label */
ST_FUNC ಪೂರ್ಣಾಂಕ gjmp(ಪೂರ್ಣಾಂಕ t)
{
  ಪೂರ್ಣಾಂಕ r;
  ಆದರೆ (nocode_wanted)
    ಹಿಂತಿರುಗಿ t;
  r=ind;
  o(0xE0000000|encbranch(r,t,1));
  ಹಿಂತಿರುಗಿ r;
}

/* generate a jump to a fixed address */
ST_FUNC ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಂಕ a)
{
  gjmp(a);
}

ST_FUNC ಪೂರ್ಣಾಂಕ gjmp_cond(ಪೂರ್ಣಾಂಕ op, ಪೂರ್ಣಾಂಕ t)
{
  ಪೂರ್ಣಾಂಕ r;
  ಆದರೆ (nocode_wanted)
    ಹಿಂತಿರುಗಿ t;
  r=ind;
  op=mapcc(op);
  op|=encbranch(r,t,1);
  o(op);
  ಹಿಂತಿರುಗಿ r;
}

ST_FUNC ಪೂರ್ಣಾಂಕ gjmp_append(ಪೂರ್ಣಾಂಕ n, ಪೂರ್ಣಾಂಕ t)
{
  uint32_t *x;
  ಪೂರ್ಣಾಂಕ p,lp;
  ಆದರೆ(n) {
    p = n;
    ಮಾಡು {
      p = decbranch(lp=p);
    } ಆಗ(p);
    x = (uint32_t *)(cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ + lp);
    *x &= 0xff000000;
    *x |= encbranch(lp,t,1);
    t = n;
  }
  ಹಿಂತಿರುಗಿ t;
}

/* generate an integer binary operation */
ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಂಕ op)
{
  ಪೂರ್ಣಾಂಕ c, func = 0;
  uint32_t opc = 0, r, fr;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ retreg = REG_IRET;

  c=0;
  ಆಯ್ಕೆ(op) {
    ಸ್ಥಿತಿ '+':
      opc = 0x8;
      c=1;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ADDC1: /* add with carry generation */
      opc = 0x9;
      c=1;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '-':
      opc = 0x4;
      c=1;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SUBC1: /* sub with carry generation */
      opc = 0x5;
      c=1;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ADDC2: /* add with carry use */
      opc = 0xA;
      c=1;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SUBC2: /* sub with carry use */
      opc = 0xC;
      c=1;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '&':
      opc = 0x0;
      c=1;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '^':
      opc = 0x2;
      c=1;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '|':
      opc = 0x18;
      c=1;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '*':
      gv2(RC_INT, RC_INT);
      r = vtop[-1].r;
      fr = vtop[0].r;
      vtop--;
      o(0xE0000090|(intr(r)<<16)|(intr(r)<<8)|intr(fr));
      ಹಿಂತಿರುಗಿ;
    ಸ್ಥಿತಿ TOK_SHL:
      opc = 0;
      c=2;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SHR:
      opc = 1;
      c=2;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SAR:
      opc = 2;
      c=2;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '/':
    ಸ್ಥಿತಿ TOK_PDIV:
      func=TOK___divsi3;
      c=3;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_UDIV:
      func=TOK___udivsi3;
      c=3;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '%':
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
      func=TOK___aeabi_idivmod;
      retreg=REG_IRE2;
#ಇಲ್ಲದಿದ್ದರೆ
      func=TOK___modsi3;
#ಆದರೆ_ಅಂತ್ಯ
      c=3;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_UMOD:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
      func=TOK___aeabi_uidivmod;
      retreg=REG_IRE2;
#ಇಲ್ಲದಿದ್ದರೆ
      func=TOK___umodsi3;
#ಆದರೆ_ಅಂತ್ಯ
      c=3;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_UMULL:
      gv2(RC_INT, RC_INT);
      r=intr(vtop[-1].r2=get_reg(RC_INT));
      c=vtop[-1].r;
      vtop[-1].r=get_reg_ex(RC_INT,regmask(c));
      vtop--;
      o(0xE0800090|(r<<16)|(intr(vtop->r)<<12)|(intr(c)<<8)|intr(vtop[1].r));
      ಹಿಂತಿರುಗಿ;
    ಪೂರ್ವನಿಯೋಜಿತ:
      opc = 0x15;
      c=1;
      ನಿಲ್ಲಿಸು;
  }
  ಆಯ್ಕೆ(c) {
    ಸ್ಥಿತಿ 1:
      ಆದರೆ((vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	ಆದರೆ(opc == 4 || opc == 5 || opc == 0xc) {
	  vswap();
	  opc|=2; // sub -> rsb
	}
      }
      vswap();
      c=intr(gv(RC_INT));
      vswap();
      opc=0xE0000000|(opc<<20);
      ಆದರೆ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	uint32_t x;
	x=stuff_const(opc|0x2000000|(c<<16),vtop->c.i);
	ಆದರೆ(x) {
	  ಆದರೆ ((x & 0xfff00000) == 0xe3500000)   // cmp rx,#c
	    o(x);
	  ಇಲ್ಲದಿದ್ದರೆ {
	    r=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	    o(x|(r<<12));
	  }
	  ಹೋಗು ಮುಗಿದ;
	}
      }
      fr=intr(gv(RC_INT));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
      ಆದರೆ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
        vswap();
        c=intr(gv(RC_INT));
        vswap();
      }
#ಆದರೆ_ಅಂತ್ಯ
      ಆದರೆ ((opc & 0xfff00000) == 0xe1500000) // cmp rx,ry
	o(opc|(c<<16)|fr);
      ಇಲ್ಲದಿದ್ದರೆ {
        r=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
        o(opc|(c<<16)|(r<<12)|fr);
      }
ಮುಗಿದ:
      vtop--;
      ಆದರೆ (op >= TOK_ULT && op <= TOK_GT)
        vset_VT_CMP(op);
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 2:
      opc=0xE1A00000|(opc<<5);
      vswap();
      r=intr(gv(RC_INT));
      vswap();
      ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	fr=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	c = vtop->c.i & 0x1f;
	o(opc|r|(c<<7)|(fr<<12));
      } ಇಲ್ಲದಿದ್ದರೆ {
        fr=intr(gv(RC_INT));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=intr(gv(RC_INT));
          vswap();
        }
#ಆದರೆ_ಅಂತ್ಯ
	c=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
	o(opc|r|(c<<12)|(fr<<8)|0x10);
      }
      vtop--;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 3:
      vpush_helper_func(func);
      vrott(3);
      gfunc_call(2);
      vpushi(0);
      vtop->r = retreg;
      ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
      tcc_error("gen_opi %i unimplemented!",op);
  }
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_zero(ಪೂರ್ಣಾಂಕ i)
{
  ಆದರೆ((vtop[i].r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    ಹಿಂತಿರುಗಿ 0;
  ಆದರೆ (vtop[i].type.t == VT_FLOAT)
    ಹಿಂತಿರುಗಿ (vtop[i].c.f == 0.f);
  ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (vtop[i].type.t == VT_DOUBLE)
    ಹಿಂತಿರುಗಿ (vtop[i].c.d == 0.0);
  ಹಿಂತಿರುಗಿ (vtop[i].c.ld == 0.l);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
 *    two operands are guaranteed to have the same floating point type */
ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಂಕ op)
{
  uint32_t x;
  ಪೂರ್ಣಾಂಕ fneg=0,r;
  x=0xEE000A00|T2CPR(vtop->type.t);
  ಆಯ್ಕೆ(op) {
    ಸ್ಥಿತಿ '+':
      ಆದರೆ(is_zero(-1))
        vswap();
      ಆದರೆ(is_zero(0)) {
        vtop--;
        ಹಿಂತಿರುಗಿ;
      }
      x|=0x300000;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '-':
      x|=0x300040;
      ಆದರೆ(is_zero(0)) {
        vtop--;
        ಹಿಂತಿರುಗಿ;
      }
      ಆದರೆ(is_zero(-1)) {
        x|=0x810000; /* fsubX -> fnegX */
        vswap();
        vtop--;
        fneg=1;
      }
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '*':
      x|=0x200000;
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '/':
      x|=0x800000;
      ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
      ಆದರೆ(op < TOK_ULT || op > TOK_GT) {
        tcc_error("unknown fp op %x!",op);
        ಹಿಂತಿರುಗಿ;
      }
      ಆದರೆ(is_zero(-1)) {
        vswap();
        ಆಯ್ಕೆ(op) {
          ಸ್ಥಿತಿ TOK_LT: op=TOK_GT; ನಿಲ್ಲಿಸು;
          ಸ್ಥಿತಿ TOK_GE: op=TOK_ULE; ನಿಲ್ಲಿಸು;
          ಸ್ಥಿತಿ TOK_LE: op=TOK_GE; ನಿಲ್ಲಿಸು;
          ಸ್ಥಿತಿ TOK_GT: op=TOK_ULT; ನಿಲ್ಲಿಸು;
        }
      }
      x|=0xB40040; /* fcmpX */
      ಆದರೆ(op!=TOK_EQ && op!=TOK_NE)
        x|=0x80; /* fcmpX -> fcmpeX */
      ಆದರೆ(is_zero(0)) {
        vtop--;
        o(x|0x10000|(vfpr(gv(RC_FLOAT))<<12)); /* fcmp(e)X -> fcmp(e)zX */
      } ಇಲ್ಲದಿದ್ದರೆ {
        gv2(RC_FLOAT,RC_FLOAT);
        x|=vfpr(vtop[0].r);
        o(x|(vfpr(vtop[-1].r) << 12));
        vtop--;
      }
      o(0xEEF1FA10); /* fmstat */

      ಆಯ್ಕೆ(op) {
        ಸ್ಥಿತಿ TOK_LE: op=TOK_ULE; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_LT: op=TOK_ULT; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_UGE: op=TOK_GE; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_UGT: op=TOK_GT; ನಿಲ್ಲಿಸು;
      }
      vset_VT_CMP(op);
      ಹಿಂತಿರುಗಿ;
  }
  r=gv(RC_FLOAT);
  x|=vfpr(r);
  r=regmask(r);
  ಆದರೆ(!fneg) {
    ಪೂರ್ಣಾಂಕ r2;
    vswap();
    r2=gv(RC_FLOAT);
    x|=vfpr(r2)<<16;
    r|=regmask(r2);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
      vswap();
      r=gv(RC_FLOAT);
      vswap();
      x=(x&~0xf)|vfpr(r);
    }
#ಆದರೆ_ಅಂತ್ಯ
  }
  vtop->r=get_reg_ex(RC_FLOAT,r);
  ಆದರೆ(!fneg)
    vtop--;
  o(x|(vfpr(vtop->r)<<12));
}

#ಇಲ್ಲದಿದ್ದರೆ
ಸ್ಥಿರ uint32_t is_fconst()
{
  ದೀರ್ಘ ದ್ವಿಗುಣ f;
  uint32_t r;
  ಆದರೆ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    ಹಿಂತಿರುಗಿ 0;
  ಆದರೆ (vtop->type.t == VT_FLOAT)
    f = vtop->c.f;
  ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (vtop->type.t == VT_DOUBLE)
    f = vtop->c.d;
  ಇಲ್ಲದಿದ್ದರೆ
    f = vtop->c.ld;
  ಆದರೆ(!ieee_finite(f))
    ಹಿಂತಿರುಗಿ 0;
  r=0x8;
  ಆದರೆ(f<0.0) {
    r=0x18;
    f=-f;
  }
  ಆದರೆ(f==0.0)
    ಹಿಂತಿರುಗಿ r;
  ಆದರೆ(f==1.0)
    ಹಿಂತಿರುಗಿ r|1;
  ಆದರೆ(f==2.0)
    ಹಿಂತಿರುಗಿ r|2;
  ಆದರೆ(f==3.0)
    ಹಿಂತಿರುಗಿ r|3;
  ಆದರೆ(f==4.0)
    ಹಿಂತಿರುಗಿ r|4;
  ಆದರೆ(f==5.0)
    ಹಿಂತಿರುಗಿ r|5;
  ಆದರೆ(f==0.5)
    ಹಿಂತಿರುಗಿ r|6;
  ಆದರೆ(f==10.0)
    ಹಿಂತಿರುಗಿ r|7;
  ಹಿಂತಿರುಗಿ 0;
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಂಕ op)
{
  uint32_t x, r, r2, c1, c2;
  //fputs("gen_opf\n",stderr);
  vswap();
  c1 = is_fconst();
  vswap();
  c2 = is_fconst();
  x=0xEE000100;
  ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
    x|=0x80;
#ಆದರೆ LDOUBLE_ಗಾತ್ರ != 8
  ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE)
    x|=0x80000;
#ಆದರೆ_ಅಂತ್ಯ

  ಆಯ್ಕೆ(op)
  {
    ಸ್ಥಿತಿ '+':
      ಆದರೆ(!c2) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      ಆದರೆ(c2) {
	ಆದರೆ(c2>0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
      } ಇಲ್ಲದಿದ್ದರೆ {
	r2=fpr(gv(RC_FLOAT));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#ಆದರೆ_ಅಂತ್ಯ
      }
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '-':
      ಆದರೆ(c2) {
	ಆದರೆ(c2<=0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(c1 && c1<=0xf) {
	x|=0x300000; // rsf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ಇಲ್ಲದಿದ್ದರೆ {
	x|=0x200000; // suf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#ಆದರೆ_ಅಂತ್ಯ
      }
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '*':
      ಆದರೆ(!c2 || c2>0xf) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      ಆದರೆ(c2 && c2<=0xf)
	r2=c2;
      ಇಲ್ಲದಿದ್ದರೆ {
	r2=fpr(gv(RC_FLOAT));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#ಆದರೆ_ಅಂತ್ಯ
      }
      x|=0x100000; // muf
      ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '/':
      ಆದರೆ(c2 && c2<=0xf) {
	x|=0x400000; // dvf
	r2=c2;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(c1 && c1<=0xf) {
	x|=0x500000; // rdf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ಇಲ್ಲದಿದ್ದರೆ {
	x|=0x400000; // dvf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#ಆದರೆ_ಅಂತ್ಯ
      }
      ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
      ಆದರೆ(op >= TOK_ULT && op <= TOK_GT) {
	x|=0xd0f110; // cmfe
/* bug (intention?) in Linux FPU emulator
   doesn't set carry if equal */
	ಆಯ್ಕೆ(op) {
	  ಸ್ಥಿತಿ TOK_ULT:
	  ಸ್ಥಿತಿ TOK_UGE:
	  ಸ್ಥಿತಿ TOK_ULE:
	  ಸ್ಥಿತಿ TOK_UGT:
            tcc_error("unsigned comparison on floats?");
	    ನಿಲ್ಲಿಸು;
	  ಸ್ಥಿತಿ TOK_LT:
            op=TOK_Nset;
	    ನಿಲ್ಲಿಸು;
	  ಸ್ಥಿತಿ TOK_LE:
            op=TOK_ULE; /* correct in unordered case only if AC bit in FPSR set */
	    ನಿಲ್ಲಿಸು;
	  ಸ್ಥಿತಿ TOK_EQ:
	  ಸ್ಥಿತಿ TOK_NE:
	    x&=~0x400000; // cmfe -> cmf
	    ನಿಲ್ಲಿಸು;
	}
	ಆದರೆ(c1 && !c2) {
	  c2=c1;
	  vswap();
	  ಆಯ್ಕೆ(op) {
            ಸ್ಥಿತಿ TOK_Nset:
              op=TOK_GT;
	      ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_GE:
	      op=TOK_ULE;
	      ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ TOK_ULE:
              op=TOK_GE;
	      ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_GT:
              op=TOK_Nset;
	      ನಿಲ್ಲಿಸು;
	  }
	}
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	ಆದರೆ(c2) {
	  ಆದರೆ(c2>0xf)
	    x|=0x200000;
	  r2=c2&0xf;
	} ಇಲ್ಲದಿದ್ದರೆ {
	  r2=fpr(gv(RC_FLOAT));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
          ಆದರೆ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            r=fpr(gv(RC_FLOAT));
            vswap();
          }
#ಆದರೆ_ಅಂತ್ಯ
	}
        --vtop;
        vset_VT_CMP(op);
        ++vtop;
      } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_error("unknown fp op %x!",op);
	ಹಿಂತಿರುಗಿ;
      }
  }
  ಆದರೆ(vtop[-1].r == VT_CMP)
    c1=15;
  ಇಲ್ಲದಿದ್ದರೆ {
    c1=vtop->r;
    ಆದರೆ(r2&0x8)
      c1=vtop[-1].r;
    vtop[-1].r=get_reg_ex(RC_FLOAT,two2mask(vtop[-1].r,c1));
    c1=fpr(vtop[-1].r);
  }
  vtop--;
  o(x|(r<<16)|(c1<<12)|r2);
}
#ಆದರೆ_ಅಂತ್ಯ

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ST_FUNC ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಂಕ t)
{
  uint32_t r, r2;
  ಪೂರ್ಣಾಂಕ bt;
  bt=vtop->type.t & VT_BTYPE;
  ಆದರೆ(bt == VT_INT || bt == VT_SHORT || bt == VT_BYTE) {
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ARM_VFP
    uint32_t dsize = 0;
#ಆದರೆ_ಅಂತ್ಯ
    r=intr(gv(RC_INT));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
    r2=vfpr(vtop->r=get_reg(RC_FLOAT));
    o(0xEE000A10|(r<<12)|(r2<<16)); /* fmsr */
    r2|=r2<<12;
    ಆದರೆ(!(vtop->type.t & VT_UNSIGNED))
      r2|=0x80;                /* fuitoX -> fsituX */
    o(0xEEB80A40|r2|T2CPR(t)); /* fYitoX*/
#ಇಲ್ಲದಿದ್ದರೆ
    r2=fpr(vtop->r=get_reg(RC_FLOAT));
    ಆದರೆ((t & VT_BTYPE) != VT_FLOAT)
      dsize=0x80;    /* flts -> fltd */
    o(0xEE000110|dsize|(r2<<16)|(r<<12)); /* flts */
    ಆದರೆ((vtop->type.t & (VT_UNSIGNED|VT_BTYPE)) == (VT_UNSIGNED|VT_INT)) {
      uint32_t off = 0;
      o(0xE3500000|(r<<12));        /* cmp */
      r=fpr(get_reg(RC_FLOAT));
      ಆದರೆ(ಕೊನೆಯ_itod_magic) {
	off=ind+8-ಕೊನೆಯ_itod_magic;
	off/=4;
	ಆದರೆ(off>255)
	  off=0;
      }
      o(0xBD1F0100|(r<<12)|off);    /* ldflts */
      ಆದರೆ(!off) {
        o(0xEA000000);              /* b */
        ಕೊನೆಯ_itod_magic=ind;
        o(0x4F800000);              /* 4294967296.0f */
      }
      o(0xBE000100|dsize|(r2<<16)|(r2<<12)|r); /* adflt */
    }
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ;
  } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(bt == VT_LLONG) {
    ಪೂರ್ಣಾಂಕ func;
    CType *func_type = 0;
    ಆದರೆ((t & VT_BTYPE) == VT_FLOAT) {
      func_type = &func_float_type;
      ಆದರೆ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundisf;
      ಇಲ್ಲದಿದ್ದರೆ
        func=TOK___floatdisf;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ((t & VT_BTYPE) == VT_DOUBLE) {
      func_type = &func_double_type;
      ಆದರೆ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundidf;
      ಇಲ್ಲದಿದ್ದರೆ
        func=TOK___floatdidf;
#ಆದರೆ LDOUBLE_ಗಾತ್ರ != 8
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ((t & VT_BTYPE) == VT_LDOUBLE) {
      func_type = &func_ldouble_type;
      ಆದರೆ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundixf;
      ಇಲ್ಲದಿದ್ದರೆ
        func=TOK___floatdixf;
#ಆದರೆ_ಅಂತ್ಯ
    }
    ಆದರೆ(func_type) {
      vpushsym(func_type, external_helper_sym(func));
      vswap();
      gfunc_call(1);
      vpushi(0);
      vtop->r=TREG_F0;
      ಹಿಂತಿರುಗಿ;
    }
  }
  tcc_error("unimplemented gen_cvt_itof %x!",vtop->type.t);
}

/* convert fp to int 't' type */
ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಂಕ t)
{
  uint32_t r, r2;
  ಪೂರ್ಣಾಂಕ u, func = 0;
  u=t&VT_UNSIGNED;
  t&=VT_BTYPE;
  r2=vtop->type.t & VT_BTYPE;
  ಆದರೆ(t==VT_INT) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
    r=vfpr(gv(RC_FLOAT));
    u=u?0:0x10000;
    o(0xEEBC0AC0|(r<<12)|r|T2CPR(r2)|u); /* ftoXizY */
    r2=intr(vtop->r=get_reg(RC_INT));
    o(0xEE100A10|(r<<16)|(r2<<12));
    ಹಿಂತಿರುಗಿ;
#ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ(u) {
      ಆದರೆ(r2 == VT_FLOAT)
        func=TOK___fixunssfsi;
      ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(r2 == VT_DOUBLE)
	func=TOK___fixunsdfsi;
#ಆದರೆ LDOUBLE_ಗಾತ್ರ != 8
      ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(r2 == VT_LDOUBLE)
	func=TOK___fixunsxfsi;
#ಆದರೆ_ಅಂತ್ಯ
    } ಇಲ್ಲದಿದ್ದರೆ {
      r=fpr(gv(RC_FLOAT));
      r2=intr(vtop->r=get_reg(RC_INT));
      o(0xEE100170|(r2<<12)|r);
      ಹಿಂತಿರುಗಿ;
    }
#ಆದರೆ_ಅಂತ್ಯ
  } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(t == VT_LLONG) { // unsigned handled in gen_cvt_ftoi1
    ಆದರೆ(r2 == VT_FLOAT)
      func=TOK___fixsfdi;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(r2 == VT_DOUBLE)
      func=TOK___fixdfdi;
#ಆದರೆ LDOUBLE_ಗಾತ್ರ != 8
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(r2 == VT_LDOUBLE)
      func=TOK___fixxfdi;
#ಆದರೆ_ಅಂತ್ಯ
  }
  ಆದರೆ(func) {
    vpush_helper_func(func);
    vswap();
    gfunc_call(1);
    vpushi(0);
    ಆದರೆ(t == VT_LLONG)
      vtop->r2 = REG_IRE2;
    vtop->r = REG_IRET;
    ಹಿಂತಿರುಗಿ;
  }
  tcc_error("unimplemented gen_cvt_ftoi!");
}

/* convert from one floating point type to another */
ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಂಕ t)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_VFP
  uint32_t r = gv(RC_FLOAT);
  ಆದರೆ(((vtop->type.t & VT_BTYPE) == VT_FLOAT) != ((t & VT_BTYPE) == VT_FLOAT)) {
    r = vfpr(r);
    o(0xEEB70AC0|(r<<12)|r|T2CPR(vtop->type.t));
  }
#ಇಲ್ಲದಿದ್ದರೆ
  /* all we have to do on i386 and FPA ARM is to put the float in a register */
  gv(RC_FLOAT);
#ಆದರೆ_ಅಂತ್ಯ
}

/* increment tcov counter */
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv)
{
  ಪೂರ್ಣಾಂಕ r1, r2;

  vpushv(sv);
  vtop->r = r1 = get_reg(RC_INT);
  r2 = get_reg(RC_INT);
  o(0xE59F0000 | (intr(r1)<<12)); // ldr r1,[pc]
  o(0xEA000000); // b $+4
  greloc(cur_ಪಠ್ಯ_section, sv->sym, ind, R_ARM_REL32);
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
ಶೂನ್ಯ ggoto(ಶೂನ್ಯ)
{
  gcall_or_jmp(1);
  vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC ಶೂನ್ಯ gen_vla_sp_save(ಪೂರ್ಣಾಂಕ addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    store(TREG_SP, &v);
}

/* Restore the SP from a location on the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_sp_restore(ಪೂರ್ಣಾಂಕ addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    ತುಂಬು(TREG_SP, &v);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC ಶೂನ್ಯ gen_vla_alloc(CType *type, ಪೂರ್ಣಾಂಕ align) {
    ಪೂರ್ಣಾಂಕ r;
#ಆದರೆ defined(CONFIG_TCC_BCHECK)
    ಆದರೆ (tcc_state->do_bounds_check)
        vpushv(vtop);
#ಆದರೆ_ಅಂತ್ಯ
    r = intr(gv(RC_INT));
#ಆದರೆ defined(CONFIG_TCC_BCHECK)
    ಆದರೆ (tcc_state->do_bounds_check)
        o(0xe2800001 | (r<<16)|(r<<12)); /* add r,r,#1 */
#ಆದರೆ_ಅಂತ್ಯ
    o(0xE04D0000|(r<<12)|r); /* sub r, sp, r */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
    ಆದರೆ (align < 8)
        align = 8;
#ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ (align < 4)
        align = 4;
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (align & (align - 1))
        tcc_error("alignment is not a power of 2: %i", align);
    o(stuff_const(0xE3C0D000|(r<<16), align - 1)); /* bic sp, r, #align-1 */
    vpop();
#ಆದರೆ defined(CONFIG_TCC_BCHECK)
    ಆದರೆ (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R0;
        o(0xe1a0000d | (vtop->r << 12)); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_ಕೂಡಿಸು_epilog = 1;
    }
#ಆದರೆ_ಅಂತ್ಯ
}

/* end of ARM code generator */
/*************************************************************/
#ಆದರೆ_ಅಂತ್ಯ
/*************************************************************/
