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

प्रकारव्याख्या पूर्णांक Wtype;
प्रकारव्याख्या अचिन्हित पूर्णांक UWtype;
प्रकारव्याख्या अचिन्हित पूर्णांक USItype;
प्रकारव्याख्या दीर्घ दीर्घ DWtype;
प्रकारव्याख्या अचिन्हित दीर्घ दीर्घ UDWtype;

संरचना DWstruct {
    Wtype खालचा, वरचा;
};

प्रकारव्याख्या संघ
{
  संरचना DWstruct s;
  DWtype ll;
} DWunion;

प्रकारव्याख्या दीर्घ द्विगुण XFtype;
#define WORD_SIZE (आकार (Wtype) * BITS_PER_UNIT)
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
#define HIDDEND_LL	((दीर्घ दीर्घ)1 << 52)
#define MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#define PACKD_LL(s,e,m)	(((दीर्घ दीर्घ)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#define EXCESSLD	16382
#define EXPLD(fp)	(fp.l.upper & 0x7fff)
#define SIGNLD(fp)	((fp.l.upper) & 0x8000)

/* only for x86 */
संघ ldouble_long {
    दीर्घ द्विगुण ld;
    संरचना {
        अचिन्हित दीर्घ दीर्घ lower;
        अचिन्हित लघु upper;
    } l;
};

संघ double_long {
    द्विगुण d;
#जर 1
    संरचना {
        अचिन्हित पूर्णांक lower;
        पूर्णांक upper;
    } l;
#अन्यथा
    संरचना {
        पूर्णांक upper;
        अचिन्हित पूर्णांक lower;
    } l;
#endif
    दीर्घ दीर्घ ll;
};

संघ float_long {
    दशांश f;
    अचिन्हित पूर्णांक l;
};

/* XXX: we don't support several builtin supports for now */
#जर defined __i386__

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
  करा {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (मोजणी_2) = __cbtmp ^ 31;						\
  } पर्यंत (0)

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

#जर !defined(UDIV_NEEDS_NORMALIZATION)
  जर (d1 == 0)
    {
      जर (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      अन्यथा
	{
	  /* qq = NN / 0d */

	  जर (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      जर (rp != 0)
	{
	  rr.s.खालचा = n0;
	  rr.s.वरचा = 0;
	  *rp = rr.ll;
	}
    }

#अन्यथा /* UDIV_NEEDS_NORMALIZATION */

  जर (d1 == 0)
    {
      जर (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  मोजणी_leading_zeros (bm, d0);

	  जर (bm != 0)
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

	  जर (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  मोजणी_leading_zeros (bm, d0);

	  जर (bm == 0)
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

      जर (rp != 0)
	{
	  rr.s.खालचा = n0 >> bm;
	  rr.s.वरचा = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  अन्यथा
    {
      जर (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  जर (rp != 0)
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
	  जर (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      जर (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      अन्यथा
		q0 = 0;

	      q1 = 0;

	      जर (rp != 0)
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

	      जर (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      जर (rp != 0)
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
  परत ww.ll;
}

#define __negdi2(a) (-(a))

दीर्घ दीर्घ __divdi3(दीर्घ दीर्घ u, दीर्घ दीर्घ v)
{
    पूर्णांक c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    जर (uu.s.वरचा < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    जर (vv.s.वरचा < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    जर (c)
        w = __negdi2 (w);
    परत w;
}

दीर्घ दीर्घ __moddi3(दीर्घ दीर्घ u, दीर्घ दीर्घ v)
{
    पूर्णांक c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    जर (uu.s.वरचा < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    जर (vv.s.वरचा < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    जर (c)
        w = __negdi2 (w);
    परत w;
}

अचिन्हित दीर्घ दीर्घ __udivdi3(अचिन्हित दीर्घ दीर्घ u, अचिन्हित दीर्घ दीर्घ v)
{
    परत __udivmoddi4 (u, v, (UDWtype *) 0);
}

अचिन्हित दीर्घ दीर्घ __umoddi3(अचिन्हित दीर्घ दीर्घ u, अचिन्हित दीर्घ दीर्घ v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    परत w;
}

/* XXX: fix tcc's code generator to do this instead */
दीर्घ दीर्घ __ashrdi3(दीर्घ दीर्घ a, पूर्णांक b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    जर (b >= 32) {
        u.s.खालचा = u.s.वरचा >> (b - 32);
        u.s.वरचा = u.s.वरचा >> 31;
    } अन्यथा जर (b != 0) {
        u.s.खालचा = ((अचिन्हित)u.s.खालचा >> b) | (u.s.वरचा << (32 - b));
        u.s.वरचा = u.s.वरचा >> b;
    }
    परत u.ll;
#अन्यथा
    परत a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
अचिन्हित दीर्घ दीर्घ __lshrdi3(अचिन्हित दीर्घ दीर्घ a, पूर्णांक b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    जर (b >= 32) {
        u.s.खालचा = (अचिन्हित)u.s.वरचा >> (b - 32);
        u.s.वरचा = 0;
    } अन्यथा जर (b != 0) {
        u.s.खालचा = ((अचिन्हित)u.s.खालचा >> b) | (u.s.वरचा << (32 - b));
        u.s.वरचा = (अचिन्हित)u.s.वरचा >> b;
    }
    परत u.ll;
#अन्यथा
    परत a >> b;
#endif
}

/* XXX: fix tcc's code generator to do this instead */
दीर्घ दीर्घ __ashldi3(दीर्घ दीर्घ a, पूर्णांक b)
{
#ifdef __TINYC__
    DWunion u;
    u.ll = a;
    जर (b >= 32) {
        u.s.वरचा = (अचिन्हित)u.s.खालचा << (b - 32);
        u.s.खालचा = 0;
    } अन्यथा जर (b != 0) {
        u.s.वरचा = ((अचिन्हित)u.s.वरचा << b) | ((अचिन्हित)u.s.खालचा >> (32 - b));
        u.s.खालचा = (अचिन्हित)u.s.खालचा << b;
    }
    परत u.ll;
#अन्यथा
    परत a << b;
#endif
}

#endif /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
दशांश __floatundisf(अचिन्हित दीर्घ दीर्घ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    जर (uu.s.वरचा >= 0) {
        परत (दशांश)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        परत (दशांश)r;
    }
}

द्विगुण __floatundidf(अचिन्हित दीर्घ दीर्घ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    जर (uu.s.वरचा >= 0) {
        परत (द्विगुण)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        परत (द्विगुण)r;
    }
}

दीर्घ द्विगुण __floatundixf(अचिन्हित दीर्घ दीर्घ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    जर (uu.s.वरचा >= 0) {
        परत (दीर्घ द्विगुण)uu.ll;
    } अन्यथा {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        परत (दीर्घ द्विगुण)r;
    }
}

अचिन्हित दीर्घ दीर्घ __fixunssfdi (दशांश a1)
{
    नोंदणी संघ float_long fl1;
    नोंदणी पूर्णांक exp;
    नोंदणी अचिन्हित दीर्घ दीर्घ l;

    fl1.f = a1;

    जर (fl1.l == 0)
	परत (0);

    exp = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    जर (exp >= 41)
        परत 1ULL << 63;
    अन्यथा जर (exp >= 0)
        l <<= exp;
    अन्यथा जर (exp >= -23)
        l >>= -exp;
    अन्यथा
	परत 0;
    जर (SIGN(fl1.l))
        l = (अचिन्हित दीर्घ दीर्घ)-l;
    परत l;
}

दीर्घ दीर्घ __fixsfdi (दशांश a1)
{
    दीर्घ दीर्घ ret; पूर्णांक s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    परत s ? ret : -ret;
}

अचिन्हित दीर्घ दीर्घ __fixunsdfdi (द्विगुण a1)
{
    नोंदणी संघ double_long dl1;
    नोंदणी पूर्णांक exp;
    नोंदणी अचिन्हित दीर्घ दीर्घ l;

    dl1.d = a1;

    जर (dl1.ll == 0)
	परत (0);

    exp = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    जर (exp >= 12)
        परत 1ULL << 63; /* overflow result (like gcc, somewhat) */
    अन्यथा जर (exp >= 0)
        l <<= exp;
    अन्यथा जर (exp >= -52)
        l >>= -exp;
    अन्यथा
        परत 0;
    जर (SIGND(dl1))
        l = (अचिन्हित दीर्घ दीर्घ)-l;
    परत l;
}

दीर्घ दीर्घ __fixdfdi (द्विगुण a1)
{
    दीर्घ दीर्घ ret; पूर्णांक s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    परत s ? ret : -ret;
}

#ifndef __arm__
अचिन्हित दीर्घ दीर्घ __fixunsxfdi (दीर्घ द्विगुण a1)
{
    नोंदणी संघ ldouble_long dl1;
    नोंदणी पूर्णांक exp;
    नोंदणी अचिन्हित दीर्घ दीर्घ l;

    dl1.ld = a1;

    जर (dl1.l.lower == 0 && dl1.l.upper == 0)
	परत (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.lower;
    जर (exp > 0)
	परत 1ULL << 63;
    जर (exp < -63)
        परत 0;
    l >>= -exp;
    जर (SIGNLD(dl1))
        l = (अचिन्हित दीर्घ दीर्घ)-l;
    परत l;
}

दीर्घ दीर्घ __fixxfdi (दीर्घ द्विगुण a1)
{
    दीर्घ दीर्घ ret; पूर्णांक s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    परत s ? ret : -ret;
}
#endif /* !ARM */
