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

प्रकारनिर्देश पूर्णाङ्क Wtype;
प्रकारनिर्देश unsigned पूर्णाङ्क UWtype;
प्रकारनिर्देश unsigned पूर्णाङ्क USItype;
प्रकारनिर्देश long long DWtype;
प्रकारनिर्देश unsigned long long UDWtype;

संरचना DWstruct {
    Wtype खालचा, वरचा;
};

प्रकारनिर्देश सङ्घ
{
  संरचना DWstruct s;
  DWtype ll;
} DWunion;

प्रकारनिर्देश long द्विगुण XFtype;
#define WORD_SIZE (परिमाण (Wtype) * BITS_PER_UNIT)
#define वरचा_WORD_COEFF (((UDWtype) 1) << WORD_SIZE)

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
सङ्घ ldouble_long {
    long द्विगुण ld;
    संरचना {
        unsigned long long lower;
        unsigned short upper;
    } l;
};

सङ्घ double_long {
    द्विगुण d;
#यदि 1
    संरचना {
        unsigned पूर्णाङ्क lower;
        पूर्णाङ्क upper;
    } l;
#अन्यथा
    संरचना {
        पूर्णाङ्क upper;
        unsigned पूर्णाङ्क lower;
    } l;
#endif
    long long ll;
};

सङ्घ float_long {
    भिन्न f;
    unsigned पूर्णाङ्क l;
};

/* XXX: we don't support several builtin supports for now */
#यदि defined __i386__

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
#define मोजणी_leading_zeros(मोजणी_2, x) \
  कुरु {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (मोजणी_2) = __cbtmp ^ 31;						\
  } यावत् (0)

/* most of this code is taken from libgcc2.c from gcc */

स्थिर UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.खालचा;
  d1 = dd.s.वरचा;
  n0 = nn.s.खालचा;
  n1 = nn.s.वरचा;

#यदि !defined(UDIV_NEEDS_NORMALIZATION)
  यदि (d1 == 0)
    {
      यदि (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      अन्यथा
	{
	  /* qq = NN / 0d */

	  यदि (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      यदि (rp != 0)
	{
	  rr.s.खालचा = n0;
	  rr.s.वरचा = 0;
	  *rp = rr.ll;
	}
    }

#अन्यथा /* UDIV_NEEDS_NORMALIZATION */

  यदि (d1 == 0)
    {
      यदि (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  मोजणी_leading_zeros (bm, d0);

	  यदि (bm != 0)
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
      अन्यथा
	{
	  /* qq = NN / 0d */

	  यदि (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  मोजणी_leading_zeros (bm, d0);

	  यदि (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  अन्यथा
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

      यदि (rp != 0)
	{
	  rr.s.खालचा = n0 >> bm;
	  rr.s.वरचा = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  अन्यथा
    {
      यदि (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  यदि (rp != 0)
	    {
	      rr.s.खालचा = n0;
	      rr.s.वरचा = n1;
	      *rp = rr.ll;
	    }
	}
      अन्यथा
	{
	  /* 0q = NN / dd */

	  मोजणी_leading_zeros (bm, d1);
	  यदि (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      यदि (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      अन्यथा
		q0 = 0;

	      q1 = 0;

	      यदि (rp != 0)
		{
		  rr.s.खालचा = n0;
		  rr.s.वरचा = n1;
		  *rp = rr.ll;
		}
	    }
	  अन्यथा
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

	      यदि (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      यदि (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.खालचा = (n1 << b) | (n0 >> bm);
		  rr.s.वरचा = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.खालचा = q0;
  ww.s.वरचा = q1;
  प्रत्यागम ww.ll;
}

#define __negdi2(a) (-(a))

long long __divdi3(long long u, long long v)
{
    पूर्णाङ्क c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    यदि (uu.s.वरचा < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    यदि (vv.s.वरचा < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    यदि (c)
        w = __negdi2 (w);
    प्रत्यागम w;
}

long long __moddi3(long long u, long long v)
{
    पूर्णाङ्क c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    यदि (uu.s.वरचा < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    यदि (vv.s.वरचा < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    यदि (c)
        w = __negdi2 (w);
    प्रत्यागम w;
}

unsigned long long __udivdi3(unsigned long long u, unsigned long long v)
{
    प्रत्यागम __udivmoddi4 (u, v, (UDWtype *) 0);
}

unsigned long long __umoddi3(unsigned long long u, unsigned long long v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    प्रत्यागम w;
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashrdi3(long long a, पूर्णाङ्क b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    यदि (b >= 32) {
        u.s.खालचा = u.s.वरचा >> (b - 32);
        u.s.वरचा = u.s.वरचा >> 31;
    } अन्यथा यदि (b != 0) {
        u.s.खालचा = ((unsigned)u.s.खालचा >> b) | (u.s.वरचा << (32 - b));
        u.s.वरचा = u.s.वरचा >> b;
    }
    प्रत्यागम u.ll;
#अन्यथा
    प्रत्यागम a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
unsigned long long __lshrdi3(unsigned long long a, पूर्णाङ्क b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    यदि (b >= 32) {
        u.s.खालचा = (unsigned)u.s.वरचा >> (b - 32);
        u.s.वरचा = 0;
    } अन्यथा यदि (b != 0) {
        u.s.खालचा = ((unsigned)u.s.खालचा >> b) | (u.s.वरचा << (32 - b));
        u.s.वरचा = (unsigned)u.s.वरचा >> b;
    }
    प्रत्यागम u.ll;
#अन्यथा
    प्रत्यागम a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
long long __ashldi3(long long a, पूर्णाङ्क b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    यदि (b >= 32) {
        u.s.वरचा = (unsigned)u.s.खालचा << (b - 32);
        u.s.खालचा = 0;
    } अन्यथा यदि (b != 0) {
        u.s.वरचा = ((unsigned)u.s.वरचा << b) | ((unsigned)u.s.खालचा >> (32 - b));
        u.s.खालचा = (unsigned)u.s.खालचा << b;
    }
    प्रत्यागम u.ll;
#अन्यथा
    प्रत्यागम a << b;
#endif
}

#endif /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
भिन्न __floatundisf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    यदि (uu.s.वरचा >= 0) {
        प्रत्यागम (भिन्न)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        प्रत्यागम (भिन्न)r;
    }
}

द्विगुण __floatundidf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    यदि (uu.s.वरचा >= 0) {
        प्रत्यागम (द्विगुण)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        प्रत्यागम (द्विगुण)r;
    }
}

long द्विगुण __floatundixf(unsigned long long a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    यदि (uu.s.वरचा >= 0) {
        प्रत्यागम (long द्विगुण)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        प्रत्यागम (long द्विगुण)r;
    }
}

unsigned long long __fixunssfdi (भिन्न a1)
{
    पञ्जिका सङ्घ float_long fl1;
    पञ्जिका पूर्णाङ्क exp;
    पञ्जिका unsigned long long l;

    fl1.f = a1;

    यदि (fl1.l == 0)
	प्रत्यागम (0);

    exp = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    यदि (exp >= 41)
        प्रत्यागम 1ULL << 63;
    अन्यथा यदि (exp >= 0)
        l <<= exp;
    अन्यथा यदि (exp >= -23)
        l >>= -exp;
    अन्यथा
	प्रत्यागम 0;
    यदि (SIGN(fl1.l))
        l = (unsigned long long)-l;
    प्रत्यागम l;
}

long long __fixsfdi (भिन्न a1)
{
    long long ret; पूर्णाङ्क s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    प्रत्यागम s ? ret : -ret;
}

unsigned long long __fixunsdfdi (द्विगुण a1)
{
    पञ्जिका सङ्घ double_long dl1;
    पञ्जिका पूर्णाङ्क exp;
    पञ्जिका unsigned long long l;

    dl1.d = a1;

    यदि (dl1.ll == 0)
	प्रत्यागम (0);

    exp = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    यदि (exp >= 12)
        प्रत्यागम 1ULL << 63; /* overflow result (like gcc, somewhat) */
    अन्यथा यदि (exp >= 0)
        l <<= exp;
    अन्यथा यदि (exp >= -52)
        l >>= -exp;
    अन्यथा
        प्रत्यागम 0;
    यदि (SIGND(dl1))
        l = (unsigned long long)-l;
    प्रत्यागम l;
}

long long __fixdfdi (द्विगुण a1)
{
    long long ret; पूर्णाङ्क s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    प्रत्यागम s ? ret : -ret;
}

#ifndef __arm__
unsigned long long __fixunsxfdi (long द्विगुण a1)
{
    पञ्जिका सङ्घ ldouble_long dl1;
    पञ्जिका पूर्णाङ्क exp;
    पञ्जिका unsigned long long l;

    dl1.ld = a1;

    यदि (dl1.l.lower == 0 && dl1.l.upper == 0)
	प्रत्यागम (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.lower;
    यदि (exp > 0)
	प्रत्यागम 1ULL << 63;
    यदि (exp < -63)
        प्रत्यागम 0;
    l >>= -exp;
    यदि (SIGNLD(dl1))
        l = (unsigned long long)-l;
    प्रत्यागम l;
}

long long __fixxfdi (long द्विगुण a1)
{
    long long ret; पूर्णाङ्क s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    प्रत्यागम s ? ret : -ret;
}
#endif /* !ARM */
