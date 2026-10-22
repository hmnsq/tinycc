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

પ્રકારવ્યાખ્યા પૂર્ણાંક Wtype;
પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક UWtype;
પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક USItype;
પ્રકારવ્યાખ્યા long long DWtype;
પ્રકારવ્યાખ્યા unsigned long long UDWtype;

સંરચના DWstruct {
    Wtype નીચલું, ઉપલું;
};

પ્રકારવ્યાખ્યા સંઘ
{
  સંરચના DWstruct s;
  DWtype ll;
} DWunion;

પ્રકારવ્યાખ્યા long દ્વિગુણ XFtype;
#define WORD_SIZE (કદ (Wtype) * BITS_PER_UNIT)
#define ઉપલું_WORD_COEFF (((UDWtype) 1) << WORD_SIZE)

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
સંઘ ldouble_long {
    long દ્વિગુણ ld;
    સંરચના {
        unsigned long long lower;
        unsigned short upper;
    } l;
};

સંઘ double_long {
    દ્વિગુણ d;
#જો 1
    સંરચના {
        unsigned પૂર્ણાંક lower;
        પૂર્ણાંક upper;
    } l;
#નહીંતર
    સંરચના {
        પૂર્ણાંક upper;
        unsigned પૂર્ણાંક lower;
    } l;
#endif
    long long ll;
};

સંઘ float_long {
    દશાંશ f;
    unsigned પૂર્ણાંક l;
};

/* XXX: we don't support several builtin supports for now */
#જો defined __i386__

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
#define ગણતરી_leading_zeros(ગણતરી_2, x) \
  કરો {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (ગણતરી_2) = __cbtmp ^ 31;						\
  } જ્યારે (0)

/* most of this code is taken from libgcc2.c from gcc */

સ્થિર UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.નીચલું;
  d1 = dd.s.ઉપલું;
  n0 = nn.s.નીચલું;
  n1 = nn.s.ઉપલું;

#જો !defined(UDIV_NEEDS_NORMALIZATION)
  જો (d1 == 0)
    {
      જો (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      નહીંતર
	{
	  /* qq = NN / 0d */

	  જો (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      જો (rp != 0)
	{
	  rr.s.નીચલું = n0;
	  rr.s.ઉપલું = 0;
	  *rp = rr.ll;
	}
    }

#નહીંતર /* UDIV_NEEDS_NORMALIZATION */

  જો (d1 == 0)
    {
      જો (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  ગણતરી_leading_zeros (bm, d0);

	  જો (bm != 0)
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
      નહીંતર
	{
	  /* qq = NN / 0d */

	  જો (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  ગણતરી_leading_zeros (bm, d0);

	  જો (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  નહીંતર
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

      જો (rp != 0)
	{
	  rr.s.નીચલું = n0 >> bm;
	  rr.s.ઉપલું = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  નહીંતર
    {
      જો (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  જો (rp != 0)
	    {
	      rr.s.નીચલું = n0;
	      rr.s.ઉપલું = n1;
	      *rp = rr.ll;
	    }
	}
      નહીંતર
	{
	  /* 0q = NN / dd */

	  ગણતરી_leading_zeros (bm, d1);
	  જો (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      જો (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      નહીંતર
		q0 = 0;

	      q1 = 0;

	      જો (rp != 0)
		{
		  rr.s.નીચલું = n0;
		  rr.s.ઉપલું = n1;
		  *rp = rr.ll;
		}
	    }
	  નહીંતર
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

	      જો (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      જો (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.નીચલું = (n1 << b) | (n0 >> bm);
		  rr.s.ઉપલું = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.નીચલું = q0;
  ww.s.ઉપલું = q1;
  પાછા ww.ll;
}

#define __negdi2(a) (-(a))

long long __divdi3(long long u, long long v)
{
    પૂર્ણાંક c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    જો (uu.s.ઉપલું < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    જો (vv.s.ઉપલું < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    જો (c)
        w = __negdi2 (w);
    પાછા w;
}

long long __moddi3(long long u, long long v)
{
    પૂર્ણાંક c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    જો (uu.s.ઉપલું < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    જો (vv.s.ઉપલું < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    જો (c)
        w = __negdi2 (w);
    પાછા w;
}

unsigned long long __udivdi3(unsigned long long u, unsigned long long v)
{
    પાછા __udivmoddi4 (u, v, (UDWtype *) 0);
}

unsigned long long __umoddi3(unsigned long long u, unsigned long long v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    પાછા w;
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashrdi3(long long a, પૂર્ણાંક b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    જો (b >= 32) {
        u.s.નીચલું = u.s.ઉપલું >> (b - 32);
        u.s.ઉપલું = u.s.ઉપલું >> 31;
    } નહીંતર જો (b != 0) {
        u.s.નીચલું = ((unsigned)u.s.નીચલું >> b) | (u.s.ઉપલું << (32 - b));
        u.s.ઉપલું = u.s.ઉપલું >> b;
    }
    પાછા u.ll;
#નહીંતર
    પાછા a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
unsigned long long __lshrdi3(unsigned long long a, પૂર્ણાંક b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    જો (b >= 32) {
        u.s.નીચલું = (unsigned)u.s.ઉપલું >> (b - 32);
        u.s.ઉપલું = 0;
    } નહીંતર જો (b != 0) {
        u.s.નીચલું = ((unsigned)u.s.નીચલું >> b) | (u.s.ઉપલું << (32 - b));
        u.s.ઉપલું = (unsigned)u.s.ઉપલું >> b;
    }
    પાછા u.ll;
#નહીંતર
    પાછા a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashldi3(long long a, પૂર્ણાંક b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    જો (b >= 32) {
        u.s.ઉપલું = (unsigned)u.s.નીચલું << (b - 32);
        u.s.નીચલું = 0;
    } નહીંતર જો (b != 0) {
        u.s.ઉપલું = ((unsigned)u.s.ઉપલું << b) | ((unsigned)u.s.નીચલું >> (32 - b));
        u.s.નીચલું = (unsigned)u.s.નીચલું << b;
    }
    પાછા u.ll;
#નહીંતર
    પાછા a << b;
#endif
}

#endif /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
દશાંશ __floatundisf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    જો (uu.s.ઉપલું >= 0) {
        પાછા (દશાંશ)uu.ll;
    } નહીંતર {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        પાછા (દશાંશ)r;
    }
}

દ્વિગુણ __floatundidf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    જો (uu.s.ઉપલું >= 0) {
        પાછા (દ્વિગુણ)uu.ll;
    } નહીંતર {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        પાછા (દ્વિગુણ)r;
    }
}

long દ્વિગુણ __floatundixf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    જો (uu.s.ઉપલું >= 0) {
        પાછા (long દ્વિગુણ)uu.ll;
    } નહીંતર {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        પાછા (long દ્વિગુણ)r;
    }
}

unsigned long long __fixunssfdi (દશાંશ a1)
{
    નોંધણી સંઘ float_long fl1;
    નોંધણી પૂર્ણાંક exp;
    નોંધણી unsigned long long l;

    fl1.f = a1;

    જો (fl1.l == 0)
	પાછા (0);

    exp = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    જો (exp >= 41)
        પાછા 1ULL << 63;
    નહીંતર જો (exp >= 0)
        l <<= exp;
    નહીંતર જો (exp >= -23)
        l >>= -exp;
    નહીંતર
	પાછા 0;
    જો (SIGN(fl1.l))
        l = (unsigned long long)-l;
    પાછા l;
}

long long __fixsfdi (દશાંશ a1)
{
    long long ret; પૂર્ણાંક s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    પાછા s ? ret : -ret;
}

unsigned long long __fixunsdfdi (દ્વિગુણ a1)
{
    નોંધણી સંઘ double_long dl1;
    નોંધણી પૂર્ણાંક exp;
    નોંધણી unsigned long long l;

    dl1.d = a1;

    જો (dl1.ll == 0)
	પાછા (0);

    exp = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    જો (exp >= 12)
        પાછા 1ULL << 63; /* overflow result (like gcc, somewhat) */
    નહીંતર જો (exp >= 0)
        l <<= exp;
    નહીંતર જો (exp >= -52)
        l >>= -exp;
    નહીંતર
        પાછા 0;
    જો (SIGND(dl1))
        l = (unsigned long long)-l;
    પાછા l;
}

long long __fixdfdi (દ્વિગુણ a1)
{
    long long ret; પૂર્ણાંક s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    પાછા s ? ret : -ret;
}

#ifndef __arm__
unsigned long long __fixunsxfdi (long દ્વિગુણ a1)
{
    નોંધણી સંઘ ldouble_long dl1;
    નોંધણી પૂર્ણાંક exp;
    નોંધણી unsigned long long l;

    dl1.ld = a1;

    જો (dl1.l.lower == 0 && dl1.l.upper == 0)
	પાછા (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.lower;
    જો (exp > 0)
	પાછા 1ULL << 63;
    જો (exp < -63)
        પાછા 0;
    l >>= -exp;
    જો (SIGNLD(dl1))
        l = (unsigned long long)-l;
    પાછા l;
}

long long __fixxfdi (long દ્વિગુણ a1)
{
    long long ret; પૂર્ણાંક s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    પાછા s ? ret : -ret;
}
#endif /* !ARM */
