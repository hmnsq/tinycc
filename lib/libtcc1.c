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

തരനിർവചനം പൂർണ്ണസംഖ്യ Wtype;
തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ UWtype;
തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ USItype;
തരനിർവചനം long long DWtype;
തരനിർവചനം unsigned long long UDWtype;

ഘടന DWstruct {
    Wtype താഴെയുള്ള, മുകളിലെ;
};

തരനിർവചനം സംഘം
{
  ഘടന DWstruct s;
  DWtype ll;
} DWunion;

തരനിർവചനം long ഇരട്ട XFtype;
#define WORD_SIZE (വലുപ്പം (Wtype) * BITS_PER_UNIT)
#define മുകളിലെ_WORD_COEFF (((UDWtype) 1) << WORD_SIZE)

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
സംഘം ldouble_long {
    long ഇരട്ട ld;
    ഘടന {
        unsigned long long lower;
        unsigned short upper;
    } l;
};

സംഘം double_long {
    ഇരട്ട d;
#എങ്കിൽ 1
    ഘടന {
        unsigned പൂർണ്ണസംഖ്യ lower;
        പൂർണ്ണസംഖ്യ upper;
    } l;
#അല്ലെങ്കിൽ
    ഘടന {
        പൂർണ്ണസംഖ്യ upper;
        unsigned പൂർണ്ണസംഖ്യ lower;
    } l;
#endif
    long long ll;
};

സംഘം float_long {
    ദശാംശം f;
    unsigned പൂർണ്ണസംഖ്യ l;
};

/* XXX: we don't support several builtin supports for now */
#എങ്കിൽ defined __i386__

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
#define എണ്ണം_leading_zeros(എണ്ണം_2, x) \
  ചെയ്യുക {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (എണ്ണം_2) = __cbtmp ^ 31;						\
  } ആകുമ്പോൾ (0)

/* most of this code is taken from libgcc2.c from gcc */

സ്ഥിതം UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.താഴെയുള്ള;
  d1 = dd.s.മുകളിലെ;
  n0 = nn.s.താഴെയുള്ള;
  n1 = nn.s.മുകളിലെ;

#എങ്കിൽ !defined(UDIV_NEEDS_NORMALIZATION)
  എങ്കിൽ (d1 == 0)
    {
      എങ്കിൽ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      അല്ലെങ്കിൽ
	{
	  /* qq = NN / 0d */

	  എങ്കിൽ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      എങ്കിൽ (rp != 0)
	{
	  rr.s.താഴെയുള്ള = n0;
	  rr.s.മുകളിലെ = 0;
	  *rp = rr.ll;
	}
    }

#അല്ലെങ്കിൽ /* UDIV_NEEDS_NORMALIZATION */

  എങ്കിൽ (d1 == 0)
    {
      എങ്കിൽ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  എണ്ണം_leading_zeros (bm, d0);

	  എങ്കിൽ (bm != 0)
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
      അല്ലെങ്കിൽ
	{
	  /* qq = NN / 0d */

	  എങ്കിൽ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  എണ്ണം_leading_zeros (bm, d0);

	  എങ്കിൽ (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  അല്ലെങ്കിൽ
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

      എങ്കിൽ (rp != 0)
	{
	  rr.s.താഴെയുള്ള = n0 >> bm;
	  rr.s.മുകളിലെ = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  അല്ലെങ്കിൽ
    {
      എങ്കിൽ (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  എങ്കിൽ (rp != 0)
	    {
	      rr.s.താഴെയുള്ള = n0;
	      rr.s.മുകളിലെ = n1;
	      *rp = rr.ll;
	    }
	}
      അല്ലെങ്കിൽ
	{
	  /* 0q = NN / dd */

	  എണ്ണം_leading_zeros (bm, d1);
	  എങ്കിൽ (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      എങ്കിൽ (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      അല്ലെങ്കിൽ
		q0 = 0;

	      q1 = 0;

	      എങ്കിൽ (rp != 0)
		{
		  rr.s.താഴെയുള്ള = n0;
		  rr.s.മുകളിലെ = n1;
		  *rp = rr.ll;
		}
	    }
	  അല്ലെങ്കിൽ
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

	      എങ്കിൽ (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      എങ്കിൽ (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.താഴെയുള്ള = (n1 << b) | (n0 >> bm);
		  rr.s.മുകളിലെ = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.താഴെയുള്ള = q0;
  ww.s.മുകളിലെ = q1;
  തിരികെ ww.ll;
}

#define __negdi2(a) (-(a))

long long __divdi3(long long u, long long v)
{
    പൂർണ്ണസംഖ്യ c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    എങ്കിൽ (uu.s.മുകളിലെ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    എങ്കിൽ (vv.s.മുകളിലെ < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    എങ്കിൽ (c)
        w = __negdi2 (w);
    തിരികെ w;
}

long long __moddi3(long long u, long long v)
{
    പൂർണ്ണസംഖ്യ c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    എങ്കിൽ (uu.s.മുകളിലെ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    എങ്കിൽ (vv.s.മുകളിലെ < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    എങ്കിൽ (c)
        w = __negdi2 (w);
    തിരികെ w;
}

unsigned long long __udivdi3(unsigned long long u, unsigned long long v)
{
    തിരികെ __udivmoddi4 (u, v, (UDWtype *) 0);
}

unsigned long long __umoddi3(unsigned long long u, unsigned long long v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    തിരികെ w;
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashrdi3(long long a, പൂർണ്ണസംഖ്യ b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    എങ്കിൽ (b >= 32) {
        u.s.താഴെയുള്ള = u.s.മുകളിലെ >> (b - 32);
        u.s.മുകളിലെ = u.s.മുകളിലെ >> 31;
    } അല്ലെങ്കിൽ എങ്കിൽ (b != 0) {
        u.s.താഴെയുള്ള = ((unsigned)u.s.താഴെയുള്ള >> b) | (u.s.മുകളിലെ << (32 - b));
        u.s.മുകളിലെ = u.s.മുകളിലെ >> b;
    }
    തിരികെ u.ll;
#അല്ലെങ്കിൽ
    തിരികെ a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
unsigned long long __lshrdi3(unsigned long long a, പൂർണ്ണസംഖ്യ b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    എങ്കിൽ (b >= 32) {
        u.s.താഴെയുള്ള = (unsigned)u.s.മുകളിലെ >> (b - 32);
        u.s.മുകളിലെ = 0;
    } അല്ലെങ്കിൽ എങ്കിൽ (b != 0) {
        u.s.താഴെയുള്ള = ((unsigned)u.s.താഴെയുള്ള >> b) | (u.s.മുകളിലെ << (32 - b));
        u.s.മുകളിലെ = (unsigned)u.s.മുകളിലെ >> b;
    }
    തിരികെ u.ll;
#അല്ലെങ്കിൽ
    തിരികെ a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashldi3(long long a, പൂർണ്ണസംഖ്യ b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    എങ്കിൽ (b >= 32) {
        u.s.മുകളിലെ = (unsigned)u.s.താഴെയുള്ള << (b - 32);
        u.s.താഴെയുള്ള = 0;
    } അല്ലെങ്കിൽ എങ്കിൽ (b != 0) {
        u.s.മുകളിലെ = ((unsigned)u.s.മുകളിലെ << b) | ((unsigned)u.s.താഴെയുള്ള >> (32 - b));
        u.s.താഴെയുള്ള = (unsigned)u.s.താഴെയുള്ള << b;
    }
    തിരികെ u.ll;
#അല്ലെങ്കിൽ
    തിരികെ a << b;
#endif
}

#endif /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
ദശാംശം __floatundisf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    എങ്കിൽ (uu.s.മുകളിലെ >= 0) {
        തിരികെ (ദശാംശം)uu.ll;
    } അല്ലെങ്കിൽ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        തിരികെ (ദശാംശം)r;
    }
}

ഇരട്ട __floatundidf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    എങ്കിൽ (uu.s.മുകളിലെ >= 0) {
        തിരികെ (ഇരട്ട)uu.ll;
    } അല്ലെങ്കിൽ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        തിരികെ (ഇരട്ട)r;
    }
}

long ഇരട്ട __floatundixf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    എങ്കിൽ (uu.s.മുകളിലെ >= 0) {
        തിരികെ (long ഇരട്ട)uu.ll;
    } അല്ലെങ്കിൽ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        തിരികെ (long ഇരട്ട)r;
    }
}

unsigned long long __fixunssfdi (ദശാംശം a1)
{
    രജിസ്റ്റർ സംഘം float_long fl1;
    രജിസ്റ്റർ പൂർണ്ണസംഖ്യ exp;
    രജിസ്റ്റർ unsigned long long l;

    fl1.f = a1;

    എങ്കിൽ (fl1.l == 0)
	തിരികെ (0);

    exp = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    എങ്കിൽ (exp >= 41)
        തിരികെ 1ULL << 63;
    അല്ലെങ്കിൽ എങ്കിൽ (exp >= 0)
        l <<= exp;
    അല്ലെങ്കിൽ എങ്കിൽ (exp >= -23)
        l >>= -exp;
    അല്ലെങ്കിൽ
	തിരികെ 0;
    എങ്കിൽ (SIGN(fl1.l))
        l = (unsigned long long)-l;
    തിരികെ l;
}

long long __fixsfdi (ദശാംശം a1)
{
    long long ret; പൂർണ്ണസംഖ്യ s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    തിരികെ s ? ret : -ret;
}

unsigned long long __fixunsdfdi (ഇരട്ട a1)
{
    രജിസ്റ്റർ സംഘം double_long dl1;
    രജിസ്റ്റർ പൂർണ്ണസംഖ്യ exp;
    രജിസ്റ്റർ unsigned long long l;

    dl1.d = a1;

    എങ്കിൽ (dl1.ll == 0)
	തിരികെ (0);

    exp = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    എങ്കിൽ (exp >= 12)
        തിരികെ 1ULL << 63; /* overflow result (like gcc, somewhat) */
    അല്ലെങ്കിൽ എങ്കിൽ (exp >= 0)
        l <<= exp;
    അല്ലെങ്കിൽ എങ്കിൽ (exp >= -52)
        l >>= -exp;
    അല്ലെങ്കിൽ
        തിരികെ 0;
    എങ്കിൽ (SIGND(dl1))
        l = (unsigned long long)-l;
    തിരികെ l;
}

long long __fixdfdi (ഇരട്ട a1)
{
    long long ret; പൂർണ്ണസംഖ്യ s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    തിരികെ s ? ret : -ret;
}

#ifndef __arm__
unsigned long long __fixunsxfdi (long ഇരട്ട a1)
{
    രജിസ്റ്റർ സംഘം ldouble_long dl1;
    രജിസ്റ്റർ പൂർണ്ണസംഖ്യ exp;
    രജിസ്റ്റർ unsigned long long l;

    dl1.ld = a1;

    എങ്കിൽ (dl1.l.lower == 0 && dl1.l.upper == 0)
	തിരികെ (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.lower;
    എങ്കിൽ (exp > 0)
	തിരികെ 1ULL << 63;
    എങ്കിൽ (exp < -63)
        തിരികെ 0;
    l >>= -exp;
    എങ്കിൽ (SIGNLD(dl1))
        l = (unsigned long long)-l;
    തിരികെ l;
}

long long __fixxfdi (long ഇരട്ട a1)
{
    long long ret; പൂർണ്ണസംഖ്യ s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    തിരികെ s ? ret : -ret;
}
#endif /* !ARM */
