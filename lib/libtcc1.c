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

#define W_TYPE_আকার   32
#define BITS_PER_UNIT 8

প্রকারলেখ পূর্ণসংখ্যা Wtype;
প্রকারলেখ unsigned পূর্ণসংখ্যা UWtype;
প্রকারলেখ unsigned পূর্ণসংখ্যা USItype;
প্রকারলেখ long long DWtype;
প্রকারলেখ unsigned long long UDWtype;

কাঠামো DWstruct {
    Wtype নিচের, উপরের;
};

প্রকারলেখ সংঘ
{
  কাঠামো DWstruct s;
  DWtype ll;
} DWunion;

প্রকারলেখ long দ্বিগুণ XFtype;
#define WORD_আকার (আকার (Wtype) * BITS_PER_UNIT)
#define উপরের_WORD_COEFF (((UDWtype) 1) << WORD_আকার)

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
সংঘ ldouble_long {
    long দ্বিগুণ ld;
    কাঠামো {
        unsigned long long lower;
        unsigned short upper;
    } l;
};

সংঘ double_long {
    দ্বিগুণ d;
#যদি 1
    কাঠামো {
        unsigned পূর্ণসংখ্যা lower;
        পূর্ণসংখ্যা upper;
    } l;
#অন্যথা
    কাঠামো {
        পূর্ণসংখ্যা upper;
        unsigned পূর্ণসংখ্যা lower;
    } l;
#endif
    long long ll;
};

সংঘ float_long {
    দশমিক f;
    unsigned পূর্ণসংখ্যা l;
};

/* XXX: we don't support several builtin supports for now */
#যদি defined __i386__

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
#define গুনতি_leading_zeros(গুনতি_2, x) \
  করো {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (গুনতি_2) = __cbtmp ^ 31;						\
  } যখন (0)

/* most of this code is taken from libgcc2.c from gcc */

স্থির UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.নিচের;
  d1 = dd.s.উপরের;
  n0 = nn.s.নিচের;
  n1 = nn.s.উপরের;

#যদি !defined(UDIV_NEEDS_NORMALIZATION)
  যদি (d1 == 0)
    {
      যদি (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      অন্যথা
	{
	  /* qq = NN / 0d */

	  যদি (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      যদি (rp != 0)
	{
	  rr.s.নিচের = n0;
	  rr.s.উপরের = 0;
	  *rp = rr.ll;
	}
    }

#অন্যথা /* UDIV_NEEDS_NORMALIZATION */

  যদি (d1 == 0)
    {
      যদি (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  গুনতি_leading_zeros (bm, d0);

	  যদি (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_আকার - bm));
	      n0 = n0 << bm;
	    }

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0 >> bm.  */
	}
      অন্যথা
	{
	  /* qq = NN / 0d */

	  যদি (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  গুনতি_leading_zeros (bm, d0);

	  যদি (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  অন্যথা
	    {
	      /* Normalize.  */

	      b = W_TYPE_আকার - bm;

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

      যদি (rp != 0)
	{
	  rr.s.নিচের = n0 >> bm;
	  rr.s.উপরের = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  অন্যথা
    {
      যদি (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  যদি (rp != 0)
	    {
	      rr.s.নিচের = n0;
	      rr.s.উপরের = n1;
	      *rp = rr.ll;
	    }
	}
      অন্যথা
	{
	  /* 0q = NN / dd */

	  গুনতি_leading_zeros (bm, d1);
	  যদি (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      যদি (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      অন্যথা
		q0 = 0;

	      q1 = 0;

	      যদি (rp != 0)
		{
		  rr.s.নিচের = n0;
		  rr.s.উপরের = n1;
		  *rp = rr.ll;
		}
	    }
	  অন্যথা
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_আকার - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);

	      যদি (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      যদি (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.নিচের = (n1 << b) | (n0 >> bm);
		  rr.s.উপরের = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.নিচের = q0;
  ww.s.উপরের = q1;
  ফেরত ww.ll;
}

#define __negdi2(a) (-(a))

long long __divdi3(long long u, long long v)
{
    পূর্ণসংখ্যা c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    যদি (uu.s.উপরের < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    যদি (vv.s.উপরের < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    যদি (c)
        w = __negdi2 (w);
    ফেরত w;
}

long long __moddi3(long long u, long long v)
{
    পূর্ণসংখ্যা c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    যদি (uu.s.উপরের < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    যদি (vv.s.উপরের < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    যদি (c)
        w = __negdi2 (w);
    ফেরত w;
}

unsigned long long __udivdi3(unsigned long long u, unsigned long long v)
{
    ফেরত __udivmoddi4 (u, v, (UDWtype *) 0);
}

unsigned long long __umoddi3(unsigned long long u, unsigned long long v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    ফেরত w;
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashrdi3(long long a, পূর্ণসংখ্যা b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    যদি (b >= 32) {
        u.s.নিচের = u.s.উপরের >> (b - 32);
        u.s.উপরের = u.s.উপরের >> 31;
    } অন্যথা যদি (b != 0) {
        u.s.নিচের = ((unsigned)u.s.নিচের >> b) | (u.s.উপরের << (32 - b));
        u.s.উপরের = u.s.উপরের >> b;
    }
    ফেরত u.ll;
#অন্যথা
    ফেরত a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
unsigned long long __lshrdi3(unsigned long long a, পূর্ণসংখ্যা b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    যদি (b >= 32) {
        u.s.নিচের = (unsigned)u.s.উপরের >> (b - 32);
        u.s.উপরের = 0;
    } অন্যথা যদি (b != 0) {
        u.s.নিচের = ((unsigned)u.s.নিচের >> b) | (u.s.উপরের << (32 - b));
        u.s.উপরের = (unsigned)u.s.উপরের >> b;
    }
    ফেরত u.ll;
#অন্যথা
    ফেরত a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashldi3(long long a, পূর্ণসংখ্যা b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    যদি (b >= 32) {
        u.s.উপরের = (unsigned)u.s.নিচের << (b - 32);
        u.s.নিচের = 0;
    } অন্যথা যদি (b != 0) {
        u.s.উপরের = ((unsigned)u.s.উপরের << b) | ((unsigned)u.s.নিচের >> (32 - b));
        u.s.নিচের = (unsigned)u.s.নিচের << b;
    }
    ফেরত u.ll;
#অন্যথা
    ফেরত a << b;
#endif
}

#endif /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
দশমিক __floatundisf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    যদি (uu.s.উপরের >= 0) {
        ফেরত (দশমিক)uu.ll;
    } অন্যথা {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ফেরত (দশমিক)r;
    }
}

দ্বিগুণ __floatundidf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    যদি (uu.s.উপরের >= 0) {
        ফেরত (দ্বিগুণ)uu.ll;
    } অন্যথা {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ফেরত (দ্বিগুণ)r;
    }
}

long দ্বিগুণ __floatundixf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    যদি (uu.s.উপরের >= 0) {
        ফেরত (long দ্বিগুণ)uu.ll;
    } অন্যথা {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ফেরত (long দ্বিগুণ)r;
    }
}

unsigned long long __fixunssfdi (দশমিক a1)
{
    নিবন্ধ সংঘ float_long fl1;
    নিবন্ধ পূর্ণসংখ্যা exp;
    নিবন্ধ unsigned long long l;

    fl1.f = a1;

    যদি (fl1.l == 0)
	ফেরত (0);

    exp = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    যদি (exp >= 41)
        ফেরত 1ULL << 63;
    অন্যথা যদি (exp >= 0)
        l <<= exp;
    অন্যথা যদি (exp >= -23)
        l >>= -exp;
    অন্যথা
	ফেরত 0;
    যদি (SIGN(fl1.l))
        l = (unsigned long long)-l;
    ফেরত l;
}

long long __fixsfdi (দশমিক a1)
{
    long long ret; পূর্ণসংখ্যা s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    ফেরত s ? ret : -ret;
}

unsigned long long __fixunsdfdi (দ্বিগুণ a1)
{
    নিবন্ধ সংঘ double_long dl1;
    নিবন্ধ পূর্ণসংখ্যা exp;
    নিবন্ধ unsigned long long l;

    dl1.d = a1;

    যদি (dl1.ll == 0)
	ফেরত (0);

    exp = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    যদি (exp >= 12)
        ফেরত 1ULL << 63; /* overflow result (like gcc, somewhat) */
    অন্যথা যদি (exp >= 0)
        l <<= exp;
    অন্যথা যদি (exp >= -52)
        l >>= -exp;
    অন্যথা
        ফেরত 0;
    যদি (SIGND(dl1))
        l = (unsigned long long)-l;
    ফেরত l;
}

long long __fixdfdi (দ্বিগুণ a1)
{
    long long ret; পূর্ণসংখ্যা s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    ফেরত s ? ret : -ret;
}

#ifndef __arm__
unsigned long long __fixunsxfdi (long দ্বিগুণ a1)
{
    নিবন্ধ সংঘ ldouble_long dl1;
    নিবন্ধ পূর্ণসংখ্যা exp;
    নিবন্ধ unsigned long long l;

    dl1.ld = a1;

    যদি (dl1.l.lower == 0 && dl1.l.upper == 0)
	ফেরত (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.lower;
    যদি (exp > 0)
	ফেরত 1ULL << 63;
    যদি (exp < -63)
        ফেরত 0;
    l >>= -exp;
    যদি (SIGNLD(dl1))
        l = (unsigned long long)-l;
    ফেরত l;
}

long long __fixxfdi (long দ্বিগুণ a1)
{
    long long ret; পূর্ণসংখ্যা s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    ফেরত s ? ret : -ret;
}
#endif /* !ARM */
