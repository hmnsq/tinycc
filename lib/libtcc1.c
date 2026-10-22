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

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ Wtype;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ UWtype;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ USItype;
ಪ್ರಕಾರನಿರ್ದೇಶ long long DWtype;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long long UDWtype;

ಸಂರಚನಾ DWstruct {
    Wtype ಕೆಳಗಿನ, ಮೇಲಿನ;
};

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ
{
  ಸಂರಚನಾ DWstruct s;
  DWtype ll;
} DWunion;

ಪ್ರಕಾರನಿರ್ದೇಶ long ದ್ವಿಗುಣ XFtype;
#define WORD_SIZE (ಪರಿಮಾಣ (Wtype) * BITS_PER_UNIT)
#define ಮೇಲಿನ_WORD_COEFF (((UDWtype) 1) << WORD_SIZE)

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
ಸಙ್ಘ ldouble_long {
    long ದ್ವಿಗುಣ ld;
    ಸಂರಚನಾ {
        unsigned long long lower;
        unsigned short upper;
    } l;
};

ಸಙ್ಘ double_long {
    ದ್ವಿಗುಣ d;
#ಯದಿ 1
    ಸಂರಚನಾ {
        unsigned ಪೂರ್ಣಾಙ್ಕ lower;
        ಪೂರ್ಣಾಙ್ಕ upper;
    } l;
#ಅನ್ಯಥಾ
    ಸಂರಚನಾ {
        ಪೂರ್ಣಾಙ್ಕ upper;
        unsigned ಪೂರ್ಣಾಙ್ಕ lower;
    } l;
#endif
    long long ll;
};

ಸಙ್ಘ float_long {
    ಭಿನ್ನ f;
    unsigned ಪೂರ್ಣಾಙ್ಕ l;
};

/* XXX: we don't support several builtin supports for now */
#ಯದಿ defined __i386__

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
#define ಎಣಿಕೆ_leading_zeros(ಎಣಿಕೆ_2, x) \
  ಕುರು {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (ಎಣಿಕೆ_2) = __cbtmp ^ 31;						\
  } ಯಾವತ್ (0)

/* most of this code is taken from libgcc2.c from gcc */

ಸ್ಥಿರ UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.ಕೆಳಗಿನ;
  d1 = dd.s.ಮೇಲಿನ;
  n0 = nn.s.ಕೆಳಗಿನ;
  n1 = nn.s.ಮೇಲಿನ;

#ಯದಿ !defined(UDIV_NEEDS_NORMALIZATION)
  ಯದಿ (d1 == 0)
    {
      ಯದಿ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      ಅನ್ಯಥಾ
	{
	  /* qq = NN / 0d */

	  ಯದಿ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      ಯದಿ (rp != 0)
	{
	  rr.s.ಕೆಳಗಿನ = n0;
	  rr.s.ಮೇಲಿನ = 0;
	  *rp = rr.ll;
	}
    }

#ಅನ್ಯಥಾ /* UDIV_NEEDS_NORMALIZATION */

  ಯದಿ (d1 == 0)
    {
      ಯದಿ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  ಎಣಿಕೆ_leading_zeros (bm, d0);

	  ಯದಿ (bm != 0)
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
      ಅನ್ಯಥಾ
	{
	  /* qq = NN / 0d */

	  ಯದಿ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  ಎಣಿಕೆ_leading_zeros (bm, d0);

	  ಯದಿ (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  ಅನ್ಯಥಾ
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

      ಯದಿ (rp != 0)
	{
	  rr.s.ಕೆಳಗಿನ = n0 >> bm;
	  rr.s.ಮೇಲಿನ = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  ಅನ್ಯಥಾ
    {
      ಯದಿ (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  ಯದಿ (rp != 0)
	    {
	      rr.s.ಕೆಳಗಿನ = n0;
	      rr.s.ಮೇಲಿನ = n1;
	      *rp = rr.ll;
	    }
	}
      ಅನ್ಯಥಾ
	{
	  /* 0q = NN / dd */

	  ಎಣಿಕೆ_leading_zeros (bm, d1);
	  ಯದಿ (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      ಯದಿ (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      ಅನ್ಯಥಾ
		q0 = 0;

	      q1 = 0;

	      ಯದಿ (rp != 0)
		{
		  rr.s.ಕೆಳಗಿನ = n0;
		  rr.s.ಮೇಲಿನ = n1;
		  *rp = rr.ll;
		}
	    }
	  ಅನ್ಯಥಾ
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

	      ಯದಿ (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      ಯದಿ (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.ಕೆಳಗಿನ = (n1 << b) | (n0 >> bm);
		  rr.s.ಮೇಲಿನ = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.ಕೆಳಗಿನ = q0;
  ww.s.ಮೇಲಿನ = q1;
  ಪ್ರತ್ಯಾಗಮ ww.ll;
}

#define __negdi2(a) (-(a))

long long __divdi3(long long u, long long v)
{
    ಪೂರ್ಣಾಙ್ಕ c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ಯದಿ (uu.s.ಮೇಲಿನ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ಯದಿ (vv.s.ಮೇಲಿನ < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    ಯದಿ (c)
        w = __negdi2 (w);
    ಪ್ರತ್ಯಾಗಮ w;
}

long long __moddi3(long long u, long long v)
{
    ಪೂರ್ಣಾಙ್ಕ c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ಯದಿ (uu.s.ಮೇಲಿನ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ಯದಿ (vv.s.ಮೇಲಿನ < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    ಯದಿ (c)
        w = __negdi2 (w);
    ಪ್ರತ್ಯಾಗಮ w;
}

unsigned long long __udivdi3(unsigned long long u, unsigned long long v)
{
    ಪ್ರತ್ಯಾಗಮ __udivmoddi4 (u, v, (UDWtype *) 0);
}

unsigned long long __umoddi3(unsigned long long u, unsigned long long v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    ಪ್ರತ್ಯಾಗಮ w;
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashrdi3(long long a, ಪೂರ್ಣಾಙ್ಕ b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    ಯದಿ (b >= 32) {
        u.s.ಕೆಳಗಿನ = u.s.ಮೇಲಿನ >> (b - 32);
        u.s.ಮೇಲಿನ = u.s.ಮೇಲಿನ >> 31;
    } ಅನ್ಯಥಾ ಯದಿ (b != 0) {
        u.s.ಕೆಳಗಿನ = ((unsigned)u.s.ಕೆಳಗಿನ >> b) | (u.s.ಮೇಲಿನ << (32 - b));
        u.s.ಮೇಲಿನ = u.s.ಮೇಲಿನ >> b;
    }
    ಪ್ರತ್ಯಾಗಮ u.ll;
#ಅನ್ಯಥಾ
    ಪ್ರತ್ಯಾಗಮ a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
unsigned long long __lshrdi3(unsigned long long a, ಪೂರ್ಣಾಙ್ಕ b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    ಯದಿ (b >= 32) {
        u.s.ಕೆಳಗಿನ = (unsigned)u.s.ಮೇಲಿನ >> (b - 32);
        u.s.ಮೇಲಿನ = 0;
    } ಅನ್ಯಥಾ ಯದಿ (b != 0) {
        u.s.ಕೆಳಗಿನ = ((unsigned)u.s.ಕೆಳಗಿನ >> b) | (u.s.ಮೇಲಿನ << (32 - b));
        u.s.ಮೇಲಿನ = (unsigned)u.s.ಮೇಲಿನ >> b;
    }
    ಪ್ರತ್ಯಾಗಮ u.ll;
#ಅನ್ಯಥಾ
    ಪ್ರತ್ಯಾಗಮ a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashldi3(long long a, ಪೂರ್ಣಾಙ್ಕ b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    ಯದಿ (b >= 32) {
        u.s.ಮೇಲಿನ = (unsigned)u.s.ಕೆಳಗಿನ << (b - 32);
        u.s.ಕೆಳಗಿನ = 0;
    } ಅನ್ಯಥಾ ಯದಿ (b != 0) {
        u.s.ಮೇಲಿನ = ((unsigned)u.s.ಮೇಲಿನ << b) | ((unsigned)u.s.ಕೆಳಗಿನ >> (32 - b));
        u.s.ಕೆಳಗಿನ = (unsigned)u.s.ಕೆಳಗಿನ << b;
    }
    ಪ್ರತ್ಯಾಗಮ u.ll;
#ಅನ್ಯಥಾ
    ಪ್ರತ್ಯಾಗಮ a << b;
#endif
}

#endif /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
ಭಿನ್ನ __floatundisf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ಯದಿ (uu.s.ಮೇಲಿನ >= 0) {
        ಪ್ರತ್ಯಾಗಮ (ಭಿನ್ನ)uu.ll;
    } ಅನ್ಯಥಾ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ಪ್ರತ್ಯಾಗಮ (ಭಿನ್ನ)r;
    }
}

ದ್ವಿಗುಣ __floatundidf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ಯದಿ (uu.s.ಮೇಲಿನ >= 0) {
        ಪ್ರತ್ಯಾಗಮ (ದ್ವಿಗುಣ)uu.ll;
    } ಅನ್ಯಥಾ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ಪ್ರತ್ಯಾಗಮ (ದ್ವಿಗುಣ)r;
    }
}

long ದ್ವಿಗುಣ __floatundixf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ಯದಿ (uu.s.ಮೇಲಿನ >= 0) {
        ಪ್ರತ್ಯಾಗಮ (long ದ್ವಿಗುಣ)uu.ll;
    } ಅನ್ಯಥಾ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ಪ್ರತ್ಯಾಗಮ (long ದ್ವಿಗುಣ)r;
    }
}

unsigned long long __fixunssfdi (ಭಿನ್ನ a1)
{
    ಪಞ್ಜಿಕಾ ಸಙ್ಘ float_long fl1;
    ಪಞ್ಜಿಕಾ ಪೂರ್ಣಾಙ್ಕ exp;
    ಪಞ್ಜಿಕಾ unsigned long long l;

    fl1.f = a1;

    ಯದಿ (fl1.l == 0)
	ಪ್ರತ್ಯಾಗಮ (0);

    exp = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    ಯದಿ (exp >= 41)
        ಪ್ರತ್ಯಾಗಮ 1ULL << 63;
    ಅನ್ಯಥಾ ಯದಿ (exp >= 0)
        l <<= exp;
    ಅನ್ಯಥಾ ಯದಿ (exp >= -23)
        l >>= -exp;
    ಅನ್ಯಥಾ
	ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (SIGN(fl1.l))
        l = (unsigned long long)-l;
    ಪ್ರತ್ಯಾಗಮ l;
}

long long __fixsfdi (ಭಿನ್ನ a1)
{
    long long ret; ಪೂರ್ಣಾಙ್ಕ s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    ಪ್ರತ್ಯಾಗಮ s ? ret : -ret;
}

unsigned long long __fixunsdfdi (ದ್ವಿಗುಣ a1)
{
    ಪಞ್ಜಿಕಾ ಸಙ್ಘ double_long dl1;
    ಪಞ್ಜಿಕಾ ಪೂರ್ಣಾಙ್ಕ exp;
    ಪಞ್ಜಿಕಾ unsigned long long l;

    dl1.d = a1;

    ಯದಿ (dl1.ll == 0)
	ಪ್ರತ್ಯಾಗಮ (0);

    exp = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    ಯದಿ (exp >= 12)
        ಪ್ರತ್ಯಾಗಮ 1ULL << 63; /* overflow result (like gcc, somewhat) */
    ಅನ್ಯಥಾ ಯದಿ (exp >= 0)
        l <<= exp;
    ಅನ್ಯಥಾ ಯದಿ (exp >= -52)
        l >>= -exp;
    ಅನ್ಯಥಾ
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (SIGND(dl1))
        l = (unsigned long long)-l;
    ಪ್ರತ್ಯಾಗಮ l;
}

long long __fixdfdi (ದ್ವಿಗುಣ a1)
{
    long long ret; ಪೂರ್ಣಾಙ್ಕ s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    ಪ್ರತ್ಯಾಗಮ s ? ret : -ret;
}

#ifndef __arm__
unsigned long long __fixunsxfdi (long ದ್ವಿಗುಣ a1)
{
    ಪಞ್ಜಿಕಾ ಸಙ್ಘ ldouble_long dl1;
    ಪಞ್ಜಿಕಾ ಪೂರ್ಣಾಙ್ಕ exp;
    ಪಞ್ಜಿಕಾ unsigned long long l;

    dl1.ld = a1;

    ಯದಿ (dl1.l.lower == 0 && dl1.l.upper == 0)
	ಪ್ರತ್ಯಾಗಮ (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.lower;
    ಯದಿ (exp > 0)
	ಪ್ರತ್ಯಾಗಮ 1ULL << 63;
    ಯದಿ (exp < -63)
        ಪ್ರತ್ಯಾಗಮ 0;
    l >>= -exp;
    ಯದಿ (SIGNLD(dl1))
        l = (unsigned long long)-l;
    ಪ್ರತ್ಯಾಗಮ l;
}

long long __fixxfdi (long ದ್ವಿಗುಣ a1)
{
    long long ret; ಪೂರ್ಣಾಙ್ಕ s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    ಪ್ರತ್ಯಾಗಮ s ? ret : -ret;
}
#endif /* !ARM */
