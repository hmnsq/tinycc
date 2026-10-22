/* TCC runtime library. 
   Parts of this code are (c) 2002 Fabrice Bellard 

   Copyright (C) 1987, 1988, 1992, 1994, 1995 Free Software Foundation, Inc.

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
do apply in other respects; for example, they cover modification of
the file, and distribution when not linked into a combine
executable.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  
*/

#define W_TYPE_SIZE   32
#define BITS_PER_UNIT 8

تعريفنوع صحيح Wtype;
تعريفنوع unsigned صحيح UWtype;
تعريفنوع unsigned صحيح USItype;
تعريفنوع long long DWtype;
تعريفنوع unsigned long long UDWtype;

بنية DWstruct {
    Wtype أدنى, أعلى;
};

تعريفنوع اتحاد
{
  بنية DWstruct s;
  DWtype ll;
} DWunion;

تعريفنوع long مزدوج XFtype;
#define WORD_SIZE (حجم (Wtype) * BITS_PER_UNIT)
#define أعلى_WORD_COEFF (((UDWtype) 1) << WORD_SIZE)

/* the following deal with IEEE single-precision numbers */
#define EXCESS		126
#define SIGNBIT		0x80000000
#define HIDDEN		(1 << 23)
#define SIGN(fp)	((fp) & SIGNBIT)
#define EXP(fp)		(((fp) >> 23) & 0xFF)
#define MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#define PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE double-precision numbers */
#define EXCESSD		1022
#define HIDDEND		(1 << 20)
#define EXPD(fp)	(((fp.l.upper) >> 20) & 0x7FF)
#define SIGND(fp)	((fp.l.upper) & SIGNBIT)
#define MANTD(fp)	(((((fp.l.upper) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.lower >> 22))
#define HIDDEND_LL	((long long)1 << 52)
#define MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#define PACKD_LL(s,e,m)	(((long long)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#define EXCESSLD	16382
#define EXPLD(fp)	(fp.l.upper & 0x7fff)
#define SIGNLD(fp)	((fp.l.upper) & 0x8000)

/* only for x86 */
اتحاد ldouble_long {
    long مزدوج ld;
    بنية {
        unsigned long long lower;
        unsigned short upper;
    } l;
};

اتحاد double_long {
    مزدوج d;
#إذا 1
    بنية {
        unsigned صحيح lower;
        صحيح upper;
    } l;
#وإلا
    بنية {
        صحيح upper;
        unsigned صحيح lower;
    } l;
#endif
    long long ll;
};

اتحاد float_long {
    عائم f;
    unsigned صحيح l;
};

/* XXX: we don't support several builtin supports for now */
#إذا defined __i386__

/* XXX: use gcc/tcc intrinsic ? */
#define sub_ddmmss(sh, sl, ah, al, bh, bl) \
  __asm__ ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#define umul_ppmm(w1, w0, u, v) \
  __asm__ ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#define udiv_qrnnd(q, r, n1, n0, dv) \
  __asm__ ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#define تعداد_leading_zeros(تعداد_3, x) \
  افعل {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (تعداد_3) = __cbtmp ^ 31;						\
  } بينما (0)

/* most of this code is taken from libgcc2.c from gcc */

ساكن UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.أدنى;
  d1 = dd.s.أعلى;
  n0 = nn.s.أدنى;
  n1 = nn.s.أعلى;

#إذا !defined(UDIV_NEEDS_NORMALIZATION)
  إذا (d1 == 0)
    {
      إذا (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      وإلا
	{
	  /* qq = NN / 0d */

	  إذا (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      إذا (rp != 0)
	{
	  rr.s.أدنى = n0;
	  rr.s.أعلى = 0;
	  *rp = rr.ll;
	}
    }

#وإلا /* UDIV_NEEDS_NORMALIZATION */

  إذا (d1 == 0)
    {
      إذا (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  تعداد_leading_zeros (bm, d0);

	  إذا (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_SIZE - bm));
	      n0 = n0 << bm;
	    }

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0 >> bm.  */
	}
      وإلا
	{
	  /* qq = NN / 0d */

	  إذا (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  تعداد_leading_zeros (bm, d0);

	  إذا (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  وإلا
	    {
	      /* Normalize.  */

	      b = W_TYPE_SIZE - bm;

	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q1, n1, n2, n1, d0);
	    }

	  /* n1 != d0...  */

	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0 >> bm.  */
	}

      إذا (rp != 0)
	{
	  rr.s.أدنى = n0 >> bm;
	  rr.s.أعلى = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  وإلا
    {
      إذا (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  إذا (rp != 0)
	    {
	      rr.s.أدنى = n0;
	      rr.s.أعلى = n1;
	      *rp = rr.ll;
	    }
	}
      وإلا
	{
	  /* 0q = NN / dd */

	  تعداد_leading_zeros (bm, d1);
	  إذا (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      إذا (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      وإلا
		q0 = 0;

	      q1 = 0;

	      إذا (rp != 0)
		{
		  rr.s.أدنى = n0;
		  rr.s.أعلى = n1;
		  *rp = rr.ll;
		}
	    }
	  وإلا
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_SIZE - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);

	      إذا (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      إذا (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.أدنى = (n1 << b) | (n0 >> bm);
		  rr.s.أعلى = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.أدنى = q0;
  ww.s.أعلى = q1;
  إرجاع ww.ll;
}

#define __negdi2(a) (-(a))

long long __divdi3(long long u, long long v)
{
    صحيح c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    إذا (uu.s.أعلى < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    إذا (vv.s.أعلى < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    إذا (c)
        w = __negdi2 (w);
    إرجاع w;
}

long long __moddi3(long long u, long long v)
{
    صحيح c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    إذا (uu.s.أعلى < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    إذا (vv.s.أعلى < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    إذا (c)
        w = __negdi2 (w);
    إرجاع w;
}

unsigned long long __udivdi3(unsigned long long u, unsigned long long v)
{
    إرجاع __udivmoddi4 (u, v, (UDWtype *) 0);
}

unsigned long long __umoddi3(unsigned long long u, unsigned long long v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    إرجاع w;
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashrdi3(long long a, صحيح b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.أدنى = u.s.أعلى >> (b - 32);
        u.s.أعلى = u.s.أعلى >> 31;
    } وإلا إذا (b != 0) {
        u.s.أدنى = ((unsigned)u.s.أدنى >> b) | (u.s.أعلى << (32 - b));
        u.s.أعلى = u.s.أعلى >> b;
    }
    إرجاع u.ll;
#وإلا
    إرجاع a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
unsigned long long __lshrdi3(unsigned long long a, صحيح b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.أدنى = (unsigned)u.s.أعلى >> (b - 32);
        u.s.أعلى = 0;
    } وإلا إذا (b != 0) {
        u.s.أدنى = ((unsigned)u.s.أدنى >> b) | (u.s.أعلى << (32 - b));
        u.s.أعلى = (unsigned)u.s.أعلى >> b;
    }
    إرجاع u.ll;
#وإلا
    إرجاع a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashldi3(long long a, صحيح b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.أعلى = (unsigned)u.s.أدنى << (b - 32);
        u.s.أدنى = 0;
    } وإلا إذا (b != 0) {
        u.s.أعلى = ((unsigned)u.s.أعلى << b) | ((unsigned)u.s.أدنى >> (32 - b));
        u.s.أدنى = (unsigned)u.s.أدنى << b;
    }
    إرجاع u.ll;
#وإلا
    إرجاع a << b;
#endif
}

#endif /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
عائم __floatundisf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.أعلى >= 0) {
        إرجاع (عائم)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        إرجاع (عائم)r;
    }
}

مزدوج __floatundidf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.أعلى >= 0) {
        إرجاع (مزدوج)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        إرجاع (مزدوج)r;
    }
}

long مزدوج __floatundixf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.أعلى >= 0) {
        إرجاع (long مزدوج)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        إرجاع (long مزدوج)r;
    }
}

unsigned long long __fixunssfdi (عائم a1)
{
    سجل اتحاد float_long fl1;
    سجل صحيح exp;
    سجل unsigned long long l;

    fl1.f = a1;

    إذا (fl1.l == 0)
	إرجاع (0);

    exp = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    إذا (exp >= 41)
        إرجاع 1ULL << 63;
    وإلا إذا (exp >= 0)
        l <<= exp;
    وإلا إذا (exp >= -23)
        l >>= -exp;
    وإلا
	إرجاع 0;
    إذا (SIGN(fl1.l))
        l = (unsigned long long)-l;
    إرجاع l;
}

long long __fixsfdi (عائم a1)
{
    long long ret; صحيح s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    إرجاع s ? ret : -ret;
}

unsigned long long __fixunsdfdi (مزدوج a1)
{
    سجل اتحاد double_long dl1;
    سجل صحيح exp;
    سجل unsigned long long l;

    dl1.d = a1;

    إذا (dl1.ll == 0)
	إرجاع (0);

    exp = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    إذا (exp >= 12)
        إرجاع 1ULL << 63; /* overflow result (like gcc, somewhat) */
    وإلا إذا (exp >= 0)
        l <<= exp;
    وإلا إذا (exp >= -52)
        l >>= -exp;
    وإلا
        إرجاع 0;
    إذا (SIGND(dl1))
        l = (unsigned long long)-l;
    إرجاع l;
}

long long __fixdfdi (مزدوج a1)
{
    long long ret; صحيح s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    إرجاع s ? ret : -ret;
}

#ifndef __arm__
unsigned long long __fixunsxfdi (long مزدوج a1)
{
    سجل اتحاد ldouble_long dl1;
    سجل صحيح exp;
    سجل unsigned long long l;

    dl1.ld = a1;

    إذا (dl1.l.lower == 0 && dl1.l.upper == 0)
	إرجاع (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.lower;
    إذا (exp > 0)
	إرجاع 1ULL << 63;
    إذا (exp < -63)
        إرجاع 0;
    l >>= -exp;
    إذا (SIGNLD(dl1))
        l = (unsigned long long)-l;
    إرجاع l;
}

long long __fixxfdi (long مزدوج a1)
{
    long long ret; صحيح s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    إرجاع s ? ret : -ret;
}
#endif /* !ARM */
