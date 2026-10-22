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

#ವ್ಯಾಖ್ಯಾನಿಸು W_TYPE_ಗಾತ್ರ   32
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್ಟುಗಳು_ಪ್ರತಿ_UNIT 8

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ Wtype;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ UWtype;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ USItype;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ DWtype;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ UDWtype;

ರಚನೆ DWstruct {
    Wtype ಕೆಳಗಿನ, ಮೇಲಿನ;
};

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ
{
  ರಚನೆ DWstruct s;
  DWtype ll;
} DWunion;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದ್ವಿಗುಣ XFtype;
#ವ್ಯಾಖ್ಯಾನಿಸು ಶಬ್ದ_ಗಾತ್ರ (ಗಾತ್ರ (Wtype) * ಬಿಟ್ಟುಗಳು_ಪ್ರತಿ_UNIT)
#ವ್ಯಾಖ್ಯಾನಿಸು ಮೇಲಿನ_ಶಬ್ದ_COEFF (((UDWtype) 1) << ಶಬ್ದ_ಗಾತ್ರ)

/* the following deal with IEEE single-precision numbers */
#ವ್ಯಾಖ್ಯಾನಿಸು EXCESS		126
#ವ್ಯಾಖ್ಯಾನಿಸು SIGNBIT		0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು HIDDEN		(1 << 23)
#ವ್ಯಾಖ್ಯಾನಿಸು SIGN(fp)	((fp) & SIGNBIT)
#ವ್ಯಾಖ್ಯಾನಿಸು EXP(fp)		(((fp) >> 23) & 0xFF)
#ವ್ಯಾಖ್ಯಾನಿಸು MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#ವ್ಯಾಖ್ಯಾನಿಸು PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE double-precision numbers */
#ವ್ಯಾಖ್ಯಾನಿಸು EXCESSD		1022
#ವ್ಯಾಖ್ಯಾನಿಸು HIDDEND		(1 << 20)
#ವ್ಯಾಖ್ಯಾನಿಸು EXPD(fp)	(((fp.l.ಊರ್ಧ್ವ) >> 20) & 0x7FF)
#ವ್ಯಾಖ್ಯಾನಿಸು SIGND(fp)	((fp.l.ಊರ್ಧ್ವ) & SIGNBIT)
#ವ್ಯಾಖ್ಯಾನಿಸು MANTD(fp)	(((((fp.l.ಊರ್ಧ್ವ) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.ಅಧೋ >> 22))
#ವ್ಯಾಖ್ಯಾನಿಸು HIDDEND_LL	((ದೀರ್ಘ ದೀರ್ಘ)1 << 52)
#ವ್ಯಾಖ್ಯಾನಿಸು MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#ವ್ಯಾಖ್ಯಾನಿಸು PACKD_LL(s,e,m)	(((ದೀರ್ಘ ದೀರ್ಘ)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#ವ್ಯಾಖ್ಯಾನಿಸು EXCESSLD	16382
#ವ್ಯಾಖ್ಯಾನಿಸು EXPLD(fp)	(fp.l.ಊರ್ಧ್ವ & 0x7fff)
#ವ್ಯಾಖ್ಯಾನಿಸು SIGNLD(fp)	((fp.l.ಊರ್ಧ್ವ) & 0x8000)

/* only for x86 */
ಒಕ್ಕೂಟ ldouble_long {
    ದೀರ್ಘ ದ್ವಿಗುಣ ld;
    ರಚನೆ {
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಅಧೋ;
        ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಊರ್ಧ್ವ;
    } l;
};

ಒಕ್ಕೂಟ double_long {
    ದ್ವಿಗುಣ d;
#ಆದರೆ 1
    ರಚನೆ {
        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಅಧೋ;
        ಪೂರ್ಣಾಂಕ ಊರ್ಧ್ವ;
    } l;
#ಇಲ್ಲದಿದ್ದರೆ
    ರಚನೆ {
        ಪೂರ್ಣಾಂಕ ಊರ್ಧ್ವ;
        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಅಧೋ;
    } l;
#ಆದರೆ_ಅಂತ್ಯ
    ದೀರ್ಘ ದೀರ್ಘ ll;
};

ಒಕ್ಕೂಟ float_long {
    ದಶಮಾಂಶ f;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ l;
};

/* XXX: we don't support several builtin supports for now */
#ಆದರೆ defined __i386__

/* XXX: use gcc/tcc intrinsic ? */
#ವ್ಯಾಖ್ಯಾನಿಸು sub_ddmmss(sh, sl, ah, al, bh, bl) \
  __asm__ ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#ವ್ಯಾಖ್ಯಾನಿಸು umul_ppmm(w1, w0, u, v) \
  __asm__ ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#ವ್ಯಾಖ್ಯಾನಿಸು udiv_qrnnd(q, r, n1, n0, dv) \
  __asm__ ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#ವ್ಯಾಖ್ಯಾನಿಸು ಎಣಿಕೆ_leading_zeros(ಎಣಿಕೆ_3, x) \
  ಮಾಡು {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (ಎಣಿಕೆ_3) = __cbtmp ^ 31;						\
  } ಆಗ (0)

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

#ಆದರೆ !defined(UDIV_NEEDS_NORMALIZATION)
  ಆದರೆ (d1 == 0)
    {
      ಆದರೆ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      ಇಲ್ಲದಿದ್ದರೆ
	{
	  /* qq = NN / 0d */

	  ಆದರೆ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      ಆದರೆ (rp != 0)
	{
	  rr.s.ಕೆಳಗಿನ = n0;
	  rr.s.ಮೇಲಿನ = 0;
	  *rp = rr.ll;
	}
    }

#ಇಲ್ಲದಿದ್ದರೆ /* UDIV_NEEDS_NORMALIZATION */

  ಆದರೆ (d1 == 0)
    {
      ಆದರೆ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  ಎಣಿಕೆ_leading_zeros (bm, d0);

	  ಆದರೆ (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_ಗಾತ್ರ - bm));
	      n0 = n0 << bm;
	    }

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0 >> bm.  */
	}
      ಇಲ್ಲದಿದ್ದರೆ
	{
	  /* qq = NN / 0d */

	  ಆದರೆ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  ಎಣಿಕೆ_leading_zeros (bm, d0);

	  ಆದರೆ (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  ಇಲ್ಲದಿದ್ದರೆ
	    {
	      /* Normalize.  */

	      b = W_TYPE_ಗಾತ್ರ - bm;

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

      ಆದರೆ (rp != 0)
	{
	  rr.s.ಕೆಳಗಿನ = n0 >> bm;
	  rr.s.ಮೇಲಿನ = 0;
	  *rp = rr.ll;
	}
    }
#ಆದರೆ_ಅಂತ್ಯ /* UDIV_NEEDS_NORMALIZATION */

  ಇಲ್ಲದಿದ್ದರೆ
    {
      ಆದರೆ (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  ಆದರೆ (rp != 0)
	    {
	      rr.s.ಕೆಳಗಿನ = n0;
	      rr.s.ಮೇಲಿನ = n1;
	      *rp = rr.ll;
	    }
	}
      ಇಲ್ಲದಿದ್ದರೆ
	{
	  /* 0q = NN / dd */

	  ಎಣಿಕೆ_leading_zeros (bm, d1);
	  ಆದರೆ (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      ಆದರೆ (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      ಇಲ್ಲದಿದ್ದರೆ
		q0 = 0;

	      q1 = 0;

	      ಆದರೆ (rp != 0)
		{
		  rr.s.ಕೆಳಗಿನ = n0;
		  rr.s.ಮೇಲಿನ = n1;
		  *rp = rr.ll;
		}
	    }
	  ಇಲ್ಲದಿದ್ದರೆ
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_ಗಾತ್ರ - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);

	      ಆದರೆ (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      ಆದರೆ (rp != 0)
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
  ಹಿಂತಿರುಗಿ ww.ll;
}

#ವ್ಯಾಖ್ಯಾನಿಸು __negdi2(a) (-(a))

ದೀರ್ಘ ದೀರ್ಘ __divdi3(ದೀರ್ಘ ದೀರ್ಘ u, ದೀರ್ಘ ದೀರ್ಘ v)
{
    ಪೂರ್ಣಾಂಕ c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ಆದರೆ (uu.s.ಮೇಲಿನ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ಆದರೆ (vv.s.ಮೇಲಿನ < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    ಆದರೆ (c)
        w = __negdi2 (w);
    ಹಿಂತಿರುಗಿ w;
}

ದೀರ್ಘ ದೀರ್ಘ __moddi3(ದೀರ್ಘ ದೀರ್ಘ u, ದೀರ್ಘ ದೀರ್ಘ v)
{
    ಪೂರ್ಣಾಂಕ c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ಆದರೆ (uu.s.ಮೇಲಿನ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ಆದರೆ (vv.s.ಮೇಲಿನ < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    ಆದರೆ (c)
        w = __negdi2 (w);
    ಹಿಂತಿರುಗಿ w;
}

ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ __udivdi3(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ u, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ v)
{
    ಹಿಂತಿರುಗಿ __udivmoddi4 (u, v, (UDWtype *) 0);
}

ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ __umoddi3(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ u, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    ಹಿಂತಿರುಗಿ w;
}

/* XXX: fix tcc's code generator to do this instead */
ದೀರ್ಘ ದೀರ್ಘ __ashrdi3(ದೀರ್ಘ ದೀರ್ಘ a, ಪೂರ್ಣಾಂಕ b)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__
    DWunion u;
    u.ll = a;
    ಆದರೆ (b >= 32) {
        u.s.ಕೆಳಗಿನ = u.s.ಮೇಲಿನ >> (b - 32);
        u.s.ಮೇಲಿನ = u.s.ಮೇಲಿನ >> 31;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (b != 0) {
        u.s.ಕೆಳಗಿನ = ((ಚಿಹ್ನೆರಹಿತ)u.s.ಕೆಳಗಿನ >> b) | (u.s.ಮೇಲಿನ << (32 - b));
        u.s.ಮೇಲಿನ = u.s.ಮೇಲಿನ >> b;
    }
    ಹಿಂತಿರುಗಿ u.ll;
#ಇಲ್ಲದಿದ್ದರೆ
    ಹಿಂತಿರುಗಿ a >> b;
#ಆದರೆ_ಅಂತ್ಯ
}

/* XXX: fix tcc's code generator to do this instead */
ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ __lshrdi3(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ a, ಪೂರ್ಣಾಂಕ b)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__
    DWunion u;
    u.ll = a;
    ಆದರೆ (b >= 32) {
        u.s.ಕೆಳಗಿನ = (ಚಿಹ್ನೆರಹಿತ)u.s.ಮೇಲಿನ >> (b - 32);
        u.s.ಮೇಲಿನ = 0;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (b != 0) {
        u.s.ಕೆಳಗಿನ = ((ಚಿಹ್ನೆರಹಿತ)u.s.ಕೆಳಗಿನ >> b) | (u.s.ಮೇಲಿನ << (32 - b));
        u.s.ಮೇಲಿನ = (ಚಿಹ್ನೆರಹಿತ)u.s.ಮೇಲಿನ >> b;
    }
    ಹಿಂತಿರುಗಿ u.ll;
#ಇಲ್ಲದಿದ್ದರೆ
    ಹಿಂತಿರುಗಿ a >> b;
#ಆದರೆ_ಅಂತ್ಯ
}

/* XXX: fix tcc's code generator to do this instead */
ದೀರ್ಘ ದೀರ್ಘ __ashldi3(ದೀರ್ಘ ದೀರ್ಘ a, ಪೂರ್ಣಾಂಕ b)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__
    DWunion u;
    u.ll = a;
    ಆದರೆ (b >= 32) {
        u.s.ಮೇಲಿನ = (ಚಿಹ್ನೆರಹಿತ)u.s.ಕೆಳಗಿನ << (b - 32);
        u.s.ಕೆಳಗಿನ = 0;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (b != 0) {
        u.s.ಮೇಲಿನ = ((ಚಿಹ್ನೆರಹಿತ)u.s.ಮೇಲಿನ << b) | ((ಚಿಹ್ನೆರಹಿತ)u.s.ಕೆಳಗಿನ >> (32 - b));
        u.s.ಕೆಳಗಿನ = (ಚಿಹ್ನೆರಹಿತ)u.s.ಕೆಳಗಿನ << b;
    }
    ಹಿಂತಿರುಗಿ u.ll;
#ಇಲ್ಲದಿದ್ದರೆ
    ಹಿಂತಿರುಗಿ a << b;
#ಆದರೆ_ಅಂತ್ಯ
}

#ಆದರೆ_ಅಂತ್ಯ /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
ದಶಮಾಂಶ __floatundisf(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ಆದರೆ (uu.s.ಮೇಲಿನ >= 0) {
        ಹಿಂತಿರುಗಿ (ದಶಮಾಂಶ)uu.ll;
    } ಇಲ್ಲದಿದ್ದರೆ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ಹಿಂತಿರುಗಿ (ದಶಮಾಂಶ)r;
    }
}

ದ್ವಿಗುಣ __floatundidf(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ಆದರೆ (uu.s.ಮೇಲಿನ >= 0) {
        ಹಿಂತಿರುಗಿ (ದ್ವಿಗುಣ)uu.ll;
    } ಇಲ್ಲದಿದ್ದರೆ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ಹಿಂತಿರುಗಿ (ದ್ವಿಗುಣ)r;
    }
}

ದೀರ್ಘ ದ್ವಿಗುಣ __floatundixf(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ಆದರೆ (uu.s.ಮೇಲಿನ >= 0) {
        ಹಿಂತಿರುಗಿ (ದೀರ್ಘ ದ್ವಿಗುಣ)uu.ll;
    } ಇಲ್ಲದಿದ್ದರೆ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ಹಿಂತಿರುಗಿ (ದೀರ್ಘ ದ್ವಿಗುಣ)r;
    }
}

ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ __fixunssfdi (ದಶಮಾಂಶ a1)
{
    ನೋಂದಣಿ ಒಕ್ಕೂಟ float_long fl1;
    ನೋಂದಣಿ ಪೂರ್ಣಾಂಕ ಘಾತಾಂಕ;
    ನೋಂದಣಿ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ l;

    fl1.f = a1;

    ಆದರೆ (fl1.l == 0)
	ಹಿಂತಿರುಗಿ (0);

    ಘಾತಾಂಕ = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    ಆದರೆ (ಘಾತಾಂಕ >= 41)
        ಹಿಂತಿರುಗಿ 1ULL << 63;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಘಾತಾಂಕ >= 0)
        l <<= ಘಾತಾಂಕ;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಘಾತಾಂಕ >= -23)
        l >>= -ಘಾತಾಂಕ;
    ಇಲ್ಲದಿದ್ದರೆ
	ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (SIGN(fl1.l))
        l = (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)-l;
    ಹಿಂತಿರುಗಿ l;
}

ದೀರ್ಘ ದೀರ್ಘ __fixsfdi (ದಶಮಾಂಶ a1)
{
    ದೀರ್ಘ ದೀರ್ಘ ret; ಪೂರ್ಣಾಂಕ s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    ಹಿಂತಿರುಗಿ s ? ret : -ret;
}

ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ __fixunsdfdi (ದ್ವಿಗುಣ a1)
{
    ನೋಂದಣಿ ಒಕ್ಕೂಟ double_long dl1;
    ನೋಂದಣಿ ಪೂರ್ಣಾಂಕ ಘಾತಾಂಕ;
    ನೋಂದಣಿ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ l;

    dl1.d = a1;

    ಆದರೆ (dl1.ll == 0)
	ಹಿಂತಿರುಗಿ (0);

    ಘಾತಾಂಕ = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    ಆದರೆ (ಘಾತಾಂಕ >= 12)
        ಹಿಂತಿರುಗಿ 1ULL << 63; /* overflow result (like gcc, somewhat) */
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಘಾತಾಂಕ >= 0)
        l <<= ಘಾತಾಂಕ;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಘಾತಾಂಕ >= -52)
        l >>= -ಘಾತಾಂಕ;
    ಇಲ್ಲದಿದ್ದರೆ
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (SIGND(dl1))
        l = (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)-l;
    ಹಿಂತಿರುಗಿ l;
}

ದೀರ್ಘ ದೀರ್ಘ __fixdfdi (ದ್ವಿಗುಣ a1)
{
    ದೀರ್ಘ ದೀರ್ಘ ret; ಪೂರ್ಣಾಂಕ s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    ಹಿಂತಿರುಗಿ s ? ret : -ret;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __arm__
ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ __fixunsxfdi (ದೀರ್ಘ ದ್ವಿಗುಣ a1)
{
    ನೋಂದಣಿ ಒಕ್ಕೂಟ ldouble_long dl1;
    ನೋಂದಣಿ ಪೂರ್ಣಾಂಕ ಘಾತಾಂಕ;
    ನೋಂದಣಿ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ l;

    dl1.ld = a1;

    ಆದರೆ (dl1.l.ಅಧೋ == 0 && dl1.l.ಊರ್ಧ್ವ == 0)
	ಹಿಂತಿರುಗಿ (0);

    ಘಾತಾಂಕ = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.ಅಧೋ;
    ಆದರೆ (ಘಾತಾಂಕ > 0)
	ಹಿಂತಿರುಗಿ 1ULL << 63;
    ಆದರೆ (ಘಾತಾಂಕ < -63)
        ಹಿಂತಿರುಗಿ 0;
    l >>= -ಘಾತಾಂಕ;
    ಆದರೆ (SIGNLD(dl1))
        l = (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)-l;
    ಹಿಂತಿರುಗಿ l;
}

ದೀರ್ಘ ದೀರ್ಘ __fixxfdi (ದೀರ್ಘ ದ್ವಿಗುಣ a1)
{
    ದೀರ್ಘ ದೀರ್ಘ ret; ಪೂರ್ಣಾಂಕ s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    ಹಿಂತಿರುಗಿ s ? ret : -ret;
}
#ಆದರೆ_ಅಂತ್ಯ /* !ARM */
