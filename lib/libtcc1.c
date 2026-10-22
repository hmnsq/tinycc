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

#تعریف_کن W_TYPE_اندازه   32
#تعریف_کن بیتها_در_هر_UNIT 8

تعريفنوع صحيح Wtype;
تعريفنوع بیعلامت صحيح UWtype;
تعريفنوع بیعلامت صحيح USItype;
تعريفنوع دراز دراز DWtype;
تعريفنوع بیعلامت دراز دراز UDWtype;

بنية DWstruct {
    Wtype کم, بالا;
};

تعريفنوع اتحاد
{
  بنية DWstruct s;
  DWtype ll;
} DWunion;

تعريفنوع دراز مزدوج XFtype;
#تعریف_کن کلمه_اندازه (حجم (Wtype) * بیتها_در_هر_UNIT)
#تعریف_کن بالا_کلمه_COEFF (((UDWtype) 1) << کلمه_اندازه)

/* the following deal with IEEE single-precision numbers */
#تعریف_کن EXCESS		126
#تعریف_کن SIGNBIT		0x80000000
#تعریف_کن HIDDEN		(1 << 23)
#تعریف_کن SIGN(fp)	((fp) & SIGNBIT)
#تعریف_کن EXP(fp)		(((fp) >> 23) & 0xFF)
#تعریف_کن MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#تعریف_کن PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE double-precision numbers */
#تعریف_کن EXCESSD		1022
#تعریف_کن HIDDEND		(1 << 20)
#تعریف_کن EXPD(fp)	(((fp.l.فوقانی) >> 20) & 0x7FF)
#تعریف_کن SIGND(fp)	((fp.l.فوقانی) & SIGNBIT)
#تعریف_کن MANTD(fp)	(((((fp.l.فوقانی) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.پایینی >> 22))
#تعریف_کن HIDDEND_LL	((دراز دراز)1 << 52)
#تعریف_کن MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#تعریف_کن PACKD_LL(s,e,m)	(((دراز دراز)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#تعریف_کن EXCESSLD	16382
#تعریف_کن EXPLD(fp)	(fp.l.فوقانی & 0x7fff)
#تعریف_کن SIGNLD(fp)	((fp.l.فوقانی) & 0x8000)

/* only for x86 */
اتحاد ldouble_long {
    دراز مزدوج ld;
    بنية {
        بیعلامت دراز دراز پایینی;
        بیعلامت کوتاه فوقانی;
    } l;
};

اتحاد double_long {
    مزدوج d;
#إذا 1
    بنية {
        بیعلامت صحيح پایینی;
        صحيح فوقانی;
    } l;
#وإلا
    بنية {
        صحيح فوقانی;
        بیعلامت صحيح پایینی;
    } l;
#پایان_اگر
    دراز دراز ll;
};

اتحاد float_long {
    عائم f;
    بیعلامت صحيح l;
};

/* XXX: we don't support several builtin supports for now */
#إذا defined __i386__

/* XXX: use gcc/tcc intrinsic ? */
#تعریف_کن sub_ddmmss(sh, sl, ah, al, bh, bl) \
  __asm__ ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#تعریف_کن umul_ppmm(w1, w0, u, v) \
  __asm__ ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#تعریف_کن udiv_qrnnd(q, r, n1, n0, dv) \
  __asm__ ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#تعریف_کن شمار_leading_zeros(شمار_2, x) \
  افعل {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (شمار_2) = __cbtmp ^ 31;						\
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

  d0 = dd.s.کم;
  d1 = dd.s.بالا;
  n0 = nn.s.کم;
  n1 = nn.s.بالا;

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
	  rr.s.کم = n0;
	  rr.s.بالا = 0;
	  *rp = rr.ll;
	}
    }

#وإلا /* UDIV_NEEDS_NORMALIZATION */

  إذا (d1 == 0)
    {
      إذا (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  شمار_leading_zeros (bm, d0);

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

	  شمار_leading_zeros (bm, d0);

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
	  rr.s.کم = n0 >> bm;
	  rr.s.بالا = 0;
	  *rp = rr.ll;
	}
    }
#پایان_اگر /* UDIV_NEEDS_NORMALIZATION */

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
	      rr.s.کم = n0;
	      rr.s.بالا = n1;
	      *rp = rr.ll;
	    }
	}
      وإلا
	{
	  /* 0q = NN / dd */

	  شمار_leading_zeros (bm, d1);
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
		  rr.s.کم = n0;
		  rr.s.بالا = n1;
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
		  rr.s.کم = (n1 << b) | (n0 >> bm);
		  rr.s.بالا = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.کم = q0;
  ww.s.بالا = q1;
  أرجع ww.ll;
}

#تعریف_کن __negdi2(a) (-(a))

دراز دراز __divdi3(دراز دراز u, دراز دراز v)
{
    صحيح c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    إذا (uu.s.بالا < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    إذا (vv.s.بالا < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    إذا (c)
        w = __negdi2 (w);
    أرجع w;
}

دراز دراز __moddi3(دراز دراز u, دراز دراز v)
{
    صحيح c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    إذا (uu.s.بالا < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    إذا (vv.s.بالا < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    إذا (c)
        w = __negdi2 (w);
    أرجع w;
}

بیعلامت دراز دراز __udivdi3(بیعلامت دراز دراز u, بیعلامت دراز دراز v)
{
    أرجع __udivmoddi4 (u, v, (UDWtype *) 0);
}

بیعلامت دراز دراز __umoddi3(بیعلامت دراز دراز u, بیعلامت دراز دراز v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    أرجع w;
}

/* XXX: fix tcc's code generator to do this instead */
دراز دراز __ashrdi3(دراز دراز a, صحيح b)
{
#اگر_تعریف_شده __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.کم = u.s.بالا >> (b - 32);
        u.s.بالا = u.s.بالا >> 31;
    } وإلا إذا (b != 0) {
        u.s.کم = ((بیعلامت)u.s.کم >> b) | (u.s.بالا << (32 - b));
        u.s.بالا = u.s.بالا >> b;
    }
    أرجع u.ll;
#وإلا
    أرجع a >> b;
#پایان_اگر
}

/* XXX: fix tcc's code generator to do this instead */
بیعلامت دراز دراز __lshrdi3(بیعلامت دراز دراز a, صحيح b)
{
#اگر_تعریف_شده __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.کم = (بیعلامت)u.s.بالا >> (b - 32);
        u.s.بالا = 0;
    } وإلا إذا (b != 0) {
        u.s.کم = ((بیعلامت)u.s.کم >> b) | (u.s.بالا << (32 - b));
        u.s.بالا = (بیعلامت)u.s.بالا >> b;
    }
    أرجع u.ll;
#وإلا
    أرجع a >> b;
#پایان_اگر
}

/* XXX: fix tcc's code generator to do this instead */
دراز دراز __ashldi3(دراز دراز a, صحيح b)
{
#اگر_تعریف_شده __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.بالا = (بیعلامت)u.s.کم << (b - 32);
        u.s.کم = 0;
    } وإلا إذا (b != 0) {
        u.s.بالا = ((بیعلامت)u.s.بالا << b) | ((بیعلامت)u.s.کم >> (32 - b));
        u.s.کم = (بیعلامت)u.s.کم << b;
    }
    أرجع u.ll;
#وإلا
    أرجع a << b;
#پایان_اگر
}

#پایان_اگر /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
عائم __floatundisf(بیعلامت دراز دراز a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.بالا >= 0) {
        أرجع (عائم)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        أرجع (عائم)r;
    }
}

مزدوج __floatundidf(بیعلامت دراز دراز a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.بالا >= 0) {
        أرجع (مزدوج)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        أرجع (مزدوج)r;
    }
}

دراز مزدوج __floatundixf(بیعلامت دراز دراز a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.بالا >= 0) {
        أرجع (دراز مزدوج)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        أرجع (دراز مزدوج)r;
    }
}

بیعلامت دراز دراز __fixunssfdi (عائم a1)
{
    سجل اتحاد float_long fl1;
    سجل صحيح نمایی_تابع;
    سجل بیعلامت دراز دراز l;

    fl1.f = a1;

    إذا (fl1.l == 0)
	أرجع (0);

    نمایی_تابع = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    إذا (نمایی_تابع >= 41)
        أرجع 1ULL << 63;
    وإلا إذا (نمایی_تابع >= 0)
        l <<= نمایی_تابع;
    وإلا إذا (نمایی_تابع >= -23)
        l >>= -نمایی_تابع;
    وإلا
	أرجع 0;
    إذا (SIGN(fl1.l))
        l = (بیعلامت دراز دراز)-l;
    أرجع l;
}

دراز دراز __fixsfdi (عائم a1)
{
    دراز دراز ret; صحيح s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    أرجع s ? ret : -ret;
}

بیعلامت دراز دراز __fixunsdfdi (مزدوج a1)
{
    سجل اتحاد double_long dl1;
    سجل صحيح نمایی_تابع;
    سجل بیعلامت دراز دراز l;

    dl1.d = a1;

    إذا (dl1.ll == 0)
	أرجع (0);

    نمایی_تابع = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    إذا (نمایی_تابع >= 12)
        أرجع 1ULL << 63; /* overflow result (like gcc, somewhat) */
    وإلا إذا (نمایی_تابع >= 0)
        l <<= نمایی_تابع;
    وإلا إذا (نمایی_تابع >= -52)
        l >>= -نمایی_تابع;
    وإلا
        أرجع 0;
    إذا (SIGND(dl1))
        l = (بیعلامت دراز دراز)-l;
    أرجع l;
}

دراز دراز __fixdfdi (مزدوج a1)
{
    دراز دراز ret; صحيح s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    أرجع s ? ret : -ret;
}

#اگر_تعریف_نشده __arm__
بیعلامت دراز دراز __fixunsxfdi (دراز مزدوج a1)
{
    سجل اتحاد ldouble_long dl1;
    سجل صحيح نمایی_تابع;
    سجل بیعلامت دراز دراز l;

    dl1.ld = a1;

    إذا (dl1.l.پایینی == 0 && dl1.l.فوقانی == 0)
	أرجع (0);

    نمایی_تابع = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.پایینی;
    إذا (نمایی_تابع > 0)
	أرجع 1ULL << 63;
    إذا (نمایی_تابع < -63)
        أرجع 0;
    l >>= -نمایی_تابع;
    إذا (SIGNLD(dl1))
        l = (بیعلامت دراز دراز)-l;
    أرجع l;
}

دراز دراز __fixxfdi (دراز مزدوج a1)
{
    دراز دراز ret; صحيح s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    أرجع s ? ret : -ret;
}
#پایان_اگر /* !ARM */
