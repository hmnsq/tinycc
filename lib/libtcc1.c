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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ W_TYPE_ਮਾਪ   32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਿੱਟ_ਪ੍ਰਤੀ_UNIT 8

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ Wtype;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ UWtype;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ USItype;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ DWtype;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ UDWtype;

ਬਣਤਰ DWstruct {
    Wtype ਨੀਵਾਂ, ਉੱਚਾ;
};

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ
{
  ਬਣਤਰ DWstruct s;
  DWtype ll;
} DWunion;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਦੁੱਗਣਾ XFtype;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸ਼ਬਦ_ਮਾਪ (ਆਕਾਰ (Wtype) * ਬਿੱਟ_ਪ੍ਰਤੀ_UNIT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਉੱਚਾ_ਸ਼ਬਦ_COEFF (((UDWtype) 1) << ਸ਼ਬਦ_ਮਾਪ)

/* the following deal with IEEE single-precision numbers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCESS		126
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGNBIT		0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HIDDEN		(1 << 23)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGN(fp)	((fp) & SIGNBIT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXP(fp)		(((fp) >> 23) & 0xFF)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE double-precision numbers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCESSD		1022
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HIDDEND		(1 << 20)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXPD(fp)	(((fp.l.ਉੱਤਲਾ) >> 20) & 0x7FF)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGND(fp)	((fp.l.ਉੱਤਲਾ) & SIGNBIT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MANTD(fp)	(((((fp.l.ਉੱਤਲਾ) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.ਹੇਠਲਾ >> 22))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HIDDEND_LL	((ਲੰਮਾ ਲੰਮਾ)1 << 52)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PACKD_LL(s,e,m)	(((ਲੰਮਾ ਲੰਮਾ)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 long double-precision numbers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCESSLD	16382
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXPLD(fp)	(fp.l.ਉੱਤਲਾ & 0x7fff)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGNLD(fp)	((fp.l.ਉੱਤਲਾ) & 0x8000)

/* only for x86 */
ਸੰਘ ldouble_long {
    ਲੰਮਾ ਦੁੱਗਣਾ ld;
    ਬਣਤਰ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਹੇਠਲਾ;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਉੱਤਲਾ;
    } l;
};

ਸੰਘ double_long {
    ਦੁੱਗਣਾ d;
#ਜੇ 1
    ਬਣਤਰ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਹੇਠਲਾ;
        ਪੂਰਨ ਉੱਤਲਾ;
    } l;
#ਨਹੀਂਤਾਂ
    ਬਣਤਰ {
        ਪੂਰਨ ਉੱਤਲਾ;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਹੇਠਲਾ;
    } l;
#ਜੇ_ਅੰਤ
    ਲੰਮਾ ਲੰਮਾ ll;
};

ਸੰਘ float_long {
    ਦਸ਼ਮਲਵ f;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ l;
};

/* XXX: we don't support several builtin supports for now */
#ਜੇ defined __i386__

/* XXX: use gcc/tcc intrinsic ? */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ sub_ddmmss(sh, sl, ah, al, bh, bl) \
  __asm__ ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ umul_ppmm(w1, w0, u, v) \
  __asm__ ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ udiv_qrnnd(q, r, n1, n0, dv) \
  __asm__ ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗਿਣਤੀ_leading_zeros(ਗਿਣਤੀ_3, x) \
  ਕਰੋ {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (ਗਿਣਤੀ_3) = __cbtmp ^ 31;						\
  } ਜਦੋਂ (0)

/* most of this code is taken from libgcc2.c from gcc */

ਸਥਿਰ UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.ਨੀਵਾਂ;
  d1 = dd.s.ਉੱਚਾ;
  n0 = nn.s.ਨੀਵਾਂ;
  n1 = nn.s.ਉੱਚਾ;

#ਜੇ !defined(UDIV_NEEDS_NORMALIZATION)
  ਜੇ (d1 == 0)
    {
      ਜੇ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      ਨਹੀਂਤਾਂ
	{
	  /* qq = NN / 0d */

	  ਜੇ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      ਜੇ (rp != 0)
	{
	  rr.s.ਨੀਵਾਂ = n0;
	  rr.s.ਉੱਚਾ = 0;
	  *rp = rr.ll;
	}
    }

#ਨਹੀਂਤਾਂ /* UDIV_NEEDS_NORMALIZATION */

  ਜੇ (d1 == 0)
    {
      ਜੇ (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  ਗਿਣਤੀ_leading_zeros (bm, d0);

	  ਜੇ (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_ਮਾਪ - bm));
	      n0 = n0 << bm;
	    }

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0 >> bm.  */
	}
      ਨਹੀਂਤਾਂ
	{
	  /* qq = NN / 0d */

	  ਜੇ (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  ਗਿਣਤੀ_leading_zeros (bm, d0);

	  ਜੇ (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  ਨਹੀਂਤਾਂ
	    {
	      /* Normalize.  */

	      b = W_TYPE_ਮਾਪ - bm;

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

      ਜੇ (rp != 0)
	{
	  rr.s.ਨੀਵਾਂ = n0 >> bm;
	  rr.s.ਉੱਚਾ = 0;
	  *rp = rr.ll;
	}
    }
#ਜੇ_ਅੰਤ /* UDIV_NEEDS_NORMALIZATION */

  ਨਹੀਂਤਾਂ
    {
      ਜੇ (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  ਜੇ (rp != 0)
	    {
	      rr.s.ਨੀਵਾਂ = n0;
	      rr.s.ਉੱਚਾ = n1;
	      *rp = rr.ll;
	    }
	}
      ਨਹੀਂਤਾਂ
	{
	  /* 0q = NN / dd */

	  ਗਿਣਤੀ_leading_zeros (bm, d1);
	  ਜੇ (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      ਜੇ (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      ਨਹੀਂਤਾਂ
		q0 = 0;

	      q1 = 0;

	      ਜੇ (rp != 0)
		{
		  rr.s.ਨੀਵਾਂ = n0;
		  rr.s.ਉੱਚਾ = n1;
		  *rp = rr.ll;
		}
	    }
	  ਨਹੀਂਤਾਂ
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_ਮਾਪ - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);

	      ਜੇ (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      ਜੇ (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.ਨੀਵਾਂ = (n1 << b) | (n0 >> bm);
		  rr.s.ਉੱਚਾ = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.ਨੀਵਾਂ = q0;
  ww.s.ਉੱਚਾ = q1;
  ਵਾਪਸ ww.ll;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __negdi2(a) (-(a))

ਲੰਮਾ ਲੰਮਾ __divdi3(ਲੰਮਾ ਲੰਮਾ u, ਲੰਮਾ ਲੰਮਾ v)
{
    ਪੂਰਨ c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ਜੇ (uu.s.ਉੱਚਾ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ਜੇ (vv.s.ਉੱਚਾ < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    ਜੇ (c)
        w = __negdi2 (w);
    ਵਾਪਸ w;
}

ਲੰਮਾ ਲੰਮਾ __moddi3(ਲੰਮਾ ਲੰਮਾ u, ਲੰਮਾ ਲੰਮਾ v)
{
    ਪੂਰਨ c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    ਜੇ (uu.s.ਉੱਚਾ < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    ਜੇ (vv.s.ਉੱਚਾ < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    ਜੇ (c)
        w = __negdi2 (w);
    ਵਾਪਸ w;
}

ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ __udivdi3(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ u, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ v)
{
    ਵਾਪਸ __udivmoddi4 (u, v, (UDWtype *) 0);
}

ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ __umoddi3(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ u, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    ਵਾਪਸ w;
}

/* XXX: fix tcc's code generator to do this instead */
ਲੰਮਾ ਲੰਮਾ __ashrdi3(ਲੰਮਾ ਲੰਮਾ a, ਪੂਰਨ b)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__
    DWunion u;
    u.ll = a;
    ਜੇ (b >= 32) {
        u.s.ਨੀਵਾਂ = u.s.ਉੱਚਾ >> (b - 32);
        u.s.ਉੱਚਾ = u.s.ਉੱਚਾ >> 31;
    } ਨਹੀਂਤਾਂ ਜੇ (b != 0) {
        u.s.ਨੀਵਾਂ = ((ਬਿਨਾਨਿਸ਼ਾਨੀ)u.s.ਨੀਵਾਂ >> b) | (u.s.ਉੱਚਾ << (32 - b));
        u.s.ਉੱਚਾ = u.s.ਉੱਚਾ >> b;
    }
    ਵਾਪਸ u.ll;
#ਨਹੀਂਤਾਂ
    ਵਾਪਸ a >> b;
#ਜੇ_ਅੰਤ
}

/* XXX: fix tcc's code generator to do this instead */
ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ __lshrdi3(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ a, ਪੂਰਨ b)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__
    DWunion u;
    u.ll = a;
    ਜੇ (b >= 32) {
        u.s.ਨੀਵਾਂ = (ਬਿਨਾਨਿਸ਼ਾਨੀ)u.s.ਉੱਚਾ >> (b - 32);
        u.s.ਉੱਚਾ = 0;
    } ਨਹੀਂਤਾਂ ਜੇ (b != 0) {
        u.s.ਨੀਵਾਂ = ((ਬਿਨਾਨਿਸ਼ਾਨੀ)u.s.ਨੀਵਾਂ >> b) | (u.s.ਉੱਚਾ << (32 - b));
        u.s.ਉੱਚਾ = (ਬਿਨਾਨਿਸ਼ਾਨੀ)u.s.ਉੱਚਾ >> b;
    }
    ਵਾਪਸ u.ll;
#ਨਹੀਂਤਾਂ
    ਵਾਪਸ a >> b;
#ਜੇ_ਅੰਤ
}

/* XXX: fix tcc's code generator to do this instead */
ਲੰਮਾ ਲੰਮਾ __ashldi3(ਲੰਮਾ ਲੰਮਾ a, ਪੂਰਨ b)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__
    DWunion u;
    u.ll = a;
    ਜੇ (b >= 32) {
        u.s.ਉੱਚਾ = (ਬਿਨਾਨਿਸ਼ਾਨੀ)u.s.ਨੀਵਾਂ << (b - 32);
        u.s.ਨੀਵਾਂ = 0;
    } ਨਹੀਂਤਾਂ ਜੇ (b != 0) {
        u.s.ਉੱਚਾ = ((ਬਿਨਾਨਿਸ਼ਾਨੀ)u.s.ਉੱਚਾ << b) | ((ਬਿਨਾਨਿਸ਼ਾਨੀ)u.s.ਨੀਵਾਂ >> (32 - b));
        u.s.ਨੀਵਾਂ = (ਬਿਨਾਨਿਸ਼ਾਨੀ)u.s.ਨੀਵਾਂ << b;
    }
    ਵਾਪਸ u.ll;
#ਨਹੀਂਤਾਂ
    ਵਾਪਸ a << b;
#ਜੇ_ਅੰਤ
}

#ਜੇ_ਅੰਤ /* __i386__ */

/* XXX: fix tcc's code generator to do this instead */
ਦਸ਼ਮਲਵ __floatundisf(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ਜੇ (uu.s.ਉੱਚਾ >= 0) {
        ਵਾਪਸ (ਦਸ਼ਮਲਵ)uu.ll;
    } ਨਹੀਂਤਾਂ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ਵਾਪਸ (ਦਸ਼ਮਲਵ)r;
    }
}

ਦੁੱਗਣਾ __floatundidf(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ਜੇ (uu.s.ਉੱਚਾ >= 0) {
        ਵਾਪਸ (ਦੁੱਗਣਾ)uu.ll;
    } ਨਹੀਂਤਾਂ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ਵਾਪਸ (ਦੁੱਗਣਾ)r;
    }
}

ਲੰਮਾ ਦੁੱਗਣਾ __floatundixf(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    ਜੇ (uu.s.ਉੱਚਾ >= 0) {
        ਵਾਪਸ (ਲੰਮਾ ਦੁੱਗਣਾ)uu.ll;
    } ਨਹੀਂਤਾਂ {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        ਵਾਪਸ (ਲੰਮਾ ਦੁੱਗਣਾ)r;
    }
}

ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ __fixunssfdi (ਦਸ਼ਮਲਵ a1)
{
    ਰਜਿਸਟਰ ਸੰਘ float_long fl1;
    ਰਜਿਸਟਰ ਪੂਰਨ ਘਾਤਾਂਕ;
    ਰਜਿਸਟਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ l;

    fl1.f = a1;

    ਜੇ (fl1.l == 0)
	ਵਾਪਸ (0);

    ਘਾਤਾਂਕ = EXP (fl1.l) - EXCESS - 24;
    l = MANT(fl1.l);

    ਜੇ (ਘਾਤਾਂਕ >= 41)
        ਵਾਪਸ 1ULL << 63;
    ਨਹੀਂਤਾਂ ਜੇ (ਘਾਤਾਂਕ >= 0)
        l <<= ਘਾਤਾਂਕ;
    ਨਹੀਂਤਾਂ ਜੇ (ਘਾਤਾਂਕ >= -23)
        l >>= -ਘਾਤਾਂਕ;
    ਨਹੀਂਤਾਂ
	ਵਾਪਸ 0;
    ਜੇ (SIGN(fl1.l))
        l = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)-l;
    ਵਾਪਸ l;
}

ਲੰਮਾ ਲੰਮਾ __fixsfdi (ਦਸ਼ਮਲਵ a1)
{
    ਲੰਮਾ ਲੰਮਾ ret; ਪੂਰਨ s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    ਵਾਪਸ s ? ret : -ret;
}

ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ __fixunsdfdi (ਦੁੱਗਣਾ a1)
{
    ਰਜਿਸਟਰ ਸੰਘ double_long dl1;
    ਰਜਿਸਟਰ ਪੂਰਨ ਘਾਤਾਂਕ;
    ਰਜਿਸਟਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ l;

    dl1.d = a1;

    ਜੇ (dl1.ll == 0)
	ਵਾਪਸ (0);

    ਘਾਤਾਂਕ = EXPD (dl1) - EXCESSD - 53;
    l = MANTD_LL(dl1);

    ਜੇ (ਘਾਤਾਂਕ >= 12)
        ਵਾਪਸ 1ULL << 63; /* overflow result (like gcc, somewhat) */
    ਨਹੀਂਤਾਂ ਜੇ (ਘਾਤਾਂਕ >= 0)
        l <<= ਘਾਤਾਂਕ;
    ਨਹੀਂਤਾਂ ਜੇ (ਘਾਤਾਂਕ >= -52)
        l >>= -ਘਾਤਾਂਕ;
    ਨਹੀਂਤਾਂ
        ਵਾਪਸ 0;
    ਜੇ (SIGND(dl1))
        l = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)-l;
    ਵਾਪਸ l;
}

ਲੰਮਾ ਲੰਮਾ __fixdfdi (ਦੁੱਗਣਾ a1)
{
    ਲੰਮਾ ਲੰਮਾ ret; ਪੂਰਨ s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    ਵਾਪਸ s ? ret : -ret;
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __arm__
ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ __fixunsxfdi (ਲੰਮਾ ਦੁੱਗਣਾ a1)
{
    ਰਜਿਸਟਰ ਸੰਘ ldouble_long dl1;
    ਰਜਿਸਟਰ ਪੂਰਨ ਘਾਤਾਂਕ;
    ਰਜਿਸਟਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ l;

    dl1.ld = a1;

    ਜੇ (dl1.l.ਹੇਠਲਾ == 0 && dl1.l.ਉੱਤਲਾ == 0)
	ਵਾਪਸ (0);

    ਘਾਤਾਂਕ = EXPLD (dl1) - EXCESSLD - 64;
    l = dl1.l.ਹੇਠਲਾ;
    ਜੇ (ਘਾਤਾਂਕ > 0)
	ਵਾਪਸ 1ULL << 63;
    ਜੇ (ਘਾਤਾਂਕ < -63)
        ਵਾਪਸ 0;
    l >>= -ਘਾਤਾਂਕ;
    ਜੇ (SIGNLD(dl1))
        l = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)-l;
    ਵਾਪਸ l;
}

ਲੰਮਾ ਲੰਮਾ __fixxfdi (ਲੰਮਾ ਦੁੱਗਣਾ a1)
{
    ਲੰਮਾ ਲੰਮਾ ret; ਪੂਰਨ s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    ਵਾਪਸ s ? ret : -ret;
}
#ਜੇ_ਅੰਤ /* !ARM */
