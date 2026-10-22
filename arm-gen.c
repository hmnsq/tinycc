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

#اگر_تعریف_شدہ ہدف_DEFS_ONLY

#اگر defined(TCC_ARM_EABI) && !defined(TCC_ARM_VFP)
#غلطی "Currently TinyCC only supports float computation with VFP instructions"
#اگر_ختم

/* number of available registers */
#اگر_تعریف_شدہ TCC_ARM_VFP
#تعریف_کرو NB_REGS            13
#ورنہ
#تعریف_کرو NB_REGS             9
#اگر_ختم

#اگر_غیر_تعریف_شدہ CONFIG_TCC_CPUVER
# define CONFIG_TCC_CPUVER 5
#اگر_ختم

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
#اگر_تعریف_شدہ TCC_ARM_VFP
#تعریف_کرو RC_F4      0x0800
#تعریف_کرو RC_F5      0x1000
#تعریف_کرو RC_F6      0x2000
#تعریف_کرو RC_F7      0x4000
#اگر_ختم
#تعریف_کرو RC_IRET    RC_R0  /* function return: integer register */
#تعریف_کرو RC_IRE2    RC_R1  /* function return: second integer register */
#تعریف_کرو RC_FRET    RC_F0  /* function return: float register */

/* pretty names for the registers */
شمار {
    TREG_R0 = 0,
    TREG_R1,
    TREG_R2,
    TREG_R3,
    TREG_R12,
    TREG_F0,
    TREG_F1,
    TREG_F2,
    TREG_F3,
#اگر_تعریف_شدہ TCC_ARM_VFP
    TREG_F4,
    TREG_F5,
    TREG_F6,
    TREG_F7,
#اگر_ختم
    TREG_SP = 13,
    TREG_LR,
};

#اگر_تعریف_شدہ TCC_ARM_VFP
#تعریف_کرو T2CPR(t) (((t) & VT_BTYPE) != VT_FLOAT ? 0x100 : 0)
#اگر_ختم

/* return registers for function */
#تعریف_کرو REG_IRET TREG_R0 /* single word int return register */
#تعریف_کرو REG_IRE2 TREG_R1 /* second word return register (for long long) */
#تعریف_کرو REG_FRET TREG_F0 /* float return register */

#اگر_تعریف_شدہ TCC_ARM_EABI
#تعریف_کرو TOK___divdi3 TOK___aeabi_ldivmod
#تعریف_کرو TOK___moddi3 TOK___aeabi_ldivmod
#تعریف_کرو TOK___udivdi3 TOK___aeabi_uldivmod
#تعریف_کرو TOK___umoddi3 TOK___aeabi_uldivmod
#اگر_ختم

/* defined if function parameters must be evaluated in reverse order */
#تعریف_کرو INVERT_FUNC_PARAMS

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#تعریف_کرو PTR_سائز 4

/* long double size and alignment, in bytes */
#اگر_تعریف_شدہ TCC_ARM_VFP
#تعریف_کرو LDOUBLE_سائز  8
#اگر_ختم

#اگر_غیر_تعریف_شدہ LDOUBLE_سائز
#تعریف_کرو LDOUBLE_سائز  8
#اگر_ختم

#اگر_تعریف_شدہ TCC_ARM_EABI
#تعریف_کرو LDOUBLE_ALIGN 8
#ورنہ
#تعریف_کرو LDOUBLE_ALIGN 4
#اگر_ختم

#اگر LDOUBLE_سائز == 8
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#اگر_ختم

/* maximum alignment (for aligned attribute support) */
#تعریف_کرو MAX_ALIGN     8

#تعریف_کرو CHAR_IS_UNSIGNED

#تعریف_کرو ARM_SOFTFP_FLOAT 0
#تعریف_کرو ARM_HARD_FLOAT 1

/******************************************************/
#ورنہ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"

ST_ڈیٹا ثابت حرف * ثابت ہدف_machine_defs =
    "__arm__\0"
    "__arm\0"
    "arm\0"
    "__arm_elf__\0"
    "__arm_elf\0"
    "arm_elf\0"
    "__ARM_ARCH_4__\0"
    "__ARMEL__\0"
    "__APCS_32__\0"
#اگر defined TCC_ARM_EABI
    "__ARM_EABI__\0"
#اگر_ختم
    ;

ST_ڈیٹا ثابت صحیح reg_classes[NB_REGS] = {
    /* r0 */ RC_INT | RC_R0,
    /* r1 */ RC_INT | RC_R1,
    /* r2 */ RC_INT | RC_R2,
    /* r3 */ RC_INT | RC_R3,
    /* r12 */ RC_INT | RC_R12,
    /* f0 */ RC_FLOAT | RC_F0,
    /* f1 */ RC_FLOAT | RC_F1,
    /* f2 */ RC_FLOAT | RC_F2,
    /* f3 */ RC_FLOAT | RC_F3,
#اگر_تعریف_شدہ TCC_ARM_VFP
 /* d4/s8 */ RC_FLOAT | RC_F4,
/* d5/s10 */ RC_FLOAT | RC_F5,
/* d6/s12 */ RC_FLOAT | RC_F6,
/* d7/s14 */ RC_FLOAT | RC_F7,
#اگر_ختم
};

ساکن صحیح float_abi;
ساکن صحیح func_sub_sp_انحراف, آخری_itod_magic;
ساکن صحیح leaffunc;

#اگر defined(CONFIG_TCC_BCHECK)
ساکن addr_t func_bound_انحراف;
ساکن غیرعلامتی طویل func_bound_ind;
ST_ڈیٹا صحیح func_bound_جوڑو_epilog;
#اگر_ختم

#اگر defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
ساکن CType float_type, double_type, func_float_type, func_double_type;
ST_FUNC خالی arm_init(ساخت TCCState *s)
{
    float_type.t = VT_FLOAT;
    double_type.t = VT_DOUBLE;
    func_float_type.t = VT_FUNC;
    func_float_type.ref = sym_ڈالو(SYM_میدان, &float_type, FUNC_CDECL, FUNC_OLD);
    func_double_type.t = VT_FUNC;
    func_double_type.ref = sym_ڈالو(SYM_میدان, &double_type, FUNC_CDECL, FUNC_OLD);

    float_abi = s->float_abi;
#اگر_غیر_تعریف_شدہ TCC_ARM_HARDFLOAT
// XXX: Works on OpenBSD
// # warning "soft float ABI currently not supported: default to softfp"
#اگر_ختم
}
#ورنہ
#تعریف_کرو func_float_type func_old_type
#تعریف_کرو func_double_type func_old_type
#تعریف_کرو func_ldouble_type func_old_type
ST_FUNC خالی arm_init(ساخت TCCState *s)
{
#اگر 0
#اگر !defined (TCC_ARM_VFP)
    tcc_warning("Support for FPA is deprecated and will be removed in next"
                " release");
#اگر_ختم
#اگر !defined (TCC_ARM_EABI)
    tcc_warning("Support for OABI is deprecated and will be removed in next"
                " release");
#اگر_ختم
#اگر_ختم
}
#اگر_ختم

#تعریف_کرو CHECK_R(r) ((r) >= TREG_R0 && (r) <= TREG_LR)

ساکن صحیح two2mask(صحیح a,صحیح b) {
  اگر (!CHECK_R(a) || !CHECK_R(b))
    tcc_error("compiler error! registers %i,%i is not valid",a,b);
  واپس (reg_classes[a]|reg_classes[b])&~(RC_INT|RC_FLOAT);
}

ساکن صحیح regmask(صحیح r) {
  اگر (!CHECK_R(r))
    tcc_error("compiler error! register %i is not valid",r);
  واپس reg_classes[r]&~(RC_INT|RC_FLOAT);
}

/******************************************************/

خالی o(uint32_t i)
{
  /* this is a good place to start adding big-endian support*/
  صحیح ind1;
  اگر (nocode_wanted)
    واپس;
  ind1 = ind + 4;
  اگر (!cur_متن_section)
    tcc_error("compiler error! This happens f.ex. if the compiler\n"
         "can't evaluate constant expressions outside of a function.");
  اگر (ind1 > cur_متن_section->ڈیٹا_allocated)
    section_realloc(cur_متن_section, ind1);
  cur_متن_section->ڈیٹا[ind++] = i&255;
  i>>=8;
  cur_متن_section->ڈیٹا[ind++] = i&255;
  i>>=8;
  cur_متن_section->ڈیٹا[ind++] = i&255;
  i>>=8;
  cur_متن_section->ڈیٹا[ind++] = i;
}

ساکن uint32_t stuff_const(uint32_t op, uint32_t c)
{
  صحیح try_neg=0;
  uint32_t nc = 0, negop = 0;

  انتخاب(op&0x1F00000)
  {
    حالت 0x800000: //add
    حالت 0x400000: //sub
      try_neg=1;
      negop=op^0xC00000;
      nc=-c;
      توڑو;
    حالت 0x1A00000: //mov
    حالت 0x1E00000: //mvn
      try_neg=1;
      negop=op^0x400000;
      nc=~c;
      توڑو;
    حالت 0x200000: //xor
      اگر(c==~0)
	واپس (op&0xF010F000)|((op>>16)&0xF)|0x1E00000;
      توڑو;
    حالت 0x0: //and
      اگر(c==~0)
	واپس (op&0xF010F000)|((op>>16)&0xF)|0x1A00000;
    حالت 0x1C00000: //bic
      try_neg=1;
      negop=op^0x1C00000;
      nc=~c;
      توڑو;
    حالت 0x1800000: //orr
      اگر(c==~0)
	واپس (op&0xFFF0FFFF)|0x1E00000;
      توڑو;
  }
  کرو {
    uint32_t m;
    صحیح i;
    اگر(c<256) /* catch undefined <<32 */
      واپس op|c;
    برائے(i=2;i<32;i+=2) {
      m=(0xffu>>i)|(0xffu<<(32-i));
      اگر(!(c&~m))
	واپس op|(i<<7)|(c<<i)|(c>>(32-i));
    }
    op=negop;
    c=nc;
  } جب(try_neg--);
  واپس 0;
}


//only add,sub
خالی stuff_const_harder(uint32_t op, uint32_t v) {
  uint32_t x;
  x=stuff_const(op,v);
  اگر(x)
    o(x);
  ورنہ {
    uint32_t a[16], nv, no, o2, n2;
    صحیح i,j,k;
    a[0]=0xff;
    o2=(op&0xfff0ffff)|((op&0xf000)<<4);;
    برائے(i=1;i<16;i++)
      a[i]=(a[i-1]>>2)|(a[i-1]<<30);
    برائے(i=0;i<12;i++)
      برائے(j=i<4?i+12:15;j>=i+4;j--)
	اگر((v&(a[i]|a[j]))==v) {
	  o(stuff_const(op,v&a[i]));
	  o(stuff_const(o2,v&a[j]));
	  واپس;
	}
    no=op^0xC00000;
    n2=o2^0xC00000;
    nv=-v;
    برائے(i=0;i<12;i++)
      برائے(j=i<4?i+12:15;j>=i+4;j--)
	اگر((nv&(a[i]|a[j]))==nv) {
	  o(stuff_const(no,nv&a[i]));
	  o(stuff_const(n2,nv&a[j]));
	  واپس;
	}
    برائے(i=0;i<8;i++)
      برائے(j=i+4;j<12;j++)
	برائے(k=i<4?i+12:15;k>=j+4;k--)
	  اگر((v&(a[i]|a[j]|a[k]))==v) {
	    o(stuff_const(op,v&a[i]));
	    o(stuff_const(o2,v&a[j]));
	    o(stuff_const(o2,v&a[k]));
	    واپس;
	  }
    no=op^0xC00000;
    nv=-v;
    برائے(i=0;i<8;i++)
      برائے(j=i+4;j<12;j++)
	برائے(k=i<4?i+12:15;k>=j+4;k--)
	  اگر((nv&(a[i]|a[j]|a[k]))==nv) {
	    o(stuff_const(no,nv&a[i]));
	    o(stuff_const(n2,nv&a[j]));
	    o(stuff_const(n2,nv&a[k]));
	    واپس;
	  }
    o(stuff_const(op,v&a[0]));
    o(stuff_const(o2,v&a[4]));
    o(stuff_const(o2,v&a[8]));
    o(stuff_const(o2,v&a[12]));
  }
}

uint32_t encbranch(صحیح pos, صحیح addr, صحیح fail)
{
  addr-=pos+8;
  addr/=4;
  اگر(addr>=0x1000000 || addr<-0x1000000) {
    اگر(fail)
      tcc_error("FIXME: function bigger than 32MB");
    واپس 0;
  }
  واپس 0x0A000000|(addr&0xffffff);
}

صحیح decbranch(صحیح pos)
{
  صحیح x;
  x=*(uint32_t *)(cur_متن_section->ڈیٹا + pos);
  x&=0x00ffffff;
  اگر(x&0x800000)
    x-=0x1000000;
  واپس x*4+pos+8;
}

/* output a symbol and patch all calls to it */
خالی gsym_addr(صحیح t, صحیح a)
{
  uint32_t *x;
  صحیح lt;
  جب(t) {
    x=(uint32_t *)(cur_متن_section->ڈیٹا + t);
    t=decbranch(lt=t);
    اگر(a==lt+4)
      *x=0xE1A00000; // nop
    ورنہ {
      *x &= 0xff000000;
      *x |= encbranch(lt,a,1);
    }
  }
}

#اگر_تعریف_شدہ TCC_ARM_VFP
ساکن uint32_t vfpr(صحیح r)
{
  اگر(r<TREG_F0 || r>TREG_F7)
    tcc_error("compiler error! register %i is no vfp register",r);
  واپس r - TREG_F0;
}
#ورنہ
ساکن uint32_t fpr(صحیح r)
{
  اگر(r<TREG_F0 || r>TREG_F3)
    tcc_error("compiler error! register %i is no fpa register",r);
  واپس r - TREG_F0;
}
#اگر_ختم

ساکن uint32_t intr(صحیح r)
{
  اگر(r == TREG_R12)
    واپس 12;
  اگر(r >= TREG_R0 && r <= TREG_R3)
    واپس r - TREG_R0;
  اگر (!(r >= TREG_SP && r <= TREG_LR))
    tcc_error("compiler error! register %i is no int register",r);
  واپس r + (13 - TREG_SP);
}

ساکن خالی calcaddr(uint32_t *بنیاد, صحیح *off, صحیح *sgn, صحیح maxoff, غیرعلامتی سرکاؤ)
{
  اگر(*off>maxoff || *off&((1<<سرکاؤ)-1)) {
    uint32_t x, y;
    x=0xE280E000;
    اگر(*sgn)
      x=0xE240E000;
    x|=(*بنیاد)<<16;
    *بنیاد=14; // lr
    y=stuff_const(x,*off&~maxoff);
    اگر(y) {
      o(y);
      *off&=maxoff;
      واپس;
    }
    y=stuff_const(x,(*off+maxoff)&~maxoff);
    اگر(y) {
      o(y);
      *sgn=!*sgn;
      *off=((*off+maxoff)&~maxoff)-*off;
      واپس;
    }
    stuff_const_harder(x,*off&~maxoff);
    *off&=maxoff;
  }
}

ساکن uint32_t mapcc(صحیح cc)
{
  انتخاب(cc)
  {
    حالت TOK_ULT:
      واپس 0x30000000; /* CC/LO */
    حالت TOK_UGE:
      واپس 0x20000000; /* CS/HS */
    حالت TOK_EQ:
      واپس 0x00000000; /* EQ */
    حالت TOK_NE:
      واپس 0x10000000; /* NE */
    حالت TOK_ULE:
      واپس 0x90000000; /* LS */
    حالت TOK_UGT:
      واپس 0x80000000; /* HI */
    حالت TOK_Nset:
      واپس 0x40000000; /* MI */
    حالت TOK_Nclear:
      واپس 0x50000000; /* PL */
    حالت TOK_LT:
      واپس 0xB0000000; /* LT */
    حالت TOK_GE:
      واپس 0xA0000000; /* GE */
    حالت TOK_LE:
      واپس 0xD0000000; /* LE */
    حالت TOK_GT:
      واپس 0xC0000000; /* GT */
  }
  tcc_error("unexpected condition code");
  واپس 0xE0000000; /* AL */
}

ساکن صحیح negcc(صحیح cc)
{
  انتخاب(cc)
  {
    حالت TOK_ULT:
      واپس TOK_UGE;
    حالت TOK_UGE:
      واپس TOK_ULT;
    حالت TOK_EQ:
      واپس TOK_NE;
    حالت TOK_NE:
      واپس TOK_EQ;
    حالت TOK_ULE:
      واپس TOK_UGT;
    حالت TOK_UGT:
      واپس TOK_ULE;
    حالت TOK_Nset:
      واپس TOK_Nclear;
    حالت TOK_Nclear:
      واپس TOK_Nset;
    حالت TOK_LT:
      واپس TOK_GE;
    حالت TOK_GE:
      واپس TOK_LT;
    حالت TOK_LE:
      واپس TOK_GT;
    حالت TOK_GT:
      واپس TOK_LE;
  }
  tcc_error("unexpected condition code");
  واپس TOK_NE;
}

/* Load value into register r.
   Use relative/got addressing to avoid setting DT_TEXTREL */
ساکن خالی بھرو_قدر(SValue *sv, صحیح r)
{
#اگر CONFIG_TCC_CPUVER >= 7
    اگر (!(sv->r & VT_SYM)) {
        غیرعلامتی x=sv->c.i;
        o(0xE3000000|intr(r)<<12|(x&0xFFF)|(x<<4&0xF0000)); /* movw rx,#x(lo) */
        اگر (x&0xFFFF0000)
          o(0xE3400000|intr(r)<<12|(x>>16&0xFFF)|(x>>12&0xF0000)); /* movt rx,#x(hi) */
        واپس;
    }
#اگر_ختم
    o(0xE59F0000|(intr(r)<<12)); /* ldr r, [pc] */
    o(0xEA000000); /* b $+4 */
#اگر_غیر_تعریف_شدہ CONFIG_TCC_PIC
    اگر(sv->r & VT_SYM)
        greloc(cur_متن_section, sv->sym, ind, R_ARM_ABS32);
    o(sv->c.i);
#ورنہ
    اگر(sv->r & VT_SYM) {
	اگر (sv->sym->type.t & VT_STATIC) {
            greloc(cur_متن_section, sv->sym, ind, R_ARM_REL32);
            o(sv->c.i - 12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
        }
        ورنہ {
            greloc(cur_متن_section, sv->sym, ind, R_ARM_GOT_PREL);
            o(-12);
            o(0xe080000f | (intr(r)<<12) | (intr(r)<<16));  // add rx,rx,pc
            o(0xe5900000 | (intr(r)<<12) | (intr(r)<<16));  // ldr rx,[rx]
            اگر (sv->c.i)
              stuff_const_harder(0xe2800000 | (intr(r)<<12) | (intr(r)<<16),
                                 sv->c.i);
        }
    }
    ورنہ
        o(sv->c.i);
#اگر_ختم
}

/* load 'r' from value 'sv' */
خالی بھرو(صحیح r, SValue *sv)
{
  صحیح v, ft, fc, fr, sign;
  uint32_t op, بنیاد;
  SValue v1;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  اگر(fc>=0)
    sign=0;
  ورنہ {
    sign=1;
    fc=-(غیرعلامتی)fc;
  }

  v = fr & VT_VALMASK;
  اگر (fr & VT_LVAL) {

    اگر ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe510e000; /* ldr r, [lr, #0] */
        greloca(cur_متن_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        واپس;
    }

    بنیاد = 0xB; // fp
    اگر(v == VT_LLOCAL) {
      v1.type.t = VT_PTR;
      v1.r = VT_LOCAL | VT_LVAL;
      v1.c.i = sv->c.i;
      بھرو(TREG_LR, &v1);
      بنیاد = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } ورنہ اگر(v == VT_CONST) {
      v1.type.t = VT_PTR;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      بھرو(TREG_LR, &v1);
      بنیاد = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    } ورنہ اگر(v < VT_CONST) {
      بنیاد=intr(v);
      fc=sign=0;
      v=VT_LOCAL;
    }
    اگر(v == VT_LOCAL) {
      اگر(is_float(ft)) {
	calcaddr(&بنیاد,&fc,&sign,1020,2);
#اگر_تعریف_شدہ TCC_ARM_VFP
        op=0xED100A00; /* flds */
        اگر(!sign)
          op|=0x800000;
        اگر ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* flds -> fldd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(بنیاد<<16));
#ورنہ
	op=0xED100100;
	اگر(!sign)
	  op|=0x800000;
	اگر ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#اگر LDOUBLE_سائز != 8
	ورنہ اگر ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#اگر_ختم
	o(op|(fpr(r)<<12)|(fc>>2)|(بنیاد<<16));
#اگر_ختم
      } ورنہ اگر((ft & (VT_BTYPE|VT_UNSIGNED)) == VT_BYTE
                || (ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&بنیاد,&fc,&sign,255,0);
	op=0xE1500090;
	اگر ((ft & VT_BTYPE) == VT_SHORT)
	  op|=0x20;
	اگر ((ft & VT_UNSIGNED) == 0)
	  op|=0x40;
	اگر(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(بنیاد<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } ورنہ {
	calcaddr(&بنیاد,&fc,&sign,4095,0);
	op=0xE5100000;
	اگر(!sign)
	  op|=0x800000;
        اگر ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(بنیاد<<16));
      }
      واپس;
    }
  } ورنہ {
    اگر (v == VT_CONST) {
      op=stuff_const(0xE3A00000|(intr(r)<<12),sv->c.i);
      اگر (fr & VT_SYM || !op)
	بھرو_قدر(sv, r);
      ورنہ
        o(op);
      واپس;
    } ورنہ اگر (v == VT_LOCAL) {
      op=stuff_const(0xE28B0000|(intr(r)<<12),sv->c.i);
      اگر (fr & VT_SYM || !op) {
	بھرو_قدر(sv, r);
	o(0xE08B0000|(intr(r)<<12)|intr(r));
      } ورنہ
	o(op);
      واپس;
    } ورنہ اگر(v == VT_CMP) {
      o(mapcc(sv->c.i)|0x3A00001|(intr(r)<<12));
      o(mapcc(negcc(sv->c.i))|0x3A00000|(intr(r)<<12));
      واپس;
    } ورنہ اگر (v == VT_JMP || v == VT_JMPI) {
      صحیح t;
      t = v & 1;
      o(0xE3A00000|(intr(r)<<12)|t);
      o(0xEA000000);
      gsym(sv->c.i);
      o(0xE3A00000|(intr(r)<<12)|(t^1));
      واپس;
    } ورنہ اگر (v < VT_CONST) {
      اگر(is_float(ft))
#اگر_تعریف_شدہ TCC_ARM_VFP
        o(0xEEB00A40|(vfpr(r)<<12)|vfpr(v)|T2CPR(ft)); /* fcpyX */
#ورنہ
	o(0xEE008180|(fpr(r)<<12)|fpr(v));
#اگر_ختم
      ورنہ
	o(0xE1A00000|(intr(r)<<12)|intr(v));
      واپس;
    }
  }
  tcc_error("load unimplemented!");
}

/* store register 'r' in lvalue 'v' */
خالی store(صحیح r, SValue *sv)
{
  SValue v1;
  صحیح v, ft, fc, fr, sign;
  uint32_t op, بنیاد;

  fr = sv->r;
  ft = sv->type.t;
  fc = sv->c.i;

  اگر(fc>=0)
    sign=0;
  ورنہ {
    sign=1;
    fc=-fc;
  }

  v = fr & VT_VALMASK;
  اگر (fr & VT_LVAL || fr == VT_LOCAL) {

    اگر ((fr & VT_SYM) && sv->sym->type.t & VT_TLS) {
        /* XXX: this does not work */
        uint32_t op;
        o(0xee1d0fe0); /* mrc p15, 0, lr, c13, c0, 3 */
        op = 0xe500e000; /* str r, [lr, #0] */
        greloca(cur_متن_section, sv->sym, ind, R_ARM_TLS_LE32, 0);
        o(op | (intr(r) << 12));
        واپس;
    }

    بنیاد = 0xb; /* fp */
    اگر(v < VT_CONST) {
      بنیاد=intr(v);
      v=VT_LOCAL;
      fc=sign=0;
    } ورنہ اگر(v == VT_CONST) {
      v1.type.t = ft;
      v1.r = fr&~VT_LVAL;
      v1.c.i = sv->c.i;
      v1.sym=sv->sym;
      بھرو(TREG_LR, &v1);
      بنیاد = 14; /* lr */
      fc=sign=0;
      v=VT_LOCAL;
    }
    اگر(v == VT_LOCAL) {
       اگر(is_float(ft)) {
	calcaddr(&بنیاد,&fc,&sign,1020,2);
#اگر_تعریف_شدہ TCC_ARM_VFP
        op=0xED000A00; /* fsts */
        اگر(!sign)
          op|=0x800000;
        اگر ((ft & VT_BTYPE) != VT_FLOAT)
          op|=0x100;   /* fsts -> fstd */
        o(op|(vfpr(r)<<12)|(fc>>2)|(بنیاد<<16));
#ورنہ
	op=0xED000100;
	اگر(!sign)
	  op|=0x800000;
	اگر ((ft & VT_BTYPE) == VT_DOUBLE)
	  op|=0x8000;
#اگر LDOUBLE_سائز != 8
	ورنہ اگر ((ft & VT_BTYPE) == VT_LDOUBLE)
	  op|=0x400000;
#اگر_ختم
	o(op|(fpr(r)<<12)|(fc>>2)|(بنیاد<<16));
#اگر_ختم
	واپس;
      } ورنہ اگر((ft & VT_BTYPE) == VT_SHORT) {
	calcaddr(&بنیاد,&fc,&sign,255,0);
	op=0xE14000B0;
	اگر(!sign)
	  op|=0x800000;
	o(op|(intr(r)<<12)|(بنیاد<<16)|((fc&0xf0)<<4)|(fc&0xf));
      } ورنہ {
	calcaddr(&بنیاد,&fc,&sign,4095,0);
	op=0xE5000000;
	اگر(!sign)
	  op|=0x800000;
        اگر ((ft & VT_BTYPE) == VT_BYTE || (ft & VT_BTYPE) == VT_BOOL)
          op|=0x400000;
        o(op|(intr(r)<<12)|fc|(بنیاد<<16));
      }
      واپس;
    }
  }
  tcc_error("store unimplemented");
}

ساکن خالی gadd_sp(صحیح val)
{
  stuff_const_harder(0xE28DD000,val);
}

/* 'is_jmp' is '1' if it is a jump */
ساکن خالی gcall_or_jmp(صحیح is_jmp)
{
  صحیح r;
  uint32_t x;
  اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
    /* constant case */
    اگر(vtop->r & VT_SYM){
	x=encbranch(ind,ind+vtop->c.i,0);
	اگر(x) {
	    /* relocation case */
	    greloc(cur_متن_section, vtop->sym, ind, R_ARM_PC24);
	    o(x|(is_jmp?0xE0000000:0xE1000000));
	} ورنہ {
	    r = TREG_LR;
	    بھرو_قدر(vtop, r);
	    اگر(is_jmp)
	        o(0xE1A0F000 | intr(r)); // mov pc, r
	    ورنہ
		o(0xe12fff30 | intr(r)); // blx r
	}
     }ورنہ{
	اگر(!is_jmp)
	    o(0xE28FE004); // add lr,pc,#4
	o(0xE51FF004);   // ldr pc,[pc,#-4]
	o(vtop->c.i);
     }
  } ورنہ {
    /* otherwise, indirect call */
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    vtop->r &= ~VT_MUSTBOUND;
#اگر_ختم
    r = gv(RC_INT);
    اگر(!is_jmp)
      o(0xE1A0E00F);       // mov lr,pc
    o(0xE1A0F000|intr(r)); // mov pc,r
  }
}

#اگر defined(CONFIG_TCC_BCHECK)

ساکن خالی gen_bounds_call(صحیح v)
{
    Sym *sym = external_helper_sym(v);

    greloc(cur_متن_section, sym, ind, R_ARM_PC24);
    o(0xebfffffe);
}

ساکن خالی gen_bounds_prolog(خالی)
{
    /* leave some room for bound checking code */
    func_bound_انحراف = lbounds_section->ڈیٹا_انحراف;
    func_bound_ind = ind;
    func_bound_جوڑو_epilog = 0;
    o(0xe1a00000);  /* ld r0,lbounds_section->data_offset */
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);
    o(0xe1a00000);  /* call __bound_local_new */
}

ساکن خالی gen_bounds_epilog(خالی)
{
    addr_t saved_ind;
    addr_t *bounds_ptr;
    Sym *sym_ڈیٹا;
    صحیح انحراف_modified = func_bound_انحراف != lbounds_section->ڈیٹا_انحراف;

    اگر (!انحراف_modified && !func_bound_جوڑو_epilog)
        واپس;

    /* add end of table info */
    bounds_ptr = section_ptr_جوڑو(lbounds_section, حجم(addr_t));
    *bounds_ptr = 0;

    sym_ڈیٹا = get_sym_ref(&char_اشارہ_گر_type, lbounds_section,
                           func_bound_انحراف, PTR_سائز);

    /* generate bound local allocation */
    اگر (انحراف_modified) {
        saved_ind = ind;
        ind = func_bound_ind;
        o(0xe59f0000);  /* ldr r0, [pc] */
        o(0xea000000);  /* b $+4 */
        greloc(cur_متن_section, sym_ڈیٹا, ind, R_ARM_REL32);
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
    greloc(cur_متن_section, sym_ڈیٹا, ind, R_ARM_REL32);
    o(-12);  /* lbounds_section->data_offset */
    o(0xe080000f);  /* add r0,r0,pc */
    gen_bounds_call(TOK___bound_local_delete);
    o(0xecbd0b04); /* vpop {d0,d1} */
    o(0xe8bd0003); /* pop {r0,r1} */
}
#اگر_ختم

/* Return whether a structure is an homogeneous float aggregate or not.
   The answer is true if all the elements of the structure are of the same
   primitive float type and there is less than 4 elements.

   type: the type corresponding to the structure to be tested */
ساکن صحیح is_hgen_float_aggr(CType *type)
{
  اگر ((type->t & VT_BTYPE) == VT_STRUCT) {
    ساخت Sym *ref;
    صحیح btype, nb_fields = 0;

    ref = type->ref->اگلا;
    اگر (ref) {
      btype = ref->type.t & VT_BTYPE;
      اگر (btype == VT_FLOAT || btype == VT_DOUBLE) {
        برائے(; ref && btype == (ref->type.t & VT_BTYPE); ref = ref->اگلا, nb_fields++)
            ;
        واپس !ref && nb_fields <= 4;
      }
    }
  }
  واپس 0;
}

ساخت avail_regs {
  علامتی حرف avail[3]; /* 3 holes max with only float and double alignments */
  صحیح پہلا_hole; /* first available hole */
  صحیح آخری_hole; /* last available hole (none if equal to first_hole) */
  صحیح پہلا_free_reg; /* next free register in the sequence, hole excluded */
};

/* Find suitable registers for a VFP Co-Processor Register Candidate (VFP CPRC
   param) according to the rules described in the procedure call standard for
   the ARM architecture (AAPCS). If found, the registers are assigned to this
   VFP CPRC parameter. Registers are allocated in sequence unless a hole exists
   and the parameter is a single float.

   avregs: opaque structure to keep track of available VFP co-processor regs
   align: alignment constraints for the param, as returned by type_size()
   size: size of the parameter, as returned by type_size() */
صحیح تفویض_vfpreg(ساخت avail_regs *avregs, صحیح align, صحیح سائز)
{
  صحیح پہلا_reg = 0;

  اگر (avregs->پہلا_free_reg == -1)
    واپس -1;
  اگر (align >> 3) { /* double alignment */
    پہلا_reg = avregs->پہلا_free_reg;
    /* alignment constraint not respected so use next reg and record hole */
    اگر (پہلا_reg & 1)
      avregs->avail[avregs->آخری_hole++] = پہلا_reg++;
  } ورنہ { /* no special alignment (float or array of float) */
    /* if single float and a hole is available, assign the param to it */
    اگر (سائز == 4 && avregs->پہلا_hole != avregs->آخری_hole)
      واپس avregs->avail[avregs->پہلا_hole++];
    ورنہ
      پہلا_reg = avregs->پہلا_free_reg;
  }
  اگر (پہلا_reg + سائز / 4 <= 16) {
    avregs->پہلا_free_reg = پہلا_reg + سائز / 4;
    واپس پہلا_reg;
  }
  avregs->پہلا_free_reg = -1;
  واپس -1;
}

/* Returns whether all params need to be passed in core registers or not.
   This is the case for function part of the runtime ABI. */
صحیح floats_اندر_core_regs(SValue *sval)
{
  اگر (!sval->sym)
    واپس 0;

  انتخاب (sval->sym->v) {
    حالت TOK___floatundisf:
    حالت TOK___floatundidf:
    حالت TOK___fixunssfdi:
    حالت TOK___fixunsdfdi:
#اگر_غیر_تعریف_شدہ TCC_ARM_VFP
    حالت TOK___fixunsxfdi:
#اگر_ختم
    حالت TOK___floatdisf:
    حالت TOK___floatdidf:
    حالت TOK___fixsfdi:
    حالت TOK___fixdfdi:
      واپس 1;

    طےشدہ:
      واپس 0;
  }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحیح gfunc_sret(CType *vt, صحیح variadic, CType *ret, صحیح *ret_align, صحیح *regsize) {
#اگر_تعریف_شدہ TCC_ARM_EABI
    صحیح سائز, align;
    سائز = type_سائز(vt, &align);
    اگر (float_abi == ARM_HARD_FLOAT && !variadic &&
        (is_float(vt->t) || is_hgen_float_aggr(vt))) {
        *ret_align = 8;
	*regsize = 8;
        ret->ref = تہی;
        ret->t = VT_DOUBLE;
        واپس (سائز + 7) >> 3;
    } ورنہ اگر (سائز > 0 && سائز <= 4) {
        *ret_align = 4;
	*regsize = 4;
        ret->ref = تہی;
        ret->t = VT_INT;
        واپس 1;
    } ورنہ
        واپس 0;
#ورنہ
    واپس 0;
#اگر_ختم
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
شمار reg_class {
	ڈھیر_CLASS = 0,
	CORE_STRUCT_CLASS,
	VFP_CLASS,
	VFP_STRUCT_CLASS,
	CORE_CLASS,
	NB_CLASSES
};

ساخت param_plan {
    صحیح آغاز; /* first reg or addr used depending on the class */
    صحیح انتہا; /* last reg used or next free addr depending on the class */
    SValue *sval; /* pointer to SValue on the value stack */
    ساخت param_plan *پچھلا; /*  previous element in this class */
};

ساخت plan {
    ساخت param_plan *pplans; /* array of all the param plans */
    ساخت param_plan *clsplans[NB_CLASSES]; /* per class lists of param plans */
    صحیح nb_plans;
};

ساکن خالی جوڑو_param_plan(ساخت plan* plan, صحیح cls, صحیح آغاز, صحیح انتہا, SValue *v)
{
    ساخت param_plan *p = &plan->pplans[plan->nb_plans++];
    p->پچھلا = plan->clsplans[cls];
    plan->clsplans[cls] = p;
    p->آغاز = آغاز, p->انتہا = انتہا, p->sval = v;
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
ساکن صحیح تفویض_regs(صحیح nb_دلائل, صحیح float_abi, ساخت plan *plan, صحیح *todo)
{
  صحیح i, سائز, align;
  صحیح ncrn /* next core register number */, nsaa /* next stacked argument address*/;
  ساخت avail_regs avregs = {{0}};

  ncrn = nsaa = 0;
  *todo = 0;

  برائے(i = nb_دلائل; i-- ;) {
    صحیح j, آغاز_vfpreg = 0;
    CType type = vtop[-i].type;
    type.t &= ~VT_ARRAY;
    سائز = type_سائز(&type, &align);
    سائز = (سائز + 3) & ~3;
    align = (align + 3) & ~3;
    انتخاب(vtop[-i].type.t & VT_BTYPE) {
      حالت VT_STRUCT:
      حالت VT_FLOAT:
      حالت VT_DOUBLE:
      حالت VT_LDOUBLE:
      اگر (float_abi == ARM_HARD_FLOAT) {
        صحیح is_hfa = 0; /* Homogeneous float aggregate */

        اگر (is_float(vtop[-i].type.t)
            || (is_hfa = is_hgen_float_aggr(&vtop[-i].type))) {
          صحیح انتہا_vfpreg;

          آغاز_vfpreg = تفویض_vfpreg(&avregs, align, سائز);
          انتہا_vfpreg = آغاز_vfpreg + ((سائز - 1) >> 2);
          اگر (آغاز_vfpreg >= 0) {
            جوڑو_param_plan(plan, is_hfa ? VFP_STRUCT_CLASS : VFP_CLASS,
                آغاز_vfpreg, انتہا_vfpreg, &vtop[-i]);
            جاری;
          } ورنہ
            توڑو;
        }
      }
      ncrn = (ncrn + (align-1)/4) & ~((align/4) - 1);
      اگر (ncrn + سائز/4 <= 4 || (ncrn < 4 && آغاز_vfpreg != -1)) {
        /* The parameter is allocated both in core register and on stack. As
	 * such, it can be of either class: it would either be the last of
	 * CORE_STRUCT_CLASS or the first of STACK_CLASS. */
        برائے (j = ncrn; j < 4 && j < ncrn + سائز / 4; j++)
          *todo|=(1<<j);
        جوڑو_param_plan(plan, CORE_STRUCT_CLASS, ncrn, j, &vtop[-i]);
        ncrn += سائز/4;
        اگر (ncrn > 4)
          nsaa = (ncrn - 4) * 4;
      } ورنہ {
        ncrn = 4;
        توڑو;
      }
      جاری;
      طےشدہ:
      اگر (ncrn < 4) {
        صحیح is_long = (vtop[-i].type.t & VT_BTYPE) == VT_LLONG;

        اگر (is_long) {
          ncrn = (ncrn + 1) & -2;
          اگر (ncrn == 4)
            توڑو;
        }
        جوڑو_param_plan(plan, CORE_CLASS, ncrn, ncrn + is_long, &vtop[-i]);
        ncrn += 1 + is_long;
        جاری;
      }
    }
    nsaa = (nsaa + (align - 1)) & ~(align - 1);
    جوڑو_param_plan(plan, ڈھیر_CLASS, nsaa, nsaa + سائز, &vtop[-i]);
    nsaa += سائز; /* size already rounded up before */
  }
  واپس nsaa;
}

/* Copy parameters to their final destination (core reg, VFP reg or stack) for
   function call.

   nb_args: number of parameters the function take
   plan: the overall assignment plan for parameters
   todo: a bitmap indicating what core reg will hold a parameter

   Returns the number of SValue added by this function on the value stack */
ساکن صحیح copy_params(صحیح nb_دلائل, ساخت plan *plan, صحیح todo)
{
  صحیح سائز, align, r, i, nb_extra_sval = 0;
  ساخت param_plan *pplan;
  صحیح pass = 0;

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
  برائے(i = 0; i < NB_CLASSES; i++) {
    برائے(pplan = plan->clsplans[i]; pplan; pplan = pplan->پچھلا) {

      اگر (pass
          && (i != CORE_CLASS || pplan->sval->r < VT_CONST))
        جاری;

      vpushv(pplan->sval);
      pplan->sval->r = pplan->sval->r2 = VT_CONST; /* disable entry */
      انتخاب(i) {
        حالت ڈھیر_CLASS:
        حالت CORE_STRUCT_CLASS:
        حالت VFP_STRUCT_CLASS:
          اگر ((pplan->sval->type.t & VT_BTYPE) == VT_STRUCT) {
            صحیح padding = 0;
            سائز = type_سائز(&pplan->sval->type, &align);
            /* align to stack align size */
            سائز = (سائز + 3) & ~3;
            اگر (i == ڈھیر_CLASS && pplan->پچھلا)
              padding = pplan->آغاز - pplan->پچھلا->انتہا;
            سائز += padding; /* Add padding if any */
            /* allocate the necessary size on stack */
            gadd_sp(-سائز);
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
            اگر (i == VFP_STRUCT_CLASS) {
              صحیح پہلا = pplan->آغاز, nb = pplan->انتہا - پہلا + 1;
              /* vpop.32 {pplan->start, ..., pplan->end} */
              o(0xECBD0A00|(پہلا&1)<<22|(پہلا>>1)<<12|nb);
              /* No need to write the register used to a SValue since VFP regs
                 cannot be used for gcall_or_jmp */
            }
          } ورنہ {
            اگر (is_float(pplan->sval->type.t)) {
#اگر_تعریف_شدہ TCC_ARM_VFP
              r = vfpr(gv(RC_FLOAT)) << 12;
              اگر ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                سائز = 4;
              ورنہ {
                سائز = 8;
                r |= 0x101; /* vpush.32 -> vpush.64 */
              }
              o(0xED2D0A01 + r); /* vpush */
#ورنہ
              r = fpr(gv(RC_FLOAT)) << 12;
              اگر ((pplan->sval->type.t & VT_BTYPE) == VT_FLOAT)
                سائز = 4;
              ورنہ اگر ((pplan->sval->type.t & VT_BTYPE) == VT_DOUBLE)
                سائز = 8;
              ورنہ
                سائز = LDOUBLE_سائز;
              اگر (سائز == 12)
                r |= 0x400000;
              ورنہ اگر(سائز == 8)
                r|=0x8000;

              o(0xED2D0100|r|(سائز>>2)); /* some kind of vpush for FPA */
#اگر_ختم
            } ورنہ {
              /* simple type (currently always same size) */
              /* XXX: implicit cast ? */
              سائز=4;
              اگر ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
                lexpand();
                سائز = 8;
                r = gv(RC_INT);
                o(0xE52D0004|(intr(r)<<12)); /* push r */
                vtop--;
              }
              r = gv(RC_INT);
              o(0xE52D0004|(intr(r)<<12)); /* push r */
            }
            اگر (i == ڈھیر_CLASS && pplan->پچھلا)
              gadd_sp(pplan->پچھلا->انتہا - pplan->آغاز); /* Add padding if any */
          }
          توڑو;

        حالت VFP_CLASS:
          gv(regmask(TREG_F0 + (pplan->آغاز >> 1)));
          اگر (pplan->آغاز & 1) { /* Must be in upper part of double register */
            o(0xEEF00A40|((pplan->آغاز>>1)<<12)|(pplan->آغاز>>1)); /* vmov.f32 s(n+1), sn */
            vtop->r = VT_CONST; /* avoid being saved on stack by gv for next float */
          }
          توڑو;

        حالت CORE_CLASS:
          اگر ((pplan->sval->type.t & VT_BTYPE) == VT_LLONG) {
            lexpand();
            gv(regmask(pplan->انتہا));
            pplan->sval->r2 = vtop->r;
            vtop--;
          }
          gv(regmask(pplan->آغاز));
          /* Mark register as used so that gcall_or_jmp use another one
             (regs >=4 are free as never used to pass parameters) */
          pplan->sval->r = vtop->r;
          توڑو;
      }
      vtop--;
    }
  }

  /* second pass to restore registers that were saved on stack by accident.
     Maybe redundant after the "lvalue_save" patch in tccgen.c:gv() */
  اگر (++pass < 2)
    جاؤ again;

  اگر(todo) {
    o(0xE8BD0000|todo); /* pop {todo} */
    برائے(pplan = plan->clsplans[CORE_STRUCT_CLASS]; pplan; pplan = pplan->پچھلا) {
      صحیح r;
      pplan->sval->r = pplan->آغاز;
      /* An SValue can only pin 2 registers at best (r and r2) but a structure
         can occupy more than 2 registers. Thus, we need to push on the value
         stack some fake parameter to have on SValue for each registers used
         by a structure (r2 is not used). */
      برائے (r = pplan->آغاز + 1; r <= pplan->انتہا; r++) {
        اگر (todo & (1 << r)) {
          nb_extra_sval++;
          vpushi(0);
          vtop->r = r;
        }
      }
    }
  }
  واپس nb_extra_sval;
}

/* Generate function call. The function address is pushed first, then
   all the parameters in call order. This functions pops all the
   parameters and the function address. */
خالی gfunc_call(صحیح nb_دلائل)
{
  صحیح دلائل_سائز;
  صحیح def_float_abi = float_abi;
  صحیح todo;
  ساخت plan plan;
#اگر_تعریف_شدہ TCC_ARM_EABI
  صحیح variadic;
#اگر_ختم

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
  اگر (tcc_state->do_bounds_check)
    gbound_دلائل(nb_دلائل);
#اگر_ختم

  save_regs(nb_دلائل + 1);

#اگر_تعریف_شدہ TCC_ARM_EABI
  اگر (float_abi == ARM_HARD_FLOAT) {
    variadic = (vtop[-nb_دلائل].type.ref->f.func_type == FUNC_ELLIPSIS);
    اگر (variadic || floats_اندر_core_regs(&vtop[-nb_دلائل]))
      float_abi = ARM_SOFTFP_FLOAT;
  }
#اگر_ختم

  memset(&plan, 0, حجم plan);
  اگر (nb_دلائل)
    plan.pplans = tcc_malloc(nb_دلائل * حجم(*plan.pplans));

  دلائل_سائز = تفویض_regs(nb_دلائل, float_abi, &plan, &todo);

#اگر_تعریف_شدہ TCC_ARM_EABI
  اگر (دلائل_سائز & 7) { /* Stack must be 8 byte aligned at fct call for EABI */
    دلائل_سائز = (دلائل_سائز + 7) & ~7;
    o(0xE24DD004); /* sub sp, sp, #4 */
  }
#اگر_ختم

  nb_دلائل += copy_params(nb_دلائل, &plan, todo);
  tcc_free(plan.pplans);

  /* Move fct SValue on top as required by gcall_or_jmp */
  vrotb(nb_دلائل + 1);
  gcall_or_jmp(0);
  اگر (دلائل_سائز)
      gadd_sp(دلائل_سائز); /* pop all parameters passed on the stack */
#اگر defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  اگر(float_abi == ARM_SOFTFP_FLOAT && is_float(vtop->type.ref->type.t)) {
    اگر((vtop->type.ref->type.t & VT_BTYPE) == VT_FLOAT) {
      o(0xEE000A10); /*vmov s0, r0 */
    } ورنہ {
      o(0xEE000B10); /* vmov.32 d0[0], r0 */
      o(0xEE201B10); /* vmov.32 d0[1], r1 */
    }
  }
#اگر_ختم
  vtop -= nb_دلائل + 1; /* Pop all params and fct address from value stack */
  leaffunc = 0; /* we are calling a function, so we aren't in a leaf function */
  float_abi = def_float_abi;
}

/* generate function prolog of type 't' */
خالی gfunc_prolog(Sym *func_sym)
{
  CType *func_type = &func_sym->type;
  Sym *sym,*sym2;
  صحیح n, nf, سائز, align, rs, struct_ret = 0;
  صحیح addr, pn, sn; /* pn=core, sn=stack */
  CType ret_type;

#اگر_تعریف_شدہ TCC_ARM_EABI
  ساخت avail_regs avregs = {{0}};
#اگر_ختم

  sym = func_type->ref;

  n = nf = 0;
  اگر ((func_vt.t & VT_BTYPE) == VT_STRUCT &&
      !gfunc_sret(&func_vt, func_var, &ret_type, &align, &rs))
  {
    n++;
    struct_ret = 1;
    func_vc = 12; /* Offset from fp of the place to store the result */
  }
  برائے(sym2 = sym->اگلا; sym2 && (n < 4 || nf < 16); sym2 = sym2->اگلا) {
    سائز = type_سائز(&sym2->type, &align);
#اگر_تعریف_شدہ TCC_ARM_EABI
    اگر (float_abi == ARM_HARD_FLOAT && !func_var &&
        (is_float(sym2->type.t) || is_hgen_float_aggr(&sym2->type))) {
      صحیح tmpnf = تفویض_vfpreg(&avregs, align, سائز);
      tmpnf += (سائز + 3) / 4;
      nf = (tmpnf > nf) ? tmpnf : nf;
    } ورنہ
#اگر_ختم
    اگر (n < 4)
      n += (سائز + 3) / 4;
  }
  o(0xE1A0C00D); /* mov ip,sp */
  اگر (func_var)
    n=4;
  اگر (n) {
    اگر(n>4)
      n=4;
#اگر_تعریف_شدہ TCC_ARM_EABI
    n=(n+1)&-2;
#اگر_ختم
    o(0xE92D0000|((1<<n)-1)); /* save r0-r4 on stack if needed */
  }
  اگر (nf) {
    اگر (nf>16)
      nf=16;
    nf=(nf+1)&-2; /* nf => HARDFLOAT => EABI */
    o(0xED2D0A00|nf); /* save s0-s15 on stack if needed */
  }
  o(0xE92D5800); /* save fp, ip, lr */
  o(0xE1A0B00D); /* mov fp, sp */
  func_sub_sp_انحراف = ind;
  o(0xE1A00000); /* nop, leave space for stack adjustment in epilog */

#اگر_تعریف_شدہ TCC_ARM_EABI
  اگر (float_abi == ARM_HARD_FLOAT) {
    func_vc += nf * 4;
    memset(&avregs, 0, حجم avregs);
  }
#اگر_ختم
  pn = struct_ret, sn = 0;
  جب ((sym = sym->اگلا)) {
    CType *type;
    type = &sym->type;
    سائز = type_سائز(type, &align);
    سائز = (سائز + 3) >> 2;
    align = (align + 3) & ~3;
#اگر_تعریف_شدہ TCC_ARM_EABI
    اگر (float_abi == ARM_HARD_FLOAT && !func_var && (is_float(sym->type.t)
        || is_hgen_float_aggr(&sym->type))) {
      صحیح fpn = تفویض_vfpreg(&avregs, align, سائز << 2);
      اگر (fpn >= 0)
        addr = fpn * 4;
      ورنہ
        جاؤ from_ڈھیر;
    } ورنہ
#اگر_ختم
    اگر (pn < 4) {
#اگر_تعریف_شدہ TCC_ARM_EABI
        pn = (pn + (align-1)/4) & -(align/4);
#اگر_ختم
      addr = (nf + pn) * 4;
      pn += سائز;
      اگر (!sn && pn > 4)
        sn = (pn - 4);
    } ورنہ {
#اگر_تعریف_شدہ TCC_ARM_EABI
from_ڈھیر:
        sn = (sn + (align-1)/4) & -(align/4);
#اگر_ختم
      addr = (n + nf + sn) * 4;
      sn += سائز;
    }
    gfunc_سیٹ_param(sym, addr + 12, 0);
  }
  آخری_itod_magic=0;
  leaffunc = 1;
  loc = 0;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
  اگر (tcc_state->do_bounds_check)
    gen_bounds_prolog();
#اگر_ختم
}

/* generate function epilog */
خالی gfunc_epilog(خالی)
{
  uint32_t x;
  صحیح diff;

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
  اگر (tcc_state->do_bounds_check)
    gen_bounds_epilog();
#اگر_ختم
  /* Copy float return value to core register if base standard is used and
     float computation is made with VFP */
#اگر defined(TCC_ARM_EABI) && defined(TCC_ARM_VFP)
  اگر ((float_abi == ARM_SOFTFP_FLOAT || func_var) && is_float(func_vt.t)) {
    اگر((func_vt.t & VT_BTYPE) == VT_FLOAT)
      o(0xEE100A10); /* fmrs r0, s0 */
    ورنہ {
      o(0xEE100B10); /* fmrdl r0, d0 */
      o(0xEE301B10); /* fmrdh r1, d0 */
    }
  }
#اگر_ختم
  o(0xE89BA800); /* restore fp, sp, pc */
  diff = (-loc + 3) & -4;
#اگر_تعریف_شدہ TCC_ARM_EABI
  اگر(!leaffunc)
    diff = ((diff + 11) & -8) - 4;
#اگر_ختم
  اگر(diff > 0) {
    x=stuff_const(0xE24BD000, diff); /* sub sp,fp,# */
    اگر(x)
      *(uint32_t *)(cur_متن_section->ڈیٹا + func_sub_sp_انحراف) = x;
    ورنہ {
      صحیح addr;
      addr=ind;
      o(0xE59FC004); /* ldr ip,[pc+4] */
      o(0xE04BD00C); /* sub sp,fp,ip  */
      o(0xE1A0F00E); /* mov pc,lr */
      o(diff);
      *(uint32_t *)(cur_متن_section->ڈیٹا + func_sub_sp_انحراف) = 0xE1000000|encbranch(func_sub_sp_انحراف,addr,1);
    }
  }
}

ST_FUNC خالی gen_fill_nops(صحیح بائٹیں)
{
    اگر ((بائٹیں & 3))
      tcc_error("alignment of code section not multiple of 4");
    جب (بائٹیں > 0) {
	o(0xE1A00000);
	بائٹیں -= 4;
    }
}

/* generate a jump to a label */
ST_FUNC صحیح gjmp(صحیح t)
{
  صحیح r;
  اگر (nocode_wanted)
    واپس t;
  r=ind;
  o(0xE0000000|encbranch(r,t,1));
  واپس r;
}

/* generate a jump to a fixed address */
ST_FUNC خالی gjmp_addr(صحیح a)
{
  gjmp(a);
}

ST_FUNC صحیح gjmp_cond(صحیح op, صحیح t)
{
  صحیح r;
  اگر (nocode_wanted)
    واپس t;
  r=ind;
  op=mapcc(op);
  op|=encbranch(r,t,1);
  o(op);
  واپس r;
}

ST_FUNC صحیح gjmp_append(صحیح n, صحیح t)
{
  uint32_t *x;
  صحیح p,lp;
  اگر(n) {
    p = n;
    کرو {
      p = decbranch(lp=p);
    } جب(p);
    x = (uint32_t *)(cur_متن_section->ڈیٹا + lp);
    *x &= 0xff000000;
    *x |= encbranch(lp,t,1);
    t = n;
  }
  واپس t;
}

/* generate an integer binary operation */
خالی gen_opi(صحیح op)
{
  صحیح c, func = 0;
  uint32_t opc = 0, r, fr;
  غیرعلامتی مختصر retreg = REG_IRET;

  c=0;
  انتخاب(op) {
    حالت '+':
      opc = 0x8;
      c=1;
      توڑو;
    حالت TOK_ADDC1: /* add with carry generation */
      opc = 0x9;
      c=1;
      توڑو;
    حالت '-':
      opc = 0x4;
      c=1;
      توڑو;
    حالت TOK_SUBC1: /* sub with carry generation */
      opc = 0x5;
      c=1;
      توڑو;
    حالت TOK_ADDC2: /* add with carry use */
      opc = 0xA;
      c=1;
      توڑو;
    حالت TOK_SUBC2: /* sub with carry use */
      opc = 0xC;
      c=1;
      توڑو;
    حالت '&':
      opc = 0x0;
      c=1;
      توڑو;
    حالت '^':
      opc = 0x2;
      c=1;
      توڑو;
    حالت '|':
      opc = 0x18;
      c=1;
      توڑو;
    حالت '*':
      gv2(RC_INT, RC_INT);
      r = vtop[-1].r;
      fr = vtop[0].r;
      vtop--;
      o(0xE0000090|(intr(r)<<16)|(intr(r)<<8)|intr(fr));
      واپس;
    حالت TOK_SHL:
      opc = 0;
      c=2;
      توڑو;
    حالت TOK_SHR:
      opc = 1;
      c=2;
      توڑو;
    حالت TOK_SAR:
      opc = 2;
      c=2;
      توڑو;
    حالت '/':
    حالت TOK_PDIV:
      func=TOK___divsi3;
      c=3;
      توڑو;
    حالت TOK_UDIV:
      func=TOK___udivsi3;
      c=3;
      توڑو;
    حالت '%':
#اگر_تعریف_شدہ TCC_ARM_EABI
      func=TOK___aeabi_idivmod;
      retreg=REG_IRE2;
#ورنہ
      func=TOK___modsi3;
#اگر_ختم
      c=3;
      توڑو;
    حالت TOK_UMOD:
#اگر_تعریف_شدہ TCC_ARM_EABI
      func=TOK___aeabi_uidivmod;
      retreg=REG_IRE2;
#ورنہ
      func=TOK___umodsi3;
#اگر_ختم
      c=3;
      توڑو;
    حالت TOK_UMULL:
      gv2(RC_INT, RC_INT);
      r=intr(vtop[-1].r2=get_reg(RC_INT));
      c=vtop[-1].r;
      vtop[-1].r=get_reg_ex(RC_INT,regmask(c));
      vtop--;
      o(0xE0800090|(r<<16)|(intr(vtop->r)<<12)|(intr(c)<<8)|intr(vtop[1].r));
      واپس;
    طےشدہ:
      opc = 0x15;
      c=1;
      توڑو;
  }
  انتخاب(c) {
    حالت 1:
      اگر((vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	اگر(opc == 4 || opc == 5 || opc == 0xc) {
	  vswap();
	  opc|=2; // sub -> rsb
	}
      }
      vswap();
      c=intr(gv(RC_INT));
      vswap();
      opc=0xE0000000|(opc<<20);
      اگر((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	uint32_t x;
	x=stuff_const(opc|0x2000000|(c<<16),vtop->c.i);
	اگر(x) {
	  اگر ((x & 0xfff00000) == 0xe3500000)   // cmp rx,#c
	    o(x);
	  ورنہ {
	    r=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	    o(x|(r<<12));
	  }
	  جاؤ مکمل;
	}
      }
      fr=intr(gv(RC_INT));
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
      اگر ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
        vswap();
        c=intr(gv(RC_INT));
        vswap();
      }
#اگر_ختم
      اگر ((opc & 0xfff00000) == 0xe1500000) // cmp rx,ry
	o(opc|(c<<16)|fr);
      ورنہ {
        r=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
        o(opc|(c<<16)|(r<<12)|fr);
      }
مکمل:
      vtop--;
      اگر (op >= TOK_ULT && op <= TOK_GT)
        vset_VT_CMP(op);
      توڑو;
    حالت 2:
      opc=0xE1A00000|(opc<<5);
      vswap();
      r=intr(gv(RC_INT));
      vswap();
      اگر ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
	fr=intr(vtop[-1].r=get_reg_ex(RC_INT,regmask(vtop[-1].r)));
	c = vtop->c.i & 0x1f;
	o(opc|r|(c<<7)|(fr<<12));
      } ورنہ {
        fr=intr(gv(RC_INT));
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=intr(gv(RC_INT));
          vswap();
        }
#اگر_ختم
	c=intr(vtop[-1].r=get_reg_ex(RC_INT,two2mask(vtop->r,vtop[-1].r)));
	o(opc|r|(c<<12)|(fr<<8)|0x10);
      }
      vtop--;
      توڑو;
    حالت 3:
      vpush_helper_func(func);
      vrott(3);
      gfunc_call(2);
      vpushi(0);
      vtop->r = retreg;
      توڑو;
    طےشدہ:
      tcc_error("gen_opi %i unimplemented!",op);
  }
}

#اگر_تعریف_شدہ TCC_ARM_VFP
ساکن صحیح is_zero(صحیح i)
{
  اگر((vtop[i].r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    واپس 0;
  اگر (vtop[i].type.t == VT_FLOAT)
    واپس (vtop[i].c.f == 0.f);
  ورنہ اگر (vtop[i].type.t == VT_DOUBLE)
    واپس (vtop[i].c.d == 0.0);
  واپس (vtop[i].c.ld == 0.l);
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
 *    two operands are guaranteed to have the same floating point type */
خالی gen_opf(صحیح op)
{
  uint32_t x;
  صحیح fneg=0,r;
  x=0xEE000A00|T2CPR(vtop->type.t);
  انتخاب(op) {
    حالت '+':
      اگر(is_zero(-1))
        vswap();
      اگر(is_zero(0)) {
        vtop--;
        واپس;
      }
      x|=0x300000;
      توڑو;
    حالت '-':
      x|=0x300040;
      اگر(is_zero(0)) {
        vtop--;
        واپس;
      }
      اگر(is_zero(-1)) {
        x|=0x810000; /* fsubX -> fnegX */
        vswap();
        vtop--;
        fneg=1;
      }
      توڑو;
    حالت '*':
      x|=0x200000;
      توڑو;
    حالت '/':
      x|=0x800000;
      توڑو;
    طےشدہ:
      اگر(op < TOK_ULT || op > TOK_GT) {
        tcc_error("unknown fp op %x!",op);
        واپس;
      }
      اگر(is_zero(-1)) {
        vswap();
        انتخاب(op) {
          حالت TOK_LT: op=TOK_GT; توڑو;
          حالت TOK_GE: op=TOK_ULE; توڑو;
          حالت TOK_LE: op=TOK_GE; توڑو;
          حالت TOK_GT: op=TOK_ULT; توڑو;
        }
      }
      x|=0xB40040; /* fcmpX */
      اگر(op!=TOK_EQ && op!=TOK_NE)
        x|=0x80; /* fcmpX -> fcmpeX */
      اگر(is_zero(0)) {
        vtop--;
        o(x|0x10000|(vfpr(gv(RC_FLOAT))<<12)); /* fcmp(e)X -> fcmp(e)zX */
      } ورنہ {
        gv2(RC_FLOAT,RC_FLOAT);
        x|=vfpr(vtop[0].r);
        o(x|(vfpr(vtop[-1].r) << 12));
        vtop--;
      }
      o(0xEEF1FA10); /* fmstat */

      انتخاب(op) {
        حالت TOK_LE: op=TOK_ULE; توڑو;
        حالت TOK_LT: op=TOK_ULT; توڑو;
        حالت TOK_UGE: op=TOK_GE; توڑو;
        حالت TOK_UGT: op=TOK_GT; توڑو;
      }
      vset_VT_CMP(op);
      واپس;
  }
  r=gv(RC_FLOAT);
  x|=vfpr(r);
  r=regmask(r);
  اگر(!fneg) {
    صحیح r2;
    vswap();
    r2=gv(RC_FLOAT);
    x|=vfpr(r2)<<16;
    r|=regmask(r2);
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
      vswap();
      r=gv(RC_FLOAT);
      vswap();
      x=(x&~0xf)|vfpr(r);
    }
#اگر_ختم
  }
  vtop->r=get_reg_ex(RC_FLOAT,r);
  اگر(!fneg)
    vtop--;
  o(x|(vfpr(vtop->r)<<12));
}

#ورنہ
ساکن uint32_t is_fconst()
{
  طویل دوہرا f;
  uint32_t r;
  اگر((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
    واپس 0;
  اگر (vtop->type.t == VT_FLOAT)
    f = vtop->c.f;
  ورنہ اگر (vtop->type.t == VT_DOUBLE)
    f = vtop->c.d;
  ورنہ
    f = vtop->c.ld;
  اگر(!ieee_finite(f))
    واپس 0;
  r=0x8;
  اگر(f<0.0) {
    r=0x18;
    f=-f;
  }
  اگر(f==0.0)
    واپس r;
  اگر(f==1.0)
    واپس r|1;
  اگر(f==2.0)
    واپس r|2;
  اگر(f==3.0)
    واپس r|3;
  اگر(f==4.0)
    واپس r|4;
  اگر(f==5.0)
    واپس r|5;
  اگر(f==0.5)
    واپس r|6;
  اگر(f==10.0)
    واپس r|7;
  واپس 0;
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
خالی gen_opf(صحیح op)
{
  uint32_t x, r, r2, c1, c2;
  //fputs("gen_opf\n",stderr);
  vswap();
  c1 = is_fconst();
  vswap();
  c2 = is_fconst();
  x=0xEE000100;
  اگر ((vtop->type.t & VT_BTYPE) == VT_DOUBLE)
    x|=0x80;
#اگر LDOUBLE_سائز != 8
  ورنہ اگر ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE)
    x|=0x80000;
#اگر_ختم

  انتخاب(op)
  {
    حالت '+':
      اگر(!c2) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      اگر(c2) {
	اگر(c2>0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
      } ورنہ {
	r2=fpr(gv(RC_FLOAT));
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#اگر_ختم
      }
      توڑو;
    حالت '-':
      اگر(c2) {
	اگر(c2<=0xf)
	  x|=0x200000; // suf
	r2=c2&0xf;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ورنہ اگر(c1 && c1<=0xf) {
	x|=0x300000; // rsf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ورنہ {
	x|=0x200000; // suf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#اگر_ختم
      }
      توڑو;
    حالت '*':
      اگر(!c2 || c2>0xf) {
	vswap();
	c2=c1;
      }
      vswap();
      r=fpr(gv(RC_FLOAT));
      vswap();
      اگر(c2 && c2<=0xf)
	r2=c2;
      ورنہ {
	r2=fpr(gv(RC_FLOAT));
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#اگر_ختم
      }
      x|=0x100000; // muf
      توڑو;
    حالت '/':
      اگر(c2 && c2<=0xf) {
	x|=0x400000; // dvf
	r2=c2;
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ورنہ اگر(c1 && c1<=0xf) {
	x|=0x500000; // rdf
	r2=c1;
	r=fpr(gv(RC_FLOAT));
	vswap();
      } ورنہ {
	x|=0x400000; // dvf
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	r2=fpr(gv(RC_FLOAT));
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
          vswap();
          r=fpr(gv(RC_FLOAT));
          vswap();
        }
#اگر_ختم
      }
      توڑو;
    طےشدہ:
      اگر(op >= TOK_ULT && op <= TOK_GT) {
	x|=0xd0f110; // cmfe
/* bug (intention?) in Linux FPU emulator
   doesn't set carry if equal */
	انتخاب(op) {
	  حالت TOK_ULT:
	  حالت TOK_UGE:
	  حالت TOK_ULE:
	  حالت TOK_UGT:
            tcc_error("unsigned comparison on floats?");
	    توڑو;
	  حالت TOK_LT:
            op=TOK_Nset;
	    توڑو;
	  حالت TOK_LE:
            op=TOK_ULE; /* correct in unordered case only if AC bit in FPSR set */
	    توڑو;
	  حالت TOK_EQ:
	  حالت TOK_NE:
	    x&=~0x400000; // cmfe -> cmf
	    توڑو;
	}
	اگر(c1 && !c2) {
	  c2=c1;
	  vswap();
	  انتخاب(op) {
            حالت TOK_Nset:
              op=TOK_GT;
	      توڑو;
            حالت TOK_GE:
	      op=TOK_ULE;
	      توڑو;
	    حالت TOK_ULE:
              op=TOK_GE;
	      توڑو;
            حالت TOK_GT:
              op=TOK_Nset;
	      توڑو;
	  }
	}
	vswap();
	r=fpr(gv(RC_FLOAT));
	vswap();
	اگر(c2) {
	  اگر(c2>0xf)
	    x|=0x200000;
	  r2=c2&0xf;
	} ورنہ {
	  r2=fpr(gv(RC_FLOAT));
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
          اگر ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            r=fpr(gv(RC_FLOAT));
            vswap();
          }
#اگر_ختم
	}
        --vtop;
        vset_VT_CMP(op);
        ++vtop;
      } ورنہ {
        tcc_error("unknown fp op %x!",op);
	واپس;
      }
  }
  اگر(vtop[-1].r == VT_CMP)
    c1=15;
  ورنہ {
    c1=vtop->r;
    اگر(r2&0x8)
      c1=vtop[-1].r;
    vtop[-1].r=get_reg_ex(RC_FLOAT,two2mask(vtop[-1].r,c1));
    c1=fpr(vtop[-1].r);
  }
  vtop--;
  o(x|(r<<16)|(c1<<12)|r2);
}
#اگر_ختم

/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
ST_FUNC خالی gen_cvt_itof(صحیح t)
{
  uint32_t r, r2;
  صحیح bt;
  bt=vtop->type.t & VT_BTYPE;
  اگر(bt == VT_INT || bt == VT_SHORT || bt == VT_BYTE) {
#اگر_غیر_تعریف_شدہ TCC_ARM_VFP
    uint32_t dsize = 0;
#اگر_ختم
    r=intr(gv(RC_INT));
#اگر_تعریف_شدہ TCC_ARM_VFP
    r2=vfpr(vtop->r=get_reg(RC_FLOAT));
    o(0xEE000A10|(r<<12)|(r2<<16)); /* fmsr */
    r2|=r2<<12;
    اگر(!(vtop->type.t & VT_UNSIGNED))
      r2|=0x80;                /* fuitoX -> fsituX */
    o(0xEEB80A40|r2|T2CPR(t)); /* fYitoX*/
#ورنہ
    r2=fpr(vtop->r=get_reg(RC_FLOAT));
    اگر((t & VT_BTYPE) != VT_FLOAT)
      dsize=0x80;    /* flts -> fltd */
    o(0xEE000110|dsize|(r2<<16)|(r<<12)); /* flts */
    اگر((vtop->type.t & (VT_UNSIGNED|VT_BTYPE)) == (VT_UNSIGNED|VT_INT)) {
      uint32_t off = 0;
      o(0xE3500000|(r<<12));        /* cmp */
      r=fpr(get_reg(RC_FLOAT));
      اگر(آخری_itod_magic) {
	off=ind+8-آخری_itod_magic;
	off/=4;
	اگر(off>255)
	  off=0;
      }
      o(0xBD1F0100|(r<<12)|off);    /* ldflts */
      اگر(!off) {
        o(0xEA000000);              /* b */
        آخری_itod_magic=ind;
        o(0x4F800000);              /* 4294967296.0f */
      }
      o(0xBE000100|dsize|(r2<<16)|(r2<<12)|r); /* adflt */
    }
#اگر_ختم
    واپس;
  } ورنہ اگر(bt == VT_LLONG) {
    صحیح func;
    CType *func_type = 0;
    اگر((t & VT_BTYPE) == VT_FLOAT) {
      func_type = &func_float_type;
      اگر(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundisf;
      ورنہ
        func=TOK___floatdisf;
    } ورنہ اگر((t & VT_BTYPE) == VT_DOUBLE) {
      func_type = &func_double_type;
      اگر(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundidf;
      ورنہ
        func=TOK___floatdidf;
#اگر LDOUBLE_سائز != 8
    } ورنہ اگر((t & VT_BTYPE) == VT_LDOUBLE) {
      func_type = &func_ldouble_type;
      اگر(vtop->type.t & VT_UNSIGNED)
        func=TOK___floatundixf;
      ورنہ
        func=TOK___floatdixf;
#اگر_ختم
    }
    اگر(func_type) {
      vpushsym(func_type, external_helper_sym(func));
      vswap();
      gfunc_call(1);
      vpushi(0);
      vtop->r=TREG_F0;
      واپس;
    }
  }
  tcc_error("unimplemented gen_cvt_itof %x!",vtop->type.t);
}

/* convert fp to int 't' type */
خالی gen_cvt_ftoi(صحیح t)
{
  uint32_t r, r2;
  صحیح u, func = 0;
  u=t&VT_UNSIGNED;
  t&=VT_BTYPE;
  r2=vtop->type.t & VT_BTYPE;
  اگر(t==VT_INT) {
#اگر_تعریف_شدہ TCC_ARM_VFP
    r=vfpr(gv(RC_FLOAT));
    u=u?0:0x10000;
    o(0xEEBC0AC0|(r<<12)|r|T2CPR(r2)|u); /* ftoXizY */
    r2=intr(vtop->r=get_reg(RC_INT));
    o(0xEE100A10|(r<<16)|(r2<<12));
    واپس;
#ورنہ
    اگر(u) {
      اگر(r2 == VT_FLOAT)
        func=TOK___fixunssfsi;
      ورنہ اگر(r2 == VT_DOUBLE)
	func=TOK___fixunsdfsi;
#اگر LDOUBLE_سائز != 8
      ورنہ اگر(r2 == VT_LDOUBLE)
	func=TOK___fixunsxfsi;
#اگر_ختم
    } ورنہ {
      r=fpr(gv(RC_FLOAT));
      r2=intr(vtop->r=get_reg(RC_INT));
      o(0xEE100170|(r2<<12)|r);
      واپس;
    }
#اگر_ختم
  } ورنہ اگر(t == VT_LLONG) { // unsigned handled in gen_cvt_ftoi1
    اگر(r2 == VT_FLOAT)
      func=TOK___fixsfdi;
    ورنہ اگر(r2 == VT_DOUBLE)
      func=TOK___fixdfdi;
#اگر LDOUBLE_سائز != 8
    ورنہ اگر(r2 == VT_LDOUBLE)
      func=TOK___fixxfdi;
#اگر_ختم
  }
  اگر(func) {
    vpush_helper_func(func);
    vswap();
    gfunc_call(1);
    vpushi(0);
    اگر(t == VT_LLONG)
      vtop->r2 = REG_IRE2;
    vtop->r = REG_IRET;
    واپس;
  }
  tcc_error("unimplemented gen_cvt_ftoi!");
}

/* convert from one floating point type to another */
خالی gen_cvt_ftof(صحیح t)
{
#اگر_تعریف_شدہ TCC_ARM_VFP
  uint32_t r = gv(RC_FLOAT);
  اگر(((vtop->type.t & VT_BTYPE) == VT_FLOAT) != ((t & VT_BTYPE) == VT_FLOAT)) {
    r = vfpr(r);
    o(0xEEB70AC0|(r<<12)|r|T2CPR(vtop->type.t));
  }
#ورنہ
  /* all we have to do on i386 and FPA ARM is to put the float in a register */
  gv(RC_FLOAT);
#اگر_ختم
}

/* increment tcov counter */
ST_FUNC خالی gen_increment_tcov (SValue *sv)
{
  صحیح r1, r2;

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
خالی ggoto(خالی)
{
  gcall_or_jmp(1);
  vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC خالی gen_vla_sp_save(صحیح addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    store(TREG_SP, &v);
}

/* Restore the SP from a location on the stack */
ST_FUNC خالی gen_vla_sp_restore(صحیح addr) {
    SValue v;
    v.type.t = VT_PTR;
    v.r = VT_LOCAL | VT_LVAL;
    v.c.i = addr;
    بھرو(TREG_SP, &v);
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC خالی gen_vla_alloc(CType *type, صحیح align) {
    صحیح r;
#اگر defined(CONFIG_TCC_BCHECK)
    اگر (tcc_state->do_bounds_check)
        vpushv(vtop);
#اگر_ختم
    r = intr(gv(RC_INT));
#اگر defined(CONFIG_TCC_BCHECK)
    اگر (tcc_state->do_bounds_check)
        o(0xe2800001 | (r<<16)|(r<<12)); /* add r,r,#1 */
#اگر_ختم
    o(0xE04D0000|(r<<12)|r); /* sub r, sp, r */
#اگر_تعریف_شدہ TCC_ARM_EABI
    اگر (align < 8)
        align = 8;
#ورنہ
    اگر (align < 4)
        align = 4;
#اگر_ختم
    اگر (align & (align - 1))
        tcc_error("alignment is not a power of 2: %i", align);
    o(stuff_const(0xE3C0D000|(r<<16), align - 1)); /* bic sp, r, #align-1 */
    vpop();
#اگر defined(CONFIG_TCC_BCHECK)
    اگر (tcc_state->do_bounds_check) {
        vpushi(0);
        vtop->r = TREG_R0;
        o(0xe1a0000d | (vtop->r << 12)); // mov r0,sp
        vswap();
        vpush_helper_func(TOK___bound_new_region);
        vrott(3);
        gfunc_call(2);
        func_bound_جوڑو_epilog = 1;
    }
#اگر_ختم
}

/* end of ARM code generator */
/*************************************************************/
#اگر_ختم
/*************************************************************/
