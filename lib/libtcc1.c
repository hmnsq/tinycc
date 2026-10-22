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

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା Wtype;
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା UWtype;
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା USItype;
ପ୍ରକାରବ୍ୟାଖ୍ୟା long long DWtype;
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned long long UDWtype;

ସଂରଚନା DWstruct {
    Wtype ତଳ, ଉପର;
};

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂଘ
{
  ସଂରଚନା DWstruct s;
  DWtype ll;
} DWunion;

ପ୍ରକାରବ୍ୟାଖ୍ୟା long ଦ୍ୱିଗୁଣ XFtype;
#define WORD_SIZE (ଆକାର (Wtype) * BITS_PER_UNIT)
#define ଉପର_WORD_COEFF (((UDWtype) 1) << WORD_SIZE)

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
ସଂଘ ldouble_long {
    long ଦ୍ୱିଗୁଣ ld;
    ସଂରଚନା {
        unsigned long long lower;
        unsigned short upper;
    } l;
};

ସଂଘ double_long {
    ଦ୍ୱିଗୁଣ d;
#ଯଦି 1
    ସଂରଚନା {
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା lower;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା upper;
    } l;
#ଅନ୍ୟଥା
    ସଂରଚନା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା upper;
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା lower;
    } l;
#endif
    long long ll;
};

ସଂଘ float_long {
    ଦଶମିକ f;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା l;
};

/* XXX: we don't support several builtin supports for now */
#ଯଦି defined __i386__

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
#define ଗଣନା_leading_zeros(ଗଣନା_3, x) \
  କର {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (ଗଣନା_3) = __cbtmp ^ 31;						\
  } ଯେତେବେଳେ (0)

/* most of this code is taken from libgcc2.c from gcc */

ସ୍ଥିର UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.ତଳ;
  d1 = dd.s.ଉପର;
  n0 = nn.s.ତଳ;
  n1 = nn.s.ଉପର;

#ଯଦି !defined(UDIV_NEEDS_NORMALIZATION)
  ଯଦି (d1 == 0)
    {
      ଯଦି (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      ଅନ୍ୟଥା
	{
	  /* qq = NN / 0d */

	  ଯଦି (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      ଯଦି (rp != 0)
	{
	  rr.s.ତଳ = n0;
	  rr.s.ଉପର = 0;
	  *rp = rr.ll;
	}
    }

#ଅନ୍ୟଥା /* UDIV_NEEDS_NORMALIZATION */

  ଯଦି (d1 == 0)
    {
      ଯଦି (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  ଗଣନା_leading_zeros (bm, d0);

	  ଯଦି (bm != 0)
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
      ଅନ୍ୟଥା
	{
	  /* qq = NN / 0d */

	  ଯଦି (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  ଗଣନା_leading_zeros (bm, d0);

	  ଯଦି (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  ଅନ୍ୟଥା
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

      ଯଦି (rp != 0)
	{
	  rr.s.ତଳ = n0 >> bm;
	  rr.s.ଉପର = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  ଅନ୍ୟଥା
    {
      ଯଦି (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  ଯଦି (rp != 0)
	    {
	      rr.s.ତଳ = n0;
	      rr.s.ଉପର = n1;
	      *rp = rr.ll;
	    }
	}
      ଅନ୍ୟଥା
	{
	  /* 0q = NN / dd */

	  ଗଣନା_leading_zeros (bm, d1);
	  ଯଦି (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      ଯଦି (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      ଅନ୍ୟଥା
		q0 = 0;

	      q1 = 0;

	      ଯଦି (rp != 0)
		{
		  rr.s.ତଳ = n0;
		  rr.s.ଉପର = n1;
		  *rp = rr.ll;
		}
	    }
	  ଅନ୍ୟଥା
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

	      ଯଦି (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      ଯଦି (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.ତଳ = (n1 << b) | (n0 >> bm);
		  rr.s.ଉପର = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.ତଳ = q0;
  ww.s.ଉପର = q1;
  ଫେରନ୍ତୁ ww.ll;
}

#define __negdi2(a) (-(a))

long long __divdi3(long long u, long long v)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ଯଦି (uu.s.ଉପର < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ଯଦି (vv.s.ଉପର < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    ଯଦି (c)
        w = __negdi2 (w);
    ଫେରନ୍ତୁ w;
}

long long __moddi3(long long u, long long v)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ଯଦି (uu.s.ଉପର < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ଯଦି (vv.s.ଉପର < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    ଯଦି (c)
        w = __negdi2 (w);
    ଫେରନ୍ତୁ w;
}

unsigned long long __udivdi3(unsigned long long u, unsigned long long v)
{
    ଫେରନ୍ତୁ __udivmoddi4 (u, v, (UDWtype *) 0);
}

unsigned long long __umoddi3(unsigned long long u, unsigned long long v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    ଫେରନ୍ତୁ w;
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashrdi3(long long a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    ଯଦି (b >= 32) {
        u.s.ତଳ = u.s.ଉପର >> (b - 32);
        u.s.ଉପର = u.s.ଉପର >> 31;
    } ଅନ୍ୟଥା ଯଦି (b != 0) {
        u.s.ତଳ = ((unsigned)u.s.ତଳ >> b) | (u.s.ଉପର << (32 - b));
        u.s.ଉପର = u.s.ଉପର >> b;
    }
    ଫେରନ୍ତୁ u.ll;
#ଅନ୍ୟଥା
    ଫେରନ୍ତୁ a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
unsigned long long __lshrdi3(unsigned long long a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    ଯଦି (b >= 32) {
        u.s.ତଳ = (unsigned)u.s.ଉପର >> (b - 32);
        u.s.ଉପର = 0;
    } ଅନ୍ୟଥା ଯଦି (b != 0) {
        u.s.ତଳ = ((unsigned)u.s.ତଳ >> b) | (u.s.ଉପର << (32 - b));
        u.s.ଉପର = (unsigned)u.s.ଉପର >> b;
    }
    ଫେରନ୍ତୁ u.ll;
#ଅନ୍ୟଥା
    ଫେରନ୍ତୁ a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashldi3(long long a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    ଯଦି (b >= 32) {
        u.s.ଉପର = (unsigned)u.s.ତଳ << (b - 32);
        u.s.ତଳ = 0;
    } ଅନ୍ୟଥା ଯଦି (b != 0) {
        u.s.ଉପର = ((unsigned)u.s.ଉପର << b) | ((unsigned)u.s.ତଳ >> (32 - b));
        u.s.ତଳ = (unsigned)u.s.ତଳ << b;
    }
    ଫେରନ୍ତୁ u.ll;
#ଅନ୍ୟଥା
    ଫେରନ୍ତୁ a << b;
#endif
}

#endif /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
ଦଶମିକ __floatundisf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ଯଦି (uu.s.ଉପର >= 0) {
        ଫେରନ୍ତୁ (ଦଶମିକ)uu.ll;
    } ଅନ୍ୟଥା {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ଫେରନ୍ତୁ (ଦଶମିକ)r;
    }
}

ଦ୍ୱିଗୁଣ __floatundidf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ଯଦି (uu.s.ଉପର >= 0) {
        ଫେରନ୍ତୁ (ଦ୍ୱିଗୁଣ)uu.ll;
    } ଅନ୍ୟଥା {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ଫେରନ୍ତୁ (ଦ୍ୱିଗୁଣ)r;
    }
}

long ଦ୍ୱିଗୁଣ __floatundixf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ଯଦି (uu.s.ଉପର >= 0) {
        ଫେରନ୍ତୁ (long ଦ୍ୱିଗୁଣ)uu.ll;
    } ଅନ୍ୟଥା {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ଫେରନ୍ତୁ (long ଦ୍ୱିଗୁଣ)r;
    }
}

unsigned long long __fixunssfdi (ଦଶମିକ a1)
{
    ପଞ୍ଜିକରଣ ସଂଘ float_long fl1;
    ପଞ୍ଜିକରଣ ପୂର୍ଣ୍ଣସଂଖ୍ୟା exp;
    ପଞ୍ଜିକରଣ unsigned long long l;

    fl1.f = a1;

    ଯଦି (fl1.l == 0)
	ଫେରନ୍ତୁ (0);

    exp = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    ଯଦି (exp >= 41)
        ଫେରନ୍ତୁ 1ULL << 63;
    ଅନ୍ୟଥା ଯଦି (exp >= 0)
        l <<= exp;
    ଅନ୍ୟଥା ଯଦି (exp >= -23)
        l >>= -exp;
    ଅନ୍ୟଥା
	ଫେରନ୍ତୁ 0;
    ଯଦି (SIGN(fl1.l))
        l = (unsigned long long)-l;
    ଫେରନ୍ତୁ l;
}

long long __fixsfdi (ଦଶମିକ a1)
{
    long long ret; ପୂର୍ଣ୍ଣସଂଖ୍ୟା s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    ଫେରନ୍ତୁ s ? ret : -ret;
}

unsigned long long __fixunsdfdi (ଦ୍ୱିଗୁଣ a1)
{
    ପଞ୍ଜିକରଣ ସଂଘ double_long dl1;
    ପଞ୍ଜିକରଣ ପୂର୍ଣ୍ଣସଂଖ୍ୟା exp;
    ପଞ୍ଜିକରଣ unsigned long long l;

    dl1.d = a1;

    ଯଦି (dl1.ll == 0)
	ଫେରନ୍ତୁ (0);

    exp = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    ଯଦି (exp >= 12)
        ଫେରନ୍ତୁ 1ULL << 63; /* overflow result (like gcc, somewhat) */
    ଅନ୍ୟଥା ଯଦି (exp >= 0)
        l <<= exp;
    ଅନ୍ୟଥା ଯଦି (exp >= -52)
        l >>= -exp;
    ଅନ୍ୟଥା
        ଫେରନ୍ତୁ 0;
    ଯଦି (SIGND(dl1))
        l = (unsigned long long)-l;
    ଫେରନ୍ତୁ l;
}

long long __fixdfdi (ଦ୍ୱିଗୁଣ a1)
{
    long long ret; ପୂର୍ଣ୍ଣସଂଖ୍ୟା s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    ଫେରନ୍ତୁ s ? ret : -ret;
}

#ifndef __arm__
unsigned long long __fixunsxfdi (long ଦ୍ୱିଗୁଣ a1)
{
    ପଞ୍ଜିକରଣ ସଂଘ ldouble_long dl1;
    ପଞ୍ଜିକରଣ ପୂର୍ଣ୍ଣସଂଖ୍ୟା exp;
    ପଞ୍ଜିକରଣ unsigned long long l;

    dl1.ld = a1;

    ଯଦି (dl1.l.lower == 0 && dl1.l.upper == 0)
	ଫେରନ୍ତୁ (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.lower;
    ଯଦି (exp > 0)
	ଫେରନ୍ତୁ 1ULL << 63;
    ଯଦି (exp < -63)
        ଫେରନ୍ତୁ 0;
    l >>= -exp;
    ଯଦି (SIGNLD(dl1))
        l = (unsigned long long)-l;
    ଫେରନ୍ତୁ l;
}

long long __fixxfdi (long ଦ୍ୱିଗୁଣ a1)
{
    long long ret; ପୂର୍ଣ୍ଣସଂଖ୍ୟା s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    ଫେରନ୍ତୁ s ? ret : -ret;
}
#endif /* !ARM */
