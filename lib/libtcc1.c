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

#تعریف_کرو W_TYPE_ناپ   32
#تعریف_کرو بٹ_فی_UNIT 8

تعريفنوع صحيح Wtype;
تعريفنوع بنانشانی صحيح UWtype;
تعريفنوع بنانشانی صحيح USItype;
تعريفنوع لما لما DWtype;
تعريفنوع بنانشانی لما لما UDWtype;

بنية DWstruct {
    Wtype کم, بلند;
};

تعريفنوع اتحاد
{
  بنية DWstruct s;
  DWtype ll;
} DWunion;

تعريفنوع لما مزدوج XFtype;
#تعریف_کرو لفظ_ناپ (حجم (Wtype) * بٹ_فی_UNIT)
#تعریف_کرو بلند_لفظ_COEFF (((UDWtype) 1) << لفظ_ناپ)

/* the following deal with IEEE single-precision numbers */
#تعریف_کرو EXCESS		126
#تعریف_کرو SIGNBIT		0x80000000
#تعریف_کرو HIDDEN		(1 << 23)
#تعریف_کرو SIGN(fp)	((fp) & SIGNBIT)
#تعریف_کرو EXP(fp)		(((fp) >> 23) & 0xFF)
#تعریف_کرو MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#تعریف_کرو PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE double-precision numbers */
#تعریف_کرو EXCESSD		1022
#تعریف_کرو HIDDEND		(1 << 20)
#تعریف_کرو EXPD(fp)	(((fp.l.اتلا) >> 20) & 0x7FF)
#تعریف_کرو SIGND(fp)	((fp.l.اتلا) & SIGNBIT)
#تعریف_کرو MANTD(fp)	(((((fp.l.اتلا) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.ہیٹھلا >> 22))
#تعریف_کرو HIDDEND_LL	((لما لما)1 << 52)
#تعریف_کرو MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#تعریف_کرو PACKD_LL(s,e,m)	(((لما لما)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#تعریف_کرو EXCESSLD	16382
#تعریف_کرو EXPLD(fp)	(fp.l.اتلا & 0x7fff)
#تعریف_کرو SIGNLD(fp)	((fp.l.اتلا) & 0x8000)

/* only for x86 */
اتحاد ldouble_long {
    لما مزدوج ld;
    بنية {
        بنانشانی لما لما ہیٹھلا;
        بنانشانی چھوٹا اتلا;
    } l;
};

اتحاد double_long {
    مزدوج d;
#إذا 1
    بنية {
        بنانشانی صحيح ہیٹھلا;
        صحيح اتلا;
    } l;
#وإلا
    بنية {
        صحيح اتلا;
        بنانشانی صحيح ہیٹھلا;
    } l;
#جے_انت
    لما لما ll;
};

اتحاد float_long {
    عائم f;
    بنانشانی صحيح l;
};

/* XXX: we don't support several builtin supports for now */
#إذا defined __i386__

/* XXX: use gcc/tcc intrinsic ? */
#تعریف_کرو sub_ddmmss(sh, sl, ah, al, bh, bl) \
  __asm__ ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#تعریف_کرو umul_ppmm(w1, w0, u, v) \
  __asm__ ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#تعریف_کرو udiv_qrnnd(q, r, n1, n0, dv) \
  __asm__ ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#تعریف_کرو گنتی_leading_zeros(گنتی_2, x) \
  افعل {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (گنتی_2) = __cbtmp ^ 31;						\
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
  d1 = dd.s.بلند;
  n0 = nn.s.کم;
  n1 = nn.s.بلند;

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
	  rr.s.بلند = 0;
	  *rp = rr.ll;
	}
    }

#وإلا /* UDIV_NEEDS_NORMALIZATION */

  إذا (d1 == 0)
    {
      إذا (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  گنتی_leading_zeros (bm, d0);

	  إذا (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_ناپ - bm));
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

	  گنتی_leading_zeros (bm, d0);

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

	      b = W_TYPE_ناپ - bm;

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
	  rr.s.بلند = 0;
	  *rp = rr.ll;
	}
    }
#جے_انت /* UDIV_NEEDS_NORMALIZATION */

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
	      rr.s.بلند = n1;
	      *rp = rr.ll;
	    }
	}
      وإلا
	{
	  /* 0q = NN / dd */

	  گنتی_leading_zeros (bm, d1);
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
		  rr.s.بلند = n1;
		  *rp = rr.ll;
		}
	    }
	  وإلا
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_ناپ - bm;

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
		  rr.s.بلند = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.کم = q0;
  ww.s.بلند = q1;
  أرجع ww.ll;
}

#تعریف_کرو __negdi2(a) (-(a))

لما لما __divdi3(لما لما u, لما لما v)
{
    صحيح c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    إذا (uu.s.بلند < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    إذا (vv.s.بلند < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    إذا (c)
        w = __negdi2 (w);
    أرجع w;
}

لما لما __moddi3(لما لما u, لما لما v)
{
    صحيح c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    إذا (uu.s.بلند < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    إذا (vv.s.بلند < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    إذا (c)
        w = __negdi2 (w);
    أرجع w;
}

بنانشانی لما لما __udivdi3(بنانشانی لما لما u, بنانشانی لما لما v)
{
    أرجع __udivmoddi4 (u, v, (UDWtype *) 0);
}

بنانشانی لما لما __umoddi3(بنانشانی لما لما u, بنانشانی لما لما v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    أرجع w;
}

/* XXX: fix tcc's code generator to do this instead */
لما لما __ashrdi3(لما لما a, صحيح b)
{
#جے_تعریف_شدہ __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.کم = u.s.بلند >> (b - 32);
        u.s.بلند = u.s.بلند >> 31;
    } وإلا إذا (b != 0) {
        u.s.کم = ((بنانشانی)u.s.کم >> b) | (u.s.بلند << (32 - b));
        u.s.بلند = u.s.بلند >> b;
    }
    أرجع u.ll;
#وإلا
    أرجع a >> b;
#جے_انت
}

/* XXX: fix tcc's code generator to do this instead */
بنانشانی لما لما __lshrdi3(بنانشانی لما لما a, صحيح b)
{
#جے_تعریف_شدہ __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.کم = (بنانشانی)u.s.بلند >> (b - 32);
        u.s.بلند = 0;
    } وإلا إذا (b != 0) {
        u.s.کم = ((بنانشانی)u.s.کم >> b) | (u.s.بلند << (32 - b));
        u.s.بلند = (بنانشانی)u.s.بلند >> b;
    }
    أرجع u.ll;
#وإلا
    أرجع a >> b;
#جے_انت
}

/* XXX: fix tcc's code generator to do this instead */
لما لما __ashldi3(لما لما a, صحيح b)
{
#جے_تعریف_شدہ __TINYC__
    DWunion u;
    u.ll = a;
    إذا (b >= 32) {
        u.s.بلند = (بنانشانی)u.s.کم << (b - 32);
        u.s.کم = 0;
    } وإلا إذا (b != 0) {
        u.s.بلند = ((بنانشانی)u.s.بلند << b) | ((بنانشانی)u.s.کم >> (32 - b));
        u.s.کم = (بنانشانی)u.s.کم << b;
    }
    أرجع u.ll;
#وإلا
    أرجع a << b;
#جے_انت
}

#جے_انت /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
عائم __floatundisf(بنانشانی لما لما a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.بلند >= 0) {
        أرجع (عائم)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        أرجع (عائم)r;
    }
}

مزدوج __floatundidf(بنانشانی لما لما a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.بلند >= 0) {
        أرجع (مزدوج)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        أرجع (مزدوج)r;
    }
}

لما مزدوج __floatundixf(بنانشانی لما لما a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    إذا (uu.s.بلند >= 0) {
        أرجع (لما مزدوج)uu.ll;
    } وإلا {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        أرجع (لما مزدوج)r;
    }
}

بنانشانی لما لما __fixunssfdi (عائم a1)
{
    سجل اتحاد float_long fl1;
    سجل صحيح قوت_نما;
    سجل بنانشانی لما لما l;

    fl1.f = a1;

    إذا (fl1.l == 0)
	أرجع (0);

    قوت_نما = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    إذا (قوت_نما >= 41)
        أرجع 1ULL << 63;
    وإلا إذا (قوت_نما >= 0)
        l <<= قوت_نما;
    وإلا إذا (قوت_نما >= -23)
        l >>= -قوت_نما;
    وإلا
	أرجع 0;
    إذا (SIGN(fl1.l))
        l = (بنانشانی لما لما)-l;
    أرجع l;
}

لما لما __fixsfdi (عائم a1)
{
    لما لما ret; صحيح s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    أرجع s ? ret : -ret;
}

بنانشانی لما لما __fixunsdfdi (مزدوج a1)
{
    سجل اتحاد double_long dl1;
    سجل صحيح قوت_نما;
    سجل بنانشانی لما لما l;

    dl1.d = a1;

    إذا (dl1.ll == 0)
	أرجع (0);

    قوت_نما = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    إذا (قوت_نما >= 12)
        أرجع 1ULL << 63; /* overflow result (like gcc, somewhat) */
    وإلا إذا (قوت_نما >= 0)
        l <<= قوت_نما;
    وإلا إذا (قوت_نما >= -52)
        l >>= -قوت_نما;
    وإلا
        أرجع 0;
    إذا (SIGND(dl1))
        l = (بنانشانی لما لما)-l;
    أرجع l;
}

لما لما __fixdfdi (مزدوج a1)
{
    لما لما ret; صحيح s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    أرجع s ? ret : -ret;
}

#جے_بنا_تعریف __arm__
بنانشانی لما لما __fixunsxfdi (لما مزدوج a1)
{
    سجل اتحاد ldouble_long dl1;
    سجل صحيح قوت_نما;
    سجل بنانشانی لما لما l;

    dl1.ld = a1;

    إذا (dl1.l.ہیٹھلا == 0 && dl1.l.اتلا == 0)
	أرجع (0);

    قوت_نما = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.ہیٹھلا;
    إذا (قوت_نما > 0)
	أرجع 1ULL << 63;
    إذا (قوت_نما < -63)
        أرجع 0;
    l >>= -قوت_نما;
    إذا (SIGNLD(dl1))
        l = (بنانشانی لما لما)-l;
    أرجع l;
}

لما لما __fixxfdi (لما مزدوج a1)
{
    لما لما ret; صحيح s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    أرجع s ? ret : -ret;
}
#جے_انت /* !ARM */
