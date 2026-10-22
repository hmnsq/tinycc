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

#నిర్వచించు W_TYPE_కొలత   32
#నిర్వచించు బిట్లు_చొప్పున_UNIT 8

రకనిర్వచనం పూర్ణాంకం Wtype;
రకనిర్వచనం గుర్తులేని పూర్ణాంకం UWtype;
రకనిర్వచనం గుర్తులేని పూర్ణాంకం USItype;
రకనిర్వచనం దీర్ఘ దీర్ఘ DWtype;
రకనిర్వచనం గుర్తులేని దీర్ఘ దీర్ఘ UDWtype;

నిర్మాణం DWstruct {
    Wtype దిగువ, ఎగువ;
};

రకనిర్వచనం సంఘం
{
  నిర్మాణం DWstruct s;
  DWtype ll;
} DWunion;

రకనిర్వచనం దీర్ఘ ద్విగుణ XFtype;
#నిర్వచించు మాట_కొలత (పరిమాణం (Wtype) * బిట్లు_చొప్పున_UNIT)
#నిర్వచించు ఎగువ_మాట_COEFF (((UDWtype) 1) << మాట_కొలత)

/* the following deal with IEEE single-precision numbers */
#నిర్వచించు EXCESS		126
#నిర్వచించు SIGNBIT		0x80000000
#నిర్వచించు HIDDEN		(1 << 23)
#నిర్వచించు SIGN(fp)	((fp) & SIGNBIT)
#నిర్వచించు EXP(fp)		(((fp) >> 23) & 0xFF)
#నిర్వచించు MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#నిర్వచించు PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE double-precision numbers */
#నిర్వచించు EXCESSD		1022
#నిర్వచించు HIDDEND		(1 << 20)
#నిర్వచించు EXPD(fp)	(((fp.l.పై) >> 20) & 0x7FF)
#నిర్వచించు SIGND(fp)	((fp.l.పై) & SIGNBIT)
#నిర్వచించు MANTD(fp)	(((((fp.l.పై) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.క్రింది >> 22))
#నిర్వచించు HIDDEND_LL	((దీర్ఘ దీర్ఘ)1 << 52)
#నిర్వచించు MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#నిర్వచించు PACKD_LL(s,e,m)	(((దీర్ఘ దీర్ఘ)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#నిర్వచించు EXCESSLD	16382
#నిర్వచించు EXPLD(fp)	(fp.l.పై & 0x7fff)
#నిర్వచించు SIGNLD(fp)	((fp.l.పై) & 0x8000)

/* only for x86 */
సంఘం ldouble_long {
    దీర్ఘ ద్విగుణ ld;
    నిర్మాణం {
        గుర్తులేని దీర్ఘ దీర్ఘ క్రింది;
        గుర్తులేని పొట్టి పై;
    } l;
};

సంఘం double_long {
    ద్విగుణ d;
#ఒకవేళ 1
    నిర్మాణం {
        గుర్తులేని పూర్ణాంకం క్రింది;
        పూర్ణాంకం పై;
    } l;
#లేకపోతే
    నిర్మాణం {
        పూర్ణాంకం పై;
        గుర్తులేని పూర్ణాంకం క్రింది;
    } l;
#అయితే_ముగింపు
    దీర్ఘ దీర్ఘ ll;
};

సంఘం float_long {
    దశాంశం f;
    గుర్తులేని పూర్ణాంకం l;
};

/* XXX: we don't support several builtin supports for now */
#ఒకవేళ defined __i386__

/* XXX: use gcc/tcc intrinsic ? */
#నిర్వచించు sub_ddmmss(sh, sl, ah, al, bh, bl) \
  __asm__ ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#నిర్వచించు umul_ppmm(w1, w0, u, v) \
  __asm__ ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#నిర్వచించు udiv_qrnnd(q, r, n1, n0, dv) \
  __asm__ ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#నిర్వచించు లెక్క_leading_zeros(లెక్క_2, x) \
  చేయి {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (లెక్క_2) = __cbtmp ^ 31;						\
  } అయితే (0)

/* most of this code is taken from libgcc2.c from gcc */

స్థిర UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.దిగువ;
  d1 = dd.s.ఎగువ;
  n0 = nn.s.దిగువ;
  n1 = nn.s.ఎగువ;

#ఒకవేళ !defined(UDIV_NEEDS_NORMALIZATION)
  ఒకవేళ (d1 == 0)
    {
      ఒకవేళ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      లేకపోతే
	{
	  /* qq = NN / 0d */

	  ఒకవేళ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      ఒకవేళ (rp != 0)
	{
	  rr.s.దిగువ = n0;
	  rr.s.ఎగువ = 0;
	  *rp = rr.ll;
	}
    }

#లేకపోతే /* UDIV_NEEDS_NORMALIZATION */

  ఒకవేళ (d1 == 0)
    {
      ఒకవేళ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  లెక్క_leading_zeros (bm, d0);

	  ఒకవేళ (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_కొలత - bm));
	      n0 = n0 << bm;
	    }

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0 >> bm.  */
	}
      లేకపోతే
	{
	  /* qq = NN / 0d */

	  ఒకవేళ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  లెక్క_leading_zeros (bm, d0);

	  ఒకవేళ (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  లేకపోతే
	    {
	      /* Normalize.  */

	      b = W_TYPE_కొలత - bm;

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

      ఒకవేళ (rp != 0)
	{
	  rr.s.దిగువ = n0 >> bm;
	  rr.s.ఎగువ = 0;
	  *rp = rr.ll;
	}
    }
#అయితే_ముగింపు /* UDIV_NEEDS_NORMALIZATION */

  లేకపోతే
    {
      ఒకవేళ (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  ఒకవేళ (rp != 0)
	    {
	      rr.s.దిగువ = n0;
	      rr.s.ఎగువ = n1;
	      *rp = rr.ll;
	    }
	}
      లేకపోతే
	{
	  /* 0q = NN / dd */

	  లెక్క_leading_zeros (bm, d1);
	  ఒకవేళ (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      ఒకవేళ (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      లేకపోతే
		q0 = 0;

	      q1 = 0;

	      ఒకవేళ (rp != 0)
		{
		  rr.s.దిగువ = n0;
		  rr.s.ఎగువ = n1;
		  *rp = rr.ll;
		}
	    }
	  లేకపోతే
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_కొలత - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);

	      ఒకవేళ (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      ఒకవేళ (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.దిగువ = (n1 << b) | (n0 >> bm);
		  rr.s.ఎగువ = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.దిగువ = q0;
  ww.s.ఎగువ = q1;
  తిరిగి ww.ll;
}

#నిర్వచించు __negdi2(a) (-(a))

దీర్ఘ దీర్ఘ __divdi3(దీర్ఘ దీర్ఘ u, దీర్ఘ దీర్ఘ v)
{
    పూర్ణాంకం c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ఒకవేళ (uu.s.ఎగువ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ఒకవేళ (vv.s.ఎగువ < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    ఒకవేళ (c)
        w = __negdi2 (w);
    తిరిగి w;
}

దీర్ఘ దీర్ఘ __moddi3(దీర్ఘ దీర్ఘ u, దీర్ఘ దీర్ఘ v)
{
    పూర్ణాంకం c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ఒకవేళ (uu.s.ఎగువ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ఒకవేళ (vv.s.ఎగువ < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    ఒకవేళ (c)
        w = __negdi2 (w);
    తిరిగి w;
}

గుర్తులేని దీర్ఘ దీర్ఘ __udivdi3(గుర్తులేని దీర్ఘ దీర్ఘ u, గుర్తులేని దీర్ఘ దీర్ఘ v)
{
    తిరిగి __udivmoddi4 (u, v, (UDWtype *) 0);
}

గుర్తులేని దీర్ఘ దీర్ఘ __umoddi3(గుర్తులేని దీర్ఘ దీర్ఘ u, గుర్తులేని దీర్ఘ దీర్ఘ v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    తిరిగి w;
}

/* XXX: fix tcc's code generator to do this instead */
దీర్ఘ దీర్ఘ __ashrdi3(దీర్ఘ దీర్ఘ a, పూర్ణాంకం b)
{
#నిర్వచితమైతే __TINYC__
    DWunion u;
    u.ll = a;
    ఒకవేళ (b >= 32) {
        u.s.దిగువ = u.s.ఎగువ >> (b - 32);
        u.s.ఎగువ = u.s.ఎగువ >> 31;
    } లేకపోతే ఒకవేళ (b != 0) {
        u.s.దిగువ = ((గుర్తులేని)u.s.దిగువ >> b) | (u.s.ఎగువ << (32 - b));
        u.s.ఎగువ = u.s.ఎగువ >> b;
    }
    తిరిగి u.ll;
#లేకపోతే
    తిరిగి a >> b;
#అయితే_ముగింపు
}

/* XXX: fix tcc's code generator to do this instead */
గుర్తులేని దీర్ఘ దీర్ఘ __lshrdi3(గుర్తులేని దీర్ఘ దీర్ఘ a, పూర్ణాంకం b)
{
#నిర్వచితమైతే __TINYC__
    DWunion u;
    u.ll = a;
    ఒకవేళ (b >= 32) {
        u.s.దిగువ = (గుర్తులేని)u.s.ఎగువ >> (b - 32);
        u.s.ఎగువ = 0;
    } లేకపోతే ఒకవేళ (b != 0) {
        u.s.దిగువ = ((గుర్తులేని)u.s.దిగువ >> b) | (u.s.ఎగువ << (32 - b));
        u.s.ఎగువ = (గుర్తులేని)u.s.ఎగువ >> b;
    }
    తిరిగి u.ll;
#లేకపోతే
    తిరిగి a >> b;
#అయితే_ముగింపు
}

/* XXX: fix tcc's code generator to do this instead */
దీర్ఘ దీర్ఘ __ashldi3(దీర్ఘ దీర్ఘ a, పూర్ణాంకం b)
{
#నిర్వచితమైతే __TINYC__
    DWunion u;
    u.ll = a;
    ఒకవేళ (b >= 32) {
        u.s.ఎగువ = (గుర్తులేని)u.s.దిగువ << (b - 32);
        u.s.దిగువ = 0;
    } లేకపోతే ఒకవేళ (b != 0) {
        u.s.ఎగువ = ((గుర్తులేని)u.s.ఎగువ << b) | ((గుర్తులేని)u.s.దిగువ >> (32 - b));
        u.s.దిగువ = (గుర్తులేని)u.s.దిగువ << b;
    }
    తిరిగి u.ll;
#లేకపోతే
    తిరిగి a << b;
#అయితే_ముగింపు
}

#అయితే_ముగింపు /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
దశాంశం __floatundisf(గుర్తులేని దీర్ఘ దీర్ఘ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ఒకవేళ (uu.s.ఎగువ >= 0) {
        తిరిగి (దశాంశం)uu.ll;
    } లేకపోతే {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        తిరిగి (దశాంశం)r;
    }
}

ద్విగుణ __floatundidf(గుర్తులేని దీర్ఘ దీర్ఘ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ఒకవేళ (uu.s.ఎగువ >= 0) {
        తిరిగి (ద్విగుణ)uu.ll;
    } లేకపోతే {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        తిరిగి (ద్విగుణ)r;
    }
}

దీర్ఘ ద్విగుణ __floatundixf(గుర్తులేని దీర్ఘ దీర్ఘ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ఒకవేళ (uu.s.ఎగువ >= 0) {
        తిరిగి (దీర్ఘ ద్విగుణ)uu.ll;
    } లేకపోతే {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        తిరిగి (దీర్ఘ ద్విగుణ)r;
    }
}

గుర్తులేని దీర్ఘ దీర్ఘ __fixunssfdi (దశాంశం a1)
{
    నమోదు సంఘం float_long fl1;
    నమోదు పూర్ణాంకం ఘాతాంకం;
    నమోదు గుర్తులేని దీర్ఘ దీర్ఘ l;

    fl1.f = a1;

    ఒకవేళ (fl1.l == 0)
	తిరిగి (0);

    ఘాతాంకం = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    ఒకవేళ (ఘాతాంకం >= 41)
        తిరిగి 1ULL << 63;
    లేకపోతే ఒకవేళ (ఘాతాంకం >= 0)
        l <<= ఘాతాంకం;
    లేకపోతే ఒకవేళ (ఘాతాంకం >= -23)
        l >>= -ఘాతాంకం;
    లేకపోతే
	తిరిగి 0;
    ఒకవేళ (SIGN(fl1.l))
        l = (గుర్తులేని దీర్ఘ దీర్ఘ)-l;
    తిరిగి l;
}

దీర్ఘ దీర్ఘ __fixsfdi (దశాంశం a1)
{
    దీర్ఘ దీర్ఘ ret; పూర్ణాంకం s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    తిరిగి s ? ret : -ret;
}

గుర్తులేని దీర్ఘ దీర్ఘ __fixunsdfdi (ద్విగుణ a1)
{
    నమోదు సంఘం double_long dl1;
    నమోదు పూర్ణాంకం ఘాతాంకం;
    నమోదు గుర్తులేని దీర్ఘ దీర్ఘ l;

    dl1.d = a1;

    ఒకవేళ (dl1.ll == 0)
	తిరిగి (0);

    ఘాతాంకం = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    ఒకవేళ (ఘాతాంకం >= 12)
        తిరిగి 1ULL << 63; /* overflow result (like gcc, somewhat) */
    లేకపోతే ఒకవేళ (ఘాతాంకం >= 0)
        l <<= ఘాతాంకం;
    లేకపోతే ఒకవేళ (ఘాతాంకం >= -52)
        l >>= -ఘాతాంకం;
    లేకపోతే
        తిరిగి 0;
    ఒకవేళ (SIGND(dl1))
        l = (గుర్తులేని దీర్ఘ దీర్ఘ)-l;
    తిరిగి l;
}

దీర్ఘ దీర్ఘ __fixdfdi (ద్విగుణ a1)
{
    దీర్ఘ దీర్ఘ ret; పూర్ణాంకం s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    తిరిగి s ? ret : -ret;
}

#నిర్వచితం_కాకపోతే __arm__
గుర్తులేని దీర్ఘ దీర్ఘ __fixunsxfdi (దీర్ఘ ద్విగుణ a1)
{
    నమోదు సంఘం ldouble_long dl1;
    నమోదు పూర్ణాంకం ఘాతాంకం;
    నమోదు గుర్తులేని దీర్ఘ దీర్ఘ l;

    dl1.ld = a1;

    ఒకవేళ (dl1.l.క్రింది == 0 && dl1.l.పై == 0)
	తిరిగి (0);

    ఘాతాంకం = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.క్రింది;
    ఒకవేళ (ఘాతాంకం > 0)
	తిరిగి 1ULL << 63;
    ఒకవేళ (ఘాతాంకం < -63)
        తిరిగి 0;
    l >>= -ఘాతాంకం;
    ఒకవేళ (SIGNLD(dl1))
        l = (గుర్తులేని దీర్ఘ దీర్ఘ)-l;
    తిరిగి l;
}

దీర్ఘ దీర్ఘ __fixxfdi (దీర్ఘ ద్విగుణ a1)
{
    దీర్ఘ దీర్ఘ ret; పూర్ణాంకం s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    తిరిగి s ? ret : -ret;
}
#అయితే_ముగింపు /* !ARM */
