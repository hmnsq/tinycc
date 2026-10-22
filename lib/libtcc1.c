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

#تعریف_کړه W_TYPE_اندازه   32
#تعریف_کړه بټونه_فی_UNIT 8

تعريفنوع صحيح Wtype;
تعريفنوع بینښه صحيح UWtype;
تعريفنوع بینښه صحيح USItype;
تعريفنوع اوږد اوږد DWtype;
تعريفنوع بینښه اوږد اوږد UDWtype;

بنية DWstruct {
    Wtype ټیټ, لوړ;
};

تعريفنوع اتحاد
{
  بنية DWstruct s;
  DWtype ll;
} DWunion;

تعريفنوع اوږد مزدوج XFtype;
#تعریف_کړه کلمه_اندازه (حجم (Wtype) * بټونه_فی_UNIT)
#تعریف_کړه لوړ_کلمه_COEFF (((UDWtype) 1) << کلمه_اندازه)

/* the following deal with IEEE single-precision numbers */
#تعریف_کړه EXCESS		126
#تعریف_کړه SIGNBIT		0x80000000
#تعریف_کړه HIDDEN		(1 << 23)
#تعریف_کړه SIGN(fp)	((fp) & SIGNBIT)
#تعریف_کړه EXP(fp)		(((fp) >> 23) & 0xFF)
#تعریف_کړه MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#تعریف_کړه PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE double-precision numbers */
#تعریف_کړه EXCESSD		1022
#تعریف_کړه HIDDEND		(1 << 20)
#تعریف_کړه EXPD(fp)	(((fp.l.پاسنی) >> 20) & 0x7FF)
#تعریف_کړه SIGND(fp)	((fp.l.پاسنی) & SIGNBIT)
#تعریف_کړه MANTD(fp)	(((((fp.l.پاسنی) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.ښکتنی >> 22))
#تعریف_کړه HIDDEND_LL	((اوږد اوږد)1 << 52)
#تعریف_کړه MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#تعریف_کړه PACKD_LL(s,e,m)	(((اوږد اوږد)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#تعریف_کړه EXCESSLD	16382
#تعریف_کړه EXPLD(fp)	(fp.l.پاسنی & 0x7fff)
#تعریف_کړه SIGNLD(fp)	((fp.l.پاسنی) & 0x8000)

/* only for x86 */
اتحاد ldouble_long {
    اوږد مزدوج ld;
    بنية {
        بینښه اوږد اوږد ښکتنی;
        بینښه لنډ پاسنی;
    } l;
};

اتحاد double_long {
    مزدوج d;
#إذا 1
    بنية {
        بینښه صحيح ښکتنی;
        صحيح پاسنی;
    } l;
#وإلا
    بنية {
        صحيح پاسنی;
        بینښه صحيح ښکتنی;
    } l;
#د_که_پای
    اوږد اوږد ll;
};

اتحاد float_long {
    عائم f;
    بینښه صحيح l;
};

/* XXX: we don't support several builtin supports for now */
#إذا defined __i386__

/* XXX: use gcc/tcc intrinsic ? */
#تعریف_کړه sub_ddmmss(sh, sl, ah, al, bh, bl) \
  __asm__ ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#تعریف_کړه umul_ppmm(w1, w0, u, v) \
  __asm__ ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#تعریف_کړه udiv_qrnnd(q, r, n1, n0, dv) \
  __asm__ ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#تعریف_کړه شمېر_leading_zeros(شمېر_2, x) \
  افعل {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (شمېر_2) = __cbtmp ^ 31;						\
  } طالما (0)

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

  d0 = dd.s.ټیټ;
  d1 = dd.s.لوړ;
  n0 = nn.s.ټیټ;
  n1 = nn.s.لوړ;

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
	  rr.s.ټیټ = n0;
	  rr.s.لوړ = 0;
	  *rp = rr.ll;
	}
    }

#وإلا /* UDIV_NEEDS_NORMALIZATION */

  إذا (d1 == 0)
    {
      إذا (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  شمېر_leading_zeros (bm, d0);

	  إذا (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_اندازه - bm));
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

	  شمېر_leading_zeros (bm, d0);

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

	      b = W_TYPE_اندازه - bm;

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
	  rr.s.ټیټ = n0 >> bm;
	  rr.s.لوړ = 0;
	  *rp = rr.ll;
	}
    }
#د_که_پای /* UDIV_NEEDS_NORMALIZATION */

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
	      rr.s.ټیټ = n0;
	      rr.s.لوړ = n1;
	      *rp = rr.ll;
	    }
	}
      وإلا
	{
	  /* 0q = NN / dd */

	  شمېر_leading_zeros (bm, d1);
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
		  rr.s.ټیټ = n0;
		  rr.s.لوړ = n1;
		  *rp = rr.ll;
		}
	    }
	  وإلا
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_اندازه - bm;

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
		  rr.s.ټیټ = (n1 << b) | (n0 >> bm);
		  rr.s.لوړ = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.ټیټ = q0;
  ww.s.لوړ = q1;
  أرجع ww.ll;
}

#تعریف_کړه __negdi2(a) (-(a))

اوږد اوږد __divdi3(اوږد اوږد u, اوږد اوږد v)
{
    صحيح c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    إذا (uu.s.لوړ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    إذا (vv.s.لوړ < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    إذا (c)
        w = __negdi2 (w);
    أرجع w;
}

اوږد اوږد __moddi3(اوږد اوږد u, اوږد اوږد v)
{
    صحيح c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    إذا (uu.s.لوړ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    إذا (vv.s.لوړ < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    إذا (c)
        w = __negdi2 (w);
    أرجع w;
}

بینښه اوږد اوږد __udivdi3(بینښه اوږد اوږد u, بینښه اوږد اوږد v)
{
    أرجع __udivmoddi4 (u, v, (UDWtype *) 0);
}

بینښه اوږد اوږد __umoddi3(بینښه اوږد اوږد u, بینښه اوږد اوږد v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    أرجع w;
}

/* XXX: fix tcc's code generator to do this instead */
اوږد اوږد __ashrdi3(اوږد اوږد a, صحيح b)
{
#که_تعریف_شوی __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.ټیټ = u.s.لوړ >> (b - 32);
        u.s.لوړ = u.s.لوړ >> 31;
    } وإلا إذا (b != 0) {
        u.s.ټیټ = ((بینښه)u.s.ټیټ >> b) | (u.s.لوړ << (32 - b));
        u.s.لوړ = u.s.لوړ >> b;
    }
    أرجع u.ll;
#وإلا
    أرجع a >> b;
#د_که_پای
}

/* XXX: fix tcc's code generator to do this instead */
بینښه اوږد اوږد __lshrdi3(بینښه اوږد اوږد a, صحيح b)
{
#که_تعریف_شوی __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.ټیټ = (بینښه)u.s.لوړ >> (b - 32);
        u.s.لوړ = 0;
    } وإلا إذا (b != 0) {
        u.s.ټیټ = ((بینښه)u.s.ټیټ >> b) | (u.s.لوړ << (32 - b));
        u.s.لوړ = (بینښه)u.s.لوړ >> b;
    }
    أرجع u.ll;
#وإلا
    أرجع a >> b;
#د_که_پای
}

/* XXX: fix tcc's code generator to do this instead */
اوږد اوږد __ashldi3(اوږد اوږد a, صحيح b)
{
#که_تعریف_شوی __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.لوړ = (بینښه)u.s.ټیټ << (b - 32);
        u.s.ټیټ = 0;
    } وإلا إذا (b != 0) {
        u.s.لوړ = ((بینښه)u.s.لوړ << b) | ((بینښه)u.s.ټیټ >> (32 - b));
        u.s.ټیټ = (بینښه)u.s.ټیټ << b;
    }
    أرجع u.ll;
#وإلا
    أرجع a << b;
#د_که_پای
}

#د_که_پای /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
عائم __floatundisf(بینښه اوږد اوږد a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.لوړ >= 0) {
        أرجع (عائم)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        أرجع (عائم)r;
    }
}

مزدوج __floatundidf(بینښه اوږد اوږد a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.لوړ >= 0) {
        أرجع (مزدوج)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        أرجع (مزدوج)r;
    }
}

اوږد مزدوج __floatundixf(بینښه اوږد اوږد a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.لوړ >= 0) {
        أرجع (اوږد مزدوج)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        أرجع (اوږد مزدوج)r;
    }
}

بینښه اوږد اوږد __fixunssfdi (عائم a1)
{
    سجل اتحاد float_long fl1;
    سجل صحيح توانیز_تابع;
    سجل بینښه اوږد اوږد l;

    fl1.f = a1;

    إذا (fl1.l == 0)
	أرجع (0);

    توانیز_تابع = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    إذا (توانیز_تابع >= 41)
        أرجع 1ULL << 63;
    وإلا إذا (توانیز_تابع >= 0)
        l <<= توانیز_تابع;
    وإلا إذا (توانیز_تابع >= -23)
        l >>= -توانیز_تابع;
    وإلا
	أرجع 0;
    إذا (SIGN(fl1.l))
        l = (بینښه اوږد اوږد)-l;
    أرجع l;
}

اوږد اوږد __fixsfdi (عائم a1)
{
    اوږد اوږد ret; صحيح s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    أرجع s ? ret : -ret;
}

بینښه اوږد اوږد __fixunsdfdi (مزدوج a1)
{
    سجل اتحاد double_long dl1;
    سجل صحيح توانیز_تابع;
    سجل بینښه اوږد اوږد l;

    dl1.d = a1;

    إذا (dl1.ll == 0)
	أرجع (0);

    توانیز_تابع = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    إذا (توانیز_تابع >= 12)
        أرجع 1ULL << 63; /* overflow result (like gcc, somewhat) */
    وإلا إذا (توانیز_تابع >= 0)
        l <<= توانیز_تابع;
    وإلا إذا (توانیز_تابع >= -52)
        l >>= -توانیز_تابع;
    وإلا
        أرجع 0;
    إذا (SIGND(dl1))
        l = (بینښه اوږد اوږد)-l;
    أرجع l;
}

اوږد اوږد __fixdfdi (مزدوج a1)
{
    اوږد اوږد ret; صحيح s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    أرجع s ? ret : -ret;
}

#که_نه_تعریف_شوی __arm__
بینښه اوږد اوږد __fixunsxfdi (اوږد مزدوج a1)
{
    سجل اتحاد ldouble_long dl1;
    سجل صحيح توانیز_تابع;
    سجل بینښه اوږد اوږد l;

    dl1.ld = a1;

    إذا (dl1.l.ښکتنی == 0 && dl1.l.پاسنی == 0)
	أرجع (0);

    توانیز_تابع = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.ښکتنی;
    إذا (توانیز_تابع > 0)
	أرجع 1ULL << 63;
    إذا (توانیز_تابع < -63)
        أرجع 0;
    l >>= -توانیز_تابع;
    إذا (SIGNLD(dl1))
        l = (بینښه اوږد اوږد)-l;
    أرجع l;
}

اوږد اوږد __fixxfdi (اوږد مزدوج a1)
{
    اوږد اوږد ret; صحيح s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    أرجع s ? ret : -ret;
}
#د_که_پای /* !ARM */
