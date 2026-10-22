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

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

#ਜੇ defined(TCC_ARM_EABI) && !defined(TCC_ARM_VFP)
#ਗਲਤੀ "Currently TinyCC only supports float computation with VFP instructions"
#ਜੇ_ਅੰਤ

/* number of available registers */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_REGS            13
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_REGS             9
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_CPUVER
# define CONFIG_TCC_CPUVER 5
#ਜੇ_ਅੰਤ

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_INT     0x0001 /* generic integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FLOAT   0x0002 /* generic float register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R0      0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R1      0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R2      0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R3      0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_R12     0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_F0      0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_F1      0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_F2      0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_F3      0x0400
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_F4      0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_F5      0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_F6      0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_F7      0x4000
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_IRET    RC_R0  /* function return: integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_IRE2    RC_R1  /* function return: second integer register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FRET    RC_F0  /* function return: float register */

/* pretty names for the registers */
ਗਿਣਤੀ {
    TREG_R0 = 0,
    TREG_R1,
    TREG_R2,
    TREG_R3,
    TREG_R12,
    TREG_F0,
    TREG_F1,
    TREG_F2,
    TREG_F3,
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
    TREG_F4,
    TREG_F5,
    TREG_F6,
    TREG_F7,
#ਜੇ_ਅੰਤ
    TREG_SP = 13,
    TREG_LR,
};

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ T2CPR(t) (((t) & VT_BTYPE) != VT_FLOAT ? 0x100 : 0)
#ਜੇ_ਅੰਤ

/* return registers for function */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IRET TREG_R0 /* single word int return register */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_IRE2 TREG_R1 /* second word return register (for long long) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_FRET TREG_F0 /* float return register */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK___divdi3 TOK___aeabi_ldivmod
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK___moddi3 TOK___aeabi_ldivmod
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK___udivdi3 TOK___aeabi_uldivmod
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK___umoddi3 TOK___aeabi_uldivmod
#ਜੇ_ਅੰਤ

/* defined if function parameters must be evaluated in reverse order */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTR_ਮਾਪ 4

/* long double size and alignment, in bytes */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ਮਾਪ  8
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ LDOUBLE_ਮਾਪ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ਮਾਪ  8
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ALIGN 8
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ALIGN 4
#ਜੇ_ਅੰਤ

#ਜੇ LDOUBLE_ਮਾਪ == 8
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#ਜੇ_ਅੰਤ

/* maximum alignment (for aligned attribute support) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_ALIGN     8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHAR_IS_UNSIGNED

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARM_SOFTFP_FLOAT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARM_HARD_FLOAT 1

/******************************************************/
#ਨਹੀਂਤਾਂ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

ST_ਅੰਕੜੇ ਅਚਲ ਅੱਖਰ * ਅਚਲ ਨਿਸ਼ਾਨਾ_machine_defs =
    "__arm__\0"
    "__arm\0"
    "arm\0"
    "__arm_elf__\0"
    "__arm_elf\0"
    "arm_elf\0"
    "__ARM_ARCH_4__\0"
    "__ARMEL__\0"
    "__APCS_32__\0"
#ਜੇ defined TCC_ARM_EABI
    "__ARM_EABI__\0"
#ਜੇ_ਅੰਤ
    ;

ST_ਅੰਕੜੇ ਅਚਲ ਪੂਰਨ reg_classes[NB_REGS] = {
    /* r0 */ RC_INT | RC_R0,
    /* r1 */ RC_INT | RC_R1,
    /* r2 */ RC_INT | RC_R2,
    /* r3 */ RC_INT | RC_R3,
    /* r12 */ RC_INT | RC_R12,
    /* f0 */ RC_FLOAT | RC_F0,
    /* f1 */ RC_FLOAT | RC_F1,
    /* f2 */ RC_FLOAT | RC_F2,
    /* f3 */ RC_FLOAT | RC_F3,
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
 /* d4/s8 */ RC_FLOAT | RC_F4,
/* d5/s10 */ RC_FLOAT | RC_F5,
/* d6/s12 */ RC_FLOAT | RC_F6,
/* d7/s14 */ RC_FLOAT | RC_F7,
#ਜੇ_ਅੰਤ
};

ਸਥਿਰ ਪੂਰਨ float_abi;
ਸਥਿਰ ਪੂਰਨ func_sub_sp_ਵਿੱਥ, ਆਖਰੀ_itod_magic;
ਸਥਿਰ ਪੂਰਨ leaffunc;

#ਜੇ defined(CONFIG_TCC_BCHECK)
ਸਥਿਰ addr_t func_bound_ਵਿੱਥ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ func_bound_ind;
ST_ਅੰਕੜੇ ਪੂਰਨ func_bound_ਜੋੜੋ_epilog;
#ਜੇ_ਅੰਤ

#ਜੇ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
ਸਥਿਰ CType float_type, double_type, func_float_type, func_double_type;
ST_FUNC ਖਾਲੀ arm_init(ਬਣਤਰ TCCState *s)
{
    float_type.t = VT_FLOAT;
    double_type.t = VT_DOUBLE;
    func_float_type.t = VT_FUNC;
    func_float_type.ref = sym_ਧੱਕੋ(SYM_ਖੇਤਰ, &float_type, FUNC_CDECL, FUNC_OLD);
    func_double_type.t = VT_FUNC;
    func_double_type.ref = sym_ਧੱਕੋ(SYM_ਖੇਤਰ, &double_type, FUNC_CDECL, FUNC_OLD);

    float_abi = s->float_abi;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ARM_HARDFLOAT
// XXX: Works on OpenBSD
// # warning "soft float ABI currently not supported: default to softfp"
#ਜੇ_ਅੰਤ
}
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ func_float_type func_old_type
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ func_double_type func_old_type
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ func_ldouble_type func_old_type
ST_FUNC ਖਾਲੀ arm_init(ਬਣਤਰ TCCState *s)
{
#ਜੇ 0
#ਜੇ !defined (TCC_ARM_VFP)
    tcc_warning("Support for FPA is deprecated and will be removed in next"
                " release");
#ਜੇ_ਅੰਤ
#ਜੇ !defined (TCC_ARM_EABI)
    tcc_warning("Support for OABI is deprecated and will be removed in next"
                " release");
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
}
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHECK_R(r) ((r) >= TREG_R0 && (r) <= TREG_LR)

ਸਥਿਰ ਪੂਰਨ two2mask(ਪੂਰਨ a,ਪੂਰਨ b) {
  ਜੇ (!CHECK_R(a) || !CHECK_R(b))
    tcc_error("compiler error! registers %i,%i is not valid",a,b);
  ਵਾਪਸ (reg_classes[a]|reg_classes[b])&~(RC_INT|RC_FLOAT);
}

ਸਥਿਰ ਪੂਰਨ regmask(ਪੂਰਨ r) {
  ਜੇ (!CHECK_R(r))
    tcc_error("compiler error! register %i is not valid",r);
  ਵਾਪਸ reg_classes[r]&~(RC_INT|RC_FLOAT);
}

/******************************************************/

ਖਾਲੀ o(uint32_t i)
{
  /* this is a good place to start adding big-endian support*/
  ਪੂਰਨ ind1;
  ਜੇ (nocode_wanted)
    ਵਾਪਸ;
  ind1 = ind + 4;
  ਜੇ (!cur_ਪਾਠ_section)
    tcc_error("compiler error! This happens f.ex. if the compiler\n"
         "can't evaluate constant expressions outside of a function.");
  ਜੇ (ind1 > cur_ਪਾਠ_section->ਅੰਕੜੇ_allocated)
    section_realloc(cur_ਪਾਠ_section, ind1);
  cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = i&255;
  i>>=8;
  cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = i&255;
  i>>=8;
  cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = i&255;
  i>>=8;
  cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = i;
}

ਸਥਿਰ uint32_t stuff_const(uint32_t op, uint32_t c)
{
  ਪੂਰਨ try_neg=0;
  uint32_t nc = 0, negop = 0;

  ਚੋਣ(op&0x1F00000)
  {
    ਹਾਲਤ 0x800000: //add
    ਹਾਲਤ 0x400000: //sub
      try_neg=1;
      negop=op^0xC00000;
      nc=-c;
      ਰੋਕੋ;
    ਹਾਲਤ 0x1A00000: //mov
    ਹਾਲਤ 0x1E00000: //mvn
      try_neg=1;
      negop=op^0x400000;
      nc=~c;
      ਰੋਕੋ;
    ਹਾਲਤ 0x200000: //xor
      ਜੇ(c==~0)
	ਵਾਪਸ (op&0xF010F000)|((op>>16)&0xF)|0x1E00000;
      ਰੋਕੋ;
    ਹਾਲਤ 0x0: //and
      ਜੇ(c==~0)
	ਵਾਪਸ (op&0xF010F000)|((op>>16)&0xF)|0x1A00000;
    ਹਾਲਤ 0x1C00000: //bic
      try_neg=1;
      negop=op^0x1C00000;
      nc=~c;
      ਰੋਕੋ;
    ਹਾਲਤ 0x1800000: //orr
      ਜੇ(c==~0)
	ਵਾਪਸ (op&0xFFF0FFFF)|0x1E00000;
      ਰੋਕੋ;
  }
  ਕਰੋ {
    uint32_t m;
    ਪੂਰਨ i;
    ਜੇ(c<256) /* catch undefined <<32 */
      ਵਾਪਸ op|c;
    ਲਈ(i=2;i<32;i+=2) {
      m=(0xffu>>i)|(0xffu<<(32-i));
      ਜੇ(!(c&~m))
	ਵਾਪਸ op|(i<<7)|(c<<i)|(c>>(32-i));
    }
    op=negop;
    c=nc;
  } ਜਦੋਂ(try_neg--);
  ਵਾਪਸ 0;
}


//only add,sub
ਖਾਲੀ stuff_const_harder(uint32_t op, uint32_t v) {
  uint32_t x;
  x=stuff_const(op,v);
  ਜੇ(x)
    o(x);
  ਨਹੀਂਤਾਂ {
    uint32_t a[16], nv, no, o2, n2;
    ਪੂਰਨ i,j,k;
    a[0]=0xff;
    o2=(op&0xfff0ffff)|((op&0xf000)<<4);;
    ਲਈ(i=1;i<16;i++)
      a[i]=(a[i-1]>>2)|(a[i-1]<<30);
    ਲਈ(i=0;i<12;i++)
      ਲਈ(j=i<4?i+12:15;j>=i+4;j--)
	ਜੇ((v&(a[i]|a[j]))==v) {
	  o(stuff_const(op,v&a[i]));
	  o(stuff_const(o2,v&a[j]));
	  ਵਾਪਸ;
	}
    no=op^0xC00000;
    n2=o2^0xC00000;
    nv=-v;
    ਲਈ(i=0;i<12;i++)
      ਲਈ(j=i<4?i+12:15;j>=i+4;j--)
	ਜੇ((nv&(a[i]|a[j]))==nv) {
	  o(stuff_const(no,nv&a[i]));
	  o(stuff_const(n2,nv&a[j]));
	  ਵਾਪਸ;
	}
    ਲਈ(i=0;i<8;i++)
      ਲਈ(j=i+4;j<12;j++)
	ਲਈ(k=i<4?i+12:15;k>=j+4;k--)
	  ਜੇ((v&(a[i]|a[j]|a[k]))==v) {
	    o(stuff_const(op,v&a[i]));
	    o(stuff_const(o2,v&a[j]));
	    o(stuff_const(o2,v&a[k]));
	    ਵਾਪਸ;
	  }
    no=op^0xC00000;
    nv=-v;
    ਲਈ(i=0;i<8;i++)
      ਲਈ(j=i+4;j<12;j++)
	ਲਈ(k=i<4?i+12:15;k>=j+4;k--)
	  ਜੇ((nv&(a[i]|a[j]|a[k]))==nv) {
	    o(stuff_const(no,nv&a[i]));
	    o(stuff_const(n2,nv&a[j]));
	    o(stuff_const(n2,nv&a[k]));
	    ਵਾਪਸ;
	  }
    o(stuff_const(op,v&a[0]));
    o(stuff_const(o2,v&a[4]));
    o(stuff_const(o2,v&a[8]));
    o(stuff_const(o2,v&a[12]));
  }
}

uint32_t encbranch(ਪੂਰਨ pos, ਪੂਰਨ addr, ਪੂਰਨ fail)
{
  addr-=pos+8;
  addr/=4;
  ਜੇ(addr>=0x1000000 || addr<-0x1000000) {
    ਜੇ(fail)
      tcc_error("FIXME: function bigger than 32MB");
    ਵਾਪਸ 0;
  }
  ਵਾਪਸ 0x0A000000|(addr&0xffffff);
}

ਪੂਰਨ decbranch(ਪੂਰਨ pos)
{
  ਪੂਰਨ x;
  x=*(uint32_t *)(cur_ਪਾਠ_section->ਅੰਕੜੇ + pos);
  x&=0x00ffffff;
  ਜੇ(x&0x800000)
    x-=0x1000000;
  ਵਾਪਸ x*4+pos+8;
}

/* output a symbol and patch all calls to it */
ਖਾਲੀ gsym_addr(ਪੂਰਨ t, ਪੂਰਨ a)
{
  uint32_t *x;
  ਪੂਰਨ lt;
  ਜਦੋਂ(t) {
    x=(uint32_t *)(cur_ਪਾਠ_section->ਅੰਕੜੇ + t);
    t=decbranch(lt=t);
    ਜੇ(a==lt+4)
      *x=0xE1A00000; // nop
    ਨਹੀਂਤਾਂ {
      *x &= 0xff000000;
      *x |= encbranch(lt,a,1);
    }
  }
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
ਸਥਿਰ uint32_t vfpr(ਪੂਰਨ r)
{
  ਜੇ(r<TREG_F0 || r>TREG_F7)
    tcc_error("compiler error! register %i is no vfp register",r);
  ਵਾਪਸ r - TREG_F0;
}
#ਨਹੀਂਤਾਂ
ਸਥਿਰ uint32_t fpr(ਪੂਰਨ r)
{
  ਜੇ(r<TREG_F0 || r>TREG_F3)
    tcc_error("compiler error! register %i is no fpa register",r);
  ਵਾਪਸ r - TREG_F0;
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ uint32_t intr(ਪੂਰਨ r)
{
  ਜੇ(r == TREG_R12)
    ਵਾਪਸ 12;
  ਜੇ(r >= TREG_R0 && r <= TREG_R3)
    ਵਾਪਸ r - TREG_R0;
  ਜੇ (!(r >= TREG_SP && r <= TREG_LR))
    tcc_error("compiler error! register %i is no int register",r);
  ਵਾਪਸ r + (13 - TREG_SP);
}

ਸਥਿਰ ਖਾਲੀ calcaddr(uint32_t *ਅਧਾਰ, ਪੂਰਨ *off, ਪੂਰਨ *sgn, ਪੂਰਨ maxoff, ਬਿਨਾਨਿਸ਼ਾਨੀ ਖਿਸਕਾਓ)
{
  ਜੇ(*off>maxoff || *off&((1<<ਖਿਸਕਾਓ)-1)) {
    uint32_t x, y;
    x=0xE280E000;
    ਜੇ(*sgn)
      x=0xE240E000;
    x|=(*ਅਧਾਰ)<<16;
    *ਅਧਾਰ=14; // lr
    y=stuff_const(x,*off&~maxoff);
    ਜੇ(y) {
      o(y);
      *off&=maxoff;
      ਵਾਪਸ;
    }
    y=stuff_const(x,(*off+maxoff)&~maxoff);
    ਜੇ(y) {
      o(y);
      *sgn=!*sgn;
      *off=((*off+maxoff)&~maxoff)-*off;
      ਵਾਪਸ;
    }
    stuff_const_harder(x,*off&~maxoff);
    *off&=maxoff;
  }
}

ਸਥਿਰ uint32_t mapcc(ਪੂਰਨ cc)
{
  ਚੋਣ(cc)
  {
    ਹਾਲਤ TOK_ULT:
      ਵਾਪਸ 0x30000000; /* CC/LO */
    ਹਾਲਤ TOK_UGE:
      ਵਾਪਸ 0x20000000; /* CS/HS */
    ਹਾਲਤ TOK_EQ:
      ਵਾਪਸ 0x00000000; /* EQ */
    ਹਾਲਤ TOK_NE:
      ਵਾਪਸ 0x10000000; /* NE */
    ਹਾਲਤ TOK_ULE:
      ਵਾਪਸ 0x90000000; /* LS */
    ਹਾਲਤ TOK_UGT:
      ਵਾਪਸ 0x80000000; /* HI */
    ਹਾਲਤ TOK_Nset:
      ਵਾਪਸ 0x40000000; /* MI */
    ਹਾਲਤ TOK_Nclear:
      ਵਾਪਸ 0x50000000; /* PL */
    ਹਾਲਤ TOK_LT:
      ਵਾਪਸ 0xB0000000; /* LT */
    ਹਾਲਤ TOK_GE:
      ਵਾਪਸ 0xA0000000; /* GE */
    ਹਾਲਤ TOK_LE:
      ਵਾਪਸ 0xD0000000; /* LE */
    ਹਾਲਤ TOK_GT:
      ਵਾਪਸ 0xC0000000; /* GT */
  }
  tcc_error("unexpected condition code");
  ਵਾਪਸ 0xE0000000; /* AL */
}

ਸਥਿਰ ਪੂਰਨ negcc(ਪੂਰਨ cc)
{
  ਚੋਣ(cc)
  {
    ਹਾਲਤ TOK_ULT:
      ਵਾਪਸ TOK_UGE;
    ਹਾਲਤ TOK_UGE:
      ਵਾਪਸ TOK_ULT;
    ਹਾਲਤ TOK_EQ:
      ਵਾਪਸ TOK_NE;
    ਹਾਲਤ TOK_NE:
      ਵਾਪਸ TOK_EQ;
    ਹਾਲਤ TOK_ULE:
      ਵਾਪਸ TOK_UGT;
    ਹਾਲਤ TOK_UGT:
      ਵਾਪਸ TOK_ULE;
    ਹਾਲਤ TOK_Nset:
      ਵਾਪਸ TOK_Nclear;
    ਹਾਲਤ TOK_Nclear:
      ਵਾਪਸ TOK_Nset;
    ਹਾਲਤ TOK_LT:
      ਵਾਪਸ TOK_GE;
    ਹਾਲਤ TOK_GE:
      ਵਾਪਸ TOK_LT;
    ਹਾਲਤ TOK_LE:
      ਵਾਪਸ TOK_GT;
    ਹਾਲਤ TOK_GT:
      ਵਾਪਸ TOK_LE;
  }
  tcc_error("unexpected condition code");
  ਵਾਪਸ TOK_NE;
}

/* Load value into register r.
   Use relative/got addressing to avoid setting DT_TEXTREL */
ਸਥਿਰ ਖਾਲੀ ਲੱਦੋ_ਮੁੱਲ(SValue *sv, ਪੂਰਨ r)
{
#ਜੇ CONFIG_TCC_CPUVER >= 7
    ਜੇ (!(sv->r & VT_SYM)) {
        ਬਿਨਾਨਿਸ਼ਾਨੀ x=sv->c.i;
        o(0xE3000000|intr(r)<<12|(x&0xFFF)|(x<<4&0xF0000)); /* movw rx,#x(lo) */
        ਜੇ (x&0xFFFF0000)
          o(0xE3400000|intr(r)<<12|(x>>16&0xFFF)|(x>>12&0xF0000)); /* movt rx,#x(hi) */
        ਵਾਪਸ;
    }
#ਜੇ_ਅੰਤ
    o(0xE59F0000|(intr(r)<<12)); /* ldr r, [pc] */
    o(0xEA000000); /* b $+4 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_PIC
    ਜੇ(sv->r & VT_SYM)
        greloc(cur_ਪਾਠ_section, sv->sym, ind, R_ARM_ABS32);
    o(sv->c.i);
#ਨਹੀਂਤਾਂ
    ਜੇ(sv->r & VT_SYM) {
	ਜੇ (sv->sym->type.t & VT_STATIC) {
            greloc(cur_ਪਾਠ_section, sv->sym, ind, R_ARM_REL32);
            o(sv->c.i - 12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
        }
        ਨਹੀਂਤਾਂ {
            greloc(cur_ਪਾਠ_section, sv->sym, ind, R_ARM_GOT_PREL);
            o(-12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
            o(0xe5900000 | (intr(r)<<12) | (intr(r)<<16));  // ldr rx,[rx]
            ਜੇ (sv->c.i)
              stuff_const_harder(0xe2800000 | (intr(r)<<12) | (intr(r)<<16),
                                 sv->c.i);
        }
    }
    ਨਹੀਂਤਾਂ
        o(sv->c.i);
#ਜੇ_ਅੰਤ
}

/* load 'r' from value 'sv' */
ਖਾਲੀ ਲੱਦੋ(ਪੂਰਨ r, SValue *sv)
{
  ਪੂਰਨ v, ft, fc, fr, sign;
  uint32_t op, ਅਧਾਰ;
  SValue v1;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  ਜੇ(fc>=0)
    sign=0;
  ਨਹੀਂਤਾਂ {
    sign=1;
    fc=-(ਬਿਨਾਨਿਸ਼ਾਨੀ)fc;
  }

  v = fr & VT_VALMASK;
  ਜੇ (fr & VT_LVAL) {

    ਜੇ ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe510e000; /* ldr r, [lr, #0] */
        greloca(cur_ਪਾਠ_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        ਵਾਪਸ;
    }

    ਅਧਾਰ = 0xB; // fp
    ਜੇ(v == VT_LLOCAL) {
      v1.type.t = VT_PTR;
      v1.r = VT_LOCAL | VT_LVAL;
      v1.c.i = sv->c.i;
      ਲੱਦੋ(TREG_LR, &v1);
      ਅਧਾਰ = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } ਨਹੀਂਤਾਂ ਜੇ(v == VT_CONST) {
      v1.type.t = VT_PTR;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      ਲੱਦੋ(TREG_LR, &v1);
      ਅਧਾਰ = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } ਨਹੀਂਤਾਂ ਜੇ(v < VT_CONST) {
      ਅਧਾਰ=intr(v);
      fc=sign=0;
      v=VT_LOCAL;
    }
    ਜੇ(v == VT_LOCAL) {
      ਜੇ(is_float(ft)) {
	calcaddr(&ਅਧਾਰ,&fc,&sign,1020,2);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
        op=0xED100A00; /* flds */
        ਜੇ(!sign)
          op|=0x800000;
        ਜੇ ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* flds -> fldd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(ਅਧਾਰ<<16));
#ਨਹੀਂਤਾਂ
	op=0xED100100;
	ਜੇ(!sign)
	  op|=0x800000;
	ਜੇ ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#ਜੇ LDOUBLE_ਮਾਪ != 8
	ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#ਜੇ_ਅੰਤ
	o(op|(fpr(r)<<12)|(fc>>2)|(ਅਧਾਰ<<16));
#ਜੇ_ਅੰਤ
      } ਨਹੀਂਤਾਂ ਜੇ((ft & (VT_BTYPE|VT_UNSIGNED)) == VT_BYTE
                || (ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&ਅਧਾਰ,&fc,&sign,255,0);
	op=0xE1500090;
	ਜੇ ((ft & VT_BTYPE) == VT_SHORT)
	  op|=0x20;
	ਜੇ ((ft & VT_UNSIGNED) == 0)
	  op|=0x40;
	ਜੇ(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(ਅਧਾਰ<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } ਨਹੀਂਤਾਂ {
	calcaddr(&ਅਧਾਰ,&fc,&sign,4095,0);
	op=0xE5100000;
	ਜੇ(!sign)
	  op|=0x800000;
        ਜੇ ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(ਅਧਾਰ<<16));
      }
      ਵਾਪਸ;
    }
  } ਨਹੀਂਤਾਂ {
    ਜੇ (v == VT_CONST) {
      op=stuff_const(0xE3A00000|(intr(r)<<12),sv->c.i);
      ਜੇ (fr & VT_SYM || !op)
	ਲੱਦੋ_ਮੁੱਲ(sv, r);
      ਨਹੀਂਤਾਂ
        o(op);
      ਵਾਪਸ;
    } ਨਹੀਂਤਾਂ ਜੇ (v == VT_LOCAL) {
      op=stuff_const(0xE28B0000|(intr(r)<<12),sv->c.i);
      ਜੇ (fr & VT_SYM || !op) {
	ਲੱਦੋ_ਮੁੱਲ(sv, r);
	o(0xE08B0000|(intr(r)<<12)|intr(r));
      } ਨਹੀਂਤਾਂ
	o(op);
      ਵਾਪਸ;
    } ਨਹੀਂਤਾਂ ਜੇ(v == VT_CMP) {
      o(mapcc(sv->c.i)|0x3A00001|(intr(r)<<12));
      o(mapcc(negcc(sv->c.i))|0x3A00000|(intr(r)<<12));
      ਵਾਪਸ;
    } ਨਹੀਂਤਾਂ ਜੇ (v == VT_JMP || v == VT_JMPI) {
      ਪੂਰਨ t;
      t = v & 1;
      o(0xE3A00000|(intr(r)<<12)|t);
      o(0xEA000000);
      gsym(sv->c.i);
      o(0xE3A00000|(intr(r)<<12)|(t^1));
      ਵਾਪਸ;
    } ਨਹੀਂਤਾਂ ਜੇ (v < VT_CONST) {
      ਜੇ(is_float(ft))
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
        o(0xEEB00A40|(vfpr(r)<<12)|vfpr(v)|T2CPR(ft)); /* fcpyX */
#ਨਹੀਂਤਾਂ
	o(0xEE008180|(fpr(r)<<12)|fpr(v));
#ਜੇ_ਅੰਤ
      ਨਹੀਂਤਾਂ
	o(0xE1A00000|(intr(r)<<12)|intr(v));
      ਵਾਪਸ;
    }
  }
  tcc_error("load unimplemented!");
}

/* store register 'r' in lvalue 'v' */
ਖਾਲੀ store(ਪੂਰਨ r, SValue *sv)
{
  SValue v1;
  ਪੂਰਨ v, ft, fc, fr, sign;
  uint32_t op, ਅਧਾਰ;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  ਜੇ(fc>=0)
    sign=0;
  ਨਹੀਂਤਾਂ {
    sign=1;
    fc=-fc;
  }

  v = fr & VT_VALMASK;
  ਜੇ (fr & VT_LVAL || fr == VT_LOCAL) {

    ਜੇ ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe500e000; /* str r, [lr, #0] */
        greloca(cur_ਪਾਠ_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        ਵਾਪਸ;
    }

    ਅਧਾਰ = 0xb; /* fp */
    ਜੇ(v < VT_CONST) {
      ਅਧਾਰ=intr(v);
      v=VT_LOCAL;
      fc=sign=0;
    } ਨਹੀਂਤਾਂ ਜੇ(v == VT_CONST) {
      v1.type.t = ft;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      ਲੱਦੋ(TREG_LR, &v1);
      ਅਧਾਰ = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    }
    ਜੇ(v == VT_LOCAL) {
       ਜੇ(is_float(ft)) {
	calcaddr(&ਅਧਾਰ,&fc,&sign,1020,2);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
        op=0xED000A00; /* fsts */
        ਜੇ(!sign)
          op|=0x800000;
        ਜੇ ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* fsts -> fstd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(ਅਧਾਰ<<16));
#ਨਹੀਂਤਾਂ
	op=0xED000100;
	ਜੇ(!sign)
	  op|=0x800000;
	ਜੇ ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#ਜੇ LDOUBLE_ਮਾਪ != 8
	ਨਹੀਂਤਾਂ ਜੇ ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#ਜੇ_ਅੰਤ
	o(op|(fpr(r)<<12)|(fc>>2)|(ਅਧਾਰ<<16));
#ਜੇ_ਅੰਤ
	ਵਾਪਸ;
      } ਨਹੀਂਤਾਂ ਜੇ((ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&ਅਧਾਰ,&fc,&sign,255,0);
	op=0xE14000B0;
	ਜੇ(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(ਅਧਾਰ<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } ਨਹੀਂਤਾਂ {
	calcaddr(&ਅਧਾਰ,&fc,&sign,4095,0);
	op=0xE5000000;
	ਜੇ(!sign)
	  op|=0x800000;
        ਜੇ ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(ਅਧਾਰ<<16));
      }
      ਵਾਪਸ;
    }
  }
  tcc_error("store unimplemented");
}

ਸਥਿਰ ਖਾਲੀ gadd_sp(ਪੂਰਨ val)
{
  stuff_const_harder(0xE28DD000,val);
}

/* 'is_jmp' is '1' if it is a jump */
ਸਥਿਰ ਖਾਲੀ gcall_or_jmp(ਪੂਰਨ is_jmp)
{
  ਪੂਰਨ r;
  uint32_t x;
  ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
    /* constant case */
    ਜੇ(vtop->r & VT_SYM){
	x=encbranch(ind,ind+vtop->c.i,0);
	ਜੇ(x) {
	    /* relocation case */
	    greloc(cur_ਪਾਠ_section, vtop->sym, ind, R_ARM_PC24);
	    o(x|(is_jmp?0xE0000000:0xE1000000));
	} ਨਹੀਂਤਾਂ {
	    r = TREG_LR;
	    ਲੱਦੋ_ਮੁੱਲ(vtop, r);
	    ਜੇ(is_jmp)
	        o(0xE1A0F000 | intr(r)); // mov pc, r
	    ਨਹੀਂਤਾਂ
		o(0xe12fff30 | intr(r)); // blx r
	}
     }ਨਹੀਂਤਾਂ{
	ਜੇ(!is_jmp)
	    o(0xE28FE004); // add lr,pc,#4
	o(0xE51FF004);   // ldr pc,[pc,#-4]
	o(vtop->c.i);
     }
  } ਨਹੀਂਤਾਂ {
    /* otherwise, indirect call */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    vtop->r &= ~VT_MUSTBOUND;
#ਜੇ_ਅੰਤ
    r = gv(RC_INT);
    ਜੇ(!is_jmp)
      o(0xE1A0E00F);       // mov lr,pc
    o(0xE1A0F000|intr(r)); // mov pc,r
  }
}

#ਜੇ defined(CONFIG_TCC_BCHECK)

ਸਥਿਰ ਖਾਲੀ gen_bounds_call(ਪੂਰਨ v)
{
    Sym *sym = external_helper_sym(v);

    greloc(cur_ਪਾਠ_section, sym, ind, R_ARM_PC24);
    o(0xebfffffe);
}

ਸਥਿਰ ਖਾਲੀ gen_bounds_prolog(ਖਾਲੀ)
{
    /* leave some room for bound checking code */
    func_bound_ਵਿੱਥ = lbounds_section->ਅੰਕੜੇ_ਵਿੱਥ;
    func_bound_ind = ind;
    func_bound_ਜੋੜੋ_epilog = 0;
    o(0xe1a00000);  /* ld r0,lbounds_section->data_offset */
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);  /* call __bound_local_new */
}

ਸਥਿਰ ਖਾਲੀ gen_bounds_epilog(ਖਾਲੀ)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ਅੰਕੜੇ;
    ਪੂਰਨ ਵਿੱਥ_modified = func_bound_ਵਿੱਥ != lbounds_section->ਅੰਕੜੇ_ਵਿੱਥ;

    ਜੇ (!ਵਿੱਥ_modified && !func_bound_ਜੋੜੋ_epilog)
        ਵਾਪਸ;

    /* add end of table info */
    bounds_ptr = section_ptr_ਜੋੜੋ(lbounds_section, ਆਕਾਰ(addr_t));
    *bounds_ptr = 0;

    sym_ਅੰਕੜੇ = get_sym_ref(&char_ਸੂਚਕ_type, lbounds_section,
                           func_bound_ਵਿੱਥ, PTR_ਮਾਪ);

    /* generate bound local allocation */
    ਜੇ (ਵਿੱਥ_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        o(0xe59f0000);  /* ldr r0, [pc] */
        o(0xea000000);  /* b $+4 */
        greloc(cur_ਪਾਠ_section, sym_ਅੰਕੜੇ, ind, R_ARM_REL32);
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
    greloc(cur_ਪਾਠ_section, sym_ਅੰਕੜੇ, ind, R_ARM_REL32);
    o(-12);  /* lbounds_section->data_offset */
    o(0xe080000f);  /* add r0,r0,pc */
    gen_bounds_call(TOK___bound_local_delete);
    o(0xecbd0b04); /* vpop {d0,d1} */
    o(0xe8bd0003); /* pop {r0,r1} */
}
#ਜੇ_ਅੰਤ

/* Return whether a structure is an homogeneous float aggregate or not.
   The answer is true if all the elements of the structure are of the same
   primitive float type and there is less than 4 elements.

   type: the type corresponding to the structure to be tested */
ਸਥਿਰ ਪੂਰਨ is_hgen_float_aggr(CType *type)
{
  ਜੇ ((type->t & VT_BTYPE) == VT_STRUCT) {
    ਬਣਤਰ Sym *ref;
    ਪੂਰਨ btype, nb_fields = 0;

    ref = type->ref->ਅਗਲਾ;
    ਜੇ (ref) {
      btype = ref->type.t & VT_BTYPE;
      ਜੇ (btype == VT_FLOAT || btype == VT_DOUBLE) {
        ਲਈ(; ref && btype == (ref->type.t & VT_BTYPE); ref = ref->ਅਗਲਾ, nb_fields++)
            ;
        ਵਾਪਸ !ref && nb_fields <= 4;
      }
    }
  }
  ਵਾਪਸ 0;
}

ਬਣਤਰ avail_regs {
  ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ avail[3]; /* 3 holes max with only float and double alignments */
  ਪੂਰਨ ਪਹਿਲਾ_hole; /* first available hole */
  ਪੂਰਨ ਆਖਰੀ_hole; /* last available hole (none if equal to first_hole) */
  ਪੂਰਨ ਪਹਿਲਾ_free_reg; /* next free register in the sequence, hole excluded */
};

/* Find suitable registers for a VFP Co-Processor Register Candidate (VFP CPRC
   param) according to the rules described in the procedure call standard for
   the ARM architecture (AAPCS). If found, the registers are assigned to this
   VFP CPRC parameter. Registers are allocated in sequence unless a hole exists
   and the parameter is a single float.

   avregs: opaque structure to keep track of available VFP co-processor regs
   align: alignment constraints for the param, as returned by type_size()
   size: size of the parameter, as returned by type_size() */
ਪੂਰਨ ਸੌਂਪੋ_vfpreg(ਬਣਤਰ avail_regs *avregs, ਪੂਰਨ align, ਪੂਰਨ ਮਾਪ)
{
  ਪੂਰਨ ਪਹਿਲਾ_reg = 0;

  ਜੇ (avregs->ਪਹਿਲਾ_free_reg == -1)
    ਵਾਪਸ -1;
  ਜੇ (align >> 3) { /* double alignment */
    ਪਹਿਲਾ_reg = avregs->ਪਹਿਲਾ_free_reg;
    /* alignment constraint not respected so use next reg and record hole */
    ਜੇ (ਪਹਿਲਾ_reg & 1)
      avregs->avail[avregs->ਆਖਰੀ_hole++] = ਪਹਿਲਾ_reg++;
  } ਨਹੀਂਤਾਂ { /* no special alignment (float or array of float) */
    /* if single float and a hole is available, assign the param to it */
    ਜੇ (ਮਾਪ == 4 && avregs->ਪਹਿਲਾ_hole != avregs->ਆਖਰੀ_hole)
      ਵਾਪਸ avregs->avail[avregs->ਪਹਿਲਾ_hole++];
    ਨਹੀਂਤਾਂ
      ਪਹਿਲਾ_reg = avregs->ਪਹਿਲਾ_free_reg;
  }
  ਜੇ (ਪਹਿਲਾ_reg + ਮਾਪ / 4 <= 16) {
    avregs->ਪਹਿਲਾ_free_reg = ਪਹਿਲਾ_reg + ਮਾਪ / 4;
    ਵਾਪਸ ਪਹਿਲਾ_reg;
  }
  avregs->ਪਹਿਲਾ_free_reg = -1;
  ਵਾਪਸ -1;
}

/* Returns whether all params need to be passed in core registers or not.
   This is the case for function part of the runtime ABI. */
ਪੂਰਨ floats_ਵਿੱਚ_core_regs(SValue *sval)
{
  ਜੇ (!sval->sym)
    ਵਾਪਸ 0;

  ਚੋਣ (sval->sym->v) {
    ਹਾਲਤ TOK___floatundisf:
    ਹਾਲਤ TOK___floatundidf:
    ਹਾਲਤ TOK___fixunssfdi:
    ਹਾਲਤ TOK___fixunsdfdi:
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
    ਹਾਲਤ TOK___fixunsxfdi:
#ਜੇ_ਅੰਤ
    ਹਾਲਤ TOK___floatdisf:
    ਹਾਲਤ TOK___floatdidf:
    ਹਾਲਤ TOK___fixsfdi:
    ਹਾਲਤ TOK___fixdfdi:
      ਵਾਪਸ 1;

    ਮੂਲ:
      ਵਾਪਸ 0;
  }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ਪੂਰਨ gfunc_sret(CType *vt, ਪੂਰਨ variadic, CType *ret, ਪੂਰਨ *ret_align, ਪੂਰਨ *regsize) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
    ਪੂਰਨ ਮਾਪ, align;
    ਮਾਪ = type_ਮਾਪ(vt, &align);
    ਜੇ (float_abi == ARM_HARD_FLOAT && !variadic &&
        (is_float(vt->t) || is_hgen_float_aggr(vt))) {
        *ret_align = 8;
	*regsize = 8;
        ret->ref = ਨਿਰਾ;
        ret->t = VT_DOUBLE;
        ਵਾਪਸ (ਮਾਪ + 7) >> 3;
    } ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ > 0 && ਮਾਪ <= 4) {
        *ret_align = 4;
	*regsize = 4;
        ret->ref = ਨਿਰਾ;
        ret->t = VT_INT;
        ਵਾਪਸ 1;
    } ਨਹੀਂਤਾਂ
        ਵਾਪਸ 0;
#ਨਹੀਂਤਾਂ
    ਵਾਪਸ 0;
#ਜੇ_ਅੰਤ
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
ਗਿਣਤੀ reg_class {
	ਢੇਰ_CLASS = 0,
	CORE_STRUCT_CLASS,
	VFP_CLASS,
	VFP_STRUCT_CLASS,
	CORE_CLASS,
	NB_CLASSES
};

ਬਣਤਰ param_plan {
    ਪੂਰਨ ਸ਼ੁਰੂ; /* first reg or addr used depending on the class */
    ਪੂਰਨ ਸਿਰਾ; /* last reg used or next free addr depending on the class */
    SValue *sval; /* pointer to SValue on the value stack */
    ਬਣਤਰ param_plan *prev; /*  previous element in this class */
};

ਬਣਤਰ plan {
    ਬਣਤਰ param_plan *pplans; /* array of all the param plans */
    ਬਣਤਰ param_plan *clsplans[NB_CLASSES]; /* per class lists of param plans */
    ਪੂਰਨ nb_plans;
};

ਸਥਿਰ ਖਾਲੀ ਜੋੜੋ_param_plan(ਬਣਤਰ plan* plan, ਪੂਰਨ cls, ਪੂਰਨ ਸ਼ੁਰੂ, ਪੂਰਨ ਸਿਰਾ, SValue *v)
{
    ਬਣਤਰ param_plan *p = &plan->pplans[plan->nb_plans++];
    p->prev = plan->clsplans[cls];
    plan->clsplans[cls] = p;
    p->ਸ਼ੁਰੂ = ਸ਼ੁਰੂ, p->ਸਿਰਾ = ਸਿਰਾ, p->sval = v;
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
ਸਥਿਰ ਪੂਰਨ ਸੌਂਪੋ_regs(ਪੂਰਨ nb_ਦਲੀਲਾਂ, ਪੂਰਨ float_abi, ਬਣਤਰ plan *plan, ਪੂਰਨ *todo)
{
  ਪੂਰਨ i, ਮਾਪ, align;
  ਪੂਰਨ ncrn /* next core register number */, nsaa /* next stacked argument address*/;
  ਬਣਤਰ avail_regs avregs = {{0}};

  ncrn = nsaa = 0;
  *todo = 0;

  ਲਈ(i = nb_ਦਲੀਲਾਂ; i-- ;) {
    ਪੂਰਨ j, ਸ਼ੁਰੂ_vfpreg = 0;
    CType type = vtop[-i].type;
    type.t &= ~VT_ARRAY;
    ਮਾਪ = type_ਮਾਪ(&type, &align);
    ਮਾਪ = (ਮਾਪ + 3) & ~3;
    align = (align + 3) & ~3;
    ਚੋਣ(vtop[-i].type.t & VT_BTYPE) {
      ਹਾਲਤ VT_STRUCT:
      ਹਾਲਤ VT_FLOAT:
      ਹਾਲਤ VT_DOUBLE:
      ਹਾਲਤ VT_LDOUBLE:
      ਜੇ (float_abi == ARM_HARD_FLOAT) {
        ਪੂਰਨ is_hfa = 0; /* Homogeneous float aggregate */

        ਜੇ (is_float(vtop[-i].type.t)
            || (is_hfa = is_hgen_float_aggr(&vtop[-i].type))) {
          ਪੂਰਨ ਸਿਰਾ_vfpreg;

          ਸ਼ੁਰੂ_vfpreg = ਸੌਂਪੋ_vfpreg(&avregs, align, ਮਾਪ);
          ਸਿਰਾ_vfpreg = ਸ਼ੁਰੂ_vfpreg + ((ਮਾਪ - 1) >> 2);
          ਜੇ (ਸ਼ੁਰੂ_vfpreg >= 0) {
            ਜੋੜੋ_param_plan(plan, is_hfa ? VFP_STRUCT_CLASS : VFP_CLASS,
                ਸ਼ੁਰੂ_vfpreg, ਸਿਰਾ_vfpreg, &vtop[-i]);
            ਜਾਰੀ;
          } ਨਹੀਂਤਾਂ
            ਰੋਕੋ;
        }
      }
      ncrn = (ncrn + (align-1)/4) & ~((align/4) - 1);
      ਜੇ (ncrn + ਮਾਪ/4 <= 4 || (ncrn < 4 && ਸ਼ੁਰੂ_vfpreg != -1)) {
        /* The parameter is allocated both in core register and on stack. As
	 * such, it can be of either class: it would either be the last of
	 * CORE_STRUCT_CLASS or the first of STACK_CLASS. */
        ਲਈ (j = ncrn; j < 4 && j < ncrn + ਮਾਪ / 4; j++)
          *todo|=(1<<j);
        ਜੋੜੋ_param_plan(plan, CORE_STRUCT_CLASS, ncrn, j, &vtop[-i]);
        ncrn += ਮਾਪ/4;
        ਜੇ (ncrn > 4)
          nsaa = (ncrn - 4) * 4;
      } ਨਹੀਂਤਾਂ {
        ncrn = 4;
        ਰੋਕੋ;
      }
      ਜਾਰੀ;
      ਮੂਲ:
      ਜੇ (ncrn < 4) {
        ਪੂਰਨ is_long = (vtop[-i].type.t & VT_BTYPE) == VT_LLONG;

        ਜੇ (is_long) {
          ncrn = (ncrn + 1) & -2;
          ਜੇ (ncrn == 4)
            ਰੋਕੋ;
        }
        ਜੋੜੋ_param_plan(plan, CORE_CLASS, ncrn, ncrn + is_long, &vtop[-i]);
        ncrn += 1 + is_long;
        ਜਾਰੀ;
      }
    }
    nsaa = (nsaa + (align - 1)) & ~(align - 1);
    ਜੋੜੋ_param_plan(plan, ਢੇਰ_CLASS, nsaa, nsaa + ਮਾਪ, &vtop[-i]);
    nsaa += ਮਾਪ; /* size already rounded up before */
  }
  ਵਾਪਸ nsaa;
}

/* Copy parameters to their final destination (core reg, VFP reg or stack) for
   function call.

   nb_args: number of parameters the function take
   plan: the overall assignment plan for parameters
   todo: a bitmap indicating what core reg will hold a parameter

   Returns the number of SValue added by this function on the value stack */
ਸਥਿਰ ਪੂਰਨ copy_params(ਪੂਰਨ nb_ਦਲੀਲਾਂ, ਬਣਤਰ plan *plan, ਪੂਰਨ todo)
{
  ਪੂਰਨ ਮਾਪ, align, r, i, nb_extra_sval = 0;
  ਬਣਤਰ param_plan *pplan;
  ਪੂਰਨ pass = 0;

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
  ਲਈ(i = 0; i < NB_CLASSES; i++) {
    ਲਈ(pplan = plan->clsplans[i]; pplan; pplan = pplan->prev) {

      ਜੇ (pass
          && (i != CORE_CLASS || pplan->sval->r < VT_CONST))
        ਜਾਰੀ;

      vpushv(pplan->sval);
      pplan->sval->r = pplan->sval->r2 = VT_CONST; /* disable entry */
      ਚੋਣ(i) {
        ਹਾਲਤ ਢੇਰ_CLASS:
        ਹਾਲਤ CORE_STRUCT_CLASS:
        ਹਾਲਤ VFP_STRUCT_CLASS:
          ਜੇ ((pplan->sval->type.t & VT_BTYPE) == VT_STRUCT) {
            ਪੂਰਨ padding = 0;
            ਮਾਪ = type_ਮਾਪ(&pplan->sval->type, &align);
            /* align to stack align size */
            ਮਾਪ = (ਮਾਪ + 3) & ~3;
            ਜੇ (i == ਢੇਰ_CLASS && pplan->prev)
              padding = pplan->ਸ਼ੁਰੂ - pplan->prev->ਸਿਰਾ;
            ਮਾਪ += padding; /* Add padding if any */
            /* allocate the necessary size on stack */
            gadd_sp(-ਮਾਪ);
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
            ਜੇ (i == VFP_STRUCT_CLASS) {
              ਪੂਰਨ ਪਹਿਲਾ = pplan->ਸ਼ੁਰੂ, nb = pplan->ਸਿਰਾ - ਪਹਿਲਾ + 1;
              /* vpop.32 {pplan->start, ..., pplan->end} */
              o(0xECBD0A00|(ਪਹਿਲਾ&1)<<22|(ਪਹਿਲਾ>>1)<<12|nb);
              /* No need to write the register used to a SValue since VFP regs
                 cannot be used for gcall_or_jmp */
            }
          } ਨਹੀਂਤਾਂ {
            ਜੇ (is_float(pplan->sval->type.t)) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
              r = vfpr(gv(RC_FLOAT)) << 12;
              ਜੇ ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                ਮਾਪ = 4;
              ਨਹੀਂਤਾਂ {
                ਮਾਪ = 8;
                r |= 0x101; /* vpush.32 -> vpush.64 */
              }
              o(0xED2D0A01 + r); /* vpush */
#ਨਹੀਂਤਾਂ
              r = fpr(gv(RC_FLOAT)) << 12;
              ਜੇ ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                ਮਾਪ = 4;
              ਨਹੀਂਤਾਂ ਜੇ ((pplan->sval->type.t & VT_BTYPE) == VT_DOUBLE)
                ਮਾਪ = 8;
              ਨਹੀਂਤਾਂ
                ਮਾਪ = LDOUBLE_ਮਾਪ;
              ਜੇ (ਮਾਪ == 12)
                r |= 0x400000;
              ਨਹੀਂਤਾਂ ਜੇ(ਮਾਪ == 8)
                r|=0x8000;

              o(0xED2D0100|r|(ਮਾਪ>>2)); /* some kind of vpush for FPA */
#ਜੇ_ਅੰਤ
            } ਨਹੀਂਤਾਂ {
              /* simple type (currently always same size) */
              /* XXX: implicit cast ? */
              ਮਾਪ=4;
              ਜੇ ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
                lexpand();
                ਮਾਪ = 8;
                r = gv(RC_INT);
                o(0xE52D0004|(intr(r)<<12)); /* push r */
                vtop--;
              }
              r = gv(RC_INT);
              o(0xE52D0004|(intr(r)<<12)); /* push r */
            }
            ਜੇ (i == ਢੇਰ_CLASS && pplan->prev)
              gadd_sp(pplan->prev->ਸਿਰਾ - pplan->ਸ਼ੁਰੂ); /* Add padding if any */
          }
          ਰੋਕੋ;

        ਹਾਲਤ VFP_CLASS:
          gv(regmask(TREG_F0 + (pplan->ਸ਼ੁਰੂ >> 1)));
          ਜੇ (pplan->ਸ਼ੁਰੂ & 1) { /* Must be in upper part of double register */
            o(0xEEF00A40|((pplan->ਸ਼ੁਰੂ>>1)<<12)|(pplan->ਸ਼ੁਰੂ>>1)); /* vmov.f32 s(n+1), sn */
            vtop->r = VT_CONST; /* avoid being saved on stack by gv for next float */
          }
          ਰੋਕੋ;

        ਹਾਲਤ CORE_CLASS:
          ਜੇ ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
            lexpand();
            gv(regmask(pplan->ਸਿਰਾ));
            pplan->sval->r2 = vtop->r;
            vtop--;
          }
          gv(regmask(pplan->ਸ਼ੁਰੂ));
          /* Mark register as used so that gcall_or_jmp use another one
             (regs >=4 are free as never used to pass parameters) */
          pplan->sval->r = vtop->r;
          ਰੋਕੋ;
      }
      vtop--;
    }
  }

  /* second pass to restore registers that were saved on stack by accident.
     Maybe redundant after the "lvalue_save" patch in tccgen.c:gv() */
  ਜੇ (++pass < 2)
    ਜਾਓ again;

  ਜੇ(todo) {
    o(0xE8BD0000|todo); /* pop {todo} */
    ਲਈ(pplan = plan->clsplans[CORE_STRUCT_CLASS]; pplan; pplan = pplan->prev) {
      ਪੂਰਨ r;
      pplan->sval->r = pplan->ਸ਼ੁਰੂ;
      /* An SValue can only pin 2 registers at best (r and r2) but a structure
         can occupy more than 2 registers. Thus, we need to push on the value
         stack some fake parameter to have on SValue for each registers used
         by a structure (r2 is not used). */
      ਲਈ (r = pplan->ਸ਼ੁਰੂ + 1; r <= pplan->ਸਿਰਾ; r++) {
        ਜੇ (todo & (1 << r)) {
          nb_extra_sval++;
          vpushi(0);
          vtop->r = r;
        }
      }
    }
  }
  ਵਾਪਸ nb_extra_sval;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
ਖਾਲੀ gfunc_call(ਪੂਰਨ nb_ਦਲੀਲਾਂ)
{
  ਪੂਰਨ ਦਲੀਲਾਂ_ਮਾਪ;
  ਪੂਰਨ def_float_abi = float_abi;
  ਪੂਰਨ todo;
  ਬਣਤਰ plan plan;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
  ਪੂਰਨ variadic;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
  ਜੇ (tcc_state->do_bounds_check)
    gbound_ਦਲੀਲਾਂ(nb_ਦਲੀਲਾਂ);
#ਜੇ_ਅੰਤ

  save_regs(nb_ਦਲੀਲਾਂ + 1);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
  ਜੇ (float_abi == ARM_HARD_FLOAT) {
    variadic = (vtop[-nb_ਦਲੀਲਾਂ].type.ref->f.func_type == FUNC_ELLIPSIS);
    ਜੇ (variadic || floats_ਵਿੱਚ_core_regs(&vtop[-nb_ਦਲੀਲਾਂ]))
      float_abi = ARM_SOFTFP_FLOAT;
  }
#ਜੇ_ਅੰਤ

  memset(&plan, 0, ਆਕਾਰ plan);
  ਜੇ (nb_ਦਲੀਲਾਂ)
    plan.pplans = tcc_malloc(nb_ਦਲੀਲਾਂ * ਆਕਾਰ(*plan.pplans));

  ਦਲੀਲਾਂ_ਮਾਪ = ਸੌਂਪੋ_regs(nb_ਦਲੀਲਾਂ, float_abi, &plan, &todo);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
  ਜੇ (ਦਲੀਲਾਂ_ਮਾਪ & 7) { /* Stack must be 8 byte aligned at fct call for EABI */
    ਦਲੀਲਾਂ_ਮਾਪ = (ਦਲੀਲਾਂ_ਮਾਪ + 7) & ~7;
    o(0xE24DD004); /* sub sp, sp, #4 */
  }
#ਜੇ_ਅੰਤ

  nb_ਦਲੀਲਾਂ += copy_params(nb_ਦਲੀਲਾਂ, &plan, todo);
  tcc_free(plan.pplans);

  /* Move fct SValue on top as required by gcall_or_jmp */
  vrotb(nb_ਦਲੀਲਾਂ + 1);
  gcall_or_jmp(0);
  ਜੇ (ਦਲੀਲਾਂ_ਮਾਪ)
      gadd_sp(ਦਲੀਲਾਂ_ਮਾਪ); /* pop all parameters passed on the stack */
#ਜੇ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  ਜੇ(float_abi == ARM_SOFTFP_FLOAT && is_float(vtop->type.ref->type.t)) {
    ਜੇ((vtop->type.ref->type.t & VT_BTYPE) == VT_FLOAT) {
      o(0xEE000A10); /*vmov s0, r0 */
    } ਨਹੀਂਤਾਂ {
      o(0xEE000B10); /* vmov.32 d0[0], r0 */
      o(0xEE201B10); /* vmov.32 d0[1], r1 */
    }
  }
#ਜੇ_ਅੰਤ
  vtop -= nb_ਦਲੀਲਾਂ + 1; /* Pop all params and fct address from value stack */
  leaffunc = 0; /* we are calling a function, so we aren't in a leaf function */
  float_abi = def_float_abi;
}

/* generate function prolog of type 't' */
ਖਾਲੀ gfunc_prolog(Sym *func_sym)
{
  CType *func_type = &func_sym->type;
  Sym *sym,*sym2;
  ਪੂਰਨ n, nf, ਮਾਪ, align, rs, struct_ret = 0;
  ਪੂਰਨ addr, pn, sn; /* pn=core, sn=stack */
  CType ret_type;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
  ਬਣਤਰ avail_regs avregs = {{0}};
#ਜੇ_ਅੰਤ

  sym = func_type->ref;

  n = nf = 0;
  ਜੇ ((func_vt.t & VT_BTYPE) == VT_STRUCT &&
      !gfunc_sret(&func_vt, func_var, &ret_type, &align, &rs))
  {
    n++;
    struct_ret = 1;
    func_vc = 12; /* Offset from fp of the place to store the result */
  }
  ਲਈ(sym2 = sym->ਅਗਲਾ; sym2 && (n < 4 || nf < 16); sym2 = sym2->ਅਗਲਾ) {
    ਮਾਪ = type_ਮਾਪ(&sym2->type, &align);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
    ਜੇ (float_abi == ARM_HARD_FLOAT && !func_var &&
        (is_float(sym2->type.t) || is_hgen_float_aggr(&sym2->type))) {
      ਪੂਰਨ tmpnf = ਸੌਂਪੋ_vfpreg(&avregs, align, ਮਾਪ);
      tmpnf += (ਮਾਪ + 3) / 4;
      nf = (tmpnf > nf) ? tmpnf : nf;
    } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
    ਜੇ (n < 4)
      n += (ਮਾਪ + 3) / 4;
  }
  o(0xE1A0C00D); /* mov ip,sp */
  ਜੇ (func_var)
    n=4;
  ਜੇ (n) {
    ਜੇ(n>4)
      n=4;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
    n=(n+1)&-2;
#ਜੇ_ਅੰਤ
    o(0xE92D0000|((1<<n)-1)); /* save r0-r4 on stack if needed */
  }
  ਜੇ (nf) {
    ਜੇ (nf>16)
      nf=16;
    nf=(nf+1)&-2; /* nf => HARDFLOAT => EABI */
    o(0xED2D0A00|nf); /* save s0-s15 on stack if needed */
  }
  o(0xE92D5800); /* save fp, ip, lr */
  o(0xE1A0B00D); /* mov fp, sp */
  func_sub_sp_ਵਿੱਥ = ind;
  o(0xE1A00000); /* nop, leave space for stack adjustment in epilog */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
  ਜੇ (float_abi == ARM_HARD_FLOAT) {
    func_vc += nf * 4;
    memset(&avregs, 0, ਆਕਾਰ avregs);
  }
#ਜੇ_ਅੰਤ
  pn = struct_ret, sn = 0;
  ਜਦੋਂ ((sym = sym->ਅਗਲਾ)) {
    CType *type;
    type = &sym->type;
    ਮਾਪ = type_ਮਾਪ(type, &align);
    ਮਾਪ = (ਮਾਪ + 3) >> 2;
    align = (align + 3) & ~3;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
    ਜੇ (float_abi == ARM_HARD_FLOAT && !func_var && (is_float(sym->type.t)
        || is_hgen_float_aggr(&sym->type))) {
      ਪੂਰਨ fpn = ਸੌਂਪੋ_vfpreg(&avregs, align, ਮਾਪ << 2);
      ਜੇ (fpn >= 0)
        addr = fpn * 4;
      ਨਹੀਂਤਾਂ
        ਜਾਓ from_ਢੇਰ;
    } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
    ਜੇ (pn < 4) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
        pn = (pn + (align-1)/4) & -(align/4);
#ਜੇ_ਅੰਤ
      addr = (nf + pn) * 4;
      pn += ਮਾਪ;
      ਜੇ (!sn && pn > 4)
        sn = (pn - 4);
    } ਨਹੀਂਤਾਂ {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
from_ਢੇਰ:
        sn = (sn + (align-1)/4) & -(align/4);
#ਜੇ_ਅੰਤ
      addr = (n + nf + sn) * 4;
      sn += ਮਾਪ;
    }
    gfunc_ਸੈੱਟ_param(sym, addr + 12, 0);
  }
  ਆਖਰੀ_itod_magic=0;
  leaffunc = 1;
  loc = 0;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
  ਜੇ (tcc_state->do_bounds_check)
    gen_bounds_prolog();
#ਜੇ_ਅੰਤ
}

/* generate function epilog */
ਖਾਲੀ gfunc_epilog(ਖਾਲੀ)
{
  uint32_t x;
  ਪੂਰਨ diff;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
  ਜੇ (tcc_state->do_bounds_check)
    gen_bounds_epilog();
#ਜੇ_ਅੰਤ
  /* Copy float return value to core register if base standard is used and
     float computation is made with VFP */
#ਜੇ defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  ਜੇ ((float_abi == ARM_SOFTFP_FLOAT || func_var) && is_float(func_vt.t)) {
    ਜੇ((func_vt.t & VT_BTYPE) == VT_FLOAT)
      o(0xEE100A10); /* fmrs r0, s0 */
    ਨਹੀਂਤਾਂ {
      o(0xEE100B10); /* fmrdl r0, d0 */
      o(0xEE301B10); /* fmrdh r1, d0 */
    }
  }
#ਜੇ_ਅੰਤ
  o(0xE89BA800); /* restore fp, sp, pc */
  diff = (-loc + 3) & -4;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
  ਜੇ(!leaffunc)
    diff = ((diff + 11) & -8) - 4;
#ਜੇ_ਅੰਤ
  ਜੇ(diff > 0) {
    x=stuff_const(0xE24BD000, diff); /* sub sp,fp,# */
    ਜੇ(x)
      *(uint32_t *)(cur_ਪਾਠ_section->ਅੰਕੜੇ + func_sub_sp_ਵਿੱਥ) = x;
    ਨਹੀਂਤਾਂ {
      ਪੂਰਨ addr;
      addr=ind;
      o(0xE59FC004); /* ldr ip,[pc+4] */
      o(0xE04BD00C); /* sub sp,fp,ip  */
      o(0xE1A0F00E); /* mov pc,lr */
      o(diff);
      *(uint32_t *)(cur_ਪਾਠ_section->ਅੰਕੜੇ + func_sub_sp_ਵਿੱਥ) = 0xE1000000|encbranch(func_sub_sp_ਵਿੱਥ,addr,1);
    }
  }
}

ST_FUNC ਖਾਲੀ gen_fill_nops(ਪੂਰਨ ਬਾਈਟਾਂ)
{
    ਜੇ ((ਬਾਈਟਾਂ & 3))
      tcc_error("alignment of code section not multiple of 4");
    ਜਦੋਂ (ਬਾਈਟਾਂ > 0) {
	o(0xE1A00000);
	ਬਾਈਟਾਂ -= 4;
    }
}

/* generate a jump to a label */
ST_FUNC ਪੂਰਨ gjmp(ਪੂਰਨ t)
{
  ਪੂਰਨ r;
  ਜੇ (nocode_wanted)
    ਵਾਪਸ t;
  r=ind;
  o(0xE0000000|encbranch(r,t,1));
  ਵਾਪਸ r;
}

/* generate a jump to a fixed address */
ST_FUNC ਖਾਲੀ gjmp_addr(ਪੂਰਨ a)
{
  gjmp(a);
}

ST_FUNC ਪੂਰਨ gjmp_cond(ਪੂਰਨ op, ਪੂਰਨ t)
{
  ਪੂਰਨ r;
  ਜੇ (nocode_wanted)
    ਵਾਪਸ t;
  r=ind;
  op=mapcc(op);
  op|=encbranch(r,t,1);
  o(op);
  ਵਾਪਸ r;
}

ST_FUNC ਪੂਰਨ gjmp_append(ਪੂਰਨ n, ਪੂਰਨ t)
{
  uint32_t *x;
  ਪੂਰਨ p,lp;
  ਜੇ(n) {
    p = n;
    ਕਰੋ {
      p = decbranch(lp=p);
    } ਜਦੋਂ(p);
    x = (uint32_t *)(cur_ਪਾਠ_section->ਅੰਕੜੇ + lp);
    *x &= 0xff000000;
    *x |= encbranch(lp,t,1);
    t = n;
  }
  ਵਾਪਸ t;
}

/* generate an integer binary operation */
ਖਾਲੀ gen_opi(ਪੂਰਨ op)
{
  ਪੂਰਨ c, func = 0;
  uint32_t opc = 0, r, fr;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ retreg = REG_IRET;

  c=0;
  ਚੋਣ(op) {
    ਹਾਲਤ '+':
      opc = 0x8;
      c=1;
      ਰੋਕੋ;
    ਹਾਲਤ TOK_ADDC1: /* add with carry generation */
      opc = 0x9;
      c=1;
      ਰੋਕੋ;
    ਹਾਲਤ '-':
      opc = 0x4;
      c=1;
      ਰੋਕੋ;
    ਹਾਲਤ TOK_SUBC1: /* sub with carry generation */
      opc = 0x5;
      c=1;
      ਰੋਕੋ;
    ਹਾਲਤ TOK_ADDC2: /* add with carry use */
      opc = 0xA;
      c=1;
      ਰੋਕੋ;
    ਹਾਲਤ TOK_SUBC2: /* sub with carry use */
      opc = 0xC;
      c=1;
      ਰੋਕੋ;
    ਹਾਲਤ '&':
      opc = 0x0;
      c=1;
      ਰੋਕੋ;
    ਹਾਲਤ '^':
      opc = 0x2;
      c=1;
      ਰੋਕੋ;
    ਹਾਲਤ '|':
      opc = 0x18;
      c=1;
      ਰੋਕੋ;
    ਹਾਲਤ '*':
      gv2(RC_INT, RC_INT);
      r = vtop[-1].r;
      fr = vtop[0].r;
      vtop--;
      o(0xE0000090|(intr(r)<<16)|(intr(r)<<8)|intr(fr));
      ਵਾਪਸ;
    ਹਾਲਤ TOK_SHL:
      opc = 0;
      c=2;
      ਰੋਕੋ;
    ਹਾਲਤ TOK_SHR:
      opc = 1;
      c=2;
      ਰੋਕੋ;
    ਹਾਲਤ TOK_SAR:
      opc = 2;
      c=2;
      ਰੋਕੋ;
    ਹਾਲਤ '/':
    ਹਾਲਤ TOK_PDIV:
      func=TOK___divsi3;
      c=3;
      ਰੋਕੋ;
    ਹਾਲਤ TOK_UDIV:
      func=TOK___udivsi3;
      c=3;
      ਰੋਕੋ;
    ਹਾਲਤ '%':
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
      func=TOK___aeabi_idivmod;
      retreg=REG_IRE2;
#ਨਹੀਂਤਾਂ
      func=TOK___modsi3;
#ਜੇ_ਅੰਤ
      c=3;
      ਰੋਕੋ;
    ਹਾਲਤ TOK_UMOD:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
      func=TOK___aeabi_uidivmod;
      retreg=REG_IRE2;
#ਨਹੀਂਤਾਂ
      func=TOK___umodsi3;
#ਜੇ_ਅੰਤ
      c=3;
      ਰੋਕੋ;
    ਹਾਲਤ TOK_UMULL:
      gv2(RC_INT, RC_INT);
      r=intr(vtop[-1].r2=get_reg(RC_INT));
      c=vtop[-1].r;
      vtop[-1].r=get_reg_ex(RC_INT,regmask(c));
      vtop--;
      o(0xE0800090|(r<<16)|(intr(vtop->r)<<12)|(intr(c)<<8)|intr(vtop[1].r));
      ਵਾਪਸ;
    ਮੂਲ:
      opc = 0x15;
      c=1;
      ਰੋਕੋ;
  }
  ਚੋਣ(c) {
    ਹਾਲਤ 1:
      ਜੇ((vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	ਜੇ(opc == 4 || opc == 5 || opc == 0xc) {
	  vswap();
	  opc|=2; // sub -> rsb
	}
      }
      vswap();
      c=intr(gv(RC_INT));
      vswap();
      opc=0xE0000000|(opc<<20);
      ਜੇ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	uint32_t x;
	x=stuff_const(opc|0x2000000|(c<<16),vtop->c.i);
	ਜੇ(x) {
	  ਜੇ ((x & 0xfff00000) == 0xe3500000)   // cmp rx,#c
	    o(x);
	  ਨਹੀਂਤਾਂ {
	    r=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	    o(x|(r<<12));
	  }
	  ਜਾਓ ਪੂਰਾ;
	}
      }
      fr=intr(gv(RC_INT));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
      ਜੇ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
        vswap();
        c=intr(gv(RC_INT));
        vswap();
      }
#ਜੇ_ਅੰਤ
      ਜੇ ((opc & 0xfff00000) == 0xe1500000) // cmp rx,ry
	o(opc|(c<<16)|fr);
      ਨਹੀਂਤਾਂ {
        r=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
        o(opc|(c<<16)|(r<<12)|fr);
      }
ਪੂਰਾ:
      vtop--;
      ਜੇ (op >= TOK_ULT && op <= TOK_GT)
        vset_VT_CMP(op);
      ਰੋਕੋ;
    ਹਾਲਤ 2:
      opc=0xE1A00000|(opc<<5);
      vswap();
      r=intr(gv(RC_INT));
      vswap();
      ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	fr=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	c = vtop->c.i & 0x1f;
	o(opc|r|(c<<7)|(fr<<12));
      } ਨਹੀਂਤਾਂ {
        fr=intr(gv(RC_INT));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=intr(gv(RC_INT));
          vswap();
        }
#ਜੇ_ਅੰਤ
	c=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
	o(opc|r|(c<<12)|(fr<<8)|0x10);
      }
      vtop--;
      ਰੋਕੋ;
    ਹਾਲਤ 3:
      vpush_helper_func(func);
      vrott(3);
      gfunc_call(2);
      vpushi(0);
      vtop->r = retreg;
      ਰੋਕੋ;
    ਮੂਲ:
      tcc_error("gen_opi %i unimplemented!",op);
  }
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
ਸਥਿਰ ਪੂਰਨ is_zero(ਪੂਰਨ i)
{
  ਜੇ((vtop[i].r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    ਵਾਪਸ 0;
  ਜੇ (vtop[i].type.t == VT_FLOAT)
    ਵਾਪਸ (vtop[i].c.f == 0.f);
  ਨਹੀਂਤਾਂ ਜੇ (vtop[i].type.t == VT_DOUBLE)
    ਵਾਪਸ (vtop[i].c.d == 0.0);
  ਵਾਪਸ (vtop[i].c.ld == 0.l);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
 *    two operands are guaranteed to have the same floating point type */
ਖਾਲੀ gen_opf(ਪੂਰਨ op)
{
  uint32_t x;
  ਪੂਰਨ fneg=0,r;
  x=0xEE000A00|T2CPR(vtop->type.t);
  ਚੋਣ(op) {
    ਹਾਲਤ '+':
      ਜੇ(is_zero(-1))
        vswap();
      ਜੇ(is_zero(0)) {
        vtop--;
        ਵਾਪਸ;
      }
      x|=0x300000;
      ਰੋਕੋ;
    ਹਾਲਤ '-':
      x|=0x300040;
      ਜੇ(is_zero(0)) {
        vtop--;
        ਵਾਪਸ;
      }
      ਜੇ(is_zero(-1)) {
        x|=0x810000; /* fsubX -> fnegX */
        vswap();
        vtop--;
        fneg=1;
      }
      ਰੋਕੋ;
    ਹਾਲਤ '*':
      x|=0x200000;
      ਰੋਕੋ;
    ਹਾਲਤ '/':
      x|=0x800000;
      ਰੋਕੋ;
    ਮੂਲ:
      ਜੇ(op < TOK_ULT || op > TOK_GT) {
        tcc_error("unknown fp op %x!",op);
        ਵਾਪਸ;
      }
      ਜੇ(is_zero(-1)) {
        vswap();
        ਚੋਣ(op) {
          ਹਾਲਤ TOK_LT: op=TOK_GT; ਰੋਕੋ;
          ਹਾਲਤ TOK_GE: op=TOK_ULE; ਰੋਕੋ;
          ਹਾਲਤ TOK_LE: op=TOK_GE; ਰੋਕੋ;
          ਹਾਲਤ TOK_GT: op=TOK_ULT; ਰੋਕੋ;
        }
      }
      x|=0xB40040; /* fcmpX */
      ਜੇ(op!=TOK_EQ && op!=TOK_NE)
        x|=0x80; /* fcmpX -> fcmpeX */
      ਜੇ(is_zero(0)) {
        vtop--;
        o(x|0x10000|(vfpr(gv(RC_FLOAT))<<12)); /* fcmp(e)X -> fcmp(e)zX */
      } ਨਹੀਂਤਾਂ {
        gv2(RC_FLOAT,RC_FLOAT);
        x|=vfpr(vtop[0].r);
        o(x|(vfpr(vtop[-1].r) << 12));
        vtop--;
      }
      o(0xEEF1FA10); /* fmstat */

      ਚੋਣ(op) {
        ਹਾਲਤ TOK_LE: op=TOK_ULE; ਰੋਕੋ;
        ਹਾਲਤ TOK_LT: op=TOK_ULT; ਰੋਕੋ;
        ਹਾਲਤ TOK_UGE: op=TOK_GE; ਰੋਕੋ;
        ਹਾਲਤ TOK_UGT: op=TOK_GT; ਰੋਕੋ;
      }
      vset_VT_CMP(op);
      ਵਾਪਸ;
  }
  r=gv(RC_FLOAT);
  x|=vfpr(r);
  r=regmask(r);
  ਜੇ(!fneg) {
    ਪੂਰਨ r2;
    vswap();
    r2=gv(RC_FLOAT);
    x|=vfpr(r2)<<16;
    r|=regmask(r2);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
      vswap();
      r=gv(RC_FLOAT);
      vswap();
      x=(x&~0xf)|vfpr(r);
    }
#ਜੇ_ਅੰਤ
  }
  vtop->r=get_reg_ex(RC_FLOAT,r);
  ਜੇ(!fneg)
    vtop--;
  o(x|(vfpr(vtop->r)<<12));
}

#ਨਹੀਂਤਾਂ
ਸਥਿਰ uint32_t is_fconst()
{
  ਲੰਮਾ ਦੁੱਗਣਾ f;
  uint32_t r;
  ਜੇ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    ਵਾਪਸ 0;
  ਜੇ (vtop->type.t == VT_FLOAT)
    f = vtop->c.f;
  ਨਹੀਂਤਾਂ ਜੇ (vtop->type.t == VT_DOUBLE)
    f = vtop->c.d;
  ਨਹੀਂਤਾਂ
    f = vtop->c.ld;
  ਜੇ(!ieee_finite(f))
    ਵਾਪਸ 0;
  r=0x8;
  ਜੇ(f<0.0) {
    r=0x18;
    f=-f;
  }
  ਜੇ(f==0.0)
    ਵਾਪਸ r;
  ਜੇ(f==1.0)
    ਵਾਪਸ r|1;
  ਜੇ(f==2.0)
    ਵਾਪਸ r|2;
  ਜੇ(f==3.0)
    ਵਾਪਸ r|3;
  ਜੇ(f==4.0)
    ਵਾਪਸ r|4;
  ਜੇ(f==5.0)
    ਵਾਪਸ r|5;
  ਜੇ(f==0.5)
    ਵਾਪਸ r|6;
  ਜੇ(f==10.0)
    ਵਾਪਸ r|7;
  ਵਾਪਸ 0;
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
ਖਾਲੀ gen_opf(ਪੂਰਨ op)
{
  uint32_t x, r, r2, c1, c2;
  //fputs("gen_opf\n",stderr);
  vswap();
  c1 = is_fconst();
  vswap();
  c2 = is_fconst();
  x=0xEE000100;
  ਜੇ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
    x|=0x80;
#ਜੇ LDOUBLE_ਮਾਪ != 8
  ਨਹੀਂਤਾਂ ਜੇ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE)
    x|=0x80000;
#ਜੇ_ਅੰਤ

  ਚੋਣ(op)
  {
    ਹਾਲਤ '+':
      ਜੇ(!c2) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      ਜੇ(c2) {
	ਜੇ(c2>0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
      } ਨਹੀਂਤਾਂ {
	r2=fpr(gv(RC_FLOAT));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#ਜੇ_ਅੰਤ
      }
      ਰੋਕੋ;
    ਹਾਲਤ '-':
      ਜੇ(c2) {
	ਜੇ(c2<=0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ਨਹੀਂਤਾਂ ਜੇ(c1 && c1<=0xf) {
	x|=0x300000; // rsf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ਨਹੀਂਤਾਂ {
	x|=0x200000; // suf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#ਜੇ_ਅੰਤ
      }
      ਰੋਕੋ;
    ਹਾਲਤ '*':
      ਜੇ(!c2 || c2>0xf) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      ਜੇ(c2 && c2<=0xf)
	r2=c2;
      ਨਹੀਂਤਾਂ {
	r2=fpr(gv(RC_FLOAT));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#ਜੇ_ਅੰਤ
      }
      x|=0x100000; // muf
      ਰੋਕੋ;
    ਹਾਲਤ '/':
      ਜੇ(c2 && c2<=0xf) {
	x|=0x400000; // dvf
	r2=c2;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ਨਹੀਂਤਾਂ ਜੇ(c1 && c1<=0xf) {
	x|=0x500000; // rdf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ਨਹੀਂਤਾਂ {
	x|=0x400000; // dvf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#ਜੇ_ਅੰਤ
      }
      ਰੋਕੋ;
    ਮੂਲ:
      ਜੇ(op >= TOK_ULT && op <= TOK_GT) {
	x|=0xd0f110; // cmfe
/* bug (intention?) in Linux FPU emulator
   doesn't set carry if equal */
	ਚੋਣ(op) {
	  ਹਾਲਤ TOK_ULT:
	  ਹਾਲਤ TOK_UGE:
	  ਹਾਲਤ TOK_ULE:
	  ਹਾਲਤ TOK_UGT:
            tcc_error("unsigned comparison on floats?");
	    ਰੋਕੋ;
	  ਹਾਲਤ TOK_LT:
            op=TOK_Nset;
	    ਰੋਕੋ;
	  ਹਾਲਤ TOK_LE:
            op=TOK_ULE; /* correct in unordered case only if AC bit in FPSR set */
	    ਰੋਕੋ;
	  ਹਾਲਤ TOK_EQ:
	  ਹਾਲਤ TOK_NE:
	    x&=~0x400000; // cmfe -> cmf
	    ਰੋਕੋ;
	}
	ਜੇ(c1 && !c2) {
	  c2=c1;
	  vswap();
	  ਚੋਣ(op) {
            ਹਾਲਤ TOK_Nset:
              op=TOK_GT;
	      ਰੋਕੋ;
            ਹਾਲਤ TOK_GE:
	      op=TOK_ULE;
	      ਰੋਕੋ;
	    ਹਾਲਤ TOK_ULE:
              op=TOK_GE;
	      ਰੋਕੋ;
            ਹਾਲਤ TOK_GT:
              op=TOK_Nset;
	      ਰੋਕੋ;
	  }
	}
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	ਜੇ(c2) {
	  ਜੇ(c2>0xf)
	    x|=0x200000;
	  r2=c2&0xf;
	} ਨਹੀਂਤਾਂ {
	  r2=fpr(gv(RC_FLOAT));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
          ਜੇ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            r=fpr(gv(RC_FLOAT));
            vswap();
          }
#ਜੇ_ਅੰਤ
	}
        --vtop;
        vset_VT_CMP(op);
        ++vtop;
      } ਨਹੀਂਤਾਂ {
        tcc_error("unknown fp op %x!",op);
	ਵਾਪਸ;
      }
  }
  ਜੇ(vtop[-1].r == VT_CMP)
    c1=15;
  ਨਹੀਂਤਾਂ {
    c1=vtop->r;
    ਜੇ(r2&0x8)
      c1=vtop[-1].r;
    vtop[-1].r=get_reg_ex(RC_FLOAT,two2mask(vtop[-1].r,c1));
    c1=fpr(vtop[-1].r);
  }
  vtop--;
  o(x|(r<<16)|(c1<<12)|r2);
}
#ਜੇ_ਅੰਤ

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ST_FUNC ਖਾਲੀ gen_cvt_itof(ਪੂਰਨ t)
{
  uint32_t r, r2;
  ਪੂਰਨ bt;
  bt=vtop->type.t & VT_BTYPE;
  ਜੇ(bt == VT_INT || bt == VT_SHORT || bt == VT_BYTE) {
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
    uint32_t dsize = 0;
#ਜੇ_ਅੰਤ
    r=intr(gv(RC_INT));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
    r2=vfpr(vtop->r=get_reg(RC_FLOAT));
    o(0xEE000A10|(r<<12)|(r2<<16)); /* fmsr */
    r2|=r2<<12;
    ਜੇ(!(vtop->type.t & VT_UNSIGNED))
      r2|=0x80;                /* fuitoX -> fsituX */
    o(0xEEB80A40|r2|T2CPR(t)); /* fYitoX*/
#ਨਹੀਂਤਾਂ
    r2=fpr(vtop->r=get_reg(RC_FLOAT));
    ਜੇ((t & VT_BTYPE) != VT_FLOAT)
      dsize=0x80;    /* flts -> fltd */
    o(0xEE000110|dsize|(r2<<16)|(r<<12)); /* flts */
    ਜੇ((vtop->type.t & (VT_UNSIGNED|VT_BTYPE)) == (VT_UNSIGNED|VT_INT)) {
      uint32_t off = 0;
      o(0xE3500000|(r<<12));        /* cmp */
      r=fpr(get_reg(RC_FLOAT));
      ਜੇ(ਆਖਰੀ_itod_magic) {
	off=ind+8-ਆਖਰੀ_itod_magic;
	off/=4;
	ਜੇ(off>255)
	  off=0;
      }
      o(0xBD1F0100|(r<<12)|off);    /* ldflts */
      ਜੇ(!off) {
        o(0xEA000000);              /* b */
        ਆਖਰੀ_itod_magic=ind;
        o(0x4F800000);              /* 4294967296.0f */
      }
      o(0xBE000100|dsize|(r2<<16)|(r2<<12)|r); /* adflt */
    }
#ਜੇ_ਅੰਤ
    ਵਾਪਸ;
  } ਨਹੀਂਤਾਂ ਜੇ(bt == VT_LLONG) {
    ਪੂਰਨ func;
    CType *func_type = 0;
    ਜੇ((t & VT_BTYPE) == VT_FLOAT) {
      func_type = &func_float_type;
      ਜੇ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundisf;
      ਨਹੀਂਤਾਂ
        func=TOK___floatdisf;
    } ਨਹੀਂਤਾਂ ਜੇ((t & VT_BTYPE) == VT_DOUBLE) {
      func_type = &func_double_type;
      ਜੇ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundidf;
      ਨਹੀਂਤਾਂ
        func=TOK___floatdidf;
#ਜੇ LDOUBLE_ਮਾਪ != 8
    } ਨਹੀਂਤਾਂ ਜੇ((t & VT_BTYPE) == VT_LDOUBLE) {
      func_type = &func_ldouble_type;
      ਜੇ(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundixf;
      ਨਹੀਂਤਾਂ
        func=TOK___floatdixf;
#ਜੇ_ਅੰਤ
    }
    ਜੇ(func_type) {
      vpushsym(func_type, external_helper_sym(func));
      vswap();
      gfunc_call(1);
      vpushi(0);
      vtop->r=TREG_F0;
      ਵਾਪਸ;
    }
  }
  tcc_error("unimplemented gen_cvt_itof %x!",vtop->type.t);
}

/* convert fp to int 't' type */
ਖਾਲੀ gen_cvt_ftoi(ਪੂਰਨ t)
{
  uint32_t r, r2;
  ਪੂਰਨ u, func = 0;
  u=t&VT_UNSIGNED;
  t&=VT_BTYPE;
  r2=vtop->type.t & VT_BTYPE;
  ਜੇ(t==VT_INT) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
    r=vfpr(gv(RC_FLOAT));
    u=u?0:0x10000;
    o(0xEEBC0AC0|(r<<12)|r|T2CPR(r2)|u); /* ftoXizY */
    r2=intr(vtop->r=get_reg(RC_INT));
    o(0xEE100A10|(r<<16)|(r2<<12));
    ਵਾਪਸ;
#ਨਹੀਂਤਾਂ
    ਜੇ(u) {
      ਜੇ(r2 == VT_FLOAT)
        func=TOK___fixunssfsi;
      ਨਹੀਂਤਾਂ ਜੇ(r2 == VT_DOUBLE)
	func=TOK___fixunsdfsi;
#ਜੇ LDOUBLE_ਮਾਪ != 8
      ਨਹੀਂਤਾਂ ਜੇ(r2 == VT_LDOUBLE)
	func=TOK___fixunsxfsi;
#ਜੇ_ਅੰਤ
    } ਨਹੀਂਤਾਂ {
      r=fpr(gv(RC_FLOAT));
      r2=intr(vtop->r=get_reg(RC_INT));
      o(0xEE100170|(r2<<12)|r);
      ਵਾਪਸ;
    }
#ਜੇ_ਅੰਤ
  } ਨਹੀਂਤਾਂ ਜੇ(t == VT_LLONG) { // unsigned handled in gen_cvt_ftoi1
    ਜੇ(r2 == VT_FLOAT)
      func=TOK___fixsfdi;
    ਨਹੀਂਤਾਂ ਜੇ(r2 == VT_DOUBLE)
      func=TOK___fixdfdi;
#ਜੇ LDOUBLE_ਮਾਪ != 8
    ਨਹੀਂਤਾਂ ਜੇ(r2 == VT_LDOUBLE)
      func=TOK___fixxfdi;
#ਜੇ_ਅੰਤ
  }
  ਜੇ(func) {
    vpush_helper_func(func);
    vswap();
    gfunc_call(1);
    vpushi(0);
    ਜੇ(t == VT_LLONG)
      vtop->r2 = REG_IRE2;
    vtop->r = REG_IRET;
    ਵਾਪਸ;
  }
  tcc_error("unimplemented gen_cvt_ftoi!");
}

/* convert from one floating point type to another */
ਖਾਲੀ gen_cvt_ftof(ਪੂਰਨ t)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_VFP
  uint32_t r = gv(RC_FLOAT);
  ਜੇ(((vtop->type.t & VT_BTYPE) == VT_FLOAT) != ((t & VT_BTYPE) == VT_FLOAT)) {
    r = vfpr(r);
    o(0xEEB70AC0|(r<<12)|r|T2CPR(vtop->type.t));
  }
#ਨਹੀਂਤਾਂ
  /* all we have to do on i386 and FPA ARM is to put the float in a register */
  gv(RC_FLOAT);
#ਜੇ_ਅੰਤ
}

/* increment tcov counter */
ST_FUNC ਖਾਲੀ gen_increment_tcov (SValue *sv)
{
  ਪੂਰਨ r1, r2;

  vpushv(sv);
  vtop->r = r1 = get_reg(RC_INT);
  r2 = get_reg(RC_INT);
  o(0xE59F0000 | (intr(r1)<<12)); // ldr r1,[pc]
  o(0xEA000000); // b $+4
  greloc(cur_ਪਾਠ_section, sv->sym, ind, R_ARM_REL32);
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
ਖਾਲੀ ggoto(ਖਾਲੀ)
{
  gcall_or_jmp(1);
  vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC ਖਾਲੀ gen_vla_sp_save(ਪੂਰਨ addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    store(TREG_SP, &v);
}

/* Restore the SP from a location on the stack */
ST_FUNC ਖਾਲੀ gen_vla_sp_restore(ਪੂਰਨ addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    ਲੱਦੋ(TREG_SP, &v);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC ਖਾਲੀ gen_vla_alloc(CType *type, ਪੂਰਨ align) {
    ਪੂਰਨ r;
#ਜੇ defined(CONFIG_TCC_BCHECK)
    ਜੇ (tcc_state->do_bounds_check)
        vpushv(vtop);
#ਜੇ_ਅੰਤ
    r = intr(gv(RC_INT));
#ਜੇ defined(CONFIG_TCC_BCHECK)
    ਜੇ (tcc_state->do_bounds_check)
        o(0xe2800001 | (r<<16)|(r<<12)); /* add r,r,#1 */
#ਜੇ_ਅੰਤ
    o(0xE04D0000|(r<<12)|r); /* sub r, sp, r */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
    ਜੇ (align < 8)
        align = 8;
#ਨਹੀਂਤਾਂ
    ਜੇ (align < 4)
        align = 4;
#ਜੇ_ਅੰਤ
    ਜੇ (align & (align - 1))
        tcc_error("alignment is not a power of 2: %i", align);
    o(stuff_const(0xE3C0D000|(r<<16), align - 1)); /* bic sp, r, #align-1 */
    vpop();
#ਜੇ defined(CONFIG_TCC_BCHECK)
    ਜੇ (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R0;
        o(0xe1a0000d | (vtop->r << 12)); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_ਜੋੜੋ_epilog = 1;
    }
#ਜੇ_ਅੰਤ
}

/* end of ARM code generator */
/*************************************************************/
#ਜੇ_ਅੰਤ
/*************************************************************/
