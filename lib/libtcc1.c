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

typedef puur_naa_nka Wtype;
typedef unsigned puur_naa_nka UWtype;
typedef unsigned puur_naa_nka USItype;
typedef long long DWtype;
typedef unsigned long long UDWtype;

sa_nracanaa DWstruct {
    Wtype low, high;
};

typedef sa_ngha
{
  sa_nracanaa DWstruct s;
  DWtype ll;
} DWunion;

typedef long dviguu_na XFtype;
#define WORD_SIZE (parimaa_na (Wtype) * BITS_PER_UNIT)
#define HIGH_WORD_COEFF (((UDWtype) 1) << WORD_SIZE)

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
sa_ngha ldouble_long {
    long dviguu_na ld;
    sa_nracanaa {
        unsigned long long lower;
        unsigned short upper;
    } l;
};

sa_ngha double_long {
    dviguu_na d;
#ꦪꦼꦤ꧀ 1
    sa_nracanaa {
        unsigned puur_naa_nka lower;
        puur_naa_nka upper;
    } l;
#ꦭꦶꦪ
    sa_nracanaa {
        puur_naa_nka upper;
        unsigned puur_naa_nka lower;
    } l;
#endif
    long long ll;
};

sa_ngha float_long {
    float f;
    unsigned puur_naa_nka l;
};

/* XXX: we don't support several builtin supports for now */
#ꦪꦼꦤ꧀ defined __i386__

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
#define count_leading_zeros(count, x) \
  do {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (count) = __cbtmp ^ 31;						\
  } ꦱꦼꦢꦼꦭ (0)

/* most of this code is taken from libgcc2.c from gcc */

static UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;

#ꦪꦼꦤ꧀ !defined(UDIV_NEEDS_NORMALIZATION)
  ꦪꦼꦤ꧀ (d1 == 0)
    {
      ꦪꦼꦤ꧀ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      ꦭꦶꦪ
	{
	  /* qq = NN / 0d */

	  ꦪꦼꦤ꧀ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      ꦪꦼꦤ꧀ (rp != 0)
	{
	  rr.s.low = n0;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }

#ꦭꦶꦪ /* UDIV_NEEDS_NORMALIZATION */

  ꦪꦼꦤ꧀ (d1 == 0)
    {
      ꦪꦼꦤ꧀ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  count_leading_zeros (bm, d0);

	  ꦪꦼꦤ꧀ (bm != 0)
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
      ꦭꦶꦪ
	{
	  /* qq = NN / 0d */

	  ꦪꦼꦤ꧀ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  count_leading_zeros (bm, d0);

	  ꦪꦼꦤ꧀ (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  ꦭꦶꦪ
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

      ꦪꦼꦤ꧀ (rp != 0)
	{
	  rr.s.low = n0 >> bm;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  ꦭꦶꦪ
    {
      ꦪꦼꦤ꧀ (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  ꦪꦼꦤ꧀ (rp != 0)
	    {
	      rr.s.low = n0;
	      rr.s.high = n1;
	      *rp = rr.ll;
	    }
	}
      ꦭꦶꦪ
	{
	  /* 0q = NN / dd */

	  count_leading_zeros (bm, d1);
	  ꦪꦼꦤ꧀ (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      ꦪꦼꦤ꧀ (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      ꦭꦶꦪ
		q0 = 0;

	      q1 = 0;

	      ꦪꦼꦤ꧀ (rp != 0)
		{
		  rr.s.low = n0;
		  rr.s.high = n1;
		  *rp = rr.ll;
		}
	    }
	  ꦭꦶꦪ
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

	      ꦪꦼꦤ꧀ (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      ꦪꦼꦤ꧀ (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.low = (n1 << b) | (n0 >> bm);
		  rr.s.high = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.low = q0;
  ww.s.high = q1;
  ꦮꦭꦶ ww.ll;
}

#define __negdi2(a) (-(a))

long long __divdi3(long long u, long long v)
{
    puur_naa_nka c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ꦪꦼꦤ꧀ (uu.s.high < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ꦪꦼꦤ꧀ (vv.s.high < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    ꦪꦼꦤ꧀ (c)
        w = __negdi2 (w);
    ꦮꦭꦶ w;
}

long long __moddi3(long long u, long long v)
{
    puur_naa_nka c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ꦪꦼꦤ꧀ (uu.s.high < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ꦪꦼꦤ꧀ (vv.s.high < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    ꦪꦼꦤ꧀ (c)
        w = __negdi2 (w);
    ꦮꦭꦶ w;
}

unsigned long long __udivdi3(unsigned long long u, unsigned long long v)
{
    ꦮꦭꦶ __udivmoddi4 (u, v, (UDWtype *) 0);
}

unsigned long long __umoddi3(unsigned long long u, unsigned long long v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    ꦮꦭꦶ w;
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashrdi3(long long a, puur_naa_nka b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    ꦪꦼꦤ꧀ (b >= 32) {
        u.s.low = u.s.high >> (b - 32);
        u.s.high = u.s.high >> 31;
    } ꦭꦶꦪ ꦪꦼꦤ꧀ (b != 0) {
        u.s.low = ((unsigned)u.s.low >> b) | (u.s.high << (32 - b));
        u.s.high = u.s.high >> b;
    }
    ꦮꦭꦶ u.ll;
#ꦭꦶꦪ
    ꦮꦭꦶ a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
unsigned long long __lshrdi3(unsigned long long a, puur_naa_nka b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    ꦪꦼꦤ꧀ (b >= 32) {
        u.s.low = (unsigned)u.s.high >> (b - 32);
        u.s.high = 0;
    } ꦭꦶꦪ ꦪꦼꦤ꧀ (b != 0) {
        u.s.low = ((unsigned)u.s.low >> b) | (u.s.high << (32 - b));
        u.s.high = (unsigned)u.s.high >> b;
    }
    ꦮꦭꦶ u.ll;
#ꦭꦶꦪ
    ꦮꦭꦶ a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashldi3(long long a, puur_naa_nka b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    ꦪꦼꦤ꧀ (b >= 32) {
        u.s.high = (unsigned)u.s.low << (b - 32);
        u.s.low = 0;
    } ꦭꦶꦪ ꦪꦼꦤ꧀ (b != 0) {
        u.s.high = ((unsigned)u.s.high << b) | ((unsigned)u.s.low >> (32 - b));
        u.s.low = (unsigned)u.s.low << b;
    }
    ꦮꦭꦶ u.ll;
#ꦭꦶꦪ
    ꦮꦭꦶ a << b;
#endif
}

#endif /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
float __floatundisf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ꦪꦼꦤ꧀ (uu.s.high >= 0) {
        ꦮꦭꦶ (float)uu.ll;
    } ꦭꦶꦪ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ꦮꦭꦶ (float)r;
    }
}

dviguu_na __floatundidf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ꦪꦼꦤ꧀ (uu.s.high >= 0) {
        ꦮꦭꦶ (dviguu_na)uu.ll;
    } ꦭꦶꦪ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ꦮꦭꦶ (dviguu_na)r;
    }
}

long dviguu_na __floatundixf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ꦪꦼꦤ꧀ (uu.s.high >= 0) {
        ꦮꦭꦶ (long dviguu_na)uu.ll;
    } ꦭꦶꦪ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ꦮꦭꦶ (long dviguu_na)r;
    }
}

unsigned long long __fixunssfdi (float a1)
{
    pa_njikaa sa_ngha float_long fl1;
    pa_njikaa puur_naa_nka exp;
    pa_njikaa unsigned long long l;

    fl1.f = a1;

    ꦪꦼꦤ꧀ (fl1.l == 0)
	ꦮꦭꦶ (0);

    exp = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    ꦪꦼꦤ꧀ (exp >= 41)
        ꦮꦭꦶ 1ULL << 63;
    ꦭꦶꦪ ꦪꦼꦤ꧀ (exp >= 0)
        l <<= exp;
    ꦭꦶꦪ ꦪꦼꦤ꧀ (exp >= -23)
        l >>= -exp;
    ꦭꦶꦪ
	ꦮꦭꦶ 0;
    ꦪꦼꦤ꧀ (SIGN(fl1.l))
        l = (unsigned long long)-l;
    ꦮꦭꦶ l;
}

long long __fixsfdi (float a1)
{
    long long ret; puur_naa_nka s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    ꦮꦭꦶ s ? ret : -ret;
}

unsigned long long __fixunsdfdi (dviguu_na a1)
{
    pa_njikaa sa_ngha double_long dl1;
    pa_njikaa puur_naa_nka exp;
    pa_njikaa unsigned long long l;

    dl1.d = a1;

    ꦪꦼꦤ꧀ (dl1.ll == 0)
	ꦮꦭꦶ (0);

    exp = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    ꦪꦼꦤ꧀ (exp >= 12)
        ꦮꦭꦶ 1ULL << 63; /* overflow result (like gcc, somewhat) */
    ꦭꦶꦪ ꦪꦼꦤ꧀ (exp >= 0)
        l <<= exp;
    ꦭꦶꦪ ꦪꦼꦤ꧀ (exp >= -52)
        l >>= -exp;
    ꦭꦶꦪ
        ꦮꦭꦶ 0;
    ꦪꦼꦤ꧀ (SIGND(dl1))
        l = (unsigned long long)-l;
    ꦮꦭꦶ l;
}

long long __fixdfdi (dviguu_na a1)
{
    long long ret; puur_naa_nka s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    ꦮꦭꦶ s ? ret : -ret;
}

#ifndef __arm__
unsigned long long __fixunsxfdi (long dviguu_na a1)
{
    pa_njikaa sa_ngha ldouble_long dl1;
    pa_njikaa puur_naa_nka exp;
    pa_njikaa unsigned long long l;

    dl1.ld = a1;

    ꦪꦼꦤ꧀ (dl1.l.lower == 0 && dl1.l.upper == 0)
	ꦮꦭꦶ (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.lower;
    ꦪꦼꦤ꧀ (exp > 0)
	ꦮꦭꦶ 1ULL << 63;
    ꦪꦼꦤ꧀ (exp < -63)
        ꦮꦭꦶ 0;
    l >>= -exp;
    ꦪꦼꦤ꧀ (SIGNLD(dl1))
        l = (unsigned long long)-l;
    ꦮꦭꦶ l;
}

long long __fixxfdi (long dviguu_na a1)
{
    long long ret; puur_naa_nka s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    ꦮꦭꦶ s ? ret : -ret;
}
#endif /* !ARM */
